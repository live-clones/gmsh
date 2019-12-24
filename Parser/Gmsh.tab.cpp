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
     tAdaptMesh = 381,
     tRelocateMesh = 382,
     tReorientMesh = 383,
     tSetFactory = 384,
     tThruSections = 385,
     tWedge = 386,
     tFillet = 387,
     tChamfer = 388,
     tPlane = 389,
     tRuled = 390,
     tTransfinite = 391,
     tPhysical = 392,
     tCompound = 393,
     tPeriodic = 394,
     tParent = 395,
     tUsing = 396,
     tPlugin = 397,
     tDegenerated = 398,
     tRecursive = 399,
     tSewing = 400,
     tRotate = 401,
     tTranslate = 402,
     tSymmetry = 403,
     tDilate = 404,
     tExtrude = 405,
     tLevelset = 406,
     tAffine = 407,
     tBooleanUnion = 408,
     tBooleanIntersection = 409,
     tBooleanDifference = 410,
     tBooleanSection = 411,
     tBooleanFragments = 412,
     tThickSolid = 413,
     tRecombine = 414,
     tSmoother = 415,
     tSplit = 416,
     tDelete = 417,
     tCoherence = 418,
     tIntersect = 419,
     tMeshAlgorithm = 420,
     tReverseMesh = 421,
     tMeshSizeFromBoundary = 422,
     tLayers = 423,
     tScaleLast = 424,
     tHole = 425,
     tAlias = 426,
     tAliasWithOptions = 427,
     tCopyOptions = 428,
     tQuadTriAddVerts = 429,
     tQuadTriNoNewVerts = 430,
     tRecombLaterals = 431,
     tTransfQuadTri = 432,
     tText2D = 433,
     tText3D = 434,
     tInterpolationScheme = 435,
     tTime = 436,
     tCombine = 437,
     tBSpline = 438,
     tBezier = 439,
     tNurbs = 440,
     tNurbsOrder = 441,
     tNurbsKnots = 442,
     tColor = 443,
     tColorTable = 444,
     tFor = 445,
     tIn = 446,
     tEndFor = 447,
     tIf = 448,
     tElseIf = 449,
     tElse = 450,
     tEndIf = 451,
     tExit = 452,
     tAbort = 453,
     tField = 454,
     tReturn = 455,
     tCall = 456,
     tSlide = 457,
     tMacro = 458,
     tShow = 459,
     tHide = 460,
     tGetValue = 461,
     tGetStringValue = 462,
     tGetEnv = 463,
     tGetString = 464,
     tGetNumber = 465,
     tUnique = 466,
     tHomology = 467,
     tCohomology = 468,
     tBetti = 469,
     tExists = 470,
     tFileExists = 471,
     tGetForced = 472,
     tGetForcedStr = 473,
     tGMSH_MAJOR_VERSION = 474,
     tGMSH_MINOR_VERSION = 475,
     tGMSH_PATCH_VERSION = 476,
     tGmshExecutableName = 477,
     tSetPartition = 478,
     tNameToString = 479,
     tStringToName = 480,
     tAFFECTDIVIDE = 481,
     tAFFECTTIMES = 482,
     tAFFECTMINUS = 483,
     tAFFECTPLUS = 484,
     tOR = 485,
     tAND = 486,
     tNOTEQUAL = 487,
     tEQUAL = 488,
     tGREATERGREATER = 489,
     tLESSLESS = 490,
     tGREATEROREQUAL = 491,
     tLESSOREQUAL = 492,
     UNARYPREC = 493,
     tMINUSMINUS = 494,
     tPLUSPLUS = 495
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
#define tAdaptMesh 381
#define tRelocateMesh 382
#define tReorientMesh 383
#define tSetFactory 384
#define tThruSections 385
#define tWedge 386
#define tFillet 387
#define tChamfer 388
#define tPlane 389
#define tRuled 390
#define tTransfinite 391
#define tPhysical 392
#define tCompound 393
#define tPeriodic 394
#define tParent 395
#define tUsing 396
#define tPlugin 397
#define tDegenerated 398
#define tRecursive 399
#define tSewing 400
#define tRotate 401
#define tTranslate 402
#define tSymmetry 403
#define tDilate 404
#define tExtrude 405
#define tLevelset 406
#define tAffine 407
#define tBooleanUnion 408
#define tBooleanIntersection 409
#define tBooleanDifference 410
#define tBooleanSection 411
#define tBooleanFragments 412
#define tThickSolid 413
#define tRecombine 414
#define tSmoother 415
#define tSplit 416
#define tDelete 417
#define tCoherence 418
#define tIntersect 419
#define tMeshAlgorithm 420
#define tReverseMesh 421
#define tMeshSizeFromBoundary 422
#define tLayers 423
#define tScaleLast 424
#define tHole 425
#define tAlias 426
#define tAliasWithOptions 427
#define tCopyOptions 428
#define tQuadTriAddVerts 429
#define tQuadTriNoNewVerts 430
#define tRecombLaterals 431
#define tTransfQuadTri 432
#define tText2D 433
#define tText3D 434
#define tInterpolationScheme 435
#define tTime 436
#define tCombine 437
#define tBSpline 438
#define tBezier 439
#define tNurbs 440
#define tNurbsOrder 441
#define tNurbsKnots 442
#define tColor 443
#define tColorTable 444
#define tFor 445
#define tIn 446
#define tEndFor 447
#define tIf 448
#define tElseIf 449
#define tElse 450
#define tEndIf 451
#define tExit 452
#define tAbort 453
#define tField 454
#define tReturn 455
#define tCall 456
#define tSlide 457
#define tMacro 458
#define tShow 459
#define tHide 460
#define tGetValue 461
#define tGetStringValue 462
#define tGetEnv 463
#define tGetString 464
#define tGetNumber 465
#define tUnique 466
#define tHomology 467
#define tCohomology 468
#define tBetti 469
#define tExists 470
#define tFileExists 471
#define tGetForced 472
#define tGetForcedStr 473
#define tGMSH_MAJOR_VERSION 474
#define tGMSH_MINOR_VERSION 475
#define tGMSH_PATCH_VERSION 476
#define tGmshExecutableName 477
#define tSetPartition 478
#define tNameToString 479
#define tStringToName 480
#define tAFFECTDIVIDE 481
#define tAFFECTTIMES 482
#define tAFFECTMINUS 483
#define tAFFECTPLUS 484
#define tOR 485
#define tAND 486
#define tNOTEQUAL 487
#define tEQUAL 488
#define tGREATERGREATER 489
#define tLESSLESS 490
#define tGREATEROREQUAL 491
#define tLESSOREQUAL 492
#define UNARYPREC 493
#define tMINUSMINUS 494
#define tPLUSPLUS 495




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
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
#line 759 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 772 "Gmsh.tab.cpp"

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
#define YYLAST   17822

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  263
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   495

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   248,     2,   260,     2,   245,   247,     2,
     253,   254,   243,   241,   262,   242,   259,   244,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     235,     2,   236,   230,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   255,     2,   256,   252,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   257,   246,   258,   261,     2,     2,     2,
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
     225,   226,   227,   228,   229,   231,   232,   233,   234,   237,
     238,   239,   240,   249,   250,   251
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
    1110,  1122,  1128,  1138,  1148,  1156,  1161,  1171,  1181,  1183,
    1185,  1186,  1189,  1196,  1204,  1212,  1219,  1227,  1236,  1247,
    1262,  1279,  1292,  1307,  1322,  1337,  1352,  1361,  1370,  1377,
    1382,  1388,  1394,  1401,  1408,  1412,  1417,  1421,  1427,  1434,
    1440,  1445,  1449,  1454,  1458,  1463,  1469,  1474,  1480,  1484,
    1490,  1498,  1506,  1510,  1518,  1522,  1525,  1528,  1531,  1534,
    1537,  1553,  1556,  1559,  1562,  1572,  1584,  1587,  1590,  1593,
    1596,  1613,  1625,  1632,  1641,  1650,  1661,  1663,  1666,  1669,
    1671,  1675,  1679,  1684,  1689,  1691,  1693,  1699,  1711,  1725,
    1726,  1734,  1735,  1749,  1750,  1766,  1767,  1774,  1784,  1787,
    1791,  1802,  1816,  1818,  1821,  1827,  1835,  1838,  1841,  1845,
    1848,  1852,  1855,  1859,  1869,  1876,  1878,  1880,  1882,  1884,
    1886,  1887,  1890,  1894,  1898,  1903,  1913,  1918,  1933,  1934,
    1938,  1939,  1941,  1942,  1945,  1946,  1949,  1950,  1953,  1960,
    1968,  1975,  1981,  1985,  1994,  2003,  2012,  2021,  2030,  2039,
    2045,  2050,  2057,  2069,  2081,  2100,  2119,  2132,  2145,  2158,
    2169,  2174,  2179,  2184,  2189,  2194,  2197,  2201,  2208,  2210,
    2212,  2214,  2217,  2223,  2231,  2242,  2244,  2248,  2251,  2254,
    2257,  2261,  2265,  2269,  2273,  2277,  2281,  2285,  2289,  2293,
    2297,  2301,  2305,  2309,  2313,  2317,  2321,  2325,  2329,  2335,
    2340,  2345,  2350,  2355,  2360,  2365,  2370,  2375,  2380,  2385,
    2392,  2397,  2402,  2407,  2412,  2417,  2422,  2427,  2432,  2439,
    2446,  2453,  2458,  2465,  2472,  2474,  2476,  2478,  2480,  2482,
    2484,  2486,  2488,  2490,  2492,  2494,  2495,  2502,  2504,  2509,
    2516,  2518,  2523,  2528,  2533,  2540,  2546,  2554,  2563,  2574,
    2579,  2584,  2591,  2596,  2600,  2603,  2609,  2615,  2619,  2625,
    2632,  2641,  2648,  2657,  2664,  2669,  2677,  2684,  2691,  2698,
    2703,  2710,  2715,  2716,  2719,  2720,  2723,  2724,  2732,  2734,
    2738,  2740,  2743,  2744,  2748,  2750,  2753,  2756,  2760,  2764,
    2776,  2786,  2794,  2802,  2804,  2808,  2810,  2812,  2815,  2819,
    2824,  2830,  2832,  2836,  2838,  2841,  2845,  2849,  2855,  2860,
    2865,  2868,  2873,  2876,  2880,  2884,  2901,  2907,  2913,  2919,
    2921,  2923,  2925,  2929,  2935,  2943,  2948,  2953,  2958,  2965,
    2972,  2981,  2990,  2995,  3010,  3015,  3020,  3022,  3024,  3028,
    3032,  3042,  3050,  3052,  3058,  3062,  3069,  3071,  3075,  3077,
    3079,  3084,  3089,  3093,  3099,  3106,  3115,  3122,  3127,  3133,
    3135,  3140,  3142,  3144,  3146,  3148,  3153,  3160,  3165,  3172,
    3178,  3186,  3191,  3196,  3201,  3210,  3215,  3220,  3225,  3230,
    3239,  3248,  3255,  3260,  3267,  3272,  3274,  3276,  3281,  3286,
    3287,  3294,  3299,  3302,  3307,  3312,  3314,  3316,  3320,  3322,
    3324,  3328,  3332,  3336,  3342,  3350,  3356,  3362,  3371,  3373,
    3375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     264,     0,    -1,   265,    -1,     1,     6,    -1,    -1,   265,
     266,    -1,   268,    -1,   269,    -1,   290,    -1,   129,   253,
     366,   254,     6,    -1,   309,    -1,   315,    -1,   319,    -1,
     320,    -1,   321,    -1,   322,    -1,   326,    -1,   335,    -1,
     336,    -1,   342,    -1,   343,    -1,   325,    -1,   324,    -1,
     323,    -1,   318,    -1,   345,    -1,   236,    -1,   237,    -1,
      46,   253,   366,   254,     6,    -1,    48,   253,   366,   254,
       6,    -1,    47,   253,   366,   254,     6,    -1,    46,   253,
     366,   254,   267,   366,     6,    -1,    46,   253,   366,   262,
     362,   254,     6,    -1,    48,   253,   366,   262,   362,   254,
       6,    -1,    47,   253,   366,   262,   362,   254,     6,    -1,
      46,   253,   366,   262,   362,   254,   267,   366,     6,    -1,
     376,   366,   257,   270,   258,     6,    -1,   171,     4,   255,
     346,   256,     6,    -1,   172,     4,   255,   346,   256,     6,
      -1,   173,     4,   255,   346,   262,   346,   256,     6,    -1,
      -1,   270,   273,    -1,   270,   277,    -1,   270,   280,    -1,
     270,   282,    -1,   270,   283,    -1,   270,   325,    -1,   346,
      -1,   271,   262,   346,    -1,   346,    -1,   272,   262,   346,
      -1,    -1,    -1,     4,   274,   253,   271,   254,   275,   257,
     272,   258,     6,    -1,   366,    -1,   276,   262,   366,    -1,
      -1,   178,   253,   346,   262,   346,   262,   346,   254,   278,
     257,   276,   258,     6,    -1,   366,    -1,   279,   262,   366,
      -1,    -1,   179,   253,   346,   262,   346,   262,   346,   262,
     346,   254,   281,   257,   279,   258,     6,    -1,   180,   257,
     358,   258,   257,   358,   258,     6,    -1,   180,   257,   358,
     258,   257,   358,   258,   257,   358,   258,   257,   358,   258,
       6,    -1,    -1,   181,   284,   257,   272,   258,     6,    -1,
       7,    -1,   229,    -1,   228,    -1,   227,    -1,   226,    -1,
     251,    -1,   250,    -1,   253,    -1,   255,    -1,   254,    -1,
     256,    -1,     4,    -1,    36,    -1,    37,    -1,   110,    -1,
     111,    -1,    90,   255,   292,   256,     6,    -1,    91,   255,
     296,   256,     6,    -1,   351,     6,    -1,    98,   287,   367,
     262,   346,   288,     6,    -1,   100,   287,   376,   262,   367,
     288,     6,    -1,   376,   285,   359,     6,    -1,   376,   286,
       6,    -1,   376,   287,   288,   285,   359,     6,    -1,   376,
     287,   257,   362,   258,   288,   285,   359,     6,    -1,   376,
     255,   346,   256,   285,   346,     6,    -1,   376,   255,   346,
     256,   286,     6,    -1,   376,   253,   346,   254,   285,   346,
       6,    -1,   376,   253,   346,   254,   286,     6,    -1,   376,
       7,   367,     6,    -1,   376,   287,   288,     7,    49,   287,
     288,     6,    -1,   376,   287,   288,     7,    49,   287,   371,
     288,     6,    -1,   376,   287,   288,   229,    49,   287,   371,
     288,     6,    -1,   376,   259,   289,     7,   367,     6,    -1,
     376,   255,   346,   256,   259,   289,     7,   367,     6,    -1,
     376,   259,   289,   285,   346,     6,    -1,   376,   255,   346,
     256,   259,   289,   285,   346,     6,    -1,   376,   259,   289,
     286,     6,    -1,   376,   255,   346,   256,   259,   289,   286,
       6,    -1,   376,   259,   188,   259,   289,     7,   363,     6,
      -1,   376,   255,   346,   256,   259,   188,   259,   289,     7,
     363,     6,    -1,   376,   259,   189,     7,   364,     6,    -1,
     376,   255,   346,   256,   259,   189,     7,   364,     6,    -1,
     376,   199,     7,   359,     6,    -1,   199,   255,   346,   256,
       7,   289,     6,    -1,   199,   255,   346,   256,   259,   289,
       7,   346,     6,    -1,   199,   255,   346,   256,   259,   289,
       7,   367,     6,    -1,   199,   255,   346,   256,   259,   289,
       7,   257,   362,   258,     6,    -1,   199,   255,   346,   256,
     259,   289,     6,    -1,   142,   253,     4,   254,   259,   289,
       7,   346,     6,    -1,   142,   253,     4,   254,   259,   289,
       7,   367,     6,    -1,    -1,   262,    -1,    -1,   292,   291,
     376,    -1,   292,   291,   376,     7,   346,    -1,    -1,   292,
     291,   376,     7,   257,   359,   293,   298,   258,    -1,    -1,
     292,   291,   376,   287,   288,     7,   257,   359,   294,   298,
     258,    -1,   292,   291,   376,     7,   367,    -1,    -1,   292,
     291,   376,     7,   257,   367,   295,   302,   258,    -1,    -1,
     296,   291,   366,    -1,   346,     7,   367,    -1,   297,   262,
     346,     7,   367,    -1,   361,     7,   376,   253,   254,    -1,
      -1,   262,   300,    -1,    -1,   300,    -1,   301,    -1,   300,
     262,   301,    -1,     4,   359,    -1,    36,   346,    -1,    37,
     346,    -1,     4,    -1,     4,   257,   297,   258,    -1,     4,
     367,    -1,     4,   370,    -1,    -1,   262,   303,    -1,   304,
      -1,   303,   262,   304,    -1,     4,   346,    -1,     4,   367,
      -1,   203,   367,    -1,     4,   372,    -1,     4,   370,    -1,
     346,    -1,   367,    -1,   367,   262,   346,    -1,    -1,   191,
     105,   257,   346,   258,    -1,   141,   101,   257,   362,   258,
      -1,   141,   120,   257,   362,   258,    -1,    -1,   134,   356,
      -1,    -1,   141,   145,    -1,   101,   253,   346,   254,     7,
     356,     6,    -1,   104,   253,   346,   254,     7,   359,     6,
      -1,   108,   253,   346,   254,     7,   359,     6,    -1,   138,
     108,   253,   346,   254,     7,   359,   141,   346,     6,    -1,
     138,   183,   253,   346,   254,     7,   359,   141,   346,     6,
      -1,   102,   253,   346,   254,     7,   359,   307,     6,    -1,
     103,   253,   346,   254,     7,   359,   307,     6,    -1,   183,
     253,   346,   254,     7,   359,     6,    -1,   184,   253,   346,
     254,     7,   359,     6,    -1,   185,   253,   346,   254,     7,
     359,   187,   359,   186,   346,     6,    -1,   119,   253,   346,
     254,     7,   359,     6,    -1,   104,     4,   253,   346,   254,
       7,   359,     6,    -1,   134,   107,   253,   346,   254,     7,
     359,     6,    -1,   107,   253,   346,   254,     7,   359,   306,
       6,    -1,   135,   107,   253,   346,   254,     7,   359,   306,
       6,    -1,    13,    14,     6,    -1,    14,   107,   346,     6,
      -1,   123,   107,   253,   346,   254,     7,     5,     5,     5,
       6,    -1,   105,   253,   346,   254,     7,   359,     6,    -1,
     106,   253,   346,   254,     7,   359,     6,    -1,   110,   253,
     346,   254,     7,   359,     6,    -1,   113,   253,   346,   254,
       7,   359,     6,    -1,   117,   253,   346,   254,     7,   359,
       6,    -1,   118,   253,   346,   254,     7,   359,     6,    -1,
     111,   253,   346,   254,     7,   359,     6,    -1,   112,   253,
     346,   254,     7,   359,     6,    -1,   131,   253,   346,   254,
       7,   359,     6,    -1,   158,   253,   346,   254,     7,   359,
       6,    -1,   107,     4,   253,   346,   254,     7,   359,   308,
       6,    -1,   109,   253,   346,   254,     7,   359,     6,    -1,
     130,   253,   346,   254,     7,   359,     6,    -1,   135,   130,
     253,   346,   254,     7,   359,     6,    -1,   138,   312,   253,
     346,   254,     7,   359,     6,    -1,   138,   312,   253,   346,
     254,     7,   359,     4,   257,   358,   258,     6,    -1,    -1,
     137,   311,   310,   253,   305,   254,   285,   359,     6,    -1,
     101,    -1,   104,    -1,   107,    -1,   109,    -1,   120,   257,
     346,   258,    -1,   104,    -1,   107,    -1,   109,    -1,   120,
     257,   346,   258,    -1,   104,    -1,   107,    -1,   120,   257,
     346,   258,    -1,   101,    -1,   104,    -1,   107,    -1,   120,
     257,   346,   258,    -1,   147,   356,   257,   316,   258,    -1,
     146,   257,   356,   262,   356,   262,   346,   258,   257,   316,
     258,    -1,   148,   356,   257,   316,   258,    -1,   149,   257,
     356,   262,   346,   258,   257,   316,   258,    -1,   149,   257,
     356,   262,   356,   258,   257,   316,   258,    -1,   152,   257,
     362,   258,   257,   316,   258,    -1,     4,   257,   316,   258,
      -1,   164,   104,   257,   362,   258,   107,   257,   346,   258,
      -1,   161,   104,   253,   346,   254,   257,   362,   258,     6,
      -1,   317,    -1,   315,    -1,    -1,   317,   309,    -1,   317,
     311,   257,   362,   258,     6,    -1,   317,   137,   311,   257,
     362,   258,     6,    -1,   317,   140,   311,   257,   362,   258,
       6,    -1,   317,   311,   257,     8,   258,     6,    -1,   317,
     137,   311,   257,     8,   258,     6,    -1,   151,   134,   253,
     346,   254,     7,   359,     6,    -1,   151,   101,   253,   346,
     254,     7,   257,   358,   258,     6,    -1,   151,   134,   253,
     346,   254,     7,   257,   356,   262,   356,   262,   362,   258,
       6,    -1,   151,   134,   253,   346,   254,     7,   257,   356,
     262,   356,   262,   356,   262,   362,   258,     6,    -1,   151,
     105,   253,   346,   254,     7,   257,   356,   262,   362,   258,
       6,    -1,   151,   111,   253,   346,   254,     7,   257,   356,
     262,   356,   262,   362,   258,     6,    -1,   151,   112,   253,
     346,   254,     7,   257,   356,   262,   356,   262,   362,   258,
       6,    -1,   151,   114,   253,   346,   254,     7,   257,   356,
     262,   356,   262,   362,   258,     6,    -1,   151,   115,   253,
     346,   254,     7,   257,   356,   262,   356,   262,   362,   258,
       6,    -1,   151,     4,   253,   346,   254,     7,   359,     6,
      -1,   151,     4,   253,   346,   254,     7,     5,     6,    -1,
     151,     4,   257,   346,   258,     6,    -1,   162,   257,   317,
     258,    -1,   144,   162,   257,   317,   258,    -1,   162,     4,
     257,   317,   258,    -1,   162,   199,   255,   346,   256,     6,
      -1,   162,     4,   255,   346,   256,     6,    -1,   162,   376,
       6,    -1,   162,     4,     4,     6,    -1,   162,    93,     6,
      -1,   188,   363,   257,   317,   258,    -1,   144,   188,   363,
     257,   317,   258,    -1,   223,   346,   257,   317,   258,    -1,
     204,   257,     8,   258,    -1,   204,     5,     6,    -1,   205,
     257,     8,   258,    -1,   205,     5,     6,    -1,   204,   257,
     317,   258,    -1,   144,   204,   257,   317,   258,    -1,   205,
     257,   317,   258,    -1,   144,   205,   257,   317,   258,    -1,
     376,   367,     6,    -1,    79,   253,   373,   254,     6,    -1,
     376,   376,   255,   346,   256,   366,     6,    -1,   376,   376,
     376,   255,   346,   256,     6,    -1,   376,   346,     6,    -1,
     142,   253,     4,   254,   259,     4,     6,    -1,   182,     4,
       6,    -1,   197,     6,    -1,   198,     6,    -1,    74,     6,
      -1,    75,     6,    -1,    67,     6,    -1,    67,   257,   346,
     262,   346,   262,   346,   262,   346,   262,   346,   262,   346,
     258,     6,    -1,    68,     6,    -1,    69,     6,    -1,    84,
       6,    -1,    86,   257,   346,   262,   346,   262,   346,   258,
       6,    -1,    86,   257,   346,   262,   346,   262,   346,   262,
     346,   258,     6,    -1,    85,     6,    -1,    87,     6,    -1,
      88,     6,    -1,   125,     6,    -1,   126,   257,   362,   258,
     257,   362,   258,   257,   358,   258,   257,   346,   262,   346,
     258,     6,    -1,   202,   253,   257,   362,   258,   262,   367,
     262,   367,   254,     6,    -1,   190,   253,   346,     8,   346,
     254,    -1,   190,   253,   346,     8,   346,     8,   346,   254,
      -1,   190,     4,   191,   257,   346,     8,   346,   258,    -1,
     190,     4,   191,   257,   346,     8,   346,     8,   346,   258,
      -1,   192,    -1,   203,     4,    -1,   203,   367,    -1,   200,
      -1,   201,   376,     6,    -1,   201,   367,     6,    -1,   193,
     253,   346,   254,    -1,   194,   253,   346,   254,    -1,   195,
      -1,   196,    -1,   150,   356,   257,   317,   258,    -1,   150,
     257,   356,   262,   356,   262,   346,   258,   257,   317,   258,
      -1,   150,   257,   356,   262,   356,   262,   356,   262,   346,
     258,   257,   317,   258,    -1,    -1,   150,   356,   257,   317,
     327,   331,   258,    -1,    -1,   150,   257,   356,   262,   356,
     262,   346,   258,   257,   317,   328,   331,   258,    -1,    -1,
     150,   257,   356,   262,   356,   262,   356,   262,   346,   258,
     257,   317,   329,   331,   258,    -1,    -1,   150,   257,   317,
     330,   331,   258,    -1,   150,   257,   317,   258,   141,   119,
     257,   346,   258,    -1,   130,   359,    -1,   135,   130,   359,
      -1,   132,   257,   362,   258,   257,   362,   258,   257,   362,
     258,    -1,   133,   257,   362,   258,   257,   362,   258,   257,
     362,   258,   257,   362,   258,    -1,   332,    -1,   331,   332,
      -1,   168,   257,   346,   258,     6,    -1,   168,   257,   359,
     262,   359,   258,     6,    -1,   169,     6,    -1,   159,     6,
      -1,   159,   346,     6,    -1,   174,     6,    -1,   174,   176,
       6,    -1,   175,     6,    -1,   175,   176,     6,    -1,   170,
     253,   346,   254,     7,   359,   141,   346,     6,    -1,   141,
       4,   255,   346,   256,     6,    -1,   153,    -1,   154,    -1,
     155,    -1,   156,    -1,   157,    -1,    -1,   162,     6,    -1,
     144,   162,     6,    -1,   162,   346,     6,    -1,   144,   162,
     346,     6,    -1,   333,   257,   317,   334,   258,   257,   317,
     334,   258,    -1,   116,   253,   366,   254,    -1,   333,   253,
     346,   254,     7,   257,   317,   334,   258,   257,   317,   334,
     258,     6,    -1,    -1,   141,     4,   346,    -1,    -1,     4,
      -1,    -1,     7,   359,    -1,    -1,     7,   346,    -1,    -1,
     152,   359,    -1,   121,   122,   360,     7,   346,     6,    -1,
     136,   104,   360,     7,   346,   337,     6,    -1,   136,   107,
     360,   339,   338,     6,    -1,   136,   109,   360,   339,     6,
      -1,   177,   360,     6,    -1,    99,   101,   253,   346,   262,
     346,   254,     6,    -1,    99,   104,   253,   346,   262,   346,
     254,     6,    -1,    99,   107,   253,   346,   262,   346,   254,
       6,    -1,    99,   109,   253,   346,   262,   346,   254,     6,
      -1,   165,   107,   257,   362,   258,     7,   346,     6,    -1,
     167,   107,   257,   362,   258,     7,   346,     6,    -1,   159,
     107,   360,   340,     6,    -1,   159,   109,   360,     6,    -1,
     160,   107,   360,     7,   346,     6,    -1,   139,   104,   257,
     362,   258,     7,   257,   362,   258,   341,     6,    -1,   139,
     107,   257,   362,   258,     7,   257,   362,   258,   341,     6,
      -1,   139,   104,   257,   362,   258,     7,   257,   362,   258,
     146,   257,   356,   262,   356,   262,   346,   258,     6,    -1,
     139,   107,   257,   362,   258,     7,   257,   362,   258,   146,
     257,   356,   262,   356,   262,   346,   258,     6,    -1,   139,
     104,   257,   362,   258,     7,   257,   362,   258,   147,   356,
       6,    -1,   139,   107,   257,   362,   258,     7,   257,   362,
     258,   147,   356,     6,    -1,   139,   107,   346,   257,   362,
     258,     7,   346,   257,   362,   258,     6,    -1,   311,   257,
     362,   258,   191,   311,   257,   346,   258,     6,    -1,   166,
     313,   360,     6,    -1,   127,   314,   360,     6,    -1,   128,
     109,   359,     6,    -1,   143,   104,   359,     6,    -1,   138,
     312,   359,     6,    -1,   163,     6,    -1,   163,     4,     6,
      -1,   163,   101,   257,   362,   258,     6,    -1,   212,    -1,
     213,    -1,   214,    -1,   344,     6,    -1,   344,   257,   359,
     258,     6,    -1,   344,   257,   359,   262,   359,   258,     6,
      -1,   344,   253,   359,   254,   257,   359,   262,   359,   258,
       6,    -1,   347,    -1,   253,   346,   254,    -1,   242,   346,
      -1,   241,   346,    -1,   248,   346,    -1,   346,   242,   346,
      -1,   346,   241,   346,    -1,   346,   243,   346,    -1,   346,
     244,   346,    -1,   346,   246,   346,    -1,   346,   247,   346,
      -1,   346,   245,   346,    -1,   346,   252,   346,    -1,   346,
     235,   346,    -1,   346,   236,   346,    -1,   346,   240,   346,
      -1,   346,   239,   346,    -1,   346,   234,   346,    -1,   346,
     233,   346,    -1,   346,   232,   346,    -1,   346,   231,   346,
      -1,   346,   237,   346,    -1,   346,   238,   346,    -1,   346,
     230,   346,     8,   346,    -1,    16,   287,   346,   288,    -1,
      17,   287,   346,   288,    -1,    18,   287,   346,   288,    -1,
      19,   287,   346,   288,    -1,    20,   287,   346,   288,    -1,
      21,   287,   346,   288,    -1,    22,   287,   346,   288,    -1,
      23,   287,   346,   288,    -1,    24,   287,   346,   288,    -1,
      26,   287,   346,   288,    -1,    27,   287,   346,   262,   346,
     288,    -1,    28,   287,   346,   288,    -1,    29,   287,   346,
     288,    -1,    30,   287,   346,   288,    -1,    31,   287,   346,
     288,    -1,    32,   287,   346,   288,    -1,    33,   287,   346,
     288,    -1,    34,   287,   346,   288,    -1,    35,   287,   346,
     288,    -1,    38,   287,   346,   262,   346,   288,    -1,    39,
     287,   346,   262,   346,   288,    -1,    40,   287,   346,   262,
     346,   288,    -1,    25,   287,   346,   288,    -1,    37,   287,
     346,   262,   346,   288,    -1,    36,   287,   346,   262,   346,
     288,    -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,
      12,    -1,   219,    -1,   220,    -1,   221,    -1,    81,    -1,
      82,    -1,    83,    -1,    -1,    92,   287,   346,   348,   298,
     288,    -1,   351,    -1,   210,   287,   366,   288,    -1,   210,
     287,   366,   262,   346,   288,    -1,   353,    -1,   376,   255,
     346,   256,    -1,   376,   253,   346,   254,    -1,   215,   253,
     353,   254,    -1,   215,   253,   353,   259,   289,   254,    -1,
     217,   253,   353,   349,   254,    -1,   217,   253,   353,   259,
     289,   349,   254,    -1,   217,   253,   353,   287,   346,   288,
     349,   254,    -1,   217,   253,   353,   259,   289,   287,   346,
     288,   349,   254,    -1,   216,   253,   367,   254,    -1,   260,
     376,   287,   288,    -1,   260,   353,   259,   289,   287,   288,
      -1,    95,   287,   376,   288,    -1,    95,   287,   288,    -1,
     376,   286,    -1,   376,   255,   346,   256,   286,    -1,   376,
     253,   346,   254,   286,    -1,   376,   259,   289,    -1,   376,
       9,   376,   259,   289,    -1,   376,   259,   289,   253,   346,
     254,    -1,   376,     9,   376,   259,   289,   253,   346,   254,
      -1,   376,   259,   289,   255,   346,   256,    -1,   376,     9,
     376,   259,   289,   255,   346,   256,    -1,   376,   255,   346,
     256,   259,   289,    -1,   376,   259,   289,   286,    -1,   376,
     255,   346,   256,   259,   289,   286,    -1,   206,   253,   366,
     262,   346,   254,    -1,    59,   253,   359,   262,   359,   254,
      -1,    60,   287,   366,   262,   366,   288,    -1,    58,   287,
     366,   288,    -1,    61,   287,   366,   262,   366,   288,    -1,
      66,   253,   373,   254,    -1,    -1,   262,   346,    -1,    -1,
     262,   366,    -1,    -1,    93,   353,   355,   352,   255,   299,
     256,    -1,   376,    -1,   376,     9,   376,    -1,    96,    -1,
      96,   346,    -1,    -1,   253,   354,   254,    -1,   357,    -1,
     242,   356,    -1,   241,   356,    -1,   356,   242,   356,    -1,
     356,   241,   356,    -1,   257,   346,   262,   346,   262,   346,
     262,   346,   262,   346,   258,    -1,   257,   346,   262,   346,
     262,   346,   262,   346,   258,    -1,   257,   346,   262,   346,
     262,   346,   258,    -1,   253,   346,   262,   346,   262,   346,
     254,    -1,   359,    -1,   358,   262,   359,    -1,   346,    -1,
     361,    -1,   257,   258,    -1,   257,   362,   258,    -1,   242,
     257,   362,   258,    -1,   346,   243,   257,   362,   258,    -1,
     359,    -1,   257,     8,   258,    -1,     5,    -1,   242,   361,
      -1,   346,   243,   361,    -1,   346,     8,   346,    -1,   346,
       8,   346,     8,   346,    -1,   101,   257,   346,   258,    -1,
     101,   257,     8,   258,    -1,   101,     5,    -1,   312,   257,
       8,   258,    -1,   312,     5,    -1,   137,   311,   360,    -1,
     140,   311,   359,    -1,   311,   191,    67,   257,   346,   262,
     346,   262,   346,   262,   346,   262,   346,   262,   346,   258,
      -1,    67,   311,   257,   362,   258,    -1,    76,   312,   257,
     346,   258,    -1,    77,   312,   257,   346,   258,    -1,   315,
      -1,   326,    -1,   335,    -1,   376,   287,   288,    -1,   376,
     259,   289,   287,   288,    -1,   376,     9,   376,   259,   289,
     287,   288,    -1,    41,   255,   376,   256,    -1,    41,   255,
     361,   256,    -1,    41,   253,   361,   254,    -1,    41,   287,
     257,   362,   258,   288,    -1,   376,   287,   257,   362,   258,
     288,    -1,    42,   287,   346,   262,   346,   262,   346,   288,
      -1,    43,   287,   346,   262,   346,   262,   346,   288,    -1,
      44,   287,   366,   288,    -1,    45,   287,   346,   262,   346,
     262,   346,   262,   346,   262,   346,   262,   346,   288,    -1,
     211,   287,   361,   288,    -1,    32,   287,   361,   288,    -1,
     346,    -1,   361,    -1,   362,   262,   346,    -1,   362,   262,
     361,    -1,   257,   346,   262,   346,   262,   346,   262,   346,
     258,    -1,   257,   346,   262,   346,   262,   346,   258,    -1,
     376,    -1,     4,   259,   188,   259,     4,    -1,   257,   365,
     258,    -1,   376,   255,   346,   256,   259,   189,    -1,   363,
      -1,   365,   262,   363,    -1,   367,    -1,   376,    -1,   376,
     255,   346,   256,    -1,   376,   253,   346,   254,    -1,   376,
     259,   289,    -1,   376,     9,   376,   259,   289,    -1,   376,
     259,   289,   253,   346,   254,    -1,   376,     9,   376,   259,
     289,   253,   346,   254,    -1,   376,   255,   346,   256,   259,
       4,    -1,   311,   257,   346,   258,    -1,   137,   311,   257,
     346,   258,    -1,     5,    -1,   224,   255,   376,   256,    -1,
      70,    -1,   222,    -1,    78,    -1,    80,    -1,   208,   253,
     366,   254,    -1,   207,   253,   366,   262,   366,   254,    -1,
     209,   287,   366,   288,    -1,   209,   287,   366,   262,   366,
     288,    -1,   218,   253,   353,   350,   254,    -1,   218,   253,
     353,   259,   289,   350,   254,    -1,    51,   287,   373,   288,
      -1,    52,   253,   366,   254,    -1,    53,   253,   366,   254,
      -1,    54,   253,   366,   262,   366,   262,   366,   254,    -1,
      49,   287,   373,   288,    -1,    63,   287,   366,   288,    -1,
      64,   287,   366,   288,    -1,    65,   287,   366,   288,    -1,
      62,   287,   346,   262,   366,   262,   366,   288,    -1,    57,
     287,   366,   262,   346,   262,   346,   288,    -1,    57,   287,
     366,   262,   346,   288,    -1,    50,   287,   366,   288,    -1,
      50,   287,   366,   262,   362,   288,    -1,    71,   287,   366,
     288,    -1,    72,    -1,    73,    -1,    56,   287,   366,   288,
      -1,    55,   287,   366,   288,    -1,    -1,    97,   287,   367,
     368,   302,   288,    -1,    94,   287,   369,   288,    -1,   260,
     346,    -1,   376,     9,   260,   346,    -1,    49,   287,   372,
     288,    -1,   373,    -1,   372,    -1,   257,   373,   258,    -1,
     366,    -1,   374,    -1,   373,   262,   366,    -1,   373,   262,
     374,    -1,   376,   253,   254,    -1,   376,   259,   289,   253,
     254,    -1,   376,     9,   376,   259,   289,   253,   254,    -1,
       4,   261,   257,   346,   258,    -1,   375,   261,   257,   346,
     258,    -1,   225,   255,   366,   256,   261,   257,   346,   258,
      -1,     4,    -1,   375,    -1,   225,   255,   366,   256,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   270,   270,   271,   276,   278,   282,   283,   284,   285,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   323,   327,   334,   339,
     344,   349,   363,   376,   389,   402,   430,   444,   457,   470,
     489,   494,   495,   496,   497,   498,   499,   503,   505,   510,
     512,   518,   622,   517,   640,   647,   658,   657,   675,   682,
     693,   692,   709,   726,   749,   748,   762,   763,   764,   765,
     766,   770,   771,   777,   777,   779,   779,   784,   785,   786,
     787,   788,   794,   795,   796,   797,   802,   808,   870,   885,
     914,   924,   929,   937,   942,   950,   959,   964,   976,   993,
     999,  1008,  1026,  1044,  1053,  1065,  1070,  1078,  1098,  1121,
    1141,  1149,  1171,  1194,  1232,  1253,  1265,  1279,  1279,  1281,
    1283,  1292,  1302,  1301,  1322,  1321,  1339,  1349,  1348,  1362,
    1364,  1372,  1378,  1383,  1410,  1412,  1415,  1417,  1421,  1422,
    1426,  1438,  1442,  1446,  1459,  1473,  1481,  1494,  1496,  1500,
    1501,  1506,  1514,  1523,  1531,  1545,  1563,  1567,  1574,  1583,
    1586,  1592,  1596,  1608,  1611,  1618,  1621,  1627,  1650,  1666,
    1682,  1699,  1716,  1753,  1797,  1813,  1829,  1861,  1877,  1894,
    1910,  1960,  1978,  1984,  1990,  1997,  2028,  2043,  2065,  2088,
    2111,  2134,  2158,  2182,  2206,  2232,  2249,  2265,  2283,  2301,
    2313,  2327,  2326,  2356,  2358,  2360,  2362,  2364,  2372,  2374,
    2376,  2378,  2386,  2388,  2390,  2398,  2400,  2402,  2404,  2414,
    2430,  2446,  2462,  2478,  2494,  2511,  2548,  2570,  2594,  2595,
    2600,  2603,  2607,  2624,  2644,  2664,  2683,  2710,  2729,  2750,
    2765,  2781,  2799,  2850,  2871,  2893,  2916,  3021,  3037,  3072,
    3094,  3116,  3128,  3134,  3149,  3177,  3189,  3198,  3205,  3217,
    3237,  3241,  3246,  3250,  3255,  3262,  3269,  3276,  3288,  3361,
    3379,  3404,  3419,  3452,  3464,  3496,  3500,  3505,  3512,  3517,
    3527,  3532,  3538,  3546,  3550,  3554,  3558,  3562,  3566,  3570,
    3579,  3643,  3659,  3676,  3693,  3715,  3737,  3772,  3780,  3788,
    3794,  3801,  3808,  3828,  3854,  3866,  3877,  3895,  3913,  3932,
    3931,  3956,  3955,  3982,  3981,  4006,  4005,  4028,  4044,  4061,
    4078,  4101,  4129,  4132,  4138,  4150,  4170,  4174,  4178,  4182,
    4186,  4190,  4194,  4198,  4207,  4220,  4221,  4222,  4223,  4224,
    4228,  4229,  4230,  4231,  4232,  4235,  4259,  4278,  4301,  4304,
    4320,  4323,  4340,  4343,  4349,  4352,  4359,  4362,  4369,  4391,
    4432,  4476,  4515,  4540,  4552,  4564,  4576,  4588,  4605,  4622,
    4652,  4678,  4704,  4736,  4763,  4789,  4815,  4841,  4867,  4889,
    4900,  4948,  5002,  5017,  5029,  5040,  5047,  5062,  5076,  5077,
    5078,  5082,  5088,  5100,  5118,  5146,  5147,  5148,  5149,  5150,
    5151,  5152,  5153,  5154,  5161,  5162,  5163,  5164,  5165,  5166,
    5167,  5168,  5169,  5170,  5171,  5172,  5173,  5174,  5175,  5176,
    5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,  5185,  5186,
    5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,  5195,  5196,
    5197,  5198,  5199,  5200,  5209,  5210,  5211,  5212,  5213,  5214,
    5215,  5216,  5217,  5218,  5219,  5224,  5223,  5231,  5233,  5238,
    5243,  5247,  5252,  5257,  5261,  5265,  5269,  5273,  5277,  5281,
    5287,  5302,  5306,  5312,  5317,  5336,  5356,  5377,  5381,  5385,
    5389,  5393,  5397,  5401,  5406,  5416,  5426,  5431,  5442,  5451,
    5456,  5461,  5489,  5490,  5496,  5497,  5503,  5502,  5525,  5527,
    5532,  5534,  5540,  5541,  5546,  5550,  5554,  5558,  5562,  5569,
    5573,  5577,  5581,  5588,  5593,  5600,  5605,  5609,  5614,  5618,
    5626,  5637,  5641,  5645,  5659,  5667,  5675,  5682,  5692,  5715,
    5720,  5726,  5731,  5737,  5748,  5754,  5760,  5766,  5778,  5792,
    5802,  5812,  5822,  5834,  5838,  5843,  5855,  5859,  5863,  5867,
    5885,  5893,  5901,  5930,  5940,  5956,  5967,  5972,  5976,  5980,
    5992,  5996,  6008,  6025,  6035,  6039,  6054,  6059,  6066,  6070,
    6075,  6089,  6103,  6107,  6111,  6115,  6119,  6127,  6133,  6142,
    6146,  6150,  6158,  6164,  6170,  6174,  6181,  6189,  6196,  6205,
    6209,  6213,  6228,  6242,  6256,  6268,  6284,  6293,  6302,  6312,
    6323,  6331,  6339,  6343,  6362,  6369,  6375,  6381,  6388,  6396,
    6395,  6405,  6429,  6431,  6437,  6442,  6444,  6449,  6454,  6459,
    6461,  6465,  6477,  6491,  6495,  6502,  6510,  6518,  6529,  6531,
    6534
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
  "tElliptic", "tRefineMesh", "tAdaptMesh", "tRelocateMesh",
  "tReorientMesh", "tSetFactory", "tThruSections", "tWedge", "tFillet",
  "tChamfer", "tPlane", "tRuled", "tTransfinite", "tPhysical", "tCompound",
  "tPeriodic", "tParent", "tUsing", "tPlugin", "tDegenerated",
  "tRecursive", "tSewing", "tRotate", "tTranslate", "tSymmetry", "tDilate",
  "tExtrude", "tLevelset", "tAffine", "tBooleanUnion",
  "tBooleanIntersection", "tBooleanDifference", "tBooleanSection",
  "tBooleanFragments", "tThickSolid", "tRecombine", "tSmoother", "tSplit",
  "tDelete", "tCoherence", "tIntersect", "tMeshAlgorithm", "tReverseMesh",
  "tMeshSizeFromBoundary", "tLayers", "tScaleLast", "tHole", "tAlias",
  "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
  "tQuadTriNoNewVerts", "tRecombLaterals", "tTransfQuadTri", "tText2D",
  "tText3D", "tInterpolationScheme", "tTime", "tCombine", "tBSpline",
  "tBezier", "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor",
  "tColorTable", "tFor", "tIn", "tEndFor", "tIf", "tElseIf", "tElse",
  "tEndIf", "tExit", "tAbort", "tField", "tReturn", "tCall", "tSlide",
  "tMacro", "tShow", "tHide", "tGetValue", "tGetStringValue", "tGetEnv",
  "tGetString", "tGetNumber", "tUnique", "tHomology", "tCohomology",
  "tBetti", "tExists", "tFileExists", "tGetForced", "tGetForcedStr",
  "tGMSH_MAJOR_VERSION", "tGMSH_MINOR_VERSION", "tGMSH_PATCH_VERSION",
  "tGmshExecutableName", "tSetPartition", "tNameToString", "tStringToName",
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
      63,   485,   486,   487,   488,    60,    62,   489,   490,   491,
     492,    43,    45,    42,    47,    37,   124,    38,    33,   493,
     494,   495,    94,    40,    41,    91,    93,   123,   125,    46,
      35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   263,   264,   264,   265,   265,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   269,   269,
     270,   270,   270,   270,   270,   270,   270,   271,   271,   272,
     272,   274,   275,   273,   276,   276,   278,   277,   279,   279,
     281,   280,   282,   282,   284,   283,   285,   285,   285,   285,
     285,   286,   286,   287,   287,   288,   288,   289,   289,   289,
     289,   289,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   291,   291,   292,
     292,   292,   293,   292,   294,   292,   292,   295,   292,   296,
     296,   297,   297,   297,   298,   298,   299,   299,   300,   300,
     301,   301,   301,   301,   301,   301,   301,   302,   302,   303,
     303,   304,   304,   304,   304,   304,   305,   305,   305,   306,
     306,   306,   306,   307,   307,   308,   308,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   310,   309,   311,   311,   311,   311,   311,   312,   312,
     312,   312,   313,   313,   313,   314,   314,   314,   314,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   316,   316,
     317,   317,   317,   317,   317,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   319,
     319,   319,   319,   319,   319,   319,   319,   320,   320,   321,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   324,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   326,   326,   326,   327,
     326,   328,   326,   329,   326,   330,   326,   326,   326,   326,
     326,   326,   331,   331,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   333,   333,   333,   333,   333,
     334,   334,   334,   334,   334,   335,   335,   336,   337,   337,
     338,   338,   339,   339,   340,   340,   341,   341,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   343,   343,   343,   344,   344,
     344,   345,   345,   345,   345,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   348,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   349,   349,   350,   350,   352,   351,   353,   353,
     354,   354,   355,   355,   356,   356,   356,   356,   356,   357,
     357,   357,   357,   358,   358,   359,   359,   359,   359,   359,
     359,   360,   360,   360,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   362,   362,   362,   362,
     363,   363,   363,   363,   364,   364,   365,   365,   366,   366,
     366,   366,   366,   366,   366,   366,   366,   366,   366,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     367,   367,   369,   369,   370,   371,   371,   372,   373,   373,
     373,   373,   374,   374,   374,   375,   375,   375,   376,   376,
     376
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
      11,     5,     9,     9,     7,     4,     9,     9,     1,     1,
       0,     2,     6,     7,     7,     6,     7,     8,    10,    14,
      16,    12,    14,    14,    14,    14,     8,     8,     6,     4,
       5,     5,     6,     6,     3,     4,     3,     5,     6,     5,
       4,     3,     4,     3,     4,     5,     4,     5,     3,     5,
       7,     7,     3,     7,     3,     2,     2,     2,     2,     2,
      15,     2,     2,     2,     9,    11,     2,     2,     2,     2,
      16,    11,     6,     8,     8,    10,     1,     2,     2,     1,
       3,     3,     4,     4,     1,     1,     5,    11,    13,     0,
       7,     0,    13,     0,    15,     0,     6,     9,     2,     3,
      10,    13,     1,     2,     5,     7,     2,     2,     3,     2,
       3,     2,     3,     9,     6,     1,     1,     1,     1,     1,
       0,     2,     3,     3,     4,     9,     4,    14,     0,     3,
       0,     1,     0,     2,     0,     2,     0,     2,     6,     7,
       6,     5,     3,     8,     8,     8,     8,     8,     8,     5,
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
       2,     4,     2,     3,     3,    16,     5,     5,     5,     1,
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
       0,     0,     0,     0,   335,   336,   337,   338,   339,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,   304,   305,     0,     0,     0,   299,     0,     0,
       0,     0,     0,   388,   389,   390,     0,     0,     5,     6,
       7,     8,    10,     0,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,     0,   629,     0,   230,     0,     0,     0,     0,     0,
       0,   279,     0,   281,   282,   277,   278,     0,   283,   286,
       0,   287,   288,   119,   129,   628,   502,   498,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   289,     0,
     215,   216,   217,     0,     0,     0,     0,   444,   445,   447,
     448,   446,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     452,   453,   454,     0,     0,   203,   208,   209,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   450,   451,     0,     0,     0,     0,     0,     0,     0,
       0,   539,   540,     0,   541,   515,   395,   457,   460,   318,
     516,   498,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,   204,   205,   206,   201,   208,   209,     0,   210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,     0,     0,   230,
       0,     0,   385,     0,     0,     0,   212,   213,     0,     0,
       0,     0,     0,     0,   523,     0,     0,   521,     0,     0,
       0,     0,     0,   628,     0,     0,   562,     0,     0,     0,
       0,   275,   276,     0,   579,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   581,     0,
     605,   606,   583,   584,     0,     0,     0,     0,     0,     0,
     582,     0,     0,     0,     0,   297,   298,     0,   230,     0,
     230,     0,     0,     0,   498,     0,     0,     0,   230,   391,
       0,     0,    84,     0,    66,     0,     0,    70,    69,    68,
      67,    72,    71,    73,    74,     0,     0,     0,     0,     0,
       0,     0,   568,   498,     0,   229,     0,   228,     0,   182,
       0,     0,   568,   569,     0,     0,     0,   618,     0,   619,
     569,     0,   117,   117,     0,   496,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   556,   557,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   530,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   398,     0,   397,
     524,   399,     0,   517,     0,     0,   498,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,   474,     0,     0,     0,     0,     0,
       0,     0,   319,     0,   352,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,   230,
     230,     0,   506,   505,     0,     0,     0,     0,   230,   230,
       0,     0,     0,     0,   315,     0,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   354,     0,
       0,     0,     0,     0,   230,   256,     0,     0,   254,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,   274,     0,     0,     0,     0,     0,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   301,   300,     0,   261,     0,
       0,   263,     0,     0,     0,   397,     0,   230,     0,     0,
       0,     0,     0,     0,     0,   340,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,     0,
       0,     0,     0,    88,    75,    76,     0,     0,     0,   272,
      40,   268,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,   231,     0,     0,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,     0,     0,     0,   500,
       0,     0,   499,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   346,     0,     0,     0,   207,     0,
       0,     0,     0,     0,     0,   381,   382,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   455,   473,     0,     0,     0,     0,   533,   534,     0,
       0,     0,     0,     0,   492,     0,   396,   518,     0,     0,
       0,     0,   526,     0,   415,   414,   413,   412,   408,   409,
     416,   417,   411,   410,   401,   400,     0,   402,   525,   403,
     406,   404,   405,   407,   499,     0,     0,   477,     0,   542,
       0,     0,     0,     0,     0,     0,     0,     0,   350,     0,
       0,     0,     0,     0,     0,   384,     0,     0,     0,     0,
     383,     0,   230,     0,     0,     0,     0,     0,   508,   507,
       0,     0,     0,     0,     0,     0,     0,   309,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   370,     0,     0,   255,     0,     0,     0,   249,     0,
       0,     0,     0,   380,     0,     0,     0,     0,   396,   522,
       0,     0,     0,     0,     0,     0,     0,     0,   302,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,     0,
       0,     0,   494,     0,     0,   260,   264,   262,   266,     0,
     402,     0,   499,   477,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,   396,     0,     0,
       0,    66,     0,     0,    87,     0,    66,    67,     0,     0,
       0,   499,     0,     0,   477,     0,     0,     0,   201,     0,
       0,     0,   625,    28,    26,    27,     0,     0,     0,     0,
       0,   572,    30,     0,    29,     0,     0,   269,   620,   621,
       0,   622,   572,     0,    82,   120,    83,   130,   501,   503,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,   559,
     218,     9,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   441,   428,     0,   430,   431,   432,   433,   434,   555,
     435,   436,   437,     0,     0,     0,     0,     0,   547,   546,
     545,     0,     0,     0,   552,     0,   489,     0,     0,     0,
     491,     0,     0,     0,   134,   472,   529,   528,   211,     0,
       0,   458,   554,   463,     0,   469,     0,     0,     0,     0,
     519,     0,     0,   470,     0,   531,     0,     0,     0,     0,
     462,   461,    73,    74,   484,     0,     0,     0,     0,     0,
       0,     0,   396,   348,   353,   351,     0,   361,     0,   156,
     157,     0,   211,     0,   396,     0,     0,     0,     0,   250,
       0,   265,   267,     0,     0,     0,   219,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   322,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,     0,   355,   369,     0,     0,     0,   251,
       0,     0,     0,     0,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,     0,     0,     0,   595,
       0,   602,   591,   592,   593,     0,   608,   607,     0,     0,
     596,   597,   598,   604,   612,   611,     0,   147,     0,   585,
       0,   587,     0,     0,     0,   580,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   341,     0,     0,     0,   392,
       0,   626,     0,   109,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,     0,     0,
       0,   577,    51,     0,     0,     0,    64,     0,    41,    42,
      43,    44,    45,    46,     0,   462,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   571,
     570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,   137,   138,     0,     0,     0,     0,
       0,     0,     0,   163,   163,     0,     0,     0,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   536,   537,   538,     0,
       0,     0,     0,     0,   492,   493,     0,   465,     0,     0,
       0,   527,   418,   520,   478,   476,     0,   475,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     360,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,   258,     0,     0,     0,     0,     0,     0,     0,   327,
       0,     0,   326,     0,   329,     0,   331,     0,   316,   323,
       0,     0,     0,   248,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   371,     0,   253,   252,   387,     0,     0,
       0,    37,    38,     0,     0,     0,     0,   563,     0,     0,
       0,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   495,   589,     0,   478,     0,     0,
     230,   342,     0,   343,   230,     0,     0,   578,     0,    94,
       0,     0,     0,     0,    92,     0,   566,     0,   107,     0,
      99,   101,     0,     0,     0,    89,     0,     0,     0,     0,
       0,    36,   478,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,     0,   573,     0,
       0,    34,    33,     0,   573,   623,     0,     0,   121,   126,
       0,     0,     0,   140,   145,   146,   141,   142,   497,     0,
      85,     0,     0,     0,     0,    86,   167,     0,     0,     0,
       0,   168,   185,   186,   165,     0,     0,     0,   169,   196,
     187,   191,   192,   188,   189,   190,   177,     0,     0,   429,
     443,   442,   438,   439,   440,   548,     0,     0,     0,   487,
     488,   490,   135,   456,   486,   459,   464,     0,     0,   492,
     197,   471,     0,    73,    74,     0,   483,   479,   481,   549,
     193,     0,     0,     0,   159,     0,     0,   359,     0,   158,
       0,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   230,   230,     0,     0,   328,   515,     0,     0,   330,
     332,     0,     0,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   224,   194,     0,     0,     0,     0,
       0,   174,   175,     0,     0,     0,     0,   110,   114,     0,
     603,     0,     0,   601,     0,   613,     0,     0,   148,   149,
     610,   586,   588,     0,     0,     0,     0,     0,     0,   340,
     344,   340,     0,   393,    93,     0,     0,    66,     0,     0,
      91,     0,   564,     0,     0,     0,     0,     0,     0,   616,
     615,     0,     0,     0,     0,     0,   513,     0,     0,    77,
     270,   479,   271,     0,     0,     0,     0,     0,   235,   232,
       0,     0,   576,   574,     0,     0,     0,     0,   122,   127,
       0,     0,     0,   556,   557,   139,   363,   364,   365,   366,
     164,   172,   173,   178,     0,     0,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,   466,     0,     0,     0,
       0,   544,   485,     0,     0,   179,     0,   198,   349,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
     512,   511,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   246,     0,     0,     0,     0,     0,     0,
       0,     0,   237,     0,     0,   367,   368,    39,     0,   561,
       0,     0,   294,   293,     0,     0,     0,     0,     0,     0,
     151,   152,   155,   154,   153,     0,   590,     0,   627,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,   567,
       0,     0,     0,    96,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    49,     0,   236,   233,   234,    35,     0,
       0,   624,   284,     0,   134,   147,     0,     0,   144,     0,
       0,     0,   166,   195,     0,     0,     0,     0,     0,   550,
     551,     0,   492,   467,     0,   480,   482,     0,     0,   181,
     202,     0,     0,     0,   356,   356,     0,   115,   116,   230,
       0,   222,   223,   317,     0,   324,     0,     0,   230,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   226,     0,
       0,     0,     0,   111,   112,   594,   600,   599,   150,     0,
       0,     0,   345,     0,     0,   108,   100,   102,     0,    90,
     617,    97,    98,    52,     0,     0,     0,     0,   514,     0,
       0,   480,   575,     0,     0,     0,     0,   124,   614,     0,
     131,     0,     0,     0,     0,   184,     0,     0,     0,     0,
     320,     0,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   510,     0,   334,     0,     0,   311,
       0,   238,     0,     0,     0,     0,     0,     0,     0,   560,
     295,     0,     0,   379,   230,   394,     0,   565,     0,    48,
       0,     0,     0,    65,    50,     0,   285,   123,   128,   134,
       0,     0,   161,   162,   160,     0,     0,   468,     0,     0,
       0,     0,     0,   357,   372,     0,     0,   373,     0,   220,
       0,   325,     0,   307,     0,   230,     0,     0,     0,     0,
       0,     0,   176,   113,   291,   340,   106,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,   200,
       0,   376,     0,   377,   378,   509,     0,     0,   313,   241,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
      62,     0,     0,   125,     0,     0,     0,   321,     0,     0,
     333,   312,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,   244,   245,     0,   239,   347,    53,
       0,    60,     0,   280,     0,   553,     0,     0,     0,   314,
       0,     0,    54,     0,     0,   290,     0,     0,     0,   240,
       0,     0,     0,     0,   535,     0,     0,    57,    55,     0,
      58,     0,   374,   375,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,  1086,   119,   120,  1070,  1936,  1942,
    1368,  1586,  2098,  2231,  1369,  2202,  2249,  1370,  2233,  1371,
    1372,  1590,   446,   604,   605,  1158,  1686,   121,   796,   472,
    1954,  2109,  1955,   473,  1822,  1450,  1403,  1404,  1405,  1550,
    1758,  1759,  1228,  1647,  1638,  1835,   773,   616,   279,   280,
     359,   204,   281,   456,   457,   125,   126,   127,   128,   129,
     130,   131,   132,   282,  1262,  2134,  2193,   965,  1258,  1259,
     283,  1049,   284,   136,  1479,  1226,   938,   980,  2068,   137,
     138,   139,   140,   285,   286,  1184,  1199,  1324,   287,   801,
     288,   800,   475,   633,   327,  1795,   367,   368,   290,   574,
     375,  1352,  1577,   467,   462,  1317,  1026,  1625,  1788,  1789,
    1011,   469,   142,   424
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1929
static const yytype_int16 yypact[] =
{
   13163,    67,    85, 13365, -1929, -1929,  -202,   147,     1,  -124,
    -114,  -109,    36,   169,   184,   222,   245,     9,   282,   354,
     107,   379,   383,   174,   196,    19,   126,   687,   126,   205,
     285,   300,    58,   314,   336,    61,   342,   365,   373,   401,
     420,   429,   435,   447,   453,   459,   377,   565,   630,   734,
     486,    88,   680,   521,  7119,   527,   492,   533,   692,   -46,
     537,   615,   306,   616,   547,   730,   -90,   570,   251,   251,
     576,   341,   405,   585, -1929, -1929, -1929, -1929, -1929,   613,
     312,   769,   773,    20,    42,   780,   799,   143,   811,   891,
     917,   924,  6115,   934,   719,   726,   736,    11,    64, -1929,
     757,   768, -1929, -1929,   935,   938,   700, -1929, 13609,   776,
   13645,    25,    29, -1929, -1929, -1929, 12145,   781, -1929, -1929,
   -1929, -1929, -1929,   695, -1929, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, -1929,  -158, -1929, -1929, -1929, -1929,    50,
   -1929,  1025,   777,  5854,   484,   711,  1033, 12145, 13547, 13547,
   13547, -1929, 12145, -1929, -1929, -1929, -1929, 13547, -1929, -1929,
   12145, -1929, -1929, -1929, -1929,   784,   814,  1043, -1929, -1929,
    1538,   817,   826,   834,   835,    19, 12145, 12145, 12145,   836,
   12145, 12145, 12145,   838, 12145, 12145, 12145, 12145, 12145, 12145,
   12145, 13547, 12145, 12145, 12145, 12145,  6115,   839, -1929,  9870,
   -1929, -1929, -1929,   796,  6115,  7370, 13547, -1929, -1929, -1929,
   -1929, -1929,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   242,   126,   126,
     126,   126,   126,   840,   126,   126,   841,   615,   622,   622,
   -1929, -1929, -1929,   126,   126,    35,   864,   890,   904,   843,
    7370,   966,   615,   615,   844,   126,   126,   848,   849,   850,
   -1929, -1929, -1929, 12145,  7621, 12145, 12145,  7872,    19,   913,
      49, -1929, -1929,   851, -1929,  4536, -1929, -1929, -1929, -1929,
   -1929,    95, 12145,  9870,  9870,   852,   853,  8123,  6115,  6115,
    6115, -1929, -1929, -1929, -1929, -1929, -1929, -1929,   854, -1929,
     855,   856,  8374,   857,  4921,  1106,  7370,   875,    11,   876,
     878,   251,   251,   251, 12145, 12145,  -122, -1929,   -37,   251,
   10803,   290,  -123,   858,   868,   901,   902,   908,   910,   911,
    9870, 12145,  6115,  6115,  6115,   912,    15,  1151,   918, -1929,
    1153,  1161, -1929,   915,   920,   921, -1929, -1929,   922,  6115,
     925,   926,   928,   930, -1929, 12145,  6366, -1929,  1162,  1183,
   12145, 12145, 12145,   471, 12145,   933, -1929,  1000, 12145, 12145,
   12145, -1929, -1929, 12145, -1929,   126,   126,   126,   939,   940,
     941,   126,   126,   126,   126,   126,   126,   126, -1929,   126,
   -1929, -1929, -1929, -1929,   126,   126,   942,   943,   126,   944,
   -1929,   945,  1193,  1195,   946, -1929, -1929,  1196,  1197,  1198,
    1199,   126, 12145, 12102,   123, 13547,  9870, 12145, -1929, -1929,
    7370,  7370, -1929,   949,  1538,   615,  1201, -1929, -1929, -1929,
   -1929, -1929, -1929, 12145, 12145,    54,  7370,  1203,   501,   953,
    1910,   954,  1211,    28,   961, -1929,   964, 11534, 12145, -1929,
    2221,   -40, -1929,    57,   -21,    -8,  8560, -1929,     7, -1929,
     102,  8811,   -77,   -62,  1124, -1929,    19,   963, 12145, 12145,
   12145, 12145,   965, 15918, 15943, 15968, 12145, 15993, 16018, 16043,
   12145, 16068, 16093, 16118, 16143, 16168, 16193, 16218,   969, 16243,
   16268, 16293, 14531,  1217, 12145,  9870,  6050, -1929,   210, 12145,
    1220,  1222,   975, 12145, 12145, 12145, 12145, 12145, 12145, 12145,
   12145, 12145, 12145, 12145, 12145, 12145, 12145, 12145, 12145,  9870,
   12145, 12145, 12145, 12145, 12145, 12145, 12145, 12145,  9870,  9870,
     973, 12145, 12145, 13547, 12145, 13547,  7370, 13547, 13547, 13547,
     976,   977,   978, 12145,    48, -1929, 10889, 12145,  7370,  6115,
    7370, 13547, 13547,  9870,    19,  1538,    19,   984,  9870,   984,
   -1929,   984, 16318, -1929,   232,   979,    94,  1170, -1929,  1231,
   12145, 12145, 12145, 12145, 12145, 12145, 12145, 12145, 12145, 12145,
   12145, 12145, 12145, 12145,  8625, 12145, 12145, 12145, 12145, 12145,
      19, 12145, 12145,    40, -1929,   766, 16343,   279,   292, 12145,
   12145, 12145, -1929,  1233,  1234,  1234,   989, 12145, 12145, 12145,
   12145,  1237,  9870,  9870, 15430,   990,  1239, -1929,   991, -1929,
   -1929,  -135, -1929, -1929,  9057,  9303,   251,   251,   484,   484,
    -104, 10803, 10803, 12145,   329,   -89, -1929, 12145, 12145, 12145,
   12145, 12145, 12145, 12145, 12145, 12145,   455, 16368,  1244,  1240,
    1245, 12145,  1247, 12145, -1929, -1929, 12145,  5908, -1929, -1929,
    9870,  9870,  9870, 12145,  1248,  9870, 12145, 12145, 12145, 16393,
     997, -1929, -1929, 16418, 16443, 16468,  1068,  9554, -1929,  1002,
    6301, 16493, 16518, 15513, 13547, 13547, 13547, 13547, 13547, 13547,
   13547, 13547, 13547, 12145, 13547, 13547, 13547, 13547,     5,  1538,
   13547, 13547, 13547,    19,    19, -1929, -1929,  9870, -1929,   999,
   12173, -1929,  1003, 12305, 12145,   984, 12145, -1929,    19, 12145,
   12145,    40,  1004,   540, 16543, 11195,  1009,   574, 12145,  1258,
    1008,  7370, 16568, 15540, -1929, -1929, -1929, -1929, -1929,  1007,
    1261,   167,  1263, -1929, -1929, -1929,  9870,   171, 12145, -1929,
   -1929, -1929,    19, 12145, 12145,    40,  1016, -1929,  1019,   -44,
     615,   306,   615, -1929,  1018, 14560, -1929,   115,  9870,    19,
   12145, 12145,    40,  1267,  9870,  1271,  9870, 12145,  1275, 13547,
      19, 11135,    40, 12145,  1276, -1929,    19,  1277, 13547, 12145,
    1030,  1034, -1929, 12145,  9805, 10147, 10493, 10755,  1538,  1278,
    1283,  1284, 16593,  1288,  1289,  1291, 16618,  1292,  1293,  1294,
    1296,  1297,  1298,  1300, -1929,  1301,  1302,  1303, -1929, 12145,
   16643,  9870,  1054,  9870, 14589, -1929, -1929,  1306, 15486, 15486,
   15486, 15486, 15486, 15486, 15486, 15486, 15486, 15486, 15486, 10834,
   15486, 15486, 15486, 15486,   906,   568, 15486, 15486, 15486, 11166,
   11505, 11765, 11844, 12011,  6050,  1059,  1058,    79,  9870, 12982,
   13162,   568, 13543,   568,  1056,  1057,  1060,   121,  9870, 12145,
   12145, 12292, -1929,   568,  1063, 14618, 14647, -1929, -1929,  1061,
    -187,   568,  -142,  1062,   331,   602,  1317, -1929,    40,   568,
    1069,  1067,  6552,  6803,  1149,  1410,   525,   525,   434,   434,
     434,   434,   434,   434,   594,   594,  9870,   481, -1929,   481,
     481,   984,   984,   984,  1071, 16668, 15567,   608,  9870, -1929,
    1320,  1075,  1076, 16693, 16718, 16743, 12145,  7370,  1324,  1328,
   10557, 16768, 14676, 16793, 16818, -1929,   611,   620,  9870,  1077,
   -1929, 12363, -1929, 12448, 12506,   251, 12145, 12145, -1929, -1929,
    1079,  1080, 10803,  7305,  1200,   577,   251, 12591, 16843, 14705,
   16868, 16893, 16918, 16943, 16968, 16993, 17018,  1082,  1333, 12145,
    1336, -1929, 12145, 17043, -1929, 15594, 12649, 15621, -1929,   629,
     631,   632, 14734, -1929,   638, 15648, 15675, 13640, -1929, -1929,
    1337,  1338,  1339,  1084, 12145, 12734, 12145, 12145, -1929, -1929,
      46,   308,   323,   308,  1095,  1096,  1089,   568,   568,  1091,
   13673,   568,   568,   568,   568, 12145,   568,  1345, -1929,  1093,
    1102,   494,    74,  1101,   639, -1929, -1929, -1929, -1929, 15486,
     481, 12792,  1099,   617,  1103,  1169,  1355,  1204, 11228,  1107,
    1110,  1362,  7370, 14763, -1929, 12145,  1363,   228,    72,    40,
      27,  1538, 12145,  1364, -1929,   640,  1322,  1323,  7370, 14792,
      31,  1115, 17068, 15702,   597, 12145, 12145,  1123,  1120,  1126,
    1142,  8876, -1929, -1929, -1929, -1929, 13547,   158,  1141, 17093,
   15729,  1150, -1929,   162, -1929,   199, 13706, -1929, -1929, -1929,
    1143, -1929,  1152, 13739, -1929,    71, -1929, -1929, 12292, -1929,
      56, 15486, 12145, 12145, 12145, 12145,   568,   251,  7370,  7370,
    1397,  7370,  7370,  7370,  1399,  7370,  7370,  7370,  7370,  7370,
    7370,  7370,  7370,  7370,  7370,  2365,  1400,  9870,  6050, -1929,
   -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, 12145, -1929, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929, -1929, 12145, 12145, 12145, 12145, 12145, -1929, -1929,
   -1929,   646, 12145, 12145, -1929, 12145, -1929,  7370, 13547, 13547,
   -1929,   647, 14821, 14850,  1146, -1929, -1929, -1929,  1218, 12145,
   12145, -1929, -1929, -1929,    40, -1929,    40, 12145, 12145,  1156,
   -1929,  7370,   126, -1929, 12145, -1929, 12145, 12145,   649,    40,
     156,  -102, 12145, 12145, -1929,   568,   657,  7370,  9870,  9870,
    1404,  1406,  1407,  3053, -1929, -1929,  1409, -1929,  1163, 12292,
    1157,  1411, -1929,  1413,  1414,  1415,  1416,   662,    45, -1929,
   12877, -1929, -1929,   -82, 13772, 13805, -1929, -1929, 14879,  -171,
    1305,  1430, 11474,  1187,  1439,  1202,    30,    37,   359, -1929,
     -79, -1929,   577,  1441,  1443,  1445,  1446,  1449,  1450,  1451,
    1452,  1453,   484,  7370, 12292, -1929,  2463,  1205,  1444, -1929,
    1455,  1457,  1357,  1458, -1929,  1460,  1462,  1463, 12145,  7370,
    7370,  7370,  1466, 13838, -1929,  7054,  1567,    40,    40, -1929,
    9870, -1929, -1929, -1929, -1929, 13547, -1929, -1929, 12145, 13547,
   -1929, -1929, -1929, -1929, 12292, -1929,  1216,  1209, 13547, -1929,
   13547, -1929,    40, 13547,  1223, -1929,  1221, -1929,    40, 12145,
   12145,  1227,   615,  1228, 11567, -1929,  2486,  1229,  7370, -1929,
    1230, -1929, 14908, -1929, -1929, 12145,  1472,    60, 12145,  1473,
    1482,    11,  1484,  1236,  1486,  2587, -1929,   568,   126,   126,
    1487, -1929, -1929,  1241,  1242,  1243, -1929,  1490, -1929, -1929,
   -1929, -1929, -1929, -1929,    40,   528,   962, 12145, 15756, 17118,
   12145,  9122, 12145,  9870,  1246,   665,  1491,   122,    40, -1929,
    1249, 12145,  1493,  1496, 12145,    40, 11813, 12145, 10116,   568,
    5321, 12145, 12145,  1250,  1251, -1929,  1499, 17143, 17168, 17193,
   17218,  1501,   125,  1376,  1376,  7370,  1505,  1506,  1508,  7370,
     -91,  1509,  1510,  1512,  1513,  1516,  1517,  1518,  1519,  1520,
   -1929,  1522,   668, 15486, 15486, 15486, 15486, 15486, 15486,   568,
   13871, 13904, 13937,  1274,   568,   568, -1929, -1929, -1929,    56,
     568, 17243, 15486,  1279,   268, 12292, 15486, -1929,  1524,   568,
   13970, 12292, 12292, -1929,   598, -1929,    40, -1929, 17268, 15783,
   -1929,   568,  1525,   671,   678,  7370,  7370,  7370,  1528,  1529,
   -1929,   175, 12145,  7370,  7370,  7370,  1280,  1281,  1527,  1530,
    1532, -1929, 12145, 12145, 12145,  1287,  1290,  1295,  1285, -1929,
    3090,  7370, -1929, 12145, -1929,  1535, -1929,  1539, -1929, -1929,
   10803,   483,  6617, -1929,  1299,  1304,  1307,  1308,  1309,  1310,
    9368,  1311,  1540, -1929,  9870, -1929, -1929, -1929,  1313, 12145,
   12145, -1929, -1929, 15810,  1543,  1544,  1366, -1929, 12145, 12145,
   12145, -1929,  1545,   518,   567,  1314,  3892,  1315, 12145,    34,
     568,  1319,   568,  1316, -1929, -1929,  1538,   735, 12145,  1325,
   -1929, -1929,  3332, -1929, -1929,  1321,  1548, -1929,  3869, -1929,
    1312,  1550,   248,  4078, -1929,    11, -1929,   681, -1929, 12145,
   -1929, -1929,   175,  2313,  4979, -1929,  1326, 12145, 12145,  7370,
    1327, -1929,   254,   105,  1549, 17293,  1552,  1317, 17318,  1340,
     688, 17343,   689,  1553,  1556, -1929, -1929, 13547,  1332,  1559,
   17368, -1929, -1929, 14003,  1343, -1929,  7556,  5587, 12292, -1929,
    1590,   126,  7872, -1929, -1929, -1929, 12292, 12292, -1929,    56,
   -1929,  1562,  1593,  1599,  1600, -1929, -1929,   251,  1601,  1606,
    1607, -1929, -1929, -1929,  1474,   -18,  1515,  1611, -1929, -1929,
   -1929, -1929, -1929, -1929, -1929, -1929, -1929,  1616,  1365, -1929,
   -1929, -1929, -1929, -1929, -1929, -1929, 12145, 12145, 12145, -1929,
   -1929, -1929,  1251, -1929, -1929, -1929, -1929, 12145,  1369,  1367,
   -1929, -1929, 12145, 12145, 12145,   568,   156, -1929, -1929, -1929,
   -1929,  1368,  1370,  1618,   -91,  1620, 12145, -1929,  7370, 12292,
    1489,  1492,  1024,  9870,  9870, 12145, -1929, 10557, 14937, 17393,
    7807,   484,   484, 12145, 12145, -1929,   369,  1372, 17418, -1929,
   -1929, 14966,   -65, -1929,  1622,  1625,  7370,   251,   251,   251,
     251,   251,  6868,  1630, -1929, -1929,   691, 12145,  4160,  4185,
    1631, -1929, -1929,  7370,  8058,   573, 17443, -1929, -1929, 10211,
   -1929, 13547, 12145, -1929, 13547, 12292, 10462,  1538,  1377, -1929,
   -1929, -1929, -1929,  1386,  1379, 12145, 12145, 14995, 12145, 11195,
   -1929, 11195,  7370, -1929, -1929,    40,    27,  1538, 12145,  1652,
   -1929,  1653, -1929,    11, 15837,  7370, 13547,  1654,   568, -1929,
    1401,   568, 12145, 14036, 14069,   696, -1929, 12145, 12145,  1417,
   -1929,  1418, -1929,  1407,  1655,  1664,  1414,  1665, -1929, -1929,
    1666, 12145, -1929, -1929, 12145, 11899,  1667, 12145, -1929, -1929,
    1419,  4979,   699,  5257,  1670, -1929, -1929, -1929, -1929, -1929,
     421, -1929, -1929, -1929,  1533,  1673,  1424,  1426,  1429, -1929,
    1684,  7370, 15486, 15486, 14102, 15486, -1929,  1436, 14135, 17468,
   15864, -1929, -1929,  9870,  9870, -1929,  1685, -1929, 12292,  1686,
   12145, 12145,  1437, -1929,   701,   702, 15458,  4296,  1687,  1440,
   -1929, -1929, 12145,  1447,  1448, 15024, 15891,  1693,  7370,  1695,
    1456, 12145, -1929, -1929,   707,   -55,   -24,    -2,   146,   149,
    9619,   203, -1929,  1697, 15053, -1929, -1929, -1929,  1521, -1929,
   12145, 12145, -1929, -1929,  9870,  4325,  1706,  1461, 15486,   568,
   12292, -1929, -1929, -1929, -1929,    34, -1929,  1538, -1929, 15082,
    1464,  1467,  1468,  1707,  1712,  1713,  4444, -1929, -1929, -1929,
    1465,  1714,   712, -1929,  1715,  1721,   326, 12292, 12145, 12145,
    1471,  7370,   713, 12292, 17493, -1929, -1929, -1929, -1929, 17518,
   14168, -1929, -1929, 15111,  1146,  1209,  7370,   568, -1929, 12145,
    1538,    19, -1929, -1929,  9870,  9870, 12145,  1724,   715, -1929,
   -1929, 12145,  1367, -1929, 12145, -1929, -1929,   722,   723, -1929,
   -1929,  4567,  4591,  7370,   697,   710,  9870, -1929, -1929,   484,
    8309, -1929, -1929, -1929,  1725, -1929,  1477,  7370, -1929, 15140,
    1726,  9870,   251,   251,   251,   251,   251, -1929, -1929, 12145,
   15169, 15198,   724, -1929, -1929, -1929, -1929, -1929, -1929,  1483,
    1733,  1485, -1929,  1735,    11, -1929, -1929, -1929,  1554, -1929,
   -1929, -1929, -1929, -1929, 12145, 14201, 14234,  7370, -1929,  1738,
   12145,  1497, -1929, 12145,  1743,  1495,  1500, -1929, -1929,  5526,
   -1929,  1502,   729,   737, 15227, -1929,  1504, 14267,  1503, 14300,
   -1929,  1507, -1929, -1929,   738,  1511,   251,  7370,  1744,  1514,
     251,  1753,   739,  1523, -1929, 12145, -1929,  1757,  1624, 12935,
    1531, -1929,   740,   229,   239,   241,   243,   307,  4617, -1929,
   -1929,  1760,  1764, -1929, -1929, -1929,  1768, -1929,  1534, 12292,
   12145, 12145,   745, -1929, 12292, 14333, -1929, -1929, -1929,  1146,
    1538,  1536, -1929, -1929, -1929, 12145, 12145, -1929, 12145,  9870,
    1769,   251,   127, -1929, -1929,   251,   130, -1929,  1770, -1929,
   15256, -1929, 12145, -1929,   577, -1929,  1771,  9870,  9870,  9870,
    9870,  9619, -1929, -1929, -1929, 11195, -1929, 12145, 17543, 14366,
      51, 12145,  1526, -1929, -1929, 14399, 14432, 14465,   746, -1929,
     330, -1929,   334, -1929, -1929, -1929,  5011,   496, 13020, -1929,
     747,   779,   786,   788,   381,   789,  1537,   800, -1929, 12145,
   -1929,  7370, 15285, -1929, 12145, 12145, 12145, -1929,   251,   251,
   -1929, -1929, -1929,   577,  1772,  1773,  1779,  1780,  9870,  1781,
    1783,  1787,  1558, 17568,   802,  1788, 15314, 15486, 14498,   387,
     397,   515, -1929, -1929, -1929, -1929,   810, -1929, -1929, -1929,
   13547, -1929,  1563, -1929,  1790, -1929, 12145, 12145, 12145, -1929,
    1810,   815, -1929,  1565,  7370, -1929, 15343, 15372, 15401, -1929,
    1817, 13547, 13547,   818, -1929,  1818,  1819, -1929, -1929,   828,
   -1929,  1820, -1929, -1929,  1821, 13547, -1929, -1929, -1929
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1929, -1929, -1929, -1929,   441, -1929, -1929, -1929, -1929,  -318,
   -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929,  -737,  -126,  4496,  3054,  -412, -1929,  1358, -1929,
   -1929, -1929, -1929, -1929, -1929, -1928, -1929,   385,   201,  -120,
   -1929,   -83, -1929,   142,   423, -1929,  1836, -1929,   731,   -50,
   -1929, -1929,    22,  -637,  -302, -1929, -1929, -1929, -1929, -1929,
   -1929, -1929,   770,  1838, -1929, -1929, -1929, -1929, -1251, -1255,
    1839, -1753,  1840, -1929, -1929, -1929,  1232, -1929,  -141, -1929,
   -1929, -1929, -1929,  2475, -1929, -1929, -1450,   293,  1842, -1929,
       2, -1929, -1929,   -63, -1929, -1719,   801,  -175,  3170,  3081,
    -308,    73, -1929,  1561,   -69, -1929, -1929,    96,   270, -1711,
    -144,  1066, -1929,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -577
static const yytype_int16 yytable[] =
{
     143,   960,   961,  1509,  1678,   326,   328,  1884,   331,   165,
     628,  1511,   312,   468,  1062,   373,  1920,   447,  1921,   662,
    1068,   503,   167,   165,   346,   124,  2045,   166,   644,   510,
     417,   165,   165,   751,   419,  1362,  1504,   762,  1756,   412,
     555,   416,   151,  1506,   744,  1913,   351,   667,   352,  1489,
    1645,   291,   165,  1297,   578,   144,   429,  2180,   744,   145,
    1400,   296,   179,   296,   744,   183,   779,   754,   377,   755,
     636,   637,   317,     4,   452,  1190,   745,   746,  1398,  1344,
     350,   745,   746,  1836,   297,     5,  1077,  1496,   600,   291,
     745,   746,  1401,  1402,   376,   427,   745,   746,   318,   428,
    1646,   477,  1837,   476,   600,   413,   636,   637,   147,  1799,
    1957,   790,  1193,   347,   319,   320,   720,  1194,   723,   636,
     637,  1083,  1968,   613,   614,   615,   735,   955,  1606,   148,
     647,  1636,   728,  2161,   648,   638,  2163,   636,   637,   149,
     453,   745,   746,   353,   150,   463,   463,   463,   441,   442,
     747,   748,   636,   637,   470,   747,   748,  1466,   962,   636,
     637,   146,   636,   637,   747,   748,   455,   658,   659,   660,
     747,   748,   482,   966,  1061,   153,   636,   637,  1066,   794,
    1492,  2152,  1344,  1510,   674,   795,   636,   637,   463,   200,
     154,   927,   201,   291,   797,   202,   291,  1881,   551,   552,
     795,   291,   291,   463,   636,   637,  1505,  2001,   203,  1363,
    1364,  1365,  1366,  1507,   777,   747,   748,   636,   637,   348,
     639,    98,   778,    99,   100,   101,   102,   103,   155,  1847,
     117,   107,   108,   783,   110,  1344,   117,  1757,  2002,   636,
     637,   784,   749,   750,   117,   117,   785,   356,  1570,  1571,
     357,   156,   117,   117,   786,  1777,  1509,   291,   631,   632,
    2003,   788,   157,   358,  2064,  1025,   640,   645,   374,   789,
     663,   291,   664,   117,   291,   576,   145,   349,   441,   442,
     575,   763,   418,   764,  1351,  -569,   420,   765,   158,  1367,
     291,   291,   556,   152,   291,   291,   291,   291,   437,   438,
     439,   440,   754,   430,   755,  1298,   579,   431,  2181,   291,
     780,   180,   781,   291,   184,   376,   782,   378,  2102,  1043,
    1345,  1348,   441,   442,   168,   951,   169,   953,   954,   441,
     442,  1347,   601,  1322,   602,  1170,  1323,   291,   603,   291,
     291,   291,     7,     8,   967,   441,   442,   168,   601,   169,
     602,  1084,  1085,  1074,   603,   791,   291,   781,  1084,  1085,
     159,   792,   986,   291,   160,   739,   636,   637,   636,   637,
    1091,   636,   637,   441,   442,  1180,   729,   580,   730,   168,
    1102,   169,   731,   789,   887,   161,  1005,   636,   637,   162,
     636,   637,  2176,   437,   438,   439,   440,   437,   438,   439,
    1067,   437,   438,   439,   440,   877,   441,   442,  2004,   332,
     306,  2005,  1387,   307,   308,   309,  1392,   441,   442,   342,
     833,   343,   463,   291,   833,  1041,   310,   291,   291,   163,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   291,   636,   637,    43,    44,    45,    46,
     766,   164,    48,  1393,   437,   438,   439,   440,   176,   768,
      55,   833,  2204,    58,   769,  2006,   770,   771,   832,   772,
     636,   637,   833,   802,   437,   438,   439,   440,   441,   442,
     636,   637,   636,   637,   636,   637,  1202,    79,   454,   311,
     897,  2137,   322,   323,   833,   538,   893,   539,   441,   442,
    1251,  2138,   291,  2139,   324,  2140,   333,  1798,   325,  1766,
     334,  -573,    94,    95,    96,  2243,   335,   336,  1252,   337,
     338,   168,  2058,   169,  1748,  1749,   291,  1253,  1254,  1255,
    1197,   636,   637,  1256,  1257,   291,   867,   931,   177,   339,
     463,   833,   463,   291,   463,   463,   470,   646,   636,   637,
     932,   883,  1013,   178,   833,   291,   291,   291,   463,   463,
     291,   167,   754,   167,   755,   291,   892,   181,   894,  2141,
     789,   636,   637,   958,   959,   636,   637,   754,   632,   755,
    2033,  1901,   322,   323,   168,  1300,   169,   964,  2034,   182,
    1196,   291,  2188,  1197,   324,   185,  2189,   924,   330,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,  1508,   186,   291,
     291,   599,   636,   637,  1251,  1063,   187,  1877,   636,   637,
      67,    68,    69,    70,   195,  1521,    73,  1251,   636,   637,
    1028,   298,  1252,  2198,   299,    82,   300,  1350,    85,  2227,
    1240,  1253,  1254,  1255,   188,  1252,  1251,  1256,  1257,  2228,
     455,   455,   636,   637,  1253,  1254,  1255,   291,   291,   291,
    1256,  1257,   291,   189,  1252,   592,   593,   726,   595,   596,
     597,   598,   190,  1253,  1254,  1255,   599,   196,   191,  1256,
    1257,   470,   463,   470,   463,   463,   463,   463,   463,   463,
     192,   463,   463,   463,   463,  1027,   193,   463,   463,   463,
     167,  1033,   194,   977,   291,  1032,   301,   833,  1251,   302,
     313,  1079,   303,   314,   304,  1042,   306,   597,   598,   307,
     686,   309,   145,   599,   123,    46,  1252,   197,   291,  1116,
     198,  1723,   310,   199,  1698,  1253,  1254,  1255,   754,   293,
     755,  1256,  1257,   291,  2191,   754,  1320,   755,   756,  1071,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,  2229,   206,   291,  1088,   599,   441,   442,
     292,   291,  1453,   291,  1454,  -571,   470,  1100,   171,   205,
     294,   172,   305,  1105,   173,   463,   174,  1464,  1045,   295,
     315,  1214,   833,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,   754,   754,   755,   755,   599,  1490,   321,   291,   833,
     291,  1902,  1051,   329,   316,  1778,  1052,   726,   595,   596,
     597,   598,   340,  2065,  2066,  1785,   599,   441,   442,  2067,
    1377,  1683,  1330,  1684,  -572,   289,  2069,  2070,   441,   442,
    1200,  1212,  2067,  1213,   833,   291,   341,   441,   442,  1235,
    1329,  1230,  1330,   833,   449,   291,   344,   345,  1236,   449,
     449,   449,   833,  2167,   354,  1542,  1543,  1281,   449,  1282,
    1283,   833,  1243,   833,   833,   361,  1285,  1326,  1357,  1249,
     833,   833,   833,  1260,  1439,  1446,   355,  1463,   833,   833,
    1553,   833,  1509,   291,   580,  1471,  1557,  1214,   360,   833,
    1488,   362,   449,  1604,   833,   291,  1658,   833,   363,  1691,
     833,  1346,  1349,   833,   291,  1572,  1692,   449,   369,  1782,
     833,   381,  2211,  1783,   382,   291,  1805,  1807,  1214,  1893,
     833,   833,   426,   833,  1940,   383,  1509,  1958,  1941,  1984,
    1985,  1959,  1592,   833,   833,  2000,   165,   384,   458,  1941,
    2030,  2039,   370,  2056,   789,  2040,  1608,  1941,   550,   371,
    2060,  2061,  2091,  1614,   833,   833,   833,  2112,  1765,   372,
    1766,   833,  1354,   559,   560,  2113,  2120,  2128,  2136,   833,
    1941,   833,   833,  2150,  2187,  2194,   511,  1941,   833,   833,
     379,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     754,   380,   755,   928,   394,   395,   396,   397,  1862,   414,
    1863,   432,   398,   399,   400,   401,   425,  2195,   433,   459,
     402,   833,   403,  1576,  2196,   145,  2197,  2199,   833,   291,
     833,   833,   476,   509,  1412,  -204,   404,  1353,  2201,   405,
    2222,   289,  2040,   301,  1941,   291,   302,   474,  2230,   303,
     478,   304,   833,  2240,  1873,  1874,  2251,  2241,   291,   479,
    1941,  -205,    46,   463,  1465,  1467,  2254,   480,   481,   486,
    2255,   490,   504,   546,   549,  -206,   558,   561,   612,   435,
     557,   564,   565,   566,   577,   609,   610,   617,   428,   619,
     625,   649,   618,   621,   622,   291,   291,   626,   291,   291,
     291,   650,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   627,   629,   291,   630,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   831,
     595,   596,   597,   598,   651,   652,   449,   665,   599,   668,
     754,   653,   755,   654,   655,   661,   740,   669,   681,   406,
     407,   408,   670,   666,   291,   463,   463,   671,   672,   673,
     409,   676,   675,   677,   410,   678,   411,   117,   774,   682,
     688,   689,   697,   698,   699,   710,   711,   713,   291,   715,
     714,   716,   718,   717,   721,   719,   738,   722,   741,   753,
     758,   760,   441,   442,   291,   291,   291,   761,   144,  -570,
     799,  1593,   767,   824,   829,   803,   835,   808,   836,   837,
     868,   736,   737,   878,   879,   880,   599,   900,   898,   901,
     936,   937,   940,   945,   949,   950,   981,   752,   952,  1465,
    1467,   979,   982,   984,   993,   999,  1003,  1035,  1769,  1006,
    1044,  1037,  1771,  1050,  1054,  1055,  1059,  1781,  1060,  1064,
     291,  1075,  1076,  1092,   449,  1081,   449,  1094,   449,   449,
     449,  1097,  1104,  1106,  1109,  1117,   291,   291,   291,  1110,
    1118,  1119,   449,   449,   455,  1121,  1122,   291,  1123,  1125,
    1126,  1127,   463,  1128,  1129,  1130,   463,  1131,  1132,  1133,
    1134,  1137,  1141,  1168,  1169,   463,  1195,   463,  1177,  1178,
     463,  1186,  1179,  1189,  1201,  1205,  1204,  1217,  1225,  1619,
    1209,  1624,  1218,  1219,  1227,   291,  1238,  1246,  1247,  1272,
    1273,  1250,  1275,  1292,  1289,  1290,  1291,   874,   376,  1303,
    1304,  1305,  2073,  1308,  1316,  1318,  1319,  1325,  1328,   612,
    1332,   888,  1333,  1923,  1331,  1337,  1334,  1338,  1339,  1343,
    1356,  1358,  1359,   463,  1374,   774,  1380,  1381,   291,  1382,
     291,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,   291,   774,  1383,
    1388,   599,  1395,  1391,  1415,  1396,  1419,  1431,  1449,  -207,
    1457,  1475,   291,  1476,  1477,  1480,   291,  1481,  1483,  1482,
    1484,  1485,  1486,  1487,  1497,   449,   449,   449,   449,   449,
     449,   449,   449,   449,  1498,   449,   449,   449,   449,  1790,
    1790,   449,   449,   449,  1501,  1502,  1779,  1722,  1512,  1513,
    1525,   774,  1514,  1515,   774,  1503,  1516,  1517,  1518,  1519,
    1520,  1526,  1524,  1527,  1528,  1529,   774,  1530,  1531,  1532,
    1537,  1549,   291,   291,   291,  1929,  1548,  1555,  1569,  1574,
     291,   291,   291,  1556,  1558,  1560,  1564,  1764,  1566,  1575,
    1578,  1579,  1580,  1585,  1587,  1588,  1591,  1605,   291,  1611,
    1589,  1078,  1612,  1080,  1603,  1630,  1628,  1635,  1609,   291,
    1637,  1641,  1642,  1629,  1643,  1648,  1649,   291,  1650,  1651,
     449,   291,  1652,  1653,  1654,  1655,  1656,  1657,  1669,   449,
    1680,  1690,  1696,  1676,  1705,  1697,  1706,  1703,  1704,  1707,
    1714,  1719,  1056,   384,  1711,  1720,  1735,  1712,  1819,  1741,
    1742,  1747,  1713,  1743,  1773,  1800,  1726,  1776,  1802,  1808,
    1852,  1727,  1809,  1812,  1728,  1729,  1730,  1731,  1826,  1734,
    1737,  1775,   376,  1761,  1830,  1540,  1751,  1754,  1323,  1792,
     470,   470,  1768,  1772,  1797,  1811,   291,   385,   386,   387,
     388,   389,   390,   391,   392,   393,  1815,  1820,  1804,  1827,
     394,   395,   396,   397,   463,  1828,  1829,  1831,   398,   399,
     400,   401,  1832,  1833,   291,  1834,   402,  1839,   403,   291,
    1838,  1840,  1841,  1846,  1855,  1853,  1857,  1854,  1882,  1197,
    1860,  1883,   404,  1861,  1878,   405,  1892,  1897,  1868,  1915,
    1916,  1917,  1932,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,  1927,  1928,
    1933,  1945,   599,   789,  1885,  1886,  1887,  1888,  1889,  1891,
    1946,  1947,  1948,  1952,  -576,  -574,  1956,  1961,  1962,  1963,
    1906,  1964,   774,  1965,   774,   774,  1966,  1911,  1914,  1967,
    1973,  1979,  1980,  1988,  1983,   291,  2079,  1989,   774,  1995,
     291,   291,  1997,  2007,   451,  1991,  1992,  2009,  1925,   461,
     464,   465,  2014,  1998,  2024,  2015,  2096,   774,  2025,  2026,
    2029,  2031,  2021,   291,  2028,  2022,  2023,  2032,  2037,   291,
    2055,  2076,  2081,   455,   455,  2077,   774,  2092,  1224,  2093,
     291,  2095,  2094,  2097,  2103,   406,   407,   408,   463,  2106,
    2124,   463,   498,  2107,  -575,  2111,   409,  2117,  2108,  2127,
     410,  2115,   411,  2131,  2119,  2132,  2143,   512,  2121,   291,
    2144,  2125,   774,  1353,  2146,  2159,  2164,  2169,  2212,  2213,
     376,  2129,   291,   470,  2183,  2214,  2215,  2217,  2135,  2218,
    2154,  2147,  2145,  2219,  2223,  2200,  2235,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,  2220,  2239,   449,   470,   599,
    2234,  1541,  2242,  2247,  2252,  2253,  2256,  2257,  1607,  2177,
    1825,   798,  2018,  2168,  1672,  2046,  1856,  1639,   291,   122,
    1373,   133,   134,   135,  2071,   141,  1763,   939,  2019,  1924,
     291,   291,  1912,  1340,  1791,  1099,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1360,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,  2050,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,     0,   449,
     449,     0,     0,     0,     0,     0,   759,     0,     0,  1413,
    1414,     0,  1416,  1417,  1418,     0,  1420,  1421,  1422,  1423,
    1424,  1425,  1426,  1427,  1428,  1429,     0,     0,   291,  2083,
    2084,  2085,  2086,  2087,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   291,     0,     0,     0,     0,  2051,     0,
       0,   291,   291,     0,     0,     0,     0,     0,     0,     0,
       0,   774,     0,     0,     0,     0,     0,     0,  1443,     0,
     291,     0,     0,   291,     0,     0,   732,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,   291,     0,
       0,     0,  1458,  2122,     0,     0,     0,  2126,     0,     0,
       0,   455,     0,     0,     0,     0,     0,     0,  1472,     0,
       0,   376,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,   449,     0,     0,     0,
     449,  2153,     0,     0,     0,     0,     0,     0,     0,   449,
       0,   449,     0,     0,   449,     0,     0,     0,  2160,     0,
       0,     0,  2162,  1559,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1522,     0,     0,     0,  2174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1534,  1535,  1536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   871,     0,   873,   449,   875,   876,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,   889,   890,     0,  2209,  2210,     0,     0,     0,
       0,     0,     0,     0,   291,   291,   291,   291,   291,  1565,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,  1623,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1640,   463,     0,     0,
    1644,     0,     0,     0,     0,     0,     0,   776,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,   463,   463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,     0,  1012,     0,  1014,  1015,
    1016,  1017,  1018,  1019,     0,  1021,  1022,  1023,  1024,     0,
       0,  1029,  1030,  1031,     0,     0,  1693,  1694,  1695,     0,
       0,     0,     0,     0,  1700,  1701,  1702,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1717,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1725,   449,   449,     0,   165,   384,     0,
       0,  1733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   449,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,   385,   386,   387,   388,   389,   390,   391,   392,
     393,  1430,     0,     0,     0,   394,   395,   396,   397,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
    1796,   402,     0,   403,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   404,     0,     0,
     405,     0,     0,     0,   301,     0,     0,   302,  1818,     0,
     303,     0,   304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     435,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,  1523,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,   449,     0,     0,   449,     0,     0,     0,     0,
       0,     0,  1563,     0,     0,     0,     0,     0,     0,  1859,
     774,     0,   774,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   449,     0,     0,
     406,   407,   408,     0,     0,     0,     0,  1796,     0,     0,
       0,   409,     0,     0,     0,   410,     0,   411,   117,     0,
       0,     0,     0,     0,  1898,     0,     0,     0,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   754,     0,   755,
    1786,     0,     0,  1922,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1931,     0,     0,     0,
       0,   423,     0,  1581,     0,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,   450,     0,
       0,     0,   460,     0,     0,     0,     0,   466,     0,     0,
       0,     0,     0,     0,     0,   471,     0,     0,     0,     0,
       0,     0,  1796,     0,     0,     0,     0,  1386,     0,     0,
       0,   483,   484,   485,     0,   487,   488,   489,     0,   491,
     492,   493,   494,   495,   496,   497,     0,   499,   500,   501,
     502,     0,     0,     0,   506,     0,     0,     0,     0,  1996,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,  1444,
    1445,     0,  2038,     0,     0,     0,     0,     0,   567,   569,
     571,   572,   506,     0,     0,     0,     0,  2047,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   606,   506,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1796,     0,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,     0,     0,  2078,   634,
     635,     0,     0,     0,     0,   635,     0,     0,     0,     0,
     774,     0,     0,     0,     0,   506,   657,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,  1796,   599,
     679,   506,     0,     0,     0,   683,   684,   685,     0,   687,
       0,     0,     0,   690,   691,   692,     0,     0,   693,     0,
       0,     0,     0,     0,     0,     0,  1545,     0,  2123,     0,
    1547,     0,     0,     0,     0,     0,   774,     0,     0,  1551,
       0,  1552,     0,     0,  1554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   725,     0,   774,
       0,   506,   734,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   742,   743,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   775,     0,     0,     0,  1594,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,     0,   804,   805,   806,   807,     0,     0,     0,
       0,   812,     0,     0,     0,   816,     0,     0,     0,     0,
       0,     0,   449,   449,     0,     0,     0,     0,     0,   830,
     569,     0,  1796,     0,   834,     0,   449,     0,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,   851,   852,   853,   854,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   864,     0,   869,   870,     0,   872,
       0,     0,     0,     0,     0,     0,     0,     0,   881,     0,
       0,   885,   886,     0,     0,  1796,     0,     0,   864,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,   912,   913,   914,   915,   917,
     919,   920,   921,   922,   923,     0,   925,   926,     0,     0,
       0,     0,     0,     0,   933,   934,   935,     0,     0,     0,
       0,     0,   941,   942,   943,   944,  1715,   506,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   567,   725,   963,     0,
       0,     0,   968,   969,   970,   971,   972,   973,   974,   975,
     976,     0,     0,     0,     0,     0,   983,     0,   985,     0,
       0,   987,     0,     0,     0,   506,   506,   506,   992,     0,
     506,   995,   996,   997,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1810,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1020,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,  1478,     0,     0,     0,     0,  1039,
       0,  1040,     0,     0,   925,   926,     0,     0,     0,     0,
       0,     0,     0,  1053,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,  1069,     0,     0,     0,     0,  1072,  1073,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,  1089,  1090,     0,     0,   506,
       0,   506,  1096,     0,     0,     0,  1089,     0,  1103,     0,
       0,     0,     0,     0,  1108,     0,     0,     0,  1111,     0,
     508,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,  1135,   599,   917,     0,  1138,     0,
       0,     0,  1907,     0,     0,  1909,     0,     0,     0,     0,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,  1770,     0,
       0,     0,   599,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,  1182,  1183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,     0,     0,     0,   607,   608,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,  1223,     0,     0,     0,  1229,     0,     0,     0,     0,
       0,   656,     0,   506,     0,     0,     0,     0,     0,     0,
       0,  1244,  1245,     0,     0,     0,     0,  1248,     0,     0,
       0,     0,     0,     0,   570,     0,     0,   507,     0,     0,
       0,     0,     0,     0,  1274,     0,     0,  1276,     0,     0,
       0,     0,     0,   507,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1293,
       0,  1295,  1296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1314,     0,   757,     0,     0,     0,     0,   733,     0,     0,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1336,     0,     0,     0,     0,     0,     0,
    1342,     0,     0,     0,     0,     0,   507,  1355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1378,  1379,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,  1407,  1408,  1409,
    1410,     0,     0,     0,     0,     0,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   882,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1433,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1434,  1435,
    1436,  1437,  1438,     0,     0,     0,     0,  1440,  1441,   895,
    1442,     0,     0,     0,     0,     0,     0,     0,     0,   929,
       0,     0,     0,     0,  1451,  1452,     0,     0,     0,     0,
       0,     0,  1455,  1456,     0,   570,     0,     0,     0,  1460,
       0,  1461,  1462,     0,     0,     0,     0,  1468,  1469,     0,
       0,     0,     0,   506,   506,     0,     0,     0,     0,   855,
       0,     0,     0,   946,   947,     0,     0,     0,   865,   866,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1500,     0,     0,
       0,     0,     0,   891,     0,     0,     0,     0,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   989,   990,   991,     0,     0,   994,     0,     0,     0,
       0,     0,     0,  1533,   918,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0,  2232,     0,  1546,     0,     0,     0,     0,     0,     0,
       0,     0,   507,   507,     0,     0,     0,     0,  1034,     0,
       0,     0,  2248,  2250,  1468,  1469,     0,     0,     0,  1562,
       0,     0,     0,     0,     0,     0,  2258,     0,     0,     0,
    1568,     0,     0,  1573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1065,     0,     0,
     507,   507,   507,     0,     0,   507,     0,     0,     0,     0,
       0,     0,  1595,     0,     0,  1598,   506,  1601,   506,  1087,
       0,     0,     0,     0,     0,  1093,  1610,  1095,     0,  1613,
       0,  1610,  1616,  1618,     0,  1774,  1626,  1627,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,     0,
       0,     0,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,     0,  1154,  1155,  1156,  1157,     0,  1159,
    1160,  1161,  1162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1174,   507,  1176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1185,     0,     0,
       0,     0,     0,     0,  1191,  1192,     0,     0,   507,  1171,
       0,     0,     0,  1203,   507,     0,   507,  1699,     0,  1181,
       0,     0,     0,     0,     0,     0,     0,  1708,  1709,  1710,
       0,     0,     0,     0,     0,     0,  1716,     0,  1718,     0,
       0,     0,     0,     0,     0,  1721,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1208,     0,   506,
       0,   918,     0,  1139,  1738,  1739,     0,     0,     0,  1216,
       0,     0,     0,  1744,  1745,  1746,     0,     0,     0,     0,
       0,     0,     0,  1755,     0,     0,     0,     0,     0,  1237,
       0,     0,     0,  1767,     0,     0,     0,     0,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,     0,
       0,     0,     0,     0,  1784,     0,     0,     0,     0,     0,
       0,     0,  1793,  1794,     0,  1299,  1301,  1302,     0,     0,
       0,  1306,  1307,     0,     0,  1310,  1311,  1312,  1313,     0,
    1315,     0,     0,     0,  1780,  1321,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1823,   507,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,   507,     0,
       0,   599,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,  1842,  1843,  1844,   599,     0,   754,     0,   755,     0,
       0,     0,  1845,     0,  1752,     0,     0,  1848,  1849,  1850,
       0,     0,  1385,     0,     0,  1406,  1895,     0,     0,     0,
    1411,  1858,     0,     0,     0,     0,     0,     0,   506,   506,
    1866,     0,  1867,     0,     0,     0,     0,     0,  1875,  1876,
       0,  1896,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,  1894,     0,     0,     0,     0,     0,  1432,     0,
       0,     0,     0,     0,  1905,     0,     0,  1908,     0,     0,
       0,  1910,     0,     0,     0,     0,     0,     0,     0,     0,
    1849,  1850,     0,  1919,     0,     0,     0,     0,     0,     0,
       0,   507,     0,  1926,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1937,     0,  1470,
       0,     0,  1943,  1944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1949,     0,     0,  1950,
    1949,     0,  1953,     0,     0,     0,     0,     0,     0,  1473,
    1474,     0,  1987,     0,     0,     0,     0,   507,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,   506,   506,
     599,  2013,     0,     0,     0,  1981,  1982,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1990,     0,     0,
       0,     0,     0,     0,     0,     0,  1999,     0,     0,     0,
       0,     0,     0,     0,     0,   569,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2010,  2011,     0,     0,   506,
       0,  1544,     0,     0,     0,     0,     0,     0,   507,   507,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,  1582,   599,  2035,  2036,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,  2049,     0,     0,   599,     0,   506,
     506,  2054,     0,     0,     0,     0,  2057,     0,     0,  2059,
    2027,     0,     0,  1620,     0,     0,     0,     0,     0,     0,
       0,   506,  1600,     0,  1602,     0,     0,     0,     0,     0,
     507,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,  2088,     0,     0,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,     0,     0,     0,     0,  1670,  1671,
       0,     0,     0,     0,  1673,     0,  1675,     0,     0,  2099,
    1679,     0,     0,  1681,     0,  2104,     0,     0,  2105,     0,
       0,     0,   170,     0,   175,  1689,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,   580,     0,     0,     0,   599,     0,
    2130,   507,     0,   507,     0,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,  2062,     0,  2148,  2149,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2155,  2156,     0,  2157,   506,     0,     0,  2063,  1750,     0,
    1753,     0,     0,     0,  1760,  1736,  1762,  2166,     0,     0,
       0,     0,   506,   506,   506,   506,   506,     0,     0,     0,
       0,     0,  1943,  2142,     0,     0,  2182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1787,     0,   448,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2203,     0,     0,     0,     0,  2206,
    2207,  2208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,   507,     0,   599,     0,     0,     0,
       0,  2236,  2237,  2238,     0,     0,     0,     0,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   540,   541,   542,   543,   544,   545,  1851,
     547,   548,     0,     0,     0,     0,     0,     0,     0,   553,
     554,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   562,   563,     0,     0,     0,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,  1864,  1865,     0,     0,   599,     0,
       0,     0,  1824,     0,     0,     0,     0,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,  1934,   599,     0,  1935,     0,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,   507,   507,     0,     0,     0,     0,     0,
       0,   694,   695,   696,     0,     0,     0,   700,   701,   702,
     703,   704,   705,   706,     0,   707,  1969,  1970,     0,  1972,
     708,   709,   507,     0,   712,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   724,     0,     0,
       0,     0,     0,     0,   207,   165,     0,     0,     0,     0,
       0,   208,   209,   210,  1977,  1978,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   421,   229,   230,   231,   232,   233,   234,
     235,   236,  2016,  2017,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
     243,   244,   245,   165,   384,  2012,     0,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   251,   252,     0,     0,     0,     0,     0,
       0,  2048,     0,   253,    25,     0,   254,  2190,     0,     0,
       0,     0,     0,   507,   507,     0,     0,     0,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,   395,   396,   397,  2052,  2053,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   402,     0,   403,
     570,     0,     0,     0,     0,     0,     0,  2072,     0,     0,
       0,     0,   899,   404,   507,     0,   405,     0,     0,     0,
     301,     0,  2082,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   265,     0,     0,   507,   507,   267,   268,   269,     0,
     270,   271,   272,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   507,     0,     0,     0,
       0,     0,   273,   422,     0,     0,     0,     0,     0,   275,
       0,   507,     0,     0,   365,     0,     0,     0,   623,     0,
       0,   278,     0,     0,     0,     0,   406,   407,   408,     0,
       0,     0,     0,     0,     0,     0,     0,   409,     0,     0,
    2158,   410,     0,   411,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2170,  2171,
    2172,  2173,  2175,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1786,     0,     0,     0,
       0,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,  2225,     0,   599,  1960,   580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,   507,   507,
     507,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   207,     6,   384,     0,     0,     0,
       0,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   507,     0,
    1621,   386,   387,   388,   389,   390,   391,   392,   393,   242,
     243,   244,   245,   394,   395,   396,   397,   246,   247,     0,
    1198,   398,   399,   400,   401,     0,     0,   248,   249,   402,
       0,   403,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   253,    25,   404,   254,     0,   405,     0,
       0,     0,   255,  1215,     0,   256,     0,     0,   257,     0,
     258,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,    56,    57,     0,   261,     0,   262,     0,
       0,   263,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,     0,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     831,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   406,   407,
     408,   265,   266,  2110,     0,     0,   267,   268,   269,   409,
     270,   271,   272,   410,     0,   411,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   274,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   365,     0,     0,     0,  1622,     0,
       0,   278,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     6,   384,     0,     0,     0,     0,   208,   209,   210,
       0,  1399,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   242,   243,   244,   245,   394,
     395,   396,   397,   246,   247,     0,     0,   398,   399,   400,
     401,     0,     0,   248,   249,   402,     0,   403,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   253,
      25,   404,   254,     0,   405,     0,     0,     0,   255,     0,
       0,   256,     0,     0,   257,     0,   258,     0,  1459,     0,
       0,     0,     0,    42,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,    56,
      57,     0,   261,     0,   262,     0,     0,   263,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,     0,     0,     0,     0,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   406,   407,   408,   265,   266,     0,
       0,     0,   267,   268,   269,   409,   270,   271,   272,   410,
       0,   411,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   274,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     365,     0,     0,     0,   277,     0,     0,   278,     0,     0,
       0,     0,     0,     0,  1583,  1584,     0,   207,   165,   384,
       0,   434,     0,     0,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   421,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   242,   243,   244,   245,   394,   395,   396,   397,
     246,     7,     8,     0,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   403,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   253,    25,   404,   254,
    1677,   405,     0,     0,     0,   301,     0,     0,   302,     0,
    1685,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   768,    55,
       0,     0,    58,   769,     0,   770,   771,     0,   772,     0,
       0,     0,     0,   436,     0,     0,     0,     0,   580,     0,
     264,   406,   407,   408,   265,     0,    79,     0,     0,   267,
     268,   269,   409,   270,   271,   272,   410,     0,   411,   117,
     437,   438,   439,   440,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,     0,   273,   422,     0,     0,     0,
       0,     0,   275,     0,   441,   442,     0,   443,     0,   444,
       0,     0,     0,   445,   278,     0,     0,  1821,   207,     6,
     364,     0,     0,     0,     0,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     0,     0,     0,   988,     0,     0,     0,
       0,     0,     0,   242,   243,   244,   245,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,    25,     0,
     254,     0,     0,     0,     0,     0,   255,     0,     0,   256,
       0,     0,   257,     0,   258,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,    56,    57,     0,
     261,     0,   262,     0,     0,   263,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   831,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,  1007,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   265,   266,     0,     0,     0,
     267,   268,   269,     0,   270,   271,   272,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   274,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,   207,
       6,     0,   366,     0,   680,   278,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   243,   244,   245,     0,     0,
       0,     0,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,    25,
       0,   254,     0,     0,     0,     0,     0,   255,     0,     0,
     256,     0,     0,   257,     0,   258,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,    56,    57,
       0,   261,     0,   262,     0,     0,   263,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
    1206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,   265,   266,     0,     0,
       0,   267,   268,   269,     0,   270,   271,   272,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   505,     0,
       0,     0,     0,     0,   275,     0,     0,     0,     0,   365,
     207,     6,  1724,     0,   573,     0,   278,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   243,   244,   245,     0,
       0,     0,     0,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,     0,     0,     0,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   253,
      25,     0,   254,     0,     0,     0,     0,     0,   255,     0,
       0,   256,     0,     0,   257,     0,   258,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,    56,
      57,     0,   261,     0,   262,     0,     0,   263,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,  1207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,   265,   266,     0,
       0,     0,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   274,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     365,   207,     6,     0,   277,     0,     0,   278,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   243,   244,   245,
       0,     0,     0,     0,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
     253,    25,     0,   254,     0,     0,     0,     0,     0,   255,
       0,     0,   256,     0,     0,   257,     0,   258,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,     0,
      56,    57,     0,   261,     0,   262,     0,     0,   263,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,  1539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   265,   266,
       0,     0,     0,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
    1890,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   643,   207,     6,     0,   325,   573,     0,   278,   208,
     209,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,     0,     0,     0,     0,     0,
     255,     0,     0,   256,     0,     0,   257,     0,   258,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,    56,    57,     0,   261,     0,   262,     0,     0,   263,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,   265,
     266,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   274,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,   276,   207,     6,     0,   277,     0,     0,   278,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   242,   243,
     244,   245,     0,     0,     0,     0,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,     0,     0,
       0,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    25,     0,   254,     0,     0,     0,     0,
       0,   255,     0,     0,   256,     0,     0,   257,     0,   258,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,    56,    57,     0,   261,     0,   262,     0,     0,
     263,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,   998,
       0,     0,     0,     0,     0,     0,     0,   956,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
     265,   266,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   274,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,   207,     6,     0,   277,     0,     0,
     278,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
     243,   244,   245,     0,     0,     0,     0,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,     0,
       0,     0,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   253,    25,     0,   254,     0,     0,     0,
       0,     0,   255,     0,     0,   256,     0,     0,   257,     0,
     258,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,     0,    56,    57,     0,   261,     0,   262,     0,
       0,   263,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1816,     0,     0,     0,  1817,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   265,   266,     0,     0,     0,   267,   268,   269,     0,
     270,   271,   272,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   505,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   365,   207,     6,     0,   568,     0,
       0,   278,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,   243,   244,   245,     0,     0,     0,     0,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
       0,     0,     0,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,    25,     0,   254,     0,     0,
       0,     0,     0,   255,     0,     0,   256,     0,     0,   257,
       0,   258,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,    56,    57,     0,   261,     0,   262,
       0,     0,   263,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1871,     0,     0,     0,  1872,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,   266,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   505,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   365,   207,     6,     0,     0,
     573,     0,   278,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,   244,   245,     0,     0,     0,     0,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     0,     0,     0,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   253,    25,     0,   254,     0,
       0,     0,     0,     0,   255,     0,     0,   256,     0,     0,
     257,     0,   258,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,    56,    57,     0,   261,     0,
     262,     0,     0,   263,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1899,     0,     0,     0,
    1900,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,   266,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   611,   207,     6,     0,
     277,     0,     0,   278,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,   244,   245,     0,     0,     0,     0,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,     0,     0,     0,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   253,    25,     0,   254,
       0,     0,     0,     0,     0,   255,     0,     0,   256,     0,
       0,   257,     0,   258,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,    56,    57,     0,   261,
       0,   262,     0,     0,   263,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  2074,     0,     0,
       0,  2075,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   265,   266,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   274,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,   620,   207,     6,
       0,   277,     0,     0,   278,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,   243,   244,   245,     0,     0,     0,
       0,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,     0,     0,     0,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,    25,     0,
     254,     0,     0,     0,     0,     0,   255,     0,     0,   256,
       0,     0,   257,     0,   258,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,    56,    57,     0,
     261,     0,   262,     0,     0,   263,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   787,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   265,   266,     0,     0,     0,
     267,   268,   269,     0,   270,   271,   272,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   505,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,   207,
       6,     0,   916,     0,  1384,   278,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   243,   244,   245,     0,     0,
       0,     0,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,    25,
       0,   254,     0,     0,     0,     0,     0,   255,     0,     0,
     256,     0,     0,   257,     0,   258,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,    56,    57,
       0,   261,     0,   262,     0,     0,   263,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   793,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,   265,   266,     0,     0,
       0,   267,   268,   269,     0,   270,   271,   272,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   505,     0,
       0,     0,     0,     0,   275,   207,     6,     0,     0,   365,
    1599,     0,   208,   209,   210,     0,   278,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,   243,   244,   245,     0,     0,     0,     0,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
       0,     0,     0,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,    25,     0,   254,     0,     0,
       0,     0,     0,   255,     0,     0,   256,     0,     0,   257,
       0,   258,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,    56,    57,     0,   261,     0,   262,
       0,     0,   263,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   956,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,   266,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   505,     0,     0,     0,     0,     0,
     275,   207,     6,     0,     0,   365,     0,     0,   208,   209,
     210,     0,   278,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   243,   244,   245,
       0,     0,     0,     0,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,     0,     0,     0,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
     253,    25,     0,   254,     0,     0,     0,     0,     0,   255,
       0,     0,   256,     0,     0,   257,     0,   258,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   260,     0,
      56,    57,     0,   261,     0,   262,     0,     0,   263,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   957,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   265,   266,
       0,     0,     0,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     274,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   365,   207,     6,     0,  1732,     0,     0,   278,   208,
     209,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,     0,     0,     0,     0,     0,
     255,     0,     0,   256,     0,     0,   257,     0,   258,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,    56,    57,     0,   261,     0,   262,     0,     0,   263,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1004,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,   265,
     266,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,  1890,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,   643,   207,     6,     0,   325,     0,     0,   278,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   242,   243,
     244,   245,     0,     0,     0,     0,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,     0,     0,
       0,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    25,     0,   254,     0,     0,     0,     0,
       0,   255,     0,     0,   256,     0,     0,   257,     0,   258,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,     0,    56,    57,     0,   261,     0,   262,     0,     0,
     263,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
     265,   266,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   505,     0,     0,     0,     0,     0,   275,   207,
     165,   384,     0,   365,     0,     0,   208,   209,   210,     0,
     278,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   421,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   242,   243,   244,   245,   394,   395,
     396,   397,   246,     0,     0,     0,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   403,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,    25,
     404,   254,     0,   405,   207,   165,   384,     0,     0,     0,
       0,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   421,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   242,
     243,   244,   245,   394,   395,   396,   397,   246,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,   403,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   253,    25,   404,   254,     0,   405,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   406,   407,   408,   265,     0,     0,     0,
       0,   267,   268,   269,   409,   270,   271,   272,   410,     0,
     411,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   422,     0,
       0,     0,     0,     0,   275,     0,     0,     0,     0,   365,
       0,     0,     0,  1617,     0,     0,   278,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,     0,     0,     0,     0,     0,     0,   264,   406,   407,
     408,   265,     0,     0,     0,     0,   267,   268,   269,   409,
     270,   271,   272,   410,     0,   411,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   422,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   365,   207,   165,   384,  1904,     0,
       0,   278,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   421,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,  1621,   386,   387,   388,   389,   390,   391,   392,   393,
     242,   243,   244,   245,   394,   395,   396,   397,   246,     0,
       0,     0,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,   403,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,    25,   404,   254,     0,   405,
     207,   165,   384,     0,     0,     0,     0,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   421,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   242,   243,   244,   245,   394,
     395,   396,   397,   246,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   403,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   253,
      25,   404,   254,     0,   405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,   406,
     407,   408,   265,     0,     0,     0,     0,   267,   268,   269,
     409,   270,   271,   272,   410,     0,   411,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   422,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   365,     0,     0,     0,  1786,
       0,     0,   278,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,   264,   406,   407,   408,   265,     0,     0,
       0,     0,   267,   268,   269,   409,   270,   271,   272,   410,
       0,   411,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   422,
       0,     0,     0,     0,     0,   275,   207,   165,     0,     0,
     365,     0,     0,   208,   209,   210,     0,   278,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   421,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,   244,   245,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,     0,     0,
       0,     0,   207,   165,     0,   253,    25,   884,   254,   208,
     209,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   421,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,   264,
       0,     0,     0,   265,     0,     0,     0,  1115,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,   642,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   643,     0,     0,     0,
     325,     0,     0,   278,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,   264,  1153,     0,     0,   265,
       0,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   422,     0,     0,     0,     0,     0,   275,   207,   165,
       0,     0,   365,     0,     0,   208,   209,   210,     0,   278,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   421,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,   243,   244,   245,     0,     0,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,    25,     0,
     254,   207,   165,     0,  1335,     0,     0,     0,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     421,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   243,   244,   245,
       0,     0,     0,     0,   246,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,   250,
     251,   252,    43,    44,    45,    46,     0,     0,    48,     0,
     253,    25,     0,   254,     0,   768,    55,     0,     0,    58,
     769,     0,   770,   771,     0,   772,     0,     0,     0,  1047,
       0,   264,     0,     0,     0,   265,     0,     0,     0,     0,
     267,   268,   269,    79,   270,   271,   272,  1048,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   422,    94,    95,
      96,     0,     0,   275,     0,     0,     0,     0,   365,  1101,
       0,     0,     0,     0,     0,   278,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1163,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   265,     0,
       0,     0,     0,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     422,     0,     0,     0,     0,     0,   275,   207,   165,     0,
    1499,   365,     0,     0,   208,   209,   210,     0,   278,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   421,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,   244,   245,     0,     0,     0,     0,
     246,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   253,    25,     0,   254,
     207,   165,     0,  1561,     0,     0,     0,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   421,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   243,   244,   245,     0,
       0,     0,     0,   246,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   250,   251,
     252,    43,    44,    45,    46,     0,     0,    48,     0,   253,
      25,     0,   254,     0,   768,    55,     0,     0,    58,   769,
       0,   770,   771,     0,   772,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   265,     0,     0,     0,     0,   267,
     268,   269,    79,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   422,    94,    95,    96,
       0,     0,   275,     0,     0,     0,     0,   365,     0,     0,
       0,     0,     0,     0,   278,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1164,     0,     0,
       0,     0,     0,   264,     0,     0,     0,   265,     0,     0,
       0,     0,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   422,
       0,     0,     0,     0,     0,   275,   207,   165,     0,     0,
     365,     0,     0,   208,   209,   210,     0,   278,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   421,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,   244,   245,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,     0,     0,
       0,     0,   207,   165,     0,   253,    25,     0,   254,   208,
     209,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   421,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,   264,
       0,     0,     0,   265,     0,     0,     0,  1165,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   422,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   365,  1615,     0,     0,
       0,     0,     0,   278,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,   264,  1166,     0,     0,   265,
       0,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   422,     0,     0,     0,     0,     0,   275,   207,   165,
       0,     0,   365,  1951,     0,   208,   209,   210,     0,   278,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   421,   229,   230,
     231,   232,   233,   234,   235,   236,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,   243,   244,   245,     0,     0,     0,
       0,   246,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,    25,     0,
     254,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,   768,    55,     0,     0,    58,   769,     0,
     770,   771,     0,   772,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,   264,     0,     0,   599,   265,    94,    95,    96,   727,
     267,   268,   269,     0,   270,   271,   272,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   422,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,     0,
       0,     0,     0,     0,     0,   278,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,  1036,     0,     0,     0,   768,    55,     0,     0,    58,
     769,     0,   770,   771,     0,   772,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    79,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,    94,    95,
      96,     0,     0,   768,    55,     0,     0,    58,   769,     0,
     770,   771,     0,   772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,    79,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,    94,    95,    96,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,  1038,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   768,    55,
       0,     0,    58,   769,     0,   770,   771,     0,   772,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,    79,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,  1239,     0,    43,    44,    45,    46,     0,     0,    48,
       0,    94,    95,    96,     0,     0,   768,    55,     0,     0,
      58,   769,     0,   770,   771,     0,   772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,  1241,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,   768,    55,     0,     0,    58,   769,     0,   770,   771,
       0,   772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,    79,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,  1242,     0,    43,    44,    45,    46,
       0,     0,    48,     0,    94,    95,    96,     0,     0,   768,
      55,     0,     0,    58,   769,     0,   770,   771,     0,   772,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,  1261,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   768,    55,     0,     0,    58,   769,
       0,   770,   771,     0,   772,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,    79,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,  1279,     0,    43,
      44,    45,    46,     0,     0,    48,     0,    94,    95,    96,
       0,     0,   768,    55,     0,     0,    58,   769,     0,   770,
     771,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,  1294,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,   768,    55,     0,
       0,    58,   769,     0,   770,   771,     0,   772,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    79,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
    1327,     0,    43,    44,    45,    46,     0,     0,    48,     0,
      94,    95,    96,     0,     0,   768,    55,     0,     0,    58,
     769,     0,   770,   771,     0,   772,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,  1491,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     768,    55,     0,     0,    58,   769,     0,   770,   771,     0,
     772,     0,     0,    -4,     1,     0,     0,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,    -4,    -4,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,     0,     0,     0,    -4,
      -4,    -4,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
      -4,    -4,    -4,     0,   599,     0,     0,    -4,    -4,     0,
       0,     0,    -4,     0,  1172,     0,     0,    -4,    -4,    -4,
      -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,  2192,    -4,
      -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,     0,
      -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,     0,
       0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     6,
       0,     0,     0,     0,     0,    -4,    -4,    -4,     7,     8,
       0,     0,     0,     0,     0,     0,    -4,     0,    -4,     0,
       0,     0,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     9,    10,    11,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1173,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     0,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,    18,
      19,    20,    21,    22,     0,    23,    24,     0,    25,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,    42,    43,    44,    45,    46,    47,     0,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,     0,    64,    65,    66,
       0,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    89,    90,    91,     0,
       0,     0,    92,     0,     0,     0,     0,    93,    94,    95,
      96,   165,   384,    97,     0,    98,     0,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   116,     0,
     117,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
     395,   396,   397,   165,   384,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,     0,   405,     0,     0,     0,   301,   415,
     384,   302,     0,     0,   303,     0,   304,     0,   385,   386,
     387,   388,   389,   390,   391,   392,   393,    46,     0,     0,
       0,   394,   395,   396,   397,     0,     0,     0,     0,   398,
     399,   400,   401,     0,   435,     0,     0,   402,     0,   403,
       0,     0,     0,     0,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   404,     0,     0,   405,   394,   395,   396,
     397,     0,     0,     0,     0,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   403,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   404,
       0,     0,   405,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,   407,   408,     0,     0,     0,
       0,     0,     0,     0,     0,   409,     0,     0,     0,   410,
       0,   411,   117,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   406,   407,   408,     0,
       0,     0,     0,     0,     0,     0,     0,   409,     0,     0,
       0,   410,     0,   411,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   406,   407,   408,     0,     0,     0,     0,     0,
       0,     0,     0,   409,     0,     0,     0,   410,     0,   411,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1288,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1309,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1394,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1397,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1493,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1494,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1538,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1666,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1667,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1668,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1682,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1814,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1938,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1939,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1971,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1974,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2043,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2100,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2101,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2116,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2118,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2151,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2179,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2184,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2185,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2186,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2226,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,   828,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  1082,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  1140,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1187,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1188,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1232,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  1264,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  1284,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  1341,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    1361,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  1447,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  1448,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  1495,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1567,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1869,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1880,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  1918,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  1993,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  2008,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    2020,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  2044,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  2080,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  2089,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  2090,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  2114,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  2165,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  2205,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  2224,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  2244,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    2245,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  2246,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,   948,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,  1986,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
     754,     0,   755,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,  1010,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,  1058,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,  1211,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
    1278,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,  1280,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,  1286,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,  1287,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,  1376,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,  1390,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,  1596,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,  1688,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,  1740,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,  1930,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
    1976,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,  1994,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   809,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   810,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   811,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   813,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   814,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   815,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   817,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   818,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   819,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   820,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   821,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   822,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   823,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   825,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   826,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   827,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   896,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   930,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,   978,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,   998,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1000,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1001,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1002,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1008,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1009,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1046,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1057,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1120,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1124,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1136,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1210,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1220,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1221,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1222,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1231,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1233,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1234,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1263,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1265,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1266,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1267,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1268,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1269,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1270,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1271,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1277,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1375,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1389,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1597,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1631,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1632,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1633,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1634,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1674,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1687,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1801,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1803,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1806,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1813,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1870,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1879,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  1903,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  1975,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  2041,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  2042,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,  2178,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,  2221
};

static const yytype_int16 yycheck[] =
{
       3,   638,   639,  1258,  1454,    68,    69,  1726,    71,     4,
     318,  1262,    62,   157,   751,     4,  1769,   143,  1771,     4,
     757,   196,    25,     4,     4,     3,  1954,    25,   330,   204,
       5,     4,     4,   445,     5,     4,     6,     9,     4,   108,
       5,   110,     6,     6,     4,  1756,     4,   349,     6,     4,
     141,    54,     4,     7,     5,   257,     6,     6,     4,   261,
       4,   107,     4,   107,     4,     4,     9,   254,     4,   256,
     241,   242,   162,     6,   143,   262,    36,    37,     7,     7,
      83,    36,    37,   101,   130,     0,   130,   258,     9,    92,
      36,    37,    36,    37,    97,   253,    36,    37,   188,   257,
     191,   170,   120,     9,     9,   108,   241,   242,   107,     4,
    1821,     9,   254,    93,   204,   205,   418,   259,   420,   241,
     242,     6,  1841,   298,   299,   300,   428,   262,     6,   253,
     253,     6,     9,     6,   257,   257,     6,   241,   242,   253,
     143,    36,    37,   101,   253,   148,   149,   150,   250,   251,
     110,   111,   241,   242,   157,   110,   111,   259,   262,   241,
     242,    14,   241,   242,   110,   111,   144,   342,   343,   344,
     110,   111,   175,   262,     7,     6,   241,   242,     7,   256,
     262,  2109,     7,   262,   359,   262,   241,   242,   191,   101,
       6,   603,   104,   196,   256,   107,   199,   262,   248,   249,
     262,   204,   205,   206,   241,   242,   176,   262,   120,   178,
     179,   180,   181,   176,   254,   110,   111,   241,   242,   199,
     257,   190,   262,   192,   193,   194,   195,   196,     6,  1679,
     225,   200,   201,   254,   203,     7,   225,   203,   262,   241,
     242,   262,   188,   189,   225,   225,   254,   104,   188,   189,
     107,     6,   225,   225,   262,     7,  1511,   260,   321,   322,
     262,   254,   253,   120,  1983,   260,   329,   330,   257,   262,
     255,   274,   257,   225,   277,   278,   261,   257,   250,   251,
     278,   253,   257,   255,   257,   257,   257,   259,     6,   258,
     293,   294,   257,   257,   297,   298,   299,   300,   226,   227,
     228,   229,   254,   253,   256,   259,   257,   257,   257,   312,
     253,   253,   255,   316,   253,   318,   259,   253,  2037,   731,
    1057,  1058,   250,   251,   253,   627,   255,   629,   630,   250,
     251,   259,   253,   259,   255,   256,   262,   340,   259,   342,
     343,   344,    13,    14,   646,   250,   251,   253,   253,   255,
     255,   236,   237,   765,   259,   253,   359,   255,   236,   237,
       6,   259,   664,   366,   257,   434,   241,   242,   241,   242,
     782,   241,   242,   250,   251,   254,   253,     8,   255,   253,
     792,   255,   259,   262,   559,     6,   688,   241,   242,     6,
     241,   242,  2145,   226,   227,   228,   229,   226,   227,   228,
     229,   226,   227,   228,   229,   549,   250,   251,   262,     4,
     104,   262,   254,   107,   108,   109,   254,   250,   251,   107,
     262,   109,   425,   426,   262,   727,   120,   430,   431,   255,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   446,   241,   242,   117,   118,   119,   120,
     453,   255,   123,   254,   226,   227,   228,   229,   253,   130,
     131,   262,  2181,   134,   135,   262,   137,   138,   258,   140,
     241,   242,   262,   476,   226,   227,   228,   229,   250,   251,
     241,   242,   241,   242,   241,   242,   898,   158,     4,   183,
     258,   262,   241,   242,   262,   253,   565,   255,   250,   251,
     141,   262,   505,   262,   253,   262,   101,   253,   257,   255,
     105,   257,   183,   184,   185,  2234,   111,   112,   159,   114,
     115,   253,  1972,   255,     6,     7,   529,   168,   169,   170,
     262,   241,   242,   174,   175,   538,   539,   258,   253,   134,
     543,   262,   545,   546,   547,   548,   549,   257,   241,   242,
     258,   554,   696,   253,   262,   558,   559,   560,   561,   562,
     563,   564,   254,   566,   256,   568,   564,   253,   566,   262,
     262,   241,   242,   636,   637,   241,   242,   254,   641,   256,
     254,     8,   241,   242,   253,   262,   255,   258,   262,   253,
     259,   594,   262,   262,   253,   253,   262,   600,   257,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   258,   253,   622,
     623,   252,   241,   242,   141,   751,   253,   258,   241,   242,
     146,   147,   148,   149,   257,  1272,   152,   141,   241,   242,
     709,   104,   159,   262,   107,   161,   109,  1059,   164,   262,
     952,   168,   169,   170,   253,   159,   141,   174,   175,   262,
     638,   639,   241,   242,   168,   169,   170,   670,   671,   672,
     174,   175,   675,   253,   159,   241,   242,   243,   244,   245,
     246,   247,   253,   168,   169,   170,   252,   122,   253,   174,
     175,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     253,   704,   705,   706,   707,   708,   253,   710,   711,   712,
     713,   714,   253,   258,   717,   713,   101,   262,   141,   104,
     104,   771,   107,   107,   109,   728,   104,   246,   247,   107,
     259,   109,   261,   252,     3,   120,   159,   107,   741,   808,
       6,   258,   120,   257,  1481,   168,   169,   170,   254,   257,
     256,   174,   175,   756,   258,   254,   262,   256,   257,   762,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   258,   253,   778,   779,   252,   250,   251,
     253,   784,  1194,   786,  1196,   257,   789,   790,   101,   109,
     257,   104,    61,   796,   107,   798,   109,  1209,   258,   107,
     253,   927,   262,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   254,   254,   256,   256,   252,  1238,   257,   831,   262,
     833,   258,   258,   257,   104,  1572,   262,   243,   244,   245,
     246,   247,   257,   146,   147,  1582,   252,   250,   251,   152,
     253,   253,   255,   255,   257,    54,   146,   147,   250,   251,
     258,   253,   152,   255,   262,   868,   253,   250,   251,   258,
     253,   940,   255,   262,   143,   878,   107,   104,   258,   148,
     149,   150,   262,  2134,   104,  1297,  1298,   258,   157,   258,
     258,   262,   955,   262,   262,     4,   258,   258,   258,   962,
     262,   262,   262,   966,   258,   258,   107,   258,   262,   262,
    1322,   262,  2167,   916,     8,   258,  1328,  1043,   107,   262,
     258,     4,   191,   258,   262,   928,   258,   262,     4,   258,
     262,  1057,  1058,   262,   937,  1347,   258,   206,     4,   258,
     262,     6,  2193,   262,     6,   948,   258,   258,  1074,   258,
     262,   262,   257,   262,   258,   255,  2211,   258,   262,   258,
     258,   262,  1374,   262,   262,   258,     4,     5,   257,   262,
     258,   258,   253,   258,   262,   262,  1388,   262,   247,   253,
     258,   258,   258,  1395,   262,   262,   262,   258,   253,   253,
     255,   262,  1061,   262,   263,   258,   258,   258,   258,   262,
     262,   262,   262,   258,   258,   258,   205,   262,   262,   262,
     253,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     254,   253,   256,   257,    62,    63,    64,    65,     4,   253,
       6,     6,    70,    71,    72,    73,   255,   258,   261,     6,
      78,   262,    80,  1351,   258,   261,   258,   258,   262,  1052,
     262,   262,     9,   257,  1117,   191,    94,  1060,   258,    97,
     258,   260,   262,   101,   262,  1068,   104,   253,   258,   107,
     253,   109,   262,   258,  1711,  1712,   258,   262,  1081,   253,
     262,   191,   120,  1086,  1210,  1211,   258,   253,   253,   253,
     262,   253,   253,   253,   253,   191,   130,   253,   297,   137,
     257,   253,   253,   253,   191,   253,   253,   253,   257,   253,
       4,   253,   257,   312,   257,  1118,  1119,   316,  1121,  1122,
    1123,   253,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,   257,   257,  1137,   257,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   253,   253,   425,     6,   252,     6,
     254,   253,   256,   253,   253,   253,   435,     6,     6,   207,
     208,   209,   257,   255,  1177,  1178,  1179,   257,   257,   257,
     218,   255,   257,   255,   222,   255,   224,   225,   457,     6,
     257,   191,   253,   253,   253,   253,   253,   253,  1201,     6,
     255,     6,     6,   257,     6,     8,   257,     8,     7,     6,
     257,   257,   250,   251,  1217,  1218,  1219,     6,   257,   257,
      96,   259,   258,   254,     7,   262,     6,   262,     6,   254,
     257,   430,   431,   257,   257,   257,   252,    67,   259,     8,
       7,     7,   253,     6,   254,     6,     6,   446,   257,  1375,
    1376,     7,     7,     6,     6,   258,   188,   258,  1560,   257,
     256,   258,  1564,   254,     6,   257,   259,  1575,     7,     6,
    1273,   255,   253,     6,   543,   257,   545,     6,   547,   548,
     549,     6,     6,     6,   254,     7,  1289,  1290,  1291,   255,
       7,     7,   561,   562,  1272,     7,     7,  1300,     7,     7,
       7,     7,  1305,     7,     7,     7,  1309,     7,     7,     7,
       7,   257,     6,   254,   256,  1318,   254,  1320,   262,   262,
    1323,   258,   262,   262,     7,   258,   257,     7,     4,  1398,
     259,  1400,   257,   257,     6,  1338,   259,   258,   258,   257,
       7,   141,     6,   259,     7,     7,     7,   546,  1351,   254,
     254,   262,  1989,   262,     9,   262,   254,   256,   259,   558,
     191,   560,     7,  1775,   261,   258,   162,   257,     6,     6,
       6,    49,    49,  1376,   259,   644,   253,   257,  1381,   253,
    1383,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,  1400,   667,   257,
     259,   252,   259,   253,     7,   253,     7,     7,   262,   191,
     254,     7,  1415,     7,     7,     6,  1419,   254,     7,   262,
       7,     7,     7,     7,   119,   694,   695,   696,   697,   698,
     699,   700,   701,   702,     4,   704,   705,   706,   707,  1583,
    1584,   710,   711,   712,   257,     6,  1572,  1510,     7,     6,
       6,   720,     7,     7,   723,   253,     7,     7,     7,     7,
       7,     6,   257,     6,   107,     7,   735,     7,     6,     6,
       4,   262,  1475,  1476,  1477,  1783,   260,   254,     6,     6,
    1483,  1484,  1485,   262,   257,   257,   257,  1556,   258,     7,
       6,   255,     6,     6,   253,   253,     6,     6,  1501,     6,
     257,   770,     6,   772,   258,     6,   256,     6,   259,  1512,
     134,     6,     6,   262,     6,     6,     6,  1520,     6,     6,
     789,  1524,     6,     6,     6,     6,     6,     5,   254,   798,
       6,     6,     4,   254,     7,     6,     6,   257,   257,     7,
     255,     6,   741,     5,   257,     6,     6,   257,  1617,     6,
       6,     6,   257,   187,     6,     6,   257,     7,     6,     6,
    1686,   257,     6,     4,   257,   257,   257,   257,     6,   258,
     257,   259,  1575,   254,  1637,     8,   262,   262,   262,   253,
    1583,  1584,   257,   262,   257,   253,  1589,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   253,     7,   258,     6,
      62,    63,    64,    65,  1607,     6,     6,     6,    70,    71,
      72,    73,     6,     6,  1617,   141,    78,     6,    80,  1622,
     105,     5,   257,   254,     6,   257,     6,   257,     6,   262,
     141,     6,    94,   141,   262,    97,     6,     6,  1707,   262,
     254,   262,  1786,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     6,     6,
       6,     6,   252,   262,  1727,  1728,  1729,  1730,  1731,  1732,
       6,     6,     6,     6,   257,   257,   257,     7,   145,     6,
    1749,   257,   951,   257,   953,   954,   257,  1756,  1757,     5,
     254,     6,     6,     6,   257,  1698,  1998,   257,   967,     6,
    1703,  1704,     7,     6,   143,   258,   258,   186,  1777,   148,
     149,   150,     6,   257,     7,   254,  2024,   986,     6,     6,
       6,     6,   258,  1726,   259,   258,   258,     6,   257,  1732,
       6,     6,     6,  1711,  1712,   258,  1005,   254,   937,     6,
    1743,     6,   257,   189,     6,   207,   208,   209,  1751,     6,
       6,  1754,   191,   258,   257,   253,   218,   254,   258,     6,
     222,   257,   224,     6,   257,   141,     6,   206,   257,  1772,
       6,   257,  1041,  1776,     6,     6,     6,     6,     6,     6,
    1783,   258,  1785,  1786,   258,     6,     6,     6,   257,     6,
     254,   257,  2094,     6,     6,   258,     6,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   257,     6,  1086,  1821,   252,
     257,   254,   257,     6,     6,     6,     6,     6,  1387,  2147,
    1629,   473,  1915,  2135,  1449,  1955,  1694,  1414,  1841,     3,
    1070,     3,     3,     3,  1985,     3,  1553,   615,  1917,  1776,
    1853,  1854,  1756,  1052,  1584,   789,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1068,
      -1,    -1,    -1,    -1,    -1,  1878,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1890,    -1,    -1,
      -1,  1960,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,
    1179,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  1118,
    1119,    -1,  1121,  1122,  1123,    -1,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1134,    -1,    -1,  1941,  2002,
    2003,  2004,  2005,  2006,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1956,    -1,    -1,    -1,    -1,  1961,    -1,
      -1,  1964,  1965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1240,    -1,    -1,    -1,    -1,    -1,    -1,  1177,    -1,
    1983,    -1,    -1,  1986,    -1,    -1,   425,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,  2001,    -1,
      -1,    -1,  1201,  2066,    -1,    -1,    -1,  2070,    -1,    -1,
      -1,  1989,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,
      -1,  2024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2037,    -1,  1305,    -1,    -1,    -1,
    1309,  2110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1318,
      -1,  1320,    -1,    -1,  1323,    -1,    -1,    -1,  2121,    -1,
      -1,    -1,  2125,  1332,  2067,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,  2141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1289,  1290,  1291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,    -1,   545,  1376,   547,   548,
      -1,    -1,    -1,    -1,    -1,    -1,  2119,    -1,    -1,    -1,
      -1,    -1,   561,   562,    -1,  2188,  2189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2137,  2138,  2139,  2140,  2141,  1338,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2198,    -1,    -1,    -1,    -1,
      -1,  1400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1415,  2220,    -1,    -1,
    1419,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,  2234,    -1,    -1,    -1,    -1,    -1,    -1,  2241,  2242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2255,    -1,    -1,    -1,   695,    -1,   697,   698,
     699,   700,   701,   702,    -1,   704,   705,   706,   707,    -1,
      -1,   710,   711,   712,    -1,    -1,  1475,  1476,  1477,    -1,
      -1,    -1,    -1,    -1,  1483,  1484,  1485,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1512,  1583,  1584,    -1,     4,     5,    -1,
      -1,  1520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     789,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   798,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     6,    -1,    -1,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,
    1589,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,   104,  1617,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     6,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1751,    -1,    -1,  1754,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1698,
    1769,    -1,  1771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,  1726,    -1,    -1,
      -1,   218,    -1,    -1,    -1,   222,    -1,   224,   225,    -1,
      -1,    -1,    -1,    -1,  1743,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,   256,
     257,    -1,    -1,  1772,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,
      -1,   116,    -1,     6,    -1,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,   143,    -1,
      -1,    -1,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,    -1,    -1,
      -1,    -1,  1841,    -1,    -1,    -1,    -1,  1086,    -1,    -1,
      -1,   176,   177,   178,    -1,   180,   181,   182,    -1,   184,
     185,   186,   187,   188,   189,   190,    -1,   192,   193,   194,
     195,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,  1878,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,  1178,
    1179,    -1,  1941,    -1,    -1,    -1,    -1,    -1,   273,   274,
     275,   276,   277,    -1,    -1,    -1,    -1,  1956,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   292,   293,   294,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1983,    -1,    -1,    -1,    -1,   314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1997,   324,
     325,    -1,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,
    2079,    -1,    -1,    -1,    -1,   340,   341,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,  2037,   252,
     365,   366,    -1,    -1,    -1,   370,   371,   372,    -1,   374,
      -1,    -1,    -1,   378,   379,   380,    -1,    -1,   383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1305,    -1,  2067,    -1,
    1309,    -1,    -1,    -1,    -1,    -1,  2145,    -1,    -1,  1318,
      -1,  1320,    -1,    -1,  1323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,  2168,
      -1,   426,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,  1376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2220,    -1,   478,   479,   480,   481,    -1,    -1,    -1,
      -1,   486,    -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,
      -1,    -1,  2241,  2242,    -1,    -1,    -1,    -1,    -1,   504,
     505,    -1,  2181,    -1,   509,    -1,  2255,    -1,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,    -1,   541,   542,    -1,   544,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,
      -1,   556,   557,    -1,    -1,  2234,    -1,    -1,   563,    -1,
      -1,    -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,    -1,   601,   602,    -1,    -1,
      -1,    -1,    -1,    -1,   609,   610,   611,    -1,    -1,    -1,
      -1,    -1,   617,   618,   619,   620,     6,   622,   623,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   641,   642,   643,    -1,
      -1,    -1,   647,   648,   649,   650,   651,   652,   653,   654,
     655,    -1,    -1,    -1,    -1,    -1,   661,    -1,   663,    -1,
      -1,   666,    -1,    -1,    -1,   670,   671,   672,   673,    -1,
     675,   676,   677,   678,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   703,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   717,    -1,   141,    -1,    -1,    -1,    -1,   724,
      -1,   726,    -1,    -1,   729,   730,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   738,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   756,    -1,   758,    -1,    -1,    -1,    -1,   763,   764,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   778,    -1,   780,   781,    -1,    -1,   784,
      -1,   786,   787,    -1,    -1,    -1,   791,    -1,   793,    -1,
      -1,    -1,    -1,    -1,   799,    -1,    -1,    -1,   803,    -1,
     199,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,   829,   252,   831,    -1,   833,    -1,
      -1,    -1,  1751,    -1,    -1,  1754,    -1,    -1,    -1,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     6,    -1,
      -1,    -1,   252,   868,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   878,   879,   880,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,   293,   294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   916,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   928,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   936,    -1,    -1,    -1,   940,    -1,    -1,    -1,    -1,
      -1,   340,    -1,   948,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   956,   957,    -1,    -1,    -1,    -1,   962,    -1,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,   277,    -1,    -1,
      -1,    -1,    -1,    -1,   979,    -1,    -1,   982,    -1,    -1,
      -1,    -1,    -1,   293,   294,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1004,
      -1,  1006,  1007,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1025,    -1,   448,    -1,    -1,    -1,    -1,   426,    -1,    -1,
     340,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1048,    -1,    -1,    -1,    -1,    -1,    -1,
    1055,    -1,    -1,    -1,    -1,    -1,   366,  1062,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1075,  1076,    -1,    -1,    -1,    -1,  1081,    -1,    -1,    -1,
      -1,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,  1112,  1113,  1114,
    1115,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,    -1,
      -1,    -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,  1164,
    1165,  1166,  1167,    -1,    -1,    -1,    -1,  1172,  1173,   568,
    1175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,
      -1,    -1,    -1,    -1,  1189,  1190,    -1,    -1,    -1,    -1,
      -1,    -1,  1197,  1198,    -1,   505,    -1,    -1,    -1,  1204,
      -1,  1206,  1207,    -1,    -1,    -1,    -1,  1212,  1213,    -1,
      -1,    -1,    -1,  1218,  1219,    -1,    -1,    -1,    -1,   529,
      -1,    -1,    -1,   622,   623,    -1,    -1,    -1,   538,   539,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,    -1,    -1,
      -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,   568,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   670,   671,   672,    -1,    -1,   675,    -1,    -1,    -1,
      -1,    -1,    -1,  1288,   594,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1300,    -1,    -1,    -1,    -1,
      -1,  2220,    -1,  1308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,   623,    -1,    -1,    -1,    -1,   717,    -1,
      -1,    -1,  2241,  2242,  1329,  1330,    -1,    -1,    -1,  1334,
      -1,    -1,    -1,    -1,    -1,    -1,  2255,    -1,    -1,    -1,
    1345,    -1,    -1,  1348,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   756,    -1,    -1,
     670,   671,   672,    -1,    -1,   675,    -1,    -1,    -1,    -1,
      -1,    -1,  1377,    -1,    -1,  1380,  1381,  1382,  1383,   778,
      -1,    -1,    -1,    -1,    -1,   784,  1391,   786,    -1,  1394,
      -1,  1396,  1397,  1398,    -1,     6,  1401,  1402,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   717,    -1,    -1,
      -1,    -1,   838,   839,   840,   841,   842,   843,   844,   845,
     846,   847,   848,    -1,   850,   851,   852,   853,    -1,   855,
     856,   857,   858,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   871,   756,   873,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   883,    -1,    -1,
      -1,    -1,    -1,    -1,   890,   891,    -1,    -1,   778,   868,
      -1,    -1,    -1,   899,   784,    -1,   786,  1482,    -1,   878,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1492,  1493,  1494,
      -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,  1503,    -1,
      -1,    -1,    -1,    -1,    -1,  1510,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   916,    -1,  1524,
      -1,   831,    -1,   833,  1529,  1530,    -1,    -1,    -1,   928,
      -1,    -1,    -1,  1538,  1539,  1540,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1548,    -1,    -1,    -1,    -1,    -1,   948,
      -1,    -1,    -1,  1558,    -1,    -1,    -1,    -1,   868,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,    -1,
      -1,    -1,    -1,    -1,  1579,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1587,  1588,    -1,  1011,  1012,  1013,    -1,    -1,
      -1,  1017,  1018,    -1,    -1,  1021,  1022,  1023,  1024,    -1,
    1026,    -1,    -1,    -1,     6,  1031,   916,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1622,   928,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,   948,    -1,
      -1,   252,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,  1666,  1667,  1668,   252,    -1,   254,    -1,   256,    -1,
      -1,    -1,  1677,    -1,   262,    -1,    -1,  1682,  1683,  1684,
      -1,    -1,  1081,    -1,    -1,  1111,     6,    -1,    -1,    -1,
    1116,  1696,    -1,    -1,    -1,    -1,    -1,    -1,  1703,  1704,
    1705,    -1,  1707,    -1,    -1,    -1,    -1,    -1,  1713,  1714,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1732,    -1,    -1,
      -1,    -1,  1737,    -1,    -1,    -1,    -1,    -1,  1137,    -1,
      -1,    -1,    -1,    -1,  1749,    -1,    -1,  1752,    -1,    -1,
      -1,  1756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1765,  1766,    -1,  1768,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1081,    -1,  1778,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1792,    -1,  1215,
      -1,    -1,  1797,  1798,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1811,    -1,    -1,  1814,
    1815,    -1,  1817,    -1,    -1,    -1,    -1,    -1,    -1,  1218,
    1219,    -1,     6,    -1,    -1,    -1,    -1,  1137,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,  1853,  1854,
     252,     6,    -1,    -1,    -1,  1860,  1861,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1872,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1881,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1890,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1900,  1901,    -1,    -1,  1904,
      -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,  1218,  1219,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,  1357,   252,  1938,  1939,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,  1959,    -1,    -1,   252,    -1,  1964,
    1965,  1966,    -1,    -1,    -1,    -1,  1971,    -1,    -1,  1974,
       6,    -1,    -1,  1399,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1986,  1381,    -1,  1383,    -1,    -1,    -1,    -1,    -1,
    1300,    -1,    -1,    -1,    -1,    -1,  2001,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2009,    -1,    -1,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,    -1,    -1,    -1,    -1,  1444,  1445,
      -1,    -1,    -1,    -1,  1450,    -1,  1452,    -1,    -1,  2034,
    1456,    -1,    -1,  1459,    -1,  2040,    -1,    -1,  2043,    -1,
      -1,    -1,    26,    -1,    28,  1471,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     8,    -1,    -1,    -1,   252,    -1,
    2075,  1381,    -1,  1383,    -1,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     6,    -1,  2100,  2101,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2115,  2116,    -1,  2118,  2119,    -1,    -1,     6,  1544,    -1,
    1546,    -1,    -1,    -1,  1550,  1524,  1552,  2132,    -1,    -1,
      -1,    -1,  2137,  2138,  2139,  2140,  2141,    -1,    -1,    -1,
      -1,    -1,  2147,     6,    -1,    -1,  2151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1583,    -1,   143,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2179,    -1,    -1,    -1,    -1,  2184,
    2185,  2186,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2198,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,  1524,    -1,   252,    -1,    -1,    -1,
      -1,  2226,  2227,  2228,    -1,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,  1685,
     244,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,   266,    -1,    -1,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,  1703,  1704,    -1,    -1,   252,    -1,
      -1,    -1,  1622,    -1,    -1,    -1,    -1,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,  1788,   252,    -1,  1791,    -1,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,  1703,  1704,    -1,    -1,    -1,    -1,    -1,
      -1,   385,   386,   387,    -1,    -1,    -1,   391,   392,   393,
     394,   395,   396,   397,    -1,   399,  1842,  1843,    -1,  1845,
     404,   405,  1732,    -1,   408,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,
      -1,    10,    11,    12,  1853,  1854,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,  1908,  1909,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,     4,     5,  1904,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,  1957,    -1,    92,    93,    -1,    95,     6,    -1,    -1,
      -1,    -1,    -1,  1853,  1854,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,  1964,  1965,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,
    1890,    -1,    -1,    -1,    -1,    -1,    -1,  1986,    -1,    -1,
      -1,    -1,   576,    94,  1904,    -1,    97,    -1,    -1,    -1,
     101,    -1,  2001,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,    -1,    -1,  1964,  1965,   215,   216,   217,    -1,
     219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1986,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
      -1,  2001,    -1,    -1,   253,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,
    2119,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2137,  2138,
    2139,  2140,  2141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,  2207,    -1,   252,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2137,  2138,  2139,
    2140,  2141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,  2198,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
     894,    70,    71,    72,    73,    -1,    -1,    76,    77,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      -1,    -1,   101,   927,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,   132,   133,    -1,   135,    -1,   137,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,    -1,   152,   153,   154,   155,   156,   157,    -1,
      -1,    -1,   161,    -1,    -1,   164,    -1,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,   208,
     209,   210,   211,     7,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,  1105,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    76,    77,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,  1202,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     133,    -1,   135,    -1,   137,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,  1358,  1359,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    13,    14,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
    1454,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
    1464,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,     8,    -1,
     206,   207,   208,   209,   210,    -1,   158,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,   224,   225,
     226,   227,   228,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,   248,    -1,   250,   251,    -1,   253,    -1,   255,
      -1,    -1,    -1,   259,   260,    -1,    -1,  1621,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,    -1,
     135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,   152,   153,   154,
     155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,
     215,   216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,     3,
       4,    -1,   257,    -1,     8,   260,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,
      -1,   135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,
     164,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,   210,   211,    -1,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,
       3,     4,     5,    -1,   258,    -1,   260,    10,    11,    12,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     133,    -1,   135,    -1,   137,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,
      -1,   164,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,    -1,   210,   211,    -1,
      -1,    -1,   215,   216,   217,    -1,   219,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,     3,     4,    -1,   257,    -1,    -1,   260,    10,    11,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   133,    -1,   135,    -1,   137,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,
     152,   153,   154,   155,   156,   157,    -1,    -1,    -1,   161,
      -1,    -1,   164,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,   211,
      -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   253,     3,     4,    -1,   257,   258,    -1,   260,    10,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   133,    -1,   135,    -1,   137,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
      -1,   152,   153,   154,   155,   156,   157,    -1,    -1,    -1,
     161,    -1,    -1,   164,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,
     211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,     3,     4,    -1,   257,    -1,    -1,   260,
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
     130,    -1,   132,   133,    -1,   135,    -1,   137,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,    -1,   152,   153,   154,   155,   156,   157,    -1,    -1,
      -1,   161,    -1,    -1,   164,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,     3,     4,    -1,   257,    -1,    -1,
     260,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
      -1,   130,    -1,   132,   133,    -1,   135,    -1,   137,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,    -1,   152,   153,   154,   155,   156,   157,    -1,
      -1,    -1,   161,    -1,    -1,   164,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,
     219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   253,     3,     4,    -1,   257,    -1,
      -1,   260,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,   130,    -1,   132,   133,    -1,   135,    -1,   137,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,   152,   153,   154,   155,   156,   157,
      -1,    -1,    -1,   161,    -1,    -1,   164,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,   253,     3,     4,    -1,    -1,
     258,    -1,   260,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,   130,    -1,   132,   133,    -1,   135,    -1,
     137,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,    -1,   152,   153,   154,   155,   156,
     157,    -1,    -1,    -1,   161,    -1,    -1,   164,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
      -1,    -1,    -1,   210,   211,    -1,    -1,    -1,   215,   216,
     217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,   253,     3,     4,    -1,
     257,    -1,    -1,   260,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,   130,    -1,   132,   133,    -1,   135,
      -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,    -1,   152,   153,   154,   155,
     156,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,   253,     3,     4,
      -1,   257,    -1,    -1,   260,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,    -1,
     135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,   152,   153,   154,
     155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,
     215,   216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,     3,
       4,    -1,   257,    -1,     8,   260,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,
      -1,   135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,
     164,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,   210,   211,    -1,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,   248,     3,     4,    -1,    -1,   253,
       8,    -1,    10,    11,    12,    -1,   260,    15,    16,    17,
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
      -1,    -1,   130,    -1,   132,   133,    -1,   135,    -1,   137,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,    -1,   152,   153,   154,   155,   156,   157,
      -1,    -1,    -1,   161,    -1,    -1,   164,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,     3,     4,    -1,    -1,   253,    -1,    -1,    10,    11,
      12,    -1,   260,    15,    16,    17,    18,    19,    20,    21,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
     132,   133,    -1,   135,    -1,   137,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,
     152,   153,   154,   155,   156,   157,    -1,    -1,    -1,   161,
      -1,    -1,   164,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,   211,
      -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   253,     3,     4,    -1,   257,    -1,    -1,   260,    10,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      -1,   132,   133,    -1,   135,    -1,   137,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
      -1,   152,   153,   154,   155,   156,   157,    -1,    -1,    -1,
     161,    -1,    -1,   164,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,
     211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,     3,     4,    -1,   257,    -1,    -1,   260,
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
     130,    -1,   132,   133,    -1,   135,    -1,   137,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,    -1,   152,   153,   154,   155,   156,   157,    -1,    -1,
      -1,   161,    -1,    -1,   164,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,     3,
       4,     5,    -1,   253,    -1,    -1,    10,    11,    12,    -1,
     260,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,   257,    -1,    -1,   260,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   253,     3,     4,     5,   257,    -1,
      -1,   260,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,   224,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,
      -1,    -1,   260,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,    -1,
     253,    -1,    -1,    10,    11,    12,    -1,   260,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    92,    93,     8,    95,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   262,   215,   216,
     217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,    -1,    -1,   260,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   262,    -1,    -1,   210,
      -1,    -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,    -1,   253,    -1,    -1,    10,    11,    12,    -1,   260,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,     3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    81,
      82,    83,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      92,    93,    -1,    95,    -1,   130,   131,    -1,    -1,   134,
     135,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,   144,
      -1,   206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
     215,   216,   217,   158,   219,   220,   221,   162,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,   183,   184,
     185,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,   254,
      -1,    -1,    -1,    -1,    -1,   260,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,
       6,   253,    -1,    -1,    10,    11,    12,    -1,   260,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    81,    82,
      83,   117,   118,   119,   120,    -1,    -1,   123,    -1,    92,
      93,    -1,    95,    -1,   130,   131,    -1,    -1,   134,   135,
      -1,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,   215,
     216,   217,   158,   219,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,   242,   183,   184,   185,
      -1,    -1,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,   215,   216,   217,    -1,   219,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,    -1,
     253,    -1,    -1,    10,    11,    12,    -1,   260,    15,    16,
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
      -1,    92,    93,    -1,    95,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,   262,   215,   216,
     217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,   253,   254,    -1,    -1,
      -1,    -1,    -1,   260,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,   262,    -1,    -1,   210,
      -1,    -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,    -1,   253,   254,    -1,    10,    11,    12,    -1,   260,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,
      95,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,   135,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,   206,    -1,    -1,   252,   210,   183,   184,   185,   257,
     215,   216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,   260,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,   258,    -1,    -1,    -1,   130,   131,    -1,    -1,   134,
     135,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   158,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,   183,   184,
     185,    -1,    -1,   130,   131,    -1,    -1,   134,   135,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,   158,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,   183,   184,   185,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,   258,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
      -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,   158,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,   258,    -1,   117,   118,   119,   120,    -1,    -1,   123,
      -1,   183,   184,   185,    -1,    -1,   130,   131,    -1,    -1,
     134,   135,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   258,    -1,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,    -1,    -1,   134,   135,    -1,   137,   138,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   158,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,   258,    -1,   117,   118,   119,   120,
      -1,    -1,   123,    -1,   183,   184,   185,    -1,    -1,   130,
     131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,   258,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,    -1,    -1,   134,   135,
      -1,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,   158,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   258,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,   183,   184,   185,
      -1,    -1,   130,   131,    -1,    -1,   134,   135,    -1,   137,
     138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,   185,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   258,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
      -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,   158,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     258,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
     183,   184,   185,    -1,    -1,   130,   131,    -1,    -1,   134,
     135,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   258,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,
     140,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,    46,
      47,    48,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      67,    68,    69,    -1,   252,    -1,    -1,    74,    75,    -1,
      -1,    -1,    79,    -1,   262,    -1,    -1,    84,    85,    86,
      87,    88,    -1,    90,    91,    -1,    93,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   258,   116,
     117,   118,   119,   120,   121,    -1,   123,    -1,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    -1,    -1,   142,   143,   144,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   182,   183,   184,   185,    -1,
      -1,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,     4,
      -1,    -1,    -1,    -1,    -1,   212,   213,   214,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,   225,    -1,
      -1,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    46,    47,    48,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    -1,    90,    91,    -1,    93,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,   123,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,    -1,    -1,   142,   143,   144,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,    -1,    -1,    -1,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,   182,   183,   184,
     185,     4,     5,   188,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,     4,     5,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,     4,
       5,   104,    -1,    -1,   107,    -1,   109,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   120,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,   137,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    94,    -1,    -1,    97,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,   222,
      -1,   224,   225,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,   224,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,   258,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,   258,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,   258,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,   258,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,   258,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,   258,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
     258,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,   258,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,   258,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,   258,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,   258,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,   258,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,   258,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
     258,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,   258,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,   258,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,   258,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,   258,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,   258,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,   258,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,   258,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
     258,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,   257,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,   257,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
     254,    -1,   256,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,   256,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,   256,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,   256,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
     256,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,   256,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,   256,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,   256,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,   256,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,   256,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,   256,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,   256,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,   256,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,   256,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
     256,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,   256,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,   254
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   264,   265,     6,     0,     4,    13,    14,    46,
      47,    48,    67,    68,    69,    74,    75,    79,    84,    85,
      86,    87,    88,    90,    91,    93,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   116,   117,   118,   119,   120,   121,   123,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   142,   143,   144,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   171,
     172,   173,   177,   182,   183,   184,   185,   188,   190,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   212,   213,   214,   223,   225,   266,   268,
     269,   290,   309,   311,   315,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   333,   335,   336,   342,   343,   344,
     345,   351,   375,   376,   257,   261,    14,   107,   253,   253,
     253,     6,   257,     6,     6,     6,     6,   253,     6,     6,
     257,     6,     6,   255,   255,     4,   353,   376,   253,   255,
     287,   101,   104,   107,   109,   287,   253,   253,   253,     4,
     253,   253,   253,     4,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   257,   122,   107,     6,   257,
     101,   104,   107,   120,   314,   109,   253,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    58,    59,    60,    61,    66,    67,    76,    77,
      81,    82,    83,    92,    95,   101,   104,   107,   109,   120,
     130,   135,   137,   140,   206,   210,   211,   215,   216,   217,
     219,   220,   221,   241,   242,   248,   253,   257,   260,   311,
     312,   315,   326,   333,   335,   346,   347,   351,   353,   359,
     361,   376,   253,   257,   257,   107,   107,   130,   104,   107,
     109,   101,   104,   107,   109,   311,   104,   107,   108,   109,
     120,   183,   312,   104,   107,   253,   104,   162,   188,   204,
     205,   257,   241,   242,   253,   257,   356,   357,   356,   257,
     257,   356,     4,   101,   105,   111,   112,   114,   115,   134,
     257,   253,   107,   109,   107,   104,     4,    93,   199,   257,
     376,     4,     6,   101,   104,   107,   104,   107,   120,   313,
     107,     4,     4,     4,     5,   253,   257,   359,   360,     4,
     253,   253,   253,     4,   257,   363,   376,     4,   253,   253,
     253,     6,     6,   255,     5,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    62,    63,    64,    65,    70,    71,
      72,    73,    78,    80,    94,    97,   207,   208,   209,   218,
     222,   224,   367,   376,   253,     4,   367,     5,   257,     5,
     257,    32,   242,   346,   376,   255,   257,   253,   257,     6,
     253,   257,     6,   261,     7,   137,   199,   226,   227,   228,
     229,   250,   251,   253,   255,   259,   285,   286,   287,   311,
     346,   366,   367,   376,     4,   315,   316,   317,   257,     6,
     346,   366,   367,   376,   366,   366,   346,   366,   373,   374,
     376,   346,   292,   296,   253,   355,     9,   367,   253,   253,
     253,   253,   376,   346,   346,   346,   253,   346,   346,   346,
     253,   346,   346,   346,   346,   346,   346,   346,   366,   346,
     346,   346,   346,   360,   253,   242,   346,   361,   362,   257,
     360,   359,   366,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   253,   255,
     287,   287,   287,   287,   287,   287,   253,   287,   287,   253,
     311,   312,   312,   287,   287,     5,   257,   257,   130,   311,
     311,   253,   287,   287,   253,   253,   253,   346,   257,   346,
     361,   346,   346,   258,   362,   353,   376,   191,     5,   257,
       8,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   252,
       9,   253,   255,   259,   286,   287,   346,   362,   362,   253,
     253,   253,   359,   360,   360,   360,   310,   253,   257,   253,
     253,   359,   257,   257,   346,     4,   359,   257,   363,   257,
     257,   356,   356,   356,   346,   346,   241,   242,   257,   257,
     356,   241,   242,   253,   317,   356,   257,   253,   257,   253,
     253,   253,   253,   253,   253,   253,   362,   346,   360,   360,
     360,   253,     4,   255,   257,     6,   255,   317,     6,     6,
     257,   257,   257,   257,   360,   257,   255,   255,   255,   346,
       8,     6,     6,   346,   346,   346,   259,   346,   257,   191,
     346,   346,   346,   346,   287,   287,   287,   253,   253,   253,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     253,   253,   287,   253,   255,     6,     6,   257,     6,     8,
     317,     6,     8,   317,   287,   346,   243,   257,     9,   253,
     255,   259,   366,   362,   346,   317,   359,   359,   257,   367,
     311,     7,   346,   346,     4,    36,    37,   110,   111,   188,
     189,   289,   359,     6,   254,   256,   257,   288,   257,     6,
     257,     6,     9,   253,   255,   259,   376,   258,   130,   135,
     137,   138,   140,   309,   311,   346,     6,   254,   262,     9,
     253,   255,   259,   254,   262,   254,   262,   262,   254,   262,
       9,   253,   259,   262,   256,   262,   291,   256,   291,    96,
     354,   352,   376,   262,   346,   346,   346,   346,   262,   254,
     254,   254,   346,   254,   254,   254,   346,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   258,     7,
     346,   243,   258,   262,   346,     6,     6,   254,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   361,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   361,   361,   376,   257,   346,
     346,   366,   346,   366,   359,   366,   366,   373,   257,   257,
     257,   346,   288,   376,     8,   346,   346,   360,   359,   366,
     366,   361,   353,   367,   353,   362,   254,   258,   259,   287,
      67,     8,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   257,   346,   361,   346,
     346,   346,   346,   346,   376,   346,   346,   289,   257,   288,
     254,   258,   258,   346,   346,   346,     7,     7,   339,   339,
     253,   346,   346,   346,   346,     6,   362,   362,   257,   254,
       6,   317,   257,   317,   317,   262,   262,   262,   356,   356,
     316,   316,   262,   346,   258,   330,   262,   317,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   258,   254,     7,
     340,     6,     7,   346,     6,   346,   317,   346,   258,   362,
     362,   362,   346,     6,   362,   346,   346,   346,   254,   258,
     254,   254,   254,   188,   262,   317,   257,     8,   254,   254,
     256,   373,   366,   373,   366,   366,   366,   366,   366,   366,
     346,   366,   366,   366,   366,   260,   369,   376,   367,   366,
     366,   366,   353,   376,   362,   258,   258,   258,   258,   346,
     346,   317,   376,   289,   256,   258,   254,   144,   162,   334,
     254,   258,   262,   346,     6,   257,   359,   254,   256,   259,
       7,     7,   285,   286,     6,   362,     7,   229,   285,   346,
     270,   376,   346,   346,   289,   255,   253,   130,   311,   312,
     311,   257,   258,     6,   236,   237,   267,   362,   376,   346,
     346,   289,     6,   362,     6,   362,   346,     6,   366,   374,
     376,   254,   289,   346,     6,   376,     6,   366,   346,   254,
     255,   346,   262,   262,   262,   262,   367,     7,     7,     7,
     254,     7,     7,     7,   254,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   346,   254,   257,   346,   361,
     258,     6,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   262,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   262,   262,   262,   262,   262,   254,   256,
     256,   362,   262,   262,   288,   262,   288,   262,   262,   262,
     254,   362,   346,   346,   348,   288,   258,   258,   258,   262,
     262,   288,   288,   254,   259,   254,   259,   262,   287,   349,
     258,     7,   289,   288,   257,   258,     8,     8,   362,   259,
     254,   256,   253,   255,   286,   287,   362,     7,   257,   257,
     254,   254,   254,   346,   359,     4,   338,     6,   305,   346,
     367,   254,   258,   254,   254,   258,   258,   362,   259,   258,
     317,   258,   258,   356,   346,   346,   258,   258,   346,   356,
     141,   141,   159,   168,   169,   170,   174,   175,   331,   332,
     356,   258,   327,   254,   258,   254,   254,   254,   254,   254,
     254,   254,   257,     7,   346,     6,   346,   254,   256,   258,
     256,   258,   258,   258,   258,   258,   256,   256,   262,     7,
       7,     7,   259,   346,   258,   346,   346,     7,   259,   288,
     262,   288,   288,   254,   254,   262,   288,   288,   262,   262,
     288,   288,   288,   288,   346,   288,     9,   368,   262,   254,
     262,   288,   259,   262,   350,   256,   258,   258,   259,   253,
     255,   261,   191,     7,   162,     6,   346,   258,   257,     6,
     359,   258,   346,     6,     7,   285,   286,   259,   285,   286,
     289,   257,   364,   376,   367,   346,     6,   258,    49,    49,
     359,   258,     4,   178,   179,   180,   181,   258,   273,   277,
     280,   282,   283,   325,   259,   254,   256,   253,   346,   346,
     253,   257,   253,   257,     8,   362,   366,   254,   259,   254,
     256,   253,   254,   254,   262,   259,   253,   262,     7,   287,
       4,    36,    37,   299,   300,   301,   288,   346,   346,   346,
     346,   288,   356,   359,   359,     7,   359,   359,   359,     7,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
       6,     7,   362,   346,   346,   346,   346,   346,   346,   258,
     346,   346,   346,   359,   366,   366,   258,   258,   258,   262,
     298,   346,   346,   289,   289,   346,   346,   254,   359,   287,
     346,   346,   346,   258,   289,   286,   259,   286,   346,   346,
     288,   258,   359,   362,   362,     7,     7,     7,   141,   337,
       6,   254,   262,     7,     7,     7,     7,     7,   258,     4,
     289,   258,   262,   262,   262,   258,   258,   119,     4,     6,
     346,   257,     6,   253,     6,   176,     6,   176,   258,   332,
     262,   331,     7,     6,     7,     7,     7,     7,     7,     7,
       7,   316,   359,     6,   257,     6,     6,     6,   107,     7,
       7,     6,     6,   346,   359,   359,   359,     4,   262,     8,
       8,   254,   289,   289,   362,   366,   346,   366,   260,   262,
     302,   366,   366,   289,   366,   254,   262,   289,   257,   311,
     257,     6,   346,     6,   257,   359,   258,   258,   346,     6,
     188,   189,   289,   346,     6,     7,   363,   365,     6,   255,
       6,     6,   288,   287,   287,     6,   274,   253,   253,   257,
     284,     6,   289,   259,   366,   346,   256,   254,   346,     8,
     362,   346,   362,   258,   258,     6,     6,   267,   289,   259,
     346,     6,     6,   346,   289,   254,   346,   257,   346,   367,
     288,    49,   257,   359,   367,   370,   346,   346,   256,   262,
       6,   254,   254,   254,   254,     6,     6,   134,   307,   307,
     359,     6,     6,     6,   359,   141,   191,   306,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     5,   258,   288,
     288,   288,   288,   288,   288,   288,   262,   262,   262,   254,
     288,   288,   300,   288,   254,   288,   254,   287,   349,   288,
       6,   288,   262,   253,   255,   287,   289,   254,   256,   288,
       6,   258,   258,   359,   359,   359,     4,     6,   285,   346,
     359,   359,   359,   257,   257,     7,     6,     7,   346,   346,
     346,   257,   257,   257,   255,     6,   346,   359,   346,     6,
       6,   346,   356,   258,     5,   359,   257,   257,   257,   257,
     257,   257,   257,   359,   258,     6,   362,   257,   346,   346,
     256,     6,     6,   187,   346,   346,   346,     6,     6,     7,
     288,   262,   262,   288,   262,   346,     4,   203,   303,   304,
     288,   254,   288,   350,   367,   253,   255,   346,   257,   317,
       6,   317,   262,     6,     6,   259,     7,     7,   285,   286,
       6,   363,   258,   262,   346,   285,   257,   288,   371,   372,
     373,   371,   253,   346,   346,   358,   359,   257,   253,     4,
       6,   254,     6,   254,   258,   258,   254,   258,     6,     6,
     366,   253,     4,   254,   262,   253,   258,   262,   359,   367,
       7,   287,   297,   346,   361,   301,     6,     6,     6,     6,
     356,     6,     6,     6,   141,   308,   101,   120,   105,     6,
       5,   257,   346,   346,   346,   346,   254,   349,   346,   346,
     346,   288,   286,   257,   257,     6,   306,     6,   346,   359,
     141,   141,     4,     6,   362,   362,   346,   346,   367,   258,
     254,   258,   262,   316,   316,   346,   346,   258,   262,   254,
     258,   262,     6,     6,   358,   356,   356,   356,   356,   356,
     242,   356,     6,   258,   346,     6,     6,     6,   359,   258,
     262,     8,   258,   254,   257,   346,   367,   366,   346,   366,
     346,   367,   370,   372,   367,   262,   254,   262,   258,   346,
     334,   334,   359,   289,   364,   367,   346,     6,     6,   363,
     256,   359,   373,     6,   288,   288,   271,   346,   262,   262,
     258,   262,   272,   346,   346,     6,     6,     6,     6,   346,
     346,   254,     6,   346,   293,   295,   257,   372,   258,   262,
       7,     7,   145,     6,   257,   257,   257,     5,   358,   288,
     288,   262,   288,   254,   262,   254,   256,   362,   362,     6,
       6,   346,   346,   257,   258,   258,   257,     6,     6,   257,
     346,   258,   258,   258,   256,     6,   359,     7,   257,   346,
     258,   262,   262,   262,   262,   262,   262,     6,   258,   186,
     346,   346,   362,     6,     6,   254,   288,   288,   304,   367,
     258,   258,   258,   258,     7,     6,     6,     6,   259,     6,
     258,     6,     6,   254,   262,   346,   346,   257,   359,   258,
     262,   254,   254,   262,   258,   298,   302,   359,   288,   346,
     367,   376,   362,   362,   346,     6,   258,   346,   349,   346,
     258,   258,     6,     6,   358,   146,   147,   152,   341,   146,
     147,   341,   362,   316,   258,   262,     6,   258,   359,   317,
     258,     6,   362,   356,   356,   356,   356,   356,   346,   258,
     258,   258,   254,     6,   257,     6,   363,   189,   275,   346,
     262,   262,   358,     6,   346,   346,     6,   258,   258,   294,
       7,   253,   258,   258,   258,   257,   262,   254,   262,   257,
     258,   257,   356,   359,     6,   257,   356,     6,   258,   258,
     346,     6,   141,   258,   328,   257,   258,   262,   262,   262,
     262,   262,     6,     6,     6,   317,     6,   257,   346,   346,
     258,   262,   298,   367,   254,   346,   346,   346,   362,     6,
     356,     6,   356,     6,     6,   258,   346,   331,   317,     6,
     362,   362,   362,   362,   356,   362,   334,   272,   254,   262,
       6,   257,   346,   258,   262,   262,   262,   258,   262,   262,
       6,   258,   258,   329,   258,   258,   258,   258,   262,   258,
     258,   258,   278,   346,   358,   258,   346,   346,   346,   356,
     356,   331,     6,     6,     6,     6,   362,     6,     6,     6,
     257,   254,   258,     6,   258,   288,   262,   262,   262,   258,
     258,   276,   366,   281,   257,     6,   346,   346,   346,     6,
     258,   262,   257,   358,   258,   258,   258,     6,   366,   279,
     366,   258,     6,     6,   258,   262,     6,     6,   366
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
#line 271 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 282 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 283 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 284 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 286 "Gmsh.y"
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
#line 304 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 305 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 306 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 307 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 308 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 309 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 310 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 311 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 312 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 315 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 316 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 317 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 318 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 319 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 324 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 328 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 335 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 340 "Gmsh.y"
    {
      Msg::Warning((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 345 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 31:
#line 350 "Gmsh.y"
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
#line 364 "Gmsh.y"
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
#line 377 "Gmsh.y"
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
#line 390 "Gmsh.y"
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
#line 403 "Gmsh.y"
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
#line 431 "Gmsh.y"
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
#line 445 "Gmsh.y"
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
#line 458 "Gmsh.y"
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
#line 471 "Gmsh.y"
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
#line 489 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 47:
#line 504 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 48:
#line 506 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 49:
#line 511 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 50:
#line 513 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 51:
#line 518 "Gmsh.y"
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
#line 622 "Gmsh.y"
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
#line 632 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 54:
#line 641 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 55:
#line 648 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 56:
#line 658 "Gmsh.y"
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
#line 667 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 58:
#line 676 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 59:
#line 683 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 60:
#line 693 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 61:
#line 701 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 62:
#line 711 "Gmsh.y"
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
#line 730 "Gmsh.y"
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
#line 749 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 65:
#line 755 "Gmsh.y"
    {
    ;}
    break;

  case 66:
#line 762 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 67:
#line 763 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 68:
#line 764 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 69:
#line 765 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 70:
#line 766 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 71:
#line 770 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 72:
#line 771 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 73:
#line 777 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 74:
#line 777 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 75:
#line 779 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 76:
#line 779 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 784 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 78:
#line 785 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Min"); ;}
    break;

  case 79:
#line 786 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Max"); ;}
    break;

  case 80:
#line 787 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(4 * sizeof(char)); strcpy((yyval.c), "Box"); ;}
    break;

  case 81:
#line 788 "Gmsh.y"
    { (yyval.c) = (char *)Malloc(9 * sizeof(char)); strcpy((yyval.c), "Cylinder"); ;}
    break;

  case 85:
#line 798 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 86:
#line 803 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 87:
#line 809 "Gmsh.y"
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
#line 871 "Gmsh.y"
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
#line 886 "Gmsh.y"
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
#line 915 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 91:
#line 925 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 92:
#line 930 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 93:
#line 938 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 94:
#line 943 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 95:
#line 951 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 96:
#line 960 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 97:
#line 965 "Gmsh.y"
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
#line 977 "Gmsh.y"
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
#line 994 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 100:
#line 1000 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 101:
#line 1009 "Gmsh.y"
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
#line 1027 "Gmsh.y"
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
#line 1045 "Gmsh.y"
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
#line 1054 "Gmsh.y"
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
#line 1066 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 106:
#line 1071 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 107:
#line 1079 "Gmsh.y"
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
#line 1099 "Gmsh.y"
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
#line 1122 "Gmsh.y"
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
#line 1142 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 111:
#line 1150 "Gmsh.y"
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
#line 1172 "Gmsh.y"
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
#line 1195 "Gmsh.y"
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
#line 1233 "Gmsh.y"
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
#line 1254 "Gmsh.y"
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
#line 1266 "Gmsh.y"
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
#line 1284 "Gmsh.y"
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
#line 1293 "Gmsh.y"
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
#line 1302 "Gmsh.y"
    { init_options(); ;}
    break;

  case 123:
#line 1304 "Gmsh.y"
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
#line 1322 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
#line 1324 "Gmsh.y"
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
#line 1340 "Gmsh.y"
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
#line 1349 "Gmsh.y"
    { init_options(); ;}
    break;

  case 128:
#line 1351 "Gmsh.y"
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
#line 1365 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 131:
#line 1373 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 132:
#line 1379 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 133:
#line 1384 "Gmsh.y"
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
#line 1427 "Gmsh.y"
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
#line 1439 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 142:
#line 1443 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 143:
#line 1447 "Gmsh.y"
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
#line 1460 "Gmsh.y"
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
#line 1474 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1482 "Gmsh.y"
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
#line 1507 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 152:
#line 1515 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 153:
#line 1524 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 154:
#line 1532 "Gmsh.y"
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
#line 1546 "Gmsh.y"
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
#line 1564 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 157:
#line 1568 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 158:
#line 1575 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 159:
#line 1583 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 160:
#line 1587 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 161:
#line 1593 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 162:
#line 1597 "Gmsh.y"
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
#line 1608 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 164:
#line 1612 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 165:
#line 1618 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 166:
#line 1622 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 167:
#line 1628 "Gmsh.y"
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
#line 1651 "Gmsh.y"
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
#line 1667 "Gmsh.y"
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
#line 1683 "Gmsh.y"
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
#line 1700 "Gmsh.y"
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
#line 1717 "Gmsh.y"
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
#line 1754 "Gmsh.y"
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
#line 1798 "Gmsh.y"
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
#line 1814 "Gmsh.y"
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
#line 1831 "Gmsh.y"
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
#line 1862 "Gmsh.y"
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
#line 1878 "Gmsh.y"
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
#line 1895 "Gmsh.y"
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
#line 1911 "Gmsh.y"
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
#line 1961 "Gmsh.y"
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
#line 1979 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 183:
#line 1985 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 184:
#line 1991 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 185:
#line 1998 "Gmsh.y"
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
#line 2029 "Gmsh.y"
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
#line 2044 "Gmsh.y"
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
#line 2066 "Gmsh.y"
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
#line 2089 "Gmsh.y"
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
#line 2112 "Gmsh.y"
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
#line 2135 "Gmsh.y"
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
#line 2159 "Gmsh.y"
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
#line 2183 "Gmsh.y"
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
#line 2207 "Gmsh.y"
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
#line 2233 "Gmsh.y"
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
#line 2250 "Gmsh.y"
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
#line 2266 "Gmsh.y"
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
#line 2284 "Gmsh.y"
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
#line 2302 "Gmsh.y"
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
#line 2315 "Gmsh.y"
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
#line 2327 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 202:
#line 2331 "Gmsh.y"
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
#line 2357 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2359 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2361 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2363 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 207:
#line 2365 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 208:
#line 2373 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 209:
#line 2375 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 210:
#line 2377 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 211:
#line 2379 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 212:
#line 2387 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 213:
#line 2389 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 214:
#line 2391 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 215:
#line 2399 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 216:
#line 2401 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 217:
#line 2403 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 218:
#line 2405 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 219:
#line 2415 "Gmsh.y"
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
#line 2431 "Gmsh.y"
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
#line 2447 "Gmsh.y"
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
#line 2463 "Gmsh.y"
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
#line 2479 "Gmsh.y"
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
#line 2495 "Gmsh.y"
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
#line 2512 "Gmsh.y"
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
#line 2549 "Gmsh.y"
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
        yymsg(0, "Split Line not available with OpenCASCADE geometry kernel");
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
      if(!r) yymsg(0, "Could not split line");
      List_Delete((yyvsp[(7) - (9)].l));
    ;}
    break;

  case 228:
#line 2594 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 229:
#line 2595 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 230:
#line 2600 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 231:
#line 2604 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 232:
#line 2608 "Gmsh.y"
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

  case 233:
#line 2625 "Gmsh.y"
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

  case 234:
#line 2645 "Gmsh.y"
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

  case 235:
#line 2665 "Gmsh.y"
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

  case 236:
#line 2684 "Gmsh.y"
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

  case 237:
#line 2711 "Gmsh.y"
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

  case 238:
#line 2730 "Gmsh.y"
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

  case 239:
#line 2752 "Gmsh.y"
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

  case 240:
#line 2767 "Gmsh.y"
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

  case 241:
#line 2782 "Gmsh.y"
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

  case 242:
#line 2801 "Gmsh.y"
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

  case 243:
#line 2852 "Gmsh.y"
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

  case 244:
#line 2873 "Gmsh.y"
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

  case 245:
#line 2895 "Gmsh.y"
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

  case 246:
#line 2917 "Gmsh.y"
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

  case 247:
#line 3022 "Gmsh.y"
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

  case 248:
#line 3038 "Gmsh.y"
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

  case 249:
#line 3073 "Gmsh.y"
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

  case 250:
#line 3095 "Gmsh.y"
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

  case 251:
#line 3117 "Gmsh.y"
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

  case 252:
#line 3129 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 253:
#line 3135 "Gmsh.y"
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

  case 254:
#line 3150 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (3)].c), "Meshes") || !strcmp((yyvsp[(2) - (3)].c), "All")){
        ClearProject();
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

  case 255:
#line 3178 "Gmsh.y"
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

  case 256:
#line 3190 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 257:
#line 3199 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 258:
#line 3206 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 259:
#line 3218 "Gmsh.y"
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

  case 260:
#line 3238 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 261:
#line 3242 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 262:
#line 3247 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 263:
#line 3251 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 264:
#line 3256 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 265:
#line 3263 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 266:
#line 3270 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 267:
#line 3277 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 268:
#line 3289 "Gmsh.y"
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

  case 269:
#line 3362 "Gmsh.y"
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

  case 270:
#line 3380 "Gmsh.y"
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

  case 271:
#line 3405 "Gmsh.y"
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

  case 272:
#line 3420 "Gmsh.y"
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

  case 273:
#line 3453 "Gmsh.y"
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

  case 274:
#line 3465 "Gmsh.y"
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

  case 275:
#line 3497 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 276:
#line 3501 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 277:
#line 3506 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 278:
#line 3513 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 279:
#line 3518 "Gmsh.y"
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

  case 280:
#line 3528 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 281:
#line 3533 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 282:
#line 3539 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 283:
#line 3547 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 284:
#line 3551 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 285:
#line 3555 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 286:
#line 3559 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 287:
#line 3563 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 288:
#line 3567 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 289:
#line 3571 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 290:
#line 3581 "Gmsh.y"
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

  case 291:
#line 3644 "Gmsh.y"
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

  case 292:
#line 3660 "Gmsh.y"
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

  case 293:
#line 3677 "Gmsh.y"
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

  case 294:
#line 3694 "Gmsh.y"
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

  case 295:
#line 3716 "Gmsh.y"
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

  case 296:
#line 3738 "Gmsh.y"
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

  case 297:
#line 3773 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 298:
#line 3781 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 299:
#line 3789 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 300:
#line 3795 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 301:
#line 3802 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 302:
#line 3809 "Gmsh.y"
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

  case 303:
#line 3829 "Gmsh.y"
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

  case 304:
#line 3855 "Gmsh.y"
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

  case 305:
#line 3867 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 306:
#line 3878 "Gmsh.y"
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

  case 307:
#line 3896 "Gmsh.y"
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

  case 308:
#line 3914 "Gmsh.y"
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

  case 309:
#line 3932 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 310:
#line 3938 "Gmsh.y"
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

  case 311:
#line 3956 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 312:
#line 3962 "Gmsh.y"
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

  case 313:
#line 3982 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 314:
#line 3988 "Gmsh.y"
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

  case 315:
#line 4006 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 316:
#line 4012 "Gmsh.y"
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

  case 317:
#line 4029 "Gmsh.y"
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

  case 318:
#line 4045 "Gmsh.y"
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

  case 319:
#line 4062 "Gmsh.y"
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

  case 320:
#line 4080 "Gmsh.y"
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

  case 321:
#line 4103 "Gmsh.y"
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

  case 322:
#line 4130 "Gmsh.y"
    {
    ;}
    break;

  case 323:
#line 4133 "Gmsh.y"
    {
    ;}
    break;

  case 324:
#line 4139 "Gmsh.y"
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

  case 325:
#line 4151 "Gmsh.y"
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

  case 326:
#line 4171 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 327:
#line 4175 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 328:
#line 4179 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 329:
#line 4183 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 330:
#line 4187 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 331:
#line 4191 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 332:
#line 4195 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 333:
#line 4199 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 334:
#line 4208 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 335:
#line 4220 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 336:
#line 4221 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 337:
#line 4222 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 338:
#line 4223 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 339:
#line 4224 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 340:
#line 4228 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 341:
#line 4229 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 342:
#line 4230 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 343:
#line 4231 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 344:
#line 4232 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 345:
#line 4237 "Gmsh.y"
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

  case 346:
#line 4260 "Gmsh.y"
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

  case 347:
#line 4280 "Gmsh.y"
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

  case 348:
#line 4301 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 349:
#line 4305 "Gmsh.y"
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

  case 350:
#line 4320 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 351:
#line 4324 "Gmsh.y"
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

  case 352:
#line 4340 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 353:
#line 4344 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 354:
#line 4349 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 355:
#line 4353 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 356:
#line 4359 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 357:
#line 4363 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 358:
#line 4370 "Gmsh.y"
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

  case 359:
#line 4392 "Gmsh.y"
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

  case 360:
#line 4433 "Gmsh.y"
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

  case 361:
#line 4477 "Gmsh.y"
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

  case 362:
#line 4516 "Gmsh.y"
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

  case 363:
#line 4541 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GVertex *gf = GModel::current()->getVertexByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model point %d",tag);
      }
    ;}
    break;

  case 364:
#line 4553 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GEdge *gf = GModel::current()->getEdgeByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model curve %d",tag);
      }
    ;}
    break;

  case 365:
#line 4565 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model surface %d",tag);
      }
    ;}
    break;

  case 366:
#line 4577 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GRegion *gf = GModel::current()->getRegionByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown model volume %d",tag);
      }
    ;}
    break;

  case 367:
#line 4589 "Gmsh.y"
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
#line 4606 "Gmsh.y"
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
#line 4623 "Gmsh.y"
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
#line 4653 "Gmsh.y"
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
#line 4679 "Gmsh.y"
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
#line 4706 "Gmsh.y"
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
#line 4738 "Gmsh.y"
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
#line 4765 "Gmsh.y"
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
#line 4791 "Gmsh.y"
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
#line 4817 "Gmsh.y"
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
#line 4843 "Gmsh.y"
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
#line 4869 "Gmsh.y"
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
#line 4890 "Gmsh.y"
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
#line 4901 "Gmsh.y"
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
#line 4949 "Gmsh.y"
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
#line 5003 "Gmsh.y"
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
#line 5018 "Gmsh.y"
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
#line 5030 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 385:
#line 5041 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 386:
#line 5048 "Gmsh.y"
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
#line 5063 "Gmsh.y"
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
#line 5076 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 389:
#line 5077 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 390:
#line 5078 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 391:
#line 5083 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 392:
#line 5089 "Gmsh.y"
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
#line 5101 "Gmsh.y"
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
#line 5119 "Gmsh.y"
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
#line 5146 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 396:
#line 5147 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 397:
#line 5148 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 398:
#line 5149 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 399:
#line 5150 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 5151 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 401:
#line 5152 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 402:
#line 5153 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5155 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 404:
#line 5161 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 405:
#line 5162 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 406:
#line 5163 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 407:
#line 5164 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 408:
#line 5165 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 409:
#line 5166 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 410:
#line 5167 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5168 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5169 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5170 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5171 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5172 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5173 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 417:
#line 5174 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 418:
#line 5175 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 419:
#line 5176 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 420:
#line 5177 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5178 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 422:
#line 5179 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5180 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 424:
#line 5181 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5182 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5183 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5184 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5185 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5186 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 430:
#line 5187 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5188 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5189 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5190 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5191 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 435:
#line 5192 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 436:
#line 5193 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 437:
#line 5194 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 438:
#line 5195 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 439:
#line 5196 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 440:
#line 5197 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5198 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 442:
#line 5199 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5200 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 444:
#line 5209 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 445:
#line 5210 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 446:
#line 5211 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 447:
#line 5212 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 448:
#line 5213 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 449:
#line 5214 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 450:
#line 5215 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 451:
#line 5216 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 452:
#line 5217 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 453:
#line 5218 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 454:
#line 5219 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 455:
#line 5224 "Gmsh.y"
    { init_options(); ;}
    break;

  case 456:
#line 5226 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 457:
#line 5232 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 458:
#line 5234 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 459:
#line 5239 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 460:
#line 5244 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 461:
#line 5249 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 462:
#line 5254 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 463:
#line 5258 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 464:
#line 5262 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 465:
#line 5266 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 466:
#line 5270 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 467:
#line 5274 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 468:
#line 5278 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 469:
#line 5282 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5288 "Gmsh.y"
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
#line 5303 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 472:
#line 5307 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 473:
#line 5313 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 474:
#line 5318 "Gmsh.y"
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
#line 5337 "Gmsh.y"
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

  case 477:
#line 5378 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 478:
#line 5382 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 479:
#line 5386 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 480:
#line 5390 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 481:
#line 5394 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 482:
#line 5398 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 483:
#line 5402 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 484:
#line 5407 "Gmsh.y"
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
#line 5417 "Gmsh.y"
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
#line 5427 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 487:
#line 5432 "Gmsh.y"
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
#line 5443 "Gmsh.y"
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
#line 5452 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 490:
#line 5457 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 491:
#line 5462 "Gmsh.y"
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
#line 5489 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 493:
#line 5491 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 494:
#line 5496 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 495:
#line 5498 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 496:
#line 5503 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 497:
#line 5510 "Gmsh.y"
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
#line 5526 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 499:
#line 5528 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 500:
#line 5533 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 501:
#line 5535 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 502:
#line 5540 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 503:
#line 5542 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 504:
#line 5547 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 505:
#line 5551 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 506:
#line 5555 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 507:
#line 5559 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 508:
#line 5563 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 509:
#line 5570 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 510:
#line 5574 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 511:
#line 5578 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 512:
#line 5582 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 513:
#line 5589 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 514:
#line 5594 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 515:
#line 5601 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 516:
#line 5606 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 517:
#line 5610 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 518:
#line 5615 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 519:
#line 5619 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 520:
#line 5627 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 521:
#line 5638 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 522:
#line 5642 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 523:
#line 5646 "Gmsh.y"
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
#line 5660 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 525:
#line 5668 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 526:
#line 5676 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 527:
#line 5683 "Gmsh.y"
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
#line 5693 "Gmsh.y"
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
#line 5716 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 530:
#line 5721 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 531:
#line 5727 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 532:
#line 5732 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 533:
#line 5738 "Gmsh.y"
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
#line 5749 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 535:
#line 5756 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 536:
#line 5761 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 537:
#line 5767 "Gmsh.y"
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
#line 5779 "Gmsh.y"
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
#line 5793 "Gmsh.y"
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
#line 5803 "Gmsh.y"
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
#line 5813 "Gmsh.y"
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
#line 5823 "Gmsh.y"
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
#line 5835 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 544:
#line 5839 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 545:
#line 5844 "Gmsh.y"
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
#line 5856 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 547:
#line 5860 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 548:
#line 5864 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 549:
#line 5868 "Gmsh.y"
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
#line 5886 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 551:
#line 5894 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 552:
#line 5902 "Gmsh.y"
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
#line 5931 "Gmsh.y"
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
#line 5941 "Gmsh.y"
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
#line 5957 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 556:
#line 5968 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 557:
#line 5973 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 558:
#line 5977 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 559:
#line 5981 "Gmsh.y"
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
#line 5993 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 561:
#line 5997 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 562:
#line 6009 "Gmsh.y"
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
#line 6026 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 564:
#line 6036 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 565:
#line 6040 "Gmsh.y"
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
#line 6055 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 567:
#line 6060 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 568:
#line 6067 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 569:
#line 6071 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 570:
#line 6076 "Gmsh.y"
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
#line 6090 "Gmsh.y"
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
#line 6104 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 573:
#line 6108 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 574:
#line 6112 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 575:
#line 6116 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 576:
#line 6120 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 577:
#line 6128 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 578:
#line 6134 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 579:
#line 6143 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 580:
#line 6147 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 581:
#line 6151 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 582:
#line 6159 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 583:
#line 6165 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 584:
#line 6171 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 585:
#line 6175 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6182 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 587:
#line 6190 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6197 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 589:
#line 6206 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 590:
#line 6210 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 591:
#line 6214 "Gmsh.y"
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
#line 6229 "Gmsh.y"
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
#line 6243 "Gmsh.y"
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
#line 6257 "Gmsh.y"
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
#line 6269 "Gmsh.y"
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
#line 6285 "Gmsh.y"
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
#line 6294 "Gmsh.y"
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
#line 6303 "Gmsh.y"
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
#line 6313 "Gmsh.y"
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
#line 6324 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 601:
#line 6332 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 602:
#line 6340 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 603:
#line 6344 "Gmsh.y"
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
#line 6363 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 605:
#line 6370 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 606:
#line 6376 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 607:
#line 6382 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 608:
#line 6389 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6396 "Gmsh.y"
    { init_options(); ;}
    break;

  case 610:
#line 6398 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 611:
#line 6406 "Gmsh.y"
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
#line 6430 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 613:
#line 6432 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 614:
#line 6438 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 615:
#line 6443 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 616:
#line 6445 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 617:
#line 6450 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 618:
#line 6455 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 619:
#line 6460 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 620:
#line 6462 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 621:
#line 6466 "Gmsh.y"
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
#line 6478 "Gmsh.y"
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
#line 6492 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 624:
#line 6496 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 625:
#line 6503 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 626:
#line 6511 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 627:
#line 6519 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 628:
#line 6530 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 629:
#line 6532 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 630:
#line 6535 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14690 "Gmsh.tab.cpp"
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


#line 6538 "Gmsh.y"


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

