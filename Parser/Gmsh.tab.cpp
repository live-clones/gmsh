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
     tRelocateMesh = 384,
     tReorientMesh = 385,
     tSetFactory = 386,
     tThruSections = 387,
     tWedge = 388,
     tFillet = 389,
     tChamfer = 390,
     tPlane = 391,
     tRuled = 392,
     tTransfinite = 393,
     tPhysical = 394,
     tCompound = 395,
     tPeriodic = 396,
     tParent = 397,
     tUsing = 398,
     tPlugin = 399,
     tDegenerated = 400,
     tRecursive = 401,
     tSewing = 402,
     tRotate = 403,
     tTranslate = 404,
     tSymmetry = 405,
     tDilate = 406,
     tExtrude = 407,
     tLevelset = 408,
     tAffine = 409,
     tBooleanUnion = 410,
     tBooleanIntersection = 411,
     tBooleanDifference = 412,
     tBooleanSection = 413,
     tBooleanFragments = 414,
     tThickSolid = 415,
     tRecombine = 416,
     tSmoother = 417,
     tSplit = 418,
     tDelete = 419,
     tCoherence = 420,
     tIntersect = 421,
     tMeshAlgorithm = 422,
     tReverseMesh = 423,
     tMeshSizeFromBoundary = 424,
     tLayers = 425,
     tScaleLast = 426,
     tHole = 427,
     tAlias = 428,
     tAliasWithOptions = 429,
     tCopyOptions = 430,
     tQuadTriAddVerts = 431,
     tQuadTriNoNewVerts = 432,
     tRecombLaterals = 433,
     tTransfQuadTri = 434,
     tText2D = 435,
     tText3D = 436,
     tInterpolationScheme = 437,
     tTime = 438,
     tCombine = 439,
     tBSpline = 440,
     tBezier = 441,
     tNurbs = 442,
     tNurbsOrder = 443,
     tNurbsKnots = 444,
     tColor = 445,
     tColorTable = 446,
     tFor = 447,
     tIn = 448,
     tEndFor = 449,
     tIf = 450,
     tElseIf = 451,
     tElse = 452,
     tEndIf = 453,
     tExit = 454,
     tAbort = 455,
     tField = 456,
     tReturn = 457,
     tCall = 458,
     tSlide = 459,
     tMacro = 460,
     tShow = 461,
     tHide = 462,
     tGetValue = 463,
     tGetStringValue = 464,
     tGetEnv = 465,
     tGetString = 466,
     tGetNumber = 467,
     tUnique = 468,
     tSetMaxTag = 469,
     tHomology = 470,
     tCohomology = 471,
     tBetti = 472,
     tExists = 473,
     tFileExists = 474,
     tGetForced = 475,
     tGetForcedStr = 476,
     tGMSH_MAJOR_VERSION = 477,
     tGMSH_MINOR_VERSION = 478,
     tGMSH_PATCH_VERSION = 479,
     tGmshExecutableName = 480,
     tSetPartition = 481,
     tNameToString = 482,
     tStringToName = 483,
     tUnsplitWindow = 484,
     tAFFECTDIVIDE = 485,
     tAFFECTTIMES = 486,
     tAFFECTMINUS = 487,
     tAFFECTPLUS = 488,
     tOR = 489,
     tAND = 490,
     tNOTEQUAL = 491,
     tEQUAL = 492,
     tGREATERGREATER = 493,
     tLESSLESS = 494,
     tGREATEROREQUAL = 495,
     tLESSOREQUAL = 496,
     UNARYPREC = 497,
     tMINUSMINUS = 498,
     tPLUSPLUS = 499
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
#define tRelocateMesh 384
#define tReorientMesh 385
#define tSetFactory 386
#define tThruSections 387
#define tWedge 388
#define tFillet 389
#define tChamfer 390
#define tPlane 391
#define tRuled 392
#define tTransfinite 393
#define tPhysical 394
#define tCompound 395
#define tPeriodic 396
#define tParent 397
#define tUsing 398
#define tPlugin 399
#define tDegenerated 400
#define tRecursive 401
#define tSewing 402
#define tRotate 403
#define tTranslate 404
#define tSymmetry 405
#define tDilate 406
#define tExtrude 407
#define tLevelset 408
#define tAffine 409
#define tBooleanUnion 410
#define tBooleanIntersection 411
#define tBooleanDifference 412
#define tBooleanSection 413
#define tBooleanFragments 414
#define tThickSolid 415
#define tRecombine 416
#define tSmoother 417
#define tSplit 418
#define tDelete 419
#define tCoherence 420
#define tIntersect 421
#define tMeshAlgorithm 422
#define tReverseMesh 423
#define tMeshSizeFromBoundary 424
#define tLayers 425
#define tScaleLast 426
#define tHole 427
#define tAlias 428
#define tAliasWithOptions 429
#define tCopyOptions 430
#define tQuadTriAddVerts 431
#define tQuadTriNoNewVerts 432
#define tRecombLaterals 433
#define tTransfQuadTri 434
#define tText2D 435
#define tText3D 436
#define tInterpolationScheme 437
#define tTime 438
#define tCombine 439
#define tBSpline 440
#define tBezier 441
#define tNurbs 442
#define tNurbsOrder 443
#define tNurbsKnots 444
#define tColor 445
#define tColorTable 446
#define tFor 447
#define tIn 448
#define tEndFor 449
#define tIf 450
#define tElseIf 451
#define tElse 452
#define tEndIf 453
#define tExit 454
#define tAbort 455
#define tField 456
#define tReturn 457
#define tCall 458
#define tSlide 459
#define tMacro 460
#define tShow 461
#define tHide 462
#define tGetValue 463
#define tGetStringValue 464
#define tGetEnv 465
#define tGetString 466
#define tGetNumber 467
#define tUnique 468
#define tSetMaxTag 469
#define tHomology 470
#define tCohomology 471
#define tBetti 472
#define tExists 473
#define tFileExists 474
#define tGetForced 475
#define tGetForcedStr 476
#define tGMSH_MAJOR_VERSION 477
#define tGMSH_MINOR_VERSION 478
#define tGMSH_PATCH_VERSION 479
#define tGmshExecutableName 480
#define tSetPartition 481
#define tNameToString 482
#define tStringToName 483
#define tUnsplitWindow 484
#define tAFFECTDIVIDE 485
#define tAFFECTTIMES 486
#define tAFFECTMINUS 487
#define tAFFECTPLUS 488
#define tOR 489
#define tAND 490
#define tNOTEQUAL 491
#define tEQUAL 492
#define tGREATERGREATER 493
#define tLESSLESS 494
#define tGREATEROREQUAL 495
#define tLESSOREQUAL 496
#define UNARYPREC 497
#define tMINUSMINUS 498
#define tPLUSPLUS 499




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
   char* val_default = NULL, int type_treat = 0);
