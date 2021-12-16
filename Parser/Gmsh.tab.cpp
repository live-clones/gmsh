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
     tIntersect = 422,
     tMeshAlgorithm = 423,
     tReverseMesh = 424,
     tMeshSize = 425,
     tMeshSizeFromBoundary = 426,
     tLayers = 427,
     tScaleLast = 428,
     tHole = 429,
     tAlias = 430,
     tAliasWithOptions = 431,
     tCopyOptions = 432,
     tQuadTriAddVerts = 433,
     tQuadTriNoNewVerts = 434,
     tRecombLaterals = 435,
     tTransfQuadTri = 436,
     tText2D = 437,
     tText3D = 438,
     tInterpolationScheme = 439,
     tTime = 440,
     tCombine = 441,
     tBSpline = 442,
     tBezier = 443,
     tNurbs = 444,
     tNurbsOrder = 445,
     tNurbsKnots = 446,
     tColor = 447,
     tColorTable = 448,
     tFor = 449,
     tIn = 450,
     tEndFor = 451,
     tIf = 452,
     tElseIf = 453,
     tElse = 454,
     tEndIf = 455,
     tExit = 456,
     tAbort = 457,
     tField = 458,
     tReturn = 459,
     tCall = 460,
     tSlide = 461,
     tMacro = 462,
     tShow = 463,
     tHide = 464,
     tGetValue = 465,
     tGetStringValue = 466,
     tGetEnv = 467,
     tGetString = 468,
     tGetNumber = 469,
     tUnique = 470,
     tSetMaxTag = 471,
     tHomology = 472,
     tCohomology = 473,
     tBetti = 474,
     tExists = 475,
     tFileExists = 476,
     tGetForced = 477,
     tGetForcedStr = 478,
     tGMSH_MAJOR_VERSION = 479,
     tGMSH_MINOR_VERSION = 480,
     tGMSH_PATCH_VERSION = 481,
     tGmshExecutableName = 482,
     tSetPartition = 483,
     tNameToString = 484,
     tStringToName = 485,
     tUnsplitWindow = 486,
     tAFFECTDIVIDE = 487,
     tAFFECTTIMES = 488,
     tAFFECTMINUS = 489,
     tAFFECTPLUS = 490,
     tOR = 491,
     tAND = 492,
     tNOTEQUAL = 493,
     tEQUAL = 494,
     tGREATERGREATER = 495,
     tLESSLESS = 496,
     tGREATEROREQUAL = 497,
     tLESSOREQUAL = 498,
     UNARYPREC = 499,
     tMINUSMINUS = 500,
     tPLUSPLUS = 501
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
#define tIntersect 422
#define tMeshAlgorithm 423
#define tReverseMesh 424
#define tMeshSize 425
#define tMeshSizeFromBoundary 426
#define tLayers 427
#define tScaleLast 428
#define tHole 429
#define tAlias 430
#define tAliasWithOptions 431
#define tCopyOptions 432
#define tQuadTriAddVerts 433
#define tQuadTriNoNewVerts 434
#define tRecombLaterals 435
#define tTransfQuadTri 436
#define tText2D 437
#define tText3D 438
#define tInterpolationScheme 439
#define tTime 440
#define tCombine 441
#define tBSpline 442
#define tBezier 443
#define tNurbs 444
#define tNurbsOrder 445
#define tNurbsKnots 446
#define tColor 447
#define tColorTable 448
#define tFor 449
#define tIn 450
#define tEndFor 451
#define tIf 452
#define tElseIf 453
#define tElse 454
#define tEndIf 455
#define tExit 456
#define tAbort 457
#define tField 458
#define tReturn 459
#define tCall 460
#define tSlide 461
#define tMacro 462
#define tShow 463
#define tHide 464
#define tGetValue 465
#define tGetStringValue 466
#define tGetEnv 467
#define tGetString 468
#define tGetNumber 469
#define tUnique 470
#define tSetMaxTag 471
#define tHomology 472
#define tCohomology 473
#define tBetti 474
#define tExists 475
#define tFileExists 476
#define tGetForced 477
#define tGetForcedStr 478
#define tGMSH_MAJOR_VERSION 479
#define tGMSH_MINOR_VERSION 480
#define tGMSH_PATCH_VERSION 481
#define tGmshExecutableName 482
#define tSetPartition 483
#define tNameToString 484
#define tStringToName 485
#define tUnsplitWindow 486
#define tAFFECTDIVIDE 487
#define tAFFECTTIMES 488
#define tAFFECTMINUS 489
#define tAFFECTPLUS 490
#define tOR 491
#define tAND 492
#define tNOTEQUAL 493
#define tEQUAL 494
#define tGREATERGREATER 495
#define tLESSLESS 496
#define tGREATEROREQUAL 497
#define tLESSOREQUAL 498
#define UNARYPREC 499
#define tMINUSMINUS 500
#define tPLUSPLUS 501




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
#line 775 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 788 "Gmsh.tab.cpp"

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
#define YYLAST   17761

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  269
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  640
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2289

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   501

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   254,     2,   266,     2,   251,   253,     2,
     259,   260,   249,   247,   268,   248,   265,   250,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     241,     2,   242,   236,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   261,     2,   262,   258,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   263,   252,   264,   267,     2,     2,     2,
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
     235,   237,   238,   239,   240,   243,   244,   245,   246,   255,
     256,   257
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
    2228,  2233,  2238,  2243,  2250,  2253,  2257,  2264,  2266,  2268,
    2270,  2273,  2279,  2287,  2298,  2300,  2304,  2307,  2310,  2313,
    2317,  2321,  2325,  2329,  2333,  2337,  2341,  2345,  2349,  2353,
    2357,  2361,  2365,  2369,  2373,  2377,  2381,  2385,  2391,  2396,
    2401,  2406,  2411,  2416,  2421,  2426,  2431,  2436,  2441,  2448,
    2453,  2458,  2463,  2468,  2473,  2478,  2483,  2488,  2495,  2502,
    2509,  2514,  2521,  2528,  2530,  2532,  2534,  2536,  2538,  2540,
    2542,  2544,  2546,  2548,  2550,  2551,  2558,  2560,  2565,  2572,
    2574,  2579,  2584,  2589,  2596,  2602,  2610,  2619,  2630,  2635,
    2640,  2647,  2652,  2656,  2659,  2665,  2671,  2675,  2681,  2688,
    2697,  2704,  2713,  2720,  2725,  2733,  2740,  2747,  2754,  2759,
    2766,  2771,  2772,  2775,  2776,  2779,  2780,  2788,  2790,  2794,
    2796,  2799,  2800,  2804,  2806,  2809,  2812,  2816,  2820,  2832,
    2842,  2850,  2858,  2860,  2864,  2866,  2868,  2871,  2875,  2880,
    2886,  2888,  2892,  2894,  2897,  2901,  2905,  2911,  2916,  2921,
    2924,  2929,  2932,  2936,  2940,  2945,  2951,  2957,  2963,  2969,
    2971,  2973,  2975,  2979,  2985,  2993,  2998,  3003,  3008,  3015,
    3022,  3031,  3040,  3045,  3060,  3065,  3070,  3072,  3074,  3078,
    3082,  3092,  3100,  3102,  3108,  3112,  3119,  3121,  3125,  3127,
    3129,  3134,  3139,  3143,  3149,  3156,  3165,  3172,  3177,  3183,
    3185,  3190,  3192,  3194,  3196,  3198,  3203,  3210,  3215,  3222,
    3228,  3236,  3241,  3246,  3251,  3260,  3265,  3270,  3275,  3280,
    3289,  3298,  3305,  3310,  3317,  3322,  3324,  3326,  3331,  3336,
    3337,  3344,  3349,  3352,  3357,  3362,  3364,  3366,  3370,  3372,
    3374,  3378,  3382,  3386,  3392,  3400,  3406,  3412,  3421,  3423,
    3425
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     270,     0,    -1,   271,    -1,     1,     6,    -1,    -1,   271,
     272,    -1,   274,    -1,   275,    -1,   296,    -1,   132,   259,
     372,   260,     6,    -1,   315,    -1,   321,    -1,   325,    -1,
     326,    -1,   327,    -1,   328,    -1,   332,    -1,   341,    -1,
     342,    -1,   348,    -1,   349,    -1,   331,    -1,   330,    -1,
     329,    -1,   324,    -1,   351,    -1,   242,    -1,   243,    -1,
      46,   259,   372,   260,     6,    -1,    48,   259,   372,   260,
       6,    -1,    47,   259,   372,   260,     6,    -1,    46,   259,
     372,   260,   273,   372,     6,    -1,    46,   259,   372,   268,
     368,   260,     6,    -1,    48,   259,   372,   268,   368,   260,
       6,    -1,    47,   259,   372,   268,   368,   260,     6,    -1,
      46,   259,   372,   268,   368,   260,   273,   372,     6,    -1,
     382,   372,   263,   276,   264,     6,    -1,   175,     4,   261,
     352,   262,     6,    -1,   176,     4,   261,   352,   262,     6,
      -1,   177,     4,   261,   352,   268,   352,   262,     6,    -1,
      -1,   276,   279,    -1,   276,   283,    -1,   276,   286,    -1,
     276,   288,    -1,   276,   289,    -1,   276,   331,    -1,   352,
      -1,   277,   268,   352,    -1,   352,    -1,   278,   268,   352,
      -1,    -1,    -1,     4,   280,   259,   277,   260,   281,   263,
     278,   264,     6,    -1,   372,    -1,   282,   268,   372,    -1,
      -1,   182,   259,   352,   268,   352,   268,   352,   260,   284,
     263,   282,   264,     6,    -1,   372,    -1,   285,   268,   372,
      -1,    -1,   183,   259,   352,   268,   352,   268,   352,   268,
     352,   260,   287,   263,   285,   264,     6,    -1,   184,   263,
     364,   264,   263,   364,   264,     6,    -1,   184,   263,   364,
     264,   263,   364,   264,   263,   364,   264,   263,   364,   264,
       6,    -1,    -1,   185,   290,   263,   278,   264,     6,    -1,
       7,    -1,   235,    -1,   234,    -1,   233,    -1,   232,    -1,
     257,    -1,   256,    -1,   259,    -1,   261,    -1,   260,    -1,
     262,    -1,     4,    -1,    36,    -1,    37,    -1,   111,    -1,
     112,    -1,    91,   261,   298,   262,     6,    -1,    92,   261,
     302,   262,     6,    -1,   357,     6,    -1,    99,   293,   373,
     268,   352,   294,     6,    -1,   101,   293,   373,   268,   373,
     294,     6,    -1,   382,   291,   365,     6,    -1,   382,   292,
       6,    -1,   382,   293,   294,   291,   365,     6,    -1,   382,
     293,   263,   368,   264,   294,   291,   365,     6,    -1,   382,
     261,   352,   262,   291,   352,     6,    -1,   382,   261,   352,
     262,   292,     6,    -1,   382,   259,   352,   260,   291,   352,
       6,    -1,   382,   259,   352,   260,   292,     6,    -1,   382,
       7,   373,     6,    -1,   382,   293,   294,     7,    49,   293,
     294,     6,    -1,   382,   293,   294,     7,    49,   293,   377,
     294,     6,    -1,   382,   293,   294,   235,    49,   293,   377,
     294,     6,    -1,   382,   265,   295,     7,   373,     6,    -1,
     382,   261,   352,   262,   265,   295,     7,   373,     6,    -1,
     382,   265,   295,   291,   352,     6,    -1,   382,   261,   352,
     262,   265,   295,   291,   352,     6,    -1,   382,   265,   295,
     292,     6,    -1,   382,   261,   352,   262,   265,   295,   292,
       6,    -1,   382,   265,   192,   265,   295,     7,   369,     6,
      -1,   382,   261,   352,   262,   265,   192,   265,   295,     7,
     369,     6,    -1,   382,   265,   193,     7,   370,     6,    -1,
     382,   261,   352,   262,   265,   193,     7,   370,     6,    -1,
     382,   203,     7,   365,     6,    -1,   203,   261,   352,   262,
       7,   295,     6,    -1,   203,   261,   352,   262,   265,   295,
       7,   352,     6,    -1,   203,   261,   352,   262,   265,   295,
       7,   373,     6,    -1,   203,   261,   352,   262,   265,   295,
       7,   263,   368,   264,     6,    -1,   203,   261,   352,   262,
     265,   295,     6,    -1,   145,   259,     4,   260,   265,   295,
       7,   352,     6,    -1,   145,   259,     4,   260,   265,   295,
       7,   373,     6,    -1,    -1,   268,    -1,    -1,   298,   297,
     382,    -1,   298,   297,   382,     7,   352,    -1,    -1,   298,
     297,   382,     7,   263,   365,   299,   304,   264,    -1,    -1,
     298,   297,   382,   293,   294,     7,   263,   365,   300,   304,
     264,    -1,   298,   297,   382,     7,   373,    -1,    -1,   298,
     297,   382,     7,   263,   373,   301,   308,   264,    -1,    -1,
     302,   297,   372,    -1,   352,     7,   373,    -1,   303,   268,
     352,     7,   373,    -1,   367,     7,   382,   259,   260,    -1,
      -1,   268,   306,    -1,    -1,   306,    -1,   307,    -1,   306,
     268,   307,    -1,     4,   365,    -1,    36,   352,    -1,    37,
     352,    -1,     4,    -1,     4,   263,   303,   264,    -1,     4,
     373,    -1,     4,   376,    -1,    -1,   268,   309,    -1,   310,
      -1,   309,   268,   310,    -1,     4,   352,    -1,     4,   373,
      -1,   207,   373,    -1,     4,   378,    -1,     4,   376,    -1,
     352,    -1,   373,    -1,   373,   268,   352,    -1,    -1,   195,
     106,   263,   352,   264,    -1,   144,   102,   263,   368,   264,
      -1,   144,   121,   263,   368,   264,    -1,    -1,   137,   362,
      -1,    -1,   144,   148,    -1,   102,   259,   352,   260,     7,
     362,     6,    -1,   105,   259,   352,   260,     7,   365,     6,
      -1,   109,   259,   352,   260,     7,   365,     6,    -1,   141,
     109,   259,   352,   260,     7,   365,   144,   352,     6,    -1,
     141,   187,   259,   352,   260,     7,   365,   144,   352,     6,
      -1,   103,   259,   352,   260,     7,   365,   313,     6,    -1,
     104,   259,   352,   260,     7,   365,   313,     6,    -1,   187,
     259,   352,   260,     7,   365,     6,    -1,   188,   259,   352,
     260,     7,   365,     6,    -1,   189,   259,   352,   260,     7,
     365,   191,   365,   190,   352,     6,    -1,   120,   259,   352,
     260,     7,   365,     6,    -1,   105,     4,   259,   352,   260,
       7,   365,     6,    -1,   137,   108,   259,   352,   260,     7,
     365,     6,    -1,   108,   259,   352,   260,     7,   365,   312,
       6,    -1,   138,   108,   259,   352,   260,     7,   365,   312,
       6,    -1,   187,   108,   259,   352,   260,     7,   365,     6,
      -1,   188,   108,   259,   352,   260,     7,   365,     6,    -1,
      13,    14,     6,    -1,    14,   108,   352,     6,    -1,   124,
     108,   259,   352,   260,     7,     5,     5,     5,     6,    -1,
     106,   259,   352,   260,     7,   365,     6,    -1,   107,   259,
     352,   260,     7,   365,     6,    -1,   111,   259,   352,   260,
       7,   365,     6,    -1,   114,   259,   352,   260,     7,   365,
       6,    -1,   118,   259,   352,   260,     7,   365,     6,    -1,
     119,   259,   352,   260,     7,   365,     6,    -1,   112,   259,
     352,   260,     7,   365,     6,    -1,   113,   259,   352,   260,
       7,   365,     6,    -1,   134,   259,   352,   260,     7,   365,
       6,    -1,   161,   259,   352,   260,     7,   365,     6,    -1,
     108,     4,   259,   352,   260,     7,   365,   314,     6,    -1,
     110,   259,   352,   260,     7,   365,     6,    -1,   133,   259,
     352,   260,     7,   365,     6,    -1,   138,   133,   259,   352,
     260,     7,   365,     6,    -1,   141,   318,   259,   352,   260,
       7,   365,     6,    -1,   141,   318,   259,   352,   260,     7,
     365,     4,   263,   364,   264,     6,    -1,    -1,   140,   317,
     316,   259,   311,   260,   291,   365,     6,    -1,   102,    -1,
     105,    -1,   108,    -1,   110,    -1,   121,   263,   352,   264,
      -1,   105,    -1,   108,    -1,   110,    -1,   121,   263,   352,
     264,    -1,   105,    -1,   108,    -1,   121,   263,   352,   264,
      -1,   102,    -1,   105,    -1,   108,    -1,   121,   263,   352,
     264,    -1,   150,   362,   263,   322,   264,    -1,   149,   263,
     362,   268,   362,   268,   352,   264,   263,   322,   264,    -1,
     151,   362,   263,   322,   264,    -1,   152,   263,   362,   268,
     352,   264,   263,   322,   264,    -1,   152,   263,   362,   268,
     362,   264,   263,   322,   264,    -1,   155,   263,   368,   264,
     263,   322,   264,    -1,     4,   263,   322,   264,    -1,   167,
     105,   263,   368,   264,   108,   263,   352,   264,    -1,   164,
     105,   263,   352,   264,   102,   263,   368,   264,     6,    -1,
     164,   105,   259,   352,   260,   263,   368,   264,     6,    -1,
     323,    -1,   321,    -1,    -1,   323,   315,    -1,   323,   317,
     263,   368,   264,     6,    -1,   323,   140,   317,   263,   368,
     264,     6,    -1,   323,   143,   317,   263,   368,   264,     6,
      -1,   323,   317,   263,     8,   264,     6,    -1,   323,   140,
     317,   263,     8,   264,     6,    -1,   154,   137,   259,   352,
     260,     7,   365,     6,    -1,   154,   102,   259,   352,   260,
       7,   263,   364,   264,     6,    -1,   154,   137,   259,   352,
     260,     7,   263,   362,   268,   362,   268,   368,   264,     6,
      -1,   154,   137,   259,   352,   260,     7,   263,   362,   268,
     362,   268,   362,   268,   368,   264,     6,    -1,   154,   106,
     259,   352,   260,     7,   263,   362,   268,   368,   264,     6,
      -1,   154,   112,   259,   352,   260,     7,   263,   362,   268,
     362,   268,   368,   264,     6,    -1,   154,   113,   259,   352,
     260,     7,   263,   362,   268,   362,   268,   368,   264,     6,
      -1,   154,   115,   259,   352,   260,     7,   263,   362,   268,
     362,   268,   368,   264,     6,    -1,   154,   116,   259,   352,
     260,     7,   263,   362,   268,   362,   268,   368,   264,     6,
      -1,   154,     4,   259,   352,   260,     7,   365,     6,    -1,
     154,     4,   259,   352,   260,     7,     5,     6,    -1,   154,
       4,   263,   352,   264,     6,    -1,   165,   263,   323,   264,
      -1,   147,   165,   263,   323,   264,    -1,   165,     4,   263,
     323,   264,    -1,   165,   203,   261,   352,   262,     6,    -1,
     165,     4,   261,   352,   262,     6,    -1,   165,   382,     6,
      -1,   165,     4,     4,     6,    -1,   165,    94,     6,    -1,
     192,   369,   263,   323,   264,    -1,   147,   192,   369,   263,
     323,   264,    -1,   228,   352,   263,   323,   264,    -1,   208,
     263,     8,   264,    -1,   208,     5,     6,    -1,   209,   263,
       8,   264,    -1,   209,     5,     6,    -1,   208,   263,   323,
     264,    -1,   147,   208,   263,   323,   264,    -1,   209,   263,
     323,   264,    -1,   147,   209,   263,   323,   264,    -1,   382,
     373,     6,    -1,    80,   259,   379,   260,     6,    -1,   382,
     382,   261,   352,   262,   372,     6,    -1,   382,   382,   382,
     261,   352,   262,     6,    -1,   382,   352,     6,    -1,   231,
       6,    -1,   145,   259,     4,   260,   265,     4,     6,    -1,
     186,     4,     6,    -1,   201,     6,    -1,   202,     6,    -1,
      74,     6,    -1,    75,     6,    -1,    67,     6,    -1,    67,
     263,   352,   268,   352,   268,   352,   268,   352,   268,   352,
     268,   352,   264,     6,    -1,    68,     6,    -1,    69,     6,
      -1,    85,   263,   352,   268,   352,   264,     6,    -1,    85,
       6,    -1,    87,   263,   352,   268,   352,   268,   352,   264,
       6,    -1,    87,   263,   352,   268,   352,   268,   352,   268,
     352,   264,     6,    -1,    86,     6,    -1,    86,   263,   323,
     264,    -1,    88,     6,    -1,    89,     6,    -1,   126,     6,
      -1,   127,     6,    -1,   128,   263,   368,   264,   263,   368,
     264,   263,   364,   264,   263,   352,   268,   352,   264,     6,
      -1,   129,   263,   368,   264,     6,    -1,   129,   263,   368,
     264,   263,   322,   264,     6,    -1,   206,   259,   263,   368,
     264,   268,   373,   268,   373,   260,     6,    -1,   194,   259,
     352,     8,   352,   260,    -1,   194,   259,   352,     8,   352,
       8,   352,   260,    -1,   194,     4,   195,   263,   352,     8,
     352,   264,    -1,   194,     4,   195,   263,   352,     8,   352,
       8,   352,   264,    -1,   196,    -1,   207,     4,    -1,   207,
     373,    -1,   204,    -1,   205,   382,     6,    -1,   205,   373,
       6,    -1,   197,   259,   352,   260,    -1,   198,   259,   352,
     260,    -1,   199,    -1,   200,    -1,   153,   362,   263,   323,
     264,    -1,   153,   263,   362,   268,   362,   268,   352,   264,
     263,   323,   264,    -1,   153,   263,   362,   268,   362,   268,
     362,   268,   352,   264,   263,   323,   264,    -1,    -1,   153,
     362,   263,   323,   333,   337,   264,    -1,    -1,   153,   263,
     362,   268,   362,   268,   352,   264,   263,   323,   334,   337,
     264,    -1,    -1,   153,   263,   362,   268,   362,   268,   362,
     268,   352,   264,   263,   323,   335,   337,   264,    -1,    -1,
     153,   263,   323,   336,   337,   264,    -1,   153,   263,   323,
     264,   144,   120,   263,   352,   264,    -1,   133,   365,    -1,
     138,   133,   365,    -1,   135,   263,   368,   264,   263,   368,
     264,   263,   368,   264,    -1,   136,   263,   368,   264,   263,
     368,   264,   263,   368,   264,   263,   368,   264,    -1,   338,
      -1,   337,   338,    -1,   172,   263,   352,   264,     6,    -1,
     172,   263,   365,   268,   365,   264,     6,    -1,   173,     6,
      -1,   162,     6,    -1,   162,   352,     6,    -1,   178,     6,
      -1,   178,   180,     6,    -1,   179,     6,    -1,   179,   180,
       6,    -1,   174,   259,   352,   260,     7,   365,   144,   352,
       6,    -1,   144,     4,   261,   352,   262,     6,    -1,   156,
      -1,   157,    -1,   158,    -1,   159,    -1,   160,    -1,    -1,
     165,     6,    -1,   147,   165,     6,    -1,   165,   352,     6,
      -1,   147,   165,   352,     6,    -1,   339,   263,   323,   340,
     264,   263,   323,   340,   264,    -1,   117,   259,   372,   260,
      -1,   339,   259,   352,   260,     7,   263,   323,   340,   264,
     263,   323,   340,   264,     6,    -1,    -1,   144,     4,   352,
      -1,    -1,     4,    -1,    -1,     7,   365,    -1,    -1,     7,
     352,    -1,    -1,   155,   365,    -1,   170,   366,     7,   352,
       6,    -1,   122,   123,   366,     7,   352,     6,    -1,   139,
     105,   366,     7,   352,   343,     6,    -1,   139,   108,   366,
     345,   344,     6,    -1,   139,   110,   366,   345,     6,    -1,
     181,   366,     6,    -1,   100,   317,   259,   352,   268,   352,
     260,     6,    -1,   216,   317,   259,   352,   260,     6,    -1,
     168,   108,   263,   368,   264,     7,   352,     6,    -1,   171,
     108,   263,   368,   264,     7,   352,     6,    -1,   162,   108,
     366,   346,     6,    -1,   162,   110,   366,     6,    -1,   163,
     108,   366,     7,   352,     6,    -1,   142,   105,   263,   368,
     264,     7,   263,   368,   264,   347,     6,    -1,   142,   108,
     263,   368,   264,     7,   263,   368,   264,   347,     6,    -1,
     142,   105,   263,   368,   264,     7,   263,   368,   264,   149,
     263,   362,   268,   362,   268,   352,   264,     6,    -1,   142,
     108,   263,   368,   264,     7,   263,   368,   264,   149,   263,
     362,   268,   362,   268,   352,   264,     6,    -1,   142,   105,
     263,   368,   264,     7,   263,   368,   264,   150,   362,     6,
      -1,   142,   108,   263,   368,   264,     7,   263,   368,   264,
     150,   362,     6,    -1,   142,   108,   352,   263,   368,   264,
       7,   352,   263,   368,   264,     6,    -1,   317,   263,   368,
     264,   195,   317,   263,   352,   264,     6,    -1,   169,   319,
     366,     6,    -1,   130,   320,   366,     6,    -1,   131,   110,
     365,     6,    -1,   146,   105,   365,     6,    -1,   141,   318,
     365,     6,    -1,   141,   318,   365,   168,   352,     6,    -1,
     166,     6,    -1,   166,     4,     6,    -1,   166,   102,   263,
     368,   264,     6,    -1,   217,    -1,   218,    -1,   219,    -1,
     350,     6,    -1,   350,   263,   365,   264,     6,    -1,   350,
     263,   365,   268,   365,   264,     6,    -1,   350,   259,   365,
     260,   263,   365,   268,   365,   264,     6,    -1,   353,    -1,
     259,   352,   260,    -1,   248,   352,    -1,   247,   352,    -1,
     254,   352,    -1,   352,   248,   352,    -1,   352,   247,   352,
      -1,   352,   249,   352,    -1,   352,   250,   352,    -1,   352,
     252,   352,    -1,   352,   253,   352,    -1,   352,   251,   352,
      -1,   352,   258,   352,    -1,   352,   241,   352,    -1,   352,
     242,   352,    -1,   352,   246,   352,    -1,   352,   245,   352,
      -1,   352,   240,   352,    -1,   352,   239,   352,    -1,   352,
     238,   352,    -1,   352,   237,   352,    -1,   352,   243,   352,
      -1,   352,   244,   352,    -1,   352,   236,   352,     8,   352,
      -1,    16,   293,   352,   294,    -1,    17,   293,   352,   294,
      -1,    18,   293,   352,   294,    -1,    19,   293,   352,   294,
      -1,    20,   293,   352,   294,    -1,    21,   293,   352,   294,
      -1,    22,   293,   352,   294,    -1,    23,   293,   352,   294,
      -1,    24,   293,   352,   294,    -1,    26,   293,   352,   294,
      -1,    27,   293,   352,   268,   352,   294,    -1,    28,   293,
     352,   294,    -1,    29,   293,   352,   294,    -1,    30,   293,
     352,   294,    -1,    31,   293,   352,   294,    -1,    32,   293,
     352,   294,    -1,    33,   293,   352,   294,    -1,    34,   293,
     352,   294,    -1,    35,   293,   352,   294,    -1,    38,   293,
     352,   268,   352,   294,    -1,    39,   293,   352,   268,   352,
     294,    -1,    40,   293,   352,   268,   352,   294,    -1,    25,
     293,   352,   294,    -1,    37,   293,   352,   268,   352,   294,
      -1,    36,   293,   352,   268,   352,   294,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   224,    -1,
     225,    -1,   226,    -1,    82,    -1,    83,    -1,    84,    -1,
      -1,    93,   293,   352,   354,   304,   294,    -1,   357,    -1,
     214,   293,   372,   294,    -1,   214,   293,   372,   268,   352,
     294,    -1,   359,    -1,   382,   261,   352,   262,    -1,   382,
     259,   352,   260,    -1,   220,   259,   359,   260,    -1,   220,
     259,   359,   265,   295,   260,    -1,   222,   259,   359,   355,
     260,    -1,   222,   259,   359,   265,   295,   355,   260,    -1,
     222,   259,   359,   293,   352,   294,   355,   260,    -1,   222,
     259,   359,   265,   295,   293,   352,   294,   355,   260,    -1,
     221,   259,   373,   260,    -1,   266,   382,   293,   294,    -1,
     266,   359,   265,   295,   293,   294,    -1,    96,   293,   382,
     294,    -1,    96,   293,   294,    -1,   382,   292,    -1,   382,
     261,   352,   262,   292,    -1,   382,   259,   352,   260,   292,
      -1,   382,   265,   295,    -1,   382,     9,   382,   265,   295,
      -1,   382,   265,   295,   259,   352,   260,    -1,   382,     9,
     382,   265,   295,   259,   352,   260,    -1,   382,   265,   295,
     261,   352,   262,    -1,   382,     9,   382,   265,   295,   261,
     352,   262,    -1,   382,   261,   352,   262,   265,   295,    -1,
     382,   265,   295,   292,    -1,   382,   261,   352,   262,   265,
     295,   292,    -1,   210,   259,   372,   268,   352,   260,    -1,
      59,   259,   365,   268,   365,   260,    -1,    60,   293,   372,
     268,   372,   294,    -1,    58,   293,   372,   294,    -1,    61,
     293,   372,   268,   372,   294,    -1,    66,   259,   379,   260,
      -1,    -1,   268,   352,    -1,    -1,   268,   372,    -1,    -1,
      94,   359,   361,   358,   261,   305,   262,    -1,   382,    -1,
     382,     9,   382,    -1,    97,    -1,    97,   352,    -1,    -1,
     259,   360,   260,    -1,   363,    -1,   248,   362,    -1,   247,
     362,    -1,   362,   248,   362,    -1,   362,   247,   362,    -1,
     263,   352,   268,   352,   268,   352,   268,   352,   268,   352,
     264,    -1,   263,   352,   268,   352,   268,   352,   268,   352,
     264,    -1,   263,   352,   268,   352,   268,   352,   264,    -1,
     259,   352,   268,   352,   268,   352,   260,    -1,   365,    -1,
     364,   268,   365,    -1,   352,    -1,   367,    -1,   263,   264,
      -1,   263,   368,   264,    -1,   248,   263,   368,   264,    -1,
     352,   249,   263,   368,   264,    -1,   365,    -1,   263,     8,
     264,    -1,     5,    -1,   248,   367,    -1,   352,   249,   367,
      -1,   352,     8,   352,    -1,   352,     8,   352,     8,   352,
      -1,   102,   263,   352,   264,    -1,   102,   263,     8,   264,
      -1,   102,     5,    -1,   318,   263,     8,   264,    -1,   318,
       5,    -1,   140,   317,   366,    -1,   143,   317,   365,    -1,
     317,   195,    67,   365,    -1,    67,   317,   263,   368,   264,
      -1,    76,   318,   263,   352,   264,    -1,    77,   318,   263,
     352,   264,    -1,    78,   318,   263,   352,   264,    -1,   321,
      -1,   332,    -1,   341,    -1,   382,   293,   294,    -1,   382,
     265,   295,   293,   294,    -1,   382,     9,   382,   265,   295,
     293,   294,    -1,    41,   261,   382,   262,    -1,    41,   261,
     367,   262,    -1,    41,   259,   367,   260,    -1,    41,   293,
     263,   368,   264,   294,    -1,   382,   293,   263,   368,   264,
     294,    -1,    42,   293,   352,   268,   352,   268,   352,   294,
      -1,    43,   293,   352,   268,   352,   268,   352,   294,    -1,
      44,   293,   372,   294,    -1,    45,   293,   352,   268,   352,
     268,   352,   268,   352,   268,   352,   268,   352,   294,    -1,
     215,   293,   367,   294,    -1,    32,   293,   367,   294,    -1,
     352,    -1,   367,    -1,   368,   268,   352,    -1,   368,   268,
     367,    -1,   263,   352,   268,   352,   268,   352,   268,   352,
     264,    -1,   263,   352,   268,   352,   268,   352,   264,    -1,
     382,    -1,     4,   265,   192,   265,     4,    -1,   263,   371,
     264,    -1,   382,   261,   352,   262,   265,   193,    -1,   369,
      -1,   371,   268,   369,    -1,   373,    -1,   382,    -1,   382,
     261,   352,   262,    -1,   382,   259,   352,   260,    -1,   382,
     265,   295,    -1,   382,     9,   382,   265,   295,    -1,   382,
     265,   295,   259,   352,   260,    -1,   382,     9,   382,   265,
     295,   259,   352,   260,    -1,   382,   261,   352,   262,   265,
       4,    -1,   317,   263,   352,   264,    -1,   140,   317,   263,
     352,   264,    -1,     5,    -1,   229,   261,   382,   262,    -1,
      70,    -1,   227,    -1,    79,    -1,    81,    -1,   212,   259,
     372,   260,    -1,   211,   259,   372,   268,   372,   260,    -1,
     213,   293,   372,   294,    -1,   213,   293,   372,   268,   372,
     294,    -1,   223,   259,   359,   356,   260,    -1,   223,   259,
     359,   265,   295,   356,   260,    -1,    51,   293,   379,   294,
      -1,    52,   259,   372,   260,    -1,    53,   259,   372,   260,
      -1,    54,   259,   372,   268,   372,   268,   372,   260,    -1,
      49,   293,   379,   294,    -1,    63,   293,   372,   294,    -1,
      64,   293,   372,   294,    -1,    65,   293,   372,   294,    -1,
      62,   293,   352,   268,   372,   268,   372,   294,    -1,    57,
     293,   372,   268,   352,   268,   352,   294,    -1,    57,   293,
     372,   268,   352,   294,    -1,    50,   293,   372,   294,    -1,
      50,   293,   372,   268,   368,   294,    -1,    71,   293,   372,
     294,    -1,    72,    -1,    73,    -1,    56,   293,   372,   294,
      -1,    55,   293,   372,   294,    -1,    -1,    98,   293,   373,
     374,   308,   294,    -1,    95,   293,   375,   294,    -1,   266,
     352,    -1,   382,     9,   266,   352,    -1,    49,   293,   378,
     294,    -1,   379,    -1,   378,    -1,   263,   379,   264,    -1,
     372,    -1,   380,    -1,   379,   268,   372,    -1,   379,   268,
     380,    -1,   382,   259,   260,    -1,   382,   265,   295,   259,
     260,    -1,   382,     9,   382,   265,   295,   259,   260,    -1,
       4,   267,   263,   352,   264,    -1,   381,   267,   263,   352,
     264,    -1,   230,   261,   372,   262,   267,   263,   352,   264,
      -1,     4,    -1,   381,    -1,   230,   261,   372,   262,    -1
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
    5169,  5184,  5196,  5202,  5214,  5221,  5236,  5250,  5251,  5252,
    5256,  5262,  5274,  5292,  5320,  5321,  5322,  5323,  5324,  5325,
    5326,  5327,  5328,  5335,  5336,  5337,  5338,  5339,  5340,  5341,
    5342,  5343,  5344,  5345,  5346,  5347,  5348,  5349,  5350,  5351,
    5352,  5353,  5354,  5355,  5356,  5357,  5358,  5359,  5360,  5361,
    5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,  5370,  5371,
    5372,  5373,  5374,  5383,  5384,  5385,  5386,  5387,  5388,  5389,
    5390,  5391,  5392,  5393,  5398,  5397,  5405,  5409,  5414,  5419,
    5423,  5428,  5433,  5437,  5441,  5445,  5449,  5453,  5457,  5463,
    5478,  5482,  5488,  5493,  5512,  5532,  5553,  5557,  5561,  5565,
    5569,  5573,  5577,  5582,  5592,  5602,  5607,  5618,  5627,  5632,
    5637,  5665,  5666,  5672,  5673,  5679,  5678,  5701,  5703,  5708,
    5710,  5716,  5717,  5722,  5726,  5730,  5734,  5738,  5745,  5749,
    5753,  5757,  5764,  5769,  5776,  5781,  5785,  5790,  5794,  5802,
    5813,  5817,  5821,  5835,  5843,  5851,  5858,  5868,  5891,  5896,
    5902,  5907,  5913,  5924,  5930,  5944,  5950,  5962,  5976,  5989,
    5999,  6009,  6019,  6031,  6035,  6040,  6052,  6056,  6060,  6064,
    6082,  6090,  6098,  6127,  6137,  6153,  6164,  6169,  6173,  6177,
    6189,  6193,  6205,  6222,  6232,  6236,  6251,  6256,  6263,  6267,
    6272,  6286,  6300,  6304,  6308,  6312,  6316,  6324,  6330,  6339,
    6343,  6347,  6355,  6361,  6367,  6371,  6378,  6386,  6393,  6402,
    6406,  6410,  6425,  6439,  6453,  6465,  6481,  6490,  6499,  6509,
    6520,  6528,  6536,  6540,  6559,  6566,  6572,  6578,  6585,  6593,
    6592,  6602,  6626,  6628,  6634,  6639,  6641,  6646,  6651,  6656,
    6658,  6662,  6674,  6688,  6692,  6699,  6707,  6715,  6726,  6728,
    6731
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
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverseMesh", "tMeshSize", "tMeshSizeFromBoundary",
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tSlide", "tMacro", "tShow", "tHide",
  "tGetValue", "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber",
  "tUnique", "tSetMaxTag", "tHomology", "tCohomology", "tBetti", "tExists",
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
     485,   486,   487,   488,   489,   490,    63,   491,   492,   493,
     494,    60,    62,   495,   496,   497,   498,    43,    45,    42,
      47,    37,   124,    38,    33,   499,   500,   501,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   269,   270,   270,   271,   271,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   273,   273,   274,   274,
     274,   274,   274,   274,   274,   274,   275,   275,   275,   275,
     276,   276,   276,   276,   276,   276,   276,   277,   277,   278,
     278,   280,   281,   279,   282,   282,   284,   283,   285,   285,
     287,   286,   288,   288,   290,   289,   291,   291,   291,   291,
     291,   292,   292,   293,   293,   294,   294,   295,   295,   295,
     295,   295,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   297,   297,   298,
     298,   298,   299,   298,   300,   298,   298,   301,   298,   302,
     302,   303,   303,   303,   304,   304,   305,   305,   306,   306,
     307,   307,   307,   307,   307,   307,   307,   308,   308,   309,
     309,   310,   310,   310,   310,   310,   311,   311,   311,   312,
     312,   312,   312,   313,   313,   314,   314,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   316,   315,   317,   317,   317,   317,   317,
     318,   318,   318,   318,   319,   319,   319,   320,   320,   320,
     320,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   322,   322,   323,   323,   323,   323,   323,   323,   323,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   325,   325,   325,   325,   325,   325,   325,   325,
     326,   326,   327,   328,   328,   328,   328,   328,   328,   328,
     328,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   332,   332,   333,   332,
     334,   332,   335,   332,   336,   332,   332,   332,   332,   332,
     332,   337,   337,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   339,   339,   339,   339,   339,   340,
     340,   340,   340,   340,   341,   341,   342,   343,   343,   344,
     344,   345,   345,   346,   346,   347,   347,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   349,   349,   349,   350,   350,   350,
     351,   351,   351,   351,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   354,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   355,   355,   356,   356,   358,   357,   359,   359,   360,
     360,   361,   361,   362,   362,   362,   362,   362,   363,   363,
     363,   363,   364,   364,   365,   365,   365,   365,   365,   365,
     366,   366,   366,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   368,   368,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   374,
     373,   373,   375,   375,   376,   377,   377,   378,   379,   379,
     379,   379,   380,   380,   380,   381,   381,   381,   382,   382,
     382
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
       4,     4,     4,     6,     2,     3,     6,     1,     1,     1,
       2,     5,     7,    10,     1,     3,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       4,     6,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     1,     4,     6,     1,
       4,     4,     4,     6,     5,     7,     8,    10,     4,     4,
       6,     4,     3,     2,     5,     5,     3,     5,     6,     8,
       6,     8,     6,     4,     7,     6,     6,     6,     4,     6,
       4,     0,     2,     0,     2,     0,     7,     1,     3,     1,
       2,     0,     3,     1,     2,     2,     3,     3,    11,     9,
       7,     7,     1,     3,     1,     1,     2,     3,     4,     5,
       1,     3,     1,     2,     3,     3,     5,     4,     4,     2,
       4,     2,     3,     3,     4,     5,     5,     5,     5,     1,
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
       0,     0,     0,     2,     3,     1,   638,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,     0,     0,   207,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   344,   345,   346,   347,
     348,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   305,     0,     0,   313,   314,     0,     0,     0,
     308,     0,     0,     0,     0,     0,     0,   397,   398,   399,
       0,     0,     0,     5,     6,     7,     8,    10,     0,    11,
      24,    12,    13,    14,    15,    23,    22,    21,    16,     0,
      17,    18,    19,    20,     0,    25,     0,   639,     0,   233,
       0,     0,     0,     0,     0,     0,   283,     0,   285,   286,
     281,   282,     0,   288,     0,   291,   233,     0,   293,   294,
     119,   129,   638,   511,   507,    73,    74,     0,   205,   206,
     207,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,   296,     0,     0,
     217,   218,   219,     0,     0,     0,     0,   453,   454,   456,
     457,   455,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   461,   462,   463,     0,     0,   205,   210,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   458,   459,   460,     0,     0,     0,     0,     0,     0,
       0,     0,   549,   550,     0,   551,   524,   404,   466,   469,
     327,   525,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   210,   211,     0,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   513,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   638,     0,     0,   233,     0,     0,   394,
       0,     0,     0,   214,   215,     0,     0,   532,     0,     0,
     530,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   638,     0,     0,   572,     0,     0,     0,
       0,   279,   280,     0,   589,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   591,     0,
     615,   616,   593,   594,     0,     0,     0,     0,     0,     0,
     592,     0,     0,     0,     0,   306,   307,     0,   233,     0,
     233,     0,     0,     0,     0,   507,     0,   276,     0,     0,
     233,   400,     0,     0,    84,     0,    66,     0,     0,    70,
      69,    68,    67,    72,    71,    73,    74,     0,     0,     0,
       0,     0,     0,     0,   578,   507,     0,   232,     0,   231,
       0,   184,     0,     0,   578,   579,     0,     0,     0,   628,
       0,   629,   579,     0,     0,     0,   117,   117,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   566,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     407,     0,   406,   533,   408,     0,   526,     0,     0,   507,
       0,   541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,   483,     0,     0,
       0,     0,     0,     0,     0,   328,     0,   361,   361,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,   233,   233,     0,   515,   514,     0,     0,     0,
       0,   233,   233,     0,     0,     0,     0,   324,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   363,     0,     0,     0,     0,     0,     0,   233,   259,
       0,     0,   257,   395,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,   278,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   310,   309,     0,   264,     0,     0,   266,     0,
       0,     0,     0,   406,     0,   233,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,     0,     0,     0,
       0,    88,    75,    76,     0,     0,     0,   275,    40,   271,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,   234,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,     0,     0,   118,     0,     0,     0,   509,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   355,     0,     0,     0,   209,     0,     0,     0,     0,
       0,     0,     0,   389,   390,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,   482,     0,     0,     0,     0,   542,   543,     0,     0,
       0,     0,     0,   501,     0,   405,   527,     0,     0,     0,
       0,   535,     0,   424,   423,   422,   421,   417,   418,   425,
     426,   420,   419,   410,   409,     0,   411,   534,   412,   415,
     413,   414,   416,   508,     0,     0,   486,     0,   552,     0,
       0,     0,     0,     0,     0,     0,     0,   359,     0,     0,
       0,     0,     0,     0,   392,     0,     0,     0,     0,     0,
     391,     0,   233,     0,     0,     0,     0,     0,   517,   516,
       0,     0,     0,     0,     0,     0,     0,   318,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   378,     0,     0,     0,   258,     0,     0,     0,   252,
       0,     0,     0,     0,   388,   405,   531,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   311,   312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   619,     0,     0,     0,   503,     0,     0,   263,
     267,   265,   269,     0,     0,   411,     0,   508,   486,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,   405,     0,     0,     0,    66,     0,     0,    87,
       0,    66,    67,     0,     0,     0,   508,     0,     0,   486,
       0,     0,     0,   203,     0,     0,     0,   635,    28,    26,
      27,     0,     0,     0,     0,     0,   582,    30,     0,    29,
       0,     0,   272,   630,   631,     0,   632,   582,     0,     0,
      82,   120,    83,   130,   510,   512,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   568,   569,   298,   233,   220,     9,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   450,   437,     0,   439,
     440,   441,   442,   443,   565,   444,   445,   446,     0,     0,
       0,     0,     0,   557,   556,   555,     0,     0,     0,   562,
       0,   498,     0,     0,     0,   500,     0,     0,     0,     0,
     134,   481,   538,   537,   213,     0,     0,   467,   564,   472,
       0,   478,     0,     0,     0,     0,   528,     0,     0,   479,
     544,   540,     0,     0,     0,     0,   471,   470,    73,    74,
     493,     0,     0,     0,     0,     0,     0,     0,   405,   357,
     362,   360,     0,   371,     0,   156,   157,     0,   213,     0,
     405,     0,     0,     0,     0,     0,   253,     0,   268,   270,
       0,     0,     0,   221,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   331,     0,   315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,   364,   377,     0,     0,     0,     0,   254,     0,     0,
       0,     0,   216,   367,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,     0,     0,     0,
     605,     0,   612,   601,   602,   603,     0,   618,   617,     0,
       0,   606,   607,   608,   614,   622,   621,     0,   147,     0,
     595,     0,   597,     0,     0,     0,   590,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,   350,     0,     0,
       0,   401,     0,   636,     0,   109,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,   587,    51,     0,     0,     0,    64,     0,
      41,    42,    43,    44,    45,    46,     0,   471,   470,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   581,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,   137,   138,     0,
       0,     0,     0,   163,   163,     0,     0,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     368,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   545,   546,   547,
     548,     0,     0,     0,     0,     0,   501,   502,     0,   474,
       0,     0,   536,   427,   529,   487,   485,     0,   484,     0,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,     0,     0,     0,     0,     0,   393,     0,     0,
       0,    77,     0,   261,     0,     0,     0,     0,     0,     0,
       0,   336,     0,     0,   335,     0,   338,     0,   340,     0,
     325,   332,     0,     0,     0,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   379,     0,     0,   256,   255,
     396,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,   573,     0,     0,     0,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,   504,
     599,     0,   374,   487,     0,     0,   233,   351,     0,   352,
     233,     0,     0,   588,     0,    94,     0,     0,     0,     0,
      92,     0,   576,     0,   107,     0,    99,   101,     0,     0,
       0,    89,     0,     0,     0,     0,     0,    36,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,   583,     0,     0,    34,    33,     0,
     583,   633,   287,     0,     0,   121,   126,     0,     0,     0,
     140,   145,   146,   141,   142,   506,     0,    85,     0,    86,
     167,     0,     0,     0,     0,   168,   187,   188,   165,     0,
       0,     0,   169,   198,   189,   193,   194,   190,   191,   192,
     177,     0,     0,     0,   438,   452,   451,   447,   448,   449,
     558,     0,     0,     0,   496,   497,   499,   135,   465,   495,
     468,   473,     0,     0,   501,   199,   480,    73,    74,     0,
     492,   488,   490,   559,   195,     0,     0,     0,   159,     0,
       0,   369,     0,   158,     0,     0,     0,     0,     0,     0,
     277,     0,     0,     0,     0,   233,   233,     0,     0,   337,
     524,     0,     0,   339,   341,     0,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,   196,
       0,     0,     0,     0,     0,     0,     0,   174,     0,   175,
       0,     0,     0,     0,   110,   114,     0,   613,     0,     0,
     611,     0,   623,     0,     0,   148,   149,   620,   596,   598,
       0,     0,     0,     0,     0,     0,   349,   353,   349,     0,
     402,    93,     0,     0,    66,     0,     0,    91,     0,   574,
       0,     0,     0,     0,     0,     0,   626,   625,     0,     0,
       0,     0,     0,   522,     0,     0,    77,   273,   488,   274,
       0,     0,     0,     0,     0,   238,   235,     0,     0,   586,
     584,     0,     0,     0,     0,   122,   127,     0,     0,     0,
     566,   567,   139,   373,   164,   172,   173,   178,     0,     0,
       0,     0,     0,   180,     0,     0,   299,     0,     0,     0,
       0,   475,     0,     0,     0,   554,   494,     0,     0,   179,
       0,   200,   358,     0,     0,     0,     0,   201,     0,     0,
       0,     0,     0,     0,   521,   520,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   240,     0,     0,     0,
     375,   376,    39,   182,   183,     0,   571,     0,     0,   303,
     302,     0,     0,     0,     0,     0,     0,   151,   152,   155,
     154,   153,     0,   600,     0,   637,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   577,     0,     0,     0,
      96,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      49,     0,   239,   236,   237,    35,     0,     0,   634,   289,
       0,   134,   147,     0,     0,   144,     0,     0,     0,   166,
     197,     0,     0,     0,     0,     0,   560,   561,     0,   501,
     476,   489,   491,     0,     0,   181,   204,     0,     0,     0,
     365,   365,     0,   115,   116,   233,     0,   224,   225,   326,
       0,   333,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   230,     0,   228,     0,     0,     0,     0,
     111,   112,   604,   610,   609,   150,     0,     0,     0,   354,
       0,     0,   108,   100,   102,     0,    90,   627,    97,    98,
      52,     0,     0,     0,     0,   523,     0,     0,   489,   585,
       0,     0,     0,     0,   124,   624,     0,   131,     0,     0,
       0,     0,   186,     0,     0,     0,   329,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     519,     0,   343,     0,     0,   320,     0,   241,     0,     0,
       0,     0,     0,     0,   229,     0,   570,   304,     0,     0,
     387,   233,   403,     0,   575,     0,    48,     0,     0,     0,
      65,    50,     0,   290,   123,   128,   134,     0,     0,   161,
     162,   160,     0,     0,   477,     0,     0,     0,     0,   366,
     380,     0,     0,   381,     0,   222,     0,   334,     0,   316,
       0,   233,     0,     0,     0,     0,     0,     0,   176,   113,
     300,   349,   106,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,   202,     0,   384,     0,   385,   386,
     518,     0,     0,   322,   244,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,    62,     0,     0,   125,     0,
       0,   330,     0,     0,   342,   321,   317,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,   248,     0,
     242,   356,    53,     0,    60,     0,   284,     0,   563,     0,
       0,   323,     0,     0,    54,     0,     0,   297,     0,     0,
     243,     0,     0,     0,     0,     0,     0,    57,    55,     0,
      58,     0,   382,   383,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   123,  1111,   124,   125,  1095,  1973,  1979,
    1400,  1622,  2135,  2263,  1401,  2236,  2279,  1402,  2265,  1403,
    1404,  1626,   458,   617,   618,  1183,  1720,   126,   816,   486,
    1991,  2146,  1992,   487,  1859,  1482,  1436,  1437,  1438,  1585,
    1795,  1796,  1254,  1681,  1672,  1869,   791,   629,   290,   291,
     366,   214,   292,   468,   469,   130,   131,   132,   133,   134,
     135,   136,   137,   293,  1289,  2170,  2227,   985,  1285,  1286,
     294,  1074,   295,   141,  1510,  1252,   957,  1000,  2104,   142,
     143,   144,   145,   296,   297,  1210,  1225,  1355,   298,   821,
     299,   820,   489,   646,   334,  1832,   370,   371,   301,   587,
     385,  1384,  1613,   479,   474,  1348,  1050,  1662,  1825,  1826,
    1035,   481,   147,   435
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1957
static const yytype_int16 yypact[] =
{
   12982,    92,   107, 13189, -1957, -1957,  -139,   207,   121,    14,
      19,    76,    17,   161,   249,   291,   362,   126,    41,    51,
     -15,   384,   410,   177,   192,    23,   116,   498,   116,   199,
     210,   215,    10,   243,   255,    62,   277,   294,   303,   316,
     336,   357,   383,   388,   395,   399,   368,   543,   576,   695,
     711,   400,   425,   538,   584,   464,  7277,   490,   491,   511,
     660,   -57,   407,   498,   390,    89,   517,   686,   -71,   532,
     439,   439,   534,   444,   523,   546, -1957, -1957, -1957, -1957,
   -1957,   547,   287,   712,   717,    21,   123,   723,   752,   144,
    6249,   771,   880,   885,   887,  6249,   888,   -68,   -64,   655,
      24,    64, -1957,   668,   669, -1957, -1957,   923,   929,   679,
   -1957,  3493,   700,  1000,    29,    31,   498, -1957, -1957, -1957,
   11965,   701,   943, -1957, -1957, -1957, -1957, -1957,   728, -1957,
   -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957,    32,
   -1957, -1957, -1957, -1957,    54, -1957,   979,   734,  5990,   330,
     753,  1002, 11965, 13375, 13375, 13375, -1957, 11965, -1957, -1957,
   -1957, -1957, 13375, -1957, 11965, -1957, -1957, 11965, -1957, -1957,
   -1957, -1957,   748,   767,  1022, -1957, -1957,  5352, -1957, -1957,
   -1957, -1957,   780,  5352, 11965, 11965, 11965,   786, 11965, 11965,
   11965,   788, 11965, 11965, 11965, 11965, 11965, 11965, 11965, 13375,
   11965, 11965, 11965, 11965,  6249,   789, -1957, -1957, 10094, 10094,
   -1957, -1957, -1957,   795,  6249,  7534, 13375, -1957, -1957, -1957,
   -1957, -1957,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   164,   116,   116,
     116,   116,   116,   801,   116,   116,   807,   498,   585,   585,
     585, -1957, -1957, -1957,   116,   116,    36,   872,   873,   874,
     814,  7534,   942,   498,   498,   827,   116,   116,   832,   833,
     834, -1957, -1957, -1957, 11965,  7791, 11965, 11965,  8048,    23,
     909,    37, -1957, -1957,   848, -1957,  6182, -1957, -1957, -1957,
   -1957, -1957,   127, 11965, 10094, 10094,   853,   855,  8305,  6249,
    6249,  6249, -1957, -1957, -1957,   856, -1957,   854,   857,  8562,
     858, 10795,  1114,  7534,   859,    24,   860,   862,   439,   439,
     439, 11965, 11965,   -90, -1957,   163,   439, 10952,   230,   367,
     861,   867,   868,   869,   870,   871,   875, 10094, 11965,  6249,
    6249,  6249,   385,    16,  1113,   876, -1957,  1125,  1126, -1957,
     877,   881,   892, -1957, -1957,   893,  6249, -1957, 11965,  6506,
   -1957,  1128,   895,   898,   899,   900,  1130,  1156,   924, 11965,
     925, 11965, 11965,   221, 11965,   919, -1957,   990, 11965, 11965,
   11965, -1957, -1957, 11965, -1957,   116,   116,   116,   930,   932,
     933,   116,   116,   116,   116,   116,   116,   116, -1957,   116,
   -1957, -1957, -1957, -1957,   116,   116,   934,   935,   116,   936,
   -1957,   926,  1190,  1191,   939, -1957, -1957,  1192,  1195,  1198,
    1197,   947,   116, 11965, 15337,   137, 13375, -1957, 10094, 11965,
   -1957, -1957,  7534,  7534, -1957,   944,  5352,   498,  1201, -1957,
   -1957, -1957, -1957, -1957, -1957, 11965, 11965,   420,  7534,  1203,
     -78,   951,  1585,   952,  1204,    95,   953, -1957,   954, 13522,
   11965, -1957,  1652,  -195, -1957,    71,  -127,   -18,  9008, -1957,
      99, -1957,    84,  9260, 11271,  9512,   262,   281,  1120, -1957,
      23,   957, 11965,   964, 13261, 15853, 15878, 11965, 15903, 15928,
   15953, 11965, 15978, 16003, 16028, 16053, 16078, 16103, 16128,   959,
   16153, 16178, 16203,  5068,  1213, 11965, 10094,  6438, -1957,  -100,
     432, 11965,  1215,  1216,   973, 11965, 11965, 11965, 11965, 11965,
   11965, 11965, 11965, 11965, 11965, 11965, 11965, 11965, 11965, 11965,
   11965, 10094, 11965, 11965, 11965, 11965, 11965, 11965, 11965, 11965,
   10094, 10094,   971, 11965, 11965, 13375, 11965, 13375,  7534, 13375,
   13375, 13375,   972,   974,   975,   976, 11965,    28, -1957, 11052,
   11965,  7534,  6249,  7534, 13375, 13375, 10094,    23,  5352,    23,
     978, 10094,   978, -1957,   978, 16228, -1957,   469,   982,    96,
    1176, -1957,  1236, 11965, 11965, 11965, 11965, 11965, 11965, 11965,
   11965, 11965, 11965, 11965, 11965, 11965, 11965,  8819, 11965, 11965,
   11965, 11965, 11965,    23, 11965, 11965,    59, -1957,   540, 16253,
     476,   505, 11965, 11965, 11965, -1957,  1241,  1242,  1242,   991,
   11965, 11965, 11965, 11965,    25, 10094, 10094, 15365,   992,  1245,
   -1957,   994, -1957, -1957,  -193, -1957, -1957,  9769, 10026,   439,
     439,   330,   330,  -178, 10952, 10952, 11965, 11523,  -128, -1957,
   11965, 11965, 11965, 11965, 11965, 11965, 11965, 11965, 11965,   521,
   16278,  1246,  1248,  1251, 11965, 11965,  1249, 11965, -1957, -1957,
   11965, 11775, -1957, -1957, 10094, 10094, 10094, 11965,  1253, 16303,
     996, 11965, 10094, 11965, 11965, 11965, -1957, -1957, 11965, 16328,
   11965, 16353, 16378,  1069, 10377, -1957,   999,  6695, 16403, 16428,
   15448, 13375, 13375, 13375, 13375, 13375, 13375, 13375, 13375, 13375,
   11965, 13375, 13375, 13375, 13375,    15,  5352, 13375, 13375, 13375,
      23,    23, -1957, -1957, 10094, -1957,  1001, 12163, -1957,  1003,
   12223, 11965, 11965,   978, 11965, -1957,    23, 11965, 11965,    59,
    1004,   528, 16453, 13420,  1008,   553, 11965,  1257,  1007,  7534,
   16478, 15475, -1957, -1957, -1957, -1957, -1957,  1009,  1268,   171,
    1258, -1957, -1957, -1957, 10094,   197, 11965, -1957, -1957, -1957,
      23, 11965, 11965,    59,  1015, -1957,  1019,   -44,   498,   390,
     498, -1957,  1018,  5876, -1957,    18, 10094,    23, 11965, 11965,
      59,  1276, 10094,  1277, 10094, 11965,  1279, 13375,    23, 11209,
      59, 11965, -1957, 11965,  1280, -1957,    23,  1281, 13375, 11965,
    1028,  1029, -1957, 11965, 12765,  5352,  1284,  1285,  1287, 16503,
    1288,  1289,  1292, 16528,  1293,  1294,  1295,  1296,  1297,  1298,
    1299, -1957,  1300,  1301,  1302, -1957, 11965, 16553, 10094,  1047,
   10094,    55, 14438, -1957, -1957,  1305, 15421, 15421, 15421, 15421,
   15421, 15421, 15421, 15421, 15421, 15421, 15421, 12980, 15421, 15421,
   15421, 15421,   928,   241, 15421, 15421, 15421, 13448, 13481, 13514,
   13547, 13580,  6438,  1055,  1058,   117, 10094, 13613, 13646,   241,
   13679,   241,  1049,  1053,  1054,   269, 10094, 11965, 11965, 11965,
   17503, -1957,   241,  1059, 14467, 14496, -1957, -1957,  1056,   -88,
     241,  -116,  1065,   356,   559,  1319, -1957,    59,   241,  7534,
    1063,  6952,  7209,  1385,  1975,   427,   427,   512,   512,   512,
     512,   512,   512,   529,   529, 10094,  -167, -1957,  -167,  -167,
     978,   978,   978,  1064, 16578, 15502,   527, 10094, -1957,  1323,
    1068,  1071, 16603, 16628, 16653, 11965,  7534,  1328,  1330, 10699,
   16678, 14525, 16703, 16728, -1957, 11965,   565,   566, 10094,  1073,
   -1957, 12285, -1957, 12345, 12407,   439, 11965, 11965, -1957, -1957,
    1075,  1076, 10952,  7980,  1199,   372,   439, 12467, 16753, 14554,
   16778, 16803, 16828, 16853, 16878, 16903, 16928,  1078,  1335, 11965,
    1338, -1957, 11965, 16953, 14583, -1957, 15529, 12529, 15556, -1957,
     567,   572,   573, 14612, -1957, -1957, -1957,  2142,   574, 15583,
   15610, 13712, 16978,  1340, 17003,  1343,  1345,  1080, 11965, 12589,
   11965, 11965, -1957, -1957,    38,   203,   329,   203,  1093,  1094,
    1087,   241,   241,  1088, 13745,   241,   241,   241,   241, 11965,
     241,  1349, -1957,  1095,  1101,   437,    85,  1100,   575, -1957,
   -1957, -1957, -1957, 17028, 15421,  -167, 12651,  1103,   551,  1098,
    1171,  1362,  1205, 11304,  1107,  1110,  1368,  7534, 14641, -1957,
   11965,  1369,   180,   105,    59,    26,  5352, 11965,  1370, -1957,
     580,  1332,  1333,  7534, 14670,    34,  1119, 17053, 15637,   489,
   11965, 11965,  1132,  1133,  1138,  1140,  9076, -1957, -1957, -1957,
   -1957, 13375,   299,  1136, 17078, 15664,  1145, -1957,   322, -1957,
     360, 13778, -1957, -1957, -1957,  1141, -1957,  1148, 14699, 13811,
   -1957,    65, -1957, -1957, 17503, -1957,   106, 15421, 11965,   241,
     439,  7534,  7534,  1401,  7534,  7534,  7534,  1404,  7534,  7534,
    7534,  7534,  7534,  7534,  7534,  7534,  7534,  7534,  2193,  1406,
   10094,  6438, -1957, -1957,   330, -1957, -1957, -1957, -1957, -1957,
   -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957, 11965, -1957,
   -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957, 11965, 11965,
   11965, 11965, 11965, -1957, -1957, -1957,   582, 11965, 11965, -1957,
   11965, -1957,  7534, 13375, 13375, -1957,   587, 14728, 14757, 14786,
    1146, -1957, -1957, -1957,  1220, 11965, 11965, -1957, -1957, -1957,
      59, -1957,    59, 11965, 11965,  1158, -1957,  7534,   116, -1957,
   -1957, -1957, 11965, 11965,   588,    59,  -198,   227, 11965, 11965,
   -1957,   241,   589,  7534, 10094, 10094,  1409,  1412,  1413,  3141,
   -1957, -1957,  1415, -1957,  1162, 17503,  1155,  1417, -1957,  1418,
    1419,  2274,  1420,  1422,   594,    77, -1957, 12711, -1957, -1957,
     -92, 13844, 13877, -1957, -1957, 14815,  -117,  1311,  1428, 11461,
    1170,  1429,  1175,    27,    42,   -95, -1957,   -87, -1957,   372,
    1430,  1432,  1433,  1434,  1438,  1440,  1441,  1442,  1443,   330,
    7534, 17503, -1957,  2441,  1173,  1337,  1437, -1957,  1445,  1446,
    1346,  1449, -1957, -1957,  1450,  1447,  1452, 11965,  1453,  7534,
    1454,  7534,  7534,  1455, 13910, -1957,  7466,  1436,    59,    59,
   -1957, 10094, -1957, -1957, -1957, -1957, 13375, -1957, -1957, 11965,
   13375, -1957, -1957, -1957, -1957, 17503, -1957,  1196,  1202, 13375,
   -1957, 13375, -1957,    59, 13375,  1206, -1957,  1207,  1457, -1957,
      59, 11965, 11965,  1208,   498,  1209, 11556, -1957,  2721,  1211,
    7534, -1957,  1200, -1957, 14844, -1957, -1957, 11965,  1459,   430,
   11965,  1471,  1472,    24,  1475,  1221,  1479,  3782, -1957,   241,
     116,   116,  1480, -1957, -1957,  1228,  1229,  1227, -1957,  1485,
   -1957, -1957, -1957, -1957, -1957, -1957,    59,   108,  2237, 11965,
   15691, 17103, 11965,  9328, 11965, 10094,  1230,   604,  1486,    20,
      59, -1957,  1231, 11965,  1487,  1489, 11965,    59, 11713,  1491,
   11965,  4885,   241,  5451, 11965, 11965,  1238,  1233, -1957,  1496,
   17128,  1500,    94,  1371,  1371,  7534,  1501,  1508,  1509,  7534,
     -94,  1510,  1512,  1513,  1514,  1515,  1516,  1517,  1518,  1519,
   -1957,  1521,   605,  1263, 15421, 15421, 15421, 15421, 15421, 15421,
     241, 13943, 13976, 14009,  1269,   241,   241, -1957, -1957, -1957,
   -1957,   106,   241, 17153, 15421,  1271,   -82, 17503, 15421, -1957,
    1522,   241, 17503, 17503, -1957,   348, -1957,    59, -1957, 17178,
   15718, -1957,   241,  1526,   607,   610,  7534,  7534,  7534,  1529,
    1528, -1957,   213, 11965,  7534,  7534,  7534, -1957,  1272,  1273,
    1530,  1532,  1533, -1957, 11965, 11965, 11965,  1282,  1283,  1291,
    1278, -1957,  3941,  7534, -1957, 11965, -1957,  1536, -1957,  1537,
   -1957, -1957, 10952,   -56,  6763, -1957,  1304,  1306,  1307,  1308,
    1309,  1312,  9580,  1286,  1538, -1957, 10094,  1313, -1957, -1957,
   -1957,  1314, 11965, 11965, -1957, -1957, 15745,  7534,  1541,  7534,
    1542,  1360, -1957, 11965, 11965, 11965, -1957,  1546,   147,   470,
    1290,  7723,  1310, 11965,    39,   241,  1303,   241,  1315, -1957,
   -1957,  5352, -1957,   496, 11965,  1316, -1957, -1957,  3998, -1957,
   -1957,  1318,  1550, -1957,  4505, -1957,  1317,  1553,   185,  4586,
   -1957,    24, -1957,   618, -1957, 11965, -1957, -1957,   213,  4364,
   12031, -1957,  1322, 11965, 11965,  7534,  1321, -1957,   555,    98,
    1551, 17203,  1555,  1319, 17228,  1324,   626, 17253,   651,  1556,
    1559, -1957, -1957, 13375,  1331,  1564, 17278, -1957, -1957, 14042,
    1334, -1957, -1957,  7489,  5726, 17503, -1957,  1567,   116,  8048,
   -1957, -1957, -1957, 17503, 17503, -1957,   106, -1957,  1581, -1957,
   -1957,   439,  1583,  1586,  1588, -1957, -1957, -1957,  1451,   -50,
    1490,  1591, -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957,
   -1957,  1593,  1339,  1594, -1957, -1957, -1957, -1957, -1957, -1957,
   -1957, 11965, 11965, 11965, -1957, -1957, -1957,  1233, -1957, -1957,
   -1957, -1957, 11965,  1341,  1336, -1957, -1957, 11965, 11965,   241,
    -198, -1957, -1957, -1957, -1957,  1342,  1344,  1597,   -94,  1600,
   11965, -1957,  7534, 17503,  1466,  1467,   592, 10094, 10094, 11965,
   -1957, 10699, 14873, 17303,  8237,   330,   330, 11965, 11965, -1957,
     659,  1347, 17328, -1957, -1957, 14902,   -85, -1957,  1607,  1612,
    7534,   439,   439,   439,   439,   439,  7020,  1613, -1957, -1957,
     657, 10094, 11965,  4624,  4779,  1614,  1615, -1957,  1633, -1957,
    7534,  8494,   731, 17353, -1957, -1957, 10346, -1957, 13375, 11965,
   -1957, 13375, 17503, 10442,  5352,  1373, -1957, -1957, -1957, -1957,
    1384,  1377, 11965, 11965, 14931, 11965, 13420, -1957, 13420,  7534,
   -1957, -1957,    59,    26,  5352, 11965,  1641, -1957,  1642, -1957,
      24, 15772,  7534, 13375,  1643,   241, -1957,  1382,   241, 11965,
   14075, 14108,   658, -1957, 11965, 11965,  1389, -1957,  1390, -1957,
    1413,  1648,  1653,  1419,  1655, -1957, -1957,  1656, 11965, -1957,
   -1957, 11965, 11808,  1657, 11965, -1957, -1957,  1402, 12031,   666,
    5908,  1659, -1957, -1957,   629, -1957, -1957, -1957,  1520,  1658,
    1427,  1435,  1444, -1957,  1664,  7534, -1957, 15421, 15421, 14141,
   15421, -1957,  1431, 17378, 15799, -1957, -1957, 10094, 10094, -1957,
    1686, -1957, 17503,  1687, 11965, 11965,  1448, -1957,   673,   674,
   15393,  4834,  1689,  1458, -1957, -1957, 11965,  1460,  1461, 14960,
   15826,  1691,  7534,  1698,  1463, 11965, -1957, -1957,   675,   -45,
     -33,   -21,   -11,    -4,  9837,   153, -1957,  1700,   682, 14989,
   -1957, -1957, -1957, -1957, -1957,  1523, -1957, 11965, 11965, -1957,
   -1957, 10094,  4923,  1702,  1456, 15421,   241, 17503, -1957, -1957,
   -1957, -1957,    39, -1957,  5352, -1957, 15018,  1464,  1468,  1469,
    1703,  1709,  1711,  4946, -1957, -1957, -1957,  1462,  1712,   687,
   -1957,  1716,  1717,   381, 17503, 11965, 11965,  1473,  7534,   688,
   17503, 17403, -1957, -1957, -1957, -1957, 17428, 14174, -1957, -1957,
   15047,  1146,  1202,  7534,   241, -1957, 11965,  5352,    23, -1957,
   -1957, 10094, 10094, 11965,  1724,   690, -1957, -1957, 11965,  1336,
   -1957, -1957, -1957,   693,   722, -1957, -1957,  5098,  5130,  7534,
     586,   617, 10094, -1957, -1957,   330,  8751, -1957, -1957, -1957,
    1725, -1957,  1474,  7534, -1957, 15076,  1731, 10094,   439,   439,
     439,   439,   439, -1957,  1735, -1957, 11965, 15105, 15134,   724,
   -1957, -1957, -1957, -1957, -1957, -1957,  1482,  1737,  1483, -1957,
    1741,    24, -1957, -1957, -1957,  1557, -1957, -1957, -1957, -1957,
   -1957, 11965, 14207, 14240,  7534, -1957,  1742, 11965,  1488, -1957,
   11965,  1743,  1492,  1494, -1957, -1957,  5936, -1957,  1493,   729,
     730, 15163, -1957,  1497, 14273,  1495, -1957,  1498, -1957, -1957,
     732,  1499,   439,  7534,  1747,  1502,   439,  1748,   735,  1503,
   -1957, 11965, -1957,  1753,  1565, 12773,  1506, -1957,   738,   196,
     202,   204,   228,   242, -1957,  5391, -1957, -1957,  1758,  1760,
   -1957, -1957, -1957,  1764, -1957,  1511, 17503, 11965, 11965,   743,
   -1957, 17503, 14306, -1957, -1957, -1957,  1146,  5352,  1524, -1957,
   -1957, -1957, 11965, 11965, -1957, 10094,  1765,   439,   133, -1957,
   -1957,   439,   160, -1957,  1766, -1957, 15192, -1957, 11965, -1957,
     372, -1957,  1767, 10094, 10094, 10094, 10094,  9837, -1957, -1957,
   -1957, 13420, -1957, 11965, 17453, 14339,    56, 11965,  1525, -1957,
   -1957, 14372, 14405,   745, -1957,   260, -1957,   292, -1957, -1957,
   -1957,  5661,   347, 12833, -1957,   746,   768,   773,   774,   318,
     776,  1527,   812, -1957, 11965, -1957,  7534, 15221, -1957, 11965,
   11965, -1957,   439,   439, -1957, -1957, -1957,   372,  1769,  1770,
    1772,  1773, 10094,  1774,  1775,  1777,  1531, 17478,   819,  1780,
   15250, 15421,   337,   346,   483, -1957, -1957, -1957, -1957,   820,
   -1957, -1957, -1957, 13375, -1957,  1534, -1957,  1781, -1957, 11965,
   11965, -1957,  1784,   821, -1957,  1535,  7534, -1957, 15279, 15308,
   -1957,  1786, 13375, 13375,   841,  1787,  1789, -1957, -1957,   842,
   -1957,  1790, -1957, -1957,  1793, 13375, -1957, -1957, -1957
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1957, -1957, -1957, -1957,   382, -1957, -1957, -1957, -1957,  -381,
   -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957, -1957,
   -1957, -1957,  -754,  -135,  2391,  3746,    49, -1957,  1320, -1957,
   -1957, -1957, -1957, -1957, -1957, -1956, -1957,   323,   139,  -189,
   -1957,  -144, -1957,    81,   369, -1957,  1808, -1957,   306,   -60,
   -1957, -1957,    -1,  -646,   -41, -1957, -1957, -1957, -1957, -1957,
   -1957, -1957,   719,  1809, -1957, -1957, -1957, -1957, -1282, -1284,
    1812, -1790,  1813, -1957, -1957, -1957,  1212, -1957,  -203, -1957,
   -1957, -1957, -1957,  2552, -1957, -1957, -1474,   251,  1838, -1957,
       4, -1957, -1957,   -62, -1957, -1743,  1041,   -39,  3121,  3265,
    -322,    33, -1957,   671,   -74, -1957, -1957,    52,   222, -1747,
    -152,  1037, -1957,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -587
static const yytype_int16 yytable[] =
{
     148,  1541,   129,   641,   319,   980,   981,  1543,   333,   335,
     480,   338,  1713,   459,   187,  1087,  1957,  1918,  1958,   172,
     676,  1093,   174,   156,  1108,   353,  1642,   172,   383,   173,
     172,   964,   172,  1536,   427,  2082,   429,   422,  1394,   426,
     378,   568,   591,  1793,   380,  1328,  1950,   163,  1538,  1278,
    1679,   307,  1870,   302,   649,   650,   376,   165,   453,   454,
     441,  1163,  2215,   762,   307,   795,   191,  1279,   387,   649,
     650,  1871,  1431,   796,   464,   975,   308,  1280,  1281,  1282,
     797,  1521,   357,  1283,  1284,   610,   611,   302,  1278,  1102,
     982,   612,   302,   808,   324,   763,   764,   386,     4,   172,
    1670,  1680,  1836,   491,   780,   490,  1279,     5,   423,   493,
    1433,  1994,  1376,   763,   764,   354,  1280,  1281,  1282,   649,
     650,   325,  1283,  1284,   149,   484,   613,   358,   150,   359,
     649,   650,  2005,   801,   763,   764,   613,   326,   327,  2196,
     986,   802,  1434,  1435,  1219,   465,   746,  1528,   467,  1220,
     475,   475,   475,  1785,  1786,   649,   650,   649,   650,   482,
     649,   650,   649,   650,   849,   514,  2198,   158,   850,  1540,
     765,   766,   772,   651,   773,   522,  1524,   175,  1086,   176,
    1216,  1542,   772,  1915,   773,   774,  1223,  1376,   765,   766,
    2188,   379,  1814,   965,   320,   381,   475,   321,   563,   564,
     565,   302,   649,   650,  1091,   302,   302,  1537,  1757,   765,
     766,   302,   302,   475,   649,   650,  1395,  1396,  1397,  1398,
    1376,   151,  1539,  2037,   355,   360,   649,   650,   101,   152,
     102,   103,   104,   105,   106,  2038,   649,   650,   110,   111,
    1882,   113,   803,   649,   650,   121,  1794,  2039,   167,   363,
     804,   121,   364,   121,   121,   159,   121,  2040,   121,  1541,
    1109,  1110,  1109,  1110,  2041,   365,   644,   645,   302,   188,
     626,   627,   628,   153,   653,   658,  2100,   677,   154,   678,
     157,  1049,   302,   150,   356,   302,   589,   384,   772,  1383,
     773,   439,   428,   588,   430,   440,   657,   160,  1399,   569,
     592,   302,   302,  1329,   164,   302,   302,   302,   302,   128,
     671,   672,   673,   442,   166,   681,   302,   443,  1164,  2216,
     302,   192,   386,   388,   175,   121,   176,   688,  1377,  1380,
     798,  2139,   799,   182,   466,   155,   800,   449,   450,   451,
     452,   649,   650,   809,   302,   799,   302,   302,   302,   810,
    1353,   453,   454,  1354,   781,   175,   782,   176,  -579,   806,
     783,   453,   454,   302,   453,   454,   302,   807,   161,   312,
    1379,  -581,   757,   453,   454,   175,   614,   176,   615,  1195,
     649,   650,   616,   453,   454,   162,   614,   737,   615,   740,
     168,  2211,   616,   453,   454,   349,   747,   350,   748,   753,
     649,   650,   749,   449,   450,   451,   452,   649,   650,   895,
     649,   650,   449,   450,   451,   452,   169,   449,   450,   451,
     452,  2042,   431,   550,   762,   551,   652,   453,   454,   449,
     450,   451,  1092,   475,   762,   302,   453,   454,   170,   302,
     302,   453,   454,   649,   650,   449,   450,   451,   452,   649,
     650,   649,   650,   171,   461,   302,   763,   764,   184,   461,
     461,   461,   784,   772,  2173,   773,   763,   764,   461,   185,
    2174,   807,  2175,  2238,   186,   649,   650,   649,   650,    69,
      70,    71,    72,   453,   454,    75,   703,   822,   150,   649,
     650,  1278,  1497,   659,    84,   313,  2176,    87,   314,   315,
     316,   772,   189,   773,   912,   461,   769,   649,   650,  1279,
    2177,   317,   309,   302,   190,   310,  1278,   311,  1463,  1280,
    1281,  1282,   461,  2274,   814,  1283,  1284,   339,  2222,  1205,
     815,   765,   766,   906,  1279,  2095,   193,   807,   302,   649,
     650,   765,   766,   817,  1280,  1281,  1282,   302,   885,   815,
    1283,  1284,   475,   194,   475,   302,   475,   475,   482,  1419,
    2223,  1037,   195,   562,   902,   649,   650,   850,   302,   302,
     302,   475,   475,   302,   174,   196,   174,   318,   302,   572,
     573,   911,  1424,   913,   649,   650,  2232,   978,   979,   772,
     850,   773,   645,   649,   650,   197,  1896,  1331,  1897,   971,
     178,   973,   974,   179,   302,  2259,   180,  1717,   181,  1718,
     943,  2225,   767,   768,  2260,   175,   198,   176,   987,    46,
    1425,  1222,  1606,  1607,  1223,   340,   660,  1278,   850,   341,
     661,   203,   302,   302,  1088,   342,   343,  1007,   344,   345,
     210,  2070,   199,   211,   674,  1279,   212,   200,   675,  2071,
     467,   467,  1052,  1553,   201,  1280,  1281,  1282,   202,   213,
     346,  1283,  1284,   208,  1029,   946,   204,   593,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,   302,   302,   302,   205,   612,   329,   330,   209,   302,
     313,   329,   330,   314,   215,   316,   851,   772,   331,   773,
     850,   206,   332,   331,  1066,  1351,   317,   337,   482,   475,
     482,   475,   475,   475,   475,   475,   475,   207,   475,   475,
     475,   475,  1051,   216,   475,   475,   475,   174,  1057,  1104,
     772,   302,   773,   916,  1056,  2101,  2102,   850,   850,  1938,
     950,  2103,   461,  1067,   850,   453,   454,  2261,  1409,   303,
    1362,  1139,  -582,   758,   304,  1802,   302,  1803,  1732,   605,
     606,   744,   608,   609,   610,   611,  2105,  2106,   306,   951,
     612,   302,  2103,   850,   305,   792,   322,  1096,   744,   608,
     609,   610,   611,   453,   454,   997,  1238,   612,  1239,   850,
     792,   323,  1070,   302,  1113,   328,   850,   336,  1068,   302,
     772,   302,   773,   947,   482,  1125,   348,   453,   454,   347,
    1361,  1240,  1362,  1131,  1835,   475,  1803,  1076,  -583,   463,
     351,  1077,   352,  1226,   473,   476,   477,   850,   361,  1262,
    1263,  1309,  1099,   850,   850,   850,  1310,  1311,  1314,  1357,
     850,   850,   850,   850,  1389,   302,  1470,   302,   850,  1116,
     850,  1477,  1494,  1502,  1815,   850,   850,   850,  1520,  1127,
     362,   461,   850,   461,  1822,   461,   461,   461,  1640,  1692,
     509,  1725,   850,   850,  1726,   850,   649,   650,   850,   372,
     461,   461,  1819,   302,   373,  1256,  1820,   524,  2202,   374,
    1842,   375,   377,   302,   850,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,  1270,   382,  1844,   302,   612,  1541,   850,
    1276,  1927,  1977,  1911,  1287,   850,  1978,   389,   390,   391,
    1995,  1267,   302,  1240,  1996,   392,   593,  2020,  2021,  2036,
     393,   850,   850,  1978,   302,  2244,  2044,  1378,  1381,   437,
     850,  2067,  2076,   302,  2093,   807,  2077,  2096,  1978,   424,
    1541,   850,   436,   792,  1240,   302,  1228,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,   444,  2097,   792,  2128,   612,
     850,   438,   850,  2149,  2150,  1939,  2156,   850,   850,  2164,
    1978,   445,  2172,   850,   425,   394,   850,  2186,   471,  2221,
    2228,  1978,  1386,   850,   850,   150,   470,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   488,   461,   461,   461,
     461,   490,  2229,   461,   461,   461,   850,  2230,  2231,   492,
    2233,   850,   850,   792,   850,   497,   792,   501,   515,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   521,   792,
     558,  1612,   404,   405,   406,   407,   561,  -206,  -207,  -208,
     408,   409,   410,   411,   302,   571,  2235,   570,  1442,   412,
    2077,   413,  1385,  2255,  2262,  2271,   574,  1978,   850,  2272,
     302,   577,   578,   579,  1103,   414,  1105,   300,   415,  1907,
    1908,  1496,  1498,   302,   590,  2281,  2284,   750,   475,  1978,
    2285,   440,   622,   461,   623,   630,   632,   631,   638,   679,
     662,   635,   640,   642,   461,   643,   663,   664,   665,   666,
     667,   682,   683,  1382,   668,   691,   696,   680,   302,   302,
     684,   302,   302,   302,   685,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   686,   687,   302,   692,   693,
     694,   695,   697,   467,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   848,   608,   609,
     610,   611,   705,   698,   700,   706,   612,   731,   772,   714,
     773,   715,   716,   727,   728,   730,   732,   733,   735,   302,
     475,   475,   734,   736,   738,   739,   741,   756,   759,   771,
     779,   416,   417,   418,   776,   778,   149,   819,   785,   841,
     846,   853,   854,   419,   302,   823,   889,   420,   891,   421,
     893,   894,   825,   855,   886,   896,   612,   897,   898,   899,
     302,   302,   302,   919,   920,   908,   909,   917,   955,   956,
     959,   970,   969,   999,  1001,  1005,   523,   972,  1002,  1014,
    1016,  1027,  1030,  1079,  1089,  1059,  1069,  1061,  1075,  1485,
    1080,  1486,  1496,  1498,  1084,  1085,  1100,   792,  1101,   792,
     792,  1106,  1117,  1119,  1495,  1122,  1130,  1132,  1135,  1818,
    1136,  1140,  1141,   792,  1142,  1144,  1145,   302,   467,  1146,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1160,  1166,   300,   792,  1522,  1193,   302,  1202,   302,   302,
    1194,  1203,  1204,  1212,  1215,  1221,  1227,  1231,   302,  1235,
    1243,  1244,  1251,   475,  1245,   792,  1253,   475,  1265,  1273,
    1274,  1299,  1300,  1277,  1302,  1323,   475,  1319,   475,   625,
    1321,   475,  1322,  1334,  1335,  1336,  1339,  1656,  1347,  1661,
     634,  1350,  1356,  1349,   639,  1363,  1364,   302,  1360,  1365,
    1366,  1369,   792,  1370,  1371,  1375,  1388,  1577,  1578,  2109,
     386,  1390,  1391,  1036,  1406,  1038,  1039,  1040,  1041,  1042,
    1043,  1412,  1045,  1046,  1047,  1048,  1413,  1414,  1053,  1054,
    1055,  1420,  1588,  1415,  1423,   475,  1427,  1428,  1445,  1593,
     302,  1449,   302,  1461,  1481,  -209,  1506,   461,  1489,  1507,
    1508,  1511,  1512,  1513,  1514,  1515,  1516,  1518,  1608,  1519,
     302,  1529,  1530,  1533,  1535,  1534,  1556,  1544,  1545,  1557,
    1546,  1547,   302,  1558,  1575,  1548,   302,  1549,  1550,  1551,
    1552,  1559,  1560,  1564,  1561,  1628,  1562,  1563,  1565,  1572,
    1567,  1569,  1583,  1592,  1602,  1605,  1590,  1827,  1827,  1644,
    1584,  1594,  1596,  1816,  1600,  1591,  1650,  1610,  1123,  1611,
    1756,  1614,  1615,   754,   755,  1616,  1621,  1623,  1624,  1133,
    1625,  1627,  1641,  1647,  1639,  1648,  1645,  1652,  1966,   770,
    1665,  1666,  1667,   302,   302,   302,  1669,  1675,  1671,   461,
     461,   302,   302,   302,  1676,  1677,  1682,  1801,  1683,  1684,
    1685,  1686,  1687,  1688,  1689,  1690,  1691,  1693,  1715,  1704,
     302,  1711,  1724,  1730,  1731,  1737,  1738,  1739,  1740,  1748,
    1741,   302,  1753,  1754,  1769,  1745,  1746,  1777,  1779,   302,
    1768,  1780,  1784,   302,  1747,  1806,  1810,  1837,  1788,  1808,
    1813,  1839,  1845,  1798,   302,  1846,   302,  1760,  1849,  1761,
    1762,  1763,  1764,   792,  1857,  1765,  1771,  1772,  1791,  1805,
    1856,  1829,  1812,  1354,  1834,  1886,  1809,  1863,  1841,  1865,
    1848,   777,  1866,  1852,  1867,  1868,  1872,  1873,  1874,   892,
    1876,  1881,  1875,  1889,  1223,  1887,  1891,  1888,   386,  1864,
    1894,  1895,   625,  1916,   907,  1912,   482,   482,  1917,  1926,
    1932,  1933,   302,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,  1934,
     475,  1952,   461,   612,  1953,  1954,   461,  1964,  1965,  1970,
     807,   302,  -586,  -584,  1982,   461,   302,   461,   794,  1983,
     461,  1984,  1985,  1989,  2000,  1993,  1998,  1902,  1999,  2004,
    1595,  1969,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
    2001,  2010,  2015,  2016,   612,  2024,  1576,  2031,  2002,  1919,
    1920,  1921,  1922,  1923,  1925,  2033,  2043,  2003,  2051,  2168,
    2061,  2019,  1943,  2046,   461,  2062,  2052,  2063,  2066,  1948,
    1951,  2025,  2068,  2069,  2027,  2028,  2034,  2065,  2058,   302,
    2092,  2112,  2059,  2060,   302,   302,  2074,  2117,  2113,  2133,
    1962,  2124,  2129,  2130,   467,   467,  2131,  2132,  2140,  2143,
    2134,  -585,  2148,  2160,  2163,  2154,  2144,   302,  2145,  2167,
    2152,  2155,  2157,   302,  2179,  2161,  2180,  2165,   302,  2171,
    2182,  2194,  2199,  2204,  2183,  2245,  2246,   302,  2247,  2248,
    2250,  2251,  1418,  2252,  2190,   475,  2256,  2267,   475,  2218,
    2270,  2234,  2277,  2282,  2253,  2283,  2286,  2266,  2273,  2287,
    1081,  1643,  2212,  2083,  1707,  1862,   302,   818,  2055,  1890,
    1385,   127,   138,  1673,  1405,   139,   140,   386,  2107,   302,
     482,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,  1800,
     958,   146,  1828,   612,  1124,  1949,  1961,     0,     0,     0,
       0,     0,     0,     0,     0,   482,     0,     0,     0,     0,
       0,  1960,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   302,     0,  1475,  1476,     0,     0,     0,     0,
    2056,     0,     0,     0,   302,   302,     0,     0,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,   302,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,  2087,     0,   461,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,  2119,  2120,  2121,  2122,
    2123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,  2115,     0,  2088,     0,  1250,   302,   302,
       0,     0,     0,     0,     0,     0,     0,  1580,     0,     0,
       0,  1582,     0,     0,     0,     0,   302,     0,     0,   302,
    1586,     0,  1587,     0,   467,  1589,     0,     0,     0,     0,
     302,     0,     0,     0,   302,     0,     0,     0,     0,     0,
    2158,     0,     0,     0,  2162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,  2189,     0,     0,     0,     0,     0,  1630,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2181,     0,     0,     0,   461,  2195,     0,   461,     0,  2197,
     302,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   792,     0,   792,  2209,     0,     0,  1372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   461,
    2203,     0,     0,     0,  1392,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1313,     0,
       0,     0,   302,     0,     0,     0,     0,     0,     0,     0,
    2242,  2243,     0,     0,   461,     0,     0,     0,     0,     0,
     302,   302,   302,   302,   302,     0,     0,     0,     0,     0,
       0,     0,  1443,  1444,     0,  1446,  1447,  1448,     0,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   302,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,   302,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,   172,   394,  1474,     0,     0,     0,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   302,     0,     0,     0,     0,  1490,   475,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1517,     0,   475,     0,  1503,     0,   395,   396,   397,   398,
     399,   400,   401,   402,   403,     0,     0,     0,     0,   404,
     405,   406,   407,     0,     0,     0,     0,   408,   409,   410,
     411,     0,     0,     0,  1847,     0,   412,     0,   413,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   414,     0,     0,   415,     0,     0,     0,   178,
       0,  1554,   179,     0,     0,   180,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
    1568,     0,  1570,  1571,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1601,     0,     0,     0,     0,     0,   177,     0,   183,
       0,   792,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,  1555,   416,   417,
     418,   612,     0,     0,     0,     0,     0,     0,     0,  1944,
     419,     0,  1946,     0,   420,     0,   421,   121,     0,     0,
       0,     0,     0,     0,  1660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1674,   792,     0,     0,
    1678,     0,     0,   453,   454,     0,     0,     0,     0,     0,
    -580,     0,  1629,     0,     0,     0,     0,     0,     0,   792,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,   460,
       0,     0,     0,     0,     0,     0,     0,  1727,  1728,  1729,
       0,     0,     0,     0,     0,  1734,  1735,  1736,     0,   461,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1751,     0,     0,     0,   461,   461,
       0,     0,     0,     0,     0,  1759,     0,     0,     0,     0,
       0,   461,     0,  1767,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1776,     0,
    1778,     0,     0,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   552,   553,
     554,   555,   556,   557,     0,   559,   560,     0,     0,     0,
       0,     0,     0,     0,     0,   566,   567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1833,   575,   576,     0,
       0,     0,   434,     0,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,  1855,     0,     0,     0,   612,
     462,     0,     0,     0,   472,     0,     0,     0,     0,   478,
       0,     0,     0,     0,     0,     0,   483,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,  1599,     0,     0,
       0,     0,     0,     0,     0,     0,   494,   495,   496,     0,
     498,   499,   500,     0,   502,   503,   504,   505,   506,   507,
     508,     0,   510,   511,   512,   513,     0,     0,     0,     0,
     517,   517,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1893,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   711,   712,   713,     0,
       0,     0,   717,   718,   719,   720,   721,   722,   723,     0,
     724,  1833,     0,     0,     0,   725,   726,     0,     0,   729,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1935,     0,   742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   582,   584,   585,
     517,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1959,     0,     0,     0,     0,   619,   517,   517,     0,     0,
       0,     0,     0,  1968,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   637,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   647,   648,     0,     0,     0,     0,   648,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   517,
     670,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1833,     0,     0,     0,
     689,   517,     0,     0,  2264,     0,     0,     0,     0,     0,
       0,   699,     0,   701,   702,     0,   704,     0,     0,     0,
     707,   708,   709,  2278,  2280,   710,     0,     0,     0,     0,
       0,     0,     0,  2032,     0,     0,  2288,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
     918,     0,     0,     0,     0,   743,     0,     0,     0,     0,
     517,   752,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   760,   761,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2075,
       0,     0,   793,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2084,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   824,     0,     0,     0,     0,   829,
       0,     0,     0,   833,     0,     0,     0,     0,     0,     0,
    1833,     0,     0,     0,     0,     0,     0,   847,   582,     0,
       0,     0,     0,   852,  2114,     0,     0,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,   871,   872,   874,   875,   876,   877,   878,   879,
     880,   881,   882,   882,     0,   887,   888,     0,   890,     0,
       0,     0,     0,     0,     0,  1833,     0,     0,   900,     0,
       0,   904,   905,     0,     0,     0,     0,     0,   882,     0,
       0,     0,     0,   517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2159,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   934,   936,
     938,   939,   940,   941,   942,     0,   944,   945,     0,     0,
       0,     0,     0,     0,   952,   953,   954,     0,     0,     0,
       0,     0,   960,   961,   962,   963,     0,   517,   517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   580,   743,   983,     0,
       0,     0,   988,   989,   990,   991,   992,   993,   994,   995,
     996,     0,     0,     0,     0,     0,  1003,  1004,     0,  1006,
       0,     0,  1008,     0,     0,     0,   517,   517,   517,  1013,
       0,     0,     0,  1017,   517,  1019,  1020,  1021,     0,     0,
    1022,     0,  1024,     0,     0,     0,     0,  1833,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1044,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1509,   517,     0,     0,     0,
       0,     0,     0,  1063,  1064,     0,  1065,     0,     0,   944,
     945,     0,     0,     0,  1224,     0,     0,  1833,  1078,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   517,     0,  1094,   518,
     518,     0,     0,  1097,  1098,     0,     0,  1241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
    1114,  1115,     0,     0,   517,     0,   517,  1121,     0,     0,
       0,  1114,     0,  1128,     0,  1129,     0,     0,     0,     0,
       0,  1134,     0,     0,     0,  1137,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,  1158,   612,
     936,     0,  1161,     0,     0,     0,   583,     0,     0,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   518,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,  1207,
    1208,  1209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   518,     0,
       0,     0,     0,   519,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   517,     0,     0,
     518,     0,     0,     0,     0,     0,     0,   172,   394,   517,
       0,     0,     0,     0,     0,     0,     0,  1249,     0,     0,
       0,  1255,     0,     0,     0,     0,     0,  1261,     0,     0,
     517,     0,  1432,     0,     0,     0,     0,     0,  1271,  1272,
       0,     0,     0,     0,  1275,     0,     0,     0,     0,     0,
       0,     0,   395,   396,   397,   398,   399,   400,   401,   402,
     403,  1301,     0,     0,  1303,   404,   405,   406,   407,   518,
       0,     0,     0,   408,   409,   410,   411,     0,     0,   620,
     621,     0,   412,     0,   413,     0,     0,     0,     0,     0,
    1324,     0,  1326,  1327,     0,     0,     0,     0,   414,     0,
       0,   415,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   669,     0,     0,     0,     0,     0,     0,  1491,
       0,     0,     0,     0,     0,  1368,     0,     0,     0,     0,
       0,     0,  1374,     0,     0,     0,     0,   583,     0,  1387,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1410,  1411,     0,     0,     0,     0,   517,     0,
       0,     0,   873,     0,     0,     0,     0,     0,     0,     0,
       0,   883,   884,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1440,     0,     0,     0,     0,     0,     0,   910,     0,     0,
       0,     0,   518,   751,   416,   417,   418,     0,     0,     0,
       0,     0,   517,     0,     0,     0,   419,     0,     0,     0,
     420,     0,   421,   121,     0,     0,     0,     0,   937,     0,
    1464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1465,  1466,  1467,  1468,  1469,     0,     0,     0,     0,  1471,
    1472,     0,  1473,     0,     0,     0,   518,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1483,  1484,     0,
       0,     0,     0,     0,     0,  1487,  1488,     0,     0,     0,
       0,  1619,  1620,     0,  1492,  1493,     0,     0,  1617,     0,
    1499,  1500,     0,     0,     0,     0,   517,   517,     0,     0,
       0,     0,     0,     0,     0,   518,   518,   518,     0,     0,
       0,     0,     0,   518,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1532,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   914,     0,     0,     0,
       0,     0,     0,     0,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1566,
       0,     0,     0,     0,     0,     0,     0,  1712,     0,     0,
       0,     0,     0,   517,     0,     0,  1719,     0,     0,     0,
       0,  1581,     0,     0,     0,   518,     0,     0,     0,     0,
     966,   967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1499,  1500,     0,     0,   518,  1598,     0,
       0,     0,     0,   518,     0,   518,     0,     0,     0,  1604,
       0,     0,  1609,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1749,     0,  1010,
    1011,  1012,     0,     0,     0,     0,     0,  1018,     0,     0,
       0,  1631,     0,     0,  1634,   517,  1637,   517,     0,   937,
       0,  1162,     0,     0,     0,  1646,     0,     0,  1649,     0,
    1646,     0,  1653,  1655,     0,     0,  1663,  1664,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1058,
       0,     0,     0,     0,  1807,     0,     0,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,  1090,
     612,     0,     0,     0,     0,     0,     0,     0,     0,  1858,
       0,     0,     0,     0,     0,     0,   518,     0,     0,     0,
       0,  1112,     0,     0,     0,  1733,     0,  1118,   518,  1120,
       0,     0,     0,     0,     0,     0,  1742,  1743,  1744,     0,
       0,     0,     0,     0,     0,  1750,     0,  1752,     0,   518,
       0,     0,     0,     0,  1755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   517,     0,
       0,     0,     0,     0,  1773,  1774,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1781,  1782,  1783,     0,     0,
       0,     0,     0,     0,     0,  1792,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1804,     0,     0,     0,
       0,  1196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1206,     0,     0,     0,     0,     0,  1821,     0,     0,
       0,     0,     0,     0,     0,  1830,  1831,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
    1234,     0,     0,     0,     0,     0,   775,     0,     0,     0,
       0,  1860,  1242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,     0,     0,
       0,     0,     0,  1264,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,  1877,  1878,  1879,   612,     0,     0,     0,
       0,     0,     0,     0,  1880,     0,     0,     0,     0,  1883,
    1884,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   518,  1892,     0,     0,     0,     0,     0,     0,   517,
     517,  1900,     0,  1901,     0,     0,     0,     0,     0,  1909,
    1910,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   901,     0,     0,     0,     0,   517,     0,
       0,     0,     0,   517,  1929,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1942,     0,
       0,  1945,     0,     0,     0,  1947,     0,     0,     0,     0,
       0,     0,     0,     0,  1883,  1884,     0,  1956,     0,     0,
       0,     0,     0,     0,   948,   518,   518,  1963,   172,   394,
       0,  1417,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1974,     0,     0,     0,     0,  1980,  1981,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1986,     0,     0,  1987,  1986,     0,  1990,     0,     0,     0,
       0,     0,     0,   395,   396,   397,   398,   399,   400,   401,
     402,   403,     0,     0,     0,  1462,   404,   405,   406,   407,
       0,     0,     0,     0,   408,   409,   410,   411,     0,   517,
     517,     0,     0,   412,     0,   413,  2017,  2018,     0,     0,
       0,     0,   518,     0,     0,     0,     0,     0,  2026,   414,
       0,     0,   415,     0,     0,     0,   178,  2035,     0,   179,
       0,     0,   180,     0,   181,     0,   582,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,  2047,
    2048,     0,     0,   517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   447,     0,     0,     0,     0,  1504,
    1505,  1811,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2072,  2073,     0,
       0,     0,     0,     0,   518,     0,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2086,     0,
       0,     0,     0,   517,   517,  2091,     0,     0,     0,     0,
    2094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   517,   416,   417,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   419,     0,   517,
       0,   420,  1817,   421,   121,     0,  1579,     0,  2125,     0,
       0,     0,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,     0,  1179,  1180,  1181,  1182,     0,  1184,
    1185,  1186,  1187,  2136,   772,     0,   773,  1823,     0,  2141,
    1930,     0,  2142,     0,     0,  1199,     0,  1201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1211,     0,
       0,     0,     0,     0,     0,  1217,  1218,     0,     0,     0,
       0,     0,     0,  2166,  1229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   518,  1636,     0,
    1638,     0,     0,     0,     0,     0,     0,     0,     0,  2184,
    2185,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2191,  2192,     0,   517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2201,     0,     0,     0,     0,   517,   517,   517,   517,   517,
       0,     0,     0,     0,     0,  1980,     0,     0,     0,  2217,
       0,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,  2237,     0,     0,     0,
       0,  2240,  2241,     0,     0,     0,     0,     0,     0,     0,
    1861,  1330,  1332,  1333,   517,  1931,     0,  1337,  1338,     0,
       0,  1341,  1342,  1343,  1344,     0,  1346,     0,     0,     0,
       0,  1352,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2268,  2269,     0,     0,     0,     0,     0,     0,     0,
       0,  1770,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
    2023,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   518,   518,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,  1439,     0,  1441,     0,   518,   217,   172,
     394,     0,   518,     0,     0,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   432,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,  2050,
       0,     0,     0,     0,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   252,   253,   254,   255,   404,   405,   406,
     407,   256,  2064,     0,     0,   408,   409,   410,   411,     0,
       0,     0,     0,     0,   412,     0,   413,   261,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   264,    25,
     414,   265,     0,   415,     0,     0,     0,  1501,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1898,  1899,     0,     0,     0,     0,   518,   518,
       0,     0,     0,     0,     0,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,  1928,   612,     0,     0,
       0,     0,     0,     0,     0,   583,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,   275,   416,   417,   418,   276,
       0,     0,     0,     0,  2098,   278,   279,   280,   419,   281,
     282,   283,   420,     0,   421,   121,     0,     0,     0,     0,
       0,     0,   518,   518,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   433,     0,  1618,  2099,     0,     0,   286,
       0,     0,     0,   518,   368,     0,     0,     0,  1654,     0,
       0,   289,  2013,  2014,     0,     0,     0,     0,   518,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,  1657,     0,
       0,   612,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,  2049,     0,     0,     0,
    1694,  1695,  1696,  1697,  1698,  1699,  1700,     0,     0,     0,
       0,  1705,  1706,     0,     0,     0,     0,     0,  1708,     0,
    1710,     0,     0,     0,  1714,     0,     0,  1716,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2089,  2090,     0,     0,
       0,     0,     0,     0,     0,     0,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2108,     0,     0,
       0,     0,     0,     0,   518,   518,   518,   518,   518,     0,
       0,     0,  2118,     0,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,  1787,   612,  1790,     0,     0,
       0,  1797,   845,  1799,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,   518,     0,     0,   612,   394,     0,     0,
       0,     0,     0,     0,     0,  1824,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,     0,     0,     0,  2178,     0,     0,
       0,   395,   396,   397,   398,   399,   400,   401,   402,   403,
       0,     0,     0,     0,   404,   405,   406,   407,     0,     0,
    2193,     0,   408,   409,   410,   411,     0,     0,     0,     0,
       0,   412,     0,   413,     0,     0,     0,     0,  2205,  2206,
    2207,  2208,  2210,     0,     0,     0,     0,   414,     0,     0,
     415,     0,     0,     0,   217,     6,   394,     0,     0,     0,
       0,   218,   219,   220,     0,  1885,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,  2249,     0,     0,
    1658,   396,   397,   398,   399,   400,   401,   402,   403,   252,
     253,   254,   255,   404,   405,   406,   407,   256,   257,     0,
       0,   408,   409,   410,   411,     0,     0,   258,   259,   260,
     412,     0,   413,   261,   262,   263,     0,     0,     0,     0,
       0,     0,     0,     0,   264,    25,   414,   265,     0,   415,
       0,     0,     0,   266,     0,     0,   267,     0,     0,   268,
       0,   269,     0,   416,   417,   418,     0,     0,    42,     0,
       0,  1971,   270,     0,  1972,   419,     0,     0,     0,   420,
       0,   421,     0,     0,   271,     0,    58,    59,     0,   272,
       0,   273,     0,     0,   274,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,    87,     0,
       0,     0,     0,  2006,  2007,     0,  2009,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   416,   417,   418,   276,   277,  2224,     0,     0,
       0,   278,   279,   280,   419,   281,   282,   283,   420,     0,
     421,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2053,  2054,     0,     0,     0,     0,     0,   284,   285,
       0,     0,     0,     0,     0,   286,     0,     0,     0,     0,
     368,     0,     0,     0,  1659,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       6,   394,     0,     0,     0,     0,   218,   219,   220,     0,
    2085,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     0,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   252,   253,   254,   255,   404,   405,
     406,   407,   256,   257,     0,     0,   408,   409,   410,   411,
       0,     0,   258,   259,   260,   412,     0,   413,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,   264,
      25,   414,   265,     0,   415,     0,     0,     0,   266,     0,
       0,   267,     0,     0,   268,     0,   269,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,    58,    59,     0,   272,     0,   273,     0,     0,   274,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,    87,     0,     0,     0,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,  1997,   593,     0,     0,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,   416,   417,   418,
     276,   277,     0,  2147,     0,     0,   278,   279,   280,   419,
     281,   282,   283,   420,     0,   421,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   285,     0,     0,     0,     0,     0,
     286,     0,     0,     0,     0,   368,     0,  2258,     0,   288,
       0,     0,   289,   217,   172,   394,     0,   446,     0,     0,
     218,   219,   220,     0,     0,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   432,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   252,   253,
     254,   255,   404,   405,   406,   407,   256,     0,     0,     0,
     408,   409,   410,   411,     0,     0,     0,     0,     0,   412,
       0,   413,   261,   262,   263,     0,     0,     0,     0,     0,
       0,     0,     0,   264,    25,   414,   265,     0,   415,     0,
       0,     0,   178,     0,     0,   179,     0,     0,   180,     0,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
     447,     0,     0,     0,   612,     0,     0,     0,     0,     0,
    1107,     0,     0,     0,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   848,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
     593,     0,     0,   448,   612,     0,     0,     0,     0,     0,
     275,   416,   417,   418,   276,     0,     0,     0,     0,     0,
     278,   279,   280,   419,   281,   282,   283,   420,     0,   421,
     121,     0,   449,   450,   451,   452,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,   433,     0,
       0,     0,     0,     0,   286,     0,   453,   454,     0,   455,
       0,   456,   217,     6,   367,   457,   289,     0,     0,   218,
     219,   220,     0,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   254,
     255,     0,     0,     0,     0,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,     0,     0,
       0,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,   264,    25,     0,   265,     0,     0,     0,     0,
       0,   266,     0,     0,   267,     0,     0,   268,     0,   269,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,    58,    59,     0,   272,     0,   273,
       0,     0,   274,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,    87,     0,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,   593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
       0,     0,     0,   276,   277,     0,     0,     0,     0,   278,
     279,   280,     0,   281,   282,   283,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,   285,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,   368,   217,
       6,     0,   369,     0,   690,   289,   218,   219,   220,     0,
       0,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,   253,   254,   255,     0,     0,
       0,     0,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   258,   259,   260,     0,     0,     0,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,   264,
      25,     0,   265,     0,     0,     0,     0,     0,   266,     0,
       0,   267,     0,     0,   268,     0,   269,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,    58,    59,     0,   272,     0,   273,     0,     0,   274,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,    87,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   848,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,     0,  1031,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,     0,     0,
     276,   277,     0,     0,     0,     0,   278,   279,   280,     0,
     281,   282,   283,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   516,     0,     0,     0,     0,     0,
     286,     0,     0,     0,     0,   368,   217,     6,  1758,     0,
     586,     0,   289,   218,   219,   220,     0,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   252,   253,   254,   255,     0,     0,     0,     0,   256,
     257,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     259,   260,     0,     0,     0,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,   264,    25,     0,   265,
       0,     0,     0,     0,     0,   266,     0,     0,   267,     0,
       0,   268,     0,   269,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,    58,    59,
       0,   272,     0,   273,     0,     0,   274,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    84,     0,     0,
      87,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
    1232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,     0,     0,     0,   276,   277,     0,
       0,     0,     0,   278,   279,   280,     0,   281,   282,   283,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   285,     0,     0,     0,     0,     0,   286,     0,     0,
       0,     0,   368,   217,     6,     0,   288,     0,     0,   289,
     218,   219,   220,     0,     0,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   253,
     254,   255,     0,     0,     0,     0,   256,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,   261,   262,   263,     0,     0,     0,     0,     0,
       0,     0,     0,   264,    25,     0,   265,     0,     0,     0,
       0,     0,   266,     0,     0,   267,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,    58,    59,     0,   272,     0,
     273,     0,     0,   274,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    84,     0,     0,    87,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,  1233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,     0,     0,   276,   277,     0,     0,     0,     0,
     278,   279,   280,     0,   281,   282,   283,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   654,  1924,     0,
       0,     0,     0,     0,   286,     0,     0,     0,     0,   656,
     217,     6,     0,   332,   586,     0,   289,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,   253,   254,   255,     0,
       0,     0,     0,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,   260,     0,     0,     0,   261,
     262,   263,     0,     0,     0,     0,     0,     0,     0,     0,
     264,    25,     0,   265,     0,     0,     0,     0,     0,   266,
       0,     0,   267,     0,     0,   268,     0,   269,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,    58,    59,     0,   272,     0,   273,     0,     0,
     274,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,    87,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,  1574,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   275,     0,     0,
       0,   276,   277,     0,     0,     0,     0,   278,   279,   280,
       0,   281,   282,   283,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   284,   285,     0,     0,     0,     0,
       0,   286,     0,     0,     0,     0,   287,   217,     6,     0,
     288,     0,     0,   289,   218,   219,   220,     0,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,   254,   255,     0,     0,     0,     0,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     258,   259,   260,     0,     0,     0,   261,   262,   263,     0,
       0,     0,     0,     0,     0,     0,     0,   264,    25,     0,
     265,     0,     0,     0,     0,     0,   266,     0,     0,   267,
       0,     0,   268,     0,   269,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,    58,
      59,     0,   272,     0,   273,     0,     0,   274,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,    87,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,   275,     0,     0,   612,   276,   277,
       0,     0,     0,  1853,   278,   279,   280,  1854,   281,   282,
     283,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   285,     0,     0,     0,     0,     0,   286,     0,
       0,     0,     0,   368,   217,     6,     0,   288,     0,     0,
     289,   218,   219,   220,     0,     0,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
     253,   254,   255,     0,     0,     0,     0,   256,   257,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   259,   260,
       0,     0,     0,   261,   262,   263,     0,     0,     0,     0,
       0,     0,     0,     0,   264,    25,     0,   265,     0,     0,
       0,     0,     0,   266,     0,     0,   267,     0,     0,   268,
       0,   269,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,     0,    58,    59,     0,   272,
       0,   273,     0,     0,   274,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,    75,    76,    77,    78,
      79,    80,     0,     0,     0,    84,     0,     0,    87,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   772,     0,   773,     0,     0,     0,     0,
       0,  1789,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,     0,   276,   277,     0,     0,     0,
       0,   278,   279,   280,     0,   281,   282,   283,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,   516,
       0,     0,     0,     0,     0,   286,     0,     0,     0,     0,
     368,   217,     6,     0,   581,     0,     0,   289,   218,   219,
     220,     0,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   253,   254,   255,
       0,     0,     0,     0,   256,   257,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,   260,     0,     0,     0,
     261,   262,   263,     0,     0,     0,     0,     0,     0,     0,
       0,   264,    25,     0,   265,     0,     0,     0,     0,     0,
     266,     0,     0,   267,     0,     0,   268,     0,   269,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,    58,    59,     0,   272,     0,   273,     0,
       0,   274,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    84,     0,     0,    87,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
    1015,     0,     0,     0,     0,     0,     0,     0,   976,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
       0,     0,   276,   277,     0,     0,     0,     0,   278,   279,
     280,     0,   281,   282,   283,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   516,     0,     0,     0,
       0,     0,   286,     0,     0,     0,     0,   368,   217,     6,
       0,     0,   586,     0,   289,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,   255,     0,     0,     0,
       0,   256,   257,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,   261,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   264,    25,
       0,   265,     0,     0,     0,     0,     0,   266,     0,     0,
     267,     0,     0,   268,     0,   269,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
      58,    59,     0,   272,     0,   273,     0,     0,   274,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    84,
       0,     0,    87,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,  1905,     0,     0,     0,  1906,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,     0,   276,
     277,     0,     0,     0,     0,   278,   279,   280,     0,   281,
     282,   283,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   285,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,   624,   217,     6,     0,   288,     0,
       0,   289,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,   255,     0,     0,     0,     0,   256,   257,
       0,     0,     0,     0,     0,     0,     0,     0,   258,   259,
     260,     0,     0,     0,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,   264,    25,     0,   265,     0,
       0,     0,     0,     0,   266,     0,     0,   267,     0,     0,
     268,     0,   269,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,    58,    59,     0,
     272,     0,   273,     0,     0,   274,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,    87,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,  1936,     0,
       0,     0,  1937,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,     0,     0,   276,   277,     0,     0,
       0,     0,   278,   279,   280,     0,   281,   282,   283,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     285,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,   633,   217,     6,     0,   288,     0,     0,   289,   218,
     219,   220,     0,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   254,
     255,     0,     0,     0,     0,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   260,     0,     0,
       0,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,   264,    25,     0,   265,     0,     0,     0,     0,
       0,   266,     0,     0,   267,     0,     0,   268,     0,   269,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,    58,    59,     0,   272,     0,   273,
       0,     0,   274,     0,     0,     0,     0,     0,    69,    70,
      71,    72,    73,     0,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    84,     0,     0,    87,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,  2110,     0,     0,     0,  2111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
       0,     0,     0,   276,   277,     0,     0,     0,     0,   278,
     279,   280,     0,   281,   282,   283,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,   516,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,   368,   217,
       6,     0,   935,     0,  1416,   289,   218,   219,   220,     0,
       0,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,   253,   254,   255,     0,     0,
       0,     0,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   258,   259,   260,     0,     0,     0,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,   264,
      25,     0,   265,     0,     0,     0,     0,     0,   266,     0,
       0,   267,     0,     0,   268,     0,   269,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,    58,    59,     0,   272,     0,   273,     0,     0,   274,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,    87,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   805,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,     0,     0,
     276,   277,     0,     0,     0,     0,   278,   279,   280,     0,
     281,   282,   283,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   516,     0,     0,     0,     0,     0,
     286,   217,     6,     0,     0,   368,  1635,     0,   218,   219,
     220,     0,   289,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   253,   254,   255,
       0,     0,     0,     0,   256,   257,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,   260,     0,     0,     0,
     261,   262,   263,     0,     0,     0,     0,     0,     0,     0,
       0,   264,    25,     0,   265,     0,     0,     0,     0,     0,
     266,     0,     0,   267,     0,     0,   268,     0,   269,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   270,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,    58,    59,     0,   272,     0,   273,     0,
       0,   274,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,     0,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    84,     0,     0,    87,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   811,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
       0,     0,   276,   277,     0,     0,     0,     0,   278,   279,
     280,     0,   281,   282,   283,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,   516,     0,     0,     0,
       0,     0,   286,   217,     6,     0,     0,   368,     0,     0,
     218,   219,   220,     0,   289,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   253,
     254,   255,     0,     0,     0,     0,   256,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,   261,   262,   263,     0,     0,     0,     0,     0,
       0,     0,     0,   264,    25,     0,   265,     0,     0,     0,
       0,     0,   266,     0,     0,   267,     0,     0,   268,     0,
     269,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   270,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,    58,    59,     0,   272,     0,
     273,     0,     0,   274,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,     0,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    84,     0,     0,    87,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     813,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,     0,     0,     0,   276,   277,     0,     0,     0,     0,
     278,   279,   280,     0,   281,   282,   283,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   284,   285,     0,
       0,     0,     0,     0,   286,     0,     0,     0,     0,   368,
     217,     6,     0,  1766,     0,     0,   289,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,   253,   254,   255,     0,
       0,     0,     0,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   259,   260,     0,     0,     0,   261,
     262,   263,     0,     0,     0,     0,     0,     0,     0,     0,
     264,    25,     0,   265,     0,     0,     0,     0,     0,   266,
       0,     0,   267,     0,     0,   268,     0,   269,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,    58,    59,     0,   272,     0,   273,     0,     0,
     274,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,     0,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    84,     0,     0,    87,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   976,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   275,     0,     0,
       0,   276,   277,     0,     0,     0,     0,   278,   279,   280,
       0,   281,   282,   283,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   654,  1924,     0,     0,     0,     0,
       0,   286,     0,     0,     0,     0,   656,   217,     6,     0,
     332,     0,     0,   289,   218,   219,   220,     0,     0,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,   254,   255,     0,     0,     0,     0,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     258,   259,   260,     0,     0,     0,   261,   262,   263,     0,
       0,     0,     0,     0,     0,     0,     0,   264,    25,     0,
     265,     0,     0,     0,     0,     0,   266,     0,     0,   267,
       0,     0,   268,     0,   269,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   270,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,    58,
      59,     0,   272,     0,   273,     0,     0,   274,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,     0,    75,
      76,    77,    78,    79,    80,     0,     0,     0,    84,     0,
       0,    87,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   977,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,     0,     0,   276,   277,
       0,     0,     0,     0,   278,   279,   280,     0,   281,   282,
     283,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   516,     0,     0,     0,     0,     0,   286,   217,
     172,   394,     0,   368,     0,     0,   218,   219,   220,     0,
     289,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   432,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,     0,     0,     0,     0,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   252,   253,   254,   255,   404,   405,
     406,   407,   256,     0,     0,     0,   408,   409,   410,   411,
       0,     0,     0,     0,     0,   412,     0,   413,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,   264,
      25,   414,   265,     0,   415,   217,   172,   394,     0,     0,
       0,     0,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   432,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
       0,  1658,   396,   397,   398,   399,   400,   401,   402,   403,
     252,   253,   254,   255,   404,   405,   406,   407,   256,     0,
       0,     0,   408,   409,   410,   411,     0,     0,     0,     0,
       0,   412,     0,   413,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,   264,    25,   414,   265,     0,
     415,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,   416,   417,   418,
     276,     0,     0,     0,     0,     0,   278,   279,   280,   419,
     281,   282,   283,   420,     0,   421,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   433,     0,     0,     0,     0,     0,
     286,     0,     0,     0,     0,   368,     0,     0,     0,  1941,
       0,     0,   289,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1028,     0,     0,     0,     0,
       0,     0,   275,   416,   417,   418,   276,     0,     0,     0,
       0,     0,   278,   279,   280,   419,   281,   282,   283,   420,
       0,   421,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   284,
     433,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,   368,   217,   172,   394,  1823,     0,     0,   289,   218,
     219,   220,     0,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   432,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,     0,     0,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   252,   253,   254,
     255,   404,   405,   406,   407,   256,     0,     0,     0,   408,
     409,   410,   411,     0,     0,     0,     0,     0,   412,     0,
     413,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,   264,    25,   414,   265,     0,   415,   217,   172,
       0,     0,     0,     0,     0,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   432,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,   255,     0,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   264,    25,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
     416,   417,   418,   276,     0,     0,     0,     0,     0,   278,
     279,   280,   419,   281,   282,   283,   420,     0,   421,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,   433,     0,     0,
       0,     0,     0,   286,     0,   217,   172,     0,   368,     0,
       0,     0,   218,   219,   220,   289,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   432,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,     0,   276,
     252,   253,   254,   255,     0,   278,   279,   280,   256,   281,
     282,   283,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   262,   263,     0,     0,     0,
       0,     0,   284,   433,     0,   264,    25,     0,   265,   286,
       0,     0,     0,     0,   368,   217,   172,     0,   636,     0,
     903,   289,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   432,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,   255,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,   264,    25,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,     0,     0,   276,     0,     0,     0,
       0,     0,   278,   279,   280,     0,   281,   282,   283,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,   656,   217,   172,     0,   332,     0,     0,   289,   218,
     219,   220,     0,     0,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   432,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,     0,     0,     0,   276,   252,   253,   254,
     255,     0,   278,   279,   280,   256,   281,   282,   283,     0,
       0,     0,   121,     0,     7,     8,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,     0,     0,   284,
     433,     0,   264,    25,     0,   265,   286,   217,   172,     0,
    1367,   368,     0,     0,   218,   219,   220,     0,   289,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   432,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,   254,   255,     0,     0,     0,     0,
     256,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   261,   262,   263,    43,
      44,    45,    46,     0,     0,    48,     0,   264,    25,     0,
     265,     0,     0,     0,   786,    57,     0,     0,    60,   787,
       0,   788,   789,     0,   790,     0,     0,     0,     0,   275,
       0,     0,     0,   276,     0,     0,     0,     0,     0,   278,
     279,   280,    81,   281,   282,   283,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   284,   433,    97,    98,
      99,     0,     0,   286,   217,   172,     0,  1531,   368,  1126,
       0,   218,   219,   220,     0,   289,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   432,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,     0,     0,   276,   252,
     253,   254,   255,     0,   278,   279,   280,   256,   281,   282,
     283,     0,     0,     0,   121,   812,     7,     8,     0,     0,
       0,     0,     0,   261,   262,   263,     0,     0,     0,     0,
       0,   284,   433,     0,   264,    25,     0,   265,   286,   217,
     172,     0,  1597,   368,     0,     0,   218,   219,   220,     0,
     289,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   432,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,   253,   254,   255,     0,     0,
       0,     0,   256,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   261,   262,
     263,    43,    44,    45,    46,     0,     0,    48,     0,   264,
      25,     0,   265,     0,     0,     0,   786,    57,     0,     0,
      60,   787,     0,   788,   789,     0,   790,     0,     0,     0,
       0,   275,     0,     0,     0,   276,     0,     0,     0,     0,
       0,   278,   279,   280,    81,   281,   282,   283,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,   433,
      97,    98,    99,     0,     0,   286,   217,   172,     0,     0,
     368,     0,     0,   218,   219,   220,     0,   289,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   432,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,     0,     0,     0,
     276,   252,   253,   254,   255,     0,   278,   279,   280,   256,
     281,   282,   283,     0,     0,     0,   121,   984,     7,     8,
       0,     0,     0,     0,     0,   261,   262,   263,     0,     0,
       0,     0,     0,   284,   433,     0,   264,    25,     0,   265,
     286,   217,   172,     0,     0,   368,     0,     0,   218,   219,
     220,     0,   289,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     432,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   253,   254,   255,
       0,     0,     0,     0,   256,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     261,   262,   263,    43,    44,    45,    46,     0,     0,    48,
       0,   264,    25,     0,   265,     0,     0,     0,   786,    57,
       0,     0,    60,   787,     0,   788,   789,     0,   790,     0,
       0,     0,     0,   275,     0,     0,     0,   276,     0,     0,
       0,     0,     0,   278,   279,   280,    81,   281,   282,   283,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   433,    97,    98,    99,     0,     0,   286,   217,   172,
       0,     0,   368,  1651,     0,   218,   219,   220,     0,   289,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   432,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,     0,
       0,     0,   276,   252,   253,   254,   255,     0,   278,   279,
     280,   256,   281,   282,   283,   172,   394,     0,   121,  1009,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,     0,     0,   284,   433,     0,   264,    25,
       0,   265,   286,     0,     0,     0,     0,   368,  1988,     0,
       0,     0,     0,     0,   289,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   399,   400,   401,   402,   403,     0,
       0,     0,     0,   404,   405,   406,   407,     0,     0,     0,
       0,   408,   409,   410,   411,     0,     0,     0,     0,     0,
     412,     0,   413,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   414,     0,     0,   415,
       0,     0,     0,   178,     0,     0,   179,     0,     0,   180,
       0,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   447,     0,     0,     0,   275,     7,     8,     0,   276,
       0,     0,     0,     0,     0,   278,   279,   280,     0,   281,
     282,   283,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   284,   433,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,   368,     0,     0,     0,     0,     0,
       0,   289,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,   416,   417,   418,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   419,     0,     0,     0,   420,     0,
     421,   121,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,  1823,     0,   786,    57,     7,     8,
      60,   787,     0,   788,   789,     0,   790,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
      97,    98,    99,     0,     0,     0,   786,    57,     7,     8,
      60,   787,     0,   788,   789,     0,   790,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
      97,    98,    99,     0,     0,     0,     0,     0,   786,    57,
       7,     8,    60,   787,     0,   788,   789,  1060,   790,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,    97,    98,    99,     0,     0,     0,   786,    57,
       7,     8,    60,   787,     0,   788,   789,  1062,   790,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,    97,    98,    99,     0,     0,     0,     0,     0,
     786,    57,     7,     8,    60,   787,     0,   788,   789,  1266,
     790,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,    97,    98,    99,     0,     0,     0,
     786,    57,     7,     8,    60,   787,     0,   788,   789,  1268,
     790,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,    97,    98,    99,     0,     0,     0,
       0,     0,   786,    57,     7,     8,    60,   787,     0,   788,
     789,  1269,   790,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,    97,    98,    99,     0,
       0,     0,   786,    57,     7,     8,    60,   787,     0,   788,
     789,  1288,   790,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    97,    98,    99,     0,
       0,     0,     0,     0,   786,    57,     7,     8,    60,   787,
       0,   788,   789,  1307,   790,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,    97,    98,
      99,     0,     0,     0,   786,    57,     7,     8,    60,   787,
       0,   788,   789,  1325,   790,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,    97,    98,
      99,     0,     0,     0,     0,     0,   786,    57,     0,     0,
      60,   787,     0,   788,   789,  1359,   790,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
      97,    98,    99,     0,     0,     0,   786,    57,     0,     0,
      60,   787,     0,   788,   789,  1523,   790,     0,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    81,    -4,    -4,     0,     0,     0,
       0,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
      97,    98,    99,   612,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,  1138,     0,     0,     0,  2169,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,    -4,     0,     0,     0,     0,    -4,    -4,     0,     0,
       0,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,  2226,     0,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,    -4,     0,     0,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     9,    10,    11,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1178,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14,     0,
       0,     0,     0,    15,    16,     0,     0,     0,     0,    17,
       0,     0,     0,     0,    18,    19,    20,    21,    22,     0,
      23,    24,     0,    25,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,    42,    43,    44,    45,
      46,    47,     0,    48,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,     0,    66,    67,    68,     0,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    92,    93,    94,     0,     0,     0,
      95,     0,     0,     0,     0,    96,    97,    98,    99,   172,
     394,   100,     0,   101,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,   120,     0,   121,
     122,     0,     0,     0,   395,   396,   397,   398,   399,   400,
     401,   402,   403,     7,     8,     0,     0,   404,   405,   406,
     407,     0,     0,     0,     0,   408,   409,   410,   411,     0,
       0,     0,     0,     0,   412,     0,   413,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     414,     0,     0,   415,     0,     0,     0,   178,     0,     0,
     179,     0,     0,   180,     0,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,   447,     0,     0,     0,   612,
       0,   826,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     7,     8,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   786,    57,     0,     0,    60,   787,     0,
     788,   789,     0,   790,     0,     0,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,  1073,   416,   417,   418,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   419,     0,
       0,     0,   420,     0,   421,   121,     0,    97,    98,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,   786,    57,     0,     0,    60,
     787,     0,   788,   789,     0,   790,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,    97,
      98,    99,     0,     0,     0,     0,  1188,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1189,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1190,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1191,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1192,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1197,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1198,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1200,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1317,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1340,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1426,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1430,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1525,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1526,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1573,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1701,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1702,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1703,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1851,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1975,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1976,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2008,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2080,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2137,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2138,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2153,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2187,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2214,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2219,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2220,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,  1165,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,  1213,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
    1214,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,  1258,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,  1291,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,  1305,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,  1312,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,  1373,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,  1393,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,  1429,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,  1478,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,  1479,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
    1480,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,  1527,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,  1603,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,  1903,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,  1914,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,  1955,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,  2029,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,  2045,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,  2057,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
       0,  2081,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
    2116,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,  2126,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,     0,     0,  2127,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,  2151,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,     0,     0,  2200,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,     0,     0,  2239,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,     0,     0,  2257,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,     0,     0,  2275,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
       0,     0,  2276,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,     0,
     745,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,     0,   968,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,     0,  2022,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,   772,     0,   773,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
    1034,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,  1083,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,  1237,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,  1306,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,  1308,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,     0,     0,  1315,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   744,
     608,   609,   610,   611,     0,     0,     0,     0,   612,     0,
       0,     0,  1316,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   744,   608,   609,   610,
     611,     0,     0,     0,     0,   612,     0,     0,     0,  1408,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   744,   608,   609,   610,   611,     0,     0,
       0,     0,   612,     0,     0,     0,  1422,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     744,   608,   609,   610,   611,     0,     0,     0,     0,   612,
       0,     0,     0,  1632,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,     0,     0,
    1722,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   744,   608,   609,   610,   611,     0,
       0,     0,     0,   612,     0,     0,     0,  1775,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   744,   608,   609,   610,   611,     0,     0,     0,     0,
     612,     0,     0,     0,  1967,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   744,   608,
     609,   610,   611,     0,     0,     0,     0,   612,     0,     0,
       0,  2012,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   744,   608,   609,   610,   611,
       0,     0,     0,     0,   612,     0,     0,     0,  2030,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   827,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   828,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   830,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   831,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   832,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   834,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   835,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   836,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   837,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   838,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   839,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   840,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   842,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   843,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   844,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   915,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,   949,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,   998,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1015,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1023,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1025,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1026,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1032,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1033,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1071,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1082,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1143,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1147,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1159,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1236,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1246,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1247,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1248,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1257,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1259,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1260,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1290,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1292,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1293,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1294,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1295,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1296,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1297,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1298,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1304,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1318,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1320,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1358,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1407,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1421,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1633,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1668,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1709,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1721,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1838,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1840,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1843,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1850,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1904,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  1913,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  1940,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  2011,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  2078,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  2079,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612,     0,  2213,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   744,   608,   609,
     610,   611,     0,     0,     0,     0,   612,     0,  2254,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   744,   608,   609,   610,   611,     0,     0,     0,
       0,   612
};

static const yytype_int16 yycheck[] =
{
       3,  1285,     3,   325,    64,   651,   652,  1289,    70,    71,
     162,    73,  1486,   148,     4,   769,  1806,  1760,  1808,     4,
       4,   775,    25,     6,     6,     4,     6,     4,     4,    25,
       4,     6,     4,     6,     5,  1991,     5,   111,     4,   113,
     108,     5,     5,     4,   108,     7,  1793,     6,     6,   144,
     144,   108,   102,    56,   247,   248,    95,     6,   256,   257,
       6,     6,     6,     4,   108,   260,     4,   162,     4,   247,
     248,   121,     7,   268,   148,   268,   133,   172,   173,   174,
       9,     4,    85,   178,   179,   252,   253,    90,   144,   133,
     268,   258,    95,     9,   165,    36,    37,   100,     6,     4,
       6,   195,     4,   177,     9,     9,   162,     0,   111,   183,
       4,  1858,     7,    36,    37,    94,   172,   173,   174,   247,
     248,   192,   178,   179,   263,   166,     9,     4,   267,     6,
     247,   248,  1875,   260,    36,    37,     9,   208,   209,     6,
     268,   268,    36,    37,   260,   148,     9,   264,   149,   265,
     153,   154,   155,     6,     7,   247,   248,   247,   248,   162,
     247,   248,   247,   248,   264,   204,     6,     6,   268,   264,
     111,   112,   260,   263,   262,   214,   268,   259,     7,   261,
     268,   268,   260,   268,   262,   263,   268,     7,   111,   112,
    2146,   259,     7,   168,   105,   259,   199,   108,   258,   259,
     260,   204,   247,   248,     7,   208,   209,   180,   264,   111,
     112,   214,   215,   216,   247,   248,   182,   183,   184,   185,
       7,    14,   180,   268,   203,   102,   247,   248,   194,   108,
     196,   197,   198,   199,   200,   268,   247,   248,   204,   205,
    1714,   207,   260,   247,   248,   230,   207,   268,   263,   105,
     268,   230,   108,   230,   230,     6,   230,   268,   230,  1543,
     242,   243,   242,   243,   268,   121,   328,   329,   271,   259,
     309,   310,   311,   259,   336,   337,  2019,   261,   259,   263,
     263,   266,   285,   267,   263,   288,   289,   263,   260,   263,
     262,   259,   263,   289,   263,   263,   337,     6,   264,   263,
     263,   304,   305,   265,   263,   308,   309,   310,   311,     3,
     349,   350,   351,   259,   263,   356,   319,   263,   263,   263,
     323,   259,   325,   259,   259,   230,   261,   366,  1082,  1083,
     259,  2074,   261,    27,     4,   259,   265,   232,   233,   234,
     235,   247,   248,   259,   347,   261,   349,   350,   351,   265,
     265,   256,   257,   268,   259,   259,   261,   261,   263,   260,
     265,   256,   257,   366,   256,   257,   369,   268,     6,    63,
     265,   263,   446,   256,   257,   259,   259,   261,   261,   262,
     247,   248,   265,   256,   257,   259,   259,   428,   261,   430,
       6,  2181,   265,   256,   257,   108,   259,   110,   261,   440,
     247,   248,   265,   232,   233,   234,   235,   247,   248,   561,
     247,   248,   232,   233,   234,   235,     6,   232,   233,   234,
     235,   268,   116,   259,     4,   261,   263,   256,   257,   232,
     233,   234,   235,   436,     4,   438,   256,   257,   261,   442,
     443,   256,   257,   247,   248,   232,   233,   234,   235,   247,
     248,   247,   248,   261,   148,   458,    36,    37,   259,   153,
     154,   155,   465,   260,   268,   262,    36,    37,   162,   259,
     268,   268,   268,  2216,   259,   247,   248,   247,   248,   149,
     150,   151,   152,   256,   257,   155,   265,   490,   267,   247,
     248,   144,   265,   263,   164,   105,   268,   167,   108,   109,
     110,   260,   259,   262,   578,   199,   457,   247,   248,   162,
     268,   121,   105,   516,   259,   108,   144,   110,  1164,   172,
     173,   174,   216,  2266,   262,   178,   179,     4,   268,   260,
     268,   111,   112,   572,   162,  2009,   259,   268,   541,   247,
     248,   111,   112,   262,   172,   173,   174,   550,   551,   268,
     178,   179,   555,   259,   557,   558,   559,   560,   561,   260,
     268,   713,   259,   257,   567,   247,   248,   268,   571,   572,
     573,   574,   575,   576,   577,   259,   579,   187,   581,   273,
     274,   577,   260,   579,   247,   248,   268,   649,   650,   260,
     268,   262,   654,   247,   248,   259,     4,   268,     6,   640,
     102,   642,   643,   105,   607,   268,   108,   259,   110,   261,
     613,   264,   192,   193,   268,   259,   259,   261,   659,   121,
     260,   265,   192,   193,   268,   102,   259,   144,   268,   106,
     263,   263,   635,   636,   769,   112,   113,   678,   115,   116,
     102,   260,   259,   105,   259,   162,   108,   259,   263,   268,
     651,   652,   726,  1299,   259,   172,   173,   174,   259,   121,
     137,   178,   179,   263,   705,   616,   123,     8,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   684,   685,   686,   108,   258,   247,   248,   263,   692,
     105,   247,   248,   108,   110,   110,   264,   260,   259,   262,
     268,     6,   263,   259,   745,   268,   121,   263,   711,   712,
     713,   714,   715,   716,   717,   718,   719,     6,   721,   722,
     723,   724,   725,   259,   727,   728,   729,   730,   731,   789,
     260,   734,   262,   264,   730,   149,   150,   268,   268,     8,
     264,   155,   436,   746,   268,   256,   257,   264,   259,   259,
     261,   825,   263,   447,   263,   259,   759,   261,  1512,   247,
     248,   249,   250,   251,   252,   253,   149,   150,   108,   264,
     258,   774,   155,   268,   263,   469,   259,   780,   249,   250,
     251,   252,   253,   256,   257,   264,   259,   258,   261,   268,
     484,   105,   264,   796,   797,   263,   268,   263,   749,   802,
     260,   804,   262,   263,   807,   808,   259,   256,   257,   263,
     259,   946,   261,   816,   259,   818,   261,   264,   263,   148,
     108,   268,   105,   264,   153,   154,   155,   268,   105,   264,
     264,   264,   783,   268,   268,   268,   264,   264,   264,   264,
     268,   268,   268,   268,   264,   848,   264,   850,   268,   800,
     268,   264,   264,   264,  1608,   268,   268,   268,   264,   810,
     108,   555,   268,   557,  1618,   559,   560,   561,   264,   264,
     199,   264,   268,   268,   264,   268,   247,   248,   268,   108,
     574,   575,   264,   886,     4,   959,   268,   216,  2170,     4,
     264,     4,     4,   896,   268,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   975,   259,   264,   919,   258,  2202,   268,
     982,   264,   264,   264,   986,   268,   268,   259,   259,     6,
     264,   972,   935,  1068,   268,     6,     8,   264,   264,   264,
     261,   268,   268,   268,   947,  2227,   264,  1082,  1083,     6,
     268,   264,   264,   956,   264,   268,   268,   264,   268,   259,
    2244,   268,   261,   657,  1099,   968,   917,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     6,   264,   681,   264,   258,
     268,   263,   268,   264,   264,   264,   264,   268,   268,   264,
     268,   267,   264,   268,     4,     5,   268,   264,     6,   264,
     264,   268,  1086,   268,   268,   267,   263,   711,   712,   713,
     714,   715,   716,   717,   718,   719,   259,   721,   722,   723,
     724,     9,   264,   727,   728,   729,   268,   264,   264,   259,
     264,   268,   268,   737,   268,   259,   740,   259,   259,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   263,   753,
     259,  1383,    62,    63,    64,    65,   259,   195,   195,   195,
      70,    71,    72,    73,  1077,   133,   264,   263,  1140,    79,
     268,    81,  1085,   264,   264,   264,   259,   268,   268,   268,
    1093,   259,   259,   259,   788,    95,   790,    56,    98,  1745,
    1746,  1236,  1237,  1106,   195,   264,   264,   436,  1111,   268,
     268,   263,   259,   807,   259,   259,   259,   263,     4,     6,
     259,   263,   263,   263,   818,   263,   259,   259,   259,   259,
     259,     6,     6,  1084,   259,     7,     6,   261,  1141,  1142,
     263,  1144,  1145,  1146,   263,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,   263,   263,  1160,   263,   261,
     261,   261,     6,  1164,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   263,   259,   259,   195,   258,   261,   260,   259,
     262,   259,   259,   259,   259,   259,     6,     6,     6,  1202,
    1203,  1204,   263,     8,     6,     8,   259,   263,     7,     6,
       6,   211,   212,   213,   263,   263,   263,    97,   264,   260,
       7,     6,     6,   223,  1227,   268,   555,   227,   557,   229,
     559,   560,   268,   260,   263,   263,   258,   263,   263,   263,
    1243,  1244,  1245,    67,     8,   574,   575,   265,     7,     7,
     259,     6,   260,     7,     6,     6,   215,   263,     7,     6,
     264,   192,   263,     6,     6,   264,   262,   264,   260,  1220,
     263,  1222,  1407,  1408,   265,     7,   261,   971,   259,   973,
     974,   263,     6,     6,  1235,     6,     6,     6,   260,  1611,
     261,     7,     7,   987,     7,     7,     7,  1300,  1299,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     263,     6,   271,  1007,  1265,   260,  1319,   268,  1321,  1322,
     262,   268,   268,   264,   268,   260,     7,   264,  1331,   265,
       7,   263,     4,  1336,   263,  1029,     6,  1340,   265,   264,
     264,   263,     7,   144,     6,   265,  1349,     7,  1351,   308,
       7,  1354,     7,   260,   260,   268,   268,  1431,     9,  1433,
     319,   260,   262,   268,   323,   267,   195,  1370,   265,     7,
     165,   264,  1066,   263,     6,     6,     6,  1328,  1329,  2025,
    1383,    49,    49,   712,   265,   714,   715,   716,   717,   718,
     719,   259,   721,   722,   723,   724,   263,   259,   727,   728,
     729,   265,  1353,   263,   259,  1408,   265,   259,     7,  1360,
    1413,     7,  1415,     7,   268,   195,     7,  1111,   260,     7,
       7,     6,   260,   268,     7,     7,     7,     7,  1379,     7,
    1433,   120,     4,   263,   259,     6,   263,     7,     6,   102,
       7,     7,  1445,     6,     8,     7,  1449,     7,     7,     7,
       7,     6,     6,     6,   108,  1406,     7,     7,     6,     4,
       7,     7,   266,     6,   264,     6,   260,  1619,  1620,  1420,
     268,   263,   263,  1608,   263,   268,  1427,     6,   807,     7,
    1542,     6,   261,   442,   443,     6,     6,   259,   259,   818,
     263,     6,     6,     6,   264,     6,   265,     6,  1820,   458,
     262,   268,     6,  1506,  1507,  1508,     6,     6,   137,  1203,
    1204,  1514,  1515,  1516,     6,     6,     6,  1591,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   264,     6,   260,
    1533,   260,     6,     4,     6,   263,   263,     7,     6,   261,
       7,  1544,     6,     6,     6,   263,   263,     6,     6,  1552,
     264,   191,     6,  1556,   263,  1596,     6,     6,   268,  1600,
       7,     6,     6,   260,  1567,     6,  1569,   263,     4,   263,
     263,   263,   263,  1267,     7,   263,   263,   263,   268,   263,
    1654,   259,   265,   268,   263,  1720,   268,     6,   264,     6,
     259,     6,     6,   259,     6,   144,   106,     6,     5,   558,
       6,   260,   263,     6,   268,   263,     6,   263,  1611,  1671,
     144,   144,   571,     6,   573,   268,  1619,  1620,     6,     6,
       6,     6,  1625,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     6,
    1643,   268,  1336,   258,   260,   268,  1340,     6,     6,     6,
     268,  1654,   263,   263,     6,  1349,  1659,  1351,     6,     6,
    1354,     6,     6,     6,     6,   263,     7,  1741,   148,     5,
    1364,  1823,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     263,   260,     6,     6,   258,     6,   260,     6,   263,  1761,
    1762,  1763,  1764,  1765,  1766,     7,     6,   263,     6,   144,
       7,   263,  1786,   190,  1408,     6,   260,     6,     6,  1793,
    1794,   263,     6,     6,   264,   264,   263,   265,   264,  1732,
       6,     6,   264,   264,  1737,  1738,   263,     6,   264,  2061,
    1814,     6,   260,     6,  1745,  1746,   263,     6,     6,     6,
     193,   263,   259,     6,     6,   260,   264,  1760,   264,     6,
     263,   263,   263,  1766,     6,   263,     6,   264,  1771,   263,
       6,     6,     6,     6,   263,     6,     6,  1780,     6,     6,
       6,     6,  1111,     6,   260,  1788,     6,     6,  1791,   264,
       6,   264,     6,     6,   263,     6,     6,   263,   263,     6,
     759,  1419,  2183,  1992,  1481,  1666,  1809,   487,  1952,  1728,
    1813,     3,     3,  1444,  1095,     3,     3,  1820,  2021,  1822,
    1823,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,  1588,
     628,     3,  1620,   258,   807,  1793,  1813,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1858,    -1,    -1,    -1,    -1,
      -1,  1812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1875,    -1,  1203,  1204,    -1,    -1,    -1,    -1,
    1954,    -1,    -1,    -1,  1887,  1888,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,  1912,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1924,    -1,  1997,    -1,  1619,  1620,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1941,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     919,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1978,  2038,  2039,  2040,  2041,
    2042,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1993,    -1,    -1,  2034,    -1,  1998,    -1,   956,  2001,  2002,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,    -1,
      -1,  1340,    -1,    -1,    -1,    -1,  2019,    -1,    -1,  2022,
    1349,    -1,  1351,    -1,  2025,  1354,    -1,    -1,    -1,    -1,
    2033,    -1,    -1,    -1,  2037,    -1,    -1,    -1,    -1,    -1,
    2102,    -1,    -1,    -1,  2106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2061,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2074,    -1,  2147,    -1,    -1,    -1,    -1,    -1,  1408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2131,    -1,    -1,    -1,  1788,  2157,    -1,  1791,    -1,  2161,
    2103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1806,    -1,  1808,  2177,    -1,    -1,  1077,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1823,
    2171,    -1,    -1,    -1,  1093,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,  2155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2222,  2223,    -1,    -1,  1858,    -1,    -1,    -1,    -1,    -1,
    2173,  2174,  2175,  2176,  2177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1141,  1142,    -1,  1144,  1145,  1146,    -1,  1148,
    1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2216,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,  2232,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,  1202,    -1,    -1,    -1,    -1,    -1,    -1,
    2253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2266,    -1,    -1,    -1,    -1,  1227,  2272,
    2273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,  2285,    -1,  1243,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,  1643,    -1,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,  1300,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,
    1319,    -1,  1321,  1322,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1370,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,
      -1,  2115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     6,   211,   212,
     213,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1788,
     223,    -1,  1791,    -1,   227,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,    -1,  1433,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1445,  2181,    -1,    -1,
    1449,    -1,    -1,   256,   257,    -1,    -1,    -1,    -1,    -1,
     263,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,  2203,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1506,  1507,  1508,
      -1,    -1,    -1,    -1,    -1,  1514,  1515,  1516,    -1,  2253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1533,    -1,    -1,    -1,  2272,  2273,
      -1,    -1,    -1,    -1,    -1,  1544,    -1,    -1,    -1,    -1,
      -1,  2285,    -1,  1552,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1567,    -1,
    1569,    -1,    -1,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1625,   276,   277,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,  1654,    -1,    -1,    -1,   258,
     148,    -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,
     188,   189,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,    -1,   200,   201,   202,   203,    -1,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1732,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,   396,   397,    -1,
      -1,    -1,   401,   402,   403,   404,   405,   406,   407,    -1,
     409,  1760,    -1,    -1,    -1,   414,   415,    -1,    -1,   418,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1780,    -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   284,   285,   286,   287,
     288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1809,    -1,    -1,    -1,    -1,   303,   304,   305,    -1,    -1,
      -1,    -1,    -1,  1822,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   321,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   331,   332,    -1,    -1,    -1,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,
     348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1875,    -1,    -1,    -1,
     368,   369,    -1,    -1,  2253,    -1,    -1,    -1,    -1,    -1,
      -1,   379,    -1,   381,   382,    -1,   384,    -1,    -1,    -1,
     388,   389,   390,  2272,  2273,   393,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1912,    -1,    -1,  2285,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
     589,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,    -1,
     438,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,   456,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1978,
      -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1993,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,   497,
      -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,
    2019,    -1,    -1,    -1,    -1,    -1,    -1,   515,   516,    -1,
      -1,    -1,    -1,   521,  2033,    -1,    -1,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   550,   551,    -1,   553,   554,    -1,   556,    -1,
      -1,    -1,    -1,    -1,    -1,  2074,    -1,    -1,   566,    -1,
      -1,   569,   570,    -1,    -1,    -1,    -1,    -1,   576,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2103,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,    -1,   614,   615,    -1,    -1,
      -1,    -1,    -1,    -1,   622,   623,   624,    -1,    -1,    -1,
      -1,    -1,   630,   631,   632,   633,    -1,   635,   636,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   654,   655,   656,    -1,
      -1,    -1,   660,   661,   662,   663,   664,   665,   666,   667,
     668,    -1,    -1,    -1,    -1,    -1,   674,   675,    -1,   677,
      -1,    -1,   680,    -1,    -1,    -1,   684,   685,   686,   687,
      -1,    -1,    -1,   691,   692,   693,   694,   695,    -1,    -1,
     698,    -1,   700,    -1,    -1,    -1,    -1,  2216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   734,    -1,    -1,    -1,
      -1,    -1,    -1,   741,   742,    -1,   744,    -1,    -1,   747,
     748,    -1,    -1,    -1,   913,    -1,    -1,  2266,   756,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   774,    -1,   776,   208,
     209,    -1,    -1,   781,   782,    -1,    -1,   946,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   796,    -1,
     798,   799,    -1,    -1,   802,    -1,   804,   805,    -1,    -1,
      -1,   809,    -1,   811,    -1,   813,    -1,    -1,    -1,    -1,
      -1,   819,    -1,    -1,    -1,   823,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,   846,   258,
     848,    -1,   850,    -1,    -1,    -1,   285,    -1,    -1,   288,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   304,   305,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   886,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   896,   897,
     898,   899,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   935,    -1,    -1,
     369,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,   947,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   955,    -1,    -1,
      -1,   959,    -1,    -1,    -1,    -1,    -1,   965,    -1,    -1,
     968,    -1,  1131,    -1,    -1,    -1,    -1,    -1,   976,   977,
      -1,    -1,    -1,    -1,   982,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   999,    -1,    -1,  1002,    62,    63,    64,    65,   438,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,   304,
     305,    -1,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,
    1028,    -1,  1030,  1031,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,  1228,
      -1,    -1,    -1,    -1,    -1,  1073,    -1,    -1,    -1,    -1,
      -1,    -1,  1080,    -1,    -1,    -1,    -1,   516,    -1,  1087,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1100,  1101,    -1,    -1,    -1,    -1,  1106,    -1,
      -1,    -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1138,    -1,    -1,    -1,    -1,    -1,    -1,   576,    -1,    -1,
      -1,    -1,   581,   438,   211,   212,   213,    -1,    -1,    -1,
      -1,    -1,  1160,    -1,    -1,    -1,   223,    -1,    -1,    -1,
     227,    -1,   229,   230,    -1,    -1,    -1,    -1,   607,    -1,
    1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1188,  1189,  1190,  1191,  1192,    -1,    -1,    -1,    -1,  1197,
    1198,    -1,  1200,    -1,    -1,    -1,   635,   636,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1215,  1216,    -1,
      -1,    -1,    -1,    -1,    -1,  1223,  1224,    -1,    -1,    -1,
      -1,  1390,  1391,    -1,  1232,  1233,    -1,    -1,     6,    -1,
    1238,  1239,    -1,    -1,    -1,    -1,  1244,  1245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   684,   685,   686,    -1,    -1,
      -1,    -1,    -1,   692,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1486,    -1,    -1,
      -1,    -1,    -1,  1331,    -1,    -1,  1495,    -1,    -1,    -1,
      -1,  1339,    -1,    -1,    -1,   774,    -1,    -1,    -1,    -1,
     635,   636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1361,  1362,    -1,    -1,   796,  1366,    -1,
      -1,    -1,    -1,   802,    -1,   804,    -1,    -1,    -1,  1377,
      -1,    -1,  1380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,   684,
     685,   686,    -1,    -1,    -1,    -1,    -1,   692,    -1,    -1,
      -1,  1409,    -1,    -1,  1412,  1413,  1414,  1415,    -1,   848,
      -1,   850,    -1,    -1,    -1,  1423,    -1,    -1,  1426,    -1,
    1428,    -1,  1430,  1431,    -1,    -1,  1434,  1435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   734,
      -1,    -1,    -1,    -1,     6,    -1,    -1,   886,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   896,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,   774,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1658,
      -1,    -1,    -1,    -1,    -1,    -1,   935,    -1,    -1,    -1,
      -1,   796,    -1,    -1,    -1,  1513,    -1,   802,   947,   804,
      -1,    -1,    -1,    -1,    -1,    -1,  1524,  1525,  1526,    -1,
      -1,    -1,    -1,    -1,    -1,  1533,    -1,  1535,    -1,   968,
      -1,    -1,    -1,    -1,  1542,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1556,    -1,
      -1,    -1,    -1,    -1,  1562,  1563,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1573,  1574,  1575,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,
      -1,   886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   896,    -1,    -1,    -1,    -1,    -1,  1615,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1623,  1624,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
     935,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,    -1,
      -1,  1659,   947,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1106,    -1,    -1,
      -1,    -1,    -1,   968,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,  1701,  1702,  1703,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1712,    -1,    -1,    -1,    -1,  1717,
    1718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1160,  1730,    -1,    -1,    -1,    -1,    -1,    -1,  1737,
    1738,  1739,    -1,  1741,    -1,    -1,    -1,    -1,    -1,  1747,
    1748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,  1766,    -1,
      -1,    -1,    -1,  1771,  1772,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,
      -1,  1789,    -1,    -1,    -1,  1793,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1802,  1803,    -1,  1805,    -1,    -1,
      -1,    -1,    -1,    -1,   618,  1244,  1245,  1815,     4,     5,
      -1,  1106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1829,    -1,    -1,    -1,    -1,  1834,  1835,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1848,    -1,    -1,  1851,  1852,    -1,  1854,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,  1160,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,  1887,
    1888,    -1,    -1,    79,    -1,    81,  1894,  1895,    -1,    -1,
      -1,    -1,  1331,    -1,    -1,    -1,    -1,    -1,  1906,    95,
      -1,    -1,    98,    -1,    -1,    -1,   102,  1915,    -1,   105,
      -1,    -1,   108,    -1,   110,    -1,  1924,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,  1937,
    1938,    -1,    -1,  1941,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,  1244,
    1245,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1975,  1976,    -1,
      -1,    -1,    -1,    -1,  1413,    -1,  1415,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1996,    -1,
      -1,    -1,    -1,  2001,  2002,  2003,    -1,    -1,    -1,    -1,
    2008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2022,   211,   212,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,  2037,
      -1,   227,     6,   229,   230,    -1,  1331,    -1,  2046,    -1,
      -1,    -1,   856,   857,   858,   859,   860,   861,   862,   863,
     864,   865,   866,    -1,   868,   869,   870,   871,    -1,   873,
     874,   875,   876,  2071,   260,    -1,   262,   263,    -1,  2077,
       6,    -1,  2080,    -1,    -1,   889,    -1,   891,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   902,    -1,
      -1,    -1,    -1,    -1,    -1,   909,   910,    -1,    -1,    -1,
      -1,    -1,    -1,  2111,   918,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1556,  1413,    -1,
    1415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2137,
    2138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2152,  2153,    -1,  2155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2168,    -1,    -1,    -1,    -1,  2173,  2174,  2175,  2176,  2177,
      -1,    -1,    -1,    -1,    -1,  2183,    -1,    -1,    -1,  2187,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,  2214,    -1,    -1,    -1,
      -1,  2219,  2220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1659,  1035,  1036,  1037,  2232,     6,    -1,  1041,  1042,    -1,
      -1,  1045,  1046,  1047,  1048,    -1,  1050,    -1,    -1,    -1,
      -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2259,  2260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1556,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       6,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1737,  1738,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,  1137,    -1,  1139,    -1,  1766,     3,     4,
       5,    -1,  1771,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     6,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    -1,    98,    -1,    -1,    -1,  1241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1737,  1738,    -1,    -1,    -1,    -1,  1887,  1888,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,  1771,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1941,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,   210,   211,   212,   213,   214,
      -1,    -1,    -1,    -1,     6,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,  2001,  2002,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,  1389,     6,    -1,    -1,   254,
      -1,    -1,    -1,  2022,   259,    -1,    -1,    -1,   263,    -1,
      -1,   266,  1887,  1888,    -1,    -1,    -1,    -1,  2037,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,  1432,    -1,
      -1,   258,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,  1941,    -1,    -1,    -1,
    1464,  1465,  1466,  1467,  1468,  1469,  1470,    -1,    -1,    -1,
      -1,  1475,  1476,    -1,    -1,    -1,    -1,    -1,  1482,    -1,
    1484,    -1,    -1,    -1,  1488,    -1,    -1,  1491,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1502,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2001,  2002,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2022,    -1,    -1,
      -1,    -1,    -1,    -1,  2173,  2174,  2175,  2176,  2177,    -1,
      -1,    -1,  2037,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,  1579,   258,  1581,    -1,    -1,
      -1,  1585,   264,  1587,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,  2232,    -1,    -1,   258,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1619,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
    2155,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    81,    -1,    -1,    -1,    -1,  2173,  2174,
    2175,  2176,  2177,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      98,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,  1719,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,  2232,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,
      -1,   110,    -1,   211,   212,   213,    -1,    -1,   117,    -1,
      -1,  1825,   121,    -1,  1828,   223,    -1,    -1,    -1,   227,
      -1,   229,    -1,    -1,   133,    -1,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,   167,    -1,
      -1,    -1,    -1,  1877,  1878,    -1,  1880,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,   211,   212,   213,   214,   215,     6,    -1,    -1,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1945,  1946,    -1,    -1,    -1,    -1,    -1,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,   263,    -1,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
    1994,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,   167,    -1,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,     7,     8,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,    -1,     7,    -1,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,   229,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,   259,    -1,  2241,    -1,   263,
      -1,    -1,   266,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     140,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       8,    -1,    -1,   203,   258,    -1,    -1,    -1,    -1,    -1,
     210,   211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
     230,    -1,   232,   233,   234,   235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,
      -1,    -1,    -1,    -1,   254,    -1,   256,   257,    -1,   259,
      -1,   261,     3,     4,     5,   265,   266,    -1,    -1,    10,
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
      -1,    -1,    -1,   164,    -1,    -1,   167,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,
     221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,     3,
       4,    -1,   263,    -1,     8,   266,    10,    11,    12,    -1,
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
     164,    -1,    -1,   167,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,    -1,
     224,   225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,   259,     3,     4,     5,    -1,
     264,    -1,   266,    10,    11,    12,    -1,    -1,    15,    16,
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
     167,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   215,    -1,
      -1,    -1,    -1,   220,   221,   222,    -1,   224,   225,   226,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,     3,     4,    -1,   263,    -1,    -1,   266,
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
     160,    -1,    -1,    -1,   164,    -1,    -1,   167,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,
     220,   221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,
       3,     4,    -1,   263,   264,    -1,   266,    10,    11,    12,
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
      -1,   164,    -1,    -1,   167,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,
      -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,   259,     3,     4,    -1,
     263,    -1,    -1,   266,    10,    11,    12,    -1,    -1,    15,
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
      -1,   167,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,   210,    -1,    -1,   258,   214,   215,
      -1,    -1,    -1,   264,   220,   221,   222,   268,   224,   225,
     226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,   259,     3,     4,    -1,   263,    -1,    -1,
     266,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
     159,   160,    -1,    -1,    -1,   164,    -1,    -1,   167,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,    -1,   262,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
      -1,   220,   221,   222,    -1,   224,   225,   226,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     259,     3,     4,    -1,   263,    -1,    -1,   266,    10,    11,
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
      -1,    -1,   164,    -1,    -1,   167,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,   221,
     222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,   259,     3,     4,
      -1,    -1,   264,    -1,   266,    10,    11,    12,    -1,    -1,
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
      -1,    -1,   167,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
     215,    -1,    -1,    -1,    -1,   220,   221,   222,    -1,   224,
     225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,     3,     4,    -1,   263,    -1,
      -1,   266,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,   167,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,    -1,   220,   221,   222,    -1,   224,   225,   226,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,     3,     4,    -1,   263,    -1,    -1,   266,    10,
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
      -1,    -1,    -1,   164,    -1,    -1,   167,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,
     221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,     3,
       4,    -1,   263,    -1,     8,   266,    10,    11,    12,    -1,
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
     164,    -1,    -1,   167,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,    -1,
     224,   225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,     3,     4,    -1,    -1,   259,     8,    -1,    10,    11,
      12,    -1,   266,    15,    16,    17,    18,    19,    20,    21,
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
      -1,    -1,   164,    -1,    -1,   167,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,   221,
     222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,     3,     4,    -1,    -1,   259,    -1,    -1,
      10,    11,    12,    -1,   266,    15,    16,    17,    18,    19,
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
     160,    -1,    -1,    -1,   164,    -1,    -1,   167,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,
     220,   221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,
       3,     4,    -1,   263,    -1,    -1,   266,    10,    11,    12,
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
      -1,   164,    -1,    -1,   167,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,
      -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,   259,     3,     4,    -1,
     263,    -1,    -1,   266,    10,    11,    12,    -1,    -1,    15,
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
      -1,   167,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,    -1,   220,   221,   222,    -1,   224,   225,
     226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,     3,
       4,     5,    -1,   259,    -1,    -1,    10,    11,    12,    -1,
     266,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,   229,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,
      -1,    -1,   266,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,
      -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
      -1,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,     3,     4,     5,   263,    -1,    -1,   266,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    -1,    98,     3,     4,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
     211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,   229,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,     3,     4,    -1,   259,    -1,
      -1,    -1,    10,    11,    12,   266,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
      58,    59,    60,    61,    -1,   220,   221,   222,    66,   224,
     225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,    93,    94,    -1,    96,   254,
      -1,    -1,    -1,    -1,   259,     3,     4,    -1,   263,    -1,
       8,   266,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,    -1,   224,   225,   226,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,     3,     4,    -1,   263,    -1,    -1,   266,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   214,    58,    59,    60,
      61,    -1,   220,   221,   222,    66,   224,   225,   226,    -1,
      -1,    -1,   230,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    93,    94,    -1,    96,   254,     3,     4,    -1,
       6,   259,    -1,    -1,    10,    11,    12,    -1,   266,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    82,    83,    84,   118,
     119,   120,   121,    -1,    -1,   124,    -1,    93,    94,    -1,
      96,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,   138,
      -1,   140,   141,    -1,   143,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   161,   224,   225,   226,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,   187,   188,
     189,    -1,    -1,   254,     3,     4,    -1,     6,   259,   260,
      -1,    10,    11,    12,    -1,   266,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    58,
      59,    60,    61,    -1,   220,   221,   222,    66,   224,   225,
     226,    -1,    -1,    -1,   230,   264,    13,    14,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,   247,   248,    -1,    93,    94,    -1,    96,   254,     3,
       4,    -1,     6,   259,    -1,    -1,    10,    11,    12,    -1,
     266,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    82,    83,
      84,   118,   119,   120,   121,    -1,    -1,   124,    -1,    93,
      94,    -1,    96,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,   161,   224,   225,   226,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
     187,   188,   189,    -1,    -1,   254,     3,     4,    -1,    -1,
     259,    -1,    -1,    10,    11,    12,    -1,   266,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
     214,    58,    59,    60,    61,    -1,   220,   221,   222,    66,
     224,   225,   226,    -1,    -1,    -1,   230,   264,    13,    14,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    93,    94,    -1,    96,
     254,     3,     4,    -1,    -1,   259,    -1,    -1,    10,    11,
      12,    -1,   266,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      82,    83,    84,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    93,    94,    -1,    96,    -1,    -1,    -1,   133,   134,
      -1,    -1,   137,   138,    -1,   140,   141,    -1,   143,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,   161,   224,   225,   226,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,   187,   188,   189,    -1,    -1,   254,     3,     4,
      -1,    -1,   259,   260,    -1,    10,    11,    12,    -1,   266,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,    58,    59,    60,    61,    -1,   220,   221,
     222,    66,   224,   225,   226,     4,     5,    -1,   230,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    93,    94,
      -1,    96,   254,    -1,    -1,    -1,    -1,   259,   260,    -1,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    -1,    -1,   210,    13,    14,    -1,   214,
      -1,    -1,    -1,    -1,    -1,   220,   221,   222,    -1,   224,
     225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,   227,    -1,
     229,   230,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   263,    -1,   133,   134,    13,    14,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,   133,   134,    13,    14,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,   133,   134,
      13,    14,   137,   138,    -1,   140,   141,   264,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,   133,   134,
      13,    14,   137,   138,    -1,   140,   141,   264,   143,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
      -1,   124,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,
     133,   134,    13,    14,   137,   138,    -1,   140,   141,   264,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
      -1,   124,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,
     133,   134,    13,    14,   137,   138,    -1,   140,   141,   264,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,   124,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,   133,   134,    13,    14,   137,   138,    -1,   140,
     141,   264,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,   124,    -1,    -1,   187,   188,   189,    -1,
      -1,    -1,   133,   134,    13,    14,   137,   138,    -1,   140,
     141,   264,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,    -1,   124,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,   133,   134,    13,    14,   137,   138,
      -1,   140,   141,   264,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,    -1,   124,    -1,    -1,   187,   188,
     189,    -1,    -1,    -1,   133,   134,    13,    14,   137,   138,
      -1,   140,   141,   264,   143,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,   264,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,   264,   143,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,    13,    14,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
     187,   188,   189,   258,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    -1,   268,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    -1,    91,    92,    -1,    94,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   264,    -1,   117,
     118,   119,   120,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    -1,    -1,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,    -1,    -1,    -1,   175,   176,   177,
      -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,   192,    -1,   194,    -1,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,     4,    -1,    -1,    -1,    -1,   216,   217,
     218,   219,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     228,    -1,   230,   231,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    46,    47,    48,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    -1,
      91,    92,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,   117,   118,   119,   120,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,    -1,    -1,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,   186,   187,   188,   189,     4,
       5,   192,    -1,   194,    -1,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,   230,
     231,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    13,    14,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   140,    -1,    -1,    -1,   258,
      -1,   260,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    13,    14,    -1,   118,   119,
     120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,   134,    -1,    -1,   137,   138,    -1,
     140,   141,    -1,   143,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,    -1,   165,   211,   212,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,
      -1,    -1,   227,    -1,   229,   230,    -1,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,
     138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,   187,
     188,   189,    -1,    -1,    -1,    -1,   268,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     268,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   268,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     268,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   268,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     268,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,   264,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,   264,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
     264,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,   264,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,   264,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,   264,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,   264,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,   264,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,   264,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,   264,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
     264,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,   264,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,   264,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,   264,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,   264,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,   264,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,   264,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,   264,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
     264,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,   264,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,   264,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,   264,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,   264,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,   264,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,   264,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,   264,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     263,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   263,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,   263,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,   260,    -1,   262,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
     262,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,   262,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,   262,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   262,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,   262,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,   262,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,   262,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,   262,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
     262,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,   262,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,   262,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   262,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   260,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   260,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   270,   271,     6,     0,     4,    13,    14,    46,
      47,    48,    67,    68,    69,    74,    75,    80,    85,    86,
      87,    88,    89,    91,    92,    94,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   117,   118,   119,   120,   121,   122,   124,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   145,   146,   147,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   175,   176,   177,   181,   186,   187,   188,   189,
     192,   194,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   216,   217,   218,   219,
     228,   230,   231,   272,   274,   275,   296,   315,   317,   321,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   339,
     341,   342,   348,   349,   350,   351,   357,   381,   382,   263,
     267,    14,   108,   259,   259,   259,     6,   263,     6,     6,
       6,     6,   259,     6,   263,     6,   263,   263,     6,     6,
     261,   261,     4,   359,   382,   259,   261,   293,   102,   105,
     108,   110,   317,   293,   259,   259,   259,     4,   259,   259,
     259,     4,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   263,   123,   108,     6,     6,   263,   263,
     102,   105,   108,   121,   320,   110,   259,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    58,    59,    60,    61,    66,    67,    76,    77,
      78,    82,    83,    84,    93,    96,   102,   105,   108,   110,
     121,   133,   138,   140,   143,   210,   214,   215,   220,   221,
     222,   224,   225,   226,   247,   248,   254,   259,   263,   266,
     317,   318,   321,   332,   339,   341,   352,   353,   357,   359,
     365,   367,   382,   259,   263,   263,   108,   108,   133,   105,
     108,   110,   317,   105,   108,   109,   110,   121,   187,   318,
     105,   108,   259,   105,   165,   192,   208,   209,   263,   247,
     248,   259,   263,   362,   363,   362,   263,   263,   362,     4,
     102,   106,   112,   113,   115,   116,   137,   263,   259,   108,
     110,   108,   105,     4,    94,   203,   263,   382,     4,     6,
     102,   105,   108,   105,   108,   121,   319,     5,   259,   263,
     365,   366,   108,     4,     4,     4,   366,     4,   108,   259,
     108,   259,   259,     4,   263,   369,   382,     4,   259,   259,
     259,     6,     6,   261,     5,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    62,    63,    64,    65,    70,    71,
      72,    73,    79,    81,    95,    98,   211,   212,   213,   223,
     227,   229,   373,   382,   259,     4,   373,     5,   263,     5,
     263,   317,    32,   248,   352,   382,   261,     6,   263,   259,
     263,     6,   259,   263,     6,   267,     7,   140,   203,   232,
     233,   234,   235,   256,   257,   259,   261,   265,   291,   292,
     293,   317,   352,   372,   373,   382,     4,   321,   322,   323,
     263,     6,   352,   372,   373,   382,   372,   372,   352,   372,
     379,   380,   382,   352,   323,   352,   298,   302,   259,   361,
       9,   373,   259,   373,   352,   352,   352,   259,   352,   352,
     352,   259,   352,   352,   352,   352,   352,   352,   352,   372,
     352,   352,   352,   352,   366,   259,   248,   352,   367,   368,
     368,   263,   366,   365,   372,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     259,   261,   293,   293,   293,   293,   293,   293,   259,   293,
     293,   259,   317,   318,   318,   318,   293,   293,     5,   263,
     263,   133,   317,   317,   259,   293,   293,   259,   259,   259,
     352,   263,   352,   367,   352,   352,   264,   368,   359,   382,
     195,     5,   263,     8,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   258,     9,   259,   261,   265,   292,   293,   352,
     368,   368,   259,   259,   259,   365,   366,   366,   366,   316,
     259,   263,   259,   259,   365,   263,   263,   352,     4,   365,
     263,   369,   263,   263,   362,   362,   362,   352,   352,   247,
     248,   263,   263,   362,   247,   248,   259,   323,   362,   263,
     259,   263,   259,   259,   259,   259,   259,   259,   259,   368,
     352,   366,   366,   366,   259,   263,     4,   261,   263,     6,
     261,   323,     6,     6,   263,   263,   263,   263,   366,   352,
       8,     7,   263,   261,   261,   261,     6,     6,   259,   352,
     259,   352,   352,   265,   352,   263,   195,   352,   352,   352,
     352,   293,   293,   293,   259,   259,   259,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   259,   259,   293,
     259,   261,     6,     6,   263,     6,     8,   323,     6,     8,
     323,   259,   293,   352,   249,   263,     9,   259,   261,   265,
     372,   368,   352,   323,   365,   365,   263,   373,   317,     7,
     352,   352,     4,    36,    37,   111,   112,   192,   193,   295,
     365,     6,   260,   262,   263,   294,   263,     6,   263,     6,
       9,   259,   261,   265,   382,   264,   133,   138,   140,   141,
     143,   315,   317,   352,     6,   260,   268,     9,   259,   261,
     265,   260,   268,   260,   268,   268,   260,   268,     9,   259,
     265,   268,   264,   268,   262,   268,   297,   262,   297,    97,
     360,   358,   382,   268,   352,   268,   260,   260,   260,   352,
     260,   260,   260,   352,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   264,     7,   352,   249,   264,
     268,   264,   352,     6,     6,   260,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   367,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   367,   367,   382,   263,   352,   352,   372,
     352,   372,   365,   372,   372,   379,   263,   263,   263,   263,
     352,   294,   382,     8,   352,   352,   366,   365,   372,   372,
     367,   359,   373,   359,   368,   260,   264,   265,   293,    67,
       8,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   263,   352,   367,   352,   352,
     352,   352,   352,   382,   352,   352,   295,   263,   294,   260,
     264,   264,   352,   352,   352,     7,     7,   345,   345,   259,
     352,   352,   352,   352,     6,   168,   368,   368,   263,   260,
       6,   323,   263,   323,   323,   268,   268,   268,   362,   362,
     322,   322,   268,   352,   264,   336,   268,   323,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   264,   260,     7,
     346,     6,     7,   352,   352,     6,   352,   323,   352,   264,
     368,   368,   368,   352,     6,   260,   264,   352,   368,   352,
     352,   352,   352,   260,   352,   260,   260,   192,   268,   323,
     263,     8,   260,   260,   262,   379,   372,   379,   372,   372,
     372,   372,   372,   372,   352,   372,   372,   372,   372,   266,
     375,   382,   373,   372,   372,   372,   359,   382,   368,   264,
     264,   264,   264,   352,   352,   352,   323,   382,   295,   262,
     264,   260,   147,   165,   340,   260,   264,   268,   352,     6,
     263,   365,   260,   262,   265,     7,     7,   291,   292,     6,
     368,     7,   235,   291,   352,   276,   382,   352,   352,   295,
     261,   259,   133,   317,   318,   317,   263,   264,     6,   242,
     243,   273,   368,   382,   352,   352,   295,     6,   368,     6,
     368,   352,     6,   372,   380,   382,   260,   295,   352,   352,
       6,   382,     6,   372,   352,   260,   261,   352,   268,   373,
       7,     7,     7,   260,     7,     7,     7,   260,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   352,   260,
     263,   352,   367,     6,   263,   264,     6,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   268,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   268,   268,
     268,   268,   268,   260,   262,   262,   368,   268,   268,   294,
     268,   294,   268,   268,   268,   260,   368,   352,   352,   352,
     354,   294,   264,   264,   264,   268,   268,   294,   294,   260,
     265,   260,   265,   268,   293,   355,   264,     7,   295,   294,
     365,   264,     8,     8,   368,   265,   260,   262,   259,   261,
     292,   293,   368,     7,   263,   263,   260,   260,   260,   352,
     365,     4,   344,     6,   311,   352,   373,   260,   264,   260,
     260,   352,   264,   264,   368,   265,   264,   323,   264,   264,
     362,   352,   352,   264,   264,   352,   362,   144,   144,   162,
     172,   173,   174,   178,   179,   337,   338,   362,   264,   333,
     260,   264,   260,   260,   260,   260,   260,   260,   260,   263,
       7,   352,     6,   352,   260,   264,   262,   264,   262,   264,
     264,   264,   264,     6,   264,   262,   262,   268,   260,     7,
     260,     7,     7,   265,   352,   264,   352,   352,     7,   265,
     294,   268,   294,   294,   260,   260,   268,   294,   294,   268,
     268,   294,   294,   294,   294,   352,   294,     9,   374,   268,
     260,   268,   294,   265,   268,   356,   262,   264,   260,   264,
     265,   259,   261,   267,   195,     7,   165,     6,   352,   264,
     263,     6,   365,   264,   352,     6,     7,   291,   292,   265,
     291,   292,   295,   263,   370,   382,   373,   352,     6,   264,
      49,    49,   365,   264,     4,   182,   183,   184,   185,   264,
     279,   283,   286,   288,   289,   331,   265,   260,   262,   259,
     352,   352,   259,   263,   259,   263,     8,   368,   372,   260,
     265,   260,   262,   259,   260,   260,   268,   265,   259,   264,
     268,     7,   293,     4,    36,    37,   305,   306,   307,   294,
     352,   294,   362,   365,   365,     7,   365,   365,   365,     7,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
       6,     7,   368,   322,   352,   352,   352,   352,   352,   352,
     264,   352,   352,   352,   365,   372,   372,   264,   264,   264,
     264,   268,   304,   352,   352,   295,   295,   352,   352,   260,
     365,   293,   352,   352,   264,   295,   292,   265,   292,   352,
     352,   294,   264,   365,   368,   368,     7,     7,     7,   144,
     343,     6,   260,   268,     7,     7,     7,     6,     7,     7,
     264,     4,   295,   264,   268,   268,   268,   264,   264,   120,
       4,     6,   352,   263,     6,   259,     6,   180,     6,   180,
     264,   338,   268,   337,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   322,   365,     6,   263,   102,     6,     6,
       6,   108,     7,     7,     6,     6,   352,     7,   365,     7,
     365,   365,     4,   268,     8,     8,   260,   295,   295,   368,
     372,   352,   372,   266,   268,   308,   372,   372,   295,   372,
     260,   268,     6,   295,   263,   317,   263,     6,   352,     6,
     263,   365,   264,   264,   352,     6,   192,   193,   295,   352,
       6,     7,   369,   371,     6,   261,     6,     6,   294,   293,
     293,     6,   280,   259,   259,   263,   290,     6,   295,   265,
     372,   352,   262,   260,   352,     8,   368,   352,   368,   264,
     264,     6,     6,   273,   295,   265,   352,     6,     6,   352,
     295,   260,     6,   352,   263,   352,   373,   294,    49,   263,
     365,   373,   376,   352,   352,   262,   268,     6,   260,     6,
       6,   137,   313,   313,   365,     6,     6,     6,   365,   144,
     195,   312,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,   264,   264,   294,   294,   294,   294,   294,   294,
     294,   268,   268,   268,   260,   294,   294,   306,   294,   260,
     294,   260,   293,   355,   294,     6,   294,   259,   261,   293,
     295,   260,   262,   294,     6,   264,   264,   365,   365,   365,
       4,     6,   291,   352,   365,   365,   365,   263,   263,     7,
       6,     7,   352,   352,   352,   263,   263,   263,   261,     6,
     352,   365,   352,     6,     6,   352,   362,   264,     5,   365,
     263,   263,   263,   263,   263,   263,   263,   365,   264,     6,
     368,   263,   263,   352,   352,   262,   365,     6,   365,     6,
     191,   352,   352,   352,     6,     6,     7,   294,   268,   268,
     294,   268,   352,     4,   207,   309,   310,   294,   260,   294,
     356,   373,   259,   261,   352,   263,   323,     6,   323,   268,
       6,     6,   265,     7,     7,   291,   292,     6,   369,   264,
     268,   352,   291,   263,   294,   377,   378,   379,   377,   259,
     352,   352,   364,   365,   263,   259,     4,     6,   260,     6,
     260,   264,   264,   260,   264,     6,     6,   372,   259,     4,
     260,   268,   259,   264,   268,   365,   373,     7,   293,   303,
     352,   367,   307,     6,   362,     6,     6,     6,   144,   314,
     102,   121,   106,     6,     5,   263,     6,   352,   352,   352,
     352,   260,   355,   352,   352,   294,   292,   263,   263,     6,
     312,     6,   352,   365,   144,   144,     4,     6,   368,   368,
     352,   352,   373,   264,   260,   264,   268,   322,   322,   352,
     352,   264,   268,   260,   264,   268,     6,     6,   364,   362,
     362,   362,   362,   362,   248,   362,     6,   264,   368,   352,
       6,     6,     6,     6,     6,   365,   264,   268,     8,   264,
     260,   263,   352,   373,   372,   352,   372,   352,   373,   376,
     378,   373,   268,   260,   268,   264,   352,   340,   340,   365,
     295,   370,   373,   352,     6,     6,   369,   262,   365,   379,
       6,   294,   294,   277,   352,   268,   268,   264,   268,   278,
     352,   352,     6,     6,     6,     6,   352,   352,   260,     6,
     352,   299,   301,   263,   378,   264,   268,     7,     7,   148,
       6,   263,   263,   263,     5,   364,   294,   294,   268,   294,
     260,   260,   262,   368,   368,     6,     6,   352,   352,   263,
     264,   264,   263,     6,     6,   263,   352,   264,   264,   264,
     262,     6,   365,     7,   263,   352,   264,   268,   268,   268,
     268,   268,   268,     6,   264,   264,   190,   352,   352,   368,
       6,     6,   260,   294,   294,   310,   373,   264,   264,   264,
     264,     7,     6,     6,     6,   265,     6,   264,     6,     6,
     260,   268,   352,   352,   263,   365,   264,   268,   260,   260,
     268,   264,   304,   308,   365,   294,   352,   373,   382,   368,
     368,   352,     6,   264,   352,   355,   264,   264,     6,     6,
     364,   149,   150,   155,   347,   149,   150,   347,   368,   322,
     264,   268,     6,   264,   365,   323,   264,     6,   368,   362,
     362,   362,   362,   362,     6,   352,   264,   264,   264,   260,
       6,   263,     6,   369,   193,   281,   352,   268,   268,   364,
       6,   352,   352,     6,   264,   264,   300,     7,   259,   264,
     264,   264,   263,   268,   260,   263,   264,   263,   362,   365,
       6,   263,   362,     6,   264,   264,   352,     6,   144,   264,
     334,   263,   264,   268,   268,   268,   268,   268,     6,     6,
       6,   323,     6,   263,   352,   352,   264,   268,   304,   373,
     260,   352,   352,   368,     6,   362,     6,   362,     6,     6,
     264,   352,   337,   323,     6,   368,   368,   368,   368,   362,
     368,   340,   278,   260,   268,     6,   263,   352,   264,   268,
     268,   264,   268,   268,     6,   264,   264,   335,   264,   264,
     264,   264,   268,   264,   264,   264,   284,   352,   364,   264,
     352,   352,   362,   362,   337,     6,     6,     6,     6,   368,
       6,     6,     6,   263,   260,   264,     6,   264,   294,   268,
     268,   264,   264,   282,   372,   287,   263,     6,   352,   352,
       6,   264,   268,   263,   364,   264,   264,     6,   372,   285,
     372,   264,     6,     6,   264,   268,     6,     6,   372
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
      drawContext::global()->draw();
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
      // lcExtendFromBoundary onstraints are stored in GEO internals in addition
      // to GModel, as they can be copied around during GEO operations
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
#line 5250 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 398:
#line 5251 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 399:
#line 5252 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 400:
#line 5257 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 401:
#line 5263 "Gmsh.y"
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

  case 402:
#line 5275 "Gmsh.y"
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

  case 403:
#line 5293 "Gmsh.y"
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

  case 404:
#line 5320 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 405:
#line 5321 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 406:
#line 5322 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 407:
#line 5323 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 408:
#line 5324 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 409:
#line 5325 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 410:
#line 5326 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5327 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5329 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 413:
#line 5335 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 414:
#line 5336 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 415:
#line 5337 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 416:
#line 5338 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 417:
#line 5339 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 418:
#line 5340 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 419:
#line 5341 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5342 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5343 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 422:
#line 5344 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 423:
#line 5345 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 424:
#line 5346 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 425:
#line 5347 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 426:
#line 5348 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 427:
#line 5349 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 428:
#line 5350 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5351 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5352 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 431:
#line 5353 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5354 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5355 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5356 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 435:
#line 5357 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5358 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 437:
#line 5359 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5360 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 439:
#line 5361 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5362 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5363 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5364 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 443:
#line 5365 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 444:
#line 5366 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 445:
#line 5367 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 446:
#line 5368 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 447:
#line 5369 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 448:
#line 5370 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 449:
#line 5371 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 450:
#line 5372 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 451:
#line 5373 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 452:
#line 5374 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 453:
#line 5383 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 454:
#line 5384 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 455:
#line 5385 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 456:
#line 5386 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 457:
#line 5387 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 458:
#line 5388 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 459:
#line 5389 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 460:
#line 5390 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 461:
#line 5391 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 462:
#line 5392 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 463:
#line 5393 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 464:
#line 5398 "Gmsh.y"
    { init_options(); ;}
    break;

  case 465:
#line 5400 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 466:
#line 5406 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 467:
#line 5410 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 468:
#line 5415 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 469:
#line 5420 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 470:
#line 5425 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 471:
#line 5430 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(nullptr, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 472:
#line 5434 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 473:
#line 5438 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 474:
#line 5442 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 475:
#line 5446 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 476:
#line 5450 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 477:
#line 5454 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 478:
#line 5458 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 479:
#line 5464 "Gmsh.y"
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

  case 480:
#line 5479 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 481:
#line 5483 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 482:
#line 5489 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 483:
#line 5494 "Gmsh.y"
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

  case 484:
#line 5513 "Gmsh.y"
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

  case 485:
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

  case 486:
#line 5554 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 487:
#line 5558 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 488:
#line 5562 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 489:
#line 5566 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 490:
#line 5570 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 491:
#line 5574 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 492:
#line 5578 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 493:
#line 5583 "Gmsh.y"
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

  case 494:
#line 5593 "Gmsh.y"
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

  case 495:
#line 5603 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 496:
#line 5608 "Gmsh.y"
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

  case 497:
#line 5619 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 498:
#line 5628 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 499:
#line 5633 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 500:
#line 5638 "Gmsh.y"
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

  case 501:
#line 5665 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 502:
#line 5667 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 503:
#line 5672 "Gmsh.y"
    { (yyval.c) = nullptr; ;}
    break;

  case 504:
#line 5674 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 505:
#line 5679 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 506:
#line 5686 "Gmsh.y"
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

  case 507:
#line 5702 "Gmsh.y"
    { (yyval.c2).char1 = nullptr; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 508:
#line 5704 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 509:
#line 5709 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 510:
#line 5711 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 511:
#line 5716 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 512:
#line 5718 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 513:
#line 5723 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 514:
#line 5727 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 515:
#line 5731 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 516:
#line 5735 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 517:
#line 5739 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 518:
#line 5746 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 519:
#line 5750 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 520:
#line 5754 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 521:
#line 5758 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 522:
#line 5765 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 523:
#line 5770 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 524:
#line 5777 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 525:
#line 5782 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 526:
#line 5786 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 527:
#line 5791 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 528:
#line 5795 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 529:
#line 5803 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 530:
#line 5814 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 531:
#line 5818 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 532:
#line 5822 "Gmsh.y"
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

  case 533:
#line 5836 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 534:
#line 5844 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 535:
#line 5852 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 536:
#line 5859 "Gmsh.y"
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

  case 537:
#line 5869 "Gmsh.y"
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

  case 538:
#line 5892 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 539:
#line 5897 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 540:
#line 5903 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 541:
#line 5908 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 542:
#line 5914 "Gmsh.y"
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

  case 543:
#line 5925 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 544:
#line 5931 "Gmsh.y"
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

  case 545:
#line 5945 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 546:
#line 5951 "Gmsh.y"
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

  case 547:
#line 5963 "Gmsh.y"
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

  case 548:
#line 5977 "Gmsh.y"
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

  case 549:
#line 5990 "Gmsh.y"
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

  case 550:
#line 6000 "Gmsh.y"
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

  case 551:
#line 6010 "Gmsh.y"
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
#line 6020 "Gmsh.y"
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

  case 553:
#line 6032 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 554:
#line 6036 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 555:
#line 6041 "Gmsh.y"
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

  case 556:
#line 6053 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 557:
#line 6057 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 558:
#line 6061 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 559:
#line 6065 "Gmsh.y"
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

  case 560:
#line 6083 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 561:
#line 6091 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 562:
#line 6099 "Gmsh.y"
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

  case 563:
#line 6128 "Gmsh.y"
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

  case 564:
#line 6138 "Gmsh.y"
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

  case 565:
#line 6154 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 566:
#line 6165 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 567:
#line 6170 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 568:
#line 6174 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 569:
#line 6178 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 570:
#line 6190 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 571:
#line 6194 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 572:
#line 6206 "Gmsh.y"
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

  case 573:
#line 6223 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 574:
#line 6233 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 575:
#line 6237 "Gmsh.y"
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

  case 576:
#line 6252 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 577:
#line 6257 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 578:
#line 6264 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 579:
#line 6268 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 580:
#line 6273 "Gmsh.y"
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

  case 581:
#line 6287 "Gmsh.y"
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

  case 582:
#line 6301 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 583:
#line 6305 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 584:
#line 6309 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 585:
#line 6313 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 586:
#line 6317 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 587:
#line 6325 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 588:
#line 6331 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 589:
#line 6340 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 590:
#line 6344 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 591:
#line 6348 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 592:
#line 6356 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 593:
#line 6362 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 594:
#line 6368 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 595:
#line 6372 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 596:
#line 6379 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 597:
#line 6387 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 598:
#line 6394 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 599:
#line 6403 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 600:
#line 6407 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 601:
#line 6411 "Gmsh.y"
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

  case 602:
#line 6426 "Gmsh.y"
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

  case 603:
#line 6440 "Gmsh.y"
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

  case 604:
#line 6454 "Gmsh.y"
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

  case 605:
#line 6466 "Gmsh.y"
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

  case 606:
#line 6482 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 607:
#line 6491 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 608:
#line 6500 "Gmsh.y"
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

  case 609:
#line 6510 "Gmsh.y"
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

  case 610:
#line 6521 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 611:
#line 6529 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 612:
#line 6537 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 613:
#line 6541 "Gmsh.y"
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

  case 614:
#line 6560 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 615:
#line 6567 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 616:
#line 6573 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 617:
#line 6579 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 618:
#line 6586 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 619:
#line 6593 "Gmsh.y"
    { init_options(); ;}
    break;

  case 620:
#line 6595 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 621:
#line 6603 "Gmsh.y"
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

  case 622:
#line 6627 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 623:
#line 6629 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 624:
#line 6635 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 625:
#line 6640 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 626:
#line 6642 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 627:
#line 6647 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 628:
#line 6652 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 629:
#line 6657 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 630:
#line 6659 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 631:
#line 6663 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 632:
#line 6675 "Gmsh.y"
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

  case 633:
#line 6689 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 634:
#line 6693 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 635:
#line 6700 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 636:
#line 6708 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 637:
#line 6716 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 638:
#line 6727 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 639:
#line 6729 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 640:
#line 6732 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14937 "Gmsh.tab.cpp"
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


#line 6735 "Gmsh.y"


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

