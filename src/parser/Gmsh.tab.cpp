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
     tAtan = 281,
     tAtan2 = 282,
     tSinh = 283,
     tCosh = 284,
     tTanh = 285,
     tFabs = 286,
     tAbs = 287,
     tFloor = 288,
     tCeil = 289,
     tRound = 290,
     tMin = 291,
     tMax = 292,
     tFmod = 293,
     tModulo = 294,
     tHypot = 295,
     tList = 296,
     tLinSpace = 297,
     tLogSpace = 298,
     tListFromFile = 299,
     tCatenary = 300,
     tPrintf = 301,
     tError = 302,
     tWarning = 303,
     tStr = 304,
     tSprintf = 305,
     tStrCat = 306,
     tStrPrefix = 307,
     tStrRelative = 308,
     tStrReplace = 309,
     tAbsolutePath = 310,
     tDirName = 311,
     tStrSub = 312,
     tStrLen = 313,
     tFind = 314,
     tStrFind = 315,
     tStrCmp = 316,
     tStrChoice = 317,
     tUpperCase = 318,
     tLowerCase = 319,
     tLowerCaseIn = 320,
     tTextAttributes = 321,
     tBoundingBox = 322,
     tDraw = 323,
     tSetChanged = 324,
     tToday = 325,
     tFixRelativePath = 326,
     tCurrentDirectory = 327,
     tCurrentFileName = 328,
     tSyncModel = 329,
     tNewModel = 330,
     tMass = 331,
     tCenterOfMass = 332,
     tMatrixOfInertia = 333,
     tOnelabAction = 334,
     tOnelabRun = 335,
     tCodeName = 336,
     tCpu = 337,
     tMemory = 338,
     tTotalMemory = 339,
     tCreateTopology = 340,
     tCreateGeometry = 341,
     tClassifySurfaces = 342,
     tRenumberMeshNodes = 343,
     tRenumberMeshElements = 344,
     tDistanceFunction = 345,
     tDefineConstant = 346,
     tUndefineConstant = 347,
     tDefineNumber = 348,
     tDefineStruct = 349,
     tNameStruct = 350,
     tDimNameSpace = 351,
     tAppend = 352,
     tDefineString = 353,
     tSetNumber = 354,
     tSetTag = 355,
     tSetString = 356,
     tPoint = 357,
     tCircle = 358,
     tEllipse = 359,
     tCurve = 360,
     tSphere = 361,
     tPolarSphere = 362,
     tSurface = 363,
     tSpline = 364,
     tVolume = 365,
     tBox = 366,
     tCylinder = 367,
     tCone = 368,
     tTorus = 369,
     tEllipsoid = 370,
     tQuadric = 371,
     tShapeFromFile = 372,
     tRectangle = 373,
     tDisk = 374,
     tWire = 375,
     tGeoEntity = 376,
     tCharacteristic = 377,
     tLength = 378,
     tParametric = 379,
     tElliptic = 380,
     tRefineMesh = 381,
     tRecombineMesh = 382,
     tAdaptMesh = 383,
     tTransformMesh = 384,
     tRelocateMesh = 385,
     tReorientMesh = 386,
     tSetFactory = 387,
     tThruSections = 388,
     tWedge = 389,
     tFillet = 390,
     tChamfer = 391,
     tPlane = 392,
     tRuled = 393,
     tTransfinite = 394,
     tPhysical = 395,
     tCompound = 396,
     tPeriodic = 397,
     tParent = 398,
     tUsing = 399,
     tPlugin = 400,
     tDegenerated = 401,
     tRecursive = 402,
     tSewing = 403,
     tRotate = 404,
     tTranslate = 405,
     tSymmetry = 406,
     tDilate = 407,
     tExtrude = 408,
     tLevelset = 409,
     tAffine = 410,
     tBooleanUnion = 411,
     tBooleanIntersection = 412,
     tBooleanDifference = 413,
     tBooleanSection = 414,
     tBooleanFragments = 415,
     tThickSolid = 416,
     tRecombine = 417,
     tSmoother = 418,
     tSplit = 419,
     tDelete = 420,
     tCoherence = 421,
     tHealShapes = 422,
     tIntersect = 423,
     tMeshAlgorithm = 424,
     tReverseMesh = 425,
     tMeshSize = 426,
     tMeshSizeFromBoundary = 427,
     tLayers = 428,
     tScaleLast = 429,
     tHole = 430,
     tAlias = 431,
     tAliasWithOptions = 432,
     tCopyOptions = 433,
     tQuadTriAddVerts = 434,
     tQuadTriNoNewVerts = 435,
     tRecombLaterals = 436,
     tTransfQuadTri = 437,
     tText2D = 438,
     tText3D = 439,
     tInterpolationScheme = 440,
     tTime = 441,
     tCombine = 442,
     tBSpline = 443,
     tBezier = 444,
     tNurbs = 445,
     tNurbsOrder = 446,
     tNurbsKnots = 447,
     tColor = 448,
     tColorTable = 449,
     tFor = 450,
     tIn = 451,
     tEndFor = 452,
     tIf = 453,
     tElseIf = 454,
     tElse = 455,
     tEndIf = 456,
     tExit = 457,
     tAbort = 458,
     tField = 459,
     tReturn = 460,
     tCall = 461,
     tSlide = 462,
     tMacro = 463,
     tShow = 464,
     tHide = 465,
     tGetValue = 466,
     tGetStringValue = 467,
     tGetEnv = 468,
     tGetString = 469,
     tGetNumber = 470,
     tUnique = 471,
     tSetMaxTag = 472,
     tHomology = 473,
     tCohomology = 474,
     tBetti = 475,
     tExists = 476,
     tFileExists = 477,
     tGetForced = 478,
     tGetForcedStr = 479,
     tGMSH_MAJOR_VERSION = 480,
     tGMSH_MINOR_VERSION = 481,
     tGMSH_PATCH_VERSION = 482,
     tGmshExecutableName = 483,
     tSetPartition = 484,
     tNameToString = 485,
     tStringToName = 486,
     tUnsplitWindow = 487,
     tAFFECTDIVIDE = 488,
     tAFFECTTIMES = 489,
     tAFFECTMINUS = 490,
     tAFFECTPLUS = 491,
     tOR = 492,
     tAND = 493,
     tNOTEQUAL = 494,
     tEQUAL = 495,
     tGREATERGREATER = 496,
     tLESSLESS = 497,
     tGREATEROREQUAL = 498,
     tLESSOREQUAL = 499,
     UNARYPREC = 500,
     tMINUSMINUS = 501,
     tPLUSPLUS = 502
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
#define tAtan 281
#define tAtan2 282
#define tSinh 283
#define tCosh 284
#define tTanh 285
#define tFabs 286
#define tAbs 287
#define tFloor 288
#define tCeil 289
#define tRound 290
#define tMin 291
#define tMax 292
#define tFmod 293
#define tModulo 294
#define tHypot 295
#define tList 296
#define tLinSpace 297
#define tLogSpace 298
#define tListFromFile 299
#define tCatenary 300
#define tPrintf 301
#define tError 302
#define tWarning 303
#define tStr 304
#define tSprintf 305
#define tStrCat 306
#define tStrPrefix 307
#define tStrRelative 308
#define tStrReplace 309
#define tAbsolutePath 310
#define tDirName 311
#define tStrSub 312
#define tStrLen 313
#define tFind 314
#define tStrFind 315
#define tStrCmp 316
#define tStrChoice 317
#define tUpperCase 318
#define tLowerCase 319
#define tLowerCaseIn 320
#define tTextAttributes 321
#define tBoundingBox 322
#define tDraw 323
#define tSetChanged 324
#define tToday 325
#define tFixRelativePath 326
#define tCurrentDirectory 327
#define tCurrentFileName 328
#define tSyncModel 329
#define tNewModel 330
#define tMass 331
#define tCenterOfMass 332
#define tMatrixOfInertia 333
#define tOnelabAction 334
#define tOnelabRun 335
#define tCodeName 336
#define tCpu 337
#define tMemory 338
#define tTotalMemory 339
#define tCreateTopology 340
#define tCreateGeometry 341
#define tClassifySurfaces 342
#define tRenumberMeshNodes 343
#define tRenumberMeshElements 344
#define tDistanceFunction 345
#define tDefineConstant 346
#define tUndefineConstant 347
#define tDefineNumber 348
#define tDefineStruct 349
#define tNameStruct 350
#define tDimNameSpace 351
#define tAppend 352
#define tDefineString 353
#define tSetNumber 354
#define tSetTag 355
#define tSetString 356
#define tPoint 357
#define tCircle 358
#define tEllipse 359
#define tCurve 360
#define tSphere 361
#define tPolarSphere 362
#define tSurface 363
#define tSpline 364
#define tVolume 365
#define tBox 366
#define tCylinder 367
#define tCone 368
#define tTorus 369
#define tEllipsoid 370
#define tQuadric 371
#define tShapeFromFile 372
#define tRectangle 373
#define tDisk 374
#define tWire 375
#define tGeoEntity 376
#define tCharacteristic 377
#define tLength 378
#define tParametric 379
#define tElliptic 380
#define tRefineMesh 381
#define tRecombineMesh 382
#define tAdaptMesh 383
#define tTransformMesh 384
#define tRelocateMesh 385
#define tReorientMesh 386
#define tSetFactory 387
#define tThruSections 388
#define tWedge 389
#define tFillet 390
#define tChamfer 391
#define tPlane 392
#define tRuled 393
#define tTransfinite 394
#define tPhysical 395
#define tCompound 396
#define tPeriodic 397
#define tParent 398
#define tUsing 399
#define tPlugin 400
#define tDegenerated 401
#define tRecursive 402
#define tSewing 403
#define tRotate 404
#define tTranslate 405
#define tSymmetry 406
#define tDilate 407
#define tExtrude 408
#define tLevelset 409
#define tAffine 410
#define tBooleanUnion 411
#define tBooleanIntersection 412
#define tBooleanDifference 413
#define tBooleanSection 414
#define tBooleanFragments 415
#define tThickSolid 416
#define tRecombine 417
#define tSmoother 418
#define tSplit 419
#define tDelete 420
#define tCoherence 421
#define tHealShapes 422
#define tIntersect 423
#define tMeshAlgorithm 424
#define tReverseMesh 425
#define tMeshSize 426
#define tMeshSizeFromBoundary 427
#define tLayers 428
#define tScaleLast 429
#define tHole 430
#define tAlias 431
#define tAliasWithOptions 432
#define tCopyOptions 433
#define tQuadTriAddVerts 434
#define tQuadTriNoNewVerts 435
#define tRecombLaterals 436
#define tTransfQuadTri 437
#define tText2D 438
#define tText3D 439
#define tInterpolationScheme 440
#define tTime 441
#define tCombine 442
#define tBSpline 443
#define tBezier 444
#define tNurbs 445
#define tNurbsOrder 446
#define tNurbsKnots 447
#define tColor 448
#define tColorTable 449
#define tFor 450
#define tIn 451
#define tEndFor 452
#define tIf 453
#define tElseIf 454
#define tElse 455
#define tEndIf 456
#define tExit 457
#define tAbort 458
#define tField 459
#define tReturn 460
#define tCall 461
#define tSlide 462
#define tMacro 463
#define tShow 464
#define tHide 465
#define tGetValue 466
#define tGetStringValue 467
#define tGetEnv 468
#define tGetString 469
#define tGetNumber 470
#define tUnique 471
#define tSetMaxTag 472
#define tHomology 473
#define tCohomology 474
#define tBetti 475
#define tExists 476
#define tFileExists 477
#define tGetForced 478
#define tGetForcedStr 479
#define tGMSH_MAJOR_VERSION 480
#define tGMSH_MINOR_VERSION 481
#define tGMSH_PATCH_VERSION 482
#define tGmshExecutableName 483
#define tSetPartition 484
#define tNameToString 485
#define tStringToName 486
#define tUnsplitWindow 487
#define tAFFECTDIVIDE 488
#define tAFFECTTIMES 489
#define tAFFECTMINUS 490
#define tAFFECTPLUS 491
#define tOR 492
#define tAND 493
#define tNOTEQUAL 494
#define tEQUAL 495
#define tGREATERGREATER 496
#define tLESSLESS 497
#define tGREATEROREQUAL 498
#define tLESSOREQUAL 499
#define UNARYPREC 500
#define tMINUSMINUS 501
#define tPLUSPLUS 502




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
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
int printListOfDouble(char *format, List_T *list, char *buffer);
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
#line 777 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 790 "Gmsh.tab.cpp"

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
#define YYLAST   18049

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  270
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  642
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2296

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   502

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   255,     2,   267,     2,   252,   254,     2,
     260,   261,   250,   248,   269,   249,   266,   251,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     242,     2,   243,   237,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   262,     2,   263,   259,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   264,   253,   265,   268,     2,     2,     2,
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
     235,   236,   238,   239,   240,   241,   244,   245,   246,   247,
     256,   257,   258
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
     298,   300,   302,   308,   314,   317,   325,   333,   338,   342,
     349,   359,   367,   374,   382,   389,   394,   403,   413,   423,
     430,   440,   447,   457,   463,   472,   481,   493,   500,   510,
     516,   524,   534,   544,   556,   564,   574,   584,   585,   587,
     588,   592,   598,   599,   609,   610,   622,   628,   629,   639,
     640,   644,   648,   654,   660,   661,   664,   665,   667,   669,
     673,   676,   679,   682,   684,   689,   692,   695,   696,   699,
     701,   705,   708,   711,   714,   717,   720,   722,   724,   728,
     729,   735,   741,   747,   748,   751,   752,   755,   763,   771,
     779,   790,   801,   810,   819,   827,   835,   847,   855,   864,
     873,   882,   892,   901,   910,   914,   919,   930,   938,   946,
     954,   962,   970,   978,   986,   994,  1002,  1010,  1020,  1028,
    1036,  1045,  1054,  1067,  1068,  1078,  1080,  1082,  1084,  1086,
    1091,  1093,  1095,  1097,  1102,  1104,  1106,  1111,  1113,  1115,
    1117,  1122,  1128,  1140,  1146,  1156,  1166,  1174,  1179,  1189,
    1200,  1210,  1212,  1214,  1215,  1218,  1225,  1233,  1241,  1248,
    1256,  1265,  1276,  1291,  1308,  1321,  1336,  1351,  1366,  1381,
    1390,  1399,  1406,  1411,  1417,  1423,  1430,  1437,  1441,  1446,
    1450,  1456,  1463,  1469,  1474,  1478,  1483,  1487,  1492,  1498,
    1503,  1509,  1513,  1519,  1527,  1535,  1539,  1542,  1550,  1554,
    1557,  1560,  1563,  1566,  1569,  1585,  1588,  1591,  1599,  1602,
    1612,  1624,  1627,  1632,  1635,  1638,  1641,  1644,  1661,  1667,
    1676,  1688,  1695,  1704,  1713,  1724,  1726,  1729,  1732,  1734,
    1738,  1742,  1747,  1752,  1754,  1756,  1762,  1774,  1788,  1789,
    1797,  1798,  1812,  1813,  1829,  1830,  1837,  1847,  1850,  1854,
    1865,  1879,  1881,  1884,  1890,  1898,  1901,  1904,  1908,  1911,
    1915,  1918,  1922,  1932,  1939,  1941,  1943,  1945,  1947,  1949,
    1950,  1953,  1957,  1961,  1966,  1976,  1981,  1996,  1997,  2001,
    2002,  2004,  2005,  2008,  2009,  2012,  2013,  2016,  2022,  2029,
    2037,  2044,  2050,  2054,  2063,  2070,  2079,  2088,  2094,  2099,
    2106,  2118,  2130,  2149,  2168,  2181,  2194,  2207,  2218,  2223,
    2228,  2233,  2238,  2243,  2250,  2253,  2257,  2264,  2267,  2269,
    2271,  2273,  2276,  2282,  2290,  2301,  2303,  2307,  2310,  2313,
    2316,  2320,  2324,  2328,  2332,  2336,  2340,  2344,  2348,  2352,
    2356,  2360,  2364,  2368,  2372,  2376,  2380,  2384,  2388,  2394,
    2399,  2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,  2444,
    2451,  2456,  2461,  2466,  2471,  2476,  2481,  2486,  2491,  2498,
    2505,  2512,  2517,  2524,  2531,  2533,  2535,  2537,  2539,  2541,
    2543,  2545,  2547,  2549,  2551,  2553,  2554,  2561,  2563,  2568,
    2575,  2577,  2582,  2587,  2592,  2599,  2605,  2613,  2622,  2633,
    2638,  2643,  2650,  2655,  2659,  2662,  2668,  2674,  2678,  2684,
    2691,  2700,  2707,  2716,  2723,  2728,  2736,  2743,  2750,  2757,
    2762,  2769,  2774,  2775,  2778,  2779,  2782,  2783,  2791,  2793,
    2797,  2799,  2802,  2803,  2807,  2809,  2812,  2815,  2819,  2823,
    2835,  2845,  2853,  2861,  2863,  2867,  2869,  2871,  2874,  2878,
    2883,  2889,  2891,  2895,  2897,  2900,  2904,  2908,  2914,  2919,
    2924,  2927,  2932,  2935,  2939,  2943,  2948,  2954,  2960,  2966,
    2972,  2978,  2980,  2982,  2984,  2988,  2994,  3002,  3007,  3012,
    3017,  3024,  3031,  3040,  3049,  3054,  3069,  3074,  3079,  3081,
    3083,  3087,  3091,  3101,  3109,  3111,  3117,  3121,  3128,  3130,
    3134,  3136,  3138,  3143,  3148,  3152,  3158,  3165,  3174,  3181,
    3186,  3192,  3194,  3199,  3201,  3203,  3205,  3207,  3212,  3219,
    3224,  3231,  3237,  3245,  3250,  3255,  3260,  3269,  3274,  3279,
    3284,  3289,  3298,  3307,  3314,  3319,  3326,  3331,  3333,  3335,
    3340,  3345,  3346,  3353,  3358,  3361,  3366,  3371,  3373,  3375,
    3379,  3381,  3383,  3387,  3391,  3395,  3401,  3409,  3415,  3421,
    3430,  3432,  3434
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     271,     0,    -1,   272,    -1,     1,     6,    -1,    -1,   272,
     273,    -1,   275,    -1,   276,    -1,   297,    -1,   132,   260,
     373,   261,     6,    -1,   316,    -1,   322,    -1,   326,    -1,
     327,    -1,   328,    -1,   329,    -1,   333,    -1,   342,    -1,
     343,    -1,   349,    -1,   350,    -1,   332,    -1,   331,    -1,
     330,    -1,   325,    -1,   352,    -1,   243,    -1,   244,    -1,
      46,   260,   373,   261,     6,    -1,    48,   260,   373,   261,
       6,    -1,    47,   260,   373,   261,     6,    -1,    46,   260,
     373,   261,   274,   373,     6,    -1,    46,   260,   373,   269,
     369,   261,     6,    -1,    48,   260,   373,   269,   369,   261,
       6,    -1,    47,   260,   373,   269,   369,   261,     6,    -1,
      46,   260,   373,   269,   369,   261,   274,   373,     6,    -1,
     383,   373,   264,   277,   265,     6,    -1,   176,     4,   262,
     353,   263,     6,    -1,   177,     4,   262,   353,   263,     6,
      -1,   178,     4,   262,   353,   269,   353,   263,     6,    -1,
      -1,   277,   280,    -1,   277,   284,    -1,   277,   287,    -1,
     277,   289,    -1,   277,   290,    -1,   277,   332,    -1,   353,
      -1,   278,   269,   353,    -1,   353,    -1,   279,   269,   353,
      -1,    -1,    -1,     4,   281,   260,   278,   261,   282,   264,
     279,   265,     6,    -1,   373,    -1,   283,   269,   373,    -1,
      -1,   183,   260,   353,   269,   353,   269,   353,   261,   285,
     264,   283,   265,     6,    -1,   373,    -1,   286,   269,   373,
      -1,    -1,   184,   260,   353,   269,   353,   269,   353,   269,
     353,   261,   288,   264,   286,   265,     6,    -1,   185,   264,
     365,   265,   264,   365,   265,     6,    -1,   185,   264,   365,
     265,   264,   365,   265,   264,   365,   265,   264,   365,   265,
       6,    -1,    -1,   186,   291,   264,   279,   265,     6,    -1,
       7,    -1,   236,    -1,   235,    -1,   234,    -1,   233,    -1,
     258,    -1,   257,    -1,   260,    -1,   262,    -1,   261,    -1,
     263,    -1,     4,    -1,    36,    -1,    37,    -1,   111,    -1,
     112,    -1,    91,   262,   299,   263,     6,    -1,    92,   262,
     303,   263,     6,    -1,   358,     6,    -1,    99,   294,   374,
     269,   353,   295,     6,    -1,   101,   294,   374,   269,   374,
     295,     6,    -1,   383,   292,   366,     6,    -1,   383,   293,
       6,    -1,   383,   294,   295,   292,   366,     6,    -1,   383,
     294,   264,   369,   265,   295,   292,   366,     6,    -1,   383,
     262,   353,   263,   292,   353,     6,    -1,   383,   262,   353,
     263,   293,     6,    -1,   383,   260,   353,   261,   292,   353,
       6,    -1,   383,   260,   353,   261,   293,     6,    -1,   383,
       7,   374,     6,    -1,   383,   294,   295,     7,    49,   294,
     295,     6,    -1,   383,   294,   295,     7,    49,   294,   378,
     295,     6,    -1,   383,   294,   295,   236,    49,   294,   378,
     295,     6,    -1,   383,   266,   296,     7,   374,     6,    -1,
     383,   262,   353,   263,   266,   296,     7,   374,     6,    -1,
     383,   266,   296,   292,   353,     6,    -1,   383,   262,   353,
     263,   266,   296,   292,   353,     6,    -1,   383,   266,   296,
     293,     6,    -1,   383,   262,   353,   263,   266,   296,   293,
       6,    -1,   383,   266,   193,   266,   296,     7,   370,     6,
      -1,   383,   262,   353,   263,   266,   193,   266,   296,     7,
     370,     6,    -1,   383,   266,   194,     7,   371,     6,    -1,
     383,   262,   353,   263,   266,   194,     7,   371,     6,    -1,
     383,   204,     7,   366,     6,    -1,   204,   262,   353,   263,
       7,   296,     6,    -1,   204,   262,   353,   263,   266,   296,
       7,   353,     6,    -1,   204,   262,   353,   263,   266,   296,
       7,   374,     6,    -1,   204,   262,   353,   263,   266,   296,
       7,   264,   369,   265,     6,    -1,   204,   262,   353,   263,
     266,   296,     6,    -1,   145,   260,     4,   261,   266,   296,
       7,   353,     6,    -1,   145,   260,     4,   261,   266,   296,
       7,   374,     6,    -1,    -1,   269,    -1,    -1,   299,   298,
     383,    -1,   299,   298,   383,     7,   353,    -1,    -1,   299,
     298,   383,     7,   264,   366,   300,   305,   265,    -1,    -1,
     299,   298,   383,   294,   295,     7,   264,   366,   301,   305,
     265,    -1,   299,   298,   383,     7,   374,    -1,    -1,   299,
     298,   383,     7,   264,   374,   302,   309,   265,    -1,    -1,
     303,   298,   373,    -1,   353,     7,   374,    -1,   304,   269,
     353,     7,   374,    -1,   368,     7,   383,   260,   261,    -1,
      -1,   269,   307,    -1,    -1,   307,    -1,   308,    -1,   307,
     269,   308,    -1,     4,   366,    -1,    36,   353,    -1,    37,
     353,    -1,     4,    -1,     4,   264,   304,   265,    -1,     4,
     374,    -1,     4,   377,    -1,    -1,   269,   310,    -1,   311,
      -1,   310,   269,   311,    -1,     4,   353,    -1,     4,   374,
      -1,   208,   374,    -1,     4,   379,    -1,     4,   377,    -1,
     353,    -1,   374,    -1,   374,   269,   353,    -1,    -1,   196,
     106,   264,   353,   265,    -1,   144,   102,   264,   369,   265,
      -1,   144,   121,   264,   369,   265,    -1,    -1,   137,   363,
      -1,    -1,   144,   148,    -1,   102,   260,   353,   261,     7,
     363,     6,    -1,   105,   260,   353,   261,     7,   366,     6,
      -1,   109,   260,   353,   261,     7,   366,     6,    -1,   141,
     109,   260,   353,   261,     7,   366,   144,   353,     6,    -1,
     141,   188,   260,   353,   261,     7,   366,   144,   353,     6,
      -1,   103,   260,   353,   261,     7,   366,   314,     6,    -1,
     104,   260,   353,   261,     7,   366,   314,     6,    -1,   188,
     260,   353,   261,     7,   366,     6,    -1,   189,   260,   353,
     261,     7,   366,     6,    -1,   190,   260,   353,   261,     7,
     366,   192,   366,   191,   353,     6,    -1,   120,   260,   353,
     261,     7,   366,     6,    -1,   105,     4,   260,   353,   261,
       7,   366,     6,    -1,   137,   108,   260,   353,   261,     7,
     366,     6,    -1,   108,   260,   353,   261,     7,   366,   313,
       6,    -1,   138,   108,   260,   353,   261,     7,   366,   313,
       6,    -1,   188,   108,   260,   353,   261,     7,   366,     6,
      -1,   189,   108,   260,   353,   261,     7,   366,     6,    -1,
      13,    14,     6,    -1,    14,   108,   353,     6,    -1,   124,
     108,   260,   353,   261,     7,     5,     5,     5,     6,    -1,
     106,   260,   353,   261,     7,   366,     6,    -1,   107,   260,
     353,   261,     7,   366,     6,    -1,   111,   260,   353,   261,
       7,   366,     6,    -1,   114,   260,   353,   261,     7,   366,
       6,    -1,   118,   260,   353,   261,     7,   366,     6,    -1,
     119,   260,   353,   261,     7,   366,     6,    -1,   112,   260,
     353,   261,     7,   366,     6,    -1,   113,   260,   353,   261,
       7,   366,     6,    -1,   134,   260,   353,   261,     7,   366,
       6,    -1,   161,   260,   353,   261,     7,   366,     6,    -1,
     108,     4,   260,   353,   261,     7,   366,   315,     6,    -1,
     110,   260,   353,   261,     7,   366,     6,    -1,   133,   260,
     353,   261,     7,   366,     6,    -1,   138,   133,   260,   353,
     261,     7,   366,     6,    -1,   141,   319,   260,   353,   261,
       7,   366,     6,    -1,   141,   319,   260,   353,   261,     7,
     366,     4,   264,   365,   265,     6,    -1,    -1,   140,   318,
     317,   260,   312,   261,   292,   366,     6,    -1,   102,    -1,
     105,    -1,   108,    -1,   110,    -1,   121,   264,   353,   265,
      -1,   105,    -1,   108,    -1,   110,    -1,   121,   264,   353,
     265,    -1,   105,    -1,   108,    -1,   121,   264,   353,   265,
      -1,   102,    -1,   105,    -1,   108,    -1,   121,   264,   353,
     265,    -1,   150,   363,   264,   323,   265,    -1,   149,   264,
     363,   269,   363,   269,   353,   265,   264,   323,   265,    -1,
     151,   363,   264,   323,   265,    -1,   152,   264,   363,   269,
     353,   265,   264,   323,   265,    -1,   152,   264,   363,   269,
     363,   265,   264,   323,   265,    -1,   155,   264,   369,   265,
     264,   323,   265,    -1,     4,   264,   323,   265,    -1,   168,
     105,   264,   369,   265,   108,   264,   353,   265,    -1,   164,
     105,   264,   353,   265,   102,   264,   369,   265,     6,    -1,
     164,   105,   260,   353,   261,   264,   369,   265,     6,    -1,
     324,    -1,   322,    -1,    -1,   324,   316,    -1,   324,   318,
     264,   369,   265,     6,    -1,   324,   140,   318,   264,   369,
     265,     6,    -1,   324,   143,   318,   264,   369,   265,     6,
      -1,   324,   318,   264,     8,   265,     6,    -1,   324,   140,
     318,   264,     8,   265,     6,    -1,   154,   137,   260,   353,
     261,     7,   366,     6,    -1,   154,   102,   260,   353,   261,
       7,   264,   365,   265,     6,    -1,   154,   137,   260,   353,
     261,     7,   264,   363,   269,   363,   269,   369,   265,     6,
      -1,   154,   137,   260,   353,   261,     7,   264,   363,   269,
     363,   269,   363,   269,   369,   265,     6,    -1,   154,   106,
     260,   353,   261,     7,   264,   363,   269,   369,   265,     6,
      -1,   154,   112,   260,   353,   261,     7,   264,   363,   269,
     363,   269,   369,   265,     6,    -1,   154,   113,   260,   353,
     261,     7,   264,   363,   269,   363,   269,   369,   265,     6,
      -1,   154,   115,   260,   353,   261,     7,   264,   363,   269,
     363,   269,   369,   265,     6,    -1,   154,   116,   260,   353,
     261,     7,   264,   363,   269,   363,   269,   369,   265,     6,
      -1,   154,     4,   260,   353,   261,     7,   366,     6,    -1,
     154,     4,   260,   353,   261,     7,     5,     6,    -1,   154,
       4,   264,   353,   265,     6,    -1,   165,   264,   324,   265,
      -1,   147,   165,   264,   324,   265,    -1,   165,     4,   264,
     324,   265,    -1,   165,   204,   262,   353,   263,     6,    -1,
     165,     4,   262,   353,   263,     6,    -1,   165,   383,     6,
      -1,   165,     4,     4,     6,    -1,   165,    94,     6,    -1,
     193,   370,   264,   324,   265,    -1,   147,   193,   370,   264,
     324,   265,    -1,   229,   353,   264,   324,   265,    -1,   209,
     264,     8,   265,    -1,   209,     5,     6,    -1,   210,   264,
       8,   265,    -1,   210,     5,     6,    -1,   209,   264,   324,
     265,    -1,   147,   209,   264,   324,   265,    -1,   210,   264,
     324,   265,    -1,   147,   210,   264,   324,   265,    -1,   383,
     374,     6,    -1,    80,   260,   380,   261,     6,    -1,   383,
     383,   262,   353,   263,   373,     6,    -1,   383,   383,   383,
     262,   353,   263,     6,    -1,   383,   353,     6,    -1,   232,
       6,    -1,   145,   260,     4,   261,   266,     4,     6,    -1,
     187,     4,     6,    -1,   202,     6,    -1,   203,     6,    -1,
      74,     6,    -1,    75,     6,    -1,    67,     6,    -1,    67,
     264,   353,   269,   353,   269,   353,   269,   353,   269,   353,
     269,   353,   265,     6,    -1,    68,     6,    -1,    69,     6,
      -1,    85,   264,   353,   269,   353,   265,     6,    -1,    85,
       6,    -1,    87,   264,   353,   269,   353,   269,   353,   265,
       6,    -1,    87,   264,   353,   269,   353,   269,   353,   269,
     353,   265,     6,    -1,    86,     6,    -1,    86,   264,   324,
     265,    -1,    88,     6,    -1,    89,     6,    -1,   126,     6,
      -1,   127,     6,    -1,   128,   264,   369,   265,   264,   369,
     265,   264,   365,   265,   264,   353,   269,   353,   265,     6,
      -1,   129,   264,   369,   265,     6,    -1,   129,   264,   369,
     265,   264,   323,   265,     6,    -1,   207,   260,   264,   369,
     265,   269,   374,   269,   374,   261,     6,    -1,   195,   260,
     353,     8,   353,   261,    -1,   195,   260,   353,     8,   353,
       8,   353,   261,    -1,   195,     4,   196,   264,   353,     8,
     353,   265,    -1,   195,     4,   196,   264,   353,     8,   353,
       8,   353,   265,    -1,   197,    -1,   208,     4,    -1,   208,
     374,    -1,   205,    -1,   206,   383,     6,    -1,   206,   374,
       6,    -1,   198,   260,   353,   261,    -1,   199,   260,   353,
     261,    -1,   200,    -1,   201,    -1,   153,   363,   264,   324,
     265,    -1,   153,   264,   363,   269,   363,   269,   353,   265,
     264,   324,   265,    -1,   153,   264,   363,   269,   363,   269,
     363,   269,   353,   265,   264,   324,   265,    -1,    -1,   153,
     363,   264,   324,   334,   338,   265,    -1,    -1,   153,   264,
     363,   269,   363,   269,   353,   265,   264,   324,   335,   338,
     265,    -1,    -1,   153,   264,   363,   269,   363,   269,   363,
     269,   353,   265,   264,   324,   336,   338,   265,    -1,    -1,
     153,   264,   324,   337,   338,   265,    -1,   153,   264,   324,
     265,   144,   120,   264,   353,   265,    -1,   133,   366,    -1,
     138,   133,   366,    -1,   135,   264,   369,   265,   264,   369,
     265,   264,   369,   265,    -1,   136,   264,   369,   265,   264,
     369,   265,   264,   369,   265,   264,   369,   265,    -1,   339,
      -1,   338,   339,    -1,   173,   264,   353,   265,     6,    -1,
     173,   264,   366,   269,   366,   265,     6,    -1,   174,     6,
      -1,   162,     6,    -1,   162,   353,     6,    -1,   179,     6,
      -1,   179,   181,     6,    -1,   180,     6,    -1,   180,   181,
       6,    -1,   175,   260,   353,   261,     7,   366,   144,   353,
       6,    -1,   144,     4,   262,   353,   263,     6,    -1,   156,
      -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,    -1,
     165,     6,    -1,   147,   165,     6,    -1,   165,   353,     6,
      -1,   147,   165,   353,     6,    -1,   340,   264,   324,   341,
     265,   264,   324,   341,   265,    -1,   117,   260,   373,   261,
      -1,   340,   260,   353,   261,     7,   264,   324,   341,   265,
     264,   324,   341,   265,     6,    -1,    -1,   144,     4,   353,
      -1,    -1,     4,    -1,    -1,     7,   366,    -1,    -1,     7,
     353,    -1,    -1,   155,   366,    -1,   171,   367,     7,   353,
       6,    -1,   122,   123,   367,     7,   353,     6,    -1,   139,
     105,   367,     7,   353,   344,     6,    -1,   139,   108,   367,
     346,   345,     6,    -1,   139,   110,   367,   346,     6,    -1,
     182,   367,     6,    -1,   100,   318,   260,   353,   269,   353,
     261,     6,    -1,   217,   318,   260,   353,   261,     6,    -1,
     169,   108,   264,   369,   265,     7,   353,     6,    -1,   172,
     108,   264,   369,   265,     7,   353,     6,    -1,   162,   108,
     367,   347,     6,    -1,   162,   110,   367,     6,    -1,   163,
     108,   367,     7,   353,     6,    -1,   142,   105,   264,   369,
     265,     7,   264,   369,   265,   348,     6,    -1,   142,   108,
     264,   369,   265,     7,   264,   369,   265,   348,     6,    -1,
     142,   105,   264,   369,   265,     7,   264,   369,   265,   149,
     264,   363,   269,   363,   269,   353,   265,     6,    -1,   142,
     108,   264,   369,   265,     7,   264,   369,   265,   149,   264,
     363,   269,   363,   269,   353,   265,     6,    -1,   142,   105,
     264,   369,   265,     7,   264,   369,   265,   150,   363,     6,
      -1,   142,   108,   264,   369,   265,     7,   264,   369,   265,
     150,   363,     6,    -1,   142,   108,   353,   264,   369,   265,
       7,   353,   264,   369,   265,     6,    -1,   318,   264,   369,
     265,   196,   318,   264,   353,   265,     6,    -1,   170,   320,
     367,     6,    -1,   130,   321,   367,     6,    -1,   131,   110,
     366,     6,    -1,   146,   105,   366,     6,    -1,   141,   319,
     366,     6,    -1,   141,   319,   366,   169,   353,     6,    -1,
     166,     6,    -1,   166,     4,     6,    -1,   166,   102,   264,
     369,   265,     6,    -1,   167,     6,    -1,   218,    -1,   219,
      -1,   220,    -1,   351,     6,    -1,   351,   264,   366,   265,
       6,    -1,   351,   264,   366,   269,   366,   265,     6,    -1,
     351,   260,   366,   261,   264,   366,   269,   366,   265,     6,
      -1,   354,    -1,   260,   353,   261,    -1,   249,   353,    -1,
     248,   353,    -1,   255,   353,    -1,   353,   249,   353,    -1,
     353,   248,   353,    -1,   353,   250,   353,    -1,   353,   251,
     353,    -1,   353,   253,   353,    -1,   353,   254,   353,    -1,
     353,   252,   353,    -1,   353,   259,   353,    -1,   353,   242,
     353,    -1,   353,   243,   353,    -1,   353,   247,   353,    -1,
     353,   246,   353,    -1,   353,   241,   353,    -1,   353,   240,
     353,    -1,   353,   239,   353,    -1,   353,   238,   353,    -1,
     353,   244,   353,    -1,   353,   245,   353,    -1,   353,   237,
     353,     8,   353,    -1,    16,   294,   353,   295,    -1,    17,
     294,   353,   295,    -1,    18,   294,   353,   295,    -1,    19,
     294,   353,   295,    -1,    20,   294,   353,   295,    -1,    21,
     294,   353,   295,    -1,    22,   294,   353,   295,    -1,    23,
     294,   353,   295,    -1,    24,   294,   353,   295,    -1,    26,
     294,   353,   295,    -1,    27,   294,   353,   269,   353,   295,
      -1,    28,   294,   353,   295,    -1,    29,   294,   353,   295,
      -1,    30,   294,   353,   295,    -1,    31,   294,   353,   295,
      -1,    32,   294,   353,   295,    -1,    33,   294,   353,   295,
      -1,    34,   294,   353,   295,    -1,    35,   294,   353,   295,
      -1,    38,   294,   353,   269,   353,   295,    -1,    39,   294,
     353,   269,   353,   295,    -1,    40,   294,   353,   269,   353,
     295,    -1,    25,   294,   353,   295,    -1,    37,   294,   353,
     269,   353,   295,    -1,    36,   294,   353,   269,   353,   295,
      -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,    12,
      -1,   225,    -1,   226,    -1,   227,    -1,    82,    -1,    83,
      -1,    84,    -1,    -1,    93,   294,   353,   355,   305,   295,
      -1,   358,    -1,   215,   294,   373,   295,    -1,   215,   294,
     373,   269,   353,   295,    -1,   360,    -1,   383,   262,   353,
     263,    -1,   383,   260,   353,   261,    -1,   221,   260,   360,
     261,    -1,   221,   260,   360,   266,   296,   261,    -1,   223,
     260,   360,   356,   261,    -1,   223,   260,   360,   266,   296,
     356,   261,    -1,   223,   260,   360,   294,   353,   295,   356,
     261,    -1,   223,   260,   360,   266,   296,   294,   353,   295,
     356,   261,    -1,   222,   260,   374,   261,    -1,   267,   383,
     294,   295,    -1,   267,   360,   266,   296,   294,   295,    -1,
      96,   294,   383,   295,    -1,    96,   294,   295,    -1,   383,
     293,    -1,   383,   262,   353,   263,   293,    -1,   383,   260,
     353,   261,   293,    -1,   383,   266,   296,    -1,   383,     9,
     383,   266,   296,    -1,   383,   266,   296,   260,   353,   261,
      -1,   383,     9,   383,   266,   296,   260,   353,   261,    -1,
     383,   266,   296,   262,   353,   263,    -1,   383,     9,   383,
     266,   296,   262,   353,   263,    -1,   383,   262,   353,   263,
     266,   296,    -1,   383,   266,   296,   293,    -1,   383,   262,
     353,   263,   266,   296,   293,    -1,   211,   260,   373,   269,
     353,   261,    -1,    59,   260,   366,   269,   366,   261,    -1,
      60,   294,   373,   269,   373,   295,    -1,    58,   294,   373,
     295,    -1,    61,   294,   373,   269,   373,   295,    -1,    66,
     260,   380,   261,    -1,    -1,   269,   353,    -1,    -1,   269,
     373,    -1,    -1,    94,   360,   362,   359,   262,   306,   263,
      -1,   383,    -1,   383,     9,   383,    -1,    97,    -1,    97,
     353,    -1,    -1,   260,   361,   261,    -1,   364,    -1,   249,
     363,    -1,   248,   363,    -1,   363,   249,   363,    -1,   363,
     248,   363,    -1,   264,   353,   269,   353,   269,   353,   269,
     353,   269,   353,   265,    -1,   264,   353,   269,   353,   269,
     353,   269,   353,   265,    -1,   264,   353,   269,   353,   269,
     353,   265,    -1,   260,   353,   269,   353,   269,   353,   261,
      -1,   366,    -1,   365,   269,   366,    -1,   353,    -1,   368,
      -1,   264,   265,    -1,   264,   369,   265,    -1,   249,   264,
     369,   265,    -1,   353,   250,   264,   369,   265,    -1,   366,
      -1,   264,     8,   265,    -1,     5,    -1,   249,   368,    -1,
     353,   250,   368,    -1,   353,     8,   353,    -1,   353,     8,
     353,     8,   353,    -1,   102,   264,   353,   265,    -1,   102,
     264,     8,   265,    -1,   102,     5,    -1,   319,   264,     8,
     265,    -1,   319,     5,    -1,   140,   318,   367,    -1,   143,
     318,   366,    -1,   318,   196,    67,   366,    -1,    67,   318,
     264,   369,   265,    -1,    76,   319,   264,   353,   265,    -1,
      77,   319,   264,   353,   265,    -1,    78,   319,   264,   353,
     265,    -1,   193,   319,   264,   353,   265,    -1,   322,    -1,
     333,    -1,   342,    -1,   383,   294,   295,    -1,   383,   266,
     296,   294,   295,    -1,   383,     9,   383,   266,   296,   294,
     295,    -1,    41,   262,   383,   263,    -1,    41,   262,   368,
     263,    -1,    41,   260,   368,   261,    -1,    41,   294,   264,
     369,   265,   295,    -1,   383,   294,   264,   369,   265,   295,
      -1,    42,   294,   353,   269,   353,   269,   353,   295,    -1,
      43,   294,   353,   269,   353,   269,   353,   295,    -1,    44,
     294,   373,   295,    -1,    45,   294,   353,   269,   353,   269,
     353,   269,   353,   269,   353,   269,   353,   295,    -1,   216,
     294,   368,   295,    -1,    32,   294,   368,   295,    -1,   353,
      -1,   368,    -1,   369,   269,   353,    -1,   369,   269,   368,
      -1,   264,   353,   269,   353,   269,   353,   269,   353,   265,
      -1,   264,   353,   269,   353,   269,   353,   265,    -1,   383,
      -1,     4,   266,   193,   266,     4,    -1,   264,   372,   265,
      -1,   383,   262,   353,   263,   266,   194,    -1,   370,    -1,
     372,   269,   370,    -1,   374,    -1,   383,    -1,   383,   262,
     353,   263,    -1,   383,   260,   353,   261,    -1,   383,   266,
     296,    -1,   383,     9,   383,   266,   296,    -1,   383,   266,
     296,   260,   353,   261,    -1,   383,     9,   383,   266,   296,
     260,   353,   261,    -1,   383,   262,   353,   263,   266,     4,
      -1,   318,   264,   353,   265,    -1,   140,   318,   264,   353,
     265,    -1,     5,    -1,   230,   262,   383,   263,    -1,    70,
      -1,   228,    -1,    79,    -1,    81,    -1,   213,   260,   373,
     261,    -1,   212,   260,   373,   269,   373,   261,    -1,   214,
     294,   373,   295,    -1,   214,   294,   373,   269,   373,   295,
      -1,   224,   260,   360,   357,   261,    -1,   224,   260,   360,
     266,   296,   357,   261,    -1,    51,   294,   380,   295,    -1,
      52,   260,   373,   261,    -1,    53,   260,   373,   261,    -1,
      54,   260,   373,   269,   373,   269,   373,   261,    -1,    49,
     294,   380,   295,    -1,    63,   294,   373,   295,    -1,    64,
     294,   373,   295,    -1,    65,   294,   373,   295,    -1,    62,
     294,   353,   269,   373,   269,   373,   295,    -1,    57,   294,
     373,   269,   353,   269,   353,   295,    -1,    57,   294,   373,
     269,   353,   295,    -1,    50,   294,   373,   295,    -1,    50,
     294,   373,   269,   369,   295,    -1,    71,   294,   373,   295,
      -1,    72,    -1,    73,    -1,    56,   294,   373,   295,    -1,
      55,   294,   373,   295,    -1,    -1,    98,   294,   374,   375,
     309,   295,    -1,    95,   294,   376,   295,    -1,   267,   353,
      -1,   383,     9,   267,   353,    -1,    49,   294,   379,   295,
      -1,   380,    -1,   379,    -1,   264,   380,   265,    -1,   373,
      -1,   381,    -1,   380,   269,   373,    -1,   380,   269,   381,
      -1,   383,   260,   261,    -1,   383,   266,   296,   260,   261,
      -1,   383,     9,   383,   266,   296,   260,   261,    -1,     4,
     268,   264,   353,   265,    -1,   382,   268,   264,   353,   265,
      -1,   231,   262,   373,   263,   268,   264,   353,   265,    -1,
       4,    -1,   382,    -1,   231,   262,   373,   263,    -1
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
     802,   803,   809,   810,   811,   812,   817,   823,   884,   899,
     927,   937,   942,   950,   955,   963,   972,   977,   989,  1006,
    1012,  1021,  1039,  1057,  1066,  1078,  1083,  1091,  1111,  1134,
    1154,  1162,  1179,  1197,  1235,  1256,  1268,  1282,  1282,  1284,
    1286,  1295,  1305,  1304,  1325,  1324,  1342,  1352,  1351,  1365,
    1367,  1375,  1381,  1386,  1413,  1415,  1418,  1420,  1424,  1425,
    1429,  1441,  1445,  1449,  1462,  1476,  1484,  1497,  1499,  1503,
    1504,  1509,  1517,  1526,  1534,  1548,  1566,  1570,  1577,  1586,
    1589,  1595,  1599,  1611,  1614,  1621,  1624,  1630,  1653,  1669,
    1685,  1702,  1719,  1756,  1800,  1816,  1832,  1864,  1880,  1897,
    1913,  1963,  1981,  2002,  2023,  2029,  2035,  2042,  2073,  2088,
    2110,  2133,  2156,  2179,  2203,  2227,  2251,  2277,  2294,  2310,
    2328,  2346,  2358,  2372,  2371,  2401,  2403,  2405,  2407,  2409,
    2417,  2419,  2421,  2423,  2431,  2433,  2435,  2443,  2445,  2447,
    2449,  2459,  2475,  2491,  2507,  2523,  2539,  2556,  2593,  2614,
    2635,  2661,  2662,  2667,  2670,  2674,  2691,  2711,  2731,  2750,
    2777,  2796,  2817,  2832,  2848,  2866,  2917,  2938,  2960,  2983,
    3088,  3104,  3139,  3164,  3189,  3201,  3207,  3222,  3253,  3265,
    3274,  3281,  3293,  3313,  3317,  3322,  3326,  3331,  3338,  3345,
    3352,  3364,  3437,  3455,  3480,  3495,  3544,  3550,  3562,  3594,
    3598,  3603,  3610,  3615,  3625,  3630,  3636,  3644,  3655,  3663,
    3667,  3671,  3675,  3682,  3686,  3690,  3702,  3711,  3770,  3790,
    3816,  3832,  3849,  3866,  3888,  3910,  3945,  3953,  3961,  3967,
    3974,  3981,  4001,  4027,  4039,  4050,  4068,  4086,  4105,  4104,
    4129,  4128,  4155,  4154,  4179,  4178,  4201,  4217,  4234,  4251,
    4274,  4302,  4305,  4311,  4323,  4343,  4347,  4351,  4355,  4359,
    4363,  4367,  4371,  4380,  4393,  4394,  4395,  4396,  4397,  4401,
    4402,  4403,  4404,  4405,  4408,  4432,  4451,  4474,  4477,  4495,
    4498,  4515,  4518,  4524,  4527,  4534,  4537,  4544,  4567,  4586,
    4627,  4671,  4710,  4735,  4742,  4753,  4770,  4787,  4817,  4843,
    4869,  4901,  4929,  4955,  4981,  5007,  5033,  5055,  5067,  5115,
    5169,  5184,  5196,  5202,  5214,  5221,  5236,  5245,  5266,  5267,
    5268,  5272,  5278,  5290,  5308,  5336,  5337,  5338,  5339,  5340,
    5341,  5342,  5343,  5344,  5351,  5352,  5353,  5354,  5355,  5356,
    5357,  5358,  5359,  5360,  5361,  5362,  5363,  5364,  5365,  5366,
    5367,  5368,  5369,  5370,  5371,  5372,  5373,  5374,  5375,  5376,
    5377,  5378,  5379,  5380,  5381,  5382,  5383,  5384,  5385,  5386,
    5387,  5388,  5389,  5390,  5399,  5400,  5401,  5402,  5403,  5404,
    5405,  5406,  5407,  5408,  5409,  5414,  5413,  5421,  5425,  5430,
    5435,  5439,  5444,  5449,  5453,  5457,  5461,  5465,  5469,  5473,
    5479,  5494,  5498,  5504,  5509,  5528,  5548,  5569,  5573,  5577,
    5581,  5585,  5589,  5593,  5598,  5608,  5618,  5623,  5634,  5643,
    5648,  5653,  5681,  5682,  5688,  5689,  5695,  5694,  5717,  5719,
    5724,  5726,  5732,  5733,  5738,  5742,  5746,  5750,  5754,  5761,
    5765,  5769,  5773,  5780,  5785,  5792,  5797,  5801,  5806,  5810,
    5818,  5829,  5833,  5837,  5851,  5859,  5867,  5874,  5884,  5907,
    5912,  5918,  5923,  5929,  5940,  5946,  5960,  5966,  5978,  5992,
    6005,  6022,  6032,  6042,  6052,  6064,  6068,  6073,  6085,  6089,
    6093,  6097,  6115,  6123,  6131,  6160,  6170,  6186,  6197,  6202,
    6206,  6210,  6222,  6226,  6238,  6255,  6265,  6269,  6284,  6289,
    6296,  6300,  6305,  6319,  6333,  6337,  6341,  6345,  6349,  6357,
    6363,  6372,  6376,  6380,  6388,  6394,  6400,  6404,  6411,  6419,
    6426,  6435,  6439,  6443,  6458,  6472,  6486,  6498,  6514,  6523,
    6532,  6542,  6553,  6561,  6569,  6573,  6592,  6599,  6605,  6611,
    6618,  6626,  6625,  6635,  6659,  6661,  6667,  6672,  6674,  6679,
    6684,  6689,  6691,  6695,  6707,  6721,  6725,  6732,  6740,  6748,
    6759,  6761,  6764
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
  "tSqrt", "tSin", "tAsin", "tCos", "tAcos", "tTan", "tRand", "tAtan",
  "tAtan2", "tSinh", "tCosh", "tTanh", "tFabs", "tAbs", "tFloor", "tCeil",
  "tRound", "tMin", "tMax", "tFmod", "tModulo", "tHypot", "tList",
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
  "ListOfDoubleOrAll", "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr",
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
     485,   486,   487,   488,   489,   490,   491,    63,   492,   493,
     494,   495,    60,    62,   496,   497,   498,   499,    43,    45,
      42,    47,    37,   124,    38,    33,   500,   501,   502,    94,
      40,    41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   270,   271,   271,   272,   272,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   274,   274,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   278,   278,   279,
     279,   281,   282,   280,   283,   283,   285,   284,   286,   286,
     288,   287,   289,   289,   291,   290,   292,   292,   292,   292,
     292,   293,   293,   294,   294,   295,   295,   296,   296,   296,
     296,   296,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   298,   298,   299,
     299,   299,   300,   299,   301,   299,   299,   302,   299,   303,
     303,   304,   304,   304,   305,   305,   306,   306,   307,   307,
     308,   308,   308,   308,   308,   308,   308,   309,   309,   310,
     310,   311,   311,   311,   311,   311,   312,   312,   312,   313,
     313,   313,   313,   314,   314,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   317,   316,   318,   318,   318,   318,   318,
     319,   319,   319,   319,   320,   320,   320,   321,   321,   321,
     321,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   323,   323,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   326,   326,   326,   326,   326,   326,   326,   326,
     327,   327,   328,   329,   329,   329,   329,   329,   329,   329,
     329,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   330,   330,   330,
     331,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   333,   333,   333,   334,   333,
     335,   333,   336,   333,   337,   333,   333,   333,   333,   333,
     333,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   340,   340,   340,   340,   340,   341,
     341,   341,   341,   341,   342,   342,   343,   344,   344,   345,
     345,   346,   346,   347,   347,   348,   348,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   350,   350,   350,   350,   351,   351,
     351,   352,   352,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   355,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   356,   356,   357,   357,   359,   358,   360,   360,
     361,   361,   362,   362,   363,   363,   363,   363,   363,   364,
     364,   364,   364,   365,   365,   366,   366,   366,   366,   366,
     366,   367,   367,   367,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   369,   369,
     369,   369,   370,   370,   370,   370,   371,   371,   372,   372,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   375,   374,   374,   376,   376,   377,   378,   378,   379,
     380,   380,   380,   380,   381,   381,   381,   382,   382,   382,
     383,   383,   383
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
       1,     1,     5,     5,     2,     7,     7,     4,     3,     6,
       9,     7,     6,     7,     6,     4,     8,     9,     9,     6,
       9,     6,     9,     5,     8,     8,    11,     6,     9,     5,
       7,     9,     9,    11,     7,     9,     9,     0,     1,     0,
       3,     5,     0,     9,     0,    11,     5,     0,     9,     0,
       3,     3,     5,     5,     0,     2,     0,     1,     1,     3,
       2,     2,     2,     1,     4,     2,     2,     0,     2,     1,
       3,     2,     2,     2,     2,     2,     1,     1,     3,     0,
       5,     5,     5,     0,     2,     0,     2,     7,     7,     7,
      10,    10,     8,     8,     7,     7,    11,     7,     8,     8,
       8,     9,     8,     8,     3,     4,    10,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     9,     7,     7,
       8,     8,    12,     0,     9,     1,     1,     1,     1,     4,
       1,     1,     1,     4,     1,     1,     4,     1,     1,     1,
       4,     5,    11,     5,     9,     9,     7,     4,     9,    10,
       9,     1,     1,     0,     2,     6,     7,     7,     6,     7,
       8,    10,    14,    16,    12,    14,    14,    14,    14,     8,
       8,     6,     4,     5,     5,     6,     6,     3,     4,     3,
       5,     6,     5,     4,     3,     4,     3,     4,     5,     4,
       5,     3,     5,     7,     7,     3,     2,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     7,     2,     9,
      11,     2,     4,     2,     2,     2,     2,    16,     5,     8,
      11,     6,     8,     8,    10,     1,     2,     2,     1,     3,
       3,     4,     4,     1,     1,     5,    11,    13,     0,     7,
       0,    13,     0,    15,     0,     6,     9,     2,     3,    10,
      13,     1,     2,     5,     7,     2,     2,     3,     2,     3,
       2,     3,     9,     6,     1,     1,     1,     1,     1,     0,
       2,     3,     3,     4,     9,     4,    14,     0,     3,     0,
       1,     0,     2,     0,     2,     0,     2,     5,     6,     7,
       6,     5,     3,     8,     6,     8,     8,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,     4,     4,
       4,     4,     4,     6,     2,     3,     6,     2,     1,     1,
       1,     2,     5,     7,    10,     1,     3,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       6,     4,     6,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     1,     4,     6,
       1,     4,     4,     4,     6,     5,     7,     8,    10,     4,
       4,     6,     4,     3,     2,     5,     5,     3,     5,     6,
       8,     6,     8,     6,     4,     7,     6,     6,     6,     4,
       6,     4,     0,     2,     0,     2,     0,     7,     1,     3,
       1,     2,     0,     3,     1,     2,     2,     3,     3,    11,
       9,     7,     7,     1,     3,     1,     1,     2,     3,     4,
       5,     1,     3,     1,     2,     3,     3,     5,     4,     4,
       2,     4,     2,     3,     3,     4,     5,     5,     5,     5,
       5,     1,     1,     1,     3,     5,     7,     4,     4,     4,
       6,     6,     8,     8,     4,    14,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     8,     6,     4,
       5,     1,     4,     1,     1,     1,     1,     4,     6,     4,
       6,     5,     7,     4,     4,     4,     8,     4,     4,     4,
       4,     8,     8,     6,     4,     6,     4,     1,     1,     4,
       4,     0,     6,     4,     2,     4,     4,     1,     1,     3,
       1,     1,     3,     3,     3,     5,     7,     5,     5,     8,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   640,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,     0,     0,   207,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   344,   345,   346,   347,
     348,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   305,     0,     0,   313,   314,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,   398,   399,
     400,     0,     0,     0,     5,     6,     7,     8,    10,     0,
      11,    24,    12,    13,    14,    15,    23,    22,    21,    16,
       0,    17,    18,    19,    20,     0,    25,     0,   641,     0,
     233,     0,     0,     0,     0,     0,     0,   283,     0,   285,
     286,   281,   282,     0,   288,     0,   291,   233,     0,   293,
     294,   119,   129,   640,   512,   508,    73,    74,     0,   205,
     206,   207,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   296,     0,
       0,   217,   218,   219,     0,     0,     0,     0,   454,   455,
     457,   458,   456,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   462,   463,   464,     0,     0,   205,   210,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,   460,   461,     0,     0,     0,     0,
       0,     0,     0,     0,   551,   552,     0,   553,   525,   405,
     467,   470,   327,   526,   508,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   210,   211,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   514,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   640,     0,     0,   233,     0,
       0,   394,     0,   397,     0,     0,   214,   215,     0,     0,
     533,     0,     0,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   640,     0,     0,   574,
       0,     0,     0,     0,   279,   280,     0,   591,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,     0,   617,   618,   595,   596,     0,     0,     0,
       0,     0,     0,   594,     0,     0,     0,     0,   306,   307,
       0,   233,     0,   233,     0,     0,     0,     0,   508,     0,
     276,     0,     0,   233,   401,     0,     0,    84,     0,    66,
       0,     0,    70,    69,    68,    67,    72,    71,    73,    74,
       0,     0,     0,     0,     0,     0,     0,   580,   508,     0,
     232,     0,   231,     0,   184,     0,     0,   580,   581,     0,
       0,     0,   630,     0,   631,   581,     0,     0,     0,   117,
     117,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     568,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   408,     0,   407,   534,   409,     0,
     527,     0,     0,   508,     0,   542,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       0,   484,     0,     0,     0,     0,     0,     0,     0,   328,
       0,   361,   361,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,   233,   233,     0,   516,
     515,     0,     0,     0,     0,   233,   233,     0,     0,     0,
       0,   324,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   363,     0,     0,     0,     0,
       0,     0,   233,   259,     0,     0,   257,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     372,   278,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,   309,     0,   264,
       0,     0,   266,     0,     0,     0,     0,   407,     0,   233,
       0,     0,     0,     0,     0,     0,     0,   349,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    88,    75,    76,     0,     0,
       0,   275,    40,   271,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,   234,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,   118,
       0,     0,     0,   510,     0,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   355,     0,     0,     0,   209,
       0,     0,     0,     0,     0,     0,     0,   389,   390,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   465,   483,     0,     0,     0,     0,
     543,   544,     0,     0,     0,     0,     0,     0,   502,     0,
     406,   528,     0,     0,     0,     0,   536,     0,   425,   424,
     423,   422,   418,   419,   426,   427,   421,   420,   411,   410,
       0,   412,   535,   413,   416,   414,   415,   417,   509,     0,
       0,   487,     0,   554,     0,     0,     0,     0,     0,     0,
       0,     0,   359,     0,     0,     0,     0,     0,     0,   392,
       0,     0,     0,     0,     0,   391,     0,   233,     0,     0,
       0,     0,     0,   518,   517,     0,     0,     0,     0,     0,
       0,     0,   318,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   378,     0,     0,     0,
     258,     0,     0,     0,   252,     0,     0,     0,     0,   388,
     406,   532,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   311,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   621,     0,     0,
       0,   504,     0,     0,   263,   267,   265,   269,     0,     0,
     412,     0,   509,   487,   642,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,   406,     0,     0,
       0,    66,     0,     0,    87,     0,    66,    67,     0,     0,
       0,   509,     0,     0,   487,     0,     0,     0,   203,     0,
       0,     0,   637,    28,    26,    27,     0,     0,     0,     0,
       0,   584,    30,     0,    29,     0,     0,   272,   632,   633,
       0,   634,   584,     0,     0,    82,   120,    83,   130,   511,
     513,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   570,   571,   298,   233,
     220,     9,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   451,   438,     0,   440,   441,   442,   443,   444,   567,
     445,   446,   447,     0,     0,     0,     0,     0,   559,   558,
     557,     0,     0,     0,   564,     0,   499,     0,     0,     0,
     501,     0,     0,     0,     0,   134,   482,   539,   538,   213,
       0,     0,     0,   468,   566,   473,     0,   479,     0,     0,
       0,     0,   529,     0,     0,   480,   545,   541,     0,     0,
       0,     0,   472,   471,    73,    74,   494,     0,     0,     0,
       0,     0,     0,     0,   406,   357,   362,   360,     0,   371,
       0,   156,   157,     0,   213,     0,   406,     0,     0,     0,
       0,     0,   253,     0,   268,   270,     0,     0,     0,   221,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   331,     0,   315,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,   364,   377,     0,
       0,     0,     0,   254,     0,     0,     0,     0,   216,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,     0,     0,     0,   607,     0,   614,   603,
     604,   605,     0,   620,   619,     0,     0,   608,   609,   610,
     616,   624,   623,     0,   147,     0,   597,     0,   599,     0,
       0,     0,   592,     0,     0,   262,     0,     0,     0,     0,
       0,     0,     0,   350,     0,     0,     0,   402,     0,   638,
       0,   109,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,   589,
      51,     0,     0,     0,    64,     0,    41,    42,    43,    44,
      45,    46,     0,   472,   471,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   583,   582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,   137,   138,     0,     0,     0,     0,   163,
     163,     0,     0,     0,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   546,   547,   548,   549,     0,     0,   550,
       0,     0,     0,   502,   503,     0,   475,     0,     0,   537,
     428,   530,   488,   486,     0,   485,     0,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,     0,
       0,     0,     0,     0,   393,     0,     0,     0,    77,     0,
     261,     0,     0,     0,     0,     0,     0,     0,   336,     0,
       0,   335,     0,   338,     0,   340,     0,   325,   332,     0,
       0,     0,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   379,     0,     0,   256,   255,   396,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,   575,
       0,     0,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,   505,   601,     0,   374,
     488,     0,     0,   233,   351,     0,   352,   233,     0,     0,
     590,     0,    94,     0,     0,     0,     0,    92,     0,   578,
       0,   107,     0,    99,   101,     0,     0,     0,    89,     0,
       0,     0,     0,     0,    36,   488,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,    32,
       0,   585,     0,     0,    34,    33,     0,   585,   635,   287,
       0,     0,   121,   126,     0,     0,     0,   140,   145,   146,
     141,   142,   507,     0,    85,     0,    86,   167,     0,     0,
       0,     0,   168,   187,   188,   165,     0,     0,     0,   169,
     198,   189,   193,   194,   190,   191,   192,   177,     0,     0,
       0,   439,   453,   452,   448,   449,   450,   560,     0,     0,
       0,   497,   498,   500,   135,   466,   496,   469,   474,     0,
       0,   502,   199,   481,    73,    74,     0,   493,   489,   491,
     561,   195,     0,     0,     0,   159,     0,     0,   369,     0,
     158,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   233,   233,     0,     0,   337,   525,     0,     0,
     339,   341,     0,     0,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,   196,     0,     0,     0,
       0,     0,     0,     0,   174,     0,   175,     0,     0,     0,
       0,   110,   114,     0,   615,     0,     0,   613,     0,   625,
       0,     0,   148,   149,   622,   598,   600,     0,     0,     0,
       0,     0,     0,   349,   353,   349,     0,   403,    93,     0,
       0,    66,     0,     0,    91,     0,   576,     0,     0,     0,
       0,     0,     0,   628,   627,     0,     0,     0,     0,     0,
     523,     0,     0,    77,   273,   489,   274,     0,     0,     0,
       0,     0,   238,   235,     0,     0,   588,   586,     0,     0,
       0,     0,   122,   127,     0,     0,     0,   568,   569,   139,
     373,   164,   172,   173,   178,     0,     0,     0,     0,     0,
     180,     0,     0,   299,     0,     0,     0,     0,   476,     0,
       0,     0,   556,   495,     0,     0,   179,     0,   200,   358,
       0,     0,     0,     0,   201,     0,     0,     0,     0,     0,
       0,   522,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   240,     0,     0,     0,   375,   376,    39,
     182,   183,     0,   573,     0,     0,   303,   302,     0,     0,
       0,     0,     0,     0,   151,   152,   155,   154,   153,     0,
     602,     0,   639,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   579,     0,     0,     0,    96,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    49,     0,   239,
     236,   237,    35,     0,     0,   636,   289,     0,   134,   147,
       0,     0,   144,     0,     0,     0,   166,   197,     0,     0,
       0,     0,     0,   562,   563,     0,   502,   477,   490,   492,
       0,     0,   181,   204,     0,     0,     0,   365,   365,     0,
     115,   116,   233,     0,   224,   225,   326,     0,   333,     0,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,   228,     0,     0,     0,     0,   111,   112,   606,
     612,   611,   150,     0,     0,     0,   354,     0,     0,   108,
     100,   102,     0,    90,   629,    97,    98,    52,     0,     0,
       0,     0,   524,     0,     0,   490,   587,     0,     0,     0,
       0,   124,   626,     0,   131,     0,     0,     0,     0,   186,
       0,     0,     0,   329,     0,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   520,     0,   343,
       0,     0,   320,     0,   241,     0,     0,     0,     0,     0,
       0,   229,     0,   572,   304,     0,     0,   387,   233,   404,
       0,   577,     0,    48,     0,     0,     0,    65,    50,     0,
     290,   123,   128,   134,     0,     0,   161,   162,   160,     0,
       0,   478,     0,     0,     0,     0,   366,   380,     0,     0,
     381,     0,   222,     0,   334,     0,   316,     0,   233,     0,
       0,     0,     0,     0,     0,   176,   113,   300,   349,   106,
       0,     0,     0,     0,     0,     0,   132,   133,     0,     0,
       0,   202,     0,   384,     0,   385,   386,   519,     0,     0,
     322,   244,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,    62,     0,     0,   125,     0,     0,   330,     0,
       0,   342,   321,   317,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,   248,     0,   242,   356,    53,
       0,    60,     0,   284,     0,   565,     0,     0,   323,     0,
       0,    54,     0,     0,   297,     0,     0,   243,     0,     0,
       0,     0,     0,     0,    57,    55,     0,    58,     0,   382,
     383,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   124,  1116,   125,   126,  1100,  1980,  1986,
    1406,  1629,  2142,  2270,  1407,  2243,  2286,  1408,  2272,  1409,
    1410,  1633,   461,   621,   622,  1188,  1727,   127,   820,   489,
    1998,  2153,  1999,   490,  1866,  1488,  1442,  1443,  1444,  1592,
    1802,  1803,  1260,  1688,  1679,  1876,   795,   633,   292,   293,
     369,   215,   294,   471,   472,   131,   132,   133,   134,   135,
     136,   137,   138,   295,  1295,  2177,  2234,   990,  1291,  1292,
     296,  1079,   297,   142,  1517,  1258,   962,  1005,  2111,   143,
     144,   145,   146,   298,   299,  1215,  1231,  1361,   300,   825,
     301,   824,   492,   650,   336,  1839,   373,   374,   303,   591,
     388,  1390,  1620,   482,   477,  1354,  1055,  1669,  1832,  1833,
    1040,   484,   148,   438
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1971
static const yytype_int16 yypact[] =
{
   13695,    75,   125, 13903, -1971, -1971,  -156,    34,    66,   -79,
     -59,   -44,    52,   381,   393,   429,   456,    10,    53,    57,
      80,   508,   521,   268,   278,    22,   517,    13,   517,    97,
     289,   294,    12,   319,   325,    23,   328,   335,   380,   421,
     436,   448,   461,   467,   490,   530,   389,   500,   691,   778,
     812,   565,   566,   359,   711,   586,  7161,   593,   592,   606,
     752,   -31,   601,    13,   -48,   237,   624,   785,   -99,   643,
    -116,  -116,   669,   221,   371,   689, -1971, -1971, -1971, -1971,
   -1971,   631,   684,   804,   855,    35,    45,   962,   864,   874,
       9,  6129,   882,   991,  1007,  1017,  6129,  1018,   -78,   -75,
     784,    25,    71, -1971,   789,   790, -1971, -1971,  1042,  1045,
     792, -1971, 14152,   795, 14189,    33,    37,    13, -1971, -1971,
   -1971, 12404,   794,  1046, -1971, -1971, -1971, -1971, -1971,   793,
   -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971,
    -138, -1971, -1971, -1971, -1971,     4, -1971,  1052,   791,  5869,
     351,   796,  1056, 12404, 14090, 14090, 14090, -1971, 12404, -1971,
   -1971, -1971, -1971, 14090, -1971, 12404, -1971, -1971, 12404, -1971,
   -1971, -1971, -1971,   798,   803,  1055, -1971, -1971,  1436, -1971,
   -1971, -1971, -1971,   807,  1436, 12404, 12404, 12404,   808, 12404,
   12404, 12404,   809, 12404, 12404, 12404, 12404, 12404, 12404, 12404,
   14090, 12404, 12404, 12404, 12404,  6129,   810, -1971, -1971,  9989,
    9989, -1971, -1971, -1971,   813,  6129,  7419, 14090, -1971, -1971,
   -1971, -1971, -1971,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   638,   517,
     517,   517,   517,   517,   811,   517,   517,   814,    13,   584,
     584,   584, -1971, -1971, -1971,   517,   517,    41,   876,   877,
     880,   816,  7419,   948,    13,    13,   584,   823,   517,   517,
     824,   825,   828, -1971, -1971, -1971, 12404,  7677, 12404, 12404,
    7935,    22,   893,    42, -1971, -1971,   826, -1971,  3848, -1971,
   -1971, -1971, -1971, -1971,   110, 12404,  9989,  9989,   831,   832,
    8193,  6129,  6129,  6129, -1971, -1971, -1971,   833, -1971,   830,
     836,  8451,   834, 10945,  1093,  7419,   835,    25,   837,   838,
    -116,  -116,  -116, 12404, 12404,   338, -1971,   349,  -116, 11032,
     368,     1,   840,   845,   846,   847,   849,   850,   856,  9989,
   12404,  6129,  6129,  6129,   155,    17,  1109,   858, -1971,  1111,
    1112, -1971,   857, -1971,   859,   860, -1971, -1971,   862,  6129,
   -1971, 12404,  6387, -1971,  1115,   866,   863,   869,   870,  1122,
    1127,   878, 12404,   879, 12404, 12404,   652, 12404,   873, -1971,
     938, 12404, 12404, 12404, -1971, -1971, 12404, -1971,   517,   517,
     517,   881,   885,   889,   517,   517,   517,   517,   517,   517,
     517, -1971,   517, -1971, -1971, -1971, -1971,   517,   517,   900,
     901,   517,   905, -1971,   904,  1134,  1136,   903, -1971, -1971,
    1163,  1180,  1183,  1182,   931,   517, 12404, 15599,   122, 14090,
   -1971,  9989, 12404, -1971, -1971,  7419,  7419, -1971,   929,  1436,
      13,  1188, -1971, -1971, -1971, -1971, -1971, -1971, 12404, 12404,
     410,  7419,  1191,   507,   934,  1012,   935,  1194,    36,   937,
   -1971,   942,  2576, 12404, -1971,  1659,  -169, -1971,    74,  -111,
     -46,  7609, -1971,   -21, -1971,   111,  7867, 12536,  8125,  -124,
     -14,  1105, -1971,    22,   939, 12404,   958, 16115, 16140, 16165,
   12404, 16190, 16215, 16240, 12404, 16265, 16290, 16315, 16340, 16365,
   16390, 16415,   967, 16440, 16465, 16490, 14613,  1196, 12404,  9989,
    5754, -1971,     8,   172, 12404,  1223,  1226,   973, 12404, 12404,
   12404, 12404, 12404, 12404, 12404, 12404, 12404, 12404, 12404, 12404,
   12404, 12404, 12404, 12404,  9989, 12404, 12404, 12404, 12404, 12404,
   12404, 12404, 12404,  9989,  9989,   971, 12404, 12404, 14090, 12404,
   14090,  7419, 14090, 14090, 14090,   974,   975,   977,   978, 12404,
      51, -1971, 11290, 12404,  7419,  6129,  7419,   979, 14090, 14090,
    9989,    22,  1436,    22,   985,  9989,   985, -1971,   985, 16515,
   -1971,   206,  1001,    81,  1169, -1971,  1229, 12404, 12404, 12404,
   12404, 12404, 12404, 12404, 12404, 12404, 12404, 12404, 12404, 12404,
   12404,  8709, 12404, 12404, 12404, 12404, 12404,    22, 12404, 12404,
      50, -1971,   782, 16540,   374,   383, 12404, 12404, 12404, -1971,
    1238,  1261,  1261,  1009, 12404, 12404, 12404, 12404,    26,  9989,
    9989, 15627,  1011,  1264, -1971,  1010, -1971, -1971,   -73, -1971,
   -1971,  8383,  8641,  -116,  -116,   351,   351,   -49, 11032, 11032,
   12404, 12580,   -45, -1971, 12404, 12404, 12404, 12404, 12404, 12404,
   12404, 12404, 12404,   433, 16565,  1266,  1269,  1270, 12404, 12404,
    1272, 12404, -1971, -1971, 12404, 12653, -1971, -1971,  9989,  9989,
    9989, 12404,  1273, 16590,  1015, 12404,  9989, 12404, 12404, 12404,
   -1971, -1971, 12404, 16615, 12404, 16640, 16665,  1083,  8899, -1971,
    1020,  5777, 16690, 16715, 15710, 14090, 14090, 14090, 14090, 14090,
   14090, 14090, 14090, 14090, 12404, 14090, 14090, 14090, 14090,    19,
    1436, 14090, 14090, 14090,    22,    22, -1971, -1971,  9989, -1971,
    1016, 12714, -1971,  1021, 12817, 12404, 12404,   985, 12404, -1971,
      22, 12404, 12404,    50,  1022,   468, 16740, 14318,  1026,   487,
   12404,  1282,  1025,  7419, 16765, 15737, -1971, -1971, -1971, -1971,
   -1971,  1024,  1284,   160,  1286, -1971, -1971, -1971,  9989,    24,
   12404, -1971, -1971, -1971,    22, 12404, 12404,    50,  1031, -1971,
    1035,   -17,    13,   -48,    13, -1971,  1032, 14642, -1971,   148,
    9989,    22, 12404, 12404,    50,  1291,  9989,  1292,  9989, 12404,
    1295, 14090,    22, 11377,    50, 12404, -1971, 12404,  1296, -1971,
      22,  1299, 14090, 12404,  1047,  1044, -1971, 12404,  9152,  1436,
    1300,  1302,  1303, 16790,  1305,  1306,  1307, 16815,  1308,  1310,
    1311,  1312,  1313,  1314,  1316, -1971,  1319,  1320,  1321, -1971,
   12404, 16840,  9989,  1065,  9989,    59, 14671, -1971, -1971,  1324,
   15683, 15683, 15683, 15683, 15683, 15683, 15683, 15683, 15683, 15683,
   15683,  9405, 15683, 15683, 15683, 15683,   933,   552, 15683, 15683,
   15683,  9663,  9921, 10273, 10627, 10892,  5754,  1070,  1069,    96,
    9989, 10976, 11237,   552, 11321,   552,  1066,  1067,  1068,   120,
    9989, 12404, 12404, 12404, 17790, -1971,   552,  1073, 14700, 14729,
   -1971, -1971, 12404,  1071,   265,   552,   -28,  1080,   197,   524,
    1335, -1971,    50,   552,  7419,  1079,  5800,  6061,  1216,  1946,
     591,   591,   -61,   -61,   -61,   -61,   -61,   -61,   513,   513,
    9989,  -185, -1971,  -185,  -185,   985,   985,   985,  1081, 16865,
   15764,   497,  9989, -1971,  1338,  1082,  1085, 16890, 16915, 16940,
   12404,  7419,  1346,  1345, 10692, 16965, 14758, 16990, 17015, -1971,
   12404,   526,   535,  9989,  1087, -1971, 12878, -1971, 12951, 12995,
    -116, 12404, 12404, -1971, -1971,  1090,  1091, 11032,  4973,  1214,
     471,  -116, 13131, 17040, 14787, 17065, 17090, 17115, 17140, 17165,
   17190, 17215,  1095,  1353, 12404,  1355, -1971, 12404, 17240, 14816,
   -1971, 15791, 13175, 15818, -1971,   537,   542,   545, 14845, -1971,
   -1971, -1971,  1710,   547, 15845, 15872, 11585, 17265,  1356, 17290,
    1357,  1358,  1096, 12404, 13248, 12404, 12404, -1971, -1971,    49,
     305,   434,   305,  1106,  1108,  1101,   552,   552,  1102, 11661,
     552,   552,   552,   552, 12404,   552,  1363, -1971,  1107,  1113,
     438,   226,  1114,   557, -1971, -1971, -1971, -1971, 17315, 15683,
    -185, 13309,  1116,   525,  1110,  1179,  1373,  1219, 11630,  1120,
    1117,  1381,  7419, 14874, -1971, 12404,  1382,   170,    94,    50,
      31,  1436, 12404,  1383, -1971,   558,  1341,  1364,  7419, 14903,
      46,  1146, 17340, 15899,   516, 12404, 12404,  1154,  1153,  1160,
    1158,  8967, -1971, -1971, -1971, -1971, 14090,   163,  1161, 17365,
   15926,  1166, -1971,   235, -1971,   236, 11924, -1971, -1971, -1971,
    1162, -1971,  1170, 14932, 12008, -1971,    73, -1971, -1971, 17790,
   -1971,    48, 15683, 12404,   552,  -116,  7419,  7419,  1422,  7419,
    7419,  7419,  1424,  7419,  7419,  7419,  7419,  7419,  7419,  7419,
    7419,  7419,  7419,  1805,  1425,  9989,  5754, -1971, -1971,   351,
   -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971,
   -1971, -1971, -1971, 12404, -1971, -1971, -1971, -1971, -1971, -1971,
   -1971, -1971, -1971, 12404, 12404, 12404, 12404, 12404, -1971, -1971,
   -1971,   563, 12404, 12404, -1971, 12404, -1971,  7419, 14090, 14090,
   -1971,   583, 14961, 14990, 15019,  1164, -1971, -1971, -1971,  1239,
   15048, 12404, 12404, -1971, -1971, -1971,    50, -1971,    50, 12404,
   12404,  1173, -1971,  7419,   517, -1971, -1971, -1971, 12404, 12404,
     589,    50,   372,   -40, 12404, 12404, -1971,   552,   590,  7419,
    9989,  9989,  1430,  1431,  1435,  2398, -1971, -1971,  1437, -1971,
    1184, 17790,  1175,  1439, -1971,  1440,  1442,  2001,  1444,  1446,
     596,    60, -1971, 13412, -1971, -1971,   -27, 12264, 12359, -1971,
   -1971, 15077,   -92,  1354,  1469, 11724,  1212,  1472,  1220,    30,
      38,   -38, -1971,   181, -1971,   471,  1474,  1473,  1475,  1476,
    1487,  1488,  1489,  1490,  1495,   351,  7419, 17790, -1971,  2056,
    1240,  1403,  1507, -1971,  1510,  1515,  1415,  1517, -1971, -1971,
    1519,  1522,  1524, 12404,  1525,  7419,  1526,  7419,  7419,  1531,
   12921, -1971,  6319,   972,    50,    50, -1971,  9989, -1971, -1971,
   -1971, -1971, 14090, -1971, -1971, 12404, 14090, -1971, -1971, -1971,
   -1971, 17790, -1971,  1274,  1267, 14090, -1971, 14090, -1971,    50,
   14090,  1278, -1971,  1275,  1536, -1971,    50, 12404, 12404,  1281,
      13,  1283, 11977, -1971,  2164,  1285,  7419, -1971,  1287, -1971,
   15106, -1971, -1971, 12404,  1544,   412, 12404,  1545,  1546,    25,
    1548,  1293,  1551,  2207, -1971,   552,   517,   517,  1552, -1971,
   -1971,  1301,  1304,  1298, -1971,  1553, -1971, -1971, -1971, -1971,
   -1971, -1971,    50,   377,  2279, 12404, 15953, 17390, 12404,  9220,
   12404,  9989,  1309,   597,  1557,   164,    50, -1971,  1325, 12404,
    1559,  1560, 12404,    50, 12064,  1561, 12404, 10242,   552,  5254,
   12404, 12404,  1322,  1326, -1971,  1562, 17415,  1563,   137,  1433,
    1433,  7419,  1566,  1569,  1592,  7419,  -107,  1593,  1594,  1595,
    1597,  1598,  1600,  1601,  1602,  1603, -1971,  1605,   602,  1347,
   15683, 15683, 15683, 15683, 15683, 15683,   552, 12954, 13478, 13693,
    1350,   552,   552, -1971, -1971, -1971, -1971,    48,   552, -1971,
   17440, 15683,  1352,  -190, 17790, 15683, -1971,  1608,   552, 17790,
   17790, -1971,   676, -1971,    50, -1971, 17465, 15980, -1971,   552,
    1610,   603,   604,  7419,  7419,  7419,  1613,  1614, -1971,   177,
   12404,  7419,  7419,  7419, -1971,  1361,  1362,  1612,  1615,  1620,
   -1971, 12404, 12404, 12404,  1366,  1367,  1368,  1360, -1971,  2275,
    7419, -1971, 12404, -1971,  1622, -1971,  1627, -1971, -1971, 11032,
     363,  6645, -1971,  1370,  1372,  1374,  1375,  1376,  1377,  9473,
    1378,  1631, -1971,  9989,  1388, -1971, -1971, -1971,  1390, 12404,
   12404, -1971, -1971, 16007,  7419,  1636,  7419,  1639,  1454, -1971,
   12404, 12404, 12404, -1971,  1650,   733,   475,  1392,  3012,  1393,
   12404,    20,   552,  1396,   552,  1398, -1971, -1971,  1436, -1971,
     692, 12404,  1395, -1971, -1971,  2590, -1971, -1971,  1399,  1663,
   -1971,  2655, -1971,  1404,  1664,   187,  3467, -1971,    25, -1971,
     610, -1971, 12404, -1971, -1971,   177,  3815,  4749, -1971,  1413,
   12404, 12404,  7419,  1410, -1971,   101,    67,  1670, 17490,  1672,
    1335, 17515,  1414,   611, 17540,   612,  1674,  1675, -1971, -1971,
   14090,  1426,  1678, 17565, -1971, -1971, 14098,  1427, -1971, -1971,
    6577,  5601, 17790, -1971,  1677,   517,  7935, -1971, -1971, -1971,
   17790, 17790, -1971,    48, -1971,  1679, -1971, -1971,  -116,  1682,
    1683,  1684, -1971, -1971, -1971,  1547,   -26,  1586,  1687, -1971,
   -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971,  1689,  1432,
    1691, -1971, -1971, -1971, -1971, -1971, -1971, -1971, 12404, 12404,
   12404, -1971, -1971, -1971,  1326, -1971, -1971, -1971, -1971, 12404,
    1434,  1429, -1971, -1971, 12404, 12404,   552,   372, -1971, -1971,
   -1971, -1971,  1441,  1453,  1695,  -107,  1712, 12404, -1971,  7419,
   17790,  1575,  1576,   970,  9989,  9989, 12404, -1971, 10692, 15135,
   17590,  6835,   351,   351, 12404, 12404, -1971,   423,  1452, 17615,
   -1971, -1971, 15164,   191, -1971,  1717,  1718,  7419,  -116,  -116,
    -116,  -116,  -116,  6903,  1719, -1971, -1971,   617,  9989, 12404,
    3816,  4044,  1720,  1721, -1971,  1722, -1971,  7419,  7093,   788,
   17640, -1971, -1971, 10338, -1971, 14090, 12404, -1971, 14090, 17790,
   10596,  1436,  1462, -1971, -1971, -1971, -1971,  1471,  1464, 12404,
   12404, 15193, 12404, 14318, -1971, 14318,  7419, -1971, -1971,    50,
      31,  1436, 12404,  1728, -1971,  1729, -1971,    25, 16034,  7419,
   14090,  1731,   552, -1971,  1470,   552, 12404, 14250, 14283,   620,
   -1971, 12404, 12404,  1479, -1971,  1481, -1971,  1435,  1732,  1734,
    1442,  1740, -1971, -1971,  1741, 12404, -1971, -1971, 12404, 12317,
    1742, 12404, -1971, -1971,  1485,  4749,   627,  1156,  1746, -1971,
   -1971,   442, -1971, -1971, -1971,  1606,  1749,  1492,  1493,  1494,
   -1971,  1754,  7419, -1971, 15683, 15683, 14316, 15683, -1971,  1500,
   17665, 16061, -1971, -1971,  9989,  9989, -1971,  1756, -1971, 17790,
    1757, 12404, 12404,  1501, -1971,   648,   658, 15655,  4130,  1760,
    1503, -1971, -1971, 12404,  1504,  1506, 15222, 16088,  1762,  7419,
    1765,  1512, 12404, -1971, -1971,   660,   203,   205,   207,   230,
     240,  9731,   264, -1971,  1768,   663, 15251, -1971, -1971, -1971,
   -1971, -1971,  1587, -1971, 12404, 12404, -1971, -1971,  9989,  4534,
    1771,  1518, 15683,   552, 17790, -1971, -1971, -1971, -1971,    20,
   -1971,  1436, -1971, 15280,  1516,  1520,  1523,  1773,  1776,  1777,
    4744, -1971, -1971, -1971,  1521,  1783,   665, -1971,  1784,  1785,
     270, 17790, 12404, 12404,  1529,  7419,   666, 17790, 17690, -1971,
   -1971, -1971, -1971, 17715, 14349, -1971, -1971, 15309,  1164,  1267,
    7419,   552, -1971, 12404,  1436,    22, -1971, -1971,  9989,  9989,
   12404,  1788,   674, -1971, -1971, 12404,  1429, -1971, -1971, -1971,
     679,   681, -1971, -1971,  4887,  4940,  7419,    14,   444,  9989,
   -1971, -1971,   351,  7351, -1971, -1971, -1971,  1790, -1971,  1532,
    7419, -1971, 15338,  1792,  9989,  -116,  -116,  -116,  -116,  -116,
   -1971,  1793, -1971, 12404, 15367, 15396,   682, -1971, -1971, -1971,
   -1971, -1971, -1971,  1539,  1795,  1540, -1971,  1797,    25, -1971,
   -1971, -1971,  1611, -1971, -1971, -1971, -1971, -1971, 12404, 14382,
   14415,  7419, -1971,  1800, 12404,  1543, -1971, 12404,  1802,  1549,
    1550, -1971, -1971,  5332, -1971,  1556,   690,   696, 15425, -1971,
    1554, 14448,  1558, -1971,  1564, -1971, -1971,   697,  1565,  -116,
    7419,  1803,  1567,  -116,  1804,   698,  1555, -1971, 12404, -1971,
    1806,  1681, 13473,  1568, -1971,   706,   296,   315,   321,   343,
     352, -1971,  5189, -1971, -1971,  1815,  1816, -1971, -1971, -1971,
    1817, -1971,  1570, 17790, 12404, 12404,   712, -1971, 17790, 14481,
   -1971, -1971, -1971,  1164,  1436,  1574, -1971, -1971, -1971, 12404,
   12404, -1971,  9989,  1824,  -116,   149, -1971, -1971,  -116,   153,
   -1971,  1830, -1971, 15454, -1971, 12404, -1971,   471, -1971,  1832,
    9989,  9989,  9989,  9989,  9731, -1971, -1971, -1971, 14318, -1971,
   12404, 17740, 14514,    61, 12404,  1577, -1971, -1971, 14547, 14580,
     714, -1971,   362, -1971,   378, -1971, -1971, -1971,  5294,   373,
   13546, -1971,   719,   720,   722,   727,   409,   732,  1578,   735,
   -1971, 12404, -1971,  7419, 15483, -1971, 12404, 12404, -1971,  -116,
    -116, -1971, -1971, -1971,   471,  1835,  1838,  1839,  1840,  9989,
    1841,  1842,  1843,  1588, 17765,   737,  1844, 15512, 15683,   431,
     435,   445, -1971, -1971, -1971, -1971,   738, -1971, -1971, -1971,
   14090, -1971,  1590, -1971,  1845, -1971, 12404, 12404, -1971,  1849,
     743, -1971,  1596,  7419, -1971, 15541, 15570, -1971,  1850, 14090,
   14090,   744,  1851,  1852, -1971, -1971,   754, -1971,  1855, -1971,
   -1971,  1863, 14090, -1971, -1971, -1971
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1971, -1971, -1971, -1971,   446, -1971, -1971, -1971, -1971,  -320,
   -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971, -1971,
   -1971, -1971,  -768,  -131,  4473,  3614,  -440, -1971,  1384, -1971,
   -1971, -1971, -1971, -1971, -1971, -1970, -1971,   385,   202,  -123,
   -1971,   -82, -1971,   147,   437, -1971,  1880, -1971,   861,   -51,
   -1971, -1971,    -1,  -649,  -153, -1971, -1971, -1971, -1971, -1971,
   -1971, -1971,   786,  1881, -1971, -1971, -1971, -1971, -1294, -1287,
    1882, -1798,  1886, -1971, -1971, -1971,  1262, -1971,  -135, -1971,
   -1971, -1971, -1971,  2418, -1971, -1971, -1484,   320,  1911, -1971,
       0, -1971, -1971,    95, -1971, -1755,   553,   -77,  2992,  2787,
    -324,    99, -1971,   183,   -71, -1971, -1971,   117,   293, -1766,
    -155,  1119, -1971,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -589
static const yytype_int16 yytable[] =
{
     149,  1550,   130,   645,  1548,  1092,   985,   986,   483,  1720,
     444,  1098,  1925,   321,   487,  1964,   188,  1965,   462,   379,
     773,   680,   175,   173,  1800,   174,   173,   192,  2089,   386,
     381,  1096,   969,   383,  1957,   173,  1543,  1686,   430,   355,
     173,   425,   432,   429,  1545,   784,   571,   595,   152,   360,
    1400,   361,  1439,   304,   766,   173,  1334,   315,   157,   164,
     316,   317,   318,   166,  1528,  1168,   326,  2222,   614,   615,
     176,  1843,   177,   319,   616,   390,  1877,   309,   467,  1229,
    1437,     4,   359,   801,  1440,  1441,   767,   768,   304,  1687,
     493,   309,   799,   304,   327,  1878,   767,   768,   389,  2001,
     800,  1382,   310,   767,   768,   617,  1284,   494,   150,   426,
     328,   329,   151,   496,   366,   179,  1107,   367,   180,   617,
     812,   181,   442,   182,  1285,     5,   443,  2012,   517,   356,
     368,   750,   331,   332,    46,  1286,  1287,  1288,   525,   818,
     320,  1289,  1290,  1677,   333,   819,   468,   362,   334,   470,
     805,   478,   478,   478,  1113,  2203,   653,   654,   806,  2205,
     485,   769,   770,  2108,  2109,   335,   337,  1091,   340,  2110,
    1649,   769,   770,  1535,   153,   653,   654,  1382,   769,   770,
     951,   154,   382,  2195,  1382,   384,   661,   609,   610,   748,
     612,   613,   614,   615,  1821,   970,   980,   478,   616,   653,
     654,   155,   304,   653,   654,   685,   304,   304,   566,   567,
     568,  1544,   304,   304,   478,   807,   156,   456,   457,  1546,
     987,   653,   654,   808,   991,   577,  1504,  1547,  1801,  1401,
    1402,  1403,  1404,  1225,   630,   631,   632,  1889,  1226,   357,
     810,   102,  1531,   103,   104,   105,   106,   107,   811,   821,
     122,   111,   112,   122,   114,   819,   122,   452,   453,   454,
    1097,   664,   122,  1548,   445,   665,   122,   122,   446,   304,
     163,  2107,   189,   853,   675,   676,   677,   854,   741,   681,
     744,   682,   122,   193,   304,   151,  1054,   304,   593,   387,
     757,   592,   692,   456,   457,  1389,   785,   431,   786,   358,
    -581,   433,   787,   304,   304,   572,   596,   304,   304,   304,
     304,  1405,   776,  1073,   777,  1335,   158,   165,   304,  1383,
    1386,   167,   304,  1169,   389,  2223,  2146,   452,   453,   454,
     455,   391,   466,   176,   802,   177,   803,   476,   479,   480,
     804,   176,   322,   177,   168,   323,   304,  1104,   304,   304,
     304,   456,   457,   456,   457,   469,   618,   185,   619,  1200,
    1385,  1842,   620,  1810,  1121,  -585,   304,   456,   457,   304,
     618,   813,   619,   803,  1132,   341,   620,   814,   761,   456,
     457,  1210,   751,   512,   752,   653,   654,   159,   753,   811,
    2218,  1114,  1115,   452,   453,   454,   455,   653,   654,   160,
     527,   653,   654,   452,   453,   454,   455,  1114,  1115,   899,
     452,   453,   454,   455,   766,   678,   766,   456,   457,   679,
     452,   453,   454,   455,  1425,   648,   649,   456,   457,   653,
     654,   597,   854,   657,   662,   161,   478,   855,   304,   653,
     654,   854,   304,   304,   456,   457,   767,   768,   767,   768,
    1549,   653,   654,   653,   654,   653,   654,   176,   304,   177,
    1922,   211,   162,  1228,   212,   788,  1229,   213,  2245,   331,
     332,   921,  2044,   342,  2045,   854,  2046,   343,   653,   654,
     214,   333,  1234,   344,   345,   339,   346,   347,   653,   654,
     826,   976,  1359,   978,   979,  1360,  1430,  1431,   910,  2047,
      69,    70,    71,    72,   854,   854,    75,  1284,   348,  2048,
     992,   917,   653,   654,   169,    84,   304,  1284,  2281,    88,
    1469,   769,   770,   769,   770,  1285,   776,   170,   777,  1012,
     171,  2077,  2102,  2049,  1222,  1285,  1286,  1287,  1288,  2078,
     172,   304,  1289,  1290,   653,   654,  1286,  1287,  1288,   186,
     304,   889,  1289,  1290,   187,   478,  1034,   478,   304,   478,
     478,   485,  1042,   653,   654,  2180,   776,   906,   777,   653,
     654,   304,   304,   304,   811,   478,   478,   304,   175,   190,
     175,   916,   304,   918,  2181,   191,   653,   654,   194,  1284,
    2182,   653,   654,  2112,  2113,   195,  1071,   653,   654,  2110,
     653,   654,   655,   771,   772,  1613,  1614,  1285,   304,   302,
     653,   654,  2183,   656,   948,  1284,   653,   654,  1286,  1287,
    1288,  2184,   754,   205,  1289,  1290,   653,   654,  1764,   456,
     457,  2229,   663,  1285,   456,   457,   304,   304,  2232,   955,
     196,  -583,  1093,   854,  1286,  1287,  1288,  2230,   956,  1388,
    1289,  1290,   854,   204,   470,   470,  1560,   653,   654,  1057,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,  2239,   653,
     654,   197,   616,   653,   654,   304,   304,   304,  1918,   315,
     653,   654,   316,   304,   318,   776,   198,   777,  1002,   776,
    2266,   777,   854,  1337,  2267,   319,   311,  1357,   199,   312,
    2268,   313,   485,   478,   485,   478,   478,   478,   478,   478,
     478,   200,   478,   478,   478,   478,  1056,   201,   478,   478,
     478,   175,  1062,  1075,  1061,   304,   776,   854,   777,  1792,
    1793,   893,  1109,   895,   854,   897,   898,  1072,   983,   984,
     202,  1739,  1081,   649,   456,   457,  1082,  1244,  1144,  1245,
     304,   913,   914,   748,   612,   613,   614,   615,   776,   526,
     777,   778,   616,   456,   457,   304,  1415,   176,  1368,   177,
    -584,  1101,   456,   457,   207,  1367,  1492,  1368,  1493,  1232,
     203,  1268,   351,   854,   352,   854,  1945,   304,  1118,   206,
    1269,  1502,  1315,   304,   854,   304,   854,  1316,   485,  1130,
    1317,   854,  1320,   776,   854,   777,   854,  1136,   208,   478,
    1246,   216,  1363,  1395,  1273,   302,   854,   854,  1476,   209,
     210,  1529,   854,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,   217,  1822,  1483,   304,
     616,   304,   854,   305,  1501,  1509,   306,  1829,   854,   854,
     308,  1527,  1647,   629,   129,   854,   854,  1699,  1732,  1733,
     307,   854,   854,   854,   638,  1826,  1849,  1851,   643,  1827,
     854,   854,  1934,  2209,   324,  1984,   854,   304,   183,  1985,
     325,   350,  2002,  1262,  1584,  1585,  2003,   304,   553,  1041,
     554,  1043,  1044,  1045,  1046,  1047,  1048,   330,  1050,  1051,
    1052,  1053,   353,  2027,  1058,  1059,  1060,   854,   707,  1595,
     151,   304,  1548,  2028,   314,  2043,  1600,   854,  2051,  1985,
    2074,  2083,   854,   338,   811,  2084,  1724,   304,  1725,  2100,
    2251,   597,  1246,  1985,  2103,  1615,  2104,  2135,   854,   304,
     854,   854,  1809,   349,  1810,  2156,  1384,  1387,   304,   854,
     354,  2157,  2163,  2171,  1548,   854,  1985,   854,   363,   364,
     304,  2179,  1635,  1246,  1903,   854,  1904,  2193,   434,  2228,
    1582,  1985,   365,   854,  2235,  2236,  1651,  2237,   854,   854,
     375,   854,  2238,  1657,  1128,   376,   854,  2240,   758,   759,
    2242,   854,  2262,  2269,  2084,  1138,  1985,   854,  2278,  2288,
     464,   377,  2279,  1985,   774,   464,   464,   464,   781,  2291,
    1392,   378,   380,  2292,   464,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,   776,   385,   777,   952,   616,   394,   392,
     393,   395,   440,  1946,   396,   427,   439,   441,   447,   448,
     473,   464,   474,   491,   493,  1619,   151,   495,   500,   504,
     518,   561,  -206,  -207,   564,  1276,  -208,   524,   464,   304,
     573,   574,  1282,   578,   581,   582,  1293,  1391,   583,   594,
     443,   626,   627,   634,   635,   304,   636,   642,   639,   644,
     666,   646,   647,  1914,  1915,   667,   668,   669,   304,   670,
     671,  1503,  1505,   478,   896,   683,   672,   686,   687,   565,
     684,   688,   695,   689,   690,   697,   691,   629,   700,   911,
     696,   698,   699,   701,   710,   575,   576,   709,   702,   704,
     736,   718,   737,   304,   304,   719,   304,   304,   304,   720,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     731,   732,   304,  2004,   597,   734,   735,   738,   470,   739,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   852,   612,   613,   614,   615,   740,   742,
     743,   745,   616,   760,   776,   763,   777,   775,   780,   782,
     783,   150,   823,   850,   304,   478,   478,   789,   827,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,   829,   845,   857,
     304,   616,   858,  1583,   859,   890,   924,   925,   900,   901,
    1448,   902,   903,   912,   616,   960,   304,   304,   304,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,   922,   961,   964,
     975,   616,   974,  1004,   977,  1006,  1032,  1007,  1010,  1019,
    1021,  1064,  1503,  1505,  1035,  1074,  1066,  1080,  1084,  1085,
    1089,  1090,  1094,  1105,  1825,  1106,  1111,  1122,  1124,  1424,
     464,  1127,  1135,   304,   470,  1137,  1141,  1145,  1140,  1146,
    1147,   762,  1149,  1150,  1151,  1153,  1086,  1154,  1155,  1156,
    1157,  1158,   304,  1159,   304,   304,  1160,  1161,  1162,  1165,
    1171,  1198,  1199,   796,   304,  1207,  1208,  1209,  1217,   478,
    1221,  1227,  1233,   478,  1237,  1249,  1250,  1241,   796,  1251,
    1257,  1259,   478,  1271,   478,  1279,  1280,   478,  1283,  1305,
    1306,  1308,  1329,  1325,  1327,  1328,  1663,  1340,  1668,  1341,
    1342,  1345,  1353,   304,  1356,  1370,  1355,  1362,  1369,  1967,
    1371,  1376,  1366,  2116,  1372,  1375,   389,  1377,  1381,  1394,
    1396,  1481,  1482,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   852,   612,   613,   614,
     615,   478,  1412,  1397,  1418,   616,   304,  1419,   304,   464,
    1420,   464,  1421,   464,   464,   464,  1429,  1426,  1433,  1451,
    1434,  1455,  1467,  1487,  1496,  -209,   304,  1513,  1514,   464,
     464,   397,  1515,  1518,  1520,  1519,  1521,  1522,   304,  1523,
    1813,  1525,   304,  1526,  1815,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,  1834,  1834,  1537,  1536,   616,  1540,  1236,  1541,  1552,
    1542,  1551,  1553,  1554,  1823,   398,   399,   400,   401,   402,
     403,   404,   405,   406,  1555,  1556,  1557,  1558,   407,   408,
     409,   410,  1559,  1973,  1563,  1564,   411,   412,   413,   414,
     304,   304,   304,  1565,  1256,   415,  1566,   416,   304,   304,
     304,  1567,   796,  1568,  1569,  1587,  1570,  1808,  1571,  1589,
    1572,   417,  1574,  1576,   418,  1579,  1591,   304,  1593,  1597,
    1594,  1590,  1599,  1596,  1598,  1601,   796,  1603,   304,  1607,
    1612,  1617,  1609,  1618,  1621,  1622,   304,  1623,  1628,  1634,
     304,  1630,  1632,  1648,  1631,  1654,  1655,  1659,  1674,  1676,
    1678,   304,  1682,   304,  1646,  1683,   464,   464,   464,   464,
     464,   464,   464,   464,   464,  1672,   464,   464,   464,   464,
    1863,  1652,   464,   464,   464,  1673,  1893,  1637,  1684,  1689,
    1690,  1691,   796,  1692,  1693,   796,  1694,  1695,  1696,  1697,
    1698,  1711,  1700,  1718,  1722,   389,  1731,  1737,   796,  1746,
    1738,  1747,  1755,   485,   485,  1744,  1745,  1748,  1760,   304,
    1752,  1753,  1754,  1761,  1767,  1378,  1768,  1776,  1769,  1770,
    1771,  1772,  1784,  1775,  1763,  1786,  1787,   478,   419,   420,
     421,  1398,  1778,  1108,  1779,  1110,  1791,  1805,   304,  1812,
     422,  1795,  1798,   304,   423,   798,   424,  1360,  1816,  1817,
    1819,  1820,   464,  1836,  1841,  1976,  1844,  1909,  1846,  1848,
    1852,  1853,  1856,   464,  1864,  1870,  1855,  1859,  1872,  1873,
    1874,  1875,  1879,  1880,  1881,  1888,  1882,  1883,  1229,  1449,
    1450,  1896,  1452,  1453,  1454,  1894,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1465,  1319,  1895,  1898,  1901,
    1902,  1919,  1950,  1923,  1924,  1933,  1939,  1940,  1941,  1955,
    1958,  1959,  1960,  1961,  1971,  1972,   304,  1977,  1989,   811,
    1990,   304,   304,  -588,  2140,  -586,  1991,  1992,  1996,  2000,
    1969,   470,   470,  2005,  2006,  2007,  2008,  2009,  2010,  2011,
    1480,  2017,  2022,  2023,   304,  2026,  2031,  2032,  2038,  2034,
     304,  2035,  2040,  1871,  2050,   304,  2041,  2058,  2053,  2059,
    2068,  2065,  2069,  2070,   304,  2066,  1497,  2072,  2067,  2073,
    2075,  2076,   478,  2081,  2099,   478,  2119,  2120,  2124,  2131,
    2136,  2137,  1510,  2139,  2138,  2141,  2147,  -587,  2150,  2167,
    2170,  1466,  2174,   304,  2151,  2152,  2155,  1391,  2159,  2161,
    2172,  2186,  2187,  2189,   389,  2175,   304,   485,  2162,  2164,
    2201,  2168,  2178,  1854,  2190,  2197,  2206,   796,  2211,   796,
     796,  2252,  2225,  2241,  2253,  2254,  2255,  2257,  2258,  2259,
    2263,  2274,  2260,   796,  2273,  2277,  2284,  2289,  2290,  1561,
    2280,  2293,   485,  1926,  1927,  1928,  1929,  1930,  1932,  2294,
    2219,  1650,  1714,   796,   822,  1869,  2090,  2062,  1575,   304,
    1577,  1578,  1897,   128,   139,   140,  1411,  1680,  2122,   141,
    2063,   304,   304,  2114,   963,   796,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,   147,  1807,   304,  1956,   616,  1968,
    1835,     0,     0,     0,     0,     0,     0,     0,   304,  1608,
    1129,     0,   796,  2094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   304,     0,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,     0,     0,   464,  1951,     0,
       0,  1953,   304,     0,     0,  2188,     0,     0,     0,     0,
       0,     0,  1667,     0,     0,     0,     0,   304,     0,     0,
       0,     0,  2095,     0,  1681,   304,   304,  1524,  1685,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,  2210,   304,     0,     0,     0,
       0,   470,     0,     0,     0,     0,     0,   304,     0,     0,
       0,   304,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,  1562,     0,   616,   389,  1734,  1735,  1736,   464,
     464,     0,     0,     0,  1741,  1742,  1743,     0,   304,     0,
       0,     0,     0,  2196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1758,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1766,     0,     0,   304,     0,     0,
       0,     0,  1774,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1783,     0,  1785,
       0,     0,     0,     0,   796,     0,     0,     0,     0,     0,
    2126,  2127,  2128,  2129,  2130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   304,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1606,     0,     0,     0,     0,     0,     0,   304,   304,   304,
     304,   304,     0,     0,     0,  1840,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,   464,  2165,   616,     0,   464,  2169,     0,
       0,     0,     0,  1624,  1862,     0,   464,     0,   464,     0,
     304,   464,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1602,     0,     0,     0,     0,   304,     0,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,   478,     0,  2202,
     616,     0,     0,  2204,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,     0,   464,   478,   478,     0,  2216,
       0,  1756,     0,   173,   397,     0,     0,     0,     0,   478,
       0,     0,  1900,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,     0,
    1840,     0,     0,     0,  2249,  2250,     0,     0,   398,   399,
     400,   401,   402,   403,   404,   405,   406,     0,     0,     0,
    1942,   407,   408,   409,   410,     0,     0,     0,     0,   411,
     412,   413,   414,     0,     0,     0,     0,     0,   415,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,  1966,
       0,     0,     0,     0,   417,     0,     0,   418,     0,     0,
       0,   179,  1975,     0,   180,     0,     0,   181,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,   450,
       0,     0,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1840,     0,     0,     0,     0,
       0,     0,     0,  2271,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,  2285,  2287,     0,     0,   616,     0,     0,     0,
       0,     0,  2039,     0,     0,  2295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   464,   464,     0,
       0,   419,   420,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   422,     0,     0,     0,   423,     0,   424,
     122,   464,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   456,   457,  2082,   437,
       0,     0,  1516,  -582,     0,  1636,     0,     0,     0,     0,
       0,     0,     0,  2091,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   465,     0,     0,
       0,   475,     0,     0,     0,     0,   481,     0,     0,  1840,
       0,     0,     0,   486,     0,     0,   488,     0,     0,     7,
       8,     0,     0,  2121,     0,     0,  1814,     0,     0,     0,
       0,     0,     0,   497,   498,   499,     0,   501,   502,   503,
       0,   505,   506,   507,   508,   509,   510,   511,     0,   513,
     514,   515,   516,     0,     0,     0,     0,   520,   520,     0,
       0,     0,     0,     0,  1840,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,   464,   616,     0,   464,
       0,  1818,     0,  2166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   796,     0,   796,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,   464,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,   584,   586,   588,   589,   520,   790,
      57,     0,     0,    60,   791,     0,   792,   793,     0,   794,
       0,     0,     0,   623,   520,   520,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,   652,     0,     0,     0,     0,   652,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   520,   674,     0,
       0,     0,     0,     0,     0,     0,  1840,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   693,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     703,     0,   705,   706,     0,   708,     0,     0,     0,   711,
     712,   713,     0,     0,   714,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1840,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,   747,     0,     0,     0,     0,   520,
     756,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   764,   765,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   797,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,   828,   616,     0,     0,     0,   833,     0,
       0,     0,   837,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   851,   586,     0,     0,
       0,     0,   856,     0,     0,     0,   860,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,   871,   872,   873,
     874,   875,   876,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   886,     0,   891,   892,     0,   894,     0,     0,
       0,     0,     0,   796,     0,     0,     0,   904,     0,     0,
     908,   909,     0,     0,     0,     0,   522,   523,   886,     0,
       0,     0,     0,   520,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   926,   927,   928,   929,   930,
     931,   932,   933,   934,   935,   936,   937,   938,   939,   941,
     943,   944,   945,   946,   947,     0,   949,   950,     0,     0,
       0,     0,     0,     0,   957,   958,   959,     0,     0,   796,
       0,     0,   965,   966,   967,   968,     0,   520,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   796,     0,     0,     0,     0,   584,   747,   988,     0,
       0,     0,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,     0,     0,   624,   625,     0,  1008,  1009,     0,  1011,
       0,     0,  1013,     0,     0,     0,   520,   520,   520,  1018,
       0,     0,     0,  1022,   520,  1024,  1025,  1026,     0,     0,
    1027,   464,  1029,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   673,     0,     0,     0,
     464,   464,  1049,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   464,     0,     0,   520,     0,     0,     0,
       0,     0,     0,  1068,  1069,     0,  1070,     0,     0,   949,
     950,     0,     0,     0,     0,     0,     0,     0,  1083,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,     0,  1099,     0,
       0,   521,   521,  1102,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,     0,
    1119,  1120,     0,     0,   520,     0,   520,  1126,   755,     0,
       0,  1119,     0,  1133,     0,  1134,     0,     0,     0,     0,
       0,  1139,     0,     0,     0,  1142,     0,     0,     0,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,  1163,     0,
     941,   616,  1166,   776,     0,   777,     0,     0,     0,   587,
       0,  1796,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,   521,
       0,     0,     0,     0,     0,     0,     0,     0,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,  1212,
    1213,  1214,     0,     0,     0,     0,     0,     0,     0,     0,
    1220,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   521,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   520,     0,
       0,     0,     0,     0,   521,     0,     0,     0,     0,     0,
     520,     0,   919,     0,     0,     0,     0,     0,  1255,     0,
       0,     0,  1261,     0,     0,     0,     0,     0,  1267,     0,
       0,   520,     0,     0,     0,     0,     0,     0,     0,  1277,
    1278,     0,     0,     0,     0,  1281,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1307,     0,     0,  1309,   971,   972,     0,     0,
       0,     0,     0,   521,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1330,     0,  1332,  1333,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1351,  1824,     0,  1015,  1016,  1017,     0,     0,
       0,     0,     0,  1023,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1374,     0,     0,     0,
       0,     0,     0,  1380,     0,     0,     0,     0,     0,     0,
    1393,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1416,  1417,  1063,     0,     0,     0,   520,
       0,     0,     0,     0,     0,     0,   877,     0,     0,     0,
       0,     0,     0,     0,     0,   887,   888,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1446,     0,     0,     0,  1095,     0,     0,     0,     0,
       0,     0,   915,     0,     0,     0,     0,   521,     0,     0,
       0,     0,     0,   520,     0,     0,     0,  1117,     0,     0,
       0,     0,     0,  1123,     0,  1125,     0,     0,     0,     0,
       0,  1470,     0,   942,     0,     0,     0,     0,     0,     0,
       0,  1471,  1472,  1473,  1474,  1475,     0,     0,     0,     0,
    1477,  1478,     0,  1479,     0,     0,     0,     0,     0,     0,
       0,   521,   521,     0,     0,     0,     0,     0,     0,  1490,
    1491,     0,     0,     0,     0,     0,     0,  1494,  1495,     0,
       0,     0,     0,     0,     0,     0,  1499,  1500,     0,     0,
       0,     0,  1506,  1507,     0,     0,     0,     0,   520,   520,
       0,     0,     0,     0,     0,     0,     0,  1201,     0,     0,
     521,   521,   521,     0,     0,     0,     0,  1211,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1539,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,  1240,     0,     0,
     521,     0,     0,     0,     0,     0,     0,     0,     0,  1248,
       0,  1573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,     0,     0,     0,     0,
    1270,     0,     0,  1588,     0,     0,     0,     0,     0,     0,
     521,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1506,  1507,     0,     0,     0,
    1605,     0,   521,     0,     0,     0,     0,     0,   521,     0,
     521,  1611,     0,     0,  1616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     397,     0,  1937,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1638,     0,     0,  1641,   520,  1644,   520,
       0,     0,     0,     0,   942,     0,  1167,  1653,     0,     0,
    1656,     0,  1653,     0,  1660,  1662,   597,     0,  1670,  1671,
       0,     0,     0,     0,   398,   399,   400,   401,   402,   403,
     404,   405,   406,     0,     0,     0,     0,   407,   408,   409,
     410,     0,   521,     0,     0,   411,   412,   413,   414,     0,
       0,     0,   521,     0,   415,     0,   416,     0,  1423,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     417,     0,     0,   418,     0,     0,     0,   179,     0,     0,
     180,     0,     0,   181,     0,   182,     0,     0,     0,     0,
       0,     0,   521,     0,     0,     0,    46,     0,  1740,     0,
       0,     0,     0,     0,   521,     0,     0,     0,     0,  1749,
    1750,  1751,  1468,     0,     0,   450,     0,     0,  1757,     0,
    1759,     0,     0,     0,     0,   521,     0,  1762,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   520,     0,     0,     0,     0,     0,  1780,  1781,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1788,  1789,
    1790,     0,     0,     0,     0,     0,     0,     0,  1799,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1811,
       0,     0,     0,     0,     0,     0,     0,   419,   420,   421,
       0,     0,     0,     0,     0,     0,     0,  1511,  1512,   422,
    1828,     0,     0,   423,     0,   424,   122,     0,  1837,  1838,
    1938,     0,     0,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,   776,   779,   777,  1830,
       0,     0,     0,     0,  1867,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   521,     0,     0,     0,   616,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1586,     0,  1884,  1885,  1886,     0,
       0,     0,     0,     0,     0,     0,  2030,  1887,     0,     0,
       0,     0,  1890,  1891,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1899,     0,   521,     0,     0,
       0,     0,   520,   520,  1907,     0,  1908,     0,     0,     0,
       0,     0,  1916,  1917,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   905,     0,     0,     0,     0,     0,
       0,   520,     0,     0,     0,     0,   520,  1936,     0,     0,
       0,     0,     0,     0,     0,     0,  1643,     0,  1645,     0,
       0,  1949,     0,     0,  1952,     0,     0,     0,  1954,     0,
       0,     0,     0,     0,     0,     0,     0,  1890,  1891,     0,
    1963,     0,     0,     0,     0,     0,   953,     0,     0,     0,
    1970,     0,   521,   521,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1981,     0,     0,     0,     0,  1987,
    1988,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1993,     0,     0,  1994,  1993,     0,  1997,
       0,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,   520,   520,     0,     0,     0,     0,     0,  2024,
    2025,     0,     0,     0,     0,     0,     0,     0,     0,   521,
       0,  2033,     0,     0,     0,     0,     0,     0,     0,     0,
    2042,     0,     0,     0,     0,     0,     0,     0,     0,   586,
    1777,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2054,  2055,     0,     0,   520,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2079,  2080,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   521,     0,   521,     0,     0,     0,     0,     0,     0,
       0,  2093,     0,     0,     0,     0,   520,   520,  2098,     0,
       0,     0,     0,  2101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   520,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,  2132,     0,     0,  1172,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,     0,  1184,  1185,  1186,  1187,
       0,  1189,  1190,  1191,  1192,     0,  2143,     0,     0,   178,
       0,   184,  2148,     0,     0,  2149,     0,  1204,     0,  1206,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1216,     0,     0,     0,     0,     0,     0,     0,  1223,  1224,
       0,  1905,  1906,     0,     0,     0,  2173,  1235,     0,     0,
    2057,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   521,     0,     0,     0,     0,
       0,     0,  2191,  2192,     0,  1935,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2198,  2199,     0,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2208,     0,     0,     0,     0,   520,   520,
     520,   520,   520,     0,     0,     0,     0,     0,  1987,     0,
       0,     0,  2224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2244,
       0,     0,     0,     0,  2247,  2248,     0,     0,     0,     0,
       0,     0,     0,     0,  1336,  1338,  1339,   520,  1868,     0,
    1343,  1344,     0,     0,  1347,  1348,  1349,  1350,     0,  1352,
       0,     0,     0,     0,  1358,     0,     0,     0,     0,     0,
       0,  2020,  2021,     0,  2275,  2276,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   555,   556,   557,   558,   559,   560,     0,   562,   563,
       0,     0,     0,     0,     0,  2056,   521,   521,   569,   570,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2071,   579,   580,   173,   397,     0,  1445,     0,  1447,     0,
       0,     0,     0,     0,     0,   521,     0,     0,     0,     0,
     521,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,  2096,  2097,     0,   398,   399,
     400,   401,   402,   403,   404,   405,   406,     0,     0,     0,
       0,   407,   408,   409,   410,     0,  2115,     0,     0,   411,
     412,   413,   414,     0,     0,     0,     0,     0,   415,     0,
     416,  2125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   417,     0,     0,   418,     0,     0,
       0,   179,     0,     0,   180,     0,     0,   181,     0,   182,
       0,  1508,     0,     0,     0,     0,     0,     0,     0,     0,
      46,   715,   716,   717,     0,     0,     0,   721,   722,   723,
     724,   725,   726,   727,     0,   728,   521,   521,     0,   450,
     729,   730,     0,  2105,   733,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   746,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     521,     0,     0,     0,     0,     0,  2106,     0,     0,  2200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   419,   420,   421,     0,     0,     0,  2212,  2213,  2214,
    2215,  2217,     0,   422,     0,     0,     0,   423,     0,   424,
     122,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
     521,   521,     0,   616,     0,     0,     0,     0,     0,  1625,
       0,     0,     0,  1830,     0,     0,     0,     0,     0,     0,
       0,   521,     0,     0,     0,     0,  2256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1664,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   923,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1701,  1702,  1703,  1704,  1705,  1706,
    1707,     0,     0,     0,     0,  1712,  1713,     0,     0,     0,
       0,     0,  1715,     0,     0,  1717,     0,     0,     0,  1721,
       0,     0,  1723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1730,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,   521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   521,   521,   521,   521,   521,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,  2185,     0,     0,     0,   616,
    1794,     0,  1797,     0,     0,     0,  1804,     0,  1806,     0,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,   521,   616,     0,  1020,     0,     0,     0,     0,     0,
    1831,     0,   981,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,     6,   397,
       0,     0,     0,     0,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
    2231,     0,     0,  1665,   399,   400,   401,   402,   403,   404,
     405,   406,   253,   254,   255,   256,   407,   408,   409,   410,
     257,   258,     0,     0,   411,   412,   413,   414,     0,     0,
     259,   260,   261,   415,     0,   416,   262,   263,   264,  2154,
    1892,     0,     0,     0,     0,     0,     0,   265,    25,   417,
     266,     0,   418,     0,     0,     0,   267,     0,     0,   268,
       0,     0,   269,     0,   270,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,    58,
      59,  1230,   273,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,     0,  1247,     0,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,  1978,   276,   616,  1979,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   419,   420,   421,   278,
     279,     0,     0,     0,     0,   280,   281,   282,   422,   283,
     284,   285,   423,     0,   424,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2013,  2014,
       0,  2016,   286,   287,     0,     0,     0,     0,     0,   288,
       0,     0,     0,     0,   371,     0,     0,     0,  1666,     0,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2060,  2061,     0,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,     6,   397,     0,     0,  1438,
       0,   219,   220,   221,     0,  2092,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,     0,     0,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   253,
     254,   255,   256,   407,   408,   409,   410,   257,   258,     0,
       0,   411,   412,   413,   414,     0,     0,   259,   260,   261,
     415,     0,   416,   262,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   265,    25,   417,   266,     0,   418,
       0,     0,     0,   267,     0,     0,   268,  1498,     0,   269,
       0,   270,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,    58,    59,     0,   273,
       0,   274,     0,     0,   275,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,   597,     0,     0,    84,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1036,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1238,     0,
       0,     0,   277,   419,   420,   421,   278,   279,     0,     0,
       0,     0,   280,   281,   282,   422,   283,   284,   285,   423,
       0,   424,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
     287,     0,     0,     0,     0,     0,   288,     0,     0,     0,
       0,   371,  2265,     0,     0,   290,     0,     0,   291,  1626,
    1627,     0,   218,   173,   397,     0,   449,     0,     0,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   435,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   253,   254,   255,
     256,   407,   408,   409,   410,   257,     0,     0,     0,   411,
     412,   413,   414,     0,     0,     0,     0,     0,   415,     0,
     416,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,   417,   266,  1719,   418,     0,     0,
       0,   179,     0,     0,   180,  1726,     0,   181,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   852,   612,   613,   614,   615,   450,
       0,     0,     0,   616,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1239,
       0,     0,     0,   451,     0,     0,     0,     0,     0,     0,
     277,   419,   420,   421,   278,     0,     0,     0,     0,     0,
     280,   281,   282,   422,   283,   284,   285,   423,     0,   424,
     122,     0,   452,   453,   454,   455,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   436,     0,
       0,     0,     0,     0,   288,     0,   456,   457,     0,   458,
       0,   459,   218,     6,   370,   460,   291,     0,  1865,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,     0,     0,     0,     0,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,     0,     0,
       0,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,     0,   266,     0,     0,     0,     0,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,    58,    59,     0,   273,     0,   274,
       0,     0,   275,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,   276,     0,     0,     0,     0,  1581,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,   278,   279,     0,     0,     0,     0,
     280,   281,   282,     0,   283,   284,   285,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   287,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,   371,
     218,     6,     0,   372,     0,   694,   291,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    25,     0,   266,     0,     0,     0,     0,     0,   267,
       0,     0,   268,     0,     0,   269,     0,   270,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,    58,    59,     0,   273,     0,   274,     0,     0,
     275,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,     0,    88,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,   278,   279,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   519,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,   218,     6,
    1765,     0,   590,     0,   291,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   254,   255,   256,     0,     0,     0,
       0,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,     0,     0,     0,   262,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   265,    25,
       0,   266,     0,     0,     0,     0,     0,   267,     0,     0,
     268,     0,     0,   269,     0,   270,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,     0,
      58,    59,     0,   273,     0,   274,     0,     0,   275,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    84,
       0,     0,     0,    88,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,   276,     0,
       0,     0,  1860,     0,     0,     0,  1861,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,     0,     0,
     278,   279,     0,     0,     0,     0,   280,   281,   282,     0,
     283,   284,   285,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   287,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,   371,   218,     6,     0,   290,
       0,     0,   291,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,   255,   256,     0,     0,     0,     0,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,     0,     0,     0,   262,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,    25,     0,   266,
       0,     0,     0,     0,     0,   267,     0,     0,   268,     0,
       0,   269,     0,   270,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,     0,    58,    59,
       0,   273,     0,   274,     0,     0,   275,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
       0,    88,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   276,     0,     0,     0,
    1912,     0,     0,     0,  1913,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,     0,     0,   278,   279,
       0,     0,     0,     0,   280,   281,   282,     0,   283,   284,
     285,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   658,  1931,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,   660,   218,     6,     0,   334,   590,     0,
     291,   219,   220,   221,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     254,   255,   256,     0,     0,     0,     0,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
       0,     0,     0,   262,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   265,    25,     0,   266,     0,     0,
       0,     0,     0,   267,     0,     0,   268,     0,     0,   269,
       0,   270,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,    58,    59,     0,   273,
       0,   274,     0,     0,   275,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,     0,    88,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,   276,     0,     0,     0,  1943,     0,
       0,     0,  1944,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,     0,   278,   279,     0,     0,
       0,     0,   280,   281,   282,     0,   283,   284,   285,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
     287,     0,     0,     0,     0,     0,   288,     0,     0,     0,
       0,   289,   218,     6,     0,   290,     0,     0,   291,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,     0,     0,     0,     0,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,     0,     0,
       0,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,     0,   266,     0,     0,     0,     0,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,    58,    59,     0,   273,     0,   274,
       0,     0,   275,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,   276,     0,     0,     0,  2117,     0,     0,     0,
    2118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,   278,   279,     0,     0,     0,     0,
     280,   281,   282,     0,   283,   284,   285,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   287,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,   371,
     218,     6,     0,   290,     0,     0,   291,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    25,     0,   266,     0,     0,     0,     0,     0,   267,
       0,     0,   268,     0,     0,   269,     0,   270,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,    58,    59,     0,   273,     0,   274,     0,     0,
     275,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,     0,    88,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
     276,     0,     0,     0,     0,     0,     0,     0,   809,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,   278,   279,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   519,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,   218,     6,
       0,   585,     0,     0,   291,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   254,   255,   256,     0,     0,     0,
       0,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,   259,   260,   261,     0,     0,     0,   262,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   265,    25,
       0,   266,     0,     0,     0,     0,     0,   267,     0,     0,
     268,     0,     0,   269,     0,   270,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,     0,
      58,    59,     0,   273,     0,   274,     0,     0,   275,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    84,
       0,     0,     0,    88,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,   276,     0,
       0,     0,     0,     0,     0,     0,   815,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,     0,     0,
     278,   279,     0,     0,     0,     0,   280,   281,   282,     0,
     283,   284,   285,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   519,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,   371,   218,     6,     0,     0,
     590,     0,   291,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,   255,   256,     0,     0,     0,     0,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,     0,     0,     0,   262,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,    25,     0,   266,
       0,     0,     0,     0,     0,   267,     0,     0,   268,     0,
       0,   269,     0,   270,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,     0,    58,    59,
       0,   273,     0,   274,     0,     0,   275,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
       0,    88,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   276,     0,     0,     0,
       0,     0,     0,     0,   817,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,     0,     0,   278,   279,
       0,     0,     0,     0,   280,   281,   282,     0,   283,   284,
     285,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,   287,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,   628,   218,     6,     0,   290,     0,     0,
     291,   219,   220,   221,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     254,   255,   256,     0,     0,     0,     0,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
       0,     0,     0,   262,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   265,    25,     0,   266,     0,     0,
       0,     0,     0,   267,     0,     0,   268,     0,     0,   269,
       0,   270,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,    58,    59,     0,   273,
       0,   274,     0,     0,   275,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,     0,    88,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,   276,     0,     0,     0,     0,     0,
       0,     0,   981,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,     0,   278,   279,     0,     0,
       0,     0,   280,   281,   282,     0,   283,   284,   285,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
     287,     0,     0,     0,     0,     0,   288,     0,     0,     0,
       0,   637,   218,     6,     0,   290,     0,     0,   291,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,     0,     0,     0,     0,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,     0,     0,
       0,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,     0,   266,     0,     0,     0,     0,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,    58,    59,     0,   273,     0,   274,
       0,     0,   275,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,   276,     0,     0,     0,     0,     0,     0,     0,
     982,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,   278,   279,     0,     0,     0,     0,
     280,   281,   282,     0,   283,   284,   285,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   519,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,   371,
     218,     6,     0,   940,     0,  1422,   291,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    25,     0,   266,     0,     0,     0,     0,     0,   267,
       0,     0,   268,     0,     0,   269,     0,   270,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,    58,    59,     0,   273,     0,   274,     0,     0,
     275,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,     0,    88,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
     276,     0,     0,     0,     0,     0,     0,     0,  1033,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,   278,   279,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   519,     0,     0,     0,
       0,     0,   288,   218,     6,     0,     0,   371,  1642,     0,
     219,   220,   221,     0,   291,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,   256,     0,     0,     0,     0,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,   259,   260,   261,     0,
       0,     0,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,    25,     0,   266,     0,     0,     0,
       0,     0,   267,     0,     0,   268,     0,     0,   269,     0,
     270,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   271,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,     0,    58,    59,     0,   273,     0,
     274,     0,     0,   275,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    84,     0,     0,     0,    88,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,   276,     0,     0,     0,     0,     0,     0,
       0,  1143,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,   278,   279,     0,     0,     0,
       0,   280,   281,   282,     0,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   519,
       0,     0,     0,     0,     0,   288,   218,     6,     0,     0,
     371,     0,     0,   219,   220,   221,     0,   291,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,   255,   256,     0,     0,     0,     0,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,   259,
     260,   261,     0,     0,     0,   262,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,    25,     0,   266,
       0,     0,     0,     0,     0,   267,     0,     0,   268,     0,
       0,   269,     0,   270,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,     0,    58,    59,
       0,   273,     0,   274,     0,     0,   275,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
       0,    88,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   276,     0,     0,     0,
       0,     0,     0,     0,  1183,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,     0,     0,     0,   278,   279,
       0,     0,     0,     0,   280,   281,   282,     0,   283,   284,
     285,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,   287,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,   371,   218,     6,     0,  1773,     0,     0,
     291,   219,   220,   221,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     254,   255,   256,     0,     0,     0,     0,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
       0,     0,     0,   262,   263,   264,     0,     0,     0,     0,
       0,     0,     0,     0,   265,    25,     0,   266,     0,     0,
       0,     0,     0,   267,     0,     0,   268,     0,     0,   269,
       0,   270,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,    58,    59,     0,   273,
       0,   274,     0,     0,   275,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,     0,    88,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,   276,     0,     0,     0,     0,     0,
       0,     0,  1193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,     0,     0,     0,   278,   279,     0,     0,
       0,     0,   280,   281,   282,     0,   283,   284,   285,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   658,
    1931,     0,     0,     0,     0,     0,   288,     0,     0,     0,
       0,   660,   218,     6,     0,   334,     0,     0,   291,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,     0,     0,     0,     0,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   260,   261,     0,     0,
       0,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,     0,   266,     0,     0,     0,     0,
       0,   267,     0,     0,   268,     0,     0,   269,     0,   270,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,    58,    59,     0,   273,     0,   274,
       0,     0,   275,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,   276,     0,     0,     0,     0,     0,     0,     0,
    1194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,   278,   279,     0,     0,     0,     0,
     280,   281,   282,     0,   283,   284,   285,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   519,     0,
       0,     0,     0,     0,   288,   218,   173,   397,     0,   371,
       0,     0,   219,   220,   221,     0,   291,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   435,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     253,   254,   255,   256,   407,   408,   409,   410,   257,     0,
       0,     0,   411,   412,   413,   414,     0,     0,     0,     0,
       0,   415,     0,   416,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,   417,   266,     0,
     418,   218,   173,   397,     0,     0,     0,     0,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     435,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   253,   254,   255,   256,
     407,   408,   409,   410,   257,     0,     0,     0,   411,   412,
     413,   414,     0,     0,     0,     0,     0,   415,     0,   416,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,    25,   417,   266,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   419,   420,   421,   278,     0,     0,
       0,     0,     0,   280,   281,   282,   422,   283,   284,   285,
     423,     0,   424,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   436,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   371,     0,     0,     0,  1661,     0,     0,   291,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1195,     0,     0,     0,     0,     0,     0,   277,
     419,   420,   421,   278,     0,     0,     0,     0,     0,   280,
     281,   282,   422,   283,   284,   285,   423,     0,   424,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   436,     0,     0,
       0,     0,     0,   288,     0,     0,     0,     0,   371,   218,
     173,   397,  1948,     0,     0,   291,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   435,   240,
     241,   242,   243,   244,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,  1665,   399,   400,   401,   402,
     403,   404,   405,   406,   253,   254,   255,   256,   407,   408,
     409,   410,   257,     0,     0,     0,   411,   412,   413,   414,
       0,     0,     0,     0,     0,   415,     0,   416,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
      25,   417,   266,     0,   418,   218,   173,   397,     0,     0,
       0,     0,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   435,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     253,   254,   255,   256,   407,   408,   409,   410,   257,     0,
       0,     0,   411,   412,   413,   414,     0,     0,     0,     0,
       0,   415,     0,   416,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,   417,   266,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   419,   420,
     421,   278,     0,     0,     0,     0,     0,   280,   281,   282,
     422,   283,   284,   285,   423,     0,   424,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,   436,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,   371,     0,     0,     0,
    1830,     0,     0,   291,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1196,     0,     0,     0,
       0,     0,     0,   277,   419,   420,   421,   278,     0,     0,
       0,     0,     0,   280,   281,   282,   422,   283,   284,   285,
     423,     0,   424,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   436,     0,     0,     0,     0,     0,   288,   218,   173,
       0,     0,   371,     0,     0,   219,   220,   221,     0,   291,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   435,   240,   241,
     242,   243,   244,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   254,   255,   256,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,   263,   264,
       0,     0,     0,     0,     0,   218,   173,     0,   265,    25,
       0,   266,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   435,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   255,   256,     0,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,     0,   266,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,   277,     0,     0,     0,
     278,  1197,     0,     0,     0,     0,   280,   281,   282,     0,
     283,   284,   285,     0,     0,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   436,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,   371,     0,     0,     0,   640,
       0,     0,   291,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,     0,     0,   277,     0,  1202,     0,   278,     0,     0,
       0,     0,     0,   280,   281,   282,     0,   283,   284,   285,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     658,   659,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   660,   218,   173,     0,   334,     0,   907,   291,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   435,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,   256,     0,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   263,   264,     0,     0,     0,     0,     0,
     218,   173,     0,   265,    25,     0,   266,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   435,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    25,     0,   266,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,   277,     0,     0,     0,   278,  1203,     0,     0,     0,
       0,   280,   281,   282,     0,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   436,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     371,     0,     0,     0,     0,     0,     0,   291,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,     0,     0,   277,     0,
    1205,     0,   278,     0,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   436,     0,     0,     0,
       0,     0,   288,   218,   173,     0,  1373,   371,  1131,     0,
     219,   220,   221,     0,   291,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   435,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,   256,     0,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,    25,     0,   266,   218,   173,     0,
    1538,     0,     0,     0,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   435,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,     0,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,   277,     0,     0,   616,   278,     0,     0,     0,     0,
       0,   280,   281,   282,  1323,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   436,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     371,     0,     0,     0,     0,     0,     0,   291,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1346,     0,     0,     0,     0,   277,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   436,     0,     0,     0,     0,     0,   288,
     218,   173,     0,  1604,   371,     0,     0,   219,   220,   221,
       0,   291,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   435,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,   218,   173,     0,
     265,    25,     0,   266,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   435,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,   277,     0,
       0,     0,   278,  1432,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   436,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,     0,     0,
       0,     0,     0,     0,   291,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,     0,     0,     0,     0,   277,     0,  1436,     0,   278,
       0,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   436,     0,     0,     0,     0,     0,   288,
     218,   173,     0,     0,   371,  1658,     0,   219,   220,   221,
       0,   291,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   435,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,   218,   173,     0,
     265,    25,     0,   266,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   435,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,   277,     0,
       0,     0,   278,  1532,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   436,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,  1995,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,   277,     0,     0,   616,   278,
       0,     0,     0,     0,     0,   280,   281,   282,  1533,   283,
     284,   285,     0,     0,     0,   122,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,   286,   436,    43,    44,    45,    46,     0,   288,
      48,     0,     0,     0,   371,     0,     7,     8,     0,   790,
      57,   291,     0,    60,   791,     0,   792,   793,     0,   794,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    81,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   790,    57,     0,     0,    60,   791,     0,
     792,   793,     0,   794,    98,    99,   100,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    98,    99,
     100,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   790,    57,     0,     0,
      60,   791,     0,   792,   793,     0,   794,     0,     0,     0,
       0,   816,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       7,     8,    43,    44,    45,    46,     0,     0,    48,     0,
       0,    98,    99,   100,     0,   989,     0,   790,    57,     0,
       0,    60,   791,     0,   792,   793,     0,   794,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1014,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
     790,    57,     0,     0,    60,   791,     0,   792,   793,     0,
     794,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,  1065,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,    98,    99,   100,     7,     8,
       0,   790,    57,     0,     0,    60,   791,     0,   792,   793,
       0,   794,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    98,    99,   100,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,  1067,     0,   790,    57,     0,     0,    60,   791,
       0,   792,   793,     0,   794,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    81,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   790,    57,
       0,     0,    60,   791,     0,   792,   793,     0,   794,    98,
      99,   100,     0,  1272,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,    98,    99,   100,     0,     0,     7,     8,
    1580,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,  1274,     0,     0,     0,
       0,     0,     0,  1708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
    1275,     7,     8,     0,   790,    57,     0,     0,    60,   791,
       0,   792,   793,     0,   794,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    81,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   790,    57,
       0,     0,    60,   791,     0,   792,   793,     0,   794,    98,
      99,   100,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    98,    99,   100,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   790,    57,     0,     0,    60,   791,     0,   792,   793,
       0,   794,     0,     0,     0,     0,  1294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     7,     8,    43,    44,    45,
      46,     0,     0,    48,     0,     0,    98,    99,   100,     0,
    1313,     0,   790,    57,     0,     0,    60,   791,     0,   792,
     793,     0,   794,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1331,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   790,    57,     0,     0,    60,
     791,     0,   792,   793,     0,   794,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,  1365,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
      98,    99,   100,     0,     0,     0,   790,    57,     0,     0,
      60,   791,     0,   792,   793,     0,   794,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    98,    99,   100,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,  1530,     0,   790,
      57,     0,     0,    60,   791,     0,   792,   793,     0,   794,
       0,     0,     0,     0,     0,    -4,     1,     0,     0,    -4,
       0,     0,     0,     0,     0,     0,     0,    81,    -4,    -4,
       0,     0,     0,     0,     0,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,    98,    99,   100,   616,  2176,     0,
       0,    -4,    -4,    -4,     0,     0,     0,  1709,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,    -4,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,  2233,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
      -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     7,     8,     0,     0,
       0,     0,     0,     0,    -4,     0,    -4,    -4,     0,     0,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     9,
      10,    11,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1710,     0,     0,     0,     0,     0,     0,     0,
      12,    13,    14,     0,     0,     0,     0,    15,    16,     0,
       0,     0,     0,    17,     0,     0,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    24,     0,    25,     0,     0,
       0,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
      42,    43,    44,    45,    46,    47,     0,    48,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,    66,    67,
      68,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    93,
      94,    95,     0,     0,     0,    96,     0,     0,     0,     0,
      97,    98,    99,   100,   173,   397,   101,     0,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,   122,   123,     0,     0,     0,   398,
     399,   400,   401,   402,   403,   404,   405,   406,     0,     0,
       0,     0,   407,   408,   409,   410,   173,   397,     0,     0,
     411,   412,   413,   414,     0,     0,     0,     0,     0,   415,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   417,     0,     0,   418,     0,
       0,     0,   179,   428,   397,   180,     0,     0,   181,     0,
     182,   398,   399,   400,   401,   402,   403,   404,   405,   406,
       0,    46,     0,     0,   407,   408,   409,   410,     0,     0,
       0,     0,   411,   412,   413,   414,     0,     0,     0,     0,
     450,   415,     0,   416,     0,     0,     0,     0,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   417,     0,     0,
     418,   407,   408,   409,   410,     0,     0,     0,     0,   411,
     412,   413,   414,     0,     0,     0,     0,     0,   415,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   417,     0,     0,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   419,   420,   421,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   422,     0,     0,     0,   423,     0,
     424,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,     0,     0,     0,   419,   420,   421,  1858,     0,     0,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
     423,     0,   424,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   419,   420,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   422,     0,     0,     0,   423,     0,   424,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   790,    57,     0,     0,    60,   791,     0,   792,   793,
       0,   794,     0,     0,     0,  1077,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,  1078,     0,     0,     0,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,    98,    99,   100,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1982,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1983,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2015,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2087,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2144,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2145,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2160,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2194,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2221,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2226,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2227,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,     0,     0,   849,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,  1112,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,  1170,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,  1218,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
       0,     0,     0,     0,  1219,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,     0,     0,  1264,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,     0,  1297,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,  1311,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,     0,     0,     0,     0,
    1318,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,  1379,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,     0,     0,  1399,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,  1435,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,  1484,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,  1485,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
       0,     0,     0,     0,  1486,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,     0,     0,  1489,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,     0,  1534,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,  1610,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,     0,     0,     0,     0,
    1910,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,  1921,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,     0,     0,  1962,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,  2036,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,  2052,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,  2064,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
       0,     0,     0,     0,  2088,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,     0,     0,  2123,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,     0,  2133,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,     0,
       0,  2134,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,     0,     0,     0,     0,
    2158,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,     0,     0,  2207,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,     0,     0,  2246,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,     0,     0,  2264,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,     0,     0,  2282,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,  2283,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
       0,     0,     0,   749,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
       0,   973,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,     0,     0,     0,  2029,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,   776,     0,   777,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,  1039,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
    1088,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,  1243,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,  1312,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,  1314,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,     0,     0,  1321,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   748,   612,   613,   614,   615,     0,     0,     0,
       0,   616,     0,     0,     0,  1322,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   748,
     612,   613,   614,   615,     0,     0,     0,     0,   616,     0,
       0,     0,  1414,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   748,   612,   613,   614,
     615,     0,     0,     0,     0,   616,     0,     0,     0,  1428,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   748,   612,   613,   614,   615,     0,     0,
       0,     0,   616,     0,     0,     0,  1639,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,     0,     0,  1729,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   748,   612,   613,
     614,   615,     0,     0,     0,     0,   616,     0,     0,     0,
    1782,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   748,   612,   613,   614,   615,     0,
       0,     0,     0,   616,     0,     0,     0,  1974,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   748,   612,   613,   614,   615,     0,     0,     0,     0,
     616,     0,     0,     0,  2019,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   748,   612,
     613,   614,   615,     0,     0,     0,     0,   616,     0,     0,
       0,  2037,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   830,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   831,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   832,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   834,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   835,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   836,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   838,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   839,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   840,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   841,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   842,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   843,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   844,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   846,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   847,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   848,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,   920,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,   954,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1003,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1020,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1028,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1030,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1031,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1037,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1038,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1076,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1087,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1148,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1152,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1164,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1242,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1252,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1253,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1254,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1263,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1265,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1266,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1296,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1298,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1299,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1300,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1301,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1302,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1303,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1304,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1310,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1324,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1326,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1364,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1413,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1427,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1640,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1675,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1716,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1728,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1845,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1847,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1850,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1857,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1911,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  1920,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  1947,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  2018,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  2085,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  2086,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616,
       0,  2220,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   748,   612,   613,   614,   615,
       0,     0,     0,     0,   616,     0,  2261,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     748,   612,   613,   614,   615,     0,     0,     0,     0,   616
};

static const yytype_int16 yycheck[] =
{
       3,  1295,     3,   327,  1291,   773,   655,   656,   163,  1493,
       6,   779,  1767,    64,   167,  1813,     4,  1815,   149,    96,
     460,     4,    25,     4,     4,    25,     4,     4,  1998,     4,
     108,     7,     6,   108,  1800,     4,     6,   144,     5,     4,
       4,   112,     5,   114,     6,     9,     5,     5,    14,     4,
       4,     6,     4,    56,     4,     4,     7,   105,     6,     6,
     108,   109,   110,     6,     4,     6,   165,     6,   253,   254,
     260,     4,   262,   121,   259,     4,   102,   108,   149,   269,
       7,     6,    85,     9,    36,    37,    36,    37,    91,   196,
       9,   108,   261,    96,   193,   121,    36,    37,   101,  1865,
     269,     7,   133,    36,    37,     9,   144,   178,   264,   112,
     209,   210,   268,   184,   105,   102,   133,   108,   105,     9,
       9,   108,   260,   110,   162,     0,   264,  1882,   205,    94,
     121,     9,   248,   249,   121,   173,   174,   175,   215,   263,
     188,   179,   180,     6,   260,   269,   149,   102,   264,   150,
     261,   154,   155,   156,     6,     6,   248,   249,   269,     6,
     163,   111,   112,   149,   150,    70,    71,     7,    73,   155,
       6,   111,   112,   265,   108,   248,   249,     7,   111,   112,
     620,   260,   260,  2153,     7,   260,   339,   248,   249,   250,
     251,   252,   253,   254,     7,   169,   269,   200,   259,   248,
     249,   260,   205,   248,   249,   358,   209,   210,   259,   260,
     261,   181,   215,   216,   217,   261,   260,   257,   258,   181,
     269,   248,   249,   269,   269,   276,   266,   265,   208,   183,
     184,   185,   186,   261,   311,   312,   313,  1721,   266,   204,
     261,   195,   269,   197,   198,   199,   200,   201,   269,   263,
     231,   205,   206,   231,   208,   269,   231,   233,   234,   235,
     236,   260,   231,  1550,   260,   264,   231,   231,   264,   272,
     260,  2026,   260,   265,   351,   352,   353,   269,   431,   262,
     433,   264,   231,   260,   287,   268,   267,   290,   291,   264,
     443,   291,   369,   257,   258,   264,   260,   264,   262,   264,
     264,   264,   266,   306,   307,   264,   264,   310,   311,   312,
     313,   265,   261,   753,   263,   266,   264,   264,   321,  1087,
    1088,   264,   325,   264,   327,   264,  2081,   233,   234,   235,
     236,   260,   149,   260,   260,   262,   262,   154,   155,   156,
     266,   260,   105,   262,   264,   108,   349,   787,   351,   352,
     353,   257,   258,   257,   258,     4,   260,   260,   262,   263,
     266,   260,   266,   262,   804,   264,   369,   257,   258,   372,
     260,   260,   262,   262,   814,     4,   266,   266,   449,   257,
     258,   261,   260,   200,   262,   248,   249,     6,   266,   269,
    2188,   243,   244,   233,   234,   235,   236,   248,   249,     6,
     217,   248,   249,   233,   234,   235,   236,   243,   244,   564,
     233,   234,   235,   236,     4,   260,     4,   257,   258,   264,
     233,   234,   235,   236,   261,   330,   331,   257,   258,   248,
     249,     8,   269,   338,   339,     6,   439,   265,   441,   248,
     249,   269,   445,   446,   257,   258,    36,    37,    36,    37,
     269,   248,   249,   248,   249,   248,   249,   260,   461,   262,
     269,   102,     6,   266,   105,   468,   269,   108,  2223,   248,
     249,   265,   269,   102,   269,   269,   269,   106,   248,   249,
     121,   260,   922,   112,   113,   264,   115,   116,   248,   249,
     493,   644,   266,   646,   647,   269,   261,   261,   575,   269,
     149,   150,   151,   152,   269,   269,   155,   144,   137,   269,
     663,   582,   248,   249,     6,   164,   519,   144,  2273,   168,
    1169,   111,   112,   111,   112,   162,   261,     6,   263,   682,
     262,   261,  2016,   269,   269,   162,   173,   174,   175,   269,
     262,   544,   179,   180,   248,   249,   173,   174,   175,   260,
     553,   554,   179,   180,   260,   558,   709,   560,   561,   562,
     563,   564,   717,   248,   249,   269,   261,   570,   263,   248,
     249,   574,   575,   576,   269,   578,   579,   580,   581,   260,
     583,   581,   585,   583,   269,   260,   248,   249,   260,   144,
     269,   248,   249,   149,   150,   260,   749,   248,   249,   155,
     248,   249,   264,   193,   194,   193,   194,   162,   611,    56,
     248,   249,   269,   264,   617,   144,   248,   249,   173,   174,
     175,   269,   439,   123,   179,   180,   248,   249,   265,   257,
     258,   269,   264,   162,   257,   258,   639,   640,   265,   265,
     260,   264,   773,   269,   173,   174,   175,   269,   265,  1089,
     179,   180,   269,   264,   655,   656,  1305,   248,   249,   730,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   269,   248,
     249,   260,   259,   248,   249,   688,   689,   690,   265,   105,
     248,   249,   108,   696,   110,   261,   260,   263,   265,   261,
     269,   263,   269,   269,   269,   121,   105,   269,   260,   108,
     265,   110,   715,   716,   717,   718,   719,   720,   721,   722,
     723,   260,   725,   726,   727,   728,   729,   260,   731,   732,
     733,   734,   735,   265,   734,   738,   261,   269,   263,     6,
       7,   558,   793,   560,   269,   562,   563,   750,   653,   654,
     260,  1519,   265,   658,   257,   258,   269,   260,   829,   262,
     763,   578,   579,   250,   251,   252,   253,   254,   261,   216,
     263,   264,   259,   257,   258,   778,   260,   260,   262,   262,
     264,   784,   257,   258,     6,   260,  1226,   262,  1228,   265,
     260,   265,   108,   269,   110,   269,     8,   800,   801,   108,
     265,  1241,   265,   806,   269,   808,   269,   265,   811,   812,
     265,   269,   265,   261,   269,   263,   269,   820,     6,   822,
     951,   110,   265,   265,   977,   272,   269,   269,   265,   264,
     264,  1271,   269,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   260,  1615,   265,   852,
     259,   854,   269,   260,   265,   265,   264,  1625,   269,   269,
     108,   265,   265,   310,     3,   269,   269,   265,   265,   265,
     264,   269,   269,   269,   321,   265,   265,   265,   325,   269,
     269,   269,   265,  2177,   260,   265,   269,   890,    27,   269,
     105,   260,   265,   964,  1334,  1335,   269,   900,   260,   716,
     262,   718,   719,   720,   721,   722,   723,   264,   725,   726,
     727,   728,   108,   265,   731,   732,   733,   269,   266,  1359,
     268,   924,  2209,   265,    63,   265,  1366,   269,   265,   269,
     265,   265,   269,   264,   269,   269,   260,   940,   262,   265,
    2234,     8,  1073,   269,   265,  1385,   265,   265,   269,   952,
     269,   269,   260,   264,   262,   265,  1087,  1088,   961,   269,
     105,   265,   265,   265,  2251,   269,   269,   269,     6,   105,
     973,   265,  1412,  1104,     4,   269,     6,   265,   117,   265,
       8,   269,   108,   269,   265,   265,  1426,   265,   269,   269,
     108,   269,   265,  1433,   811,     4,   269,   265,   445,   446,
     265,   269,   265,   265,   269,   822,   269,   269,   265,   265,
     149,     4,   269,   269,   461,   154,   155,   156,     6,   265,
    1091,     4,     4,   269,   163,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   261,   260,   263,   264,   259,     6,   260,
     260,     6,     6,   265,   262,   260,   262,   264,     6,   268,
     264,   200,     6,   260,     9,  1389,   268,   260,   260,   260,
     260,   260,   196,   196,   260,   980,   196,   264,   217,  1082,
     264,   133,   987,   260,   260,   260,   991,  1090,   260,   196,
     264,   260,   260,   260,   264,  1098,   260,     4,   264,   264,
     260,   264,   264,  1752,  1753,   260,   260,   260,  1111,   260,
     260,  1242,  1243,  1116,   561,     6,   260,     6,     6,   258,
     262,   264,     7,   264,   264,   262,   264,   574,     6,   576,
     264,   262,   262,     6,   196,   274,   275,   264,   260,   260,
       6,   260,     6,  1146,  1147,   260,  1149,  1150,  1151,   260,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
     260,   260,  1165,     7,     8,   260,   262,   264,  1169,     6,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     8,     6,
       8,   260,   259,   264,   261,     7,   263,     6,   264,   264,
       6,   264,    97,     7,  1207,  1208,  1209,   265,   269,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   269,   261,     6,
    1233,   259,     6,   261,   261,   264,    67,     8,   264,   264,
    1145,   264,   264,   264,   259,     7,  1249,  1250,  1251,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   266,     7,   260,
       6,   259,   261,     7,   264,     6,   193,     7,     6,     6,
     265,   265,  1413,  1414,   264,   263,   265,   261,     6,   264,
     266,     7,     6,   262,  1618,   260,   264,     6,     6,  1116,
     439,     6,     6,  1306,  1305,     6,   262,     7,   261,     7,
       7,   450,     7,     7,     7,     7,   763,     7,     7,     7,
       7,     7,  1325,     7,  1327,  1328,     7,     7,     7,   264,
       6,   261,   263,   472,  1337,   269,   269,   269,   265,  1342,
     269,   261,     7,  1346,   265,     7,   264,   266,   487,   264,
       4,     6,  1355,   266,  1357,   265,   265,  1360,   144,   264,
       7,     6,   266,     7,     7,     7,  1437,   261,  1439,   261,
     269,   269,     9,  1376,   261,   196,   269,   263,   268,  1819,
       7,   264,   266,  2032,   165,   265,  1389,     6,     6,     6,
      49,  1208,  1209,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,  1414,   266,    49,   260,   259,  1419,   264,  1421,   558,
     260,   560,   264,   562,   563,   564,   260,   266,   266,     7,
     260,     7,     7,   269,   261,   196,  1439,     7,     7,   578,
     579,     5,     7,     6,   269,   261,     7,     7,  1451,     7,
    1603,     7,  1455,     7,  1607,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,  1626,  1627,     4,   120,   259,   264,   924,     6,     6,
     260,     7,     7,     7,  1615,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     7,     7,     7,     7,    62,    63,
      64,    65,     7,  1827,   264,   102,    70,    71,    72,    73,
    1513,  1514,  1515,     6,   961,    79,     6,    81,  1521,  1522,
    1523,     6,   661,   108,     7,  1342,     7,  1598,     6,  1346,
       6,    95,     7,     7,    98,     4,   269,  1540,  1355,   261,
    1357,   267,     6,  1360,   269,   264,   685,   264,  1551,   264,
       6,     6,   265,     7,     6,   262,  1559,     6,     6,     6,
    1563,   260,   264,     6,   260,     6,     6,     6,     6,     6,
     137,  1574,     6,  1576,   265,     6,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   263,   725,   726,   727,   728,
    1661,   266,   731,   732,   733,   269,  1727,  1414,     6,     6,
       6,     6,   741,     6,     6,   744,     6,     6,     6,     6,
       5,   261,   265,   261,     6,  1618,     6,     4,   757,     7,
       6,     6,   262,  1626,  1627,   264,   264,     7,     6,  1632,
     264,   264,   264,     6,   264,  1082,   264,     6,   264,   264,
     264,   264,     6,   265,  1549,     6,   192,  1650,   212,   213,
     214,  1098,   264,   792,   264,   794,     6,   261,  1661,   264,
     224,   269,   269,  1666,   228,     6,   230,   269,   269,     6,
     266,     7,   811,   260,   264,  1830,     6,  1748,     6,   265,
       6,     6,     4,   822,     7,     6,   260,   260,     6,     6,
       6,   144,   106,     6,     5,   261,   264,     6,   269,  1146,
    1147,     6,  1149,  1150,  1151,   264,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,     6,   264,     6,   144,
     144,   269,  1793,     6,     6,     6,     6,     6,     6,  1800,
    1801,   269,   261,   269,     6,     6,  1739,     6,     6,   269,
       6,  1744,  1745,   264,  2068,   264,     6,     6,     6,   264,
    1821,  1752,  1753,     7,   148,     6,   264,   264,   264,     5,
    1207,   261,     6,     6,  1767,   264,     6,   264,     6,   265,
    1773,   265,     7,  1678,     6,  1778,   264,     6,   191,   261,
       7,   265,     6,     6,  1787,   265,  1233,   266,   265,     6,
       6,     6,  1795,   264,     6,  1798,     6,   265,     6,     6,
     261,     6,  1249,     6,   264,   194,     6,   264,     6,     6,
       6,     6,     6,  1816,   265,   265,   260,  1820,   264,   261,
     265,     6,     6,     6,  1827,   144,  1829,  1830,   264,   264,
       6,   264,   264,  1650,   264,   261,     6,   976,     6,   978,
     979,     6,   265,   265,     6,     6,     6,     6,     6,     6,
       6,     6,   264,   992,   264,     6,     6,     6,     6,  1306,
     264,     6,  1865,  1768,  1769,  1770,  1771,  1772,  1773,     6,
    2190,  1425,  1487,  1012,   490,  1673,  1999,  1959,  1325,  1882,
    1327,  1328,  1735,     3,     3,     3,  1100,  1450,  2041,     3,
    1961,  1894,  1895,  2028,   632,  1034,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     3,  1595,  1919,  1800,   259,  1820,
    1627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1931,  1376,
     811,    -1,  1071,  2004,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1948,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1116,  1795,    -1,
      -1,  1798,  1985,    -1,    -1,  2138,    -1,    -1,    -1,    -1,
      -1,    -1,  1439,    -1,    -1,    -1,    -1,  2000,    -1,    -1,
      -1,    -1,  2005,    -1,  1451,  2008,  2009,     6,  1455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2026,    -1,  2178,  2029,    -1,    -1,    -1,
      -1,  2032,    -1,    -1,    -1,    -1,    -1,  2040,    -1,    -1,
      -1,  2044,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,     6,    -1,   259,  2068,  1513,  1514,  1515,  1208,
    1209,    -1,    -1,    -1,  1521,  1522,  1523,    -1,  2081,    -1,
      -1,    -1,    -1,  2154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1540,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1551,    -1,    -1,  2110,    -1,    -1,
      -1,    -1,  1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1574,    -1,  1576,
      -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,    -1,    -1,
    2045,  2046,  2047,  2048,  2049,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,  2180,  2181,  2182,
    2183,  2184,    -1,    -1,    -1,  1632,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,  1342,  2109,   259,    -1,  1346,  2113,    -1,
      -1,    -1,    -1,     6,  1661,    -1,  1355,    -1,  1357,    -1,
    2223,  1360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1370,    -1,    -1,    -1,    -1,  2239,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,  2260,    -1,  2164,
     259,    -1,    -1,  2168,    -1,    -1,    -1,    -1,    -1,    -1,
    2273,    -1,    -1,    -1,    -1,  1414,  2279,  2280,    -1,  2184,
      -1,     6,    -1,     4,     5,    -1,    -1,    -1,    -1,  2292,
      -1,    -1,  1739,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
    1767,    -1,    -1,    -1,  2229,  2230,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
    1787,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1816,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,   102,  1829,    -1,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   140,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1882,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2260,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,  2279,  2280,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,  1919,    -1,    -1,  2292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1626,  1627,    -1,
      -1,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,   230,
     231,  1650,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   257,   258,  1985,   121,
      -1,    -1,   144,   264,    -1,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2000,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,  2026,
      -1,    -1,    -1,   165,    -1,    -1,   168,    -1,    -1,    13,
      14,    -1,    -1,  2040,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,   198,   199,    -1,   201,
     202,   203,   204,    -1,    -1,    -1,    -1,   209,   210,    -1,
      -1,    -1,    -1,    -1,  2081,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,  1795,   259,    -1,  1798,
      -1,     6,    -1,  2110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1813,    -1,  1815,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,  1830,    -1,    -1,   118,   119,   120,   121,    -1,    -1,
     124,    -1,    -1,    -1,   286,   287,   288,   289,   290,   133,
     134,    -1,    -1,   137,   138,    -1,   140,   141,    -1,   143,
      -1,    -1,    -1,   305,   306,   307,  1865,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,
      -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,   334,    -1,    -1,    -1,    -1,   339,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   189,   190,   349,   350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,
     372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     382,    -1,   384,   385,    -1,   387,    -1,    -1,    -1,   391,
     392,   393,    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2273,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,   441,
     442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   458,   459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   473,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,   495,   259,    -1,    -1,    -1,   500,    -1,
      -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   518,   519,    -1,    -1,
      -1,    -1,   524,    -1,    -1,    -1,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,    -1,   556,   557,    -1,   559,    -1,    -1,
      -1,    -1,    -1,  2122,    -1,    -1,    -1,   569,    -1,    -1,
     572,   573,    -1,    -1,    -1,    -1,   209,   210,   580,    -1,
      -1,    -1,    -1,   585,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,    -1,   618,   619,    -1,    -1,
      -1,    -1,    -1,    -1,   626,   627,   628,    -1,    -1,  2188,
      -1,    -1,   634,   635,   636,   637,    -1,   639,   640,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2210,    -1,    -1,    -1,    -1,   658,   659,   660,    -1,
      -1,    -1,   664,   665,   666,   667,   668,   669,   670,   671,
     672,    -1,    -1,   306,   307,    -1,   678,   679,    -1,   681,
      -1,    -1,   684,    -1,    -1,    -1,   688,   689,   690,   691,
      -1,    -1,    -1,   695,   696,   697,   698,   699,    -1,    -1,
     702,  2260,   704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,
    2279,  2280,   724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2292,    -1,    -1,   738,    -1,    -1,    -1,
      -1,    -1,    -1,   745,   746,    -1,   748,    -1,    -1,   751,
     752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   778,    -1,   780,    -1,
      -1,   209,   210,   785,   786,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   800,    -1,
     802,   803,    -1,    -1,   806,    -1,   808,   809,   441,    -1,
      -1,   813,    -1,   815,    -1,   817,    -1,    -1,    -1,    -1,
      -1,   823,    -1,    -1,    -1,   827,    -1,    -1,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   850,    -1,
     852,   259,   854,   261,    -1,   263,    -1,    -1,    -1,   287,
      -1,   269,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   890,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   900,   901,
     902,   903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     912,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,
     952,    -1,   585,    -1,    -1,    -1,    -1,    -1,   960,    -1,
      -1,    -1,   964,    -1,    -1,    -1,    -1,    -1,   970,    -1,
      -1,   973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,
     982,    -1,    -1,    -1,    -1,   987,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1004,    -1,    -1,  1007,   639,   640,    -1,    -1,
      -1,    -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1033,    -1,  1035,  1036,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1054,     6,    -1,   688,   689,   690,    -1,    -1,
      -1,    -1,    -1,   696,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1078,    -1,    -1,    -1,
      -1,    -1,    -1,  1085,    -1,    -1,    -1,    -1,    -1,    -1,
    1092,   519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1105,  1106,   738,    -1,    -1,    -1,  1111,
      -1,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   553,   554,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1143,    -1,    -1,    -1,   778,    -1,    -1,    -1,    -1,
      -1,    -1,   580,    -1,    -1,    -1,    -1,   585,    -1,    -1,
      -1,    -1,    -1,  1165,    -1,    -1,    -1,   800,    -1,    -1,
      -1,    -1,    -1,   806,    -1,   808,    -1,    -1,    -1,    -1,
      -1,  1183,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1193,  1194,  1195,  1196,  1197,    -1,    -1,    -1,    -1,
    1202,  1203,    -1,  1205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   639,   640,    -1,    -1,    -1,    -1,    -1,    -1,  1221,
    1222,    -1,    -1,    -1,    -1,    -1,    -1,  1229,  1230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1238,  1239,    -1,    -1,
      -1,    -1,  1244,  1245,    -1,    -1,    -1,    -1,  1250,  1251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   890,    -1,    -1,
     688,   689,   690,    -1,    -1,    -1,    -1,   900,   696,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1285,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,   940,    -1,    -1,
     738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   952,
      -1,  1323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1337,    -1,    -1,    -1,    -1,
     973,    -1,    -1,  1345,    -1,    -1,    -1,    -1,    -1,    -1,
     778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1367,  1368,    -1,    -1,    -1,
    1372,    -1,   800,    -1,    -1,    -1,    -1,    -1,   806,    -1,
     808,  1383,    -1,    -1,  1386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1415,    -1,    -1,  1418,  1419,  1420,  1421,
      -1,    -1,    -1,    -1,   852,    -1,   854,  1429,    -1,    -1,
    1432,    -1,  1434,    -1,  1436,  1437,     8,    -1,  1440,  1441,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,   890,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,   900,    -1,    79,    -1,    81,    -1,  1111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   940,    -1,    -1,    -1,   121,    -1,  1520,    -1,
      -1,    -1,    -1,    -1,   952,    -1,    -1,    -1,    -1,  1531,
    1532,  1533,  1165,    -1,    -1,   140,    -1,    -1,  1540,    -1,
    1542,    -1,    -1,    -1,    -1,   973,    -1,  1549,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1563,    -1,    -1,    -1,    -1,    -1,  1569,  1570,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,  1581,
    1582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1590,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1250,  1251,   224,
    1622,    -1,    -1,   228,    -1,   230,   231,    -1,  1630,  1631,
       6,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,   261,   463,   263,   264,
      -1,    -1,    -1,    -1,  1666,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,  1111,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1337,    -1,  1708,  1709,  1710,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,  1719,    -1,    -1,
      -1,    -1,  1724,  1725,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1737,    -1,  1165,    -1,    -1,
      -1,    -1,  1744,  1745,  1746,    -1,  1748,    -1,    -1,    -1,
      -1,    -1,  1754,  1755,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   570,    -1,    -1,    -1,    -1,    -1,
      -1,  1773,    -1,    -1,    -1,    -1,  1778,  1779,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1419,    -1,  1421,    -1,
      -1,  1793,    -1,    -1,  1796,    -1,    -1,    -1,  1800,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1809,  1810,    -1,
    1812,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
    1822,    -1,  1250,  1251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1836,    -1,    -1,    -1,    -1,  1841,
    1842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1855,    -1,    -1,  1858,  1859,    -1,  1861,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1894,  1895,    -1,    -1,    -1,    -1,    -1,  1901,
    1902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,
      -1,  1913,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1931,
    1563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1944,  1945,    -1,    -1,  1948,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1982,  1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1419,    -1,  1421,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2003,    -1,    -1,    -1,    -1,  2008,  2009,  2010,    -1,
      -1,    -1,    -1,  2015,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2029,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2053,    -1,    -1,   860,   861,   862,   863,   864,   865,
     866,   867,   868,   869,   870,    -1,   872,   873,   874,   875,
      -1,   877,   878,   879,   880,    -1,  2078,    -1,    -1,    26,
      -1,    28,  2084,    -1,    -1,  2087,    -1,   893,    -1,   895,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     906,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,   915,
      -1,  1744,  1745,    -1,    -1,    -1,  2118,   923,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1563,    -1,    -1,    -1,    -1,
      -1,    -1,  2144,  2145,    -1,  1778,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2159,  2160,    -1,
    2162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2175,    -1,    -1,    -1,    -1,  2180,  2181,
    2182,  2183,  2184,    -1,    -1,    -1,    -1,    -1,  2190,    -1,
      -1,    -1,  2194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2221,
      -1,    -1,    -1,    -1,  2226,  2227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1040,  1041,  1042,  2239,  1666,    -1,
    1046,  1047,    -1,    -1,  1050,  1051,  1052,  1053,    -1,  1055,
      -1,    -1,    -1,    -1,  1060,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,  1895,    -1,  2266,  2267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,   255,   256,
      -1,    -1,    -1,    -1,    -1,  1948,  1744,  1745,   265,   266,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,   278,   279,     4,     5,    -1,  1142,    -1,  1144,    -1,
      -1,    -1,    -1,    -1,    -1,  1773,    -1,    -1,    -1,    -1,
    1778,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,  2008,  2009,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,  2029,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,  2044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,
      -1,  1247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   398,   399,   400,    -1,    -1,    -1,   404,   405,   406,
     407,   408,   409,   410,    -1,   412,  1894,  1895,    -1,   140,
     417,   418,    -1,     6,   421,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1931,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1948,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  2162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,    -1,    -1,    -1,  2180,  2181,  2182,
    2183,  2184,    -1,   224,    -1,    -1,    -1,   228,    -1,   230,
     231,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
    2008,  2009,    -1,   259,    -1,    -1,    -1,    -1,    -1,  1395,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2029,    -1,    -1,    -1,    -1,  2239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2044,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,    -1,    -1,    -1,    -1,  1481,  1482,    -1,    -1,    -1,
      -1,    -1,  1488,    -1,    -1,  1491,    -1,    -1,    -1,  1495,
      -1,    -1,  1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1509,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2180,  2181,  2182,  2183,  2184,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,     6,    -1,    -1,    -1,   259,
    1586,    -1,  1588,    -1,    -1,    -1,  1592,    -1,  1594,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,  2239,   259,    -1,   261,    -1,    -1,    -1,    -1,    -1,
    1626,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       6,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    -1,    81,    82,    83,    84,     7,
    1726,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,
     136,   918,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   168,    -1,   951,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,  1832,   193,   259,  1835,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,   221,   222,   223,   224,   225,
     226,   227,   228,    -1,   230,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1884,  1885,
      -1,  1887,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,
      -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1952,  1953,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,  1136,
      -1,    10,    11,    12,    -1,  2001,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,   105,  1234,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,     8,    -1,    -1,   164,    -1,    -1,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,   211,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,   260,  2248,    -1,    -1,   264,    -1,    -1,   267,  1396,
    1397,    -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,  1493,    98,    -1,    -1,
      -1,   102,    -1,    -1,   105,  1502,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   140,
      -1,    -1,    -1,   259,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,    -1,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,   257,   258,    -1,   260,
      -1,   262,     3,     4,     5,   266,   267,    -1,  1665,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   193,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,
     221,   222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,
       3,     4,    -1,   264,    -1,     8,   267,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,    -1,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,   168,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,     3,     4,
       5,    -1,   265,    -1,   267,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,   159,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,   168,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,   193,    -1,
      -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
     215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,
     225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,   260,     3,     4,    -1,   264,
      -1,    -1,   267,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,   168,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   193,    -1,    -1,    -1,
     265,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,   226,
     227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,   260,     3,     4,    -1,   264,   265,    -1,
     267,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   168,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,   193,    -1,    -1,    -1,   265,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,   215,   216,    -1,    -1,
      -1,    -1,   221,   222,   223,    -1,   225,   226,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,   260,     3,     4,    -1,   264,    -1,    -1,   267,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   193,    -1,    -1,    -1,   265,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,
     221,   222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,
       3,     4,    -1,   264,    -1,    -1,   267,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,    -1,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,   168,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,     3,     4,
      -1,   264,    -1,    -1,   267,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,   159,   160,    -1,    -1,    -1,   164,
      -1,    -1,    -1,   168,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,   193,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
     215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,
     225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,   260,     3,     4,    -1,    -1,
     265,    -1,   267,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,   168,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,   226,
     227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,   260,     3,     4,    -1,   264,    -1,    -1,
     267,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   168,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,   215,   216,    -1,    -1,
      -1,    -1,   221,   222,   223,    -1,   225,   226,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,   260,     3,     4,    -1,   264,    -1,    -1,   267,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,
     221,   222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,
       3,     4,    -1,   264,    -1,     8,   267,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,    -1,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,   164,    -1,    -1,    -1,   168,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
     193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,     3,     4,    -1,    -1,   260,     8,    -1,
      10,    11,    12,    -1,   267,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,   135,   136,    -1,   138,    -1,
     140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,    -1,   155,   156,   157,   158,   159,
     160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,   225,   226,   227,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
      -1,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,    -1,
     260,    -1,    -1,    10,    11,    12,    -1,   267,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,    -1,   155,   156,
     157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,
      -1,   168,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,   216,
      -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,   226,
     227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,   260,     3,     4,    -1,   264,    -1,    -1,
     267,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   168,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   211,    -1,    -1,    -1,   215,   216,    -1,    -1,
      -1,    -1,   221,   222,   223,    -1,   225,   226,   227,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,   260,     3,     4,    -1,   264,    -1,    -1,   267,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,
     221,   222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,     3,     4,     5,    -1,   260,
      -1,    -1,    10,    11,    12,    -1,   267,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      98,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,   221,
     222,   223,   224,   225,   226,   227,   228,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,     3,
       4,     5,   264,    -1,    -1,   267,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    -1,    98,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,    -1,   230,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
     264,    -1,    -1,   267,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,
      -1,    -1,    -1,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,    -1,   260,    -1,    -1,    10,    11,    12,    -1,   267,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    93,    94,
      -1,    96,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,
     215,   269,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,
     225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,
      -1,    -1,   267,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,   269,    -1,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,    -1,   225,   226,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,     3,     4,    -1,   264,    -1,     8,   267,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    93,    94,    -1,    96,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    -1,    96,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,   215,   269,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,   225,   226,   227,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,   267,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,
     269,    -1,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,     3,     4,    -1,     6,   260,   261,    -1,
      10,    11,    12,    -1,   267,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    -1,    96,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   211,    -1,    -1,   259,   215,    -1,    -1,    -1,    -1,
      -1,   221,   222,   223,   269,   225,   226,   227,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,   267,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,
     226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,
       3,     4,    -1,     6,   260,    -1,    -1,    10,    11,    12,
      -1,   267,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      93,    94,    -1,    96,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,   215,   269,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,   267,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,   269,    -1,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,
     226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,
       3,     4,    -1,    -1,   260,   261,    -1,    10,    11,    12,
      -1,   267,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      93,    94,    -1,    96,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   211,    -1,
      -1,    -1,   215,   269,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,   261,    -1,
      -1,    -1,    -1,    -1,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,   211,    -1,    -1,   259,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,   269,   225,
     226,   227,    -1,    -1,    -1,   231,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,   248,   249,   118,   119,   120,   121,    -1,   255,
     124,    -1,    -1,    -1,   260,    -1,    13,    14,    -1,   133,
     134,   267,    -1,   137,   138,    -1,   140,   141,    -1,   143,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,   161,   118,   119,
     120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,    -1,    -1,   137,   138,    -1,
     140,   141,    -1,   143,   188,   189,   190,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   188,   189,
     190,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      13,    14,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,   188,   189,   190,    -1,   265,    -1,   133,   134,    -1,
      -1,   137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,   134,    -1,    -1,   137,   138,    -1,   140,   141,    -1,
     143,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   265,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,   124,    -1,    -1,   188,   189,   190,    13,    14,
      -1,   133,   134,    -1,    -1,   137,   138,    -1,   140,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   188,   189,   190,   118,
     119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,   265,    -1,   133,   134,    -1,    -1,   137,   138,
      -1,   140,   141,    -1,   143,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,   161,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
      -1,    -1,   137,   138,    -1,   140,   141,    -1,   143,   188,
     189,   190,    -1,   265,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,   188,   189,   190,    -1,    -1,    13,    14,
     269,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,
     265,    13,    14,    -1,   133,   134,    -1,    -1,   137,   138,
      -1,   140,   141,    -1,   143,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,   161,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
      -1,    -1,   137,   138,    -1,   140,   141,    -1,   143,   188,
     189,   190,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   188,   189,   190,   118,   119,   120,   121,
      -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,    -1,    -1,   137,   138,    -1,   140,   141,
      -1,   143,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    13,    14,   118,   119,   120,
     121,    -1,    -1,   124,    -1,    -1,   188,   189,   190,    -1,
     265,    -1,   133,   134,    -1,    -1,   137,   138,    -1,   140,
     141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,   189,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   265,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,
     138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   265,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
     188,   189,   190,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   188,   189,   190,   118,   119,   120,   121,    -1,    -1,
     124,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,   133,
     134,    -1,    -1,   137,   138,    -1,   140,   141,    -1,   143,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    13,    14,
      -1,    -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   188,   189,   190,   259,   265,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    -1,    91,    92,    -1,    94,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,   265,   117,   118,   119,   120,   121,   122,    -1,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,    -1,    -1,
     145,   146,   147,    -1,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,   176,   177,   178,    -1,    -1,    -1,   182,    -1,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,     4,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   229,    -1,   231,   232,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    46,
      47,    48,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    -1,    91,    92,    -1,    94,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
     117,   118,   119,   120,   121,   122,    -1,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,    -1,    -1,   145,   146,
     147,    -1,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,
     187,   188,   189,   190,     4,     5,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,   231,   232,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,     4,     5,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,    -1,   102,     4,     5,   105,    -1,    -1,   108,    -1,
     110,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,   121,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
     140,    79,    -1,    81,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    95,    -1,    -1,
      98,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,
     230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,   214,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     228,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,   230,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,   134,    -1,    -1,   137,   138,    -1,   140,   141,
      -1,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,    -1,    -1,   165,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,   188,   189,   190,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   269,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   269,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   269,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,   265,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,   265,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
      -1,   265,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
     265,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,   265,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,   265,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
      -1,   265,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
     265,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,   265,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,   265,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,
      -1,   265,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
     265,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,   264,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,   264,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,   261,    -1,   263,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   263,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
     263,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,   263,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,   263,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,   263,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,   263,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,   263,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,   263,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,   263,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
     263,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,   263,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,   263,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,   263,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   261,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   271,   272,     6,     0,     4,    13,    14,    46,
      47,    48,    67,    68,    69,    74,    75,    80,    85,    86,
      87,    88,    89,    91,    92,    94,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   117,   118,   119,   120,   121,   122,   124,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   145,   146,   147,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   176,   177,   178,   182,   187,   188,   189,
     190,   193,   195,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   217,   218,   219,
     220,   229,   231,   232,   273,   275,   276,   297,   316,   318,
     322,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     340,   342,   343,   349,   350,   351,   352,   358,   382,   383,
     264,   268,    14,   108,   260,   260,   260,     6,   264,     6,
       6,     6,     6,   260,     6,   264,     6,   264,   264,     6,
       6,   262,   262,     4,   360,   383,   260,   262,   294,   102,
     105,   108,   110,   318,   294,   260,   260,   260,     4,   260,
     260,   260,     4,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   264,   123,   108,     6,     6,   264,
     264,   102,   105,   108,   121,   321,   110,   260,     3,    10,
      11,    12,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    58,    59,    60,    61,    66,    67,    76,
      77,    78,    82,    83,    84,    93,    96,   102,   105,   108,
     110,   121,   133,   138,   140,   143,   193,   211,   215,   216,
     221,   222,   223,   225,   226,   227,   248,   249,   255,   260,
     264,   267,   318,   319,   322,   333,   340,   342,   353,   354,
     358,   360,   366,   368,   383,   260,   264,   264,   108,   108,
     133,   105,   108,   110,   318,   105,   108,   109,   110,   121,
     188,   319,   105,   108,   260,   105,   165,   193,   209,   210,
     264,   248,   249,   260,   264,   363,   364,   363,   264,   264,
     363,     4,   102,   106,   112,   113,   115,   116,   137,   264,
     260,   108,   110,   108,   105,     4,    94,   204,   264,   383,
       4,     6,   102,     6,   105,   108,   105,   108,   121,   320,
       5,   260,   264,   366,   367,   108,     4,     4,     4,   367,
       4,   108,   260,   108,   260,   260,     4,   264,   370,   383,
       4,   260,   260,   260,     6,     6,   262,     5,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    62,    63,    64,
      65,    70,    71,    72,    73,    79,    81,    95,    98,   212,
     213,   214,   224,   228,   230,   374,   383,   260,     4,   374,
       5,   264,     5,   264,   318,    32,   249,   353,   383,   262,
       6,   264,   260,   264,     6,   260,   264,     6,   268,     7,
     140,   204,   233,   234,   235,   236,   257,   258,   260,   262,
     266,   292,   293,   294,   318,   353,   373,   374,   383,     4,
     322,   323,   324,   264,     6,   353,   373,   374,   383,   373,
     373,   353,   373,   380,   381,   383,   353,   324,   353,   299,
     303,   260,   362,     9,   374,   260,   374,   353,   353,   353,
     260,   353,   353,   353,   260,   353,   353,   353,   353,   353,
     353,   353,   373,   353,   353,   353,   353,   367,   260,   249,
     353,   368,   369,   369,   264,   367,   366,   373,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   260,   262,   294,   294,   294,   294,   294,
     294,   260,   294,   294,   260,   318,   319,   319,   319,   294,
     294,     5,   264,   264,   133,   318,   318,   319,   260,   294,
     294,   260,   260,   260,   353,   264,   353,   368,   353,   353,
     265,   369,   360,   383,   196,     5,   264,     8,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   259,     9,   260,   262,
     266,   293,   294,   353,   369,   369,   260,   260,   260,   366,
     367,   367,   367,   317,   260,   264,   260,   260,   366,   264,
     264,   353,     4,   366,   264,   370,   264,   264,   363,   363,
     363,   353,   353,   248,   249,   264,   264,   363,   248,   249,
     260,   324,   363,   264,   260,   264,   260,   260,   260,   260,
     260,   260,   260,   369,   353,   367,   367,   367,   260,   264,
       4,   262,   264,     6,   262,   324,     6,     6,   264,   264,
     264,   264,   367,   353,     8,     7,   264,   262,   262,   262,
       6,     6,   260,   353,   260,   353,   353,   266,   353,   264,
     196,   353,   353,   353,   353,   294,   294,   294,   260,   260,
     260,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   260,   260,   294,   260,   262,     6,     6,   264,     6,
       8,   324,     6,     8,   324,   260,   294,   353,   250,   264,
       9,   260,   262,   266,   373,   369,   353,   324,   366,   366,
     264,   374,   318,     7,   353,   353,     4,    36,    37,   111,
     112,   193,   194,   296,   366,     6,   261,   263,   264,   295,
     264,     6,   264,     6,     9,   260,   262,   266,   383,   265,
     133,   138,   140,   141,   143,   316,   318,   353,     6,   261,
     269,     9,   260,   262,   266,   261,   269,   261,   269,   269,
     261,   269,     9,   260,   266,   269,   265,   269,   263,   269,
     298,   263,   298,    97,   361,   359,   383,   269,   353,   269,
     261,   261,   261,   353,   261,   261,   261,   353,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   265,
       7,   353,   250,   265,   269,   265,   353,     6,     6,   261,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   368,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   368,   368,   383,
     264,   353,   353,   373,   353,   373,   366,   373,   373,   380,
     264,   264,   264,   264,   353,   295,   383,     8,   353,   353,
     367,   366,   264,   373,   373,   368,   360,   374,   360,   369,
     261,   265,   266,   294,    67,     8,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     264,   353,   368,   353,   353,   353,   353,   353,   383,   353,
     353,   296,   264,   295,   261,   265,   265,   353,   353,   353,
       7,     7,   346,   346,   260,   353,   353,   353,   353,     6,
     169,   369,   369,   264,   261,     6,   324,   264,   324,   324,
     269,   269,   269,   363,   363,   323,   323,   269,   353,   265,
     337,   269,   324,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   265,   261,     7,   347,     6,     7,   353,   353,
       6,   353,   324,   353,   265,   369,   369,   369,   353,     6,
     261,   265,   353,   369,   353,   353,   353,   353,   261,   353,
     261,   261,   193,   269,   324,   264,     8,   261,   261,   263,
     380,   373,   380,   373,   373,   373,   373,   373,   373,   353,
     373,   373,   373,   373,   267,   376,   383,   374,   373,   373,
     373,   360,   383,   369,   265,   265,   265,   265,   353,   353,
     353,   324,   383,   296,   263,   265,   261,   147,   165,   341,
     261,   265,   269,   353,     6,   264,   366,   261,   263,   266,
       7,     7,   292,   293,     6,   369,     7,   236,   292,   353,
     277,   383,   353,   353,   296,   262,   260,   133,   318,   319,
     318,   264,   265,     6,   243,   244,   274,   369,   383,   353,
     353,   296,     6,   369,     6,   369,   353,     6,   373,   381,
     383,   261,   296,   353,   353,     6,   383,     6,   373,   353,
     261,   262,   353,   269,   374,     7,     7,     7,   261,     7,
       7,     7,   261,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   353,   261,   264,   353,   368,     6,   264,
     265,     6,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   269,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   269,   269,   269,   269,   269,   261,   263,
     263,   369,   269,   269,   295,   269,   295,   269,   269,   269,
     261,   369,   353,   353,   353,   355,   295,   265,   265,   265,
     353,   269,   269,   295,   295,   261,   266,   261,   266,   269,
     294,   356,   265,     7,   296,   295,   366,   265,     8,     8,
     369,   266,   261,   263,   260,   262,   293,   294,   369,     7,
     264,   264,   261,   261,   261,   353,   366,     4,   345,     6,
     312,   353,   374,   261,   265,   261,   261,   353,   265,   265,
     369,   266,   265,   324,   265,   265,   363,   353,   353,   265,
     265,   353,   363,   144,   144,   162,   173,   174,   175,   179,
     180,   338,   339,   363,   265,   334,   261,   265,   261,   261,
     261,   261,   261,   261,   261,   264,     7,   353,     6,   353,
     261,   265,   263,   265,   263,   265,   265,   265,   265,     6,
     265,   263,   263,   269,   261,     7,   261,     7,     7,   266,
     353,   265,   353,   353,     7,   266,   295,   269,   295,   295,
     261,   261,   269,   295,   295,   269,   269,   295,   295,   295,
     295,   353,   295,     9,   375,   269,   261,   269,   295,   266,
     269,   357,   263,   265,   261,   265,   266,   260,   262,   268,
     196,     7,   165,     6,   353,   265,   264,     6,   366,   265,
     353,     6,     7,   292,   293,   266,   292,   293,   296,   264,
     371,   383,   374,   353,     6,   265,    49,    49,   366,   265,
       4,   183,   184,   185,   186,   265,   280,   284,   287,   289,
     290,   332,   266,   261,   263,   260,   353,   353,   260,   264,
     260,   264,     8,   369,   373,   261,   266,   261,   263,   260,
     261,   261,   269,   266,   260,   265,   269,     7,   294,     4,
      36,    37,   306,   307,   308,   295,   353,   295,   363,   366,
     366,     7,   366,   366,   366,     7,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,     6,     7,   369,   323,
     353,   353,   353,   353,   353,   353,   265,   353,   353,   353,
     366,   373,   373,   265,   265,   265,   265,   269,   305,   265,
     353,   353,   296,   296,   353,   353,   261,   366,   294,   353,
     353,   265,   296,   293,   266,   293,   353,   353,   295,   265,
     366,   369,   369,     7,     7,     7,   144,   344,     6,   261,
     269,     7,     7,     7,     6,     7,     7,   265,     4,   296,
     265,   269,   269,   269,   265,   265,   120,     4,     6,   353,
     264,     6,   260,     6,   181,     6,   181,   265,   339,   269,
     338,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     323,   366,     6,   264,   102,     6,     6,     6,   108,     7,
       7,     6,     6,   353,     7,   366,     7,   366,   366,     4,
     269,     8,     8,   261,   296,   296,   369,   373,   353,   373,
     267,   269,   309,   373,   373,   296,   373,   261,   269,     6,
     296,   264,   318,   264,     6,   353,     6,   264,   366,   265,
     265,   353,     6,   193,   194,   296,   353,     6,     7,   370,
     372,     6,   262,     6,     6,   295,   294,   294,     6,   281,
     260,   260,   264,   291,     6,   296,   266,   373,   353,   263,
     261,   353,     8,   369,   353,   369,   265,   265,     6,     6,
     274,   296,   266,   353,     6,     6,   353,   296,   261,     6,
     353,   264,   353,   374,   295,    49,   264,   366,   374,   377,
     353,   353,   263,   269,     6,   261,     6,     6,   137,   314,
     314,   366,     6,     6,     6,   366,   144,   196,   313,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     5,   265,
     265,   295,   295,   295,   295,   295,   295,   295,   269,   269,
     269,   261,   295,   295,   307,   295,   261,   295,   261,   294,
     356,   295,     6,   295,   260,   262,   294,   296,   261,   263,
     295,     6,   265,   265,   366,   366,   366,     4,     6,   292,
     353,   366,   366,   366,   264,   264,     7,     6,     7,   353,
     353,   353,   264,   264,   264,   262,     6,   353,   366,   353,
       6,     6,   353,   363,   265,     5,   366,   264,   264,   264,
     264,   264,   264,   264,   366,   265,     6,   369,   264,   264,
     353,   353,   263,   366,     6,   366,     6,   192,   353,   353,
     353,     6,     6,     7,   295,   269,   269,   295,   269,   353,
       4,   208,   310,   311,   295,   261,   295,   357,   374,   260,
     262,   353,   264,   324,     6,   324,   269,     6,     6,   266,
       7,     7,   292,   293,     6,   370,   265,   269,   353,   292,
     264,   295,   378,   379,   380,   378,   260,   353,   353,   365,
     366,   264,   260,     4,     6,   261,     6,   261,   265,   265,
     261,   265,     6,     6,   373,   260,     4,   261,   269,   260,
     265,   269,   366,   374,     7,   294,   304,   353,   368,   308,
       6,   363,     6,     6,     6,   144,   315,   102,   121,   106,
       6,     5,   264,     6,   353,   353,   353,   353,   261,   356,
     353,   353,   295,   293,   264,   264,     6,   313,     6,   353,
     366,   144,   144,     4,     6,   369,   369,   353,   353,   374,
     265,   261,   265,   269,   323,   323,   353,   353,   265,   269,
     261,   265,   269,     6,     6,   365,   363,   363,   363,   363,
     363,   249,   363,     6,   265,   369,   353,     6,     6,     6,
       6,     6,   366,   265,   269,     8,   265,   261,   264,   353,
     374,   373,   353,   373,   353,   374,   377,   379,   374,   269,
     261,   269,   265,   353,   341,   341,   366,   296,   371,   374,
     353,     6,     6,   370,   263,   366,   380,     6,   295,   295,
     278,   353,   269,   269,   265,   269,   279,   353,   353,     6,
       6,     6,     6,   353,   353,   261,     6,   353,   300,   302,
     264,   379,   265,   269,     7,     7,   148,     6,   264,   264,
     264,     5,   365,   295,   295,   269,   295,   261,   261,   263,
     369,   369,     6,     6,   353,   353,   264,   265,   265,   264,
       6,     6,   264,   353,   265,   265,   265,   263,     6,   366,
       7,   264,   353,   265,   269,   269,   269,   269,   269,   269,
       6,   265,   265,   191,   353,   353,   369,     6,     6,   261,
     295,   295,   311,   374,   265,   265,   265,   265,     7,     6,
       6,     6,   266,     6,   265,     6,     6,   261,   269,   353,
     353,   264,   366,   265,   269,   261,   261,   269,   265,   305,
     309,   366,   295,   353,   374,   383,   369,   369,   353,     6,
     265,   353,   356,   265,   265,     6,     6,   365,   149,   150,
     155,   348,   149,   150,   348,   369,   323,   265,   269,     6,
     265,   366,   324,   265,     6,   369,   363,   363,   363,   363,
     363,     6,   353,   265,   265,   265,   261,     6,   264,     6,
     370,   194,   282,   353,   269,   269,   365,     6,   353,   353,
       6,   265,   265,   301,     7,   260,   265,   265,   265,   264,
     269,   261,   264,   265,   264,   363,   366,     6,   264,   363,
       6,   265,   265,   353,     6,   144,   265,   335,   264,   265,
     269,   269,   269,   269,   269,     6,     6,     6,   324,     6,
     264,   353,   353,   265,   269,   305,   374,   261,   353,   353,
     369,     6,   363,     6,   363,     6,     6,   265,   353,   338,
     324,     6,   369,   369,   369,   369,   363,   369,   341,   279,
     261,   269,     6,   264,   353,   265,   269,   269,   265,   269,
     269,     6,   265,   265,   336,   265,   265,   265,   265,   269,
     265,   265,   265,   285,   353,   365,   265,   353,   353,   363,
     363,   338,     6,     6,     6,     6,   369,     6,     6,     6,
     264,   261,   265,     6,   265,   295,   269,   269,   265,   265,
     283,   373,   288,   264,     6,   353,   353,     6,   265,   269,
     264,   365,   265,   265,     6,   373,   286,   373,   265,     6,
       6,   265,   269,     6,     6,   373
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
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Printf");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Printf", i, (i > 1) ? "s" : "");
      else
	Msg::Direct(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 33:
#line 392 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(1, "Too few arguments in Error");
      else if(i > 0)
	yymsg(1, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Warning(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 34:
#line 405 "Gmsh.y"
    {
      char tmpstring[5000];
      int i = printListOfDouble((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].l), tmpstring);
      if(i < 0)
	yymsg(0, "Too few arguments in Error");
      else if(i > 0)
	yymsg(0, "%d extra argument%s in Error", i, (i > 1) ? "s" : "");
      else
	Msg::Error(tmpstring);
      Free((yyvsp[(3) - (7)].c));
      List_Delete((yyvsp[(5) - (7)].l));
    ;}
    break;

  case 35:
#line 418 "Gmsh.y"
    {
      char tmpstring[5000];
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
	  fprintf(fp, "%s\n", tmpstring);
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
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 803 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 813 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 818 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 824 "Gmsh.y"
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
#line 885 "Gmsh.y"
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
#line 900 "Gmsh.y"
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
#line 928 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 938 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 943 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 951 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 956 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 964 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 973 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 978 "Gmsh.y"
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
#line 990 "Gmsh.y"
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
#line 1007 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 1013 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 1022 "Gmsh.y"
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
#line 1040 "Gmsh.y"
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
#line 1058 "Gmsh.y"
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
#line 1067 "Gmsh.y"
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
#line 1079 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 1084 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1092 "Gmsh.y"
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
#line 1112 "Gmsh.y"
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
#line 1135 "Gmsh.y"
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
#line 1155 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1163 "Gmsh.y"
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
#line 1180 "Gmsh.y"
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
#line 1198 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  if(option->getType() == FIELD_OPTION_LIST) {
	    std::list<int> vl = option->list();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	      double id;
	      List_Read((yyvsp[(9) - (11)].l), i, &id);
	      vl.push_back((int)id);
	    }
	    option->list(vl);
	  }
	  else {
	    std::list<double> vl = option->listdouble();
	    vl.clear();
	    for(int i = 0; i < List_Nbr((yyvsp[(9) - (11)].l)); i++){
	      double id;
	      List_Read((yyvsp[(9) - (11)].l), i, &id);
	      vl.push_back(id);
	    }
	    option->listdouble(vl);
	  }
	}
	else
	  yymsg(0, "Unknown option '%s' in field %i of type '%s'",
		(yyvsp[(6) - (11)].c), (int)(yyvsp[(3) - (11)].d), field->getName());
      }
      else
	yymsg(0, "No field with id %i", (int)(yyvsp[(3) - (11)].d));
