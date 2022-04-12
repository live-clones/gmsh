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
#define YYLAST   17721

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  269
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  641
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2294

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
    2975,  2977,  2979,  2981,  2985,  2991,  2999,  3004,  3009,  3014,
    3021,  3028,  3037,  3046,  3051,  3066,  3071,  3076,  3078,  3080,
    3084,  3088,  3098,  3106,  3108,  3114,  3118,  3125,  3127,  3131,
    3133,  3135,  3140,  3145,  3149,  3155,  3162,  3171,  3178,  3183,
    3189,  3191,  3196,  3198,  3200,  3202,  3204,  3209,  3216,  3221,
    3228,  3234,  3242,  3247,  3252,  3257,  3266,  3271,  3276,  3281,
    3286,  3295,  3304,  3311,  3316,  3323,  3328,  3330,  3332,  3337,
    3342,  3343,  3350,  3355,  3358,  3363,  3368,  3370,  3372,  3376,
    3378,  3380,  3384,  3388,  3392,  3398,  3406,  3412,  3418,  3427,
    3429,  3431
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
     352,   264,    -1,    78,   318,   263,   352,   264,    -1,   192,
     318,   263,   352,   264,    -1,   321,    -1,   332,    -1,   341,
      -1,   382,   293,   294,    -1,   382,   265,   295,   293,   294,
      -1,   382,     9,   382,   265,   295,   293,   294,    -1,    41,
     261,   382,   262,    -1,    41,   261,   367,   262,    -1,    41,
     259,   367,   260,    -1,    41,   293,   263,   368,   264,   294,
      -1,   382,   293,   263,   368,   264,   294,    -1,    42,   293,
     352,   268,   352,   268,   352,   294,    -1,    43,   293,   352,
     268,   352,   268,   352,   294,    -1,    44,   293,   372,   294,
      -1,    45,   293,   352,   268,   352,   268,   352,   268,   352,
     268,   352,   268,   352,   294,    -1,   215,   293,   367,   294,
      -1,    32,   293,   367,   294,    -1,   352,    -1,   367,    -1,
     368,   268,   352,    -1,   368,   268,   367,    -1,   263,   352,
     268,   352,   268,   352,   268,   352,   264,    -1,   263,   352,
     268,   352,   268,   352,   264,    -1,   382,    -1,     4,   265,
     192,   265,     4,    -1,   263,   371,   264,    -1,   382,   261,
     352,   262,   265,   193,    -1,   369,    -1,   371,   268,   369,
      -1,   373,    -1,   382,    -1,   382,   261,   352,   262,    -1,
     382,   259,   352,   260,    -1,   382,   265,   295,    -1,   382,
       9,   382,   265,   295,    -1,   382,   265,   295,   259,   352,
     260,    -1,   382,     9,   382,   265,   295,   259,   352,   260,
      -1,   382,   261,   352,   262,   265,     4,    -1,   317,   263,
     352,   264,    -1,   140,   317,   263,   352,   264,    -1,     5,
      -1,   229,   261,   382,   262,    -1,    70,    -1,   227,    -1,
      79,    -1,    81,    -1,   212,   259,   372,   260,    -1,   211,
     259,   372,   268,   372,   260,    -1,   213,   293,   372,   294,
      -1,   213,   293,   372,   268,   372,   294,    -1,   223,   259,
     359,   356,   260,    -1,   223,   259,   359,   265,   295,   356,
     260,    -1,    51,   293,   379,   294,    -1,    52,   259,   372,
     260,    -1,    53,   259,   372,   260,    -1,    54,   259,   372,
     268,   372,   268,   372,   260,    -1,    49,   293,   379,   294,
      -1,    63,   293,   372,   294,    -1,    64,   293,   372,   294,
      -1,    65,   293,   372,   294,    -1,    62,   293,   352,   268,
     372,   268,   372,   294,    -1,    57,   293,   372,   268,   352,
     268,   352,   294,    -1,    57,   293,   372,   268,   352,   294,
      -1,    50,   293,   372,   294,    -1,    50,   293,   372,   268,
     368,   294,    -1,    71,   293,   372,   294,    -1,    72,    -1,
      73,    -1,    56,   293,   372,   294,    -1,    55,   293,   372,
     294,    -1,    -1,    98,   293,   373,   374,   308,   294,    -1,
      95,   293,   375,   294,    -1,   266,   352,    -1,   382,     9,
     266,   352,    -1,    49,   293,   378,   294,    -1,   379,    -1,
     378,    -1,   263,   379,   264,    -1,   372,    -1,   380,    -1,
     379,   268,   372,    -1,   379,   268,   380,    -1,   382,   259,
     260,    -1,   382,   265,   295,   259,   260,    -1,   382,     9,
     382,   265,   295,   259,   260,    -1,     4,   267,   263,   352,
     264,    -1,   381,   267,   263,   352,   264,    -1,   230,   261,
     372,   262,   267,   263,   352,   264,    -1,     4,    -1,   381,
      -1,   230,   261,   372,   262,    -1
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
    6006,  6016,  6026,  6036,  6048,  6052,  6057,  6069,  6073,  6077,
    6081,  6099,  6107,  6115,  6144,  6154,  6170,  6181,  6186,  6190,
    6194,  6206,  6210,  6222,  6239,  6249,  6253,  6268,  6273,  6280,
    6284,  6289,  6303,  6317,  6321,  6325,  6329,  6333,  6341,  6347,
    6356,  6360,  6364,  6372,  6378,  6384,  6388,  6395,  6403,  6410,
    6419,  6423,  6427,  6442,  6456,  6470,  6482,  6498,  6507,  6516,
    6526,  6537,  6545,  6553,  6557,  6576,  6583,  6589,  6595,  6602,
    6610,  6609,  6619,  6643,  6645,  6651,  6656,  6658,  6663,  6668,
    6673,  6675,  6679,  6691,  6705,  6709,  6716,  6724,  6732,  6743,
    6745,  6748
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
     367,   367,   367,   367,   367,   367,   367,   368,   368,   368,
     368,   369,   369,   369,   369,   370,   370,   371,   371,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     374,   373,   373,   375,   375,   376,   377,   377,   378,   379,
     379,   379,   379,   380,   380,   380,   381,   381,   381,   382,
     382,   382
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
       4,     2,     3,     3,     4,     5,     5,     5,     5,     5,
       1,     1,     1,     3,     5,     7,     4,     4,     4,     6,
       6,     8,     8,     4,    14,     4,     4,     1,     1,     3,
       3,     9,     7,     1,     5,     3,     6,     1,     3,     1,
       1,     4,     4,     3,     5,     6,     8,     6,     4,     5,
       1,     4,     1,     1,     1,     1,     4,     6,     4,     6,
       5,     7,     4,     4,     4,     8,     4,     4,     4,     4,
       8,     8,     6,     4,     6,     4,     1,     1,     4,     4,
       0,     6,     4,     2,     4,     4,     1,     1,     3,     1,
       1,     3,     3,     3,     5,     7,     5,     5,     8,     1,
       1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   639,     0,     0,     0,
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
      17,    18,    19,    20,     0,    25,     0,   640,     0,   233,
       0,     0,     0,     0,     0,     0,   283,     0,   285,   286,
     281,   282,     0,   288,     0,   291,   233,     0,   293,   294,
     119,   129,   639,   511,   507,    73,    74,     0,   205,   206,
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
       0,     0,   458,   459,   460,     0,     0,     0,     0,     0,
       0,     0,     0,   550,   551,     0,   552,   524,   404,   466,
     469,   327,   525,   507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,   210,   211,     0,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   513,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,     0,     0,   233,     0,     0,
     394,     0,     0,     0,   214,   215,     0,     0,   532,     0,
       0,   530,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,     0,     0,   573,     0,     0,
       0,     0,   279,   280,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   592,
       0,   616,   617,   594,   595,     0,     0,     0,     0,     0,
       0,   593,     0,     0,     0,     0,   306,   307,     0,   233,
       0,   233,     0,     0,     0,     0,   507,     0,   276,     0,
       0,   233,   400,     0,     0,    84,     0,    66,     0,     0,
      70,    69,    68,    67,    72,    71,    73,    74,     0,     0,
       0,     0,     0,     0,     0,   579,   507,     0,   232,     0,
     231,     0,   184,     0,     0,   579,   580,     0,     0,     0,
     629,     0,   630,   580,     0,     0,     0,   117,   117,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,   568,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   407,     0,   406,   533,   408,     0,   526,     0,
       0,   507,     0,   541,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,     0,   483,
       0,     0,     0,     0,     0,     0,     0,   328,     0,   361,
     361,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,   233,   233,     0,   515,   514,     0,
       0,     0,     0,   233,   233,     0,     0,     0,     0,   324,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   363,     0,     0,     0,     0,     0,     0,
     233,   259,     0,     0,   257,   395,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   372,   278,
       0,     0,     0,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   310,   309,     0,   264,     0,     0,
     266,     0,     0,     0,     0,   406,     0,   233,     0,     0,
       0,     0,     0,     0,     0,   349,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,    88,    75,    76,     0,     0,     0,   275,
      40,   271,     0,     0,     0,     0,     0,   227,     0,     0,
       0,     0,     0,   234,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,   118,     0,     0,
       0,   509,     0,     0,   508,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   355,     0,     0,     0,   209,     0,     0,
       0,     0,     0,     0,     0,   389,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   482,     0,     0,     0,     0,   542,   543,
       0,     0,     0,     0,     0,     0,   501,     0,   405,   527,
       0,     0,     0,     0,   535,     0,   424,   423,   422,   421,
     417,   418,   425,   426,   420,   419,   410,   409,     0,   411,
     534,   412,   415,   413,   414,   416,   508,     0,     0,   486,
       0,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     359,     0,     0,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,   391,     0,   233,     0,     0,     0,     0,
       0,   517,   516,     0,     0,     0,     0,     0,     0,     0,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   378,     0,     0,     0,   258,     0,
       0,     0,   252,     0,     0,     0,     0,   388,   405,   531,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   311,   312,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   620,     0,     0,     0,   503,
       0,     0,   263,   267,   265,   269,     0,     0,   411,     0,
     508,   486,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,   405,     0,     0,     0,    66,
       0,     0,    87,     0,    66,    67,     0,     0,     0,   508,
       0,     0,   486,     0,     0,     0,   203,     0,     0,     0,
     636,    28,    26,    27,     0,     0,     0,     0,     0,   583,
      30,     0,    29,     0,     0,   272,   631,   632,     0,   633,
     583,     0,     0,    82,   120,    83,   130,   510,   512,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   569,   570,   298,   233,   220,     9,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   450,
     437,     0,   439,   440,   441,   442,   443,   566,   444,   445,
     446,     0,     0,     0,     0,     0,   558,   557,   556,     0,
       0,     0,   563,     0,   498,     0,     0,     0,   500,     0,
       0,     0,     0,   134,   481,   538,   537,   213,     0,     0,
       0,   467,   565,   472,     0,   478,     0,     0,     0,     0,
     528,     0,     0,   479,   544,   540,     0,     0,     0,     0,
     471,   470,    73,    74,   493,     0,     0,     0,     0,     0,
       0,     0,   405,   357,   362,   360,     0,   371,     0,   156,
     157,     0,   213,     0,   405,     0,     0,     0,     0,     0,
     253,     0,   268,   270,     0,     0,     0,   221,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     331,     0,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,   364,   377,     0,     0,     0,
       0,   254,     0,     0,     0,     0,   216,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,     0,     0,   606,     0,   613,   602,   603,   604,
       0,   619,   618,     0,     0,   607,   608,   609,   615,   623,
     622,     0,   147,     0,   596,     0,   598,     0,     0,     0,
     591,     0,     0,   262,     0,     0,     0,     0,     0,     0,
       0,   350,     0,     0,     0,   401,     0,   637,     0,   109,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,     0,     0,     0,   588,    51,     0,
       0,     0,    64,     0,    41,    42,    43,    44,    45,    46,
       0,   471,   470,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   582,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   137,   138,     0,     0,     0,     0,   163,   163,     0,
       0,     0,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   368,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   545,   546,   547,   548,     0,     0,   549,     0,     0,
       0,   501,   502,     0,   474,     0,     0,   536,   427,   529,
     487,   485,     0,   484,     0,     0,   554,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   370,     0,     0,     0,
       0,     0,   393,     0,     0,     0,    77,     0,   261,     0,
       0,     0,     0,     0,     0,     0,   336,     0,     0,   335,
       0,   338,     0,   340,     0,   325,   332,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     379,     0,     0,   256,   255,   396,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,   574,     0,     0,
       0,   301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,   504,   600,     0,   374,   487,     0,
       0,   233,   351,     0,   352,   233,     0,     0,   589,     0,
      94,     0,     0,     0,     0,    92,     0,   577,     0,   107,
       0,    99,   101,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    36,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   584,
       0,     0,    34,    33,     0,   584,   634,   287,     0,     0,
     121,   126,     0,     0,     0,   140,   145,   146,   141,   142,
     506,     0,    85,     0,    86,   167,     0,     0,     0,     0,
     168,   187,   188,   165,     0,     0,     0,   169,   198,   189,
     193,   194,   190,   191,   192,   177,     0,     0,     0,   438,
     452,   451,   447,   448,   449,   559,     0,     0,     0,   496,
     497,   499,   135,   465,   495,   468,   473,     0,     0,   501,
     199,   480,    73,    74,     0,   492,   488,   490,   560,   195,
       0,     0,     0,   159,     0,     0,   369,     0,   158,     0,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     233,   233,     0,     0,   337,   524,     0,     0,   339,   341,
       0,     0,   319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   196,     0,     0,     0,     0,     0,
       0,     0,   174,     0,   175,     0,     0,     0,     0,   110,
     114,     0,   614,     0,     0,   612,     0,   624,     0,     0,
     148,   149,   621,   597,   599,     0,     0,     0,     0,     0,
       0,   349,   353,   349,     0,   402,    93,     0,     0,    66,
       0,     0,    91,     0,   575,     0,     0,     0,     0,     0,
       0,   627,   626,     0,     0,     0,     0,     0,   522,     0,
       0,    77,   273,   488,   274,     0,     0,     0,     0,     0,
     238,   235,     0,     0,   587,   585,     0,     0,     0,     0,
     122,   127,     0,     0,     0,   567,   568,   139,   373,   164,
     172,   173,   178,     0,     0,     0,     0,     0,   180,     0,
       0,   299,     0,     0,     0,     0,   475,     0,     0,     0,
     555,   494,     0,     0,   179,     0,   200,   358,     0,     0,
       0,     0,   201,     0,     0,     0,     0,     0,     0,   521,
     520,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   240,     0,     0,     0,   375,   376,    39,   182,   183,
       0,   572,     0,     0,   303,   302,     0,     0,     0,     0,
       0,     0,   151,   152,   155,   154,   153,     0,   601,     0,
     638,     0,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   578,     0,     0,     0,    96,     0,     0,     0,    47,
       0,     0,     0,     0,     0,    49,     0,   239,   236,   237,
      35,     0,     0,   635,   289,     0,   134,   147,     0,     0,
     144,     0,     0,     0,   166,   197,     0,     0,     0,     0,
       0,   561,   562,     0,   501,   476,   489,   491,     0,     0,
     181,   204,     0,     0,     0,   365,   365,     0,   115,   116,
     233,     0,   224,   225,   326,     0,   333,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,   230,     0,
     228,     0,     0,     0,     0,   111,   112,   605,   611,   610,
     150,     0,     0,     0,   354,     0,     0,   108,   100,   102,
       0,    90,   628,    97,    98,    52,     0,     0,     0,     0,
     523,     0,     0,   489,   586,     0,     0,     0,     0,   124,
     625,     0,   131,     0,     0,     0,     0,   186,     0,     0,
       0,   329,     0,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   519,     0,   343,     0,     0,
     320,     0,   241,     0,     0,     0,     0,     0,     0,   229,
       0,   571,   304,     0,     0,   387,   233,   403,     0,   576,
       0,    48,     0,     0,     0,    65,    50,     0,   290,   123,
     128,   134,     0,     0,   161,   162,   160,     0,     0,   477,
       0,     0,     0,     0,   366,   380,     0,     0,   381,     0,
     222,     0,   334,     0,   316,     0,   233,     0,     0,     0,
       0,     0,     0,   176,   113,   300,   349,   106,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,   202,
       0,   384,     0,   385,   386,   518,     0,     0,   322,   244,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
      62,     0,     0,   125,     0,     0,   330,     0,     0,   342,
     321,   317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,   247,   248,     0,   242,   356,    53,     0,    60,
       0,   284,     0,   564,     0,     0,   323,     0,     0,    54,
       0,     0,   297,     0,     0,   243,     0,     0,     0,     0,
       0,     0,    57,    55,     0,    58,     0,   382,   383,     0,
       0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   123,  1114,   124,   125,  1098,  1978,  1984,
    1404,  1627,  2140,  2268,  1405,  2241,  2284,  1406,  2270,  1407,
    1408,  1631,   459,   619,   620,  1186,  1725,   126,   818,   487,
    1996,  2151,  1997,   488,  1864,  1486,  1440,  1441,  1442,  1590,
    1800,  1801,  1258,  1686,  1677,  1874,   793,   631,   291,   292,
     367,   214,   293,   469,   470,   130,   131,   132,   133,   134,
     135,   136,   137,   294,  1293,  2175,  2232,   988,  1289,  1290,
     295,  1077,   296,   141,  1515,  1256,   960,  1003,  2109,   142,
     143,   144,   145,   297,   298,  1213,  1229,  1359,   299,   823,
     300,   822,   490,   648,   335,  1837,   371,   372,   302,   589,
     386,  1388,  1618,   480,   475,  1352,  1053,  1667,  1830,  1831,
    1038,   482,   147,   436
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1976
static const yytype_int16 yypact[] =
{
   13201,    78,   123, 13408, -1976, -1976,   199,    93,    55,  -110,
     -87,   -57,    18,   134,   222,   228,   231,    81,    37,    42,
     113,   376,   382,   141,   157,    25,     6,    26,     6,    99,
     178,   191,    15,   212,   217,    16,   235,   240,   263,   295,
     303,   354,   374,   377,   466,   497,   163,   358,   571,   769,
     787,   548,   556,   151,   710,   592,  7420,   602,   621,   629,
     773,   -50,   731,    26,    12,   -39,   634,   809,   -90,   668,
     442,   442,   679,   501,   352,   682, -1976, -1976, -1976, -1976,
   -1976,   656,   301,   816,   854,    30,   108,   855,   872,   -56,
    6392,   884,  1003,  1004,  1025,  6392,  1039,   -80,   -75,   792,
      27,    60, -1976,   800,   801, -1976, -1976,  1047,  1055,   808,
   -1976,  6254,   817, 13656,    22,    33,    26, -1976, -1976, -1976,
   12301,   814,  1075, -1976, -1976, -1976, -1976, -1976,   825, -1976,
   -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976,    51,
   -1976, -1976, -1976, -1976,    38, -1976,  1084,   824,  6133,   323,
     832,  1090, 12301, 13594, 13594, 13594, -1976, 12301, -1976, -1976,
   -1976, -1976, 13594, -1976, 12301, -1976, -1976, 12301, -1976, -1976,
   -1976, -1976,   830,   839,  1091, -1976, -1976, 13693, -1976, -1976,
   -1976, -1976,   840, 13693, 12301, 12301, 12301,   842, 12301, 12301,
   12301,   845, 12301, 12301, 12301, 12301, 12301, 12301, 12301, 13594,
   12301, 12301, 12301, 12301,  6392,   850, -1976, -1976, 10237, 10237,
   -1976, -1976, -1976,   847,  6392,  7677, 13594, -1976, -1976, -1976,
   -1976, -1976,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,   196,     6,     6,
       6,     6,     6,   856,     6,     6,   858,    26,   713,   713,
     713, -1976, -1976, -1976,     6,     6,    35,   918,   919,   923,
     857,  7677,   986,    26,    26,   713,   862,     6,     6,   863,
     864,   867, -1976, -1976, -1976, 12301,  7934, 12301, 12301,  8191,
      25,   933,    36, -1976, -1976,   866, -1976,  4970, -1976, -1976,
   -1976, -1976, -1976,   104, 12301, 10237, 10237,   871,   873,  8448,
    6392,  6392,  6392, -1976, -1976, -1976,   874, -1976,   868,   875,
    8705,   876,  4903,  1131,  7677,   880,    27,   896,   898,   442,
     442,   442, 12301, 12301,   175, -1976,   551,   442,  5228,   565,
     232,   877,   878,   879,   888,   903,   904,   905, 10237, 12301,
    6392,  6392,  6392,   246,    21,  1159,   906, -1976,  1162,  1163,
   -1976,   907,   908,   909, -1976, -1976,   910,  6392, -1976, 12301,
    6649, -1976,  1167,   912,   937,   939,   944,  1200,  1202,   950,
   12301,   951, 12301, 12301,   430, 12301,   949, -1976,  1020, 12301,
   12301, 12301, -1976, -1976, 12301, -1976,     6,     6,     6,   957,
     958,   959,     6,     6,     6,     6,     6,     6,     6, -1976,
       6, -1976, -1976, -1976, -1976,     6,     6,   960,   961,     6,
     962, -1976,   963,  1217,  1219,   964, -1976, -1976,  1220,  1222,
    1225,  1224,   974,     6, 12301, 15297,   118, 13594, -1976, 10237,
   12301, -1976, -1976,  7677,  7677, -1976,   971, 13693,    26,  1228,
   -1976, -1976, -1976, -1976, -1976, -1976, 12301, 12301,   415,  7677,
    1230,   341,   976,  1152,   979,  1231,    59,   980, -1976,   988,
   13923, 12301, -1976,  1216,  -180, -1976,    76,  -167,   -45,  6044,
   -1976,     1, -1976,    85,  7609,  3995,  7866,  -127,   -46,  1151,
   -1976,    25,   982, 12301,   985,  3008, 15813, 15838, 12301, 15863,
   15888, 15913, 12301, 15938, 15963, 15988, 16013, 16038, 16063, 16088,
     994, 16113, 16138, 16163, 14311,  1248, 12301, 10237,  5163, -1976,
     272,   273, 12301,  1250,  1251,   998, 12301, 12301, 12301, 12301,
   12301, 12301, 12301, 12301, 12301, 12301, 12301, 12301, 12301, 12301,
   12301, 12301, 10237, 12301, 12301, 12301, 12301, 12301, 12301, 12301,
   12301, 10237, 10237,   996, 12301, 12301, 13594, 12301, 13594,  7677,
   13594, 13594, 13594,   997,   999,  1000,  1001, 12301,    32, -1976,
   11190, 12301,  7677,  6392,  7677,  1002, 13594, 13594, 10237,    25,
   13693,    25,  1011, 10237,  1011, -1976,  1011, 16188, -1976,   346,
    1005,   107,  1204, -1976,  1264, 12301, 12301, 12301, 12301, 12301,
   12301, 12301, 12301, 12301, 12301, 12301, 12301, 12301, 12301,  8962,
   12301, 12301, 12301, 12301, 12301,    25, 12301, 12301,    63, -1976,
     782, 16213,   413,   486, 12301, 12301, 12301, -1976,  1266,  1267,
    1267,  1017, 12301, 12301, 12301, 12301,    29, 10237, 10237, 15325,
    1021,  1271, -1976,  1019, -1976, -1976,   -78, -1976, -1976,  8123,
    8380,   442,   442,   323,   323,   -70,  5228,  5228, 12301, 11244,
     -65, -1976, 12301, 12301, 12301, 12301, 12301, 12301, 12301, 12301,
   12301,   508, 16238,  1273,  1277,  1278, 12301, 12301,  1280, 12301,
   -1976, -1976, 12301, 11929, -1976, -1976, 10237, 10237, 10237, 12301,
    1281, 16263,  1024, 12301, 10237, 12301, 12301, 12301, -1976, -1976,
   12301, 16288, 12301, 16313, 16338,  1092,  8637, -1976,  1026,  5272,
   16363, 16388, 15408, 13594, 13594, 13594, 13594, 13594, 13594, 13594,
   13594, 13594, 12301, 13594, 13594, 13594, 13594,     5, 13693, 13594,
   13594, 13594,    25,    25, -1976, -1976, 10237, -1976,  1027, 12268,
   -1976,  1028, 12432, 12301, 12301,  1011, 12301, -1976,    25, 12301,
   12301,    63,  1032,   510, 16413, 13821,  1030,   541, 12301,  1289,
    1033,  7677, 16438, 15435, -1976, -1976, -1976, -1976, -1976,  1034,
    1290,   160,  1292, -1976, -1976, -1976, 10237,   210, 12301, -1976,
   -1976, -1976,    25, 12301, 12301,    63,  1042, -1976,  1041,   -27,
      26,    12,    26, -1976,  1043, 14340, -1976,   147, 10237,    25,
   12301, 12301,    63,  1298, 10237,  1299, 10237, 12301,  1301, 13594,
      25, 11277,    63, 12301, -1976, 12301,  1302, -1976,    25,  1303,
   13594, 12301,  1050,  1052, -1976, 12301,  8894, 13693,  1304,  1308,
    1309, 16463,  1310,  1311,  1312, 16488,  1314,  1317,  1318,  1319,
    1320,  1321,  1323, -1976,  1324,  1326,  1327, -1976, 12301, 16513,
   10237,  1072, 10237,    49, 14369, -1976, -1976,  1330, 15381, 15381,
   15381, 15381, 15381, 15381, 15381, 15381, 15381, 15381, 15381,  9151,
   15381, 15381, 15381, 15381,   420,   612, 15381, 15381, 15381,  9403,
    9655,  9912, 10169, 10520,  5163,  1078,  1077,    77, 10237, 10873,
   11221,   612, 11484,   612,  1074,  1076,  1079,    83, 10237, 12301,
   12301, 12301, 17463, -1976,   612,  1081, 14398, 14427, -1976, -1976,
   12301,  1080,   -73,   612,  -203,  1083,   502,   558,  1333, -1976,
      63,   612,  7677,  1082,  5307,  5497,  1946,  1180,   539,   539,
     607,   607,   607,   607,   607,   607,   580,   580, 10237,   280,
   -1976,   280,   280,  1011,  1011,  1011,  1086, 16538, 15462,   610,
   10237, -1976,  1342,  1093,  1094, 16563, 16588, 16613, 12301,  7677,
    1349,  1348, 10938, 16638, 14456, 16663, 16688, -1976, 12301,   578,
     584, 10237,  1095, -1976, 12492, -1976, 12564, 12624,   442, 12301,
   12301, -1976, -1976,  1098,  1100,  5228,  6325,  1214,   -18,   442,
   12686, 16713, 14485, 16738, 16763, 16788, 16813, 16838, 16863, 16888,
    1096,  1358, 12301,  1360, -1976, 12301, 16913, 14514, -1976, 15489,
   12746, 15516, -1976,   600,   615,   618, 14543, -1976, -1976, -1976,
    1245,   623, 15543, 15570, 11560, 16938,  1361, 16963,  1362,  1365,
    1102, 12301, 12808, 12301, 12301, -1976, -1976,    39,   438,   509,
     438,  1114,  1115,  1105,   612,   612,  1108, 11906,   612,   612,
     612,   612, 12301,   612,  1368, -1976,  1110,  1119,   540,   -77,
    1118,   626, -1976, -1976, -1976, -1976, 16988, 15381,   280, 12868,
    1116,   619,  1139,  1188,  1378,  1242, 11529,  1144,  1148,  1406,
    7677, 14572, -1976, 12301,  1407,   164,    97,    63,    28, 13693,
   12301,  1409, -1976,   652,  1386,  1388,  7677, 14601,    47,  1174,
   17013, 15597,   388, 12301, 12301,  1158,  1178,  1183,  1181,  9219,
   -1976, -1976, -1976, -1976, 13594,   110,  1182, 17038, 15624,  1184,
   -1976,   144, -1976,   171, 12245, -1976, -1976, -1976,  1186, -1976,
    1189, 14630, 12984, -1976,    98, -1976, -1976, 17463, -1976,   121,
   15381, 12301,   612,   442,  7677,  7677,  1438,  7677,  7677,  7677,
    1442,  7677,  7677,  7677,  7677,  7677,  7677,  7677,  7677,  7677,
    7677,  1708,  1463, 10237,  5163, -1976, -1976,   323, -1976, -1976,
   -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976,
   -1976, 12301, -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976,
   -1976, 12301, 12301, 12301, 12301, 12301, -1976, -1976, -1976,   653,
   12301, 12301, -1976, 12301, -1976,  7677, 13594, 13594, -1976,   659,
   14659, 14688, 14717,  1203, -1976, -1976, -1976,  1282, 14746, 12301,
   12301, -1976, -1976, -1976,    63, -1976,    63, 12301, 12301,  1218,
   -1976,  7677,     6, -1976, -1976, -1976, 12301, 12301,   661,    63,
     480,  -119, 12301, 12301, -1976,   612,   662,  7677, 10237, 10237,
    1469,  1472,  1492,   660, -1976, -1976,  1494, -1976,  1241, 17463,
    1236,  1498, -1976,  1499,  1500,  1804,  1504,  1506,   664,    74,
   -1976, 12930, -1976, -1976,   -54, 13199, 13602, -1976, -1976, 14775,
     -22,  1394,  1511, 11623,  1256,  1514,  1262,    20,    24,  -102,
   -1976,     2, -1976,   -18,  1516,  1518,  1519,  1520,  1521,  1522,
    1523,  1524,  1525,   323,  7677, 17463, -1976,  2001,  1270,  1423,
    1528, -1976,  1530,  1531,  1430,  1532, -1976, -1976,  1533,  1535,
    1536, 12301,  1537,  7677,  1538,  7677,  7677,  1539, 13650, -1976,
    5603,   941,    63,    63, -1976, 10237, -1976, -1976, -1976, -1976,
   13594, -1976, -1976, 12301, 13594, -1976, -1976, -1976, -1976, 17463,
   -1976,  1283,  1279, 13594, -1976, 13594, -1976,    63, 13594,  1288,
   -1976,  1284,  1545, -1976,    63, 12301, 12301,  1293,    26,  1294,
   11875, -1976,  2055,  1296,  7677, -1976,  1291, -1976, 14804, -1976,
   -1976, 12301,  1547,   449, 12301,  1554,  1555,    27,  1557,  1305,
    1558,  2397, -1976,   612,     6,     6,  1559, -1976, -1976,  1313,
    1315,  1307, -1976,  1561, -1976, -1976, -1976, -1976, -1976, -1976,
      63,   383,   984, 12301, 15651, 17063, 12301,  9471, 12301, 10237,
    1316,   672,  1562,   158,    63, -1976,  1322, 12301,  1567,  1569,
   12301,    63, 11962,  1570, 12301, 10489,   612,  5565, 12301, 12301,
    1328,  1325, -1976,  1571, 17088,  1572,   124,  1444,  1444,  7677,
    1573,  1576,  1578,  7677,   -97,  1580,  1582,  1583,  1585,  1588,
    1589,  1590,  1591,  1593, -1976,  1595,   673,  1337, 15381, 15381,
   15381, 15381, 15381, 15381,   612, 13753, 13849, 13882,  1343,   612,
     612, -1976, -1976, -1976, -1976,   121,   612, -1976, 17113, 15381,
    1344,   -41, 17463, 15381, -1976,  1596,   612, 17463, 17463, -1976,
     389, -1976,    63, -1976, 17138, 15678, -1976,   612,  1599,   675,
     680,  7677,  7677,  7677,  1602,  1601, -1976,   214, 12301,  7677,
    7677,  7677, -1976,  1345,  1346,  1603,  1605,  1607, -1976, 12301,
   12301, 12301,  1352,  1353,  1354,  1351, -1976,  2428,  7677, -1976,
   12301, -1976,  1612, -1976,  1613, -1976, -1976,  5228,   -83,  6906,
   -1976,  1357,  1363,  1366,  1367,  1369,  1371,  9723,  1359,  1618,
   -1976, 10237,  1372, -1976, -1976, -1976,  1373, 12301, 12301, -1976,
   -1976, 15705,  7677,  1619,  7677,  1622,  1440, -1976, 12301, 12301,
   12301, -1976,  1631,   759,   575,  1370,  5799,  1375, 12301,    41,
     612,  1379,   612,  1376, -1976, -1976, 13693, -1976,   734, 12301,
    1377, -1976, -1976,  2589, -1976, -1976,  1380,  1635, -1976,  3034,
   -1976,  1381,  1640,   173,  3101, -1976,    27, -1976,   686, -1976,
   12301, -1976, -1976,   214,  2337,  5277, -1976,  1391, 12301, 12301,
    7677,  1389, -1976,   318,   423,  1645, 17163,  1647,  1333, 17188,
    1390,   687, 17213,   693,  1649,  1651, -1976, -1976, 13594,  1399,
    1655, 17238, -1976, -1976, 13915,  1401, -1976, -1976,  6581,  5866,
   17463, -1976,  1656,     6,  8191, -1976, -1976, -1976, 17463, 17463,
   -1976,   121, -1976,  1658, -1976, -1976,   442,  1659,  1660,  1661,
   -1976, -1976, -1976,  1526,   -48,  1556,  1662, -1976, -1976, -1976,
   -1976, -1976, -1976, -1976, -1976, -1976,  1672,  1415,  1673, -1976,
   -1976, -1976, -1976, -1976, -1976, -1976, 12301, 12301, 12301, -1976,
   -1976, -1976,  1325, -1976, -1976, -1976, -1976, 12301,  1420,  1413,
   -1976, -1976, 12301, 12301,   612,   480, -1976, -1976, -1976, -1976,
    1419,  1421,  1677,   -97,  1679, 12301, -1976,  7677, 17463,  1542,
    1543,  1046, 10237, 10237, 12301, -1976, 10938, 14833, 17263,  6838,
     323,   323, 12301, 12301, -1976,   347,  1424, 17288, -1976, -1976,
   14862,   167, -1976,  1682,  1685,  7677,   442,   442,   442,   442,
     442,  7163,  1687, -1976, -1976,   698, 10237, 12301,  3296,  3473,
    1688,  1689, -1976,  1690, -1976,  7677,  7095,   379, 17313, -1976,
   -1976, 10585, -1976, 13594, 12301, -1976, 13594, 17463, 10842, 13693,
    1431, -1976, -1976, -1976, -1976,  1443,  1447, 12301, 12301, 14891,
   12301, 13821, -1976, 13821,  7677, -1976, -1976,    63,    28, 13693,
   12301,  1710, -1976,  1712, -1976,    27, 15732,  7677, 13594,  1713,
     612, -1976,  1452,   612, 12301, 13948, 13981,   699, -1976, 12301,
   12301,  1458, -1976,  1459, -1976,  1492,  1717,  1720,  1500,  1721,
   -1976, -1976,  1722, 12301, -1976, -1976, 12301, 12214,  1723, 12301,
   -1976, -1976,  1467,  5277,   706,  4164,  1724, -1976, -1976,   496,
   -1976, -1976, -1976,  1584,  1727,  1473,  1474,  1475, -1976,  1730,
    7677, -1976, 15381, 15381, 14014, 15381, -1976,  1481, 17338, 15759,
   -1976, -1976, 10237, 10237, -1976,  1736, -1976, 17463,  1738, 12301,
   12301,  1483, -1976,   707,   708, 15353,  3626,  1741,  1485, -1976,
   -1976, 12301,  1487,  1488, 14920, 15786,  1747,  7677,  1748,  1491,
   12301, -1976, -1976,   709,   236,   245,   250,   255,   260,  9980,
     277, -1976,  1750,   714, 14949, -1976, -1976, -1976, -1976, -1976,
    1574, -1976, 12301, 12301, -1976, -1976, 10237,  3669,  1751,  1501,
   15381,   612, 17463, -1976, -1976, -1976, -1976,    41, -1976, 13693,
   -1976, 14978,  1495,  1496,  1502,  1756,  1759,  1761,  4053, -1976,
   -1976, -1976,  1505,  1763,   715, -1976,  1768,  1769,   201, 17463,
   12301, 12301,  1513,  7677,   717, 17463, 17363, -1976, -1976, -1976,
   -1976, 17388, 14047, -1976, -1976, 15007,  1203,  1279,  7677,   612,
   -1976, 12301, 13693,    25, -1976, -1976, 10237, 10237, 12301,  1771,
     722, -1976, -1976, 12301,  1413, -1976, -1976, -1976,   723,   730,
   -1976, -1976,  4141,  4522,  7677,   544,   695, 10237, -1976, -1976,
     323,  7352, -1976, -1976, -1976,  1772, -1976,  1515,  7677, -1976,
   15036,  1774, 10237,   442,   442,   442,   442,   442, -1976,  1775,
   -1976, 12301, 15065, 15094,   735, -1976, -1976, -1976, -1976, -1976,
   -1976,  1527,  1777,  1529, -1976,  1779,    27, -1976, -1976, -1976,
    1598, -1976, -1976, -1976, -1976, -1976, 12301, 14080, 14113,  7677,
   -1976,  1780, 12301,  1534, -1976, 12301,  1782,  1540,  1541, -1976,
   -1976,  4937, -1976,  1544,   736,   737, 15123, -1976,  1546, 14146,
    1548, -1976,  1549, -1976, -1976,   738,  1550,   442,  7677,  1783,
    1551,   442,  1788,   745,  1552, -1976, 12301, -1976,  1789,  1654,
   12990,  1560, -1976,   746,   282,   296,   299,   304,   428, -1976,
    4567, -1976, -1976,  1793,  1795, -1976, -1976, -1976,  1796, -1976,
    1577, 17463, 12301, 12301,   752, -1976, 17463, 14179, -1976, -1976,
   -1976,  1203, 13693,  1575, -1976, -1976, -1976, 12301, 12301, -1976,
   10237,  1800,   442,   133, -1976, -1976,   442,   137, -1976,  1801,
   -1976, 15152, -1976, 12301, -1976,   -18, -1976,  1811, 10237, 10237,
   10237, 10237,  9980, -1976, -1976, -1976, 13821, -1976, 12301, 17413,
   14212,    50, 12301,  1581, -1976, -1976, 14245, 14278,   753, -1976,
     439, -1976,   484, -1976, -1976, -1976,  4602,   338, 13052, -1976,
     754,   755,   760,   762,   487,   763,  1586,   794, -1976, 12301,
   -1976,  7677, 15181, -1976, 12301, 12301, -1976,   442,   442, -1976,
   -1976, -1976,   -18,  1812,  1813,  1814,  1815, 10237,  1835,  1840,
    1841,  1604, 17438,   802,  1842, 15210, 15381,   491,   494,   530,
   -1976, -1976, -1976, -1976,   803, -1976, -1976, -1976, 13594, -1976,
    1606, -1976,  1843, -1976, 12301, 12301, -1976,  1845,   804, -1976,
    1608,  7677, -1976, 15239, 15268, -1976,  1847, 13594, 13594,   810,
    1848,  1850, -1976, -1976,   819, -1976,  1852, -1976, -1976,  1853,
   13594, -1976, -1976, -1976
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1976, -1976, -1976, -1976,   447, -1976, -1976, -1976, -1976,  -316,
   -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976, -1976,
   -1976, -1976,  -760,  -133,  4479,  3613,  -399, -1976,  1385, -1976,
   -1976, -1976, -1976, -1976, -1976, -1975, -1976,   390,   209,  -116,
   -1976,   -71, -1976,   149,   435, -1976,  1881, -1976,  1113,   -51,
   -1976, -1976,    -1,  -648,  -165, -1976, -1976, -1976, -1976, -1976,
   -1976, -1976,   789,  1885, -1976, -1976, -1976, -1976, -1286, -1285,
    1888, -1795,  1889, -1976, -1976, -1976,  1263, -1976,  -132, -1976,
   -1976, -1976, -1976,  2417, -1976, -1976, -1483,   302,  1893, -1976,
     -13, -1976, -1976,    95, -1976, -1751,   553,   -72,  3125,  2795,
    -323,    79, -1976,  1776,   -74, -1976, -1976,   100,   274, -1748,
    -152,  1097, -1976,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -588
static const yytype_int16 yytable[] =
{
     148,   485,   129,   643,  1546,   983,   984,  1548,  1718,   172,
     481,  1090,   173,   320,  1923,   460,  1962,  1096,  1963,   187,
     191,  2087,   174,   377,   156,   678,  1541,   428,   379,   172,
    1543,   384,   172,   381,   354,   967,   172,   423,   430,   427,
     569,   593,  1282,   163,   442,  1798,  1332,  1684,   165,   364,
    1955,  1398,   365,   303,  1875,  1166,  2220,  1223,   308,   771,
    1283,  1282,  1224,   172,   388,   366,   321,   764,   782,   322,
    1284,  1285,  1286,  1876,   465,   325,  1287,  1288,  1526,  1283,
     797,   308,   358,   309,     4,   799,   615,   303,   798,  1284,
    1285,  1286,   303,   803,   810,  1287,  1288,   387,  1685,   765,
     766,   804,   326,   492,  1380,  1435,  1105,   151,   424,   494,
     765,   766,   359,   615,   360,  1999,   491,   314,   327,   328,
     315,   316,   317,     5,   355,  1437,  1282,   748,   178,  2010,
    1675,   179,   515,   318,   180,   816,   181,   454,   455,  2201,
     158,   817,   523,  2203,  1283,   466,  1502,    46,   468,   153,
     476,   476,   476,  1111,  1284,  1285,  1286,  1438,  1439,   483,
    1287,  1288,  1545,   152,  1647,   334,   336,  1089,   339,   651,
     652,  1380,   154,   659,   767,   768,  2193,   651,   652,   380,
    1819,  1762,   651,   652,   382,   767,   768,   774,  1357,   775,
     978,  1358,   683,   651,   652,  1220,   476,   968,   985,   319,
    1542,   303,   155,   989,  1544,   303,   303,   564,   565,   566,
     361,   303,   303,   476,  1529,   805,   819,  1094,   175,   949,
     176,  1380,   817,   806,   575,   651,   652,  1227,   159,  1399,
    1400,  1401,  1402,   356,   160,   121,  1887,   161,   628,   629,
     630,   101,  1533,   102,   103,   104,   105,   106,  1799,   651,
     652,   110,   111,   210,   113,   121,   211,   121,   121,   212,
     121,   808,   121,  1546,   739,   175,   742,   176,   303,   809,
    1547,  1052,   213,  2105,   188,   192,   755,   590,   673,   674,
     675,   157,   679,   303,   680,   429,   303,   591,   150,   121,
     385,  1387,   774,   357,   775,   690,   431,   443,   570,   594,
     164,   444,   303,   303,  1333,   166,   303,   303,   303,   303,
     440,  1403,  1167,  2221,   441,   454,   455,   303,   783,   389,
     784,   303,  -580,   387,   785,  1381,  1384,   467,  2144,   450,
     451,   452,   453,   454,   455,   800,   616,   801,   617,  1198,
     162,   802,   618,  1208,   811,   303,   801,   303,   303,   303,
     812,   809,  1071,   454,   455,   595,   340,   175,   184,   176,
     454,   455,  1383,   616,   303,   617,   175,   303,   176,   618,
    1423,   651,   652,   759,   454,   455,   167,   749,   852,   750,
     651,   652,   168,   751,   651,   652,  1102,  1943,   169,  1112,
    1113,  2216,   450,   451,   452,   453,   450,   451,   452,   453,
    1112,  1113,   170,  1119,  1428,   450,   451,   452,   453,   350,
     897,   351,   852,  1130,   651,   652,   454,   455,   171,   764,
     454,   455,   651,   652,   646,   647,   203,  1841,   595,   454,
     455,  1429,   655,   660,   476,  1920,   303,   185,   653,   852,
     303,   303,   450,   451,   452,  1095,   450,   451,   452,   453,
     186,   765,   766,   764,   341,   551,   303,   552,   342,   765,
     766,  2075,   149,   786,   343,   344,   150,   345,   346,  2076,
    2243,   189,    69,    70,    71,    72,   190,   974,    75,   976,
     977,   204,  1282,   651,   652,   765,   766,    84,   824,   347,
      87,   662,   651,   652,   193,   663,   990,   651,   652,   194,
    1283,   908,   651,   652,  2042,   676,   915,   651,   652,   677,
    1284,  1285,  1286,  2043,   303,  1010,  1287,  1288,  2044,  1467,
    2279,  1232,   195,  2045,   651,   652,   767,   768,  2046,   651,
     652,  2100,   612,   613,   767,   768,   851,   853,   614,   303,
     852,   852,  1032,   651,   652,  2047,   651,   652,   303,   887,
    2178,   651,   652,   476,   196,   476,   303,   476,   476,   483,
     767,   768,   197,  1040,  2179,   904,   914,  2180,   916,   303,
     303,   303,  2181,   476,   476,   303,   174,  1840,   174,  1808,
     303,  -584,  1069,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   774,  2230,   775,   776,   614,   303,   769,   770,   301,
     919,  1916,   946,   198,   852,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,   199,   303,   303,   200,   614,  1091,   454,
     455,  1611,  1612,  1944,   454,   455,  -582,  1413,  1722,  1366,
    1723,  -583,   468,   468,  1055,  1558,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   850,
     610,   611,   612,   613,  1282,   651,   652,   953,   614,   205,
     774,   852,   775,   303,   303,   303,   651,   652,  1386,   330,
     331,   303,  1283,  2106,  2107,   705,  2182,   150,   774,  2108,
     775,   332,  1284,  1285,  1286,   333,   809,  2227,  1287,  1288,
     483,   476,   483,   476,   476,   476,   476,   476,   476,  1059,
     476,   476,   476,   476,  1054,   201,   476,   476,   476,   174,
    1060,   651,   652,   303,   651,   652,   454,   455,   651,   652,
    1107,   651,   652,   651,   652,  1070,   981,   982,   330,   331,
     954,   647,  2228,  1142,   852,  2237,   202,  1737,   303,  2264,
     332,   175,  2265,   176,   338,  1790,  1791,  1226,   524,   774,
    1227,   775,  1000,   303,  1073,   206,   852,  1335,   852,  1099,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,   207,  2266,   303,  1116,   614,   651,   652,
     774,   303,   775,   303,  1514,  1079,   483,  1128,  1355,  1080,
    1271,   208,   651,   652,   654,  1134,  1244,   476,   314,   209,
     215,   315,  1230,   317,   301,  1490,   852,  1491,   661,   746,
     610,   611,   612,   613,   318,   774,   310,   775,   614,   311,
    1500,   312,  1266,   852,  2110,  2111,   852,   303,  1267,   303,
    2108,   216,   852,  1820,   607,   608,   746,   610,   611,   612,
     613,   304,   627,  1827,  1313,   614,   454,   455,   852,  1242,
    1527,  1243,   774,   636,   775,   454,   455,   641,  1365,  1314,
    1366,   307,  1315,   852,   305,   303,   852,  1318,  1260,  2207,
    1361,   852,   306,   323,   852,   303,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,   324,   349,  1393,  1474,   614,   303,
     852,   852,  1546,  1481,   352,  1499,  1507,   852,  1525,   852,
     852,   329,   852,  1582,  1583,   303,  1645,  1697,  1244,  1730,
     852,   852,   337,   852,  1731,   348,  2249,   303,   852,  1580,
    1824,  1847,  1382,  1385,  1825,   852,   303,  1849,  1593,   353,
     362,   852,  1932,  1982,  1546,  1598,   852,  1983,   303,  1244,
    2000,  2025,  2026,  2041,  2001,   852,   852,  1983,  2049,  2072,
     363,  2081,   852,   809,  1613,  2082,  2098,  2101,   172,   395,
    1983,   852,   373,  1807,  2102,  1808,   756,   757,   852,  2133,
    2154,  2155,  2161,   852,   852,   852,  1983,   374,   375,  2169,
    2177,  1633,   772,   852,   852,  1390,  2191,  2226,  2233,  2234,
    1983,   852,   852,   852,  2235,  1649,  2236,  2238,   852,   376,
     852,   852,  1655,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   774,   378,   775,   950,   405,   406,   407,   408,
    1901,   383,  1902,   392,   409,   410,   411,   412,  2240,   390,
     391,   393,  2082,   413,  1617,   414,  2260,  2267,  2276,   394,
    1983,   852,  2277,  1274,  2286,   437,   425,   303,  1983,   415,
    1280,   438,   416,  2289,  1291,  1389,   178,  2290,   439,   179,
     445,   446,   180,   303,   181,   471,   472,   150,   489,   493,
     491,   498,  1912,  1913,   502,    46,   303,  1501,  1503,   516,
     522,   476,   894,  -206,  -207,   559,   128,   562,  -208,   572,
     571,   576,   579,   580,   448,   627,   581,   909,   592,   441,
     624,   633,   625,   632,   634,   640,   664,   665,   666,   637,
     182,   303,   303,   642,   303,   303,   303,   667,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   779,   644,
     303,   645,   668,   669,   670,   681,   468,   682,   684,   685,
     686,   687,   688,   689,   693,   694,   313,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,   417,   418,   419,   695,   614,
     696,  1581,   303,   476,   476,   697,   698,   420,   699,   700,
     702,   421,   707,   422,   121,   708,   716,   717,   718,   729,
     730,   732,   796,   734,   733,   735,   737,   736,   303,   432,
     738,   740,   741,   743,   758,   761,   773,   781,  1446,   778,
     454,   455,   780,   149,   303,   303,   303,  -581,   821,  1634,
     825,  1317,   787,   827,   843,   848,   855,   856,   857,   888,
     898,   462,   899,   900,   901,   910,   462,   462,   462,   614,
     920,   922,   923,   958,   959,   462,   962,   973,  1501,  1503,
    1002,   972,   975,  1004,  1030,  1005,  1008,  1017,  1019,  1033,
    1078,  1062,  1064,  1823,  1072,  1082,  1083,  1088,  1092,  1087,
    1104,   303,   468,  1103,  1120,  1122,  1109,  1125,  1133,  1135,
    1138,  1143,   462,  1139,  1084,  1144,  1145,  1147,  1148,  1149,
     303,  1151,   303,   303,  1152,  1153,  1154,  1155,  1156,   462,
    1157,  1158,   303,  1159,  1160,  1163,  1169,   476,  1196,  1197,
    1231,   476,  1205,  1225,  1206,  1215,  1235,  1207,  1219,  1247,
     476,  1239,   476,  1255,  1257,   476,  1248,  1249,  1281,  1303,
    1269,  1661,  1277,  1666,  1278,  1304,  1306,  1327,  1323,  1325,
     563,   303,  1326,  1340,  1338,  1339,  1343,  1351,  1353,  1354,
    1360,  1364,  2114,  1368,   387,  1369,   573,   574,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,  1367,  1370,  1373,   476,
     614,  1374,  1375,  1379,   303,  1392,   303,  1416,  1965,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,   303,  1394,  1811,  1395,   614,  1410,
    1813,  1417,  1418,  1427,  1419,  1449,   303,  1424,  1432,  1453,
     303,  1431,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
    1465,  1485,  1832,  1832,   614,  1234,  1511,  -209,  1494,  1512,
    1821,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,  1513,
    1516,  1517,  1971,   614,  1518,  1519,  1520,  1521,   303,   303,
     303,  1523,  1254,  1524,  1534,  1535,   303,   303,   303,  1538,
    1539,  1540,  1806,  1549,  1550,  1562,  1551,  1552,  1553,  1554,
    1555,  1556,  1557,  1561,  1563,   303,  1564,  1565,  1566,  1567,
    1568,  1569,  1570,  1577,  1572,  1574,   303,  1589,  1595,  1588,
     462,  1597,  1596,  1610,   303,  1607,  1599,  1601,   303,  1605,
    1615,   760,  1616,  1619,  1621,  1626,  1620,  1632,  1646,   303,
    1630,   303,  1628,  1652,  1629,  1653,  1657,  1672,  1674,  1680,
    1644,  1676,  1681,   794,  1682,  1861,  1687,  1650,  1688,  1689,
    1670,  1690,  1891,  1671,  1691,  1692,  1693,  1694,   794,  1695,
    1696,  1698,  1720,  1709,  1716,  1729,  1735,  1736,  1742,  1743,
    1744,  1745,  1753,   387,  1746,  1750,  1751,  1752,  1758,  1759,
    1765,   483,   483,  1773,  1774,  1782,  1766,   303,  1784,  1767,
    1768,  1785,  1769,  1376,  1770,  1776,  1777,  1789,  1793,  1803,
    1810,  1815,  1761,  1796,  1358,   476,  1817,  1818,  1814,  1396,
    1834,  1842,  1839,  1844,  1846,  1850,   303,  1851,  1853,  1854,
    1857,   303,  1877,  1862,  1868,  1870,  1871,  1872,  1878,   462,
    1873,   462,  1907,   462,   462,   462,  1974,  1879,  1880,  1881,
    1886,  1227,  1892,  1894,  1893,  1896,  1899,  1900,  1921,   462,
     462,  1922,  1917,  1931,  1937,  1938,  1939,  1447,  1448,  1957,
    1450,  1451,  1452,  1958,  1454,  1455,  1456,  1457,  1458,  1459,
    1460,  1461,  1462,  1463,  1464,  1959,  1969,  1948,  1970,  1975,
     809,  -587,  -585,  1987,  1953,  1956,  1988,  1989,  1990,  1994,
    1998,  2003,  2004,  2005,   303,  2009,  2006,  2007,  2008,   303,
     303,  2015,  2020,  2138,  2021,  1967,  2024,  2029,  2030,   468,
     468,  2032,  2033,  2036,  2039,  2038,  2048,  2056,  1478,  2063,
    2064,  2057,   303,  2066,  2051,  2067,  2065,  2068,   303,  2071,
    2070,  1869,   794,   303,  2073,  2074,  2079,  2097,  2117,  2118,
    2122,  2129,   303,  2135,  1495,  2137,  2145,  2134,  2148,  2165,
     476,  2139,  2136,   476,  2168,  2172,   794,  -586,  2173,  2184,
    1508,  2185,  2187,  2153,  2149,  2150,  2199,  2204,  2159,  2157,
    1522,   303,  2160,  2162,  2166,  1389,  2170,  2209,  2250,  2251,
    2252,  2253,   387,  2176,   303,   483,   462,   462,   462,   462,
     462,   462,   462,   462,   462,  2195,   462,   462,   462,   462,
    2188,  2255,   462,   462,   462,  2223,  2256,  2257,  2261,  2272,
    2239,  2275,   794,  2282,  2287,   794,  2288,  1559,  2291,  2292,
     483,  1924,  1925,  1926,  1927,  1928,  1930,  2258,   794,  2271,
    1648,  2278,  2217,   820,  2120,  1712,  1573,   303,  1575,  1576,
    1867,  2088,  1895,  1678,   127,  2061,  2060,  1409,   138,   303,
     303,   139,   140,   961,  2112,  1805,   146,  1966,  1954,  1833,
       0,     0,     0,  1106,     0,  1108,  1127,     0,     0,     0,
       0,     0,     0,     0,   303,     0,     0,     0,     0,     0,
       0,     0,   462,     0,   464,     0,   303,  1606,  2092,   474,
     477,   478,     0,   462,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   303,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,  2186,     0,     0,     0,   510,     0,     0,     0,     0,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1665,     0,   525,     0,     0,   303,     0,     0,     0,     0,
    2093,     0,  1679,   303,   303,     0,  1683,  1560,     0,     0,
       0,  2208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   303,     0,     0,   303,     0,     0,     0,     0,   468,
       0,     0,     0,     0,     0,   303,     0,     0,     0,   303,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,  1604,   614,   387,  1732,  1733,  1734,     0,     0,     0,
       0,     0,  1739,  1740,  1741,     0,   303,     0,  2194,     0,
       0,     0,     0,     0,     0,     0,     0,   794,     0,   794,
     794,  1756,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1764,   794,     0,   303,     0,     0,     0,     0,
    1772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   794,     0,  1781,     0,  1783,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2124,  2125,
    2126,  2127,  2128,     0,     0,   794,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   303,   303,   303,   303,   303,
       0,     0,   794,  1838,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,  2163,     0,   614,     0,  2167,     0,     0,     0,
       0,     0,  1860,   752,     0,     0,     0,     0,   303,     0,
       0,     0,     0,     0,     0,     0,     0,   462,     0,     0,
       0,     0,     0,     0,   303,     0,     0,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,   476,     0,  2200,     0,   614,
       0,  2202,     0,     0,     0,     0,     0,     0,   303,     0,
       0,     0,     0,     0,   476,   476,     0,  2214,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   476,     0,     0,
    1898,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,  1838,   462,
     462,     0,  2247,  2248,     0,     0,     0,     0,     0,     0,
       0,     0,   891,     0,   893,     0,   895,   896,  1940,     0,
       0,   172,   395,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   911,   912,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1973,     0,     0,     0,   794,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   404,     0,     0,     0,     0,   405,
     406,   407,   408,  1622,     0,     0,     0,   409,   410,   411,
     412,     0,     0,     0,     0,     0,   413,     0,   414,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   415,  1838,  1754,   416,     0,     0,     0,   178,
       0,     0,   179,     0,     0,   180,     0,   181,     0,     0,
       0,     0,     0,   462,     0,     0,     0,   462,    46,     0,
       0,     0,     0,     0,     0,     0,   462,     0,   462,     0,
    2037,   462,     0,     0,     0,     0,     0,   448,     0,     0,
       0,  1600,     0,     0,     0,     0,     0,     0,     0,     0,
    1039,     0,  1041,  1042,  1043,  1044,  1045,  1046,     0,  1048,
    1049,  1050,  1051,     0,     0,  1056,  1057,  1058,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   462,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2080,   435,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   417,   418,
     419,  2089,     0,     0,     0,     0,     0,     0,     0,     0,
     420,     0,     0,     0,   421,   463,   422,   121,     0,   473,
       0,     0,     0,     0,   479,     0,     0,  1838,     0,     0,
       0,   484,     0,     0,   486,  1126,     0,     0,     0,     0,
       0,  2119,     0,     0,     0,  1812,  1136,   774,     0,   775,
    1828,   495,   496,   497,     0,   499,   500,   501,     0,   503,
     504,   505,   506,   507,   508,   509,     0,   511,   512,   513,
     514,     0,     0,     0,     0,   518,   518,     0,     0,     0,
       0,     0,  1838,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,     0,
       0,  2164,     0,     0,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   582,   584,   586,   587,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   621,   518,   518,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   462,   462,   639,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   649,
     650,     0,     0,     0,     0,   650,     0,     0,     0,     0,
       0,   462,     0,     0,     0,   518,   672,     0,     0,     0,
       0,     0,     0,     0,  1838,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   691,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   701,     0,   703,
     704,     0,   706,     0,     0,     0,   709,   710,   711,     0,
       0,   712,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1838,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,   745,     0,     0,     0,     0,   518,   754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   762,   763,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   795,     0,
    1422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   462,     0,     0,   462,
     826,     0,     0,     0,     0,   831,     0,     0,     0,   835,
       0,     0,     0,     0,   794,     0,   794,     0,     0,     0,
       0,     0,     0,   849,   584,     0,     0,     0,     0,   854,
       0,   462,     0,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   872,   873,   874,
     876,   877,   878,   879,   880,   881,   882,   883,   884,   884,
       0,   889,   890,     0,   892,     0,   462,     0,     0,     0,
       0,     0,  1479,  1480,   902,     0,     0,   906,   907,     0,
       0,     0,     0,     0,     0,   884,     0,     0,     0,     0,
     518,     0,     0,   520,   521,     0,     0,     0,     0,     0,
       0,     0,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,   934,   935,   936,   937,   939,   941,   942,   943,
     944,   945,     0,   947,   948,     0,     0,     0,     0,     0,
    1816,   955,   956,   957,     0,     0,     0,     0,     0,   963,
     964,   965,   966,     0,   518,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,   745,   986,     0,     0,     0,   991,
     992,   993,   994,   995,   996,   997,   998,   999,     0,     0,
       0,     0,     0,  1006,  1007,     0,  1009,     0,     0,  1011,
     622,   623,     0,   518,   518,   518,  1016,  1822,     0,     0,
    1020,   518,  1022,  1023,  1024,     0,  1585,  1025,     0,  1027,
    1587,     0,     0,     0,     0,     0,     0,     0,     0,  1591,
       0,  1592,     0,     0,  1594,     0,     0,     0,     0,  1047,
       0,     0,     0,   671,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   518,     0,     0,     0,     0,     0,     0,
    1066,  1067,     0,  1068,     0,     0,   947,   948,     0,     0,
       0,     0,     0,     0,     0,  1081,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1635,     0,
       0,     0,     0,   518,     0,  1097,     0,     0,     0,     0,
    1100,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   518,     0,  1117,  1118,     0,
       0,   518,     0,   518,  1124,     0,     0,     0,  1117,     0,
    1131,     0,  1132,   794,   753,     0,     0,     0,  1137,     0,
       0,     0,  1140,     0,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,  1161,   614,   939,   828,  1164,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,     0,   794,
       0,     0,  1935,     0,     0,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   518,  1210,  1211,  1212,     0,
       0,   794,     0,     0,     0,     0,     0,  1218,     0,     0,
       0,     0,     0,   519,   519,     0,     0,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,   518,     0,     0,     0,   614,
       0,     0,     0,     0,     0,     0,     0,   518,     0,     0,
       0,   462,     0,     0,     0,  1253,     0,     0,   917,  1259,
       0,     0,     0,     0,     0,  1265,     0,     0,   518,     0,
     462,   462,     0,     0,     0,     0,  1275,  1276,     0,     0,
       0,     0,  1279,   462,     0,     0,     0,     0,     0,     0,
       0,   585,     0,     0,   519,     0,     0,     0,     0,  1305,
       0,     0,  1307,     0,  1852,     0,     0,     0,     0,     0,
     519,   519,   969,   970,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1328,     0,
    1330,  1331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1349,
       0,     0,     0,   519,     0,     0,     0,     0,     0,  1936,
       0,  1013,  1014,  1015,     0,     0,     0,     0,     0,  1021,
       0,     0,     0,  1372,     0,   519,     0,     0,     0,     0,
    1378,     0,     0,     0,     0,     0,     0,  1391,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1414,  1415,     0,     0,     0,     0,   518,     0,     0,     0,
       0,  1061,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,  1444,     0,
       0,     0,     0,     0,   519,     0,     0,     0,     0,  1949,
       0,  1093,  1951,     0,     0,     0,     0,     0,     0,     0,
     518,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1115,     0,     0,     0,     0,  1468,  1121,
       0,  1123,     0,     0,     0,     0,     0,     0,  1469,  1470,
    1471,  1472,  1473,     0,     0,     0,     0,  1475,  1476,     0,
    1477,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2028,     0,     0,     0,  1488,  1489,     0,     0,
       0,     0,   585,     0,  1492,  1493,     0,     0,     0,     0,
       0,     0,     0,  1497,  1498,     0,     0,     0,     0,  1504,
    1505,     0,     0,     0,     0,   518,   518,   875,     0,     0,
       0,     0,     0,     0,     0,  2055,   885,   886,     0,     0,
       0,     0,     0,  1199,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1209,     0,     0,     0,     0,     0,     0,
    1537,     0,     0,   913,     0,     0,     0,     0,   519,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1238,   940,     0,     0,     0,  1571,     0,
       0,     0,     0,     0,     0,  1246,     0,     0,     0,     0,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
    1586,     0,   519,   519,     0,     0,  1268,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1504,  1505,     0,     0,     0,  1603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1609,     0,
       0,  1614,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   519,   519,   519,     0,     0,     0,     0,     0,   519,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1636,     0,     0,  1639,   518,  1642,   518,     0,     0,     0,
       0,     0,     0,     0,  1651,     0,     0,  1654,     0,  1651,
       0,  1658,  1660,     0,     0,  1668,  1669,     0,     0,     0,
       0,   519,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   519,     0,     0,  1421,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,   519,     0,     0,     0,   614,     0,   519,
       0,   519,     0,     0,     0,  1738,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1747,  1748,  1749,     0,
       0,     0,     0,     0,     0,  1755,     0,  1757,  1466,     0,
       0,     0,     0,     0,  1760,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   940,     0,  1165,   518,     0,
       0,     0,     0,     0,  1778,  1779,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1786,  1787,  1788,     0,     0,
       0,     0,     0,     0,     0,  1797,     0,     0,     7,     8,
       0,     0,     0,   519,     0,     0,  1809,     0,     0,     0,
       0,     0,     0,   519,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2269,     0,     0,  1826,     0,     0,
       0,     0,     0,  1509,  1510,  1835,  1836,     0,     0,     0,
       0,     0,     0,  2283,  2285,     0,     0,     0,     0,  2069,
       0,     0,     0,   519,     0,     0,  2293,     0,     0,     0,
       0,     0,     0,     0,   777,   519,     0,     0,     0,     0,
       0,  1865,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   519,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,  1882,  1883,  1884,     0,     0,   788,    57,
    1584,     0,    60,   789,  1885,   790,   791,     0,   792,  1888,
    1889,     0,     0,     0,     0,     0,     0,  2103,     0,     0,
       0,     0,  1897,     0,     0,     0,    81,     0,     0,   518,
     518,  1905,     0,  1906,     0,     0,     0,     0,     0,  1914,
    1915,  2002,   595,     0,     0,     0,     0,     0,     0,     0,
       0,   903,    97,    98,    99,     0,     0,     0,   518,     0,
       0,     0,     0,   518,  1934,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1947,     0,
       0,  1950,  1641,     0,  1643,  1952,     0,     0,     0,     0,
       0,     0,     0,     0,  1888,  1889,     0,  1961,     0,     0,
       0,     0,     0,   951,   519,     0,     0,  1968,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1979,     0,     0,     0,     0,  1985,  1986,     0,   814,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1991,     0,     0,  1992,  1991,     0,  1995,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   519,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,   518,
     518,   614,     0,     0,     0,     0,  2022,  2023,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2031,     0,
       0,     0,     0,     0,     0,     0,     0,  2040,     0,     0,
       0,     0,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1775,     0,     0,  2052,
    2053,     0,     0,   518,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   519,     0,     0,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,  2077,  2078,   614,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   850,   610,   611,   612,   613,  2091,     0,
       0,     0,   614,   518,   518,  2096,     0,     0,     0,     0,
    2099,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   518,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   518,
     519,     0,     0,     0,     0,     0,     0,     0,  2130,     0,
       0,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,
    1179,  1180,     0,  1182,  1183,  1184,  1185,     0,  1187,  1188,
    1189,  1190,     0,  2141,     0,     0,     0,     0,     0,  2146,
       0,     0,  2147,     0,  1202,   177,  1204,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1214,     0,     0,
       0,     0,     0,     0,     0,  1221,  1222,     0,  2104,     0,
       0,     0,     0,  2171,  1233,     0,     0,  1903,  1904,     0,
       0,     0,   519,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2189,
    2190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1933,     0,  2183,  2196,  2197,     0,   518,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2206,     0,     0,     0,     0,   518,   518,   518,   518,   518,
       0,     0,     0,     0,     0,  1985,     0,     0,  2229,  2222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,  2242,     0,     0,     0,
       0,  2245,  2246,     0,     0,     0,     0,     0,     0,     0,
       0,  1334,  1336,  1337,   518,     0,     0,  1341,  1342,     0,
       0,  1345,  1346,  1347,  1348,     0,  1350,     0,     0,     0,
       0,  1356,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2273,  2274,     0,     0,     0,   519,  2018,  2019,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   553,   554,   555,   556,
     557,   558,     0,   560,   561,     0,     0,     0,     0,     0,
       0,  2054,     0,   567,   568,     0,     0,     0,     0,     0,
       0,     0,     0,  1443,     0,  1445,   577,   578,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,     0,     0,     0,  1866,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2094,  2095,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,  2113,     0,     0,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2123,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,  1506,     0,
     614,     0,     0,     0,     0,     0,     0,   519,   519,     0,
       0,     0,     0,     0,     0,   713,   714,   715,     0,     0,
       0,   719,   720,   721,   722,   723,   724,   725,     0,   726,
       0,     0,     0,     0,   727,   728,   519,     0,   731,     0,
       0,   519,     0,     0,     0,     0,   217,   172,     0,     0,
       0,     0,   744,   218,   219,   220,     0,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   433,   239,   240,   241,   242,
     243,   244,   245,   246,  2152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2198,     0,     0,     0,     0,
       0,   252,   253,   254,   255,     0,     0,     0,     0,   256,
       0,     0,     0,  2210,  2211,  2212,  2213,  2215,   595,     0,
       0,     0,     0,     0,     0,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,   264,    25,     0,   265,
       0,     0,     0,     0,     0,     0,  1623,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   519,   519,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1662,
       0,     0,     0,     0,   585,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     921,   519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1699,  1700,  1701,  1702,  1703,  1704,  1705,     0,     0,
       0,     0,  1710,  1711,     0,     0,     0,     0,     0,  1713,
       0,     0,  1715,     0,     0,     0,  1719,     0,     0,  1721,
       0,     0,     0,   276,     0,     0,     0,   277,     0,     0,
    1728,     0,     0,   279,   280,   281,     0,   282,   283,   284,
       0,   519,   519,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   434,   519,     0,     0,     0,     0,   287,     0,     0,
       0,     0,   369,     0,     0,     0,   638,   519,     0,   290,
       0,   595,     0,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,  1792,     0,  1795,
       0,     0,     0,  1802,     0,  1804,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,   217,   172,     0,     0,     0,     0,  1829,   218,   219,
     220,     0,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     433,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1034,   172,   395,     0,     0,   519,   252,   253,   254,   255,
       0,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   519,   519,   519,   519,     0,     0,
     261,   262,   263,     0,     0,  1236,     0,     0,     0,     0,
       0,   264,    25,     0,   265,     0,   396,   397,   398,   399,
     400,   401,   402,   403,   404,     0,     0,  1890,     0,   405,
     406,   407,   408,     0,     0,     0,     0,   409,   410,   411,
     412,     0,     0,     0,     0,     0,   413,     0,   414,     0,
       0,     0,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   415,     0,     0,   416,     0,     0,     0,   178,
       0,     0,   179,     0,     0,   180,     0,   181,     0,     0,
       0,     0,     0,     0,     0,  1228,     0,     0,    46,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   850,   610,   611,   612,   613,   448,     0,     0,
       0,   614,     0,     0,     0,     0,     0,     0,  1245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
       0,     0,   277,  1976,     0,     0,  1977,     0,   279,   280,
     281,     0,   282,   283,   284,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   656,   657,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,   658,   417,   418,
     419,   333,     0,     0,   290,  2011,  2012,     0,  2014,     0,
     420,     0,     0,     0,   421,  1237,   422,   121,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1828,     0,     0,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,  2058,  2059,   614,     0,     0,   217,     6,
     395,     0,     0,     0,     0,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,  1579,  2090,  1436,  1663,   397,   398,   399,   400,   401,
     402,   403,   404,   252,   253,   254,   255,   405,   406,   407,
     408,   256,   257,     0,     0,   409,   410,   411,   412,     0,
       0,   258,   259,   260,   413,     0,   414,   261,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   264,    25,
     415,   265,     0,   416,     0,     0,     0,   266,     0,     0,
     267,     0,     0,   268,     0,   269,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
      58,    59,     0,   272,     0,   273,     0,     0,   274,     0,
       0,  1496,     0,     0,    69,    70,    71,    72,    73,     0,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    84,
       0,     0,    87,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,   417,   418,   419,   277,
     278,     0,     0,     0,     0,   279,   280,   281,   420,   282,
     283,   284,   421,     0,   422,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,   369,     0,     0,     0,  1664,     0,
       0,   290,     0,     0,     0,     0,     0,     0,     0,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,  2263,
       0,   614,     0,     0,     0,     0,     0,     0,     0,   217,
       6,   395,     0,  1624,  1625,     0,   218,   219,   220,     0,
       0,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     0,     0,     0,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   252,   253,   254,   255,   405,   406,
     407,   408,   256,   257,     0,     0,   409,   410,   411,   412,
       0,     0,   258,   259,   260,   413,     0,   414,   261,   262,
     263,     0,     0,     0,     0,     0,     0,     0,     0,   264,
      25,   415,   265,     0,   416,     0,     0,     0,   266,     0,
    1717,   267,     0,     0,   268,     0,   269,     0,     0,  1724,
       0,     0,     0,    42,     0,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,    58,    59,     0,   272,     0,   273,     0,     0,   274,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      84,     0,     0,    87,     0,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,   275,   774,
       0,   775,     0,     0,     0,     0,     0,  1794,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   417,   418,   419,
     277,   278,     0,     0,     0,     0,   279,   280,   281,   420,
     282,   283,   284,   421,     0,   422,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   285,   286,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,   369,     0,     0,     0,   289,
       0,     0,   290,     0,     0,     0,   217,   172,   395,     0,
     447,     0,  1863,   218,   219,   220,     0,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   433,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   252,   253,   254,   255,   405,   406,   407,   408,   256,
       0,     0,     0,   409,   410,   411,   412,     0,     0,     0,
       0,     0,   413,     0,   414,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,   264,    25,   415,   265,
       0,   416,     0,     0,     0,   178,     0,     0,   179,     0,
       0,   180,     0,   181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,   172,   395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   448,     0,     0,     0,     0,     0,     0,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   807,     0,     0,     0,   405,   406,   407,   408,
       0,     0,     0,     0,   409,   410,   411,   412,     0,     0,
       0,     0,     0,   413,     0,   414,   449,     0,     0,     0,
       0,     0,     0,   276,   417,   418,   419,   277,     0,   415,
       0,     0,   416,   279,   280,   281,   420,   282,   283,   284,
     421,     0,   422,   121,     0,   450,   451,   452,   453,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   434,     0,     0,     0,     0,     0,   287,     0,   454,
     455,     0,   456,     0,   457,   217,     6,   368,   458,   290,
       0,     0,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,   255,     0,     0,     0,     0,   256,   257,
       0,     0,     0,     0,     0,   417,   418,   419,   258,   259,
     260,     0,     0,     0,   261,   262,   263,   420,     0,     0,
       0,   421,     0,   422,   121,   264,    25,     0,   265,     0,
       0,     0,     0,     0,   266,     0,     0,   267,     0,     0,
     268,     0,   269,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,    58,    59,     0,
     272,     0,   273,     0,     0,   274,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    84,     0,     0,    87,
       0,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,   275,  1018,     0,     0,     0,     0,
       0,     0,     0,   979,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,     0,     0,   277,   278,     0,     0,
       0,     0,   279,   280,   281,     0,   282,   283,   284,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
     286,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,   369,   217,     6,     0,   370,     0,   692,   290,   218,
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
       0,     0,     0,    84,     0,     0,    87,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,   275,     0,     0,     0,  1858,     0,     0,     0,  1859,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,     0,   277,   278,     0,     0,     0,     0,   279,
     280,   281,     0,   282,   283,   284,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   517,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,   369,   217,
       6,  1763,     0,   588,     0,   290,   218,   219,   220,     0,
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
      84,     0,     0,    87,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   275,     0,
       0,     0,  1910,     0,     0,     0,  1911,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,     0,     0,
     277,   278,     0,     0,     0,     0,   279,   280,   281,     0,
     282,   283,   284,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   285,   286,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,   369,   217,     6,     0,   289,
       0,     0,   290,   218,   219,   220,     0,     0,   221,   222,
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
      87,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,   275,     0,     0,     0,  1941,
       0,     0,     0,  1942,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,     0,     0,   277,   278,     0,
       0,     0,     0,   279,   280,   281,     0,   282,   283,   284,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     656,  1929,     0,     0,     0,     0,     0,   287,     0,     0,
       0,     0,   658,   217,     6,     0,   333,   588,     0,   290,
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
      80,     0,     0,     0,    84,     0,     0,    87,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,   275,     0,     0,     0,  2115,     0,     0,     0,
    2116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,   277,   278,     0,     0,     0,     0,
     279,   280,   281,     0,   282,   283,   284,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,   288,
     217,     6,     0,   289,     0,     0,   290,   218,   219,   220,
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
       0,    84,     0,     0,    87,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,   275,
       0,     0,     0,     0,     0,     0,     0,   813,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,     0,
       0,   277,   278,     0,     0,     0,     0,   279,   280,   281,
       0,   282,   283,   284,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,   369,   217,     6,     0,
     289,     0,     0,   290,   218,   219,   220,     0,     0,   221,
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
       0,    87,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,   275,     0,     0,     0,
       0,     0,     0,     0,   815,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,     0,     0,   277,   278,
       0,     0,     0,     0,   279,   280,   281,     0,   282,   283,
     284,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   517,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,   369,   217,     6,     0,   583,     0,     0,
     290,   218,   219,   220,     0,     0,   221,   222,   223,   224,
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
      79,    80,     0,     0,     0,    84,     0,     0,    87,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   275,     0,     0,     0,     0,     0,     0,
       0,   979,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,   277,   278,     0,     0,     0,
       0,   279,   280,   281,     0,   282,   283,   284,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,   517,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
     369,   217,     6,     0,     0,   588,     0,   290,   218,   219,
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
       0,     0,    84,     0,     0,    87,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
     275,     0,     0,     0,     0,     0,     0,     0,   980,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,     0,
       0,     0,   277,   278,     0,     0,     0,     0,   279,   280,
     281,     0,   282,   283,   284,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,   626,   217,     6,
       0,   289,     0,     0,   290,   218,   219,   220,     0,     0,
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
       0,     0,    87,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,   275,     0,     0,
       0,     0,     0,     0,     0,  1031,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,   277,
     278,     0,     0,     0,     0,   279,   280,   281,     0,   282,
     283,   284,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,   635,   217,     6,     0,   289,     0,
       0,   290,   218,   219,   220,     0,     0,   221,   222,   223,
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
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,   275,     0,     0,     0,     0,     0,
       0,     0,  1141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,     0,     0,     0,   277,   278,     0,     0,
       0,     0,   279,   280,   281,     0,   282,   283,   284,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
     517,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,   369,   217,     6,     0,   938,     0,  1420,   290,   218,
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
       0,     0,     0,    84,     0,     0,    87,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,   275,     0,     0,     0,     0,     0,     0,     0,  1181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
       0,     0,     0,   277,   278,     0,     0,     0,     0,   279,
     280,   281,     0,   282,   283,   284,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   517,     0,     0,
       0,     0,     0,   287,   217,     6,     0,     0,   369,  1640,
       0,   218,   219,   220,     0,   290,   221,   222,   223,   224,
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
      79,    80,     0,     0,     0,    84,     0,     0,    87,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   275,     0,     0,     0,     0,     0,     0,
       0,  1191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,   277,   278,     0,     0,     0,
       0,   279,   280,   281,     0,   282,   283,   284,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,   517,
       0,     0,     0,     0,     0,   287,   217,     6,     0,     0,
     369,     0,     0,   218,   219,   220,     0,   290,   221,   222,
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
      87,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,   275,     0,     0,     0,     0,
       0,     0,     0,  1192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   276,     0,     0,     0,   277,   278,     0,
       0,     0,     0,   279,   280,   281,     0,   282,   283,   284,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,     0,   287,     0,     0,
       0,     0,   369,   217,     6,     0,  1771,     0,     0,   290,
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
      80,     0,     0,     0,    84,     0,     0,    87,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,   275,     0,     0,     0,     0,     0,     0,     0,
    1193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,   277,   278,     0,     0,     0,     0,
     279,   280,   281,     0,   282,   283,   284,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   656,  1929,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,   658,
     217,     6,     0,   333,     0,     0,   290,   218,   219,   220,
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
       0,    84,     0,     0,    87,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,   275,
       0,     0,     0,     0,     0,     0,     0,  1194,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,     0,     0,
       0,   277,   278,     0,     0,     0,     0,   279,   280,   281,
       0,   282,   283,   284,     0,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   517,     0,     0,     0,     0,
       0,   287,   217,   172,   395,     0,   369,     0,     0,   218,
     219,   220,     0,   290,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   433,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,     0,     0,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   252,   253,   254,
     255,   405,   406,   407,   408,   256,     0,     0,     0,   409,
     410,   411,   412,     0,     0,     0,     0,     0,   413,     0,
     414,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,   264,    25,   415,   265,     0,   416,   217,   172,
     395,     0,     0,     0,     0,   218,   219,   220,     0,     0,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   433,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   252,   253,   254,   255,   405,   406,   407,
     408,   256,     0,     0,     0,   409,   410,   411,   412,     0,
       0,     0,     0,     0,   413,     0,   414,   261,   262,   263,
       0,     0,     0,     0,     0,     0,     0,     0,   264,    25,
     415,   265,     0,   416,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     417,   418,   419,   277,     0,     0,     0,     0,     0,   279,
     280,   281,   420,   282,   283,   284,   421,     0,   422,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   434,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,   369,     0,
       0,     0,  1659,     0,     0,   290,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1195,     0,
       0,     0,     0,     0,     0,   276,   417,   418,   419,   277,
       0,     0,     0,     0,     0,   279,   280,   281,   420,   282,
     283,   284,   421,     0,   422,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   434,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,   369,   217,   172,   395,  1946,     0,
       0,   290,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   433,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
       0,  1663,   397,   398,   399,   400,   401,   402,   403,   404,
     252,   253,   254,   255,   405,   406,   407,   408,   256,     0,
       0,     0,   409,   410,   411,   412,     0,     0,     0,     0,
       0,   413,     0,   414,   261,   262,   263,     0,     0,     0,
       0,     0,     0,     0,     0,   264,    25,   415,   265,     0,
     416,   217,   172,   395,     0,     0,     0,     0,   218,   219,
     220,     0,     0,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     433,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,     0,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   252,   253,   254,   255,
     405,   406,   407,   408,   256,     0,     0,     0,   409,   410,
     411,   412,     0,     0,     0,     0,     0,   413,     0,   414,
     261,   262,   263,     0,     0,     0,     0,     0,     0,     0,
       0,   264,    25,   415,   265,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   417,   418,   419,   277,     0,     0,     0,
       0,     0,   279,   280,   281,   420,   282,   283,   284,   421,
       0,   422,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
     434,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,   369,     0,     0,     0,  1828,     0,     0,   290,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1200,     0,     0,     0,     0,     0,     0,   276,   417,
     418,   419,   277,     0,     0,     0,     0,     0,   279,   280,
     281,   420,   282,   283,   284,   421,     0,   422,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   434,     0,     0,     0,
       0,     0,   287,   217,   172,     0,     0,   369,   905,     0,
     218,   219,   220,     0,   290,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   433,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   253,
     254,   255,     0,     0,     0,     0,   256,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   262,   263,     0,     0,     0,     0,     0,
     217,   172,     0,   264,    25,     0,   265,   218,   219,   220,
       0,     0,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   433,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   252,   253,   254,   255,     0,
       0,     0,     0,   256,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   261,
     262,   263,    43,    44,    45,    46,     0,     0,    48,     0,
     264,    25,     0,   265,     0,     0,     0,   788,    57,     0,
       0,    60,   789,     0,   790,   791,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     276,     0,     0,     0,   277,    81,     0,     0,     0,     0,
     279,   280,   281,     0,   282,   283,   284,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,     0,     0,     0,   285,   434,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,   369,
       0,     0,     0,     0,     0,     0,   290,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,     0,     0,   276,     0,  1201,
       0,   277,     0,     0,     0,     0,     0,   279,   280,   281,
       0,   282,   283,   284,     0,     0,     0,   121,   987,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   434,     0,     0,     0,     0,
       0,   287,   217,   172,     0,  1371,   369,  1129,     0,   218,
     219,   220,     0,   290,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   433,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   254,
     255,     0,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,   264,    25,     0,   265,   217,   172,     0,  1536,
       0,     0,     0,   218,   219,   220,     0,     0,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   433,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   252,   253,   254,   255,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   261,   262,   263,     0,     0,
       0,     0,     0,     0,     0,     0,   264,    25,     0,   265,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,   276,
       0,     0,   614,   277,     0,     0,     0,     0,     0,   279,
     280,   281,  1203,   282,   283,   284,     0,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   434,     0,     0,
       0,     0,     0,   287,     0,     0,     0,     0,   369,     0,
       0,     0,     0,     0,     0,   290,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1321,     0,
       0,     0,     0,   276,     0,     0,     0,   277,     0,     0,
       0,     0,     0,   279,   280,   281,     0,   282,   283,   284,
       0,     0,     0,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   434,     0,     0,     0,     0,     0,   287,   217,   172,
       0,  1602,   369,     0,     0,   218,   219,   220,     0,   290,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   433,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,   255,     0,     0,     0,
       0,   256,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   262,   263,
       0,     0,     0,     0,     0,   217,   172,     0,   264,    25,
       0,   265,   218,   219,   220,     0,     0,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   433,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,   255,     0,     0,     0,     0,   256,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   261,   262,   263,    43,    44,    45,
      46,     0,     0,    48,     0,   264,    25,     0,   265,     0,
       0,     0,   788,    57,     0,     0,    60,   789,     0,   790,
     791,     0,   792,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   276,     0,     0,     0,   277,
      81,     0,     0,     0,     0,   279,   280,   281,     0,   282,
     283,   284,     0,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,    98,    99,     0,
       0,     0,   285,   434,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,   369,     0,     0,     0,     0,     0,
       0,   290,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,     0,     0,
       0,     0,   276,     0,  1344,     0,   277,     0,     0,     0,
       0,     0,   279,   280,   281,     0,   282,   283,   284,     0,
       0,     0,   121,  1012,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   285,
     434,     0,     0,     0,     0,     0,   287,   217,   172,     0,
       0,   369,  1656,     0,   218,   219,   220,     0,   290,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   433,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,   254,   255,     0,     0,     0,     0,
     256,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   261,   262,   263,     0,
       0,     0,     0,     0,   217,   172,     0,   264,    25,     0,
     265,   218,   219,   220,     0,     0,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   433,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
     253,   254,   255,     0,     0,     0,     0,   256,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   261,   262,   263,    43,    44,    45,    46,
       0,     0,    48,     0,   264,    25,     0,   265,     0,     0,
       0,   788,    57,     0,     0,    60,   789,     0,   790,   791,
       0,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   276,     0,     0,     0,   277,    81,
       0,     0,     0,     0,   279,   280,   281,     0,   282,   283,
     284,     0,     0,     0,   121,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    98,    99,     0,     0,
       0,   285,   434,     0,     0,     0,     0,     0,   287,     0,
       0,     0,     0,   369,  1993,     0,     0,     0,     0,     0,
     290,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     7,     8,     0,     0,     0,
       0,   276,     0,  1430,     0,   277,     0,     0,     0,     0,
       0,   279,   280,   281,     0,   282,   283,   284,     0,     0,
       0,   121,  1063,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,   285,   434,
      43,    44,    45,    46,     0,   287,    48,     0,     0,     0,
     369,     0,     0,     0,     0,   788,    57,   290,     0,    60,
     789,     0,   790,   791,     0,   792,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,    97,
      98,    99,     0,     0,     0,   788,    57,     0,     0,    60,
     789,     0,   790,   791,     0,   792,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    97,
      98,    99,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,  1065,   788,    57,     7,
       8,    60,   789,     0,   790,   791,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,    97,    98,    99,     0,     0,  1270,   788,    57,     7,
       8,    60,   789,     0,   790,   791,     0,   792,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,    97,    98,    99,     0,     0,     0,     0,     0,   788,
      57,     7,     8,    60,   789,     0,   790,   791,  1272,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,    97,    98,    99,     0,     0,     0,   788,
      57,     7,     8,    60,   789,     0,   790,   791,  1273,   792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,    97,    98,    99,     0,     0,     0,     0,
       0,   788,    57,     7,     8,    60,   789,     0,   790,   791,
    1292,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,    97,    98,    99,     0,     0,
       0,   788,    57,     7,     8,    60,   789,     0,   790,   791,
    1311,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,    97,    98,    99,     0,     0,
       0,     0,     0,   788,    57,     7,     8,    60,   789,     0,
     790,   791,  1329,   792,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,    97,    98,    99,
       0,     0,     0,   788,    57,     0,     0,    60,   789,     0,
     790,   791,  1363,   792,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,    97,    98,    99,
       0,     0,     0,     0,     0,   788,    57,     0,     0,    60,
     789,     0,   790,   791,  1528,   792,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,     0,     0,     0,
       0,     0,     0,    81,    -4,    -4,     0,     0,     0,     0,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,    97,
      98,    99,   614,     0,     0,     0,     0,    -4,    -4,    -4,
       0,     0,  1434,     0,  2174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
      -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,  2231,     0,    -4,    -4,
      -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     6,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,     7,     8,     0,     0,     0,     0,     0,     0,    -4,
       0,    -4,    -4,     0,     0,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     9,    10,    11,   614,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1530,     0,     0,
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
       0,     0,     0,    92,    93,    94,     0,     0,     0,    95,
       0,     0,     0,     0,    96,    97,    98,    99,   172,   395,
     100,     0,   101,     0,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,   121,   122,
       0,     0,     0,   396,   397,   398,   399,   400,   401,   402,
     403,   404,     0,     0,     0,     0,   405,   406,   407,   408,
     426,   395,     0,     0,   409,   410,   411,   412,     0,     0,
       0,     0,     0,   413,     0,   414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   415,
       0,     0,   416,     0,     0,     0,   178,     0,   395,   179,
       0,     0,   180,     0,   181,   396,   397,   398,   399,   400,
     401,   402,   403,   404,     0,    46,     0,     0,   405,   406,
     407,   408,     0,     0,     0,     0,   409,   410,   411,   412,
       0,     0,     0,     0,   448,   413,     0,   414,     0,     0,
       0,     0,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   415,     0,     0,   416,   405,   406,   407,   408,     0,
       0,     0,     0,   409,   410,   411,   412,     0,     0,     0,
       0,     0,   413,     0,   414,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   415,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   417,   418,   419,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   420,     0,     0,
       0,   421,     0,   422,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,     0,   417,   418,   419,
    1531,     0,     0,     0,     0,     0,     0,     0,     0,   420,
       0,     0,     0,   421,     0,   422,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,   417,   418,   419,     0,   614,     0,
       0,     0,     0,     0,     0,     0,   420,     0,  1578,     0,
     421,     0,   422,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     7,     8,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,   788,    57,     0,     0,    60,   789,
       0,   790,   791,     0,   792,     0,     0,     0,  1075,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,  1076,     0,     0,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,    97,    98,
      99,   614,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1706,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   788,    57,     0,     0,
      60,   789,     0,   790,   791,     0,   792,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
      97,    98,    99,     0,     0,     0,     0,  1707,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1708,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1856,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1980,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1981,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2013,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2085,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2142,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2143,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2158,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2192,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2219,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2224,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2225,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,   847,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,  1110,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,     0,     0,  1168,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,  1216,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,     0,
       0,  1217,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,     0,     0,
    1262,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,     0,  1295,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,  1309,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,     0,     0,  1316,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,  1377,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,  1397,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,  1433,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,     0,     0,  1482,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,  1483,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,     0,
       0,  1484,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,     0,     0,
    1487,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,     0,  1532,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,  1608,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,     0,     0,  1908,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,  1919,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,  1960,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,  2034,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,     0,     0,  2050,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,  2062,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,     0,
       0,  2086,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,     0,     0,
    2121,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,     0,  2131,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,     0,     0,  2132,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,     0,     0,  2156,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,     0,     0,  2205,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,  2244,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,     0,     0,  2262,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,     0,     0,  2280,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,  2281,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,     0,
     747,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,     0,   971,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,     0,  2027,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,   774,     0,   775,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
    1037,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,  1086,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,  1241,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,  1310,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,  1312,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,     0,     0,  1319,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   746,
     610,   611,   612,   613,     0,     0,     0,     0,   614,     0,
       0,     0,  1320,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   746,   610,   611,   612,
     613,     0,     0,     0,     0,   614,     0,     0,     0,  1412,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   746,   610,   611,   612,   613,     0,     0,
       0,     0,   614,     0,     0,     0,  1426,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     746,   610,   611,   612,   613,     0,     0,     0,     0,   614,
       0,     0,     0,  1637,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,     0,     0,
    1727,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   746,   610,   611,   612,   613,     0,
       0,     0,     0,   614,     0,     0,     0,  1780,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   746,   610,   611,   612,   613,     0,     0,     0,     0,
     614,     0,     0,     0,  1972,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   746,   610,
     611,   612,   613,     0,     0,     0,     0,   614,     0,     0,
       0,  2017,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   746,   610,   611,   612,   613,
       0,     0,     0,     0,   614,     0,     0,     0,  2035,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   829,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   830,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   832,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   833,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   834,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   836,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   837,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   838,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   839,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   840,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   841,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   842,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   844,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   845,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   846,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,   918,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,   952,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1001,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1018,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1026,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1028,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1029,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1035,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1036,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1074,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1085,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1146,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1150,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1162,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1240,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1250,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1251,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1252,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1261,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1263,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1264,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1294,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1296,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1297,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1298,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1299,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1300,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1301,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1302,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1308,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1322,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1324,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1362,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1411,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1425,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1638,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1673,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1714,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1726,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1843,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1845,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1848,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1855,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1909,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  1918,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  1945,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  2016,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  2083,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  2084,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614,     0,  2218,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   746,   610,   611,
     612,   613,     0,     0,     0,     0,   614,     0,  2259,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   746,   610,   611,   612,   613,     0,     0,     0,
       0,   614
};

static const yytype_int16 yycheck[] =
{
       3,   166,     3,   326,  1289,   653,   654,  1293,  1491,     4,
     162,   771,    25,    64,  1765,   148,  1811,   777,  1813,     4,
       4,  1996,    25,    95,     6,     4,     6,     5,   108,     4,
       6,     4,     4,   108,     4,     6,     4,   111,     5,   113,
       5,     5,   144,     6,     6,     4,     7,   144,     6,   105,
    1798,     4,   108,    56,   102,     6,     6,   260,   108,   458,
     162,   144,   265,     4,     4,   121,   105,     4,     9,   108,
     172,   173,   174,   121,   148,   165,   178,   179,     4,   162,
     260,   108,    85,   133,     6,     9,     9,    90,   268,   172,
     173,   174,    95,   260,     9,   178,   179,   100,   195,    36,
      37,   268,   192,   177,     7,     7,   133,    14,   111,   183,
      36,    37,     4,     9,     6,  1863,     9,   105,   208,   209,
     108,   109,   110,     0,    94,     4,   144,     9,   102,  1880,
       6,   105,   204,   121,   108,   262,   110,   256,   257,     6,
       6,   268,   214,     6,   162,   148,   265,   121,   149,   259,
     153,   154,   155,     6,   172,   173,   174,    36,    37,   162,
     178,   179,   264,   108,     6,    70,    71,     7,    73,   247,
     248,     7,   259,   338,   111,   112,  2151,   247,   248,   259,
       7,   264,   247,   248,   259,   111,   112,   260,   265,   262,
     268,   268,   357,   247,   248,   268,   199,   168,   268,   187,
     180,   204,   259,   268,   180,   208,   209,   258,   259,   260,
     102,   214,   215,   216,   268,   260,   262,     7,   259,   618,
     261,     7,   268,   268,   275,   247,   248,   268,     6,   182,
     183,   184,   185,   203,     6,   230,  1719,     6,   310,   311,
     312,   194,   264,   196,   197,   198,   199,   200,   207,   247,
     248,   204,   205,   102,   207,   230,   105,   230,   230,   108,
     230,   260,   230,  1548,   429,   259,   431,   261,   271,   268,
     268,   266,   121,  2024,   259,   259,   441,   290,   350,   351,
     352,   263,   261,   286,   263,   263,   289,   290,   267,   230,
     263,   263,   260,   263,   262,   367,   263,   259,   263,   263,
     263,   263,   305,   306,   265,   263,   309,   310,   311,   312,
     259,   264,   263,   263,   263,   256,   257,   320,   259,   259,
     261,   324,   263,   326,   265,  1085,  1086,     4,  2079,   232,
     233,   234,   235,   256,   257,   259,   259,   261,   261,   262,
     259,   265,   265,   260,   259,   348,   261,   350,   351,   352,
     265,   268,   751,   256,   257,     8,     4,   259,   259,   261,
     256,   257,   265,   259,   367,   261,   259,   370,   261,   265,
     260,   247,   248,   447,   256,   257,   263,   259,   268,   261,
     247,   248,     6,   265,   247,   248,   785,     8,     6,   242,
     243,  2186,   232,   233,   234,   235,   232,   233,   234,   235,
     242,   243,   261,   802,   260,   232,   233,   234,   235,   108,
     562,   110,   268,   812,   247,   248,   256,   257,   261,     4,
     256,   257,   247,   248,   329,   330,   263,     4,     8,   256,
     257,   260,   337,   338,   437,   268,   439,   259,   263,   268,
     443,   444,   232,   233,   234,   235,   232,   233,   234,   235,
     259,    36,    37,     4,   102,   259,   459,   261,   106,    36,
      37,   260,   263,   466,   112,   113,   267,   115,   116,   268,
    2221,   259,   149,   150,   151,   152,   259,   642,   155,   644,
     645,   123,   144,   247,   248,    36,    37,   164,   491,   137,
     167,   259,   247,   248,   259,   263,   661,   247,   248,   259,
     162,   573,   247,   248,   268,   259,   580,   247,   248,   263,
     172,   173,   174,   268,   517,   680,   178,   179,   268,  1167,
    2271,   920,   259,   268,   247,   248,   111,   112,   268,   247,
     248,  2014,   252,   253,   111,   112,   264,   264,   258,   542,
     268,   268,   707,   247,   248,   268,   247,   248,   551,   552,
     268,   247,   248,   556,   259,   558,   559,   560,   561,   562,
     111,   112,   259,   715,   268,   568,   579,   268,   581,   572,
     573,   574,   268,   576,   577,   578,   579,   259,   581,   261,
     583,   263,   747,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   260,   264,   262,   263,   258,   609,   192,   193,    56,
     264,   264,   615,   259,   268,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   259,   637,   638,   259,   258,   771,   256,
     257,   192,   193,   264,   256,   257,   263,   259,   259,   261,
     261,   263,   653,   654,   728,  1303,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   144,   247,   248,   264,   258,   108,
     260,   268,   262,   686,   687,   688,   247,   248,  1087,   247,
     248,   694,   162,   149,   150,   265,   268,   267,   260,   155,
     262,   259,   172,   173,   174,   263,   268,   268,   178,   179,
     713,   714,   715,   716,   717,   718,   719,   720,   721,   732,
     723,   724,   725,   726,   727,   259,   729,   730,   731,   732,
     733,   247,   248,   736,   247,   248,   256,   257,   247,   248,
     791,   247,   248,   247,   248,   748,   651,   652,   247,   248,
     264,   656,   268,   827,   268,   268,   259,  1517,   761,   268,
     259,   259,   268,   261,   263,     6,     7,   265,   215,   260,
     268,   262,   264,   776,   264,     6,   268,   268,   268,   782,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     6,   264,   798,   799,   258,   247,   248,
     260,   804,   262,   806,   144,   264,   809,   810,   268,   268,
     975,   263,   247,   248,   263,   818,   949,   820,   105,   263,
     110,   108,   264,   110,   271,  1224,   268,  1226,   263,   249,
     250,   251,   252,   253,   121,   260,   105,   262,   258,   108,
    1239,   110,   264,   268,   149,   150,   268,   850,   264,   852,
     155,   259,   268,  1613,   247,   248,   249,   250,   251,   252,
     253,   259,   309,  1623,   264,   258,   256,   257,   268,   259,
    1269,   261,   260,   320,   262,   256,   257,   324,   259,   264,
     261,   108,   264,   268,   263,   888,   268,   264,   962,  2175,
     264,   268,   263,   259,   268,   898,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   105,   259,   264,   264,   258,   922,
     268,   268,  2207,   264,   108,   264,   264,   268,   264,   268,
     268,   263,   268,  1332,  1333,   938,   264,   264,  1071,   264,
     268,   268,   263,   268,   264,   263,  2232,   950,   268,     8,
     264,   264,  1085,  1086,   268,   268,   959,   264,  1357,   105,
     105,   268,   264,   264,  2249,  1364,   268,   268,   971,  1102,
     264,   264,   264,   264,   268,   268,   268,   268,   264,   264,
     108,   264,   268,   268,  1383,   268,   264,   264,     4,     5,
     268,   268,   108,   259,   264,   261,   443,   444,   268,   264,
     264,   264,   264,   268,   268,   268,   268,     4,     4,   264,
     264,  1410,   459,   268,   268,  1089,   264,   264,   264,   264,
     268,   268,   268,   268,   264,  1424,   264,   264,   268,     4,
     268,   268,  1431,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   260,     4,   262,   263,    62,    63,    64,    65,
       4,   259,     6,     6,    70,    71,    72,    73,   264,   259,
     259,     6,   268,    79,  1387,    81,   264,   264,   264,   261,
     268,   268,   268,   978,   264,   261,   259,  1080,   268,    95,
     985,     6,    98,   264,   989,  1088,   102,   268,   263,   105,
       6,   267,   108,  1096,   110,   263,     6,   267,   259,   259,
       9,   259,  1750,  1751,   259,   121,  1109,  1240,  1241,   259,
     263,  1114,   559,   195,   195,   259,     3,   259,   195,   133,
     263,   259,   259,   259,   140,   572,   259,   574,   195,   263,
     259,   263,   259,   259,   259,     4,   259,   259,   259,   263,
      27,  1144,  1145,   263,  1147,  1148,  1149,   259,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,     6,   263,
    1163,   263,   259,   259,   259,     6,  1167,   261,     6,     6,
     263,   263,   263,   263,     7,   263,    63,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   211,   212,   213,   261,   258,
     261,   260,  1205,  1206,  1207,   261,     6,   223,     6,   259,
     259,   227,   263,   229,   230,   195,   259,   259,   259,   259,
     259,   259,     6,     6,   261,     6,     6,   263,  1231,   116,
       8,     6,     8,   259,   263,     7,     6,     6,  1143,   263,
     256,   257,   263,   263,  1247,  1248,  1249,   263,    97,   265,
     268,     6,   264,   268,   260,     7,     6,     6,   260,   263,
     263,   148,   263,   263,   263,   263,   153,   154,   155,   258,
     265,    67,     8,     7,     7,   162,   259,     6,  1411,  1412,
       7,   260,   263,     6,   192,     7,     6,     6,   264,   263,
     260,   264,   264,  1616,   262,     6,   263,     7,     6,   265,
     259,  1304,  1303,   261,     6,     6,   263,     6,     6,     6,
     260,     7,   199,   261,   761,     7,     7,     7,     7,     7,
    1323,     7,  1325,  1326,     7,     7,     7,     7,     7,   216,
       7,     7,  1335,     7,     7,   263,     6,  1340,   260,   262,
       7,  1344,   268,   260,   268,   264,   264,   268,   268,     7,
    1353,   265,  1355,     4,     6,  1358,   263,   263,   144,   263,
     265,  1435,   264,  1437,   264,     7,     6,   265,     7,     7,
     257,  1374,     7,   268,   260,   260,   268,     9,   268,   260,
     262,   265,  2030,   195,  1387,     7,   273,   274,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   267,   165,   264,  1412,
     258,   263,     6,     6,  1417,     6,  1419,   259,  1817,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,  1437,    49,  1601,    49,   258,   265,
    1605,   263,   259,   259,   263,     7,  1449,   265,   259,     7,
    1453,   265,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
       7,   268,  1624,  1625,   258,   922,     7,   195,   260,     7,
    1613,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,     7,
       6,   260,  1825,   258,   268,     7,     7,     7,  1511,  1512,
    1513,     7,   959,     7,   120,     4,  1519,  1520,  1521,   263,
       6,   259,  1596,     7,     6,   102,     7,     7,     7,     7,
       7,     7,     7,   263,     6,  1538,     6,     6,   108,     7,
       7,     6,     6,     4,     7,     7,  1549,   268,   260,   266,
     437,     6,   268,     6,  1557,   264,   263,   263,  1561,   263,
       6,   448,     7,     6,     6,     6,   261,     6,     6,  1572,
     263,  1574,   259,     6,   259,     6,     6,     6,     6,     6,
     264,   137,     6,   470,     6,  1659,     6,   265,     6,     6,
     262,     6,  1725,   268,     6,     6,     6,     6,   485,     6,
       5,   264,     6,   260,   260,     6,     4,     6,   263,   263,
       7,     6,   261,  1616,     7,   263,   263,   263,     6,     6,
     263,  1624,  1625,   264,     6,     6,   263,  1630,     6,   263,
     263,   191,   263,  1080,   263,   263,   263,     6,   268,   260,
     263,     6,  1547,   268,   268,  1648,   265,     7,   268,  1096,
     259,     6,   263,     6,   264,     6,  1659,     6,   259,     4,
     259,  1664,   106,     7,     6,     6,     6,     6,     6,   556,
     144,   558,  1746,   560,   561,   562,  1828,     5,   263,     6,
     260,   268,   263,     6,   263,     6,   144,   144,     6,   576,
     577,     6,   268,     6,     6,     6,     6,  1144,  1145,   268,
    1147,  1148,  1149,   260,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,     6,   268,     6,  1791,     6,     6,
     268,   263,   263,     6,  1798,  1799,     6,     6,     6,     6,
     263,     7,   148,     6,  1737,     5,   263,   263,   263,  1742,
    1743,   260,     6,  2066,     6,  1819,   263,     6,   263,  1750,
    1751,   264,   264,     6,   263,     7,     6,     6,  1205,   264,
     264,   260,  1765,     7,   190,     6,   264,     6,  1771,     6,
     265,  1676,   659,  1776,     6,     6,   263,     6,     6,   264,
       6,     6,  1785,     6,  1231,     6,     6,   260,     6,     6,
    1793,   193,   263,  1796,     6,     6,   683,   263,   144,     6,
    1247,     6,     6,   259,   264,   264,     6,     6,   260,   263,
       6,  1814,   263,   263,   263,  1818,   264,     6,     6,     6,
       6,     6,  1825,   263,  1827,  1828,   713,   714,   715,   716,
     717,   718,   719,   720,   721,   260,   723,   724,   725,   726,
     263,     6,   729,   730,   731,   264,     6,     6,     6,     6,
     264,     6,   739,     6,     6,   742,     6,  1304,     6,     6,
    1863,  1766,  1767,  1768,  1769,  1770,  1771,   263,   755,   263,
    1423,   263,  2188,   488,  2039,  1485,  1323,  1880,  1325,  1326,
    1671,  1997,  1733,  1448,     3,  1959,  1957,  1098,     3,  1892,
    1893,     3,     3,   630,  2026,  1593,     3,  1818,  1798,  1625,
      -1,    -1,    -1,   790,    -1,   792,   809,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1917,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   809,    -1,   148,    -1,  1929,  1374,  2002,   153,
     154,   155,    -1,   820,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,  2136,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
    1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1437,    -1,   216,    -1,    -1,  1998,    -1,    -1,    -1,    -1,
    2003,    -1,  1449,  2006,  2007,    -1,  1453,     6,    -1,    -1,
      -1,  2176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2024,    -1,    -1,  2027,    -1,    -1,    -1,    -1,  2030,
      -1,    -1,    -1,    -1,    -1,  2038,    -1,    -1,    -1,  2042,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,     6,   258,  2066,  1511,  1512,  1513,    -1,    -1,    -1,
      -1,    -1,  1519,  1520,  1521,    -1,  2079,    -1,  2152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   974,    -1,   976,
     977,  1538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1549,   990,    -1,  2108,    -1,    -1,    -1,    -1,
    1557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1010,    -1,  1572,    -1,  1574,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2043,  2044,
    2045,  2046,  2047,    -1,    -1,  1032,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2178,  2179,  2180,  2181,  2182,
      -1,    -1,  1069,  1630,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,  2107,    -1,   258,    -1,  2111,    -1,    -1,    -1,
      -1,    -1,  1659,   437,    -1,    -1,    -1,    -1,  2221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1114,    -1,    -1,
      -1,    -1,    -1,    -1,  2237,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,  2258,    -1,  2162,    -1,   258,
      -1,  2166,    -1,    -1,    -1,    -1,    -1,    -1,  2271,    -1,
      -1,    -1,    -1,    -1,  2277,  2278,    -1,  2182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2290,    -1,    -1,
    1737,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,  1765,  1206,
    1207,    -1,  2227,  2228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   556,    -1,   558,    -1,   560,   561,  1785,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,   577,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1814,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,  1271,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,     6,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,  1880,     6,    98,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,  1340,    -1,    -1,    -1,  1344,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1353,    -1,  1355,    -1,
    1917,  1358,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,  1368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     714,    -1,   716,   717,   718,   719,   720,   721,    -1,   723,
     724,   725,   726,    -1,    -1,   729,   730,   731,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1983,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,   212,
     213,  1998,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,    -1,    -1,    -1,   227,   148,   229,   230,    -1,   152,
      -1,    -1,    -1,    -1,   157,    -1,    -1,  2024,    -1,    -1,
      -1,   164,    -1,    -1,   167,   809,    -1,    -1,    -1,    -1,
      -1,  2038,    -1,    -1,    -1,     6,   820,   260,    -1,   262,
     263,   184,   185,   186,    -1,   188,   189,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,    -1,   200,   201,   202,
     203,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
      -1,    -1,  2079,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,  2108,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   285,   286,   287,   288,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,   305,   306,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1624,  1625,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   332,
     333,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,
      -1,  1648,    -1,    -1,    -1,   348,   349,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   369,   370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,   382,
     383,    -1,   385,    -1,    -1,    -1,   389,   390,   391,    -1,
      -1,   394,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2271,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   434,    -1,    -1,    -1,    -1,   439,   440,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   456,   457,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   471,    -1,
    1114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1793,    -1,    -1,  1796,
     493,    -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,   502,
      -1,    -1,    -1,    -1,  1811,    -1,  1813,    -1,    -1,    -1,
      -1,    -1,    -1,   516,   517,    -1,    -1,    -1,    -1,   522,
      -1,  1828,    -1,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
      -1,   554,   555,    -1,   557,    -1,  1863,    -1,    -1,    -1,
      -1,    -1,  1206,  1207,   567,    -1,    -1,   570,   571,    -1,
      -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,    -1,    -1,
     583,    -1,    -1,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,    -1,   616,   617,    -1,    -1,    -1,    -1,    -1,
       6,   624,   625,   626,    -1,    -1,    -1,    -1,    -1,   632,
     633,   634,   635,    -1,   637,   638,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   656,   657,   658,    -1,    -1,    -1,   662,
     663,   664,   665,   666,   667,   668,   669,   670,    -1,    -1,
      -1,    -1,    -1,   676,   677,    -1,   679,    -1,    -1,   682,
     305,   306,    -1,   686,   687,   688,   689,     6,    -1,    -1,
     693,   694,   695,   696,   697,    -1,  1340,   700,    -1,   702,
    1344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1353,
      -1,  1355,    -1,    -1,  1358,    -1,    -1,    -1,    -1,   722,
      -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   736,    -1,    -1,    -1,    -1,    -1,    -1,
     743,   744,    -1,   746,    -1,    -1,   749,   750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   758,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1412,    -1,
      -1,    -1,    -1,   776,    -1,   778,    -1,    -1,    -1,    -1,
     783,   784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   798,    -1,   800,   801,    -1,
      -1,   804,    -1,   806,   807,    -1,    -1,    -1,   811,    -1,
     813,    -1,   815,  2120,   439,    -1,    -1,    -1,   821,    -1,
      -1,    -1,   825,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,    -1,    -1,    -1,   848,   258,   850,   260,   852,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,  2186,
      -1,    -1,     6,    -1,    -1,   888,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   898,   899,   900,   901,    -1,
      -1,  2208,    -1,    -1,    -1,    -1,    -1,   910,    -1,    -1,
      -1,    -1,    -1,   208,   209,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   938,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   950,    -1,    -1,
      -1,  2258,    -1,    -1,    -1,   958,    -1,    -1,   583,   962,
      -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,   971,    -1,
    2277,  2278,    -1,    -1,    -1,    -1,   979,   980,    -1,    -1,
      -1,    -1,   985,  2290,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   286,    -1,    -1,   289,    -1,    -1,    -1,    -1,  1002,
      -1,    -1,  1005,    -1,  1648,    -1,    -1,    -1,    -1,    -1,
     305,   306,   637,   638,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1031,    -1,
    1033,  1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
      -1,    -1,    -1,   348,    -1,    -1,    -1,    -1,    -1,     6,
      -1,   686,   687,   688,    -1,    -1,    -1,    -1,    -1,   694,
      -1,    -1,    -1,  1076,    -1,   370,    -1,    -1,    -1,    -1,
    1083,    -1,    -1,    -1,    -1,    -1,    -1,  1090,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1103,  1104,    -1,    -1,    -1,    -1,  1109,    -1,    -1,    -1,
      -1,   736,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,  1141,    -1,
      -1,    -1,    -1,    -1,   439,    -1,    -1,    -1,    -1,  1793,
      -1,   776,  1796,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   798,    -1,    -1,    -1,    -1,  1181,   804,
      -1,   806,    -1,    -1,    -1,    -1,    -1,    -1,  1191,  1192,
    1193,  1194,  1195,    -1,    -1,    -1,    -1,  1200,  1201,    -1,
    1203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,  1219,  1220,    -1,    -1,
      -1,    -1,   517,    -1,  1227,  1228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1236,  1237,    -1,    -1,    -1,    -1,  1242,
    1243,    -1,    -1,    -1,    -1,  1248,  1249,   542,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   551,   552,    -1,    -1,
      -1,    -1,    -1,   888,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,    -1,
    1283,    -1,    -1,   578,    -1,    -1,    -1,    -1,   583,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,   938,   609,    -1,    -1,    -1,  1321,    -1,
      -1,    -1,    -1,    -1,    -1,   950,    -1,    -1,    -1,    -1,
      -1,    -1,  1335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1343,    -1,   637,   638,    -1,    -1,   971,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1365,  1366,    -1,    -1,    -1,  1370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1381,    -1,
      -1,  1384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   686,   687,   688,    -1,    -1,    -1,    -1,    -1,   694,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1413,    -1,    -1,  1416,  1417,  1418,  1419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1427,    -1,    -1,  1430,    -1,  1432,
      -1,  1434,  1435,    -1,    -1,  1438,  1439,    -1,    -1,    -1,
      -1,   736,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   776,    -1,    -1,  1109,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   798,    -1,    -1,    -1,   258,    -1,   804,
      -1,   806,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1529,  1530,  1531,    -1,
      -1,    -1,    -1,    -1,    -1,  1538,    -1,  1540,  1163,    -1,
      -1,    -1,    -1,    -1,  1547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   850,    -1,   852,  1561,    -1,
      -1,    -1,    -1,    -1,  1567,  1568,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1578,  1579,  1580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1588,    -1,    -1,    13,    14,
      -1,    -1,    -1,   888,    -1,    -1,  1599,    -1,    -1,    -1,
      -1,    -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2258,    -1,    -1,  1620,    -1,    -1,
      -1,    -1,    -1,  1248,  1249,  1628,  1629,    -1,    -1,    -1,
      -1,    -1,    -1,  2277,  2278,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,   938,    -1,    -1,  2290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   461,   950,    -1,    -1,    -1,    -1,
      -1,  1664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   971,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,    -1,  1706,  1707,  1708,    -1,    -1,   133,   134,
    1335,    -1,   137,   138,  1717,   140,   141,    -1,   143,  1722,
    1723,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,  1735,    -1,    -1,    -1,   161,    -1,    -1,  1742,
    1743,  1744,    -1,  1746,    -1,    -1,    -1,    -1,    -1,  1752,
    1753,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   568,   187,   188,   189,    -1,    -1,    -1,  1771,    -1,
      -1,    -1,    -1,  1776,  1777,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,    -1,
      -1,  1794,  1417,    -1,  1419,  1798,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1807,  1808,    -1,  1810,    -1,    -1,
      -1,    -1,    -1,   620,  1109,    -1,    -1,  1820,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1834,    -1,    -1,    -1,    -1,  1839,  1840,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,    -1,    -1,  1856,  1857,    -1,  1859,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,  1892,
    1893,   258,    -1,    -1,    -1,    -1,  1899,  1900,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1920,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1929,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1561,    -1,    -1,  1942,
    1943,    -1,    -1,  1946,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1248,  1249,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,  1980,  1981,   258,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,  2001,    -1,
      -1,    -1,   258,  2006,  2007,  2008,    -1,    -1,    -1,    -1,
    2013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2027,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2042,
    1335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2051,    -1,
      -1,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,    -1,   870,   871,   872,   873,    -1,   875,   876,
     877,   878,    -1,  2076,    -1,    -1,    -1,    -1,    -1,  2082,
      -1,    -1,  2085,    -1,   891,    26,   893,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   904,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   912,   913,    -1,     6,    -1,
      -1,    -1,    -1,  2116,   921,    -1,    -1,  1742,  1743,    -1,
      -1,    -1,  1417,    -1,  1419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2142,
    2143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1776,    -1,     6,  2157,  2158,    -1,  2160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2173,    -1,    -1,    -1,    -1,  2178,  2179,  2180,  2181,  2182,
      -1,    -1,    -1,    -1,    -1,  2188,    -1,    -1,     6,  2192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2219,    -1,    -1,    -1,
      -1,  2224,  2225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,  1039,  1040,  2237,    -1,    -1,  1044,  1045,    -1,
      -1,  1048,  1049,  1050,  1051,    -1,  1053,    -1,    -1,    -1,
      -1,  1058,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2264,  2265,    -1,    -1,    -1,  1561,  1892,  1893,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
      -1,  1946,    -1,   264,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1140,    -1,  1142,   277,   278,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1664,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2006,  2007,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,  2027,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2042,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,  1245,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,  1742,  1743,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   397,   398,    -1,    -1,
      -1,   402,   403,   404,   405,   406,   407,   408,    -1,   410,
      -1,    -1,    -1,    -1,   415,   416,  1771,    -1,   419,    -1,
      -1,  1776,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,   433,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2160,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,  2178,  2179,  2180,  2181,  2182,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,  1393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1892,  1893,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1436,
      -1,    -1,    -1,    -1,  1929,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     591,  1946,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1468,  1469,  1470,  1471,  1472,  1473,  1474,    -1,    -1,
      -1,    -1,  1479,  1480,    -1,    -1,    -1,    -1,    -1,  1486,
      -1,    -1,  1489,    -1,    -1,    -1,  1493,    -1,    -1,  1496,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,    -1,
    1507,    -1,    -1,   220,   221,   222,    -1,   224,   225,   226,
      -1,  2006,  2007,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,  2027,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,   263,  2042,    -1,   266,
      -1,     8,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,  1584,    -1,  1586,
      -1,    -1,    -1,  1590,    -1,  1592,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,     3,     4,    -1,    -1,    -1,    -1,  1624,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     4,     5,    -1,    -1,  2160,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2178,  2179,  2180,  2181,  2182,    -1,    -1,
      82,    83,    84,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    96,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,  1724,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,
      -1,    -1,  2237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   916,    -1,    -1,   121,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   140,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,   949,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,  1830,    -1,    -1,  1833,    -1,   220,   221,
     222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,   259,   211,   212,
     213,   263,    -1,    -1,   266,  1882,  1883,    -1,  1885,    -1,
     223,    -1,    -1,    -1,   227,     8,   229,   230,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,  1950,  1951,   258,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     8,  1999,  1134,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,    -1,
      -1,  1232,    -1,    -1,   149,   150,   151,   152,   153,    -1,
     155,   156,   157,   158,   159,   160,    -1,    -1,    -1,   164,
      -1,    -1,   167,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    -1,    -1,    -1,   258,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,  2246,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,  1394,  1395,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,
    1491,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,  1500,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
      -1,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
     164,    -1,    -1,   167,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,   192,   260,
      -1,   262,    -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,   229,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,
      -1,    -1,   266,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,    -1,  1663,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,    -1,
      -1,    -1,   258,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   268,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,   203,    -1,    -1,    -1,
      -1,    -1,    -1,   210,   211,   212,   213,   214,    -1,    95,
      -1,    -1,    98,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,   230,    -1,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,   256,
     257,    -1,   259,    -1,   261,     3,     4,     5,   265,   266,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,   211,   212,   213,    76,    77,
      78,    -1,    -1,    -1,    82,    83,    84,   223,    -1,    -1,
      -1,   227,    -1,   229,   230,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,   135,   136,    -1,
     138,    -1,   140,    -1,    -1,   143,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,    -1,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,   164,    -1,    -1,   167,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,   192,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,    -1,   220,   221,   222,    -1,   224,   225,   226,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,     3,     4,    -1,   263,    -1,     8,   266,    10,
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
      -1,   192,    -1,    -1,    -1,   264,    -1,    -1,    -1,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,
     221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,     3,
       4,     5,    -1,   264,    -1,   266,    10,    11,    12,    -1,
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
     252,   253,    -1,    -1,    -1,    -1,   258,    -1,   192,    -1,
      -1,    -1,   264,    -1,    -1,    -1,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
     214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,    -1,
     224,   225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,   259,     3,     4,    -1,   263,
      -1,    -1,   266,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,   258,    -1,   192,    -1,    -1,    -1,   264,
      -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   215,    -1,
      -1,    -1,    -1,   220,   221,   222,    -1,   224,   225,   226,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,     3,     4,    -1,   263,   264,    -1,   266,
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
     258,    -1,   192,    -1,    -1,    -1,   264,    -1,    -1,    -1,
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
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,   192,
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
      -1,    -1,    -1,    -1,   258,    -1,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   215,
      -1,    -1,    -1,    -1,   220,   221,   222,    -1,   224,   225,
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
      -1,   258,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
      -1,   220,   221,   222,    -1,   224,   225,   226,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     259,     3,     4,    -1,    -1,   264,    -1,   266,    10,    11,
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
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,   221,
     222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,   259,     3,     4,
      -1,   263,    -1,    -1,   266,    10,    11,    12,    -1,    -1,
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
     253,    -1,    -1,    -1,    -1,   258,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,
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
      -1,    -1,   258,    -1,   192,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,   214,   215,    -1,    -1,
      -1,    -1,   220,   221,   222,    -1,   224,   225,   226,    -1,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,     3,     4,    -1,   263,    -1,     8,   266,    10,
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
      -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,   220,
     221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,     3,     4,    -1,    -1,   259,     8,
      -1,    10,    11,    12,    -1,   266,    15,    16,    17,    18,
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
      -1,   258,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,   214,   215,    -1,    -1,    -1,
      -1,   220,   221,   222,    -1,   224,   225,   226,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,     3,     4,    -1,    -1,
     259,    -1,    -1,    10,    11,    12,    -1,   266,    15,    16,
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
      -1,    -1,    -1,   258,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,
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
     258,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   214,   215,    -1,    -1,    -1,    -1,   220,   221,   222,
      -1,   224,   225,   226,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,     3,     4,     5,    -1,   259,    -1,    -1,    10,
      11,    12,    -1,   266,    15,    16,    17,    18,    19,    20,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,
     211,   212,   213,   214,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,   229,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,   263,    -1,    -1,   266,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
      -1,    -1,    -1,    -1,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,     3,     4,     5,   263,    -1,
      -1,   266,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,   210,   211,   212,   213,   214,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
      -1,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,   263,    -1,    -1,   266,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,
     212,   213,   214,    -1,    -1,    -1,    -1,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,    -1,   229,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,     3,     4,    -1,    -1,   259,     8,    -1,
      10,    11,    12,    -1,   266,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    93,    94,    -1,    96,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    82,
      83,    84,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,   133,   134,    -1,
      -1,   137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,   214,   161,    -1,    -1,    -1,    -1,
     220,   221,   222,    -1,   224,   225,   226,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,   247,   248,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,
      -1,    -1,    -1,    -1,    -1,    -1,   266,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,   268,
      -1,   214,    -1,    -1,    -1,    -1,    -1,   220,   221,   222,
      -1,   224,   225,   226,    -1,    -1,    -1,   230,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,     3,     4,    -1,     6,   259,   260,    -1,    10,
      11,    12,    -1,   266,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,    96,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,   210,
      -1,    -1,   258,   214,    -1,    -1,    -1,    -1,    -1,   220,
     221,   222,   268,   224,   225,   226,    -1,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,   266,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,   220,   221,   222,    -1,   224,   225,   226,
      -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,     3,     4,
      -1,     6,   259,    -1,    -1,    10,    11,    12,    -1,   266,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    93,    94,
      -1,    96,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    82,    83,    84,   118,   119,   120,
     121,    -1,    -1,   124,    -1,    93,    94,    -1,    96,    -1,
      -1,    -1,   133,   134,    -1,    -1,   137,   138,    -1,   140,
     141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,
     161,    -1,    -1,    -1,    -1,   220,   221,   222,    -1,   224,
     225,   226,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,
      -1,    -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,   268,    -1,   214,    -1,    -1,    -1,
      -1,    -1,   220,   221,   222,    -1,   224,   225,   226,    -1,
      -1,    -1,   230,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,     3,     4,    -1,
      -1,   259,   260,    -1,    10,    11,    12,    -1,   266,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    93,    94,    -1,
      96,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    82,    83,    84,   118,   119,   120,   121,
      -1,    -1,   124,    -1,    93,    94,    -1,    96,    -1,    -1,
      -1,   133,   134,    -1,    -1,   137,   138,    -1,   140,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,   214,   161,
      -1,    -1,    -1,    -1,   220,   221,   222,    -1,   224,   225,
     226,    -1,    -1,    -1,   230,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,   259,   260,    -1,    -1,    -1,    -1,    -1,
     266,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,    -1,
      -1,    -1,    -1,   258,    -1,    13,    14,    -1,    -1,    -1,
      -1,   210,    -1,   268,    -1,   214,    -1,    -1,    -1,    -1,
      -1,   220,   221,   222,    -1,   224,   225,   226,    -1,    -1,
      -1,   230,   264,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,   247,   248,
     118,   119,   120,   121,    -1,   254,   124,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,   133,   134,   266,    -1,   137,
     138,    -1,   140,   141,    -1,   143,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,   187,
     188,   189,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,
     138,    -1,   140,   141,    -1,   143,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   187,
     188,   189,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   133,   134,    13,
      14,   137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,   187,   188,   189,    -1,    -1,   264,   133,   134,    13,
      14,   137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,
     124,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,   133,
     134,    13,    14,   137,   138,    -1,   140,   141,   264,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,
     124,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   133,
     134,    13,    14,   137,   138,    -1,   140,   141,   264,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,   124,   187,   188,   189,    -1,    -1,    -1,    -1,
      -1,   133,   134,    13,    14,   137,   138,    -1,   140,   141,
     264,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,   124,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,   133,   134,    13,    14,   137,   138,    -1,   140,   141,
     264,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,   124,   187,   188,   189,    -1,    -1,
      -1,    -1,    -1,   133,   134,    13,    14,   137,   138,    -1,
     140,   141,   264,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,   124,    -1,    -1,   187,   188,   189,
      -1,    -1,    -1,   133,   134,    -1,    -1,   137,   138,    -1,
     140,   141,   264,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,    -1,
     118,   119,   120,   121,    -1,    -1,   124,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,
     138,    -1,   140,   141,   264,   143,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,    13,    14,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,    -1,   187,
     188,   189,   258,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,   268,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    -1,    91,    92,    -1,    94,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   264,    -1,   117,   118,
     119,   120,   121,   122,    -1,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,    -1,    -1,   145,   146,   147,    -1,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,    -1,    -1,    -1,   175,   176,   177,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,   192,    -1,   194,    -1,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,     4,    -1,    -1,    -1,    -1,   216,   217,   218,
     219,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,   230,   231,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    46,    47,    48,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    -1,    91,
      92,    -1,    94,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,   117,   118,   119,   120,   121,
     122,    -1,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    -1,    -1,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,   175,   176,   177,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,     4,     5,
     192,    -1,   194,    -1,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,    -1,    -1,    -1,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   228,    -1,   230,   231,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
       4,     5,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,     5,   105,
      -1,    -1,   108,    -1,   110,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,   121,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,   140,    79,    -1,    81,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    95,    -1,    -1,    98,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,   212,   213,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,    -1,
      -1,   227,    -1,   229,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,   211,   212,   213,
     268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
      -1,    -1,    -1,   227,    -1,   229,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   211,   212,   213,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,   268,    -1,
     227,    -1,   229,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    13,    14,    -1,   118,
     119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   133,   134,    -1,    -1,   137,   138,
      -1,   140,   141,    -1,   143,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,    -1,    -1,   165,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,    -1,   187,   188,
     189,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,   134,    -1,    -1,
     137,   138,    -1,   140,   141,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,    -1,    -1,    -1,    -1,   258,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,    -1,   268,   236,   237,
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
     121,   133,   138,   140,   143,   192,   210,   214,   215,   220,
     221,   222,   224,   225,   226,   247,   248,   254,   259,   263,
     266,   317,   318,   321,   332,   339,   341,   352,   353,   357,
     359,   365,   367,   382,   259,   263,   263,   108,   108,   133,
     105,   108,   110,   317,   105,   108,   109,   110,   121,   187,
     318,   105,   108,   259,   105,   165,   192,   208,   209,   263,
     247,   248,   259,   263,   362,   363,   362,   263,   263,   362,
       4,   102,   106,   112,   113,   115,   116,   137,   263,   259,
     108,   110,   108,   105,     4,    94,   203,   263,   382,     4,
       6,   102,   105,   108,   105,   108,   121,   319,     5,   259,
     263,   365,   366,   108,     4,     4,     4,   366,     4,   108,
     259,   108,   259,   259,     4,   263,   369,   382,     4,   259,
     259,   259,     6,     6,   261,     5,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    62,    63,    64,    65,    70,
      71,    72,    73,    79,    81,    95,    98,   211,   212,   213,
     223,   227,   229,   373,   382,   259,     4,   373,     5,   263,
       5,   263,   317,    32,   248,   352,   382,   261,     6,   263,
     259,   263,     6,   259,   263,     6,   267,     7,   140,   203,
     232,   233,   234,   235,   256,   257,   259,   261,   265,   291,
     292,   293,   317,   352,   372,   373,   382,     4,   321,   322,
     323,   263,     6,   352,   372,   373,   382,   372,   372,   352,
     372,   379,   380,   382,   352,   323,   352,   298,   302,   259,
     361,     9,   373,   259,   373,   352,   352,   352,   259,   352,
     352,   352,   259,   352,   352,   352,   352,   352,   352,   352,
     372,   352,   352,   352,   352,   366,   259,   248,   352,   367,
     368,   368,   263,   366,   365,   372,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   259,   261,   293,   293,   293,   293,   293,   293,   259,
     293,   293,   259,   317,   318,   318,   318,   293,   293,     5,
     263,   263,   133,   317,   317,   318,   259,   293,   293,   259,
     259,   259,   352,   263,   352,   367,   352,   352,   264,   368,
     359,   382,   195,     5,   263,     8,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   258,     9,   259,   261,   265,   292,
     293,   352,   368,   368,   259,   259,   259,   365,   366,   366,
     366,   316,   259,   263,   259,   259,   365,   263,   263,   352,
       4,   365,   263,   369,   263,   263,   362,   362,   362,   352,
     352,   247,   248,   263,   263,   362,   247,   248,   259,   323,
     362,   263,   259,   263,   259,   259,   259,   259,   259,   259,
     259,   368,   352,   366,   366,   366,   259,   263,     4,   261,
     263,     6,   261,   323,     6,     6,   263,   263,   263,   263,
     366,   352,     8,     7,   263,   261,   261,   261,     6,     6,
     259,   352,   259,   352,   352,   265,   352,   263,   195,   352,
     352,   352,   352,   293,   293,   293,   259,   259,   259,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   259,
     259,   293,   259,   261,     6,     6,   263,     6,     8,   323,
       6,     8,   323,   259,   293,   352,   249,   263,     9,   259,
     261,   265,   372,   368,   352,   323,   365,   365,   263,   373,
     317,     7,   352,   352,     4,    36,    37,   111,   112,   192,
     193,   295,   365,     6,   260,   262,   263,   294,   263,     6,
     263,     6,     9,   259,   261,   265,   382,   264,   133,   138,
     140,   141,   143,   315,   317,   352,     6,   260,   268,     9,
     259,   261,   265,   260,   268,   260,   268,   268,   260,   268,
       9,   259,   265,   268,   264,   268,   262,   268,   297,   262,
     297,    97,   360,   358,   382,   268,   352,   268,   260,   260,
     260,   352,   260,   260,   260,   352,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   264,     7,   352,
     249,   264,   268,   264,   352,     6,     6,   260,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   367,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   367,   367,   382,   263,   352,
     352,   372,   352,   372,   365,   372,   372,   379,   263,   263,
     263,   263,   352,   294,   382,     8,   352,   352,   366,   365,
     263,   372,   372,   367,   359,   373,   359,   368,   260,   264,
     265,   293,    67,     8,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   263,   352,
     367,   352,   352,   352,   352,   352,   382,   352,   352,   295,
     263,   294,   260,   264,   264,   352,   352,   352,     7,     7,
     345,   345,   259,   352,   352,   352,   352,     6,   168,   368,
     368,   263,   260,     6,   323,   263,   323,   323,   268,   268,
     268,   362,   362,   322,   322,   268,   352,   264,   336,   268,
     323,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     264,   260,     7,   346,     6,     7,   352,   352,     6,   352,
     323,   352,   264,   368,   368,   368,   352,     6,   260,   264,
     352,   368,   352,   352,   352,   352,   260,   352,   260,   260,
     192,   268,   323,   263,     8,   260,   260,   262,   379,   372,
     379,   372,   372,   372,   372,   372,   372,   352,   372,   372,
     372,   372,   266,   375,   382,   373,   372,   372,   372,   359,
     382,   368,   264,   264,   264,   264,   352,   352,   352,   323,
     382,   295,   262,   264,   260,   147,   165,   340,   260,   264,
     268,   352,     6,   263,   365,   260,   262,   265,     7,     7,
     291,   292,     6,   368,     7,   235,   291,   352,   276,   382,
     352,   352,   295,   261,   259,   133,   317,   318,   317,   263,
     264,     6,   242,   243,   273,   368,   382,   352,   352,   295,
       6,   368,     6,   368,   352,     6,   372,   380,   382,   260,
     295,   352,   352,     6,   382,     6,   372,   352,   260,   261,
     352,   268,   373,     7,     7,     7,   260,     7,     7,     7,
     260,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   352,   260,   263,   352,   367,     6,   263,   264,     6,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   268,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   268,   268,   268,   268,   268,   260,   262,   262,   368,
     268,   268,   294,   268,   294,   268,   268,   268,   260,   368,
     352,   352,   352,   354,   294,   264,   264,   264,   352,   268,
     268,   294,   294,   260,   265,   260,   265,   268,   293,   355,
     264,     7,   295,   294,   365,   264,     8,     8,   368,   265,
     260,   262,   259,   261,   292,   293,   368,     7,   263,   263,
     260,   260,   260,   352,   365,     4,   344,     6,   311,   352,
     373,   260,   264,   260,   260,   352,   264,   264,   368,   265,
     264,   323,   264,   264,   362,   352,   352,   264,   264,   352,
     362,   144,   144,   162,   172,   173,   174,   178,   179,   337,
     338,   362,   264,   333,   260,   264,   260,   260,   260,   260,
     260,   260,   260,   263,     7,   352,     6,   352,   260,   264,
     262,   264,   262,   264,   264,   264,   264,     6,   264,   262,
     262,   268,   260,     7,   260,     7,     7,   265,   352,   264,
     352,   352,     7,   265,   294,   268,   294,   294,   260,   260,
     268,   294,   294,   268,   268,   294,   294,   294,   294,   352,
     294,     9,   374,   268,   260,   268,   294,   265,   268,   356,
     262,   264,   260,   264,   265,   259,   261,   267,   195,     7,
     165,     6,   352,   264,   263,     6,   365,   264,   352,     6,
       7,   291,   292,   265,   291,   292,   295,   263,   370,   382,
     373,   352,     6,   264,    49,    49,   365,   264,     4,   182,
     183,   184,   185,   264,   279,   283,   286,   288,   289,   331,
     265,   260,   262,   259,   352,   352,   259,   263,   259,   263,
       8,   368,   372,   260,   265,   260,   262,   259,   260,   260,
     268,   265,   259,   264,   268,     7,   293,     4,    36,    37,
     305,   306,   307,   294,   352,   294,   362,   365,   365,     7,
     365,   365,   365,     7,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,     6,     7,   368,   322,   352,   352,
     352,   352,   352,   352,   264,   352,   352,   352,   365,   372,
     372,   264,   264,   264,   264,   268,   304,   264,   352,   352,
     295,   295,   352,   352,   260,   365,   293,   352,   352,   264,
     295,   292,   265,   292,   352,   352,   294,   264,   365,   368,
     368,     7,     7,     7,   144,   343,     6,   260,   268,     7,
       7,     7,     6,     7,     7,   264,     4,   295,   264,   268,
     268,   268,   264,   264,   120,     4,     6,   352,   263,     6,
     259,     6,   180,     6,   180,   264,   338,   268,   337,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   322,   365,
       6,   263,   102,     6,     6,     6,   108,     7,     7,     6,
       6,   352,     7,   365,     7,   365,   365,     4,   268,     8,
       8,   260,   295,   295,   368,   372,   352,   372,   266,   268,
     308,   372,   372,   295,   372,   260,   268,     6,   295,   263,
     317,   263,     6,   352,     6,   263,   365,   264,   264,   352,
       6,   192,   193,   295,   352,     6,     7,   369,   371,     6,
     261,     6,     6,   294,   293,   293,     6,   280,   259,   259,
     263,   290,     6,   295,   265,   372,   352,   262,   260,   352,
       8,   368,   352,   368,   264,   264,     6,     6,   273,   295,
     265,   352,     6,     6,   352,   295,   260,     6,   352,   263,
     352,   373,   294,    49,   263,   365,   373,   376,   352,   352,
     262,   268,     6,   260,     6,     6,   137,   313,   313,   365,
       6,     6,     6,   365,   144,   195,   312,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   264,   264,   294,
     294,   294,   294,   294,   294,   294,   268,   268,   268,   260,
     294,   294,   306,   294,   260,   294,   260,   293,   355,   294,
       6,   294,   259,   261,   293,   295,   260,   262,   294,     6,
     264,   264,   365,   365,   365,     4,     6,   291,   352,   365,
     365,   365,   263,   263,     7,     6,     7,   352,   352,   352,
     263,   263,   263,   261,     6,   352,   365,   352,     6,     6,
     352,   362,   264,     5,   365,   263,   263,   263,   263,   263,
     263,   263,   365,   264,     6,   368,   263,   263,   352,   352,
     262,   365,     6,   365,     6,   191,   352,   352,   352,     6,
       6,     7,   294,   268,   268,   294,   268,   352,     4,   207,
     309,   310,   294,   260,   294,   356,   373,   259,   261,   352,
     263,   323,     6,   323,   268,     6,     6,   265,     7,     7,
     291,   292,     6,   369,   264,   268,   352,   291,   263,   294,
     377,   378,   379,   377,   259,   352,   352,   364,   365,   263,
     259,     4,     6,   260,     6,   260,   264,   264,   260,   264,
       6,     6,   372,   259,     4,   260,   268,   259,   264,   268,
     365,   373,     7,   293,   303,   352,   367,   307,     6,   362,
       6,     6,     6,   144,   314,   102,   121,   106,     6,     5,
     263,     6,   352,   352,   352,   352,   260,   355,   352,   352,
     294,   292,   263,   263,     6,   312,     6,   352,   365,   144,
     144,     4,     6,   368,   368,   352,   352,   373,   264,   260,
     264,   268,   322,   322,   352,   352,   264,   268,   260,   264,
     268,     6,     6,   364,   362,   362,   362,   362,   362,   248,
     362,     6,   264,   368,   352,     6,     6,     6,     6,     6,
     365,   264,   268,     8,   264,   260,   263,   352,   373,   372,
     352,   372,   352,   373,   376,   378,   373,   268,   260,   268,
     264,   352,   340,   340,   365,   295,   370,   373,   352,     6,
       6,   369,   262,   365,   379,     6,   294,   294,   277,   352,
     268,   268,   264,   268,   278,   352,   352,     6,     6,     6,
       6,   352,   352,   260,     6,   352,   299,   301,   263,   378,
     264,   268,     7,     7,   148,     6,   263,   263,   263,     5,
     364,   294,   294,   268,   294,   260,   260,   262,   368,   368,
       6,     6,   352,   352,   263,   264,   264,   263,     6,     6,
     263,   352,   264,   264,   264,   262,     6,   365,     7,   263,
     352,   264,   268,   268,   268,   268,   268,   268,     6,   264,
     264,   190,   352,   352,   368,     6,     6,   260,   294,   294,
     310,   373,   264,   264,   264,   264,     7,     6,     6,     6,
     265,     6,   264,     6,     6,   260,   268,   352,   352,   263,
     365,   264,   268,   260,   260,   268,   264,   304,   308,   365,
     294,   352,   373,   382,   368,   368,   352,     6,   264,   352,
     355,   264,   264,     6,     6,   364,   149,   150,   155,   347,
     149,   150,   347,   368,   322,   264,   268,     6,   264,   365,
     323,   264,     6,   368,   362,   362,   362,   362,   362,     6,
     352,   264,   264,   264,   260,     6,   263,     6,   369,   193,
     281,   352,   268,   268,   364,     6,   352,   352,     6,   264,
     264,   300,     7,   259,   264,   264,   264,   263,   268,   260,
     263,   264,   263,   362,   365,     6,   263,   362,     6,   264,
     264,   352,     6,   144,   264,   334,   263,   264,   268,   268,
     268,   268,   268,     6,     6,     6,   323,     6,   263,   352,
     352,   264,   268,   304,   373,   260,   352,   352,   368,     6,
     362,     6,   362,     6,     6,   264,   352,   337,   323,     6,
     368,   368,   368,   368,   362,   368,   340,   278,   260,   268,
       6,   263,   352,   264,   268,   268,   264,   268,   268,     6,
     264,   264,   335,   264,   264,   264,   264,   268,   264,   264,
     264,   284,   352,   364,   264,   352,   352,   362,   362,   337,
       6,     6,     6,     6,   368,     6,     6,     6,   263,   260,
     264,     6,   264,   294,   268,   268,   264,   264,   282,   372,
     287,   263,     6,   352,   352,     6,   264,   268,   263,   364,
     264,   264,     6,   372,   285,   372,   264,     6,     6,   264,
     268,     6,     6,   372
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

  case 550:
#line 6007 "Gmsh.y"
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
#line 6017 "Gmsh.y"
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

  case 554:
#line 6049 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 555:
#line 6053 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 556:
#line 6058 "Gmsh.y"
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

  case 557:
#line 6070 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 558:
#line 6074 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 559:
#line 6078 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 560:
#line 6082 "Gmsh.y"
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

  case 561:
#line 6100 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 562:
#line 6108 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 563:
#line 6116 "Gmsh.y"
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

  case 564:
#line 6145 "Gmsh.y"
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

  case 565:
#line 6155 "Gmsh.y"
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

  case 566:
#line 6171 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 567:
#line 6182 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 568:
#line 6187 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 569:
#line 6191 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 570:
#line 6195 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 571:
#line 6207 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 572:
#line 6211 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 573:
#line 6223 "Gmsh.y"
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

  case 574:
#line 6240 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 575:
#line 6250 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 576:
#line 6254 "Gmsh.y"
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

  case 577:
#line 6269 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 578:
#line 6274 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 579:
#line 6281 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 580:
#line 6285 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 581:
#line 6290 "Gmsh.y"
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
#line 6304 "Gmsh.y"
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
#line 6318 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 584:
#line 6322 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 585:
#line 6326 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(nullptr, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 586:
#line 6330 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 587:
#line 6334 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 588:
#line 6342 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 589:
#line 6348 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 590:
#line 6357 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 591:
#line 6361 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 592:
#line 6365 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 593:
#line 6373 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 594:
#line 6379 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 595:
#line 6385 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 596:
#line 6389 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 597:
#line 6396 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 598:
#line 6404 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 599:
#line 6411 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 600:
#line 6420 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(nullptr, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 601:
#line 6424 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 602:
#line 6428 "Gmsh.y"
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

  case 603:
#line 6443 "Gmsh.y"
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

  case 604:
#line 6457 "Gmsh.y"
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

  case 605:
#line 6471 "Gmsh.y"
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

  case 606:
#line 6483 "Gmsh.y"
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

  case 607:
#line 6499 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 608:
#line 6508 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 609:
#line 6517 "Gmsh.y"
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

  case 610:
#line 6527 "Gmsh.y"
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

  case 611:
#line 6538 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 612:
#line 6546 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 613:
#line 6554 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 614:
#line 6558 "Gmsh.y"
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

  case 615:
#line 6577 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 616:
#line 6584 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 617:
#line 6590 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 618:
#line 6596 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 619:
#line 6603 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 620:
#line 6610 "Gmsh.y"
    { init_options(); ;}
    break;

  case 621:
#line 6612 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 622:
#line 6620 "Gmsh.y"
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

  case 623:
#line 6644 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 624:
#line 6646 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 625:
#line 6652 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 626:
#line 6657 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 627:
#line 6659 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 628:
#line 6664 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 629:
#line 6669 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 630:
#line 6674 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 631:
#line 6676 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 632:
#line 6680 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 633:
#line 6692 "Gmsh.y"
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

  case 634:
#line 6706 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(nullptr, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 635:
#line 6710 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 636:
#line 6717 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 637:
#line 6725 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 638:
#line 6733 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 639:
#line 6744 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 640:
#line 6746 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 641:
#line 6749 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14953 "Gmsh.tab.cpp"
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


#line 6752 "Gmsh.y"


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

