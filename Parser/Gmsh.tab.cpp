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
#define YYLAST   17695

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  631
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2249

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
     873,   882,   892,   901,   905,   910,   921,   929,   937,   945,
     953,   961,   969,   977,   985,   993,  1001,  1011,  1019,  1027,
    1036,  1045,  1058,  1059,  1069,  1071,  1073,  1075,  1077,  1082,
    1084,  1086,  1088,  1093,  1095,  1097,  1102,  1104,  1106,  1108,
    1113,  1119,  1131,  1137,  1147,  1157,  1165,  1170,  1180,  1191,
    1201,  1203,  1205,  1206,  1209,  1216,  1224,  1232,  1239,  1247,
    1256,  1267,  1282,  1299,  1312,  1327,  1342,  1357,  1372,  1381,
    1390,  1397,  1402,  1408,  1414,  1421,  1428,  1432,  1437,  1441,
    1447,  1454,  1460,  1465,  1469,  1474,  1478,  1483,  1489,  1494,
    1500,  1504,  1510,  1518,  1526,  1530,  1538,  1542,  1545,  1548,
    1551,  1554,  1557,  1573,  1576,  1579,  1582,  1592,  1604,  1607,
    1610,  1613,  1616,  1619,  1636,  1648,  1655,  1664,  1673,  1684,
    1686,  1689,  1692,  1694,  1698,  1702,  1707,  1712,  1714,  1716,
    1722,  1734,  1748,  1749,  1757,  1758,  1772,  1773,  1789,  1790,
    1797,  1807,  1810,  1814,  1825,  1839,  1841,  1844,  1850,  1858,
    1861,  1864,  1868,  1871,  1875,  1878,  1882,  1892,  1899,  1901,
    1903,  1905,  1907,  1909,  1910,  1913,  1917,  1921,  1926,  1936,
    1941,  1956,  1957,  1961,  1962,  1964,  1965,  1968,  1969,  1972,
    1973,  1976,  1983,  1991,  1998,  2004,  2008,  2017,  2024,  2033,
    2042,  2048,  2053,  2060,  2072,  2084,  2103,  2122,  2135,  2148,
    2161,  2172,  2177,  2182,  2187,  2192,  2197,  2200,  2204,  2211,
    2213,  2215,  2217,  2220,  2226,  2234,  2245,  2247,  2251,  2254,
    2257,  2260,  2264,  2268,  2272,  2276,  2280,  2284,  2288,  2292,
    2296,  2300,  2304,  2308,  2312,  2316,  2320,  2324,  2328,  2332,
    2338,  2343,  2348,  2353,  2358,  2363,  2368,  2373,  2378,  2383,
    2388,  2395,  2400,  2405,  2410,  2415,  2420,  2425,  2430,  2435,
    2442,  2449,  2456,  2461,  2468,  2475,  2477,  2479,  2481,  2483,
    2485,  2487,  2489,  2491,  2493,  2495,  2497,  2498,  2505,  2507,
    2512,  2519,  2521,  2526,  2531,  2536,  2543,  2549,  2557,  2566,
    2577,  2582,  2587,  2594,  2599,  2603,  2606,  2612,  2618,  2622,
    2628,  2635,  2644,  2651,  2660,  2667,  2672,  2680,  2687,  2694,
    2701,  2706,  2713,  2718,  2719,  2722,  2723,  2726,  2727,  2735,
    2737,  2741,  2743,  2746,  2747,  2751,  2753,  2756,  2759,  2763,
    2767,  2779,  2789,  2797,  2805,  2807,  2811,  2813,  2815,  2818,
    2822,  2827,  2833,  2835,  2839,  2841,  2844,  2848,  2852,  2858,
    2863,  2868,  2871,  2876,  2879,  2883,  2887,  2892,  2898,  2904,
    2910,  2912,  2914,  2916,  2920,  2926,  2934,  2939,  2944,  2949,
    2956,  2963,  2972,  2981,  2986,  3001,  3006,  3011,  3013,  3015,
    3019,  3023,  3033,  3041,  3043,  3049,  3053,  3060,  3062,  3066,
    3068,  3070,  3075,  3080,  3084,  3090,  3097,  3106,  3113,  3118,
    3124,  3126,  3131,  3133,  3135,  3137,  3139,  3144,  3151,  3156,
    3163,  3169,  3177,  3182,  3187,  3192,  3201,  3206,  3211,  3216,
    3221,  3230,  3239,  3246,  3251,  3258,  3263,  3265,  3267,  3272,
    3277,  3278,  3285,  3290,  3293,  3298,  3303,  3305,  3307,  3311,
    3313,  3315,  3319,  3323,  3327,  3333,  3341,  3347,  3353,  3362,
    3364,  3366
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
      -1,    13,    14,     6,    -1,    14,   107,   348,     6,    -1,
     123,   107,   255,   348,   256,     7,     5,     5,     5,     6,
      -1,   105,   255,   348,   256,     7,   361,     6,    -1,   106,
     255,   348,   256,     7,   361,     6,    -1,   110,   255,   348,
     256,     7,   361,     6,    -1,   113,   255,   348,   256,     7,
     361,     6,    -1,   117,   255,   348,   256,     7,   361,     6,
      -1,   118,   255,   348,   256,     7,   361,     6,    -1,   111,
     255,   348,   256,     7,   361,     6,    -1,   112,   255,   348,
     256,     7,   361,     6,    -1,   132,   255,   348,   256,     7,
     361,     6,    -1,   159,   255,   348,   256,     7,   361,     6,
      -1,   107,     4,   255,   348,   256,     7,   361,   310,     6,
      -1,   109,   255,   348,   256,     7,   361,     6,    -1,   131,
     255,   348,   256,     7,   361,     6,    -1,   136,   131,   255,
     348,   256,     7,   361,     6,    -1,   139,   314,   255,   348,
     256,     7,   361,     6,    -1,   139,   314,   255,   348,   256,
       7,   361,     4,   259,   360,   260,     6,    -1,    -1,   138,
     313,   312,   255,   307,   256,   287,   361,     6,    -1,   101,
      -1,   104,    -1,   107,    -1,   109,    -1,   120,   259,   348,
     260,    -1,   104,    -1,   107,    -1,   109,    -1,   120,   259,
     348,   260,    -1,   104,    -1,   107,    -1,   120,   259,   348,
     260,    -1,   101,    -1,   104,    -1,   107,    -1,   120,   259,
     348,   260,    -1,   148,   358,   259,   318,   260,    -1,   147,
     259,   358,   264,   358,   264,   348,   260,   259,   318,   260,
      -1,   149,   358,   259,   318,   260,    -1,   150,   259,   358,
     264,   348,   260,   259,   318,   260,    -1,   150,   259,   358,
     264,   358,   260,   259,   318,   260,    -1,   153,   259,   364,
     260,   259,   318,   260,    -1,     4,   259,   318,   260,    -1,
     165,   104,   259,   364,   260,   107,   259,   348,   260,    -1,
     162,   104,   259,   348,   260,   101,   259,   364,   260,     6,
      -1,   162,   104,   255,   348,   256,   259,   364,   260,     6,
      -1,   319,    -1,   317,    -1,    -1,   319,   311,    -1,   319,
     313,   259,   364,   260,     6,    -1,   319,   138,   313,   259,
     364,   260,     6,    -1,   319,   141,   313,   259,   364,   260,
       6,    -1,   319,   313,   259,     8,   260,     6,    -1,   319,
     138,   313,   259,     8,   260,     6,    -1,   152,   135,   255,
     348,   256,     7,   361,     6,    -1,   152,   101,   255,   348,
     256,     7,   259,   360,   260,     6,    -1,   152,   135,   255,
     348,   256,     7,   259,   358,   264,   358,   264,   364,   260,
       6,    -1,   152,   135,   255,   348,   256,     7,   259,   358,
     264,   358,   264,   358,   264,   364,   260,     6,    -1,   152,
     105,   255,   348,   256,     7,   259,   358,   264,   364,   260,
       6,    -1,   152,   111,   255,   348,   256,     7,   259,   358,
     264,   358,   264,   364,   260,     6,    -1,   152,   112,   255,
     348,   256,     7,   259,   358,   264,   358,   264,   364,   260,
       6,    -1,   152,   114,   255,   348,   256,     7,   259,   358,
     264,   358,   264,   364,   260,     6,    -1,   152,   115,   255,
     348,   256,     7,   259,   358,   264,   358,   264,   364,   260,
       6,    -1,   152,     4,   255,   348,   256,     7,   361,     6,
      -1,   152,     4,   255,   348,   256,     7,     5,     6,    -1,
     152,     4,   259,   348,   260,     6,    -1,   163,   259,   319,
     260,    -1,   145,   163,   259,   319,   260,    -1,   163,     4,
     259,   319,   260,    -1,   163,   200,   257,   348,   258,     6,
      -1,   163,     4,   257,   348,   258,     6,    -1,   163,   378,
       6,    -1,   163,     4,     4,     6,    -1,   163,    93,     6,
      -1,   189,   365,   259,   319,   260,    -1,   145,   189,   365,
     259,   319,   260,    -1,   225,   348,   259,   319,   260,    -1,
     205,   259,     8,   260,    -1,   205,     5,     6,    -1,   206,
     259,     8,   260,    -1,   206,     5,     6,    -1,   205,   259,
     319,   260,    -1,   145,   205,   259,   319,   260,    -1,   206,
     259,   319,   260,    -1,   145,   206,   259,   319,   260,    -1,
     378,   369,     6,    -1,    79,   255,   375,   256,     6,    -1,
     378,   378,   257,   348,   258,   368,     6,    -1,   378,   378,
     378,   257,   348,   258,     6,    -1,   378,   348,     6,    -1,
     143,   255,     4,   256,   261,     4,     6,    -1,   183,     4,
       6,    -1,   198,     6,    -1,   199,     6,    -1,    74,     6,
      -1,    75,     6,    -1,    67,     6,    -1,    67,   259,   348,
     264,   348,   264,   348,   264,   348,   264,   348,   264,   348,
     260,     6,    -1,    68,     6,    -1,    69,     6,    -1,    84,
       6,    -1,    86,   259,   348,   264,   348,   264,   348,   260,
       6,    -1,    86,   259,   348,   264,   348,   264,   348,   264,
     348,   260,     6,    -1,    85,     6,    -1,    87,     6,    -1,
      88,     6,    -1,   125,     6,    -1,   126,     6,    -1,   127,
     259,   364,   260,   259,   364,   260,   259,   360,   260,   259,
     348,   264,   348,   260,     6,    -1,   203,   255,   259,   364,
     260,   264,   369,   264,   369,   256,     6,    -1,   191,   255,
     348,     8,   348,   256,    -1,   191,   255,   348,     8,   348,
       8,   348,   256,    -1,   191,     4,   192,   259,   348,     8,
     348,   260,    -1,   191,     4,   192,   259,   348,     8,   348,
       8,   348,   260,    -1,   193,    -1,   204,     4,    -1,   204,
     369,    -1,   201,    -1,   202,   378,     6,    -1,   202,   369,
       6,    -1,   194,   255,   348,   256,    -1,   195,   255,   348,
     256,    -1,   196,    -1,   197,    -1,   151,   358,   259,   319,
     260,    -1,   151,   259,   358,   264,   358,   264,   348,   260,
     259,   319,   260,    -1,   151,   259,   358,   264,   358,   264,
     358,   264,   348,   260,   259,   319,   260,    -1,    -1,   151,
     358,   259,   319,   329,   333,   260,    -1,    -1,   151,   259,
     358,   264,   358,   264,   348,   260,   259,   319,   330,   333,
     260,    -1,    -1,   151,   259,   358,   264,   358,   264,   358,
     264,   348,   260,   259,   319,   331,   333,   260,    -1,    -1,
     151,   259,   319,   332,   333,   260,    -1,   151,   259,   319,
     260,   142,   119,   259,   348,   260,    -1,   131,   361,    -1,
     136,   131,   361,    -1,   133,   259,   364,   260,   259,   364,
     260,   259,   364,   260,    -1,   134,   259,   364,   260,   259,
     364,   260,   259,   364,   260,   259,   364,   260,    -1,   334,
      -1,   333,   334,    -1,   169,   259,   348,   260,     6,    -1,
     169,   259,   361,   264,   361,   260,     6,    -1,   170,     6,
      -1,   160,     6,    -1,   160,   348,     6,    -1,   175,     6,
      -1,   175,   177,     6,    -1,   176,     6,    -1,   176,   177,
       6,    -1,   171,   255,   348,   256,     7,   361,   142,   348,
       6,    -1,   142,     4,   257,   348,   258,     6,    -1,   154,
      -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,    -1,
     163,     6,    -1,   145,   163,     6,    -1,   163,   348,     6,
      -1,   145,   163,   348,     6,    -1,   335,   259,   319,   336,
     260,   259,   319,   336,   260,    -1,   116,   255,   368,   256,
      -1,   335,   255,   348,   256,     7,   259,   319,   336,   260,
     259,   319,   336,   260,     6,    -1,    -1,   142,     4,   348,
      -1,    -1,     4,    -1,    -1,     7,   361,    -1,    -1,     7,
     348,    -1,    -1,   153,   361,    -1,   121,   122,   362,     7,
     348,     6,    -1,   137,   104,   362,     7,   348,   339,     6,
      -1,   137,   107,   362,   341,   340,     6,    -1,   137,   109,
     362,   341,     6,    -1,   178,   362,     6,    -1,    99,   313,
     255,   348,   264,   348,   256,     6,    -1,   213,   313,   255,
     348,   256,     6,    -1,   166,   107,   259,   364,   260,     7,
     348,     6,    -1,   168,   107,   259,   364,   260,     7,   348,
       6,    -1,   160,   107,   362,   342,     6,    -1,   160,   109,
     362,     6,    -1,   161,   107,   362,     7,   348,     6,    -1,
     140,   104,   259,   364,   260,     7,   259,   364,   260,   343,
       6,    -1,   140,   107,   259,   364,   260,     7,   259,   364,
     260,   343,     6,    -1,   140,   104,   259,   364,   260,     7,
     259,   364,   260,   147,   259,   358,   264,   358,   264,   348,
     260,     6,    -1,   140,   107,   259,   364,   260,     7,   259,
     364,   260,   147,   259,   358,   264,   358,   264,   348,   260,
       6,    -1,   140,   104,   259,   364,   260,     7,   259,   364,
     260,   148,   358,     6,    -1,   140,   107,   259,   364,   260,
       7,   259,   364,   260,   148,   358,     6,    -1,   140,   107,
     348,   259,   364,   260,     7,   348,   259,   364,   260,     6,
      -1,   313,   259,   364,   260,   192,   313,   259,   348,   260,
       6,    -1,   167,   315,   362,     6,    -1,   128,   316,   362,
       6,    -1,   129,   109,   361,     6,    -1,   144,   104,   361,
       6,    -1,   139,   314,   361,     6,    -1,   164,     6,    -1,
     164,     4,     6,    -1,   164,   101,   259,   364,   260,     6,
      -1,   214,    -1,   215,    -1,   216,    -1,   346,     6,    -1,
     346,   259,   361,   260,     6,    -1,   346,   259,   361,   264,
     361,   260,     6,    -1,   346,   255,   361,   256,   259,   361,
     264,   361,   260,     6,    -1,   349,    -1,   255,   348,   256,
      -1,   244,   348,    -1,   243,   348,    -1,   250,   348,    -1,
     348,   244,   348,    -1,   348,   243,   348,    -1,   348,   245,
     348,    -1,   348,   246,   348,    -1,   348,   248,   348,    -1,
     348,   249,   348,    -1,   348,   247,   348,    -1,   348,   254,
     348,    -1,   348,   237,   348,    -1,   348,   238,   348,    -1,
     348,   242,   348,    -1,   348,   241,   348,    -1,   348,   236,
     348,    -1,   348,   235,   348,    -1,   348,   234,   348,    -1,
     348,   233,   348,    -1,   348,   239,   348,    -1,   348,   240,
     348,    -1,   348,   232,   348,     8,   348,    -1,    16,   289,
     348,   290,    -1,    17,   289,   348,   290,    -1,    18,   289,
     348,   290,    -1,    19,   289,   348,   290,    -1,    20,   289,
     348,   290,    -1,    21,   289,   348,   290,    -1,    22,   289,
     348,   290,    -1,    23,   289,   348,   290,    -1,    24,   289,
     348,   290,    -1,    26,   289,   348,   290,    -1,    27,   289,
     348,   264,   348,   290,    -1,    28,   289,   348,   290,    -1,
      29,   289,   348,   290,    -1,    30,   289,   348,   290,    -1,
      31,   289,   348,   290,    -1,    32,   289,   348,   290,    -1,
      33,   289,   348,   290,    -1,    34,   289,   348,   290,    -1,
      35,   289,   348,   290,    -1,    38,   289,   348,   264,   348,
     290,    -1,    39,   289,   348,   264,   348,   290,    -1,    40,
     289,   348,   264,   348,   290,    -1,    25,   289,   348,   290,
      -1,    37,   289,   348,   264,   348,   290,    -1,    36,   289,
     348,   264,   348,   290,    -1,     3,    -1,    10,    -1,    15,
      -1,    11,    -1,    12,    -1,   221,    -1,   222,    -1,   223,
      -1,    81,    -1,    82,    -1,    83,    -1,    -1,    92,   289,
     348,   350,   300,   290,    -1,   353,    -1,   211,   289,   368,
     290,    -1,   211,   289,   368,   264,   348,   290,    -1,   355,
      -1,   378,   257,   348,   258,    -1,   378,   255,   348,   256,
      -1,   217,   255,   355,   256,    -1,   217,   255,   355,   261,
     291,   256,    -1,   219,   255,   355,   351,   256,    -1,   219,
     255,   355,   261,   291,   351,   256,    -1,   219,   255,   355,
     289,   348,   290,   351,   256,    -1,   219,   255,   355,   261,
     291,   289,   348,   290,   351,   256,    -1,   218,   255,   369,
     256,    -1,   262,   378,   289,   290,    -1,   262,   355,   261,
     291,   289,   290,    -1,    95,   289,   378,   290,    -1,    95,
     289,   290,    -1,   378,   288,    -1,   378,   257,   348,   258,
     288,    -1,   378,   255,   348,   256,   288,    -1,   378,   261,
     291,    -1,   378,     9,   378,   261,   291,    -1,   378,   261,
     291,   255,   348,   256,    -1,   378,     9,   378,   261,   291,
     255,   348,   256,    -1,   378,   261,   291,   257,   348,   258,
      -1,   378,     9,   378,   261,   291,   257,   348,   258,    -1,
     378,   257,   348,   258,   261,   291,    -1,   378,   261,   291,
     288,    -1,   378,   257,   348,   258,   261,   291,   288,    -1,
     207,   255,   368,   264,   348,   256,    -1,    59,   255,   361,
     264,   361,   256,    -1,    60,   289,   368,   264,   368,   290,
      -1,    58,   289,   368,   290,    -1,    61,   289,   368,   264,
     368,   290,    -1,    66,   255,   375,   256,    -1,    -1,   264,
     348,    -1,    -1,   264,   368,    -1,    -1,    93,   355,   357,
     354,   257,   301,   258,    -1,   378,    -1,   378,     9,   378,
      -1,    96,    -1,    96,   348,    -1,    -1,   255,   356,   256,
      -1,   359,    -1,   244,   358,    -1,   243,   358,    -1,   358,
     244,   358,    -1,   358,   243,   358,    -1,   259,   348,   264,
     348,   264,   348,   264,   348,   264,   348,   260,    -1,   259,
     348,   264,   348,   264,   348,   264,   348,   260,    -1,   259,
     348,   264,   348,   264,   348,   260,    -1,   255,   348,   264,
     348,   264,   348,   256,    -1,   361,    -1,   360,   264,   361,
      -1,   348,    -1,   363,    -1,   259,   260,    -1,   259,   364,
     260,    -1,   244,   259,   364,   260,    -1,   348,   245,   259,
     364,   260,    -1,   361,    -1,   259,     8,   260,    -1,     5,
      -1,   244,   363,    -1,   348,   245,   363,    -1,   348,     8,
     348,    -1,   348,     8,   348,     8,   348,    -1,   101,   259,
     348,   260,    -1,   101,   259,     8,   260,    -1,   101,     5,
      -1,   314,   259,     8,   260,    -1,   314,     5,    -1,   138,
     313,   362,    -1,   141,   313,   361,    -1,   313,   192,    67,
     361,    -1,    67,   313,   259,   364,   260,    -1,    76,   314,
     259,   348,   260,    -1,    77,   314,   259,   348,   260,    -1,
     317,    -1,   328,    -1,   337,    -1,   378,   289,   290,    -1,
     378,   261,   291,   289,   290,    -1,   378,     9,   378,   261,
     291,   289,   290,    -1,    41,   257,   378,   258,    -1,    41,
     257,   363,   258,    -1,    41,   255,   363,   256,    -1,    41,
     289,   259,   364,   260,   290,    -1,   378,   289,   259,   364,
     260,   290,    -1,    42,   289,   348,   264,   348,   264,   348,
     290,    -1,    43,   289,   348,   264,   348,   264,   348,   290,
      -1,    44,   289,   368,   290,    -1,    45,   289,   348,   264,
     348,   264,   348,   264,   348,   264,   348,   264,   348,   290,
      -1,   212,   289,   363,   290,    -1,    32,   289,   363,   290,
      -1,   348,    -1,   363,    -1,   364,   264,   348,    -1,   364,
     264,   363,    -1,   259,   348,   264,   348,   264,   348,   264,
     348,   260,    -1,   259,   348,   264,   348,   264,   348,   260,
      -1,   378,    -1,     4,   261,   189,   261,     4,    -1,   259,
     367,   260,    -1,   378,   257,   348,   258,   261,   190,    -1,
     365,    -1,   367,   264,   365,    -1,   369,    -1,   378,    -1,
     378,   257,   348,   258,    -1,   378,   255,   348,   256,    -1,
     378,   261,   291,    -1,   378,     9,   378,   261,   291,    -1,
     378,   261,   291,   255,   348,   256,    -1,   378,     9,   378,
     261,   291,   255,   348,   256,    -1,   378,   257,   348,   258,
     261,     4,    -1,   313,   259,   348,   260,    -1,   138,   313,
     259,   348,   260,    -1,     5,    -1,   226,   257,   378,   258,
      -1,    70,    -1,   224,    -1,    78,    -1,    80,    -1,   209,
     255,   368,   256,    -1,   208,   255,   368,   264,   368,   256,
      -1,   210,   289,   368,   290,    -1,   210,   289,   368,   264,
     368,   290,    -1,   220,   255,   355,   352,   256,    -1,   220,
     255,   355,   261,   291,   352,   256,    -1,    51,   289,   375,
     290,    -1,    52,   255,   368,   256,    -1,    53,   255,   368,
     256,    -1,    54,   255,   368,   264,   368,   264,   368,   256,
      -1,    49,   289,   375,   290,    -1,    63,   289,   368,   290,
      -1,    64,   289,   368,   290,    -1,    65,   289,   368,   290,
      -1,    62,   289,   348,   264,   368,   264,   368,   290,    -1,
      57,   289,   368,   264,   348,   264,   348,   290,    -1,    57,
     289,   368,   264,   348,   290,    -1,    50,   289,   368,   290,
      -1,    50,   289,   368,   264,   364,   290,    -1,    71,   289,
     368,   290,    -1,    72,    -1,    73,    -1,    56,   289,   368,
     290,    -1,    55,   289,   368,   290,    -1,    -1,    97,   289,
     369,   370,   304,   290,    -1,    94,   289,   371,   290,    -1,
     262,   348,    -1,   378,     9,   262,   348,    -1,    49,   289,
     374,   290,    -1,   375,    -1,   374,    -1,   259,   375,   260,
      -1,   368,    -1,   376,    -1,   375,   264,   368,    -1,   375,
     264,   376,    -1,   378,   255,   256,    -1,   378,   261,   291,
     255,   256,    -1,   378,     9,   378,   261,   291,   255,   256,
      -1,     4,   263,   259,   348,   260,    -1,   377,   263,   259,
     348,   260,    -1,   227,   257,   368,   258,   263,   259,   348,
     260,    -1,     4,    -1,   377,    -1,   227,   257,   368,   258,
      -1
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
    1911,  1961,  1979,  2000,  2006,  2012,  2019,  2050,  2065,  2087,
    2110,  2133,  2156,  2180,  2204,  2228,  2254,  2271,  2287,  2305,
    2323,  2335,  2349,  2348,  2378,  2380,  2382,  2384,  2386,  2394,
    2396,  2398,  2400,  2408,  2410,  2412,  2420,  2422,  2424,  2426,
    2436,  2452,  2468,  2484,  2500,  2516,  2533,  2570,  2591,  2612,
    2638,  2639,  2644,  2647,  2651,  2668,  2688,  2708,  2727,  2754,
    2773,  2794,  2809,  2825,  2843,  2894,  2915,  2937,  2960,  3065,
    3081,  3116,  3138,  3160,  3172,  3178,  3193,  3224,  3236,  3245,
    3252,  3264,  3284,  3288,  3293,  3297,  3302,  3309,  3316,  3323,
    3335,  3408,  3426,  3451,  3466,  3499,  3511,  3543,  3547,  3552,
    3559,  3564,  3574,  3579,  3585,  3593,  3601,  3605,  3609,  3613,
    3617,  3621,  3633,  3642,  3706,  3722,  3739,  3756,  3778,  3800,
    3835,  3843,  3851,  3857,  3864,  3871,  3891,  3917,  3929,  3940,
    3958,  3976,  3995,  3994,  4019,  4018,  4045,  4044,  4069,  4068,
    4091,  4107,  4124,  4141,  4164,  4192,  4195,  4201,  4213,  4233,
    4237,  4241,  4245,  4249,  4253,  4257,  4261,  4270,  4283,  4284,
    4285,  4286,  4287,  4291,  4292,  4293,  4294,  4295,  4298,  4322,
    4341,  4364,  4367,  4383,  4386,  4403,  4406,  4412,  4415,  4422,
    4425,  4432,  4454,  4495,  4539,  4578,  4603,  4616,  4627,  4644,
    4661,  4691,  4717,  4743,  4775,  4802,  4828,  4854,  4880,  4906,
    4928,  4939,  4987,  5041,  5056,  5068,  5079,  5086,  5101,  5115,
    5116,  5117,  5121,  5127,  5139,  5157,  5185,  5186,  5187,  5188,
    5189,  5190,  5191,  5192,  5193,  5200,  5201,  5202,  5203,  5204,
    5205,  5206,  5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,
    5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,  5223,  5224,
    5225,  5226,  5227,  5228,  5229,  5230,  5231,  5232,  5233,  5234,
    5235,  5236,  5237,  5238,  5239,  5248,  5249,  5250,  5251,  5252,
    5253,  5254,  5255,  5256,  5257,  5258,  5263,  5262,  5270,  5274,
    5279,  5284,  5288,  5293,  5298,  5302,  5306,  5310,  5314,  5318,
    5322,  5328,  5343,  5347,  5353,  5358,  5377,  5397,  5418,  5422,
    5426,  5430,  5434,  5438,  5442,  5447,  5457,  5467,  5472,  5483,
    5492,  5497,  5502,  5530,  5531,  5537,  5538,  5544,  5543,  5566,
    5568,  5573,  5575,  5581,  5582,  5587,  5591,  5595,  5599,  5603,
    5610,  5614,  5618,  5622,  5629,  5634,  5641,  5646,  5650,  5655,
    5659,  5667,  5678,  5682,  5686,  5700,  5708,  5716,  5723,  5733,
    5756,  5761,  5767,  5772,  5778,  5789,  5795,  5809,  5815,  5827,
    5841,  5851,  5861,  5871,  5883,  5887,  5892,  5904,  5908,  5912,
    5916,  5934,  5942,  5950,  5979,  5989,  6005,  6016,  6021,  6025,
    6029,  6041,  6045,  6057,  6074,  6084,  6088,  6103,  6108,  6115,
    6119,  6124,  6138,  6152,  6156,  6160,  6164,  6168,  6176,  6182,
    6191,  6195,  6199,  6207,  6213,  6219,  6223,  6230,  6238,  6245,
    6254,  6258,  6262,  6277,  6291,  6305,  6317,  6333,  6342,  6351,
    6361,  6372,  6380,  6388,  6392,  6411,  6418,  6424,  6430,  6437,
    6445,  6444,  6454,  6478,  6480,  6486,  6491,  6493,  6498,  6503,
    6508,  6510,  6514,  6526,  6540,  6544,  6551,  6559,  6567,  6578,
    6580,  6583
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
     311,   311,   312,   311,   313,   313,   313,   313,   313,   314,
     314,   314,   314,   315,   315,   315,   316,   316,   316,   316,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   318,   319,   319,   319,   319,   319,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   321,   321,   321,   321,   321,   321,   321,   321,   322,
     322,   323,   324,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   326,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   328,
     328,   328,   329,   328,   330,   328,   331,   328,   332,   328,
     328,   328,   328,   328,   328,   333,   333,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   335,   335,
     335,   335,   335,   336,   336,   336,   336,   336,   337,   337,
     338,   339,   339,   340,   340,   341,   341,   342,   342,   343,
     343,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   345,   345,   345,   346,
     346,   346,   347,   347,   347,   347,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   350,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   351,   351,   352,   352,   354,   353,   355,
     355,   356,   356,   357,   357,   358,   358,   358,   358,   358,
     359,   359,   359,   359,   360,   360,   361,   361,   361,   361,
     361,   361,   362,   362,   362,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   364,   364,   364,
     364,   365,   365,   365,   365,   366,   366,   367,   367,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     370,   369,   369,   371,   371,   372,   373,   373,   374,   375,
     375,   375,   375,   376,   376,   376,   377,   377,   377,   378,
     378,   378
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
       8,     9,     8,     3,     4,    10,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     9,     7,     7,     8,
       8,    12,     0,     9,     1,     1,     1,     1,     4,     1,
       1,     1,     4,     1,     1,     4,     1,     1,     1,     4,
       5,    11,     5,     9,     9,     7,     4,     9,    10,     9,
       1,     1,     0,     2,     6,     7,     7,     6,     7,     8,
      10,    14,    16,    12,    14,    14,    14,    14,     8,     8,
       6,     4,     5,     5,     6,     6,     3,     4,     3,     5,
       6,     5,     4,     3,     4,     3,     4,     5,     4,     5,
       3,     5,     7,     7,     3,     7,     3,     2,     2,     2,
       2,     2,    15,     2,     2,     2,     9,    11,     2,     2,
       2,     2,     2,    16,    11,     6,     8,     8,    10,     1,
       2,     2,     1,     3,     3,     4,     4,     1,     1,     5,
      11,    13,     0,     7,     0,    13,     0,    15,     0,     6,
       9,     2,     3,    10,    13,     1,     2,     5,     7,     2,
       2,     3,     2,     3,     2,     3,     9,     6,     1,     1,
       1,     1,     1,     0,     2,     3,     3,     4,     9,     4,
      14,     0,     3,     0,     1,     0,     2,     0,     2,     0,
       2,     6,     7,     6,     5,     3,     8,     6,     8,     8,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,     4,     4,     4,     4,     4,     2,     3,     6,     1,
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
       0,     0,     0,     2,     3,     1,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,   205,     0,     0,   206,     0,   207,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   338,   339,   340,   341,   342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     299,     0,     0,   307,   308,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,   389,   390,   391,     0,     0,
       5,     6,     7,     8,    10,     0,    11,    24,    12,    13,
      14,    15,    23,    22,    21,    16,     0,    17,    18,    19,
      20,     0,    25,     0,   630,     0,   232,     0,     0,     0,
       0,     0,     0,   281,     0,   283,   284,   279,   280,     0,
     285,   288,     0,   289,   290,   119,   129,   629,   503,   499,
      73,    74,     0,   204,   205,   206,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,   292,     0,   216,   217,   218,     0,     0,     0,
       0,   445,   446,   448,   449,   447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   453,   454,   455,     0,     0,   204,
     209,   210,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   450,   451,   452,     0,     0,     0,
       0,     0,     0,     0,     0,   540,   541,     0,   542,   516,
     396,   458,   461,   321,   517,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,   209,   210,     0,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   629,     0,     0,   232,
       0,     0,   386,     0,     0,     0,   213,   214,     0,     0,
       0,     0,     0,     0,   524,     0,     0,   522,     0,     0,
       0,     0,     0,     0,   629,     0,     0,   563,     0,     0,
       0,     0,   277,   278,     0,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   582,
       0,   606,   607,   584,   585,     0,     0,     0,     0,     0,
       0,   583,     0,     0,     0,     0,   300,   301,     0,   232,
       0,   232,     0,     0,     0,     0,   499,     0,     0,     0,
     232,   392,     0,     0,    84,     0,    66,     0,     0,    70,
      69,    68,    67,    72,    71,    73,    74,     0,     0,     0,
       0,     0,     0,     0,   569,   499,     0,   231,     0,   230,
       0,   183,     0,     0,   569,   570,     0,     0,     0,   619,
       0,   620,   570,     0,   117,   117,     0,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   557,   558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   399,     0,   398,   525,
     400,     0,   518,     0,     0,   499,     0,   533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,   475,     0,     0,     0,     0,     0,     0,
       0,   322,     0,   355,   355,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,   232,   232,
       0,   507,   506,     0,     0,     0,     0,   232,   232,     0,
       0,     0,     0,   318,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,   232,   258,     0,     0,   256,   387,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,   276,     0,     0,     0,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   304,   303,     0,   263,
       0,     0,   265,     0,     0,     0,     0,   398,     0,   232,
       0,     0,     0,     0,     0,     0,     0,   343,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    88,    75,    76,     0,     0,
       0,   274,    40,   270,     0,     0,     0,     0,     0,   226,
       0,     0,     0,     0,     0,   233,     0,     0,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,     0,     0,
       0,   501,     0,     0,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,   382,   383,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     456,   474,     0,     0,     0,     0,   534,   535,     0,     0,
       0,     0,     0,   493,     0,   397,   519,     0,     0,     0,
       0,   527,     0,   416,   415,   414,   413,   409,   410,   417,
     418,   412,   411,   402,   401,     0,   403,   526,   404,   407,
     405,   406,   408,   500,     0,     0,   478,     0,   543,     0,
       0,     0,     0,     0,     0,     0,     0,   353,     0,     0,
       0,     0,     0,     0,   385,     0,     0,     0,     0,   384,
       0,   232,     0,     0,     0,     0,     0,   509,   508,     0,
       0,     0,     0,     0,     0,     0,   312,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     371,     0,     0,     0,   257,     0,     0,     0,   251,     0,
       0,     0,     0,   381,     0,     0,     0,     0,   397,   523,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
     306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
       0,     0,     0,   495,     0,     0,   262,   266,   264,   268,
       0,     0,   403,     0,   500,   478,   631,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,   397,
       0,     0,     0,    66,     0,     0,    87,     0,    66,    67,
       0,     0,     0,   500,     0,     0,   478,     0,     0,     0,
     202,     0,     0,     0,   626,    28,    26,    27,     0,     0,
       0,     0,     0,   573,    30,     0,    29,     0,     0,   271,
     621,   622,     0,   623,   573,     0,    82,   120,    83,   130,
     502,   504,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   559,   560,   219,
       9,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     442,   429,     0,   431,   432,   433,   434,   435,   556,   436,
     437,   438,     0,     0,     0,     0,     0,   548,   547,   546,
       0,     0,     0,   553,     0,   490,     0,     0,     0,   492,
       0,     0,     0,   134,   473,   530,   529,   212,     0,     0,
     459,   555,   464,     0,   470,     0,     0,     0,     0,   520,
       0,     0,   471,   536,   532,     0,     0,     0,     0,   463,
     462,    73,    74,   485,     0,     0,     0,     0,     0,     0,
       0,   397,   351,   356,   354,     0,   364,     0,   156,   157,
       0,   212,     0,   397,     0,     0,     0,     0,   252,     0,
     267,   269,     0,     0,     0,   220,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   325,     0,
     309,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,     0,   358,   370,     0,     0,     0,     0,   253,
       0,     0,     0,     0,   215,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,     0,     0,     0,     0,
     596,     0,   603,   592,   593,   594,     0,   609,   608,     0,
       0,   597,   598,   599,   605,   613,   612,     0,   147,     0,
     586,     0,   588,     0,     0,     0,   581,     0,     0,   261,
       0,     0,     0,     0,     0,     0,     0,   344,     0,     0,
       0,   393,     0,   627,     0,   109,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,   578,    51,     0,     0,     0,    64,     0,
      41,    42,    43,    44,    45,    46,     0,   463,   462,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   572,   571,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,   137,   138,     0,     0,
       0,     0,   163,   163,     0,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   537,   538,   539,     0,     0,
       0,     0,     0,   493,   494,     0,   466,     0,     0,   528,
     419,   521,   479,   477,     0,   476,     0,     0,   544,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,   260,
       0,     0,     0,     0,     0,     0,     0,   330,     0,     0,
     329,     0,   332,     0,   334,     0,   319,   326,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   372,     0,     0,   255,   254,   388,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,   564,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   590,     0,   367,   479,     0,
       0,   232,   345,     0,   346,   232,     0,     0,   579,     0,
      94,     0,     0,     0,     0,    92,     0,   567,     0,   107,
       0,    99,   101,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    36,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   574,
       0,     0,    34,    33,     0,   574,   624,     0,     0,   121,
     126,     0,     0,     0,   140,   145,   146,   141,   142,   498,
       0,    85,     0,    86,   167,     0,     0,     0,     0,   168,
     186,   187,   165,     0,     0,     0,   169,   197,   188,   192,
     193,   189,   190,   191,   177,     0,     0,   430,   444,   443,
     439,   440,   441,   549,     0,     0,     0,   488,   489,   491,
     135,   457,   487,   460,   465,     0,     0,   493,   198,   472,
      73,    74,     0,   484,   480,   482,   550,   194,     0,     0,
       0,   159,     0,     0,   362,     0,   158,     0,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   232,   232,
       0,     0,   331,   516,     0,     0,   333,   335,     0,     0,
     313,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   195,     0,     0,     0,     0,     0,     0,     0,
     174,   175,     0,     0,     0,     0,   110,   114,     0,   604,
       0,     0,   602,     0,   614,     0,     0,   148,   149,   611,
     587,   589,     0,     0,     0,     0,     0,     0,   343,   347,
     343,     0,   394,    93,     0,     0,    66,     0,     0,    91,
       0,   565,     0,     0,     0,     0,     0,     0,   617,   616,
       0,     0,     0,     0,     0,   514,     0,     0,    77,   272,
     480,   273,     0,     0,     0,     0,     0,   237,   234,     0,
       0,   577,   575,     0,     0,     0,     0,   122,   127,     0,
       0,     0,   557,   558,   139,   366,   164,   172,   173,   178,
       0,     0,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,   467,     0,     0,     0,   545,   486,     0,     0,
     179,     0,   199,   352,     0,     0,     0,     0,   200,     0,
       0,     0,     0,     0,     0,   513,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   249,   248,     0,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
       0,   368,   369,    39,   182,     0,   562,     0,     0,   297,
     296,     0,     0,     0,     0,     0,     0,   151,   152,   155,
     154,   153,     0,   591,     0,   628,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   568,     0,     0,     0,
      96,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      49,     0,   238,   235,   236,    35,     0,     0,   625,   286,
       0,   134,   147,     0,     0,   144,     0,     0,     0,   166,
     196,     0,     0,     0,     0,     0,   551,   552,     0,   493,
     468,   481,   483,     0,     0,   181,   203,     0,     0,     0,
     359,   359,     0,   115,   116,   232,     0,   223,   224,   320,
       0,   327,     0,     0,   232,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,   227,     0,     0,     0,     0,
     111,   112,   595,   601,   600,   150,     0,     0,     0,   348,
       0,     0,   108,   100,   102,     0,    90,   618,    97,    98,
      52,     0,     0,     0,     0,   515,     0,     0,   481,   576,
       0,     0,     0,     0,   124,   615,     0,   131,     0,     0,
       0,     0,   185,     0,     0,     0,   323,     0,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     511,     0,   337,     0,     0,   314,     0,   240,     0,     0,
       0,     0,     0,     0,   228,     0,   561,   298,     0,     0,
     380,   232,   395,     0,   566,     0,    48,     0,     0,     0,
      65,    50,     0,   287,   123,   128,   134,     0,     0,   161,
     162,   160,     0,     0,   469,     0,     0,     0,     0,   360,
     373,     0,     0,   374,     0,   221,     0,   328,     0,   310,
       0,   232,     0,     0,     0,     0,     0,     0,   176,   113,
     294,   343,   106,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,   201,     0,   377,     0,   378,   379,
     510,     0,     0,   316,   243,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,    62,     0,     0,   125,     0,
       0,   324,     0,     0,   336,   315,   311,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   244,   245,   246,   247,     0,
     241,   350,    53,     0,    60,     0,   282,     0,   554,     0,
       0,   317,     0,     0,    54,     0,     0,   293,     0,     0,
     242,     0,     0,     0,     0,     0,     0,    57,    55,     0,
      58,     0,   375,   376,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   120,  1088,   121,   122,  1072,  1933,  1939,
    1370,  1587,  2095,  2223,  1371,  2196,  2239,  1372,  2225,  1373,
    1374,  1591,   448,   603,   604,  1157,  1683,   123,   798,   474,
    1951,  2106,  1952,   475,  1821,  1449,  1405,  1406,  1407,  1550,
    1757,  1758,  1227,  1645,  1636,  1831,   775,   615,   283,   284,
     359,   208,   285,   458,   459,   127,   128,   129,   130,   131,
     132,   133,   134,   286,  1261,  2130,  2187,   964,  1257,  1258,
     287,  1051,   288,   138,  1477,  1225,   937,   979,  2064,   139,
     140,   141,   142,   289,   290,  1183,  1198,  1325,   291,   803,
     292,   802,   477,   632,   327,  1794,   367,   368,   294,   573,
     376,  1354,  1578,   469,   464,  1318,  1027,  1626,  1787,  1788,
    1012,   471,   144,   426
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1934
static const yytype_int16 yypact[] =
{
   13175,    23,    56, 13379, -1934, -1934,   115,    27,   -35,  -158,
    -151,  -126,    25,   158,   168,   178,   193,   -53,   211,   237,
     -26,   270,   280,    78,   105,    39,  -104,   491,  -104,   117,
     138,   146,    42,   177,   188,    57,   250,   296,   325,   338,
     344,   355,   411,   433,   452,   461,     5,   147,   316,   560,
     695,   483,   500,   623,   496,  6753,   524,   555,   566,   753,
     -62,   359,   491,   477,     7,   648,   791,   -93,   677,    -2,
      -2,   754,   293,   350,   759, -1934, -1934, -1934, -1934, -1934,
     653,   407,   813,   823,    29,    44,   833,   844,   238,   883,
    1008,  1015,  1016,  5741,  1017,   -86,   768,   769,     9,    64,
   -1934,   770,   771, -1934, -1934,  1021,  1022,   772, -1934,  3604,
     775, 13624,    15,    18,   491, -1934, -1934, -1934, 11899,   774,
   -1934, -1934, -1934, -1934, -1934,   773, -1934, -1934, -1934, -1934,
   -1934, -1934, -1934, -1934, -1934, -1934,   189, -1934, -1934, -1934,
   -1934,    52, -1934,  1027,   776,  4910,   429,   778,  1028, 11899,
   13562, 13562, 13562, -1934, 11899, -1934, -1934, -1934, -1934, 13562,
   -1934, -1934, 11899, -1934, -1934, -1934, -1934,   777,   780,  1029,
   -1934, -1934, 13660, -1934, -1934, -1934, -1934,   786,    39, 11899,
   11899, 11899,   787, 11899, 11899, 11899,   788, 11899, 11899, 11899,
   11899, 11899, 11899, 11899, 13562, 11899, 11899, 11899, 11899,  5741,
     789, -1934, -1934,  9526, -1934, -1934, -1934,   790,  5741,  7006,
   13562, -1934, -1934, -1934, -1934, -1934,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -104,   163,  -104,  -104,  -104,  -104,  -104,   792,  -104,  -104,
     793,   491,   463,   463, -1934, -1934, -1934,  -104,  -104,    33,
     853,   854,   858,   794,  7006,   921,   491,   491,   800,  -104,
    -104,   802,   803,   805, -1934, -1934, -1934, 11899,  7259, 11899,
   11899,  7512,    39,   869,    37, -1934, -1934,   804, -1934,  5675,
   -1934, -1934, -1934, -1934, -1934,    91, 11899,  9526,  9526,   807,
     809,  7765,  5741,  5741,  5741, -1934, -1934, -1934,   810, -1934,
     811,   814,  8018,   812, 10465,  1062,  7006,   815,     9,   818,
     819,    -2,    -2,    -2, 11899, 11899,   -40, -1934,   330,    -2,
   10551,   365,   370,   817,   824,   826,   827,   828,   829,   831,
    9526, 11899,  5741,  5741,  5741,   458,     8,  1067,   832, -1934,
    1082,  1084, -1934,   836,   837,   838, -1934, -1934,   839,  5741,
     840,   834,   843,   846, -1934, 11899,  5994, -1934,  1096,  1100,
     852, 11899, 11899, 11899,   258, 11899,   849, -1934,   876, 11899,
   11899, 11899, -1934, -1934, 11899, -1934,  -104,  -104,  -104,   855,
     861,   865,  -104,  -104,  -104,  -104,  -104,  -104,  -104, -1934,
    -104, -1934, -1934, -1934, -1934,  -104,  -104,   877,   879,  -104,
     880, -1934,   874,  1103,  1131,   881, -1934, -1934,  1132,  1133,
    1136,  1135,   884,  -104, 11899, 15275,   118, 13562,  9526, 11899,
   -1934, -1934,  7006,  7006, -1934,   885, 13660,   491,  1138, -1934,
   -1934, -1934, -1934, -1934, -1934, 11899, 11899,   328,  7006,  1140,
     431,   888,  1615,   889,  1143,    28,   891, -1934,   893, 13887,
   11899, -1934,  1677,  -139, -1934,    53,   -48,    74,  8458, -1934,
     226, -1934,    92,  8706,  -191,   -70,  1055, -1934,    39,   912,
   11899,   914, 15791, 15816, 15841, 11899, 15866, 15891, 15916, 11899,
   15941, 15966, 15991, 16016, 16041, 16066, 16091,   924, 16116, 16141,
   16166, 14376,  1172, 11899,  9526,  5928, -1934,   475, 11899,  1175,
    1176,   928, 11899, 11899, 11899, 11899, 11899, 11899, 11899, 11899,
   11899, 11899, 11899, 11899, 11899, 11899, 11899, 11899,  9526, 11899,
   11899, 11899, 11899, 11899, 11899, 11899, 11899,  9526,  9526,   926,
   11899, 11899, 13562, 11899, 13562,  7006, 13562, 13562, 13562,   927,
     929,   930, 11899,    35, -1934, 10804, 11899,  7006,  5741,  7006,
   13562, 13562,  9526,    39, 13660,    39,   933,  9526,   933, -1934,
     933, 16191, -1934,   481,   931,   100,  1123, -1934,  1183, 11899,
   11899, 11899, 11899, 11899, 11899, 11899, 11899, 11899, 11899, 11899,
   11899, 11899, 11899,  8271, 11899, 11899, 11899, 11899, 11899,    39,
   11899, 11899,    55, -1934,   758, 16216,   493,   552, 11899, 11899,
   11899, -1934,  1187,  1188,  1188,   941, 11899, 11899, 11899, 11899,
    1192,  9526,  9526, 15303,   943,  1194, -1934,   944, -1934, -1934,
    -141, -1934, -1934,  8954,  9207,    -2,    -2,   429,   429,  -124,
   10551, 10551, 11899, 12164,  -110, -1934, 11899, 11899, 11899, 11899,
   11899, 11899, 11899, 11899, 11899,   559, 16241,  1195,  1198,  1199,
   11899, 11899,  1201, 11899, -1934, -1934, 11899, 12250, -1934, -1934,
    9526,  9526,  9526, 11899,  1205,  9526, 11899, 11899, 11899, 16266,
     945, -1934, -1934, 11899, 16291, 16316, 16341,  1012,  9460, -1934,
     953,  6181, 16366, 16391, 15386, 13562, 13562, 13562, 13562, 13562,
   13562, 13562, 13562, 13562, 11899, 13562, 13562, 13562, 13562,    10,
   13660, 13562, 13562, 13562,    39,    39, -1934, -1934,  9526, -1934,
     956, 12352, -1934,   975, 12412, 11899, 11899,   933, 11899, -1934,
      39, 11899, 11899,    55,   978,   564, 16416, 13786,   981,   573,
   11899,  1232,   983,  7006, 16441, 15413, -1934, -1934, -1934, -1934,
   -1934,   984,  1239,   161,  1242, -1934, -1934, -1934,  9526,    17,
   11899, -1934, -1934, -1934,    39, 11899, 11899,    55,   992, -1934,
     995,   -56,   491,   477,   491, -1934,   993, 14405, -1934,    20,
    9526,    39, 11899, 11899,    55,  1245,  9526,  1248,  9526, 11899,
    1250, 13562,    39, 10890,    55, 11899,  1251, -1934,    39,  1254,
   13562, 11899,  1005,  1006, -1934, 11899,  9805, 13660,  1255,  1257,
    1258, 16466,  1260,  1261,  1264, 16491,  1267,  1268,  1269,  1270,
    1271,  1272,  1273, -1934,  1274,  1275,  1276, -1934, 11899, 16516,
    9526,  1025,  9526, 14434, -1934, -1934,  1280, 15359, 15359, 15359,
   15359, 15359, 15359, 15359, 15359, 15359, 15359, 15359, 10153, 15359,
   15359, 15359, 15359,   985,   313, 15359, 15359, 15359, 10415, 10496,
   10754, 10835, 11169,  5928,  1034,  1033,    68,  9526, 11429, 11510,
     313, 11763,   313,  1030,  1031,  1032,   274,  9526, 11899, 11899,
   17441, -1934,   313,  1037, 14463, 14492, -1934, -1934,  1035,  -106,
     313,  -185,  1036,   469,   575,  1286, -1934,    55,   313,  7006,
    1040,  6434,  6687,  2671,   527,   561,   561,   437,   437,   437,
     437,   437,   437,   474,   474,  9526,   422, -1934,   422,   422,
     933,   933,   933,  1041, 16541, 15440,   565,  9526, -1934,  1294,
    1045,  1046, 16566, 16591, 16616, 11899,  7006,  1302,  1303, 10217,
   16641, 14521, 16666, 16691, -1934,   578,   581,  9526,  1047, -1934,
   12472, -1934, 12532, 12592,    -2, 11899, 11899, -1934, -1934,  1050,
    1051, 10551,  7193,  1171,   446,    -2, 12652, 16716, 14550, 16741,
   16766, 16791, 16816, 16841, 16866, 16891,  1056,  1307, 11899,  1311,
   -1934, 11899, 16916, 14579, -1934, 15467, 12712, 15494, -1934,   583,
     584,   586, 14608, -1934,   589, 15521, 15548, 11844, -1934, -1934,
   16941,  1312,  1313,  1317,  1061, 11899, 12772, 11899, 11899, -1934,
   -1934,    12,   -79,   151,   -79,  1069,  1070,  1063,   313,   313,
    1064, 12992,   313,   313,   313,   313, 11899,   313,  1320, -1934,
    1066,  1075,   399,  -123,  1074,   594, -1934, -1934, -1934, -1934,
   16966, 15359,   422, 12832,  1072,   579,  1071,  1144,  1328,  1177,
   11138,  1078,  1080,  1335,  7006, 14637, -1934, 11899,  1336,   169,
      75,    55,    11, 13660, 11899,  1337, -1934,   599,  1295,  1296,
    7006, 14666,    30,  1085, 16991, 15575,   495, 11899, 11899,  1092,
    1089,  1094,  1095,  8524, -1934, -1934, -1934, -1934, 13562,   297,
    1090, 17016, 15602,  1098, -1934,   349, -1934,   398, 13174, -1934,
   -1934, -1934,  1097, -1934,  1101, 13571, -1934,    67, -1934, -1934,
   17441, -1934,    62, 15359, 11899,   313,    -2,  7006,  7006,  1348,
    7006,  7006,  7006,  1350,  7006,  7006,  7006,  7006,  7006,  7006,
    7006,  7006,  7006,  7006,  1829,  1352,  9526,  5928, -1934, -1934,
   -1934, -1934, -1934, -1934, -1934, -1934, -1934, -1934, -1934, -1934,
   -1934, -1934, 11899, -1934, -1934, -1934, -1934, -1934, -1934, -1934,
   -1934, -1934, 11899, 11899, 11899, 11899, 11899, -1934, -1934, -1934,
     601, 11899, 11899, -1934, 11899, -1934,  7006, 13562, 13562, -1934,
     602, 14695, 14724,  1099, -1934, -1934, -1934,  1168, 11899, 11899,
   -1934, -1934, -1934,    55, -1934,    55, 11899, 11899,  1105, -1934,
    7006,  -104, -1934, -1934, -1934, 11899, 11899,   607,    55,   541,
     247, 11899, 11899, -1934,   313,   609,  7006,  9526,  9526,  1355,
    1357,  1359,  2792, -1934, -1934,  1361, -1934,  1112, 17441,  1106,
    1364, -1934,  1365,  1366,  1367,  1369,   637,    79, -1934, 12892,
   -1934, -1934,  -107, 13719, 13815, -1934, -1934, 14753,  -180,  1259,
    1373, 11231,  1124,  1378,  1130,    41,    51,   -82, -1934,   -81,
   -1934,   446,  1379,  1381,  1382,  1383,  1384,  1386,  1387,  1388,
    1389,   429,  7006, 17441, -1934,  1959,  1129,  1297,  1391, -1934,
    1394,  1396,  1298,  1397, -1934,  1399,  1401,  1402, 11899,  1403,
    7006,  7006,  7006,  1405, 13848, -1934,  6940,  1315,    55,    55,
   -1934,  9526, -1934, -1934, -1934, -1934, 13562, -1934, -1934, 11899,
   13562, -1934, -1934, -1934, -1934, 17441, -1934,  1141,  1148, 13562,
   -1934, 13562, -1934,    55, 13562,  1157, -1934,  1150,  1410, -1934,
      55, 11899, 11899,  1158,   491,  1159, 11479, -1934,  2327,  1160,
    7006, -1934,  1161, -1934, 14782, -1934, -1934, 11899,  1414,   413,
   11899,  1416,  1417,     9,  1419,  1166,  1420,  2818, -1934,   313,
    -104,  -104,  1421, -1934, -1934,  1179,  1190,  1189, -1934,  1424,
   -1934, -1934, -1934, -1934, -1934, -1934,    55,   391,  4485, 11899,
   15629, 17041, 11899,  8772, 11899,  9526,  1186,   638,  1441,   149,
      55, -1934,  1193, 11899,  1443,  1445, 11899,    55, 11565, 11899,
    9774,   313,  5222, 11899, 11899,  1200,  1196, -1934,  1447, 17066,
    1451,   133,  1324,  1324,  7006,  1455,  1456,  1457,  7006,   -87,
    1458,  1460,  1461,  1463,  1467,  1468,  1469,  1470,  1471, -1934,
    1476,   640, 15359, 15359, 15359, 15359, 15359, 15359,   313, 13881,
   13914, 13947,  1226,   313,   313, -1934, -1934, -1934,    62,   313,
   17091, 15359,  1227,   276, 17441, 15359, -1934,  1479,   313, 17441,
   17441, -1934,   371, -1934,    55, -1934, 17116, 15656, -1934,   313,
    1485,   646,   649,  7006,  7006,  7006,  1488,  1487, -1934,    21,
   11899,  7006,  7006,  7006,  1235,  1236,  1490,  1492,  1493, -1934,
   11899, 11899, 11899,  1240,  1246,  1247,  1244, -1934,  3015,  7006,
   -1934, 11899, -1934,  1498, -1934,  1502, -1934, -1934, 10551,   266,
    6247, -1934,  1253,  1262,  1263,  1265,  1266,  1277,  9020,  1249,
    1504, -1934,  9526,  1278, -1934, -1934, -1934,  1279, 11899, 11899,
   -1934, -1934, 15683,  7006,  1507,  1508,  1329, -1934, 11899, 11899,
   11899, -1934,  1510,   845,   473,  1256,  3298,  1281, 11899,    40,
     313,  1283,   313,  1301, -1934, -1934, 13660, -1934,   420, 11899,
    1282, -1934, -1934,  3069, -1934, -1934,  1304,  1512, -1934,  3210,
   -1934,  1305,  1516,   175,  3394, -1934,     9, -1934,   651, -1934,
   11899, -1934, -1934,    21, 12119,  4786, -1934,  1285, 11899, 11899,
    7006,  1284, -1934,   525,   436,  1520, 17141,  1522,  1286, 17166,
    1310,   654, 17191,   659,  1523,  1525, -1934, -1934, 13562,  1289,
    1528, 17216, -1934, -1934, 13980,  1319, -1934,  7446,  5488, 17441,
   -1934,  1526,  -104,  7512, -1934, -1934, -1934, 17441, 17441, -1934,
      62, -1934,  1529, -1934, -1934,    -2,  1561,  1566,  1569, -1934,
   -1934, -1934,  1392,    66,  1472,  1570, -1934, -1934, -1934, -1934,
   -1934, -1934, -1934, -1934, -1934,  1574,  1321, -1934, -1934, -1934,
   -1934, -1934, -1934, -1934, 11899, 11899, 11899, -1934, -1934, -1934,
    1196, -1934, -1934, -1934, -1934, 11899,  1330,  1325, -1934, -1934,
   11899, 11899,   313,   541, -1934, -1934, -1934, -1934,  1331,  1332,
    1578,   -87,  1582, 11899, -1934,  7006, 17441,  1450,  1452,   752,
    9526,  9526, 11899, -1934, 10217, 14811, 17241,  7699,   429,   429,
   11899, 11899, -1934,   645,  1333, 17266, -1934, -1934, 14840,   -63,
   -1934,  1587,  1589,  7006,    -2,    -2,    -2,    -2,    -2,  6500,
    1590, -1934, -1934,   661,  9526, 11899,  3813,  3893,  1592,  1593,
   -1934, -1934,  7006,  7952,   923, 17291, -1934, -1934,  9869, -1934,
   13562, 11899, -1934, 13562, 17441, 10122, 13660,  1340, -1934, -1934,
   -1934, -1934,  1344,  1343, 11899, 11899, 14869, 11899, 13786, -1934,
   13786,  7006, -1934, -1934,    55,    11, 13660, 11899,  1602, -1934,
    1604, -1934,     9, 15710,  7006, 13562,  1605,   313, -1934,  1349,
     313, 11899, 14013, 14046,   662, -1934, 11899, 11899,  1353, -1934,
    1358, -1934,  1359,  1608,  1610,  1366,  1612, -1934, -1934,  1613,
   11899, -1934, -1934, 11899, 11813,  1616, 11899, -1934, -1934,  1368,
    4786,   668,  5161,  1617, -1934, -1934,   632, -1934, -1934, -1934,
    1477,  1619,  1370,  1371,  1372, -1934,  1621,  7006, 15359, 15359,
   14079, 15359, -1934,  1376, 17316, 15737, -1934, -1934,  9526,  9526,
   -1934,  1622, -1934, 17441,  1627, 11899, 11899,  1375, -1934,   670,
     675, 15331,  3923,  1629,  1377, -1934, -1934, 11899,  1398,  1400,
   14898, 15764,  1640,  7006,  1645,  1406, 11899, -1934, -1934,   678,
     -51,   -29,    -4,   152,   167,  9273,   203, -1934,  1651,   683,
   14927, -1934, -1934, -1934, -1934,  1474, -1934, 11899, 11899, -1934,
   -1934,  9526,  4038,  1653,  1408, 15359,   313, 17441, -1934, -1934,
   -1934, -1934,    40, -1934, 13660, -1934, 14956,  1407,  1409,  1411,
    1655,  1664,  1666,  4138, -1934, -1934, -1934,  1413,  1669,   686,
   -1934,  1670,  1671,   482, 17441, 11899, 11899,  1422,  7006,   692,
   17441, 17341, -1934, -1934, -1934, -1934, 17366, 14112, -1934, -1934,
   14985,  1099,  1148,  7006,   313, -1934, 11899, 13660,    39, -1934,
   -1934,  9526,  9526, 11899,  1672,   693, -1934, -1934, 11899,  1325,
   -1934, -1934, -1934,   698,   699, -1934, -1934,  4482,  4525,  7006,
     639,   643,  9526, -1934, -1934,   429,  8205, -1934, -1934, -1934,
    1674, -1934,  1425,  7006, -1934, 15014,  1676,  9526,    -2,    -2,
      -2,    -2,    -2, -1934,  1680, -1934, 11899, 15043, 15072,   700,
   -1934, -1934, -1934, -1934, -1934, -1934,  1432,  1683,  1431, -1934,
    1685,     9, -1934, -1934, -1934,  1503, -1934, -1934, -1934, -1934,
   -1934, 11899, 14145, 14178,  7006, -1934,  1688, 11899,  1436, -1934,
   11899,  1690,  1440,  1442, -1934, -1934,  5428, -1934,  1446,   701,
     706, 15101, -1934,  1444, 14211,  1449, -1934,  1448, -1934, -1934,
     708,  1453,    -2,  7006,  1700,  1459,    -2,  1702,   713,  1464,
   -1934, 11899, -1934,  1703,  1568, 12952,  1462, -1934,   714,   210,
     213,   215,   227,   240, -1934,  4577, -1934, -1934,  1705,  1709,
   -1934, -1934, -1934,  1711, -1934,  1473, 17441, 11899, 11899,   715,
   -1934, 17441, 14244, -1934, -1934, -1934,  1099, 13660,  1478, -1934,
   -1934, -1934, 11899, 11899, -1934,  9526,  1713,    -2,   137, -1934,
   -1934,    -2,   140, -1934,  1721, -1934, 15130, -1934, 11899, -1934,
     446, -1934,  1722,  9526,  9526,  9526,  9526,  9273, -1934, -1934,
   -1934, 13786, -1934, 11899, 17391, 14277,    43, 11899,  1475, -1934,
   -1934, 14310, 14343,   716, -1934,   245, -1934,   249, -1934, -1934,
   -1934,  4951,   327, 13012, -1934,   721,   722,   723,   724,   263,
     731,  1480,   736, -1934, 11899, -1934,  7006, 15159, -1934, 11899,
   11899, -1934,    -2,    -2, -1934, -1934, -1934,   446,  1724,  1730,
    1731,  1732,  9526,  1735,  1737,  1738,  1486, 17416,   737,  1740,
   15188, 15359,   268,   285,   489, -1934, -1934, -1934, -1934,   738,
   -1934, -1934, -1934, 13562, -1934,  1489, -1934,  1743, -1934, 11899,
   11899, -1934,  1745,   745, -1934,  1494,  7006, -1934, 15217, 15246,
   -1934,  1746, 13562, 13562,   746,  1749,  1750, -1934, -1934,   747,
   -1934,  1751, -1934, -1934,  1752, 13562, -1934, -1934, -1934
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1934, -1934, -1934, -1934,   372, -1934, -1934, -1934, -1934,  -384,
   -1934, -1934, -1934, -1934, -1934, -1934, -1934, -1934, -1934, -1934,
   -1934, -1934,  -743,  -105,  2219,  3630,  -382, -1934,  1299, -1934,
   -1934, -1934, -1934, -1934, -1934, -1933, -1934,   312,   139,  -182,
   -1934,  -137, -1934,    80,   360, -1934,  1773, -1934,   942,   -55,
   -1934, -1934,    14,  -633,  -295, -1934, -1934, -1934, -1934, -1934,
   -1934, -1934,   705,  1775, -1934, -1934, -1934, -1934, -1258, -1255,
    1777, -1759,  1780, -1934, -1934, -1934,  1173, -1934,  -193, -1934,
   -1934, -1934, -1934,  2217, -1934, -1934, -1447,   236,  1787, -1934,
       0, -1934, -1934,    38, -1934, -1716,   311,  -172,  2564,  2906,
    -317,    16, -1934,   -66,    50, -1934, -1934,    45,   212, -1702,
    -129,  1004, -1934,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -578
static const yytype_int16 yytable[] =
{
     145,   627,  1507,  1509,   959,   960,  1676,  1879,   312,  1917,
    1064,  1918,   662,   374,   167,   167,  1070,   126,  2042,  1298,
     418,   370,   169,   420,  1068,   168,  1085,   502,  1346,     4,
     470,   153,   167,   346,  1364,   643,   509,   764,   554,   167,
     449,   148,   577,   167,  1755,   300,   182,  1502,   351,  2175,
     352,   300,   295,  1910,   667,  1643,     5,  1504,   431,   746,
    1250,   186,   781,   635,   636,   753,  1402,   796,   378,   301,
     317,  1192,   149,   797,  1400,  1079,  1193,   599,  1251,   453,
    1494,   350,  1346,  1487,   463,   466,   467,  1252,  1253,  1254,
     295,   747,   748,  1255,  1256,   377,   318,   150,  1403,  1404,
     599,   792,   635,   636,   151,  1644,   414,   326,   328,   478,
     331,   313,   319,   320,   314,   747,   748,   779,  1954,   635,
     636,  1965,   347,   954,   721,   780,   724,   730,   497,   152,
     612,   613,   614,   635,   636,   737,   635,   636,  1323,  1634,
     961,  1324,   455,  2156,   511,   353,  2158,   465,   465,   465,
     756,   170,   757,   171,   965,  1607,   472,  1490,  1189,   413,
     457,   417,   635,   636,   155,   749,   750,  1832,  1063,   371,
     657,   658,   659,  2148,   156,   481,  1346,   756,  1506,   757,
     635,   636,  1776,  1508,   157,   791,  1833,   674,   799,   749,
     750,   465,   635,   636,   797,   454,   295,   550,   551,   158,
     295,  1876,   159,   635,   636,   295,   295,   465,   785,  1365,
    1366,  1367,  1368,  1997,   635,   636,   786,   160,  1503,   637,
     926,    99,   479,   100,   101,   102,   103,   104,  1505,   348,
    1843,   108,   109,   162,   111,  1998,   119,   119,   119,   635,
     636,   322,   323,   161,  1756,   439,   440,   441,  1069,   439,
     440,   441,   442,   324,  1507,   119,   119,   325,  1086,  1087,
    1999,   295,   119,  2060,   198,   663,   119,   664,   375,   199,
    1353,   147,  1026,  1299,   419,   295,   163,   421,   295,   575,
     443,   444,   574,   765,   154,   766,   164,  -570,   349,   767,
    1369,   756,   555,   757,   295,   295,   578,   183,   295,   295,
     295,   295,  2176,   439,   440,   441,   442,   432,   782,   295,
     783,   433,   187,   295,   784,   377,  1347,  1350,  2099,   379,
     443,   444,   170,   600,   171,   601,  1169,   443,   444,   602,
     787,   950,   746,   952,   953,   165,  1349,   295,   788,   295,
     295,   295,   356,   443,   444,   357,   600,   793,   601,   783,
     966,  1045,   602,   794,   332,   170,   295,   171,   358,   630,
     631,   734,   166,   295,   747,   748,   293,   639,   644,   986,
     443,   444,   179,   731,   146,   732,   635,   636,   147,   733,
     635,   636,  2171,   635,   636,  1076,   886,  1086,  1087,   439,
     440,   441,   442,   180,  1006,   635,   636,   439,   440,   441,
     442,   181,  1093,   439,   440,   441,   442,   756,  1250,   757,
     635,   636,  1104,   443,   444,  1301,  2000,   746,   537,   876,
     538,   443,   444,   200,   465,   295,  1251,   443,   444,   295,
     295,  2001,   184,   456,  1043,  1252,  1253,  1254,   749,   750,
    1798,  1255,  1256,   185,   429,   295,   635,   636,   430,   747,
     748,   333,   768,   635,   636,   334,   635,   636,   635,   636,
    2198,   335,   336,   302,   337,   338,   303,  2002,   304,  1250,
     635,   636,   747,   748,  2133,   804,   870,  2134,   872,  2135,
     874,   875,   790,   635,   636,   339,   741,  1251,   635,   636,
     791,  2136,   635,   636,   888,   889,  1252,  1253,  1254,   443,
     444,   295,  1255,  1256,  2137,   188,   635,   636,  1464,  2182,
    2234,   635,   636,  2183,   342,  1201,   343,   751,   752,   687,
     510,   147,  2055,   749,   750,   295,  1720,  2192,   635,   636,
    1179,   170,  2219,   171,   295,   866,   322,   323,   791,   465,
    1196,   465,   295,   465,   465,   472,   749,   750,   324,  2220,
     882,   189,   330,  1389,   295,   295,   295,   465,   465,   295,
     169,   832,   169,   891,   295,   893,   201,   306,  1014,   756,
     307,   757,   309,   635,   636,   293,    68,    69,    70,    71,
     190,   306,    74,   310,   307,   308,   309,  2185,  1250,   638,
     295,    83,   173,   191,    86,   174,   923,   310,   175,   192,
     176,   204,  1571,  1572,   205,  1394,  1251,   206,   635,   636,
     193,    46,   611,   832,   892,  1252,  1253,  1254,   295,   295,
     207,  1255,  1256,   620,   645,   646,  1680,   625,  1681,   647,
    1013,  1250,  1015,  1016,  1017,  1018,  1019,  1020,  1519,  1022,
    1023,  1024,  1025,   443,   444,  1030,  1031,  1032,  1065,  1251,
    -572,   457,   457,   579,  1395,   756,  1239,   757,  1252,  1253,
    1254,   311,   832,  1321,  1255,  1256,   194,   295,   295,   295,
     596,   597,   295,   957,   958,  1764,   598,  1765,   631,  1352,
     591,   592,   728,   594,   595,   596,   597,   756,   195,   757,
     758,   598,   472,   465,   472,   465,   465,   465,   465,   465,
     465,   202,   465,   465,   465,   465,  1028,   196,   465,   465,
     465,   169,  1034,   660,  1033,   295,   197,   661,  1081,   728,
     594,   595,   596,   597,   170,  1100,   171,  1044,   598,   756,
    1195,   757,   209,  1196,  1109,   831,  1695,   832,  2030,   832,
     295,   896,   203,   738,   739,   832,  2031,   443,   444,  2221,
    1379,   210,  1332,   930,  -573,   295,  1857,   832,  1858,   754,
    1029,  1073,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,   295,  1090,   296,
    1797,   598,  1765,   295,  -574,   295,  2061,  2062,   472,  1102,
    2065,  2066,  2063,   443,   444,  1107,  2063,   465,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,  1452,   931,  1453,   297,   598,   832,   443,   444,   976,
    1211,  1213,  1212,   832,  1047,   298,  1462,   295,   832,   295,
    1777,   443,   444,  1053,  1331,  1199,  1332,  1054,  1234,   832,
    1784,  1235,   832,  1281,  1282,   832,  1283,   832,   832,  1285,
     832,  1747,  1748,   832,  1327,  1488,   873,  1115,   832,  1359,
     299,  1438,  1445,   832,   295,   832,   832,  1461,   611,  1469,
     887,   832,  2162,   832,   295,   635,   636,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   316,   295,  1486,  1605,   598,
    1656,   832,   832,   315,   832,  1872,  1688,  1507,   341,  1689,
     832,  1781,   295,   832,  1804,  1782,  1542,  1543,   832,  1806,
     344,  1888,  1937,   832,   295,   832,  1938,   345,  1955,  2204,
    1980,  1898,  1956,   295,   832,  1981,   321,   354,  1996,   832,
    1213,  1553,  1938,  2004,   295,   125,  2027,   832,  1558,  1507,
     791,   355,  2036,  2053,  1348,  1351,  2037,  1938,  2056,  2057,
    2088,  2109,   832,   832,   832,   832,  2110,  1573,  2116,   177,
     832,  1213,  1938,  2124,  2132,  2146,  2181,   832,   832,  1938,
     832,  2188,  2189,  2190,  2191,   832,   832,   832,   832,  1229,
     360,  2193,  1242,   579,  1593,   832,  2195,  2215,  2222,  1248,
    2037,  1938,   832,  1259,   305,  2231,  2241,  2244,  1609,  2232,
    1938,  2245,   361,   329,   756,  1615,   757,   927,   340,   362,
     363,   369,  1388,   372,   373,   380,   381,   382,   383,   384,
     415,   427,   428,   434,   461,   476,  1577,   460,   478,   435,
     147,   480,   485,   489,   503,  -205,  -206,   545,   548,   508,
    -207,   295,   557,   556,  1058,   560,   422,   563,   564,  1355,
     565,   576,   608,   430,   609,   616,   624,   295,   690,   618,
     617,   621,   648,   665,   626,  1868,  1869,   628,   629,   649,
     295,   650,   651,   652,   653,   465,   654,   451,   668,   666,
     669,   676,   451,   451,   451,   670,   671,   672,   673,   675,
     677,   451,   681,   678,  1463,  1465,   682,   683,   689,   716,
     698,  1443,  1444,  1356,   295,   295,   699,   295,   295,   295,
     700,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   715,   711,   295,   712,   714,   451,   717,   719,   725,
     718,   720,   722,   723,   740,   743,   755,   760,   762,   763,
     146,   801,   451,   769,  1411,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,   295,   465,   465,   805,   598,   807,   828,
     823,   834,   835,  1899,   836,   867,   877,   598,   878,   879,
     899,   900,   897,   549,   935,   936,   939,   295,   944,   948,
     949,  1004,   978,   951,   980,   999,   981,   984,   558,   559,
    1203,   993,  1007,   295,   295,   295,  1036,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     830,   594,   595,   596,   597,  1038,  1046,  1052,  1056,   598,
    1545,   756,  1057,   757,  1547,  1061,  1062,  1223,  1066,  1077,
    1078,  1094,  1083,  1551,  1096,  1552,  1099,  1106,  1554,  1780,
    1108,  1111,  1116,  1112,  1117,  1118,  1768,  1120,  1121,   295,
    1770,  1122,  1463,  1465,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,  1133,  1136,   457,  1140,   295,   295,   295,
    1167,  1168,  1194,  1200,  1176,  1177,  1178,  1185,   295,  1188,
    1204,  1216,  1208,   465,  1217,  1218,  1224,   465,  1237,  1226,
    1245,  1246,  1595,  1249,  1272,  1271,   465,  1274,   465,  1290,
    1291,   465,  1293,  1540,  1292,  1304,  1305,  1306,  1309,  1317,
    1319,  1320,  1326,  1330,  1333,  1335,  1334,   295,  1339,  1340,
    1336,  1341,  1345,  1358,  1360,  1361,  1376,  1382,  1383,  1384,
     377,  1390,  2069,  1393,  1385,  1414,  1398,  1418,  1397,  1430,
    -208,  1456,  1473,  1448,  1474,  1342,  1475,  1478,  1479,   451,
    1480,  1481,  1482,  1483,  1484,   465,  1485,  1496,  1495,   742,
     295,  1362,   295,  1499,  1500,  1501,  1510,  1511,  1522,  1512,
    1513,  1514,  1920,  1515,  1516,  1517,  1518,  1524,  1523,   295,
    1525,   776,  1526,  1548,  1528,  1527,  1529,  1530,  1531,  1537,
    1533,   295,  1549,  1555,  1556,   295,  1557,  1559,  1561,  1565,
    1570,  1567,  1575,  1580,  1576,  1579,  1581,  1586,  1412,  1413,
    1592,  1415,  1416,  1417,  1588,  1419,  1420,  1421,  1422,  1423,
    1424,  1425,  1426,  1427,  1428,  1589,  1604,  1606,  1590,  1612,
    1620,  1613,  1625,  1631,  1610,  1789,  1789,  1633,  1629,  1635,
    1630,  1639,  1640,  1641,  1646,  1926,  1647,  1648,  1778,  1649,
     295,   295,   295,  1650,  1651,  1652,  1653,  1654,   295,   295,
     295,  1655,  1667,  1674,   451,  1678,   451,  1442,   451,   451,
     451,  1687,  1693,  1694,  1700,  1701,   295,  1702,  1703,  1708,
    1704,  1711,   451,   451,  1716,  1709,  1710,   295,  1717,  1731,
    1732,  1457,  1723,  1740,  1741,   295,  1746,  1742,  1772,   295,
    1750,  1724,  1725,  1775,  1726,  1727,  1799,  1470,  1801,  1807,
     295,  1808,  1811,  1819,  1830,  1825,  1728,  1734,  1735,  1760,
    1791,  1767,  1809,  1796,  1810,  1753,  1719,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,  1324,  1774,  1827,  1771,   598,
    1803,  1541,  1828,   377,  1814,  1829,  1835,  1834,  1847,  1836,
    1837,   472,   472,  1520,  1850,   776,  1842,   295,  1852,  1196,
    1848,  1849,  1855,  1877,  1856,  1878,  1887,  1873,  1893,  1894,
    1913,  1534,  1535,  1536,  1912,   465,  1763,  1914,  1924,   776,
    1925,  1930,  -577,   791,  1942,   295,  1943,  -575,  1944,  1945,
     295,   761,  1949,  1959,  1958,  1960,  1964,  1953,  1975,  1961,
    1962,  1963,  1970,  1976,  1979,  1984,  1985,   451,   451,   451,
     451,   451,   451,   451,   451,   451,  1991,   451,   451,   451,
     451,  1566,  1993,   451,   451,   451,  1929,  2003,  1987,  2011,
    1988,  2006,  2021,   776,  2012,  1994,   776,  2018,  1818,  2019,
    2022,  2020,  2023,  1826,  2025,  2026,  2028,  2029,  2052,   776,
    2072,  2034,  2077,   778,  1904,  2073,  2084,  1906,  2089,  2090,
    2091,  2092,   295,  2094,  2100,  -576,  2103,   295,   295,  2075,
    2104,  2108,  2105,  2112,  2093,  2114,  2120,  2115,  2123,  2127,
    2128,  2139,  2117,  1624,  1080,  2140,  1082,  2142,  2121,  2154,
     295,  2131,   457,   457,  2125,  1638,   295,  2159,  2164,  1642,
    2205,   295,  2143,   451,  2150,  2178,  2206,  2207,  2208,   295,
    2194,  2210,   451,  2211,  2212,  2213,  2216,   465,  2226,  2227,
     465,  2230,  2237,  2233,  1863,  2242,  2243,  2246,  2247,  2172,
    1670,  1608,  1880,  1881,  1882,  1883,  1884,  1886,   295,  1824,
    2043,  1851,  1355,  1637,   800,  2015,   124,  1375,   135,   377,
     136,   295,   472,   137,  1690,  1691,  1692,   938,  2067,  1762,
     143,  1921,  1697,  1698,  1699,  1101,  2141,  1790,  1903,     0,
    1909,     0,     0,     0,     0,  1908,  1911,     0,     0,     0,
    1714,     0,     0,     0,     0,     0,     0,   472,     0,     0,
       0,  1722,     0,     0,     0,     0,  1922,     0,     0,  1730,
       0,     0,     0,     0,   295,  1429,  2163,     0,     0,     0,
       0,     0,     0,     0,  1739,   295,   295,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   776,     0,   776,   776,     0,     0,   295,     0,
       0,  1795,     0,     0,     0,     0,     0,     0,   776,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,   776,  1817,
       0,   598,     0,     0,     0,   295,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   776,     0,
     295,     0,     0,     0,     0,  2048,     0,     0,   295,   295,
       0,     0,     0,     0,  2016,  1521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,   295,
       0,     0,     0,     0,     0,   776,     0,     0,     0,     0,
     295,     0,     0,     0,   295,     0,     0,     0,     0,   457,
       0,     0,     0,     0,     0,     0,  1854,  2047,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   377,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     451,   295,     0,     0,  1795,     0,  2079,  2080,  2081,  2082,
    2083,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1895,     0,     0,     0,     0,     0,     0,
     295,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,  1919,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1928,     0,     0,     0,     0,
    2118,     0,     0,     0,  2122,     0,     0,     0,     0,     0,
       0,     0,   295,     0,     0,     0,     0,     0,     0,   451,
     451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   295,   295,   295,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2224,  1795,     0,
       0,     0,     0,     0,     0,  2155,     0,  2149,     0,  2157,
       0,     0,     0,     0,     0,     0,  2238,  2240,     0,     0,
       0,     0,     0,   295,     0,  2169,     0,     0,     0,  2248,
       0,   776,     0,     0,  1992,     0,     0,     0,     0,   295,
       0,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
     465,     0,     0,   598,     0,     0,     0,     0,     0,     0,
    2202,  2203,     0,   295,     0,     0,     0,     0,     0,   465,
     465,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   465,     0,     0,   172,     0,   178,   451,  2035,
       0,     0,   451,     0,     0,     0,     0,     0,     0,     0,
       0,   451,     0,   451,  2044,     0,   451,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1560,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1795,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2074,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     451,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1564,     0,   425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1795,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   452,     0,   450,     0,   462,     0,     0,     0,
       0,   468,     0,     0,  2119,     0,     0,     0,     0,   473,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   482,   483,   484,     0,
     486,   487,   488,     0,   490,   491,   492,   493,   494,   495,
     496,     0,   498,   499,   500,   501,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     539,   540,   541,   542,   543,   544,     0,   546,   547,     0,
       0,     0,     0,     0,     0,     0,   552,   553,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1795,   561,   562,
       0,     0,     0,     0,   566,   568,   570,   571,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   605,   505,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   451,   451,     0,     0,
       0,   623,     0,     0,     0,     0,     0,  1795,     0,     0,
       0,   633,   634,     0,     0,     0,     0,   634,     0,     0,
     451,     0,     0,     0,     0,     0,     0,   505,   656,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,   679,   505,     0,     0,     0,     0,   684,   685,
     686,     0,   688,     0,     0,     0,   691,   692,   693,     0,
       0,   694,     0,     0,     0,   695,   696,   697,     0,     0,
       0,   701,   702,   703,   704,   705,   706,   707,     0,   708,
       0,     0,     0,     0,   709,   710,     0,     0,   713,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   727,   726,     0,     0,   505,   736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   744,   745,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   777,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   451,     0,     0,   451,     0,   806,     0,     0,
       0,     0,   811,     0,     0,     0,   815,     0,     0,     0,
     776,     0,   776,     0,     0,     0,     0,     0,     0,     0,
     829,   568,     0,     0,     0,   833,     0,   451,     0,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   863,     0,   868,   869,     0,
     871,     0,   451,     0,     0,     0,     0,   506,     0,   880,
       0,     0,   884,   885,     0,     0,     0,     0,     0,   863,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   898,     0,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   912,   913,   914,
     916,   918,   919,   920,   921,   922,     0,   924,   925,     0,
       0,     0,     0,     0,  1582,   932,   933,   934,     0,     0,
       0,     0,     0,   940,   941,   942,   943,     0,   505,   505,
       0,     0,   569,     0,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   566,   727,   962,
       0,   506,   506,   967,   968,   969,   970,   971,   972,   973,
     974,   975,     0,     0,     0,     0,     0,   982,   983,     0,
     985,     0,     0,   987,     0,     0,     0,   505,   505,   505,
     992,     0,   505,   995,   996,   997,     0,     0,     0,     0,
    1000,     0,     0,     0,   506,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,  1021,     0,     0,     0,   598,     0,     0,     0,     0,
     506,     0,     0,     0,  1476,   505,     0,     0,     0,     0,
       0,     0,  1040,  1041,     0,  1042,     0,     0,   924,   925,
       0,     0,     0,     0,     0,     0,     0,  1055,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,  1071,     0,     0,
       0,     0,  1074,  1075,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,   505,     0,  1091,
    1092,     0,     0,   505,     0,   505,  1098,     0,     0,     0,
    1091,     0,  1105,     0,     0,     0,     0,   776,  1110,     0,
       0,  1712,  1113,     0,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,  1134,   598,   916,     0,  1137,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,   569,     0,
       0,     0,   598,     0,     0,  1769,     0,     0,     0,     0,
       0,     0,     0,   776,   505,     0,     0,     0,     0,     0,
       0,     0,   854,     0,   505,  1181,  1182,     0,     0,     0,
       0,   864,   865,     0,     0,   776,     0,     0,     0,   507,
       0,     0,  1197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   890,     0,     0,     0,
       0,   506,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   505,  1214,     0,     0,     0,     0,
       0,     0,  1222,     0,     0,   451,  1228,   917,     0,     0,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,  1243,  1244,   451,   451,     0,     0,  1247,     0,
       0,     0,     0,     0,     0,   506,   506,   451,     0,     0,
       0,     0,     0,     0,     0,  1273,     0,     0,  1275,     0,
       0,     0,     0,   606,   607,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1773,     0,     0,     0,
       0,     0,  1294,     0,  1296,  1297,     0,     0,     0,     0,
       0,     0,     0,     0,   506,   506,   506,     0,     0,   506,
       0,     0,     0,  1315,     0,     0,   655,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,  1338,     0,   598,
       0,     0,     0,     0,  1344,     0,     0,     0,     0,     0,
       0,  1357,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1380,  1381,     0,     0,     0,     0,
     505,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,   506,   598,     0,     0,  1401,     0,     0,     0,
       0,  1409,     0,     0,   735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,     0,
     506,     0,   506,   505,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1432,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1433,
    1434,  1435,  1436,  1437,     0,     0,     0,     0,  1439,  1440,
       0,  1441,     0,     0,   917,     0,  1138,     0,     0,     0,
    1779,     0,     0,     0,     0,  1450,  1451,     0,     0,     0,
       0,     0,     0,  1454,  1455,     0,     0,     0,     0,     0,
    1458,     0,  1459,  1460,     0,     0,     0,     0,  1466,  1467,
       0,   506,     0,     0,   505,   505,     0,     0,     0,     0,
       0,   506,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,  1498,     0,
       0,     0,     0,   894,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1532,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,  1546,   945,   946,     0,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,  1466,  1467,
       0,     0,   598,  1563,   756,     0,   757,     0,     0,     0,
       0,     0,  1751,     0,  1569,     0,     0,  1574,     0,     0,
       0,     0,     0,     0,     0,     0,   989,   990,   991,  1584,
    1585,   994,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1596,     0,     0,  1599,
     505,  1602,   505,     0,     0,     0,     0,     0,   167,   385,
    1611,     0,     0,  1614,     0,  1611,  1617,  1619,     0,     0,
    1627,  1628,     0,     0,  1035,     0,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,   506,   598,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,     0,     0,  1067,     0,   395,   396,   397,   398,
       0,     0,  1675,     0,   399,   400,   401,   402,     0,     0,
       0,  1682,   403,     0,   404,     0,  1089,     0,     0,     0,
       0,     0,  1095,     0,  1097,     0,     0,  1696,   405,     0,
     506,   406,     0,     0,     0,     0,     0,  1705,  1706,  1707,
       0,     0,     0,     0,     0,     0,  1713,     0,  1715,     0,
       0,     0,     0,     0,     0,  1718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,  1736,  1737,     0,     0,     0,
       0,     0,     0,     0,     0,  1743,  1744,  1745,     0,     0,
       0,     0,     0,     0,     0,  1754,     0,     0,     0,     0,
       0,     0,     0,  1170,     0,     0,  1766,     0,     0,     0,
       0,   506,   506,  1180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1783,     0,     0,
       0,     0,     0,     0,     0,  1792,  1793,     0,     0,     0,
       0,     0,   407,   408,   409,     0,     0,     0,     0,  1891,
       0,  1207,     0,     0,   410,     0,     0,     0,   411,     0,
     412,   119,     0,  1215,     0,     0,     0,     0,     0,     0,
    1822,  1820,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1838,  1839,  1840,     0,     0,     0,     0,     0,     0,
       0,     0,  1841,     0,     0,     0,     0,  1844,  1845,  1892,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1853,     0,     0,     0,     0,     0,     0,   505,   505,  1861,
       0,  1862,     0,     0,     0,     0,     0,  1870,  1871,  1983,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,   506,     0,   506,
       0,   505,  1890,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1902,     0,     0,  1905,     0,
       0,     0,  1907,     0,     0,     0,     0,     0,     0,     0,
       0,  1844,  1845,     0,  1916,     0,     0,     0,     0,  1387,
       0,     0,     0,     0,  1923,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1934,     0,
       0,     0,     0,  1940,  1941,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1946,     0,     0,
    1947,  1946,     0,  1950,     0,     0,     0,     0,     0,     0,
       0,     0,  1431,     0,  2010,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,   505,   505,   598,     0,     0,
       0,     0,  1977,  1978,     0,     0,     0,     0,     0,     0,
     759,     0,     0,     0,  1986,     0,   506,     0,     0,     0,
       0,     0,     0,  1995,     0,     0,     0,     0,     0,     0,
       0,     0,   568,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2007,  2008,     0,     0,   505,     0,
       0,     0,     0,  1471,  1472,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,  2024,     0,     0,   598,     0,     0,
       0,     0,  2032,  2033,     0,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,  2046,     0,     0,     0,   598,   505,   505,
    2051,     0,     0,   881,     0,  2054,     0,  1823,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,  1544,     0,     0,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,  2085,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   928,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2096,     0,
       0,     0,     0,     0,  2101,     0,     0,  2102,     0,     0,
       0,     0,     0,     0,   506,   506,     0,     0,     0,     0,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,  2126,  1601,
       0,  1603,   598,   506,     0,     0,     0,     0,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2144,  2145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2151,
    2152,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2161,     0,     0,     0,     0,
     505,   505,   505,   505,   505,     0,     0,     0,     0,     0,
    1940,     0,     0,     0,  2177,     0,     0,     0,     0,     0,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,  2197,   598,     0,     0,     0,  2200,  2201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,   506,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1733,     0,
       0,     0,     0,     0,     0,     0,  2228,  2229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   569,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,     0,  1153,
    1154,  1155,  1156,     0,  1158,  1159,  1160,  1161,  2058,   167,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1173,     0,  1175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1184,     0,     0,     0,     0,     0,     0,  1190,
    1191,     0,     0,     0,     0,   506,   506,     0,  1202,     0,
       0,  2059,     0,     0,   386,   387,   388,   389,   390,   391,
     392,   393,   394,     0,     0,     0,   506,   395,   396,   397,
     398,     0,     0,     0,     0,   399,   400,   401,   402,     0,
       0,   506,     0,   403,     0,   404,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   405,
       0,     0,   406,  2138,     0,     0,   173,     0,     0,   174,
       0,     0,   175,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,  1859,  1860,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1889,     0,  1300,  1302,  1303,     0,     0,     0,  1307,  1308,
       0,     0,  1311,  1312,  1313,  1314,     0,  1316,     0,     0,
       0,     0,  1322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   407,   408,   409,     0,   506,   506,   506,
     506,   506,     0,     0,     0,   410,     0,     0,     0,   411,
       0,   412,   119,     0,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,   443,   444,     0,
       0,     0,     0,  1408,  -571,  1410,  1594,     0,     0,     0,
       0,     0,     0,     0,  1973,  1974,   506,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   385,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2009,     0,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,   386,   387,   388,   389,   390,
     391,   392,   393,   394,  1468,     0,     0,     0,   395,   396,
     397,   398,     0,     0,     0,     0,   399,   400,   401,   402,
       0,     0,     0,     0,   403,     0,   404,  2049,  2050,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     405,     0,     0,   406,     0,     0,     0,   173,  2068,     0,
     174,     0,     0,   175,     0,   176,     0,     0,     0,     0,
       0,     0,     0,  2078,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   211,   167,   385,     0,   436,     0,     0,
     212,   213,   214,     0,   437,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   423,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,  2184,     0,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   246,   247,
     248,   249,   395,   396,   397,   398,   250,     0,     0,     0,
     399,   400,   401,   402,     0,     0,     0,     0,   403,  1583,
     404,   254,   255,   256,   407,   408,   409,     0,     0,     0,
       0,     0,   257,    25,   405,   258,   410,   406,     0,     0,
     411,   173,   412,   119,   174,     0,     0,   175,     0,   176,
       0,  2153,     0,     0,     0,     0,     0,     0,     0,     0,
      46,  1621,     0,     0,     0,     0,     0,     0,     0,  2165,
    2166,  2167,  2168,  2170,     0,  1785,     0,     0,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1657,  1658,  1659,  1660,  1661,  1662,  1663,     0,
       0,     0,     0,  1668,  1669,     0,     0,     0,     0,  1671,
       0,  1673,     0,     0,     0,  1677,     0,     0,  1679,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2209,  1686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     438,     0,     0,     0,     0,     0,     0,   268,   407,   408,
     409,   269,     0,     0,     0,     0,     0,   271,   272,   273,
     410,   274,   275,   276,   411,     0,   412,   119,   439,   440,
     441,   442,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   424,     0,     0,     0,     0,     0,
     279,     0,   443,   444,     0,   445,     0,   446,  1957,   579,
       0,   447,   282,     0,  1749,     0,  1752,     0,     0,     0,
    1759,     0,  1761,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,     0,     0,  1786,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,     6,   385,     0,     0,
       0,     0,   212,   213,   214,     0,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
       0,  1622,   387,   388,   389,   390,   391,   392,   393,   394,
     246,   247,   248,   249,   395,   396,   397,   398,   250,   251,
       0,     0,   399,   400,   401,   402,     0,     0,   252,   253,
     403,     0,   404,   254,   255,   256,     0,     0,     0,     0,
       0,     0,  1846,     0,   257,    25,   405,   258,     0,   406,
       0,     0,     0,   259,     0,     0,   260,     0,     0,   261,
       0,   262,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,    57,    58,     0,   265,     0,
     266,     0,     0,   267,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,     0,     0,
       0,     0,     0,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   830,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1931,     0,     0,
    1932,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     407,   408,   409,   269,   270,  2107,     0,     0,     0,   271,
     272,   273,   410,   274,   275,   276,   411,     0,   412,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   278,     0,  1966,  1967,
       0,  1969,   279,     0,     0,     0,     0,   365,     0,     0,
       0,  1623,     0,     0,   282,     0,     0,     0,     0,     0,
       0,   211,     6,   385,     0,     0,     0,     0,   212,   213,
     214,     0,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,  2013,  2014,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   246,   247,   248,   249,
     395,   396,   397,   398,   250,   251,     0,     0,   399,   400,
     401,   402,     0,     0,   252,   253,   403,     0,   404,   254,
     255,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     257,    25,   405,   258,  2045,   406,     0,     0,     0,   259,
       0,     0,   260,     0,     0,   261,     0,   262,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,    57,    58,     0,   265,     0,   266,     0,     0,   267,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,     0,     0,     0,     0,     0,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,   579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   407,   408,   409,   269,
     270,     0,     0,     0,     0,   271,   272,   273,   410,   274,
     275,   276,   411,     0,   412,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,   278,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,   365,   211,     6,   364,   281,     0,     0,
     282,   212,   213,   214,     0,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,   248,   249,     0,     0,     0,     0,   250,   251,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,     0,
       0,     0,   254,   255,   256,     0,     0,     0,     0,     0,
       0,  2218,     0,   257,    25,     0,   258,     0,     0,     0,
       0,     0,   259,     0,     0,   260,     0,     0,   261,     0,
     262,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,    57,    58,     0,   265,     0,   266,
       0,     0,   267,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    83,     0,     0,    86,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,     0,   579,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,   269,   270,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,   278,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,   365,   211,     6,     0,
     366,     0,   680,   282,   212,   213,   214,     0,     0,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,   248,   249,     0,     0,     0,     0,
     250,   251,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,     0,     0,     0,   254,   255,   256,     0,     0,
       0,     0,     0,     0,     0,     0,   257,    25,     0,   258,
       0,     0,     0,     0,     0,   259,     0,     0,   260,     0,
       0,   261,     0,   262,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,    57,    58,     0,
     265,     0,   266,     0,     0,   267,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   830,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,     0,  1008,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,     0,     0,     0,   269,   270,     0,     0,     0,
       0,   271,   272,   273,     0,   274,   275,   276,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   504,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,   365,
     211,     6,  1721,     0,   572,     0,   282,   212,   213,   214,
       0,     0,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,   248,   249,     0,
       0,     0,     0,   250,   251,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,     0,     0,     0,   254,   255,
     256,     0,     0,     0,     0,     0,     0,     0,     0,   257,
      25,     0,   258,     0,     0,     0,     0,     0,   259,     0,
       0,   260,     0,     0,   261,     0,   262,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
      57,    58,     0,   265,     0,   266,     0,     0,   267,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,     0,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    83,
       0,     0,    86,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,  1205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,     0,     0,   269,   270,
       0,     0,     0,     0,   271,   272,   273,     0,   274,   275,
     276,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   278,     0,     0,     0,     0,     0,   279,     0,     0,
       0,     0,   365,   211,     6,     0,   281,     0,     0,   282,
     212,   213,   214,     0,     0,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,     0,     0,     0,     0,   250,   251,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   253,     0,     0,
       0,   254,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,   257,    25,     0,   258,     0,     0,     0,     0,
       0,   259,     0,     0,   260,     0,     0,   261,     0,   262,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,    57,    58,     0,   265,     0,   266,     0,
       0,   267,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,  1206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,     0,
       0,   269,   270,     0,     0,     0,     0,   271,   272,   273,
       0,   274,   275,   276,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   640,  1885,     0,     0,     0,     0,     0,
     279,     0,     0,     0,     0,   642,   211,     6,     0,   325,
     572,     0,   282,   212,   213,   214,     0,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,   248,   249,     0,     0,     0,     0,   250,
     251,     0,     0,     0,     0,     0,     0,     0,     0,   252,
     253,     0,     0,     0,   254,   255,   256,     0,     0,     0,
       0,     0,     0,     0,     0,   257,    25,     0,   258,     0,
       0,     0,     0,     0,   259,     0,     0,   260,     0,     0,
     261,     0,   262,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,    57,    58,     0,   265,
       0,   266,     0,     0,   267,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,     0,  1539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,   269,   270,     0,     0,     0,     0,
     271,   272,   273,     0,   274,   275,   276,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   278,     0,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   280,   211,
       6,     0,   281,     0,     0,   282,   212,   213,   214,     0,
       0,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,   248,   249,     0,     0,
       0,     0,   250,   251,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,     0,     0,     0,   254,   255,   256,
       0,     0,     0,     0,     0,     0,     0,     0,   257,    25,
       0,   258,     0,     0,     0,     0,     0,   259,     0,     0,
     260,     0,     0,   261,     0,   262,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,    57,
      58,     0,   265,     0,   266,     0,     0,   267,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,     0,     0,     0,   269,   270,     0,
       0,     0,     0,   271,   272,   273,     0,   274,   275,   276,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     278,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,   365,   211,     6,     0,   281,     0,     0,   282,   212,
     213,   214,     0,     0,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,   248,
     249,     0,     0,     0,     0,   250,   251,     0,     0,     0,
       0,     0,     0,     0,     0,   252,   253,     0,     0,     0,
     254,   255,   256,     0,     0,     0,     0,     0,     0,     0,
       0,   257,    25,     0,   258,     0,     0,     0,     0,     0,
     259,     0,     0,   260,     0,     0,   261,     0,   262,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,    57,    58,     0,   265,     0,   266,     0,     0,
     267,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    83,     0,     0,    86,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,   998,
       0,     0,     0,     0,     0,     0,     0,   955,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,     0,     0,
     269,   270,     0,     0,     0,     0,   271,   272,   273,     0,
     274,   275,   276,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,   504,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   365,   211,     6,     0,   567,     0,
       0,   282,   212,   213,   214,     0,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,   248,   249,     0,     0,     0,     0,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   253,
       0,     0,     0,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,     0,   257,    25,     0,   258,     0,     0,
       0,     0,     0,   259,     0,     0,   260,     0,     0,   261,
       0,   262,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,    57,    58,     0,   265,     0,
     266,     0,     0,   267,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,  1815,     0,     0,     0,
    1816,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,     0,     0,   269,   270,     0,     0,     0,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   504,     0,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   365,   211,     6,
       0,     0,   572,     0,   282,   212,   213,   214,     0,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,     0,     0,     0,
       0,   250,   251,     0,     0,     0,     0,     0,     0,     0,
       0,   252,   253,     0,     0,     0,   254,   255,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   257,    25,     0,
     258,     0,     0,     0,     0,     0,   259,     0,     0,   260,
       0,     0,   261,     0,   262,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,    57,    58,
       0,   265,     0,   266,     0,     0,   267,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,  1866,
       0,     0,     0,  1867,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,     0,     0,   269,   270,     0,     0,
       0,     0,   271,   272,   273,     0,   274,   275,   276,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   278,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     610,   211,     6,     0,   281,     0,     0,   282,   212,   213,
     214,     0,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,   248,   249,
       0,     0,     0,     0,   250,   251,     0,     0,     0,     0,
       0,     0,     0,     0,   252,   253,     0,     0,     0,   254,
     255,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     257,    25,     0,   258,     0,     0,     0,     0,     0,   259,
       0,     0,   260,     0,     0,   261,     0,   262,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,    57,    58,     0,   265,     0,   266,     0,     0,   267,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,  1896,     0,     0,     0,  1897,     0,     0,     0,
       0,     0,     0,     0,     0,   268,     0,     0,     0,   269,
     270,     0,     0,     0,     0,   271,   272,   273,     0,   274,
     275,   276,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,   278,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,   619,   211,     6,     0,   281,     0,     0,
     282,   212,   213,   214,     0,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,   248,   249,     0,     0,     0,     0,   250,   251,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,     0,
       0,     0,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,     0,   257,    25,     0,   258,     0,     0,     0,
       0,     0,   259,     0,     0,   260,     0,     0,   261,     0,
     262,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,    57,    58,     0,   265,     0,   266,
       0,     0,   267,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,     0,    74,    75,    76,    77,    78,    79,
       0,     0,     0,    83,     0,     0,    86,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,  2070,     0,     0,     0,  2071,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,   269,   270,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,   504,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,   365,   211,     6,     0,
     915,     0,  1386,   282,   212,   213,   214,     0,     0,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,   248,   249,     0,     0,     0,     0,
     250,   251,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,     0,     0,     0,   254,   255,   256,     0,     0,
       0,     0,     0,     0,     0,     0,   257,    25,     0,   258,
       0,     0,     0,     0,     0,   259,     0,     0,   260,     0,
       0,   261,     0,   262,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,    57,    58,     0,
     265,     0,   266,     0,     0,   267,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   789,     0,     0,     0,     0,     0,     0,     0,
       0,   268,     0,     0,     0,   269,   270,     0,     0,     0,
       0,   271,   272,   273,     0,   274,   275,   276,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   504,     0,
       0,     0,     0,     0,   279,   211,     6,     0,     0,   365,
    1600,     0,   212,   213,   214,     0,   282,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,   248,   249,     0,     0,     0,     0,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,   252,   253,
       0,     0,     0,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,     0,   257,    25,     0,   258,     0,     0,
       0,     0,     0,   259,     0,     0,   260,     0,     0,   261,
       0,   262,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,    57,    58,     0,   265,     0,
     266,     0,     0,   267,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     795,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,     0,     0,   269,   270,     0,     0,     0,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   504,     0,     0,     0,
       0,     0,   279,   211,     6,     0,     0,   365,     0,     0,
     212,   213,   214,     0,   282,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,     0,     0,     0,     0,   250,   251,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   253,     0,     0,
       0,   254,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,   257,    25,     0,   258,     0,     0,     0,     0,
       0,   259,     0,     0,   260,     0,     0,   261,     0,   262,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,    57,    58,     0,   265,     0,   266,     0,
       0,   267,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   955,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,     0,
       0,   269,   270,     0,     0,     0,     0,   271,   272,   273,
       0,   274,   275,   276,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   278,     0,     0,     0,     0,     0,
     279,     0,     0,     0,     0,   365,   211,     6,     0,  1729,
       0,     0,   282,   212,   213,   214,     0,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,   248,   249,     0,     0,     0,     0,   250,
     251,     0,     0,     0,     0,     0,     0,     0,     0,   252,
     253,     0,     0,     0,   254,   255,   256,     0,     0,     0,
       0,     0,     0,     0,     0,   257,    25,     0,   258,     0,
       0,     0,     0,     0,   259,     0,     0,   260,     0,     0,
     261,     0,   262,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,    57,    58,     0,   265,
       0,   266,     0,     0,   267,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   956,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,   269,   270,     0,     0,     0,     0,
     271,   272,   273,     0,   274,   275,   276,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   640,  1885,     0,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   642,   211,
       6,     0,   325,     0,     0,   282,   212,   213,   214,     0,
       0,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,   248,   249,     0,     0,
       0,     0,   250,   251,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,     0,     0,     0,   254,   255,   256,
       0,     0,     0,     0,     0,     0,     0,     0,   257,    25,
       0,   258,     0,     0,     0,     0,     0,   259,     0,     0,
     260,     0,     0,   261,     0,   262,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   263,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,    57,
      58,     0,   265,     0,   266,     0,     0,   267,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1005,     0,     0,     0,     0,     0,
       0,     0,     0,   268,     0,     0,     0,   269,   270,     0,
       0,     0,     0,   271,   272,   273,     0,   274,   275,   276,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     504,     0,     0,     0,     0,     0,   279,   211,   167,   385,
       0,   365,     0,     0,   212,   213,   214,     0,   282,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   423,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   246,   247,   248,   249,   395,   396,   397,   398,
     250,     0,     0,     0,   399,   400,   401,   402,     0,     0,
       0,     0,   403,     0,   404,   254,   255,   256,     0,     0,
       0,     0,     0,     0,     0,     0,   257,    25,   405,   258,
       0,   406,   211,   167,   385,     0,     0,     0,     0,   212,
     213,   214,     0,     0,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   423,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   246,   247,   248,
     249,   395,   396,   397,   398,   250,     0,     0,     0,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   404,
     254,   255,   256,     0,     0,     0,     0,     0,     0,     0,
       0,   257,    25,   405,   258,     0,   406,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   407,   408,   409,   269,     0,     0,     0,     0,
       0,   271,   272,   273,   410,   274,   275,   276,   411,     0,
     412,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   424,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,   365,
       0,     0,     0,  1618,     0,     0,   282,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,     0,     0,     0,     0,     0,   268,   407,   408,   409,
     269,     0,     0,     0,     0,     0,   271,   272,   273,   410,
     274,   275,   276,   411,     0,   412,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,   424,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   365,   211,   167,   385,  1901,     0,
       0,   282,   212,   213,   214,     0,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   423,   233,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,  1622,   387,   388,   389,   390,   391,   392,   393,   394,
     246,   247,   248,   249,   395,   396,   397,   398,   250,     0,
       0,     0,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   404,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,     0,   257,    25,   405,   258,     0,   406,
     211,   167,   385,     0,     0,     0,     0,   212,   213,   214,
       0,     0,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   423,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   246,   247,   248,   249,   395,
     396,   397,   398,   250,     0,     0,     0,   399,   400,   401,
     402,     0,     0,     0,     0,   403,     0,   404,   254,   255,
     256,     0,     0,     0,     0,     0,     0,     0,     0,   257,
      25,   405,   258,     0,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     407,   408,   409,   269,     0,     0,     0,     0,     0,   271,
     272,   273,   410,   274,   275,   276,   411,     0,   412,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   424,     0,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   365,     0,     0,
       0,  1785,     0,     0,   282,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1152,     0,     0,
       0,     0,     0,     0,   268,   407,   408,   409,   269,     0,
       0,     0,     0,     0,   271,   272,   273,   410,   274,   275,
     276,   411,     0,   412,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   424,     0,     0,     0,     0,     0,   279,   211,   167,
       0,     0,   365,     0,     0,   212,   213,   214,     0,   282,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   423,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,     0,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
       0,     0,     0,     0,   211,   167,     0,   257,    25,     0,
     258,   212,   213,   214,     0,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   423,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,   248,   249,     0,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,     0,   257,    25,     0,   258,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,   268,     0,     0,     0,   269,     0,     0,  1162,
       0,     0,   271,   272,   273,     0,   274,   275,   276,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   424,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     365,     0,     0,     0,   622,     0,     0,   282,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,     0,     0,   268,     0,
    1163,     0,   269,     0,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   640,   641,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,   642,   211,   167,     0,
     325,     0,   883,   282,   212,   213,   214,     0,     0,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   423,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,   248,   249,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,     0,
       0,     0,     0,   211,   167,     0,   257,    25,     0,   258,
     212,   213,   214,     0,     0,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   423,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,     0,     0,     0,     0,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,   257,    25,     0,   258,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,   268,     0,     0,     0,   269,     0,     0,  1164,     0,
       0,   271,   272,   273,     0,   274,   275,   276,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   424,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,   365,
       0,     0,     0,     0,     0,     0,   282,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,     0,     0,   268,     0,  1165,
       0,   269,     0,     0,     0,     0,     0,   271,   272,   273,
       0,   274,   275,   276,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   424,     0,     0,     0,     0,     0,
     279,   211,   167,     0,  1337,   365,  1103,     0,   212,   213,
     214,     0,   282,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     423,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,   248,   249,
       0,     0,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
     255,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     257,    25,     0,   258,   211,   167,     0,  1497,     0,     0,
       0,   212,   213,   214,     0,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   423,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,   248,   249,     0,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,     0,   257,    25,     0,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,     0,     0,     0,   269,
       0,     0,     0,     0,     0,   271,   272,   273,     0,   274,
     275,   276,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,   424,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,   365,     0,     0,     0,     0,     0,     0,
     282,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1166,     0,     0,     0,     0,   268,     0,
       0,     0,   269,     0,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,   424,     0,     0,     0,     0,
       0,   279,   211,   167,     0,  1562,   365,     0,     0,   212,
     213,   214,     0,   282,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   423,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,   248,
     249,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,     0,     0,     0,     0,     0,   211,   167,
       0,   257,    25,     0,   258,   212,   213,   214,     0,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   423,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,     0,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   257,    25,     0,
     258,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,   268,     0,     0,     0,
     269,     0,     0,  1171,     0,     0,   271,   272,   273,     0,
     274,   275,   276,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,   424,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   282,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
       0,     0,   268,     0,  1172,     0,   269,     0,     0,     0,
       0,     0,   271,   272,   273,     0,   274,   275,   276,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   424,
       0,     0,     0,     0,     0,   279,   211,   167,     0,     0,
     365,  1616,     0,   212,   213,   214,     0,   282,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   423,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,   248,   249,     0,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,   256,     0,     0,     0,
       0,     0,   211,   167,     0,   257,    25,     0,   258,   212,
     213,   214,     0,     0,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   423,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,   248,
     249,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,     0,     0,     0,     0,     0,     0,     0,
       0,   257,    25,     0,   258,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
     268,     0,     0,     0,   269,     0,     0,  1174,     0,     0,
     271,   272,   273,     0,   274,   275,   276,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   424,     0,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   365,  1948,
       0,     0,     0,     0,     0,   282,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,   268,     0,  1288,     0,
     269,     0,     0,     0,     0,     0,   271,   272,   273,     0,
     274,   275,   276,   167,   385,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,   424,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   282,     0,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   393,   394,     7,     8,     0,
       0,   395,   396,   397,   398,     0,     0,     0,     0,   399,
     400,   401,   402,     0,     0,     0,     0,   403,     0,   404,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   405,     0,     0,   406,     0,     0,     0,
     173,     0,     0,   174,     0,     0,   175,     0,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,     0,     0,
       0,     0,     0,     7,     8,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   770,    56,     0,     0,    59,
     771,     0,   772,   773,     0,   774,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,   407,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
       0,     0,     0,   411,     0,   412,   119,     0,    95,    96,
      97,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     7,     8,    43,    44,    45,
      46,     0,     0,    48,     0,   756,     0,   757,  1785,     0,
       0,   770,    56,     0,     0,    59,   771,     0,   772,   773,
       0,   774,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     7,     8,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,     0,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     988,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,     0,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1037,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1039,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1238,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1240,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1241,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1260,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1279,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     7,     8,    59,   771,     0,
     772,   773,  1295,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     0,     0,    59,   771,     0,
     772,   773,  1329,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    95,    96,    97,     0,
       0,     0,     0,   770,    56,     0,     0,    59,   771,     0,
     772,   773,  1489,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,    -4,     1,     0,     0,    -4,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2129,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,    -4,    -4,    -4,     0,   598,     0,     0,    -4,
      -4,     0,     0,     0,    -4,     0,  1310,     0,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,  2186,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,     7,     8,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,     0,     0,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     9,    10,    11,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1396,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14,     0,
       0,     0,     0,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,     0,    25,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,    42,    43,    44,    45,    46,
      47,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,    65,    66,    67,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,    91,    92,     0,     0,     0,    93,     0,     0,
       0,     0,    94,    95,    96,    97,   167,   385,    98,     0,
      99,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,   118,     0,   119,     0,     0,     0,
       0,   386,   387,   388,   389,   390,   391,   392,   393,   394,
       0,     0,     0,     0,   395,   396,   397,   398,   416,   385,
       0,     0,   399,   400,   401,   402,     0,     0,     0,     0,
     403,     0,   404,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,     0,     0,   406,
       0,     0,     0,   173,     0,   385,   174,     0,     0,   175,
       0,   176,     0,   386,   387,   388,   389,   390,   391,   392,
     393,   394,    46,     0,     0,     0,   395,   396,   397,   398,
       0,     0,     0,     0,   399,   400,   401,   402,     0,     0,
     437,     0,   403,     0,   404,     0,     0,     0,     0,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   405,     0,
       0,   406,   395,   396,   397,   398,     0,     0,     0,     0,
     399,   400,   401,   402,     0,     0,     0,     0,   403,     0,
     404,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,     0,     0,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     407,   408,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,     0,     0,     0,   411,     0,   412,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,   407,   408,   409,  1399,     0,     0,     0,     0,
       0,     0,     0,     0,   410,     0,     0,     0,   411,     0,
     412,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   407,   408,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,     0,     0,     0,   411,     0,   412,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       7,     8,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   770,    56,     0,
       0,    59,   771,     0,   772,   773,     0,   774,     0,     0,
       0,  1049,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,  1050,
       0,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
      95,    96,    97,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1491,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   770,    56,
       0,     0,    59,   771,     0,   772,   773,     0,   774,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,    95,    96,    97,     0,     0,     0,     0,     0,  1492,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1538,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1664,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1665,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1666,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1813,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1935,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1936,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1968,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2040,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2097,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2098,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2113,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2147,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2174,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2179,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2180,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,   827,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,  1084,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,  1139,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,  1186,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,  1187,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,  1231,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
    1263,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,  1277,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,  1284,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,  1343,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,  1363,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,  1446,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,  1447,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,  1493,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,  1568,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,  1864,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
    1875,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,  1915,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,  1989,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,  2005,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,  2017,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,     0,  2041,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,     0,     0,  2076,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,     0,  2086,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,     0,     0,     0,
       0,     0,  2087,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
       0,  2111,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,     0,     0,
    2160,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,     0,     0,  2199,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,     0,     0,  2217,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,     0,     0,  2235,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,     0,     0,  2236,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,     0,   729,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,     0,   947,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,     0,
    1982,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,   756,     0,   757,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,  1011,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,  1060,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,  1210,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,  1278,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,  1280,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,     0,     0,  1286,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   728,   594,   595,   596,   597,     0,     0,
       0,     0,   598,     0,     0,     0,  1287,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     728,   594,   595,   596,   597,     0,     0,     0,     0,   598,
       0,     0,     0,  1378,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   728,   594,   595,
     596,   597,     0,     0,     0,     0,   598,     0,     0,     0,
    1392,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   728,   594,   595,   596,   597,     0,
       0,     0,     0,   598,     0,     0,     0,  1597,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,     0,     0,  1685,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   728,   594,
     595,   596,   597,     0,     0,     0,     0,   598,     0,     0,
       0,  1738,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   728,   594,   595,   596,   597,
       0,     0,     0,     0,   598,     0,     0,     0,  1927,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   728,   594,   595,   596,   597,     0,     0,     0,
       0,   598,     0,     0,     0,  1972,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   728,
     594,   595,   596,   597,     0,     0,     0,     0,   598,     0,
       0,     0,  1990,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   808,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   809,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   810,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   812,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   813,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   814,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   816,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   817,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   818,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   819,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   820,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   821,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   822,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   824,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   825,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   826,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   895,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   929,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,   977,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,   998,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1001,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1002,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1003,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1009,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1010,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1048,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1059,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1119,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1123,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1135,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1209,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1219,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1220,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1221,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1230,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1232,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1233,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1262,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1264,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1265,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1266,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1267,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1268,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1269,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1270,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1276,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1289,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1328,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1377,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1391,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1598,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1632,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1672,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1684,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1800,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1802,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1805,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1812,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1865,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1874,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  1900,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  1971,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  2038,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  2039,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598,     0,  2173,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   728,   594,   595,   596,   597,     0,     0,     0,     0,
     598,     0,  2214,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   728,   594,   595,   596,
     597,     0,     0,     0,     0,   598
};

static const yytype_int16 yycheck[] =
{
       3,   318,  1257,  1261,   637,   638,  1453,  1723,    63,  1768,
     753,  1770,     4,     4,     4,     4,   759,     3,  1951,     7,
       5,   107,    25,     5,     7,    25,     6,   199,     7,     6,
     159,     6,     4,     4,     4,   330,   208,     9,     5,     4,
     145,    14,     5,     4,     4,   107,     4,     6,     4,     6,
       6,   107,    55,  1755,   349,   142,     0,     6,     6,     4,
     142,     4,     9,   243,   244,   447,     4,   258,     4,   131,
     163,   256,   107,   264,     7,   131,   261,     9,   160,   145,
     260,    84,     7,     4,   150,   151,   152,   169,   170,   171,
      93,    36,    37,   175,   176,    98,   189,   255,    36,    37,
       9,     9,   243,   244,   255,   192,   109,    69,    70,     9,
      72,   104,   205,   206,   107,    36,    37,   256,  1820,   243,
     244,  1837,    93,   264,   419,   264,   421,     9,   194,   255,
     302,   303,   304,   243,   244,   430,   243,   244,   261,     6,
     264,   264,   145,     6,   210,   101,     6,   150,   151,   152,
     256,   255,   258,   257,   264,     6,   159,   264,   264,   109,
     146,   111,   243,   244,     6,   110,   111,   101,     7,   255,
     342,   343,   344,  2106,     6,   178,     7,   256,   260,   258,
     243,   244,     7,   264,     6,   264,   120,   359,   258,   110,
     111,   194,   243,   244,   264,   145,   199,   252,   253,     6,
     203,   264,   255,   243,   244,   208,   209,   210,   256,   179,
     180,   181,   182,   264,   243,   244,   264,     6,   177,   259,
     602,   191,   172,   193,   194,   195,   196,   197,   177,   200,
    1677,   201,   202,   259,   204,   264,   227,   227,   227,   243,
     244,   243,   244,     6,   204,   228,   229,   230,   231,   228,
     229,   230,   231,   255,  1509,   227,   227,   259,   238,   239,
     264,   264,   227,  1979,   259,   257,   227,   259,   259,   122,
     259,   263,   262,   261,   259,   278,     6,   259,   281,   282,
     252,   253,   282,   255,   259,   257,     6,   259,   259,   261,
     260,   256,   259,   258,   297,   298,   259,   255,   301,   302,
     303,   304,   259,   228,   229,   230,   231,   255,   255,   312,
     257,   259,   255,   316,   261,   318,  1059,  1060,  2034,   255,
     252,   253,   255,   255,   257,   257,   258,   252,   253,   261,
     256,   626,     4,   628,   629,   257,   261,   340,   264,   342,
     343,   344,   104,   252,   253,   107,   255,   255,   257,   257,
     645,   733,   261,   261,     4,   255,   359,   257,   120,   321,
     322,   427,   257,   366,    36,    37,    55,   329,   330,   664,
     252,   253,   255,   255,   259,   257,   243,   244,   263,   261,
     243,   244,  2141,   243,   244,   767,   558,   238,   239,   228,
     229,   230,   231,   255,   689,   243,   244,   228,   229,   230,
     231,   255,   784,   228,   229,   230,   231,   256,   142,   258,
     243,   244,   794,   252,   253,   264,   264,     4,   255,   548,
     257,   252,   253,   107,   427,   428,   160,   252,   253,   432,
     433,   264,   255,     4,   729,   169,   170,   171,   110,   111,
       4,   175,   176,   255,   255,   448,   243,   244,   259,    36,
      37,   101,   455,   243,   244,   105,   243,   244,   243,   244,
    2176,   111,   112,   104,   114,   115,   107,   264,   109,   142,
     243,   244,    36,    37,   264,   478,   542,   264,   544,   264,
     546,   547,   256,   243,   244,   135,   436,   160,   243,   244,
     264,   264,   243,   244,   560,   561,   169,   170,   171,   252,
     253,   504,   175,   176,   264,   255,   243,   244,   261,   264,
    2226,   243,   244,   264,   107,   897,   109,   189,   190,   261,
     209,   263,  1969,   110,   111,   528,   260,   264,   243,   244,
     256,   255,   264,   257,   537,   538,   243,   244,   264,   542,
     264,   544,   545,   546,   547,   548,   110,   111,   255,   264,
     553,   255,   259,   256,   557,   558,   559,   560,   561,   562,
     563,   264,   565,   563,   567,   565,     6,   104,   697,   256,
     107,   258,   109,   243,   244,   264,   147,   148,   149,   150,
     255,   104,   153,   120,   107,   108,   109,   260,   142,   259,
     593,   162,   101,   255,   165,   104,   599,   120,   107,   255,
     109,   101,   189,   190,   104,   256,   160,   107,   243,   244,
     255,   120,   301,   264,   564,   169,   170,   171,   621,   622,
     120,   175,   176,   312,   259,   255,   255,   316,   257,   259,
     696,   142,   698,   699,   700,   701,   702,   703,  1271,   705,
     706,   707,   708,   252,   253,   711,   712,   713,   753,   160,
     259,   637,   638,     8,   256,   256,   951,   258,   169,   170,
     171,   184,   264,   264,   175,   176,   255,   670,   671,   672,
     248,   249,   675,   635,   636,   255,   254,   257,   640,  1061,
     243,   244,   245,   246,   247,   248,   249,   256,   255,   258,
     259,   254,   695,   696,   697,   698,   699,   700,   701,   702,
     703,     6,   705,   706,   707,   708,   709,   255,   711,   712,
     713,   714,   715,   255,   714,   718,   255,   259,   773,   245,
     246,   247,   248,   249,   255,   791,   257,   730,   254,   256,
     261,   258,   109,   264,   800,   260,  1479,   264,   256,   264,
     743,   260,   259,   432,   433,   264,   264,   252,   253,   260,
     255,   255,   257,   260,   259,   758,     4,   264,     6,   448,
     710,   764,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   780,   781,   255,
     255,   254,   257,   786,   259,   788,   147,   148,   791,   792,
     147,   148,   153,   252,   253,   798,   153,   800,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,  1193,   260,  1195,   259,   254,   264,   252,   253,   260,
     255,   926,   257,   264,   260,   259,  1208,   830,   264,   832,
    1573,   252,   253,   260,   255,   260,   257,   264,   260,   264,
    1583,   260,   264,   260,   260,   264,   260,   264,   264,   260,
     264,     6,     7,   264,   260,  1237,   545,   807,   264,   260,
     107,   260,   260,   264,   867,   264,   264,   260,   557,   260,
     559,   264,  2130,   264,   877,   243,   244,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   104,   899,   260,   260,   254,
     260,   264,   264,   255,   264,   260,   260,  2162,   255,   260,
     264,   260,   915,   264,   260,   264,  1298,  1299,   264,   260,
     107,   260,   260,   264,   927,   264,   264,   104,   260,  2187,
     260,     8,   264,   936,   264,   260,   259,   104,   260,   264,
    1045,  1323,   264,   260,   947,     3,   260,   264,  1330,  2204,
     264,   107,   260,   260,  1059,  1060,   264,   264,   260,   260,
     260,   260,   264,   264,   264,   264,   260,  1349,   260,    27,
     264,  1076,   264,   260,   260,   260,   260,   264,   264,   264,
     264,   260,   260,   260,   260,   264,   264,   264,   264,   939,
     107,   260,   954,     8,  1376,   264,   260,   260,   260,   961,
     264,   264,   264,   965,    62,   260,   260,   260,  1390,   264,
     264,   264,     4,   259,   256,  1397,   258,   259,   259,     4,
       4,     4,  1088,   255,   255,   255,   255,     6,     6,   257,
     255,   257,   259,     6,     6,   255,  1353,   259,     9,   263,
     263,   255,   255,   255,   255,   192,   192,   255,   255,   259,
     192,  1054,   131,   259,   743,   255,   114,   255,   255,  1062,
     255,   192,   255,   259,   255,   255,     4,  1070,   192,   255,
     259,   259,   255,     6,   259,  1708,  1709,   259,   259,   255,
    1083,   255,   255,   255,   255,  1088,   255,   145,     6,   257,
       6,   257,   150,   151,   152,   259,   259,   259,   259,   259,
     257,   159,     6,   257,  1209,  1210,     6,   255,   259,     6,
     255,  1177,  1178,  1063,  1117,  1118,   255,  1120,  1121,  1122,
     255,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,   257,   255,  1136,   255,   255,   194,     6,     6,   255,
     259,     8,     6,     8,   259,     7,     6,   259,   259,     6,
     259,    96,   210,   260,  1116,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,  1176,  1177,  1178,   264,   254,   264,     7,
     256,     6,     6,   260,   256,   259,   259,   254,   259,   259,
      67,     8,   261,   251,     7,     7,   255,  1200,     6,   256,
       6,   189,     7,   259,     6,   260,     7,     6,   266,   267,
     899,     6,   259,  1216,  1217,  1218,   260,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   260,   258,   256,     6,   254,
    1306,   256,   259,   258,  1310,   261,     7,   936,     6,   257,
     255,     6,   259,  1319,     6,  1321,     6,     6,  1324,  1576,
       6,   256,     7,   257,     7,     7,  1561,     7,     7,  1272,
    1565,     7,  1377,  1378,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   259,  1271,     6,  1290,  1291,  1292,
     256,   258,   256,     7,   264,   264,   264,   260,  1301,   264,
     260,     7,   261,  1306,   259,   259,     4,  1310,   261,     6,
     260,   260,  1378,   142,     7,   259,  1319,     6,  1321,     7,
       7,  1324,   261,     8,     7,   256,   256,   264,   264,     9,
     264,   256,   258,   261,   263,     7,   192,  1340,   260,   259,
     163,     6,     6,     6,    49,    49,   261,   255,   259,   255,
    1353,   261,  1985,   255,   259,     7,   255,     7,   261,     7,
     192,   256,     7,   264,     7,  1054,     7,     6,   256,   427,
     264,     7,     7,     7,     7,  1378,     7,     4,   119,   437,
    1383,  1070,  1385,   259,     6,   255,     7,     6,   259,     7,
       7,     7,  1774,     7,     7,     7,     7,     6,   101,  1402,
       6,   459,     6,   262,     7,   107,     7,     6,     6,     4,
       7,  1414,   264,   256,   264,  1418,     6,   259,   259,   259,
       6,   260,     6,   257,     7,     6,     6,     6,  1117,  1118,
       6,  1120,  1121,  1122,   255,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,   255,   260,     6,   259,     6,
    1400,     6,  1402,     6,   261,  1584,  1585,     6,   258,   135,
     264,     6,     6,     6,     6,  1782,     6,     6,  1573,     6,
    1473,  1474,  1475,     6,     6,     6,     6,     6,  1481,  1482,
    1483,     5,   256,   256,   542,     6,   544,  1176,   546,   547,
     548,     6,     4,     6,   259,   259,  1499,     7,     6,   259,
       7,   257,   560,   561,     6,   259,   259,  1510,     6,   260,
       6,  1200,   259,     6,     6,  1518,     6,   188,     6,  1522,
     264,   259,   259,     7,   259,   259,     6,  1216,     6,     6,
    1533,     6,     4,     7,   142,     6,   259,   259,   259,   256,
     255,   259,  1608,   259,   255,   264,  1508,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   264,   261,     6,   264,   254,
     260,   256,     6,  1576,   255,     6,     6,   105,  1683,     5,
     259,  1584,  1585,  1272,     6,   643,   256,  1590,     6,   264,
     259,   259,   142,     6,   142,     6,     6,   264,     6,     6,
     256,  1290,  1291,  1292,   264,  1608,  1556,   264,     6,   667,
       6,     6,   259,   264,     6,  1618,     6,   259,     6,     6,
    1623,     6,     6,   146,     7,     6,     5,   259,     6,   259,
     259,   259,   256,     6,   259,     6,   259,   695,   696,   697,
     698,   699,   700,   701,   702,   703,     6,   705,   706,   707,
     708,  1340,     7,   711,   712,   713,  1785,     6,   260,     6,
     260,   187,     7,   721,   256,   259,   724,   260,  1618,   260,
       6,   260,     6,  1635,   261,     6,     6,     6,     6,   737,
       6,   259,     6,     6,  1750,   260,     6,  1753,   256,     6,
     259,     6,  1695,   190,     6,   259,     6,  1700,  1701,  1994,
     260,   255,   260,   259,  2021,   256,     6,   259,     6,     6,
     142,     6,   259,  1402,   772,     6,   774,     6,   259,     6,
    1723,   259,  1708,  1709,   260,  1414,  1729,     6,     6,  1418,
       6,  1734,   259,   791,   256,   260,     6,     6,     6,  1742,
     260,     6,   800,     6,     6,   259,     6,  1750,   259,     6,
    1753,     6,     6,   259,  1704,     6,     6,     6,     6,  2143,
    1448,  1389,  1724,  1725,  1726,  1727,  1728,  1729,  1771,  1630,
    1952,  1691,  1775,  1413,   475,  1912,     3,  1072,     3,  1782,
       3,  1784,  1785,     3,  1473,  1474,  1475,   614,  1981,  1553,
       3,  1775,  1481,  1482,  1483,   791,  2091,  1585,  1748,    -1,
    1755,    -1,    -1,    -1,    -1,  1755,  1756,    -1,    -1,    -1,
    1499,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,  1510,    -1,    -1,    -1,    -1,  1776,    -1,    -1,  1518,
      -1,    -1,    -1,    -1,  1837,     6,  2131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1533,  1848,  1849,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
    1873,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1885,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   950,    -1,   952,   953,    -1,    -1,  1901,    -1,
      -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,   966,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   986,  1618,
      -1,   254,    -1,    -1,    -1,  1938,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1006,    -1,
    1953,    -1,    -1,    -1,    -1,  1958,    -1,    -1,  1961,  1962,
      -1,    -1,    -1,    -1,  1914,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,  1982,
      -1,    -1,    -1,    -1,    -1,  1043,    -1,    -1,    -1,    -1,
    1993,    -1,    -1,    -1,  1997,    -1,    -1,    -1,    -1,  1985,
      -1,    -1,    -1,    -1,    -1,    -1,  1695,  1957,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2021,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1088,  2034,    -1,    -1,  1723,    -1,  1998,  1999,  2000,  2001,
    2002,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1742,    -1,    -1,    -1,    -1,    -1,    -1,
    2063,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,  1771,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1784,    -1,    -1,    -1,    -1,
    2062,    -1,    -1,    -1,  2066,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2115,    -1,    -1,    -1,    -1,    -1,    -1,  1177,
    1178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2133,  2134,  2135,  2136,  2137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2213,  1837,    -1,
      -1,    -1,    -1,    -1,    -1,  2117,    -1,  2107,    -1,  2121,
      -1,    -1,    -1,    -1,    -1,    -1,  2232,  2233,    -1,    -1,
      -1,    -1,    -1,  2176,    -1,  2137,    -1,    -1,    -1,  2245,
      -1,  1239,    -1,    -1,  1873,    -1,    -1,    -1,    -1,  2192,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
    2213,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
    2182,  2183,    -1,  2226,    -1,    -1,    -1,    -1,    -1,  2232,
    2233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2245,    -1,    -1,    26,    -1,    28,  1306,  1938,
      -1,    -1,  1310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1319,    -1,  1321,  1953,    -1,  1324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1334,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1979,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1993,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1378,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2034,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,   145,    -1,   149,    -1,    -1,    -1,
      -1,   154,    -1,    -1,  2063,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    -1,
     183,   184,   185,    -1,   187,   188,   189,   190,   191,   192,
     193,    -1,   195,   196,   197,   198,    -1,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,    -1,   248,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2176,   269,   270,
      -1,    -1,    -1,    -1,   277,   278,   279,   280,   281,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   296,   297,   298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1584,  1585,    -1,    -1,
      -1,   314,    -1,    -1,    -1,    -1,    -1,  2226,    -1,    -1,
      -1,   324,   325,    -1,    -1,    -1,    -1,   330,    -1,    -1,
    1608,    -1,    -1,    -1,    -1,    -1,    -1,   340,   341,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,   365,   366,    -1,    -1,    -1,    -1,   371,   372,
     373,    -1,   375,    -1,    -1,    -1,   379,   380,   381,    -1,
      -1,   384,    -1,    -1,    -1,   386,   387,   388,    -1,    -1,
      -1,   392,   393,   394,   395,   396,   397,   398,    -1,   400,
      -1,    -1,    -1,    -1,   405,   406,    -1,    -1,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   424,   423,    -1,    -1,   428,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   445,   446,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1750,    -1,    -1,  1753,    -1,   480,    -1,    -1,
      -1,    -1,   485,    -1,    -1,    -1,   489,    -1,    -1,    -1,
    1768,    -1,  1770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     503,   504,    -1,    -1,    -1,   508,    -1,  1785,    -1,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,    -1,   540,   541,    -1,
     543,    -1,  1820,    -1,    -1,    -1,    -1,   203,    -1,   552,
      -1,    -1,   555,   556,    -1,    -1,    -1,    -1,    -1,   562,
      -1,    -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   575,    -1,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,    -1,   600,   601,    -1,
      -1,    -1,    -1,    -1,     6,   608,   609,   610,    -1,    -1,
      -1,    -1,    -1,   616,   617,   618,   619,    -1,   621,   622,
      -1,    -1,   278,    -1,    -1,   281,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   640,   641,   642,
      -1,   297,   298,   646,   647,   648,   649,   650,   651,   652,
     653,   654,    -1,    -1,    -1,    -1,    -1,   660,   661,    -1,
     663,    -1,    -1,   666,    -1,    -1,    -1,   670,   671,   672,
     673,    -1,   675,   676,   677,   678,    -1,    -1,    -1,    -1,
     683,    -1,    -1,    -1,   340,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   704,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     366,    -1,    -1,    -1,   142,   718,    -1,    -1,    -1,    -1,
      -1,    -1,   725,   726,    -1,   728,    -1,    -1,   731,   732,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   740,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   758,    -1,   760,    -1,    -1,
      -1,    -1,   765,   766,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,    -1,    -1,    -1,    -1,   780,    -1,   782,
     783,    -1,    -1,   786,    -1,   788,   789,    -1,    -1,    -1,
     793,    -1,   795,    -1,    -1,    -1,    -1,  2075,   801,    -1,
      -1,     6,   805,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,   828,   254,   830,    -1,   832,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   504,    -1,
      -1,    -1,   254,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2141,   867,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   528,    -1,   877,   878,   879,    -1,    -1,    -1,
      -1,   537,   538,    -1,    -1,  2163,    -1,    -1,    -1,   203,
      -1,    -1,   893,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
      -1,   567,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   927,   926,    -1,    -1,    -1,    -1,
      -1,    -1,   935,    -1,    -1,  2213,   939,   593,    -1,    -1,
      -1,    -1,    -1,    -1,   947,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   955,   956,  2232,  2233,    -1,    -1,   961,    -1,
      -1,    -1,    -1,    -1,    -1,   621,   622,  2245,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   978,    -1,    -1,   981,    -1,
      -1,    -1,    -1,   297,   298,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,  1005,    -1,  1007,  1008,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   670,   671,   672,    -1,    -1,   675,
      -1,    -1,    -1,  1026,    -1,    -1,   340,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,  1050,    -1,   254,
      -1,    -1,    -1,    -1,  1057,    -1,    -1,    -1,    -1,    -1,
      -1,  1064,   718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1077,  1078,    -1,    -1,    -1,    -1,
    1083,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,   758,   254,    -1,    -1,  1107,    -1,    -1,    -1,
      -1,  1114,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   780,    -1,    -1,    -1,    -1,    -1,
     786,    -1,   788,  1136,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1162,
    1163,  1164,  1165,  1166,    -1,    -1,    -1,    -1,  1171,  1172,
      -1,  1174,    -1,    -1,   830,    -1,   832,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,  1188,  1189,    -1,    -1,    -1,
      -1,    -1,    -1,  1196,  1197,    -1,    -1,    -1,    -1,    -1,
    1201,    -1,  1205,  1206,    -1,    -1,    -1,    -1,  1211,  1212,
      -1,   867,    -1,    -1,  1217,  1218,    -1,    -1,    -1,    -1,
      -1,   877,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,  1251,    -1,
      -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,   915,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   927,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1288,    -1,    -1,    -1,    -1,
      -1,   947,    -1,    -1,    -1,    -1,    -1,    -1,  1301,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1309,   621,   622,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,  1331,  1332,
      -1,    -1,   254,  1336,   256,    -1,   258,    -1,    -1,    -1,
      -1,    -1,   264,    -1,  1347,    -1,    -1,  1350,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   670,   671,   672,  1360,
    1361,   675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1379,    -1,    -1,  1382,
    1383,  1384,  1385,    -1,    -1,    -1,    -1,    -1,     4,     5,
    1393,    -1,    -1,  1396,    -1,  1398,  1399,  1400,    -1,    -1,
    1403,  1404,    -1,    -1,   718,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,  1083,   254,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,   758,    -1,    62,    63,    64,    65,
      -1,    -1,  1453,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,  1462,    78,    -1,    80,    -1,   780,    -1,    -1,    -1,
      -1,    -1,   786,    -1,   788,    -1,    -1,  1480,    94,    -1,
    1136,    97,    -1,    -1,    -1,    -1,    -1,  1490,  1491,  1492,
      -1,    -1,    -1,    -1,    -1,    -1,  1499,    -1,  1501,    -1,
      -1,    -1,    -1,    -1,    -1,  1508,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1522,
      -1,    -1,    -1,    -1,    -1,  1528,  1529,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1538,  1539,  1540,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1548,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   867,    -1,    -1,  1559,    -1,    -1,    -1,
      -1,  1217,  1218,   877,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1588,  1589,    -1,    -1,    -1,
      -1,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,     6,
      -1,   915,    -1,    -1,   220,    -1,    -1,    -1,   224,    -1,
     226,   227,    -1,   927,    -1,    -1,    -1,    -1,    -1,    -1,
    1623,  1622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   947,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1664,  1665,  1666,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1675,    -1,    -1,    -1,    -1,  1680,  1681,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1693,    -1,    -1,    -1,    -1,    -1,    -1,  1700,  1701,  1702,
      -1,  1704,    -1,    -1,    -1,    -1,    -1,  1710,  1711,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1729,  1383,    -1,  1385,
      -1,  1734,  1735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1748,    -1,    -1,  1751,    -1,
      -1,    -1,  1755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1764,  1765,    -1,  1767,    -1,    -1,    -1,    -1,  1083,
      -1,    -1,    -1,    -1,  1777,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,    -1,
      -1,    -1,    -1,  1796,  1797,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1810,    -1,    -1,
    1813,  1814,    -1,  1816,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1136,    -1,     6,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,  1848,  1849,   254,    -1,    -1,
      -1,    -1,  1855,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,    -1,  1867,    -1,  1522,    -1,    -1,    -1,
      -1,    -1,    -1,  1876,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1885,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1897,  1898,    -1,    -1,  1901,    -1,
      -1,    -1,    -1,  1217,  1218,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,     6,    -1,    -1,   254,    -1,    -1,
      -1,    -1,  1935,  1936,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,  1956,    -1,    -1,    -1,   254,  1961,  1962,
    1963,    -1,    -1,   553,    -1,  1968,    -1,  1623,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1301,    -1,    -1,
      -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2006,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2031,    -1,
      -1,    -1,    -1,    -1,  2037,    -1,    -1,  2040,    -1,    -1,
      -1,    -1,    -1,    -1,  1700,  1701,    -1,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,  2071,  1383,
      -1,  1385,   254,  1729,    -1,    -1,    -1,    -1,  1734,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2097,  2098,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2112,
    2113,    -1,  2115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2128,    -1,    -1,    -1,    -1,
    2133,  2134,  2135,  2136,  2137,    -1,    -1,    -1,    -1,    -1,
    2143,    -1,    -1,    -1,  2147,    -1,    -1,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,  2174,   254,    -1,    -1,    -1,  2179,  2180,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2192,
      -1,    -1,  1848,  1849,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2219,  2220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1885,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1901,    -1,   837,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847,    -1,   849,
     850,   851,   852,    -1,   854,   855,   856,   857,     6,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     870,    -1,   872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   882,    -1,    -1,    -1,    -1,    -1,    -1,   889,
     890,    -1,    -1,    -1,    -1,  1961,  1962,    -1,   898,    -1,
      -1,     6,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,  1982,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,  1997,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    97,     6,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,  1700,  1701,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1734,    -1,  1012,  1013,  1014,    -1,    -1,    -1,  1018,  1019,
      -1,    -1,  1022,  1023,  1024,  1025,    -1,  1027,    -1,    -1,
      -1,    -1,  1032,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   208,   209,   210,    -1,  2133,  2134,  2135,
    2136,  2137,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,
      -1,   226,   227,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,   252,   253,    -1,
      -1,    -1,    -1,  1113,   259,  1115,   261,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1848,  1849,  2192,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1901,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,  1214,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,  1961,  1962,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,   101,  1982,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1997,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,   138,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,  1359,
      80,    81,    82,    83,   208,   209,   210,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,   220,    97,    -1,    -1,
     224,   101,   226,   227,   104,    -1,    -1,   107,    -1,   109,
      -1,  2115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,  1401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2133,
    2134,  2135,  2136,  2137,    -1,   259,    -1,    -1,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1432,  1433,  1434,  1435,  1436,  1437,  1438,    -1,
      -1,    -1,    -1,  1443,  1444,    -1,    -1,    -1,    -1,  1449,
      -1,  1451,    -1,    -1,    -1,  1455,    -1,    -1,  1458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2192,  1469,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   226,   227,   228,   229,
     230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,   252,   253,    -1,   255,    -1,   257,     7,     8,
      -1,   261,   262,    -1,  1544,    -1,  1546,    -1,    -1,    -1,
    1550,    -1,  1552,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1584,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,  1682,    -1,    92,    93,    94,    95,    -1,    97,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,    -1,
      -1,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,  1787,    -1,    -1,
    1790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,   211,   212,     7,    -1,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,  1838,  1839,
      -1,  1841,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,  1905,  1906,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,  1954,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,   255,     3,     4,     5,   259,    -1,    -1,
     262,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,  2201,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,
      -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,    -1,   153,   154,   155,   156,   157,   158,
      -1,    -1,    -1,   162,    -1,    -1,   165,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,
     259,    -1,     8,   262,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,
       3,     4,     5,    -1,   260,    -1,   262,    10,    11,    12,
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
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,   259,
     260,    -1,   262,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,
       4,    -1,   259,    -1,    -1,   262,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,   255,     3,     4,    -1,   259,    -1,    -1,   262,    10,
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
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
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
     254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,    -1,   260,    -1,   262,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,
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
      -1,    -1,   260,    -1,    -1,    -1,   264,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,
     259,    -1,     8,   262,    10,    11,    12,    -1,    -1,    15,
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
       8,    -1,    10,    11,    12,    -1,   262,    15,    16,    17,
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
      -1,    -1,   250,     3,     4,    -1,    -1,   255,    -1,    -1,
      10,    11,    12,    -1,   262,    15,    16,    17,    18,    19,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
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
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,
       4,    -1,   259,    -1,    -1,   262,    10,    11,    12,    -1,
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
     244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,     5,
      -1,   255,    -1,    -1,    10,    11,    12,    -1,   262,    15,
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
      -1,    -1,    -1,    -1,   255,     3,     4,     5,   259,    -1,
      -1,   262,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,   259,    -1,    -1,   262,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,    -1,
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,
      -1,    -1,   255,    -1,    -1,    10,    11,    12,    -1,   262,
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
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,   259,    -1,    -1,   262,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
     264,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,    -1,
     259,    -1,     8,   262,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    92,    93,    -1,    95,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   207,    -1,    -1,    -1,   211,    -1,    -1,   264,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   264,
      -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,     3,     4,    -1,     6,   255,   256,    -1,    10,    11,
      12,    -1,   262,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,     3,     4,    -1,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
     262,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,   207,    -1,
      -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,     3,     4,    -1,     6,   255,    -1,    -1,    10,
      11,    12,    -1,   262,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    92,    93,    -1,    95,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,   207,    -1,    -1,    -1,
     211,    -1,    -1,   264,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,    -1,   264,    -1,   211,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,     3,     4,    -1,    -1,
     255,   256,    -1,    10,    11,    12,    -1,   262,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    92,    93,    -1,    95,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
     207,    -1,    -1,    -1,   211,    -1,    -1,   264,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,   256,
      -1,    -1,    -1,    -1,    -1,   262,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   264,    -1,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,     4,     5,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    13,    14,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    13,    14,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   208,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
      -1,    -1,    -1,   224,    -1,   226,   227,    -1,   184,   185,
     186,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    13,    14,   117,   118,   119,
     120,    -1,    -1,   123,    -1,   256,    -1,   258,   259,    -1,
      -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    13,    14,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,   184,   185,   186,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,   260,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    67,    68,    69,    -1,   254,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    -1,   264,    -1,    -1,    84,
      85,    86,    87,    88,    -1,    90,    91,    -1,    93,    -1,
      -1,    -1,   260,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,   123,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,   172,   173,   174,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,   183,   184,
     185,   186,    -1,    -1,   189,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,     4,    -1,    -1,    -1,    -1,   213,   214,
     215,   216,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,   227,    -1,    -1,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    46,    47,    48,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,    90,
      91,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,   116,   117,   118,   119,   120,
     121,    -1,   123,    -1,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,   172,   173,   174,    -1,    -1,    -1,   178,    -1,    -1,
      -1,    -1,   183,   184,   185,   186,     4,     5,   189,    -1,
     191,    -1,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   213,   214,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,     4,     5,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,   101,    -1,     5,   104,    -1,    -1,   107,
      -1,   109,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   120,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
     138,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    94,    -1,
      -1,    97,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   220,    -1,    -1,    -1,   224,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,   208,   209,   210,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,    -1,    -1,   224,    -1,   226,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      13,    14,    -1,   117,   118,   119,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,
      -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,
      -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,   163,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     184,   185,   186,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,   264,
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
      -1,    -1,    -1,    -1,   259,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,   259,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
     259,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,   256,    -1,   258,   232,   233,
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
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,   256,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254
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
       6,     6,   259,     6,     6,   257,   257,     4,   355,   378,
     255,   257,   289,   101,   104,   107,   109,   313,   289,   255,
     255,   255,     4,   255,   255,   255,     4,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   259,   122,
     107,     6,     6,   259,   101,   104,   107,   120,   316,   109,
     255,     3,    10,    11,    12,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    58,    59,    60,    61,
      66,    67,    76,    77,    81,    82,    83,    92,    95,   101,
     104,   107,   109,   120,   131,   136,   138,   141,   207,   211,
     212,   217,   218,   219,   221,   222,   223,   243,   244,   250,
     255,   259,   262,   313,   314,   317,   328,   335,   337,   348,
     349,   353,   355,   361,   363,   378,   255,   259,   259,   107,
     107,   131,   104,   107,   109,   313,   104,   107,   108,   109,
     120,   184,   314,   104,   107,   255,   104,   163,   189,   205,
     206,   259,   243,   244,   255,   259,   358,   359,   358,   259,
     259,   358,     4,   101,   105,   111,   112,   114,   115,   135,
     259,   255,   107,   109,   107,   104,     4,    93,   200,   259,
     378,     4,     6,   101,   104,   107,   104,   107,   120,   315,
     107,     4,     4,     4,     5,   255,   259,   361,   362,     4,
     107,   255,   255,   255,     4,   259,   365,   378,     4,   255,
     255,   255,     6,     6,   257,     5,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    62,    63,    64,    65,    70,
      71,    72,    73,    78,    80,    94,    97,   208,   209,   210,
     220,   224,   226,   369,   378,   255,     4,   369,     5,   259,
       5,   259,   313,    32,   244,   348,   378,   257,   259,   255,
     259,     6,   255,   259,     6,   263,     7,   138,   200,   228,
     229,   230,   231,   252,   253,   255,   257,   261,   287,   288,
     289,   313,   348,   368,   369,   378,     4,   317,   318,   319,
     259,     6,   348,   368,   369,   378,   368,   368,   348,   368,
     375,   376,   378,   348,   294,   298,   255,   357,     9,   369,
     255,   378,   348,   348,   348,   255,   348,   348,   348,   255,
     348,   348,   348,   348,   348,   348,   348,   368,   348,   348,
     348,   348,   362,   255,   244,   348,   363,   364,   259,   362,
     361,   368,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   255,   257,   289,
     289,   289,   289,   289,   289,   255,   289,   289,   255,   313,
     314,   314,   289,   289,     5,   259,   259,   131,   313,   313,
     255,   289,   289,   255,   255,   255,   348,   259,   348,   363,
     348,   348,   260,   364,   355,   378,   192,     5,   259,     8,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   254,     9,
     255,   257,   261,   288,   289,   348,   364,   364,   255,   255,
     255,   361,   362,   362,   362,   312,   255,   259,   255,   255,
     361,   259,   259,   348,     4,   361,   259,   365,   259,   259,
     358,   358,   358,   348,   348,   243,   244,   259,   259,   358,
     243,   244,   255,   319,   358,   259,   255,   259,   255,   255,
     255,   255,   255,   255,   255,   364,   348,   362,   362,   362,
     255,   259,     4,   257,   259,     6,   257,   319,     6,     6,
     259,   259,   259,   259,   362,   259,   257,   257,   257,   348,
       8,     6,     6,   255,   348,   348,   348,   261,   348,   259,
     192,   348,   348,   348,   348,   289,   289,   289,   255,   255,
     255,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   255,   255,   289,   255,   257,     6,     6,   259,     6,
       8,   319,     6,     8,   319,   255,   289,   348,   245,   259,
       9,   255,   257,   261,   368,   364,   348,   319,   361,   361,
     259,   369,   313,     7,   348,   348,     4,    36,    37,   110,
     111,   189,   190,   291,   361,     6,   256,   258,   259,   290,
     259,     6,   259,     6,     9,   255,   257,   261,   378,   260,
     131,   136,   138,   139,   141,   311,   313,   348,     6,   256,
     264,     9,   255,   257,   261,   256,   264,   256,   264,   264,
     256,   264,     9,   255,   261,   264,   258,   264,   293,   258,
     293,    96,   356,   354,   378,   264,   348,   264,   256,   256,
     256,   348,   256,   256,   256,   348,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   260,     7,   348,
     245,   260,   264,   348,     6,     6,   256,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   363,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   363,   363,   378,   259,   348,   348,
     368,   348,   368,   361,   368,   368,   375,   259,   259,   259,
     348,   290,   378,     8,   348,   348,   362,   361,   368,   368,
     363,   355,   369,   355,   364,   256,   260,   261,   289,    67,
       8,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   259,   348,   363,   348,   348,
     348,   348,   348,   378,   348,   348,   291,   259,   290,   256,
     260,   260,   348,   348,   348,     7,     7,   341,   341,   255,
     348,   348,   348,   348,     6,   364,   364,   259,   256,     6,
     319,   259,   319,   319,   264,   264,   264,   358,   358,   318,
     318,   264,   348,   260,   332,   264,   319,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   260,   256,     7,   342,
       6,     7,   348,   348,     6,   348,   319,   348,   260,   364,
     364,   364,   348,     6,   364,   348,   348,   348,   256,   260,
     348,   256,   256,   256,   189,   264,   319,   259,     8,   256,
     256,   258,   375,   368,   375,   368,   368,   368,   368,   368,
     368,   348,   368,   368,   368,   368,   262,   371,   378,   369,
     368,   368,   368,   355,   378,   364,   260,   260,   260,   260,
     348,   348,   348,   319,   378,   291,   258,   260,   256,   145,
     163,   336,   256,   260,   264,   348,     6,   259,   361,   256,
     258,   261,     7,     7,   287,   288,     6,   364,     7,   231,
     287,   348,   272,   378,   348,   348,   291,   257,   255,   131,
     313,   314,   313,   259,   260,     6,   238,   239,   269,   364,
     378,   348,   348,   291,     6,   364,     6,   364,   348,     6,
     368,   376,   378,   256,   291,   348,     6,   378,     6,   368,
     348,   256,   257,   348,   264,   369,     7,     7,     7,   256,
       7,     7,     7,   256,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   348,   256,   259,   348,   363,   260,
       6,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   264,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   264,   264,   264,   264,   264,   256,   258,   258,
     364,   264,   264,   290,   264,   290,   264,   264,   264,   256,
     364,   348,   348,   350,   290,   260,   260,   260,   264,   264,
     290,   290,   256,   261,   256,   261,   264,   289,   351,   260,
       7,   291,   290,   361,   260,     8,     8,   364,   261,   256,
     258,   255,   257,   288,   289,   364,     7,   259,   259,   256,
     256,   256,   348,   361,     4,   340,     6,   307,   348,   369,
     256,   260,   256,   256,   260,   260,   364,   261,   260,   319,
     260,   260,   358,   348,   348,   260,   260,   348,   358,   142,
     142,   160,   169,   170,   171,   175,   176,   333,   334,   358,
     260,   329,   256,   260,   256,   256,   256,   256,   256,   256,
     256,   259,     7,   348,     6,   348,   256,   260,   258,   260,
     258,   260,   260,   260,   260,   260,   258,   258,   264,   256,
       7,     7,     7,   261,   348,   260,   348,   348,     7,   261,
     290,   264,   290,   290,   256,   256,   264,   290,   290,   264,
     264,   290,   290,   290,   290,   348,   290,     9,   370,   264,
     256,   264,   290,   261,   264,   352,   258,   260,   256,   260,
     261,   255,   257,   263,   192,     7,   163,     6,   348,   260,
     259,     6,   361,   260,   348,     6,     7,   287,   288,   261,
     287,   288,   291,   259,   366,   378,   369,   348,     6,   260,
      49,    49,   361,   260,     4,   179,   180,   181,   182,   260,
     275,   279,   282,   284,   285,   327,   261,   256,   258,   255,
     348,   348,   255,   259,   255,   259,     8,   364,   368,   256,
     261,   256,   258,   255,   256,   256,   264,   261,   255,   264,
       7,   289,     4,    36,    37,   301,   302,   303,   290,   348,
     290,   358,   361,   361,     7,   361,   361,   361,     7,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,     6,
       7,   364,   348,   348,   348,   348,   348,   348,   260,   348,
     348,   348,   361,   368,   368,   260,   260,   260,   264,   300,
     348,   348,   291,   291,   348,   348,   256,   361,   289,   348,
     348,   260,   291,   288,   261,   288,   348,   348,   290,   260,
     361,   364,   364,     7,     7,     7,   142,   339,     6,   256,
     264,     7,     7,     7,     7,     7,   260,     4,   291,   260,
     264,   264,   264,   260,   260,   119,     4,     6,   348,   259,
       6,   255,     6,   177,     6,   177,   260,   334,   264,   333,
       7,     6,     7,     7,     7,     7,     7,     7,     7,   318,
     361,     6,   259,   101,     6,     6,     6,   107,     7,     7,
       6,     6,   348,     7,   361,   361,   361,     4,   264,     8,
       8,   256,   291,   291,   364,   368,   348,   368,   262,   264,
     304,   368,   368,   291,   368,   256,   264,     6,   291,   259,
     313,   259,     6,   348,     6,   259,   361,   260,   260,   348,
       6,   189,   190,   291,   348,     6,     7,   365,   367,     6,
     257,     6,     6,   290,   289,   289,     6,   276,   255,   255,
     259,   286,     6,   291,   261,   368,   348,   258,   256,   348,
       8,   364,   348,   364,   260,   260,     6,     6,   269,   291,
     261,   348,     6,     6,   348,   291,   256,   348,   259,   348,
     369,   290,    49,   259,   361,   369,   372,   348,   348,   258,
     264,     6,   256,     6,     6,   135,   309,   309,   361,     6,
       6,     6,   361,   142,   192,   308,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     5,   260,   290,   290,   290,
     290,   290,   290,   290,   264,   264,   264,   256,   290,   290,
     302,   290,   256,   290,   256,   289,   351,   290,     6,   290,
     255,   257,   289,   291,   256,   258,   290,     6,   260,   260,
     361,   361,   361,     4,     6,   287,   348,   361,   361,   361,
     259,   259,     7,     6,     7,   348,   348,   348,   259,   259,
     259,   257,     6,   348,   361,   348,     6,     6,   348,   358,
     260,     5,   361,   259,   259,   259,   259,   259,   259,   259,
     361,   260,     6,   364,   259,   259,   348,   348,   258,   361,
       6,     6,   188,   348,   348,   348,     6,     6,     7,   290,
     264,   264,   290,   264,   348,     4,   204,   305,   306,   290,
     256,   290,   352,   369,   255,   257,   348,   259,   319,     6,
     319,   264,     6,     6,   261,     7,     7,   287,   288,     6,
     365,   260,   264,   348,   287,   259,   290,   373,   374,   375,
     373,   255,   348,   348,   360,   361,   259,   255,     4,     6,
     256,     6,   256,   260,   260,   256,   260,     6,     6,   368,
     255,     4,   256,   264,   255,   260,   264,   361,   369,     7,
     289,   299,   348,   363,   303,     6,   358,     6,     6,     6,
     142,   310,   101,   120,   105,     6,     5,   259,   348,   348,
     348,   348,   256,   351,   348,   348,   290,   288,   259,   259,
       6,   308,     6,   348,   361,   142,   142,     4,     6,   364,
     364,   348,   348,   369,   260,   256,   260,   264,   318,   318,
     348,   348,   260,   264,   256,   260,   264,     6,     6,   360,
     358,   358,   358,   358,   358,   244,   358,     6,   260,   364,
     348,     6,     6,     6,     6,   361,   260,   264,     8,   260,
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
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 184:
#line 2007 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 185:
#line 2013 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 186:
#line 2020 "Gmsh.y"
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

  case 187:
#line 2051 "Gmsh.y"
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

  case 188:
#line 2066 "Gmsh.y"
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

  case 189:
#line 2088 "Gmsh.y"
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

  case 190:
#line 2111 "Gmsh.y"
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

  case 191:
#line 2134 "Gmsh.y"
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

  case 192:
#line 2157 "Gmsh.y"
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

  case 193:
#line 2181 "Gmsh.y"
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

  case 194:
#line 2205 "Gmsh.y"
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

  case 195:
#line 2229 "Gmsh.y"
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

  case 196:
#line 2255 "Gmsh.y"
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

  case 197:
#line 2272 "Gmsh.y"
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

  case 198:
#line 2288 "Gmsh.y"
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

  case 199:
#line 2306 "Gmsh.y"
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

  case 200:
#line 2324 "Gmsh.y"
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

  case 201:
#line 2337 "Gmsh.y"
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

  case 202:
#line 2349 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 203:
#line 2353 "Gmsh.y"
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

  case 204:
#line 2379 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 205:
#line 2381 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 206:
#line 2383 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 207:
#line 2385 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 208:
#line 2387 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 209:
#line 2395 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 210:
#line 2397 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 211:
#line 2399 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 212:
#line 2401 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 213:
#line 2409 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 214:
#line 2411 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 215:
#line 2413 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 216:
#line 2421 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 217:
#line 2423 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 218:
#line 2425 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 219:
#line 2427 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 220:
#line 2437 "Gmsh.y"
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

  case 221:
#line 2453 "Gmsh.y"
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

  case 222:
#line 2469 "Gmsh.y"
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

  case 223:
#line 2485 "Gmsh.y"
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

  case 224:
#line 2501 "Gmsh.y"
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

  case 225:
#line 2517 "Gmsh.y"
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

  case 226:
#line 2534 "Gmsh.y"
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

  case 227:
#line 2571 "Gmsh.y"
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

  case 228:
#line 2592 "Gmsh.y"
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

  case 229:
#line 2613 "Gmsh.y"
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

  case 230:
#line 2638 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 231:
#line 2639 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 232:
#line 2644 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 233:
#line 2648 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 234:
#line 2652 "Gmsh.y"
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

  case 235:
#line 2669 "Gmsh.y"
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

  case 236:
#line 2689 "Gmsh.y"
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

  case 237:
#line 2709 "Gmsh.y"
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

  case 238:
#line 2728 "Gmsh.y"
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

  case 239:
#line 2755 "Gmsh.y"
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

  case 240:
#line 2774 "Gmsh.y"
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

  case 241:
#line 2796 "Gmsh.y"
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

  case 242:
#line 2811 "Gmsh.y"
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

  case 243:
#line 2826 "Gmsh.y"
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

  case 244:
#line 2845 "Gmsh.y"
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

  case 245:
#line 2896 "Gmsh.y"
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

  case 246:
#line 2917 "Gmsh.y"
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

  case 247:
#line 2939 "Gmsh.y"
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

  case 248:
#line 2961 "Gmsh.y"
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

  case 249:
#line 3066 "Gmsh.y"
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

  case 250:
#line 3082 "Gmsh.y"
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

  case 251:
#line 3117 "Gmsh.y"
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

  case 252:
#line 3139 "Gmsh.y"
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

  case 253:
#line 3161 "Gmsh.y"
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

  case 254:
#line 3173 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 255:
#line 3179 "Gmsh.y"
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

  case 256:
#line 3194 "Gmsh.y"
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

  case 257:
#line 3225 "Gmsh.y"
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

  case 258:
#line 3237 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 259:
#line 3246 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3253 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 261:
#line 3265 "Gmsh.y"
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

  case 262:
#line 3285 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 263:
#line 3289 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 264:
#line 3294 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 265:
#line 3298 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 266:
#line 3303 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 267:
#line 3310 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 268:
#line 3317 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 269:
#line 3324 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 270:
#line 3336 "Gmsh.y"
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

  case 271:
#line 3409 "Gmsh.y"
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

  case 272:
#line 3427 "Gmsh.y"
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

  case 273:
#line 3452 "Gmsh.y"
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

  case 274:
#line 3467 "Gmsh.y"
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

  case 275:
#line 3500 "Gmsh.y"
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

  case 276:
#line 3512 "Gmsh.y"
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

  case 277:
#line 3544 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 278:
#line 3548 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 279:
#line 3553 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 280:
#line 3560 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 281:
#line 3565 "Gmsh.y"
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

  case 282:
#line 3575 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 283:
#line 3580 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 284:
#line 3586 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 285:
#line 3594 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals! Make it optional?
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 286:
#line 3602 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 287:
#line 3606 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 288:
#line 3610 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 289:
#line 3614 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 290:
#line 3618 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 291:
#line 3622 "Gmsh.y"
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

  case 292:
#line 3634 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 293:
#line 3644 "Gmsh.y"
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

  case 294:
#line 3707 "Gmsh.y"
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

  case 295:
#line 3723 "Gmsh.y"
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

  case 296:
#line 3740 "Gmsh.y"
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

  case 297:
#line 3757 "Gmsh.y"
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

  case 298:
#line 3779 "Gmsh.y"
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

  case 299:
#line 3801 "Gmsh.y"
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

  case 300:
#line 3836 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 301:
#line 3844 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 302:
#line 3852 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 303:
#line 3858 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 304:
#line 3865 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 305:
#line 3872 "Gmsh.y"
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

  case 306:
#line 3892 "Gmsh.y"
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

  case 307:
#line 3918 "Gmsh.y"
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

  case 308:
#line 3930 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 309:
#line 3941 "Gmsh.y"
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

  case 310:
#line 3959 "Gmsh.y"
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

  case 311:
#line 3977 "Gmsh.y"
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

  case 312:
#line 3995 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4001 "Gmsh.y"
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

  case 314:
#line 4019 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 315:
#line 4025 "Gmsh.y"
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

  case 316:
#line 4045 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 317:
#line 4051 "Gmsh.y"
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

  case 318:
#line 4069 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 319:
#line 4075 "Gmsh.y"
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

  case 320:
#line 4092 "Gmsh.y"
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

  case 321:
#line 4108 "Gmsh.y"
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

  case 322:
#line 4125 "Gmsh.y"
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

  case 323:
#line 4143 "Gmsh.y"
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

  case 324:
#line 4166 "Gmsh.y"
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

  case 325:
#line 4193 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 4196 "Gmsh.y"
    {
    ;}
    break;

  case 327:
#line 4202 "Gmsh.y"
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

  case 328:
#line 4214 "Gmsh.y"
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

  case 329:
#line 4234 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 330:
#line 4238 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 331:
#line 4242 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 332:
#line 4246 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 333:
#line 4250 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 334:
#line 4254 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 335:
#line 4258 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 336:
#line 4262 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 337:
#line 4271 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 338:
#line 4283 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 339:
#line 4284 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 340:
#line 4285 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 341:
#line 4286 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 342:
#line 4287 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 343:
#line 4291 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 344:
#line 4292 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 345:
#line 4293 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 346:
#line 4294 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 347:
#line 4295 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 348:
#line 4300 "Gmsh.y"
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

  case 349:
#line 4323 "Gmsh.y"
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

  case 350:
#line 4343 "Gmsh.y"
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

  case 351:
#line 4364 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 352:
#line 4368 "Gmsh.y"
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

  case 353:
#line 4383 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 354:
#line 4387 "Gmsh.y"
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

  case 355:
#line 4403 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 356:
#line 4407 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 357:
#line 4412 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 358:
#line 4416 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 359:
#line 4422 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 360:
#line 4426 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 361:
#line 4433 "Gmsh.y"
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

  case 362:
#line 4455 "Gmsh.y"
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

  case 363:
#line 4496 "Gmsh.y"
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

  case 364:
#line 4540 "Gmsh.y"
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

  case 365:
#line 4579 "Gmsh.y"
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

  case 366:
#line 4604 "Gmsh.y"
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

  case 367:
#line 4617 "Gmsh.y"
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

  case 368:
#line 4628 "Gmsh.y"
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

  case 369:
#line 4645 "Gmsh.y"
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

  case 370:
#line 4662 "Gmsh.y"
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

  case 371:
#line 4692 "Gmsh.y"
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

  case 372:
#line 4718 "Gmsh.y"
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

  case 373:
#line 4745 "Gmsh.y"
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

  case 374:
#line 4777 "Gmsh.y"
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

  case 375:
#line 4804 "Gmsh.y"
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

  case 376:
#line 4830 "Gmsh.y"
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

  case 377:
#line 4856 "Gmsh.y"
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

  case 378:
#line 4882 "Gmsh.y"
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

  case 379:
#line 4908 "Gmsh.y"
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

  case 380:
#line 4929 "Gmsh.y"
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

  case 381:
#line 4940 "Gmsh.y"
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

  case 382:
#line 4988 "Gmsh.y"
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

  case 383:
#line 5042 "Gmsh.y"
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

  case 384:
#line 5057 "Gmsh.y"
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

  case 385:
#line 5069 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 386:
#line 5080 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 387:
#line 5087 "Gmsh.y"
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

  case 388:
#line 5102 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 389:
#line 5115 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 390:
#line 5116 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 391:
#line 5117 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 392:
#line 5122 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 393:
#line 5128 "Gmsh.y"
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

  case 394:
#line 5140 "Gmsh.y"
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

  case 395:
#line 5158 "Gmsh.y"
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

  case 396:
#line 5185 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 397:
#line 5186 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 398:
#line 5187 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 399:
#line 5188 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 400:
#line 5189 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 401:
#line 5190 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 402:
#line 5191 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5192 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5194 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 405:
#line 5200 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 406:
#line 5201 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 407:
#line 5202 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 408:
#line 5203 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 409:
#line 5204 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 410:
#line 5205 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5206 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5207 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5208 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5209 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5210 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5211 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5212 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 418:
#line 5213 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 419:
#line 5214 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 420:
#line 5215 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5216 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5217 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 423:
#line 5218 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5219 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 425:
#line 5220 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5221 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 427:
#line 5222 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5223 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 429:
#line 5224 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5225 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 431:
#line 5226 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5227 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5228 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5229 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5230 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 436:
#line 5231 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 437:
#line 5232 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 438:
#line 5233 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 439:
#line 5234 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 440:
#line 5235 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5236 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 442:
#line 5237 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 443:
#line 5238 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5239 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5248 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 446:
#line 5249 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 447:
#line 5250 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 448:
#line 5251 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 449:
#line 5252 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 450:
#line 5253 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 451:
#line 5254 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 452:
#line 5255 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 453:
#line 5256 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 454:
#line 5257 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 455:
#line 5258 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 456:
#line 5263 "Gmsh.y"
    { init_options(); ;}
    break;

  case 457:
#line 5265 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 458:
#line 5271 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 459:
#line 5275 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 460:
#line 5280 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 461:
#line 5285 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 462:
#line 5290 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 463:
#line 5295 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 464:
#line 5299 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 465:
#line 5303 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 466:
#line 5307 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 467:
#line 5311 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 468:
#line 5315 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 469:
#line 5319 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 470:
#line 5323 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 471:
#line 5329 "Gmsh.y"
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

  case 472:
#line 5344 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 473:
#line 5348 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 474:
#line 5354 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 475:
#line 5359 "Gmsh.y"
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

  case 476:
#line 5378 "Gmsh.y"
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

  case 477:
#line 5398 "Gmsh.y"
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

  case 478:
#line 5419 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 479:
#line 5423 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 480:
#line 5427 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 481:
#line 5431 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 482:
#line 5435 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 483:
#line 5439 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 484:
#line 5443 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 485:
#line 5448 "Gmsh.y"
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

  case 486:
#line 5458 "Gmsh.y"
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

  case 487:
#line 5468 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 488:
#line 5473 "Gmsh.y"
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

  case 489:
#line 5484 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 490:
#line 5493 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 491:
#line 5498 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 492:
#line 5503 "Gmsh.y"
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

  case 493:
#line 5530 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 494:
#line 5532 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 495:
#line 5537 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 496:
#line 5539 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 497:
#line 5544 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 498:
#line 5551 "Gmsh.y"
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

  case 499:
#line 5567 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 500:
#line 5569 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 501:
#line 5574 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 502:
#line 5576 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 503:
#line 5581 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 504:
#line 5583 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 505:
#line 5588 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 506:
#line 5592 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 507:
#line 5596 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 508:
#line 5600 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 509:
#line 5604 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 510:
#line 5611 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 511:
#line 5615 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 512:
#line 5619 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 513:
#line 5623 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 514:
#line 5630 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 515:
#line 5635 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 516:
#line 5642 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 517:
#line 5647 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 518:
#line 5651 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 519:
#line 5656 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 520:
#line 5660 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 521:
#line 5668 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 522:
#line 5679 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 523:
#line 5683 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 524:
#line 5687 "Gmsh.y"
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

  case 525:
#line 5701 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 526:
#line 5709 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 527:
#line 5717 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 528:
#line 5724 "Gmsh.y"
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

  case 529:
#line 5734 "Gmsh.y"
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

  case 530:
#line 5757 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 531:
#line 5762 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 532:
#line 5768 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 533:
#line 5773 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 534:
#line 5779 "Gmsh.y"
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

  case 535:
#line 5790 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 536:
#line 5796 "Gmsh.y"
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

  case 537:
#line 5810 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 538:
#line 5816 "Gmsh.y"
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

  case 539:
#line 5828 "Gmsh.y"
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

  case 540:
#line 5842 "Gmsh.y"
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

  case 541:
#line 5852 "Gmsh.y"
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

  case 542:
#line 5862 "Gmsh.y"
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
#line 5872 "Gmsh.y"
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

  case 544:
#line 5884 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 545:
#line 5888 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 546:
#line 5893 "Gmsh.y"
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

  case 547:
#line 5905 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 548:
#line 5909 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 549:
#line 5913 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 550:
#line 5917 "Gmsh.y"
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

  case 551:
#line 5935 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 552:
#line 5943 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 553:
#line 5951 "Gmsh.y"
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

  case 554:
#line 5980 "Gmsh.y"
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

  case 555:
#line 5990 "Gmsh.y"
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

  case 556:
#line 6006 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 557:
#line 6017 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 558:
#line 6022 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 559:
#line 6026 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 560:
#line 6030 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 561:
#line 6042 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 562:
#line 6046 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 563:
#line 6058 "Gmsh.y"
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

  case 564:
#line 6075 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 565:
#line 6085 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 566:
#line 6089 "Gmsh.y"
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

  case 567:
#line 6104 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 568:
#line 6109 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 569:
#line 6116 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 570:
#line 6120 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 571:
#line 6125 "Gmsh.y"
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

  case 572:
#line 6139 "Gmsh.y"
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

  case 573:
#line 6153 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 574:
#line 6157 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 575:
#line 6161 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 576:
#line 6165 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 577:
#line 6169 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 578:
#line 6177 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 579:
#line 6183 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 580:
#line 6192 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 581:
#line 6196 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 582:
#line 6200 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 583:
#line 6208 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 584:
#line 6214 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 585:
#line 6220 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 586:
#line 6224 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 6231 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 588:
#line 6239 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 589:
#line 6246 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 590:
#line 6255 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 591:
#line 6259 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 592:
#line 6263 "Gmsh.y"
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

  case 593:
#line 6278 "Gmsh.y"
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

  case 594:
#line 6292 "Gmsh.y"
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

  case 595:
#line 6306 "Gmsh.y"
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

  case 596:
#line 6318 "Gmsh.y"
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

  case 597:
#line 6334 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 598:
#line 6343 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 599:
#line 6352 "Gmsh.y"
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

  case 600:
#line 6362 "Gmsh.y"
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

  case 601:
#line 6373 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 602:
#line 6381 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 603:
#line 6389 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 604:
#line 6393 "Gmsh.y"
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

  case 605:
#line 6412 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 606:
#line 6419 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 607:
#line 6425 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 608:
#line 6431 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6438 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 610:
#line 6445 "Gmsh.y"
    { init_options(); ;}
    break;

  case 611:
#line 6447 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 612:
#line 6455 "Gmsh.y"
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

  case 613:
#line 6479 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 614:
#line 6481 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 615:
#line 6487 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 616:
#line 6492 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 617:
#line 6494 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 618:
#line 6499 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 619:
#line 6504 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 620:
#line 6509 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 621:
#line 6511 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 622:
#line 6515 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 623:
#line 6527 "Gmsh.y"
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

  case 624:
#line 6541 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 625:
#line 6545 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 626:
#line 6552 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 627:
#line 6560 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 628:
#line 6568 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 629:
#line 6579 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 630:
#line 6581 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 631:
#line 6584 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14719 "Gmsh.tab.cpp"
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


#line 6587 "Gmsh.y"


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