#endif
      Free((yyvsp[(6) - (11)].c));
      List_Delete((yyvsp[(9) - (11)].l));
    ;}
    break;

  case 114:
#line 1236 "Gmsh.y"
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
#line 1257 "Gmsh.y"
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
#line 1269 "Gmsh.y"
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
#line 1287 "Gmsh.y"
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
#line 1296 "Gmsh.y"
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
#line 1305 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1307 "Gmsh.y"
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
#line 1325 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1327 "Gmsh.y"
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
#line 1343 "Gmsh.y"
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
#line 1352 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1354 "Gmsh.y"
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
#line 1368 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1376 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1382 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1387 "Gmsh.y"
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
#line 1430 "Gmsh.y"
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
#line 1442 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1446 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1450 "Gmsh.y"
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

  case 144:
#line 1463 "Gmsh.y"
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

  case 145:
#line 1477 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1485 "Gmsh.y"
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

  case 151:
#line 1510 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 152:
#line 1518 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 153:
#line 1527 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1535 "Gmsh.y"
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

  case 155:
#line 1549 "Gmsh.y"
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
#line 1567 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1571 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1578 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1586 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 160:
#line 1590 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 161:
#line 1596 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 162:
#line 1600 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 163:
#line 1611 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 164:
#line 1615 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 165:
#line 1621 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 166:
#line 1625 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 167:
#line 1631 "Gmsh.y"
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

  case 168:
#line 1654 "Gmsh.y"
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

  case 169:
#line 1670 "Gmsh.y"
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

  case 170:
#line 1686 "Gmsh.y"
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

  case 171:
#line 1703 "Gmsh.y"
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

  case 172:
#line 1720 "Gmsh.y"
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

  case 173:
#line 1757 "Gmsh.y"
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

  case 174:
#line 1801 "Gmsh.y"
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

  case 175:
#line 1817 "Gmsh.y"
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

  case 176:
#line 1834 "Gmsh.y"
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

  case 177:
#line 1865 "Gmsh.y"
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

  case 178:
#line 1881 "Gmsh.y"
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

  case 179:
#line 1898 "Gmsh.y"
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

  case 180:
#line 1914 "Gmsh.y"
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

  case 181:
#line 1964 "Gmsh.y"
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

  case 182:
#line 1982 "Gmsh.y"
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

  case 183:
#line 2003 "Gmsh.y"
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

  case 184:
#line 2024 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 185:
#line 2030 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2036 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2043 "Gmsh.y"
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

  case 188:
#line 2074 "Gmsh.y"
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

  case 189:
#line 2089 "Gmsh.y"
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

  case 190:
#line 2111 "Gmsh.y"
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

  case 191:
#line 2134 "Gmsh.y"
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

  case 192:
#line 2157 "Gmsh.y"
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

  case 193:
#line 2180 "Gmsh.y"
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

  case 194:
#line 2204 "Gmsh.y"
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

  case 195:
#line 2228 "Gmsh.y"
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

  case 196:
#line 2252 "Gmsh.y"
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

  case 197:
#line 2278 "Gmsh.y"
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

  case 198:
#line 2295 "Gmsh.y"
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

  case 199:
#line 2311 "Gmsh.y"
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

  case 200:
#line 2329 "Gmsh.y"
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

  case 201:
#line 2347 "Gmsh.y"
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

  case 202:
#line 2360 "Gmsh.y"
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

  case 203:
#line 2372 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 204:
#line 2376 "Gmsh.y"
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

  case 205:
#line 2402 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 206:
#line 2404 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 207:
#line 2406 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 208:
#line 2408 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 209:
#line 2410 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 210:
#line 2418 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 211:
#line 2420 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 212:
#line 2422 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 213:
#line 2424 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 214:
#line 2432 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 215:
#line 2434 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 216:
#line 2436 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 217:
#line 2444 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 218:
#line 2446 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 219:
#line 2448 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 220:
#line 2450 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if((yyval.i) < 0 || (yyval.i) > 2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 221:
#line 2460 "Gmsh.y"
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

  case 222:
#line 2476 "Gmsh.y"
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

  case 223:
#line 2492 "Gmsh.y"
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

  case 224:
#line 2508 "Gmsh.y"
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

  case 225:
#line 2524 "Gmsh.y"
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

  case 226:
#line 2540 "Gmsh.y"
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

  case 227:
#line 2557 "Gmsh.y"
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

  case 228:
#line 2594 "Gmsh.y"
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

  case 229:
#line 2615 "Gmsh.y"
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

  case 230:
#line 2636 "Gmsh.y"
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

  case 231:
#line 2661 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 232:
#line 2662 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 233:
#line 2667 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 234:
#line 2671 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 235:
#line 2675 "Gmsh.y"
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

  case 236:
#line 2692 "Gmsh.y"
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

  case 237:
#line 2712 "Gmsh.y"
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

  case 238:
#line 2732 "Gmsh.y"
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

  case 239:
#line 2751 "Gmsh.y"
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

  case 240:
#line 2778 "Gmsh.y"
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

  case 241:
#line 2797 "Gmsh.y"
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

  case 242:
#line 2819 "Gmsh.y"
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

  case 243:
#line 2834 "Gmsh.y"
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

  case 244:
#line 2849 "Gmsh.y"
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

  case 245:
#line 2868 "Gmsh.y"
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

  case 246:
