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

// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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
#define YYLAST   18117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  270
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2298

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
    1557,  1561,  1564,  1567,  1570,  1573,  1589,  1592,  1595,  1603,
    1606,  1616,  1628,  1631,  1636,  1639,  1642,  1645,  1648,  1665,
    1671,  1680,  1692,  1699,  1708,  1717,  1728,  1730,  1733,  1736,
    1738,  1742,  1746,  1751,  1756,  1758,  1760,  1766,  1778,  1792,
    1793,  1801,  1802,  1816,  1817,  1833,  1834,  1841,  1851,  1854,
    1858,  1869,  1883,  1885,  1888,  1894,  1902,  1905,  1908,  1912,
    1915,  1919,  1922,  1926,  1936,  1943,  1945,  1947,  1949,  1951,
    1953,  1954,  1957,  1961,  1965,  1970,  1980,  1985,  2000,  2001,
    2005,  2006,  2008,  2009,  2012,  2013,  2016,  2017,  2020,  2026,
    2033,  2041,  2048,  2054,  2058,  2067,  2074,  2083,  2092,  2098,
    2103,  2110,  2122,  2134,  2153,  2172,  2185,  2198,  2211,  2222,
    2227,  2232,  2237,  2242,  2247,  2254,  2257,  2261,  2268,  2271,
    2273,  2275,  2277,  2280,  2286,  2294,  2305,  2307,  2311,  2314,
    2317,  2320,  2324,  2328,  2332,  2336,  2340,  2344,  2348,  2352,
    2356,  2360,  2364,  2368,  2372,  2376,  2380,  2384,  2388,  2392,
    2398,  2403,  2408,  2413,  2418,  2423,  2428,  2433,  2438,  2443,
    2448,  2455,  2460,  2465,  2470,  2475,  2480,  2485,  2490,  2495,
    2502,  2509,  2516,  2521,  2528,  2535,  2537,  2539,  2541,  2543,
    2545,  2547,  2549,  2551,  2553,  2555,  2557,  2558,  2565,  2567,
    2572,  2579,  2581,  2586,  2591,  2596,  2603,  2609,  2617,  2626,
    2637,  2642,  2647,  2654,  2659,  2663,  2666,  2672,  2678,  2682,
    2688,  2695,  2704,  2711,  2720,  2727,  2732,  2740,  2747,  2754,
    2761,  2766,  2773,  2778,  2779,  2782,  2783,  2786,  2787,  2795,
    2797,  2801,  2803,  2806,  2807,  2811,  2813,  2816,  2819,  2823,
    2827,  2839,  2849,  2857,  2865,  2867,  2871,  2873,  2875,  2878,
    2882,  2887,  2893,  2895,  2899,  2901,  2904,  2908,  2912,  2918,
    2923,  2928,  2931,  2936,  2939,  2943,  2947,  2952,  2958,  2964,
    2970,  2976,  2982,  2984,  2986,  2988,  2992,  2998,  3006,  3011,
    3016,  3021,  3028,  3035,  3044,  3053,  3058,  3073,  3078,  3083,
    3085,  3087,  3091,  3095,  3105,  3113,  3115,  3121,  3125,  3132,
    3134,  3138,  3140,  3142,  3147,  3152,  3156,  3162,  3169,  3178,
    3185,  3190,  3196,  3198,  3203,  3205,  3207,  3209,  3211,  3216,
    3223,  3228,  3235,  3241,  3249,  3254,  3259,  3264,  3273,  3278,
    3283,  3288,  3293,  3302,  3311,  3318,  3323,  3330,  3335,  3337,
    3339,  3344,  3349,  3350,  3357,  3362,  3365,  3370,  3375,  3377,
    3379,  3383,  3385,  3387,  3391,  3395,  3399,  3405,  3413,  3419,
    3425,  3434,  3436,  3438
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
     187,     4,     6,    -1,   202,     6,    -1,   202,   353,     6,
      -1,   203,     6,    -1,    74,     6,    -1,    75,     6,    -1,
      67,     6,    -1,    67,   264,   353,   269,   353,   269,   353,
     269,   353,   269,   353,   269,   353,   265,     6,    -1,    68,
       6,    -1,    69,     6,    -1,    85,   264,   353,   269,   353,
     265,     6,    -1,    85,     6,    -1,    87,   264,   353,   269,
     353,   269,   353,   265,     6,    -1,    87,   264,   353,   269,
     353,   269,   353,   269,   353,   265,     6,    -1,    86,     6,
      -1,    86,   264,   324,   265,    -1,    88,     6,    -1,    89,
       6,    -1,   126,     6,    -1,   127,     6,    -1,   128,   264,
     369,   265,   264,   369,   265,   264,   365,   265,   264,   353,
     269,   353,   265,     6,    -1,   129,   264,   369,   265,     6,
      -1,   129,   264,   369,   265,   264,   323,   265,     6,    -1,
     207,   260,   264,   369,   265,   269,   374,   269,   374,   261,
       6,    -1,   195,   260,   353,     8,   353,   261,    -1,   195,
     260,   353,     8,   353,     8,   353,   261,    -1,   195,     4,
     196,   264,   353,     8,   353,   265,    -1,   195,     4,   196,
     264,   353,     8,   353,     8,   353,   265,    -1,   197,    -1,
     208,     4,    -1,   208,   374,    -1,   205,    -1,   206,   383,
       6,    -1,   206,   374,     6,    -1,   198,   260,   353,   261,
      -1,   199,   260,   353,   261,    -1,   200,    -1,   201,    -1,
     153,   363,   264,   324,   265,    -1,   153,   264,   363,   269,
     363,   269,   353,   265,   264,   324,   265,    -1,   153,   264,
     363,   269,   363,   269,   363,   269,   353,   265,   264,   324,
     265,    -1,    -1,   153,   363,   264,   324,   334,   338,   265,
      -1,    -1,   153,   264,   363,   269,   363,   269,   353,   265,
     264,   324,   335,   338,   265,    -1,    -1,   153,   264,   363,
     269,   363,   269,   363,   269,   353,   265,   264,   324,   336,
     338,   265,    -1,    -1,   153,   264,   324,   337,   338,   265,
      -1,   153,   264,   324,   265,   144,   120,   264,   353,   265,
      -1,   133,   366,    -1,   138,   133,   366,    -1,   135,   264,
     369,   265,   264,   369,   265,   264,   369,   265,    -1,   136,
     264,   369,   265,   264,   369,   265,   264,   369,   265,   264,
     369,   265,    -1,   339,    -1,   338,   339,    -1,   173,   264,
     353,   265,     6,    -1,   173,   264,   366,   269,   366,   265,
       6,    -1,   174,     6,    -1,   162,     6,    -1,   162,   353,
       6,    -1,   179,     6,    -1,   179,   181,     6,    -1,   180,
       6,    -1,   180,   181,     6,    -1,   175,   260,   353,   261,
       7,   366,   144,   353,     6,    -1,   144,     4,   262,   353,
     263,     6,    -1,   156,    -1,   157,    -1,   158,    -1,   159,
      -1,   160,    -1,    -1,   165,     6,    -1,   147,   165,     6,
      -1,   165,   353,     6,    -1,   147,   165,   353,     6,    -1,
     340,   264,   324,   341,   265,   264,   324,   341,   265,    -1,
     117,   260,   373,   261,    -1,   340,   260,   353,   261,     7,
     264,   324,   341,   265,   264,   324,   341,   265,     6,    -1,
      -1,   144,     4,   353,    -1,    -1,     4,    -1,    -1,     7,
     366,    -1,    -1,     7,   353,    -1,    -1,   155,   366,    -1,
     171,   367,     7,   353,     6,    -1,   122,   123,   367,     7,
     353,     6,    -1,   139,   105,   367,     7,   353,   344,     6,
      -1,   139,   108,   367,   346,   345,     6,    -1,   139,   110,
     367,   346,     6,    -1,   182,   367,     6,    -1,   100,   318,
     260,   353,   269,   353,   261,     6,    -1,   217,   318,   260,
     353,   261,     6,    -1,   169,   108,   264,   369,   265,     7,
     353,     6,    -1,   172,   108,   264,   369,   265,     7,   353,
       6,    -1,   162,   108,   367,   347,     6,    -1,   162,   110,
     367,     6,    -1,   163,   108,   367,     7,   353,     6,    -1,
     142,   105,   264,   369,   265,     7,   264,   369,   265,   348,
       6,    -1,   142,   108,   264,   369,   265,     7,   264,   369,
     265,   348,     6,    -1,   142,   105,   264,   369,   265,     7,
     264,   369,   265,   149,   264,   363,   269,   363,   269,   353,
     265,     6,    -1,   142,   108,   264,   369,   265,     7,   264,
     369,   265,   149,   264,   363,   269,   363,   269,   353,   265,
       6,    -1,   142,   105,   264,   369,   265,     7,   264,   369,
     265,   150,   363,     6,    -1,   142,   108,   264,   369,   265,
       7,   264,   369,   265,   150,   363,     6,    -1,   142,   108,
     353,   264,   369,   265,     7,   353,   264,   369,   265,     6,
      -1,   318,   264,   369,   265,   196,   318,   264,   353,   265,
       6,    -1,   170,   320,   367,     6,    -1,   130,   321,   367,
       6,    -1,   131,   110,   366,     6,    -1,   146,   105,   366,
       6,    -1,   141,   319,   366,     6,    -1,   141,   319,   366,
     169,   353,     6,    -1,   166,     6,    -1,   166,     4,     6,
      -1,   166,   102,   264,   369,   265,     6,    -1,   167,     6,
      -1,   218,    -1,   219,    -1,   220,    -1,   351,     6,    -1,
     351,   264,   366,   265,     6,    -1,   351,   264,   366,   269,
     366,   265,     6,    -1,   351,   260,   366,   261,   264,   366,
     269,   366,   265,     6,    -1,   354,    -1,   260,   353,   261,
      -1,   249,   353,    -1,   248,   353,    -1,   255,   353,    -1,
     353,   249,   353,    -1,   353,   248,   353,    -1,   353,   250,
     353,    -1,   353,   251,   353,    -1,   353,   253,   353,    -1,
     353,   254,   353,    -1,   353,   252,   353,    -1,   353,   259,
     353,    -1,   353,   242,   353,    -1,   353,   243,   353,    -1,
     353,   247,   353,    -1,   353,   246,   353,    -1,   353,   241,
     353,    -1,   353,   240,   353,    -1,   353,   239,   353,    -1,
     353,   238,   353,    -1,   353,   244,   353,    -1,   353,   245,
     353,    -1,   353,   237,   353,     8,   353,    -1,    16,   294,
     353,   295,    -1,    17,   294,   353,   295,    -1,    18,   294,
     353,   295,    -1,    19,   294,   353,   295,    -1,    20,   294,
     353,   295,    -1,    21,   294,   353,   295,    -1,    22,   294,
     353,   295,    -1,    23,   294,   353,   295,    -1,    24,   294,
     353,   295,    -1,    26,   294,   353,   295,    -1,    27,   294,
     353,   269,   353,   295,    -1,    28,   294,   353,   295,    -1,
      29,   294,   353,   295,    -1,    30,   294,   353,   295,    -1,
      31,   294,   353,   295,    -1,    32,   294,   353,   295,    -1,
      33,   294,   353,   295,    -1,    34,   294,   353,   295,    -1,
      35,   294,   353,   295,    -1,    38,   294,   353,   269,   353,
     295,    -1,    39,   294,   353,   269,   353,   295,    -1,    40,
     294,   353,   269,   353,   295,    -1,    25,   294,   353,   295,
      -1,    37,   294,   353,   269,   353,   295,    -1,    36,   294,
     353,   269,   353,   295,    -1,     3,    -1,    10,    -1,    15,
      -1,    11,    -1,    12,    -1,   225,    -1,   226,    -1,   227,
      -1,    82,    -1,    83,    -1,    84,    -1,    -1,    93,   294,
     353,   355,   305,   295,    -1,   358,    -1,   215,   294,   373,
     295,    -1,   215,   294,   373,   269,   353,   295,    -1,   360,
      -1,   383,   262,   353,   263,    -1,   383,   260,   353,   261,
      -1,   221,   260,   360,   261,    -1,   221,   260,   360,   266,
     296,   261,    -1,   223,   260,   360,   356,   261,    -1,   223,
     260,   360,   266,   296,   356,   261,    -1,   223,   260,   360,
     294,   353,   295,   356,   261,    -1,   223,   260,   360,   266,
     296,   294,   353,   295,   356,   261,    -1,   222,   260,   374,
     261,    -1,   267,   383,   294,   295,    -1,   267,   360,   266,
     296,   294,   295,    -1,    96,   294,   383,   295,    -1,    96,
     294,   295,    -1,   383,   293,    -1,   383,   262,   353,   263,
     293,    -1,   383,   260,   353,   261,   293,    -1,   383,   266,
     296,    -1,   383,     9,   383,   266,   296,    -1,   383,   266,
     296,   260,   353,   261,    -1,   383,     9,   383,   266,   296,
     260,   353,   261,    -1,   383,   266,   296,   262,   353,   263,
      -1,   383,     9,   383,   266,   296,   262,   353,   263,    -1,
     383,   262,   353,   263,   266,   296,    -1,   383,   266,   296,
     293,    -1,   383,   262,   353,   263,   266,   296,   293,    -1,
     211,   260,   373,   269,   353,   261,    -1,    59,   260,   366,
     269,   366,   261,    -1,    60,   294,   373,   269,   373,   295,
      -1,    58,   294,   373,   295,    -1,    61,   294,   373,   269,
     373,   295,    -1,    66,   260,   380,   261,    -1,    -1,   269,
     353,    -1,    -1,   269,   373,    -1,    -1,    94,   360,   362,
     359,   262,   306,   263,    -1,   383,    -1,   383,     9,   383,
      -1,    97,    -1,    97,   353,    -1,    -1,   260,   361,   261,
      -1,   364,    -1,   249,   363,    -1,   248,   363,    -1,   363,
     249,   363,    -1,   363,   248,   363,    -1,   264,   353,   269,
     353,   269,   353,   269,   353,   269,   353,   265,    -1,   264,
     353,   269,   353,   269,   353,   269,   353,   265,    -1,   264,
     353,   269,   353,   269,   353,   265,    -1,   260,   353,   269,
     353,   269,   353,   261,    -1,   366,    -1,   365,   269,   366,
      -1,   353,    -1,   368,    -1,   264,   265,    -1,   264,   369,
     265,    -1,   249,   264,   369,   265,    -1,   353,   250,   264,
     369,   265,    -1,   366,    -1,   264,     8,   265,    -1,     5,
      -1,   249,   368,    -1,   353,   250,   368,    -1,   353,     8,
     353,    -1,   353,     8,   353,     8,   353,    -1,   102,   264,
     353,   265,    -1,   102,   264,     8,   265,    -1,   102,     5,
      -1,   319,   264,     8,   265,    -1,   319,     5,    -1,   140,
     318,   367,    -1,   143,   318,   366,    -1,   318,   196,    67,
     366,    -1,    67,   318,   264,   369,   265,    -1,    76,   319,
     264,   353,   265,    -1,    77,   319,   264,   353,   265,    -1,
      78,   319,   264,   353,   265,    -1,   193,   319,   264,   353,
     265,    -1,   322,    -1,   333,    -1,   342,    -1,   383,   294,
     295,    -1,   383,   266,   296,   294,   295,    -1,   383,     9,
     383,   266,   296,   294,   295,    -1,    41,   262,   383,   263,
      -1,    41,   262,   368,   263,    -1,    41,   260,   368,   261,
      -1,    41,   294,   264,   369,   265,   295,    -1,   383,   294,
     264,   369,   265,   295,    -1,    42,   294,   353,   269,   353,
     269,   353,   295,    -1,    43,   294,   353,   269,   353,   269,
     353,   295,    -1,    44,   294,   373,   295,    -1,    45,   294,
     353,   269,   353,   269,   353,   269,   353,   269,   353,   269,
     353,   295,    -1,   216,   294,   368,   295,    -1,    32,   294,
     368,   295,    -1,   353,    -1,   368,    -1,   369,   269,   353,
      -1,   369,   269,   368,    -1,   264,   353,   269,   353,   269,
     353,   269,   353,   265,    -1,   264,   353,   269,   353,   269,
     353,   265,    -1,   383,    -1,     4,   266,   193,   266,     4,
      -1,   264,   372,   265,    -1,   383,   262,   353,   263,   266,
     194,    -1,   370,    -1,   372,   269,   370,    -1,   374,    -1,
     383,    -1,   383,   262,   353,   263,    -1,   383,   260,   353,
     261,    -1,   383,   266,   296,    -1,   383,     9,   383,   266,
     296,    -1,   383,   266,   296,   260,   353,   261,    -1,   383,
       9,   383,   266,   296,   260,   353,   261,    -1,   383,   262,
     353,   263,   266,     4,    -1,   318,   264,   353,   265,    -1,
     140,   318,   264,   353,   265,    -1,     5,    -1,   230,   262,
     383,   263,    -1,    70,    -1,   228,    -1,    79,    -1,    81,
      -1,   213,   260,   373,   261,    -1,   212,   260,   373,   269,
     373,   261,    -1,   214,   294,   373,   295,    -1,   214,   294,
     373,   269,   373,   295,    -1,   224,   260,   360,   357,   261,
      -1,   224,   260,   360,   266,   296,   357,   261,    -1,    51,
     294,   380,   295,    -1,    52,   260,   373,   261,    -1,    53,
     260,   373,   261,    -1,    54,   260,   373,   269,   373,   269,
     373,   261,    -1,    49,   294,   380,   295,    -1,    63,   294,
     373,   295,    -1,    64,   294,   373,   295,    -1,    65,   294,
     373,   295,    -1,    62,   294,   353,   269,   373,   269,   373,
     295,    -1,    57,   294,   373,   269,   353,   269,   353,   295,
      -1,    57,   294,   373,   269,   353,   295,    -1,    50,   294,
     373,   295,    -1,    50,   294,   373,   269,   369,   295,    -1,
      71,   294,   373,   295,    -1,    72,    -1,    73,    -1,    56,
     294,   373,   295,    -1,    55,   294,   373,   295,    -1,    -1,
      98,   294,   374,   375,   309,   295,    -1,    95,   294,   376,
     295,    -1,   267,   353,    -1,   383,     9,   267,   353,    -1,
      49,   294,   379,   295,    -1,   380,    -1,   379,    -1,   264,
     380,   265,    -1,   373,    -1,   381,    -1,   380,   269,   373,
      -1,   380,   269,   381,    -1,   383,   260,   261,    -1,   383,
     266,   296,   260,   261,    -1,   383,     9,   383,   266,   296,
     260,   261,    -1,     4,   268,   264,   353,   265,    -1,   382,
     268,   264,   353,   265,    -1,   231,   262,   373,   263,   268,
     264,   353,   265,    -1,     4,    -1,   382,    -1,   231,   262,
     373,   263,    -1
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
    3598,  3602,  3607,  3614,  3619,  3629,  3634,  3640,  3648,  3659,
    3667,  3671,  3675,  3679,  3686,  3690,  3694,  3706,  3715,  3774,
    3794,  3820,  3836,  3853,  3870,  3892,  3914,  3949,  3957,  3965,
    3971,  3978,  3985,  4005,  4031,  4043,  4054,  4072,  4090,  4109,
    4108,  4133,  4132,  4159,  4158,  4183,  4182,  4205,  4221,  4238,
    4255,  4278,  4306,  4309,  4315,  4327,  4347,  4351,  4355,  4359,
    4363,  4367,  4371,  4375,  4384,  4397,  4398,  4399,  4400,  4401,
    4405,  4406,  4407,  4408,  4409,  4412,  4436,  4455,  4478,  4481,
    4499,  4502,  4519,  4522,  4528,  4531,  4538,  4541,  4548,  4571,
    4590,  4631,  4675,  4714,  4739,  4746,  4757,  4774,  4791,  4821,
    4847,  4873,  4905,  4933,  4959,  4985,  5011,  5037,  5059,  5071,
    5119,  5173,  5188,  5200,  5206,  5218,  5225,  5240,  5249,  5270,
    5271,  5272,  5276,  5282,  5294,  5312,  5340,  5341,  5342,  5343,
    5344,  5345,  5346,  5347,  5348,  5355,  5356,  5357,  5358,  5359,
    5360,  5361,  5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,
    5370,  5371,  5372,  5373,  5374,  5375,  5376,  5377,  5378,  5379,
    5380,  5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,  5389,
    5390,  5391,  5392,  5393,  5394,  5403,  5404,  5405,  5406,  5407,
    5408,  5409,  5410,  5411,  5412,  5413,  5418,  5417,  5425,  5429,
    5434,  5439,  5443,  5448,  5453,  5457,  5461,  5465,  5469,  5473,
    5477,  5483,  5498,  5502,  5508,  5513,  5532,  5552,  5573,  5577,
    5581,  5585,  5589,  5593,  5597,  5602,  5612,  5622,  5627,  5638,
    5647,  5652,  5657,  5685,  5686,  5692,  5693,  5699,  5698,  5721,
    5723,  5728,  5730,  5736,  5737,  5742,  5746,  5750,  5754,  5758,
    5765,  5769,  5773,  5777,  5784,  5789,  5796,  5801,  5805,  5810,
    5814,  5822,  5833,  5837,  5841,  5855,  5863,  5871,  5878,  5888,
    5911,  5916,  5922,  5927,  5933,  5944,  5950,  5964,  5970,  5982,
    5996,  6009,  6026,  6036,  6046,  6056,  6068,  6072,  6077,  6089,
    6093,  6097,  6101,  6119,  6127,  6135,  6164,  6174,  6190,  6201,
    6206,  6210,  6214,  6226,  6230,  6242,  6259,  6269,  6273,  6288,
    6293,  6300,  6304,  6309,  6323,  6337,  6341,  6345,  6349,  6353,
    6361,  6367,  6376,  6380,  6384,  6392,  6398,  6404,  6408,  6415,
    6423,  6430,  6439,  6443,  6447,  6462,  6476,  6490,  6502,  6518,
    6527,  6536,  6546,  6557,  6565,  6573,  6577,  6595,  6602,  6608,
    6614,  6621,  6629,  6628,  6638,  6662,  6664,  6670,  6675,  6677,
    6682,  6687,  6692,  6694,  6698,  6710,  6724,  6728,  6735,  6743,
    6751,  6762,  6764,  6767
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
     330,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   333,   333,   333,   334,
     333,   335,   333,   336,   333,   337,   333,   333,   333,   333,
     333,   333,   338,   338,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   340,   340,   340,   340,   340,
     341,   341,   341,   341,   341,   342,   342,   343,   344,   344,
     345,   345,   346,   346,   347,   347,   348,   348,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   350,   350,   350,   350,   351,
     351,   351,   352,   352,   352,   352,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   355,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   356,   356,   357,   357,   359,   358,   360,
     360,   361,   361,   362,   362,   363,   363,   363,   363,   363,
     364,   364,   364,   364,   365,   365,   366,   366,   366,   366,
     366,   366,   367,   367,   367,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   369,
     369,   369,   369,   370,   370,   370,   370,   371,   371,   372,
     372,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   375,   374,   374,   376,   376,   377,   378,   378,
     379,   380,   380,   380,   380,   381,   381,   381,   382,   382,
     382,   383,   383,   383
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
       3,     2,     2,     2,     2,    15,     2,     2,     7,     2,
       9,    11,     2,     4,     2,     2,     2,     2,    16,     5,
       8,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     9,     2,     3,
      10,    13,     1,     2,     5,     7,     2,     2,     3,     2,
       3,     2,     3,     9,     6,     1,     1,     1,     1,     1,
       0,     2,     3,     3,     4,     9,     4,    14,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     5,     6,
       7,     6,     5,     3,     8,     6,     8,     8,     5,     4,
       6,    11,    11,    18,    18,    12,    12,    12,    10,     4,
       4,     4,     4,     4,     6,     2,     3,     6,     2,     1,
       1,     1,     2,     5,     7,    10,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     6,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     1,     4,
       6,     1,     4,     4,     4,     6,     5,     7,     8,    10,
       4,     4,     6,     4,     3,     2,     5,     5,     3,     5,
       6,     8,     6,     8,     6,     4,     7,     6,     6,     6,
       4,     6,     4,     0,     2,     0,     2,     0,     7,     1,
       3,     1,     2,     0,     3,     1,     2,     2,     3,     3,
      11,     9,     7,     7,     1,     3,     1,     1,     2,     3,
       4,     5,     1,     3,     1,     2,     3,     3,     5,     4,
       4,     2,     4,     2,     3,     3,     4,     5,     5,     5,
       5,     5,     1,     1,     1,     3,     5,     7,     4,     4,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,     0,     0,   207,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   345,   346,   347,   348,
     349,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,   314,   315,     0,     0,
       0,   309,     0,     0,     0,     0,     0,     0,   399,   400,
     401,     0,     0,     0,     5,     6,     7,     8,    10,     0,
      11,    24,    12,    13,    14,    15,    23,    22,    21,    16,
       0,    17,    18,    19,    20,     0,    25,     0,   642,     0,
     233,     0,     0,     0,     0,     0,     0,   284,     0,   286,
     287,   282,   283,     0,   289,     0,   292,   233,     0,   294,
     295,   119,   129,   641,   513,   509,    73,    74,     0,   205,
     206,   207,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   297,     0,
       0,   217,   218,   219,     0,     0,     0,     0,   455,   456,
     458,   459,   457,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,   464,   465,     0,     0,   205,   210,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,   461,   462,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,     0,   554,   526,   406,
     468,   471,   328,   527,   509,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   210,   211,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   515,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   641,     0,     0,   233,     0,
       0,   395,     0,   398,     0,     0,   214,   215,     0,     0,
     534,     0,     0,   532,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   641,     0,     0,   575,
       0,     0,     0,     0,   279,     0,     0,     0,   509,   281,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,     0,   618,   619,   596,
     597,     0,     0,     0,     0,     0,     0,   595,     0,     0,
       0,     0,   307,   308,     0,   233,     0,   233,     0,     0,
       0,   276,     0,     0,   233,   402,     0,     0,    84,     0,
      66,     0,     0,    70,    69,    68,    67,    72,    71,    73,
      74,     0,     0,     0,     0,     0,     0,     0,   581,   509,
       0,   232,     0,   231,     0,   184,     0,     0,   581,   582,
       0,     0,     0,   631,     0,   632,   582,     0,     0,     0,
     117,   117,     0,   507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   569,   570,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   541,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   409,     0,   408,   535,   410,
       0,   528,     0,     0,   509,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,   485,     0,     0,     0,     0,     0,     0,     0,
     329,     0,   362,   362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,   233,   233,     0,
     517,   516,     0,     0,     0,     0,   233,   233,     0,     0,
       0,     0,   325,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,     0,     0,     0,
       0,     0,     0,   233,   259,     0,     0,   257,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   373,   278,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,   408,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   311,   310,     0,   264,     0,
       0,   266,     0,     0,     0,   233,     0,     0,     0,   350,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,     0,     0,     0,     0,    88,    75,    76,
       0,     0,     0,   275,    40,   271,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,     0,   234,     0,     0,
     185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
       0,   118,     0,     0,     0,   511,     0,     0,   510,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   356,     0,     0,
       0,   209,     0,     0,     0,     0,     0,     0,     0,   390,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   466,   484,     0,     0,
       0,     0,   544,   545,     0,     0,     0,     0,     0,     0,
     503,     0,   407,   529,     0,     0,     0,     0,   537,     0,
     426,   425,   424,   423,   419,   420,   427,   428,   422,   421,
     412,   411,     0,   413,   536,   414,   417,   415,   416,   418,
     510,     0,     0,   488,     0,   555,     0,     0,     0,     0,
       0,     0,     0,     0,   360,     0,     0,     0,     0,     0,
       0,   393,     0,     0,     0,     0,     0,   392,     0,   233,
       0,     0,     0,     0,     0,   519,   518,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
       0,     0,   258,     0,     0,     0,   252,     0,     0,     0,
       0,   389,   407,   533,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   312,
     313,     0,   413,   510,   488,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   622,     0,     0,     0,   505,     0,     0,
     263,   267,   265,   269,     0,     0,   643,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,   407,
       0,     0,     0,    66,     0,     0,    87,     0,    66,    67,
       0,     0,     0,   510,     0,     0,   488,     0,     0,     0,
     203,     0,     0,     0,   638,    28,    26,    27,     0,     0,
       0,     0,     0,   585,    30,     0,    29,     0,     0,   272,
     633,   634,     0,   635,   585,     0,     0,    82,   120,    83,
     130,   512,   514,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   571,   572,
     299,   233,   220,     9,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   452,   439,     0,   441,   442,   443,   444,
     445,   568,   446,   447,   448,     0,     0,     0,     0,     0,
     560,   559,   558,     0,     0,     0,   565,     0,   500,     0,
       0,     0,   502,     0,     0,     0,     0,   134,   483,   540,
     539,   213,     0,     0,     0,   469,   567,   474,     0,   480,
       0,     0,     0,     0,   530,     0,     0,   481,   546,   542,
       0,     0,     0,     0,   473,   472,    73,    74,   495,     0,
       0,     0,     0,     0,     0,     0,   407,   358,   363,   361,
       0,   372,     0,   156,   157,     0,   213,     0,   407,     0,
       0,     0,     0,     0,   253,     0,   268,   270,     0,     0,
       0,   221,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,     0,   316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,   365,
     378,     0,     0,     0,     0,   254,     0,     0,     0,     0,
     216,   368,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,   608,     0,   615,   604,   605,   606,     0,   621,   620,
       0,     0,   609,   610,   611,   617,   625,   624,     0,   147,
       0,   598,     0,   600,     0,     0,     0,   593,     0,     0,
     262,     0,     0,     0,     0,   351,     0,     0,     0,   403,
       0,   639,     0,   109,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,   590,    51,     0,     0,     0,    64,     0,    41,    42,
      43,    44,    45,    46,     0,   473,   472,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   584,
     583,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   137,   138,     0,     0,     0,
       0,   163,   163,     0,     0,     0,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,   548,   549,   550,     0,
       0,   551,     0,     0,     0,   503,   504,     0,   476,     0,
       0,   538,   429,   531,   489,   487,     0,   486,     0,     0,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     371,     0,     0,     0,     0,     0,   394,     0,     0,     0,
      77,     0,   261,     0,     0,     0,     0,     0,     0,     0,
     337,     0,     0,   336,     0,   339,     0,   341,     0,   326,
     333,     0,     0,     0,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   380,     0,     0,   256,   255,   397,
       0,     0,     0,    37,    38,     0,     0,     0,     0,     0,
       0,   576,     0,     0,     0,   302,   489,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,   506,
     602,     0,   375,     0,     0,   233,   352,     0,   353,   233,
       0,     0,   591,     0,    94,     0,     0,     0,     0,    92,
       0,   579,     0,   107,     0,    99,   101,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    36,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,   586,     0,     0,    34,    33,     0,   586,
     636,   288,     0,     0,   121,   126,     0,     0,     0,   140,
     145,   146,   141,   142,   508,     0,    85,     0,    86,   167,
       0,     0,     0,     0,   168,   187,   188,   165,     0,     0,
       0,   169,   198,   189,   193,   194,   190,   191,   192,   177,
       0,     0,     0,   440,   454,   453,   449,   450,   451,   561,
       0,     0,     0,   498,   499,   501,   135,   467,   497,   470,
     475,     0,     0,   503,   199,   482,    73,    74,     0,   494,
     490,   492,   562,   195,     0,     0,     0,   159,     0,     0,
     370,     0,   158,     0,     0,     0,     0,     0,     0,   277,
       0,     0,     0,     0,   233,   233,     0,     0,   338,   526,
       0,     0,   340,   342,     0,     0,   320,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   196,     0,
       0,     0,     0,     0,     0,     0,   174,     0,   175,     0,
       0,     0,     0,     0,     0,   110,   114,     0,   616,     0,
       0,   614,     0,   626,     0,     0,   148,   149,   623,   599,
     601,     0,     0,     0,     0,   350,   354,   350,     0,   404,
      93,     0,     0,    66,     0,     0,    91,     0,   577,     0,
       0,     0,     0,     0,     0,   629,   628,     0,     0,     0,
       0,     0,   524,     0,     0,    77,   273,   490,   274,     0,
       0,     0,     0,     0,   238,   235,     0,     0,   589,   587,
       0,     0,     0,     0,   122,   127,     0,     0,     0,   569,
     570,   139,   374,   164,   172,   173,   178,     0,     0,     0,
       0,     0,   180,     0,     0,   300,     0,     0,     0,     0,
     477,     0,     0,     0,   557,   496,     0,     0,   179,     0,
     200,   359,     0,     0,     0,     0,   201,     0,     0,     0,
       0,     0,     0,   523,   522,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,     0,     0,   376,
     377,    39,   182,   183,     0,   574,     0,     0,   304,   303,
       0,     0,     0,     0,     0,     0,   151,   152,   155,   154,
     153,     0,   603,     0,   640,     0,     0,     0,     0,     0,
       0,     0,     0,   104,   105,   580,     0,     0,     0,    96,
       0,     0,     0,    47,     0,     0,     0,     0,     0,    49,
       0,   239,   236,   237,    35,     0,     0,   637,   290,     0,
     134,   147,     0,     0,   144,     0,     0,     0,   166,   197,
       0,     0,     0,     0,     0,   563,   564,     0,   503,   478,
     491,   493,     0,     0,   181,   204,     0,     0,     0,   366,
     366,     0,   115,   116,   233,     0,   224,   225,   327,     0,
     334,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,   230,     0,   228,     0,     0,     0,     0,   111,
     112,   607,   613,   612,   150,     0,     0,     0,   355,     0,
       0,   108,   100,   102,     0,    90,   630,    97,    98,    52,
       0,     0,     0,     0,   525,     0,     0,   491,   588,     0,
       0,     0,     0,   124,   627,     0,   131,     0,     0,     0,
       0,   186,     0,     0,     0,   330,     0,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
       0,   344,     0,     0,   321,     0,   241,     0,     0,     0,
       0,     0,     0,   229,     0,   573,   305,     0,     0,   388,
     233,   405,     0,   578,     0,    48,     0,     0,     0,    65,
      50,     0,   291,   123,   128,   134,     0,     0,   161,   162,
     160,     0,     0,   479,     0,     0,     0,     0,   367,   381,
       0,     0,   382,     0,   222,     0,   335,     0,   317,     0,
     233,     0,     0,     0,     0,     0,     0,   176,   113,   301,
     350,   106,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,   202,     0,   385,     0,   386,   387,   520,
       0,     0,   323,   244,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,    62,     0,     0,   125,     0,     0,
     331,     0,     0,   343,   322,   318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,   248,     0,   242,
     357,    53,     0,    60,     0,   285,     0,   566,     0,     0,
     324,     0,     0,    54,     0,     0,   298,     0,     0,   243,
       0,     0,     0,     0,     0,     0,    57,    55,     0,    58,
       0,   383,   384,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   124,  1118,   125,   126,  1102,  1982,  1988,
    1408,  1631,  2144,  2272,  1409,  2245,  2288,  1410,  2274,  1411,
    1412,  1635,   462,   622,   623,  1190,  1729,   127,   822,   490,
    2000,  2155,  2001,   491,  1868,  1490,  1444,  1445,  1446,  1595,
    1806,  1807,  1262,  1690,  1681,  1878,   797,   634,   292,   293,
     369,   215,   294,   472,   473,   131,   132,   133,   134,   135,
     136,   137,   138,   295,  1297,  2179,  2236,   992,  1293,  1294,
     296,  1081,   297,   142,  1519,  1260,   964,  1007,  2113,   143,
     144,   145,   146,   298,   299,  1217,  1233,  1366,   300,   827,
     301,   826,   493,   651,   336,  1841,   373,   374,   303,   592,
     388,  1392,  1622,   483,   478,  1359,  1061,  1671,  1834,  1835,
    1046,   485,   148,   398
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1970
static const yytype_int16 yypact[] =
{
   13692,   111,    89, 13900, -1970, -1970,  -201,    32,    76,   -69,
     -61,   -52,    21,   256,   292,   305,   356,    69,    41,    42,
     125,   405,   465,   171,   224,    24,   -45,   659,   -45,   182,
     261,   267,    40,   276,   294,    60,   303,   306,   315,   322,
     352,   353,   376,   385,   388,   408,   252,   407,   546,   673,
     730,   537,   548,   -48,   642,   454,  7318,   482,   579,   584,
     701,   -47,    29,   659,   436,    88,   594,   750,   -21,   605,
     511,   511,   614,   592,   504,   627, -1970, -1970, -1970, -1970,
   -1970,   634,   487,   810,   800,    12,    46,   918,   822,   827,
     -40,  6286,   833,   955,   958,   964,  6286,   977,   -75,   -70,
     752,    25,    66, -1970,   753,   767, -1970, -1970, 10849,   999,
     782, -1970, 14149,   785, 14186,     8,    27,   659, -1970, -1970,
   -1970, 12474,   794,  1055, -1970, -1970, -1970, -1970, -1970,   844,
   -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970,
      13, -1970, -1970, -1970, -1970,    63, -1970,  1063,   809,  6026,
     437,   847,  1081, 12474, 14087, 14087, 14087, -1970, 12474, -1970,
   -1970, -1970, -1970, 14087, -1970, 12474, -1970, -1970, 12474, -1970,
   -1970, -1970, -1970,   825,   852,  1104, -1970, -1970, 14270, -1970,
   -1970, -1970, -1970,   854, 14270, 12474, 12474, 12474,   858, 12474,
   12474, 12474,   859, 12474, 12474, 12474, 12474, 12474, 12474, 12474,
   14087, 12474, 12474, 12474, 12474,  6286,   860, -1970, -1970, 10146,
   10146, -1970, -1970, -1970,   857,  6286,  7576, 14087, -1970, -1970,
   -1970, -1970, -1970,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   105,   -45,
     -45,   -45,   -45,   -45,   862,   -45,   -45,   863,   659,   404,
     404,   404, -1970, -1970, -1970,   -45,   -45,    35,   928,   929,
     933,   866,  7576,   998,   659,   659,   404,   872,   -45,   -45,
     873,   874,   875, -1970, -1970, -1970, 12474,  7834, 12474, 12474,
    8092,    24,   941,    37, -1970, -1970,   876, -1970,  5428, -1970,
   -1970, -1970, -1970, -1970,   164, 12474, 10146, 10146,   878,   879,
    8350,  6286,  6286,  6286, -1970, -1970, -1970,   881, -1970,   880,
     891,  8608,   898, 11007,  1159,  7576,   901,    25,   902,   903,
     511,   511,   511, 12474, 12474,   -17, -1970,   289,   511, 11102,
     501,   122,   908,   909,   911,   921,   922,   923,   924, 10146,
   12474,  6286,  6286,  6286,   194,     3,  1183,   930, -1970,  1184,
    1185, -1970,   934, -1970,   935,   936, -1970, -1970,   937,  6286,
   -1970, 12474,  6544, -1970,  1190,   939,   943,   947,   948,  1205,
    1206,   953, 12474,   954, 12474, 12474,   355, 12474,   951, -1970,
    1020, 12474, 12474, 12474, -1970,   -45, 12474,  1714,   174, -1970,
   12474, -1970,   -45,   -45,   -45,   957,   959,   960,   -45,   -45,
     -45,   -45,   -45,   -45,   -45, -1970,   -45, -1970, -1970, -1970,
   -1970,   -45,   -45,   962,   963,   -45,   966, -1970,   965,  1218,
    1223,   971, -1970, -1970,  1224,  1228,  1231,  1230,   979, 15717,
   14087, -1970, 10146, 12474, -1970, -1970,  7576,  7576, -1970,   976,
   14270,   659,  1234, -1970, -1970, -1970, -1970, -1970, -1970, 12474,
   12474,    55,  7576,  1236,   429,   981,  2004,   982,  1237,    81,
     983, -1970,   986,  5282, 12474, -1970,  2156,  -104, -1970,    70,
     -51,   -34,  8024, -1970,   -33, -1970,    71,  8282,  5220,  8540,
    -162,  -105,  1155, -1970,    24,   984, 12474,   985, 16206, 16231,
   16256, 12474, 16281, 16306, 16331, 12474, 16356, 16381, 16406, 16431,
   16456, 16481, 16506,   994, 16531, 16556, 16581, 14731,  1249, 12474,
   10146,  5691, -1970,   151,   199, 12474,  1251,  1252,  1000, 12474,
   12474, 12474, 12474, 12474, 12474, 12474, 12474, 12474, 12474, 12474,
   12474, 12474, 12474, 12474, 12474, 10146, 12474, 12474, 12474, 12474,
   12474, 12474, 12474, 12474, 10146, 10146,   995, 12474, 12474, 14087,
   12474, 14087,  7576, 14087, 14087, 14087,   996,  1001,  1002,  1003,
   12474,     7, -1970, 11360, 12474,  7576,  6286,  7576,  1004, 14087,
   14087, 10146,    24, 14270,    24,  1005, 10146,  1005, -1970,  1005,
   16606, -1970,   278,  1006,    91,  1195, -1970,  1261, 12474, 12474,
   12474, 12474, 12474, 12474, 12474, 12474, 12474, 12474, 12474, 12474,
   12474, 12474,  8866, 12474, 12474, 12474, 12474, 12474,    24, 12474,
   12474,    67, -1970,   755, 16631,   365,   394, 12474, 12474, 12474,
   -1970,  1263,  1266,  1266,  1014, 12474, 12474, 12474, 12474,    31,
   10146, 10146, 15745,  1016,  1291, -1970,  1034, -1970, -1970,  -122,
   -1970, -1970,  8798,  9056,   511,   511,   437,   437,  -113, 11102,
   11102, 12474, 12606,   -23, -1970, 12474, 12474, 12474, 12474, 12474,
   12474, 12474, 12474, 12474,   411, 16656,  1292,  1295,  1296, 12474,
   12474,  1301, 12474, -1970, -1970, 12474, 12650, -1970, -1970, 10146,
   10146, 10146, 12474,  1303, 16681,  1045, 12474, 10146, 12474, 12474,
   12474, -1970, -1970, 12474, 16706, 12474, 16731, 16756,  1118,  9309,
   -1970,  1048,  5938, 16781, 16806, 12474,  1005, -1970, 12474,    24,
   12474, 12474,    67, 15801, 14087, 14087, 14087, 14087, 14087, 14087,
   14087, 14087, 14087, 12474, 14087, 14087, 14087, 14087,    19, 14270,
   14087, 14087, 14087,    24,    24, -1970, -1970, 10146, -1970,  1049,
   12723, -1970,  1050, 12784, 12474, -1970,  1053,   450, 16831, 14315,
    1052,   488, 12474,  1311,  1054,  7576, 16856, 15828, -1970, -1970,
   -1970, -1970, -1970,  1056,  1313,   212,  1315, -1970, -1970, -1970,
   10146,   247, 12474, -1970, -1970, -1970,    24, 12474, 12474,    67,
    1061, -1970,  1065,   -36,   659,   436,   659, -1970,  1064, 14760,
   -1970,   132, 10146,    24, 12474, 12474,    67,  1323, 10146,  1324,
   10146, 12474,  1325, 14087,    24, 11447,    67, 12474, -1970, 12474,
    1326, -1970,    24,  1327, 14087, 12474,  1073,  1076, -1970, 12474,
    9562, 14270,  1333,  1335,  1336, 16881,  1338,  1339,  1342, 16906,
    1343,  1345,  1348,  1351,  1353,  1354,  1356, -1970,  1357,  1358,
    1360, -1970, 12474, 16931, 10146,  1105, 10146,    49, 14789, -1970,
   -1970,  1364,  5911,  5911,  5911,  5911,  5911,  5911,  5911,  5911,
    5911,  5911,  5911,  9820,  5911,  5911,  5911,  5911,  1041,   518,
    5911,  5911,  5911, 10078, 10430, 10962, 11038, 11307,  5691,  1110,
    1109,   152, 10146, 11391, 11655,   518, 11731,   518,  1107,  1108,
    1113,    83, 10146, 12474, 12474, 12474,  2768, -1970,   518,  1114,
   14818, 14847, -1970, -1970, 12474,  1115,   420,   518,   -79,  1112,
     -68,   577,  1367, -1970,    67,   518,  7576,  1120,  5961,  6218,
    1454,   544,   747,   747,   704,   704,   704,   704,   704,   704,
     607,   607, 10146,     5, -1970,     5,     5,  1005,  1005,  1005,
    1117, 16956, 15855,   558, 10146, -1970,  1371,  1122,  1126, 16981,
   17006, 17031, 12474,  7576,  1387,  1388, 10753, 17056, 14876, 17081,
   17106, -1970, 12474,   580,   599, 10146,  1127, -1970, 12887, -1970,
   12948, 13021,   511, 12474, 12474, -1970, -1970,  1132,  1133, 11102,
    6735,  1255,   498,   511, 13065, 17131, 14905, 17156, 17181, 17206,
   17231, 17256, 17281, 17306,  1136,  1394, 12474,  1396, -1970, 12474,
   17331, 14934, -1970, 15882, 13201, 15909, -1970,   611,   631,   632,
   14963, -1970, -1970, -1970,  2184,   643, 15936, 15963, 11994, 17356,
    1397, 17381,  1398,  1399,  1137, 12474, 13245, 12474, 12474, -1970,
   -1970,  5911,     5,  1141,   649,    36,   513,   545,   513,  1148,
    1149,  1142,   518,   518,  1143, 12078,   518,   518,   518,   518,
   12474,   518,  1405, -1970,  1146,  1156,   604,   -98,  1153,   650,
   -1970, -1970, -1970, -1970, 17406, 13318,  1151,  1225,  1415,  1258,
   11700,  1160,  1162,  1418,  7576, 14992, -1970, 12474,  1422,   217,
      59,    67,    26, 14270, 12474,  1424, -1970,   651,  1385,  1386,
    7576, 15021,   173,  1170, 17431, 15990,   617, 12474, 12474,  1177,
    1175,  1180,  1178,  9124, -1970, -1970, -1970, -1970, 14087,   156,
    1179, 17456, 16017,  1186, -1970,   166, -1970,   204, 12334, -1970,
   -1970, -1970,  1187, -1970,  1189, 15050, 12429, -1970,    80, -1970,
   -1970,  2768, -1970,    95,  5911, 12474,   518,   511,  7576,  7576,
    1436,  7576,  7576,  7576,  1437,  7576,  7576,  7576,  7576,  7576,
    7576,  7576,  7576,  7576,  7576,  2349,  1444, 10146,  5691, -1970,
   -1970,   437, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970,
   -1970, -1970, -1970, -1970, -1970, 12474, -1970, -1970, -1970, -1970,
   -1970, -1970, -1970, -1970, -1970, 12474, 12474, 12474, 12474, 12474,
   -1970, -1970, -1970,   652, 12474, 12474, -1970, 12474, -1970,  7576,
   14087, 14087, -1970,   660, 15079, 15108, 15137,  1193, -1970, -1970,
   -1970,  1256, 15166, 12474, 12474, -1970, -1970, -1970,    67, -1970,
      67, 12474, 12474,  1194, -1970,  7576,   -45, -1970, -1970, -1970,
   12474, 12474,   663,    67,  -180,  -183, 12474, 12474, -1970,   518,
     665,  7576, 10146, 10146,  1451,  1466,  1467,  1957, -1970, -1970,
    1469, -1970,  1215,  2768,  1209,  1472, -1970,  1473,  1474,  2410,
    1475,  1476,   671,    92, -1970, 13379, -1970, -1970,   180, 12991,
   13024, -1970, -1970, 15195,  -124,  1365,  1480, 11794,  1226,  1482,
    1232,    28,    30,   -60, -1970,   207, -1970,   498,  1484,  1488,
    1489,  1490,  1491,  1492,  1493,  1494,  1495,   437,  7576,  2768,
   -1970,  2792,  1239,  1402,  1500, -1970,  1501,  1502,  1401,  1503,
   -1970, -1970,  1504,  1509,  1510, 12474,  1511,  7576,  1512,  7576,
    7576,  1519, 13475, -1970,  6476,   459,    67, 12474, 12474,    67,
      67, -1970, 10146, -1970, -1970, -1970, -1970, 14087, -1970, -1970,
   12474, 14087, -1970, -1970, -1970, -1970,  2768, -1970,  1257,  1260,
   14087, -1970, 14087, -1970,    67, 14087,  1264, -1970,  1262,  1520,
   -1970,  1268,   659,  1271, 12047, -1970,  3049,  1272,  7576, -1970,
    1273, -1970, 15224, -1970, -1970, 12474,  1521,    58, 12474,  1531,
    1533,    25,  1535,  1280,  1538,  3202, -1970,   518,   -45,   -45,
    1539, -1970, -1970,  1286,  1287,  1284, -1970,  1543, -1970, -1970,
   -1970, -1970, -1970, -1970,    67,   427,  1123, 12474, 16044, 17481,
   12474,  9377, 12474, 10146,  1288,   677,  1545,   144,    67, -1970,
    1289, 12474,  1546,  1550, 12474,    67, 12134,  1551, 12474,  5042,
     518,  5492, 12474, 12474,  1297,  1294, -1970,  1555, 17506,  1558,
     106,  1428,  1428,  7576,  1560,  1561,  1562,  7576,   -86,  1563,
    1564,  1565,  1566,  1568,  1570,  1571,  1572,  1573, -1970,  1575,
     678,  1316,  5911,  5911,  5911,  5911,  5911,  5911,   518, 13690,
   14269, 14302,  1321,   518,   518, -1970, -1970, -1970, -1970,    95,
     518, -1970, 17531,  5911,  1322,  -139,  2768,  5911, -1970,  1578,
     518,  2768,  2768, -1970,   724, -1970,    67, -1970, 17556, 16071,
   -1970,   518,  1579,   679,   700,  7576,  7576,  7576,  1582,  1581,
   -1970,   254, 12474,  7576,  7576,  7576, -1970,  1337,  1347,  1584,
    1600,  1605, -1970, 12474, 12474, 12474,  1349,  1350,  1355,  1361,
   -1970,  3227,  7576, -1970, 12474, -1970,  1601, -1970,  1609, -1970,
   -1970, 11102,     1,  6802, -1970,  1366,  1368,  1369,  1370,  1372,
    1375,  9630,  1363,  1614, -1970, 10146,  1376, -1970, -1970, -1970,
    1377, 12474, 12474, -1970, -1970, 16098,  7576,  1616,  7576,  1623,
    1450, -1970, 12474, 12474, 12474, -1970,   841,  1637,   238,   629,
    1319,  4283,  1378, 12474,    45,   518,  1383,   518,  1379, -1970,
   -1970, 14270, -1970, 12474,  1381, -1970, -1970,  3384, -1970, -1970,
    1382,  1640, -1970,  3408, -1970,  1384,  1645,   227,  3569, -1970,
      25, -1970,   702, -1970, 12474, -1970, -1970,   254,  3120,  4645,
   -1970,  1393, 12474, 12474,  7576,  1390, -1970,   340,   118,  1649,
   17581,  1650,  1367, 17606,  1392,   705, 17631,   708,  1652,  1653,
   -1970, -1970, 14087,  1403,  1657, 17656, -1970, -1970, 14335,  1406,
   -1970, -1970,  6992,  5759,  2768, -1970,  1660,   -45,  8092, -1970,
   -1970, -1970,  2768,  2768, -1970,    95, -1970,  1662, -1970, -1970,
     511,  1663,  1665,  1666, -1970, -1970, -1970,  1529,    38,  1569,
    1670, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970,
    1673,  1416,  1676, -1970, -1970, -1970, -1970, -1970, -1970, -1970,
   12474, 12474, 12474, -1970, -1970, -1970,  1294, -1970, -1970, -1970,
   -1970, 12474,  1423,  1410, -1970, -1970, 12474, 12474,   518,  -180,
   -1970, -1970, -1970, -1970,  1425,  1427,  1681,   -86,  1703, 12474,
   -1970,  7576,  2768,  1567,  1577,  1103, 10146, 10146, 12474, -1970,
   10753, 15253, 17681,  7250,   437,   437, 12474, 12474, -1970,   154,
    1441, 17706, -1970, -1970, 15282,   244, -1970,  1706,  1716,  7576,
     511,   511,   511,   511,   511,  7060,  1717, -1970, -1970,   710,
   10146, 12474,  3921,  3991,  1719,  1720, -1970,  1721, -1970,  7576,
    7508,   585, 17731, 12474, 12474, -1970, -1970, 10399, -1970, 14087,
   12474, -1970, 14087,  2768, 10495, 14270,  1459, -1970, -1970, -1970,
   -1970,  1468,  1461, 15311, 12474, 14315, -1970, 14315,  7576, -1970,
   -1970,    67,    26, 14270, 12474,  1727, -1970,  1728, -1970,    25,
   16125,  7576, 14087,  1729,   518, -1970,  1471,   518, 12474, 14368,
   14401,   711, -1970, 12474, 12474,  1477, -1970,  1478, -1970,  1467,
    1730,  1731,  1474,  1739, -1970, -1970,  1741, 12474, -1970, -1970,
   12474, 12387,  1742, 12474, -1970, -1970,  1487,  4645,   713,  3605,
    1745, -1970, -1970,   248, -1970, -1970, -1970,  1607,  1750,  1496,
    1498,  1499, -1970,  1752,  7576, -1970,  5911,  5911, 14434,  5911,
   -1970,  1497, 17756, 16152, -1970, -1970, 10146, 10146, -1970,  1753,
   -1970,  2768,  1758, 12474, 12474,  1505, -1970,   718,   738, 15773,
    4132,  1761,  1506, -1970, -1970, 12474,  1508,  1513, 15340, 16179,
    1762,  7576,  1764,  1515, 12474, -1970, -1970,   739,   246,   251,
     253,   257,   270,  9888,   286, -1970,  1768,   745, 15369, -1970,
   -1970, -1970, -1970, -1970,  1585, -1970, 12474, 12474, -1970, -1970,
   10146,  4179,  1769,  1522,  5911,   518,  2768, -1970, -1970, -1970,
   -1970,    45, -1970, 14270, -1970, 15398,  1516,  1517,  1523,  1773,
    1778,  1779,  4205, -1970, -1970, -1970,  1524,  1781,   746, -1970,
    1783,  1785,   242,  2768, 12474, 12474,  1528,  7576,   756,  2768,
   17781, -1970, -1970, -1970, -1970, 17806, 14467, -1970, -1970, 15427,
    1193,  1260,  7576,   518, -1970, 12474, 14270,    24, -1970, -1970,
   10146, 10146, 12474,  1787,   761, -1970, -1970, 12474,  1410, -1970,
   -1970, -1970,   763,   764, -1970, -1970,  4245,  4697,  7576,   596,
     623, 10146, -1970, -1970,   437,  7766, -1970, -1970, -1970,  1788,
   -1970,  1530,  7576, -1970, 15456,  1791, 10146,   511,   511,   511,
     511,   511, -1970,  1792, -1970, 12474, 15485, 15514,   769, -1970,
   -1970, -1970, -1970, -1970, -1970,  1540,  1794,  1541, -1970,  1796,
      25, -1970, -1970, -1970,  1610, -1970, -1970, -1970, -1970, -1970,
   12474, 14500, 14533,  7576, -1970,  1797, 12474,  1542, -1970, 12474,
    1801,  1544,  1547, -1970, -1970,  5210, -1970,  1548,   770,   771,
   15543, -1970,  1549, 14566,  1553, -1970,  1552, -1970, -1970,   772,
    1554,   511,  7576,  1804,  1556,   511,  1805,   777,  1557, -1970,
   12474, -1970,  1811,  1677, 13482,  1574, -1970,   778,   301,   316,
     342,   359,   395, -1970,  4909, -1970, -1970,  1821,  1824, -1970,
   -1970, -1970,  1828, -1970,  1576,  2768, 12474, 12474,   797, -1970,
    2768, 14599, -1970, -1970, -1970,  1193, 14270,  1580, -1970, -1970,
   -1970, 12474, 12474, -1970, 10146,  1829,   511,   112, -1970, -1970,
     511,   136, -1970,  1830, -1970, 15572, -1970, 12474, -1970,   498,
   -1970,  1831, 10146, 10146, 10146, 10146,  9888, -1970, -1970, -1970,
   14315, -1970, 12474, 17831, 14632,    50, 12474,  1586, -1970, -1970,
   14665, 14698,   805, -1970,   398, -1970,   401, -1970, -1970, -1970,
    4962,   452, 13543, -1970,   806,   807,   813,   814,   413,   815,
    1587,   821, -1970, 12474, -1970,  7576, 15601, -1970, 12474, 12474,
   -1970,   511,   511, -1970, -1970, -1970,   498,  1833,  1836,  1837,
    1838, 10146,  1839,  1841,  1847,  1590, 17856,   823,  1849, 15630,
    5911,   426,   499,   478, -1970, -1970, -1970, -1970,   829, -1970,
   -1970, -1970, 14087, -1970,  1592, -1970,  1851, -1970, 12474, 12474,
   -1970,  1852,   830, -1970,  1595,  7576, -1970, 15659, 15688, -1970,
    1854, 14087, 14087,   831,  1857,  1859, -1970, -1970,   837, -1970,
    1860, -1970, -1970,  1861, 14087, -1970, -1970, -1970
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1970, -1970, -1970, -1970,   441, -1970, -1970, -1970, -1970,  -322,
   -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970, -1970,
   -1970, -1970,  -755,  -140,  4368,  3414,  -426, -1970,  1380, -1970,
   -1970, -1970, -1970, -1970, -1970, -1969, -1970,   383,   198,  -127,
   -1970,   -85, -1970,   138,   425, -1970,  1875, -1970,   868,   -39,
   -1970, -1970,    -1,  -638,  -116, -1970, -1970, -1970, -1970, -1970,
   -1970, -1970,   781,  1876, -1970, -1970, -1970, -1970, -1291, -1289,
    1877, -1807,  1882, -1970, -1970, -1970,  1254, -1970,  -141, -1970,
   -1970, -1970, -1970,  2172, -1970, -1970, -1490,   290,  1888, -1970,
     -13, -1970, -1970,   -56, -1970, -1768,   308,   -72,  3248,  2794,
    -324,    73, -1970,   323,   -73, -1970, -1970,    93,   263, -1759,
    -142,  1083, -1970,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -590
static const yytype_int16 yytable[] =
{
     149,  1927,   130,   646,  1550,  1722,  1552,   681,  1966,   463,
    1967,   173,   174,   434,   335,   337,   355,   340,   987,   988,
    1094,   484,   175,   173,   379,   321,  1100,   157,   173,   386,
     173,  2091,   436,   381,  1545,   775,  1547,   971,   383,   429,
     572,   433,   596,  1339,   188,  1959,   152,   164,   166,  1804,
     360,   488,   361,   304,   211,  1170,  2224,   212,  1688,   768,
     213,   309,   768,   150,   192,   366,  1384,   151,   367,   445,
     390,   768,   309,   214,   457,   458,   468,   457,   458,   803,
     814,   368,   359,  1506,  1286,   173,   310,  1439,   304,     5,
     786,   769,   770,   304,   769,   770,  1530,  1109,   389,  1441,
     494,   820,  1287,   769,   770,   495,   356,   821,  2003,   430,
    1689,   497,  1679,  1288,  1289,  1290,  2014,     4,  2205,  1291,
    1292,   176,  1845,   177,   654,   655,   654,   655,   769,   770,
    1231,  1442,  1443,   518,   311,   654,   655,   312,  1115,   313,
    1879,  1537,  2207,   526,   326,  1286,   469,   982,   362,   471,
    1651,   479,   479,   479,   769,   770,   989,   801,   823,  1880,
     486,   618,   598,  1287,   821,   802,   771,   772,  1364,   771,
     772,  1365,   327,   618,  1288,  1289,  1290,  1402,   771,   772,
    1291,  1292,  1227,   719,   153,   382,  2197,  1228,   328,   329,
     384,   154,   176,   322,   177,   953,   323,   479,  1230,   155,
     972,  1231,   304,   771,   772,  1549,   304,   304,   156,  1546,
     807,  1548,   304,   304,   479,   176,   357,   177,   808,  1093,
     567,   568,   569,   662,  1384,   654,   655,   809,   812,   771,
     772,   654,   655,  1891,  1823,   810,   813,   578,   122,   631,
     632,   633,   686,   122,  1796,  1797,   993,   656,   773,   774,
     122,  1615,  1616,  1805,  1098,   122,   122,   122,   615,   616,
    2109,  1384,   159,  1550,   617,   682,  1766,   683,   778,   304,
     779,   151,   435,   443,   649,   650,   358,   444,   593,   676,
     677,   678,   658,   663,   304,   158,  1060,   304,   594,   387,
    1391,   437,   453,   454,   455,   456,  1044,   693,   160,   573,
     189,   597,  1340,   304,   304,   165,   167,   304,   304,   304,
     304,   161,   122,  1171,  2225,  2148,   457,   458,   304,   750,
     193,   753,   304,   446,   389,  1387,   391,   447,   759,   163,
     804,   815,   805,   805,  1385,  1388,   806,   816,   457,   458,
     176,   787,   177,   788,  1212,  -582,   304,   789,   304,   304,
     304,   176,   813,   177,   654,   655,  1403,  1404,  1405,  1406,
     654,   655,   162,  1106,   302,   554,   304,   555,   102,   304,
     103,   104,   105,   106,   107,  1116,  1117,   763,   111,   112,
    1123,   114,   665,  2220,   654,   655,   666,  1116,  1117,   168,
    1134,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   457,
     458,   169,   619,   617,   620,  1202,   855,  1427,   621,  1920,
     856,   457,   458,   901,   619,   856,   620,  1432,   654,   655,
     621,   457,   458,   171,   720,   856,   721,   479,  1407,   304,
     722,   470,   185,   304,   304,   453,   454,   455,   456,  1533,
     453,   454,   455,   456,   679,   654,   655,  2247,   680,   304,
     453,   454,   455,   456,   857,  1433,   790,  1584,   856,   457,
     458,   170,   467,   856,   457,   458,  1551,   477,   480,   481,
     453,   454,   455,  1099,   457,   458,   172,   453,   454,   455,
     456,   828,   654,   655,   654,   655,   654,   655,  1236,   654,
     655,   654,   655,  2079,   912,   654,   655,  2283,   341,   315,
     919,  2080,   316,  1924,   318,  2046,   204,   304,   654,   655,
    2047,   186,  2048,   513,   527,   319,  2049,   187,  2104,   978,
     205,   980,   981,  1471,   654,   655,   190,   654,   655,  2050,
     528,   315,   304,   923,   316,   317,   318,   856,   994,   654,
     655,   304,   891,   657,   191,  2051,   479,   319,   479,   304,
     479,   479,   486,   194,   654,   655,   195,  1014,   908,   918,
    2182,   920,   304,   304,   304,   196,   479,   479,   304,   175,
     302,   175,   197,   304,  1048,  2183,    69,    70,    71,    72,
     654,   655,    75,  1947,  1036,   351,  1286,   352,   985,   986,
    1844,    84,  1794,   650,  -586,    88,   342,   654,   655,   304,
     343,  2184,   198,   199,  1287,   950,   344,   345,   630,   346,
     347,   708,  1286,   151,   320,  1288,  1289,  1290,  2185,   639,
     957,  1291,  1292,   644,   856,  1095,   200,   304,   304,  1075,
    1287,   348,  1286,   654,   655,   201,   654,   655,   202,   654,
     655,  1288,  1289,  1290,   206,   471,   471,  1291,  1292,   958,
    1287,   654,   655,   856,  2186,  1390,  1063,  2231,   203,  1562,
    2232,  1288,  1289,  1290,   654,   655,  1004,  1291,  1292,   207,
     856,   778,  2241,   779,   457,   458,   304,   304,   304,  1224,
     778,  -584,   779,   780,   304,  2268,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,   217,  1077,  1043,  2234,   617,   856,
    1585,   486,   479,   486,   479,   479,   479,   479,   479,   479,
    1067,   479,   479,   479,   479,  1062,   208,   479,   479,   479,
     175,  1068,   305,  2270,   304,  2110,  2111,   654,   655,   654,
     655,  2112,   216,  1083,   760,   761,  1111,  1084,  1146,   331,
     332,   179,   304,   756,   180,   664,  1741,   181,  2269,   182,
     776,   333,  2114,  2115,   778,   334,   779,   304,  2112,   778,
      46,   779,   813,  1103,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,   304,
    1120,   209,  1494,   617,  1495,   304,   778,   304,   779,   308,
     486,  1132,   210,  1248,  1342,   457,   458,  1504,  1246,  1138,
    1247,   479,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
     331,   332,  1234,   306,   617,  1270,   856,  1531,   307,   856,
    1948,   304,   333,   304,   324,   325,   339,   718,   613,   614,
     615,   616,  1824,  1275,  1271,   778,   617,   779,   856,   330,
     898,   129,  1831,  1362,   457,   458,  1317,  1417,   338,  1338,
     856,  -585,   895,   630,   897,   913,   899,   900,  2211,   304,
     778,   349,   779,  1264,   350,   183,  1318,  1319,   856,   304,
     856,   856,   915,   916,  1248,   354,   457,   458,  1322,  1337,
    1586,  1338,   856,  1587,  1588,  1368,  1397,  1478,   353,   856,
     856,   856,  1550,   304,   363,  1485,  1278,   364,  1503,   856,
    1511,   314,   856,  1284,   856,   365,  1529,  1295,  1598,   304,
     856,   375,  1649,  1701,  1734,  2253,   856,   856,   856,  1386,
    1389,   304,   610,   611,   718,   613,   614,   615,   616,   376,
     304,  1617,   377,   617,  1550,  1735,  1248,  1828,   378,   856,
    1851,  1829,   304,  1853,   856,  1936,  1986,   856,  2004,   856,
    1987,   380,  2005,  2029,  1726,   438,  1727,   856,  1637,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,  1653,  2030,  2045,   399,   617,   856,  1987,  1659,
    2053,  2076,   385,   392,   856,   813,   778,   465,   779,   954,
    1394,  2085,   465,   465,   465,  2086,  2102,   393,  2105,  2106,
    1987,   465,   856,   856,  2137,  2158,  2159,  2165,   856,   856,
     856,  1987,  2173,  2181,   400,   431,   856,   856,  1047,   598,
    1049,  1050,  1051,  1052,  1053,  1054,   440,  1056,  1057,  1058,
    1059,   441,  2195,  1064,  1065,  1066,  1987,  1621,   465,   448,
    2230,  2237,  2238,  1088,   856,   856,   856,   449,  2239,  2240,
    2242,   304,   856,   856,   856,   465,  2244,   475,  2264,  1393,
    2086,  1450,  1987,   151,  2271,  2280,  2290,   304,   856,  2281,
    1987,  1793,  2293,  1794,  1505,  1507,  2294,  1905,   442,  1906,
     304,   474,   492,   494,   496,   479,  1916,  1917,   501,   505,
     519,   525,   562,   565,  -206,  -207,   566,   173,   401,  -208,
     574,   575,   579,   582,   583,   584,  1130,   595,   627,   628,
     444,   635,   576,   577,   636,   304,   304,  1140,   304,   304,
     304,   637,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   640,   643,   304,   645,   647,   648,   667,   668,
     471,   669,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   670,   671,   672,   673,   411,   412,   413,   414,   684,
     687,   688,   685,   415,   416,   417,   418,   696,   689,   690,
     691,   692,   419,   697,   420,   698,   304,   479,   479,   699,
     700,   701,   702,   703,   705,   710,   711,   727,   421,   728,
     729,   422,   740,   741,   745,   179,   743,   744,   180,   746,
     748,   181,   304,   182,  1238,   747,   749,   751,   752,   754,
     762,   765,   777,   785,    46,   782,   784,   150,   304,   304,
     304,   791,   825,   829,   831,   847,   852,   859,   860,   892,
     902,   861,   926,   451,   617,   903,   904,   905,   914,   927,
     962,  1258,   924,   963,   966,  1505,  1507,   976,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   854,   613,   614,   615,   616,  1827,   977,   979,  1006,
     617,  1008,   778,  1009,   779,   304,   471,  1012,   465,  1021,
    1023,  1034,  1037,  1082,  1070,  1072,  1076,  1086,  1087,   764,
    1092,  1096,  1091,  1107,   304,  1108,   304,   304,  1113,  1124,
    1126,  1129,  1137,  1139,  1142,   423,   424,   425,  1143,   304,
    1147,   798,  1148,  1149,   479,  1151,  1152,   426,   479,  1153,
    1155,   427,  1156,   428,   122,  1157,   798,   479,  1158,   479,
    1159,  1160,   479,  1161,  1162,  1163,  1665,  1164,  1670,  1167,
    1173,  1200,  1201,  1229,  1235,   304,  1209,  1210,  1251,  1219,
     457,   458,  1211,  1243,  1223,  1239,  1252,  -583,   389,  1638,
    1253,  1259,  1380,  1273,  1261,  1969,  2118,  1281,  1282,  1285,
    1307,  1308,  1310,  1331,  1327,  1329,  1330,  1336,  1400,  1345,
    1346,  1347,  1350,   479,  1358,  1360,  1367,  1361,   304,  1371,
     304,  1372,  1373,  1374,  1379,  1377,  1378,   465,  1383,   465,
    1396,   465,   465,   465,  1398,  1399,  1414,  1420,   304,  1421,
    1422,  1426,  1423,  1453,  1457,  1428,  1431,   465,   465,  1436,
     304,  1469,  -209,  1435,   304,  1498,  1451,  1452,  1515,  1454,
    1455,  1456,  1489,  1458,  1459,  1460,  1461,  1462,  1463,  1464,
    1465,  1466,  1467,  1516,  1517,  1520,  1521,  1825,  1522,  1523,
    1524,  1525,  1527,  1528,  1539,  1538,  1836,  1836,  1543,  1815,
    1542,  1553,  1544,  1817,  1554,  1765,  1555,  1556,  1557,  1558,
    1559,  1560,  1561,  1565,  1566,  1975,  1567,  1568,  1569,  1570,
    1571,  1572,   304,   304,   304,  1573,  1574,  1482,  1576,  1578,
     304,   304,   304,  1581,  1593,  1600,  1602,  1614,  1812,  1594,
     798,  1601,  1603,  1483,  1484,  1605,  1609,  1619,  1611,   304,
    1620,  1623,  1624,  1499,  1625,  1630,  1632,  1633,  1634,  1636,
     304,  1650,  1656,  1648,   798,  1654,  1657,  1661,   304,  1512,
    1674,  1676,   304,  1675,  1678,  1680,  1684,  1685,  1686,  1691,
    1692,  1693,  1694,   304,  1695,   304,  1696,  1697,  1698,  1699,
    1700,  1702,  1713,  1720,  1724,  1733,  1739,  1740,  1799,  1895,
    1865,  1748,   465,   465,   465,   465,   465,   465,   465,   465,
     465,  1746,   465,   465,   465,   465,  1749,  1762,   465,   465,
     465,  1747,  1750,  1754,  1755,  1763,  1563,   389,   798,  1756,
    1778,   798,  1786,  1757,  1873,   486,   486,   798,  1777,  1788,
    1769,   304,  1770,  1771,  1772,  1577,  1773,  1579,  1580,  1774,
    1780,  1781,  1789,  1795,  1809,  1814,  1819,  1802,  1365,   479,
    1821,  1818,  1822,  1838,  1843,  1846,  1848,  1850,  1854,  1855,
     304,  1858,  1110,  1857,  1112,   304,  1861,  1866,  1872,  1874,
    1590,  1875,  1876,  1877,  1592,  1881,  1882,  1911,  1883,  1231,
    1884,   465,  1885,  1596,  1890,  1597,  1610,  1898,  1599,  1896,
    1978,  1897,   465,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,  1900,
    1921,  1903,  1925,   617,  1928,  1929,  1930,  1931,  1932,  1934,
     717,  1904,  1926,  1935,  1952,  1941,  1942,  1943,  1961,  1962,
    1963,  1957,  1960,  1973,  1974,  1979,  1991,  1992,   304,  1639,
     813,  -589,  -587,   304,   304,  1993,  2142,  1994,  1998,  1669,
    1971,  2002,  2007,   471,   471,  2008,  2009,  2013,  2019,  2024,
    2010,  1683,  2011,  2012,  2025,  1687,   304,  2033,  2040,  2028,
    2034,  2042,   304,  2036,  2052,  2060,  2055,   304,  2037,  2043,
    2070,  2067,  2068,  2061,  2071,  2072,   304,  2075,  2069,  2077,
    2074,  2078,  2083,  2101,  2121,  2122,   479,  2126,  2133,   479,
    2139,  2138,  2141,  2149,  2143,  2140,  -588,  2152,  2157,  2153,
    2169,  2172,  2154,  2161,  2163,   304,  2164,  2176,  2166,  1393,
    2170,  2177,  2174,  1736,  1737,  1738,   389,  2188,   304,   486,
    2189,  1743,  1744,  1745,  2191,  2203,  2208,  2213,  2180,  2254,
    2192,  2199,  2255,  2256,  2257,  2259,   798,  2260,   798,   798,
    1760,  2227,  2243,  2261,  2262,  2265,  2275,  2276,  2279,  2282,
    2286,  1768,   798,  2291,   486,  2292,  2295,  2296,  1652,  1776,
    2221,   824,  1716,  1871,  2092,  1899,  2064,  1682,   128,   139,
     140,   304,   798,  1413,  1785,   141,  1787,   965,  1811,  2116,
    2065,   147,  1837,   304,   304,  1970,  1131,  1958,     0,     0,
       0,     0,     0,     0,   798,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,  2124,     0,     0,
     304,     0,     0,  2096,     0,     0,     0,     0,     0,     0,
       0,     0,  1842,   798,     0,     0,     0,   304,     0,     0,
       0,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,  1864,     0,   617,     0,  1856,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,   465,     0,     0,     0,
       0,  2128,  2129,  2130,  2131,  2132,     0,     0,     0,   304,
       0,     0,     0,     0,  2097,     0,     0,   304,   304,     0,
     783,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2190,   304,     0,     0,   304,     0,
       0,     0,     0,   471,     0,     0,     0,     0,     0,   304,
       0,     0,     0,   304,     0,     0,     0,     0,     0,  1902,
       0,     0,     0,     0,     0,  2167,     0,     0,     0,  2171,
       0,     0,     0,     0,  2212,     0,     0,   389,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1842,   465,   465,
     304,     0,     0,  2198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1944,     0,     0,
       0,  1518,     0,     0,     0,     0,     0,     0,     0,   304,
    2204,     0,     0,     0,  2206,     0,     0,     0,     0,     0,
       0,     0,  1953,     0,     0,  1955,  1968,     0,     0,     0,
    2218,     0,     0,     0,     0,     0,     0,     0,     0,  1977,
       0,     0,     0,   798,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,   800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2251,  2252,     0,     0,   304,
     304,   304,   304,   304,     0,     0,     0,     0,     0,     0,
    1321,     0,  1842,     0,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,   465,   617,     0,     0,   465,
       0,     0,   304,     0,     0,     0,     0,     0,   465,  2041,
     465,     0,     0,   465,     0,     0,     0,     0,   304,     0,
    1604,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,   479,
       0,     0,     0,   617,     0,     0,     0,     0,     0,     0,
       0,     0,   304,     0,     0,     0,     0,     0,   479,   479,
     397,     0,     0,     0,   465,     0,     0,     0,     0,     0,
       0,   479,     0,   439,     0,  2084,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2093,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,     0,     0,     0,   476,     0,     0,     0,     0,
     482,     0,     0,     0,     0,     0,  1842,   487,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2123,     0,     0,     0,     0,  1468,     0,   498,   499,   500,
       0,   502,   503,   504,     0,   506,   507,   508,   509,   510,
     511,   512,     0,   514,   515,   516,   517,     0,     0,     0,
       0,   521,   521,     0,     0,     0,     0,     0,     0,     0,
       0,  1842,     0,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,  1526,     0,     0,     0,
    2168,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   585,   587,
     589,   590,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   624,   521,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,   465,   465,     0,     0,
       0,     0,     0,     0,     0,   652,   653,     0,     0,     0,
       0,   653,     0,     0,     0,     0,     0,     0,     0,     0,
     465,   521,   675,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1842,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   694,   521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   704,     0,   706,   707,     0,   709,
       0,     0,     0,   712,   713,   714,     0,     0,   716,     0,
       0,     0,   723,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1842,     0,  2273,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,  2287,  2289,     0,     0,   617,     0,
       0,     0,     0,     0,   521,   758,     0,  2297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   766,   767,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   799,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,   465,   830,   617,
     465,     0,     0,   835,     0,     0,     0,   839,     0,     0,
       0,     0,     0,   798,     0,   798,     0,     0,     0,     0,
       0,   853,   587,     0,     0,     0,     0,   858,     0,     0,
     465,   862,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   880,   881,
     882,   883,   884,   885,   886,   887,   888,   888,     0,   893,
     894,     0,   896,     0,     0,   465,     0,     0,     0,     0,
       0,     0,   906,     0,     0,   910,   911,     0,     0,     0,
       0,     0,     0,   888,     0,     0,     0,     0,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     928,   929,   930,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   941,   943,   945,   946,   947,   948,   949,
       0,   951,   952,     0,     0,     0,     0,     0,  1564,   959,
     960,   961,     0,     0,     0,     0,     0,   967,   968,   969,
     970,     0,   521,   521,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   585,   716,   990,     0,     0,     0,   995,   996,   997,
     998,   999,  1000,  1001,  1002,  1003,     0,     0,     0,     0,
       0,  1010,  1011,     0,  1013,     0,     0,  1015,     0,     0,
       0,   521,   521,   521,  1020,     0,     0,     0,  1024,   521,
    1026,  1027,  1028,     0,     0,  1029,     0,  1031,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1041,     0,     0,
    1042,     0,   951,   952,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1055,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   521,
       0,     0,     0,     0,     0,     0,  1074,     0,     0,     0,
       0,     0,     0,     0,  1085,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   521,     0,  1101,     0,     0,     0,     0,  1104,
    1105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   521,     0,  1121,  1122,     0,     0,
     521,     0,   521,  1128,     0,     0,     0,  1121,     0,  1135,
       0,  1136,   798,     0,     0,     0,     0,  1141,     0,     0,
       0,  1144,     0,   523,   524,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,  1165,     0,   943,   617,  1168,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,  1608,     0,     0,   798,     0,
       0,     0,     0,     0,   521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   521,  1214,  1215,  1216,     0,     0,
     798,     0,     0,     0,     0,     0,  1222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     625,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   401,   521,     0,     0,     0,
     465,     0,     0,     0,  1257,     0,     0,     0,  1263,     0,
       0,     0,     0,   674,  1269,     0,     0,   521,     0,   465,
     465,     0,     0,     0,     0,  1279,  1280,     0,     0,     0,
       0,  1283,   465,     0,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   410,  1309,     0,
       0,  1311,   411,   412,   413,   414,     0,     0,     0,     0,
     415,   416,   417,   418,     0,     0,     0,     0,     0,   419,
       0,   420,     0,     0,     0,     0,     0,  1332,  1626,  1334,
    1335,     0,     0,     0,     0,   421,     0,     0,   422,     0,
       0,     0,   179,     0,     0,   180,     0,     0,   181,     0,
     182,     0,  1356,  1758,     0,     0,   757,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1376,     0,     0,     0,     0,     0,     0,  1382,
     451,     0,     0,     0,     0,     0,  1395,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1418,
    1419,     0,     0,     0,     0,   521,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,     0,     0,     0,  1448,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   423,   424,   425,     0,     0,     0,     0,   521,
       0,     0,     0,     0,   426,     0,     0,     0,   427,     0,
     428,   122,     0,     0,     0,     0,     0,  1472,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1473,  1474,  1475,
    1476,  1477,     0,     0,     0,     0,  1479,  1480,     0,  1481,
     921,   778,     0,   779,  1832,     0,     0,     0,     0,     0,
    1816,     0,     0,     0,     0,  1492,  1493,     0,     0,     0,
       0,     0,     0,  1496,  1497,     0,     0,     0,     0,     0,
       0,     0,  1501,  1502,  1820,     0,     0,     0,  1508,  1509,
       0,     0,     0,     0,   521,   521,     0,     0,     0,     0,
       0,     0,     0,     0,   973,   974,     0,     0,     0,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,   522,   522,  1541,
       0,   617,     0,     0,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,  1017,  1018,  1019,   617,     0,     0,     0,
       0,  1025,     0,     0,     0,     0,     0,  1575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1508,
    1509,     0,     0,     0,   521,     0,     0,     0,     0,     0,
       0,     0,  1591,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   588,     0,     0,   522,     0,
       0,  1069,     0,     0,     0,     0,  1607,     0,     0,     0,
       0,     0,     0,     0,   522,   522,     0,  1613,     0,     0,
    1618,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1097,  1826,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1640,
       0,     0,  1643,   521,  1646,   521,  1119,   522,     0,     0,
       0,     0,  1125,  1655,  1127,     0,  1658,     0,  1655,     0,
    1662,  1664,  2006,   598,  1672,  1673,     0,     0,     0,     0,
     522,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1203,     0,     0,     0,
     522,     0,     0,     0,  1742,     0,  1213,     0,     0,     0,
       0,     0,     0,     0,     0,  1751,  1752,  1753,     0,     0,
       0,     0,     0,     0,  1759,     0,  1761,     0,     0,     0,
       0,     0,     0,  1764,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1242,   521,     0,     0,
       0,     0,     0,  1782,  1783,     0,     0,     0,  1250,     0,
       0,     0,     0,     0,  1790,  1791,  1792,     0,     0,     0,
       0,     0,     0,     0,     0,  1803,     0,     0,   588,  1272,
       0,     0,     0,     0,     0,  1813,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   879,     0,     0,  1830,     0,     0,     0,
       0,     0,   889,   890,  1839,  1840,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,   917,
       0,     0,     0,     0,   522,     0,     0,     0,     0,     0,
    1869,     0,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   854,   613,   614,   615,   616,
     944,     0,     0,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   781,     0,
       0,     0,  1886,  1887,  1888,     0,     0,     0,   522,   522,
       0,     0,     0,  1889,     0,     0,     0,     0,  1892,  1893,
       0,     0,     0,     0,     0,     0,     0,  1425,     0,     0,
       0,  1901,     0,     0,     0,     0,     0,     0,   521,   521,
    1909,     0,  1910,     0,     0,     0,     0,  1939,  1918,  1919,
       0,     0,     0,     0,     0,     0,     0,   522,   522,   522,
       0,     0,     0,     0,     0,   522,     0,   521,     0,     0,
       0,     0,   521,  1938,     0,     0,     0,     0,     0,     0,
       0,  1470,     0,     0,     0,  1892,  1893,     0,     0,  1951,
       0,     0,  1954,     0,     0,     0,  1956,     0,     0,     0,
       0,     0,     0,     0,     0,   907,  1965,     0,     0,     0,
       0,     0,     0,     0,     0,   522,  1972,  1940,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1983,     0,     0,     0,     0,  1989,  1990,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,  1995,
       0,     0,  1996,  1995,     0,  1999,     0,   955,     0,     0,
       0,     0,     0,     0,     0,     0,  1513,  1514,     0,     0,
     522,     0,     0,     0,     0,     0,   522,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   521,   521,
       0,     0,     0,     0,     0,  2026,  2027,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2035,     0,     0,
       0,     0,     0,     0,     0,     0,  2044,     0,     0,     0,
       0,     0,   944,     0,  1169,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2056,  2057,
       0,     0,   521,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1589,     0,  2032,     0,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,  2081,  2082,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,  2095,     0,     0,
     617,     0,   521,   521,  2100,  2059,     0,     0,     0,  2103,
     522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   522,   521,     0,     0,     0,     0,     0,     0,
       0,  2073,     0,     0,     0,  1645,     0,  1647,   521,     0,
       0,     0,     0,   522,     0,     0,     0,  2134,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,  2107,  2145,     0,     0,     0,     0,     0,  2150,     0,
       0,  2151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,     0,  1186,  1187,
    1188,  1189,  2175,  1191,  1192,  1193,  1194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1206,
       0,  1208,     0,     0,     0,     0,     0,     0,  2193,  2194,
       0,     0,  1218,     0,     0,     0,     0,     0,     0,     0,
    1225,  1226,     0,  2200,  2201,     0,   521,     0,     0,  1237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2210,
       0,     0,     0,     0,   521,   521,   521,   521,   521,  1779,
       0,   522,     0,     0,  1989,     0,     0,     0,  2226,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,   178,  2246,   184,     0,     0,     0,
    2249,  2250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,     0,   522,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
    2277,  2278,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
    1341,  1343,  1344,     0,   617,     0,  1348,  1349,     0,     0,
    1352,  1353,  1354,  1355,     0,  1357,     0,     0,     0,     0,
    1363,     0,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
     522,   522,     0,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   464,     0,     0,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
    1907,  1908,   617,     0,   778,     0,   779,     0,     0,     0,
       0,     0,  1800,     0,     0,     0,     0,     0,  1447,     0,
    1449,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1937,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   556,   557,   558,   559,
     560,   561,     0,   563,   564,     0,     0,     0,     0,     0,
       0,     0,     0,   570,   571,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   581,     0,   173,
     401,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1510,     0,     0,     0,     0,     0,   522,
       0,   522,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2022,  2023,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   410,  2108,     0,     0,     0,   411,   412,   413,
     414,     0,     0,     0,     0,   415,   416,   417,   418,     0,
       0,     0,     0,     0,   419,     0,   420,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     421,     0,     0,   422,  2058,     0,     0,   179,     0,     0,
     180,     0,     0,   181,     0,   182,     0,     0,     0,     0,
       0,     0,     0,   715,     0,     0,    46,     0,     0,     0,
     724,   725,   726,     0,     0,     0,   730,   731,   732,   733,
     734,   735,   736,     0,   737,   451,     0,     0,     0,   738,
     739,     0,     0,   742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2098,  2099,     0,     0,     0,     0,
       0,  1627,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1666,     0,     0,   423,   424,   425,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   426,
       0,     0,     0,   427,     0,   428,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1703,  1704,  1705,  1706,
    1707,  1708,  1709,     0,     0,     0,     0,  1714,  1715,     0,
       0,     0,     0,     0,  1717,     0,     0,  1719,     0,  1832,
       0,  1723,     0,     0,  1725,  2187,  1870,     0,     0,     0,
       0,     0,     0,     0,     0,  1732,     0,     0,     0,     0,
       0,     0,     0,     0,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,  2202,     0,
       0,     0,   925,     0,     0,     0,     0,     0,  2233,     0,
       0,     0,     0,     0,     0,     0,  2214,  2215,  2216,  2217,
    2219,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   522,   522,     0,     0,     0,     0,
       0,     0,     0,  1798,     0,  1801,     0,     0,     0,  1808,
       0,  1810,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,   522,     0,
       0,     0,     0,     0,     0,  2258,     0,     0,     0,     0,
       0,     0,  1833,     0,     0,   218,   173,   401,     0,     0,
       0,     0,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   395,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     253,   254,   255,   256,   411,   412,   413,   414,   257,     0,
       0,     0,   415,   416,   417,   418,     0,     0,     0,     0,
       0,   419,     0,   420,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,   421,   266,     0,
     422,     0,  1894,     0,   522,   522,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   588,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,  2156,     0,     0,
       0,   617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1980,     0,
       0,  1981,     0,   277,   423,   424,   425,   278,   522,   522,
       0,     0,     0,   280,   281,   282,   426,   283,   284,   285,
     427,     0,   428,   122,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,     0,  1232,     0,
     286,   396,     0,     0,   522,     7,     8,   288,     0,     0,
    2015,  2016,   371,  2018,     0,     0,  1663,     0,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1249,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   792,    57,     0,     0,    60,   793,     0,
     794,   795,     0,   796,     0,     0,     0,     0,  2062,  2063,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,    98,    99,
     100,     0,   522,     0,     0,   792,    57,  2094,     0,    60,
     793,     0,   794,   795,     0,   796,     0,     0,     0,     0,
     522,   522,   522,   522,   522,     0,   598,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
      98,    99,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   818,     0,     0,     0,   522,
       0,     0,     0,     0,     0,   218,     6,   401,     0,     0,
       0,     0,   219,   220,   221,     0,  1440,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,     0,
       0,  1667,   403,   404,   405,   406,   407,   408,   409,   410,
     253,   254,   255,   256,   411,   412,   413,   414,   257,   258,
       0,     0,   415,   416,   417,   418,     0,     0,   259,   260,
     261,   419,     0,   420,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,   421,   266,     0,
     422,     0,     0,     0,   267,     0,     0,   268,     0,     0,
     269,     0,   270,     0,  1500,     0,     0,     0,     0,    42,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,    58,    59,     0,
     273,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,     0,     0,     0,  2267,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,   276,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   598,
       0,     0,     0,   277,   423,   424,   425,   278,   279,     0,
       0,     0,     0,   280,   281,   282,   426,   283,   284,   285,
     427,     0,   428,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   287,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   371,     0,     0,     0,  1668,     0,     0,   291,
       0,     0,   218,     6,   401,     0,  1628,  1629,     0,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   253,   254,   255,
     256,   411,   412,   413,   414,   257,   258,     0,     0,   415,
     416,   417,   418,     0,     0,   259,   260,   261,   419,     0,
     420,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,   421,   266,     0,   422,     0,     0,
       0,   267,     0,  1721,   268,     0,     0,   269,     0,   270,
       0,     0,  1728,     0,     0,     0,    42,     0,     0,     0,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,    58,    59,     0,   273,     0,   274,
       0,     0,   275,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,     0,    88,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   854,   613,   614,   615,   616,  1038,     0,     0,     0,
     617,     0,   276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1240,
     277,   423,   424,   425,   278,   279,     0,     0,     0,     0,
     280,   281,   282,   426,   283,   284,   285,   427,     0,   428,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   287,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,   371,
       0,     0,     0,   290,     0,     0,   291,     0,     0,   218,
     173,   401,     0,   450,     0,  1867,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   395,   240,
     241,   242,   243,   244,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   253,   254,   255,   256,   411,   412,
     413,   414,   257,     0,     0,     0,   415,   416,   417,   418,
       0,     0,     0,     0,     0,   419,     0,   420,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
      25,   421,   266,     0,   422,     0,     0,     0,   179,     0,
       0,   180,     0,     0,   181,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,   451,     0,     0,     0,
     617,     0,   778,     0,   779,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,  1241,     0,     0,     0,
     452,     0,     0,     0,     0,     0,     0,   277,   423,   424,
     425,   278,     0,     0,     0,     0,     0,   280,   281,   282,
     426,   283,   284,   285,   427,     0,   428,   122,     0,   453,
     454,   455,   456,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,   396,     0,     0,     0,     0,
       0,   288,     0,   457,   458,     0,   459,     0,   460,   218,
       6,   370,   461,   291,     0,     0,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,     0,     0,     0,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
      25,     0,   266,     0,     0,     0,     0,     0,   267,     0,
       0,   268,     0,     0,   269,     0,   270,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,    58,    59,     0,   273,     0,   274,     0,     0,   275,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,     0,    88,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,   276,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,   278,   279,     0,     0,     0,     0,   280,   281,   282,
       0,   283,   284,   285,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,   287,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,   371,   218,     6,     0,
     372,     0,   695,   291,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   260,   261,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,     0,     0,     0,     0,     0,   267,     0,     0,   268,
       0,     0,   269,     0,   270,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,    58,
      59,     0,   273,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,   278,
     279,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   520,     0,     0,     0,     0,     0,   288,
       0,     0,     0,     0,   371,   218,     6,  1767,     0,   591,
       0,   291,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   255,   256,     0,     0,     0,     0,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   260,
     261,     0,     0,     0,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,     0,   266,     0,
       0,     0,     0,     0,   267,     0,     0,   268,     0,     0,
     269,     0,   270,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,    58,    59,     0,
     273,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,     0,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,   276,  1022,     0,     0,     0,
       0,     0,     0,     0,   983,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,     0,   278,   279,     0,
       0,     0,     0,   280,   281,   282,     0,   283,   284,   285,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   287,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   371,   218,     6,     0,   290,     0,     0,   291,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
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
      80,     0,     0,     0,    84,     0,     0,     0,    88,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,   276,     0,     0,     0,  1862,     0,     0,
       0,  1863,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,   278,   279,     0,     0,     0,
       0,   280,   281,   282,     0,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   659,  1933,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     661,   218,     6,     0,   334,   591,     0,   291,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,   254,   255,   256,
       0,     0,     0,     0,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   260,   261,     0,     0,     0,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,    25,     0,   266,     0,     0,     0,     0,     0,
     267,     0,     0,   268,     0,     0,   269,     0,   270,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,    58,    59,     0,   273,     0,   274,     0,
       0,   275,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    84,     0,     0,     0,    88,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,   276,     0,     0,     0,  1914,     0,     0,     0,  1915,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       0,     0,     0,   278,   279,     0,     0,     0,     0,   280,
     281,   282,     0,   283,   284,   285,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   287,     0,     0,
       0,     0,     0,   288,     0,     0,     0,     0,   289,   218,
       6,     0,   290,     0,     0,   291,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,     0,     0,     0,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
      25,     0,   266,     0,     0,     0,     0,     0,   267,     0,
       0,   268,     0,     0,   269,     0,   270,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,    58,    59,     0,   273,     0,   274,     0,     0,   275,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,     0,    88,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,   276,
       0,     0,     0,  1945,     0,     0,     0,  1946,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,   278,   279,     0,     0,     0,     0,   280,   281,   282,
       0,   283,   284,   285,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,   287,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,   371,   218,     6,     0,
     290,     0,     0,   291,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   260,   261,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,     0,     0,     0,     0,     0,   267,     0,     0,   268,
       0,     0,   269,     0,   270,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,    58,
      59,     0,   273,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   276,     0,     0,
       0,  2119,     0,     0,     0,  2120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,   278,
     279,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   520,     0,     0,     0,     0,     0,   288,
       0,     0,     0,     0,   371,   218,     6,     0,   586,     0,
       0,   291,   219,   220,   221,     0,     0,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   255,   256,     0,     0,     0,     0,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   260,
     261,     0,     0,     0,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,     0,   266,     0,
       0,     0,     0,     0,   267,     0,     0,   268,     0,     0,
     269,     0,   270,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,    58,    59,     0,
     273,     0,   274,     0,     0,   275,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,     0,
      88,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,   276,     0,     0,     0,     0,
       0,     0,     0,   811,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,     0,   278,   279,     0,
       0,     0,     0,   280,   281,   282,     0,   283,   284,   285,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     286,   520,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   371,   218,     6,     0,     0,   591,     0,   291,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
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
      80,     0,     0,     0,    84,     0,     0,     0,    88,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,   276,     0,     0,     0,     0,     0,     0,
       0,   817,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,   278,   279,     0,     0,     0,
       0,   280,   281,   282,     0,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   287,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     629,   218,     6,     0,   290,     0,     0,   291,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,   254,   255,   256,
       0,     0,     0,     0,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   260,   261,     0,     0,     0,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,    25,     0,   266,     0,     0,     0,     0,     0,
     267,     0,     0,   268,     0,     0,   269,     0,   270,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,    58,    59,     0,   273,     0,   274,     0,
       0,   275,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    84,     0,     0,     0,    88,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,   276,     0,     0,     0,     0,     0,     0,     0,   819,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       0,     0,     0,   278,   279,     0,     0,     0,     0,   280,
     281,   282,     0,   283,   284,   285,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,   287,     0,     0,
       0,     0,     0,   288,     0,     0,     0,     0,   638,   218,
       6,     0,   290,     0,     0,   291,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,     0,     0,     0,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
      25,     0,   266,     0,     0,     0,     0,     0,   267,     0,
       0,   268,     0,     0,   269,     0,   270,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,    58,    59,     0,   273,     0,   274,     0,     0,   275,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,     0,    88,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,   276,
       0,     0,     0,     0,     0,     0,     0,   983,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,   278,   279,     0,     0,     0,     0,   280,   281,   282,
       0,   283,   284,   285,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,   520,     0,     0,     0,     0,
       0,   288,     0,     0,     0,     0,   371,   218,     6,     0,
     942,     0,  1424,   291,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   260,   261,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,     0,     0,     0,     0,     0,   267,     0,     0,   268,
       0,     0,   269,     0,   270,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,    58,
      59,     0,   273,     0,   274,     0,     0,   275,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,     0,    88,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   276,     0,     0,
       0,     0,     0,     0,     0,   984,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,   278,
     279,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   520,     0,     0,     0,     0,     0,   288,
     218,     6,     0,     0,   371,  1644,     0,   219,   220,   221,
       0,   291,   222,   223,   224,   225,   226,   227,   228,   229,
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
       0,    84,     0,     0,     0,    88,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
     276,     0,     0,     0,     0,     0,     0,     0,  1035,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,   278,   279,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   520,     0,     0,     0,
       0,     0,   288,   218,     6,     0,     0,   371,     0,     0,
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
      80,     0,     0,     0,    84,     0,     0,     0,    88,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,   276,     0,     0,     0,     0,     0,     0,
       0,  1145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,     0,     0,     0,   278,   279,     0,     0,     0,
       0,   280,   281,   282,     0,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   287,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     371,   218,     6,     0,  1775,     0,     0,   291,   219,   220,
     221,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   253,   254,   255,   256,
       0,     0,     0,     0,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   260,   261,     0,     0,     0,
     262,   263,   264,     0,     0,     0,     0,     0,     0,     0,
       0,   265,    25,     0,   266,     0,     0,     0,     0,     0,
     267,     0,     0,   268,     0,     0,   269,     0,   270,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,    58,    59,     0,   273,     0,   274,     0,
       0,   275,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    84,     0,     0,     0,    88,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,   276,     0,     0,     0,     0,     0,     0,     0,  1185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
       0,     0,     0,   278,   279,     0,     0,     0,     0,   280,
     281,   282,     0,   283,   284,   285,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   659,  1933,     0,     0,
       0,     0,     0,   288,     0,     0,     0,     0,   661,   218,
       6,     0,   334,     0,     0,   291,   219,   220,   221,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,   255,   256,     0,     0,
       0,     0,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,     0,     0,     0,   262,   263,
     264,     0,     0,     0,     0,     0,     0,     0,     0,   265,
      25,     0,   266,     0,     0,     0,     0,     0,   267,     0,
       0,   268,     0,     0,   269,     0,   270,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,    58,    59,     0,   273,     0,   274,     0,     0,   275,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,     0,    88,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,   276,
       0,     0,     0,     0,     0,     0,     0,  1195,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,     0,     0,
       0,   278,   279,     0,     0,     0,     0,   280,   281,   282,
       0,   283,   284,   285,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,   520,     0,     0,     0,     0,
       0,   288,   218,   173,   401,     0,   371,     0,     0,   219,
     220,   221,     0,   291,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   395,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   253,   254,   255,
     256,   411,   412,   413,   414,   257,     0,     0,     0,   415,
     416,   417,   418,     0,     0,     0,     0,     0,   419,     0,
     420,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,   421,   266,     0,   422,   218,   173,
     401,     0,     0,     0,     0,   219,   220,   221,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   395,   240,   241,
     242,   243,   244,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,  1667,   403,   404,   405,   406,   407,
     408,   409,   410,   253,   254,   255,   256,   411,   412,   413,
     414,   257,     0,     0,     0,   415,   416,   417,   418,     0,
       0,     0,     0,     0,   419,     0,   420,   262,   263,   264,
       0,     0,     0,     0,     0,     0,     0,     0,   265,    25,
     421,   266,     0,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   423,   424,   425,   278,     0,     0,     0,     0,     0,
     280,   281,   282,   426,   283,   284,   285,   427,     0,   428,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   396,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,   371,
       0,     0,     0,  1950,     0,     0,   291,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1196,
       0,     0,     0,     0,     0,     0,   277,   423,   424,   425,
     278,     0,     0,     0,     0,     0,   280,   281,   282,   426,
     283,   284,   285,   427,     0,   428,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,   396,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,   371,   218,   173,   401,  1832,
       0,     0,   291,   219,   220,   221,     0,     0,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   395,   240,   241,   242,   243,
     244,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   253,   254,   255,   256,   411,   412,   413,   414,   257,
       0,     0,     0,   415,   416,   417,   418,     0,     0,     0,
       0,     0,   419,     0,   420,   262,   263,   264,     0,     0,
       0,     0,     0,     0,     0,     0,   265,    25,   421,   266,
       0,   422,   218,   173,     0,   394,     0,     0,     0,   219,
     220,   221,     0,     0,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   395,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,   265,    25,     0,   266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,   423,   424,   425,   278,     0,
       0,     0,     0,     0,   280,   281,   282,   426,   283,   284,
     285,   427,     0,   428,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,   396,     0,     0,     0,     0,     0,   288,     0,
     218,   173,     0,   371,     0,     0,     0,   219,   220,   221,
     291,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   395,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,   278,   253,   254,   255,   256,     0,
     280,   281,   282,   257,   283,   284,   285,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,   286,   396,     0,
     265,    25,     0,   266,   288,   218,   173,     0,     0,   371,
       0,     0,   219,   220,   221,     0,   291,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   395,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,   255,   256,     0,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   263,   264,     0,     0,     0,
       0,     0,     0,     0,     0,   265,    25,     0,   266,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,   277,     0,
       0,   617,   278,     0,     0,     0,     0,     0,   280,   281,
     282,  1197,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   396,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,     0,     0,
       0,   641,     0,     0,   291,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1198,     0,     0,
       0,     0,     0,   277,     0,     0,     0,   278,     0,     0,
       0,     0,     0,   280,   281,   282,     0,   283,   284,   285,
       0,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     659,   660,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,   661,   218,   173,     0,   334,     0,   909,   291,
     219,   220,   221,     0,     0,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   395,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,   256,     0,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   263,   264,     0,     0,     0,     0,     0,
     218,   173,     0,   265,    25,     0,   266,   219,   220,   221,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   395,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    25,     0,   266,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
       0,   277,     0,     0,     0,   278,  1199,     0,     0,     0,
       0,   280,   281,   282,     0,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   396,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     371,     0,     0,     0,     0,     0,     0,   291,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,     0,     0,   277,     0,
    1204,     0,   278,     0,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   396,     0,     0,     0,
       0,     0,   288,   218,   173,     0,  1375,   371,  1133,     0,
     219,   220,   221,     0,   291,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   395,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
     255,   256,     0,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,   263,   264,     0,     0,     0,     0,     0,
       0,     0,     0,   265,    25,     0,   266,   218,   173,     0,
    1540,     0,     0,     0,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   395,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,     0,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,   277,     0,     0,   617,   278,     0,     0,     0,     0,
       0,   280,   281,   282,  1205,   283,   284,   285,     0,     0,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   396,
       0,     0,     0,     0,     0,   288,     0,     0,     0,     0,
     371,     0,     0,     0,     0,     0,     0,   291,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1207,     0,     0,     0,     0,   277,     0,     0,     0,   278,
       0,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   396,     0,     0,     0,     0,     0,   288,
     218,   173,     0,  1606,   371,     0,     0,   219,   220,   221,
       0,   291,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   395,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,   218,   173,     0,
     265,    25,     0,   266,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   395,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,   277,     0,
       0,     0,   278,  1325,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   396,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,     0,     0,
       0,     0,     0,     0,   291,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,     0,     0,   277,     0,  1351,     0,   278,
       0,     0,     0,     0,     0,   280,   281,   282,     0,   283,
     284,   285,     0,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   286,   396,     0,     0,     0,     0,     0,   288,
     218,   173,     0,     0,   371,  1660,     0,   219,   220,   221,
       0,   291,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   395,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,     0,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     263,   264,     0,     0,     0,     0,     0,   218,   173,     0,
     265,    25,     0,   266,   219,   220,   221,     0,     0,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   395,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,   255,   256,     0,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,   263,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   265,    25,     0,
     266,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,   277,     0,
       0,     0,   278,  1434,     0,     0,     0,     0,   280,   281,
     282,     0,   283,   284,   285,     0,     0,     0,   122,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   286,   396,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,   371,  1997,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,   277,     0,     0,   617,   278,
       0,     0,     0,     0,     0,   280,   281,   282,  1438,   283,
     284,   285,     0,     0,     0,   122,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,   286,   396,    43,    44,    45,    46,     0,   288,
      48,     0,     0,     0,   371,     0,     7,     8,     0,   792,
      57,   291,     0,    60,   793,     0,   794,   795,     0,   796,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    81,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   792,    57,     0,     0,    60,   793,     0,
     794,   795,     0,   796,    98,    99,   100,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    98,    99,
     100,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   792,    57,     0,     0,
      60,   793,     0,   794,   795,     0,   796,     0,     0,     0,
       0,   991,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       7,     8,    43,    44,    45,    46,     0,     0,    48,     0,
       0,    98,    99,   100,     0,  1016,     0,   792,    57,     0,
       0,    60,   793,     0,   794,   795,     0,   796,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1071,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
     792,    57,     0,     0,    60,   793,     0,   794,   795,     0,
     796,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,  1073,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,    98,    99,   100,     7,     8,
       0,   792,    57,     0,     0,    60,   793,     0,   794,   795,
       0,   796,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    98,    99,   100,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,  1274,     0,   792,    57,     0,     0,    60,   793,
       0,   794,   795,     0,   796,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    81,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   792,    57,
       0,     0,    60,   793,     0,   794,   795,     0,   796,    98,
      99,   100,     0,  1276,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,    98,    99,   100,     0,     0,     7,     8,
    1534,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,  1277,     0,     0,     0,
       0,     0,     0,  1535,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
    1296,     7,     8,     0,   792,    57,     0,     0,    60,   793,
       0,   794,   795,     0,   796,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    81,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   792,    57,
       0,     0,    60,   793,     0,   794,   795,     0,   796,    98,
      99,   100,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    98,    99,   100,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
       0,   792,    57,     0,     0,    60,   793,     0,   794,   795,
       0,   796,     0,     0,     0,     0,  1315,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     7,     8,    43,    44,    45,
      46,     0,     0,    48,     0,     0,    98,    99,   100,     0,
    1333,     0,   792,    57,     0,     0,    60,   793,     0,   794,
     795,     0,   796,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1370,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   792,    57,     0,     0,    60,
     793,     0,   794,   795,     0,   796,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,  1532,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
      98,    99,   100,     0,     0,     0,   792,    57,     0,     0,
      60,   793,     0,   794,   795,     0,   796,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    81,    -4,    -4,     0,     0,     0,
       0,     0,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,    98,    99,   100,   617,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,  1582,     0,     0,  2178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,  2235,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,    -4,     0,     0,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     9,    10,    11,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1710,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    18,    19,    20,    21,    22,
       0,    23,    24,     0,    25,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,    42,    43,    44,
      45,    46,    47,     0,    48,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,    93,    94,    95,     0,
       0,     0,    96,     0,     0,     0,     0,    97,    98,    99,
     100,   173,   401,   101,     0,   102,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,   122,   123,     0,     0,     0,   402,   403,   404,   405,
     406,   407,   408,   409,   410,     0,     0,     0,     0,   411,
     412,   413,   414,   173,   401,     0,     0,   415,   416,   417,
     418,     0,     0,     0,     0,     0,   419,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   421,     0,     0,   422,     0,     0,     0,   179,
     432,   401,   180,     0,     0,   181,     0,   182,   402,   403,
     404,   405,   406,   407,   408,   409,   410,     0,    46,     0,
       0,   411,   412,   413,   414,     0,     0,     0,     0,   415,
     416,   417,   418,     0,     0,     0,     0,   451,   419,     0,
     420,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   421,     0,     0,   422,   411,   412,
     413,   414,     0,     0,     0,     0,   415,   416,   417,   418,
       0,     0,     0,     0,     0,   419,     0,   420,     0,     0,
       0,     0,     0,     0,     0,   401,     0,     0,     0,     0,
       0,   421,     0,     0,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   423,
     424,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,   427,     0,   428,   122,   402,
     403,   404,   405,   406,   407,   408,   409,   410,     7,     8,
       0,     0,   411,   412,   413,   414,     0,     0,     0,     0,
     415,   416,   417,   418,     0,     0,     0,     0,     0,   419,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   423,   424,   425,     0,   421,     0,     0,   422,     0,
       0,     0,     0,   426,     0,     0,     0,   427,     0,   428,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   423,   424,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     426,     0,     0,     0,   427,     0,   428,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   792,    57,
       0,     0,    60,   793,     0,   794,   795,     0,   796,     0,
       0,     0,  1079,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,     0,
    1080,     0,   423,   424,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   426,     0,     0,     0,   427,     0,
     428,     0,     0,    98,    99,   100,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1711,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1712,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1860,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1984,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1985,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2017,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2089,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2146,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
       0,     0,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2147,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2162,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2196,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2223,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2228,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2229,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,   851,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,  1114,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,  1172,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,  1220,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
       0,     0,  1221,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,     0,     0,     0,
       0,  1266,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,     0,     0,
    1299,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,     0,  1313,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
       0,     0,   617,     0,     0,     0,     0,     0,  1320,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,     0,     0,  1381,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,  1401,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,  1437,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,  1486,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,  1487,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
       0,     0,  1488,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,     0,     0,     0,
       0,  1491,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,     0,     0,
    1536,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,     0,  1612,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
       0,     0,   617,     0,     0,     0,     0,     0,  1912,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,     0,     0,  1923,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,  1964,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,  2038,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,  2054,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,  2066,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
       0,     0,  2090,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,     0,     0,     0,
       0,  2125,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,     0,     0,
    2135,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,     0,     0,  2136,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
       0,     0,   617,     0,     0,     0,     0,     0,  2160,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,     0,     0,  2209,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,     0,     0,  2248,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,  2266,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,     0,     0,  2284,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,     0,     0,  2285,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
       0,   755,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,     0,   975,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
       0,     0,   617,     0,     0,     0,     0,  2031,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,  1045,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,  1090,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,  1245,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,  1314,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,  1316,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,     0,     0,  1323,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   718,   613,   614,   615,   616,     0,     0,
       0,     0,   617,     0,     0,     0,  1324,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     718,   613,   614,   615,   616,     0,     0,     0,     0,   617,
       0,     0,     0,  1416,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   718,   613,   614,
     615,   616,     0,     0,     0,     0,   617,     0,     0,     0,
    1430,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   718,   613,   614,   615,   616,     0,
       0,     0,     0,   617,     0,     0,     0,  1641,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,     0,     0,  1731,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   718,   613,
     614,   615,   616,     0,     0,     0,     0,   617,     0,     0,
       0,  1784,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   718,   613,   614,   615,   616,
       0,     0,     0,     0,   617,     0,     0,     0,  1976,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   718,   613,   614,   615,   616,     0,     0,     0,
       0,   617,     0,     0,     0,  2021,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   718,
     613,   614,   615,   616,     0,     0,     0,     0,   617,     0,
       0,     0,  2039,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   832,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   833,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   834,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   836,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   837,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   838,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   840,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   841,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   842,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   843,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   844,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   845,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   846,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   848,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   849,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   850,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,   922,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,   956,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1005,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1022,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1030,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1032,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1033,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1039,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1040,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1078,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1089,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1150,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1154,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1166,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1244,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1254,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1255,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1256,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1265,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1267,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1268,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1298,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1300,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1301,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1302,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1303,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1304,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1305,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1306,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1312,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1326,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1328,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1369,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1415,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1429,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1642,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1677,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1718,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1730,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1847,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1849,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1852,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1859,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1913,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  1922,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  1949,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  2020,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  2087,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  2088,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   718,   613,   614,   615,   616,     0,     0,     0,     0,
     617,     0,  2222,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   718,   613,   614,   615,
     616,     0,     0,     0,     0,   617,     0,  2263
};

static const yytype_int16 yycheck[] =
{
       3,  1769,     3,   327,  1293,  1495,  1297,     4,  1815,   149,
    1817,     4,    25,     5,    70,    71,     4,    73,   656,   657,
     775,   163,    25,     4,    96,    64,   781,     6,     4,     4,
       4,  2000,     5,   108,     6,   461,     6,     6,   108,   112,
       5,   114,     5,     7,     4,  1804,    14,     6,     6,     4,
       4,   167,     6,    56,   102,     6,     6,   105,   144,     4,
     108,   108,     4,   264,     4,   105,     7,   268,   108,     6,
       4,     4,   108,   121,   257,   258,   149,   257,   258,     9,
       9,   121,    85,   266,   144,     4,   133,     7,    91,     0,
       9,    36,    37,    96,    36,    37,     4,   133,   101,     4,
       9,   263,   162,    36,    37,   178,    94,   269,  1867,   112,
     196,   184,     6,   173,   174,   175,  1884,     6,     6,   179,
     180,   260,     4,   262,   248,   249,   248,   249,    36,    37,
     269,    36,    37,   205,   105,   248,   249,   108,     6,   110,
     102,   265,     6,   215,   165,   144,   149,   269,   102,   150,
       6,   154,   155,   156,    36,    37,   269,   261,   263,   121,
     163,     9,     8,   162,   269,   269,   111,   112,   266,   111,
     112,   269,   193,     9,   173,   174,   175,     4,   111,   112,
     179,   180,   261,     9,   108,   260,  2155,   266,   209,   210,
     260,   260,   260,   105,   262,   621,   108,   200,   266,   260,
     169,   269,   205,   111,   112,   265,   209,   210,   260,   181,
     261,   181,   215,   216,   217,   260,   204,   262,   269,     7,
     259,   260,   261,   339,     7,   248,   249,   261,   261,   111,
     112,   248,   249,  1723,     7,   269,   269,   276,   231,   311,
     312,   313,   358,   231,     6,     7,   269,   264,   193,   194,
     231,   193,   194,   208,     7,   231,   231,   231,   253,   254,
    2028,     7,     6,  1552,   259,   262,   265,   264,   261,   272,
     263,   268,   264,   260,   330,   331,   264,   264,   291,   351,
     352,   353,   338,   339,   287,   264,   267,   290,   291,   264,
     264,   264,   233,   234,   235,   236,   722,   369,     6,   264,
     260,   264,   266,   306,   307,   264,   264,   310,   311,   312,
     313,     6,   231,   264,   264,  2083,   257,   258,   321,   435,
     260,   437,   325,   260,   327,   266,   260,   264,   444,   260,
     260,   260,   262,   262,  1089,  1090,   266,   266,   257,   258,
     260,   260,   262,   262,   261,   264,   349,   266,   351,   352,
     353,   260,   269,   262,   248,   249,   183,   184,   185,   186,
     248,   249,     6,   789,    56,   260,   369,   262,   195,   372,
     197,   198,   199,   200,   201,   243,   244,   450,   205,   206,
     806,   208,   260,  2190,   248,   249,   264,   243,   244,   264,
     816,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   257,
     258,     6,   260,   259,   262,   263,   265,   261,   266,   265,
     269,   257,   258,   565,   260,   269,   262,   261,   248,   249,
     266,   257,   258,   262,   260,   269,   262,   440,   265,   442,
     266,     4,   260,   446,   447,   233,   234,   235,   236,   269,
     233,   234,   235,   236,   260,   248,   249,  2225,   264,   462,
     233,   234,   235,   236,   265,   261,   469,     8,   269,   257,
     258,     6,   149,   269,   257,   258,   269,   154,   155,   156,
     233,   234,   235,   236,   257,   258,   262,   233,   234,   235,
     236,   494,   248,   249,   248,   249,   248,   249,   924,   248,
     249,   248,   249,   261,   576,   248,   249,  2275,     4,   105,
     583,   269,   108,   269,   110,   269,   264,   520,   248,   249,
     269,   260,   269,   200,   216,   121,   269,   260,  2018,   645,
     123,   647,   648,  1171,   248,   249,   260,   248,   249,   269,
     217,   105,   545,   265,   108,   109,   110,   269,   664,   248,
     249,   554,   555,   264,   260,   269,   559,   121,   561,   562,
     563,   564,   565,   260,   248,   249,   260,   683,   571,   582,
     269,   584,   575,   576,   577,   260,   579,   580,   581,   582,
     272,   584,   260,   586,   726,   269,   149,   150,   151,   152,
     248,   249,   155,     8,   710,   108,   144,   110,   654,   655,
     260,   164,   262,   659,   264,   168,   102,   248,   249,   612,
     106,   269,   260,   260,   162,   618,   112,   113,   310,   115,
     116,   266,   144,   268,   188,   173,   174,   175,   269,   321,
     265,   179,   180,   325,   269,   775,   260,   640,   641,   755,
     162,   137,   144,   248,   249,   260,   248,   249,   260,   248,
     249,   173,   174,   175,   108,   656,   657,   179,   180,   265,
     162,   248,   249,   269,   269,  1091,   739,   269,   260,  1307,
     269,   173,   174,   175,   248,   249,   265,   179,   180,     6,
     269,   261,   269,   263,   257,   258,   689,   690,   691,   269,
     261,   264,   263,   264,   697,   269,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   260,   265,   719,   265,   259,   269,
     261,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     743,   734,   735,   736,   737,   738,     6,   740,   741,   742,
     743,   744,   260,   265,   747,   149,   150,   248,   249,   248,
     249,   155,   110,   265,   446,   447,   795,   269,   831,   248,
     249,   102,   765,   440,   105,   264,  1521,   108,   269,   110,
     462,   260,   149,   150,   261,   264,   263,   780,   155,   261,
     121,   263,   269,   786,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   802,
     803,   264,  1228,   259,  1230,   808,   261,   810,   263,   108,
     813,   814,   264,   953,   269,   257,   258,  1243,   260,   822,
     262,   824,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     248,   249,   265,   264,   259,   265,   269,  1273,   264,   269,
     265,   854,   260,   856,   260,   105,   264,   250,   251,   252,
     253,   254,  1617,   979,   265,   261,   259,   263,   269,   264,
     562,     3,  1627,   269,   257,   258,   265,   260,   264,   262,
     269,   264,   559,   575,   561,   577,   563,   564,  2179,   892,
     261,   264,   263,   966,   260,    27,   265,   265,   269,   902,
     269,   269,   579,   580,  1044,   105,   257,   258,   265,   260,
    1336,   262,   269,  1339,  1340,   265,   265,   265,   108,   269,
     269,   269,  2211,   926,     6,   265,   982,   105,   265,   269,
     265,    63,   269,   989,   269,   108,   265,   993,  1364,   942,
     269,   108,   265,   265,   265,  2236,   269,   269,   269,  1089,
    1090,   954,   248,   249,   250,   251,   252,   253,   254,     4,
     963,  1387,     4,   259,  2253,   265,  1106,   265,     4,   269,
     265,   269,   975,   265,   269,   265,   265,   269,   265,   269,
     269,     4,   269,   265,   260,   117,   262,   269,  1414,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,  1428,   265,   265,     6,   259,   269,   269,  1435,
     265,   265,   260,   260,   269,   269,   261,   149,   263,   264,
    1093,   265,   154,   155,   156,   269,   265,   260,   265,   265,
     269,   163,   269,   269,   265,   265,   265,   265,   269,   269,
     269,   269,   265,   265,   262,   260,   269,   269,   725,     8,
     727,   728,   729,   730,   731,   732,   262,   734,   735,   736,
     737,     6,   265,   740,   741,   742,   269,  1391,   200,     6,
     265,   265,   265,   765,   269,   269,   269,   268,   265,   265,
     265,  1084,   269,   269,   269,   217,   265,     6,   265,  1092,
     269,  1147,   269,   268,   265,   265,   265,  1100,   269,   269,
     269,   260,   265,   262,  1244,  1245,   269,     4,   264,     6,
    1113,   264,   260,     9,   260,  1118,  1754,  1755,   260,   260,
     260,   264,   260,   260,   196,   196,   258,     4,     5,   196,
     264,   133,   260,   260,   260,   260,   813,   196,   260,   260,
     264,   260,   274,   275,   264,  1148,  1149,   824,  1151,  1152,
    1153,   260,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,   264,     4,  1167,   264,   264,   264,   260,   260,
    1171,   260,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   260,   260,   260,   260,    62,    63,    64,    65,     6,
       6,     6,   262,    70,    71,    72,    73,     7,   264,   264,
     264,   264,    79,   264,    81,   262,  1209,  1210,  1211,   262,
     262,     6,     6,   260,   260,   264,   196,   260,    95,   260,
     260,    98,   260,   260,     6,   102,   260,   262,   105,     6,
       6,   108,  1235,   110,   926,   264,     8,     6,     8,   260,
     264,     7,     6,     6,   121,   264,   264,   264,  1251,  1252,
    1253,   265,    97,   269,   269,   261,     7,     6,     6,   264,
     264,   261,    67,   140,   259,   264,   264,   264,   264,     8,
       7,   963,   266,     7,   260,  1415,  1416,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,  1620,     6,   264,     7,
     259,     6,   261,     7,   263,  1308,  1307,     6,   440,     6,
     265,   193,   264,   261,   265,   265,   263,     6,   264,   451,
       7,     6,   266,   262,  1327,   260,  1329,  1330,   264,     6,
       6,     6,     6,     6,   261,   212,   213,   214,   262,  1342,
       7,   473,     7,     7,  1347,     7,     7,   224,  1351,     7,
       7,   228,     7,   230,   231,     7,   488,  1360,     7,  1362,
       7,     7,  1365,     7,     7,     7,  1439,     7,  1441,   264,
       6,   261,   263,   261,     7,  1378,   269,   269,     7,   265,
     257,   258,   269,   266,   269,   265,   264,   264,  1391,   266,
     264,     4,  1084,   266,     6,  1821,  2034,   265,   265,   144,
     264,     7,     6,   266,     7,     7,     7,   266,  1100,   261,
     261,   269,   269,  1416,     9,   269,   263,   261,  1421,   268,
    1423,   196,     7,   165,     6,   265,   264,   559,     6,   561,
       6,   563,   564,   565,    49,    49,   266,   260,  1441,   264,
     260,  1118,   264,     7,     7,   266,   260,   579,   580,   260,
    1453,     7,   196,   266,  1457,   261,  1148,  1149,     7,  1151,
    1152,  1153,   269,  1155,  1156,  1157,  1158,  1159,  1160,  1161,
    1162,  1163,  1164,     7,     7,     6,   261,  1617,   269,     7,
       7,     7,     7,     7,     4,   120,  1628,  1629,     6,  1605,
     264,     7,   260,  1609,     6,  1551,     7,     7,     7,     7,
       7,     7,     7,   264,   102,  1829,     6,     6,     6,   108,
       7,     7,  1515,  1516,  1517,     6,     6,  1209,     7,     7,
    1523,  1524,  1525,     4,   267,   261,     6,     6,  1601,   269,
     662,   269,   264,  1210,  1211,   264,   264,     6,   265,  1542,
       7,     6,   262,  1235,     6,     6,   260,   260,   264,     6,
    1553,     6,     6,   265,   686,   266,     6,     6,  1561,  1251,
     263,     6,  1565,   269,     6,   137,     6,     6,     6,     6,
       6,     6,     6,  1576,     6,  1578,     6,     6,     6,     6,
       5,   265,   261,   261,     6,     6,     4,     6,   269,  1729,
    1663,     7,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   264,   734,   735,   736,   737,     6,     6,   740,   741,
     742,   264,     7,   264,   264,     6,  1308,  1620,   750,   264,
       6,   753,     6,   262,  1680,  1628,  1629,   759,   265,     6,
     264,  1634,   264,   264,   264,  1327,   264,  1329,  1330,   264,
     264,   264,   192,     6,   261,   264,     6,   269,   269,  1652,
     266,   269,     7,   260,   264,     6,     6,   265,     6,     6,
    1663,     4,   794,   260,   796,  1668,   260,     7,     6,     6,
    1347,     6,     6,   144,  1351,   106,     6,  1750,     5,   269,
     264,   813,     6,  1360,   261,  1362,  1378,     6,  1365,   264,
    1832,   264,   824,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,     6,
     269,   144,     6,   259,  1770,  1771,  1772,  1773,  1774,  1775,
       6,   144,     6,     6,  1797,     6,     6,     6,   269,   261,
     269,  1804,  1805,     6,     6,     6,     6,     6,  1741,  1416,
     269,   264,   264,  1746,  1747,     6,  2070,     6,     6,  1441,
    1823,   264,     7,  1754,  1755,   148,     6,     5,   261,     6,
     264,  1453,   264,   264,     6,  1457,  1769,     6,     6,   264,
     264,     7,  1775,   265,     6,     6,   191,  1780,   265,   264,
       7,   265,   265,   261,     6,     6,  1789,     6,   265,     6,
     266,     6,   264,     6,     6,   265,  1799,     6,     6,  1802,
       6,   261,     6,     6,   194,   264,   264,     6,   260,   265,
       6,     6,   265,   264,   261,  1818,   264,     6,   264,  1822,
     264,   144,   265,  1515,  1516,  1517,  1829,     6,  1831,  1832,
       6,  1523,  1524,  1525,     6,     6,     6,     6,   264,     6,
     264,   261,     6,     6,     6,     6,   978,     6,   980,   981,
    1542,   265,   265,     6,   264,     6,   264,     6,     6,   264,
       6,  1553,   994,     6,  1867,     6,     6,     6,  1427,  1561,
    2192,   491,  1489,  1675,  2001,  1737,  1961,  1452,     3,     3,
       3,  1884,  1014,  1102,  1576,     3,  1578,   633,  1598,  2030,
    1963,     3,  1629,  1896,  1897,  1822,   813,  1804,    -1,    -1,
      -1,    -1,    -1,    -1,  1036,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1921,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2043,    -1,    -1,
    1933,    -1,    -1,  2006,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1634,  1075,    -1,    -1,    -1,  1950,    -1,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,  1663,    -1,   259,    -1,  1652,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1987,    -1,  1118,    -1,    -1,    -1,
      -1,  2047,  2048,  2049,  2050,  2051,    -1,    -1,    -1,  2002,
      -1,    -1,    -1,    -1,  2007,    -1,    -1,  2010,  2011,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2140,  2028,    -1,    -1,  2031,    -1,
      -1,    -1,    -1,  2034,    -1,    -1,    -1,    -1,    -1,  2042,
      -1,    -1,    -1,  2046,    -1,    -1,    -1,    -1,    -1,  1741,
      -1,    -1,    -1,    -1,    -1,  2111,    -1,    -1,    -1,  2115,
      -1,    -1,    -1,    -1,  2180,    -1,    -1,  2070,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,  1210,  1211,
    2083,    -1,    -1,  2156,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1789,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2112,
    2166,    -1,    -1,    -1,  2170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1799,    -1,    -1,  1802,  1818,    -1,    -1,    -1,
    2186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1831,
      -1,    -1,    -1,  1275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2164,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2231,  2232,    -1,    -1,  2182,
    2183,  2184,  2185,  2186,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,  1884,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,  1347,   259,    -1,    -1,  1351,
      -1,    -1,  2225,    -1,    -1,    -1,    -1,    -1,  1360,  1921,
    1362,    -1,    -1,  1365,    -1,    -1,    -1,    -1,  2241,    -1,
    1372,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,  2262,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2275,    -1,    -1,    -1,    -1,    -1,  2281,  2282,
     108,    -1,    -1,    -1,  1416,    -1,    -1,    -1,    -1,    -1,
      -1,  2294,    -1,   121,    -1,  1987,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    -1,  2028,   165,    -1,    -1,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2042,    -1,    -1,    -1,    -1,     6,    -1,   185,   186,   187,
      -1,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
     198,   199,    -1,   201,   202,   203,   204,    -1,    -1,    -1,
      -1,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2083,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,     6,    -1,    -1,    -1,
    2112,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   286,   287,
     288,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   305,   306,   307,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,  1628,  1629,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   333,   334,    -1,    -1,    -1,
      -1,   339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1652,   349,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   371,   372,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   382,    -1,   384,   385,    -1,   387,
      -1,    -1,    -1,   391,   392,   393,    -1,    -1,   396,    -1,
      -1,    -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2275,    -1,  2262,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,  2281,  2282,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,   442,   443,    -1,  2294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,  1799,   496,   259,
    1802,    -1,    -1,   501,    -1,    -1,    -1,   505,    -1,    -1,
      -1,    -1,    -1,  1815,    -1,  1817,    -1,    -1,    -1,    -1,
      -1,   519,   520,    -1,    -1,    -1,    -1,   525,    -1,    -1,
    1832,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,   552,   553,   554,   555,    -1,   557,
     558,    -1,   560,    -1,    -1,  1867,    -1,    -1,    -1,    -1,
      -1,    -1,   570,    -1,    -1,   573,   574,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,   586,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
      -1,   619,   620,    -1,    -1,    -1,    -1,    -1,     6,   627,
     628,   629,    -1,    -1,    -1,    -1,    -1,   635,   636,   637,
     638,    -1,   640,   641,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   659,   660,   661,    -1,    -1,    -1,   665,   666,   667,
     668,   669,   670,   671,   672,   673,    -1,    -1,    -1,    -1,
      -1,   679,   680,    -1,   682,    -1,    -1,   685,    -1,    -1,
      -1,   689,   690,   691,   692,    -1,    -1,    -1,   696,   697,
     698,   699,   700,    -1,    -1,   703,    -1,   705,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   715,    -1,    -1,
     718,    -1,   720,   721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   733,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   747,
      -1,    -1,    -1,    -1,    -1,    -1,   754,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   762,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   780,    -1,   782,    -1,    -1,    -1,    -1,   787,
     788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   802,    -1,   804,   805,    -1,    -1,
     808,    -1,   810,   811,    -1,    -1,    -1,   815,    -1,   817,
      -1,   819,  2124,    -1,    -1,    -1,    -1,   825,    -1,    -1,
      -1,   829,    -1,   209,   210,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,   852,    -1,   854,   259,   856,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,     6,    -1,    -1,  2190,    -1,
      -1,    -1,    -1,    -1,   892,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   902,   903,   904,   905,    -1,    -1,
    2212,    -1,    -1,    -1,    -1,    -1,   914,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   942,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,   954,    -1,    -1,    -1,
    2262,    -1,    -1,    -1,   962,    -1,    -1,    -1,   966,    -1,
      -1,    -1,    -1,   349,   972,    -1,    -1,   975,    -1,  2281,
    2282,    -1,    -1,    -1,    -1,   983,   984,    -1,    -1,    -1,
      -1,   989,  2294,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,  1006,    -1,
      -1,  1009,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,  1035,     6,  1037,
    1038,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,
     110,    -1,  1060,     6,    -1,    -1,   442,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1080,    -1,    -1,    -1,    -1,    -1,    -1,  1087,
     140,    -1,    -1,    -1,    -1,    -1,  1094,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1107,
    1108,    -1,    -1,    -1,    -1,  1113,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,    -1,    -1,    -1,    -1,  1167,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,
     230,   231,    -1,    -1,    -1,    -1,    -1,  1185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1195,  1196,  1197,
    1198,  1199,    -1,    -1,    -1,    -1,  1204,  1205,    -1,  1207,
     586,   261,    -1,   263,   264,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,  1223,  1224,    -1,    -1,    -1,
      -1,    -1,    -1,  1231,  1232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1240,  1241,     6,    -1,    -1,    -1,  1246,  1247,
      -1,    -1,    -1,    -1,  1252,  1253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   640,   641,    -1,    -1,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   209,   210,  1287,
      -1,   259,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,   689,   690,   691,   259,    -1,    -1,    -1,
      -1,   697,    -1,    -1,    -1,    -1,    -1,  1325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1337,
    1338,    -1,    -1,    -1,  1342,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   290,    -1,
      -1,   747,    -1,    -1,    -1,    -1,  1374,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,   307,    -1,  1385,    -1,    -1,
    1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   780,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,
      -1,    -1,  1420,  1421,  1422,  1423,   802,   349,    -1,    -1,
      -1,    -1,   808,  1431,   810,    -1,  1434,    -1,  1436,    -1,
    1438,  1439,     7,     8,  1442,  1443,    -1,    -1,    -1,    -1,
     372,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   892,    -1,    -1,    -1,
     442,    -1,    -1,    -1,  1522,    -1,   902,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1533,  1534,  1535,    -1,    -1,
      -1,    -1,    -1,    -1,  1542,    -1,  1544,    -1,    -1,    -1,
      -1,    -1,    -1,  1551,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   942,  1565,    -1,    -1,
      -1,    -1,    -1,  1571,  1572,    -1,    -1,    -1,   954,    -1,
      -1,    -1,    -1,    -1,  1582,  1583,  1584,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1593,    -1,    -1,   520,   975,
      -1,    -1,    -1,    -1,    -1,  1603,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   545,    -1,    -1,  1624,    -1,    -1,    -1,
      -1,    -1,   554,   555,  1632,  1633,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,   581,
      -1,    -1,    -1,    -1,   586,    -1,    -1,    -1,    -1,    -1,
    1668,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     612,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,    -1,
      -1,    -1,  1710,  1711,  1712,    -1,    -1,    -1,   640,   641,
      -1,    -1,    -1,  1721,    -1,    -1,    -1,    -1,  1726,  1727,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,    -1,    -1,
      -1,  1739,    -1,    -1,    -1,    -1,    -1,    -1,  1746,  1747,
    1748,    -1,  1750,    -1,    -1,    -1,    -1,     6,  1756,  1757,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   689,   690,   691,
      -1,    -1,    -1,    -1,    -1,   697,    -1,  1775,    -1,    -1,
      -1,    -1,  1780,  1781,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1167,    -1,    -1,    -1,  1793,  1794,    -1,    -1,  1797,
      -1,    -1,  1800,    -1,    -1,    -1,  1804,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   571,  1814,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   747,  1824,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1838,    -1,    -1,    -1,    -1,  1843,  1844,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   780,  1857,
      -1,    -1,  1860,  1861,    -1,  1863,    -1,   623,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1252,  1253,    -1,    -1,
     802,    -1,    -1,    -1,    -1,    -1,   808,    -1,   810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1896,  1897,
      -1,    -1,    -1,    -1,    -1,  1903,  1904,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1915,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,
      -1,    -1,   854,    -1,   856,  1933,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1946,  1947,
      -1,    -1,  1950,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1342,    -1,     6,    -1,
     892,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     902,    -1,    -1,    -1,    -1,    -1,  1984,  1985,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,  2005,    -1,    -1,
     259,    -1,  2010,  2011,  2012,     6,    -1,    -1,    -1,  2017,
     942,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   954,  2031,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,  1421,    -1,  1423,  2046,    -1,
      -1,    -1,    -1,   975,    -1,    -1,    -1,  2055,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,     6,  2080,    -1,    -1,    -1,    -1,    -1,  2086,    -1,
      -1,  2089,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   862,   863,   864,   865,
     866,   867,   868,   869,   870,   871,   872,    -1,   874,   875,
     876,   877,  2120,   879,   880,   881,   882,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   895,
      -1,   897,    -1,    -1,    -1,    -1,    -1,    -1,  2146,  2147,
      -1,    -1,   908,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     916,   917,    -1,  2161,  2162,    -1,  2164,    -1,    -1,   925,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2177,
      -1,    -1,    -1,    -1,  2182,  2183,  2184,  2185,  2186,  1565,
      -1,  1113,    -1,    -1,  2192,    -1,    -1,    -1,  2196,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    26,  2223,    28,    -1,    -1,    -1,
    2228,  2229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2241,    -1,  1167,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
    2268,  2269,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
    1046,  1047,  1048,    -1,   259,    -1,  1052,  1053,    -1,    -1,
    1056,  1057,  1058,  1059,    -1,  1061,    -1,    -1,    -1,    -1,
    1066,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
    1252,  1253,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
    1746,  1747,   259,    -1,   261,    -1,   263,    -1,    -1,    -1,
      -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,  1144,    -1,
    1146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1780,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1342,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,   255,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   265,   266,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   278,   279,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,    -1,  1421,
      -1,  1423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1896,  1897,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     6,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    98,  1950,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   395,    -1,    -1,   121,    -1,    -1,    -1,
     402,   403,   404,    -1,    -1,    -1,   408,   409,   410,   411,
     412,   413,   414,    -1,   416,   140,    -1,    -1,    -1,   421,
     422,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2010,  2011,    -1,    -1,    -1,    -1,
      -1,  1397,    -1,  1565,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2031,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2046,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1440,    -1,    -1,   212,   213,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,   228,    -1,   230,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,    -1,    -1,    -1,    -1,  1483,  1484,    -1,
      -1,    -1,    -1,    -1,  1490,    -1,    -1,  1493,    -1,   264,
      -1,  1497,    -1,    -1,  1500,     6,  1668,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,  2164,    -1,
      -1,    -1,   594,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2182,  2183,  2184,  2185,
    2186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1746,  1747,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1589,    -1,  1591,    -1,    -1,    -1,  1595,
      -1,  1597,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1775,    -1,    -1,    -1,    -1,  1780,    -1,
      -1,    -1,    -1,    -1,    -1,  2241,    -1,    -1,    -1,    -1,
      -1,    -1,  1628,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      98,    -1,  1728,    -1,  1896,  1897,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1950,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,     7,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1834,    -1,
      -1,  1837,    -1,   211,   212,   213,   214,   215,  2010,  2011,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,  2031,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   920,    -1,
     248,   249,    -1,    -1,  2046,    13,    14,   255,    -1,    -1,
    1886,  1887,   260,  1889,    -1,    -1,   264,    -1,    -1,   267,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   953,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,    -1,    -1,   137,   138,    -1,
     140,   141,    -1,   143,    -1,    -1,    -1,    -1,  1954,  1955,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,    -1,   124,    -1,   188,   189,
     190,    -1,  2164,    -1,    -1,   133,   134,  2003,    -1,   137,
     138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,    -1,
    2182,  2183,  2184,  2185,  2186,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
     188,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,  2241,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,  1138,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,
      98,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,  1236,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,
     138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,
     168,    -1,    -1,    -1,  2250,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,   193,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,   267,
      -1,    -1,     3,     4,     5,    -1,  1398,  1399,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    -1,    98,    -1,    -1,
      -1,   102,    -1,  1495,   105,    -1,    -1,   108,    -1,   110,
      -1,    -1,  1504,    -1,    -1,    -1,   117,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,    -1,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,     8,    -1,    -1,    -1,
     259,    -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,  1667,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   140,    -1,    -1,    -1,
     259,    -1,   261,    -1,   263,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,    -1,   230,   231,    -1,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
      -1,   255,    -1,   257,   258,    -1,   260,    -1,   262,     3,
       4,     5,   266,   267,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,   193,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,   260,     3,     4,    -1,
     264,    -1,     8,   267,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,
     136,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   168,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,
     226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,   260,     3,     4,     5,    -1,   265,
      -1,   267,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,
     138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,
     168,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,   193,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,    -1,   221,   222,   223,    -1,   225,   226,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,     3,     4,    -1,   264,    -1,    -1,   267,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
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
      -1,   259,    -1,   193,    -1,    -1,    -1,   265,    -1,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,   215,   216,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,   225,   226,   227,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     260,     3,     4,    -1,   264,   265,    -1,   267,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   193,    -1,    -1,    -1,   265,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,   221,
     222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,     3,
       4,    -1,   264,    -1,    -1,   267,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,   193,
      -1,    -1,    -1,   265,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,   260,     3,     4,    -1,
     264,    -1,    -1,   267,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,
     136,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   168,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   193,    -1,    -1,
      -1,   265,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,
     226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,   260,     3,     4,    -1,   264,    -1,
      -1,   267,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,
     138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,
     168,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,    -1,
      -1,    -1,    -1,   259,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    -1,   215,   216,    -1,
      -1,    -1,    -1,   221,   222,   223,    -1,   225,   226,   227,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,   260,     3,     4,    -1,    -1,   265,    -1,   267,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
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
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     260,     3,     4,    -1,   264,    -1,    -1,   267,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,   221,
     222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,     3,
       4,    -1,   264,    -1,    -1,   267,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,   260,     3,     4,    -1,
     264,    -1,     8,   267,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,   135,
     136,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,    -1,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   168,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,
     216,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,   225,
     226,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,
       3,     4,    -1,    -1,   260,     8,    -1,    10,    11,    12,
      -1,   267,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,    -1,   255,     3,     4,    -1,    -1,   260,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     260,     3,     4,    -1,   264,    -1,    -1,   267,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    -1,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,   135,   136,    -1,   138,    -1,   140,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,    -1,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,   164,    -1,    -1,    -1,   168,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,   215,   216,    -1,    -1,    -1,    -1,   221,
     222,   223,    -1,   225,   226,   227,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,     3,
       4,    -1,   264,    -1,    -1,   267,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,
      -1,   215,   216,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,   225,   226,   227,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,
      -1,   255,     3,     4,     5,    -1,   260,    -1,    -1,    10,
      11,    12,    -1,   267,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    -1,    98,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,   264,    -1,    -1,   267,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,   260,     3,     4,     5,   264,
      -1,    -1,   267,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      -1,    98,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,    -1,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,
       3,     4,    -1,   260,    -1,    -1,    -1,    10,    11,    12,
     267,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,    -1,   215,    58,    59,    60,    61,    -1,
     221,   222,   223,    66,   225,   226,   227,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,   248,   249,    -1,
      93,    94,    -1,    96,   255,     3,     4,    -1,    -1,   260,
      -1,    -1,    10,    11,    12,    -1,   267,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,   211,    -1,
      -1,   259,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,
     223,   269,   225,   226,   227,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,   267,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,   211,    -1,    -1,    -1,   215,    -1,    -1,
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
     138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   265,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
     188,   189,   190,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    13,    14,    -1,    -1,    -1,
      -1,    -1,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,   188,   189,   190,   259,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,    -1,   269,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    -1,    91,    92,    -1,    94,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   265,   117,
     118,   119,   120,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,   176,   177,
     178,    -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,     4,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   229,    -1,   231,   232,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,    -1,    46,    47,    48,   259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      -1,    91,    92,    -1,    94,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,   117,   118,   119,
     120,   121,   122,    -1,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,   176,   177,   178,    -1,
      -1,    -1,   182,    -1,    -1,    -1,    -1,   187,   188,   189,
     190,     4,     5,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,   231,   232,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,     4,     5,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,   102,
       4,     5,   105,    -1,    -1,   108,    -1,   110,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,   121,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,   140,    79,    -1,
      81,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    95,    -1,    -1,    98,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,   228,    -1,   230,   231,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    13,    14,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   212,   213,   214,    -1,    95,    -1,    -1,    98,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,   230,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,   228,    -1,   230,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,   134,
      -1,    -1,   137,   138,    -1,   140,   141,    -1,   143,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,
     165,    -1,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,
     230,    -1,    -1,   188,   189,   190,   237,   238,   239,   240,
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
      -1,    -1,    -1,    -1,   265,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,   265,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,   264,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,   264,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,   264,   237,   238,
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
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,   263,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,   263,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,    -1,    -1,    -1,    -1,
     259,    -1,   261,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,    -1,    -1,    -1,    -1,   259,    -1,   261
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
       4,   260,   260,   260,     6,    32,   249,   353,   383,     6,
     262,     5,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    62,    63,    64,    65,    70,    71,    72,    73,    79,
      81,    95,    98,   212,   213,   214,   224,   228,   230,   374,
     383,   260,     4,   374,     5,   264,     5,   264,   318,   353,
     262,     6,   264,   260,   264,     6,   260,   264,     6,   268,
       7,   140,   204,   233,   234,   235,   236,   257,   258,   260,
     262,   266,   292,   293,   294,   318,   353,   373,   374,   383,
       4,   322,   323,   324,   264,     6,   353,   373,   374,   383,
     373,   373,   353,   373,   380,   381,   383,   353,   324,   353,
     299,   303,   260,   362,     9,   374,   260,   374,   353,   353,
     353,   260,   353,   353,   353,   260,   353,   353,   353,   353,
     353,   353,   353,   373,   353,   353,   353,   353,   367,   260,
     249,   353,   368,   369,   369,   264,   367,   366,   373,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   260,   262,   294,   294,   294,   294,
     294,   294,   260,   294,   294,   260,   318,   319,   319,   319,
     294,   294,     5,   264,   264,   133,   318,   318,   319,   260,
     294,   294,   260,   260,   260,   353,   264,   353,   368,   353,
     353,   265,   369,   360,   383,   196,     5,   264,     8,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   259,     9,   260,
     262,   266,   293,   294,   353,   369,   369,   260,   260,   260,
     366,   367,   367,   367,   317,   260,   264,   260,   260,   366,
     264,   264,   353,     4,   366,   264,   370,   264,   264,   363,
     363,   363,   353,   353,   248,   249,   264,   264,   363,   248,
     249,   260,   324,   363,   264,   260,   264,   260,   260,   260,
     260,   260,   260,   260,   369,   353,   367,   367,   367,   260,
     264,     4,   262,   264,     6,   262,   324,     6,     6,   264,
     264,   264,   264,   367,   353,     8,     7,   264,   262,   262,
     262,     6,     6,   260,   353,   260,   353,   353,   266,   353,
     264,   196,   353,   353,   353,   294,   353,     6,   250,     9,
     260,   262,   266,   353,   294,   294,   294,   260,   260,   260,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     260,   260,   294,   260,   262,     6,     6,   264,     6,     8,
     324,     6,     8,   324,   260,   264,   373,   369,   353,   324,
     366,   366,   264,   374,   318,     7,   353,   353,     4,    36,
      37,   111,   112,   193,   194,   296,   366,     6,   261,   263,
     264,   295,   264,     6,   264,     6,     9,   260,   262,   266,
     383,   265,   133,   138,   140,   141,   143,   316,   318,   353,
       6,   261,   269,     9,   260,   262,   266,   261,   269,   261,
     269,   269,   261,   269,     9,   260,   266,   269,   265,   269,
     263,   269,   298,   263,   298,    97,   361,   359,   383,   269,
     353,   269,   261,   261,   261,   353,   261,   261,   261,   353,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   265,     7,   353,   250,   265,   269,   265,   353,     6,
       6,   261,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   368,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   368,
     368,   383,   264,   353,   353,   373,   353,   373,   366,   373,
     373,   380,   264,   264,   264,   264,   353,   295,   383,     8,
     353,   353,   367,   366,   264,   373,   373,   368,   360,   374,
     360,   369,   261,   265,   266,   294,    67,     8,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   264,   353,   368,   353,   353,   353,   353,   353,
     383,   353,   353,   296,   264,   295,   261,   265,   265,   353,
     353,   353,     7,     7,   346,   346,   260,   353,   353,   353,
     353,     6,   169,   369,   369,   264,   261,     6,   324,   264,
     324,   324,   269,   269,   269,   363,   363,   323,   323,   269,
     353,   265,   337,   269,   324,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   265,   261,     7,   347,     6,     7,
     353,   353,     6,   353,   324,   353,   265,   369,   369,   369,
     353,     6,   261,   265,   353,   369,   353,   353,   353,   353,
     261,   353,   261,   261,   193,   269,   324,   264,     8,   261,
     261,   353,   353,   383,   296,   263,   380,   373,   380,   373,
     373,   373,   373,   373,   373,   353,   373,   373,   373,   373,
     267,   376,   383,   374,   373,   373,   373,   360,   383,   369,
     265,   265,   265,   265,   353,   324,   263,   265,   261,   147,
     165,   341,   261,   265,   269,   353,     6,   264,   366,   261,
     263,   266,     7,     7,   292,   293,     6,   369,     7,   236,
     292,   353,   277,   383,   353,   353,   296,   262,   260,   133,
     318,   319,   318,   264,   265,     6,   243,   244,   274,   369,
     383,   353,   353,   296,     6,   369,     6,   369,   353,     6,
     373,   381,   383,   261,   296,   353,   353,     6,   383,     6,
     373,   353,   261,   262,   353,   269,   374,     7,     7,     7,
     261,     7,     7,     7,   261,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   353,   261,   264,   353,   368,
       6,   264,   265,     6,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   269,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   269,   269,   269,   269,   269,
     261,   263,   263,   369,   269,   269,   295,   269,   295,   269,
     269,   269,   261,   369,   353,   353,   353,   355,   295,   265,
     265,   265,   353,   269,   269,   295,   295,   261,   266,   261,
     266,   269,   294,   356,   265,     7,   296,   295,   366,   265,
       8,     8,   369,   266,   261,   263,   260,   262,   293,   294,
     369,     7,   264,   264,   261,   261,   261,   353,   366,     4,
     345,     6,   312,   353,   374,   261,   265,   261,   261,   353,
     265,   265,   369,   266,   265,   324,   265,   265,   363,   353,
     353,   265,   265,   353,   363,   144,   144,   162,   173,   174,
     175,   179,   180,   338,   339,   363,   265,   334,   261,   265,
     261,   261,   261,   261,   261,   261,   261,   264,     7,   353,
       6,   353,   261,   265,   263,   265,   263,   265,   265,   265,
     265,     6,   265,   263,   263,   269,   261,     7,   261,     7,
       7,   266,   353,   265,   353,   353,   266,   260,   262,     7,
     266,   295,   269,   295,   295,   261,   261,   269,   295,   295,
     269,   269,   295,   295,   295,   295,   353,   295,     9,   375,
     269,   261,   269,   295,   266,   269,   357,   263,   265,   261,
     265,   268,   196,     7,   165,     6,   353,   265,   264,     6,
     366,   265,   353,     6,     7,   292,   293,   266,   292,   293,
     296,   264,   371,   383,   374,   353,     6,   265,    49,    49,
     366,   265,     4,   183,   184,   185,   186,   265,   280,   284,
     287,   289,   290,   332,   266,   261,   263,   260,   353,   353,
     260,   264,   260,   264,     8,   369,   373,   261,   266,   261,
     263,   260,   261,   261,   269,   266,   260,   265,   269,     7,
     294,     4,    36,    37,   306,   307,   308,   295,   353,   295,
     363,   366,   366,     7,   366,   366,   366,     7,   366,   366,
     366,   366,   366,   366,   366,   366,   366,   366,     6,     7,
     369,   323,   353,   353,   353,   353,   353,   353,   265,   353,
     353,   353,   366,   373,   373,   265,   265,   265,   265,   269,
     305,   265,   353,   353,   296,   296,   353,   353,   261,   366,
     294,   353,   353,   265,   296,   293,   266,   293,   353,   353,
     295,   265,   366,   369,   369,     7,     7,     7,   144,   344,
       6,   261,   269,     7,     7,     7,     6,     7,     7,   265,
       4,   296,   265,   269,   269,   269,   265,   265,   120,     4,
       6,   353,   264,     6,   260,     6,   181,     6,   181,   265,
     339,   269,   338,     7,     6,     7,     7,     7,     7,     7,
       7,     7,   323,   366,     6,   264,   102,     6,     6,     6,
     108,     7,     7,     6,     6,   353,     7,   366,     7,   366,
     366,     4,   269,     8,     8,   261,   296,   296,   296,   369,
     373,   353,   373,   267,   269,   309,   373,   373,   296,   373,
     261,   269,     6,   264,   318,   264,     6,   353,     6,   264,
     366,   265,   265,   353,     6,   193,   194,   296,   353,     6,
       7,   370,   372,     6,   262,     6,     6,   295,   294,   294,
       6,   281,   260,   260,   264,   291,     6,   296,   266,   373,
     353,   263,   261,   353,     8,   369,   353,   369,   265,   265,
       6,     6,   274,   296,   266,   353,     6,     6,   353,   296,
     261,     6,   353,   264,   353,   374,   295,    49,   264,   366,
     374,   377,   353,   353,   263,   269,     6,   261,     6,     6,
     137,   314,   314,   366,     6,     6,     6,   366,   144,   196,
     313,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   265,   265,   295,   295,   295,   295,   295,   295,   295,
     269,   269,   269,   261,   295,   295,   307,   295,   261,   295,
     261,   294,   356,   295,     6,   295,   260,   262,   294,   296,
     261,   263,   295,     6,   265,   265,   366,   366,   366,     4,
       6,   292,   353,   366,   366,   366,   264,   264,     7,     6,
       7,   353,   353,   353,   264,   264,   264,   262,     6,   353,
     366,   353,     6,     6,   353,   363,   265,     5,   366,   264,
     264,   264,   264,   264,   264,   264,   366,   265,     6,   369,
     264,   264,   353,   353,   263,   366,     6,   366,     6,   192,
     353,   353,   353,   260,   262,     6,     6,     7,   295,   269,
     269,   295,   269,   353,     4,   208,   310,   311,   295,   261,
     295,   357,   374,   353,   264,   324,     6,   324,   269,     6,
       6,   266,     7,     7,   292,   293,     6,   370,   265,   269,
     353,   292,   264,   295,   378,   379,   380,   378,   260,   353,
     353,   365,   366,   264,   260,     4,     6,   261,     6,   261,
     265,   265,   261,   265,     6,     6,   373,   260,     4,   261,
     269,   260,   265,   269,   366,   374,     7,   294,   304,   353,
     368,   308,     6,   363,     6,     6,     6,   144,   315,   102,
     121,   106,     6,     5,   264,     6,   353,   353,   353,   353,
     261,   356,   353,   353,   295,   293,   264,   264,     6,   313,
       6,   353,   366,   144,   144,     4,     6,   369,   369,   353,
     353,   374,   265,   261,   265,   269,   323,   323,   353,   353,
     265,   269,   261,   265,   269,     6,     6,   365,   363,   363,
     363,   363,   363,   249,   363,     6,   265,   369,   353,     6,
       6,     6,     6,     6,   366,   265,   269,     8,   265,   261,
     264,   353,   374,   373,   353,   373,   353,   374,   377,   379,
     374,   269,   261,   269,   265,   353,   341,   341,   366,   296,
     371,   374,   353,     6,     6,   370,   263,   366,   380,     6,
     295,   295,   278,   353,   269,   269,   265,   269,   279,   353,
     353,     6,     6,     6,     6,   353,   353,   261,     6,   353,
     300,   302,   264,   379,   265,   269,     7,     7,   148,     6,
     264,   264,   264,     5,   365,   295,   295,   269,   295,   261,
     261,   263,   369,   369,     6,     6,   353,   353,   264,   265,
     265,   264,     6,     6,   264,   353,   265,   265,   265,   263,
       6,   366,     7,   264,   353,   265,   269,   269,   269,   269,
     269,   269,     6,   265,   265,   191,   353,   353,   369,     6,
       6,   261,   295,   295,   311,   374,   265,   265,   265,   265,
       7,     6,     6,     6,   266,     6,   265,     6,     6,   261,
     269,   353,   353,   264,   366,   265,   269,   261,   261,   269,
     265,   305,   309,   366,   295,   353,   374,   383,   369,   369,
     353,     6,   265,   353,   356,   265,   265,     6,     6,   365,
     149,   150,   155,   348,   149,   150,   348,   369,   323,   265,
     269,     6,   265,   366,   324,   265,     6,   369,   363,   363,
     363,   363,   363,     6,   353,   265,   265,   265,   261,     6,
     264,     6,   370,   194,   282,   353,   269,   269,   365,     6,
     353,   353,     6,   265,   265,   301,     7,   260,   265,   265,
     265,   264,   269,   261,   264,   265,   264,   363,   366,     6,
     264,   363,     6,   265,   265,   353,     6,   144,   265,   335,
     264,   265,   269,   269,   269,   269,   269,     6,     6,     6,
     324,     6,   264,   353,   353,   265,   269,   305,   374,   261,
     353,   353,   369,     6,   363,     6,   363,     6,     6,   265,
     353,   338,   324,     6,   369,   369,   369,   369,   363,   369,
     341,   279,   261,   269,     6,   264,   353,   265,   269,   269,
     265,   269,   269,     6,   265,   265,   336,   265,   265,   265,
     265,   269,   265,   265,   265,   285,   353,   365,   265,   353,
     353,   363,   363,   338,     6,     6,     6,     6,   369,     6,
       6,     6,   264,   261,   265,     6,   265,   295,   269,   269,
     265,   265,   283,   373,   288,   264,     6,   353,   353,     6,
     265,   269,   264,   365,   265,   265,     6,   373,   286,   373,
     265,     6,     6,   265,   269,     6,     6,   373
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
      Msg::Exit((int)(yyvsp[(2) - (3)].d));
    ;}
    break;

  case 281:
#line 3603 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 282:
#line 3608 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 283:
#line 3615 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 284:
#line 3620 "Gmsh.y"
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

  case 285:
#line 3630 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 286:
#line 3635 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw(false); // not rate limited
#endif
    ;}
    break;

  case 287:
#line 3641 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 288:
#line 3649 "Gmsh.y"
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

  case 289:
#line 3660 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 290:
#line 3668 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 291:
#line 3672 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 292:
#line 3676 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 293:
#line 3680 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 294:
#line 3687 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 295:
#line 3691 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 296:
#line 3695 "Gmsh.y"
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

  case 297:
#line 3707 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 298:
#line 3717 "Gmsh.y"
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

  case 299:
#line 3775 "Gmsh.y"
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

  case 300:
#line 3795 "Gmsh.y"
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

  case 301:
#line 3821 "Gmsh.y"
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

  case 302:
#line 3837 "Gmsh.y"
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

  case 303:
#line 3854 "Gmsh.y"
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

  case 304:
#line 3871 "Gmsh.y"
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

  case 305:
#line 3893 "Gmsh.y"
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

  case 306:
#line 3915 "Gmsh.y"
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

  case 307:
#line 3950 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 308:
#line 3958 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(nullptr, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 309:
#line 3966 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 310:
#line 3972 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 311:
#line 3979 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 312:
#line 3986 "Gmsh.y"
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

  case 313:
#line 4006 "Gmsh.y"
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

  case 314:
#line 4032 "Gmsh.y"
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

  case 315:
#line 4044 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 316:
#line 4055 "Gmsh.y"
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

  case 317:
#line 4073 "Gmsh.y"
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

  case 318:
#line 4091 "Gmsh.y"
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

  case 319:
#line 4109 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 4115 "Gmsh.y"
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

  case 321:
#line 4133 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4139 "Gmsh.y"
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

  case 323:
#line 4159 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 324:
#line 4165 "Gmsh.y"
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

  case 325:
#line 4183 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 326:
#line 4189 "Gmsh.y"
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

  case 327:
#line 4206 "Gmsh.y"
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

  case 328:
#line 4222 "Gmsh.y"
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

  case 329:
#line 4239 "Gmsh.y"
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

  case 330:
#line 4257 "Gmsh.y"
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

  case 331:
#line 4280 "Gmsh.y"
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

  case 332:
#line 4307 "Gmsh.y"
    {
    ;}
    break;

  case 333:
#line 4310 "Gmsh.y"
    {
    ;}
    break;

  case 334:
#line 4316 "Gmsh.y"
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

  case 335:
#line 4328 "Gmsh.y"
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

  case 336:
#line 4348 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 337:
#line 4352 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 338:
#line 4356 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 339:
#line 4360 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 340:
#line 4364 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 341:
#line 4368 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 342:
#line 4372 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 343:
#line 4376 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 344:
#line 4385 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 345:
#line 4397 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 346:
#line 4398 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 347:
#line 4399 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 348:
#line 4400 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 349:
#line 4401 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 350:
#line 4405 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 351:
#line 4406 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 352:
#line 4407 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 353:
#line 4408 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 354:
#line 4409 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 355:
#line 4414 "Gmsh.y"
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

  case 356:
#line 4437 "Gmsh.y"
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

  case 357:
#line 4457 "Gmsh.y"
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

  case 358:
#line 4478 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 359:
#line 4482 "Gmsh.y"
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

  case 360:
#line 4499 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 361:
#line 4503 "Gmsh.y"
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

  case 362:
#line 4519 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 363:
#line 4523 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 364:
#line 4528 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 365:
#line 4532 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 366:
#line 4538 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 367:
#line 4542 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 368:
#line 4549 "Gmsh.y"
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

  case 369:
#line 4572 "Gmsh.y"
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

  case 370:
#line 4591 "Gmsh.y"
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

  case 371:
#line 4632 "Gmsh.y"
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

  case 372:
#line 4676 "Gmsh.y"
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

  case 373:
#line 4715 "Gmsh.y"
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

  case 374:
#line 4740 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      int new_tag = (int)(yyvsp[(6) - (8)].d);
      GModel::current()->changeEntityTag(dim, tag, new_tag);
    ;}
    break;

  case 375:
#line 4747 "Gmsh.y"
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

  case 376:
#line 4758 "Gmsh.y"
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

  case 377:
#line 4775 "Gmsh.y"
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

  case 378:
#line 4792 "Gmsh.y"
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

  case 379:
#line 4822 "Gmsh.y"
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

  case 380:
#line 4848 "Gmsh.y"
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

  case 381:
#line 4875 "Gmsh.y"
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

  case 382:
#line 4907 "Gmsh.y"
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

  case 383:
#line 4935 "Gmsh.y"
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

  case 384:
#line 4961 "Gmsh.y"
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

  case 385:
#line 4987 "Gmsh.y"
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

  case 386:
#line 5013 "Gmsh.y"
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

  case 387:
#line 5039 "Gmsh.y"
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

  case 388:
#line 5060 "Gmsh.y"
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

  case 389:
#line 5072 "Gmsh.y"
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

  case 390:
#line 5120 "Gmsh.y"
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

  case 391:
#line 5174 "Gmsh.y"
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

  case 392:
#line 5189 "Gmsh.y"
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

  case 393:
#line 5201 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 394:
#line 5207 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (6)].l), tags);
      tags.push_back(- (int) (yyvsp[(5) - (6)].d));
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (6)].i), tags);
      List_Delete((yyvsp[(3) - (6)].l));
    ;}
    break;

  case 395:
#line 5219 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 396:
#line 5226 "Gmsh.y"
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

  case 397:
#line 5241 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 398:
#line 5250 "Gmsh.y"
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

  case 399:
#line 5270 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 400:
#line 5271 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 401:
#line 5272 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 402:
#line 5277 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 403:
#line 5283 "Gmsh.y"
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
#line 5295 "Gmsh.y"
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
#line 5313 "Gmsh.y"
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
#line 5340 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 407:
#line 5341 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 408:
#line 5342 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 410:
#line 5344 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 411:
#line 5345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5346 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5347 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5349 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 415:
#line 5355 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 416:
#line 5356 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 417:
#line 5357 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 418:
#line 5358 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 419:
#line 5359 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 420:
#line 5360 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 421:
#line 5361 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5362 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5363 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5364 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5365 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 426:
#line 5366 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 427:
#line 5367 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 428:
#line 5368 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 429:
#line 5369 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 430:
#line 5370 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5371 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 432:
#line 5372 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 433:
#line 5373 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5374 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5375 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5376 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 437:
#line 5377 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5378 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 439:
#line 5379 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5380 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 441:
#line 5381 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5382 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5383 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 444:
#line 5384 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 445:
#line 5385 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 446:
#line 5386 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 447:
#line 5387 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 448:
#line 5388 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 449:
#line 5389 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 450:
#line 5390 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 451:
#line 5391 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 452:
#line 5392 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 453:
#line 5393 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 454:
#line 5394 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 455:
#line 5403 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 456:
#line 5404 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 457:
#line 5405 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 458:
#line 5406 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 459:
#line 5407 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 460:
#line 5408 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 461:
#line 5409 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 462:
#line 5410 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 463:
#line 5411 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 464:
#line 5412 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 465:
#line 5413 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 466:
#line 5418 "Gmsh.y"
    { init_options(); ;}
    break;

  case 467:
#line 5420 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 468:
#line 5426 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 469:
#line 5430 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5435 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 471:
#line 5440 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 472:
#line 5445 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 473:
#line 5450 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 474:
#line 5454 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 475:
#line 5458 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 476:
#line 5462 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 477:
#line 5466 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 478:
#line 5470 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 479:
#line 5474 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 480:
#line 5478 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 481:
#line 5484 "Gmsh.y"
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

  case 482:
#line 5499 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 483:
#line 5503 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 484:
#line 5509 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 485:
#line 5514 "Gmsh.y"
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

  case 486:
#line 5533 "Gmsh.y"
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
#line 5553 "Gmsh.y"
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
#line 5574 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 489:
#line 5578 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 490:
#line 5582 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 491:
#line 5586 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 492:
#line 5590 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 493:
#line 5594 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 494:
#line 5598 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 495:
#line 5603 "Gmsh.y"
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

  case 496:
#line 5613 "Gmsh.y"
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

  case 497:
#line 5623 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 498:
#line 5628 "Gmsh.y"
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

  case 499:
#line 5639 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 500:
#line 5648 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 501:
#line 5653 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 502:
#line 5658 "Gmsh.y"
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

  case 503:
#line 5685 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 504:
#line 5687 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 505:
#line 5692 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 506:
#line 5694 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 507:
#line 5699 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 508:
#line 5706 "Gmsh.y"
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

  case 509:
#line 5722 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 510:
#line 5724 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 511:
#line 5729 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 512:
#line 5731 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 513:
#line 5736 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 514:
#line 5738 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 515:
#line 5743 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5 * sizeof(double));
    ;}
    break;

  case 516:
#line 5747 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 517:
#line 5751 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 518:
#line 5755 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 519:
#line 5759 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 520:
#line 5766 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 521:
#line 5770 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 522:
#line 5774 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 523:
#line 5778 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 524:
#line 5785 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 525:
#line 5790 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 526:
#line 5797 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 527:
#line 5802 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 528:
#line 5806 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 529:
#line 5811 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 530:
#line 5815 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 531:
#line 5823 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 532:
#line 5834 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 533:
#line 5838 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 534:
#line 5842 "Gmsh.y"
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

  case 535:
#line 5856 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 536:
#line 5864 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 537:
#line 5872 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 538:
#line 5879 "Gmsh.y"
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

  case 539:
#line 5889 "Gmsh.y"
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

  case 540:
#line 5912 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 541:
#line 5917 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 542:
#line 5923 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 543:
#line 5928 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 544:
#line 5934 "Gmsh.y"
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

  case 545:
#line 5945 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 546:
#line 5951 "Gmsh.y"
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
#line 5965 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 548:
#line 5971 "Gmsh.y"
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
#line 5983 "Gmsh.y"
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
#line 5997 "Gmsh.y"
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
#line 6010 "Gmsh.y"
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
#line 6027 "Gmsh.y"
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
#line 6037 "Gmsh.y"
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
#line 6047 "Gmsh.y"
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
#line 6057 "Gmsh.y"
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
#line 6069 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 557:
#line 6073 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 558:
#line 6078 "Gmsh.y"
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
#line 6090 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 560:
#line 6094 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 561:
#line 6098 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 562:
#line 6102 "Gmsh.y"
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
#line 6120 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 564:
#line 6128 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 565:
#line 6136 "Gmsh.y"
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

  case 566:
#line 6165 "Gmsh.y"
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
#line 6175 "Gmsh.y"
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
#line 6191 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 569:
#line 6202 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 570:
#line 6207 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 571:
#line 6211 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 572:
#line 6215 "Gmsh.y"
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
#line 6227 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 574:
#line 6231 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 575:
#line 6243 "Gmsh.y"
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
#line 6260 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 577:
#line 6270 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 578:
#line 6274 "Gmsh.y"
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
#line 6289 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 580:
#line 6294 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 581:
#line 6301 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 582:
#line 6305 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 583:
#line 6310 "Gmsh.y"
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
#line 6324 "Gmsh.y"
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
#line 6338 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 586:
#line 6342 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 587:
#line 6346 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 588:
#line 6350 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 589:
#line 6354 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 590:
#line 6362 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 591:
#line 6368 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 592:
#line 6377 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 593:
#line 6381 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 594:
#line 6385 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 595:
#line 6393 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 596:
#line 6399 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 597:
#line 6405 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 598:
#line 6409 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 599:
#line 6416 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 600:
#line 6424 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 601:
#line 6431 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 602:
#line 6440 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 603:
#line 6444 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 604:
#line 6448 "Gmsh.y"
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
#line 6463 "Gmsh.y"
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
#line 6477 "Gmsh.y"
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
#line 6491 "Gmsh.y"
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
#line 6503 "Gmsh.y"
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
#line 6519 "Gmsh.y"
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
#line 6528 "Gmsh.y"
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
#line 6537 "Gmsh.y"
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
#line 6547 "Gmsh.y"
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
#line 6558 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 614:
#line 6566 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 615:
#line 6574 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 616:
#line 6578 "Gmsh.y"
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
#line 6596 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 618:
#line 6603 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 619:
#line 6609 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 620:
#line 6615 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 621:
#line 6622 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 622:
#line 6629 "Gmsh.y"
    { init_options(); ;}
    break;

  case 623:
#line 6631 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 624:
#line 6639 "Gmsh.y"
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
#line 6663 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 626:
#line 6665 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 627:
#line 6671 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 628:
#line 6676 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 629:
#line 6678 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 630:
#line 6683 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 631:
#line 6688 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 632:
#line 6693 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 633:
#line 6695 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 634:
#line 6699 "Gmsh.y"
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
#line 6711 "Gmsh.y"
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
#line 6725 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 637:
#line 6729 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 638:
#line 6736 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 639:
#line 6744 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr) + 1) * sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 640:
#line 6752 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr) + 1) * sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 641:
#line 6763 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 642:
#line 6765 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 643:
#line 6768 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 15060 "Gmsh.tab.cpp"
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


#line 6771 "Gmsh.y"


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

