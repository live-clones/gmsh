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
     tBooleanUnion = 413,
     tBooleanIntersection = 414,
     tBooleanDifference = 415,
     tBooleanSection = 416,
     tBooleanFragments = 417,
     tThickSolid = 418,
     tRecombine = 419,
     tSmoother = 420,
     tSplit = 421,
     tDelete = 422,
     tCoherence = 423,
     tHealShapes = 424,
     tIntersect = 425,
     tMeshAlgorithm = 426,
     tReverseMesh = 427,
     tMeshSize = 428,
     tMeshSizeFromBoundary = 429,
     tLayers = 430,
     tScaleLast = 431,
     tHole = 432,
     tAlias = 433,
     tAliasWithOptions = 434,
     tCopyOptions = 435,
     tQuadTriAddVerts = 436,
     tQuadTriNoNewVerts = 437,
     tRecombLaterals = 438,
     tTransfQuadTri = 439,
     tText2D = 440,
     tText3D = 441,
     tInterpolationScheme = 442,
     tTime = 443,
     tCombine = 444,
     tBSpline = 445,
     tBezier = 446,
     tNurbs = 447,
     tNurbsOrder = 448,
     tNurbsKnots = 449,
     tColor = 450,
     tColorTable = 451,
     tFor = 452,
     tIn = 453,
     tEndFor = 454,
     tIf = 455,
     tElseIf = 456,
     tElse = 457,
     tEndIf = 458,
     tExit = 459,
     tAbort = 460,
     tField = 461,
     tReturn = 462,
     tCall = 463,
     tSlide = 464,
     tMacro = 465,
     tShow = 466,
     tHide = 467,
     tGetValue = 468,
     tGetStringValue = 469,
     tGetEnv = 470,
     tGetString = 471,
     tGetNumber = 472,
     tUnique = 473,
     tSetMaxTag = 474,
     tHomology = 475,
     tCohomology = 476,
     tBetti = 477,
     tExists = 478,
     tFileExists = 479,
     tGetForced = 480,
     tGetForcedStr = 481,
     tGMSH_MAJOR_VERSION = 482,
     tGMSH_MINOR_VERSION = 483,
     tGMSH_PATCH_VERSION = 484,
     tGmshExecutableName = 485,
     tSetPartition = 486,
     tNameToString = 487,
     tStringToName = 488,
     tUnsplitWindow = 489,
     tAFFECTDIVIDE = 490,
     tAFFECTTIMES = 491,
     tAFFECTMINUS = 492,
     tAFFECTPLUS = 493,
     tOR = 494,
     tAND = 495,
     tNOTEQUAL = 496,
     tEQUAL = 497,
     tGREATERGREATER = 498,
     tLESSLESS = 499,
     tGREATEROREQUAL = 500,
     tLESSOREQUAL = 501,
     UNARYPREC = 502,
     tMINUSMINUS = 503,
     tPLUSPLUS = 504
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
#define tBooleanUnion 413
#define tBooleanIntersection 414
#define tBooleanDifference 415
#define tBooleanSection 416
#define tBooleanFragments 417
#define tThickSolid 418
#define tRecombine 419
#define tSmoother 420
#define tSplit 421
#define tDelete 422
#define tCoherence 423
#define tHealShapes 424
#define tIntersect 425
#define tMeshAlgorithm 426
#define tReverseMesh 427
#define tMeshSize 428
#define tMeshSizeFromBoundary 429
#define tLayers 430
#define tScaleLast 431
#define tHole 432
#define tAlias 433
#define tAliasWithOptions 434
#define tCopyOptions 435
#define tQuadTriAddVerts 436
#define tQuadTriNoNewVerts 437
#define tRecombLaterals 438
#define tTransfQuadTri 439
#define tText2D 440
#define tText3D 441
#define tInterpolationScheme 442
#define tTime 443
#define tCombine 444
#define tBSpline 445
#define tBezier 446
#define tNurbs 447
#define tNurbsOrder 448
#define tNurbsKnots 449
#define tColor 450
#define tColorTable 451
#define tFor 452
#define tIn 453
#define tEndFor 454
#define tIf 455
#define tElseIf 456
#define tElse 457
#define tEndIf 458
#define tExit 459
#define tAbort 460
#define tField 461
#define tReturn 462
#define tCall 463
#define tSlide 464
#define tMacro 465
#define tShow 466
#define tHide 467
#define tGetValue 468
#define tGetStringValue 469
#define tGetEnv 470
#define tGetString 471
#define tGetNumber 472
#define tUnique 473
#define tSetMaxTag 474
#define tHomology 475
#define tCohomology 476
#define tBetti 477
#define tExists 478
#define tFileExists 479
#define tGetForced 480
#define tGetForcedStr 481
#define tGMSH_MAJOR_VERSION 482
#define tGMSH_MINOR_VERSION 483
#define tGMSH_PATCH_VERSION 484
#define tGmshExecutableName 485
#define tSetPartition 486
#define tNameToString 487
#define tStringToName 488
#define tUnsplitWindow 489
#define tAFFECTDIVIDE 490
#define tAFFECTTIMES 491
#define tAFFECTMINUS 492
#define tAFFECTPLUS 493
#define tOR 494
#define tAND 495
#define tNOTEQUAL 496
#define tEQUAL 497
#define tGREATERGREATER 498
#define tLESSLESS 499
#define tGREATEROREQUAL 500
#define tLESSOREQUAL 501
#define UNARYPREC 502
#define tMINUSMINUS 503
#define tPLUSPLUS 504




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
#line 781 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 794 "Gmsh.tab.cpp"

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
#define YYLAST   18457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  272
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  650
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2316

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   504

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   257,     2,   269,     2,   254,   256,     2,
     262,   263,   252,   250,   271,   251,   268,   253,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     244,     2,   245,   239,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   264,     2,   265,   261,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   266,   255,   267,   270,     2,     2,     2,
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
     235,   236,   237,   238,   240,   241,   242,   243,   246,   247,
     248,   249,   258,   259,   260
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
    1182,  1192,  1203,  1213,  1215,  1217,  1218,  1221,  1228,  1236,
    1244,  1251,  1259,  1268,  1279,  1294,  1311,  1324,  1339,  1354,
    1369,  1384,  1393,  1402,  1409,  1414,  1420,  1426,  1433,  1440,
    1444,  1449,  1453,  1459,  1466,  1472,  1477,  1481,  1486,  1490,
    1495,  1501,  1506,  1512,  1516,  1522,  1530,  1538,  1542,  1545,
    1553,  1557,  1560,  1564,  1567,  1570,  1573,  1576,  1592,  1595,
    1598,  1606,  1609,  1619,  1631,  1634,  1639,  1642,  1645,  1648,
    1651,  1668,  1674,  1683,  1695,  1702,  1711,  1720,  1731,  1733,
    1736,  1739,  1741,  1745,  1749,  1754,  1759,  1761,  1763,  1769,
    1781,  1795,  1796,  1804,  1805,  1819,  1820,  1836,  1837,  1844,
    1854,  1857,  1861,  1872,  1886,  1888,  1891,  1897,  1905,  1908,
    1911,  1915,  1918,  1922,  1925,  1929,  1939,  1946,  1948,  1950,
    1952,  1954,  1956,  1957,  1960,  1964,  1968,  1973,  1983,  1988,
    2003,  2004,  2008,  2009,  2011,  2012,  2015,  2016,  2019,  2020,
    2023,  2029,  2036,  2044,  2051,  2057,  2061,  2070,  2077,  2086,
    2095,  2101,  2106,  2113,  2125,  2137,  2156,  2175,  2188,  2201,
    2214,  2225,  2230,  2235,  2240,  2245,  2250,  2257,  2260,  2264,
    2271,  2274,  2276,  2278,  2280,  2283,  2289,  2297,  2308,  2310,
    2314,  2317,  2320,  2323,  2327,  2331,  2335,  2339,  2343,  2347,
    2351,  2355,  2359,  2363,  2367,  2371,  2375,  2379,  2383,  2387,
    2391,  2395,  2401,  2406,  2411,  2416,  2421,  2426,  2431,  2436,
    2441,  2446,  2451,  2456,  2463,  2468,  2473,  2478,  2483,  2488,
    2493,  2498,  2503,  2510,  2517,  2524,  2529,  2536,  2543,  2545,
    2547,  2549,  2551,  2553,  2555,  2557,  2559,  2561,  2563,  2565,
    2566,  2573,  2575,  2580,  2587,  2589,  2594,  2599,  2604,  2611,
    2617,  2625,  2634,  2645,  2650,  2655,  2662,  2667,  2671,  2674,
    2680,  2686,  2690,  2696,  2703,  2712,  2719,  2728,  2735,  2740,
    2748,  2755,  2762,  2769,  2774,  2781,  2786,  2787,  2790,  2791,
    2794,  2795,  2803,  2805,  2809,  2811,  2814,  2815,  2819,  2821,
    2824,  2827,  2831,  2835,  2847,  2857,  2865,  2873,  2875,  2879,
    2881,  2883,  2886,  2890,  2895,  2901,  2904,  2908,  2913,  2915,
    2919,  2921,  2924,  2928,  2932,  2938,  2943,  2948,  2951,  2956,
    2959,  2963,  2967,  2972,  2978,  2984,  2990,  2996,  3002,  3008,
    3010,  3012,  3014,  3018,  3024,  3032,  3037,  3042,  3047,  3054,
    3061,  3070,  3079,  3084,  3099,  3104,  3109,  3111,  3113,  3117,
    3121,  3131,  3139,  3141,  3147,  3151,  3158,  3160,  3164,  3166,
    3168,  3173,  3178,  3182,  3188,  3195,  3204,  3211,  3216,  3222,
    3224,  3229,  3231,  3233,  3235,  3237,  3242,  3249,  3254,  3261,
    3267,  3275,  3280,  3285,  3290,  3299,  3304,  3309,  3314,  3319,
    3328,  3337,  3344,  3349,  3356,  3361,  3363,  3365,  3370,  3375,
    3376,  3383,  3388,  3391,  3396,  3401,  3403,  3405,  3409,  3411,
    3413,  3417,  3421,  3425,  3431,  3439,  3445,  3451,  3460,  3462,
    3464
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     273,     0,    -1,   274,    -1,     1,     6,    -1,    -1,   274,
     275,    -1,   277,    -1,   278,    -1,   299,    -1,   134,   262,
     376,   263,     6,    -1,   318,    -1,   324,    -1,   328,    -1,
     329,    -1,   330,    -1,   331,    -1,   335,    -1,   344,    -1,
     345,    -1,   351,    -1,   352,    -1,   334,    -1,   333,    -1,
     332,    -1,   327,    -1,   354,    -1,   245,    -1,   246,    -1,
      47,   262,   376,   263,     6,    -1,    49,   262,   376,   263,
       6,    -1,    48,   262,   376,   263,     6,    -1,    47,   262,
     376,   263,   276,   376,     6,    -1,    47,   262,   376,   271,
     372,   263,     6,    -1,    49,   262,   376,   271,   372,   263,
       6,    -1,    48,   262,   376,   271,   372,   263,     6,    -1,
      47,   262,   376,   271,   372,   263,   276,   376,     6,    -1,
     386,   376,   266,   279,   267,     6,    -1,   178,     4,   264,
     355,   265,     6,    -1,   179,     4,   264,   355,   265,     6,
      -1,   180,     4,   264,   355,   271,   355,   265,     6,    -1,
      -1,   279,   282,    -1,   279,   286,    -1,   279,   289,    -1,
     279,   291,    -1,   279,   292,    -1,   279,   334,    -1,   355,
      -1,   280,   271,   355,    -1,   355,    -1,   281,   271,   355,
      -1,    -1,    -1,     4,   283,   262,   280,   263,   284,   266,
     281,   267,     6,    -1,   376,    -1,   285,   271,   376,    -1,
      -1,   185,   262,   355,   271,   355,   271,   355,   263,   287,
     266,   285,   267,     6,    -1,   376,    -1,   288,   271,   376,
      -1,    -1,   186,   262,   355,   271,   355,   271,   355,   271,
     355,   263,   290,   266,   288,   267,     6,    -1,   187,   266,
     367,   267,   266,   367,   267,     6,    -1,   187,   266,   367,
     267,   266,   367,   267,   266,   367,   267,   266,   367,   267,
       6,    -1,    -1,   188,   293,   266,   281,   267,     6,    -1,
       7,    -1,   238,    -1,   237,    -1,   236,    -1,   235,    -1,
     260,    -1,   259,    -1,   262,    -1,   264,    -1,   263,    -1,
     265,    -1,     4,    -1,    37,    -1,    38,    -1,    26,    -1,
     112,    -1,   113,    -1,    92,   264,   301,   265,     6,    -1,
      93,   264,   305,   265,     6,    -1,   360,     6,    -1,   100,
     296,   377,   271,   355,   297,     6,    -1,   102,   296,   377,
     271,   377,   297,     6,    -1,   386,   294,   368,     6,    -1,
     386,   295,     6,    -1,   386,   296,   297,   294,   368,     6,
      -1,   386,   296,   266,   372,   267,   297,   294,   368,     6,
      -1,   386,   264,   355,   265,   294,   355,     6,    -1,   386,
     264,   355,   265,   295,     6,    -1,   386,   262,   355,   263,
     294,   355,     6,    -1,   386,   262,   355,   263,   295,     6,
      -1,   386,     7,   377,     6,    -1,   386,   296,   297,     7,
      50,   296,   297,     6,    -1,   386,   296,   297,     7,    50,
     296,   381,   297,     6,    -1,   386,   296,   297,   238,    50,
     296,   381,   297,     6,    -1,   386,   268,   298,     7,   377,
       6,    -1,   386,   264,   355,   265,   268,   298,     7,   377,
       6,    -1,   386,   268,   298,   294,   355,     6,    -1,   386,
     264,   355,   265,   268,   298,   294,   355,     6,    -1,   386,
     268,   298,   295,     6,    -1,   386,   264,   355,   265,   268,
     298,   295,     6,    -1,   386,   268,   195,   268,   298,     7,
     373,     6,    -1,   386,   264,   355,   265,   268,   195,   268,
     298,     7,   373,     6,    -1,   386,   268,   196,     7,   374,
       6,    -1,   386,   264,   355,   265,   268,   196,     7,   374,
       6,    -1,   386,   206,     7,   368,     6,    -1,   206,   264,
     355,   265,     7,   298,     6,    -1,   206,   264,   355,   265,
     268,   298,     7,   355,     6,    -1,   206,   264,   355,   265,
     268,   298,     7,   377,     6,    -1,   206,   264,   355,   265,
     268,   298,     7,   369,     6,    -1,   206,   264,   355,   265,
     268,   298,     6,    -1,   147,   262,     4,   263,   268,   298,
       7,   355,     6,    -1,   147,   262,     4,   263,   268,   298,
       7,   377,     6,    -1,    -1,   271,    -1,    -1,   301,   300,
     386,    -1,   301,   300,   386,     7,   355,    -1,    -1,   301,
     300,   386,     7,   266,   368,   302,   307,   267,    -1,    -1,
     301,   300,   386,   296,   297,     7,   266,   368,   303,   307,
     267,    -1,   301,   300,   386,     7,   377,    -1,    -1,   301,
     300,   386,     7,   266,   377,   304,   311,   267,    -1,    -1,
     305,   300,   376,    -1,   355,     7,   377,    -1,   306,   271,
     355,     7,   377,    -1,   371,     7,   386,   262,   263,    -1,
      -1,   271,   309,    -1,    -1,   309,    -1,   310,    -1,   309,
     271,   310,    -1,     4,   368,    -1,    37,   355,    -1,    38,
     355,    -1,    26,   355,    -1,     4,    -1,     4,   266,   306,
     267,    -1,     4,   377,    -1,     4,   380,    -1,    -1,   271,
     312,    -1,   313,    -1,   312,   271,   313,    -1,     4,   355,
      -1,     4,   377,    -1,   210,   377,    -1,     4,   382,    -1,
       4,   380,    -1,   355,    -1,   377,    -1,   377,   271,   355,
      -1,    -1,   198,   107,   266,   355,   267,    -1,   146,   103,
     266,   372,   267,    -1,   146,   122,   266,   372,   267,    -1,
      -1,   139,   365,    -1,    -1,   146,   150,    -1,   103,   262,
     355,   263,     7,   365,     6,    -1,   106,   262,   355,   263,
       7,   368,     6,    -1,   110,   262,   355,   263,     7,   368,
       6,    -1,   143,   110,   262,   355,   263,     7,   368,   146,
     355,     6,    -1,   143,   190,   262,   355,   263,     7,   368,
     146,   355,     6,    -1,   104,   262,   355,   263,     7,   368,
     316,     6,    -1,   105,   262,   355,   263,     7,   368,   316,
       6,    -1,   190,   262,   355,   263,     7,   368,     6,    -1,
     191,   262,   355,   263,     7,   368,     6,    -1,   192,   262,
     355,   263,     7,   368,   194,   368,   193,   355,     6,    -1,
     121,   262,   355,   263,     7,   368,     6,    -1,   106,     4,
     262,   355,   263,     7,   368,     6,    -1,   139,   109,   262,
     355,   263,     7,   368,     6,    -1,   109,   262,   355,   263,
       7,   368,   315,     6,    -1,   140,   109,   262,   355,   263,
       7,   368,   315,     6,    -1,   190,   109,   262,   355,   263,
       7,   368,     6,    -1,   191,   109,   262,   355,   263,     7,
     368,     6,    -1,    13,    14,     6,    -1,    14,   109,   355,
       6,    -1,   126,   109,   262,   355,   263,     7,     5,     5,
       5,     6,    -1,   107,   262,   355,   263,     7,   368,     6,
      -1,   108,   262,   355,   263,     7,   368,     6,    -1,   112,
     262,   355,   263,     7,   368,     6,    -1,   115,   262,   355,
     263,     7,   368,     6,    -1,   119,   262,   355,   263,     7,
     368,     6,    -1,   120,   262,   355,   263,     7,   368,     6,
      -1,   113,   262,   355,   263,     7,   368,     6,    -1,   114,
     262,   355,   263,     7,   368,     6,    -1,   136,   262,   355,
     263,     7,   368,     6,    -1,   163,   262,   355,   263,     7,
     368,     6,    -1,   109,     4,   262,   355,   263,     7,   368,
     317,     6,    -1,   111,   262,   355,   263,     7,   368,     6,
      -1,   135,   262,   355,   263,     7,   368,     6,    -1,   140,
     135,   262,   355,   263,     7,   368,     6,    -1,   143,   321,
     262,   355,   263,     7,   368,     6,    -1,   143,   321,   262,
     355,   263,     7,   368,     4,   266,   367,   267,     6,    -1,
      -1,   142,   320,   319,   262,   314,   263,   294,   368,     6,
      -1,   103,    -1,   106,    -1,   109,    -1,   111,    -1,   122,
     266,   355,   267,    -1,   106,    -1,   109,    -1,   111,    -1,
     122,   266,   355,   267,    -1,   106,    -1,   109,    -1,   122,
     266,   355,   267,    -1,   103,    -1,   106,    -1,   109,    -1,
     122,   266,   355,   267,    -1,   152,   365,   266,   325,   267,
      -1,   151,   266,   365,   271,   365,   271,   355,   267,   266,
     325,   267,    -1,   153,   365,   266,   325,   267,    -1,   154,
     266,   365,   271,   355,   267,   266,   325,   267,    -1,   154,
     266,   365,   271,   365,   267,   266,   325,   267,    -1,   157,
     266,   372,   267,   266,   325,   267,    -1,     4,   266,   325,
     267,    -1,   170,   106,   266,   372,   267,   109,   266,   355,
     267,    -1,   166,   106,   266,   355,   267,   103,   266,   372,
     267,     6,    -1,   166,   106,   262,   355,   263,   266,   372,
     267,     6,    -1,   326,    -1,   324,    -1,    -1,   326,   318,
      -1,   326,   320,   266,   372,   267,     6,    -1,   326,   142,
     320,   266,   372,   267,     6,    -1,   326,   145,   320,   266,
     372,   267,     6,    -1,   326,   320,   266,     8,   267,     6,
      -1,   326,   142,   320,   266,     8,   267,     6,    -1,   156,
     139,   262,   355,   263,     7,   368,     6,    -1,   156,   103,
     262,   355,   263,     7,   266,   367,   267,     6,    -1,   156,
     139,   262,   355,   263,     7,   266,   365,   271,   365,   271,
     372,   267,     6,    -1,   156,   139,   262,   355,   263,     7,
     266,   365,   271,   365,   271,   365,   271,   372,   267,     6,
      -1,   156,   107,   262,   355,   263,     7,   266,   365,   271,
     372,   267,     6,    -1,   156,   113,   262,   355,   263,     7,
     266,   365,   271,   365,   271,   372,   267,     6,    -1,   156,
     114,   262,   355,   263,     7,   266,   365,   271,   365,   271,
     372,   267,     6,    -1,   156,   116,   262,   355,   263,     7,
     266,   365,   271,   365,   271,   372,   267,     6,    -1,   156,
     117,   262,   355,   263,     7,   266,   365,   271,   365,   271,
     372,   267,     6,    -1,   156,     4,   262,   355,   263,     7,
     368,     6,    -1,   156,     4,   262,   355,   263,     7,     5,
       6,    -1,   156,     4,   266,   355,   267,     6,    -1,   167,
     266,   326,   267,    -1,   149,   167,   266,   326,   267,    -1,
     167,     4,   266,   326,   267,    -1,   167,   206,   264,   355,
     265,     6,    -1,   167,     4,   264,   355,   265,     6,    -1,
     167,   386,     6,    -1,   167,     4,     4,     6,    -1,   167,
      95,     6,    -1,   195,   373,   266,   326,   267,    -1,   149,
     195,   373,   266,   326,   267,    -1,   231,   355,   266,   326,
     267,    -1,   211,   266,     8,   267,    -1,   211,     5,     6,
      -1,   212,   266,     8,   267,    -1,   212,     5,     6,    -1,
     211,   266,   326,   267,    -1,   149,   211,   266,   326,   267,
      -1,   212,   266,   326,   267,    -1,   149,   212,   266,   326,
     267,    -1,   386,   377,     6,    -1,    81,   262,   383,   263,
       6,    -1,   386,   386,   264,   355,   265,   376,     6,    -1,
     386,   386,   386,   264,   355,   265,     6,    -1,   386,   355,
       6,    -1,   234,     6,    -1,   147,   262,     4,   263,   268,
       4,     6,    -1,   189,     4,     6,    -1,   204,     6,    -1,
     204,   355,     6,    -1,   205,     6,    -1,    75,     6,    -1,
      76,     6,    -1,    68,     6,    -1,    68,   266,   355,   271,
     355,   271,   355,   271,   355,   271,   355,   271,   355,   267,
       6,    -1,    69,     6,    -1,    70,     6,    -1,    86,   266,
     355,   271,   355,   267,     6,    -1,    86,     6,    -1,    88,
     266,   355,   271,   355,   271,   355,   267,     6,    -1,    88,
     266,   355,   271,   355,   271,   355,   271,   355,   267,     6,
      -1,    87,     6,    -1,    87,   266,   326,   267,    -1,    89,
       6,    -1,    90,     6,    -1,   128,     6,    -1,   129,     6,
      -1,   130,   266,   372,   267,   266,   372,   267,   266,   367,
     267,   266,   355,   271,   355,   267,     6,    -1,   131,   266,
     372,   267,     6,    -1,   131,   266,   372,   267,   266,   325,
     267,     6,    -1,   209,   262,   266,   372,   267,   271,   377,
     271,   377,   263,     6,    -1,   197,   262,   355,     8,   355,
     263,    -1,   197,   262,   355,     8,   355,     8,   355,   263,
      -1,   197,     4,   198,   266,   355,     8,   355,   267,    -1,
     197,     4,   198,   266,   355,     8,   355,     8,   355,   267,
      -1,   199,    -1,   210,     4,    -1,   210,   377,    -1,   207,
      -1,   208,   386,     6,    -1,   208,   377,     6,    -1,   200,
     262,   355,   263,    -1,   201,   262,   355,   263,    -1,   202,
      -1,   203,    -1,   155,   365,   266,   326,   267,    -1,   155,
     266,   365,   271,   365,   271,   355,   267,   266,   326,   267,
      -1,   155,   266,   365,   271,   365,   271,   365,   271,   355,
     267,   266,   326,   267,    -1,    -1,   155,   365,   266,   326,
     336,   340,   267,    -1,    -1,   155,   266,   365,   271,   365,
     271,   355,   267,   266,   326,   337,   340,   267,    -1,    -1,
     155,   266,   365,   271,   365,   271,   365,   271,   355,   267,
     266,   326,   338,   340,   267,    -1,    -1,   155,   266,   326,
     339,   340,   267,    -1,   155,   266,   326,   267,   146,   121,
     266,   355,   267,    -1,   135,   368,    -1,   140,   135,   368,
      -1,   137,   266,   372,   267,   266,   372,   267,   266,   372,
     267,    -1,   138,   266,   372,   267,   266,   372,   267,   266,
     372,   267,   266,   372,   267,    -1,   341,    -1,   340,   341,
      -1,   175,   266,   355,   267,     6,    -1,   175,   266,   368,
     271,   368,   267,     6,    -1,   176,     6,    -1,   164,     6,
      -1,   164,   355,     6,    -1,   181,     6,    -1,   181,   183,
       6,    -1,   182,     6,    -1,   182,   183,     6,    -1,   177,
     262,   355,   263,     7,   368,   146,   355,     6,    -1,   146,
       4,   264,   355,   265,     6,    -1,   158,    -1,   159,    -1,
     160,    -1,   161,    -1,   162,    -1,    -1,   167,     6,    -1,
     149,   167,     6,    -1,   167,   355,     6,    -1,   149,   167,
     355,     6,    -1,   342,   266,   326,   343,   267,   266,   326,
     343,   267,    -1,   118,   262,   376,   263,    -1,   342,   262,
     355,   263,     7,   266,   326,   343,   267,   266,   326,   343,
     267,     6,    -1,    -1,   146,     4,   355,    -1,    -1,     4,
      -1,    -1,     7,   368,    -1,    -1,     7,   355,    -1,    -1,
     157,   368,    -1,   173,   370,     7,   355,     6,    -1,   124,
     125,   370,     7,   355,     6,    -1,   141,   106,   370,     7,
     355,   346,     6,    -1,   141,   109,   370,   348,   347,     6,
      -1,   141,   111,   370,   348,     6,    -1,   184,   370,     6,
      -1,   101,   320,   262,   355,   271,   355,   263,     6,    -1,
     219,   320,   262,   355,   263,     6,    -1,   171,   109,   266,
     372,   267,     7,   355,     6,    -1,   174,   109,   266,   372,
     267,     7,   355,     6,    -1,   164,   109,   370,   349,     6,
      -1,   164,   111,   370,     6,    -1,   165,   109,   370,     7,
     355,     6,    -1,   144,   106,   266,   372,   267,     7,   266,
     372,   267,   350,     6,    -1,   144,   109,   266,   372,   267,
       7,   266,   372,   267,   350,     6,    -1,   144,   106,   266,
     372,   267,     7,   266,   372,   267,   151,   266,   365,   271,
     365,   271,   355,   267,     6,    -1,   144,   109,   266,   372,
     267,     7,   266,   372,   267,   151,   266,   365,   271,   365,
     271,   355,   267,     6,    -1,   144,   106,   266,   372,   267,
       7,   266,   372,   267,   152,   365,     6,    -1,   144,   109,
     266,   372,   267,     7,   266,   372,   267,   152,   365,     6,
      -1,   144,   109,   355,   266,   372,   267,     7,   355,   266,
     372,   267,     6,    -1,   320,   266,   372,   267,   198,   320,
     266,   355,   267,     6,    -1,   172,   322,   370,     6,    -1,
     132,   323,   370,     6,    -1,   133,   111,   368,     6,    -1,
     148,   106,   368,     6,    -1,   143,   321,   368,     6,    -1,
     143,   321,   368,   171,   355,     6,    -1,   168,     6,    -1,
     168,     4,     6,    -1,   168,   103,   266,   372,   267,     6,
      -1,   169,     6,    -1,   220,    -1,   221,    -1,   222,    -1,
     353,     6,    -1,   353,   266,   368,   267,     6,    -1,   353,
     266,   368,   271,   368,   267,     6,    -1,   353,   262,   368,
     263,   266,   368,   271,   368,   267,     6,    -1,   356,    -1,
     262,   355,   263,    -1,   251,   355,    -1,   250,   355,    -1,
     257,   355,    -1,   355,   251,   355,    -1,   355,   250,   355,
      -1,   355,   252,   355,    -1,   355,   253,   355,    -1,   355,
     255,   355,    -1,   355,   256,   355,    -1,   355,   254,   355,
      -1,   355,   261,   355,    -1,   355,   244,   355,    -1,   355,
     245,   355,    -1,   355,   249,   355,    -1,   355,   248,   355,
      -1,   355,   243,   355,    -1,   355,   242,   355,    -1,   355,
     241,   355,    -1,   355,   240,   355,    -1,   355,   246,   355,
      -1,   355,   247,   355,    -1,   355,   239,   355,     8,   355,
      -1,    26,   296,   355,   297,    -1,    16,   296,   355,   297,
      -1,    17,   296,   355,   297,    -1,    18,   296,   355,   297,
      -1,    19,   296,   355,   297,    -1,    20,   296,   355,   297,
      -1,    21,   296,   355,   297,    -1,    22,   296,   355,   297,
      -1,    23,   296,   355,   297,    -1,    24,   296,   355,   297,
      -1,    27,   296,   355,   297,    -1,    28,   296,   355,   271,
     355,   297,    -1,    29,   296,   355,   297,    -1,    30,   296,
     355,   297,    -1,    31,   296,   355,   297,    -1,    32,   296,
     355,   297,    -1,    33,   296,   355,   297,    -1,    34,   296,
     355,   297,    -1,    35,   296,   355,   297,    -1,    36,   296,
     355,   297,    -1,    39,   296,   355,   271,   355,   297,    -1,
      40,   296,   355,   271,   355,   297,    -1,    41,   296,   355,
     271,   355,   297,    -1,    25,   296,   355,   297,    -1,    38,
     296,   355,   271,   355,   297,    -1,    37,   296,   355,   271,
     355,   297,    -1,     3,    -1,    10,    -1,    15,    -1,    11,
      -1,    12,    -1,   227,    -1,   228,    -1,   229,    -1,    83,
      -1,    84,    -1,    85,    -1,    -1,    94,   296,   355,   357,
     307,   297,    -1,   360,    -1,   217,   296,   376,   297,    -1,
     217,   296,   376,   271,   355,   297,    -1,   362,    -1,   386,
     264,   355,   265,    -1,   386,   262,   355,   263,    -1,   223,
     262,   362,   263,    -1,   223,   262,   362,   268,   298,   263,
      -1,   225,   262,   362,   358,   263,    -1,   225,   262,   362,
     268,   298,   358,   263,    -1,   225,   262,   362,   296,   355,
     297,   358,   263,    -1,   225,   262,   362,   268,   298,   296,
     355,   297,   358,   263,    -1,   224,   262,   377,   263,    -1,
     269,   386,   296,   297,    -1,   269,   362,   268,   298,   296,
     297,    -1,    97,   296,   386,   297,    -1,    97,   296,   297,
      -1,   386,   295,    -1,   386,   264,   355,   265,   295,    -1,
     386,   262,   355,   263,   295,    -1,   386,   268,   298,    -1,
     386,     9,   386,   268,   298,    -1,   386,   268,   298,   262,
     355,   263,    -1,   386,     9,   386,   268,   298,   262,   355,
     263,    -1,   386,   268,   298,   264,   355,   265,    -1,   386,
       9,   386,   268,   298,   264,   355,   265,    -1,   386,   264,
     355,   265,   268,   298,    -1,   386,   268,   298,   295,    -1,
     386,   264,   355,   265,   268,   298,   295,    -1,   213,   262,
     376,   271,   355,   263,    -1,    60,   262,   368,   271,   368,
     263,    -1,    61,   296,   376,   271,   376,   297,    -1,    59,
     296,   376,   297,    -1,    62,   296,   376,   271,   376,   297,
      -1,    67,   262,   383,   263,    -1,    -1,   271,   355,    -1,
      -1,   271,   376,    -1,    -1,    95,   362,   364,   361,   264,
     308,   265,    -1,   386,    -1,   386,     9,   386,    -1,    98,
      -1,    98,   355,    -1,    -1,   262,   363,   263,    -1,   366,
      -1,   251,   365,    -1,   250,   365,    -1,   365,   251,   365,
      -1,   365,   250,   365,    -1,   266,   355,   271,   355,   271,
     355,   271,   355,   271,   355,   267,    -1,   266,   355,   271,
     355,   271,   355,   271,   355,   267,    -1,   266,   355,   271,
     355,   271,   355,   267,    -1,   262,   355,   271,   355,   271,
     355,   263,    -1,   368,    -1,   367,   271,   368,    -1,   355,
      -1,   371,    -1,   266,   267,    -1,   266,   372,   267,    -1,
     251,   266,   372,   267,    -1,   355,   252,   266,   372,   267,
      -1,   266,   267,    -1,   266,   372,   267,    -1,   251,   266,
     372,   267,    -1,   368,    -1,   266,     8,   267,    -1,     5,
      -1,   251,   371,    -1,   355,   252,   371,    -1,   355,     8,
     355,    -1,   355,     8,   355,     8,   355,    -1,   103,   266,
     355,   267,    -1,   103,   266,     8,   267,    -1,   103,     5,
      -1,   321,   266,     8,   267,    -1,   321,     5,    -1,   142,
     320,   370,    -1,   145,   320,   368,    -1,   320,   198,    68,
     368,    -1,    68,   320,   266,   372,   267,    -1,    77,   321,
     266,   355,   267,    -1,    78,   321,   266,   355,   267,    -1,
      79,   321,   266,   355,   267,    -1,   123,   109,   266,   372,
     267,    -1,   195,   321,   266,   355,   267,    -1,   324,    -1,
     335,    -1,   344,    -1,   386,   296,   297,    -1,   386,   268,
     298,   296,   297,    -1,   386,     9,   386,   268,   298,   296,
     297,    -1,    42,   264,   386,   265,    -1,    42,   264,   371,
     265,    -1,    42,   262,   371,   263,    -1,    42,   296,   266,
     372,   267,   297,    -1,   386,   296,   266,   372,   267,   297,
      -1,    43,   296,   355,   271,   355,   271,   355,   297,    -1,
      44,   296,   355,   271,   355,   271,   355,   297,    -1,    45,
     296,   376,   297,    -1,    46,   296,   355,   271,   355,   271,
     355,   271,   355,   271,   355,   271,   355,   297,    -1,   218,
     296,   371,   297,    -1,    33,   296,   371,   297,    -1,   355,
      -1,   371,    -1,   372,   271,   355,    -1,   372,   271,   371,
      -1,   266,   355,   271,   355,   271,   355,   271,   355,   267,
      -1,   266,   355,   271,   355,   271,   355,   267,    -1,   386,
      -1,     4,   268,   195,   268,     4,    -1,   266,   375,   267,
      -1,   386,   264,   355,   265,   268,   196,    -1,   373,    -1,
     375,   271,   373,    -1,   377,    -1,   386,    -1,   386,   264,
     355,   265,    -1,   386,   262,   355,   263,    -1,   386,   268,
     298,    -1,   386,     9,   386,   268,   298,    -1,   386,   268,
     298,   262,   355,   263,    -1,   386,     9,   386,   268,   298,
     262,   355,   263,    -1,   386,   264,   355,   265,   268,     4,
      -1,   320,   266,   355,   267,    -1,   142,   320,   266,   355,
     267,    -1,     5,    -1,   232,   264,   386,   265,    -1,    71,
      -1,   230,    -1,    80,    -1,    82,    -1,   215,   262,   376,
     263,    -1,   214,   262,   376,   271,   376,   263,    -1,   216,
     296,   376,   297,    -1,   216,   296,   376,   271,   376,   297,
      -1,   226,   262,   362,   359,   263,    -1,   226,   262,   362,
     268,   298,   359,   263,    -1,    52,   296,   383,   297,    -1,
      53,   262,   376,   263,    -1,    54,   262,   376,   263,    -1,
      55,   262,   376,   271,   376,   271,   376,   263,    -1,    50,
     296,   383,   297,    -1,    64,   296,   376,   297,    -1,    65,
     296,   376,   297,    -1,    66,   296,   376,   297,    -1,    63,
     296,   355,   271,   376,   271,   376,   297,    -1,    58,   296,
     376,   271,   355,   271,   355,   297,    -1,    58,   296,   376,
     271,   355,   297,    -1,    51,   296,   376,   297,    -1,    51,
     296,   376,   271,   372,   297,    -1,    72,   296,   376,   297,
      -1,    73,    -1,    74,    -1,    57,   296,   376,   297,    -1,
      56,   296,   376,   297,    -1,    -1,    99,   296,   377,   378,
     311,   297,    -1,    96,   296,   379,   297,    -1,   269,   355,
      -1,   386,     9,   269,   355,    -1,    50,   296,   382,   297,
      -1,   383,    -1,   382,    -1,   266,   383,   267,    -1,   376,
      -1,   384,    -1,   383,   271,   376,    -1,   383,   271,   384,
      -1,   386,   262,   263,    -1,   386,   268,   298,   262,   263,
      -1,   386,     9,   386,   268,   298,   262,   263,    -1,     4,
     270,   266,   355,   267,    -1,   385,   270,   266,   355,   267,
      -1,   233,   264,   376,   265,   270,   266,   355,   267,    -1,
       4,    -1,   385,    -1,   233,   264,   376,   265,    -1
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
    2598,  2619,  2640,  2666,  2667,  2672,  2675,  2679,  2696,  2716,
    2736,  2755,  2782,  2801,  2822,  2837,  2853,  2871,  2922,  2943,
    2965,  2988,  3093,  3109,  3144,  3169,  3194,  3206,  3212,  3227,
    3258,  3270,  3279,  3286,  3298,  3318,  3322,  3327,  3331,  3336,
    3343,  3350,  3357,  3369,  3442,  3460,  3485,  3500,  3549,  3555,
    3567,  3599,  3603,  3607,  3612,  3619,  3624,  3634,  3639,  3645,
    3653,  3664,  3672,  3676,  3680,  3684,  3691,  3695,  3699,  3711,
    3720,  3779,  3799,  3825,  3841,  3858,  3875,  3897,  3919,  3954,
    3962,  3970,  3976,  3983,  3990,  4010,  4036,  4048,  4059,  4077,
    4095,  4114,  4113,  4138,  4137,  4164,  4163,  4188,  4187,  4210,
    4226,  4243,  4260,  4283,  4311,  4314,  4320,  4332,  4352,  4356,
    4360,  4364,  4368,  4372,  4376,  4380,  4389,  4402,  4403,  4404,
    4405,  4406,  4410,  4411,  4412,  4413,  4414,  4417,  4441,  4460,
    4483,  4486,  4514,  4517,  4534,  4537,  4543,  4546,  4553,  4556,
    4563,  4586,  4605,  4646,  4690,  4729,  4754,  4761,  4772,  4789,
    4806,  4836,  4862,  4888,  4920,  4948,  4974,  5000,  5026,  5052,
    5074,  5086,  5134,  5188,  5203,  5215,  5221,  5233,  5240,  5255,
    5264,  5285,  5286,  5287,  5291,  5297,  5309,  5327,  5355,  5356,
    5357,  5358,  5359,  5360,  5361,  5362,  5363,  5370,  5371,  5372,
    5373,  5374,  5375,  5376,  5377,  5378,  5379,  5380,  5381,  5382,
    5383,  5384,  5385,  5386,  5387,  5388,  5389,  5390,  5391,  5392,
    5393,  5394,  5395,  5396,  5397,  5398,  5399,  5400,  5401,  5402,
    5403,  5404,  5405,  5406,  5407,  5408,  5409,  5410,  5419,  5420,
    5421,  5422,  5423,  5424,  5425,  5426,  5427,  5428,  5429,  5434,
    5433,  5441,  5445,  5450,  5455,  5459,  5464,  5469,  5473,  5477,
    5481,  5485,  5489,  5493,  5499,  5514,  5518,  5524,  5529,  5548,
    5568,  5589,  5593,  5597,  5601,  5605,  5609,  5613,  5618,  5628,
    5638,  5643,  5654,  5663,  5668,  5673,  5701,  5702,  5708,  5709,
    5715,  5714,  5737,  5739,  5744,  5746,  5752,  5753,  5758,  5762,
    5766,  5770,  5774,  5781,  5785,  5789,  5793,  5800,  5805,  5812,
    5817,  5821,  5825,  5829,  5837,  5848,  5852,  5856,  5867,  5871,
    5875,  5889,  5897,  5905,  5912,  5922,  5945,  5950,  5956,  5961,
    5967,  5978,  5984,  5998,  6004,  6016,  6030,  6043,  6089,  6106,
    6116,  6126,  6136,  6148,  6152,  6157,  6169,  6173,  6177,  6181,
    6199,  6207,  6215,  6244,  6254,  6270,  6281,  6286,  6290,  6294,
    6306,  6310,  6322,  6339,  6349,  6353,  6368,  6373,  6380,  6384,
    6389,  6403,  6417,  6421,  6425,  6429,  6433,  6441,  6447,  6456,
    6460,  6464,  6472,  6478,  6484,  6488,  6495,  6503,  6510,  6519,
    6523,  6527,  6542,  6556,  6570,  6582,  6598,  6607,  6616,  6626,
    6637,  6645,  6653,  6657,  6675,  6682,  6688,  6694,  6701,  6709,
    6708,  6718,  6742,  6744,  6750,  6755,  6757,  6762,  6767,  6772,
    6774,  6778,  6790,  6804,  6808,  6815,  6823,  6831,  6842,  6844,
    6847
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
  "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,    63,
     494,   495,   496,   497,    60,    62,   498,   499,   500,   501,
      43,    45,    42,    47,    37,   124,    38,    33,   502,   503,
     504,    94,    40,    41,    91,    93,   123,   125,    46,    35,
     126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   272,   273,   273,   274,   274,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   277,   277,
     277,   277,   277,   277,   277,   277,   278,   278,   278,   278,
     279,   279,   279,   279,   279,   279,   279,   280,   280,   281,
     281,   283,   284,   282,   285,   285,   287,   286,   288,   288,
     290,   289,   291,   291,   293,   292,   294,   294,   294,   294,
     294,   295,   295,   296,   296,   297,   297,   298,   298,   298,
     298,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   300,   300,
     301,   301,   301,   302,   301,   303,   301,   301,   304,   301,
     305,   305,   306,   306,   306,   307,   307,   308,   308,   309,
     309,   310,   310,   310,   310,   310,   310,   310,   310,   311,
     311,   312,   312,   313,   313,   313,   313,   313,   314,   314,
     314,   315,   315,   315,   315,   316,   316,   317,   317,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   319,   318,   320,   320,   320,
     320,   320,   321,   321,   321,   321,   322,   322,   322,   323,
     323,   323,   323,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   325,   325,   326,   326,   326,   326,   326,
     326,   326,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   328,   328,   328,   328,   328,   328,
     328,   328,   329,   329,   330,   331,   331,   331,   331,   331,
     331,   331,   331,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   333,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   335,   335,
     335,   336,   335,   337,   335,   338,   335,   339,   335,   335,
     335,   335,   335,   335,   340,   340,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   342,   342,   342,
     342,   342,   343,   343,   343,   343,   343,   344,   344,   345,
     346,   346,   347,   347,   348,   348,   349,   349,   350,   350,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   352,   352,   352,
     352,   353,   353,   353,   354,   354,   354,   354,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   357,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   358,   358,   359,   359,
     361,   360,   362,   362,   363,   363,   364,   364,   365,   365,
     365,   365,   365,   366,   366,   366,   366,   367,   367,   368,
     368,   368,   368,   368,   368,   369,   369,   369,   370,   370,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   372,   372,   372,   372,
     373,   373,   373,   373,   374,   374,   375,   375,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   376,   376,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   377,   378,
     377,   377,   379,   379,   380,   381,   381,   382,   383,   383,
     383,   383,   384,   384,   384,   385,   385,   385,   386,   386,
     386
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
       1,     1,     4,     5,    11,     5,     9,     9,     7,     4,
       9,    10,     9,     1,     1,     0,     2,     6,     7,     7,
       6,     7,     8,    10,    14,    16,    12,    14,    14,    14,
      14,     8,     8,     6,     4,     5,     5,     6,     6,     3,
       4,     3,     5,     6,     5,     4,     3,     4,     3,     4,
       5,     4,     5,     3,     5,     7,     7,     3,     2,     7,
       3,     2,     3,     2,     2,     2,     2,    15,     2,     2,
       7,     2,     9,    11,     2,     4,     2,     2,     2,     2,
      16,     5,     8,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       2,     3,    10,    13,     1,     2,     5,     7,     2,     2,
       3,     2,     3,     2,     3,     9,     6,     1,     1,     1,
       1,     1,     0,     2,     3,     3,     4,     9,     4,    14,
       0,     3,     0,     1,     0,     2,     0,     2,     0,     2,
       5,     6,     7,     6,     5,     3,     8,     6,     8,     8,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,     4,     4,     4,     4,     4,     6,     2,     3,     6,
       2,     1,     1,     1,     2,     5,     7,    10,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     1,     4,     6,     1,     4,     4,     4,     6,     5,
       7,     8,    10,     4,     4,     6,     4,     3,     2,     5,
       5,     3,     5,     6,     8,     6,     8,     6,     4,     7,
       6,     6,     6,     4,     6,     4,     0,     2,     0,     2,
       0,     7,     1,     3,     1,     2,     0,     3,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     2,     3,     4,     1,     3,
       1,     2,     3,     3,     5,     4,     4,     2,     4,     2,
       3,     3,     4,     5,     5,     5,     5,     5,     5,     1,
       1,     1,     3,     5,     7,     4,     4,     4,     6,     6,
       8,     8,     4,    14,     4,     4,     1,     1,     3,     3,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       0,     0,   208,     0,     0,   209,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   347,   348,   349,   350,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   308,     0,     0,   316,   317,     0,     0,
       0,   311,     0,     0,     0,     0,     0,     0,   401,   402,
     403,     0,     0,     0,     5,     6,     7,     8,    10,     0,
      11,    24,    12,    13,    14,    15,    23,    22,    21,    16,
       0,    17,    18,    19,    20,     0,    25,     0,   649,     0,
     235,     0,     0,     0,     0,     0,     0,   286,     0,   288,
     289,   284,   285,     0,   291,     0,   294,   235,     0,   296,
     297,   120,   130,   648,   516,   512,    73,    74,     0,   207,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   298,   299,     0,
       0,   219,   220,   221,     0,     0,     0,     0,   458,   459,
     461,   462,   460,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   466,   467,   468,     0,     0,   207,   212,
     213,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,   464,   465,     0,     0,
       0,     0,     0,     0,     0,     0,   559,   560,     0,   561,
     529,   408,   471,   474,   330,   530,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   212,   213,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   518,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   648,     0,     0,
     235,     0,     0,   397,     0,   400,     0,     0,   216,   217,
       0,     0,   540,     0,     0,   538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   648,     0,
       0,   582,     0,     0,     0,     0,   281,     0,     0,     0,
     512,   283,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   601,     0,   625,
     626,   603,   604,     0,     0,     0,     0,     0,     0,   602,
       0,     0,     0,     0,   309,   310,     0,   235,     0,   235,
       0,     0,     0,   278,     0,     0,   235,   404,     0,     0,
      85,     0,    66,     0,     0,    70,    69,    68,    67,    72,
      71,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     588,   512,     0,   234,     0,   233,     0,   186,     0,     0,
     588,   589,     0,     0,     0,   638,     0,   639,   589,     0,
       0,     0,   118,   118,     0,   510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   576,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   411,
       0,   410,   541,   412,     0,   531,     0,     0,   512,     0,
     549,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,   488,     0,     0,     0,
       0,     0,     0,     0,   331,     0,   364,   364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   235,
       0,   235,   235,     0,   520,   519,     0,     0,     0,     0,
     235,   235,     0,     0,     0,     0,   327,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     366,     0,     0,     0,     0,     0,     0,   235,   261,     0,
       0,   259,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   375,   280,     0,     0,     0,
       0,     0,     0,     0,   235,     0,     0,     0,     0,     0,
     410,   282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   313,
     312,     0,   266,     0,     0,   268,     0,     0,     0,   235,
       0,     0,     0,   352,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    80,    78,    79,    81,    82,     0,     0,
       0,     0,    89,    75,    76,     0,     0,     0,   277,    40,
     273,     0,     0,     0,     0,     0,   229,     0,     0,     0,
       0,     0,   236,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,   119,     0,     0,     0,
     514,     0,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   358,     0,     0,     0,   211,     0,     0,     0,
       0,     0,     0,     0,   392,   393,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   469,   487,     0,     0,     0,     0,     0,   550,
     551,     0,     0,     0,     0,     0,     0,   506,     0,   409,
     532,     0,     0,     0,     0,   543,     0,   428,   427,   426,
     425,   421,   422,   429,   430,   424,   423,   414,   413,     0,
     415,   542,   416,   419,   417,   418,   420,   513,     0,     0,
     491,     0,   562,     0,     0,     0,     0,     0,     0,     0,
       0,   362,     0,     0,     0,     0,     0,     0,   395,     0,
       0,     0,     0,     0,   394,     0,   235,     0,     0,     0,
       0,     0,   522,   521,     0,     0,     0,     0,     0,     0,
       0,   321,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   381,     0,     0,     0,   260,
       0,     0,     0,   254,     0,     0,     0,     0,   391,   409,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   314,   315,     0,   415,
     513,   491,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     629,     0,     0,     0,   508,     0,     0,   265,   269,   267,
     271,     0,     0,   650,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,   409,     0,     0,     0,
      66,     0,     0,    88,     0,    66,    67,     0,     0,     0,
     513,     0,     0,   491,     0,     0,     0,   205,     0,     0,
       0,   645,    28,    26,    27,     0,     0,     0,     0,     0,
     592,    30,     0,    29,     0,     0,   274,   640,   641,     0,
     642,   592,     0,     0,    83,   121,    84,   131,   515,   517,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   578,   579,   301,   235,   222,
       9,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     455,   432,   442,     0,   444,   445,   446,   447,   448,   575,
     449,   450,   451,     0,     0,     0,     0,     0,   567,   566,
     565,     0,     0,     0,   572,     0,   503,     0,     0,     0,
     505,     0,     0,     0,     0,   135,   486,   546,   545,   215,
       0,     0,     0,     0,   472,   574,   477,     0,   483,     0,
       0,     0,     0,   533,     0,     0,   484,   552,   548,     0,
       0,     0,     0,   476,   475,    73,    74,   498,     0,     0,
       0,     0,     0,     0,     0,   409,   360,   365,   363,     0,
     374,     0,   158,   159,     0,   215,     0,   409,     0,     0,
       0,     0,     0,   255,     0,   270,   272,     0,     0,     0,
     223,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   334,     0,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235,     0,   367,   380,
       0,     0,     0,     0,   256,     0,     0,     0,     0,   218,
     370,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
     615,     0,   622,   611,   612,   613,     0,   628,   627,     0,
       0,   616,   617,   618,   624,   632,   631,     0,   149,     0,
     605,     0,   607,     0,     0,     0,   600,     0,     0,   264,
       0,     0,     0,     0,   353,     0,     0,     0,   405,     0,
     646,     0,   110,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
     597,    51,     0,     0,     0,    64,     0,    41,    42,    43,
      44,    45,    46,     0,   476,   475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   591,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,   138,   139,     0,     0,     0,
       0,   165,   165,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   371,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   553,   554,   555,   556,     0,
       0,   557,   558,     0,     0,     0,   506,   507,     0,   479,
       0,     0,   544,   431,   534,   492,   490,     0,   489,     0,
       0,   563,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   373,     0,     0,     0,     0,     0,   396,     0,     0,
       0,    77,     0,   263,     0,     0,     0,     0,     0,     0,
       0,   339,     0,     0,   338,     0,   341,     0,   343,     0,
     328,   335,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   382,     0,     0,   258,   257,
     399,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,   583,     0,     0,     0,   304,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
     509,   609,     0,   377,     0,     0,   235,   354,     0,   355,
     235,     0,     0,   598,     0,    95,     0,     0,     0,     0,
      93,     0,   586,     0,   108,     0,   100,   102,     0,     0,
       0,    90,     0,     0,     0,     0,     0,    36,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,   593,     0,     0,    34,    33,     0,
     593,   643,   290,     0,     0,   122,   127,     0,     0,     0,
     141,   147,   148,   144,   142,   143,   511,     0,    86,     0,
      87,   169,     0,     0,     0,     0,   170,   189,   190,   167,
       0,     0,     0,   171,   200,   191,   195,   196,   192,   193,
     194,   179,     0,     0,     0,   443,   457,   456,   452,   453,
     454,   568,     0,     0,     0,   501,   502,   504,   136,   470,
     500,   473,   478,     0,     0,   506,   201,   485,    73,    74,
       0,   497,   493,   495,   569,   197,     0,     0,     0,   161,
       0,     0,   372,     0,   160,     0,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,   235,   235,     0,     0,
     340,   529,     0,     0,   342,   344,     0,     0,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     198,     0,     0,     0,     0,     0,     0,     0,   176,     0,
     177,     0,     0,     0,     0,     0,     0,   111,   115,     0,
     623,     0,     0,   621,     0,   633,     0,     0,   150,   151,
     630,   606,   608,     0,     0,     0,     0,   352,   356,   352,
       0,   406,    94,     0,     0,    66,     0,     0,    92,     0,
     584,     0,     0,     0,     0,     0,     0,   636,   635,     0,
       0,     0,     0,     0,   527,     0,     0,    77,   275,   493,
     276,     0,     0,     0,     0,     0,   240,   237,     0,     0,
     596,   594,     0,     0,     0,     0,   123,   128,     0,     0,
       0,   576,   577,   140,   376,   166,   174,   175,   180,     0,
       0,     0,     0,     0,   182,     0,     0,   302,     0,     0,
       0,     0,   480,     0,     0,     0,   564,   499,     0,     0,
     181,     0,   202,   361,     0,     0,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   526,   525,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   251,     0,
       0,     0,     0,     0,     0,     0,     0,   242,     0,     0,
       0,   378,   379,    39,   184,   185,     0,   581,     0,     0,
     306,   305,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   154,   157,   156,   155,     0,   610,     0,   647,     0,
       0,     0,     0,     0,     0,     0,     0,   105,   106,   587,
       0,     0,     0,    97,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    49,     0,   241,   238,   239,    35,     0,
       0,   644,   292,     0,   135,   149,     0,     0,   146,     0,
       0,     0,   168,   199,     0,     0,     0,     0,     0,   570,
     571,     0,   506,   481,   494,   496,     0,     0,   183,   206,
       0,     0,     0,   368,   368,     0,   116,   117,   235,     0,
     226,   227,   329,     0,   336,     0,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,   230,     0,
       0,     0,     0,   535,     0,   112,   114,   113,   614,   620,
     619,   152,     0,     0,     0,   357,     0,     0,   109,   101,
     103,     0,    91,   637,    98,    99,    52,     0,     0,     0,
       0,   528,     0,     0,   494,   595,     0,     0,     0,     0,
     125,   634,     0,   132,     0,     0,     0,     0,   188,     0,
       0,     0,   332,     0,   172,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,     0,   346,     0,
       0,   323,     0,   243,     0,     0,     0,     0,     0,     0,
     231,     0,   580,   307,     0,   536,     0,   390,   235,   407,
       0,   585,     0,    48,     0,     0,     0,    65,    50,     0,
     293,   124,   129,   135,     0,     0,   163,   164,   162,     0,
       0,   482,     0,     0,     0,     0,   369,   383,     0,     0,
     384,     0,   224,     0,   337,     0,   319,     0,   235,     0,
       0,     0,     0,     0,     0,   178,   537,   303,   352,   107,
       0,     0,     0,     0,     0,     0,   133,   134,     0,     0,
       0,   204,     0,   387,     0,   388,   389,   523,     0,     0,
     325,   246,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,    62,     0,     0,   126,     0,     0,   333,     0,
       0,   345,   324,   320,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,   250,     0,   244,   359,    53,
       0,    60,     0,   287,     0,   573,     0,     0,   326,     0,
       0,    54,     0,     0,   300,     0,     0,   245,     0,     0,
       0,     0,     0,     0,    57,    55,     0,    58,     0,   385,
     386,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   124,  1125,   125,   126,  1109,  1996,  2002,
    1417,  1642,  2162,  2290,  1418,  2263,  2306,  1419,  2292,  1420,
    1421,  1646,   464,   626,   627,  1198,  1741,   127,   827,   492,
    2014,  2173,  2015,   493,  1880,  1500,  1454,  1455,  1456,  1606,
    1818,  1819,  1271,  1702,  1693,  1890,   802,   638,   294,   295,
     371,   215,   296,   474,   475,   131,   132,   133,   134,   135,
     136,   137,   138,   297,  1306,  2197,  2254,   999,  1302,  1303,
     298,  1088,   299,   142,  1530,  1269,   971,  1014,  2130,   143,
     144,   145,   146,   300,   301,  1225,  1242,  1375,   302,   832,
     303,   831,   495,   655,   338,  1853,   375,  1965,   376,   305,
     596,   390,  1401,  1633,   485,   480,  1368,  1068,  1682,  1846,
    1847,  1053,   487,   148,   400
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1973
static const yytype_int16 yypact[] =
{
   14216,    46,   154, 14426, -1973, -1973,  -137,    87,    10,  -120,
     -95,   -41,    31,   181,   190,   229,   307,    59,    42,    48,
      95,   331,   340,   117,   128,    27,  -199,   648,  -199,   104,
     137,   163,     6,   178,   221,    54,   232,   266,   269,   294,
     317,   327,   375,   399,   415,   420,   150,   310,   343,   563,
     682,   431,   438,     4,   613,   484,  7690,   501,   474,   518,
     690,   -65,   700,   648,   370,   361,   525,   714,  -108,   541,
     -80,   -80,   551,   -19,    52,   561, -1973, -1973, -1973, -1973,
   -1973,   577,   507,   740,   766,    16,    60,   846,   778,   759,
     -31,  6910,   774,   897,   907,   923,  6910,   925,   -74,   -58,
     680,    19,    56, -1973,   688,   689, -1973, -1973,  5209,   946,
     706, -1973,  6770,   713, 13261,    25,    29,   648, -1973, -1973,
   -1973, 13139,   727,   971, -1973, -1973, -1973, -1973, -1973,   742,
   -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973,
      11, -1973, -1973, -1973, -1973,    21, -1973,  1022,   765,  6648,
     382,   802,  1065, 13139, 14615, 14615, 14615, -1973, 13139, -1973,
   -1973, -1973, -1973, 14615, -1973, 13139, -1973, -1973, 13139, -1973,
   -1973, -1973, -1973,   805,   810,  1067, -1973, -1973, 14678, -1973,
   -1973, -1973, -1973,   815, 14678, 13139, 13139, 13139,   816, 13139,
   13139, 13139,   817, 13139, 13139, 13139, 13139, 13139, 13139, 13139,
   14615, 13139, 13139, 13139, 13139,  6910,   819, -1973, -1973, 10800,
   10800, -1973, -1973, -1973,   818,  6910,  7950, 14615, -1973, -1973,
   -1973, -1973, -1973,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   500,
    -199,  -199,  -199,  -199,  -199,   820,  -199,  -199,   821,   648,
     578,   578,   578, -1973, -1973, -1973,  -199,  -199,    34,   887,
     888,   889,   823,   981,  7950,   956,   648,   648,   578,   830,
    -199,  -199,   831,   832,   833, -1973, -1973, -1973, 13139,  8210,
   13139, 13139,  8470,    27,   899,    38, -1973, -1973,   834, -1973,
    4916, -1973, -1973, -1973, -1973, -1973,   125, 13139, 10800, 10800,
     836,   837,  8730,  6910,  6910,  6910, -1973, -1973, -1973,   839,
   -1973,   840,   841,  8990,   843, 11407,  1098,  7950,   844,    19,
     847,   848,   -80,   -80,   -80, 13139, 13139,   172, -1973,   203,
     -80, 11495,   251,   291,   845,   853,   854,   856,   857,   877,
     879, 10800, 13139,  6910,  6910,  6910,   304,    28,  1099,   878,
   -1973,  1138,  1142, -1973,   883, -1973,   884,   885, -1973, -1973,
     892,  6910, -1973, 13139,  2451, -1973,  1162,   924,   929,   931,
     932,  1191,  1192,   937, 13139,   939, 13139, 13139,   562, 13139,
     936, -1973,  1005, 13139, 13139, 13139, -1973,  -199, 13139,  1164,
     136, -1973, 13139, -1973,  -199,  -199,  -199,   944,   945,   947,
    -199,  -199,  -199,  -199,  -199,  -199,  -199, -1973,  -199, -1973,
   -1973, -1973, -1973,  -199,  -199,   948,   949,  -199,   950, -1973,
     953,  1207,  1212,   954, -1973, -1973,  1213,  1214,  1215,  1216,
     961, 16030, 14615, -1973, 10800, 13139, -1973, -1973,  7950,  7950,
   -1973,   959, 14678,   648,  1219, -1973, -1973, -1973, -1973, -1973,
   -1973, 13139, 13139,    24,  7950,  1222,   800,   963,  1603,   964,
    1225,    70,   966, -1973,   967, 14810, 13139, -1973,  1974,   -26,
   -1973,    63,    -4,   173,  6558, -1973,   214, -1973,    71,  7102,
    5567,  7362,   -93,   123,  1135, -1973,    27,   965, 13139,   968,
   13259, 16546, 16571, 13139, 16596, 16621, 16646, 13139, 16671, 16696,
   16721, 16746, 16771, 16796, 16821,   972, 16846, 16871, 16896,  5068,
    1230, 13139, 10800,  5250, -1973,   369,   448, 13139,  1232,  1234,
     979, 13139, 13139, 13139, 13139, 13139, 13139, 13139, 13139, 13139,
   13139, 13139, 13139, 13139, 13139, 13139, 13139, 13139, 10800, 13139,
   13139, 13139, 13139, 13139, 13139, 13139, 13139, 10800, 10800,   977,
   13139, 13139, 14615, 13139, 14615,  7950, 14615, 14615, 14615,   978,
     980,   982,   983, 13139,    36, -1973, 11755, 13139,   985,  7950,
    6910,  7950,   986, 14615, 14615, 10800,    27, 14678,    27,   984,
   10800,   984, -1973,   984, 16921, -1973,   450,   987,    91,  1179,
   -1973,  1245, 13139, 13139, 13139, 13139, 13139, 13139, 13139, 13139,
   13139, 13139, 13139, 13139, 13139, 13139,  9250, 13139, 13139, 13139,
   13139, 13139,    27, 13139, 13139,   411, -1973,   804, 16946,   485,
     506, 13139, 13139, 13139, -1973,  1247,  1253,  1253,   999, 13139,
   13139, 13139, 13139,    23, 10800, 10800, 16058,  1001,  1256, -1973,
    1000, -1973, -1973,  -182, -1973, -1973,  7622,  7882,   -80,   -80,
     382,   382,  -174, 11495, 11495, 13139, 11462,  -156, -1973, 13139,
   13139, 13139, 13139, 13139, 13139, 13139, 13139, 13139,   558, 16971,
    1258,  1263,  1264, 13139, 13139,  1266, 13139, -1973, -1973, 13139,
   11810, -1973, -1973, 10800, 10800, 10800, 13139,  1267, 16996,  1003,
   13139, 10800, 13139, 13139, 13139, -1973, -1973, 13139, 17021, 13139,
   17046, 17071,  1079,  8142, -1973,  1009,  5688, 17096, 17121, 13139,
     984, -1973, 13139,    27, 13139, 13139,   411, 16141, 14615, 14615,
   14615, 14615, 14615, 14615, 14615, 14615, 14615, 13139, 14615, 14615,
   14615, 14615,    15, 14678, 14615, 14615, 14615,    27,    27, -1973,
   -1973, 10800, -1973,  1010, 12503, -1973,  1011, 12846, 13139, -1973,
    1014,   595, 17146, 14677,  1013,   603, 13139,  1274,  1015,  7950,
   17171, 16168, -1973, -1973, -1973, -1973, -1973, -1973,  1016,  1278,
     183,  1280, -1973, -1973, -1973, 10800,   227, 13139, -1973, -1973,
   -1973,    27, 13139, 13139,   411,  1023, -1973,  1026,   -64,   648,
     370,   648, -1973,  1024,  5843, -1973,    18, 10800,    27, 13139,
   13139,   411,  1283, 10800,  1285, 10800, 13139,  1286, 14615,    27,
   11843,   411, 13139, -1973, 13139,  1287, -1973,    27,  1288, 14615,
   13139,  1032,  1033, -1973, 13139,  8402, 14678,  1289,  1291,  1292,
   17196,  1293,  1295,  1296, 17221,  1297,  1299,  1300,  1301,  1302,
    1303,  1304, -1973,  1306,  1308,  1310, -1973, 13139, 17246, 10800,
    1052, 10800,    49,  6134, -1973, -1973,  1313, 16114, 16114, 16114,
   16114, 16114, 16114, 16114, 16114, 16114, 16114, 16114, 16114,  8662,
   16114, 16114, 16114, 16114,  1248,   594, 16114, 16114, 16114,  8922,
    9182,  9442,  9697,  9952,  5250,  1059,  1058,   149, 10800, 10212,
   10472,   594, 10732,   594,  1053,  1054,  1055,   279, 10800, 13139,
   13139, 13139, 18196, -1973,   594,  1060, 15131, 15160, 10800, -1973,
   -1973, 13139,  1057,  -149,   594,   -40,  1066,  -121,   618,  1324,
   -1973,   411,   594,  7950,  1070,  5717,  5820,   882,   378,   751,
     751,   626,   626,   626,   626,   626,   626,   537,   537, 10800,
     547, -1973,   547,   547,   984,   984,   984,  1064, 17271, 16195,
     591, 10800, -1973,  1327,  1072,  1073, 17296, 17321, 17346, 13139,
    7950,  1336,  1335, 11152, 17371, 15189, 17396, 17421, -1973, 13139,
     623,   625, 10800,  1074, -1973, 13421, -1973, 13524, 13586,   -80,
   13139, 13139, -1973, -1973,  1076,  1077, 11495,  3235,  1199,   314,
     -80, 13660, 17446, 15218, 17471, 17496, 17521, 17546, 17571, 17596,
   17621,  1080,  1340, 13139,  1343, -1973, 13139, 17646, 15247, -1973,
   16222, 13721, 16249, -1973,   631,   633,   636, 15276, -1973, -1973,
   -1973,  2018,   639, 16276, 16303, 11086, 17671,  1344, 17696,  1345,
    1347,  1082, 13139, 13795, 13139, 13139, -1973, -1973, 16114,   547,
    1087,   601,    39,   -82,   249,   -82,  1093,  1095,  1088,   594,
     594,  1089, 11438,   594,   594,   594,   594, 13139,   594,  1352,
   -1973,  1091,  1100,   490,   242,  1102,   641, -1973, -1973, -1973,
   -1973, 17721, 13856,  1094,  1167,  1362,  1203, 12098,  1106,  1109,
    1370,  7950, 15305, -1973, 13139,  1371,   191,   142,   411,    22,
   14678, 13139,  1372, -1973,   646,  1329,  1330,  7950, 15334,   157,
    1113, 17746, 16330,   512, 13139, 13139,  1120,  1117,  1123,  1121,
    9510, -1973, -1973, -1973, -1973, 14615,   280,  1118, 17771, 16357,
    1126, -1973,   321, -1973,   447, 11786, -1973, -1973, -1973,  1122,
   -1973,  1127, 15363, 12053, -1973,    85, -1973, -1973, 18196, -1973,
     101, 16114, 13139,   594,   -80,  7950,  7950,  1384,  7950,  7950,
    7950,  1385,  7950,  7950,  7950,  7950,  7950,  7950,  7950,  7950,
    7950,  7950,  2144,  1386, 10800,  5250, -1973, -1973,   382, -1973,
   -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973, -1973, 13139, -1973, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973, -1973, 13139, 13139, 13139, 13139, 13139, -1973, -1973,
   -1973,   652, 13139, 13139, -1973, 13139, -1973,  7950, 14615, 14615,
   -1973,   654, 15392, 15421, 15450,  1124, -1973, -1973, -1973,  1196,
     655, 15479, 13139, 13139, -1973, -1973, -1973,   411, -1973,   411,
   13139, 13139,  1133, -1973,  7950,  -199, -1973, -1973, -1973, 13139,
   13139,   657,   411,    -6,   -60, 13139, 13139, -1973,   594,   666,
    7950, 10800, 10800,  1391,  1392,  1393,  2597, -1973, -1973,  1395,
   -1973,  1158, 18196,  1152,  1417, -1973,  1419,  1421,  2179,  1423,
    1424,   667,   462, -1973, 13930, -1973, -1973,   -94, 12129, 12479,
   -1973, -1973, 15508,  -119,  1311,  1430, 12193,  1169,  1433,  1174,
      35,    41,    -2, -1973,   -66, -1973,   314,  1434,  1436,  1438,
    1439,  1441,  1442,  1443,  1445,  1447,   382,  7950, 18196, -1973,
    2508,  1177,  1337,  1451, -1973,  1453,  1455,  1354,  1458, -1973,
   -1973,  1460,  1462,  1464, 13139,  1465,  7950,  1467,  7950,  7950,
    1471, 12822, -1973,  6034,  1448,   411, 13139, 13139,   411,   411,
   -1973, 10800, -1973, -1973, -1973, -1973, 14615, -1973, -1973, 13139,
   14615, -1973, -1973, -1973, -1973, 18196, -1973,  1210,  1209, 14615,
   -1973, 14615, -1973,   411, 14615,  1220, -1973,  1211,  1478, -1973,
    1239,   648,  1240, 12448, -1973,  2532,  1241,  7950, -1973,  1218,
   -1973, 15537, -1973, -1973, 13139,  1502,    80, 13139,  1504,  1505,
      19,  1508,  1252,  1511,  2684, -1973,   594,  -199,  -199,  1512,
   -1973, -1973,  1257,  1259,  1254, -1973,  1516, -1973, -1973, -1973,
   -1973, -1973, -1973,   411,   281,  3530, 13139, 16384, 17796, 13139,
    9765, 13139, 10800,  1261,   668,  1520,   129,   411, -1973,  1262,
   13139,  1523,  1528, 13139,   411, 12536,  1529, 13139,  5322,   594,
    6102, 13139, 13139, 13139,  1272,  1268, -1973,  1532, 17821,  1534,
      90,  1402,  1402,  7950,  1536,  1537,  1538,  7950,  -113,  1539,
    1540,  1541,  1542,  1543,  1545,  1546,  1550,  1554, -1973,  1557,
     669,  1298, 16114, 16114, 16114, 16114, 16114, 16114,   594, 13998,
   14215, 14610,  1309,   594,   594, -1973, -1973, -1973, -1973,   101,
     594, -1973, -1973, 17846, 16114,  1314,  -181, 18196, 16114, -1973,
    1558,   594, 18196, 18196, -1973,   605, -1973,   411, -1973, 17871,
   16411, -1973,   594,  1560,   676,   677,  7950,  7950,  7950,  1559,
    1561, -1973,   237, 13139,  7950,  7950,  7950, -1973,  1305,  1312,
    1569,  1573,  1574, -1973, 13139, 13139, 13139,  1316,  1317,  1319,
    1323, -1973,  2708,  7950, -1973, 13139, -1973,  1582, -1973,  1583,
   -1973, -1973, 11495,   530,  7170, -1973,  1325,  1326,  1328,  1331,
    1334,  1338, 10020,  1339,  1584, -1973, 10800,  1341, -1973, -1973,
   -1973,  1342, 13139, 13139, -1973, -1973, 16438,  7950,  1587,  7950,
    1589,  1407, -1973, 13139, 13139, 13139, -1973,   629,  1590,   838,
     504,  1332,  2894,  1346, 13139,     7,   594,  1348,   594,  1349,
   -1973, -1973, 14678, -1973, 13139,  1350, -1973, -1973,  2731, -1973,
   -1973,  1351,  1596, -1973,  2821, -1973,  1353,  1598,   196,  3487,
   -1973,    19, -1973,   678, -1973, 13139, -1973, -1973,   237, 13188,
   13375, -1973,  1318, 13139, 13139,  7950,  1357, -1973,   141,   478,
    1604, 17896,  1607,  1324, 17921,  1358,   686, 17946,   692,  1608,
    1609, -1973, -1973, 14615,  1356,  1615, 17971, -1973, -1973, 14735,
    1364, -1973, -1973,  3304,  6388, 18196, -1973,  1617,  -199,  8470,
   -1973, -1973, -1973, 18196, 18196, 18196, -1973,   101, -1973,  1621,
   -1973, -1973,   -80,  1623,  1624,  1625, -1973, -1973, -1973,  1486,
     -36,  1526,  1628, -1973, -1973, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973,  1630,  1373,  1632, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973, 13139, 13139, 13139, -1973, -1973, -1973,  1268, -1973,
   -1973, -1973, -1973, 13139,  1377,  1374, -1973, -1973, 13139, 13139,
     594,    -6, -1973, -1973, -1973, -1973,  1375,  1378,  1637,  -113,
    1640, 13139, -1973,  7950, 18196,  1501,  1503,   910, 10800, 10800,
   13139, -1973, 11152, 15566, 17996,  4688,   382,   382, 13139, 13139,
   -1973,   404,  1379, 18021, -1973, -1973, 15595,   -35, -1973,  1642,
    1645,  7950,   -80,   -80,   -80,   -80,   -80,  7430,  1646, -1973,
   -1973,   693, 10800, 13139,  3591,  3621,  1647,  1648, -1973,  1649,
   -1973,  7950,  6320,   933, 18046, 13139, 13139, -1973, -1973,  5786,
   -1973, 14615, 13139, -1973, 14615, 18196, 11055, 14678,  1387, -1973,
   -1973, -1973, -1973,  1396,  1390, 15624, 13139, 14677, -1973, 14677,
    7950, -1973, -1973,   411,    22, 14678, 13139,  1650, -1973,  1656,
   -1973,    19, 16465,  7950, 14615,  1657,   594, -1973,  1394,   594,
   13139, 14768, 14801,   694, -1973, 13139, 13139,  1398, -1973,  1400,
   -1973,  1393,  1661,  1662,  1421,  1663, -1973, -1973,  1664, 13139,
   -1973, -1973, 13139, 12791,  1666, 13139, -1973, -1973,  1408, 13375,
     695,  4892,  1668, -1973, -1973,   208, -1973, -1973, -1973,  1527,
    1667,  1412,  1413,  1414, -1973,  1678,  7950, -1973, 16114, 16114,
   14834, 16114, -1973,  1422, 18071, 16492, -1973, -1973, 10800, 10800,
   -1973,  1699, -1973, 18196,  1700, 13139, 13139,  1418, -1973,   701,
     702, 16086,  3873,  1701,  1444, -1973, -1973, 13139,  1446,  1449,
   15653, 16519,  1702,  7950,  1705,  1452, 13139, -1973, -1973,   709,
     -25,   -21,    -9,   247,   256, 10280,   258, -1973,  1708,   711,
   15682, -1973, -1973, -1973, -1973, -1973,  1522, -1973, 13139, 13139,
   -1973, -1973, 12879, 10540,  4446,  1711,  1722,  1475, 16114,   594,
   18196, -1973, -1973, -1973, -1973,     7, -1973, 14678, -1973, 15711,
    1472,  1476,  1477,  1727,  1740,  1741,  4541, -1973, -1973, -1973,
    1481,  1745,   716, -1973,  1746,  1747,   451, 18196, 13139, 13139,
    1491,  7950,   719, 18196, 18096, -1973, -1973, -1973, -1973, 18121,
   14867, -1973, -1973, 15740,  1124,  1209,  7950,   594, -1973, 13139,
   14678,    27, -1973, -1973, 10800, 10800, 13139,  1754,   721, -1973,
   -1973, 13139,  1374, -1973, -1973, -1973,   722,   743, -1973, -1973,
    4578,  4606,  7950,   662,   671, 10800, -1973, -1973,   382,  6842,
   -1973, -1973, -1973,  1756, -1973,  1496,  7950, -1973, 15769,  1758,
   10800,   -80,   -80,   -80,   -80,   -80, -1973,  1760, -1973, 13139,
   15798, 15827, 10800, -1973,   744, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973,  1506,  1761,  1507, -1973,  1762,    19, -1973, -1973,
   -1973,  1575, -1973, -1973, -1973, -1973, -1973, 13139, 14900, 14933,
    7950, -1973,  1764, 13139,  1509, -1973, 13139,  1766,  1510,  1515,
   -1973, -1973,   356, -1973,  1514,   746,   749, 15856, -1973,  1513,
   14966,  1524, -1973,  1517, -1973, -1973,   752,  1519,   -80,  7950,
    1768,  1525,   -80,  1780,   754,  1521, -1973, 13139, -1973,  1787,
    1651, 13991,  1530, -1973,   755,   275,   287,   322,   364,   412,
   -1973,  4835, -1973, -1973,   760, -1973,  1788, -1973, -1973, -1973,
    1789, -1973,  1533, 18196, 13139, 13139,   762, -1973, 18196, 14999,
   -1973, -1973, -1973,  1124, 14678,  1544, -1973, -1973, -1973, 13139,
   13139, -1973, 10800,  1794,   -80,   119, -1973, -1973,   -80,   122,
   -1973,  1795, -1973, 15885, -1973, 13139, -1973,   314, -1973,  1796,
   10800, 10800, 10800, 10800, 10280, -1973, -1973, -1973, 14677, -1973,
   13139, 18146, 15032,    51, 13139,  1547, -1973, -1973, 15065, 15098,
     763, -1973,   422, -1973,   428, -1973, -1973, -1973,  4868,   604,
   14065, -1973,   769,   770,   771,   776,   430,   777,  1548,   782,
   -1973, 13139, -1973,  7950, 15914, -1973, 13139, 13139, -1973,   -80,
     -80, -1973, -1973, -1973,   314,  1797,  1798,  1799,  1800, 10800,
    1804,  1806,  1807,  1551, 18171,   784,  1810, 15943, 16114,   445,
     452,   619, -1973, -1973, -1973, -1973,   785, -1973, -1973, -1973,
   14615, -1973,  1552, -1973,  1813, -1973, 13139, 13139, -1973,  1815,
     790, -1973,  1556,  7950, -1973, 15972, 16001, -1973,  1817, 14615,
   14615,   791,  1818,  1819, -1973, -1973,   793, -1973,  1820, -1973,
   -1973,  1822, 14615, -1973, -1973, -1973
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1973, -1973, -1973, -1973,   393, -1973, -1973, -1973, -1973,  -380,
   -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973,  -774,  -142,  3958,  4134,  -364, -1973,  1367, -1973,
   -1973, -1973, -1973, -1973, -1973, -1972, -1973,   362,   152,  -153,
   -1973,  -112, -1973,   116,   405, -1973,  1863, -1973,   991,   -51,
   -1973, -1973,    14,  -646,  -165, -1973, -1973, -1973, -1973, -1973,
   -1973, -1973,   761,  1865, -1973, -1973, -1973, -1973, -1298, -1297,
    1866, -1811,  1868, -1973, -1973, -1973,  1235, -1973,  -171, -1973,
   -1973, -1973, -1973,  2707, -1973, -1973, -1502,   265,  1872, -1973,
       0, -1973, -1973,    50, -1973, -1772,   989, -1973,   -75,  3722,
    3696,  -326,    43, -1973,   102,   -76, -1973, -1973,    62,   239,
   -1767,  -162,  1062, -1973,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -597
static const yytype_int16 yytable[] =
{
     149,   486,   490,   650,  1734,  1561,  1101,   465,  1563,  1939,
     188,  1816,  1107,   323,   994,   995,  1980,   130,  1981,   173,
     357,   381,   175,   388,  1122,   174,   173,   447,   772,   978,
     436,   173,   685,  1700,   438,   383,   431,   157,   435,   575,
     173,  1556,  2108,   600,   311,   311,  1348,  1558,   164,  1973,
     773,   385,     4,   306,   166,  1177,   343,  2242,   192,   328,
     392,   774,   775,   176,   362,   177,   363,  1891,   658,   659,
     312,  1116,   808,   470,   173,   368,   658,   659,   369,   791,
     819,   176,   361,   177,   772,  1701,  1892,   329,   306,   989,
    1240,   370,  1448,   306,   658,   659,  1691,   996,   391,   780,
     496,   152,   497,   330,   331,  1450,   773,   211,   499,   432,
     212,   358,  2017,   213,   783,  1000,   784,   774,   775,   153,
     337,   339,  1233,   342,  2028,  2223,   214,  1451,  2225,   150,
     520,   658,   659,   151,   622,  1662,   776,   777,  1452,  1453,
     528,   176,   154,   177,  1295,   723,   471,  1239,  1548,  1393,
    1240,   481,   481,   481,     5,   344,   658,   659,   622,   345,
     488,  1411,  1296,   364,   473,   346,   347,   155,   348,   349,
     333,   334,   825,  1297,  1298,  1299,   666,  1544,   826,  1300,
    1301,   783,   335,   784,   658,   659,   336,   159,   384,   818,
    1100,   350,   776,   777,   979,   690,   160,   481,  1393,   459,
     460,  2215,   306,  1835,   386,  1562,   306,   306,  1517,   570,
     571,   572,   306,   306,   481,   658,   659,  1817,  1557,   778,
     779,   156,   359,  1236,  1559,   658,   659,   582,  1237,   658,
     659,   333,   334,  1903,  1105,   161,  1936,   806,   635,   636,
     637,   658,   659,   335,  1393,   807,  2060,   341,   122,   122,
    2061,   469,   122,   459,   460,   122,   479,   482,   483,   812,
     122,   960,  2062,  1123,  1124,  1560,  1561,   813,   189,   122,
    2126,   306,   754,   445,   757,  1626,  1627,   446,   680,   681,
     682,   763,   360,   448,  1067,   389,   306,   449,  1400,   306,
     598,   437,   686,   597,   687,   439,   697,   158,   151,   783,
     576,   784,   515,   122,   601,   306,   306,  1349,   165,   306,
     306,   306,   306,   162,   167,  1178,   193,  2243,   393,   530,
     306,   163,  1394,  1397,   306,   809,   391,   810,  2166,   459,
     460,   811,   792,   820,   793,   810,  -589,   169,   794,   821,
     658,   659,  1412,  1413,  1414,  1415,   170,   176,   306,   177,
     306,   306,   306,   176,   102,   177,   103,   104,   105,   106,
     107,   168,  1051,  2174,   111,   112,   185,   114,   306,   658,
     659,   306,   658,   659,  1123,  1124,   767,   455,   456,   457,
     458,   171,   653,   654,   459,   460,   472,   623,   828,   624,
     662,   667,   172,   625,   826,   459,   460,  2238,   724,   186,
     725,   459,   460,  1856,   726,  1806,   907,  -593,   459,   460,
    1396,   623,   602,   624,  1210,   772,   204,   625,   455,   456,
     457,   458,   658,   659,  1416,   187,   455,   456,   457,   458,
    1113,   455,   456,   457,   458,   205,   814,   773,   660,   481,
     190,   306,   459,   460,   815,   306,   306,  1130,   774,   775,
     459,   460,   206,   658,   659,   459,   460,  1141,   658,   659,
    1295,   306,   455,   456,   457,  1106,  1541,   324,   795,   661,
     325,  2265,   455,   456,   457,   458,   317,   817,  1296,   318,
     319,   320,  1857,   191,   985,   818,   987,   988,   773,  1297,
    1298,  1299,   321,   833,   194,  1300,  1301,   658,   659,   774,
     775,   658,   659,  1001,   773,   919,   658,   659,   658,   659,
    1373,   926,   783,  1374,   784,   774,   775,   668,  2063,   306,
    1351,  2301,  1021,   776,   777,   658,   659,  2064,   195,  2065,
    2121,   196,  1481,    69,    70,    71,    72,   658,   659,    75,
     459,   460,  1220,  1436,   760,   306,  2200,  -591,    84,  1043,
     818,   861,    88,   669,   306,   897,   197,   670,  2201,   481,
     322,   481,   306,   481,   481,   488,   683,  1245,  1055,   207,
     684,   914,   658,   659,   776,   777,   306,   306,   306,   198,
     481,   481,   306,   175,  1441,   175,   925,   306,   927,   199,
     776,   777,   861,  2202,  1082,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,   306,   658,   659,   353,   621,   354,   957,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,  2203,   860,   200,  1102,   621,
     861,   306,   306,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   201,   658,   659,   901,   621,   903,  1070,   905,   906,
    1573,  1932,   658,   659,   473,   473,  1295,   202,   658,   659,
     658,   659,   203,  2204,   317,   922,   923,   318,   208,   320,
     306,   306,   306,  2249,  1296,   658,   659,   209,   306,  2250,
     321,  2259,   658,   659,   210,  1297,  1298,  1299,   992,   993,
    1442,  1300,  1301,   654,  2096,   862,  2286,   930,   861,   861,
    1050,   861,  2097,  2287,   216,   488,   481,   488,   481,   481,
     481,   481,   481,   481,  1399,   481,   481,   481,   481,  1069,
     308,   481,   481,   481,   175,  1075,   217,  1074,   306,  1118,
    1295,   179,   964,   783,   180,   784,   861,   181,  1753,   182,
    1153,  1371,   557,   307,   558,  1295,   306,   783,  1296,   784,
      46,   459,   460,   965,  1426,   861,  1347,   861,  -592,  1297,
    1298,  1299,   306,  1296,   309,  1300,  1301,   326,  1110,   722,
     617,   618,   619,   620,  1297,  1298,  1299,  1778,   621,   310,
    1300,  1301,   619,   620,   306,  1127,   313,   332,   621,   314,
     306,   315,   306,  2127,  2128,   488,  1139,   340,  1257,  2129,
     327,  1284,  2131,  2132,  1145,  1011,   481,   351,  2129,   861,
     712,  1054,   151,  1056,  1057,  1058,  1059,  1060,  1061,   352,
    1063,  1064,  1065,  1066,  1808,  1809,  1071,  1072,  1073,   355,
     459,   460,   365,  1255,  1836,  1256,   306,   783,   306,   784,
     459,   460,  1084,  1346,  1843,  1347,   861,  1738,   367,  1739,
    1090,  2252,   356,  1505,  1091,  1506,   614,   615,   722,   617,
     618,   619,   620,   377,   366,  1243,  2288,   621,  1515,   861,
    1279,  1805,  1280,  1806,   861,   306,   861,  1273,  1326,  2229,
    1327,   378,   861,  1328,   861,   306,  1331,   861,  1377,  1257,
     861,   379,   861,  1406,  1917,   306,  1918,   861,  1542,  1488,
    1137,  1495,  1501,   861,  1514,   861,   861,   380,   861,   382,
     306,  1147,  1561,  1522,  1540,  1660,  1713,   861,   861,   861,
     861,  1959,   387,  1746,  1747,  1840,   306,   861,   861,  1841,
     394,   395,   401,  1863,  1395,  1398,  2271,   861,   306,  1865,
    1948,  2000,  2018,   861,   861,  2001,  2019,   306,  2043,  2044,
     402,  1257,   861,   861,  1561,   433,  2059,   443,  2067,   306,
    2001,  1597,   861,  2093,  1598,  1599,  2102,   818,  2119,  2122,
    2103,   442,  2001,   861,   129,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,   444,  1609,
    2123,  2155,   621,  2176,   861,   861,  2177,   861,   183,  2183,
     861,  2191,  2199,  2001,  1403,   861,   861,  2206,   450,  2213,
    2248,   861,  1628,  2001,   861,   451,  2255,  2256,  2257,  1287,
     861,   861,   861,  2258,  2260,   304,  1293,   861,   861,  2262,
    1304,  2282,  2289,  2103,   316,  2001,   861,  2298,  2308,  1648,
    2311,  2299,  2001,   783,  2312,   784,   785,   783,   476,   784,
     961,   477,   494,  1664,  1632,   151,   496,   498,   503,   507,
    1670,   521,   565,   568,   527,  -208,  -209,  -210,   306,   577,
     578,   579,   583,   586,   587,   588,  1402,   599,   631,   632,
     446,   639,   647,   641,   306,   688,   640,   671,   440,   644,
     649,  1516,  1518,   651,   652,   672,   673,   306,   674,   675,
    1928,  1929,   481,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,   676,
     467,   677,   689,   621,   691,   467,   467,   467,   692,   693,
     694,   695,   306,   306,   467,   306,   306,   306,   696,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   700,
     721,   306,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
     701,   467,   473,   702,   621,   703,   704,   705,   706,   707,
    1960,   709,   714,   715,  1460,   529,   731,   732,   467,   733,
     744,   745,   747,   749,   306,   481,   481,   748,   750,   752,
     751,   755,   753,   758,   756,   766,   769,  1435,   782,   787,
     789,   790,   150,   830,   796,   852,   834,   857,   864,   836,
     865,   306,   866,   898,   908,   621,   909,   933,   910,   911,
     569,   918,   921,   934,   969,   931,   602,   306,   306,   306,
     970,   973,   984,   304,   983,  1013,   986,   580,   581,  1015,
    1030,  1016,  1019,  1028,  1041,  1044,  1089,  1077,  1079,  1083,
    1093,  1094,  1516,  1518,  1098,  1099,  1103,  1114,  1115,  1131,
    1120,  1133,  1136,  1144,  1146,  1149,  1154,  1150,  1155,  1156,
    1158,   634,  1159,  1160,  1162,  1839,  1163,  1164,  1165,  1166,
    1167,  1168,   643,  1169,   306,  1170,   648,  1171,  1174,  1180,
    1493,  1494,  1208,  1209,  1217,  1218,  1219,  1227,  1232,  1238,
     473,  1244,  1252,   306,  1260,   306,   306,  1248,  1261,  1262,
    1268,  1270,  1282,  1290,  1291,  1294,  1316,  1317,   306,  1319,
    1340,  1336,  1338,   481,  1339,  1345,  1354,   481,  1355,  1356,
    1359,  1367,  1369,  1370,  1380,  1381,   481,  1376,   481,  1382,
    1383,   481,  1676,  1386,  1681,  1387,  1388,  1392,  1405,  1407,
    1408,  1423,  1429,  1430,   306,  1431,  1437,  1432,  1440,  1445,
    1444,  1463,  1467,  1479,  -211,  1499,  1509,   391,  1526,  1527,
    1528,  1531,  2135,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,  1532,   481,  1533,  1534,   621,  1535,   306,  1536,   306,
    1538,  1539,  1549,   467,  1550,  1553,  1555,   764,   765,  1554,
    1577,  1564,  1565,  1576,   768,  1566,  1567,   306,  1568,  1569,
    1570,  1827,  1571,   781,  1572,  1829,  1595,  1578,  1601,  1579,
     306,  1580,  1603,  1581,   306,  1582,   803,  1583,  1584,  1983,
    1585,  1607,  1587,  1608,  1589,  1592,  1610,  1848,  1848,  1604,
    1605,   803,  1612,  1611,  1613,  1622,  1837,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     859,   617,   618,   619,   620,  1614,  1616,  1620,  1625,   621,
    1630,   783,  1631,   784,  1634,  1989,  1635,  1636,  1641,  1643,
    1645,  1644,  1647,   306,   306,   306,  1661,  1650,  1659,  1667,
    1665,   306,   306,   306,  1668,  1672,  1824,  1686,  1688,  1687,
    1690,  1692,  1696,  1697,  1698,  1703,  1704,  1705,  1706,  1707,
     306,  1708,  1709,   467,   904,   467,  1710,   467,   467,   467,
    1711,   306,  1712,  1751,  1736,  1714,  1745,  1752,   634,   306,
     920,  1758,  1725,   306,   467,   467,  1760,  1732,  1759,  1761,
    1850,  1762,  1766,  1767,   306,  1768,   306,  1769,  1774,  1775,
    1790,  1781,  1782,  1798,  1783,  1800,  1807,  1784,  1877,  1907,
    1785,  1801,  1831,  1811,  1786,  1834,  1789,  1792,  1793,   788,
    1858,  1821,  1777,  1860,  1866,  1867,  1826,  1814,  1869,  1870,
    1374,  1833,  1830,  1855,  1878,  1862,  1873,  1884,   391,  1886,
    1887,  1888,  1889,  1893,  1894,  1895,   488,   488,  1897,  1896,
    1902,  1908,   306,  1910,  1909,  1240,  1912,  1915,  1937,  1916,
    1933,  1938,  1947,  1953,  1954,  1955,  1987,   803,  1975,  1976,
     481,  1977,  1988,  1993,  -596,   818,  -594,  2005,  2006,  2007,
    2008,   306,  2012,  2023,  2016,  2021,   306,  2022,  2024,  2025,
    2026,   803,  1992,  2027,  2042,  2033,  1923,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,  2038,  2039,  2047,  2054,   621,
    2048,  1596,  2056,  2050,  2066,  2069,  2051,  2076,  2057,   467,
     467,   467,   467,   467,   467,   467,   467,   467,  2077,   467,
     467,   467,   467,  1966,  2087,   467,   467,   467,  2078,  2084,
    1971,  1974,  1885,  2085,  2086,   803,  2088,  2089,   803,  2091,
     306,  2092,  2094,  2095,   803,   306,   306,  2100,  1095,  1985,
    2118,  2160,  2138,  2139,  2143,  1868,  2150,  2157,  2159,  2156,
    2167,  2161,  2170,  2158,  2187,  -595,  2175,  2171,   306,  2179,
     473,   473,  2172,  2182,   306,  2184,  2190,  2181,  2192,   306,
    1117,  2188,  1119,  2194,  2207,  2209,  2198,  2195,   306,  2210,
    2221,  2226,  2231,  2272,  2273,  2274,  2275,  2217,   481,   467,
    2277,   481,  2278,  2279,  2245,  2261,  2283,  2280,  2293,  2294,
     467,  2297,  2300,  2304,  2309,  2310,  2313,   306,  2314,  1663,
    2239,  1402,  1940,  1941,  1942,  1943,  1944,  1946,   391,  1883,
     306,   488,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
     829,  1728,  2109,  2081,   621,  1911,   128,  1694,   139,   140,
    1422,   141,   972,  2133,  1823,   147,   488,  1984,  1972,  1849,
    1138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2141,   306,     0,     0,     0,     0,     0,     0,
       0,  2082,     0,     0,     0,   306,   306,     0,     0,     0,
       0,     0,     0,  1967,     0,     0,  1969,     0,     0,     0,
       0,     0,  1247,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,  2113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1267,
     306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   803,     0,   803,   803,
     805,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   803,  2208,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   803,   306,     0,     0,     0,     0,  2114,     0,
       0,   306,   306,     0,  1330,     0,     0,     0,     0,     0,
       0,     0,     0,  2230,   803,     0,     0,     0,     0,   306,
       0,     0,   306,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,   306,     0,     0,
       0,     0,   473,     0,     0,     0,     0,     0,     0,   306,
       0,     0,     0,   803,     0,     0,     0,     0,     0,     0,
    1389,     0,     0,     0,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1409,   306,  2216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2145,  2146,  2147,  2148,  2149,   467,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1461,  1462,     0,  1464,  1465,  1466,
    1478,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,
    1477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2185,   306,
       0,     0,  2189,     0,     0,  1537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   306,   306,   306,
     306,   306,     0,     0,     0,     0,  1492,     0,     0,   467,
     467,     0,     0,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,  1510,  2222,   621,     0,     0,  2224,     0,
     306,     0,     0,     0,     0,     0,     0,     0,     0,  1523,
       0,     0,     0,     0,  2236,     0,   306,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,   803,     0,   481,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,     0,     0,     0,     0,     0,   481,   481,     0,  2269,
    2270,     0,     0,     0,     0,     0,  1574,     0,     0,   481,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1588,     0,  1590,  1591,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   467,     0,     0,
       0,   467,     0,     0,     0,     0,     0,     0,     0,     0,
     467,     0,   467,     0,     0,   467,     0,     0,     0,     0,
       0,     0,  1615,     0,     0,     0,  1621,     0,     0,     0,
       0,     0,  2291,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,  2305,  2307,     0,     0,   621,     0,     0,     0,     0,
       0,     0,     0,     0,  2315,     0,   467,     0,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,  1680,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1695,     0,   218,     6,  1699,     0,     0,   699,
       0,   219,   220,   221,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,   257,  1575,  1748,  1749,  1750,   258,   259,
       0,     0,     0,  1755,  1756,  1757,     0,     0,   260,   261,
     262,     0,     0,     0,   263,   264,   265,     0,  1619,     0,
       0,     0,  1772,     0,     0,   266,    25,     0,   267,     0,
       0,     0,     0,  1780,   268,     0,     0,   269,     0,     0,
     270,  1788,   271,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   272,   273,     0,  1797,     0,  1799,     0,
       0,     0,     0,     0,     0,     0,   274,     0,    58,    59,
       0,   275,     0,   276,     0,     0,   277,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
     467,   467,     0,     0,  1854,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,     0,     0,     0,
       0,     0,     0,     0,   467,     0,     0,     0,     0,     0,
       0,     0,     0,  1876,   279,     0,     0,     0,   280,   281,
       0,     0,     0,     0,   282,   283,   284,     0,   285,   286,
     287,     0,     0,     0,   122,     0,     0,     0,     0,     0,
    1637,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,   522,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,   373,  1770,     0,     0,     0,   595,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1828,     0,     0,
       0,     0,  1914,  1529,     0,     0,     0,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
    1854,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
    1956,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,   467,     0,     0,   467,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   399,     0,     0,   803,  1982,
     803,     0,     0,     0,     0,     0,     0,  1832,   441,     0,
       0,     0,  1991,     0,     0,   467,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,   468,     0,   621,     0,
     478,     0,     0,     0,     0,   484,     0,     0,     0,     0,
     467,     0,   489,     0,     0,   491,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1854,     0,     0,     0,     0,
       0,     0,   500,   501,   502,     0,   504,   505,   506,     0,
     508,   509,   510,   511,   512,   513,   514,     0,   516,   517,
     518,   519,     0,     0,     0,     0,   523,   523,     0,     0,
       0,     0,  2055,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
    2101,     0,   621,     0,     0,   589,   591,   593,   594,   523,
       0,     0,     0,     0,     0,  2110,     0,     0,     0,     0,
       0,     0,     0,     0,   628,   523,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1854,   646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   656,   657,     0,  2140,     0,     0,   657,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,   679,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
     698,   523,   621,     0,     0,     0,     0,     0,     0,  1854,
       0,   708,     0,   710,   711,     0,   713,     0,     0,     0,
     716,   717,   718,     0,     0,   720,     0,     0,     0,   727,
       0,     0,     0,     0,     0,     0,     0,     0,  2186,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   803,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,   523,   762,     0,     0,   621,     0,   783,     0,   784,
       0,     0,     0,     0,     0,  1812,     0,     0,   770,   771,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   804,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   803,
       0,     0,     0,     0,     0,   835,     0,     0,     0,     0,
     840,     0,     0,     0,   844,     0,     0,     0,     0,     0,
       0,   803,     0,     0,     0,     0,     0,     0,   858,   591,
       0,     0,  1854,     0,   863,     0,     0,     0,   867,   868,
     869,   870,   871,   872,   873,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   894,     0,   899,   900,     0,
     902,   467,     0,     0,     0,     0,     0,     0,     0,     0,
     912,     0,  1854,   916,   917,     0,     0,     0,     0,     0,
     467,   467,   894,     0,     0,     0,     0,   523,     0,     0,
       0,     0,     0,   467,     0,     0,     0,     0,     0,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   950,   952,   953,   954,   955,   956,     0,
     958,   959,     0,     0,     0,     0,     0,     0,   966,   967,
     968,     0,     0,     0,     0,     0,   974,   975,   976,   977,
       0,   523,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,   720,   997,     0,     0,     0,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1009,  1010,     0,     0,     0,     0,     0,
    1017,  1018,     0,  1020,     0,     0,  1022,     0,     0,     0,
     523,   523,   523,  1027,     0,     0,     0,  1031,   523,  1033,
    1034,  1035,     0,     0,  1036,     0,  1038,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1048,     0,     0,  1049,
       0,   958,   959,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1062,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
       0,     0,     0,     0,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,  1092,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,   523,  1838,  1108,     0,   621,     0,  1029,  1111,
    1112,     0,     0,     0,     0,     0,   990,     0,     0,     0,
       0,     0,     0,     0,   523,     0,  1128,  1129,     0,     0,
     523,     0,   523,  1135,     0,     0,     0,  1128,     0,  1142,
       0,  1143,     0,     0,   173,   403,     0,  1148,     0,     0,
       0,  1151,     0,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,  1172,   621,   950,     0,  1175,     0,
       0,  1874,     0,     0,     0,  1875,     0,     0,     0,     0,
     404,   405,   406,   407,   408,   409,   410,   411,   412,     0,
       0,     0,     0,   413,   414,   415,   416,  1951,     0,     0,
       0,   417,   418,   419,   420,   523,     0,     0,     0,     0,
     421,     0,   422,     0,     0,   523,  1222,  1223,  1224,     0,
       0,     0,     0,     0,     0,   523,   423,  1952,  1231,   424,
       0,     0,     0,   179,     0,     0,   180,     0,     0,   181,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
       0,     0,   453,     0,     0,     0,  1266,     0,     0,     0,
    1272,     0,     0,     0,     0,     0,  1278,     0,     0,   523,
       0,     0,     0,     0,     0,     0,     0,  1288,  1289,     0,
       0,     0,     0,  1292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1318,     0,     0,  1320,     0,     0,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,   425,   426,   427,     0,   621,  1341,
       0,  1343,  1344,     0,     0,     0,   428,     0,     0,     0,
     429,     0,   430,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   459,
     460,     0,     0,     0,  1385,     0,  -590,     0,  1649,     0,
       0,  1391,     0,     0,     0,     0,     0,     0,  1404,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1427,  1428,     0,     0,     0,     0,   523,     0,     0,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,     0,  1458,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,  2046,
       0,   523,   621,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1482,     0,     0,     0,     0,   525,   526,     0,     0,     0,
    1483,  1484,  1485,  1486,  1487,     0,     0,     0,     0,  1489,
    1490,     0,  1491,     0,     0,     0,     0,     0,     0,     0,
       0,   524,   524,     0,     0,     0,     0,     0,     0,  1503,
    1504,     0,     0,     0,     0,     0,     0,  1507,  1508,     0,
       0,     0,     0,     0,     0,     0,  1512,  1513,     0,     0,
       0,     0,  1519,  1520,     0,     0,     0,     0,   523,   523,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,     0,   184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1552,   629,   630,     0,     0,     0,     0,
       0,   592,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1586,     0,     0,     0,     0,     0,   678,     0,     0,
       0,     0,     0,  1519,  1520,     0,     0,     0,   523,     0,
       0,     0,     0,     0,     0,     0,  1602,     0,     0,     0,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1618,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,  1624,     0,     0,  1629,     0,     0,   466,     0,     0,
       0,     0,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,     0,  1651,   621,     0,  1654,   523,  1657,   523,
     761,     0,     0,     0,     0,     0,     0,  1666,     0,     0,
    1669,     0,  1666,     0,  1673,  1675,     0,     0,  1683,  1684,
    1685,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   559,   560,   561,
     562,   563,   564,     0,   566,   567,     0,     0,     0,     0,
       0,     0,     0,     0,   573,   574,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   584,   585,
    1754,     0,     0,     0,   592,     0,     0,     0,     0,     0,
       0,  1763,  1764,  1765,     0,     0,     0,     0,     0,     0,
    1771,     0,  1773,     0,     0,     0,     0,     0,     0,  1776,
     885,     0,     0,     0,     0,     0,     0,     0,     0,   895,
     896,     0,     0,   523,     0,     0,   928,     0,     0,  1794,
    1795,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1802,  1803,  1804,     0,     0,     0,     0,   924,     0,     0,
       0,  1815,   524,     0,     0,     0,     0,     0,     0,     0,
       0,  1825,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   951,     0,
     980,   981,  1842,     0,     0,     0,     0,     0,     0,     0,
    1851,  1852,     0,     0,     0,   719,     0,     0,     0,     0,
       0,     0,   728,   729,   730,     0,   524,   524,   734,   735,
     736,   737,   738,   739,   740,     0,   741,     0,     0,     0,
       0,   742,   743,     0,     0,   746,  1881,     0,     0,  1024,
    1025,  1026,     0,     0,     0,     0,     0,  1032,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,   524,   524,     0,     0,
       0,     0,     0,   524,     0,     0,     0,     0,     0,  1898,
    1899,  1900,     0,     0,     0,     0,     0,     0,     0,     0,
    1901,     0,     0,     0,     0,  1904,  1905,  1076,     0,     0,
       0,     0,  2075,     0,     0,     0,     0,     0,  1913,     0,
       0,     0,     0,     0,     0,   523,   523,  1921,     0,  1922,
       0,     0,     0,   524,     0,  1930,  1931,     0,     0,     0,
       0,  1104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   523,     0,     0,     0,     0,   523,
    1950,     0,     0,  1126,     0,     0,     0,   524,     0,  1132,
       0,  1134,  1904,  1905,     0,     0,  1964,     0,     0,  1968,
       0,     0,     0,  1970,     0,     0,     0,     0,     0,   524,
       0,     0,     0,  1979,     0,   524,     0,   524,     0,     0,
       0,     0,     0,  1986,     0,     0,     0,  2090,     0,     0,
       0,     0,     0,     0,     0,     0,   932,  1997,     0,     0,
       0,     0,  2003,  2004,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2009,     0,     0,  2010,
    2009,   951,  2013,  1176,  2124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1211,     0,     0,     0,     0,     0,
     786,     0,     0,     0,  1221,     0,     0,     0,     0,     0,
       0,     0,  2125,     0,  1230,   523,   523,     0,     0,     0,
     524,     0,  2040,  2041,     0,     0,     0,     0,     0,     0,
     524,     0,     0,     0,  2049,     0,     0,     0,     0,     0,
     524,     0,     0,  2058,     0,  1251,     0,     0,     0,     0,
       0,     0,   591,     0,     0,     0,     0,  1259,     0,     0,
       0,     0,     0,     0,     0,  2070,  2071,     0,     0,   720,
     523,   524,     0,     0,     0,     0,     0,     0,  1281,     0,
       0,     0,     0,   524,     0,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,   524,  2098,  2099,   621,   913,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2112,     0,     0,     0,
       0,   523,   523,  2117,     0,     0,     0,     0,  2120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,     0,     0,     0,     0,
       0,   962,     0,     0,     0,     0,     0,   523,     0,     0,
       0,     0,     0,     0,     0,     0,  2151,     0,     0,   523,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  2163,     0,     0,     0,     0,     0,
    2168,     0,     0,  2169,     0,     0,  1434,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,  2205,   524,     0,  2193,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
    1480,  2211,  2212,     0,  2251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1241,  2218,  2219,     0,   523,
       0,     0,     0,     0,     0,     0,   524,     0,     0,  2020,
     602,     0,  2228,     0,     0,     0,     0,   523,   523,   523,
     523,   523,     0,     0,     0,     0,     0,  2003,  1258,     0,
       0,  2244,     0,     0,   602,     0,     0,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,  2264,   621,
       0,     0,     0,  2267,  2268,  1926,     0,  1524,  1525,  1927,
       0,     0,     0,     0,     0,     0,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,   524,     0,     0,     0,     0,     0,
       0,     0,     0,  2295,  2296,     0,     0,     0,     0,     0,
       0,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1191,  1192,     0,  1194,  1195,  1196,  1197,     0,  1199,
    1200,  1201,  1202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1214,     0,  1216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1600,  1226,     0,
       0,     0,     0,     0,     0,     0,     0,  1234,  1235,     0,
       0,     0,     0,     0,     0,     0,  1246,     0,     0,     0,
       0,     0,     0,   524,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,     0,  1449,     0,     0,     0,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,  1656,     0,  1658,   621,
       0,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   859,   617,   618,   619,   620,     0,
       0,     0,   524,   621,   524,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1350,  1352,  1353,
       0,     0,     0,  1357,  1358,     0,     0,  1361,  1362,  1363,
    1364,     0,  1366,  1511,     0,     0,     0,  1372,     0,     0,
       0,     0,   218,   173,     0,   396,     0,     0,     0,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   397,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,     0,     0,     0,     0,   602,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,   257,  1791,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,     0,  1457,     0,  1459,     0,     0,
       0,     0,   263,   264,   265,     0,     0,     0,   524,     0,
       0,     0,     0,   266,    25,     0,   267,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,   218,   173,   403,     0,   621,
       0,     0,   219,   220,   221,   856,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   397,   241,   242,   243,   244,
     245,   246,   247,   248,     0,  1639,  1640,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   254,   255,   256,   257,   413,   414,   415,   416,   258,
       0,     0,  1521,   417,   418,   419,   420,     0,     0,     0,
       0,  1882,   421,     0,   422,   263,   264,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   266,    25,   423,   267,
       0,   424,   279,     0,     0,     0,   280,     0,     0,     0,
       0,     0,   282,   283,   284,     0,   285,   286,   287,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1919,  1920,     0,     0,     0,   288,
     398,     0,     0,     0,  1733,     0,   290,     0,     0,     0,
       0,   373,     0,  1740,     0,     0,     0,     0,   293,     0,
     524,   524,     0,     0,     0,     0,     0,     0,  1949,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   859,   617,   618,   619,   620,     0,     0,   524,
       0,   621,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,   425,   426,   427,   280,
    1638,     0,     0,     0,     0,   282,   283,   284,   428,   285,
     286,   287,   429,     0,   430,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   288,   398,     0,     0,     0,     0,     0,   290,
       7,     8,     0,  1677,   373,     0,     0,     0,  1674,     0,
       0,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2036,  2037,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1715,  1716,  1717,  1718,
    1719,  1720,  1721,     0,     0,     0,     0,  1726,  1727,     0,
     524,   524,     0,     0,  1729,     0,  1879,     0,  1731,     0,
       0,     0,  1735,     0,     0,  1737,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1744,     0,     0,  2074,
       0,     0,     0,     0,     0,     0,     0,   592,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,   524,    43,    44,    45,    46,
       0,     0,     0,    48,     0,     0,  1045,     0,     0,     0,
       0,     0,   797,    57,     0,     0,    60,   798,     0,   799,
     800,     0,   801,     0,     0,     0,     0,     0,     0,     0,
    2115,  2116,     0,     0,     0,  1249,     0,     0,     0,     0,
      81,     0,     0,     0,  1810,     0,  1813,     0,     0,     0,
    1820,  2134,  1822,     0,     0,     0,   524,   524,     0,     0,
       0,     0,     0,     0,     0,     0,  2144,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,   524,  2154,     0,
       0,     0,     0,  1845,     0,     0,     0,     0,     0,     0,
       0,     0,   524,     0,     0,     0,     0,     0,     0,   218,
     173,   403,     0,     0,   524,     0,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   397,
     241,   242,   243,   244,   245,   246,   247,   248,  1250,     0,
       0,     0,     0,     0,   823,     0,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   254,   255,   256,   257,   413,
     414,   415,   416,   258,     0,     0,     0,   417,   418,   419,
     420,     0,     0,     0,     0,     0,   421,     0,   422,   263,
     264,   265,     0,     0,  1906,     0,     0,     0,  2220,     0,
     266,    25,   423,   267,     0,   424,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2232,  2233,  2234,  2235,
    2237,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,   524,   524,   524,   524,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,  2276,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
    1994,   524,     0,  1995,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
     425,   426,   427,   280,     0,     0,     0,     0,     0,   282,
     283,   284,   428,   285,   286,   287,   429,     0,   430,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2029,  2030,     0,  2032,   288,  1962,     0,     0,
       0,     0,  1594,   290,     0,     0,     0,     0,   373,     0,
       0,     0,  1963,     0,     0,   293,     0,     0,     0,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,  2079,  2080,   621,   218,     6,   403,     0,     0,
    1121,     0,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,  2111,  1678,   405,   406,   407,   408,   409,   410,   411,
     412,   254,   255,   256,   257,   413,   414,   415,   416,   258,
     259,     0,     0,   417,   418,   419,   420,     0,     0,   260,
     261,   262,   421,     0,   422,   263,   264,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   266,    25,   423,   267,
       0,   424,     0,     0,     0,   268,     0,     0,   269,     0,
       0,   270,     0,   271,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   272,   273,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   274,     0,    58,
      59,     0,   275,     0,   276,     0,     0,   277,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,   278,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,   425,   426,   427,   280,
     281,     0,     0,     0,     0,   282,   283,   284,   428,   285,
     286,   287,   429,     0,   430,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   288,   289,     0,     0,     0,     0,     0,   290,
       0,     0,     0,     0,   373,     0,     0,     0,  1679,     0,
       0,   293,     0,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,   218,     6,   403,     0,   621,     0,     0,   219,   220,
     221,  1179,  2285,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   254,   255,   256,
     257,   413,   414,   415,   416,   258,   259,     0,     0,   417,
     418,   419,   420,     0,     0,   260,   261,   262,   421,     0,
     422,   263,   264,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   266,    25,   423,   267,     0,   424,     0,     0,
       0,   268,     0,     0,   269,     0,     0,   270,     0,   271,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     272,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   274,     0,    58,    59,     0,   275,     0,
     276,     0,     0,   277,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    84,     0,     0,     0,    88,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,   278,     0,     0,     0,  1957,     0,     0,
       0,  1958,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   279,   425,   426,   427,   280,   281,     0,     0,     0,
       0,   282,   283,   284,   428,   285,   286,   287,   429,     0,
     430,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   289,
       0,     0,     0,     0,     0,   290,     0,     0,     0,     0,
     373,   218,   173,   403,   292,   452,     0,   293,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   397,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   254,   255,   256,
     257,   413,   414,   415,   416,   258,     0,     0,     0,   417,
     418,   419,   420,     0,     0,     0,     0,     0,   421,     0,
     422,   263,   264,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   266,    25,   423,   267,     0,   424,     0,     0,
       0,   179,     0,     0,   180,     0,     0,   181,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,   173,   403,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     453,     0,     0,     0,     0,     0,     0,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   816,
       0,     0,     0,   413,   414,   415,   416,     0,     0,     0,
       0,   417,   418,   419,   420,     0,     0,     0,     0,     0,
     421,     0,   422,     0,   454,     0,     0,     0,     0,     0,
       0,   279,   425,   426,   427,   280,   423,     0,     0,   424,
       0,   282,   283,   284,   428,   285,   286,   287,   429,     0,
     430,   122,     0,   455,   456,   457,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   398,
       0,     0,     0,     0,     0,   290,     0,   459,   460,     0,
     461,     0,   462,   218,     6,   372,   463,   293,     0,     0,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,   425,   426,   427,   260,   261,   262,
       0,     0,     0,   263,   264,   265,   428,     0,     0,     0,
     429,     0,   430,   122,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,  2136,
       0,     0,     0,  2137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,  1779,   374,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,   822,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,   292,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,   824,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     663,  1945,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   665,   218,     6,     0,   336,   595,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,   990,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   291,   218,     6,     0,   292,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,   991,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,   292,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1042,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   522,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,   590,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   522,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,     0,   595,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   633,   218,     6,     0,   292,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   642,   218,     6,     0,   292,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   522,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,   949,     0,  1433,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   522,     0,     0,     0,     0,     0,   290,   218,     6,
       0,     0,   373,  1655,     0,   219,   220,   221,     0,   293,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,   257,     0,     0,
       0,     0,   258,   259,     0,     0,     0,     0,     0,     0,
       0,     0,   260,   261,   262,     0,     0,     0,   263,   264,
     265,     0,     0,     0,     0,     0,     0,     0,     0,   266,
      25,     0,   267,     0,     0,     0,     0,     0,   268,     0,
       0,   269,     0,     0,   270,     0,   271,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   272,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,    58,    59,     0,   275,     0,   276,     0,     0,
     277,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,     0,    88,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
     278,     0,     0,     0,     0,     0,     0,     0,  1206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
       0,     0,   280,   281,     0,     0,     0,     0,   282,   283,
     284,     0,   285,   286,   287,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   288,   522,     0,     0,     0,
       0,     0,   290,   218,     6,     0,     0,   373,     0,     0,
     219,   220,   221,     0,   293,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   289,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,  1787,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     663,  1945,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   665,   218,     6,     0,   336,     0,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   522,     0,     0,     0,     0,     0,   290,     0,     0,
       0,     0,   373,   218,     6,     0,     0,  2073,     0,   293,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,   260,   261,   262,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,     0,   267,     0,     0,
       0,     0,     0,   268,     0,     0,   269,     0,     0,   270,
       0,   271,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   272,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,    58,    59,     0,
     275,     0,   276,     0,     0,   277,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,   278,     0,     0,     0,     0,
       0,     0,     0,  1215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,     0,     0,     0,   280,   281,     0,
       0,     0,     0,   282,   283,   284,     0,   285,   286,   287,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   522,     0,     0,     0,     0,     0,   290,   218,   173,
     403,     0,   373,     0,     0,   219,   220,   221,     0,   293,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   397,   241,
     242,   243,   244,   245,   246,   247,   248,     0,     0,     0,
       0,     0,     0,     0,     0,  1678,   405,   406,   407,   408,
     409,   410,   411,   412,   254,   255,   256,   257,   413,   414,
     415,   416,   258,     0,     0,     0,   417,   418,   419,   420,
       0,     0,     0,     0,     0,   421,     0,   422,   263,   264,
     265,     0,     0,     0,     0,     0,     0,     0,     0,   266,
      25,   423,   267,     0,   424,   218,   173,   403,     0,     0,
       0,     0,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   397,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     0,     0,     0,     0,
       0,     0,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   254,   255,   256,   257,   413,   414,   415,   416,   258,
       0,     0,     0,   417,   418,   419,   420,     0,     0,     0,
       0,     0,   421,     0,   422,   263,   264,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   266,    25,   423,   267,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   425,
     426,   427,   280,     0,     0,     0,     0,     0,   282,   283,
     284,   428,   285,   286,   287,   429,     0,   430,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   288,   398,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,   373,     0,     0,
       0,  1844,     0,     0,   293,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1334,     0,     0,
       0,     0,     0,     0,     0,   279,   425,   426,   427,   280,
       0,     0,     0,     0,     0,   282,   283,   284,   428,   285,
     286,   287,   429,     0,   430,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   288,   398,     0,     0,     0,     0,     0,   290,
     218,   173,     0,     0,   373,     0,     0,   219,   220,   221,
       0,   293,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     397,   241,   242,   243,   244,   245,   246,   247,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,   257,
       0,     0,     0,     0,   258,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   264,   265,     0,     0,     0,     0,     0,   218,   173,
       0,   266,    25,     0,   267,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   397,   241,
     242,   243,   244,   245,   246,   247,   248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,   257,     0,     0,
       0,     0,   258,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   263,   264,
     265,    43,    44,    45,    46,     0,     0,     0,    48,   266,
      25,     0,   267,     0,     0,     0,     0,   797,    57,     0,
       0,    60,   798,     0,   799,   800,     0,   801,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,     0,     0,     0,   280,    81,     0,     0,     0,     0,
     282,   283,   284,     0,   285,   286,   287,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,     0,   288,   398,     0,
       0,     0,     0,     0,   290,     0,     0,     0,     0,   373,
       0,     0,     0,   645,     0,     0,   293,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,   279,  1360,
       0,     0,   280,     0,     0,     0,     0,     0,   282,   283,
     284,     0,   285,   286,   287,     0,     0,     0,   122,   998,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   663,   664,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,   665,   218,   173,
       0,   336,     0,   915,   293,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   397,   241,
     242,   243,   244,   245,   246,   247,   248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,   257,     0,     0,
       0,     0,   258,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   264,
     265,     0,     0,     0,     0,     0,   218,   173,     0,   266,
      25,     0,   267,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   397,   241,   242,   243,
     244,   245,   246,   247,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,   257,     0,     0,     0,     0,
     258,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   263,   264,   265,    43,
      44,    45,    46,     0,     0,     0,    48,   266,    25,     0,
     267,     0,     0,     0,     0,   797,    57,     0,     0,    60,
     798,     0,   799,   800,     0,   801,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
       0,     0,   280,    81,     0,     0,     0,     0,   282,   283,
     284,     0,   285,   286,   287,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,     0,   288,   398,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,   373,     0,     0,
       0,     0,     0,     0,   293,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,     0,     0,   279,  1443,     0,     0,
     280,     0,     0,     0,     0,     0,   282,   283,   284,     0,
     285,   286,   287,     0,     0,     0,   122,  1023,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   288,   398,     0,     0,     0,     0,     0,
     290,   218,   173,     0,  1384,   373,  1140,     0,   219,   220,
     221,     0,   293,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   397,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
     257,     0,     0,     0,     0,   258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   264,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   266,    25,     0,   267,   218,   173,     0,  1551,
       0,     0,     0,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   397,   241,   242,   243,
     244,   245,   246,   247,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,   257,     0,     0,     0,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,   264,   265,     0,
       0,     0,     0,     0,     0,     0,     0,   266,    25,     0,
     267,     0,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,   279,     0,     0,   621,   280,     0,     0,     0,     0,
       0,   282,   283,   284,  1447,   285,   286,   287,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   398,
       0,     0,     0,     0,     0,   290,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,   293,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1545,     0,     0,     0,     0,     0,   279,     0,     0,     0,
     280,     0,     0,     0,     0,     0,   282,   283,   284,     0,
     285,   286,   287,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   288,   398,     0,     0,     0,     0,     0,
     290,   218,   173,     0,  1617,   373,     0,     0,   219,   220,
     221,     0,   293,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   397,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
     257,     0,     0,     0,     0,   258,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   264,   265,     0,     0,     0,     0,     0,   218,
     173,     0,   266,    25,     0,   267,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   397,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,   257,     0,
       0,     0,     0,   258,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   263,
     264,   265,    43,    44,    45,    46,     0,     0,     0,    48,
     266,    25,     0,   267,     0,     0,     0,     0,   797,    57,
       0,     0,    60,   798,     0,   799,   800,     0,   801,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   279,     0,     0,     0,   280,    81,     0,     0,     0,
       0,   282,   283,   284,     0,   285,   286,   287,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,     0,   288,   398,
       0,     0,     0,     0,     0,   290,     0,     0,     0,     0,
     373,     0,     0,     0,     0,     0,     0,   293,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,   279,
    1546,     0,     0,   280,     0,     0,     0,     0,     0,   282,
     283,   284,     0,   285,   286,   287,     0,     0,     0,   122,
    1078,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,   398,     0,     0,
       0,     0,     0,   290,   218,   173,     0,     0,   373,  1671,
       0,   219,   220,   221,     0,   293,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   397,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,   257,     0,     0,     0,     0,   258,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,   264,   265,     0,     0,     0,
       0,     0,   218,   173,     0,   266,    25,     0,   267,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   397,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,   257,     0,     0,     0,     0,   258,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   263,   264,   265,    43,    44,    45,    46,     0,
       0,     0,    48,   266,    25,     0,   267,     0,     0,     0,
       0,   797,    57,     0,     0,    60,   798,     0,   799,   800,
       0,   801,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,     0,     0,     0,   280,    81,
       0,     0,     0,     0,   282,   283,   284,     0,   285,   286,
     287,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
       0,   288,   398,     0,     0,     0,     0,     0,   290,     0,
       0,     0,     0,   373,  2011,     0,     0,     0,     0,     0,
     293,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,   279,  1593,     0,     0,   280,     0,     0,     0,
       0,     0,   282,   283,   284,     0,   285,   286,   287,     0,
       0,     0,   122,  1080,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   288,
     398,     0,     0,     0,     0,     0,   290,     0,     0,     0,
       0,   373,   218,   173,     0,  2072,     0,     0,   293,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   397,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   403,     0,     0,     0,     0,   254,   255,
     256,   257,     0,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   264,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   266,    25,     0,   267,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,     0,     0,     0,
       0,   413,   414,   415,   416,     0,     0,     0,     0,   417,
     418,   419,   420,     0,     0,   434,   403,     0,   421,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,   424,     0,     0,
       0,   179,     0,     0,   180,     0,     0,   181,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,   404,   405,   406,   407,   408,   409,   410,   411,   412,
       0,     0,     0,     0,   413,   414,   415,   416,     0,     0,
     453,     0,   417,   418,   419,   420,     0,     0,     0,     0,
       0,   421,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,   279,     0,     0,     0,   280,   423,     0,     0,
     424,     0,   282,   283,   284,     0,   285,   286,   287,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,   173,
     403,     0,     0,     0,     0,     0,     0,     0,     0,   288,
     398,     0,     0,     0,     0,     0,   290,     0,     0,     0,
       0,   373,   425,   426,   427,     0,     0,     0,   293,     0,
       0,     0,     0,     0,   428,     0,     0,     0,   429,     0,
     430,   122,     0,     0,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,     7,     8,     0,     0,   413,   414,
     415,   416,     0,     0,     0,     0,   417,   418,   419,   420,
       0,   783,     0,   784,  1844,   421,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,   424,   425,   426,   427,   179,     0,
       0,   180,     0,     0,   181,     0,   182,   428,     0,     0,
       0,   429,     0,   430,     0,     0,     0,    46,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,   453,     0,     0,
     621,     0,   837,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     7,     8,     0,
      43,    44,    45,    46,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   797,    57,     0,     0,
      60,   798,     0,   799,   800,     0,   801,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,   425,
     426,   427,     0,     0,     0,     0,     0,     0,     0,     7,
       8,   428,     0,     0,     0,   429,     0,   430,   122,     0,
       0,    98,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,  1844,     0,    43,    44,    45,    46,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   797,
      57,     0,     0,    60,   798,     0,   799,   800,     0,   801,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,  1283,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,     0,    48,     0,    98,    99,   100,     0,     0,     0,
       0,   797,    57,     0,     0,    60,   798,     0,   799,   800,
       0,   801,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    98,    99,   100,    43,
      44,    45,    46,     0,     0,     0,    48,     0,     0,     0,
       0,  1285,     0,     0,     0,   797,    57,     0,     0,    60,
     798,     0,   799,   800,     0,   801,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,     0,    48,     0,     0,
      98,    99,   100,  1286,     0,     0,   797,    57,     0,     0,
      60,   798,     0,   799,   800,     0,   801,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    98,    99,   100,    43,    44,    45,    46,     0,     0,
       0,    48,     0,     0,     0,     0,     0,  1305,     0,     0,
     797,    57,     0,     0,    60,   798,     0,   799,   800,     0,
     801,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,     0,    48,     0,     0,    98,    99,   100,  1324,     0,
       0,   797,    57,     0,     0,    60,   798,     0,   799,   800,
       0,   801,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    98,    99,   100,    43,
      44,    45,    46,     0,     0,     0,    48,     0,     0,     0,
       0,     0,  1342,     0,     0,   797,    57,     0,     0,    60,
     798,     0,   799,   800,     0,   801,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,     0,    48,     0,     0,
      98,    99,   100,  1379,     0,     0,   797,    57,     0,     0,
      60,   798,     0,   799,   800,     0,   801,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    98,    99,   100,    43,    44,    45,    46,     0,     0,
       0,    48,     0,     0,     0,     0,     0,  1543,     0,     0,
     797,    57,     0,     0,    60,   798,     0,   799,   800,     0,
     801,     0,     0,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,    81,    -4,
      -4,     0,     0,     0,     0,     0,     0,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,    98,    99,   100,  2196,   621,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     0,  1722,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
       0,    -4,    -4,     0,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,  2253,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
      -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       6,     0,     0,     0,     0,    -4,    -4,    -4,    -4,     7,
       8,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
      -4,     0,     0,     0,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     9,    10,    11,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1723,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       0,    15,    16,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
       0,    25,     0,     0,     0,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,    42,    43,    44,    45,    46,     0,
      47,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,    94,    95,     0,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   173,
     403,   101,     0,   102,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,   122,
     123,     0,     0,     0,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   412,     0,     0,     0,     0,   413,   414,
     415,   416,     0,   403,     0,     0,   417,   418,   419,   420,
       7,     8,     0,     0,     0,   421,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,   424,     0,     0,     0,   179,     0,
       0,   180,     0,     0,   181,     0,   182,     0,   404,   405,
     406,   407,   408,   409,   410,   411,   412,    46,     0,     0,
       0,   413,   414,   415,   416,     0,     0,     0,     0,   417,
     418,   419,   420,     0,     0,     0,     0,   453,   421,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,   424,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,   797,    57,     0,     0,    60,   798,     0,   799,
     800,     0,   801,     7,     8,     0,  1086,     0,     0,   425,
     426,   427,     0,     0,     0,     0,     0,     0,     0,     0,
      81,   428,     0,     0,  1087,   429,     0,   430,   122,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,    98,    99,   100,
       0,   621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1724,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   425,   426,   427,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,     0,     0,     0,   429,     0,
     430,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   797,    57,     0,     0,    60,
     798,     0,   799,   800,     0,   801,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
      98,    99,   100,     0,     0,     0,  1872,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1998,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1999,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2031,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2106,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2164,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,     0,     0,   621,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2165,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2180,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2214,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2241,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2246,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2247,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,  1228,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,  1229,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,  1275,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,  1308,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,  1322,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,  1329,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,  1390,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,  1410,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,     0,     0,   621,     0,     0,     0,     0,     0,
    1446,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,  1496,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,  1497,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,  1498,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,  1502,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,  1547,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,  1623,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,  1924,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,  1935,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,  1978,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,     0,     0,   621,     0,     0,     0,     0,     0,
    2052,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,  2068,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,  2083,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,  2107,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,  2142,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,  2152,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
       0,     0,     0,     0,  2153,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,     0,  2178,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
       0,     0,  2227,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,  2266,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,     0,     0,   621,     0,     0,     0,     0,     0,
    2284,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,     0,     0,  2302,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,  2303,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,     0,     0,     0,   759,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,     0,   982,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,     0,  2045,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,   783,     0,   784,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,  1052,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,  1097,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
    1254,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,  1323,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,  1325,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,     0,
       0,  1332,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   722,   617,   618,   619,   620,
       0,     0,     0,     0,   621,     0,     0,     0,  1333,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   722,   617,   618,   619,   620,     0,     0,     0,
       0,   621,     0,     0,     0,  1425,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   722,
     617,   618,   619,   620,     0,     0,     0,     0,   621,     0,
       0,     0,  1439,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   722,   617,   618,   619,
     620,     0,     0,     0,     0,   621,     0,     0,     0,  1652,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,     0,     0,  1743,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     722,   617,   618,   619,   620,     0,     0,     0,     0,   621,
       0,     0,     0,  1796,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   722,   617,   618,
     619,   620,     0,     0,     0,     0,   621,     0,     0,     0,
    1990,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   722,   617,   618,   619,   620,     0,
       0,     0,     0,   621,     0,     0,     0,  2035,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   722,   617,   618,   619,   620,     0,     0,     0,     0,
     621,     0,     0,     0,  2053,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   838,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   839,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   841,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   842,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   843,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   845,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   846,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   847,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   848,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   849,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   850,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   851,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   853,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   854,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   855,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,   929,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,   963,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1012,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1029,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1037,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1039,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1040,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1046,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1047,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1085,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1096,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1157,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1161,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1173,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1253,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1263,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1264,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1265,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1274,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1276,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1277,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1307,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1309,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1310,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1311,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1312,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1313,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1314,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1315,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1321,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1335,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1337,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1378,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1424,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1438,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1653,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1689,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1730,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1742,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1859,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1861,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1864,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1871,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1925,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  1934,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  1961,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  2034,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  2104,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  2105,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621,     0,  2240,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   722,   617,   618,   619,   620,     0,     0,
       0,     0,   621,     0,  2281,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   722,   617,
     618,   619,   620,     0,     0,     0,     0,   621
};

static const yytype_int16 yycheck[] =
{
       3,   163,   167,   329,  1506,  1302,   780,   149,  1306,  1781,
       4,     4,   786,    64,   660,   661,  1827,     3,  1829,     4,
       4,    96,    25,     4,     6,    25,     4,     6,     4,     6,
       5,     4,     4,   146,     5,   109,   112,     6,   114,     5,
       4,     6,  2014,     5,   109,   109,     7,     6,     6,  1816,
      26,   109,     6,    56,     6,     6,     4,     6,     4,   167,
       4,    37,    38,   262,     4,   264,     6,   103,   250,   251,
     135,   135,     9,   149,     4,   106,   250,   251,   109,     9,
       9,   262,    85,   264,     4,   198,   122,   195,    91,   271,
     271,   122,     7,    96,   250,   251,     6,   271,   101,   463,
       9,    14,   178,   211,   212,     4,    26,   103,   184,   112,
     106,    95,  1879,   109,   263,   271,   265,    37,    38,   109,
      70,    71,   271,    73,  1896,     6,   122,    26,     6,   266,
     205,   250,   251,   270,     9,     6,   112,   113,    37,    38,
     215,   262,   262,   264,   146,     9,   149,   268,   267,     7,
     271,   154,   155,   156,     0,   103,   250,   251,     9,   107,
     163,     4,   164,   103,   150,   113,   114,   262,   116,   117,
     250,   251,   265,   175,   176,   177,   341,   271,   271,   181,
     182,   263,   262,   265,   250,   251,   266,     6,   262,   271,
       7,   139,   112,   113,   171,   360,     6,   200,     7,   259,
     260,  2173,   205,     7,   262,   271,   209,   210,   268,   260,
     261,   262,   215,   216,   217,   250,   251,   210,   183,   195,
     196,   262,   206,   263,   183,   250,   251,   278,   268,   250,
     251,   250,   251,  1735,     7,     6,   271,   263,   313,   314,
     315,   250,   251,   262,     7,   271,   271,   266,   233,   233,
     271,   149,   233,   259,   260,   233,   154,   155,   156,   263,
     233,   625,   271,   245,   246,   267,  1563,   271,   262,   233,
    2042,   274,   437,   262,   439,   195,   196,   266,   353,   354,
     355,   446,   266,   262,   269,   266,   289,   266,   266,   292,
     293,   266,   264,   293,   266,   266,   371,   266,   270,   263,
     266,   265,   200,   233,   266,   308,   309,   268,   266,   312,
     313,   314,   315,     6,   266,   266,   262,   266,   262,   217,
     323,   262,  1096,  1097,   327,   262,   329,   264,  2100,   259,
     260,   268,   262,   262,   264,   264,   266,     6,   268,   268,
     250,   251,   185,   186,   187,   188,     6,   262,   351,   264,
     353,   354,   355,   262,   197,   264,   199,   200,   201,   202,
     203,   266,   726,     7,   207,   208,   262,   210,   371,   250,
     251,   374,   250,   251,   245,   246,   452,   235,   236,   237,
     238,   264,   332,   333,   259,   260,     4,   262,   265,   264,
     340,   341,   264,   268,   271,   259,   260,  2208,   262,   262,
     264,   259,   260,   262,   268,   264,   568,   266,   259,   260,
     268,   262,     8,   264,   265,     4,   266,   268,   235,   236,
     237,   238,   250,   251,   267,   262,   235,   236,   237,   238,
     794,   235,   236,   237,   238,   125,   263,    26,   266,   442,
     262,   444,   259,   260,   271,   448,   449,   811,    37,    38,
     259,   260,   109,   250,   251,   259,   260,   821,   250,   251,
     146,   464,   235,   236,   237,   238,     4,   106,   471,   266,
     109,  2243,   235,   236,   237,   238,   106,   263,   164,   109,
     110,   111,     4,   262,   649,   271,   651,   652,    26,   175,
     176,   177,   122,   496,   262,   181,   182,   250,   251,    37,
      38,   250,   251,   668,    26,   580,   250,   251,   250,   251,
     268,   587,   263,   271,   265,    37,    38,   266,   271,   522,
     271,  2293,   687,   112,   113,   250,   251,   271,   262,   271,
    2032,   262,  1178,   151,   152,   153,   154,   250,   251,   157,
     259,   260,   263,   263,   442,   548,   271,   266,   166,   714,
     271,   271,   170,   262,   557,   558,   262,   266,   271,   562,
     190,   564,   565,   566,   567,   568,   262,   931,   730,     6,
     266,   574,   250,   251,   112,   113,   579,   580,   581,   262,
     583,   584,   585,   586,   263,   588,   586,   590,   588,   262,
     112,   113,   271,   271,   759,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   616,   250,   251,   109,   261,   111,   622,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   271,   267,   262,   780,   261,
     271,   644,   645,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   262,   250,   251,   562,   261,   564,   743,   566,   567,
    1316,   267,   250,   251,   660,   661,   146,   262,   250,   251,
     250,   251,   262,   271,   106,   583,   584,   109,     6,   111,
     693,   694,   695,   271,   164,   250,   251,   266,   701,   271,
     122,   271,   250,   251,   266,   175,   176,   177,   658,   659,
     263,   181,   182,   663,   263,   267,   271,   267,   271,   271,
     723,   271,   271,   271,   111,   728,   729,   730,   731,   732,
     733,   734,   735,   736,  1098,   738,   739,   740,   741,   742,
     266,   744,   745,   746,   747,   748,   262,   747,   751,   800,
     146,   103,   267,   263,   106,   265,   271,   109,  1532,   111,
     836,   271,   262,   262,   264,   146,   769,   263,   164,   265,
     122,   259,   260,   267,   262,   271,   264,   271,   266,   175,
     176,   177,   785,   164,   266,   181,   182,   262,   791,   252,
     253,   254,   255,   256,   175,   176,   177,   267,   261,   109,
     181,   182,   255,   256,   807,   808,   106,   266,   261,   109,
     813,   111,   815,   151,   152,   818,   819,   266,   960,   157,
     106,   986,   151,   152,   827,   267,   829,   266,   157,   271,
     268,   729,   270,   731,   732,   733,   734,   735,   736,   262,
     738,   739,   740,   741,     6,     7,   744,   745,   746,   109,
     259,   260,     6,   262,  1628,   264,   859,   263,   861,   265,
     259,   260,   267,   262,  1638,   264,   271,   262,   109,   264,
     267,   267,   106,  1237,   271,  1239,   250,   251,   252,   253,
     254,   255,   256,   109,   106,   267,   267,   261,  1252,   271,
     267,   262,   267,   264,   271,   898,   271,   973,   267,  2197,
     267,     4,   271,   267,   271,   908,   267,   271,   267,  1051,
     271,     4,   271,   267,     4,   918,     6,   271,  1282,   267,
     818,   267,   267,   271,   267,   271,   271,     4,   271,     4,
     933,   829,  2229,   267,   267,   267,   267,   271,   271,   271,
     271,     8,   262,   267,   267,   267,   949,   271,   271,   271,
     262,   262,     6,   267,  1096,  1097,  2254,   271,   961,   267,
     267,   267,   267,   271,   271,   271,   271,   970,   267,   267,
     264,  1113,   271,   271,  2271,   262,   267,     6,   267,   982,
     271,  1345,   271,   267,  1348,  1349,   267,   271,   267,   267,
     271,   264,   271,   271,     3,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   266,  1373,
     267,   267,   261,   267,   271,   271,   267,   271,    27,   267,
     271,   267,   267,   271,  1100,   271,   271,   267,     6,   267,
     267,   271,  1396,   271,   271,   270,   267,   267,   267,   989,
     271,   271,   271,   267,   267,    56,   996,   271,   271,   267,
    1000,   267,   267,   271,    63,   271,   271,   267,   267,  1423,
     267,   271,   271,   263,   271,   265,   266,   263,   266,   265,
     266,     6,   262,  1437,  1400,   270,     9,   262,   262,   262,
    1444,   262,   262,   262,   266,   198,   198,   198,  1091,   266,
     109,   135,   262,   262,   262,   262,  1099,   198,   262,   262,
     266,   262,     4,   262,  1107,     6,   266,   262,   117,   266,
     266,  1253,  1254,   266,   266,   262,   262,  1120,   262,   262,
    1766,  1767,  1125,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   262,
     149,   262,   264,   261,     6,   154,   155,   156,     6,   266,
     266,   266,  1155,  1156,   163,  1158,  1159,  1160,   266,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,     7,
       6,  1174,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     266,   200,  1178,   264,   261,   264,   264,     6,     6,   262,
     267,   262,   266,   198,  1154,   216,   262,   262,   217,   262,
     262,   262,   262,     6,  1217,  1218,  1219,   264,     6,     6,
     266,     6,     8,   262,     8,   266,     7,  1125,     6,   266,
     266,     6,   266,    98,   267,   263,   271,     7,     6,   271,
       6,  1244,   263,   266,   266,   261,   266,    68,   266,   266,
     259,   266,   266,     8,     7,   268,     8,  1260,  1261,  1262,
       7,   262,     6,   274,   263,     7,   266,   276,   277,     6,
     267,     7,     6,     6,   195,   266,   263,   267,   267,   265,
       6,   266,  1424,  1425,   268,     7,     6,   264,   262,     6,
     266,     6,     6,     6,     6,   263,     7,   264,     7,     7,
       7,   312,     7,     7,     7,  1631,     7,     7,     7,     7,
       7,     7,   323,     7,  1317,     7,   327,     7,   266,     6,
    1218,  1219,   263,   265,   271,   271,   271,   267,   271,   263,
    1316,     7,   268,  1336,     7,  1338,  1339,   267,   266,   266,
       4,     6,   268,   267,   267,   146,   266,     7,  1351,     6,
     268,     7,     7,  1356,     7,   268,   263,  1360,   263,   271,
     271,     9,   271,   263,   270,   198,  1369,   265,  1371,     7,
     167,  1374,  1448,   267,  1450,   266,     6,     6,     6,    50,
      50,   268,   262,   266,  1387,   262,   268,   266,   262,   262,
     268,     7,     7,     7,   198,   271,   263,  1400,     7,     7,
       7,     6,  2048,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   263,  1425,   271,     7,   261,     7,  1430,     7,  1432,
       7,     7,   121,   442,     4,   266,   262,   448,   449,     6,
     103,     7,     6,   266,   453,     7,     7,  1450,     7,     7,
       7,  1616,     7,   464,     7,  1620,     8,     6,  1356,     6,
    1463,     6,  1360,   109,  1467,     7,   475,     7,     6,  1833,
       6,  1369,     7,  1371,     7,     4,  1374,  1639,  1640,   269,
     271,   490,   271,   263,     6,   267,  1628,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   266,   266,   266,     6,   261,
       6,   263,     7,   265,     6,  1841,   264,     6,     6,   262,
     266,   262,     6,  1526,  1527,  1528,     6,  1425,   267,     6,
     268,  1534,  1535,  1536,     6,     6,  1612,   265,     6,   271,
       6,   139,     6,     6,     6,     6,     6,     6,     6,     6,
    1553,     6,     6,   562,   565,   564,     6,   566,   567,   568,
       6,  1564,     5,     4,     6,   267,     6,     6,   579,  1572,
     581,   266,   263,  1576,   583,   584,     7,   263,   266,     6,
     262,     7,   266,   266,  1587,   266,  1589,   264,     6,     6,
       6,   266,   266,     6,   266,     6,     6,   266,  1674,  1741,
     266,   194,     6,   271,   266,     7,   267,   266,   266,     6,
       6,   263,  1562,     6,     6,     6,   266,   271,   262,     4,
     271,   268,   271,   266,     7,   267,   262,     6,  1631,     6,
       6,     6,   146,   107,     6,     5,  1639,  1640,     6,   266,
     263,   266,  1645,     6,   266,   271,     6,   146,     6,   146,
     271,     6,     6,     6,     6,     6,     6,   666,   271,   263,
    1663,   271,     6,     6,   266,   271,   266,     6,     6,     6,
       6,  1674,     6,     6,   266,     7,  1679,   150,   266,   266,
     266,   690,  1844,     5,   266,   263,  1762,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,     6,     6,     6,     6,   261,
     266,   263,     7,   267,     6,   193,   267,     6,   266,   728,
     729,   730,   731,   732,   733,   734,   735,   736,     6,   738,
     739,   740,   741,  1809,     7,   744,   745,   746,   263,   267,
    1816,  1817,  1692,   267,   267,   754,     6,     6,   757,   268,
    1753,     6,     6,     6,   763,  1758,  1759,   266,   769,  1835,
       6,  2087,     6,   267,     6,  1663,     6,     6,     6,   263,
       6,   196,     6,   266,     6,   266,   262,   267,  1781,   266,
    1766,  1767,   267,   266,  1787,   266,     6,   263,   267,  1792,
     799,   266,   801,     6,     6,     6,   266,   146,  1801,   266,
       6,     6,     6,     6,     6,     6,     6,   263,  1811,   818,
       6,  1814,     6,     6,   267,   267,     6,   266,   266,     6,
     829,     6,   266,     6,     6,     6,     6,  1830,     6,  1436,
    2210,  1834,  1782,  1783,  1784,  1785,  1786,  1787,  1841,  1687,
    1843,  1844,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     493,  1499,  2015,  1975,   261,  1749,     3,  1462,     3,     3,
    1109,     3,   637,  2044,  1609,     3,  1879,  1834,  1816,  1640,
     818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2057,  1896,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1977,    -1,    -1,    -1,  1908,  1909,    -1,    -1,    -1,
      -1,    -1,    -1,  1811,    -1,    -1,  1814,    -1,    -1,    -1,
      -1,    -1,   933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1945,    -1,  2020,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,
    1963,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,   987,   988,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1001,  2158,    -1,    -1,    -1,    -1,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1021,  2016,    -1,    -1,    -1,    -1,  2021,    -1,
      -1,  2024,  2025,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2198,  1043,    -1,    -1,    -1,    -1,  2042,
      -1,    -1,  2045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2056,    -1,    -1,    -1,  2060,    -1,    -1,
      -1,    -1,  2048,    -1,    -1,    -1,    -1,    -1,    -1,  2072,
      -1,    -1,    -1,  1082,    -1,    -1,    -1,    -1,    -1,    -1,
    1091,    -1,    -1,    -1,  2087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1107,  2100,  2174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2061,  2062,  2063,  2064,  2065,  1125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1155,  1156,    -1,  1158,  1159,  1160,
       6,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2128,  2182,
      -1,    -1,  2132,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2200,  2201,  2202,
    2203,  2204,    -1,    -1,    -1,    -1,  1217,    -1,    -1,  1218,
    1219,    -1,    -1,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,  1244,  2184,   261,    -1,    -1,  2188,    -1,
    2243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1260,
      -1,    -1,    -1,    -1,  2204,    -1,  2259,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,  1284,    -1,  2280,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2293,    -1,    -1,    -1,    -1,    -1,  2299,  2300,    -1,  2249,
    2250,    -1,    -1,    -1,    -1,    -1,  1317,    -1,    -1,  2312,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1336,    -1,  1338,  1339,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1356,    -1,    -1,
      -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1369,    -1,  1371,    -1,    -1,  1374,    -1,    -1,    -1,    -1,
      -1,    -1,  1381,    -1,    -1,    -1,  1387,    -1,    -1,    -1,
      -1,    -1,  2280,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,  2299,  2300,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2312,    -1,  1425,    -1,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,  1450,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1463,    -1,     3,     4,  1467,    -1,    -1,     8,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,     6,  1526,  1527,  1528,    67,    68,
      -1,    -1,    -1,  1534,  1535,  1536,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    83,    84,    85,    -1,     6,    -1,
      -1,    -1,  1553,    -1,    -1,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,  1564,   103,    -1,    -1,   106,    -1,    -1,
     109,  1572,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,    -1,  1587,    -1,  1589,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,
      -1,   140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1639,  1640,    -1,    -1,  1645,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1674,   213,    -1,    -1,    -1,   217,   218,
      -1,    -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,
     229,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,   262,     6,    -1,    -1,    -1,   267,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,  1753,   146,    -1,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
    1781,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
    1801,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1811,    -1,    -1,  1814,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,  1827,  1830,
    1829,    -1,    -1,    -1,    -1,    -1,    -1,     6,   121,    -1,
      -1,    -1,  1843,    -1,    -1,  1844,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,   149,    -1,   261,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
    1879,    -1,   165,    -1,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1896,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   186,   187,    -1,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,    -1,   201,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,
      -1,    -1,  1933,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
    2001,    -1,   261,    -1,    -1,   288,   289,   290,   291,   292,
      -1,    -1,    -1,    -1,    -1,  2016,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   307,   308,   309,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2042,   325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   335,   336,    -1,  2056,    -1,    -1,   341,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,   352,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
     373,   374,   261,    -1,    -1,    -1,    -1,    -1,    -1,  2100,
      -1,   384,    -1,   386,   387,    -1,   389,    -1,    -1,    -1,
     393,   394,   395,    -1,    -1,   398,    -1,    -1,    -1,   402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2141,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   444,   445,    -1,    -1,   261,    -1,   263,    -1,   265,
      -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,   461,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2208,
      -1,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,
     503,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,
      -1,  2230,    -1,    -1,    -1,    -1,    -1,    -1,   521,   522,
      -1,    -1,  2243,    -1,   527,    -1,    -1,    -1,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,    -1,   560,   561,    -1,
     563,  2280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     573,    -1,  2293,   576,   577,    -1,    -1,    -1,    -1,    -1,
    2299,  2300,   585,    -1,    -1,    -1,    -1,   590,    -1,    -1,
      -1,    -1,    -1,  2312,    -1,    -1,    -1,    -1,    -1,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,    -1,
     623,   624,    -1,    -1,    -1,    -1,    -1,    -1,   631,   632,
     633,    -1,    -1,    -1,    -1,    -1,   639,   640,   641,   642,
      -1,   644,   645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     663,   664,   665,    -1,    -1,    -1,   669,   670,   671,   672,
     673,   674,   675,   676,   677,    -1,    -1,    -1,    -1,    -1,
     683,   684,    -1,   686,    -1,    -1,   689,    -1,    -1,    -1,
     693,   694,   695,   696,    -1,    -1,    -1,   700,   701,   702,
     703,   704,    -1,    -1,   707,    -1,   709,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   719,    -1,    -1,   722,
      -1,   724,   725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   737,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   751,    -1,
      -1,    -1,    -1,    -1,    -1,   758,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   766,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   785,     6,   787,    -1,   261,    -1,   263,   792,
     793,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   807,    -1,   809,   810,    -1,    -1,
     813,    -1,   815,   816,    -1,    -1,    -1,   820,    -1,   822,
      -1,   824,    -1,    -1,     4,     5,    -1,   830,    -1,    -1,
      -1,   834,    -1,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,   857,   261,   859,    -1,   861,    -1,
      -1,   267,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,     6,    -1,    -1,
      -1,    71,    72,    73,    74,   898,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,   908,   909,   910,   911,    -1,
      -1,    -1,    -1,    -1,    -1,   918,    96,     6,   921,    99,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   949,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   961,    -1,
      -1,    -1,   142,    -1,    -1,    -1,   969,    -1,    -1,    -1,
     973,    -1,    -1,    -1,    -1,    -1,   979,    -1,    -1,   982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   990,   991,    -1,
      -1,    -1,    -1,   996,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1013,    -1,    -1,  1016,    -1,    -1,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   214,   215,   216,    -1,   261,  1042,
      -1,  1044,  1045,    -1,    -1,    -1,   226,    -1,    -1,    -1,
     230,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1067,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,
     260,    -1,    -1,    -1,  1087,    -1,   266,    -1,   268,    -1,
      -1,  1094,    -1,    -1,    -1,    -1,    -1,    -1,  1101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1114,  1115,    -1,    -1,    -1,    -1,  1120,    -1,    -1,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,  1152,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,     6,
      -1,  1174,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1193,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,
    1203,  1204,  1205,  1206,  1207,    -1,    -1,    -1,    -1,  1212,
    1213,    -1,  1215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,  1232,
    1233,    -1,    -1,    -1,    -1,    -1,    -1,  1240,  1241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1249,  1250,    -1,    -1,
      -1,    -1,  1255,  1256,    -1,    -1,    -1,    -1,  1261,  1262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1296,   308,   309,    -1,    -1,    -1,    -1,
      -1,   289,    -1,    -1,   292,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     308,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1334,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,
      -1,    -1,    -1,  1346,  1347,    -1,    -1,    -1,  1351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1359,    -1,    -1,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1383,    -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,    -1,
      -1,  1394,    -1,    -1,  1397,    -1,    -1,   149,    -1,    -1,
      -1,    -1,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,    -1,  1426,   261,    -1,  1429,  1430,  1431,  1432,
     444,    -1,    -1,    -1,    -1,    -1,    -1,  1440,    -1,    -1,
    1443,    -1,  1445,    -1,  1447,  1448,    -1,    -1,  1451,  1452,
    1453,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   256,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,   267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,   281,
    1533,    -1,    -1,    -1,   522,    -1,    -1,    -1,    -1,    -1,
      -1,  1544,  1545,  1546,    -1,    -1,    -1,    -1,    -1,    -1,
    1553,    -1,  1555,    -1,    -1,    -1,    -1,    -1,    -1,  1562,
     548,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,
     558,    -1,    -1,  1576,    -1,    -1,   590,    -1,    -1,  1582,
    1583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1593,  1594,  1595,    -1,    -1,    -1,    -1,   585,    -1,    -1,
      -1,  1604,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   616,    -1,
     644,   645,  1635,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1643,  1644,    -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,
      -1,    -1,   404,   405,   406,    -1,   644,   645,   410,   411,
     412,   413,   414,   415,   416,    -1,   418,    -1,    -1,    -1,
      -1,   423,   424,    -1,    -1,   427,  1679,    -1,    -1,   693,
     694,   695,    -1,    -1,    -1,    -1,    -1,   701,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   693,   694,   695,    -1,    -1,
      -1,    -1,    -1,   701,    -1,    -1,    -1,    -1,    -1,  1722,
    1723,  1724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1733,    -1,    -1,    -1,    -1,  1738,  1739,   751,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,  1751,    -1,
      -1,    -1,    -1,    -1,    -1,  1758,  1759,  1760,    -1,  1762,
      -1,    -1,    -1,   751,    -1,  1768,  1769,    -1,    -1,    -1,
      -1,   785,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1787,    -1,    -1,    -1,    -1,  1792,
    1793,    -1,    -1,   807,    -1,    -1,    -1,   785,    -1,   813,
      -1,   815,  1805,  1806,    -1,    -1,  1809,    -1,    -1,  1812,
      -1,    -1,    -1,  1816,    -1,    -1,    -1,    -1,    -1,   807,
      -1,    -1,    -1,  1826,    -1,   813,    -1,   815,    -1,    -1,
      -1,    -1,    -1,  1836,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   598,  1850,    -1,    -1,
      -1,    -1,  1855,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1869,    -1,    -1,  1872,
    1873,   859,  1875,   861,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,
     466,    -1,    -1,    -1,   908,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,   918,  1908,  1909,    -1,    -1,    -1,
     898,    -1,  1915,  1916,    -1,    -1,    -1,    -1,    -1,    -1,
     908,    -1,    -1,    -1,  1927,    -1,    -1,    -1,    -1,    -1,
     918,    -1,    -1,  1936,    -1,   949,    -1,    -1,    -1,    -1,
      -1,    -1,  1945,    -1,    -1,    -1,    -1,   961,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1958,  1959,    -1,    -1,  1962,
    1963,   949,    -1,    -1,    -1,    -1,    -1,    -1,   982,    -1,
      -1,    -1,    -1,   961,    -1,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   982,  1998,  1999,   261,   574,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2019,    -1,    -1,    -1,
      -1,  2024,  2025,  2026,    -1,    -1,    -1,    -1,  2031,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   627,    -1,    -1,    -1,    -1,    -1,  2060,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2069,    -1,    -1,  2072,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,  2097,    -1,    -1,    -1,    -1,    -1,
    2103,    -1,    -1,  2106,    -1,    -1,  1120,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,     6,  1120,    -1,  2137,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
    1174,  2164,  2165,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   927,  2179,  2180,    -1,  2182,
      -1,    -1,    -1,    -1,    -1,    -1,  1174,    -1,    -1,     7,
       8,    -1,  2195,    -1,    -1,    -1,    -1,  2200,  2201,  2202,
    2203,  2204,    -1,    -1,    -1,    -1,    -1,  2210,   960,    -1,
      -1,  2214,    -1,    -1,     8,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,  2241,   261,
      -1,    -1,    -1,  2246,  2247,   267,    -1,  1261,  1262,   271,
      -1,    -1,    -1,    -1,    -1,    -1,  2259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1261,  1262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2286,  2287,    -1,    -1,    -1,    -1,    -1,
      -1,   867,   868,   869,   870,   871,   872,   873,   874,   875,
     876,   877,   878,    -1,   880,   881,   882,   883,    -1,   885,
     886,   887,   888,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   901,    -1,   903,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1351,   914,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   923,   924,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   932,    -1,    -1,    -1,
      -1,    -1,    -1,  1351,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,    -1,  1145,    -1,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,  1430,    -1,  1432,   261,
      -1,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,  1430,   261,  1432,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1053,  1054,  1055,
      -1,    -1,    -1,  1059,  1060,    -1,    -1,  1063,  1064,  1065,
    1066,    -1,  1068,  1245,    -1,    -1,    -1,  1073,    -1,    -1,
      -1,    -1,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,  1576,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1151,    -1,  1153,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,  1576,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,     3,     4,     5,    -1,   261,
      -1,    -1,    10,    11,    12,   267,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,  1407,  1408,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,  1258,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,  1679,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      -1,    99,   213,    -1,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,    -1,   227,   228,   229,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1758,  1759,    -1,    -1,    -1,   250,
     251,    -1,    -1,    -1,  1506,    -1,   257,    -1,    -1,    -1,
      -1,   262,    -1,  1515,    -1,    -1,    -1,    -1,   269,    -1,
    1758,  1759,    -1,    -1,    -1,    -1,    -1,    -1,  1792,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,  1787,
      -1,   261,    -1,    -1,  1792,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,   215,   216,   217,
    1406,    -1,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,
      13,    14,    -1,  1449,   262,    -1,    -1,    -1,   266,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1908,  1909,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1482,  1483,  1484,  1485,
    1486,  1487,  1488,    -1,    -1,    -1,    -1,  1493,  1494,    -1,
    1908,  1909,    -1,    -1,  1500,    -1,  1678,    -1,  1504,    -1,
      -1,    -1,  1508,    -1,    -1,  1511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1522,    -1,    -1,  1963,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1945,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,  1963,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,
     143,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2024,  2025,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,  1600,    -1,  1602,    -1,    -1,    -1,
    1606,  2045,  1608,    -1,    -1,    -1,  2024,  2025,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2060,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2045,  2072,    -1,
      -1,    -1,    -1,  1639,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2060,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,  2072,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     8,    -1,
      -1,    -1,    -1,    -1,   267,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    -1,    -1,  1740,    -1,    -1,    -1,  2182,    -1,
      94,    95,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2200,  2201,  2202,  2203,
    2204,    -1,    -1,    -1,  2182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2200,  2201,  2202,  2203,  2204,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,  2259,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
    1846,  2259,    -1,  1849,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1898,  1899,    -1,  1901,   250,   251,    -1,    -1,
      -1,    -1,     8,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,   266,    -1,    -1,   269,    -1,    -1,    -1,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,  1968,  1969,   261,     3,     4,     5,    -1,    -1,
     267,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,  2017,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    77,
      78,    79,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   137,
     138,    -1,   140,    -1,   142,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,   170,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,   266,    -1,
      -1,   269,    -1,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,     3,     4,     5,    -1,   261,    -1,    -1,    10,    11,
      12,   267,  2268,    15,    16,    17,    18,    19,    20,    21,
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
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,   137,   138,    -1,   140,    -1,
     142,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,   170,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,   195,    -1,    -1,    -1,   267,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
     262,     3,     4,     5,   266,     7,    -1,   269,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   271,
      -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    -1,    82,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   214,   215,   216,   217,    96,    -1,    -1,    99,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,
      -1,    -1,    -1,    -1,    -1,   257,    -1,   259,   260,    -1,
     262,    -1,   264,     3,     4,     5,   268,   269,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,   214,   215,   216,    77,    78,    79,
      -1,    -1,    -1,    83,    84,    85,   226,    -1,    -1,    -1,
     230,    -1,   232,   233,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,   267,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,     5,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,   267,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,    -1,   267,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,     8,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,     3,     4,
      -1,    -1,   262,     8,    -1,    10,    11,    12,    -1,   269,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,    -1,   137,   138,    -1,   140,    -1,   142,    -1,    -1,
     145,    -1,    -1,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
     195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,   217,   218,    -1,    -1,    -1,    -1,   223,   224,
     225,    -1,   227,   228,   229,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   251,    -1,    -1,    -1,
      -1,    -1,   257,     3,     4,    -1,    -1,   262,    -1,    -1,
      10,    11,    12,    -1,   269,    15,    16,    17,    18,    19,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,   262,     3,     4,    -1,    -1,   267,    -1,   269,
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
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,   137,   138,    -1,
     140,    -1,   142,    -1,    -1,   145,    -1,    -1,    -1,    -1,
      -1,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,    -1,    -1,    -1,
     170,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,    -1,
      -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,   229,
      -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,    -1,    -1,    -1,    -1,    -1,   257,     3,     4,
       5,    -1,   262,    -1,    -1,    10,    11,    12,    -1,   269,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    -1,    99,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,   266,    -1,    -1,   269,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,    -1,   262,    -1,    -1,    10,    11,    12,
      -1,   269,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    94,    95,    -1,    97,    10,    11,    12,    -1,    -1,
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
     213,    -1,    -1,    -1,   217,   163,    -1,    -1,    -1,    -1,
     223,   224,   225,    -1,   227,   228,   229,    -1,    -1,    -1,
     233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   190,   191,   192,    -1,    -1,   250,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,   266,    -1,    -1,   269,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   271,
      -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,    -1,   227,   228,   229,    -1,    -1,    -1,   233,   267,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,   262,     3,     4,
      -1,   266,    -1,     8,   269,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    94,
      95,    -1,    97,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    83,    84,    85,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    94,    95,    -1,
      97,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,
     140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,
      -1,    -1,   217,   163,    -1,    -1,    -1,    -1,   223,   224,
     225,    -1,   227,   228,   229,    -1,    -1,    -1,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,    -1,    -1,   250,   251,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   213,   271,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,    -1,
     227,   228,   229,    -1,    -1,    -1,   233,   267,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,
     257,     3,     4,    -1,     6,   262,   263,    -1,    10,    11,
      12,    -1,   269,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    -1,    97,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      97,    -1,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   213,    -1,    -1,   261,   217,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   271,   227,   228,   229,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,   269,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     271,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,
     217,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,    -1,
     227,   228,   229,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,
     257,     3,     4,    -1,     6,   262,    -1,    -1,    10,    11,
      12,    -1,   269,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    94,    95,    -1,    97,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    83,
      84,    85,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,   135,   136,
      -1,    -1,   139,   140,    -1,   142,   143,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,   217,   163,    -1,    -1,    -1,
      -1,   223,   224,   225,    -1,   227,   228,   229,    -1,    -1,
      -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,   192,    -1,    -1,   250,   251,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,   269,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
     271,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,    -1,   227,   228,   229,    -1,    -1,    -1,   233,
     267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,   251,    -1,    -1,
      -1,    -1,    -1,   257,     3,     4,    -1,    -1,   262,   263,
      -1,    10,    11,    12,    -1,   269,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    94,    95,    -1,    97,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    83,    84,    85,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,   143,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   163,
      -1,    -1,    -1,    -1,   223,   224,   225,    -1,   227,   228,
     229,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,    -1,
      -1,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,   262,   263,    -1,    -1,    -1,    -1,    -1,
     269,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   271,    -1,    -1,   217,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,    -1,   227,   228,   229,    -1,
      -1,    -1,   233,   267,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
     251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,   262,     3,     4,    -1,   266,    -1,    -1,   269,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    97,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,     4,     5,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,
      -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    -1,    -1,
     142,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,   217,    96,    -1,    -1,
      99,    -1,   223,   224,   225,    -1,   227,   228,   229,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
     251,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,   262,   214,   215,   216,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   230,    -1,
     232,   233,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    13,    14,    -1,    -1,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,   263,    -1,   265,   266,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,   214,   215,   216,   103,    -1,
      -1,   106,    -1,    -1,   109,    -1,   111,   226,    -1,    -1,
      -1,   230,    -1,   232,    -1,    -1,    -1,   122,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   142,    -1,    -1,
     261,    -1,   263,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    13,    14,    -1,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,   226,    -1,    -1,    -1,   230,    -1,   232,   233,    -1,
      -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,   266,    -1,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,    -1,    -1,   139,   140,    -1,   142,   143,    -1,   145,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   267,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,   190,   191,   192,    -1,    -1,    -1,
      -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,   143,
      -1,   145,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   190,   191,   192,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,   267,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,
     140,    -1,   142,   143,    -1,   145,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,
     190,   191,   192,   267,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   190,   191,   192,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,   267,    -1,    -1,
     135,   136,    -1,    -1,   139,   140,    -1,   142,   143,    -1,
     145,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,    -1,   190,   191,   192,   267,    -1,
      -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,   143,
      -1,   145,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   190,   191,   192,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,   267,    -1,    -1,   135,   136,    -1,    -1,   139,
     140,    -1,   142,   143,    -1,   145,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,    -1,    -1,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,
     190,   191,   192,   267,    -1,    -1,   135,   136,    -1,    -1,
     139,   140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   190,   191,   192,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,   267,    -1,    -1,
     135,   136,    -1,    -1,   139,   140,    -1,   142,   143,    -1,
     145,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   190,   191,   192,   267,   261,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,   271,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   267,    -1,   118,   119,   120,   121,   122,    -1,
     124,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,    -1,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
       4,    -1,    -1,    -1,    -1,   219,   220,   221,   222,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,   233,
     234,    -1,    -1,    -1,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    47,    48,    49,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    -1,    -1,   118,   119,   120,   121,   122,    -1,
     124,    -1,   126,    -1,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,   178,   179,   180,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,   189,   190,   191,   192,     4,
       5,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,   233,
     234,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    -1,     5,    -1,    -1,    71,    72,    73,    74,
      13,    14,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,   109,    -1,   111,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   122,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,   142,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,    99,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,    -1,    -1,   139,   140,    -1,   142,
     143,    -1,   145,    13,    14,    -1,   149,    -1,    -1,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   226,    -1,    -1,   167,   230,    -1,   232,   233,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   190,   191,   192,
      -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,   215,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,    -1,    -1,    -1,   230,    -1,
     232,    -1,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    -1,    -1,    -1,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,   139,
     140,    -1,   142,   143,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
     190,   191,   192,    -1,    -1,    -1,   271,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   271,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   271,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   271,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   271,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     271,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   271,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,   267,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,   267,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,   267,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,   267,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,   267,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,   267,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
     267,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,   267,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,   267,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,   267,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,   267,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,   267,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,   267,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
     267,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,   267,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,   267,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,   267,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,   267,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,   267,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,   267,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
     267,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   267,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,   266,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,   266,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,   266,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,   263,    -1,   265,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,   265,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,   265,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
     265,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,   265,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,   265,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,   265,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,   265,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,   265,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,   265,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,   265,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,   265,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,   265,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
     265,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,   265,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,   265,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261,    -1,   263,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,    -1,
      -1,    -1,   261,    -1,   263,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,    -1,    -1,    -1,   261
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   273,   274,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    92,    93,    95,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   118,   119,   120,   121,   122,   124,   126,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   147,   148,   149,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   178,   179,   180,   184,   189,   190,   191,
     192,   195,   197,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   219,   220,   221,
     222,   231,   233,   234,   275,   277,   278,   299,   318,   320,
     324,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     342,   344,   345,   351,   352,   353,   354,   360,   385,   386,
     266,   270,    14,   109,   262,   262,   262,     6,   266,     6,
       6,     6,     6,   262,     6,   266,     6,   266,   266,     6,
       6,   264,   264,     4,   362,   386,   262,   264,   296,   103,
     106,   109,   111,   320,   296,   262,   262,   262,     4,   262,
     262,   262,     4,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   266,   125,   109,     6,     6,   266,
     266,   103,   106,   109,   122,   323,   111,   262,     3,    10,
      11,    12,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    59,    60,    61,    62,    67,    68,
      77,    78,    79,    83,    84,    85,    94,    97,   103,   106,
     109,   111,   122,   123,   135,   140,   142,   145,   195,   213,
     217,   218,   223,   224,   225,   227,   228,   229,   250,   251,
     257,   262,   266,   269,   320,   321,   324,   335,   342,   344,
     355,   356,   360,   362,   368,   371,   386,   262,   266,   266,
     109,   109,   135,   106,   109,   111,   320,   106,   109,   110,
     111,   122,   190,   321,   106,   109,   262,   106,   167,   195,
     211,   212,   266,   250,   251,   262,   266,   365,   366,   365,
     266,   266,   365,     4,   103,   107,   113,   114,   116,   117,
     139,   266,   262,   109,   111,   109,   106,     4,    95,   206,
     266,   386,     4,     6,   103,     6,   106,   109,   106,   109,
     122,   322,     5,   262,   266,   368,   370,   109,     4,     4,
       4,   370,     4,   109,   262,   109,   262,   262,     4,   266,
     373,   386,     4,   262,   262,   262,     6,    33,   251,   355,
     386,     6,   264,     5,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    63,    64,    65,    66,    71,    72,    73,
      74,    80,    82,    96,    99,   214,   215,   216,   226,   230,
     232,   377,   386,   262,     4,   377,     5,   266,     5,   266,
     320,   355,   264,     6,   266,   262,   266,     6,   262,   266,
       6,   270,     7,   142,   206,   235,   236,   237,   238,   259,
     260,   262,   264,   268,   294,   295,   296,   320,   355,   376,
     377,   386,     4,   324,   325,   326,   266,     6,   355,   376,
     377,   386,   376,   376,   355,   376,   383,   384,   386,   355,
     326,   355,   301,   305,   262,   364,     9,   377,   262,   377,
     355,   355,   355,   262,   355,   355,   355,   262,   355,   355,
     355,   355,   355,   355,   355,   376,   355,   355,   355,   355,
     370,   262,   251,   355,   371,   372,   372,   266,   370,   368,
     376,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   262,   264,   296,
     296,   296,   296,   296,   296,   262,   296,   296,   262,   320,
     321,   321,   321,   296,   296,     5,   266,   266,   109,   135,
     320,   320,   321,   262,   296,   296,   262,   262,   262,   355,
     266,   355,   371,   355,   355,   267,   372,   362,   386,   198,
       5,   266,     8,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   261,     9,   262,   264,   268,   295,   296,   355,   372,
     372,   262,   262,   262,   368,   370,   370,   370,   319,   262,
     266,   262,   262,   368,   266,   266,   355,     4,   368,   266,
     373,   266,   266,   365,   365,   365,   355,   355,   250,   251,
     266,   266,   365,   250,   251,   262,   326,   365,   266,   262,
     266,   262,   262,   262,   262,   262,   262,   262,   372,   355,
     370,   370,   370,   262,   266,     4,   264,   266,     6,   264,
     326,     6,     6,   266,   266,   266,   266,   370,   355,     8,
       7,   266,   264,   264,   264,     6,     6,   262,   355,   262,
     355,   355,   268,   355,   266,   198,   355,   355,   355,   296,
     355,     6,   252,     9,   262,   264,   268,   355,   296,   296,
     296,   262,   262,   262,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   262,   262,   296,   262,   264,     6,
       6,   266,     6,     8,   326,     6,     8,   326,   262,   266,
     376,   372,   355,   326,   368,   368,   266,   377,   320,     7,
     355,   355,     4,    26,    37,    38,   112,   113,   195,   196,
     298,   368,     6,   263,   265,   266,   297,   266,     6,   266,
       6,     9,   262,   264,   268,   386,   267,   135,   140,   142,
     143,   145,   318,   320,   355,     6,   263,   271,     9,   262,
     264,   268,   263,   271,   263,   271,   271,   263,   271,     9,
     262,   268,   271,   267,   271,   265,   271,   300,   265,   300,
      98,   363,   361,   386,   271,   355,   271,   263,   263,   263,
     355,   263,   263,   263,   355,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   267,     7,   355,   252,
     267,   271,   267,   355,     6,     6,   263,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   371,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   371,   371,   386,   266,   355,
     355,   376,   355,   376,   368,   376,   376,   383,   266,   266,
     266,   266,   355,   297,   386,     8,   355,   355,   266,   370,
     368,   266,   376,   376,   371,   362,   377,   362,   372,   263,
     267,   268,   296,    68,     8,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   266,
     355,   371,   355,   355,   355,   355,   355,   386,   355,   355,
     298,   266,   297,   263,   267,   267,   355,   355,   355,     7,
       7,   348,   348,   262,   355,   355,   355,   355,     6,   171,
     372,   372,   266,   263,     6,   326,   266,   326,   326,   271,
     271,   271,   365,   365,   325,   325,   271,   355,   267,   339,
     271,   326,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   267,   263,     7,   349,     6,     7,   355,   355,     6,
     355,   326,   355,   267,   372,   372,   372,   355,     6,   263,
     267,   355,   372,   355,   355,   355,   355,   263,   355,   263,
     263,   195,   271,   326,   266,     8,   263,   263,   355,   355,
     386,   298,   265,   383,   376,   383,   376,   376,   376,   376,
     376,   376,   355,   376,   376,   376,   376,   269,   379,   386,
     377,   376,   376,   376,   362,   386,   372,   267,   267,   267,
     267,   355,   326,   265,   267,   263,   149,   167,   343,   263,
     267,   271,   355,     6,   266,   368,   263,   265,   268,     7,
       7,   294,   295,     6,   372,     7,   238,   294,   355,   279,
     386,   355,   355,   298,   264,   262,   135,   320,   321,   320,
     266,   267,     6,   245,   246,   276,   372,   386,   355,   355,
     298,     6,   372,     6,   372,   355,     6,   376,   384,   386,
     263,   298,   355,   355,     6,   386,     6,   376,   355,   263,
     264,   355,   271,   377,     7,     7,     7,   263,     7,     7,
       7,   263,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   355,   263,   266,   355,   371,     6,   266,   267,
       6,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   271,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   271,   271,   271,   271,   271,   263,   265,
     265,   372,   271,   271,   297,   271,   297,   271,   271,   271,
     263,   372,   355,   355,   355,   357,   297,   267,   267,   267,
     372,   355,   271,   271,   297,   297,   263,   268,   263,   268,
     271,   296,   358,   267,     7,   298,   297,   368,   267,     8,
       8,   372,   268,   263,   265,   262,   264,   295,   296,   372,
       7,   266,   266,   263,   263,   263,   355,   368,     4,   347,
       6,   314,   355,   377,   263,   267,   263,   263,   355,   267,
     267,   372,   268,   267,   326,   267,   267,   365,   355,   355,
     267,   267,   355,   365,   146,   146,   164,   175,   176,   177,
     181,   182,   340,   341,   365,   267,   336,   263,   267,   263,
     263,   263,   263,   263,   263,   263,   266,     7,   355,     6,
     355,   263,   267,   265,   267,   265,   267,   267,   267,   267,
       6,   267,   265,   265,   271,   263,     7,   263,     7,     7,
     268,   355,   267,   355,   355,   268,   262,   264,     7,   268,
     297,   271,   297,   297,   263,   263,   271,   297,   297,   271,
     271,   297,   297,   297,   297,   355,   297,     9,   378,   271,
     263,   271,   297,   268,   271,   359,   265,   267,   263,   267,
     270,   198,     7,   167,     6,   355,   267,   266,     6,   368,
     267,   355,     6,     7,   294,   295,   268,   294,   295,   298,
     266,   374,   386,   377,   355,     6,   267,    50,    50,   368,
     267,     4,   185,   186,   187,   188,   267,   282,   286,   289,
     291,   292,   334,   268,   263,   265,   262,   355,   355,   262,
     266,   262,   266,     8,   372,   376,   263,   268,   263,   265,
     262,   263,   263,   271,   268,   262,   267,   271,     7,   296,
       4,    26,    37,    38,   308,   309,   310,   297,   355,   297,
     365,   368,   368,     7,   368,   368,   368,     7,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,     6,     7,
     372,   325,   355,   355,   355,   355,   355,   355,   267,   355,
     355,   355,   368,   376,   376,   267,   267,   267,   267,   271,
     307,   267,   267,   355,   355,   298,   298,   355,   355,   263,
     368,   296,   355,   355,   267,   298,   295,   268,   295,   355,
     355,   297,   267,   368,   372,   372,     7,     7,     7,   146,
     346,     6,   263,   271,     7,     7,     7,     6,     7,     7,
     267,     4,   298,   267,   271,   271,   271,   267,   267,   121,
       4,     6,   355,   266,     6,   262,     6,   183,     6,   183,
     267,   341,   271,   340,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   325,   368,     6,   266,   103,     6,     6,
       6,   109,     7,     7,     6,     6,   355,     7,   368,     7,
     368,   368,     4,   271,     8,     8,   263,   298,   298,   298,
     372,   376,   355,   376,   269,   271,   311,   376,   376,   298,
     376,   263,   271,     6,   266,   320,   266,     6,   355,     6,
     266,   368,   267,   267,   355,     6,   195,   196,   298,   355,
       6,     7,   373,   375,     6,   264,     6,     6,   297,   296,
     296,     6,   283,   262,   262,   266,   293,     6,   298,   268,
     376,   355,   265,   263,   355,     8,   372,   355,   372,   267,
     267,     6,     6,   276,   298,   268,   355,     6,     6,   355,
     298,   263,     6,   355,   266,   355,   377,   297,    50,   266,
     368,   377,   380,   355,   355,   355,   265,   271,     6,   263,
       6,     6,   139,   316,   316,   368,     6,     6,     6,   368,
     146,   198,   315,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   267,   267,   297,   297,   297,   297,   297,
     297,   297,   271,   271,   271,   263,   297,   297,   309,   297,
     263,   297,   263,   296,   358,   297,     6,   297,   262,   264,
     296,   298,   263,   265,   297,     6,   267,   267,   368,   368,
     368,     4,     6,   294,   355,   368,   368,   368,   266,   266,
       7,     6,     7,   355,   355,   355,   266,   266,   266,   264,
       6,   355,   368,   355,     6,     6,   355,   365,   267,     5,
     368,   266,   266,   266,   266,   266,   266,   266,   368,   267,
       6,   372,   266,   266,   355,   355,   265,   368,     6,   368,
       6,   194,   355,   355,   355,   262,   264,     6,     6,     7,
     297,   271,   271,   297,   271,   355,     4,   210,   312,   313,
     297,   263,   297,   359,   377,   355,   266,   326,     6,   326,
     271,     6,     6,   268,     7,     7,   294,   295,     6,   373,
     267,   271,   355,   294,   266,   297,   381,   382,   383,   381,
     262,   355,   355,   367,   368,   266,   262,     4,     6,   263,
       6,   263,   267,   267,   263,   267,     6,     6,   376,   262,
       4,   263,   271,   262,   267,   271,   368,   377,     7,   296,
     306,   355,   371,   310,     6,   365,     6,     6,     6,   146,
     317,   103,   122,   107,     6,     5,   266,     6,   355,   355,
     355,   355,   263,   358,   355,   355,   297,   295,   266,   266,
       6,   315,     6,   355,   368,   146,   146,     4,     6,   372,
     372,   355,   355,   377,   267,   263,   267,   271,   325,   325,
     355,   355,   267,   271,   263,   267,   271,     6,     6,   367,
     365,   365,   365,   365,   365,   251,   365,     6,   267,   372,
     355,     6,     6,     6,     6,     6,   368,   267,   271,     8,
     267,   263,   251,   266,   355,   369,   377,   376,   355,   376,
     355,   377,   380,   382,   377,   271,   263,   271,   267,   355,
     343,   343,   368,   298,   374,   377,   355,     6,     6,   373,
     265,   368,   383,     6,   297,   297,   280,   355,   271,   271,
     267,   271,   281,   355,   355,     6,     6,     6,     6,   355,
     355,   263,     6,   355,   302,   304,   266,   382,   267,   271,
       7,     7,   150,     6,   266,   266,   266,     5,   367,   297,
     297,   271,   297,   263,   263,   265,   372,   372,     6,     6,
     355,   355,   266,   267,   267,   266,     6,     6,   266,   355,
     267,   267,   267,   265,     6,   368,     7,   266,   355,   267,
     271,   271,   271,   271,   271,   271,     6,   267,   267,   193,
     355,   355,   266,   267,   372,     6,     6,     6,   263,   297,
     297,   313,   377,   267,   267,   267,   267,     7,     6,     6,
       6,   268,     6,   267,     6,     6,   263,   271,   355,   355,
     266,   368,   267,   271,   263,   263,   271,   267,   307,   311,
     368,   297,   355,   377,   386,   372,   372,   355,     6,   267,
     355,   358,   267,   267,     6,     6,   367,   151,   152,   157,
     350,   151,   152,   350,   372,   325,   267,   271,     6,   267,
     368,   326,   267,     6,   372,   365,   365,   365,   365,   365,
       6,   355,   267,   267,   372,   267,   263,     6,   266,     6,
     373,   196,   284,   355,   271,   271,   367,     6,   355,   355,
       6,   267,   267,   303,     7,   262,   267,   267,   267,   266,
     271,   263,   266,   267,   266,   365,   368,     6,   266,   365,
       6,   267,   267,   355,     6,   146,   267,   337,   266,   267,
     271,   271,   271,   271,   271,     6,   267,     6,   326,     6,
     266,   355,   355,   267,   271,   307,   377,   263,   355,   355,
     372,     6,   365,     6,   365,     6,     6,   267,   355,   340,
     326,     6,   372,   372,   372,   372,   365,   372,   343,   281,
     263,   271,     6,   266,   355,   267,   271,   271,   267,   271,
     271,     6,   267,   267,   338,   267,   267,   267,   267,   271,
     267,   267,   267,   287,   355,   367,   267,   355,   355,   365,
     365,   340,     6,     6,     6,     6,   372,     6,     6,     6,
     266,   263,   267,     6,   267,   297,   271,   271,   267,   267,
     285,   376,   290,   266,     6,   355,   355,     6,   267,   271,
     266,   367,   267,   267,     6,   376,   288,   376,   267,     6,
       6,   267,   271,     6,     6,   376
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

  case 230:
#line 2599 "Gmsh.y"
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
#line 2620 "Gmsh.y"
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
#line 2641 "Gmsh.y"
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
#line 2666 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 234:
#line 2667 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 235:
#line 2672 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 236:
#line 2676 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 237:
#line 2680 "Gmsh.y"
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
#line 2697 "Gmsh.y"
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
#line 2717 "Gmsh.y"
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
#line 2737 "Gmsh.y"
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
#line 2756 "Gmsh.y"
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
#line 2783 "Gmsh.y"
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

  case 243:
#line 2802 "Gmsh.y"
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

  case 244:
#line 2824 "Gmsh.y"
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

  case 245:
#line 2839 "Gmsh.y"
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

  case 246:
#line 2854 "Gmsh.y"
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

  case 247:
#line 2873 "Gmsh.y"
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

  case 248:
#line 2924 "Gmsh.y"
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

  case 249:
#line 2945 "Gmsh.y"
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

  case 250:
#line 2967 "Gmsh.y"
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

  case 251:
#line 2989 "Gmsh.y"
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

  case 252:
#line 3094 "Gmsh.y"
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

  case 253:
#line 3110 "Gmsh.y"
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

  case 254:
#line 3145 "Gmsh.y"
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

  case 255:
#line 3170 "Gmsh.y"
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

  case 256:
#line 3195 "Gmsh.y"
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

  case 257:
#line 3207 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 258:
#line 3213 "Gmsh.y"
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

  case 259:
#line 3228 "Gmsh.y"
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

  case 260:
#line 3259 "Gmsh.y"
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

  case 261:
#line 3271 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 262:
#line 3280 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 263:
#line 3287 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 264:
#line 3299 "Gmsh.y"
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

  case 265:
#line 3319 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 266:
#line 3323 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 267:
#line 3328 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 268:
#line 3332 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 269:
#line 3337 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 270:
#line 3344 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 271:
#line 3351 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 272:
#line 3358 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 273:
#line 3370 "Gmsh.y"
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

  case 274:
#line 3443 "Gmsh.y"
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

  case 275:
#line 3461 "Gmsh.y"
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

  case 276:
#line 3486 "Gmsh.y"
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

  case 277:
#line 3501 "Gmsh.y"
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

  case 278:
#line 3550 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 279:
#line 3556 "Gmsh.y"
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

  case 280:
#line 3568 "Gmsh.y"
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

  case 281:
#line 3600 "Gmsh.y"
    {
      Msg::Exit(0, false); // will return 0 only if no meshing error occurred
    ;}
    break;

  case 282:
#line 3604 "Gmsh.y"
    {
      Msg::Exit((int)(yyvsp[(2) - (3)].d), true); // will always return the specified value
    ;}
    break;

  case 283:
#line 3608 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 284:
#line 3613 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 285:
#line 3620 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 286:
#line 3625 "Gmsh.y"
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

  case 287:
#line 3635 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 288:
#line 3640 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 289:
#line 3646 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 290:
#line 3654 "Gmsh.y"
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

  case 291:
#line 3665 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 292:
#line 3673 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 293:
#line 3677 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 294:
#line 3681 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 295:
#line 3685 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 296:
#line 3692 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 297:
#line 3696 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 298:
#line 3700 "Gmsh.y"
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

  case 299:
#line 3712 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 300:
#line 3722 "Gmsh.y"
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

  case 301:
#line 3780 "Gmsh.y"
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

  case 302:
#line 3800 "Gmsh.y"
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

  case 303:
#line 3826 "Gmsh.y"
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

  case 304:
#line 3842 "Gmsh.y"
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

  case 305:
#line 3859 "Gmsh.y"
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

  case 306:
#line 3876 "Gmsh.y"
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

  case 307:
#line 3898 "Gmsh.y"
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

  case 308:
#line 3920 "Gmsh.y"
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

  case 309:
#line 3955 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 310:
#line 3963 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 311:
#line 3971 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 312:
#line 3977 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 313:
#line 3984 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 314:
#line 3991 "Gmsh.y"
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

  case 315:
#line 4011 "Gmsh.y"
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

  case 316:
#line 4037 "Gmsh.y"
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

  case 317:
#line 4049 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 318:
#line 4060 "Gmsh.y"
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

  case 319:
#line 4078 "Gmsh.y"
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

  case 320:
#line 4096 "Gmsh.y"
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

  case 321:
#line 4114 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4120 "Gmsh.y"
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

  case 323:
#line 4138 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4144 "Gmsh.y"
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

  case 325:
#line 4164 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4170 "Gmsh.y"
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

  case 327:
#line 4188 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 328:
#line 4194 "Gmsh.y"
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

  case 329:
#line 4211 "Gmsh.y"
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

  case 330:
#line 4227 "Gmsh.y"
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

  case 331:
#line 4244 "Gmsh.y"
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

  case 332:
#line 4262 "Gmsh.y"
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

  case 333:
#line 4285 "Gmsh.y"
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

  case 334:
#line 4312 "Gmsh.y"
    {
    ;}
    break;

  case 335:
#line 4315 "Gmsh.y"
    {
    ;}
    break;

  case 336:
#line 4321 "Gmsh.y"
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

  case 337:
#line 4333 "Gmsh.y"
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

  case 338:
#line 4353 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 339:
#line 4357 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 340:
#line 4361 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 341:
#line 4365 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 342:
#line 4369 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 343:
#line 4373 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 344:
#line 4377 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 345:
#line 4381 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 346:
#line 4390 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 347:
#line 4402 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 348:
#line 4403 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 349:
#line 4404 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 350:
#line 4405 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 351:
#line 4406 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 352:
#line 4410 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 353:
#line 4411 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 354:
#line 4412 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 355:
#line 4413 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 356:
#line 4414 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 357:
#line 4419 "Gmsh.y"
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

  case 358:
#line 4442 "Gmsh.y"
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

  case 359:
#line 4462 "Gmsh.y"
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

  case 360:
#line 4483 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 361:
#line 4487 "Gmsh.y"
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

  case 362:
#line 4514 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 363:
#line 4518 "Gmsh.y"
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

  case 364:
#line 4534 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 365:
#line 4538 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 366:
#line 4543 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 367:
#line 4547 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 368:
#line 4553 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 369:
#line 4557 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 370:
#line 4564 "Gmsh.y"
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

  case 371:
#line 4587 "Gmsh.y"
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

  case 372:
#line 4606 "Gmsh.y"
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

  case 373:
#line 4647 "Gmsh.y"
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

  case 374:
#line 4691 "Gmsh.y"
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

  case 375:
#line 4730 "Gmsh.y"
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

  case 376:
#line 4755 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 377:
#line 4762 "Gmsh.y"
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

  case 378:
#line 4773 "Gmsh.y"
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

  case 379:
#line 4790 "Gmsh.y"
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

  case 380:
#line 4807 "Gmsh.y"
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

  case 381:
#line 4837 "Gmsh.y"
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

  case 382:
#line 4863 "Gmsh.y"
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

  case 383:
#line 4890 "Gmsh.y"
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

  case 384:
#line 4922 "Gmsh.y"
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

  case 385:
#line 4950 "Gmsh.y"
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

  case 386:
#line 4976 "Gmsh.y"
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

  case 387:
#line 5002 "Gmsh.y"
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

  case 388:
#line 5028 "Gmsh.y"
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

  case 389:
#line 5054 "Gmsh.y"
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

  case 390:
#line 5075 "Gmsh.y"
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

  case 391:
#line 5087 "Gmsh.y"
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

  case 392:
#line 5135 "Gmsh.y"
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

  case 393:
#line 5189 "Gmsh.y"
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

  case 394:
#line 5204 "Gmsh.y"
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

  case 395:
#line 5216 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 396:
#line 5222 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 397:
#line 5234 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 398:
#line 5241 "Gmsh.y"
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

  case 399:
#line 5256 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 400:
#line 5265 "Gmsh.y"
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

  case 401:
#line 5285 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 402:
#line 5286 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 403:
#line 5287 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 404:
#line 5292 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 405:
#line 5298 "Gmsh.y"
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

  case 406:
#line 5310 "Gmsh.y"
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

  case 407:
#line 5328 "Gmsh.y"
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

  case 408:
#line 5355 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 409:
#line 5356 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 410:
#line 5357 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5358 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 412:
#line 5359 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 413:
#line 5360 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5361 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5362 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 416:
#line 5364 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 417:
#line 5370 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 418:
#line 5371 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 419:
#line 5372 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 420:
#line 5373 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 421:
#line 5374 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 422:
#line 5375 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 423:
#line 5376 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5377 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5378 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5379 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5380 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 428:
#line 5381 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 429:
#line 5382 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 430:
#line 5383 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 431:
#line 5384 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 432:
#line 5385 "Gmsh.y"
    { (yyval.d) = ((yyvsp[(3) - (4)].d) < 0) ? 0 : 1; ;}
    break;

  case 433:
#line 5386 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 434:
#line 5387 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5388 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 436:
#line 5389 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5390 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 438:
#line 5391 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5392 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 440:
#line 5393 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5394 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 442:
#line 5395 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5396 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 444:
#line 5397 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 445:
#line 5398 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 446:
#line 5399 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 447:
#line 5400 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 448:
#line 5401 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 449:
#line 5402 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 450:
#line 5403 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 451:
#line 5404 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 452:
#line 5405 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 453:
#line 5406 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 454:
#line 5407 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 455:
#line 5408 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 456:
#line 5409 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 457:
#line 5410 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 458:
#line 5419 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 459:
#line 5420 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 460:
#line 5421 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 461:
#line 5422 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 462:
#line 5423 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 463:
#line 5424 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 464:
#line 5425 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 465:
#line 5426 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 466:
#line 5427 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 467:
#line 5428 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 468:
#line 5429 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 469:
#line 5434 "Gmsh.y"
    { init_options(); ;}
    break;

  case 470:
#line 5436 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 471:
#line 5442 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 472:
#line 5446 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 473:
#line 5451 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 474:
#line 5456 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 475:
#line 5461 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 476:
#line 5466 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 477:
#line 5470 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 478:
#line 5474 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 479:
#line 5478 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 480:
#line 5482 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 481:
#line 5486 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 482:
#line 5490 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 483:
#line 5494 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 484:
#line 5500 "Gmsh.y"
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

  case 485:
#line 5515 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 486:
#line 5519 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 487:
#line 5525 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 488:
#line 5530 "Gmsh.y"
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

  case 489:
#line 5549 "Gmsh.y"
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

  case 490:
#line 5569 "Gmsh.y"
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
#line 5590 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 492:
#line 5594 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 493:
#line 5598 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 494:
#line 5602 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 495:
#line 5606 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 496:
#line 5610 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 497:
#line 5614 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 498:
#line 5619 "Gmsh.y"
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

  case 499:
#line 5629 "Gmsh.y"
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

  case 500:
#line 5639 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 501:
#line 5644 "Gmsh.y"
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

  case 502:
#line 5655 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 503:
#line 5664 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 504:
#line 5669 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 505:
#line 5674 "Gmsh.y"
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

  case 506:
#line 5701 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 507:
#line 5703 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 508:
#line 5708 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 509:
#line 5710 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 510:
#line 5715 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 511:
#line 5722 "Gmsh.y"
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

  case 512:
#line 5738 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 513:
#line 5740 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 514:
#line 5745 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 515:
#line 5747 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 516:
#line 5752 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 517:
#line 5754 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 518:
#line 5759 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 519:
#line 5763 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 520:
#line 5767 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 521:
#line 5771 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 522:
#line 5775 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 523:
#line 5782 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 524:
#line 5786 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 525:
#line 5790 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 526:
#line 5794 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 527:
#line 5801 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 528:
#line 5806 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 529:
#line 5813 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 530:
#line 5818 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 531:
#line 5822 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 532:
#line 5826 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 533:
#line 5830 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 534:
#line 5838 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 535:
#line 5849 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 536:
#line 5853 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 537:
#line 5857 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 538:
#line 5868 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 539:
#line 5872 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 540:
#line 5876 "Gmsh.y"
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

  case 541:
#line 5890 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 542:
#line 5898 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 543:
#line 5906 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 544:
#line 5913 "Gmsh.y"
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

  case 545:
#line 5923 "Gmsh.y"
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

  case 546:
#line 5946 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 547:
#line 5951 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 548:
#line 5957 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 549:
#line 5962 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 550:
#line 5968 "Gmsh.y"
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

  case 551:
#line 5979 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 552:
#line 5985 "Gmsh.y"
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

  case 553:
#line 5999 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 554:
#line 6005 "Gmsh.y"
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

  case 555:
#line 6017 "Gmsh.y"
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

  case 556:
#line 6031 "Gmsh.y"
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

  case 557:
#line 6044 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      (yyval.l) = List_Create(9, 1, sizeof(double));
      if(List_Nbr((yyvsp[(4) - (5)].l)) < 1) {
        yymsg(0, "Missing surface tag for normal computation");
      }
      else {
        double d;
        List_Read((yyvsp[(4) - (5)].l), 0, &d);
        int tag = (int)d;
        GFace *gf = GModel::current()->getFaceByTag(tag);
        if(!gf) {
          yymsg(0, "Surface %d does not exist", tag);
        }
        if(List_Nbr((yyvsp[(4) - (5)].l)) == 1) {
          SPoint2 param(0., 0.);
          SVector3 n = gf->normal(param);
          double x = n.x(), y = n.y(), z = n.z();
          List_Add((yyval.l), &x);
          List_Add((yyval.l), &y);
          List_Add((yyval.l), &z);
        }
        else if(List_Nbr((yyvsp[(4) - (5)].l)) - 1 % 2) {
          yymsg(0, "Number of parametric coordinates should be even");
        }
        else {
          for(int i = 1; i < List_Nbr((yyvsp[(4) - (5)].l)); i += 2) {
            double u, v;
            List_Read((yyvsp[(4) - (5)].l), i, &u);
            List_Read((yyvsp[(4) - (5)].l), i + 1, &v);
            SPoint2 param(u, v);
            SVector3 n = gf->normal(param);
            double x = n.x(), y = n.y(), z = n.z();
            List_Add((yyval.l), &x);
            List_Add((yyval.l), &y);
            List_Add((yyval.l), &z);
          }
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 558:
#line 6090 "Gmsh.y"
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

  case 559:
#line 6107 "Gmsh.y"
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
#line 6117 "Gmsh.y"
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

  case 561:
#line 6127 "Gmsh.y"
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

  case 562:
#line 6137 "Gmsh.y"
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

  case 563:
#line 6149 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 564:
#line 6153 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 565:
#line 6158 "Gmsh.y"
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

  case 566:
#line 6170 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 567:
#line 6174 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 568:
#line 6178 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 569:
#line 6182 "Gmsh.y"
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

  case 570:
#line 6200 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 571:
#line 6208 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 572:
#line 6216 "Gmsh.y"
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

  case 573:
#line 6245 "Gmsh.y"
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

  case 574:
#line 6255 "Gmsh.y"
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

  case 575:
#line 6271 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 576:
#line 6282 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 577:
#line 6287 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 578:
#line 6291 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 579:
#line 6295 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 580:
#line 6307 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 581:
#line 6311 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 582:
#line 6323 "Gmsh.y"
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
#line 6340 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 584:
#line 6350 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 585:
#line 6354 "Gmsh.y"
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
#line 6369 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 587:
#line 6374 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 588:
#line 6381 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 589:
#line 6385 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 590:
#line 6390 "Gmsh.y"
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
#line 6404 "Gmsh.y"
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
#line 6418 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 593:
#line 6422 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 594:
#line 6426 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 595:
#line 6430 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 596:
#line 6434 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 597:
#line 6442 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 598:
#line 6448 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 599:
#line 6457 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 600:
#line 6461 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 601:
#line 6465 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 602:
#line 6473 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 603:
#line 6479 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 604:
#line 6485 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 605:
#line 6489 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 606:
#line 6496 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 607:
#line 6504 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 608:
#line 6511 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 609:
#line 6520 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 610:
#line 6524 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 611:
#line 6528 "Gmsh.y"
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
#line 6543 "Gmsh.y"
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
#line 6557 "Gmsh.y"
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
#line 6571 "Gmsh.y"
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
#line 6583 "Gmsh.y"
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
#line 6599 "Gmsh.y"
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
#line 6608 "Gmsh.y"
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
#line 6617 "Gmsh.y"
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
#line 6627 "Gmsh.y"
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
#line 6638 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 621:
#line 6646 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 622:
#line 6654 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 623:
#line 6658 "Gmsh.y"
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
#line 6676 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 625:
#line 6683 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 626:
#line 6689 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 627:
#line 6695 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 628:
#line 6702 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 629:
#line 6709 "Gmsh.y"
    { init_options(); ;}
    break;

  case 630:
#line 6711 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 631:
#line 6719 "Gmsh.y"
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
#line 6743 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 633:
#line 6745 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 634:
#line 6751 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 635:
#line 6756 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 636:
#line 6758 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 637:
#line 6763 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 638:
#line 6768 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 639:
#line 6773 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 640:
#line 6775 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 641:
#line 6779 "Gmsh.y"
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
#line 6791 "Gmsh.y"
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
#line 6805 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 644:
#line 6809 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 645:
#line 6816 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 646:
#line 6824 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 647:
#line 6832 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 648:
#line 6843 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 649:
#line 6845 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 650:
#line 6848 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15246 "Gmsh.tab.cpp"
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


#line 6851 "Gmsh.y"


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

