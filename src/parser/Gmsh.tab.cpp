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
     tCharacteristic = 378,
     tLength = 379,
     tParametric = 380,
     tElliptic = 381,
     tRefineMesh = 382,
     tRecombineMesh = 383,
     tAdaptMesh = 384,
     tTransformMesh = 385,
     tRelocateMesh = 386,
     tReorientMesh = 387,
     tSetFactory = 388,
     tThruSections = 389,
     tWedge = 390,
     tFillet = 391,
     tChamfer = 392,
     tPlane = 393,
     tRuled = 394,
     tTransfinite = 395,
     tPhysical = 396,
     tCompound = 397,
     tPeriodic = 398,
     tParent = 399,
     tUsing = 400,
     tPlugin = 401,
     tDegenerated = 402,
     tRecursive = 403,
     tSewing = 404,
     tRotate = 405,
     tTranslate = 406,
     tSymmetry = 407,
     tDilate = 408,
     tExtrude = 409,
     tLevelset = 410,
     tAffine = 411,
     tBooleanUnion = 412,
     tBooleanIntersection = 413,
     tBooleanDifference = 414,
     tBooleanSection = 415,
     tBooleanFragments = 416,
     tThickSolid = 417,
     tRecombine = 418,
     tSmoother = 419,
     tSplit = 420,
     tDelete = 421,
     tCoherence = 422,
     tHealShapes = 423,
     tIntersect = 424,
     tMeshAlgorithm = 425,
     tReverseMesh = 426,
     tMeshSize = 427,
     tMeshSizeFromBoundary = 428,
     tLayers = 429,
     tScaleLast = 430,
     tHole = 431,
     tAlias = 432,
     tAliasWithOptions = 433,
     tCopyOptions = 434,
     tQuadTriAddVerts = 435,
     tQuadTriNoNewVerts = 436,
     tRecombLaterals = 437,
     tTransfQuadTri = 438,
     tText2D = 439,
     tText3D = 440,
     tInterpolationScheme = 441,
     tTime = 442,
     tCombine = 443,
     tBSpline = 444,
     tBezier = 445,
     tNurbs = 446,
     tNurbsOrder = 447,
     tNurbsKnots = 448,
     tColor = 449,
     tColorTable = 450,
     tFor = 451,
     tIn = 452,
     tEndFor = 453,
     tIf = 454,
     tElseIf = 455,
     tElse = 456,
     tEndIf = 457,
     tExit = 458,
     tAbort = 459,
     tField = 460,
     tReturn = 461,
     tCall = 462,
     tSlide = 463,
     tMacro = 464,
     tShow = 465,
     tHide = 466,
     tGetValue = 467,
     tGetStringValue = 468,
     tGetEnv = 469,
     tGetString = 470,
     tGetNumber = 471,
     tUnique = 472,
     tSetMaxTag = 473,
     tHomology = 474,
     tCohomology = 475,
     tBetti = 476,
     tExists = 477,
     tFileExists = 478,
     tGetForced = 479,
     tGetForcedStr = 480,
     tGMSH_MAJOR_VERSION = 481,
     tGMSH_MINOR_VERSION = 482,
     tGMSH_PATCH_VERSION = 483,
     tGmshExecutableName = 484,
     tSetPartition = 485,
     tNameToString = 486,
     tStringToName = 487,
     tUnsplitWindow = 488,
     tAFFECTDIVIDE = 489,
     tAFFECTTIMES = 490,
     tAFFECTMINUS = 491,
     tAFFECTPLUS = 492,
     tOR = 493,
     tAND = 494,
     tNOTEQUAL = 495,
     tEQUAL = 496,
     tGREATERGREATER = 497,
     tLESSLESS = 498,
     tGREATEROREQUAL = 499,
     tLESSOREQUAL = 500,
     UNARYPREC = 501,
     tMINUSMINUS = 502,
     tPLUSPLUS = 503
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
#define tCharacteristic 378
#define tLength 379
#define tParametric 380
#define tElliptic 381
#define tRefineMesh 382
#define tRecombineMesh 383
#define tAdaptMesh 384
#define tTransformMesh 385
#define tRelocateMesh 386
#define tReorientMesh 387
#define tSetFactory 388
#define tThruSections 389
#define tWedge 390
#define tFillet 391
#define tChamfer 392
#define tPlane 393
#define tRuled 394
#define tTransfinite 395
#define tPhysical 396
#define tCompound 397
#define tPeriodic 398
#define tParent 399
#define tUsing 400
#define tPlugin 401
#define tDegenerated 402
#define tRecursive 403
#define tSewing 404
#define tRotate 405
#define tTranslate 406
#define tSymmetry 407
#define tDilate 408
#define tExtrude 409
#define tLevelset 410
#define tAffine 411
#define tBooleanUnion 412
#define tBooleanIntersection 413
#define tBooleanDifference 414
#define tBooleanSection 415
#define tBooleanFragments 416
#define tThickSolid 417
#define tRecombine 418
#define tSmoother 419
#define tSplit 420
#define tDelete 421
#define tCoherence 422
#define tHealShapes 423
#define tIntersect 424
#define tMeshAlgorithm 425
#define tReverseMesh 426
#define tMeshSize 427
#define tMeshSizeFromBoundary 428
#define tLayers 429
#define tScaleLast 430
#define tHole 431
#define tAlias 432
#define tAliasWithOptions 433
#define tCopyOptions 434
#define tQuadTriAddVerts 435
#define tQuadTriNoNewVerts 436
#define tRecombLaterals 437
#define tTransfQuadTri 438
#define tText2D 439
#define tText3D 440
#define tInterpolationScheme 441
#define tTime 442
#define tCombine 443
#define tBSpline 444
#define tBezier 445
#define tNurbs 446
#define tNurbsOrder 447
#define tNurbsKnots 448
#define tColor 449
#define tColorTable 450
#define tFor 451
#define tIn 452
#define tEndFor 453
#define tIf 454
#define tElseIf 455
#define tElse 456
#define tEndIf 457
#define tExit 458
#define tAbort 459
#define tField 460
#define tReturn 461
#define tCall 462
#define tSlide 463
#define tMacro 464
#define tShow 465
#define tHide 466
#define tGetValue 467
#define tGetStringValue 468
#define tGetEnv 469
#define tGetString 470
#define tGetNumber 471
#define tUnique 472
#define tSetMaxTag 473
#define tHomology 474
#define tCohomology 475
#define tBetti 476
#define tExists 477
#define tFileExists 478
#define tGetForced 479
#define tGetForcedStr 480
#define tGMSH_MAJOR_VERSION 481
#define tGMSH_MINOR_VERSION 482
#define tGMSH_PATCH_VERSION 483
#define tGmshExecutableName 484
#define tSetPartition 485
#define tNameToString 486
#define tStringToName 487
#define tUnsplitWindow 488
#define tAFFECTDIVIDE 489
#define tAFFECTTIMES 490
#define tAFFECTMINUS 491
#define tAFFECTPLUS 492
#define tOR 493
#define tAND 494
#define tNOTEQUAL 495
#define tEQUAL 496
#define tGREATERGREATER 497
#define tLESSLESS 498
#define tGREATEROREQUAL 499
#define tLESSOREQUAL 500
#define UNARYPREC 501
#define tMINUSMINUS 502
#define tPLUSPLUS 503




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
#line 779 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 792 "Gmsh.tab.cpp"

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
#define YYLAST   18308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  271
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  649
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2311

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   503

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   256,     2,   268,     2,   253,   255,     2,
     261,   262,   251,   249,   270,   250,   267,   252,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     243,     2,   244,   238,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   263,     2,   264,   260,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   265,   254,   266,   269,     2,     2,     2,
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
     235,   236,   237,   239,   240,   241,   242,   245,   246,   247,
     248,   257,   258,   259
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
    2959,  2963,  2967,  2972,  2978,  2984,  2990,  2996,  3002,  3004,
    3006,  3008,  3012,  3018,  3026,  3031,  3036,  3041,  3048,  3055,
    3064,  3073,  3078,  3093,  3098,  3103,  3105,  3107,  3111,  3115,
    3125,  3133,  3135,  3141,  3145,  3152,  3154,  3158,  3160,  3162,
    3167,  3172,  3176,  3182,  3189,  3198,  3205,  3210,  3216,  3218,
    3223,  3225,  3227,  3229,  3231,  3236,  3243,  3248,  3255,  3261,
    3269,  3274,  3279,  3284,  3293,  3298,  3303,  3308,  3313,  3322,
    3331,  3338,  3343,  3350,  3355,  3357,  3359,  3364,  3369,  3370,
    3377,  3382,  3385,  3390,  3395,  3397,  3399,  3403,  3405,  3407,
    3411,  3415,  3419,  3425,  3433,  3439,  3445,  3454,  3456,  3458
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     272,     0,    -1,   273,    -1,     1,     6,    -1,    -1,   273,
     274,    -1,   276,    -1,   277,    -1,   298,    -1,   133,   261,
     375,   262,     6,    -1,   317,    -1,   323,    -1,   327,    -1,
     328,    -1,   329,    -1,   330,    -1,   334,    -1,   343,    -1,
     344,    -1,   350,    -1,   351,    -1,   333,    -1,   332,    -1,
     331,    -1,   326,    -1,   353,    -1,   244,    -1,   245,    -1,
      47,   261,   375,   262,     6,    -1,    49,   261,   375,   262,
       6,    -1,    48,   261,   375,   262,     6,    -1,    47,   261,
     375,   262,   275,   375,     6,    -1,    47,   261,   375,   270,
     371,   262,     6,    -1,    49,   261,   375,   270,   371,   262,
       6,    -1,    48,   261,   375,   270,   371,   262,     6,    -1,
      47,   261,   375,   270,   371,   262,   275,   375,     6,    -1,
     385,   375,   265,   278,   266,     6,    -1,   177,     4,   263,
     354,   264,     6,    -1,   178,     4,   263,   354,   264,     6,
      -1,   179,     4,   263,   354,   270,   354,   264,     6,    -1,
      -1,   278,   281,    -1,   278,   285,    -1,   278,   288,    -1,
     278,   290,    -1,   278,   291,    -1,   278,   333,    -1,   354,
      -1,   279,   270,   354,    -1,   354,    -1,   280,   270,   354,
      -1,    -1,    -1,     4,   282,   261,   279,   262,   283,   265,
     280,   266,     6,    -1,   375,    -1,   284,   270,   375,    -1,
      -1,   184,   261,   354,   270,   354,   270,   354,   262,   286,
     265,   284,   266,     6,    -1,   375,    -1,   287,   270,   375,
      -1,    -1,   185,   261,   354,   270,   354,   270,   354,   270,
     354,   262,   289,   265,   287,   266,     6,    -1,   186,   265,
     366,   266,   265,   366,   266,     6,    -1,   186,   265,   366,
     266,   265,   366,   266,   265,   366,   266,   265,   366,   266,
       6,    -1,    -1,   187,   292,   265,   280,   266,     6,    -1,
       7,    -1,   237,    -1,   236,    -1,   235,    -1,   234,    -1,
     259,    -1,   258,    -1,   261,    -1,   263,    -1,   262,    -1,
     264,    -1,     4,    -1,    37,    -1,    38,    -1,    26,    -1,
     112,    -1,   113,    -1,    92,   263,   300,   264,     6,    -1,
      93,   263,   304,   264,     6,    -1,   359,     6,    -1,   100,
     295,   376,   270,   354,   296,     6,    -1,   102,   295,   376,
     270,   376,   296,     6,    -1,   385,   293,   367,     6,    -1,
     385,   294,     6,    -1,   385,   295,   296,   293,   367,     6,
      -1,   385,   295,   265,   371,   266,   296,   293,   367,     6,
      -1,   385,   263,   354,   264,   293,   354,     6,    -1,   385,
     263,   354,   264,   294,     6,    -1,   385,   261,   354,   262,
     293,   354,     6,    -1,   385,   261,   354,   262,   294,     6,
      -1,   385,     7,   376,     6,    -1,   385,   295,   296,     7,
      50,   295,   296,     6,    -1,   385,   295,   296,     7,    50,
     295,   380,   296,     6,    -1,   385,   295,   296,   237,    50,
     295,   380,   296,     6,    -1,   385,   267,   297,     7,   376,
       6,    -1,   385,   263,   354,   264,   267,   297,     7,   376,
       6,    -1,   385,   267,   297,   293,   354,     6,    -1,   385,
     263,   354,   264,   267,   297,   293,   354,     6,    -1,   385,
     267,   297,   294,     6,    -1,   385,   263,   354,   264,   267,
     297,   294,     6,    -1,   385,   267,   194,   267,   297,     7,
     372,     6,    -1,   385,   263,   354,   264,   267,   194,   267,
     297,     7,   372,     6,    -1,   385,   267,   195,     7,   373,
       6,    -1,   385,   263,   354,   264,   267,   195,     7,   373,
       6,    -1,   385,   205,     7,   367,     6,    -1,   205,   263,
     354,   264,     7,   297,     6,    -1,   205,   263,   354,   264,
     267,   297,     7,   354,     6,    -1,   205,   263,   354,   264,
     267,   297,     7,   376,     6,    -1,   205,   263,   354,   264,
     267,   297,     7,   368,     6,    -1,   205,   263,   354,   264,
     267,   297,     6,    -1,   146,   261,     4,   262,   267,   297,
       7,   354,     6,    -1,   146,   261,     4,   262,   267,   297,
       7,   376,     6,    -1,    -1,   270,    -1,    -1,   300,   299,
     385,    -1,   300,   299,   385,     7,   354,    -1,    -1,   300,
     299,   385,     7,   265,   367,   301,   306,   266,    -1,    -1,
     300,   299,   385,   295,   296,     7,   265,   367,   302,   306,
     266,    -1,   300,   299,   385,     7,   376,    -1,    -1,   300,
     299,   385,     7,   265,   376,   303,   310,   266,    -1,    -1,
     304,   299,   375,    -1,   354,     7,   376,    -1,   305,   270,
     354,     7,   376,    -1,   370,     7,   385,   261,   262,    -1,
      -1,   270,   308,    -1,    -1,   308,    -1,   309,    -1,   308,
     270,   309,    -1,     4,   367,    -1,    37,   354,    -1,    38,
     354,    -1,    26,   354,    -1,     4,    -1,     4,   265,   305,
     266,    -1,     4,   376,    -1,     4,   379,    -1,    -1,   270,
     311,    -1,   312,    -1,   311,   270,   312,    -1,     4,   354,
      -1,     4,   376,    -1,   209,   376,    -1,     4,   381,    -1,
       4,   379,    -1,   354,    -1,   376,    -1,   376,   270,   354,
      -1,    -1,   197,   107,   265,   354,   266,    -1,   145,   103,
     265,   371,   266,    -1,   145,   122,   265,   371,   266,    -1,
      -1,   138,   364,    -1,    -1,   145,   149,    -1,   103,   261,
     354,   262,     7,   364,     6,    -1,   106,   261,   354,   262,
       7,   367,     6,    -1,   110,   261,   354,   262,     7,   367,
       6,    -1,   142,   110,   261,   354,   262,     7,   367,   145,
     354,     6,    -1,   142,   189,   261,   354,   262,     7,   367,
     145,   354,     6,    -1,   104,   261,   354,   262,     7,   367,
     315,     6,    -1,   105,   261,   354,   262,     7,   367,   315,
       6,    -1,   189,   261,   354,   262,     7,   367,     6,    -1,
     190,   261,   354,   262,     7,   367,     6,    -1,   191,   261,
     354,   262,     7,   367,   193,   367,   192,   354,     6,    -1,
     121,   261,   354,   262,     7,   367,     6,    -1,   106,     4,
     261,   354,   262,     7,   367,     6,    -1,   138,   109,   261,
     354,   262,     7,   367,     6,    -1,   109,   261,   354,   262,
       7,   367,   314,     6,    -1,   139,   109,   261,   354,   262,
       7,   367,   314,     6,    -1,   189,   109,   261,   354,   262,
       7,   367,     6,    -1,   190,   109,   261,   354,   262,     7,
     367,     6,    -1,    13,    14,     6,    -1,    14,   109,   354,
       6,    -1,   125,   109,   261,   354,   262,     7,     5,     5,
       5,     6,    -1,   107,   261,   354,   262,     7,   367,     6,
      -1,   108,   261,   354,   262,     7,   367,     6,    -1,   112,
     261,   354,   262,     7,   367,     6,    -1,   115,   261,   354,
     262,     7,   367,     6,    -1,   119,   261,   354,   262,     7,
     367,     6,    -1,   120,   261,   354,   262,     7,   367,     6,
      -1,   113,   261,   354,   262,     7,   367,     6,    -1,   114,
     261,   354,   262,     7,   367,     6,    -1,   135,   261,   354,
     262,     7,   367,     6,    -1,   162,   261,   354,   262,     7,
     367,     6,    -1,   109,     4,   261,   354,   262,     7,   367,
     316,     6,    -1,   111,   261,   354,   262,     7,   367,     6,
      -1,   134,   261,   354,   262,     7,   367,     6,    -1,   139,
     134,   261,   354,   262,     7,   367,     6,    -1,   142,   320,
     261,   354,   262,     7,   367,     6,    -1,   142,   320,   261,
     354,   262,     7,   367,     4,   265,   366,   266,     6,    -1,
      -1,   141,   319,   318,   261,   313,   262,   293,   367,     6,
      -1,   103,    -1,   106,    -1,   109,    -1,   111,    -1,   122,
     265,   354,   266,    -1,   106,    -1,   109,    -1,   111,    -1,
     122,   265,   354,   266,    -1,   106,    -1,   109,    -1,   122,
     265,   354,   266,    -1,   103,    -1,   106,    -1,   109,    -1,
     122,   265,   354,   266,    -1,   151,   364,   265,   324,   266,
      -1,   150,   265,   364,   270,   364,   270,   354,   266,   265,
     324,   266,    -1,   152,   364,   265,   324,   266,    -1,   153,
     265,   364,   270,   354,   266,   265,   324,   266,    -1,   153,
     265,   364,   270,   364,   266,   265,   324,   266,    -1,   156,
     265,   371,   266,   265,   324,   266,    -1,     4,   265,   324,
     266,    -1,   169,   106,   265,   371,   266,   109,   265,   354,
     266,    -1,   165,   106,   265,   354,   266,   103,   265,   371,
     266,     6,    -1,   165,   106,   261,   354,   262,   265,   371,
     266,     6,    -1,   325,    -1,   323,    -1,    -1,   325,   317,
      -1,   325,   319,   265,   371,   266,     6,    -1,   325,   141,
     319,   265,   371,   266,     6,    -1,   325,   144,   319,   265,
     371,   266,     6,    -1,   325,   319,   265,     8,   266,     6,
      -1,   325,   141,   319,   265,     8,   266,     6,    -1,   155,
     138,   261,   354,   262,     7,   367,     6,    -1,   155,   103,
     261,   354,   262,     7,   265,   366,   266,     6,    -1,   155,
     138,   261,   354,   262,     7,   265,   364,   270,   364,   270,
     371,   266,     6,    -1,   155,   138,   261,   354,   262,     7,
     265,   364,   270,   364,   270,   364,   270,   371,   266,     6,
      -1,   155,   107,   261,   354,   262,     7,   265,   364,   270,
     371,   266,     6,    -1,   155,   113,   261,   354,   262,     7,
     265,   364,   270,   364,   270,   371,   266,     6,    -1,   155,
     114,   261,   354,   262,     7,   265,   364,   270,   364,   270,
     371,   266,     6,    -1,   155,   116,   261,   354,   262,     7,
     265,   364,   270,   364,   270,   371,   266,     6,    -1,   155,
     117,   261,   354,   262,     7,   265,   364,   270,   364,   270,
     371,   266,     6,    -1,   155,     4,   261,   354,   262,     7,
     367,     6,    -1,   155,     4,   261,   354,   262,     7,     5,
       6,    -1,   155,     4,   265,   354,   266,     6,    -1,   166,
     265,   325,   266,    -1,   148,   166,   265,   325,   266,    -1,
     166,     4,   265,   325,   266,    -1,   166,   205,   263,   354,
     264,     6,    -1,   166,     4,   263,   354,   264,     6,    -1,
     166,   385,     6,    -1,   166,     4,     4,     6,    -1,   166,
      95,     6,    -1,   194,   372,   265,   325,   266,    -1,   148,
     194,   372,   265,   325,   266,    -1,   230,   354,   265,   325,
     266,    -1,   210,   265,     8,   266,    -1,   210,     5,     6,
      -1,   211,   265,     8,   266,    -1,   211,     5,     6,    -1,
     210,   265,   325,   266,    -1,   148,   210,   265,   325,   266,
      -1,   211,   265,   325,   266,    -1,   148,   211,   265,   325,
     266,    -1,   385,   376,     6,    -1,    81,   261,   382,   262,
       6,    -1,   385,   385,   263,   354,   264,   375,     6,    -1,
     385,   385,   385,   263,   354,   264,     6,    -1,   385,   354,
       6,    -1,   233,     6,    -1,   146,   261,     4,   262,   267,
       4,     6,    -1,   188,     4,     6,    -1,   203,     6,    -1,
     203,   354,     6,    -1,   204,     6,    -1,    75,     6,    -1,
      76,     6,    -1,    68,     6,    -1,    68,   265,   354,   270,
     354,   270,   354,   270,   354,   270,   354,   270,   354,   266,
       6,    -1,    69,     6,    -1,    70,     6,    -1,    86,   265,
     354,   270,   354,   266,     6,    -1,    86,     6,    -1,    88,
     265,   354,   270,   354,   270,   354,   266,     6,    -1,    88,
     265,   354,   270,   354,   270,   354,   270,   354,   266,     6,
      -1,    87,     6,    -1,    87,   265,   325,   266,    -1,    89,
       6,    -1,    90,     6,    -1,   127,     6,    -1,   128,     6,
      -1,   129,   265,   371,   266,   265,   371,   266,   265,   366,
     266,   265,   354,   270,   354,   266,     6,    -1,   130,   265,
     371,   266,     6,    -1,   130,   265,   371,   266,   265,   324,
     266,     6,    -1,   208,   261,   265,   371,   266,   270,   376,
     270,   376,   262,     6,    -1,   196,   261,   354,     8,   354,
     262,    -1,   196,   261,   354,     8,   354,     8,   354,   262,
      -1,   196,     4,   197,   265,   354,     8,   354,   266,    -1,
     196,     4,   197,   265,   354,     8,   354,     8,   354,   266,
      -1,   198,    -1,   209,     4,    -1,   209,   376,    -1,   206,
      -1,   207,   385,     6,    -1,   207,   376,     6,    -1,   199,
     261,   354,   262,    -1,   200,   261,   354,   262,    -1,   201,
      -1,   202,    -1,   154,   364,   265,   325,   266,    -1,   154,
     265,   364,   270,   364,   270,   354,   266,   265,   325,   266,
      -1,   154,   265,   364,   270,   364,   270,   364,   270,   354,
     266,   265,   325,   266,    -1,    -1,   154,   364,   265,   325,
     335,   339,   266,    -1,    -1,   154,   265,   364,   270,   364,
     270,   354,   266,   265,   325,   336,   339,   266,    -1,    -1,
     154,   265,   364,   270,   364,   270,   364,   270,   354,   266,
     265,   325,   337,   339,   266,    -1,    -1,   154,   265,   325,
     338,   339,   266,    -1,   154,   265,   325,   266,   145,   121,
     265,   354,   266,    -1,   134,   367,    -1,   139,   134,   367,
      -1,   136,   265,   371,   266,   265,   371,   266,   265,   371,
     266,    -1,   137,   265,   371,   266,   265,   371,   266,   265,
     371,   266,   265,   371,   266,    -1,   340,    -1,   339,   340,
      -1,   174,   265,   354,   266,     6,    -1,   174,   265,   367,
     270,   367,   266,     6,    -1,   175,     6,    -1,   163,     6,
      -1,   163,   354,     6,    -1,   180,     6,    -1,   180,   182,
       6,    -1,   181,     6,    -1,   181,   182,     6,    -1,   176,
     261,   354,   262,     7,   367,   145,   354,     6,    -1,   145,
       4,   263,   354,   264,     6,    -1,   157,    -1,   158,    -1,
     159,    -1,   160,    -1,   161,    -1,    -1,   166,     6,    -1,
     148,   166,     6,    -1,   166,   354,     6,    -1,   148,   166,
     354,     6,    -1,   341,   265,   325,   342,   266,   265,   325,
     342,   266,    -1,   118,   261,   375,   262,    -1,   341,   261,
     354,   262,     7,   265,   325,   342,   266,   265,   325,   342,
     266,     6,    -1,    -1,   145,     4,   354,    -1,    -1,     4,
      -1,    -1,     7,   367,    -1,    -1,     7,   354,    -1,    -1,
     156,   367,    -1,   172,   369,     7,   354,     6,    -1,   123,
     124,   369,     7,   354,     6,    -1,   140,   106,   369,     7,
     354,   345,     6,    -1,   140,   109,   369,   347,   346,     6,
      -1,   140,   111,   369,   347,     6,    -1,   183,   369,     6,
      -1,   101,   319,   261,   354,   270,   354,   262,     6,    -1,
     218,   319,   261,   354,   262,     6,    -1,   170,   109,   265,
     371,   266,     7,   354,     6,    -1,   173,   109,   265,   371,
     266,     7,   354,     6,    -1,   163,   109,   369,   348,     6,
      -1,   163,   111,   369,     6,    -1,   164,   109,   369,     7,
     354,     6,    -1,   143,   106,   265,   371,   266,     7,   265,
     371,   266,   349,     6,    -1,   143,   109,   265,   371,   266,
       7,   265,   371,   266,   349,     6,    -1,   143,   106,   265,
     371,   266,     7,   265,   371,   266,   150,   265,   364,   270,
     364,   270,   354,   266,     6,    -1,   143,   109,   265,   371,
     266,     7,   265,   371,   266,   150,   265,   364,   270,   364,
     270,   354,   266,     6,    -1,   143,   106,   265,   371,   266,
       7,   265,   371,   266,   151,   364,     6,    -1,   143,   109,
     265,   371,   266,     7,   265,   371,   266,   151,   364,     6,
      -1,   143,   109,   354,   265,   371,   266,     7,   354,   265,
     371,   266,     6,    -1,   319,   265,   371,   266,   197,   319,
     265,   354,   266,     6,    -1,   171,   321,   369,     6,    -1,
     131,   322,   369,     6,    -1,   132,   111,   367,     6,    -1,
     147,   106,   367,     6,    -1,   142,   320,   367,     6,    -1,
     142,   320,   367,   170,   354,     6,    -1,   167,     6,    -1,
     167,     4,     6,    -1,   167,   103,   265,   371,   266,     6,
      -1,   168,     6,    -1,   219,    -1,   220,    -1,   221,    -1,
     352,     6,    -1,   352,   265,   367,   266,     6,    -1,   352,
     265,   367,   270,   367,   266,     6,    -1,   352,   261,   367,
     262,   265,   367,   270,   367,   266,     6,    -1,   355,    -1,
     261,   354,   262,    -1,   250,   354,    -1,   249,   354,    -1,
     256,   354,    -1,   354,   250,   354,    -1,   354,   249,   354,
      -1,   354,   251,   354,    -1,   354,   252,   354,    -1,   354,
     254,   354,    -1,   354,   255,   354,    -1,   354,   253,   354,
      -1,   354,   260,   354,    -1,   354,   243,   354,    -1,   354,
     244,   354,    -1,   354,   248,   354,    -1,   354,   247,   354,
      -1,   354,   242,   354,    -1,   354,   241,   354,    -1,   354,
     240,   354,    -1,   354,   239,   354,    -1,   354,   245,   354,
      -1,   354,   246,   354,    -1,   354,   238,   354,     8,   354,
      -1,    26,   295,   354,   296,    -1,    16,   295,   354,   296,
      -1,    17,   295,   354,   296,    -1,    18,   295,   354,   296,
      -1,    19,   295,   354,   296,    -1,    20,   295,   354,   296,
      -1,    21,   295,   354,   296,    -1,    22,   295,   354,   296,
      -1,    23,   295,   354,   296,    -1,    24,   295,   354,   296,
      -1,    27,   295,   354,   296,    -1,    28,   295,   354,   270,
     354,   296,    -1,    29,   295,   354,   296,    -1,    30,   295,
     354,   296,    -1,    31,   295,   354,   296,    -1,    32,   295,
     354,   296,    -1,    33,   295,   354,   296,    -1,    34,   295,
     354,   296,    -1,    35,   295,   354,   296,    -1,    36,   295,
     354,   296,    -1,    39,   295,   354,   270,   354,   296,    -1,
      40,   295,   354,   270,   354,   296,    -1,    41,   295,   354,
     270,   354,   296,    -1,    25,   295,   354,   296,    -1,    38,
     295,   354,   270,   354,   296,    -1,    37,   295,   354,   270,
     354,   296,    -1,     3,    -1,    10,    -1,    15,    -1,    11,
      -1,    12,    -1,   226,    -1,   227,    -1,   228,    -1,    83,
      -1,    84,    -1,    85,    -1,    -1,    94,   295,   354,   356,
     306,   296,    -1,   359,    -1,   216,   295,   375,   296,    -1,
     216,   295,   375,   270,   354,   296,    -1,   361,    -1,   385,
     263,   354,   264,    -1,   385,   261,   354,   262,    -1,   222,
     261,   361,   262,    -1,   222,   261,   361,   267,   297,   262,
      -1,   224,   261,   361,   357,   262,    -1,   224,   261,   361,
     267,   297,   357,   262,    -1,   224,   261,   361,   295,   354,
     296,   357,   262,    -1,   224,   261,   361,   267,   297,   295,
     354,   296,   357,   262,    -1,   223,   261,   376,   262,    -1,
     268,   385,   295,   296,    -1,   268,   361,   267,   297,   295,
     296,    -1,    97,   295,   385,   296,    -1,    97,   295,   296,
      -1,   385,   294,    -1,   385,   263,   354,   264,   294,    -1,
     385,   261,   354,   262,   294,    -1,   385,   267,   297,    -1,
     385,     9,   385,   267,   297,    -1,   385,   267,   297,   261,
     354,   262,    -1,   385,     9,   385,   267,   297,   261,   354,
     262,    -1,   385,   267,   297,   263,   354,   264,    -1,   385,
       9,   385,   267,   297,   263,   354,   264,    -1,   385,   263,
     354,   264,   267,   297,    -1,   385,   267,   297,   294,    -1,
     385,   263,   354,   264,   267,   297,   294,    -1,   212,   261,
     375,   270,   354,   262,    -1,    60,   261,   367,   270,   367,
     262,    -1,    61,   295,   375,   270,   375,   296,    -1,    59,
     295,   375,   296,    -1,    62,   295,   375,   270,   375,   296,
      -1,    67,   261,   382,   262,    -1,    -1,   270,   354,    -1,
      -1,   270,   375,    -1,    -1,    95,   361,   363,   360,   263,
     307,   264,    -1,   385,    -1,   385,     9,   385,    -1,    98,
      -1,    98,   354,    -1,    -1,   261,   362,   262,    -1,   365,
      -1,   250,   364,    -1,   249,   364,    -1,   364,   250,   364,
      -1,   364,   249,   364,    -1,   265,   354,   270,   354,   270,
     354,   270,   354,   270,   354,   266,    -1,   265,   354,   270,
     354,   270,   354,   270,   354,   266,    -1,   265,   354,   270,
     354,   270,   354,   266,    -1,   261,   354,   270,   354,   270,
     354,   262,    -1,   367,    -1,   366,   270,   367,    -1,   354,
      -1,   370,    -1,   265,   266,    -1,   265,   371,   266,    -1,
     250,   265,   371,   266,    -1,   354,   251,   265,   371,   266,
      -1,   265,   266,    -1,   265,   371,   266,    -1,   250,   265,
     371,   266,    -1,   367,    -1,   265,     8,   266,    -1,     5,
      -1,   250,   370,    -1,   354,   251,   370,    -1,   354,     8,
     354,    -1,   354,     8,   354,     8,   354,    -1,   103,   265,
     354,   266,    -1,   103,   265,     8,   266,    -1,   103,     5,
      -1,   320,   265,     8,   266,    -1,   320,     5,    -1,   141,
     319,   369,    -1,   144,   319,   367,    -1,   319,   197,    68,
     367,    -1,    68,   319,   265,   371,   266,    -1,    77,   320,
     265,   354,   266,    -1,    78,   320,   265,   354,   266,    -1,
      79,   320,   265,   354,   266,    -1,   194,   320,   265,   354,
     266,    -1,   323,    -1,   334,    -1,   343,    -1,   385,   295,
     296,    -1,   385,   267,   297,   295,   296,    -1,   385,     9,
     385,   267,   297,   295,   296,    -1,    42,   263,   385,   264,
      -1,    42,   263,   370,   264,    -1,    42,   261,   370,   262,
      -1,    42,   295,   265,   371,   266,   296,    -1,   385,   295,
     265,   371,   266,   296,    -1,    43,   295,   354,   270,   354,
     270,   354,   296,    -1,    44,   295,   354,   270,   354,   270,
     354,   296,    -1,    45,   295,   375,   296,    -1,    46,   295,
     354,   270,   354,   270,   354,   270,   354,   270,   354,   270,
     354,   296,    -1,   217,   295,   370,   296,    -1,    33,   295,
     370,   296,    -1,   354,    -1,   370,    -1,   371,   270,   354,
      -1,   371,   270,   370,    -1,   265,   354,   270,   354,   270,
     354,   270,   354,   266,    -1,   265,   354,   270,   354,   270,
     354,   266,    -1,   385,    -1,     4,   267,   194,   267,     4,
      -1,   265,   374,   266,    -1,   385,   263,   354,   264,   267,
     195,    -1,   372,    -1,   374,   270,   372,    -1,   376,    -1,
     385,    -1,   385,   263,   354,   264,    -1,   385,   261,   354,
     262,    -1,   385,   267,   297,    -1,   385,     9,   385,   267,
     297,    -1,   385,   267,   297,   261,   354,   262,    -1,   385,
       9,   385,   267,   297,   261,   354,   262,    -1,   385,   263,
     354,   264,   267,     4,    -1,   319,   265,   354,   266,    -1,
     141,   319,   265,   354,   266,    -1,     5,    -1,   231,   263,
     385,   264,    -1,    71,    -1,   229,    -1,    80,    -1,    82,
      -1,   214,   261,   375,   262,    -1,   213,   261,   375,   270,
     375,   262,    -1,   215,   295,   375,   296,    -1,   215,   295,
     375,   270,   375,   296,    -1,   225,   261,   361,   358,   262,
      -1,   225,   261,   361,   267,   297,   358,   262,    -1,    52,
     295,   382,   296,    -1,    53,   261,   375,   262,    -1,    54,
     261,   375,   262,    -1,    55,   261,   375,   270,   375,   270,
     375,   262,    -1,    50,   295,   382,   296,    -1,    64,   295,
     375,   296,    -1,    65,   295,   375,   296,    -1,    66,   295,
     375,   296,    -1,    63,   295,   354,   270,   375,   270,   375,
     296,    -1,    58,   295,   375,   270,   354,   270,   354,   296,
      -1,    58,   295,   375,   270,   354,   296,    -1,    51,   295,
     375,   296,    -1,    51,   295,   375,   270,   371,   296,    -1,
      72,   295,   375,   296,    -1,    73,    -1,    74,    -1,    57,
     295,   375,   296,    -1,    56,   295,   375,   296,    -1,    -1,
      99,   295,   376,   377,   310,   296,    -1,    96,   295,   378,
     296,    -1,   268,   354,    -1,   385,     9,   268,   354,    -1,
      50,   295,   381,   296,    -1,   382,    -1,   381,    -1,   265,
     382,   266,    -1,   375,    -1,   383,    -1,   382,   270,   375,
      -1,   382,   270,   383,    -1,   385,   261,   262,    -1,   385,
     267,   297,   261,   262,    -1,   385,     9,   385,   267,   297,
     261,   262,    -1,     4,   269,   265,   354,   266,    -1,   384,
     269,   265,   354,   266,    -1,   232,   263,   375,   264,   269,
     265,   354,   266,    -1,     4,    -1,   384,    -1,   232,   263,
     375,   264,    -1
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
    5967,  5978,  5984,  5998,  6004,  6016,  6030,  6043,  6060,  6070,
    6080,  6090,  6102,  6106,  6111,  6123,  6127,  6131,  6135,  6153,
    6161,  6169,  6198,  6208,  6224,  6235,  6240,  6244,  6248,  6260,
    6264,  6276,  6293,  6303,  6307,  6322,  6327,  6334,  6338,  6343,
    6357,  6371,  6375,  6379,  6383,  6387,  6395,  6401,  6410,  6414,
    6418,  6426,  6432,  6438,  6442,  6449,  6457,  6464,  6473,  6477,
    6481,  6496,  6510,  6524,  6536,  6552,  6561,  6570,  6580,  6591,
    6599,  6607,  6611,  6629,  6636,  6642,  6648,  6655,  6663,  6662,
    6672,  6696,  6698,  6704,  6709,  6711,  6716,  6721,  6726,  6728,
    6732,  6744,  6758,  6762,  6769,  6777,  6785,  6796,  6798,  6801
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
  "tWire", "tGeoEntity", "tCharacteristic", "tLength", "tParametric",
  "tElliptic", "tRefineMesh", "tRecombineMesh", "tAdaptMesh",
  "tTransformMesh", "tRelocateMesh", "tReorientMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tParent",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tSewing", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
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
     485,   486,   487,   488,   489,   490,   491,   492,    63,   493,
     494,   495,   496,    60,    62,   497,   498,   499,   500,    43,
      45,    42,    47,    37,   124,    38,    33,   501,   502,   503,
      94,    40,    41,    91,    93,   123,   125,    46,    35,   126,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   271,   272,   272,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   275,   275,   276,   276,
     276,   276,   276,   276,   276,   276,   277,   277,   277,   277,
     278,   278,   278,   278,   278,   278,   278,   279,   279,   280,
     280,   282,   283,   281,   284,   284,   286,   285,   287,   287,
     289,   288,   290,   290,   292,   291,   293,   293,   293,   293,
     293,   294,   294,   295,   295,   296,   296,   297,   297,   297,
     297,   297,   297,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   299,   299,
     300,   300,   300,   301,   300,   302,   300,   300,   303,   300,
     304,   304,   305,   305,   305,   306,   306,   307,   307,   308,
     308,   309,   309,   309,   309,   309,   309,   309,   309,   310,
     310,   311,   311,   312,   312,   312,   312,   312,   313,   313,
     313,   314,   314,   314,   314,   315,   315,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   318,   317,   319,   319,   319,
     319,   319,   320,   320,   320,   320,   321,   321,   321,   322,
     322,   322,   322,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   327,   327,   327,   327,   327,   327,
     327,   327,   328,   328,   329,   330,   330,   330,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   332,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   334,   334,
     334,   335,   334,   336,   334,   337,   334,   338,   334,   334,
     334,   334,   334,   334,   339,   339,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   341,   341,   341,
     341,   341,   342,   342,   342,   342,   342,   343,   343,   344,
     345,   345,   346,   346,   347,   347,   348,   348,   349,   349,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   351,   351,   351,
     351,   352,   352,   352,   353,   353,   353,   353,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   356,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   357,   357,   358,   358,
     360,   359,   361,   361,   362,   362,   363,   363,   364,   364,
     364,   364,   364,   365,   365,   365,   365,   366,   366,   367,
     367,   367,   367,   367,   367,   368,   368,   368,   369,   369,
     369,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   371,   371,   371,   371,   372,
     372,   372,   372,   373,   373,   374,   374,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   376,   377,   376,
     376,   378,   378,   379,   380,   380,   381,   382,   382,   382,
     382,   383,   383,   383,   384,   384,   384,   385,   385,   385
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
       3,     3,     4,     5,     5,     5,     5,     5,     1,     1,
       1,     3,     5,     7,     4,     4,     4,     6,     6,     8,
       8,     4,    14,     4,     4,     1,     1,     3,     3,     9,
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
       0,     0,     0,     2,     3,     1,   647,     0,     0,     0,
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
       0,    17,    18,    19,    20,     0,    25,     0,   648,     0,
     235,     0,     0,     0,     0,     0,     0,   286,     0,   288,
     289,   284,   285,     0,   291,     0,   294,   235,     0,   296,
     297,   120,   130,   647,   516,   512,    73,    74,     0,   207,
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
       0,     0,     0,     0,   463,   464,   465,     0,     0,     0,
       0,     0,     0,     0,     0,   558,   559,     0,   560,   529,
     408,   471,   474,   330,   530,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   212,   213,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   647,     0,     0,   235,
       0,     0,   397,     0,   400,     0,     0,   216,   217,     0,
       0,   540,     0,     0,   538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   647,     0,     0,
     581,     0,     0,     0,     0,   281,     0,     0,     0,   512,
     283,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   600,     0,   624,   625,
     602,   603,     0,     0,     0,     0,     0,     0,   601,     0,
       0,     0,     0,   309,   310,     0,   235,     0,   235,     0,
       0,     0,   278,     0,     0,   235,   404,     0,     0,    85,
       0,    66,     0,     0,    70,    69,    68,    67,    72,    71,
      73,    74,     0,     0,     0,     0,     0,     0,     0,   587,
     512,     0,   234,     0,   233,     0,   186,     0,     0,   587,
     588,     0,     0,     0,   637,     0,   638,   588,     0,     0,
       0,   118,   118,     0,   510,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   575,   576,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   547,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,   410,
     541,   412,     0,   531,     0,     0,   512,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,   488,     0,     0,     0,     0,     0,
       0,     0,   331,     0,   364,   364,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,     0,   235,
     235,     0,   520,   519,     0,     0,     0,     0,   235,   235,
       0,     0,     0,     0,   327,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   366,     0,
       0,     0,     0,     0,     0,   235,   261,     0,     0,   259,
     398,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   375,   280,     0,     0,     0,     0,     0,
       0,     0,   235,     0,     0,     0,     0,     0,   410,   282,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   313,   312,     0,
     266,     0,     0,   268,     0,     0,     0,   235,     0,     0,
       0,   352,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    80,    78,    79,    81,    82,     0,     0,     0,     0,
      89,    75,    76,     0,     0,     0,   277,    40,   273,     0,
       0,     0,     0,     0,   229,     0,     0,     0,     0,     0,
     236,     0,     0,   187,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,   119,     0,     0,     0,   514,     0,
       0,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,     0,     0,   211,     0,     0,     0,     0,     0,
       0,     0,   392,   393,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,   487,     0,     0,     0,     0,   550,   551,     0,     0,
       0,     0,     0,     0,   506,     0,   409,   532,     0,     0,
       0,     0,   543,     0,   428,   427,   426,   425,   421,   422,
     429,   430,   424,   423,   414,   413,     0,   415,   542,   416,
     419,   417,   418,   420,   513,     0,     0,   491,     0,   561,
       0,     0,     0,     0,     0,     0,     0,     0,   362,     0,
       0,     0,     0,     0,     0,   395,     0,     0,     0,     0,
       0,   394,     0,   235,     0,     0,     0,     0,     0,   522,
     521,     0,     0,     0,     0,     0,     0,     0,   321,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,     0,     0,     0,   260,     0,     0,     0,
     254,     0,     0,     0,     0,   391,   409,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   314,   315,     0,   415,   513,   491,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   628,     0,     0,
       0,   508,     0,     0,   265,   269,   267,   271,     0,     0,
     649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,   409,     0,     0,     0,    66,     0,     0,
      88,     0,    66,    67,     0,     0,     0,   513,     0,     0,
     491,     0,     0,     0,   205,     0,     0,     0,   644,    28,
      26,    27,     0,     0,     0,     0,     0,   591,    30,     0,
      29,     0,     0,   274,   639,   640,     0,   641,   591,     0,
       0,    83,   121,    84,   131,   515,   517,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,   578,   301,   235,   222,     9,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   455,   432,   442,
       0,   444,   445,   446,   447,   448,   574,   449,   450,   451,
       0,     0,     0,     0,     0,   566,   565,   564,     0,     0,
       0,   571,     0,   503,     0,     0,     0,   505,     0,     0,
       0,     0,   135,   486,   546,   545,   215,     0,     0,     0,
     472,   573,   477,     0,   483,     0,     0,     0,     0,   533,
       0,     0,   484,   552,   548,     0,     0,     0,     0,   476,
     475,    73,    74,   498,     0,     0,     0,     0,     0,     0,
       0,   409,   360,   365,   363,     0,   374,     0,   158,   159,
       0,   215,     0,   409,     0,     0,     0,     0,     0,   255,
       0,   270,   272,     0,     0,     0,   223,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   334,
       0,   318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,     0,   367,   380,     0,     0,     0,     0,
     256,     0,     0,     0,     0,   218,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,   614,     0,   621,   610,
     611,   612,     0,   627,   626,     0,     0,   615,   616,   617,
     623,   631,   630,     0,   149,     0,   604,     0,   606,     0,
       0,     0,   599,     0,     0,   264,     0,     0,     0,     0,
     353,     0,     0,     0,   405,     0,   645,     0,   110,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,   596,    51,     0,     0,
       0,    64,     0,    41,    42,    43,    44,    45,    46,     0,
     476,   475,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   590,   589,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,   138,   139,     0,     0,     0,     0,   165,   165,     0,
       0,     0,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   371,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   553,   554,   555,   556,     0,     0,   557,     0,     0,
       0,   506,   507,     0,   479,     0,     0,   544,   431,   534,
     492,   490,     0,   489,     0,     0,   562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   373,     0,     0,     0,
       0,     0,   396,     0,     0,     0,    77,     0,   263,     0,
       0,     0,     0,     0,     0,     0,   339,     0,     0,   338,
       0,   341,     0,   343,     0,   328,   335,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,     0,     0,   258,   257,   399,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,   582,     0,     0,
       0,   304,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   508,   509,   608,     0,   377,     0,
       0,   235,   354,     0,   355,   235,     0,     0,   597,     0,
      95,     0,     0,     0,     0,    93,     0,   585,     0,   108,
       0,   100,   102,     0,     0,     0,    90,     0,     0,     0,
       0,     0,    36,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   592,
       0,     0,    34,    33,     0,   592,   642,   290,     0,     0,
     122,   127,     0,     0,     0,   141,   147,   148,   144,   142,
     143,   511,     0,    86,     0,    87,   169,     0,     0,     0,
       0,   170,   189,   190,   167,     0,     0,     0,   171,   200,
     191,   195,   196,   192,   193,   194,   179,     0,     0,     0,
     443,   457,   456,   452,   453,   454,   567,     0,     0,     0,
     501,   502,   504,   136,   470,   500,   473,   478,     0,     0,
     506,   201,   485,    73,    74,     0,   497,   493,   495,   568,
     197,     0,     0,     0,   161,     0,     0,   372,     0,   160,
       0,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,   235,   235,     0,     0,   340,   529,     0,     0,   342,
     344,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   198,     0,     0,     0,     0,
       0,     0,     0,   176,     0,   177,     0,     0,     0,     0,
       0,     0,   111,   115,     0,   622,     0,     0,   620,     0,
     632,     0,     0,   150,   151,   629,   605,   607,     0,     0,
       0,     0,   352,   356,   352,     0,   406,    94,     0,     0,
      66,     0,     0,    92,     0,   583,     0,     0,     0,     0,
       0,     0,   635,   634,     0,     0,     0,     0,     0,   527,
       0,     0,    77,   275,   493,   276,     0,     0,     0,     0,
       0,   240,   237,     0,     0,   595,   593,     0,     0,     0,
       0,   123,   128,     0,     0,     0,   575,   576,   140,   376,
     166,   174,   175,   180,     0,     0,     0,     0,     0,   182,
       0,     0,   302,     0,     0,     0,     0,   480,     0,     0,
       0,   563,   499,     0,     0,   181,     0,   202,   361,     0,
       0,     0,     0,   203,     0,     0,     0,     0,     0,     0,
     526,   525,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   251,     0,     0,     0,     0,     0,     0,
       0,     0,   242,     0,     0,     0,   378,   379,    39,   184,
     185,     0,   580,     0,     0,   306,   305,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   157,   156,   155,
       0,   609,     0,   646,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   106,   586,     0,     0,     0,    97,     0,
       0,     0,    47,     0,     0,     0,     0,     0,    49,     0,
     241,   238,   239,    35,     0,     0,   643,   292,     0,   135,
     149,     0,     0,   146,     0,     0,     0,   168,   199,     0,
       0,     0,     0,     0,   569,   570,     0,   506,   481,   494,
     496,     0,     0,   183,   206,     0,     0,     0,   368,   368,
       0,   116,   117,   235,     0,   226,   227,   329,     0,   336,
       0,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,   230,     0,     0,     0,     0,   535,     0,
     112,   114,   113,   613,   619,   618,   152,     0,     0,     0,
     357,     0,     0,   109,   101,   103,     0,    91,   636,    98,
      99,    52,     0,     0,     0,     0,   528,     0,     0,   494,
     594,     0,     0,     0,     0,   125,   633,     0,   132,     0,
       0,     0,     0,   188,     0,     0,     0,   332,     0,   172,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,   346,     0,     0,   323,     0,   243,     0,
       0,     0,     0,     0,     0,   231,     0,   579,   307,     0,
     536,     0,   390,   235,   407,     0,   584,     0,    48,     0,
       0,     0,    65,    50,     0,   293,   124,   129,   135,     0,
       0,   163,   164,   162,     0,     0,   482,     0,     0,     0,
       0,   369,   383,     0,     0,   384,     0,   224,     0,   337,
       0,   319,     0,   235,     0,     0,     0,     0,     0,     0,
     178,   537,   303,   352,   107,     0,     0,     0,     0,     0,
       0,   133,   134,     0,     0,     0,   204,     0,   387,     0,
     388,   389,   523,     0,     0,   325,   246,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,    62,     0,     0,
     126,     0,     0,   333,     0,     0,   345,   324,   320,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
     250,     0,   244,   359,    53,     0,    60,     0,   287,     0,
     572,     0,     0,   326,     0,     0,    54,     0,     0,   300,
       0,     0,   245,     0,     0,     0,     0,     0,     0,    57,
      55,     0,    58,     0,   385,   386,     0,     0,    63,    61,
      59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   124,  1122,   125,   126,  1106,  1991,  1997,
    1413,  1637,  2157,  2285,  1414,  2258,  2301,  1415,  2287,  1416,
    1417,  1641,   463,   624,   625,  1195,  1736,   127,   825,   491,
    2009,  2168,  2010,   492,  1875,  1496,  1450,  1451,  1452,  1601,
    1813,  1814,  1267,  1697,  1688,  1885,   800,   636,   293,   294,
     370,   215,   295,   473,   474,   131,   132,   133,   134,   135,
     136,   137,   138,   296,  1302,  2192,  2249,   996,  1298,  1299,
     297,  1085,   298,   142,  1525,  1265,   968,  1011,  2125,   143,
     144,   145,   146,   299,   300,  1222,  1238,  1371,   301,   830,
     302,   829,   494,   653,   337,  1848,   374,  1960,   375,   304,
     594,   389,  1397,  1628,   484,   479,  1364,  1065,  1677,  1841,
    1842,  1050,   486,   148,   399
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1965
static const yytype_int16 yypact[] =
{
   13848,    93,   124, 14057, -1965, -1965,  -157,   101,    38,  -103,
     -80,   -38,    31,   233,   248,   271,   277,    65,    42,    48,
      66,   315,   336,    85,   106,    27,     0,   650,     0,    92,
     125,   149,    17,   175,   190,    40,   197,   208,   237,   244,
     266,   276,   288,   323,   357,   360,   341,   506,   574,   688,
     749,   432,   495,   406,   652,   514,  7551,   521,   500,   525,
     682,   -45,    68,   650,   -25,   116,   543,   703,  -119,   547,
     -29,   -29,   550,   370,    54,   572, -1965, -1965, -1965, -1965,
   -1965,   570,   253,   740,   756,    19,    45,   849,   766,   751,
      60,  6515,   792,   873,   922,   928,  6515,   936,   -83,   -81,
     699,    11,    56, -1965,   704,   707, -1965, -1965, 11356,   939,
     711, -1965, 14308,   736,  3986,     9,    22,   650, -1965, -1965,
   -1965, 13249,   735,   945, -1965, -1965, -1965, -1965, -1965,   774,
   -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965,
     115, -1965, -1965, -1965, -1965,    51, -1965,  1021,   771,  6249,
      34,   823,  1025, 13249, 14245, 14245, 14245, -1965, 13249, -1965,
   -1965, -1965, -1965, 14245, -1965, 13249, -1965, -1965, 13249, -1965,
   -1965, -1965, -1965,   810,   836,  1080, -1965, -1965, 14345, -1965,
   -1965, -1965, -1965,   875, 14345, 13249, 13249, 13249,   883, 13249,
   13249, 13249,   885, 13249, 13249, 13249, 13249, 13249, 13249, 13249,
   14245, 13249, 13249, 13249, 13249,  6515,   886, -1965, -1965, 10649,
   10649, -1965, -1965, -1965,   861,  6515,  7810, 14245, -1965, -1965,
   -1965, -1965, -1965,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,   887,     0,     0,   890,   650,
     138,   138,   138, -1965, -1965, -1965,     0,     0,    35,   913,
     937,   942,   901,  7810,  1033,   650,   650,   138,   894,     0,
       0,   908,   909,   911, -1965, -1965, -1965, 13249,  8069, 13249,
   13249,  8328,    27,   976,    37, -1965, -1965,   910, -1965,   739,
   -1965, -1965, -1965, -1965, -1965,   114, 13249, 10649, 10649,   915,
     916,  8587,  6515,  6515,  6515, -1965, -1965, -1965,   919, -1965,
     920,   923,  8846,   921, 11514,  1170,  7810,   924,    11,   925,
     926,   -29,   -29,   -29, 13249, 13249,  -131, -1965,   174,   -29,
   11610,   285,   265,   927,   931,   932,   953,   956,   957,   958,
   10649, 13249,  6515,  6515,  6515,   304,     6,  1175,   959, -1965,
    1181,  1214, -1965,   960, -1965,   961,   962, -1965, -1965,   963,
    6515, -1965, 13249,  6774, -1965,  1216,   964,   967,   969,   970,
    1215,  1218,   973, 13249,   974, 13249, 13249,   131, 13249,   971,
   -1965,  1041, 13249, 13249, 13249, -1965,     0, 13249,   462,   129,
   -1965, 13249, -1965,     0,     0,     0,   978,   979,   980,     0,
       0,     0,     0,     0,     0,     0, -1965,     0, -1965, -1965,
   -1965, -1965,     0,     0,   981,   982,     0,   983, -1965,   984,
    1239,  1240,   985, -1965, -1965,  1242,  1241,  1245,  1244,   995,
   15884, 14245, -1965, 10649, 13249, -1965, -1965,  7810,  7810, -1965,
     992, 14345,   650,  1251, -1965, -1965, -1965, -1965, -1965, -1965,
   13249, 13249,   433,  7810,  1253,   840,   996,  1459,   997,  1254,
      32,   998, -1965,   999, 14577, 13249, -1965,  1608,  -167, -1965,
      57,  -135,   -79,  6965, -1965,   224, -1965,   150,  7224,  5190,
    7483,  -203,  -108,  1166, -1965,    27,  1000, 13249,  1001, 16373,
   16398, 16423, 13249, 16448, 16473, 16498, 13249, 16523, 16548, 16573,
   16598, 16623, 16648, 16673,  1006, 16698, 16723, 16748, 14898,  1262,
   13249, 10649,  3606, -1965,   302,   504, 13249,  1266,  1267,  1013,
   13249, 13249, 13249, 13249, 13249, 13249, 13249, 13249, 13249, 13249,
   13249, 13249, 13249, 13249, 13249, 13249, 13249, 10649, 13249, 13249,
   13249, 13249, 13249, 13249, 13249, 13249, 10649, 10649,  1011, 13249,
   13249, 14245, 13249, 14245,  7810, 14245, 14245, 14245,  1012,  1016,
    1018,  1019, 13249,    30, -1965, 11869, 13249,  7810,  6515,  7810,
    1020, 14245, 14245, 10649,    27, 14345,    27,  1026, 10649,  1026,
   -1965,  1026, 16773, -1965,   515,  1023,    91,  1220, -1965,  1283,
   13249, 13249, 13249, 13249, 13249, 13249, 13249, 13249, 13249, 13249,
   13249, 13249, 13249, 13249,  9105, 13249, 13249, 13249, 13249, 13249,
      27, 13249, 13249,   503, -1965,   878, 16798,   541,   564, 13249,
   13249, 13249, -1965,  1286,  1287,  1287,  1034, 13249, 13249, 13249,
   13249,    24, 10649, 10649, 15912,  1035,  1290, -1965,  1036, -1965,
   -1965,  -145, -1965, -1965,  7742,  8001,   -29,   -29,    34,    34,
    -139, 11610, 11610, 13249,  5792,  -133, -1965, 13249, 13249, 13249,
   13249, 13249, 13249, 13249, 13249, 13249,   591, 16823,  1291,  1294,
    1295, 13249, 13249,  1298, 13249, -1965, -1965, 13249,  6304, -1965,
   -1965, 10649, 10649, 10649, 13249,  1300, 16848,  1045, 13249, 10649,
   13249, 13249, 13249, -1965, -1965, 13249, 16873, 13249, 16898, 16923,
    1118,  8260, -1965,  1048,  4290, 16948, 16973, 13249,  1026, -1965,
   13249,    27, 13249, 13249,   503, 15968, 14245, 14245, 14245, 14245,
   14245, 14245, 14245, 14245, 14245, 13249, 14245, 14245, 14245, 14245,
       5, 14345, 14245, 14245, 14245,    27,    27, -1965, -1965, 10649,
   -1965,  1049, 11577, -1965,  1051, 11924, 13249, -1965,  1050,   597,
   16998, 14474,  1056,   616, 13249,  1313,  1055,  7810, 17023, 15995,
   -1965, -1965, -1965, -1965, -1965, -1965,  1054,  1315,   168,  1319,
   -1965, -1965, -1965, 10649,   212, 13249, -1965, -1965, -1965,    27,
   13249, 13249,   503,  1063, -1965,  1066,   -40,   650,   -25,   650,
   -1965,  1065, 14927, -1965,    23, 10649,    27, 13249, 13249,   503,
    1322, 10649,  1327, 10649, 13249,  1328, 14245,    27, 11957,   503,
   13249, -1965, 13249,  1329, -1965,    27,  1331, 14245, 13249,  1076,
    1077, -1965, 13249,  8519, 14345,  1332,  1334,  1335, 17048,  1338,
    1339,  1340, 17073,  1341,  1343,  1344,  1345,  1347,  1348,  1349,
   -1965,  1350,  1351,  1352, -1965, 13249, 17098, 10649,  1095, 10649,
      49, 14956, -1965, -1965,  1355,  4846,  4846,  4846,  4846,  4846,
    4846,  4846,  4846,  4846,  4846,  4846,  4846,  8778,  4846,  4846,
    4846,  4846,  1358,   345,  4846,  4846,  4846,  9037,  9296,  9550,
    9804, 10063,  3606,  1101,  1104,    74, 10649, 10322, 10581,   345,
   10934,   345,  1099,  1100,  1102,   238, 10649, 13249, 13249, 13249,
   18048, -1965,   345,  1105, 14985, 15014, -1965, -1965, 13249,  1103,
     210,   345,   -10,  1112,   562,   617,  1368, -1965,   503,   345,
    7810,  1110,  5299,  5350,   955,   761,   813,   813,   546,   546,
     546,   546,   546,   546,   566,   566, 10649,   513, -1965,   513,
     513,  1026,  1026,  1026,  1098, 17123, 16022,   -63, 10649, -1965,
    1370,  1113,  1114, 17148, 17173, 17198, 13249,  7810,  1377,  1376,
   11259, 17223, 15043, 17248, 17273, -1965, 13249,   618,   619, 10649,
    1117, -1965, 12615, -1965, 12957, 13216,   -29, 13249, 13249, -1965,
   -1965,  1119,  1120, 11610,  3060,  1246,   321,   -29, 13278, 17298,
   15072, 17323, 17348, 17373, 17398, 17423, 17448, 17473,  1122,  1382,
   13249,  1384, -1965, 13249, 17498, 15101, -1965, 16049, 13381, 16076,
   -1965,   624,   629,   634, 15130, -1965, -1965, -1965,  2075,   636,
   16103, 16130, 11545, 17523,  1385, 17548,  1387,  1388,  1130, 13249,
   13442, 13249, 13249, -1965, -1965,  4846,   513,  1132,   589,    39,
     249,   362,   249,  1138,  1139,  1133,   345,   345,  1135, 11900,
     345,   345,   345,   345, 13249,   345,  1398, -1965,  1140,  1146,
     374,   104,  1145,   663, -1965, -1965, -1965, -1965, 17573, 13515,
    1142,  1217,  1405,  1247, 12211,  1149,  1151,  1411,  7810, 15159,
   -1965, 13249,  1413,   194,   148,   503,    21, 14345, 13249,  1414,
   -1965,   668,  1371,  1372,  7810, 15188,   159,  1157, 17598, 16157,
     615, 13249, 13249,  1165,  1162,  1167,  1164,  9364, -1965, -1965,
   -1965, -1965, 14245,   407,  1168, 17623, 16184,  1171, -1965,   422,
   -1965,   425, 12166, -1965, -1965, -1965,  1169, -1965,  1172, 15217,
   12242, -1965,    73, -1965, -1965, 18048, -1965,    64,  4846, 13249,
     345,   -29,  7810,  7810,  1427,  7810,  7810,  7810,  1430,  7810,
    7810,  7810,  7810,  7810,  7810,  7810,  7810,  7810,  7810,  2166,
    1431, 10649,  3606, -1965, -1965,    34, -1965, -1965, -1965, -1965,
   -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965,
   13249, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965,
   13249, 13249, 13249, 13249, 13249, -1965, -1965, -1965,   669, 13249,
   13249, -1965, 13249, -1965,  7810, 14245, 14245, -1965,   671, 15246,
   15275, 15304,  1174, -1965, -1965, -1965,  1243, 15333, 13249, 13249,
   -1965, -1965, -1965,   503, -1965,   503, 13249, 13249,  1177, -1965,
    7810,     0, -1965, -1965, -1965, 13249, 13249,   684,   503,  -185,
     183, 13249, 13249, -1965,   345,   691,  7810, 10649, 10649,  1438,
    1439,  1440,  3129, -1965, -1965,  1435, -1965,  1186, 18048,  1179,
    1443, -1965,  1444,  1445,  2193,  1446,  1447,   692,   510, -1965,
   13575, -1965, -1965,  -129, 12591, 12933, -1965, -1965, 15362,  -187,
    1336,  1451, 12306,  1193,  1453,  1200,    26,    33,   505, -1965,
    -121, -1965,   321,  1455,  1457,  1460,  1470,  1476,  1480,  1483,
    1484,  1485,    34,  7810, 18048, -1965,  2359,  1199,  1363,  1487,
   -1965,  1489,  1490,  1389,  1492, -1965, -1965,  1493,  1495,  1496,
   13249,  1497,  7810,  1498,  7810,  7810,  1502, 13630, -1965,  5717,
    1434,   503, 13249, 13249,   503,   503, -1965, 10649, -1965, -1965,
   -1965, -1965, 14245, -1965, -1965, 13249, 14245, -1965, -1965, -1965,
   -1965, 18048, -1965,  1248,  1237, 14245, -1965, 14245, -1965,   503,
   14245,  1249, -1965,  1238,  1504, -1965,  1250,   650,  1252, 12560,
   -1965,  2382,  1256,  7810, -1965,  1257, -1965, 15391, -1965, -1965,
   13249,  1506,   439, 13249,  1507,  1515,    11,  1508,  1261,  1519,
    2510, -1965,   345,     0,     0,  1523, -1965, -1965,  1269,  1270,
    1268, -1965,  1526, -1965, -1965, -1965, -1965, -1965, -1965,   503,
     492,  3353, 13249, 16211, 17648, 13249,  9618, 13249, 10649,  1271,
     697,  1528,   134,   503, -1965,  1273, 13249,  1529,  1530, 13249,
     503, 12648,  1532, 13249,  2446,   345,  5618, 13249, 13249, 13249,
    1278,  1274, -1965,  1537, 17673,  1540,    90,  1409,  1409,  7810,
    1542,  1543,  1544,  7810,  -110,  1545,  1546,  1547,  1548,  1549,
    1551,  1553,  1554,  1555, -1965,  1557,   700,  1297,  4846,  4846,
    4846,  4846,  4846,  4846,   345, 13847, 14254, 14406,  1304,   345,
     345, -1965, -1965, -1965, -1965,    64,   345, -1965, 17698,  4846,
    1305,  -211, 18048,  4846, -1965,  1564,   345, 18048, 18048, -1965,
     230, -1965,   503, -1965, 17723, 16238, -1965,   345,  1565,   705,
     730,  7810,  7810,  7810,  1568,  1567, -1965,   227, 13249,  7810,
    7810,  7810, -1965,  1310,  1311,  1570,  1576,  1577, -1965, 13249,
   13249, 13249,  1318,  1320,  1323,  1324, -1965,  2538,  7810, -1965,
   13249, -1965,  1583, -1965,  1584, -1965, -1965, 11610,   603,  7033,
   -1965,  1326,  1354,  1356,  1359,  1360,  1361,  9872,  1362,  1586,
   -1965, 10649,  1364, -1965, -1965, -1965,  1365, 13249, 13249, -1965,
   -1965, 16265,  7810,  1587,  7810,  1588,  1422, -1965, 13249, 13249,
   13249, -1965,   382,  1610,   475,   412,  1366,  5152,  1369, 13249,
      29,   345,  1373,   345,  1374, -1965, -1965, 14345, -1965, 13249,
    1375, -1965, -1965,  2647, -1965, -1965,  1378,  1611, -1965,  2709,
   -1965,  1367,  1626,   198,  3554, -1965,    11, -1965,   753, -1965,
   13249, -1965, -1965,   227,  3603,  4564, -1965,  1380, 13249, 13249,
    7810,  1381, -1965,   153,   529,  1632, 17748,  1636,  1368, 17773,
    1379,   754, 17798,   759,  1637,  1641, -1965, -1965, 14245,  1390,
    1645, 17823, -1965, -1965, 14502,  1391, -1965, -1965,  5916,  5983,
   18048, -1965,  1643,     0,  8328, -1965, -1965, -1965, 18048, 18048,
   18048, -1965,    64, -1965,  1647, -1965, -1965,   -29,  1648,  1650,
    1651, -1965, -1965, -1965,  1513,    10,  1552,  1654, -1965, -1965,
   -1965, -1965, -1965, -1965, -1965, -1965, -1965,  1656,  1397,  1657,
   -1965, -1965, -1965, -1965, -1965, -1965, -1965, 13249, 13249, 13249,
   -1965, -1965, -1965,  1274, -1965, -1965, -1965, -1965, 13249,  1402,
    1395, -1965, -1965, 13249, 13249,   345,  -185, -1965, -1965, -1965,
   -1965,  1403,  1404,  1661,  -110,  1664, 13249, -1965,  7810, 18048,
    1550,  1571,   715, 10649, 10649, 13249, -1965, 11259, 15420, 17848,
    6134,    34,    34, 13249, 13249, -1965,   348,  1420, 17873, -1965,
   -1965, 15449,  -105, -1965,  1685,  1686,  7810,   -29,   -29,   -29,
     -29,   -29,  7292,  1711, -1965, -1965,   760, 10649, 13249,  3993,
    4513,  1712,  1714, -1965,  1715, -1965,  7810,  6447,   670, 17898,
   13249, 13249, -1965, -1965, 10903, -1965, 14245, 13249, -1965, 14245,
   18048, 11000, 14345,  1452, -1965, -1965, -1965, -1965,  1461,  1462,
   15478, 13249, 14474, -1965, 14474,  7810, -1965, -1965,   503,    21,
   14345, 13249,  1719, -1965,  1723, -1965,    11, 16292,  7810, 14245,
    1724,   345, -1965,  1463,   345, 13249, 14535, 14568,   762, -1965,
   13249, 13249,  1469, -1965,  1471, -1965,  1440,  1729,  1731,  1445,
    1732, -1965, -1965,  1733, 13249, -1965, -1965, 13249, 12902,  1735,
   13249, -1965, -1965,  1478,  4564,   767,  1895,  1737, -1965, -1965,
     594, -1965, -1965, -1965,  1597,  1741,  1488,  1491,  1494, -1965,
    1743,  7810, -1965,  4846,  4846, 14601,  4846, -1965,  1499, 17923,
   16319, -1965, -1965, 10649, 10649, -1965,  1746, -1965, 18048,  1748,
   13249, 13249,  1503, -1965,   768,   775, 15940,  4676,  1751,  1509,
   -1965, -1965, 13249,  1501,  1505, 15507, 16346,  1752,  7810,  1756,
    1510, 13249, -1965, -1965,   776,   -77,   -61,   -39,   -22,   -20,
   10131,    -4, -1965,  1758,   781, 15536, -1965, -1965, -1965, -1965,
   -1965,  1580, -1965, 13249, 13249, -1965, -1965, 12990, 10390,  4703,
    1770,  1771,  1516,  4846,   345, 18048, -1965, -1965, -1965, -1965,
      29, -1965, 14345, -1965, 15565,  1514,  1517,  1521,  1774,  1779,
    1783,  4727, -1965, -1965, -1965,  1524,  1784,   782, -1965,  1786,
    1788,   482, 18048, 13249, 13249,  1531,  7810,   783, 18048, 17948,
   -1965, -1965, -1965, -1965, 17973, 14634, -1965, -1965, 15594,  1174,
    1237,  7810,   345, -1965, 13249, 14345,    27, -1965, -1965, 10649,
   10649, 13249,  1789,   784, -1965, -1965, 13249,  1395, -1965, -1965,
   -1965,   804,   805, -1965, -1965,  4770,  4817,  7810,   677,   689,
   10649, -1965, -1965,    34,  6706, -1965, -1965, -1965,  1791, -1965,
    1533,  7810, -1965, 15623,  1792, 10649,   -29,   -29,   -29,   -29,
     -29, -1965,  1794, -1965, 13249, 15652, 15681, 10649, -1965,   806,
   -1965, -1965, -1965, -1965, -1965, -1965, -1965,  1539,  1796,  1558,
   -1965,  1798,    11, -1965, -1965, -1965,  1612, -1965, -1965, -1965,
   -1965, -1965, 13249, 14667, 14700,  7810, -1965,  1799, 13249,  1559,
   -1965, 13249,  1802,  1561,  1562, -1965, -1965,  4166, -1965,  1556,
     811,   812, 15710, -1965,  1560, 14733,  1569, -1965,  1572, -1965,
   -1965,   814,  1573,   -29,  7810,  1803,  1574,   -29,  1804,   817,
    1563, -1965, 13249, -1965,  1805,  1667, 13638,  1575, -1965,   820,
     205,   229,   240,   272,   289, -1965,  4873, -1965, -1965,   825,
   -1965,  1807, -1965, -1965, -1965,  1808, -1965,  1578, 18048, 13249,
   13249,   828, -1965, 18048, 14766, -1965, -1965, -1965,  1174, 14345,
    1579, -1965, -1965, -1965, 13249, 13249, -1965, 10649,  1809,   -29,
     144, -1965, -1965,   -29,   170, -1965,  1810, -1965, 15739, -1965,
   13249, -1965,   321, -1965,  1812, 10649, 10649, 10649, 10649, 10131,
   -1965, -1965, -1965, 14474, -1965, 13249, 17998, 14799,    50, 13249,
    1566, -1965, -1965, 14832, 14865,   830, -1965,   307, -1965,   355,
   -1965, -1965, -1965,  5001,   613, 13698, -1965,   833,   845,   846,
     847,   397,   852,  1599,   854, -1965, 13249, -1965,  7810, 15768,
   -1965, 13249, 13249, -1965,   -29,   -29, -1965, -1965, -1965,   321,
    1813,  1814,  1824,  1828, 10649,  1836,  1838,  1839,  1601, 18023,
     855,  1861, 15797,  4846,   421,   423,   690, -1965, -1965, -1965,
   -1965,   857, -1965, -1965, -1965, 14245, -1965,  1604, -1965,  1864,
   -1965, 13249, 13249, -1965,  1867,   862, -1965,  1609,  7810, -1965,
   15826, 15855, -1965,  1869, 14245, 14245,   863,  1870,  1871, -1965,
   -1965,   865, -1965,  1872, -1965, -1965,  1873, 14245, -1965, -1965,
   -1965
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1965, -1965, -1965, -1965,   448, -1965, -1965, -1965, -1965,  -324,
   -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965, -1965,
   -1965, -1965,  -765,  -141,  4934,  3984,  -397, -1965,  1392, -1965,
   -1965, -1965, -1965, -1965, -1965, -1964, -1965,   387,   201,  -125,
   -1965,   -84, -1965,   143,   431, -1965,  1887, -1965,   742,   -44,
   -1965, -1965,     4,  -655,   -37, -1965, -1965, -1965, -1965, -1965,
   -1965, -1965,   785,  1889, -1965, -1965, -1965, -1965, -1300, -1293,
    1890, -1806,  1891, -1965, -1965, -1965,  1260, -1965,  -143, -1965,
   -1965, -1965, -1965,  2533, -1965, -1965, -1495,   293,  1896, -1965,
     -13, -1965, -1965,   185, -1965, -1765,   819, -1965,   -72,  3322,
    3251,  -327,    69, -1965,   -78,   -42, -1965, -1965,    94,   269,
   -1768,  -146,  1090, -1965,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -596
static const yytype_int16 yytable[] =
{
     149,   648,  1558,   991,   992,  1556,  1729,   130,   464,   173,
     683,  1934,   174,  1098,   435,   387,  1975,   485,  1976,  1104,
     322,   188,   175,   356,   380,   173,   382,   437,   384,  1119,
     975,   173,  1551,  1811,   173,  1695,   173,   157,   471,  1553,
     574,   789,   598,  1968,   192,  2103,  1344,   327,   164,   361,
     176,   362,   177,   305,   166,  1174,  2237,   446,   342,  1236,
     391,   823,   656,   657,   310,   778,   806,   824,  1446,   310,
     430,   468,   434,   458,   459,   328,   478,   481,   482,  1543,
    1444,   316,   360,   620,   317,   318,   319,  1696,   305,   311,
    1447,   329,   330,   305,  1113,   804,  1686,   320,   390,     4,
     495,  1448,  1449,   805,   656,   657,  2012,   469,   150,   431,
     656,   657,   151,  1886,   357,   152,   656,   657,   656,   657,
     656,   657,   514,   620,     5,   986,  2023,   810,   656,   657,
     489,   993,  1887,   519,   658,   811,   496,   997,   721,   529,
    1657,  1539,   498,   527,   656,   657,   470,   153,   363,  1557,
    2218,   480,   480,   480,   472,  1389,   826,   343,   154,   817,
     487,   344,   824,  1407,   321,  1931,   367,   345,   346,   368,
     347,   348,   656,   657,   312,  1097,  2220,   313,   383,   314,
     385,   155,   369,   812,    69,    70,    71,    72,   656,   657,
      75,   813,   349,  2055,   976,   458,   459,   480,  1251,    84,
    1252,  1389,   305,    88,  2210,  1830,   305,   305,  1552,  2056,
     656,   657,   305,   305,   480,  1554,   569,   570,   571,  1102,
     332,   333,   323,   156,   358,   324,   957,   656,   657,   656,
     657,  2057,   334,   580,  1389,  1898,   335,   122,  1812,   159,
     633,   634,   635,   122,   316,   656,   657,   317,  2058,   319,
    2059,   122,  1232,   122,   160,   336,   338,  1233,   341,   122,
     320,   176,   122,   177,   122,  1556,  2060,  1120,  1121,   684,
     305,   685,  2121,  1064,   436,   151,   388,   161,   189,   595,
     678,   679,   680,   162,   359,   305,  1396,   438,   305,   596,
     458,   459,   781,   790,   782,   791,   158,  -588,   695,   792,
     575,   193,   599,   664,   305,   305,  1345,   165,   305,   305,
     305,   305,   447,   167,  1175,  2238,   448,   392,   807,   305,
     808,   169,   688,   305,   809,   390,   163,  1048,  1390,  1393,
    2161,   168,   458,   459,   176,   621,   177,   622,  1207,   656,
     657,   623,   170,  1408,  1409,  1410,  1411,   305,   171,   305,
     305,   305,   176,   185,   177,   102,   600,   103,   104,   105,
     106,   107,   352,   758,   353,   111,   112,   305,   114,   172,
     305,  1369,   458,   459,  1370,   621,   444,   622,  1120,  1121,
     445,   623,   454,   455,   456,   457,   186,   458,   459,   556,
     722,   557,   723,   656,   657,  1110,   724,  2233,   710,   752,
     151,   755,   454,   455,   456,   457,   458,   459,   761,   765,
     187,   818,  1127,   808,  1851,  1392,  1801,   819,  -592,   656,
     657,   905,  1138,   656,   657,  1412,   458,   459,   454,   455,
     456,   457,   454,   455,   456,   457,   190,   770,   480,   659,
     305,   458,   459,   770,   305,   305,   454,   455,   456,  1103,
    1512,   191,   458,   459,   656,   657,   458,   459,   194,   771,
     305,   454,   455,   456,   457,   771,  1291,   793,   719,   195,
     772,   773,   781,  2260,   782,  2195,   772,   773,   656,   657,
    1229,  1803,  1804,   899,  1292,   901,   815,   903,   904,   656,
     657,  1733,   831,  1734,   816,  1293,  1294,  1295,   196,  2196,
    1217,  1296,  1297,   919,   920,   197,   916,   770,   816,   211,
    2197,   781,   212,   782,  1536,   213,   651,   652,   305,   816,
    1477,   656,   657,  2296,   660,   665,   667,   198,   214,   771,
     668,  1241,  2116,  1852,   656,   657,   771,   199,   656,   657,
     772,   773,  2198,   923,   305,   774,   775,   772,   773,   200,
     666,   774,   775,   305,   895,   771,   656,   657,   480,  2199,
     480,   305,   480,   480,   487,   681,   772,   773,   858,   682,
     912,   922,   859,   924,   305,   305,   305,  2244,   480,   480,
     305,   175,  1052,   175,   201,   305,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   656,   657,   204,   781,   619,   782,
     982,   305,   984,   985,  1927,   774,   775,   954,   202,   332,
     333,   203,   774,   775,   781,  2245,   782,   776,   777,   998,
     205,   334,  1347,  1621,  1622,   340,   781,  1099,   782,   305,
     305,   774,   775,  1800,  1367,  1801,   656,   657,  1018,  1051,
    1291,  1053,  1054,  1055,  1056,  1057,  1058,  1568,  1060,  1061,
    1062,  1063,   472,   472,  1068,  1069,  1070,  2254,  1292,  1432,
     656,   657,   656,   657,   781,  1040,   782,   859,  1954,  1293,
    1294,  1295,   859,   206,  1437,  1296,  1297,  1438,   305,   305,
     305,  2281,   859,  2282,   207,   859,   305,   209,  1395,  1067,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,  1047,  1912,
    1079,  1913,   619,   487,   480,   487,   480,   480,   480,   480,
     480,   480,  1071,   480,   480,   480,   480,  1066,  1134,   480,
     480,   480,   175,  1072,  2091,   129,   305,   600,  1291,  1144,
     458,   459,  2092,   179,  1115,   208,   180,  -590,  1291,   181,
     210,   182,  1748,   216,   305,   307,  1292,   617,   618,   183,
     860,  1555,    46,   619,   859,   217,  1292,  1293,  1294,  1295,
     305,   927,   306,  1296,  1297,   859,  1107,  1293,  1294,  1295,
     308,   309,  1150,  1296,  1297,   612,   613,   720,   615,   616,
     617,   618,   305,  1124,   325,   315,   619,   961,   305,   326,
     305,   859,   331,   487,  1136,   339,  1253,   720,   615,   616,
     617,   618,  1142,   176,   480,   177,   619,  2122,  2123,  1235,
     962,   351,  1236,  2124,   859,  1291,  1500,   350,  1501,  2126,
    2127,   989,   990,   656,   657,  2124,   652,   458,   459,   354,
    1342,  1510,  1343,  1292,   305,   364,   305,  1008,  1831,   439,
     366,   859,   355,  1081,  1293,  1294,  1295,   859,  1838,  1773,
    1296,  1297,   365,   458,   459,   303,  1422,   377,  1343,  2247,
    -591,  1537,  1087,  1239,  1275,  1276,  1088,   859,   859,   859,
    1322,   466,  2224,   305,   859,  1323,   466,   466,   466,   859,
    1324,   376,  1327,   305,   859,   466,   859,  1253,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,   378,   305,  1269,  1373,
     619,  1556,   379,   859,  1402,  1484,  1955,  1491,   859,   859,
     381,   859,   466,   305,  1592,   400,  1280,  1593,  1594,  2266,
    1509,   442,  1391,  1394,   859,   305,  2283,  1517,  1535,   466,
     386,   859,   859,  1655,   305,   393,  1708,   859,   394,  1253,
     859,  1741,  1604,  1556,   401,   859,   305,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,  1623,  1742,   432,   441,   619,
     859,   568,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,   578,   579,  1835,
    1858,   619,  1643,  1836,   859,  1860,  1943,   449,  1995,   859,
     859,   476,  1996,  2013,  2038,   528,  1659,  2014,   859,   443,
     450,  2039,  2054,  1665,  1431,   859,  1996,  2062,  2088,  2097,
    2114,   859,   816,  2098,  1996,  1399,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,  1627,
    2117,  2118,  2150,   619,   859,   859,   859,  2171,  2172,   151,
    2178,   859,   859,  2186,  1996,   305,  2194,   859,   475,   495,
     859,  2201,   303,  1398,  2208,   859,  2243,   493,  1996,  2250,
     859,   305,   781,   859,   782,   783,  1923,  1924,  1511,  1513,
    -208,  2251,  2252,  2253,   305,   859,   859,   859,  2255,   480,
    2257,  2277,   859,  2284,  2098,  1996,   526,   859,  2293,  2303,
     632,  2306,  2294,  1996,  -209,  2307,   497,  1489,  1490,  -210,
     781,   641,   782,   958,   502,   646,   506,   520,   564,   305,
     305,   567,   305,   305,   305,   581,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   576,   577,   305,   584,
     585,  1283,   586,   597,   645,   445,   629,   630,  1289,   472,
     637,   686,  1300,   466,   639,   638,   642,   689,   669,   647,
     649,   650,   670,   671,   766,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,   305,   480,   480,   672,   619,   801,   673,   674,   675,
     690,   703,   687,   698,   704,   691,   692,   693,   694,   699,
     700,   801,   701,   702,   705,   707,   712,   305,   713,   729,
     730,   731,   742,   743,   745,   747,   748,   746,   750,   751,
     749,   753,   754,   305,   305,   305,   756,   764,   767,   780,
     788,   785,   787,   150,   828,   794,   762,   763,   850,   855,
     832,   834,   862,   863,  1596,   864,   896,   906,  1598,  1511,
    1513,   907,   779,   908,   909,   918,   619,  1602,   930,  1603,
     928,   931,  1605,   966,   967,   970,   981,   980,  1010,  1834,
    1012,   983,  1013,   466,  1016,   466,  1025,   466,   466,   466,
     305,  1027,  1038,  1041,  1080,  1074,   472,  1076,  1086,  1090,
    1091,  1095,  1096,   466,   466,  1100,  1111,  1112,  1128,   305,
    1117,   305,   305,  1130,  1133,  1141,  1456,  1143,  1146,  1151,
    1147,  1152,  1153,  1645,   305,  1155,  1156,  1157,  1159,   480,
    1160,  1161,  1162,   480,  1163,  1164,  1165,  1166,  1167,  1168,
    1171,  1177,   480,  1205,   480,  1248,   600,   480,  1206,  1214,
    1215,  1224,  1216,  1228,  1234,  1240,  1244,  1256,  1257,  1258,
     305,  1264,  1266,   902,  1278,  1286,  1287,  1312,  2130,  1313,
    1315,  1290,  1332,   390,  1334,  1335,   632,  1336,   917,  1341,
    1350,  1351,  1671,  1352,  1676,  1355,   801,  1363,  1366,  1372,
    1365,  1376,  1378,  1379,  1377,  1382,  1383,  1384,   480,  1388,
    1401,  1403,  1404,   305,  1419,   305,  1425,  1426,  1427,  1428,
     801,  1978,  1436,  1441,  1459,  1433,  1440,  1463,  1475,  1504,
    -211,  1526,  1590,   305,  1495,  1521,  1522,  1523,  1527,  1528,
    1529,  1530,  1531,  1533,  1534,  1545,   305,  1544,  1548,  1549,
     305,  1550,  1559,  1560,  1571,   786,  1572,  1561,   466,   466,
     466,   466,   466,   466,   466,   466,   466,  1562,   466,   466,
     466,   466,  1832,  1563,   466,   466,   466,  1564,  1843,  1843,
    1565,  1566,  1567,  1573,   801,  1574,  1575,   801,  1576,  1577,
    1578,  1579,  1580,   801,  1582,  1584,  1587,  1600,  1607,  1984,
    1608,  1606,  1620,  1625,  1629,  1609,  1599,  1611,   305,   305,
     305,  1615,  1626,  1617,  1630,  1631,   305,   305,   305,  1636,
    1638,  1639,  1642,  1640,  1656,  1662,  1663,  1654,  1667,  1114,
    1660,  1116,  1681,  1683,  1682,   305,  1685,  1687,  1691,  1692,
    1693,  1698,  1699,  1700,  1701,  1702,   305,  1703,   466,  1704,
    1705,  1706,  1707,  1709,   305,  1819,  1720,  1727,   305,   466,
    1731,  1740,  1746,  1747,  1822,  1753,  1754,  1755,  1824,   305,
    1863,   305,  1756,  1761,  1757,  1762,  1092,  1764,  1763,  1769,
    1770,  1776,  1785,  1793,  1795,  1902,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   857,
     615,   616,   617,   618,   803,  1796,  1802,  1826,   619,  1777,
     781,  1778,   782,   390,  1779,  1780,  1781,  1872,  1784,  1787,
    1788,   487,   487,  1829,  1828,  1816,  1806,   305,  1853,  1809,
    1821,  1845,  1855,  1861,  1370,  1857,  1850,  1862,  1825,  1865,
    1873,  1864,  1868,  1879,  1881,   480,  1882,  1883,  1884,  1888,
    1889,  1890,  1891,  1892,  1897,  1236,   305,  1905,  1903,  1904,
    1907,   305,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
    1928,  1932,  1933,  1987,   619,  1910,  1591,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,  1918,  1911,  1942,  1948,   619,
    1949,  1950,  1970,  1971,   801,  1982,   801,   801,  1962,  1983,
    1988,  1964,  1972,   816,  -595,  2000,  -593,  2001,  2002,  2003,
     801,  2007,  1772,  2011,  2016,   305,  2017,  2018,  2022,  1243,
     305,   305,  2033,  2019,  2034,  2155,  2020,  2042,  2049,  2021,
     801,  2028,  1961,  2051,  2061,   472,   472,  2045,  2037,  1966,
    1969,  2046,  2064,   305,  2043,  2052,  2071,  2072,  2073,   305,
    2079,  2082,   801,  2080,   305,  2083,  1263,  2081,  1980,  2084,
    2087,  2086,  2089,   305,  2090,  2113,  2095,  2133,  2138,  2134,
    2145,  2151,  2152,   480,  2154,  2162,   480,  2156,  2165,  2182,
    2185,  2189,  2190,  2202,  2204,  2216,  2221,  2170,  2226,  2267,
    2268,   801,   305,  2153,  -594,  2174,  1398,  2166,  2167,  2187,
    2269,  2176,  2240,   390,  2270,   305,   487,  2177,  2179,  2183,
    2193,  2212,  2272,  2205,  2273,  2274,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,   466,  2256,  2275,  2278,   619,  2288,
    2289,   487,  1880,  2292,  2295,  2299,  2304,  2305,  2308,  2309,
    1658,  2234,  1723,  1878,   827,  2104,  2076,  1906,   305,  1689,
     128,  1418,   139,   140,   141,   969,  2128,  1818,  1979,   147,
     305,   305,  2015,   600,  1844,  1967,  1135,  1385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1405,     0,   305,     0,     0,     0,     0,
    2077,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,     0,   466,   466,     0,
       0,     0,  1935,  1936,  1937,  1938,  1939,  1941,     0,     0,
       0,  1457,  1458,  2108,  1460,  1461,  1462,     0,  1464,  1465,
    1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,     0,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   305,     0,
       0,     0,     0,  2109,     0,  2136,   305,   305,     0,     0,
       0,     0,   801,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1488,   305,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,   305,     0,
       0,     0,   305,     0,     0,     0,     0,     0,     0,  1505,
       0,     0,     0,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1518,     0,     0,     0,   390,
       0,  1326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,     0,   466,     0,     0,     0,   466,     0,
       0,     0,     0,     0,     0,     0,     0,   466,     0,   466,
       0,     0,   466,     0,     0,     0,  2203,     0,     0,  1610,
       0,   305,     0,     0,     0,     0,     0,  2211,     0,     0,
       0,     0,  1569,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   857,   615,   616,   617,
     618,  1583,     0,  1585,  1586,   619,  2225,     0,     0,     0,
       0,     0,     0,   466,     0,     0,     0,     0,     0,     0,
       0,     0,  1474,     0,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,   305,   305,   305,   305,  2286,     0,  1532,
       0,     0,  1616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2300,  2302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2310,
       0,     0,     0,     0,     0,   305,     0,     0,     0,     0,
       0,  2140,  2141,  2142,  2143,  2144,     0,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1675,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,  1690,     0,
       0,     0,  1694,     0,     0,   305,     0,     0,     0,     0,
       0,   480,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,     0,     0,     0,  2180,     0,
       0,     0,  2184,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
    1743,  1744,  1745,     0,     0,     0,     0,     0,  1750,  1751,
    1752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2217,  1570,     0,  1767,  2219,     0,
       0,     0,     0,     0,     0,     0,   466,   466,  1775,     0,
       0,     0,     0,     0,  2231,     0,  1783,     0,  1614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     466,  1792,     0,  1794,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,  2264,
    2265,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,   218,
     173,   402,     0,   619,     0,     0,   219,   220,   221,  1849,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   396,
     241,   242,   243,   244,   245,   246,   247,   248,  1871,     0,
       0,     0,     0,     0,     0,     0,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   254,   255,   256,   257,   412,
     413,   414,   415,   258,     0,     0,  1632,   416,   417,   418,
     419,     0,     0,     0,     0,     0,   420,     0,   421,   263,
     264,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     266,    25,   422,   267,  1765,   423,     0,     0,   466,     0,
       0,   466,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   801,     0,   801,  1909,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1849,     0,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,  1951,   466,     0,     0,   619,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,   398,   619,     0,  1977,     0,     0,     0,     0,     0,
       0,     0,     0,  1823,   440,     0,     0,  1986,   278,   424,
     425,   426,   279,     0,     0,     0,     0,     0,   281,   282,
     283,   427,   284,   285,   286,   428,     0,   429,   122,     0,
       0,     0,   467,     0,     0,     0,   477,     0,     0,     0,
       0,   483,     0,     0,     0,   287,   397,     0,   488,     0,
       0,   490,   289,     0,     0,     0,     0,   372,     0,     0,
    1849,  1669,     0,     0,   292,  1827,     0,     0,   499,   500,
     501,     0,   503,   504,   505,     0,   507,   508,   509,   510,
     511,   512,   513,     0,   515,   516,   517,   518,     0,     0,
       0,     0,   522,   522,     0,     0,     0,  2050,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2096,     0,     0,     0,     0,
     587,   589,   591,   592,   522,     0,     0,     0,     0,     0,
    2105,     0,     0,     0,     0,     0,     0,     0,     0,   626,
     522,   522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1849,   644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   654,   655,     0,
    2135,     0,     0,   655,     0,     0,     0,     0,   801,     0,
       0,     0,     0,   522,   677,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,   696,   522,   619,     0,     0,
       0,     0,     0,     0,  1849,     0,   706,     0,   708,   709,
       0,   711,     0,     0,     0,   714,   715,   716,     0,     0,
     718,     0,     0,     0,   725,     0,     0,     0,     0,     0,
       0,     0,     0,  2181,     0,   801,     0,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,   801,     0,   619,
       0,     0,     0,     0,     0,     0,   522,   760,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   768,   769,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   802,     0,
       0,     0,     0,     0,     0,     0,     0,   466,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     833,     0,     0,     0,     0,   838,   466,   466,     0,   842,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
       0,     0,     0,   856,   589,     0,     0,  1849,     0,   861,
       0,     0,     0,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     892,     0,   897,   898,     0,   900,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   910,     0,  1849,   914,   915,
       0,     0,     0,     0,     0,     0,   892,     0,     0,     0,
       0,   522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,   947,   949,   950,
     951,   952,   953,     0,   955,   956,     0,     0,     0,     0,
       0,     0,   963,   964,   965,     0,     0,     0,     0,     0,
     971,   972,   973,   974,     0,   522,   522,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   718,   994,     0,     0,     0,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,     0,
       0,     0,     0,     0,  1014,  1015,     0,  1017,     0,     0,
    1019,     0,     0,     0,   522,   522,   522,  1024,     0,     0,
       0,  1028,   522,  1030,  1031,  1032,     0,     0,  1033,     0,
    1035,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1045,     0,     0,  1046,     0,   955,   956,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1059,     0,
       0,     0,     0,     0,  1524,     0,     0,     0,     0,     0,
       0,     0,   522,     0,     0,     0,     0,     0,     0,  1078,
       0,     0,     0,     0,     0,     0,     0,  1089,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,   522,     0,  1105,     0,
     619,     0,  1026,  1108,  1109,     0,     0,     0,     0,     0,
     987,     0,     0,     0,     0,     0,     0,     0,   522,     0,
    1125,  1126,     0,     0,   522,     0,   522,  1132,     0,     0,
       0,  1125,     0,  1139,     0,  1140,     0,   173,   402,     0,
       0,  1145,     0,     0,     0,  1148,     0,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,  1169,   619,
     947,     0,  1172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,   413,   414,   415,
       0,     0,     0,     0,   416,   417,   418,   419,     0,   522,
       0,     0,     0,   420,     0,   421,     0,     0,     0,   522,
    1219,  1220,  1221,     0,     0,     0,     0,     0,     0,   422,
       0,  1227,   423,     0,     0,     0,   179,     0,     0,   180,
     524,   525,   181,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   522,     0,     0,   452,     0,     0,     0,     0,  1262,
       0,     0,     0,  1268,     0,     0,     0,     0,     0,  1274,
       0,     0,   522,     0,     0,     0,     0,     0,     0,     0,
    1284,  1285,     0,     0,     0,     0,  1288,     0,     0,     0,
       0,   523,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1314,     0,     0,  1316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   627,   628,
    1833,     0,     0,     0,     0,     0,   424,   425,   426,     0,
       0,     0,  1337,     0,  1339,  1340,     0,     0,   427,     0,
       0,     0,   428,     0,   429,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1361,     0,     0,
       0,   676,     0,     0,     0,     0,     0,   173,   402,     0,
     590,   458,   459,   523,   600,     0,     0,  1381,  -589,     0,
    1644,     0,     0,     0,  1387,     0,     0,     0,     0,   523,
     523,  1400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1423,  1424,     0,     0,     0,     0,
     522,     0,     0,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,     0,     0,     0,   412,   413,   414,   415,
       0,     0,   523,     0,   416,   417,   418,   419,     0,     0,
       0,     0,  1454,   420,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,   759,   523,     0,     0,     0,   422,
       0,     0,   423,     0,   522,     0,   179,     0,     0,   180,
       0,     0,   181,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,  1478,     0,    46,     0,     0,     0,     0,
       0,     0,     0,  1479,  1480,  1481,  1482,  1483,     0,     0,
       0,     0,  1485,  1486,   452,  1487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1498,  1499,     0,     0,   523,     0,     0,     0,  1502,
    1503,     0,     0,     0,     0,     0,     0,     0,  1507,  1508,
       0,     0,     0,     0,  1514,  1515,     0,     0,     0,     0,
     522,   522,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,   424,   425,   426,     0,
       0,     0,     0,     0,     0,  1547,     0,     0,   427,     0,
       0,     0,   428,     0,   429,   122,     0,     0,     0,   925,
       0,     0,     0,   590,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   857,   615,   616,
     617,   618,     0,  1581,     0,   781,   619,   782,  1839,   883,
       0,     0,     0,     0,     0,  1514,  1515,     0,   893,   894,
     522,     0,     0,     0,     0,     0,     0,     0,  1597,     0,
       0,     0,     0,   977,   978,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   921,     0,     0,     0,     0,
     523,     0,  1613,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1619,     0,     0,  1624,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   948,     0,     0,     0,
       0,     0,  1021,  1022,  1023,     0,     0,     0,     0,     0,
    1029,     0,     0,     0,     0,  1646,     0,     0,  1649,   522,
    1652,   522,     0,     0,   523,   523,     0,     0,     0,  1661,
       0,     0,  1664,     0,  1661,     0,  1668,  1670,     0,     0,
    1678,  1679,  1680,     0,     0,     0,     0,     0,     0,     0,
     433,   402,     0,     0,     0,     0,     0,     0,     0,  1946,
    1073,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   523,   523,   523,     0,     0,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,     0,   403,   404,   405,   406,
     407,   408,   409,   410,   411,     0,     0,     0,     0,   412,
     413,   414,   415,     0,     0,     0,  1123,   416,   417,   418,
     419,  1749,  1129,     0,  1131,     0,   420,     0,   421,     0,
       0,   523,  1758,  1759,  1760,     0,     0,     0,     0,     0,
       0,  1766,   422,  1768,     0,   423,     0,     0,     0,     0,
    1771,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,   523,     0,     0,     0,     0,
    1789,  1790,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1797,  1798,  1799,     0,     0,     0,   523,     0,     0,
       0,     0,  1810,   523,     0,   523,     0,     0,     0,     0,
       0,     0,  1820,     0,     0,     0,     0,  1208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1218,     0,     0,
       0,     0,     0,  1837,     0,     0,     0,     0,     0,     0,
       0,  1846,  1847,  2169,     0,     0,     0,     0,     0,   948,
       0,  1173,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1247,     0,   424,
     425,   426,     0,     0,     0,     0,     0,  1876,     0,  1255,
       0,   427,     0,     0,     0,   428,     0,   429,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,     0,
    1277,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
    1893,  1894,  1895,   619,     0,     0,     0,     0,     0,     0,
       0,  1896,     0,     0,     0,     0,  1899,  1900,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1908,
     523,     0,     0,     0,     0,     0,   522,   522,  1916,     0,
    1917,     0,     0,     0,     0,     0,  1925,  1926,  1042,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   522,     0,     0,     0,     0,
     522,  1945,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1899,  1900,     0,     0,  1959,     0,     0,
    1963,     0,     0,     0,  1965,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1974,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1981,     0,     0,     0,  1430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1992,     0,
       0,     0,     0,  1998,  1999,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2004,     0,     0,
    2005,  2004,     0,  2008,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,  1476,     0,     0,     0,   619,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   522,   522,     0,   523,
       0,     0,     0,  2035,  2036,     0,     0,     0,     0,   784,
       0,     0,     0,     0,     0,  2044,     0,     0,     0,     0,
       0,     0,     0,     0,  2053,     0,     0,     0,     0,     0,
       0,     0,     0,   589,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2065,  2066,     0,     0,
     718,   522,     0,   523,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1519,  1520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1947,
       0,     0,     0,     0,     0,     0,  2093,  2094,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,  2107,     0,     0,
     619,     0,   522,   522,  2112,     0,     0,   911,     0,  2115,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   402,
       0,     0,     0,   522,     0,     0,     0,     0,     0,   523,
     523,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,  2146,  1595,     0,
     522,     0,     0,     0,     0,     0,     0,     0,     0,   959,
       0,     0,     0,     0,   403,   404,   405,   406,   407,   408,
     409,   410,   411,     0,     0,  2158,     0,   412,   413,   414,
     415,  2163,     0,     0,  2164,   416,   417,   418,   419,     0,
       0,     0,     0,     0,   420,     0,   421,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     422,     0,     0,   423,     0,  2188,     0,   179,     0,   523,
     180,     0,     0,   181,     0,   182,     0,  1651,     0,  1653,
       0,     0,  2041,     0,     0,     0,    46,     0,     0,     0,
       0,     0,  2206,  2207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,     0,  2213,  2214,  2070,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2223,     0,     0,     0,     0,   522,   522,
     522,   522,   522,  2085,     0,     0,     0,     0,  1998,     0,
       0,     0,  2239,     0,     0,     0,     0,     0,   523,     0,
     523,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,  2259,
       0,     0,     0,   619,  2262,  2263,  2119,   424,   425,   426,
       0,     0,     0,     0,     0,     0,     0,   522,     0,   427,
       0,     0,     0,   428,     0,   429,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2290,  2291,     0,     0,     0,     0,
       0,     0,  1786,  2120,     0,     0,     0,     0,     0,  1839,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1178,
    1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,  1187,  1188,
    1189,     0,  1191,  1192,  1193,  1194,     0,  1196,  1197,  1198,
    1199,     0,     0,     0,     0,     0,     0,     0,     0,  2200,
       0,     0,     0,  1211,     0,  1213,     0,     0,     0,     0,
       0,     0,     0,   523,     0,     0,  1223,     0,     0,     0,
       0,     0,     0,     0,  1230,  1231,     0,     0,     0,     0,
       0,     0,     0,  1242,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
       0,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
     178,     0,   184,   619,     0,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,     0,     0,     0,  1877,     0,     0,     0,
       0,     0,     0,     0,  1914,  1915,     0,  2246,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,  1346,  1348,  1349,     0,  1944,     0,
    1353,  1354,     0,     0,  1357,  1358,  1359,  1360,     0,  1362,
       0,     0,     0,     0,  1368,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,   523,   523,   619,     0,     0,
       0,     0,     0,   465,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,   523,     0,   619,     0,   781,   523,
     782,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,  1453,   619,  1455,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2031,  2032,     0,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   558,   559,   560,   561,   562,   563,     0,
     565,   566,     0,     0,     0,     0,     0,     0,     0,     0,
     572,   573,     0,     7,     8,     0,     0,     0,     0,  2069,
       0,     0,     0,   582,   583,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   523,   523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1516,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,   590,     0,     0,     0,     0,     0,     0,     0,
    2110,  2111,     0,     0,     0,     0,     0,     0,     0,     0,
     523,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2129,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,  2139,  1245,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,  2149,     0,
       0,     0,     0,     0,   795,    57,     0,     0,    60,   796,
     717,   797,   798,     0,   799,     0,     0,   726,   727,   728,
       0,   523,   523,   732,   733,   734,   735,   736,   737,   738,
       0,   739,    81,     0,     0,     0,   740,   741,  1246,     0,
     744,     0,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,     0,    98,
      99,   100,     0,     0,     0,     0,  1633,     0,     0,   523,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,   781,     0,   782,     0,     0,     0,
       0,     0,  1807,     0,     0,     0,     0,     0,  2215,  1672,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2227,  2228,  2229,  2230,
    2232,     0,     0,     0,     0,     0,   821,     0,     0,     0,
       0,     0,  1710,  1711,  1712,  1713,  1714,  1715,  1716,     0,
       0,     0,     0,  1721,  1722,     0,     0,     0,     0,     0,
    1724,     0,     0,  1726,     0,     0,     0,  1730,     0,     0,
    1732,     0,     0,     0,     0,     0,     0,     0,     0,   523,
       0,  1739,     0,     0,     0,  2271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   523,   523,   523,
     523,   523,     0,     0,     0,     0,     0,     0,     0,     0,
     929,     0,     0,     0,     0,     0,     0,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   523,     0,     0,  1805,
       0,  1808,     0,     0,     0,  1815,     0,  1817,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,     0,     0,  1840,     0,
       0,   218,     6,   402,     0,     0,     0,     0,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,  1673,   404,
     405,   406,   407,   408,   409,   410,   411,   254,   255,   256,
     257,   412,   413,   414,   415,   258,   259,     0,     0,   416,
     417,   418,   419,     0,     0,   260,   261,   262,   420,     0,
     421,   263,   264,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   266,    25,   422,   267,     0,   423,     0,  1901,
       0,   268,     0,     0,   269,  1589,     0,   270,     0,   271,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,     0,    58,    59,     0,   274,     0,   275,
       0,     0,   276,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1989,     0,     0,  1990,     0,
     278,   424,   425,   426,   279,   280,     0,     0,     0,     0,
     281,   282,   283,   427,   284,   285,   286,   428,     0,   429,
     122,     0,     0,     0,     0,     0,     0,     0,  1237,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   288,     0,
       0,     0,     0,     0,   289,     0,     0,  2024,  2025,   372,
    2027,     0,     0,  1674,     0,     0,   292,     0,     0,     0,
       0,  1254,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   795,    57,     0,     0,
      60,   796,     0,   797,   798,     0,   799,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2074,  2075,     0,
       0,     0,     0,     0,    81,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,    98,    99,   100,     0,     0,   218,     6,   402,     0,
       0,     0,     0,   219,   220,   221,  2106,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   254,   255,   256,   257,   412,   413,   414,   415,
     258,   259,     0,     0,   416,   417,   418,   419,   995,     0,
     260,   261,   262,   420,     0,   421,   263,   264,   265,     0,
       0,     0,     0,     0,     0,     0,  1445,   266,    25,   422,
     267,     0,   423,     0,     0,     0,   268,     0,     0,   269,
       0,     0,   270,     0,   271,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,     0,    58,
      59,     0,   274,     0,   275,     0,     0,   276,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,     0,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,  1506,   619,   277,     0,     0,
       0,     0,  1869,     0,     0,     0,  1870,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   424,   425,   426,   279,
     280,     0,     0,     0,     0,   281,   282,   283,   427,   284,
     285,   286,   428,     0,   429,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,   372,     0,     0,  2280,   291,     0,
       0,   292,   218,   173,   402,     0,   451,     0,     0,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   396,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,     0,     0,     0,     0,     0,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   254,   255,
     256,   257,   412,   413,   414,   415,   258,     7,     8,     0,
     416,   417,   418,   419,     0,     0,     0,     0,     0,   420,
       0,   421,   263,   264,   265,     0,     0,  1634,  1635,     0,
       0,     0,     0,   266,    25,   422,   267,     0,   423,     0,
       0,     0,   179,     0,     0,   180,     0,     0,   181,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
     452,     0,     0,     0,   619,     0,     0,     0,     0,     0,
    1921,     0,     0,     0,  1922,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,  1728,     0,     0,   795,    57,
       0,     0,    60,   796,  1735,   797,   798,     0,   799,     0,
       0,     0,     0,     0,   453,     0,     0,     0,     0,     0,
       0,   278,   424,   425,   426,   279,    81,     0,     0,     0,
       0,   281,   282,   283,   427,   284,   285,   286,   428,     0,
     429,   122,     0,   454,   455,   456,   457,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,     0,   287,   397,
       0,     0,     0,     0,     0,   289,     0,   458,   459,     0,
     460,     0,   461,     0,     0,     0,   462,   292,   218,     6,
     371,     0,     0,     0,     0,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
    1020,     0,     0,     0,   254,   255,   256,   257,     0,     0,
       0,     0,   258,   259,     0,     0,     0,     0,     0,     0,
       0,     0,   260,   261,   262,     0,     0,     0,   263,   264,
     265,     0,     0,     0,     0,     0,     0,  1874,     0,   266,
      25,     0,   267,     0,     0,     0,     0,     0,   268,     0,
       0,   269,     0,     0,   270,     0,   271,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,    58,    59,     0,   274,     0,   275,     0,     0,   276,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,     0,    88,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,   277,
       0,     0,     0,  1952,     0,     0,     0,  1953,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   279,   280,     0,     0,     0,     0,   281,   282,   283,
       0,   284,   285,   286,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,     0,     0,     0,     0,
       0,   289,     0,     0,     0,     0,   372,   218,     6,     0,
     373,     0,   697,   292,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,   257,     0,     0,     0,
       0,   258,   259,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   261,   262,     0,     0,     0,   263,   264,   265,
       0,     0,     0,     0,     0,     0,     0,     0,   266,    25,
       0,   267,     0,     0,     0,     0,     0,   268,     0,     0,
     269,     0,     0,   270,     0,   271,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
      58,    59,     0,   274,     0,   275,     0,     0,   276,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    84,
       0,     0,     0,    88,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,   277,     0,
       0,     0,  2131,     0,     0,     0,  2132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,     0,     0,     0,
     279,   280,     0,     0,     0,     0,   281,   282,   283,     0,
     284,   285,   286,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   521,     0,     0,     0,     0,     0,
     289,     0,     0,     0,     0,   372,   218,     6,  1774,     0,
     593,     0,   292,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,   257,     0,     0,     0,     0,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,   261,   262,     0,     0,     0,   263,   264,   265,     0,
       0,     0,     0,     0,     0,     0,     0,   266,    25,     0,
     267,     0,     0,     0,     0,     0,   268,     0,     0,   269,
       0,     0,   270,     0,   271,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,     0,    58,
      59,     0,   274,     0,   275,     0,     0,   276,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,   277,     0,     0,
       0,     0,     0,     0,     0,   814,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,     0,     0,   279,
     280,     0,     0,     0,     0,   281,   282,   283,     0,   284,
     285,   286,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,   372,   218,     6,     0,   291,     0,
       0,   292,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,   257,     0,     0,     0,     0,   258,
     259,     0,     0,     0,     0,     0,     0,     0,     0,   260,
     261,   262,     0,     0,     0,   263,   264,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   266,    25,     0,   267,
       0,     0,     0,     0,     0,   268,     0,     0,   269,     0,
       0,   270,     0,   271,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,     0,    58,    59,
       0,   274,     0,   275,     0,     0,   276,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
       0,    88,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,   277,     0,     0,     0,
       0,     0,     0,     0,   820,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,   279,   280,
       0,     0,     0,     0,   281,   282,   283,     0,   284,   285,
     286,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   661,  1940,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,   663,   218,     6,     0,   335,   593,     0,
     292,   219,   220,   221,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,   257,     0,     0,     0,     0,   258,   259,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   261,
     262,     0,     0,     0,   263,   264,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   266,    25,     0,   267,     0,
       0,     0,     0,     0,   268,     0,     0,   269,     0,     0,
     270,     0,   271,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,     0,    58,    59,     0,
     274,     0,   275,     0,     0,   276,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   277,     0,     0,     0,     0,
       0,     0,     0,   822,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   279,   280,     0,
       0,     0,     0,   281,   282,   283,     0,   284,   285,   286,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,   290,   218,     6,     0,   291,     0,     0,   292,
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
       0,     0,   272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,    58,    59,     0,   274,
       0,   275,     0,     0,   276,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,     0,    88,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,   277,     0,     0,     0,     0,     0,
       0,     0,   987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,   279,   280,     0,     0,
       0,     0,   281,   282,   283,     0,   284,   285,   286,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     288,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,   372,   218,     6,     0,   291,     0,     0,   292,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,   257,     0,     0,     0,     0,   258,   259,     0,     0,
       0,     0,     0,     0,     0,     0,   260,   261,   262,     0,
       0,     0,   263,   264,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   266,    25,     0,   267,     0,     0,     0,
       0,     0,   268,     0,     0,   269,     0,     0,   270,     0,
     271,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,     0,    58,    59,     0,   274,     0,
     275,     0,     0,   276,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    84,     0,     0,     0,    88,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,   277,     0,     0,     0,     0,     0,     0,
       0,   988,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   279,   280,     0,     0,     0,
       0,   281,   282,   283,     0,   284,   285,   286,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   521,
       0,     0,     0,     0,     0,   289,     0,     0,     0,     0,
     372,   218,     6,     0,   588,     0,     0,   292,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
     257,     0,     0,     0,     0,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,   261,   262,     0,     0,
       0,   263,   264,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   266,    25,     0,   267,     0,     0,     0,     0,
       0,   268,     0,     0,   269,     0,     0,   270,     0,   271,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,     0,    58,    59,     0,   274,     0,   275,
       0,     0,   276,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,   277,     0,     0,     0,     0,     0,     0,     0,
    1039,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,     0,     0,     0,   279,   280,     0,     0,     0,     0,
     281,   282,   283,     0,   284,   285,   286,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   521,     0,
       0,     0,     0,     0,   289,     0,     0,     0,     0,   372,
     218,     6,     0,     0,   593,     0,   292,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,   257,
       0,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   261,   262,     0,     0,     0,
     263,   264,   265,     0,     0,     0,     0,     0,     0,     0,
       0,   266,    25,     0,   267,     0,     0,     0,     0,     0,
     268,     0,     0,   269,     0,     0,   270,     0,   271,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,     0,    58,    59,     0,   274,     0,   275,     0,
       0,   276,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    84,     0,     0,     0,    88,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,   277,     0,     0,     0,     0,     0,     0,     0,  1149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,     0,     0,   279,   280,     0,     0,     0,     0,   281,
     282,   283,     0,   284,   285,   286,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   288,     0,     0,
       0,     0,     0,   289,     0,     0,     0,     0,   631,   218,
       6,     0,   291,     0,     0,   292,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,   257,     0,
       0,     0,     0,   258,   259,     0,     0,     0,     0,     0,
       0,     0,     0,   260,   261,   262,     0,     0,     0,   263,
     264,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     266,    25,     0,   267,     0,     0,     0,     0,     0,   268,
       0,     0,   269,     0,     0,   270,     0,   271,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   272,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,     0,    58,    59,     0,   274,     0,   275,     0,     0,
     276,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,     0,    88,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     277,     0,     0,     0,     0,     0,     0,     0,  1190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,     0,
       0,     0,   279,   280,     0,     0,     0,     0,   281,   282,
     283,     0,   284,   285,   286,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   288,     0,     0,     0,
       0,     0,   289,     0,     0,     0,     0,   640,   218,     6,
       0,   291,     0,     0,   292,   219,   220,   221,     0,     0,
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
       0,     0,     0,    42,     0,     0,     0,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,    58,    59,     0,   274,     0,   275,     0,     0,   276,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,     0,    88,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,   277,
       0,     0,     0,     0,     0,     0,     0,  1200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,     0,     0,
       0,   279,   280,     0,     0,     0,     0,   281,   282,   283,
       0,   284,   285,   286,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   521,     0,     0,     0,     0,
       0,   289,     0,     0,     0,     0,   372,   218,     6,     0,
     946,     0,  1429,   292,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,   257,     0,     0,     0,
       0,   258,   259,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   261,   262,     0,     0,     0,   263,   264,   265,
       0,     0,     0,     0,     0,     0,     0,     0,   266,    25,
       0,   267,     0,     0,     0,     0,     0,   268,     0,     0,
     269,     0,     0,   270,     0,   271,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   272,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
      58,    59,     0,   274,     0,   275,     0,     0,   276,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    84,
       0,     0,     0,    88,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,   277,     0,
       0,     0,     0,     0,     0,     0,  1201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,     0,     0,     0,
     279,   280,     0,     0,     0,     0,   281,   282,   283,     0,
     284,   285,   286,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   521,     0,     0,     0,     0,     0,
     289,   218,     6,     0,     0,   372,  1650,     0,   219,   220,
     221,     0,   292,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
     257,     0,     0,     0,     0,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,   261,   262,     0,     0,
       0,   263,   264,   265,     0,     0,     0,     0,     0,     0,
       0,     0,   266,    25,     0,   267,     0,     0,     0,     0,
       0,   268,     0,     0,   269,     0,     0,   270,     0,   271,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,     0,    58,    59,     0,   274,     0,   275,
       0,     0,   276,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,   277,     0,     0,     0,     0,     0,     0,     0,
    1202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,     0,     0,     0,   279,   280,     0,     0,     0,     0,
     281,   282,   283,     0,   284,   285,   286,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   521,     0,
       0,     0,     0,     0,   289,   218,     6,     0,     0,   372,
       0,     0,   219,   220,   221,     0,   292,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,   257,     0,     0,     0,     0,   258,
     259,     0,     0,     0,     0,     0,     0,     0,     0,   260,
     261,   262,     0,     0,     0,   263,   264,   265,     0,     0,
       0,     0,     0,     0,     0,     0,   266,    25,     0,   267,
       0,     0,     0,     0,     0,   268,     0,     0,   269,     0,
       0,   270,     0,   271,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,     0,    58,    59,
       0,   274,     0,   275,     0,     0,   276,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
       0,    88,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,   277,     0,     0,     0,
       0,     0,     0,     0,  1203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,   279,   280,
       0,     0,     0,     0,   281,   282,   283,     0,   284,   285,
     286,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,   372,   218,     6,     0,  1782,     0,     0,
     292,   219,   220,   221,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,   257,     0,     0,     0,     0,   258,   259,
       0,     0,     0,     0,     0,     0,     0,     0,   260,   261,
     262,     0,     0,     0,   263,   264,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   266,    25,     0,   267,     0,
       0,     0,     0,     0,   268,     0,     0,   269,     0,     0,
     270,     0,   271,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,     0,    58,    59,     0,
     274,     0,   275,     0,     0,   276,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   277,     0,     0,     0,     0,
       0,     0,     0,  1204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,     0,   279,   280,     0,
       0,     0,     0,   281,   282,   283,     0,   284,   285,   286,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     661,  1940,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,   663,   218,     6,     0,   335,     0,     0,   292,
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
       0,     0,   272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,     0,    58,    59,     0,   274,
       0,   275,     0,     0,   276,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,     0,    88,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,   277,     0,     0,     0,     0,     0,
       0,     0,  1209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,   279,   280,     0,     0,
       0,     0,   281,   282,   283,     0,   284,   285,   286,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     521,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,   372,   218,     6,     0,     0,  2068,     0,   292,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,   257,     0,     0,     0,     0,   258,   259,     0,     0,
       0,     0,     0,     0,     0,     0,   260,   261,   262,     0,
       0,     0,   263,   264,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   266,    25,     0,   267,     0,     0,     0,
       0,     0,   268,     0,     0,   269,     0,     0,   270,     0,
     271,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,     0,    58,    59,     0,   274,     0,
     275,     0,     0,   276,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    84,     0,     0,     0,    88,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,   277,     0,     0,     0,     0,     0,     0,
       0,  1210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   279,   280,     0,     0,     0,
       0,   281,   282,   283,     0,   284,   285,   286,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   521,
       0,     0,     0,     0,     0,   289,   218,   173,   402,     0,
     372,     0,     0,   219,   220,   221,     0,   292,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   396,   241,   242,   243,
     244,   245,   246,   247,   248,     0,     0,     0,     0,     0,
       0,     0,     0,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   254,   255,   256,   257,   412,   413,   414,   415,
     258,     0,     0,     0,   416,   417,   418,   419,     0,     0,
       0,     0,     0,   420,     0,   421,   263,   264,   265,     0,
       0,     0,     0,     0,     0,     0,     0,   266,    25,   422,
     267,     0,   423,   218,   173,   402,     0,     0,     0,     0,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   396,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,     0,     0,     0,     0,
    1673,   404,   405,   406,   407,   408,   409,   410,   411,   254,
     255,   256,   257,   412,   413,   414,   415,   258,     0,     0,
       0,   416,   417,   418,   419,     0,     0,     0,     0,     0,
     420,     0,   421,   263,   264,   265,     0,     0,     0,     0,
       0,     0,     0,     0,   266,    25,   422,   267,     0,   423,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   424,   425,   426,   279,
       0,     0,     0,     0,     0,   281,   282,   283,   427,   284,
     285,   286,   428,     0,   429,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,  1957,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,   372,     0,     0,     0,  1958,     0,
       0,   292,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1212,     0,     0,     0,     0,     0,
       0,     0,   278,   424,   425,   426,   279,     0,     0,     0,
       0,     0,   281,   282,   283,   427,   284,   285,   286,   428,
       0,   429,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     397,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,   372,   218,   173,   402,  1839,     0,     0,   292,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   396,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,     0,     0,     0,     0,     0,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   254,   255,
     256,   257,   412,   413,   414,   415,   258,     0,     0,     0,
     416,   417,   418,   419,     0,     0,     0,     0,     0,   420,
       0,   421,   263,   264,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   266,    25,   422,   267,     0,   423,   218,
     173,     0,   395,     0,     0,     0,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   396,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,   257,     0,
       0,     0,     0,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
     264,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     266,    25,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   424,   425,   426,   279,     0,     0,     0,     0,
       0,   281,   282,   283,   427,   284,   285,   286,   428,     0,
     429,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   397,
       0,     0,     0,     0,     0,   289,     0,   218,   173,     0,
     372,     0,     0,     0,   219,   220,   221,   292,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   396,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,     0,
       0,     0,   279,   254,   255,   256,   257,     0,   281,   282,
     283,   258,   284,   285,   286,     0,     0,     0,   122,     0,
       7,     8,     0,     0,     0,     0,     0,   263,   264,   265,
       0,     0,     0,     0,     0,   287,   397,     0,   266,    25,
       0,   267,   289,   218,   173,     0,     0,   372,     0,     0,
     219,   220,   221,     0,   292,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   396,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   263,   264,   265,    43,    44,    45,    46,
       0,     0,    48,     0,   266,    25,     0,   267,     0,     0,
       0,   795,    57,     0,     0,    60,   796,     0,   797,   798,
       0,   799,     0,     0,     0,     0,   278,     0,     0,     0,
     279,     0,     0,     0,     0,     0,   281,   282,   283,    81,
     284,   285,   286,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   397,     0,    98,    99,   100,     0,
     289,     0,     0,     0,     0,   372,     0,     0,     0,   643,
       0,     0,   292,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1330,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,   279,     0,     0,     0,
       0,     0,   281,   282,   283,     0,   284,   285,   286,     0,
       0,     0,   122,  1075,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   661,
     662,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,   663,   218,   173,     0,   335,     0,   913,   292,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   396,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,   257,     0,     0,     0,     0,   258,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   264,   265,     0,     0,     0,     0,     0,
     218,   173,     0,   266,    25,     0,   267,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     396,   241,   242,   243,   244,   245,   246,   247,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,   257,
       0,     0,     0,     0,   258,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     263,   264,   265,    43,    44,    45,    46,     0,     0,    48,
       0,   266,    25,     0,   267,     0,     0,     0,   795,    57,
       0,     0,    60,   796,     0,   797,   798,     0,   799,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,     0,     0,     0,   279,    81,     0,     0,     0,
       0,   281,   282,   283,     0,   284,   285,   286,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,     0,   287,   397,
       0,     0,     0,     0,     0,   289,     0,     0,     0,     0,
     372,     0,     0,     0,     0,     0,     0,   292,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,     0,     0,     0,   278,
    1356,     0,     0,   279,     0,     0,     0,     0,     0,   281,
     282,   283,     0,   284,   285,   286,     0,     0,     0,   122,
    1077,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   397,     0,     0,
       0,     0,     0,   289,   218,   173,     0,  1380,   372,  1137,
       0,   219,   220,   221,     0,   292,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   396,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,   257,     0,     0,     0,     0,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,   264,   265,     0,     0,     0,
       0,     0,     0,     0,     0,   266,    25,     0,   267,   218,
     173,     0,  1546,     0,     0,     0,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   396,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,   257,     0,
       0,     0,     0,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
     264,   265,     0,     0,     0,     0,     0,     0,     0,     0,
     266,    25,     0,   267,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,   278,     0,     0,   619,   279,     0,     0,
       0,     0,     0,   281,   282,   283,  1439,   284,   285,   286,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   397,     0,     0,     0,     0,     0,   289,     0,     0,
       0,     0,   372,     0,     0,     0,     0,     0,     0,   292,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1443,     0,     0,     0,     0,     0,   278,     0,
       0,     0,   279,     0,     0,     0,     0,     0,   281,   282,
     283,     0,   284,   285,   286,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   397,     0,     0,     0,
       0,     0,   289,   218,   173,     0,  1612,   372,     0,     0,
     219,   220,   221,     0,   292,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   396,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,   264,   265,     0,     0,     0,     0,
       0,   218,   173,     0,   266,    25,     0,   267,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   396,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
     257,     0,     0,     0,     0,   258,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,   263,   264,   265,    43,    44,    45,    46,     0,     0,
      48,     0,   266,    25,     0,   267,     0,     0,     0,   795,
      57,     0,     0,    60,   796,     0,   797,   798,     0,   799,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,     0,     0,     0,   279,    81,     0,     0,
       0,     0,   281,   282,   283,     0,   284,   285,   286,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,     0,   287,
     397,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,   372,     0,     0,     0,     0,     0,     0,   292,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,     0,     0,     0,     0,     0,     0,     0,
     278,  1540,     0,     0,   279,     0,     0,     0,     0,     0,
     281,   282,   283,     0,   284,   285,   286,     0,     0,     0,
     122,  1279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   397,     0,
       0,     0,     0,     0,   289,   218,   173,     0,     0,   372,
    1666,     0,   219,   220,   221,     0,   292,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   396,   241,   242,   243,   244,
     245,   246,   247,   248,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,   257,     0,     0,     0,     0,   258,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   264,   265,     0,     0,
       0,     0,     0,   218,   173,     0,   266,    25,     0,   267,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   396,   241,   242,   243,   244,   245,   246,
     247,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,   257,     0,     0,     0,     0,   258,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   263,   264,   265,    43,    44,    45,    46,
       0,     0,    48,     0,   266,    25,     0,   267,     0,     0,
       0,   795,    57,     0,     0,    60,   796,     0,   797,   798,
       0,   799,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,     0,     0,     0,   279,    81,
       0,     0,     0,     0,   281,   282,   283,     0,   284,   285,
     286,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
       0,   287,   397,     0,     0,     0,     0,     0,   289,     0,
       0,     0,     0,   372,  2006,     0,     0,     0,     0,     0,
     292,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,     0,     0,     0,     0,     0,
       0,     0,   278,  1541,     0,     0,   279,     0,     0,     0,
       0,     0,   281,   282,   283,     0,   284,   285,   286,     0,
       0,     0,   122,  1281,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     397,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,   372,   218,   173,     0,  2067,     0,     0,   292,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   396,   241,   242,   243,   244,   245,   246,   247,
     248,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,   257,     0,     0,     0,     0,   258,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   263,   264,   265,    43,    44,    45,    46,     0,
       0,    48,     0,   266,    25,     0,   267,     0,     0,     0,
     795,    57,     0,     0,    60,   796,     0,   797,   798,     0,
     799,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     7,     8,     0,    43,    44,    45,
      46,     0,     0,    48,     0,    98,    99,   100,     0,     0,
       0,     0,   795,    57,     0,     0,    60,   796,     0,   797,
     798,     0,   799,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,   278,     0,     0,     0,   279,     0,    98,    99,   100,
       0,   281,   282,   283,     0,   284,   285,   286,     0,     0,
       0,   122,  1282,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,   287,   397,
      43,    44,    45,    46,     0,   289,    48,     0,     0,     0,
     372,     0,     0,     0,     0,   795,    57,   292,     0,    60,
     796,     0,   797,   798,     0,   799,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,  1301,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
      98,    99,   100,     0,     0,     0,   795,    57,     0,     0,
      60,   796,     0,   797,   798,     0,   799,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    98,    99,   100,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,  1320,     0,   795,
      57,     7,     8,    60,   796,     0,   797,   798,     0,   799,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,    98,    99,   100,     0,  1338,   795,
      57,     7,     8,    60,   796,     0,   797,   798,     0,   799,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,    98,    99,   100,     0,     0,     0,
       0,     0,   795,    57,     0,     0,    60,   796,     0,   797,
     798,  1375,   799,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,    98,    99,   100,
       0,     0,   795,    57,     0,     0,    60,   796,     0,   797,
     798,  1538,   799,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
      81,    -4,    -4,     0,     0,     0,     0,     0,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,    98,    99,   100,
     619,     0,     0,     0,     0,    -4,    -4,    -4,     0,     0,
    1588,     0,     0,     0,  2191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,  2248,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     6,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       7,     8,     0,     0,     0,     0,     0,     0,    -4,     0,
      -4,    -4,     0,     0,     0,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     9,    10,    11,   619,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1717,     0,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,     0,
       0,     0,    15,    16,     0,     0,     0,     0,    17,     0,
       0,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,     0,    25,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,    42,    43,    44,    45,    46,
      47,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,    93,    94,    95,     0,     0,     0,
      96,     0,     0,     0,     0,    97,    98,    99,   100,   173,
     402,   101,     0,   102,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,   122,
     123,     0,     0,     0,     0,   403,   404,   405,   406,   407,
     408,   409,   410,   411,     0,     0,     0,     0,   412,   413,
     414,   415,   173,   402,     0,     0,   416,   417,   418,   419,
       0,     0,     0,     0,     0,   420,     0,   421,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   422,     0,     0,   423,     0,     0,     0,   179,     0,
     402,   180,     0,     0,   181,     0,   182,     0,   403,   404,
     405,   406,   407,   408,   409,   410,   411,    46,     0,     0,
       0,   412,   413,   414,   415,     0,     0,     0,     0,   416,
     417,   418,   419,     0,     0,     0,   452,     0,   420,     0,
     421,     0,     0,     0,     0,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   422,     0,     0,   423,   412,   413,
     414,   415,     0,     0,     0,     0,   416,   417,   418,   419,
       0,     0,     0,     0,     0,   420,     0,   421,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   422,     0,     0,   423,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   424,   425,
     426,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     427,     0,     0,     0,   428,     0,   429,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,     0,
       0,   424,   425,   426,  1718,     0,     0,     0,     0,     0,
       0,     0,     0,   427,     0,     0,     0,   428,     0,   429,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   424,   425,
     426,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     427,     0,     0,     0,   428,     0,   429,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       7,     8,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   795,    57,
       0,     0,    60,   796,     0,   797,   798,     0,   799,     0,
       0,     0,  1083,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,     0,
    1084,     0,     0,     0,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,    98,    99,   100,   619,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1719,     0,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   795,    57,     0,     0,    60,   796,     0,   797,   798,
       0,   799,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,    98,    99,   100,     0,
       0,     0,  1867,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1993,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1994,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2026,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2101,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2159,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2160,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2175,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2209,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2236,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2241,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2242,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,     0,     0,   854,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,  1118,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
       0,     0,  1176,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,  1225,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,     0,
    1226,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,     0,     0,     0,     0,  1271,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,     0,     0,  1304,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,     0,     0,     0,     0,  1318,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,  1325,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,     0,     0,  1386,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,     0,     0,  1406,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,  1442,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
       0,     0,  1492,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,  1493,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,     0,
    1494,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,     0,     0,     0,     0,  1497,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,     0,     0,  1542,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,     0,     0,     0,     0,  1618,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,  1919,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,     0,     0,  1930,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,     0,     0,  1973,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,  2047,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
       0,     0,  2063,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,  2078,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,     0,
    2102,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,     0,     0,     0,     0,  2137,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,     0,     0,  2147,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,     0,     0,     0,     0,  2148,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,     0,  2173,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,     0,     0,  2222,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,     0,     0,  2261,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,  2279,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
       0,     0,  2297,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,     0,
       0,  2298,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,     0,   757,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,     0,   979,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,     0,  2040,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,  1049,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,  1094,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,  1250,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,  1319,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
    1321,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,     0,     0,  1328,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   720,   615,   616,   617,   618,     0,     0,     0,     0,
     619,     0,     0,     0,  1329,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   720,   615,
     616,   617,   618,     0,     0,     0,     0,   619,     0,     0,
       0,  1421,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   720,   615,   616,   617,   618,
       0,     0,     0,     0,   619,     0,     0,     0,  1435,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   720,   615,   616,   617,   618,     0,     0,     0,
       0,   619,     0,     0,     0,  1647,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
       0,     0,  1738,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   720,   615,   616,   617,
     618,     0,     0,     0,     0,   619,     0,     0,     0,  1791,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   720,   615,   616,   617,   618,     0,     0,
       0,     0,   619,     0,     0,     0,  1985,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     720,   615,   616,   617,   618,     0,     0,     0,     0,   619,
       0,     0,     0,  2030,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   720,   615,   616,
     617,   618,     0,     0,     0,     0,   619,     0,     0,     0,
    2048,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   835,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     836,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   837,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     839,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   840,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     841,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   843,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     844,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   845,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     846,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   847,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     848,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   849,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     851,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   852,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     853,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,   926,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
     960,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1009,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1026,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1034,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1036,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1037,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1043,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1044,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1082,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1093,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1154,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1158,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1170,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1249,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1259,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1260,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1261,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1270,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1272,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1273,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1303,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1305,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1306,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1307,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1308,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1309,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1310,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1311,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1317,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1331,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1333,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1374,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1420,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1434,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1648,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1684,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1725,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1737,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1854,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1856,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1859,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1866,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1920,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  1929,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    1956,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  2029,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    2099,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  2100,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619,     0,
    2235,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   720,   615,   616,   617,   618,     0,
       0,     0,     0,   619,     0,  2276,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   720,
     615,   616,   617,   618,     0,     0,     0,     0,   619
};

static const yytype_int16 yycheck[] =
{
       3,   328,  1302,   658,   659,  1298,  1501,     3,   149,     4,
       4,  1776,    25,   778,     5,     4,  1822,   163,  1824,   784,
      64,     4,    25,     4,    96,     4,   109,     5,   109,     6,
       6,     4,     6,     4,     4,   145,     4,     6,     4,     6,
       5,     9,     5,  1811,     4,  2009,     7,   166,     6,     4,
     261,     6,   263,    56,     6,     6,     6,     6,     4,   270,
       4,   264,   249,   250,   109,   462,     9,   270,     4,   109,
     112,   149,   114,   258,   259,   194,   154,   155,   156,   266,
       7,   106,    85,     9,   109,   110,   111,   197,    91,   134,
      26,   210,   211,    96,   134,   262,     6,   122,   101,     6,
       9,    37,    38,   270,   249,   250,  1874,   149,   265,   112,
     249,   250,   269,   103,    95,    14,   249,   250,   249,   250,
     249,   250,   200,     9,     0,   270,  1891,   262,   249,   250,
     167,   270,   122,   205,   265,   270,   178,   270,     9,   217,
       6,   270,   184,   215,   249,   250,   149,   109,   103,   270,
       6,   154,   155,   156,   150,     7,   264,   103,   261,     9,
     163,   107,   270,     4,   189,   270,   106,   113,   114,   109,
     116,   117,   249,   250,   106,     7,     6,   109,   261,   111,
     261,   261,   122,   262,   150,   151,   152,   153,   249,   250,
     156,   270,   138,   270,   170,   258,   259,   200,   261,   165,
     263,     7,   205,   169,  2168,     7,   209,   210,   182,   270,
     249,   250,   215,   216,   217,   182,   260,   261,   262,     7,
     249,   250,   106,   261,   205,   109,   623,   249,   250,   249,
     250,   270,   261,   277,     7,  1730,   265,   232,   209,     6,
     312,   313,   314,   232,   106,   249,   250,   109,   270,   111,
     270,   232,   262,   232,     6,    70,    71,   267,    73,   232,
     122,   261,   232,   263,   232,  1558,   270,   244,   245,   263,
     273,   265,  2037,   268,   265,   269,   265,     6,   261,   292,
     352,   353,   354,     6,   265,   288,   265,   265,   291,   292,
     258,   259,   262,   261,   264,   263,   265,   265,   370,   267,
     265,   261,   265,   340,   307,   308,   267,   265,   311,   312,
     313,   314,   261,   265,   265,   265,   265,   261,   261,   322,
     263,     6,   359,   326,   267,   328,   261,   724,  1093,  1094,
    2095,   265,   258,   259,   261,   261,   263,   263,   264,   249,
     250,   267,     6,   184,   185,   186,   187,   350,   263,   352,
     353,   354,   261,   261,   263,   196,     8,   198,   199,   200,
     201,   202,   109,   441,   111,   206,   207,   370,   209,   263,
     373,   267,   258,   259,   270,   261,   261,   263,   244,   245,
     265,   267,   234,   235,   236,   237,   261,   258,   259,   261,
     261,   263,   263,   249,   250,   792,   267,  2203,   267,   436,
     269,   438,   234,   235,   236,   237,   258,   259,   445,   451,
     261,   261,   809,   263,   261,   267,   263,   267,   265,   249,
     250,   567,   819,   249,   250,   266,   258,   259,   234,   235,
     236,   237,   234,   235,   236,   237,   261,     4,   441,   265,
     443,   258,   259,     4,   447,   448,   234,   235,   236,   237,
     267,   261,   258,   259,   249,   250,   258,   259,   261,    26,
     463,   234,   235,   236,   237,    26,   145,   470,     6,   261,
      37,    38,   262,  2238,   264,   270,    37,    38,   249,   250,
     270,     6,     7,   561,   163,   563,   262,   565,   566,   249,
     250,   261,   495,   263,   270,   174,   175,   176,   261,   270,
     262,   180,   181,   581,   582,   261,   578,     4,   270,   103,
     270,   262,   106,   264,     4,   109,   331,   332,   521,   270,
    1175,   249,   250,  2288,   339,   340,   261,   261,   122,    26,
     265,   928,  2027,     4,   249,   250,    26,   261,   249,   250,
      37,    38,   270,   585,   547,   112,   113,    37,    38,   261,
     265,   112,   113,   556,   557,    26,   249,   250,   561,   270,
     563,   564,   565,   566,   567,   261,    37,    38,   266,   265,
     573,   584,   270,   586,   577,   578,   579,   270,   581,   582,
     583,   584,   728,   586,   261,   588,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   249,   250,   265,   262,   260,   264,
     647,   614,   649,   650,   266,   112,   113,   620,   261,   249,
     250,   261,   112,   113,   262,   270,   264,   194,   195,   666,
     124,   261,   270,   194,   195,   265,   262,   778,   264,   642,
     643,   112,   113,   261,   270,   263,   249,   250,   685,   727,
     145,   729,   730,   731,   732,   733,   734,  1312,   736,   737,
     738,   739,   658,   659,   742,   743,   744,   270,   163,   262,
     249,   250,   249,   250,   262,   712,   264,   270,     8,   174,
     175,   176,   270,   109,   262,   180,   181,   262,   691,   692,
     693,   270,   270,   270,     6,   270,   699,   265,  1095,   741,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   721,     4,
     757,     6,   260,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   745,   736,   737,   738,   739,   740,   816,   742,
     743,   744,   745,   746,   262,     3,   749,     8,   145,   827,
     258,   259,   270,   103,   798,     6,   106,   265,   145,   109,
     265,   111,  1527,   111,   767,   265,   163,   254,   255,    27,
     266,   266,   122,   260,   270,   261,   163,   174,   175,   176,
     783,   266,   261,   180,   181,   270,   789,   174,   175,   176,
     265,   109,   834,   180,   181,   249,   250,   251,   252,   253,
     254,   255,   805,   806,   261,    63,   260,   266,   811,   106,
     813,   270,   265,   816,   817,   265,   957,   251,   252,   253,
     254,   255,   825,   261,   827,   263,   260,   150,   151,   267,
     266,   261,   270,   156,   270,   145,  1233,   265,  1235,   150,
     151,   656,   657,   249,   250,   156,   661,   258,   259,   109,
     261,  1248,   263,   163,   857,     6,   859,   266,  1623,   117,
     109,   270,   106,   266,   174,   175,   176,   270,  1633,   266,
     180,   181,   106,   258,   259,    56,   261,     4,   263,   266,
     265,  1278,   266,   266,   266,   266,   270,   270,   270,   270,
     266,   149,  2192,   896,   270,   266,   154,   155,   156,   270,
     266,   109,   266,   906,   270,   163,   270,  1048,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,     4,   930,   970,   266,
     260,  2224,     4,   270,   266,   266,   266,   266,   270,   270,
       4,   270,   200,   946,  1341,     6,   983,  1344,  1345,  2249,
     266,     6,  1093,  1094,   270,   958,   266,   266,   266,   217,
     261,   270,   270,   266,   967,   261,   266,   270,   261,  1110,
     270,   266,  1369,  2266,   263,   270,   979,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,  1392,   266,   261,   263,   260,
     270,   259,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   275,   276,   266,
     266,   260,  1419,   270,   270,   266,   266,     6,   266,   270,
     270,     6,   270,   266,   266,   216,  1433,   270,   270,   265,
     269,   266,   266,  1440,  1122,   270,   270,   266,   266,   266,
     266,   270,   270,   270,   270,  1097,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,  1396,
     266,   266,   266,   260,   270,   270,   270,   266,   266,   269,
     266,   270,   270,   266,   270,  1088,   266,   270,   265,     9,
     270,   266,   273,  1096,   266,   270,   266,   261,   270,   266,
     270,  1104,   262,   270,   264,   265,  1761,  1762,  1249,  1250,
     197,   266,   266,   266,  1117,   270,   270,   270,   266,  1122,
     266,   266,   270,   266,   270,   270,   265,   270,   266,   266,
     311,   266,   270,   270,   197,   270,   261,  1215,  1216,   197,
     262,   322,   264,   265,   261,   326,   261,   261,   261,  1152,
    1153,   261,  1155,  1156,  1157,   261,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,   265,   134,  1171,   261,
     261,   986,   261,   197,     4,   265,   261,   261,   993,  1175,
     261,     6,   997,   441,   261,   265,   265,     6,   261,   265,
     265,   265,   261,   261,   452,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,  1214,  1215,  1216,   261,   260,   474,   261,   261,   261,
       6,     6,   263,     7,     6,   265,   265,   265,   265,   265,
     263,   489,   263,   263,   261,   261,   265,  1240,   197,   261,
     261,   261,   261,   261,   261,     6,     6,   263,     6,     8,
     265,     6,     8,  1256,  1257,  1258,   261,   265,     7,     6,
       6,   265,   265,   265,    98,   266,   447,   448,   262,     7,
     270,   270,     6,     6,  1352,   262,   265,   265,  1356,  1420,
    1421,   265,   463,   265,   265,   265,   260,  1365,    68,  1367,
     267,     8,  1370,     7,     7,   261,     6,   262,     7,  1626,
       6,   265,     7,   561,     6,   563,     6,   565,   566,   567,
    1313,   266,   194,   265,   264,   266,  1312,   266,   262,     6,
     265,   267,     7,   581,   582,     6,   263,   261,     6,  1332,
     265,  1334,  1335,     6,     6,     6,  1151,     6,   262,     7,
     263,     7,     7,  1421,  1347,     7,     7,     7,     7,  1352,
       7,     7,     7,  1356,     7,     7,     7,     7,     7,     7,
     265,     6,  1365,   262,  1367,   267,     8,  1370,   264,   270,
     270,   266,   270,   270,   262,     7,   266,     7,   265,   265,
    1383,     4,     6,   564,   267,   266,   266,   265,  2043,     7,
       6,   145,     7,  1396,     7,     7,   577,   267,   579,   267,
     262,   262,  1444,   270,  1446,   270,   664,     9,   262,   264,
     270,   269,     7,   166,   197,   266,   265,     6,  1421,     6,
       6,    50,    50,  1426,   267,  1428,   261,   265,   261,   265,
     688,  1828,   261,   261,     7,   267,   267,     7,     7,   262,
     197,     6,     8,  1446,   270,     7,     7,     7,   262,   270,
       7,     7,     7,     7,     7,     4,  1459,   121,   265,     6,
    1463,   261,     7,     6,   265,     6,   103,     7,   726,   727,
     728,   729,   730,   731,   732,   733,   734,     7,   736,   737,
     738,   739,  1623,     7,   742,   743,   744,     7,  1634,  1635,
       7,     7,     7,     6,   752,     6,     6,   755,   109,     7,
       7,     6,     6,   761,     7,     7,     4,   270,   270,  1836,
       6,   262,     6,     6,     6,   265,   268,   265,  1521,  1522,
    1523,   265,     7,   266,   263,     6,  1529,  1530,  1531,     6,
     261,   261,     6,   265,     6,     6,     6,   266,     6,   797,
     267,   799,   264,     6,   270,  1548,     6,   138,     6,     6,
       6,     6,     6,     6,     6,     6,  1559,     6,   816,     6,
       6,     6,     5,   266,  1567,  1607,   262,   262,  1571,   827,
       6,     6,     4,     6,  1611,   265,   265,     7,  1615,  1582,
    1658,  1584,     6,   265,     7,   265,   767,   263,   265,     6,
       6,   265,     6,     6,     6,  1736,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,     6,   193,     6,     6,   260,   265,
     262,   265,   264,  1626,   265,   265,   265,  1669,   266,   265,
     265,  1634,  1635,     7,   267,   262,   270,  1640,     6,   270,
     265,   261,     6,     6,   270,   266,   265,     6,   270,     4,
       7,   261,   261,     6,     6,  1658,     6,     6,   145,   107,
       6,     5,   265,     6,   262,   270,  1669,     6,   265,   265,
       6,  1674,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     270,     6,     6,  1839,   260,   145,   262,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,  1757,   145,     6,     6,   260,
       6,     6,   270,   262,   982,     6,   984,   985,  1806,     6,
       6,  1809,   270,   270,   265,     6,   265,     6,     6,     6,
     998,     6,  1557,   265,     7,  1748,   149,     6,     5,   930,
    1753,  1754,     6,   265,     6,  2082,   265,     6,     6,   265,
    1018,   262,  1804,     7,     6,  1761,  1762,   266,   265,  1811,
    1812,   266,   192,  1776,   265,   265,     6,     6,   262,  1782,
     266,     7,  1040,   266,  1787,     6,   967,   266,  1830,     6,
       6,   267,     6,  1796,     6,     6,   265,     6,     6,   266,
       6,   262,     6,  1806,     6,     6,  1809,   195,     6,     6,
       6,     6,   145,     6,     6,     6,     6,   261,     6,     6,
       6,  1079,  1825,   265,   265,   265,  1829,   266,   266,   266,
       6,   262,   266,  1836,     6,  1838,  1839,   265,   265,   265,
     265,   262,     6,   265,     6,     6,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,  1122,   266,   265,     6,   260,   265,
       6,  1874,  1687,     6,   265,     6,     6,     6,     6,     6,
    1432,  2205,  1495,  1682,   492,  2010,  1970,  1744,  1891,  1458,
       3,  1106,     3,     3,     3,   635,  2039,  1604,  1829,     3,
    1903,  1904,     7,     8,  1635,  1811,   816,  1088,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1104,    -1,  1928,    -1,    -1,    -1,    -1,
    1972,    -1,    -1,    -1,    -1,    -1,    -1,  1940,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1958,    -1,  1215,  1216,    -1,
      -1,    -1,  1777,  1778,  1779,  1780,  1781,  1782,    -1,    -1,
      -1,  1152,  1153,  2015,  1155,  1156,  1157,    -1,  1159,  1160,
    1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,    -1,    -1,
      -1,    -1,    -1,  1996,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2011,    -1,
      -1,    -1,    -1,  2016,    -1,  2052,  2019,  2020,    -1,    -1,
      -1,    -1,  1280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1214,  2037,    -1,    -1,  2040,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2043,  2051,    -1,
      -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,  1240,
      -1,    -1,    -1,    -1,  2067,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1256,    -1,    -1,    -1,  2082,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2095,    -1,  1352,    -1,    -1,    -1,  1356,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1365,    -1,  1367,
      -1,    -1,  1370,    -1,    -1,    -1,  2153,    -1,    -1,  1377,
      -1,  2124,    -1,    -1,    -1,    -1,    -1,  2169,    -1,    -1,
      -1,    -1,  1313,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,  1332,    -1,  1334,  1335,   260,  2193,    -1,    -1,    -1,
      -1,    -1,    -1,  1421,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,  2177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2195,  2196,  2197,  2198,  2199,  2275,    -1,     6,
      -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2294,  2295,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2307,
      -1,    -1,    -1,    -1,    -1,  2238,    -1,    -1,    -1,    -1,
      -1,  2056,  2057,  2058,  2059,  2060,    -1,    -1,    -1,    -1,
      -1,  2254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1446,    -1,    -1,    -1,    -1,
      -1,    -1,  2275,    -1,    -1,    -1,    -1,    -1,  1459,    -1,
      -1,    -1,  1463,    -1,    -1,  2288,    -1,    -1,    -1,    -1,
      -1,  2294,  2295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2307,    -1,    -1,    -1,  2123,    -1,
      -1,    -1,  2127,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
    1521,  1522,  1523,    -1,    -1,    -1,    -1,    -1,  1529,  1530,
    1531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2179,     6,    -1,  1548,  2183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1634,  1635,  1559,    -1,
      -1,    -1,    -1,    -1,  2199,    -1,  1567,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1658,  1582,    -1,  1584,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,  2244,
    2245,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,     3,
       4,     5,    -1,   260,    -1,    -1,    10,    11,    12,  1640,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,  1669,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,     6,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    96,    97,     6,    99,    -1,    -1,  1806,    -1,
      -1,  1809,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1822,    -1,  1824,  1748,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1776,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,  1796,  1874,    -1,    -1,   260,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,   108,   260,    -1,  1825,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   121,    -1,    -1,  1838,   212,   213,
     214,   215,   216,    -1,    -1,    -1,    -1,    -1,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,   231,   232,    -1,
      -1,    -1,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,   249,   250,    -1,   165,    -1,
      -1,   168,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,
    1891,   265,    -1,    -1,   268,     6,    -1,    -1,   185,   186,
     187,    -1,   189,   190,   191,    -1,   193,   194,   195,   196,
     197,   198,   199,    -1,   201,   202,   203,   204,    -1,    -1,
      -1,    -1,   209,   210,    -1,    -1,    -1,  1928,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1996,    -1,    -1,    -1,    -1,
     287,   288,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,
    2011,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,
     307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2037,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,   335,    -1,
    2051,    -1,    -1,   340,    -1,    -1,    -1,    -1,  2136,    -1,
      -1,    -1,    -1,   350,   351,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,   372,   373,   260,    -1,    -1,
      -1,    -1,    -1,    -1,  2095,    -1,   383,    -1,   385,   386,
      -1,   388,    -1,    -1,    -1,   392,   393,   394,    -1,    -1,
     397,    -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2124,    -1,  2203,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,  2225,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,   443,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,   461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     497,    -1,    -1,    -1,    -1,   502,  2294,  2295,    -1,   506,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2307,
      -1,    -1,    -1,   520,   521,    -1,    -1,  2238,    -1,   526,
      -1,    -1,    -1,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,    -1,   559,   560,    -1,   562,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   572,    -1,  2288,   575,   576,
      -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,
      -1,   588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,   619,    -1,   621,   622,    -1,    -1,    -1,    -1,
      -1,    -1,   629,   630,   631,    -1,    -1,    -1,    -1,    -1,
     637,   638,   639,   640,    -1,   642,   643,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   661,   662,   663,    -1,    -1,    -1,
     667,   668,   669,   670,   671,   672,   673,   674,   675,    -1,
      -1,    -1,    -1,    -1,   681,   682,    -1,   684,    -1,    -1,
     687,    -1,    -1,    -1,   691,   692,   693,   694,    -1,    -1,
      -1,   698,   699,   700,   701,   702,    -1,    -1,   705,    -1,
     707,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     717,    -1,    -1,   720,    -1,   722,   723,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   735,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   749,    -1,    -1,    -1,    -1,    -1,    -1,   756,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   764,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   783,    -1,   785,    -1,
     260,    -1,   262,   790,   791,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   805,    -1,
     807,   808,    -1,    -1,   811,    -1,   813,   814,    -1,    -1,
      -1,   818,    -1,   820,    -1,   822,    -1,     4,     5,    -1,
      -1,   828,    -1,    -1,    -1,   832,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,   855,   260,
     857,    -1,   859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,   896,
      -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,   906,
     907,   908,   909,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,   918,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,
     209,   210,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   946,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   958,    -1,    -1,   141,    -1,    -1,    -1,    -1,   966,
      -1,    -1,    -1,   970,    -1,    -1,    -1,    -1,    -1,   976,
      -1,    -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     987,   988,    -1,    -1,    -1,    -1,   993,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1010,    -1,    -1,  1013,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,   308,
       6,    -1,    -1,    -1,    -1,    -1,   213,   214,   215,    -1,
      -1,    -1,  1039,    -1,  1041,  1042,    -1,    -1,   225,    -1,
      -1,    -1,   229,    -1,   231,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1064,    -1,    -1,
      -1,   350,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
     288,   258,   259,   291,     8,    -1,    -1,  1084,   265,    -1,
     267,    -1,    -1,    -1,  1091,    -1,    -1,    -1,    -1,   307,
     308,  1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1111,  1112,    -1,    -1,    -1,    -1,
    1117,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      -1,    -1,   350,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,  1149,    80,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   373,    -1,    -1,    -1,    96,
      -1,    -1,    99,    -1,  1171,    -1,   103,    -1,    -1,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1190,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1200,  1201,  1202,  1203,  1204,    -1,    -1,
      -1,    -1,  1209,  1210,   141,  1212,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1228,  1229,    -1,    -1,   443,    -1,    -1,    -1,  1236,
    1237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1245,  1246,
      -1,    -1,    -1,    -1,  1251,  1252,    -1,    -1,    -1,    -1,
    1257,  1258,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,   213,   214,   215,    -1,
      -1,    -1,    -1,    -1,    -1,  1292,    -1,    -1,   225,    -1,
      -1,    -1,   229,    -1,   231,   232,    -1,    -1,    -1,   588,
      -1,    -1,    -1,   521,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,  1330,    -1,   262,   260,   264,   265,   547,
      -1,    -1,    -1,    -1,    -1,  1342,  1343,    -1,   556,   557,
    1347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,
      -1,    -1,    -1,   642,   643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,
     588,    -1,  1379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1390,    -1,    -1,  1393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,    -1,
      -1,    -1,   691,   692,   693,    -1,    -1,    -1,    -1,    -1,
     699,    -1,    -1,    -1,    -1,  1422,    -1,    -1,  1425,  1426,
    1427,  1428,    -1,    -1,   642,   643,    -1,    -1,    -1,  1436,
      -1,    -1,  1439,    -1,  1441,    -1,  1443,  1444,    -1,    -1,
    1447,  1448,  1449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
     749,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   691,   692,   693,    -1,    -1,    -1,    -1,
      -1,   699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   783,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    -1,    -1,    -1,   805,    71,    72,    73,
      74,  1528,   811,    -1,   813,    -1,    80,    -1,    82,    -1,
      -1,   749,  1539,  1540,  1541,    -1,    -1,    -1,    -1,    -1,
      -1,  1548,    96,  1550,    -1,    99,    -1,    -1,    -1,    -1,
    1557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1571,   783,    -1,    -1,    -1,    -1,
    1577,  1578,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1588,  1589,  1590,    -1,    -1,    -1,   805,    -1,    -1,
      -1,    -1,  1599,   811,    -1,   813,    -1,    -1,    -1,    -1,
      -1,    -1,  1609,    -1,    -1,    -1,    -1,   896,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   906,    -1,    -1,
      -1,    -1,    -1,  1630,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1638,  1639,     7,    -1,    -1,    -1,    -1,    -1,   857,
      -1,   859,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   946,    -1,   213,
     214,   215,    -1,    -1,    -1,    -1,    -1,  1674,    -1,   958,
      -1,   225,    -1,    -1,    -1,   229,    -1,   231,   896,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   906,    -1,
     979,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
    1717,  1718,  1719,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1728,    -1,    -1,    -1,    -1,  1733,  1734,   946,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1746,
     958,    -1,    -1,    -1,    -1,    -1,  1753,  1754,  1755,    -1,
    1757,    -1,    -1,    -1,    -1,    -1,  1763,  1764,     8,    -1,
      -1,   979,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1782,    -1,    -1,    -1,    -1,
    1787,  1788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1800,  1801,    -1,    -1,  1804,    -1,    -1,
    1807,    -1,    -1,    -1,  1811,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1821,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1831,    -1,    -1,    -1,  1117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1845,    -1,
      -1,    -1,    -1,  1850,  1851,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1864,    -1,    -1,
    1867,  1868,    -1,  1870,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,  1171,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1903,  1904,    -1,  1117,
      -1,    -1,    -1,  1910,  1911,    -1,    -1,    -1,    -1,   465,
      -1,    -1,    -1,    -1,    -1,  1922,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1931,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1940,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1953,  1954,    -1,    -1,
    1957,  1958,    -1,  1171,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1257,  1258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,  1993,  1994,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,  2014,    -1,    -1,
     260,    -1,  2019,  2020,  2021,    -1,    -1,   573,    -1,  2026,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,  2040,    -1,    -1,    -1,    -1,    -1,  1257,
    1258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2055,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2064,  1347,    -1,
    2067,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,  2092,    -1,    63,    64,    65,
      66,  2098,    -1,    -1,  2101,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    99,    -1,  2132,    -1,   103,    -1,  1347,
     106,    -1,    -1,   109,    -1,   111,    -1,  1426,    -1,  1428,
      -1,    -1,     6,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,  2159,  2160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,  2174,  2175,     6,
    2177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2190,    -1,    -1,    -1,    -1,  2195,  2196,
    2197,  2198,  2199,     6,    -1,    -1,    -1,    -1,  2205,    -1,
      -1,    -1,  2209,    -1,    -1,    -1,    -1,    -1,  1426,    -1,
    1428,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,  2236,
      -1,    -1,    -1,   260,  2241,  2242,     6,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2254,    -1,   225,
      -1,    -1,    -1,   229,    -1,   231,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2281,  2282,    -1,    -1,    -1,    -1,
      -1,    -1,  1571,     6,    -1,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,
     866,   867,   868,   869,   870,   871,   872,   873,   874,   875,
     876,    -1,   878,   879,   880,   881,    -1,   883,   884,   885,
     886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,   899,    -1,   901,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1571,    -1,    -1,   912,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   920,   921,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   929,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      26,    -1,    28,   260,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1674,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1753,  1754,    -1,     6,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,  1050,  1051,  1052,    -1,  1787,    -1,
    1056,  1057,    -1,    -1,  1060,  1061,  1062,  1063,    -1,  1065,
      -1,    -1,    -1,    -1,  1070,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,  1753,  1754,   260,    -1,    -1,
      -1,    -1,    -1,   149,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,  1782,    -1,   260,    -1,   262,  1787,
     264,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,  1148,   260,  1150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1903,  1904,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
     256,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   267,    -1,    13,    14,    -1,    -1,    -1,    -1,  1958,
      -1,    -1,    -1,   279,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1903,  1904,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1254,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,  1940,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2019,  2020,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2040,    -1,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,  2055,     8,    -1,   119,
     120,   121,   122,    -1,    -1,   125,    -1,    -1,  2067,    -1,
      -1,    -1,    -1,    -1,   134,   135,    -1,    -1,   138,   139,
     396,   141,   142,    -1,   144,    -1,    -1,   403,   404,   405,
      -1,  2019,  2020,   409,   410,   411,   412,   413,   414,   415,
      -1,   417,   162,    -1,    -1,    -1,   422,   423,     8,    -1,
     426,    -1,  2040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2055,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,  1402,    -1,    -1,  2067,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,   262,    -1,   264,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,  2177,  1445,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2195,  2196,  2197,  2198,
    2199,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,  1478,  1479,  1480,  1481,  1482,  1483,  1484,    -1,
      -1,    -1,    -1,  1489,  1490,    -1,    -1,    -1,    -1,    -1,
    1496,    -1,    -1,  1499,    -1,    -1,    -1,  1503,    -1,    -1,
    1506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2177,
      -1,  1517,    -1,    -1,    -1,  2254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2195,  2196,  2197,
    2198,  2199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     596,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2254,    -1,    -1,  1595,
      -1,  1597,    -1,    -1,    -1,  1601,    -1,  1603,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1634,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    77,    78,    79,    80,    -1,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    -1,    99,    -1,  1735,
      -1,   103,    -1,    -1,   106,     8,    -1,   109,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,   136,   137,    -1,   139,    -1,   141,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1841,    -1,    -1,  1844,    -1,
     212,   213,   214,   215,   216,   217,    -1,    -1,    -1,    -1,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   924,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,    -1,
      -1,    -1,    -1,    -1,   256,    -1,    -1,  1893,  1894,   261,
    1896,    -1,    -1,   265,    -1,    -1,   268,    -1,    -1,    -1,
      -1,   957,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,    -1,    -1,
     138,   139,    -1,   141,   142,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1963,  1964,    -1,
      -1,    -1,    -1,    -1,   162,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,   189,   190,   191,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,  2012,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,   266,    -1,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1142,    94,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,   103,    -1,    -1,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,   136,
     137,    -1,   139,    -1,   141,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,  1241,   260,   194,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,   222,   223,   224,   225,   226,
     227,   228,   229,    -1,   231,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,  2263,   265,    -1,
      -1,   268,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    13,    14,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,  1403,  1404,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,    -1,
      -1,    -1,   103,    -1,    -1,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     141,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,   270,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,   134,   135,
      -1,    -1,   138,   139,  1510,   141,   142,    -1,   144,    -1,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,   215,   216,   162,    -1,    -1,    -1,
      -1,   222,   223,   224,   225,   226,   227,   228,   229,    -1,
     231,   232,    -1,   234,   235,   236,   237,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,    -1,    -1,   249,   250,
      -1,    -1,    -1,    -1,    -1,   256,    -1,   258,   259,    -1,
     261,    -1,   263,    -1,    -1,    -1,   267,   268,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    59,    60,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,  1673,    -1,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,   106,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,   136,   137,    -1,   139,    -1,   141,    -1,    -1,   144,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,   194,
      -1,    -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
      -1,   216,   217,    -1,    -1,    -1,    -1,   222,   223,   224,
      -1,   226,   227,   228,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,
     265,    -1,     8,   268,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   118,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
     136,   137,    -1,   139,    -1,   141,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
      -1,    -1,    -1,   169,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,   194,    -1,
      -1,    -1,   266,    -1,    -1,    -1,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
     216,   217,    -1,    -1,    -1,    -1,   222,   223,   224,    -1,
     226,   227,   228,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,   261,     3,     4,     5,    -1,
     266,    -1,   268,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,   118,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,   136,
     137,    -1,   139,    -1,   141,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,    -1,
      -1,    -1,   169,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,    -1,   222,   223,   224,    -1,   226,
     227,   228,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,   261,     3,     4,    -1,   265,    -1,
      -1,   268,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     118,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,   136,   137,
      -1,   139,    -1,   141,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,
      -1,   169,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   216,   217,
      -1,    -1,    -1,    -1,   222,   223,   224,    -1,   226,   227,
     228,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   261,     3,     4,    -1,   265,   266,    -1,
     268,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,   136,   137,    -1,
     139,    -1,   141,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,   216,   217,    -1,
      -1,    -1,    -1,   222,   223,   224,    -1,   226,   227,   228,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,   261,     3,     4,    -1,   265,    -1,    -1,   268,
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
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,   136,   137,    -1,   139,
      -1,   141,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,   216,   217,    -1,    -1,
      -1,    -1,   222,   223,   224,    -1,   226,   227,   228,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,     3,     4,    -1,   265,    -1,    -1,   268,    10,
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
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,    -1,   136,   137,    -1,   139,    -1,
     141,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,
      -1,   222,   223,   224,    -1,   226,   227,   228,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
     261,     3,     4,    -1,   265,    -1,    -1,   268,    10,    11,
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
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,   136,   137,    -1,   139,    -1,   141,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,    -1,    -1,    -1,   169,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,    -1,
     222,   223,   224,    -1,   226,   227,   228,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,    -1,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,   261,
       3,     4,    -1,    -1,   266,    -1,   268,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,   136,   137,    -1,   139,    -1,   141,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,   161,    -1,
      -1,    -1,   165,    -1,    -1,    -1,   169,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,    -1,   216,   217,    -1,    -1,    -1,    -1,   222,
     223,   224,    -1,   226,   227,   228,    -1,    -1,    -1,   232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,   250,    -1,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,   261,     3,
       4,    -1,   265,    -1,    -1,   268,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    -1,   136,   137,    -1,   139,    -1,   141,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,   161,    -1,    -1,
      -1,   165,    -1,    -1,    -1,   169,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,   216,   217,    -1,    -1,    -1,    -1,   222,   223,
     224,    -1,   226,   227,   228,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,   261,     3,     4,
      -1,   265,    -1,    -1,   268,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    -1,   118,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
      -1,   136,   137,    -1,   139,    -1,   141,    -1,    -1,   144,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,    -1,    -1,    -1,   169,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,   194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
      -1,   216,   217,    -1,    -1,    -1,    -1,   222,   223,   224,
      -1,   226,   227,   228,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,   261,     3,     4,    -1,
     265,    -1,     8,   268,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   118,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,
     136,   137,    -1,   139,    -1,   141,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
      -1,    -1,    -1,   169,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
     216,   217,    -1,    -1,    -1,    -1,   222,   223,   224,    -1,
     226,   227,   228,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,    -1,    -1,    -1,    -1,    -1,
     256,     3,     4,    -1,    -1,   261,     8,    -1,    10,    11,
      12,    -1,   268,    15,    16,    17,    18,    19,    20,    21,
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
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,   136,   137,    -1,   139,    -1,   141,
      -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,   161,
      -1,    -1,    -1,   165,    -1,    -1,    -1,   169,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,    -1,
     222,   223,   224,    -1,   226,   227,   228,    -1,    -1,    -1,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,    -1,
      -1,    -1,    -1,    -1,   256,     3,     4,    -1,    -1,   261,
      -1,    -1,    10,    11,    12,    -1,   268,    15,    16,    17,
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
     118,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,    -1,   136,   137,
      -1,   139,    -1,   141,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,
      -1,   169,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   216,   217,
      -1,    -1,    -1,    -1,   222,   223,   224,    -1,   226,   227,
     228,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   261,     3,     4,    -1,   265,    -1,    -1,
     268,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,   136,   137,    -1,
     139,    -1,   141,    -1,    -1,   144,    -1,    -1,    -1,    -1,
      -1,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,
     169,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   194,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,   216,   217,    -1,
      -1,    -1,    -1,   222,   223,   224,    -1,   226,   227,   228,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,   261,     3,     4,    -1,   265,    -1,    -1,   268,
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
      -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,   136,   137,    -1,   139,
      -1,   141,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,   216,   217,    -1,    -1,
      -1,    -1,   222,   223,   224,    -1,   226,   227,   228,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,     3,     4,    -1,    -1,   266,    -1,   268,    10,
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
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,    -1,   136,   137,    -1,   139,    -1,
     141,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
     161,    -1,    -1,    -1,   165,    -1,    -1,    -1,   169,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,   216,   217,    -1,    -1,    -1,
      -1,   222,   223,   224,    -1,   226,   227,   228,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
      -1,    -1,    -1,    -1,    -1,   256,     3,     4,     5,    -1,
     261,    -1,    -1,    10,    11,    12,    -1,   268,    15,    16,
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
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,    -1,   222,   223,   224,   225,   226,
     227,   228,   229,    -1,   231,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,   265,    -1,
      -1,   268,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,   222,   223,   224,   225,   226,   227,   228,   229,
      -1,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,     3,     4,     5,   265,    -1,    -1,   268,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    -1,    99,     3,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
      -1,   222,   223,   224,   225,   226,   227,   228,   229,    -1,
     231,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
      -1,    -1,    -1,    -1,    -1,   256,    -1,     3,     4,    -1,
     261,    -1,    -1,    -1,    10,    11,    12,   268,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,   216,    59,    60,    61,    62,    -1,   222,   223,
     224,    67,   226,   227,   228,    -1,    -1,    -1,   232,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,   249,   250,    -1,    94,    95,
      -1,    97,   256,     3,     4,    -1,    -1,   261,    -1,    -1,
      10,    11,    12,    -1,   268,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    83,    84,    85,   119,   120,   121,   122,
      -1,    -1,   125,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,   134,   135,    -1,    -1,   138,   139,    -1,   141,   142,
      -1,   144,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,   222,   223,   224,   162,
     226,   227,   228,    -1,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,    -1,   189,   190,   191,    -1,
     256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,   265,
      -1,    -1,   268,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,   222,   223,   224,    -1,   226,   227,   228,    -1,
      -1,    -1,   232,   266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,     3,     4,    -1,   265,    -1,     8,   268,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    94,    95,    -1,    97,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      83,    84,    85,   119,   120,   121,   122,    -1,    -1,   125,
      -1,    94,    95,    -1,    97,    -1,    -1,    -1,   134,   135,
      -1,    -1,   138,   139,    -1,   141,   142,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,   216,   162,    -1,    -1,    -1,
      -1,   222,   223,   224,    -1,   226,   227,   228,    -1,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,    -1,    -1,   249,   250,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,   268,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     270,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,   222,
     223,   224,    -1,   226,   227,   228,    -1,    -1,    -1,   232,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,   250,    -1,    -1,
      -1,    -1,    -1,   256,     3,     4,    -1,     6,   261,   262,
      -1,    10,    11,    12,    -1,   268,    15,    16,    17,    18,
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
      94,    95,    -1,    97,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   212,    -1,    -1,   260,   216,    -1,    -1,
      -1,    -1,    -1,   222,   223,   224,   270,   226,   227,   228,
      -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,   222,   223,
     224,    -1,   226,   227,   228,    -1,    -1,    -1,   232,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,   250,    -1,    -1,    -1,
      -1,    -1,   256,     3,     4,    -1,     6,   261,    -1,    -1,
      10,    11,    12,    -1,   268,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    94,    95,    -1,    97,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    83,    84,    85,   119,   120,   121,   122,    -1,    -1,
     125,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,   134,
     135,    -1,    -1,   138,   139,    -1,   141,   142,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,    -1,    -1,    -1,   216,   162,    -1,    -1,
      -1,    -1,   222,   223,   224,    -1,   226,   227,   228,    -1,
      -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,   268,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,   270,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
     222,   223,   224,    -1,   226,   227,   228,    -1,    -1,    -1,
     232,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,    -1,
      -1,    -1,    -1,    -1,   256,     3,     4,    -1,    -1,   261,
     262,    -1,    10,    11,    12,    -1,   268,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    94,    95,    -1,    97,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    83,    84,    85,   119,   120,   121,   122,
      -1,    -1,   125,    -1,    94,    95,    -1,    97,    -1,    -1,
      -1,   134,   135,    -1,    -1,   138,   139,    -1,   141,   142,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   216,   162,
      -1,    -1,    -1,    -1,   222,   223,   224,    -1,   226,   227,
     228,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,    -1,
      -1,   249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   261,   262,    -1,    -1,    -1,    -1,    -1,
     268,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   270,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,   222,   223,   224,    -1,   226,   227,   228,    -1,
      -1,    -1,   232,   266,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,     3,     4,    -1,   265,    -1,    -1,   268,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    83,    84,    85,   119,   120,   121,   122,    -1,
      -1,   125,    -1,    94,    95,    -1,    97,    -1,    -1,    -1,
     134,   135,    -1,    -1,   138,   139,    -1,   141,   142,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    13,    14,    -1,   119,   120,   121,
     122,    -1,    -1,   125,    -1,   189,   190,   191,    -1,    -1,
      -1,    -1,   134,   135,    -1,    -1,   138,   139,    -1,   141,
     142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,   212,    -1,    -1,    -1,   216,    -1,   189,   190,   191,
      -1,   222,   223,   224,    -1,   226,   227,   228,    -1,    -1,
      -1,   232,   266,    -1,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,   249,   250,
     119,   120,   121,   122,    -1,   256,   125,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,   134,   135,   268,    -1,   138,
     139,    -1,   141,   142,    -1,   144,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   266,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    -1,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,   125,    -1,    -1,
     189,   190,   191,    -1,    -1,    -1,   134,   135,    -1,    -1,
     138,   139,    -1,   141,   142,    -1,   144,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   189,   190,   191,   119,   120,   121,   122,    -1,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,   134,
     135,    13,    14,   138,   139,    -1,   141,   142,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    -1,    -1,    -1,   119,   120,   121,   122,    -1,    -1,
     125,    -1,    -1,    -1,   189,   190,   191,    -1,   266,   134,
     135,    13,    14,   138,   139,    -1,   141,   142,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,    -1,   125,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,   134,   135,    -1,    -1,   138,   139,    -1,   141,
     142,   266,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    -1,    -1,    -1,   119,   120,   121,
     122,    -1,    -1,   125,    -1,    -1,    -1,   189,   190,   191,
      -1,    -1,   134,   135,    -1,    -1,   138,   139,    -1,   141,
     142,   266,   144,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    13,    14,    -1,    -1,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,   189,   190,   191,
     260,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
     270,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   266,    -1,   118,   119,   120,   121,
     122,   123,    -1,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,     4,    -1,    -1,    -1,    -1,   218,   219,   220,   221,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     232,   233,    -1,    -1,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    47,    48,    49,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,   118,   119,   120,   121,   122,
     123,    -1,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,   188,   189,   190,   191,     4,
       5,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,   232,
     233,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,     4,     5,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,    -1,   103,    -1,
       5,   106,    -1,    -1,   109,    -1,   111,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   122,    -1,    -1,
      -1,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,   141,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    96,    -1,    -1,    99,    63,    64,
      65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
     215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,   229,    -1,   231,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,   213,   214,   215,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,   229,    -1,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
     215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,    -1,    -1,   229,    -1,   231,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      13,    14,    -1,   119,   120,   121,   122,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
      -1,    -1,   138,   139,    -1,   141,   142,    -1,   144,    -1,
      -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
     166,    -1,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,   189,   190,   191,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,    -1,    -1,   119,   120,   121,   122,
      -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,    -1,    -1,   138,   139,    -1,   141,   142,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,   189,   190,   191,    -1,
      -1,    -1,   270,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   270,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   270,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   270,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,   266,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,   266,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,   266,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
     266,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,   266,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,   266,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,   266,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,   266,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,   266,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
     266,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,   266,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,   266,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,   266,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,   266,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,   266,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
     266,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,   266,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,   266,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,   266,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,   266,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,   266,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,   266,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,   266,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,   265,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,   265,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,   265,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,   264,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,   264,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,   264,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
     264,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,   264,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,   264,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,   264,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,   264,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,   264,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,   264,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,   264,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
     264,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
     262,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,    -1,
      -1,    -1,    -1,   260,    -1,   262,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   272,   273,     6,     0,     4,    13,    14,    47,
      48,    49,    68,    69,    70,    75,    76,    81,    86,    87,
      88,    89,    90,    92,    93,    95,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   118,   119,   120,   121,   122,   123,   125,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   146,   147,   148,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   177,   178,   179,   183,   188,   189,   190,
     191,   194,   196,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   218,   219,   220,
     221,   230,   232,   233,   274,   276,   277,   298,   317,   319,
     323,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     341,   343,   344,   350,   351,   352,   353,   359,   384,   385,
     265,   269,    14,   109,   261,   261,   261,     6,   265,     6,
       6,     6,     6,   261,     6,   265,     6,   265,   265,     6,
       6,   263,   263,     4,   361,   385,   261,   263,   295,   103,
     106,   109,   111,   319,   295,   261,   261,   261,     4,   261,
     261,   261,     4,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   265,   124,   109,     6,     6,   265,
     265,   103,   106,   109,   122,   322,   111,   261,     3,    10,
      11,    12,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    59,    60,    61,    62,    67,    68,
      77,    78,    79,    83,    84,    85,    94,    97,   103,   106,
     109,   111,   122,   134,   139,   141,   144,   194,   212,   216,
     217,   222,   223,   224,   226,   227,   228,   249,   250,   256,
     261,   265,   268,   319,   320,   323,   334,   341,   343,   354,
     355,   359,   361,   367,   370,   385,   261,   265,   265,   109,
     109,   134,   106,   109,   111,   319,   106,   109,   110,   111,
     122,   189,   320,   106,   109,   261,   106,   166,   194,   210,
     211,   265,   249,   250,   261,   265,   364,   365,   364,   265,
     265,   364,     4,   103,   107,   113,   114,   116,   117,   138,
     265,   261,   109,   111,   109,   106,     4,    95,   205,   265,
     385,     4,     6,   103,     6,   106,   109,   106,   109,   122,
     321,     5,   261,   265,   367,   369,   109,     4,     4,     4,
     369,     4,   109,   261,   109,   261,   261,     4,   265,   372,
     385,     4,   261,   261,   261,     6,    33,   250,   354,   385,
       6,   263,     5,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    63,    64,    65,    66,    71,    72,    73,    74,
      80,    82,    96,    99,   213,   214,   215,   225,   229,   231,
     376,   385,   261,     4,   376,     5,   265,     5,   265,   319,
     354,   263,     6,   265,   261,   265,     6,   261,   265,     6,
     269,     7,   141,   205,   234,   235,   236,   237,   258,   259,
     261,   263,   267,   293,   294,   295,   319,   354,   375,   376,
     385,     4,   323,   324,   325,   265,     6,   354,   375,   376,
     385,   375,   375,   354,   375,   382,   383,   385,   354,   325,
     354,   300,   304,   261,   363,     9,   376,   261,   376,   354,
     354,   354,   261,   354,   354,   354,   261,   354,   354,   354,
     354,   354,   354,   354,   375,   354,   354,   354,   354,   369,
     261,   250,   354,   370,   371,   371,   265,   369,   367,   375,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   261,   263,   295,   295,
     295,   295,   295,   295,   261,   295,   295,   261,   319,   320,
     320,   320,   295,   295,     5,   265,   265,   134,   319,   319,
     320,   261,   295,   295,   261,   261,   261,   354,   265,   354,
     370,   354,   354,   266,   371,   361,   385,   197,     5,   265,
       8,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   260,
       9,   261,   263,   267,   294,   295,   354,   371,   371,   261,
     261,   261,   367,   369,   369,   369,   318,   261,   265,   261,
     261,   367,   265,   265,   354,     4,   367,   265,   372,   265,
     265,   364,   364,   364,   354,   354,   249,   250,   265,   265,
     364,   249,   250,   261,   325,   364,   265,   261,   265,   261,
     261,   261,   261,   261,   261,   261,   371,   354,   369,   369,
     369,   261,   265,     4,   263,   265,     6,   263,   325,     6,
       6,   265,   265,   265,   265,   369,   354,     8,     7,   265,
     263,   263,   263,     6,     6,   261,   354,   261,   354,   354,
     267,   354,   265,   197,   354,   354,   354,   295,   354,     6,
     251,     9,   261,   263,   267,   354,   295,   295,   295,   261,
     261,   261,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   261,   261,   295,   261,   263,     6,     6,   265,
       6,     8,   325,     6,     8,   325,   261,   265,   375,   371,
     354,   325,   367,   367,   265,   376,   319,     7,   354,   354,
       4,    26,    37,    38,   112,   113,   194,   195,   297,   367,
       6,   262,   264,   265,   296,   265,     6,   265,     6,     9,
     261,   263,   267,   385,   266,   134,   139,   141,   142,   144,
     317,   319,   354,     6,   262,   270,     9,   261,   263,   267,
     262,   270,   262,   270,   270,   262,   270,     9,   261,   267,
     270,   266,   270,   264,   270,   299,   264,   299,    98,   362,
     360,   385,   270,   354,   270,   262,   262,   262,   354,   262,
     262,   262,   354,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   266,     7,   354,   251,   266,   270,
     266,   354,     6,     6,   262,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   370,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   370,   370,   385,   265,   354,   354,   375,
     354,   375,   367,   375,   375,   382,   265,   265,   265,   265,
     354,   296,   385,     8,   354,   354,   369,   367,   265,   375,
     375,   370,   361,   376,   361,   371,   262,   266,   267,   295,
      68,     8,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   265,   354,   370,   354,
     354,   354,   354,   354,   385,   354,   354,   297,   265,   296,
     262,   266,   266,   354,   354,   354,     7,     7,   347,   347,
     261,   354,   354,   354,   354,     6,   170,   371,   371,   265,
     262,     6,   325,   265,   325,   325,   270,   270,   270,   364,
     364,   324,   324,   270,   354,   266,   338,   270,   325,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   266,   262,
       7,   348,     6,     7,   354,   354,     6,   354,   325,   354,
     266,   371,   371,   371,   354,     6,   262,   266,   354,   371,
     354,   354,   354,   354,   262,   354,   262,   262,   194,   270,
     325,   265,     8,   262,   262,   354,   354,   385,   297,   264,
     382,   375,   382,   375,   375,   375,   375,   375,   375,   354,
     375,   375,   375,   375,   268,   378,   385,   376,   375,   375,
     375,   361,   385,   371,   266,   266,   266,   266,   354,   325,
     264,   266,   262,   148,   166,   342,   262,   266,   270,   354,
       6,   265,   367,   262,   264,   267,     7,     7,   293,   294,
       6,   371,     7,   237,   293,   354,   278,   385,   354,   354,
     297,   263,   261,   134,   319,   320,   319,   265,   266,     6,
     244,   245,   275,   371,   385,   354,   354,   297,     6,   371,
       6,   371,   354,     6,   375,   383,   385,   262,   297,   354,
     354,     6,   385,     6,   375,   354,   262,   263,   354,   270,
     376,     7,     7,     7,   262,     7,     7,     7,   262,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   354,
     262,   265,   354,   370,     6,   265,   266,     6,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     270,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     270,   270,   270,   270,   270,   262,   264,   264,   371,   270,
     270,   296,   270,   296,   270,   270,   270,   262,   371,   354,
     354,   354,   356,   296,   266,   266,   266,   354,   270,   270,
     296,   296,   262,   267,   262,   267,   270,   295,   357,   266,
       7,   297,   296,   367,   266,     8,     8,   371,   267,   262,
     264,   261,   263,   294,   295,   371,     7,   265,   265,   262,
     262,   262,   354,   367,     4,   346,     6,   313,   354,   376,
     262,   266,   262,   262,   354,   266,   266,   371,   267,   266,
     325,   266,   266,   364,   354,   354,   266,   266,   354,   364,
     145,   145,   163,   174,   175,   176,   180,   181,   339,   340,
     364,   266,   335,   262,   266,   262,   262,   262,   262,   262,
     262,   262,   265,     7,   354,     6,   354,   262,   266,   264,
     266,   264,   266,   266,   266,   266,     6,   266,   264,   264,
     270,   262,     7,   262,     7,     7,   267,   354,   266,   354,
     354,   267,   261,   263,     7,   267,   296,   270,   296,   296,
     262,   262,   270,   296,   296,   270,   270,   296,   296,   296,
     296,   354,   296,     9,   377,   270,   262,   270,   296,   267,
     270,   358,   264,   266,   262,   266,   269,   197,     7,   166,
       6,   354,   266,   265,     6,   367,   266,   354,     6,     7,
     293,   294,   267,   293,   294,   297,   265,   373,   385,   376,
     354,     6,   266,    50,    50,   367,   266,     4,   184,   185,
     186,   187,   266,   281,   285,   288,   290,   291,   333,   267,
     262,   264,   261,   354,   354,   261,   265,   261,   265,     8,
     371,   375,   262,   267,   262,   264,   261,   262,   262,   270,
     267,   261,   266,   270,     7,   295,     4,    26,    37,    38,
     307,   308,   309,   296,   354,   296,   364,   367,   367,     7,
     367,   367,   367,     7,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,     6,     7,   371,   324,   354,   354,
     354,   354,   354,   354,   266,   354,   354,   354,   367,   375,
     375,   266,   266,   266,   266,   270,   306,   266,   354,   354,
     297,   297,   354,   354,   262,   367,   295,   354,   354,   266,
     297,   294,   267,   294,   354,   354,   296,   266,   367,   371,
     371,     7,     7,     7,   145,   345,     6,   262,   270,     7,
       7,     7,     6,     7,     7,   266,     4,   297,   266,   270,
     270,   270,   266,   266,   121,     4,     6,   354,   265,     6,
     261,     6,   182,     6,   182,   266,   340,   270,   339,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   324,   367,
       6,   265,   103,     6,     6,     6,   109,     7,     7,     6,
       6,   354,     7,   367,     7,   367,   367,     4,   270,     8,
       8,   262,   297,   297,   297,   371,   375,   354,   375,   268,
     270,   310,   375,   375,   297,   375,   262,   270,     6,   265,
     319,   265,     6,   354,     6,   265,   367,   266,   266,   354,
       6,   194,   195,   297,   354,     6,     7,   372,   374,     6,
     263,     6,     6,   296,   295,   295,     6,   282,   261,   261,
     265,   292,     6,   297,   267,   375,   354,   264,   262,   354,
       8,   371,   354,   371,   266,   266,     6,     6,   275,   297,
     267,   354,     6,     6,   354,   297,   262,     6,   354,   265,
     354,   376,   296,    50,   265,   367,   376,   379,   354,   354,
     354,   264,   270,     6,   262,     6,     6,   138,   315,   315,
     367,     6,     6,     6,   367,   145,   197,   314,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   266,   266,
     296,   296,   296,   296,   296,   296,   296,   270,   270,   270,
     262,   296,   296,   308,   296,   262,   296,   262,   295,   357,
     296,     6,   296,   261,   263,   295,   297,   262,   264,   296,
       6,   266,   266,   367,   367,   367,     4,     6,   293,   354,
     367,   367,   367,   265,   265,     7,     6,     7,   354,   354,
     354,   265,   265,   265,   263,     6,   354,   367,   354,     6,
       6,   354,   364,   266,     5,   367,   265,   265,   265,   265,
     265,   265,   265,   367,   266,     6,   371,   265,   265,   354,
     354,   264,   367,     6,   367,     6,   193,   354,   354,   354,
     261,   263,     6,     6,     7,   296,   270,   270,   296,   270,
     354,     4,   209,   311,   312,   296,   262,   296,   358,   376,
     354,   265,   325,     6,   325,   270,     6,     6,   267,     7,
       7,   293,   294,     6,   372,   266,   270,   354,   293,   265,
     296,   380,   381,   382,   380,   261,   354,   354,   366,   367,
     265,   261,     4,     6,   262,     6,   262,   266,   266,   262,
     266,     6,     6,   375,   261,     4,   262,   270,   261,   266,
     270,   367,   376,     7,   295,   305,   354,   370,   309,     6,
     364,     6,     6,     6,   145,   316,   103,   122,   107,     6,
       5,   265,     6,   354,   354,   354,   354,   262,   357,   354,
     354,   296,   294,   265,   265,     6,   314,     6,   354,   367,
     145,   145,     4,     6,   371,   371,   354,   354,   376,   266,
     262,   266,   270,   324,   324,   354,   354,   266,   270,   262,
     266,   270,     6,     6,   366,   364,   364,   364,   364,   364,
     250,   364,     6,   266,   371,   354,     6,     6,     6,     6,
       6,   367,   266,   270,     8,   266,   262,   250,   265,   354,
     368,   376,   375,   354,   375,   354,   376,   379,   381,   376,
     270,   262,   270,   266,   354,   342,   342,   367,   297,   373,
     376,   354,     6,     6,   372,   264,   367,   382,     6,   296,
     296,   279,   354,   270,   270,   266,   270,   280,   354,   354,
       6,     6,     6,     6,   354,   354,   262,     6,   354,   301,
     303,   265,   381,   266,   270,     7,     7,   149,     6,   265,
     265,   265,     5,   366,   296,   296,   270,   296,   262,   262,
     264,   371,   371,     6,     6,   354,   354,   265,   266,   266,
     265,     6,     6,   265,   354,   266,   266,   266,   264,     6,
     367,     7,   265,   354,   266,   270,   270,   270,   270,   270,
     270,     6,   266,   266,   192,   354,   354,   265,   266,   371,
       6,     6,     6,   262,   296,   296,   312,   376,   266,   266,
     266,   266,     7,     6,     6,     6,   267,     6,   266,     6,
       6,   262,   270,   354,   354,   265,   367,   266,   270,   262,
     262,   270,   266,   306,   310,   367,   296,   354,   376,   385,
     371,   371,   354,     6,   266,   354,   357,   266,   266,     6,
       6,   366,   150,   151,   156,   349,   150,   151,   349,   371,
     324,   266,   270,     6,   266,   367,   325,   266,     6,   371,
     364,   364,   364,   364,   364,     6,   354,   266,   266,   371,
     266,   262,     6,   265,     6,   372,   195,   283,   354,   270,
     270,   366,     6,   354,   354,     6,   266,   266,   302,     7,
     261,   266,   266,   266,   265,   270,   262,   265,   266,   265,
     364,   367,     6,   265,   364,     6,   266,   266,   354,     6,
     145,   266,   336,   265,   266,   270,   270,   270,   270,   270,
       6,   266,     6,   325,     6,   265,   354,   354,   266,   270,
     306,   376,   262,   354,   354,   371,     6,   364,     6,   364,
       6,     6,   266,   354,   339,   325,     6,   371,   371,   371,
     371,   364,   371,   342,   280,   262,   270,     6,   265,   354,
     266,   270,   270,   266,   270,   270,     6,   266,   266,   337,
     266,   266,   266,   266,   270,   266,   266,   266,   286,   354,
     366,   266,   354,   354,   364,   364,   339,     6,     6,     6,
       6,   371,     6,     6,     6,   265,   262,   266,     6,   266,
     296,   270,   270,   266,   266,   284,   375,   289,   265,     6,
     354,   354,     6,   266,   270,   265,   366,   266,   266,     6,
     375,   287,   375,   266,     6,     6,   266,   270,     6,     6,
     375
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

  case 558:
#line 6061 "Gmsh.y"
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
#line 6071 "Gmsh.y"
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
#line 6081 "Gmsh.y"
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
#line 6091 "Gmsh.y"
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

  case 562:
#line 6103 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 563:
#line 6107 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 564:
#line 6112 "Gmsh.y"
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

  case 565:
#line 6124 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 566:
#line 6128 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 567:
#line 6132 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 568:
#line 6136 "Gmsh.y"
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

  case 569:
#line 6154 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 570:
#line 6162 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 571:
#line 6170 "Gmsh.y"
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

  case 572:
#line 6199 "Gmsh.y"
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

  case 573:
#line 6209 "Gmsh.y"
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

  case 574:
#line 6225 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 575:
#line 6236 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 576:
#line 6241 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 577:
#line 6245 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 578:
#line 6249 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 579:
#line 6261 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 580:
#line 6265 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 581:
#line 6277 "Gmsh.y"
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

  case 582:
#line 6294 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 583:
#line 6304 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 584:
#line 6308 "Gmsh.y"
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

  case 585:
#line 6323 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 586:
#line 6328 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 587:
#line 6335 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 588:
#line 6339 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 589:
#line 6344 "Gmsh.y"
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

  case 590:
#line 6358 "Gmsh.y"
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
#line 6372 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 592:
#line 6376 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 593:
#line 6380 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 594:
#line 6384 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 595:
#line 6388 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 596:
#line 6396 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 597:
#line 6402 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 598:
#line 6411 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 599:
#line 6415 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 600:
#line 6419 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 601:
#line 6427 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 602:
#line 6433 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 603:
#line 6439 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 604:
#line 6443 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 605:
#line 6450 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 606:
#line 6458 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 607:
#line 6465 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 608:
#line 6474 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 609:
#line 6478 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 610:
#line 6482 "Gmsh.y"
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

  case 611:
#line 6497 "Gmsh.y"
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

  case 612:
#line 6511 "Gmsh.y"
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

  case 613:
#line 6525 "Gmsh.y"
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

  case 614:
#line 6537 "Gmsh.y"
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

  case 615:
#line 6553 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 616:
#line 6562 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 617:
#line 6571 "Gmsh.y"
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

  case 618:
#line 6581 "Gmsh.y"
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

  case 619:
#line 6592 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 620:
#line 6600 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 621:
#line 6608 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 622:
#line 6612 "Gmsh.y"
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

  case 623:
#line 6630 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 624:
#line 6637 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 625:
#line 6643 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 626:
#line 6649 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 627:
#line 6656 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 628:
#line 6663 "Gmsh.y"
    { init_options(); ;}
    break;

  case 629:
#line 6665 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 630:
#line 6673 "Gmsh.y"
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

  case 631:
#line 6697 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 632:
#line 6699 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 633:
#line 6705 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 634:
#line 6710 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 635:
#line 6712 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 636:
#line 6717 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 637:
#line 6722 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 638:
#line 6727 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 639:
#line 6729 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 640:
#line 6733 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 641:
#line 6745 "Gmsh.y"
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

  case 642:
#line 6759 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 643:
#line 6763 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 644:
#line 6770 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 645:
#line 6778 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 646:
#line 6786 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 647:
#line 6797 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 648:
#line 6799 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 649:
#line 6802 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15161 "Gmsh.tab.cpp"
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


#line 6805 "Gmsh.y"


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

