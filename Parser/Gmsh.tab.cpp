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
#define YYLAST   17900

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  267
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  636
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2272

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
    1557,  1560,  1563,  1566,  1569,  1585,  1588,  1591,  1599,  1602,
    1612,  1624,  1627,  1632,  1635,  1638,  1641,  1644,  1661,  1673,
    1680,  1689,  1698,  1709,  1711,  1714,  1717,  1719,  1723,  1727,
    1732,  1737,  1739,  1741,  1747,  1759,  1773,  1774,  1782,  1783,
    1797,  1798,  1814,  1815,  1822,  1832,  1835,  1839,  1850,  1864,
    1866,  1869,  1875,  1883,  1886,  1889,  1893,  1896,  1900,  1903,
    1907,  1917,  1924,  1926,  1928,  1930,  1932,  1934,  1935,  1938,
    1942,  1946,  1951,  1961,  1966,  1981,  1982,  1986,  1987,  1989,
    1990,  1993,  1994,  1997,  1998,  2001,  2008,  2016,  2023,  2029,
    2033,  2042,  2049,  2058,  2067,  2073,  2078,  2085,  2097,  2109,
    2128,  2147,  2160,  2173,  2186,  2197,  2202,  2207,  2212,  2217,
    2222,  2225,  2229,  2236,  2238,  2240,  2242,  2245,  2251,  2259,
    2270,  2272,  2276,  2279,  2282,  2285,  2289,  2293,  2297,  2301,
    2305,  2309,  2313,  2317,  2321,  2325,  2329,  2333,  2337,  2341,
    2345,  2349,  2353,  2357,  2363,  2368,  2373,  2378,  2383,  2388,
    2393,  2398,  2403,  2408,  2413,  2420,  2425,  2430,  2435,  2440,
    2445,  2450,  2455,  2460,  2467,  2474,  2481,  2486,  2493,  2500,
    2502,  2504,  2506,  2508,  2510,  2512,  2514,  2516,  2518,  2520,
    2522,  2523,  2530,  2532,  2537,  2544,  2546,  2551,  2556,  2561,
    2568,  2574,  2582,  2591,  2602,  2607,  2612,  2619,  2624,  2628,
    2631,  2637,  2643,  2647,  2653,  2660,  2669,  2676,  2685,  2692,
    2697,  2705,  2712,  2719,  2726,  2731,  2738,  2743,  2744,  2747,
    2748,  2751,  2752,  2760,  2762,  2766,  2768,  2771,  2772,  2776,
    2778,  2781,  2784,  2788,  2792,  2804,  2814,  2822,  2830,  2832,
    2836,  2838,  2840,  2843,  2847,  2852,  2858,  2860,  2864,  2866,
    2869,  2873,  2877,  2883,  2888,  2893,  2896,  2901,  2904,  2908,
    2912,  2917,  2923,  2929,  2935,  2941,  2943,  2945,  2947,  2951,
    2957,  2965,  2970,  2975,  2980,  2987,  2994,  3003,  3012,  3017,
    3032,  3037,  3042,  3044,  3046,  3050,  3054,  3064,  3072,  3074,
    3080,  3084,  3091,  3093,  3097,  3099,  3101,  3106,  3111,  3115,
    3121,  3128,  3137,  3144,  3149,  3155,  3157,  3162,  3164,  3166,
    3168,  3170,  3175,  3182,  3187,  3194,  3200,  3208,  3213,  3218,
    3223,  3232,  3237,  3242,  3247,  3252,  3261,  3270,  3277,  3282,
    3289,  3294,  3296,  3298,  3303,  3308,  3309,  3316,  3321,  3324,
    3329,  3334,  3336,  3338,  3342,  3344,  3346,  3350,  3354,  3358,
    3364,  3372,  3378,  3384,  3393,  3395,  3397
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
      -1,    85,   261,   350,   266,   350,   262,     6,    -1,    85,
       6,    -1,    87,   261,   350,   266,   350,   266,   350,   262,
       6,    -1,    87,   261,   350,   266,   350,   266,   350,   266,
     350,   262,     6,    -1,    86,     6,    -1,    86,   261,   321,
     262,    -1,    88,     6,    -1,    89,     6,    -1,   126,     6,
      -1,   127,     6,    -1,   128,   261,   366,   262,   261,   366,
     262,   261,   362,   262,   261,   350,   266,   350,   262,     6,
      -1,   204,   257,   261,   366,   262,   266,   371,   266,   371,
     258,     6,    -1,   192,   257,   350,     8,   350,   258,    -1,
     192,   257,   350,     8,   350,     8,   350,   258,    -1,   192,
       4,   193,   261,   350,     8,   350,   262,    -1,   192,     4,
     193,   261,   350,     8,   350,     8,   350,   262,    -1,   194,
      -1,   205,     4,    -1,   205,   371,    -1,   202,    -1,   203,
     380,     6,    -1,   203,   371,     6,    -1,   195,   257,   350,
     258,    -1,   196,   257,   350,   258,    -1,   197,    -1,   198,
      -1,   152,   360,   261,   321,   262,    -1,   152,   261,   360,
     266,   360,   266,   350,   262,   261,   321,   262,    -1,   152,
     261,   360,   266,   360,   266,   360,   266,   350,   262,   261,
     321,   262,    -1,    -1,   152,   360,   261,   321,   331,   335,
     262,    -1,    -1,   152,   261,   360,   266,   360,   266,   350,
     262,   261,   321,   332,   335,   262,    -1,    -1,   152,   261,
     360,   266,   360,   266,   360,   266,   350,   262,   261,   321,
     333,   335,   262,    -1,    -1,   152,   261,   321,   334,   335,
     262,    -1,   152,   261,   321,   262,   143,   120,   261,   350,
     262,    -1,   132,   363,    -1,   137,   132,   363,    -1,   134,
     261,   366,   262,   261,   366,   262,   261,   366,   262,    -1,
     135,   261,   366,   262,   261,   366,   262,   261,   366,   262,
     261,   366,   262,    -1,   336,    -1,   335,   336,    -1,   170,
     261,   350,   262,     6,    -1,   170,   261,   363,   266,   363,
     262,     6,    -1,   171,     6,    -1,   161,     6,    -1,   161,
     350,     6,    -1,   176,     6,    -1,   176,   178,     6,    -1,
     177,     6,    -1,   177,   178,     6,    -1,   172,   257,   350,
     258,     7,   363,   143,   350,     6,    -1,   143,     4,   259,
     350,   260,     6,    -1,   155,    -1,   156,    -1,   157,    -1,
     158,    -1,   159,    -1,    -1,   164,     6,    -1,   146,   164,
       6,    -1,   164,   350,     6,    -1,   146,   164,   350,     6,
      -1,   337,   261,   321,   338,   262,   261,   321,   338,   262,
      -1,   117,   257,   370,   258,    -1,   337,   257,   350,   258,
       7,   261,   321,   338,   262,   261,   321,   338,   262,     6,
      -1,    -1,   143,     4,   350,    -1,    -1,     4,    -1,    -1,
       7,   363,    -1,    -1,     7,   350,    -1,    -1,   154,   363,
      -1,   122,   123,   364,     7,   350,     6,    -1,   138,   105,
     364,     7,   350,   341,     6,    -1,   138,   108,   364,   343,
     342,     6,    -1,   138,   110,   364,   343,     6,    -1,   179,
     364,     6,    -1,   100,   315,   257,   350,   266,   350,   258,
       6,    -1,   214,   315,   257,   350,   258,     6,    -1,   167,
     108,   261,   366,   262,     7,   350,     6,    -1,   169,   108,
     261,   366,   262,     7,   350,     6,    -1,   161,   108,   364,
     344,     6,    -1,   161,   110,   364,     6,    -1,   162,   108,
     364,     7,   350,     6,    -1,   141,   105,   261,   366,   262,
       7,   261,   366,   262,   345,     6,    -1,   141,   108,   261,
     366,   262,     7,   261,   366,   262,   345,     6,    -1,   141,
     105,   261,   366,   262,     7,   261,   366,   262,   148,   261,
     360,   266,   360,   266,   350,   262,     6,    -1,   141,   108,
     261,   366,   262,     7,   261,   366,   262,   148,   261,   360,
     266,   360,   266,   350,   262,     6,    -1,   141,   105,   261,
     366,   262,     7,   261,   366,   262,   149,   360,     6,    -1,
     141,   108,   261,   366,   262,     7,   261,   366,   262,   149,
     360,     6,    -1,   141,   108,   350,   261,   366,   262,     7,
     350,   261,   366,   262,     6,    -1,   315,   261,   366,   262,
     193,   315,   261,   350,   262,     6,    -1,   168,   317,   364,
       6,    -1,   129,   318,   364,     6,    -1,   130,   110,   363,
       6,    -1,   145,   105,   363,     6,    -1,   140,   316,   363,
       6,    -1,   165,     6,    -1,   165,     4,     6,    -1,   165,
     102,   261,   366,   262,     6,    -1,   215,    -1,   216,    -1,
     217,    -1,   348,     6,    -1,   348,   261,   363,   262,     6,
      -1,   348,   261,   363,   266,   363,   262,     6,    -1,   348,
     257,   363,   258,   261,   363,   266,   363,   262,     6,    -1,
     351,    -1,   257,   350,   258,    -1,   246,   350,    -1,   245,
     350,    -1,   252,   350,    -1,   350,   246,   350,    -1,   350,
     245,   350,    -1,   350,   247,   350,    -1,   350,   248,   350,
      -1,   350,   250,   350,    -1,   350,   251,   350,    -1,   350,
     249,   350,    -1,   350,   256,   350,    -1,   350,   239,   350,
      -1,   350,   240,   350,    -1,   350,   244,   350,    -1,   350,
     243,   350,    -1,   350,   238,   350,    -1,   350,   237,   350,
      -1,   350,   236,   350,    -1,   350,   235,   350,    -1,   350,
     241,   350,    -1,   350,   242,   350,    -1,   350,   234,   350,
       8,   350,    -1,    16,   291,   350,   292,    -1,    17,   291,
     350,   292,    -1,    18,   291,   350,   292,    -1,    19,   291,
     350,   292,    -1,    20,   291,   350,   292,    -1,    21,   291,
     350,   292,    -1,    22,   291,   350,   292,    -1,    23,   291,
     350,   292,    -1,    24,   291,   350,   292,    -1,    26,   291,
     350,   292,    -1,    27,   291,   350,   266,   350,   292,    -1,
      28,   291,   350,   292,    -1,    29,   291,   350,   292,    -1,
      30,   291,   350,   292,    -1,    31,   291,   350,   292,    -1,
      32,   291,   350,   292,    -1,    33,   291,   350,   292,    -1,
      34,   291,   350,   292,    -1,    35,   291,   350,   292,    -1,
      38,   291,   350,   266,   350,   292,    -1,    39,   291,   350,
     266,   350,   292,    -1,    40,   291,   350,   266,   350,   292,
      -1,    25,   291,   350,   292,    -1,    37,   291,   350,   266,
     350,   292,    -1,    36,   291,   350,   266,   350,   292,    -1,
       3,    -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,
     222,    -1,   223,    -1,   224,    -1,    82,    -1,    83,    -1,
      84,    -1,    -1,    93,   291,   350,   352,   302,   292,    -1,
     355,    -1,   212,   291,   370,   292,    -1,   212,   291,   370,
     266,   350,   292,    -1,   357,    -1,   380,   259,   350,   260,
      -1,   380,   257,   350,   258,    -1,   218,   257,   357,   258,
      -1,   218,   257,   357,   263,   293,   258,    -1,   220,   257,
     357,   353,   258,    -1,   220,   257,   357,   263,   293,   353,
     258,    -1,   220,   257,   357,   291,   350,   292,   353,   258,
      -1,   220,   257,   357,   263,   293,   291,   350,   292,   353,
     258,    -1,   219,   257,   371,   258,    -1,   264,   380,   291,
     292,    -1,   264,   357,   263,   293,   291,   292,    -1,    96,
     291,   380,   292,    -1,    96,   291,   292,    -1,   380,   290,
      -1,   380,   259,   350,   260,   290,    -1,   380,   257,   350,
     258,   290,    -1,   380,   263,   293,    -1,   380,     9,   380,
     263,   293,    -1,   380,   263,   293,   257,   350,   258,    -1,
     380,     9,   380,   263,   293,   257,   350,   258,    -1,   380,
     263,   293,   259,   350,   260,    -1,   380,     9,   380,   263,
     293,   259,   350,   260,    -1,   380,   259,   350,   260,   263,
     293,    -1,   380,   263,   293,   290,    -1,   380,   259,   350,
     260,   263,   293,   290,    -1,   208,   257,   370,   266,   350,
     258,    -1,    59,   257,   363,   266,   363,   258,    -1,    60,
     291,   370,   266,   370,   292,    -1,    58,   291,   370,   292,
      -1,    61,   291,   370,   266,   370,   292,    -1,    66,   257,
     377,   258,    -1,    -1,   266,   350,    -1,    -1,   266,   370,
      -1,    -1,    94,   357,   359,   356,   259,   303,   260,    -1,
     380,    -1,   380,     9,   380,    -1,    97,    -1,    97,   350,
      -1,    -1,   257,   358,   258,    -1,   361,    -1,   246,   360,
      -1,   245,   360,    -1,   360,   246,   360,    -1,   360,   245,
     360,    -1,   261,   350,   266,   350,   266,   350,   266,   350,
     266,   350,   262,    -1,   261,   350,   266,   350,   266,   350,
     266,   350,   262,    -1,   261,   350,   266,   350,   266,   350,
     262,    -1,   257,   350,   266,   350,   266,   350,   258,    -1,
     363,    -1,   362,   266,   363,    -1,   350,    -1,   365,    -1,
     261,   262,    -1,   261,   366,   262,    -1,   246,   261,   366,
     262,    -1,   350,   247,   261,   366,   262,    -1,   363,    -1,
     261,     8,   262,    -1,     5,    -1,   246,   365,    -1,   350,
     247,   365,    -1,   350,     8,   350,    -1,   350,     8,   350,
       8,   350,    -1,   102,   261,   350,   262,    -1,   102,   261,
       8,   262,    -1,   102,     5,    -1,   316,   261,     8,   262,
      -1,   316,     5,    -1,   139,   315,   364,    -1,   142,   315,
     363,    -1,   315,   193,    67,   363,    -1,    67,   315,   261,
     366,   262,    -1,    76,   316,   261,   350,   262,    -1,    77,
     316,   261,   350,   262,    -1,    78,   316,   261,   350,   262,
      -1,   319,    -1,   330,    -1,   339,    -1,   380,   291,   292,
      -1,   380,   263,   293,   291,   292,    -1,   380,     9,   380,
     263,   293,   291,   292,    -1,    41,   259,   380,   260,    -1,
      41,   259,   365,   260,    -1,    41,   257,   365,   258,    -1,
      41,   291,   261,   366,   262,   292,    -1,   380,   291,   261,
     366,   262,   292,    -1,    42,   291,   350,   266,   350,   266,
     350,   292,    -1,    43,   291,   350,   266,   350,   266,   350,
     292,    -1,    44,   291,   370,   292,    -1,    45,   291,   350,
     266,   350,   266,   350,   266,   350,   266,   350,   266,   350,
     292,    -1,   213,   291,   365,   292,    -1,    32,   291,   365,
     292,    -1,   350,    -1,   365,    -1,   366,   266,   350,    -1,
     366,   266,   365,    -1,   261,   350,   266,   350,   266,   350,
     266,   350,   262,    -1,   261,   350,   266,   350,   266,   350,
     262,    -1,   380,    -1,     4,   263,   190,   263,     4,    -1,
     261,   369,   262,    -1,   380,   259,   350,   260,   263,   191,
      -1,   367,    -1,   369,   266,   367,    -1,   371,    -1,   380,
      -1,   380,   259,   350,   260,    -1,   380,   257,   350,   258,
      -1,   380,   263,   293,    -1,   380,     9,   380,   263,   293,
      -1,   380,   263,   293,   257,   350,   258,    -1,   380,     9,
     380,   263,   293,   257,   350,   258,    -1,   380,   259,   350,
     260,   263,     4,    -1,   315,   261,   350,   262,    -1,   139,
     315,   261,   350,   262,    -1,     5,    -1,   227,   259,   380,
     260,    -1,    70,    -1,   225,    -1,    79,    -1,    81,    -1,
     210,   257,   370,   258,    -1,   209,   257,   370,   266,   370,
     258,    -1,   211,   291,   370,   292,    -1,   211,   291,   370,
     266,   370,   292,    -1,   221,   257,   357,   354,   258,    -1,
     221,   257,   357,   263,   293,   354,   258,    -1,    51,   291,
     377,   292,    -1,    52,   257,   370,   258,    -1,    53,   257,
     370,   258,    -1,    54,   257,   370,   266,   370,   266,   370,
     258,    -1,    49,   291,   377,   292,    -1,    63,   291,   370,
     292,    -1,    64,   291,   370,   292,    -1,    65,   291,   370,
     292,    -1,    62,   291,   350,   266,   370,   266,   370,   292,
      -1,    57,   291,   370,   266,   350,   266,   350,   292,    -1,
      57,   291,   370,   266,   350,   292,    -1,    50,   291,   370,
     292,    -1,    50,   291,   370,   266,   366,   292,    -1,    71,
     291,   370,   292,    -1,    72,    -1,    73,    -1,    56,   291,
     370,   292,    -1,    55,   291,   370,   292,    -1,    -1,    98,
     291,   371,   372,   306,   292,    -1,    95,   291,   373,   292,
      -1,   264,   350,    -1,   380,     9,   264,   350,    -1,    49,
     291,   376,   292,    -1,   377,    -1,   376,    -1,   261,   377,
     262,    -1,   370,    -1,   378,    -1,   377,   266,   370,    -1,
     377,   266,   378,    -1,   380,   257,   258,    -1,   380,   263,
     293,   257,   258,    -1,   380,     9,   380,   263,   293,   257,
     258,    -1,     4,   265,   261,   350,   262,    -1,   379,   265,
     261,   350,   262,    -1,   228,   259,   370,   260,   265,   261,
     350,   262,    -1,     4,    -1,   379,    -1,   228,   259,   370,
     260,    -1
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
    3594,  3599,  3606,  3611,  3621,  3626,  3632,  3640,  3651,  3659,
    3663,  3667,  3671,  3678,  3682,  3686,  3698,  3707,  3771,  3787,
    3804,  3821,  3843,  3865,  3900,  3908,  3916,  3922,  3929,  3936,
    3956,  3982,  3994,  4005,  4023,  4041,  4060,  4059,  4084,  4083,
    4110,  4109,  4134,  4133,  4156,  4172,  4189,  4206,  4229,  4257,
    4260,  4266,  4278,  4298,  4302,  4306,  4310,  4314,  4318,  4322,
    4326,  4335,  4348,  4349,  4350,  4351,  4352,  4356,  4357,  4358,
    4359,  4360,  4363,  4387,  4406,  4429,  4432,  4448,  4451,  4468,
    4471,  4477,  4480,  4487,  4490,  4497,  4519,  4560,  4604,  4643,
    4668,  4681,  4692,  4709,  4726,  4756,  4782,  4808,  4840,  4867,
    4893,  4919,  4945,  4971,  4993,  5004,  5052,  5106,  5121,  5133,
    5144,  5151,  5166,  5180,  5181,  5182,  5186,  5192,  5204,  5222,
    5250,  5251,  5252,  5253,  5254,  5255,  5256,  5257,  5258,  5265,
    5266,  5267,  5268,  5269,  5270,  5271,  5272,  5273,  5274,  5275,
    5276,  5277,  5278,  5279,  5280,  5281,  5282,  5283,  5284,  5285,
    5286,  5287,  5288,  5289,  5290,  5291,  5292,  5293,  5294,  5295,
    5296,  5297,  5298,  5299,  5300,  5301,  5302,  5303,  5304,  5313,
    5314,  5315,  5316,  5317,  5318,  5319,  5320,  5321,  5322,  5323,
    5328,  5327,  5335,  5339,  5344,  5349,  5353,  5358,  5363,  5367,
    5371,  5375,  5379,  5383,  5387,  5393,  5408,  5412,  5418,  5423,
    5442,  5462,  5483,  5487,  5491,  5495,  5499,  5503,  5507,  5512,
    5522,  5532,  5537,  5548,  5557,  5562,  5567,  5595,  5596,  5602,
    5603,  5609,  5608,  5631,  5633,  5638,  5640,  5646,  5647,  5652,
    5656,  5660,  5664,  5668,  5675,  5679,  5683,  5687,  5694,  5699,
    5706,  5711,  5715,  5720,  5724,  5732,  5743,  5747,  5751,  5765,
    5773,  5781,  5788,  5798,  5821,  5826,  5832,  5837,  5843,  5854,
    5860,  5874,  5880,  5892,  5906,  5919,  5929,  5939,  5949,  5961,
    5965,  5970,  5982,  5986,  5990,  5994,  6012,  6020,  6028,  6057,
    6067,  6083,  6094,  6099,  6103,  6107,  6119,  6123,  6135,  6152,
    6162,  6166,  6181,  6186,  6193,  6197,  6202,  6216,  6230,  6234,
    6238,  6242,  6246,  6254,  6260,  6269,  6273,  6277,  6285,  6291,
    6297,  6301,  6308,  6316,  6323,  6332,  6336,  6340,  6355,  6369,
    6383,  6395,  6411,  6420,  6429,  6439,  6450,  6458,  6466,  6470,
    6489,  6496,  6502,  6508,  6515,  6523,  6522,  6532,  6556,  6558,
    6564,  6569,  6571,  6576,  6581,  6586,  6588,  6592,  6604,  6618,
    6622,  6629,  6637,  6645,  6656,  6658,  6661
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
     327,   327,   327,   327,   327,   327,   327,   327,   328,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   330,   330,   330,   331,   330,   332,   330,
     333,   330,   334,   330,   330,   330,   330,   330,   330,   335,
     335,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   337,   337,   337,   337,   337,   338,   338,   338,
     338,   338,   339,   339,   340,   341,   341,   342,   342,   343,
     343,   344,   344,   345,   345,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     347,   347,   347,   348,   348,   348,   349,   349,   349,   349,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     352,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   353,   353,   354,
     354,   356,   355,   357,   357,   358,   358,   359,   359,   360,
     360,   360,   360,   360,   361,   361,   361,   361,   362,   362,
     363,   363,   363,   363,   363,   363,   364,   364,   364,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   366,   366,   366,   366,   367,   367,   367,   367,
     368,   368,   369,   369,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   372,   371,   371,   373,   373,
     374,   375,   375,   376,   377,   377,   377,   377,   378,   378,
     378,   379,   379,   379,   380,   380,   380
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
      11,     2,     4,     2,     2,     2,     2,    16,    11,     6,
       8,     8,    10,     1,     2,     2,     1,     3,     3,     4,
       4,     1,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     9,     2,     3,    10,    13,     1,
       2,     5,     7,     2,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       3,     4,     9,     4,    14,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     6,     7,     6,     5,     3,
       8,     6,     8,     8,     5,     4,     6,    11,    11,    18,
      18,    12,    12,    12,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     6,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     1,     4,     6,     1,     4,     4,     4,     6,
       5,     7,     8,    10,     4,     4,     6,     4,     3,     2,
       5,     5,     3,     5,     6,     8,     6,     8,     6,     4,
       7,     6,     6,     6,     4,     6,     4,     0,     2,     0,
       2,     0,     7,     1,     3,     1,     2,     0,     3,     1,
       2,     2,     3,     3,    11,     9,     7,     7,     1,     3,
       1,     1,     2,     3,     4,     5,     1,     3,     1,     2,
       3,     3,     5,     4,     4,     2,     4,     2,     3,     3,
       4,     5,     5,     5,     5,     1,     1,     1,     3,     5,
       7,     4,     4,     4,     6,     6,     8,     8,     4,    14,
       4,     4,     1,     1,     3,     3,     9,     7,     1,     5,
       3,     6,     1,     3,     1,     1,     4,     4,     3,     5,
       6,     8,     6,     4,     5,     1,     4,     1,     1,     1,
       1,     4,     6,     4,     6,     5,     7,     4,     4,     4,
       8,     4,     4,     4,     4,     8,     8,     6,     4,     6,
       4,     1,     1,     4,     4,     0,     6,     4,     2,     4,
       4,     1,     1,     3,     1,     1,     3,     3,     3,     5,
       7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   634,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,     0,     0,   207,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   342,   343,   344,   345,   346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,     0,     0,   311,   312,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,   393,   394,   395,     0,     0,
       0,     5,     6,     7,     8,    10,     0,    11,    24,    12,
      13,    14,    15,    23,    22,    21,    16,     0,    17,    18,
      19,    20,     0,    25,     0,   635,     0,   233,     0,     0,
       0,     0,     0,     0,   283,     0,   285,   286,   281,   282,
       0,   288,     0,   291,   233,     0,   293,   294,   119,   129,
     634,   507,   503,    73,    74,     0,   205,   206,   207,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   296,     0,   217,   218,   219,
       0,     0,     0,     0,   449,   450,   452,   453,   451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,   458,
     459,     0,     0,   205,   210,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   454,   455,
     456,     0,     0,     0,     0,     0,     0,     0,     0,   545,
     546,     0,   547,   520,   400,   462,   465,   325,   521,   503,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
     210,   211,     0,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     634,     0,     0,   233,     0,     0,   390,     0,     0,     0,
     214,   215,     0,     0,     0,     0,     0,     0,   528,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,   634,
       0,     0,   568,     0,     0,     0,     0,   279,   280,     0,
     585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,     0,   611,   612,   589,   590,
       0,     0,     0,     0,     0,     0,   588,     0,     0,     0,
       0,   304,   305,     0,   233,     0,   233,     0,     0,     0,
       0,   503,     0,   276,     0,     0,   233,   396,     0,     0,
      84,     0,    66,     0,     0,    70,    69,    68,    67,    72,
      71,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     574,   503,     0,   232,     0,   231,     0,   184,     0,     0,
     574,   575,     0,     0,     0,   624,     0,   625,   575,     0,
       0,     0,   117,   117,     0,   501,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   562,   563,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   535,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   403,     0,   402,   529,   404,
       0,   522,     0,     0,   503,     0,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,   479,     0,     0,     0,     0,     0,     0,     0,
     326,     0,   359,   359,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   233,     0,   233,   233,     0,
     511,   510,     0,     0,     0,     0,   233,   233,     0,     0,
       0,     0,   322,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   361,     0,     0,     0,
       0,     0,     0,   233,   259,     0,     0,   257,   391,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     369,   278,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   308,   307,     0,   264,
       0,     0,   266,     0,     0,     0,     0,   402,     0,   233,
       0,     0,     0,     0,     0,     0,     0,   347,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    88,    75,    76,     0,     0,
       0,   275,    40,   271,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,   234,     0,     0,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,   118,
       0,     0,     0,   505,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   353,     0,     0,     0,   209,
       0,     0,     0,     0,     0,     0,   386,   387,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   460,   478,     0,     0,     0,     0,   538,
     539,     0,     0,     0,     0,     0,   497,     0,   401,   523,
       0,     0,     0,     0,   531,     0,   420,   419,   418,   417,
     413,   414,   421,   422,   416,   415,   406,   405,     0,   407,
     530,   408,   411,   409,   410,   412,   504,     0,     0,   482,
       0,   548,     0,     0,     0,     0,     0,     0,     0,     0,
     357,     0,     0,     0,     0,     0,     0,   389,     0,     0,
       0,     0,   388,     0,   233,     0,     0,     0,     0,     0,
     513,   512,     0,     0,     0,     0,     0,     0,     0,   316,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   375,     0,     0,     0,   258,     0,     0,
       0,   252,     0,     0,     0,     0,   385,     0,     0,     0,
       0,   401,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,   310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,     0,     0,     0,   499,     0,     0,
     263,   267,   265,   269,     0,     0,   407,     0,   504,   482,
     636,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,   401,     0,     0,     0,    66,     0,     0,
      87,     0,    66,    67,     0,     0,     0,   504,     0,     0,
     482,     0,     0,     0,   203,     0,     0,     0,   631,    28,
      26,    27,     0,     0,     0,     0,     0,   578,    30,     0,
      29,     0,     0,   272,   626,   627,     0,   628,   578,     0,
       0,    82,   120,    83,   130,   506,   508,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   564,   565,   220,     9,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   446,   433,     0,   435,   436,
     437,   438,   439,   561,   440,   441,   442,     0,     0,     0,
       0,     0,   553,   552,   551,     0,     0,     0,   558,     0,
     494,     0,     0,     0,   496,     0,     0,     0,     0,   134,
     477,   534,   533,   213,     0,     0,   463,   560,   468,     0,
     474,     0,     0,     0,     0,   524,     0,     0,   475,   540,
     536,     0,     0,     0,     0,   467,   466,    73,    74,   489,
       0,     0,     0,     0,     0,     0,     0,   401,   355,   360,
     358,     0,   368,     0,   156,   157,     0,   213,     0,   401,
       0,     0,     0,     0,   253,     0,   268,   270,     0,     0,
       0,   221,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,     0,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,   362,
     374,     0,     0,     0,     0,   254,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,     0,     0,     0,   601,     0,   608,
     597,   598,   599,     0,   614,   613,     0,     0,   602,   603,
     604,   610,   618,   617,     0,   147,     0,   591,     0,   593,
       0,     0,     0,   586,     0,     0,   262,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,   397,     0,
     632,     0,   109,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
     583,    51,     0,     0,     0,    64,     0,    41,    42,    43,
      44,    45,    46,     0,   467,   466,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   577,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,   137,   138,     0,     0,     0,     0,
     163,   163,     0,     0,     0,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   541,   542,   543,   544,     0,     0,     0,
       0,     0,   497,   498,     0,   470,     0,     0,   532,   423,
     525,   483,   481,     0,   480,     0,     0,   549,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,   261,     0,
       0,     0,     0,     0,     0,     0,   334,     0,     0,   333,
       0,   336,     0,   338,     0,   323,   330,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     376,     0,     0,   256,   255,   392,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,   569,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,   500,   595,     0,   371,   483,     0,
       0,   233,   349,     0,   350,   233,     0,     0,   584,     0,
      94,     0,     0,     0,     0,    92,     0,   572,     0,   107,
       0,    99,   101,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    36,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   579,
       0,     0,    34,    33,     0,   579,   629,   287,     0,     0,
     121,   126,     0,     0,     0,   140,   145,   146,   141,   142,
     502,     0,    85,     0,    86,   167,     0,     0,     0,     0,
     168,   187,   188,   165,     0,     0,     0,   169,   198,   189,
     193,   194,   190,   191,   192,   177,     0,     0,   434,   448,
     447,   443,   444,   445,   554,     0,     0,     0,   492,   493,
     495,   135,   461,   491,   464,   469,     0,     0,   497,   199,
     476,    73,    74,     0,   488,   484,   486,   555,   195,     0,
       0,     0,   159,     0,     0,   366,     0,   158,     0,     0,
       0,     0,     0,     0,   277,     0,     0,     0,     0,   233,
     233,     0,     0,   335,   520,     0,     0,   337,   339,     0,
       0,   317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   226,   196,     0,     0,     0,     0,     0,     0,
       0,   174,     0,   175,     0,     0,     0,     0,   110,   114,
       0,   609,     0,     0,   607,     0,   619,     0,     0,   148,
     149,   616,   592,   594,     0,     0,     0,     0,     0,     0,
     347,   351,   347,     0,   398,    93,     0,     0,    66,     0,
       0,    91,     0,   570,     0,     0,     0,     0,     0,     0,
     622,   621,     0,     0,     0,     0,     0,   518,     0,     0,
      77,   273,   484,   274,     0,     0,     0,     0,     0,   238,
     235,     0,     0,   582,   580,     0,     0,     0,     0,   122,
     127,     0,     0,     0,   562,   563,   139,   370,   164,   172,
     173,   178,     0,     0,     0,     0,     0,   180,     0,     0,
       0,     0,     0,     0,   471,     0,     0,     0,   550,   490,
       0,     0,   179,     0,   200,   356,     0,     0,     0,     0,
     201,     0,     0,     0,     0,     0,     0,   517,   516,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       0,     0,     0,   372,   373,    39,   182,   183,     0,   567,
       0,     0,   301,   300,     0,     0,     0,     0,     0,     0,
     151,   152,   155,   154,   153,     0,   596,     0,   633,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   573,
       0,     0,     0,    96,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    49,     0,   239,   236,   237,    35,     0,
       0,   630,   289,     0,   134,   147,     0,     0,   144,     0,
       0,     0,   166,   197,     0,     0,     0,     0,     0,   556,
     557,     0,   497,   472,   485,   487,     0,     0,   181,   204,
       0,     0,     0,   363,   363,     0,   115,   116,   233,     0,
     224,   225,   324,     0,   331,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   230,     0,   228,     0,
       0,     0,     0,   111,   112,   600,   606,   605,   150,     0,
       0,     0,   352,     0,     0,   108,   100,   102,     0,    90,
     623,    97,    98,    52,     0,     0,     0,     0,   519,     0,
       0,   485,   581,     0,     0,     0,     0,   124,   620,     0,
     131,     0,     0,     0,     0,   186,     0,     0,     0,   327,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   515,     0,   341,     0,     0,   318,     0,
     241,     0,     0,     0,     0,     0,     0,   229,     0,   566,
     302,     0,     0,   384,   233,   399,     0,   571,     0,    48,
       0,     0,     0,    65,    50,     0,   290,   123,   128,   134,
       0,     0,   161,   162,   160,     0,     0,   473,     0,     0,
       0,     0,   364,   377,     0,     0,   378,     0,   222,     0,
     332,     0,   314,     0,   233,     0,     0,     0,     0,     0,
       0,   176,   113,   298,   347,   106,     0,     0,     0,     0,
       0,     0,   132,   133,     0,     0,     0,   202,     0,   381,
       0,   382,   383,   514,     0,     0,   320,   244,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,    62,     0,
       0,   125,     0,     0,   328,     0,     0,   340,   319,   315,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
     247,   248,     0,   242,   354,    53,     0,    60,     0,   284,
       0,   559,     0,     0,   321,     0,     0,    54,     0,     0,
     297,     0,     0,   243,     0,     0,     0,     0,     0,     0,
      57,    55,     0,    58,     0,   379,   380,     0,     0,    63,
      61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   121,  1102,   122,   123,  1086,  1956,  1962,
    1387,  1607,  2118,  2246,  1388,  2219,  2262,  1389,  2248,  1390,
    1391,  1611,   454,   612,   613,  1172,  1704,   124,   810,   482,
    1974,  2129,  1975,   483,  1843,  1468,  1423,  1424,  1425,  1570,
    1779,  1780,  1243,  1666,  1657,  1853,   785,   624,   287,   288,
     363,   211,   289,   464,   465,   128,   129,   130,   131,   132,
     133,   134,   135,   290,  1277,  2153,  2210,   977,  1273,  1274,
     291,  1065,   292,   139,  1496,  1241,   950,   992,  2087,   140,
     141,   142,   143,   293,   294,  1199,  1214,  1342,   295,   815,
     296,   814,   485,   641,   331,  1816,   371,   372,   298,   582,
     381,  1371,  1598,   475,   470,  1335,  1041,  1647,  1809,  1810,
    1026,   477,   145,   431
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1942
static const yytype_int16 yypact[] =
{
   12919,    74,   161, 13124, -1942, -1942,   -41,   127,    83,   -71,
     -39,   -16,    15,   249,   257,   310,   320,    81,    47,    57,
      12,   343,   352,   106,   203,    26,   120,    85,   120,   218,
     254,   263,    50,   301,   326,    65,   331,   366,   379,   425,
     443,   454,   460,   489,   511,   532,   436,   551,   632,   791,
     796,   559,   141,   616,   594,  7092,   615,   652,   658,   797,
     -70,   130,    85,   405,   -12,   663,   837,   -75,   690,   210,
     210,   691,   358,    56,   747, -1942, -1942, -1942, -1942, -1942,
     701,   527,   882,   892,    16,    42,   900,   905,   503,   912,
    1021,  1023,  1024,  5264,  1025,   -82,   -72,   773,    11,    68,
   -1942,   774,   775, -1942, -1942,  1027,  1029,   777, -1942,  7976,
     780,  8231,    24,    34,    85, -1942, -1942, -1942, 11744,   779,
    1033, -1942, -1942, -1942, -1942, -1942,   781, -1942, -1942, -1942,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942,   260, -1942, -1942,
   -1942, -1942,     3, -1942,  1034,   776,  6070,   342,   782,  1038,
   11744, 13308, 13308, 13308, -1942, 11744, -1942, -1942, -1942, -1942,
   13308, -1942, 11744, -1942, -1942, 11744, -1942, -1942, -1942, -1942,
     785,   788,  1037, -1942, -1942,  8486, -1942, -1942, -1942, -1942,
     790,    26, 11744, 11744, 11744,   794, 11744, 11744, 11744,   795,
   11744, 11744, 11744, 11744, 11744, 11744, 11744, 13308, 11744, 11744,
   11744, 11744,  5264,   798, -1942, -1942,  9887, -1942, -1942, -1942,
     792,  5264,  7347, 13308, -1942, -1942, -1942, -1942, -1942,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   544,   120,   120,   120,   120,   120,
     799,   120,   120,   800,    85,    46,    46,    46, -1942, -1942,
   -1942,   120,   120,    36,   865,   866,   867,   801,  7347,   929,
      85,    85,   806,   120,   120,   809,   810,   811, -1942, -1942,
   -1942, 11744,  7602, 11744, 11744,  7857,    26,   876,    40, -1942,
   -1942,   813, -1942,  2502, -1942, -1942, -1942, -1942, -1942,    73,
   11744,  9887,  9887,   814,   815,  8112,  5264,  5264,  5264, -1942,
   -1942, -1942,   818, -1942,   816,   819,  8367,   817, 10584,  1066,
    7347,   821,    11,   822,   823,   210,   210,   210, 11744, 11744,
     261, -1942,   341,   210, 10739,   371,   287,   828,   829,   830,
     832,   833,   834,   835,  9887, 11744,  5264,  5264,  5264,   336,
      19,  1073,   836, -1942,  1074,  1082, -1942,   841,   844,   845,
   -1942, -1942,   846,  5264,   848,   838,   839,   851, -1942, 11744,
    6327, -1942,  1087,  1090,   854, 11744,   855, 11744, 11744,   749,
   11744,   856, -1942,   923, 11744, 11744, 11744, -1942, -1942, 11744,
   -1942,   120,   120,   120,   861,   862,   863,   120,   120,   120,
     120,   120,   120,   120, -1942,   120, -1942, -1942, -1942, -1942,
     120,   120,   869,   870,   120,   874, -1942,   887,  1116,  1141,
     888, -1942, -1942,  1144,  1143,  1146,  1145,   897,   120, 11744,
   15453,   100, 13308, -1942,  9887, 11744, -1942, -1942,  7347,  7347,
   -1942,   894,  8486,    85,  1149, -1942, -1942, -1942, -1942, -1942,
   -1942, 11744, 11744,   416,  7347,  1151,   487,   898,  3004,   899,
    1152,    33,   901, -1942,   902, 13447, 11744, -1942,  3524,  -209,
   -1942,   109,   -21,   143, 10168, -1942,   153, -1942,   119, 11806,
    1336, 12734,  -139,  -124,  1064, -1942,    26,   903, 11744,   904,
   15969, 15994, 16019, 11744, 16044, 16069, 16094, 11744, 16119, 16144,
   16169, 16194, 16219, 16244, 16269,   908, 16294, 16319, 16344, 14496,
    1160, 11744,  9887,  6515, -1942,   363, 11744,  1162,  1165,   916,
   11744, 11744, 11744, 11744, 11744, 11744, 11744, 11744, 11744, 11744,
   11744, 11744, 11744, 11744, 11744, 11744,  9887, 11744, 11744, 11744,
   11744, 11744, 11744, 11744, 11744,  9887,  9887,   914, 11744, 11744,
   13308, 11744, 13308,  7347, 13308, 13308, 13308,   917,   918,   919,
     920, 11744,    63, -1942, 10839, 11744,  7347,  5264,  7347, 13308,
   13308,  9887,    26,  8486,    26,   921,  9887,   921, -1942,   921,
   16369, -1942,   390,   922,    78,  1115, -1942,  1175, 11744, 11744,
   11744, 11744, 11744, 11744, 11744, 11744, 11744, 11744, 11744, 11744,
   11744, 11744,  8622, 11744, 11744, 11744, 11744, 11744,    26, 11744,
   11744,    71, -1942,   709, 16394,   395,   409, 11744, 11744, 11744,
   -1942,  1177,  1179,  1179,   930, 11744, 11744, 11744, 11744,  1185,
    9887,  9887, 15481,   952,  1205, -1942,   951, -1942, -1942,  -190,
   -1942, -1942, 12917, 13374,   210,   210,   342,   342,  -172, 10739,
   10739, 11744,  3187,  -133, -1942, 11744, 11744, 11744, 11744, 11744,
   11744, 11744, 11744, 11744,   418, 16419,  1209,  1211,  1212, 11744,
   11744,  1215, 11744, -1942, -1942, 11744, 11873, -1942, -1942,  9887,
    9887,  9887, 11744,  1216,  9887, 11744, 11744, 11744, 16444,   956,
   -1942, -1942, 11744, 16469, 11744, 16494, 16519,  1035, 13407, -1942,
     962,  6770, 16544, 16569, 15564, 13308, 13308, 13308, 13308, 13308,
   13308, 13308, 13308, 13308, 11744, 13308, 13308, 13308, 13308,     2,
    8486, 13308, 13308, 13308,    26,    26, -1942, -1942,  9887, -1942,
     964, 11985, -1942,   965, 12055, 11744, 11744,   921, 11744, -1942,
      26, 11744, 11744,    71,   968,   433, 16594, 13361,   966,   504,
   11744,  1226,   972,  7347, 16619, 15591, -1942, -1942, -1942, -1942,
   -1942,   971,  1228,    20,  1230, -1942, -1942, -1942,  9887,   167,
   11744, -1942, -1942, -1942,    26, 11744, 11744,    71,   978, -1942,
     981,   -61,    85,   405,    85, -1942,   979, 14525, -1942,     7,
    9887,    26, 11744, 11744,    71,  1233,  9887,  1235,  9887, 11744,
    1236, 13308,    26, 10994,    71, 11744, -1942, 11744,  1237, -1942,
      26,  1238, 13308, 11744,   987,   989, -1942, 11744, 13440,  8486,
    1239,  1242,  1243, 16644,  1244,  1249,  1250, 16669,  1251,  1253,
    1255,  1256,  1257,  1258,  1259, -1942,  1260,  1262,  1264, -1942,
   11744, 16694,  9887,  1013,  9887, 14554, -1942, -1942,  1270, 15537,
   15537, 15537, 15537, 15537, 15537, 15537, 15537, 15537, 15537, 15537,
   13473, 15537, 15537, 15537, 15537,  2550,   758, 15537, 15537, 15537,
   13506, 13539, 13572, 13605, 13638,  6515,  1019,  1018,    93,  9887,
   13671, 13704,   758, 13737,   758,  1014,  1015,  1022,   191,  9887,
   11744, 11744, 11744, 17644, -1942,   758,  1017, 14583, 14612, -1942,
   -1942,  1026,   -62,   758,   -79,  1028,   435,   528,  1277, -1942,
      71,   758,  7347,  1031,  7025,  7280,   651,   535,   513,   513,
     417,   417,   417,   417,   417,   417,   440,   440,  9887,   244,
   -1942,   244,   244,   921,   921,   921,  1032, 16719, 15618,   556,
    9887, -1942,  1280,  1030,  1036, 16744, 16769, 16794, 11744,  7347,
    1285,  1284, 10488, 16819, 14641, 16844, 16869, -1942,   530,   538,
    9887,  1039, -1942, 12125, -1942, 12195, 12265,   210, 11744, 11744,
   -1942, -1942,  1042,  1045, 10739,  8810,  1153,   302,   210, 12335,
   16894, 14670, 16919, 16944, 16969, 16994, 17019, 17044, 17069,  1040,
    1287, 11744,  1293, -1942, 11744, 17094, 14699, -1942, 15645, 12405,
   15672, -1942,   546,   552,   563, 14728, -1942,   574, 15699, 15726,
   13770, -1942, -1942, 17119,  1302, 17144,  1303,  1304,  1049, 11744,
   12475, 11744, 11744, -1942, -1942,    43,   469,   472,   469,  1055,
    1058,  1051,   758,   758,  1052, 13803,   758,   758,   758,   758,
   11744,   758,  1310, -1942,  1056,  1063,   476,   184,  1065,   583,
   -1942, -1942, -1942, -1942, 17169, 15537,   244, 12545,  1060,   576,
    1067,  1135,  1323,  1167, 11089,  1072,  1075,  1331,  7347, 14757,
   -1942, 11744,  1333,   159,    79,    71,    28,  8486, 11744,  1334,
   -1942,   584,  1292,  1294,  7347, 14786,    31,  1079, 17194, 15753,
     567, 11744, 11744,  1088,  1083,  1089,  1086,  8877, -1942, -1942,
   -1942, -1942, 13308,   304,  1085, 17219, 15780,  1094, -1942,   360,
   -1942,   427, 13836, -1942, -1942, -1942,  1093, -1942,  1095, 14815,
   13869, -1942,    72, -1942, -1942, 17644, -1942,    55, 15537, 11744,
     758,   210,  7347,  7347,  1346,  7347,  7347,  7347,  1350,  7347,
    7347,  7347,  7347,  7347,  7347,  7347,  7347,  7347,  7347,  3592,
    1351,  9887,  6515, -1942, -1942, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942, 11744, -1942, -1942,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942, 11744, 11744, 11744,
   11744, 11744, -1942, -1942, -1942,   586, 11744, 11744, -1942, 11744,
   -1942,  7347, 13308, 13308, -1942,   591, 14844, 14873, 14902,  1096,
   -1942, -1942, -1942,  1166, 11744, 11744, -1942, -1942, -1942,    71,
   -1942,    71, 11744, 11744,  1102, -1942,  7347,   120, -1942, -1942,
   -1942, 11744, 11744,   596,    71,   340,   367, 11744, 11744, -1942,
     758,   601,  7347,  9887,  9887,  1354,  1356,  1357,  2977, -1942,
   -1942,  1359, -1942,  1108, 17644,  1103,  1361, -1942,  1363,  1366,
    1367,  1368,   602,   110, -1942, 12615, -1942, -1942,  -129, 13902,
   13935, -1942, -1942, 14931,   170,  1261,  1372, 11244,  1117,  1371,
    1123,    37,    38,   -73, -1942,  -126, -1942,   302,  1375,  1377,
    1378,  1379,  1380,  1381,  1382,  1383,  1384,   342,  7347, 17644,
   -1942,  3632,  1132,  1282,  1388, -1942,  1389,  1390,  1290,  1393,
   -1942,  1394,  1396,  1397, 11744,  1398,  7347,  1399,  7347,  7347,
    1403, 13968, -1942,  7535,  2851,    71,    71, -1942,  9887, -1942,
   -1942, -1942, -1942, 13308, -1942, -1942, 11744, 13308, -1942, -1942,
   -1942, -1942, 17644, -1942,  1147,  1148, 13308, -1942, 13308, -1942,
      71, 13308,  1154, -1942,  1150,  1404, -1942,    71, 11744, 11744,
    1157,    85,  1158, 11339, -1942,  3773,  1159,  7347, -1942,  1161,
   -1942, 14960, -1942, -1942, 11744,  1407,   423, 11744,  1409,  1414,
      11,  1416,  1168,  1418,  3804, -1942,   758,   120,   120,  1419,
   -1942, -1942,  1169,  1171,  1170, -1942,  1424, -1942, -1942, -1942,
   -1942, -1942, -1942,    71,   169,  2404, 11744, 15807, 17244, 11744,
    9127, 11744,  9887,  1172,   603,  1426,    18,    71, -1942,  1173,
   11744,  1429,  1431, 11744,    71, 11494,  1447, 11744,  4695,   758,
    5550, 11744, 11744,  1198,  1193, -1942,  1455, 17269,  1456,    94,
    1327,  1327,  7347,  1458,  1459,  1460,  7347,   -92,  1464,  1465,
    1468,  1471,  1473,  1474,  1476,  1478,  1479, -1942,  1481,   604,
   15537, 15537, 15537, 15537, 15537, 15537,   758, 14001, 14034, 14067,
    1229,   758,   758, -1942, -1942, -1942, -1942,    55,   758, 17294,
   15537,  1234,   413, 17644, 15537, -1942,  1482,   758, 17644, 17644,
   -1942,   760, -1942,    71, -1942, 17319, 15834, -1942,   758,  1488,
     611,   612,  7347,  7347,  7347,  1491,  1494, -1942,   174, 11744,
    7347,  7347,  7347,  1240,  1241,  1496,  1499,  1500, -1942, 11744,
   11744, 11744,  1245,  1247,  1248,  1252, -1942,  3995,  7347, -1942,
   11744, -1942,  1504, -1942,  1506, -1942, -1942, 10739,   267,  6582,
   -1942,  1263,  1266,  1268,  1269,  1274,  1275,  9377,  1278,  1507,
   -1942,  9887,  1276, -1942, -1942, -1942,  1281, 11744, 11744, -1942,
   -1942, 15861,  7347,  1511,  7347,  1512,  1330, -1942, 11744, 11744,
   11744, -1942,  1514,   831,   483,  1265,  8555,  1273, 11744,    27,
     758,  1267,   758,  1279, -1942, -1942,  8486, -1942,   764, 11744,
    1286, -1942, -1942,  4117, -1942, -1942,  1288,  1535, -1942,  4619,
   -1942,  1283,  1536,   163,  4736, -1942,    11, -1942,   618, -1942,
   11744, -1942, -1942,   174,  3442, 11810, -1942,  1291, 11744, 11744,
    7347,  1289, -1942,  -193,   444,  1546, 17344,  1547,  1277, 17369,
    1295,   619, 17394,   642,  1549,  1550, -1942, -1942, 13308,  1301,
    1555, 17419, -1942, -1942, 14100,  1305, -1942, -1942,  9060,  5815,
   17644, -1942,  1554,   120,  7857, -1942, -1942, -1942, 17644, 17644,
   -1942,    55, -1942,  1557, -1942, -1942,   210,  1558,  1559,  1561,
   -1942, -1942, -1942,  1425,   -44,  1463,  1564, -1942, -1942, -1942,
   -1942, -1942, -1942, -1942, -1942, -1942,  1566,  1311, -1942, -1942,
   -1942, -1942, -1942, -1942, -1942, 11744, 11744, 11744, -1942, -1942,
   -1942,  1193, -1942, -1942, -1942, -1942, 11744,  1315,  1308, -1942,
   -1942, 11744, 11744,   758,   340, -1942, -1942, -1942, -1942,  1317,
    1318,  1570,   -92,  1574, 11744, -1942,  7347, 17644,  1439,  1440,
    1020,  9887,  9887, 11744, -1942, 10488, 14989, 17444,  9310,   342,
     342, 11744, 11744, -1942,   958,  1319, 17469, -1942, -1942, 15018,
    -111, -1942,  1578,  1580,  7347,   210,   210,   210,   210,   210,
    6837,  1581, -1942, -1942,   644,  9887, 11744,  4829,  4885,  1582,
    1583, -1942,  1584, -1942,  7347,  9565,  2129, 17494, -1942, -1942,
   10137, -1942, 13308, 11744, -1942, 13308, 17644, 10233,  8486,  1325,
   -1942, -1942, -1942, -1942,  1337,  1328, 11744, 11744, 15047, 11744,
   13361, -1942, 13361,  7347, -1942, -1942,    71,    28,  8486, 11744,
    1590, -1942,  1591, -1942,    11, 15888,  7347, 13308,  1593,   758,
   -1942,  1338,   758, 11744, 14133, 14166,   650, -1942, 11744, 11744,
    1339, -1942,  1342, -1942,  1357,  1599,  1600,  1366,  1602, -1942,
   -1942,  1603, 11744, -1942, -1942, 11744, 11589,  1604, 11744, -1942,
   -1942,  1352, 11810,   655,  6260,  1605, -1942, -1942,   637, -1942,
   -1942, -1942,  1467,  1609,  1355,  1358,  1360, -1942,  1606,  7347,
   15537, 15537, 14199, 15537, -1942,  1362, 17519, 15915, -1942, -1942,
    9887,  9887, -1942,  1611, -1942, 17644,  1612, 11744, 11744,  1365,
   -1942,   656,   664, 15509,  4915,  1616,  1369, -1942, -1942, 11744,
    1370,  1373, 15076, 15942,  1618,  7347,  1620,  1376, 11744, -1942,
   -1942,   665,  -107,   -93,   -69,   142,   176,  9632,   180, -1942,
    1622,   666, 15105, -1942, -1942, -1942, -1942, -1942,  1441, -1942,
   11744, 11744, -1942, -1942,  9887,  4945,  1625,  1385, 15537,   758,
   17644, -1942, -1942, -1942, -1942,    27, -1942,  8486, -1942, 15134,
    1386,  1387,  1400,  1626,  1628,  1632,  4982, -1942, -1942, -1942,
    1395,  1634,   667, -1942,  1636,  1638,   465, 17644, 11744, 11744,
    1391,  7347,   672, 17644, 17544, -1942, -1942, -1942, -1942, 17569,
   14232, -1942, -1942, 15163,  1096,  1148,  7347,   758, -1942, 11744,
    8486,    26, -1942, -1942,  9887,  9887, 11744,  1639,   673, -1942,
   -1942, 11744,  1308, -1942, -1942, -1942,   678,   679, -1942, -1942,
    5204,  5483,  7347,   226,   485,  9887, -1942, -1942,   342,  9820,
   -1942, -1942, -1942,  1640, -1942,  1401,  7347, -1942, 15192,  1641,
    9887,   210,   210,   210,   210,   210, -1942,  1644, -1942, 11744,
   15221, 15250,   687, -1942, -1942, -1942, -1942, -1942, -1942,  1402,
    1653,  1405, -1942,  1655,    11, -1942, -1942, -1942,  1477, -1942,
   -1942, -1942, -1942, -1942, 11744, 14265, 14298,  7347, -1942,  1658,
   11744,  1406, -1942, 11744,  1659,  1411,  1412, -1942, -1942,  3441,
   -1942,  1420,   688,   697, 15279, -1942,  1408, 14331,  1417, -1942,
    1415, -1942, -1942,   698,  1421,   210,  7347,  1672,  1422,   210,
    1673,   706,  1423, -1942, 11744, -1942,  1674,  1538, 12685,  1428,
   -1942,   713,   188,   195,   219,   223,   291, -1942,  5748, -1942,
   -1942,  1678,  1680, -1942, -1942, -1942,  1687, -1942,  1444, 17644,
   11744, 11744,   714, -1942, 17644, 14364, -1942, -1942, -1942,  1096,
    8486,  1448, -1942, -1942, -1942, 11744, 11744, -1942,  9887,  1702,
     210,   116, -1942, -1942,   210,   124, -1942,  1703, -1942, 15308,
   -1942, 11744, -1942,   302, -1942,  1704,  9887,  9887,  9887,  9887,
    9632, -1942, -1942, -1942, 13361, -1942, 11744, 17594, 14397,    59,
   11744,  1449, -1942, -1942, 14430, 14463,   715, -1942,   315, -1942,
     330, -1942, -1942, -1942,  5994,   327, 12755, -1942,   720,   721,
     722,   723,   332,   729,  1450,   730, -1942, 11744, -1942,  7347,
   15337, -1942, 11744, 11744, -1942,   210,   210, -1942, -1942, -1942,
     302,  1708,  1709,  1711,  1714,  9887,  1715,  1716,  1718,  1466,
   17619,   736,  1720, 15366, 15537,   334,   346,   369, -1942, -1942,
   -1942, -1942,   737, -1942, -1942, -1942, 13308, -1942,  1469, -1942,
    1722, -1942, 11744, 11744, -1942,  1723,   738, -1942,  1470,  7347,
   -1942, 15395, 15424, -1942,  1726, 13308, 13308,   744,  1727,  1728,
   -1942, -1942,   745, -1942,  1730, -1942, -1942,  1731, 13308, -1942,
   -1942, -1942
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1942, -1942, -1942, -1942,   333, -1942, -1942, -1942, -1942,  -428,
   -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942,  -759,  -112,  4423,  3574,  -392, -1942,  1271, -1942,
   -1942, -1942, -1942, -1942, -1942, -1941, -1942,   273,    97,  -231,
   -1942,  -186, -1942,    39,   314, -1942,  1747, -1942,  1101,   -55,
   -1942, -1942,    13,  -629,   -53, -1942, -1942, -1942, -1942, -1942,
   -1942, -1942,   669,  1753, -1942, -1942, -1942, -1942, -1274, -1271,
    1754, -1778,  1755, -1942, -1942, -1942,  1136, -1942,  -244, -1942,
   -1942, -1942, -1942,  2390, -1942, -1942, -1467,   189,  1760, -1942,
       0, -1942, -1942,   198, -1942, -1733,   555,  -183,  3097,   175,
    -321,   -33, -1942,   -68,    96, -1942, -1942,   -11,   160, -1737,
    -153,   967, -1942,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -583
static const yytype_int16 yytable[] =
{
     146,   636,  1526,  1528,  1078,  1697,   170,   476,   316,   437,
    1084,  1901,  1940,  1099,  1941,   379,   127,   972,   973,   510,
     350,   154,   172,   671,  1627,   171,   374,  1077,   517,   423,
     170,  1777,   170,  2065,   455,  1381,   376,   170,   304,   425,
    1933,   563,   774,  1521,  1523,   586,   355,   304,   356,   789,
    1315,  1664,   299,   161,   185,   644,   645,   790,  1854,  1420,
     336,   763,   305,   163,  1819,  2198,  1787,   170,  -579,   189,
    1266,  1093,   383,   644,   645,   756,   967,  1855,   459,  1418,
       4,   354,   608,   469,   472,   473,  1363,   486,  1267,   321,
     299,  1421,  1422,   317,   974,   382,   318,  1268,  1269,  1270,
    1655,  1665,   608,  1271,  1272,  1977,   419,   757,   758,   740,
     351,   480,   644,   645,  1506,   322,   644,   645,   791,   644,
     645,   808,  2179,   621,   622,   623,  1988,   809,   802,   505,
    2181,   323,   324,   978,   644,   645,   811,  1509,   644,   645,
    1527,   149,   809,   461,   357,   519,   757,   758,   471,   471,
     471,   310,   644,   645,   311,  1898,   313,   478,   337,  2020,
     463,     5,   338,   666,   667,   668,  1363,   314,   339,   340,
    1798,   341,   342,  2021,  1082,   375,   644,   645,   489,  1208,
     683,  1363,   759,   760,  1209,   377,   151,   176,  2171,  1525,
     177,   150,   343,   178,   471,   179,   766,  2022,   767,   299,
     558,   559,   560,   299,  1205,   418,    46,   422,   299,   299,
     471,  1382,  1383,  1384,  1385,  1522,  1524,   352,   152,   939,
     147,   759,   760,    99,   148,   100,   101,   102,   103,   104,
     119,  1865,  1778,   108,   109,   306,   111,   795,   307,   119,
     308,   153,   460,   207,   119,   796,   208,  1100,  1101,   209,
     445,   446,   447,   448,   119,   156,   119,  1526,  1100,  1101,
     438,   119,   210,   157,   439,   299,  1040,   330,   332,  2083,
     335,   487,   380,   165,   449,   450,   155,   353,   672,   299,
     673,   652,   299,   584,   148,   424,   583,   449,   450,  1370,
     775,   119,   776,  1386,  -575,   426,   777,   564,   299,   299,
     676,   587,   299,   299,   299,   299,  1316,   186,   162,   445,
     446,   447,   448,   299,  1364,  1367,   158,   299,   164,   382,
    2199,   766,   190,   767,  2122,   384,   159,   449,   450,   173,
     609,   174,   610,   449,   450,   173,   611,   174,   160,   644,
     645,   299,  1366,   299,   299,   299,   462,   449,   450,   166,
     609,  1059,   610,  1184,   449,   450,   611,   741,   167,   742,
     299,   644,   645,   743,   744,   168,   792,   299,   793,   644,
     645,   731,   794,   734,  2084,  2085,   803,   173,   793,   174,
    2086,   515,   804,   747,   899,  1090,  2194,   644,   645,   445,
     446,   447,   448,   445,   446,   447,   448,   445,   446,   447,
    1083,   797,  1107,   888,   445,   446,   447,   448,  2023,   798,
    1266,   800,  1118,   449,   450,   644,   645,   449,   450,   801,
     756,   644,   645,   449,   450,   644,   645,   756,  1267,   471,
    -577,   299,  1513,   644,   645,   299,   299,  1268,  1269,  1270,
     644,   645,  2024,  1271,  1272,  1266,  2025,  1340,  1820,  1194,
    1341,   299,   757,   758,  2156,   326,   327,   801,   778,   757,
     758,  2157,   169,  1267,   644,   645,  2221,   328,   644,   645,
    1266,   329,  1268,  1269,  1270,   182,   615,   616,  1271,  1272,
     757,   758,   882,   816,   884,  2158,   886,   887,  1267,  2159,
      68,    69,    70,    71,   605,   606,    74,  1268,  1269,  1270,
     607,   901,   902,  1271,  1272,    83,   644,   645,    86,   299,
     310,   183,  1266,   311,   312,   313,  2257,   435,  1217,   664,
     184,   436,   646,   639,   640,  2078,   314,   759,   760,  1741,
    1267,   648,   653,   299,   759,   760,   644,   645,   751,  1268,
    1269,  1270,   299,   878,   655,  1271,  1272,   471,   656,   471,
     299,   471,   471,   478,  1028,   759,   760,  2160,   187,   895,
     644,   645,  1406,   299,   299,   299,   471,   471,   299,   172,
     844,   172,   904,   299,   906,   644,   645,   644,   645,   644,
     645,  2205,   963,   188,   965,   966,   644,   645,   191,  2208,
     315,   644,   645,   669,   449,   450,  2206,   670,  2215,   299,
    2242,   979,   647,   326,   327,   936,   761,   762,   360,   745,
     297,   361,  2243,  1591,  1592,   328,   644,   645,  1411,   334,
     999,   449,   450,   192,   362,   843,   844,   299,   299,   844,
    1483,  2244,   654,  2088,  2089,   346,   193,   347,  1027,  2086,
    1029,  1030,  1031,  1032,  1033,  1034,  1020,  1036,  1037,  1038,
    1039,  1079,   909,  1044,  1045,  1046,   844,   943,  1538,   463,
     463,   844,   600,   601,   738,   603,   604,   605,   606,   905,
     173,   944,   174,   607,   202,   844,   299,   299,   299,  1212,
     989,   299,   194,  1369,   844,  1412,  1057,   738,   603,   604,
     605,   606,   173,   844,   174,  1061,   607,   201,  1211,   844,
     195,  1212,   478,   471,   478,   471,   471,   471,   471,   471,
     471,   196,   471,   471,   471,   471,  1042,   197,   471,   471,
     471,   172,  1048,  2053,  1047,   299,   212,   766,  1095,   767,
     766,  2054,   767,  1114,   766,   801,   767,  1058,  1318,  1716,
     203,   766,  1338,   767,  1124,   766,   198,   767,   768,   844,
     299,   907,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,   299,  1067,   518,   199,   607,
    1068,  1087,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,   299,  1104,   200,
    1215,   607,  1250,   299,   844,   299,   844,   204,   478,  1116,
    1251,   545,   205,   546,   844,   958,   959,  1122,  1297,   471,
     449,   450,   844,  1227,  1298,  1228,  1043,  1471,   844,  1472,
     206,   449,   450,   297,  1396,  1299,  1349,  1229,  -578,   844,
     449,   450,  1481,  1348,  1799,  1349,  1301,  1769,  1770,   299,
     844,   299,   970,   971,  1806,  1344,  1376,   640,  1456,   844,
     844,   213,   844,  1463,  1002,  1003,  1004,   844,  1480,  1007,
     620,  1507,   844,  1488,  1505,  1625,  1677,   844,   844,   844,
     844,   629,   300,  1709,  1710,   634,   299,   844,   844,  2185,
    1803,  1826,   644,   645,  1804,   844,   299,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,  1049,  1828,   303,  1910,   607,   844,   299,
     844,  1255,  1960,   301,  1526,  1130,  1961,  1978,  2003,   302,
     319,  1979,   844,  1562,  1563,   299,  2004,  2019,  2027,  2050,
     844,  1961,   844,   801,  2059,  2076,  2227,   299,  2060,  1961,
    2079,  2080,   320,  1081,   844,   844,   299,  1229,  1573,  2111,
    2132,   325,   333,   844,   844,  1578,  1526,   299,   345,  2133,
    2139,  1365,  1368,   844,  1961,  1103,   588,   766,  2147,   767,
     940,  1109,   844,  1111,  1593,  2155,  2169,  2204,  1229,   844,
    1961,   844,  2211,  2212,  2213,  2214,   844,   844,   844,   844,
     348,  2216,  2218,   748,   749,   844,  2060,   349,  2238,  2245,
    2254,  1613,  1961,   844,  2255,   358,  2264,  2267,   344,   764,
    1961,  2268,   697,   359,   148,  1629,   766,  1701,   767,  1702,
     364,  1786,  1635,  1787,  1879,   365,  1880,   366,   367,   373,
     378,   385,   386,   387,  1405,   388,   389,   420,   432,   433,
     440,   441,   434,   466,   467,   484,   486,   488,  1245,  1597,
     148,   493,   497,   516,  1185,   511,   553,   556,  -206,  -207,
    -208,   566,   565,   569,  1195,   299,   572,   573,   574,   585,
     633,   617,   618,  1372,   436,   625,   627,   626,   630,   674,
     677,   299,   635,   637,   638,   657,   658,   659,   678,   660,
     661,   662,   663,   690,   299,   675,   691,   685,   686,   471,
    1890,  1891,   679,  1223,   126,   680,   681,   682,   885,   684,
     687,   692,   694,  1482,  1484,  1231,   700,   699,   708,   709,
     710,   620,   726,   900,  1461,  1462,   721,   722,   180,   299,
     299,   724,   299,   299,   299,  1252,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   725,   727,   299,   728,
     729,   730,   732,   733,   735,   750,   753,   765,   773,   770,
     772,   813,   147,   309,   779,  1258,   835,   840,   846,   817,
     819,   847,  1264,  1373,   848,   879,  1275,   607,   889,   890,
     891,   892,   912,   913,   948,   910,   949,   952,   299,   471,
     471,   957,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     961,   962,   964,   299,   607,   427,   991,   993,  1012,   994,
    1894,   997,  1006,  1021,  1066,  1018,  1050,  1052,  1060,   299,
     299,   299,  1070,  1071,  1075,  1076,  1080,  1091,  1092,  1108,
    1097,  1110,  1113,  1121,  1123,  1126,  1131,   457,  1127,  1132,
    1133,  1135,   457,   457,   457,  1565,  1136,  1137,  1139,  1567,
    1140,   457,  1141,  1142,  1143,  1144,  1145,  1146,  1571,  1147,
    1572,  1148,  1404,  1574,  1151,  1802,  1155,  1182,  1183,  1201,
    1191,  1192,  1482,  1484,  1216,   299,  1210,  1232,  1193,  1240,
    1242,  1233,  1204,  1220,  1288,  1224,  1265,  1234,   457,  1290,
     463,  1287,  1253,   299,  1261,   299,   299,  1262,  1072,  1306,
    1308,  1309,  1310,  1321,   457,   299,  1322,  1323,  1326,  1334,
     471,  1337,  1336,  1347,   471,  1343,  1449,  1615,  1351,  1429,
    1352,  1353,  1350,   471,  1356,   471,  1357,  1358,   471,  1362,
    1375,  1377,  1393,  1378,  1400,  1399,  1401,  1402,  1407,     7,
       8,  1410,  1415,  1432,   299,   557,  1414,  1436,  1448,  -209,
    1475,  1492,  1467,  1493,  1494,  1497,  1498,   382,  1500,  1499,
    1501,   567,   568,  1502,  1503,  1504,  1515,  1519,  1518,  2092,
    1520,  1514,  1529,  1530,  1542,  1531,  1532,  1533,  1534,  1535,
    1536,  1537,   471,  1541,  1543,  1544,  1545,   299,  1546,   299,
    1547,  1548,  1549,  1550,  1943,  1552,  1554,  1557,  1490,  1491,
    1577,  1568,  1575,  1590,  1569,  1595,  1576,   299,  1579,  1581,
    1585,  1596,  1599,  1587,  1601,  1606,  1608,  1600,  1609,   299,
    1612,  1610,  1626,   299,  1624,  1632,  1630,  1633,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,  1811,  1811,  1637,    43,    44,    45,    46,  1650,  1651,
      48,  1652,  1654,  1656,  1660,  1661,  1662,  1219,   780,    56,
    1667,  1668,    59,   781,  1669,   782,   783,  1670,   784,  1671,
    1672,  1800,  1673,  1949,  1674,  1675,  1676,  1688,  1699,   299,
     299,   299,  1695,  1564,  1708,  1714,    80,   299,   299,   299,
    1715,  1721,  1722,  1723,  1239,  1724,  1729,  1725,  1730,  1731,
    1737,  1732,  1738,  1753,  1641,   299,  1646,  1761,  1763,  1764,
    1768,    95,    96,    97,  1744,  1782,   299,  1745,  1790,  1746,
    1747,  1772,  1792,   457,   299,  1748,  1749,  1755,   299,  1775,
    1752,  1794,  1756,  1797,   752,  1341,  1796,  1789,  1813,   299,
    1818,   299,  1821,  1823,  1793,  1829,  1830,  1825,  1832,  1833,
    1831,  1841,  1836,  1847,  1849,  1850,   786,  1851,  1852,  1856,
    1857,  1858,  1859,  1864,  1212,  1621,  1872,  1623,  1870,  1871,
    1874,   786,  1877,  1878,  1899,  1895,  1900,  1909,  1915,  1916,
    1917,  1935,  1869,   382,  1937,  1936,  1947,  1948,   806,  1953,
    -582,   478,   478,  -580,   801,  1965,  1966,   299,  1967,  1968,
    1972,  1987,  1981,  1976,  1982,  1983,  1984,  1998,  1999,  1985,
    1993,  1986,  2007,  1359,  2014,   471,  2002,  2016,  2026,  2029,
    2008,  2034,  2010,  2044,  2045,  2011,   299,  2017,  2046,  1379,
    2049,   299,  2051,  2035,  2052,  2075,  2095,  2100,  2041,  2042,
    2107,   457,  2057,   457,  1952,   457,   457,   457,  2048,  2113,
    2112,  2115,  2043,  2096,  2123,  2126,  2114,  -581,  2117,  2135,
     457,   457,  1785,  2127,  2128,  2137,  2138,  2131,  2143,  2146,
    2150,  2151,  2140,  2144,  2162,  2148,  2163,  1430,  1431,  2154,
    1433,  1434,  1435,  2165,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1927,  2166,  2173,  1929,  2177,  2182,
    2187,  2201,  2217,   299,  2228,  2229,  1754,  2230,   299,   299,
    2231,  2233,  2234,  2116,  2235,  1740,  2239,  2236,  2250,  2253,
    2249,  2256,  2260,  2265,  2266,  1840,  2269,  2270,  2195,  1628,
    1691,   299,   463,   463,  2066,  1658,  1460,   299,  1846,  2038,
     125,  1873,   299,   786,   812,  1392,   136,   137,   138,   951,
    2090,   299,  1784,   144,  1944,  1812,  1932,     0,  1115,   471,
       0,  1476,   471,     0,     0,     0,     0,   786,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1489,     0,     0,
     299,     0,     0,     0,  1372,     0,     0,     0,     0,     0,
       0,   382,     0,   299,   478,     0,   457,   457,   457,   457,
     457,   457,   457,   457,   457,     0,   457,   457,   457,   457,
       0,  1885,   457,   457,   457,     0,     0,     0,     0,     0,
       0,     0,   786,     0,     0,   786,     0,     0,     0,   478,
       0,     0,     0,  1539,     0,     0,     0,     0,   786,     0,
       0,     0,     0,     0,  1848,     0,   299,     0,     0,     0,
       0,  1553,     0,  1555,  1556,     0,  1926,   299,   299,     0,
       0,     0,     0,  1931,  1934,     0,     0,     0,     0,     0,
       0,     0,     0,  1094,     0,  1096,     0,     0,     0,     0,
       0,     0,   299,     0,  1945,     0,  1881,  1882,     0,     0,
       0,     0,   457,     0,   299,     0,     0,     0,     0,     0,
       0,     0,  1586,   457,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
    1911,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1902,  1903,  1904,  1905,  1906,  1908,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,  2098,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,  1645,     0,     0,  2071,     0,
       0,   299,   299,     0,     0,     0,     0,  1659,     0,     0,
       0,  1663,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,     0,   299,     0,     0,
       0,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2039,     0,     0,     0,     0,     0,     0,
       0,   382,     0,     0,     0,  1996,  1997,  1711,  1712,  1713,
       0,     0,     0,     0,   299,  1718,  1719,  1720,     0,     0,
       0,  2164,     0,     0,   786,     0,   786,   786,     0,     0,
       0,     0,     0,  1735,     0,     0,  2070,     0,     0,     0,
     786,     0,     0,   299,  1743,     0,     0,     0,     0,     0,
       0,     0,  1751,     0,     0,     0,     0,     0,     0,  2032,
     786,  2186,     0,     0,     0,     0,     0,  1760,     0,  1762,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   786,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,  1921,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,   299,   299,   299,   299,   786,  2072,
    2073,     0,     0,     0,     0,  1817,     0,     0,  2247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2091,     0,     0,     0,     0,     0,     0,  2261,  2263,     0,
       0,     0,     0,     0,  1839,  2101,   299,     0,     0,     0,
    2271,     0,     0,   457,     0,     0,     0,     0,     0,     0,
       0,     0,   299,     0,     0,     0,     0,     0,     0,  2102,
    2103,  2104,  2105,  2106,     0,     0,  2172,     0,     0,     0,
       0,     0,     0,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,   471,   471,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   471,     0,     0,     0,     0,
       0,  1876,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2141,     0,     0,     0,  2145,     0,     0,
       0,     0,     0,   457,   457,     0,     0,     0,     0,  1817,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2176,     0,     0,     0,     0,     0,  1918,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2188,  2189,  2190,  2191,  2193,     0,     0,  2178,     0,
       0,     0,  2180,     0,     0,     0,     0,     0,  1942,     0,
       0,     0,     0,     0,     0,     0,   786,     0,  2192,     0,
       0,  1951,     0,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
    2232,  1922,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2225,  2226,     0,     0,     0,   170,   390,
       0,     0,     0,     0,  1817,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,   457,     0,   457,
       0,     0,   457,     0,     0,     0,     0,     0,     0,     0,
    2015,     0,  1580,   391,   392,   393,   394,   395,   396,   397,
     398,   399,     0,     0,     0,     0,   400,   401,   402,   403,
       0,     0,     0,     0,   404,   405,   406,   407,     0,     0,
       0,     0,     0,   408,     0,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,     0,     0,   410,
       0,     0,   411,     0,     0,     0,   176,     0,   430,   177,
     588,     0,   178,     0,   179,     0,  2058,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,  2067,     0,     0,     0,     0,   458,     0,     0,     0,
     468,     0,     0,   443,     0,   474,     0,     0,     0,     0,
       0,     0,   479,     0,     0,   481,     0,  1817,   588,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2097,   490,   491,   492,     0,   494,   495,   496,     0,
     498,   499,   500,   501,   502,   503,   504,     0,   506,   507,
     508,   509,     0,     0,     0,     0,   513,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1817,   412,   413,   414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   415,     0,     0,     0,   416,
       0,   417,   119,     0,     0,     0,     0,     0,     0,     0,
       0,  2142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   449,   450,
       0,     0,     0,     0,     0,  -576,     0,  1614,     0,     0,
       0,   575,   577,   579,   580,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,   513,   513,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   457,   457,     0,   632,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,   643,
       0,     0,     0,     0,   643,     0,     0,     0,     0,   457,
       0,     0,     0,     0,   513,   665,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,  1817,     0,     0,     0,   607,   688,
     513,     0,     0,     0,     0,   693,     0,   695,   696,     0,
     698,     0,     0,     0,   701,   702,   703,     0,     0,   704,
       0,     0,     0,     0,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   842,   603,   604,
     605,   606,     0,     0,  1817,     0,   607,     0,   766,     0,
     767,     0,     0,     0,     0,     0,     0,     0,     0,   737,
       0,     0,     0,     0,   513,   746,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   787,     0,     0,  1560,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   457,     0,     0,   457,     0,   818,     0,
       0,     0,     0,   823,     0,     0,     0,   827,     0,     0,
       0,   786,     0,   786,     0,     0,     0,     0,     0,     0,
       0,   841,   577,     0,     0,     0,   845,     0,   457,     0,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   865,   867,   868,   869,
     870,   871,   872,   873,   874,   875,   875,     0,   880,   881,
       0,   883,     0,   457,     0,     0,     0,     0,     0,     0,
       0,   893,     0,     0,   897,   898,     0,     0,     0,     0,
       0,   875,     0,     0,     0,     0,   513,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   914,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   929,   931,   932,   933,   934,   935,     0,   937,
     938,     0,     0,     0,     0,     0,     0,   945,   946,   947,
     771,     0,     0,     0,     0,   953,   954,   955,   956,     0,
     513,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   575,
     737,   975,     0,     0,     0,   980,   981,   982,   983,   984,
     985,   986,   987,   988,     0,     0,     0,     0,     0,   995,
     996,     0,   998,     0,     0,  1000,     0,     0,     0,   513,
     513,   513,  1005,     0,   513,  1008,  1009,  1010,     0,     0,
       0,     0,  1013,     0,  1015,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,  1035,     0,     0,   607,     0,  1561,
       0,     0,     0,     0,     0,     0,     0,     0,   513,     0,
    1495,     0,     0,     0,     0,  1054,  1055,     0,  1056,     0,
       0,   937,   938,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   513,     0,
    1085,     0,     0,     0,     0,  1088,  1089,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     513,     0,  1105,  1106,     0,     0,   513,     0,   513,  1112,
       0,     0,     0,  1105,     0,  1119,     0,  1120,     0,   786,
       7,     8,     0,  1125,     0,     0,     0,  1128,     0,     0,
       0,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
    1149,     0,   929,   607,  1152,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,   786,     0,     0,     0,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   513,
    1196,  1197,  1198,     0,     0,     0,     0,   786,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,   514,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   513,   780,
      56,     0,     0,    59,   781,     0,   782,   783,     0,   784,
     513,     0,     0,     0,     0,     0,     0,   457,  1238,     0,
       0,     0,  1244,     0,     0,     0,     0,    80,     0,     0,
     513,     0,     0,     0,     0,     0,   457,   457,  1259,  1260,
       0,     0,     0,     0,  1263,     0,     0,     0,     0,   457,
       0,     0,    95,    96,    97,     0,     0,     0,     0,   578,
       0,  1289,   514,     0,  1291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   514,   514,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1311,
       0,  1313,  1314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1332,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   514,     0,     0,     0,     0,   170,   390,  2130,   976,
       0,     0,     0,     0,  1355,     0,     0,     0,     0,     0,
       0,  1361,     0,     0,     0,     0,     0,   514,  1374,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1397,  1398,     0,     0,     0,     0,   513,     0,     0,
       0,   391,   392,   393,   394,   395,   396,   397,   398,   399,
       0,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,   404,   405,   406,   407,     0,     0,     0,  1427,
       0,   408,     0,   409,     0,     0,     0,     0,     0,     0,
     788,   514,     0,     0,     0,     0,     0,   410,     0,     0,
     411,   513,     0,     0,   176,     0,     0,   177,     0,     0,
     178,     0,   179,     0,     0,     0,     0,  1450,     0,     0,
       0,     0,     0,    46,     0,     0,     0,  1451,  1452,  1453,
    1454,  1455,     0,     0,     0,     0,  1457,  1458,     0,  1459,
       0,   443,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1469,  1470,     0,     0,  1447,     0,
       0,     0,  1473,  1474,     0,     0,     0,     0,     0,   578,
       0,  1478,  1479,     0,     0,     0,     0,  1485,  1486,     0,
       0,     0,     0,   513,   513,     0,     0,     0,     0,     0,
       0,     0,     0,   866,     0,     0,     0,     0,  1540,     0,
       0,     0,   876,   877,     0,     0,     0,     0,     0,     0,
       0,   412,   413,   414,     0,     0,     0,  1517,     0,     0,
       0,     0,     0,   415,     0,     0,     0,   416,   903,   417,
     119,     0,     0,   514,     0,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,  1551,     0,     0,   607,     0,   930,
     766,     0,   767,  1807,     0,     0,     0,     0,   513,     0,
       0,     0,     0,     0,     0,     0,  1566,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   514,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1485,  1486,
       0,     0,     0,  1583,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1589,     0,     0,  1594,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,   514,   514,   514,  1584,
     607,   514,     0,     0,     0,     0,  1616,     0,     0,  1619,
     513,  1622,   513,     0,     0,     0,     0,     0,     0,     0,
    1631,     0,     0,  1634,     0,  1631,     0,  1638,  1640,     0,
    1602,  1648,  1649,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   514,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   514,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,   514,   607,  1717,
       0,     0,     0,   514,     0,   514,     0,     0,     0,  1726,
    1727,  1728,     0,     0,     0,     0,     0,     0,  1734,     0,
    1736,     0,     0,     0,     0,     0,     0,  1739,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   513,     0,     0,     0,     0,     0,  1757,  1758,   930,
       0,  1153,     0,     0,     0,     0,     0,     0,  1765,  1766,
    1767,     0,     0,     0,     0,     0,     0,     0,  1776,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1788,
       0,     0,     0,     0,     0,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   514,     0,     0,     0,
    1805,     0,     0,     0,     0,     0,     0,     0,  1814,  1815,
       0,  1733,     0,     0,     0,     0,     0,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,   514,     0,     0,     0,   607,
     769,     0,     0,     0,  1844,     0,     0,   514,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,   514,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1860,  1861,  1862,     0,     0,
       0,     0,     0,     0,     0,     0,  1863,     0,     0,     0,
       0,  1866,  1867,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1875,     0,     0,     0,     0,     0,
       0,   513,   513,  1883,     0,  1884,     0,     0,     0,     0,
       0,  1892,  1893,  1791,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   894,     0,     0,     0,
     513,     0,     0,     0,     0,   513,  1912,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1925,     0,     0,  1928,     0,     0,     0,  1930,     0,     0,
       0,     0,     0,     0,     0,     0,  1866,  1867,     0,  1939,
       0,     0,     0,     0,     0,     0,     0,   941,     0,  1946,
       0,     0,     0,     0,   514,     0,     0,     0,     0,     0,
       0,     0,     0,  1957,     0,     0,     0,     0,  1963,  1964,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1969,     0,     0,  1970,  1969,     0,  1973,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,   514,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
     513,   513,     0,     0,     0,     0,     0,  2000,  2001,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2009,
       0,     0,     0,     0,     0,     0,     0,     0,  2018,     0,
       0,     0,     0,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2030,  2031,     0,     0,   513,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     514,   514,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2055,  2056,
       0,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,  2069,
       0,     0,     0,   607,   513,   513,  2074,     0,     0,     0,
       0,  2077,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     513,     0,     0,     0,     0,   514,     0,     0,     0,  2108,
       0,     0,     0,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,     0,  1168,  1169,  1170,  1171,     0,
    1173,  1174,  1175,  1176,  2119,     0,     0,     0,     0,   175,
    2124,   181,     0,  2125,     0,     0,  1188,     0,  1190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1200,
       0,     0,     0,     0,     0,     0,  1206,  1207,     0,     0,
       0,     0,     0,     0,  2149,  1218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   514,     0,   514,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2167,  2168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2174,  2175,     0,   513,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2184,     0,     0,     0,     0,   513,   513,   513,   513,
     513,     0,     0,     0,     0,     0,  1963,     0,     0,     0,
    2200,     0,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2220,     0,     0,
       0,     0,  2223,  2224,     0,     0,     0,     0,     0,     0,
    1317,  1319,  1320,     0,     0,   513,  1324,  1325,     0,     0,
    1328,  1329,  1330,  1331,     0,  1333,     0,     0,     0,     0,
    1339,     0,     0,     0,     0,  1795,     0,     0,     0,     0,
       0,     0,  2251,  2252,     0,     0,     0,     0,   514,     0,
       0,     0,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   547,   548,   549,
     550,   551,   552,     0,   554,   555,     0,     0,     0,     0,
       0,     0,     0,     0,   561,   562,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   570,   571,   214,   170,
     390,     0,  1426,     0,  1428,   215,   216,   217,     0,     0,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   428,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
       0,  1845,  1801,     0,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   249,   250,   251,   252,   400,   401,   402,
     403,   253,     0,     0,     0,   404,   405,   406,   407,     0,
       0,     0,     0,     0,   408,     0,   409,   258,   259,   260,
       0,     0,     0,     0,     0,     0,     0,     0,   261,    25,
     410,   262,     0,   411,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   705,   706,   707,     0,   514,   514,
     711,   712,   713,   714,   715,   716,   717,     0,   718,     0,
       0,     0,     0,   719,   720,  1913,     0,   723,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   514,     0,     0,
       0,   736,   514,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1914,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,   412,   413,   414,   273,     0,     0,
       0,     0,     0,   275,   276,   277,   415,   278,   279,   280,
     416,  2006,   417,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,   429,     0,     0,     0,     0,     0,   283,     0,     0,
    1603,  2033,   369,     0,     0,     0,  1639,     0,     0,   286,
       0,     0,     0,     0,     0,     0,     0,   514,   514,     0,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,  2047,     0,
       0,     0,   607,  1642,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   578,     0,     0,   911,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   514,     0,     0,  1678,  1679,  1680,  1681,  1682,  1683,
    1684,     0,     0,     0,     0,  1689,  1690,     0,     0,     0,
       0,     0,  1692,     0,  1694,     0,     0,     0,  1698,     0,
       0,  1700,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1707,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,   514,   514,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   514,     0,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,  1771,     0,
    1774,   607,     0,     0,  1781,     0,  1783,     0,     0,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,  1808,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
    2081,     0,     0,     0,     0,     0,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,   514,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   514,   514,   514,   514,   514,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,     6,   368,
       0,     0,     0,     0,   215,   216,   217,  1868,     0,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
       0,     0,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   250,   251,   252,     0,     0,     0,  1213,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
     255,   256,   257,     0,     0,     0,   258,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,   261,    25,     0,
     262,     0,  1230,     0,     0,     0,   263,     0,     0,   264,
       0,     0,   265,     0,   266,     0,     0,     0,     0,     0,
       0,    42,     0,  1954,     0,   267,  1955,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,    57,    58,
       0,   269,     0,   270,     0,     0,   271,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,     0,     0,     0,  1989,  1990,     0,  1992,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,   273,   274,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,   280,  2082,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2036,  2037,     0,     0,     0,     0,     0,   281,
     282,     0,     0,     0,     0,     0,   283,     0,     0,     0,
       0,   369,     0,     0,     0,   370,     0,     0,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1419,     0,     0,     0,     0,
       0,  2068,     0,   214,     6,   390,     0,     0,     0,     0,
     215,   216,   217,     0,     0,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,     0,     0,     0,  1643,
     392,   393,   394,   395,   396,   397,   398,   399,   249,   250,
     251,   252,   400,   401,   402,   403,   253,   254,     0,     0,
     404,   405,   406,   407,     0,     0,   255,   256,   257,   408,
       0,   409,   258,   259,   260,     0,     0,     0,     0,     0,
    1477,     0,     0,   261,    25,   410,   262,     0,   411,     0,
       0,     0,   263,     0,     0,   264,     0,     0,   265,     0,
     266,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,    57,    58,     0,   269,     0,   270,
       0,     0,   271,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    83,     0,     0,    86,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2161,     0,     0,     0,   272,   412,
     413,   414,   273,   274,     0,     0,     0,     0,   275,   276,
     277,   415,   278,   279,   280,   416,     0,   417,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   282,     0,  2241,     0,
    1604,  1605,   283,     0,     0,     0,     0,   369,     0,     0,
       0,  1644,     0,     0,   286,     0,     0,     0,   214,     6,
     390,     0,     0,     0,     0,   215,   216,   217,     0,     0,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,     0,     0,     0,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   249,   250,   251,   252,   400,   401,   402,
     403,   253,   254,     0,     0,   404,   405,   406,   407,     0,
       0,   255,   256,   257,   408,  1696,   409,   258,   259,   260,
       0,     0,     0,     0,  1703,     0,     0,     0,   261,    25,
     410,   262,     0,   411,     0,     0,     0,   263,     0,     0,
     264,     0,     0,   265,     0,   266,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,    57,
      58,     0,   269,     0,   270,     0,     0,   271,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
    2207,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,   412,   413,   414,   273,   274,     0,
       0,     0,     0,   275,   276,   277,   415,   278,   279,   280,
     416,     0,   417,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,   282,     0,     0,     0,     0,  1842,   283,     0,     0,
       0,     0,   369,   214,   170,   390,   285,   442,     0,   286,
     215,   216,   217,     0,     0,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   428,   236,   237,   238,   239,   240,   241,   242,
     243,     0,     0,     0,     0,     0,     0,     0,     0,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   249,   250,
     251,   252,   400,   401,   402,   403,   253,     0,     0,     0,
     404,   405,   406,   407,     0,     0,     0,     0,     0,   408,
       0,   409,   258,   259,   260,     0,     0,     0,     0,     0,
       0,     0,     0,   261,    25,   410,   262,     0,   411,     0,
       0,     0,   176,     0,     0,   177,     0,     0,   178,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   443,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1980,   588,     0,
       0,   444,     0,     0,     0,     0,     0,     0,   272,   412,
     413,   414,   273,     0,     0,     0,     0,     0,   275,   276,
     277,   415,   278,   279,   280,   416,     0,   417,   119,     0,
     445,   446,   447,   448,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   281,   429,     0,     0,     0,
       0,     0,   283,     0,   449,   450,     0,   451,     0,   452,
     214,     6,     0,   453,   286,   689,     0,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   842,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,   588,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   512,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   369,   214,     6,  1742,     0,   581,
       0,   286,   215,   216,   217,     0,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   251,   252,     0,     0,     0,     0,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,     0,     0,     0,   258,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,    25,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,   266,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,    57,    58,     0,   269,
       0,   270,     0,     0,   271,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   842,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,  1022,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   273,   274,     0,     0,     0,     0,
     275,   276,   277,     0,   278,   279,   280,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   282,     0,
       0,     0,     0,     0,   283,     0,     0,     0,     0,   369,
     214,     6,     0,   285,     0,     0,   286,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,  1221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   649,  1907,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   651,   214,     6,     0,   329,   581,
       0,   286,   215,   216,   217,     0,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   251,   252,     0,     0,     0,     0,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,     0,     0,     0,   258,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,    25,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,   266,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,    57,    58,     0,   269,
       0,   270,     0,     0,   271,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,  1222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   273,   274,     0,     0,     0,     0,
     275,   276,   277,     0,   278,   279,   280,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   282,     0,
       0,     0,     0,     0,   283,     0,     0,     0,     0,   284,
     214,     6,     0,   285,     0,     0,   286,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,  1559,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   282,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   369,   214,     6,     0,   285,     0,
       0,   286,   215,   216,   217,     0,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   251,   252,     0,     0,     0,     0,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,     0,     0,     0,   258,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,    25,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,   266,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,    57,    58,     0,   269,
       0,   270,     0,     0,   271,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   273,   274,     0,     0,     0,     0,
     275,   276,   277,     0,   278,   279,   280,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   512,     0,
       0,     0,     0,     0,   283,     0,     0,     0,     0,   369,
     214,     6,     0,   576,     0,     0,   286,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
     170,   390,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   404,   405,   406,   407,
       0,     0,     0,     0,     0,   408,     0,   409,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,   410,     0,     0,   411,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   512,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   369,   214,     6,     0,     0,   581,
       0,   286,   215,   216,   217,     0,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   251,   252,     0,     0,     0,     0,   253,   254,
       0,     0,     0,     0,     0,   412,   413,   414,   255,   256,
     257,     0,     0,     0,   258,   259,   260,   415,     0,     0,
       0,   416,     0,   417,   119,   261,    25,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,   266,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   267,     0,   421,   390,     0,     0,     0,
       0,     0,     0,     0,   268,     0,    57,    58,     0,   269,
       0,   270,     0,     0,   271,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,     0,
     391,   392,   393,   394,   395,   396,   397,   398,   399,     0,
       0,     0,     0,   400,   401,   402,   403,     0,     0,     0,
       0,   404,   405,   406,   407,     0,     0,     0,     0,     0,
     408,     0,   409,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   273,   274,   410,     0,     0,   411,
     275,   276,   277,     0,   278,   279,   280,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   282,     0,
       0,     0,     0,     0,   283,     0,     0,     0,     0,   619,
     214,     6,     0,   285,     0,     0,   286,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
     412,   413,   414,   255,   256,   257,     0,     0,     0,   258,
     259,   260,   415,     0,     0,     0,   416,     0,   417,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,   390,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,   391,   392,   393,   394,   395,
     396,   397,   398,   399,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   404,   405,   406,   407,
       0,     0,     0,     0,     0,   408,     0,   409,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,   410,     0,     0,   411,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   282,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   628,   214,     6,     0,   285,     0,
       0,   286,   215,   216,   217,     0,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   251,   252,     0,     0,     0,     0,   253,   254,
       0,     0,     0,     0,     0,   412,   413,   414,   255,   256,
     257,     0,     0,     0,   258,   259,   260,   415,     0,     0,
       0,   416,     0,   417,     0,   261,    25,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,   266,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,    57,    58,     0,   269,
       0,   270,     0,     0,   271,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,   766,     0,   767,     0,     0,     0,     0,
       0,  1773,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   273,   274,     0,     0,     0,     0,
     275,   276,   277,     0,   278,   279,   280,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,   512,     0,
       0,     0,     0,     0,   283,     0,     0,     0,     0,   369,
     214,     6,     0,   928,     0,  1403,   286,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,  1011,     0,
       0,     0,     0,     0,     0,     0,   968,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   512,     0,     0,     0,     0,     0,   283,
     214,     6,     0,     0,   369,  1620,     0,   215,   216,   217,
       0,   286,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,  1837,     0,     0,     0,  1838,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   512,     0,     0,     0,     0,     0,   283,
     214,     6,     0,     0,   369,     0,     0,   215,   216,   217,
       0,   286,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,  1888,     0,     0,     0,  1889,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   282,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   369,   214,     6,     0,  1750,     0,
       0,   286,   215,   216,   217,     0,     0,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,   250,   251,   252,     0,     0,     0,     0,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,     0,     0,     0,   258,   259,   260,     0,     0,     0,
       0,     0,     0,     0,     0,   261,    25,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,   264,     0,     0,
     265,     0,   266,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,    57,    58,     0,   269,
       0,   270,     0,     0,   271,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,  1919,     0,     0,
       0,  1920,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,   273,   274,     0,     0,     0,     0,
     275,   276,   277,     0,   278,   279,   280,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   649,  1907,     0,
       0,     0,     0,     0,   283,     0,     0,     0,     0,   651,
     214,     6,     0,   329,     0,     0,   286,   215,   216,   217,
       0,     0,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,   250,   251,   252,     0,
       0,     0,     0,   253,   254,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,   264,     0,     0,   265,     0,   266,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,    57,    58,     0,   269,     0,   270,     0,     0,   271,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,  2093,     0,     0,     0,  2094,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,   273,
     274,     0,     0,     0,     0,   275,   276,   277,     0,   278,
     279,   280,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   512,     0,     0,     0,     0,     0,   283,
     214,   170,   390,     0,   369,     0,     0,   215,   216,   217,
       0,   286,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   428,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,     0,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   249,   250,   251,   252,   400,
     401,   402,   403,   253,     0,     0,     0,   404,   405,   406,
     407,     0,     0,     0,     0,     0,   408,     0,   409,   258,
     259,   260,     0,     0,     0,     0,     0,     0,     0,     0,
     261,    25,   410,   262,     0,   411,   214,   170,   390,     0,
       0,     0,     0,   215,   216,   217,     0,     0,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   428,   236,   237,   238,   239,
     240,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,     0,  1643,   392,   393,   394,   395,   396,   397,   398,
     399,   249,   250,   251,   252,   400,   401,   402,   403,   253,
       0,     0,     0,   404,   405,   406,   407,     0,     0,     0,
       0,     0,   408,     0,   409,   258,   259,   260,     0,     0,
       0,     0,     0,     0,     0,     0,   261,    25,   410,   262,
       0,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,   412,   413,   414,   273,
       0,     0,     0,     0,     0,   275,   276,   277,   415,   278,
     279,   280,   416,     0,   417,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,   429,     0,     0,     0,     0,     0,   283,
       0,     0,     0,     0,   369,     0,     0,     0,  1924,     0,
       0,   286,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   799,     0,     0,     0,     0,     0,
       0,   272,   412,   413,   414,   273,     0,     0,     0,     0,
       0,   275,   276,   277,   415,   278,   279,   280,   416,     0,
     417,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   281,   429,
       0,     0,     0,     0,     0,   283,     0,     0,     0,     0,
     369,   214,   170,   390,  1807,     0,     0,   286,   215,   216,
     217,     0,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     428,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   249,   250,   251,   252,
     400,   401,   402,   403,   253,     0,     0,     0,   404,   405,
     406,   407,     0,     0,     0,     0,     0,   408,     0,   409,
     258,   259,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   261,    25,   410,   262,     0,   411,   214,   170,     0,
       0,     0,     0,     0,   215,   216,   217,     0,     0,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   428,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   249,   250,   251,   252,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,     0,     0,     0,     0,     0,   261,    25,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   412,   413,   414,
     273,     0,     0,     0,     0,     0,   275,   276,   277,   415,
     278,   279,   280,   416,     0,   417,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,   429,     0,     0,     0,     0,     0,
     283,     0,   214,   170,     0,   369,     0,     0,     0,   215,
     216,   217,   286,     0,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   428,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,   273,   249,   250,   251,
     252,     0,   275,   276,   277,   253,   278,   279,   280,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,     0,     0,   281,
     429,     0,   261,    25,     0,   262,   283,     0,     0,     0,
       0,   369,   214,   170,     0,   631,     0,   896,   286,   215,
     216,   217,     0,     0,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   428,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   250,   251,
     252,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,    25,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   273,     0,     0,     0,     0,     0,   275,   276,   277,
       0,   278,   279,   280,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   649,   650,     0,     0,     0,     0,
       0,   283,     0,     0,     0,     0,   651,   214,   170,     0,
     329,     0,     0,   286,   215,   216,   217,     0,     0,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   428,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   273,   249,   250,   251,   252,     0,   275,   276,   277,
     253,   278,   279,   280,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,     0,     0,   281,   429,     0,   261,    25,     0,
     262,   283,   214,   170,     0,  1354,   369,     0,     0,   215,
     216,   217,     0,   286,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   428,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   250,   251,
     252,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,    25,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,   273,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,   280,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     429,     0,     0,     0,     0,     0,   283,   214,   170,     0,
    1516,   369,  1117,     0,   215,   216,   217,     0,   286,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   428,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   273,   249,   250,   251,   252,     0,   275,   276,   277,
     253,   278,   279,   280,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,     0,     0,   281,   429,     0,   261,    25,     0,
     262,   283,   214,   170,     0,  1582,   369,     0,     0,   215,
     216,   217,     0,   286,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   428,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   250,   251,
     252,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,    25,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,   273,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,   280,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     429,     0,     0,     0,     0,     0,   283,   214,   170,     0,
       0,   369,     0,     0,   215,   216,   217,     0,   286,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   428,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   273,   249,   250,   251,   252,     0,   275,   276,   277,
     253,   278,   279,   280,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,     0,     0,   281,   429,     0,   261,    25,     0,
     262,   283,   214,   170,     0,     0,   369,     0,     0,   215,
     216,   217,     0,   286,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   428,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   250,   251,
     252,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,   259,   260,     0,     0,     0,     0,     0,     0,
       0,     0,   261,    25,     0,   262,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,   273,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,   280,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   281,
     429,     0,     0,     0,     0,     0,   283,   214,   170,     0,
       0,   369,  1636,     0,   215,   216,   217,     0,   286,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   428,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
       0,   273,   249,   250,   251,   252,     0,   275,   276,   277,
     253,   278,   279,   280,   170,   390,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,   260,     0,
       0,     0,     0,     0,   281,   429,     0,   261,    25,     0,
     262,   283,     0,     0,     0,     0,   369,  1971,     0,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,   391,
     392,   393,   394,   395,   396,   397,   398,   399,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
     404,   405,   406,   407,     0,     0,     7,     8,     0,   408,
       0,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   410,     0,     0,   411,     0,
       0,     0,   176,     0,     0,   177,     0,     0,   178,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   443,
       0,     0,   272,     0,     0,     0,   273,     0,     0,     0,
       0,     0,   275,   276,   277,     0,   278,   279,   280,     0,
       0,     0,   119,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,   281,
     429,    43,    44,    45,    46,     0,   283,    48,     7,     8,
       0,   369,     0,     0,     0,   780,    56,     0,   286,    59,
     781,     0,   782,   783,     0,   784,     0,     0,     0,   412,
     413,   414,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   415,     0,    80,     0,   416,     0,   417,   119,     0,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,    95,    96,
      97,     0,   607,     0,     0,     0,     0,     0,     7,     8,
       0,  1807,   805,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,  1001,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1051,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1053,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1254,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1256,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1257,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1276,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1295,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1312,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1346,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      95,    96,    97,    43,    44,    45,    46,  1508,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   780,    56,     0,
       0,    59,   781,     0,   782,   783,     0,   784,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,    -4,
       1,     0,     0,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,     0,     0,     0,     0,     0,     0,
      95,    96,    97,     0,     0,     0,     0,  2152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,    -4,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,    -4,    -4,    -4,     0,
     607,     0,     0,    -4,    -4,     0,     0,     0,     0,    -4,
     807,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,  2209,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,
       0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,     0,
       0,     0,     0,     0,     0,    -4,     0,    -4,    -4,     0,
       0,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       9,    10,    11,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   968,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,     0,    25,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    42,    43,    44,    45,    46,    47,     0,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    65,    66,
      67,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,    91,    92,
       0,     0,     0,    93,     0,     0,     0,     0,    94,    95,
      96,    97,   170,   390,    98,     0,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,   119,   120,     0,     0,     0,   391,   392,   393,
     394,   395,   396,   397,   398,   399,     0,     0,     0,     0,
     400,   401,   402,   403,     7,     8,     0,     0,   404,   405,
     406,   407,     0,     0,     0,     0,     0,   408,     0,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,     0,     0,   411,     0,     0,     0,
     176,     0,     0,   177,     0,     0,   178,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   443,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   780,    56,     0,     0,    59,   781,     0,
     782,   783,     0,   784,     0,     0,     0,  1063,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   412,   413,   414,
       0,    80,     0,     0,     0,  1064,     0,     0,     0,   415,
       0,     0,     0,   416,     0,   417,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,   780,
      56,     0,     0,    59,   781,     0,   782,   783,     0,   784,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,    95,    96,    97,     0,     0,     0,     0,     0,
     969,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1019,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1129,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1167,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1177,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1178,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1179,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1180,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1181,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1186,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1187,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1189,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1304,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1327,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1413,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1417,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1510,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1511,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1558,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1685,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1686,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1687,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1835,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1958,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1959,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1991,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2063,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2120,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2121,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2136,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2170,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2197,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2202,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2203,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,   839,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,  1098,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,  1154,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,  1202,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,  1203,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,  1247,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,  1279,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,  1293,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
    1300,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,  1360,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,  1380,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,  1416,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,  1464,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,  1465,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,  1466,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,  1512,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,  1588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,  1886,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
    1897,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,  1938,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,  2012,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,  2028,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,  2040,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,     0,  2064,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,  2099,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,  2109,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,  2110,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
       0,  2134,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,     0,     0,
    2183,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,     0,     0,  2222,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,     0,     0,  2240,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,     0,     0,  2258,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,     0,     0,  2259,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,     0,   739,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,     0,   960,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,     0,
    2005,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,   766,     0,   767,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,  1025,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,  1074,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,  1226,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,  1294,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,  1296,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,     0,     0,  1302,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   738,   603,   604,   605,   606,     0,     0,
       0,     0,   607,     0,     0,     0,  1303,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     738,   603,   604,   605,   606,     0,     0,     0,     0,   607,
       0,     0,     0,  1395,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   738,   603,   604,
     605,   606,     0,     0,     0,     0,   607,     0,     0,     0,
    1409,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   738,   603,   604,   605,   606,     0,
       0,     0,     0,   607,     0,     0,     0,  1617,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,     0,     0,  1706,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   738,   603,
     604,   605,   606,     0,     0,     0,     0,   607,     0,     0,
       0,  1759,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   738,   603,   604,   605,   606,
       0,     0,     0,     0,   607,     0,     0,     0,  1950,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   738,   603,   604,   605,   606,     0,     0,     0,
       0,   607,     0,     0,     0,  1995,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   738,
     603,   604,   605,   606,     0,     0,     0,     0,   607,     0,
       0,     0,  2013,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   820,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   821,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   822,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   824,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   825,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   826,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   828,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   829,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   830,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   831,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   832,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   833,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   834,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   836,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   837,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   838,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   908,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,   942,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,   990,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1011,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1014,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1016,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1017,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1023,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1024,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1062,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1073,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1134,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1138,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1150,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1225,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1235,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1236,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1237,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1246,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1248,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1249,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1278,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1280,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1281,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1282,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1283,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1284,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1285,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1286,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1292,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1305,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1307,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1345,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1394,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1408,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1618,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1653,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1693,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1705,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1822,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1824,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1827,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1834,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1887,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1896,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  1923,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  1994,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  2061,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  2062,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607,     0,  2196,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   738,   603,   604,   605,
     606,     0,     0,     0,     0,   607,     0,  2237,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   738,   603,   604,   605,   606,     0,     0,     0,     0,
     607
};

static const yytype_int16 yycheck[] =
{
       3,   322,  1273,  1277,   763,  1472,     4,   160,    63,     6,
     769,  1744,  1790,     6,  1792,     4,     3,   646,   647,   202,
       4,     6,    25,     4,     6,    25,   108,     7,   211,     5,
       4,     4,     4,  1974,   146,     4,   108,     4,   108,     5,
    1777,     5,     9,     6,     6,     5,     4,   108,     6,   258,
       7,   143,    55,     6,     4,   245,   246,   266,   102,     4,
       4,   453,   132,     6,   257,     6,   259,     4,   261,     4,
     143,   132,     4,   245,   246,     4,   266,   121,   146,     7,
       6,    84,     9,   151,   152,   153,     7,     9,   161,   164,
      93,    36,    37,   105,   266,    98,   108,   170,   171,   172,
       6,   193,     9,   176,   177,  1842,   109,    36,    37,     9,
      94,   164,   245,   246,     4,   190,   245,   246,     9,   245,
     246,   260,     6,   306,   307,   308,  1859,   266,     9,   197,
       6,   206,   207,   266,   245,   246,   260,   266,   245,   246,
     266,    14,   266,   146,   102,   213,    36,    37,   151,   152,
     153,   105,   245,   246,   108,   266,   110,   160,   102,   266,
     147,     0,   106,   346,   347,   348,     7,   121,   112,   113,
       7,   115,   116,   266,     7,   257,   245,   246,   181,   258,
     363,     7,   111,   112,   263,   257,   257,   102,  2129,   262,
     105,   108,   136,   108,   197,   110,   258,   266,   260,   202,
     255,   256,   257,   206,   266,   109,   121,   111,   211,   212,
     213,   180,   181,   182,   183,   178,   178,   201,   257,   611,
     261,   111,   112,   192,   265,   194,   195,   196,   197,   198,
     228,  1698,   205,   202,   203,   105,   205,   258,   108,   228,
     110,   257,   146,   102,   228,   266,   105,   240,   241,   108,
     230,   231,   232,   233,   228,     6,   228,  1528,   240,   241,
     257,   228,   121,     6,   261,   268,   264,    69,    70,  2002,
      72,   175,   261,   261,   254,   255,   261,   261,   259,   282,
     261,   334,   285,   286,   265,   261,   286,   254,   255,   261,
     257,   228,   259,   262,   261,   261,   263,   261,   301,   302,
     353,   261,   305,   306,   307,   308,   263,   257,   261,   230,
     231,   232,   233,   316,  1073,  1074,     6,   320,   261,   322,
     261,   258,   257,   260,  2057,   257,     6,   254,   255,   257,
     257,   259,   259,   254,   255,   257,   263,   259,   257,   245,
     246,   344,   263,   346,   347,   348,     4,   254,   255,     6,
     257,   743,   259,   260,   254,   255,   263,   257,     6,   259,
     363,   245,   246,   263,   432,   259,   257,   370,   259,   245,
     246,   424,   263,   426,   148,   149,   257,   257,   259,   259,
     154,   206,   263,   436,   567,   777,  2164,   245,   246,   230,
     231,   232,   233,   230,   231,   232,   233,   230,   231,   232,
     233,   258,   794,   556,   230,   231,   232,   233,   266,   266,
     143,   258,   804,   254,   255,   245,   246,   254,   255,   266,
       4,   245,   246,   254,   255,   245,   246,     4,   161,   432,
     261,   434,   262,   245,   246,   438,   439,   170,   171,   172,
     245,   246,   266,   176,   177,   143,   266,   263,     4,   258,
     266,   454,    36,    37,   266,   245,   246,   266,   461,    36,
      37,   266,   259,   161,   245,   246,  2199,   257,   245,   246,
     143,   261,   170,   171,   172,   257,   301,   302,   176,   177,
      36,    37,   550,   486,   552,   266,   554,   555,   161,   266,
     148,   149,   150,   151,   250,   251,   154,   170,   171,   172,
     256,   569,   570,   176,   177,   163,   245,   246,   166,   512,
     105,   257,   143,   108,   109,   110,  2249,   257,   910,   344,
     257,   261,   261,   325,   326,  1992,   121,   111,   112,   262,
     161,   333,   334,   536,   111,   112,   245,   246,   442,   170,
     171,   172,   545,   546,   257,   176,   177,   550,   261,   552,
     553,   554,   555,   556,   707,   111,   112,   266,   257,   562,
     245,   246,   258,   566,   567,   568,   569,   570,   571,   572,
     266,   574,   572,   576,   574,   245,   246,   245,   246,   245,
     246,   266,   635,   257,   637,   638,   245,   246,   257,   262,
     185,   245,   246,   257,   254,   255,   266,   261,   266,   602,
     266,   654,   261,   245,   246,   608,   190,   191,   105,   434,
      55,   108,   266,   190,   191,   257,   245,   246,   258,   261,
     673,   254,   255,   257,   121,   262,   266,   630,   631,   266,
     263,   262,   261,   148,   149,   108,   257,   110,   706,   154,
     708,   709,   710,   711,   712,   713,   699,   715,   716,   717,
     718,   763,   262,   721,   722,   723,   266,   262,  1287,   646,
     647,   266,   245,   246,   247,   248,   249,   250,   251,   573,
     257,   262,   259,   256,   123,   266,   679,   680,   681,   266,
     262,   684,   257,  1075,   266,   258,   739,   247,   248,   249,
     250,   251,   257,   266,   259,   262,   256,   261,   263,   266,
     257,   266,   705,   706,   707,   708,   709,   710,   711,   712,
     713,   257,   715,   716,   717,   718,   719,   257,   721,   722,
     723,   724,   725,   258,   724,   728,   110,   258,   783,   260,
     258,   266,   260,   801,   258,   266,   260,   740,   266,  1498,
     108,   258,   266,   260,   812,   258,   257,   260,   261,   266,
     753,   576,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   768,   262,   212,   257,   256,
     266,   774,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   790,   791,   257,
     262,   256,   262,   796,   266,   798,   266,     6,   801,   802,
     262,   257,     6,   259,   266,   630,   631,   810,   262,   812,
     254,   255,   266,   257,   262,   259,   720,  1209,   266,  1211,
     261,   254,   255,   268,   257,   262,   259,   939,   261,   266,
     254,   255,  1224,   257,  1593,   259,   262,     6,     7,   842,
     266,   844,   644,   645,  1603,   262,   262,   649,   262,   266,
     266,   257,   266,   262,   679,   680,   681,   266,   262,   684,
     305,  1253,   266,   262,   262,   262,   262,   266,   266,   266,
     266,   316,   257,   262,   262,   320,   879,   266,   266,  2153,
     262,   262,   245,   246,   266,   266,   889,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   728,   262,   108,   262,   256,   266,   912,
     266,   964,   262,   261,  2185,   819,   266,   262,   262,   261,
     257,   266,   266,  1315,  1316,   928,   262,   262,   262,   262,
     266,   266,   266,   266,   262,   262,  2210,   940,   266,   266,
     262,   262,   105,   768,   266,   266,   949,  1059,  1340,   262,
     262,   261,   261,   266,   266,  1347,  2227,   960,   257,   262,
     262,  1073,  1074,   266,   266,   790,     8,   258,   262,   260,
     261,   796,   266,   798,  1366,   262,   262,   262,  1090,   266,
     266,   266,   262,   262,   262,   262,   266,   266,   266,   266,
     108,   262,   262,   438,   439,   266,   266,   105,   262,   262,
     262,  1393,   266,   266,   266,   105,   262,   262,   261,   454,
     266,   266,   263,   108,   265,  1407,   258,   257,   260,   259,
     108,   257,  1414,   259,     4,     4,     6,     4,     4,     4,
     257,   257,   257,     6,  1102,     6,   259,   257,   259,     6,
       6,   265,   261,   261,     6,   257,     9,   257,   952,  1370,
     265,   257,   257,   261,   879,   257,   257,   257,   193,   193,
     193,   132,   261,   257,   889,  1068,   257,   257,   257,   193,
       4,   257,   257,  1076,   261,   257,   257,   261,   261,     6,
       6,  1084,   261,   261,   261,   257,   257,   257,     6,   257,
     257,   257,   257,     6,  1097,   259,     6,   259,   259,  1102,
    1729,  1730,   261,   928,     3,   261,   261,   261,   553,   261,
     259,   257,   257,  1225,  1226,   940,   193,   261,   257,   257,
     257,   566,     6,   568,  1192,  1193,   257,   257,    27,  1132,
    1133,   257,  1135,  1136,  1137,   960,  1139,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,   259,     6,  1151,   261,
       6,     8,     6,     8,   257,   261,     7,     6,     6,   261,
     261,    97,   261,    62,   262,   967,   258,     7,     6,   266,
     266,     6,   974,  1077,   258,   261,   978,   256,   261,   261,
     261,   261,    67,     8,     7,   263,     7,   257,  1191,  1192,
    1193,     6,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     258,     6,   261,  1216,   256,   114,     7,     6,   262,     7,
     262,     6,     6,   261,   258,   190,   262,   262,   260,  1232,
    1233,  1234,     6,   261,   263,     7,     6,   259,   257,     6,
     261,     6,     6,     6,     6,   258,     7,   146,   259,     7,
       7,     7,   151,   152,   153,  1323,     7,     7,     7,  1327,
       7,   160,     7,     7,     7,     7,     7,     7,  1336,     7,
    1338,     7,  1097,  1341,   261,  1596,     6,   258,   260,   262,
     266,   266,  1394,  1395,     7,  1288,   258,     7,   266,     4,
       6,   261,   266,   262,     7,   263,   143,   261,   197,     6,
    1287,   261,   263,  1306,   262,  1308,  1309,   262,   753,     7,
       7,     7,   263,   258,   213,  1318,   258,   266,   266,     9,
    1323,   258,   266,   263,  1327,   260,  1151,  1395,   193,  1131,
       7,   164,   265,  1336,   262,  1338,   261,     6,  1341,     6,
       6,    49,   263,    49,   261,   257,   257,   261,   263,    13,
      14,   257,   257,     7,  1357,   254,   263,     7,     7,   193,
     258,     7,   266,     7,     7,     6,   258,  1370,     7,   266,
       7,   270,   271,     7,     7,     7,     4,     6,   261,  2008,
     257,   120,     7,     6,   102,     7,     7,     7,     7,     7,
       7,     7,  1395,   261,     6,     6,     6,  1400,   108,  1402,
       7,     7,     6,     6,  1796,     7,     7,     4,  1233,  1234,
       6,   264,   258,     6,   266,     6,   266,  1420,   261,   261,
     261,     7,     6,   262,     6,     6,   257,   259,   257,  1432,
       6,   261,     6,  1436,   262,     6,   263,     6,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,  1604,  1605,     6,   118,   119,   120,   121,   260,   266,
     124,     6,     6,   136,     6,     6,     6,   912,   132,   133,
       6,     6,   136,   137,     6,   139,   140,     6,   142,     6,
       6,  1593,     6,  1804,     6,     6,     5,   258,     6,  1492,
    1493,  1494,   258,  1318,     6,     4,   160,  1500,  1501,  1502,
       6,   261,   261,     7,   949,     6,   261,     7,   261,   261,
       6,   259,     6,     6,  1418,  1518,  1420,     6,     6,   189,
       6,   185,   186,   187,   261,   258,  1529,   261,  1581,   261,
     261,   266,  1585,   432,  1537,   261,   261,   261,  1541,   266,
     262,     6,   261,     7,   443,   266,   263,   261,   257,  1552,
     261,  1554,     6,     6,   266,     6,     6,   262,   257,     4,
    1628,     7,   257,     6,     6,     6,   465,     6,   143,   106,
       6,     5,   261,   258,   266,  1400,     6,  1402,   261,   261,
       6,   480,   143,   143,     6,   266,     6,     6,     6,     6,
       6,   266,  1704,  1596,   266,   258,     6,     6,   262,     6,
     261,  1604,  1605,   261,   266,     6,     6,  1610,     6,     6,
       6,     5,     7,   261,   147,     6,   261,     6,     6,   261,
     258,   261,     6,  1068,     6,  1628,   261,     7,     6,   188,
     261,     6,   262,     7,     6,   262,  1639,   261,     6,  1084,
       6,  1644,     6,   258,     6,     6,     6,     6,   262,   262,
       6,   550,   261,   552,  1807,   554,   555,   556,   263,     6,
     258,     6,   262,   262,     6,     6,   261,   261,   191,   261,
     569,   570,  1576,   262,   262,   258,   261,   257,     6,     6,
       6,   143,   261,   261,     6,   262,     6,  1132,  1133,   261,
    1135,  1136,  1137,     6,  1139,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1772,   261,   258,  1775,     6,     6,
       6,   262,   262,  1716,     6,     6,  1541,     6,  1721,  1722,
       6,     6,     6,  2044,     6,  1527,     6,   261,     6,     6,
     261,   261,     6,     6,     6,  1639,     6,     6,  2166,  1406,
    1467,  1744,  1729,  1730,  1975,  1431,  1191,  1750,  1651,  1935,
       3,  1712,  1755,   652,   483,  1086,     3,     3,     3,   623,
    2004,  1764,  1573,     3,  1797,  1605,  1777,    -1,   801,  1772,
      -1,  1216,  1775,    -1,    -1,    -1,    -1,   676,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1232,    -1,    -1,
    1793,    -1,    -1,    -1,  1797,    -1,    -1,    -1,    -1,    -1,
      -1,  1804,    -1,  1806,  1807,    -1,   705,   706,   707,   708,
     709,   710,   711,   712,   713,    -1,   715,   716,   717,   718,
      -1,  1725,   721,   722,   723,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   731,    -1,    -1,   734,    -1,    -1,    -1,  1842,
      -1,    -1,    -1,  1288,    -1,    -1,    -1,    -1,   747,    -1,
      -1,    -1,    -1,    -1,  1656,    -1,  1859,    -1,    -1,    -1,
      -1,  1306,    -1,  1308,  1309,    -1,  1770,  1870,  1871,    -1,
      -1,    -1,    -1,  1777,  1778,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   782,    -1,   784,    -1,    -1,    -1,    -1,
      -1,    -1,  1895,    -1,  1798,    -1,  1721,  1722,    -1,    -1,
      -1,    -1,   801,    -1,  1907,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1357,   812,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1745,  1746,  1747,  1748,  1749,  1750,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1961,    -1,
      -1,    -1,    -1,    -1,  2017,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1976,    -1,  1420,    -1,    -1,  1981,    -1,
      -1,  1984,  1985,    -1,    -1,    -1,    -1,  1432,    -1,    -1,
      -1,  1436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2002,
      -1,    -1,  2005,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2016,    -1,    -1,    -1,  2020,    -1,    -1,
      -1,  2008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1937,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2044,    -1,    -1,    -1,  1870,  1871,  1492,  1493,  1494,
      -1,    -1,    -1,    -1,  2057,  1500,  1501,  1502,    -1,    -1,
      -1,  2114,    -1,    -1,   963,    -1,   965,   966,    -1,    -1,
      -1,    -1,    -1,  1518,    -1,    -1,  1980,    -1,    -1,    -1,
     979,    -1,    -1,  2086,  1529,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1537,    -1,    -1,    -1,    -1,    -1,    -1,  1924,
     999,  2154,    -1,    -1,    -1,    -1,    -1,  1552,    -1,  1554,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1020,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2138,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2156,  2157,  2158,  2159,  2160,  1057,  1984,
    1985,    -1,    -1,    -1,    -1,  1610,    -1,    -1,  2236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2005,    -1,    -1,    -1,    -1,    -1,    -1,  2255,  2256,    -1,
      -1,    -1,    -1,    -1,  1639,  2020,  2199,    -1,    -1,    -1,
    2268,    -1,    -1,  1102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2215,    -1,    -1,    -1,    -1,    -1,    -1,  2021,
    2022,  2023,  2024,  2025,    -1,    -1,  2130,    -1,    -1,    -1,
      -1,    -1,    -1,  2236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2249,    -1,    -1,    -1,
      -1,    -1,  2255,  2256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2268,    -1,    -1,    -1,    -1,
      -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2085,    -1,    -1,    -1,  2089,    -1,    -1,
      -1,    -1,    -1,  1192,  1193,    -1,    -1,    -1,    -1,  1744,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2138,    -1,    -1,    -1,    -1,    -1,  1764,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2156,  2157,  2158,  2159,  2160,    -1,    -1,  2140,    -1,
      -1,    -1,  2144,    -1,    -1,    -1,    -1,    -1,  1793,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1255,    -1,  2160,    -1,
      -1,  1806,    -1,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
    2215,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2205,  2206,    -1,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,  1859,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1323,    -1,    -1,    -1,  1327,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,  1338,
      -1,    -1,  1341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1895,    -1,  1351,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1395,    -1,    -1,    95,
      -1,    -1,    98,    -1,    -1,    -1,   102,    -1,   118,   105,
       8,    -1,   108,    -1,   110,    -1,  1961,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,  1976,    -1,    -1,    -1,    -1,   146,    -1,    -1,    -1,
     150,    -1,    -1,   139,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,   162,    -1,    -1,   165,    -1,  2002,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2016,   182,   183,   184,    -1,   186,   187,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,    -1,   198,   199,
     200,   201,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2057,   209,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,    -1,   225,
      -1,   227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2086,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,    -1,    -1,    -1,    -1,   261,    -1,   263,    -1,    -1,
      -1,   281,   282,   283,   284,   285,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,   301,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1604,  1605,    -1,   318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,   329,
      -1,    -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,  1628,
      -1,    -1,    -1,    -1,   344,   345,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,  2199,    -1,    -1,    -1,   256,   369,
     370,    -1,    -1,    -1,    -1,   375,    -1,   377,   378,    -1,
     380,    -1,    -1,    -1,   384,   385,   386,    -1,    -1,   389,
      -1,    -1,    -1,    -1,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    -1,    -1,  2249,    -1,   256,    -1,   258,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,
      -1,    -1,    -1,    -1,   434,   435,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,   452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   466,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1772,    -1,    -1,  1775,    -1,   488,    -1,
      -1,    -1,    -1,   493,    -1,    -1,    -1,   497,    -1,    -1,
      -1,  1790,    -1,  1792,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   511,   512,    -1,    -1,    -1,   516,    -1,  1807,    -1,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,    -1,   548,   549,
      -1,   551,    -1,  1842,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   561,    -1,    -1,   564,   565,    -1,    -1,    -1,    -1,
      -1,   571,    -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,    -1,   609,
     610,    -1,    -1,    -1,    -1,    -1,    -1,   617,   618,   619,
       6,    -1,    -1,    -1,    -1,   625,   626,   627,   628,    -1,
     630,   631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   649,
     650,   651,    -1,    -1,    -1,   655,   656,   657,   658,   659,
     660,   661,   662,   663,    -1,    -1,    -1,    -1,    -1,   669,
     670,    -1,   672,    -1,    -1,   675,    -1,    -1,    -1,   679,
     680,   681,   682,    -1,   684,   685,   686,   687,    -1,    -1,
      -1,    -1,   692,    -1,   694,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,   714,    -1,    -1,   256,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   728,    -1,
     143,    -1,    -1,    -1,    -1,   735,   736,    -1,   738,    -1,
      -1,   741,   742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,    -1,
     770,    -1,    -1,    -1,    -1,   775,   776,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     790,    -1,   792,   793,    -1,    -1,   796,    -1,   798,   799,
      -1,    -1,    -1,   803,    -1,   805,    -1,   807,    -1,  2098,
      13,    14,    -1,   813,    -1,    -1,    -1,   817,    -1,    -1,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
     840,    -1,   842,   256,   844,    -1,    -1,    -1,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,  2164,    -1,    -1,    -1,   879,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   889,
     890,   891,   892,    -1,    -1,    -1,    -1,  2186,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   206,    -1,   118,   119,   120,   121,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,   928,   132,
     133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,   142,
     940,    -1,    -1,    -1,    -1,    -1,    -1,  2236,   948,    -1,
      -1,    -1,   952,    -1,    -1,    -1,    -1,   160,    -1,    -1,
     960,    -1,    -1,    -1,    -1,    -1,  2255,  2256,   968,   969,
      -1,    -1,    -1,    -1,   974,    -1,    -1,    -1,    -1,  2268,
      -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,   282,
      -1,   991,   285,    -1,   994,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1019,
      -1,  1021,  1022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   344,    -1,    -1,    -1,    -1,     4,     5,     7,   262,
      -1,    -1,    -1,    -1,  1064,    -1,    -1,    -1,    -1,    -1,
      -1,  1071,    -1,    -1,    -1,    -1,    -1,   370,  1078,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1091,  1092,    -1,    -1,    -1,    -1,  1097,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,  1129,
      -1,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
       6,   434,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      98,  1151,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,    -1,    -1,  1167,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,  1177,  1178,  1179,
    1180,  1181,    -1,    -1,    -1,    -1,  1186,  1187,    -1,  1189,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1204,  1205,    -1,    -1,     6,    -1,
      -1,    -1,  1212,  1213,    -1,    -1,    -1,    -1,    -1,   512,
      -1,  1221,  1222,    -1,    -1,    -1,    -1,  1227,  1228,    -1,
      -1,    -1,    -1,  1233,  1234,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   536,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,   545,   546,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,   211,    -1,    -1,    -1,  1267,    -1,    -1,
      -1,    -1,    -1,   221,    -1,    -1,    -1,   225,   571,   227,
     228,    -1,    -1,   576,    -1,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,  1304,    -1,    -1,   256,    -1,   602,
     258,    -1,   260,   261,    -1,    -1,    -1,    -1,  1318,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1326,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,   631,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1348,  1349,
      -1,    -1,    -1,  1353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1364,    -1,    -1,  1367,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   679,   680,   681,     6,
     256,   684,    -1,    -1,    -1,    -1,  1396,    -1,    -1,  1399,
    1400,  1401,  1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1410,    -1,    -1,  1413,    -1,  1415,    -1,  1417,  1418,    -1,
       6,  1421,  1422,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   728,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   768,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,    -1,    -1,   790,   256,  1499,
      -1,    -1,    -1,   796,    -1,   798,    -1,    -1,    -1,  1509,
    1510,  1511,    -1,    -1,    -1,    -1,    -1,    -1,  1518,    -1,
    1520,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1541,    -1,    -1,    -1,    -1,    -1,  1547,  1548,   842,
      -1,   844,    -1,    -1,    -1,    -1,    -1,    -1,  1558,  1559,
    1560,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1568,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1579,
      -1,    -1,    -1,    -1,    -1,    -1,   879,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   889,    -1,    -1,    -1,
    1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1608,  1609,
      -1,     6,    -1,    -1,    -1,    -1,    -1,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   928,    -1,    -1,    -1,   256,
     456,    -1,    -1,    -1,  1644,    -1,    -1,   940,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,   960,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1685,  1686,  1687,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,
      -1,  1701,  1702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,
      -1,  1721,  1722,  1723,    -1,  1725,    -1,    -1,    -1,    -1,
      -1,  1731,  1732,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
    1750,    -1,    -1,    -1,    -1,  1755,  1756,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,    -1,    -1,  1773,    -1,    -1,    -1,  1777,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1786,  1787,    -1,  1789,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   613,    -1,  1799,
      -1,    -1,    -1,    -1,  1097,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1813,    -1,    -1,    -1,    -1,  1818,  1819,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1832,    -1,    -1,  1835,  1836,    -1,  1838,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,  1151,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1870,  1871,    -1,    -1,    -1,    -1,    -1,  1877,  1878,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1889,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1898,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1907,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1920,  1921,    -1,    -1,  1924,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1233,  1234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1958,  1959,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,  1979,
      -1,    -1,    -1,   256,  1984,  1985,  1986,    -1,    -1,    -1,
      -1,  1991,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2005,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2020,    -1,    -1,    -1,    -1,  1318,    -1,    -1,    -1,  2029,
      -1,    -1,    -1,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   858,   859,    -1,   861,   862,   863,   864,    -1,
     866,   867,   868,   869,  2054,    -1,    -1,    -1,    -1,    26,
    2060,    28,    -1,  2063,    -1,    -1,   882,    -1,   884,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   895,
      -1,    -1,    -1,    -1,    -1,    -1,   902,   903,    -1,    -1,
      -1,    -1,    -1,    -1,  2094,   911,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1400,    -1,  1402,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2120,  2121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2135,  2136,    -1,  2138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2151,    -1,    -1,    -1,    -1,  2156,  2157,  2158,  2159,
    2160,    -1,    -1,    -1,    -1,    -1,  2166,    -1,    -1,    -1,
    2170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2197,    -1,    -1,
      -1,    -1,  2202,  2203,    -1,    -1,    -1,    -1,    -1,    -1,
    1026,  1027,  1028,    -1,    -1,  2215,  1032,  1033,    -1,    -1,
    1036,  1037,  1038,  1039,    -1,  1041,    -1,    -1,    -1,    -1,
    1046,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,  2242,  2243,    -1,    -1,    -1,    -1,  1541,    -1,
      -1,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,   274,     3,     4,
       5,    -1,  1128,    -1,  1130,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,  1644,     6,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   391,   392,   393,    -1,  1721,  1722,
     397,   398,   399,   400,   401,   402,   403,    -1,   405,    -1,
      -1,    -1,    -1,   410,   411,     6,    -1,   414,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,    -1,    -1,
      -1,   428,  1755,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,     6,   227,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,
    1376,     6,   257,    -1,    -1,    -1,   261,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1870,  1871,    -1,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,     6,    -1,
      -1,    -1,   256,  1419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1907,    -1,    -1,   584,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1924,    -1,    -1,  1450,  1451,  1452,  1453,  1454,  1455,
    1456,    -1,    -1,    -1,    -1,  1461,  1462,    -1,    -1,    -1,
      -1,    -1,  1468,    -1,  1470,    -1,    -1,    -1,  1474,    -1,
      -1,  1477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1488,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,  1984,  1985,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2005,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2020,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,  1564,    -1,
    1566,   256,    -1,    -1,  1570,    -1,  1572,    -1,    -1,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,  1604,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,    -1,  2138,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2156,  2157,  2158,  2159,  2160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,  1703,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,  2215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,   906,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,   939,    -1,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   117,    -1,  1809,    -1,   121,  1812,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,   134,   135,
      -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,    -1,   154,   155,
     156,   157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,
     166,    -1,    -1,    -1,  1860,  1861,    -1,  1863,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,   213,    -1,    -1,
      -1,    -1,   218,   219,   220,    -1,   222,   223,   224,     6,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1928,  1929,    -1,    -1,    -1,    -1,    -1,   245,
     246,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,   261,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1122,    -1,    -1,    -1,    -1,
      -1,  1977,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
    1217,    -1,    -1,    93,    94,    95,    96,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    -1,   134,   135,    -1,   137,    -1,   139,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,    -1,   154,   155,   156,   157,   158,   159,
      -1,    -1,    -1,   163,    -1,    -1,   166,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,    -1,  2224,    -1,
    1377,  1378,   252,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,   261,    -1,    -1,   264,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,  1472,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,  1481,    -1,    -1,    -1,    93,    94,
      95,    96,    -1,    98,    -1,    -1,    -1,   102,    -1,    -1,
     105,    -1,    -1,   108,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,   134,
     135,    -1,   137,    -1,   139,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,    -1,   163,    -1,
      -1,   166,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
       6,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,   218,   219,   220,   221,   222,   223,   224,
     225,    -1,   227,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,    -1,    -1,    -1,    -1,  1643,   252,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,
     220,   221,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,    -1,    -1,    -1,
      -1,    -1,   252,    -1,   254,   255,    -1,   257,    -1,   259,
       3,     4,    -1,   263,   264,     8,    -1,    10,    11,    12,
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
      -1,    -1,    -1,    -1,   257,     3,     4,     5,    -1,   262,
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
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,   261,   262,
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
      -1,    -1,    -1,    -1,   257,     3,     4,    -1,    -1,   262,
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
      -1,    -1,    -1,   121,    -1,     4,     5,    -1,    -1,    -1,
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
       3,     4,    -1,   261,    -1,    -1,   264,    10,    11,    12,
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
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
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
      -1,   225,    -1,   227,    -1,    93,    94,    -1,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
     108,    -1,   110,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,   134,   135,    -1,   137,
      -1,   139,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,    -1,   154,   155,   156,   157,
     158,   159,    -1,    -1,    -1,   163,    -1,    -1,   166,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,    -1,    -1,    -1,
      -1,   256,    -1,   258,    -1,   260,    -1,    -1,    -1,    -1,
      -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,    -1,    -1,    -1,   212,   213,    -1,    -1,    -1,    -1,
     218,   219,   220,    -1,   222,   223,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,
       3,     4,    -1,   261,    -1,     8,   264,    10,    11,    12,
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
     250,   251,    -1,    -1,    -1,    -1,   256,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,    -1,   212,
     213,    -1,    -1,    -1,    -1,   218,   219,   220,    -1,   222,
     223,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
       3,     4,    -1,    -1,   257,     8,    -1,    10,    11,    12,
      -1,   264,    15,    16,    17,    18,    19,    20,    21,    22,
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
       3,     4,    -1,    -1,   257,    -1,    -1,    10,    11,    12,
      -1,   264,    15,    16,    17,    18,    19,    20,    21,    22,
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
       3,     4,     5,    -1,   257,    -1,    -1,    10,    11,    12,
      -1,   264,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    -1,    98,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,   227,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,   261,    -1,
      -1,   264,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,
      -1,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
     257,     3,     4,     5,   261,    -1,    -1,   264,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    -1,    98,     3,     4,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,    -1,    -1,    -1,    -1,    -1,
     252,    -1,     3,     4,    -1,   257,    -1,    -1,    -1,    10,
      11,    12,   264,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,    58,    59,    60,
      61,    -1,   218,   219,   220,    66,   222,   223,   224,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,   245,
     246,    -1,    93,    94,    -1,    96,   252,    -1,    -1,    -1,
      -1,   257,     3,     4,    -1,   261,    -1,     8,   264,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,   212,    -1,    -1,    -1,    -1,    -1,   218,   219,   220,
      -1,   222,   223,   224,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,   257,     3,     4,    -1,
     261,    -1,    -1,   264,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,   212,    58,    59,    60,    61,    -1,   218,   219,   220,
      66,   222,   223,   224,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,    93,    94,    -1,
      96,   252,     3,     4,    -1,     6,   257,    -1,    -1,    10,
      11,    12,    -1,   264,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   218,   219,   220,    -1,   222,   223,   224,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,    -1,    -1,    -1,    -1,    -1,   252,     3,     4,    -1,
       6,   257,   258,    -1,    10,    11,    12,    -1,   264,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,   212,    58,    59,    60,    61,    -1,   218,   219,   220,
      66,   222,   223,   224,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,    93,    94,    -1,
      96,   252,     3,     4,    -1,     6,   257,    -1,    -1,    10,
      11,    12,    -1,   264,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   218,   219,   220,    -1,   222,   223,   224,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,    -1,    -1,    -1,    -1,    -1,   252,     3,     4,    -1,
      -1,   257,    -1,    -1,    10,    11,    12,    -1,   264,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,   212,    58,    59,    60,    61,    -1,   218,   219,   220,
      66,   222,   223,   224,    -1,    -1,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,    93,    94,    -1,
      96,   252,     3,     4,    -1,    -1,   257,    -1,    -1,    10,
      11,    12,    -1,   264,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   218,   219,   220,    -1,   222,   223,   224,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,    -1,    -1,    -1,    -1,    -1,   252,     3,     4,    -1,
      -1,   257,   258,    -1,    10,    11,    12,    -1,   264,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,
      -1,   212,    58,    59,    60,    61,    -1,   218,   219,   220,
      66,   222,   223,   224,     4,     5,    -1,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,    93,    94,    -1,
      96,   252,    -1,    -1,    -1,    -1,   257,   258,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    13,    14,    -1,    79,
      -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,   108,    -1,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   208,    -1,    -1,    -1,   212,    -1,    -1,    -1,
      -1,    -1,   218,   219,   220,    -1,   222,   223,   224,    -1,
      -1,    -1,   228,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    -1,   245,
     246,   118,   119,   120,   121,    -1,   252,   124,    13,    14,
      -1,   257,    -1,    -1,    -1,   132,   133,    -1,   264,   136,
     137,    -1,   139,   140,    -1,   142,    -1,    -1,    -1,   209,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   221,    -1,   160,    -1,   225,    -1,   227,   228,    -1,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   185,   186,
     187,    -1,   256,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,   261,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,    -1,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     185,   186,   187,   118,   119,   120,   121,   262,    -1,   124,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,   136,   137,    -1,   139,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,     0,
       1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   186,   187,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    67,    68,    69,    -1,
     256,    -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,
     266,    -1,    -1,    -1,    85,    86,    87,    88,    89,    -1,
      91,    92,    -1,    94,    -1,    -1,    -1,   262,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,    -1,   117,   118,   119,   120,
     121,   122,    -1,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,    -1,
      -1,    -1,   173,   174,   175,    -1,    -1,    -1,   179,    -1,
      -1,    -1,    -1,   184,   185,   186,   187,    -1,    -1,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,     4,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,   226,    -1,   228,   229,    -1,
      -1,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      46,    47,    48,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    -1,    91,    92,    -1,    94,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    -1,
      -1,   117,   118,   119,   120,   121,   122,    -1,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,   144,   145,
     146,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,    -1,    -1,    -1,   173,   174,   175,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,   185,
     186,   187,     4,     5,   190,    -1,   192,    -1,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,    -1,   228,   229,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    13,    14,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    98,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,   108,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,    -1,    -1,   136,   137,    -1,
     139,   140,    -1,   142,    -1,    -1,    -1,   146,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,
      -1,   160,    -1,    -1,    -1,   164,    -1,    -1,    -1,   221,
      -1,    -1,    -1,   225,    -1,   227,   228,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
     133,    -1,    -1,   136,   137,    -1,   139,   140,    -1,   142,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,    -1,
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
     256,    -1,    -1,    -1,    -1,    -1,   262,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,   261,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,   261,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,
     261,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,    -1,
      -1,    -1,    -1,   256,    -1,   258,    -1,   260,   234,   235,
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
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256,    -1,   258,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,    -1,    -1,    -1,    -1,   256,    -1,   258,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,    -1,    -1,    -1,    -1,
     256
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
     257,     6,   261,     6,   261,   261,     6,     6,   259,   259,
       4,   357,   380,   257,   259,   291,   102,   105,   108,   110,
     315,   291,   257,   257,   257,     4,   257,   257,   257,     4,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   261,   123,   108,     6,     6,   261,   102,   105,   108,
     121,   318,   110,   257,     3,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    58,
      59,    60,    61,    66,    67,    76,    77,    78,    82,    83,
      84,    93,    96,   102,   105,   108,   110,   121,   132,   137,
     139,   142,   208,   212,   213,   218,   219,   220,   222,   223,
     224,   245,   246,   252,   257,   261,   264,   315,   316,   319,
     330,   337,   339,   350,   351,   355,   357,   363,   365,   380,
     257,   261,   261,   108,   108,   132,   105,   108,   110,   315,
     105,   108,   109,   110,   121,   185,   316,   105,   108,   257,
     105,   164,   190,   206,   207,   261,   245,   246,   257,   261,
     360,   361,   360,   261,   261,   360,     4,   102,   106,   112,
     113,   115,   116,   136,   261,   257,   108,   110,   108,   105,
       4,    94,   201,   261,   380,     4,     6,   102,   105,   108,
     105,   108,   121,   317,   108,     4,     4,     4,     5,   257,
     261,   363,   364,     4,   108,   257,   108,   257,   257,     4,
     261,   367,   380,     4,   257,   257,   257,     6,     6,   259,
       5,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      62,    63,    64,    65,    70,    71,    72,    73,    79,    81,
      95,    98,   209,   210,   211,   221,   225,   227,   371,   380,
     257,     4,   371,     5,   261,     5,   261,   315,    32,   246,
     350,   380,   259,     6,   261,   257,   261,     6,   257,   261,
       6,   265,     7,   139,   201,   230,   231,   232,   233,   254,
     255,   257,   259,   263,   289,   290,   291,   315,   350,   370,
     371,   380,     4,   319,   320,   321,   261,     6,   350,   370,
     371,   380,   370,   370,   350,   370,   377,   378,   380,   350,
     321,   350,   296,   300,   257,   359,     9,   371,   257,   380,
     350,   350,   350,   257,   350,   350,   350,   257,   350,   350,
     350,   350,   350,   350,   350,   370,   350,   350,   350,   350,
     364,   257,   246,   350,   365,   366,   261,   364,   363,   370,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   257,   259,   291,   291,   291,
     291,   291,   291,   257,   291,   291,   257,   315,   316,   316,
     316,   291,   291,     5,   261,   261,   132,   315,   315,   257,
     291,   291,   257,   257,   257,   350,   261,   350,   365,   350,
     350,   262,   366,   357,   380,   193,     5,   261,     8,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   256,     9,   257,
     259,   263,   290,   291,   350,   366,   366,   257,   257,   257,
     363,   364,   364,   364,   314,   257,   261,   257,   257,   363,
     261,   261,   350,     4,   363,   261,   367,   261,   261,   360,
     360,   360,   350,   350,   245,   246,   261,   261,   360,   245,
     246,   257,   321,   360,   261,   257,   261,   257,   257,   257,
     257,   257,   257,   257,   366,   350,   364,   364,   364,   257,
     261,     4,   259,   261,     6,   259,   321,     6,     6,   261,
     261,   261,   261,   364,   261,   259,   259,   259,   350,     8,
       6,     6,   257,   350,   257,   350,   350,   263,   350,   261,
     193,   350,   350,   350,   350,   291,   291,   291,   257,   257,
     257,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   257,   257,   291,   257,   259,     6,     6,   261,     6,
       8,   321,     6,     8,   321,   257,   291,   350,   247,   261,
       9,   257,   259,   263,   370,   366,   350,   321,   363,   363,
     261,   371,   315,     7,   350,   350,     4,    36,    37,   111,
     112,   190,   191,   293,   363,     6,   258,   260,   261,   292,
     261,     6,   261,     6,     9,   257,   259,   263,   380,   262,
     132,   137,   139,   140,   142,   313,   315,   350,     6,   258,
     266,     9,   257,   259,   263,   258,   266,   258,   266,   266,
     258,   266,     9,   257,   263,   266,   262,   266,   260,   266,
     295,   260,   295,    97,   358,   356,   380,   266,   350,   266,
     258,   258,   258,   350,   258,   258,   258,   350,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   262,
       7,   350,   247,   262,   266,   350,     6,     6,   258,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   365,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   365,   365,   380,   261,
     350,   350,   370,   350,   370,   363,   370,   370,   377,   261,
     261,   261,   261,   350,   292,   380,     8,   350,   350,   364,
     363,   370,   370,   365,   357,   371,   357,   366,   258,   262,
     263,   291,    67,     8,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   261,   350,
     365,   350,   350,   350,   350,   350,   380,   350,   350,   293,
     261,   292,   258,   262,   262,   350,   350,   350,     7,     7,
     343,   343,   257,   350,   350,   350,   350,     6,   366,   366,
     261,   258,     6,   321,   261,   321,   321,   266,   266,   266,
     360,   360,   320,   320,   266,   350,   262,   334,   266,   321,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   262,
     258,     7,   344,     6,     7,   350,   350,     6,   350,   321,
     350,   262,   366,   366,   366,   350,     6,   366,   350,   350,
     350,   258,   262,   350,   258,   350,   258,   258,   190,   266,
     321,   261,     8,   258,   258,   260,   377,   370,   377,   370,
     370,   370,   370,   370,   370,   350,   370,   370,   370,   370,
     264,   373,   380,   371,   370,   370,   370,   357,   380,   366,
     262,   262,   262,   262,   350,   350,   350,   321,   380,   293,
     260,   262,   258,   146,   164,   338,   258,   262,   266,   350,
       6,   261,   363,   258,   260,   263,     7,     7,   289,   290,
       6,   366,     7,   233,   289,   350,   274,   380,   350,   350,
     293,   259,   257,   132,   315,   316,   315,   261,   262,     6,
     240,   241,   271,   366,   380,   350,   350,   293,     6,   366,
       6,   366,   350,     6,   370,   378,   380,   258,   293,   350,
     350,     6,   380,     6,   370,   350,   258,   259,   350,   266,
     371,     7,     7,     7,   258,     7,     7,     7,   258,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   350,
     258,   261,   350,   365,   262,     6,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   266,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   266,   266,   266,
     266,   266,   258,   260,   260,   366,   266,   266,   292,   266,
     292,   266,   266,   266,   258,   366,   350,   350,   350,   352,
     292,   262,   262,   262,   266,   266,   292,   292,   258,   263,
     258,   263,   266,   291,   353,   262,     7,   293,   292,   363,
     262,     8,     8,   366,   263,   258,   260,   257,   259,   290,
     291,   366,     7,   261,   261,   258,   258,   258,   350,   363,
       4,   342,     6,   309,   350,   371,   258,   262,   258,   258,
     262,   262,   366,   263,   262,   321,   262,   262,   360,   350,
     350,   262,   262,   350,   360,   143,   143,   161,   170,   171,
     172,   176,   177,   335,   336,   360,   262,   331,   258,   262,
     258,   258,   258,   258,   258,   258,   258,   261,     7,   350,
       6,   350,   258,   262,   260,   262,   260,   262,   262,   262,
     262,   262,   260,   260,   266,   258,     7,   258,     7,     7,
     263,   350,   262,   350,   350,     7,   263,   292,   266,   292,
     292,   258,   258,   266,   292,   292,   266,   266,   292,   292,
     292,   292,   350,   292,     9,   372,   266,   258,   266,   292,
     263,   266,   354,   260,   262,   258,   262,   263,   257,   259,
     265,   193,     7,   164,     6,   350,   262,   261,     6,   363,
     262,   350,     6,     7,   289,   290,   263,   289,   290,   293,
     261,   368,   380,   371,   350,     6,   262,    49,    49,   363,
     262,     4,   180,   181,   182,   183,   262,   277,   281,   284,
     286,   287,   329,   263,   258,   260,   257,   350,   350,   257,
     261,   257,   261,     8,   366,   370,   258,   263,   258,   260,
     257,   258,   258,   266,   263,   257,   262,   266,     7,   291,
       4,    36,    37,   303,   304,   305,   292,   350,   292,   360,
     363,   363,     7,   363,   363,   363,     7,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,     6,     7,   366,
     350,   350,   350,   350,   350,   350,   262,   350,   350,   350,
     363,   370,   370,   262,   262,   262,   262,   266,   302,   350,
     350,   293,   293,   350,   350,   258,   363,   291,   350,   350,
     262,   293,   290,   263,   290,   350,   350,   292,   262,   363,
     366,   366,     7,     7,     7,   143,   341,     6,   258,   266,
       7,     7,     7,     7,     7,   262,     4,   293,   262,   266,
     266,   266,   262,   262,   120,     4,     6,   350,   261,     6,
     257,     6,   178,     6,   178,   262,   336,   266,   335,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   320,   363,
       6,   261,   102,     6,     6,     6,   108,     7,     7,     6,
       6,   350,     7,   363,     7,   363,   363,     4,   266,     8,
       8,   258,   293,   293,   366,   370,   350,   370,   264,   266,
     306,   370,   370,   293,   370,   258,   266,     6,   293,   261,
     315,   261,     6,   350,     6,   261,   363,   262,   262,   350,
       6,   190,   191,   293,   350,     6,     7,   367,   369,     6,
     259,     6,     6,   292,   291,   291,     6,   278,   257,   257,
     261,   288,     6,   293,   263,   370,   350,   260,   258,   350,
       8,   366,   350,   366,   262,   262,     6,     6,   271,   293,
     263,   350,     6,     6,   350,   293,   258,     6,   350,   261,
     350,   371,   292,    49,   261,   363,   371,   374,   350,   350,
     260,   266,     6,   258,     6,     6,   136,   311,   311,   363,
       6,     6,     6,   363,   143,   193,   310,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   262,   292,   292,
     292,   292,   292,   292,   292,   266,   266,   266,   258,   292,
     292,   304,   292,   258,   292,   258,   291,   353,   292,     6,
     292,   257,   259,   291,   293,   258,   260,   292,     6,   262,
     262,   363,   363,   363,     4,     6,   289,   350,   363,   363,
     363,   261,   261,     7,     6,     7,   350,   350,   350,   261,
     261,   261,   259,     6,   350,   363,   350,     6,     6,   350,
     360,   262,     5,   363,   261,   261,   261,   261,   261,   261,
     261,   363,   262,     6,   366,   261,   261,   350,   350,   260,
     363,     6,   363,     6,   189,   350,   350,   350,     6,     6,
       7,   292,   266,   266,   292,   266,   350,     4,   205,   307,
     308,   292,   258,   292,   354,   371,   257,   259,   350,   261,
     321,     6,   321,   266,     6,     6,   263,     7,     7,   289,
     290,     6,   367,   262,   266,   350,   289,   261,   292,   375,
     376,   377,   375,   257,   350,   350,   362,   363,   261,   257,
       4,     6,   258,     6,   258,   262,   262,   258,   262,     6,
       6,   370,   257,     4,   258,   266,   257,   262,   266,   363,
     371,     7,   291,   301,   350,   365,   305,     6,   360,     6,
       6,     6,   143,   312,   102,   121,   106,     6,     5,   261,
     350,   350,   350,   350,   258,   353,   350,   350,   292,   290,
     261,   261,     6,   310,     6,   350,   363,   143,   143,     4,
       6,   366,   366,   350,   350,   371,   262,   258,   262,   266,
     320,   320,   350,   350,   262,   266,   258,   262,   266,     6,
       6,   362,   360,   360,   360,   360,   360,   246,   360,     6,
     262,   366,   350,     6,     6,     6,     6,     6,   363,   262,
     266,     8,   262,   258,   261,   350,   371,   370,   350,   370,
     350,   371,   374,   376,   371,   266,   258,   266,   262,   350,
     338,   338,   363,   293,   368,   371,   350,     6,     6,   367,
     260,   363,   377,     6,   292,   292,   275,   350,   266,   266,
     262,   266,   276,   350,   350,     6,     6,     6,     6,   350,
     350,   258,     6,   350,   297,   299,   261,   376,   262,   266,
       7,     7,   147,     6,   261,   261,   261,     5,   362,   292,
     292,   266,   292,   258,   258,   260,   366,   366,     6,     6,
     350,   350,   261,   262,   262,   261,     6,     6,   261,   350,
     262,   262,   262,   260,     6,   363,     7,   261,   350,   262,
     266,   266,   266,   266,   266,   266,     6,   262,   262,   188,
     350,   350,   366,     6,     6,   258,   292,   292,   308,   371,
     262,   262,   262,   262,     7,     6,     6,     6,   263,     6,
     262,     6,     6,   258,   266,   350,   350,   261,   363,   262,
     266,   258,   258,   266,   262,   302,   306,   363,   292,   350,
     371,   380,   366,   366,   350,     6,   262,   350,   353,   262,
     262,     6,     6,   362,   148,   149,   154,   345,   148,   149,
     345,   366,   320,   262,   266,     6,   262,   363,   321,   262,
       6,   366,   360,   360,   360,   360,   360,     6,   350,   262,
     262,   262,   258,     6,   261,     6,   367,   191,   279,   350,
     266,   266,   362,     6,   350,   350,     6,   262,   262,   298,
       7,   257,   262,   262,   262,   261,   266,   258,   261,   262,
     261,   360,   363,     6,   261,   360,     6,   262,   262,   350,
       6,   143,   262,   332,   261,   262,   266,   266,   266,   266,
     266,     6,     6,     6,   321,     6,   261,   350,   350,   262,
     266,   302,   371,   258,   350,   350,   366,     6,   360,     6,
     360,     6,     6,   262,   350,   335,   321,     6,   366,   366,
     366,   366,   360,   366,   338,   276,   258,   266,     6,   261,
     350,   262,   266,   266,   262,   266,   266,     6,   262,   262,
     333,   262,   262,   262,   262,   266,   262,   262,   262,   282,
     350,   362,   262,   350,   350,   360,   360,   335,     6,     6,
       6,     6,   366,     6,     6,     6,   261,   258,   262,     6,
     262,   292,   266,   266,   262,   262,   280,   370,   285,   261,
       6,   350,   350,     6,   262,   266,   261,   362,   262,   262,
       6,   370,   283,   370,   262,     6,     6,   262,   266,     6,
       6,   370
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
#line 3652 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals!
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 289:
#line 3660 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 290:
#line 3664 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 291:
#line 3668 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 292:
#line 3672 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 293:
#line 3679 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 294:
#line 3683 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 295:
#line 3687 "Gmsh.y"
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
#line 3699 "Gmsh.y"
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
#line 3709 "Gmsh.y"
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
#line 3772 "Gmsh.y"
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

  case 299:
#line 3788 "Gmsh.y"
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

  case 300:
#line 3805 "Gmsh.y"
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

  case 301:
#line 3822 "Gmsh.y"
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

  case 302:
#line 3844 "Gmsh.y"
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

  case 303:
#line 3866 "Gmsh.y"
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

  case 304:
#line 3901 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 305:
#line 3909 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 306:
#line 3917 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 307:
#line 3923 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 308:
#line 3930 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 309:
#line 3937 "Gmsh.y"
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

  case 310:
#line 3957 "Gmsh.y"
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

  case 311:
#line 3983 "Gmsh.y"
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

  case 312:
#line 3995 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 313:
#line 4006 "Gmsh.y"
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

  case 314:
#line 4024 "Gmsh.y"
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

  case 315:
#line 4042 "Gmsh.y"
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

  case 316:
#line 4060 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4066 "Gmsh.y"
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

  case 318:
#line 4084 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4090 "Gmsh.y"
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

  case 320:
#line 4110 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4116 "Gmsh.y"
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

  case 322:
#line 4134 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 323:
#line 4140 "Gmsh.y"
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

  case 324:
#line 4157 "Gmsh.y"
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

  case 325:
#line 4173 "Gmsh.y"
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

  case 326:
#line 4190 "Gmsh.y"
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

  case 327:
#line 4208 "Gmsh.y"
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

  case 328:
#line 4231 "Gmsh.y"
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

  case 329:
#line 4258 "Gmsh.y"
    {
    ;}
    break;

  case 330:
#line 4261 "Gmsh.y"
    {
    ;}
    break;

  case 331:
#line 4267 "Gmsh.y"
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

  case 332:
#line 4279 "Gmsh.y"
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

  case 333:
#line 4299 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 334:
#line 4303 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 335:
#line 4307 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 336:
#line 4311 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 337:
#line 4315 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 338:
#line 4319 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 339:
#line 4323 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 340:
#line 4327 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 341:
#line 4336 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 342:
#line 4348 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 343:
#line 4349 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 344:
#line 4350 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 345:
#line 4351 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 346:
#line 4352 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 347:
#line 4356 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 348:
#line 4357 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 349:
#line 4358 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 350:
#line 4359 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 351:
#line 4360 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 352:
#line 4365 "Gmsh.y"
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

  case 353:
#line 4388 "Gmsh.y"
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

  case 354:
#line 4408 "Gmsh.y"
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

  case 355:
#line 4429 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 356:
#line 4433 "Gmsh.y"
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

  case 357:
#line 4448 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 358:
#line 4452 "Gmsh.y"
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

  case 359:
#line 4468 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 360:
#line 4472 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 361:
#line 4477 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 362:
#line 4481 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 363:
#line 4487 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 364:
#line 4491 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 365:
#line 4498 "Gmsh.y"
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

  case 366:
#line 4520 "Gmsh.y"
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

  case 367:
#line 4561 "Gmsh.y"
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

  case 368:
#line 4605 "Gmsh.y"
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

  case 369:
#line 4644 "Gmsh.y"
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

  case 370:
#line 4669 "Gmsh.y"
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

  case 371:
#line 4682 "Gmsh.y"
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

  case 372:
#line 4693 "Gmsh.y"
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

  case 373:
#line 4710 "Gmsh.y"
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

  case 374:
#line 4727 "Gmsh.y"
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

  case 375:
#line 4757 "Gmsh.y"
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

  case 376:
#line 4783 "Gmsh.y"
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

  case 377:
#line 4810 "Gmsh.y"
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

  case 378:
#line 4842 "Gmsh.y"
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

  case 379:
#line 4869 "Gmsh.y"
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

  case 380:
#line 4895 "Gmsh.y"
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

  case 381:
#line 4921 "Gmsh.y"
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

  case 382:
#line 4947 "Gmsh.y"
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

  case 383:
#line 4973 "Gmsh.y"
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

  case 384:
#line 4994 "Gmsh.y"
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

  case 385:
#line 5005 "Gmsh.y"
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

  case 386:
#line 5053 "Gmsh.y"
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

  case 387:
#line 5107 "Gmsh.y"
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

  case 388:
#line 5122 "Gmsh.y"
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

  case 389:
#line 5134 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 390:
#line 5145 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 391:
#line 5152 "Gmsh.y"
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

  case 392:
#line 5167 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 393:
#line 5180 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 394:
#line 5181 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 395:
#line 5182 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 396:
#line 5187 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 397:
#line 5193 "Gmsh.y"
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

  case 398:
#line 5205 "Gmsh.y"
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

  case 399:
#line 5223 "Gmsh.y"
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

  case 400:
#line 5250 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 401:
#line 5251 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 402:
#line 5252 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 403:
#line 5253 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 404:
#line 5254 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 405:
#line 5255 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 406:
#line 5256 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5257 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 408:
#line 5259 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 409:
#line 5265 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 410:
#line 5266 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 411:
#line 5267 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 412:
#line 5268 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 413:
#line 5269 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 414:
#line 5270 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 415:
#line 5271 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5272 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5273 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5274 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5275 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 420:
#line 5276 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 421:
#line 5277 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 422:
#line 5278 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 423:
#line 5279 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 424:
#line 5280 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 425:
#line 5281 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5282 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 427:
#line 5283 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5284 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5285 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5286 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5287 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5288 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 433:
#line 5289 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5290 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 435:
#line 5291 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5292 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5293 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5294 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5295 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 440:
#line 5296 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 441:
#line 5297 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 442:
#line 5298 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 443:
#line 5299 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5300 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5301 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5302 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 447:
#line 5303 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 448:
#line 5304 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 449:
#line 5313 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 450:
#line 5314 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 451:
#line 5315 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 452:
#line 5316 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 453:
#line 5317 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 454:
#line 5318 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 455:
#line 5319 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 456:
#line 5320 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 457:
#line 5321 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 458:
#line 5322 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 459:
#line 5323 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 460:
#line 5328 "Gmsh.y"
    { init_options(); ;}
    break;

  case 461:
#line 5330 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 462:
#line 5336 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 463:
#line 5340 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 464:
#line 5345 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 465:
#line 5350 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 466:
#line 5355 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 467:
#line 5360 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 468:
#line 5364 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 469:
#line 5368 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 470:
#line 5372 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 471:
#line 5376 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 472:
#line 5380 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 473:
#line 5384 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 474:
#line 5388 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 475:
#line 5394 "Gmsh.y"
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

  case 476:
#line 5409 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 477:
#line 5413 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 478:
#line 5419 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 479:
#line 5424 "Gmsh.y"
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

  case 480:
#line 5443 "Gmsh.y"
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
#line 5463 "Gmsh.y"
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

  case 482:
#line 5484 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 483:
#line 5488 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 484:
#line 5492 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 485:
#line 5496 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 486:
#line 5500 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 487:
#line 5504 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 488:
#line 5508 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 489:
#line 5513 "Gmsh.y"
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

  case 490:
#line 5523 "Gmsh.y"
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

  case 491:
#line 5533 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 492:
#line 5538 "Gmsh.y"
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

  case 493:
#line 5549 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 494:
#line 5558 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 495:
#line 5563 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 496:
#line 5568 "Gmsh.y"
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

  case 497:
#line 5595 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 498:
#line 5597 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 499:
#line 5602 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 500:
#line 5604 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 501:
#line 5609 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 502:
#line 5616 "Gmsh.y"
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

  case 503:
#line 5632 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 504:
#line 5634 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 505:
#line 5639 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 506:
#line 5641 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 507:
#line 5646 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 508:
#line 5648 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 509:
#line 5653 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 510:
#line 5657 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 511:
#line 5661 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 512:
#line 5665 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 513:
#line 5669 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 514:
#line 5676 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 515:
#line 5680 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 516:
#line 5684 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 517:
#line 5688 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 518:
#line 5695 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 519:
#line 5700 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 520:
#line 5707 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 521:
#line 5712 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 522:
#line 5716 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 523:
#line 5721 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 524:
#line 5725 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 525:
#line 5733 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 526:
#line 5744 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 527:
#line 5748 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 528:
#line 5752 "Gmsh.y"
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

  case 529:
#line 5766 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 530:
#line 5774 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 531:
#line 5782 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 532:
#line 5789 "Gmsh.y"
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

  case 533:
#line 5799 "Gmsh.y"
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

  case 534:
#line 5822 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 535:
#line 5827 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 536:
#line 5833 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 537:
#line 5838 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 538:
#line 5844 "Gmsh.y"
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

  case 539:
#line 5855 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 540:
#line 5861 "Gmsh.y"
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

  case 541:
#line 5875 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 542:
#line 5881 "Gmsh.y"
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

  case 543:
#line 5893 "Gmsh.y"
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

  case 544:
#line 5907 "Gmsh.y"
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

  case 545:
#line 5920 "Gmsh.y"
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
#line 5930 "Gmsh.y"
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
#line 5940 "Gmsh.y"
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

  case 548:
#line 5950 "Gmsh.y"
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

  case 549:
#line 5962 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 550:
#line 5966 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 551:
#line 5971 "Gmsh.y"
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

  case 552:
#line 5983 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 553:
#line 5987 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 554:
#line 5991 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 555:
#line 5995 "Gmsh.y"
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

  case 556:
#line 6013 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 557:
#line 6021 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 558:
#line 6029 "Gmsh.y"
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

  case 559:
#line 6058 "Gmsh.y"
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

  case 560:
#line 6068 "Gmsh.y"
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

  case 561:
#line 6084 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 562:
#line 6095 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 563:
#line 6100 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 564:
#line 6104 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 565:
#line 6108 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 566:
#line 6120 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 567:
#line 6124 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 568:
#line 6136 "Gmsh.y"
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

  case 569:
#line 6153 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 570:
#line 6163 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 571:
#line 6167 "Gmsh.y"
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

  case 572:
#line 6182 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 573:
#line 6187 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 574:
#line 6194 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 575:
#line 6198 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 576:
#line 6203 "Gmsh.y"
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
#line 6217 "Gmsh.y"
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

  case 578:
#line 6231 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 579:
#line 6235 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 580:
#line 6239 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 581:
#line 6243 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 582:
#line 6247 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 583:
#line 6255 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 584:
#line 6261 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 585:
#line 6270 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 586:
#line 6274 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 587:
#line 6278 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 588:
#line 6286 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 589:
#line 6292 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 590:
#line 6298 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 591:
#line 6302 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 592:
#line 6309 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 593:
#line 6317 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 594:
#line 6324 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 595:
#line 6333 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 596:
#line 6337 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 597:
#line 6341 "Gmsh.y"
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

  case 598:
#line 6356 "Gmsh.y"
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

  case 599:
#line 6370 "Gmsh.y"
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

  case 600:
#line 6384 "Gmsh.y"
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

  case 601:
#line 6396 "Gmsh.y"
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

  case 602:
#line 6412 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 603:
#line 6421 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 604:
#line 6430 "Gmsh.y"
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

  case 605:
#line 6440 "Gmsh.y"
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

  case 606:
#line 6451 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 607:
#line 6459 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 608:
#line 6467 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 609:
#line 6471 "Gmsh.y"
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

  case 610:
#line 6490 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6497 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 612:
#line 6503 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 613:
#line 6509 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 614:
#line 6516 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 615:
#line 6523 "Gmsh.y"
    { init_options(); ;}
    break;

  case 616:
#line 6525 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 617:
#line 6533 "Gmsh.y"
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

  case 618:
#line 6557 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 619:
#line 6559 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 620:
#line 6565 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 621:
#line 6570 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 622:
#line 6572 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 623:
#line 6577 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 624:
#line 6582 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 625:
#line 6587 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 626:
#line 6589 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 627:
#line 6593 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 628:
#line 6605 "Gmsh.y"
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

  case 629:
#line 6619 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 630:
#line 6623 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 631:
#line 6630 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 632:
#line 6638 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 633:
#line 6646 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 634:
#line 6657 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 635:
#line 6659 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 636:
#line 6662 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14870 "Gmsh.tab.cpp"
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


#line 6665 "Gmsh.y"


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