#line 2919 "Gmsh.y"
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

  case 247:
#line 2940 "Gmsh.y"
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

  case 248:
#line 2962 "Gmsh.y"
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

  case 249:
#line 2984 "Gmsh.y"
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

  case 250:
#line 3089 "Gmsh.y"
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

  case 251:
#line 3105 "Gmsh.y"
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

  case 252:
#line 3140 "Gmsh.y"
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
        Msg::Debug("Destroying %lu entities in model", removed.size());
        for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3165 "Gmsh.y"
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
        Msg::Debug("Destroying %lu entities in model", removed.size());
        for(std::size_t i = 0; i < removed.size(); i++) delete removed[i];
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3190 "Gmsh.y"
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

  case 255:
#line 3202 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 256:
#line 3208 "Gmsh.y"
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

  case 257:
#line 3223 "Gmsh.y"
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

  case 258:
#line 3254 "Gmsh.y"
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

  case 259:
#line 3266 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 260:
#line 3275 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 261:
#line 3282 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 262:
#line 3294 "Gmsh.y"
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

  case 263:
#line 3314 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 264:
#line 3318 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 265:
#line 3323 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 266:
#line 3327 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 267:
#line 3332 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 268:
#line 3339 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 269:
#line 3346 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 270:
#line 3353 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 271:
#line 3365 "Gmsh.y"
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

  case 272:
