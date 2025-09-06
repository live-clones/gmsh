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
     tCharacteristic = 379,
     tLength = 380,
     tParametric = 381,
     tElliptic = 382,
     tRefineMesh = 383,
     tRecombineMesh = 384,
     tAdaptMesh = 385,
     tTransformMesh = 386,
     tRelocateMesh = 387,
     tReorientMesh = 388,
     tSetFactory = 389,
     tThruSections = 390,
     tWedge = 391,
     tFillet = 392,
     tChamfer = 393,
     tPlane = 394,
     tRuled = 395,
     tTransfinite = 396,
     tPhysical = 397,
     tCompound = 398,
     tPeriodic = 399,
     tParent = 400,
     tUsing = 401,
     tPlugin = 402,
     tDegenerated = 403,
     tRecursive = 404,
     tSewing = 405,
     tRotate = 406,
     tTranslate = 407,
     tSymmetry = 408,
     tDilate = 409,
     tExtrude = 410,
     tLevelset = 411,
     tAffine = 412,
     tClosest = 413,
     tBooleanUnion = 414,
     tBooleanIntersection = 415,
     tBooleanDifference = 416,
     tBooleanSection = 417,
     tBooleanFragments = 418,
     tThickSolid = 419,
     tRecombine = 420,
     tSmoother = 421,
     tSplit = 422,
     tDelete = 423,
     tCoherence = 424,
     tHealShapes = 425,
     tIntersect = 426,
     tMeshAlgorithm = 427,
     tReverseMesh = 428,
     tMeshSize = 429,
     tMeshSizeFromBoundary = 430,
     tLayers = 431,
     tScaleLast = 432,
     tHole = 433,
     tAlias = 434,
     tAliasWithOptions = 435,
     tCopyOptions = 436,
     tQuadTriAddVerts = 437,
     tQuadTriNoNewVerts = 438,
     tRecombLaterals = 439,
     tTransfQuadTri = 440,
     tText2D = 441,
     tText3D = 442,
     tInterpolationScheme = 443,
     tTime = 444,
     tCombine = 445,
     tBSpline = 446,
     tBezier = 447,
     tNurbs = 448,
     tNurbsOrder = 449,
     tNurbsKnots = 450,
     tColor = 451,
     tColorTable = 452,
     tFor = 453,
     tIn = 454,
     tEndFor = 455,
     tIf = 456,
     tElseIf = 457,
     tElse = 458,
     tEndIf = 459,
     tExit = 460,
     tAbort = 461,
     tField = 462,
     tReturn = 463,
     tCall = 464,
     tSlide = 465,
     tMacro = 466,
     tShow = 467,
     tHide = 468,
     tGetValue = 469,
     tGetStringValue = 470,
     tGetEnv = 471,
     tGetString = 472,
     tGetNumber = 473,
     tUnique = 474,
     tSetMaxTag = 475,
     tHomology = 476,
     tCohomology = 477,
     tBetti = 478,
     tExists = 479,
     tFileExists = 480,
     tGetForced = 481,
     tGetForcedStr = 482,
     tGMSH_MAJOR_VERSION = 483,
     tGMSH_MINOR_VERSION = 484,
     tGMSH_PATCH_VERSION = 485,
     tGmshExecutableName = 486,
     tSetPartition = 487,
     tNameToString = 488,
     tStringToName = 489,
     tUnsplitWindow = 490,
     tAFFECTDIVIDE = 491,
     tAFFECTTIMES = 492,
     tAFFECTMINUS = 493,
     tAFFECTPLUS = 494,
     tOR = 495,
     tAND = 496,
     tNOTEQUAL = 497,
     tEQUAL = 498,
     tGREATERGREATER = 499,
     tLESSLESS = 500,
     tGREATEROREQUAL = 501,
     tLESSOREQUAL = 502,
     UNARYPREC = 503,
     tMINUSMINUS = 504,
     tPLUSPLUS = 505
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
#define tCharacteristic 379
#define tLength 380
#define tParametric 381
#define tElliptic 382
#define tRefineMesh 383
#define tRecombineMesh 384
#define tAdaptMesh 385
#define tTransformMesh 386
#define tRelocateMesh 387
#define tReorientMesh 388
#define tSetFactory 389
#define tThruSections 390
#define tWedge 391
#define tFillet 392
#define tChamfer 393
#define tPlane 394
#define tRuled 395
#define tTransfinite 396
#define tPhysical 397
#define tCompound 398
#define tPeriodic 399
#define tParent 400
#define tUsing 401
#define tPlugin 402
#define tDegenerated 403
#define tRecursive 404
#define tSewing 405
#define tRotate 406
#define tTranslate 407
#define tSymmetry 408
#define tDilate 409
#define tExtrude 410
#define tLevelset 411
#define tAffine 412
#define tClosest 413
#define tBooleanUnion 414
#define tBooleanIntersection 415
#define tBooleanDifference 416
#define tBooleanSection 417
#define tBooleanFragments 418
#define tThickSolid 419
#define tRecombine 420
#define tSmoother 421
#define tSplit 422
#define tDelete 423
#define tCoherence 424
#define tHealShapes 425
#define tIntersect 426
#define tMeshAlgorithm 427
#define tReverseMesh 428
#define tMeshSize 429
#define tMeshSizeFromBoundary 430
#define tLayers 431
#define tScaleLast 432
#define tHole 433
#define tAlias 434
#define tAliasWithOptions 435
#define tCopyOptions 436
#define tQuadTriAddVerts 437
#define tQuadTriNoNewVerts 438
#define tRecombLaterals 439
#define tTransfQuadTri 440
#define tText2D 441
#define tText3D 442
#define tInterpolationScheme 443
#define tTime 444
#define tCombine 445
#define tBSpline 446
#define tBezier 447
#define tNurbs 448
#define tNurbsOrder 449
#define tNurbsKnots 450
#define tColor 451
#define tColorTable 452
#define tFor 453
#define tIn 454
#define tEndFor 455
#define tIf 456
#define tElseIf 457
#define tElse 458
#define tEndIf 459
#define tExit 460
#define tAbort 461
#define tField 462
#define tReturn 463
#define tCall 464
#define tSlide 465
#define tMacro 466
#define tShow 467
#define tHide 468
#define tGetValue 469
#define tGetStringValue 470
#define tGetEnv 471
#define tGetString 472
#define tGetNumber 473
#define tUnique 474
#define tSetMaxTag 475
#define tHomology 476
#define tCohomology 477
#define tBetti 478
#define tExists 479
#define tFileExists 480
#define tGetForced 481
#define tGetForcedStr 482
#define tGMSH_MAJOR_VERSION 483
#define tGMSH_MINOR_VERSION 484
#define tGMSH_PATCH_VERSION 485
#define tGmshExecutableName 486
#define tSetPartition 487
#define tNameToString 488
#define tStringToName 489
#define tUnsplitWindow 490
#define tAFFECTDIVIDE 491
#define tAFFECTTIMES 492
#define tAFFECTMINUS 493
#define tAFFECTPLUS 494
#define tOR 495
#define tAND 496
#define tNOTEQUAL 497
#define tEQUAL 498
#define tGREATERGREATER 499
#define tLESSLESS 500
#define tGREATEROREQUAL 501
#define tLESSOREQUAL 502
#define UNARYPREC 503
#define tMINUSMINUS 504
#define tPLUSPLUS 505




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
#line 783 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 796 "Gmsh.tab.cpp"

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
#define YYLAST   18693

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  273
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  653
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2342

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   505

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   258,     2,   270,     2,   255,   257,     2,
     263,   264,   253,   251,   272,   252,   269,   254,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     245,     2,   246,   240,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   265,     2,   266,   262,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   267,   256,   268,   271,     2,     2,     2,
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
     235,   236,   237,   238,   239,   241,   242,   243,   244,   247,
     248,   249,   250,   259,   260,   261
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
    1183,  1188,  1198,  1209,  1219,  1221,  1223,  1224,  1227,  1234,
    1242,  1250,  1257,  1265,  1274,  1285,  1300,  1317,  1330,  1345,
    1360,  1375,  1390,  1399,  1408,  1415,  1420,  1426,  1432,  1439,
    1446,  1450,  1455,  1459,  1465,  1472,  1478,  1483,  1487,  1492,
    1496,  1501,  1507,  1512,  1518,  1522,  1528,  1536,  1544,  1548,
    1551,  1559,  1563,  1566,  1570,  1573,  1576,  1579,  1582,  1598,
    1601,  1604,  1612,  1615,  1625,  1637,  1640,  1645,  1648,  1651,
    1654,  1657,  1674,  1680,  1689,  1701,  1708,  1717,  1726,  1737,
    1739,  1742,  1745,  1747,  1751,  1755,  1760,  1765,  1767,  1769,
    1775,  1787,  1801,  1802,  1810,  1811,  1825,  1826,  1842,  1843,
    1850,  1860,  1863,  1867,  1878,  1892,  1894,  1897,  1903,  1911,
    1914,  1917,  1921,  1924,  1928,  1931,  1935,  1945,  1952,  1954,
    1956,  1958,  1960,  1962,  1963,  1966,  1970,  1974,  1979,  1989,
    1994,  2009,  2010,  2014,  2015,  2017,  2018,  2021,  2022,  2025,
    2026,  2029,  2035,  2042,  2050,  2057,  2063,  2067,  2076,  2083,
    2092,  2101,  2107,  2112,  2119,  2131,  2143,  2162,  2181,  2194,
    2207,  2220,  2231,  2236,  2241,  2246,  2251,  2256,  2263,  2266,
    2270,  2277,  2280,  2282,  2284,  2286,  2289,  2295,  2303,  2314,
    2316,  2320,  2323,  2326,  2329,  2333,  2337,  2341,  2345,  2349,
    2353,  2357,  2361,  2365,  2369,  2373,  2377,  2381,  2385,  2389,
    2393,  2397,  2401,  2407,  2412,  2417,  2422,  2427,  2432,  2437,
    2442,  2447,  2452,  2457,  2462,  2469,  2474,  2479,  2484,  2489,
    2494,  2499,  2504,  2509,  2516,  2523,  2530,  2535,  2542,  2549,
    2551,  2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,
    2571,  2572,  2579,  2581,  2586,  2593,  2595,  2600,  2605,  2610,
    2617,  2623,  2631,  2640,  2651,  2656,  2661,  2668,  2673,  2677,
    2680,  2686,  2692,  2696,  2702,  2709,  2718,  2725,  2734,  2741,
    2746,  2754,  2761,  2768,  2775,  2780,  2787,  2792,  2793,  2796,
    2797,  2800,  2801,  2809,  2811,  2815,  2817,  2820,  2821,  2825,
    2827,  2830,  2833,  2837,  2841,  2853,  2863,  2871,  2879,  2881,
    2885,  2887,  2889,  2892,  2896,  2901,  2907,  2910,  2914,  2919,
    2921,  2925,  2927,  2930,  2934,  2938,  2944,  2949,  2954,  2957,
    2962,  2965,  2969,  2973,  2978,  2984,  2990,  2996,  3002,  3009,
    3021,  3032,  3038,  3040,  3042,  3044,  3048,  3054,  3062,  3067,
    3072,  3077,  3084,  3091,  3100,  3109,  3114,  3129,  3134,  3139,
    3141,  3143,  3147,  3151,  3161,  3169,  3171,  3177,  3181,  3188,
    3190,  3194,  3196,  3198,  3203,  3208,  3212,  3218,  3225,  3234,
    3241,  3246,  3252,  3254,  3259,  3261,  3263,  3265,  3267,  3272,
    3279,  3284,  3291,  3297,  3305,  3310,  3315,  3320,  3329,  3334,
    3339,  3344,  3349,  3358,  3367,  3374,  3379,  3386,  3391,  3393,
    3395,  3400,  3405,  3406,  3413,  3418,  3421,  3426,  3431,  3433,
    3435,  3439,  3441,  3443,  3447,  3451,  3455,  3461,  3469,  3475,
    3481,  3490,  3492,  3494
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     274,     0,    -1,   275,    -1,     1,     6,    -1,    -1,   275,
     276,    -1,   278,    -1,   279,    -1,   300,    -1,   134,   263,
     377,   264,     6,    -1,   319,    -1,   325,    -1,   329,    -1,
     330,    -1,   331,    -1,   332,    -1,   336,    -1,   345,    -1,
     346,    -1,   352,    -1,   353,    -1,   335,    -1,   334,    -1,
     333,    -1,   328,    -1,   355,    -1,   246,    -1,   247,    -1,
      47,   263,   377,   264,     6,    -1,    49,   263,   377,   264,
       6,    -1,    48,   263,   377,   264,     6,    -1,    47,   263,
     377,   264,   277,   377,     6,    -1,    47,   263,   377,   272,
     373,   264,     6,    -1,    49,   263,   377,   272,   373,   264,
       6,    -1,    48,   263,   377,   272,   373,   264,     6,    -1,
      47,   263,   377,   272,   373,   264,   277,   377,     6,    -1,
     387,   377,   267,   280,   268,     6,    -1,   179,     4,   265,
     356,   266,     6,    -1,   180,     4,   265,   356,   266,     6,
      -1,   181,     4,   265,   356,   272,   356,   266,     6,    -1,
      -1,   280,   283,    -1,   280,   287,    -1,   280,   290,    -1,
     280,   292,    -1,   280,   293,    -1,   280,   335,    -1,   356,
      -1,   281,   272,   356,    -1,   356,    -1,   282,   272,   356,
      -1,    -1,    -1,     4,   284,   263,   281,   264,   285,   267,
     282,   268,     6,    -1,   377,    -1,   286,   272,   377,    -1,
      -1,   186,   263,   356,   272,   356,   272,   356,   264,   288,
     267,   286,   268,     6,    -1,   377,    -1,   289,   272,   377,
      -1,    -1,   187,   263,   356,   272,   356,   272,   356,   272,
     356,   264,   291,   267,   289,   268,     6,    -1,   188,   267,
     368,   268,   267,   368,   268,     6,    -1,   188,   267,   368,
     268,   267,   368,   268,   267,   368,   268,   267,   368,   268,
       6,    -1,    -1,   189,   294,   267,   282,   268,     6,    -1,
       7,    -1,   239,    -1,   238,    -1,   237,    -1,   236,    -1,
     261,    -1,   260,    -1,   263,    -1,   265,    -1,   264,    -1,
     266,    -1,     4,    -1,    37,    -1,    38,    -1,    26,    -1,
     112,    -1,   113,    -1,    92,   265,   302,   266,     6,    -1,
      93,   265,   306,   266,     6,    -1,   361,     6,    -1,   100,
     297,   378,   272,   356,   298,     6,    -1,   102,   297,   378,
     272,   378,   298,     6,    -1,   387,   295,   369,     6,    -1,
     387,   296,     6,    -1,   387,   297,   298,   295,   369,     6,
      -1,   387,   297,   267,   373,   268,   298,   295,   369,     6,
      -1,   387,   265,   356,   266,   295,   356,     6,    -1,   387,
     265,   356,   266,   296,     6,    -1,   387,   263,   356,   264,
     295,   356,     6,    -1,   387,   263,   356,   264,   296,     6,
      -1,   387,     7,   378,     6,    -1,   387,   297,   298,     7,
      50,   297,   298,     6,    -1,   387,   297,   298,     7,    50,
     297,   382,   298,     6,    -1,   387,   297,   298,   239,    50,
     297,   382,   298,     6,    -1,   387,   269,   299,     7,   378,
       6,    -1,   387,   265,   356,   266,   269,   299,     7,   378,
       6,    -1,   387,   269,   299,   295,   356,     6,    -1,   387,
     265,   356,   266,   269,   299,   295,   356,     6,    -1,   387,
     269,   299,   296,     6,    -1,   387,   265,   356,   266,   269,
     299,   296,     6,    -1,   387,   269,   196,   269,   299,     7,
     374,     6,    -1,   387,   265,   356,   266,   269,   196,   269,
     299,     7,   374,     6,    -1,   387,   269,   197,     7,   375,
       6,    -1,   387,   265,   356,   266,   269,   197,     7,   375,
       6,    -1,   387,   207,     7,   369,     6,    -1,   207,   265,
     356,   266,     7,   299,     6,    -1,   207,   265,   356,   266,
     269,   299,     7,   356,     6,    -1,   207,   265,   356,   266,
     269,   299,     7,   378,     6,    -1,   207,   265,   356,   266,
     269,   299,     7,   370,     6,    -1,   207,   265,   356,   266,
     269,   299,     6,    -1,   147,   263,     4,   264,   269,   299,
       7,   356,     6,    -1,   147,   263,     4,   264,   269,   299,
       7,   378,     6,    -1,    -1,   272,    -1,    -1,   302,   301,
     387,    -1,   302,   301,   387,     7,   356,    -1,    -1,   302,
     301,   387,     7,   267,   369,   303,   308,   268,    -1,    -1,
     302,   301,   387,   297,   298,     7,   267,   369,   304,   308,
     268,    -1,   302,   301,   387,     7,   378,    -1,    -1,   302,
     301,   387,     7,   267,   378,   305,   312,   268,    -1,    -1,
     306,   301,   377,    -1,   356,     7,   378,    -1,   307,   272,
     356,     7,   378,    -1,   372,     7,   387,   263,   264,    -1,
      -1,   272,   310,    -1,    -1,   310,    -1,   311,    -1,   310,
     272,   311,    -1,     4,   369,    -1,    37,   356,    -1,    38,
     356,    -1,    26,   356,    -1,     4,    -1,     4,   267,   307,
     268,    -1,     4,   378,    -1,     4,   381,    -1,    -1,   272,
     313,    -1,   314,    -1,   313,   272,   314,    -1,     4,   356,
      -1,     4,   378,    -1,   211,   378,    -1,     4,   383,    -1,
       4,   381,    -1,   356,    -1,   378,    -1,   378,   272,   356,
      -1,    -1,   199,   107,   267,   356,   268,    -1,   146,   103,
     267,   373,   268,    -1,   146,   122,   267,   373,   268,    -1,
      -1,   139,   366,    -1,    -1,   146,   150,    -1,   103,   263,
     356,   264,     7,   366,     6,    -1,   106,   263,   356,   264,
       7,   369,     6,    -1,   110,   263,   356,   264,     7,   369,
       6,    -1,   143,   110,   263,   356,   264,     7,   369,   146,
     356,     6,    -1,   143,   191,   263,   356,   264,     7,   369,
     146,   356,     6,    -1,   104,   263,   356,   264,     7,   369,
     317,     6,    -1,   105,   263,   356,   264,     7,   369,   317,
       6,    -1,   191,   263,   356,   264,     7,   369,     6,    -1,
     192,   263,   356,   264,     7,   369,     6,    -1,   193,   263,
     356,   264,     7,   369,   195,   369,   194,   356,     6,    -1,
     121,   263,   356,   264,     7,   369,     6,    -1,   106,     4,
     263,   356,   264,     7,   369,     6,    -1,   139,   109,   263,
     356,   264,     7,   369,     6,    -1,   109,   263,   356,   264,
       7,   369,   316,     6,    -1,   140,   109,   263,   356,   264,
       7,   369,   316,     6,    -1,   191,   109,   263,   356,   264,
       7,   369,     6,    -1,   192,   109,   263,   356,   264,     7,
     369,     6,    -1,    13,    14,     6,    -1,    14,   109,   356,
       6,    -1,   126,   109,   263,   356,   264,     7,     5,     5,
       5,     6,    -1,   107,   263,   356,   264,     7,   369,     6,
      -1,   108,   263,   356,   264,     7,   369,     6,    -1,   112,
     263,   356,   264,     7,   369,     6,    -1,   115,   263,   356,
     264,     7,   369,     6,    -1,   119,   263,   356,   264,     7,
     369,     6,    -1,   120,   263,   356,   264,     7,   369,     6,
      -1,   113,   263,   356,   264,     7,   369,     6,    -1,   114,
     263,   356,   264,     7,   369,     6,    -1,   136,   263,   356,
     264,     7,   369,     6,    -1,   164,   263,   356,   264,     7,
     369,     6,    -1,   109,     4,   263,   356,   264,     7,   369,
     318,     6,    -1,   111,   263,   356,   264,     7,   369,     6,
      -1,   135,   263,   356,   264,     7,   369,     6,    -1,   140,
     135,   263,   356,   264,     7,   369,     6,    -1,   143,   322,
     263,   356,   264,     7,   369,     6,    -1,   143,   322,   263,
     356,   264,     7,   369,     4,   267,   368,   268,     6,    -1,
      -1,   142,   321,   320,   263,   315,   264,   295,   369,     6,
      -1,   103,    -1,   106,    -1,   109,    -1,   111,    -1,   122,
     267,   356,   268,    -1,   106,    -1,   109,    -1,   111,    -1,
     122,   267,   356,   268,    -1,   106,    -1,   109,    -1,   122,
     267,   356,   268,    -1,   103,    -1,   106,    -1,   109,    -1,
     122,   267,   356,   268,    -1,   152,   366,   267,   326,   268,
      -1,   151,   267,   366,   272,   366,   272,   356,   268,   267,
     326,   268,    -1,   153,   366,   267,   326,   268,    -1,   154,
     267,   366,   272,   356,   268,   267,   326,   268,    -1,   154,
     267,   366,   272,   366,   268,   267,   326,   268,    -1,   157,
     267,   373,   268,   267,   326,   268,    -1,   158,   366,   267,
     326,   268,    -1,     4,   267,   326,   268,    -1,   171,   106,
     267,   373,   268,   109,   267,   356,   268,    -1,   167,   106,
     267,   356,   268,   103,   267,   373,   268,     6,    -1,   167,
     106,   263,   356,   264,   267,   373,   268,     6,    -1,   327,
      -1,   325,    -1,    -1,   327,   319,    -1,   327,   321,   267,
     373,   268,     6,    -1,   327,   142,   321,   267,   373,   268,
       6,    -1,   327,   145,   321,   267,   373,   268,     6,    -1,
     327,   321,   267,     8,   268,     6,    -1,   327,   142,   321,
     267,     8,   268,     6,    -1,   156,   139,   263,   356,   264,
       7,   369,     6,    -1,   156,   103,   263,   356,   264,     7,
     267,   368,   268,     6,    -1,   156,   139,   263,   356,   264,
       7,   267,   366,   272,   366,   272,   373,   268,     6,    -1,
     156,   139,   263,   356,   264,     7,   267,   366,   272,   366,
     272,   366,   272,   373,   268,     6,    -1,   156,   107,   263,
     356,   264,     7,   267,   366,   272,   373,   268,     6,    -1,
     156,   113,   263,   356,   264,     7,   267,   366,   272,   366,
     272,   373,   268,     6,    -1,   156,   114,   263,   356,   264,
       7,   267,   366,   272,   366,   272,   373,   268,     6,    -1,
     156,   116,   263,   356,   264,     7,   267,   366,   272,   366,
     272,   373,   268,     6,    -1,   156,   117,   263,   356,   264,
       7,   267,   366,   272,   366,   272,   373,   268,     6,    -1,
     156,     4,   263,   356,   264,     7,   369,     6,    -1,   156,
       4,   263,   356,   264,     7,     5,     6,    -1,   156,     4,
     267,   356,   268,     6,    -1,   168,   267,   327,   268,    -1,
     149,   168,   267,   327,   268,    -1,   168,     4,   267,   327,
     268,    -1,   168,   207,   265,   356,   266,     6,    -1,   168,
       4,   265,   356,   266,     6,    -1,   168,   387,     6,    -1,
     168,     4,     4,     6,    -1,   168,    95,     6,    -1,   196,
     374,   267,   327,   268,    -1,   149,   196,   374,   267,   327,
     268,    -1,   232,   356,   267,   327,   268,    -1,   212,   267,
       8,   268,    -1,   212,     5,     6,    -1,   213,   267,     8,
     268,    -1,   213,     5,     6,    -1,   212,   267,   327,   268,
      -1,   149,   212,   267,   327,   268,    -1,   213,   267,   327,
     268,    -1,   149,   213,   267,   327,   268,    -1,   387,   378,
       6,    -1,    81,   263,   384,   264,     6,    -1,   387,   387,
     265,   356,   266,   377,     6,    -1,   387,   387,   387,   265,
     356,   266,     6,    -1,   387,   356,     6,    -1,   235,     6,
      -1,   147,   263,     4,   264,   269,     4,     6,    -1,   190,
       4,     6,    -1,   205,     6,    -1,   205,   356,     6,    -1,
     206,     6,    -1,    75,     6,    -1,    76,     6,    -1,    68,
       6,    -1,    68,   267,   356,   272,   356,   272,   356,   272,
     356,   272,   356,   272,   356,   268,     6,    -1,    69,     6,
      -1,    70,     6,    -1,    86,   267,   356,   272,   356,   268,
       6,    -1,    86,     6,    -1,    88,   267,   356,   272,   356,
     272,   356,   268,     6,    -1,    88,   267,   356,   272,   356,
     272,   356,   272,   356,   268,     6,    -1,    87,     6,    -1,
      87,   267,   327,   268,    -1,    89,     6,    -1,    90,     6,
      -1,   128,     6,    -1,   129,     6,    -1,   130,   267,   373,
     268,   267,   373,   268,   267,   368,   268,   267,   356,   272,
     356,   268,     6,    -1,   131,   267,   373,   268,     6,    -1,
     131,   267,   373,   268,   267,   326,   268,     6,    -1,   210,
     263,   267,   373,   268,   272,   378,   272,   378,   264,     6,
      -1,   198,   263,   356,     8,   356,   264,    -1,   198,   263,
     356,     8,   356,     8,   356,   264,    -1,   198,     4,   199,
     267,   356,     8,   356,   268,    -1,   198,     4,   199,   267,
     356,     8,   356,     8,   356,   268,    -1,   200,    -1,   211,
       4,    -1,   211,   378,    -1,   208,    -1,   209,   387,     6,
      -1,   209,   378,     6,    -1,   201,   263,   356,   264,    -1,
     202,   263,   356,   264,    -1,   203,    -1,   204,    -1,   155,
     366,   267,   327,   268,    -1,   155,   267,   366,   272,   366,
     272,   356,   268,   267,   327,   268,    -1,   155,   267,   366,
     272,   366,   272,   366,   272,   356,   268,   267,   327,   268,
      -1,    -1,   155,   366,   267,   327,   337,   341,   268,    -1,
      -1,   155,   267,   366,   272,   366,   272,   356,   268,   267,
     327,   338,   341,   268,    -1,    -1,   155,   267,   366,   272,
     366,   272,   366,   272,   356,   268,   267,   327,   339,   341,
     268,    -1,    -1,   155,   267,   327,   340,   341,   268,    -1,
     155,   267,   327,   268,   146,   121,   267,   356,   268,    -1,
     135,   369,    -1,   140,   135,   369,    -1,   137,   267,   373,
     268,   267,   373,   268,   267,   373,   268,    -1,   138,   267,
     373,   268,   267,   373,   268,   267,   373,   268,   267,   373,
     268,    -1,   342,    -1,   341,   342,    -1,   176,   267,   356,
     268,     6,    -1,   176,   267,   369,   272,   369,   268,     6,
      -1,   177,     6,    -1,   165,     6,    -1,   165,   356,     6,
      -1,   182,     6,    -1,   182,   184,     6,    -1,   183,     6,
      -1,   183,   184,     6,    -1,   178,   263,   356,   264,     7,
     369,   146,   356,     6,    -1,   146,     4,   265,   356,   266,
       6,    -1,   159,    -1,   160,    -1,   161,    -1,   162,    -1,
     163,    -1,    -1,   168,     6,    -1,   149,   168,     6,    -1,
     168,   356,     6,    -1,   149,   168,   356,     6,    -1,   343,
     267,   327,   344,   268,   267,   327,   344,   268,    -1,   118,
     263,   377,   264,    -1,   343,   263,   356,   264,     7,   267,
     327,   344,   268,   267,   327,   344,   268,     6,    -1,    -1,
     146,     4,   356,    -1,    -1,     4,    -1,    -1,     7,   369,
      -1,    -1,     7,   356,    -1,    -1,   157,   369,    -1,   174,
     371,     7,   356,     6,    -1,   124,   125,   371,     7,   356,
       6,    -1,   141,   106,   371,     7,   356,   347,     6,    -1,
     141,   109,   371,   349,   348,     6,    -1,   141,   111,   371,
     349,     6,    -1,   185,   371,     6,    -1,   101,   321,   263,
     356,   272,   356,   264,     6,    -1,   220,   321,   263,   356,
     264,     6,    -1,   172,   109,   267,   373,   268,     7,   356,
       6,    -1,   175,   109,   267,   373,   268,     7,   356,     6,
      -1,   165,   109,   371,   350,     6,    -1,   165,   111,   371,
       6,    -1,   166,   109,   371,     7,   356,     6,    -1,   144,
     106,   267,   373,   268,     7,   267,   373,   268,   351,     6,
      -1,   144,   109,   267,   373,   268,     7,   267,   373,   268,
     351,     6,    -1,   144,   106,   267,   373,   268,     7,   267,
     373,   268,   151,   267,   366,   272,   366,   272,   356,   268,
       6,    -1,   144,   109,   267,   373,   268,     7,   267,   373,
     268,   151,   267,   366,   272,   366,   272,   356,   268,     6,
      -1,   144,   106,   267,   373,   268,     7,   267,   373,   268,
     152,   366,     6,    -1,   144,   109,   267,   373,   268,     7,
     267,   373,   268,   152,   366,     6,    -1,   144,   109,   356,
     267,   373,   268,     7,   356,   267,   373,   268,     6,    -1,
     321,   267,   373,   268,   199,   321,   267,   356,   268,     6,
      -1,   173,   323,   371,     6,    -1,   132,   324,   371,     6,
      -1,   133,   111,   369,     6,    -1,   148,   106,   369,     6,
      -1,   143,   322,   369,     6,    -1,   143,   322,   369,   172,
     356,     6,    -1,   169,     6,    -1,   169,     4,     6,    -1,
     169,   103,   267,   373,   268,     6,    -1,   170,     6,    -1,
     221,    -1,   222,    -1,   223,    -1,   354,     6,    -1,   354,
     267,   369,   268,     6,    -1,   354,   267,   369,   272,   369,
     268,     6,    -1,   354,   263,   369,   264,   267,   369,   272,
     369,   268,     6,    -1,   357,    -1,   263,   356,   264,    -1,
     252,   356,    -1,   251,   356,    -1,   258,   356,    -1,   356,
     252,   356,    -1,   356,   251,   356,    -1,   356,   253,   356,
      -1,   356,   254,   356,    -1,   356,   256,   356,    -1,   356,
     257,   356,    -1,   356,   255,   356,    -1,   356,   262,   356,
      -1,   356,   245,   356,    -1,   356,   246,   356,    -1,   356,
     250,   356,    -1,   356,   249,   356,    -1,   356,   244,   356,
      -1,   356,   243,   356,    -1,   356,   242,   356,    -1,   356,
     241,   356,    -1,   356,   247,   356,    -1,   356,   248,   356,
      -1,   356,   240,   356,     8,   356,    -1,    26,   297,   356,
     298,    -1,    16,   297,   356,   298,    -1,    17,   297,   356,
     298,    -1,    18,   297,   356,   298,    -1,    19,   297,   356,
     298,    -1,    20,   297,   356,   298,    -1,    21,   297,   356,
     298,    -1,    22,   297,   356,   298,    -1,    23,   297,   356,
     298,    -1,    24,   297,   356,   298,    -1,    27,   297,   356,
     298,    -1,    28,   297,   356,   272,   356,   298,    -1,    29,
     297,   356,   298,    -1,    30,   297,   356,   298,    -1,    31,
     297,   356,   298,    -1,    32,   297,   356,   298,    -1,    33,
     297,   356,   298,    -1,    34,   297,   356,   298,    -1,    35,
     297,   356,   298,    -1,    36,   297,   356,   298,    -1,    39,
     297,   356,   272,   356,   298,    -1,    40,   297,   356,   272,
     356,   298,    -1,    41,   297,   356,   272,   356,   298,    -1,
      25,   297,   356,   298,    -1,    38,   297,   356,   272,   356,
     298,    -1,    37,   297,   356,   272,   356,   298,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   228,
      -1,   229,    -1,   230,    -1,    83,    -1,    84,    -1,    85,
      -1,    -1,    94,   297,   356,   358,   308,   298,    -1,   361,
      -1,   218,   297,   377,   298,    -1,   218,   297,   377,   272,
     356,   298,    -1,   363,    -1,   387,   265,   356,   266,    -1,
     387,   263,   356,   264,    -1,   224,   263,   363,   264,    -1,
     224,   263,   363,   269,   299,   264,    -1,   226,   263,   363,
     359,   264,    -1,   226,   263,   363,   269,   299,   359,   264,
      -1,   226,   263,   363,   297,   356,   298,   359,   264,    -1,
     226,   263,   363,   269,   299,   297,   356,   298,   359,   264,
      -1,   225,   263,   378,   264,    -1,   270,   387,   297,   298,
      -1,   270,   363,   269,   299,   297,   298,    -1,    97,   297,
     387,   298,    -1,    97,   297,   298,    -1,   387,   296,    -1,
     387,   265,   356,   266,   296,    -1,   387,   263,   356,   264,
     296,    -1,   387,   269,   299,    -1,   387,     9,   387,   269,
     299,    -1,   387,   269,   299,   263,   356,   264,    -1,   387,
       9,   387,   269,   299,   263,   356,   264,    -1,   387,   269,
     299,   265,   356,   266,    -1,   387,     9,   387,   269,   299,
     265,   356,   266,    -1,   387,   265,   356,   266,   269,   299,
      -1,   387,   269,   299,   296,    -1,   387,   265,   356,   266,
     269,   299,   296,    -1,   214,   263,   377,   272,   356,   264,
      -1,    60,   263,   369,   272,   369,   264,    -1,    61,   297,
     377,   272,   377,   298,    -1,    59,   297,   377,   298,    -1,
      62,   297,   377,   272,   377,   298,    -1,    67,   263,   384,
     264,    -1,    -1,   272,   356,    -1,    -1,   272,   377,    -1,
      -1,    95,   363,   365,   362,   265,   309,   266,    -1,   387,
      -1,   387,     9,   387,    -1,    98,    -1,    98,   356,    -1,
      -1,   263,   364,   264,    -1,   367,    -1,   252,   366,    -1,
     251,   366,    -1,   366,   252,   366,    -1,   366,   251,   366,
      -1,   267,   356,   272,   356,   272,   356,   272,   356,   272,
     356,   268,    -1,   267,   356,   272,   356,   272,   356,   272,
     356,   268,    -1,   267,   356,   272,   356,   272,   356,   268,
      -1,   263,   356,   272,   356,   272,   356,   264,    -1,   369,
      -1,   368,   272,   369,    -1,   356,    -1,   372,    -1,   267,
     268,    -1,   267,   373,   268,    -1,   252,   267,   373,   268,
      -1,   356,   253,   267,   373,   268,    -1,   267,   268,    -1,
     267,   373,   268,    -1,   252,   267,   373,   268,    -1,   369,
      -1,   267,     8,   268,    -1,     5,    -1,   252,   372,    -1,
     356,   253,   372,    -1,   356,     8,   356,    -1,   356,     8,
     356,     8,   356,    -1,   103,   267,   356,   268,    -1,   103,
     267,     8,   268,    -1,   103,     5,    -1,   322,   267,     8,
     268,    -1,   322,     5,    -1,   142,   321,   371,    -1,   145,
     321,   369,    -1,   321,   199,    68,   369,    -1,    68,   321,
     267,   373,   268,    -1,    77,   322,   267,   356,   268,    -1,
      78,   322,   267,   356,   268,    -1,    79,   322,   267,   356,
     268,    -1,   126,    68,   323,   267,   356,   268,    -1,   123,
     109,   267,   356,   268,   126,   267,   356,   272,   356,   268,
      -1,   126,   103,   267,   356,   268,   199,   109,   267,   356,
     268,    -1,   196,   322,   267,   356,   268,    -1,   325,    -1,
     336,    -1,   345,    -1,   387,   297,   298,    -1,   387,   269,
     299,   297,   298,    -1,   387,     9,   387,   269,   299,   297,
     298,    -1,    42,   265,   387,   266,    -1,    42,   265,   372,
     266,    -1,    42,   263,   372,   264,    -1,    42,   297,   267,
     373,   268,   298,    -1,   387,   297,   267,   373,   268,   298,
      -1,    43,   297,   356,   272,   356,   272,   356,   298,    -1,
      44,   297,   356,   272,   356,   272,   356,   298,    -1,    45,
     297,   377,   298,    -1,    46,   297,   356,   272,   356,   272,
     356,   272,   356,   272,   356,   272,   356,   298,    -1,   219,
     297,   372,   298,    -1,    33,   297,   372,   298,    -1,   356,
      -1,   372,    -1,   373,   272,   356,    -1,   373,   272,   372,
      -1,   267,   356,   272,   356,   272,   356,   272,   356,   268,
      -1,   267,   356,   272,   356,   272,   356,   268,    -1,   387,
      -1,     4,   269,   196,   269,     4,    -1,   267,   376,   268,
      -1,   387,   265,   356,   266,   269,   197,    -1,   374,    -1,
     376,   272,   374,    -1,   378,    -1,   387,    -1,   387,   265,
     356,   266,    -1,   387,   263,   356,   264,    -1,   387,   269,
     299,    -1,   387,     9,   387,   269,   299,    -1,   387,   269,
     299,   263,   356,   264,    -1,   387,     9,   387,   269,   299,
     263,   356,   264,    -1,   387,   265,   356,   266,   269,     4,
      -1,   321,   267,   356,   268,    -1,   142,   321,   267,   356,
     268,    -1,     5,    -1,   233,   265,   387,   266,    -1,    71,
      -1,   231,    -1,    80,    -1,    82,    -1,   216,   263,   377,
     264,    -1,   215,   263,   377,   272,   377,   264,    -1,   217,
     297,   377,   298,    -1,   217,   297,   377,   272,   377,   298,
      -1,   227,   263,   363,   360,   264,    -1,   227,   263,   363,
     269,   299,   360,   264,    -1,    52,   297,   384,   298,    -1,
      53,   263,   377,   264,    -1,    54,   263,   377,   264,    -1,
      55,   263,   377,   272,   377,   272,   377,   264,    -1,    50,
     297,   384,   298,    -1,    64,   297,   377,   298,    -1,    65,
     297,   377,   298,    -1,    66,   297,   377,   298,    -1,    63,
     297,   356,   272,   377,   272,   377,   298,    -1,    58,   297,
     377,   272,   356,   272,   356,   298,    -1,    58,   297,   377,
     272,   356,   298,    -1,    51,   297,   377,   298,    -1,    51,
     297,   377,   272,   373,   298,    -1,    72,   297,   377,   298,
      -1,    73,    -1,    74,    -1,    57,   297,   377,   298,    -1,
      56,   297,   377,   298,    -1,    -1,    99,   297,   378,   379,
     312,   298,    -1,    96,   297,   380,   298,    -1,   270,   356,
      -1,   387,     9,   270,   356,    -1,    50,   297,   383,   298,
      -1,   384,    -1,   383,    -1,   267,   384,   268,    -1,   377,
      -1,   385,    -1,   384,   272,   377,    -1,   384,   272,   385,
      -1,   387,   263,   264,    -1,   387,   269,   299,   263,   264,
      -1,   387,     9,   387,   269,   299,   263,   264,    -1,     4,
     271,   267,   356,   268,    -1,   386,   271,   267,   356,   268,
      -1,   234,   265,   377,   266,   271,   267,   356,   268,    -1,
       4,    -1,   386,    -1,   234,   265,   377,   266,    -1
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
    2581,  2623,  2644,  2665,  2691,  2692,  2697,  2700,  2704,  2721,
    2741,  2761,  2780,  2807,  2826,  2847,  2862,  2878,  2896,  2947,
    2968,  2990,  3013,  3118,  3134,  3169,  3194,  3219,  3231,  3237,
    3252,  3283,  3295,  3304,  3311,  3323,  3343,  3347,  3352,  3356,
    3361,  3368,  3375,  3382,  3394,  3467,  3485,  3510,  3525,  3574,
    3580,  3592,  3624,  3628,  3632,  3637,  3644,  3649,  3659,  3664,
    3670,  3678,  3689,  3697,  3701,  3705,  3709,  3716,  3720,  3724,
    3736,  3745,  3804,  3824,  3850,  3866,  3883,  3900,  3922,  3944,
    3979,  3987,  3995,  4001,  4008,  4015,  4035,  4061,  4073,  4084,
    4102,  4120,  4139,  4138,  4163,  4162,  4189,  4188,  4213,  4212,
    4235,  4251,  4268,  4285,  4308,  4336,  4339,  4345,  4357,  4377,
    4381,  4385,  4389,  4393,  4397,  4401,  4405,  4414,  4427,  4428,
    4429,  4430,  4431,  4435,  4436,  4437,  4438,  4439,  4442,  4466,
    4485,  4508,  4511,  4539,  4542,  4559,  4562,  4568,  4571,  4578,
    4581,  4588,  4611,  4630,  4671,  4715,  4754,  4779,  4786,  4797,
    4814,  4831,  4861,  4887,  4913,  4945,  4973,  4999,  5025,  5051,
    5077,  5099,  5111,  5159,  5213,  5228,  5240,  5246,  5258,  5265,
    5280,  5289,  5310,  5311,  5312,  5316,  5322,  5334,  5352,  5380,
    5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,  5395,  5396,
    5397,  5398,  5399,  5400,  5401,  5402,  5403,  5404,  5405,  5406,
    5407,  5408,  5409,  5410,  5411,  5412,  5413,  5414,  5415,  5416,
    5417,  5418,  5419,  5420,  5421,  5422,  5423,  5424,  5425,  5426,
    5427,  5428,  5429,  5430,  5431,  5432,  5433,  5434,  5435,  5444,
    5445,  5446,  5447,  5448,  5449,  5450,  5451,  5452,  5453,  5454,
    5459,  5458,  5466,  5470,  5475,  5480,  5484,  5489,  5494,  5498,
    5502,  5506,  5510,  5514,  5518,  5524,  5539,  5543,  5549,  5554,
    5573,  5593,  5614,  5618,  5622,  5626,  5630,  5634,  5638,  5643,
    5653,  5663,  5668,  5679,  5688,  5693,  5698,  5726,  5727,  5733,
    5734,  5740,  5739,  5762,  5764,  5769,  5771,  5777,  5778,  5783,
    5787,  5791,  5795,  5799,  5806,  5810,  5814,  5818,  5825,  5830,
    5837,  5842,  5846,  5850,  5854,  5862,  5873,  5877,  5881,  5892,
    5896,  5900,  5914,  5922,  5930,  5937,  5947,  5970,  5975,  5981,
    5986,  5992,  6003,  6009,  6023,  6029,  6041,  6055,  6068,  6098,
    6120,  6140,  6157,  6167,  6177,  6187,  6199,  6203,  6208,  6220,
    6224,  6228,  6232,  6250,  6258,  6266,  6295,  6305,  6321,  6332,
    6337,  6341,  6345,  6357,  6361,  6373,  6390,  6400,  6404,  6419,
    6424,  6431,  6435,  6440,  6454,  6468,  6472,  6476,  6480,  6484,
    6492,  6498,  6507,  6511,  6515,  6523,  6529,  6535,  6539,  6546,
    6554,  6561,  6570,  6574,  6578,  6593,  6607,  6621,  6633,  6649,
    6658,  6667,  6677,  6688,  6696,  6704,  6708,  6726,  6733,  6739,
    6745,  6752,  6760,  6759,  6769,  6793,  6795,  6801,  6806,  6808,
    6813,  6818,  6823,  6825,  6829,  6841,  6855,  6859,  6866,  6874,
    6882,  6893,  6895,  6898
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
  "tWire", "tGeoEntity", "tNormal", "tCharacteristic", "tLength",
  "tParametric", "tElliptic", "tRefineMesh", "tRecombineMesh",
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
      63,   495,   496,   497,   498,    60,    62,   499,   500,   501,
     502,    43,    45,    42,    47,    37,   124,    38,    33,   503,
     504,   505,    94,    40,    41,    91,    93,   123,   125,    46,
      35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   273,   274,   274,   275,   275,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   277,   277,   278,   278,
     278,   278,   278,   278,   278,   278,   279,   279,   279,   279,
     280,   280,   280,   280,   280,   280,   280,   281,   281,   282,
     282,   284,   285,   283,   286,   286,   288,   287,   289,   289,
     291,   290,   292,   292,   294,   293,   295,   295,   295,   295,
     295,   296,   296,   297,   297,   298,   298,   299,   299,   299,
     299,   299,   299,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   301,   301,
     302,   302,   302,   303,   302,   304,   302,   302,   305,   302,
     306,   306,   307,   307,   307,   308,   308,   309,   309,   310,
     310,   311,   311,   311,   311,   311,   311,   311,   311,   312,
     312,   313,   313,   314,   314,   314,   314,   314,   315,   315,
     315,   316,   316,   316,   316,   317,   317,   318,   318,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   320,   319,   321,   321,   321,
     321,   321,   322,   322,   322,   322,   323,   323,   323,   324,
     324,   324,   324,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   326,   326,   327,   327,   327,   327,
     327,   327,   327,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   330,   331,   332,   332,   332,   332,
     332,   332,   332,   332,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   334,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   336,
     336,   336,   337,   336,   338,   336,   339,   336,   340,   336,
     336,   336,   336,   336,   336,   341,   341,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   343,   343,
     343,   343,   343,   344,   344,   344,   344,   344,   345,   345,
     346,   347,   347,   348,   348,   349,   349,   350,   350,   351,
     351,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   353,   353,
     353,   353,   354,   354,   354,   355,   355,   355,   355,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     358,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   359,   359,   360,
     360,   362,   361,   363,   363,   364,   364,   365,   365,   366,
     366,   366,   366,   366,   367,   367,   367,   367,   368,   368,
     369,   369,   369,   369,   369,   369,   370,   370,   370,   371,
     371,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   373,
     373,   373,   373,   374,   374,   374,   374,   375,   375,   376,
     376,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   379,   378,   378,   380,   380,   381,   382,   382,
     383,   384,   384,   384,   384,   385,   385,   385,   386,   386,
     386,   387,   387,   387
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
       1,     1,     4,     5,    11,     5,     9,     9,     7,     5,
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
       0,     0,     0,     2,     3,     1,   651,     0,     0,     0,
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
      16,     0,    17,    18,    19,    20,     0,    25,     0,   652,
       0,   236,     0,     0,     0,     0,     0,     0,   287,     0,
     289,   290,   285,   286,     0,   292,     0,   295,   236,     0,
     297,   298,   120,   130,   651,   517,   513,    73,    74,     0,
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
       0,     0,     0,     0,     0,     0,     0,   464,   465,   466,
       0,     0,     0,     0,     0,     0,     0,     0,   562,   563,
       0,   564,   530,   409,   472,   475,   331,   531,   513,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   212,
     213,     0,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     519,     0,     0,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     651,     0,     0,   236,     0,     0,   398,     0,   401,     0,
       0,   216,   217,     0,     0,   541,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,     0,   585,     0,     0,     0,     0,   282,
       0,     0,     0,   513,   284,     0,   602,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     604,     0,   628,   629,   606,   607,     0,     0,     0,     0,
       0,     0,   605,     0,     0,     0,     0,   310,   311,     0,
     236,     0,   236,     0,     0,     0,   279,     0,     0,   236,
     405,     0,     0,    85,     0,    66,     0,     0,    70,    69,
      68,    67,    72,    71,    73,    74,     0,     0,     0,     0,
       0,     0,     0,   591,   513,     0,   235,     0,   234,     0,
     186,     0,     0,   591,   592,     0,     0,     0,   641,     0,
     642,   592,     0,     0,     0,   118,   118,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   579,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   412,     0,   411,   542,   413,     0,
     532,     0,     0,   513,     0,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       0,   489,     0,     0,     0,     0,     0,     0,     0,   332,
       0,   365,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,   236,   236,     0,   521,
     520,     0,     0,     0,     0,   236,   236,     0,     0,     0,
       0,   328,     0,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,     0,   367,     0,     0,     0,
       0,     0,     0,   236,   262,     0,     0,   260,   399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,   281,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,     0,   411,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,   313,     0,   267,     0,
       0,   269,     0,     0,     0,   236,     0,     0,     0,   353,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    80,
      78,    79,    81,    82,     0,     0,     0,     0,    89,    75,
      76,     0,     0,     0,   278,    40,   274,     0,     0,     0,
       0,     0,   230,     0,     0,     0,     0,     0,   237,     0,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,   119,     0,     0,     0,   515,     0,     0,   514,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,     0,
       0,     0,   211,     0,     0,     0,     0,     0,     0,     0,
     393,   394,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   470,   488,
       0,     0,     0,     0,     0,     0,     0,   551,   552,     0,
       0,     0,     0,     0,     0,   507,     0,   410,   533,     0,
       0,     0,     0,   544,     0,   429,   428,   427,   426,   422,
     423,   430,   431,   425,   424,   415,   414,     0,   416,   543,
     417,   420,   418,   419,   421,   514,     0,     0,   492,     0,
     565,     0,     0,     0,     0,     0,     0,     0,     0,   363,
       0,     0,     0,     0,     0,     0,   396,     0,     0,     0,
       0,     0,   395,     0,   236,     0,     0,     0,     0,     0,
     523,   522,     0,     0,     0,     0,     0,     0,     0,   322,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,     0,     0,     0,   261,     0,
       0,     0,   255,     0,     0,     0,     0,   392,   410,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,   316,     0,   416,   514,
     492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
       0,     0,     0,   509,     0,     0,   266,   270,   268,   272,
       0,     0,   653,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,   410,     0,     0,     0,    66,
       0,     0,    88,     0,    66,    67,     0,     0,     0,   514,
       0,     0,   492,     0,     0,     0,   205,     0,     0,     0,
     648,    28,    26,    27,     0,     0,     0,     0,     0,   595,
      30,     0,    29,     0,     0,   275,   643,   644,     0,   645,
     595,     0,     0,    83,   121,    84,   131,   516,   518,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   581,   582,   302,   236,   222,     9,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   456,
     433,   443,     0,   445,   446,   447,   448,   449,   578,   450,
     451,   452,     0,     0,     0,     0,     0,   570,   569,   568,
       0,     0,     0,   575,     0,   504,     0,     0,     0,   506,
       0,     0,     0,     0,   135,   487,   547,   546,   215,     0,
       0,     0,     0,     0,     0,   473,   577,   478,     0,   484,
       0,     0,     0,     0,   534,     0,     0,   485,   553,   549,
       0,     0,     0,     0,   477,   476,    73,    74,   499,     0,
       0,     0,     0,     0,     0,     0,   410,   361,   366,   364,
       0,   375,     0,   158,   159,     0,   215,     0,   410,     0,
       0,     0,     0,     0,   256,     0,   271,   273,     0,     0,
       0,   223,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   335,     0,   319,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   229,     0,
     368,   381,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   218,   371,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,   618,     0,   625,   614,   615,   616,     0,   631,
     630,     0,     0,   619,   620,   621,   627,   635,   634,     0,
     149,     0,   608,     0,   610,     0,     0,     0,   603,     0,
       0,   265,     0,     0,     0,     0,   354,     0,     0,     0,
     406,     0,   649,     0,   110,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
       0,     0,   600,    51,     0,     0,     0,    64,     0,    41,
      42,    43,    44,    45,    46,     0,   477,   476,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,   138,   139,     0,
       0,     0,     0,   165,   165,     0,     0,     0,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     372,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,   555,   556,
     557,     0,     0,     0,     0,     0,   561,     0,     0,     0,
     507,   508,     0,   480,     0,     0,   545,   432,   535,   493,
     491,     0,   490,     0,     0,   566,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,     0,     0,     0,     0,
       0,   397,     0,     0,     0,    77,     0,   264,     0,     0,
       0,     0,     0,     0,     0,   340,     0,     0,   339,     0,
     342,     0,   344,     0,   329,   336,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
       0,     0,   259,   258,   400,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,   586,     0,     0,     0,
     305,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,   510,   612,     0,   378,     0,     0,
     236,   355,     0,   356,   236,     0,     0,   601,     0,    95,
       0,     0,     0,     0,    93,     0,   589,     0,   108,     0,
     100,   102,     0,     0,     0,    90,     0,     0,     0,     0,
       0,    36,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,     0,   596,     0,
       0,    34,    33,     0,   596,   646,   291,     0,     0,   122,
     127,     0,     0,     0,   141,   147,   148,   144,   142,   143,
     512,     0,    86,     0,    87,   169,     0,     0,     0,     0,
     170,   189,   190,   167,     0,     0,     0,   171,   200,   191,
     195,   196,   192,   193,   194,   179,     0,     0,     0,   444,
     458,   457,   453,   454,   455,   571,     0,     0,     0,   502,
     503,   505,   136,   471,     0,   558,     0,   501,   474,   479,
       0,     0,   507,   201,   486,    73,    74,     0,   498,   494,
     496,   572,   197,     0,     0,     0,   161,     0,     0,   373,
       0,   160,     0,     0,     0,     0,     0,     0,   280,     0,
       0,     0,     0,   236,   236,     0,     0,   341,   530,     0,
       0,   343,   345,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   198,     0,     0,
       0,     0,     0,     0,     0,   176,     0,   177,     0,     0,
       0,     0,     0,     0,   111,   115,     0,   626,     0,     0,
     624,     0,   636,     0,     0,   150,   151,   633,   609,   611,
       0,     0,     0,     0,   353,   357,   353,     0,   407,    94,
       0,     0,    66,     0,     0,    92,     0,   587,     0,     0,
       0,     0,     0,     0,   639,   638,     0,     0,     0,     0,
       0,   528,     0,     0,    77,   276,   494,   277,     0,     0,
       0,     0,     0,   241,   238,     0,     0,   599,   597,     0,
       0,     0,     0,   123,   128,     0,     0,     0,   579,   580,
     140,   377,   166,   174,   175,   180,     0,     0,     0,     0,
       0,   182,     0,     0,   303,     0,     0,     0,     0,     0,
       0,   481,     0,     0,     0,   567,   500,     0,     0,   181,
       0,   202,   362,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,   527,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,     0,     0,
     379,   380,    39,   184,   185,     0,   584,     0,     0,   307,
     306,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   157,   156,   155,     0,   613,     0,   650,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,   590,     0,
       0,     0,    97,     0,     0,     0,    47,     0,     0,     0,
       0,     0,    49,     0,   242,   239,   240,    35,     0,     0,
     647,   293,     0,   135,   149,     0,     0,   146,     0,     0,
       0,   168,   199,     0,     0,     0,     0,     0,   573,   574,
       0,     0,     0,   507,   482,   495,   497,     0,     0,   183,
     206,     0,     0,     0,   369,   369,     0,   116,   117,   236,
       0,   226,   227,   330,     0,   337,     0,     0,   236,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,   231,
       0,     0,     0,     0,   536,     0,   112,   114,   113,   617,
     623,   622,   152,     0,     0,     0,   358,     0,     0,   109,
     101,   103,     0,    91,   640,    98,    99,    52,     0,     0,
       0,     0,   529,     0,     0,   495,   598,     0,     0,     0,
       0,   125,   637,     0,   132,     0,     0,     0,     0,   188,
       0,     0,     0,     0,     0,   333,     0,   172,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   525,
       0,   347,     0,     0,   324,     0,   244,     0,     0,     0,
       0,     0,     0,   232,     0,   583,   308,     0,   537,     0,
     391,   236,   408,     0,   588,     0,    48,     0,     0,     0,
      65,    50,     0,   294,   124,   129,   135,     0,     0,   163,
     164,   162,     0,     0,     0,   560,   483,     0,     0,     0,
       0,   370,   384,     0,     0,   385,     0,   224,     0,   338,
       0,   320,     0,   236,     0,     0,     0,     0,     0,     0,
     178,   538,   304,   353,   107,     0,     0,     0,     0,     0,
       0,   133,   134,     0,     0,   559,     0,   204,     0,   388,
       0,   389,   390,   524,     0,     0,   326,   247,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,    62,     0,
       0,   126,     0,     0,   334,     0,     0,   346,   325,   321,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,   251,     0,   245,   360,    53,     0,    60,     0,   288,
       0,   576,     0,     0,   327,     0,     0,    54,     0,     0,
     301,     0,     0,   246,     0,     0,     0,     0,     0,     0,
      57,    55,     0,    58,     0,   386,   387,     0,     0,    63,
      61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   125,  1134,   126,   127,  1118,  2015,  2021,
    1429,  1656,  2185,  2316,  1430,  2289,  2332,  1431,  2318,  1432,
    1433,  1660,   467,   631,   632,  1207,  1758,   128,   833,   495,
    2033,  2196,  2034,   496,  1897,  1512,  1466,  1467,  1468,  1620,
    1835,  1836,  1282,  1716,  1707,  1907,   808,   643,   296,   297,
     374,   216,   298,   477,   478,   132,   133,   134,   135,   136,
     137,   138,   139,   299,  1317,  2222,  2280,  1007,  1313,  1314,
     300,  1097,   301,   143,  1544,  1280,   979,  1023,  2153,   144,
     145,   146,   147,   302,   303,  1234,  1253,  1387,   304,   838,
     305,   837,   498,   660,   340,  1870,   378,  1984,   379,   307,
     601,   393,  1413,  1647,   488,   483,  1380,  1077,  1696,  1863,
    1864,  1062,   490,   149,   403
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2002
static const yytype_int16 yypact[] =
{
   14183,   100,    46, 14394, -2002, -2002,   -89,    71,    88,  -167,
     -17,     4,    39,   227,   273,   294,   332,    97,    43,    53,
      98,   435,   459,   125,   144,    27,  -196,   671,  -196,   281,
     316,   350,    40,   379,   395,    62,   402,   413,   448,   454,
     464,   467,   497,   500,   512,   528,   239,   391,   417,   578,
     772,   280,   591,    61,   744,   600,  7388,   603,   608,   629,
     786,   -48,   655,   671,   346,    90,   623,   800,   -98,   641,
     461,   461,   647,   518,    52,   672,   461, -2002, -2002, -2002,
   -2002, -2002,   650,   295,   806,   816,    22,    48,   917,   836,
     834,   -49,  6344,   853,   954,   955,   960,  6344,   980,   -76,
     -73,   731,    23,    64, -2002,   732,   754, -2002, -2002,  2699,
    1012,   765, -2002,  1566,   756, 14647,     2,    13,   671, -2002,
   -2002, -2002, 12955,   771,  1025, -2002, -2002, -2002, -2002, -2002,
     770, -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002,
   -2002,   -37, -2002, -2002, -2002, -2002,    42, -2002,  1033,   781,
    5401,   388,   788,  1101, 12955, 14584, 14584, 14584, -2002, 12955,
   -2002, -2002, -2002, -2002, 14584, -2002, 12955, -2002, -2002, 12955,
   -2002, -2002, -2002, -2002,   838,   856,  1114, -2002, -2002, 14684,
   -2002, -2002, -2002, -2002,   861, 14684, 12955, 12955, 12955,   862,
   12955, 12955, 12955,   866, 12955, 12955, 12955, 12955, 12955, 12955,
   12955, 14584, 12955, 12955, 12955, 12955,  6344,   867, -2002, -2002,
   10510, 10510, -2002, -2002, -2002,   881,  6344,  7649, 14584, -2002,
   -2002, -2002, -2002, -2002,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
     -92,  -196,  -196,  -196,  -196,  -196,   892,  -196,  -196,   893,
     671,   690,   690,   690, -2002, -2002, -2002,  -196,  -196,    20,
     958,   959,   961,   896,  1050,   -10,  7649,  1032,   671,   671,
     690,   915,  -196,  -196,   916,   918,   919, -2002, -2002, -2002,
   12955,  7910, 12955, 12955,  8171,    27,   984,    32, -2002, -2002,
     941, -2002,  5652, -2002, -2002, -2002, -2002, -2002,   126, 12955,
   10510, 10510,   921,   946,  8432,  6344,  6344,  6344, -2002, -2002,
   -2002,   947, -2002,   945,   951,  8693,   948,  4597,  1212,  7649,
     950,    23,   952,   953,   461,   461,   461, 12955, 12955,   199,
   -2002,   374,   461, 11477,   403,    94,   963,   964,   965,   966,
     967,   968,   969, 10510,   438, 12955,  6344,  6344,  6344,   180,
      31,  1215,   957, -2002,  1227,  1228, -2002,   970, -2002,   971,
     972, -2002, -2002,   974,  6344, -2002, 12955,  6605, -2002,  1229,
     975,   978,   979,   981,  1239,  1241,   985, 12955,   986, 12955,
   12955,   226, 12955,   983, -2002,  1036, 12955, 12955, 12955, -2002,
    -196, 12955,   949,   136, -2002, 12955, -2002,  -196,  -196,  -196,
     988,   990,   991,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
   -2002,  -196, -2002, -2002, -2002, -2002,  -196,  -196,   993,   995,
    -196,   996, -2002,   997,  1254,  1255,   998, -2002, -2002,  1257,
    1256,  1260,  1259,  1008, 16240, 14584, -2002, 10510, 12955, -2002,
   -2002,  7649,  7649, -2002,  1022, 14684,   671,  1285, -2002, -2002,
   -2002, -2002, -2002, -2002, 12955, 12955,   441,  7649,  1287,   812,
    1028,  1467,  1030,  1290,   103,  1031, -2002,  1034, 14821, 12955,
   -2002,  1622,  -190, -2002,    82,  -169,  -139,  7581, -2002,   -30,
   -2002,    93,  7842,  5202,  8103,   -62,   111,  1202, -2002,    27,
    1027, 12955,  1035, 16756, 16781, 16806, 12955, 16831, 16856, 16881,
   12955, 16906, 16931, 16956, 16981, 17006, 17031, 17056,  1037, 17081,
   17106, 17131,  6082,  1297, 12955, 10510,  5758, -2002,   284,   321,
   12955,  1300,  1303,  1046, 12955, 12955, 12955, 12955, 12955, 12955,
   12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955,
   12955, 10510, 12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955,
   10510, 10510,  1044, 12955, 12955, 14584, 12955, 14584,  7649, 14584,
   14584, 14584,  1045,  1047,  1048,  1051, 12955,   109, -2002, 11565,
   12955,  1052,   -49,  1053,  7649,  6344,  7649,  1054, 14584, 14584,
   10510,    27, 14684,    27,  1055, 10510,  1055, -2002,  1055, 17156,
   -2002,   329,  1056,   113,  1245, -2002,  1314, 12955, 12955, 12955,
   12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955, 12955,
   12955,  8954, 12955, 12955, 12955, 12955, 12955,    27, 12955, 12955,
     482, -2002,   887, 17181,   409,   427, 12955, 12955, 12955, -2002,
    1316,  1317,  1317,  1065, 12955, 12955, 12955, 12955,    44, 10510,
   10510, 16268,  1070,  1329, -2002,  1069, -2002, -2002,  -143, -2002,
   -2002,  8364,  8625,   461,   461,   388,   388,  -110, 11477, 11477,
   12955, 11532,   -66, -2002, 12955, 12955, 12955, 12955, 12955, 12955,
   12955, 12955, 12955,   457,   388, 17206,  1330,  1332,  1333, 12955,
   12955,  1335, 12955, -2002, -2002, 12955, 12578, -2002, -2002, 10510,
   10510, 10510, 12955,  1336, 17231,  1071, 12955, 10510, 12955, 12955,
   12955, -2002, -2002, 12955, 17256, 12955, 17281, 17306,  1147,  8886,
   -2002,  1077,  5781, 17331, 17356, 12955,  1055, -2002, 12955,    27,
   12955, 12955,   482, 16351, 14584, 14584, 14584, 14584, 14584, 14584,
   14584, 14584, 14584, 12955, 14584, 14584, 14584, 14584,    11, 14684,
   14584, 14584, 14584,    27,    27, -2002, -2002, 10510, -2002,  1078,
   13137, -2002,  1081, 13201, 12955, -2002,  1086,   515, 17381, 14746,
    1090,   541, 12955,  1349,  1089,  7649, 17406, 16378, -2002, -2002,
   -2002, -2002, -2002, -2002,  1092,  1355,   193,  1357, -2002, -2002,
   -2002, 10510,   236, 12955, -2002, -2002, -2002,    27, 12955, 12955,
     482,  1099, -2002,  1103,   -45,   671,   346,   671, -2002,  1100,
   15138, -2002,    37, 10510,    27, 12955, 12955,   482,  1362, 10510,
    1364, 10510, 12955,  1365, 14584,    27, 11821,   482, 12955, -2002,
   12955,  1366, -2002,    27,  1367, 14584, 12955,  1110,  1111, -2002,
   12955,  9147, 14684,  1368,  1370,  1372, 17431,  1374,  1375,  1377,
   17456,  1378,  1380,  1382,  1383,  1384,  1386,  1387, -2002,  1388,
    1390,  1391, -2002, 12955, 17481, 10510,  1132, 10510,    56, 15167,
   -2002, -2002,  1394, 16324, 16324, 16324, 16324, 16324, 16324, 16324,
   16324, 16324, 16324, 16324, 16324,  9403, 16324, 16324, 16324, 16324,
     759,   520, 16324, 16324, 16324,  9659,  9920, 10181, 10442, 10797,
    5758,  1137,  1136,   119, 10510, 11155, 11508,   520, 11776,   520,
    1131,  1133,  1134,   -14, 10510, 12955, 12955, 12955, 18431, -2002,
     520,  1139, 15196, 15225, 12955,  1141, 12955, -2002, -2002, 12955,
    1138,   174,   520,  -130,  1140,  -145,   552,  1404, -2002,   482,
     520,  7649,  1144,  5983,  6279,   890,  1029,   839,   839,   617,
     617,   617,   617,   617,   617,   628,   628, 10510,   276, -2002,
     276,   276,  1055,  1055,  1055,  1145, 17506, 16405,   554, 10510,
   -2002,  1408,  1149,  1150, 17531, 17556, 17581, 12955,  7649,  1415,
    1414, 11221, 17606, 15254, 17631, 17656, -2002, 12955,   555,   588,
   10510,  1152, -2002, 13304, -2002, 13367, 13470,   461, 12955, 12955,
   -2002, -2002,  1154,  1155, 11477,  3480,  1279,   538,   461, 13533,
   17681, 15283, 17706, 17731, 17756, 17781, 17806, 17831, 17856,  1159,
    1160,  1420, 12955,  1423, -2002, 12955, 17881, 15312, -2002, 16432,
   13636, 16459, -2002,   589,   619,   620, 15341, -2002, -2002, -2002,
    1756,   625, 16486, 16513, 11852, 17906,  1424, 17931,  1425,  1428,
    1161, 12955, 13699, 12955, 12955, -2002, -2002, 16324,   276,  1167,
     568,    35,   243,   305,   243,  1173,  1174,  1168,   520,   520,
    1170, 12127,   520,   520,   520,   520, 12955,   520,  1434, -2002,
    1172,  1181,   531,  -126,  1180,   626, -2002, -2002, -2002, -2002,
   17956, 13802,  1176,  1249,  1442,  1282, 11916,  1183,  1185,  1447,
    7649, 15370, -2002, 12955,  1448,   198,    79,   482,    30, 14684,
   12955,  1449, -2002,   632,  1406,  1407,  7649, 15399,    51,  1191,
   17981, 16540,   356, 12955, 12955,  1198,  1195,  1200,  1197,  9215,
   -2002, -2002, -2002, -2002, 14584,    77,  1196, 18006, 16567,  1203,
   -2002,   216, -2002,   249, 12203, -2002, -2002, -2002,  1199, -2002,
    1204, 15428, 12554, -2002,    81, -2002, -2002, 18431, -2002,   112,
   16324, 12955,   520,   461,  7649,  7649,  1462,  7649,  7649,  7649,
    1463,  7649,  7649,  7649,  7649,  7649,  7649,  7649,  7649,  7649,
    7649,  1989,  1464, 10510,  5758, -2002, -2002,   388, -2002, -2002,
   -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002,
   -2002, -2002, 12955, -2002, -2002, -2002, -2002, -2002, -2002, -2002,
   -2002, -2002, 12955, 12955, 12955, 12955, 12955, -2002, -2002, -2002,
     637, 12955, 12955, -2002, 12955, -2002,  7649, 14584, 14584, -2002,
     648, 15457, 15486, 15515,  1206, -2002, -2002, -2002,  1275, 15544,
   12955, 15573, 15602, 12955, 12955, -2002, -2002, -2002,   482, -2002,
     482, 12955, 12955,  1211, -2002,  7649,  -196, -2002, -2002, -2002,
   12955, 12955,   653,   482,   300,   -68, 12955, 12955, -2002,   520,
     656,  7649, 10510, 10510,  1472,  1473,  1474,  4230, -2002, -2002,
    1476, -2002,  1219, 18431,  1213,  1477, -2002,  1479,  1480,  2105,
    1481,  1482,   661,   596, -2002, 13865, -2002, -2002,   -63, 13107,
   13273, -2002, -2002, 15631,  -171,  1371,  1489, 12172,  1238,  1488,
    1232,    18,    41,   -46, -2002,   -40, -2002,   538,  1503,  1505,
    1509,  1510,  1511,  1513,  1514,  1516,  1517,   388, -2002,  7649,
   18431, -2002,  2391,  1261,  1429,  1521, -2002,  1527,  1528,  1426,
    1529, -2002, -2002,  1533,  1535,  1536, 12955,  1537,  7649,  1541,
    7649,  7649,  1539, 13439, -2002,  6537,   818,   482, 12955, 12955,
     482,   482, -2002, 10510, -2002, -2002, -2002, -2002, 14584, -2002,
   -2002, 12955, 14584, -2002, -2002, -2002, -2002, 18431, -2002,  1280,
    1277, 14584, -2002, 14584, -2002,   482, 14584,  1289, -2002,  1283,
    1545, -2002,  1291,   671,  1292, 12267, -2002,  2924,  1293,  7649,
   -2002,  1286, -2002, 15660, -2002, -2002, 12955,  1550,   486, 12955,
    1551,  1554,    23,  1556,  1301,  1559,  3114, -2002,   520,  -196,
    -196,  1562, -2002, -2002,  1310,  1311,  1309, -2002,  1571, -2002,
   -2002, -2002, -2002, -2002, -2002,   482,   209,  2338, 12955, 16594,
   18031, 12955,  9471, 12955, 10510,  1312,   662,  1572,    86,   482,
   -2002,  1313, 12955,  1573,  1575, 12955,   482, 12523,  1578, 12955,
   10766,   520,  5719, 12955, 12955, 12955,  1319,  1318, -2002,  1583,
   18056,  1585,    24,  1454,  1454,  7649,  1588,  1589,  1590,  7649,
     -95,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
   -2002,  1605,   663,  1343, 16324, 16324, 16324, 16324, 16324, 16324,
     520, 13605, 13771, 13963,  1348,   520,   520, -2002, -2002, -2002,
   -2002,   112,   520,  1487, 15689,  1416, -2002, 18081, 16324,  1361,
       0, 18431, 16324, -2002,  1627,   520, 18431, 18431, -2002,   539,
   -2002,   482, -2002, 18106, 16621, -2002,   520,  1628,   664,   669,
    7649,  7649,  7649,  1631,  1630, -2002,   263, 12955,  7649,  7649,
    7649, -2002,  1376,  1392,  1634,  1638,  1640, -2002, 12955, 12955,
   12955,  1393,  1396,  1397,  1389, -2002,  3189,  7649, -2002, 12955,
   -2002,  1639, -2002,  1649, -2002, -2002, 11477,    -2,  6866, -2002,
    1399,  1400,  1402,  1403,  1405,  1413,  9727,  1418,  1651, -2002,
   10510,  1421, -2002, -2002, -2002,  1422, 12955, 12955, -2002, -2002,
   16648,  7649,  1652,  7649,  1655,  1478, -2002, 12955, 12955, 12955,
   -2002,   571,  1665,   646,   534,  1409,  4079,  1410, 12955,    36,
     520,  1411,   520,  1419, -2002, -2002, 14684, -2002, 12955,  1427,
   -2002, -2002,  3575, -2002, -2002,  1430,  1677, -2002,  3637, -2002,
    1431,  1680,   224,  3733, -2002,    23, -2002,   676, -2002, 12955,
   -2002, -2002,   263,  2758, 13004, -2002,  1432, 12955, 12955,  7649,
    1436, -2002,  -107,   606,  1686, 18131,  1687,  1404, 18156,  1433,
     677, 18181,   685,  1690,  1691, -2002, -2002, 14584,  1441,  1695,
   18206, -2002, -2002, 14182,  1443, -2002, -2002,  5447,  6051, 18431,
   -2002,  1718,  -196,  8171, -2002, -2002, -2002, 18431, 18431, 18431,
   -2002,   112, -2002,  1720, -2002, -2002,   461,  1721,  1722,  1724,
   -2002, -2002, -2002,  1586,   -38,  1624,  1727, -2002, -2002, -2002,
   -2002, -2002, -2002, -2002, -2002, -2002,  1730,  1469,  1731, -2002,
   -2002, -2002, -2002, -2002, -2002, -2002, 12955, 12955, 12955, -2002,
   -2002, -2002,  1318, -2002,  1471, -2002,  1632, -2002, -2002, -2002,
   12955,  1475,  1468, -2002, -2002, 12955, 12955,   520,   300, -2002,
   -2002, -2002, -2002,  1484,  1494,  1742,   -95,  1743, 12955, -2002,
    7649, 18431,  1608,  1610,   872, 10510, 10510, 12955, -2002, 11221,
   15718, 18231,  6798,   388,   388, 12955, 12955, -2002,   171,  1491,
   18256, -2002, -2002, 15747,   -31, -2002,  1758,  1759,  7649,   461,
     461,   461,   461,   461,  7127,  1760, -2002, -2002,   688, 10510,
   12955,  3784,  3838,  1764,  1768, -2002,  1769, -2002,  7649,  7059,
     597, 18281, 12955, 12955, -2002, -2002, 10863, -2002, 14584, 12955,
   -2002, 14584, 18431, 11124, 14684,  1504, -2002, -2002, -2002, -2002,
    1520,  1508, 15776, 12955, 14746, -2002, 14746,  7649, -2002, -2002,
     482,    30, 14684, 12955,  1771, -2002,  1780, -2002,    23, 16675,
    7649, 14584,  1782,   520, -2002,  1519,   520, 12955, 14727, 14775,
     693, -2002, 12955, 12955,  1522, -2002,  1538, -2002,  1474,  1788,
    1796,  1480,  1797, -2002, -2002,  1798, 12955, -2002, -2002, 12955,
   12611,  1801, 12955, -2002, -2002,  1544, 13004,   699,  3064,  1805,
   -2002, -2002,   556, -2002, -2002, -2002,  1658,  1807,  1549,  1552,
    1553, -2002,  1812,  7649, -2002, 16324, 16324, 14808, 12955,  1555,
   16324, -2002,  1557, 18306, 16702, -2002, -2002, 10510, 10510, -2002,
    1817, -2002, 18431,  1818, 12955, 12955,  1560, -2002,   701,   702,
   16296,  3891,  1820,  1563, -2002, -2002, 12955,  1561,  1564, 15805,
   16729,  1825,  7649,  1811,  1567, 12955, -2002, -2002,   704,   -28,
     -24,   231,   242,   253,  9988,   298, -2002,  1827,   710, 15834,
   -2002, -2002, -2002, -2002, -2002,  1641, -2002, 12955, 12955, -2002,
   -2002, 12867, 10249,  3985,  1830,  1831,  1574, 16324,   520, 18431,
   -2002, -2002, -2002, -2002,    36, -2002, 14684, -2002, 15863,  1577,
    1579,  1581,  1832,  1834,  1835,  4117, -2002, -2002, -2002,  1582,
    1836,   711, -2002,  1837,  1840,   279, 18431, 12955, 12955,  1587,
    7649,   717, 18431, 18331, -2002, -2002, -2002, -2002, 18356, 14841,
   -2002, -2002, 15892,  1206,  1277,  7649,   520, -2002, 12955, 14684,
      27, -2002, -2002, 10510, 10510, 12955,  1844,   718, -2002, -2002,
   12955, 14874, 12955,  1468, -2002, -2002, -2002,   724,   725, -2002,
   -2002,  4173,  4198,  7649,   488,   536, 10510, -2002, -2002,   388,
    7320, -2002, -2002, -2002,  1846, -2002,  1591,  7649, -2002, 15921,
    1850, 10510,   461,   461,   461,   461,   461, -2002,  1854, -2002,
   12955, 15950, 15979, 10510, -2002,   752, -2002, -2002, -2002, -2002,
   -2002, -2002, -2002,  1616,  1855,  1615, -2002,  1877,    23, -2002,
   -2002, -2002,  1688, -2002, -2002, -2002, -2002, -2002, 12955, 14907,
   14940,  7649, -2002,  1880, 12955,  1620, -2002, 12955,  1882,  1621,
    1626, -2002, -2002,  4999, -2002,  1629,   760,   761, 16008, -2002,
    1623, 14973, 12955, 16037,  1633, -2002,  1635, -2002, -2002,   766,
    1636,   461,  7649,  1889,  1637,   461,  1892,   774,  1643, -2002,
   12955, -2002,  1893,  1754, 13968,  1642, -2002,   776,   324,   376,
     378,   384,   428, -2002,  4801, -2002, -2002,   777, -2002,  1895,
   -2002, -2002, -2002,  1899, -2002,  1645, 18431, 12955, 12955,   779,
   -2002, 18431, 15006, -2002, -2002, -2002,  1206, 14684,  1644, -2002,
   -2002, -2002, 12955, 12955, 16066, -2002, -2002, 10510,  1900,   461,
     142, -2002, -2002,   461,   151, -2002,  1901, -2002, 16095, -2002,
   12955, -2002,   538, -2002,  1907, 10510, 10510, 10510, 10510,  9988,
   -2002, -2002, -2002, 14746, -2002, 12955, 18381, 15039,    57, 12955,
    1646, -2002, -2002, 15072, 15105, -2002,   782, -2002,   434, -2002,
     450, -2002, -2002, -2002,  4948,   352, 14031, -2002,   785,   809,
     830,   831,   501,   832,  1647,   840, -2002, 12955, -2002,  7649,
   16124, -2002, 12955, 12955, -2002,   461,   461, -2002, -2002, -2002,
     538,  1910,  1911,  1912,  1913, 10510,  1914,  1915,  1917,  1659,
   18406,   842,  1921, 16153, 16324,   504,   507,   426, -2002, -2002,
   -2002, -2002,   843, -2002, -2002, -2002, 14584, -2002,  1661, -2002,
    1923, -2002, 12955, 12955, -2002,  1924,   848, -2002,  1664,  7649,
   -2002, 16182, 16211, -2002,  1926, 14584, 14584,   849,  1927,  1929,
   -2002, -2002,   850, -2002,  1930, -2002, -2002,  1931, 14584, -2002,
   -2002, -2002
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2002, -2002, -2002, -2002,   490, -2002, -2002, -2002, -2002,  -296,
   -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002, -2002,
   -2002, -2002,  -775,   -79,  2274,  4064,  -458, -2002,  1444, -2002,
   -2002, -2002, -2002, -2002, -2002, -2001, -2002,   430,   241,   -91,
   -2002,   -50, -2002,   179,   473, -2002,  1945, -2002,   762,   -44,
    1369, -2002,    26,  -656,   -42, -2002, -2002, -2002, -2002, -2002,
   -2002, -2002,   835,  1947, -2002, -2002, -2002, -2002, -1312, -1309,
    1949, -1823,  1951, -2002, -2002, -2002,  1315, -2002,  -109, -2002,
   -2002, -2002, -2002,  2947, -2002, -2002, -1517,   335,  1952, -2002,
     -13, -2002, -2002,   -57, -2002, -1792,  1201, -2002,   -22,  3308,
     977,  -329,   108, -2002,   -78,   -74, -2002, -2002,   127,   308,
   -1795,  -163,  1142, -2002,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -600
static const yytype_int16 yytable[] =
{
     150,   489,   655,  1751,  1575,  1577,  1958,   439,   786,  1002,
    1003,  1110,   175,   339,   341,   174,   344,  1116,   441,   354,
     325,  1999,   176,  2000,  1570,   578,   360,   391,  1020,   131,
    1705,   174,  2129,   386,   174,   691,   388,   605,  1992,   434,
    1833,   438,  1360,  1131,   189,   158,     5,  1572,   450,   165,
     986,  1714,   365,   308,   366,  1423,   345,   371,   582,   167,
     372,   313,  1186,  2268,   313,  1908,   193,   177,   395,   178,
     330,   468,   472,   373,   812,   384,   473,   482,   485,   486,
     663,   664,   813,   364,  1909,   153,  1405,   314,  1460,   308,
    1125,   814,  1676,   583,   308,   818,   155,  1562,   331,   394,
    1306,  2036,   825,   819,  1715,   500,     4,   174,   663,   664,
     435,   502,   797,   174,   332,   333,  1462,   361,   177,  1307,
     178,  2047,   499,   518,  1250,   820,   493,  1251,   627,   997,
    1308,  1309,  1310,   821,  1247,   627,  1311,  1312,  1463,  1248,
     533,   663,   664,  1385,  1306,   729,  1386,   474,  2249,  1464,
    1465,   367,   484,   484,   484,   346,  1873,  2251,  1823,   347,
    -596,   491,  1004,  1307,   212,   348,   349,   213,   350,   351,
     214,   560,   968,   561,  1308,  1309,  1310,   476,   151,   607,
    1311,  1312,   152,   215,   523,   663,   664,   387,   663,   664,
     389,   352,   462,   463,   531,  2240,   326,   154,   484,   327,
    1109,  1531,  1571,   308,   831,  1405,  1008,   308,   308,  1558,
     832,   663,   664,   308,   308,   484,   987,   573,   574,   575,
     663,   664,  1574,   663,   664,  1573,   448,   663,   664,   362,
     449,  1852,  1576,   160,   823,  1922,   587,  1424,  1425,  1426,
    1427,  1955,   824,  1114,  2081,   123,   156,  1834,  2082,   103,
    1229,   104,   105,   106,   107,   108,   123,   123,   824,   112,
     113,   123,   115,   177,   123,   178,  1795,   157,  1575,   440,
    1405,  2149,  1251,   308,  1060,   663,   664,   658,   659,   161,
     442,  1076,   602,  1132,  1133,   667,   672,   579,   308,   363,
     392,   308,   603,   640,   641,   642,   692,  1412,   693,   606,
     162,   671,   152,   190,  1361,   451,   159,   308,   308,   452,
     166,   308,   308,   308,   308,   458,   459,   460,   461,  1428,
     168,   696,   308,  1187,  2269,   194,   308,   396,   394,  2189,
    1406,  1409,  1132,  1133,   686,   687,   688,   123,   163,   462,
     463,  1448,  1122,   123,   177,   815,   178,   816,  1408,   867,
     308,   817,   703,   308,   308,   308,   826,   674,   816,  1139,
     164,   675,   827,   462,   463,   169,   798,   766,   799,  1150,
    -592,   308,   800,   789,   308,   790,   177,   834,   178,   462,
     463,   773,   628,   832,   629,  1219,   462,   463,   630,   628,
     172,   629,   475,   663,   664,   630,   462,   463,   760,   730,
     763,   731,   663,   664,   356,   732,   357,   769,   913,   173,
    2264,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   458,
     459,   460,   461,   626,   458,   459,   460,   461,   789,  1951,
     790,   170,   484,   689,   308,   778,  1244,   690,   308,   308,
     663,   664,   319,   462,   463,   320,   321,   322,   462,   463,
     458,   459,   460,   461,   308,   171,   665,   779,   323,   462,
     463,   801,   458,   459,   460,  1115,  -594,  2291,   780,   781,
    1453,  1256,   663,   664,   462,   463,   778,   907,   867,   909,
     778,   911,   912,   663,   664,   718,   839,   152,  1306,   458,
     459,   460,   461,  2083,   663,   664,   205,   789,   779,   790,
     930,   931,   779,  1454,  2084,   824,   206,  1307,   934,   780,
     781,   867,   308,   780,   781,  2085,   207,  2327,  1308,  1309,
    1310,  1493,   624,   625,  1311,  1312,  2144,   324,   626,    69,
      70,    71,    72,  2117,   186,    75,    76,   210,   308,   663,
     664,  2118,   866,   782,   783,    85,   867,   308,   903,    89,
     462,   463,   484,   927,   484,   308,   484,   484,   491,   789,
    2086,   790,  1306,  1064,   920,   663,   664,  1363,   933,   187,
     935,   308,   308,   308,   208,   484,   484,   308,   176,   868,
     176,  1307,   308,   867,   782,   783,  2225,   938,   782,   783,
    1555,   867,  1308,  1309,  1310,  1978,  1000,  1001,  1311,  1312,
    1874,   659,   993,   188,   995,   996,   462,   463,   308,  1438,
    2278,  1359,   779,  -595,   965,   663,   664,   663,   664,   663,
     664,  1009,   779,   780,   781,   663,   664,   784,   785,  2150,
    2151,   666,   191,   780,   781,  2152,   308,   308,  2226,  1411,
    2227,  1030,  1825,  1826,   663,   664,  2228,  1063,   192,  1065,
    1066,  1067,  1068,  1069,  1070,   195,  1072,  1073,  1074,  1075,
     673,  1587,  1080,  1081,  1082,  1079,   196,   972,  1052,   663,
     664,   867,  1640,  1641,  1306,   663,   664,  2154,  2155,   663,
     664,   476,   476,  2152,  2314,   973,   308,   308,   308,   867,
    2229,   663,   664,  1307,   308,   684,  2275,  1111,   782,   783,
     476,   197,   335,   336,  1308,  1309,  1310,   198,   782,   783,
    1311,  1312,  2276,  1091,   337,  1019,  1059,   199,   338,   867,
     200,   491,   484,   491,   484,   484,   484,   484,   484,   484,
    1083,   484,   484,   484,   484,  1078,  1146,   484,   484,   484,
     176,  1084,   663,   664,   308,   663,   664,  1156,   663,   664,
     201,   315,  1127,   202,   316,   130,   317,   607,  1162,   335,
     336,  1770,   308,  2285,   180,   203,  2312,   181,   209,  2313,
     182,   337,   183,  1093,   789,   343,   790,   867,   308,   184,
    1519,   204,  1520,    46,  1119,   789,   319,   790,   789,   320,
     790,   322,  1755,  1383,  1756,  1529,   867,   663,   664,  1099,
     308,  1136,   323,  1100,   462,   463,   308,  1266,   308,  1267,
    1254,   491,  1148,  1290,   867,   318,  1609,   867,   462,   463,
    1154,  1358,   484,  1359,  1822,  1556,  1823,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,   217,  1291,  1338,   211,   626,
     867,   867,   308,   218,   308,  1979,   309,  1853,   619,   620,
     728,   622,   623,   624,   625,   310,  1936,  1860,  1937,   626,
     443,   728,   622,   623,   624,   625,   328,  1339,  1340,  1268,
     626,   867,   867,  1343,  1389,   312,   311,   867,   867,  1611,
    1418,   308,  1612,  1613,   867,  1500,   329,  1284,   334,   867,
    2255,   308,   470,   355,   342,   358,  1507,   470,   470,   470,
     867,  1528,   359,   368,  1536,   867,   470,  1623,   867,  1554,
    1674,  1727,  1763,   867,   867,   867,   867,  1764,   308,   353,
    1298,   867,   369,   370,  1857,  1880,  1575,  1304,  1858,   867,
    1642,  1315,  1295,  1882,   308,   727,  1967,   867,   381,   382,
     867,  2019,   380,   470,   383,  2020,   308,  2037,  2297,  2064,
    2065,  2038,  2080,   867,   867,   308,  2020,  1662,  2088,  2114,
     470,  1268,   867,   824,   385,  2123,  2140,   308,  1575,  2124,
    2020,  1678,  2145,  2146,   390,   397,   867,   867,  1684,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   865,   622,   623,   624,   625,   398,   404,   436,
    2178,   626,   572,   789,   867,   790,  1407,  1410,  2199,  2200,
     405,   446,   867,   867,  2208,  1415,   445,   447,  2020,   453,
     585,   586,  2216,  1268,  2224,  2231,   867,  2238,   867,   867,
    2274,  2020,   454,  2281,   867,   479,  1447,   867,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,   789,  2282,   790,   791,
     626,   867,  1610,  1646,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,   308,  2283,  2284,
    2286,   626,   867,   867,   867,  1414,  1472,   480,  2288,   152,
    2308,  2315,  2124,   308,  2020,   867,  2324,  2334,  2337,   497,
    2325,  2020,  2338,   499,   501,   506,   308,  1947,  1948,   510,
     524,   484,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,   530,  1505,
    1506,   789,   626,   790,   969,   568,   571,  -208,  -209,   581,
    -210,   308,   308,   580,   308,   308,   308,   584,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   588,   591,
     308,   592,   593,   604,   636,  1530,  1532,   528,   529,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,   470,   449,   637,
     644,   626,   645,   476,   646,   649,   652,   654,   774,   656,
     657,   694,   695,   308,   484,   484,   676,   677,   678,   679,
     680,   681,   682,   697,   698,   721,   706,   699,   700,   701,
     809,   702,   707,   708,   709,   711,   710,   712,   713,   715,
     720,   737,   308,   738,   739,   809,   750,   306,   751,   753,
     755,   756,   754,   758,   759,   757,   761,   762,   308,   308,
     308,   764,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,   634,   635,   772,
    1615,   626,   775,   788,  1617,   793,   796,   795,   151,   840,
     836,   858,   802,  1621,   863,  1622,   870,   842,  1624,   871,
     872,   904,   914,   941,   915,   916,  1856,   626,   917,   924,
     926,   929,   942,   977,   978,   939,   308,   470,   981,   470,
     683,   470,   470,   470,   991,   992,   994,  1022,  1024,  1039,
    1025,  1028,  1037,  1050,  1053,   308,  1086,   308,   308,  1088,
     470,   470,  1092,   476,  1098,  1102,  1103,  1530,  1532,  1664,
     308,  1107,  1108,  1112,  1123,   484,  1124,  1129,  1140,   484,
    1142,  1145,  1153,  1155,  1158,  1163,  1159,  1164,   484,  1165,
     484,  1167,  1168,   484,  1169,  1171,  1690,  1172,  1695,  1173,
    1174,  1175,  2002,  1176,  1177,  1178,   308,  1179,  1180,  1183,
    1189,  1217,  1218,  1226,  1249,  1227,  1228,  1236,  1240,   394,
    1243,  1255,  1259,  2158,  1263,  1271,  1272,  1273,   532,  1279,
    1281,  1293,  1301,  1302,   767,  1305,  1327,  1329,  1328,  1331,
    1352,  1348,  1350,   809,   484,  1351,  1357,  1366,  1367,   308,
    1368,   308,  1371,  1379,  1381,  1382,  1388,  1392,  1393,  1394,
    1395,  1398,  1399,  1400,  1404,  1417,  1419,  1420,   809,   308,
    1435,  1441,  1442,  1443,  1444,  1449,  1452,  1457,  1456,  1475,
    1479,  1491,   308,   794,  -211,  1523,   308,   306,  1511,  1540,
    1541,  1542,  1545,  1546,  1548,  1547,  1549,  1550,  1552,  1553,
    1865,  1865,  1563,  1564,  1568,  1569,   470,   470,   470,   470,
     470,   470,   470,   470,   470,  1567,   470,   470,   470,   470,
    1578,  1579,   470,   470,   470,   639,  1580,  1581,  1582,  1794,
    1583,  1584,   809,  1585,  1586,   809,   648,  1592,  1590,  2008,
     653,   809,  1591,  1593,  1594,  1595,  1596,   308,   308,   308,
    1597,  1598,  1599,  1606,  1601,   308,   308,   308,  1603,  1619,
    1618,  1627,  1841,  1625,  1636,  1626,  1639,  1644,  1628,  1630,
    1634,  1645,  1648,  1854,   308,  1650,  1649,  1126,  1655,  1128,
     174,   406,   936,  1657,  1658,   308,  1659,  1661,  1675,  1681,
    1673,  1682,  1679,   308,  1686,  1700,   470,   308,  1844,  1702,
    1701,  1704,  1846,  1706,  1710,  1711,  1712,   470,   308,  1885,
     308,  1717,  1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,
    1726,  1728,  1739,  1744,  1894,  1746,   407,   408,   409,   410,
     411,   412,   413,   414,   415,  1749,   988,   989,   811,   416,
     417,   418,   419,  1753,  1762,  1768,  1769,   420,   421,   422,
     423,  1777,   394,  1775,  1778,  1791,   424,  1779,   425,  1902,
     491,   491,   770,   771,  1786,  1792,   308,  1807,  1815,  1776,
    1783,  1817,   426,  1784,  1785,   427,  1798,  1799,   787,  1800,
    1801,  1824,  1802,  1818,   484,  1838,  1033,  1034,  1035,  1926,
    1803,  1828,  1831,  1848,  1041,   308,  1806,  1851,  1809,  1810,
     308,  1386,  1875,  1877,  1843,  1867,  1883,  1884,  2011,  1887,
    1850,  1879,  1847,  1872,  1886,  1942,  1890,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,  1895,  1901,  1903,  1904,   626,
    1905,  1910,  1906,  1911,  1085,  1912,  1913,  1914,  1918,  1921,
    1251,  1919,  1959,  1960,  1961,  1962,  1963,  1965,  1929,  1931,
    1986,  1927,  1985,  1988,  1934,   809,  1935,   809,   809,  1990,
    1993,  1928,  1342,  1952,  1956,  1957,  1966,   308,  1113,   910,
    1972,   809,   308,   308,  1973,  1974,  1994,  2006,  2004,  2183,
    1996,   428,   429,   430,  1995,   639,  2007,   928,  2012,  -599,
    1135,   824,   809,   431,  2024,   308,  1141,   432,  1143,   433,
     123,   308,  2025,  2026,  2027,  -597,   308,  2031,  2041,   476,
     476,  2035,  2040,  2042,   809,   308,  2043,  2046,  2077,  2044,
    2045,  2054,  2052,  2059,  2060,   484,  2068,  2063,   484,  2071,
    2069,  2075,  2072,  2087,  2078,  2090,  2097,  2098,  2099,  2108,
    2109,  2110,  2113,  2115,   308,  2105,  2116,  2106,  1414,  2107,
    2139,  2112,  2161,   809,  2121,   394,  2166,   308,   491,  2162,
    2173,  2180,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
    2179,  1220,  2181,  2182,   626,  2184,  2190,  -598,  2193,  2194,
    2202,  1230,  2198,   491,  2195,  2212,   470,  2206,  2215,  2219,
    2220,  2232,  2207,  2209,  2213,  2234,  2247,  2252,  2242,  2223,
     308,  2217,  2235,  2257,  2271,  2287,  2298,  2299,  2300,  2301,
    2303,  2304,  2103,  2305,   308,   308,  2306,  2309,  2319,  2320,
    2323,  2326,  2330,  2335,  1262,  2336,  2339,  2340,  1677,  2265,
     835,  1742,  1900,  2130,  2102,  1930,  1270,  1708,   129,   308,
     140,   925,   141,  1434,   142,   148,  2156,   980,  1840,  2003,
    1991,   308,  1866,     0,     0,  2134,  1147,  1292,     0,     0,
       0,     0,     0,     0,     0,     0,  1104,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
     470,     0,     0,     0,     0,  1490,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,   308,   626,     0,
       0,     0,     0,     0,     0,  2168,  2169,  2170,  2171,  2172,
       0,     0,   308,     0,     0,     0,  2164,  2135,     0,     0,
     308,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   809,     0,     0,
     308,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,     0,     0,     0,   308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,     0,     0,     0,  2210,   476,     0,     0,  2214,     0,
       0,     0,     0,     0,     0,   394,  1446,     0,     0,     0,
       0,  1551,     0,     0,     0,     0,     0,     0,   308,     0,
       0,     0,     0,  2241,     0,     0,     0,     0,     0,     0,
     470,     0,     0,     0,   470,     0,     0,     0,     0,  2233,
       0,     0,  1258,   470,     0,   470,     0,     0,   470,   308,
       0,     0,  2248,     0,     0,  1629,  2250,     0,     0,     0,
    1492,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2262,     0,     0,     0,     0,     0,     0,  1278,
       0,  2256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
       0,     0,     0,     0,   308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2295,  2296,
       0,     0,   308,   308,   308,   308,   308,     0,  2317,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,  2331,  2333,  1538,
    1539,   626,     0,     0,     0,     0,     0,     0,     0,     0,
    2341,     0,     0,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,  1401,   185,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,  1421,     0,     0,
       0,     0,   484,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,     0,
    1614,     0,   174,   406,     0,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,  1473,  1474,   626,  1476,  1477,
    1478,     0,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,
    1488,  1489,     0,     0,     0,     0,     0,     0,   407,   408,
     409,   410,   411,   412,   413,   414,   415,  1589,     0,     0,
       0,   416,   417,   418,   419,     0,     0,     0,     0,   420,
     421,   422,   423,     0,     0,   470,   470,     0,   424,  1670,
     425,  1672,     0,     0,   469,     0,     0,  1504,     0,     0,
       0,     0,     0,     0,   426,     0,     0,   427,     0,   470,
       0,   180,     0,     0,   181,     0,     0,   182,     0,   183,
       0,     0,     0,     0,     0,     0,  1524,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1537,     0,     0,     0,     0,     0,     0,     0,
     456,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   562,   563,   564,   565,   566,   567,
    1588,   569,   570,     0,     0,     0,     0,     0,     0,     0,
       0,   576,   577,     0,     0,     0,     0,     0,     0,  1602,
       0,  1604,  1605,   428,   429,   430,   589,   590,     0,     0,
       0,     0,     0,     0,     0,   431,     0,  1808,     0,   432,
       0,   433,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,     0,     0,   470,     0,     0,     0,     0,   462,   463,
    1635,     0,     0,     0,     0,  -593,   809,  1663,   809,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   470,     0,     0,     0,     0,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,   470,     0,
       0,     0,     0,  1694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   725,     0,  1709,     0,     0,     0,
    1713,   734,   735,   736,     0,     0,     0,   740,   741,   742,
     743,   744,   745,   746,     0,   747,     0,     0,     0,     0,
     748,   749,   219,   174,   752,   399,     0,     0,     0,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   400,   242,   243,   244,   245,   246,   247,   248,
     249,  1765,  1766,  1767,     0,     0,     0,     0,     0,  1772,
    1773,  1774,  1938,  1939,     0,     0,     0,     0,   255,   256,
     257,   258,   174,   406,     0,     0,   259,     0,  1789,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1797,
       0,     0,   264,   265,   266,     0,  1968,  1805,     0,     0,
       0,     0,     0,   267,    25,     0,   268,     0,     0,     0,
       0,     0,  1814,     0,  1816,     0,     0,     0,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,   417,   418,   419,     0,     0,     0,     0,   420,
     421,   422,   423,     0,     0,     0,     0,     0,   424,     0,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,     0,     0,   427,     0,     0,
    1871,   180,     0,     0,   181,     0,     0,   182,     0,   183,
       0,     0,     0,     0,     0,     0,     0,   940,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,  1893,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     456,     0,     0,     0,  2057,  2058,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,     0,   282,     0,     0,
       0,     0,     0,   284,   285,   286,   809,   287,   288,   289,
    1633,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   401,     0,     0,     0,     0,     0,   292,     0,  2095,
       0,     0,   376,     0,     0,     0,     0,     0,     0,   295,
       0,  1933,     0,   428,   429,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,     0,   432,
       0,   433,   123,     0,     0,   809,     0,     0,     0,  1871,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   809,  1975,
    2136,  2137,   789,     0,   790,  1861,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2157,     0,     0,     0,     0,  2001,     0,
       0,     0,     0,     0,     0,     0,   402,     0,  2167,     0,
       0,  2010,     0,     0,     0,     0,     0,     0,   470,   444,
    2177,  2039,   607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,   470,     0,
       0,     0,     0,     0,     0,     0,     0,   471,     0,     0,
     470,   481,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,     0,   492,  1871,     0,   494,     0,     0,     0,
    1651,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,   504,   505,     0,   507,   508,   509,
       0,   511,   512,   513,   514,   515,   516,   517,     0,   519,
     520,   521,   522,  2076,     0,     0,     0,   526,   526,     0,
       0,     0,     0,     0,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,  2246,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
       0,     0,  2258,  2259,  2260,  2261,  2263,     0,     0,  1252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2131,   594,   596,   598,
     599,   526,  1269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   633,   526,   526,     0,
       0,     0,  2302,     0,  1871,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   651,     0,     0,     0,  2163,     0,
       0,     0,     0,     0,   661,   662,     0,     0,     0,     0,
     662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,     0,   685,     0,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   865,   622,   623,
     624,   625,  1871,   704,   526,     0,   626,     0,     0,     0,
       0,     0,     0,     0,   714,     0,   716,   717,     0,   719,
       0,     0,     0,   722,   723,   724,     0,     0,   726,     0,
       0,     0,   733,  2211,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,   768,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,   777,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   810,     0,  1461,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,   841,     0,
       0,   626,     0,   846,     0,     0,     0,   850,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1871,   864,   596,     0,     0,     0,     0,   869,     0,     0,
       0,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   892,
     893,   894,   895,   896,   897,   898,   899,   900,   900,     0,
     905,   906,     0,   908,     0,     0,     0,     0,   527,   527,
    1871,     0,     0,   918,     0,     0,   922,   923,     0,     0,
    1525,     0,     0,     0,     0,     0,     0,   900,     0,     0,
       0,     0,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   952,   953,   954,   955,   956,   958,   960,
     961,   962,   963,   964,     0,   966,   967,     0,     0,     0,
       0,  1845,     0,   974,   975,   976,     0,     0,     0,     0,
       0,   982,   983,   984,   985,     0,   526,   526,     0,   597,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   726,  1005,   527,   527,
       0,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
       0,     0,     0,     0,     0,     0,  1026,  1027,     0,  1029,
       0,     0,  1031,  1849,     0,     0,   526,   526,   526,  1036,
       0,     0,     0,  1040,   526,  1042,  1043,  1044,     0,     0,
    1045,   527,  1047,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1057,     0,     0,  1058,     0,   966,   967,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
    1071,     0,     0,  1653,  1654,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,     0,     0,     0,     0,     0,
       0,  1090,     0,     0,     0,     0,     0,     0,     0,  1101,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,   526,  1855,
    1117,     0,   626,     0,  1038,  1120,  1121,     0,     0,     0,
       0,     0,   998,     0,     0,   527,     0,     0,     0,     0,
     526,     0,  1137,  1138,     0,     0,   526,     0,   526,  1144,
       0,     0,     0,  1137,     0,  1151,     0,  1152,     0,     0,
       0,     0,     0,  1157,     0,     0,     0,  1160,     0,     0,
    1970,     0,     0,     0,  1750,     0,     0,     0,     0,     0,
       0,     0,     0,  1757,     0,     0,     0,     0,     0,     0,
    1181,     0,   958,     0,  1184,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,   597,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,  1971,     0,     0,     0,     0,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,   891,
       0,   526,  1231,  1232,  1233,     0,     0,     0,   901,   902,
       0,  1239,     0,  1241,     0,     0,  1242,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,  2067,   932,   626,
       0,     0,     0,   527,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,  1277,     0,     0,     0,  1283,   959,
       0,     0,     0,     0,  1289,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,  1299,  1300,     0,     0,     0,
       0,  1303,     0,     0,     0,     0,     0,   527,   527,     0,
       0,     0,     0,     0,     0,     0,  1896,     0,     0,  1330,
       0,     0,  1332,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,  2096,     0,     0,     0,   626,     0,     0,  1353,     0,
    1355,  1356,     0,     0,     0,     0,     0,   527,   527,   527,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,  1377,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,  1397,     0,     0,   626,     0,     0,     0,
    1403,     0,     0,     0,     0,     0,     0,  1416,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
    1439,  1440,     0,     0,     0,     0,   526,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,   527,
     626,     0,     0,     0,     0,     0,     0,     0,  1470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,  2111,     0,     0,     0,   527,     0,   527,
     526,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,  1494,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1495,
    1496,  1497,  1498,  1499,     0,     0,     0,     0,  1501,  1502,
       0,  1503,     0,   959,     0,  1185,     0,     0,     0,  2147,
       0,     0,     0,     0,     0,     0,     0,  1514,     0,     0,
    1517,  1518,     0,     0,     0,     0,     0,     0,  1521,  1522,
       0,     0,     0,     0,  2148,     0,     0,  1526,  1527,     0,
       0,     0,   527,  1533,  1534,     0,     0,     0,     0,   526,
     526,     0,   527,     0,     0,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,  1566,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,  1533,  1534,     0,     0,     0,
     526,     0,     0,     0,     0,     0,     0,     0,  1616,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,  1632,   789,     0,   790,     0,     0,     0,     0,
       0,  1829,     0,  1638,     0,     0,  1643,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,  1543,     0,     0,   626,
       0,     0,     0,     0,     0,  1665,     0,     0,  1668,   526,
    1671,   526,     0,     0,     0,     0,     0,     0,     0,  1680,
       0,     0,  1683,     0,  1680,     0,  1687,  1689,     0,     0,
    1697,  1698,  1699,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,   527,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,   527,   626,     0,  1771,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1780,  1781,  1782,     0,     0,
       0,     0,     0,     0,  1788,     0,  1790,     0,     0,     0,
       0,     0,     0,  1793,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   792,     0,     0,     0,   526,     0,     0,
       0,     0,     0,  1811,  1812,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1819,  1820,  1821,     0,     0,     0,
       0,     0,     0,     0,     0,  1832,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1842,     0,     0,     0,     0,
     527,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1859,     0,     0,     0,
     219,   174,     0,     0,  1868,  1869,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     400,   242,   243,   244,   245,   246,   247,   248,   249,     0,
    1898,   919,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,  1915,  1916,  1917,     0,     0,     0,     0,
       0,   267,    25,     0,   268,     0,   970,  1920,     0,     0,
       0,     0,  1923,  1924,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1932,     0,     0,     0,     0,
       0,     0,   526,   526,  1940,     0,  1941,     0,     0,     0,
       0,     0,  1949,  1950,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,   526,   527,     0,     0,     0,   526,  1969,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1923,
    1924,     0,     0,  1983,     0,     0,  1987,     0,     0,     0,
    1989,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1998,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2005,     0,     0,     0,     0,     0,     0,  2230,     0,     0,
       0,   281,     0,     0,  2016,   282,     0,     0,     0,  2022,
    2023,   284,   285,   286,     0,   287,   288,   289,     0,     0,
       0,   123,     0,  2028,     0,     0,  2029,  2028,     0,  2032,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   401,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     376,     0,     0,     0,   650,  2051,     0,   295,     0,     0,
       0,     0,     0,     0,   526,   526,     0,     0,     0,     0,
       0,  2061,  2062,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2070,     0,     0,     0,     0,   527,     0,
       0,     0,  2079,     0,     0,     0,     0,     0,     0,     0,
       0,   596,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2091,  2092,     0,     0,   726,   526,
       0,     0,     0,     0,     0,     0,     0,  1190,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,     0,
    1203,  1204,  1205,  1206,  2277,  1208,  1209,  1210,  1211,     0,
       0,     0,     0,     0,  2119,  2120,     0,     0,     0,     0,
       0,  1223,     0,  1225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1235,  2133,     0,     0,     0,     0,
     526,   526,  2138,     0,     0,  1245,  1246,  2141,     0,  2143,
       0,  1899,     0,     0,  1257,     0,  2197,     0,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,     0,     0,     0,     0,     0,     0,  2174,     0,     0,
     526,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2186,     0,     0,     0,     0,
       0,  2191,     0,     0,  2192,     0,     0,     0,     0,     0,
       0,     0,     0,   527,   527,     0,     0,     0,     0,  2204,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2218,     0,     0,
       0,     0,   527,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,  1362,  1364,  1365,     0,
       0,     0,  1369,  1370,  2236,  2237,  1373,  1374,  1375,  1376,
       0,  1378,     0,     0,     0,     0,  1384,     0,     0,  2243,
    2244,     0,     0,     0,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2254,     0,     0,
       0,     0,   526,   526,   526,   526,   526,     0,     0,     0,
       0,     0,  2022,     0,     0,     0,  2270,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,  2290,     7,     8,     0,     0,  2293,
    2294,     0,     0,     0,  1469,     0,  1471,     0,     0,     0,
       0,     0,   526,     0,     0,   527,   527,     0,     0,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,  2321,
    2322,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,     0,    48,     0,
       0,     0,     0,  1535,     0,     0,     0,   803,    57,     0,
       0,    60,   804,     0,   805,   806,     0,   807,     0,     0,
       0,   527,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,    99,   100,   101,     0,     0,     0,     0,
       0,   527,     0,     0,   219,   174,   406,     0,   455,     0,
       0,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   400,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     255,   256,   257,   258,   416,   417,   418,   419,   259,     0,
     829,     0,   420,   421,   422,   423,     0,     0,     0,     0,
       0,   424,  1652,   425,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,   426,   268,     0,
     427,     0,     0,     0,   180,     0,     0,   181,     0,     0,
     182,     0,   183,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,    46,     0,  1691,     0,     0,     0,     0,
       0,     0,     0,   527,   527,   527,   527,   527,     0,     0,
       0,     0,     0,   456,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1729,  1730,
    1731,  1732,  1733,  1734,  1735,     0,     0,     0,     0,  1740,
    1741,     0,     0,     0,     0,     0,  1743,     0,     0,     0,
       0,     0,  1748,     0,     0,     0,  1752,     0,     0,  1754,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
    1761,     0,     0,     0,     0,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,   281,   428,   429,   430,   282,
       0,     0,     0,     0,     0,   284,   285,   286,   431,   287,
     288,   289,   432,     0,   433,   123,     0,   458,   459,   460,
     461,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   401,     0,     0,     0,     0,     0,   292,
     607,   462,   463,     0,   464,     0,   465,     0,     0,     0,
     466,   295,     0,     0,     0,     0,     0,     0,  1827,     0,
    1830,     0,     0,     0,  1837,     0,  1839,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1891,     0,  1862,     0,  1892,
       0,     0,   219,     6,   406,     0,     0,     0,     0,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   607,     0,     0,  1692,
     408,   409,   410,   411,   412,   413,   414,   415,   255,   256,
     257,   258,   416,   417,   418,   419,   259,   260,     0,  1054,
     420,   421,   422,   423,     0,     0,   261,   262,   263,   424,
       0,   425,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    25,   426,   268,     0,   427,     0,
       0,  1925,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   273,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,    58,    59,     0,   277,
       0,   278,     0,     0,   279,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,     0,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
       0,     0,     0,     0,   626,   280,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2013,     0,     0,
    2014,     0,     0,   281,   428,   429,   430,   282,   283,     0,
       0,     0,     0,   284,   285,   286,   431,   287,   288,   289,
     432,     0,   433,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   291,     0,     0,     0,     0,     0,   292,     0,  2048,
    2049,     0,   376,     0,  2053,     0,  1693,     0,     0,   295,
       0,  1260,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   865,   622,   623,   624,   625,     0,     0,     0,     0,
     626,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,  2100,  2101,     0,   219,     6,   406,     0,     0,     0,
       0,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,     0,
    2132,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     255,   256,   257,   258,   416,   417,   418,   419,   259,   260,
       0,     0,   420,   421,   422,   423,     0,     0,   261,   262,
     263,   424,     0,   425,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,   426,   268,     0,
     427,     0,     0,     0,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   273,   274,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,    58,    59,
       0,   277,     0,   278,     0,     0,   279,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   428,   429,   430,   282,
     283,     0,     0,     0,     0,   284,   285,   286,   431,   287,
     288,   289,   432,     0,   433,   123,     0,  1261,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   291,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,   376,     0,     0,     0,   294,     0,
       0,   295,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,   219,     6,   375,
     862,     0,     0,     0,   220,   221,   222,     0,  2311,   223,
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
       0,     0,    42,     0,     0,     0,   273,   274,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    58,    59,     0,   277,     0,   278,     0,     0,   279,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,     0,     0,     0,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
     280,   626,     0,     0,     0,  1608,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,   282,   283,     0,     0,     0,     0,   284,   285,
     286,     0,   287,   288,   289,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   376,   219,     6,
       0,   377,     0,   705,   295,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   262,   263,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   267,
      25,     0,   268,     0,     0,     0,     0,     0,   269,     0,
       0,   270,     0,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   273,   274,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,    58,    59,     0,   277,     0,   278,     0,     0,
     279,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,   280,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
       0,     0,     0,   282,   283,     0,     0,     0,     0,   284,
     285,   286,     0,   287,   288,   289,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   525,     0,     0,
       0,     0,     0,   292,     0,     0,     0,     0,   376,   219,
       6,  1796,     0,   600,     0,   295,   220,   221,   222,     0,
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
       0,     0,   275,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,    58,    59,     0,   277,     0,   278,     0,
       0,   279,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    85,     0,     0,     0,    89,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,   280,     0,     0,     0,  1945,     0,     0,     0,
    1946,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,     0,     0,   282,   283,     0,     0,     0,     0,
     284,   285,   286,     0,   287,   288,   289,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,   376,
     219,     6,     0,   294,     0,     0,   295,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,   260,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   262,   263,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    25,     0,   268,     0,     0,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   273,
     274,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,    58,    59,     0,   277,     0,   278,
       0,     0,   279,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   280,     0,     0,     0,  1976,     0,     0,
       0,  1977,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   282,   283,     0,     0,     0,
       0,   284,   285,   286,     0,   287,   288,   289,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   668,  1964,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     670,   219,     6,     0,   338,   600,     0,   295,   220,   221,
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
     273,   274,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,    58,    59,     0,   277,     0,
     278,     0,     0,   279,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    85,     0,     0,     0,    89,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,   280,     0,     0,     0,  2159,     0,
       0,     0,  2160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,   282,   283,     0,     0,
       0,     0,   284,   285,   286,     0,   287,   288,   289,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,   293,   219,     6,     0,   294,     0,     0,   295,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,   260,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,   263,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    25,     0,   268,     0,     0,     0,
       0,     0,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   273,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,    58,    59,     0,   277,
       0,   278,     0,     0,   279,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   280,     0,     0,     0,     0,
       0,     0,     0,   822,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,     0,   282,   283,     0,
       0,     0,     0,   284,   285,   286,     0,   287,   288,   289,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   291,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,   376,   219,     6,     0,   294,     0,     0,   295,
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
       0,     0,   273,   274,     0,     0,   275,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,    58,    59,     0,
     277,     0,   278,     0,     0,   279,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,   280,     0,     0,     0,
       0,     0,     0,     0,   828,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,     0,     0,   282,   283,
       0,     0,     0,     0,   284,   285,   286,     0,   287,   288,
     289,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   525,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,   376,   219,     6,     0,   595,     0,     0,
     295,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,     0,     0,   259,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   261,   262,
     263,     0,     0,     0,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,     0,   268,     0,
       0,     0,     0,     0,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   273,   274,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,    58,    59,
       0,   277,     0,   278,     0,     0,   279,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,   280,     0,     0,
       0,     0,     0,     0,     0,   830,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,   282,
     283,     0,     0,     0,     0,   284,   285,   286,     0,   287,
     288,   289,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   525,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,   376,   219,     6,     0,     0,   600,
       0,   295,   220,   221,   222,     0,     0,   223,   224,   225,
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
      42,     0,     0,     0,   273,   274,     0,     0,   275,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,    58,
      59,     0,   277,     0,   278,     0,     0,   279,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    85,
       0,     0,     0,    89,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   280,     0,
       0,     0,     0,     0,     0,     0,   998,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,     0,     0,
     282,   283,     0,     0,     0,     0,   284,   285,   286,     0,
     287,   288,   289,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,   291,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,   638,   219,     6,     0,   294,
       0,     0,   295,   220,   221,   222,     0,     0,   223,   224,
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
       0,    42,     0,     0,     0,   273,   274,     0,     0,   275,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
      58,    59,     0,   277,     0,   278,     0,     0,   279,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      85,     0,     0,     0,    89,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,   280,
       0,     0,     0,     0,     0,     0,     0,   999,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
       0,   282,   283,     0,     0,     0,     0,   284,   285,   286,
       0,   287,   288,   289,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,   291,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,   647,   219,     6,     0,
     294,     0,     0,   295,   220,   221,   222,     0,     0,   223,
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
       0,     0,    42,     0,     0,     0,   273,   274,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    58,    59,     0,   277,     0,   278,     0,     0,   279,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     280,     0,     0,     0,     0,     0,     0,     0,  1051,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,   282,   283,     0,     0,     0,     0,   284,   285,
     286,     0,   287,   288,   289,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   525,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   376,   219,     6,
       0,   957,     0,  1445,   295,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   262,   263,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   267,
      25,     0,   268,     0,     0,     0,     0,     0,   269,     0,
       0,   270,     0,     0,   271,     0,   272,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   273,   274,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,    58,    59,     0,   277,     0,   278,     0,     0,
     279,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    85,     0,     0,     0,    89,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,   280,     0,     0,     0,     0,     0,     0,     0,  1161,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
       0,     0,     0,   282,   283,     0,     0,     0,     0,   284,
     285,   286,     0,   287,   288,   289,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   525,     0,     0,
       0,     0,     0,   292,   219,     6,     0,     0,   376,  1669,
       0,   220,   221,   222,     0,   295,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,     0,     0,   259,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   261,   262,
     263,     0,     0,     0,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,     0,   268,     0,
       0,     0,     0,     0,   269,     0,     0,   270,     0,     0,
     271,     0,   272,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   273,   274,     0,     0,   275,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,    58,    59,
       0,   277,     0,   278,     0,     0,   279,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    85,     0,
       0,     0,    89,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,   280,     0,     0,
       0,     0,     0,     0,     0,  1202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,   282,
     283,     0,     0,     0,     0,   284,   285,   286,     0,   287,
     288,   289,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   525,     0,     0,     0,     0,     0,   292,
     219,     6,     0,     0,   376,     0,     0,   220,   221,   222,
       0,   295,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,   260,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   262,   263,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    25,     0,   268,     0,     0,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   273,
     274,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,    58,    59,     0,   277,     0,   278,
       0,     0,   279,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   280,     0,     0,     0,     0,     0,     0,
       0,  1212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   282,   283,     0,     0,     0,
       0,   284,   285,   286,     0,   287,   288,   289,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   291,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     376,   219,     6,     0,  1804,     0,     0,   295,   220,   221,
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
     273,   274,     0,     0,   275,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,    58,    59,     0,   277,     0,
     278,     0,     0,   279,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,    85,     0,     0,     0,    89,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,   280,     0,     0,     0,     0,     0,
       0,     0,  1213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,   282,   283,     0,     0,
       0,     0,   284,   285,   286,     0,   287,   288,   289,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   668,
    1964,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,   670,   219,     6,     0,   338,     0,     0,   295,   220,
     221,   222,     0,     0,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,     0,     0,     0,     0,   259,   260,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,   263,     0,
       0,     0,   264,   265,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   267,    25,     0,   268,     0,     0,     0,
       0,     0,   269,     0,     0,   270,     0,     0,   271,     0,
     272,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   273,   274,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,    58,    59,     0,   277,
       0,   278,     0,     0,   279,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,     0,    85,     0,     0,     0,
      89,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   280,     0,     0,     0,     0,
       0,     0,     0,  1214,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,     0,   282,   283,     0,
       0,     0,     0,   284,   285,   286,     0,   287,   288,   289,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   525,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,   376,   219,     6,     0,     0,  2094,     0,   295,
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
       0,     0,   273,   274,     0,     0,   275,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,    58,    59,     0,
     277,     0,   278,     0,     0,   279,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    85,     0,     0,
       0,    89,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,   280,     0,     0,     0,
       0,     0,     0,     0,  1215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   281,     0,     0,     0,   282,   283,
       0,     0,     0,     0,   284,   285,   286,     0,   287,   288,
     289,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   525,     0,     0,     0,     0,     0,   292,   219,
     174,   406,     0,   376,     0,     0,   220,   221,   222,     0,
     295,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   400,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   255,   256,   257,   258,   416,
     417,   418,   419,   259,     0,     0,     0,   420,   421,   422,
     423,     0,     0,     0,     0,     0,   424,     0,   425,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,   426,   268,     0,   427,   219,   174,   406,     0,
       0,     0,     0,   220,   221,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   400,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   255,   256,   257,   258,   416,   417,   418,   419,
     259,     0,     0,     0,   420,   421,   422,   423,     0,     0,
       0,     0,     0,   424,     0,   425,   264,   265,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   267,    25,   426,
     268,     0,   427,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,   428,   429,   430,   282,     0,     0,     0,     0,     0,
     284,   285,   286,   431,   287,   288,   289,   432,     0,   433,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   401,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,   376,
       0,     0,     0,  1688,     0,     0,   295,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1216,
       0,     0,     0,     0,     0,     0,     0,   281,   428,   429,
     430,   282,     0,     0,     0,     0,     0,   284,   285,   286,
     431,   287,   288,   289,   432,     0,   433,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,  1981,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,   376,   219,   174,   406,
    1982,     0,     0,   295,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   400,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,  1692,   408,   409,   410,   411,   412,
     413,   414,   415,   255,   256,   257,   258,   416,   417,   418,
     419,   259,     0,     0,     0,   420,   421,   422,   423,     0,
       0,     0,     0,     0,   424,     0,   425,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    25,
     426,   268,     0,   427,   219,   174,   406,     0,     0,     0,
       0,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   400,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     255,   256,   257,   258,   416,   417,   418,   419,   259,     0,
       0,     0,   420,   421,   422,   423,     0,     0,     0,     0,
       0,   424,     0,   425,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,   426,   268,     0,
     427,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,   428,
     429,   430,   282,     0,     0,     0,     0,     0,   284,   285,
     286,   431,   287,   288,   289,   432,     0,   433,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   401,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   376,     0,     0,
       0,  1861,     0,     0,   295,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1221,     0,     0,
       0,     0,     0,     0,     0,   281,   428,   429,   430,   282,
       0,     0,     0,     0,     0,   284,   285,   286,   431,   287,
     288,   289,   432,     0,   433,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   401,     0,     0,     0,     0,     0,   292,
     219,   174,     0,     0,   376,     0,     0,   220,   221,   222,
       0,   295,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     400,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,   219,   174,
       0,   267,    25,   921,   268,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   400,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   264,   265,
     266,    43,    44,    45,    46,     0,     0,     0,    48,   267,
      25,     0,   268,     0,     0,     0,     0,   803,    57,     0,
       0,    60,   804,     0,   805,   806,     0,   807,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   282,    82,     0,     0,     0,
       0,   284,   285,   286,     0,   287,   288,   289,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,     0,   668,   669,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     670,     0,     0,     0,   338,     0,     0,   295,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,   281,
    1222,     0,     0,   282,     0,     0,     0,     0,     0,   284,
     285,   286,     0,   287,   288,   289,     0,     0,     0,   123,
    1006,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   401,     0,     0,
       0,     0,     0,   292,   219,   174,     0,     0,   376,     0,
       0,   220,   221,   222,     0,   295,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   400,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,     0,   268,   219,
     174,     0,  1396,     0,     0,     0,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   400,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,     0,     0,     0,
     267,    25,     0,   268,     0,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,   281,     0,     0,   626,   282,
       0,     0,     0,     0,     0,   284,   285,   286,  1224,   287,
     288,   289,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   401,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,   376,  1149,     0,     0,     0,     0,
       0,   295,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1346,     0,     0,     0,     0,     0,
     281,     0,     0,     0,   282,     0,     0,     0,     0,     0,
     284,   285,   286,     0,   287,   288,   289,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   401,     0,
       0,     0,     0,     0,   292,   219,   174,     0,  1565,   376,
       0,     0,   220,   221,   222,     0,   295,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   400,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,     0,     0,     0,   267,    25,     0,   268,
     219,   174,     0,  1631,     0,     0,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     400,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    25,     0,   268,     0,     0,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,   281,     0,     0,   626,
     282,     0,     0,     0,     0,     0,   284,   285,   286,  1372,
     287,   288,   289,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,   401,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,   376,     0,     0,     0,     0,
       0,     0,   295,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1455,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   282,     0,     0,     0,     0,
       0,   284,   285,   286,     0,   287,   288,   289,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   401,
       0,     0,     0,     0,     0,   292,   219,   174,     0,     0,
     376,     0,     0,   220,   221,   222,     0,   295,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   400,   242,   243,   244,
     245,   246,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,     0,     0,     0,     0,
     259,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   265,   266,     0,
       0,     0,     0,     0,   219,   174,     0,   267,    25,     0,
     268,   220,   221,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   400,   242,   243,   244,   245,   246,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,     0,     0,   259,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   264,   265,   266,    43,    44,    45,
      46,     0,     0,     0,    48,   267,    25,     0,   268,     0,
       0,     0,     0,   803,    57,     0,     0,    60,   804,     0,
     805,   806,     0,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
       0,   282,    82,     0,     0,     0,     0,   284,   285,   286,
       0,   287,   288,   289,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,     0,   290,   401,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,   376,  1685,     0,     0,
       0,     0,     0,   295,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,   281,  1459,     0,     0,   282,
       0,     0,     0,     0,     0,   284,   285,   286,     0,   287,
     288,   289,     0,     0,     0,   123,  1032,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   401,     0,     0,     0,     0,     0,   292,
     219,   174,     0,     0,   376,  2030,     0,   220,   221,   222,
       0,   295,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     400,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,   258,
       0,     0,     0,     0,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,   265,   266,     0,     0,     0,     0,     0,   219,   174,
       0,   267,    25,     0,   268,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   400,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   406,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   267,
      25,     0,   268,     0,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,   417,   418,
     419,     0,     0,     0,     0,   420,   421,   422,   423,     0,
       0,   281,     0,     0,   424,   282,   425,     0,     0,     0,
       0,   284,   285,   286,     0,   287,   288,   289,     0,     0,
     426,   123,     0,   427,     0,     0,     0,   180,     0,     0,
     181,     0,     0,   182,     0,   183,     0,     0,   290,   401,
       0,     0,     0,     0,     0,   292,    46,     0,     0,     0,
     376,     0,     0,     0,  2093,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,   456,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
       0,     0,     0,   282,     0,     0,     0,     0,     0,   284,
     285,   286,     0,   287,   288,   289,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   401,     0,     0,
       0,     0,     0,   292,     7,     8,     0,     0,   376,   428,
     429,   430,     0,     0,     0,   295,     0,     0,     0,     0,
       0,   431,     0,     0,     0,   432,     0,   433,   123,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,  1861,   803,    57,     0,     0,    60,   804,     0,   805,
     806,     0,   807,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     7,     8,     0,
      43,    44,    45,    46,     0,     0,     0,    48,    99,   100,
     101,     0,     0,     0,     0,     0,   803,    57,     0,     0,
      60,   804,     0,   805,   806,     0,   807,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,    82,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1559,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1087,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   803,
      57,     0,     0,    60,   804,     0,   805,   806,     0,   807,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,  1089,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     7,     8,     0,    43,    44,    45,    46,
       0,     0,     0,    48,     0,    99,   100,   101,     0,     0,
       0,     0,   803,    57,     0,     0,    60,   804,     0,   805,
     806,     0,   807,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,    82,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1560,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1294,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   803,    57,     0,     0,    60,
     804,     0,   805,   806,     0,   807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,  1296,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     7,
       8,     0,    43,    44,    45,    46,     0,     0,     0,    48,
       0,    99,   100,   101,     0,     0,     0,     0,   803,    57,
       0,     0,    60,   804,     0,   805,   806,     0,   807,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,    82,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1607,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,   100,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1297,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   803,    57,     0,     0,    60,   804,     0,   805,   806,
       0,   807,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,  1316,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     7,     8,     0,    43,    44,
      45,    46,     0,     0,     0,    48,     0,    99,   100,   101,
       0,     0,     0,     0,   803,    57,     0,     0,    60,   804,
       0,   805,   806,     0,   807,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,    82,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1736,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1336,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,   803,    57,     0,
       0,    60,   804,     0,   805,   806,     0,   807,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,  1354,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     7,     8,     0,    43,    44,    45,    46,     0,     0,
       0,    48,     0,    99,   100,   101,     0,     0,     0,     0,
     803,    57,     0,     0,    60,   804,     0,   805,   806,     0,
     807,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,    82,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1737,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1391,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   803,    57,     0,     0,    60,   804,     0,
     805,   806,     0,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,  1557,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,     0,    48,     0,    99,
     100,   101,     0,     0,     0,     0,   803,    57,     0,     0,
      60,   804,     0,   805,   806,     0,   807,     0,     0,     0,
       0,     0,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,    82,    -4,    -4,     0,     0,
       0,     0,     0,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,    99,   100,   101,   626,     0,     0,     0,     0,
      -4,    -4,    -4,     0,     0,  1738,  2221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,  2279,
       0,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
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
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     9,    10,    11,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1889,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,     0,    25,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    42,    43,    44,    45,    46,     0,    47,     0,
      48,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,    94,    95,    96,     0,     0,     0,    97,
       0,     0,     0,     0,    98,    99,   100,   101,   174,   406,
     102,     0,   103,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,     0,     0,
       0,     0,     0,     0,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,   407,   408,   409,   410,   411,   412,
     413,   414,   415,     0,     0,     0,     0,   416,   417,   418,
     419,   437,   406,     0,     0,   420,   421,   422,   423,     0,
       0,     0,     0,     0,   424,     0,   425,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     426,     0,     0,   427,     0,     0,     0,   180,     0,   406,
     181,     0,     0,   182,     0,   183,     0,   407,   408,   409,
     410,   411,   412,   413,   414,   415,    46,     0,     0,     0,
     416,   417,   418,   419,     0,     0,     0,     0,   420,   421,
     422,   423,     0,     0,     0,     0,   456,   424,     0,   425,
       0,     0,     0,     0,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   426,     0,     0,   427,   416,   417,   418,
     419,     0,     0,     0,     0,   420,   421,   422,   423,     7,
       8,     0,     0,     0,   424,     0,   425,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     426,     0,     0,   427,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,     0,     0,     0,   432,     0,   433,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   428,   429,   430,    43,    44,    45,    46,     0,
       0,     0,    48,     0,   431,     0,     0,     0,   432,     0,
     433,   803,    57,     0,     0,    60,   804,     0,   805,   806,
       0,   807,     0,     0,     0,  1095,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,     0,     0,
      82,   431,     0,     0,  1096,   432,     0,   433,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    99,   100,   101,
      43,    44,    45,    46,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   803,    57,     0,     0,
      60,   804,     0,   805,   806,     0,   807,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,    82,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2017,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2018,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2050,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2127,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2142,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2187,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2188,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2203,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2239,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2267,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2272,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2273,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1130,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1188,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1237,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1238,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1286,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1319,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1334,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1341,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  1402,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  1422,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1458,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1508,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1509,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1510,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1513,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1515,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1516,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1561,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  1637,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  1745,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1943,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1954,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1997,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  2073,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  2089,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  2104,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    2128,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  2165,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  2175,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  2176,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  2201,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  2205,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  2245,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  2253,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  2292,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  2310,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    2328,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  2329,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,   765,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,   990,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,  2066,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,   789,     0,
     790,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,  1061,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,  1106,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,  1265,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,  1335,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,  1337,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,  1344,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,  1345,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,  1437,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,  1451,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
    1666,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,  1760,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,  1813,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,  2009,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,  2056,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,  2074,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     843,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   844,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     845,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   847,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     848,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   849,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     851,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   852,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     853,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   854,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     855,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   856,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     857,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   859,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     860,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   861,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     937,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   971,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1021,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1038,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1046,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1048,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1049,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1055,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1056,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1094,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1105,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1166,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1170,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1182,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1264,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1274,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1275,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1276,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1285,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1287,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1288,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1318,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1320,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1321,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1322,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1323,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1324,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1325,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1326,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1333,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1347,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1349,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1390,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1436,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1450,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1667,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1703,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1747,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1759,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1876,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1878,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1881,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1888,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1944,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1953,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1980,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    2055,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2125,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    2126,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2266,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    2307,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626
};

static const yytype_int16 yycheck[] =
{
       3,   164,   331,  1520,  1313,  1317,  1798,     5,   466,   665,
     666,   786,    25,    70,    71,     4,    73,   792,     5,    76,
      64,  1844,    25,  1846,     6,     5,     4,     4,   684,     3,
       6,     4,  2033,   109,     4,     4,   109,     5,  1833,   113,
       4,   115,     7,     6,     4,     6,     0,     6,     6,     6,
       6,   146,     4,    56,     6,     4,     4,   106,    68,     6,
     109,   109,     6,     6,   109,   103,     4,   263,     4,   265,
     168,   150,   150,   122,   264,    97,   150,   155,   156,   157,
     251,   252,   272,    86,   122,    14,     7,   135,     7,    92,
     135,     9,     6,   103,    97,   264,   263,   268,   196,   102,
     146,  1896,     9,   272,   199,   179,     6,     4,   251,   252,
     113,   185,     9,     4,   212,   213,     4,    95,   263,   165,
     265,  1913,     9,   201,   269,   264,   168,   272,     9,   272,
     176,   177,   178,   272,   264,     9,   182,   183,    26,   269,
     218,   251,   252,   269,   146,     9,   272,   150,     6,    37,
      38,   103,   155,   156,   157,   103,   263,     6,   265,   107,
     267,   164,   272,   165,   103,   113,   114,   106,   116,   117,
     109,   263,   630,   265,   176,   177,   178,   151,   267,     8,
     182,   183,   271,   122,   206,   251,   252,   263,   251,   252,
     263,   139,   260,   261,   216,  2196,   106,   109,   201,   109,
       7,   269,   184,   206,   266,     7,   272,   210,   211,   272,
     272,   251,   252,   216,   217,   218,   172,   261,   262,   263,
     251,   252,   268,   251,   252,   184,   263,   251,   252,   207,
     267,     7,   272,     6,   264,  1752,   280,   186,   187,   188,
     189,   272,   272,     7,   272,   234,   263,   211,   272,   198,
     264,   200,   201,   202,   203,   204,   234,   234,   272,   208,
     209,   234,   211,   263,   234,   265,   268,   263,  1577,   267,
       7,  2063,   272,   276,   732,   251,   252,   334,   335,     6,
     267,   270,   295,   246,   247,   342,   343,   267,   291,   267,
     267,   294,   295,   315,   316,   317,   265,   267,   267,   267,
       6,   343,   271,   263,   269,   263,   267,   310,   311,   267,
     267,   314,   315,   316,   317,   236,   237,   238,   239,   268,
     267,   363,   325,   267,   267,   263,   329,   263,   331,  2121,
    1105,  1106,   246,   247,   356,   357,   358,   234,     6,   260,
     261,   264,   800,   234,   263,   263,   265,   265,   269,   272,
     353,   269,   374,   356,   357,   358,   263,   263,   265,   817,
     263,   267,   269,   260,   261,   267,   263,   445,   265,   827,
     267,   374,   269,   264,   377,   266,   263,   266,   265,   260,
     261,   455,   263,   272,   265,   266,   260,   261,   269,   263,
     265,   265,     4,   251,   252,   269,   260,   261,   440,   263,
     442,   265,   251,   252,   109,   269,   111,   449,   571,   265,
    2233,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   236,
     237,   238,   239,   262,   236,   237,   238,   239,   264,   268,
     266,     6,   445,   263,   447,     4,   272,   267,   451,   452,
     251,   252,   106,   260,   261,   109,   110,   111,   260,   261,
     236,   237,   238,   239,   467,     6,   267,    26,   122,   260,
     261,   474,   236,   237,   238,   239,   267,  2269,    37,    38,
     264,   939,   251,   252,   260,   261,     4,   565,   272,   567,
       4,   569,   570,   251,   252,   269,   499,   271,   146,   236,
     237,   238,   239,   272,   251,   252,   267,   264,    26,   266,
     588,   589,    26,   264,   272,   272,   125,   165,   592,    37,
      38,   272,   525,    37,    38,   272,   109,  2319,   176,   177,
     178,  1187,   256,   257,   182,   183,  2053,   191,   262,   151,
     152,   153,   154,   264,   263,   157,   158,   267,   551,   251,
     252,   272,   268,   112,   113,   167,   272,   560,   561,   171,
     260,   261,   565,   585,   567,   568,   569,   570,   571,   264,
     272,   266,   146,   736,   577,   251,   252,   272,   591,   263,
     593,   584,   585,   586,     6,   588,   589,   590,   591,   268,
     593,   165,   595,   272,   112,   113,   272,   268,   112,   113,
       4,   272,   176,   177,   178,     8,   663,   664,   182,   183,
       4,   668,   654,   263,   656,   657,   260,   261,   621,   263,
     268,   265,    26,   267,   627,   251,   252,   251,   252,   251,
     252,   673,    26,    37,    38,   251,   252,   196,   197,   151,
     152,   267,   263,    37,    38,   157,   649,   650,   272,  1107,
     272,   693,     6,     7,   251,   252,   272,   735,   263,   737,
     738,   739,   740,   741,   742,   263,   744,   745,   746,   747,
     267,  1327,   750,   751,   752,   749,   263,   268,   720,   251,
     252,   272,   196,   197,   146,   251,   252,   151,   152,   251,
     252,   665,   666,   157,   268,   268,   699,   700,   701,   272,
     272,   251,   252,   165,   707,   267,   272,   786,   112,   113,
     684,   263,   251,   252,   176,   177,   178,   263,   112,   113,
     182,   183,   272,   765,   263,   268,   729,   263,   267,   272,
     263,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     753,   744,   745,   746,   747,   748,   824,   750,   751,   752,
     753,   754,   251,   252,   757,   251,   252,   835,   251,   252,
     263,   106,   806,   263,   109,     3,   111,     8,   842,   251,
     252,  1546,   775,   272,   103,   263,   272,   106,     6,   272,
     109,   263,   111,   268,   264,   267,   266,   272,   791,    27,
    1248,   263,  1250,   122,   797,   264,   106,   266,   264,   109,
     266,   111,   263,   272,   265,  1263,   272,   251,   252,   268,
     813,   814,   122,   272,   260,   261,   819,   263,   821,   265,
     268,   824,   825,   268,   272,    63,     8,   272,   260,   261,
     833,   263,   835,   265,   263,  1293,   265,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   111,   268,   268,   267,   262,
     272,   272,   865,   263,   867,   268,   263,  1642,   251,   252,
     253,   254,   255,   256,   257,   267,     4,  1652,     6,   262,
     118,   253,   254,   255,   256,   257,   263,   268,   268,   968,
     262,   272,   272,   268,   268,   109,   267,   272,   272,  1357,
     268,   904,  1360,  1361,   272,   268,   106,   981,   267,   272,
    2222,   914,   150,   263,   267,   109,   268,   155,   156,   157,
     272,   268,   106,     6,   268,   272,   164,  1385,   272,   268,
     268,   268,   268,   272,   272,   272,   272,   268,   941,   267,
     997,   272,   106,   109,   268,   268,  2255,  1004,   272,   272,
    1408,  1008,   994,   268,   957,     6,   268,   272,     4,     4,
     272,   268,   109,   201,     4,   272,   969,   268,  2280,   268,
     268,   272,   268,   272,   272,   978,   272,  1435,   268,   268,
     218,  1060,   272,   272,     4,   268,   268,   990,  2297,   272,
     272,  1449,   268,   268,   263,   263,   272,   272,  1456,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   263,     6,   263,
     268,   262,   260,   264,   272,   266,  1105,  1106,   268,   268,
     265,     6,   272,   272,   268,  1109,   265,   267,   272,     6,
     278,   279,   268,  1122,   268,   268,   272,   268,   272,   272,
     268,   272,   271,   268,   272,   267,  1134,   272,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   264,   268,   266,   267,
     262,   272,   264,  1412,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,  1100,   268,   268,
     268,   262,   272,   272,   272,  1108,  1163,     6,   268,   271,
     268,   268,   272,  1116,   272,   272,   268,   268,   268,   263,
     272,   272,   272,     9,   263,   263,  1129,  1783,  1784,   263,
     263,  1134,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   267,  1227,
    1228,   264,   262,   266,   267,   263,   263,   199,   199,   109,
     199,  1164,  1165,   267,  1167,  1168,  1169,   135,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,   263,   263,
    1183,   263,   263,   199,   263,  1264,  1265,   210,   211,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   445,   267,   263,
     263,   262,   267,  1187,   263,   267,     4,   267,   456,   267,
     267,     6,   265,  1226,  1227,  1228,   263,   263,   263,   263,
     263,   263,   263,     6,     6,   199,     7,   267,   267,   267,
     478,   267,   267,   265,   265,     6,   265,     6,   263,   263,
     267,   263,  1255,   263,   263,   493,   263,    56,   263,   263,
       6,     6,   265,     6,     8,   267,     6,     8,  1271,  1272,
    1273,   263,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   310,   311,   267,
    1368,   262,     7,     6,  1372,   267,     6,   267,   267,   272,
      98,   264,   268,  1381,     7,  1383,     6,   272,  1386,     6,
     264,   267,   267,    68,   267,   267,  1645,   262,   267,   267,
     267,   267,     8,     7,     7,   269,  1329,   565,   263,   567,
     353,   569,   570,   571,   264,     6,   267,     7,     6,   268,
       7,     6,     6,   196,   267,  1348,   268,  1350,  1351,   268,
     588,   589,   266,  1327,   264,     6,   267,  1436,  1437,  1437,
    1363,   269,     7,     6,   265,  1368,   263,   267,     6,  1372,
       6,     6,     6,     6,   264,     7,   265,     7,  1381,     7,
    1383,     7,     7,  1386,     7,     7,  1460,     7,  1462,     7,
       7,     7,  1850,     7,     7,     7,  1399,     7,     7,   267,
       6,   264,   266,   272,   264,   272,   272,   268,   267,  1412,
     272,     7,   268,  2069,   269,     7,   267,   267,   217,     4,
       6,   269,   268,   268,   447,   146,   267,     7,   268,     6,
     269,     7,     7,   671,  1437,     7,   269,   264,   264,  1442,
     272,  1444,   272,     9,   272,   264,   266,   271,   199,     7,
     168,   268,   267,     6,     6,     6,    50,    50,   696,  1462,
     269,   263,   267,   263,   267,   269,   263,   263,   269,     7,
       7,     7,  1475,     6,   199,   264,  1479,   276,   272,     7,
       7,     7,     6,   264,     7,   272,     7,     7,     7,     7,
    1653,  1654,   121,     4,     6,   263,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   267,   744,   745,   746,   747,
       7,     6,   750,   751,   752,   314,     7,     7,     7,  1576,
       7,     7,   760,     7,     7,   763,   325,     6,   267,  1858,
     329,   769,   103,     6,     6,   109,     7,  1540,  1541,  1542,
       7,     6,     6,     4,     7,  1548,  1549,  1550,     7,   272,
     270,     6,  1626,   264,   268,   272,     6,     6,   267,   267,
     267,     7,     6,  1642,  1567,     6,   265,   805,     6,   807,
       4,     5,   595,   263,   263,  1578,   267,     6,     6,     6,
     268,     6,   269,  1586,     6,   266,   824,  1590,  1630,     6,
     272,     6,  1634,   139,     6,     6,     6,   835,  1601,  1677,
    1603,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   268,   264,   126,  1688,   199,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   264,   649,   650,     6,    63,
      64,    65,    66,     6,     6,     4,     6,    71,    72,    73,
      74,     7,  1645,   267,     6,     6,    80,     7,    82,  1706,
    1653,  1654,   451,   452,   265,     6,  1659,     6,     6,   267,
     267,     6,    96,   267,   267,    99,   267,   267,   467,   267,
     267,     6,   267,   195,  1677,   264,   699,   700,   701,  1758,
     267,   272,   272,     6,   707,  1688,   268,     7,   267,   267,
    1693,   272,     6,     6,   267,   263,     6,     6,  1861,     4,
     269,   268,   272,   267,   263,  1779,   263,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,     7,     6,     6,     6,   262,
       6,   107,   146,     6,   757,     5,   267,     6,   267,   264,
     272,   109,  1799,  1800,  1801,  1802,  1803,  1804,     6,     6,
    1828,   267,  1826,  1831,   146,   993,   146,   995,   996,  1833,
    1834,   267,     6,   272,     6,     6,     6,  1770,   791,   568,
       6,  1009,  1775,  1776,     6,     6,   272,     6,  1852,  2108,
     272,   215,   216,   217,   264,   584,     6,   586,     6,   267,
     813,   272,  1030,   227,     6,  1798,   819,   231,   821,   233,
     234,  1804,     6,     6,     6,   267,  1809,     6,   150,  1783,
    1784,   267,     7,     6,  1052,  1818,   267,     5,     7,   267,
     267,   264,   267,     6,     6,  1828,     6,   267,  1831,   268,
     267,     6,   268,     6,   267,   194,     6,     6,   264,     7,
       6,     6,     6,     6,  1847,   268,     6,   268,  1851,   268,
       6,   269,     6,  1091,   267,  1858,     6,  1860,  1861,   268,
       6,     6,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     264,   904,   267,     6,   262,   197,     6,   267,     6,   268,
     267,   914,   263,  1896,   268,     6,  1134,   264,     6,     6,
     146,     6,   267,   267,   267,     6,     6,     6,   264,   267,
    1913,   268,   267,     6,   268,   268,     6,     6,     6,     6,
       6,     6,  1996,     6,  1927,  1928,   267,     6,   267,     6,
       6,   267,     6,     6,   957,     6,     6,     6,  1448,  2235,
     496,  1511,  1701,  2034,  1994,  1766,   969,  1474,     3,  1952,
       3,   582,     3,  1118,     3,     3,  2065,   642,  1623,  1851,
    1833,  1964,  1654,    -1,    -1,  2039,   824,   990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   775,    -1,    -1,  1982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1227,
    1228,    -1,    -1,    -1,    -1,     6,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,  2020,   262,    -1,
      -1,    -1,    -1,    -1,    -1,  2082,  2083,  2084,  2085,  2086,
      -1,    -1,  2035,    -1,    -1,    -1,  2078,  2040,    -1,    -1,
    2043,  2044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,    -1,
    2063,    -1,    -1,  2066,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2077,    -1,    -1,    -1,  2081,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2093,    -1,    -1,    -1,  2151,  2069,    -1,    -1,  2155,    -1,
      -1,    -1,    -1,    -1,    -1,  2108,  1129,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,  2121,    -1,
      -1,    -1,    -1,  2197,    -1,    -1,    -1,    -1,    -1,    -1,
    1368,    -1,    -1,    -1,  1372,    -1,    -1,    -1,    -1,  2181,
      -1,    -1,   941,  1381,    -1,  1383,    -1,    -1,  1386,  2152,
      -1,    -1,  2209,    -1,    -1,  1393,  2213,    -1,    -1,    -1,
    1183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2229,    -1,    -1,    -1,    -1,    -1,    -1,   978,
      -1,  2223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,
      -1,    -1,    -1,    -1,  2207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2275,  2276,
      -1,    -1,  2225,  2226,  2227,  2228,  2229,    -1,  2306,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,  2325,  2326,  1272,
    1273,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2338,    -1,    -1,    -1,    -1,    -1,  2269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,  1100,    28,  2306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2319,  1116,    -1,    -1,
      -1,    -1,  2325,  2326,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2338,    -1,    -1,    -1,    -1,
    1363,    -1,     4,     5,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,  1164,  1165,   262,  1167,  1168,
    1169,    -1,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,
    1179,  1180,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     6,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,  1653,  1654,    -1,    80,  1442,
      82,  1444,    -1,    -1,   150,    -1,    -1,  1226,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,  1677,
      -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,  1255,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
    1329,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   268,    -1,    -1,    -1,    -1,    -1,    -1,  1348,
      -1,  1350,  1351,   215,   216,   217,   282,   283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,  1590,    -1,   231,
      -1,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1828,    -1,    -1,  1831,    -1,    -1,    -1,    -1,   260,   261,
    1399,    -1,    -1,    -1,    -1,   267,  1844,   269,  1846,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1861,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,  1896,    -1,
      -1,    -1,    -1,  1462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,    -1,  1475,    -1,    -1,    -1,
    1479,   407,   408,   409,    -1,    -1,    -1,   413,   414,   415,
     416,   417,   418,   419,    -1,   421,    -1,    -1,    -1,    -1,
     426,   427,     3,     4,   430,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,  1540,  1541,  1542,    -1,    -1,    -1,    -1,    -1,  1548,
    1549,  1550,  1775,  1776,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,     4,     5,    -1,    -1,    67,    -1,  1567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1578,
      -1,    -1,    83,    84,    85,    -1,  1809,  1586,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,  1601,    -1,  1603,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,
    1659,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,  1927,  1928,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,   218,    -1,    -1,
      -1,    -1,    -1,   224,   225,   226,  2164,   228,   229,   230,
       6,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,  1982,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,  1770,    -1,   215,   216,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,
      -1,   233,   234,    -1,    -1,  2233,    -1,    -1,    -1,  1798,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2256,  1818,
    2043,  2044,   264,    -1,   266,   267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2066,    -1,    -1,    -1,    -1,  1847,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,  2081,    -1,
      -1,  1860,    -1,    -1,    -1,    -1,    -1,    -1,  2306,   122,
    2093,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2325,  2326,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
    2338,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,  1913,    -1,   169,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,    -1,   190,   191,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,  1952,    -1,    -1,    -1,   210,   211,    -1,
      -1,    -1,    -1,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,  2207,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,  2225,  2226,  2227,  2228,  2229,    -1,    -1,   935,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2020,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2035,   290,   291,   292,
     293,   294,   968,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   309,   310,   311,    -1,
      -1,    -1,  2285,    -1,  2063,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,  2077,    -1,
      -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,    -1,
     343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,   355,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,  2121,   376,   377,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   387,    -1,   389,   390,    -1,   392,
      -1,    -1,    -1,   396,   397,   398,    -1,    -1,   401,    -1,
      -1,    -1,   405,  2152,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   447,   448,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   464,   465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,  1154,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   501,    -1,
      -1,   262,    -1,   506,    -1,    -1,    -1,   510,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2269,   524,   525,    -1,    -1,    -1,    -1,   530,    -1,    -1,
      -1,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,    -1,
     563,   564,    -1,   566,    -1,    -1,    -1,    -1,   210,   211,
    2319,    -1,    -1,   576,    -1,    -1,   579,   580,    -1,    -1,
    1256,    -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,    -1,
      -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,    -1,   628,   629,    -1,    -1,    -1,
      -1,     6,    -1,   636,   637,   638,    -1,    -1,    -1,    -1,
      -1,   644,   645,   646,   647,    -1,   649,   650,    -1,   291,
      -1,    -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   668,   669,   670,   310,   311,
      -1,   674,   675,   676,   677,   678,   679,   680,   681,   682,
      -1,    -1,    -1,    -1,    -1,    -1,   689,   690,    -1,   692,
      -1,    -1,   695,     6,    -1,    -1,   699,   700,   701,   702,
      -1,    -1,    -1,   706,   707,   708,   709,   710,    -1,    -1,
     713,   353,   715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   725,    -1,    -1,   728,    -1,   730,   731,    -1,
      -1,    -1,    -1,    -1,    -1,   377,    -1,    -1,    -1,    -1,
     743,    -1,    -1,  1419,  1420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   757,    -1,    -1,    -1,    -1,    -1,
      -1,   764,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   772,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   791,     6,
     793,    -1,   262,    -1,   264,   798,   799,    -1,    -1,    -1,
      -1,    -1,   272,    -1,    -1,   447,    -1,    -1,    -1,    -1,
     813,    -1,   815,   816,    -1,    -1,   819,    -1,   821,   822,
      -1,    -1,    -1,   826,    -1,   828,    -1,   830,    -1,    -1,
      -1,    -1,    -1,   836,    -1,    -1,    -1,   840,    -1,    -1,
       6,    -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1529,    -1,    -1,    -1,    -1,    -1,    -1,
     863,    -1,   865,    -1,   867,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   525,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,
      -1,   914,   915,   916,   917,    -1,    -1,    -1,   560,   561,
      -1,   924,    -1,   926,    -1,    -1,   929,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,     6,   590,   262,
      -1,    -1,    -1,   595,   957,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   977,    -1,    -1,    -1,   981,   621,
      -1,    -1,    -1,    -1,   987,    -1,    -1,   990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   998,   999,    -1,    -1,    -1,
      -1,  1004,    -1,    -1,    -1,    -1,    -1,   649,   650,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1692,    -1,    -1,  1022,
      -1,    -1,  1025,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,     6,    -1,    -1,    -1,   262,    -1,    -1,  1051,    -1,
    1053,  1054,    -1,    -1,    -1,    -1,    -1,   699,   700,   701,
      -1,    -1,    -1,    -1,    -1,   707,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1076,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,  1096,    -1,    -1,   262,    -1,    -1,    -1,
    1103,    -1,    -1,    -1,    -1,    -1,    -1,  1110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   757,    -1,    -1,    -1,    -1,
    1123,  1124,    -1,    -1,    -1,    -1,  1129,    -1,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,   791,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   813,    -1,     6,    -1,    -1,    -1,   819,    -1,   821,
    1183,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,  1202,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,  1212,
    1213,  1214,  1215,  1216,    -1,    -1,    -1,    -1,  1221,  1222,
      -1,  1224,    -1,   865,    -1,   867,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1240,    -1,    -1,
    1243,  1244,    -1,    -1,    -1,    -1,    -1,    -1,  1251,  1252,
      -1,    -1,    -1,    -1,     6,    -1,    -1,  1260,  1261,    -1,
      -1,    -1,   904,  1266,  1267,    -1,    -1,    -1,    -1,  1272,
    1273,    -1,   914,    -1,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,  1307,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1346,    -1,    -1,    -1,    -1,   990,    -1,
      -1,    -1,    -1,    -1,    -1,  1358,  1359,    -1,    -1,    -1,
    1363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1371,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,  1395,   264,    -1,   266,    -1,    -1,    -1,    -1,
      -1,   272,    -1,  1406,    -1,    -1,  1409,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   146,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,  1438,    -1,    -1,  1441,  1442,
    1443,  1444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1452,
      -1,    -1,  1455,    -1,  1457,    -1,  1459,  1460,    -1,    -1,
    1463,  1464,  1465,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,  1129,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,  1183,   262,    -1,  1547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1558,  1559,  1560,    -1,    -1,
      -1,    -1,    -1,    -1,  1567,    -1,  1569,    -1,    -1,    -1,
      -1,    -1,    -1,  1576,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   469,    -1,    -1,    -1,  1590,    -1,    -1,
      -1,    -1,    -1,  1596,  1597,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1607,  1608,  1609,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1618,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1628,    -1,    -1,    -1,    -1,
    1272,  1273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1649,    -1,    -1,    -1,
       3,     4,    -1,    -1,  1657,  1658,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
    1693,   577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,  1363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,  1736,  1737,  1738,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    -1,   632,  1750,    -1,    -1,
      -1,    -1,  1755,  1756,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1768,    -1,    -1,    -1,    -1,
      -1,    -1,  1775,  1776,  1777,    -1,  1779,    -1,    -1,    -1,
      -1,    -1,  1785,  1786,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1442,  1804,  1444,    -1,    -1,    -1,  1809,  1810,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1822,
    1823,    -1,    -1,  1826,    -1,    -1,  1829,    -1,    -1,    -1,
    1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,   214,    -1,    -1,  1867,   218,    -1,    -1,    -1,  1872,
    1873,   224,   225,   226,    -1,   228,   229,   230,    -1,    -1,
      -1,   234,    -1,  1886,    -1,    -1,  1889,  1890,    -1,  1892,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,   267,  1918,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,  1927,  1928,    -1,    -1,    -1,    -1,
      -1,  1934,  1935,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,    -1,    -1,    -1,    -1,  1590,    -1,
      -1,    -1,  1955,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1977,  1978,    -1,    -1,  1981,  1982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   873,   874,   875,
     876,   877,   878,   879,   880,   881,   882,   883,   884,    -1,
     886,   887,   888,   889,     6,   891,   892,   893,   894,    -1,
      -1,    -1,    -1,    -1,  2017,  2018,    -1,    -1,    -1,    -1,
      -1,   907,    -1,   909,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   920,  2038,    -1,    -1,    -1,    -1,
    2043,  2044,  2045,    -1,    -1,   931,   932,  2050,    -1,  2052,
      -1,  1693,    -1,    -1,   940,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,  2066,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2081,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2090,    -1,    -1,
    2093,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,  2118,    -1,    -1,    -1,    -1,
      -1,  2124,    -1,    -1,  2127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1775,  1776,    -1,    -1,    -1,    -1,  2142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2160,    -1,    -1,
      -1,    -1,  1804,    -1,    -1,    -1,    -1,  1809,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1062,  1063,  1064,    -1,
      -1,    -1,  1068,  1069,  2187,  2188,  1072,  1073,  1074,  1075,
      -1,  1077,    -1,    -1,    -1,    -1,  1082,    -1,    -1,  2202,
    2203,    -1,    -1,    -1,  2207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2220,    -1,    -1,
      -1,    -1,  2225,  2226,  2227,  2228,  2229,    -1,    -1,    -1,
      -1,    -1,  2235,    -1,    -1,    -1,  2239,    -1,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,  2267,    13,    14,    -1,    -1,  2272,
    2273,    -1,    -1,    -1,  1160,    -1,  1162,    -1,    -1,    -1,
      -1,    -1,  2285,    -1,    -1,  1927,  1928,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,  2312,
    2313,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1964,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,  1269,    -1,    -1,    -1,   135,   136,    -1,
      -1,   139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,
      -1,  2043,  2044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2066,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2081,
      -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,  2093,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
     268,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,  1418,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,  2207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,  1461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2225,  2226,  2227,  2228,  2229,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1494,  1495,
    1496,  1497,  1498,  1499,  1500,    -1,    -1,    -1,    -1,  1505,
    1506,    -1,    -1,    -1,    -1,    -1,  1512,    -1,    -1,    -1,
      -1,    -1,  1518,    -1,    -1,    -1,  1522,    -1,    -1,  1525,
      -1,    -1,    -1,  2285,    -1,    -1,    -1,    -1,    -1,    -1,
    1536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,   233,   234,    -1,   236,   237,   238,
     239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
       8,   260,   261,    -1,   263,    -1,   265,    -1,    -1,    -1,
     269,   270,    -1,    -1,    -1,    -1,    -1,    -1,  1614,    -1,
    1616,    -1,    -1,    -1,  1620,    -1,  1622,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,   268,    -1,  1653,    -1,   272,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     8,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,     8,
      71,    72,    73,    74,    -1,    -1,    77,    78,    79,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,    -1,
      -1,  1757,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,   140,
      -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,
     171,    -1,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1863,    -1,    -1,
    1866,    -1,    -1,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,    -1,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,  1915,
    1916,    -1,   263,    -1,  1920,    -1,   267,    -1,    -1,   270,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1987,  1988,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
    2036,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    77,    78,
      79,    80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,
      99,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,
      -1,   140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,
      -1,    -1,   171,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,   233,   234,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,   267,    -1,
      -1,   270,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,     3,     4,     5,
     268,    -1,    -1,    -1,    10,    11,    12,    -1,  2294,    15,
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
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,   137,   138,    -1,   140,    -1,   142,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,   167,    -1,    -1,    -1,   171,    -1,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
     196,   262,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,    -1,   224,   225,
     226,    -1,   228,   229,   230,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,   263,     3,     4,
      -1,   267,    -1,     8,   270,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,    -1,   137,   138,    -1,   140,    -1,   142,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,   167,    -1,    -1,    -1,   171,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,   224,
     225,   226,    -1,   228,   229,   230,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   263,     3,
       4,     5,    -1,   268,    -1,   270,    10,    11,    12,    -1,
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
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,    -1,   137,   138,    -1,   140,    -1,   142,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,
     154,   155,    -1,   157,   158,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,    -1,    -1,    -1,   171,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,   196,    -1,    -1,    -1,   268,    -1,    -1,    -1,
     272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,
     224,   225,   226,    -1,   228,   229,   230,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   263,
       3,     4,    -1,   267,    -1,    -1,   270,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,    -1,   137,   138,    -1,   140,    -1,   142,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,   196,    -1,    -1,    -1,   268,    -1,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
      -1,   224,   225,   226,    -1,   228,   229,   230,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,     3,     4,    -1,   267,   268,    -1,   270,    10,    11,
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
     122,   123,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,   137,   138,    -1,   140,    -1,
     142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,   196,    -1,    -1,    -1,   268,    -1,
      -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,   219,    -1,    -1,
      -1,    -1,   224,   225,   226,    -1,   228,   229,   230,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,   263,     3,     4,    -1,   267,    -1,    -1,   270,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,   140,
      -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,
     171,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,    -1,   224,   225,   226,    -1,   228,   229,   230,
      -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,   263,     3,     4,    -1,   267,    -1,    -1,   270,
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
      -1,    -1,   122,   123,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,
      -1,   171,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,   229,
     230,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,   263,     3,     4,    -1,   267,    -1,    -1,
     270,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,
      -1,   140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,
      -1,    -1,   171,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,
     229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,   263,     3,     4,    -1,    -1,   268,
      -1,   270,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     118,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,
     138,    -1,   140,    -1,   142,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
      -1,    -1,    -1,   171,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
     218,   219,    -1,    -1,    -1,    -1,   224,   225,   226,    -1,
     228,   229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,   263,     3,     4,    -1,   267,
      -1,    -1,   270,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,   118,    -1,    -1,    -1,   122,   123,    -1,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
     137,   138,    -1,   140,    -1,   142,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,   162,   163,    -1,    -1,    -1,
     167,    -1,    -1,    -1,   171,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,   219,    -1,    -1,    -1,    -1,   224,   225,   226,
      -1,   228,   229,   230,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,   263,     3,     4,    -1,
     267,    -1,    -1,   270,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,   137,   138,    -1,   140,    -1,   142,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,   167,    -1,    -1,    -1,   171,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,   218,   219,    -1,    -1,    -1,    -1,   224,   225,
     226,    -1,   228,   229,   230,    -1,    -1,    -1,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,   263,     3,     4,
      -1,   267,    -1,     8,   270,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,    -1,   137,   138,    -1,   140,    -1,   142,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,   163,    -1,
      -1,    -1,   167,    -1,    -1,    -1,   171,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,   224,
     225,   226,    -1,   228,   229,   230,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,
      -1,    -1,    -1,   258,     3,     4,    -1,    -1,   263,     8,
      -1,    10,    11,    12,    -1,   270,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,
      -1,   140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,
      -1,    -1,   171,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,   196,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,   218,
     219,    -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,
     229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
       3,     4,    -1,    -1,   263,    -1,    -1,    10,    11,    12,
      -1,   270,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,    -1,   137,   138,    -1,   140,    -1,   142,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,   157,   158,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,   219,    -1,    -1,    -1,
      -1,   224,   225,   226,    -1,   228,   229,   230,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,     3,     4,    -1,   267,    -1,    -1,   270,    10,    11,
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
     122,   123,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,   137,   138,    -1,   140,    -1,
     142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,   171,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,   219,    -1,    -1,
      -1,    -1,   224,   225,   226,    -1,   228,   229,   230,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,   263,     3,     4,    -1,   267,    -1,    -1,   270,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,   140,
      -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,    -1,
     171,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   214,    -1,    -1,    -1,   218,   219,    -1,
      -1,    -1,    -1,   224,   225,   226,    -1,   228,   229,   230,
      -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,   263,     3,     4,    -1,    -1,   268,    -1,   270,
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
      -1,    -1,   122,   123,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,
      -1,   171,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,   218,   219,
      -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,   229,
     230,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,     3,
       4,     5,    -1,   263,    -1,    -1,    10,    11,    12,    -1,
     270,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,    -1,    99,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,    -1,   233,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,   267,    -1,    -1,   270,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,   230,   231,    -1,   233,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,   263,     3,     4,     5,
     267,    -1,    -1,   270,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    -1,    99,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,   233,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,   267,    -1,    -1,   270,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,    -1,   233,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
       3,     4,    -1,    -1,   263,    -1,    -1,    10,    11,    12,
      -1,   270,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    94,    95,     8,    97,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    83,    84,
      85,   119,   120,   121,   122,    -1,    -1,    -1,   126,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,   135,   136,    -1,
      -1,   139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,   164,    -1,    -1,    -1,
      -1,   224,   225,   226,    -1,   228,   229,   230,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,   192,   193,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,   267,    -1,    -1,   270,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
     272,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,   224,
     225,   226,    -1,   228,   229,   230,    -1,    -1,    -1,   234,
     268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,
      -1,    -1,    -1,   258,     3,     4,    -1,    -1,   263,    -1,
      -1,    10,    11,    12,    -1,   270,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,     3,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   214,    -1,    -1,   262,   218,
      -1,    -1,    -1,    -1,    -1,   224,   225,   226,   272,   228,
     229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,   263,   264,    -1,    -1,    -1,    -1,
      -1,   270,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
     224,   225,   226,    -1,   228,   229,   230,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,
      -1,    -1,    -1,    -1,   258,     3,     4,    -1,     6,   263,
      -1,    -1,    10,    11,    12,    -1,   270,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    -1,    97,    -1,    -1,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   214,    -1,    -1,   262,
     218,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,   272,
     228,   229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,   270,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,   224,   225,   226,    -1,   228,   229,   230,    -1,    -1,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,     3,     4,    -1,    -1,
     263,    -1,    -1,    10,    11,    12,    -1,   270,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    94,    95,    -1,
      97,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    83,    84,    85,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,
     142,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,
      -1,   218,   164,    -1,    -1,    -1,    -1,   224,   225,   226,
      -1,   228,   229,   230,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     192,   193,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,   263,   264,    -1,    -1,
      -1,    -1,    -1,   270,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   272,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,
     229,   230,    -1,    -1,    -1,   234,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,
       3,     4,    -1,    -1,   263,   264,    -1,    10,    11,    12,
      -1,   270,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    94,    95,    -1,    97,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,   214,    -1,    -1,    80,   218,    82,    -1,    -1,    -1,
      -1,   224,   225,   226,    -1,   228,   229,   230,    -1,    -1,
      96,   234,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,   122,    -1,    -1,    -1,
     263,    -1,    -1,    -1,   267,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,   224,
     225,   226,    -1,   228,   229,   230,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,
      -1,    -1,    -1,   258,    13,    14,    -1,    -1,   263,   215,
     216,   217,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   231,    -1,   233,   234,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   267,   135,   136,    -1,    -1,   139,   140,    -1,   142,
     143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    13,    14,    -1,
     119,   120,   121,   122,    -1,    -1,    -1,   126,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   164,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,    -1,   139,   140,    -1,   142,   143,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   268,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    13,    14,    -1,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,   191,   192,   193,    -1,    -1,
      -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,
     143,    -1,   145,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   164,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,
     140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   268,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    13,
      14,    -1,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,   135,   136,
      -1,    -1,   139,   140,    -1,   142,   143,    -1,   145,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   164,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,   143,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   268,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    13,    14,    -1,   119,   120,
     121,   122,    -1,    -1,    -1,   126,    -1,   191,   192,   193,
      -1,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,   140,
      -1,   142,   143,    -1,   145,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   164,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,
      -1,   139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   268,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    13,    14,    -1,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
     135,   136,    -1,    -1,   139,   140,    -1,   142,   143,    -1,
     145,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   164,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     268,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,
     142,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   268,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,   191,
     192,   193,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   164,    13,    14,    -1,    -1,
      -1,    -1,    -1,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   191,   192,   193,   262,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,   272,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   268,
      -1,   118,   119,   120,   121,   122,    -1,   124,    -1,   126,
      -1,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,   190,   191,   192,   193,    -1,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,     4,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,   234,   235,    -1,
      -1,    -1,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    47,    48,    49,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,   118,   119,   120,   121,   122,    -1,   124,    -1,
     126,    -1,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,     4,     5,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,    -1,    -1,
      -1,    -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,   234,   235,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,     4,     5,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,     5,
     106,    -1,    -1,   109,    -1,   111,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   122,    -1,    -1,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,   142,    80,    -1,    82,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    96,    -1,    -1,    99,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    13,
      14,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   215,
     216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   227,    -1,    -1,    -1,   231,    -1,   233,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   215,   216,   217,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,   227,    -1,    -1,    -1,   231,    -1,
     233,   135,   136,    -1,    -1,   139,   140,    -1,   142,   143,
      -1,   145,    -1,    -1,    -1,   149,    -1,    -1,    -1,   215,
     216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   227,    -1,    -1,   168,   231,    -1,   233,    -1,    -1,
      -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   191,   192,   193,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   164,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,   193,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     272,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   272,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   272,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   272,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,   268,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,   268,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,   268,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
     268,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,   268,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,   268,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,   268,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
     268,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,   268,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,   268,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,   268,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
     268,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,   268,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,   268,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,   268,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,   268,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
     268,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   268,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,   267,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,   267,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,   267,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,   264,    -1,
     266,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,   266,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,   266,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,   266,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,   266,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   266,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,   266,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,   266,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,   266,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,   266,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
     266,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,   266,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,   266,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,   266,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,   266,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   266,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     264,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   274,   275,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    92,    93,    95,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   118,   119,   120,   121,   122,   124,   126,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   147,   148,   149,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   179,   180,   181,   185,   190,   191,
     192,   193,   196,   198,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   220,   221,
     222,   223,   232,   234,   235,   276,   278,   279,   300,   319,
     321,   325,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   343,   345,   346,   352,   353,   354,   355,   361,   386,
     387,   267,   271,    14,   109,   263,   263,   263,     6,   267,
       6,     6,     6,     6,   263,     6,   267,     6,   267,   267,
       6,     6,   265,   265,     4,   363,   387,   263,   265,   297,
     103,   106,   109,   111,   321,   297,   263,   263,   263,     4,
     263,   263,   263,     4,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   267,   125,   109,     6,     6,
     267,   267,   103,   106,   109,   122,   324,   111,   263,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    59,    60,    61,    62,    67,
      68,    77,    78,    79,    83,    84,    85,    94,    97,   103,
     106,   109,   111,   122,   123,   126,   135,   140,   142,   145,
     196,   214,   218,   219,   224,   225,   226,   228,   229,   230,
     251,   252,   258,   263,   267,   270,   321,   322,   325,   336,
     343,   345,   356,   357,   361,   363,   369,   372,   387,   263,
     267,   267,   109,   109,   135,   106,   109,   111,   321,   106,
     109,   110,   111,   122,   191,   322,   106,   109,   263,   106,
     168,   196,   212,   213,   267,   251,   252,   263,   267,   366,
     367,   366,   267,   267,   366,     4,   103,   107,   113,   114,
     116,   117,   139,   267,   366,   263,   109,   111,   109,   106,
       4,    95,   207,   267,   387,     4,     6,   103,     6,   106,
     109,   106,   109,   122,   323,     5,   263,   267,   369,   371,
     109,     4,     4,     4,   371,     4,   109,   263,   109,   263,
     263,     4,   267,   374,   387,     4,   263,   263,   263,     6,
      33,   252,   356,   387,     6,   265,     5,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    63,    64,    65,    66,
      71,    72,    73,    74,    80,    82,    96,    99,   215,   216,
     217,   227,   231,   233,   378,   387,   263,     4,   378,     5,
     267,     5,   267,   321,   356,   265,     6,   267,   263,   267,
       6,   263,   267,     6,   271,     7,   142,   207,   236,   237,
     238,   239,   260,   261,   263,   265,   269,   295,   296,   297,
     321,   356,   377,   378,   387,     4,   325,   326,   327,   267,
       6,   356,   377,   378,   387,   377,   377,   356,   377,   384,
     385,   387,   356,   327,   356,   302,   306,   263,   365,     9,
     378,   263,   378,   356,   356,   356,   263,   356,   356,   356,
     263,   356,   356,   356,   356,   356,   356,   356,   377,   356,
     356,   356,   356,   371,   263,   252,   356,   372,   373,   373,
     267,   371,   369,   377,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     263,   265,   297,   297,   297,   297,   297,   297,   263,   297,
     297,   263,   321,   322,   322,   322,   297,   297,     5,   267,
     267,   109,    68,   103,   135,   321,   321,   322,   263,   297,
     297,   263,   263,   263,   356,   267,   356,   372,   356,   356,
     268,   373,   363,   387,   199,     5,   267,     8,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   262,     9,   263,   265,
     269,   296,   297,   356,   373,   373,   263,   263,   263,   369,
     371,   371,   371,   320,   263,   267,   263,   263,   369,   267,
     267,   356,     4,   369,   267,   374,   267,   267,   366,   366,
     366,   356,   356,   251,   252,   267,   267,   366,   251,   252,
     263,   327,   366,   267,   263,   267,   263,   263,   263,   263,
     263,   263,   263,   373,   267,   356,   371,   371,   371,   263,
     267,     4,   265,   267,     6,   265,   327,     6,     6,   267,
     267,   267,   267,   371,   356,     8,     7,   267,   265,   265,
     265,     6,     6,   263,   356,   263,   356,   356,   269,   356,
     267,   199,   356,   356,   356,   297,   356,     6,   253,     9,
     263,   265,   269,   356,   297,   297,   297,   263,   263,   263,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     263,   263,   297,   263,   265,     6,     6,   267,     6,     8,
     327,     6,     8,   327,   263,   267,   377,   373,   356,   327,
     369,   369,   267,   378,   321,     7,   356,   356,     4,    26,
      37,    38,   112,   113,   196,   197,   299,   369,     6,   264,
     266,   267,   298,   267,     6,   267,     6,     9,   263,   265,
     269,   387,   268,   135,   140,   142,   143,   145,   319,   321,
     356,     6,   264,   272,     9,   263,   265,   269,   264,   272,
     264,   272,   272,   264,   272,     9,   263,   269,   272,   268,
     272,   266,   272,   301,   266,   301,    98,   364,   362,   387,
     272,   356,   272,   264,   264,   264,   356,   264,   264,   264,
     356,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   268,     7,   356,   253,   268,   272,   268,   356,
       6,     6,   264,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   372,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   372,   372,   387,   267,   356,   356,   377,   356,   377,
     369,   377,   377,   384,   267,   267,   267,   267,   356,   298,
     387,     8,   356,   356,   267,   323,   267,   371,   369,   267,
     377,   377,   372,   363,   378,   363,   373,   264,   268,   269,
     297,    68,     8,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   267,   356,   372,
     356,   356,   356,   356,   356,   387,   356,   356,   299,   267,
     298,   264,   268,   268,   356,   356,   356,     7,     7,   349,
     349,   263,   356,   356,   356,   356,     6,   172,   373,   373,
     267,   264,     6,   327,   267,   327,   327,   272,   272,   272,
     366,   366,   326,   326,   272,   356,   268,   340,   272,   327,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   268,
     326,   264,     7,   350,     6,     7,   356,   356,     6,   356,
     327,   356,   268,   373,   373,   373,   356,     6,   264,   268,
     356,   373,   356,   356,   356,   356,   264,   356,   264,   264,
     196,   272,   327,   267,     8,   264,   264,   356,   356,   387,
     299,   266,   384,   377,   384,   377,   377,   377,   377,   377,
     377,   356,   377,   377,   377,   377,   270,   380,   387,   378,
     377,   377,   377,   363,   387,   373,   268,   268,   268,   268,
     356,   327,   266,   268,   264,   149,   168,   344,   264,   268,
     272,   356,     6,   267,   369,   264,   266,   269,     7,     7,
     295,   296,     6,   373,     7,   239,   295,   356,   280,   387,
     356,   356,   299,   265,   263,   135,   321,   322,   321,   267,
     268,     6,   246,   247,   277,   373,   387,   356,   356,   299,
       6,   373,     6,   373,   356,     6,   377,   385,   387,   264,
     299,   356,   356,     6,   387,     6,   377,   356,   264,   265,
     356,   272,   378,     7,     7,     7,   264,     7,     7,     7,
     264,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   356,   264,   267,   356,   372,     6,   267,   268,     6,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   272,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   272,   272,   272,   272,   272,   264,   266,   266,
     373,   272,   272,   298,   272,   298,   272,   272,   272,   264,
     373,   356,   356,   356,   358,   298,   268,   268,   268,   356,
     267,   356,   356,   272,   272,   298,   298,   264,   269,   264,
     269,   272,   297,   359,   268,     7,   299,   298,   369,   268,
       8,     8,   373,   269,   264,   266,   263,   265,   296,   297,
     373,     7,   267,   267,   264,   264,   264,   356,   369,     4,
     348,     6,   315,   356,   378,   264,   268,   264,   264,   356,
     268,   268,   373,   269,   268,   327,   268,   268,   366,   356,
     356,   268,   268,   356,   366,   146,   146,   165,   176,   177,
     178,   182,   183,   341,   342,   366,   268,   337,   264,   268,
     264,   264,   264,   264,   264,   264,   264,   267,   268,     7,
     356,     6,   356,   264,   268,   266,   268,   266,   268,   268,
     268,   268,     6,   268,   266,   266,   272,   264,     7,   264,
       7,     7,   269,   356,   268,   356,   356,   269,   263,   265,
       7,   269,   298,   272,   298,   298,   264,   264,   272,   298,
     298,   272,   272,   298,   298,   298,   298,   356,   298,     9,
     379,   272,   264,   272,   298,   269,   272,   360,   266,   268,
     264,   268,   271,   199,     7,   168,     6,   356,   268,   267,
       6,   369,   268,   356,     6,     7,   295,   296,   269,   295,
     296,   299,   267,   375,   387,   378,   356,     6,   268,    50,
      50,   369,   268,     4,   186,   187,   188,   189,   268,   283,
     287,   290,   292,   293,   335,   269,   264,   266,   263,   356,
     356,   263,   267,   263,   267,     8,   373,   377,   264,   269,
     264,   266,   263,   264,   264,   272,   269,   263,   268,   272,
       7,   297,     4,    26,    37,    38,   309,   310,   311,   298,
     356,   298,   366,   369,   369,     7,   369,   369,   369,     7,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
       6,     7,   373,   326,   356,   356,   356,   356,   356,   356,
     268,   356,   356,   356,   369,   377,   377,   268,   268,   268,
     268,   272,   308,   268,   356,   268,   268,   356,   356,   299,
     299,   356,   356,   264,   369,   297,   356,   356,   268,   299,
     296,   269,   296,   356,   356,   298,   268,   369,   373,   373,
       7,     7,     7,   146,   347,     6,   264,   272,     7,     7,
       7,     6,     7,     7,   268,     4,   299,   268,   272,   272,
     272,   268,   268,   121,     4,     6,   356,   267,     6,   263,
       6,   184,     6,   184,   268,   342,   272,   341,     7,     6,
       7,     7,     7,     7,     7,     7,     7,   326,   369,     6,
     267,   103,     6,     6,     6,   109,     7,     7,     6,     6,
     356,     7,   369,     7,   369,   369,     4,   272,     8,     8,
     264,   299,   299,   299,   373,   377,   356,   377,   270,   272,
     312,   377,   377,   299,   377,   264,   272,     6,   267,   321,
     267,     6,   356,     6,   267,   369,   268,   268,   356,     6,
     196,   197,   299,   356,     6,     7,   374,   376,     6,   265,
       6,     6,   298,   297,   297,     6,   284,   263,   263,   267,
     294,     6,   299,   269,   377,   356,   266,   264,   356,     8,
     373,   356,   373,   268,   268,     6,     6,   277,   299,   269,
     356,     6,     6,   356,   299,   264,     6,   356,   267,   356,
     378,   298,    50,   267,   369,   378,   381,   356,   356,   356,
     266,   272,     6,   264,     6,     6,   139,   317,   317,   369,
       6,     6,     6,   369,   146,   199,   316,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   268,   268,   298,
     298,   298,   298,   298,   298,   298,   272,   272,   272,   264,
     298,   298,   310,   298,   126,   268,   199,   264,   298,   264,
     297,   359,   298,     6,   298,   263,   265,   297,   299,   264,
     266,   298,     6,   268,   268,   369,   369,   369,     4,     6,
     295,   356,   369,   369,   369,   267,   267,     7,     6,     7,
     356,   356,   356,   267,   267,   267,   265,     6,   356,   369,
     356,     6,     6,   356,   366,   268,     5,   369,   267,   267,
     267,   267,   267,   267,   267,   369,   268,     6,   373,   267,
     267,   356,   356,   266,   369,     6,   369,     6,   195,   356,
     356,   356,   263,   265,     6,     6,     7,   298,   272,   272,
     298,   272,   356,     4,   211,   313,   314,   298,   264,   298,
     360,   378,   356,   267,   327,     6,   327,   272,     6,     6,
     269,     7,     7,   295,   296,     6,   374,   268,   272,   356,
     295,   267,   298,   382,   383,   384,   382,   263,   356,   356,
     368,   369,   267,   263,     4,     6,   264,     6,   264,   268,
     268,   264,   268,     6,     6,   377,   263,     4,   264,   272,
     263,   268,   272,   369,   378,     7,   297,   307,   356,   372,
     311,     6,   366,     6,     6,     6,   146,   318,   103,   122,
     107,     6,     5,   267,     6,   356,   356,   356,   267,   109,
     356,   264,   359,   356,   356,   298,   296,   267,   267,     6,
     316,     6,   356,   369,   146,   146,     4,     6,   373,   373,
     356,   356,   378,   268,   264,   268,   272,   326,   326,   356,
     356,   268,   272,   264,   268,   272,     6,     6,   368,   366,
     366,   366,   366,   366,   252,   366,     6,   268,   373,   356,
       6,     6,     6,     6,     6,   369,   268,   272,     8,   268,
     264,   252,   267,   356,   370,   378,   377,   356,   377,   356,
     378,   381,   383,   378,   272,   264,   272,   268,   356,   344,
     344,   369,   299,   375,   378,   356,     6,     6,   374,   266,
     369,   384,     6,   298,   298,   281,   356,   272,   272,   268,
     272,   282,   356,   356,     6,     6,     6,     6,   356,   356,
     264,     6,   356,   303,   305,   267,   383,   268,   272,     7,
       7,   150,     6,   267,   267,   267,     5,   368,   298,   298,
     272,   356,   267,   298,   264,   264,   266,   373,   373,     6,
       6,   356,   356,   267,   268,   268,   267,     6,     6,   267,
     356,   268,   268,   268,   266,     6,   369,     7,   267,   356,
     268,   272,   272,   272,   272,   272,   272,     6,   268,   268,
     194,   356,   356,   267,   268,   373,     6,     6,     6,   264,
     298,   298,   314,   378,   268,   268,   268,   268,     7,     6,
       6,     6,   269,     6,   268,     6,     6,   264,   272,   356,
     356,   267,   369,   268,   272,   264,   264,   272,   268,   308,
     312,   369,   298,   356,   378,   387,   373,   373,   356,     6,
     268,   356,   272,   356,   359,   268,   268,     6,     6,   368,
     151,   152,   157,   351,   151,   152,   351,   373,   326,   268,
     272,     6,   268,   369,   327,   268,     6,   373,   366,   366,
     366,   366,   366,     6,   356,   268,   268,   373,   268,   264,
       6,   267,     6,   374,   197,   285,   356,   272,   272,   368,
       6,   356,   356,     6,   268,   268,   304,     7,   263,   268,
     268,   268,   267,   272,   356,   268,   264,   267,   268,   267,
     366,   369,     6,   267,   366,     6,   268,   268,   356,     6,
     146,   268,   338,   267,   268,   272,   272,   272,   272,   272,
       6,   268,     6,   327,     6,   267,   356,   356,   268,   272,
     308,   378,   264,   356,   356,   268,   373,     6,   366,     6,
     366,     6,     6,   268,   356,   341,   327,     6,   373,   373,
     373,   373,   366,   373,   344,   282,   264,   272,     6,   267,
     356,   268,   272,   272,   268,   272,   272,     6,   268,   268,
     339,   268,   268,   268,   268,   272,   268,   268,   268,   288,
     356,   368,   268,   356,   356,   366,   366,   341,     6,     6,
       6,     6,   373,     6,     6,     6,   267,   264,   268,     6,
     268,   298,   272,   272,   268,   268,   286,   377,   291,   267,
       6,   356,   356,     6,   268,   272,   267,   368,   268,   268,
       6,   377,   289,   377,   268,     6,     6,   268,   272,     6,
       6,   377
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
      std::vector<std::pair<int, int> > dimTags, outDimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      (yyval.l) = (yyvsp[(4) - (5)].l);
      List_Reset((yyval.l));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        int dim, tag;
        double dist, x, y, z;
        r = GModel::current()->getOCCInternals()->getClosestEntity
          ((yyvsp[(2) - (5)].v)[0], (yyvsp[(2) - (5)].v)[1], (yyvsp[(2) - (5)].v)[2], dimTags, dim, tag, dist, x, y, z);
        if(r) outDimTags.push_back(std::make_pair(dim, tag));
      }
      else{
        yymsg(0, "Closest entity only available with OpenCASCADE geometry kernel");
      }
      if(!r) yymsg(0, "Closest entity search failed");
      VectorOfPairs2ListOfShapes(outDimTags, (yyval.l));
    ;}
    break;

  case 230:
#line 2582 "Gmsh.y"
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
#line 2624 "Gmsh.y"
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
#line 2645 "Gmsh.y"
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
#line 2666 "Gmsh.y"
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
#line 2691 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 235:
#line 2692 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 236:
#line 2697 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 237:
#line 2701 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 238:
#line 2705 "Gmsh.y"
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
#line 2722 "Gmsh.y"
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
#line 2742 "Gmsh.y"
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
#line 2762 "Gmsh.y"
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
#line 2781 "Gmsh.y"
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
#line 2808 "Gmsh.y"
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
#line 2827 "Gmsh.y"
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
#line 2849 "Gmsh.y"
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
#line 2864 "Gmsh.y"
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
#line 2879 "Gmsh.y"
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
#line 2898 "Gmsh.y"
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
#line 2949 "Gmsh.y"
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
#line 2970 "Gmsh.y"
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
#line 2992 "Gmsh.y"
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
#line 3014 "Gmsh.y"
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
#line 3119 "Gmsh.y"
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
#line 3135 "Gmsh.y"
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
#line 3170 "Gmsh.y"
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
#line 3195 "Gmsh.y"
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
#line 3220 "Gmsh.y"
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
#line 3232 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 259:
#line 3238 "Gmsh.y"
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
#line 3253 "Gmsh.y"
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
#line 3284 "Gmsh.y"
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
#line 3296 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 263:
#line 3305 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 264:
#line 3312 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 265:
#line 3324 "Gmsh.y"
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
#line 3344 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 267:
#line 3348 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 268:
#line 3353 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 269:
#line 3357 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 270:
#line 3362 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 271:
#line 3369 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 272:
#line 3376 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 273:
#line 3383 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 274:
#line 3395 "Gmsh.y"
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
#line 3468 "Gmsh.y"
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
#line 3486 "Gmsh.y"
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
#line 3511 "Gmsh.y"
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
#line 3526 "Gmsh.y"
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
#line 3575 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 280:
#line 3581 "Gmsh.y"
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
#line 3593 "Gmsh.y"
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
#line 3625 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 283:
#line 3629 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 284:
#line 3633 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 285:
#line 3638 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 286:
#line 3645 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 287:
#line 3650 "Gmsh.y"
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
#line 3660 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 289:
#line 3665 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 290:
#line 3671 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 291:
#line 3679 "Gmsh.y"
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
#line 3690 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 293:
#line 3698 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 294:
#line 3702 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 295:
#line 3706 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 296:
#line 3710 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 297:
#line 3717 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 298:
#line 3721 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 299:
#line 3725 "Gmsh.y"
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
#line 3737 "Gmsh.y"
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
#line 3747 "Gmsh.y"
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
#line 3805 "Gmsh.y"
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
#line 3825 "Gmsh.y"
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
#line 3851 "Gmsh.y"
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
#line 3867 "Gmsh.y"
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
#line 3884 "Gmsh.y"
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
#line 3901 "Gmsh.y"
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
#line 3923 "Gmsh.y"
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
#line 3945 "Gmsh.y"
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
#line 3980 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 311:
#line 3988 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 312:
#line 3996 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 313:
#line 4002 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 314:
#line 4009 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 315:
#line 4016 "Gmsh.y"
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
#line 4036 "Gmsh.y"
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
#line 4062 "Gmsh.y"
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
#line 4074 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 319:
#line 4085 "Gmsh.y"
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
#line 4103 "Gmsh.y"
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
#line 4121 "Gmsh.y"
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
#line 4139 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4145 "Gmsh.y"
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
#line 4163 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4169 "Gmsh.y"
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
#line 4189 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 327:
#line 4195 "Gmsh.y"
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
#line 4213 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 329:
#line 4219 "Gmsh.y"
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
#line 4236 "Gmsh.y"
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
#line 4252 "Gmsh.y"
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
#line 4269 "Gmsh.y"
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
#line 4287 "Gmsh.y"
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
#line 4310 "Gmsh.y"
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
#line 4337 "Gmsh.y"
    {
    ;}
    break;

  case 336:
#line 4340 "Gmsh.y"
    {
    ;}
    break;

  case 337:
#line 4346 "Gmsh.y"
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
#line 4358 "Gmsh.y"
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
#line 4378 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 340:
#line 4382 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 341:
#line 4386 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 342:
#line 4390 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 343:
#line 4394 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 344:
#line 4398 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 345:
#line 4402 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 346:
#line 4406 "Gmsh.y"
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
#line 4415 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 348:
#line 4427 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 349:
#line 4428 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 350:
#line 4429 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 351:
#line 4430 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 352:
#line 4431 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 353:
#line 4435 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 354:
#line 4436 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 355:
#line 4437 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 356:
#line 4438 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 357:
#line 4439 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 358:
#line 4444 "Gmsh.y"
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
#line 4467 "Gmsh.y"
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
#line 4487 "Gmsh.y"
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
#line 4508 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 362:
#line 4512 "Gmsh.y"
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
#line 4539 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 364:
#line 4543 "Gmsh.y"
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
#line 4559 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 366:
#line 4563 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 367:
#line 4568 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 368:
#line 4572 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 369:
#line 4578 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 370:
#line 4582 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 371:
#line 4589 "Gmsh.y"
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
#line 4612 "Gmsh.y"
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
#line 4631 "Gmsh.y"
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
#line 4672 "Gmsh.y"
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

  case 375:
#line 4716 "Gmsh.y"
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

  case 376:
#line 4755 "Gmsh.y"
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
#line 4780 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 378:
#line 4787 "Gmsh.y"
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
#line 4798 "Gmsh.y"
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
#line 4815 "Gmsh.y"
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
#line 4832 "Gmsh.y"
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
#line 4862 "Gmsh.y"
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
#line 4888 "Gmsh.y"
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
#line 4915 "Gmsh.y"
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
#line 4947 "Gmsh.y"
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
#line 4975 "Gmsh.y"
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
#line 5001 "Gmsh.y"
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
#line 5027 "Gmsh.y"
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
#line 5053 "Gmsh.y"
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
#line 5079 "Gmsh.y"
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
#line 5100 "Gmsh.y"
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
#line 5112 "Gmsh.y"
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
#line 5160 "Gmsh.y"
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
#line 5214 "Gmsh.y"
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
#line 5229 "Gmsh.y"
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
#line 5241 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 397:
#line 5247 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 398:
#line 5259 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 399:
#line 5266 "Gmsh.y"
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
#line 5281 "Gmsh.y"
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
#line 5290 "Gmsh.y"
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
#line 5310 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 403:
#line 5311 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 404:
#line 5312 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 405:
#line 5317 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 406:
#line 5323 "Gmsh.y"
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
#line 5335 "Gmsh.y"
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
#line 5353 "Gmsh.y"
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
#line 5380 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 410:
#line 5381 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 411:
#line 5382 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 412:
#line 5383 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 413:
#line 5384 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 414:
#line 5385 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5386 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5387 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 417:
#line 5389 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 418:
#line 5395 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 419:
#line 5396 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 420:
#line 5397 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 421:
#line 5398 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 422:
#line 5399 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 423:
#line 5400 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 424:
#line 5401 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5402 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5403 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5404 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 428:
#line 5405 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 429:
#line 5406 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 430:
#line 5407 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 431:
#line 5408 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 432:
#line 5409 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 433:
#line 5410 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 434:
#line 5411 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5412 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 436:
#line 5413 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 437:
#line 5414 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5415 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 439:
#line 5416 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5417 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 441:
#line 5418 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5419 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 443:
#line 5420 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5421 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 445:
#line 5422 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 446:
#line 5423 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 447:
#line 5424 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 448:
#line 5425 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 449:
#line 5426 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 450:
#line 5427 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 451:
#line 5428 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 452:
#line 5429 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 453:
#line 5430 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 454:
#line 5431 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 455:
#line 5432 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 456:
#line 5433 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 457:
#line 5434 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 458:
#line 5435 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 459:
#line 5444 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 460:
#line 5445 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 461:
#line 5446 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 462:
#line 5447 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 463:
#line 5448 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 464:
#line 5449 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 465:
#line 5450 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 466:
#line 5451 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 467:
#line 5452 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 468:
#line 5453 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 469:
#line 5454 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 470:
#line 5459 "Gmsh.y"
    { init_options(); ;}
    break;

  case 471:
#line 5461 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 472:
#line 5467 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 473:
#line 5471 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 474:
#line 5476 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 475:
#line 5481 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 476:
#line 5486 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 477:
#line 5491 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 478:
#line 5495 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 479:
#line 5499 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 480:
#line 5503 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 481:
#line 5507 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 482:
#line 5511 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 483:
#line 5515 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 484:
#line 5519 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 485:
#line 5525 "Gmsh.y"
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
#line 5540 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 487:
#line 5544 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 488:
#line 5550 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 489:
#line 5555 "Gmsh.y"
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
#line 5574 "Gmsh.y"
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
#line 5594 "Gmsh.y"
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
#line 5615 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 493:
#line 5619 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 494:
#line 5623 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 495:
#line 5627 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 496:
#line 5631 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 497:
#line 5635 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 498:
#line 5639 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 499:
#line 5644 "Gmsh.y"
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
#line 5654 "Gmsh.y"
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
#line 5664 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 502:
#line 5669 "Gmsh.y"
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
#line 5680 "Gmsh.y"
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
#line 5689 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 505:
#line 5694 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 506:
#line 5699 "Gmsh.y"
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
#line 5726 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 508:
#line 5728 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 509:
#line 5733 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 510:
#line 5735 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 511:
#line 5740 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 512:
#line 5747 "Gmsh.y"
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
#line 5763 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 514:
#line 5765 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 515:
#line 5770 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 516:
#line 5772 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 517:
#line 5777 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 518:
#line 5779 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 519:
#line 5784 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 520:
#line 5788 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 521:
#line 5792 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 522:
#line 5796 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 523:
#line 5800 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 524:
#line 5807 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 525:
#line 5811 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 526:
#line 5815 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 527:
#line 5819 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 528:
#line 5826 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 529:
#line 5831 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 530:
#line 5838 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 531:
#line 5843 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 532:
#line 5847 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 533:
#line 5851 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 534:
#line 5855 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 535:
#line 5863 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 536:
#line 5874 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 537:
#line 5878 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 538:
#line 5882 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 539:
#line 5893 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 540:
#line 5897 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 541:
#line 5901 "Gmsh.y"
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
#line 5915 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 543:
#line 5923 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 544:
#line 5931 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 545:
#line 5938 "Gmsh.y"
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
#line 5948 "Gmsh.y"
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
#line 5971 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 548:
#line 5976 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 549:
#line 5982 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 550:
#line 5987 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 551:
#line 5993 "Gmsh.y"
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
#line 6004 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 553:
#line 6010 "Gmsh.y"
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
#line 6024 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 555:
#line 6030 "Gmsh.y"
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
#line 6042 "Gmsh.y"
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
#line 6056 "Gmsh.y"
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
#line 6069 "Gmsh.y"
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
#line 6099 "Gmsh.y"
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
#line 6121 "Gmsh.y"
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

  case 561:
#line 6141 "Gmsh.y"
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
#line 6158 "Gmsh.y"
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
#line 6168 "Gmsh.y"
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
#line 6178 "Gmsh.y"
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
#line 6188 "Gmsh.y"
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
#line 6200 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 567:
#line 6204 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 568:
#line 6209 "Gmsh.y"
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
#line 6221 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 570:
#line 6225 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 571:
#line 6229 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 572:
#line 6233 "Gmsh.y"
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
#line 6251 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 574:
#line 6259 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 575:
#line 6267 "Gmsh.y"
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
#line 6296 "Gmsh.y"
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
#line 6306 "Gmsh.y"
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
#line 6322 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 579:
#line 6333 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 580:
#line 6338 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 581:
#line 6342 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 582:
#line 6346 "Gmsh.y"
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
#line 6358 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 584:
#line 6362 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 585:
#line 6374 "Gmsh.y"
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

  case 586:
#line 6391 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 587:
#line 6401 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 588:
#line 6405 "Gmsh.y"
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

  case 589:
#line 6420 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 590:
#line 6425 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 591:
#line 6432 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 592:
#line 6436 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 593:
#line 6441 "Gmsh.y"
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

  case 594:
#line 6455 "Gmsh.y"
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

  case 595:
#line 6469 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 596:
#line 6473 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 597:
#line 6477 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 598:
#line 6481 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 599:
#line 6485 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 600:
#line 6493 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 601:
#line 6499 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 602:
#line 6508 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 603:
#line 6512 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 604:
#line 6516 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 605:
#line 6524 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 606:
#line 6530 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 607:
#line 6536 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 608:
#line 6540 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6547 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 610:
#line 6555 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6562 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 612:
#line 6571 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 613:
#line 6575 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 614:
#line 6579 "Gmsh.y"
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

  case 615:
#line 6594 "Gmsh.y"
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

  case 616:
#line 6608 "Gmsh.y"
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

  case 617:
#line 6622 "Gmsh.y"
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

  case 618:
#line 6634 "Gmsh.y"
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

  case 619:
#line 6650 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 620:
#line 6659 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 621:
#line 6668 "Gmsh.y"
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

  case 622:
#line 6678 "Gmsh.y"
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

  case 623:
#line 6689 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 624:
#line 6697 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 625:
#line 6705 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 626:
#line 6709 "Gmsh.y"
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

  case 627:
#line 6727 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 628:
#line 6734 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 629:
#line 6740 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 630:
#line 6746 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 631:
#line 6753 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 632:
#line 6760 "Gmsh.y"
    { init_options(); ;}
    break;

  case 633:
#line 6762 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 634:
#line 6770 "Gmsh.y"
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

  case 635:
#line 6794 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 636:
#line 6796 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 637:
#line 6802 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 638:
#line 6807 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 639:
#line 6809 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 640:
#line 6814 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 641:
#line 6819 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 642:
#line 6824 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 643:
#line 6826 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 644:
#line 6830 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 645:
#line 6842 "Gmsh.y"
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

  case 646:
#line 6856 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 647:
#line 6860 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 648:
#line 6867 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 649:
#line 6875 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 650:
#line 6883 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 651:
#line 6894 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 652:
#line 6896 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 653:
#line 6899 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15368 "Gmsh.tab.cpp"
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


#line 6902 "Gmsh.y"


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