char* treat_Struct_FullName_dot_tSTRING_String
  (char* c1, char* c2, char* c3, int index = 0,
   char* val_default = NULL, int type_treat = 0);
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
#line 771 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 784 "Gmsh.tab.cpp"

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
#define YYLAST   17958

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  267
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  635
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2266

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   499

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   252,     2,   264,     2,   249,   251,     2,
     257,   258,   247,   245,   266,   246,   263,   248,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     239,     2,   240,   234,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   259,     2,   260,   256,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,   250,   262,   265,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   235,
     236,   237,   238,   241,   242,   243,   244,   253,   254,   255
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
    1557,  1560,  1563,  1566,  1569,  1585,  1588,  1591,  1594,  1604,
    1616,  1619,  1624,  1627,  1630,  1633,  1636,  1653,  1665,  1672,
    1681,  1690,  1701,  1703,  1706,  1709,  1711,  1715,  1719,  1724,
    1729,  1731,  1733,  1739,  1751,  1765,  1766,  1774,  1775,  1789,
    1790,  1806,  1807,  1814,  1824,  1827,  1831,  1842,  1856,  1858,
    1861,  1867,  1875,  1878,  1881,  1885,  1888,  1892,  1895,  1899,
    1909,  1916,  1918,  1920,  1922,  1924,  1926,  1927,  1930,  1934,
    1938,  1943,  1953,  1958,  1973,  1974,  1978,  1979,  1981,  1982,
    1985,  1986,  1989,  1990,  1993,  2000,  2008,  2015,  2021,  2025,
    2034,  2041,  2050,  2059,  2065,  2070,  2077,  2089,  2101,  2120,
    2139,  2152,  2165,  2178,  2189,  2194,  2199,  2204,  2209,  2214,
    2217,  2221,  2228,  2230,  2232,  2234,  2237,  2243,  2251,  2262,
    2264,  2268,  2271,  2274,  2277,  2281,  2285,  2289,  2293,  2297,
    2301,  2305,  2309,  2313,  2317,  2321,  2325,  2329,  2333,  2337,
    2341,  2345,  2349,  2355,  2360,  2365,  2370,  2375,  2380,  2385,
    2390,  2395,  2400,  2405,  2412,  2417,  2422,  2427,  2432,  2437,
    2442,  2447,  2452,  2459,  2466,  2473,  2478,  2485,  2492,  2494,
    2496,  2498,  2500,  2502,  2504,  2506,  2508,  2510,  2512,  2514,
    2515,  2522,  2524,  2529,  2536,  2538,  2543,  2548,  2553,  2560,
    2566,  2574,  2583,  2594,  2599,  2604,  2611,  2616,  2620,  2623,
    2629,  2635,  2639,  2645,  2652,  2661,  2668,  2677,  2684,  2689,
    2697,  2704,  2711,  2718,  2723,  2730,  2735,  2736,  2739,  2740,
    2743,  2744,  2752,  2754,  2758,  2760,  2763,  2764,  2768,  2770,
    2773,  2776,  2780,  2784,  2796,  2806,  2814,  2822,  2824,  2828,
    2830,  2832,  2835,  2839,  2844,  2850,  2852,  2856,  2858,  2861,
    2865,  2869,  2875,  2880,  2885,  2888,  2893,  2896,  2900,  2904,
    2909,  2915,  2921,  2927,  2933,  2935,  2937,  2939,  2943,  2949,
    2957,  2962,  2967,  2972,  2979,  2986,  2995,  3004,  3009,  3024,
    3029,  3034,  3036,  3038,  3042,  3046,  3056,  3064,  3066,  3072,
    3076,  3083,  3085,  3089,  3091,  3093,  3098,  3103,  3107,  3113,
    3120,  3129,  3136,  3141,  3147,  3149,  3154,  3156,  3158,  3160,
    3162,  3167,  3174,  3179,  3186,  3192,  3200,  3205,  3210,  3215,
    3224,  3229,  3234,  3239,  3244,  3253,  3262,  3269,  3274,  3281,
    3286,  3288,  3290,  3295,  3300,  3301,  3308,  3313,  3316,  3321,
    3326,  3328,  3330,  3334,  3336,  3338,  3342,  3346,  3350,  3356,
    3364,  3370,  3376,  3385,  3387,  3389
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     268,     0,    -1,   269,    -1,     1,     6,    -1,    -1,   269,
     270,    -1,   272,    -1,   273,    -1,   294,    -1,   131,   257,
     370,   258,     6,    -1,   313,    -1,   319,    -1,   323,    -1,
     324,    -1,   325,    -1,   326,    -1,   330,    -1,   339,    -1,
     340,    -1,   346,    -1,   347,    -1,   329,    -1,   328,    -1,
     327,    -1,   322,    -1,   349,    -1,   240,    -1,   241,    -1,
      46,   257,   370,   258,     6,    -1,    48,   257,   370,   258,
       6,    -1,    47,   257,   370,   258,     6,    -1,    46,   257,
     370,   258,   271,   370,     6,    -1,    46,   257,   370,   266,
     366,   258,     6,    -1,    48,   257,   370,   266,   366,   258,
       6,    -1,    47,   257,   370,   266,   366,   258,     6,    -1,
      46,   257,   370,   266,   366,   258,   271,   370,     6,    -1,
     380,   370,   261,   274,   262,     6,    -1,   173,     4,   259,
     350,   260,     6,    -1,   174,     4,   259,   350,   260,     6,
      -1,   175,     4,   259,   350,   266,   350,   260,     6,    -1,
      -1,   274,   277,    -1,   274,   281,    -1,   274,   284,    -1,
     274,   286,    -1,   274,   287,    -1,   274,   329,    -1,   350,
      -1,   275,   266,   350,    -1,   350,    -1,   276,   266,   350,
      -1,    -1,    -1,     4,   278,   257,   275,   258,   279,   261,
     276,   262,     6,    -1,   370,    -1,   280,   266,   370,    -1,
      -1,   180,   257,   350,   266,   350,   266,   350,   258,   282,
     261,   280,   262,     6,    -1,   370,    -1,   283,   266,   370,
      -1,    -1,   181,   257,   350,   266,   350,   266,   350,   266,
     350,   258,   285,   261,   283,   262,     6,    -1,   182,   261,
     362,   262,   261,   362,   262,     6,    -1,   182,   261,   362,
     262,   261,   362,   262,   261,   362,   262,   261,   362,   262,
       6,    -1,    -1,   183,   288,   261,   276,   262,     6,    -1,
       7,    -1,   233,    -1,   232,    -1,   231,    -1,   230,    -1,
     255,    -1,   254,    -1,   257,    -1,   259,    -1,   258,    -1,
     260,    -1,     4,    -1,    36,    -1,    37,    -1,   111,    -1,
     112,    -1,    91,   259,   296,   260,     6,    -1,    92,   259,
     300,   260,     6,    -1,   355,     6,    -1,    99,   291,   371,
     266,   350,   292,     6,    -1,   101,   291,   380,   266,   371,
     292,     6,    -1,   380,   289,   363,     6,    -1,   380,   290,
       6,    -1,   380,   291,   292,   289,   363,     6,    -1,   380,
     291,   261,   366,   262,   292,   289,   363,     6,    -1,   380,
     259,   350,   260,   289,   350,     6,    -1,   380,   259,   350,
     260,   290,     6,    -1,   380,   257,   350,   258,   289,   350,
       6,    -1,   380,   257,   350,   258,   290,     6,    -1,   380,
       7,   371,     6,    -1,   380,   291,   292,     7,    49,   291,
     292,     6,    -1,   380,   291,   292,     7,    49,   291,   375,
     292,     6,    -1,   380,   291,   292,   233,    49,   291,   375,
     292,     6,    -1,   380,   263,   293,     7,   371,     6,    -1,
     380,   259,   350,   260,   263,   293,     7,   371,     6,    -1,
     380,   263,   293,   289,   350,     6,    -1,   380,   259,   350,
     260,   263,   293,   289,   350,     6,    -1,   380,   263,   293,
     290,     6,    -1,   380,   259,   350,   260,   263,   293,   290,
       6,    -1,   380,   263,   190,   263,   293,     7,   367,     6,
      -1,   380,   259,   350,   260,   263,   190,   263,   293,     7,
     367,     6,    -1,   380,   263,   191,     7,   368,     6,    -1,
     380,   259,   350,   260,   263,   191,     7,   368,     6,    -1,
     380,   201,     7,   363,     6,    -1,   201,   259,   350,   260,
       7,   293,     6,    -1,   201,   259,   350,   260,   263,   293,
       7,   350,     6,    -1,   201,   259,   350,   260,   263,   293,
       7,   371,     6,    -1,   201,   259,   350,   260,   263,   293,
       7,   261,   366,   262,     6,    -1,   201,   259,   350,   260,
     263,   293,     6,    -1,   144,   257,     4,   258,   263,   293,
       7,   350,     6,    -1,   144,   257,     4,   258,   263,   293,
       7,   371,     6,    -1,    -1,   266,    -1,    -1,   296,   295,
     380,    -1,   296,   295,   380,     7,   350,    -1,    -1,   296,
     295,   380,     7,   261,   363,   297,   302,   262,    -1,    -1,
     296,   295,   380,   291,   292,     7,   261,   363,   298,   302,
     262,    -1,   296,   295,   380,     7,   371,    -1,    -1,   296,
     295,   380,     7,   261,   371,   299,   306,   262,    -1,    -1,
     300,   295,   370,    -1,   350,     7,   371,    -1,   301,   266,
     350,     7,   371,    -1,   365,     7,   380,   257,   258,    -1,
      -1,   266,   304,    -1,    -1,   304,    -1,   305,    -1,   304,
     266,   305,    -1,     4,   363,    -1,    36,   350,    -1,    37,
     350,    -1,     4,    -1,     4,   261,   301,   262,    -1,     4,
     371,    -1,     4,   374,    -1,    -1,   266,   307,    -1,   308,
      -1,   307,   266,   308,    -1,     4,   350,    -1,     4,   371,
      -1,   205,   371,    -1,     4,   376,    -1,     4,   374,    -1,
     350,    -1,   371,    -1,   371,   266,   350,    -1,    -1,   193,
     106,   261,   350,   262,    -1,   143,   102,   261,   366,   262,
      -1,   143,   121,   261,   366,   262,    -1,    -1,   136,   360,
      -1,    -1,   143,   147,    -1,   102,   257,   350,   258,     7,
     360,     6,    -1,   105,   257,   350,   258,     7,   363,     6,
      -1,   109,   257,   350,   258,     7,   363,     6,    -1,   140,
     109,   257,   350,   258,     7,   363,   143,   350,     6,    -1,
     140,   185,   257,   350,   258,     7,   363,   143,   350,     6,
      -1,   103,   257,   350,   258,     7,   363,   311,     6,    -1,
     104,   257,   350,   258,     7,   363,   311,     6,    -1,   185,
     257,   350,   258,     7,   363,     6,    -1,   186,   257,   350,
     258,     7,   363,     6,    -1,   187,   257,   350,   258,     7,
     363,   189,   363,   188,   350,     6,    -1,   120,   257,   350,
     258,     7,   363,     6,    -1,   105,     4,   257,   350,   258,
       7,   363,     6,    -1,   136,   108,   257,   350,   258,     7,
     363,     6,    -1,   108,   257,   350,   258,     7,   363,   310,
       6,    -1,   137,   108,   257,   350,   258,     7,   363,   310,
       6,    -1,   185,   108,   257,   350,   258,     7,   363,     6,
      -1,   186,   108,   257,   350,   258,     7,   363,     6,    -1,
      13,    14,     6,    -1,    14,   108,   350,     6,    -1,   124,
     108,   257,   350,   258,     7,     5,     5,     5,     6,    -1,
     106,   257,   350,   258,     7,   363,     6,    -1,   107,   257,
     350,   258,     7,   363,     6,    -1,   111,   257,   350,   258,
       7,   363,     6,    -1,   114,   257,   350,   258,     7,   363,
       6,    -1,   118,   257,   350,   258,     7,   363,     6,    -1,
     119,   257,   350,   258,     7,   363,     6,    -1,   112,   257,
     350,   258,     7,   363,     6,    -1,   113,   257,   350,   258,
       7,   363,     6,    -1,   133,   257,   350,   258,     7,   363,
       6,    -1,   160,   257,   350,   258,     7,   363,     6,    -1,
     108,     4,   257,   350,   258,     7,   363,   312,     6,    -1,
     110,   257,   350,   258,     7,   363,     6,    -1,   132,   257,
     350,   258,     7,   363,     6,    -1,   137,   132,   257,   350,
     258,     7,   363,     6,    -1,   140,   316,   257,   350,   258,
       7,   363,     6,    -1,   140,   316,   257,   350,   258,     7,
     363,     4,   261,   362,   262,     6,    -1,    -1,   139,   315,
     314,   257,   309,   258,   289,   363,     6,    -1,   102,    -1,
     105,    -1,   108,    -1,   110,    -1,   121,   261,   350,   262,
      -1,   105,    -1,   108,    -1,   110,    -1,   121,   261,   350,
     262,    -1,   105,    -1,   108,    -1,   121,   261,   350,   262,
      -1,   102,    -1,   105,    -1,   108,    -1,   121,   261,   350,
     262,    -1,   149,   360,   261,   320,   262,    -1,   148,   261,
     360,   266,   360,   266,   350,   262,   261,   320,   262,    -1,
     150,   360,   261,   320,   262,    -1,   151,   261,   360,   266,
     350,   262,   261,   320,   262,    -1,   151,   261,   360,   266,
     360,   262,   261,   320,   262,    -1,   154,   261,   366,   262,
     261,   320,   262,    -1,     4,   261,   320,   262,    -1,   166,
     105,   261,   366,   262,   108,   261,   350,   262,    -1,   163,
     105,   261,   350,   262,   102,   261,   366,   262,     6,    -1,
     163,   105,   257,   350,   258,   261,   366,   262,     6,    -1,
     321,    -1,   319,    -1,    -1,   321,   313,    -1,   321,   315,
     261,   366,   262,     6,    -1,   321,   139,   315,   261,   366,
     262,     6,    -1,   321,   142,   315,   261,   366,   262,     6,
      -1,   321,   315,   261,     8,   262,     6,    -1,   321,   139,
     315,   261,     8,   262,     6,    -1,   153,   136,   257,   350,
     258,     7,   363,     6,    -1,   153,   102,   257,   350,   258,
       7,   261,   362,   262,     6,    -1,   153,   136,   257,   350,
     258,     7,   261,   360,   266,   360,   266,   366,   262,     6,
      -1,   153,   136,   257,   350,   258,     7,   261,   360,   266,
     360,   266,   360,   266,   366,   262,     6,    -1,   153,   106,
     257,   350,   258,     7,   261,   360,   266,   366,   262,     6,
      -1,   153,   112,   257,   350,   258,     7,   261,   360,   266,
     360,   266,   366,   262,     6,    -1,   153,   113,   257,   350,
     258,     7,   261,   360,   266,   360,   266,   366,   262,     6,
      -1,   153,   115,   257,   350,   258,     7,   261,   360,   266,
     360,   266,   366,   262,     6,    -1,   153,   116,   257,   350,
     258,     7,   261,   360,   266,   360,   266,   366,   262,     6,
      -1,   153,     4,   257,   350,   258,     7,   363,     6,    -1,
     153,     4,   257,   350,   258,     7,     5,     6,    -1,   153,
       4,   261,   350,   262,     6,    -1,   164,   261,   321,   262,
      -1,   146,   164,   261,   321,   262,    -1,   164,     4,   261,
     321,   262,    -1,   164,   201,   259,   350,   260,     6,    -1,
     164,     4,   259,   350,   260,     6,    -1,   164,   380,     6,
      -1,   164,     4,     4,     6,    -1,   164,    94,     6,    -1,
     190,   367,   261,   321,   262,    -1,   146,   190,   367,   261,
     321,   262,    -1,   226,   350,   261,   321,   262,    -1,   206,
     261,     8,   262,    -1,   206,     5,     6,    -1,   207,   261,
       8,   262,    -1,   207,     5,     6,    -1,   206,   261,   321,
     262,    -1,   146,   206,   261,   321,   262,    -1,   207,   261,
     321,   262,    -1,   146,   207,   261,   321,   262,    -1,   380,
     371,     6,    -1,    80,   257,   377,   258,     6,    -1,   380,
     380,   259,   350,   260,   370,     6,    -1,   380,   380,   380,
     259,   350,   260,     6,    -1,   380,   350,     6,    -1,   229,
       6,    -1,   144,   257,     4,   258,   263,     4,     6,    -1,
     184,     4,     6,    -1,   199,     6,    -1,   200,     6,    -1,
      74,     6,    -1,    75,     6,    -1,    67,     6,    -1,    67,
     261,   350,   266,   350,   266,   350,   266,   350,   266,   350,
     266,   350,   262,     6,    -1,    68,     6,    -1,    69,     6,
      -1,    85,     6,    -1,    87,   261,   350,   266,   350,   266,
     350,   262,     6,    -1,    87,   261,   350,   266,   350,   266,
     350,   266,   350,   262,     6,    -1,    86,     6,    -1,    86,
     261,   321,   262,    -1,    88,     6,    -1,    89,     6,    -1,
     126,     6,    -1,   127,     6,    -1,   128,   261,   366,   262,
     261,   366,   262,   261,   362,   262,   261,   350,   266,   350,
     262,     6,    -1,   204,   257,   261,   366,   262,   266,   371,
     266,   371,   258,     6,    -1,   192,   257,   350,     8,   350,
     258,    -1,   192,   257,   350,     8,   350,     8,   350,   258,
      -1,   192,     4,   193,   261,   350,     8,   350,   262,    -1,
     192,     4,   193,   261,   350,     8,   350,     8,   350,   262,
      -1,   194,    -1,   205,     4,    -1,   205,   371,    -1,   202,
      -1,   203,   380,     6,    -1,   203,   371,     6,    -1,   195,
     257,   350,   258,    -1,   196,   257,   350,   258,    -1,   197,
      -1,   198,    -1,   152,   360,   261,   321,   262,    -1,   152,
     261,   360,   266,   360,   266,   350,   262,   261,   321,   262,
      -1,   152,   261,   360,   266,   360,   266,   360,   266,   350,
     262,   261,   321,   262,    -1,    -1,   152,   360,   261,   321,
     331,   335,   262,    -1,    -1,   152,   261,   360,   266,   360,
     266,   350,   262,   261,   321,   332,   335,   262,    -1,    -1,
     152,   261,   360,   266,   360,   266,   360,   266,   350,   262,
     261,   321,   333,   335,   262,    -1,    -1,   152,   261,   321,
     334,   335,   262,    -1,   152,   261,   321,   262,   143,   120,
     261,   350,   262,    -1,   132,   363,    -1,   137,   132,   363,
      -1,   134,   261,   366,   262,   261,   366,   262,   261,   366,
     262,    -1,   135,   261,   366,   262,   261,   366,   262,   261,
     366,   262,   261,   366,   262,    -1,   336,    -1,   335,   336,
      -1,   170,   261,   350,   262,     6,    -1,   170,   261,   363,
     266,   363,   262,     6,    -1,   171,     6,    -1,   161,     6,
      -1,   161,   350,     6,    -1,   176,     6,    -1,   176,   178,
       6,    -1,   177,     6,    -1,   177,   178,     6,    -1,   172,
     257,   350,   258,     7,   363,   143,   350,     6,    -1,   143,
       4,   259,   350,   260,     6,    -1,   155,    -1,   156,    -1,
     157,    -1,   158,    -1,   159,    -1,    -1,   164,     6,    -1,
     146,   164,     6,    -1,   164,   350,     6,    -1,   146,   164,
     350,     6,    -1,   337,   261,   321,   338,   262,   261,   321,
     338,   262,    -1,   117,   257,   370,   258,    -1,   337,   257,
     350,   258,     7,   261,   321,   338,   262,   261,   321,   338,
     262,     6,    -1,    -1,   143,     4,   350,    -1,    -1,     4,
      -1,    -1,     7,   363,    -1,    -1,     7,   350,    -1,    -1,
     154,   363,    -1,   122,   123,   364,     7,   350,     6,    -1,
     138,   105,   364,     7,   350,   341,     6,    -1,   138,   108,
     364,   343,   342,     6,    -1,   138,   110,   364,   343,     6,
      -1,   179,   364,     6,    -1,   100,   315,   257,   350,   266,
     350,   258,     6,    -1,   214,   315,   257,   350,   258,     6,
      -1,   167,   108,   261,   366,   262,     7,   350,     6,    -1,
     169,   108,   261,   366,   262,     7,   350,     6,    -1,   161,
     108,   364,   344,     6,    -1,   161,   110,   364,     6,    -1,
     162,   108,   364,     7,   350,     6,    -1,   141,   105,   261,
     366,   262,     7,   261,   366,   262,   345,     6,    -1,   141,
     108,   261,   366,   262,     7,   261,   366,   262,   345,     6,
      -1,   141,   105,   261,   366,   262,     7,   261,   366,   262,
     148,   261,   360,   266,   360,   266,   350,   262,     6,    -1,
     141,   108,   261,   366,   262,     7,   261,   366,   262,   148,
     261,   360,   266,   360,   266,   350,   262,     6,    -1,   141,
     105,   261,   366,   262,     7,   261,   366,   262,   149,   360,
       6,    -1,   141,   108,   261,   366,   262,     7,   261,   366,
     262,   149,   360,     6,    -1,   141,   108,   350,   261,   366,
     262,     7,   350,   261,   366,   262,     6,    -1,   315,   261,
     366,   262,   193,   315,   261,   350,   262,     6,    -1,   168,
     317,   364,     6,    -1,   129,   318,   364,     6,    -1,   130,
     110,   363,     6,    -1,   145,   105,   363,     6,    -1,   140,
     316,   363,     6,    -1,   165,     6,    -1,   165,     4,     6,
      -1,   165,   102,   261,   366,   262,     6,    -1,   215,    -1,
     216,    -1,   217,    -1,   348,     6,    -1,   348,   261,   363,
     262,     6,    -1,   348,   261,   363,   266,   363,   262,     6,
      -1,   348,   257,   363,   258,   261,   363,   266,   363,   262,
       6,    -1,   351,    -1,   257,   350,   258,    -1,   246,   350,
      -1,   245,   350,    -1,   252,   350,    -1,   350,   246,   350,
      -1,   350,   245,   350,    -1,   350,   247,   350,    -1,   350,
     248,   350,    -1,   350,   250,   350,    -1,   350,   251,   350,
      -1,   350,   249,   350,    -1,   350,   256,   350,    -1,   350,
     239,   350,    -1,   350,   240,   350,    -1,   350,   244,   350,
      -1,   350,   243,   350,    -1,   350,   238,   350,    -1,   350,
     237,   350,    -1,   350,   236,   350,    -1,   350,   235,   350,
      -1,   350,   241,   350,    -1,   350,   242,   350,    -1,   350,
     234,   350,     8,   350,    -1,    16,   291,   350,   292,    -1,
      17,   291,   350,   292,    -1,    18,   291,   350,   292,    -1,
      19,   291,   350,   292,    -1,    20,   291,   350,   292,    -1,
      21,   291,   350,   292,    -1,    22,   291,   350,   292,    -1,
      23,   291,   350,   292,    -1,    24,   291,   350,   292,    -1,
      26,   291,   350,   292,    -1,    27,   291,   350,   266,   350,
     292,    -1,    28,   291,   350,   292,    -1,    29,   291,   350,
     292,    -1,    30,   291,   350,   292,    -1,    31,   291,   350,
     292,    -1,    32,   291,   350,   292,    -1,    33,   291,   350,
     292,    -1,    34,   291,   350,   292,    -1,    35,   291,   350,
     292,    -1,    38,   291,   350,   266,   350,   292,    -1,    39,
     291,   350,   266,   350,   292,    -1,    40,   291,   350,   266,
     350,   292,    -1,    25,   291,   350,   292,    -1,    37,   291,
     350,   266,   350,   292,    -1,    36,   291,   350,   266,   350,
     292,    -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,
      12,    -1,   222,    -1,   223,    -1,   224,    -1,    82,    -1,
      83,    -1,    84,    -1,    -1,    93,   291,   350,   352,   302,
     292,    -1,   355,    -1,   212,   291,   370,   292,    -1,   212,
     291,   370,   266,   350,   292,    -1,   357,    -1,   380,   259,
     350,   260,    -1,   380,   257,   350,   258,    -1,   218,   257,
     357,   258,    -1,   218,   257,   357,   263,   293,   258,    -1,
     220,   257,   357,   353,   258,    -1,   220,   257,   357,   263,
     293,   353,   258,    -1,   220,   257,   357,   291,   350,   292,
     353,   258,    -1,   220,   257,   357,   263,   293,   291,   350,
     292,   353,   258,    -1,   219,   257,   371,   258,    -1,   264,
     380,   291,   292,    -1,   264,   357,   263,   293,   291,   292,
      -1,    96,   291,   380,   292,    -1,    96,   291,   292,    -1,
     380,   290,    -1,   380,   259,   350,   260,   290,    -1,   380,
     257,   350,   258,   290,    -1,   380,   263,   293,    -1,   380,
       9,   380,   263,   293,    -1,   380,   263,   293,   257,   350,
     258,    -1,   380,     9,   380,   263,   293,   257,   350,   258,
      -1,   380,   263,   293,   259,   350,   260,    -1,   380,     9,
     380,   263,   293,   259,   350,   260,    -1,   380,   259,   350,
     260,   263,   293,    -1,   380,   263,   293,   290,    -1,   380,
     259,   350,   260,   263,   293,   290,    -1,   208,   257,   370,
     266,   350,   258,    -1,    59,   257,   363,   266,   363,   258,
      -1,    60,   291,   370,   266,   370,   292,    -1,    58,   291,
     370,   292,    -1,    61,   291,   370,   266,   370,   292,    -1,
      66,   257,   377,   258,    -1,    -1,   266,   350,    -1,    -1,
     266,   370,    -1,    -1,    94,   357,   359,   356,   259,   303,
     260,    -1,   380,    -1,   380,     9,   380,    -1,    97,    -1,
      97,   350,    -1,    -1,   257,   358,   258,    -1,   361,    -1,
     246,   360,    -1,   245,   360,    -1,   360,   246,   360,    -1,
     360,   245,   360,    -1,   261,   350,   266,   350,   266,   350,
     266,   350,   266,   350,   262,    -1,   261,   350,   266,   350,
     266,   350,   266,   350,   262,    -1,   261,   350,   266,   350,
     266,   350,   262,    -1,   257,   350,   266,   350,   266,   350,
     258,    -1,   363,    -1,   362,   266,   363,    -1,   350,    -1,
     365,    -1,   261,   262,    -1,   261,   366,   262,    -1,   246,
     261,   366,   262,    -1,   350,   247,   261,   366,   262,    -1,
     363,    -1,   261,     8,   262,    -1,     5,    -1,   246,   365,
      -1,   350,   247,   365,    -1,   350,     8,   350,    -1,   350,
       8,   350,     8,   350,    -1,   102,   261,   350,   262,    -1,
     102,   261,     8,   262,    -1,   102,     5,    -1,   316,   261,
       8,   262,    -1,   316,     5,    -1,   139,   315,   364,    -1,
     142,   315,   363,    -1,   315,   193,    67,   363,    -1,    67,
     315,   261,   366,   262,    -1,    76,   316,   261,   350,   262,
      -1,    77,   316,   261,   350,   262,    -1,    78,   316,   261,
     350,   262,    -1,   319,    -1,   330,    -1,   339,    -1,   380,
     291,   292,    -1,   380,   263,   293,   291,   292,    -1,   380,
       9,   380,   263,   293,   291,   292,    -1,    41,   259,   380,
     260,    -1,    41,   259,   365,   260,    -1,    41,   257,   365,
     258,    -1,    41,   291,   261,   366,   262,   292,    -1,   380,
     291,   261,   366,   262,   292,    -1,    42,   291,   350,   266,
     350,   266,   350,   292,    -1,    43,   291,   350,   266,   350,
     266,   350,   292,    -1,    44,   291,   370,   292,    -1,    45,
     291,   350,   266,   350,   266,   350,   266,   350,   266,   350,
     266,   350,   292,    -1,   213,   291,   365,   292,    -1,    32,
     291,   365,   292,    -1,   350,    -1,   365,    -1,   366,   266,
     350,    -1,   366,   266,   365,    -1,   261,   350,   266,   350,
     266,   350,   266,   350,   262,    -1,   261,   350,   266,   350,
     266,   350,   262,    -1,   380,    -1,     4,   263,   190,   263,
       4,    -1,   261,   369,   262,    -1,   380,   259,   350,   260,
     263,   191,    -1,   367,    -1,   369,   266,   367,    -1,   371,
      -1,   380,    -1,   380,   259,   350,   260,    -1,   380,   257,
     350,   258,    -1,   380,   263,   293,    -1,   380,     9,   380,
     263,   293,    -1,   380,   263,   293,   257,   350,   258,    -1,
     380,     9,   380,   263,   293,   257,   350,   258,    -1,   380,
     259,   350,   260,   263,     4,    -1,   315,   261,   350,   262,
      -1,   139,   315,   261,   350,   262,    -1,     5,    -1,   227,
     259,   380,   260,    -1,    70,    -1,   225,    -1,    79,    -1,
      81,    -1,   210,   257,   370,   258,    -1,   209,   257,   370,
     266,   370,   258,    -1,   211,   291,   370,   292,    -1,   211,
     291,   370,   266,   370,   292,    -1,   221,   257,   357,   354,
     258,    -1,   221,   257,   357,   263,   293,   354,   258,    -1,
      51,   291,   377,   292,    -1,    52,   257,   370,   258,    -1,
      53,   257,   370,   258,    -1,    54,   257,   370,   266,   370,
     266,   370,   258,    -1,    49,   291,   377,   292,    -1,    63,
     291,   370,   292,    -1,    64,   291,   370,   292,    -1,    65,
     291,   370,   292,    -1,    62,   291,   350,   266,   370,   266,
     370,   292,    -1,    57,   291,   370,   266,   350,   266,   350,
     292,    -1,    57,   291,   370,   266,   350,   292,    -1,    50,
     291,   370,   292,    -1,    50,   291,   370,   266,   366,   292,
      -1,    71,   291,   370,   292,    -1,    72,    -1,    73,    -1,
      56,   291,   370,   292,    -1,    55,   291,   370,   292,    -1,
      -1,    98,   291,   371,   372,   306,   292,    -1,    95,   291,
     373,   292,    -1,   264,   350,    -1,   380,     9,   264,   350,
      -1,    49,   291,   376,   292,    -1,   377,    -1,   376,    -1,
     261,   377,   262,    -1,   370,    -1,   378,    -1,   377,   266,
     370,    -1,   377,   266,   378,    -1,   380,   257,   258,    -1,
     380,   263,   293,   257,   258,    -1,   380,     9,   380,   263,
     293,   257,   258,    -1,     4,   265,   261,   350,   262,    -1,
     379,   265,   261,   350,   262,    -1,   228,   259,   370,   260,
     265,   261,   350,   262,    -1,     4,    -1,   379,    -1,   228,
     259,   370,   260,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   275,   275,   276,   281,   283,   287,   288,   289,   290,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   328,   332,   339,   344,
     349,   354,   368,   381,   394,   407,   435,   449,   462,   475,
     494,   499,   500,   501,   502,   503,   504,   508,   510,   515,
     517,   523,   627,   522,   645,   652,   663,   662,   680,   687,
     698,   697,   714,   731,   754,   753,   767,   768,   769,   770,
     771,   775,   776,   782,   782,   784,   784,   789,   790,   791,
     792,   793,   799,   800,   801,   802,   807,   813,   875,   890,
     919,   929,   934,   942,   947,   955,   964,   969,   981,   998,
    1004,  1013,  1031,  1049,  1058,  1070,  1075,  1083,  1103,  1126,
    1146,  1154,  1176,  1199,  1237,  1258,  1270,  1284,  1284,  1286,
    1288,  1297,  1307,  1306,  1327,  1326,  1344,  1354,  1353,  1367,
    1369,  1377,  1383,  1388,  1415,  1417,  1420,  1422,  1426,  1427,
    1431,  1443,  1447,  1451,  1464,  1478,  1486,  1499,  1501,  1505,
    1506,  1511,  1519,  1528,  1536,  1550,  1568,  1572,  1579,  1588,
    1591,  1597,  1601,  1613,  1616,  1623,  1626,  1632,  1655,  1671,
    1687,  1704,  1721,  1758,  1802,  1818,  1834,  1866,  1882,  1899,
    1915,  1965,  1983,  2004,  2025,  2031,  2037,  2044,  2075,  2090,
    2112,  2135,  2158,  2181,  2205,  2229,  2253,  2279,  2296,  2312,
    2330,  2348,  2360,  2374,  2373,  2403,  2405,  2407,  2409,  2411,
    2419,  2421,  2423,  2425,  2433,  2435,  2437,  2445,  2447,  2449,
    2451,  2461,  2477,  2493,  2509,  2525,  2541,  2558,  2595,  2616,
    2637,  2663,  2664,  2669,  2672,  2676,  2693,  2713,  2733,  2752,
    2779,  2798,  2819,  2834,  2850,  2868,  2919,  2940,  2962,  2985,
    3090,  3106,  3141,  3163,  3185,  3197,  3203,  3218,  3249,  3261,
    3270,  3277,  3289,  3309,  3313,  3318,  3322,  3327,  3334,  3341,
    3348,  3360,  3433,  3451,  3476,  3491,  3540,  3546,  3558,  3590,
    3594,  3599,  3606,  3611,  3621,  3626,  3632,  3640,  3648,  3652,
    3656,  3660,  3667,  3671,  3675,  3687,  3696,  3760,  3776,  3793,
    3810,  3832,  3854,  3889,  3897,  3905,  3911,  3918,  3925,  3945,
    3971,  3983,  3994,  4012,  4030,  4049,  4048,  4073,  4072,  4099,
    4098,  4123,  4122,  4145,  4161,  4178,  4195,  4218,  4246,  4249,
    4255,  4267,  4287,  4291,  4295,  4299,  4303,  4307,  4311,  4315,
    4324,  4337,  4338,  4339,  4340,  4341,  4345,  4346,  4347,  4348,
    4349,  4352,  4376,  4395,  4418,  4421,  4437,  4440,  4457,  4460,
    4466,  4469,  4476,  4479,  4486,  4508,  4549,  4593,  4632,  4657,
    4670,  4681,  4698,  4715,  4745,  4771,  4797,  4829,  4856,  4882,
    4908,  4934,  4960,  4982,  4993,  5041,  5095,  5110,  5122,  5133,
    5140,  5155,  5169,  5170,  5171,  5175,  5181,  5193,  5211,  5239,
    5240,  5241,  5242,  5243,  5244,  5245,  5246,  5247,  5254,  5255,
    5256,  5257,  5258,  5259,  5260,  5261,  5262,  5263,  5264,  5265,
    5266,  5267,  5268,  5269,  5270,  5271,  5272,  5273,  5274,  5275,
    5276,  5277,  5278,  5279,  5280,  5281,  5282,  5283,  5284,  5285,
    5286,  5287,  5288,  5289,  5290,  5291,  5292,  5293,  5302,  5303,
    5304,  5305,  5306,  5307,  5308,  5309,  5310,  5311,  5312,  5317,
    5316,  5324,  5328,  5333,  5338,  5342,  5347,  5352,  5356,  5360,
    5364,  5368,  5372,  5376,  5382,  5397,  5401,  5407,  5412,  5431,
    5451,  5472,  5476,  5480,  5484,  5488,  5492,  5496,  5501,  5511,
    5521,  5526,  5537,  5546,  5551,  5556,  5584,  5585,  5591,  5592,
    5598,  5597,  5620,  5622,  5627,  5629,  5635,  5636,  5641,  5645,
    5649,  5653,  5657,  5664,  5668,  5672,  5676,  5683,  5688,  5695,
    5700,  5704,  5709,  5713,  5721,  5732,  5736,  5740,  5754,  5762,
    5770,  5777,  5787,  5810,  5815,  5821,  5826,  5832,  5843,  5849,
    5863,  5869,  5881,  5895,  5908,  5918,  5928,  5938,  5950,  5954,
    5959,  5971,  5975,  5979,  5983,  6001,  6009,  6017,  6046,  6056,
    6072,  6083,  6088,  6092,  6096,  6108,  6112,  6124,  6141,  6151,
    6155,  6170,  6175,  6182,  6186,  6191,  6205,  6219,  6223,  6227,
    6231,  6235,  6243,  6249,  6258,  6262,  6266,  6274,  6280,  6286,
    6290,  6297,  6305,  6312,  6321,  6325,  6329,  6344,  6358,  6372,
    6384,  6400,  6409,  6418,  6428,  6439,  6447,  6455,  6459,  6478,
    6485,  6491,  6497,  6504,  6512,  6511,  6521,  6545,  6547,  6553,
    6558,  6560,  6565,  6570,  6575,  6577,  6581,  6593,  6607,  6611,
    6618,  6626,  6634,  6645,  6647,  6650
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
  "tRelocateMesh", "tReorientMesh", "tSetFactory", "tThruSections",
  "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled", "tTransfinite",
  "tPhysical", "tCompound", "tPeriodic", "tParent", "tUsing", "tPlugin",
  "tDegenerated", "tRecursive", "tSewing", "tRotate", "tTranslate",
  "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
  "tBooleanUnion", "tBooleanIntersection", "tBooleanDifference",
  "tBooleanSection", "tBooleanFragments", "tThickSolid", "tRecombine",
  "tSmoother", "tSplit", "tDelete", "tCoherence", "tIntersect",
  "tMeshAlgorithm", "tReverseMesh", "tMeshSizeFromBoundary", "tLayers",
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
     485,   486,   487,   488,    63,   489,   490,   491,   492,    60,
      62,   493,   494,   495,   496,    43,    45,    42,    47,    37,
     124,    38,    33,   497,   498,   499,    94,    40,    41,    91,
      93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   267,   268,   268,   269,   269,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   271,   271,   272,   272,
     272,   272,   272,   272,   272,   272,   273,   273,   273,   273,
     274,   274,   274,   274,   274,   274,   274,   275,   275,   276,
     276,   278,   279,   277,   280,   280,   282,   281,   283,   283,
     285,   284,   286,   286,   288,   287,   289,   289,   289,   289,
     289,   290,   290,   291,   291,   292,   292,   293,   293,   293,
     293,   293,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   295,   295,   296,
     296,   296,   297,   296,   298,   296,   296,   299,   296,   300,
     300,   301,   301,   301,   302,   302,   303,   303,   304,   304,
     305,   305,   305,   305,   305,   305,   305,   306,   306,   307,
     307,   308,   308,   308,   308,   308,   309,   309,   309,   310,
     310,   310,   310,   311,   311,   312,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   314,   313,   315,   315,   315,   315,   315,
     316,   316,   316,   316,   317,   317,   317,   318,   318,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   320,   320,   321,   321,   321,   321,   321,   321,   321,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   323,   323,   323,   323,   323,   323,   323,   323,
     324,   324,   325,   326,   326,   326,   326,   326,   326,   326,
     326,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   330,   330,   330,   331,   330,   332,   330,   333,
     330,   334,   330,   330,   330,   330,   330,   330,   335,   335,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   337,   337,   337,   337,   337,   338,   338,   338,   338,
     338,   339,   339,   340,   341,   341,   342,   342,   343,   343,
     344,   344,   345,   345,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   347,
     347,   347,   348,   348,   348,   349,   349,   349,   349,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   352,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   353,   353,   354,   354,
     356,   355,   357,   357,   358,   358,   359,   359,   360,   360,
     360,   360,   360,   361,   361,   361,   361,   362,   362,   363,
     363,   363,   363,   363,   363,   364,   364,   364,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   366,   366,   366,   366,   367,   367,   367,   367,   368,
     368,   369,   369,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   372,   371,   371,   373,   373,   374,
     375,   375,   376,   377,   377,   377,   377,   378,   378,   378,
     379,   379,   379,   380,   380,   380
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
       2,     2,     2,     2,    15,     2,     2,     2,     9,    11,
       2,     4,     2,     2,     2,     2,    16,    11,     6,     8,
       8,    10,     1,     2,     2,     1,     3,     3,     4,     4,
       1,     1,     5,    11,    13,     0,     7,     0,    13,     0,
      15,     0,     6,     9,     2,     3,    10,    13,     1,     2,
       5,     7,     2,     2,     3,     2,     3,     2,     3,     9,
       6,     1,     1,     1,     1,     1,     0,     2,     3,     3,
       4,     9,     4,    14,     0,     3,     0,     1,     0,     2,
       0,     2,     0,     2,     6,     7,     6,     5,     3,     8,
       6,     8,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     6,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     1,     4,     6,     1,     4,     4,     4,     6,     5,
       7,     8,    10,     4,     4,     6,     4,     3,     2,     5,
       5,     3,     5,     6,     8,     6,     8,     6,     4,     7,
       6,     6,     6,     4,     6,     4,     0,     2,     0,     2,
       0,     7,     1,     3,     1,     2,     0,     3,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     3,     1,     2,     3,
       3,     5,     4,     4,     2,     4,     2,     3,     3,     4,
       5,     5,     5,     5,     1,     1,     1,     3,     5,     7,
       4,     4,     4,     6,     6,     8,     8,     4,    14,     4,
       4,     1,     1,     3,     3,     9,     7,     1,     5,     3,
       6,     1,     3,     1,     1,     4,     4,     3,     5,     6,
       8,     6,     4,     5,     1,     4,     1,     1,     1,     1,
       4,     6,     4,     6,     5,     7,     4,     4,     4,     8,
       4,     4,     4,     4,     8,     8,     6,     4,     6,     4,
       1,     1,     4,     4,     0,     6,     4,     2,     4,     4,
       1,     1,     3,     1,     1,     3,     3,     3,     5,     7,
       5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   633,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,     0,     0,   207,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   341,   342,   343,   344,   345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,   310,   311,     0,     0,     0,   305,     0,
       0,     0,     0,     0,     0,   392,   393,   394,     0,     0,
       0,     5,     6,     7,     8,    10,     0,    11,    24,    12,
      13,    14,    15,    23,    22,    21,    16,     0,    17,    18,
      19,    20,     0,    25,     0,   634,     0,   233,     0,     0,
       0,     0,     0,     0,   283,     0,   285,   286,   281,   282,
       0,   287,   290,   233,     0,   292,   293,   119,   129,   633,
     506,   502,    73,    74,     0,   205,   206,   207,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,     0,   217,   218,   219,     0,
       0,     0,     0,   448,   449,   451,   452,   450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   456,   457,   458,
       0,     0,   205,   210,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,   454,   455,
       0,     0,     0,     0,     0,     0,     0,     0,   544,   545,
       0,   546,   519,   399,   461,   464,   324,   520,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   210,
     211,     0,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     508,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   633,
       0,     0,   233,     0,     0,   389,     0,     0,     0,   214,
     215,     0,     0,     0,     0,     0,     0,   527,     0,     0,
     525,     0,     0,     0,     0,     0,     0,     0,   633,     0,
       0,   567,     0,     0,     0,     0,   279,   280,     0,   584,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,     0,   610,   611,   588,   589,     0,
       0,     0,     0,     0,     0,   587,     0,     0,     0,     0,
     303,   304,     0,   233,     0,   233,     0,     0,     0,     0,
     502,     0,   276,     0,     0,   233,   395,     0,     0,    84,
       0,    66,     0,     0,    70,    69,    68,    67,    72,    71,
      73,    74,     0,     0,     0,     0,     0,     0,     0,   573,
     502,     0,   232,     0,   231,     0,   184,     0,     0,   573,
     574,     0,     0,     0,   623,     0,   624,   574,     0,     0,
     117,   117,     0,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   561,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   534,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   402,     0,   401,   528,   403,     0,   521,
       0,     0,   502,     0,   536,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
     478,     0,     0,     0,     0,     0,     0,     0,   325,     0,
     358,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,   233,   233,     0,   510,   509,
       0,     0,     0,     0,   233,   233,     0,     0,     0,     0,
     321,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   360,     0,     0,     0,     0,     0,
       0,   233,   259,     0,     0,   257,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   368,   278,
       0,     0,     0,     0,     0,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   307,   306,     0,   264,     0,     0,
     266,     0,     0,     0,     0,   401,     0,   233,     0,     0,
       0,     0,     0,     0,     0,   346,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,    88,    75,    76,     0,     0,     0,   275,
      40,   271,     0,     0,     0,     0,     0,   227,     0,     0,
       0,     0,     0,   234,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,     0,     0,   118,     0,     0,     0,
     504,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   352,     0,     0,     0,   209,     0,     0,     0,
       0,     0,     0,   385,   386,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   502,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     459,   477,     0,     0,     0,     0,   537,   538,     0,     0,
       0,     0,     0,   496,     0,   400,   522,     0,     0,     0,
       0,   530,     0,   419,   418,   417,   416,   412,   413,   420,
     421,   415,   414,   405,   404,     0,   406,   529,   407,   410,
     408,   409,   411,   503,     0,     0,   481,     0,   547,     0,
       0,     0,     0,     0,     0,     0,     0,   356,     0,     0,
       0,     0,     0,     0,   388,     0,     0,     0,     0,   387,
       0,   233,     0,     0,     0,     0,     0,   512,   511,     0,
       0,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     374,     0,     0,     0,   258,     0,     0,     0,   252,     0,
       0,     0,     0,   384,     0,     0,     0,     0,   400,   526,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     308,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,     0,     0,     0,   498,     0,     0,   263,   267,   265,
     269,     0,     0,   406,     0,   503,   481,   635,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
     400,     0,     0,     0,    66,     0,     0,    87,     0,    66,
      67,     0,     0,     0,   503,     0,     0,   481,     0,     0,
       0,   203,     0,     0,     0,   630,    28,    26,    27,     0,
       0,     0,     0,     0,   577,    30,     0,    29,     0,     0,
     272,   625,   626,     0,   627,   577,     0,    82,   120,    83,
     130,   505,   507,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,   564,
     220,     9,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   445,   432,     0,   434,   435,   436,   437,   438,   560,
     439,   440,   441,     0,     0,     0,     0,     0,   552,   551,
     550,     0,     0,     0,   557,     0,   493,     0,     0,     0,
     495,     0,     0,     0,     0,   134,   476,   533,   532,   213,
       0,     0,   462,   559,   467,     0,   473,     0,     0,     0,
       0,   523,     0,     0,   474,   539,   535,     0,     0,     0,
       0,   466,   465,    73,    74,   488,     0,     0,     0,     0,
       0,     0,     0,   400,   354,   359,   357,     0,   367,     0,
     156,   157,     0,   213,     0,   400,     0,     0,     0,     0,
     253,     0,   268,   270,     0,     0,     0,   221,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     328,     0,   312,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,   361,   373,     0,     0,     0,
       0,   254,     0,     0,     0,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,     0,
       0,     0,     0,   600,     0,   607,   596,   597,   598,     0,
     613,   612,     0,     0,   601,   602,   603,   609,   617,   616,
       0,   147,     0,   590,     0,   592,     0,     0,     0,   585,
       0,     0,   262,     0,     0,     0,     0,     0,     0,     0,
     347,     0,     0,     0,   396,     0,   631,     0,   109,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,   582,    51,     0,     0,
       0,    64,     0,    41,    42,    43,    44,    45,    46,     0,
     466,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   576,   575,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   137,
     138,     0,     0,     0,     0,   163,   163,     0,     0,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   364,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   540,   541,
     542,   543,     0,     0,     0,     0,     0,   496,   497,     0,
     469,     0,     0,   531,   422,   524,   482,   480,     0,   479,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   366,     0,     0,     0,     0,     0,     0,     0,
       0,    77,     0,   261,     0,     0,     0,     0,     0,     0,
       0,   333,     0,     0,   332,     0,   335,     0,   337,     0,
     322,   329,     0,     0,     0,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   375,     0,     0,   256,   255,
     391,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,   568,     0,     0,     0,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   498,   499,
     594,     0,   370,   482,     0,     0,   233,   348,     0,   349,
     233,     0,     0,   583,     0,    94,     0,     0,     0,     0,
      92,     0,   571,     0,   107,     0,    99,   101,     0,     0,
       0,    89,     0,     0,     0,     0,     0,    36,   482,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,   578,     0,     0,    34,    33,     0,
     578,   628,     0,     0,   121,   126,     0,     0,     0,   140,
     145,   146,   141,   142,   501,     0,    85,     0,    86,   167,
       0,     0,     0,     0,   168,   187,   188,   165,     0,     0,
       0,   169,   198,   189,   193,   194,   190,   191,   192,   177,
       0,     0,   433,   447,   446,   442,   443,   444,   553,     0,
       0,     0,   491,   492,   494,   135,   460,   490,   463,   468,
       0,     0,   496,   199,   475,    73,    74,     0,   487,   483,
     485,   554,   195,     0,     0,     0,   159,     0,     0,   365,
       0,   158,     0,     0,     0,     0,     0,     0,   277,     0,
       0,     0,     0,   233,   233,     0,     0,   334,   519,     0,
       0,   336,   338,     0,     0,   316,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   196,     0,     0,
       0,     0,     0,     0,     0,   174,     0,   175,     0,     0,
       0,     0,   110,   114,     0,   608,     0,     0,   606,     0,
     618,     0,     0,   148,   149,   615,   591,   593,     0,     0,
       0,     0,     0,     0,   346,   350,   346,     0,   397,    93,
       0,     0,    66,     0,     0,    91,     0,   569,     0,     0,
       0,     0,     0,     0,   621,   620,     0,     0,     0,     0,
       0,   517,     0,     0,    77,   273,   483,   274,     0,     0,
       0,     0,     0,   238,   235,     0,     0,   581,   579,     0,
       0,     0,     0,   122,   127,     0,     0,     0,   561,   562,
     139,   369,   164,   172,   173,   178,     0,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,   470,     0,
       0,     0,   549,   489,     0,     0,   179,     0,   200,   355,
       0,     0,     0,     0,   201,     0,     0,     0,     0,     0,
       0,   516,   515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   240,     0,     0,     0,   371,   372,    39,
     182,   183,     0,   566,     0,     0,   300,   299,     0,     0,
       0,     0,     0,     0,   151,   152,   155,   154,   153,     0,
     595,     0,   632,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,   572,     0,     0,     0,    96,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    49,     0,   239,
     236,   237,    35,     0,     0,   629,   288,     0,   134,   147,
       0,     0,   144,     0,     0,     0,   166,   197,     0,     0,
       0,     0,     0,   555,   556,     0,   496,   471,   484,   486,
       0,     0,   181,   204,     0,     0,     0,   362,   362,     0,
     115,   116,   233,     0,   224,   225,   323,     0,   330,     0,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,   228,     0,     0,     0,     0,   111,   112,   599,
     605,   604,   150,     0,     0,     0,   351,     0,     0,   108,
     100,   102,     0,    90,   622,    97,    98,    52,     0,     0,
       0,     0,   518,     0,     0,   484,   580,     0,     0,     0,
       0,   124,   619,     0,   131,     0,     0,     0,     0,   186,
       0,     0,     0,   326,     0,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   514,     0,   340,
       0,     0,   317,     0,   241,     0,     0,     0,     0,     0,
       0,   229,     0,   565,   301,     0,     0,   383,   233,   398,
       0,   570,     0,    48,     0,     0,     0,    65,    50,     0,
     289,   123,   128,   134,     0,     0,   161,   162,   160,     0,
       0,   472,     0,     0,     0,     0,   363,   376,     0,     0,
     377,     0,   222,     0,   331,     0,   313,     0,   233,     0,
       0,     0,     0,     0,     0,   176,   113,   297,   346,   106,
       0,     0,     0,     0,     0,     0,   132,   133,     0,     0,
       0,   202,     0,   380,     0,   381,   382,   513,     0,     0,
     319,   244,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,    62,     0,     0,   125,     0,     0,   327,     0,
       0,   339,   318,   314,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,   248,     0,   242,   353,    53,
       0,    60,     0,   284,     0,   558,     0,     0,   320,     0,
       0,    54,     0,     0,   296,     0,     0,   243,     0,     0,
       0,     0,     0,     0,    57,    55,     0,    58,     0,   378,
     379,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   121,  1099,   122,   123,  1083,  1950,  1956,
    1383,  1602,  2112,  2240,  1384,  2213,  2256,  1385,  2242,  1386,
    1387,  1606,   453,   610,   611,  1168,  1698,   124,   807,   480,
    1968,  2123,  1969,   481,  1837,  1463,  1418,  1419,  1420,  1565,
    1773,  1774,  1239,  1660,  1651,  1847,   783,   622,   286,   287,
     362,   210,   288,   463,   464,   128,   129,   130,   131,   132,
     133,   134,   135,   289,  1273,  2147,  2204,   974,  1269,  1270,
     290,  1062,   291,   139,  1491,  1237,   947,   989,  2081,   140,
     141,   142,   143,   292,   293,  1195,  1210,  1338,   294,   812,
     295,   811,   483,   639,   330,  1810,   370,   371,   297,   580,
     380,  1367,  1593,   474,   469,  1331,  1038,  1641,  1803,  1804,
    1023,   476,   145,   430
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1942
static const yytype_int16 yypact[] =
{
   13352,    50,    49, 13557, -1942, -1942,   -71,    73,   -45,  -126,
    -113,   -94,    45,   164,   198,   230,   237,   -68,   249,    52,
     138,   362,   399,   147,   170,    32,   -43,   527,   -43,   189,
     214,   239,    43,   251,   264,    67,   299,   311,   316,   321,
     374,   414,   439,   452,   458,   467,   179,   407,   497,   733,
     740,   520,   538,   682,   542,  7287,   573,   539,   570,   739,
     -54,   657,   527,    18,   351,   584,   743,   -73,   607,   166,
     166,   618,   408,    56,   623, -1942, -1942, -1942, -1942, -1942,
     619,   587,   810,   780,    16,    63,   828,   833,   240,   842,
     915,   951,   975,  6267,   980,   -77,   -62,   741,    19,    69,
   -1942,   744,   750, -1942, -1942,  1002,  1003,   756, -1942,  7916,
     766,  4005,    27,    33,   527, -1942, -1942, -1942, 12139,   758,
    1025, -1942, -1942, -1942, -1942, -1942,   785, -1942, -1942, -1942,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942,   -38, -1942, -1942,
   -1942, -1942,    58, -1942,  1035,   819,  6010,   350,   796,  1079,
   12139, 13741, 13741, 13741, -1942, 12139, -1942, -1942, -1942, -1942,
   13741, -1942, -1942, -1942, 12139, -1942, -1942, -1942, -1942,   821,
     830,  1080, -1942, -1942,  8171, -1942, -1942, -1942, -1942,   831,
      32, 12139, 12139, 12139,   835, 12139, 12139, 12139,   836, 12139,
   12139, 12139, 12139, 12139, 12139, 12139, 13741, 12139, 12139, 12139,
   12139,  6267,   837, -1942, -1942, 10082, -1942, -1942, -1942,   829,
    6267,  7542, 13741, -1942, -1942, -1942, -1942, -1942,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   165,   -43,   -43,   -43,   -43,   -43,   838,
     -43,   -43,   840,   527,   501,   501,   501, -1942, -1942, -1942,
     -43,   -43,    34,   905,   906,   907,   841,  7542,   969,   527,
     527,   863,   -43,   -43,   864,   865,   866, -1942, -1942, -1942,
   12139,  7797, 12139, 12139,  8052,    32,   938,    35, -1942, -1942,
     881, -1942,  6200, -1942, -1942, -1942, -1942, -1942,   126, 12139,
   10082, 10082,   886,   888,  8307,  6267,  6267,  6267, -1942, -1942,
   -1942,   889, -1942,   887,   890,  8562,   891,  2346,  1149,  7542,
     893,    19,   894,   895,   166,   166,   166, 12139, 12139,  -105,
   -1942,   191,   166, 10779,   219,   -12,   900,   901,   902,   903,
     909,   912,   913, 10082, 12139,  6267,  6267,  6267,    74,    25,
    1157,   914, -1942,  1158,  1165, -1942,   911,   916,   917, -1942,
   -1942,   918,  6267,   919,   923,   928,   929, -1942, 12139,  6522,
   -1942,  1168,  1169,   924, 12139,   932, 12139, 12139,    28, 12139,
     930, -1942,   983, 12139, 12139, 12139, -1942, -1942, 12139, -1942,
     -43,   -43,   -43,   933,   935,   936,   -43,   -43,   -43,   -43,
     -43,   -43,   -43, -1942,   -43, -1942, -1942, -1942, -1942,   -43,
     -43,   939,   941,   -43,   942, -1942,   943,  1191,  1194,   944,
   -1942, -1942,  1198,  1199,  1200,  1202,   954,   -43, 12139, 15534,
     137, 13741, -1942, 10082, 12139, -1942, -1942,  7542,  7542, -1942,
     947,  8171,   527,  1205, -1942, -1942, -1942, -1942, -1942, -1942,
   12139, 12139,    40,  7542,  1207,   476,   955,  1973,   956,  1209,
      92,   957, -1942,   958, 12106, 12139, -1942,  2058,  -196, -1942,
      66,  -172,  -169,  9255, -1942,  -144, -1942,    93, 11088,  9505,
    -192,  -155,  1122, -1942,    32,   962, 12139,   963, 16050, 16075,
   16100, 12139, 16125, 16150, 16175, 12139, 16200, 16225, 16250, 16275,
   16300, 16325, 16350,   964, 16375, 16400, 16425, 14606,  1214, 12139,
   10082,  6455, -1942,   183, 12139,  1217,  1218,   973, 12139, 12139,
   12139, 12139, 12139, 12139, 12139, 12139, 12139, 12139, 12139, 12139,
   12139, 12139, 12139, 12139, 10082, 12139, 12139, 12139, 12139, 12139,
   12139, 12139, 12139, 10082, 10082,   971, 12139, 12139, 13741, 12139,
   13741,  7542, 13741, 13741, 13741,   974,   976,   977,   979, 12139,
      29, -1942, 11034, 12139,  7542,  6267,  7542, 13741, 13741, 10082,
      32,  8171,    32,   978, 10082,   978, -1942,   978, 16450, -1942,
     273,   967,   103,  1166, -1942,  1228, 12139, 12139, 12139, 12139,
   12139, 12139, 12139, 12139, 12139, 12139, 12139, 12139, 12139, 12139,
    8817, 12139, 12139, 12139, 12139, 12139,    32, 12139, 12139,    62,
   -1942,   814, 16475,   333,   361, 12139, 12139, 12139, -1942,  1234,
    1235,  1235,   986, 12139, 12139, 12139, 12139,  1238, 10082, 10082,
   15562,   987,  1241, -1942,   993, -1942, -1942,  -153, -1942, -1942,
    9760, 10015,   166,   166,   350,   350,  -130, 10779, 10779, 12139,
   11769,   -60, -1942, 12139, 12139, 12139, 12139, 12139, 12139, 12139,
   12139, 12139,   368, 16500,  1248,  1242,  1249, 12139, 12139,  1251,
   12139, -1942, -1942, 12139, 12318, -1942, -1942, 10082, 10082, 10082,
   12139,  1252, 10082, 12139, 12139, 12139, 16525,   997, -1942, -1942,
   12139, 16550, 12139, 16575, 16600,  1071, 10363, -1942,  1001,  6710,
   16625, 16650, 15645, 13741, 13741, 13741, 13741, 13741, 13741, 13741,
   13741, 13741, 12139, 13741, 13741, 13741, 13741,    12,  8171, 13741,
   13741, 13741,    32,    32, -1942, -1942, 10082, -1942,  1004, 12404,
   -1942,  1005, 12463, 12139, 12139,   978, 12139, -1942,    32, 12139,
   12139,    62,  1008,   383, 16675, 13794,  1006,   390, 12139,  1257,
    1009,  7542, 16700, 15672, -1942, -1942, -1942, -1942, -1942,  1010,
    1258,   171,  1263, -1942, -1942, -1942, 10082,    21, 12139, -1942,
   -1942, -1942,    32, 12139, 12139,    62,  1012, -1942,  1017,   -53,
     527,    18,   527, -1942,  1014, 14635, -1942,    98, 10082,    32,
   12139, 12139,    62,  1271, 10082,  1272, 10082, 12139,  1273, 13741,
      32, 11121,    62, -1942, 12139,  1274, -1942,    32,  1276, 13741,
   12139,  1026,  1024, -1942, 12139, 10714,  8171,  1278,  1279,  1281,
   16725,  1283,  1285,  1286, 16750,  1287,  1288,  1290,  1291,  1293,
    1296,  1297, -1942,  1298,  1299,  1300, -1942, 12139, 16775, 10082,
    1047, 10082, 14664, -1942, -1942,  1303, 15618, 15618, 15618, 15618,
   15618, 15618, 15618, 15618, 15618, 15618, 15618, 11065, 15618, 15618,
   15618, 15618,   653,   611, 15618, 15618, 15618, 11402, 11746, 13167,
   13350, 13748,  6455,  1052,  1053,   115, 10082, 13781, 13814,   611,
   13847,   611,  1048,  1049,  1051,  -128, 10082, 12139, 12139, 12139,
   12390, -1942,   611,  1056, 14693, 14722, -1942, -1942,  1055,   124,
     611,  -121,  1061,   401,   400,  1315, -1942,    62,   611,  7542,
    1062,  6965,  7220,   868,   443,   510,   510,   482,   482,   482,
     482,   482,   482,   523,   523, 10082,   269, -1942,   269,   269,
     978,   978,   978,  1060, 16800, 15699,   553, 10082, -1942,  1318,
    1065,  1066, 16825, 16850, 16875, 12139,  7542,  1324,  1326,  3691,
   16900, 14751, 16925, 16950, -1942,   411,   459, 10082,  1067, -1942,
   12549, -1942, 12608, 12694,   166, 12139, 12139, -1942, -1942,  1073,
    1074, 10779,  5199,  1190,   415,   166, 12753, 16975, 14780, 17000,
   17025, 17050, 17075, 17100, 17125, 17150,  1076,  1331, 12139,  1334,
   -1942, 12139, 17175, 14809, -1942, 15726, 12839, 15753, -1942,   502,
     518,   536, 14838, -1942,   543, 15780, 15807, 13880, -1942, -1942,
   17200,  1335, 17225,  1336,  1337,  1082, 12139, 12898, 12139, 12139,
   -1942, -1942,    36,   338,   381,   338,  1088,  1089,  1083,   611,
     611,  1085, 13913,   611,   611,   611,   611, 12139,   611,  1339,
   -1942,  1086,  1096,   397,   524,  1095,   552, -1942, -1942, -1942,
   -1942, 17250, 15618,   269, 12984,  1093,   567,  1092,  1167,  1351,
    1195, 11371,  1102,  1101,  1359,  7542, 14867, -1942, 12139,  1361,
     177,    78,    62,    22,  8171, 12139,  1362, -1942,   561,  1322,
    1323,  7542, 14896,    30,  1110, 17275, 15834,   486, 12139, 12139,
    1117,  1114,  1119,  1116,  9072, -1942, -1942, -1942, -1942, 13741,
     -20,  1115, 17300, 15861,  1123, -1942,   -10, -1942,   107, 13946,
   -1942, -1942, -1942,  1118, -1942,  1125, 13979, -1942,    77, -1942,
   -1942, 12390, -1942,    46, 15618, 12139,   611,   166,  7542,  7542,
    1372,  7542,  7542,  7542,  1376,  7542,  7542,  7542,  7542,  7542,
    7542,  7542,  7542,  7542,  7542,  2092,  1377, 10082,  6455, -1942,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942, -1942, 12139, -1942, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942, -1942, 12139, 12139, 12139, 12139, 12139, -1942, -1942,
   -1942,   563, 12139, 12139, -1942, 12139, -1942,  7542, 13741, 13741,
   -1942,   566, 14925, 14954, 14983,  1121, -1942, -1942, -1942,  1192,
   12139, 12139, -1942, -1942, -1942,    62, -1942,    62, 12139, 12139,
    1131, -1942,  7542,   -43, -1942, -1942, -1942, 12139, 12139,   571,
      62,   132,   -88, 12139, 12139, -1942,   611,   578,  7542, 10082,
   10082,  1383,  1384,  1385,  2300, -1942, -1942,  1388, -1942,  1138,
   12390,  1132,  1390, -1942,  1392,  1393,  1394,  1395,   580,   151,
   -1942, 13043, -1942, -1942,   -25, 14012, 14045, -1942, -1942, 15012,
    -137,  1284,  1399, 11465,  1144,  1400,  1150,    51,    59,   290,
   -1942,    13, -1942,   415,  1401,  1405,  1406,  1407,  1408,  1409,
    1410,  1411,  1412,   350,  7542, 12390, -1942,  3137,  1159,  1319,
    1416, -1942,  1417,  1420,  1321,  1423, -1942,  1424,  1421,  1426,
   12139,  1427,  7542,  1428,  7542,  7542,  1429, 14078, -1942,  7475,
    1929,    62,    62, -1942, 10082, -1942, -1942, -1942, -1942, 13741,
   -1942, -1942, 12139, 13741, -1942, -1942, -1942, -1942, 12390, -1942,
    1172,  1171, 13741, -1942, 13741, -1942,    62, 13741,  1180, -1942,
    1173,  1436, -1942,    62, 12139, 12139,  1182,   527,  1183, 11715,
   -1942,  3340,  1184,  7542, -1942,  1186, -1942, 15041, -1942, -1942,
   12139,  1440,   417, 12139,  1443,  1444,    19,  1446,  1201,  1447,
    3888, -1942,   611,   -43,   -43,  1448, -1942, -1942,  1193,  1204,
    1196, -1942,  1453, -1942, -1942, -1942, -1942, -1942, -1942,    62,
     521,   940, 12139, 15888, 17325, 12139,  9322, 12139, 10082,  1203,
     608,  1458,   123,    62, -1942,  1206, 12139,  1460,  1461, 12139,
      62, 11802, 12139, 10332,   611,  5473, 12139, 12139,  1208,  1210,
   -1942,  1464, 17350,  1465,    24,  1338,  1338,  7542,  1466,  1467,
    1469,  7542,   -90,  1471,  1472,  1474,  1475,  1476,  1477,  1481,
    1482,  1483, -1942,  1485,   615, 15618, 15618, 15618, 15618, 15618,
   15618,   611, 14111, 14144, 14177,  1233,   611,   611, -1942, -1942,
   -1942, -1942,    46,   611, 17375, 15618,  1237,  -112, 12390, 15618,
   -1942,  1490,   611, 12390, 12390, -1942,   554, -1942,    62, -1942,
   17400, 15915, -1942,   611,  1492,   620,   648,  7542,  7542,  7542,
    1495,  1494, -1942,   211, 12139,  7542,  7542,  7542,  1240,  1243,
    1496,  1499,  1500, -1942, 12139, 12139, 12139,  1245,  1247,  1250,
    1253, -1942,  4079,  7542, -1942, 12139, -1942,  1503, -1942,  1507,
   -1942, -1942, 10779,   312,  6777, -1942,  1254,  1255,  1256,  1259,
    1261,  1264,  9572,  1262,  1508, -1942, 10082,  1265, -1942, -1942,
   -1942,  1266, 12139, 12139, -1942, -1942, 15942,  7542,  1512,  7542,
    1513,  1313, -1942, 12139, 12139, 12139, -1942,  1522,   261,   412,
    1268,  3051,  1269, 12139,    37,   611,  1282,   611,  1275, -1942,
   -1942,  8171, -1942,   713, 12139,  1289, -1942, -1942,  4168, -1942,
   -1942,  1277,  1524, -1942,  4294, -1942,  1292,  1525,   184,  4330,
   -1942,    19, -1942,   658, -1942, 12139, -1942, -1942,   211,  4939,
   12273, -1942,  1280, 12139, 12139,  7542,  1295, -1942,   -78,   160,
    1533, 17425,  1539,  1315, 17450,  1301,   659, 17475,   661,  1541,
    1542, -1942, -1942, 13741,  1294,  1545, 17500, -1942, -1942, 14210,
    1304, -1942,  8240,  5755, 12390, -1942,  1546,   -43,  8052, -1942,
   -1942, -1942, 12390, 12390, -1942,    46, -1942,  1548, -1942, -1942,
     166,  1552,  1554,  1556, -1942, -1942, -1942,  1422,   -41,  1462,
    1560, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942,
    1547,  1306, -1942, -1942, -1942, -1942, -1942, -1942, -1942, 12139,
   12139, 12139, -1942, -1942, -1942,  1210, -1942, -1942, -1942, -1942,
   12139,  1311,  1305, -1942, -1942, 12139, 12139,   611,   132, -1942,
   -1942, -1942, -1942,  1309,  1312,  1566,   -90,  1568, 12139, -1942,
    7542, 12390,  1432,  1433,   922, 10082, 10082, 12139, -1942,  3691,
   15070, 17525,  8495,   350,   350, 12139, 12139, -1942,   616,  1314,
   17550, -1942, -1942, 15099,   131, -1942,  1571,  1573,  7542,   166,
     166,   166,   166,   166,  7032,  1575, -1942, -1942,   669, 10082,
   12139,  4487,  4604,  1576,  1577, -1942,  1578, -1942,  7542,  8750,
    1685, 17575, -1942, -1942, 10428, -1942, 13741, 12139, -1942, 13741,
   12390, 10683,  8171,  1327, -1942, -1942, -1942, -1942,  1329,  1328,
   12139, 12139, 15128, 12139, 13794, -1942, 13794,  7542, -1942, -1942,
      62,    22,  8171, 12139,  1579, -1942,  1583, -1942,    19, 15969,
    7542, 13741,  1586,   611, -1942,  1332,   611, 12139, 14243, 14276,
     674, -1942, 12139, 12139,  1342, -1942,  1344, -1942,  1385,  1589,
    1594,  1393,  1600, -1942, -1942,  1601, 12139, -1942, -1942, 12139,
   12052,  1602, 12139, -1942, -1942,  1348, 12273,   676,  5695,  1603,
   -1942, -1942,   232, -1942, -1942, -1942,  1468,  1605,  1352,  1353,
    1355, -1942,  1607,  7542, 15618, 15618, 14309, 15618, -1942,  1360,
   17600, 15996, -1942, -1942, 10082, 10082, -1942,  1611, -1942, 12390,
    1613, 12139, 12139,  1363, -1942,   685,   686, 15590,  4656,  1615,
    1364, -1942, -1942, 12139,  1365,  1366, 15157, 16023,  1616,  7542,
    1619,  1368, 12139, -1942, -1942,   687,   202,   224,   229,   248,
     260,  9827,   266, -1942,  1617,   694, 15186, -1942, -1942, -1942,
   -1942, -1942,  1445, -1942, 12139, 12139, -1942, -1942, 10082,  4850,
    1625,  1374, 15618,   611, 12390, -1942, -1942, -1942, -1942,    37,
   -1942,  8171, -1942, 15215,  1375,  1378,  1379,  1627,  1630,  1632,
    4971, -1942, -1942, -1942,  1380,  1633,   695, -1942,  1638,  1640,
     244, 12390, 12139, 12139,  1386,  7542,   700, 12390, 17625, -1942,
   -1942, -1942, -1942, 17650, 14342, -1942, -1942, 15244,  1121,  1171,
    7542,   611, -1942, 12139,  8171,    32, -1942, -1942, 10082, 10082,
   12139,  1643,   701, -1942, -1942, 12139,  1305, -1942, -1942, -1942,
     702,   703, -1942, -1942,  5042,  5096,  7542,   629,   640, 10082,
   -1942, -1942,   350,  9005, -1942, -1942, -1942,  1645, -1942,  1397,
    7542, -1942, 15273,  1649, 10082,   166,   166,   166,   166,   166,
   -1942,  1650, -1942, 12139, 15302, 15331,   752, -1942, -1942, -1942,
   -1942, -1942, -1942,  1402,  1651,  1403, -1942,  1655,    19, -1942,
   -1942, -1942,  1478, -1942, -1942, -1942, -1942, -1942, 12139, 14375,
   14408,  7542, -1942,  1656, 12139,  1404, -1942, 12139,  1657,  1413,
    1414, -1942, -1942,  5940, -1942,  1415,   754,   760, 15360, -1942,
    1418, 14441,  1419, -1942,  1425, -1942, -1942,   762,  1430,   166,
    7542,  1660,  1431,   166,  1664,   763,  1434, -1942, 12139, -1942,
    1665,  1530, 13129,  1438, -1942,   768,   278,   309,   314,   336,
     344, -1942,  5159, -1942, -1942,  1668,  1672, -1942, -1942, -1942,
    1681, -1942,  1439, 12390, 12139, 12139,   770, -1942, 12390, 14474,
   -1942, -1942, -1942,  1121,  8171,  1437, -1942, -1942, -1942, 12139,
   12139, -1942, 10082,  1682,   166,    82, -1942, -1942,   166,   112,
   -1942,  1683, -1942, 15389, -1942, 12139, -1942,   415, -1942,  1688,
   10082, 10082, 10082, 10082,  9827, -1942, -1942, -1942, 13794, -1942,
   12139, 17675, 14507,    53, 12139,  1441, -1942, -1942, 14540, 14573,
     771, -1942,   348, -1942,   355, -1942, -1942, -1942,  5414,   315,
   13188, -1942,   777,   778,   787,   789,   367,   790,  1442,   792,
   -1942, 12139, -1942,  7542, 15418, -1942, 12139, 12139, -1942,   166,
     166, -1942, -1942, -1942,   415,  1695,  1696,  1699,  1700, 10082,
    1702,  1703,  1704,  1450, 17700,   797,  1708, 15447, 15618,   370,
     372,   366, -1942, -1942, -1942, -1942,   798, -1942, -1942, -1942,
   13741, -1942,  1454, -1942,  1710, -1942, 12139, 12139, -1942,  1711,
     803, -1942,  1459,  7542, -1942, 15476, 15505, -1942,  1715, 13741,
   13741,   805,  1716,  1718, -1942, -1942,   811, -1942,  1719, -1942,
   -1942,  1720, 13741, -1942, -1942, -1942
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1942, -1942, -1942, -1942,   325, -1942, -1942, -1942, -1942,  -432,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942,  -749,  -141,  4528,  3790,  -404, -1942,  1267, -1942,
   -1942, -1942, -1942, -1942, -1942, -1941, -1942,   270,    86,  -236,
   -1942,  -195, -1942,    31,   310, -1942,  1735, -1942,  1100,   -55,
   -1942, -1942,     6,  -641,  -118, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942,   656,  1737, -1942, -1942, -1942, -1942, -1267, -1262,
    1739, -1765,  1740, -1942, -1942, -1942,  1124, -1942,  -254, -1942,
   -1942, -1942, -1942,  2469, -1942, -1942, -1453,   181,  1744, -1942,
       0, -1942, -1942,   -59, -1942, -1721,   972,  -186,  2971,  3164,
    -319,   -40, -1942,   267,   -74, -1942, -1942,   -19,   153, -1729,
    -159,   959, -1942,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -582
static const yytype_int16 yytable[] =
{
     146,   475,   634,   969,   970,   454,  1523,  1521,   315,   127,
     329,   331,  1075,   334,  1691,   508,   169,  1895,  1081,  1934,
     349,  1935,   171,   378,   515,   170,   169,  2059,  1079,   669,
    1649,   373,   422,   169,  1377,   417,   169,   421,   424,   561,
     584,  1771,  1927,  1311,   754,   478,   375,   184,   761,     5,
    1415,   154,   298,  1658,   303,   303,     4,  1516,   162,  2192,
     335,  1848,   787,   150,   436,  1518,   754,   354,   805,   355,
     788,   188,   459,   382,   806,   789,   755,   756,   304,  1090,
    1849,   353,  1416,  1417,  1413,  1359,   793,   149,  2173,   795,
     298,   320,   642,   643,   794,   381,   169,   796,   755,   756,
     485,   772,   800,  1659,  1096,   808,   418,  1971,   642,   643,
     350,   806,   484,   964,   798,   642,   643,   321,  2175,   619,
     620,   621,   799,   309,   606,  1508,   310,   311,   312,  1622,
    1190,   151,  1982,   322,   323,   606,   971,  1204,   799,   313,
     642,   643,  1205,   460,   152,   172,   738,   173,   470,   470,
     470,   757,   758,   462,  1208,  1501,   644,   477,   336,   664,
     665,   666,   337,   153,  1814,   356,   448,   449,   338,   339,
     156,   340,   341,   757,   758,  1478,   681,   487,  1074,  1813,
     374,  1781,  2165,  -578,  1359,   642,   643,   755,   756,   160,
     147,  1792,   342,   470,   148,   376,   755,   756,   298,   556,
     557,   558,   298,   314,   157,   936,   975,   298,   298,   470,
    1378,  1379,  1380,  1381,   172,   650,   173,   351,  1359,   434,
     642,   643,    99,   435,   100,   101,   102,   103,   104,  1517,
     759,   760,   108,   109,   674,   111,   158,  1519,  1402,  1859,
     119,  1504,  1772,   159,   119,   653,   841,   119,  1407,   654,
     119,   444,   445,   446,  1080,   161,   841,   119,   642,   643,
     119,  1521,   757,   758,   298,   637,   638,  1763,  1764,   642,
     643,   757,   758,   646,   651,  2077,  1037,   352,   298,  1522,
     379,   298,   582,  1366,   670,   581,   671,   764,   423,   765,
     148,   695,  1382,   148,   425,   562,   585,   298,   298,  1312,
     185,   298,   298,   298,   298,   729,   155,   732,   444,   445,
     446,   447,   298,   163,  2193,   437,   298,   745,   381,   438,
     119,  1360,  1363,   790,   189,   791,   383,   642,   643,   792,
    2116,   667,   448,   449,   172,   668,   173,  1056,  1097,  1098,
     298,  1362,   298,   298,   298,   359,   448,   449,   360,   773,
     801,   774,   791,  -574,   461,   775,   802,   642,   643,   298,
     172,   361,   173,  1097,  1098,  1408,   298,   749,   165,   448,
     449,  1087,   607,   841,   608,  1180,   642,   643,   609,   896,
     448,   449,   764,   607,   765,   608,   448,   449,  1104,   609,
    1201,   448,   449,  2188,   739,   885,   740,  1892,  1115,   164,
     741,   444,   445,   446,   447,   166,   167,   444,   445,   446,
     447,   325,   326,   458,   444,   445,   446,   447,   468,   471,
     472,   754,   543,   327,   544,   448,   449,   328,   470,   168,
     298,   448,   449,  1262,   298,   298,   642,   643,   448,   449,
     200,   444,   445,   446,   447,   840,   181,   642,   643,   841,
     298,  1263,   645,   755,   756,  1262,   316,   776,  1262,   317,
    1264,  1265,  1266,   503,   642,   643,  1267,  1268,  2014,   642,
     643,   182,  2215,  1263,   642,   643,  1263,   642,   643,   517,
     652,   813,  1264,  1265,  1266,  1264,  1265,  1266,  1267,  1268,
    2015,  1267,  1268,   642,   643,  2016,   183,   902,    68,    69,
      70,    71,  2047,  1213,    74,   642,   643,   298,   186,  1262,
    2048,   642,   643,    83,  2017,   960,    86,   962,   963,   603,
     604,   187,  2251,   642,   643,   605,  2018,  1263,   757,   758,
     201,   298,  2019,  2072,   976,   906,  1264,  1265,  1266,   841,
     298,   875,  1267,  1268,  2150,   470,  1025,   470,   298,   470,
     470,   477,  1520,   996,   642,   643,   190,   892,  1262,   642,
     643,   298,   298,   298,   470,   470,   298,   171,   191,   171,
     901,   298,   903,   192,  1735,  2151,  1263,  2202,   193,  1017,
    2152,   642,   643,   967,   968,  1264,  1265,  1266,   638,   642,
     643,  1267,  1268,   642,   643,   940,   764,   298,   765,   841,
     642,   643,  2153,   933,   799,   202,   309,  1586,  1587,   310,
    2154,   312,   642,   643,  2199,   642,   643,   642,   643,  1054,
    1076,  2200,   313,   941,   586,   298,   298,   841,  2238,   175,
     986,   194,   176,  2209,   841,   177,  2236,   178,  2237,   764,
     206,   765,  1533,   207,  1040,  1058,   208,  1314,    46,   841,
     462,   462,  1064,   325,   326,   764,  1065,   765,   172,   209,
     173,   586,  1211,  1334,  1207,   327,   841,  1208,  1365,   333,
     764,   195,   765,  1246,   298,   298,   298,   841,   841,   298,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,   345,   196,   346,   742,   605,
     477,   470,   477,   470,   470,   470,   470,   470,   470,   197,
     470,   470,   470,   470,  1039,   198,   470,   470,   470,   171,
    1045,  1247,  1044,   298,   199,   841,  1092,   598,   599,   736,
     601,   602,   603,   604,   764,  1055,   765,   766,   605,   203,
     448,   449,  1126,  1392,  1710,  1345,   204,  -577,   298,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,   305,   298,  1293,   306,   605,   307,   841,  1084,
     736,   601,   602,   603,   604,   448,   449,  2078,  2079,   605,
    1294,   205,  -576,  2080,   841,   298,  1101,  1336,  2082,  2083,
    1337,   298,   211,   298,  2080,  1225,   477,  1113,  1295,   212,
     300,  1466,   841,  1467,  1118,  1297,   470,   448,   449,   841,
    1223,  1695,  1224,  1696,  1340,   879,  1476,   881,   841,   883,
     884,   448,   449,  1372,  1344,  1451,  1345,   841,  1458,   841,
     299,   301,   841,  1475,   898,   899,   298,   841,   298,  1793,
    1483,   318,  1500,  1251,   841,  1502,   841,   302,   319,  1800,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   324,   764,
    1620,   765,   605,   298,   841,  1241,   344,  1671,  1888,   332,
    2179,   841,  1703,   298,   343,   348,   841,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     839,   601,   602,   603,   604,  1254,   298,  1557,  1558,   605,
    1704,   764,  1260,   765,   841,  1225,  1271,  1521,   347,   364,
    1797,  1820,   298,  1822,  1798,   841,  1873,   841,  1874,  1361,
    1364,  1904,  1568,   357,   298,   841,  1954,  2221,  1972,  1573,
    1955,   358,  1973,   298,   169,   389,  1225,  1997,  1998,  2013,
     363,   841,   841,  1955,   298,   365,  2021,  2044,  1588,  1521,
     841,   799,  2053,  2070,  2073,  2074,  2054,  1955,   841,   841,
    1780,  1024,  1781,  1026,  1027,  1028,  1029,  1030,  1031,   366,
    1033,  1034,  1035,  1036,   372,  1608,  1041,  1042,  1043,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   377,  1624,
    1369,   384,   399,   400,   401,   402,  1630,   385,   386,   387,
     403,   404,   405,   406,  2105,   388,  2126,   431,   841,   407,
     841,   408,  2127,   419,  2133,  2141,   841,   296,  1955,   841,
    2149,   432,  2163,  2198,   841,   409,  1955,   841,   410,  2205,
    2206,   439,   175,   841,   841,   176,   433,  1592,   177,  2207,
     178,  2208,  2210,   841,  2212,   841,   841,   465,  2054,  2232,
    2239,    46,   298,  1955,   841,  2248,  1111,  2258,  1424,  2249,
    1368,  1955,   764,  2261,   765,   937,  1120,  2262,   298,   442,
    1477,  1479,  1884,  1885,   440,   466,   148,   482,   486,   484,
     514,   298,   491,   495,   509,   551,   470,   554,  -206,  -207,
    -208,   564,   563,   126,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
     567,   570,   571,   572,   605,   298,   298,   179,   298,   298,
     298,   583,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   435,   615,   298,   616,   623,   625,   624,   411,
     412,   413,   628,   631,   633,   635,   636,   655,   656,   657,
     658,   414,   308,   672,   675,   415,   659,   416,   119,   660,
     661,   676,   677,   673,   688,   689,   698,   678,   679,   680,
     682,   690,   683,   516,   298,   470,   470,   684,   685,   692,
     706,   697,   707,   708,   448,   449,   719,   724,   720,   722,
     725,  -575,   723,  1609,   727,   726,   730,   728,   748,   298,
     731,   733,   751,   763,   426,   771,   768,   770,   147,   810,
     777,   837,   832,   843,   844,   298,   298,   298,   814,   816,
     907,   845,   876,   909,   605,   886,   910,   887,   888,   296,
     889,   945,   946,   949,   954,   958,   456,   959,   990,  1477,
    1479,   456,   456,   456,   961,   988,   991,   994,  1003,  1009,
     456,  1015,  1018,  1067,  1063,  1073,  1047,  1049,  1057,  1077,
    1068,  1088,  1796,  1072,  1089,  1094,   618,  1105,  1107,  1110,
    1117,   298,  1119,  1123,  1122,  1127,  1128,   627,  1129,   462,
    1131,   632,  1132,  1133,  1135,  1136,   456,  1137,  1138,   298,
    1139,   298,   298,  1140,  1141,  1142,  1143,  1144,  1147,  1151,
    1178,   298,   456,  1179,  1187,  1188,   470,  1189,  1197,  1206,
     470,  1200,  1212,  1220,  1216,  1228,  1229,  1230,  1236,   470,
    1249,   470,  1238,  1261,   470,  1257,  1258,  1283,  1284,  1635,
    1286,  1640,  1302,  1304,  1305,  1306,  1317,  1318,  1330,  1319,
     298,  1322,  1332,   555,  1333,  1339,  1343,  1346,  1348,  1349,
    1347,  2086,  1353,   381,  1352,  1354,  1401,  1358,  1371,   565,
     566,  1373,  1374,  1389,  1395,  1396,  1397,  1398,  1403,  1427,
    1406,  1410,  1411,  1431,  1443,  -209,  1937,  1462,   470,  1470,
    1487,  1488,  1489,   298,  1492,   298,  1493,  1495,  1494,  1496,
    1497,  1498,  1499,  1510,  1509,  1513,  1514,  1515,  1524,   746,
     747,  1525,   298,  1526,  1527,  1528,  1529,  1530,  1531,  1532,
    1536,  1537,  1538,  1539,   298,   762,  1540,  1544,   298,  1541,
    1542,  1543,  1545,  1552,  1547,  1549,  1563,  1564,  1570,  1571,
    1805,  1805,  1572,  1574,  1576,  1580,  1585,  1794,  1582,  1590,
    1603,  1591,  1594,  1596,  1601,  1456,  1457,  1605,  1784,  1607,
    1595,  1604,  1786,  1734,  1621,  1619,  1627,  1628,  1644,  1625,
    1646,  1648,  1654,  1655,  1650,  1656,  1645,  1661,  1662,  1943,
    1663,  1664,  1665,  1666,   298,   298,   298,  1667,  1668,  1669,
    1670,  1682,   298,   298,   298,  1689,  1693,  1779,  1702,  1708,
    1709,  1715,  1758,  1717,  1716,  1718,  1723,  1719,  1724,  1731,
     298,  1725,  1726,  1732,  1747,  1738,  1739,  1740,  1755,  1757,
    1741,   298,  1742,   882,  1746,  1743,  1749,  1750,  1762,   298,
    1788,   456,  1791,   298,  1766,  1769,   618,  1807,   897,  1815,
    1776,  1337,   750,  1787,   298,  1817,   298,  1823,  1824,  1827,
    1783,  1826,  1852,  1835,  1841,  1790,  1812,  1863,  1843,  1834,
    1844,  1830,  1845,  1819,   784,  1846,  1851,  1853,  1850,  1858,
    1864,  1208,  1866,  1865,  1868,  1871,  1872,  1893,   784,  1894,
    1889,  1903,  1909,  1910,  1911,  1941,  1560,  1930,   381,  1942,
    1562,  1842,  1947,  1929,  1931,  1959,   477,   477,   799,  1566,
    1960,  1567,   298,  -581,  1569,  -579,  1961,  1962,  1966,  1970,
    1975,  1977,  1981,  1978,  1979,  1976,  1980,  1992,  1987,  1993,
     470,  2001,  2008,  2020,  1996,  2002,  2010,  2004,  2005,  2011,
     298,  2028,  2029,  2023,  2038,   298,  2039,  2035,  2040,  2043,
    2036,  2037,  1946,  2042,  2045,  1879,  2046,  2051,   456,  2069,
     456,  2089,   456,   456,   456,  2094,  2101,  2107,  1610,  2090,
    2106,  2109,  2117,  2120,  2108,  -580,  2137,   456,   456,  2111,
    2140,  2144,  2125,  2145,  2156,  2121,  2122,  2131,  2157,  2129,
    1896,  1897,  1898,  1899,  1900,  1902,  2132,  2159,  2171,  2176,
    1920,  2134,  2138,  1915,  2181,  2167,  2142,  1925,  1928,  2148,
    2160,  2222,  2223,  2195,  2211,  2224,  2225,   298,  2227,  2228,
    2229,  2230,   298,   298,  2233,  2243,  2244,  2247,  1939,  2110,
    2250,  2254,  2259,  1069,  2260,  2263,  2264,  1623,  2189,   462,
     462,  1840,  1685,  2060,  2032,   298,  1652,  1867,   125,  1388,
     136,   298,   137,   138,  2084,   948,   298,   144,   809,  1778,
     784,  1938,  1926,  1806,     0,   298,     0,     0,  1112,     0,
       0,     0,     0,   470,     0,     0,   470,     0,     0,     0,
       0,     0,     0,     0,   784,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   298,     0,     0,     0,  1368,     0,
       0,     0,     0,     0,     0,   381,     0,   298,   477,     0,
       0,     0,     0,   456,   456,   456,   456,   456,   456,   456,
     456,   456,     0,   456,   456,   456,   456,     0,     0,   456,
     456,   456,     0,     0,     0,     0,     0,     0,     0,   784,
       0,     0,   784,   477,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   784,     0,     0,     0,     0,
     298,     0,     0,     0,     0,     0,     0,  2033,     0,     0,
       0,   298,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1091,  1215,  1093,     0,     0,     0,   298,     0,     0,     0,
    1825,     0,     0,  2092,     0,     0,     0,     0,   298,   456,
    2064,     0,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,   298,     0,     0,  1235,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,  1555,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  1916,     0,     0,
       0,     0,   298,     0,     0,     0,  2096,  2097,  2098,  2099,
    2100,     0,     0,     0,     0,     0,     0,   298,     0,     0,
       0,     0,  2065,     0,     0,   298,   298,     0,     0,   769,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2158,     0,     0,   298,     0,     0,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   298,   462,     0,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
    2135,     0,     0,     0,  2139,     0,     0,     0,     0,     0,
    2180,     0,     0,  1921,     0,   381,  1923,  1355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   298,     0,
    2166,     0,     0,  1375,     0,     0,     0,     0,     0,     0,
     784,     0,   784,   784,   786,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2172,   784,   298,     0,  2174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2186,   784,     0,  1442,     0,
    1425,  1426,     0,  1428,  1429,  1430,     0,  1432,  1433,  1434,
    1435,  1436,  1437,  1438,  1439,  1440,  1441,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2219,  2220,     0,     0,     0,     0,     0,   298,   298,   298,
     298,   298,     0,     0,   784,     0,     0,     0,     0,  1455,
       0,     0,     0,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,  1471,   605,     0,  1556,     0,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,   456,
    1484,     0,     0,     0,     0,     0,   298,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,   470,     0,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,     0,     0,     0,   470,   470,     0,     0,
       0,     0,     0,     0,     0,     0,  1534,     0,     0,   470,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1548,     0,  1550,  1551,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,   456,
       0,     0,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1581,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,   213,
     169,   784,     0,     0,     0,     0,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   427,   235,
     236,   237,   238,   239,   240,   241,   242,  1639,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1653,
       0,     0,     0,  1657,   248,   249,   250,   251,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,   456,     0,     0,     0,     0,   257,   258,
     259,     0,   456,     0,   456,     0,     0,   456,     0,   260,
      25,     0,   261,  1490,     0,     0,     0,  1575,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1705,
    1706,  1707,     0,     0,     0,     0,     0,  1712,  1713,  1714,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1729,     0,     0,     0,     0,
       0,   456,     0,     0,     0,     0,  1737,  2241,     0,     0,
       0,     0,     0,     0,  1745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2255,  2257,     0,  1754,
       0,  1756,     0,     0,     0,     0,     0,     0,     0,  2265,
       0,     0,     0,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,   271,     0,   605,     0,   272,     0,
       0,     0,     0,     0,   274,   275,   276,     0,   277,   278,
     279,     0,     0,     0,   119,     0,     0,  1811,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,     0,     0,
       0,   280,   428,     0,     0,     0,     0,     0,   282,     0,
       0,     0,     0,   368,     0,  1833,     0,   629,     0,     0,
     285,     0,     0,     0,     0,   457,     0,     0,     0,   467,
       0,     0,     0,     0,   473,     0,     0,     0,     0,     0,
       0,     0,     0,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     488,   489,   490,     0,   492,   493,   494,     0,   496,   497,
     498,   499,   500,   501,   502,     0,   504,   505,   506,   507,
       0,     0,     0,     0,   511,     0,     0,     0,     0,     0,
       0,     0,  1870,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   456,
     456,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1811,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,     0,     0,     0,     0,     0,     0,
    1912,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
     575,   577,   578,   511,     0,     0,     0,     0,     0,  1936,
       0,     0,     0,     0,     0,     0,     0,     0,   612,   511,
     511,     0,  1945,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   630,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   640,   641,     0,     0,
       0,     0,   641,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   511,   663,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   686,   511,     0,
       0,     0,     0,   691,     0,   693,   694,     0,   696,     0,
       0,     0,   699,   700,   701,     0,     0,   702,     0,     0,
       0,  2009,     0,     0,     0,     0,   456,     0,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   784,     0,   784,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   735,     0,     0,
       0,   456,   511,   744,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   752,
     753,     0,     0,     0,     0,     0,     0,  2052,     0,     0,
       0,     0,     0,     0,   785,     0,   456,     0,     0,     0,
       0,     0,  2061,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   815,     0,     0,     0,     0,
     820,     0,     0,     0,   824,     0,     0,     0,  1811,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   838,   575,
       0,     0,  2091,   842,     0,     0,     0,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   864,   865,   866,   867,   868,   869,
     870,   871,   872,   872,     0,   877,   878,     0,   880,     0,
       0,     0,     0,  1811,     0,     0,     0,     0,   890,     0,
       0,   894,   895,     0,     0,     0,     0,     0,   872,     0,
       0,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,  2136,     0,     0,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   926,
     928,   929,   930,   931,   932,     0,   934,   935,     0,     0,
       0,     0,     0,     0,   942,   943,   944,     0,     0,     0,
       0,     0,   950,   951,   952,   953,     0,   511,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   573,   735,   972,     0,
       0,     0,   977,   978,   979,   980,   981,   982,   983,   984,
     985,     0,     0,     0,     0,     0,   992,   993,     0,   995,
       0,     0,   997,  1535,     0,     0,   511,   511,   511,  1002,
       0,   511,  1005,  1006,  1007,     0,     0,     0,     0,  1010,
       0,  1012,     0,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,     0,     0,
       0,  1032,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   784,     0,     0,   511,     0,     0,     0,     0,
       0,     0,  1051,  1052,     0,  1053,     0,     0,   934,   935,
       0,     0,     0,     0,     0,  1811,     0,  1066,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   511,     0,  1082,     0,     0,
       0,     0,  1085,  1086,     0,     0,     0,     0,     0,     0,
       0,     0,   576,     0,     0,   512,     0,   511,   784,  1102,
    1103,     0,     0,   511,     0,   511,  1109,     0,     0,     0,
    1102,   512,   512,  1116,     0,     0,     0,     0,     0,  1121,
     784,     0,     0,  1124,     0,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,  1145,   605,   926,   764,
    1148,   765,     0,     0,   512,     0,     0,  1767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     456,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     512,     0,     0,     0,     0,   511,  1579,     0,     0,   456,
     456,     0,     0,     0,     0,   511,  1192,  1193,  1194,     0,
       0,     0,   456,     0,     0,     0,     0,     0,     0,   513,
       0,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   512,     0,   511,     0,     0,     0,
       0,     0,     0,     0,  1234,     0,     0,     0,  1240,     0,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,  1255,  1256,     0,     0,     0,     0,
    1259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1285,     0,     0,
    1287,     0,     0,     0,   613,   614,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,     0,     0,     0,  1307,     0,  1309,  1310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   863,  1328,   662,     0,     0,
       0,     0,     0,     0,   873,   874,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1351,     0,     0,     0,     0,     0,     0,  1357,     0,     0,
     900,     0,     0,     0,  1370,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1393,  1394,     0,
       0,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,   927,     0,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,  1422,     0,   605,   743,     0,   512,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1445,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1446,  1447,  1448,  1449,  1450,     0,   512,   512,
     512,  1452,  1453,   512,  1454,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1464,
    1465,     0,     0,     0,     0,     0,     0,  1468,  1469,     0,
       0,     0,     0,     0,     0,     0,  1473,  1474,     0,     0,
       0,     0,  1480,  1481,   213,   169,   389,   512,   511,   511,
       0,   214,   215,   216,     0,     0,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   427,   235,   236,   237,   238,   239,   240,
     241,   242,  1512,     0,     0,     0,     0,   512,   904,     0,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   248,
     249,   250,   251,   399,   400,   401,   402,   252,     0,   512,
       0,   403,   404,   405,   406,   512,     0,   512,     0,  1546,
     407,     0,   408,   257,   258,   259,     0,     0,     0,     0,
       0,     0,     0,   511,   260,    25,   409,   261,     0,   410,
       0,  1561,   955,   956,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     927,     0,  1149,  1480,  1481,     0,     0,     0,  1578,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1584,
       0,     0,  1589,     0,     0,     0,     0,     0,     0,     0,
       0,   999,  1000,  1001,     0,     0,  1004,   512,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,     0,
       0,  1611,     0,     0,  1614,   511,  1617,   511,     0,     0,
       0,     0,     0,     0,     0,  1626,     0,     0,  1629,     0,
    1626,  1632,  1634,     0,     0,  1642,  1643,     0,     0,     0,
    1046,     0,     0,     0,  1597,     0,   512,     0,     0,   271,
     411,   412,   413,   272,     0,     0,     0,     0,   512,   274,
     275,   276,   414,   277,   278,   279,   415,     0,   416,   119,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
    1078,     0,     0,     0,     0,     0,   280,   428,     0,     0,
       0,     0,     0,   282,     0,     0,     0,     0,   368,     0,
       0,     0,  1100,     0,     0,   285,     0,     0,  1106,     0,
    1108,     0,     0,  1711,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1720,  1721,  1722,     0,     0,     0,     0,
       0,     0,  1728,     0,  1730,     0,     0,     0,     0,     0,
       0,  1733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   511,     0,     0,     0,   420,
     389,  1751,  1752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1759,  1760,  1761,     0,     0,     0,     0,     0,
       0,     0,  1770,     0,     0,     0,     0,     0,     0,     0,
    1181,     0,     0,  1782,     0,     0,     0,     0,     0,     0,
    1191,     0,     0,     0,   390,   391,   392,   393,   394,   395,
     396,   397,   398,     0,  1799,   512,     0,   399,   400,   401,
     402,     0,  1808,  1809,     0,   403,   404,   405,   406,     0,
       0,     0,     0,     0,   407,  1727,   408,     0,     0,  1219,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     409,  1227,     0,   410,     0,     0,     0,  1838,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
       0,  1248,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,  1854,  1855,
    1856,     0,     0,     0,     0,     0,     0,     0,     0,  1857,
       0,     0,     0,     0,  1860,  1861,     0,     0,     0,     0,
       0,     0,     0,     0,  1785,     0,     0,  1869,     0,     0,
       0,     0,     0,     0,   511,   511,  1877,     0,  1878,     0,
       0,     0,     0,     0,  1886,  1887,     0,     0,     0,     0,
     512,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   511,   411,   412,   413,     0,   511,  1906,
       0,     0,     0,     0,     0,     0,   414,     0,     0,     0,
     415,     0,   416,  1919,     0,     0,  1922,     0,     0,     0,
    1924,     0,     0,     0,     0,   767,     0,     0,     0,  1860,
    1861,     0,  1933,     0,     0,     0,     0,     0,  1400,     0,
       0,     0,  1940,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1951,     0,     0,     0,
       0,  1957,  1958,     0,     0,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1963,     0,     0,  1964,  1963,
    1789,  1967,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1444,     0,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,   511,   511,   605,  1795,     0,     0,     0,
    1994,  1995,     0,     0,     0,     0,     0,     0,     0,     0,
     891,     0,  2003,     0,     0,     0,     0,     0,     0,     0,
       0,  2012,     0,     0,     0,     0,     0,   512,     0,   512,
     575,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2024,  2025,     0,     0,   511,     0,     0,
       0,     0,     0,  1485,  1486,     0,     0,     0,     0,     0,
       0,   938,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,  2049,  2050,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2063,     0,     0,     0,     0,   511,   511,  2068,
       0,     0,     0,     0,  2071,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1559,     0,
       0,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,  2102,  1907,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   512,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2113,     0,     0,
       0,     0,     0,  2118,     0,     0,  2119,     0,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,   174,     0,   180,  2143,     0,     0,
    1616,     0,  1618,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,  2161,  2162,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2168,  2169,
       0,   511,     0,     0,     0,     0,     0,     0,     0,  1839,
    1908,     0,     0,     0,  2178,     0,     0,     0,     0,   511,
     511,   511,   511,   511,     0,     0,     0,     0,     0,  1957,
       0,     0,     0,  2194,     0,     0,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,     0,  1164,  1165,
    1166,  1167,     0,  1169,  1170,  1171,  1172,     0,     0,     0,
    2214,     0,  2000,     0,     0,  2217,  2218,     0,     0,  1184,
       0,  1186,     0,     0,   455,     0,     0,     0,   511,     0,
       0,     0,  1196,     0,     0,     0,   512,   512,     0,  1202,
    1203,     0,     0,     0,     0,     0,     0,     0,  1214,     0,
    1748,     0,     0,     0,     0,  2245,  2246,     0,     0,     0,
       0,     0,     0,     0,     0,   512,     0,     0,     0,     0,
     512,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   545,   546,   547,   548,   549,   550,     0,   552,   553,
       0,     0,     0,     0,     0,     0,     0,     0,   559,   560,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     568,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1313,  1315,  1316,     0,     0,     0,  1320,
    1321,     0,     0,  1324,  1325,  1326,  1327,     0,  1329,     0,
       0,     0,     0,  1335,     0,   512,   512,     0,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,  2027,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   576,     0,     0,     0,     0,     0,     0,  1875,
    1876,     0,     0,     0,     0,     0,     0,     0,     0,   512,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,  1905,  1421,     0,  1423,     0,   703,   704,
     705,     0,     0,     0,   709,   710,   711,   712,   713,   714,
     715,     0,   716,     0,     0,     0,     0,   717,   718,     0,
       0,   721,     0,   169,   389,     0,     0,     0,     0,   512,
     512,     0,     0,     0,     0,   734,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     512,     0,     0,     0,     0,     0,     0,  2041,     0,     0,
       0,     0,     0,     0,     0,   512,     0,     0,   390,   391,
     392,   393,   394,   395,   396,   397,   398,     0,     0,     0,
       0,   399,   400,   401,   402,     0,     0,     0,     0,   403,
     404,   405,   406,     0,     0,     0,  1482,     0,   407,     0,
     408,     0,     0,     0,     0,     0,     0,     0,  1990,  1991,
       0,     0,     0,     0,   409,     0,     0,   410,     0,     0,
       0,   175,     0,     0,   176,     0,     0,   177,  2075,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   442,     0,
       0,     0,  2026,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,  2076,   512,     0,     0,   605,     0,     0,     0,
     908,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   512,   512,   512,   512,   512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2066,  2067,     0,     0,     0,     0,   411,   412,
     413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     414,     0,  1598,  2085,   415,  2155,   416,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2095,     0,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   764,     0,   765,
    1801,     0,     0,     0,  1636,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,  1672,  1673,  1674,  1675,  1676,
    1677,  1678,     0,     0,     0,     0,  1683,  1684,     0,     0,
       0,     0,     0,  1686,     0,  1688,     0,     0,     0,  1692,
       0,     0,  1694,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1701,     0,     0,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,  2170,     0,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2182,  2183,  2184,  2185,  2187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,  1765,
       0,  1768,   605,     0,     0,  1775,     0,  1777,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1802,
       0,     0,     0,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,     0,
    2201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1209,     0,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,  1008,     0,     0,
       0,     0,     0,     0,  1226,   965,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     6,   389,     0,
       0,     0,     0,   214,   215,   216,     0,  1862,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     0,
       0,     0,  1637,   391,   392,   393,   394,   395,   396,   397,
     398,   248,   249,   250,   251,   399,   400,   401,   402,   252,
     253,     0,     0,   403,   404,   405,   406,     0,     0,   254,
     255,   256,   407,     0,   408,   257,   258,   259,     0,     0,
       0,     0,     0,     0,     0,     0,   260,    25,   409,   261,
       0,   410,     0,     0,     0,   262,     0,     0,   263,     0,
       0,   264,     0,   265,     0,     0,     0,     0,     0,     0,
      42,     0,     0,  1948,   266,     0,  1949,     0,     0,     0,
       0,     0,     0,     0,     0,   267,     0,    57,    58,     0,
     268,     0,   269,     0,     0,   270,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
       0,     0,     0,     0,  1983,  1984,  1414,  1986,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   411,   412,   413,   272,   273,     0,     0,     0,
       0,   274,   275,   276,   414,   277,   278,   279,   415,     0,
     416,   119,  1974,   586,     0,     0,     0,     0,     0,     0,
       0,     0,  2030,  2031,     0,     0,     0,     0,   280,   281,
       0,     0,     0,     0,     0,   282,     0,     0,     0,     0,
     368,     0,     0,     0,  1638,     0,     0,   285,     0,     0,
       0,  1472,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   213,     6,
     389,  2062,     0,     0,     0,   214,   215,   216,     0,     0,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,     0,     0,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   248,   249,   250,   251,   399,   400,   401,
     402,   252,   253,     0,     0,   403,   404,   405,   406,     0,
       0,   254,   255,   256,   407,     0,   408,   257,   258,   259,
       0,     0,     0,     0,     0,     0,     0,     0,   260,    25,
     409,   261,     0,   410,     0,     0,     0,   262,     0,     0,
     263,     0,     0,   264,     0,   265,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   267,     0,    57,
      58,     0,   268,     0,   269,     0,     0,   270,     0,     0,
       0,  1599,  1600,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   839,   601,   602,   603,   604,  2124,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   411,   412,   413,   272,   273,     0,
       0,     0,     0,   274,   275,   276,   414,   277,   278,   279,
     415,     0,   416,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1690,     0,     0,     0,     0,
     280,   281,     0,     0,  1697,     0,     0,   282,  2235,     0,
       0,     0,   368,   213,   169,   389,   284,   441,     0,   285,
     214,   215,   216,     0,     0,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   427,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   248,   249,
     250,   251,   399,   400,   401,   402,   252,     0,     0,     0,
     403,   404,   405,   406,     0,     0,     0,     0,     0,   407,
       0,   408,   257,   258,   259,     0,     0,     0,     0,     0,
       0,     0,     0,   260,    25,   409,   261,     0,   410,     0,
       0,     0,   175,     0,     0,   176,     0,     0,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1836,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   586,     0,
       0,   443,     0,     0,     0,     0,     0,     0,   271,   411,
     412,   413,   272,     0,     0,     0,     0,     0,   274,   275,
     276,   414,   277,   278,   279,   415,     0,   416,   119,     0,
     444,   445,   446,   447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   280,   428,     0,     0,     0,
       0,     0,   282,     0,   448,   449,     0,   450,     0,   451,
     213,     6,   367,   452,   285,     0,     0,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,   586,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   368,   213,     6,     0,   369,     0,
     687,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   839,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,  1019,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   510,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   368,
     213,     6,  1736,     0,   579,     0,   285,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,  1217,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   368,   213,     6,     0,   284,     0,
       0,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,  1218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   647,  1901,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   649,
     213,     6,     0,   328,   579,     0,   285,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,  1554,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   283,   213,     6,     0,   284,     0,
       0,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   281,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   368,
     213,     6,     0,   284,     0,     0,   285,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
     169,   389,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,   390,   391,   392,   393,   394,
     395,   396,   397,   398,     0,     0,     0,     0,   399,   400,
     401,   402,     0,     0,     0,     0,   403,   404,   405,   406,
       0,     0,     0,     0,     0,   407,     0,   408,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,   409,     0,     0,   410,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   510,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   368,   213,     6,     0,   574,     0,
       0,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,   411,   412,   413,   254,   255,
     256,     0,     0,     0,   257,   258,   259,   414,     0,     0,
       0,   415,     0,   416,   119,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,   389,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,     0,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,   400,   401,   402,     0,     0,     0,
       0,   403,   404,   405,   406,     0,     0,     0,     0,     0,
     407,     0,   408,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,   409,     0,     0,   410,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   510,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   368,
     213,     6,     0,     0,   579,     0,   285,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
     411,   412,   413,   254,   255,   256,     0,     0,     0,   257,
     258,   259,   414,     0,     0,     0,   415,     0,   416,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,  1831,     0,     0,     0,  1832,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   617,   213,     6,     0,   284,     0,
       0,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  1882,     0,     0,
       0,  1883,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   281,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   626,
     213,     6,     0,   284,     0,     0,   285,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,  1913,     0,     0,     0,  1914,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   510,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   368,   213,     6,     0,   925,     0,
    1399,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  2087,     0,     0,
       0,  2088,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   510,     0,
       0,     0,     0,     0,   282,   213,     6,     0,     0,   368,
    1615,     0,   214,   215,   216,     0,   285,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   797,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   510,     0,
       0,     0,     0,     0,   282,   213,     6,     0,     0,   368,
       0,     0,   214,   215,   216,     0,   285,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   804,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   281,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   368,
     213,     6,     0,  1744,     0,     0,   285,   214,   215,   216,
       0,     0,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,   251,     0,
       0,     0,     0,   252,   253,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,   257,
     258,   259,     0,     0,     0,     0,     0,     0,     0,     0,
     260,    25,     0,   261,     0,     0,     0,     0,     0,   262,
       0,     0,   263,     0,     0,   264,     0,   265,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
       0,    57,    58,     0,   268,     0,   269,     0,     0,   270,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   965,     0,     0,     0,
       0,     0,     0,     0,     0,   271,     0,     0,     0,   272,
     273,     0,     0,     0,     0,   274,   275,   276,     0,   277,
     278,   279,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   647,  1901,     0,     0,     0,     0,     0,   282,
       0,     0,     0,     0,   649,   213,     6,     0,   328,     0,
       0,   285,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
     256,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,     0,   261,     0,
       0,     0,     0,     0,   262,     0,     0,   263,     0,     0,
     264,     0,   265,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   267,     0,    57,    58,     0,   268,
       0,   269,     0,     0,   270,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   966,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,   273,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   510,     0,
       0,     0,     0,     0,   282,   213,   169,   389,     0,   368,
       0,     0,   214,   215,   216,     0,   285,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   427,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     0,
       0,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     248,   249,   250,   251,   399,   400,   401,   402,   252,     0,
       0,     0,   403,   404,   405,   406,     0,     0,     0,     0,
       0,   407,     0,   408,   257,   258,   259,     0,     0,     0,
       0,     0,     0,     0,     0,   260,    25,   409,   261,     0,
     410,   213,   169,   389,     0,     0,     0,     0,   214,   215,
     216,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     427,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   248,   249,   250,   251,
     399,   400,   401,   402,   252,     0,     0,     0,   403,   404,
     405,   406,     0,     0,     0,     0,     0,   407,     0,   408,
     257,   258,   259,     0,     0,     0,     0,     0,     0,     0,
       0,   260,    25,   409,   261,     0,   410,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   411,   412,   413,   272,     0,     0,     0,     0,     0,
     274,   275,   276,   414,   277,   278,   279,   415,     0,   416,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   428,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   368,
       0,     0,     0,  1633,     0,     0,   285,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1016,
       0,     0,     0,     0,     0,     0,   271,   411,   412,   413,
     272,     0,     0,     0,     0,     0,   274,   275,   276,   414,
     277,   278,   279,   415,     0,   416,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,   428,     0,     0,     0,     0,     0,
     282,     0,     0,     0,     0,   368,   213,   169,   389,  1918,
       0,     0,   285,   214,   215,   216,     0,     0,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   427,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,     0,  1637,   391,   392,   393,   394,   395,   396,   397,
     398,   248,   249,   250,   251,   399,   400,   401,   402,   252,
       0,     0,     0,   403,   404,   405,   406,     0,     0,     0,
       0,     0,   407,     0,   408,   257,   258,   259,     0,     0,
       0,     0,     0,     0,     0,     0,   260,    25,   409,   261,
       0,   410,   213,   169,     0,     0,     0,     0,     0,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   427,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,   250,
     251,     0,     0,     0,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,   258,   259,     0,     0,     0,     0,     0,     0,
       0,     0,   260,    25,     0,   261,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   411,   412,   413,   272,     0,     0,     0,     0,
       0,   274,   275,   276,   414,   277,   278,   279,   415,     0,
     416,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   280,   428,
       0,     0,     0,     0,     0,   282,     0,     0,     0,     0,
     368,     0,     0,     0,  1801,     0,     0,   285,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1125,     0,     0,     0,     0,     0,     0,   271,     0,     0,
       0,   272,     0,     0,     0,     0,     0,   274,   275,   276,
       0,   277,   278,   279,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   647,   648,     0,     0,     0,     0,
       0,   282,     0,     0,     0,     0,   649,   213,   169,     0,
     328,     0,   893,   285,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   427,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,   251,     0,     0,     0,     0,
     252,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,   258,   259,     0,
       0,     0,     0,     0,   213,   169,     0,   260,    25,     0,
     261,   214,   215,   216,     0,     0,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   427,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,   251,     0,     0,     0,     0,   252,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   257,   258,   259,    43,    44,    45,    46,
       0,     0,    48,     0,   260,    25,     0,   261,     0,     0,
     778,    56,     0,     0,    59,   779,     0,   780,   781,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,     0,   272,     0,    80,     0,
       0,     0,   274,   275,   276,     0,   277,   278,   279,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,     0,     0,   280,
     428,     0,     0,     0,     0,     0,   282,     0,     0,     0,
       0,   368,     0,     0,     0,     0,     0,     0,   285,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,   271,
       0,  1163,     0,   272,     0,     0,     0,     0,     0,   274,
     275,   276,     0,   277,   278,   279,     0,     0,     0,   119,
     803,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,   428,     0,     0,
       0,     0,     0,   282,   213,   169,     0,  1350,   368,  1114,
       0,   214,   215,   216,     0,   285,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   427,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,   251,     0,     0,     0,     0,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,   260,    25,     0,   261,   213,   169,
       0,  1511,     0,     0,     0,   214,   215,   216,     0,     0,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   427,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,   251,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   258,   259,
       0,     0,     0,     0,     0,     0,     0,     0,   260,    25,
       0,   261,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,     0,     0,   272,     0,     0,     0,     0,     0,   274,
     275,   276,     0,   277,   278,   279,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,   428,     0,     0,
       0,     0,     0,   282,     0,     0,     0,     0,   368,     0,
       0,     0,     0,     0,     0,   285,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1173,     0,
       0,     0,     0,   271,     0,     0,     0,   272,     0,     0,
       0,     0,     0,   274,   275,   276,     0,   277,   278,   279,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     280,   428,     0,     0,     0,     0,     0,   282,   213,   169,
       0,  1577,   368,     0,     0,   214,   215,   216,     0,   285,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   427,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,   251,     0,     0,     0,
       0,   252,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,   258,   259,
       0,     0,     0,     0,     0,   213,   169,     0,   260,    25,
       0,   261,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   427,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   257,   258,   259,    43,    44,    45,
      46,     0,     0,    48,     0,   260,    25,     0,   261,     0,
       0,   778,    56,     0,     0,    59,   779,     0,   780,   781,
       0,   782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,   272,     0,    80,
       0,     0,     0,   274,   275,   276,     0,   277,   278,   279,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,     0,     0,
     280,   428,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,   368,     0,     0,     0,     0,     0,     0,   285,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,     0,     0,
     271,     0,  1174,     0,   272,     0,     0,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,     0,     0,     0,
     119,   973,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   280,   428,     0,
       0,     0,     0,     0,   282,   213,   169,     0,     0,   368,
    1631,     0,   214,   215,   216,     0,   285,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   427,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,   258,   259,     0,     0,     0,
       0,     0,   213,   169,     0,   260,    25,     0,   261,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   427,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,   250,
     251,     0,     0,     0,     0,   252,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,   257,   258,   259,    43,    44,    45,    46,     0,     0,
      48,     0,   260,    25,     0,   261,     0,     0,   778,    56,
       0,     0,    59,   779,     0,   780,   781,     0,   782,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,     0,     0,     0,   272,     0,    80,     0,     0,     0,
     274,   275,   276,     0,   277,   278,   279,   169,   389,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,    97,     0,     0,     0,   280,   428,     0,
       0,     0,     0,     0,   282,     0,     0,     0,     0,   368,
    1965,     0,     0,     0,     0,     0,   285,     0,     0,     0,
       0,     0,   390,   391,   392,   393,   394,   395,   396,   397,
     398,     7,     8,     0,     0,   399,   400,   401,   402,     0,
       0,     0,     0,   403,   404,   405,   406,   271,     0,     0,
       0,   272,   407,     0,   408,     0,     0,   274,   275,   276,
       0,   277,   278,   279,     0,     0,     0,   119,   409,     0,
       0,   410,     0,     0,     0,   175,     0,     0,   176,     0,
       0,   177,     0,   178,   280,   428,     0,     0,     0,     0,
       0,   282,     0,     0,    46,     0,   368,     0,     0,     0,
       0,     0,     0,   285,     0,     0,     0,     0,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     7,     8,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
     778,    56,     0,     0,    59,   779,     0,   780,   781,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,    80,     0,
       0,     0,   411,   412,   413,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   414,     0,     0,     0,   415,     0,
     416,   119,     0,    95,    96,    97,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,  1801,     0,   778,    56,     0,     0,
      59,   779,     0,   780,   781,     0,   782,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    80,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
     998,    43,    44,    45,    46,     0,     0,    48,     0,    95,
      96,    97,     0,     0,     0,   778,    56,     0,     0,    59,
     779,     0,   780,   781,     0,   782,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    80,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,    95,    96,
      97,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,  1048,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,   778,    56,     0,     0,    59,   779,     0,   780,   781,
       0,   782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,    80,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,  1050,    43,    44,    45,    46,
       0,     0,    48,     0,    95,    96,    97,     0,     0,     0,
     778,    56,     0,     0,    59,   779,     0,   780,   781,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,  1250,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   778,    56,     0,     0,
      59,   779,     0,   780,   781,     0,   782,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    80,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
    1252,    43,    44,    45,    46,     0,     0,    48,     0,    95,
      96,    97,     0,     0,     0,   778,    56,     0,     0,    59,
     779,     0,   780,   781,     0,   782,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,  1253,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,   778,    56,     0,     0,    59,   779,     0,   780,   781,
       0,   782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,    80,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,  1272,    43,    44,    45,    46,
       0,     0,    48,     0,    95,    96,    97,     0,     0,     0,
     778,    56,     0,     0,    59,   779,     0,   780,   781,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,  1291,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   778,    56,     0,     0,
      59,   779,     0,   780,   781,     0,   782,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    80,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
    1308,    43,    44,    45,    46,     0,     0,    48,     0,    95,
      96,    97,     0,     0,     0,   778,    56,     0,     0,    59,
     779,     0,   780,   781,     0,   782,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,  1342,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,   778,    56,     0,     0,    59,   779,     0,   780,   781,
       0,   782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,  1503,    43,    44,    45,    46,
       0,     0,    48,     0,    95,    96,    97,     0,     0,     0,
     778,    56,     0,     0,    59,   779,     0,   780,   781,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2146,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,    -4,
      -4,    -4,     0,   605,     0,     0,    -4,    -4,     0,     0,
       0,     0,    -4,  1175,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
    2203,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     6,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       7,     8,     0,     0,     0,     0,     0,     0,    -4,     0,
      -4,    -4,     0,     0,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     9,    10,    11,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1176,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       0,    15,    16,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    18,    19,    20,    21,    22,     0,    23,    24,
       0,    25,     0,     0,     0,     0,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,    42,    43,    44,    45,    46,    47,
       0,    48,     0,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,    65,    66,    67,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,    91,    92,     0,     0,     0,    93,     0,     0,     0,
       0,    94,    95,    96,    97,   169,   389,    98,     0,    99,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,   118,     0,   119,   120,     0,     0,     0,
     390,   391,   392,   393,   394,   395,   396,   397,   398,     0,
       0,     0,     0,   399,   400,   401,   402,     7,     8,     0,
       0,   403,   404,   405,   406,     0,     0,     0,     0,     0,
     407,     0,   408,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   409,     0,     0,   410,
       0,     0,     0,   175,     0,     0,   176,     0,     0,   177,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   778,    56,     0,     0,
      59,   779,     0,   780,   781,     0,   782,     0,     0,     0,
    1060,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     411,   412,   413,     0,    80,     0,     0,     0,  1061,     0,
       0,     0,   414,     0,     0,     0,   415,     0,   416,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,    97,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1177,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1182,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1183,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1185,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1300,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1323,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1409,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1412,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1505,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1506,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1553,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1679,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1680,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1681,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1829,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1952,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1953,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1985,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2057,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2114,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2115,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2130,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2164,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2191,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2196,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2197,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,   836,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  1095,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,  1150,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,  1198,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,     0,  1199,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,  1243,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,  1275,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,  1289,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
    1296,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,  1356,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,  1376,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  1459,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,  1460,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,  1461,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,     0,  1507,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,  1583,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,  1880,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,  1891,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
    1932,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,  2006,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,  2022,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  2034,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,     0,  2058,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,     0,     0,  2093,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,     0,  2103,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,     0,     0,  2104,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,     0,  2128,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,     0,
       0,  2177,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,     0,     0,
    2216,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,     0,     0,  2234,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,     0,     0,  2252,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  2253,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,     0,   737,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,     0,   957,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
       0,  1999,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,   764,     0,   765,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,  1022,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,  1071,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,  1222,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,  1290,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,  1292,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,     0,     0,
    1298,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   736,   601,   602,   603,   604,     0,
       0,     0,     0,   605,     0,     0,     0,  1299,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   736,   601,   602,   603,   604,     0,     0,     0,     0,
     605,     0,     0,     0,  1391,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   736,   601,
     602,   603,   604,     0,     0,     0,     0,   605,     0,     0,
       0,  1405,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   736,   601,   602,   603,   604,
       0,     0,     0,     0,   605,     0,     0,     0,  1612,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,     0,     0,  1700,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   736,
     601,   602,   603,   604,     0,     0,     0,     0,   605,     0,
       0,     0,  1753,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   736,   601,   602,   603,
     604,     0,     0,     0,     0,   605,     0,     0,     0,  1944,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   736,   601,   602,   603,   604,     0,     0,
       0,     0,   605,     0,     0,     0,  1989,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     736,   601,   602,   603,   604,     0,     0,     0,     0,   605,
       0,     0,     0,  2007,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   817,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   818,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   819,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   821,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   822,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   823,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   825,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   826,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   827,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   828,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   829,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   830,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   831,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   833,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   834,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   835,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   905,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,   939,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,   987,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1008,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1011,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1013,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1014,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1020,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1021,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1059,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1070,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1130,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1134,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1146,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1221,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1231,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1232,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1233,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1242,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1244,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1245,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1274,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1276,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1277,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1278,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1279,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1280,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1281,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1282,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1288,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1301,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1303,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1341,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1390,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1404,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1613,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1647,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1687,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1699,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1816,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1818,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1821,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1828,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1881,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1890,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  1917,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  1988,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  2055,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  2056,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   736,   601,   602,   603,   604,     0,     0,     0,
       0,   605,     0,  2190,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   736,   601,   602,
     603,   604,     0,     0,     0,     0,   605,     0,  2231
};

static const yytype_int16 yycheck[] =
{
       3,   160,   321,   644,   645,   146,  1273,  1269,    63,     3,
      69,    70,   761,    72,  1467,   201,     4,  1738,   767,  1784,
       4,  1786,    25,     4,   210,    25,     4,  1968,     7,     4,
       6,   108,     5,     4,     4,   109,     4,   111,     5,     5,
       5,     4,  1771,     7,     4,   163,   108,     4,   452,     0,
       4,     6,    55,   143,   108,   108,     6,     6,     6,     6,
       4,   102,   258,   108,     6,     6,     4,     4,   260,     6,
     266,     4,   146,     4,   266,     9,    36,    37,   132,   132,
     121,    84,    36,    37,     7,     7,   258,    14,     6,   258,
      93,   164,   245,   246,   266,    98,     4,   266,    36,    37,
     174,     9,     9,   193,     6,   260,   109,  1836,   245,   246,
      94,   266,     9,   266,   258,   245,   246,   190,     6,   305,
     306,   307,   266,   105,     9,   262,   108,   109,   110,     6,
     258,   257,  1853,   206,   207,     9,   266,   258,   266,   121,
     245,   246,   263,   146,   257,   257,     9,   259,   151,   152,
     153,   111,   112,   147,   266,     4,   261,   160,   102,   345,
     346,   347,   106,   257,     4,   102,   254,   255,   112,   113,
       6,   115,   116,   111,   112,   263,   362,   180,     7,   257,
     257,   259,  2123,   261,     7,   245,   246,    36,    37,   257,
     261,     7,   136,   196,   265,   257,    36,    37,   201,   254,
     255,   256,   205,   185,     6,   609,   266,   210,   211,   212,
     180,   181,   182,   183,   257,   333,   259,   201,     7,   257,
     245,   246,   192,   261,   194,   195,   196,   197,   198,   178,
     190,   191,   202,   203,   352,   205,     6,   178,   258,  1692,
     228,   266,   205,     6,   228,   257,   266,   228,   258,   261,
     228,   230,   231,   232,   233,     6,   266,   228,   245,   246,
     228,  1523,   111,   112,   267,   324,   325,     6,     7,   245,
     246,   111,   112,   332,   333,  1996,   264,   261,   281,   266,
     261,   284,   285,   261,   259,   285,   261,   258,   261,   260,
     265,   263,   262,   265,   261,   261,   261,   300,   301,   263,
     257,   304,   305,   306,   307,   423,   261,   425,   230,   231,
     232,   233,   315,   261,   261,   257,   319,   435,   321,   261,
     228,  1070,  1071,   257,   257,   259,   257,   245,   246,   263,
    2051,   257,   254,   255,   257,   261,   259,   741,   240,   241,
     343,   263,   345,   346,   347,   105,   254,   255,   108,   257,
     257,   259,   259,   261,     4,   263,   263,   245,   246,   362,
     257,   121,   259,   240,   241,   258,   369,   441,     6,   254,
     255,   775,   257,   266,   259,   260,   245,   246,   263,   565,
     254,   255,   258,   257,   260,   259,   254,   255,   792,   263,
     266,   254,   255,  2158,   257,   554,   259,   266,   802,   261,
     263,   230,   231,   232,   233,     6,   259,   230,   231,   232,
     233,   245,   246,   146,   230,   231,   232,   233,   151,   152,
     153,     4,   257,   257,   259,   254,   255,   261,   431,   259,
     433,   254,   255,   143,   437,   438,   245,   246,   254,   255,
     261,   230,   231,   232,   233,   262,   257,   245,   246,   266,
     453,   161,   261,    36,    37,   143,   105,   460,   143,   108,
     170,   171,   172,   196,   245,   246,   176,   177,   266,   245,
     246,   257,  2193,   161,   245,   246,   161,   245,   246,   212,
     261,   484,   170,   171,   172,   170,   171,   172,   176,   177,
     266,   176,   177,   245,   246,   266,   257,   571,   148,   149,
     150,   151,   258,   907,   154,   245,   246,   510,   257,   143,
     266,   245,   246,   163,   266,   633,   166,   635,   636,   250,
     251,   257,  2243,   245,   246,   256,   266,   161,   111,   112,
     123,   534,   266,  1986,   652,   262,   170,   171,   172,   266,
     543,   544,   176,   177,   266,   548,   705,   550,   551,   552,
     553,   554,   262,   671,   245,   246,   257,   560,   143,   245,
     246,   564,   565,   566,   567,   568,   569,   570,   257,   572,
     570,   574,   572,   257,   262,   266,   161,   262,   257,   697,
     266,   245,   246,   642,   643,   170,   171,   172,   647,   245,
     246,   176,   177,   245,   246,   262,   258,   600,   260,   266,
     245,   246,   266,   606,   266,   108,   105,   190,   191,   108,
     266,   110,   245,   246,   266,   245,   246,   245,   246,   737,
     761,   266,   121,   262,     8,   628,   629,   266,   262,   102,
     262,   257,   105,   266,   266,   108,   266,   110,   266,   258,
     102,   260,  1283,   105,   718,   262,   108,   266,   121,   266,
     644,   645,   262,   245,   246,   258,   266,   260,   257,   121,
     259,     8,   262,   266,   263,   257,   266,   266,  1072,   261,
     258,   257,   260,   262,   677,   678,   679,   266,   266,   682,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   108,   257,   110,   431,   256,
     703,   704,   705,   706,   707,   708,   709,   710,   711,   257,
     713,   714,   715,   716,   717,   257,   719,   720,   721,   722,
     723,   262,   722,   726,   257,   266,   781,   245,   246,   247,
     248,   249,   250,   251,   258,   738,   260,   261,   256,     6,
     254,   255,   816,   257,  1493,   259,     6,   261,   751,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   105,   766,   262,   108,   256,   110,   266,   772,
     247,   248,   249,   250,   251,   254,   255,   148,   149,   256,
     262,   261,   261,   154,   266,   788,   789,   263,   148,   149,
     266,   794,   110,   796,   154,   936,   799,   800,   262,   257,
     261,  1205,   266,  1207,   807,   262,   809,   254,   255,   266,
     257,   257,   259,   259,   262,   548,  1220,   550,   266,   552,
     553,   254,   255,   262,   257,   262,   259,   266,   262,   266,
     257,   261,   266,   262,   567,   568,   839,   266,   841,  1588,
     262,   257,   262,   961,   266,  1249,   266,   108,   105,  1598,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   261,   258,
     262,   260,   256,   876,   266,   949,   257,   262,   262,   261,
    2147,   266,   262,   886,   261,   105,   266,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   964,   909,  1311,  1312,   256,
     262,   258,   971,   260,   266,  1056,   975,  2179,   108,     4,
     262,   262,   925,   262,   266,   266,     4,   266,     6,  1070,
    1071,   262,  1336,   105,   937,   266,   262,  2204,   262,  1343,
     266,   108,   266,   946,     4,     5,  1087,   262,   262,   262,
     108,   266,   266,   266,   957,     4,   262,   262,  1362,  2221,
     266,   266,   262,   262,   262,   262,   266,   266,   266,   266,
     257,   704,   259,   706,   707,   708,   709,   710,   711,     4,
     713,   714,   715,   716,     4,  1389,   719,   720,   721,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   257,  1403,
    1074,   257,    62,    63,    64,    65,  1410,   257,     6,     6,
      70,    71,    72,    73,   262,   259,   262,   259,   266,    79,
     266,    81,   262,   257,   262,   262,   266,    55,   266,   266,
     262,     6,   262,   262,   266,    95,   266,   266,    98,   262,
     262,     6,   102,   266,   266,   105,   261,  1366,   108,   262,
     110,   262,   262,   266,   262,   266,   266,   261,   266,   262,
     262,   121,  1065,   266,   266,   262,   799,   262,  1127,   266,
    1073,   266,   258,   262,   260,   261,   809,   266,  1081,   139,
    1221,  1222,  1723,  1724,   265,     6,   265,   257,   257,     9,
     261,  1094,   257,   257,   257,   257,  1099,   257,   193,   193,
     193,   132,   261,     3,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     257,   257,   257,   257,   256,  1128,  1129,    27,  1131,  1132,
    1133,   193,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,
    1143,  1144,   261,   257,  1147,   257,   257,   257,   261,   209,
     210,   211,   261,     4,   261,   261,   261,   257,   257,   257,
     257,   221,    62,     6,     6,   225,   257,   227,   228,   257,
     257,     6,   261,   259,     6,     6,   193,   261,   261,   261,
     261,   257,   259,   211,  1187,  1188,  1189,   259,   259,   257,
     257,   261,   257,   257,   254,   255,   257,     6,   257,   257,
       6,   261,   259,   263,     6,   261,     6,     8,   261,  1212,
       8,   257,     7,     6,   114,     6,   261,   261,   261,    97,
     262,     7,   258,     6,     6,  1228,  1229,  1230,   266,   266,
     263,   258,   261,    67,   256,   261,     8,   261,   261,   267,
     261,     7,     7,   257,     6,   258,   146,     6,     6,  1390,
    1391,   151,   152,   153,   261,     7,     7,     6,     6,   262,
     160,   190,   261,     6,   258,     7,   262,   262,   260,     6,
     261,   259,  1591,   263,   257,   261,   304,     6,     6,     6,
       6,  1284,     6,   259,   258,     7,     7,   315,     7,  1283,
       7,   319,     7,     7,     7,     7,   196,     7,     7,  1302,
       7,  1304,  1305,     7,     7,     7,     7,     7,   261,     6,
     258,  1314,   212,   260,   266,   266,  1319,   266,   262,   258,
    1323,   266,     7,   263,   262,     7,   261,   261,     4,  1332,
     263,  1334,     6,   143,  1337,   262,   262,   261,     7,  1413,
       6,  1415,     7,     7,     7,   263,   258,   258,     9,   266,
    1353,   266,   266,   253,   258,   260,   263,   265,     7,   164,
     193,  2002,   261,  1366,   262,     6,  1099,     6,     6,   269,
     270,    49,    49,   263,   257,   261,   257,   261,   263,     7,
     257,   263,   257,     7,     7,   193,  1790,   266,  1391,   258,
       7,     7,     7,  1396,     6,  1398,   258,     7,   266,     7,
       7,     7,     7,     4,   120,   261,     6,   257,     7,   437,
     438,     6,  1415,     7,     7,     7,     7,     7,     7,     7,
     261,   102,     6,     6,  1427,   453,     6,     6,  1431,   108,
       7,     7,     6,     4,     7,     7,   264,   266,   258,   266,
    1599,  1600,     6,   261,   261,   261,     6,  1588,   262,     6,
     257,     7,     6,     6,     6,  1188,  1189,   261,  1576,     6,
     259,   257,  1580,  1522,     6,   262,     6,     6,   260,   263,
       6,     6,     6,     6,   136,     6,   266,     6,     6,  1798,
       6,     6,     6,     6,  1487,  1488,  1489,     6,     6,     6,
       5,   258,  1495,  1496,  1497,   258,     6,  1571,     6,     4,
       6,   261,   189,     7,   261,     6,   261,     7,   261,     6,
    1513,   261,   259,     6,     6,   261,   261,   261,     6,     6,
     261,  1524,   261,   551,   262,   261,   261,   261,     6,  1532,
       6,   431,     7,  1536,   266,   266,   564,   257,   566,     6,
     258,   266,   442,   266,  1547,     6,  1549,     6,     6,     4,
     261,   257,     5,     7,     6,   263,   261,  1698,     6,  1633,
       6,   257,     6,   262,   464,   143,     6,   261,   106,   258,
     261,   266,     6,   261,     6,   143,   143,     6,   478,     6,
     266,     6,     6,     6,     6,     6,  1319,   258,  1591,     6,
    1323,  1650,     6,   266,   266,     6,  1599,  1600,   266,  1332,
       6,  1334,  1605,   261,  1337,   261,     6,     6,     6,   261,
       7,     6,     5,   261,   261,   147,   261,     6,   258,     6,
    1623,     6,     6,     6,   261,   261,     7,   262,   262,   261,
    1633,     6,   258,   188,     7,  1638,     6,   262,     6,     6,
     262,   262,  1801,   263,     6,  1719,     6,   261,   548,     6,
     550,     6,   552,   553,   554,     6,     6,     6,  1391,   262,
     258,     6,     6,     6,   261,   261,     6,   567,   568,   191,
       6,     6,   257,   143,     6,   262,   262,   258,     6,   261,
    1739,  1740,  1741,  1742,  1743,  1744,   261,     6,     6,     6,
    1764,   261,   261,     8,     6,   258,   262,  1771,  1772,   261,
     261,     6,     6,   262,   262,     6,     6,  1710,     6,     6,
       6,   261,  1715,  1716,     6,   261,     6,     6,  1792,  2038,
     261,     6,     6,   751,     6,     6,     6,  1402,  2160,  1723,
    1724,  1645,  1462,  1969,  1929,  1738,  1426,  1706,     3,  1083,
       3,  1744,     3,     3,  1998,   621,  1749,     3,   481,  1568,
     650,  1791,  1771,  1600,    -1,  1758,    -1,    -1,   799,    -1,
      -1,    -1,    -1,  1766,    -1,    -1,  1769,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   674,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1787,    -1,    -1,    -1,  1791,    -1,
      -1,    -1,    -1,    -1,    -1,  1798,    -1,  1800,  1801,    -1,
      -1,    -1,    -1,   703,   704,   705,   706,   707,   708,   709,
     710,   711,    -1,   713,   714,   715,   716,    -1,    -1,   719,
     720,   721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   729,
      -1,    -1,   732,  1836,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   745,    -1,    -1,    -1,    -1,
    1853,    -1,    -1,    -1,    -1,    -1,    -1,  1931,    -1,    -1,
      -1,  1864,  1865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     780,   909,   782,    -1,    -1,    -1,  1889,    -1,    -1,    -1,
    1623,    -1,    -1,  2011,    -1,    -1,    -1,    -1,  1901,   799,
    1974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   809,
      -1,    -1,    -1,    -1,    -1,  1918,    -1,    -1,   946,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     8,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,  1955,    -1,    -1,    -1,  2015,  2016,  2017,  2018,
    2019,    -1,    -1,    -1,    -1,    -1,    -1,  1970,    -1,    -1,
      -1,    -1,  1975,    -1,    -1,  1978,  1979,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2108,    -1,    -1,  1996,    -1,    -1,  1999,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2010,  2002,    -1,
      -1,  2014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2079,    -1,    -1,    -1,  2083,    -1,    -1,    -1,    -1,    -1,
    2148,    -1,    -1,  1766,    -1,  2038,  1769,  1065,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2051,    -1,
    2124,    -1,    -1,  1081,    -1,    -1,    -1,    -1,    -1,    -1,
     960,    -1,   962,   963,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2134,   976,  2080,    -1,  2138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2154,   996,    -1,     6,    -1,
    1128,  1129,    -1,  1131,  1132,  1133,    -1,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1017,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2199,  2200,    -1,    -1,    -1,    -1,    -1,  2150,  2151,  2152,
    2153,  2154,    -1,    -1,  1054,    -1,    -1,    -1,    -1,  1187,
      -1,    -1,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,  1212,   256,    -1,   258,    -1,    -1,
    2193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1099,
    1228,    -1,    -1,    -1,    -1,    -1,  2209,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,  2230,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2243,    -1,    -1,    -1,    -1,    -1,  2249,  2250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,    -1,  2262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1302,    -1,  1304,  1305,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,  1189,
      -1,    -1,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1353,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,     3,
       4,  1251,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,  1415,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1427,
      -1,    -1,    -1,  1431,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,  1319,
      -1,    -1,    -1,  1323,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,  1332,    -1,  1334,    -1,    -1,  1337,    -1,    93,
      94,    -1,    96,   143,    -1,    -1,    -1,  1347,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1487,
    1488,  1489,    -1,    -1,    -1,    -1,    -1,  1495,  1496,  1497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1513,    -1,    -1,    -1,    -1,
      -1,  1391,    -1,    -1,    -1,    -1,  1524,  2230,    -1,    -1,
      -1,    -1,    -1,    -1,  1532,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2249,  2250,    -1,  1547,
      -1,  1549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2262,
      -1,    -1,    -1,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,   208,    -1,   256,    -1,   212,    -1,
      -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,   223,
     224,    -1,    -1,    -1,   228,    -1,    -1,  1605,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,   257,    -1,  1633,    -1,   261,    -1,    -1,
     264,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,   185,   186,   187,    -1,   189,   190,
     191,   192,   193,   194,   195,    -1,   197,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1599,
    1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1623,    -1,    -1,    -1,    -1,    -1,    -1,
    1758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   280,
     281,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,  1787,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,   300,
     301,    -1,  1800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   317,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,
      -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   343,   344,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1853,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   368,   369,    -1,
      -1,    -1,    -1,   374,    -1,   376,   377,    -1,   379,    -1,
      -1,    -1,   383,   384,   385,    -1,    -1,   388,    -1,    -1,
      -1,  1889,    -1,    -1,    -1,    -1,  1766,    -1,    -1,  1769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1784,    -1,  1786,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,
      -1,  1801,   433,   434,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,
     451,    -1,    -1,    -1,    -1,    -1,    -1,  1955,    -1,    -1,
      -1,    -1,    -1,    -1,   465,    -1,  1836,    -1,    -1,    -1,
      -1,    -1,  1970,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   486,    -1,    -1,    -1,    -1,
     491,    -1,    -1,    -1,   495,    -1,    -1,    -1,  1996,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,   510,
      -1,    -1,  2010,   514,    -1,    -1,    -1,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,    -1,   546,   547,    -1,   549,    -1,
      -1,    -1,    -1,  2051,    -1,    -1,    -1,    -1,   559,    -1,
      -1,   562,   563,    -1,    -1,    -1,    -1,    -1,   569,    -1,
      -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2080,    -1,    -1,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,    -1,   607,   608,    -1,    -1,
      -1,    -1,    -1,    -1,   615,   616,   617,    -1,    -1,    -1,
      -1,    -1,   623,   624,   625,   626,    -1,   628,   629,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   647,   648,   649,    -1,
      -1,    -1,   653,   654,   655,   656,   657,   658,   659,   660,
     661,    -1,    -1,    -1,    -1,    -1,   667,   668,    -1,   670,
      -1,    -1,   673,     6,    -1,    -1,   677,   678,   679,   680,
      -1,   682,   683,   684,   685,    -1,    -1,    -1,    -1,   690,
      -1,   692,    -1,    -1,    -1,  2193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,   712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2092,    -1,    -1,   726,    -1,    -1,    -1,    -1,
      -1,    -1,   733,   734,    -1,   736,    -1,    -1,   739,   740,
      -1,    -1,    -1,    -1,    -1,  2243,    -1,   748,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   766,    -1,   768,    -1,    -1,
      -1,    -1,   773,   774,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   281,    -1,    -1,   284,    -1,   788,  2158,   790,
     791,    -1,    -1,   794,    -1,   796,   797,    -1,    -1,    -1,
     801,   300,   301,   804,    -1,    -1,    -1,    -1,    -1,   810,
    2180,    -1,    -1,   814,    -1,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,   837,   256,   839,   258,
     841,   260,    -1,    -1,   343,    -1,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     369,    -1,    -1,    -1,    -1,   876,     6,    -1,    -1,  2249,
    2250,    -1,    -1,    -1,    -1,   886,   887,   888,   889,    -1,
      -1,    -1,  2262,    -1,    -1,    -1,    -1,    -1,    -1,   205,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,   925,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   433,    -1,   937,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   945,    -1,    -1,    -1,   949,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   957,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   965,   966,    -1,    -1,    -1,    -1,
     971,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   988,    -1,    -1,
     991,    -1,    -1,    -1,   300,   301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   510,    -1,    -1,    -1,  1016,    -1,  1018,  1019,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   534,  1037,   343,    -1,    -1,
      -1,    -1,    -1,    -1,   543,   544,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1061,    -1,    -1,    -1,    -1,    -1,    -1,  1068,    -1,    -1,
     569,    -1,    -1,    -1,  1075,   574,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1088,  1089,    -1,
      -1,    -1,    -1,  1094,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   600,    -1,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,  1125,    -1,   256,   433,    -1,   628,
     629,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1173,  1174,  1175,  1176,  1177,    -1,   677,   678,
     679,  1182,  1183,   682,  1185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1200,
    1201,    -1,    -1,    -1,    -1,    -1,    -1,  1208,  1209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1217,  1218,    -1,    -1,
      -1,    -1,  1223,  1224,     3,     4,     5,   726,  1229,  1230,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,  1263,    -1,    -1,    -1,    -1,   766,   574,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,   788,
      -1,    70,    71,    72,    73,   794,    -1,   796,    -1,  1300,
      79,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1314,    93,    94,    95,    96,    -1,    98,
      -1,  1322,   628,   629,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     839,    -1,   841,  1344,  1345,    -1,    -1,    -1,  1349,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1360,
      -1,    -1,  1363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   677,   678,   679,    -1,    -1,   682,   876,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   886,    -1,    -1,
      -1,  1392,    -1,    -1,  1395,  1396,  1397,  1398,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1406,    -1,    -1,  1409,    -1,
    1411,  1412,  1413,    -1,    -1,  1416,  1417,    -1,    -1,    -1,
     726,    -1,    -1,    -1,     6,    -1,   925,    -1,    -1,   208,
     209,   210,   211,   212,    -1,    -1,    -1,    -1,   937,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   957,    -1,
     766,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,   788,    -1,    -1,   264,    -1,    -1,   794,    -1,
     796,    -1,    -1,  1494,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,  1505,  1506,    -1,    -1,    -1,    -1,
      -1,    -1,  1513,    -1,  1515,    -1,    -1,    -1,    -1,    -1,
      -1,  1522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1536,    -1,    -1,    -1,     4,
       5,  1542,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1553,  1554,  1555,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     876,    -1,    -1,  1574,    -1,    -1,    -1,    -1,    -1,    -1,
     886,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,  1595,  1094,    -1,    62,    63,    64,
      65,    -1,  1603,  1604,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,     6,    81,    -1,    -1,   925,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,   937,    -1,    98,    -1,    -1,    -1,  1638,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1147,    -1,
      -1,   957,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,  1679,  1680,
    1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1690,
      -1,    -1,    -1,    -1,  1695,  1696,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,  1708,    -1,    -1,
      -1,    -1,    -1,    -1,  1715,  1716,  1717,    -1,  1719,    -1,
      -1,    -1,    -1,    -1,  1725,  1726,    -1,    -1,    -1,    -1,
    1229,  1230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1744,   209,   210,   211,    -1,  1749,  1750,
      -1,    -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,
     225,    -1,   227,  1764,    -1,    -1,  1767,    -1,    -1,    -1,
    1771,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,  1780,
    1781,    -1,  1783,    -1,    -1,    -1,    -1,    -1,  1094,    -1,
      -1,    -1,  1793,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1807,    -1,    -1,    -1,
      -1,  1812,  1813,    -1,    -1,  1314,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1826,    -1,    -1,  1829,  1830,
       6,  1832,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1147,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,  1864,  1865,   256,     6,    -1,    -1,    -1,
    1871,  1872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     560,    -1,  1883,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1892,    -1,    -1,    -1,    -1,    -1,  1396,    -1,  1398,
    1901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1914,  1915,    -1,    -1,  1918,    -1,    -1,
      -1,    -1,    -1,  1229,  1230,    -1,    -1,    -1,    -1,    -1,
      -1,   611,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,  1952,  1953,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1973,    -1,    -1,    -1,    -1,  1978,  1979,  1980,
      -1,    -1,    -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1999,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1314,    -1,
      -1,    -1,    -1,  2014,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2023,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2048,    -1,    -1,
      -1,    -1,    -1,  2054,    -1,    -1,  2057,    -1,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    26,    -1,    28,  2088,    -1,    -1,
    1396,    -1,  1398,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,  2114,  2115,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2129,  2130,
      -1,  2132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1638,
       6,    -1,    -1,    -1,  2145,    -1,    -1,    -1,    -1,  2150,
    2151,  2152,  2153,  2154,    -1,    -1,    -1,    -1,    -1,  2160,
      -1,    -1,    -1,  2164,    -1,    -1,   846,   847,   848,   849,
     850,   851,   852,   853,   854,   855,   856,    -1,   858,   859,
     860,   861,    -1,   863,   864,   865,   866,    -1,    -1,    -1,
    2191,    -1,     6,    -1,    -1,  2196,  2197,    -1,    -1,   879,
      -1,   881,    -1,    -1,   146,    -1,    -1,    -1,  2209,    -1,
      -1,    -1,   892,    -1,    -1,    -1,  1715,  1716,    -1,   899,
     900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   908,    -1,
    1536,    -1,    -1,    -1,    -1,  2236,  2237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1744,    -1,    -1,    -1,    -1,
    1749,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     272,   273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1023,  1024,  1025,    -1,    -1,    -1,  1029,
    1030,    -1,    -1,  1033,  1034,  1035,  1036,    -1,  1038,    -1,
      -1,    -1,    -1,  1043,    -1,  1864,  1865,    -1,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,     6,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1901,    -1,    -1,    -1,    -1,    -1,    -1,  1715,
    1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1918,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,  1749,  1124,    -1,  1126,    -1,   390,   391,
     392,    -1,    -1,    -1,   396,   397,   398,   399,   400,   401,
     402,    -1,   404,    -1,    -1,    -1,    -1,   409,   410,    -1,
      -1,   413,    -1,     4,     5,    -1,    -1,    -1,    -1,  1978,
    1979,    -1,    -1,    -1,    -1,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1999,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2014,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,  1226,    -1,    79,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1864,  1865,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,
      -1,   102,    -1,    -1,   105,    -1,    -1,   108,     6,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,  1918,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,     6,  2132,    -1,    -1,   256,    -1,    -1,    -1,
     582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2150,  2151,  2152,  2153,  2154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1978,  1979,    -1,    -1,    -1,    -1,   209,   210,
     211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,    -1,  1372,  1999,   225,     6,   227,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2014,    -1,
    2209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,   260,
     261,    -1,    -1,    -1,  1414,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,    -1,    -1,    -1,    -1,  1456,  1457,    -1,    -1,
      -1,    -1,    -1,  1463,    -1,  1465,    -1,    -1,    -1,  1469,
      -1,    -1,  1472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1483,    -1,    -1,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,  2132,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2150,  2151,  2152,  2153,  2154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,  1559,
      -1,  1561,   256,    -1,    -1,  1565,    -1,  1567,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1599,
      -1,    -1,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   903,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,   936,   266,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,  1697,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,  1803,   121,    -1,  1806,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,
     137,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,    -1,   154,   155,   156,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,
      -1,    -1,    -1,    -1,  1854,  1855,  1118,  1857,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   210,   211,   212,   213,    -1,    -1,    -1,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1922,  1923,    -1,    -1,    -1,    -1,   245,   246,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,   261,    -1,    -1,   264,    -1,    -1,
      -1,  1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,  1971,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,   134,
     135,    -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,
      -1,  1373,  1374,   148,   149,   150,   151,   152,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
      -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,     7,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1467,    -1,    -1,    -1,    -1,
     245,   246,    -1,    -1,  1476,    -1,    -1,   252,  2218,    -1,
      -1,    -1,   257,     3,     4,     5,   261,     7,    -1,   264,
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
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1637,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,    -1,
      -1,    -1,   252,    -1,   254,   255,    -1,   257,    -1,   259,
       3,     4,     5,   263,   264,    -1,    -1,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
       8,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,     5,    -1,   262,    -1,   264,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
      -1,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,   261,   262,    -1,   264,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
      -1,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,   261,    -1,    -1,   264,    10,    11,    12,
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
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    95,    -1,    -1,    98,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
      -1,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,   209,   210,   211,    76,    77,
      78,    -1,    -1,    -1,    82,    83,    84,   221,    -1,    -1,
      -1,   225,    -1,   227,   228,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   121,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    95,    -1,    -1,    98,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,    -1,   262,    -1,   264,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,    76,    77,    78,    -1,    -1,    -1,    82,
      83,    84,   221,    -1,    -1,    -1,   225,    -1,   227,    -1,
      93,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
      -1,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,   261,    -1,    -1,   264,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
       8,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,     3,     4,    -1,    -1,   257,
       8,    -1,    10,    11,    12,    -1,   264,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,     3,     4,    -1,    -1,   257,
      -1,    -1,    10,    11,    12,    -1,   264,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,   261,    -1,    -1,   264,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,   134,   135,    -1,   137,    -1,   139,    -1,    -1,   142,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,    -1,
     163,    -1,    -1,   166,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,    -1,
      -1,   264,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,     3,     4,     5,    -1,   257,
      -1,    -1,    10,    11,    12,    -1,   264,    15,    16,    17,
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
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,    -1,   227,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
      -1,    -1,    -1,   261,    -1,    -1,   264,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,   257,     3,     4,     5,   261,
      -1,    -1,   264,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      -1,    98,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,
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
      -1,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,   261,    -1,    -1,   264,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,
      -1,   222,   223,   224,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,   257,     3,     4,    -1,
     261,    -1,     8,   264,    10,    11,    12,    -1,    -1,    15,
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
     132,   133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,    -1,   160,    -1,
      -1,    -1,   218,   219,   220,    -1,   222,   223,   224,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,   245,
     246,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,   264,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,   266,    -1,   212,    -1,    -1,    -1,    -1,    -1,   218,
     219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,   228,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,
      -1,    -1,    -1,   252,     3,     4,    -1,     6,   257,   258,
      -1,    10,    11,    12,    -1,   264,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    -1,    96,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
      -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,   218,
     219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,    -1,   208,    -1,    -1,    -1,   212,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,    -1,   222,   223,   224,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,    -1,    -1,    -1,    -1,    -1,   252,     3,     4,
      -1,     6,   257,    -1,    -1,    10,    11,    12,    -1,   264,
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
      -1,   132,   133,    -1,    -1,   136,   137,    -1,   139,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,    -1,    -1,    -1,   212,    -1,   160,
      -1,    -1,    -1,   218,   219,   220,    -1,   222,   223,   224,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,
     245,   246,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,   266,    -1,   212,    -1,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,     3,     4,    -1,    -1,   257,
     258,    -1,    10,    11,    12,    -1,   264,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    93,    94,    -1,    96,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    82,    83,    84,   118,   119,   120,   121,    -1,    -1,
     124,    -1,    93,    94,    -1,    96,    -1,    -1,   132,   133,
      -1,    -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,    -1,   160,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,     4,     5,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,   186,   187,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
     258,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    13,    14,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,   208,    -1,    -1,
      -1,   212,    79,    -1,    81,    -1,    -1,   218,   219,   220,
      -1,   222,   223,   224,    -1,    -1,    -1,   228,    95,    -1,
      -1,    98,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,   110,   245,   246,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,   121,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,    -1,    -1,    -1,    -1,    13,    14,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   160,    -1,
      -1,    -1,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,   225,    -1,
     227,   228,    -1,   185,   186,   187,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,   261,    -1,   132,   133,    -1,    -1,
     136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,   160,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
     262,   118,   119,   120,   121,    -1,    -1,   124,    -1,   185,
     186,   187,    -1,    -1,    -1,   132,   133,    -1,    -1,   136,
     137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   160,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   185,   186,
     187,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,   262,   118,   119,   120,
     121,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,    -1,    -1,   136,   137,    -1,   139,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   160,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,   262,   118,   119,   120,   121,
      -1,    -1,   124,    -1,   185,   186,   187,    -1,    -1,    -1,
     132,   133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,   262,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,    -1,
     136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,   160,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
     262,   118,   119,   120,   121,    -1,    -1,   124,    -1,   185,
     186,   187,    -1,    -1,    -1,   132,   133,    -1,    -1,   136,
     137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,   262,   118,   119,   120,
     121,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,    -1,    -1,   136,   137,    -1,   139,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   160,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,   262,   118,   119,   120,   121,
      -1,    -1,   124,    -1,   185,   186,   187,    -1,    -1,    -1,
     132,   133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,   262,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,    -1,
     136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,   160,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,    -1,
     262,   118,   119,   120,   121,    -1,    -1,   124,    -1,   185,
     186,   187,    -1,    -1,    -1,   132,   133,    -1,    -1,   136,
     137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,   262,   118,   119,   120,
     121,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,    -1,    -1,   136,   137,    -1,   139,   140,
      -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    -1,    -1,   262,   118,   119,   120,   121,
      -1,    -1,   124,    -1,   185,   186,   187,    -1,    -1,    -1,
     132,   133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    67,
      68,    69,    -1,   256,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    80,   266,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    -1,    91,    92,    -1,    94,    -1,    -1,    -1,
     262,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,    -1,    -1,   117,
     118,   119,   120,   121,   122,    -1,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,   144,   145,   146,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,
      -1,    -1,   190,    -1,   192,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,     4,    -1,    -1,    -1,    -1,   214,   215,   216,   217,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   226,    -1,
     228,   229,    -1,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    46,    47,    48,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    -1,    91,    92,
      -1,    94,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,   117,   118,   119,   120,   121,   122,
      -1,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    -1,    -1,    -1,
     173,   174,   175,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,   184,   185,   186,   187,     4,     5,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,    -1,   228,   229,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    13,    14,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,
      -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,    -1,
     136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,
     146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,    -1,   160,    -1,    -1,    -1,   164,    -1,
      -1,    -1,   221,    -1,    -1,    -1,   225,    -1,   227,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     186,   187,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   266,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   266,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   266,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   266,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   266,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,   262,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,   262,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,   262,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,   262,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
     262,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,   262,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,   262,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,   262,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,   262,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
     262,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,   262,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,   262,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,   262,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,   262,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
     262,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,   261,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,   261,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,   261,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,   258,    -1,   260,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,   260,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,   260,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,   260,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,   260,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
     260,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,   260,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   260,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,   260,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,   260,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,   260,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,   260,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,   260,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   268,   269,     6,     0,     4,    13,    14,    46,
      47,    48,    67,    68,    69,    74,    75,    80,    85,    86,
      87,    88,    89,    91,    92,    94,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   117,   118,   119,   120,   121,   122,   124,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   144,   145,   146,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     173,   174,   175,   179,   184,   185,   186,   187,   190,   192,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   214,   215,   216,   217,   226,   228,
     229,   270,   272,   273,   294,   313,   315,   319,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   337,   339,   340,
     346,   347,   348,   349,   355,   379,   380,   261,   265,    14,
     108,   257,   257,   257,     6,   261,     6,     6,     6,     6,
     257,     6,     6,   261,   261,     6,     6,   259,   259,     4,
     357,   380,   257,   259,   291,   102,   105,   108,   110,   315,
     291,   257,   257,   257,     4,   257,   257,   257,     4,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     261,   123,   108,     6,     6,   261,   102,   105,   108,   121,
     318,   110,   257,     3,    10,    11,    12,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    58,    59,
      60,    61,    66,    67,    76,    77,    78,    82,    83,    84,
      93,    96,   102,   105,   108,   110,   121,   132,   137,   139,
     142,   208,   212,   213,   218,   219,   220,   222,   223,   224,
     245,   246,   252,   257,   261,   264,   315,   316,   319,   330,
     337,   339,   350,   351,   355,   357,   363,   365,   380,   257,
     261,   261,   108,   108,   132,   105,   108,   110,   315,   105,
     108,   109,   110,   121,   185,   316,   105,   108,   257,   105,
     164,   190,   206,   207,   261,   245,   246,   257,   261,   360,
     361,   360,   261,   261,   360,     4,   102,   106,   112,   113,
     115,   116,   136,   261,   257,   108,   110,   108,   105,     4,
      94,   201,   261,   380,     4,     6,   102,   105,   108,   105,
     108,   121,   317,   108,     4,     4,     4,     5,   257,   261,
     363,   364,     4,   108,   257,   108,   257,   257,     4,   261,
     367,   380,     4,   257,   257,   257,     6,     6,   259,     5,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    62,
      63,    64,    65,    70,    71,    72,    73,    79,    81,    95,
      98,   209,   210,   211,   221,   225,   227,   371,   380,   257,
       4,   371,     5,   261,     5,   261,   315,    32,   246,   350,
     380,   259,     6,   261,   257,   261,     6,   257,   261,     6,
     265,     7,   139,   201,   230,   231,   232,   233,   254,   255,
     257,   259,   263,   289,   290,   291,   315,   350,   370,   371,
     380,     4,   319,   320,   321,   261,     6,   350,   370,   371,
     380,   370,   370,   350,   370,   377,   378,   380,   321,   350,
     296,   300,   257,   359,     9,   371,   257,   380,   350,   350,
     350,   257,   350,   350,   350,   257,   350,   350,   350,   350,
     350,   350,   350,   370,   350,   350,   350,   350,   364,   257,
     246,   350,   365,   366,   261,   364,   363,   370,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   257,   259,   291,   291,   291,   291,   291,
     291,   257,   291,   291,   257,   315,   316,   316,   316,   291,
     291,     5,   261,   261,   132,   315,   315,   257,   291,   291,
     257,   257,   257,   350,   261,   350,   365,   350,   350,   262,
     366,   357,   380,   193,     5,   261,     8,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   256,     9,   257,   259,   263,
     290,   291,   350,   366,   366,   257,   257,   257,   363,   364,
     364,   364,   314,   257,   261,   257,   257,   363,   261,   261,
     350,     4,   363,   261,   367,   261,   261,   360,   360,   360,
     350,   350,   245,   246,   261,   261,   360,   245,   246,   257,
     321,   360,   261,   257,   261,   257,   257,   257,   257,   257,
     257,   257,   366,   350,   364,   364,   364,   257,   261,     4,
     259,   261,     6,   259,   321,     6,     6,   261,   261,   261,
     261,   364,   261,   259,   259,   259,   350,     8,     6,     6,
     257,   350,   257,   350,   350,   263,   350,   261,   193,   350,
     350,   350,   350,   291,   291,   291,   257,   257,   257,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   257,
     257,   291,   257,   259,     6,     6,   261,     6,     8,   321,
       6,     8,   321,   257,   291,   350,   247,   261,     9,   257,
     259,   263,   370,   366,   350,   321,   363,   363,   261,   371,
     315,     7,   350,   350,     4,    36,    37,   111,   112,   190,
     191,   293,   363,     6,   258,   260,   261,   292,   261,     6,
     261,     6,     9,   257,   259,   263,   380,   262,   132,   137,
     139,   140,   142,   313,   315,   350,     6,   258,   266,     9,
     257,   259,   263,   258,   266,   258,   266,   266,   258,   266,
       9,   257,   263,   262,   266,   260,   266,   295,   260,   295,
      97,   358,   356,   380,   266,   350,   266,   258,   258,   258,
     350,   258,   258,   258,   350,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   262,     7,   350,   247,
     262,   266,   350,     6,     6,   258,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   365,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   365,   365,   380,   261,   350,   350,   370,
     350,   370,   363,   370,   370,   377,   261,   261,   261,   261,
     350,   292,   380,     8,   350,   350,   364,   363,   370,   370,
     365,   357,   371,   357,   366,   258,   262,   263,   291,    67,
       8,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   261,   350,   365,   350,   350,
     350,   350,   350,   380,   350,   350,   293,   261,   292,   258,
     262,   262,   350,   350,   350,     7,     7,   343,   343,   257,
     350,   350,   350,   350,     6,   366,   366,   261,   258,     6,
     321,   261,   321,   321,   266,   266,   266,   360,   360,   320,
     320,   266,   350,   262,   334,   266,   321,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   262,   258,     7,   344,
       6,     7,   350,   350,     6,   350,   321,   350,   262,   366,
     366,   366,   350,     6,   366,   350,   350,   350,   258,   262,
     350,   258,   350,   258,   258,   190,   266,   321,   261,     8,
     258,   258,   260,   377,   370,   377,   370,   370,   370,   370,
     370,   370,   350,   370,   370,   370,   370,   264,   373,   380,
     371,   370,   370,   370,   357,   380,   366,   262,   262,   262,
     262,   350,   350,   350,   321,   380,   293,   260,   262,   258,
     146,   164,   338,   258,   262,   266,   350,     6,   261,   363,
     258,   260,   263,     7,     7,   289,   290,     6,   366,     7,
     233,   289,   350,   274,   380,   350,   350,   293,   259,   257,
     132,   315,   316,   315,   261,   262,     6,   240,   241,   271,
     366,   380,   350,   350,   293,     6,   366,     6,   366,   350,
       6,   370,   378,   380,   258,   293,   350,     6,   380,     6,
     370,   350,   258,   259,   350,   266,   371,     7,     7,     7,
     258,     7,     7,     7,   258,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   350,   258,   261,   350,   365,
     262,     6,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   266,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   266,   266,   266,   266,   266,   258,   260,
     260,   366,   266,   266,   292,   266,   292,   266,   266,   266,
     258,   366,   350,   350,   350,   352,   292,   262,   262,   262,
     266,   266,   292,   292,   258,   263,   258,   263,   266,   291,
     353,   262,     7,   293,   292,   363,   262,     8,     8,   366,
     263,   258,   260,   257,   259,   290,   291,   366,     7,   261,
     261,   258,   258,   258,   350,   363,     4,   342,     6,   309,
     350,   371,   258,   262,   258,   258,   262,   262,   366,   263,
     262,   321,   262,   262,   360,   350,   350,   262,   262,   350,
     360,   143,   143,   161,   170,   171,   172,   176,   177,   335,
     336,   360,   262,   331,   258,   262,   258,   258,   258,   258,
     258,   258,   258,   261,     7,   350,     6,   350,   258,   262,
     260,   262,   260,   262,   262,   262,   262,   262,   260,   260,
     266,   258,     7,   258,     7,     7,   263,   350,   262,   350,
     350,     7,   263,   292,   266,   292,   292,   258,   258,   266,
     292,   292,   266,   266,   292,   292,   292,   292,   350,   292,
       9,   372,   266,   258,   266,   292,   263,   266,   354,   260,
     262,   258,   262,   263,   257,   259,   265,   193,     7,   164,
       6,   350,   262,   261,     6,   363,   262,   350,     6,     7,
     289,   290,   263,   289,   290,   293,   261,   368,   380,   371,
     350,     6,   262,    49,    49,   363,   262,     4,   180,   181,
     182,   183,   262,   277,   281,   284,   286,   287,   329,   263,
     258,   260,   257,   350,   350,   257,   261,   257,   261,     8,
     366,   370,   258,   263,   258,   260,   257,   258,   258,   266,
     263,   257,   266,     7,   291,     4,    36,    37,   303,   304,
     305,   292,   350,   292,   360,   363,   363,     7,   363,   363,
     363,     7,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,     6,     7,   366,   350,   350,   350,   350,   350,
     350,   262,   350,   350,   350,   363,   370,   370,   262,   262,
     262,   262,   266,   302,   350,   350,   293,   293,   350,   350,
     258,   363,   291,   350,   350,   262,   293,   290,   263,   290,
     350,   350,   292,   262,   363,   366,   366,     7,     7,     7,
     143,   341,     6,   258,   266,     7,     7,     7,     7,     7,
     262,     4,   293,   262,   266,   266,   266,   262,   262,   120,
       4,     6,   350,   261,     6,   257,     6,   178,     6,   178,
     262,   336,   266,   335,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   320,   363,     6,   261,   102,     6,     6,
       6,   108,     7,     7,     6,     6,   350,     7,   363,     7,
     363,   363,     4,   266,     8,     8,   258,   293,   293,   366,
     370,   350,   370,   264,   266,   306,   370,   370,   293,   370,
     258,   266,     6,   293,   261,   315,   261,     6,   350,     6,
     261,   363,   262,   262,   350,     6,   190,   191,   293,   350,
       6,     7,   367,   369,     6,   259,     6,     6,   292,   291,
     291,     6,   278,   257,   257,   261,   288,     6,   293,   263,
     370,   350,   260,   258,   350,     8,   366,   350,   366,   262,
     262,     6,     6,   271,   293,   263,   350,     6,     6,   350,
     293,   258,   350,   261,   350,   371,   292,    49,   261,   363,
     371,   374,   350,   350,   260,   266,     6,   258,     6,     6,
     136,   311,   311,   363,     6,     6,     6,   363,   143,   193,
     310,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   262,   292,   292,   292,   292,   292,   292,   292,   266,
     266,   266,   258,   292,   292,   304,   292,   258,   292,   258,
     291,   353,   292,     6,   292,   257,   259,   291,   293,   258,
     260,   292,     6,   262,   262,   363,   363,   363,     4,     6,
     289,   350,   363,   363,   363,   261,   261,     7,     6,     7,
     350,   350,   350,   261,   261,   261,   259,     6,   350,   363,
     350,     6,     6,   350,   360,   262,     5,   363,   261,   261,
     261,   261,   261,   261,   261,   363,   262,     6,   366,   261,
     261,   350,   350,   260,   363,     6,   363,     6,   189,   350,
     350,   350,     6,     6,     7,   292,   266,   266,   292,   266,
     350,     4,   205,   307,   308,   292,   258,   292,   354,   371,
     257,   259,   350,   261,   321,     6,   321,   266,     6,     6,
     263,     7,     7,   289,   290,     6,   367,   262,   266,   350,
     289,   261,   292,   375,   376,   377,   375,   257,   350,   350,
     362,   363,   261,   257,     4,     6,   258,     6,   258,   262,
     262,   258,   262,     6,     6,   370,   257,     4,   258,   266,
     257,   262,   266,   363,   371,     7,   291,   301,   350,   365,
     305,     6,   360,     6,     6,     6,   143,   312,   102,   121,
     106,     6,     5,   261,   350,   350,   350,   350,   258,   353,
     350,   350,   292,   290,   261,   261,     6,   310,     6,   350,
     363,   143,   143,     4,     6,   366,   366,   350,   350,   371,
     262,   258,   262,   266,   320,   320,   350,   350,   262,   266,
     258,   262,   266,     6,     6,   362,   360,   360,   360,   360,
     360,   246,   360,     6,   262,   366,   350,     6,     6,     6,
       6,     6,   363,   262,   266,     8,   262,   258,   261,   350,
     371,   370,   350,   370,   350,   371,   374,   376,   371,   266,
     258,   266,   262,   350,   338,   338,   363,   293,   368,   371,
     350,     6,     6,   367,   260,   363,   377,     6,   292,   292,
     275,   350,   266,   266,   262,   266,   276,   350,   350,     6,
       6,     6,     6,   350,   350,   258,     6,   350,   297,   299,
     261,   376,   262,   266,     7,     7,   147,     6,   261,   261,
     261,     5,   362,   292,   292,   266,   292,   258,   258,   260,
     366,   366,     6,     6,   350,   350,   261,   262,   262,   261,
       6,     6,   261,   350,   262,   262,   262,   260,     6,   363,
       7,   261,   350,   262,   266,   266,   266,   266,   266,   266,
       6,   262,   262,   188,   350,   350,   366,     6,     6,   258,
     292,   292,   308,   371,   262,   262,   262,   262,     7,     6,
       6,     6,   263,     6,   262,     6,     6,   258,   266,   350,
     350,   261,   363,   262,   266,   258,   258,   266,   262,   302,
     306,   363,   292,   350,   371,   380,   366,   366,   350,     6,
     262,   350,   353,   262,   262,     6,     6,   362,   148,   149,
     154,   345,   148,   149,   345,   366,   320,   262,   266,     6,
     262,   363,   321,   262,     6,   366,   360,   360,   360,   360,
     360,     6,   350,   262,   262,   262,   258,     6,   261,     6,
     367,   191,   279,   350,   266,   266,   362,     6,   350,   350,
       6,   262,   262,   298,     7,   257,   262,   262,   262,   261,
     266,   258,   261,   262,   261,   360,   363,     6,   261,   360,
       6,   262,   262,   350,     6,   143,   262,   332,   261,   262,
     266,   266,   266,   266,   266,     6,     6,     6,   321,     6,
     261,   350,   350,   262,   266,   302,   371,   258,   350,   350,
     366,     6,   360,     6,   360,     6,     6,   262,   350,   335,
     321,     6,   366,   366,   366,   366,   360,   366,   338,   276,
     258,   266,     6,   261,   350,   262,   266,   266,   262,   266,
     266,     6,   262,   262,   333,   262,   262,   262,   262,   266,
     262,   262,   262,   282,   350,   362,   262,   350,   350,   360,
     360,   335,     6,     6,     6,     6,   366,     6,     6,     6,
     261,   258,   262,     6,   262,   292,   266,   266,   262,   262,
     280,   370,   285,   261,     6,   350,   350,     6,   262,   266,
     261,   362,   262,   262,     6,   370,   283,   370,   262,     6,
       6,   262,   266,     6,     6,   370
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
      gmsh_yyfactory = (yyvsp[(3) - (5)].c);
      if(gmsh_yyfactory == "OpenCASCADE"){
        if(!GModel::current()->getOCCInternals())
          GModel::current()->createOCCInternals();
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getOCCInternals()->setMaxTag
            (dim, std::max(GModel::current()->getOCCInternals()->getMaxTag(dim),
                           GModel::current()->getGEOInternals()->getMaxTag(dim)));
      }
      else if(GModel::current()->getOCCInternals()){
        for(int dim = -2; dim <= 3; dim++)
          GModel::current()->getGEOInternals()->setMaxTag
            (dim, std::max(GModel::current()->getGEOInternals()->getMaxTag(dim),
                           GModel::current()->getOCCInternals()->getMaxTag(dim)));
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 10:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 310 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 311 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 312 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 315 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 316 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 317 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 318 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 319 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 320 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 321 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 322 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 323 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 324 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 329 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 333 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 340 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 345 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 350 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 31:
#line 355 "Gmsh.y"
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
#line 369 "Gmsh.y"
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
#line 382 "Gmsh.y"
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
#line 395 "Gmsh.y"
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
#line 408 "Gmsh.y"
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
#line 436 "Gmsh.y"
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
#line 450 "Gmsh.y"
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
#line 463 "Gmsh.y"
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
#line 476 "Gmsh.y"
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
#line 494 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 47:
#line 509 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 48:
#line 511 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 49:
#line 516 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 50:
#line 518 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 51:
#line 523 "Gmsh.y"
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
#line 627 "Gmsh.y"
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
#line 637 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 54:
#line 646 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 653 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 663 "Gmsh.y"
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
#line 672 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 58:
#line 681 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 59:
#line 688 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 60:
#line 698 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 61:
#line 706 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 62:
#line 716 "Gmsh.y"
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
#line 735 "Gmsh.y"
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
#line 754 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 65:
#line 760 "Gmsh.y"
    {
    ;}
    break;

  case 66:
#line 767 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 67:
#line 768 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 769 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 69:
#line 770 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 70:
#line 771 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 71:
#line 775 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 72:
#line 776 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 73:
#line 782 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 74:
#line 782 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 75:
#line 784 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 76:
#line 784 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 789 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 78:
#line 790 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 79:
#line 791 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 80:
#line 792 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 793 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 803 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 808 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 814 "Gmsh.y"
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
              std::vector<double>::iterator it = std::find(s.value.begin(),
                                                           s.value.end(), d);
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
#line 876 "Gmsh.y"
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
#line 891 "Gmsh.y"
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
          std::vector<double>::iterator it = std::find(s.value.begin(),
                                                       s.value.end(), d);
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
#line 920 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 930 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 935 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 943 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 948 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 956 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 965 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 970 "Gmsh.y"
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
#line 982 "Gmsh.y"
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
#line 999 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 1005 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 1014 "Gmsh.y"
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
#line 1032 "Gmsh.y"
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
#line 1050 "Gmsh.y"
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
#line 1059 "Gmsh.y"
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
#line 1071 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 1076 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1084 "Gmsh.y"
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
#line 1104 "Gmsh.y"
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
#line 1127 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (5)].l), tags);
      if(!strcmp((yyvsp[(1) - (5)].c),"Background")) {
	if (tags.size() > 1)
	  yymsg(0, "Only 1 field can be set as a background field.");
	else if (tags.size() == 0)
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
#line 1147 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1155 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->numericalValue((yyvsp[(8) - (9)].d)); }
	  catch(...){
	    yymsg(0, "Cannot assign a numerical value to option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
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
    ;}
    break;

  case 112:
#line 1177 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (9)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (9)].c)];
	if(option){
	  try { option->string((yyvsp[(8) - (9)].c)); }
	  catch (...){
	    yymsg(0, "Cannot assign a string value to  option '%s' "
		  "in field %i of type '%s'", (yyvsp[(6) - (9)].c), (int)(yyvsp[(3) - (9)].d), field->getName());
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
      Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 113:
#line 1200 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      Field *field = GModel::current()->getFields()->get((int)(yyvsp[(3) - (11)].d));
      if(field){
	FieldOption *option = field->options[(yyvsp[(6) - (11)].c)];
	if(option){
	  if (option->getType() == FIELD_OPTION_LIST) {
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
#line 1238 "Gmsh.y"
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
#line 1259 "Gmsh.y"
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
#line 1271 "Gmsh.y"
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
#line 1289 "Gmsh.y"
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
#line 1298 "Gmsh.y"
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
#line 1307 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1309 "Gmsh.y"
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
#line 1327 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1329 "Gmsh.y"
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
#line 1345 "Gmsh.y"
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
#line 1354 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1356 "Gmsh.y"
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
#line 1370 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1378 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1384 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1389 "Gmsh.y"
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
#line 1432 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      for(int i = 0; i < List_Nbr((yyvsp[(2) - (2)].l)); i++){
        double v;
        List_Read((yyvsp[(2) - (2)].l), i, &v);
        floatOptions[key].push_back(v);
        if (flag_Enum && !i) { member_ValMax = (int)v; }
      }
      Free((yyvsp[(1) - (2)].c));
      List_Delete((yyvsp[(2) - (2)].l));
    ;}
    break;

  case 141:
#line 1444 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1448 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1452 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (1)].c));
      double v;
      if (!flag_Enum) {
        v = 1.;
        if (key == "Enum") flag_Enum = 1;
      }
      else
        v = (double)++member_ValMax;
      floatOptions[key].push_back(v);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 144:
#line 1465 "Gmsh.y"
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
#line 1479 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1487 "Gmsh.y"
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
#line 1512 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 152:
#line 1520 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 153:
#line 1529 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1537 "Gmsh.y"
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
#line 1551 "Gmsh.y"
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
#line 1569 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1573 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1580 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1588 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 160:
#line 1592 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 161:
#line 1598 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 162:
#line 1602 "Gmsh.y"
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
#line 1613 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 164:
#line 1617 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 165:
#line 1623 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 166:
#line 1627 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 167:
#line 1633 "Gmsh.y"
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
#line 1656 "Gmsh.y"
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
#line 1672 "Gmsh.y"
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
#line 1688 "Gmsh.y"
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
#line 1705 "Gmsh.y"
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
#line 1722 "Gmsh.y"
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
#line 1759 "Gmsh.y"
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
#line 1803 "Gmsh.y"
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
#line 1819 "Gmsh.y"
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
#line 1836 "Gmsh.y"
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
#line 1867 "Gmsh.y"
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
#line 1883 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addLineLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addLineLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add line loop");
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SEGM_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1900 "Gmsh.y"
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
#line 1916 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(6) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1){
          yymsg(0, "OpenCASCADE surface filling requires a single line loop");
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
#line 1966 "Gmsh.y"
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
#line 1984 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single line loop");
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
#line 2005 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> wires; ListOfDouble2Vector((yyvsp[(7) - (8)].l), wires);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(wires.size() != 1) {
          yymsg(0, "OpenCASCADE BSpline filling requires a single line loop");
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
#line 2026 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 185:
#line 2032 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2038 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2045 "Gmsh.y"
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
#line 2076 "Gmsh.y"
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
#line 2091 "Gmsh.y"
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
#line 2113 "Gmsh.y"
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
#line 2136 "Gmsh.y"
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
#line 2159 "Gmsh.y"
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
#line 2182 "Gmsh.y"
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
#line 2206 "Gmsh.y"
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
#line 2230 "Gmsh.y"
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
#line 2254 "Gmsh.y"
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
#line 2280 "Gmsh.y"
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
#line 2297 "Gmsh.y"
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
#line 2313 "Gmsh.y"
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
#line 2331 "Gmsh.y"
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
#line 2349 "Gmsh.y"
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
#line 2362 "Gmsh.y"
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
#line 2374 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 204:
#line 2378 "Gmsh.y"
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
#line 2404 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 206:
#line 2406 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 207:
#line 2408 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 208:
#line 2410 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 209:
#line 2412 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 210:
#line 2420 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 211:
#line 2422 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 212:
#line 2424 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 213:
#line 2426 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 214:
#line 2434 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 215:
#line 2436 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 216:
#line 2438 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 217:
#line 2446 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 218:
#line 2448 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 219:
#line 2450 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 220:
#line 2452 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 221:
#line 2462 "Gmsh.y"
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
#line 2478 "Gmsh.y"
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
#line 2494 "Gmsh.y"
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
#line 2510 "Gmsh.y"
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
#line 2526 "Gmsh.y"
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
#line 2542 "Gmsh.y"
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
#line 2559 "Gmsh.y"
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
#line 2596 "Gmsh.y"
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
#line 2617 "Gmsh.y"
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
#line 2638 "Gmsh.y"
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
#line 2663 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 232:
#line 2664 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 233:
#line 2669 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 234:
#line 2673 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 235:
#line 2677 "Gmsh.y"
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
#line 2694 "Gmsh.y"
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
#line 2714 "Gmsh.y"
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
#line 2734 "Gmsh.y"
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
#line 2753 "Gmsh.y"
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
#line 2780 "Gmsh.y"
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
#line 2799 "Gmsh.y"
    {
      int t = (int)(yyvsp[(4) - (10)].d);
      if(gLevelset::find(t)){
	yymsg(0, "Levelset %d already exists", t);
      }
      else {
	fullMatrix<double> centers(List_Nbr((yyvsp[(8) - (10)].l)),3);
	for (int i = 0; i < List_Nbr((yyvsp[(8) - (10)].l)); i++){
	  List_T *l = *(List_T**)List_Pointer((yyvsp[(8) - (10)].l), i);
	  for (int j = 0; j < List_Nbr(l); j++){
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
#line 2821 "Gmsh.y"
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
#line 2836 "Gmsh.y"
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
#line 2851 "Gmsh.y"
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
#line 2870 "Gmsh.y"
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
#line 2921 "Gmsh.y"
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
#line 2942 "Gmsh.y"
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
#line 2964 "Gmsh.y"
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
#line 2986 "Gmsh.y"
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
          gLevelset *ls = NULL;
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
#line 3091 "Gmsh.y"
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
#line 3107 "Gmsh.y"
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
#line 3142 "Gmsh.y"
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
        GModel::current()->remove(dimTags);
      }
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3164 "Gmsh.y"
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
        GModel::current()->remove(dimTags, true);
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3186 "Gmsh.y"
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
#line 3198 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 256:
#line 3204 "Gmsh.y"
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
#line 3219 "Gmsh.y"
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
#line 3250 "Gmsh.y"
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
#line 3262 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 260:
#line 3271 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 261:
#line 3278 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 262:
#line 3290 "Gmsh.y"
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
#line 3310 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 264:
#line 3314 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 265:
#line 3319 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 266:
#line 3323 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 267:
#line 3328 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 268:
#line 3335 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 269:
#line 3342 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 270:
#line 3349 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 271:
#line 3361 "Gmsh.y"
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
#line 3434 "Gmsh.y"
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
#line 3452 "Gmsh.y"
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
#line 3477 "Gmsh.y"
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
#line 3492 "Gmsh.y"
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
#line 3541 "Gmsh.y"
    {
#if defined(HAVE_FLTK)
      FlGui::instance()->splitCurrentOpenglWindow('u');
#endif
    ;}
    break;

  case 277:
#line 3547 "Gmsh.y"
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
#line 3559 "Gmsh.y"
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
#line 3591 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 280:
#line 3595 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 281:
#line 3600 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 282:
#line 3607 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 283:
#line 3612 "Gmsh.y"
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
#line 3622 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 285:
#line 3627 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 286:
#line 3633 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 287:
#line 3641 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals! Make it optional?
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 288:
#line 3649 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 289:
#line 3653 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 290:
#line 3657 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 291:
#line 3661 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 292:
#line 3668 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 293:
#line 3672 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 294:
#line 3676 "Gmsh.y"
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

  case 295:
#line 3688 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 296:
#line 3698 "Gmsh.y"
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

  case 297:
#line 3761 "Gmsh.y"
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

  case 298:
#line 3777 "Gmsh.y"
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

  case 299:
#line 3794 "Gmsh.y"
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

  case 300:
#line 3811 "Gmsh.y"
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

  case 301:
#line 3833 "Gmsh.y"
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

  case 302:
#line 3855 "Gmsh.y"
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

  case 303:
#line 3890 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 304:
#line 3898 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 305:
#line 3906 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 306:
#line 3912 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 307:
#line 3919 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 308:
#line 3926 "Gmsh.y"
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

  case 309:
#line 3946 "Gmsh.y"
    {
      if(ImbricatedTest > 0){
        if (statusImbricatedTests[ImbricatedTest]){
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

  case 310:
#line 3972 "Gmsh.y"
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

  case 311:
#line 3984 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 312:
#line 3995 "Gmsh.y"
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

  case 313:
#line 4013 "Gmsh.y"
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

  case 314:
#line 4031 "Gmsh.y"
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

  case 315:
#line 4049 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4055 "Gmsh.y"
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

  case 317:
#line 4073 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 4079 "Gmsh.y"
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

  case 319:
#line 4099 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 320:
#line 4105 "Gmsh.y"
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

  case 321:
#line 4123 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 322:
#line 4129 "Gmsh.y"
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

  case 323:
#line 4146 "Gmsh.y"
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

  case 324:
#line 4162 "Gmsh.y"
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

  case 325:
#line 4179 "Gmsh.y"
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

  case 326:
#line 4197 "Gmsh.y"
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

  case 327:
#line 4220 "Gmsh.y"
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

  case 328:
#line 4247 "Gmsh.y"
    {
    ;}
    break;

  case 329:
#line 4250 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 4256 "Gmsh.y"
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

  case 331:
#line 4268 "Gmsh.y"
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

  case 332:
#line 4288 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 333:
#line 4292 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 334:
#line 4296 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 335:
#line 4300 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 336:
#line 4304 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 337:
#line 4308 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 338:
#line 4312 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 339:
#line 4316 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 340:
#line 4325 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 341:
#line 4337 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 342:
#line 4338 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 343:
#line 4339 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 344:
#line 4340 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 345:
#line 4341 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 346:
#line 4345 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 347:
#line 4346 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 348:
#line 4347 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 349:
#line 4348 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 350:
#line 4349 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 351:
#line 4354 "Gmsh.y"
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

  case 352:
#line 4377 "Gmsh.y"
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

  case 353:
#line 4397 "Gmsh.y"
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

  case 354:
#line 4418 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 355:
#line 4422 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Progression") || !strcmp((yyvsp[(2) - (3)].c), "Power"))
        (yyval.v)[0] = 1.;
      else if(!strcmp((yyvsp[(2) - (3)].c), "Bump"))
        (yyval.v)[0] = 2.;
      else{
        yymsg(0, "Unknown transfinite mesh type");
        (yyval.v)[0] = 1.;
      }
      (yyval.v)[1] = (yyvsp[(3) - (3)].d);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 356:
#line 4437 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 357:
#line 4441 "Gmsh.y"
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

  case 358:
#line 4457 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 359:
#line 4461 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 360:
#line 4466 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 361:
#line 4470 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 362:
#line 4476 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 363:
#line 4480 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 364:
#line 4487 "Gmsh.y"
    {
      // mesh sizes at vertices are stored in internal CAD data, as they can be
      // specified during vertex creation and copied around during CAD
      // operations
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

  case 365:
#line 4509 "Gmsh.y"
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

  case 366:
#line 4550 "Gmsh.y"
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

  case 367:
#line 4594 "Gmsh.y"
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

  case 368:
#line 4633 "Gmsh.y"
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

  case 369:
#line 4658 "Gmsh.y"
    {
      int dim = (int)(yyvsp[(2) - (8)].i);
      int tag = (int)(yyvsp[(4) - (8)].d);
      GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
      if(ge){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	ge->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model entity of dimension %d and tag %d", dim, tag);
      }
    ;}
    break;

  case 370:
#line 4671 "Gmsh.y"
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

  case 371:
#line 4682 "Gmsh.y"
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

  case 372:
#line 4699 "Gmsh.y"
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

  case 373:
#line 4716 "Gmsh.y"
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

  case 374:
#line 4746 "Gmsh.y"
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

  case 375:
#line 4772 "Gmsh.y"
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

  case 376:
#line 4799 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master lines (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        std::vector<double> transfo;
        if(List_Nbr((yyvsp[(10) - (11)].l)) != 0) {
          if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
            yymsg(0, "Affine transformation requires at least 12 entries (we have %d)",
                  List_Nbr((yyvsp[(10) - (11)].l)));
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

  case 377:
#line 4831 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (11)].l)) != List_Nbr((yyvsp[(8) - (11)].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (11)].l)), List_Nbr((yyvsp[(4) - (11)].l)));
      }
      else{
        if (List_Nbr((yyvsp[(10) - (11)].l)) < 12){
          // FIXME full automatic case here if List_Nbr($10) == 0)
          yymsg(0, "Affine transformation requires at least 12 entries");
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

  case 378:
#line 4858 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master curves (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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

  case 379:
#line 4884 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (18)].l)) != List_Nbr((yyvsp[(8) - (18)].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (18)].l)), List_Nbr((yyvsp[(4) - (18)].l)));
      }
      else{
        SPoint3 origin((yyvsp[(14) - (18)].v)[0],(yyvsp[(14) - (18)].v)[1],(yyvsp[(14) - (18)].v)[2]);
        SPoint3 axis((yyvsp[(12) - (18)].v)[0],(yyvsp[(12) - (18)].v)[1],(yyvsp[(12) - (18)].v)[2]);
        double  angle((yyvsp[(16) - (18)].d));
        SPoint3 translation(0,0,0);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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

  case 380:
#line 4910 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master curves (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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

  case 381:
#line 4936 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(4) - (12)].l)) != List_Nbr((yyvsp[(8) - (12)].l))){
        yymsg(0, "Number of master surfaces (%d) different from number of "
              "slaves (%d) ", List_Nbr((yyvsp[(8) - (12)].l)), List_Nbr((yyvsp[(4) - (12)].l)));
      }
      else{
        SPoint3 origin(0,0,0);
        SPoint3 axis(0,0,0);
        double  angle(0);
        SPoint3 translation((yyvsp[(11) - (12)].v)[0],(yyvsp[(11) - (12)].v)[1],(yyvsp[(11) - (12)].v)[2]);

        std::vector<double> transfo;
        computeAffineTransformation(origin,axis,angle,translation,transfo);

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

  case 382:
#line 4962 "Gmsh.y"
    {
      if (List_Nbr((yyvsp[(5) - (12)].l)) != List_Nbr((yyvsp[(10) - (12)].l))){
        yymsg(0, "Number of master surface curves (%d) different from number of "
              "slave (%d) curves", List_Nbr((yyvsp[(10) - (12)].l)), List_Nbr((yyvsp[(5) - (12)].l)));
      }
      else{
        int j_master = (int)(yyvsp[(8) - (12)].d);
        int j_slave = (int)(yyvsp[(3) - (12)].d);
        std::map<int,int> edgeCounterParts;
        for (int i = 0; i < List_Nbr((yyvsp[(5) - (12)].l)); i++){
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

  case 383:
#line 4983 "Gmsh.y"
    {
      if (((yyvsp[(6) - (10)].i)==2 || (yyvsp[(6) - (10)].i)==3) && (yyvsp[(1) - (10)].i)<(yyvsp[(6) - (10)].i) ) {
        std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (10)].l), tags);
        addEmbedded((yyvsp[(1) - (10)].i), tags, (yyvsp[(6) - (10)].i), (int)(yyvsp[(8) - (10)].d));
      }
      else {
        yymsg(0, "GeoEntity of dim %d In GeoEntity of dim %d not allowed", (yyvsp[(1) - (10)].i), (yyvsp[(6) - (10)].i));
      }
      List_Delete((yyvsp[(3) - (10)].l));
    ;}
    break;

  case 384:
#line 4994 "Gmsh.y"
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

  case 385:
#line 5042 "Gmsh.y"
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

  case 386:
#line 5096 "Gmsh.y"
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

  case 387:
#line 5111 "Gmsh.y"
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

  case 388:
#line 5123 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 389:
#line 5134 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 390:
#line 5141 "Gmsh.y"
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

  case 391:
#line 5156 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 392:
#line 5169 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 393:
#line 5170 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 394:
#line 5171 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 395:
#line 5176 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 396:
#line 5182 "Gmsh.y"
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

  case 397:
#line 5194 "Gmsh.y"
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

  case 398:
#line 5212 "Gmsh.y"
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

  case 399:
#line 5239 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 400:
#line 5240 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 401:
#line 5241 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 402:
#line 5242 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 403:
#line 5243 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 404:
#line 5244 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5245 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 406:
#line 5246 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5248 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 408:
#line 5254 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 409:
#line 5255 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 410:
#line 5256 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 411:
#line 5257 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 412:
#line 5258 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5259 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5260 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5261 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5262 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5263 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5264 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5265 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5266 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 421:
#line 5267 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 422:
#line 5268 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 423:
#line 5269 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5270 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 425:
#line 5271 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 426:
#line 5272 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5273 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5274 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5275 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5276 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5277 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 432:
#line 5278 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5279 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 434:
#line 5280 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5281 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5282 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5283 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5284 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 439:
#line 5285 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 440:
#line 5286 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 441:
#line 5287 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 442:
#line 5288 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5289 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5290 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5291 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 446:
#line 5292 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5293 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 448:
#line 5302 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 449:
#line 5303 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 450:
#line 5304 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 451:
#line 5305 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 452:
#line 5306 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 453:
#line 5307 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 454:
#line 5308 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 455:
#line 5309 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 456:
#line 5310 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 457:
#line 5311 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 458:
#line 5312 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 459:
#line 5317 "Gmsh.y"
    { init_options(); ;}
    break;

  case 460:
#line 5319 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 461:
#line 5325 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 462:
#line 5329 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 463:
#line 5334 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 464:
#line 5339 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 465:
#line 5344 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 466:
#line 5349 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 467:
#line 5353 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 468:
#line 5357 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 469:
#line 5361 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 470:
#line 5365 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 471:
#line 5369 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 472:
#line 5373 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 473:
#line 5377 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 474:
#line 5383 "Gmsh.y"
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

  case 475:
#line 5398 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 476:
#line 5402 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 477:
#line 5408 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 478:
#line 5413 "Gmsh.y"
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

  case 479:
#line 5432 "Gmsh.y"
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
#line 5452 "Gmsh.y"
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

  case 481:
#line 5473 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 482:
#line 5477 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 483:
#line 5481 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 484:
#line 5485 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 485:
#line 5489 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 486:
#line 5493 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 487:
#line 5497 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 488:
#line 5502 "Gmsh.y"
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

  case 489:
#line 5512 "Gmsh.y"
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

  case 490:
#line 5522 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 491:
#line 5527 "Gmsh.y"
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

  case 492:
#line 5538 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 493:
#line 5547 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 494:
#line 5552 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 495:
#line 5557 "Gmsh.y"
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

  case 496:
#line 5584 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 497:
#line 5586 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 498:
#line 5591 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 499:
#line 5593 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 500:
#line 5598 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 501:
#line 5605 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (7)].c2).char1? (yyvsp[(2) - (7)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (7)].c2).char2);
      Free((yyvsp[(2) - (7)].c2).char1); Free((yyvsp[(2) - (7)].c2).char2);
      int tag_out;
      if (gmsh_yynamespaces.defStruct(struct_namespace, struct_name,
                                      floatOptions, charOptions,
                                      tag_out, member_ValMax, (yyvsp[(3) - (7)].i)))
        yymsg(0, "Redefinition of Struct '%s::%s'",
              struct_namespace.c_str(), struct_name.c_str());
      (yyval.d) = (double)tag_out;
    ;}
    break;

  case 502:
#line 5621 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 503:
#line 5623 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 504:
#line 5628 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 505:
#line 5630 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 506:
#line 5635 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 507:
#line 5637 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 508:
#line 5642 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 509:
#line 5646 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 510:
#line 5650 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 511:
#line 5654 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 512:
#line 5658 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 513:
#line 5665 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 514:
#line 5669 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 515:
#line 5673 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 516:
#line 5677 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 517:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 518:
#line 5689 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 519:
#line 5696 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 520:
#line 5701 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 521:
#line 5705 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 522:
#line 5710 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 523:
#line 5714 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 524:
#line 5722 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 525:
#line 5733 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 526:
#line 5737 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 527:
#line 5741 "Gmsh.y"
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

  case 528:
#line 5755 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 529:
#line 5763 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 530:
#line 5771 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 531:
#line 5778 "Gmsh.y"
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

  case 532:
#line 5788 "Gmsh.y"
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

  case 533:
#line 5811 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 534:
#line 5816 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 535:
#line 5822 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 536:
#line 5827 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 537:
#line 5833 "Gmsh.y"
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

  case 538:
#line 5844 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 539:
#line 5850 "Gmsh.y"
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

  case 540:
#line 5864 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 541:
#line 5870 "Gmsh.y"
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

  case 542:
#line 5882 "Gmsh.y"
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

  case 543:
#line 5896 "Gmsh.y"
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

  case 544:
#line 5909 "Gmsh.y"
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

  case 545:
#line 5919 "Gmsh.y"
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

  case 546:
#line 5929 "Gmsh.y"
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

  case 547:
#line 5939 "Gmsh.y"
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

  case 548:
#line 5951 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 549:
#line 5955 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 550:
#line 5960 "Gmsh.y"
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

  case 551:
#line 5972 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 552:
#line 5976 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 553:
#line 5980 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 554:
#line 5984 "Gmsh.y"
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

  case 555:
#line 6002 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 556:
#line 6010 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 557:
#line 6018 "Gmsh.y"
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
            fscanf(File, "%s", dummy);
            yymsg(0, "Ignoring '%s' in file '%s'", dummy, (yyvsp[(3) - (4)].c));
          }
        }
	fclose(File);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 558:
#line 6047 "Gmsh.y"
    {
      double x0 = (yyvsp[(3) - (14)].d), x1 = (yyvsp[(5) - (14)].d), y0 = (yyvsp[(7) - (14)].d), y1 = (yyvsp[(9) - (14)].d), ys = (yyvsp[(11) - (14)].d);
      int N = (int)(yyvsp[(13) - (14)].d);
      std::vector<double> y(N);
      if(!catenary(x0, x1, y0, y1, ys, N, &y[0]))
        Msg::Warning("Catenary did not converge, using linear interpolation");
      (yyval.l) = List_Create(N,10,sizeof(double));
      for(int i = 0; i < N; i++) List_Add((yyval.l), &y[i]);
    ;}
    break;

  case 559:
#line 6057 "Gmsh.y"
    {
      std::vector<double> tmp;
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double d; List_Read((yyvsp[(3) - (4)].l), i, &d);
        tmp.push_back(d);
      }
      std::sort(tmp.begin(), tmp.end());
      std::vector<double>::iterator last = std::unique(tmp.begin(), tmp.end());
      tmp.erase(last, tmp.end());
      (yyval.l) = (yyvsp[(3) - (4)].l);
      List_Reset((yyval.l));
      for(std::size_t i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    ;}
    break;

  case 560:
#line 6073 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 561:
#line 6084 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 562:
#line 6089 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 563:
#line 6093 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 564:
#line 6097 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 565:
#line 6109 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 566:
#line 6113 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 567:
#line 6125 "Gmsh.y"
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

  case 568:
#line 6142 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 569:
#line 6152 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 570:
#line 6156 "Gmsh.y"
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

  case 571:
#line 6171 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 572:
#line 6176 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 573:
#line 6183 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 574:
#line 6187 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 575:
#line 6192 "Gmsh.y"
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

  case 576:
#line 6206 "Gmsh.y"
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

  case 577:
#line 6220 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 578:
#line 6224 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 579:
#line 6228 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 580:
#line 6232 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 581:
#line 6236 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 582:
#line 6244 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 583:
#line 6250 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 584:
#line 6259 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 585:
#line 6263 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 586:
#line 6267 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 587:
#line 6275 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 588:
#line 6281 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 589:
#line 6287 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 590:
#line 6291 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 591:
#line 6298 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 592:
#line 6306 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 593:
#line 6313 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 594:
#line 6322 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 595:
#line 6326 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 596:
#line 6330 "Gmsh.y"
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

  case 597:
#line 6345 "Gmsh.y"
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

  case 598:
#line 6359 "Gmsh.y"
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

  case 599:
#line 6373 "Gmsh.y"
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

  case 600:
#line 6385 "Gmsh.y"
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

  case 601:
#line 6401 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 602:
#line 6410 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 603:
#line 6419 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        if (i > 0 && (yyvsp[(3) - (4)].c)[i-1] != '_')
          (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 604:
#line 6429 "Gmsh.y"
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

  case 605:
#line 6440 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 606:
#line 6448 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 607:
#line 6456 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 608:
#line 6460 "Gmsh.y"
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

  case 609:
#line 6479 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 610:
#line 6486 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 611:
#line 6492 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 612:
#line 6498 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 613:
#line 6505 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 614:
#line 6512 "Gmsh.y"
    { init_options(); ;}
    break;

  case 615:
#line 6514 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 616:
#line 6522 "Gmsh.y"
    {
      std::string out;
      const std::string * key_struct = NULL;
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

  case 617:
#line 6546 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 618:
#line 6548 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 619:
#line 6554 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 620:
#line 6559 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 621:
#line 6561 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 622:
#line 6566 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 623:
#line 6571 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 624:
#line 6576 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 625:
#line 6578 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 626:
#line 6582 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 627:
#line 6594 "Gmsh.y"
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

  case 628:
#line 6608 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 629:
#line 6612 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 630:
#line 6619 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 631:
#line 6627 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 632:
#line 6635 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 633:
#line 6646 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 634:
#line 6648 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 635:
#line 6651 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14862 "Gmsh.tab.cpp"
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


#line 6654 "Gmsh.y"


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
  for(std::map<std::string, gmsh_yysymbol>::iterator it = gmsh_yysymbols.begin();
      it != gmsh_yysymbols.end(); it++){
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
  for(std::map<std::string, std::vector<std::string> >::iterator it =
        gmsh_yystringsymbols.begin(); it != gmsh_yystringsymbols.end(); it++){
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
  if (gmsh_yynamespaces.size()){
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
    if(dim >= 0 && dim <= 3) v.push_back(std::pair<int, int>(dim, s.Num));
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
  Msg::Error("'%s', line %d : %s (%s)", gmsh_yyname.c_str(), gmsh_yylineno - 1,
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
    Msg::Error("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
    gmsh_yyerrorstate++;
  }
  else if(level == 1){
    Msg::Warning("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
  }
  else{
    Msg::Info("'%s', line %d : %s", gmsh_yyname.c_str(), gmsh_yylineno - 1, tmp);
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
  if (!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget, iSource);
  }
  else target->setMeshMaster(source, affineTransform);
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
  std::map<int,int>::const_iterator sIter = edgeCounterparts.begin();
  for (; sIter != edgeCounterparts.end(); ++sIter) {
    Msg::Info("%d - %d", sIter->first, sIter->second);
  }

  GFace *target = GModel::current()->getFaceByTag(std::abs(iTarget));
  GFace *source = GModel::current()->getFaceByTag(std::abs(iSource));
  if (!target || !source) {
    Msg::Error("Could not find surface %d or %d for periodic copy",
               iTarget,iSource);
  }
  else target->setMeshMaster(source, edgeCounterparts);
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
  if (!target || !source)
    Msg::Error("Could not find curve %d or %d for periodic copy",
               iTarget,iSource);
  if (affineTransform.size() >= 12) {
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

  tfo[0*4+0] = ca + ux*ux*(1.-ca);
  tfo[0*4+1] = ux*uy*(1.-ca) - uz * sa;
  tfo[0*4+2] = ux*uz*(1.-ca) + uy * sa;

  tfo[1*4+0] = ux*uy*(1.-ca) + uz * sa;
  tfo[1*4+1] = ca + uy*uy*(1.-ca);
  tfo[1*4+2] = uy*uz*(1.-ca) - ux * sa;

  tfo[2*4+0] = ux*uz*(1.-ca) - uy * sa;
  tfo[2*4+1] = uy*uz*(1.-ca) + ux * sa;
  tfo[2*4+2] = ca + uz*uz*(1.-ca);

  int idx = 0;
  for (size_t i = 0; i < 3; i++,idx++) {
    int tIdx = i*4+3;
    tfo[tIdx] = origin[i] + translation[i];
    for (int j = 0; j < 3; j++,idx++) tfo[tIdx] -= tfo[idx] * origin[j];
  }

  for (int i = 0; i < 4; i++) tfo[12+i] = 0;
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
  for(std::map<int, std::vector<GEntity*> >::iterator it = groups.begin();
      it != groups.end(); it++){
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
    std::map<int, std::vector<GEntity*> >::iterator it = groups.find(num);
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
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    else { // Get (0) or GetForced (2)
      if (type_var == 1) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(s.value.empty()){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s'", c2);
        }
        else
          out = s.value[0];
      }
      else if (type_var == 2) {
        gmsh_yysymbol &s(gmsh_yysymbols[c2]);
        if(index < 0 || (int)s.value.size() < index + 1){
          out = val_default;
          if (type_treat == 0) yymsg(0, "Uninitialized variable '%s[%d]'", c2, index);
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
    if (type_var == 1) {
      std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
      if(gmsh_yynamespaces.getTag(struct_namespace, struct_name, out)) {
        out = val_default;
        if (type_treat == 0) yymsg(0, "Unknown variable '%s'", struct_name.c_str());
      }
    }
    else {
      out = val_default;
      if (type_treat == 0) yymsg(0, "Unknown variable '%s(.)'", c2);
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
    if (type_treat == 1) out = 1.; // Exists (type_treat == 1)
    break;
  case 1:
    if (!NumberOption(GMSH_GET, c2, 0, c3, out, type_treat==0))
      out = val_default;
    break;
  case 2:
    if (type_treat != 0) {
      const std::string * out_dummy = NULL;
      out = (gmsh_yynamespaces.getMember
             (struct_namespace, struct_name, key_member, out_dummy))?
        val_default : 1.;
    }
    else {
      out = val_default;
      if (type_treat == 0)
        yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    }
    break;
  case 3:
    out = val_default;
    if (type_treat == 0)
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
  List_T * out, * val_default = NULL;
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
  const std::string * out = NULL;
  std::string out_tmp;
  if(!c1 && gmsh_yystringsymbols.count(c2)){
    // Get (0) or GetForced (2)
    if(gmsh_yystringsymbols[c2].size() != 1){
      out = &string_default;
      if (type_treat == 0)
        yymsg(0, "Expected single valued string variable '%s'", c2);
    }
    else {
      out_tmp = gmsh_yystringsymbols[c2][0];
      out = &out_tmp;
    }
  }
  else{
    out = &string_default;
    if (type_treat == 0) yymsg(0, "Unknown string variable '%s'", c2);
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
  const std::string * out = NULL;
  std::string out_tmp; // PD: we should avoid that -> StringOption() to be changed
  std::string struct_namespace(c1? c1 : std::string("")), struct_name(c2);
  std::string key_member(c3);
  switch (gmsh_yynamespaces.getMember
          (struct_namespace, struct_name, key_member, out, index)) {
  case 0:
    break;
  case 1:
    if (StringOption(GMSH_GET, c2, 0, c3, out_tmp, type_treat==0))
      out = &out_tmp;
    else
      out = &string_default;
    break;
  case 2:
    out = &string_default;
    if (type_treat == 0)
      yymsg(0, "Unknown member '%s' of Struct %s", c3, struct_name.c_str());
    break;
  case 3:
    out = &string_default;
    if (type_treat == 0)
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
  List_T * out, * val_default = NULL;
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

