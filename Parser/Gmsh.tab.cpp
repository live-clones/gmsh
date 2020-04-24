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
     tHomology = 468,
     tCohomology = 469,
     tBetti = 470,
     tExists = 471,
     tFileExists = 472,
     tGetForced = 473,
     tGetForcedStr = 474,
     tGMSH_MAJOR_VERSION = 475,
     tGMSH_MINOR_VERSION = 476,
     tGMSH_PATCH_VERSION = 477,
     tGmshExecutableName = 478,
     tSetPartition = 479,
     tNameToString = 480,
     tStringToName = 481,
     tAFFECTDIVIDE = 482,
     tAFFECTTIMES = 483,
     tAFFECTMINUS = 484,
     tAFFECTPLUS = 485,
     tOR = 486,
     tAND = 487,
     tNOTEQUAL = 488,
     tEQUAL = 489,
     tGREATERGREATER = 490,
     tLESSLESS = 491,
     tGREATEROREQUAL = 492,
     tLESSOREQUAL = 493,
     UNARYPREC = 494,
     tMINUSMINUS = 495,
     tPLUSPLUS = 496
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
#define tHomology 468
#define tCohomology 469
#define tBetti 470
#define tExists 471
#define tFileExists 472
#define tGetForced 473
#define tGetForcedStr 474
#define tGMSH_MAJOR_VERSION 475
#define tGMSH_MINOR_VERSION 476
#define tGMSH_PATCH_VERSION 477
#define tGmshExecutableName 478
#define tSetPartition 479
#define tNameToString 480
#define tStringToName 481
#define tAFFECTDIVIDE 482
#define tAFFECTTIMES 483
#define tAFFECTMINUS 484
#define tAFFECTPLUS 485
#define tOR 486
#define tAND 487
#define tNOTEQUAL 488
#define tEQUAL 489
#define tGREATERGREATER 490
#define tLESSLESS 491
#define tGREATEROREQUAL 492
#define tLESSOREQUAL 493
#define UNARYPREC 494
#define tMINUSMINUS 495
#define tPLUSPLUS 496




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
#line 761 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 774 "Gmsh.tab.cpp"

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
#define YYLAST   17558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  264
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  632
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2257

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   496

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   249,     2,   261,     2,   246,   248,     2,
     254,   255,   244,   242,   263,   243,   260,   245,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     236,     2,   237,   231,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   256,     2,   257,   253,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   258,   247,   259,   262,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   232,   233,   234,   235,
     238,   239,   240,   241,   250,   251,   252
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
    1967,  1974,  1982,  1989,  1995,  1999,  2008,  2017,  2026,  2035,
    2044,  2053,  2059,  2064,  2071,  2083,  2095,  2114,  2133,  2146,
    2159,  2172,  2183,  2188,  2193,  2198,  2203,  2208,  2211,  2215,
    2222,  2224,  2226,  2228,  2231,  2237,  2245,  2256,  2258,  2262,
    2265,  2268,  2271,  2275,  2279,  2283,  2287,  2291,  2295,  2299,
    2303,  2307,  2311,  2315,  2319,  2323,  2327,  2331,  2335,  2339,
    2343,  2349,  2354,  2359,  2364,  2369,  2374,  2379,  2384,  2389,
    2394,  2399,  2406,  2411,  2416,  2421,  2426,  2431,  2436,  2441,
    2446,  2453,  2460,  2467,  2472,  2479,  2486,  2488,  2490,  2492,
    2494,  2496,  2498,  2500,  2502,  2504,  2506,  2508,  2509,  2516,
    2518,  2523,  2530,  2532,  2537,  2542,  2547,  2554,  2560,  2568,
    2577,  2588,  2593,  2598,  2605,  2610,  2614,  2617,  2623,  2629,
    2633,  2639,  2646,  2655,  2662,  2671,  2678,  2683,  2691,  2698,
    2705,  2712,  2717,  2724,  2729,  2730,  2733,  2734,  2737,  2738,
    2746,  2748,  2752,  2754,  2757,  2758,  2762,  2764,  2767,  2770,
    2774,  2778,  2790,  2800,  2808,  2816,  2818,  2822,  2824,  2826,
    2829,  2833,  2838,  2844,  2846,  2850,  2852,  2855,  2859,  2863,
    2869,  2874,  2879,  2882,  2887,  2890,  2894,  2898,  2903,  2909,
    2915,  2921,  2923,  2925,  2927,  2931,  2937,  2945,  2950,  2955,
    2960,  2967,  2974,  2983,  2992,  2997,  3012,  3017,  3022,  3024,
    3026,  3030,  3034,  3044,  3052,  3054,  3060,  3064,  3071,  3073,
    3077,  3079,  3081,  3086,  3091,  3095,  3101,  3108,  3117,  3124,
    3129,  3135,  3137,  3142,  3144,  3146,  3148,  3150,  3155,  3162,
    3167,  3174,  3180,  3188,  3193,  3198,  3203,  3212,  3217,  3222,
    3227,  3232,  3241,  3250,  3257,  3262,  3269,  3274,  3276,  3278,
    3283,  3288,  3289,  3296,  3301,  3304,  3309,  3314,  3316,  3318,
    3322,  3324,  3326,  3330,  3334,  3338,  3344,  3352,  3358,  3364,
    3373,  3375,  3377
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     265,     0,    -1,   266,    -1,     1,     6,    -1,    -1,   266,
     267,    -1,   269,    -1,   270,    -1,   291,    -1,   130,   254,
     367,   255,     6,    -1,   310,    -1,   316,    -1,   320,    -1,
     321,    -1,   322,    -1,   323,    -1,   327,    -1,   336,    -1,
     337,    -1,   343,    -1,   344,    -1,   326,    -1,   325,    -1,
     324,    -1,   319,    -1,   346,    -1,   237,    -1,   238,    -1,
      46,   254,   367,   255,     6,    -1,    48,   254,   367,   255,
       6,    -1,    47,   254,   367,   255,     6,    -1,    46,   254,
     367,   255,   268,   367,     6,    -1,    46,   254,   367,   263,
     363,   255,     6,    -1,    48,   254,   367,   263,   363,   255,
       6,    -1,    47,   254,   367,   263,   363,   255,     6,    -1,
      46,   254,   367,   263,   363,   255,   268,   367,     6,    -1,
     377,   367,   258,   271,   259,     6,    -1,   172,     4,   256,
     347,   257,     6,    -1,   173,     4,   256,   347,   257,     6,
      -1,   174,     4,   256,   347,   263,   347,   257,     6,    -1,
      -1,   271,   274,    -1,   271,   278,    -1,   271,   281,    -1,
     271,   283,    -1,   271,   284,    -1,   271,   326,    -1,   347,
      -1,   272,   263,   347,    -1,   347,    -1,   273,   263,   347,
      -1,    -1,    -1,     4,   275,   254,   272,   255,   276,   258,
     273,   259,     6,    -1,   367,    -1,   277,   263,   367,    -1,
      -1,   179,   254,   347,   263,   347,   263,   347,   255,   279,
     258,   277,   259,     6,    -1,   367,    -1,   280,   263,   367,
      -1,    -1,   180,   254,   347,   263,   347,   263,   347,   263,
     347,   255,   282,   258,   280,   259,     6,    -1,   181,   258,
     359,   259,   258,   359,   259,     6,    -1,   181,   258,   359,
     259,   258,   359,   259,   258,   359,   259,   258,   359,   259,
       6,    -1,    -1,   182,   285,   258,   273,   259,     6,    -1,
       7,    -1,   230,    -1,   229,    -1,   228,    -1,   227,    -1,
     252,    -1,   251,    -1,   254,    -1,   256,    -1,   255,    -1,
     257,    -1,     4,    -1,    36,    -1,    37,    -1,   110,    -1,
     111,    -1,    90,   256,   293,   257,     6,    -1,    91,   256,
     297,   257,     6,    -1,   352,     6,    -1,    98,   288,   368,
     263,   347,   289,     6,    -1,   100,   288,   377,   263,   368,
     289,     6,    -1,   377,   286,   360,     6,    -1,   377,   287,
       6,    -1,   377,   288,   289,   286,   360,     6,    -1,   377,
     288,   258,   363,   259,   289,   286,   360,     6,    -1,   377,
     256,   347,   257,   286,   347,     6,    -1,   377,   256,   347,
     257,   287,     6,    -1,   377,   254,   347,   255,   286,   347,
       6,    -1,   377,   254,   347,   255,   287,     6,    -1,   377,
       7,   368,     6,    -1,   377,   288,   289,     7,    49,   288,
     289,     6,    -1,   377,   288,   289,     7,    49,   288,   372,
     289,     6,    -1,   377,   288,   289,   230,    49,   288,   372,
     289,     6,    -1,   377,   260,   290,     7,   368,     6,    -1,
     377,   256,   347,   257,   260,   290,     7,   368,     6,    -1,
     377,   260,   290,   286,   347,     6,    -1,   377,   256,   347,
     257,   260,   290,   286,   347,     6,    -1,   377,   260,   290,
     287,     6,    -1,   377,   256,   347,   257,   260,   290,   287,
       6,    -1,   377,   260,   189,   260,   290,     7,   364,     6,
      -1,   377,   256,   347,   257,   260,   189,   260,   290,     7,
     364,     6,    -1,   377,   260,   190,     7,   365,     6,    -1,
     377,   256,   347,   257,   260,   190,     7,   365,     6,    -1,
     377,   200,     7,   360,     6,    -1,   200,   256,   347,   257,
       7,   290,     6,    -1,   200,   256,   347,   257,   260,   290,
       7,   347,     6,    -1,   200,   256,   347,   257,   260,   290,
       7,   368,     6,    -1,   200,   256,   347,   257,   260,   290,
       7,   258,   363,   259,     6,    -1,   200,   256,   347,   257,
     260,   290,     6,    -1,   143,   254,     4,   255,   260,   290,
       7,   347,     6,    -1,   143,   254,     4,   255,   260,   290,
       7,   368,     6,    -1,    -1,   263,    -1,    -1,   293,   292,
     377,    -1,   293,   292,   377,     7,   347,    -1,    -1,   293,
     292,   377,     7,   258,   360,   294,   299,   259,    -1,    -1,
     293,   292,   377,   288,   289,     7,   258,   360,   295,   299,
     259,    -1,   293,   292,   377,     7,   368,    -1,    -1,   293,
     292,   377,     7,   258,   368,   296,   303,   259,    -1,    -1,
     297,   292,   367,    -1,   347,     7,   368,    -1,   298,   263,
     347,     7,   368,    -1,   362,     7,   377,   254,   255,    -1,
      -1,   263,   301,    -1,    -1,   301,    -1,   302,    -1,   301,
     263,   302,    -1,     4,   360,    -1,    36,   347,    -1,    37,
     347,    -1,     4,    -1,     4,   258,   298,   259,    -1,     4,
     368,    -1,     4,   371,    -1,    -1,   263,   304,    -1,   305,
      -1,   304,   263,   305,    -1,     4,   347,    -1,     4,   368,
      -1,   204,   368,    -1,     4,   373,    -1,     4,   371,    -1,
     347,    -1,   368,    -1,   368,   263,   347,    -1,    -1,   192,
     105,   258,   347,   259,    -1,   142,   101,   258,   363,   259,
      -1,   142,   120,   258,   363,   259,    -1,    -1,   135,   357,
      -1,    -1,   142,   146,    -1,   101,   254,   347,   255,     7,
     357,     6,    -1,   104,   254,   347,   255,     7,   360,     6,
      -1,   108,   254,   347,   255,     7,   360,     6,    -1,   139,
     108,   254,   347,   255,     7,   360,   142,   347,     6,    -1,
     139,   184,   254,   347,   255,     7,   360,   142,   347,     6,
      -1,   102,   254,   347,   255,     7,   360,   308,     6,    -1,
     103,   254,   347,   255,     7,   360,   308,     6,    -1,   184,
     254,   347,   255,     7,   360,     6,    -1,   185,   254,   347,
     255,     7,   360,     6,    -1,   186,   254,   347,   255,     7,
     360,   188,   360,   187,   347,     6,    -1,   119,   254,   347,
     255,     7,   360,     6,    -1,   104,     4,   254,   347,   255,
       7,   360,     6,    -1,   135,   107,   254,   347,   255,     7,
     360,     6,    -1,   107,   254,   347,   255,     7,   360,   307,
       6,    -1,   136,   107,   254,   347,   255,     7,   360,   307,
       6,    -1,    13,    14,     6,    -1,    14,   107,   347,     6,
      -1,   123,   107,   254,   347,   255,     7,     5,     5,     5,
       6,    -1,   105,   254,   347,   255,     7,   360,     6,    -1,
     106,   254,   347,   255,     7,   360,     6,    -1,   110,   254,
     347,   255,     7,   360,     6,    -1,   113,   254,   347,   255,
       7,   360,     6,    -1,   117,   254,   347,   255,     7,   360,
       6,    -1,   118,   254,   347,   255,     7,   360,     6,    -1,
     111,   254,   347,   255,     7,   360,     6,    -1,   112,   254,
     347,   255,     7,   360,     6,    -1,   132,   254,   347,   255,
       7,   360,     6,    -1,   159,   254,   347,   255,     7,   360,
       6,    -1,   107,     4,   254,   347,   255,     7,   360,   309,
       6,    -1,   109,   254,   347,   255,     7,   360,     6,    -1,
     131,   254,   347,   255,     7,   360,     6,    -1,   136,   131,
     254,   347,   255,     7,   360,     6,    -1,   139,   313,   254,
     347,   255,     7,   360,     6,    -1,   139,   313,   254,   347,
     255,     7,   360,     4,   258,   359,   259,     6,    -1,    -1,
     138,   312,   311,   254,   306,   255,   286,   360,     6,    -1,
     101,    -1,   104,    -1,   107,    -1,   109,    -1,   120,   258,
     347,   259,    -1,   104,    -1,   107,    -1,   109,    -1,   120,
     258,   347,   259,    -1,   104,    -1,   107,    -1,   120,   258,
     347,   259,    -1,   101,    -1,   104,    -1,   107,    -1,   120,
     258,   347,   259,    -1,   148,   357,   258,   317,   259,    -1,
     147,   258,   357,   263,   357,   263,   347,   259,   258,   317,
     259,    -1,   149,   357,   258,   317,   259,    -1,   150,   258,
     357,   263,   347,   259,   258,   317,   259,    -1,   150,   258,
     357,   263,   357,   259,   258,   317,   259,    -1,   153,   258,
     363,   259,   258,   317,   259,    -1,     4,   258,   317,   259,
      -1,   165,   104,   258,   363,   259,   107,   258,   347,   259,
      -1,   162,   104,   258,   347,   259,   101,   258,   363,   259,
       6,    -1,   162,   104,   254,   347,   255,   258,   363,   259,
       6,    -1,   318,    -1,   316,    -1,    -1,   318,   310,    -1,
     318,   312,   258,   363,   259,     6,    -1,   318,   138,   312,
     258,   363,   259,     6,    -1,   318,   141,   312,   258,   363,
     259,     6,    -1,   318,   312,   258,     8,   259,     6,    -1,
     318,   138,   312,   258,     8,   259,     6,    -1,   152,   135,
     254,   347,   255,     7,   360,     6,    -1,   152,   101,   254,
     347,   255,     7,   258,   359,   259,     6,    -1,   152,   135,
     254,   347,   255,     7,   258,   357,   263,   357,   263,   363,
     259,     6,    -1,   152,   135,   254,   347,   255,     7,   258,
     357,   263,   357,   263,   357,   263,   363,   259,     6,    -1,
     152,   105,   254,   347,   255,     7,   258,   357,   263,   363,
     259,     6,    -1,   152,   111,   254,   347,   255,     7,   258,
     357,   263,   357,   263,   363,   259,     6,    -1,   152,   112,
     254,   347,   255,     7,   258,   357,   263,   357,   263,   363,
     259,     6,    -1,   152,   114,   254,   347,   255,     7,   258,
     357,   263,   357,   263,   363,   259,     6,    -1,   152,   115,
     254,   347,   255,     7,   258,   357,   263,   357,   263,   363,
     259,     6,    -1,   152,     4,   254,   347,   255,     7,   360,
       6,    -1,   152,     4,   254,   347,   255,     7,     5,     6,
      -1,   152,     4,   258,   347,   259,     6,    -1,   163,   258,
     318,   259,    -1,   145,   163,   258,   318,   259,    -1,   163,
       4,   258,   318,   259,    -1,   163,   200,   256,   347,   257,
       6,    -1,   163,     4,   256,   347,   257,     6,    -1,   163,
     377,     6,    -1,   163,     4,     4,     6,    -1,   163,    93,
       6,    -1,   189,   364,   258,   318,   259,    -1,   145,   189,
     364,   258,   318,   259,    -1,   224,   347,   258,   318,   259,
      -1,   205,   258,     8,   259,    -1,   205,     5,     6,    -1,
     206,   258,     8,   259,    -1,   206,     5,     6,    -1,   205,
     258,   318,   259,    -1,   145,   205,   258,   318,   259,    -1,
     206,   258,   318,   259,    -1,   145,   206,   258,   318,   259,
      -1,   377,   368,     6,    -1,    79,   254,   374,   255,     6,
      -1,   377,   377,   256,   347,   257,   367,     6,    -1,   377,
     377,   377,   256,   347,   257,     6,    -1,   377,   347,     6,
      -1,   143,   254,     4,   255,   260,     4,     6,    -1,   183,
       4,     6,    -1,   198,     6,    -1,   199,     6,    -1,    74,
       6,    -1,    75,     6,    -1,    67,     6,    -1,    67,   258,
     347,   263,   347,   263,   347,   263,   347,   263,   347,   263,
     347,   259,     6,    -1,    68,     6,    -1,    69,     6,    -1,
      84,     6,    -1,    86,   258,   347,   263,   347,   263,   347,
     259,     6,    -1,    86,   258,   347,   263,   347,   263,   347,
     263,   347,   259,     6,    -1,    85,     6,    -1,    87,     6,
      -1,    88,     6,    -1,   125,     6,    -1,   126,     6,    -1,
     127,   258,   363,   259,   258,   363,   259,   258,   359,   259,
     258,   347,   263,   347,   259,     6,    -1,   203,   254,   258,
     363,   259,   263,   368,   263,   368,   255,     6,    -1,   191,
     254,   347,     8,   347,   255,    -1,   191,   254,   347,     8,
     347,     8,   347,   255,    -1,   191,     4,   192,   258,   347,
       8,   347,   259,    -1,   191,     4,   192,   258,   347,     8,
     347,     8,   347,   259,    -1,   193,    -1,   204,     4,    -1,
     204,   368,    -1,   201,    -1,   202,   377,     6,    -1,   202,
     368,     6,    -1,   194,   254,   347,   255,    -1,   195,   254,
     347,   255,    -1,   196,    -1,   197,    -1,   151,   357,   258,
     318,   259,    -1,   151,   258,   357,   263,   357,   263,   347,
     259,   258,   318,   259,    -1,   151,   258,   357,   263,   357,
     263,   357,   263,   347,   259,   258,   318,   259,    -1,    -1,
     151,   357,   258,   318,   328,   332,   259,    -1,    -1,   151,
     258,   357,   263,   357,   263,   347,   259,   258,   318,   329,
     332,   259,    -1,    -1,   151,   258,   357,   263,   357,   263,
     357,   263,   347,   259,   258,   318,   330,   332,   259,    -1,
      -1,   151,   258,   318,   331,   332,   259,    -1,   151,   258,
     318,   259,   142,   119,   258,   347,   259,    -1,   131,   360,
      -1,   136,   131,   360,    -1,   133,   258,   363,   259,   258,
     363,   259,   258,   363,   259,    -1,   134,   258,   363,   259,
     258,   363,   259,   258,   363,   259,   258,   363,   259,    -1,
     333,    -1,   332,   333,    -1,   169,   258,   347,   259,     6,
      -1,   169,   258,   360,   263,   360,   259,     6,    -1,   170,
       6,    -1,   160,     6,    -1,   160,   347,     6,    -1,   175,
       6,    -1,   175,   177,     6,    -1,   176,     6,    -1,   176,
     177,     6,    -1,   171,   254,   347,   255,     7,   360,   142,
     347,     6,    -1,   142,     4,   256,   347,   257,     6,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   158,    -1,
      -1,   163,     6,    -1,   145,   163,     6,    -1,   163,   347,
       6,    -1,   145,   163,   347,     6,    -1,   334,   258,   318,
     335,   259,   258,   318,   335,   259,    -1,   116,   254,   367,
     255,    -1,   334,   254,   347,   255,     7,   258,   318,   335,
     259,   258,   318,   335,   259,     6,    -1,    -1,   142,     4,
     347,    -1,    -1,     4,    -1,    -1,     7,   360,    -1,    -1,
       7,   347,    -1,    -1,   153,   360,    -1,   121,   122,   361,
       7,   347,     6,    -1,   137,   104,   361,     7,   347,   338,
       6,    -1,   137,   107,   361,   340,   339,     6,    -1,   137,
     109,   361,   340,     6,    -1,   178,   361,     6,    -1,    99,
     101,   254,   347,   263,   347,   255,     6,    -1,    99,   104,
     254,   347,   263,   347,   255,     6,    -1,    99,   107,   254,
     347,   263,   347,   255,     6,    -1,    99,   109,   254,   347,
     263,   347,   255,     6,    -1,   166,   107,   258,   363,   259,
       7,   347,     6,    -1,   168,   107,   258,   363,   259,     7,
     347,     6,    -1,   160,   107,   361,   341,     6,    -1,   160,
     109,   361,     6,    -1,   161,   107,   361,     7,   347,     6,
      -1,   140,   104,   258,   363,   259,     7,   258,   363,   259,
     342,     6,    -1,   140,   107,   258,   363,   259,     7,   258,
     363,   259,   342,     6,    -1,   140,   104,   258,   363,   259,
       7,   258,   363,   259,   147,   258,   357,   263,   357,   263,
     347,   259,     6,    -1,   140,   107,   258,   363,   259,     7,
     258,   363,   259,   147,   258,   357,   263,   357,   263,   347,
     259,     6,    -1,   140,   104,   258,   363,   259,     7,   258,
     363,   259,   148,   357,     6,    -1,   140,   107,   258,   363,
     259,     7,   258,   363,   259,   148,   357,     6,    -1,   140,
     107,   347,   258,   363,   259,     7,   347,   258,   363,   259,
       6,    -1,   312,   258,   363,   259,   192,   312,   258,   347,
     259,     6,    -1,   167,   314,   361,     6,    -1,   128,   315,
     361,     6,    -1,   129,   109,   360,     6,    -1,   144,   104,
     360,     6,    -1,   139,   313,   360,     6,    -1,   164,     6,
      -1,   164,     4,     6,    -1,   164,   101,   258,   363,   259,
       6,    -1,   213,    -1,   214,    -1,   215,    -1,   345,     6,
      -1,   345,   258,   360,   259,     6,    -1,   345,   258,   360,
     263,   360,   259,     6,    -1,   345,   254,   360,   255,   258,
     360,   263,   360,   259,     6,    -1,   348,    -1,   254,   347,
     255,    -1,   243,   347,    -1,   242,   347,    -1,   249,   347,
      -1,   347,   243,   347,    -1,   347,   242,   347,    -1,   347,
     244,   347,    -1,   347,   245,   347,    -1,   347,   247,   347,
      -1,   347,   248,   347,    -1,   347,   246,   347,    -1,   347,
     253,   347,    -1,   347,   236,   347,    -1,   347,   237,   347,
      -1,   347,   241,   347,    -1,   347,   240,   347,    -1,   347,
     235,   347,    -1,   347,   234,   347,    -1,   347,   233,   347,
      -1,   347,   232,   347,    -1,   347,   238,   347,    -1,   347,
     239,   347,    -1,   347,   231,   347,     8,   347,    -1,    16,
     288,   347,   289,    -1,    17,   288,   347,   289,    -1,    18,
     288,   347,   289,    -1,    19,   288,   347,   289,    -1,    20,
     288,   347,   289,    -1,    21,   288,   347,   289,    -1,    22,
     288,   347,   289,    -1,    23,   288,   347,   289,    -1,    24,
     288,   347,   289,    -1,    26,   288,   347,   289,    -1,    27,
     288,   347,   263,   347,   289,    -1,    28,   288,   347,   289,
      -1,    29,   288,   347,   289,    -1,    30,   288,   347,   289,
      -1,    31,   288,   347,   289,    -1,    32,   288,   347,   289,
      -1,    33,   288,   347,   289,    -1,    34,   288,   347,   289,
      -1,    35,   288,   347,   289,    -1,    38,   288,   347,   263,
     347,   289,    -1,    39,   288,   347,   263,   347,   289,    -1,
      40,   288,   347,   263,   347,   289,    -1,    25,   288,   347,
     289,    -1,    37,   288,   347,   263,   347,   289,    -1,    36,
     288,   347,   263,   347,   289,    -1,     3,    -1,    10,    -1,
      15,    -1,    11,    -1,    12,    -1,   220,    -1,   221,    -1,
     222,    -1,    81,    -1,    82,    -1,    83,    -1,    -1,    92,
     288,   347,   349,   299,   289,    -1,   352,    -1,   211,   288,
     367,   289,    -1,   211,   288,   367,   263,   347,   289,    -1,
     354,    -1,   377,   256,   347,   257,    -1,   377,   254,   347,
     255,    -1,   216,   254,   354,   255,    -1,   216,   254,   354,
     260,   290,   255,    -1,   218,   254,   354,   350,   255,    -1,
     218,   254,   354,   260,   290,   350,   255,    -1,   218,   254,
     354,   288,   347,   289,   350,   255,    -1,   218,   254,   354,
     260,   290,   288,   347,   289,   350,   255,    -1,   217,   254,
     368,   255,    -1,   261,   377,   288,   289,    -1,   261,   354,
     260,   290,   288,   289,    -1,    95,   288,   377,   289,    -1,
      95,   288,   289,    -1,   377,   287,    -1,   377,   256,   347,
     257,   287,    -1,   377,   254,   347,   255,   287,    -1,   377,
     260,   290,    -1,   377,     9,   377,   260,   290,    -1,   377,
     260,   290,   254,   347,   255,    -1,   377,     9,   377,   260,
     290,   254,   347,   255,    -1,   377,   260,   290,   256,   347,
     257,    -1,   377,     9,   377,   260,   290,   256,   347,   257,
      -1,   377,   256,   347,   257,   260,   290,    -1,   377,   260,
     290,   287,    -1,   377,   256,   347,   257,   260,   290,   287,
      -1,   207,   254,   367,   263,   347,   255,    -1,    59,   254,
     360,   263,   360,   255,    -1,    60,   288,   367,   263,   367,
     289,    -1,    58,   288,   367,   289,    -1,    61,   288,   367,
     263,   367,   289,    -1,    66,   254,   374,   255,    -1,    -1,
     263,   347,    -1,    -1,   263,   367,    -1,    -1,    93,   354,
     356,   353,   256,   300,   257,    -1,   377,    -1,   377,     9,
     377,    -1,    96,    -1,    96,   347,    -1,    -1,   254,   355,
     255,    -1,   358,    -1,   243,   357,    -1,   242,   357,    -1,
     357,   243,   357,    -1,   357,   242,   357,    -1,   258,   347,
     263,   347,   263,   347,   263,   347,   263,   347,   259,    -1,
     258,   347,   263,   347,   263,   347,   263,   347,   259,    -1,
     258,   347,   263,   347,   263,   347,   259,    -1,   254,   347,
     263,   347,   263,   347,   255,    -1,   360,    -1,   359,   263,
     360,    -1,   347,    -1,   362,    -1,   258,   259,    -1,   258,
     363,   259,    -1,   243,   258,   363,   259,    -1,   347,   244,
     258,   363,   259,    -1,   360,    -1,   258,     8,   259,    -1,
       5,    -1,   243,   362,    -1,   347,   244,   362,    -1,   347,
       8,   347,    -1,   347,     8,   347,     8,   347,    -1,   101,
     258,   347,   259,    -1,   101,   258,     8,   259,    -1,   101,
       5,    -1,   313,   258,     8,   259,    -1,   313,     5,    -1,
     138,   312,   361,    -1,   141,   312,   360,    -1,   312,   192,
      67,   360,    -1,    67,   312,   258,   363,   259,    -1,    76,
     313,   258,   347,   259,    -1,    77,   313,   258,   347,   259,
      -1,   316,    -1,   327,    -1,   336,    -1,   377,   288,   289,
      -1,   377,   260,   290,   288,   289,    -1,   377,     9,   377,
     260,   290,   288,   289,    -1,    41,   256,   377,   257,    -1,
      41,   256,   362,   257,    -1,    41,   254,   362,   255,    -1,
      41,   288,   258,   363,   259,   289,    -1,   377,   288,   258,
     363,   259,   289,    -1,    42,   288,   347,   263,   347,   263,
     347,   289,    -1,    43,   288,   347,   263,   347,   263,   347,
     289,    -1,    44,   288,   367,   289,    -1,    45,   288,   347,
     263,   347,   263,   347,   263,   347,   263,   347,   263,   347,
     289,    -1,   212,   288,   362,   289,    -1,    32,   288,   362,
     289,    -1,   347,    -1,   362,    -1,   363,   263,   347,    -1,
     363,   263,   362,    -1,   258,   347,   263,   347,   263,   347,
     263,   347,   259,    -1,   258,   347,   263,   347,   263,   347,
     259,    -1,   377,    -1,     4,   260,   189,   260,     4,    -1,
     258,   366,   259,    -1,   377,   256,   347,   257,   260,   190,
      -1,   364,    -1,   366,   263,   364,    -1,   368,    -1,   377,
      -1,   377,   256,   347,   257,    -1,   377,   254,   347,   255,
      -1,   377,   260,   290,    -1,   377,     9,   377,   260,   290,
      -1,   377,   260,   290,   254,   347,   255,    -1,   377,     9,
     377,   260,   290,   254,   347,   255,    -1,   377,   256,   347,
     257,   260,     4,    -1,   312,   258,   347,   259,    -1,   138,
     312,   258,   347,   259,    -1,     5,    -1,   225,   256,   377,
     257,    -1,    70,    -1,   223,    -1,    78,    -1,    80,    -1,
     209,   254,   367,   255,    -1,   208,   254,   367,   263,   367,
     255,    -1,   210,   288,   367,   289,    -1,   210,   288,   367,
     263,   367,   289,    -1,   219,   254,   354,   351,   255,    -1,
     219,   254,   354,   260,   290,   351,   255,    -1,    51,   288,
     374,   289,    -1,    52,   254,   367,   255,    -1,    53,   254,
     367,   255,    -1,    54,   254,   367,   263,   367,   263,   367,
     255,    -1,    49,   288,   374,   289,    -1,    63,   288,   367,
     289,    -1,    64,   288,   367,   289,    -1,    65,   288,   367,
     289,    -1,    62,   288,   347,   263,   367,   263,   367,   289,
      -1,    57,   288,   367,   263,   347,   263,   347,   289,    -1,
      57,   288,   367,   263,   347,   289,    -1,    50,   288,   367,
     289,    -1,    50,   288,   367,   263,   363,   289,    -1,    71,
     288,   367,   289,    -1,    72,    -1,    73,    -1,    56,   288,
     367,   289,    -1,    55,   288,   367,   289,    -1,    -1,    97,
     288,   368,   369,   303,   289,    -1,    94,   288,   370,   289,
      -1,   261,   347,    -1,   377,     9,   261,   347,    -1,    49,
     288,   373,   289,    -1,   374,    -1,   373,    -1,   258,   374,
     259,    -1,   367,    -1,   375,    -1,   374,   263,   367,    -1,
     374,   263,   375,    -1,   377,   254,   255,    -1,   377,   260,
     290,   254,   255,    -1,   377,     9,   377,   260,   290,   254,
     255,    -1,     4,   262,   258,   347,   259,    -1,   376,   262,
     258,   347,   259,    -1,   226,   256,   367,   257,   262,   258,
     347,   259,    -1,     4,    -1,   376,    -1,   226,   256,   367,
     257,    -1
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
    4411,  4433,  4474,  4518,  4557,  4582,  4594,  4606,  4618,  4630,
    4647,  4664,  4694,  4720,  4746,  4778,  4805,  4831,  4857,  4883,
    4909,  4931,  4942,  4990,  5044,  5059,  5071,  5082,  5089,  5104,
    5118,  5119,  5120,  5124,  5130,  5142,  5160,  5188,  5189,  5190,
    5191,  5192,  5193,  5194,  5195,  5196,  5203,  5204,  5205,  5206,
    5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,
    5217,  5218,  5219,  5220,  5221,  5222,  5223,  5224,  5225,  5226,
    5227,  5228,  5229,  5230,  5231,  5232,  5233,  5234,  5235,  5236,
    5237,  5238,  5239,  5240,  5241,  5242,  5251,  5252,  5253,  5254,
    5255,  5256,  5257,  5258,  5259,  5260,  5261,  5266,  5265,  5273,
    5275,  5280,  5285,  5289,  5294,  5299,  5303,  5307,  5311,  5315,
    5319,  5323,  5329,  5344,  5348,  5354,  5359,  5378,  5398,  5419,
    5423,  5427,  5431,  5435,  5439,  5443,  5448,  5458,  5468,  5473,
    5484,  5493,  5498,  5503,  5531,  5532,  5538,  5539,  5545,  5544,
    5567,  5569,  5574,  5576,  5582,  5583,  5588,  5592,  5596,  5600,
    5604,  5611,  5615,  5619,  5623,  5630,  5635,  5642,  5647,  5651,
    5656,  5660,  5668,  5679,  5683,  5687,  5701,  5709,  5717,  5724,
    5734,  5757,  5762,  5768,  5773,  5779,  5790,  5796,  5810,  5816,
    5828,  5842,  5852,  5862,  5872,  5884,  5888,  5893,  5905,  5909,
    5913,  5917,  5935,  5943,  5951,  5980,  5990,  6006,  6017,  6022,
    6026,  6030,  6042,  6046,  6058,  6075,  6085,  6089,  6104,  6109,
    6116,  6120,  6125,  6139,  6153,  6157,  6161,  6165,  6169,  6177,
    6183,  6192,  6196,  6200,  6208,  6214,  6220,  6224,  6231,  6239,
    6246,  6255,  6259,  6263,  6278,  6292,  6306,  6318,  6334,  6343,
    6352,  6362,  6373,  6381,  6389,  6393,  6412,  6419,  6425,  6431,
    6438,  6446,  6445,  6455,  6479,  6481,  6487,  6492,  6494,  6499,
    6504,  6509,  6511,  6515,  6527,  6541,  6545,  6552,  6560,  6568,
    6579,  6581,  6584
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
  "tHomology", "tCohomology", "tBetti", "tExists", "tFileExists",
  "tGetForced", "tGetForcedStr", "tGMSH_MAJOR_VERSION",
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
     485,    63,   486,   487,   488,   489,    60,    62,   490,   491,
     492,   493,    43,    45,    42,    47,    37,   124,    38,    33,
     494,   495,   496,    94,    40,    41,    91,    93,   123,   125,
      46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   264,   265,   265,   266,   266,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   268,   268,   269,   269,
     269,   269,   269,   269,   269,   269,   270,   270,   270,   270,
     271,   271,   271,   271,   271,   271,   271,   272,   272,   273,
     273,   275,   276,   274,   277,   277,   279,   278,   280,   280,
     282,   281,   283,   283,   285,   284,   286,   286,   286,   286,
     286,   287,   287,   288,   288,   289,   289,   290,   290,   290,
     290,   290,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   292,   292,   293,
     293,   293,   294,   293,   295,   293,   293,   296,   293,   297,
     297,   298,   298,   298,   299,   299,   300,   300,   301,   301,
     302,   302,   302,   302,   302,   302,   302,   303,   303,   304,
     304,   305,   305,   305,   305,   305,   306,   306,   306,   307,
     307,   307,   307,   308,   308,   309,   309,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   311,   310,   312,   312,   312,   312,   312,   313,   313,
     313,   313,   314,   314,   314,   315,   315,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   317,
     317,   318,   318,   318,   318,   318,   318,   318,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   321,
     322,   323,   323,   323,   323,   323,   323,   323,   323,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   325,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   327,   327,
     327,   328,   327,   329,   327,   330,   327,   331,   327,   327,
     327,   327,   327,   327,   332,   332,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   334,   334,   334,
     334,   334,   335,   335,   335,   335,   335,   336,   336,   337,
     338,   338,   339,   339,   340,   340,   341,   341,   342,   342,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   344,   344,   344,
     345,   345,   345,   346,   346,   346,   346,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   349,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   350,   350,   351,   351,   353,   352,
     354,   354,   355,   355,   356,   356,   357,   357,   357,   357,
     357,   358,   358,   358,   358,   359,   359,   360,   360,   360,
     360,   360,   360,   361,   361,   361,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   363,   363,
     363,   363,   364,   364,   364,   364,   365,   365,   366,   366,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   369,   368,   368,   370,   370,   371,   372,   372,   373,
     374,   374,   374,   374,   375,   375,   375,   376,   376,   376,
     377,   377,   377
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
       6,     7,     6,     5,     3,     8,     8,     8,     8,     8,
       8,     5,     4,     6,    11,    11,    18,    18,    12,    12,
      12,    10,     4,     4,     4,     4,     4,     2,     3,     6,
       1,     1,     1,     2,     5,     7,    10,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     6,     4,     6,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     5,     7,     8,
      10,     4,     4,     6,     4,     3,     2,     5,     5,     3,
       5,     6,     8,     6,     8,     6,     4,     7,     6,     6,
       6,     4,     6,     4,     0,     2,     0,     2,     0,     7,
       1,     3,     1,     2,     0,     3,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     3,     1,     2,     3,     3,     5,
       4,     4,     2,     4,     2,     3,     3,     4,     5,     5,
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
       0,     0,     0,     2,     3,     1,   630,     0,     0,     0,
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
       0,     0,     0,     0,   390,   391,   392,     0,     0,     5,
       6,     7,     8,    10,     0,    11,    24,    12,    13,    14,
      15,    23,    22,    21,    16,     0,    17,    18,    19,    20,
       0,    25,     0,   631,     0,   231,     0,     0,     0,     0,
       0,     0,   280,     0,   282,   283,   278,   279,     0,   284,
     287,     0,   288,   289,   119,   129,   630,   504,   500,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
     291,     0,   215,   216,   217,     0,     0,     0,     0,   446,
     447,   449,   450,   448,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   454,   455,   456,     0,     0,   203,   208,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   451,   452,   453,     0,     0,     0,     0,     0,
       0,     0,     0,   541,   542,     0,   543,   517,   397,   459,
     462,   320,   518,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,   204,   205,   206,   201,   208,   209,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   630,     0,
       0,   231,     0,     0,   387,     0,     0,     0,   212,   213,
       0,     0,     0,     0,     0,     0,   525,     0,     0,   523,
       0,     0,     0,     0,     0,   630,     0,     0,   564,     0,
       0,     0,     0,   276,   277,     0,   581,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     583,     0,   607,   608,   585,   586,     0,     0,     0,     0,
       0,     0,   584,     0,     0,     0,     0,   299,   300,     0,
     231,     0,   231,     0,     0,     0,   500,     0,     0,     0,
     231,   393,     0,     0,    84,     0,    66,     0,     0,    70,
      69,    68,    67,    72,    71,    73,    74,     0,     0,     0,
       0,     0,     0,     0,   570,   500,     0,   230,     0,   229,
       0,   182,     0,     0,   570,   571,     0,     0,     0,   620,
       0,   621,   571,     0,   117,   117,     0,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,   559,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,   399,   526,   401,     0,   519,     0,     0,   500,     0,
     534,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,   476,     0,     0,     0,
       0,     0,     0,     0,   321,     0,   354,   354,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
       0,   231,   231,     0,   508,   507,     0,     0,     0,     0,
     231,   231,     0,     0,     0,     0,   317,     0,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     356,     0,     0,     0,     0,     0,     0,   231,   257,     0,
       0,   255,   388,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   364,   275,     0,     0,     0,     0,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   302,
       0,   262,     0,     0,   264,     0,     0,     0,   399,     0,
     231,     0,     0,     0,     0,     0,     0,     0,   342,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,     0,     0,     0,     0,    88,    75,    76,     0,
       0,     0,   273,    40,   269,     0,     0,     0,     0,     0,
     225,     0,     0,     0,     0,     0,   232,     0,     0,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
       0,     0,   502,     0,     0,   501,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   348,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,   383,   384,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     500,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,   475,     0,     0,     0,     0,
     535,   536,     0,     0,     0,     0,     0,   494,     0,   398,
     520,     0,     0,     0,     0,   528,     0,   417,   416,   415,
     414,   410,   411,   418,   419,   413,   412,   403,   402,     0,
     404,   527,   405,   408,   406,   407,   409,   501,     0,     0,
     479,     0,   544,     0,     0,     0,     0,     0,     0,     0,
       0,   352,     0,     0,     0,     0,     0,     0,   386,     0,
       0,     0,     0,   385,     0,   231,     0,     0,     0,     0,
       0,   510,   509,     0,     0,     0,     0,     0,     0,     0,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   372,     0,     0,     0,   256,     0,
       0,     0,   250,     0,     0,     0,     0,   382,     0,     0,
       0,     0,   398,   524,     0,     0,     0,     0,     0,     0,
       0,     0,   304,   305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   611,     0,     0,     0,   496,     0,     0,   261,
     265,   263,   267,     0,   404,     0,   501,   479,   632,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,     0,
       0,   398,     0,     0,     0,    66,     0,     0,    87,     0,
      66,    67,     0,     0,     0,   501,     0,     0,   479,     0,
       0,     0,   201,     0,     0,     0,   627,    28,    26,    27,
       0,     0,     0,     0,     0,   574,    30,     0,    29,     0,
       0,   270,   622,   623,     0,   624,   574,     0,    82,   120,
      83,   130,   503,   505,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   560,   561,   218,     9,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   443,   430,     0,   432,   433,
     434,   435,   436,   557,   437,   438,   439,     0,     0,     0,
       0,     0,   549,   548,   547,     0,     0,     0,   554,     0,
     491,     0,     0,     0,   493,     0,     0,     0,   134,   474,
     531,   530,   211,     0,     0,   460,   556,   465,     0,   471,
       0,     0,     0,     0,   521,     0,     0,   472,   537,   533,
       0,     0,     0,     0,   464,   463,    73,    74,   486,     0,
       0,     0,     0,     0,     0,     0,   398,   350,   355,   353,
       0,   363,     0,   156,   157,     0,   211,     0,   398,     0,
       0,     0,     0,   251,     0,   266,   268,     0,     0,     0,
     219,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,     0,   308,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   231,     0,   357,   371,
       0,     0,     0,     0,   252,     0,     0,     0,     0,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,     0,     0,     0,   597,     0,   604,   593,   594,   595,
       0,   610,   609,     0,     0,   598,   599,   600,   606,   614,
     613,     0,   147,     0,   587,     0,   589,     0,     0,     0,
     582,     0,   260,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,   394,     0,   628,     0,   109,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,   579,    51,     0,     0,
       0,    64,     0,    41,    42,    43,    44,    45,    46,     0,
     464,   463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   573,   572,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   137,
     138,     0,     0,     0,     0,     0,     0,     0,   163,   163,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   538,   539,   540,     0,     0,     0,     0,     0,   494,
     495,     0,   467,     0,     0,   529,   420,   522,   480,   478,
       0,   477,     0,     0,   545,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   362,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,   259,     0,     0,     0,     0,
       0,     0,     0,   329,     0,     0,   328,     0,   331,     0,
     333,     0,   318,   325,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   373,     0,     0,
     254,   253,   389,     0,     0,     0,    37,    38,     0,     0,
       0,     0,   565,     0,     0,     0,   294,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   496,   497,
     591,     0,   480,     0,     0,   231,   344,     0,   345,   231,
       0,     0,   580,     0,    94,     0,     0,     0,     0,    92,
       0,   568,     0,   107,     0,    99,   101,     0,     0,     0,
      89,     0,     0,     0,     0,     0,    36,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,   575,     0,     0,    34,    33,     0,   575,
     625,     0,     0,   121,   126,     0,     0,     0,   140,   145,
     146,   141,   142,   499,     0,    85,     0,     0,     0,     0,
      86,   167,     0,     0,     0,     0,   168,   185,   186,   165,
       0,     0,     0,   169,   196,   187,   191,   192,   188,   189,
     190,   177,     0,     0,   431,   445,   444,   440,   441,   442,
     550,     0,     0,     0,   489,   490,   492,   135,   458,   488,
     461,   466,     0,     0,   494,   197,   473,    73,    74,     0,
     485,   481,   483,   551,   193,     0,     0,     0,   159,     0,
       0,   361,     0,   158,     0,     0,     0,     0,     0,     0,
     274,     0,     0,     0,     0,   231,   231,     0,     0,   330,
     517,     0,     0,   332,   334,     0,     0,   312,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   224,   194,
       0,     0,     0,     0,     0,     0,   174,   175,     0,     0,
       0,     0,   110,   114,     0,   605,     0,     0,   603,     0,
     615,     0,     0,   148,   149,   612,   588,   590,     0,     0,
       0,     0,     0,     0,   342,   346,   342,     0,   395,    93,
       0,     0,    66,     0,     0,    91,     0,   566,     0,     0,
       0,     0,     0,     0,   618,   617,     0,     0,     0,     0,
       0,   515,     0,     0,    77,   271,   481,   272,     0,     0,
       0,     0,     0,   236,   233,     0,     0,   578,   576,     0,
       0,     0,     0,   122,   127,     0,     0,     0,   558,   559,
     139,   365,   366,   367,   368,   164,   172,   173,   178,     0,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,   468,     0,     0,     0,   546,   487,     0,     0,   179,
       0,   198,   351,     0,     0,     0,     0,   199,     0,     0,
       0,     0,     0,     0,   514,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
     369,   370,    39,     0,   563,     0,     0,   296,   295,     0,
       0,     0,     0,     0,     0,   151,   152,   155,   154,   153,
       0,   592,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,   569,     0,     0,     0,    96,     0,
       0,     0,    47,     0,     0,     0,     0,     0,    49,     0,
     237,   234,   235,    35,     0,     0,   626,   285,     0,   134,
     147,     0,     0,   144,     0,     0,     0,   166,   195,     0,
       0,     0,     0,     0,   552,   553,     0,   494,   469,   482,
     484,     0,     0,   181,   202,     0,     0,     0,   358,   358,
       0,   115,   116,   231,     0,   222,   223,   319,     0,   326,
       0,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,   228,     0,   226,     0,     0,     0,     0,   111,   112,
     596,   602,   601,   150,     0,     0,     0,   347,     0,     0,
     108,   100,   102,     0,    90,   619,    97,    98,    52,     0,
       0,     0,     0,   516,     0,     0,   482,   577,     0,     0,
       0,     0,   124,   616,     0,   131,     0,     0,     0,     0,
     184,     0,     0,     0,   322,     0,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   512,     0,
     336,     0,     0,   313,     0,   239,     0,     0,     0,     0,
       0,     0,   227,     0,   562,   297,     0,     0,   381,   231,
     396,     0,   567,     0,    48,     0,     0,     0,    65,    50,
       0,   286,   123,   128,   134,     0,     0,   161,   162,   160,
       0,     0,   470,     0,     0,     0,     0,   359,   374,     0,
       0,   375,     0,   220,     0,   327,     0,   309,     0,   231,
       0,     0,     0,     0,     0,     0,   176,   113,   293,   342,
     106,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,   200,     0,   378,     0,   379,   380,   511,     0,
       0,   315,   242,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    62,     0,     0,   125,     0,     0,   323,
       0,     0,   335,   314,   310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   243,   244,   245,   246,     0,   240,   349,
      53,     0,    60,     0,   281,     0,   555,     0,     0,   316,
       0,     0,    54,     0,     0,   292,     0,     0,   241,     0,
       0,     0,     0,     0,     0,    57,    55,     0,    58,     0,
     376,   377,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   119,  1090,   120,   121,  1074,  1941,  1947,
    1373,  1591,  2103,  2231,  1374,  2204,  2247,  1375,  2233,  1376,
    1377,  1595,   448,   606,   607,  1162,  1690,   122,   799,   474,
    1959,  2114,  1960,   475,  1827,  1455,  1408,  1409,  1410,  1555,
    1763,  1764,  1232,  1652,  1643,  1840,   776,   618,   281,   282,
     361,   206,   283,   458,   459,   126,   127,   128,   129,   130,
     131,   132,   133,   284,  1266,  2138,  2195,   968,  1262,  1263,
     285,  1053,   286,   137,  1483,  1230,   941,   983,  2072,   138,
     139,   140,   141,   287,   288,  1188,  1203,  1329,   289,   804,
     290,   803,   477,   635,   329,  1800,   369,   370,   292,   576,
     377,  1357,  1582,   469,   464,  1322,  1030,  1630,  1793,  1794,
    1015,   471,   143,   426
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1918
static const yytype_int16 yypact[] =
{
   12974,    44,    66, 13177, -1918, -1918,   182,   100,    -7,   -63,
     -53,    -2,    27,   146,   260,   308,   314,    54,   350,   372,
     -47,   403,   445,     4,   209,    56,   298,   745,   298,   208,
     222,   235,    10,   268,   275,    51,   295,   312,   338,   348,
     355,   461,   475,   486,   494,   512,   324,   412,   401,   712,
     779,   374,   667,   704,   543,  6678,   562,   411,   564,   752,
     -43,   327,   663,   -15,   106,   588,   762,   -85,   616,   386,
     386,   647,   392,    53,   653, -1918, -1918, -1918, -1918, -1918,
     672,   466,   786,   790,    45,    55,   814,   828,   240,   844,
     918,   953,   968,  5670,   997,   758,   763,   771,    32,    52,
   -1918,   795,   817, -1918, -1918,   996,  1030,   818, -1918, 13422,
     821, 13458,    25,    30, -1918, -1918, -1918, 11722,   822, -1918,
   -1918, -1918, -1918, -1918,   784, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918, -1918, -1918, -1918,  -131, -1918, -1918, -1918, -1918,
     101, -1918,  1074,   824,  4825,   477,   825,  1078, 11722, 13360,
   13360, 13360, -1918, 11722, -1918, -1918, -1918, -1918, 13360, -1918,
   -1918, 11722, -1918, -1918, -1918, -1918,   826,   831,  1080, -1918,
   -1918, 13494,   836,   839,   840,   843,    56, 11722, 11722, 11722,
     845, 11722, 11722, 11722,   846, 11722, 11722, 11722, 11722, 11722,
   11722, 11722, 13360, 11722, 11722, 11722, 11722,  5670,   847, -1918,
   -1918,  9440, -1918, -1918, -1918,   848,  5670,  6930, 13360, -1918,
   -1918, -1918, -1918, -1918,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   507,
     298,   298,   298,   298,   298,   849,   298,   298,   850,   663,
     640,   640, -1918, -1918, -1918,   298,   298,    36,   910,   913,
     916,   852,  6930,   980,   663,   663,   858,   298,   298,   859,
     860,   861, -1918, -1918, -1918, 11722,  7182, 11722, 11722,  7434,
      56,   924,    42, -1918, -1918,   867, -1918,  5606, -1918, -1918,
   -1918, -1918, -1918,   110, 11722,  9440,  9440,   863,   864,  7686,
    5670,  5670,  5670, -1918, -1918, -1918, -1918, -1918, -1918, -1918,
     882, -1918,   879,   885,  7938,   891,  4463,  1146,  6930,   893,
      32,   894,   899,   386,   386,   386, 11722, 11722,   533, -1918,
     560,   386, 10376,   563,   236,   904,   905,   906,   911,   912,
     914,   919,  9440, 11722,  5670,  5670,  5670,   249,    16,  1161,
     920, -1918,  1164,  1166, -1918,   917,   923,   925, -1918, -1918,
     926,  5670,   928,   921,   931,   933, -1918, 11722,  5922, -1918,
    1168,  1176, 11722, 11722, 11722,   598, 11722,   932, -1918,   999,
   11722, 11722, 11722, -1918, -1918, 11722, -1918,   298,   298,   298,
     939,   940,   942,   298,   298,   298,   298,   298,   298,   298,
   -1918,   298, -1918, -1918, -1918, -1918,   298,   298,   943,   945,
     298,   947, -1918,   948,  1197,  1201,   950, -1918, -1918,  1203,
    1202,  1206,  1205,   298, 11722, 15114,   181, 13360,  9440, 11722,
   -1918, -1918,  6930,  6930, -1918,   956, 13494,   663,  1208, -1918,
   -1918, -1918, -1918, -1918, -1918, 11722, 11722,   487,  6930,  1210,
     435,   959,  1870,   963,  1216,    76,   965, -1918,   966, 11109,
   11722, -1918,  2115,  -218, -1918,   125,  -153,  -137,  8377, -1918,
     -89, -1918,   126,  8624,   -77,   -51,  1128, -1918,    56,   964,
   11722, 11722, 11722, 11722,   967, 15630, 15655, 15680, 11722, 15705,
   15730, 15755, 11722, 15780, 15805, 15830, 15855, 15880, 15905, 15930,
     971, 15955, 15980, 16005, 14215,  1221, 11722,  9440,  5857, -1918,
     328, 11722,  1225,  1226,   978, 11722, 11722, 11722, 11722, 11722,
   11722, 11722, 11722, 11722, 11722, 11722, 11722, 11722, 11722, 11722,
   11722,  9440, 11722, 11722, 11722, 11722, 11722, 11722, 11722, 11722,
    9440,  9440,   976, 11722, 11722, 13360, 11722, 13360,  6930, 13360,
   13360, 13360,   977,   979,   981, 11722,    78, -1918, 10462, 11722,
    6930,  5670,  6930, 13360, 13360,  9440,    56, 13494,    56,   983,
    9440,   983, -1918,   983, 16030, -1918,   360,   984,   115,  1171,
   -1918,  1232, 11722, 11722, 11722, 11722, 11722, 11722, 11722, 11722,
   11722, 11722, 11722, 11722, 11722, 11722,  8190, 11722, 11722, 11722,
   11722, 11722,    56, 11722, 11722,    39, -1918,   815, 16055,   384,
     415, 11722, 11722, 11722, -1918,  1234,  1238,  1238,   993, 11722,
   11722, 11722, 11722,  1242,  9440,  9440, 15142,   994,  1245, -1918,
     995, -1918, -1918,  -134, -1918, -1918,  8871,  9123,   386,   386,
     477,   477,  -130, 10376, 10376, 11722,  3632,  -100, -1918, 11722,
   11722, 11722, 11722, 11722, 11722, 11722, 11722, 11722,   464, 16080,
    1247,  1246,  1248, 11722, 11722,  1250, 11722, -1918, -1918, 11722,
   11997, -1918, -1918,  9440,  9440,  9440, 11722,  1253,  9440, 11722,
   11722, 11722, 16105,  1002, -1918, -1918, 16130, 16155, 16180,  1076,
    9375, -1918,  1008,  6109, 16205, 16230, 15225, 13360, 13360, 13360,
   13360, 13360, 13360, 13360, 13360, 13360, 11722, 13360, 13360, 13360,
   13360,    23, 13494, 13360, 13360, 13360,    56,    56, -1918, -1918,
    9440, -1918,  1009, 12083, -1918,  1010, 12184, 11722,   983, 11722,
   -1918,    56, 11722, 11722,    39,  1013,   514, 16255, 10769,  1012,
     529, 11722,  1265,  1014,  6930, 16280, 15252, -1918, -1918, -1918,
   -1918, -1918,  1015,  1266,   175,  1271, -1918, -1918, -1918,  9440,
     376, 11722, -1918, -1918, -1918,    56, 11722, 11722,    39,  1022,
   -1918,  1025,   -16,   663,   -15,   663, -1918,  1023, 14244, -1918,
      13,  9440,    56, 11722, 11722,    39,  1274,  9440,  1276,  9440,
   11722,  1277, 13360,    56, 10709,    39, 11722,  1279, -1918,    56,
    1280, 13360, 11722,  1032,  1033, -1918, 11722,  9718, 10065, 10327,
   10407, 13494,  1281,  1283,  1287, 16305,  1288,  1290,  1291, 16330,
    1297,  1298,  1299,  1301,  1302,  1305,  1306, -1918,  1311,  1312,
    1314, -1918, 11722, 16355,  9440,  1065,  9440, 14273, -1918, -1918,
    1318, 15198, 15198, 15198, 15198, 15198, 15198, 15198, 15198, 15198,
   15198, 15198, 10740, 15198, 15198, 15198, 15198,  1625,   568, 15198,
   15198, 15198, 11080, 11340, 11420, 11678, 12764,  5857,  1084,  1085,
     161,  9440, 12973, 13361,   568, 13453,   568,  1081,  1082,  1087,
     137,  9440, 11722, 11722, 17305, -1918,   568,  1088, 14302, 14331,
   -1918, -1918,  1089,  -127,   568,    71,  1086,   -79,   541,  1348,
   -1918,    39,   568,  6930,  1097,  6361,  6613,  1524,  1593,  1090,
    1090,   438,   438,   438,   438,   438,   438,   592,   592,  9440,
    -108, -1918,  -108,  -108,   983,   983,   983,  1099, 16380, 15279,
     635,  9440, -1918,  1350,  1102,  1103, 16405, 16430, 16455, 11722,
    6930,  1361,  1360, 10129, 16480, 14360, 16505, 16530, -1918,   584,
     585,  9440,  1107, -1918, 12244, -1918, 12314, 12373,   386, 11722,
   11722, -1918, -1918,  1109,  1110, 10376,  7117,  1228,   659,   386,
   12443, 16555, 14389, 16580, 16605, 16630, 16655, 16680, 16705, 16730,
    1113,  1365, 11722,  1367, -1918, 11722, 16755, 14418, -1918, 15306,
   12502, 15333, -1918,   629,   636,   649, 14447, -1918,   651, 15360,
   15387, 13489, -1918, -1918,  1368,  1369,  1370,  1119, 11722, 12572,
   11722, 11722, -1918, -1918,    41,   -55,   159,   -55,  1125,  1126,
    1121,   568,   568,  1123, 13522,   568,   568,   568,   568, 11722,
     568,  1373, -1918,  1124,  1133,   270,  -101,  1132,   654, -1918,
   -1918, -1918, -1918, 15198,  -108, 12631,  1130,   650,  1129,  1200,
    1386,  1231, 10802,  1136,  1139,  1392,  6930, 14476, -1918, 11722,
    1393,   250,   124,    39,    49, 13494, 11722,  1394, -1918,   660,
    1352,  1354,  6930, 14505,   291,  1144, 16780, 15414,   625, 11722,
   11722,  1151,  1148,  1153,  1150,  8442, -1918, -1918, -1918, -1918,
   13360,   203,  1149, 16805, 15441,  1156, -1918,   258, -1918,   280,
   13555, -1918, -1918, -1918,  1152, -1918,  1157, 13588, -1918,    65,
   -1918, -1918, 17305, -1918,    47, 15198, 11722, 11722, 11722, 11722,
     568,   386,  6930,  6930,  1406,  6930,  6930,  6930,  1407,  6930,
    6930,  6930,  6930,  6930,  6930,  6930,  6930,  6930,  6930,  2193,
    1408,  9440,  5857, -1918, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918, -1918, -1918, -1918, -1918, -1918, 11722, -1918, -1918,
   -1918, -1918, -1918, -1918, -1918, -1918, -1918, 11722, 11722, 11722,
   11722, 11722, -1918, -1918, -1918,   662, 11722, 11722, -1918, 11722,
   -1918,  6930, 13360, 13360, -1918,   668, 14534, 14563,  1155, -1918,
   -1918, -1918,  1224, 11722, 11722, -1918, -1918, -1918,    39, -1918,
      39, 11722, 11722,  1165, -1918,  6930,   298, -1918, -1918, -1918,
   11722, 11722,   670,    39,    86,  -135, 11722, 11722, -1918,   568,
     677,  6930,  9440,  9440,  1412,  1415,  1416,  2703, -1918, -1918,
    1420, -1918,  1175, 17305,  1178,  1435, -1918,  1436,  1437,  1440,
    1441,   682,    50, -1918, 12701, -1918, -1918,   -64, 13621, 13654,
   -1918, -1918, 14592,  -180,  1330,  1446, 11049,  1193,  1447,  1204,
      18,    19,  -102, -1918,   200, -1918,   659,  1448,  1450,  1453,
    1454,  1455,  1456,  1457,  1458,  1459,   477,  6930, 17305, -1918,
    2735,  1199,  1366,  1463, -1918,  1464,  1465,  1372,  1466, -1918,
    1467,  1469,  1474, 11722,  6930,  6930,  6930,  1477, 13687, -1918,
    6865,  1918,    39,    39, -1918,  9440, -1918, -1918, -1918, -1918,
   13360, -1918, -1918, 11722, 13360, -1918, -1918, -1918, -1918, 17305,
   -1918,  1229,  1219, 13360, -1918, 13360, -1918,    39, 13360,  1236,
   -1918,  1230, -1918,    39, 11722, 11722,  1237,   663,  1239, 11142,
   -1918,  2780,  1240,  6930, -1918,  1233, -1918, 14621, -1918, -1918,
   11722,  1481,   683, 11722,  1488,  1489,    32,  1493,  1244,  1495,
    3253, -1918,   568,   298,   298,  1497, -1918, -1918,  1251,  1252,
    1254, -1918,  1498, -1918, -1918, -1918, -1918, -1918, -1918,    39,
    -181, 11769, 11722, 15468, 16830, 11722,  8689, 11722,  9440,  1249,
     684,  1503,   201,    39, -1918,  1255, 11722,  1504,  1505, 11722,
      39, 11389, 11722,  9687,   568,  5143, 11722, 11722,  1257,  1256,
   -1918,  1510, 16855, 16880, 16905, 16930,  1511,    11,  1383,  1383,
    6930,  1514,  1516,  1518,  6930,   -96,  1538,  1539,  1540,  1541,
    1543,  1545,  1546,  1547,  1549, -1918,  1551,   687, 15198, 15198,
   15198, 15198, 15198, 15198,   568, 13720, 13753, 13786,  1303,   568,
     568, -1918, -1918, -1918,    47,   568, 16955, 15198,  1304,   205,
   17305, 15198, -1918,  1554,   568, 17305, 17305, -1918,   626, -1918,
      39, -1918, 16980, 15495, -1918,   568,  1555,   690,   695,  6930,
    6930,  6930,  1553,  1556, -1918,   383, 11722,  6930,  6930,  6930,
    1307,  1308,  1557,  1562,  1563, -1918, 11722, 11722, 11722,  1313,
    1315,  1316,  1319, -1918,  3326,  6930, -1918, 11722, -1918,  1566,
   -1918,  1570, -1918, -1918, 10376,   561,  6174, -1918,  1320,  1324,
    1326,  1329,  1331,  1332,  8936,  1310,  1582, -1918,  9440,  1334,
   -1918, -1918, -1918,  1335, 11722, 11722, -1918, -1918, 15522,  1588,
    1589,  1375, -1918, 11722, 11722, 11722, -1918,  1594,   748,   333,
    1336,  3950,  1338, 11722,     5,   568,  1347,   568,  1340, -1918,
   -1918, 13494,   688, 11722,  1346, -1918, -1918,  3358, -1918, -1918,
    1342,  1600, -1918,  3719, -1918,  1351,  1601,   356,  3841, -1918,
      32, -1918,   697, -1918, 11722, -1918, -1918,   383,  1091, 11952,
   -1918,  1353, 11722, 11722,  6930,  1355, -1918,   609,    61,  1604,
   17005,  1606,  1348, 17030,  1356,   700, 17055,   705,  1608,  1611,
   -1918, -1918, 13360,  1364,  1617, 17080, -1918, -1918, 13819,  1371,
   -1918,  7369,  5418, 17305, -1918,  1615,   298,  7434, -1918, -1918,
   -1918, 17305, 17305, -1918,    47, -1918,  1621,  1622,  1624,  1626,
   -1918, -1918,   386,  1629,  1630,  1631, -1918, -1918, -1918,  1496,
      31,  1534,  1634, -1918, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918,  1618,  1384, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, 11722, 11722, 11722, -1918, -1918, -1918,  1256, -1918, -1918,
   -1918, -1918, 11722,  1389,  1378, -1918, -1918, 11722, 11722,   568,
      86, -1918, -1918, -1918, -1918,  1388,  1391,  1641,   -96,  1645,
   11722, -1918,  6930, 17305,  1512,  1517,  1051,  9440,  9440, 11722,
   -1918, 10129, 14650, 17105,  7621,   477,   477, 11722, 11722, -1918,
     420,  1390, 17130, -1918, -1918, 14679,   204, -1918,  1646,  1652,
    6930,   386,   386,   386,   386,   386,  6426,  1654, -1918, -1918,
     706,  9440, 11722,  4052,  4099,  1655, -1918, -1918,  6930,  7873,
    1295, 17155, -1918, -1918,  9782, -1918, 13360, 11722, -1918, 13360,
   17305, 10034, 13494,  1399, -1918, -1918, -1918, -1918,  1409,  1400,
   11722, 11722, 14708, 11722, 10769, -1918, 10769,  6930, -1918, -1918,
      39,    49, 13494, 11722,  1659, -1918,  1660, -1918,    32, 15549,
    6930, 13360,  1661,   568, -1918,  1405,   568, 11722, 13852, 13885,
     707, -1918, 11722, 11722,  1417, -1918,  1418, -1918,  1416,  1671,
    1672,  1437,  1673, -1918, -1918,  1674, 11722, -1918, -1918, 11722,
   11475,  1675, 11722, -1918, -1918,  1424, 11952,   708,  5080,  1677,
   -1918, -1918, -1918, -1918, -1918,   823, -1918, -1918, -1918,  1542,
    1679,  1428,  1431,  1432, -1918,  1686,  6930, 15198, 15198, 13918,
   15198, -1918,  1438, 17180, 15576, -1918, -1918,  9440,  9440, -1918,
    1688, -1918, 17305,  1689, 11722, 11722,  1434, -1918,   714,   715,
   15170,  4129,  1690,  1439, -1918, -1918, 11722,  1442,  1443, 14737,
   15603,  1694,  6930,  1696,  1451, 11722, -1918, -1918,   720,   206,
     211,   254,   257,   263,  9188,   269, -1918,  1700,   721, 14766,
   -1918, -1918, -1918,  1521, -1918, 11722, 11722, -1918, -1918,  9440,
    4386,  1704,  1460, 15198,   568, 17305, -1918, -1918, -1918, -1918,
       5, -1918, 13494, -1918, 14795,  1452,  1461,  1462,  1705,  1710,
    1711,  4409, -1918, -1918, -1918,  1468,  1712,   722, -1918,  1713,
    1719,   378, 17305, 11722, 11722,  1471,  6930,   727, 17305, 17205,
   -1918, -1918, -1918, -1918, 17230, 13951, -1918, -1918, 14824,  1155,
    1219,  6930,   568, -1918, 11722, 13494,    56, -1918, -1918,  9440,
    9440, 11722,  1724,   728, -1918, -1918, 11722,  1378, -1918, -1918,
   -1918,   729,   734, -1918, -1918,  4508,  4541,  6930,   664,   679,
    9440, -1918, -1918,   477,  8125, -1918, -1918, -1918,  1725, -1918,
    1473,  6930, -1918, 14853,  1728,  9440,   386,   386,   386,   386,
     386, -1918,  1729, -1918, 11722, 14882, 14911,   735, -1918, -1918,
   -1918, -1918, -1918, -1918,  1482,  1730,  1483, -1918,  1734,    32,
   -1918, -1918, -1918,  1552, -1918, -1918, -1918, -1918, -1918, 11722,
   13984, 14017,  6930, -1918,  1737, 11722,  1486, -1918, 11722,  1740,
    1490,  1491, -1918, -1918,  5360, -1918,  1494,   736,   737, 14940,
   -1918,  1515, 14050,  1492, -1918,  1526, -1918, -1918,   759,  1528,
     386,  6930,  1745,  1535,   386,  1746,   764,  1520, -1918, 11722,
   -1918,  1748,  1613, 12760,  1536, -1918,   765,   273,   276,   288,
     326,   337, -1918,  4569, -1918, -1918,  1769,  1770, -1918, -1918,
   -1918,  1786, -1918,  1537, 17305, 11722, 11722,   767, -1918, 17305,
   14083, -1918, -1918, -1918,  1155, 13494,  1544, -1918, -1918, -1918,
   11722, 11722, -1918,  9440,  1790,   386,   131, -1918, -1918,   386,
     177, -1918,  1791, -1918, 14969, -1918, 11722, -1918,   659, -1918,
    1792,  9440,  9440,  9440,  9440,  9188, -1918, -1918, -1918, 10769,
   -1918, 11722, 17255, 14116,    33, 11722,  1550, -1918, -1918, 14149,
   14182,   772, -1918,   352, -1918,   375, -1918, -1918, -1918,  4886,
     582, 12830, -1918,   774,   775,   780,   782,   446,   788,  1558,
     789, -1918, 11722, -1918,  6930, 14998, -1918, 11722, 11722, -1918,
     386,   386, -1918, -1918, -1918,   659,  1795,  1796,  1797,  1798,
    9440,  1799,  1800,  1802,  1561, 17280,   791,  1804, 15027, 15198,
     483,   496,   639, -1918, -1918, -1918, -1918,   797, -1918, -1918,
   -1918, 13360, -1918,  1564, -1918,  1805, -1918, 11722, 11722, -1918,
    1806,   799, -1918,  1567,  6930, -1918, 15056, 15085, -1918,  1807,
   13360, 13360,   804,  1808,  1809, -1918, -1918,   805, -1918,  1810,
   -1918, -1918,  1815, 13360, -1918, -1918, -1918
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1918, -1918, -1918, -1918,   432, -1918, -1918, -1918, -1918,  -309,
   -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918,  -716,  -123,     0,  3552,  -418, -1918,  1374, -1918,
   -1918, -1918, -1918, -1918, -1918, -1917, -1918,   390,   213,  -115,
   -1918,   -72, -1918,   152,   433, -1918,  1848, -1918,   306,   -58,
   -1918, -1918,     8,  -639,  -319, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918,   800,  1850, -1918, -1918, -1918, -1918, -1263, -1250,
    1872, -1758,  1874, -1918, -1918, -1918,  1264, -1918,  -106, -1918,
   -1918, -1918, -1918,  2127, -1918, -1918, -1436,   329,  1881, -1918,
       6, -1918, -1918,   -62, -1918, -1724,   302,   -21,  2829,  2471,
    -316,   104, -1918,  1506,   178, -1918, -1918,   127,   297, -1727,
    -143,  1098, -1918,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -579
static const yytype_int16 yytable[] =
{
     144,   963,   964,  1515,   630,   314,  1888,   328,   330,  1761,
     333,   125,  1513,   646,   180,   470,  1925,  1641,  1926,  1087,
     665,   449,   168,  1683,  1508,  1510,   171,   166,   176,   754,
     419,   167,   670,   152,  1918,   421,   375,   780,  1066,  2183,
    1255,   557,  2050,   747,  1072,   781,  1650,   580,  1302,   348,
       4,  1405,   293,   166,  1493,   184,   379,   334,  1256,   353,
     166,   354,   638,   639,   298,  1804,     5,  1257,  1258,  1259,
     443,   444,  1403,  1260,  1261,   748,   749,  -573,   319,  1500,
     166,   352,   166,  1406,  1407,   765,   748,   749,   299,   308,
     293,   298,   309,   310,   311,   378,  1651,   748,   749,  1962,
     148,   723,   786,   726,   320,   312,   415,   431,   638,   639,
     787,   738,   638,   639,   147,  1081,   443,   444,   788,   602,
     321,   322,  1973,   429,   478,  1470,   789,   430,   757,   958,
     758,  1349,  1841,   965,   782,   793,  1194,  2164,   349,   599,
     600,   455,   638,   639,   450,   601,   465,   465,   465,   750,
     751,  1842,   154,   457,   335,   472,   355,  1512,   336,  1327,
     750,   751,  1328,   969,   337,   338,   791,   339,   340,   313,
     602,   750,   751,   484,   792,   169,   505,   170,   638,   639,
     797,  1200,  1065,  2166,  1201,   512,   798,   930,   341,   465,
     731,   149,   553,   554,   293,  1509,  1511,  2156,   293,  1496,
     757,   150,   758,   293,   293,   465,   800,  1611,   792,  1762,
     315,   161,   798,   316,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   538,   539,   542,
     543,   544,   545,   546,   547,   350,   549,   550,  1852,   118,
    1088,  1089,   151,   638,   639,   555,   556,  1349,   118,   293,
     164,   633,   634,  2068,   181,  1513,   155,   564,   565,   642,
     647,   118,   666,   293,   667,   118,   293,   578,   146,   615,
     616,   617,   118,   420,  1029,   153,   577,   414,   422,   418,
     376,  2184,   293,   293,   558,  1367,   293,   293,   293,   293,
     581,  1303,   118,   351,   118,   185,   380,  1356,   158,   124,
     954,   293,   956,   957,   156,   293,  1047,   378,  2107,   169,
     157,   170,   454,   660,   661,   662,  1197,   443,   444,   970,
     766,  1198,   767,   757,  -571,   758,   768,   443,   444,   293,
     677,   293,   293,   293,   358,  1350,  1353,   359,   990,   479,
    1078,   439,   440,   441,   442,   432,   159,   291,   293,   433,
     360,   443,   444,  1782,   603,   293,   604,  1095,   307,   169,
     605,   170,  1009,   638,   639,   443,   444,  1106,   160,   783,
     794,   784,   784,  1070,  1352,   785,   795,   697,   698,   699,
    1349,  2179,  1184,   703,   704,   705,   706,   707,   708,   709,
     792,   710,   439,   440,   441,   442,   711,   712,   880,   162,
     715,  1045,   443,   444,   757,   603,   758,   604,  1174,   638,
     639,   605,  1305,   727,   465,   293,   443,   444,   582,   293,
     293,   300,   443,   444,   301,   732,   302,   733,  1088,  1089,
     145,   734,   638,   639,   146,   293,   638,   639,   638,   639,
     451,   163,   769,   638,   639,   451,   451,   451,  1392,   169,
    2206,   170,   177,  1514,   451,   165,   836,  1885,  1201,  2005,
    1368,  1369,  1370,  1371,  2006,   805,   178,   439,   440,   441,
     442,   456,    99,  1206,   100,   101,   102,   103,   104,   179,
     649,   747,   108,   109,   650,   111,   638,   639,   451,   638,
     639,   443,   444,   663,   293,   638,   639,   664,   198,   513,
    2242,   638,   639,  1397,   451,   638,   639,  2007,   638,   639,
    2008,   836,   182,   748,   749,   757,  2009,   758,   293,   183,
     638,   639,  2010,  1325,   197,  1398,  2141,   293,   870,  2142,
     890,  2063,   465,   836,   465,   293,   465,   465,   472,   186,
    1372,  2143,   169,   886,   170,   552,  1017,   293,   293,   293,
     465,   465,   293,   168,   291,   168,   187,   293,   638,   639,
     561,   562,   895,   344,   897,   345,   961,   962,   902,   638,
     639,   634,   196,   439,   440,   441,   442,   835,   757,  2144,
     758,   836,   188,   293,   638,   639,   836,   750,   751,   927,
    2145,   614,   189,   439,   440,   441,  1071,   443,   444,   190,
     439,   440,   441,   442,   742,  2190,   623,   638,   639,   900,
     628,   293,   293,   836,    68,    69,    70,    71,   324,   325,
      74,  1067,   201,  2038,   324,   325,  1244,  1525,  2191,    83,
     326,  2039,    86,   934,   327,  1355,   326,   836,   457,   457,
     332,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   295,
     293,   293,   293,   601,   935,   293,   752,   753,   836,  1881,
     594,   595,   729,   597,   598,   599,   600,   747,   638,   639,
     757,   601,   758,   759,   472,   465,   472,   465,   465,   465,
     465,   465,   465,  1255,   465,   465,   465,   465,  1031,  2200,
     465,   465,   465,   168,  1037,   191,  1083,   293,   199,   748,
     749,  1256,  1036,   980,  1255,   638,   639,   836,  1046,   192,
    1257,  1258,  1259,   451,   739,   740,  1260,  1261,   638,   639,
     193,   293,  1256,   743,   308,   896,  2227,   309,   194,   311,
     755,  1257,  1258,  1259,  1753,  1754,   293,  1260,  1261,  2228,
     312,   540,  1075,   541,   303,   777,   195,   304,   202,  1702,
     305,   203,   306,  1049,   204,   638,   639,   836,   293,  1092,
    1458,  1255,  1459,    46,   293,   200,   293,   205,  1055,   472,
    1104,   640,  1056,   750,   751,  1468,  1109,   208,   465,  1256,
    1204,  1255,   638,   639,   836,   638,   639,  1218,  1257,  1258,
    1259,  2069,  2070,   207,  1260,  1261,   294,  2071,   641,  1256,
    1727,   648,   296,   757,  1494,   758,  2073,  2074,  1257,  1258,
    1259,   293,  2071,   293,  1260,  1261,   729,   597,   598,   599,
     600,  2193,   317,  1239,  1240,   601,   172,   836,   836,   173,
     877,   451,   174,   451,   175,   451,   451,   451,   689,   297,
     146,  1783,   614,  1803,   891,  1771,   318,  -575,   293,   451,
     451,  1790,  1575,  1576,   323,  2170,   443,   444,   293,  1382,
    1687,  1335,  1688,  -574,  1547,  1548,   443,   444,  1286,  1216,
    1032,  1217,   836,   346,   347,  1287,  1247,  1202,  2229,   836,
     293,   443,   444,  1253,  1334,   331,  1335,  1264,  1288,  1558,
    1290,   342,   836,  1331,   836,  1562,   293,   836,   356,  1362,
    1513,  1444,   363,   836,  1218,   836,   343,  1451,   293,  1467,
    1219,   836,  2212,   836,  1577,   357,  1475,   293,  1351,  1354,
     836,  1492,  1770,  1609,  1771,   836,  1663,   836,   293,  1695,
     836,   362,   777,   836,  1696,  1218,  1787,   364,   836,  1810,
    1788,  1597,  1513,   836,  1812,  1897,  1945,  1963,   836,   836,
    1946,  1964,   365,  1988,  1989,  1613,   777,   836,   836,  2004,
    2012,  2035,  1619,  1946,   836,   792,  2044,  2061,  2064,  1120,
    2045,  1946,   836,  2065,  2096,  2117,  2118,   836,   836,   836,
     836,   371,   383,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   372,   451,   451,   451,   451,   373,  2124,   451,
     451,   451,  1946,  2132,  2140,   374,  2154,   836,   836,   777,
    1946,  2189,   777,  2196,  2197,   836,   384,   836,   836,  2198,
    1581,  2199,   428,   836,   777,   836,  1060,  2201,  2203,   381,
    2223,   836,  2045,   293,  1946,  1866,  2230,  1867,  2239,  1417,
     836,  1358,  2240,  2249,  2252,   638,   639,  1946,  2253,   293,
     757,   382,   758,   931,   385,   416,  1877,  1878,   427,  1082,
     434,  1084,   293,   460,   461,   476,   435,   465,   146,   478,
     480,  1469,  1471,   481,   482,   166,   386,   483,   451,   488,
     492,   506,  -204,   548,   551,  -205,   511,   451,  -206,  1404,
     559,   560,   563,   566,   567,   568,   579,   611,   612,   293,
     293,  1234,   293,   293,   293,   430,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   619,   620,   293,   621,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   624,
     627,   629,   631,   396,   397,   398,   399,   632,   651,   652,
     653,   400,   401,   402,   403,   654,   655,   668,   656,   404,
     671,   405,   672,   657,   684,   673,   669,   679,   293,   465,
     465,   674,   685,   675,   676,   406,   678,   680,   407,   681,
     691,   692,   303,   700,   701,   304,   702,   713,   305,   714,
     306,   716,   293,   718,   717,  1208,  1464,   719,   720,   721,
     722,    46,   724,   725,   741,   744,   756,   761,   293,   293,
     293,   763,   764,   145,   802,   770,   827,   806,   832,   437,
     811,   838,   839,   840,   871,   881,   601,   882,   903,   883,
     904,   939,  1228,  1359,   901,   940,  1774,   943,   948,   952,
    1776,   953,   984,   955,   982,   985,   988,  1469,  1471,   997,
     777,  1003,   777,   777,  1786,  1007,  1010,  1054,  1039,  1041,
    1048,  1058,  1059,  1064,   293,  1063,   777,  1068,  1079,  1080,
    1096,  1085,  1098,  1101,   457,  1108,  1110,  1113,  1121,  1114,
    1122,   293,   293,   293,  1123,  1125,   777,  1126,  1127,   408,
     409,   410,   293,  1906,  1129,  1130,  1131,   465,  1132,  1133,
     411,   465,  1134,  1135,   412,   777,   413,   118,  1136,  1137,
     465,  1138,   465,  1141,  1145,   465,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,  1172,
     293,  1199,  1173,   601,  1181,  1182,   757,  1190,   758,  1791,
    1183,   777,  1193,   378,  2077,  1205,  1209,  1221,  1345,  1213,
    1222,  1223,  1928,  1588,  1589,  1229,  1231,  1242,  1250,  1251,
    1254,  1276,  1277,  1279,  1365,  1294,  1295,  1296,   465,  1297,
    1308,  1309,  1321,   293,  1310,   293,  1313,  1323,  1324,  1330,
    1333,  1336,  1337,  1338,  1339,  1342,   451,  1343,  1344,  1348,
    1361,  1363,   293,  1364,  1379,  1385,  1386,  1387,  1388,  1393,
    1396,  1401,  1400,  1420,  1424,  1436,  -207,   293,  1454,  1479,
    1462,   293,  1480,  1481,  1418,  1419,  1484,  1421,  1422,  1423,
    1485,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,  1486,  1487,  1488,  1489,  1795,  1795,  1490,  1491,  1501,
    1502,  1505,  1726,  1506,  1784,  1516,  1517,  1528,  1507,  1682,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1529,  1689,  1530,
    1531,  1532,  1934,  1534,  1535,  1536,   293,   293,   293,  1533,
    1537,  1542,  1554,  1448,   293,   293,   293,  1574,   451,   451,
    1553,  1560,  1571,  1561,  1579,  1563,  1580,  1565,  1569,  1583,
    1584,  1585,   293,  1590,  1596,  1592,  1593,  1463,  1608,  1610,
    1616,  1617,  1594,   293,  1633,  1614,  1635,  1640,  1642,  1634,
    1646,   293,  1647,  1476,  1648,   293,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,  1653,  1654,  1655,  1656,   601,  1657,
     777,  1658,  1659,  1660,  1907,  1661,  1662,  1700,  1674,  1681,
    1685,  1694,  1701,  1748,  1709,  1707,  1708,  1856,  1710,  1738,
    1711,  1715,  1723,  1716,  1717,  1718,  1724,   378,  1730,  1526,
    1835,  1624,  1731,  1629,  1732,   472,   472,  1733,  1739,  1734,
    1735,   293,  1741,  1742,  1746,  1747,  1539,  1540,  1541,  1756,
    1752,  1759,  1766,  1328,  1773,  1777,  1778,  1797,  1781,   465,
    1805,  1780,  1807,  1802,  1813,  1809,   451,  1814,  1816,   293,
     451,  1817,  1825,  1845,   293,  1820,  1826,  1831,  1832,   451,
    1833,   451,  1834,   582,   451,  1836,  1837,  1838,  1839,  1843,
    1844,  1201,  1846,  1564,  1851,  1570,  1857,  1859,  1937,  1858,
     453,  1861,  1886,  1882,  1864,   463,   466,   467,  1887,  1865,
    1896,  1902,  1920,  1922,  1921,  1932,  1933,  1938,   792,  1889,
    1890,  1891,  1892,  1893,  1895,  -578,  -576,  1950,  1951,  1952,
    1953,  1957,  1961,  2083,  1966,  1968,  1969,   451,  1967,  1970,
    1971,  1972,  1987,  1978,  1983,  1984,  1992,  1993,   500,   293,
    1999,  1995,  1996,  2001,   293,   293,  2011,  1628,  2014,  2002,
    2019,  2026,  2029,  2101,   514,  2020,  2030,  2031,  2034,  2036,
    2027,  2028,  1645,   457,   457,  2037,  1649,   293,  2033,  2042,
    2060,  2080,  2081,   293,  2085,  2092,  2098,  2097,   293,  1769,
    2100,  2099,  2102,  2108,  -577,   293,  2111,  2122,  2116,  2112,
    2113,  2128,  2131,   465,  2135,  2136,   465,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,  2120,   293,  2147,  2148,   601,  1358,  2133,
    2149,  1697,  1698,  1699,  2123,   378,  2125,   293,   472,  1704,
    1705,  1706,  2150,  2129,  2139,  2151,  2162,  2167,  2172,  2158,
    1824,  2213,  2214,  2215,  2216,  2218,  2219,  1721,  2220,  2186,
    2224,  2235,  2238,  2245,  2250,  2251,  2254,  2202,  1729,  2221,
    2171,  2255,  2234,   472,  1612,  2241,  1737,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,  2180,   293,  1677,  2051,   601,  1830,  2023,   801,
    1860,   123,  1644,   134,   293,   293,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   834,
     597,   598,   599,   600,  1378,   135,   762,   136,   601,   293,
     757,   942,   758,  2075,   142,  1929,  1796,  1768,  1917,  1872,
    1103,   293,     0,     0,   451,   451,  1801,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   451,     0,
       0,     0,     0,     0,  1823,     0,  1545,     0,     0,     0,
       0,     0,  1911,   735,     0,     0,     0,     0,     0,  1916,
    1919,     0,     0,   293,  2087,  2088,  2089,  2090,  2091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
    1930,     0,     0,  2056,     0,     0,   293,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,     0,     0,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
       0,   457,   293,     0,  1863,     0,     0,     0,  2126,     0,
       0,     0,  2130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   378,     0,     0,     0,
       0,     0,  1801,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1903,   874,     0,   876,     0,   878,   879,     0,     0,     0,
       0,     0,   451,  2163,     0,   451,     0,  2165,   293,   892,
     893,     0,     0,     0,     0,     0,     0,     0,     0,  1927,
     777,     0,   777,  2177,     0,     0,     0,     0,     0,     0,
       0,     0,  1936,     0,     0,     0,     0,   451,     0,     0,
    2024,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
     293,   779,     0,   601,     0,     0,     0,     0,  2210,  2211,
       0,     0,   451,     0,     0,     0,     0,     0,   293,   293,
     293,   293,   293,  2055,     0,     0,     0,     0,  1801,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,  1546,     0,     0,     0,     0,     0,     0,
       0,   293,     0,     0,  2000,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,  1435,
       0,     0,     0,     0,  1016,     0,  1018,  1019,  1020,  1021,
    1022,  1023,     0,  1025,  1026,  1027,  1028,     0,   465,  1033,
    1034,  1035,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,     0,     0,     0,     0,     0,   465,   465,     0,
       0,     0,     0,     0,   425,     0,     0,     0,  2043,     0,
     465,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2052,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,     0,   462,     0,     0,     0,     0,
     468,     0,     0,     0,     0,     0,     0,     0,   473,  1801,
       0,     0,     0,  2157,     0,     0,     0,     0,  1102,     0,
       0,     0,     0,  2082,   485,   486,   487,  1111,   489,   490,
     491,     0,   493,   494,   495,   496,   497,   498,   499,     0,
     501,   502,   503,   504,     0,     0,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1801,     0,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,  2127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   777,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   569,   571,   573,   574,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   608,   508,   508,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,   626,     0,     0,   601,     0,     0,     0,
       0,     0,     0,   636,   637,   777,     0,     0,     0,   637,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
     659,     0,     0,     0,     0,     0,     0,   777,     0,     0,
       0,     0,     0,     0,     0,     0,  1801,     0,     0,     0,
       0,     0,     0,     0,   682,   508,     0,     0,     0,   686,
     687,   688,     0,   690,     0,     0,     0,   693,   694,   695,
       0,     0,   696,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   451,     0,     0,
       0,     0,     0,     0,     0,     0,  1801,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   451,   451,     0,     0,
       0,   728,     0,     0,     0,   508,   737,     0,     0,   451,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   745,   746,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   778,     0,     0,
       0,     0,     0,     0,     0,     0,  1391,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   807,   808,   809,
     810,     0,     0,     0,     0,   815,     0,     0,     0,   819,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   833,   571,     0,     0,     0,   837,     0,
       0,     0,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   859,
     860,   861,   862,   863,   864,   865,   866,   867,   867,     0,
     872,   873,   510,   875,     0,     0,     0,     0,     0,     0,
       0,     0,   884,     0,     0,   888,   889,     0,  1449,  1450,
       0,     0,   867,     0,     0,     0,     0,   508,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   920,   922,   923,   924,   925,   926,     0,
     928,   929,     0,     0,     0,     0,     0,     0,   936,   937,
     938,  1527,     0,     0,     0,     0,   944,   945,   946,   947,
       0,   508,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   609,   610,     0,     0,
     569,   728,   966,     0,     0,     0,   971,   972,   973,   974,
     975,   976,   977,   978,   979,     0,  1568,     0,     0,     0,
     986,   987,     0,   989,     0,     0,   991,     0,     0,     0,
     508,   508,   508,   996,     0,   508,   999,  1000,  1001,     0,
       0,     0,     0,   658,     0,     0,  1550,     0,     0,     0,
    1552,     0,     0,     0,     0,     0,     0,     0,     0,  1556,
       0,  1557,     0,  1024,  1559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1482,     0,   508,     0,     0,
       0,     0,     0,     0,  1043,     0,  1044,     0,     0,   928,
     929,     0,     0,     0,     0,     0,     0,     0,  1057,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   508,  1599,  1073,     0,
       0,     0,     0,  1076,  1077,     0,     0,     0,     0,   736,
       0,     0,     0,     0,     0,     0,     0,     0,   508,     0,
    1093,  1094,     0,     0,   508,     0,   508,  1100,     0,     0,
       0,  1093,     0,  1107,     0,     0,     0,     0,     0,  1112,
       0,     0,     0,  1115,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,  1139,
       0,   920,     0,  1142,     0,     0,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,  1186,
    1187,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
     509,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,   898,     0,     0,     0,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,  1227,     0,     0,     0,
    1233,     0,     0,     0,     0,     0,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,  1248,  1249,     0,     0,
       0,     0,  1252,     0,     0,   949,   950,     0,     0,     0,
       0,     0,     0,     0,     0,   572,     0,     0,   509,  1278,
       0,     0,  1280,     0,     0,     0,     0,     0,  1815,     0,
       0,     0,     0,     0,   509,   509,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1298,     0,  1300,  1301,     0,
       0,     0,     0,     0,   993,   994,   995,     0,     0,   998,
       0,     0,     0,     0,     0,     0,  1319,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,     0,     0,     0,     0,     0,     0,     0,  1341,
       0,     0,     0,     0,     0,     0,  1347,     0,     0,     0,
       0,  1038,     0,  1360,     0,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,  1383,  1384,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1412,  1413,  1414,  1415,     0,     0,     0,
       0,     0,  1091,     0,     0,     0,     0,   509,  1097,  1586,
    1099,     0,  1912,     0,     0,  1914,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1438,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1439,  1440,  1441,  1442,  1443,     0,
       0,     0,     0,  1445,  1446,     0,  1447,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1456,  1457,     0,     0,     0,     0,     0,     0,  1460,  1461,
       0,     0,  1719,     0,     0,     0,   572,  1465,  1466,     0,
       0,     0,  1175,  1472,  1473,     0,     0,     0,     0,   508,
     508,     0,  1185,     0,     0,     0,     0,     0,     0,     0,
     858,     0,     0,     0,  1775,     0,     0,     0,     0,   868,
     869,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1504,     0,     0,     0,     0,     0,     0,
    1212,     0,     0,     0,   894,     0,     0,     0,     0,   509,
       0,     0,  1220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1538,     0,  1241,     0,     0,   921,     0,     0,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,     0,
    1551,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   509,   509,     0,     0,     0,     0,     0,
       0,  1472,  1473,     0,     0,     0,  1567,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1573,     0,     0,
    1578,     0,     0,     0,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,   509,   509,   509,     0,   601,   509,     0,  1600,
       0,     0,  1603,   508,  1606,   508,     0,     0,     0,     0,
       0,     0,     0,  1615,     0,     0,  1618,     0,  1615,  1621,
    1623,     0,     0,  1631,  1632,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
       0,     0,     0,     0,     0,     0,  1390,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,   509,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
     509,   601,  1437,  1703,     0,     0,   509,     0,   509,     0,
       0,     0,     0,  1712,  1713,  1714,     0,     0,     0,     0,
       0,     0,  1720,     0,  1722,     0,     0,     0,     0,     0,
       0,  1725,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,  1743,  1744,   921,     0,  1143,     0,     0,     0,     0,
    1749,  1750,  1751,     0,     0,     0,     0,     0,     0,     0,
    1760,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1772,     0,     0,  1477,  1478,     0,     0,     0,     0,     0,
     509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     509,  1789,     0,     0,     0,     0,     0,     0,     0,  1798,
    1799,     0,     0,     0,     0,  1779,     0,  2232,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,  2246,  2248,   509,    43,
      44,    45,    46,     0,  1828,    48,     0,     0,     0,  2256,
     509,     0,     0,   771,    56,     0,     0,    59,   772,     0,
     773,   774,     0,   775,     0,     0,  1549,     0,     0,     0,
     509,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,  1847,  1848,
    1849,     0,     0,     0,     0,     0,     0,     0,     0,  1850,
       0,     0,     0,     0,  1853,  1854,    95,    96,    97,     0,
       0,     0,     0,     0,     0,     0,     0,  1862,     0,     0,
       0,     0,     0,     0,   508,   508,  1870,     0,  1871,     0,
       0,     0,     0,     0,  1879,  1880,     0,  1785,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1605,     0,  1607,
       0,     0,     0,   508,     0,     0,     0,     0,   508,  1899,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1910,     0,     0,  1913,     0,     0,     0,  1915,     0,
       0,   967,     0,     0,     0,     0,     0,  1853,  1854,     0,
    1924,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1931,     0,     0,     0,   509,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1942,     0,     0,     0,     0,  1948,
    1949,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1954,     0,     0,  1955,  1954,     0,  1958,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
     509,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   508,   508,     0,     0,     0,     0,
       0,  1985,  1986,     0,     0,     0,     0,     0,     0,  1740,
       0,     0,   760,  1994,     0,     0,     0,     0,     0,     0,
       0,     0,  2003,     0,     0,     0,     0,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2015,  2016,     0,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   509,   509,     0,     0,     0,     0,     0,  1900,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2040,  2041,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,  2054,     0,     0,   601,     0,   508,   508,  2059,     0,
       0,     0,     0,  2062,     0,  1901,     0,     0,   885,     0,
       0,     0,     0,     0,     0,     0,     0,   508,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   508,     0,   509,  1991,     0,     0,     0,     0,
       0,  2093,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   932,
       0,     0,     0,     0,     0,     0,  2104,     0,     0,     0,
       0,     0,  2109,     0,     0,  2110,     0,     0,  1868,  1869,
       0,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   757,  2134,   758,     0,     0,
       0,     0,  1898,  1757,     0,   509,     0,   509,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2152,  2153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2159,  2160,     0,
     508,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2169,     0,     0,     0,     0,   508,   508,
     508,   508,   508,     0,     0,     0,     0,     0,  1948,     0,
       0,     0,  2185,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,  2205,
       0,     0,     0,     0,  2208,  2209,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,  1981,  1982,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,  2236,  2237,     0,   509,     0,     0,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
    2017,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2018,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,     0,  1158,  1159,  1160,  1161,     0,
    1163,  1164,  1165,  1166,     0,  2032,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1178,     0,  1180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1189,     0,
    2057,  2058,     0,     0,     0,  1195,  1196,     0,     0,     0,
       0,     0,     0,     0,  1207,     0,  1829,     0,     0,     0,
       0,  2076,     0,     0,     0,     0,   209,   166,     0,     0,
       0,     0,     0,   210,   211,   212,  2086,     0,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   423,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2066,     0,     0,     0,     0,     0,
       0,   244,   245,   246,   247,     0,     0,     0,     0,   248,
       0,     0,     0,     0,     0,     0,   509,   509,     0,     0,
       0,     0,     0,     0,   252,   253,   254,  2067,     0,     0,
       0,     0,     0,     0,     0,   255,    25,     0,   256,     0,
       0,     0,     0,     0,     0,   509,     0,  1304,  1306,  1307,
     509,     0,     0,  1311,  1312,  2146,     0,  1315,  1316,  1317,
    1318,     0,  1320,     0,     0,     0,     0,  1326,     0,     0,
       0,     0,     0,     0,  2161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2173,  2174,  2175,  2176,  2178,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,  1411,     0,     0,
     266,  2217,  1416,     0,   267,     0,     0,     0,     0,   269,
     270,   271,     0,   272,   273,   274,   509,   509,     0,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,   424,     0,     0,     0,
       0,     0,   277,     0,     0,     0,     0,   367,     0,     0,
       0,   625,     0,   572,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1474,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,   509,   509,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,   509,
       0,     0,   601,     0,     0,     0,     0,     0,   209,   166,
     386,     0,   436,     0,   509,   210,   211,   212,     0,     0,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   423,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   244,   245,   246,   247,   396,   397,   398,
     399,   248,  2192,     0,     0,   400,   401,   402,   403,     0,
       0,     0,     0,   404,     0,   405,   252,   253,   254,     0,
       0,     0,     0,     0,  1587,     0,     0,   255,    25,   406,
     256,     0,   407,     0,     0,     0,   303,     0,     0,   304,
       0,     0,   305,     0,   306,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,   509,     0,     0,     0,  1625,     0,     0,     0,
       0,     0,     0,   437,     0,     0,     0,     0,     0,     0,
     509,   509,   509,   509,   509,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1664,  1665,  1666,  1667,  1668,  1669,  1670,     0,     0,     0,
       0,  1675,  1676,     0,     0,     0,     0,  1678,     0,  1680,
       0,     0,     0,  1684,     0,     0,  1686,     0,     0,     0,
       0,     0,     0,     0,     0,   438,     0,  1693,     0,   509,
       0,     0,   266,   408,   409,   410,   267,     0,     0,     0,
       0,   269,   270,   271,   411,   272,   273,   274,   412,     0,
     413,   118,   439,   440,   441,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   275,   424,     0,
       0,     0,     0,     0,   277,     0,   443,   444,     0,   445,
       0,   446,     0,     0,     0,   447,   280,  1965,   582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1755,     0,  1758,     0,     0,     0,  1765,     0,  1767,
       0,     0,     0,     0,     0,     0,     0,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
    1792,     0,     0,     0,     0,     0,   209,     6,   386,     0,
       0,     0,     0,   210,   211,   212,     0,     0,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
       0,     0,  1626,   388,   389,   390,   391,   392,   393,   394,
     395,   244,   245,   246,   247,   396,   397,   398,   399,   248,
     249,     0,     0,   400,   401,   402,   403,     0,     0,   250,
     251,   404,     0,   405,   252,   253,   254,     0,     0,     0,
       0,     0,     0,     0,     0,   255,    25,   406,   256,     0,
     407,  1855,     0,     0,   257,     0,     0,   258,     0,     0,
     259,     0,   260,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   261,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,    57,    58,     0,   263,
       0,   264,     0,     0,   265,     0,     0,     0,     0,     0,
      68,    69,    70,    71,    72,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,    83,     0,     0,    86,     0,
       0,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   834,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1939,     0,     0,  1940,     0,
     266,   408,   409,   410,   267,   268,     0,     0,     0,   269,
     270,   271,   411,   272,   273,   274,   412,  2115,   413,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,   276,     0,     0,     0,
       0,     0,   277,     0,     0,     0,     0,   367,     0,  1974,
    1975,  1627,  1977,     0,   280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     6,   386,     0,     0,     0,     0,   210,   211,
     212,     0,     0,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,  2021,  2022,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   244,   245,   246,   247,
     396,   397,   398,   399,   248,   249,     0,     0,   400,   401,
     402,   403,     0,     0,   250,   251,   404,     0,   405,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
     255,    25,   406,   256,  2053,   407,     0,     0,     0,   257,
       0,     0,   258,     0,     0,   259,     0,   260,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,    57,    58,     0,   263,     0,   264,     0,     0,   265,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,     0,     0,     0,     0,     0,
       0,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,   582,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,   408,   409,   410,   267,
     268,     0,     0,     0,   269,   270,   271,   411,   272,   273,
     274,   412,     0,   413,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,   276,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   367,   209,     6,   366,   279,     0,     0,   280,
     210,   211,   212,     0,     0,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,  2226,   255,    25,     0,   256,     0,     0,     0,     0,
       0,   257,     0,     0,   258,     0,     0,   259,     0,   260,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,    57,    58,     0,   263,     0,   264,     0,
       0,   265,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,     0,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,   582,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,   267,   268,     0,     0,     0,   269,   270,   271,     0,
     272,   273,   274,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,   276,     0,     0,     0,     0,     0,   277,
       0,     0,     0,     0,   367,   209,     6,     0,   368,     0,
     683,   280,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   255,    25,     0,   256,     0,     0,
       0,     0,     0,   257,     0,     0,   258,     0,     0,   259,
       0,   260,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,    57,    58,     0,   263,     0,
     264,     0,     0,   265,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   834,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,  1011,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,     0,   267,   268,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   507,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   367,   209,     6,  1728,
       0,   575,     0,   280,   210,   211,   212,     0,     0,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   245,   246,   247,     0,     0,     0,     0,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,     0,     0,     0,   252,   253,   254,     0,     0,
       0,     0,     0,     0,     0,     0,   255,    25,     0,   256,
       0,     0,     0,     0,     0,   257,     0,     0,   258,     0,
       0,   259,     0,   260,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,    57,    58,     0,
     263,     0,   264,     0,     0,   265,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,  1210,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,   267,   268,     0,     0,     0,
     269,   270,   271,     0,   272,   273,   274,     0,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,   276,     0,     0,
       0,     0,     0,   277,     0,     0,     0,     0,   367,   209,
       6,     0,   279,     0,     0,   280,   210,   211,   212,     0,
       0,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,   246,   247,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   251,     0,     0,     0,   252,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,    25,
       0,   256,     0,     0,     0,     0,     0,   257,     0,     0,
     258,     0,     0,   259,     0,   260,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,    57,
      58,     0,   263,     0,   264,     0,     0,   265,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,  1211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,     0,     0,   267,   268,     0,
       0,     0,   269,   270,   271,     0,   272,   273,   274,     0,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,  1894,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     645,   209,     6,     0,   327,   575,     0,   280,   210,   211,
     212,     0,     0,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   245,   246,   247,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,     0,     0,     0,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
     255,    25,     0,   256,     0,     0,     0,     0,     0,   257,
       0,     0,   258,     0,     0,   259,     0,   260,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,    57,    58,     0,   263,     0,   264,     0,     0,   265,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,  1544,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,   267,
     268,     0,     0,     0,   269,   270,   271,     0,   272,   273,
     274,     0,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,   276,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   278,   209,     6,     0,   279,     0,     0,   280,
     210,   211,   212,     0,     0,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,   255,    25,     0,   256,     0,     0,     0,     0,
       0,   257,     0,     0,   258,     0,     0,   259,     0,   260,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,    57,    58,     0,   263,     0,   264,     0,
       0,   265,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,   267,   268,     0,     0,     0,   269,   270,   271,     0,
     272,   273,   274,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,   276,     0,     0,     0,     0,     0,   277,
       0,     0,     0,     0,   367,   209,     6,     0,   279,     0,
       0,   280,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   255,    25,     0,   256,     0,     0,
       0,     0,     0,   257,     0,     0,   258,     0,     0,   259,
       0,   260,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,    57,    58,     0,   263,     0,
     264,     0,     0,   265,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,  1002,     0,     0,     0,     0,     0,     0,     0,
     959,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,     0,   267,   268,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   507,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   367,   209,     6,     0,
     570,     0,     0,   280,   210,   211,   212,     0,     0,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   245,   246,   247,     0,     0,     0,     0,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,     0,     0,     0,   252,   253,   254,     0,     0,
       0,     0,     0,     0,     0,     0,   255,    25,     0,   256,
       0,     0,     0,     0,     0,   257,     0,     0,   258,     0,
       0,   259,     0,   260,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   261,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,    57,    58,     0,
     263,     0,   264,     0,     0,   265,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  1821,     0,
       0,     0,  1822,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,     0,   267,   268,     0,     0,     0,
     269,   270,   271,     0,   272,   273,   274,     0,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,   507,     0,     0,
       0,     0,     0,   277,     0,     0,     0,     0,   367,   209,
       6,     0,     0,   575,     0,   280,   210,   211,   212,     0,
       0,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,   246,   247,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   251,     0,     0,     0,   252,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,    25,
       0,   256,     0,     0,     0,     0,     0,   257,     0,     0,
     258,     0,     0,   259,     0,   260,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,    57,
      58,     0,   263,     0,   264,     0,     0,   265,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    1875,     0,     0,     0,  1876,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,     0,     0,   267,   268,     0,
       0,     0,   269,   270,   271,     0,   272,   273,   274,     0,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,   276,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     613,   209,     6,     0,   279,     0,     0,   280,   210,   211,
     212,     0,     0,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   245,   246,   247,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,     0,     0,     0,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
     255,    25,     0,   256,     0,     0,     0,     0,     0,   257,
       0,     0,   258,     0,     0,   259,     0,   260,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,    57,    58,     0,   263,     0,   264,     0,     0,   265,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  1904,     0,     0,     0,  1905,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,   267,
     268,     0,     0,     0,   269,   270,   271,     0,   272,   273,
     274,     0,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     275,   276,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   622,   209,     6,     0,   279,     0,     0,   280,
     210,   211,   212,     0,     0,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,   255,    25,     0,   256,     0,     0,     0,     0,
       0,   257,     0,     0,   258,     0,     0,   259,     0,   260,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,    57,    58,     0,   263,     0,   264,     0,
       0,   265,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  2078,     0,     0,     0,  2079,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,   267,   268,     0,     0,     0,   269,   270,   271,     0,
     272,   273,   274,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,   507,     0,     0,     0,     0,     0,   277,
       0,     0,     0,     0,   367,   209,     6,     0,   919,     0,
    1389,   280,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
       0,     0,     0,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   255,    25,     0,   256,     0,     0,
       0,     0,     0,   257,     0,     0,   258,     0,     0,   259,
       0,   260,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,    57,    58,     0,   263,     0,
     264,     0,     0,   265,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     790,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,     0,     0,   267,   268,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   507,     0,     0,     0,     0,
       0,   277,   209,     6,     0,     0,   367,  1604,     0,   210,
     211,   212,     0,   280,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,     0,     0,     0,     0,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   251,     0,     0,     0,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,   255,    25,     0,   256,     0,     0,     0,     0,     0,
     257,     0,     0,   258,     0,     0,   259,     0,   260,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,    57,    58,     0,   263,     0,   264,     0,     0,
     265,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    83,     0,     0,    86,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   796,     0,     0,
       0,     0,     0,     0,     0,     0,   266,     0,     0,     0,
     267,   268,     0,     0,     0,   269,   270,   271,     0,   272,
     273,   274,     0,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   507,     0,     0,     0,     0,     0,   277,   209,
       6,     0,     0,   367,     0,     0,   210,   211,   212,     0,
     280,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,   246,   247,     0,     0,
       0,     0,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,   251,     0,     0,     0,   252,   253,   254,
       0,     0,     0,     0,     0,     0,     0,     0,   255,    25,
       0,   256,     0,     0,     0,     0,     0,   257,     0,     0,
     258,     0,     0,   259,     0,   260,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,    57,
      58,     0,   263,     0,   264,     0,     0,   265,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   959,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,     0,     0,   267,   268,     0,
       0,     0,   269,   270,   271,     0,   272,   273,   274,     0,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   275,   276,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     367,   209,     6,     0,  1736,     0,     0,   280,   210,   211,
     212,     0,     0,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   244,   245,   246,   247,
       0,     0,     0,     0,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,     0,     0,     0,   252,
     253,   254,     0,     0,     0,     0,     0,     0,     0,     0,
     255,    25,     0,   256,     0,     0,     0,     0,     0,   257,
       0,     0,   258,     0,     0,   259,     0,   260,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,    57,    58,     0,   263,     0,   264,     0,     0,   265,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   960,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,     0,     0,   267,
     268,     0,     0,     0,   269,   270,   271,     0,   272,   273,
     274,     0,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     643,  1894,     0,     0,     0,     0,     0,   277,     0,     0,
       0,     0,   645,   209,     6,     0,   327,     0,     0,   280,
     210,   211,   212,     0,     0,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,     0,     0,     0,     0,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,   251,     0,     0,
       0,   252,   253,   254,     0,     0,     0,     0,     0,     0,
       0,     0,   255,    25,     0,   256,     0,     0,     0,     0,
       0,   257,     0,     0,   258,     0,     0,   259,     0,   260,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,    57,    58,     0,   263,     0,   264,     0,
       0,   265,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1008,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,   267,   268,     0,     0,     0,   269,   270,   271,     0,
     272,   273,   274,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   275,   507,     0,     0,     0,     0,     0,   277,
     209,   166,   386,     0,   367,     0,     0,   210,   211,   212,
       0,   280,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   423,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   244,   245,   246,   247,   396,
     397,   398,   399,   248,     0,     0,     0,   400,   401,   402,
     403,     0,     0,     0,     0,   404,     0,   405,   252,   253,
     254,     0,     0,     0,     0,     0,     0,     0,     0,   255,
      25,   406,   256,     0,   407,   209,   166,   386,     0,     0,
       0,     0,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   423,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     244,   245,   246,   247,   396,   397,   398,   399,   248,     0,
       0,     0,   400,   401,   402,   403,     0,     0,     0,     0,
     404,     0,   405,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   255,    25,   406,   256,     0,   407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,   408,   409,   410,   267,     0,
       0,     0,     0,   269,   270,   271,   411,   272,   273,   274,
     412,     0,   413,   118,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
     424,     0,     0,     0,     0,     0,   277,     0,     0,     0,
       0,   367,     0,     0,     0,  1622,     0,     0,   280,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1116,     0,     0,     0,     0,     0,     0,     0,   266,
     408,   409,   410,   267,     0,     0,     0,     0,   269,   270,
     271,   411,   272,   273,   274,   412,     0,   413,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   424,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   367,   209,   166,   386,
    1909,     0,     0,   280,   210,   211,   212,     0,     0,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   423,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,  1626,   388,   389,   390,   391,   392,   393,
     394,   395,   244,   245,   246,   247,   396,   397,   398,   399,
     248,     0,     0,     0,   400,   401,   402,   403,     0,     0,
       0,     0,   404,     0,   405,   252,   253,   254,     0,     0,
       0,     0,     0,     0,     0,     0,   255,    25,   406,   256,
       0,   407,   209,   166,   386,     0,     0,     0,     0,   210,
     211,   212,     0,     0,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   423,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   244,   245,   246,
     247,   396,   397,   398,   399,   248,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   404,     0,   405,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,   255,    25,   406,   256,     0,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,   408,   409,   410,   267,     0,     0,     0,     0,
     269,   270,   271,   411,   272,   273,   274,   412,     0,   413,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   275,   424,     0,     0,
       0,     0,     0,   277,     0,     0,     0,     0,   367,     0,
       0,     0,  1791,     0,     0,   280,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1117,     0,
       0,     0,     0,     0,     0,     0,   266,   408,   409,   410,
     267,     0,     0,     0,     0,   269,   270,   271,   411,   272,
     273,   274,   412,     0,   413,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   424,     0,     0,     0,     0,     0,   277,   209,
     166,     0,     0,   367,     0,     0,   210,   211,   212,     0,
     280,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   423,   231,
     232,   233,   234,   235,   236,   237,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   244,   245,   246,   247,     0,     0,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   254,
       0,     0,     0,     0,     0,   209,   166,     0,   255,    25,
     887,   256,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   423,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   255,    25,     0,   256,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,   266,     0,     0,     0,   267,     0,     0,
    1118,     0,   269,   270,   271,     0,   272,   273,   274,     0,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,   644,
       0,     0,     0,     0,     0,   277,     0,     0,     0,     0,
     645,     0,     0,     0,   327,     0,     0,   280,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,   266,
    1119,     0,     0,   267,     0,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   424,     0,     0,     0,     0,
       0,   277,   209,   166,     0,     0,   367,     0,     0,   210,
     211,   212,     0,   280,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   423,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,     0,     0,     0,     0,   248,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,   255,    25,     0,   256,   209,   166,     0,  1340,     0,
       0,     0,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   423,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   252,   253,   254,    43,    44,    45,    46,
       0,     0,    48,     0,   255,    25,     0,   256,     0,     0,
     771,    56,     0,     0,    59,   772,     0,   773,   774,     0,
     775,     0,     0,     0,  1051,     0,   266,     0,     0,     0,
     267,     0,     0,     0,     0,   269,   270,   271,    80,   272,
     273,   274,  1052,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   424,    95,    96,    97,     0,     0,   277,     0,
       0,     0,     0,   367,  1105,     0,     0,     0,     0,     0,
     280,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1157,     0,     0,     0,     0,     0,   266,
       0,     0,     0,   267,     0,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   424,     0,     0,     0,     0,
       0,   277,   209,   166,     0,  1503,   367,     0,     0,   210,
     211,   212,     0,   280,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   423,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,     0,     0,     0,     0,   248,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
     252,   253,   254,     0,     0,     0,     0,     0,     0,     0,
       0,   255,    25,     0,   256,   209,   166,     0,  1566,     0,
       0,     0,   210,   211,   212,     0,     0,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   423,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   252,   253,   254,    43,    44,    45,    46,
       0,     0,    48,     0,   255,    25,     0,   256,     0,     0,
     771,    56,     0,     0,    59,   772,     0,   773,   774,     0,
     775,     0,     0,     0,     0,     0,   266,     0,     0,     0,
     267,     0,     0,     0,     0,   269,   270,   271,    80,   272,
     273,   274,     0,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   424,    95,    96,    97,     0,     0,   277,     0,
       0,     0,     0,   367,     0,     0,     0,     0,     0,     0,
     280,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,     0,     0,     0,     0,     0,   266,
       0,     0,     0,   267,     0,     0,     0,     0,   269,   270,
     271,     0,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   424,     0,     0,     0,     0,
       0,   277,   209,   166,     0,     0,   367,     0,     0,   210,
     211,   212,     0,   280,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   423,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,     0,     0,     0,     0,   248,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     252,   253,   254,     0,     0,     0,     0,     0,   209,   166,
       0,   255,    25,     0,   256,   210,   211,   212,     0,     0,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   423,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,   246,   247,     0,     0,     0,
       0,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   253,   254,     0,
       0,     0,     0,     0,     0,     0,     0,   255,    25,     0,
     256,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,   266,     0,     0,     0,
     267,     0,     0,  1168,     0,   269,   270,   271,     0,   272,
     273,   274,     0,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,   424,     0,     0,     0,     0,     0,   277,     0,
       0,     0,     0,   367,  1620,     0,     0,     0,     0,     0,
     280,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,   266,  1169,     0,     0,   267,     0,     0,     0,
       0,   269,   270,   271,     0,   272,   273,   274,     0,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   275,   424,     0,
       0,     0,     0,     0,   277,   209,   166,     0,     0,   367,
    1956,     0,   210,   211,   212,     0,   280,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   423,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   386,     0,     0,     0,     0,     0,
     244,   245,   246,   247,     0,     0,     0,     0,   248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,     0,   255,    25,     0,   256,   387,   388,
     389,   390,   391,   392,   393,   394,   395,     0,     0,     0,
       0,   396,   397,   398,   399,     0,     0,     0,     0,   400,
     401,   402,   403,     0,     0,     0,     0,   404,     0,   405,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   406,     0,     0,   407,     0,     0,     0,
     303,     0,     0,   304,     0,     0,   305,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   437,     0,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,   266,
       0,   601,     0,   267,     0,     0,     0,     0,   269,   270,
     271,  1170,   272,   273,   274,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   166,   386,     0,     0,
       0,     0,     0,     0,   275,   424,     0,     0,     0,     0,
       0,   277,     0,     0,     0,     0,   367,   408,   409,   410,
       0,     0,     0,   280,     0,     0,     0,     0,   411,     0,
       0,     0,   412,     0,   413,   118,     0,     0,     0,     0,
       0,   387,   388,   389,   390,   391,   392,   393,   394,   395,
       7,     8,     0,     0,   396,   397,   398,   399,     0,     0,
     443,   444,   400,   401,   402,   403,     0,  -572,     0,  1598,
     404,     0,   405,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   406,     0,     0,   407,
       0,     0,     0,   303,     0,     0,   304,     0,     0,   305,
       0,   306,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     437,     0,     0,     0,     0,     0,     7,     8,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   771,    56,
       0,     0,    59,   772,     0,   773,   774,     0,   775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,     0,
     408,   409,   410,     0,     0,     0,     0,     0,     0,     0,
       0,   411,     0,     0,     0,   412,     0,   413,   118,     0,
       0,    95,    96,    97,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     7,     8,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
    1791,     0,     0,     0,   771,    56,     0,     0,    59,   772,
       0,   773,   774,     0,   775,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   992,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   771,    56,     0,     0,    59,
     772,     0,   773,   774,     0,   775,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1040,    80,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,    95,    96,
      97,     0,     0,     0,     0,   771,    56,     0,     0,    59,
     772,     0,   773,   774,     0,   775,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    95,    96,
      97,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,  1042,     0,   771,    56,     0,     0,    59,
     772,     0,   773,   774,     0,   775,     7,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,    95,    96,
      97,     0,     0,  1243,   771,    56,     0,     0,    59,   772,
       0,   773,   774,     0,   775,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    95,    96,    97,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,  1245,   771,    56,     0,     0,    59,   772,
       0,   773,   774,     0,   775,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,    95,    96,    97,
       0,     0,  1246,   771,    56,     0,     0,    59,   772,     0,
     773,   774,     0,   775,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    95,    96,    97,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,  1265,   771,    56,     0,     0,    59,   772,     0,
     773,   774,     0,   775,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,    95,    96,    97,     0,
       0,  1284,   771,    56,     0,     0,    59,   772,     0,   773,
     774,     0,   775,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    95,    96,    97,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,  1299,   771,    56,     0,     0,    59,   772,     0,   773,
     774,     0,   775,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,    95,    96,    97,     0,     0,
    1332,   771,    56,     0,     0,    59,   772,     0,   773,   774,
       0,   775,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    95,    96,    97,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
    1495,   771,    56,     0,     0,    59,   772,     0,   773,   774,
       0,   775,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    80,
       0,     0,     0,     0,     0,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,    95,    96,    97,   601,     0,  2137,
      -4,    -4,    -4,     0,     0,     0,     0,  1171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,  2194,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,     0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     6,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       7,     8,     0,     0,     0,     0,     0,     0,    -4,     0,
      -4,     0,     0,     0,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     9,    10,    11,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1176,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
       0,    15,    16,     0,     0,     0,    17,     0,     0,     0,
       0,    18,    19,    20,    21,    22,     0,    23,    24,     0,
      25,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,    42,    43,    44,    45,    46,    47,     0,
      48,     0,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     0,     0,
      65,    66,    67,     0,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
      91,    92,     0,     0,     0,    93,     0,     0,     0,     0,
      94,    95,    96,    97,   166,   386,    98,     0,    99,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
     114,   115,   116,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   118,     0,     0,     0,     0,     0,   387,
     388,   389,   390,   391,   392,   393,   394,   395,     0,     0,
       0,     0,   396,   397,   398,   399,   166,   386,     0,     0,
     400,   401,   402,   403,     0,     0,     0,     0,   404,     0,
     405,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,     0,     0,   407,     0,     0,
       0,   303,   417,   386,   304,     0,     0,   305,     0,   306,
       0,   387,   388,   389,   390,   391,   392,   393,   394,   395,
      46,     0,     0,     0,   396,   397,   398,   399,     0,     0,
       0,     0,   400,   401,   402,   403,     0,     0,   437,   386,
     404,     0,   405,     0,     0,     0,     0,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   406,     0,     0,   407,
     396,   397,   398,   399,     0,     0,     0,     0,   400,   401,
     402,   403,     0,     0,     0,     0,   404,     0,   405,     0,
       0,     0,     0,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   406,     0,     0,   407,   396,   397,   398,   399,
       0,     0,     0,     0,   400,   401,   402,   403,   408,   409,
     410,     0,   404,     0,   405,     0,     0,     0,     0,   411,
       0,     0,     0,   412,     0,   413,   118,     0,   406,     0,
       0,   407,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1177,     0,     0,     0,     0,     0,
     408,   409,   410,     0,     0,     0,     0,     0,     0,     0,
       0,   411,     0,     0,     0,   412,     0,   413,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   408,   409,   410,     0,
       0,     0,     0,     0,     0,     0,     0,   411,     0,     0,
       0,   412,     0,   413,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,   408,   409,   410,     0,   601,     0,     0,     0,
       0,     0,     0,   411,     0,     0,  1179,   412,     0,   413,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1293,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1314,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1399,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1402,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1497,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1498,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1543,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1671,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1672,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1673,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1819,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1943,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1944,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1976,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2048,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2105,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2106,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2121,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2155,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2182,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2187,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2188,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,   831,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,  1086,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  1144,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  1191,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    1192,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,  1236,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  1268,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  1282,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  1289,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,  1346,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  1366,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,  1452,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  1453,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  1499,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    1572,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,  1873,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  1884,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  1923,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  1997,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,  2013,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  2025,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,  2049,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
       0,     0,  2084,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
       0,  2094,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,     0,     0,
    2095,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,     0,  2119,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,     0,     0,  2168,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,     0,     0,  2207,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,     0,     0,  2225,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,     0,     0,  2243,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,     0,     0,  2244,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,     0,   730,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,     0,
     951,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,     0,  1990,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,   757,     0,   758,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,  1014,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,  1062,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,  1215,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,  1283,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
    1285,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,     0,     0,  1291,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   729,   597,   598,   599,   600,     0,     0,     0,     0,
     601,     0,     0,     0,  1292,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   729,   597,
     598,   599,   600,     0,     0,     0,     0,   601,     0,     0,
       0,  1381,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   729,   597,   598,   599,   600,
       0,     0,     0,     0,   601,     0,     0,     0,  1395,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   729,   597,   598,   599,   600,     0,     0,     0,
       0,   601,     0,     0,     0,  1601,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
       0,     0,  1692,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   729,   597,   598,   599,
     600,     0,     0,     0,     0,   601,     0,     0,     0,  1745,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   729,   597,   598,   599,   600,     0,     0,
       0,     0,   601,     0,     0,     0,  1935,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     729,   597,   598,   599,   600,     0,     0,     0,     0,   601,
       0,     0,     0,  1980,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   729,   597,   598,
     599,   600,     0,     0,     0,     0,   601,     0,     0,     0,
    1998,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   812,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     813,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   814,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     816,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   817,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     818,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   820,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     821,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   822,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     823,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   824,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     825,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   826,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     828,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   829,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     830,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   899,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
     933,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,   981,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1002,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1004,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1005,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1006,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1012,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1013,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1050,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1061,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1124,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1128,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1140,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1214,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1224,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1225,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1226,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1235,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1237,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1238,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1267,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1269,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1270,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1271,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1272,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1273,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1274,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1275,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1281,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1380,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1394,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1602,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1636,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1637,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1638,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1639,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1679,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1691,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1806,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1808,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1811,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1818,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1874,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1883,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    1908,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  1979,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    2046,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  2047,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601,     0,
    2181,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   729,   597,   598,   599,   600,     0,
       0,     0,     0,   601,     0,  2222,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   729,
     597,   598,   599,   600,     0,     0,     0,     0,   601
};

static const yytype_int16 yycheck[] =
{
       3,   640,   641,  1266,   320,    63,  1730,    69,    70,     4,
      72,     3,  1262,   332,     4,   158,  1774,     6,  1776,     6,
       4,   144,    25,  1459,     6,     6,    26,     4,    28,   447,
       5,    25,   351,     6,  1761,     5,     4,   255,   754,     6,
     142,     5,  1959,     4,   760,   263,   142,     5,     7,     4,
       6,     4,    55,     4,     4,     4,     4,     4,   160,     4,
       4,     6,   242,   243,   107,     4,     0,   169,   170,   171,
     251,   252,     7,   175,   176,    36,    37,   258,   163,   259,
       4,    84,     4,    36,    37,     9,    36,    37,   131,   104,
      93,   107,   107,   108,   109,    98,   192,    36,    37,  1826,
     107,   420,   255,   422,   189,   120,   109,     6,   242,   243,
     263,   430,   242,   243,    14,   131,   251,   252,   255,     9,
     205,   206,  1846,   254,     9,   260,   263,   258,   255,   263,
     257,     7,   101,   263,     9,     9,   263,     6,    93,   247,
     248,   144,   242,   243,   144,   253,   149,   150,   151,   110,
     111,   120,     6,   145,   101,   158,   101,   259,   105,   260,
     110,   111,   263,   263,   111,   112,   255,   114,   115,   184,
       9,   110,   111,   176,   263,   254,   197,   256,   242,   243,
     257,   260,     7,     6,   263,   206,   263,   605,   135,   192,
       9,   254,   250,   251,   197,   177,   177,  2114,   201,   263,
     255,   254,   257,   206,   207,   208,   257,     6,   263,   204,
     104,   258,   263,   107,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   200,   246,   247,  1684,   226,
     237,   238,   254,   242,   243,   255,   256,     7,   226,   262,
     256,   323,   324,  1987,   254,  1515,     6,   267,   268,   331,
     332,   226,   256,   276,   258,   226,   279,   280,   262,   300,
     301,   302,   226,   258,   261,   258,   280,   109,   258,   111,
     258,   258,   295,   296,   258,     4,   299,   300,   301,   302,
     258,   260,   226,   258,   226,   254,   254,   258,   254,     3,
     629,   314,   631,   632,     6,   318,   734,   320,  2042,   254,
       6,   256,   144,   344,   345,   346,   255,   251,   252,   648,
     254,   260,   256,   255,   258,   257,   260,   251,   252,   342,
     361,   344,   345,   346,   104,  1061,  1062,   107,   667,   171,
     768,   227,   228,   229,   230,   254,     6,    55,   361,   258,
     120,   251,   252,     7,   254,   368,   256,   785,    62,   254,
     260,   256,   691,   242,   243,   251,   252,   795,     6,   254,
     254,   256,   256,     7,   260,   260,   260,   387,   388,   389,
       7,  2149,   255,   393,   394,   395,   396,   397,   398,   399,
     263,   401,   227,   228,   229,   230,   406,   407,   551,     6,
     410,   730,   251,   252,   255,   254,   257,   256,   257,   242,
     243,   260,   263,   423,   427,   428,   251,   252,     8,   432,
     433,   104,   251,   252,   107,   254,   109,   256,   237,   238,
     258,   260,   242,   243,   262,   448,   242,   243,   242,   243,
     144,     6,   455,   242,   243,   149,   150,   151,   255,   254,
    2184,   256,   254,   263,   158,   256,   263,   263,   263,   263,
     179,   180,   181,   182,   263,   478,   254,   227,   228,   229,
     230,     4,   191,   901,   193,   194,   195,   196,   197,   254,
     254,     4,   201,   202,   258,   204,   242,   243,   192,   242,
     243,   251,   252,   254,   507,   242,   243,   258,   107,   207,
    2234,   242,   243,   255,   208,   242,   243,   263,   242,   243,
     263,   263,   254,    36,    37,   255,   263,   257,   531,   254,
     242,   243,   263,   263,   122,   255,   263,   540,   541,   263,
     561,  1977,   545,   263,   547,   548,   549,   550,   551,   254,
     259,   263,   254,   556,   256,   249,   699,   560,   561,   562,
     563,   564,   565,   566,   262,   568,   254,   570,   242,   243,
     264,   265,   566,   107,   568,   109,   638,   639,   578,   242,
     243,   643,   258,   227,   228,   229,   230,   259,   255,   263,
     257,   263,   254,   596,   242,   243,   263,   110,   111,   602,
     263,   299,   254,   227,   228,   229,   230,   251,   252,   254,
     227,   228,   229,   230,   436,   263,   314,   242,   243,   259,
     318,   624,   625,   263,   147,   148,   149,   150,   242,   243,
     153,   754,   258,   255,   242,   243,   955,  1276,   263,   162,
     254,   263,   165,   259,   258,  1063,   254,   263,   640,   641,
     258,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   258,
     673,   674,   675,   253,   259,   678,   189,   190,   263,   259,
     242,   243,   244,   245,   246,   247,   248,     4,   242,   243,
     255,   253,   257,   258,   697,   698,   699,   700,   701,   702,
     703,   704,   705,   142,   707,   708,   709,   710,   711,   263,
     713,   714,   715,   716,   717,   254,   774,   720,     6,    36,
      37,   160,   716,   259,   142,   242,   243,   263,   731,   254,
     169,   170,   171,   427,   432,   433,   175,   176,   242,   243,
     254,   744,   160,   437,   104,   567,   263,   107,   254,   109,
     448,   169,   170,   171,     6,     7,   759,   175,   176,   263,
     120,   254,   765,   256,   101,   459,   254,   104,   101,  1485,
     107,   104,   109,   259,   107,   242,   243,   263,   781,   782,
    1198,   142,  1200,   120,   787,     6,   789,   120,   259,   792,
     793,   258,   263,   110,   111,  1213,   799,   254,   801,   160,
     259,   142,   242,   243,   263,   242,   243,   930,   169,   170,
     171,   147,   148,   109,   175,   176,   254,   153,   258,   160,
     259,   258,   258,   255,  1242,   257,   147,   148,   169,   170,
     171,   834,   153,   836,   175,   176,   244,   245,   246,   247,
     248,   259,   254,   259,   259,   253,   101,   263,   263,   104,
     548,   545,   107,   547,   109,   549,   550,   551,   260,   107,
     262,  1577,   560,   254,   562,   256,   104,   258,   871,   563,
     564,  1587,   189,   190,   258,  2138,   251,   252,   881,   254,
     254,   256,   256,   258,  1302,  1303,   251,   252,   259,   254,
     712,   256,   263,   107,   104,   259,   958,   897,   259,   263,
     903,   251,   252,   965,   254,   258,   256,   969,   259,  1327,
     259,   258,   263,   259,   263,  1333,   919,   263,   104,   259,
    2170,   259,     4,   263,  1047,   263,   254,   259,   931,   259,
     930,   263,  2195,   263,  1352,   107,   259,   940,  1061,  1062,
     263,   259,   254,   259,   256,   263,   259,   263,   951,   259,
     263,   107,   646,   263,   259,  1078,   259,     4,   263,   259,
     263,  1379,  2212,   263,   259,   259,   259,   259,   263,   263,
     263,   263,     4,   259,   259,  1393,   670,   263,   263,   259,
     259,   259,  1400,   263,   263,   263,   259,   259,   259,   811,
     263,   263,   263,   259,   259,   259,   259,   263,   263,   263,
     263,     4,     6,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   254,   707,   708,   709,   710,   254,   259,   713,
     714,   715,   263,   259,   259,   254,   259,   263,   263,   723,
     263,   259,   726,   259,   259,   263,     6,   263,   263,   259,
    1356,   259,   258,   263,   738,   263,   744,   259,   259,   254,
     259,   263,   263,  1056,   263,     4,   259,     6,   259,  1121,
     263,  1064,   263,   259,   259,   242,   243,   263,   263,  1072,
     255,   254,   257,   258,   256,   254,  1715,  1716,   256,   773,
       6,   775,  1085,   258,     6,   254,   262,  1090,   262,     9,
     254,  1214,  1215,   254,   254,     4,     5,   254,   792,   254,
     254,   254,   192,   254,   254,   192,   258,   801,   192,  1109,
     258,   131,   254,   254,   254,   254,   192,   254,   254,  1122,
    1123,   943,  1125,  1126,  1127,   258,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,   254,   258,  1141,   254,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   258,
       4,   258,   258,    62,    63,    64,    65,   258,   254,   254,
     254,    70,    71,    72,    73,   254,   254,     6,   254,    78,
       6,    80,     6,   254,     6,   258,   256,   256,  1181,  1182,
    1183,   258,     6,   258,   258,    94,   258,   256,    97,   256,
     258,   192,   101,   254,   254,   104,   254,   254,   107,   254,
     109,   254,  1205,     6,   256,   903,  1206,     6,   258,     6,
       8,   120,     6,     8,   258,     7,     6,   258,  1221,  1222,
    1223,   258,     6,   258,    96,   259,   255,   263,     7,   138,
     263,     6,     6,   255,   258,   258,   253,   258,    67,   258,
       8,     7,   940,  1065,   260,     7,  1565,   254,     6,   255,
    1569,     6,     6,   258,     7,     7,     6,  1380,  1381,     6,
     954,   259,   956,   957,  1580,   189,   258,   255,   259,   259,
     257,     6,   258,     7,  1277,   260,   970,     6,   256,   254,
       6,   258,     6,     6,  1276,     6,     6,   255,     7,   256,
       7,  1294,  1295,  1296,     7,     7,   990,     7,     7,   208,
     209,   210,  1305,     8,     7,     7,     7,  1310,     7,     7,
     219,  1314,     7,     7,   223,  1009,   225,   226,     7,     7,
    1323,     7,  1325,   258,     6,  1328,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   255,
    1343,   255,   257,   253,   263,   263,   255,   259,   257,   258,
     263,  1045,   263,  1356,  1993,     7,   259,     7,  1056,   260,
     258,   258,  1780,  1363,  1364,     4,     6,   260,   259,   259,
     142,   258,     7,     6,  1072,     7,     7,     7,  1381,   260,
     255,   255,     9,  1386,   263,  1388,   263,   263,   255,   257,
     260,   262,   192,     7,   163,   259,  1090,   258,     6,     6,
       6,    49,  1405,    49,   260,   254,   258,   254,   258,   260,
     254,   254,   260,     7,     7,     7,   192,  1420,   263,     7,
     255,  1424,     7,     7,  1122,  1123,     6,  1125,  1126,  1127,
     255,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,   263,     7,     7,     7,  1588,  1589,     7,     7,   119,
       4,   258,  1514,     6,  1577,     7,     6,   258,   254,  1459,
       7,     7,     7,     7,     7,     7,     7,   101,  1468,     6,
       6,     6,  1788,     7,     7,     6,  1479,  1480,  1481,   107,
       6,     4,   263,  1181,  1487,  1488,  1489,     6,  1182,  1183,
     261,   255,   259,   263,     6,   258,     7,   258,   258,     6,
     256,     6,  1505,     6,     6,   254,   254,  1205,   259,     6,
       6,     6,   258,  1516,   257,   260,     6,     6,   135,   263,
       6,  1524,     6,  1221,     6,  1528,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,     6,     6,     6,     6,   253,     6,
    1244,     6,     6,     6,   259,     6,     5,     4,   255,   255,
       6,     6,     6,   188,     7,   258,   258,  1690,     6,   259,
       7,   258,     6,   258,   258,   256,     6,  1580,   258,  1277,
    1642,  1403,   258,  1405,   258,  1588,  1589,   258,     6,   258,
     258,  1594,   258,   258,     6,     6,  1294,  1295,  1296,   263,
       6,   263,   255,   263,   258,   263,     6,   254,     7,  1612,
       6,   260,     6,   258,     6,   259,  1310,     6,   254,  1622,
    1314,     4,     7,     5,  1627,   254,  1626,     6,     6,  1323,
       6,  1325,     6,     8,  1328,     6,     6,     6,   142,   105,
       6,   263,   258,  1337,   255,  1343,   258,     6,  1791,   258,
     144,     6,     6,   263,   142,   149,   150,   151,     6,   142,
       6,     6,   263,   263,   255,     6,     6,     6,   263,  1731,
    1732,  1733,  1734,  1735,  1736,   258,   258,     6,     6,     6,
       6,     6,   258,  2002,     7,     6,   258,  1381,   146,   258,
     258,     5,   258,   255,     6,     6,     6,   258,   192,  1702,
       6,   259,   259,     7,  1707,  1708,     6,  1405,   187,   258,
       6,   259,     7,  2029,   208,   255,     6,     6,     6,     6,
     259,   259,  1420,  1715,  1716,     6,  1424,  1730,   260,   258,
       6,     6,   259,  1736,     6,     6,     6,   255,  1741,  1561,
       6,   258,   190,     6,   258,  1748,     6,   255,   254,   259,
     259,     6,     6,  1756,     6,   142,  1759,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   258,  1777,     6,     6,   253,  1781,   259,
    2099,  1479,  1480,  1481,   258,  1788,   258,  1790,  1791,  1487,
    1488,  1489,     6,   258,   258,   258,     6,     6,     6,   255,
    1622,     6,     6,     6,     6,     6,     6,  1505,     6,   259,
       6,     6,     6,     6,     6,     6,     6,   259,  1516,   258,
    2139,     6,   258,  1826,  1392,   258,  1524,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,  2151,  1846,  1454,  1960,   253,  1634,  1920,   475,
    1698,     3,  1419,     3,  1857,  1858,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,  1074,     3,     6,     3,   253,  1882,
     255,   617,   257,  1989,     3,  1781,  1589,  1558,  1761,  1711,
     792,  1894,    -1,    -1,  1588,  1589,  1594,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1909,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1612,    -1,
      -1,    -1,    -1,    -1,  1622,    -1,     8,    -1,    -1,    -1,
      -1,    -1,  1754,   427,    -1,    -1,    -1,    -1,    -1,  1761,
    1762,    -1,    -1,  1946,  2006,  2007,  2008,  2009,  2010,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1961,    -1,
    1782,    -1,    -1,  1966,    -1,    -1,  1969,  1970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1987,    -1,    -1,  1990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2001,    -1,
      -1,  1993,  2005,    -1,  1702,    -1,    -1,    -1,  2070,    -1,
      -1,    -1,  2074,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2029,    -1,    -1,    -1,
      -1,    -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,  2042,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1748,   545,    -1,   547,    -1,   549,   550,    -1,    -1,    -1,
      -1,    -1,  1756,  2125,    -1,  1759,    -1,  2129,  2071,   563,
     564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1777,
    1774,    -1,  1776,  2145,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1790,    -1,    -1,    -1,    -1,  1791,    -1,    -1,
    1922,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
    2123,     6,    -1,   253,    -1,    -1,    -1,    -1,  2190,  2191,
      -1,    -1,  1826,    -1,    -1,    -1,    -1,    -1,  2141,  2142,
    2143,  2144,  2145,  1965,    -1,    -1,    -1,    -1,  1846,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2184,    -1,    -1,  1882,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2200,    -1,     6,
      -1,    -1,    -1,    -1,   698,    -1,   700,   701,   702,   703,
     704,   705,    -1,   707,   708,   709,   710,    -1,  2221,   713,
     714,   715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2234,    -1,    -1,    -1,    -1,    -1,  2240,  2241,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,  1946,    -1,
    2253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1961,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,  1987,
      -1,    -1,    -1,  2115,    -1,    -1,    -1,    -1,   792,    -1,
      -1,    -1,    -1,  2001,   177,   178,   179,   801,   181,   182,
     183,    -1,   185,   186,   187,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2042,    -1,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,  2071,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2083,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,   276,   277,   278,   279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,   295,   296,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   316,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,   326,   327,  2149,    -1,    -1,    -1,   332,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   342,
     343,    -1,    -1,    -1,    -1,    -1,    -1,  2171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2184,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   367,   368,    -1,    -1,    -1,   372,
     373,   374,    -1,   376,    -1,    -1,    -1,   380,   381,   382,
      -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2240,  2241,    -1,    -1,
      -1,   424,    -1,    -1,    -1,   428,   429,    -1,    -1,  2253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   445,   446,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1090,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,   481,   482,
     483,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,   492,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   506,   507,    -1,    -1,    -1,   511,    -1,
      -1,    -1,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,    -1,
     543,   544,   201,   546,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,    -1,   558,   559,    -1,  1182,  1183,
      -1,    -1,   565,    -1,    -1,    -1,    -1,   570,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,    -1,
     603,   604,    -1,    -1,    -1,    -1,    -1,    -1,   611,   612,
     613,     6,    -1,    -1,    -1,    -1,   619,   620,   621,   622,
      -1,   624,   625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   295,   296,    -1,    -1,
     643,   644,   645,    -1,    -1,    -1,   649,   650,   651,   652,
     653,   654,   655,   656,   657,    -1,     6,    -1,    -1,    -1,
     663,   664,    -1,   666,    -1,    -1,   669,    -1,    -1,    -1,
     673,   674,   675,   676,    -1,   678,   679,   680,   681,    -1,
      -1,    -1,    -1,   342,    -1,    -1,  1310,    -1,    -1,    -1,
    1314,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1323,
      -1,  1325,    -1,   706,  1328,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,   720,    -1,    -1,
      -1,    -1,    -1,    -1,   727,    -1,   729,    -1,    -1,   732,
     733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   741,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   759,  1381,   761,    -1,
      -1,    -1,    -1,   766,   767,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   781,    -1,
     783,   784,    -1,    -1,   787,    -1,   789,   790,    -1,    -1,
      -1,   794,    -1,   796,    -1,    -1,    -1,    -1,    -1,   802,
      -1,    -1,    -1,   806,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,   832,
      -1,   834,    -1,   836,    -1,    -1,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   871,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   881,   882,
     883,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     201,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   570,    -1,    -1,    -1,    -1,   919,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   931,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   939,    -1,    -1,    -1,
     943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   951,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   959,   960,    -1,    -1,
      -1,    -1,   965,    -1,    -1,   624,   625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   276,    -1,    -1,   279,   982,
      -1,    -1,   985,    -1,    -1,    -1,    -1,    -1,  1612,    -1,
      -1,    -1,    -1,    -1,   295,   296,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1008,    -1,  1010,  1011,    -1,
      -1,    -1,    -1,    -1,   673,   674,   675,    -1,    -1,   678,
      -1,    -1,    -1,    -1,    -1,    -1,  1029,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
      -1,    -1,    -1,    -1,    -1,    -1,  1059,    -1,    -1,    -1,
      -1,   720,    -1,  1066,    -1,    -1,    -1,   368,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1079,  1080,    -1,    -1,
      -1,    -1,  1085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1116,  1117,  1118,  1119,    -1,    -1,    -1,
      -1,    -1,   781,    -1,    -1,    -1,    -1,   428,   787,     6,
     789,    -1,  1756,    -1,    -1,  1759,    -1,    -1,  1141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1167,  1168,  1169,  1170,  1171,    -1,
      -1,    -1,    -1,  1176,  1177,    -1,  1179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1193,  1194,    -1,    -1,    -1,    -1,    -1,    -1,  1201,  1202,
      -1,    -1,     6,    -1,    -1,    -1,   507,  1210,  1211,    -1,
      -1,    -1,   871,  1216,  1217,    -1,    -1,    -1,    -1,  1222,
    1223,    -1,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     531,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,   540,
     541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1256,    -1,    -1,    -1,    -1,    -1,    -1,
     919,    -1,    -1,    -1,   565,    -1,    -1,    -1,    -1,   570,
      -1,    -1,   931,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1293,    -1,   951,    -1,    -1,   596,    -1,    -1,    -1,    -1,
      -1,    -1,  1305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1313,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   624,   625,    -1,    -1,    -1,    -1,    -1,
      -1,  1334,  1335,    -1,    -1,    -1,  1339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1350,    -1,    -1,
    1353,    -1,    -1,    -1,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   673,   674,   675,    -1,   253,   678,    -1,  1382,
      -1,    -1,  1385,  1386,  1387,  1388,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1396,    -1,    -1,  1399,    -1,  1401,  1402,
    1403,    -1,    -1,  1406,  1407,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   720,
      -1,    -1,    -1,    -1,    -1,    -1,  1085,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   759,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
     781,   253,  1141,  1486,    -1,    -1,   787,    -1,   789,    -1,
      -1,    -1,    -1,  1496,  1497,  1498,    -1,    -1,    -1,    -1,
      -1,    -1,  1505,    -1,  1507,    -1,    -1,    -1,    -1,    -1,
      -1,  1514,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1528,    -1,    -1,    -1,    -1,
      -1,  1534,  1535,   834,    -1,   836,    -1,    -1,    -1,    -1,
    1543,  1544,  1545,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1563,    -1,    -1,  1222,  1223,    -1,    -1,    -1,    -1,    -1,
     871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     881,  1584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1592,
    1593,    -1,    -1,    -1,    -1,     6,    -1,  2221,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,  2240,  2241,   919,   117,
     118,   119,   120,    -1,  1627,   123,    -1,    -1,    -1,  2253,
     931,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,  1305,    -1,    -1,    -1,
     951,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,  1671,  1672,
    1673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1682,
      -1,    -1,    -1,    -1,  1687,  1688,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,
      -1,    -1,    -1,    -1,  1707,  1708,  1709,    -1,  1711,    -1,
      -1,    -1,    -1,    -1,  1717,  1718,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1386,    -1,  1388,
      -1,    -1,    -1,  1736,    -1,    -1,    -1,    -1,  1741,  1742,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1754,    -1,    -1,  1757,    -1,    -1,    -1,  1761,    -1,
      -1,   259,    -1,    -1,    -1,    -1,    -1,  1770,  1771,    -1,
    1773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1783,    -1,    -1,    -1,  1085,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1797,    -1,    -1,    -1,    -1,  1802,
    1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1816,    -1,    -1,  1819,  1820,    -1,  1822,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
    1141,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1857,  1858,    -1,    -1,    -1,    -1,
      -1,  1864,  1865,    -1,    -1,    -1,    -1,    -1,    -1,  1528,
      -1,    -1,   450,  1876,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1885,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1894,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1905,  1906,    -1,    -1,  1909,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1222,  1223,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1943,  1944,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,  1964,    -1,    -1,   253,    -1,  1969,  1970,  1971,    -1,
      -1,    -1,    -1,  1976,    -1,     6,    -1,    -1,   556,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1990,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2005,    -1,  1305,     6,    -1,    -1,    -1,    -1,
      -1,  2014,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,
      -1,    -1,    -1,    -1,    -1,    -1,  2039,    -1,    -1,    -1,
      -1,    -1,  2045,    -1,    -1,  2048,    -1,    -1,  1707,  1708,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,  2079,   257,    -1,    -1,
      -1,    -1,  1741,   263,    -1,  1386,    -1,  1388,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2105,  2106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2120,  2121,    -1,
    2123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2136,    -1,    -1,    -1,    -1,  2141,  2142,
    2143,  2144,  2145,    -1,    -1,    -1,    -1,    -1,  2151,    -1,
      -1,    -1,  2155,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,  2182,
      -1,    -1,    -1,    -1,  2187,  2188,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2200,  1857,  1858,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,  2227,  2228,    -1,  1528,    -1,    -1,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
    1909,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,    -1,   853,   854,   855,   856,    -1,
     858,   859,   860,   861,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   874,    -1,   876,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   886,    -1,
    1969,  1970,    -1,    -1,    -1,   893,   894,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   902,    -1,  1627,    -1,    -1,    -1,
      -1,  1990,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,  2005,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,  1707,  1708,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,  1736,    -1,  1015,  1016,  1017,
    1741,    -1,    -1,  1021,  1022,     6,    -1,  1025,  1026,  1027,
    1028,    -1,  1030,    -1,    -1,    -1,    -1,  1035,    -1,    -1,
      -1,    -1,    -1,    -1,  2123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2141,  2142,  2143,  2144,  2145,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,  1115,    -1,    -1,
     207,  2200,  1120,    -1,   211,    -1,    -1,    -1,    -1,   216,
     217,   218,    -1,   220,   221,   222,  1857,  1858,    -1,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,   258,    -1,  1894,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1909,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1219,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,  1969,  1970,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,  1990,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,  2005,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     6,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,  1362,    -1,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,  2123,    -1,    -1,    -1,  1404,    -1,    -1,    -1,
      -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
    2141,  2142,  2143,  2144,  2145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1438,  1439,  1440,  1441,  1442,  1443,  1444,    -1,    -1,    -1,
      -1,  1449,  1450,    -1,    -1,    -1,    -1,  1455,    -1,  1457,
      -1,    -1,    -1,  1461,    -1,    -1,  1464,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   200,    -1,  1475,    -1,  2200,
      -1,    -1,   207,   208,   209,   210,   211,    -1,    -1,    -1,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,
      -1,    -1,    -1,    -1,   249,    -1,   251,   252,    -1,   254,
      -1,   256,    -1,    -1,    -1,   260,   261,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1549,    -1,  1551,    -1,    -1,    -1,  1555,    -1,  1557,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
    1588,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,
      97,  1689,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,
      -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,    -1,   153,   154,   155,   156,
     157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1793,    -1,    -1,  1796,    -1,
     207,   208,   209,   210,   211,   212,    -1,    -1,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,     7,   225,   226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,   254,    -1,  1847,
    1848,   258,  1850,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,  1913,  1914,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    76,    77,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,  1962,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,
     212,    -1,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   254,     3,     4,     5,   258,    -1,    -1,   261,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2209,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,    -1,    -1,   165,    -1,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,   217,   218,    -1,
     220,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,   254,     3,     4,    -1,   258,    -1,
       8,   261,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,   217,
     218,    -1,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,   254,     3,     4,     5,
      -1,   259,    -1,   261,    10,    11,    12,    -1,    -1,    15,
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
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
     216,   217,   218,    -1,   220,   221,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,     3,
       4,    -1,   258,    -1,    -1,   261,    10,    11,    12,    -1,
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
      -1,   165,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,   216,   217,   218,    -1,   220,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     254,     3,     4,    -1,   258,   259,    -1,   261,    10,    11,
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
     162,    -1,    -1,   165,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,   216,   217,   218,    -1,   220,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   254,     3,     4,    -1,   258,    -1,    -1,   261,
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
      -1,    -1,   162,    -1,    -1,   165,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,   217,   218,    -1,
     220,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,   254,     3,     4,    -1,   258,    -1,
      -1,   261,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,   217,
     218,    -1,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,   254,     3,     4,    -1,
     258,    -1,    -1,   261,    10,    11,    12,    -1,    -1,    15,
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
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
     216,   217,   218,    -1,   220,   221,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,     3,
       4,    -1,    -1,   259,    -1,   261,    10,    11,    12,    -1,
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
      -1,   165,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,   216,   217,   218,    -1,   220,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     254,     3,     4,    -1,   258,    -1,    -1,   261,    10,    11,
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
     162,    -1,    -1,   165,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,   216,   217,   218,    -1,   220,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   254,     3,     4,    -1,   258,    -1,    -1,   261,
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
      -1,    -1,   162,    -1,    -1,   165,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,   217,   218,    -1,
     220,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,   254,     3,     4,    -1,   258,    -1,
       8,   261,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,   216,   217,
     218,    -1,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,    -1,   254,     8,    -1,    10,
      11,    12,    -1,   261,    15,    16,    17,    18,    19,    20,
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
      -1,   162,    -1,    -1,   165,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
     211,   212,    -1,    -1,    -1,   216,   217,   218,    -1,   220,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,     3,
       4,    -1,    -1,   254,    -1,    -1,    10,    11,    12,    -1,
     261,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,   165,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,   216,   217,   218,    -1,   220,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     254,     3,     4,    -1,   258,    -1,    -1,   261,    10,    11,
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
     162,    -1,    -1,   165,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,   216,   217,   218,    -1,   220,   221,
     222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   254,     3,     4,    -1,   258,    -1,    -1,   261,
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
      -1,    -1,   162,    -1,    -1,   165,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,   216,   217,   218,    -1,
     220,   221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
       3,     4,     5,    -1,   254,    -1,    -1,    10,    11,    12,
      -1,   261,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,    -1,
      -1,    -1,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,   225,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,
     243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,   258,    -1,    -1,   261,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,   211,    -1,    -1,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,   254,     3,     4,     5,
     258,    -1,    -1,   261,    10,    11,    12,    -1,    -1,    15,
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
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,   258,    -1,    -1,   261,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,
     211,    -1,    -1,    -1,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,     3,
       4,    -1,    -1,   254,    -1,    -1,    10,    11,    12,    -1,
     261,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    92,    93,
       8,    95,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,   207,    -1,    -1,    -1,   211,    -1,    -1,
     263,    -1,   216,   217,   218,    -1,   220,   221,   222,    -1,
      -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   258,    -1,    -1,   261,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     263,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,   217,
     218,    -1,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,    -1,   254,    -1,    -1,    10,
      11,    12,    -1,   261,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    81,    82,    83,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    92,    93,    -1,    95,    -1,    -1,
     131,   132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,
     141,    -1,    -1,    -1,   145,    -1,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,   216,   217,   218,   159,   220,
     221,   222,   163,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,   243,   184,   185,   186,    -1,    -1,   249,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,   217,
     218,    -1,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,     6,   254,    -1,    -1,    10,
      11,    12,    -1,   261,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    81,    82,    83,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    92,    93,    -1,    95,    -1,    -1,
     131,   132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,
     141,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
     211,    -1,    -1,    -1,    -1,   216,   217,   218,   159,   220,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,   243,   184,   185,   186,    -1,    -1,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
     261,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,   216,   217,
     218,    -1,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,    -1,   254,    -1,    -1,    10,
      11,    12,    -1,   261,    15,    16,    17,    18,    19,    20,
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
      95,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,   207,    -1,    -1,    -1,
     211,    -1,    -1,   263,    -1,   216,   217,   218,    -1,   220,
     221,   222,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,
     261,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   263,    -1,    -1,   211,    -1,    -1,    -1,
      -1,   216,   217,   218,    -1,   220,   221,   222,    -1,    -1,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,
      -1,    -1,    -1,    -1,   249,     3,     4,    -1,    -1,   254,
     255,    -1,    10,    11,    12,    -1,   261,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    95,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,   207,
      -1,   253,    -1,   211,    -1,    -1,    -1,    -1,   216,   217,
     218,   263,   220,   221,   222,    -1,    -1,    -1,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,   254,   208,   209,   210,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,   219,    -1,
      -1,    -1,   223,    -1,   225,   226,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      13,    14,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
     251,   252,    70,    71,    72,    73,    -1,   258,    -1,   260,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    13,    14,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
     208,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,    -1,    -1,    -1,   223,    -1,   225,   226,    -1,
      -1,   184,   185,   186,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    13,    14,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
     258,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,   159,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,   184,   185,
     186,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   184,   185,
     186,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,   259,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,   184,   185,
     186,    -1,    -1,   259,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   184,   185,   186,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   259,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,   184,   185,   186,
      -1,    -1,   259,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   184,   185,   186,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   259,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,    -1,   123,    -1,   184,   185,   186,    -1,
      -1,   259,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   184,   185,   186,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   259,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,   184,   185,   186,    -1,    -1,
     259,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   184,   185,   186,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     259,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   159,
      -1,    -1,    -1,    -1,    -1,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   184,   185,   186,   253,    -1,   259,
      46,    47,    48,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,   259,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,   143,   144,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,   172,   173,   174,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   183,   184,   185,
     186,    -1,    -1,   189,    -1,   191,    -1,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     4,    -1,    -1,    -1,    -1,    -1,   213,   214,   215,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
     226,    -1,    -1,    -1,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    46,    47,    48,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    84,    85,    86,    87,    88,    -1,    90,    91,    -1,
      93,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,   116,   117,   118,   119,   120,   121,    -1,
     123,    -1,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,   172,
     173,   174,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,
     183,   184,   185,   186,     4,     5,   189,    -1,   191,    -1,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,
     213,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,   226,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    62,    63,    64,    65,     4,     5,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,   101,     4,     5,   104,    -1,    -1,   107,    -1,   109,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     120,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,   138,     5,
      78,    -1,    80,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    94,    -1,    -1,    97,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    94,    -1,    -1,    97,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,   208,   209,
     210,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,   219,
      -1,    -1,    -1,   223,    -1,   225,   226,    -1,    94,    -1,
      -1,    97,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,    -1,    -1,    -1,   223,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,
      -1,   223,    -1,   225,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   208,   209,   210,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,   219,    -1,    -1,   263,   223,    -1,   225,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   263,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   263,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   263,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   263,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   263,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   263,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   263,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   263,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   263,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   263,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,   259,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,   259,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,   259,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
     259,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,   259,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,   259,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,   259,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,   259,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
     259,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,   259,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,   259,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,   259,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,   259,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
     259,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,   259,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,   259,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,   259,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,   258,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
     258,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,   258,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,   255,    -1,   257,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,   257,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,   257,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,   257,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,   257,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   257,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,   257,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,   257,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,   257,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,   257,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,   257,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     255,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    -1,   255,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   265,   266,     6,     0,     4,    13,    14,    46,
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
     203,   204,   205,   206,   213,   214,   215,   224,   226,   267,
     269,   270,   291,   310,   312,   316,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   334,   336,   337,   343,   344,
     345,   346,   352,   376,   377,   258,   262,    14,   107,   254,
     254,   254,     6,   258,     6,     6,     6,     6,   254,     6,
       6,   258,     6,     6,   256,   256,     4,   354,   377,   254,
     256,   288,   101,   104,   107,   109,   288,   254,   254,   254,
       4,   254,   254,   254,     4,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   258,   122,   107,     6,
       6,   258,   101,   104,   107,   120,   315,   109,   254,     3,
      10,    11,    12,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    58,    59,    60,    61,    66,    67,
      76,    77,    81,    82,    83,    92,    95,   101,   104,   107,
     109,   120,   131,   136,   138,   141,   207,   211,   212,   216,
     217,   218,   220,   221,   222,   242,   243,   249,   254,   258,
     261,   312,   313,   316,   327,   334,   336,   347,   348,   352,
     354,   360,   362,   377,   254,   258,   258,   107,   107,   131,
     104,   107,   109,   101,   104,   107,   109,   312,   104,   107,
     108,   109,   120,   184,   313,   104,   107,   254,   104,   163,
     189,   205,   206,   258,   242,   243,   254,   258,   357,   358,
     357,   258,   258,   357,     4,   101,   105,   111,   112,   114,
     115,   135,   258,   254,   107,   109,   107,   104,     4,    93,
     200,   258,   377,     4,     6,   101,   104,   107,   104,   107,
     120,   314,   107,     4,     4,     4,     5,   254,   258,   360,
     361,     4,   254,   254,   254,     4,   258,   364,   377,     4,
     254,   254,   254,     6,     6,   256,     5,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    62,    63,    64,    65,
      70,    71,    72,    73,    78,    80,    94,    97,   208,   209,
     210,   219,   223,   225,   368,   377,   254,     4,   368,     5,
     258,     5,   258,    32,   243,   347,   377,   256,   258,   254,
     258,     6,   254,   258,     6,   262,     7,   138,   200,   227,
     228,   229,   230,   251,   252,   254,   256,   260,   286,   287,
     288,   312,   347,   367,   368,   377,     4,   316,   317,   318,
     258,     6,   347,   367,   368,   377,   367,   367,   347,   367,
     374,   375,   377,   347,   293,   297,   254,   356,     9,   368,
     254,   254,   254,   254,   377,   347,   347,   347,   254,   347,
     347,   347,   254,   347,   347,   347,   347,   347,   347,   347,
     367,   347,   347,   347,   347,   361,   254,   243,   347,   362,
     363,   258,   361,   360,   367,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     254,   256,   288,   288,   288,   288,   288,   288,   254,   288,
     288,   254,   312,   313,   313,   288,   288,     5,   258,   258,
     131,   312,   312,   254,   288,   288,   254,   254,   254,   347,
     258,   347,   362,   347,   347,   259,   363,   354,   377,   192,
       5,   258,     8,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   253,     9,   254,   256,   260,   287,   288,   347,   363,
     363,   254,   254,   254,   360,   361,   361,   361,   311,   254,
     258,   254,   254,   360,   258,   258,   347,     4,   360,   258,
     364,   258,   258,   357,   357,   357,   347,   347,   242,   243,
     258,   258,   357,   242,   243,   254,   318,   357,   258,   254,
     258,   254,   254,   254,   254,   254,   254,   254,   363,   347,
     361,   361,   361,   254,   258,     4,   256,   258,     6,   256,
     318,     6,     6,   258,   258,   258,   258,   361,   258,   256,
     256,   256,   347,     8,     6,     6,   347,   347,   347,   260,
     347,   258,   192,   347,   347,   347,   347,   288,   288,   288,
     254,   254,   254,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   254,   254,   288,   254,   256,     6,     6,
     258,     6,     8,   318,     6,     8,   318,   288,   347,   244,
     258,     9,   254,   256,   260,   367,   363,   347,   318,   360,
     360,   258,   368,   312,     7,   347,   347,     4,    36,    37,
     110,   111,   189,   190,   290,   360,     6,   255,   257,   258,
     289,   258,     6,   258,     6,     9,   254,   256,   260,   377,
     259,   131,   136,   138,   139,   141,   310,   312,   347,     6,
     255,   263,     9,   254,   256,   260,   255,   263,   255,   263,
     263,   255,   263,     9,   254,   260,   263,   257,   263,   292,
     257,   292,    96,   355,   353,   377,   263,   347,   347,   347,
     347,   263,   255,   255,   255,   347,   255,   255,   255,   347,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   259,     7,   347,   244,   259,   263,   347,     6,     6,
     255,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   362,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   362,   362,
     377,   258,   347,   347,   367,   347,   367,   360,   367,   367,
     374,   258,   258,   258,   347,   289,   377,     8,   347,   347,
     361,   360,   367,   367,   362,   354,   368,   354,   363,   255,
     259,   260,   288,    67,     8,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   258,
     347,   362,   347,   347,   347,   347,   347,   377,   347,   347,
     290,   258,   289,   255,   259,   259,   347,   347,   347,     7,
       7,   340,   340,   254,   347,   347,   347,   347,     6,   363,
     363,   258,   255,     6,   318,   258,   318,   318,   263,   263,
     263,   357,   357,   317,   317,   263,   347,   259,   331,   263,
     318,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     259,   255,     7,   341,     6,     7,   347,   347,     6,   347,
     318,   347,   259,   363,   363,   363,   347,     6,   363,   347,
     347,   347,   255,   259,   255,   255,   255,   189,   263,   318,
     258,     8,   255,   255,   257,   374,   367,   374,   367,   367,
     367,   367,   367,   367,   347,   367,   367,   367,   367,   261,
     370,   377,   368,   367,   367,   367,   354,   377,   363,   259,
     259,   259,   259,   347,   347,   318,   377,   290,   257,   259,
     255,   145,   163,   335,   255,   259,   263,   347,     6,   258,
     360,   255,   257,   260,     7,     7,   286,   287,     6,   363,
       7,   230,   286,   347,   271,   377,   347,   347,   290,   256,
     254,   131,   312,   313,   312,   258,   259,     6,   237,   238,
     268,   363,   377,   347,   347,   290,     6,   363,     6,   363,
     347,     6,   367,   375,   377,   255,   290,   347,     6,   377,
       6,   367,   347,   255,   256,   347,   263,   263,   263,   263,
     368,     7,     7,     7,   255,     7,     7,     7,   255,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   347,
     255,   258,   347,   362,   259,     6,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   263,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   263,   263,   263,
     263,   263,   255,   257,   257,   363,   263,   263,   289,   263,
     289,   263,   263,   263,   255,   363,   347,   347,   349,   289,
     259,   259,   259,   263,   263,   289,   289,   255,   260,   255,
     260,   263,   288,   350,   259,     7,   290,   289,   360,   259,
       8,     8,   363,   260,   255,   257,   254,   256,   287,   288,
     363,     7,   258,   258,   255,   255,   255,   347,   360,     4,
     339,     6,   306,   347,   368,   255,   259,   255,   255,   259,
     259,   363,   260,   259,   318,   259,   259,   357,   347,   347,
     259,   259,   347,   357,   142,   142,   160,   169,   170,   171,
     175,   176,   332,   333,   357,   259,   328,   255,   259,   255,
     255,   255,   255,   255,   255,   255,   258,     7,   347,     6,
     347,   255,   259,   257,   259,   257,   259,   259,   259,   259,
     259,   257,   257,   263,     7,     7,     7,   260,   347,   259,
     347,   347,     7,   260,   289,   263,   289,   289,   255,   255,
     263,   289,   289,   263,   263,   289,   289,   289,   289,   347,
     289,     9,   369,   263,   255,   263,   289,   260,   263,   351,
     257,   259,   259,   260,   254,   256,   262,   192,     7,   163,
       6,   347,   259,   258,     6,   360,   259,   347,     6,     7,
     286,   287,   260,   286,   287,   290,   258,   365,   377,   368,
     347,     6,   259,    49,    49,   360,   259,     4,   179,   180,
     181,   182,   259,   274,   278,   281,   283,   284,   326,   260,
     255,   257,   254,   347,   347,   254,   258,   254,   258,     8,
     363,   367,   255,   260,   255,   257,   254,   255,   255,   263,
     260,   254,   263,     7,   288,     4,    36,    37,   300,   301,
     302,   289,   347,   347,   347,   347,   289,   357,   360,   360,
       7,   360,   360,   360,     7,   360,   360,   360,   360,   360,
     360,   360,   360,   360,   360,     6,     7,   363,   347,   347,
     347,   347,   347,   347,   259,   347,   347,   347,   360,   367,
     367,   259,   259,   259,   263,   299,   347,   347,   290,   290,
     347,   347,   255,   360,   288,   347,   347,   259,   290,   287,
     260,   287,   347,   347,   289,   259,   360,   363,   363,     7,
       7,     7,   142,   338,     6,   255,   263,     7,     7,     7,
       7,     7,   259,     4,   290,   259,   263,   263,   263,   259,
     259,   119,     4,     6,   347,   258,     6,   254,     6,   177,
       6,   177,   259,   333,   263,   332,     7,     6,     7,     7,
       7,     7,     7,     7,     7,   317,   360,     6,   258,   101,
       6,     6,     6,   107,     7,     7,     6,     6,   347,   360,
     360,   360,     4,   263,     8,     8,   255,   290,   290,   363,
     367,   347,   367,   261,   263,   303,   367,   367,   290,   367,
     255,   263,   290,   258,   312,   258,     6,   347,     6,   258,
     360,   259,   259,   347,     6,   189,   190,   290,   347,     6,
       7,   364,   366,     6,   256,     6,     6,   289,   288,   288,
       6,   275,   254,   254,   258,   285,     6,   290,   260,   367,
     347,   257,   255,   347,     8,   363,   347,   363,   259,   259,
       6,     6,   268,   290,   260,   347,     6,     6,   347,   290,
     255,   347,   258,   347,   368,   289,    49,   258,   360,   368,
     371,   347,   347,   257,   263,     6,   255,   255,   255,   255,
       6,     6,   135,   308,   308,   360,     6,     6,     6,   360,
     142,   192,   307,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   259,   289,   289,   289,   289,   289,   289,
     289,   263,   263,   263,   255,   289,   289,   301,   289,   255,
     289,   255,   288,   350,   289,     6,   289,   254,   256,   288,
     290,   255,   257,   289,     6,   259,   259,   360,   360,   360,
       4,     6,   286,   347,   360,   360,   360,   258,   258,     7,
       6,     7,   347,   347,   347,   258,   258,   258,   256,     6,
     347,   360,   347,     6,     6,   347,   357,   259,     5,   360,
     258,   258,   258,   258,   258,   258,   258,   360,   259,     6,
     363,   258,   258,   347,   347,   257,     6,     6,   188,   347,
     347,   347,     6,     6,     7,   289,   263,   263,   289,   263,
     347,     4,   204,   304,   305,   289,   255,   289,   351,   368,
     254,   256,   347,   258,   318,     6,   318,   263,     6,     6,
     260,     7,     7,   286,   287,     6,   364,   259,   263,   347,
     286,   258,   289,   372,   373,   374,   372,   254,   347,   347,
     359,   360,   258,   254,     4,     6,   255,     6,   255,   259,
     259,   255,   259,     6,     6,   367,   254,     4,   255,   263,
     254,   259,   263,   360,   368,     7,   288,   298,   347,   362,
     302,     6,     6,     6,     6,   357,     6,     6,     6,   142,
     309,   101,   120,   105,     6,     5,   258,   347,   347,   347,
     347,   255,   350,   347,   347,   289,   287,   258,   258,     6,
     307,     6,   347,   360,   142,   142,     4,     6,   363,   363,
     347,   347,   368,   259,   255,   259,   263,   317,   317,   347,
     347,   259,   263,   255,   259,   263,     6,     6,   359,   357,
     357,   357,   357,   357,   243,   357,     6,   259,   363,   347,
       6,     6,     6,   360,   259,   263,     8,   259,   255,   258,
     347,   368,   367,   347,   367,   347,   368,   371,   373,   368,
     263,   255,   263,   259,   347,   335,   335,   360,   290,   365,
     368,   347,     6,     6,   364,   257,   360,   374,     6,   289,
     289,   272,   347,   263,   263,   259,   263,   273,   347,   347,
       6,     6,     6,     6,   347,   347,   255,     6,   347,   294,
     296,   258,   373,   259,   263,     7,     7,   146,     6,   258,
     258,   258,     5,   359,   289,   289,   263,   289,   255,   255,
     257,   363,   363,     6,     6,   347,   347,   258,   259,   259,
     258,     6,     6,   258,   347,   259,   259,   259,   257,     6,
     360,     7,   258,   347,   259,   263,   263,   263,   263,   263,
     263,     6,   259,   259,   187,   347,   347,   363,     6,     6,
     255,   289,   289,   305,   368,   259,   259,   259,   259,     7,
       6,     6,     6,   260,     6,   259,     6,     6,   255,   263,
     347,   347,   258,   360,   259,   263,   255,   255,   263,   259,
     299,   303,   360,   289,   347,   368,   377,   363,   363,   347,
       6,   259,   347,   350,   259,   259,     6,     6,   359,   147,
     148,   153,   342,   147,   148,   342,   363,   317,   259,   263,
       6,   259,   360,   318,   259,     6,   363,   357,   357,   357,
     357,   357,     6,   347,   259,   259,   259,   255,     6,   258,
       6,   364,   190,   276,   347,   263,   263,   359,     6,   347,
     347,     6,   259,   259,   295,     7,   254,   259,   259,   259,
     258,   263,   255,   258,   259,   258,   357,   360,     6,   258,
     357,     6,   259,   259,   347,     6,   142,   259,   329,   258,
     259,   263,   263,   263,   263,   263,     6,     6,     6,   318,
       6,   258,   347,   347,   259,   263,   299,   368,   255,   347,
     347,   363,     6,   357,     6,   357,     6,     6,   259,   347,
     332,   318,     6,   363,   363,   363,   363,   357,   363,   335,
     273,   255,   263,     6,   258,   347,   259,   263,   263,   259,
     263,   263,     6,   259,   259,   330,   259,   259,   259,   259,
     263,   259,   259,   259,   279,   347,   359,   259,   347,   347,
     357,   357,   332,     6,     6,     6,     6,   363,     6,     6,
       6,   258,   255,   259,     6,   259,   289,   263,   263,   259,
     259,   277,   367,   282,   258,     6,   347,   347,     6,   259,
     263,   258,   359,   259,   259,     6,   367,   280,   367,   259,
       6,     6,   259,   263,     6,     6,   367
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

  case 366:
#line 4595 "Gmsh.y"
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

  case 367:
#line 4607 "Gmsh.y"
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

  case 368:
#line 4619 "Gmsh.y"
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

  case 369:
#line 4631 "Gmsh.y"
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

  case 370:
#line 4648 "Gmsh.y"
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

  case 371:
#line 4665 "Gmsh.y"
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

  case 372:
#line 4695 "Gmsh.y"
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

  case 373:
#line 4721 "Gmsh.y"
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

  case 374:
#line 4748 "Gmsh.y"
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

  case 375:
#line 4780 "Gmsh.y"
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

  case 376:
#line 4807 "Gmsh.y"
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

  case 377:
#line 4833 "Gmsh.y"
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

  case 378:
#line 4859 "Gmsh.y"
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

  case 379:
#line 4885 "Gmsh.y"
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

  case 380:
#line 4911 "Gmsh.y"
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

  case 381:
#line 4932 "Gmsh.y"
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

  case 382:
#line 4943 "Gmsh.y"
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

  case 383:
#line 4991 "Gmsh.y"
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

  case 384:
#line 5045 "Gmsh.y"
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

  case 385:
#line 5060 "Gmsh.y"
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

  case 386:
#line 5072 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 387:
#line 5083 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 388:
#line 5090 "Gmsh.y"
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

  case 389:
#line 5105 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 390:
#line 5118 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 391:
#line 5119 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 392:
#line 5120 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 393:
#line 5125 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 394:
#line 5131 "Gmsh.y"
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

  case 395:
#line 5143 "Gmsh.y"
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

  case 396:
#line 5161 "Gmsh.y"
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

  case 397:
#line 5188 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 398:
#line 5189 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 399:
#line 5190 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 400:
#line 5191 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 401:
#line 5192 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 402:
#line 5193 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5194 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5195 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5197 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 406:
#line 5203 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 407:
#line 5204 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 408:
#line 5205 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 409:
#line 5206 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 410:
#line 5207 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 411:
#line 5208 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 412:
#line 5209 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5210 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 414:
#line 5211 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 415:
#line 5212 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 416:
#line 5213 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 417:
#line 5214 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 418:
#line 5215 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 419:
#line 5216 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 420:
#line 5217 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 421:
#line 5218 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5219 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5220 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 424:
#line 5221 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5222 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 426:
#line 5223 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5224 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 428:
#line 5225 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5226 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 430:
#line 5227 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5228 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 432:
#line 5229 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 433:
#line 5230 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5231 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 435:
#line 5232 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 436:
#line 5233 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 437:
#line 5234 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 438:
#line 5235 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 439:
#line 5236 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 440:
#line 5237 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5238 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 442:
#line 5239 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 443:
#line 5240 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 444:
#line 5241 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 445:
#line 5242 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 446:
#line 5251 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 447:
#line 5252 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 448:
#line 5253 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 449:
#line 5254 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 450:
#line 5255 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 451:
#line 5256 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 452:
#line 5257 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 453:
#line 5258 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 454:
#line 5259 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 455:
#line 5260 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 456:
#line 5261 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 457:
#line 5266 "Gmsh.y"
    { init_options(); ;}
    break;

  case 458:
#line 5268 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 459:
#line 5274 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 460:
#line 5276 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 461:
#line 5281 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 462:
#line 5286 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 463:
#line 5291 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 464:
#line 5296 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 465:
#line 5300 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 466:
#line 5304 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 467:
#line 5308 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 468:
#line 5312 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 469:
#line 5316 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 470:
#line 5320 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 471:
#line 5324 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 472:
#line 5330 "Gmsh.y"
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

  case 473:
#line 5345 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 474:
#line 5349 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 475:
#line 5355 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 476:
#line 5360 "Gmsh.y"
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

  case 477:
#line 5379 "Gmsh.y"
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
#line 5399 "Gmsh.y"
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
#line 5420 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 480:
#line 5424 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 481:
#line 5428 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 482:
#line 5432 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 483:
#line 5436 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 484:
#line 5440 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 485:
#line 5444 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 486:
#line 5449 "Gmsh.y"
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

  case 487:
#line 5459 "Gmsh.y"
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

  case 488:
#line 5469 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 489:
#line 5474 "Gmsh.y"
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

  case 490:
#line 5485 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 491:
#line 5494 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 492:
#line 5499 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 493:
#line 5504 "Gmsh.y"
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

  case 494:
#line 5531 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 495:
#line 5533 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 496:
#line 5538 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 497:
#line 5540 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 498:
#line 5545 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 499:
#line 5552 "Gmsh.y"
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

  case 500:
#line 5568 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 501:
#line 5570 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 502:
#line 5575 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 503:
#line 5577 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 504:
#line 5582 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 505:
#line 5584 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 506:
#line 5589 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 507:
#line 5593 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 508:
#line 5597 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 509:
#line 5601 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 510:
#line 5605 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 511:
#line 5612 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 512:
#line 5616 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 513:
#line 5620 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 514:
#line 5624 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 515:
#line 5631 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 516:
#line 5636 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 517:
#line 5643 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 518:
#line 5648 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 519:
#line 5652 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 520:
#line 5657 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 521:
#line 5661 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 522:
#line 5669 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 523:
#line 5680 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 524:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 525:
#line 5688 "Gmsh.y"
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

  case 526:
#line 5702 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 527:
#line 5710 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 528:
#line 5718 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 529:
#line 5725 "Gmsh.y"
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

  case 530:
#line 5735 "Gmsh.y"
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

  case 531:
#line 5758 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 532:
#line 5763 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 533:
#line 5769 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 534:
#line 5774 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 535:
#line 5780 "Gmsh.y"
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

  case 536:
#line 5791 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 537:
#line 5797 "Gmsh.y"
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

  case 538:
#line 5811 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 539:
#line 5817 "Gmsh.y"
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

  case 540:
#line 5829 "Gmsh.y"
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

  case 541:
#line 5843 "Gmsh.y"
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
#line 5853 "Gmsh.y"
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
#line 5863 "Gmsh.y"
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
#line 5873 "Gmsh.y"
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

  case 545:
#line 5885 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 546:
#line 5889 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 547:
#line 5894 "Gmsh.y"
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

  case 548:
#line 5906 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 549:
#line 5910 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 550:
#line 5914 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 551:
#line 5918 "Gmsh.y"
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

  case 552:
#line 5936 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 553:
#line 5944 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 554:
#line 5952 "Gmsh.y"
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

  case 555:
#line 5981 "Gmsh.y"
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

  case 556:
#line 5991 "Gmsh.y"
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

  case 557:
#line 6007 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 558:
#line 6018 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 559:
#line 6023 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 560:
#line 6027 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 561:
#line 6031 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 562:
#line 6043 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 563:
#line 6047 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 564:
#line 6059 "Gmsh.y"
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

  case 565:
#line 6076 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 566:
#line 6086 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 567:
#line 6090 "Gmsh.y"
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

  case 568:
#line 6105 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 569:
#line 6110 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 570:
#line 6117 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 571:
#line 6121 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 572:
#line 6126 "Gmsh.y"
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
#line 6140 "Gmsh.y"
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
#line 6154 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 575:
#line 6158 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 576:
#line 6162 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 577:
#line 6166 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 578:
#line 6170 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 579:
#line 6178 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 580:
#line 6184 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 581:
#line 6193 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 582:
#line 6197 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 583:
#line 6201 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 584:
#line 6209 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 585:
#line 6215 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 586:
#line 6221 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 587:
#line 6225 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6232 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 589:
#line 6240 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 590:
#line 6247 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 591:
#line 6256 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 592:
#line 6260 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 593:
#line 6264 "Gmsh.y"
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

  case 594:
#line 6279 "Gmsh.y"
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

  case 595:
#line 6293 "Gmsh.y"
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

  case 596:
#line 6307 "Gmsh.y"
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

  case 597:
#line 6319 "Gmsh.y"
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

  case 598:
#line 6335 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 599:
#line 6344 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 600:
#line 6353 "Gmsh.y"
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

  case 601:
#line 6363 "Gmsh.y"
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

  case 602:
#line 6374 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 603:
#line 6382 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 604:
#line 6390 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 605:
#line 6394 "Gmsh.y"
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

  case 606:
#line 6413 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 607:
#line 6420 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 608:
#line 6426 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 609:
#line 6432 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 610:
#line 6439 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 611:
#line 6446 "Gmsh.y"
    { init_options(); ;}
    break;

  case 612:
#line 6448 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 613:
#line 6456 "Gmsh.y"
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

  case 614:
#line 6480 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 615:
#line 6482 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 616:
#line 6488 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 617:
#line 6493 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 618:
#line 6495 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 619:
#line 6500 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 620:
#line 6505 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 621:
#line 6510 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 622:
#line 6512 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 623:
#line 6516 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 624:
#line 6528 "Gmsh.y"
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

  case 625:
#line 6542 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 626:
#line 6546 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 627:
#line 6553 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 628:
#line 6561 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 629:
#line 6569 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 630:
#line 6580 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 631:
#line 6582 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 632:
#line 6585 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14697 "Gmsh.tab.cpp"
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


#line 6588 "Gmsh.y"


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

