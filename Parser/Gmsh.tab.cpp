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
#define YYLAST   17545

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2242

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
     873,   882,   892,   896,   901,   912,   920,   928,   936,   944,
     952,   960,   968,   976,   984,   992,  1002,  1010,  1018,  1027,
    1036,  1049,  1050,  1060,  1062,  1064,  1066,  1068,  1073,  1075,
    1077,  1079,  1084,  1086,  1088,  1093,  1095,  1097,  1099,  1104,
    1110,  1122,  1128,  1138,  1148,  1156,  1161,  1171,  1182,  1192,
    1194,  1196,  1197,  1200,  1207,  1215,  1223,  1230,  1238,  1247,
    1258,  1273,  1290,  1303,  1318,  1333,  1348,  1363,  1372,  1381,
    1388,  1393,  1399,  1405,  1412,  1419,  1423,  1428,  1432,  1438,
    1445,  1451,  1456,  1460,  1465,  1469,  1474,  1480,  1485,  1491,
    1495,  1501,  1509,  1517,  1521,  1529,  1533,  1536,  1539,  1542,
    1545,  1548,  1564,  1567,  1570,  1573,  1583,  1595,  1598,  1601,
    1604,  1607,  1610,  1627,  1639,  1646,  1655,  1664,  1675,  1677,
    1680,  1683,  1685,  1689,  1693,  1698,  1703,  1705,  1707,  1713,
    1725,  1739,  1740,  1748,  1749,  1763,  1764,  1780,  1781,  1788,
    1798,  1801,  1805,  1816,  1830,  1832,  1835,  1841,  1849,  1852,
    1855,  1859,  1862,  1866,  1869,  1873,  1883,  1890,  1892,  1894,
    1896,  1898,  1900,  1901,  1904,  1908,  1912,  1917,  1927,  1932,
    1947,  1948,  1952,  1953,  1955,  1956,  1959,  1960,  1963,  1964,
    1967,  1974,  1982,  1989,  1995,  1999,  2008,  2015,  2024,  2033,
    2039,  2044,  2051,  2063,  2075,  2094,  2113,  2126,  2139,  2152,
    2163,  2168,  2173,  2178,  2183,  2188,  2191,  2195,  2202,  2204,
    2206,  2208,  2211,  2217,  2225,  2236,  2238,  2242,  2245,  2248,
    2251,  2255,  2259,  2263,  2267,  2271,  2275,  2279,  2283,  2287,
    2291,  2295,  2299,  2303,  2307,  2311,  2315,  2319,  2323,  2329,
    2334,  2339,  2344,  2349,  2354,  2359,  2364,  2369,  2374,  2379,
    2386,  2391,  2396,  2401,  2406,  2411,  2416,  2421,  2426,  2433,
    2440,  2447,  2452,  2459,  2466,  2468,  2470,  2472,  2474,  2476,
    2478,  2480,  2482,  2484,  2486,  2488,  2489,  2496,  2498,  2503,
    2510,  2512,  2517,  2522,  2527,  2534,  2540,  2548,  2557,  2568,
    2573,  2578,  2585,  2590,  2594,  2597,  2603,  2609,  2613,  2619,
    2626,  2635,  2642,  2651,  2658,  2663,  2671,  2678,  2685,  2692,
    2697,  2704,  2709,  2710,  2713,  2714,  2717,  2718,  2726,  2728,
    2732,  2734,  2737,  2738,  2742,  2744,  2747,  2750,  2754,  2758,
    2770,  2780,  2788,  2796,  2798,  2802,  2804,  2806,  2809,  2813,
    2818,  2824,  2826,  2830,  2832,  2835,  2839,  2843,  2849,  2854,
    2859,  2862,  2867,  2870,  2874,  2878,  2883,  2889,  2895,  2901,
    2903,  2905,  2907,  2911,  2917,  2925,  2930,  2935,  2940,  2947,
    2954,  2963,  2972,  2977,  2992,  2997,  3002,  3004,  3006,  3010,
    3014,  3024,  3032,  3034,  3040,  3044,  3051,  3053,  3057,  3059,
    3061,  3066,  3071,  3075,  3081,  3088,  3097,  3104,  3109,  3115,
    3117,  3122,  3124,  3126,  3128,  3130,  3135,  3142,  3147,  3154,
    3160,  3168,  3173,  3178,  3183,  3192,  3197,  3202,  3207,  3212,
    3221,  3230,  3237,  3242,  3249,  3254,  3256,  3258,  3263,  3268,
    3269,  3276,  3281,  3284,  3289,  3294,  3296,  3298,  3302,  3304,
    3306,  3310,  3314,  3318,  3324,  3332,  3338,  3344,  3353,  3355,
    3357
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
       6,    -1,    13,    14,     6,    -1,    14,   107,   348,     6,
      -1,   123,   107,   255,   348,   256,     7,     5,     5,     5,
       6,    -1,   105,   255,   348,   256,     7,   361,     6,    -1,
     106,   255,   348,   256,     7,   361,     6,    -1,   110,   255,
     348,   256,     7,   361,     6,    -1,   113,   255,   348,   256,
       7,   361,     6,    -1,   117,   255,   348,   256,     7,   361,
       6,    -1,   118,   255,   348,   256,     7,   361,     6,    -1,
     111,   255,   348,   256,     7,   361,     6,    -1,   112,   255,
     348,   256,     7,   361,     6,    -1,   132,   255,   348,   256,
       7,   361,     6,    -1,   159,   255,   348,   256,     7,   361,
       6,    -1,   107,     4,   255,   348,   256,     7,   361,   310,
       6,    -1,   109,   255,   348,   256,     7,   361,     6,    -1,
     131,   255,   348,   256,     7,   361,     6,    -1,   136,   131,
     255,   348,   256,     7,   361,     6,    -1,   139,   314,   255,
     348,   256,     7,   361,     6,    -1,   139,   314,   255,   348,
     256,     7,   361,     4,   259,   360,   260,     6,    -1,    -1,
     138,   313,   312,   255,   307,   256,   287,   361,     6,    -1,
     101,    -1,   104,    -1,   107,    -1,   109,    -1,   120,   259,
     348,   260,    -1,   104,    -1,   107,    -1,   109,    -1,   120,
     259,   348,   260,    -1,   104,    -1,   107,    -1,   120,   259,
     348,   260,    -1,   101,    -1,   104,    -1,   107,    -1,   120,
     259,   348,   260,    -1,   148,   358,   259,   318,   260,    -1,
     147,   259,   358,   264,   358,   264,   348,   260,   259,   318,
     260,    -1,   149,   358,   259,   318,   260,    -1,   150,   259,
     358,   264,   348,   260,   259,   318,   260,    -1,   150,   259,
     358,   264,   358,   260,   259,   318,   260,    -1,   153,   259,
     364,   260,   259,   318,   260,    -1,     4,   259,   318,   260,
      -1,   165,   104,   259,   364,   260,   107,   259,   348,   260,
      -1,   162,   104,   259,   348,   260,   101,   259,   364,   260,
       6,    -1,   162,   104,   255,   348,   256,   259,   364,   260,
       6,    -1,   319,    -1,   317,    -1,    -1,   319,   311,    -1,
     319,   313,   259,   364,   260,     6,    -1,   319,   138,   313,
     259,   364,   260,     6,    -1,   319,   141,   313,   259,   364,
     260,     6,    -1,   319,   313,   259,     8,   260,     6,    -1,
     319,   138,   313,   259,     8,   260,     6,    -1,   152,   135,
     255,   348,   256,     7,   361,     6,    -1,   152,   101,   255,
     348,   256,     7,   259,   360,   260,     6,    -1,   152,   135,
     255,   348,   256,     7,   259,   358,   264,   358,   264,   364,
     260,     6,    -1,   152,   135,   255,   348,   256,     7,   259,
     358,   264,   358,   264,   358,   264,   364,   260,     6,    -1,
     152,   105,   255,   348,   256,     7,   259,   358,   264,   364,
     260,     6,    -1,   152,   111,   255,   348,   256,     7,   259,
     358,   264,   358,   264,   364,   260,     6,    -1,   152,   112,
     255,   348,   256,     7,   259,   358,   264,   358,   264,   364,
     260,     6,    -1,   152,   114,   255,   348,   256,     7,   259,
     358,   264,   358,   264,   364,   260,     6,    -1,   152,   115,
     255,   348,   256,     7,   259,   358,   264,   358,   264,   364,
     260,     6,    -1,   152,     4,   255,   348,   256,     7,   361,
       6,    -1,   152,     4,   255,   348,   256,     7,     5,     6,
      -1,   152,     4,   259,   348,   260,     6,    -1,   163,   259,
     319,   260,    -1,   145,   163,   259,   319,   260,    -1,   163,
       4,   259,   319,   260,    -1,   163,   200,   257,   348,   258,
       6,    -1,   163,     4,   257,   348,   258,     6,    -1,   163,
     378,     6,    -1,   163,     4,     4,     6,    -1,   163,    93,
       6,    -1,   189,   365,   259,   319,   260,    -1,   145,   189,
     365,   259,   319,   260,    -1,   225,   348,   259,   319,   260,
      -1,   205,   259,     8,   260,    -1,   205,     5,     6,    -1,
     206,   259,     8,   260,    -1,   206,     5,     6,    -1,   205,
     259,   319,   260,    -1,   145,   205,   259,   319,   260,    -1,
     206,   259,   319,   260,    -1,   145,   206,   259,   319,   260,
      -1,   378,   369,     6,    -1,    79,   255,   375,   256,     6,
      -1,   378,   378,   257,   348,   258,   368,     6,    -1,   378,
     378,   378,   257,   348,   258,     6,    -1,   378,   348,     6,
      -1,   143,   255,     4,   256,   261,     4,     6,    -1,   183,
       4,     6,    -1,   198,     6,    -1,   199,     6,    -1,    74,
       6,    -1,    75,     6,    -1,    67,     6,    -1,    67,   259,
     348,   264,   348,   264,   348,   264,   348,   264,   348,   264,
     348,   260,     6,    -1,    68,     6,    -1,    69,     6,    -1,
      84,     6,    -1,    86,   259,   348,   264,   348,   264,   348,
     260,     6,    -1,    86,   259,   348,   264,   348,   264,   348,
     264,   348,   260,     6,    -1,    85,     6,    -1,    87,     6,
      -1,    88,     6,    -1,   125,     6,    -1,   126,     6,    -1,
     127,   259,   364,   260,   259,   364,   260,   259,   360,   260,
     259,   348,   264,   348,   260,     6,    -1,   203,   255,   259,
     364,   260,   264,   369,   264,   369,   256,     6,    -1,   191,
     255,   348,     8,   348,   256,    -1,   191,   255,   348,     8,
     348,     8,   348,   256,    -1,   191,     4,   192,   259,   348,
       8,   348,   260,    -1,   191,     4,   192,   259,   348,     8,
     348,     8,   348,   260,    -1,   193,    -1,   204,     4,    -1,
     204,   369,    -1,   201,    -1,   202,   378,     6,    -1,   202,
     369,     6,    -1,   194,   255,   348,   256,    -1,   195,   255,
     348,   256,    -1,   196,    -1,   197,    -1,   151,   358,   259,
     319,   260,    -1,   151,   259,   358,   264,   358,   264,   348,
     260,   259,   319,   260,    -1,   151,   259,   358,   264,   358,
     264,   358,   264,   348,   260,   259,   319,   260,    -1,    -1,
     151,   358,   259,   319,   329,   333,   260,    -1,    -1,   151,
     259,   358,   264,   358,   264,   348,   260,   259,   319,   330,
     333,   260,    -1,    -1,   151,   259,   358,   264,   358,   264,
     358,   264,   348,   260,   259,   319,   331,   333,   260,    -1,
      -1,   151,   259,   319,   332,   333,   260,    -1,   151,   259,
     319,   260,   142,   119,   259,   348,   260,    -1,   131,   361,
      -1,   136,   131,   361,    -1,   133,   259,   364,   260,   259,
     364,   260,   259,   364,   260,    -1,   134,   259,   364,   260,
     259,   364,   260,   259,   364,   260,   259,   364,   260,    -1,
     334,    -1,   333,   334,    -1,   169,   259,   348,   260,     6,
      -1,   169,   259,   361,   264,   361,   260,     6,    -1,   170,
       6,    -1,   160,     6,    -1,   160,   348,     6,    -1,   175,
       6,    -1,   175,   177,     6,    -1,   176,     6,    -1,   176,
     177,     6,    -1,   171,   255,   348,   256,     7,   361,   142,
     348,     6,    -1,   142,     4,   257,   348,   258,     6,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
      -1,   163,     6,    -1,   145,   163,     6,    -1,   163,   348,
       6,    -1,   145,   163,   348,     6,    -1,   335,   259,   319,
     336,   260,   259,   319,   336,   260,    -1,   116,   255,   368,
     256,    -1,   335,   255,   348,   256,     7,   259,   319,   336,
     260,   259,   319,   336,   260,     6,    -1,    -1,   142,     4,
     348,    -1,    -1,     4,    -1,    -1,     7,   361,    -1,    -1,
       7,   348,    -1,    -1,   153,   361,    -1,   121,   122,   362,
       7,   348,     6,    -1,   137,   104,   362,     7,   348,   339,
       6,    -1,   137,   107,   362,   341,   340,     6,    -1,   137,
     109,   362,   341,     6,    -1,   178,   362,     6,    -1,    99,
     313,   255,   348,   264,   348,   256,     6,    -1,   213,   313,
     255,   348,   256,     6,    -1,   166,   107,   259,   364,   260,
       7,   348,     6,    -1,   168,   107,   259,   364,   260,     7,
     348,     6,    -1,   160,   107,   362,   342,     6,    -1,   160,
     109,   362,     6,    -1,   161,   107,   362,     7,   348,     6,
      -1,   140,   104,   259,   364,   260,     7,   259,   364,   260,
     343,     6,    -1,   140,   107,   259,   364,   260,     7,   259,
     364,   260,   343,     6,    -1,   140,   104,   259,   364,   260,
       7,   259,   364,   260,   147,   259,   358,   264,   358,   264,
     348,   260,     6,    -1,   140,   107,   259,   364,   260,     7,
     259,   364,   260,   147,   259,   358,   264,   358,   264,   348,
     260,     6,    -1,   140,   104,   259,   364,   260,     7,   259,
     364,   260,   148,   358,     6,    -1,   140,   107,   259,   364,
     260,     7,   259,   364,   260,   148,   358,     6,    -1,   140,
     107,   348,   259,   364,   260,     7,   348,   259,   364,   260,
       6,    -1,   313,   259,   364,   260,   192,   313,   259,   348,
     260,     6,    -1,   167,   315,   362,     6,    -1,   128,   316,
     362,     6,    -1,   129,   109,   361,     6,    -1,   144,   104,
     361,     6,    -1,   139,   314,   361,     6,    -1,   164,     6,
      -1,   164,     4,     6,    -1,   164,   101,   259,   364,   260,
       6,    -1,   214,    -1,   215,    -1,   216,    -1,   346,     6,
      -1,   346,   259,   361,   260,     6,    -1,   346,   259,   361,
     264,   361,   260,     6,    -1,   346,   255,   361,   256,   259,
     361,   264,   361,   260,     6,    -1,   349,    -1,   255,   348,
     256,    -1,   244,   348,    -1,   243,   348,    -1,   250,   348,
      -1,   348,   244,   348,    -1,   348,   243,   348,    -1,   348,
     245,   348,    -1,   348,   246,   348,    -1,   348,   248,   348,
      -1,   348,   249,   348,    -1,   348,   247,   348,    -1,   348,
     254,   348,    -1,   348,   237,   348,    -1,   348,   238,   348,
      -1,   348,   242,   348,    -1,   348,   241,   348,    -1,   348,
     236,   348,    -1,   348,   235,   348,    -1,   348,   234,   348,
      -1,   348,   233,   348,    -1,   348,   239,   348,    -1,   348,
     240,   348,    -1,   348,   232,   348,     8,   348,    -1,    16,
     289,   348,   290,    -1,    17,   289,   348,   290,    -1,    18,
     289,   348,   290,    -1,    19,   289,   348,   290,    -1,    20,
     289,   348,   290,    -1,    21,   289,   348,   290,    -1,    22,
     289,   348,   290,    -1,    23,   289,   348,   290,    -1,    24,
     289,   348,   290,    -1,    26,   289,   348,   290,    -1,    27,
     289,   348,   264,   348,   290,    -1,    28,   289,   348,   290,
      -1,    29,   289,   348,   290,    -1,    30,   289,   348,   290,
      -1,    31,   289,   348,   290,    -1,    32,   289,   348,   290,
      -1,    33,   289,   348,   290,    -1,    34,   289,   348,   290,
      -1,    35,   289,   348,   290,    -1,    38,   289,   348,   264,
     348,   290,    -1,    39,   289,   348,   264,   348,   290,    -1,
      40,   289,   348,   264,   348,   290,    -1,    25,   289,   348,
     290,    -1,    37,   289,   348,   264,   348,   290,    -1,    36,
     289,   348,   264,   348,   290,    -1,     3,    -1,    10,    -1,
      15,    -1,    11,    -1,    12,    -1,   221,    -1,   222,    -1,
     223,    -1,    81,    -1,    82,    -1,    83,    -1,    -1,    92,
     289,   348,   350,   300,   290,    -1,   353,    -1,   211,   289,
     368,   290,    -1,   211,   289,   368,   264,   348,   290,    -1,
     355,    -1,   378,   257,   348,   258,    -1,   378,   255,   348,
     256,    -1,   217,   255,   355,   256,    -1,   217,   255,   355,
     261,   291,   256,    -1,   219,   255,   355,   351,   256,    -1,
     219,   255,   355,   261,   291,   351,   256,    -1,   219,   255,
     355,   289,   348,   290,   351,   256,    -1,   219,   255,   355,
     261,   291,   289,   348,   290,   351,   256,    -1,   218,   255,
     369,   256,    -1,   262,   378,   289,   290,    -1,   262,   355,
     261,   291,   289,   290,    -1,    95,   289,   378,   290,    -1,
      95,   289,   290,    -1,   378,   288,    -1,   378,   257,   348,
     258,   288,    -1,   378,   255,   348,   256,   288,    -1,   378,
     261,   291,    -1,   378,     9,   378,   261,   291,    -1,   378,
     261,   291,   255,   348,   256,    -1,   378,     9,   378,   261,
     291,   255,   348,   256,    -1,   378,   261,   291,   257,   348,
     258,    -1,   378,     9,   378,   261,   291,   257,   348,   258,
      -1,   378,   257,   348,   258,   261,   291,    -1,   378,   261,
     291,   288,    -1,   378,   257,   348,   258,   261,   291,   288,
      -1,   207,   255,   368,   264,   348,   256,    -1,    59,   255,
     361,   264,   361,   256,    -1,    60,   289,   368,   264,   368,
     290,    -1,    58,   289,   368,   290,    -1,    61,   289,   368,
     264,   368,   290,    -1,    66,   255,   375,   256,    -1,    -1,
     264,   348,    -1,    -1,   264,   368,    -1,    -1,    93,   355,
     357,   354,   257,   301,   258,    -1,   378,    -1,   378,     9,
     378,    -1,    96,    -1,    96,   348,    -1,    -1,   255,   356,
     256,    -1,   359,    -1,   244,   358,    -1,   243,   358,    -1,
     358,   244,   358,    -1,   358,   243,   358,    -1,   259,   348,
     264,   348,   264,   348,   264,   348,   264,   348,   260,    -1,
     259,   348,   264,   348,   264,   348,   264,   348,   260,    -1,
     259,   348,   264,   348,   264,   348,   260,    -1,   255,   348,
     264,   348,   264,   348,   256,    -1,   361,    -1,   360,   264,
     361,    -1,   348,    -1,   363,    -1,   259,   260,    -1,   259,
     364,   260,    -1,   244,   259,   364,   260,    -1,   348,   245,
     259,   364,   260,    -1,   361,    -1,   259,     8,   260,    -1,
       5,    -1,   244,   363,    -1,   348,   245,   363,    -1,   348,
       8,   348,    -1,   348,     8,   348,     8,   348,    -1,   101,
     259,   348,   260,    -1,   101,   259,     8,   260,    -1,   101,
       5,    -1,   314,   259,     8,   260,    -1,   314,     5,    -1,
     138,   313,   362,    -1,   141,   313,   361,    -1,   313,   192,
      67,   361,    -1,    67,   313,   259,   364,   260,    -1,    76,
     314,   259,   348,   260,    -1,    77,   314,   259,   348,   260,
      -1,   317,    -1,   328,    -1,   337,    -1,   378,   289,   290,
      -1,   378,   261,   291,   289,   290,    -1,   378,     9,   378,
     261,   291,   289,   290,    -1,    41,   257,   378,   258,    -1,
      41,   257,   363,   258,    -1,    41,   255,   363,   256,    -1,
      41,   289,   259,   364,   260,   290,    -1,   378,   289,   259,
     364,   260,   290,    -1,    42,   289,   348,   264,   348,   264,
     348,   290,    -1,    43,   289,   348,   264,   348,   264,   348,
     290,    -1,    44,   289,   368,   290,    -1,    45,   289,   348,
     264,   348,   264,   348,   264,   348,   264,   348,   264,   348,
     290,    -1,   212,   289,   363,   290,    -1,    32,   289,   363,
     290,    -1,   348,    -1,   363,    -1,   364,   264,   348,    -1,
     364,   264,   363,    -1,   259,   348,   264,   348,   264,   348,
     264,   348,   260,    -1,   259,   348,   264,   348,   264,   348,
     260,    -1,   378,    -1,     4,   261,   189,   261,     4,    -1,
     259,   367,   260,    -1,   378,   257,   348,   258,   261,   190,
      -1,   365,    -1,   367,   264,   365,    -1,   369,    -1,   378,
      -1,   378,   257,   348,   258,    -1,   378,   255,   348,   256,
      -1,   378,   261,   291,    -1,   378,     9,   378,   261,   291,
      -1,   378,   261,   291,   255,   348,   256,    -1,   378,     9,
     378,   261,   291,   255,   348,   256,    -1,   378,   257,   348,
     258,   261,     4,    -1,   313,   259,   348,   260,    -1,   138,
     313,   259,   348,   260,    -1,     5,    -1,   226,   257,   378,
     258,    -1,    70,    -1,   224,    -1,    78,    -1,    80,    -1,
     209,   255,   368,   256,    -1,   208,   255,   368,   264,   368,
     256,    -1,   210,   289,   368,   290,    -1,   210,   289,   368,
     264,   368,   290,    -1,   220,   255,   355,   352,   256,    -1,
     220,   255,   355,   261,   291,   352,   256,    -1,    51,   289,
     375,   290,    -1,    52,   255,   368,   256,    -1,    53,   255,
     368,   256,    -1,    54,   255,   368,   264,   368,   264,   368,
     256,    -1,    49,   289,   375,   290,    -1,    63,   289,   368,
     290,    -1,    64,   289,   368,   290,    -1,    65,   289,   368,
     290,    -1,    62,   289,   348,   264,   368,   264,   368,   290,
      -1,    57,   289,   368,   264,   348,   264,   348,   290,    -1,
      57,   289,   368,   264,   348,   290,    -1,    50,   289,   368,
     290,    -1,    50,   289,   368,   264,   364,   290,    -1,    71,
     289,   368,   290,    -1,    72,    -1,    73,    -1,    56,   289,
     368,   290,    -1,    55,   289,   368,   290,    -1,    -1,    97,
     289,   369,   370,   304,   290,    -1,    94,   289,   371,   290,
      -1,   262,   348,    -1,   378,     9,   262,   348,    -1,    49,
     289,   374,   290,    -1,   375,    -1,   374,    -1,   259,   375,
     260,    -1,   368,    -1,   376,    -1,   375,   264,   368,    -1,
     375,   264,   376,    -1,   378,   255,   256,    -1,   378,   261,
     291,   255,   256,    -1,   378,     9,   378,   261,   291,   255,
     256,    -1,     4,   263,   259,   348,   260,    -1,   377,   263,
     259,   348,   260,    -1,   227,   257,   368,   258,   263,   259,
     348,   260,    -1,     4,    -1,   377,    -1,   227,   257,   368,
     258,    -1
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
    1911,  1961,  1979,  1985,  1991,  1998,  2029,  2044,  2066,  2089,
    2112,  2135,  2159,  2183,  2207,  2233,  2250,  2266,  2284,  2302,
    2314,  2328,  2327,  2357,  2359,  2361,  2363,  2365,  2373,  2375,
    2377,  2379,  2387,  2389,  2391,  2399,  2401,  2403,  2405,  2415,
    2431,  2447,  2463,  2479,  2495,  2512,  2549,  2570,  2591,  2617,
    2618,  2623,  2626,  2630,  2647,  2667,  2687,  2706,  2733,  2752,
    2773,  2788,  2804,  2822,  2873,  2894,  2916,  2939,  3044,  3060,
    3095,  3117,  3139,  3151,  3157,  3172,  3203,  3215,  3224,  3231,
    3243,  3263,  3267,  3272,  3276,  3281,  3288,  3295,  3302,  3314,
    3387,  3405,  3430,  3445,  3478,  3490,  3522,  3526,  3531,  3538,
    3543,  3553,  3558,  3564,  3572,  3580,  3584,  3588,  3592,  3596,
    3600,  3612,  3621,  3685,  3701,  3718,  3735,  3757,  3779,  3814,
    3822,  3830,  3836,  3843,  3850,  3870,  3896,  3908,  3919,  3937,
    3955,  3974,  3973,  3998,  3997,  4024,  4023,  4048,  4047,  4070,
    4086,  4103,  4120,  4143,  4171,  4174,  4180,  4192,  4212,  4216,
    4220,  4224,  4228,  4232,  4236,  4240,  4249,  4262,  4263,  4264,
    4265,  4266,  4270,  4271,  4272,  4273,  4274,  4277,  4301,  4320,
    4343,  4346,  4362,  4365,  4382,  4385,  4391,  4394,  4401,  4404,
    4411,  4433,  4474,  4518,  4557,  4582,  4595,  4606,  4623,  4640,
    4670,  4696,  4722,  4754,  4781,  4807,  4833,  4859,  4885,  4907,
    4918,  4966,  5020,  5035,  5047,  5058,  5065,  5080,  5094,  5095,
    5096,  5100,  5106,  5118,  5136,  5164,  5165,  5166,  5167,  5168,
    5169,  5170,  5171,  5172,  5179,  5180,  5181,  5182,  5183,  5184,
    5185,  5186,  5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,
    5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,
    5205,  5206,  5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,
    5215,  5216,  5217,  5218,  5227,  5228,  5229,  5230,  5231,  5232,
    5233,  5234,  5235,  5236,  5237,  5242,  5241,  5249,  5253,  5258,
    5263,  5267,  5272,  5277,  5281,  5285,  5289,  5293,  5297,  5301,
    5307,  5322,  5326,  5332,  5337,  5356,  5376,  5397,  5401,  5405,
    5409,  5413,  5417,  5421,  5426,  5436,  5446,  5451,  5462,  5471,
    5476,  5481,  5509,  5510,  5516,  5517,  5523,  5522,  5545,  5547,
    5552,  5554,  5560,  5561,  5566,  5570,  5574,  5578,  5582,  5589,
    5593,  5597,  5601,  5608,  5613,  5620,  5625,  5629,  5634,  5638,
    5646,  5657,  5661,  5665,  5679,  5687,  5695,  5702,  5712,  5735,
    5740,  5746,  5751,  5757,  5768,  5774,  5788,  5794,  5806,  5820,
    5830,  5840,  5850,  5862,  5866,  5871,  5883,  5887,  5891,  5895,
    5913,  5921,  5929,  5958,  5968,  5984,  5995,  6000,  6004,  6008,
    6020,  6024,  6036,  6053,  6063,  6067,  6082,  6087,  6094,  6098,
    6103,  6117,  6131,  6135,  6139,  6143,  6147,  6155,  6161,  6170,
    6174,  6178,  6186,  6192,  6198,  6202,  6209,  6217,  6224,  6233,
    6237,  6241,  6256,  6270,  6284,  6296,  6312,  6321,  6330,  6340,
    6351,  6359,  6367,  6371,  6390,  6397,  6403,  6409,  6416,  6424,
    6423,  6433,  6457,  6459,  6465,  6470,  6472,  6477,  6482,  6487,
    6489,  6493,  6505,  6519,  6523,  6530,  6538,  6546,  6557,  6559,
    6562
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
     311,   312,   311,   313,   313,   313,   313,   313,   314,   314,
     314,   314,   315,   315,   315,   316,   316,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   322,   322,
     323,   324,   324,   324,   324,   324,   324,   324,   324,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   326,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   328,   328,
     328,   329,   328,   330,   328,   331,   328,   332,   328,   328,
     328,   328,   328,   328,   333,   333,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   335,   335,   335,
     335,   335,   336,   336,   336,   336,   336,   337,   337,   338,
     339,   339,   340,   340,   341,   341,   342,   342,   343,   343,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   345,   345,   345,   346,   346,
     346,   347,   347,   347,   347,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   350,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   351,   351,   352,   352,   354,   353,   355,   355,
     356,   356,   357,   357,   358,   358,   358,   358,   358,   359,
     359,   359,   359,   360,   360,   361,   361,   361,   361,   361,
     361,   362,   362,   362,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   364,   364,   364,   364,
     365,   365,   365,   365,   366,   366,   367,   367,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   370,
     369,   369,   371,   371,   372,   373,   373,   374,   375,   375,
     375,   375,   376,   376,   376,   377,   377,   377,   378,   378,
     378
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
       8,     9,     3,     4,    10,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     9,     7,     7,     8,     8,
      12,     0,     9,     1,     1,     1,     1,     4,     1,     1,
       1,     4,     1,     1,     4,     1,     1,     1,     4,     5,
      11,     5,     9,     9,     7,     4,     9,    10,     9,     1,
       1,     0,     2,     6,     7,     7,     6,     7,     8,    10,
      14,    16,    12,    14,    14,    14,    14,     8,     8,     6,
       4,     5,     5,     6,     6,     3,     4,     3,     5,     6,
       5,     4,     3,     4,     3,     4,     5,     4,     5,     3,
       5,     7,     7,     3,     7,     3,     2,     2,     2,     2,
       2,    15,     2,     2,     2,     9,    11,     2,     2,     2,
       2,     2,    16,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       2,     3,    10,    13,     1,     2,     5,     7,     2,     2,
       3,     2,     3,     2,     3,     9,     6,     1,     1,     1,
       1,     1,     0,     2,     3,     3,     4,     9,     4,    14,
       0,     3,     0,     1,     0,     2,     0,     2,     0,     2,
       6,     7,     6,     5,     3,     8,     6,     8,     8,     5,
       4,     6,    11,    11,    18,    18,    12,    12,    12,    10,
       4,     4,     4,     4,     4,     2,     3,     6,     1,     1,
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
       2,     4,     2,     3,     3,     4,     5,     5,     5,     1,
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
       0,     0,     0,     2,     3,     1,   628,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,   204,     0,     0,   205,     0,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   337,   338,   339,   340,   341,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,   306,   307,     0,     0,     0,   301,     0,
       0,     0,     0,     0,     0,   388,   389,   390,     0,     0,
       5,     6,     7,     8,    10,     0,    11,    24,    12,    13,
      14,    15,    23,    22,    21,    16,     0,    17,    18,    19,
      20,     0,    25,     0,   629,     0,   231,     0,     0,     0,
       0,     0,     0,   280,     0,   282,   283,   278,   279,     0,
     284,   287,     0,   288,   289,   119,   129,   628,   502,   498,
      73,    74,     0,   203,   204,   205,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   290,   291,     0,   215,   216,   217,     0,     0,     0,
       0,   444,   445,   447,   448,   446,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   452,   453,   454,     0,     0,   203,
     208,   209,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,   450,   451,     0,     0,     0,
       0,     0,     0,     0,     0,   539,   540,     0,   541,   515,
     395,   457,   460,   320,   516,   498,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   208,   209,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
     231,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,     0,     0,   231,
       0,     0,   385,     0,     0,     0,   212,   213,     0,     0,
       0,     0,     0,     0,   523,     0,     0,   521,     0,     0,
       0,     0,     0,   628,     0,     0,   562,     0,     0,     0,
       0,   276,   277,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   581,     0,
     605,   606,   583,   584,     0,     0,     0,     0,     0,     0,
     582,     0,     0,     0,     0,   299,   300,     0,   231,     0,
     231,     0,     0,     0,     0,   498,     0,     0,     0,   231,
     391,     0,     0,    84,     0,    66,     0,     0,    70,    69,
      68,    67,    72,    71,    73,    74,     0,     0,     0,     0,
       0,     0,     0,   568,   498,     0,   230,     0,   229,     0,
     182,     0,     0,   568,   569,     0,     0,     0,   618,     0,
     619,   569,     0,   117,   117,     0,   496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   556,   557,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   530,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   398,     0,   397,   524,   399,
       0,   517,     0,     0,   498,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,   474,     0,     0,     0,     0,     0,     0,     0,
     321,     0,   354,   354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,     0,   231,   231,     0,
     506,   505,     0,     0,     0,     0,   231,   231,     0,     0,
       0,     0,   317,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,     0,     0,
       0,     0,     0,   231,   257,     0,     0,   255,   386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,   275,     0,     0,     0,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   302,     0,   262,     0,     0,
     264,     0,     0,     0,     0,   397,     0,   231,     0,     0,
       0,     0,     0,     0,     0,   342,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,    88,    75,    76,     0,     0,     0,   273,
      40,   269,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,   232,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,     0,     0,   500,
       0,     0,   499,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,   207,     0,     0,     0,     0,
       0,     0,   381,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   455,   473,
       0,     0,     0,     0,   533,   534,     0,     0,     0,     0,
       0,   492,     0,   396,   518,     0,     0,     0,     0,   526,
       0,   415,   414,   413,   412,   408,   409,   416,   417,   411,
     410,   401,   400,     0,   402,   525,   403,   406,   404,   405,
     407,   499,     0,     0,   477,     0,   542,     0,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,     0,     0,
       0,     0,   384,     0,     0,     0,     0,   383,     0,   231,
       0,     0,     0,     0,     0,   508,   507,     0,     0,     0,
       0,     0,     0,     0,   311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   370,     0,
       0,     0,   256,     0,     0,     0,   250,     0,     0,     0,
       0,   380,     0,     0,     0,     0,   396,   522,     0,     0,
       0,     0,     0,     0,     0,     0,   304,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   609,     0,     0,     0,
     494,     0,     0,   261,   265,   263,   267,     0,     0,   402,
       0,   499,   477,   630,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,   396,     0,     0,     0,
      66,     0,     0,    87,     0,    66,    67,     0,     0,     0,
     499,     0,     0,   477,     0,     0,     0,   201,     0,     0,
       0,   625,    28,    26,    27,     0,     0,     0,     0,     0,
     572,    30,     0,    29,     0,     0,   270,   620,   621,     0,
     622,   572,     0,    82,   120,    83,   130,   501,   503,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,   559,   218,     9,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   441,   428,     0,
     430,   431,   432,   433,   434,   555,   435,   436,   437,     0,
       0,     0,     0,     0,   547,   546,   545,     0,     0,     0,
     552,     0,   489,     0,     0,     0,   491,     0,     0,     0,
     134,   472,   529,   528,   211,     0,     0,   458,   554,   463,
       0,   469,     0,     0,     0,     0,   519,     0,     0,   470,
     535,   531,     0,     0,     0,     0,   462,   461,    73,    74,
     484,     0,     0,     0,     0,     0,     0,     0,   396,   350,
     355,   353,     0,   363,     0,   156,   157,     0,   211,     0,
     396,     0,     0,     0,     0,   251,     0,   266,   268,     0,
       0,     0,   219,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   324,     0,   308,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,     0,
     357,   369,     0,     0,     0,     0,   252,     0,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,     0,     0,     0,   595,     0,   602,   591,
     592,   593,     0,   608,   607,     0,     0,   596,   597,   598,
     604,   612,   611,     0,   147,     0,   585,     0,   587,     0,
       0,     0,   580,     0,     0,   260,     0,     0,     0,     0,
       0,     0,     0,   343,     0,     0,     0,   392,     0,   626,
       0,   109,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,   577,
      51,     0,     0,     0,    64,     0,    41,    42,    43,    44,
      45,    46,     0,   462,   461,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   571,   570,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,     0,
       0,     0,   137,   138,     0,     0,     0,     0,   163,   163,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   537,   538,     0,     0,     0,     0,     0,   492,
     493,     0,   465,     0,     0,   527,   418,   520,   478,   476,
       0,   475,     0,     0,   543,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,   259,     0,     0,     0,     0,
       0,     0,     0,   329,     0,     0,   328,     0,   331,     0,
     333,     0,   318,   325,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,     0,     0,
     254,   253,   387,     0,     0,     0,    37,    38,     0,     0,
       0,     0,   563,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   494,   495,
     589,     0,   366,   478,     0,     0,   231,   344,     0,   345,
     231,     0,     0,   578,     0,    94,     0,     0,     0,     0,
      92,     0,   566,     0,   107,     0,    99,   101,     0,     0,
       0,    89,     0,     0,     0,     0,     0,    36,   478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,   573,     0,     0,    34,    33,     0,
     573,   623,     0,     0,   121,   126,     0,     0,     0,   140,
     145,   146,   141,   142,   497,     0,    85,     0,    86,   167,
       0,     0,     0,     0,   168,   185,   186,   165,     0,     0,
       0,   169,   196,   187,   191,   192,   188,   189,   190,   177,
       0,     0,   429,   443,   442,   438,   439,   440,   548,     0,
       0,     0,   487,   488,   490,   135,   456,   486,   459,   464,
       0,     0,   492,   197,   471,    73,    74,     0,   483,   479,
     481,   549,   193,     0,     0,     0,   159,     0,     0,   361,
       0,   158,     0,     0,     0,     0,     0,     0,   274,     0,
       0,     0,     0,   231,   231,     0,     0,   330,   515,     0,
       0,   332,   334,     0,     0,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,   194,     0,     0,
       0,     0,     0,     0,   174,   175,     0,     0,     0,     0,
     110,   114,     0,   603,     0,     0,   601,     0,   613,     0,
       0,   148,   149,   610,   586,   588,     0,     0,     0,     0,
       0,     0,   342,   346,   342,     0,   393,    93,     0,     0,
      66,     0,     0,    91,     0,   564,     0,     0,     0,     0,
       0,     0,   616,   615,     0,     0,     0,     0,     0,   513,
       0,     0,    77,   271,   479,   272,     0,     0,     0,     0,
       0,   236,   233,     0,     0,   576,   574,     0,     0,     0,
       0,   122,   127,     0,     0,     0,   556,   557,   139,   365,
     164,   172,   173,   178,     0,     0,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,   466,     0,     0,     0,
     544,   485,     0,     0,   179,     0,   198,   351,     0,     0,
       0,     0,   199,     0,     0,     0,     0,     0,     0,   512,
     511,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,   367,   368,    39,     0,   561,
       0,     0,   296,   295,     0,     0,     0,     0,     0,     0,
     151,   152,   155,   154,   153,     0,   590,     0,   627,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   567,
       0,     0,     0,    96,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    49,     0,   237,   234,   235,    35,     0,
       0,   624,   285,     0,   134,   147,     0,     0,   144,     0,
       0,     0,   166,   195,     0,     0,     0,     0,     0,   550,
     551,     0,   492,   467,   480,   482,     0,     0,   181,   202,
       0,     0,     0,   358,   358,     0,   115,   116,   231,     0,
     222,   223,   319,     0,   326,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,   228,     0,   226,     0,
       0,     0,     0,   111,   112,   594,   600,   599,   150,     0,
       0,     0,   347,     0,     0,   108,   100,   102,     0,    90,
     617,    97,    98,    52,     0,     0,     0,     0,   514,     0,
       0,   480,   575,     0,     0,     0,     0,   124,   614,     0,
     131,     0,     0,     0,     0,   184,     0,     0,     0,   322,
       0,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   510,     0,   336,     0,     0,   313,     0,
     239,     0,     0,     0,     0,     0,     0,   227,     0,   560,
     297,     0,     0,   379,   231,   394,     0,   565,     0,    48,
       0,     0,     0,    65,    50,     0,   286,   123,   128,   134,
       0,     0,   161,   162,   160,     0,     0,   468,     0,     0,
       0,     0,   359,   372,     0,     0,   373,     0,   220,     0,
     327,     0,   309,     0,   231,     0,     0,     0,     0,     0,
       0,   176,   113,   293,   342,   106,     0,     0,     0,     0,
       0,     0,   132,   133,     0,     0,     0,   200,     0,   376,
       0,   377,   378,   509,     0,     0,   315,   242,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,    62,     0,
       0,   125,     0,     0,   323,     0,     0,   335,   314,   310,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,   244,
     245,   246,     0,   240,   349,    53,     0,    60,     0,   281,
       0,   553,     0,     0,   316,     0,     0,    54,     0,     0,
     292,     0,     0,   241,     0,     0,     0,     0,     0,     0,
      57,    55,     0,    58,     0,   374,   375,     0,     0,    63,
      61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   120,  1085,   121,   122,  1069,  1926,  1932,
    1366,  1582,  2088,  2216,  1367,  2189,  2232,  1368,  2218,  1369,
    1370,  1586,   447,   602,   603,  1154,  1678,   123,   796,   473,
    1944,  2099,  1945,   474,  1815,  1445,  1401,  1402,  1403,  1545,
    1751,  1752,  1224,  1640,  1631,  1825,   773,   614,   283,   284,
     359,   208,   285,   457,   458,   127,   128,   129,   130,   131,
     132,   133,   134,   286,  1258,  2123,  2180,   962,  1254,  1255,
     287,  1048,   288,   138,  1473,  1222,   935,   977,  2057,   139,
     140,   141,   142,   289,   290,  1180,  1195,  1321,   291,   801,
     292,   800,   476,   631,   327,  1788,   367,   368,   294,   572,
     375,  1350,  1573,   468,   463,  1314,  1024,  1621,  1781,  1782,
    1009,   470,   144,   425
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1911
static const yytype_int16 yypact[] =
{
   13266,    41,    99, 13470, -1911, -1911,    67,    71,    75,   -63,
     -34,   -21,    45,   102,   164,   241,   260,    22,   299,   337,
     184,   355,   443,   216,   222,    21,  -126,   647,  -126,   236,
     273,   297,    57,   311,   336,    63,   342,   354,   359,   373,
     389,   390,   432,   450,   459,   468,   245,   606,   357,   737,
     752,   490,   499,   641,   514,  6964,   522,   519,   520,   687,
     -49,   -41,   647,     6,   264,   548,   700,   -89,   561,   429,
     429,   562,   478,   400,   564, -1911, -1911, -1911, -1911, -1911,
     555,    50,   747,   708,    37,    85,   764,   766,    95,   788,
     836,   867,   892,  5952,   899,   653,   665,   674,    13,    65,
   -1911,   679,   680, -1911, -1911,   901,   937,   692, -1911, 13715,
     725, 13751,    23,    26,   647, -1911, -1911, -1911, 12110,   729,
   -1911, -1911, -1911, -1911, -1911,   703, -1911, -1911, -1911, -1911,
   -1911, -1911, -1911, -1911, -1911, -1911,    91, -1911, -1911, -1911,
   -1911,    47, -1911,   945,   722,  5697,   334,   735,   989, 12110,
   13653, 13653, 13653, -1911, 12110, -1911, -1911, -1911, -1911, 13653,
   -1911, -1911, 12110, -1911, -1911, -1911, -1911,   746,   755,  1021,
   -1911, -1911, 13787, -1911, -1911, -1911, -1911,   781,    21, 12110,
   12110, 12110,   782, 12110, 12110, 12110,   789, 12110, 12110, 12110,
   12110, 12110, 12110, 12110, 13653, 12110, 12110, 12110, 12110,  5952,
     790, -1911, -1911,  9737, -1911, -1911, -1911,   804,  5952,  7217,
   13653, -1911, -1911, -1911, -1911, -1911,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,   -54,  -126,  -126,  -126,  -126,  -126,   797,  -126,  -126,
     805,   647,   648,   648, -1911, -1911, -1911,  -126,  -126,    34,
     874,   875,   876,   812,  7217,   941,   647,   647,   818,  -126,
    -126,   819,   820,   821, -1911, -1911, -1911, 12110,  7470, 12110,
   12110,  7723,    21,   886,    38, -1911, -1911,   822, -1911,  3808,
   -1911, -1911, -1911, -1911, -1911,   112, 12110,  9737,  9737,   824,
     825,  7976,  5952,  5952,  5952, -1911, -1911, -1911,   828, -1911,
     826,   829,  8229,   832, 10676,  1088,  7217,   834,    13,   835,
     837,   429,   429,   429, 12110, 12110,  -116, -1911,   -16,   429,
   10762,     9,   331,   840,   842,   843,   844,   847,   848,   849,
    9737, 12110,  5952,  5952,  5952,   387,    17,  1101,   851, -1911,
    1103,  1104, -1911,   854,   858,   869, -1911, -1911,   870,  5952,
     881,   884,   885,   891, -1911, 12110,  6205, -1911,  1137,  1143,
   12110, 12110, 12110,   142, 12110,   897, -1911,   958, 12110, 12110,
   12110, -1911, -1911, 12110, -1911,  -126,  -126,  -126,   896,   902,
     903,  -126,  -126,  -126,  -126,  -126,  -126,  -126, -1911,  -126,
   -1911, -1911, -1911, -1911,  -126,  -126,   904,   906,  -126,   908,
   -1911,   907,  1159,  1160,   909, -1911, -1911,  1161,  1165,  1163,
    1166,   920,  -126, 12110, 15175,   124, 13653,  9737, 12110, -1911,
   -1911,  7217,  7217, -1911,   918, 13787,   647,  1171, -1911, -1911,
   -1911, -1911, -1911, -1911, 12110, 12110,    61,  7217,  1174,   207,
     922,   416,   923,  1178,    31,   926, -1911,   927, 14014, 12110,
   -1911,  2097,  -104, -1911,    53,   -69,    -7,  7151, -1911,   224,
   -1911,    87,  7404,  -178,    -4,  1092, -1911,    21,   928, 12110,
     929,  5449, 15691, 15716, 12110, 15741, 15766, 15791, 12110, 15816,
   15841, 15866, 15891, 15916, 15941, 15966,   934, 15991, 16016, 16041,
    5128,  1188, 12110,  9737,  5031, -1911,   379, 12110,  1190,  1192,
     943, 12110, 12110, 12110, 12110, 12110, 12110, 12110, 12110, 12110,
   12110, 12110, 12110, 12110, 12110, 12110, 12110,  9737, 12110, 12110,
   12110, 12110, 12110, 12110, 12110, 12110,  9737,  9737,   942, 12110,
   12110, 13653, 12110, 13653,  7217, 13653, 13653, 13653,   944,   946,
     947, 12110,    11, -1911, 11015, 12110,  7217,  5952,  7217, 13653,
   13653,  9737,    21, 13787,    21,   950,  9737,   950, -1911,   950,
   16066, -1911,   421,   939,    92,  1140, -1911,  1200, 12110, 12110,
   12110, 12110, 12110, 12110, 12110, 12110, 12110, 12110, 12110, 12110,
   12110, 12110,  8482, 12110, 12110, 12110, 12110, 12110,    21, 12110,
   12110,    51, -1911,   533, 16091,   566,   572, 12110, 12110, 12110,
   -1911,  1202,  1206,  1206,   959, 12110, 12110, 12110, 12110,  1209,
    9737,  9737, 15203,   960,  1211, -1911,   962, -1911, -1911,  -125,
   -1911, -1911,  7657,  7910,   429,   429,   334,   334,  -106, 10762,
   10762, 12110,  4635,   -90, -1911, 12110, 12110, 12110, 12110, 12110,
   12110, 12110, 12110, 12110,   574, 16116,  1212,  1216,  1217, 12110,
   12110,  1219, 12110, -1911, -1911, 12110,  4883, -1911, -1911,  9737,
    9737,  9737, 12110,  1220,  9737, 12110, 12110, 12110, 16141,   963,
   -1911, -1911, 16166, 16191, 16216,  1029,  8163, -1911,   968,  5157,
   16241, 16266, 15286, 13653, 13653, 13653, 13653, 13653, 13653, 13653,
   13653, 13653, 12110, 13653, 13653, 13653, 13653,    19, 13787, 13653,
   13653, 13653,    21,    21, -1911, -1911,  9737, -1911,   969, 12239,
   -1911,   970, 12298, 12110, 12110,   950, 12110, -1911,    21, 12110,
   12110,    51,   973,   577, 16291, 13913,   977,   579, 12110,  1229,
     978,  7217, 16316, 15313, -1911, -1911, -1911, -1911, -1911,   975,
    1231,   162,  1233, -1911, -1911, -1911,  9737,   205, 12110, -1911,
   -1911, -1911,    21, 12110, 12110,    51,   983, -1911,   987,   -48,
     647,     6,   647, -1911,   985, 14305, -1911,     3,  9737,    21,
   12110, 12110,    51,  1239,  9737,  1241,  9737, 12110,  1242, 13653,
      21, 11101,    51, 12110,  1243, -1911,    21,  1244, 13653, 12110,
     995,   996, -1911, 12110,  8416, 13787,  1245,  1250,  1251, 16341,
    1252,  1253,  1254, 16366,  1255,  1256,  1257,  1260,  1261,  1262,
    1263, -1911,  1264,  1266,  1267, -1911, 12110, 16391,  9737,  1017,
    9737, 14334, -1911, -1911,  1271, 15259, 15259, 15259, 15259, 15259,
   15259, 15259, 15259, 15259, 15259, 15259,  8669, 15259, 15259, 15259,
   15259,  1848,   271, 15259, 15259, 15259,  8917,  9165,  9418,  9671,
   10016,  5031,  1022,  1023,    64,  9737, 10364, 10626,   271, 10707,
     271,  1015,  1016,  1024,   234,  9737, 12110, 12110, 17291, -1911,
     271,  1027, 14363, 14392, -1911, -1911,  1025,   304,   271,   119,
    1037,   425,   586,  1288, -1911,    51,   271,  7217,  1036,  5349,
    5604,   643,  1404,  1115,  1115,   517,   517,   517,   517,   517,
     517,   551,   551,  9737,   553, -1911,   553,   553,   950,   950,
     950,  1040, 16416, 15340,   358,  9737, -1911,  1291,  1045,  1046,
   16441, 16466, 16491, 12110,  7217,  1303,  1304, 10428, 16516, 14421,
   16541, 16566, -1911,   587,   588,  9737,  1050, -1911, 12400, -1911,
   12459, 12561,   429, 12110, 12110, -1911, -1911,  1053,  1055, 10762,
    4687,  1176,   570,   429, 12620, 16591, 14450, 16616, 16641, 16666,
   16691, 16716, 16741, 16766,  1057,  1312, 12110,  1314, -1911, 12110,
   16791, 14479, -1911, 15367, 12722, 15394, -1911,   589,   595,   597,
   14508, -1911,   600, 15421, 15448, 10965, -1911, -1911,  1315,  1316,
    1317,  1060, 12110, 12781, 12110, 12110, -1911, -1911,    42,   314,
     462,   314,  1069,  1070,  1063,   271,   271,  1064, 11046,   271,
     271,   271,   271, 12110,   271,  1320, -1911,  1066,  1075,   471,
     123,  1074,   603, -1911, -1911, -1911, -1911, 16816, 15259,   553,
   12883,  1073,   576,  1076,  1144,  1335,  1180, 11349,  1085,  1090,
    1341,  7217, 14537, -1911, 12110,  1344,   166,   105,    51,    32,
   13787, 12110,  1359, -1911,   605,  1319,  1321,  7217, 14566,    29,
    1105, 16841, 15475,   556, 12110, 12110,  1117,  1114,  1119,  1116,
    8735, -1911, -1911, -1911, -1911, 13653,   283,  1118, 16866, 15502,
    1122, -1911,   340, -1911,   413, 11380, -1911, -1911, -1911,  1120,
   -1911,  1128, 11640, -1911,    72, -1911, -1911, 17291, -1911,    56,
   15259, 12110,   271,   429,  7217,  7217,  1380,  7217,  7217,  7217,
    1381,  7217,  7217,  7217,  7217,  7217,  7217,  7217,  7217,  7217,
    7217,  2127,  1382,  9737,  5031, -1911, -1911, -1911, -1911, -1911,
   -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, 12110,
   -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, 12110,
   12110, 12110, 12110, 12110, -1911, -1911, -1911,   638, 12110, 12110,
   -1911, 12110, -1911,  7217, 13653, 13653, -1911,   649, 14595, 14624,
    1126, -1911, -1911, -1911,  1199, 12110, 12110, -1911, -1911, -1911,
      51, -1911,    51, 12110, 12110,  1136, -1911,  7217,  -126, -1911,
   -1911, -1911, 12110, 12110,   651,    51,  -215,   149, 12110, 12110,
   -1911,   271,   652,  7217,  9737,  9737,  1386,  1387,  1389,  2682,
   -1911, -1911,  1391, -1911,  1145, 17291,  1138,  1393, -1911,  1396,
    1397,  1398,  1399,   654,    66, -1911, 12942, -1911, -1911,   -76,
   11721, 11974, -1911, -1911, 14653,  -109,  1289,  1405, 11442,  1151,
    1406,  1158,    36,    40,   285, -1911,   -60, -1911,   570,  1409,
    1414,  1424,  1427,  1428,  1429,  1430,  1431,  1432,   334,  7217,
   17291, -1911,  2219,  1181,  1340,  1436, -1911,  1437,  1438,  1339,
    1440, -1911,  1441,  1443,  1445, 12110,  7217,  7217,  7217,  1448,
   12055, -1911,  5632,  1951,    51,    51, -1911,  9737, -1911, -1911,
   -1911, -1911, 13653, -1911, -1911, 12110, 13653, -1911, -1911, -1911,
   -1911, 17291, -1911,  1191,  1193, 13653, -1911, 13653, -1911,    51,
   13653,  1198, -1911,  1194,  1449, -1911,    51, 12110, 12110,  1197,
     647,  1201, 11690, -1911,  2261,  1203,  7217, -1911,  1204, -1911,
   14682, -1911, -1911, 12110,  1455,   384, 12110,  1457,  1458,    13,
    1463,  1213,  1465,  2708, -1911,   271,  -126,  -126,  1466, -1911,
   -1911,  1222,  1223,  1221, -1911,  1473, -1911, -1911, -1911, -1911,
   -1911, -1911,    51,   521,  3877, 12110, 15529, 16891, 12110,  8983,
   12110,  9737,  1224,   657,  1476,   160,    51, -1911,  1225, 12110,
    1477,  1479, 12110,    51, 11776, 12110,  9985,   271,  5097, 12110,
   12110,  1230,  1227, -1911,  1481, 16916,  1483,    88,  1358,  1358,
    7217,  1488,  1489,  1490,  7217,   -85,  1492,  1493,  1494,  1495,
    1496,  1498,  1500,  1501,  1502, -1911,  1504,   659, 15259, 15259,
   15259, 15259, 15259, 15259,   271, 13083, 13265, 13654,  1258,   271,
     271, -1911, -1911, -1911,    56,   271, 16941, 15259,  1265,   195,
   17291, 15259, -1911,  1506,   271, 17291, 17291, -1911,   322, -1911,
      51, -1911, 16966, 15556, -1911,   271,  1510,   666,   668,  7217,
    7217,  7217,  1513,  1512, -1911,   209, 12110,  7217,  7217,  7217,
    1268,  1269,  1503,  1514,  1515, -1911, 12110, 12110, 12110,  1272,
    1282,  1287,  1273, -1911,  2764,  7217, -1911, 12110, -1911,  1517,
   -1911,  1518, -1911, -1911, 10762,   347,  6458, -1911,  1292,  1294,
    1295,  1296,  1297,  1298,  9231,  1259,  1519, -1911,  9737,  1300,
   -1911, -1911, -1911,  1305, 12110, 12110, -1911, -1911, 15583,  1520,
    1541,  1374, -1911, 12110, 12110, 12110, -1911,  1557,   134,   526,
    1301,  5886,  1302, 12110,    28,   271,  1311,   271,  1306, -1911,
   -1911, 13787, -1911,   419, 12110,  1313, -1911, -1911,  2858, -1911,
   -1911,  1309,  1569, -1911,  3184, -1911,  1318,  1571,   178,  3224,
   -1911,    13, -1911,   673, -1911, 12110, -1911, -1911,   209,  1082,
    3143, -1911,  1325, 12110, 12110,  7217,  1322, -1911,   251,    68,
    1577, 16991,  1578,  1288, 17016,  1329,   676, 17041,   681,  1579,
    1584, -1911, -1911, 13653,  1336,  1588, 17066, -1911, -1911, 13846,
    1338, -1911,  6139,  5415, 17291, -1911,  1587,  -126,  7723, -1911,
   -1911, -1911, 17291, 17291, -1911,    56, -1911,  1589, -1911, -1911,
     429,  1590,  1591,  1592, -1911, -1911, -1911,  1459,   -56,  1497,
    1593, -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911,
    1598,  1345, -1911, -1911, -1911, -1911, -1911, -1911, -1911, 12110,
   12110, 12110, -1911, -1911, -1911,  1227, -1911, -1911, -1911, -1911,
   12110,  1349,  1342, -1911, -1911, 12110, 12110,   271,  -215, -1911,
   -1911, -1911, -1911,  1348,  1353,  1602,   -85,  1607, 12110, -1911,
    7217, 17291,  1472,  1474,   730,  9737,  9737, 12110, -1911, 10428,
   14711, 17091,  6392,   334,   334, 12110, 12110, -1911,   780,  1354,
   17116, -1911, -1911, 14740,   -50, -1911,  1611,  1613,  7217,   429,
     429,   429,   429,   429,  6711,  1614, -1911, -1911,   684,  9737,
   12110,  3278,  3330,  1615, -1911, -1911,  7217,  6645,  1660, 17141,
   -1911, -1911, 10080, -1911, 13653, 12110, -1911, 13653, 17291, 10333,
   13787,  1360, -1911, -1911, -1911, -1911,  1366,  1361, 12110, 12110,
   14769, 12110, 13913, -1911, 13913,  7217, -1911, -1911,    51,    32,
   13787, 12110,  1617, -1911,  1620, -1911,    13, 15610,  7217, 13653,
    1621,   271, -1911,  1365,   271, 12110, 13942, 13975,   686, -1911,
   12110, 12110,  1371, -1911,  1372, -1911,  1389,  1627,  1628,  1397,
    1629, -1911, -1911,  1648, 12110, -1911, -1911, 12110, 12024,  1649,
   12110, -1911, -1911,  1400,  3143,   694,  4563,  1650, -1911, -1911,
     173, -1911, -1911, -1911,  1521,  1663,  1407,  1412,  1413, -1911,
    1651,  7217, 15259, 15259, 14008, 15259, -1911,  1418, 17166, 15637,
   -1911, -1911,  9737,  9737, -1911,  1669, -1911, 17291,  1670, 12110,
   12110,  1419, -1911,   696,   697, 15231,  3469,  1671,  1420, -1911,
   -1911, 12110,  1422,  1423, 14798, 15664,  1674,  7217,  1677,  1426,
   12110, -1911, -1911,   699,   -25,    -8,     1,   168,   182,  9484,
     198, -1911,  1680,   704, 14827, -1911, -1911, -1911,  1507, -1911,
   12110, 12110, -1911, -1911,  9737,  3496,  1684,  1435, 15259,   271,
   17291, -1911, -1911, -1911, -1911,    28, -1911, 13787, -1911, 14856,
    1439,  1442,  1444,  1688,  1690,  1694,  3785, -1911, -1911, -1911,
    1450,  1695,   705, -1911,  1697,  1699,   455, 17291, 12110, 12110,
    1447,  7217,   707, 17291, 17191, -1911, -1911, -1911, -1911, 17216,
   14041, -1911, -1911, 14885,  1126,  1193,  7217,   271, -1911, 12110,
   13787,    21, -1911, -1911,  9737,  9737, 12110,  1706,   710, -1911,
   -1911, 12110,  1342, -1911, -1911, -1911,   712,   715, -1911, -1911,
    4069,  4214,  7217,   669,   671,  9737, -1911, -1911,   334,  6898,
   -1911, -1911, -1911,  1710, -1911,  1460,  7217, -1911, 14914,  1711,
    9737,   429,   429,   429,   429,   429, -1911,  1712, -1911, 12110,
   14943, 14972,   717, -1911, -1911, -1911, -1911, -1911, -1911,  1467,
    1713,  1468, -1911,  1716,    13, -1911, -1911, -1911,  1534, -1911,
   -1911, -1911, -1911, -1911, 12110, 14074, 14107,  7217, -1911,  1719,
   12110,  1469, -1911, 12110,  1723,  1470,  1471, -1911, -1911,  4845,
   -1911,  1480,   718,   723, 15001, -1911,  1475, 14140,  1482, -1911,
    1478, -1911, -1911,   728,  1484,   429,  7217,  1726,  1486,   429,
    1730,   733,  1487, -1911, 12110, -1911,  1733,  1600, 13044,  1491,
   -1911,   736,   204,   214,   233,   249,   282, -1911,  4251, -1911,
   -1911,  1734,  1740, -1911, -1911, -1911,  1742, -1911,  1499, 17291,
   12110, 12110,   741, -1911, 17291, 14173, -1911, -1911, -1911,  1126,
   13787,  1505, -1911, -1911, -1911, 12110, 12110, -1911,  9737,  1743,
     429,   116, -1911, -1911,   429,   139, -1911,  1745, -1911, 15030,
   -1911, 12110, -1911,   570, -1911,  1746,  9737,  9737,  9737,  9737,
    9484, -1911, -1911, -1911, 13913, -1911, 12110, 17241, 14206,    48,
   12110,  1508, -1911, -1911, 14239, 14272,   742, -1911,   307, -1911,
     338, -1911, -1911, -1911,  4274,   361, 13103, -1911,   743,   744,
     771,   778,   341,   779,  1522,   786, -1911, 12110, -1911,  7217,
   15059, -1911, 12110, 12110, -1911,   429,   429, -1911, -1911, -1911,
     570,  1747,  1748,  1749,  1750,  9737,  1751,  1753,  1754,  1524,
   17266,   787,  1757, 15088, 15259,   344,   435,   423, -1911, -1911,
   -1911, -1911,   793, -1911, -1911, -1911, 13653, -1911,  1525, -1911,
    1758, -1911, 12110, 12110, -1911,  1759,   795, -1911,  1526,  7217,
   -1911, 15117, 15146, -1911,  1761, 13653, 13653,   798,  1766,  1768,
   -1911, -1911,   801, -1911,  1774, -1911, -1911,  1775, 13653, -1911,
   -1911, -1911
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1911, -1911, -1911, -1911,   401, -1911, -1911, -1911, -1911,  -348,
   -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911, -1911,
   -1911, -1911,  -733,  -118,  4454,  3516,  -420, -1911,  1323, -1911,
   -1911, -1911, -1911, -1911, -1911, -1910, -1911,   348,   169,  -154,
   -1911,  -112, -1911,   110,   391, -1911,  1795, -1911,   839,   -55,
   -1911, -1911,     4,  -634,  -274, -1911, -1911, -1911, -1911, -1911,
   -1911, -1911,   732,  1796, -1911, -1911, -1911, -1911, -1253, -1250,
    1799, -1748,  1801, -1911, -1911, -1911,  1195, -1911,  -169, -1911,
   -1911, -1911, -1911,  2109, -1911, -1911, -1443,   259,  1806, -1911,
       5, -1911, -1911,   -59, -1911, -1699,   300,  -179,  2455,  2775,
    -317,    43, -1911,   -74,   -61, -1911, -1911,    69,   235, -1705,
    -147,  1028, -1911,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -577
static const yytype_int16 yytable[] =
{
     145,   626,   957,   958,  1503,  1505,  1671,   126,   312,  1082,
     326,   328,   469,   331,  1910,   167,  1911,   373,  1061,  1873,
     501,   661,   169,   167,  1067,   167,   751,   448,   417,   508,
     168,   419,  1749,  1360,  2035,   167,   167,   442,   443,   553,
     762,   346,  1498,   576,  1903,  1826,  1500,     4,   412,  1294,
     416,   153,   295,   430,  2168,   744,   642,  1638,   300,   300,
    1398,   182,   779,   302,  1827,   744,   303,   186,   304,   377,
    1483,   452,  1792,   598,   317,   666,   462,   465,   466,  1396,
     794,   350,   301,  1076,   453,   148,   795,   745,   746,   351,
     295,   352,  1399,  1400,  1629,   376,   790,   745,   746,     5,
     318,   477,   745,   746,   745,   746,   413,  1639,   155,  1947,
     306,   478,  1342,   307,   308,   309,   319,   320,   634,   635,
     496,   598,  2149,   611,   612,   613,   310,   634,   635,   170,
     347,   171,  1958,   728,   634,   635,   510,   634,   635,   952,
    1741,  1742,   454,   636,   719,  2151,   722,   464,   464,   464,
     456,  1490,   777,   634,   635,   735,   471,   342,   959,   343,
     778,   747,   748,   656,   657,   658,  1602,   634,   635,  1060,
     156,   747,   748,  1342,   963,   480,   747,   748,   747,   748,
     673,   924,   149,   634,   635,  1770,   353,   783,  1486,  2141,
     311,   464,   150,   634,   635,   784,   295,   549,   550,   356,
     295,   536,   357,   537,  1504,   295,   295,   464,  1361,  1362,
    1363,  1364,  1065,  1499,  1870,   358,  1342,  1501,   634,   635,
      99,   151,   100,   101,   102,   103,   104,   634,   635,  1837,
     108,   109,  1750,   111,   152,   634,   635,   348,   119,  1990,
     119,  1083,  1084,   637,   634,   635,   119,   157,   119,   785,
     749,   750,   634,   635,   797,  1503,  1991,   786,   119,   119,
     795,   295,   629,   630,   119,  1992,   158,   754,   644,   755,
     638,   643,   374,  2053,   662,   295,   663,   159,   295,   574,
     147,  1023,   418,   442,   443,   420,   763,   573,   764,  1365,
    -569,  1349,   765,   554,   295,   295,   349,   577,   295,   295,
     295,   295,   431,  1295,   154,   160,   432,  2169,   780,   295,
     781,  1042,   183,   295,   782,   376,   442,   443,   187,   599,
     378,   600,  1166,  1343,  1346,   601,   146,   170,  2092,   171,
     147,   634,   635,   438,   439,   440,   441,   295,   455,   295,
     295,   295,   791,   161,   781,  1073,   428,   170,   792,   171,
     429,   948,   732,   950,   951,   293,   295,   442,   443,   634,
     635,   163,  1090,   295,   442,   443,  1345,   599,   313,   600,
     964,   314,  1101,   601,   739,  1189,   442,   443,   884,   729,
    1190,   730,   634,   635,  1319,   731,  2164,  1320,   744,   984,
     438,   439,   440,   441,   438,   439,   440,   441,  1083,  1084,
     874,   442,   443,   685,   332,   147,   438,   439,   440,   441,
    1460,   634,   635,  1003,   442,   443,   634,   635,   442,   443,
     745,   746,   759,   464,   295,   634,   635,  1247,   295,   295,
     442,   443,  1993,   438,   439,   440,  1066,   438,   439,   440,
     441,   634,   635,   162,   295,  1248,  1994,   634,   635,   164,
     170,   766,   171,  1040,  1249,  1250,  1251,   634,   635,  1193,
    1252,  1253,  1995,   754,   200,   755,   756,   868,  2126,   870,
    2191,   872,   873,   165,   802,  1198,   634,   635,  2127,   166,
     788,    68,    69,    70,    71,   886,   887,    74,   789,  1247,
    1176,   179,   634,   635,   747,   748,    83,  2128,   789,    86,
     295,   333,   890,  1247,   198,   334,  1791,  1248,  1759,   509,
    -573,   335,   336,  2129,   337,   338,  1249,  1250,  1251,  2048,
    2227,  1248,  1252,  1253,   295,   634,   635,   754,   180,   755,
    1249,  1250,  1251,   295,   864,   339,  1252,  1253,   464,  1385,
     464,   295,   464,   464,   471,  1502,  2130,   830,  1011,   880,
     634,   635,   181,   295,   295,   295,   464,   464,   295,   169,
     754,   169,   755,   295,   293,  1247,   184,   889,  1186,   891,
     754,  2175,   755,  1566,  1567,   955,   956,  1675,   789,  1676,
     630,   634,   635,  1248,   634,   635,   645,   634,   635,   295,
     646,   185,  1249,  1250,  1251,   921,  1390,   188,  1252,  1253,
     204,   610,  2176,   205,   830,  2185,   206,  1715,  2212,   189,
     442,   443,   619,  1208,   190,  1209,   624,   295,   295,   207,
    1010,  2178,  1012,  1013,  1014,  1015,  1016,  1017,   191,  1019,
    1020,  1021,  1022,  1062,  1515,  1027,  1028,  1029,  1348,   829,
     456,   456,   659,   830,   192,   193,   660,  1026,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,   295,   295,   295,  1391,
     597,   295,   322,   323,  1758,  1236,  1759,   830,   634,   635,
     170,   894,   171,  2214,   324,   830,  1192,   194,   325,  1193,
     471,   464,   471,   464,   464,   464,   464,   464,   464,  2213,
     464,   464,   464,   464,  1025,   195,   464,   464,   464,   169,
    1031,  2023,  1247,   295,   196,  1097,  1078,  1030,   754,  2024,
     755,   322,   323,   197,  1106,  1041,  1297,   754,   199,   755,
    1248,   736,   737,   324,  1851,  1317,  1852,   330,   295,  1249,
    1250,  1251,  1690,   201,  1112,  1252,  1253,   752,   173,   203,
     209,   174,   306,   295,   175,   307,   176,   309,   202,  1070,
     590,   591,   726,   593,   594,   595,   596,    46,   310,   210,
    1448,   597,  1449,   442,   443,   295,  1087,   296,   297,   298,
    -571,   295,   754,   295,   755,  1458,   471,  1099,   578,   754,
     830,   755,   925,  1104,   299,   464,   726,   593,   594,   595,
     596,   595,   596,   315,   316,   597,  1210,   597,   442,   443,
     341,  1375,   345,  1328,  1484,  -572,  2054,  2055,  2058,  2059,
     321,   329,  2056,   340,  2056,   295,   928,   295,   442,   443,
     830,  1327,   929,  1328,   974,  1771,   830,  1044,   830,  1050,
     361,   830,   125,  1051,   871,  1778,  1196,  1231,  1232,  1278,
     830,   830,   830,   830,   344,  1279,   610,  1280,   885,   830,
    1282,   830,   295,  1323,   830,  1355,   177,   830,   354,   830,
    2155,   362,   295,   355,  1537,  1538,  1226,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,  1239,   295,   360,   363,   597,  1434,  1548,
    1245,   305,   830,   369,  1256,  1503,  1553,   381,   370,  1441,
     295,  1457,  1465,   830,  1482,   830,   830,  1600,   830,  1651,
     371,   830,   295,   830,  1210,  1568,  1683,  2197,  1684,   372,
     830,   295,   830,  1775,   379,   380,  1798,  1776,  1344,  1347,
     830,  1800,   295,   382,  1882,   830,  1930,  1503,   830,   383,
    1931,   433,  1588,   421,  1948,  1210,  1973,  1974,  1949,  1989,
     830,   830,   427,  1931,  1997,  2020,  1604,  2029,   830,   789,
    2046,  2030,  2049,  1610,  1931,  2050,   830,  2081,  2102,   830,
     414,   830,   830,  2103,   450,   434,   426,   830,  2109,   450,
     450,   450,  1931,  2117,   459,   460,  2125,   830,   450,  1352,
     830,  2139,  2174,  2181,  2182,  1931,   830,   830,   830,   147,
     475,  1384,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     477,  2183,  1572,   450,   597,   830,   479,   484,  2184,  2186,
    1866,  1055,   830,   830,   488,   502,  2188,  2208,   295,   450,
    2030,  1931,   544,  2215,  1407,  2224,  1351,   830,  2234,  2225,
     547,  2237,  1931,   507,   295,  2238,  -204,  -205,  -206,  1862,
    1863,   555,   556,   559,   562,   563,   564,   295,   575,   607,
     608,   429,   464,   615,   617,   616,   167,   384,  1459,  1461,
     548,   620,   623,   625,   627,   647,   628,   648,   649,   650,
    1439,  1440,   651,   652,   653,   557,   558,   664,   665,   667,
     668,   295,   295,   669,   295,   295,   295,   670,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   671,   672,
     295,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     674,   675,   676,   680,   394,   395,   396,   397,   677,   681,
     688,   696,   398,   399,   400,   401,   687,   697,   698,   709,
     402,   710,   403,   712,   713,   714,   715,   717,   716,   720,
     295,   464,   464,   718,   721,   723,   404,   738,   741,   405,
     753,   758,   760,   173,   761,   146,   174,   767,   799,   175,
     821,   176,   803,   805,   295,   826,   832,  1200,   833,   834,
     895,   865,    46,   875,   597,   876,   877,   897,   898,   933,
     295,   295,   295,   934,   937,   942,   946,   947,  1001,   976,
     436,   949,   978,   997,   979,   982,   991,  1004,  1540,  1033,
    1035,  1043,  1542,  1049,  1220,  1053,  1058,  1054,  1059,  1063,
    1074,  1546,  1075,  1547,  1080,  1091,  1549,  1093,  1096,  1103,
    1105,  1108,  1113,  1109,  1774,  1459,  1461,  1114,  1115,  1117,
    1118,  1119,  1121,  1122,  1123,   450,   295,  1124,  1125,  1126,
    1127,  1128,   456,  1129,  1130,   740,  1133,  1137,  1164,  1173,
    1174,  1165,  1762,   295,   295,   295,  1764,  1182,  1175,  1185,
     406,   407,   408,  1191,   295,  1197,  1201,   774,  1213,   464,
    1590,  1205,   409,   464,  1214,  1215,   410,  1221,   411,   119,
    1223,  1234,   464,  1242,   464,  1243,  1268,   464,  1246,  1269,
    1271,  1289,  1286,  1287,  1288,  1300,  1301,  1302,  1305,  1313,
    1315,  1316,  1322,   295,  1326,  1615,  1330,  1620,   754,  1329,
     755,  1779,  1331,  1332,  2062,  1335,   376,  1337,  1913,  1336,
    1341,  1338,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,  1354,  1372,  1358,  1356,   597,
    1357,   464,  1378,  1379,  1380,  1381,   295,  1389,   295,  1386,
     450,  1393,   450,  1394,   450,   450,   450,  1410,  1414,  1426,
    1444,  -207,  1452,  1469,  1470,   295,  1471,  1474,   450,   450,
    1477,  1475,  1476,  1478,  1479,  1480,  1481,   295,  1491,  1492,
    1495,   295,  1496,  1497,  1408,  1409,  1506,  1411,  1412,  1413,
    1507,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,  1423,
    1424,  1508,  1783,  1783,  1509,  1510,  1511,  1512,  1513,  1514,
    1518,  1519,  1520,  1521,  1522,  1714,  1523,  1524,  1525,  1526,
    1772,  1527,  1532,  1543,  1550,  1552,  1554,  1544,  1551,  1919,
    1556,  1565,  1560,  1570,  1562,  1571,   295,   295,   295,  1574,
    1575,  1576,  1581,  1438,   295,   295,   295,  1583,  1584,  1587,
    1585,   774,  1601,  1607,  1599,  1608,  1605,  1626,  1624,  1628,
    1757,  1625,   295,  1630,  1634,  1635,  1636,  1453,  1641,  1642,
    1643,  1644,  1645,   295,  1646,   774,  1647,  1648,  1649,  1650,
    1697,   295,  1673,  1466,  1662,   295,  1682,  1688,  1689,  1726,
    1698,  1669,  1699,  1711,  1712,  1727,  1734,  1695,  1696,  1803,
    1706,  1703,   450,   450,   450,   450,   450,   450,   450,   450,
     450,  1704,   450,   450,   450,   450,  1705,  1735,   450,   450,
     450,  1718,  1812,  1719,  1720,  1721,  1722,  1723,   774,  1729,
    1841,   774,  1736,  1740,  1730,  1744,  1747,  1754,   376,  1516,
    1320,  1820,  1761,  1765,   774,  1766,   471,   471,  1769,  1768,
    1785,  1790,   295,  1793,  1795,  1801,  1529,  1530,  1531,  1797,
    1802,  1804,  1805,  1808,  1813,  1819,  1821,  1822,  1823,  1829,
     464,  1824,  1828,  1830,  1831,  1836,  1193,  1842,  1844,  1077,
     295,  1079,  1843,  1846,  1849,   295,  1850,  1871,  1867,  1872,
    1881,  1887,  1906,  1917,  1905,  1907,  1918,  1923,   450,   789,
    -576,  -574,  1922,  1935,  1936,  1937,  1561,   450,  1857,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,  1938,  1942,  1957,  1951,   597,  1946,
    1874,  1875,  1876,  1877,  1878,  1880,  1954,  1952,  1891,  1953,
    1897,  1955,  1956,  1899,  1963,  1968,  1969,  1977,  1972,  1978,
    1984,  1896,  1980,  1981,  1986,  1987,  1996,   295,  1901,  1904,
    2004,  2005,   295,   295,  1999,  2014,  2015,  2086,  1619,  2011,
    2016,  2019,  2012,  2021,  2013,  2022,  2027,   456,   456,  1915,
    1633,  2018,  2045,  2068,  1637,   295,  2065,  2070,  2077,  2083,
    2066,   295,  2085,  2082,  2087,  2093,   295,  2084,  -575,  2096,
    2097,  2098,  2113,   295,  2105,  2101,  2116,  2108,  2107,  2120,
    2132,   464,  2121,  2110,   464,  2114,  2133,  2118,  2135,  2147,
    2124,  2152,  2157,  2198,  2199,  2200,  2201,  2203,  2136,  2204,
    2205,  2143,   295,  2209,  2220,  2223,  1351,  2230,  2171,  1685,
    1686,  1687,  2235,   376,  2236,   295,   471,  1692,  1693,  1694,
    2239,  2240,  2187,  2206,  2219,  2226,  1603,   774,  2165,   774,
     774,  2036,  1665,  2008,  1818,  1709,  1845,   798,   124,   135,
    1632,  1371,   136,   774,   137,  2060,  1717,  1756,   936,   143,
    2134,   471,  1914,     0,  1725,  1784,     0,  1098,  1902,     0,
       0,     0,     0,   774,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
     295,     0,   774,     0,     0,     0,  2009,     0,     0,     0,
    2156,     0,     0,     0,     0,     0,   578,     0,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   295,     0,     0,   774,
       0,     0,     0,     0,     0,  1789,     0,     0,     0,  2040,
       0,   295,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,  1811,   597,     0,     0,     0,     0,     0,
    1892,     0,     0,     0,   450,     0,     0,     0,   295,     0,
       0,     0,  2072,  2073,  2074,  2075,  2076,     0,     0,     0,
       0,     0,     0,   295,     0,     0,     0,     0,  2041,     0,
       0,   295,   295,     0,     0,     0,     0,     0,     0,  1535,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   295,
       0,     0,   295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   456,   295,     0,     0,     0,   295,     0,     0,
    1848,     0,     0,     0,     0,     0,  2111,     0,     0,     0,
    2115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   376,     0,   450,   450,     0,     0,     0,  1789,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1888,     0,     0,  2142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2148,     0,   295,     0,  2150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1912,     0,     0,     0,     0,
       0,  2162,     0,     0,     0,   774,     0,     0,  1921,     0,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   828,   593,   594,   595,   596,     0,     0,
       0,     0,   597,   776,   754,   295,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2195,  2196,     0,     0,
       0,     0,     0,   295,   295,   295,   295,   295,     0,     0,
       0,  1789,  2217,  1425,     0,     0,     0,     0,     0,     0,
       0,   450,     0,     0,     0,   450,     0,     0,     0,     0,
       0,  2231,  2233,     0,   450,     0,   450,     0,     0,   450,
       0,     0,     0,     0,  2241,     0,   295,  1985,     0,  1555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,   464,     0,   597,     0,  1536,     0,     0,
       0,     0,     0,   450,     0,     0,   295,     0,     0,     0,
       0,     0,   464,   464,     0,  1517,     0,   424,     0,     0,
       0,  2028,     0,     0,     0,   464,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2037,     0,     0,     0,
       0,     0,     0,     0,   451,     0,     0,     0,   461,     0,
       0,     0,     0,   467,     0,     0,     0,  1559,     0,     0,
       0,   472,  1789,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2067,     0,   481,   482,
     483,     0,   485,   486,   487,     0,   489,   490,   491,   492,
     493,   494,   495,     0,   497,   498,   499,   500,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1789,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,  2112,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,   565,   567,   569,   570,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   604,   504,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   450,   450,
       0,     0,     0,   622,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   632,   633,     0,     0,     0,     0,   633,
       0,     0,   450,     0,     0,     0,     0,     0,     0,   504,
     655,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,  1789,
       0,     0,     0,   597,   678,   504,     0,     0,     0,   682,
     683,   684,     0,   686,     0,     0,     0,   689,   690,   691,
       0,     0,   692,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,  1789,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   725,     0,     0,     0,   504,   734,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   742,   743,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   450,     0,     0,   450,     0,   804,     0,
       0,     0,     0,   809,     0,     0,     0,   813,     0,     0,
       0,   774,     0,   774,     0,     0,     0,     0,     0,     0,
       0,   827,   567,     0,     0,     0,   831,     0,   450,     0,
     835,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   853,   854,   855,
     856,   857,   858,   859,   860,   861,   861,     0,   866,   867,
       0,   869,     0,   450,     0,     0,     0,     0,   505,     0,
     878,     0,     0,   882,   883,     0,     0,     0,     0,     0,
     861,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   914,   916,   917,   918,   919,   920,     0,   922,   923,
       0,     0,     0,     0,  1577,     0,   930,   931,   932,     0,
       0,     0,     0,     0,   938,   939,   940,   941,     0,   504,
     504,     0,     0,   568,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,   725,
     960,     0,   505,   505,   965,   966,   967,   968,   969,   970,
     971,   972,   973,     0,     0,     0,     0,     0,   980,   981,
    1707,   983,     0,     0,   985,     0,     0,     0,   504,   504,
     504,   990,     0,   504,   993,   994,   995,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1018,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,  1472,   504,     0,     0,     0,     0,
       0,     0,  1037,  1038,     0,  1039,     0,     0,   922,   923,
       0,     0,     0,     0,     0,     0,     0,  1052,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1763,   504,     0,  1068,     0,     0,
       0,     0,  1071,  1072,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,     0,   504,     0,  1088,
    1089,     0,     0,   504,     0,   504,  1095,     0,     0,     0,
    1088,     0,  1102,     0,     0,     0,     0,   774,  1107,     0,
       0,     0,  1110,     0,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,  1131,   597,   914,     0,  1134,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,   568,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   774,   504,     0,     0,     0,   506,     0,
       0,     0,   852,     0,   504,  1178,  1179,     0,     0,     0,
       0,   862,   863,     0,     0,   774,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,   888,     0,   597,     0,
       0,   505,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,  1219,     0,     0,   450,  1225,   915,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,  1240,  1241,   450,   450,     0,     0,  1244,     0,
       0,     0,   605,   606,     0,   505,   505,   450,     0,     0,
       0,     0,     0,     0,     0,  1270,     0,     0,  1272,     0,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,  1290,   597,  1292,  1293,   654,     0,     0,     0,     0,
       0,     0,     0,     0,   505,   505,   505,     0,     0,   505,
       0,     0,  1311,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   384,     0,
       0,     0,     0,     0,     0,     0,  1334,     0,     0,     0,
       0,     0,     0,  1340,     0,     0,     0,     0,     0,     0,
    1353,   505,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1376,  1377,     0,     0,     0,     0,   504,
    1767,     0,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,   733,     0,     0,   394,   395,   396,   397,     0,
       0,   505,     0,   398,   399,   400,   401,     0,     0,     0,
    1405,   402,     0,   403,     0,     0,     0,     0,     0,     0,
    1773,     0,     0,   505,     0,     0,     0,   404,     0,   505,
     405,   505,   504,     0,   173,     0,     0,   174,     0,     0,
     175,     0,   176,     0,     0,     0,     0,     0,  1428,     0,
       0,     0,     0,    46,     0,     0,     0,     0,  1429,  1430,
    1431,  1432,  1433,     0,     0,     0,     0,  1435,  1436,     0,
    1437,   436,     0,   915,  1885,  1135,     0,     0,     0,     0,
       0,     0,     0,     0,  1446,  1447,     0,     0,     0,     0,
       0,     0,  1450,  1451,     0,     0,     0,     0,     0,     0,
       0,  1455,  1456,     0,     0,     0,     0,  1462,  1463,     0,
     505,     0,     0,   504,   504,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,  1886,     0,     0,     0,
       0,   892,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   406,   407,   408,     0,     0,     0,  1494,     0,     0,
       0,     0,     0,   409,     0,     0,     0,   410,   505,   411,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1528,   943,   944,     0,     0,     0,
     505,     0,  1779,     0,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,  1541,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,  1462,  1463,   597,     0,
       0,  1558,     0,     0,   987,   988,   989,     0,     0,   992,
       0,     0,  1564,     0,     0,  1569,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,  1976,     0,     0,   597,     0,
       0,     0,     0,     0,  1591,     0,     0,  1594,   504,  1597,
     504,  1032,     0,     0,     0,     0,     0,     0,  1606,     0,
       0,  1609,  2003,  1606,  1612,  1614,     0,     0,  1622,  1623,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,  1064,   597,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1086,     0,     0,     0,     0,     0,  1092,
       0,  1094,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,  1691,     0,     0,   505,     0,
       0,     0,     0,     0,     0,  1700,  1701,  1702,     0,     0,
       0,     0,     0,     0,  1708,     0,  1710,     0,     0,     0,
       0,     0,     0,  1713,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,     0,  1731,  1732,     0,     0,     0,     0,     0,
    1167,     0,  1737,  1738,  1739,     0,     0,     0,     0,     0,
    1177,     0,  1748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1760,     0,     0,     0,     0,     0,   505,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1777,     0,     0,     0,  1204,     0,
       0,     0,  1786,  1787,     0,     0,     0,     0,     0,     0,
    1212,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
    1233,     0,     0,   597,     0,     0,     0,  1816,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1832,  1833,
    1834,     0,     0,     0,     0,     0,     0,     0,     0,  1835,
       0,     0,     0,     0,  1838,  1839,     0,     0,     0,     0,
       0,  2017,     0,     0,     0,     0,     0,  1847,     0,     0,
       0,     0,     0,     0,   504,   504,  1855,     0,  1856,     0,
       0,     0,     0,     0,  1864,  1865,   578,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,   505,     0,   505,     0,   504,  1884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1895,     0,     0,  1898,  1383,     0,     0,  1900,     0,
       0,     0,     0,     0,     0,     0,     0,  1838,  1839,     0,
    1909,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1916,   167,   384,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1927,     0,     0,     0,     0,  1933,
    1934,     0,     0,     0,     0,     0,     0,     0,  1427,     0,
       0,     0,     0,  1939,     0,     0,  1940,  1939,     0,  1943,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
     395,   396,   397,     0,     0,     0,     0,   398,   399,   400,
     401,   504,   504,     0,     0,   402,     0,   403,  1970,  1971,
       0,     0,     0,     0,     0,   757,     0,     0,     0,     0,
    1979,   404,     0,   505,   405,     0,     0,     0,   173,  1988,
       0,   174,     0,     0,   175,     0,   176,     0,   567,  1467,
    1468,     0,     0,     0,     0,     0,     0,    46,     0,  2000,
    2001,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   436,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,  2025,  2026,   597,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,  2039,     0,
       0,     0,   597,   504,   504,  2044,     0,     0,   879,     0,
    2047,     0,  1539,  1817,     0,  2051,     0,     0,     0,     0,
       0,     0,     0,     0,   504,   406,   407,   408,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   409,     0,   504,
       0,   410,     0,   411,   119,     0,     0,     0,  2078,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   926,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   442,
     443,     0,     0,  2089,     0,     0,  -570,     0,  1589,  2094,
       0,     0,  2095,     0,     0,     0,     0,     0,     0,     0,
     505,   505,     0,     0,  1596,     0,  1598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2119,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2137,
    2138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2144,  2145,     0,   504,     0,     0,
    2052,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2154,     0,     0,     0,     0,   504,   504,   504,   504,   504,
       0,     0,     0,     0,     0,  1933,     0,     0,     0,  2170,
       0,     0,     0,     0,     0,     0,     0,  2131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2190,     0,     0,     0,
    2177,  2193,  2194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1728,   504,     0,     0,   505,   505,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,  2221,  2222,   597,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   568,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,     0,  1150,  1151,  1152,  1153,     0,  1155,  1156,
    1157,  1158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1170,     0,  1172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1181,     0,     0,     0,
       0,     0,     0,  1187,  1188,     0,     0,     0,     0,   505,
     505,     0,  1199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
    1853,  1854,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,   178,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,  1883,   597,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,  1296,  1298,  1299,   597,     0,
       0,  1303,  1304,     0,     0,  1307,  1308,  1309,  1310,     0,
    1312,     0,     0,     0,     0,  1318,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
    1950,   578,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,   505,   505,   505,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1966,  1967,     0,
       0,     0,     0,     0,     0,     0,  1404,     0,  1406,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2002,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   538,   539,   540,   541,   542,
     543,     0,   545,   546,     0,     0,     0,     0,     0,     0,
       0,   551,   552,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   560,   561,     0,     0,  1464,     0,  2042,
    2043,     0,     0,     0,     0,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
    2061,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,  2071,   768,    56,     0,     0,
      59,   769,     0,   770,   771,     0,   772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   828,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   693,
     694,   695,     0,     0,     0,   699,   700,   701,   702,   703,
     704,   705,  2100,   706,     0,     0,     0,     0,   707,   708,
       0,     0,   711,     0,     0,     0,     0,     0,     0,     0,
       0,  1578,     0,     0,     0,     0,   724,     0,     0,     0,
       0,     0,     0,  2146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   961,     7,     8,     0,     0,
       0,  2158,  2159,  2160,  2161,  2163,     0,     0,     0,     0,
       0,     0,     0,  1616,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,   996,  1652,  1653,  1654,  1655,  1656,  1657,
    1658,   953,     0,     0,     0,  1663,  1664,     0,     0,     0,
    2202,  1666,     0,  1668,     0,     0,     0,  1672,     0,     0,
    1674,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1681,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,   768,    56,     0,     0,    59,   769,
       0,   770,   771,     0,   772,     0,     0,     0,   896,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   578,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1743,     0,  1746,     0,     0,
       0,  1753,     0,  1755,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,  1780,     0,     0,     0,   597,
     211,     6,   384,     0,     0,     0,     0,   212,   213,   214,
       0,     0,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   986,     0,     0,  1617,   386,   387,   388,
     389,   390,   391,   392,   393,   246,   247,   248,   249,   394,
     395,   396,   397,   250,   251,  1005,     0,   398,   399,   400,
     401,     0,     0,   252,   253,   402,     0,   403,   254,   255,
     256,     0,     0,     0,     0,     0,     0,     0,     0,   257,
      25,   404,   258,  1840,   405,     0,     0,     0,   259,     0,
       0,   260,     0,     0,   261,     0,   262,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
      57,    58,     0,   265,     0,   266,     0,     0,   267,     0,
       0,     0,     0,     0,    68,    69,    70,    71,    72,     0,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    83,
       0,     0,    86,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   828,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1924,     0,     0,
    1925,     0,     0,     0,   268,   406,   407,   408,   269,   270,
       0,     0,     0,     0,   271,   272,   273,   409,   274,   275,
     276,   410,     0,   411,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   278,     0,     0,     0,  1194,     0,   279,  1959,  1960,
       0,  1962,   365,     0,     0,     0,  1618,  1202,     0,   282,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,  1211,     0,
       0,     0,   597,     0,     0,     0,     0,     0,   825,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,  2006,  2007,     0,     0,   211,     6,
     384,     0,     0,     0,     0,   212,   213,   214,     0,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,     0,  2038,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   246,   247,   248,   249,   394,   395,   396,
     397,   250,   251,     0,     0,   398,   399,   400,   401,     0,
       0,   252,   253,   402,     0,   403,   254,   255,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   257,    25,   404,
     258,     0,   405,     0,     0,     0,   259,     0,     0,   260,
       0,     0,   261,     0,   262,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,    57,    58,
       0,   265,     0,   266,     0,     0,   267,     0,  1397,     0,
       0,     0,    68,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,    83,     0,     0,
      86,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,     0,
       0,     0,  1203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   406,   407,   408,   269,   270,     0,     0,
       0,     0,   271,   272,   273,   409,   274,   275,   276,   410,
    1534,   411,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1454,     0,     0,     0,     0,     0,   277,   278,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     365,     0,     0,     0,   281,     0,     0,   282,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
     211,   167,   384,   597,   435,   806,     0,   212,   213,   214,
    2211,     0,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   422,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   246,   247,   248,   249,   394,
     395,   396,   397,   250,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   403,   254,   255,
     256,     0,     0,     0,     0,     0,     0,     0,     0,   257,
      25,   404,   258,     0,   405,     0,     0,     0,   173,     0,
       0,   174,     0,     0,   175,     0,   176,     0,     0,     0,
    1579,  1580,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   436,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,     0,     0,
       0,     0,     0,  1670,   268,   406,   407,   408,   269,     0,
       0,     0,  1677,     0,   271,   272,   273,   409,   274,   275,
     276,   410,     0,   411,   119,   438,   439,   440,   441,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   423,     0,     0,     0,     0,     0,   279,     0,   442,
     443,     0,   444,     0,   445,   211,     6,   364,   446,   282,
       0,     0,   212,   213,   214,     0,     0,   215,   216,   217,
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
       0,  1814,   263,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,    57,    58,     0,   265,     0,
     266,     0,     0,   267,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   754,     0,   755,     0,     0,     0,     0,     0,
    1745,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,     0,     0,   269,   270,     0,     0,     0,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   278,     0,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   365,   211,     6,
       0,   366,     0,   679,   282,   212,   213,   214,     0,     0,
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
      86,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,  1809,
       0,     0,     0,  1810,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,     0,     0,   269,   270,     0,     0,
       0,     0,   271,   272,   273,     0,   274,   275,   276,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   503,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     365,   211,     6,  1716,     0,   571,     0,   282,   212,   213,
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
      83,     0,     0,    86,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
       0,     0,  1860,     0,     0,     0,  1861,     0,     0,     0,
       0,     0,     0,     0,     0,   268,     0,     0,     0,   269,
     270,     0,     0,     0,     0,   271,   272,   273,     0,   274,
     275,   276,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,   278,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,   365,   211,     6,     0,   281,     0,     0,
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
       0,     0,     0,    83,     0,     0,    86,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,     0,  1889,     0,     0,     0,  1890,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,   269,   270,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,  1879,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,   641,   211,     6,     0,
     325,   571,     0,   282,   212,   213,   214,     0,     0,   215,
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
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,  2063,     0,
       0,     0,  2064,     0,     0,     0,     0,     0,     0,     0,
       0,   268,     0,     0,     0,   269,   270,     0,     0,     0,
       0,   271,   272,   273,     0,   274,   275,   276,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   278,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,   280,
     211,     6,     0,   281,     0,     0,   282,   212,   213,   214,
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
       0,     0,    86,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   787,     0,     0,     0,     0,
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
       0,     0,    83,     0,     0,    86,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   793,     0,
       0,     0,     0,     0,     0,     0,     0,   268,     0,     0,
       0,   269,   270,     0,     0,     0,     0,   271,   272,   273,
       0,   274,   275,   276,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   503,     0,     0,     0,     0,     0,
     279,     0,     0,     0,     0,   365,   211,     6,     0,   566,
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
      78,    79,     0,     0,     0,    83,     0,     0,    86,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   953,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,   269,   270,     0,     0,     0,     0,
     271,   272,   273,     0,   274,   275,   276,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   503,     0,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   365,   211,
       6,     0,     0,   571,     0,   282,   212,   213,   214,     0,
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
       0,    86,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   954,     0,     0,     0,     0,     0,
       0,     0,     0,   268,     0,     0,     0,   269,   270,     0,
       0,     0,     0,   271,   272,   273,     0,   274,   275,   276,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     278,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,   609,   211,     6,     0,   281,     0,     0,   282,   212,
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
       0,    83,     0,     0,    86,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1002,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,     0,     0,
     269,   270,     0,     0,     0,     0,   271,   272,   273,     0,
     274,   275,   276,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,   278,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   618,   211,     6,     0,   281,     0,
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
      79,     0,     0,     0,    83,     0,     0,    86,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,     0,     0,   269,   270,     0,     0,     0,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   503,     0,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   365,   211,     6,
       0,   913,     0,  1382,   282,   212,   213,   214,     0,     0,
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
      86,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1149,     0,     0,     0,     0,     0,     0,
       0,     0,   268,     0,     0,     0,   269,   270,     0,     0,
       0,     0,   271,   272,   273,     0,   274,   275,   276,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   503,
       0,     0,     0,     0,     0,   279,   211,     6,     0,     0,
     365,  1595,     0,   212,   213,   214,     0,   282,   215,   216,
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
      78,    79,     0,     0,     0,    83,     0,     0,    86,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1159,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,   269,   270,     0,     0,     0,     0,
     271,   272,   273,     0,   274,   275,   276,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   503,     0,     0,
       0,     0,     0,   279,   211,     6,     0,     0,   365,     0,
       0,   212,   213,   214,     0,   282,   215,   216,   217,   218,
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
       0,     0,     0,    83,     0,     0,    86,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1160,
       0,     0,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,   269,   270,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,   278,     0,     0,     0,     0,
       0,   279,     0,     0,     0,     0,   365,   211,     6,     0,
    1724,     0,     0,   282,   212,   213,   214,     0,     0,   215,
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
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1161,     0,     0,     0,     0,     0,     0,     0,
       0,   268,     0,     0,     0,   269,   270,     0,     0,     0,
       0,   271,   272,   273,     0,   274,   275,   276,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   639,  1879,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,   641,
     211,     6,     0,   325,     0,     0,   282,   212,   213,   214,
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
       0,     0,    86,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1162,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,     0,     0,   269,   270,
       0,     0,     0,     0,   271,   272,   273,     0,   274,   275,
     276,     0,     0,     0,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     277,   503,     0,     0,     0,     0,     0,   279,   211,   167,
     384,     0,   365,     0,     0,   212,   213,   214,     0,   282,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   422,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,     0,     0,     0,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   246,   247,   248,   249,   394,   395,   396,
     397,   250,     0,     0,     0,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   403,   254,   255,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   257,    25,   404,
     258,     0,   405,   211,   167,   384,     0,     0,     0,     0,
     212,   213,   214,     0,     0,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   422,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   246,   247,
     248,   249,   394,   395,   396,   397,   250,     0,     0,     0,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
     403,   254,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,   257,    25,   404,   258,     0,   405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   406,   407,   408,   269,     0,     0,     0,
       0,     0,   271,   272,   273,   409,   274,   275,   276,   410,
       0,   411,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   423,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     365,     0,     0,     0,  1613,     0,     0,   282,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1163,     0,     0,     0,     0,     0,     0,   268,   406,   407,
     408,   269,     0,     0,     0,     0,     0,   271,   272,   273,
     409,   274,   275,   276,   410,     0,   411,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   423,     0,     0,     0,     0,     0,
     279,     0,     0,     0,     0,   365,   211,   167,   384,  1894,
       0,     0,   282,   212,   213,   214,     0,     0,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   422,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,     0,
       0,     0,  1617,   386,   387,   388,   389,   390,   391,   392,
     393,   246,   247,   248,   249,   394,   395,   396,   397,   250,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,   403,   254,   255,   256,     0,     0,     0,
       0,     0,     0,     0,     0,   257,    25,   404,   258,     0,
     405,   211,   167,   384,     0,     0,     0,     0,   212,   213,
     214,     0,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     422,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   246,   247,   248,   249,
     394,   395,   396,   397,   250,     0,     0,     0,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,   403,   254,
     255,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     257,    25,   404,   258,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,   406,   407,   408,   269,     0,     0,     0,     0,     0,
     271,   272,   273,   409,   274,   275,   276,   410,     0,   411,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   423,     0,     0,
       0,     0,     0,   279,     0,     0,     0,     0,   365,     0,
       0,     0,  1779,     0,     0,   282,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1168,     0,
       0,     0,     0,     0,     0,   268,   406,   407,   408,   269,
       0,     0,     0,     0,     0,   271,   272,   273,   409,   274,
     275,   276,   410,     0,   411,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   277,   423,     0,     0,     0,     0,     0,   279,   211,
     167,     0,     0,   365,     0,     0,   212,   213,   214,     0,
     282,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   422,   233,
     234,   235,   236,   237,   238,   239,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,   248,   249,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
       0,     0,     0,     0,     0,   211,   167,     0,   257,    25,
       0,   258,   212,   213,   214,     0,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   422,   233,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,   248,   249,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,     0,   257,    25,     0,   258,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,   268,     0,     0,     0,   269,     0,     0,
    1169,     0,     0,   271,   272,   273,     0,   274,   275,   276,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     423,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,   365,     0,     0,     0,   621,     0,     0,   282,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,     0,     0,   268,
       0,  1171,     0,   269,     0,     0,     0,     0,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   639,   640,     0,     0,     0,
       0,     0,   279,     0,     0,     0,     0,   641,   211,   167,
       0,   325,     0,   881,   282,   212,   213,   214,     0,     0,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   422,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,     0,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,   256,     0,
       0,     0,     0,     0,   211,   167,     0,   257,    25,     0,
     258,   212,   213,   214,     0,     0,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   422,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,   248,   249,     0,     0,     0,     0,   250,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,     0,     0,     0,     0,     0,
       0,     0,     0,   257,    25,     0,   258,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,   268,     0,     0,     0,   269,     0,     0,  1285,
       0,     0,   271,   272,   273,     0,   274,   275,   276,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   277,   423,
       0,     0,     0,     0,     0,   279,     0,     0,     0,     0,
     365,     0,     0,     0,     0,     0,     0,   282,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,   268,     0,
    1306,     0,   269,     0,     0,     0,     0,     0,   271,   272,
     273,     0,   274,   275,   276,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   277,   423,     0,     0,     0,     0,
       0,   279,   211,   167,     0,  1333,   365,  1100,     0,   212,
     213,   214,     0,   282,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   422,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,   248,
     249,     0,     0,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,   256,     0,     0,     0,     0,     0,     0,     0,
       0,   257,    25,     0,   258,   211,   167,     0,  1493,     0,
       0,     0,   212,   213,   214,     0,     0,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   422,   233,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,   248,   249,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,   255,   256,     0,     0,     0,     0,
       0,     0,     0,     0,   257,    25,     0,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,     0,     0,
     269,     0,     0,     0,     0,     0,   271,   272,   273,     0,
     274,   275,   276,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   277,   423,     0,     0,     0,     0,     0,   279,
       0,     0,     0,     0,   365,     0,     0,     0,     0,     0,
       0,   282,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1392,     0,     0,     0,     0,   268,
       0,     0,     0,   269,     0,     0,     0,     0,     0,   271,
     272,   273,     0,   274,   275,   276,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,   423,     0,     0,     0,
       0,     0,   279,   211,   167,     0,  1557,   365,     0,     0,
     212,   213,   214,     0,   282,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   422,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,     0,     0,     0,     0,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,     0,     0,     0,     0,     0,   211,
     167,     0,   257,    25,     0,   258,   212,   213,   214,     0,
       0,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   422,   233,
     234,   235,   236,   237,   238,   239,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,   248,   249,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,   255,   256,
       0,     0,     0,     0,     0,     0,     0,     0,   257,    25,
       0,   258,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,   268,     0,     0,
       0,   269,     0,     0,  1395,     0,     0,   271,   272,   273,
       0,   274,   275,   276,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,   423,     0,     0,     0,     0,     0,
     279,     0,     0,     0,     0,   365,     0,     0,     0,     0,
       0,     0,   282,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,   268,     0,  1487,     0,   269,     0,     0,
       0,     0,     0,   271,   272,   273,     0,   274,   275,   276,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     423,     0,     0,     0,     0,     0,   279,   211,   167,     0,
       0,   365,  1611,     0,   212,   213,   214,     0,   282,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   422,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,   248,   249,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   256,     0,     0,
       0,     0,     0,   211,   167,     0,   257,    25,     0,   258,
     212,   213,   214,     0,     0,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   422,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,     0,     0,     0,     0,   250,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,   255,   256,     0,     0,     0,     0,     0,     0,
       0,     0,   257,    25,     0,   258,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,   268,     0,     0,     0,   269,     0,     0,  1488,     0,
       0,   271,   272,   273,     0,   274,   275,   276,     0,     0,
       0,   119,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   277,   423,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,   365,
    1941,     0,     0,     0,     0,     0,   282,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     7,     8,     0,     0,     0,     0,   268,     0,  1533,
       0,   269,     0,     0,     0,     0,     0,   271,   272,   273,
       0,   274,   275,   276,     0,     0,     0,   119,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   277,   423,     0,    43,    44,    45,    46,
     279,     0,    48,     0,     0,   365,     0,     0,     0,     0,
     768,    56,   282,     0,    59,   769,     0,   770,   771,     0,
     772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     7,     8,    43,    44,    45,    46,     0,
       0,    48,     0,    95,    96,    97,     0,     0,     0,   768,
      56,     0,     0,    59,   769,     0,   770,   771,     0,   772,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,    95,    96,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1034,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,   768,    56,     0,     0,    59,   769,     0,   770,   771,
       0,   772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1036,    80,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     7,     8,    43,    44,    45,    46,
       0,     0,    48,     0,    95,    96,    97,     0,     0,     0,
     768,    56,     0,     0,    59,   769,     0,   770,   771,     0,
     772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1235,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   768,    56,     0,     0,    59,   769,     0,   770,
     771,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1237,
      80,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     7,     8,    43,    44,    45,
      46,     0,     0,    48,     0,    95,    96,    97,     0,     0,
       0,   768,    56,     0,     0,    59,   769,     0,   770,   771,
       0,   772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1238,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   768,    56,     0,     0,    59,   769,     0,
     770,   771,     0,   772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1257,    80,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     7,     8,    43,    44,
      45,    46,     0,     0,    48,     0,    95,    96,    97,     0,
       0,     0,   768,    56,     0,     0,    59,   769,     0,   770,
     771,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1276,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,   768,    56,     0,     0,    59,   769,
       0,   770,   771,     0,   772,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1291,    80,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     7,     8,    43,
      44,    45,    46,     0,     0,    48,     0,    95,    96,    97,
       0,     0,     0,   768,    56,     0,     0,    59,   769,     0,
     770,   771,     0,   772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1325,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   768,    56,     0,     0,    59,
     769,     0,   770,   771,     0,   772,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1485,    80,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,    95,    96,
      97,     0,     0,     0,   768,    56,     0,     0,    59,   769,
       0,   770,   771,     0,   772,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,     0,     0,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2122,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,    -4,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,    -4,    -4,    -4,     0,   597,     0,     0,
      -4,    -4,     0,     0,     0,    -4,     0,  1659,     0,     0,
      -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,
       0,     0,     0,  2179,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     6,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,     7,     8,     0,     0,     0,     0,     0,
       0,    -4,     0,    -4,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     9,    10,    11,   597,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1660,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    14,
       0,     0,     0,     0,    15,    16,     0,     0,     0,    17,
       0,     0,     0,     0,    18,    19,    20,    21,    22,     0,
      23,    24,     0,    25,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,    42,    43,    44,    45,
      46,    47,     0,    48,     0,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,    65,    66,    67,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,    91,    92,     0,     0,     0,    93,     0,
       0,     0,     0,    94,    95,    96,    97,   167,   384,    98,
       0,    99,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   385,   386,   387,   388,   389,   390,   391,   392,
     393,     0,     0,     0,     0,   394,   395,   396,   397,   167,
     384,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   402,     0,   403,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   404,     0,     0,
     405,     0,     0,     0,   173,   415,   384,   174,     0,     0,
     175,     0,   176,     0,   385,   386,   387,   388,   389,   390,
     391,   392,   393,    46,     0,     0,     0,   394,   395,   396,
     397,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,   436,   384,   402,     0,   403,     0,     0,     0,     0,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   404,
       0,     0,   405,   394,   395,   396,   397,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,   403,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   404,     0,     0,   405,   394,
     395,   396,   397,     0,     0,     0,     0,   398,   399,   400,
     401,   406,   407,   408,     0,   402,     0,   403,     0,     0,
       0,     0,     0,   409,     0,     0,     0,   410,     0,   411,
     119,   404,     0,     0,   405,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1661,     0,
       0,     0,     0,   406,   407,   408,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   409,     0,     0,     0,   410,
       0,   411,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   406,
     407,   408,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   409,     0,     0,     0,   410,     0,   411,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   406,   407,   408,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   409,     0,     0,
       0,   410,     0,   411,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     7,     8,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,   768,    56,     0,     0,    59,   769,
       0,   770,   771,     0,   772,     0,     0,     0,  1046,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,  1047,     0,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,    95,    96,    97,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1807,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   768,    56,     0,     0,    59,
     769,     0,   770,   771,     0,   772,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,    95,    96,
      97,     0,     0,     0,     0,     0,  1928,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1929,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1961,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2033,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2090,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2091,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2106,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2140,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2167,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2172,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2173,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,     0,  1081,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,  1136,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,  1183,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
       0,     0,  1184,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,  1228,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,     0,     0,
    1260,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,  1274,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,  1281,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,  1339,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,  1359,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,     0,  1442,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,  1443,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,  1489,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
       0,     0,  1563,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,  1858,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,     0,     0,
    1869,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,  1908,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,  1982,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,  1998,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,  2010,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,     0,  2034,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,     0,     0,  2069,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,     0,     0,  2079,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
       0,     0,  2080,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
       0,  2104,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,     0,     0,
    2153,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,     0,     0,  2192,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,     0,     0,  2210,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,  2228,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,     0,     0,  2229,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,     0,   727,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,     0,   945,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,     0,
    1975,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,   754,     0,   755,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,  1008,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,  1057,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,  1207,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,  1275,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,  1277,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,     0,     0,  1283,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   726,   593,   594,   595,   596,     0,     0,
       0,     0,   597,     0,     0,     0,  1284,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     726,   593,   594,   595,   596,     0,     0,     0,     0,   597,
       0,     0,     0,  1374,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   726,   593,   594,
     595,   596,     0,     0,     0,     0,   597,     0,     0,     0,
    1388,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   726,   593,   594,   595,   596,     0,
       0,     0,     0,   597,     0,     0,     0,  1592,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,     0,     0,  1680,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   726,   593,
     594,   595,   596,     0,     0,     0,     0,   597,     0,     0,
       0,  1733,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   726,   593,   594,   595,   596,
       0,     0,     0,     0,   597,     0,     0,     0,  1920,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   726,   593,   594,   595,   596,     0,     0,     0,
       0,   597,     0,     0,     0,  1965,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   726,
     593,   594,   595,   596,     0,     0,     0,     0,   597,     0,
       0,     0,  1983,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   807,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   808,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   810,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   811,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   812,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   814,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   815,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   816,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   817,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   818,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   819,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   820,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   822,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   823,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   824,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   893,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   927,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   975,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   996,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,   998,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,   999,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1000,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1006,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1007,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1045,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1056,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1116,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1120,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1132,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1206,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1216,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1217,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1218,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1227,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1229,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1230,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1259,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1261,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1262,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1263,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1264,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1265,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1266,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1267,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1273,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1324,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1373,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1387,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1593,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1627,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1667,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1679,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1794,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1796,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1799,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1806,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1859,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1868,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  1893,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  1964,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  2031,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  2032,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597,     0,  2166,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   726,   593,   594,   595,   596,     0,     0,     0,     0,
     597,     0,  2207,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   726,   593,   594,   595,
     596,     0,     0,     0,     0,   597
};

static const yytype_int16 yycheck[] =
{
       3,   318,   636,   637,  1254,  1258,  1449,     3,    63,     6,
      69,    70,   159,    72,  1762,     4,  1764,     4,   751,  1718,
     199,     4,    25,     4,   757,     4,   446,   145,     5,   208,
      25,     5,     4,     4,  1944,     4,     4,   252,   253,     5,
       9,     4,     6,     5,  1749,   101,     6,     6,   109,     7,
     111,     6,    55,     6,     6,     4,   330,   142,   107,   107,
       4,     4,     9,   104,   120,     4,   107,     4,   109,     4,
       4,   145,     4,     9,   163,   349,   150,   151,   152,     7,
     258,    84,   131,   131,   145,    14,   264,    36,    37,     4,
      93,     6,    36,    37,     6,    98,     9,    36,    37,     0,
     189,     9,    36,    37,    36,    37,   109,   192,     6,  1814,
     104,   172,     7,   107,   108,   109,   205,   206,   243,   244,
     194,     9,     6,   302,   303,   304,   120,   243,   244,   255,
      93,   257,  1831,     9,   243,   244,   210,   243,   244,   264,
       6,     7,   145,   259,   418,     6,   420,   150,   151,   152,
     146,   260,   256,   243,   244,   429,   159,   107,   264,   109,
     264,   110,   111,   342,   343,   344,     6,   243,   244,     7,
       6,   110,   111,     7,   264,   178,   110,   111,   110,   111,
     359,   601,   107,   243,   244,     7,   101,   256,   264,  2099,
     184,   194,   255,   243,   244,   264,   199,   252,   253,   104,
     203,   255,   107,   257,   264,   208,   209,   210,   179,   180,
     181,   182,     7,   177,   264,   120,     7,   177,   243,   244,
     191,   255,   193,   194,   195,   196,   197,   243,   244,  1672,
     201,   202,   204,   204,   255,   243,   244,   200,   227,   264,
     227,   238,   239,   259,   243,   244,   227,     6,   227,   256,
     189,   190,   243,   244,   258,  1505,   264,   264,   227,   227,
     264,   264,   321,   322,   227,   264,     6,   256,   259,   258,
     329,   330,   259,  1972,   257,   278,   259,   255,   281,   282,
     263,   262,   259,   252,   253,   259,   255,   282,   257,   260,
     259,   259,   261,   259,   297,   298,   259,   259,   301,   302,
     303,   304,   255,   261,   259,     6,   259,   259,   255,   312,
     257,   731,   255,   316,   261,   318,   252,   253,   255,   255,
     255,   257,   258,  1056,  1057,   261,   259,   255,  2027,   257,
     263,   243,   244,   228,   229,   230,   231,   340,     4,   342,
     343,   344,   255,     6,   257,   765,   255,   255,   261,   257,
     259,   625,   426,   627,   628,    55,   359,   252,   253,   243,
     244,     6,   782,   366,   252,   253,   261,   255,   104,   257,
     644,   107,   792,   261,   435,   256,   252,   253,   557,   255,
     261,   257,   243,   244,   261,   261,  2134,   264,     4,   663,
     228,   229,   230,   231,   228,   229,   230,   231,   238,   239,
     547,   252,   253,   261,     4,   263,   228,   229,   230,   231,
     261,   243,   244,   687,   252,   253,   243,   244,   252,   253,
      36,    37,     6,   426,   427,   243,   244,   142,   431,   432,
     252,   253,   264,   228,   229,   230,   231,   228,   229,   230,
     231,   243,   244,   259,   447,   160,   264,   243,   244,     6,
     255,   454,   257,   727,   169,   170,   171,   243,   244,   264,
     175,   176,   264,   256,   107,   258,   259,   541,   264,   543,
    2169,   545,   546,   257,   477,   895,   243,   244,   264,   257,
     256,   147,   148,   149,   150,   559,   560,   153,   264,   142,
     256,   255,   243,   244,   110,   111,   162,   264,   264,   165,
     503,   101,   563,   142,   259,   105,   255,   160,   257,   209,
     259,   111,   112,   264,   114,   115,   169,   170,   171,  1962,
    2219,   160,   175,   176,   527,   243,   244,   256,   255,   258,
     169,   170,   171,   536,   537,   135,   175,   176,   541,   256,
     543,   544,   545,   546,   547,   260,   264,   264,   695,   552,
     243,   244,   255,   556,   557,   558,   559,   560,   561,   562,
     256,   564,   258,   566,   264,   142,   255,   562,   264,   564,
     256,   264,   258,   189,   190,   634,   635,   255,   264,   257,
     639,   243,   244,   160,   243,   244,   255,   243,   244,   592,
     259,   255,   169,   170,   171,   598,   256,   255,   175,   176,
     101,   301,   264,   104,   264,   264,   107,   260,   264,   255,
     252,   253,   312,   255,   255,   257,   316,   620,   621,   120,
     694,   260,   696,   697,   698,   699,   700,   701,   255,   703,
     704,   705,   706,   751,  1268,   709,   710,   711,  1058,   260,
     636,   637,   255,   264,   255,   255,   259,   708,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   669,   670,   671,   256,
     254,   674,   243,   244,   255,   949,   257,   264,   243,   244,
     255,   260,   257,   260,   255,   264,   261,   255,   259,   264,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   264,
     703,   704,   705,   706,   707,   255,   709,   710,   711,   712,
     713,   256,   142,   716,   255,   789,   771,   712,   256,   264,
     258,   243,   244,   255,   798,   728,   264,   256,   122,   258,
     160,   431,   432,   255,     4,   264,     6,   259,   741,   169,
     170,   171,  1475,     6,   805,   175,   176,   447,   101,   259,
     109,   104,   104,   756,   107,   107,   109,   109,     6,   762,
     243,   244,   245,   246,   247,   248,   249,   120,   120,   255,
    1190,   254,  1192,   252,   253,   778,   779,   255,   259,   259,
     259,   784,   256,   786,   258,  1205,   789,   790,     8,   256,
     264,   258,   259,   796,   107,   798,   245,   246,   247,   248,
     249,   248,   249,   255,   104,   254,   924,   254,   252,   253,
     255,   255,   104,   257,  1234,   259,   147,   148,   147,   148,
     259,   259,   153,   259,   153,   828,   260,   830,   252,   253,
     264,   255,   260,   257,   260,  1568,   264,   260,   264,   260,
       4,   264,     3,   264,   544,  1578,   260,   260,   260,   260,
     264,   264,   264,   264,   107,   260,   556,   260,   558,   264,
     260,   264,   865,   260,   264,   260,    27,   264,   104,   264,
    2123,     4,   875,   107,  1294,  1295,   937,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   952,   897,   107,     4,   254,   260,  1319,
     959,    62,   264,     4,   963,  2155,  1326,     6,   255,   260,
     913,   260,   260,   264,   260,   264,   264,   260,   264,   260,
     255,   264,   925,   264,  1042,  1345,   260,  2180,   260,   255,
     264,   934,   264,   260,   255,   255,   260,   264,  1056,  1057,
     264,   260,   945,     6,   260,   264,   260,  2197,   264,   257,
     264,     6,  1372,   114,   260,  1073,   260,   260,   264,   260,
     264,   264,   259,   264,   260,   260,  1386,   260,   264,   264,
     260,   264,   260,  1393,   264,   260,   264,   260,   260,   264,
     255,   264,   264,   260,   145,   263,   257,   264,   260,   150,
     151,   152,   264,   260,   259,     6,   260,   264,   159,  1060,
     264,   260,   260,   260,   260,   264,   264,   264,   264,   263,
     255,  1085,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
       9,   260,  1349,   194,   254,   264,   255,   255,   260,   260,
     260,   741,   264,   264,   255,   255,   260,   260,  1051,   210,
     264,   264,   255,   260,  1113,   260,  1059,   264,   260,   264,
     255,   260,   264,   259,  1067,   264,   192,   192,   192,  1703,
    1704,   259,   131,   255,   255,   255,   255,  1080,   192,   255,
     255,   259,  1085,   255,   255,   259,     4,     5,  1206,  1207,
     251,   259,     4,   259,   259,   255,   259,   255,   255,   255,
    1174,  1175,   255,   255,   255,   266,   267,     6,   257,     6,
       6,  1114,  1115,   259,  1117,  1118,  1119,   259,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,   259,   259,
    1133,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     259,   257,   257,     6,    62,    63,    64,    65,   257,     6,
     192,   255,    70,    71,    72,    73,   259,   255,   255,   255,
      78,   255,    80,   255,   257,     6,     6,     6,   259,     6,
    1173,  1174,  1175,     8,     8,   255,    94,   259,     7,    97,
       6,   259,   259,   101,     6,   259,   104,   260,    96,   107,
     256,   109,   264,   264,  1197,     7,     6,   897,     6,   256,
     261,   259,   120,   259,   254,   259,   259,    67,     8,     7,
    1213,  1214,  1215,     7,   255,     6,   256,     6,   189,     7,
     138,   259,     6,   260,     7,     6,     6,   259,  1302,   260,
     260,   258,  1306,   256,   934,     6,   261,   259,     7,     6,
     257,  1315,   255,  1317,   259,     6,  1320,     6,     6,     6,
       6,   256,     7,   257,  1571,  1373,  1374,     7,     7,     7,
       7,     7,     7,     7,     7,   426,  1269,     7,     7,     7,
       7,     7,  1268,     7,     7,   436,   259,     6,   256,   264,
     264,   258,  1556,  1286,  1287,  1288,  1560,   260,   264,   264,
     208,   209,   210,   256,  1297,     7,   260,   458,     7,  1302,
    1374,   261,   220,  1306,   259,   259,   224,     4,   226,   227,
       6,   261,  1315,   260,  1317,   260,   259,  1320,   142,     7,
       6,   261,     7,     7,     7,   256,   256,   264,   264,     9,
     264,   256,   258,  1336,   261,  1396,   192,  1398,   256,   263,
     258,   259,     7,   163,  1978,   260,  1349,     6,  1768,   259,
       6,  1051,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,     6,   261,  1067,    49,   254,
      49,  1374,   255,   259,   255,   259,  1379,   255,  1381,   261,
     541,   261,   543,   255,   545,   546,   547,     7,     7,     7,
     264,   192,   256,     7,     7,  1398,     7,     6,   559,   560,
       7,   256,   264,     7,     7,     7,     7,  1410,   119,     4,
     259,  1414,     6,   255,  1114,  1115,     7,  1117,  1118,  1119,
       6,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,     7,  1579,  1580,     7,     7,     7,     7,     7,     7,
     259,   101,     6,     6,     6,  1504,   107,     7,     7,     6,
    1568,     6,     4,   262,   256,     6,   259,   264,   264,  1776,
     259,     6,   259,     6,   260,     7,  1469,  1470,  1471,     6,
     257,     6,     6,  1173,  1477,  1478,  1479,   255,   255,     6,
     259,   642,     6,     6,   260,     6,   261,     6,   258,     6,
    1551,   264,  1495,   135,     6,     6,     6,  1197,     6,     6,
       6,     6,     6,  1506,     6,   666,     6,     6,     6,     5,
       7,  1514,     6,  1213,   256,  1518,     6,     4,     6,   260,
       6,   256,     7,     6,     6,     6,     6,   259,   259,  1603,
     257,   259,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   259,   703,   704,   705,   706,   259,     6,   709,   710,
     711,   259,  1613,   259,   259,   259,   259,   259,   719,   259,
    1678,   722,   188,     6,   259,   264,   264,   256,  1571,  1269,
     264,  1630,   259,   264,   735,     6,  1579,  1580,     7,   261,
     255,   259,  1585,     6,     6,     6,  1286,  1287,  1288,   260,
       6,   255,     4,   255,     7,     6,     6,     6,     6,     6,
    1603,   142,   105,     5,   259,   256,   264,   259,     6,   770,
    1613,   772,   259,     6,   142,  1618,   142,     6,   264,     6,
       6,     6,   256,     6,   264,   264,     6,     6,   789,   264,
     259,   259,  1779,     6,     6,     6,  1336,   798,  1699,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,     6,     6,     5,     7,   254,   259,
    1719,  1720,  1721,  1722,  1723,  1724,   259,   146,     8,     6,
    1744,   259,   259,  1747,   256,     6,     6,     6,   259,   259,
       6,  1742,   260,   260,     7,   259,     6,  1690,  1749,  1750,
       6,   256,  1695,  1696,   187,     7,     6,  2014,  1398,   260,
       6,     6,   260,     6,   260,     6,   259,  1703,  1704,  1770,
    1410,   261,     6,  1987,  1414,  1718,     6,     6,     6,     6,
     260,  1724,     6,   256,   190,     6,  1729,   259,   259,     6,
     260,   260,     6,  1736,   259,   255,     6,   259,   256,     6,
       6,  1744,   142,   259,  1747,   259,     6,   260,     6,     6,
     259,     6,     6,     6,     6,     6,     6,     6,   259,     6,
       6,   256,  1765,     6,     6,     6,  1769,     6,   260,  1469,
    1470,  1471,     6,  1776,     6,  1778,  1779,  1477,  1478,  1479,
       6,     6,   260,   259,   259,   259,  1385,   948,  2136,   950,
     951,  1945,  1444,  1905,  1625,  1495,  1686,   474,     3,     3,
    1409,  1069,     3,   964,     3,  1974,  1506,  1548,   613,     3,
    2084,  1814,  1769,    -1,  1514,  1580,    -1,   789,  1749,    -1,
      -1,    -1,    -1,   984,    -1,    -1,    -1,    -1,  1831,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1842,
    1843,    -1,  1003,    -1,    -1,    -1,  1907,    -1,    -1,    -1,
    2124,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1867,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1879,    -1,    -1,  1040,
      -1,    -1,    -1,    -1,    -1,  1585,    -1,    -1,    -1,  1950,
      -1,  1894,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,  1613,   254,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,  1085,    -1,    -1,    -1,  1931,    -1,
      -1,    -1,  1991,  1992,  1993,  1994,  1995,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,    -1,    -1,    -1,    -1,  1951,    -1,
      -1,  1954,  1955,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1972,
      -1,    -1,  1975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1978,  1986,    -1,    -1,    -1,  1990,    -1,    -1,
    1690,    -1,    -1,    -1,    -1,    -1,  2055,    -1,    -1,    -1,
    2059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2014,    -1,  1174,  1175,    -1,    -1,    -1,  1718,    -1,
      -1,    -1,    -1,    -1,  2027,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1736,    -1,    -1,  2100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2110,    -1,  2056,    -1,  2114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1765,    -1,    -1,    -1,    -1,
      -1,  2130,    -1,    -1,    -1,  1236,    -1,    -1,  1778,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,     6,   256,  2108,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2175,  2176,    -1,    -1,
      -1,    -1,    -1,  2126,  2127,  2128,  2129,  2130,    -1,    -1,
      -1,  1831,  2206,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1302,    -1,    -1,    -1,  1306,    -1,    -1,    -1,    -1,
      -1,  2225,  2226,    -1,  1315,    -1,  1317,    -1,    -1,  1320,
      -1,    -1,    -1,    -1,  2238,    -1,  2169,  1867,    -1,  1330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2185,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,  2206,    -1,   254,    -1,   256,    -1,    -1,
      -1,    -1,    -1,  1374,    -1,    -1,  2219,    -1,    -1,    -1,
      -1,    -1,  2225,  2226,    -1,     6,    -1,   118,    -1,    -1,
      -1,  1931,    -1,    -1,    -1,  2238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1946,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,   154,    -1,    -1,    -1,     6,    -1,    -1,
      -1,   162,  1972,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1986,    -1,   179,   180,
     181,    -1,   183,   184,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,    -1,   195,   196,   197,   198,    -1,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2027,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,  2056,    -1,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,   277,   278,   279,   280,
     281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   296,   297,   298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1579,  1580,
      -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   324,   325,    -1,    -1,    -1,    -1,   330,
      -1,    -1,  1603,    -1,    -1,    -1,    -1,    -1,    -1,   340,
     341,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,  2169,
      -1,    -1,    -1,   254,   365,   366,    -1,    -1,    -1,   370,
     371,   372,    -1,   374,    -1,    -1,    -1,   378,   379,   380,
      -1,    -1,   383,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,  2219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   423,    -1,    -1,    -1,   427,   428,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,   445,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   459,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1744,    -1,    -1,  1747,    -1,   479,    -1,
      -1,    -1,    -1,   484,    -1,    -1,    -1,   488,    -1,    -1,
      -1,  1762,    -1,  1764,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   502,   503,    -1,    -1,    -1,   507,    -1,  1779,    -1,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,    -1,   539,   540,
      -1,   542,    -1,  1814,    -1,    -1,    -1,    -1,   203,    -1,
     551,    -1,    -1,   554,   555,    -1,    -1,    -1,    -1,    -1,
     561,    -1,    -1,    -1,    -1,   566,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,    -1,   599,   600,
      -1,    -1,    -1,    -1,     6,    -1,   607,   608,   609,    -1,
      -1,    -1,    -1,    -1,   615,   616,   617,   618,    -1,   620,
     621,    -1,    -1,   278,    -1,    -1,   281,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   639,   640,
     641,    -1,   297,   298,   645,   646,   647,   648,   649,   650,
     651,   652,   653,    -1,    -1,    -1,    -1,    -1,   659,   660,
       6,   662,    -1,    -1,   665,    -1,    -1,    -1,   669,   670,
     671,   672,    -1,   674,   675,   676,   677,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   366,    -1,    -1,   142,   716,    -1,    -1,    -1,    -1,
      -1,    -1,   723,   724,    -1,   726,    -1,    -1,   729,   730,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   738,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,   756,    -1,   758,    -1,    -1,
      -1,    -1,   763,   764,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   427,    -1,    -1,    -1,    -1,   778,    -1,   780,
     781,    -1,    -1,   784,    -1,   786,   787,    -1,    -1,    -1,
     791,    -1,   793,    -1,    -1,    -1,    -1,  2068,   799,    -1,
      -1,    -1,   803,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,   826,   254,   828,    -1,   830,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   503,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2134,   865,    -1,    -1,    -1,   203,    -1,
      -1,    -1,   527,    -1,   875,   876,   877,    -1,    -1,    -1,
      -1,   536,   537,    -1,    -1,  2156,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,   561,    -1,   254,    -1,
      -1,   566,   913,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   925,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   933,    -1,    -1,  2206,   937,   592,    -1,    -1,
      -1,    -1,    -1,    -1,   945,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   953,   954,  2225,  2226,    -1,    -1,   959,    -1,
      -1,    -1,   297,   298,    -1,   620,   621,  2238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   976,    -1,    -1,   979,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,  1002,   254,  1004,  1005,   340,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   669,   670,   671,    -1,    -1,   674,
      -1,    -1,  1023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1047,    -1,    -1,    -1,
      -1,    -1,    -1,  1054,    -1,    -1,    -1,    -1,    -1,    -1,
    1061,   716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1074,  1075,    -1,    -1,    -1,    -1,  1080,
       6,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,   427,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,   756,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
    1111,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,   778,    -1,    -1,    -1,    94,    -1,   784,
      97,   786,  1133,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,  1149,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,  1159,  1160,
    1161,  1162,  1163,    -1,    -1,    -1,    -1,  1168,  1169,    -1,
    1171,   138,    -1,   828,     6,   830,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1185,  1186,    -1,    -1,    -1,    -1,
      -1,    -1,  1193,  1194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1202,  1203,    -1,    -1,    -1,    -1,  1208,  1209,    -1,
     865,    -1,    -1,  1214,  1215,    -1,    -1,    -1,    -1,    -1,
     875,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   210,    -1,    -1,    -1,  1248,    -1,    -1,
      -1,    -1,    -1,   220,    -1,    -1,    -1,   224,   913,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     925,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1285,   620,   621,    -1,    -1,    -1,
     945,    -1,   259,    -1,    -1,    -1,  1297,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1305,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,  1327,  1328,   254,    -1,
      -1,  1332,    -1,    -1,   669,   670,   671,    -1,    -1,   674,
      -1,    -1,  1343,    -1,    -1,  1346,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,     6,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,  1375,    -1,    -1,  1378,  1379,  1380,
    1381,   716,    -1,    -1,    -1,    -1,    -1,    -1,  1389,    -1,
      -1,  1392,     6,  1394,  1395,  1396,    -1,    -1,  1399,  1400,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    -1,
      -1,   756,   254,    -1,    -1,  1080,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   778,    -1,    -1,    -1,    -1,    -1,   784,
      -1,   786,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,  1476,    -1,    -1,  1133,    -1,
      -1,    -1,    -1,    -1,    -1,  1486,  1487,  1488,    -1,    -1,
      -1,    -1,    -1,    -1,  1495,    -1,  1497,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1518,    -1,    -1,
      -1,    -1,    -1,  1524,  1525,    -1,    -1,    -1,    -1,    -1,
     865,    -1,  1533,  1534,  1535,    -1,    -1,    -1,    -1,    -1,
     875,    -1,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1554,    -1,    -1,    -1,    -1,    -1,  1214,
    1215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1575,    -1,    -1,    -1,   913,    -1,
      -1,    -1,  1583,  1584,    -1,    -1,    -1,    -1,    -1,    -1,
     925,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     945,    -1,    -1,   254,    -1,    -1,    -1,  1618,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,  1297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1659,  1660,
    1661,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1670,
      -1,    -1,    -1,    -1,  1675,  1676,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,    -1,    -1,  1695,  1696,  1697,    -1,  1699,    -1,
      -1,    -1,    -1,    -1,  1705,  1706,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1724,  1379,    -1,  1381,    -1,  1729,  1730,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1742,    -1,    -1,  1745,  1080,    -1,    -1,  1749,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1758,  1759,    -1,
    1761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1771,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,  1790,
    1791,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1133,    -1,
      -1,    -1,    -1,  1804,    -1,    -1,  1807,  1808,    -1,  1810,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,  1842,  1843,    -1,    -1,    78,    -1,    80,  1849,  1850,
      -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,
    1861,    94,    -1,  1518,    97,    -1,    -1,    -1,   101,  1870,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,  1879,  1214,
    1215,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,  1890,
    1891,    -1,    -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,  1928,  1929,   254,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,  1949,    -1,
      -1,    -1,   254,  1954,  1955,  1956,    -1,    -1,   552,    -1,
    1961,    -1,  1297,  1618,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1975,   208,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,  1990,
      -1,   224,    -1,   226,   227,    -1,    -1,    -1,  1999,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,
     253,    -1,    -1,  2024,    -1,    -1,   259,    -1,   261,  2030,
      -1,    -1,  2033,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1695,  1696,    -1,    -1,  1379,    -1,  1381,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2064,    -1,    -1,    -1,    -1,    -1,  1724,
      -1,    -1,    -1,    -1,  1729,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2090,
    2091,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2105,  2106,    -1,  2108,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2121,    -1,    -1,    -1,    -1,  2126,  2127,  2128,  2129,  2130,
      -1,    -1,    -1,    -1,    -1,  2136,    -1,    -1,    -1,  2140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2167,    -1,    -1,    -1,
       6,  2172,  2173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1518,  2185,    -1,    -1,  1842,  1843,    -1,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,  2212,  2213,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1879,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1894,
      -1,   835,   836,   837,   838,   839,   840,   841,   842,   843,
     844,   845,    -1,   847,   848,   849,   850,    -1,   852,   853,
     854,   855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   868,    -1,   870,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,    -1,    -1,
      -1,    -1,    -1,   887,   888,    -1,    -1,    -1,    -1,  1954,
    1955,    -1,   896,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1990,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
    1695,  1696,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    28,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,  1729,   254,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,  1009,  1010,  1011,   254,    -1,
      -1,  1015,  1016,    -1,    -1,  1019,  1020,  1021,  1022,    -1,
    1024,    -1,    -1,    -1,    -1,  1029,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2108,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2126,  2127,  2128,  2129,  2130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1842,  1843,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1110,    -1,  1112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1894,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   269,   270,    -1,    -1,  1211,    -1,  1954,
    1955,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
    1975,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,  1990,   131,   132,    -1,    -1,
     135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,
     386,   387,    -1,    -1,    -1,   391,   392,   393,   394,   395,
     396,   397,     7,   399,    -1,    -1,    -1,    -1,   404,   405,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1355,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,
      -1,    -1,    -1,  2108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    13,    14,    -1,    -1,
      -1,  2126,  2127,  2128,  2129,  2130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1397,    -1,    -1,    -1,    -1,    -1,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,   256,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,   264,    -1,    -1,    -1,  1439,  1440,    -1,    -1,    -1,
    2185,  1445,    -1,  1447,    -1,    -1,    -1,  1451,    -1,    -1,
    1454,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1465,    -1,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,   574,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1539,    -1,  1541,    -1,    -1,
      -1,  1545,    -1,  1547,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,  1579,    -1,    -1,    -1,   254,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   260,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     8,    -1,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,  1677,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
     133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,
      -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,
     153,   154,   155,   156,   157,   158,    -1,    -1,    -1,   162,
      -1,    -1,   165,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1781,    -1,    -1,
    1784,    -1,    -1,    -1,   207,   208,   209,   210,   211,   212,
      -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,   891,    -1,   250,  1832,  1833,
      -1,  1835,   255,    -1,    -1,    -1,   259,     8,    -1,   262,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   924,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,   260,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,  1898,  1899,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,  1947,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,
      -1,   136,    -1,   138,    -1,    -1,   141,    -1,  1104,    -1,
      -1,    -1,   147,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,
     165,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   208,   209,   210,   211,   212,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
       8,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1198,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,   259,    -1,    -1,   262,    -1,    -1,
      -1,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
       3,     4,     5,   254,     7,   256,    -1,    10,    11,    12,
    2194,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
    1356,  1357,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,  1449,   207,   208,   209,   210,   211,    -1,
      -1,    -1,  1458,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,   228,   229,   230,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,    -1,   252,
     253,    -1,   255,    -1,   257,     3,     4,     5,   261,   262,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,  1617,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,   256,    -1,   258,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,   259,    -1,     8,   262,    10,    11,    12,    -1,    -1,
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
     255,     3,     4,     5,    -1,   260,    -1,   262,    10,    11,
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
     259,   260,    -1,   262,    10,    11,    12,    -1,    -1,    15,
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
       3,     4,    -1,   259,    -1,    -1,   262,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
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
       4,    -1,    -1,   260,    -1,   262,    10,    11,    12,    -1,
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
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
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
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,   259,    -1,     8,   262,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   250,     3,     4,    -1,    -1,
     255,     8,    -1,    10,    11,    12,    -1,   262,    15,    16,
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
      -1,    -1,    -1,   250,     3,     4,    -1,    -1,   255,    -1,
      -1,    10,    11,    12,    -1,   262,    15,    16,    17,    18,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
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
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,
       3,     4,    -1,   259,    -1,    -1,   262,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,
      -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,
     223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,
       5,    -1,   255,    -1,    -1,    10,    11,    12,    -1,   262,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    -1,    97,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   208,   209,   210,   211,    -1,    -1,    -1,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,   259,    -1,    -1,   262,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,     3,     4,     5,   259,
      -1,    -1,   262,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,
      97,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   208,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,   259,    -1,    -1,   262,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,
      -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,     3,
       4,    -1,    -1,   255,    -1,    -1,    10,    11,    12,    -1,
     262,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,   255,    -1,    -1,    -1,   259,    -1,    -1,   262,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,   264,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,     3,     4,
      -1,   259,    -1,     8,   262,    10,    11,    12,    -1,    -1,
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
     255,    -1,    -1,    -1,    -1,    -1,    -1,   262,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
     264,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,
      -1,   250,     3,     4,    -1,     6,   255,   256,    -1,    10,
      11,    12,    -1,   262,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,    -1,    -1,
      -1,    -1,   250,     3,     4,    -1,     6,   255,    -1,    -1,
      10,    11,    12,    -1,   262,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    92,    93,    -1,    95,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,   207,    -1,    -1,
      -1,   211,    -1,    -1,   264,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,   262,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,   264,    -1,   211,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,    -1,    -1,    -1,    -1,   250,     3,     4,    -1,
      -1,   255,   256,    -1,    10,    11,    12,    -1,   262,    15,
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
      -1,   227,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,   255,
     256,    -1,    -1,    -1,    -1,    -1,   262,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    13,    14,    -1,    -1,    -1,    -1,   207,    -1,   264,
      -1,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   243,   244,    -1,   117,   118,   119,   120,
     250,    -1,   123,    -1,    -1,   255,    -1,    -1,    -1,    -1,
     131,   132,   262,    -1,   135,   136,    -1,   138,   139,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    13,    14,   117,   118,   119,   120,    -1,
      -1,   123,    -1,   184,   185,   186,    -1,    -1,    -1,   131,
     132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   159,
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
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,   184,   185,
     186,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    67,    68,    69,    -1,   254,    -1,    -1,
      74,    75,    -1,    -1,    -1,    79,    -1,   264,    -1,    -1,
      84,    85,    86,    87,    88,    -1,    90,    91,    -1,    93,
      -1,    -1,    -1,   260,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,   116,   117,   118,   119,   120,   121,    -1,   123,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,   143,
     144,   145,    -1,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,   172,   173,
     174,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,   183,
     184,   185,   186,    -1,    -1,   189,    -1,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,     4,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   225,    -1,   227,    -1,    -1,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,    46,    47,    48,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    -1,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   116,   117,   118,   119,
     120,   121,    -1,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,   143,   144,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,   172,   173,   174,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   183,   184,   185,   186,     4,     5,   189,
      -1,   191,    -1,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,   227,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,     4,
       5,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,   101,     4,     5,   104,    -1,    -1,
     107,    -1,   109,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   120,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,   138,     5,    78,    -1,    80,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    94,
      -1,    -1,    97,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    94,    -1,    -1,    97,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,   208,   209,   210,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,   220,    -1,    -1,    -1,   224,    -1,   226,
     227,    94,    -1,    -1,    97,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
      -1,    -1,    -1,   208,   209,   210,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,   224,
      -1,   226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,    -1,    -1,    -1,   224,    -1,   226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,
      -1,   224,    -1,   226,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    13,    14,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,   163,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   184,   185,   186,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,   264,   232,   233,   234,
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
     255,   255,   255,     4,   259,   365,   378,     4,   255,   255,
     255,     6,     6,   257,     5,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    62,    63,    64,    65,    70,    71,
      72,    73,    78,    80,    94,    97,   208,   209,   210,   220,
     224,   226,   369,   378,   255,     4,   369,     5,   259,     5,
     259,   313,    32,   244,   348,   378,   257,   259,   255,   259,
       6,   255,   259,     6,   263,     7,   138,   200,   228,   229,
     230,   231,   252,   253,   255,   257,   261,   287,   288,   289,
     313,   348,   368,   369,   378,     4,   317,   318,   319,   259,
       6,   348,   368,   369,   378,   368,   368,   348,   368,   375,
     376,   378,   348,   294,   298,   255,   357,     9,   369,   255,
     378,   348,   348,   348,   255,   348,   348,   348,   255,   348,
     348,   348,   348,   348,   348,   348,   368,   348,   348,   348,
     348,   362,   255,   244,   348,   363,   364,   259,   362,   361,
     368,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   255,   257,   289,   289,
     289,   289,   289,   289,   255,   289,   289,   255,   313,   314,
     314,   289,   289,     5,   259,   259,   131,   313,   313,   255,
     289,   289,   255,   255,   255,   348,   259,   348,   363,   348,
     348,   260,   364,   355,   378,   192,     5,   259,     8,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   254,     9,   255,
     257,   261,   288,   289,   348,   364,   364,   255,   255,   255,
     361,   362,   362,   362,   312,   255,   259,   255,   255,   361,
     259,   259,   348,     4,   361,   259,   365,   259,   259,   358,
     358,   358,   348,   348,   243,   244,   259,   259,   358,   243,
     244,   255,   319,   358,   259,   255,   259,   255,   255,   255,
     255,   255,   255,   255,   364,   348,   362,   362,   362,   255,
     259,     4,   257,   259,     6,   257,   319,     6,     6,   259,
     259,   259,   259,   362,   259,   257,   257,   257,   348,     8,
       6,     6,   348,   348,   348,   261,   348,   259,   192,   348,
     348,   348,   348,   289,   289,   289,   255,   255,   255,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   255,
     255,   289,   255,   257,     6,     6,   259,     6,     8,   319,
       6,     8,   319,   255,   289,   348,   245,   259,     9,   255,
     257,   261,   368,   364,   348,   319,   361,   361,   259,   369,
     313,     7,   348,   348,     4,    36,    37,   110,   111,   189,
     190,   291,   361,     6,   256,   258,   259,   290,   259,     6,
     259,     6,     9,   255,   257,   261,   378,   260,   131,   136,
     138,   139,   141,   311,   313,   348,     6,   256,   264,     9,
     255,   257,   261,   256,   264,   256,   264,   264,   256,   264,
       9,   255,   261,   264,   258,   264,   293,   258,   293,    96,
     356,   354,   378,   264,   348,   264,   256,   256,   256,   348,
     256,   256,   256,   348,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   260,     7,   348,   245,   260,
     264,   348,     6,     6,   256,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   363,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   363,   363,   378,   259,   348,   348,   368,   348,
     368,   361,   368,   368,   375,   259,   259,   259,   348,   290,
     378,     8,   348,   348,   362,   361,   368,   368,   363,   355,
     369,   355,   364,   256,   260,   261,   289,    67,     8,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   259,   348,   363,   348,   348,   348,   348,
     348,   378,   348,   348,   291,   259,   290,   256,   260,   260,
     348,   348,   348,     7,     7,   341,   341,   255,   348,   348,
     348,   348,     6,   364,   364,   259,   256,     6,   319,   259,
     319,   319,   264,   264,   264,   358,   358,   318,   318,   264,
     348,   260,   332,   264,   319,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   260,   256,     7,   342,     6,     7,
     348,   348,     6,   348,   319,   348,   260,   364,   364,   364,
     348,     6,   364,   348,   348,   348,   256,   260,   256,   256,
     256,   189,   264,   319,   259,     8,   256,   256,   258,   375,
     368,   375,   368,   368,   368,   368,   368,   368,   348,   368,
     368,   368,   368,   262,   371,   378,   369,   368,   368,   368,
     355,   378,   364,   260,   260,   260,   260,   348,   348,   348,
     319,   378,   291,   258,   260,   256,   145,   163,   336,   256,
     260,   264,   348,     6,   259,   361,   256,   258,   261,     7,
       7,   287,   288,     6,   364,     7,   231,   287,   348,   272,
     378,   348,   348,   291,   257,   255,   131,   313,   314,   313,
     259,   260,     6,   238,   239,   269,   364,   378,   348,   348,
     291,     6,   364,     6,   364,   348,     6,   368,   376,   378,
     256,   291,   348,     6,   378,     6,   368,   348,   256,   257,
     348,   264,   369,     7,     7,     7,   256,     7,     7,     7,
     256,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   348,   256,   259,   348,   363,   260,     6,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   264,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   264,
     264,   264,   264,   264,   256,   258,   258,   364,   264,   264,
     290,   264,   290,   264,   264,   264,   256,   364,   348,   348,
     350,   290,   260,   260,   260,   264,   264,   290,   290,   256,
     261,   256,   261,   264,   289,   351,   260,     7,   291,   290,
     361,   260,     8,     8,   364,   261,   256,   258,   255,   257,
     288,   289,   364,     7,   259,   259,   256,   256,   256,   348,
     361,     4,   340,     6,   307,   348,   369,   256,   260,   256,
     256,   260,   260,   364,   261,   260,   319,   260,   260,   358,
     348,   348,   260,   260,   348,   358,   142,   142,   160,   169,
     170,   171,   175,   176,   333,   334,   358,   260,   329,   256,
     260,   256,   256,   256,   256,   256,   256,   256,   259,     7,
     348,     6,   348,   256,   260,   258,   260,   258,   260,   260,
     260,   260,   260,   258,   258,   264,     7,     7,     7,   261,
     348,   260,   348,   348,     7,   261,   290,   264,   290,   290,
     256,   256,   264,   290,   290,   264,   264,   290,   290,   290,
     290,   348,   290,     9,   370,   264,   256,   264,   290,   261,
     264,   352,   258,   260,   256,   260,   261,   255,   257,   263,
     192,     7,   163,     6,   348,   260,   259,     6,   361,   260,
     348,     6,     7,   287,   288,   261,   287,   288,   291,   259,
     366,   378,   369,   348,     6,   260,    49,    49,   361,   260,
       4,   179,   180,   181,   182,   260,   275,   279,   282,   284,
     285,   327,   261,   256,   258,   255,   348,   348,   255,   259,
     255,   259,     8,   364,   368,   256,   261,   256,   258,   255,
     256,   256,   264,   261,   255,   264,     7,   289,     4,    36,
      37,   301,   302,   303,   290,   348,   290,   358,   361,   361,
       7,   361,   361,   361,     7,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,     6,     7,   364,   348,   348,
     348,   348,   348,   348,   260,   348,   348,   348,   361,   368,
     368,   260,   260,   260,   264,   300,   348,   348,   291,   291,
     348,   348,   256,   361,   289,   348,   348,   260,   291,   288,
     261,   288,   348,   348,   290,   260,   361,   364,   364,     7,
       7,     7,   142,   339,     6,   256,   264,     7,     7,     7,
       7,     7,   260,     4,   291,   260,   264,   264,   264,   260,
     260,   119,     4,     6,   348,   259,     6,   255,     6,   177,
       6,   177,   260,   334,   264,   333,     7,     6,     7,     7,
       7,     7,     7,     7,     7,   318,   361,     6,   259,   101,
       6,     6,     6,   107,     7,     7,     6,     6,   348,   361,
     361,   361,     4,   264,     8,     8,   256,   291,   291,   364,
     368,   348,   368,   262,   264,   304,   368,   368,   291,   368,
     256,   264,     6,   291,   259,   313,   259,     6,   348,     6,
     259,   361,   260,   260,   348,     6,   189,   190,   291,   348,
       6,     7,   365,   367,     6,   257,     6,     6,   290,   289,
     289,     6,   276,   255,   255,   259,   286,     6,   291,   261,
     368,   348,   258,   256,   348,     8,   364,   348,   364,   260,
     260,     6,     6,   269,   291,   261,   348,     6,     6,   348,
     291,   256,   348,   259,   348,   369,   290,    49,   259,   361,
     369,   372,   348,   348,   258,   264,     6,   256,     6,     6,
     135,   309,   309,   361,     6,     6,     6,   361,   142,   192,
     308,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   260,   290,   290,   290,   290,   290,   290,   290,   264,
     264,   264,   256,   290,   290,   302,   290,   256,   290,   256,
     289,   351,   290,     6,   290,   255,   257,   289,   291,   256,
     258,   290,     6,   260,   260,   361,   361,   361,     4,     6,
     287,   348,   361,   361,   361,   259,   259,     7,     6,     7,
     348,   348,   348,   259,   259,   259,   257,     6,   348,   361,
     348,     6,     6,   348,   358,   260,     5,   361,   259,   259,
     259,   259,   259,   259,   259,   361,   260,     6,   364,   259,
     259,   348,   348,   258,     6,     6,   188,   348,   348,   348,
       6,     6,     7,   290,   264,   264,   290,   264,   348,     4,
     204,   305,   306,   290,   256,   290,   352,   369,   255,   257,
     348,   259,   319,     6,   319,   264,     6,     6,   261,     7,
       7,   287,   288,     6,   365,   260,   264,   348,   287,   259,
     290,   373,   374,   375,   373,   255,   348,   348,   360,   361,
     259,   255,     4,     6,   256,     6,   256,   260,   260,   256,
     260,     6,     6,   368,   255,     4,   256,   264,   255,   260,
     264,   361,   369,     7,   289,   299,   348,   363,   303,     6,
     358,     6,     6,     6,   142,   310,   101,   120,   105,     6,
       5,   259,   348,   348,   348,   348,   256,   351,   348,   348,
     290,   288,   259,   259,     6,   308,     6,   348,   361,   142,
     142,     4,     6,   364,   364,   348,   348,   369,   260,   256,
     260,   264,   318,   318,   348,   348,   260,   264,   256,   260,
     264,     6,     6,   360,   358,   358,   358,   358,   358,   244,
     358,     6,   260,   364,   348,     6,     6,     6,   361,   260,
     264,     8,   260,   256,   259,   348,   369,   368,   348,   368,
     348,   369,   372,   374,   369,   264,   256,   264,   260,   348,
     336,   336,   361,   291,   366,   369,   348,     6,     6,   365,
     258,   361,   375,     6,   290,   290,   273,   348,   264,   264,
     260,   264,   274,   348,   348,     6,     6,     6,     6,   348,
     348,   256,     6,   348,   295,   297,   259,   374,   260,   264,
       7,     7,   146,     6,   259,   259,   259,     5,   360,   290,
     290,   264,   290,   256,   256,   258,   364,   364,     6,     6,
     348,   348,   259,   260,   260,   259,     6,     6,   259,   348,
     260,   260,   260,   258,     6,   361,     7,   259,   348,   260,
     264,   264,   264,   264,   264,   264,     6,   260,   260,   187,
     348,   348,   364,     6,     6,   256,   290,   290,   306,   369,
     260,   260,   260,   260,     7,     6,     6,     6,   261,     6,
     260,     6,     6,   256,   264,   348,   348,   259,   361,   260,
     264,   256,   256,   264,   260,   300,   304,   361,   290,   348,
     369,   378,   364,   364,   348,     6,   260,   348,   351,   260,
     260,     6,     6,   360,   147,   148,   153,   343,   147,   148,
     343,   364,   318,   260,   264,     6,   260,   361,   319,   260,
       6,   364,   358,   358,   358,   358,   358,     6,   348,   260,
     260,   260,   256,     6,   259,     6,   365,   190,   277,   348,
     264,   264,   360,     6,   348,   348,     6,   260,   260,   296,
       7,   255,   260,   260,   260,   259,   264,   256,   259,   260,
     259,   358,   361,     6,   259,   358,     6,   260,   260,   348,
       6,   142,   260,   330,   259,   260,   264,   264,   264,   264,
     264,     6,     6,     6,   319,     6,   259,   348,   348,   260,
     264,   300,   369,   256,   348,   348,   364,     6,   358,     6,
     358,     6,     6,   260,   348,   333,   319,     6,   364,   364,
     364,   364,   358,   364,   336,   274,   256,   264,     6,   259,
     348,   260,   264,   264,   260,   264,   264,     6,   260,   260,
     331,   260,   260,   260,   260,   264,   260,   260,   260,   280,
     348,   360,   260,   348,   348,   358,   358,   333,     6,     6,
       6,     6,   364,     6,     6,     6,   259,   256,   260,     6,
     260,   290,   264,   264,   260,   260,   278,   368,   283,   259,
       6,   348,   348,     6,   260,   264,   259,   360,   260,   260,
       6,   368,   281,   368,   260,     6,     6,   260,   264,     6,
       6,   368
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
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 183:
#line 1986 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 184:
#line 1992 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 1999 "Gmsh.y"
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

  case 186:
#line 2030 "Gmsh.y"
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

  case 187:
#line 2045 "Gmsh.y"
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

  case 188:
#line 2067 "Gmsh.y"
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

  case 189:
#line 2090 "Gmsh.y"
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

  case 190:
#line 2113 "Gmsh.y"
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

  case 191:
#line 2136 "Gmsh.y"
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

  case 192:
#line 2160 "Gmsh.y"
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

  case 193:
#line 2184 "Gmsh.y"
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

  case 194:
#line 2208 "Gmsh.y"
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

  case 195:
#line 2234 "Gmsh.y"
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

  case 196:
#line 2251 "Gmsh.y"
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

  case 197:
#line 2267 "Gmsh.y"
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

  case 198:
#line 2285 "Gmsh.y"
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

  case 199:
#line 2303 "Gmsh.y"
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

  case 200:
#line 2316 "Gmsh.y"
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

  case 201:
#line 2328 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 202:
#line 2332 "Gmsh.y"
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

  case 203:
#line 2358 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2360 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2362 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2364 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 207:
#line 2366 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 208:
#line 2374 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 209:
#line 2376 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 210:
#line 2378 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 211:
#line 2380 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 212:
#line 2388 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 213:
#line 2390 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 214:
#line 2392 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 215:
#line 2400 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 216:
#line 2402 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 217:
#line 2404 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 218:
#line 2406 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 219:
#line 2416 "Gmsh.y"
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

  case 220:
#line 2432 "Gmsh.y"
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

  case 221:
#line 2448 "Gmsh.y"
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

  case 222:
#line 2464 "Gmsh.y"
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

  case 223:
#line 2480 "Gmsh.y"
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

  case 224:
#line 2496 "Gmsh.y"
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

  case 225:
#line 2513 "Gmsh.y"
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

  case 226:
#line 2550 "Gmsh.y"
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

  case 227:
#line 2571 "Gmsh.y"
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

  case 228:
#line 2592 "Gmsh.y"
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

  case 229:
#line 2617 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 230:
#line 2618 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 231:
#line 2623 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 232:
#line 2627 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 233:
#line 2631 "Gmsh.y"
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

  case 234:
#line 2648 "Gmsh.y"
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

  case 235:
#line 2668 "Gmsh.y"
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

  case 236:
#line 2688 "Gmsh.y"
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

  case 237:
#line 2707 "Gmsh.y"
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

  case 238:
#line 2734 "Gmsh.y"
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

  case 239:
#line 2753 "Gmsh.y"
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

  case 240:
#line 2775 "Gmsh.y"
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

  case 241:
#line 2790 "Gmsh.y"
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

  case 242:
#line 2805 "Gmsh.y"
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

  case 243:
#line 2824 "Gmsh.y"
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

  case 244:
#line 2875 "Gmsh.y"
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

  case 245:
#line 2896 "Gmsh.y"
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

  case 246:
#line 2918 "Gmsh.y"
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

  case 247:
#line 2940 "Gmsh.y"
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

  case 248:
#line 3045 "Gmsh.y"
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

  case 249:
#line 3061 "Gmsh.y"
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

  case 250:
#line 3096 "Gmsh.y"
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

  case 251:
#line 3118 "Gmsh.y"
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

  case 252:
#line 3140 "Gmsh.y"
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

  case 253:
#line 3152 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 254:
#line 3158 "Gmsh.y"
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

  case 255:
#line 3173 "Gmsh.y"
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

  case 256:
#line 3204 "Gmsh.y"
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

  case 257:
#line 3216 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 258:
#line 3225 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 259:
#line 3232 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 260:
#line 3244 "Gmsh.y"
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

  case 261:
#line 3264 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 262:
#line 3268 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 263:
#line 3273 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 264:
#line 3277 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 265:
#line 3282 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 266:
#line 3289 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 267:
#line 3296 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 268:
#line 3303 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 269:
#line 3315 "Gmsh.y"
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

  case 270:
#line 3388 "Gmsh.y"
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

  case 271:
#line 3406 "Gmsh.y"
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

  case 272:
#line 3431 "Gmsh.y"
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

  case 273:
#line 3446 "Gmsh.y"
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

  case 274:
#line 3479 "Gmsh.y"
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

  case 275:
#line 3491 "Gmsh.y"
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

  case 276:
#line 3523 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 277:
#line 3527 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 278:
#line 3532 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 279:
#line 3539 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 280:
#line 3544 "Gmsh.y"
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

  case 281:
#line 3554 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 282:
#line 3559 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 283:
#line 3565 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 284:
#line 3573 "Gmsh.y"
    {
      GModel::current()->makeDiscreteRegionsSimplyConnected();
      GModel::current()->makeDiscreteFacesSimplyConnected();
      GModel::current()->createTopologyFromMesh();
      // Warning: this clears GEO_Internals! Make it optional?
      GModel::current()->exportDiscreteGEOInternals();
    ;}
    break;

  case 285:
#line 3581 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 286:
#line 3585 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 287:
#line 3589 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 288:
#line 3593 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 289:
#line 3597 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 290:
#line 3601 "Gmsh.y"
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

  case 291:
#line 3613 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->recombineMesh();
    ;}
    break;

  case 292:
#line 3623 "Gmsh.y"
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

  case 293:
#line 3686 "Gmsh.y"
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

  case 294:
#line 3702 "Gmsh.y"
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

  case 295:
#line 3719 "Gmsh.y"
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

  case 296:
#line 3736 "Gmsh.y"
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

  case 297:
#line 3758 "Gmsh.y"
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

  case 298:
#line 3780 "Gmsh.y"
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

  case 299:
#line 3815 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 300:
#line 3823 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 301:
#line 3831 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 302:
#line 3837 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 303:
#line 3844 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 304:
#line 3851 "Gmsh.y"
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

  case 305:
#line 3871 "Gmsh.y"
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

  case 306:
#line 3897 "Gmsh.y"
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

  case 307:
#line 3909 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 308:
#line 3920 "Gmsh.y"
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

  case 309:
#line 3938 "Gmsh.y"
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

  case 310:
#line 3956 "Gmsh.y"
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

  case 311:
#line 3974 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 312:
#line 3980 "Gmsh.y"
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

  case 313:
#line 3998 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 4004 "Gmsh.y"
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

  case 315:
#line 4024 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4030 "Gmsh.y"
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

  case 317:
#line 4048 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 318:
#line 4054 "Gmsh.y"
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

  case 319:
#line 4071 "Gmsh.y"
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

  case 320:
#line 4087 "Gmsh.y"
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

  case 321:
#line 4104 "Gmsh.y"
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

  case 322:
#line 4122 "Gmsh.y"
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

  case 323:
#line 4145 "Gmsh.y"
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

  case 324:
#line 4172 "Gmsh.y"
    {
    ;}
    break;

  case 325:
#line 4175 "Gmsh.y"
    {
    ;}
    break;

  case 326:
#line 4181 "Gmsh.y"
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

  case 327:
#line 4193 "Gmsh.y"
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

  case 328:
#line 4213 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 329:
#line 4217 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 330:
#line 4221 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 331:
#line 4225 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 332:
#line 4229 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 333:
#line 4233 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 334:
#line 4237 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 335:
#line 4241 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 336:
#line 4250 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 337:
#line 4262 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 338:
#line 4263 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 339:
#line 4264 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 340:
#line 4265 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 341:
#line 4266 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 342:
#line 4270 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 343:
#line 4271 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 344:
#line 4272 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 345:
#line 4273 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 346:
#line 4274 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 347:
#line 4279 "Gmsh.y"
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

  case 348:
#line 4302 "Gmsh.y"
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

  case 349:
#line 4322 "Gmsh.y"
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

  case 350:
#line 4343 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 351:
#line 4347 "Gmsh.y"
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

  case 352:
#line 4362 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 353:
#line 4366 "Gmsh.y"
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

  case 354:
#line 4382 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 355:
#line 4386 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 356:
#line 4391 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 357:
#line 4395 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 358:
#line 4401 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 359:
#line 4405 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 360:
#line 4412 "Gmsh.y"
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

  case 361:
#line 4434 "Gmsh.y"
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

  case 362:
#line 4475 "Gmsh.y"
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

  case 363:
#line 4519 "Gmsh.y"
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

  case 364:
#line 4558 "Gmsh.y"
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

  case 365:
#line 4583 "Gmsh.y"
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

  case 366:
#line 4596 "Gmsh.y"
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

  case 367:
#line 4607 "Gmsh.y"
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

  case 368:
#line 4624 "Gmsh.y"
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

  case 369:
#line 4641 "Gmsh.y"
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

  case 370:
#line 4671 "Gmsh.y"
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

  case 371:
#line 4697 "Gmsh.y"
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

  case 372:
#line 4724 "Gmsh.y"
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

  case 373:
#line 4756 "Gmsh.y"
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

  case 374:
#line 4783 "Gmsh.y"
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

  case 375:
#line 4809 "Gmsh.y"
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

  case 376:
#line 4835 "Gmsh.y"
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

  case 377:
#line 4861 "Gmsh.y"
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

  case 378:
#line 4887 "Gmsh.y"
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

  case 379:
#line 4908 "Gmsh.y"
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

  case 380:
#line 4919 "Gmsh.y"
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

  case 381:
#line 4967 "Gmsh.y"
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

  case 382:
#line 5021 "Gmsh.y"
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

  case 383:
#line 5036 "Gmsh.y"
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

  case 384:
#line 5048 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 385:
#line 5059 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 386:
#line 5066 "Gmsh.y"
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

  case 387:
#line 5081 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 388:
#line 5094 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 389:
#line 5095 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 390:
#line 5096 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 391:
#line 5101 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 392:
#line 5107 "Gmsh.y"
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

  case 393:
#line 5119 "Gmsh.y"
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

  case 394:
#line 5137 "Gmsh.y"
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

  case 395:
#line 5164 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 396:
#line 5165 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 397:
#line 5166 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 398:
#line 5167 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 399:
#line 5168 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 5169 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 401:
#line 5170 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 402:
#line 5171 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5173 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 404:
#line 5179 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 405:
#line 5180 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 406:
#line 5181 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 407:
#line 5182 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 408:
#line 5183 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 409:
#line 5184 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 410:
#line 5185 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5186 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5187 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5188 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5189 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5190 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5191 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 417:
#line 5192 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 418:
#line 5193 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 419:
#line 5194 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 420:
#line 5195 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5196 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 422:
#line 5197 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5198 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5199 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5200 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5201 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5202 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5203 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5204 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 430:
#line 5205 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5206 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5207 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5208 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5209 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 435:
#line 5210 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 436:
#line 5211 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5212 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 438:
#line 5213 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 439:
#line 5214 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 440:
#line 5215 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5216 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 442:
#line 5217 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5218 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5227 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 445:
#line 5228 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 446:
#line 5229 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 447:
#line 5230 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 448:
#line 5231 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 449:
#line 5232 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 450:
#line 5233 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 451:
#line 5234 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 452:
#line 5235 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 453:
#line 5236 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 454:
#line 5237 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 455:
#line 5242 "Gmsh.y"
    { init_options(); ;}
    break;

  case 456:
#line 5244 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 457:
#line 5250 "Gmsh.y"
    {
      (yyval.d) = (yyvsp[(1) - (1)].d);
    ;}
    break;

  case 458:
#line 5254 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 459:
#line 5259 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 460:
#line 5264 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 461:
#line 5269 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 462:
#line 5274 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 463:
#line 5278 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 464:
#line 5282 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 465:
#line 5286 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 466:
#line 5290 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 467:
#line 5294 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 468:
#line 5298 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 469:
#line 5302 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5308 "Gmsh.y"
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

  case 471:
#line 5323 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 472:
#line 5327 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 473:
#line 5333 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 474:
#line 5338 "Gmsh.y"
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

  case 475:
#line 5357 "Gmsh.y"
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

  case 476:
#line 5377 "Gmsh.y"
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
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 478:
#line 5402 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 479:
#line 5406 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 480:
#line 5410 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 481:
#line 5414 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 482:
#line 5418 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 483:
#line 5422 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 484:
#line 5427 "Gmsh.y"
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

  case 485:
#line 5437 "Gmsh.y"
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

  case 486:
#line 5447 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 487:
#line 5452 "Gmsh.y"
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

  case 488:
#line 5463 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 489:
#line 5472 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 490:
#line 5477 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 491:
#line 5482 "Gmsh.y"
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

  case 492:
#line 5509 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 493:
#line 5511 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 494:
#line 5516 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 495:
#line 5518 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 496:
#line 5523 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 497:
#line 5530 "Gmsh.y"
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

  case 498:
#line 5546 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 499:
#line 5548 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 500:
#line 5553 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 501:
#line 5555 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 502:
#line 5560 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 503:
#line 5562 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 504:
#line 5567 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 505:
#line 5571 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 506:
#line 5575 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 507:
#line 5579 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 508:
#line 5583 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 509:
#line 5590 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 510:
#line 5594 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 511:
#line 5598 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 512:
#line 5602 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 513:
#line 5609 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 514:
#line 5614 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 515:
#line 5621 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 516:
#line 5626 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 517:
#line 5630 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 518:
#line 5635 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 519:
#line 5639 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 520:
#line 5647 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 521:
#line 5658 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 522:
#line 5662 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 523:
#line 5666 "Gmsh.y"
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

  case 524:
#line 5680 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 525:
#line 5688 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 526:
#line 5696 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 527:
#line 5703 "Gmsh.y"
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

  case 528:
#line 5713 "Gmsh.y"
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

  case 529:
#line 5736 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 530:
#line 5741 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 531:
#line 5747 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 532:
#line 5752 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 533:
#line 5758 "Gmsh.y"
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

  case 534:
#line 5769 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 535:
#line 5775 "Gmsh.y"
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

  case 536:
#line 5789 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 537:
#line 5795 "Gmsh.y"
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

  case 538:
#line 5807 "Gmsh.y"
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

  case 539:
#line 5821 "Gmsh.y"
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

  case 540:
#line 5831 "Gmsh.y"
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
#line 5841 "Gmsh.y"
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
#line 5851 "Gmsh.y"
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

  case 543:
#line 5863 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 544:
#line 5867 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 545:
#line 5872 "Gmsh.y"
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

  case 546:
#line 5884 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 547:
#line 5888 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 548:
#line 5892 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 549:
#line 5896 "Gmsh.y"
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

  case 550:
#line 5914 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 551:
#line 5922 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 552:
#line 5930 "Gmsh.y"
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

  case 553:
#line 5959 "Gmsh.y"
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

  case 554:
#line 5969 "Gmsh.y"
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

  case 555:
#line 5985 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 556:
#line 5996 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 557:
#line 6001 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 558:
#line 6005 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 559:
#line 6009 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 560:
#line 6021 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 561:
#line 6025 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 562:
#line 6037 "Gmsh.y"
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

  case 563:
#line 6054 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 564:
#line 6064 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 565:
#line 6068 "Gmsh.y"
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

  case 566:
#line 6083 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 567:
#line 6088 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 568:
#line 6095 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 569:
#line 6099 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 570:
#line 6104 "Gmsh.y"
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

  case 571:
#line 6118 "Gmsh.y"
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
#line 6132 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 573:
#line 6136 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 574:
#line 6140 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 575:
#line 6144 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 576:
#line 6148 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 577:
#line 6156 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 578:
#line 6162 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 579:
#line 6171 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 580:
#line 6175 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 581:
#line 6179 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 582:
#line 6187 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 583:
#line 6193 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 584:
#line 6199 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 585:
#line 6203 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6210 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 587:
#line 6218 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6225 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 589:
#line 6234 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 590:
#line 6238 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 591:
#line 6242 "Gmsh.y"
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

  case 592:
#line 6257 "Gmsh.y"
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

  case 593:
#line 6271 "Gmsh.y"
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

  case 594:
#line 6285 "Gmsh.y"
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

  case 595:
#line 6297 "Gmsh.y"
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

  case 596:
#line 6313 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 597:
#line 6322 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 598:
#line 6331 "Gmsh.y"
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

  case 599:
#line 6341 "Gmsh.y"
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

  case 600:
#line 6352 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 601:
#line 6360 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 602:
#line 6368 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 603:
#line 6372 "Gmsh.y"
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

  case 604:
#line 6391 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 605:
#line 6398 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 606:
#line 6404 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 607:
#line 6410 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 608:
#line 6417 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6424 "Gmsh.y"
    { init_options(); ;}
    break;

  case 610:
#line 6426 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 611:
#line 6434 "Gmsh.y"
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

  case 612:
#line 6458 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 613:
#line 6460 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 614:
#line 6466 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 615:
#line 6471 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 616:
#line 6473 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 617:
#line 6478 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 618:
#line 6483 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 619:
#line 6488 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 620:
#line 6490 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 621:
#line 6494 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 622:
#line 6506 "Gmsh.y"
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

  case 623:
#line 6520 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 624:
#line 6524 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 625:
#line 6531 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 626:
#line 6539 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 627:
#line 6547 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 628:
#line 6558 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 629:
#line 6560 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 630:
#line 6563 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14664 "Gmsh.tab.cpp"
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


#line 6566 "Gmsh.y"


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

