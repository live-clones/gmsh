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
     tOnelabAction = 333,
     tOnelabRun = 334,
     tCodeName = 335,
     tCpu = 336,
     tMemory = 337,
     tTotalMemory = 338,
     tCreateTopology = 339,
     tCreateGeometry = 340,
     tClassifySurfaces = 341,
     tRenumberMeshNodes = 342,
     tRenumberMeshElements = 343,
     tDistanceFunction = 344,
     tDefineConstant = 345,
     tUndefineConstant = 346,
     tDefineNumber = 347,
     tDefineStruct = 348,
     tNameStruct = 349,
     tDimNameSpace = 350,
     tAppend = 351,
     tDefineString = 352,
     tSetNumber = 353,
     tSetTag = 354,
     tSetString = 355,
     tPoint = 356,
     tCircle = 357,
     tEllipse = 358,
     tCurve = 359,
     tSphere = 360,
     tPolarSphere = 361,
     tSurface = 362,
     tSpline = 363,
     tVolume = 364,
     tBox = 365,
     tCylinder = 366,
     tCone = 367,
     tTorus = 368,
     tEllipsoid = 369,
     tQuadric = 370,
     tShapeFromFile = 371,
     tRectangle = 372,
     tDisk = 373,
     tWire = 374,
     tGeoEntity = 375,
     tCharacteristic = 376,
     tLength = 377,
     tParametric = 378,
     tElliptic = 379,
     tRefineMesh = 380,
     tRecombineMesh = 381,
     tAdaptMesh = 382,
     tRelocateMesh = 383,
     tReorientMesh = 384,
     tSetFactory = 385,
     tThruSections = 386,
     tWedge = 387,
     tFillet = 388,
     tChamfer = 389,
     tPlane = 390,
     tRuled = 391,
     tTransfinite = 392,
     tPhysical = 393,
     tCompound = 394,
     tPeriodic = 395,
     tParent = 396,
     tUsing = 397,
     tPlugin = 398,
     tDegenerated = 399,
     tRecursive = 400,
     tSewing = 401,
     tRotate = 402,
     tTranslate = 403,
     tSymmetry = 404,
     tDilate = 405,
     tExtrude = 406,
     tLevelset = 407,
     tAffine = 408,
     tBooleanUnion = 409,
     tBooleanIntersection = 410,
     tBooleanDifference = 411,
     tBooleanSection = 412,
     tBooleanFragments = 413,
     tThickSolid = 414,
     tRecombine = 415,
     tSmoother = 416,
     tSplit = 417,
     tDelete = 418,
     tCoherence = 419,
     tIntersect = 420,
     tMeshAlgorithm = 421,
     tReverseMesh = 422,
     tMeshSizeFromBoundary = 423,
     tLayers = 424,
     tScaleLast = 425,
     tHole = 426,
     tAlias = 427,
     tAliasWithOptions = 428,
     tCopyOptions = 429,
     tQuadTriAddVerts = 430,
     tQuadTriNoNewVerts = 431,
     tRecombLaterals = 432,
     tTransfQuadTri = 433,
     tText2D = 434,
     tText3D = 435,
     tInterpolationScheme = 436,
     tTime = 437,
     tCombine = 438,
     tBSpline = 439,
     tBezier = 440,
     tNurbs = 441,
     tNurbsOrder = 442,
     tNurbsKnots = 443,
     tColor = 444,
     tColorTable = 445,
     tFor = 446,
     tIn = 447,
     tEndFor = 448,
     tIf = 449,
     tElseIf = 450,
     tElse = 451,
     tEndIf = 452,
     tExit = 453,
     tAbort = 454,
     tField = 455,
     tReturn = 456,
     tCall = 457,
     tSlide = 458,
     tMacro = 459,
     tShow = 460,
     tHide = 461,
     tGetValue = 462,
     tGetStringValue = 463,
     tGetEnv = 464,
     tGetString = 465,
     tGetNumber = 466,
     tUnique = 467,
     tSetMaxTag = 468,
     tHomology = 469,
     tCohomology = 470,
     tBetti = 471,
     tExists = 472,
     tFileExists = 473,
     tGetForced = 474,
     tGetForcedStr = 475,
     tGMSH_MAJOR_VERSION = 476,
     tGMSH_MINOR_VERSION = 477,
     tGMSH_PATCH_VERSION = 478,
     tGmshExecutableName = 479,
     tSetPartition = 480,
     tNameToString = 481,
     tStringToName = 482,
     tAFFECTDIVIDE = 483,
     tAFFECTTIMES = 484,
     tAFFECTMINUS = 485,
     tAFFECTPLUS = 486,
     tOR = 487,
     tAND = 488,
     tNOTEQUAL = 489,
     tEQUAL = 490,
     tGREATERGREATER = 491,
     tLESSLESS = 492,
     tGREATEROREQUAL = 493,
     tLESSOREQUAL = 494,
     UNARYPREC = 495,
     tMINUSMINUS = 496,
     tPLUSPLUS = 497
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
#define tOnelabAction 333
#define tOnelabRun 334
#define tCodeName 335
#define tCpu 336
#define tMemory 337
#define tTotalMemory 338
#define tCreateTopology 339
#define tCreateGeometry 340
#define tClassifySurfaces 341
#define tRenumberMeshNodes 342
#define tRenumberMeshElements 343
#define tDistanceFunction 344
#define tDefineConstant 345
#define tUndefineConstant 346
#define tDefineNumber 347
#define tDefineStruct 348
#define tNameStruct 349
#define tDimNameSpace 350
#define tAppend 351
#define tDefineString 352
#define tSetNumber 353
#define tSetTag 354
#define tSetString 355
#define tPoint 356
#define tCircle 357
#define tEllipse 358
#define tCurve 359
#define tSphere 360
#define tPolarSphere 361
#define tSurface 362
#define tSpline 363
#define tVolume 364
#define tBox 365
#define tCylinder 366
#define tCone 367
#define tTorus 368
#define tEllipsoid 369
#define tQuadric 370
#define tShapeFromFile 371
#define tRectangle 372
#define tDisk 373
#define tWire 374
#define tGeoEntity 375
#define tCharacteristic 376
#define tLength 377
#define tParametric 378
#define tElliptic 379
#define tRefineMesh 380
#define tRecombineMesh 381
#define tAdaptMesh 382
#define tRelocateMesh 383
#define tReorientMesh 384
#define tSetFactory 385
#define tThruSections 386
#define tWedge 387
#define tFillet 388
#define tChamfer 389
#define tPlane 390
#define tRuled 391
#define tTransfinite 392
#define tPhysical 393
#define tCompound 394
#define tPeriodic 395
#define tParent 396
#define tUsing 397
#define tPlugin 398
#define tDegenerated 399
#define tRecursive 400
#define tSewing 401
#define tRotate 402
#define tTranslate 403
#define tSymmetry 404
#define tDilate 405
#define tExtrude 406
#define tLevelset 407
#define tAffine 408
#define tBooleanUnion 409
#define tBooleanIntersection 410
#define tBooleanDifference 411
#define tBooleanSection 412
#define tBooleanFragments 413
#define tThickSolid 414
#define tRecombine 415
#define tSmoother 416
#define tSplit 417
#define tDelete 418
#define tCoherence 419
#define tIntersect 420
#define tMeshAlgorithm 421
#define tReverseMesh 422
#define tMeshSizeFromBoundary 423
#define tLayers 424
#define tScaleLast 425
#define tHole 426
#define tAlias 427
#define tAliasWithOptions 428
#define tCopyOptions 429
#define tQuadTriAddVerts 430
#define tQuadTriNoNewVerts 431
#define tRecombLaterals 432
#define tTransfQuadTri 433
#define tText2D 434
#define tText3D 435
#define tInterpolationScheme 436
#define tTime 437
#define tCombine 438
#define tBSpline 439
#define tBezier 440
#define tNurbs 441
#define tNurbsOrder 442
#define tNurbsKnots 443
#define tColor 444
#define tColorTable 445
#define tFor 446
#define tIn 447
#define tEndFor 448
#define tIf 449
#define tElseIf 450
#define tElse 451
#define tEndIf 452
#define tExit 453
#define tAbort 454
#define tField 455
#define tReturn 456
#define tCall 457
#define tSlide 458
#define tMacro 459
#define tShow 460
#define tHide 461
#define tGetValue 462
#define tGetStringValue 463
#define tGetEnv 464
#define tGetString 465
#define tGetNumber 466
#define tUnique 467
#define tSetMaxTag 468
#define tHomology 469
#define tCohomology 470
#define tBetti 471
#define tExists 472
#define tFileExists 473
#define tGetForced 474
#define tGetForcedStr 475
#define tGMSH_MAJOR_VERSION 476
#define tGMSH_MINOR_VERSION 477
#define tGMSH_PATCH_VERSION 478
#define tGmshExecutableName 479
#define tSetPartition 480
#define tNameToString 481
#define tStringToName 482
#define tAFFECTDIVIDE 483
#define tAFFECTTIMES 484
#define tAFFECTMINUS 485
#define tAFFECTPLUS 486
#define tOR 487
#define tAND 488
#define tNOTEQUAL 489
#define tEQUAL 490
#define tGREATERGREATER 491
#define tLESSLESS 492
#define tGREATEROREQUAL 493
#define tLESSOREQUAL 494
#define UNARYPREC 495
#define tMINUSMINUS 496
#define tPLUSPLUS 497




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
#line 165 "Gmsh.y"
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
#line 763 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 776 "Gmsh.tab.cpp"

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
#define YYLAST   17898

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  633
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   497

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   250,     2,   262,     2,   247,   249,     2,
     255,   256,   245,   243,   264,   244,   261,   246,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     237,     2,   238,   232,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   257,     2,   258,   254,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   259,   248,   260,   263,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   233,   234,   235,
     236,   239,   240,   241,   242,   251,   252,   253
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
    1503,  1509,  1513,  1519,  1527,  1535,  1539,  1547,  1551,  1554,
    1557,  1560,  1563,  1566,  1582,  1585,  1588,  1591,  1601,  1613,
    1616,  1621,  1624,  1627,  1630,  1633,  1650,  1662,  1669,  1678,
    1687,  1698,  1700,  1703,  1706,  1708,  1712,  1716,  1721,  1726,
    1728,  1730,  1736,  1748,  1762,  1763,  1771,  1772,  1786,  1787,
    1803,  1804,  1811,  1821,  1824,  1828,  1839,  1853,  1855,  1858,
    1864,  1872,  1875,  1878,  1882,  1885,  1889,  1892,  1896,  1906,
    1913,  1915,  1917,  1919,  1921,  1923,  1924,  1927,  1931,  1935,
    1940,  1950,  1955,  1970,  1971,  1975,  1976,  1978,  1979,  1982,
    1983,  1986,  1987,  1990,  1997,  2005,  2012,  2018,  2022,  2031,
    2038,  2047,  2056,  2062,  2067,  2074,  2086,  2098,  2117,  2136,
    2149,  2162,  2175,  2186,  2191,  2196,  2201,  2206,  2211,  2214,
    2218,  2225,  2227,  2229,  2231,  2234,  2240,  2248,  2259,  2261,
    2265,  2268,  2271,  2274,  2278,  2282,  2286,  2290,  2294,  2298,
    2302,  2306,  2310,  2314,  2318,  2322,  2326,  2330,  2334,  2338,
    2342,  2346,  2352,  2357,  2362,  2367,  2372,  2377,  2382,  2387,
    2392,  2397,  2402,  2409,  2414,  2419,  2424,  2429,  2434,  2439,
    2444,  2449,  2456,  2463,  2470,  2475,  2482,  2489,  2491,  2493,
    2495,  2497,  2499,  2501,  2503,  2505,  2507,  2509,  2511,  2512,
    2519,  2521,  2526,  2533,  2535,  2540,  2545,  2550,  2557,  2563,
    2571,  2580,  2591,  2596,  2601,  2608,  2613,  2617,  2620,  2626,
    2632,  2636,  2642,  2649,  2658,  2665,  2674,  2681,  2686,  2694,
    2701,  2708,  2715,  2720,  2727,  2732,  2733,  2736,  2737,  2740,
    2741,  2749,  2751,  2755,  2757,  2760,  2761,  2765,  2767,  2770,
    2773,  2777,  2781,  2793,  2803,  2811,  2819,  2821,  2825,  2827,
    2829,  2832,  2836,  2841,  2847,  2849,  2853,  2855,  2858,  2862,
    2866,  2872,  2877,  2882,  2885,  2890,  2893,  2897,  2901,  2906,
    2912,  2918,  2924,  2926,  2928,  2930,  2934,  2940,  2948,  2953,
    2958,  2963,  2970,  2977,  2986,  2995,  3000,  3015,  3020,  3025,
    3027,  3029,  3033,  3037,  3047,  3055,  3057,  3063,  3067,  3074,
    3076,  3080,  3082,  3084,  3089,  3094,  3098,  3104,  3111,  3120,
    3127,  3132,  3138,  3140,  3145,  3147,  3149,  3151,  3153,  3158,
    3165,  3170,  3177,  3183,  3191,  3196,  3201,  3206,  3215,  3220,
    3225,  3230,  3235,  3244,  3253,  3260,  3265,  3272,  3277,  3279,
    3281,  3286,  3291,  3292,  3299,  3304,  3307,  3312,  3317,  3319,
    3321,  3325,  3327,  3329,  3333,  3337,  3341,  3347,  3355,  3361,
    3367,  3376,  3378,  3380
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     266,     0,    -1,   267,    -1,     1,     6,    -1,    -1,   267,
     268,    -1,   270,    -1,   271,    -1,   292,    -1,   130,   255,
     368,   256,     6,    -1,   311,    -1,   317,    -1,   321,    -1,
     322,    -1,   323,    -1,   324,    -1,   328,    -1,   337,    -1,
     338,    -1,   344,    -1,   345,    -1,   327,    -1,   326,    -1,
     325,    -1,   320,    -1,   347,    -1,   238,    -1,   239,    -1,
      46,   255,   368,   256,     6,    -1,    48,   255,   368,   256,
       6,    -1,    47,   255,   368,   256,     6,    -1,    46,   255,
     368,   256,   269,   368,     6,    -1,    46,   255,   368,   264,
     364,   256,     6,    -1,    48,   255,   368,   264,   364,   256,
       6,    -1,    47,   255,   368,   264,   364,   256,     6,    -1,
      46,   255,   368,   264,   364,   256,   269,   368,     6,    -1,
     378,   368,   259,   272,   260,     6,    -1,   172,     4,   257,
     348,   258,     6,    -1,   173,     4,   257,   348,   258,     6,
      -1,   174,     4,   257,   348,   264,   348,   258,     6,    -1,
      -1,   272,   275,    -1,   272,   279,    -1,   272,   282,    -1,
     272,   284,    -1,   272,   285,    -1,   272,   327,    -1,   348,
      -1,   273,   264,   348,    -1,   348,    -1,   274,   264,   348,
      -1,    -1,    -1,     4,   276,   255,   273,   256,   277,   259,
     274,   260,     6,    -1,   368,    -1,   278,   264,   368,    -1,
      -1,   179,   255,   348,   264,   348,   264,   348,   256,   280,
     259,   278,   260,     6,    -1,   368,    -1,   281,   264,   368,
      -1,    -1,   180,   255,   348,   264,   348,   264,   348,   264,
     348,   256,   283,   259,   281,   260,     6,    -1,   181,   259,
     360,   260,   259,   360,   260,     6,    -1,   181,   259,   360,
     260,   259,   360,   260,   259,   360,   260,   259,   360,   260,
       6,    -1,    -1,   182,   286,   259,   274,   260,     6,    -1,
       7,    -1,   231,    -1,   230,    -1,   229,    -1,   228,    -1,
     253,    -1,   252,    -1,   255,    -1,   257,    -1,   256,    -1,
     258,    -1,     4,    -1,    36,    -1,    37,    -1,   110,    -1,
     111,    -1,    90,   257,   294,   258,     6,    -1,    91,   257,
     298,   258,     6,    -1,   353,     6,    -1,    98,   289,   369,
     264,   348,   290,     6,    -1,   100,   289,   378,   264,   369,
     290,     6,    -1,   378,   287,   361,     6,    -1,   378,   288,
       6,    -1,   378,   289,   290,   287,   361,     6,    -1,   378,
     289,   259,   364,   260,   290,   287,   361,     6,    -1,   378,
     257,   348,   258,   287,   348,     6,    -1,   378,   257,   348,
     258,   288,     6,    -1,   378,   255,   348,   256,   287,   348,
       6,    -1,   378,   255,   348,   256,   288,     6,    -1,   378,
       7,   369,     6,    -1,   378,   289,   290,     7,    49,   289,
     290,     6,    -1,   378,   289,   290,     7,    49,   289,   373,
     290,     6,    -1,   378,   289,   290,   231,    49,   289,   373,
     290,     6,    -1,   378,   261,   291,     7,   369,     6,    -1,
     378,   257,   348,   258,   261,   291,     7,   369,     6,    -1,
     378,   261,   291,   287,   348,     6,    -1,   378,   257,   348,
     258,   261,   291,   287,   348,     6,    -1,   378,   261,   291,
     288,     6,    -1,   378,   257,   348,   258,   261,   291,   288,
       6,    -1,   378,   261,   189,   261,   291,     7,   365,     6,
      -1,   378,   257,   348,   258,   261,   189,   261,   291,     7,
     365,     6,    -1,   378,   261,   190,     7,   366,     6,    -1,
     378,   257,   348,   258,   261,   190,     7,   366,     6,    -1,
     378,   200,     7,   361,     6,    -1,   200,   257,   348,   258,
       7,   291,     6,    -1,   200,   257,   348,   258,   261,   291,
       7,   348,     6,    -1,   200,   257,   348,   258,   261,   291,
       7,   369,     6,    -1,   200,   257,   348,   258,   261,   291,
       7,   259,   364,   260,     6,    -1,   200,   257,   348,   258,
     261,   291,     6,    -1,   143,   255,     4,   256,   261,   291,
       7,   348,     6,    -1,   143,   255,     4,   256,   261,   291,
       7,   369,     6,    -1,    -1,   264,    -1,    -1,   294,   293,
     378,    -1,   294,   293,   378,     7,   348,    -1,    -1,   294,
     293,   378,     7,   259,   361,   295,   300,   260,    -1,    -1,
     294,   293,   378,   289,   290,     7,   259,   361,   296,   300,
     260,    -1,   294,   293,   378,     7,   369,    -1,    -1,   294,
     293,   378,     7,   259,   369,   297,   304,   260,    -1,    -1,
     298,   293,   368,    -1,   348,     7,   369,    -1,   299,   264,
     348,     7,   369,    -1,   363,     7,   378,   255,   256,    -1,
      -1,   264,   302,    -1,    -1,   302,    -1,   303,    -1,   302,
     264,   303,    -1,     4,   361,    -1,    36,   348,    -1,    37,
     348,    -1,     4,    -1,     4,   259,   299,   260,    -1,     4,
     369,    -1,     4,   372,    -1,    -1,   264,   305,    -1,   306,
      -1,   305,   264,   306,    -1,     4,   348,    -1,     4,   369,
      -1,   204,   369,    -1,     4,   374,    -1,     4,   372,    -1,
     348,    -1,   369,    -1,   369,   264,   348,    -1,    -1,   192,
     105,   259,   348,   260,    -1,   142,   101,   259,   364,   260,
      -1,   142,   120,   259,   364,   260,    -1,    -1,   135,   358,
      -1,    -1,   142,   146,    -1,   101,   255,   348,   256,     7,
     358,     6,    -1,   104,   255,   348,   256,     7,   361,     6,
      -1,   108,   255,   348,   256,     7,   361,     6,    -1,   139,
     108,   255,   348,   256,     7,   361,   142,   348,     6,    -1,
     139,   184,   255,   348,   256,     7,   361,   142,   348,     6,
      -1,   102,   255,   348,   256,     7,   361,   309,     6,    -1,
     103,   255,   348,   256,     7,   361,   309,     6,    -1,   184,
     255,   348,   256,     7,   361,     6,    -1,   185,   255,   348,
     256,     7,   361,     6,    -1,   186,   255,   348,   256,     7,
     361,   188,   361,   187,   348,     6,    -1,   119,   255,   348,
     256,     7,   361,     6,    -1,   104,     4,   255,   348,   256,
       7,   361,     6,    -1,   135,   107,   255,   348,   256,     7,
     361,     6,    -1,   107,   255,   348,   256,     7,   361,   308,
       6,    -1,   136,   107,   255,   348,   256,     7,   361,   308,
       6,    -1,   184,   107,   255,   348,   256,     7,   361,     6,
      -1,   185,   107,   255,   348,   256,     7,   361,     6,    -1,
      13,    14,     6,    -1,    14,   107,   348,     6,    -1,   123,
     107,   255,   348,   256,     7,     5,     5,     5,     6,    -1,
     105,   255,   348,   256,     7,   361,     6,    -1,   106,   255,
     348,   256,     7,   361,     6,    -1,   110,   255,   348,   256,
       7,   361,     6,    -1,   113,   255,   348,   256,     7,   361,
       6,    -1,   117,   255,   348,   256,     7,   361,     6,    -1,
     118,   255,   348,   256,     7,   361,     6,    -1,   111,   255,
     348,   256,     7,   361,     6,    -1,   112,   255,   348,   256,
       7,   361,     6,    -1,   132,   255,   348,   256,     7,   361,
       6,    -1,   159,   255,   348,   256,     7,   361,     6,    -1,
     107,     4,   255,   348,   256,     7,   361,   310,     6,    -1,
     109,   255,   348,   256,     7,   361,     6,    -1,   131,   255,
     348,   256,     7,   361,     6,    -1,   136,   131,   255,   348,
     256,     7,   361,     6,    -1,   139,   314,   255,   348,   256,
       7,   361,     6,    -1,   139,   314,   255,   348,   256,     7,
     361,     4,   259,   360,   260,     6,    -1,    -1,   138,   313,
     312,   255,   307,   256,   287,   361,     6,    -1,   101,    -1,
     104,    -1,   107,    -1,   109,    -1,   120,   259,   348,   260,
      -1,   104,    -1,   107,    -1,   109,    -1,   120,   259,   348,
     260,    -1,   104,    -1,   107,    -1,   120,   259,   348,   260,
      -1,   101,    -1,   104,    -1,   107,    -1,   120,   259,   348,
     260,    -1,   148,   358,   259,   318,   260,    -1,   147,   259,
     358,   264,   358,   264,   348,   260,   259,   318,   260,    -1,
     149,   358,   259,   318,   260,    -1,   150,   259,   358,   264,
     348,   260,   259,   318,   260,    -1,   150,   259,   358,   264,
     358,   260,   259,   318,   260,    -1,   153,   259,   364,   260,
     259,   318,   260,    -1,     4,   259,   318,   260,    -1,   165,
     104,   259,   364,   260,   107,   259,   348,   260,    -1,   162,
     104,   259,   348,   260,   101,   259,   364,   260,     6,    -1,
     162,   104,   255,   348,   256,   259,   364,   260,     6,    -1,
     319,    -1,   317,    -1,    -1,   319,   311,    -1,   319,   313,
     259,   364,   260,     6,    -1,   319,   138,   313,   259,   364,
     260,     6,    -1,   319,   141,   313,   259,   364,   260,     6,
      -1,   319,   313,   259,     8,   260,     6,    -1,   319,   138,
     313,   259,     8,   260,     6,    -1,   152,   135,   255,   348,
     256,     7,   361,     6,    -1,   152,   101,   255,   348,   256,
       7,   259,   360,   260,     6,    -1,   152,   135,   255,   348,
     256,     7,   259,   358,   264,   358,   264,   364,   260,     6,
      -1,   152,   135,   255,   348,   256,     7,   259,   358,   264,
     358,   264,   358,   264,   364,   260,     6,    -1,   152,   105,
     255,   348,   256,     7,   259,   358,   264,   364,   260,     6,
      -1,   152,   111,   255,   348,   256,     7,   259,   358,   264,
     358,   264,   364,   260,     6,    -1,   152,   112,   255,   348,
     256,     7,   259,   358,   264,   358,   264,   364,   260,     6,
      -1,   152,   114,   255,   348,   256,     7,   259,   358,   264,
     358,   264,   364,   260,     6,    -1,   152,   115,   255,   348,
     256,     7,   259,   358,   264,   358,   264,   364,   260,     6,
      -1,   152,     4,   255,   348,   256,     7,   361,     6,    -1,
     152,     4,   255,   348,   256,     7,     5,     6,    -1,   152,
       4,   259,   348,   260,     6,    -1,   163,   259,   319,   260,
      -1,   145,   163,   259,   319,   260,    -1,   163,     4,   259,
     319,   260,    -1,   163,   200,   257,   348,   258,     6,    -1,
     163,     4,   257,   348,   258,     6,    -1,   163,   378,     6,
      -1,   163,     4,     4,     6,    -1,   163,    93,     6,    -1,
     189,   365,   259,   319,   260,    -1,   145,   189,   365,   259,
     319,   260,    -1,   225,   348,   259,   319,   260,    -1,   205,
     259,     8,   260,    -1,   205,     5,     6,    -1,   206,   259,
       8,   260,    -1,   206,     5,     6,    -1,   205,   259,   319,
     260,    -1,   145,   205,   259,   319,   260,    -1,   206,   259,
     319,   260,    -1,   145,   206,   259,   319,   260,    -1,   378,
     369,     6,    -1,    79,   255,   375,   256,     6,    -1,   378,
     378,   257,   348,   258,   368,     6,    -1,   378,   378,   378,
     257,   348,   258,     6,    -1,   378,   348,     6,    -1,   143,
     255,     4,   256,   261,     4,     6,    -1,   183,     4,     6,
      -1,   198,     6,    -1,   199,     6,    -1,    74,     6,    -1,
      75,     6,    -1,    67,     6,    -1,    67,   259,   348,   264,
     348,   264,   348,   264,   348,   264,   348,   264,   348,   260,
       6,    -1,    68,     6,    -1,    69,     6,    -1,    84,     6,
      -1,    86,   259,   348,   264,   348,   264,   348,   260,     6,
      -1,    86,   259,   348,   264,   348,   264,   348,   264,   348,
     260,     6,    -1,    85,     6,    -1,    85,   259,   319,   260,
      -1,    87,     6,    -1,    88,     6,    -1,   125,     6,    -1,
     126,     6,    -1,   127,   259,   364,   260,   259,   364,   260,
     259,   360,   260,   259,   348,   264,   348,   260,     6,    -1,
     203,   255,   259,   364,   260,   264,   369,   264,   369,   256,
       6,    -1,   191,   255,   348,     8,   348,   256,    -1,   191,
     255,   348,     8,   348,     8,   348,   256,    -1,   191,     4,
     192,   259,   348,     8,   348,   260,    -1,   191,     4,   192,
     259,   348,     8,   348,     8,   348,   260,    -1,   193,    -1,
     204,     4,    -1,   204,   369,    -1,   201,    -1,   202,   378,
       6,    -1,   202,   369,     6,    -1,   194,   255,   348,   256,
      -1,   195,   255,   348,   256,    -1,   196,    -1,   197,    -1,
     151,   358,   259,   319,   260,    -1,   151,   259,   358,   264,
     358,   264,   348,   260,   259,   319,   260,    -1,   151,   259,
     358,   264,   358,   264,   358,   264,   348,   260,   259,   319,
     260,    -1,    -1,   151,   358,   259,   319,   329,   333,   260,
      -1,    -1,   151,   259,   358,   264,   358,   264,   348,   260,
     259,   319,   330,   333,   260,    -1,    -1,   151,   259,   358,
     264,   358,   264,   358,   264,   348,   260,   259,   319,   331,
     333,   260,    -1,    -1,   151,   259,   319,   332,   333,   260,
      -1,   151,   259,   319,   260,   142,   119,   259,   348,   260,
      -1,   131,   361,    -1,   136,   131,   361,    -1,   133,   259,
     364,   260,   259,   364,   260,   259,   364,   260,    -1,   134,
     259,   364,   260,   259,   364,   260,   259,   364,   260,   259,
     364,   260,    -1,   334,    -1,   333,   334,    -1,   169,   259,
     348,   260,     6,    -1,   169,   259,   361,   264,   361,   260,
       6,    -1,   170,     6,    -1,   160,     6,    -1,   160,   348,
       6,    -1,   175,     6,    -1,   175,   177,     6,    -1,   176,
       6,    -1,   176,   177,     6,    -1,   171,   255,   348,   256,
       7,   361,   142,   348,     6,    -1,   142,     4,   257,   348,
     258,     6,    -1,   154,    -1,   155,    -1,   156,    -1,   157,
      -1,   158,    -1,    -1,   163,     6,    -1,   145,   163,     6,
      -1,   163,   348,     6,    -1,   145,   163,   348,     6,    -1,
     335,   259,   319,   336,   260,   259,   319,   336,   260,    -1,
     116,   255,   368,   256,    -1,   335,   255,   348,   256,     7,
     259,   319,   336,   260,   259,   319,   336,   260,     6,    -1,
      -1,   142,     4,   348,    -1,    -1,     4,    -1,    -1,     7,
     361,    -1,    -1,     7,   348,    -1,    -1,   153,   361,    -1,
     121,   122,   362,     7,   348,     6,    -1,   137,   104,   362,
       7,   348,   339,     6,    -1,   137,   107,   362,   341,   340,
       6,    -1,   137,   109,   362,   341,     6,    -1,   178,   362,
       6,    -1,    99,   313,   255,   348,   264,   348,   256,     6,
      -1,   213,   313,   255,   348,   256,     6,    -1,   166,   107,
     259,   364,   260,     7,   348,     6,    -1,   168,   107,   259,
     364,   260,     7,   348,     6,    -1,   160,   107,   362,   342,
       6,    -1,   160,   109,   362,     6,    -1,   161,   107,   362,
       7,   348,     6,    -1,   140,   104,   259,   364,   260,     7,
     259,   364,   260,   343,     6,    -1,   140,   107,   259,   364,
     260,     7,   259,   364,   260,   343,     6,    -1,   140,   104,
     259,   364,   260,     7,   259,   364,   260,   147,   259,   358,
     264,   358,   264,   348,   260,     6,    -1,   140,   107,   259,
     364,   260,     7,   259,   364,   260,   147,   259,   358,   264,
     358,   264,   348,   260,     6,    -1,   140,   104,   259,   364,
     260,     7,   259,   364,   260,   148,   358,     6,    -1,   140,
     107,   259,   364,   260,     7,   259,   364,   260,   148,   358,
       6,    -1,   140,   107,   348,   259,   364,   260,     7,   348,
     259,   364,   260,     6,    -1,   313,   259,   364,   260,   192,
     313,   259,   348,   260,     6,    -1,   167,   315,   362,     6,
      -1,   128,   316,   362,     6,    -1,   129,   109,   361,     6,
      -1,   144,   104,   361,     6,    -1,   139,   314,   361,     6,
      -1,   164,     6,    -1,   164,     4,     6,    -1,   164,   101,
     259,   364,   260,     6,    -1,   214,    -1,   215,    -1,   216,
      -1,   346,     6,    -1,   346,   259,   361,   260,     6,    -1,
     346,   259,   361,   264,   361,   260,     6,    -1,   346,   255,
     361,   256,   259,   361,   264,   361,   260,     6,    -1,   349,
      -1,   255,   348,   256,    -1,   244,   348,    -1,   243,   348,
      -1,   250,   348,    -1,   348,   244,   348,    -1,   348,   243,
     348,    -1,   348,   245,   348,    -1,   348,   246,   348,    -1,
     348,   248,   348,    -1,   348,   249,   348,    -1,   348,   247,
     348,    -1,   348,   254,   348,    -1,   348,   237,   348,    -1,
     348,   238,   348,    -1,   348,   242,   348,    -1,   348,   241,
     348,    -1,   348,   236,   348,    -1,   348,   235,   348,    -1,
     348,   234,   348,    -1,   348,   233,   348,    -1,   348,   239,
     348,    -1,   348,   240,   348,    -1,   348,   232,   348,     8,
     348,    -1,    16,   289,   348,   290,    -1,    17,   289,   348,
     290,    -1,    18,   289,   348,   290,    -1,    19,   289,   348,
     290,    -1,    20,   289,   348,   290,    -1,    21,   289,   348,
     290,    -1,    22,   289,   348,   290,    -1,    23,   289,   348,
     290,    -1,    24,   289,   348,   290,    -1,    26,   289,   348,
     290,    -1,    27,   289,   348,   264,   348,   290,    -1,    28,
     289,   348,   290,    -1,    29,   289,   348,   290,    -1,    30,
     289,   348,   290,    -1,    31,   289,   348,   290,    -1,    32,
     289,   348,   290,    -1,    33,   289,   348,   290,    -1,    34,
     289,   348,   290,    -1,    35,   289,   348,   290,    -1,    38,
     289,   348,   264,   348,   290,    -1,    39,   289,   348,   264,
     348,   290,    -1,    40,   289,   348,   264,   348,   290,    -1,
      25,   289,   348,   290,    -1,    37,   289,   348,   264,   348,
     290,    -1,    36,   289,   348,   264,   348,   290,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   221,
      -1,   222,    -1,   223,    -1,    81,    -1,    82,    -1,    83,
      -1,    -1,    92,   289,   348,   350,   300,   290,    -1,   353,
      -1,   211,   289,   368,   290,    -1,   211,   289,   368,   264,
     348,   290,    -1,   355,    -1,   378,   257,   348,   258,    -1,
     378,   255,   348,   256,    -1,   217,   255,   355,   256,    -1,
     217,   255,   355,   261,   291,   256,    -1,   219,   255,   355,
     351,   256,    -1,   219,   255,   355,   261,   291,   351,   256,
      -1,   219,   255,   355,   289,   348,   290,   351,   256,    -1,
     219,   255,   355,   261,   291,   289,   348,   290,   351,   256,
      -1,   218,   255,   369,   256,    -1,   262,   378,   289,   290,
      -1,   262,   355,   261,   291,   289,   290,    -1,    95,   289,
     378,   290,    -1,    95,   289,   290,    -1,   378,   288,    -1,
     378,   257,   348,   258,   288,    -1,   378,   255,   348,   256,
     288,    -1,   378,   261,   291,    -1,   378,     9,   378,   261,
     291,    -1,   378,   261,   291,   255,   348,   256,    -1,   378,
       9,   378,   261,   291,   255,   348,   256,    -1,   378,   261,
     291,   257,   348,   258,    -1,   378,     9,   378,   261,   291,
     257,   348,   258,    -1,   378,   257,   348,   258,   261,   291,
      -1,   378,   261,   291,   288,    -1,   378,   257,   348,   258,
     261,   291,   288,    -1,   207,   255,   368,   264,   348,   256,
      -1,    59,   255,   361,   264,   361,   256,    -1,    60,   289,
     368,   264,   368,   290,    -1,    58,   289,   368,   290,    -1,
      61,   289,   368,   264,   368,   290,    -1,    66,   255,   375,
     256,    -1,    -1,   264,   348,    -1,    -1,   264,   368,    -1,
      -1,    93,   355,   357,   354,   257,   301,   258,    -1,   378,
      -1,   378,     9,   378,    -1,    96,    -1,    96,   348,    -1,
      -1,   255,   356,   256,    -1,   359,    -1,   244,   358,    -1,
     243,   358,    -1,   358,   244,   358,    -1,   358,   243,   358,
      -1,   259,   348,   264,   348,   264,   348,   264,   348,   264,
     348,   260,    -1,   259,   348,   264,   348,   264,   348,   264,
     348,   260,    -1,   259,   348,   264,   348,   264,   348,   260,
      -1,   255,   348,   264,   348,   264,   348,   256,    -1,   361,
      -1,   360,   264,   361,    -1,   348,    -1,   363,    -1,   259,
     260,    -1,   259,   364,   260,    -1,   244,   259,   364,   260,
      -1,   348,   245,   259,   364,   260,    -1,   361,    -1,   259,
       8,   260,    -1,     5,    -1,   244,   363,    -1,   348,   245,
     363,    -1,   348,     8,   348,    -1,   348,     8,   348,     8,
     348,    -1,   101,   259,   348,   260,    -1,   101,   259,     8,
     260,    -1,   101,     5,    -1,   314,   259,     8,   260,    -1,
     314,     5,    -1,   138,   313,   362,    -1,   141,   313,   361,
      -1,   313,   192,    67,   361,    -1,    67,   313,   259,   364,
     260,    -1,    76,   314,   259,   348,   260,    -1,    77,   314,
     259,   348,   260,    -1,   317,    -1,   328,    -1,   337,    -1,
     378,   289,   290,    -1,   378,   261,   291,   289,   290,    -1,
     378,     9,   378,   261,   291,   289,   290,    -1,    41,   257,
     378,   258,    -1,    41,   257,   363,   258,    -1,    41,   255,
     363,   256,    -1,    41,   289,   259,   364,   260,   290,    -1,
     378,   289,   259,   364,   260,   290,    -1,    42,   289,   348,
     264,   348,   264,   348,   290,    -1,    43,   289,   348,   264,
     348,   264,   348,   290,    -1,    44,   289,   368,   290,    -1,
      45,   289,   348,   264,   348,   264,   348,   264,   348,   264,
     348,   264,   348,   290,    -1,   212,   289,   363,   290,    -1,
      32,   289,   363,   290,    -1,   348,    -1,   363,    -1,   364,
     264,   348,    -1,   364,   264,   363,    -1,   259,   348,   264,
     348,   264,   348,   264,   348,   260,    -1,   259,   348,   264,
     348,   264,   348,   260,    -1,   378,    -1,     4,   261,   189,
     261,     4,    -1,   259,   367,   260,    -1,   378,   257,   348,
     258,   261,   190,    -1,   365,    -1,   367,   264,   365,    -1,
     369,    -1,   378,    -1,   378,   257,   348,   258,    -1,   378,
     255,   348,   256,    -1,   378,   261,   291,    -1,   378,     9,
     378,   261,   291,    -1,   378,   261,   291,   255,   348,   256,
      -1,   378,     9,   378,   261,   291,   255,   348,   256,    -1,
     378,   257,   348,   258,   261,     4,    -1,   313,   259,   348,
     260,    -1,   138,   313,   259,   348,   260,    -1,     5,    -1,
     226,   257,   378,   258,    -1,    70,    -1,   224,    -1,    78,
      -1,    80,    -1,   209,   255,   368,   256,    -1,   208,   255,
     368,   264,   368,   256,    -1,   210,   289,   368,   290,    -1,
     210,   289,   368,   264,   368,   290,    -1,   220,   255,   355,
     352,   256,    -1,   220,   255,   355,   261,   291,   352,   256,
      -1,    51,   289,   375,   290,    -1,    52,   255,   368,   256,
      -1,    53,   255,   368,   256,    -1,    54,   255,   368,   264,
     368,   264,   368,   256,    -1,    49,   289,   375,   290,    -1,
      63,   289,   368,   290,    -1,    64,   289,   368,   290,    -1,
      65,   289,   368,   290,    -1,    62,   289,   348,   264,   368,
     264,   368,   290,    -1,    57,   289,   368,   264,   348,   264,
     348,   290,    -1,    57,   289,   368,   264,   348,   290,    -1,
      50,   289,   368,   290,    -1,    50,   289,   368,   264,   364,
     290,    -1,    71,   289,   368,   290,    -1,    72,    -1,    73,
      -1,    56,   289,   368,   290,    -1,    55,   289,   368,   290,
      -1,    -1,    97,   289,   369,   370,   304,   290,    -1,    94,
     289,   371,   290,    -1,   262,   348,    -1,   378,     9,   262,
     348,    -1,    49,   289,   374,   290,    -1,   375,    -1,   374,
      -1,   259,   375,   260,    -1,   368,    -1,   376,    -1,   375,
     264,   368,    -1,   375,   264,   376,    -1,   378,   255,   256,
      -1,   378,   261,   291,   255,   256,    -1,   378,     9,   378,
     261,   291,   255,   256,    -1,     4,   263,   259,   348,   260,
      -1,   377,   263,   259,   348,   260,    -1,   227,   257,   368,
     258,   263,   259,   348,   260,    -1,     4,    -1,   377,    -1,
     227,   257,   368,   258,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   271,   271,   272,   277,   279,   283,   284,   285,   286,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   324,   328,   335,   340,
     345,   350,   364,   377,   390,   403,   431,   445,   458,   471,
     490,   495,   496,   497,   498,   499,   500,   504,   506,   511,
     513,   519,   623,   518,   641,   648,   659,   658,   676,   683,
     694,   693,   710,   727,   750,   749,   763,   764,   765,   766,
     767,   771,   772,   778,   778,   780,   780,   785,   786,   787,
     788,   789,   795,   796,   797,   798,   803,   809,   871,   886,
     915,   925,   930,   938,   943,   951,   960,   965,   977,   994,
    1000,  1009,  1027,  1045,  1054,  1066,  1071,  1079,  1099,  1122,
    1142,  1150,  1172,  1195,  1233,  1254,  1266,  1280,  1280,  1282,
    1284,  1293,  1303,  1302,  1323,  1322,  1340,  1350,  1349,  1363,
    1365,  1373,  1379,  1384,  1411,  1413,  1416,  1418,  1422,  1423,
    1427,  1439,  1443,  1447,  1460,  1474,  1482,  1495,  1497,  1501,
    1502,  1507,  1515,  1524,  1532,  1546,  1564,  1568,  1575,  1584,
    1587,  1593,  1597,  1609,  1612,  1619,  1622,  1628,  1651,  1667,
    1683,  1700,  1717,  1754,  1798,  1814,  1830,  1862,  1878,  1895,
    1911,  1961,  1979,  2000,  2021,  2027,  2033,  2040,  2071,  2086,
    2108,  2131,  2154,  2177,  2201,  2225,  2249,  2275,  2292,  2308,
    2326,  2344,  2356,  2370,  2369,  2399,  2401,  2403,  2405,  2407,
    2415,  2417,  2419,  2421,  2429,  2431,  2433,  2441,  2443,  2445,
    2447,  2457,  2473,  2489,  2505,  2521,  2537,  2554,  2591,  2612,
    2633,  2659,  2660,  2665,  2668,  2672,  2689,  2709,  2729,  2748,
    2775,  2794,  2815,  2830,  2846,  2864,  2915,  2936,  2958,  2981,
    3086,  3102,  3137,  3159,  3181,  3193,  3199,  3214,  3245,  3257,
    3266,  3273,  3285,  3305,  3309,  3314,  3318,  3323,  3330,  3337,
    3344,  3356,  3429,  3447,  3472,  3487,  3520,  3532,  3564,  3568,
    3573,  3580,  3585,  3595,  3600,  3606,  3614,  3622,  3626,  3630,
    3634,  3641,  3645,  3649,  3661,  3670,  3734,  3750,  3767,  3784,
    3806,  3828,  3863,  3871,  3879,  3885,  3892,  3899,  3919,  3945,
    3957,  3968,  3986,  4004,  4023,  4022,  4047,  4046,  4073,  4072,
    4097,  4096,  4119,  4135,  4152,  4169,  4192,  4220,  4223,  4229,
    4241,  4261,  4265,  4269,  4273,  4277,  4281,  4285,  4289,  4298,
    4311,  4312,  4313,  4314,  4315,  4319,  4320,  4321,  4322,  4323,
    4326,  4350,  4369,  4392,  4395,  4411,  4414,  4431,  4434,  4440,
    4443,  4450,  4453,  4460,  4482,  4523,  4567,  4606,  4631,  4644,
    4655,  4672,  4689,  4719,  4745,  4771,  4803,  4830,  4856,  4882,
    4908,  4934,  4956,  4967,  5015,  5069,  5084,  5096,  5107,  5114,
    5129,  5143,  5144,  5145,  5149,  5155,  5167,  5185,  5213,  5214,
    5215,  5216,  5217,  5218,  5219,  5220,  5221,  5228,  5229,  5230,
    5231,  5232,  5233,  5234,  5235,  5236,  5237,  5238,  5239,  5240,
    5241,  5242,  5243,  5244,  5245,  5246,  5247,  5248,  5249,  5250,
    5251,  5252,  5253,  5254,  5255,  5256,  5257,  5258,  5259,  5260,
    5261,  5262,  5263,  5264,  5265,  5266,  5267,  5276,  5277,  5278,
    5279,  5280,  5281,  5282,  5283,  5284,  5285,  5286,  5291,  5290,
    5298,  5302,  5307,  5312,  5316,  5321,  5326,  5330,  5334,  5338,
    5342,  5346,  5350,  5356,  5371,  5375,  5381,  5386,  5405,  5425,
    5446,  5450,  5454,  5458,  5462,  5466,  5470,  5475,  5485,  5495,
    5500,  5511,  5520,  5525,  5530,  5558,  5559,  5565,  5566,  5572,
    5571,  5594,  5596,  5601,  5603,  5609,  5610,  5615,  5619,  5623,
    5627,  5631,  5638,  5642,  5646,  5650,  5657,  5662,  5669,  5674,
    5678,  5683,  5687,  5695,  5706,  5710,  5714,  5728,  5736,  5744,
    5751,  5761,  5784,  5789,  5795,  5800,  5806,  5817,  5823,  5837,
    5843,  5855,  5869,  5879,  5889,  5899,  5911,  5915,  5920,  5932,
    5936,  5940,  5944,  5962,  5970,  5978,  6007,  6017,  6033,  6044,
    6049,  6053,  6057,  6069,  6073,  6085,  6102,  6112,  6116,  6131,
    6136,  6143,  6147,  6152,  6166,  6180,  6184,  6188,  6192,  6196,
    6204,  6210,  6219,  6223,  6227,  6235,  6241,  6247,  6251,  6258,
    6266,  6273,  6282,  6286,  6290,  6305,  6319,  6333,  6345,  6361,
    6370,  6379,  6389,  6400,  6408,  6416,  6420,  6439,  6446,  6452,
    6458,  6465,  6473,  6472,  6482,  6506,  6508,  6514,  6519,  6521,
    6526,  6531,  6536,  6538,  6542,  6554,  6568,  6572,  6579,  6587,
    6595,  6606,  6608,  6611
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
  "tOnelabAction", "tOnelabRun", "tCodeName", "tCpu", "tMemory",
  "tTotalMemory", "tCreateTopology", "tCreateGeometry",
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
  "tSetPartition", "tNameToString", "tStringToName", "tAFFECTDIVIDE",
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
     485,   486,    63,   487,   488,   489,   490,    60,    62,   491,
     492,   493,   494,    43,    45,    42,    47,    37,   124,    38,
      33,   495,   496,   497,    94,    40,    41,    91,    93,   123,
     125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   265,   266,   266,   267,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   271,   271,   271,   271,
     272,   272,   272,   272,   272,   272,   272,   273,   273,   274,
     274,   276,   277,   275,   278,   278,   280,   279,   281,   281,
     283,   282,   284,   284,   286,   285,   287,   287,   287,   287,
     287,   288,   288,   289,   289,   290,   290,   291,   291,   291,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   293,   293,   294,
     294,   294,   295,   294,   296,   294,   294,   297,   294,   298,
     298,   299,   299,   299,   300,   300,   301,   301,   302,   302,
     303,   303,   303,   303,   303,   303,   303,   304,   304,   305,
     305,   306,   306,   306,   306,   306,   307,   307,   307,   308,
     308,   308,   308,   309,   309,   310,   310,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   312,   311,   313,   313,   313,   313,   313,
     314,   314,   314,   314,   315,   315,   315,   316,   316,   316,
     316,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   318,   318,   319,   319,   319,   319,   319,   319,   319,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   322,   323,   324,   324,   324,   324,   324,   324,   324,
     324,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   326,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   328,   328,   328,   329,   328,   330,   328,   331,   328,
     332,   328,   328,   328,   328,   328,   328,   333,   333,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     335,   335,   335,   335,   335,   336,   336,   336,   336,   336,
     337,   337,   338,   339,   339,   340,   340,   341,   341,   342,
     342,   343,   343,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   345,   345,
     345,   346,   346,   346,   347,   347,   347,   347,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   350,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   351,   351,   352,   352,   354,
     353,   355,   355,   356,   356,   357,   357,   358,   358,   358,
     358,   358,   359,   359,   359,   359,   360,   360,   361,   361,
     361,   361,   361,   361,   362,   362,   362,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   364,
     364,   364,   364,   365,   365,   365,   365,   366,   366,   367,
     367,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   370,   369,   369,   371,   371,   372,   373,   373,
     374,   375,   375,   375,   375,   376,   376,   376,   377,   377,
     377,   378,   378,   378
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
       5,     3,     5,     7,     7,     3,     7,     3,     2,     2,
       2,     2,     2,    15,     2,     2,     2,     9,    11,     2,
       4,     2,     2,     2,     2,    16,    11,     6,     8,     8,
      10,     1,     2,     2,     1,     3,     3,     4,     4,     1,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     9,     2,     3,    10,    13,     1,     2,     5,
       7,     2,     2,     3,     2,     3,     2,     3,     9,     6,
       1,     1,     1,     1,     1,     0,     2,     3,     3,     4,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     6,     7,     6,     5,     3,     8,     6,
       8,     8,     5,     4,     6,    11,    11,    18,    18,    12,
      12,    12,    10,     4,     4,     4,     4,     4,     2,     3,
       6,     1,     1,     1,     2,     5,     7,    10,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     6,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       1,     4,     6,     1,     4,     4,     4,     6,     5,     7,
       8,    10,     4,     4,     6,     4,     3,     2,     5,     5,
       3,     5,     6,     8,     6,     8,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     0,     2,     0,     2,     0,
       7,     1,     3,     1,     2,     0,     3,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     3,     1,     2,     3,     3,
       5,     4,     4,     2,     4,     2,     3,     3,     4,     5,
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
       0,     0,     0,     2,     3,     1,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   206,     0,     0,   207,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   340,   341,   342,   343,   344,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     301,     0,     0,   309,   310,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,   391,   392,   393,     0,     0,
       5,     6,     7,     8,    10,     0,    11,    24,    12,    13,
      14,    15,    23,    22,    21,    16,     0,    17,    18,    19,
      20,     0,    25,     0,   632,     0,   233,     0,     0,     0,
       0,     0,     0,   282,     0,   284,   285,   280,   281,     0,
     286,   289,   233,     0,   291,   292,   119,   129,   631,   505,
     501,    73,    74,     0,   205,   206,   207,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   294,     0,   217,   218,   219,     0,     0,
       0,     0,   447,   448,   450,   451,   449,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   456,   457,     0,     0,
     205,   210,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,   453,   454,     0,     0,
       0,     0,     0,     0,     0,     0,   542,   543,     0,   544,
     518,   398,   460,   463,   323,   519,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   210,   211,     0,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,     0,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   631,     0,     0,
     233,     0,     0,   388,     0,     0,     0,   214,   215,     0,
       0,     0,     0,     0,     0,   526,     0,     0,   524,     0,
       0,     0,     0,     0,     0,     0,   631,     0,     0,   565,
       0,     0,     0,     0,   278,   279,     0,   582,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   584,     0,   608,   609,   586,   587,     0,     0,     0,
       0,     0,     0,   585,     0,     0,     0,     0,   302,   303,
       0,   233,     0,   233,     0,     0,     0,     0,   501,     0,
       0,     0,   233,   394,     0,     0,    84,     0,    66,     0,
       0,    70,    69,    68,    67,    72,    71,    73,    74,     0,
       0,     0,     0,     0,     0,     0,   571,   501,     0,   232,
       0,   231,     0,   184,     0,     0,   571,   572,     0,     0,
       0,   621,     0,   622,   572,     0,     0,   117,   117,     0,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   559,   560,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   401,
       0,   400,   527,   402,     0,   520,     0,     0,   501,     0,
     535,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,   477,     0,     0,     0,
       0,     0,     0,     0,   324,     0,   357,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,   233,   233,     0,   509,   508,     0,     0,     0,     0,
     233,   233,     0,     0,     0,     0,   320,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,     0,     0,     0,     0,     0,     0,   233,   259,     0,
       0,   257,   389,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   367,   277,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     306,   305,     0,   264,     0,     0,   266,     0,     0,     0,
       0,   400,     0,   233,     0,     0,     0,     0,     0,     0,
       0,   345,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,     0,     0,     0,     0,    88,
      75,    76,     0,     0,     0,   275,    40,   271,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,   234,
       0,     0,   185,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,   118,     0,     0,     0,   503,     0,     0,   502,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,     0,
       0,     0,   209,     0,     0,     0,     0,     0,     0,   384,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,   476,     0,     0,     0,
       0,   536,   537,     0,     0,     0,     0,     0,   495,     0,
     399,   521,     0,     0,     0,     0,   529,     0,   418,   417,
     416,   415,   411,   412,   419,   420,   414,   413,   404,   403,
       0,   405,   528,   406,   409,   407,   408,   410,   502,     0,
       0,   480,     0,   545,     0,     0,     0,     0,     0,     0,
       0,     0,   355,     0,     0,     0,     0,     0,     0,   387,
       0,     0,     0,     0,   386,     0,   233,     0,     0,     0,
       0,     0,   511,   510,     0,     0,     0,     0,     0,     0,
       0,   314,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   373,     0,     0,     0,   258,
       0,     0,     0,   252,     0,     0,     0,     0,   383,     0,
       0,     0,     0,   399,   525,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   307,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   612,     0,     0,     0,   497,
       0,     0,   263,   267,   265,   269,     0,     0,   405,     0,
     502,   480,   633,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,   399,     0,     0,     0,    66,
       0,     0,    87,     0,    66,    67,     0,     0,     0,   502,
       0,     0,   480,     0,     0,     0,   203,     0,     0,     0,
     628,    28,    26,    27,     0,     0,     0,     0,     0,   575,
      30,     0,    29,     0,     0,   272,   623,   624,     0,   625,
     575,     0,    82,   120,    83,   130,   504,   506,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   561,   562,   220,     9,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   444,   431,     0,   433,
     434,   435,   436,   437,   558,   438,   439,   440,     0,     0,
       0,     0,     0,   550,   549,   548,     0,     0,     0,   555,
       0,   492,     0,     0,     0,   494,     0,     0,     0,   134,
     475,   532,   531,   213,     0,     0,   461,   557,   466,     0,
     472,     0,     0,     0,     0,   522,     0,     0,   473,   538,
     534,     0,     0,     0,     0,   465,   464,    73,    74,   487,
       0,     0,     0,     0,     0,     0,     0,   399,   353,   358,
     356,     0,   366,     0,   156,   157,     0,   213,     0,   399,
       0,     0,     0,     0,   253,     0,   268,   270,     0,     0,
       0,   221,   223,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,   311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,   360,
     372,     0,     0,     0,     0,   254,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,     0,     0,     0,   598,     0,   605,
     594,   595,   596,     0,   611,   610,     0,     0,   599,   600,
     601,   607,   615,   614,     0,   147,     0,   588,     0,   590,
       0,     0,     0,   583,     0,     0,   262,     0,     0,     0,
       0,     0,     0,     0,   346,     0,     0,     0,   395,     0,
     629,     0,   109,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,     0,     0,     0,     0,
     580,    51,     0,     0,     0,    64,     0,    41,    42,    43,
      44,    45,    46,     0,   465,   464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,   137,   138,     0,     0,     0,     0,   163,
     163,     0,     0,     0,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,   540,   541,     0,     0,     0,     0,     0,
     495,   496,     0,   468,     0,     0,   530,   421,   523,   481,
     479,     0,   478,     0,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,   261,     0,     0,     0,
       0,     0,     0,     0,   332,     0,     0,   331,     0,   334,
       0,   336,     0,   321,   328,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   374,     0,
       0,   256,   255,   390,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,   566,     0,     0,     0,   297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   497,   498,   592,     0,   369,   481,     0,     0,   233,
     347,     0,   348,   233,     0,     0,   581,     0,    94,     0,
       0,     0,     0,    92,     0,   569,     0,   107,     0,    99,
     101,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      36,   481,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,   576,     0,     0,
      34,    33,     0,   576,   626,     0,     0,   121,   126,     0,
       0,     0,   140,   145,   146,   141,   142,   500,     0,    85,
       0,    86,   167,     0,     0,     0,     0,   168,   187,   188,
     165,     0,     0,     0,   169,   198,   189,   193,   194,   190,
     191,   192,   177,     0,     0,   432,   446,   445,   441,   442,
     443,   551,     0,     0,     0,   490,   491,   493,   135,   459,
     489,   462,   467,     0,     0,   495,   199,   474,    73,    74,
       0,   486,   482,   484,   552,   195,     0,     0,     0,   159,
       0,     0,   364,     0,   158,     0,     0,     0,     0,     0,
       0,   276,     0,     0,     0,     0,   233,   233,     0,     0,
     333,   518,     0,     0,   335,   337,     0,     0,   315,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   226,
     196,     0,     0,     0,     0,     0,     0,     0,   174,     0,
     175,     0,     0,     0,     0,   110,   114,     0,   606,     0,
       0,   604,     0,   616,     0,     0,   148,   149,   613,   589,
     591,     0,     0,     0,     0,     0,     0,   345,   349,   345,
       0,   396,    93,     0,     0,    66,     0,     0,    91,     0,
     567,     0,     0,     0,     0,     0,     0,   619,   618,     0,
       0,     0,     0,     0,   516,     0,     0,    77,   273,   482,
     274,     0,     0,     0,     0,     0,   238,   235,     0,     0,
     579,   577,     0,     0,     0,     0,   122,   127,     0,     0,
       0,   559,   560,   139,   368,   164,   172,   173,   178,     0,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,   469,     0,     0,     0,   547,   488,     0,     0,   179,
       0,   200,   354,     0,     0,     0,     0,   201,     0,     0,
       0,     0,     0,     0,   515,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   240,     0,     0,     0,
     370,   371,    39,   182,   183,     0,   564,     0,     0,   299,
     298,     0,     0,     0,     0,     0,     0,   151,   152,   155,
     154,   153,     0,   593,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   570,     0,     0,     0,
      96,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      49,     0,   239,   236,   237,    35,     0,     0,   627,   287,
       0,   134,   147,     0,     0,   144,     0,     0,     0,   166,
     197,     0,     0,     0,     0,     0,   553,   554,     0,   495,
     470,   483,   485,     0,     0,   181,   204,     0,     0,     0,
     361,   361,     0,   115,   116,   233,     0,   224,   225,   322,
       0,   329,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   230,     0,   228,     0,     0,     0,     0,
     111,   112,   597,   603,   602,   150,     0,     0,     0,   350,
       0,     0,   108,   100,   102,     0,    90,   620,    97,    98,
      52,     0,     0,     0,     0,   517,     0,     0,   483,   578,
       0,     0,     0,     0,   124,   617,     0,   131,     0,     0,
       0,     0,   186,     0,     0,     0,   325,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     513,     0,   339,     0,     0,   316,     0,   241,     0,     0,
       0,     0,     0,     0,   229,     0,   563,   300,     0,     0,
     382,   233,   397,     0,   568,     0,    48,     0,     0,     0,
      65,    50,     0,   288,   123,   128,   134,     0,     0,   161,
     162,   160,     0,     0,   471,     0,     0,     0,     0,   362,
     375,     0,     0,   376,     0,   222,     0,   330,     0,   312,
       0,   233,     0,     0,     0,     0,     0,     0,   176,   113,
     296,   345,   106,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,   202,     0,   379,     0,   380,   381,
     512,     0,     0,   318,   244,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,    62,     0,     0,   125,     0,
       0,   326,     0,     0,   338,   317,   313,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,   248,     0,
     242,   352,    53,     0,    60,     0,   283,     0,   556,     0,
       0,   319,     0,     0,    54,     0,     0,   295,     0,     0,
     243,     0,     0,     0,     0,     0,     0,    57,    55,     0,
      58,     0,   377,   378,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   120,  1094,   121,   122,  1078,  1943,  1949,
    1377,  1595,  2105,  2233,  1378,  2206,  2249,  1379,  2235,  1380,
    1381,  1599,   450,   606,   607,  1163,  1691,   123,   803,   477,
    1961,  2116,  1962,   478,  1830,  1456,  1412,  1413,  1414,  1558,
    1766,  1767,  1233,  1653,  1644,  1840,   779,   618,   284,   285,
     360,   209,   286,   460,   461,   127,   128,   129,   130,   131,
     132,   133,   134,   287,  1267,  2140,  2197,   969,  1263,  1264,
     288,  1057,   289,   138,  1484,  1231,   942,   984,  2074,   139,
     140,   141,   142,   290,   291,  1189,  1204,  1332,   292,   808,
     293,   807,   480,   635,   328,  1803,   368,   369,   295,   576,
     378,  1361,  1586,   471,   466,  1325,  1033,  1634,  1796,  1797,
    1018,   473,   144,   428
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1937
static const yytype_int16 yypact[] =
{
   13350,    86,    62, 13554, -1937, -1937,   115,    66,     0,   -86,
     -62,   -51,    47,   216,   221,   252,   262,   117,   271,    48,
     132,   297,   407,   149,   166,    32,  -100,   585,  -100,   193,
     203,   217,    54,   228,   234,    57,   241,   250,   281,   328,
     363,   368,   371,   383,   389,   430,   267,   566,   689,   714,
     730,   436,   561,   632,   456,  6785,   491,   490,   606,   768,
     -61,   716,   585,    -6,   225,   533,   732,   -90,   619,  -150,
    -150,   622,     6,   355,   637, -1937, -1937, -1937, -1937, -1937,
     678,   434,   790,   809,    15,    53,   830,   843,   140,   849,
     978,   992,   994,  5773,   995,   -72,   -65,   745,    28,    64,
   -1937,   746,   747, -1937, -1937,   997,   998,   749, -1937, 13799,
     752, 13835,    19,    22,   585, -1937, -1937, -1937, 11931,   751,
   -1937, -1937, -1937, -1937, -1937,   750, -1937, -1937, -1937, -1937,
   -1937, -1937, -1937, -1937, -1937, -1937,   -38, -1937, -1937, -1937,
   -1937,    39, -1937,  1007,   773,  4907,   332,   778,  1033, 11931,
   13737, 13737, 13737, -1937, 11931, -1937, -1937, -1937, -1937, 13737,
   -1937, -1937, -1937, 11931, -1937, -1937, -1937, -1937,   777,   786,
    1034, -1937, -1937, 13871, -1937, -1937, -1937, -1937,   789,    32,
   11931, 11931, 11931,   791, 11931, 11931, 11931,   792, 11931, 11931,
   11931, 11931, 11931, 11931, 11931, 13737, 11931, 11931, 11931, 11931,
    5773,   793, -1937, -1937,  9558, -1937, -1937, -1937,   794,  5773,
    7038, 13737, -1937, -1937, -1937, -1937, -1937,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,   321,  -100,  -100,  -100,  -100,  -100,   795,  -100,
    -100,   796,   585,   643,   643, -1937, -1937, -1937,  -100,  -100,
      33,   853,   857,   862,   797,  7038,   921,   585,   585,   803,
    -100,  -100,   804,   806,   807, -1937, -1937, -1937, 11931,  7291,
   11931, 11931,  7544,    32,   868,    34, -1937, -1937,   808, -1937,
    3305, -1937, -1937, -1937, -1937, -1937,   118, 11931,  9558,  9558,
     811,   813,  7797,  5773,  5773,  5773, -1937, -1937, -1937,   814,
   -1937,   816,   821,  8050,   819, 10497,  1060,  7038,   820,    28,
     823,   824,  -150,  -150,  -150, 11931, 11931,   307, -1937,   405,
    -150, 10583,   423,   179,   822,   829,   832,   833,   834,   835,
     837,  9558, 11931,  5773,  5773,  5773,   248,    25,  1079,   836,
   -1937,  1088,  1089, -1937,   838,   839,   840, -1937, -1937,   841,
    5773,   842,   846,   848,   851, -1937, 11931,  6026, -1937,  1100,
    1106,   858, 11931,   859, 11931, 11931,   370, 11931,   856, -1937,
     924, 11931, 11931, 11931, -1937, -1937, 11931, -1937,  -100,  -100,
    -100,   864,   871,   882,  -100,  -100,  -100,  -100,  -100,  -100,
    -100, -1937,  -100, -1937, -1937, -1937, -1937,  -100,  -100,   883,
     903,  -100,   904, -1937,   906,  1154,  1155,   905, -1937, -1937,
    1159,  1158,  1161,  1162,   914,  -100, 11931, 15453,   131, 13737,
    9558, 11931, -1937, -1937,  7038,  7038, -1937,   912, 13871,   585,
    1165, -1937, -1937, -1937, -1937, -1937, -1937, 11931, 11931,    40,
    7038,  1167,   502,   915,   784,   916,  1170,    78,   918, -1937,
     922, 14098, 11931, -1937,  3053,  -134, -1937,    56,   -70,   -28,
    8490, -1937,   -13, -1937,    63, 12060,  8738,  -106,    98,  1082,
   -1937,    32,   919, 11931,   923, 15969, 15994, 16019, 11931, 16044,
   16069, 16094, 11931, 16119, 16144, 16169, 16194, 16219, 16244, 16269,
     929, 16294, 16319, 16344, 14554,  1179, 11931,  9558,  5707, -1937,
     343, 11931,  1182,  1183,   934, 11931, 11931, 11931, 11931, 11931,
   11931, 11931, 11931, 11931, 11931, 11931, 11931, 11931, 11931, 11931,
   11931,  9558, 11931, 11931, 11931, 11931, 11931, 11931, 11931, 11931,
    9558,  9558,   932, 11931, 11931, 13737, 11931, 13737,  7038, 13737,
   13737, 13737,   933,   936,   937, 11931,    27, -1937, 10836, 11931,
    7038,  5773,  7038, 13737, 13737,  9558,    32, 13871,    32,   939,
    9558,   939, -1937,   939, 16369, -1937,   386,   938,    91,  1130,
   -1937,  1190, 11931, 11931, 11931, 11931, 11931, 11931, 11931, 11931,
   11931, 11931, 11931, 11931, 11931, 11931,  8303, 11931, 11931, 11931,
   11931, 11931,    32, 11931, 11931,    52, -1937,   715, 16394,   427,
     520, 11931, 11931, 11931, -1937,  1193,  1194,  1194,   947, 11931,
   11931, 11931, 11931,  1198,  9558,  9558, 15481,   949,  1202, -1937,
     950, -1937, -1937,  -123, -1937, -1937,  8986,  9239,  -150,  -150,
     332,   332,  -111, 10583, 10583, 11931, 12119,   -73, -1937, 11931,
   11931, 11931, 11931, 11931, 11931, 11931, 11931, 11931,   534, 16419,
    1203,  1205,  1206, 11931, 11931,  1208, 11931, -1937, -1937, 11931,
   12221, -1937, -1937,  9558,  9558,  9558, 11931,  1209,  9558, 11931,
   11931, 11931, 16444,   952, -1937, -1937, 11931, 16469, 11931, 16494,
   16519,  1027,  9492, -1937,   958,  5960, 16544, 16569, 15564, 13737,
   13737, 13737, 13737, 13737, 13737, 13737, 13737, 13737, 11931, 13737,
   13737, 13737, 13737,     5, 13871, 13737, 13737, 13737,    32,    32,
   -1937, -1937,  9558, -1937,   962, 12280, -1937,   963, 12382, 11931,
   11931,   939, 11931, -1937,    32, 11931, 11931,    52,   960,   551,
   16594, 13997,   968,   567, 11931,  1219,   967,  7038, 16619, 15591,
   -1937, -1937, -1937, -1937, -1937,   966,  1221,   124,  1223, -1937,
   -1937, -1937,  9558,   180, 11931, -1937, -1937, -1937,    32, 11931,
   11931,    52,   973, -1937,   976,   -47,   585,    -6,   585, -1937,
     974, 14583, -1937,    31,  9558,    32, 11931, 11931,    52,  1228,
    9558,  1229,  9558, 11931,  1230, 13737,    32, 10922,    52, -1937,
   11931,  1231, -1937,    32,  1232, 13737, 11931,   986,   988, -1937,
   11931,  9837, 13871,  1239,  1240,  1241, 16644,  1242,  1243,  1244,
   16669,  1245,  1246,  1247,  1250,  1251,  1252,  1254, -1937,  1255,
    1256,  1258, -1937, 11931, 16694,  9558,  1001,  9558, 14612, -1937,
   -1937,  1261, 15537, 15537, 15537, 15537, 15537, 15537, 15537, 15537,
   15537, 15537, 15537, 10185, 15537, 15537, 15537, 15537,  2904,   539,
   15537, 15537, 15537, 10447, 10528, 10786, 10867, 11201,  5707,  1013,
    1012,   108,  9558, 11461, 11542,   539, 11795,   539,  1008,  1009,
    1010,    87,  9558, 11931, 11931, 17644, -1937,   539,  1011, 14641,
   14670, -1937, -1937,  1014,  -120,   539,  -122,  1021,   257,   569,
    1274, -1937,    52,   539,  7038,  1022,  6213,  6466,  1363,  1253,
     529,   529,   560,   560,   560,   560,   560,   560,   508,   508,
    9558,   -49, -1937,   -49,   -49,   939,   939,   939,  1023, 16719,
   15618,  -186,  9558, -1937,  1276,  1028,  1029, 16744, 16769, 16794,
   11931,  7038,  1282,  1284, 10249, 16819, 14699, 16844, 16869, -1937,
     575,   577,  9558,  1030, -1937, 12441, -1937, 12543, 12602,  -150,
   11931, 11931, -1937, -1937,  1032,  1037, 10583,  7225,  1152,   459,
    -150, 12704, 16894, 14728, 16919, 16944, 16969, 16994, 17019, 17044,
   17069,  1039,  1292, 11931,  1294, -1937, 11931, 17094, 14757, -1937,
   15645, 12763, 15672, -1937,   582,   583,   589, 14786, -1937,   591,
   15699, 15726, 11876, -1937, -1937, 17119,  1295, 17144,  1296,  1297,
    1040, 11931, 12865, 11931, 11931, -1937, -1937,    36,   -97,   197,
     -97,  1050,  1051,  1044,   539,   539,  1045, 13013,   539,   539,
     539,   539, 11931,   539,  1302, -1937,  1048,  1061,   259,   324,
    1058,   592, -1937, -1937, -1937, -1937, 17169, 15537,   -49, 12924,
    1057,   564,  1056,  1128,  1314,  1163, 11170,  1062,  1065,  1321,
    7038, 14815, -1937, 11931,  1323,   165,    97,    52,    30, 13871,
   11931,  1324, -1937,   594,  1283,  1285,  7038, 14844,    44,  1070,
   17194, 15753,   421, 11931, 11931,  1078,  1076,  1083,  1080,  8556,
   -1937, -1937, -1937, -1937, 13737,   201,  1081, 17219, 15780,  1086,
   -1937,   212, -1937,   263, 13145, -1937, -1937, -1937,  1084, -1937,
    1091, 13349, -1937,    90, -1937, -1937, 17644, -1937,    82, 15537,
   11931,   539,  -150,  7038,  7038,  1330,  7038,  7038,  7038,  1336,
    7038,  7038,  7038,  7038,  7038,  7038,  7038,  7038,  7038,  7038,
    3099,  1343,  9558,  5707, -1937, -1937, -1937, -1937, -1937, -1937,
   -1937, -1937, -1937, -1937, -1937, -1937, -1937, -1937, 11931, -1937,
   -1937, -1937, -1937, -1937, -1937, -1937, -1937, -1937, 11931, 11931,
   11931, 11931, 11931, -1937, -1937, -1937,   597, 11931, 11931, -1937,
   11931, -1937,  7038, 13737, 13737, -1937,   599, 14873, 14902,  1092,
   -1937, -1937, -1937,  1160, 11931, 11931, -1937, -1937, -1937,    52,
   -1937,    52, 11931, 11931,  1099, -1937,  7038,  -100, -1937, -1937,
   -1937, 11931, 11931,   602,    52,   739,   -42, 11931, 11931, -1937,
     539,   604,  7038,  9558,  9558,  1351,  1353,  1354,  5272, -1937,
   -1937,  1356, -1937,  1107, 17644,  1102,  1361, -1937,  1362,  1364,
    1366,  1367,   607,    74, -1937, 13026, -1937, -1937,   -55, 13738,
   13930, -1937, -1937, 14931,  -169,  1257,  1371, 11263,  1111,  1372,
    1122,    35,    43,   270, -1937,   -48, -1937,   459,  1373,  1375,
    1376,  1377,  1378,  1379,  1381,  1383,  1384,   332,  7038, 17644,
   -1937,  3157,  1133,  1293,  1387, -1937,  1389,  1390,  1290,  1392,
   -1937,  1393,  1396,  1397, 11931,  1404,  7038,  1405,  7038,  7038,
    1400, 14026, -1937,  6719,  2957,    52,    52, -1937,  9558, -1937,
   -1937, -1937, -1937, 13737, -1937, -1937, 11931, 13737, -1937, -1937,
   -1937, -1937, 17644, -1937,  1151,  1150, 13737, -1937, 13737, -1937,
      52, 13737,  1164, -1937,  1153,  1409, -1937,    52, 11931, 11931,
    1157,   585,  1168, 11511, -1937,  3479,  1169,  7038, -1937,  1166,
   -1937, 14960, -1937, -1937, 11931,  1413,   400, 11931,  1415,  1422,
      28,  1424,  1174,  1426,  3527, -1937,   539,  -100,  -100,  1427,
   -1937, -1937,  1180,  1181,  1175, -1937,  1431, -1937, -1937, -1937,
   -1937, -1937, -1937,    52,   431,  2301, 11931, 15807, 17244, 11931,
    8804, 11931,  9558,  1178,   610,  1436,   129,    52, -1937,  1184,
   11931,  1437,  1438, 11931,    52, 11597, 11931,  9806,   539,  5208,
   11931, 11931,  1189,  1185, -1937,  1442, 17269,  1444,   137,  1316,
    1316,  7038,  1446,  1447,  1449,  7038,   -79,  1451,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,  1459, -1937,  1461,   612, 15537,
   15537, 15537, 15537, 15537, 15537,   539, 14059, 14092, 14125,  1211,
     539,   539, -1937, -1937, -1937,    82,   539, 17294, 15537,  1212,
     178, 17644, 15537, -1937,  1463,   539, 17644, 17644, -1937,   555,
   -1937,    52, -1937, 17319, 15834, -1937,   539,  1465,   613,   620,
    7038,  7038,  7038,  1468,  1469, -1937,   191, 11931,  7038,  7038,
    7038,  1215,  1222,  1473,  1476,  1477, -1937, 11931, 11931, 11931,
    1224,  1249,  1259,  1248, -1937,  3978,  7038, -1937, 11931, -1937,
    1498, -1937,  1500, -1937, -1937, 10583,   317,  6279, -1937,  1260,
    1262,  1264,  1265,  1266,  1268,  9052,  1269,  1503, -1937,  9558,
    1271, -1937, -1937, -1937,  1272, 11931, 11931, -1937, -1937, 15861,
    7038,  1504,  7038,  1505,  1325, -1937, 11931, 11931, 11931, -1937,
    1506,   588,   342,  1270,  6972,  1277, 11931,    29,   539,  1286,
     539,  1279, -1937, -1937, 13871, -1937,   740, 11931,  1281, -1937,
   -1937,  4013, -1937, -1937,  1280,  1509, -1937,  4126, -1937,  1267,
    1510,   172,  4224, -1937,    28, -1937,   623, -1937, 11931, -1937,
   -1937,   191,  3855,  3531, -1937,  1278, 11931, 11931,  7038,  1287,
   -1937,   130,    92,  1514, 17344,  1532,  1274, 17369,  1288,   626,
   17394,   628,  1539,  1541, -1937, -1937, 13737,  1299,  1512, 17419,
   -1937, -1937, 14158,  1300, -1937,  7478,  5520, 17644, -1937,  1542,
    -100,  7544, -1937, -1937, -1937, 17644, 17644, -1937,    82, -1937,
    1544, -1937, -1937,  -150,  1545,  1550,  1552, -1937, -1937, -1937,
    1417,   -37,  1474,  1555, -1937, -1937, -1937, -1937, -1937, -1937,
   -1937, -1937, -1937,  1563,  1315, -1937, -1937, -1937, -1937, -1937,
   -1937, -1937, 11931, 11931, 11931, -1937, -1937, -1937,  1185, -1937,
   -1937, -1937, -1937, 11931,  1317,  1318, -1937, -1937, 11931, 11931,
     539,   739, -1937, -1937, -1937, -1937,  1319,  1326,  1574,   -79,
    1577, 11931, -1937,  7038, 17644,  1445,  1450,   818,  9558,  9558,
   11931, -1937, 10249, 14989, 17444,  7731,   332,   332, 11931, 11931,
   -1937,   908,  1327, 17469, -1937, -1937, 15018,     9, -1937,  1582,
    1587,  7038,  -150,  -150,  -150,  -150,  -150,  6532,  1588, -1937,
   -1937,   629,  9558, 11931,  4327,  4351,  1590,  1608, -1937,  1613,
   -1937,  7038,  7984,  2456, 17494, -1937, -1937,  9901, -1937, 13737,
   11931, -1937, 13737, 17644, 10154, 13871,  1357, -1937, -1937, -1937,
   -1937,  1368,  1358, 11931, 11931, 15047, 11931, 13997, -1937, 13997,
    7038, -1937, -1937,    52,    30, 13871, 11931,  1619, -1937,  1620,
   -1937,    28, 15888,  7038, 13737,  1621,   539, -1937,  1365,   539,
   11931, 14191, 14224,   631, -1937, 11931, 11931,  1374, -1937,  1382,
   -1937,  1354,  1624,  1625,  1364,  1626, -1937, -1937,  1628, 11931,
   -1937, -1937, 11931, 11845,  1629, 11931, -1937, -1937,  1385,  3531,
     634,  5247,  1630, -1937, -1937,   601, -1937, -1937, -1937,  1490,
    1632,  1386,  1388,  1391, -1937,  1635,  7038, 15537, 15537, 14257,
   15537, -1937,  1395, 17519, 15915, -1937, -1937,  9558,  9558, -1937,
    1637, -1937, 17644,  1640, 11931, 11931,  1394, -1937,   639,   642,
   15509,  4388,  1642,  1398, -1937, -1937, 11931,  1399,  1401, 15076,
   15942,  1643,  7038,  1645,  1403, 11931, -1937, -1937,   644,   185,
     200,   207,   231,   256,  9305,   258, -1937,  1648,   645, 15105,
   -1937, -1937, -1937, -1937, -1937,  1471, -1937, 11931, 11931, -1937,
   -1937,  9558,  4433,  1650,  1408, 15537,   539, 17644, -1937, -1937,
   -1937, -1937,    29, -1937, 13871, -1937, 15134,  1406,  1407,  1412,
    1653,  1662,  1663,  4469, -1937, -1937, -1937,  1418,  1674,   650,
   -1937,  1675,  1676,   300, 17644, 11931, 11931,  1425,  7038,   655,
   17644, 17544, -1937, -1937, -1937, -1937, 17569, 14290, -1937, -1937,
   15163,  1092,  1150,  7038,   539, -1937, 11931, 13871,    32, -1937,
   -1937,  9558,  9558, 11931,  1677,   658, -1937, -1937, 11931,  1318,
   -1937, -1937, -1937,   660,   661, -1937, -1937,  4571,  4830,  7038,
     461,   638,  9558, -1937, -1937,   332,  8237, -1937, -1937, -1937,
    1679, -1937,  1428,  7038, -1937, 15192,  1680,  9558,  -150,  -150,
    -150,  -150,  -150, -1937,  1681, -1937, 11931, 15221, 15250,   663,
   -1937, -1937, -1937, -1937, -1937, -1937,  1433,  1684,  1434, -1937,
    1686,    28, -1937, -1937, -1937,  1507, -1937, -1937, -1937, -1937,
   -1937, 11931, 14323, 14356,  7038, -1937,  1688, 11931,  1439, -1937,
   11931,  1689,  1441,  1443, -1937, -1937,  5454, -1937,  1462,   666,
     668, 15279, -1937,  1440, 14389,  1464, -1937,  1448, -1937, -1937,
     671,  1460,  -150,  7038,  1690,  1466,  -150,  1702,   679,  1467,
   -1937, 11931, -1937,  1704,  1569, 13085,  1470, -1937,   681,   265,
     288,   311,   338,   348, -1937,  4942, -1937, -1937,  1706,  1708,
   -1937, -1937, -1937,  1712, -1937,  1472, 17644, 11931, 11931,   687,
   -1937, 17644, 14422, -1937, -1937, -1937,  1092, 13871,  1479, -1937,
   -1937, -1937, 11931, 11931, -1937,  9558,  1715,  -150,   154, -1937,
   -1937,  -150,   171, -1937,  1716, -1937, 15308, -1937, 11931, -1937,
     459, -1937,  1717,  9558,  9558,  9558,  9558,  9305, -1937, -1937,
   -1937, 13997, -1937, 11931, 17594, 14455,    49, 11931,  1478, -1937,
   -1937, 14488, 14521,   688, -1937,   353, -1937,   361, -1937, -1937,
   -1937,  5142,   364, 13187, -1937,   693,   695,   698,   703,   393,
     704,  1480,   705, -1937, 11931, -1937,  7038, 15337, -1937, 11931,
   11931, -1937,  -150,  -150, -1937, -1937, -1937,   459,  1718,  1720,
    1724,  1726,  9558,  1727,  1730,  1731,  1482, 17619,   706,  1736,
   15366, 15537,   399,   415,   485, -1937, -1937, -1937, -1937,   712,
   -1937, -1937, -1937, 13737, -1937,  1484, -1937,  1738, -1937, 11931,
   11931, -1937,  1739,   719, -1937,  1488,  7038, -1937, 15395, 15424,
   -1937,  1743, 13737, 13737,   724,  1744,  1745, -1937, -1937,   729,
   -1937,  1746, -1937, -1937,  1747, 13737, -1937, -1937, -1937
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1937, -1937, -1937, -1937,   358, -1937, -1937, -1937, -1937,  -398,
   -1937, -1937, -1937, -1937, -1937, -1937, -1937, -1937, -1937, -1937,
   -1937, -1937,  -743,  -105,  4636,  3292,    42, -1937,  1289, -1937,
   -1937, -1937, -1937, -1937, -1937, -1936, -1937,   302,   120,  -202,
   -1937,  -161, -1937,    65,   345, -1937,  1759, -1937,    23,   -40,
   -1937, -1937,    -1,  -636,   -16, -1937, -1937, -1937, -1937, -1937,
   -1937, -1937,   685,  1763, -1937, -1937, -1937, -1937, -1255, -1260,
    1765, -1761,  1766, -1937, -1937, -1937,  1156, -1937,  -221, -1937,
   -1937, -1937, -1937,  2298, -1937, -1937, -1454,   210,  1769, -1937,
       3, -1937, -1937,   -59, -1937, -1723,   805,  -179,  2647,   312,
    -318,   -10, -1937,   860,   -94, -1937, -1937,    11,   183, -1717,
    -152,   983, -1937,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -580
static const yytype_int16 yytable[] =
{
     145,   630,   126,  1514,   964,   965,  1684,   472,  1888,   168,
     327,   329,  1516,   332,  1070,   415,  1927,   419,  1928,   347,
    1076,   505,   170,   313,   420,  2052,   125,   422,   169,   665,
     512,   168,   376,  1764,   168,   371,   168,  1091,   557,   580,
     451,  1509,   373,  1305,   750,   433,   301,  1920,  1371,  1511,
     178,   456,   296,   153,   161,  2185,   750,   352,   183,   353,
     301,   187,     5,  1651,  1841,   785,   445,   446,   380,  1217,
     302,  1218,   796,   318,   638,   639,   751,   752,  1494,   482,
     148,   351,   168,  1842,  1085,   306,  1409,   768,   751,   752,
     296,  1501,     4,   323,   324,   379,  1807,  1407,   307,   319,
     481,   308,   309,   310,  1353,   325,   416,   149,   348,   326,
     751,   752,  1964,  1652,   311,   320,   321,   602,  1410,  1411,
     638,   639,   783,  1975,   615,   616,   617,   602,   751,   752,
     784,  1069,   638,   639,  1198,  1615,   760,   424,   761,  1199,
     734,   959,   457,  1642,  1195,   459,   475,   467,   467,   467,
     753,   754,   801,   966,   354,   171,   474,   172,   802,   760,
    2166,   761,   753,   754,   660,   661,   662,   795,   453,   150,
     638,   639,  1353,   453,   453,   453,   484,  2168,   312,  1785,
    2158,   677,   453,   372,   753,   754,   789,  1074,   638,   639,
     374,   970,   467,   151,   790,   638,   639,   296,  1353,   599,
     600,   296,   753,   754,   152,   601,   296,   296,   467,  1497,
     445,   446,  1510,   553,   554,   349,  1515,   431,   453,  1471,
    1512,   432,   155,  1372,  1373,  1374,  1375,   156,   791,   755,
     756,  1852,   119,  1765,   453,    99,   792,   100,   101,   102,
     103,   104,   119,   794,   357,   108,   109,   358,   111,   323,
     324,   795,   638,   639,   119,   119,  1514,   119,   157,   119,
     359,   325,   296,   633,   634,   331,  2070,  1032,   158,  1092,
    1093,   642,   647,  1885,   350,   552,   296,   160,   421,   296,
     578,   423,   666,   760,   667,   761,   577,   377,   147,  1360,
     561,   562,   558,   581,   434,   296,   296,  1306,   435,   296,
     296,   296,   296,   164,  1376,   119,   154,   162,  2186,   184,
     296,   786,   188,   787,   296,   646,   379,   788,   797,   381,
     787,  2109,  1354,  1357,   798,   441,   442,   443,   444,   314,
     445,   446,   315,   769,   670,   770,   458,  -572,   296,   771,
     296,   296,   296,  1185,   745,   171,   171,   172,   172,   445,
     446,   795,   441,   442,   443,   444,   804,   296,  1356,   333,
     445,   446,   802,   603,   296,   604,  1175,  1092,  1093,   605,
     445,   446,   159,   603,   146,   604,   445,   446,   147,   605,
     638,   639,   891,   445,   446,  1806,   735,  1774,   736,  -576,
    2181,   163,   737,   441,   442,   443,   444,   638,   639,   881,
     441,   442,   443,   444,   750,   725,   166,   728,   441,   442,
     443,  1075,  1256,   165,   638,   639,   741,   445,   446,   441,
     442,   443,   444,   167,   445,   446,   467,   296,   638,   639,
    1257,   296,   296,   171,   649,   172,   751,   752,   650,  1258,
    1259,  1260,  1202,   638,   639,  1261,  1262,   296,   180,  2007,
     638,   639,   453,   760,   772,   761,   334,  1396,   181,  1256,
     335,  1308,   746,  2208,  2008,   837,   336,   337,  1401,   338,
     339,  2009,   182,   897,   638,   639,   837,  1257,   809,    68,
      69,    70,    71,   185,   780,    74,  1258,  1259,  1260,   186,
     340,   757,  1261,  1262,    83,  2010,   189,    86,   780,   638,
     639,   638,   639,   663,   296,   190,  1256,   664,   638,   639,
     753,   754,   171,  2244,   172,   760,   510,   761,  1201,  1402,
    2011,  1202,  2012,  1328,  1257,  2065,   199,   837,   296,  2143,
    1513,   638,   639,  1258,  1259,  1260,   191,   296,   871,  1261,
    1262,   343,   467,   344,   467,   296,   467,   467,   474,  1020,
     638,   639,  2144,   887,   638,   639,  2040,   296,   296,   296,
     467,   467,   296,   170,  2041,   170,   640,   296,   453,   896,
     453,   898,   453,   453,   453,  2145,   540,  1728,   541,   962,
     963,   638,   639,   192,   634,  1330,   453,   453,  1331,  1579,
    1580,   638,   639,   296,  1756,  1757,   638,   639,   760,   928,
     761,  1256,  2146,   836,   638,   639,   837,   837,  2071,  2072,
     609,   610,  2147,   955,  2073,   957,   958,  2192,   193,  1257,
    1035,   296,   296,   194,  2195,  2193,   195,  1256,  1258,  1259,
    1260,   691,   971,   147,  1261,  1262,   638,   639,   196,   459,
     459,  1526,   638,   639,   197,  1257,   901,   931,   638,   639,
     837,   991,  1071,   658,  1258,  1259,  1260,  2202,   638,   639,
    1261,  1262,   205,  2229,   641,   206,   638,   639,   207,   780,
     296,   296,   296,   445,   446,   296,  1386,  1012,  1339,  2230,
    -575,   208,   648,   445,   446,   198,   174,   935,   200,   175,
    -574,   837,   176,   780,   177,   204,   474,   467,   474,   467,
     467,   467,   467,   467,   467,    46,   467,   467,   467,   467,
    1034,   211,   467,   467,   467,   170,  1040,  1049,  1121,   296,
     202,  1039,   453,   453,   453,   453,   453,   453,   453,   453,
     453,  1050,   453,   453,   453,   453,   203,  1087,   453,   453,
     453,   210,   739,  1703,   296,  2231,   297,   307,   780,   298,
     308,   780,   310,   732,   597,   598,   599,   600,   760,   296,
     761,   762,   601,   311,   780,  1079,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,  1051,
     936,   296,  1096,   601,   837,  2075,  2076,   296,   316,   296,
     765,  2073,   474,  1108,   981,   760,   201,   761,   837,  1086,
    1113,  1088,   467,   594,   595,   732,   597,   598,   599,   600,
    1688,  1053,  1689,  1082,   601,   837,   445,   446,   453,  1338,
     303,  1339,  1866,   304,  1867,   305,  1219,  1059,   453,  1205,
    1099,  1060,   296,   837,   296,  1240,   317,  1241,  1786,   837,
    1110,   837,  1287,  1288,   638,   639,   837,   837,  1793,  1289,
    1235,  1291,  1334,   837,  1366,   837,   837,  1445,   837,  1452,
     294,   837,  1468,   837,  1476,   299,   837,  1493,   837,   296,
    1613,   837,  1664,  1696,   837,   300,   837,   837,   322,   296,
    1697,   330,   899,  1790,   837,  2172,  1813,  1791,  1815,  1897,
     837,  1947,   837,   837,  1965,  1948,   341,   345,  1966,  1990,
    1248,   296,  1991,   837,  2006,  2014,   837,  1254,  1948,   837,
    2037,  1265,  1514,   346,   795,  2046,   582,   296,  2063,  2047,
    2066,  2067,  1948,  2098,   837,   837,  2119,   837,  2120,   296,
     837,  2126,   837,   342,   355,  1948,   950,   951,   296,  2134,
    1245,  2142,  2214,   837,  1207,   837,  1219,  2156,  2191,   296,
     356,  1948,   837,  2198,  1514,  2199,   361,   837,  2200,   837,
    1355,  1358,   837,  2201,  2203,  2205,  2225,   837,   837,  2047,
    1948,   760,  2232,   761,   932,  1363,   837,  1219,   780,  2241,
     780,   780,   362,  2242,  2251,   994,   995,   996,  1948,  2254,
     999,   445,   446,  2255,   780,  1773,   363,  1774,   364,   370,
     375,   382,   383,   384,   385,   455,   386,   417,   429,   430,
     465,   468,   469,   436,   780,   513,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,  1041,   780,   437,   462,   601,   463,
     147,   479,  1585,   481,   483,  -206,   488,   492,   506,  -207,
     548,   551,   560,   511,  -208,   500,   559,   296,   563,   566,
     579,   567,   568,  1418,   627,  1362,   611,   432,   612,   619,
     294,   514,   780,   296,  1073,   620,   621,   651,   624,   629,
    1877,  1878,   631,   632,   652,   668,   296,   653,   654,   655,
     656,   467,   657,   669,   671,   672,  1095,   673,   674,   675,
     676,   678,  1101,   679,  1103,   680,   684,   614,   681,  1359,
    1470,  1472,   685,   686,   688,   693,   694,   453,   623,   702,
     296,   296,   628,   296,   296,   296,   703,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   704,   715,   296,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   716,   718,
     720,   721,   601,   719,   722,   723,   724,   726,  1881,   729,
     727,   744,   747,   759,   764,   766,   767,   146,   806,   296,
     467,   467,   773,   810,  1176,   828,   833,   812,   839,   840,
     841,   872,   882,   601,  1186,   883,   884,   904,   905,   902,
     940,   941,   944,   296,   949,   953,   453,   453,   954,   956,
     983,   985,  1004,   986,   989,   998,  1010,  1013,  1052,   296,
     296,   296,  1042,  1044,  1058,  1062,  1063,  1067,  1068,  1072,
    1083,  1084,  1213,  1089,  1100,  1102,  1105,  1112,  1114,   742,
     743,  1459,  1117,  1460,  1221,  1118,  1122,  1123,  1124,  1126,
    1127,  1128,  1130,  1131,  1132,   758,  1469,  1133,  1134,  1135,
    1142,  1136,  1137,  1138,  1242,  1139,  1789,  1146,   780,  1173,
    1174,  1191,  1182,  1183,  1184,   296,   459,  1200,  1194,  1470,
    1472,  1206,  1210,  1222,  1214,  1495,  1230,  1223,  1224,   738,
    1232,  1243,  1251,   296,  1255,   296,   296,  1252,  1277,  1278,
    1280,  1300,  1296,  1298,  1299,   296,  1311,  1312,  1313,  1316,
     467,  1324,  1326,  1628,   467,  1633,  1333,  1327,  1337,  1340,
    1341,  1342,  1346,   467,  1347,   467,  1343,  1348,   467,  1352,
    1365,  1383,  1367,  1389,  1368,  1390,   453,  1421,  1391,  1392,
     453,  1400,  1397,  1425,   296,  1404,  1405,  1550,  1551,   453,
    1437,   453,  -209,   878,   453,  1463,  1455,   379,  1480,  2079,
    1481,  1482,  1485,  1486,  1568,   614,  1487,   892,  1488,  1489,
    1506,  1490,  1561,  1491,  1492,  1503,  1502,  1508,  1507,  1566,
    1517,  1518,   467,  1519,  1520,  1521,  1522,   296,  1523,   296,
    1524,  1525,  1529,  1531,  1530,  1532,  1533,  1534,  1581,  1535,
    1536,  1394,  1537,  1538,  1545,   875,   296,   877,   453,   879,
     880,  1540,  1542,  1556,  1557,  1565,  1567,  1564,   296,  1578,
    1563,  1583,   296,   893,   894,  1601,  1575,  1569,  1573,  1584,
    1587,  1588,  1589,  1594,  1598,  1596,  1597,  1600,  1612,  1617,
    1798,  1798,  1614,  1620,  1621,  1618,  1623,  1637,  1639,  1638,
    1641,  1643,  1647,  1648,  1438,  1649,  1727,  1654,  1655,  1656,
    1657,  1658,  1659,  1660,  1661,  1662,  1663,  1675,  1682,  1686,
    1772,  1695,  1701,  1936,  1708,  1702,  1787,   296,   296,   296,
    1710,  1709,  1711,  1716,  1712,   296,   296,   296,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,   296,  1724,  1719,  1725,   601,  1717,  1740,
    1748,  1750,  1755,  1751,   296,  1781,  1820,  1784,  1718,  1731,
    1808,  1732,   296,  1733,  1734,  1735,   296,  1736,  1783,  1739,
    1742,  1743,  1827,  1800,  1759,  1478,  1479,   296,  1810,   296,
    1776,  1762,  1769,  1331,  1780,  1816,  1805,  1817,  1812,  1828,
    1834,  1836,  1064,  1777,  1819,  1823,  1837,  1779,  1838,  1839,
    1019,  1844,  1021,  1022,  1023,  1024,  1025,  1026,  1845,  1028,
    1029,  1030,  1031,  1851,  1846,  1036,  1037,  1038,  1857,  1843,
    1859,   379,  1202,  1861,  1835,  1858,  1856,  1864,  1886,   474,
     474,  1882,  1865,  1887,  1896,   296,  1902,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,   467,  1903,   453,   453,   601,  1872,  1904,
    1552,  1922,  1924,   296,  1923,  1934,  1935,  1940,   296,   795,
    1952,  1953,  1954,  -579,  1955,  1959,  1969,  1968,  1970,   453,
    1974,  -577,  1939,  1985,  1963,  1971,  1986,  1972,  1994,  2001,
    1973,  1980,  2003,  1989,  2013,  1106,  2021,  1995,  2016,  1997,
    2031,  1998,  2004,  1913,  2022,  1115,  2028,  2029,  2032,  2033,
    1918,  1921,  2030,  1889,  1890,  1891,  1892,  1893,  1895,  2035,
    2036,  2038,  2039,  2062,  2044,  2082,  2087,  2094,  2083,  2099,
    2100,  1932,  2102,  2101,  2110,  2113,  2130,  2104,  -578,  2122,
     296,  2114,  1609,  2115,  1611,   296,   296,  2125,  2133,  1209,
    2137,  2138,  2149,  2103,  2150,   459,   459,  2118,  2152,  2127,
    2124,  2164,  2169,  2174,  2215,  2131,  2216,  2135,   296,  2141,
    2217,  2153,  2218,  2220,   296,  2160,  2221,  2222,  2188,   296,
    2204,  2223,  2226,  2236,  2237,  2240,  1229,  2243,   296,  2247,
    2252,  2253,  2256,  2257,  1616,  2182,   467,  1678,  1833,   467,
    2053,  2025,   124,  1382,  1860,  1645,   135,   805,   136,   137,
    2077,  1771,   143,   943,  1931,  1919,  1799,   296,  1107,     0,
       0,  1362,   453,     0,     0,   453,     0,     0,   379,     0,
     296,   474,     0,     0,     0,     0,     0,     0,     0,     0,
     780,     0,   780,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   453,     0,     0,
       0,     0,     0,     0,     0,  1930,   474,     0,     0,     0,
    2026,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1741,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,   453,     0,   296,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1349,     0,     0,     0,     0,
       0,     0,     0,  2057,     0,     0,     0,     0,     0,   296,
       0,  1369,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1419,  1420,
       0,  1422,  1423,  1424,     0,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,   296,     0,     0,     0,  2089,
    2090,  2091,  2092,  2093,  1395,     0,     0,     0,     0,     0,
     296,     0,     0,     0,     0,  2058,     0,     0,   296,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   296,  1449,  2085,   296,
       0,     0,     0,     0,   459,     0,     0,     0,     0,     0,
     296,     0,     0,     0,   296,     0,     0,     0,     0,     0,
       0,  1464,     0,  2128,     0,     0,     0,  2132,     0,     0,
    1868,  1869,     0,  2159,     0,     0,     0,  1477,   379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,     0,  1450,  1451,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1898,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2165,     0,
     296,     0,  2167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1527,     0,  2151,     0,     0,  2179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1541,     0,  1543,  1544,     0,     0,     0,   780,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   296,     0,     0,  2173,     0,     0,     0,     0,
       0,     0,     0,  2212,  2213,     0,     0,     0,     0,     0,
     296,   296,   296,   296,   296,     0,     0,     0,     0,     0,
       0,     0,  1574,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1983,
    1984,     0,     0,  1553,   780,     0,     0,  1555,     0,     0,
       0,     0,     0,   296,     0,     0,  1559,     0,  1560,     0,
       0,  1562,     0,     0,     0,     0,   780,     0,     0,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1632,     0,     0,     0,     0,     0,
     467,     0,     0,  2019,     0,     0,  1646,     0,     0,     0,
    1650,     0,     0,   296,     0,     0,     0,     0,     0,   467,
     467,     0,     0,     0,     0,  1603,   453,     0,     0,     0,
       0,     0,   467,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   453,   453,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   453,     0,
       0,     0,     0,  2059,  2060,  1698,  1699,  1700,     0,     0,
       0,     0,     0,  1705,  1706,  1707,     0,     0,     0,     0,
       0,     0,     0,     0,  2078,   168,   387,     0,     0,     0,
       0,  1722,     0,     0,     0,     0,     0,     0,     0,  2088,
       0,     0,  1730,     0,     0,     0,     0,     0,     0,     0,
    1738,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1747,     0,  1749,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,     0,
       0,     0,     0,   397,   398,   399,   400,     0,     0,     0,
       0,   401,   402,   403,   404,     0,     0,     0,     0,   405,
       0,   406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   407,     0,     0,   408,     0,
       0,     0,   174,  1804,     0,   175,     0,     0,   176,     0,
     177,     0,     0,     0,     0,     0,   427,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1826,     0,     0,     0,     0,     0,  2163,     0,   439,
       0,     0,     0,   454,     0,     0,     0,   464,     0,     0,
       0,     0,   470,     0,     0,  2175,  2176,  2177,  2178,  2180,
       0,   476,     0,     0,  1908,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1818,     0,   485,   486,
     487,     0,   489,   490,   491,     0,   493,   494,   495,   496,
     497,   498,   499,     0,   501,   502,   503,   504,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,  1863,   409,
     410,   411,     0,     0,  2219,     0,     0,     0,     0,     0,
       0,   412,     0,     0,     0,   413,     0,   414,   119,     0,
       0,     0,     0,     0,     0,     0,  1804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   445,   446,     0,  1905,     0,     0,     0,
    -573,     0,  1602,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   569,   571,   573,   574,
     508,     0,     0,     0,     0,  1929,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,   508,   508,  1938,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   626,     0,     0,     0,     0,     0,  1914,
       0,     0,  1916,   636,   637,     0,     0,     0,     0,   637,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1804,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   682,   508,     0,     0,     0,     0,
     687,     0,   689,   690,     0,   692,     0,     0,     0,   695,
     696,   697,     0,     0,   698,     0,     0,  2002,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  1909,     0,     0,     0,
       0,     0,     0,     0,   731,     0,     0,     0,   508,   740,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   748,   749,     0,     0,     0,
       0,     0,     0,  2045,     0,     0,     0,     0,     0,     0,
     781,     0,     0,     0,     0,     0,     0,     0,  2054,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   811,     0,     0,     0,     0,   816,     0,     0,     0,
     820,     0,     0,     0,  1804,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   834,   571,     0,     0,  2084,   838,
       0,     0,     0,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   858,
     860,   861,   862,   863,   864,   865,   866,   867,   868,   868,
       0,   873,   874,     0,   876,     0,     0,     0,     0,  1804,
       0,   509,     0,   885,     0,     0,   889,   890,     0,     0,
       0,     0,     0,   868,     0,     0,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2129,     0,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   921,   923,   924,   925,   926,   927,
       0,   929,   930,     0,     0,     0,     0,     0,     0,   937,
     938,   939,   582,     0,     0,     0,     0,   945,   946,   947,
     948,     0,   508,   508,     0,     0,   572,     0,     0,   509,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   569,   731,   967,     0,   509,   509,   972,   973,   974,
     975,   976,   977,   978,   979,   980,     0,     0,     0,     0,
       0,   987,   988,     0,   990,  1548,     0,   992,     0,     0,
       0,   508,   508,   508,   997,     0,   508,  1000,  1001,  1002,
       0,     0,     0,     0,  1005,     0,  1007,     0,   509,     0,
       0,  1804,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1027,     0,     0,     0,
       0,     0,     0,     0,   509,     0,     0,     0,     0,     0,
     508,     0,     0,     0,     0,     0,     0,  1046,  1047,     0,
    1048,     0,     0,   929,   930,     0,     0,     0,     0,     0,
       0,  1804,  1061,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   782,
     508,     0,  1077,     0,     0,     0,     0,  1080,  1081,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,     0,
       0,     0,   508,  2234,  1097,  1098,     0,     0,   508,     0,
     508,  1104,     0,     0,     0,  1097,     0,     0,  1111,     0,
       0,     0,  2248,  2250,  1116,  1436,     0,     0,  1119,     0,
       0,     0,     0,     0,     0,  2258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1140,     0,   921,     0,  1143,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   835,
     597,   598,   599,   600,   572,     0,     0,     0,   601,     0,
     760,     0,   761,  1528,     0,     0,     0,     0,     0,     0,
     508,     0,     0,     0,     0,     0,     0,     0,   859,     0,
     508,  1187,  1188,     0,     0,     0,     0,   869,   870,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,   895,  1549,     0,     0,     0,   509,   508,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     508,     0,     0,     0,     0,     0,     0,     0,  1228,     0,
       0,     0,  1234,   922,     0,     0,     0,     0,     0,     0,
     508,     0,     0,     0,     0,     0,     0,     0,  1249,  1250,
       0,     0,     0,     0,  1253,     0,     0,     0,     0,     0,
       0,   509,   509,     0,     0,     0,     0,     0,     0,     0,
       0,  1279,     0,     0,  1281,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,  1301,
       0,  1303,  1304,   582,     0,     0,     0,     0,     0,     0,
     509,   509,   509,     0,     0,   509,     0,     0,     0,     0,
    1322,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,  1345,     0,     0,     0,     0,     0,
       0,  1351,     0,     0,     0,     0,     0,     0,  1364,   509,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1387,  1388,     0,     0,     0,     0,   508,     0,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,   509,
       0,   601,     0,     0,     0,     0,     0,     0,  1416,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0,     0,     0,     0,   509,     0,   509,
     508,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1440,  1441,  1442,  1443,
    1444,     0,     0,     0,     0,  1446,  1447,     0,  1448,     0,
       0,     0,   922,     0,  1144,  1572,     0,     0,     0,     0,
       0,     0,  1457,  1458,     0,     0,     0,     0,     0,     0,
    1461,  1462,     0,     0,     0,     0,     0,     0,     0,  1466,
    1467,     0,     0,     0,     0,  1473,  1474,     0,     0,   509,
       0,   508,   508,     0,     0,     0,     0,     0,     0,   509,
       0,     0,     0,  1590,     0,   168,   387,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,  1505,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
     388,   389,   390,   391,   392,   393,   394,   395,   396,     0,
       0,     0,  1539,   397,   398,   399,   400,     0,     0,   509,
       0,   401,   402,   403,   404,     0,   508,     0,     0,   405,
       0,   406,     0,     0,  1554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   407,     0,     0,   408,     0,
       0,     0,   174,     0,     0,   175,  1473,  1474,   176,     0,
     177,  1571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,  1577,     0,     0,  1582,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1604,     0,     0,  1607,   508,  1610,
     508,     0,     0,     0,     0,     0,     0,     0,  1619,     0,
       0,  1622,     0,  1619,  1625,  1627,     0,     0,  1635,  1636,
       0,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,   509,     0,     0,   409,
     410,   411,     0,     0,   763,     0,     0,     0,     0,     0,
       0,   412,     0,     0,     0,   413,     0,   414,   119,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,  1704,     0,     0,     0,   509,
    1794,     0,     0,     0,     0,  1713,  1714,  1715,     0,     0,
       0,     0,     0,     0,  1721,     0,  1723,     0,     0,     0,
       0,     0,     0,  1726,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,     0,     0,
       0,     0,     0,  1744,  1745,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1752,  1753,  1754,     0,   886,     0,
       0,     0,     0,     0,  1763,     0,     0,     0,     0,   168,
     387,     0,     0,     0,     0,  1775,     0,     0,     0,     0,
     509,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1792,     0,     0,     0,
       0,     0,     0,     0,  1801,  1802,     0,     0,     0,   933,
       0,     0,     0,     0,   388,   389,   390,   391,   392,   393,
     394,   395,   396,     0,     0,     0,     0,   397,   398,   399,
     400,     0,     0,     0,     0,   401,   402,   403,   404,  1831,
       0,     0,     0,   405,     0,   406,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
       0,     0,   408,     0,     0,   509,   174,     0,     0,   175,
       0,     0,   176,     0,   177,     0,     0,     0,     0,     0,
    1847,  1848,  1849,     0,     0,    46,     0,     0,     0,     0,
       0,  1850,     0,     0,  1720,     0,  1853,  1854,     0,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,  1862,
       0,     0,     0,     0,     0,     0,   508,   508,  1870,     0,
    1871,     0,     0,     0,     0,     0,  1879,  1880,     0,  1778,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,   509,     0,   509,
     508,  1899,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1912,     0,     0,  1915,     0,
       0,     0,  1917,   409,   410,   411,     0,     0,     0,     0,
       0,  1853,  1854,     0,  1926,   412,     0,     0,     0,   413,
       0,   414,   119,     0,  1933,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1944,     0,
       0,     0,     0,  1950,  1951,     0,     0,     0,     0,     0,
       0,   760,     0,   761,  1794,     0,     0,  1956,     0,     0,
    1957,  1956,     0,  1960,     0,     0,     0,     0,     0,     0,
       0,     0,  1782,     0,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,     0,  1159,  1160,  1161,  1162,
       0,  1164,  1165,  1166,  1167,   508,   508,     0,     0,     0,
       0,     0,  1987,  1988,     0,     0,     0,  1179,     0,  1181,
       0,     0,     0,     0,  1996,     0,   509,     0,     0,  1190,
       0,     0,     0,  2005,     0,     0,  1196,  1197,     0,     0,
       0,     0,   571,     0,     0,  1208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2017,  2018,     0,     0,   508,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
    1788,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2042,  2043,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,  2056,     0,     0,   601,     0,   508,
     508,  2061,     0,     0,     0,     0,  2064,     0,  1832,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     508,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
    1307,  1309,  1310,     0,  2095,     0,  1314,  1315,     0,     0,
    1318,  1319,  1320,  1321,     0,  1323,     0,     0,     0,     0,
    1329,     0,     0,  1900,     0,     0,     0,     0,     0,  2106,
       0,     0,     0,     0,     0,  2111,     0,     0,  2112,     0,
       0,     0,     0,     0,     0,   509,   509,  1901,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,  2136,
     601,     0,     0,     0,   509,     0,     0,     0,     0,   509,
       0,     0,     0,     0,  1993,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2154,  2155,     0,     0,     0,
       0,  1415,     0,  1417,     0,     0,     0,     0,     0,     0,
    2161,  2162,     0,   508,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2171,     0,     0,  2020,
       0,   508,   508,   508,   508,   508,     0,     0,     0,     0,
       0,  1950,     0,     0,     0,  2187,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,  2034,     0,     0,   601,     0,
       0,     0,  2207,     0,     0,     0,     0,  2210,  2211,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     508,     0,     0,     0,   509,   509,     0,     0,     0,     0,
       0,     0,  1475,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2238,  2239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   572,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,  2068,     0,     0,
       0,   601,     0,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,   509,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,   509,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   509,     0,     0,     0,  1591,     0,
       0,     0,   173,     0,   179,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1629,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,  1665,  1666,  1667,  1668,  1669,  1670,  1671,     0,     0,
       0,     0,  1676,  1677,     0,     0,     0,     0,  1679,     0,
    1681,     0,     0,     0,  1685,     0,     0,  1687,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1694,     0,
       0,     0,   509,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,     0,     0,     0,     0,     0,     0,
     509,   509,   509,   509,   509,     0,     0,     0,     0,     0,
       0,     0,     0,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2069,     0,     0,     0,
       0,     0,     0,     0,  1758,     0,  1761,     0,     0,   509,
    1768,     0,  1770,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   542,   543,
     544,   545,   546,   547,  1795,   549,   550,     0,     0,     0,
       0,     0,     0,     0,   555,   556,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   564,   565,     0,     0,
     212,   168,   387,     0,   438,     0,     0,   213,   214,   215,
       0,     0,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   425,
     234,   235,   236,   237,   238,   239,   240,   241,  2148,     0,
       0,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   247,   248,   249,   250,   397,
     398,   399,   400,   251,     0,     0,     0,   401,   402,   403,
     404,     0,  1855,     0,     0,   405,     0,   406,   255,   256,
     257,     0,     0,     0,     0,     0,     0,     0,     0,   258,
      25,   407,   259,     0,   408,     0,     0,     0,   174,     0,
       0,   175,     0,     0,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,   699,   700,   701,    46,     0,     0,
     705,   706,   707,   708,   709,   710,   711,     0,   712,     0,
       0,     0,     0,   713,   714,   439,     0,   717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   730,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,  1941,     0,
       0,  1942,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   440,     0,     0,
       0,     0,     0,     0,   269,   409,   410,   411,   270,     0,
       0,     0,     0,     0,   272,   273,   274,   412,   275,   276,
     277,   413,     0,   414,   119,   441,   442,   443,   444,  1976,
    1977,     0,  1979,     0,     0,     0,     0,     0,  2194,     0,
     278,   426,     0,     0,     0,     0,     0,   280,     0,   445,
     446,     0,   447,     0,   448,     0,     0,     0,   449,   283,
       0,     0,     0,     0,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2023,  2024,     0,
       0,   212,     6,   387,   903,     0,     0,     0,   213,   214,
     215,     0,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,  1967,   582,  2055,  1630,   389,   390,
     391,   392,   393,   394,   395,   396,   247,   248,   249,   250,
     397,   398,   399,   400,   251,   252,     0,     0,   401,   402,
     403,   404,     0,     0,   253,   254,   405,     0,   406,   255,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     258,    25,   407,   259,     0,   408,     0,     0,     0,   260,
       0,     0,   261,     0,     0,   262,     0,   263,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,    57,    58,     0,   266,     0,   267,     0,     0,   268,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1483,   269,   409,   410,   411,   270,
     271,     0,     0,     0,     0,   272,   273,   274,   412,   275,
     276,   277,   413,     0,   414,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,     0,     0,     0,     0,     0,   280,     0,
       0,  2117,     0,   366,     0,     0,     0,  1631,     0,     0,
     283,     0,     0,     0,     0,     0,     0,     0,     0,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   835,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,  2228,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,   212,     6,   387,   601,     0,     0,     0,
     213,   214,   215,     0,  1203,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,  1220,     0,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   247,   248,
     249,   250,   397,   398,   399,   400,   251,   252,     0,     0,
     401,   402,   403,   404,     0,     0,   253,   254,   405,     0,
     406,   255,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   258,    25,   407,   259,     0,   408,     0,     0,
       0,   260,     0,     0,   261,     0,     0,   262,     0,   263,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,     0,    57,    58,     0,   266,     0,   267,     0,
       0,   268,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,   582,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   409,   410,
     411,   270,   271,     0,     0,     0,     0,   272,   273,   274,
     412,   275,   276,   277,   413,     0,   414,   119,     0,  1408,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,     0,     0,     0,     0,     0,
     280,     0,     0,     0,     0,   366,   212,     6,   365,   282,
       0,     0,   283,   213,   214,   215,     0,     0,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   248,   249,   250,     0,     0,     0,     0,   251,
     252,     0,     0,  1465,     0,     0,     0,     0,     0,   253,
     254,     0,     0,     0,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   258,    25,     0,   259,     0,
       0,     0,     0,     0,   260,     0,     0,   261,     0,     0,
     262,     0,   263,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,    57,    58,     0,   266,
       0,   267,     0,     0,   268,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   835,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,  1014,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,   270,   271,     0,     0,     0,     0,
     272,   273,   274,     0,   275,   276,   277,     0,     0,     0,
     119,     0,     0,  1592,  1593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,   279,     0,     0,
       0,     0,     0,   280,     0,     0,     0,     0,   366,   212,
       6,     0,   367,     0,   683,   283,   213,   214,   215,     0,
       0,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,   249,   250,     0,     0,
       0,     0,   251,   252,     0,     0,  1683,     0,     0,     0,
       0,     0,   253,   254,     0,  1690,     0,   255,   256,   257,
       0,     0,     0,     0,     0,     0,     0,     0,   258,    25,
       0,   259,     0,     0,     0,     0,     0,   260,     0,     0,
     261,     0,     0,   262,     0,   263,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,    57,
      58,     0,   266,     0,   267,     0,     0,   268,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,  1211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,     0,     0,     0,   270,   271,     0,
       0,     0,     0,   272,   273,   274,     0,   275,   276,   277,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1829,     0,     0,   278,
     507,     0,     0,     0,     0,     0,   280,     0,     0,     0,
       0,   366,   212,     6,  1729,     0,   575,     0,   283,   213,
     214,   215,     0,     0,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
     250,     0,     0,     0,     0,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   253,   254,     0,     0,     0,
     255,   256,   257,     0,     0,     0,     0,     0,     0,     0,
       0,   258,    25,     0,   259,     0,     0,     0,     0,     0,
     260,     0,     0,   261,     0,     0,   262,     0,   263,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     265,     0,    57,    58,     0,   266,     0,   267,     0,     0,
     268,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    83,     0,     0,    86,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,  1212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   269,     0,     0,     0,
     270,   271,     0,     0,     0,     0,   272,   273,   274,     0,
     275,   276,   277,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   279,     0,     0,     0,     0,     0,   280,
       0,     0,     0,     0,   366,   212,     6,     0,   282,     0,
       0,   283,   213,   214,   215,     0,     0,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,   250,     0,     0,     0,     0,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
       0,     0,     0,   255,   256,   257,     0,     0,     0,     0,
       0,     0,     0,     0,   258,    25,     0,   259,     0,     0,
       0,     0,     0,   260,     0,     0,   261,     0,     0,   262,
       0,   263,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,    57,    58,     0,   266,     0,
     267,     0,     0,   268,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,  1547,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,   270,   271,     0,     0,     0,     0,   272,
     273,   274,     0,   275,   276,   277,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   643,  1894,     0,     0,     0,
       0,     0,   280,     0,     0,     0,     0,   645,   212,     6,
       0,   326,   575,     0,   283,   213,   214,   215,     0,     0,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   247,   248,   249,   250,     0,     0,     0,
       0,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,     0,     0,     0,   255,   256,   257,     0,
       0,     0,     0,     0,     0,     0,     0,   258,    25,     0,
     259,     0,     0,     0,     0,     0,   260,     0,     0,   261,
       0,     0,   262,     0,   263,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,    57,    58,
       0,   266,     0,   267,     0,     0,   268,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,   270,   271,     0,     0,
       0,     0,   272,   273,   274,     0,   275,   276,   277,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,   279,
       0,     0,     0,     0,     0,   280,     0,     0,     0,     0,
     281,   212,     6,     0,   282,     0,     0,   283,   213,   214,
     215,     0,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   248,   249,   250,
       0,     0,     0,     0,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,     0,     0,     0,   255,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     258,    25,     0,   259,     0,     0,     0,     0,     0,   260,
       0,     0,   261,     0,     0,   262,     0,   263,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,    57,    58,     0,   266,     0,   267,     0,     0,   268,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,   760,     0,
     761,     0,     0,     0,     0,     0,  1760,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,   270,
     271,     0,     0,     0,     0,   272,   273,   274,     0,   275,
     276,   277,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   279,     0,     0,     0,     0,     0,   280,     0,
       0,     0,     0,   366,   212,     6,     0,   282,     0,     0,
     283,   213,   214,   215,     0,     0,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,   249,   250,     0,     0,     0,     0,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   254,     0,
       0,     0,   255,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   258,    25,     0,   259,     0,     0,     0,
       0,     0,   260,     0,     0,   261,     0,     0,   262,     0,
     263,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   265,     0,    57,    58,     0,   266,     0,   267,
       0,     0,   268,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    83,     0,     0,    86,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,  1003,     0,     0,     0,     0,     0,     0,     0,   960,
       0,     0,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,   270,   271,     0,     0,     0,     0,   272,   273,
     274,     0,   275,   276,   277,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   507,     0,     0,     0,     0,
       0,   280,     0,     0,     0,     0,   366,   212,     6,     0,
     570,     0,     0,   283,   213,   214,   215,     0,     0,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,   250,     0,     0,     0,     0,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,     0,     0,     0,   255,   256,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   258,    25,     0,   259,
       0,     0,     0,     0,     0,   260,     0,     0,   261,     0,
       0,   262,     0,   263,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,    57,    58,     0,
     266,     0,   267,     0,     0,   268,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  1824,     0,
       0,     0,  1825,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,   270,   271,     0,     0,     0,
       0,   272,   273,   274,     0,   275,   276,   277,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   507,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,   366,
     212,     6,     0,     0,   575,     0,   283,   213,   214,   215,
       0,     0,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   248,   249,   250,     0,
       0,     0,     0,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   253,   254,     0,     0,     0,   255,   256,
     257,     0,     0,     0,     0,     0,     0,     0,     0,   258,
      25,     0,   259,     0,     0,     0,     0,     0,   260,     0,
       0,   261,     0,     0,   262,     0,   263,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,     0,
      57,    58,     0,   266,     0,   267,     0,     0,   268,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,     0,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    83,
       0,     0,    86,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  1875,     0,     0,     0,  1876,     0,     0,     0,     0,
       0,     0,     0,     0,   269,     0,     0,     0,   270,   271,
       0,     0,     0,     0,   272,   273,   274,     0,   275,   276,
     277,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   279,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,   613,   212,     6,     0,   282,     0,     0,   283,
     213,   214,   215,     0,     0,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
     249,   250,     0,     0,     0,     0,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   253,   254,     0,     0,
       0,   255,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   258,    25,     0,   259,     0,     0,     0,     0,
       0,   260,     0,     0,   261,     0,     0,   262,     0,   263,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,     0,    57,    58,     0,   266,     0,   267,     0,
       0,   268,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  1906,     0,     0,     0,  1907,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,   270,   271,     0,     0,     0,     0,   272,   273,   274,
       0,   275,   276,   277,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   279,     0,     0,     0,     0,     0,
     280,     0,     0,     0,     0,   622,   212,     6,     0,   282,
       0,     0,   283,   213,   214,   215,     0,     0,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   248,   249,   250,     0,     0,     0,     0,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     254,     0,     0,     0,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   258,    25,     0,   259,     0,
       0,     0,     0,     0,   260,     0,     0,   261,     0,     0,
     262,     0,   263,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,    57,    58,     0,   266,
       0,   267,     0,     0,   268,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  2080,     0,     0,
       0,  2081,     0,     0,     0,     0,     0,     0,     0,     0,
     269,     0,     0,     0,   270,   271,     0,     0,     0,     0,
     272,   273,   274,     0,   275,   276,   277,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,   507,     0,     0,
       0,     0,     0,   280,     0,     0,     0,     0,   366,   212,
       6,     0,   920,     0,  1393,   283,   213,   214,   215,     0,
       0,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,   249,   250,     0,     0,
       0,     0,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,   254,     0,     0,     0,   255,   256,   257,
       0,     0,     0,     0,     0,     0,     0,     0,   258,    25,
       0,   259,     0,     0,     0,     0,     0,   260,     0,     0,
     261,     0,     0,   262,     0,   263,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   265,     0,    57,
      58,     0,   266,     0,   267,     0,     0,   268,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   793,     0,     0,     0,     0,     0,
       0,     0,     0,   269,     0,     0,     0,   270,   271,     0,
       0,     0,     0,   272,   273,   274,     0,   275,   276,   277,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     507,     0,     0,     0,     0,     0,   280,   212,     6,     0,
       0,   366,  1608,     0,   213,   214,   215,     0,   283,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,   250,     0,     0,     0,     0,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
     253,   254,     0,     0,     0,   255,   256,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   258,    25,     0,   259,
       0,     0,     0,     0,     0,   260,     0,     0,   261,     0,
       0,   262,     0,   263,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,    57,    58,     0,
     266,     0,   267,     0,     0,   268,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   800,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,   270,   271,     0,     0,     0,
       0,   272,   273,   274,     0,   275,   276,   277,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   507,     0,
       0,     0,     0,     0,   280,   212,     6,     0,     0,   366,
       0,     0,   213,   214,   215,     0,   283,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,   250,     0,     0,     0,     0,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,   254,
       0,     0,     0,   255,   256,   257,     0,     0,     0,     0,
       0,     0,     0,     0,   258,    25,     0,   259,     0,     0,
       0,     0,     0,   260,     0,     0,   261,     0,     0,   262,
       0,   263,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,    57,    58,     0,   266,     0,
     267,     0,     0,   268,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     960,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,   270,   271,     0,     0,     0,     0,   272,
     273,   274,     0,   275,   276,   277,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   279,     0,     0,     0,
       0,     0,   280,     0,     0,     0,     0,   366,   212,     6,
       0,  1737,     0,     0,   283,   213,   214,   215,     0,     0,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   247,   248,   249,   250,     0,     0,     0,
       0,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,   254,     0,     0,     0,   255,   256,   257,     0,
       0,     0,     0,     0,     0,     0,     0,   258,    25,     0,
     259,     0,     0,     0,     0,     0,   260,     0,     0,   261,
       0,     0,   262,     0,   263,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,    57,    58,
       0,   266,     0,   267,     0,     0,   268,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   961,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,   270,   271,     0,     0,
       0,     0,   272,   273,   274,     0,   275,   276,   277,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,  1894,
       0,     0,     0,     0,     0,   280,     0,     0,     0,     0,
     645,   212,     6,     0,   326,     0,     0,   283,   213,   214,
     215,     0,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   248,   249,   250,
       0,     0,     0,     0,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,   254,     0,     0,     0,   255,
     256,   257,     0,     0,     0,     0,     0,     0,     0,     0,
     258,    25,     0,   259,     0,     0,     0,     0,     0,   260,
       0,     0,   261,     0,     0,   262,     0,   263,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,    57,    58,     0,   266,     0,   267,     0,     0,   268,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1011,     0,     0,     0,
       0,     0,     0,     0,     0,   269,     0,     0,     0,   270,
     271,     0,     0,     0,     0,   272,   273,   274,     0,   275,
     276,   277,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   507,     0,     0,     0,     0,     0,   280,   212,
     168,   387,     0,   366,     0,     0,   213,   214,   215,     0,
     283,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   425,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   247,   248,   249,   250,   397,   398,
     399,   400,   251,     0,     0,     0,   401,   402,   403,   404,
       0,     0,     0,     0,   405,     0,   406,   255,   256,   257,
       0,     0,     0,     0,     0,     0,     0,     0,   258,    25,
     407,   259,     0,   408,   212,   168,   387,     0,     0,     0,
       0,   213,   214,   215,     0,     0,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   425,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   247,
     248,   249,   250,   397,   398,   399,   400,   251,     0,     0,
       0,   401,   402,   403,   404,     0,     0,     0,     0,   405,
       0,   406,   255,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   258,    25,   407,   259,     0,   408,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   269,   409,   410,   411,   270,     0,     0,
       0,     0,     0,   272,   273,   274,   412,   275,   276,   277,
     413,     0,   414,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     426,     0,     0,     0,     0,     0,   280,     0,     0,     0,
       0,   366,     0,     0,     0,  1626,     0,     0,   283,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1120,     0,     0,     0,     0,     0,     0,   269,   409,
     410,   411,   270,     0,     0,     0,     0,     0,   272,   273,
     274,   412,   275,   276,   277,   413,     0,   414,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   426,     0,     0,     0,     0,
       0,   280,     0,     0,     0,     0,   366,   212,   168,   387,
    1911,     0,     0,   283,   213,   214,   215,     0,     0,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   425,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     0,     0,     0,
       0,     0,     0,  1630,   389,   390,   391,   392,   393,   394,
     395,   396,   247,   248,   249,   250,   397,   398,   399,   400,
     251,     0,     0,     0,   401,   402,   403,   404,     0,     0,
       0,     0,   405,     0,   406,   255,   256,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   258,    25,   407,   259,
       0,   408,   212,   168,   387,     0,     0,     0,     0,   213,
     214,   215,     0,     0,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   425,   234,   235,   236,   237,   238,   239,   240,   241,
       0,     0,     0,     0,     0,     0,     0,     0,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   247,   248,   249,
     250,   397,   398,   399,   400,   251,     0,     0,     0,   401,
     402,   403,   404,     0,     0,     0,     0,   405,     0,   406,
     255,   256,   257,     0,     0,     0,     0,     0,     0,     0,
       0,   258,    25,   407,   259,     0,   408,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,   409,   410,   411,   270,     0,     0,     0,     0,
       0,   272,   273,   274,   412,   275,   276,   277,   413,     0,
     414,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   426,     0,
       0,     0,     0,     0,   280,     0,     0,     0,     0,   366,
       0,     0,     0,  1794,     0,     0,   283,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1158,
       0,     0,     0,     0,     0,     0,   269,   409,   410,   411,
     270,     0,     0,     0,     0,     0,   272,   273,   274,   412,
     275,   276,   277,   413,     0,   414,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   426,     0,     0,     0,     0,     0,   280,
     212,   168,     0,     0,   366,     0,     0,   213,   214,   215,
       0,   283,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   425,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   248,   249,   250,     0,
       0,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,     0,     0,     0,     0,     0,   212,   168,     0,   258,
      25,     0,   259,   213,   214,   215,     0,     0,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   425,   234,   235,   236,   237,
     238,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   248,   249,   250,     0,     0,     0,     0,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   258,    25,     0,   259,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,   269,     0,     0,     0,   270,     0,
       0,  1168,     0,     0,   272,   273,   274,     0,   275,   276,
     277,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   426,     0,     0,     0,     0,     0,   280,     0,     0,
       0,     0,   366,     0,     0,     0,   625,     0,     0,   283,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
     269,     0,  1169,     0,   270,     0,     0,     0,     0,     0,
     272,   273,   274,     0,   275,   276,   277,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   643,   644,     0,     0,
       0,     0,     0,   280,     0,     0,     0,     0,   645,   212,
     168,     0,   326,     0,   888,   283,   213,   214,   215,     0,
       0,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   425,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,   249,   250,     0,     0,
       0,     0,   251,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   256,   257,
       0,     0,     0,     0,     0,   212,   168,     0,   258,    25,
       0,   259,   213,   214,   215,     0,     0,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   425,   234,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,   250,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,   256,   257,     0,     0,     0,     0,
       0,     0,     0,     0,   258,    25,     0,   259,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,   269,     0,     0,     0,   270,     0,     0,
    1170,     0,     0,   272,   273,   274,     0,   275,   276,   277,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     426,     0,     0,     0,     0,     0,   280,     0,     0,     0,
       0,   366,     0,     0,     0,     0,     0,     0,   283,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,   269,
       0,  1171,     0,   270,     0,     0,     0,     0,     0,   272,
     273,   274,     0,   275,   276,   277,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   426,     0,     0,     0,
       0,     0,   280,   212,   168,     0,  1344,   366,  1109,     0,
     213,   214,   215,     0,   283,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   425,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
     249,   250,     0,     0,     0,     0,   251,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,   256,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   258,    25,     0,   259,   212,   168,     0,  1504,
       0,     0,     0,   213,   214,   215,     0,     0,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   425,   234,   235,   236,   237,
     238,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   247,   248,   249,   250,     0,     0,     0,     0,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,   256,   257,     0,     0,     0,
       0,     0,     0,     0,     0,   258,    25,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,     0,     0,
       0,   270,     0,     0,     0,     0,     0,   272,   273,   274,
       0,   275,   276,   277,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,   426,     0,     0,     0,     0,     0,
     280,     0,     0,     0,     0,   366,     0,     0,     0,     0,
       0,     0,   283,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1172,     0,     0,     0,     0,
     269,     0,     0,     0,   270,     0,     0,     0,     0,     0,
     272,   273,   274,     0,   275,   276,   277,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   278,   426,     0,     0,
       0,     0,     0,   280,   212,   168,     0,  1570,   366,     0,
       0,   213,   214,   215,     0,   283,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   425,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,   249,   250,     0,     0,     0,     0,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,     0,     0,     0,     0,     0,
     212,   168,     0,   258,    25,     0,   259,   213,   214,   215,
       0,     0,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   425,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   248,   249,   250,     0,
       0,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
     257,     0,     0,     0,     0,     0,     0,     0,     0,   258,
      25,     0,   259,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,   269,     0,
       0,     0,   270,     0,     0,  1177,     0,     0,   272,   273,
     274,     0,   275,   276,   277,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   278,   426,     0,     0,     0,     0,
       0,   280,     0,     0,     0,     0,   366,     0,     0,     0,
       0,     0,     0,   283,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,   269,     0,  1178,     0,   270,     0,
       0,     0,     0,     0,   272,   273,   274,     0,   275,   276,
     277,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   426,     0,     0,     0,     0,     0,   280,   212,   168,
       0,     0,   366,  1624,     0,   213,   214,   215,     0,   283,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   425,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   247,   248,   249,   250,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256,   257,     0,
       0,     0,     0,     0,   212,   168,     0,   258,    25,     0,
     259,   213,   214,   215,     0,     0,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   425,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,   249,   250,     0,     0,     0,     0,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,   256,   257,     0,     0,     0,     0,     0,
       0,     0,     0,   258,    25,     0,   259,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,   269,     0,     0,     0,   270,     0,     0,  1180,
       0,     0,   272,   273,   274,     0,   275,   276,   277,     0,
       0,     0,   119,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   278,   426,
       0,     0,     0,     0,     0,   280,     0,     0,     0,     0,
     366,  1958,     0,     0,     0,     0,     0,   283,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     7,     8,     0,     0,     0,     0,   269,     0,
    1294,     0,   270,     0,     0,     0,     0,     0,   272,   273,
     274,     0,   275,   276,   277,     0,     0,     0,   119,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   278,   426,     0,    43,    44,    45,
      46,   280,     0,    48,     0,     0,   366,     0,     0,     0,
       0,   774,    56,   283,     0,    59,   775,     0,   776,   777,
       0,   778,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     7,     8,    43,    44,    45,    46,
       0,     0,    48,     0,    95,    96,    97,     0,     0,     0,
     774,    56,     0,     0,    59,   775,     0,   776,   777,     0,
     778,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     799,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   774,    56,     0,     0,    59,   775,     0,   776,
     777,     0,   778,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   968,
      80,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     7,     8,    43,    44,    45,
      46,     0,     0,    48,     0,    95,    96,    97,     0,     0,
       0,   774,    56,     0,     0,    59,   775,     0,   776,   777,
       0,   778,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   993,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   774,    56,     0,     0,    59,   775,     0,
     776,   777,     0,   778,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1043,    80,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     7,     8,    43,    44,
      45,    46,     0,     0,    48,     0,    95,    96,    97,     0,
       0,     0,   774,    56,     0,     0,    59,   775,     0,   776,
     777,     0,   778,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1045,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,   774,    56,     0,     0,    59,   775,
       0,   776,   777,     0,   778,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1244,    80,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     7,     8,    43,
      44,    45,    46,     0,     0,    48,     0,    95,    96,    97,
       0,     0,     0,   774,    56,     0,     0,    59,   775,     0,
     776,   777,     0,   778,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1246,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   774,    56,     0,     0,    59,
     775,     0,   776,   777,     0,   778,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1247,    80,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     7,     8,
      43,    44,    45,    46,     0,     0,    48,     0,    95,    96,
      97,     0,     0,     0,   774,    56,     0,     0,    59,   775,
       0,   776,   777,     0,   778,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1266,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   774,    56,     0,     0,
      59,   775,     0,   776,   777,     0,   778,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1285,    80,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     7,
       8,    43,    44,    45,    46,     0,     0,    48,     0,    95,
      96,    97,     0,     0,     0,   774,    56,     0,     0,    59,
     775,     0,   776,   777,     0,   778,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    96,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1302,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   774,    56,     0,
       0,    59,   775,     0,   776,   777,     0,   778,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1336,    80,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       7,     8,    43,    44,    45,    46,     0,     0,    48,     0,
      95,    96,    97,     0,     0,     0,   774,    56,     0,     0,
      59,   775,     0,   776,   777,     0,   778,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,    95,
      96,    97,     0,     0,     0,     0,     0,  1317,     0,     0,
       0,     0,     0,     0,     0,     0,  1496,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   774,    56,
       0,     0,    59,   775,     0,   776,   777,     0,   778,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2139,    80,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,     0,
       0,    95,    96,    97,     0,     0,     0,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,    -4,    -4,    -4,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1403,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,  2196,    -4,    -4,
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
       0,     0,     0,     0,     0,    -4,     0,    -4,     0,     0,
       0,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       9,    10,    11,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1406,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,     0,    17,     0,     0,     0,     0,    18,    19,
      20,    21,    22,     0,    23,    24,     0,    25,     0,     0,
       0,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
      42,    43,    44,    45,    46,    47,     0,    48,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     0,     0,    65,    66,    67,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,    91,    92,     0,
       0,     0,    93,     0,     0,     0,     0,    94,    95,    96,
      97,   168,   387,    98,     0,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,   119,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   394,   395,   396,     0,     0,     0,     0,   397,
     398,   399,   400,   168,   387,     0,     0,   401,   402,   403,
     404,     0,     0,     0,     0,   405,     0,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   407,     0,     0,   408,     0,     0,     0,   174,   418,
     387,   175,     0,     0,   176,     0,   177,     0,   388,   389,
     390,   391,   392,   393,   394,   395,   396,    46,     0,     0,
       0,   397,   398,   399,   400,     0,     0,     0,     0,   401,
     402,   403,   404,     0,     0,   439,   387,   405,     0,   406,
       0,     0,     0,     0,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   407,     0,     0,   408,   397,   398,   399,
     400,     0,     0,     0,     0,   401,   402,   403,   404,     0,
       0,     0,     0,   405,     0,   406,     0,     0,     0,     0,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   407,
       0,     0,   408,   397,   398,   399,   400,     0,     0,     0,
       0,   401,   402,   403,   404,   409,   410,   411,     0,   405,
       0,   406,     0,     0,     0,     0,     0,   412,     0,     0,
       0,   413,     0,   414,   119,   407,     0,     0,   408,     0,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1498,     0,     0,     0,     0,   409,   410,   411,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   412,
       0,     0,     0,   413,     0,   414,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   409,   410,   411,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   412,     0,     0,     0,   413,
       0,   414,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
     410,   411,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,     0,     0,   413,     0,   414,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     7,     8,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   774,    56,
       0,     0,    59,   775,     0,   776,   777,     0,   778,     0,
       0,     0,  1055,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
    1056,     0,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,    95,    96,    97,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1499,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,   774,
      56,     0,     0,    59,   775,     0,   776,   777,     0,   778,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,    95,    96,    97,     0,     0,     0,     0,     0,
    1546,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1672,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1673,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1674,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1822,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1945,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1946,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1978,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2050,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2107,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2108,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2123,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2157,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2184,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2189,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2190,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,   832,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,  1090,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  1145,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  1192,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    1193,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,  1237,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  1269,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  1283,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  1290,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,  1350,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  1370,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,  1453,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  1454,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  1500,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    1576,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,  1873,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  1884,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  1925,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  1999,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,  2015,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  2027,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,  2051,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  2086,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  2096,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    2097,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,  2121,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  2170,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  2209,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  2227,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,  2245,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  2246,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,   733,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
     952,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,  1992,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,   760,     0,   761,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,  1017,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,  1066,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,  1216,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,  1284,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
    1286,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,  1292,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   732,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,  1293,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   732,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,  1385,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   732,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,  1399,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   732,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,  1605,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,  1693,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   732,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,  1746,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   732,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,  1937,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     732,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,  1982,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   732,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
    2000,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   813,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     814,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   815,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     817,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   818,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     819,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   821,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     822,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   823,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     824,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   825,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     826,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   827,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     829,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   830,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     831,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   900,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     934,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   982,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1003,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1006,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1008,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1009,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1015,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1016,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1054,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1065,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1125,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1129,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1141,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1215,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1225,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1226,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1227,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1236,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1238,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1239,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1268,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1270,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1271,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1272,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1273,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1274,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1275,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1276,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1282,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1295,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1297,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1335,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1384,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1398,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1606,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1640,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1680,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1692,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1809,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1811,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1814,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1821,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1874,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1883,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1910,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1981,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    2048,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  2049,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    2183,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   732,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  2224,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   732,
     597,   598,   599,   600,     0,     0,     0,     0,   601
};

static const yytype_int16 yycheck[] =
{
       3,   319,     3,  1263,   640,   641,  1460,   159,  1731,     4,
      69,    70,  1267,    72,   757,   109,  1777,   111,  1779,     4,
     763,   200,    25,    63,     5,  1961,     3,     5,    25,     4,
     209,     4,     4,     4,     4,   107,     4,     6,     5,     5,
     145,     6,   107,     7,     4,     6,   107,  1764,     4,     6,
      27,   145,    55,     6,     6,     6,     4,     4,     4,     6,
     107,     4,     0,   142,   101,     9,   252,   253,     4,   255,
     131,   257,     9,   163,   243,   244,    36,    37,     4,   173,
      14,    84,     4,   120,   131,    62,     4,     9,    36,    37,
      93,   260,     6,   243,   244,    98,     4,     7,   104,   189,
       9,   107,   108,   109,     7,   255,   109,   107,    93,   259,
      36,    37,  1829,   192,   120,   205,   206,     9,    36,    37,
     243,   244,   256,  1846,   303,   304,   305,     9,    36,    37,
     264,     7,   243,   244,   256,     6,   256,   114,   258,   261,
       9,   264,   145,     6,   264,   146,   162,   150,   151,   152,
     110,   111,   258,   264,   101,   255,   159,   257,   264,   256,
       6,   258,   110,   111,   343,   344,   345,   264,   145,   255,
     243,   244,     7,   150,   151,   152,   179,     6,   184,     7,
    2116,   360,   159,   255,   110,   111,   256,     7,   243,   244,
     255,   264,   195,   255,   264,   243,   244,   200,     7,   248,
     249,   204,   110,   111,   255,   254,   209,   210,   211,   264,
     252,   253,   177,   253,   254,   200,   264,   255,   195,   261,
     177,   259,     6,   179,   180,   181,   182,     6,   256,   189,
     190,  1685,   227,   204,   211,   191,   264,   193,   194,   195,
     196,   197,   227,   256,   104,   201,   202,   107,   204,   243,
     244,   264,   243,   244,   227,   227,  1516,   227,     6,   227,
     120,   255,   265,   322,   323,   259,  1989,   262,     6,   238,
     239,   330,   331,   264,   259,   252,   279,     6,   259,   282,
     283,   259,   257,   256,   259,   258,   283,   259,   263,   259,
     267,   268,   259,   259,   255,   298,   299,   261,   259,   302,
     303,   304,   305,     6,   260,   227,   259,   259,   259,   255,
     313,   255,   255,   257,   317,   331,   319,   261,   255,   255,
     257,  2044,  1065,  1066,   261,   228,   229,   230,   231,   104,
     252,   253,   107,   255,   350,   257,     4,   259,   341,   261,
     343,   344,   345,   256,   438,   255,   255,   257,   257,   252,
     253,   264,   228,   229,   230,   231,   258,   360,   261,     4,
     252,   253,   264,   255,   367,   257,   258,   238,   239,   261,
     252,   253,   255,   255,   259,   257,   252,   253,   263,   261,
     243,   244,   561,   252,   253,   255,   255,   257,   257,   259,
    2151,   259,   261,   228,   229,   230,   231,   243,   244,   551,
     228,   229,   230,   231,     4,   421,   257,   423,   228,   229,
     230,   231,   142,     6,   243,   244,   432,   252,   253,   228,
     229,   230,   231,   257,   252,   253,   429,   430,   243,   244,
     160,   434,   435,   255,   255,   257,    36,    37,   259,   169,
     170,   171,   264,   243,   244,   175,   176,   450,   255,   264,
     243,   244,   429,   256,   457,   258,   101,   256,   255,   142,
     105,   264,   439,  2186,   264,   264,   111,   112,   256,   114,
     115,   264,   255,   567,   243,   244,   264,   160,   481,   147,
     148,   149,   150,   255,   461,   153,   169,   170,   171,   255,
     135,   449,   175,   176,   162,   264,   255,   165,   475,   243,
     244,   243,   244,   255,   507,   255,   142,   259,   243,   244,
     110,   111,   255,  2236,   257,   256,   204,   258,   261,   256,
     264,   264,   264,   264,   160,  1979,   259,   264,   531,   264,
     260,   243,   244,   169,   170,   171,   255,   540,   541,   175,
     176,   107,   545,   109,   547,   548,   549,   550,   551,   701,
     243,   244,   264,   556,   243,   244,   256,   560,   561,   562,
     563,   564,   565,   566,   264,   568,   259,   570,   545,   566,
     547,   568,   549,   550,   551,   264,   255,   260,   257,   638,
     639,   243,   244,   255,   643,   261,   563,   564,   264,   189,
     190,   243,   244,   596,     6,     7,   243,   244,   256,   602,
     258,   142,   264,   260,   243,   244,   264,   264,   147,   148,
     298,   299,   264,   629,   153,   631,   632,   264,   255,   160,
     714,   624,   625,   255,   260,   264,   255,   142,   169,   170,
     171,   261,   648,   263,   175,   176,   243,   244,   255,   640,
     641,  1277,   243,   244,   255,   160,   260,   605,   243,   244,
     264,   667,   757,   341,   169,   170,   171,   264,   243,   244,
     175,   176,   101,   264,   259,   104,   243,   244,   107,   646,
     673,   674,   675,   252,   253,   678,   255,   693,   257,   264,
     259,   120,   259,   252,   253,   255,   101,   260,   122,   104,
     259,   264,   107,   670,   109,   259,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   120,   709,   710,   711,   712,
     713,   255,   715,   716,   717,   718,   719,   733,   812,   722,
       6,   718,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   734,   709,   710,   711,   712,     6,   777,   715,   716,
     717,   109,   430,  1486,   747,   260,   255,   104,   725,   259,
     107,   728,   109,   245,   246,   247,   248,   249,   256,   762,
     258,   259,   254,   120,   741,   768,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   737,
     260,   784,   785,   254,   264,   147,   148,   790,   255,   792,
       6,   153,   795,   796,   260,   256,   107,   258,   264,   776,
     803,   778,   805,   243,   244,   245,   246,   247,   248,   249,
     255,   260,   257,   771,   254,   264,   252,   253,   795,   255,
     104,   257,     4,   107,     6,   109,   931,   260,   805,   260,
     788,   264,   835,   264,   837,   260,   104,   260,  1581,   264,
     798,   264,   260,   260,   243,   244,   264,   264,  1591,   260,
     944,   260,   260,   264,   260,   264,   264,   260,   264,   260,
      55,   264,   260,   264,   260,   259,   264,   260,   264,   872,
     260,   264,   260,   260,   264,   107,   264,   264,   259,   882,
     260,   259,   570,   260,   264,  2140,   260,   264,   260,   260,
     264,   260,   264,   264,   260,   264,   259,   107,   264,   260,
     959,   904,   260,   264,   260,   260,   264,   966,   264,   264,
     260,   970,  2172,   104,   264,   260,     8,   920,   260,   264,
     260,   260,   264,   260,   264,   264,   260,   264,   260,   932,
     264,   260,   264,   255,   104,   264,   624,   625,   941,   260,
     956,   260,  2197,   264,   902,   264,  1051,   260,   260,   952,
     107,   264,   264,   260,  2214,   260,   107,   264,   260,   264,
    1065,  1066,   264,   260,   260,   260,   260,   264,   264,   264,
     264,   256,   260,   258,   259,  1069,   264,  1082,   955,   260,
     957,   958,     4,   264,   260,   673,   674,   675,   264,   260,
     678,   252,   253,   264,   971,   255,     4,   257,     4,     4,
     255,   255,   255,     6,     6,   145,   257,   255,   257,   259,
     150,   151,   152,     6,   991,   210,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   722,  1012,   263,   259,   254,     6,
     263,   255,  1360,     9,   255,   192,   255,   255,   255,   192,
     255,   255,   131,   259,   192,   195,   259,  1060,   255,   255,
     192,   255,   255,  1122,     4,  1068,   255,   259,   255,   255,
     265,   211,  1049,  1076,   762,   259,   255,   255,   259,   259,
    1716,  1717,   259,   259,   255,     6,  1089,   255,   255,   255,
     255,  1094,   255,   257,     6,     6,   784,   259,   259,   259,
     259,   259,   790,   257,   792,   257,     6,   302,   257,  1067,
    1215,  1216,     6,   255,   255,   259,   192,  1094,   313,   255,
    1123,  1124,   317,  1126,  1127,  1128,   255,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,   255,   255,  1142,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   255,   255,
       6,     6,   254,   257,   259,     6,     8,     6,   260,   255,
       8,   259,     7,     6,   259,   259,     6,   259,    96,  1182,
    1183,  1184,   260,   264,   872,   256,     7,   264,     6,     6,
     256,   259,   259,   254,   882,   259,   259,    67,     8,   261,
       7,     7,   255,  1206,     6,   256,  1183,  1184,     6,   259,
       7,     6,   260,     7,     6,     6,   189,   259,   258,  1222,
    1223,  1224,   260,   260,   256,     6,   259,   261,     7,     6,
     257,   255,   920,   259,     6,     6,     6,     6,     6,   434,
     435,  1199,   256,  1201,   932,   257,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   450,  1214,     7,     7,     7,
     259,     7,     7,     7,   952,     7,  1584,     6,  1245,   256,
     258,   260,   264,   264,   264,  1278,  1277,   256,   264,  1384,
    1385,     7,   260,     7,   261,  1243,     4,   259,   259,   429,
       6,   261,   260,  1296,   142,  1298,  1299,   260,   259,     7,
       6,   261,     7,     7,     7,  1308,   256,   256,   264,   264,
    1313,     9,   264,  1407,  1317,  1409,   258,   256,   261,   263,
     192,     7,   260,  1326,   259,  1328,   163,     6,  1331,     6,
       6,   261,    49,   255,    49,   259,  1313,     7,   255,   259,
    1317,   255,   261,     7,  1347,   261,   255,  1305,  1306,  1326,
       7,  1328,   192,   548,  1331,   256,   264,  1360,     7,  1995,
       7,     7,     6,   256,  1341,   560,   264,   562,     7,     7,
     259,     7,  1330,     7,     7,     4,   119,   255,     6,  1337,
       7,     6,  1385,     7,     7,     7,     7,  1390,     7,  1392,
       7,     7,   259,     6,   101,     6,     6,   107,  1356,     7,
       7,  1089,     6,     6,     4,   545,  1409,   547,  1385,   549,
     550,     7,     7,   262,   264,     6,   259,   264,  1421,     6,
     256,     6,  1425,   563,   564,  1383,   260,   259,   259,     7,
       6,   257,     6,     6,   259,   255,   255,     6,   260,  1397,
    1592,  1593,     6,     6,     6,   261,  1404,   258,     6,   264,
       6,   135,     6,     6,  1142,     6,  1515,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   256,   256,     6,
    1564,     6,     4,  1791,   259,     6,  1581,  1480,  1481,  1482,
       7,   259,     6,   259,     7,  1488,  1489,  1490,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,  1506,     6,   257,     6,   254,   259,     6,
       6,     6,     6,   188,  1517,     6,     4,     7,   259,   259,
       6,   259,  1525,   259,   259,   259,  1529,   259,   261,   260,
     259,   259,  1626,   255,   264,  1223,  1224,  1540,     6,  1542,
     259,   264,   256,   264,   264,     6,   259,     6,   260,     7,
       6,     6,   747,  1569,   255,   255,     6,  1573,     6,   142,
     700,     6,   702,   703,   704,   705,   706,   707,     5,   709,
     710,   711,   712,   256,   259,   715,   716,   717,   259,   105,
       6,  1584,   264,     6,  1643,   259,  1691,   142,     6,  1592,
    1593,   264,   142,     6,     6,  1598,     6,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,  1616,     6,  1592,  1593,   254,  1712,     6,
    1308,   264,   264,  1626,   256,     6,     6,     6,  1631,   264,
       6,     6,     6,   259,     6,     6,   146,     7,     6,  1616,
       5,   259,  1794,     6,   259,   259,     6,   259,     6,     6,
     259,   256,     7,   259,     6,   795,     6,   259,   187,   260,
       7,   260,   259,  1757,   256,   805,   260,   260,     6,     6,
    1764,  1765,   260,  1732,  1733,  1734,  1735,  1736,  1737,   261,
       6,     6,     6,     6,   259,     6,     6,     6,   260,   256,
       6,  1785,     6,   259,     6,     6,     6,   190,   259,   259,
    1703,   260,  1390,   260,  1392,  1708,  1709,   259,     6,   904,
       6,   142,     6,  2031,     6,  1716,  1717,   255,     6,   259,
     256,     6,     6,     6,     6,   259,     6,   260,  1731,   259,
       6,   259,     6,     6,  1737,   256,     6,     6,   260,  1742,
     260,   259,     6,   259,     6,     6,   941,   259,  1751,     6,
       6,     6,     6,     6,  1396,  2153,  1759,  1455,  1638,  1762,
    1962,  1922,     3,  1078,  1699,  1420,     3,   478,     3,     3,
    1991,  1561,     3,   617,  1784,  1764,  1593,  1780,   795,    -1,
      -1,  1784,  1759,    -1,    -1,  1762,    -1,    -1,  1791,    -1,
    1793,  1794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1777,    -1,  1779,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1794,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1783,  1829,    -1,    -1,    -1,
    1924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1529,    -1,  1846,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1829,    -1,  1857,  1858,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1967,    -1,    -1,    -1,    -1,    -1,  1882,
      -1,  1076,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1123,  1124,
      -1,  1126,  1127,  1128,    -1,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1948,    -1,    -1,    -1,  2008,
    2009,  2010,  2011,  2012,  1094,    -1,    -1,    -1,    -1,    -1,
    1963,    -1,    -1,    -1,    -1,  1968,    -1,    -1,  1971,  1972,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1989,  1182,  2004,  1992,
      -1,    -1,    -1,    -1,  1995,    -1,    -1,    -1,    -1,    -1,
    2003,    -1,    -1,    -1,  2007,    -1,    -1,    -1,    -1,    -1,
      -1,  1206,    -1,  2072,    -1,    -1,    -1,  2076,    -1,    -1,
    1708,  1709,    -1,  2117,    -1,    -1,    -1,  1222,  2031,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2044,    -1,  1183,  1184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1742,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2127,    -1,
    2073,    -1,  2131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1278,    -1,  2101,    -1,    -1,  2147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1296,    -1,  1298,  1299,    -1,    -1,    -1,  2085,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2125,    -1,    -1,  2141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2192,  2193,    -1,    -1,    -1,    -1,    -1,
    2143,  2144,  2145,  2146,  2147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1857,
    1858,    -1,    -1,  1313,  2151,    -1,    -1,  1317,    -1,    -1,
      -1,    -1,    -1,  2186,    -1,    -1,  1326,    -1,  1328,    -1,
      -1,  1331,    -1,    -1,    -1,    -1,  2173,    -1,    -1,  2202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1409,    -1,    -1,    -1,    -1,    -1,
    2223,    -1,    -1,  1911,    -1,    -1,  1421,    -1,    -1,    -1,
    1425,    -1,    -1,  2236,    -1,    -1,    -1,    -1,    -1,  2242,
    2243,    -1,    -1,    -1,    -1,  1385,  2223,    -1,    -1,    -1,
      -1,    -1,  2255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2242,  2243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2255,    -1,
      -1,    -1,    -1,  1971,  1972,  1480,  1481,  1482,    -1,    -1,
      -1,    -1,    -1,  1488,  1489,  1490,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1992,     4,     5,    -1,    -1,    -1,
      -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2007,
      -1,    -1,  1517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1540,    -1,  1542,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,   101,  1598,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1626,    -1,    -1,    -1,    -1,    -1,  2125,    -1,   138,
      -1,    -1,    -1,   145,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,   154,    -1,    -1,  2143,  2144,  2145,  2146,  2147,
      -1,   163,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1616,    -1,   180,   181,
     182,    -1,   184,   185,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,    -1,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,    -1,    -1,  1703,   208,
     209,   210,    -1,    -1,  2202,    -1,    -1,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,   224,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1731,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   252,   253,    -1,  1751,    -1,    -1,    -1,
     259,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   278,   279,   280,   281,
     282,    -1,    -1,    -1,    -1,  1780,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   297,   298,   299,  1793,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   315,    -1,    -1,    -1,    -1,    -1,  1759,
      -1,    -1,  1762,   325,   326,    -1,    -1,    -1,    -1,   331,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,
     342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1846,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   366,   367,    -1,    -1,    -1,    -1,
     372,    -1,   374,   375,    -1,   377,    -1,    -1,    -1,   381,
     382,   383,    -1,    -1,   386,    -1,    -1,  1882,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,   430,   431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   447,   448,    -1,    -1,    -1,
      -1,    -1,    -1,  1948,    -1,    -1,    -1,    -1,    -1,    -1,
     462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1963,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
     492,    -1,    -1,    -1,  1989,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   506,   507,    -1,    -1,  2003,   511,
      -1,    -1,    -1,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
      -1,   543,   544,    -1,   546,    -1,    -1,    -1,    -1,  2044,
      -1,   204,    -1,   555,    -1,    -1,   558,   559,    -1,    -1,
      -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,   570,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2073,    -1,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
      -1,   603,   604,    -1,    -1,    -1,    -1,    -1,    -1,   611,
     612,   613,     8,    -1,    -1,    -1,    -1,   619,   620,   621,
     622,    -1,   624,   625,    -1,    -1,   279,    -1,    -1,   282,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   643,   644,   645,    -1,   298,   299,   649,   650,   651,
     652,   653,   654,   655,   656,   657,    -1,    -1,    -1,    -1,
      -1,   663,   664,    -1,   666,     8,    -1,   669,    -1,    -1,
      -1,   673,   674,   675,   676,    -1,   678,   679,   680,   681,
      -1,    -1,    -1,    -1,   686,    -1,   688,    -1,   341,    -1,
      -1,  2186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   708,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,
     722,    -1,    -1,    -1,    -1,    -1,    -1,   729,   730,    -1,
     732,    -1,    -1,   735,   736,    -1,    -1,    -1,    -1,    -1,
      -1,  2236,   744,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
     762,    -1,   764,    -1,    -1,    -1,    -1,   769,   770,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,
      -1,    -1,   784,  2223,   786,   787,    -1,    -1,   790,    -1,
     792,   793,    -1,    -1,    -1,   797,    -1,    -1,   800,    -1,
      -1,    -1,  2242,  2243,   806,     6,    -1,    -1,   810,    -1,
      -1,    -1,    -1,    -1,    -1,  2255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   833,    -1,   835,    -1,   837,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   507,    -1,    -1,    -1,   254,    -1,
     256,    -1,   258,     6,    -1,    -1,    -1,    -1,    -1,    -1,
     872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,
     882,   883,   884,    -1,    -1,    -1,    -1,   540,   541,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,   565,   256,    -1,    -1,    -1,   570,   920,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     932,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   940,    -1,
      -1,    -1,   944,   596,    -1,    -1,    -1,    -1,    -1,    -1,
     952,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   960,   961,
      -1,    -1,    -1,    -1,   966,    -1,    -1,    -1,    -1,    -1,
      -1,   624,   625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   983,    -1,    -1,   986,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,  1011,
      -1,  1013,  1014,     8,    -1,    -1,    -1,    -1,    -1,    -1,
     673,   674,   675,    -1,    -1,   678,    -1,    -1,    -1,    -1,
    1032,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,  1056,    -1,    -1,    -1,    -1,    -1,
      -1,  1063,    -1,    -1,    -1,    -1,    -1,    -1,  1070,   722,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1083,  1084,    -1,    -1,    -1,    -1,  1089,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,   762,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,  1120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   784,    -1,    -1,    -1,    -1,    -1,   790,    -1,   792,
    1142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1168,  1169,  1170,  1171,
    1172,    -1,    -1,    -1,    -1,  1177,  1178,    -1,  1180,    -1,
      -1,    -1,   835,    -1,   837,     6,    -1,    -1,    -1,    -1,
      -1,    -1,  1194,  1195,    -1,    -1,    -1,    -1,    -1,    -1,
    1202,  1203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1211,
    1212,    -1,    -1,    -1,    -1,  1217,  1218,    -1,    -1,   872,
      -1,  1223,  1224,    -1,    -1,    -1,    -1,    -1,    -1,   882,
      -1,    -1,    -1,     6,    -1,     4,     5,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,  1257,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   920,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   932,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,  1294,    62,    63,    64,    65,    -1,    -1,   952,
      -1,    70,    71,    72,    73,    -1,  1308,    -1,    -1,    78,
      -1,    80,    -1,    -1,  1316,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,   101,    -1,    -1,   104,  1338,  1339,   107,    -1,
     109,  1343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,  1354,    -1,    -1,  1357,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1386,    -1,    -1,  1389,  1390,  1391,
    1392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1400,    -1,
      -1,  1403,    -1,  1405,  1406,  1407,    -1,    -1,  1410,  1411,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,  1089,    -1,    -1,   208,
     209,   210,    -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,   224,    -1,   226,   227,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,  1487,    -1,    -1,    -1,  1142,
     259,    -1,    -1,    -1,    -1,  1497,  1498,  1499,    -1,    -1,
      -1,    -1,    -1,    -1,  1506,    -1,  1508,    -1,    -1,    -1,
      -1,    -1,    -1,  1515,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1529,    -1,    -1,
      -1,    -1,    -1,  1535,  1536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1546,  1547,  1548,    -1,   556,    -1,
      -1,    -1,    -1,    -1,  1556,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,  1567,    -1,    -1,    -1,    -1,
    1223,  1224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1588,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1596,  1597,    -1,    -1,    -1,   607,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,  1631,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,  1308,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
    1672,  1673,  1674,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,  1683,    -1,    -1,     6,    -1,  1688,  1689,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,  1701,
      -1,    -1,    -1,    -1,    -1,    -1,  1708,  1709,  1710,    -1,
    1712,    -1,    -1,    -1,    -1,    -1,  1718,  1719,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1737,    -1,  1390,    -1,  1392,
    1742,  1743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1757,    -1,    -1,  1760,    -1,
      -1,    -1,  1764,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,  1773,  1774,    -1,  1776,   220,    -1,    -1,    -1,   224,
      -1,   226,   227,    -1,  1786,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1800,    -1,
      -1,    -1,    -1,  1805,  1806,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    -1,   258,   259,    -1,    -1,  1819,    -1,    -1,
    1822,  1823,    -1,  1825,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,    -1,   854,   855,   856,   857,
      -1,   859,   860,   861,   862,  1857,  1858,    -1,    -1,    -1,
      -1,    -1,  1864,  1865,    -1,    -1,    -1,   875,    -1,   877,
      -1,    -1,    -1,    -1,  1876,    -1,  1529,    -1,    -1,   887,
      -1,    -1,    -1,  1885,    -1,    -1,   894,   895,    -1,    -1,
      -1,    -1,  1894,    -1,    -1,   903,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1907,  1908,    -1,    -1,  1911,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
       6,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1945,  1946,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,  1966,    -1,    -1,   254,    -1,  1971,
    1972,  1973,    -1,    -1,    -1,    -1,  1978,    -1,  1631,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2007,    -1,    -1,    -1,    -1,
    1018,  1019,  1020,    -1,  2016,    -1,  1024,  1025,    -1,    -1,
    1028,  1029,  1030,  1031,    -1,  1033,    -1,    -1,    -1,    -1,
    1038,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,  2041,
      -1,    -1,    -1,    -1,    -1,  2047,    -1,    -1,  2050,    -1,
      -1,    -1,    -1,    -1,    -1,  1708,  1709,     6,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,  2081,
     254,    -1,    -1,    -1,  1737,    -1,    -1,    -1,    -1,  1742,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2107,  2108,    -1,    -1,    -1,
      -1,  1119,    -1,  1121,    -1,    -1,    -1,    -1,    -1,    -1,
    2122,  2123,    -1,  2125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2138,    -1,    -1,     6,
      -1,  2143,  2144,  2145,  2146,  2147,    -1,    -1,    -1,    -1,
      -1,  2153,    -1,    -1,    -1,  2157,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,     6,    -1,    -1,   254,    -1,
      -1,    -1,  2184,    -1,    -1,    -1,    -1,  2189,  2190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2202,    -1,    -1,    -1,  1857,  1858,    -1,    -1,    -1,    -1,
      -1,    -1,  1220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2229,  2230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,     6,    -1,    -1,
      -1,   254,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1971,  1972,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,  1992,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2007,    -1,    -1,    -1,  1366,    -1,
      -1,    -1,    26,    -1,    28,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1408,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1439,  1440,  1441,  1442,  1443,  1444,  1445,    -1,    -1,
      -1,    -1,  1450,  1451,    -1,    -1,    -1,    -1,  1456,    -1,
    1458,    -1,    -1,    -1,  1462,    -1,    -1,  1465,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,    -1,
      -1,    -1,  2125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2143,  2144,  2145,  2146,  2147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1552,    -1,  1554,    -1,    -1,  2202,
    1558,    -1,  1560,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,  1592,   249,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,   259,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   270,   271,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,  1690,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   388,   389,   390,   120,    -1,    -1,
     394,   395,   396,   397,   398,   399,   400,    -1,   402,    -1,
      -1,    -1,    -1,   407,   408,   138,    -1,   411,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   425,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,  1796,    -1,
      -1,  1799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,   228,   229,   230,   231,  1847,
    1848,    -1,  1850,    -1,    -1,    -1,    -1,    -1,     6,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,   252,
     253,    -1,   255,    -1,   257,    -1,    -1,    -1,   261,   262,
      -1,    -1,    -1,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1915,  1916,    -1,
      -1,     3,     4,     5,   578,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     7,     8,  1964,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,     7,    -1,   255,    -1,    -1,    -1,   259,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,  2211,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,     3,     4,     5,   254,    -1,    -1,    -1,
      10,    11,    12,    -1,   898,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,   931,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    76,    77,    78,    -1,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    -1,    97,    -1,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,    -1,    -1,   165,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,   211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   226,   227,    -1,  1113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,     3,     4,     5,   259,
      -1,    -1,   262,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,  1207,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,  1367,  1368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,
       4,    -1,   259,    -1,     8,   262,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,  1460,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,  1469,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,
      -1,   165,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1630,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,   255,     3,     4,     5,    -1,   260,    -1,   262,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,   165,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
     211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,   255,     3,     4,    -1,   259,    -1,
      -1,   262,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,   259,   260,    -1,   262,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
     165,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
     255,     3,     4,    -1,   259,    -1,    -1,   262,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,    -1,
     258,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,   255,     3,     4,    -1,   259,    -1,    -1,
     262,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,    -1,    -1,   165,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,
     259,    -1,    -1,   262,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,
       3,     4,    -1,    -1,   260,    -1,   262,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
      -1,    -1,   165,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,
      -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,
     223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,   255,     3,     4,    -1,   259,    -1,    -1,   262,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,    -1,    -1,   165,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,   259,
      -1,    -1,   262,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,
       4,    -1,   259,    -1,     8,   262,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,
      -1,   165,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,    -1,
      -1,   255,     8,    -1,    10,    11,    12,    -1,   262,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,     3,     4,    -1,    -1,   255,
      -1,    -1,    10,    11,    12,    -1,   262,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,   259,    -1,    -1,   262,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
     165,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
     255,     3,     4,    -1,   259,    -1,    -1,   262,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,     3,
       4,     5,    -1,   255,    -1,    -1,    10,    11,    12,    -1,
     262,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    -1,    97,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   208,   209,   210,   211,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,   259,    -1,    -1,   262,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,     5,
     259,    -1,    -1,   262,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      -1,    97,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,   211,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,   259,    -1,    -1,   262,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
       3,     4,    -1,    -1,   255,    -1,    -1,    10,    11,    12,
      -1,   262,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    92,
      93,    -1,    95,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,   207,    -1,    -1,    -1,   211,    -1,
      -1,   264,    -1,    -1,   217,   218,   219,    -1,   221,   222,
     223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,   259,    -1,    -1,   262,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,   264,    -1,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,
       4,    -1,   259,    -1,     8,   262,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    92,    93,
      -1,    95,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,   207,    -1,    -1,    -1,   211,    -1,    -1,
     264,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,   262,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,   264,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,     3,     4,    -1,     6,   255,   256,    -1,
      10,    11,    12,    -1,   262,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   262,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,     3,     4,    -1,     6,   255,    -1,
      -1,    10,    11,    12,    -1,   262,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    92,    93,    -1,    95,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    95,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,   207,    -1,
      -1,    -1,   211,    -1,    -1,   264,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,   262,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,   264,    -1,   211,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,
     223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,
      -1,    -1,   255,   256,    -1,    10,    11,    12,    -1,   262,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    92,    93,    -1,
      95,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,   207,    -1,    -1,    -1,   211,    -1,    -1,   264,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
      -1,    -1,   227,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
     255,   256,    -1,    -1,    -1,    -1,    -1,   262,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    13,    14,    -1,    -1,    -1,    -1,   207,    -1,
     264,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   243,   244,    -1,   117,   118,   119,
     120,   250,    -1,   123,    -1,    -1,   255,    -1,    -1,    -1,
      -1,   131,   132,   262,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    13,    14,   117,   118,   119,   120,
      -1,    -1,   123,    -1,   184,   185,   186,    -1,    -1,    -1,
     131,   132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   185,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     159,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    13,    14,   117,   118,   119,
     120,    -1,    -1,   123,    -1,   184,   185,   186,    -1,    -1,
      -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   159,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    13,    14,   117,   118,
     119,   120,    -1,    -1,   123,    -1,   184,   185,   186,    -1,
      -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,   159,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    13,    14,   117,
     118,   119,   120,    -1,    -1,   123,    -1,   184,   185,   186,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,   159,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    13,    14,
     117,   118,   119,   120,    -1,    -1,   123,    -1,   184,   185,
     186,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,
     135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   159,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    13,
      14,   117,   118,   119,   120,    -1,    -1,   123,    -1,   184,
     185,   186,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,
      -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   159,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      13,    14,   117,   118,   119,   120,    -1,    -1,   123,    -1,
     184,   185,   186,    -1,    -1,    -1,   131,   132,    -1,    -1,
     135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,   159,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   185,   186,    -1,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    46,    47,    48,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,
      90,    91,    -1,    93,    -1,    -1,    -1,   260,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,   117,   118,   119,
     120,   121,    -1,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,   172,   173,   174,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   183,   184,   185,   186,    -1,    -1,   189,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,     4,    -1,
      -1,    -1,    -1,   213,   214,   215,   216,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      46,    47,    48,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   183,   184,   185,
     186,     4,     5,   189,    -1,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
      -1,   227,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,     4,     5,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,     4,
       5,   104,    -1,    -1,   107,    -1,   109,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   120,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,   138,     5,    78,    -1,    80,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    94,    -1,    -1,    97,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    94,
      -1,    -1,    97,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,   208,   209,   210,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,    -1,   226,   227,    94,    -1,    -1,    97,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,   208,   209,   210,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,   224,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,   224,    -1,   226,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    13,    14,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     163,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   184,   185,   186,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
     132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
     264,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   260,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     260,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   260,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     260,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   260,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,   260,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,   260,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     260,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   260,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     259,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,   259,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,   256,    -1,   258,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,   258,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,   258,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     258,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   258,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,   258,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,   258,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,   258,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   258,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,   258,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,   258,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     258,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
     256,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   266,   267,     6,     0,     4,    13,    14,    46,
      47,    48,    67,    68,    69,    74,    75,    79,    84,    85,
      86,    87,    88,    90,    91,    93,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   116,   117,   118,   119,   120,   121,   123,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   143,   144,   145,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     172,   173,   174,   178,   183,   184,   185,   186,   189,   191,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   213,   214,   215,   216,   225,   227,
     268,   270,   271,   292,   311,   313,   317,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   335,   337,   338,   344,
     345,   346,   347,   353,   377,   378,   259,   263,    14,   107,
     255,   255,   255,     6,   259,     6,     6,     6,     6,   255,
       6,     6,   259,   259,     6,     6,   257,   257,     4,   355,
     378,   255,   257,   289,   101,   104,   107,   109,   313,   289,
     255,   255,   255,     4,   255,   255,   255,     4,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   259,
     122,   107,     6,     6,   259,   101,   104,   107,   120,   316,
     109,   255,     3,    10,    11,    12,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    58,    59,    60,
      61,    66,    67,    76,    77,    81,    82,    83,    92,    95,
     101,   104,   107,   109,   120,   131,   136,   138,   141,   207,
     211,   212,   217,   218,   219,   221,   222,   223,   243,   244,
     250,   255,   259,   262,   313,   314,   317,   328,   335,   337,
     348,   349,   353,   355,   361,   363,   378,   255,   259,   259,
     107,   107,   131,   104,   107,   109,   313,   104,   107,   108,
     109,   120,   184,   314,   104,   107,   255,   104,   163,   189,
     205,   206,   259,   243,   244,   255,   259,   358,   359,   358,
     259,   259,   358,     4,   101,   105,   111,   112,   114,   115,
     135,   259,   255,   107,   109,   107,   104,     4,    93,   200,
     259,   378,     4,     6,   101,   104,   107,   104,   107,   120,
     315,   107,     4,     4,     4,     5,   255,   259,   361,   362,
       4,   107,   255,   107,   255,   255,     4,   259,   365,   378,
       4,   255,   255,   255,     6,     6,   257,     5,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    62,    63,    64,
      65,    70,    71,    72,    73,    78,    80,    94,    97,   208,
     209,   210,   220,   224,   226,   369,   378,   255,     4,   369,
       5,   259,     5,   259,   313,    32,   244,   348,   378,   257,
     259,   255,   259,     6,   255,   259,     6,   263,     7,   138,
     200,   228,   229,   230,   231,   252,   253,   255,   257,   261,
     287,   288,   289,   313,   348,   368,   369,   378,     4,   317,
     318,   319,   259,     6,   348,   368,   369,   378,   368,   368,
     348,   368,   375,   376,   378,   319,   348,   294,   298,   255,
     357,     9,   369,   255,   378,   348,   348,   348,   255,   348,
     348,   348,   255,   348,   348,   348,   348,   348,   348,   348,
     368,   348,   348,   348,   348,   362,   255,   244,   348,   363,
     364,   259,   362,   361,   368,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     255,   257,   289,   289,   289,   289,   289,   289,   255,   289,
     289,   255,   313,   314,   314,   289,   289,     5,   259,   259,
     131,   313,   313,   255,   289,   289,   255,   255,   255,   348,
     259,   348,   363,   348,   348,   260,   364,   355,   378,   192,
       5,   259,     8,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   254,     9,   255,   257,   261,   288,   289,   348,   364,
     364,   255,   255,   255,   361,   362,   362,   362,   312,   255,
     259,   255,   255,   361,   259,   259,   348,     4,   361,   259,
     365,   259,   259,   358,   358,   358,   348,   348,   243,   244,
     259,   259,   358,   243,   244,   255,   319,   358,   259,   255,
     259,   255,   255,   255,   255,   255,   255,   255,   364,   348,
     362,   362,   362,   255,   259,     4,   257,   259,     6,   257,
     319,     6,     6,   259,   259,   259,   259,   362,   259,   257,
     257,   257,   348,     8,     6,     6,   255,   348,   255,   348,
     348,   261,   348,   259,   192,   348,   348,   348,   348,   289,
     289,   289,   255,   255,   255,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   255,   255,   289,   255,   257,
       6,     6,   259,     6,     8,   319,     6,     8,   319,   255,
     289,   348,   245,   259,     9,   255,   257,   261,   368,   364,
     348,   319,   361,   361,   259,   369,   313,     7,   348,   348,
       4,    36,    37,   110,   111,   189,   190,   291,   361,     6,
     256,   258,   259,   290,   259,     6,   259,     6,     9,   255,
     257,   261,   378,   260,   131,   136,   138,   139,   141,   311,
     313,   348,     6,   256,   264,     9,   255,   257,   261,   256,
     264,   256,   264,   264,   256,   264,     9,   255,   261,   260,
     264,   258,   264,   293,   258,   293,    96,   356,   354,   378,
     264,   348,   264,   256,   256,   256,   348,   256,   256,   256,
     348,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   260,     7,   348,   245,   260,   264,   348,     6,
       6,   256,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   363,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   363,
     363,   378,   259,   348,   348,   368,   348,   368,   361,   368,
     368,   375,   259,   259,   259,   348,   290,   378,     8,   348,
     348,   362,   361,   368,   368,   363,   355,   369,   355,   364,
     256,   260,   261,   289,    67,     8,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     259,   348,   363,   348,   348,   348,   348,   348,   378,   348,
     348,   291,   259,   290,   256,   260,   260,   348,   348,   348,
       7,     7,   341,   341,   255,   348,   348,   348,   348,     6,
     364,   364,   259,   256,     6,   319,   259,   319,   319,   264,
     264,   264,   358,   358,   318,   318,   264,   348,   260,   332,
     264,   319,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   260,   256,     7,   342,     6,     7,   348,   348,     6,
     348,   319,   348,   260,   364,   364,   364,   348,     6,   364,
     348,   348,   348,   256,   260,   348,   256,   348,   256,   256,
     189,   264,   319,   259,     8,   256,   256,   258,   375,   368,
     375,   368,   368,   368,   368,   368,   368,   348,   368,   368,
     368,   368,   262,   371,   378,   369,   368,   368,   368,   355,
     378,   364,   260,   260,   260,   260,   348,   348,   348,   319,
     378,   291,   258,   260,   256,   145,   163,   336,   256,   260,
     264,   348,     6,   259,   361,   256,   258,   261,     7,     7,
     287,   288,     6,   364,     7,   231,   287,   348,   272,   378,
     348,   348,   291,   257,   255,   131,   313,   314,   313,   259,
     260,     6,   238,   239,   269,   364,   378,   348,   348,   291,
       6,   364,     6,   364,   348,     6,   368,   376,   378,   256,
     291,   348,     6,   378,     6,   368,   348,   256,   257,   348,
     264,   369,     7,     7,     7,   256,     7,     7,     7,   256,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     348,   256,   259,   348,   363,   260,     6,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   264,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   264,   264,
     264,   264,   264,   256,   258,   258,   364,   264,   264,   290,
     264,   290,   264,   264,   264,   256,   364,   348,   348,   350,
     290,   260,   260,   260,   264,   264,   290,   290,   256,   261,
     256,   261,   264,   289,   351,   260,     7,   291,   290,   361,
     260,     8,     8,   364,   261,   256,   258,   255,   257,   288,
     289,   364,     7,   259,   259,   256,   256,   256,   348,   361,
       4,   340,     6,   307,   348,   369,   256,   260,   256,   256,
     260,   260,   364,   261,   260,   319,   260,   260,   358,   348,
     348,   260,   260,   348,   358,   142,   142,   160,   169,   170,
     171,   175,   176,   333,   334,   358,   260,   329,   256,   260,
     256,   256,   256,   256,   256,   256,   256,   259,     7,   348,
       6,   348,   256,   260,   258,   260,   258,   260,   260,   260,
     260,   260,   258,   258,   264,   256,     7,   256,     7,     7,
     261,   348,   260,   348,   348,     7,   261,   290,   264,   290,
     290,   256,   256,   264,   290,   290,   264,   264,   290,   290,
     290,   290,   348,   290,     9,   370,   264,   256,   264,   290,
     261,   264,   352,   258,   260,   256,   260,   261,   255,   257,
     263,   192,     7,   163,     6,   348,   260,   259,     6,   361,
     260,   348,     6,     7,   287,   288,   261,   287,   288,   291,
     259,   366,   378,   369,   348,     6,   260,    49,    49,   361,
     260,     4,   179,   180,   181,   182,   260,   275,   279,   282,
     284,   285,   327,   261,   256,   258,   255,   348,   348,   255,
     259,   255,   259,     8,   364,   368,   256,   261,   256,   258,
     255,   256,   256,   264,   261,   255,   264,     7,   289,     4,
      36,    37,   301,   302,   303,   290,   348,   290,   358,   361,
     361,     7,   361,   361,   361,     7,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,     6,     7,   364,   348,
     348,   348,   348,   348,   348,   260,   348,   348,   348,   361,
     368,   368,   260,   260,   260,   264,   300,   348,   348,   291,
     291,   348,   348,   256,   361,   289,   348,   348,   260,   291,
     288,   261,   288,   348,   348,   290,   260,   361,   364,   364,
       7,     7,     7,   142,   339,     6,   256,   264,     7,     7,
       7,     7,     7,   260,     4,   291,   260,   264,   264,   264,
     260,   260,   119,     4,     6,   348,   259,     6,   255,     6,
     177,     6,   177,   260,   334,   264,   333,     7,     6,     7,
       7,     7,     7,     7,     7,     7,   318,   361,     6,   259,
     101,     6,     6,     6,   107,     7,     7,     6,     6,   348,
       7,   361,     7,   361,   361,     4,   264,     8,     8,   256,
     291,   291,   364,   368,   348,   368,   262,   264,   304,   368,
     368,   291,   368,   256,   264,     6,   291,   259,   313,   259,
       6,   348,     6,   259,   361,   260,   260,   348,     6,   189,
     190,   291,   348,     6,     7,   365,   367,     6,   257,     6,
       6,   290,   289,   289,     6,   276,   255,   255,   259,   286,
       6,   291,   261,   368,   348,   258,   256,   348,     8,   364,
     348,   364,   260,   260,     6,     6,   269,   291,   261,   348,
       6,     6,   348,   291,   256,   348,   259,   348,   369,   290,
      49,   259,   361,   369,   372,   348,   348,   258,   264,     6,
     256,     6,     6,   135,   309,   309,   361,     6,     6,     6,
     361,   142,   192,   308,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     5,   260,   290,   290,   290,   290,   290,
     290,   290,   264,   264,   264,   256,   290,   290,   302,   290,
     256,   290,   256,   289,   351,   290,     6,   290,   255,   257,
     289,   291,   256,   258,   290,     6,   260,   260,   361,   361,
     361,     4,     6,   287,   348,   361,   361,   361,   259,   259,
       7,     6,     7,   348,   348,   348,   259,   259,   259,   257,
       6,   348,   361,   348,     6,     6,   348,   358,   260,     5,
     361,   259,   259,   259,   259,   259,   259,   259,   361,   260,
       6,   364,   259,   259,   348,   348,   258,   361,     6,   361,
       6,   188,   348,   348,   348,     6,     6,     7,   290,   264,
     264,   290,   264,   348,     4,   204,   305,   306,   290,   256,
     290,   352,   369,   255,   257,   348,   259,   319,     6,   319,
     264,     6,     6,   261,     7,     7,   287,   288,     6,   365,
     260,   264,   348,   287,   259,   290,   373,   374,   375,   373,
     255,   348,   348,   360,   361,   259,   255,     4,     6,   256,
       6,   256,   260,   260,   256,   260,     6,     6,   368,   255,
       4,   256,   264,   255,   260,   264,   361,   369,     7,   289,
     299,   348,   363,   303,     6,   358,     6,     6,     6,   142,
     310,   101,   120,   105,     6,     5,   259,   348,   348,   348,
     348,   256,   351,   348,   348,   290,   288,   259,   259,     6,
     308,     6,   348,   361,   142,   142,     4,     6,   364,   364,
     348,   348,   369,   260,   256,   260,   264,   318,   318,   348,
     348,   260,   264,   256,   260,   264,     6,     6,   360,   358,
     358,   358,   358,   358,   244,   358,     6,   260,   364,   348,
       6,     6,     6,     6,     6,   361,   260,   264,     8,   260,
     256,   259,   348,   369,   368,   348,   368,   348,   369,   372,
     374,   369,   264,   256,   264,   260,   348,   336,   336,   361,
     291,   366,   369,   348,     6,     6,   365,   258,   361,   375,
       6,   290,   290,   273,   348,   264,   264,   260,   264,   274,
     348,   348,     6,     6,     6,     6,   348,   348,   256,     6,
     348,   295,   297,   259,   374,   260,   264,     7,     7,   146,
       6,   259,   259,   259,     5,   360,   290,   290,   264,   290,
     256,   256,   258,   364,   364,     6,     6,   348,   348,   259,
     260,   260,   259,     6,     6,   259,   348,   260,   260,   260,
     258,     6,   361,     7,   259,   348,   260,   264,   264,   264,
     264,   264,   264,     6,   260,   260,   187,   348,   348,   364,
       6,     6,   256,   290,   290,   306,   369,   260,   260,   260,
     260,     7,     6,     6,     6,   261,     6,   260,     6,     6,
     256,   264,   348,   348,   259,   361,   260,   264,   256,   256,
     264,   260,   300,   304,   361,   290,   348,   369,   378,   364,
     364,   348,     6,   260,   348,   351,   260,   260,     6,     6,
     360,   147,   148,   153,   343,   147,   148,   343,   364,   318,
     260,   264,     6,   260,   361,   319,   260,     6,   364,   358,
     358,   358,   358,   358,     6,   348,   260,   260,   260,   256,
       6,   259,     6,   365,   190,   277,   348,   264,   264,   360,
       6,   348,   348,     6,   260,   260,   296,     7,   255,   260,
     260,   260,   259,   264,   256,   259,   260,   259,   358,   361,
       6,   259,   358,     6,   260,   260,   348,     6,   142,   260,
     330,   259,   260,   264,   264,   264,   264,   264,     6,     6,
       6,   319,     6,   259,   348,   348,   260,   264,   300,   369,
     256,   348,   348,   364,     6,   358,     6,   358,     6,     6,
     260,   348,   333,   319,     6,   364,   364,   364,   364,   358,
     364,   336,   274,   256,   264,     6,   259,   348,   260,   264,
     264,   260,   264,   264,     6,   260,   260,   331,   260,   260,
     260,   260,   264,   260,   260,   260,   280,   348,   360,   260,
     348,   348,   358,   358,   333,     6,     6,     6,     6,   364,
       6,     6,     6,   259,   256,   260,     6,   260,   290,   264,
     264,   260,   260,   278,   368,   283,   259,     6,   348,   348,
       6,   260,   264,   259,   360,   260,   260,     6,   368,   281,
     368,   260,     6,     6,   260,   264,     6,     6,   368
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
#line 272 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 283 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 284 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 285 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 287 "Gmsh.y"
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
#line 305 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 306 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 307 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 308 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 310 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 311 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 312 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 315 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 316 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 317 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 318 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 319 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 320 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 325 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 329 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 336 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 341 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 346 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 31:
#line 351 "Gmsh.y"
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
#line 365 "Gmsh.y"
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
#line 378 "Gmsh.y"
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
#line 391 "Gmsh.y"
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
#line 404 "Gmsh.y"
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
#line 432 "Gmsh.y"
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
#line 446 "Gmsh.y"
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
#line 459 "Gmsh.y"
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
#line 472 "Gmsh.y"
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
#line 490 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 47:
#line 505 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 48:
#line 507 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 49:
#line 512 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 50:
#line 514 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 51:
#line 519 "Gmsh.y"
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
#line 623 "Gmsh.y"
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
#line 633 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 54:
#line 642 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 649 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 659 "Gmsh.y"
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
#line 668 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 58:
#line 677 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 59:
#line 684 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 60:
#line 694 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 61:
#line 702 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 62:
#line 712 "Gmsh.y"
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
#line 731 "Gmsh.y"
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
#line 750 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 65:
#line 756 "Gmsh.y"
    {
    ;}
    break;

  case 66:
#line 763 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 67:
#line 764 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 765 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 69:
#line 766 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 70:
#line 767 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 71:
#line 771 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 72:
#line 772 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 73:
#line 778 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 74:
#line 778 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 75:
#line 780 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 76:
#line 780 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 785 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 78:
#line 786 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 79:
#line 787 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 80:
#line 788 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 789 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 799 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 804 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 810 "Gmsh.y"
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
#line 872 "Gmsh.y"
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
#line 887 "Gmsh.y"
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
#line 916 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 926 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 931 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 939 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 944 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 952 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 961 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 966 "Gmsh.y"
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
#line 978 "Gmsh.y"
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
#line 995 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 1001 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 1010 "Gmsh.y"
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
#line 1028 "Gmsh.y"
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
#line 1046 "Gmsh.y"
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
#line 1055 "Gmsh.y"
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
#line 1067 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 1072 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1080 "Gmsh.y"
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
#line 1100 "Gmsh.y"
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
#line 1123 "Gmsh.y"
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
#line 1143 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1151 "Gmsh.y"
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
#line 1173 "Gmsh.y"
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
#line 1196 "Gmsh.y"
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
#line 1234 "Gmsh.y"
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
#line 1255 "Gmsh.y"
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
#line 1267 "Gmsh.y"
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
#line 1285 "Gmsh.y"
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
#line 1294 "Gmsh.y"
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
#line 1303 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1305 "Gmsh.y"
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
#line 1323 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1325 "Gmsh.y"
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
#line 1341 "Gmsh.y"
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
#line 1350 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1352 "Gmsh.y"
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
#line 1366 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1374 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1380 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1385 "Gmsh.y"
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
#line 1428 "Gmsh.y"
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
#line 1440 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1444 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1448 "Gmsh.y"
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
#line 1461 "Gmsh.y"
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
#line 1475 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1483 "Gmsh.y"
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
#line 1508 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 152:
#line 1516 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 153:
#line 1525 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1533 "Gmsh.y"
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
#line 1547 "Gmsh.y"
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
#line 1565 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1569 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1576 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1584 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 160:
#line 1588 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 161:
#line 1594 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 162:
#line 1598 "Gmsh.y"
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
#line 1609 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 164:
#line 1613 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 165:
#line 1619 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 166:
#line 1623 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 167:
#line 1629 "Gmsh.y"
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
#line 1652 "Gmsh.y"
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
#line 1668 "Gmsh.y"
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
#line 1684 "Gmsh.y"
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
#line 1701 "Gmsh.y"
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
#line 1718 "Gmsh.y"
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
#line 1755 "Gmsh.y"
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
#line 1799 "Gmsh.y"
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
#line 1815 "Gmsh.y"
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
#line 1832 "Gmsh.y"
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
#line 1863 "Gmsh.y"
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
#line 1879 "Gmsh.y"
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
#line 1896 "Gmsh.y"
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
#line 1912 "Gmsh.y"
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
#line 1962 "Gmsh.y"
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
#line 1980 "Gmsh.y"
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
#line 2001 "Gmsh.y"
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
#line 2022 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 185:
#line 2028 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 186:
#line 2034 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 187:
#line 2041 "Gmsh.y"
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
#line 2072 "Gmsh.y"
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
#line 2087 "Gmsh.y"
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
#line 2109 "Gmsh.y"
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
#line 2132 "Gmsh.y"
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
#line 2155 "Gmsh.y"
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
#line 2178 "Gmsh.y"
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
#line 2202 "Gmsh.y"
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
#line 2226 "Gmsh.y"
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
#line 2250 "Gmsh.y"
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
#line 2276 "Gmsh.y"
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
#line 2293 "Gmsh.y"
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
#line 2309 "Gmsh.y"
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
#line 2327 "Gmsh.y"
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
#line 2345 "Gmsh.y"
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
#line 2358 "Gmsh.y"
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
#line 2370 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 204:
#line 2374 "Gmsh.y"
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
#line 2400 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 206:
#line 2402 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 207:
#line 2404 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 208:
#line 2406 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 209:
#line 2408 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 210:
#line 2416 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 211:
#line 2418 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 212:
#line 2420 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 213:
#line 2422 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 214:
#line 2430 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 215:
#line 2432 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 216:
#line 2434 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 217:
#line 2442 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 218:
#line 2444 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 219:
#line 2446 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 220:
#line 2448 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 221:
#line 2458 "Gmsh.y"
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
#line 2474 "Gmsh.y"
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
#line 2490 "Gmsh.y"
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
#line 2506 "Gmsh.y"
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
#line 2522 "Gmsh.y"
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
#line 2538 "Gmsh.y"
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
#line 2555 "Gmsh.y"
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
#line 2592 "Gmsh.y"
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
#line 2613 "Gmsh.y"
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
#line 2634 "Gmsh.y"
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
#line 2659 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 232:
#line 2660 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 233:
#line 2665 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 234:
#line 2669 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 235:
#line 2673 "Gmsh.y"
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
#line 2690 "Gmsh.y"
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
#line 2710 "Gmsh.y"
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
#line 2730 "Gmsh.y"
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
#line 2749 "Gmsh.y"
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
#line 2776 "Gmsh.y"
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
#line 2795 "Gmsh.y"
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
#line 2817 "Gmsh.y"
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
#line 2832 "Gmsh.y"
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
#line 2847 "Gmsh.y"
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
#line 2866 "Gmsh.y"
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
#line 2917 "Gmsh.y"
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
#line 2938 "Gmsh.y"
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
#line 2960 "Gmsh.y"
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
#line 2982 "Gmsh.y"
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
#line 3087 "Gmsh.y"
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
#line 3103 "Gmsh.y"
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
#line 3138 "Gmsh.y"
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
#line 3160 "Gmsh.y"
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
#line 3182 "Gmsh.y"
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
#line 3194 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 256:
#line 3200 "Gmsh.y"
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
#line 3215 "Gmsh.y"
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
#line 3246 "Gmsh.y"
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
#line 3258 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 260:
#line 3267 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 261:
#line 3274 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 262:
#line 3286 "Gmsh.y"
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
#line 3306 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 264:
#line 3310 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 265:
#line 3315 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 266:
#line 3319 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 267:
#line 3324 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 268:
#line 3331 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 269:
#line 3338 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 270:
#line 3345 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 271:
#line 3357 "Gmsh.y"
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
#line 3430 "Gmsh.y"
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
#line 3448 "Gmsh.y"
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
#line 3473 "Gmsh.y"
    {
#if defined(HAVE_POST) && defined(HAVE_MESH)
      if(!strcmp((yyvsp[(1) - (7)].c), "Background") && !strcmp((yyvsp[(2) - (7)].c), "Mesh")  && !strcmp((yyvsp[(3) - (7)].c), "View")){
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
#line 3488 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(1) - (3)].c), "Sleep")){
	SleepInSeconds((yyvsp[(2) - (3)].d));
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Remesh")){
	yymsg(0, "Surface remeshing must be reinterfaced");
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "Mesh")){
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
      else if(!strcmp((yyvsp[(1) - (3)].c), "SetOrder")){
#if defined(HAVE_MESH)
        SetOrderN(GModel::current(), (yyvsp[(2) - (3)].d), CTX::instance()->mesh.secondOrderLinear,
                  CTX::instance()->mesh.secondOrderIncomplete,
                  CTX::instance()->mesh.meshOnlyVisible);
#endif
      }
      else if(!strcmp((yyvsp[(1) - (3)].c), "PartitionMesh")){
        GModel::current()->partitionMesh((yyvsp[(2) - (3)].d));
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (3)].c));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 276:
#line 3521 "Gmsh.y"
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

  case 277:
#line 3533 "Gmsh.y"
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

  case 278:
#line 3565 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 279:
#line 3569 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 280:
#line 3574 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 281:
#line 3581 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 282:
#line 3586 "Gmsh.y"
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

  case 283:
#line 3596 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 284:
#line 3601 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 285:
#line 3607 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 286:
#line 3615 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals! Make it optional?
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 287:
#line 3623 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 288:
#line 3627 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 289:
#line 3631 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 290:
#line 3635 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      GModel::current()->createGeometryOfDiscreteEntities(dimTags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 291:
#line 3642 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 292:
#line 3646 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 293:
#line 3650 "Gmsh.y"
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

  case 294:
#line 3662 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 295:
#line 3672 "Gmsh.y"
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

  case 296:
#line 3735 "Gmsh.y"
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

  case 297:
#line 3751 "Gmsh.y"
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

  case 298:
#line 3768 "Gmsh.y"
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

  case 299:
#line 3785 "Gmsh.y"
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

  case 300:
#line 3807 "Gmsh.y"
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

  case 301:
#line 3829 "Gmsh.y"
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

  case 302:
#line 3864 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 303:
#line 3872 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 304:
#line 3880 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 305:
#line 3886 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 306:
#line 3893 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 307:
#line 3900 "Gmsh.y"
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

  case 308:
#line 3920 "Gmsh.y"
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

  case 309:
#line 3946 "Gmsh.y"
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

  case 310:
#line 3958 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 311:
#line 3969 "Gmsh.y"
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

  case 312:
#line 3987 "Gmsh.y"
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

  case 313:
#line 4005 "Gmsh.y"
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

  case 314:
#line 4023 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4029 "Gmsh.y"
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

  case 316:
#line 4047 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4053 "Gmsh.y"
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

  case 318:
#line 4073 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4079 "Gmsh.y"
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

  case 320:
#line 4097 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 321:
#line 4103 "Gmsh.y"
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

  case 322:
#line 4120 "Gmsh.y"
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

  case 323:
#line 4136 "Gmsh.y"
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

  case 324:
#line 4153 "Gmsh.y"
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

  case 325:
#line 4171 "Gmsh.y"
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

  case 326:
#line 4194 "Gmsh.y"
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

  case 327:
#line 4221 "Gmsh.y"
    {
    ;}
    break;

  case 328:
#line 4224 "Gmsh.y"
    {
    ;}
    break;

  case 329:
#line 4230 "Gmsh.y"
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

  case 330:
#line 4242 "Gmsh.y"
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

  case 331:
#line 4262 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 332:
#line 4266 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 333:
#line 4270 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 334:
#line 4274 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 335:
#line 4278 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 336:
#line 4282 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 337:
#line 4286 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 338:
#line 4290 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 339:
#line 4299 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 340:
#line 4311 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 341:
#line 4312 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 342:
#line 4313 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 343:
#line 4314 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 344:
#line 4315 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 345:
#line 4319 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 346:
#line 4320 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 347:
#line 4321 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 348:
#line 4322 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 349:
#line 4323 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 350:
#line 4328 "Gmsh.y"
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

  case 351:
#line 4351 "Gmsh.y"
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

  case 352:
#line 4371 "Gmsh.y"
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

  case 353:
#line 4392 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 354:
#line 4396 "Gmsh.y"
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

  case 355:
#line 4411 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 356:
#line 4415 "Gmsh.y"
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

  case 357:
#line 4431 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 358:
#line 4435 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 359:
#line 4440 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 360:
#line 4444 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 361:
#line 4450 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 362:
#line 4454 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 363:
#line 4461 "Gmsh.y"
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

  case 364:
#line 4483 "Gmsh.y"
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

  case 365:
#line 4524 "Gmsh.y"
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

  case 366:
#line 4568 "Gmsh.y"
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

  case 367:
#line 4607 "Gmsh.y"
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

  case 368:
#line 4632 "Gmsh.y"
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

  case 369:
#line 4645 "Gmsh.y"
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

  case 370:
#line 4656 "Gmsh.y"
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

  case 371:
#line 4673 "Gmsh.y"
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

  case 372:
#line 4690 "Gmsh.y"
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

  case 373:
#line 4720 "Gmsh.y"
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

  case 374:
#line 4746 "Gmsh.y"
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

  case 375:
#line 4773 "Gmsh.y"
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

  case 376:
#line 4805 "Gmsh.y"
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

  case 377:
#line 4832 "Gmsh.y"
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

  case 378:
#line 4858 "Gmsh.y"
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

  case 379:
#line 4884 "Gmsh.y"
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

  case 380:
#line 4910 "Gmsh.y"
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

  case 381:
#line 4936 "Gmsh.y"
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

  case 382:
#line 4957 "Gmsh.y"
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

  case 383:
#line 4968 "Gmsh.y"
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

  case 384:
#line 5016 "Gmsh.y"
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

  case 385:
#line 5070 "Gmsh.y"
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

  case 386:
#line 5085 "Gmsh.y"
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

  case 387:
#line 5097 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 388:
#line 5108 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 389:
#line 5115 "Gmsh.y"
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

  case 390:
#line 5130 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 391:
#line 5143 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 392:
#line 5144 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 393:
#line 5145 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 394:
#line 5150 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 395:
#line 5156 "Gmsh.y"
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

  case 396:
#line 5168 "Gmsh.y"
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

  case 397:
#line 5186 "Gmsh.y"
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

  case 398:
#line 5213 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 399:
#line 5214 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 400:
#line 5215 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 401:
#line 5216 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 402:
#line 5217 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 403:
#line 5218 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5219 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5220 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 406:
#line 5222 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 407:
#line 5228 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 408:
#line 5229 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 409:
#line 5230 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 410:
#line 5231 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 411:
#line 5232 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5233 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 413:
#line 5234 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5235 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5236 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5237 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5238 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5239 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 419:
#line 5240 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 420:
#line 5241 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 421:
#line 5242 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 422:
#line 5243 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5244 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5245 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 425:
#line 5246 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5247 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5248 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5249 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5250 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5251 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 431:
#line 5252 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5253 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 433:
#line 5254 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5255 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5256 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5257 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5258 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 438:
#line 5259 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 439:
#line 5260 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 440:
#line 5261 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 441:
#line 5262 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 442:
#line 5263 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5264 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5265 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 445:
#line 5266 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5267 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 447:
#line 5276 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 448:
#line 5277 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 449:
#line 5278 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 450:
#line 5279 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 451:
#line 5280 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 452:
#line 5281 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 453:
#line 5282 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 454:
#line 5283 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 455:
#line 5284 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 456:
#line 5285 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 457:
#line 5286 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 458:
#line 5291 "Gmsh.y"
    { init_options(); ;}
    break;

  case 459:
#line 5293 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 460:
#line 5299 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 461:
#line 5303 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5308 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 463:
#line 5313 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 464:
#line 5318 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 465:
#line 5323 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 466:
#line 5327 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 467:
#line 5331 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 468:
#line 5335 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 469:
#line 5339 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 470:
#line 5343 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 471:
#line 5347 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 472:
#line 5351 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 473:
#line 5357 "Gmsh.y"
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

  case 474:
#line 5372 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 475:
#line 5376 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 476:
#line 5382 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 477:
#line 5387 "Gmsh.y"
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

  case 478:
#line 5406 "Gmsh.y"
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

  case 479:
#line 5426 "Gmsh.y"
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
#line 5447 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 481:
#line 5451 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 482:
#line 5455 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 483:
#line 5459 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 484:
#line 5463 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 485:
#line 5467 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 486:
#line 5471 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 487:
#line 5476 "Gmsh.y"
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

  case 488:
#line 5486 "Gmsh.y"
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

  case 489:
#line 5496 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 490:
#line 5501 "Gmsh.y"
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

  case 491:
#line 5512 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 492:
#line 5521 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 493:
#line 5526 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 494:
#line 5531 "Gmsh.y"
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

  case 495:
#line 5558 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 496:
#line 5560 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 497:
#line 5565 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 498:
#line 5567 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 499:
#line 5572 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 500:
#line 5579 "Gmsh.y"
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

  case 501:
#line 5595 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 502:
#line 5597 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 503:
#line 5602 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 504:
#line 5604 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 505:
#line 5609 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 506:
#line 5611 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 507:
#line 5616 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 508:
#line 5620 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 509:
#line 5624 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 510:
#line 5628 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 511:
#line 5632 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 512:
#line 5639 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 513:
#line 5643 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 514:
#line 5647 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 515:
#line 5651 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 516:
#line 5658 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 517:
#line 5663 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 518:
#line 5670 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 519:
#line 5675 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 520:
#line 5679 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 521:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 522:
#line 5688 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 523:
#line 5696 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 524:
#line 5707 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 525:
#line 5711 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 526:
#line 5715 "Gmsh.y"
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

  case 527:
#line 5729 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 528:
#line 5737 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 529:
#line 5745 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 530:
#line 5752 "Gmsh.y"
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

  case 531:
#line 5762 "Gmsh.y"
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

  case 532:
#line 5785 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 533:
#line 5790 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 534:
#line 5796 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 535:
#line 5801 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 536:
#line 5807 "Gmsh.y"
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

  case 537:
#line 5818 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 538:
#line 5824 "Gmsh.y"
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

  case 539:
#line 5838 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 540:
#line 5844 "Gmsh.y"
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

  case 541:
#line 5856 "Gmsh.y"
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

  case 542:
#line 5870 "Gmsh.y"
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

  case 543:
#line 5880 "Gmsh.y"
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

  case 544:
#line 5890 "Gmsh.y"
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
#line 5900 "Gmsh.y"
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

  case 546:
#line 5912 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 547:
#line 5916 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 548:
#line 5921 "Gmsh.y"
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

  case 549:
#line 5933 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 550:
#line 5937 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 551:
#line 5941 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 552:
#line 5945 "Gmsh.y"
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

  case 553:
#line 5963 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 554:
#line 5971 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 555:
#line 5979 "Gmsh.y"
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

  case 556:
#line 6008 "Gmsh.y"
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

  case 557:
#line 6018 "Gmsh.y"
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

  case 558:
#line 6034 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 559:
#line 6045 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 560:
#line 6050 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 561:
#line 6054 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 562:
#line 6058 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 563:
#line 6070 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 564:
#line 6074 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 565:
#line 6086 "Gmsh.y"
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

  case 566:
#line 6103 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 567:
#line 6113 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 568:
#line 6117 "Gmsh.y"
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

  case 569:
#line 6132 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 570:
#line 6137 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 571:
#line 6144 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 572:
#line 6148 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 573:
#line 6153 "Gmsh.y"
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

  case 574:
#line 6167 "Gmsh.y"
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

  case 575:
#line 6181 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 576:
#line 6185 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 577:
#line 6189 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 578:
#line 6193 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 579:
#line 6197 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 580:
#line 6205 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 581:
#line 6211 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 582:
#line 6220 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 583:
#line 6224 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 584:
#line 6228 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 585:
#line 6236 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 586:
#line 6242 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 587:
#line 6248 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 588:
#line 6252 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 589:
#line 6259 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 590:
#line 6267 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 591:
#line 6274 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 592:
#line 6283 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 593:
#line 6287 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 594:
#line 6291 "Gmsh.y"
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

  case 595:
#line 6306 "Gmsh.y"
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

  case 596:
#line 6320 "Gmsh.y"
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

  case 597:
#line 6334 "Gmsh.y"
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

  case 598:
#line 6346 "Gmsh.y"
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

  case 599:
#line 6362 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 600:
#line 6371 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 601:
#line 6380 "Gmsh.y"
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

  case 602:
#line 6390 "Gmsh.y"
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

  case 603:
#line 6401 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 604:
#line 6409 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 605:
#line 6417 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 606:
#line 6421 "Gmsh.y"
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

  case 607:
#line 6440 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 608:
#line 6447 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 609:
#line 6453 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 610:
#line 6459 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6466 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 612:
#line 6473 "Gmsh.y"
    { init_options(); ;}
    break;

  case 613:
#line 6475 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 614:
#line 6483 "Gmsh.y"
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

  case 615:
#line 6507 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 616:
#line 6509 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 617:
#line 6515 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 618:
#line 6520 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 619:
#line 6522 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 620:
#line 6527 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 621:
#line 6532 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 622:
#line 6537 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 623:
#line 6539 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 624:
#line 6543 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 625:
#line 6555 "Gmsh.y"
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

  case 626:
#line 6569 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 627:
#line 6573 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 628:
#line 6580 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 629:
#line 6588 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 630:
#line 6596 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 631:
#line 6607 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 632:
#line 6609 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 633:
#line 6612 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14797 "Gmsh.tab.cpp"
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


#line 6615 "Gmsh.y"


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