#line 3438 "Gmsh.y"
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

  case 273:
#line 3456 "Gmsh.y"
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

  case 274:
#line 3481 "Gmsh.y"
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

  case 275:
#line 3496 "Gmsh.y"
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

  case 276:
#line 3545 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 277:
#line 3551 "Gmsh.y"
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

  case 278:
#line 3563 "Gmsh.y"
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

  case 279:
#line 3595 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 280:
#line 3599 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 281:
#line 3604 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 282:
#line 3611 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 283:
#line 3616 "Gmsh.y"
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

  case 284:
#line 3626 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 285:
#line 3631 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 286:
#line 3637 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 287:
#line 3645 "Gmsh.y"
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

  case 288:
#line 3656 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 289:
#line 3664 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 290:
#line 3668 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 291:
#line 3672 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 292:
#line 3676 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 293:
#line 3683 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 294:
#line 3687 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 295:
#line 3691 "Gmsh.y"
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

  case 296:
#line 3703 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 297:
#line 3713 "Gmsh.y"
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

  case 298:
#line 3771 "Gmsh.y"
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

  case 299:
#line 3791 "Gmsh.y"
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

  case 300:
#line 3817 "Gmsh.y"
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

  case 301:
#line 3833 "Gmsh.y"
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

  case 302:
#line 3850 "Gmsh.y"
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

  case 303:
#line 3867 "Gmsh.y"
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

  case 304:
#line 3889 "Gmsh.y"
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

  case 305:
#line 3911 "Gmsh.y"
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

  case 306:
#line 3946 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 307:
#line 3954 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 308:
#line 3962 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 309:
#line 3968 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 310:
#line 3975 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 311:
#line 3982 "Gmsh.y"
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

  case 312:
#line 4002 "Gmsh.y"
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

  case 313:
#line 4028 "Gmsh.y"
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

  case 314:
#line 4040 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 315:
#line 4051 "Gmsh.y"
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

  case 316:
#line 4069 "Gmsh.y"
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

  case 317:
#line 4087 "Gmsh.y"
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

  case 318:
#line 4105 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4111 "Gmsh.y"
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

  case 320:
#line 4129 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4135 "Gmsh.y"
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

  case 322:
#line 4155 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4161 "Gmsh.y"
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

  case 324:
#line 4179 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 325:
#line 4185 "Gmsh.y"
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

  case 326:
#line 4202 "Gmsh.y"
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

  case 327:
#line 4218 "Gmsh.y"
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

  case 328:
#line 4235 "Gmsh.y"
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

  case 329:
#line 4253 "Gmsh.y"
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

  case 330:
#line 4276 "Gmsh.y"
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

  case 331:
#line 4303 "Gmsh.y"
    {
    ;}
    break;

  case 332:
#line 4306 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 4312 "Gmsh.y"
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

  case 334:
#line 4324 "Gmsh.y"
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

  case 335:
#line 4344 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 336:
#line 4348 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 337:
#line 4352 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 338:
#line 4356 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 339:
#line 4360 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 340:
#line 4364 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 341:
#line 4368 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 342:
#line 4372 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 343:
#line 4381 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 344:
#line 4393 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 345:
#line 4394 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 346:
#line 4395 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 347:
#line 4396 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 348:
#line 4397 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 349:
#line 4401 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 350:
#line 4402 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 351:
#line 4403 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 352:
#line 4404 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 353:
#line 4405 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 354:
#line 4410 "Gmsh.y"
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

  case 355:
#line 4433 "Gmsh.y"
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

  case 356:
#line 4453 "Gmsh.y"
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

  case 357:
#line 4474 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 358:
#line 4478 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Progression") || !strcmp((yyvsp[(2) - (3)].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump"))
        (yyval.v)[0] = 2.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Beta"))
        (yyval.v)[0] = 3.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[(3) - (3)].d);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 359:
#line 4495 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 360:
#line 4499 "Gmsh.y"
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
#line 4515 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 362:
#line 4519 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 363:
#line 4524 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 364:
#line 4528 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 365:
#line 4534 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 366:
#line 4538 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 367:
#line 4545 "Gmsh.y"
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
#line 4568 "Gmsh.y"
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
#line 4587 "Gmsh.y"
    {
      // transfinite constraints are stored in GEO internals in addition to
      // GModel, as they can be copied around during GEO operations
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      int type = (int)(yyvsp[(6) - (7)].v)[0];
      double coef = fabs((yyvsp[(6) - (7)].v)[1]);
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
#line 4628 "Gmsh.y"
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

  case 371:
#line 4672 "Gmsh.y"
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

  case 372:
#line 4711 "Gmsh.y"
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

  case 373:
#line 4736 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 374:
#line 4743 "Gmsh.y"
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
#line 4754 "Gmsh.y"
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

  case 376:
#line 4771 "Gmsh.y"
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

  case 377:
#line 4788 "Gmsh.y"
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

  case 378:
#line 4818 "Gmsh.y"
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

  case 379:
#line 4844 "Gmsh.y"
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

  case 380:
#line 4871 "Gmsh.y"
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
#line 4903 "Gmsh.y"
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
#line 4931 "Gmsh.y"
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
#line 4957 "Gmsh.y"
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
#line 4983 "Gmsh.y"
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
#line 5009 "Gmsh.y"
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
#line 5035 "Gmsh.y"
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
#line 5056 "Gmsh.y"
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
#line 5068 "Gmsh.y"
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

  case 389:
#line 5116 "Gmsh.y"
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

  case 390:
#line 5170 "Gmsh.y"
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

  case 391:
#line 5185 "Gmsh.y"
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
#line 5197 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 393:
#line 5203 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 394:
#line 5215 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 395:
#line 5222 "Gmsh.y"
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
#line 5237 "Gmsh.y"
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
#line 5246 "Gmsh.y"
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

  case 398:
#line 5266 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 399:
#line 5267 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 400:
#line 5268 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 401:
#line 5273 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 402:
#line 5279 "Gmsh.y"
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

  case 403:
#line 5291 "Gmsh.y"
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

  case 404:
#line 5309 "Gmsh.y"
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

  case 405:
#line 5336 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 406:
#line 5337 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 407:
#line 5338 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 408:
#line 5339 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 409:
#line 5340 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 410:
#line 5341 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5342 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5345 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 414:
#line 5351 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 415:
#line 5352 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 416:
#line 5353 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 417:
#line 5354 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 418:
#line 5355 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5356 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 420:
#line 5357 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5358 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5359 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5360 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5361 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5362 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5363 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 427:
#line 5364 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 428:
#line 5365 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 429:
#line 5366 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5367 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5368 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 432:
#line 5369 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5370 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 434:
#line 5371 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5372 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 436:
#line 5373 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5374 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 438:
#line 5375 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5376 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 440:
#line 5377 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5378 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5379 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5380 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5381 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 445:
#line 5382 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 446:
#line 5383 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 447:
#line 5384 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 448:
#line 5385 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 449:
#line 5386 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 450:
#line 5387 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 451:
#line 5388 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 452:
#line 5389 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 453:
#line 5390 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 454:
#line 5399 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 455:
#line 5400 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 456:
#line 5401 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 457:
#line 5402 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 458:
#line 5403 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 459:
#line 5404 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 460:
#line 5405 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 461:
#line 5406 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 462:
#line 5407 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 463:
#line 5408 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 464:
#line 5409 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 465:
#line 5414 "Gmsh.y"
    { init_options(); ;}
    break;

  case 466:
#line 5416 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 467:
#line 5422 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 468:
#line 5426 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 469:
#line 5431 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 470:
#line 5436 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 471:
#line 5441 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 472:
#line 5446 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 473:
#line 5450 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 474:
#line 5454 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 475:
#line 5458 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 476:
#line 5462 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 477:
#line 5466 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 478:
#line 5470 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 479:
#line 5474 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 480:
#line 5480 "Gmsh.y"
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

  case 481:
#line 5495 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 482:
#line 5499 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 483:
#line 5505 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 484:
#line 5510 "Gmsh.y"
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

  case 485:
#line 5529 "Gmsh.y"
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

  case 486:
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

  case 487:
#line 5570 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 488:
#line 5574 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 489:
#line 5578 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 490:
#line 5582 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 491:
#line 5586 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 492:
#line 5590 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 493:
#line 5594 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 494:
#line 5599 "Gmsh.y"
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

  case 495:
#line 5609 "Gmsh.y"
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

  case 496:
#line 5619 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 497:
#line 5624 "Gmsh.y"
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

  case 498:
#line 5635 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 499:
#line 5644 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 500:
#line 5649 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 501:
#line 5654 "Gmsh.y"
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

  case 502:
#line 5681 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 503:
#line 5683 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 504:
#line 5688 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 505:
#line 5690 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 506:
#line 5695 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 507:
#line 5702 "Gmsh.y"
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

  case 508:
#line 5718 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 509:
#line 5720 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 510:
#line 5725 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 511:
#line 5727 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 512:
#line 5732 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 513:
#line 5734 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 514:
#line 5739 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 515:
#line 5743 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 516:
#line 5747 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 517:
#line 5751 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 518:
#line 5755 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 519:
#line 5762 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 520:
#line 5766 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 521:
#line 5770 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 522:
#line 5774 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 523:
#line 5781 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 524:
#line 5786 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 525:
#line 5793 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 526:
#line 5798 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 527:
#line 5802 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 528:
#line 5807 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 529:
#line 5811 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 530:
#line 5819 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 531:
#line 5830 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 532:
#line 5834 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 533:
#line 5838 "Gmsh.y"
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
#line 5852 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 535:
#line 5860 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 536:
#line 5868 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 537:
#line 5875 "Gmsh.y"
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
#line 5885 "Gmsh.y"
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
#line 5908 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 540:
#line 5913 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 541:
#line 5919 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 542:
#line 5924 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 543:
#line 5930 "Gmsh.y"
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
#line 5941 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 545:
#line 5947 "Gmsh.y"
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

  case 546:
#line 5961 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 547:
#line 5967 "Gmsh.y"
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

  case 548:
#line 5979 "Gmsh.y"
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

  case 549:
#line 5993 "Gmsh.y"
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

  case 550:
#line 6006 "Gmsh.y"
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

  case 551:
#line 6023 "Gmsh.y"
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

  case 552:
#line 6033 "Gmsh.y"
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
#line 6043 "Gmsh.y"
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
#line 6053 "Gmsh.y"
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

  case 555:
#line 6065 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 556:
#line 6069 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 557:
#line 6074 "Gmsh.y"
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

  case 558:
#line 6086 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 559:
#line 6090 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 560:
#line 6094 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 561:
#line 6098 "Gmsh.y"
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

  case 562:
#line 6116 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 563:
#line 6124 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 564:
#line 6132 "Gmsh.y"
    {
      Msg::Barrier();
      FILE *File;
      (yyval.l) = List_Create(100, 100, sizeof(double));
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      if(!(File = Fopen(tmp.c_str(), "rb"))){
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
            char dummy[1024];
            if(fscanf(File, "%s", dummy))
              yymsg(0, "Ignoring '%s' in file '%s'", dummy, (yyvsp[(3) - (4)].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 565:
#line 6161 "Gmsh.y"
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

  case 566:
#line 6171 "Gmsh.y"
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

  case 567:
#line 6187 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 568:
#line 6198 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 569:
#line 6203 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 570:
#line 6207 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 571:
#line 6211 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 572:
#line 6223 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 573:
#line 6227 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 574:
#line 6239 "Gmsh.y"
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

  case 575:
#line 6256 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 576:
#line 6266 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 577:
#line 6270 "Gmsh.y"
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

  case 578:
#line 6285 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 579:
#line 6290 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 580:
#line 6297 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 581:
#line 6301 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 582:
#line 6306 "Gmsh.y"
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

  case 583:
#line 6320 "Gmsh.y"
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
#line 6334 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 585:
#line 6338 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 586:
#line 6342 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 587:
#line 6346 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 588:
#line 6350 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 589:
#line 6358 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 590:
#line 6364 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 591:
#line 6373 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 592:
#line 6377 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 593:
#line 6381 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 594:
#line 6389 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 595:
#line 6395 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 596:
#line 6401 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 597:
#line 6405 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 598:
#line 6412 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 599:
#line 6420 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 600:
#line 6427 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 601:
#line 6436 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 602:
#line 6440 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 603:
#line 6444 "Gmsh.y"
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

  case 604:
#line 6459 "Gmsh.y"
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

  case 605:
#line 6473 "Gmsh.y"
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
	strcpy((yyval.c), &(yyvsp[(3) - (4)].c)[i+1]);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 606:
#line 6487 "Gmsh.y"
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

  case 607:
#line 6499 "Gmsh.y"
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

  case 608:
#line 6515 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 609:
#line 6524 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 610:
#line 6533 "Gmsh.y"
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

  case 611:
#line 6543 "Gmsh.y"
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

  case 612:
#line 6554 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 613:
#line 6562 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 614:
#line 6570 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 615:
#line 6574 "Gmsh.y"
    {
      char tmpstring[5000];
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
	(yyval.c) = (char*)Malloc((strlen(tmpstring) + 1) * sizeof(char));
	strcpy((yyval.c), tmpstring);
	Free((yyvsp[(3) - (6)].c));
      }
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 616:
#line 6593 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 617:
#line 6600 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 618:
#line 6606 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 619:
#line 6612 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 620:
#line 6619 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 621:
#line 6626 "Gmsh.y"
    { init_options(); ;}
    break;

  case 622:
#line 6628 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 623:
#line 6636 "Gmsh.y"
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

  case 624:
#line 6660 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 625:
#line 6662 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 626:
#line 6668 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 627:
#line 6673 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 628:
#line 6675 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 629:
#line 6680 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 630:
#line 6685 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 631:
#line 6690 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 632:
#line 6692 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 633:
#line 6696 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 634:
#line 6708 "Gmsh.y"
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

  case 635:
#line 6722 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 636:
#line 6726 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 637:
#line 6733 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 638:
#line 6741 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 639:
#line 6749 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 640:
#line 6760 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 641:
#line 6762 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 642:
#line 6765 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15039 "Gmsh.tab.cpp"
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


#line 6768 "Gmsh.y"


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

int printListOfDouble(char *format, List_T *list, char *buffer)
{
  // if format does not contain formatting characters, dump the list (useful for
  // quick debugging of lists)
  int numFormats = 0;
  for(std::size_t i = 0; i < strlen(format); i++)
    if(format[i] == '%') numFormats++;
  if(!numFormats){
    strcpy(buffer, format);
    for(int i = 0; i < List_Nbr(list); i++){
      double d;
      List_Read(list, i, &d);
      char tmp[256];
      sprintf(tmp, " [%d]%g", i, d);
      strcat(buffer, tmp);
    }
    return 0;
  }

  char tmp1[256], tmp2[256];
  int j = 0, k = 0;
  buffer[j] = '\0';

  while(j < (int)strlen(format) && format[j] != '%') j++;
  strncpy(buffer, format, j);
  buffer[j] = '\0';
  for(int i = 0; i < List_Nbr(list); i++){
    k = j;
    j++;
    if(j < (int)strlen(format)){
      if(format[j] == '%'){
	strcat(buffer, "%");
	j++;
      }
      while(j < (int)strlen(format) && format[j] != '%') j++;
      if(k != j){
	strncpy(tmp1, &(format[k]), j-k);
	tmp1[j-k] = '\0';
	sprintf(tmp2, tmp1, *(double*)List_Pointer(list, i));
	strcat(buffer, tmp2);
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

  tfo[0*4+0] = ca + ux * ux * (1. - ca);
  tfo[0*4+1] = ux * uy * (1. - ca) - uz * sa;
  tfo[0*4+2] = ux * uz * (1. - ca) + uy * sa;

  tfo[1*4+0] = ux * uy * (1. - ca) + uz * sa;
  tfo[1*4+1] = ca + uy * uy * (1. - ca);
  tfo[1*4+2] = uy * uz * (1. - ca) - ux * sa;

  tfo[2*4+0] = ux * uz * (1. - ca) - uy * sa;
  tfo[2*4+1] = uy * uz * (1. - ca) + ux * sa;
  tfo[2*4+2] = ca + uz * uz * (1. - ca);

  int idx = 0;
  for(size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i * 4 + 3;
    tfo[tIdx] = origin[i] + translation[i];
    for(int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for(int i = 0; i < 4; i++) tfo[12+i] = 0;
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

