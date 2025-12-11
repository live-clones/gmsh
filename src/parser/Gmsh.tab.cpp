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
#define YYLAST   18368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  273
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  653
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2344

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
    3023,  3034,  3040,  3042,  3044,  3046,  3050,  3056,  3064,  3069,
    3074,  3079,  3086,  3093,  3102,  3111,  3116,  3131,  3136,  3141,
    3143,  3145,  3149,  3153,  3163,  3171,  3173,  3179,  3183,  3190,
    3192,  3196,  3198,  3200,  3205,  3210,  3214,  3220,  3227,  3236,
    3243,  3248,  3254,  3256,  3261,  3263,  3265,  3267,  3269,  3274,
    3281,  3286,  3293,  3299,  3307,  3312,  3317,  3322,  3331,  3336,
    3341,  3346,  3351,  3360,  3369,  3376,  3381,  3388,  3393,  3395,
    3397,  3402,  3407,  3408,  3415,  3420,  3423,  3428,  3433,  3435,
    3437,  3441,  3443,  3445,  3449,  3453,  3457,  3463,  3471,  3477,
    3483,  3492,  3494,  3496
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
     267,   373,   268,   267,   326,   268,    -1,   158,   267,   373,
     268,   267,   326,   268,    -1,     4,   267,   326,   268,    -1,
     171,   106,   267,   373,   268,   109,   267,   356,   268,    -1,
     167,   106,   267,   356,   268,   103,   267,   373,   268,     6,
      -1,   167,   106,   263,   356,   264,   267,   373,   268,     6,
      -1,   327,    -1,   325,    -1,    -1,   327,   319,    -1,   327,
     321,   267,   373,   268,     6,    -1,   327,   142,   321,   267,
     373,   268,     6,    -1,   327,   145,   321,   267,   373,   268,
       6,    -1,   327,   321,   267,     8,   268,     6,    -1,   327,
     142,   321,   267,     8,   268,     6,    -1,   156,   139,   263,
     356,   264,     7,   369,     6,    -1,   156,   103,   263,   356,
     264,     7,   267,   368,   268,     6,    -1,   156,   139,   263,
     356,   264,     7,   267,   366,   272,   366,   272,   373,   268,
       6,    -1,   156,   139,   263,   356,   264,     7,   267,   366,
     272,   366,   272,   366,   272,   373,   268,     6,    -1,   156,
     107,   263,   356,   264,     7,   267,   366,   272,   373,   268,
       6,    -1,   156,   113,   263,   356,   264,     7,   267,   366,
     272,   366,   272,   373,   268,     6,    -1,   156,   114,   263,
     356,   264,     7,   267,   366,   272,   366,   272,   373,   268,
       6,    -1,   156,   116,   263,   356,   264,     7,   267,   366,
     272,   366,   272,   373,   268,     6,    -1,   156,   117,   263,
     356,   264,     7,   267,   366,   272,   366,   272,   373,   268,
       6,    -1,   156,     4,   263,   356,   264,     7,   369,     6,
      -1,   156,     4,   263,   356,   264,     7,     5,     6,    -1,
     156,     4,   267,   356,   268,     6,    -1,   168,   267,   327,
     268,    -1,   149,   168,   267,   327,   268,    -1,   168,     4,
     267,   327,   268,    -1,   168,   207,   265,   356,   266,     6,
      -1,   168,     4,   265,   356,   266,     6,    -1,   168,   387,
       6,    -1,   168,     4,     4,     6,    -1,   168,    95,     6,
      -1,   196,   374,   267,   327,   268,    -1,   149,   196,   374,
     267,   327,   268,    -1,   232,   356,   267,   327,   268,    -1,
     212,   267,     8,   268,    -1,   212,     5,     6,    -1,   213,
     267,     8,   268,    -1,   213,     5,     6,    -1,   212,   267,
     327,   268,    -1,   149,   212,   267,   327,   268,    -1,   213,
     267,   327,   268,    -1,   149,   213,   267,   327,   268,    -1,
     387,   378,     6,    -1,    81,   263,   384,   264,     6,    -1,
     387,   387,   265,   356,   266,   377,     6,    -1,   387,   387,
     387,   265,   356,   266,     6,    -1,   387,   356,     6,    -1,
     235,     6,    -1,   147,   263,     4,   264,   269,     4,     6,
      -1,   190,     4,     6,    -1,   205,     6,    -1,   205,   356,
       6,    -1,   206,     6,    -1,    75,     6,    -1,    76,     6,
      -1,    68,     6,    -1,    68,   267,   356,   272,   356,   272,
     356,   272,   356,   272,   356,   272,   356,   268,     6,    -1,
      69,     6,    -1,    70,     6,    -1,    86,   267,   356,   272,
     356,   268,     6,    -1,    86,     6,    -1,    88,   267,   356,
     272,   356,   272,   356,   268,     6,    -1,    88,   267,   356,
     272,   356,   272,   356,   272,   356,   268,     6,    -1,    87,
       6,    -1,    87,   267,   327,   268,    -1,    89,     6,    -1,
      90,     6,    -1,   128,     6,    -1,   129,     6,    -1,   130,
     267,   373,   268,   267,   373,   268,   267,   368,   268,   267,
     356,   272,   356,   268,     6,    -1,   131,   267,   373,   268,
       6,    -1,   131,   267,   373,   268,   267,   326,   268,     6,
      -1,   210,   263,   267,   373,   268,   272,   378,   272,   378,
     264,     6,    -1,   198,   263,   356,     8,   356,   264,    -1,
     198,   263,   356,     8,   356,     8,   356,   264,    -1,   198,
       4,   199,   267,   356,     8,   356,   268,    -1,   198,     4,
     199,   267,   356,     8,   356,     8,   356,   268,    -1,   200,
      -1,   211,     4,    -1,   211,   378,    -1,   208,    -1,   209,
     387,     6,    -1,   209,   378,     6,    -1,   201,   263,   356,
     264,    -1,   202,   263,   356,   264,    -1,   203,    -1,   204,
      -1,   155,   366,   267,   327,   268,    -1,   155,   267,   366,
     272,   366,   272,   356,   268,   267,   327,   268,    -1,   155,
     267,   366,   272,   366,   272,   366,   272,   356,   268,   267,
     327,   268,    -1,    -1,   155,   366,   267,   327,   337,   341,
     268,    -1,    -1,   155,   267,   366,   272,   366,   272,   356,
     268,   267,   327,   338,   341,   268,    -1,    -1,   155,   267,
     366,   272,   366,   272,   366,   272,   356,   268,   267,   327,
     339,   341,   268,    -1,    -1,   155,   267,   327,   340,   341,
     268,    -1,   155,   267,   327,   268,   146,   121,   267,   356,
     268,    -1,   135,   369,    -1,   140,   135,   369,    -1,   137,
     267,   373,   268,   267,   373,   268,   267,   373,   268,    -1,
     138,   267,   373,   268,   267,   373,   268,   267,   373,   268,
     267,   373,   268,    -1,   342,    -1,   341,   342,    -1,   176,
     267,   356,   268,     6,    -1,   176,   267,   369,   272,   369,
     268,     6,    -1,   177,     6,    -1,   165,     6,    -1,   165,
     356,     6,    -1,   182,     6,    -1,   182,   184,     6,    -1,
     183,     6,    -1,   183,   184,     6,    -1,   178,   263,   356,
     264,     7,   369,   146,   356,     6,    -1,   146,     4,   265,
     356,   266,     6,    -1,   159,    -1,   160,    -1,   161,    -1,
     162,    -1,   163,    -1,    -1,   168,     6,    -1,   149,   168,
       6,    -1,   168,   356,     6,    -1,   149,   168,   356,     6,
      -1,   343,   267,   327,   344,   268,   267,   327,   344,   268,
      -1,   118,   263,   377,   264,    -1,   343,   263,   356,   264,
       7,   267,   327,   344,   268,   267,   327,   344,   268,     6,
      -1,    -1,   146,     4,   356,    -1,    -1,     4,    -1,    -1,
       7,   369,    -1,    -1,     7,   356,    -1,    -1,   157,   369,
      -1,   174,   371,     7,   356,     6,    -1,   124,   125,   371,
       7,   356,     6,    -1,   141,   106,   371,     7,   356,   347,
       6,    -1,   141,   109,   371,   349,   348,     6,    -1,   141,
     111,   371,   349,     6,    -1,   185,   371,     6,    -1,   101,
     321,   263,   356,   272,   356,   264,     6,    -1,   220,   321,
     263,   356,   264,     6,    -1,   172,   109,   267,   373,   268,
       7,   356,     6,    -1,   175,   109,   267,   373,   268,     7,
     356,     6,    -1,   165,   109,   371,   350,     6,    -1,   165,
     111,   371,     6,    -1,   166,   109,   371,     7,   356,     6,
      -1,   144,   106,   267,   373,   268,     7,   267,   373,   268,
     351,     6,    -1,   144,   109,   267,   373,   268,     7,   267,
     373,   268,   351,     6,    -1,   144,   106,   267,   373,   268,
       7,   267,   373,   268,   151,   267,   366,   272,   366,   272,
     356,   268,     6,    -1,   144,   109,   267,   373,   268,     7,
     267,   373,   268,   151,   267,   366,   272,   366,   272,   356,
     268,     6,    -1,   144,   106,   267,   373,   268,     7,   267,
     373,   268,   152,   366,     6,    -1,   144,   109,   267,   373,
     268,     7,   267,   373,   268,   152,   366,     6,    -1,   144,
     109,   356,   267,   373,   268,     7,   356,   267,   373,   268,
       6,    -1,   321,   267,   373,   268,   199,   321,   267,   356,
     268,     6,    -1,   173,   323,   371,     6,    -1,   132,   324,
     371,     6,    -1,   133,   111,   369,     6,    -1,   148,   106,
     369,     6,    -1,   143,   322,   369,     6,    -1,   143,   322,
     369,   172,   356,     6,    -1,   169,     6,    -1,   169,     4,
       6,    -1,   169,   103,   267,   373,   268,     6,    -1,   170,
       6,    -1,   221,    -1,   222,    -1,   223,    -1,   354,     6,
      -1,   354,   267,   369,   268,     6,    -1,   354,   267,   369,
     272,   369,   268,     6,    -1,   354,   263,   369,   264,   267,
     369,   272,   369,   268,     6,    -1,   357,    -1,   263,   356,
     264,    -1,   252,   356,    -1,   251,   356,    -1,   258,   356,
      -1,   356,   252,   356,    -1,   356,   251,   356,    -1,   356,
     253,   356,    -1,   356,   254,   356,    -1,   356,   256,   356,
      -1,   356,   257,   356,    -1,   356,   255,   356,    -1,   356,
     262,   356,    -1,   356,   245,   356,    -1,   356,   246,   356,
      -1,   356,   250,   356,    -1,   356,   249,   356,    -1,   356,
     244,   356,    -1,   356,   243,   356,    -1,   356,   242,   356,
      -1,   356,   241,   356,    -1,   356,   247,   356,    -1,   356,
     248,   356,    -1,   356,   240,   356,     8,   356,    -1,    26,
     297,   356,   298,    -1,    16,   297,   356,   298,    -1,    17,
     297,   356,   298,    -1,    18,   297,   356,   298,    -1,    19,
     297,   356,   298,    -1,    20,   297,   356,   298,    -1,    21,
     297,   356,   298,    -1,    22,   297,   356,   298,    -1,    23,
     297,   356,   298,    -1,    24,   297,   356,   298,    -1,    27,
     297,   356,   298,    -1,    28,   297,   356,   272,   356,   298,
      -1,    29,   297,   356,   298,    -1,    30,   297,   356,   298,
      -1,    31,   297,   356,   298,    -1,    32,   297,   356,   298,
      -1,    33,   297,   356,   298,    -1,    34,   297,   356,   298,
      -1,    35,   297,   356,   298,    -1,    36,   297,   356,   298,
      -1,    39,   297,   356,   272,   356,   298,    -1,    40,   297,
     356,   272,   356,   298,    -1,    41,   297,   356,   272,   356,
     298,    -1,    25,   297,   356,   298,    -1,    38,   297,   356,
     272,   356,   298,    -1,    37,   297,   356,   272,   356,   298,
      -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,    12,
      -1,   228,    -1,   229,    -1,   230,    -1,    83,    -1,    84,
      -1,    85,    -1,    -1,    94,   297,   356,   358,   308,   298,
      -1,   361,    -1,   218,   297,   377,   298,    -1,   218,   297,
     377,   272,   356,   298,    -1,   363,    -1,   387,   265,   356,
     266,    -1,   387,   263,   356,   264,    -1,   224,   263,   363,
     264,    -1,   224,   263,   363,   269,   299,   264,    -1,   226,
     263,   363,   359,   264,    -1,   226,   263,   363,   269,   299,
     359,   264,    -1,   226,   263,   363,   297,   356,   298,   359,
     264,    -1,   226,   263,   363,   269,   299,   297,   356,   298,
     359,   264,    -1,   225,   263,   378,   264,    -1,   270,   387,
     297,   298,    -1,   270,   363,   269,   299,   297,   298,    -1,
      97,   297,   387,   298,    -1,    97,   297,   298,    -1,   387,
     296,    -1,   387,   265,   356,   266,   296,    -1,   387,   263,
     356,   264,   296,    -1,   387,   269,   299,    -1,   387,     9,
     387,   269,   299,    -1,   387,   269,   299,   263,   356,   264,
      -1,   387,     9,   387,   269,   299,   263,   356,   264,    -1,
     387,   269,   299,   265,   356,   266,    -1,   387,     9,   387,
     269,   299,   265,   356,   266,    -1,   387,   265,   356,   266,
     269,   299,    -1,   387,   269,   299,   296,    -1,   387,   265,
     356,   266,   269,   299,   296,    -1,   214,   263,   377,   272,
     356,   264,    -1,    60,   263,   369,   272,   369,   264,    -1,
      61,   297,   377,   272,   377,   298,    -1,    59,   297,   377,
     298,    -1,    62,   297,   377,   272,   377,   298,    -1,    67,
     263,   384,   264,    -1,    -1,   272,   356,    -1,    -1,   272,
     377,    -1,    -1,    95,   363,   365,   362,   265,   309,   266,
      -1,   387,    -1,   387,     9,   387,    -1,    98,    -1,    98,
     356,    -1,    -1,   263,   364,   264,    -1,   367,    -1,   252,
     366,    -1,   251,   366,    -1,   366,   252,   366,    -1,   366,
     251,   366,    -1,   267,   356,   272,   356,   272,   356,   272,
     356,   272,   356,   268,    -1,   267,   356,   272,   356,   272,
     356,   272,   356,   268,    -1,   267,   356,   272,   356,   272,
     356,   268,    -1,   263,   356,   272,   356,   272,   356,   264,
      -1,   369,    -1,   368,   272,   369,    -1,   356,    -1,   372,
      -1,   267,   268,    -1,   267,   373,   268,    -1,   252,   267,
     373,   268,    -1,   356,   253,   267,   373,   268,    -1,   267,
     268,    -1,   267,   373,   268,    -1,   252,   267,   373,   268,
      -1,   369,    -1,   267,     8,   268,    -1,     5,    -1,   252,
     372,    -1,   356,   253,   372,    -1,   356,     8,   356,    -1,
     356,     8,   356,     8,   356,    -1,   103,   267,   356,   268,
      -1,   103,   267,     8,   268,    -1,   103,     5,    -1,   322,
     267,     8,   268,    -1,   322,     5,    -1,   142,   321,   371,
      -1,   145,   321,   369,    -1,   321,   199,    68,   369,    -1,
      68,   321,   267,   373,   268,    -1,    77,   322,   267,   356,
     268,    -1,    78,   322,   267,   356,   268,    -1,    79,   322,
     267,   356,   268,    -1,   126,    68,   323,   267,   356,   268,
      -1,   123,   109,   267,   356,   268,   126,   267,   356,   272,
     356,   268,    -1,   126,   103,   267,   356,   268,   199,   109,
     267,   356,   268,    -1,   196,   322,   267,   356,   268,    -1,
     325,    -1,   336,    -1,   345,    -1,   387,   297,   298,    -1,
     387,   269,   299,   297,   298,    -1,   387,     9,   387,   269,
     299,   297,   298,    -1,    42,   265,   387,   266,    -1,    42,
     265,   372,   266,    -1,    42,   263,   372,   264,    -1,    42,
     297,   267,   373,   268,   298,    -1,   387,   297,   267,   373,
     268,   298,    -1,    43,   297,   356,   272,   356,   272,   356,
     298,    -1,    44,   297,   356,   272,   356,   272,   356,   298,
      -1,    45,   297,   377,   298,    -1,    46,   297,   356,   272,
     356,   272,   356,   272,   356,   272,   356,   272,   356,   298,
      -1,   219,   297,   372,   298,    -1,    33,   297,   372,   298,
      -1,   356,    -1,   372,    -1,   373,   272,   356,    -1,   373,
     272,   372,    -1,   267,   356,   272,   356,   272,   356,   272,
     356,   268,    -1,   267,   356,   272,   356,   272,   356,   268,
      -1,   387,    -1,     4,   269,   196,   269,     4,    -1,   267,
     376,   268,    -1,   387,   265,   356,   266,   269,   197,    -1,
     374,    -1,   376,   272,   374,    -1,   378,    -1,   387,    -1,
     387,   265,   356,   266,    -1,   387,   263,   356,   264,    -1,
     387,   269,   299,    -1,   387,     9,   387,   269,   299,    -1,
     387,   269,   299,   263,   356,   264,    -1,   387,     9,   387,
     269,   299,   263,   356,   264,    -1,   387,   265,   356,   266,
     269,     4,    -1,   321,   267,   356,   268,    -1,   142,   321,
     267,   356,   268,    -1,     5,    -1,   233,   265,   387,   266,
      -1,    71,    -1,   231,    -1,    80,    -1,    82,    -1,   216,
     263,   377,   264,    -1,   215,   263,   377,   272,   377,   264,
      -1,   217,   297,   377,   298,    -1,   217,   297,   377,   272,
     377,   298,    -1,   227,   263,   363,   360,   264,    -1,   227,
     263,   363,   269,   299,   360,   264,    -1,    52,   297,   384,
     298,    -1,    53,   263,   377,   264,    -1,    54,   263,   377,
     264,    -1,    55,   263,   377,   272,   377,   272,   377,   264,
      -1,    50,   297,   384,   298,    -1,    64,   297,   377,   298,
      -1,    65,   297,   377,   298,    -1,    66,   297,   377,   298,
      -1,    63,   297,   356,   272,   377,   272,   377,   298,    -1,
      58,   297,   377,   272,   356,   272,   356,   298,    -1,    58,
     297,   377,   272,   356,   298,    -1,    51,   297,   377,   298,
      -1,    51,   297,   377,   272,   373,   298,    -1,    72,   297,
     377,   298,    -1,    73,    -1,    74,    -1,    57,   297,   377,
     298,    -1,    56,   297,   377,   298,    -1,    -1,    99,   297,
     378,   379,   312,   298,    -1,    96,   297,   380,   298,    -1,
     270,   356,    -1,   387,     9,   270,   356,    -1,    50,   297,
     383,   298,    -1,   384,    -1,   383,    -1,   267,   384,   268,
      -1,   377,    -1,   385,    -1,   384,   272,   377,    -1,   384,
     272,   385,    -1,   387,   263,   264,    -1,   387,   269,   299,
     263,   264,    -1,   387,     9,   387,   269,   299,   263,   264,
      -1,     4,   271,   267,   356,   268,    -1,   386,   271,   267,
     356,   268,    -1,   234,   265,   377,   266,   271,   267,   356,
     268,    -1,     4,    -1,   386,    -1,   234,   265,   377,   266,
      -1
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
    6128,  6148,  6165,  6175,  6185,  6195,  6207,  6211,  6216,  6228,
    6232,  6236,  6240,  6258,  6266,  6274,  6303,  6313,  6329,  6340,
    6345,  6349,  6353,  6365,  6369,  6381,  6398,  6408,  6412,  6427,
    6432,  6439,  6443,  6448,  6462,  6476,  6480,  6484,  6488,  6492,
    6500,  6506,  6515,  6519,  6523,  6531,  6537,  6543,  6547,  6554,
    6562,  6569,  6578,  6582,  6586,  6601,  6615,  6629,  6641,  6657,
    6666,  6675,  6685,  6696,  6704,  6712,  6716,  6734,  6741,  6747,
    6753,  6760,  6768,  6767,  6777,  6801,  6803,  6809,  6814,  6816,
    6821,  6826,  6831,  6833,  6837,  6849,  6863,  6867,  6874,  6882,
    6890,  6901,  6903,  6906
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
       0,     0,     0,     0,     0,     0,   367,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   236,   236,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     383,     0,     0,   259,   258,   400,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,   586,     0,     0,
       0,   305,   493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   509,   510,   612,     0,   378,     0,
       0,   236,   355,     0,   356,   236,     0,     0,   601,     0,
      95,     0,     0,     0,     0,    93,     0,   589,     0,   108,
       0,   100,   102,     0,     0,     0,    90,     0,     0,     0,
       0,     0,    36,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   596,
       0,     0,    34,    33,     0,   596,   646,   291,     0,     0,
     122,   127,     0,     0,     0,   141,   147,   148,   144,   142,
     143,   512,     0,    86,     0,    87,   169,     0,     0,     0,
       0,   170,   189,   190,   167,     0,     0,     0,   171,   200,
     191,   195,   196,   192,   193,   194,   179,     0,     0,     0,
     444,   458,   457,   453,   454,   455,   571,     0,     0,     0,
     502,   503,   505,   136,   471,     0,   558,     0,   501,   474,
     479,     0,     0,   507,   201,   486,    73,    74,     0,   498,
     494,   496,   572,   197,     0,     0,     0,   161,     0,     0,
     373,     0,   160,     0,     0,     0,     0,     0,     0,   280,
       0,     0,     0,     0,   236,   236,     0,     0,   341,   530,
       0,     0,   343,   345,     0,     0,   323,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   198,
       0,     0,     0,     0,     0,     0,     0,   176,     0,   177,
       0,     0,     0,     0,     0,     0,   111,   115,     0,   626,
       0,     0,   624,     0,   636,     0,     0,   150,   151,   633,
     609,   611,     0,     0,     0,     0,   353,   357,   353,     0,
     407,    94,     0,     0,    66,     0,     0,    92,     0,   587,
       0,     0,     0,     0,     0,     0,   639,   638,     0,     0,
       0,     0,     0,   528,     0,     0,    77,   276,   494,   277,
       0,     0,     0,     0,     0,   241,   238,     0,     0,   599,
     597,     0,     0,     0,     0,   123,   128,     0,     0,     0,
     579,   580,   140,   377,   166,   174,   175,   180,     0,     0,
       0,     0,     0,   182,     0,     0,   303,     0,     0,     0,
       0,     0,     0,   481,     0,     0,     0,   567,   500,     0,
       0,   181,     0,   202,   362,     0,     0,     0,     0,   203,
       0,     0,     0,     0,     0,     0,   527,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,     0,   379,   380,    39,   184,   185,     0,   584,     0,
       0,   307,   306,     0,     0,     0,     0,     0,     0,     0,
       0,   153,   154,   157,   156,   155,     0,   613,     0,   650,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   106,
     590,     0,     0,     0,    97,     0,     0,     0,    47,     0,
       0,     0,     0,     0,    49,     0,   242,   239,   240,    35,
       0,     0,   647,   293,     0,   135,   149,     0,     0,   146,
       0,     0,     0,   168,   199,     0,     0,     0,     0,     0,
     573,   574,     0,     0,     0,   507,   482,   495,   497,     0,
       0,   183,   206,     0,     0,     0,   369,   369,     0,   116,
     117,   236,     0,   226,   227,   330,     0,   337,     0,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,   231,     0,     0,     0,     0,   536,     0,   112,   114,
     113,   617,   623,   622,   152,     0,     0,     0,   358,     0,
       0,   109,   101,   103,     0,    91,   640,    98,    99,    52,
       0,     0,     0,     0,   529,     0,     0,   495,   598,     0,
       0,     0,     0,   125,   637,     0,   132,     0,     0,     0,
       0,   188,     0,     0,     0,     0,     0,   333,     0,   172,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   525,     0,   347,     0,     0,   324,     0,   244,     0,
       0,     0,     0,     0,     0,   232,     0,   583,   308,     0,
     537,     0,   391,   236,   408,     0,   588,     0,    48,     0,
       0,     0,    65,    50,     0,   294,   124,   129,   135,     0,
       0,   163,   164,   162,     0,     0,     0,   560,   483,     0,
       0,     0,     0,   370,   384,     0,     0,   385,     0,   224,
       0,   338,     0,   320,     0,   236,     0,     0,     0,     0,
       0,     0,   178,   538,   304,   353,   107,     0,     0,     0,
       0,     0,     0,   133,   134,     0,     0,   559,     0,   204,
       0,   388,     0,   389,   390,   524,     0,     0,   326,   247,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
      62,     0,     0,   126,     0,     0,   334,     0,     0,   346,
     325,   321,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,   245,   360,    53,     0,    60,
       0,   288,     0,   576,     0,     0,   327,     0,     0,    54,
       0,     0,   301,     0,     0,   246,     0,     0,     0,     0,
       0,     0,    57,    55,     0,    58,     0,   386,   387,     0,
       0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   125,  1134,   126,   127,  1118,  2017,  2023,
    1429,  1657,  2187,  2318,  1430,  2291,  2334,  1431,  2320,  1432,
    1433,  1661,   467,   631,   632,  1207,  1759,   128,   833,   495,
    2035,  2198,  2036,   496,  1899,  1512,  1466,  1467,  1468,  1621,
    1837,  1838,  1282,  1717,  1708,  1909,   808,   643,   296,   297,
     374,   216,   298,   477,   478,   132,   133,   134,   135,   136,
     137,   138,   139,   299,  1317,  2224,  2282,  1007,  1313,  1314,
     300,  1097,   301,   143,  1544,  1280,   979,  1023,  2155,   144,
     145,   146,   147,   302,   303,  1234,  1253,  1387,   304,   838,
     305,   837,   498,   660,   340,  1872,   378,  1986,   379,   307,
     601,   393,  1413,  1648,   488,   483,  1380,  1077,  1697,  1865,
    1866,  1062,   490,   149,   403
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2000
static const yytype_int16 yypact[] =
{
   13672,    31,    51, 13883, -2000, -2000,    14,    90,   -35,  -172,
    -140,   -73,    36,   170,   203,   234,   254,    74,    43,    53,
      85,   364,   371,   131,   185,    21,   190,   671,   190,   199,
     214,   219,    61,   260,   263,    66,   271,   281,   284,   337,
     354,   362,   381,   405,   438,   460,   248,    68,   462,   645,
     684,   489,   532,   683,   667,   490,  7602,   504,   547,   560,
     720,   -55,   309,   671,   -34,    39,   589,   757,  -101,   602,
     552,   552,   611,   557,   439,   613,   616, -2000, -2000, -2000,
   -2000, -2000,   634,   110,   794,   802,    13,    52,   914,   821,
     817,   147,  6558,   837,   935,   947,   952,  6558,   953,   -74,
     -57,   665,    20,    69, -2000,   700,   708, -2000, -2000,  3861,
     980,   723, -2000, 14136,   726, 14173,     8,    15,   671, -2000,
   -2000, -2000, 12720,   752,  1006, -2000, -2000, -2000, -2000, -2000,
     756, -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000,
   -2000,   116, -2000, -2000, -2000, -2000,    58, -2000,  1012,   778,
    5692,    34,   765,  1018, 12720, 14073, 14073, 14073, -2000, 12720,
   -2000, -2000, -2000, -2000, 14073, -2000, 12720, -2000, -2000, 12720,
   -2000, -2000, -2000, -2000,   784,   771,  1054, -2000, -2000, 14258,
   -2000, -2000, -2000, -2000,   801, 14258, 12720, 12720, 12720,   803,
   12720, 12720, 12720,   823, 12720, 12720, 12720, 12720, 12720, 12720,
   12720, 14073, 12720, 12720, 12720, 12720,  6558,   826, -2000, -2000,
   10724, 10724, -2000, -2000, -2000,   798,  6558,  7863, 14073, -2000,
   -2000, -2000, -2000, -2000,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     207,   190,   190,   190,   190,   190,   829,   190,   190,   848,
     671,   250,   250,   250, -2000, -2000, -2000,   190,   190,    29,
     902,   925,   933,   842,  1013,   -24,  7863,   988,   671,   671,
     250,   904,   190,   190,   959,   978,   981, -2000, -2000, -2000,
   12720,  8124, 12720, 12720,  8385,    21,  1044,    38, -2000, -2000,
     863, -2000,  3991, -2000, -2000, -2000, -2000, -2000,   104, 12720,
   10724, 10724,   984,   985,  8646,  6558,  6558,  6558, -2000, -2000,
   -2000,   986, -2000,   979,   987,  8907,   989, 11435,  1247,  7863,
     990,    20,   991,   993,   552,   552,   552, 12720, 12720,  -121,
   -2000,   233,   552, 11595,   473,   258,   992,   998,   999,  1000,
    1001,  1002,  1003, 10724, 10724, 12720,  6558,  6558,  6558,   272,
      19,  1248,  1008, -2000,  1261,  1268, -2000,  1009, -2000,  1010,
    1011, -2000, -2000,  1014,  6558, -2000, 12720,  6819, -2000,  1246,
    1015,  1019,  1020,  1021,  1269,  1273,  1017, 12720,  1025, 12720,
   12720,   292, 12720,  1016, -2000,  1090, 12720, 12720, 12720, -2000,
     190, 12720,  1053,   115, -2000, 12720, -2000,   190,   190,   190,
    1027,  1048,  1049,   190,   190,   190,   190,   190,   190,   190,
   -2000,   190, -2000, -2000, -2000, -2000,   190,   190,  1050,  1058,
     190,  1060, -2000,  1052,  1318,  1319,  1062, -2000, -2000,  1324,
    1323,  1326,  1325,  1071, 15915, 14073, -2000, 10724, 12720, -2000,
   -2000,  7863,  7863, -2000,  1068, 14258,   671,  1329, -2000, -2000,
   -2000, -2000, -2000, -2000, 12720, 12720,   437,  7863,  1333,   587,
    1073,  1472,  1074,  1336,    37,  1076, -2000,  1078, 14272, 12720,
   -2000,  1947,  -217, -2000,     1,  -204,  -167,  6751, -2000,  -146,
   -2000,    73,  7012,   500,  7273,  -188,  -108,  1251, -2000,    21,
    1072, 12720,  1079, 16431, 16456, 16481, 12720, 16506, 16531, 16556,
   12720, 16581, 16606, 16631, 16656, 16681, 16706, 16731,  1086, 16756,
   16781, 16806,  6035,  1345, 12720, 10724,  4047, -2000,   388,   427,
   12720,  1347,  1348,  1091, 12720, 12720, 12720, 12720, 12720, 12720,
   12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720,
   12720, 10724, 12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720,
   10724, 10724,  1089, 12720, 12720, 14073, 12720, 14073,  7863, 14073,
   14073, 14073,  1092,  1094,  1095,  1096, 12720,    67, -2000, 11696,
   12720,  1097,   147,  1099,  7863,  6558,  7863,  1100, 14073, 14073,
   10724,    21, 14258,    21,  1106, 10724,  1106, -2000,  1106, 16831,
   -2000,   513,  1088,    81,  1290, -2000,  1362, 12720, 12720, 12720,
   12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720, 12720,
   12720,  9168, 12720, 12720, 12720, 12720, 12720,    21, 12720, 12720,
     146, -2000,   706, 16856,   519,   545, 12720, 12720, 12720, -2000,
    1364,  1365,  1365,  1111, 12720, 12720, 12720, 12720,    24, 10724,
   10724, 15943,  1112,  1371, -2000,  1114, -2000, -2000,  -132, -2000,
   -2000,  7534,  7795,   552,   552,    34,    34,  -123, 11595, 11595,
   12720,  3209,  -110, -2000, 12720, 12720, 12720, 12720, 12720, 12720,
   12720, 12720, 12720,   620,   642, 16881,  1372,  1379,  1375, 12720,
   12720,  1380, 12720, -2000, -2000, 12720, 11663, -2000, -2000, 10724,
   10724, 10724, 12720,  1381, 16906,  1121, 12720, 10724, 12720, 12720,
   12720, -2000, -2000, 12720, 16931, 12720, 16956, 16981,  1194,  8056,
   -2000,  1124,  5430, 17006, 17031, 12720,  1106, -2000, 12720,    21,
   12720, 12720,   146, 16026, 14073, 14073, 14073, 14073, 14073, 14073,
   14073, 14073, 14073, 12720, 14073, 14073, 14073, 14073,    23, 14258,
   14073, 14073, 14073,    21,    21, -2000, -2000, 10724, -2000,  1125,
   11919, -2000,  1126, 12175, 12720, -2000,  1129,   672, 17056,  4596,
    1128,   673, 12720,  1391,  1131,  7863, 17081, 16053, -2000, -2000,
   -2000, -2000, -2000, -2000,  1130,  1393,   149,  1395, -2000, -2000,
   -2000, 10724,   187, 12720, -2000, -2000, -2000,    21, 12720, 12720,
     146,  1137, -2000,  1140,   -48,   671,   -34,   671, -2000,  1138,
   14813, -2000,   165, 10724,    21, 12720, 12720,   146,  1401, 10724,
    1402, 10724, 12720,  1404, 14073,    21, 11856,   146, 12720, -2000,
   12720,  1405, -2000,    21,  1406, 14073, 12720,  1149,  1150, -2000,
   12720,  8317, 14258,  1409,  1410,  1411, 17106,  1412,  1414,  1415,
   17131,  1416,  1417,  1418,  1419,  1420,  1421,  1422, -2000,  1423,
    1424,  1425, -2000, 12720, 17156, 10724,  1166, 10724,    56, 14842,
   -2000, -2000,  1430, 15999, 15999, 15999, 15999, 15999, 15999, 15999,
   15999, 15999, 15999, 15999, 15999,  8578, 15999, 15999, 15999, 15999,
    1376,   313, 15999, 15999, 15999,  8839,  9100,  9361,  9617,  9873,
    4047,  1173,  1172,    97, 10724, 10134, 10395,   313, 10656,   313,
    1168,  1170,  1171,  -129, 10724, 12720, 12720, 12720, 18106, -2000,
     313,  1176, 14871, 14900, 12720,  1179, 12720, -2000, -2000, 12720,
    1175,   215,   313,  -104,  1184,   612,   675,  1442, -2000,   146,
     313,  7863,  1182,  5575,  5608,   964,  1758,   983,   983,   680,
     680,   680,   680,   680,   680,   603,   603, 10724,   569, -2000,
     569,   569,  1106,  1106,  1106,  1183, 17181, 16080,     2, 10724,
   -2000,  1444,  1186,  1187, 17206, 17231, 17256, 12720,  7863,  1451,
    1450, 11338, 17281, 14929, 17306, 17331, -2000, 12720,   681,   687,
   10724,  1188, -2000, 12431, -2000, 12687, 13086,   552, 12720, 12720,
   -2000, -2000,  1190,  1192, 11595,  3170,  1315,   747,   552, 13148,
   17356, 14958, 17381, 17406, 17431, 17456, 17481, 17506, 17531,  1195,
    1196,  1457, 12720,  1460, -2000, 12720, 17556, 14987, -2000, 16107,
   13210, 16134, -2000,   690,   696,   697, 15016, -2000, -2000, -2000,
    2102,   710, 16161, 16188, 11011, 17581,  1461, 17606,  1463,  1464,
    1198, 12720, 13272, 12720, 12720, -2000, -2000, 15999,   569,  1204,
     656,    50,   279,   391,   279,  1210,  1211,  1205,   313,   313,
    1207, 12863,   313,   313,   313,   313, 12720,   313,  1471, -2000,
    1209,  1218,   395,   -21,  1226,   711, -2000, -2000, -2000, -2000,
   17631, 13334,  1233,  1298,  1498,  1338, 11952,  1239,  1241,  1504,
    7863, 15045, -2000, 12720,  1507,   156,    79,   146,    27, 14258,
   12720,  1508, -2000,   712,  1465,  1466,  7863, 15074,    41,  1250,
   17656, 16215,   635, 12720, 12720,  1254,  1253,  1258,  1255,  9429,
   -2000, -2000, -2000, -2000, 14073,   -94,  1256, 17681, 16242,  1260,
   -2000,   -39, -2000,   173, 12901, -2000, -2000, -2000,  1257, -2000,
    1264, 15103, 13452, -2000,    78, -2000, -2000, 18106, -2000,    77,
   15999, 12720,   313,   552,  7863,  7863,  1517,  7863,  7863,  7863,
    1523,  7863,  7863,  7863,  7863,  7863,  7863,  7863,  7863,  7863,
    7863,  2199,  1524, 10724,  4047, -2000, -2000,    34, -2000, -2000,
   -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000,
   -2000, -2000, 12720, -2000, -2000, -2000, -2000, -2000, -2000, -2000,
   -2000, -2000, 12720, 12720, 12720, 12720, 12720, -2000, -2000, -2000,
     713, 12720, 12720, -2000, 12720, -2000,  7863, 14073, 14073, -2000,
     742, 15132, 15161, 15190,  1262, -2000, -2000, -2000,  1334, 15219,
   12720, 15248, 15277, 12720, 12720, -2000, -2000, -2000,   146, -2000,
     146, 12720, 12720,  1271, -2000,  7863,   190, -2000, -2000, -2000,
   12720, 12720,   743,   146,   168,   -38, 12720, 12720, -2000,   313,
     753,  7863, 10724, 10724,  1525,  1534,  1535,   828, -2000, -2000,
    1537, -2000,  1280, 18106,  1276,  1542, -2000,  1543,  1544,  2241,
    1545,  1546,   758,   428, -2000, 13396, -2000, -2000,   -77, 13671,
   14178, -2000, -2000, 15306,  -151,  1434,  1553, 12112,  1291,  1554,
    1296,    26,    42,   -44, -2000,   -72, -2000,   747,  1555,  1557,
    1558,  1559,  1560,  1561,  1562,  1563,  1564,    34,    34,  7863,
   18106, -2000,  2408,  1294,  1469,  1568, -2000,  1570,  1571,  1470,
    1573, -2000, -2000,  1574,  1572,  1576, 12720,  1578,  7863,  1579,
    7863,  7863,  1583, 14252, -2000,  5726,   465,   146, 12720, 12720,
     146,   146, -2000, 10724, -2000, -2000, -2000, -2000, 14073, -2000,
   -2000, 12720, 14073, -2000, -2000, -2000, -2000, 18106, -2000,  1320,
    1317, 14073, -2000, 14073, -2000,   146, 14073,  1327, -2000,  1321,
    1586, -2000,  1330,   671,  1331, 12208, -2000,  2540,  1337,  7863,
   -2000,  1328, -2000, 15335, -2000, -2000, 12720,  1588,   457, 12720,
    1594,  1596,    20,  1599,  1341,  1601,  2564, -2000,   313,   190,
     190,  1602, -2000, -2000,  1346,  1349,  1343, -2000,  1605, -2000,
   -2000, -2000, -2000, -2000, -2000,   146,   141,  4933, 12720, 16269,
   17706, 12720,  9685, 12720, 10724,  1366,   761,  1607,   167,   146,
   -2000,  1367, 12720,  1609,  1629, 12720,   146, 12368,  1631, 12720,
    5238,   313,  6004, 12720, 12720, 12720,  1373,  1369, -2000,  1638,
   17731,  1639,   130,  1509,  1509,  7863,  1640,  1641,  1643,  7863,
    -106,  1644,  1647,  1648,  1649,  1650,  1652,  1653,  1654,  1655,
   -2000,  1657,   763,  1396, 15999, 15999, 15999, 15999, 15999, 15999,
     313, 14285, 14318, 14351,  1399,   313,   313, -2000, -2000, -2000,
   -2000,    77,   313,  1539, 15364,  1467, -2000, 17756, 15999,  1403,
    -156, 18106, 15999, -2000,  1662,   313, 18106, 18106, -2000,   326,
   -2000,   146, -2000, 17781, 16296, -2000,   313,  1664,   782,   788,
    7863,  7863,  7863,  1667,  1668, -2000,   197, 12720,  7863,  7863,
    7863, -2000,  1413,  1427,  1669,  1671,  1672, -2000, 12720, 12720,
   12720,  1428,  1429,  1431,  1432, -2000,  2685,  7863, -2000, 12720,
   -2000,  1675, -2000,  1677, -2000, -2000, 11595,   334,  7080, -2000,
    1433,  1435,  1436,  1437,  1438,  1439,  9941,  1440,  1441,  1679,
   -2000, 10724,  1443, -2000, -2000, -2000,  1468, 12720, 12720, -2000,
   -2000, 16323,  7863,  1682,  7863,  1683,  1483, -2000, 12720, 12720,
   12720, -2000,   535,  1684,   486,   507,  1458,  1622,  1459, 12720,
      35,   313,  1473,   313,  1474, -2000, -2000, 14258, -2000, 12720,
    1476, -2000, -2000,  2746, -2000, -2000,  1475,  1686, -2000,  3385,
   -2000,  1481,  1692,   161,  3740, -2000,    20, -2000,   789, -2000,
   12720, -2000, -2000,   197, 12857, 12953, -2000,  1477, 12720, 12720,
    7863,  1484, -2000,    82,   590,  1695, 17806,  1701,  1442, 17831,
    1485,   790, 17856,   819,  1726,  1727, -2000, -2000, 14073,  1489,
    1732, 17881, -2000, -2000, 14384,  1491, -2000, -2000,  1989,  6297,
   18106, -2000,  1748,   190,  8385, -2000, -2000, -2000, 18106, 18106,
   18106, -2000,    77, -2000,  1733, -2000, -2000,   552,  1750,  1751,
    1753, -2000, -2000, -2000,  1614,   -53,  1656,  1756, -2000, -2000,
   -2000, -2000, -2000, -2000, -2000, -2000, -2000,  1759,  1499,  1763,
   -2000, -2000, -2000, -2000, -2000, -2000, -2000, 12720, 12720, 12720,
   -2000, -2000, -2000,  1369, -2000,  1503, -2000,  1663, -2000, -2000,
   -2000, 12720,  1501,  1505, -2000, -2000, 12720, 12720,   313,   168,
   -2000, -2000, -2000, -2000,  1511,  1513,  1765,  -106,  1769, 12720,
   -2000,  7863, 18106,  1630,  1635,   724, 10724, 10724, 12720, -2000,
   11338, 15393, 17906,  5936,    34,    34, 12720, 12720, -2000,   432,
    1510, 17931, -2000, -2000, 15422,   -70, -2000,  1777,  1781,  7863,
     552,   552,   552,   552,   552,  7341,  1782, -2000, -2000, -2000,
     827, 10724, 12720,  3797,  4023,  1783,  1784, -2000,  1785, -2000,
    7863,  6229,   593, 17956, 12720, 12720, -2000, -2000, 10980, -2000,
   14073, 12720, -2000, 14073, 18106, 11077, 14258,  1520, -2000, -2000,
   -2000, -2000,  1529,  1522, 15451, 12720,  4596, -2000,  4596,  7863,
   -2000, -2000,   146,    27, 14258, 12720,  1789, -2000,  1791, -2000,
      20, 16350,  7863, 14073,  1793,   313, -2000,  1528,   313, 12720,
   14417, 14450,   830, -2000, 12720, 12720,  1538, -2000,  1540, -2000,
    1535,  1798,  1800,  1544,  1803, -2000, -2000,  1804, 12720, -2000,
   -2000, 12720, 12464,  1805, 12720, -2000, -2000,  1547, 12953,   835,
    3361,  1806, -2000, -2000,   555, -2000, -2000, -2000,  1665,  1810,
    1551,  1552,  1556, -2000,  1807,  7863, -2000, 15999, 15999, 14483,
   12720,  1565, 15999, -2000,  1567, 17981, 16377, -2000, -2000, 10724,
   10724, -2000,  1814, -2000, 18106,  1815, 12720, 12720,  1566, -2000,
     838,   844, 15971,  4314,  1816,  1569, -2000, -2000, 12720,  1575,
    1577, 15480, 16404,  1818,  7863,  1819,  1580, 12720, -2000, -2000,
     846,   -40,   155,   195,   217,   246, 10202,   252, -2000,  1822,
     849, 15509, -2000, -2000, -2000, -2000, -2000,  1645, -2000, 12720,
   12720, -2000, -2000, 12624, 10463,  4617,  1823,  1828,  1584, 15999,
     313, 18106, -2000, -2000, -2000, -2000,    35, -2000, 14258, -2000,
   15538,  1581,  1585,  1587,  1830,  1829,  1832,  5098, -2000, -2000,
   -2000,  1582,  1835,   861, -2000,  1836,  1838,   188, 18106, 12720,
   12720,  1589,  7863,   867, 18106, 18006, -2000, -2000, -2000, -2000,
   18031, 14516, -2000, -2000, 15567,  1262,  1317,  7863,   313, -2000,
   12720, 14258,    21, -2000, -2000, 10724, 10724, 12720,  1846,   869,
   -2000, -2000, 12720, 14549, 12720,  1505, -2000, -2000, -2000,   870,
     872, -2000, -2000,  5145,  5168,  7863,   722,   734, 10724, -2000,
   -2000,    34,  6490, -2000, -2000, -2000,  1848, -2000,  1590,  7863,
   -2000, 15596,  1855, 10724,   552,   552,   552,   552,   552, -2000,
    1874, -2000, 12720, 15625, 15654, 10724, -2000,   875, -2000, -2000,
   -2000, -2000, -2000, -2000, -2000,  1617,  1876,  1618, -2000,  1881,
      20, -2000, -2000, -2000,  1628, -2000, -2000, -2000, -2000, -2000,
   12720, 14582, 14615,  7863, -2000,  1883, 12720,  1623, -2000, 12720,
    1885,  1624,  1625, -2000, -2000,   751, -2000,  1642,   878,   880,
   15683, -2000,  1636, 14648, 12720, 15712,  1646, -2000,  1637, -2000,
   -2000,   883,  1651,   552,  7863,  1896,  1658,   552,  1900,   885,
    1660, -2000, 12720, -2000,  1901,  1762, 13458,  1666, -2000,   886,
     257,   308,   321,   324,   378, -2000,  5313, -2000, -2000,   888,
   -2000,  1903, -2000, -2000, -2000,  1907, -2000,  1670, 18106, 12720,
   12720,   891, -2000, 18106, 14681, -2000, -2000, -2000,  1262, 14258,
    1659, -2000, -2000, -2000, 12720, 12720, 15741, -2000, -2000, 10724,
    1909,   552,   138, -2000, -2000,   552,   153, -2000,  1910, -2000,
   15770, -2000, 12720, -2000,   747, -2000,  1911, 10724, 10724, 10724,
   10724, 10202, -2000, -2000, -2000,  4596, -2000, 12720, 18056, 14714,
      60, 12720,  1661, -2000, -2000, 14747, 14780, -2000,   910, -2000,
     380, -2000,   386, -2000, -2000, -2000,  5358,   355, 13520, -2000,
     911,   913,   916,   918,   397,   921,  1673,   923, -2000, 12720,
   -2000,  7863, 15799, -2000, 12720, 12720, -2000,   552,   552, -2000,
   -2000, -2000,   747,  1913,  1915,  1916,  1918, 10724,  1924,  1925,
    1926,  1676, 18081,   924,  1928, 15828, 15999,   511,   518,   619,
   -2000, -2000, -2000, -2000,   929, -2000, -2000, -2000, 14073, -2000,
    1678, -2000,  1929, -2000, 12720, 12720, -2000,  1932,   930, -2000,
    1680,  7863, -2000, 15857, 15886, -2000,  1933, 14073, 14073,   931,
    1934,  1936, -2000, -2000,   932, -2000,  1938, -2000, -2000,  1940,
   14073, -2000, -2000, -2000
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -2000, -2000, -2000, -2000,   501, -2000, -2000, -2000, -2000,  -289,
   -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000, -2000,
   -2000, -2000,  -771,  -145,  2286,  4015,  -341, -2000,  1454, -2000,
   -2000, -2000, -2000, -2000, -2000, -1999, -2000,   441,   253,   -80,
   -2000,   -37, -2000,   191,   483, -2000,  1957, -2000,   749,   -45,
    1382, -2000,     0,  -657,  -166, -2000, -2000, -2000, -2000, -2000,
   -2000, -2000,   843,  1959, -2000, -2000, -2000, -2000, -1306, -1309,
    1962, -1832,  1963, -2000, -2000, -2000,  1332, -2000,  -100, -2000,
   -2000, -2000, -2000,  2568, -2000, -2000, -1519,   344,  1966, -2000,
       4, -2000, -2000,    96, -2000, -1793,   820, -2000,   -79,  3152,
    3551,  -324,   117, -2000,   301,   -87, -2000, -2000,   136,   317,
   -1802,  -152,  1151, -2000,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -600
static const yytype_int16 yytable[] =
{
     150,  1752,   493,   131,  1575,   468,  1960,   655,  1002,  1003,
     814,  1577,   489,   439,  2001,  1110,  2002,   360,   384,   325,
     441,  1116,   176,   691,   391,   174,   434,   174,   438,   175,
     986,   174,  1570,  1994,   578,   386,  2131,     4,   475,  1835,
    1715,   174,   158,   605,   582,  1423,   797,   812,  1572,   165,
    1910,     5,   388,   308,   313,   813,   365,  1360,   366,   167,
     818,   313,  1186,   473,   450,   189,  2270,   330,   819,  1911,
     193,   174,   319,   395,   154,   320,   321,   322,   831,   583,
     314,  1462,   825,   364,   832,  1460,  1405,  1125,   323,   308,
     499,   155,   500,  1716,   308,   331,  2038,   820,   502,   394,
     663,   664,  1306,  1463,   153,   821,   627,   177,   361,   178,
     435,   332,   333,   627,  1464,  1465,  1251,  1562,   823,   663,
     664,  1307,  2049,   156,   729,   786,   824,   523,   663,   664,
     663,   664,  1308,  1309,  1310,  1229,  1706,   531,  1311,  1312,
     997,   663,   664,   824,  2251,   326,   665,   474,   327,  1004,
     778,   476,   484,   484,   484,   367,  1109,   324,   834,  2253,
    1247,   491,  1008,  1405,   832,  1248,   339,   341,  1854,   344,
    1448,  1131,   779,  1677,   663,   664,   160,   671,   867,   663,
     664,   663,   664,   780,   781,    69,    70,    71,    72,   387,
     157,    75,    76,   206,  1114,  1558,   987,   696,   484,  2242,
    1576,    85,  1957,   308,  1405,    89,   389,   308,   308,   161,
    1571,   663,   664,   308,   308,   484,   573,   574,   575,   356,
     362,   357,   462,   463,  1574,  1453,  1573,  1424,  1425,  1426,
    1427,  1531,  2083,   867,  1924,   587,   640,   641,   642,   103,
     162,   104,   105,   106,   107,   108,  1836,   123,  1385,   112,
     113,  1386,   115,   371,   123,   123,   372,   123,   782,   783,
     163,   123,   462,   463,   815,  1266,   816,  1267,  1575,   373,
     817,   123,  2151,   308,   760,   440,   763,   686,   687,   688,
     363,   151,   442,   769,   692,   152,   693,   392,   308,   968,
     152,   308,   603,  1076,  1412,   703,   579,   462,   463,   602,
     798,   123,   799,   159,  -592,   606,   800,   308,   308,  1428,
     166,   308,   308,   308,   308,   458,   459,   460,   461,  1361,
     168,   451,   308,  1187,   190,   452,   308,  2271,   394,   194,
    2191,   789,   396,   790,  1406,  1409,   826,   164,   816,   462,
     463,   177,   827,   178,   177,  1875,   178,  1825,  1408,  -596,
     308,   308,   169,   308,   308,   308,   319,   462,   463,   320,
     628,   322,   629,  1219,   462,   463,   630,   628,   773,   629,
     170,   308,   323,   630,   308,   462,   463,   171,   730,   448,
     731,   663,   664,   449,   732,   458,   459,   460,   461,   663,
     664,  1060,   458,   459,   460,   461,   172,   458,   459,   460,
     461,   462,   463,  2266,   663,   664,   663,   664,  -594,   462,
     463,  1132,  1133,  1132,  1133,   315,   462,   463,   316,   913,
     317,   462,   463,   458,   459,   460,  1115,  2084,   462,   463,
     658,   659,  1555,   458,   459,   460,   461,  1454,   667,   672,
     607,   778,   484,   345,   308,   867,   663,   664,   308,   308,
     173,   472,  2119,   177,   779,   178,   482,   485,   486,  1122,
    2120,   778,   186,   779,   308,   780,   781,  2085,   663,   664,
     560,   801,   561,  1610,   780,   781,  1139,   187,  2293,   789,
    1306,   790,   188,   779,   663,   664,  1150,  1244,   993,  2086,
     995,   996,  1827,  1828,   780,   781,   839,   663,   664,  1307,
     666,  1306,   518,   663,   664,   934,   927,  1009,   663,   664,
    1308,  1309,  1310,     7,     8,   205,  1311,  1312,  2087,   533,
    1307,   674,   308,   191,  2088,   675,   192,  1030,  2329,  2227,
    1493,  1308,  1309,  1310,   195,   689,  2146,  1311,  1312,   690,
     782,   783,   346,   789,   196,   790,   347,   197,   308,   782,
     783,   824,   348,   349,  1052,   350,   351,   308,   903,   663,
     664,   718,   484,   152,   484,   308,   484,   484,   491,   782,
     783,   207,   663,   664,   920,   663,   664,   789,   352,   790,
    2228,   308,   308,   308,  1064,   484,   484,   308,   176,  1756,
     176,  1757,   308,  2229,  1876,   933,  2230,   935,  1256,  1091,
     198,  1980,  1796,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   779,   199,   308,    43,
      44,    45,    46,  2280,   965,   200,    48,   780,   781,   663,
     664,   663,   664,   784,   785,   803,    57,   663,   664,    60,
     804,  1111,   805,   806,   201,   807,   308,   308,   663,   664,
    2231,   208,  2277,  1641,  1642,   789,   866,   790,  2278,   789,
     867,   790,  1079,  1363,    82,   476,   476,  1383,   202,  2287,
    1587,  1588,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     209,    99,   100,   101,   626,   868,   308,   308,   308,   867,
    1953,   203,   782,   783,   308,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,   204,   663,   664,  1059,   626,  1938,  1611,
    1939,   491,   484,   491,   484,   484,   484,   484,   484,   484,
     673,   484,   484,   484,   484,  1078,   766,   484,   484,   484,
     176,  1084,   130,   218,   308,  1162,   210,  1083,  2199,  1000,
    1001,  1127,   663,   664,   659,  1306,  1411,   309,   829,   663,
     664,   789,   308,   790,   180,  1771,   184,   181,   217,   867,
     182,   938,   183,  2314,  1307,   867,   212,   972,   308,   213,
    2315,   867,   214,    46,  1119,  1308,  1309,  1310,  1824,   211,
    1825,  1311,  1312,   335,   336,   215,   663,   664,   335,   336,
     308,  1136,   318,   973,   310,   337,   308,   867,   308,   338,
     337,   491,  1148,  1268,   343,   624,   625,   311,  1295,   312,
    1154,   626,   484,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,   789,   328,   790,   791,   626,   728,   622,   623,   624,
     625,  1981,   308,   329,   308,   626,   907,   443,   909,   334,
     911,   912,  1855,  2152,  2153,   177,   306,   178,   342,  2154,
     353,  1250,  1862,   354,  1251,  2156,  2157,  2316,  1019,   930,
     931,  2154,   867,  1306,  1284,   462,   463,   355,  1438,   470,
    1359,   308,  -595,   358,   470,   470,   470,  1519,   359,  1520,
    1020,   308,  1307,   470,   867,  1268,   462,   463,  2257,  1358,
     368,  1359,  1529,  1308,  1309,  1310,   370,   369,   390,  1311,
    1312,   619,   620,   728,   622,   623,   624,   625,   308,   381,
    1093,  1099,   626,  1254,   867,  1100,   380,   867,  1575,  1290,
     470,   382,  1556,   867,   308,  1291,   383,   385,  1338,   867,
    1407,  1410,   867,   397,  1339,  1340,   308,   470,   867,   867,
     789,   398,   790,   969,  1543,   308,  2299,  1268,  1343,  1389,
    1418,  1500,   867,   867,   867,   867,   404,   308,   405,   436,
    1575,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,   572,
    1507,  1528,   446,   626,   867,   867,  1612,   445,   453,  1613,
    1614,  1536,  1415,   447,   480,   867,  1554,   585,   586,  1675,
     867,  1728,   479,   867,   497,   867,  1063,   532,  1065,  1066,
    1067,  1068,  1069,  1070,  1624,  1072,  1073,  1074,  1075,   454,
    1764,  1080,  1081,  1082,   867,   152,  1765,  1859,  1882,   727,
     867,  1860,   867,   499,   501,   530,   506,  1643,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,   510,  1884,  1647,   524,
     626,   867,   568,  1298,  1663,  1969,   306,   308,  2021,   867,
    1304,  -208,  2022,  2039,  1315,  1414,  2066,  2040,  1679,   580,
     867,   571,  2067,   308,  2082,  1685,   867,  2090,  2022,  1530,
    1532,   867,   581,   584,  -209,  1146,   308,  1949,  1950,  2116,
     449,   484,  -210,   824,   639,  2125,  1156,  2142,  2147,  2126,
    2148,  2022,   867,  2180,   867,   648,  2201,   867,  2202,   653,
     867,  2210,   867,  2218,  2226,  2022,  2233,   867,   867,  2240,
     867,   308,   308,  2022,   308,   308,   308,   588,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,  2276,  2283,
     308,  2284,   867,   867,  2285,   867,  2286,   476,   867,  2288,
     867,  2290,  2310,   867,   470,  2126,  2022,  2317,  2326,  2336,
    2339,   867,  2327,  2022,  2340,   774,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,   591,   308,   484,   484,   626,   809,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,   592,   809,   604,   593,   626,   645,   636,   637,   644,
     646,   652,   308,   706,   694,   676,   649,   654,   656,  1472,
     657,   677,   678,   679,   680,   681,   682,   697,   308,   308,
     308,   770,   771,   695,   698,   711,   699,   700,   701,   712,
     713,   702,   707,   720,   708,   709,   710,   787,   715,   721,
     737,  1530,  1532,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,   738,   739,   750,   470,   626,   470,   754,   470,   470,
     470,   751,  1858,   753,   755,   756,   308,   476,   476,   757,
     758,   759,   761,   762,   764,   772,   775,   470,   470,   788,
     793,   795,   796,   151,   840,   308,   802,   308,   308,   836,
     858,   842,   863,   870,   871,   872,   904,   939,   941,   914,
     308,   915,   916,   917,   924,   484,   926,   929,   626,   484,
     942,   977,   978,  1691,   981,  1696,   991,   992,   484,  1022,
     484,   994,  1025,   484,   607,  1024,  1028,  1037,   910,  1039,
    1050,  1053,  1098,  1086,  1088,  1092,   308,  1102,  1103,  1107,
    1108,  1112,  1123,  1124,   639,  1129,   928,  1140,  1142,   394,
    1145,  1153,  1155,  1158,  2160,  1159,  1163,  1164,  1165,  1167,
     809,  1168,  1169,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,  1183,   484,  1447,  1189,  1217,  1218,   308,
    1226,   308,  1227,  1228,  1236,   809,  1240,  1243,  1249,  1255,
    1259,  1271,  1263,  1272,  1273,  1279,  1281,  1293,  1301,   308,
    1302,  1305,  1327,  1328,  1329,  1846,  1331,  1352,  1348,  1848,
    1350,  1351,   308,  1357,  1366,  1367,   308,  1368,   794,  1371,
    1379,  1381,  1382,   470,   470,   470,   470,   470,   470,   470,
     470,   470,  1388,   470,   470,   470,   470,  1393,  1856,   470,
     470,   470,  1867,  1867,  1392,  1394,  1395,  1398,  1399,   809,
    1400,  2004,   809,  1404,  1417,  1419,  1420,  1441,   809,  1435,
    1442,  1443,  1444,  1452,  1475,  1449,  1456,  1457,  1505,  1506,
    1479,  1491,  1540,  -211,  1511,  1523,  2010,   308,   308,   308,
    1843,  1541,  1542,  1545,  1546,   308,   308,   308,  1547,  1548,
    1549,  1550,  1552,  1553,  1126,  1563,  1128,  1564,  1567,  1569,
    1568,  1591,  1578,  1579,   308,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1592,   470,  1593,   308,  1594,  1595,  1599,  1596,
    1597,  1598,  1600,   308,   470,  1602,  1604,  1607,   308,  1620,
    1619,  1626,  1628,  1627,  1640,  1104,  1637,  1629,  1631,   308,
    1645,   308,  1896,  1646,  1635,  1649,  1650,  1651,  1656,  1658,
    1660,  1662,  1659,  1676,  1928,  1682,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   865,
     622,   623,   624,   625,  1674,  1683,  1680,  1687,   626,  1701,
     789,  1702,   790,   394,  1703,  1705,  1711,  1712,  1707,  1713,
    1718,   491,   491,  1719,  1720,  1721,  1722,   308,  1723,  1724,
    1725,  1726,  1727,  1740,  1729,  1745,  1747,  1750,  1754,  1616,
    1763,  1769,  1795,  1618,  1770,   484,  1778,  1779,  1820,  1780,
    1776,  1792,  1622,  1793,  1623,  1809,   308,  1625,  1817,  1819,
    1826,   308,  1850,  1944,  1777,  1784,  1785,  1787,  1786,  1853,
    1799,  1877,  1800,  1801,  1802,  1803,  1804,  1879,  1807,  1808,
    1811,  2013,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
    1830,  1833,  1885,  1886,   626,  1812,  1889,  1840,  1665,  1903,
    1869,  1987,   809,  1845,   809,   809,  1386,  1849,  1992,  1995,
    1852,  1874,  1888,  1881,  1892,  1897,  1905,  1906,   809,  1907,
    1908,  1258,  1913,  1912,  1914,  1923,  1915,  2006,   308,  1916,
    1920,  1931,  1921,   308,   308,  1933,  1936,  1251,  1929,   809,
    1930,  1937,  1954,  1958,   476,   476,  2185,  1959,  1968,  1974,
    1975,  1976,  1996,  1997,  1998,  2008,   308,  2009,  1278,  2014,
     824,   809,   308,  1904,  2026,  -599,  2027,  -597,   308,  2028,
    2029,  2033,  2048,  2042,  2037,  2043,  2044,   308,  2045,  2046,
    2061,  2062,  2070,  2047,  2077,  2186,  2079,   484,  2089,  2099,
     484,  2056,  2054,  2065,  2100,  2111,  2071,  2110,  2112,  2092,
     809,  2115,  2117,  2073,  2118,  2074,   308,  2080,  2101,  2107,
    1414,  2114,  2141,  2108,  2163,  2109,  2123,   394,  2164,   308,
     491,  2168,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
    2175,  2181,  2182,   470,   626,  2183,   789,  2184,   790,  2192,
    -598,  2195,  2196,  2197,  1831,   491,  1961,  1962,  1963,  1964,
    1965,  1967,  2214,  2204,  2209,  2200,  2217,  2221,  2222,  2234,
    2208,  2105,   308,  2236,  2166,  2249,  2254,  2259,  2211,  2300,
    1401,  2301,  2302,  2244,  2303,  2215,   308,   308,  2219,  2273,
    2305,  2306,  2307,  2225,  2311,  2322,  1421,  2237,  2325,  2332,
    2337,  2289,  2338,  2308,  2341,  2321,  2342,  2328,  2267,  1678,
     835,   308,  1743,   811,  2136,  1902,  2132,  1709,  1932,  2104,
     129,  1434,   140,   308,   925,   141,   142,  2158,  1842,   148,
    2005,  1993,  1868,     0,   980,  1147,   470,   470,     0,  1887,
       0,   308,     0,     0,  1473,  1474,     0,  1476,  1477,  1478,
       0,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,
    1489,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,  2235,     0,   308,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   308,     0,     0,     0,     0,  2137,
       0,     0,   308,   308,   809,     0,  1504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2258,
       0,     0,   308,     0,     0,   308,     0,     0,     0,     0,
       0,   476,     0,     0,     0,  1524,   308,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1537,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   394,  1342,     0,
       0,     0,  2243,     0,     0,     0,     0,   470,     0,     0,
     308,   470,     0,     0,     0,     0,     0,     0,     0,     0,
     470,  1988,   470,     0,  1990,   470,     0,     0,     0,     0,
       0,     0,  1630,     0,     0,     0,     0,     0,     0,  1589,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1603,     0,
    1605,  1606,     0,     0,     0,     0,     0,     0,     0,     0,
    2170,  2171,  2172,  2173,  2174,     0,   470,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,  1490,   308,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1636,
       0,     0,     0,     0,   308,   308,   308,   308,   308,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,  1551,     0,  2212,
       0,   626,     0,  2216,     0,     0,     0,  1893,     0,     0,
       0,  1894,     0,     0,     0,     0,     0,     0,   308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1695,     0,   308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1710,     0,     0,     0,  1714,
       0,     0,     0,     0,     0,   484,     0,  2250,     0,     0,
       0,  2252,   179,     0,   185,     0,     0,     0,   308,     0,
       0,     0,     0,     0,   484,   484,     0,  2264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
    1766,  1767,  1768,     0,   626,     0,     0,     0,  1773,  1774,
    1775,     0,     0,  2297,  2298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1790,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1798,     0,
       0,     0,     0,   470,   470,     0,  1806,     0,     0,     0,
       0,     0,     0,     0,  1590,     0,     0,     0,     0,     0,
       0,     0,  1816,     0,  1818,     0,     0,   470,     0,     0,
       0,     0,     0,     0,     0,     0,   469,     0,     0,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1873,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1895,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   562,   563,   564,   565,
     566,   567,     0,   569,   570,     0,  1634,     0,     0,     0,
       0,     0,     0,   576,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
    1652,     0,     0,     0,     0,     0,     0,     0,     0,   470,
       0,     0,   470,     0,     0,     0,     0,     0,     0,     0,
       0,  1935,     0,     0,     0,   809,     0,   809,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2319,
       0,     0,   470,     0,     0,     0,     0,     0,     0,  1873,
       0,     0,     0,     0,     0,     0,     0,     0,  2333,  2335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1977,  2343,     0,     0,     0,     0,     0,   470,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,  2003,
     626,     0,     0,     0,     0,     0,     0,   402,     0,     0,
       0,     0,  2012,     0,     0,     0,   725,     0,     0,     0,
     444,  1788,     0,   734,   735,   736,     0,     0,     0,   740,
     741,   742,   743,   744,   745,   746,     0,   747,     0,     0,
       0,     0,   748,   749,     0,     0,   752,     0,   471,     0,
       0,     0,   481,     0,     0,     0,     0,   487,     0,     0,
       0,     0,     0,     0,   492,  1873,     0,   494,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1847,     0,   503,   504,   505,     0,   507,   508,
     509,     0,   511,   512,   513,   514,   515,   516,   517,     0,
     519,   520,   521,   522,  2078,     0,     0,     0,   526,   526,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2133,   594,   596,
     598,   599,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   633,   526,   526,
       0,     0,     0,     0,     0,  1873,     0,     0,     0,   940,
       0,     0,     0,     0,     0,   651,     0,     0,     0,  2165,
       0,     0,     0,     0,     0,   661,   662,     0,     0,     0,
       0,   662,     0,     0,     0,   809,     0,     0,     0,     0,
       0,   526,   526,   685,     0,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,  1873,   704,   526,     0,   626,     0,     0,
       0,     0,     0,     0,     0,   714,     0,   716,   717,     0,
     719,     0,     0,     0,   722,   723,   724,     0,     0,   726,
       0,     0,     0,   733,  2213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   809,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,   809,   626,     0,
       0,     0,     0,     0,     0,   526,   768,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   776,   777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   810,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   841,
       0,     0,     0,     0,   846,     0,   470,   470,   850,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
       0,  1873,   864,   596,     0,     0,     0,     0,   869,     0,
       0,     0,   873,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   900,
       0,   905,   906,     0,   908,     0,     0,     0,     0,     0,
       0,  1873,     0,     0,   918,     0,     0,   922,   923,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   900,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   943,   944,   945,   946,   947,
     948,   949,   950,   951,   952,   953,   954,   955,   956,   958,
     960,   961,   962,   963,   964,     0,   966,   967,     0,     0,
       0,     0,     0,     0,   974,   975,   976,     0,     0,     0,
       0,     0,   982,   983,   984,   985,     0,   526,   526,     0,
       0,  1252,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   726,  1005,     0,
       0,     0,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,     0,     0,     0,  1269,     0,     0,  1026,  1027,     0,
    1029,     0,     0,  1031,     0,     0,     0,   526,   526,   526,
    1036,     0,     0,     0,  1040,   526,  1042,  1043,  1044,     0,
       0,  1045,     0,  1047,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1057,     0,     0,  1058,     0,   966,   967,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1071,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   526,     0,     0,    43,    44,
      45,    46,  1090,     0,     0,    48,     0,     0,     0,     0,
    1101,     0,     0,     0,   803,    57,     0,     0,    60,   804,
       0,   805,   806,     0,   807,     0,     0,     0,     0,   526,
       0,  1117,   527,   527,     0,     0,  1120,  1121,  2041,   607,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,   526,     0,  1137,  1138,     0,     0,   526,     0,   526,
    1144,  1851,     0,     0,  1137,     0,  1151,     0,  1152,     0,
      99,   100,   101,     0,  1157,     0,     0,     0,  1160,     0,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,  1181,   626,   958,  1038,  1184,     0,     0,     0,     0,
    1461,     0,   998,   597,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,   527,     0,     0,     0,     0,     0,     0,
       0,     0,   526,     0,     0,     0,     0,  1006,     0,     0,
       0,     0,   526,  1231,  1232,  1233,     0,     0,     0,     0,
       0,     0,  1239,     0,  1241,     0,     0,  1242,     0,     0,
       0,     0,     0,     0,     0,   527,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,     0,     0,   527,
       0,     0,     0,     0,     0,     0,     0,   526,     0,     0,
       0,     0,  1525,     0,     0,  1277,     0,     0,     0,  1283,
       0,     0,     0,     0,     0,  1289,     0,     0,   526,     0,
       0,     0,     0,     0,     0,     0,  1299,  1300,     0,     0,
       0,     0,  1303,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1330,     0,     0,  1332,     0,     0,     0,     0,     0,   527,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   865,   622,   623,   624,   625,  1353,
       0,  1355,  1356,   626,     0,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,  1377,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1397,     0,     0,     0,     0,     0,
       0,  1403,     0,     0,     0,     0,     0,   597,  1416,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1439,  1440,     0,     0,     0,     0,   526,     0,     0,
       0,     0,     0,   891,     0,  1654,  1655,     0,     0,     0,
       0,     0,   901,   902,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   932,     0,     0,     0,  1857,   527,     0,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,   529,     0,     0,     0,     0,     0,     0,     0,
    1494,     0,     0,   959,     0,     0,     0,     0,     0,     0,
    1495,  1496,  1497,  1498,  1499,     0,     0,     0,     0,  1501,
    1502,     0,  1503,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   527,  1972,     0,     0,  1751,     0,  1514,     0,
       0,  1517,  1518,     0,     0,  1758,     0,     0,     0,  1521,
    1522,     0,     0,     0,     0,     0,     0,     0,  1526,  1527,
       0,     0,     0,     0,  1533,  1534,     0,     0,     0,     0,
     526,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   527,   527,     0,     0,     0,     0,     0,   527,
       0,   634,   635,     0,   219,   174,     0,   399,     0,     0,
       0,   220,   221,   222,     0,  1566,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   400,   242,   243,   244,   245,   246,
     247,   248,   249,     0,   683,   684,     0,     0,     0,   527,
       0,     0,     0,     0,  1601,     0,     0,     0,     0,     0,
     255,   256,   257,   258,     0,     0,  1533,  1534,   259,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,  1617,
       0,     0,     0,   527,   264,   265,   266,     0,     0,     0,
       0,     0,     0,     0,     0,   267,    25,     0,   268,     0,
       0,     0,     0,  1633,     0,   527,     0,     0,     0,     0,
       0,   527,     0,   527,  1639,     0,     0,  1644,     0,  1898,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,   767,   607,
       0,     0,   626,     0,     0,     0,  1666,     0,     0,  1669,
     526,  1672,   526,     0,     0,     0,     0,   959,     0,  1185,
    1681,     0,     0,  1684,     0,  1681,     0,  1688,  1690,  1973,
       0,  1698,  1699,  1700,     0,     0,     0,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,   607,   527,     0,     0,   626,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,   282,
       0,     0,     0,     0,     0,   284,   285,   286,     0,   287,
     288,   289,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,   290,   401,     0,  1772,     0,     0,     0,   292,
       0,   527,     0,     0,   376,     0,  1781,  1782,  1783,     0,
       0,   295,     0,     0,     0,  1789,     0,  1791,     0,     0,
       0,     0,   527,     0,  1794,     0,   936,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   526,
       0,     0,     0,     0,     0,  1813,  1814,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1821,  1822,  1823,     0,
       0,     0,     0,     0,     0,     0,     0,  1834,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1844,     0,     0,
     988,   989,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1861,     0,
       0,     0,     0,     0,     0,     0,  1870,  1871,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,   624,   625,     0,
    1033,  1034,  1035,   626,     0,     0,     0,     0,  1041,     0,
       0,     0,  1900,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,   527,     0,     0,     0,   626,     0,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     865,   622,   623,   624,   625,  1917,  1918,  1919,  1085,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1922,
    2069,     0,     0,     0,  1925,  1926,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,  1934,     0,     0,
       0,     0,  1113,     0,   526,   526,  1942,     0,  1943,     0,
       0,     0,     0,     0,  1951,  1952,     0,     0,     0,     0,
       0,     0,     0,     0,  1135,     0,     0,     0,     0,     0,
    1141,     0,  1143,   526,     0,     0,     0,     0,     0,   526,
    1971,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1925,  1926,     0,     0,  1985,     0,     0,  1989,
       0,     0,     0,  1991,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2000,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2007,   527,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2018,     0,     0,
       0,     0,  2024,  2025,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1220,  2030,     0,     0,  2031,
    2030,     0,  2034,     0,     0,  1230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   792,     0,     0,     0,  2053,     0,
       0,     0,     0,     0,     0,     0,     0,   526,   526,     0,
       0,     0,     0,     0,  2063,  2064,     0,     0,  1262,     0,
       0,     0,     0,     0,     0,   527,  2072,     0,     0,     0,
    1270,     0,     0,     0,     0,  2081,     0,     0,     0,     0,
       0,     0,     0,     0,   596,     0,     0,     0,     0,     0,
       0,  1292,     0,     0,     0,     0,     0,  2093,  2094,     0,
       0,   726,   526,     0,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2121,  2122,     0,
       0,     0,   919,     0,   527,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2135,     7,
       8,     0,     0,   526,   526,  2140,     0,     0,     0,     0,
    2143,     0,  2145,  2098,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   970,     0,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,     0,
    2176,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1446,     0,     0,     0,     0,     0,     0,     0,  2188,     0,
       0,     0,     0,     0,  2193,     0,     0,  2194,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,  2206,     0,     0,    43,    44,    45,    46,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
    2220,   803,    57,     0,  1492,    60,   804,     0,   805,   806,
       0,   807,     0,   527,     0,  1095,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2238,  2239,     0,
      82,     0,     0,     0,  1096,     0,     0,     0,     0,     0,
       0,     0,  2245,  2246,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,   100,   101,
    2256,     0,     0,     0,     0,   526,   526,   526,   526,   526,
       0,     0,     0,     0,     0,  2024,     0,     0,     0,  2272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1538,  1539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2292,     0,     0,
       0,     0,  2295,  2296,     0,     0,  1901,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,  2323,  2324,     0,     0,     0,     0,  1190,  1191,
    1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
       0,  1203,  1204,  1205,  1206,     0,  1208,  1209,  1210,  1211,
       0,     0,     0,     0,  1615,     0,     0,     0,     0,     0,
       0,     0,  1223,     0,  1225,     0,     0,     0,   527,   527,
       0,     0,     0,     0,     0,  1235,     0,   174,   406,     0,
       0,     0,     0,     0,     0,     0,  1245,  1246,     0,     0,
       0,     0,     0,     0,     0,  1257,     0,   527,     0,     0,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,  1671,     0,  1673,   416,   417,   418,   419,
       0,     0,     0,     0,   420,   421,   422,   423,     0,     0,
       0,     0,     0,   424,     0,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   426,
       0,     0,   427,     0,     0,     0,   180,     0,     0,   181,
       0,     0,   182,     0,   183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   456,     0,  1362,  1364,  1365,
       0,   527,   527,  1369,  1370,     0,     0,  1373,  1374,  1375,
    1376,     0,  1378,     0,     0,     0,     0,  1384,     0,     0,
       0,     0,     0,     0,  2113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,     0,  1810,     0,     0,     0,     0,     0,   428,   429,
     430,  2149,     0,     0,     0,     0,     0,     0,     0,     0,
     431,     0,     0,     0,   432,     0,   433,   123,     0,     0,
       0,     0,     0,     0,  2150,  1469,     0,  1471,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,   463,     0,     0,   527,   527,     0,
    -593,     0,  1664,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,   219,   174,   406,     0,     0,     0,   527,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   400,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,  1535,     0,     0,     0,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   255,   256,   257,
     258,   416,   417,   418,   419,   259,     0,     0,     0,   420,
     421,   422,   423,     0,     0,     0,     0,     0,   424,  2232,
     425,   264,   265,   266,     0,     0,     0,  1940,  1941,     0,
       0,     0,   267,    25,   426,   268,     0,   427,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,   527,  1970,     0,  2279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
     527,   527,   527,   527,     0,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,  1653,     0,     0,     0,     0,  1054,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   428,   429,   430,   282,     0,     0,     0,
       0,     0,   284,   285,   286,   431,   287,   288,   289,   432,
       0,   433,   123,     0,     0,     0,  1692,     0,     0,     0,
    2059,  2060,     0,     0,     0,     0,     0,     0,     0,   290,
     401,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,   376,     0,     0,     0,  1689,     0,     0,   295,  1730,
    1731,  1732,  1733,  1734,  1735,  1736,     0,     0,     0,     0,
    1741,  1742,     0,     0,     0,     0,     0,  1744,     0,     0,
       0,     0,     0,  1749,     0,  2097,     0,  1753,     0,     0,
    1755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1762,     0,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,  1260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2138,  2139,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,  1261,     0,     0,  2159,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1829,     0,  1832,     0,  2169,     0,  1839,     0,  1841,     0,
       0,     0,     0,     0,     0,     0,  2179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1864,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,   219,   174,   406,     0,   455,
       0,     0,   220,   221,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   400,   242,   243,   244,   245,
     246,   247,   248,   249,  1609,     0,     0,     0,     0,     0,
       0,     0,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   255,   256,   257,   258,   416,   417,   418,   419,   259,
    2248,     0,     0,   420,   421,   422,   423,     0,     0,     0,
       0,     0,   424,  1927,   425,   264,   265,   266,  2260,  2261,
    2262,  2263,  2265,     0,     0,     0,   267,    25,   426,   268,
       0,   427,     0,     0,     0,   180,     0,     0,   181,     0,
       0,   182,     0,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,   456,     0,     0,   626,  2304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2015,     0,     0,  2016,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   457,
       0,     0,     0,     0,     0,     0,   281,   428,   429,   430,
     282,     0,     0,     0,     0,     0,   284,   285,   286,   431,
     287,   288,   289,   432,     0,   433,   123,     0,   458,   459,
     460,   461,  2050,  2051,     0,     0,     0,  2055,     0,     0,
       0,     0,     0,   290,   401,     0,     0,     0,     0,     0,
     292,     0,   462,   463,     0,   464,     0,   465,     0,     0,
       0,   466,   295,     0,     0,     0,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2102,  2103,     0,   219,     6,   406,
       0,     0,     0,     0,   220,   221,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,     0,     0,  2134,  1693,   408,   409,   410,   411,   412,
     413,   414,   415,   255,   256,   257,   258,   416,   417,   418,
     419,   259,   260,     0,     0,   420,   421,   422,   423,     0,
       0,   261,   262,   263,   424,     0,   425,   264,   265,   266,
       0,     0,     0,     0,     0,     0,     0,     0,   267,    25,
     426,   268,     0,   427,     0,     0,     0,   269,     0,     0,
     270,     0,     0,   271,     0,   272,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   273,   274,     0,     0,
     275,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,    58,    59,     0,   277,     0,   278,     0,     0,   279,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,    85,     0,     0,     0,    89,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     280,     0,     0,     0,  1947,     0,     0,     0,  1948,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,   428,
     429,   430,   282,   283,     0,     0,     0,     0,   284,   285,
     286,   431,   287,   288,   289,   432,     0,   433,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   291,     0,     0,     0,
       0,     0,   292,     0,     0,     0,     0,   376,     0,     0,
       0,  1694,     0,     0,   295,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
     219,     6,   406,   862,     0,     0,     0,   220,   221,   222,
       0,  2313,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,     0,     0,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   255,   256,   257,   258,
     416,   417,   418,   419,   259,   260,     0,     0,   420,   421,
     422,   423,     0,     0,   261,   262,   263,   424,     0,   425,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    25,   426,   268,     0,   427,     0,     0,     0,
     269,     0,     0,   270,     0,     0,   271,     0,   272,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   273,
     274,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,    58,    59,     0,   277,     0,   278,
       0,     0,   279,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    85,     0,     0,     0,    89,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   280,     0,     0,     0,  1978,     0,     0,
       0,  1979,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,   428,   429,   430,   282,   283,     0,     0,     0,
       0,   284,   285,   286,   431,   287,   288,   289,   432,     0,
     433,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   291,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     376,   219,     6,   375,   294,     0,     0,   295,   220,   221,
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
       0,     0,   626,     0,   280,     0,     0,     0,  2161,     0,
       0,     0,  2162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,   282,   283,     0,     0,
       0,     0,   284,   285,   286,     0,   287,   288,   289,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     291,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,   376,   219,     6,     0,   377,     0,   705,   295,   220,
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
     290,   525,     0,     0,     0,     0,     0,   292,     0,     0,
       0,     0,   376,   219,     6,  1797,     0,   600,     0,   295,
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
       0,   290,   291,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,   376,   219,     6,     0,   294,     0,     0,
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
       0,     0,   668,  1966,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,   670,   219,     6,     0,   338,   600,
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
     292,     0,     0,     0,     0,   293,   219,     6,     0,   294,
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
       0,   292,     0,     0,     0,     0,   376,   219,     6,     0,
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
       0,   595,     0,     0,   295,   220,   221,   222,     0,     0,
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
       0,     0,     0,   292,     0,     0,     0,     0,   376,   219,
       6,     0,     0,   600,     0,   295,   220,   221,   222,     0,
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
     626,     0,   280,     0,     0,     0,     0,     0,     0,     0,
    1202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,     0,     0,   282,   283,     0,     0,     0,     0,
     284,   285,   286,     0,   287,   288,   289,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   291,     0,
       0,     0,     0,     0,   292,     0,     0,     0,     0,   638,
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
       0,   626,     0,   280,     0,     0,     0,     0,     0,     0,
       0,  1212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   282,   283,     0,     0,     0,
       0,   284,   285,   286,     0,   287,   288,   289,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   291,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     647,   219,     6,     0,   294,     0,     0,   295,   220,   221,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     525,     0,     0,     0,     0,     0,   292,     0,     0,     0,
       0,   376,   219,     6,     0,   957,     0,  1445,   295,   220,
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
     290,   525,     0,     0,     0,     0,     0,   292,   219,     6,
       0,     0,   376,  1670,     0,   220,   221,   222,     0,   295,
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
       0,   280,     0,     0,     0,     0,     0,     0,     0,  1215,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
       0,     0,     0,   282,   283,     0,     0,     0,     0,   284,
     285,   286,     0,   287,   288,   289,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   290,   525,     0,     0,
       0,     0,     0,   292,   219,     6,     0,     0,   376,     0,
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
       0,     0,     0,     0,     0,  1216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,     0,     0,   282,
     283,     0,     0,     0,     0,   284,   285,   286,     0,   287,
     288,   289,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,   291,     0,     0,     0,     0,     0,   292,
       0,     0,     0,     0,   376,   219,     6,     0,  1805,     0,
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
       0,     0,     0,     0,     0,     0,  1221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,     0,     0,
     282,   283,     0,     0,     0,     0,   284,   285,   286,     0,
     287,   288,   289,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   668,  1966,     0,     0,     0,     0,     0,
     292,     0,     0,     0,     0,   670,   219,     6,     0,   338,
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
       0,     0,     0,     0,     0,     0,     0,  1222,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
       0,   282,   283,     0,     0,     0,     0,   284,   285,   286,
       0,   287,   288,   289,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   290,   525,     0,     0,     0,     0,
       0,   292,     0,     0,     0,     0,   376,   219,     6,     0,
       0,  2096,     0,   295,   220,   221,   222,     0,     0,   223,
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
     280,     0,     0,     0,     0,     0,     0,     0,  1224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,   282,   283,     0,     0,     0,     0,   284,   285,
     286,     0,   287,   288,   289,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   525,     0,     0,     0,
       0,     0,   292,   219,   174,   406,     0,   376,     0,     0,
     220,   221,   222,     0,   295,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   400,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   255,
     256,   257,   258,   416,   417,   418,   419,   259,     0,     0,
       0,   420,   421,   422,   423,     0,     0,     0,     0,     0,
     424,     0,   425,   264,   265,   266,     0,     0,     0,     0,
       0,     0,     0,     0,   267,    25,   426,   268,     0,   427,
     219,   174,   406,     0,     0,     0,     0,   220,   221,   222,
       0,     0,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     400,   242,   243,   244,   245,   246,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,  1693,   408,   409,
     410,   411,   412,   413,   414,   415,   255,   256,   257,   258,
     416,   417,   418,   419,   259,     0,     0,     0,   420,   421,
     422,   423,     0,     0,     0,     0,     0,   424,     0,   425,
     264,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,   267,    25,   426,   268,     0,   427,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   281,   428,   429,   430,   282,     0,
       0,     0,     0,     0,   284,   285,   286,   431,   287,   288,
     289,   432,     0,   433,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,  1983,     0,     0,     0,     0,     0,   292,     0,
       0,     0,     0,   376,     0,     0,     0,  1984,     0,     0,
     295,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1346,     0,     0,     0,     0,     0,     0,
       0,   281,   428,   429,   430,   282,     0,     0,     0,     0,
       0,   284,   285,   286,   431,   287,   288,   289,   432,     0,
     433,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,   401,
       0,     0,     0,     0,     0,   292,     0,     0,     0,     0,
     376,   219,   174,   406,  1863,     0,     0,   295,   220,   221,
     222,     0,     0,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   400,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   255,   256,   257,
     258,   416,   417,   418,   419,   259,     0,     0,     0,   420,
     421,   422,   423,     0,     0,     0,     0,     0,   424,     0,
     425,   264,   265,   266,     0,     0,     0,     0,     0,     0,
       0,     0,   267,    25,   426,   268,     0,   427,   219,   174,
       0,     0,     0,     0,     0,   220,   221,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   400,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,   258,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   265,
     266,     0,     0,     0,     0,     0,     0,     0,     0,   267,
      25,     0,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   428,   429,   430,   282,     0,     0,     0,
       0,     0,   284,   285,   286,   431,   287,   288,   289,   432,
       0,   433,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     401,     0,     0,     0,     0,     0,   292,     0,   219,   174,
       0,   376,     0,     0,     0,   220,   221,   222,   295,     0,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   400,   242,
     243,   244,   245,   246,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
       0,     0,     0,   282,   255,   256,   257,   258,     0,   284,
     285,   286,   259,   287,   288,   289,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     7,     8,   264,   265,
     266,     0,     0,     0,     0,     0,   290,   401,     0,   267,
      25,     0,   268,   292,     0,     0,     0,     0,   376,   219,
     174,     0,   650,     0,   921,   295,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   400,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,   259,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   264,
     265,   266,    43,    44,    45,    46,     0,     0,     0,    48,
     267,    25,     0,   268,     0,     0,     0,     0,   803,    57,
       0,     0,    60,   804,     0,   805,   806,     0,   807,   281,
       0,     0,     0,   282,     0,     0,     0,     0,     0,   284,
     285,   286,     0,   287,   288,   289,     0,    82,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   668,   669,     0,     0,
       0,     0,     0,   292,    99,   100,   101,     0,   670,   219,
     174,     0,   338,     0,     0,   295,   220,   221,   222,     0,
       0,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   400,
     242,   243,   244,   245,   246,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,     0,     0,     0,   282,   255,   256,   257,   258,     0,
     284,   285,   286,   259,   287,   288,   289,     0,     0,     0,
     123,  1032,     7,     8,     0,     0,     0,     0,     0,   264,
     265,   266,     0,     0,     0,     0,     0,   290,   401,     0,
     267,    25,     0,   268,   292,   219,   174,     0,  1396,   376,
       0,     0,   220,   221,   222,     0,   295,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   400,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,   259,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   264,   265,   266,    43,    44,
      45,    46,     0,     0,     0,    48,   267,    25,     0,   268,
       0,     0,     0,     0,   803,    57,     0,     0,    60,   804,
       0,   805,   806,     0,   807,     0,     0,     0,     0,     0,
     281,     0,     0,     0,   282,     0,     0,     0,     0,     0,
     284,   285,   286,    82,   287,   288,   289,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   401,     0,
      99,   100,   101,     0,   292,   219,   174,     0,  1565,   376,
    1149,     0,   220,   221,   222,     0,   295,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   400,   242,   243,   244,   245,
     246,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   281,     0,     0,     0,
     282,   255,   256,   257,   258,     0,   284,   285,   286,   259,
     287,   288,   289,     0,     0,     0,   123,  1087,     7,     8,
       0,     0,     0,     0,     0,   264,   265,   266,     0,     0,
       0,     0,     0,   290,   401,     0,   267,    25,     0,   268,
     292,   219,   174,     0,  1632,   376,     0,     0,   220,   221,
     222,     0,   295,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   400,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,   259,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,   264,   265,   266,    43,    44,    45,    46,     0,     0,
       0,    48,   267,    25,     0,   268,     0,     0,     0,     0,
     803,    57,     0,     0,    60,   804,     0,   805,   806,     0,
     807,     0,     0,     0,     0,     0,   281,     0,     0,     0,
     282,     0,     0,     0,     0,     0,   284,   285,   286,    82,
     287,   288,   289,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,   401,     0,    99,   100,   101,     0,
     292,   219,   174,     0,     0,   376,     0,     0,   220,   221,
     222,     0,   295,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   400,   242,   243,   244,   245,   246,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,   282,   255,   256,   257,
     258,     0,   284,   285,   286,   259,   287,   288,   289,     0,
       0,     0,   123,  1089,     7,     8,     0,     0,     0,     0,
       0,   264,   265,   266,     0,     0,     0,     0,     0,   290,
     401,     0,   267,    25,     0,   268,   292,   219,   174,     0,
       0,   376,     0,     0,   220,   221,   222,     0,   295,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   400,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,   259,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   264,   265,   266,
      43,    44,    45,    46,     0,     0,     0,    48,   267,    25,
       0,   268,     0,     0,     0,     0,   803,    57,     0,     0,
      60,   804,     0,   805,   806,     0,   807,     0,     0,     0,
       0,     0,   281,     0,     0,     0,   282,     0,     0,     0,
       0,     0,   284,   285,   286,    82,   287,   288,   289,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     401,     0,    99,   100,   101,     0,   292,   219,   174,     0,
       0,   376,  1686,     0,   220,   221,   222,     0,   295,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   400,   242,   243,
     244,   245,   246,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,     0,
       0,     0,   282,   255,   256,   257,   258,     0,   284,   285,
     286,   259,   287,   288,   289,     0,     0,     0,   123,  1294,
       7,     8,     0,     0,     0,     0,     0,   264,   265,   266,
       0,     0,     0,     0,     0,   290,   401,     0,   267,    25,
       0,   268,   292,   219,   174,     0,     0,   376,  2032,     0,
     220,   221,   222,     0,   295,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   400,   242,   243,   244,   245,   246,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,   259,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   264,   265,   266,    43,    44,    45,    46,
       0,     0,     0,    48,   267,    25,     0,   268,     0,     0,
       0,     0,   803,    57,     0,     0,    60,   804,     0,   805,
     806,     0,   807,     0,     0,     0,     0,     0,   281,     0,
       0,     0,   282,     0,     0,     0,     0,     0,   284,   285,
     286,    82,   287,   288,   289,     0,     0,     0,   123,     0,
       0,   174,   406,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   290,   401,     0,    99,   100,
     101,     0,   292,     0,     0,     0,     0,   376,     0,     0,
       0,  2095,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   407,   408,   409,
     410,   411,   412,   413,   414,   415,     0,     0,     0,     0,
     416,   417,   418,   419,     0,     0,     0,     0,   420,   421,
     422,   423,     0,     0,   281,     0,     0,   424,   282,   425,
       0,     0,     0,     0,   284,   285,   286,     0,   287,   288,
     289,     0,     0,   426,   123,  1296,   427,   174,   406,     0,
     180,     0,     0,   181,     0,     0,   182,     0,   183,     0,
       0,   290,   401,     0,     0,     0,     0,     0,   292,    46,
       0,     0,     0,   376,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,   417,   418,   419,
       0,     0,     0,     0,   420,   421,   422,   423,     0,     0,
       0,     0,     0,   424,     0,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   426,
       0,     0,   427,     0,     0,     0,   180,     0,     0,   181,
       0,     0,   182,     0,   183,     0,     0,     0,     0,     0,
       0,     0,   428,   429,   430,    46,     0,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,     0,   432,     0,
     433,   123,     0,     0,     0,   456,     0,     0,     0,     7,
       8,     0,     0,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,   789,     0,   790,  1863,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1372,     0,     0,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     7,     8,   626,     0,     0,     0,     0,   428,   429,
     430,     0,     0,  1455,     0,     0,     0,     0,     0,     0,
     431,     0,     0,     0,   432,     0,   433,   123,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
    1863,   803,    57,     7,     8,    60,   804,     0,   805,   806,
       0,   807,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,     0,    48,     0,     0,    99,   100,   101,
       0,     0,     0,   803,    57,     7,     8,    60,   804,     0,
     805,   806,     0,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,     0,    48,     0,     0,    99,
     100,   101,     0,     0,     0,   803,    57,     7,     8,    60,
     804,     0,   805,   806,  1297,   807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,     0,    48,     0,
       0,    99,   100,   101,     0,     0,     0,   803,    57,     7,
       8,    60,   804,     0,   805,   806,  1316,   807,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,     0,
      48,     0,     0,    99,   100,   101,     0,     0,     0,   803,
      57,     7,     8,    60,   804,     0,   805,   806,  1336,   807,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,     0,    48,     0,     0,    99,   100,   101,     0,     0,
       0,   803,    57,     7,     8,    60,   804,     0,   805,   806,
    1354,   807,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,     0,    48,     0,     0,    99,   100,   101,
       0,     0,     0,   803,    57,     0,     0,    60,   804,     0,
     805,   806,  1391,   807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,     0,    48,     0,     0,    99,
     100,   101,     0,     0,     0,   803,    57,     0,     0,    60,
     804,     0,   805,   806,  1557,   807,     0,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    82,    -4,    -4,     0,     0,     0,
       0,     0,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,    99,   100,   101,   626,     0,     0,     0,     0,    -4,
      -4,    -4,     0,     0,  1459,     0,  2223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,    -4,     0,     0,     0,     0,    -4,    -4,     0,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,  2281,     0,
      -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,     0,     0,
       0,     0,     0,     0,    -4,     0,    -4,    -4,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       9,    10,    11,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1559,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,     0,    25,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    42,    43,    44,    45,    46,     0,    47,     0,    48,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
      66,    67,    68,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,    94,    95,    96,     0,     0,     0,    97,     0,
       0,     0,     0,    98,    99,   100,   101,   174,   406,   102,
       0,   103,     0,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,   407,   408,   409,   410,   411,   412,   413,
     414,   415,     0,     0,     0,     0,   416,   417,   418,   419,
     174,   406,     0,     0,   420,   421,   422,   423,     0,     0,
       0,     0,     0,   424,     0,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   426,
       0,     0,   427,     0,     0,     0,   180,   437,   406,   181,
       0,     0,   182,     0,   183,     0,   407,   408,   409,   410,
     411,   412,   413,   414,   415,    46,     0,     0,     0,   416,
     417,   418,   419,     0,     0,     0,     0,   420,   421,   422,
     423,     0,     0,     0,     0,   456,   424,     0,   425,     0,
       0,     0,     0,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   426,     0,     0,   427,   416,   417,   418,   419,
       0,     0,     0,     0,   420,   421,   422,   423,     0,     0,
       0,     0,     0,   424,     0,   425,     0,     0,     0,     0,
       0,     0,     0,   406,     0,     0,     0,     0,     0,   426,
       0,     0,   427,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,   428,   429,
     430,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     431,     0,     0,     0,   432,     0,   433,   123,   407,   408,
     409,   410,   411,   412,   413,   414,   415,     0,     0,     0,
       0,   416,   417,   418,   419,     0,     0,     0,     0,   420,
     421,   422,   423,     0,     0,     0,     0,     0,   424,     0,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   428,   429,   430,   426,     0,     0,   427,     0,     0,
       0,     0,     0,   431,     0,     0,     0,   432,     0,   433,
     123,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   428,   429,
     430,    43,    44,    45,    46,     0,     0,     0,    48,     0,
     431,     0,     0,     0,   432,     0,   433,   803,    57,     0,
       0,    60,   804,     0,   805,   806,     0,   807,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,    82,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1560,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,   428,   429,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,     0,   432,
       0,   433,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1608,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1737,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1738,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1739,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1891,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2019,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2020,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2052,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2129,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2144,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2189,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2190,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2205,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2241,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2269,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2274,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2275,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1130,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1188,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1237,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  1238,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  1286,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1319,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1334,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1341,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1402,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1422,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1458,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1508,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1509,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  1510,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  1513,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  1515,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  1516,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  1561,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  1638,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  1746,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  1945,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    1956,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1999,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  2075,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  2091,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  2106,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  2130,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  2167,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,     0,  2177,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
       0,     0,  2178,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,  2203,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,     0,     0,
    2207,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  2247,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,     0,     0,  2255,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,  2294,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,  2312,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,     0,     0,  2330,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,     0,     0,  2331,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,     0,   765,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,     0,
     990,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,     0,  2068,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,   789,     0,   790,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,  1061,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,  1106,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,  1265,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,  1335,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
    1337,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,     0,     0,  1344,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   728,   622,   623,   624,   625,     0,     0,     0,     0,
     626,     0,     0,     0,  1345,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   728,   622,
     623,   624,   625,     0,     0,     0,     0,   626,     0,     0,
       0,  1437,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   728,   622,   623,   624,   625,
       0,     0,     0,     0,   626,     0,     0,     0,  1451,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   728,   622,   623,   624,   625,     0,     0,     0,
       0,   626,     0,     0,     0,  1667,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
       0,     0,  1761,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   728,   622,   623,   624,
     625,     0,     0,     0,     0,   626,     0,     0,     0,  1815,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   728,   622,   623,   624,   625,     0,     0,
       0,     0,   626,     0,     0,     0,  2011,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     728,   622,   623,   624,   625,     0,     0,     0,     0,   626,
       0,     0,     0,  2058,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   728,   622,   623,
     624,   625,     0,     0,     0,     0,   626,     0,     0,     0,
    2076,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   843,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     844,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   845,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     847,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   848,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     849,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   851,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     852,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   853,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     854,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   855,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     856,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   857,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     859,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   860,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     861,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,   937,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
     971,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1021,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1038,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1046,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1048,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1049,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1055,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1056,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1094,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1105,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1166,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1170,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1182,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1264,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1274,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1275,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1276,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1285,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1287,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1288,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1318,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1320,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1321,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1322,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1323,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1324,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1325,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1326,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1333,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1347,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1349,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1390,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1436,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1450,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1668,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1704,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1748,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1760,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1878,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1880,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1883,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1890,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1946,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  1955,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    1982,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2057,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    2127,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2128,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626,     0,
    2268,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   728,   622,   623,   624,   625,     0,
       0,     0,     0,   626,     0,  2309,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   728,
     622,   623,   624,   625,     0,     0,     0,     0,   626
};

static const yytype_int16 yycheck[] =
{
       3,  1520,   168,     3,  1313,   150,  1799,   331,   665,   666,
       9,  1317,   164,     5,  1846,   786,  1848,     4,    97,    64,
       5,   792,    25,     4,     4,     4,   113,     4,   115,    25,
       6,     4,     6,  1835,     5,   109,  2035,     6,     4,     4,
     146,     4,     6,     5,    68,     4,     9,   264,     6,     6,
     103,     0,   109,    56,   109,   272,     4,     7,     6,     6,
     264,   109,     6,   150,     6,     4,     6,   168,   272,   122,
       4,     4,   106,     4,   109,   109,   110,   111,   266,   103,
     135,     4,     9,    86,   272,     7,     7,   135,   122,    92,
       9,   263,   179,   199,    97,   196,  1898,   264,   185,   102,
     251,   252,   146,    26,    14,   272,     9,   263,    95,   265,
     113,   212,   213,     9,    37,    38,   272,   268,   264,   251,
     252,   165,  1915,   263,     9,   466,   272,   206,   251,   252,
     251,   252,   176,   177,   178,   264,     6,   216,   182,   183,
     272,   251,   252,   272,     6,   106,   267,   150,   109,   272,
       4,   151,   155,   156,   157,   103,     7,   191,   266,     6,
     264,   164,   272,     7,   272,   269,    70,    71,     7,    73,
     264,     6,    26,     6,   251,   252,     6,   343,   272,   251,
     252,   251,   252,    37,    38,   151,   152,   153,   154,   263,
     263,   157,   158,   125,     7,   272,   172,   363,   201,  2198,
     272,   167,   272,   206,     7,   171,   263,   210,   211,     6,
     184,   251,   252,   216,   217,   218,   261,   262,   263,   109,
     207,   111,   260,   261,   268,   264,   184,   186,   187,   188,
     189,   269,   272,   272,  1753,   280,   315,   316,   317,   198,
       6,   200,   201,   202,   203,   204,   211,   234,   269,   208,
     209,   272,   211,   106,   234,   234,   109,   234,   112,   113,
       6,   234,   260,   261,   263,   263,   265,   265,  1577,   122,
     269,   234,  2065,   276,   440,   267,   442,   356,   357,   358,
     267,   267,   267,   449,   265,   271,   267,   267,   291,   630,
     271,   294,   295,   270,   267,   374,   267,   260,   261,   295,
     263,   234,   265,   267,   267,   267,   269,   310,   311,   268,
     267,   314,   315,   316,   317,   236,   237,   238,   239,   269,
     267,   263,   325,   267,   263,   267,   329,   267,   331,   263,
    2123,   264,   263,   266,  1105,  1106,   263,   263,   265,   260,
     261,   263,   269,   265,   263,   263,   265,   265,   269,   267,
     353,   354,   267,   356,   357,   358,   106,   260,   261,   109,
     263,   111,   265,   266,   260,   261,   269,   263,   455,   265,
       6,   374,   122,   269,   377,   260,   261,     6,   263,   263,
     265,   251,   252,   267,   269,   236,   237,   238,   239,   251,
     252,   732,   236,   237,   238,   239,   265,   236,   237,   238,
     239,   260,   261,  2235,   251,   252,   251,   252,   267,   260,
     261,   246,   247,   246,   247,   106,   260,   261,   109,   571,
     111,   260,   261,   236,   237,   238,   239,   272,   260,   261,
     334,   335,     4,   236,   237,   238,   239,   264,   342,   343,
       8,     4,   445,     4,   447,   272,   251,   252,   451,   452,
     265,   150,   264,   263,    26,   265,   155,   156,   157,   800,
     272,     4,   263,    26,   467,    37,    38,   272,   251,   252,
     263,   474,   265,     8,    37,    38,   817,   263,  2271,   264,
     146,   266,   263,    26,   251,   252,   827,   272,   654,   272,
     656,   657,     6,     7,    37,    38,   499,   251,   252,   165,
     267,   146,   201,   251,   252,   592,   585,   673,   251,   252,
     176,   177,   178,    13,    14,   267,   182,   183,   272,   218,
     165,   263,   525,   263,   272,   267,   263,   693,  2321,   272,
    1187,   176,   177,   178,   263,   263,  2055,   182,   183,   267,
     112,   113,   103,   264,   263,   266,   107,   263,   551,   112,
     113,   272,   113,   114,   720,   116,   117,   560,   561,   251,
     252,   269,   565,   271,   567,   568,   569,   570,   571,   112,
     113,   109,   251,   252,   577,   251,   252,   264,   139,   266,
     272,   584,   585,   586,   736,   588,   589,   590,   591,   263,
     593,   265,   595,   272,     4,   591,   272,   593,   939,   765,
     263,     8,   268,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    26,   263,   621,   119,
     120,   121,   122,   268,   627,   263,   126,    37,    38,   251,
     252,   251,   252,   196,   197,   135,   136,   251,   252,   139,
     140,   786,   142,   143,   263,   145,   649,   650,   251,   252,
     272,     6,   272,   196,   197,   264,   268,   266,   272,   264,
     272,   266,   749,   272,   164,   665,   666,   272,   263,   272,
    1327,  1328,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       6,   191,   192,   193,   262,   268,   699,   700,   701,   272,
     268,   263,   112,   113,   707,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   263,   251,   252,   729,   262,     4,   264,
       6,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     267,   744,   745,   746,   747,   748,   445,   750,   751,   752,
     753,   754,     3,   263,   757,   842,   267,   753,     7,   663,
     664,   806,   251,   252,   668,   146,  1107,   263,   268,   251,
     252,   264,   775,   266,   103,  1546,    27,   106,   111,   272,
     109,   268,   111,   272,   165,   272,   103,   268,   791,   106,
     272,   272,   109,   122,   797,   176,   177,   178,   263,   267,
     265,   182,   183,   251,   252,   122,   251,   252,   251,   252,
     813,   814,    63,   268,   267,   263,   819,   272,   821,   267,
     263,   824,   825,   968,   267,   256,   257,   267,   994,   109,
     833,   262,   835,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   264,   263,   266,   267,   262,   253,   254,   255,   256,
     257,   268,   865,   106,   867,   262,   565,   118,   567,   267,
     569,   570,  1643,   151,   152,   263,    56,   265,   267,   157,
     267,   269,  1653,   267,   272,   151,   152,   268,   268,   588,
     589,   157,   272,   146,   981,   260,   261,   263,   263,   150,
     265,   904,   267,   109,   155,   156,   157,  1248,   106,  1250,
     268,   914,   165,   164,   272,  1060,   260,   261,  2224,   263,
       6,   265,  1263,   176,   177,   178,   109,   106,   263,   182,
     183,   251,   252,   253,   254,   255,   256,   257,   941,     4,
     268,   268,   262,   268,   272,   272,   109,   272,  2257,   268,
     201,     4,  1293,   272,   957,   268,     4,     4,   268,   272,
    1105,  1106,   272,   263,   268,   268,   969,   218,   272,   272,
     264,   263,   266,   267,   146,   978,  2282,  1122,   268,   268,
     268,   268,   272,   272,   272,   272,     6,   990,   265,   263,
    2299,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   260,
     268,   268,     6,   262,   272,   272,  1357,   265,     6,  1360,
    1361,   268,  1109,   267,     6,   272,   268,   278,   279,   268,
     272,   268,   267,   272,   263,   272,   735,   217,   737,   738,
     739,   740,   741,   742,  1385,   744,   745,   746,   747,   271,
     268,   750,   751,   752,   272,   271,   268,   268,   268,     6,
     272,   272,   272,     9,   263,   267,   263,  1408,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   263,   268,  1412,   263,
     262,   272,   263,   997,  1435,   268,   276,  1100,   268,   272,
    1004,   199,   272,   268,  1008,  1108,   268,   272,  1449,   267,
     272,   263,   268,  1116,   268,  1456,   272,   268,   272,  1264,
    1265,   272,   109,   135,   199,   824,  1129,  1784,  1785,   268,
     267,  1134,   199,   272,   314,   268,   835,   268,   268,   272,
     268,   272,   272,   268,   272,   325,   268,   272,   268,   329,
     272,   268,   272,   268,   268,   272,   268,   272,   272,   268,
     272,  1164,  1165,   272,  1167,  1168,  1169,   263,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,   268,   268,
    1183,   268,   272,   272,   268,   272,   268,  1187,   272,   268,
     272,   268,   268,   272,   445,   272,   272,   268,   268,   268,
     268,   272,   272,   272,   272,   456,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   263,  1226,  1227,  1228,   262,   478,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   263,   493,   199,   263,   262,   267,   263,   263,   263,
     263,     4,  1255,     7,     6,   263,   267,   267,   267,  1163,
     267,   263,   263,   263,   263,   263,   263,     6,  1271,  1272,
    1273,   451,   452,   265,     6,     6,   267,   267,   267,     6,
     263,   267,   267,   267,   265,   265,   265,   467,   263,   199,
     263,  1436,  1437,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   263,   263,   263,   565,   262,   567,   265,   569,   570,
     571,   263,  1646,   263,     6,     6,  1329,  1327,  1328,   267,
       6,     8,     6,     8,   263,   267,     7,   588,   589,     6,
     267,   267,     6,   267,   272,  1348,   268,  1350,  1351,    98,
     264,   272,     7,     6,     6,   264,   267,   269,    68,   267,
    1363,   267,   267,   267,   267,  1368,   267,   267,   262,  1372,
       8,     7,     7,  1460,   263,  1462,   264,     6,  1381,     7,
    1383,   267,     7,  1386,     8,     6,     6,     6,   568,   268,
     196,   267,   264,   268,   268,   266,  1399,     6,   267,   269,
       7,     6,   265,   263,   584,   267,   586,     6,     6,  1412,
       6,     6,     6,   264,  2071,   265,     7,     7,     7,     7,
     671,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   267,  1437,  1134,     6,   264,   266,  1442,
     272,  1444,   272,   272,   268,   696,   267,   272,   264,     7,
     268,     7,   269,   267,   267,     4,     6,   269,   268,  1462,
     268,   146,   267,   267,     7,  1631,     6,   269,     7,  1635,
       7,     7,  1475,   269,   264,   264,  1479,   272,     6,   272,
       9,   272,   264,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   266,   744,   745,   746,   747,   199,  1643,   750,
     751,   752,  1654,  1655,   271,     7,   168,   268,   267,   760,
       6,  1852,   763,     6,     6,    50,    50,   263,   769,   269,
     267,   263,   267,   263,     7,   269,   269,   263,  1227,  1228,
       7,     7,     7,   199,   272,   264,  1860,  1540,  1541,  1542,
    1627,     7,     7,     6,   264,  1548,  1549,  1550,   272,     7,
       7,     7,     7,     7,   805,   121,   807,     4,   267,   263,
       6,   267,     7,     6,  1567,     7,     7,     7,     7,     7,
       7,     7,   103,   824,     6,  1578,     6,     6,     6,   109,
       7,     7,     6,  1586,   835,     7,     7,     4,  1591,   272,
     270,   264,     6,   272,     6,   775,   268,   267,   267,  1602,
       6,  1604,  1689,     7,   267,     6,   265,     6,     6,   263,
     267,     6,   263,     6,  1759,     6,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   268,     6,   269,     6,   262,   266,
     264,   272,   266,  1646,     6,     6,     6,     6,   139,     6,
       6,  1654,  1655,     6,     6,     6,     6,  1660,     6,     6,
       6,     6,     5,   264,   268,   126,   199,   264,     6,  1368,
       6,     4,  1576,  1372,     6,  1678,     7,     6,   195,     7,
     267,     6,  1381,     6,  1383,     6,  1689,  1386,     6,     6,
       6,  1694,     6,  1780,   267,   267,   267,   265,   267,     7,
     267,     6,   267,   267,   267,   267,   267,     6,   268,   268,
     267,  1863,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     272,   272,     6,     6,   262,   267,     4,   264,  1437,     6,
     263,  1828,   993,   267,   995,   996,   272,   272,  1835,  1836,
     269,   267,   263,   268,   263,     7,     6,     6,  1009,     6,
     146,   941,     6,   107,     5,   264,   267,  1854,  1771,     6,
     267,     6,   109,  1776,  1777,     6,   146,   272,   267,  1030,
     267,   146,   272,     6,  1784,  1785,  2110,     6,     6,     6,
       6,     6,   272,   264,   272,     6,  1799,     6,   978,     6,
     272,  1052,  1805,  1707,     6,   267,     6,   267,  1811,     6,
       6,     6,     5,     7,   267,   150,     6,  1820,   267,   267,
       6,     6,     6,   267,     6,   197,     7,  1830,     6,     6,
    1833,   264,   267,   267,     6,     6,   267,     7,     6,   194,
    1091,     6,     6,   268,     6,   268,  1849,   267,   264,   268,
    1853,   269,     6,   268,     6,   268,   267,  1860,   268,  1862,
    1863,     6,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
       6,   264,     6,  1134,   262,   267,   264,     6,   266,     6,
     267,     6,   268,   268,   272,  1898,  1800,  1801,  1802,  1803,
    1804,  1805,     6,   267,   267,   263,     6,     6,   146,     6,
     264,  1998,  1915,     6,  2080,     6,     6,     6,   267,     6,
    1100,     6,     6,   264,     6,   267,  1929,  1930,   268,   268,
       6,     6,     6,   267,     6,     6,  1116,   267,     6,     6,
       6,   268,     6,   267,     6,   267,     6,   267,  2237,  1448,
     496,  1954,  1511,     6,  2041,  1702,  2036,  1474,  1767,  1996,
       3,  1118,     3,  1966,   582,     3,     3,  2067,  1624,     3,
    1853,  1835,  1655,    -1,   642,   824,  1227,  1228,    -1,  1678,
      -1,  1984,    -1,    -1,  1164,  1165,    -1,  1167,  1168,  1169,
      -1,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,
    1180,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,  2183,    -1,  2022,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2037,    -1,    -1,    -1,    -1,  2042,
      -1,    -1,  2045,  2046,  1295,    -1,  1226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2225,
      -1,    -1,  2065,    -1,    -1,  2068,    -1,    -1,    -1,    -1,
      -1,  2071,    -1,    -1,    -1,  1255,  2079,    -1,    -1,    -1,
    2083,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1271,  2095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2110,     6,    -1,
      -1,    -1,  2199,    -1,    -1,    -1,    -1,  1368,    -1,    -1,
    2123,  1372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1381,  1830,  1383,    -1,  1833,  1386,    -1,    -1,    -1,    -1,
      -1,    -1,  1393,    -1,    -1,    -1,    -1,    -1,    -1,  1329,
      -1,  2154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1348,    -1,
    1350,  1351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2084,  2085,  2086,  2087,  2088,    -1,  1437,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,     6,  2209,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1399,
      -1,    -1,    -1,    -1,  2227,  2228,  2229,  2230,  2231,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,     6,    -1,  2153,
      -1,   262,    -1,  2157,    -1,    -1,    -1,   268,    -1,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,  2271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1462,    -1,  2287,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1475,    -1,    -1,    -1,  1479,
      -1,    -1,    -1,    -1,    -1,  2308,    -1,  2211,    -1,    -1,
      -1,  2215,    26,    -1,    28,    -1,    -1,    -1,  2321,    -1,
      -1,    -1,    -1,    -1,  2327,  2328,    -1,  2231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2340,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
    1540,  1541,  1542,    -1,   262,    -1,    -1,    -1,  1548,  1549,
    1550,    -1,    -1,  2277,  2278,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1567,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1578,    -1,
      -1,    -1,    -1,  1654,  1655,    -1,  1586,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1602,    -1,  1604,    -1,    -1,  1678,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1660,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,  1689,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   257,   258,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,   267,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1830,
      -1,    -1,  1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,    -1,  1846,    -1,  1848,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2308,
      -1,    -1,  1863,    -1,    -1,    -1,    -1,    -1,    -1,  1799,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2327,  2328,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1820,  2340,    -1,    -1,    -1,    -1,    -1,  1898,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,  1849,
     262,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,  1862,    -1,    -1,    -1,   400,    -1,    -1,    -1,
     122,     6,    -1,   407,   408,   409,    -1,    -1,    -1,   413,
     414,   415,   416,   417,   418,   419,    -1,   421,    -1,    -1,
      -1,    -1,   426,   427,    -1,    -1,   430,    -1,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,   166,  1915,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,   186,   187,   188,    -1,   190,   191,
     192,    -1,   194,   195,   196,   197,   198,   199,   200,    -1,
     202,   203,   204,   205,  1954,    -1,    -1,    -1,   210,   211,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2037,   290,   291,
     292,   293,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,   310,   311,
      -1,    -1,    -1,    -1,    -1,  2065,    -1,    -1,    -1,   603,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,  2079,
      -1,    -1,    -1,    -1,    -1,   337,   338,    -1,    -1,    -1,
      -1,   343,    -1,    -1,    -1,  2166,    -1,    -1,    -1,    -1,
      -1,   353,   354,   355,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,  2123,   376,   377,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   387,    -1,   389,   390,    -1,
     392,    -1,    -1,    -1,   396,   397,   398,    -1,    -1,   401,
      -1,    -1,    -1,   405,  2154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2235,    -1,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,  2258,   262,    -1,
      -1,    -1,    -1,    -1,    -1,   447,   448,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   464,   465,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   479,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,
      -1,    -1,    -1,    -1,   506,    -1,  2327,  2328,   510,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2340,
      -1,  2271,   524,   525,    -1,    -1,    -1,    -1,   530,    -1,
      -1,    -1,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
      -1,   563,   564,    -1,   566,    -1,    -1,    -1,    -1,    -1,
      -1,  2321,    -1,    -1,   576,    -1,    -1,   579,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,
      -1,    -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,    -1,   628,   629,    -1,    -1,
      -1,    -1,    -1,    -1,   636,   637,   638,    -1,    -1,    -1,
      -1,    -1,   644,   645,   646,   647,    -1,   649,   650,    -1,
      -1,   935,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   668,   669,   670,    -1,
      -1,    -1,   674,   675,   676,   677,   678,   679,   680,   681,
     682,    -1,    -1,    -1,   968,    -1,    -1,   689,   690,    -1,
     692,    -1,    -1,   695,    -1,    -1,    -1,   699,   700,   701,
     702,    -1,    -1,    -1,   706,   707,   708,   709,   710,    -1,
      -1,   713,    -1,   715,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   725,    -1,    -1,   728,    -1,   730,   731,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   743,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   757,    -1,    -1,   119,   120,
     121,   122,   764,    -1,    -1,   126,    -1,    -1,    -1,    -1,
     772,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,   140,
      -1,   142,   143,    -1,   145,    -1,    -1,    -1,    -1,   791,
      -1,   793,   210,   211,    -1,    -1,   798,   799,     7,     8,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   813,    -1,   815,   816,    -1,    -1,   819,    -1,   821,
     822,     6,    -1,    -1,   826,    -1,   828,    -1,   830,    -1,
     191,   192,   193,    -1,   836,    -1,    -1,    -1,   840,    -1,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,   863,   262,   865,   264,   867,    -1,    -1,    -1,    -1,
    1154,    -1,   272,   291,    -1,    -1,   294,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   310,   311,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   904,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,   914,   915,   916,   917,    -1,    -1,    -1,    -1,
      -1,    -1,   924,    -1,   926,    -1,    -1,   929,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,   354,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   957,    -1,    -1,    -1,   377,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,
      -1,    -1,  1256,    -1,    -1,   977,    -1,    -1,    -1,   981,
      -1,    -1,    -1,    -1,    -1,   987,    -1,    -1,   990,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   998,   999,    -1,    -1,
      -1,    -1,  1004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1022,    -1,    -1,  1025,    -1,    -1,    -1,    -1,    -1,   447,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,  1051,
      -1,  1053,  1054,   262,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,  1076,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1096,    -1,    -1,    -1,    -1,    -1,
      -1,  1103,    -1,    -1,    -1,    -1,    -1,   525,  1110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1123,  1124,    -1,    -1,    -1,    -1,  1129,    -1,    -1,
      -1,    -1,    -1,   551,    -1,  1419,  1420,    -1,    -1,    -1,
      -1,    -1,   560,   561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   590,    -1,    -1,    -1,     6,   595,    -1,    -1,
      -1,  1183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1202,    -1,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,
    1212,  1213,  1214,  1215,  1216,    -1,    -1,    -1,    -1,  1221,
    1222,    -1,  1224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   649,   650,     6,    -1,    -1,  1520,    -1,  1240,    -1,
      -1,  1243,  1244,    -1,    -1,  1529,    -1,    -1,    -1,  1251,
    1252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1260,  1261,
      -1,    -1,    -1,    -1,  1266,  1267,    -1,    -1,    -1,    -1,
    1272,  1273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   699,   700,   701,    -1,    -1,    -1,    -1,    -1,   707,
      -1,   310,   311,    -1,     3,     4,    -1,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,  1307,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,   353,   354,    -1,    -1,    -1,   757,
      -1,    -1,    -1,    -1,  1346,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,  1358,  1359,    67,    -1,
      -1,  1363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1371,
      -1,    -1,    -1,   791,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,  1395,    -1,   813,    -1,    -1,    -1,    -1,
      -1,   819,    -1,   821,  1406,    -1,    -1,  1409,    -1,  1693,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   447,     8,
      -1,    -1,   262,    -1,    -1,    -1,  1438,    -1,    -1,  1441,
    1442,  1443,  1444,    -1,    -1,    -1,    -1,   865,    -1,   867,
    1452,    -1,    -1,  1455,    -1,  1457,    -1,  1459,  1460,     6,
      -1,  1463,  1464,  1465,    -1,    -1,    -1,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,     8,   904,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,   914,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,
     229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   957,
      -1,    -1,   251,   252,    -1,  1547,    -1,    -1,    -1,   258,
      -1,   969,    -1,    -1,   263,    -1,  1558,  1559,  1560,    -1,
      -1,   270,    -1,    -1,    -1,  1567,    -1,  1569,    -1,    -1,
      -1,    -1,   990,    -1,  1576,    -1,   595,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1591,
      -1,    -1,    -1,    -1,    -1,  1597,  1598,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1608,  1609,  1610,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1619,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1629,    -1,    -1,
     649,   650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1650,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1658,  1659,    -1,    -1,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     699,   700,   701,   262,    -1,    -1,    -1,    -1,   707,    -1,
      -1,    -1,  1694,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,  1129,    -1,    -1,    -1,   262,    -1,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,  1737,  1738,  1739,   757,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1751,
       6,    -1,    -1,    -1,  1756,  1757,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1183,    -1,  1769,    -1,    -1,
      -1,    -1,   791,    -1,  1776,  1777,  1778,    -1,  1780,    -1,
      -1,    -1,    -1,    -1,  1786,  1787,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   813,    -1,    -1,    -1,    -1,    -1,
     819,    -1,   821,  1805,    -1,    -1,    -1,    -1,    -1,  1811,
    1812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1824,  1825,    -1,    -1,  1828,    -1,    -1,  1831,
      -1,    -1,    -1,  1835,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1845,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1855,  1272,  1273,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1869,    -1,    -1,
      -1,    -1,  1874,  1875,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   904,  1888,    -1,    -1,  1891,
    1892,    -1,  1894,    -1,    -1,   914,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   469,    -1,    -1,    -1,  1920,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1929,  1930,    -1,
      -1,    -1,    -1,    -1,  1936,  1937,    -1,    -1,   957,    -1,
      -1,    -1,    -1,    -1,    -1,  1363,  1948,    -1,    -1,    -1,
     969,    -1,    -1,    -1,    -1,  1957,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1966,    -1,    -1,    -1,    -1,    -1,
      -1,   990,    -1,    -1,    -1,    -1,    -1,  1979,  1980,    -1,
      -1,  1983,  1984,    -1,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2019,  2020,    -1,
      -1,    -1,   577,    -1,  1442,    -1,  1444,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2040,    13,
      14,    -1,    -1,  2045,  2046,  2047,    -1,    -1,    -1,    -1,
    2052,    -1,  2054,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2068,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   632,    -1,    -1,
      -1,  2083,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2092,    -1,    -1,  2095,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2120,    -1,
      -1,    -1,    -1,    -1,  2126,    -1,    -1,  2129,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,  2144,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2162,   135,   136,    -1,  1183,   139,   140,    -1,   142,   143,
      -1,   145,    -1,  1591,    -1,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2189,  2190,    -1,
     164,    -1,    -1,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2204,  2205,    -1,    -1,    -1,  2209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,   192,   193,
    2222,    -1,    -1,    -1,    -1,  2227,  2228,  2229,  2230,  2231,
      -1,    -1,    -1,    -1,    -1,  2237,    -1,    -1,    -1,  2241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1272,  1273,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2269,    -1,    -1,
      -1,    -1,  2274,  2275,    -1,    -1,  1694,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2287,    -1,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,  2314,  2315,    -1,    -1,    -1,    -1,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,   884,
      -1,   886,   887,   888,   889,    -1,   891,   892,   893,   894,
      -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   907,    -1,   909,    -1,    -1,    -1,  1776,  1777,
      -1,    -1,    -1,    -1,    -1,   920,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   931,   932,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   940,    -1,  1805,    -1,    -1,
      -1,    -1,    -1,  1811,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,  1442,    -1,  1444,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,  1062,  1063,  1064,
      -1,  1929,  1930,  1068,  1069,    -1,    -1,  1072,  1073,  1074,
    1075,    -1,  1077,    -1,    -1,    -1,    -1,  1082,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1966,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1984,    -1,    -1,    -1,
      -1,    -1,  1591,    -1,    -1,    -1,    -1,    -1,   215,   216,
     217,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   231,    -1,   233,   234,    -1,    -1,
      -1,    -1,    -1,    -1,     6,  1160,    -1,  1162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   261,    -1,    -1,  2045,  2046,    -1,
     267,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2068,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2083,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,  2095,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,  1269,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,     6,
      82,    83,    84,    85,    -1,    -1,    -1,  1776,  1777,    -1,
      -1,    -1,    94,    95,    96,    97,    -1,    99,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,  2209,  1811,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2227,
    2228,  2229,  2230,  2231,    -1,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,  1418,    -1,    -1,    -1,    -1,     8,  2287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,   233,   234,    -1,    -1,    -1,  1461,    -1,    -1,    -1,
    1929,  1930,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,   267,    -1,    -1,   270,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,    -1,    -1,    -1,    -1,
    1505,  1506,    -1,    -1,    -1,    -1,    -1,  1512,    -1,    -1,
      -1,    -1,    -1,  1518,    -1,  1984,    -1,  1522,    -1,    -1,
    1525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1536,    -1,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2045,  2046,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,     8,    -1,    -1,  2068,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1615,    -1,  1617,    -1,  2083,    -1,  1621,    -1,  1623,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2095,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1654,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    2209,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,  1758,    82,    83,    84,    85,  2227,  2228,
    2229,  2230,  2231,    -1,    -1,    -1,    94,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   142,    -1,    -1,   262,  2287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1865,    -1,    -1,  1868,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,    -1,    -1,    -1,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,    -1,   233,   234,    -1,   236,   237,
     238,   239,  1917,  1918,    -1,    -1,    -1,  1922,    -1,    -1,
      -1,    -1,    -1,   251,   252,    -1,    -1,    -1,    -1,    -1,
     258,    -1,   260,   261,    -1,   263,    -1,   265,    -1,    -1,
      -1,   269,   270,    -1,    -1,    -1,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1989,  1990,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,  2038,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,   137,   138,    -1,   140,    -1,   142,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,   162,   163,    -1,    -1,
      -1,   167,    -1,    -1,    -1,   171,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
     196,    -1,    -1,    -1,   268,    -1,    -1,    -1,   272,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,    -1,   233,   234,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,   267,    -1,    -1,   270,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
       3,     4,     5,   268,    -1,    -1,    -1,    10,    11,    12,
      -1,  2296,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    77,    78,    79,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,
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
      -1,   214,   215,   216,   217,   218,   219,    -1,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
     233,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,     3,     4,     5,   267,    -1,    -1,   270,    10,    11,
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
      -1,   263,     3,     4,    -1,   267,    -1,     8,   270,    10,
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
      -1,    -1,   263,     3,     4,     5,    -1,   268,    -1,   270,
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
      -1,    -1,    -1,    -1,   263,     3,     4,    -1,   267,   268,
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
      -1,   267,    -1,    -1,   270,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   263,     3,
       4,    -1,    -1,   268,    -1,   270,    10,    11,    12,    -1,
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
     262,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   263,     3,     4,    -1,   267,    -1,     8,   270,    10,
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
     251,   252,    -1,    -1,    -1,    -1,    -1,   258,     3,     4,
      -1,    -1,   263,     8,    -1,    10,    11,    12,    -1,   270,
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
      -1,    -1,    -1,   258,     3,     4,    -1,    -1,   263,    -1,
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
      -1,    -1,    -1,    -1,   263,     3,     4,    -1,   267,    -1,
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
      -1,   268,    -1,   270,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   258,     3,     4,     5,    -1,   263,    -1,    -1,
      10,    11,    12,    -1,   270,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,    -1,   233,   234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,   267,    -1,    -1,
     270,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,    -1,
     233,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,     3,     4,     5,   267,    -1,    -1,   270,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    -1,    99,     3,     4,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
      -1,   233,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,    -1,    -1,    -1,    -1,   258,    -1,     3,     4,
      -1,   263,    -1,    -1,    -1,    10,    11,    12,   270,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,   218,    59,    60,    61,    62,    -1,   224,
     225,   226,    67,   228,   229,   230,    -1,    -1,    -1,   234,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    94,
      95,    -1,    97,   258,    -1,    -1,    -1,    -1,   263,     3,
       4,    -1,   267,    -1,     8,   270,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    83,
      84,    85,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,   135,   136,
      -1,    -1,   139,   140,    -1,   142,   143,    -1,   145,   214,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,   224,
     225,   226,    -1,   228,   229,   230,    -1,   164,    -1,   234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    -1,
      -1,    -1,    -1,   258,   191,   192,   193,    -1,   263,     3,
       4,    -1,   267,    -1,    -1,   270,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,   218,    59,    60,    61,    62,    -1,
     224,   225,   226,    67,   228,   229,   230,    -1,    -1,    -1,
     234,   268,    13,    14,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,
      94,    95,    -1,    97,   258,     3,     4,    -1,     6,   263,
      -1,    -1,    10,    11,    12,    -1,   270,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      -1,    -1,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    83,    84,    85,   119,   120,
     121,   122,    -1,    -1,    -1,   126,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,   140,
      -1,   142,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,
     214,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
     224,   225,   226,   164,   228,   229,   230,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,
     191,   192,   193,    -1,   258,     3,     4,    -1,     6,   263,
     264,    -1,    10,    11,    12,    -1,   270,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
     218,    59,    60,    61,    62,    -1,   224,   225,   226,    67,
     228,   229,   230,    -1,    -1,    -1,   234,   268,    13,    14,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,   251,   252,    -1,    94,    95,    -1,    97,
     258,     3,     4,    -1,     6,   263,    -1,    -1,    10,    11,
      12,    -1,   270,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    83,    84,    85,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
     135,   136,    -1,    -1,   139,   140,    -1,   142,   143,    -1,
     145,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,   224,   225,   226,   164,
     228,   229,   230,    -1,    -1,    -1,   234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   252,    -1,   191,   192,   193,    -1,
     258,     3,     4,    -1,    -1,   263,    -1,    -1,    10,    11,
      12,    -1,   270,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,    59,    60,    61,
      62,    -1,   224,   225,   226,    67,   228,   229,   230,    -1,
      -1,    -1,   234,   268,    13,    14,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,    94,    95,    -1,    97,   258,     3,     4,    -1,
      -1,   263,    -1,    -1,    10,    11,    12,    -1,   270,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    67,    -1,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    83,    84,    85,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    94,    95,
      -1,    97,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,    -1,    -1,    -1,
      -1,    -1,   224,   225,   226,   164,   228,   229,   230,    -1,
      -1,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   191,   192,   193,    -1,   258,     3,     4,    -1,
      -1,   263,   264,    -1,    10,    11,    12,    -1,   270,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,   218,    59,    60,    61,    62,    -1,   224,   225,
     226,    67,   228,   229,   230,    -1,    -1,    -1,   234,   268,
      13,    14,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,    94,    95,
      -1,    97,   258,     3,     4,    -1,    -1,   263,   264,    -1,
      10,    11,    12,    -1,   270,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    83,    84,    85,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,
     143,    -1,   145,    -1,    -1,    -1,    -1,    -1,   214,    -1,
      -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,   224,   225,
     226,   164,   228,   229,   230,    -1,    -1,    -1,   234,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   191,   192,
     193,    -1,   258,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,   267,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,   214,    -1,    -1,    80,   218,    82,
      -1,    -1,    -1,    -1,   224,   225,   226,    -1,   228,   229,
     230,    -1,    -1,    96,   234,   268,    99,     4,     5,    -1,
     103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,   122,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,   216,   217,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,
     233,   234,    -1,    -1,    -1,   142,    -1,    -1,    -1,    13,
      14,    -1,    -1,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   264,    -1,   266,   267,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    13,    14,   262,    -1,    -1,    -1,    -1,   215,   216,
     217,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   231,    -1,   233,   234,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     267,   135,   136,    13,    14,   139,   140,    -1,   142,   143,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    -1,    -1,   191,   192,   193,
      -1,    -1,    -1,   135,   136,    13,    14,   139,   140,    -1,
     142,   143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,   191,
     192,   193,    -1,    -1,    -1,   135,   136,    13,    14,   139,
     140,    -1,   142,   143,   268,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,   135,   136,    13,
      14,   139,   140,    -1,   142,   143,   268,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,   135,
     136,    13,    14,   139,   140,    -1,   142,   143,   268,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,   191,   192,   193,    -1,    -1,
      -1,   135,   136,    13,    14,   139,   140,    -1,   142,   143,
     268,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     164,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    -1,    -1,   191,   192,   193,
      -1,    -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,
     142,   143,   268,   145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   164,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,   191,
     192,   193,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,
     140,    -1,   142,   143,   268,   145,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,    13,    14,    -1,    -1,    -1,
      -1,    -1,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   191,   192,   193,   262,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,   272,    -1,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   268,    -1,
     118,   119,   120,   121,   122,    -1,   124,    -1,   126,    -1,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,   147,
     148,   149,    -1,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,    -1,
      -1,    -1,   190,   191,   192,   193,    -1,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    -1,     4,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   232,    -1,   234,   235,    -1,    -1,
      -1,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      47,    48,    49,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    -1,
      -1,   118,   119,   120,   121,   122,    -1,   124,    -1,   126,
      -1,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
     147,   148,   149,    -1,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
      -1,    -1,   179,   180,   181,    -1,    -1,    -1,   185,    -1,
      -1,    -1,    -1,   190,   191,   192,   193,     4,     5,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,    -1,   234,   235,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
       4,     5,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,   103,     4,     5,   106,
      -1,    -1,   109,    -1,   111,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   122,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,   142,    80,    -1,    82,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    96,    -1,    -1,    99,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,   215,   216,
     217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,   231,    -1,   233,   234,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,   216,   217,    96,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,   231,    -1,   233,
     234,    -1,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   215,   216,
     217,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
     227,    -1,    -1,    -1,   231,    -1,   233,   135,   136,    -1,
      -1,   139,   140,    -1,   142,   143,    -1,   145,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   164,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   215,   216,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,   231,
      -1,   233,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   272,   240,   241,   242,   243,   244,
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
      -1,    -1,   267,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
     267,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,   267,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,   264,    -1,   266,   240,   241,   242,   243,
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
      -1,    -1,    -1,   262,    -1,   264,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262
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
     116,   117,   139,   267,   267,   263,   109,   111,   109,   106,
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
     263,   263,   263,   373,   373,   356,   371,   371,   371,   263,
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
     268,   264,     7,   350,     6,     7,   356,   356,     6,   356,
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
     264,   264,   264,   264,   264,   264,   264,   267,   267,     7,
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
       7,     7,     7,     7,     7,     7,     7,   326,   326,   369,
       6,   267,   103,     6,     6,     6,   109,     7,     7,     6,
       6,   356,     7,   369,     7,   369,   369,     4,   272,     8,
       8,   264,   299,   299,   299,   373,   377,   356,   377,   270,
     272,   312,   377,   377,   299,   377,   264,   272,     6,   267,
     321,   267,     6,   356,     6,   267,   369,   268,   268,   356,
       6,   196,   197,   299,   356,     6,     7,   374,   376,     6,
     265,     6,     6,   298,   297,   297,     6,   284,   263,   263,
     267,   294,     6,   299,   269,   377,   356,   266,   264,   356,
       8,   373,   356,   373,   268,   268,     6,     6,   277,   299,
     269,   356,     6,     6,   356,   299,   264,     6,   356,   267,
     356,   378,   298,    50,   267,   369,   378,   381,   356,   356,
     356,   266,   272,     6,   264,     6,     6,   139,   317,   317,
     369,     6,     6,     6,   369,   146,   199,   316,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   268,   268,
     298,   298,   298,   298,   298,   298,   298,   272,   272,   272,
     264,   298,   298,   310,   298,   126,   268,   199,   264,   298,
     264,   297,   359,   298,     6,   298,   263,   265,   297,   299,
     264,   266,   298,     6,   268,   268,   369,   369,   369,     4,
       6,   295,   356,   369,   369,   369,   267,   267,     7,     6,
       7,   356,   356,   356,   267,   267,   267,   265,     6,   356,
     369,   356,     6,     6,   356,   366,   268,     5,   369,   267,
     267,   267,   267,   267,   267,   267,   369,   268,   268,     6,
     373,   267,   267,   356,   356,   266,   369,     6,   369,     6,
     195,   356,   356,   356,   263,   265,     6,     6,     7,   298,
     272,   272,   298,   272,   356,     4,   211,   313,   314,   298,
     264,   298,   360,   378,   356,   267,   327,     6,   327,   272,
       6,     6,   269,     7,     7,   295,   296,     6,   374,   268,
     272,   356,   295,   267,   298,   382,   383,   384,   382,   263,
     356,   356,   368,   369,   267,   263,     4,     6,   264,     6,
     264,   268,   268,   264,   268,     6,     6,   377,   263,     4,
     264,   272,   263,   268,   272,   369,   378,     7,   297,   307,
     356,   372,   311,     6,   366,     6,     6,     6,   146,   318,
     103,   122,   107,     6,     5,   267,     6,   356,   356,   356,
     267,   109,   356,   264,   359,   356,   356,   298,   296,   267,
     267,     6,   316,     6,   356,   369,   146,   146,     4,     6,
     373,   373,   356,   356,   378,   268,   264,   268,   272,   326,
     326,   356,   356,   268,   272,   264,   268,   272,     6,     6,
     368,   366,   366,   366,   366,   366,   252,   366,     6,   268,
     373,   356,     6,     6,     6,     6,     6,   369,   268,   272,
       8,   268,   264,   252,   267,   356,   370,   378,   377,   356,
     377,   356,   378,   381,   383,   378,   272,   264,   272,   268,
     356,   344,   344,   369,   299,   375,   378,   356,     6,     6,
     374,   266,   369,   384,     6,   298,   298,   281,   356,   272,
     272,   268,   272,   282,   356,   356,     6,     6,     6,     6,
     356,   356,   264,     6,   356,   303,   305,   267,   383,   268,
     272,     7,     7,   150,     6,   267,   267,   267,     5,   368,
     298,   298,   272,   356,   267,   298,   264,   264,   266,   373,
     373,     6,     6,   356,   356,   267,   268,   268,   267,     6,
       6,   267,   356,   268,   268,   268,   266,     6,   369,     7,
     267,   356,   268,   272,   272,   272,   272,   272,   272,     6,
     268,   268,   194,   356,   356,   267,   268,   373,     6,     6,
       6,   264,   298,   298,   314,   378,   268,   268,   268,   268,
       7,     6,     6,     6,   269,     6,   268,     6,     6,   264,
     272,   356,   356,   267,   369,   268,   272,   264,   264,   272,
     268,   308,   312,   369,   298,   356,   378,   387,   373,   373,
     356,     6,   268,   356,   272,   356,   359,   268,   268,     6,
       6,   368,   151,   152,   157,   351,   151,   152,   351,   373,
     326,   268,   272,     6,   268,   369,   327,   268,     6,   373,
     366,   366,   366,   366,   366,     6,   356,   268,   268,   373,
     268,   264,     6,   267,     6,   374,   197,   285,   356,   272,
     272,   368,     6,   356,   356,     6,   268,   268,   304,     7,
     263,   268,   268,   268,   267,   272,   356,   268,   264,   267,
     268,   267,   366,   369,     6,   267,   366,     6,   268,   268,
     356,     6,   146,   268,   338,   267,   268,   272,   272,   272,
     272,   272,     6,   268,     6,   327,     6,   267,   356,   356,
     268,   272,   308,   378,   264,   356,   356,   268,   373,     6,
     366,     6,   366,     6,     6,   268,   356,   341,   327,     6,
     373,   373,   373,   373,   366,   373,   344,   282,   264,   272,
       6,   267,   356,   268,   272,   272,   268,   272,   272,     6,
     268,   268,   339,   268,   268,   268,   268,   272,   268,   268,
     268,   288,   356,   368,   268,   356,   356,   366,   366,   341,
       6,     6,     6,     6,   373,     6,     6,     6,   267,   264,
     268,     6,   268,   298,   272,   272,   268,   268,   286,   377,
     291,   267,     6,   356,   356,     6,   268,   272,   267,   368,
     268,   268,     6,   377,   289,   377,   268,     6,     6,   268,
     272,     6,     6,   377
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
#line 6129 "Gmsh.y"
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
#line 6149 "Gmsh.y"
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
#line 6166 "Gmsh.y"
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
#line 6176 "Gmsh.y"
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
#line 6186 "Gmsh.y"
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
#line 6196 "Gmsh.y"
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
#line 6208 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 567:
#line 6212 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 568:
#line 6217 "Gmsh.y"
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
#line 6229 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 570:
#line 6233 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 571:
#line 6237 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 572:
#line 6241 "Gmsh.y"
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
#line 6259 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 574:
#line 6267 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 575:
#line 6275 "Gmsh.y"
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
#line 6304 "Gmsh.y"
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
#line 6314 "Gmsh.y"
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
#line 6330 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 579:
#line 6341 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 580:
#line 6346 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 581:
#line 6350 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 582:
#line 6354 "Gmsh.y"
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
#line 6366 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 584:
#line 6370 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 585:
#line 6382 "Gmsh.y"
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
#line 6399 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 587:
#line 6409 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 588:
#line 6413 "Gmsh.y"
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
#line 6428 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 590:
#line 6433 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 591:
#line 6440 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 592:
#line 6444 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 593:
#line 6449 "Gmsh.y"
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
#line 6463 "Gmsh.y"
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
#line 6477 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 596:
#line 6481 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 597:
#line 6485 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 598:
#line 6489 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 599:
#line 6493 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 600:
#line 6501 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 601:
#line 6507 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 602:
#line 6516 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 603:
#line 6520 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 604:
#line 6524 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 605:
#line 6532 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 606:
#line 6538 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 607:
#line 6544 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 608:
#line 6548 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6555 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 610:
#line 6563 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6570 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 612:
#line 6579 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 613:
#line 6583 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 614:
#line 6587 "Gmsh.y"
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
#line 6602 "Gmsh.y"
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
#line 6616 "Gmsh.y"
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
#line 6630 "Gmsh.y"
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
#line 6642 "Gmsh.y"
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
#line 6658 "Gmsh.y"
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
#line 6667 "Gmsh.y"
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
#line 6676 "Gmsh.y"
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
#line 6686 "Gmsh.y"
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
#line 6697 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 624:
#line 6705 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 625:
#line 6713 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 626:
#line 6717 "Gmsh.y"
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
#line 6735 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 628:
#line 6742 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 629:
#line 6748 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 630:
#line 6754 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 631:
#line 6761 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 632:
#line 6768 "Gmsh.y"
    { init_options(); ;}
    break;

  case 633:
#line 6770 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 634:
#line 6778 "Gmsh.y"
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
#line 6802 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 636:
#line 6804 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 637:
#line 6810 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 638:
#line 6815 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 639:
#line 6817 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 640:
#line 6822 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 641:
#line 6827 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 642:
#line 6832 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 643:
#line 6834 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 644:
#line 6838 "Gmsh.y"
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
#line 6850 "Gmsh.y"
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
#line 6864 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 647:
#line 6868 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 648:
#line 6875 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 649:
#line 6883 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 650:
#line 6891 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 651:
#line 6902 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 652:
#line 6904 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 653:
#line 6907 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15311 "Gmsh.tab.cpp"
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


#line 6910 "Gmsh.y"


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

