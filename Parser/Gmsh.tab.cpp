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
#define YYLAST   17503

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  263
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2247

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
    2865,  2868,  2873,  2876,  2880,  2884,  2889,  2895,  2901,  2907,
    2909,  2911,  2913,  2917,  2923,  2931,  2936,  2941,  2946,  2953,
    2960,  2969,  2978,  2983,  2998,  3003,  3008,  3010,  3012,  3016,
    3020,  3030,  3038,  3040,  3046,  3050,  3057,  3059,  3063,  3065,
    3067,  3072,  3077,  3081,  3087,  3094,  3103,  3110,  3115,  3121,
    3123,  3128,  3130,  3132,  3134,  3136,  3141,  3148,  3153,  3160,
    3166,  3174,  3179,  3184,  3189,  3198,  3203,  3208,  3213,  3218,
    3227,  3236,  3243,  3248,  3255,  3260,  3262,  3264,  3269,  3274,
    3275,  3282,  3287,  3290,  3295,  3300,  3302,  3304,  3308,  3310,
    3312,  3316,  3320,  3324,  3330,  3338,  3344,  3350,  3359,  3361,
    3363
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
     140,   311,   359,    -1,   311,   191,    67,   359,    -1,    67,
     311,   257,   362,   258,    -1,    76,   312,   257,   346,   258,
      -1,    77,   312,   257,   346,   258,    -1,   315,    -1,   326,
      -1,   335,    -1,   376,   287,   288,    -1,   376,   259,   289,
     287,   288,    -1,   376,     9,   376,   259,   289,   287,   288,
      -1,    41,   255,   376,   256,    -1,    41,   255,   361,   256,
      -1,    41,   253,   361,   254,    -1,    41,   287,   257,   362,
     258,   288,    -1,   376,   287,   257,   362,   258,   288,    -1,
      42,   287,   346,   262,   346,   262,   346,   288,    -1,    43,
     287,   346,   262,   346,   262,   346,   288,    -1,    44,   287,
     366,   288,    -1,    45,   287,   346,   262,   346,   262,   346,
     262,   346,   262,   346,   262,   346,   288,    -1,   211,   287,
     361,   288,    -1,    32,   287,   361,   288,    -1,   346,    -1,
     361,    -1,   362,   262,   346,    -1,   362,   262,   361,    -1,
     257,   346,   262,   346,   262,   346,   262,   346,   258,    -1,
     257,   346,   262,   346,   262,   346,   258,    -1,   376,    -1,
       4,   259,   188,   259,     4,    -1,   257,   365,   258,    -1,
     376,   255,   346,   256,   259,   189,    -1,   363,    -1,   365,
     262,   363,    -1,   367,    -1,   376,    -1,   376,   255,   346,
     256,    -1,   376,   253,   346,   254,    -1,   376,   259,   289,
      -1,   376,     9,   376,   259,   289,    -1,   376,   259,   289,
     253,   346,   254,    -1,   376,     9,   376,   259,   289,   253,
     346,   254,    -1,   376,   255,   346,   256,   259,     4,    -1,
     311,   257,   346,   258,    -1,   137,   311,   257,   346,   258,
      -1,     5,    -1,   224,   255,   376,   256,    -1,    70,    -1,
     222,    -1,    78,    -1,    80,    -1,   208,   253,   366,   254,
      -1,   207,   253,   366,   262,   366,   254,    -1,   209,   287,
     366,   288,    -1,   209,   287,   366,   262,   366,   288,    -1,
     218,   253,   353,   350,   254,    -1,   218,   253,   353,   259,
     289,   350,   254,    -1,    51,   287,   373,   288,    -1,    52,
     253,   366,   254,    -1,    53,   253,   366,   254,    -1,    54,
     253,   366,   262,   366,   262,   366,   254,    -1,    49,   287,
     373,   288,    -1,    63,   287,   366,   288,    -1,    64,   287,
     366,   288,    -1,    65,   287,   366,   288,    -1,    62,   287,
     346,   262,   366,   262,   366,   288,    -1,    57,   287,   366,
     262,   346,   262,   346,   288,    -1,    57,   287,   366,   262,
     346,   288,    -1,    50,   287,   366,   288,    -1,    50,   287,
     366,   262,   362,   288,    -1,    71,   287,   366,   288,    -1,
      72,    -1,    73,    -1,    56,   287,   366,   288,    -1,    55,
     287,   366,   288,    -1,    -1,    97,   287,   367,   368,   302,
     288,    -1,    94,   287,   369,   288,    -1,   260,   346,    -1,
     376,     9,   260,   346,    -1,    49,   287,   372,   288,    -1,
     373,    -1,   372,    -1,   257,   373,   258,    -1,   366,    -1,
     374,    -1,   373,   262,   366,    -1,   373,   262,   374,    -1,
     376,   253,   254,    -1,   376,   259,   289,   253,   254,    -1,
     376,     9,   376,   259,   289,   253,   254,    -1,     4,   261,
     257,   346,   258,    -1,   375,   261,   257,   346,   258,    -1,
     225,   255,   366,   256,   261,   257,   346,   258,    -1,     4,
      -1,   375,    -1,   225,   255,   366,   256,    -1
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
    5720,  5726,  5731,  5737,  5748,  5754,  5768,  5774,  5786,  5800,
    5810,  5820,  5830,  5842,  5846,  5851,  5863,  5867,  5871,  5875,
    5893,  5901,  5909,  5938,  5948,  5964,  5975,  5980,  5984,  5988,
    6000,  6004,  6016,  6033,  6043,  6047,  6062,  6067,  6074,  6078,
    6083,  6097,  6111,  6115,  6119,  6123,  6127,  6135,  6141,  6150,
    6154,  6158,  6166,  6172,  6178,  6182,  6189,  6197,  6204,  6213,
    6217,  6221,  6236,  6250,  6264,  6276,  6292,  6301,  6310,  6320,
    6331,  6339,  6347,  6351,  6370,  6377,  6383,  6389,  6396,  6404,
    6403,  6413,  6437,  6439,  6445,  6450,  6452,  6457,  6462,  6467,
    6469,  6473,  6485,  6499,  6503,  6510,  6518,  6526,  6537,  6539,
    6542
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
     519,     0,     0,   470,   535,   531,     0,     0,     0,     0,
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
     527,   418,   520,   478,   476,     0,   475,     0,     0,   543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   360,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
     258,     0,     0,     0,     0,     0,     0,     0,   327,     0,
       0,   326,     0,   329,     0,   331,     0,   316,   323,     0,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   371,     0,   253,   252,   387,     0,     0,     0,
      37,    38,     0,     0,     0,     0,   563,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   494,   495,   589,     0,   478,     0,     0,   230,
     342,     0,   343,   230,     0,     0,   578,     0,    94,     0,
       0,     0,     0,    92,     0,   566,     0,   107,     0,    99,
     101,     0,     0,     0,    89,     0,     0,     0,     0,     0,
      36,   478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,   573,     0,     0,
      34,    33,     0,   573,   623,     0,     0,   121,   126,     0,
       0,     0,   140,   145,   146,   141,   142,   497,     0,    85,
       0,     0,     0,     0,    86,   167,     0,     0,     0,     0,
     168,   185,   186,   165,     0,     0,     0,   169,   196,   187,
     191,   192,   188,   189,   190,   177,     0,     0,   429,   443,
     442,   438,   439,   440,   548,     0,     0,     0,   487,   488,
     490,   135,   456,   486,   459,   464,     0,     0,   492,   197,
     471,    73,    74,     0,   483,   479,   481,   549,   193,     0,
       0,     0,   159,     0,     0,   359,     0,   158,     0,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   230,
     230,     0,     0,   328,   515,     0,     0,   330,   332,     0,
       0,   310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   194,     0,     0,     0,     0,     0,   174,
     175,     0,     0,     0,     0,   110,   114,     0,   603,     0,
       0,   601,     0,   613,     0,     0,   148,   149,   610,   586,
     588,     0,     0,     0,     0,     0,     0,   340,   344,   340,
       0,   393,    93,     0,     0,    66,     0,     0,    91,     0,
     564,     0,     0,     0,     0,     0,     0,   616,   615,     0,
       0,     0,     0,     0,   513,     0,     0,    77,   270,   479,
     271,     0,     0,     0,     0,     0,   235,   232,     0,     0,
     576,   574,     0,     0,     0,     0,   122,   127,     0,     0,
       0,   556,   557,   139,   363,   364,   365,   366,   164,   172,
     173,   178,     0,     0,     0,     0,     0,   180,     0,     0,
       0,     0,     0,     0,   466,     0,     0,     0,   544,   485,
       0,     0,   179,     0,   198,   349,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,   512,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     246,     0,     0,     0,     0,     0,     0,     0,     0,   237,
       0,     0,   367,   368,    39,     0,   561,     0,     0,   294,
     293,     0,     0,     0,     0,     0,     0,   151,   152,   155,
     154,   153,     0,   590,     0,   627,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   567,     0,     0,     0,
      96,     0,     0,     0,    47,     0,     0,     0,     0,     0,
      49,     0,   236,   233,   234,    35,     0,     0,   624,   284,
       0,   134,   147,     0,     0,   144,     0,     0,     0,   166,
     195,     0,     0,     0,     0,     0,   550,   551,     0,   492,
     467,   480,   482,     0,     0,   181,   202,     0,     0,     0,
     356,   356,     0,   115,   116,   230,     0,   222,   223,   317,
       0,   324,     0,     0,   230,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   226,     0,     0,     0,     0,   111,
     112,   594,   600,   599,   150,     0,     0,     0,   345,     0,
       0,   108,   100,   102,     0,    90,   617,    97,    98,    52,
       0,     0,     0,     0,   514,     0,     0,   480,   575,     0,
       0,     0,     0,   124,   614,     0,   131,     0,     0,     0,
       0,   184,     0,     0,     0,   320,     0,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   510,
       0,   334,     0,     0,   311,     0,   238,     0,     0,     0,
       0,     0,     0,     0,   560,   295,     0,     0,   379,   230,
     394,     0,   565,     0,    48,     0,     0,     0,    65,    50,
       0,   285,   123,   128,   134,     0,     0,   161,   162,   160,
       0,     0,   468,     0,     0,     0,     0,   357,   372,     0,
       0,   373,     0,   220,     0,   325,     0,   307,     0,   230,
       0,     0,     0,     0,     0,     0,   176,   113,   291,   340,
     106,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,   200,     0,   376,     0,   377,   378,   509,     0,
       0,   313,   241,     0,     0,     0,     0,     0,     0,     0,
       0,    56,     0,    62,     0,     0,   125,     0,     0,   321,
       0,     0,   333,   312,   308,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   242,   243,   244,   245,     0,   239,   347,
      53,     0,    60,     0,   280,     0,   553,     0,     0,   314,
       0,     0,    54,     0,     0,   290,     0,     0,   240,     0,
       0,     0,     0,     0,     0,    57,    55,     0,    58,     0,
     374,   375,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,  1086,   119,   120,  1070,  1933,  1939,
    1368,  1585,  2093,  2221,  1369,  2194,  2237,  1370,  2223,  1371,
    1372,  1589,   446,   604,   605,  1158,  1684,   121,   796,   472,
    1951,  2104,  1952,   473,  1820,  1450,  1403,  1404,  1405,  1549,
    1756,  1757,  1228,  1646,  1637,  1833,   773,   616,   279,   280,
     359,   204,   281,   456,   457,   125,   126,   127,   128,   129,
     130,   131,   132,   282,  1262,  2128,  2185,   965,  1258,  1259,
     283,  1049,   284,   136,  1478,  1226,   938,   980,  2063,   137,
     138,   139,   140,   285,   286,  1184,  1199,  1324,   287,   801,
     288,   800,   475,   633,   327,  1793,   367,   368,   290,   574,
     375,  1352,  1576,   467,   462,  1317,  1026,  1624,  1786,  1787,
    1011,   469,   142,   424
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1918
static const yytype_int16 yypact[] =
{
   13204,   136,    81, 13406, -1918, -1918,   -83,    88,    64,  -211,
    -128,   -48,    32,   219,   228,   245,   261,    68,   327,   356,
     122,   380,   393,    83,    90,    27,    29,   654,    29,   182,
     217,   231,    57,   244,   253,    61,   269,   274,   297,   317,
     324,   341,   392,   413,   420,   422,   376,   578,   642,   745,
     449,    78,   664,   526,  6904,   532,   531,   534,   725,   -59,
     354,   570,   332,   472,   573,   727,   -74,   614,   387,   387,
     615,   471,    55,   639, -1918, -1918, -1918, -1918, -1918,   591,
     243,   767,   797,    36,    43,   800,   802,   421,   805,   920,
     934,   935,  5900,   947,   742,   743,   744,    12,    65, -1918,
     755,   760, -1918, -1918,   960,  1015,   772, -1918, 13650,   777,
   13686,    13,    21, -1918, -1918, -1918, 11930,   782, -1918, -1918,
   -1918, -1918, -1918,   781, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918, -1918, -1918,   180, -1918, -1918, -1918, -1918,    49,
   -1918,  1033,   780,  5647,   339,   786,  1039, 11930, 13588, 13588,
   13588, -1918, 11930, -1918, -1918, -1918, -1918, 13588, -1918, -1918,
   11930, -1918, -1918, -1918, -1918,   789,   794,  1042, -1918, -1918,
    1116,   799,   801,   803,   806,    27, 11930, 11930, 11930,   807,
   11930, 11930, 11930,   808, 11930, 11930, 11930, 11930, 11930, 11930,
   11930, 13588, 11930, 11930, 11930, 11930,  5900,   809, -1918,  9655,
   -1918, -1918, -1918,   796,  5900,  7155, 13588, -1918, -1918, -1918,
   -1918, -1918,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,   191,    29,    29,
      29,    29,    29,   810,    29,    29,   811,   570,   134,   134,
   -1918, -1918, -1918,    29,    29,    30,   864,   867,   875,   812,
    7155,   937,   570,   570,   815,    29,    29,   818,   819,   821,
   -1918, -1918, -1918, 11930,  7406, 11930, 11930,  7657,    27,   885,
      31, -1918, -1918,   822, -1918,  4824, -1918, -1918, -1918, -1918,
   -1918,    98, 11930,  9655,  9655,   832,   833,  7908,  5900,  5900,
    5900, -1918, -1918, -1918, -1918, -1918, -1918, -1918,   834, -1918,
     831,   836,  8159,   835,  4610,  1086,  7155,   840,    12,   841,
     843,   387,   387,   387, 11930, 11930,  -107, -1918,   -31,   387,
   10588,   478,   203,   838,   846,   848,   849,   851,   852,   853,
    9655, 11930,  5900,  5900,  5900,   854,    11,  1087,   855, -1918,
    1103,  1105, -1918,   856,   857,   860, -1918, -1918,   878,  5900,
     897,   900,   901,   904, -1918, 11930,  6151, -1918,  1106,  1154,
   11930, 11930, 11930,   273, 11930,   905, -1918,   970, 11930, 11930,
   11930, -1918, -1918, 11930, -1918,    29,    29,    29,   924,   930,
     931,    29,    29,    29,    29,    29,    29,    29, -1918,    29,
   -1918, -1918, -1918, -1918,    29,    29,   932,   938,    29,   939,
   -1918,   940,  1184,  1187,   942, -1918, -1918,  1194,  1193,  1196,
    1195,    29, 11930, 15083,   114, 13588,  9655, 11930, -1918, -1918,
    7155,  7155, -1918,   948,  1116,   570,  1197, -1918, -1918, -1918,
   -1918, -1918, -1918, 11930, 11930,   394,  7155,  1200,  -141,   950,
    2150,   951,  1205,    48,   955, -1918,   959, 11319, 11930, -1918,
    2252,  -153, -1918,    75,   -35,   131,  7341, -1918,   197, -1918,
     115,  7592,   119,   239,  1122, -1918,    27,   957, 11930, 11930,
   11930, 11930,   958, 15599, 15624, 15649, 11930, 15674, 15699, 15724,
   11930, 15749, 15774, 15799, 15824, 15849, 15874, 15899,   967, 15924,
   15949, 15974,  4878,  1215, 11930,  9655,  5064, -1918,    42, 11930,
    1218,  1219,   972, 11930, 11930, 11930, 11930, 11930, 11930, 11930,
   11930, 11930, 11930, 11930, 11930, 11930, 11930, 11930, 11930,  9655,
   11930, 11930, 11930, 11930, 11930, 11930, 11930, 11930,  9655,  9655,
     971, 11930, 11930, 13588, 11930, 13588,  7155, 13588, 13588, 13588,
     989,   990,   991, 11930,    25, -1918, 10674, 11930,  7155,  5900,
    7155, 13588, 13588,  9655,    27,  1116,    27,   975,  9655,   975,
   -1918,   975, 15999, -1918,   258,   992,    10,  1162, -1918,  1244,
   11930, 11930, 11930, 11930, 11930, 11930, 11930, 11930, 11930, 11930,
   11930, 11930, 11930, 11930,  8410, 11930, 11930, 11930, 11930, 11930,
      27, 11930, 11930,   428, -1918,   431, 16024,   372,   507, 11930,
   11930, 11930, -1918,  1247,  1248,  1248,  1009, 11930, 11930, 11930,
   11930,  1257,  9655,  9655, 15111,  1010,  1260, -1918,  1011, -1918,
   -1918,  -104, -1918, -1918,  7843,  8094,   387,   387,   339,   339,
     -65, 10588, 10588, 11930,  3680,   -58, -1918, 11930, 11930, 11930,
   11930, 11930, 11930, 11930, 11930, 11930,   509, 16049,  1262,  1283,
    1285, 11930,  1287, 11930, -1918, -1918, 11930, 12180, -1918, -1918,
    9655,  9655,  9655, 11930,  1288,  9655, 11930, 11930, 11930, 16074,
    1037, -1918, -1918, 16099, 16124, 16149,  1108,  8345, -1918,  1041,
    5338, 16174, 16199, 15194, 13588, 13588, 13588, 13588, 13588, 13588,
   13588, 13588, 13588, 11930, 13588, 13588, 13588, 13588,    17,  1116,
   13588, 13588, 13588,    27,    27, -1918, -1918,  9655, -1918,  1043,
   12288, -1918,  1045, 12346, 11930,   975, 11930, -1918,    27, 11930,
   11930,   428,  1044,   512, 16224, 10980,  1050,   557, 11930,  1293,
    1048,  7155, 16249, 15221, -1918, -1918, -1918, -1918, -1918,  1049,
    1300,   132,  1303, -1918, -1918, -1918,  9655,    20, 11930, -1918,
   -1918, -1918,    27, 11930, 11930,   428,  1056, -1918,  1059,   -54,
     570,   332,   570, -1918,  1057, 14242, -1918,   155,  9655,    27,
   11930, 11930,   428,  1307,  9655,  1310,  9655, 11930,  1312, 13588,
      27, 10920,   428, 11930,  1313, -1918,    27,  1315, 13588, 11930,
    1068,  1071, -1918, 11930,  8596,  8842,  9088,  9339,  1116,  1320,
    1321,  1322, 16274,  1323,  1324,  1325, 16299,  1326,  1329,  1330,
    1332,  1334,  1335,  1336, -1918,  1337,  1338,  1340, -1918, 11930,
   16324,  9655,  1092,  9655, 14271, -1918, -1918,  1344, 15167, 15167,
   15167, 15167, 15167, 15167, 15167, 15167, 15167, 15167, 15167,  9590,
   15167, 15167, 15167, 15167,  1861,   355, 15167, 15167, 15167,  9932,
   10278, 10540, 10619, 10951,  5064,  1097,  1096,    76,  9655, 11290,
   11550,   355, 11629,   355,  1091,  1093,  1095,   344,  9655, 11930,
   11930, 12275, -1918,   355,  1100, 14300, 14329, -1918, -1918,  1098,
    -150,   355,  -164,  1107,   495,   565,  1347, -1918,   428,   355,
    7155,  1101,  5578,  5835,   564,   998,  1038,  1038,   500,   500,
     500,   500,   500,   500,   437,   437,  9655,    -7, -1918,    -7,
      -7,   975,   975,   975,  1104, 16349, 15248,   527,  9655, -1918,
    1355,  1109,  1110, 16374, 16399, 16424, 11930,  7155,  1360,  1359,
   10342, 16449, 14358, 16474, 16499, -1918,   571,   576,  9655,  1111,
   -1918, 12431, -1918, 12489, 12574,   387, 11930, 11930, -1918, -1918,
    1113,  1114, 10588,  4284,  1227,   308,   387, 12632, 16524, 14387,
   16549, 16574, 16599, 16624, 16649, 16674, 16699,  1112,  1367, 11930,
    1369, -1918, 11930, 16724, -1918, 15275, 12717, 15302, -1918,   579,
     581,   584, 14416, -1918,   587, 15329, 15356, 11886, -1918, -1918,
    1370,  1372,  1374,  1117, 11930, 12775, 11930, 11930, -1918, -1918,
      26,     2,   275,     2,  1128,  1129,  1124,   355,   355,  1126,
   12109,   355,   355,   355,   355, 11930,   355,  1375, -1918,  1130,
    1139,   385,   337,  1138,   589, -1918, -1918, -1918, -1918, 15167,
      -7, 12860,  1136,   539,  1135,  1207,  1392,  1238, 11013,  1143,
    1145,  1399,  7155, 14445, -1918, 11930,  1400,   161,    96,   428,
      19,  1116, 11930,  1401, -1918,   598,  1361,  1362,  7155, 14474,
      28,  1149, 16749, 15383,   567, 11930, 11930,  1156,  1157,  1160,
    1158,  8661, -1918, -1918, -1918, -1918, 13588,   424,  1159, 16774,
   15410,  1164, -1918,   461, -1918,   477, 12991, -1918, -1918, -1918,
    1161, -1918,  1166, 13203, -1918,    89, -1918, -1918, 12275, -1918,
      50, 15167, 11930, 11930, 11930, 11930,   355,   387,  7155,  7155,
    1414,  7155,  7155,  7155,  1415,  7155,  7155,  7155,  7155,  7155,
    7155,  7155,  7155,  7155,  7155,  2370,  1416,  9655,  5064, -1918,
   -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918, -1918, 11930, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918, -1918, 11930, 11930, 11930, 11930, 11930, -1918, -1918,
   -1918,   599, 11930, 11930, -1918, 11930, -1918,  7155, 13588, 13588,
   -1918,   600, 14503, 14532,  1163, -1918, -1918, -1918,  1235, 11930,
   11930, -1918, -1918, -1918,   428, -1918,   428, 11930, 11930,  1173,
   -1918,  7155,    29, -1918, -1918, -1918, 11930, 11930,   601,   428,
     165,   170, 11930, 11930, -1918,   355,   606,  7155,  9655,  9655,
    1421,  1422,  1423,  2714, -1918, -1918,  1425, -1918,  1178, 12275,
    1174,  1428, -1918,  1430,  1431,  1432,  1433,   611,   438, -1918,
   12918, -1918, -1918,   -50, 13584, 13681, -1918, -1918, 14561,  -175,
    1327,  1437, 11259,  1185,  1438,  1190,    37,    38,   -96, -1918,
     -47, -1918,   308,  1441,  1443,  1444,  1445,  1446,  1447,  1448,
    1450,  1451,   339,  7155, 12275, -1918,  2589,  1202,  1454, -1918,
    1456,  1457,  1343,  1458, -1918,  1459,  1461,  1462, 11930,  7155,
    7155,  7155,  1465, 13714, -1918,  6086,  2110,   428,   428, -1918,
    9655, -1918, -1918, -1918, -1918, 13588, -1918, -1918, 11930, 13588,
   -1918, -1918, -1918, -1918, 12275, -1918,  1210,  1212, 13588, -1918,
   13588, -1918,   428, 13588,  1221, -1918,  1214, -1918,   428, 11930,
   11930,  1220,   570,  1225, 11352, -1918,  2748,  1228,  7155, -1918,
    1229, -1918, 14590, -1918, -1918, 11930,  1472,   443, 11930,  1480,
    1481,    12,  1483,  1236,  1484,  2802, -1918,   355,    29,    29,
    1486, -1918, -1918,  1240,  1241,  1239, -1918,  1489, -1918, -1918,
   -1918, -1918, -1918, -1918,   428,   -98, 11977, 11930, 15437, 16799,
   11930,  8907, 11930,  9655,  1242,   637,  1492,   167,   428, -1918,
    1243, 11930,  1493,  1495, 11930,   428, 11598, 11930,  9901,   355,
    5123, 11930, 11930,  1249,  1245, -1918,  1497, 16824, 16849, 16874,
   16899,  1498,    18,  1376,  1376,  7155,  1500,  1503,  1505,  7155,
     -91,  1506,  1507,  1508,  1509,  1511,  1512,  1513,  1515,  1516,
   -1918,  1518,   645, 15167, 15167, 15167, 15167, 15167, 15167,   355,
   13747, 13780, 13813,  1270,   355,   355, -1918, -1918, -1918,    50,
     355, 16924, 15167,  1271,  -185, 12275, 15167, -1918,  1520,   355,
   12275, 12275, -1918,   309, -1918,   428, -1918, 16949, 15464, -1918,
     355,  1521,   648,   653,  7155,  7155,  7155,  1524,  1523, -1918,
     179, 11930,  7155,  7155,  7155,  1273,  1274,  1525,  1527,  1528,
   -1918, 11930, 11930, 11930,  1277,  1279,  1281,  1295, -1918,  3004,
    7155, -1918, 11930, -1918,  1545, -1918,  1549, -1918, -1918, 10588,
     -77,  6402, -1918,  1299,  1301,  1302,  1304,  1305,  1306,  9153,
    1308,  1551, -1918,  9655, -1918, -1918, -1918,  1311, 11930, 11930,
   -1918, -1918, 15491,  1554,  1558,  1378, -1918, 11930, 11930, 11930,
   -1918,  1561,   730,   510,  1316,   646,  1319, 11930,    33,   355,
    1318,   355,  1328, -1918, -1918,  1116,   363, 11930,  1317, -1918,
   -1918,  3143, -1918, -1918,  1331,  1564, -1918,  3170, -1918,  1314,
    1568,   168,  3319, -1918,    12, -1918,   658, -1918, 11930, -1918,
   -1918,   179, 12159,  4875, -1918,  1333, 11930, 11930,  7155,  1339,
   -1918,  -195,   462,  1571, 16974,  1576,  1347, 16999,  1341,   659,
   17024,   660,  1577,  1578, -1918, -1918, 13588,  1342,  1583, 17049,
   -1918, -1918, 13846,  1345, -1918,  6337,  5396, 12275, -1918,  1581,
      29,  7657, -1918, -1918, -1918, 12275, 12275, -1918,    50, -1918,
    1585,  1588,  1591,  1594, -1918, -1918,   387,  1595,  1598,  1599,
   -1918, -1918, -1918,  1466,   -45,  1501,  1603, -1918, -1918, -1918,
   -1918, -1918, -1918, -1918, -1918, -1918,  1606,  1358, -1918, -1918,
   -1918, -1918, -1918, -1918, -1918, 11930, 11930, 11930, -1918, -1918,
   -1918,  1245, -1918, -1918, -1918, -1918, 11930,  1363,  1350, -1918,
   -1918, 11930, 11930,   355,   165, -1918, -1918, -1918, -1918,  1364,
    1365,  1610,   -91,  1613, 11930, -1918,  7155, 12275,  1479,  1485,
     617,  9655,  9655, 11930, -1918, 10342, 14619, 17074,  6588,   339,
     339, 11930, 11930, -1918,   418,  1368, 17099, -1918, -1918, 14648,
      -9, -1918,  1618,  1621,  7155,   387,   387,   387,   387,   387,
    6653,  1623, -1918, -1918,   661, 11930,  3358,  3740,  1626, -1918,
   -1918,  7155,  6839,   906, 17124, -1918, -1918,  9996, -1918, 13588,
   11930, -1918, 13588, 12275, 10247,  1116,  1371, -1918, -1918, -1918,
   -1918,  1380,  1377, 11930, 11930, 14677, 11930, 10980, -1918, 10980,
    7155, -1918, -1918,   428,    19,  1116, 11930,  1630, -1918,  1632,
   -1918,    12, 15518,  7155, 13588,  1635,   355, -1918,  1382,   355,
   11930, 13879, 13912,   668, -1918, 11930, 11930,  1391, -1918,  1402,
   -1918,  1423,  1654,  1655,  1431,  1656, -1918, -1918,  1658, 11930,
   -1918, -1918, 11930, 11684,  1659, 11930, -1918, -1918,  1409,  4875,
     671,  4527,  1660, -1918, -1918, -1918, -1918, -1918,   572, -1918,
   -1918, -1918,  1526,  1662,  1412,  1413,  1417, -1918,  1667,  7155,
   15167, 15167, 13945, 15167, -1918,  1419, 17149, 15545, -1918, -1918,
    9655,  9655, -1918,  1669, -1918, 12275,  1670, 11930, 11930,  1420,
   -1918,   673,   674, 15139,  3827,  1672,  1426, -1918, -1918, 11930,
    1424,  1427, 14706, 15572,  1673,  7155,  1679,  1434, 11930, -1918,
   -1918,   679,   172,   183,   227,   230,   252,  9404,   268, -1918,
    1674, 14735, -1918, -1918, -1918,  1502, -1918, 11930, 11930, -1918,
   -1918,  9655,  3916,  1681,  1435, 15167,   355, 12275, -1918, -1918,
   -1918, -1918,    33, -1918,  1116, -1918, 14764,  1436,  1439,  1442,
    1683,  1686,  1689,  3950, -1918, -1918, -1918,  1452,  1690,   682,
   -1918,  1696,  1698,   506, 12275, 11930, 11930,  1449,  7155,   688,
   12275, 17174, -1918, -1918, -1918, -1918, 17199, 13978, -1918, -1918,
   14793,  1163,  1212,  7155,   355, -1918, 11930,  1116,    27, -1918,
   -1918,  9655,  9655, 11930,  1699,   690, -1918, -1918, 11930,  1350,
   -1918, -1918, -1918,   695,   698, -1918, -1918,  3987,  4129,  7155,
     434,   580,  9655, -1918, -1918,   339,  7090, -1918, -1918, -1918,
    1701, -1918,  1455,  7155, -1918, 14822,  1704,  9655,   387,   387,
     387,   387,   387, -1918, -1918, 11930, 14851, 14880,   700, -1918,
   -1918, -1918, -1918, -1918, -1918,  1460,  1706,  1463, -1918,  1709,
      12, -1918, -1918, -1918,  1529, -1918, -1918, -1918, -1918, -1918,
   11930, 14011, 14044,  7155, -1918,  1711, 11930,  1467, -1918, 11930,
    1713,  1464,  1468, -1918, -1918,  4801, -1918,  1470,   703,   705,
   14909, -1918,  1471, 14077,  1475, -1918,  1473, -1918, -1918,   706,
    1474,   387,  7155,  1726,  1476,   387,  1728,   711,  1477, -1918,
   11930, -1918,  1730,  1596, 13003,  1482, -1918,   713,   271,   333,
     343,   346,   348,  4261, -1918, -1918,  1734,  1736, -1918, -1918,
   -1918,  1737, -1918,  1487, 12275, 11930, 11930,   716, -1918, 12275,
   14110, -1918, -1918, -1918,  1163,  1116,  1491, -1918, -1918, -1918,
   11930, 11930, -1918,  9655,  1741,   387,   130, -1918, -1918,   387,
     135, -1918,  1742, -1918, 14938, -1918, 11930, -1918,   308, -1918,
    1744,  9655,  9655,  9655,  9655,  9404, -1918, -1918, -1918, 10980,
   -1918, 11930, 17224, 14143,    35, 11930,  1496, -1918, -1918, 14176,
   14209,   718, -1918,   351, -1918,   360, -1918, -1918, -1918,  4503,
     -42, 13061, -1918,   719,   721,   724,   726,   362,   731,  1499,
     736, -1918, 11930, -1918,  7155, 14967, -1918, 11930, 11930, -1918,
     387,   387, -1918, -1918, -1918,   308,  1745,  1747,  1749,  1750,
    9655,  1752,  1753,  1754,  1504, 17249,   756,  1756, 14996, 15167,
     373,   384,   349, -1918, -1918, -1918, -1918,   761, -1918, -1918,
   -1918, 13588, -1918,  1517, -1918,  1757, -1918, 11930, 11930, -1918,
    1758,   762, -1918,  1519,  7155, -1918, 15025, 15054, -1918,  1759,
   13588, 13588,   764,  1760,  1762, -1918, -1918,   774, -1918,  1763,
   -1918, -1918,  1764, 13588, -1918, -1918, -1918
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1918, -1918, -1918, -1918,   386, -1918, -1918, -1918, -1918,  -369,
   -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918,  -746,  -115,  4180,  3448,  -165, -1918,  1309, -1918,
   -1918, -1918, -1918, -1918, -1918, -1917, -1918,   326,   149,  -169,
   -1918,  -127, -1918,    92,   374, -1918,  1783, -1918,   305,   -49,
   -1918, -1918,    -1,  -629,  -310, -1918, -1918, -1918, -1918, -1918,
   -1918, -1918,   717,  1786, -1918, -1918, -1918, -1918, -1258, -1255,
    1787, -1755,  1788, -1918, -1918, -1918,  1177, -1918,  -188, -1918,
   -1918, -1918, -1918,  2140, -1918, -1918, -1448,   246,  1792, -1918,
       5, -1918, -1918,    80, -1918, -1717,   524,  -179,  2831,  2354,
    -317,    22, -1918,   842,    47, -1918, -1918,    45,   220, -1708,
    -149,  1022, -1918,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -577
static const yytype_int16 yytable[] =
{
     143,   628,   124,  1508,  1510,  1062,  1677,  1881,   468,   960,
     961,  1068,  1917,   312,  1918,   662,   373,   503,   417,   476,
     644,   165,   167,   165,  1635,   510,   419,  1066,   447,   165,
     166,   165,  1362,  1297,  2041,   555,   578,  1754,   151,   667,
     346,  2173,   148,  1503,  1505,  1251,  1910,   351,   296,   352,
    1644,   291,   165,   296,  1400,   429,  1834,   762,  1796,   332,
    1764,   179,  -573,  1252,  1251,   183,   636,   637,   168,   377,
     169,   297,  1253,  1254,  1255,  1835,  1077,  1197,  1256,  1257,
     350,     5,  1252,  1495,   779,   600,  1401,  1402,   317,   291,
    1193,  1253,  1254,  1255,   376,  1194,  1398,  1256,  1257,  1251,
    1645,   777,   146,  1344,   754,   413,   755,   600,   720,   778,
     723,  1954,  1190,   754,   318,   755,   756,  1252,   735,   613,
     614,   615,  1965,   728,   790,   149,  1253,  1254,  1255,   347,
     319,   320,  1256,  1257,   636,   637,  2154,   636,   637,  1061,
     453,  2156,     4,   455,   353,   463,   463,   463,   326,   328,
     638,   331,   441,   442,   470,   412,   333,   416,   955,  -571,
     334,  1083,  1507,   658,   659,   660,   335,   336,  1344,   337,
     338,   147,   482,  1605,   144,  1775,   636,   637,   145,   200,
     674,  1721,   201,   636,   637,   202,  1344,  2146,   463,   339,
     452,   636,   637,   291,   636,   637,   291,   962,   203,   551,
     552,   291,   291,   463,   966,   150,  1363,  1364,  1365,  1366,
     636,   637,  1491,  1504,  1506,  1509,  2183,   477,    98,   783,
      99,   100,   101,   102,   103,   153,   639,   784,   107,   108,
    1845,   110,   636,   637,   154,   348,  1755,   117,   306,   597,
     598,   307,   117,   309,   117,   599,   437,   438,   439,  1067,
     117,   155,   117,  1878,   310,  1508,   754,   291,   755,   636,
     637,   117,  2059,   168,   789,   169,   663,   156,   664,   374,
     418,   291,   145,   117,   291,   576,  1351,  1025,   420,   754,
     751,   755,   168,   575,   169,  1298,  1367,   556,   579,   152,
     291,   291,  2174,   349,   291,   291,   291,   291,   441,   442,
     832,   763,   430,   764,   833,  -569,   431,   765,   123,   291,
     180,  1345,  1348,   291,   184,   376,  2097,   951,   378,   953,
     954,   157,   437,   438,   439,   440,   441,   442,   780,   601,
     781,   602,  1170,   158,   782,   603,   967,   291,   163,   291,
     291,   291,   168,   454,   169,   164,   441,   442,   441,   442,
     342,   601,   343,   602,   986,  1347,   291,   603,   437,   438,
     439,   440,   159,   291,   441,   442,   305,   729,   791,   730,
     781,   636,   637,   731,   792,   794,   636,   637,  1005,   160,
     887,   795,   441,   442,  2169,   785,   161,   437,   438,   439,
     440,  1084,  1085,   786,   437,   438,   439,   440,   744,   162,
     877,   631,   632,  1084,  1085,   437,   438,   439,   440,   640,
     645,   441,   442,   636,   637,   441,   442,  1041,   441,   442,
     441,   442,   463,   291,   636,   637,   580,   291,   291,  1465,
     745,   746,   744,   427,  1997,   176,   306,   428,   927,   307,
     308,   309,  1488,   291,   538,  1998,   539,   744,   449,  1251,
     766,   788,   310,   449,   449,   449,   647,  2196,   298,   789,
     648,   299,   449,   300,   745,   746,  1797,  1252,   636,   637,
     177,   636,   637,   802,   745,   746,  1253,  1254,  1255,   745,
     746,   739,  1256,  1257,   178,    67,    68,    69,    70,  1999,
    1251,    73,  2000,   636,   637,   797,   449,   181,   745,   746,
      82,   795,   291,    85,   747,   748,   182,  2232,  1252,   636,
     637,   449,   636,   637,  2001,   311,   897,  1253,  1254,  1255,
     833,  2054,   185,  1256,  1257,   356,   291,   186,   357,   754,
    2002,   755,   686,  2131,   145,   291,   867,  1300,   747,   748,
     463,   358,   463,   291,   463,   463,   470,  1013,   747,   748,
     187,   883,   550,   747,   748,   291,   291,   291,   463,   463,
     291,   167,  1681,   167,  1682,   291,  1043,   559,   560,   892,
     188,   894,   747,   748,   636,   637,   313,   189,   289,   314,
    2060,  2061,   749,   750,   636,   637,  2062,   636,   637,   636,
     637,   291,   636,   637,   190,  2132,  1322,   924,  1180,  1323,
    1074,   636,   637,   636,   637,  2133,   789,  2219,  2134,   754,
    2135,   755,   893,  2180,   636,   637,  1763,  1091,  1764,   291,
     291,  1859,  2181,  1860,  2190,   636,   637,  1102,   322,   323,
     931,  1569,  1570,   195,   833,  2217,  1063,   455,   455,   754,
     324,   755,  1240,  1520,   325,   191,  2218,  1320,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   192,   291,   291,   291,
     599,   301,   291,   193,   302,   194,  1874,   303,  1387,   304,
     726,   595,   596,   597,   598,   754,   833,   755,   928,   599,
      46,   470,   463,   470,   463,   463,   463,   463,   463,   463,
     196,   463,   463,   463,   463,  1027,   199,   463,   463,   463,
     167,  1033,   322,   323,   291,  1392,   958,   959,  1032,   636,
     637,   632,  1079,   833,   324,  1042,  2064,  2065,   330,   511,
     449,  1393,  2062,  1202,  1696,   646,  1746,  1747,   291,   833,
     740,   592,   593,   726,   595,   596,   597,   598,   168,   197,
     169,   198,   599,   291,  1196,   171,  1028,  1197,   172,  1071,
    2029,   173,   774,   174,   754,   932,   755,   977,  2030,   833,
    1045,   833,   833,   205,   833,   291,  1088,   441,   442,   206,
    1212,   291,  1213,   291,   289,   292,   470,  1100,   293,   441,
     442,   294,  1329,  1105,  1330,   463,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,  1214,   636,   637,  1051,   599,   441,   442,  1052,
    1377,   612,  1330,  1200,  -572,  1776,   315,   833,   291,  1235,
     291,   316,   295,   833,  1236,  1783,   621,  1281,   833,  1282,
     626,   833,  1283,   833,   341,  1285,   833,  1326,   449,   833,
     449,   833,   449,   449,   449,  1116,  1357,  1439,  1446,  1462,
     833,   833,   833,   833,  1470,   291,   449,   449,   833,  1487,
    2160,   321,   329,   833,   344,   291,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,  1350,  1603,   340,   291,   599,   833,
     754,   345,   755,  1657,   354,  1508,  1689,   833,  1750,   355,
     833,  1690,   360,   291,  1898,   833,  1780,  1803,  1805,  1890,
    1781,   833,   833,   833,   361,   291,  1937,  2202,  1214,  1955,
    1938,  1980,  1981,  1956,   291,   833,   833,  1996,   362,   363,
    2026,  1938,  1346,  1349,   789,   291,  2035,  1508,  2052,   774,
    2036,   369,  1938,  2055,   736,   737,  2056,   833,  2086,  1214,
     833,  2107,   833,  2108,  2114,   833,   381,   833,  1938,  2122,
     752,  2130,   774,   833,  2144,   833,  2179,  2186,  1938,  2187,
     833,   833,  2188,   833,  2189,   451,   833,  1230,   833,  2191,
     461,   464,   465,   833,  2193,   370,   371,   372,  2036,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   379,   449,
     449,   449,   449,   380,  2213,   449,   449,   449,  1938,  2220,
    2229,   382,  2239,   833,  2230,   774,  1938,   383,   774,  1453,
     414,  1454,  2242,   498,  1575,  1243,  2243,   425,   426,   432,
     774,   433,  1249,   458,  1463,   459,  1260,   474,   512,   291,
     145,   476,   478,   509,   479,  -204,   480,  1353,  -205,   481,
     486,   490,   504,   546,   549,   291,  -206,   558,   561,   557,
     874,   564,   565,  1489,   566,  1078,   577,  1080,   291,   428,
    1870,  1871,   612,   463,   888,   609,   610,   617,   618,   619,
     625,   649,   622,   665,   449,  1464,  1466,   627,   629,   650,
     630,   651,   652,   449,   653,   654,   655,   661,  1354,   668,
     666,   669,   681,   670,   671,   291,   291,   672,   291,   291,
     291,   384,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,  1541,  1542,   291,   673,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,   675,   676,   677,  1552,   599,   678,
     682,   689,   688,  1556,  1899,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   291,   463,   463,   697,   394,   395,
     396,   397,  1571,   698,   699,   710,   398,   399,   400,   401,
     715,   711,   713,   716,   402,   714,   403,  1412,   291,   717,
     718,   719,   721,   722,   741,   738,   753,   758,   760,  1591,
     404,   761,   144,   405,   291,   291,   291,   767,   799,   803,
     808,   824,   829,  1607,   835,   836,   837,   599,   868,   900,
    1613,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,   878,   879,   880,  1767,
     599,   898,   901,  1769,   936,   937,   774,  1779,   774,   774,
    1464,  1466,   940,   945,   949,  1056,   950,   732,   952,   979,
     291,   455,   774,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,   291,   291,   291,   981,
     599,   774,   982,   984,   993,   999,  1003,   291,  1006,  1054,
    1044,  1035,   463,  1037,  1050,  1055,   463,  1060,  1059,  1064,
     774,  1075,  1076,  1092,  1081,   463,  1094,   463,  1097,  1104,
     463,  1106,  1109,   406,   407,   408,  1110,  1117,  1118,  1119,
    1121,  1122,  1123,  1125,   409,   291,  1126,  1127,   410,  1128,
     411,  1129,  1130,  1131,  1132,  1133,   774,  1134,   376,  1137,
    1141,  1168,  1169,  1177,  1201,  1178,  2068,  1179,  1186,  1205,
    1189,  1195,  1217,  1209,  1225,  1227,  1218,  1219,  1250,  1272,
    1238,  1246,  1247,   463,  1273,  1275,  1292,  1289,   291,  1290,
     291,  1291,  1303,  1304,  1316,   871,  1305,   873,  1308,   875,
     876,   449,  1318,  1319,  1325,  1328,  1331,   291,  1332,  1333,
    1334,  1337,  1338,   889,   890,  1339,  1343,  1356,  1374,  1380,
    1358,  1359,   291,  1382,  1381,  1383,   291,  1391,  1388,  1396,
    1395,  1415,  1419,  1431,  1204,  1449,  -207,  1457,  1474,  1475,
    1476,  1479,  1480,  1788,  1788,  1482,  1481,  1483,  1484,  1485,
    1486,  1497,  1500,  1502,  1501,  1618,  1496,  1623,  1511,  1512,
    1527,  1513,  1514,  1515,  1516,  1517,  1777,  1518,  1519,  1523,
    1524,  1224,  1525,  1526,  1926,  1528,  1529,  1530,  1531,  1536,
    1547,   291,   291,   291,  1548,  1554,  1555,  1557,  1568,   291,
     291,   291,  1559,   449,   449,  1563,  1573,  1565,  1574,  1577,
    1579,  1578,  1584,  1586,  1587,  1590,  1588,   291,  1604,  1610,
    1602,  1611,  1608,  1629,  1634,  1627,  1640,  1628,   291,  1641,
    1636,  1642,  1647,  1648,  1649,  1650,   291,  1651,  1652,  1653,
     291,  1654,  1655,  1656,  1668,  1675,  1679,  1688,  1694,  1695,
    1701,  1702,  1703,  1704,  1709,  1705,  1710,  1012,  1711,  1014,
    1015,  1016,  1017,  1018,  1019,   774,  1021,  1022,  1023,  1024,
    1712,  1717,  1029,  1030,  1031,  1718,  1724,  1733,  1725,  1726,
    1739,  1727,  1728,  1729,  1740,  1741,  1732,  1745,  1735,  1849,
    1771,   376,  1759,  1773,  1766,  1774,  1340,  1798,  1749,   470,
     470,  1752,  1800,  1806,  1807,   291,  1790,  1810,  1818,  1720,
    1323,  1824,  1360,  1770,  1825,  1809,  1795,  1826,  1813,  1802,
    1827,  1829,  1762,   463,  1830,  1831,  1836,  1832,  1920,  1837,
     449,  1838,  1197,   291,   449,  1839,  1852,  1844,   291,  1854,
    1857,  1850,  1851,   449,  1879,   449,  1858,  1880,   449,  1889,
    1875,  1098,  1894,  1912,  1913,  1929,  1924,  1558,  1925,  1914,
    1107,  1930,  1413,  1414,   789,  1416,  1417,  1418,  -576,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  -574,
    1942,  1943,  1944,  1817,  1945,  1949,  1953,  1958,  1960,  1961,
    1962,  1959,  1964,  1970,  1963,  1975,  1976,  1979,  1984,  1991,
    2003,   449,  1987,  1985,  2074,  1988,  1993,  2010,  2005,  2011,
    2020,  1994,  2021,   291,  2017,  2022,  2025,  2018,   291,   291,
    2019,  1443,  2027,  2091,  2028,  2051,  2033,  2071,   455,   455,
    2076,  2024,  2088,  2072,  2087,  2090,  1828,  2098,  2092,  2101,
    2089,   291,  2102,  2106,  -575,  1458,  2103,   291,  2110,  2112,
    2113,  2115,  2118,  2119,  2121,  2123,  2125,  2126,   291,  2129,
    2137,  1471,  2138,  2140,  2141,  2148,   463,  2152,  2157,   463,
    2162,  2203,  1865,  2204,  2176,  2205,  2206,  2192,  2208,  2209,
    2210,  2211,  2214,  2225,  2228,  2235,  2240,   291,  2241,  2244,
    2245,  1353,  2170,  1606,  2224,  1671,  2231,  1823,   376,  2139,
     291,   470,   798,  2042,  1853,  2014,   122,  1373,  1638,   133,
     134,   135,   939,  2066,  1903,   141,  1921,  1521,  1761,  1909,
       0,  1908,  1911,  1789,     0,  1882,  1883,  1884,  1885,  1886,
    1888,  1099,     0,  1533,  1534,  1535,   470,     0,     0,  2161,
       0,     0,  1922,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1564,     0,     0,     0,     0,     0,     0,   580,
       0,     0,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,   449,   449,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1622,     0,     0,     0,  1386,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,  1639,
       0,     0,     0,  1643,     0,     0,     0,     0,     0,     0,
     291,     0,     0,     0,     0,  2047,     0,     0,   291,   291,
       0,  2015,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,   291,
       0,     0,     0,     0,   455,     0,     0,     0,     0,     0,
     291,     0,     0,     0,   291,     0,     0,     0,  1691,  1692,
    1693,     0,     0,     0,  2046,     0,  1698,  1699,  1700,     0,
       0,     0,     0,     0,     0,     0,     0,   376,     0,     0,
    1444,  1445,     0,     0,  1715,     0,     0,     0,     0,     0,
     291,     0,     0,     0,     0,  1723,     0,     0,     0,     0,
       0,     0,     0,  1731,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,     0,     0,   449,     0,   291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   774,     0,   774,     0,     0,     0,  2078,  2079,
    2080,  2081,  2082,     0,     0,     0,     0,     0,     0,   449,
       0,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   831,   595,   596,   597,   598,     0,
     291,     0,  1794,   599,     0,   754,     0,   755,  1539,     0,
       0,     0,     0,     0,   449,     0,     0,     0,   291,   291,
     291,   291,   291,     0,     0,     0,     0,     0,     0,     0,
    1816,  2116,     0,     0,     0,  2120,     0,  1544,     0,     0,
       0,  1546,  2147,     0,     0,     0,   759,     0,     0,     0,
    1550,     0,  1551,     0,     0,  1553,     0,     0,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,     0,  2153,     0,     0,     0,  2155,
       0,     0,     0,     0,     0,     0,     0,     0,   463,     0,
       0,     0,     0,     0,     0,  2167,     0,     0,  1593,     0,
    1856,   291,     0,     0,     0,     0,     0,   463,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     463,     0,     0,     0,     0,     0,     0,     0,  1794,     0,
       0,     0,     0,     0,     0,     0,   423,     0,   776,     0,
    2200,  2201,     0,     0,     0,  1895,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   450,     0,     0,     0,   460,     0,     0,
       0,     0,   466,     0,  1919,     0,     0,     0,     0,     0,
     471,     0,     0,     0,     0,     0,     0,  1928,     0,     0,
       0,     0,     0,     0,     0,     0,   483,   484,   485,     0,
     487,   488,   489,     0,   491,   492,   493,   494,   495,   496,
     497,     0,   499,   500,   501,   502,     0,     0,     0,   506,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,  1794,  1540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1430,     0,     0,   774,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,  1992,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   567,   569,   571,   572,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   606,   506,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   774,     0,     0,     0,  1808,     0,
       0,     0,     0,     0,   624,     0,     0,     0,     0,     0,
       0,     0,  2034,     0,   634,   635,   774,     0,     0,     0,
     635,     0,     0,     0,     0,     0,     0,  2043,     0,     0,
     506,   657,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,  1794,   599,   679,   506,     0,     0,     0,
     683,   684,   685,     0,   687,     0,   449,  2073,   690,   691,
     692,     0,     0,   693,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   449,   449,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   449,     0,
       0,     0,     0,   508,     0,     0,     0,  1794,     0,     0,
       0,     0,   725,     0,     0,     0,   506,   734,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   742,   743,     0,  2117,     0,     0,     0,
       0,  1904,     0,     0,  1906,  1522,     0,     0,   775,     0,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,   804,   805,
     806,   807,   599,     0,     0,     0,   812,     0,     0,     0,
     816,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   830,   569,     0,   607,   608,   834,
       0,     0,     0,   838,   839,   840,   841,   842,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   852,   853,   854,
     856,   857,   858,   859,   860,   861,   862,   863,   864,   864,
       0,   869,   870,     0,   872,     0,     0,     0,     0,     0,
       0,     0,     0,   881,   656,     0,   885,   886,  1794,     0,
       0,     0,     0,   864,     0,     0,     0,     0,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   915,   917,   919,   920,   921,   922,   923,
       0,   925,   926,     0,     0,     0,     0,     0,  1794,   933,
     934,   935,     0,     0,  1562,     0,     0,   941,   942,   943,
     944,     0,   506,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     733,   567,   725,   963,     0,     0,     0,   968,   969,   970,
     971,   972,   973,   974,   975,   976,     0,     0,     0,     0,
       0,   983,     0,   985,     0,     0,   987,     0,  1580,     0,
     506,   506,   506,   992,     0,   506,   995,   996,   997,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1020,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1477,     0,   506,     0,     0,
       0,     0,     0,     0,  1039,     0,  1040,     0,     0,   925,
     926,     0,     0,     0,     0,     0,     0,     0,  1053,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,     0,  1069,     0,
       0,     0,     0,  1072,  1073,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   506,     0,
    1089,  1090,   895,     0,   506,     0,   506,  1096,     0,     0,
       0,  1089,     0,  1103,     0,     0,     0,     0,     0,  1108,
       0,     0,     0,  1111,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,  1135,
       0,   917,     0,  1138,     0,     0,   946,   947,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,   506,     0,
    1713,     0,     0,     0,     0,     0,     0,     0,   506,  1182,
    1183,     0,     0,     0,   989,   990,   991,     0,     0,   994,
     507,     0,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,  2222,   599,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   506,     0,
       0,  1034,  2236,  2238,     0,     0,  1223,     0,     0,     0,
    1229,     0,     0,     0,     0,  2246,     0,     0,   506,     0,
       0,     0,     0,     0,     0,     0,  1244,  1245,     0,     0,
       0,     0,  1248,     0,     0,   570,     0,     0,   507,     0,
    1065,     0,     0,     0,     0,     0,     0,     0,     0,  1274,
       0,     0,  1276,     0,   507,   507,     0,     0,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,     0,  1093,     0,
    1095,     0,     0,     0,  1293,     0,  1295,  1296,     0,  1768,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1314,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,  1772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1336,     0,
       0,     0,     0,     0,     0,  1342,     0,   507,     0,     0,
       0,     0,  1355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1378,  1379,     0,     0,     0,
       0,   506,  1171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1181,     0,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,  1407,  1408,  1409,  1410,   599,   507,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1208,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,  1216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1433,     0,     0,     0,     0,     0,     0,
       0,     0,  1237,  1434,  1435,  1436,  1437,  1438,     0,     0,
       0,     0,  1440,  1441,     0,  1442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1778,     0,     0,     0,  1451,
    1452,     0,     0,     0,     0,     0,   570,  1455,  1456,     0,
       0,     0,     0,     0,     0,     0,  1460,  1461,     0,     0,
       0,     0,  1467,  1468,     0,     0,     0,     0,   506,   506,
     855,     0,     0,     0,  1892,     0,     0,     0,     0,   865,
     866,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,  1499,     0,   891,   599,     0,     0,     0,   507,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,   918,     0,     0,  1532,     0,
       0,     0,     0,     0,     0,  1385,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,  1545,     0,
       0,     0,     0,   507,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1467,
    1468,     0,     0,     0,  1561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1567,     0,     0,  1572,     0,
       0,  1432,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,   507,   507,     0,     0,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1594,     0,     0,
    1597,   506,  1600,   506,     0,     0,     0,     0,     0,     0,
       0,  1609,     0,     0,  1612,     0,  1609,  1615,  1617,     0,
       0,  1625,  1626,     0,     0,     0,     0,     0,   507,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,  1472,  1473,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,   507,
     599,     0,     0,     0,     0,   507,     0,   507,     0,     0,
       0,  1697,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1706,  1707,  1708,     0,     0,     0,     0,     0,     0,
    1714,     0,  1716,     0,     0,     0,     0,     0,     0,  1719,
       0,     0,     0,     0,  1543,     0,     0,     0,     0,     0,
       0,     0,   918,   506,  1139,     0,     0,     0,  1736,  1737,
       0,     0,     0,     0,     0,     0,     0,  1742,  1743,  1744,
       0,     0,     0,     0,     0,     0,     0,  1753,     0,     0,
       0,     0,     0,     7,     8,     0,     0,  1765,     0,   507,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,     0,     0,     0,     0,     0,     0,     0,  1782,     0,
       0,     0,     0,     0,     0,     0,  1791,  1792,     0,     0,
       0,     0,     0,     0,     0,  1599,     0,  1601,     0,     0,
       0,     0,     0,     0,     0,     0,  1893,   507,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,  1821,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,  1840,  1841,  1842,     0,     0,
     768,    55,     0,     0,    58,   769,  1843,   770,   771,     0,
     772,  1846,  1847,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1983,  1855,     0,     0,     0,    79,     0,
       0,   506,   506,  1863,     0,  1864,     0,     0,     0,     0,
       0,  1872,  1873,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,     0,     0,     0,     0,
     506,     0,     0,     0,     0,  1891,     0,  1734,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1902,     0,     0,
    1905,     0,     0,     0,  1907,     0,   757,     0,     0,     0,
       0,     0,     0,  1846,  1847,     0,  1916,     0,     0,     0,
       0,     0,   507,     0,     0,     0,  1923,     0,     0,     0,
       0,     0,  2009,     0,     0,     0,     0,     0,     0,     0,
    1934,     0,     0,     0,     0,  1940,  1941,     0,   964,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1946,
       0,     0,  1947,  1946,     0,  1950,  2023,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,     0,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
     506,   506,   599,  2057,     0,     0,     0,  1977,  1978,     0,
       0,     0,   882,     0,     0,     0,     0,     0,     0,  1986,
       0,     0,     0,     0,     0,     0,     0,     0,  1995,     0,
       0,     0,     0,     0,     0,     0,     0,   569,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2006,  2007,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,   507,
     507,     0,     0,   929,     0,  1861,  1862,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,  2031,  2032,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2045,     0,     0,     0,
       0,   506,   506,  2050,     0,     0,     0,     0,  2053,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,  2058,     0,   506,     0,     0,
       0,     0,     0,     0,     0,  2083,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
    2094,     0,     0,     0,     0,     0,  2099,     0,     0,  2100,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,  1973,  1974,   170,     0,   175,     0,
    2124,     0,   507,     0,   507,     0,     0,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,  2142,  2143,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2149,  2150,     0,   506,     0,  2008,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2159,  2136,     0,     0,
       0,   506,   506,   506,   506,   506,     0,     0,     0,     0,
       0,  1940,     0,     0,     0,  2175,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,     0,  1154,  1155,
    1156,  1157,     0,  1159,  1160,  1161,  1162,     0,     0,     0,
       0,     0,  2195,     0,     0,  2048,  2049,  2198,  2199,  1174,
       0,  1176,     0,   448,     0,     0,     0,     0,     0,     0,
     506,  1185,     0,     0,     0,     0,  2067,     0,  1191,  1192,
       0,     0,     0,     0,     0,     0,     0,  1203,     0,     0,
       0,  2077,     0,     0,   507,     0,     0,  2226,  2227,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   534,   535,   536,   537,   540,   541,   542,
     543,   544,   545,     0,   547,   548,     0,     0,     0,     0,
       0,     0,     0,   553,   554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   562,   563,     0,     0,     0,
       0,     0,  1822,     0,     0,     0,     0,     0,     0,  1299,
    1301,  1302,     0,     0,     0,  1306,  1307,  2151,     0,  1310,
    1311,  1312,  1313,     0,  1315,     0,     0,     0,     0,  1321,
       0,     0,     0,     0,     0,  2163,  2164,  2165,  2166,  2168,
       0,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,  2182,
       0,     0,     0,   599,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,   507,   507,  1957,   580,   599,     0,   998,     0,
       0,     0,     0,     0,  2207,     0,   956,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1406,
       0,   507,     0,     0,  1411,   694,   695,   696,     0,     0,
       0,   700,   701,   702,   703,   704,   705,   706,     0,   707,
       0,     0,     0,     0,   708,   709,     0,     0,   712,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   724,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,   165,     0,     0,     0,     0,     0,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   421,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1469,     0,     0,     0,     0,   242,   243,
     244,   245,     0,     0,     0,     0,   246,     0,     0,     0,
       0,   507,   507,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    25,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   570,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,   899,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     831,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,   507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1581,     0,     0,  2105,     0,
       0,     0,     0,   507,     0,     0,   264,     0,     0,     0,
     265,     0,     0,     0,     0,   267,   268,   269,   507,   270,
     271,   272,   580,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1619,     0,     0,
       0,   273,   422,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,     0,     0,     0,   623,     0,     0,
     278,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     384,  1658,  1659,  1660,  1661,  1662,  1663,  1664,     0,     0,
       0,     0,  1669,  1670,     0,     0,     0,     0,  1672,     0,
    1674,     0,     0,     0,  1678,     0,     0,  1680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1687,     0,
       0,     0,     0,     0,   385,   386,   387,   388,   389,   390,
     391,   392,   393,     0,     0,     0,     0,   394,   395,   396,
     397,     0,     0,     0,   507,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   403,     0,     0,     0,     0,
       0,     0,   507,   507,   507,   507,   507,     0,     0,   404,
       0,     0,   405,     0,     0,     0,   301,     0,     0,   302,
       0,     0,   303,     0,   304,     0,     0,     0,     0,     0,
       0,  1748,     0,  1751,     0,    46,     0,  1758,     0,  1760,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   435,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
    1785,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   580,     0,  1198,     0,   599,     0,     0,     0,
       0,     0,   406,   407,   408,     0,     0,     0,     0,     0,
       0,     0,     0,   409,     0,     0,     0,   410,     0,   411,
     117,     0,     0,     0,     0,     0,     0,  1215,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,   207,     6,   384,     0,
     599,  1848,  1784,   208,   209,   210,   828,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
       0,     0,  1620,   386,   387,   388,   389,   390,   391,   392,
     393,   242,   243,   244,   245,   394,   395,   396,   397,   246,
     247,     0,     0,   398,   399,   400,   401,     0,     0,   248,
     249,   402,     0,   403,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   253,    25,   404,   254,     0,
     405,     0,     0,     0,   255,     0,     0,   256,     0,     0,
     257,     0,   258,     0,  1931,     0,     0,  1932,     0,    42,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   260,     0,    56,    57,     0,   261,     0,
     262,     0,     0,   263,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,  1399,     0,    85,  1966,  1967,
       0,  1969,     0,     0,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   831,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
     406,   407,   408,   265,   266,     0,     0,     0,   267,   268,
     269,   409,   270,   271,   272,   410,  1007,   411,   117,     0,
       0,     0,     0,  2012,  2013,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   365,     0,     0,     0,
    1621,     0,  1459,   278,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   207,
       6,   384,  2044,     0,     0,     0,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   242,   243,   244,   245,   394,   395,
     396,   397,   246,   247,     0,     0,   398,   399,   400,   401,
       0,     0,   248,   249,   402,     0,   403,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,    25,
     404,   254,     0,   405,     0,     0,     0,   255,     0,     0,
     256,     0,     0,   257,     0,   258,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,    56,    57,
       0,   261,     0,   262,     0,     0,   263,     0,  1582,  1583,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,  1206,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   406,   407,   408,   265,   266,     0,     0,
       0,   267,   268,   269,   409,   270,   271,   272,   410,     0,
     411,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1676,     0,     0,   273,   274,     0,
       0,     0,     0,  1683,   275,     0,     0,  2216,     0,   365,
     207,   165,   384,   277,   434,     0,   278,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   421,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   242,   243,   244,   245,   394,
     395,   396,   397,   246,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   403,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   253,
      25,   404,   254,     0,   405,     0,     0,     0,   301,     0,
       0,   302,     0,     0,   303,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1819,     0,     0,     0,     0,     0,     0,     0,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1207,     0,     0,   436,     0,     0,     0,
       0,     0,     0,   264,   406,   407,   408,   265,     0,     0,
       0,     0,   267,   268,   269,   409,   270,   271,   272,   410,
       0,   411,   117,   437,   438,   439,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   422,
       0,     0,     0,     0,     0,   275,     0,   441,   442,     0,
     443,     0,   444,   207,     6,   364,   445,   278,     0,     0,
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
       0,     0,     0,     0,  1538,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
     265,   266,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   274,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,   207,     6,     0,   366,     0,   680,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   265,   266,     0,     0,     0,   267,   268,   269,     0,
     270,   271,   272,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   505,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   365,   207,     6,  1722,     0,   573,
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
       0,     0,     0,     0,     0,  1814,     0,     0,     0,  1815,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,   266,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   274,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   365,   207,     6,     0,   277,
       0,     0,   278,   208,   209,   210,     0,     0,   211,   212,
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
     599,     0,     0,     0,     0,     0,  1868,     0,     0,     0,
    1869,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,   266,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,  1887,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   643,   207,     6,     0,
     325,   573,     0,   278,   208,   209,   210,     0,     0,   211,
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
       0,   599,     0,     0,     0,     0,     0,  1896,     0,     0,
       0,  1897,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   265,   266,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   274,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,   276,   207,     6,
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
       0,     0,   599,     0,     0,     0,     0,     0,  2069,     0,
       0,     0,  2070,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   265,   266,     0,     0,     0,
     267,   268,   269,     0,   270,   271,   272,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   274,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,   207,
       6,     0,   277,     0,     0,   278,   208,   209,   210,     0,
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
       0,     0,     0,   787,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,   265,   266,     0,     0,
       0,   267,   268,   269,     0,   270,   271,   272,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   505,     0,
       0,     0,     0,     0,   275,     0,     0,     0,     0,   365,
     207,     6,     0,   568,     0,     0,   278,   208,   209,   210,
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
       0,     0,     0,     0,   793,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,   265,   266,     0,
       0,     0,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   505,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     365,   207,     6,     0,     0,   573,     0,   278,   208,   209,
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
       0,     0,     0,     0,     0,   956,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   265,   266,
       0,     0,     0,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     274,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   611,   207,     6,     0,   277,     0,     0,   278,   208,
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
       0,     0,     0,     0,     0,     0,   957,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,   265,
     266,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   274,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,   620,   207,     6,     0,   277,     0,     0,   278,
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
       0,     0,     0,     0,     0,     0,     0,  1004,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
     265,   266,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   505,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,   207,     6,     0,   916,     0,  1384,
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
       0,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   265,   266,     0,     0,     0,   267,   268,   269,     0,
     270,   271,   272,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   505,     0,     0,     0,     0,     0,   275,
     207,     6,     0,     0,   365,  1598,     0,   208,   209,   210,
       0,   278,   211,   212,   213,   214,   215,   216,   217,   218,
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
       0,     0,     0,     0,  1113,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,   265,   266,     0,
       0,     0,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   505,
       0,     0,     0,     0,     0,   275,   207,     6,     0,     0,
     365,     0,     0,   208,   209,   210,     0,   278,   211,   212,
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
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,   266,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   365,   207,     6,     0,
    1730,     0,     0,   278,   208,   209,   210,     0,     0,   211,
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
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1115,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   265,   266,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   641,  1887,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,   643,   207,     6,
       0,   325,     0,     0,   278,   208,   209,   210,     0,     0,
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
       0,     0,  1153,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   265,   266,     0,     0,     0,
     267,   268,   269,     0,   270,   271,   272,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   505,     0,     0,
       0,     0,     0,   275,   207,   165,   384,     0,   365,     0,
       0,   208,   209,   210,     0,   278,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   421,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   242,
     243,   244,   245,   394,   395,   396,   397,   246,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   402,
       0,   403,   250,   251,   252,     0,     0,     0,     0,     0,
       0,     0,     0,   253,    25,   404,   254,     0,   405,   207,
     165,   384,     0,     0,     0,     0,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   421,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   242,   243,   244,   245,   394,   395,
     396,   397,   246,     0,     0,     0,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   403,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,    25,
     404,   254,     0,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   406,   407,
     408,   265,     0,     0,     0,     0,   267,   268,   269,   409,
     270,   271,   272,   410,     0,   411,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   422,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   365,     0,     0,     0,  1616,     0,
       0,   278,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1163,     0,     0,     0,     0,     0,
       0,     0,   264,   406,   407,   408,   265,     0,     0,     0,
       0,   267,   268,   269,   409,   270,   271,   272,   410,     0,
     411,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   422,     0,
       0,     0,     0,     0,   275,     0,     0,     0,     0,   365,
     207,   165,   384,  1901,     0,     0,   278,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   421,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,  1620,   386,   387,   388,
     389,   390,   391,   392,   393,   242,   243,   244,   245,   394,
     395,   396,   397,   246,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   403,   250,   251,
     252,     0,     0,     0,     0,     0,     0,     0,     0,   253,
      25,   404,   254,     0,   405,   207,   165,   384,     0,     0,
       0,     0,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   421,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     242,   243,   244,   245,   394,   395,   396,   397,   246,     0,
       0,     0,   398,   399,   400,   401,     0,     0,     0,     0,
     402,     0,   403,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,    25,   404,   254,     0,   405,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   264,   406,   407,   408,   265,     0,     0,
       0,     0,   267,   268,   269,   409,   270,   271,   272,   410,
       0,   411,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   422,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     365,     0,     0,     0,  1784,     0,     0,   278,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1164,     0,     0,     0,     0,     0,     0,     0,   264,   406,
     407,   408,   265,     0,     0,     0,     0,   267,   268,   269,
     409,   270,   271,   272,   410,     0,   411,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   422,     0,     0,     0,     0,     0,
     275,   207,   165,     0,     0,   365,     0,     0,   208,   209,
     210,     0,   278,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     421,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   243,   244,   245,
       0,     0,     0,     0,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   252,     0,     0,     0,     0,     0,   207,   165,     0,
     253,    25,   884,   254,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   421,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,   244,   245,     0,     0,     0,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   253,    25,     0,   254,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,   264,     0,     0,     0,   265,     0,
       0,     0,  1165,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     642,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   643,     0,     0,     0,   325,     0,     0,   278,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
     264,  1166,     0,     0,   265,     0,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   422,     0,     0,     0,
       0,     0,   275,   207,   165,     0,     0,   365,     0,     0,
     208,   209,   210,     0,   278,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   421,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   242,   243,
     244,   245,     0,     0,     0,     0,   246,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    25,     0,   254,   207,   165,     0,  1335,
       0,     0,     0,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   421,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,   244,   245,     0,     0,     0,     0,   246,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,   250,   251,   252,    43,    44,    45,
      46,     0,     0,    48,     0,   253,    25,     0,   254,     0,
     768,    55,     0,     0,    58,   769,     0,   770,   771,     0,
     772,     0,     0,     0,  1047,     0,   264,     0,     0,     0,
     265,     0,     0,     0,     0,   267,   268,   269,    79,   270,
     271,   272,  1048,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   422,    94,    95,    96,     0,     0,   275,     0,
       0,     0,     0,   365,  1101,     0,     0,     0,     0,     0,
     278,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,     0,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   422,     0,     0,     0,     0,
       0,   275,   207,   165,     0,  1498,   365,     0,     0,   208,
     209,   210,     0,   278,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   421,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,   207,   165,     0,  1560,     0,
       0,     0,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   421,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,   243,   244,   245,     0,     0,     0,     0,   246,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   250,   251,   252,    43,    44,    45,    46,
       0,     0,    48,     0,   253,    25,     0,   254,     0,   768,
      55,     0,     0,    58,   769,     0,   770,   771,     0,   772,
       0,     0,     0,     0,     0,   264,     0,     0,     0,   265,
       0,     0,     0,     0,   267,   268,   269,    79,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   422,    94,    95,    96,     0,     0,   275,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   278,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1172,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,     0,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   422,     0,     0,     0,     0,     0,
     275,   207,   165,     0,     0,   365,     0,     0,   208,   209,
     210,     0,   278,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     421,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   243,   244,   245,
       0,     0,     0,     0,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   252,     0,     0,     0,     0,     0,   207,   165,     0,
     253,    25,     0,   254,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   421,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   243,   244,   245,     0,     0,     0,     0,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   251,   252,     0,     0,
       0,     0,     0,     0,     0,     0,   253,    25,     0,   254,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,   264,     0,     0,     0,   265,     0,
       0,     0,  1173,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     422,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   365,  1614,     0,     0,     0,     0,     0,   278,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
     264,  1175,     0,     0,   265,     0,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   422,     0,     0,     0,
       0,     0,   275,   207,   165,     0,     0,   365,  1948,     0,
     208,   209,   210,     0,   278,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   421,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   384,     0,     0,     0,     0,     0,   242,   243,
     244,   245,     0,     0,     0,     0,   246,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    25,     0,   254,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,     0,   394,
     395,   396,   397,     0,     0,     0,     0,   398,   399,   400,
     401,     0,     0,     0,     0,   402,     0,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,     0,   405,     0,     0,     0,   301,     0,
       0,   302,     0,     0,   303,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,     0,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,   264,     0,   599,     0,
     265,     0,     0,     0,     0,   267,   268,   269,  1288,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,   165,   384,     0,     0,     0,     0,     0,
       0,   273,   422,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,   406,   407,   408,     0,     0,     0,
     278,     0,     0,     7,     8,   409,     0,     0,     0,   410,
       0,   411,   117,     0,     0,     0,     0,     0,   385,   386,
     387,   388,   389,   390,   391,   392,   393,     0,     0,     0,
       0,   394,   395,   396,   397,     0,     0,   441,   442,   398,
     399,   400,   401,     0,  -570,     0,  1592,   402,     0,   403,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,     0,     0,   405,     0,     0,     0,
     301,     0,     0,   302,     0,     0,   303,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,   435,    43,    44,    45,
      46,     7,     8,    48,     0,     0,     0,     0,     0,     0,
     768,    55,     0,     0,    58,   769,     0,   770,   771,     0,
     772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     7,
       8,   599,     0,    94,    95,    96,   406,   407,   408,     0,
       0,  1309,     0,     0,     0,     0,     0,   409,     0,     0,
       0,   410,     0,   411,   117,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,   754,     0,   755,  1784,     0,   768,    55,
       0,     0,    58,   769,     0,   770,   771,     0,   772,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   988,     0,
       0,     0,     0,     0,     7,     8,    79,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,    94,    95,    96,     0,     0,   768,    55,     0,     0,
      58,   769,     0,   770,   771,     0,   772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    79,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,    94,
      95,    96,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,  1036,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,   768,    55,     0,     0,    58,   769,     0,   770,   771,
       0,   772,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,    79,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,  1038,     0,    43,    44,    45,    46,
       0,     0,    48,     0,    94,    95,    96,     0,     0,   768,
      55,     0,     0,    58,   769,     0,   770,   771,     0,   772,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,  1239,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   768,    55,     0,     0,    58,   769,
       0,   770,   771,     0,   772,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,    79,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,  1241,     0,    43,
      44,    45,    46,     0,     0,    48,     0,    94,    95,    96,
       0,     0,   768,    55,     0,     0,    58,   769,     0,   770,
     771,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,  1242,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,   768,    55,     0,
       0,    58,   769,     0,   770,   771,     0,   772,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    79,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
    1261,     0,    43,    44,    45,    46,     0,     0,    48,     0,
      94,    95,    96,     0,     0,   768,    55,     0,     0,    58,
     769,     0,   770,   771,     0,   772,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,  1279,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     768,    55,     0,     0,    58,   769,     0,   770,   771,     0,
     772,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,    79,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,  1294,     0,    43,    44,    45,    46,     0,
       0,    48,     0,    94,    95,    96,     0,     0,   768,    55,
       0,     0,    58,   769,     0,   770,   771,     0,   772,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,  1327,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,   768,    55,     0,     0,    58,   769,     0,
     770,   771,     0,   772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,  1490,     0,    43,    44,
      45,    46,     0,     0,    48,     0,    94,    95,    96,     0,
       0,   768,    55,     0,     0,    58,   769,     0,   770,   771,
       0,   772,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    79,
       0,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,    94,    95,    96,     0,     0,     0,
      -4,    -4,    -4,  1394,     0,     0,     0,     0,     0,     0,
       0,  2127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,     0,    -4,    -4,
       0,     0,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,  2184,
      -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       6,     0,     0,     0,     0,     0,    -4,    -4,    -4,     7,
       8,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     9,    10,    11,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1397,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
      15,    16,     0,     0,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,     0,    25,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    42,    43,    44,    45,    46,    47,     0,    48,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,    89,    90,    91,
       0,     0,     0,    92,     0,     0,     0,     0,    93,    94,
      95,    96,   165,   384,    97,     0,    98,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,   117,     0,     0,     0,     0,     0,   385,   386,   387,
     388,   389,   390,   391,   392,   393,     0,     0,     0,     0,
     394,   395,   396,   397,   165,   384,     0,     0,   398,   399,
     400,   401,     0,     0,     0,     0,   402,     0,   403,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,     0,     0,   405,     0,     0,     0,   301,
     415,   384,   302,     0,     0,   303,     0,   304,     0,   385,
     386,   387,   388,   389,   390,   391,   392,   393,    46,     0,
       0,     0,   394,   395,   396,   397,     0,     0,     0,     0,
     398,   399,   400,   401,     0,   435,     0,     0,   402,     0,
     403,     0,     0,     0,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   404,     0,     0,   405,   394,   395,
     396,   397,     0,     0,     0,     0,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     404,     0,     0,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   406,   407,   408,     0,     0,
       0,     0,     0,     0,     0,     0,   409,     0,     0,     0,
     410,     0,   411,   117,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1492,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   406,   407,   408,
       0,     0,     0,     0,     0,     0,     0,     0,   409,     0,
       0,     0,   410,     0,   411,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   406,   407,   408,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,     0,     0,   410,     0,
     411,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1493,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1537,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1665,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1666,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1667,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1812,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1935,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1936,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1968,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2039,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2095,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2096,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2111,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2145,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2172,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2177,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2178,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    1082,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  1140,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  1187,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  1188,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1232,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1264,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1284,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  1341,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  1361,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  1447,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    1448,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  1494,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  1566,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  1866,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1877,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1915,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1989,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  2004,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  2016,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  2040,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    2075,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  2084,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  2085,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  2109,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  2158,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  2197,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  2215,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  2233,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  2234,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
     727,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,   948,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,  1982,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,   754,     0,   755,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
    1010,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,  1058,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,  1211,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,  1278,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,  1280,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,  1286,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,  1287,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,  1376,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,  1390,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,  1595,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
    1686,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,  1738,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,  1927,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,  1972,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,  1990,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   809,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   810,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   811,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   813,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   814,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   815,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   817,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   818,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   819,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   820,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   821,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   822,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   823,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   825,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   826,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   827,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   896,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   930,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   978,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   998,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1000,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1001,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1002,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1008,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1009,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1046,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1057,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1120,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1124,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1136,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1210,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1220,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1221,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1222,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1231,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1233,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1234,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1263,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1265,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1266,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1267,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1268,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1269,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1270,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1271,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1277,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1375,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1389,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1596,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1630,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1631,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1632,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1633,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1673,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1685,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1799,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1801,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1804,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1811,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1867,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1876,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1900,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1971,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  2037,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  2038,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  2171,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  2212
};

static const yytype_int16 yycheck[] =
{
       3,   318,     3,  1258,  1262,   751,  1454,  1724,   157,   638,
     639,   757,  1767,    62,  1769,     4,     4,   196,     5,     9,
     330,     4,    25,     4,     6,   204,     5,     7,   143,     4,
      25,     4,     4,     7,  1951,     5,     5,     4,     6,   349,
       4,     6,   253,     6,     6,   141,  1754,     4,   107,     6,
     141,    54,     4,   107,     4,     6,   101,     9,   253,     4,
     255,     4,   257,   159,   141,     4,   241,   242,   253,     4,
     255,   130,   168,   169,   170,   120,   130,   262,   174,   175,
      83,     0,   159,   258,     9,     9,    36,    37,   162,    92,
     254,   168,   169,   170,    97,   259,     7,   174,   175,   141,
     191,   254,    14,     7,   254,   108,   256,     9,   418,   262,
     420,  1819,   262,   254,   188,   256,   257,   159,   428,   298,
     299,   300,  1839,     9,     9,   253,   168,   169,   170,    93,
     204,   205,   174,   175,   241,   242,     6,   241,   242,     7,
     143,     6,     6,   144,   101,   148,   149,   150,    68,    69,
     257,    71,   250,   251,   157,   108,   101,   110,   262,   257,
     105,     6,   258,   342,   343,   344,   111,   112,     7,   114,
     115,   107,   175,     6,   257,     7,   241,   242,   261,   101,
     359,   258,   104,   241,   242,   107,     7,  2104,   191,   134,
     143,   241,   242,   196,   241,   242,   199,   262,   120,   248,
     249,   204,   205,   206,   262,   253,   178,   179,   180,   181,
     241,   242,   262,   176,   176,   262,   258,   170,   190,   254,
     192,   193,   194,   195,   196,     6,   257,   262,   200,   201,
    1678,   203,   241,   242,     6,   199,   203,   225,   104,   246,
     247,   107,   225,   109,   225,   252,   226,   227,   228,   229,
     225,     6,   225,   262,   120,  1510,   254,   260,   256,   241,
     242,   225,  1979,   253,   262,   255,   255,     6,   257,   257,
     257,   274,   261,   225,   277,   278,   257,   260,   257,   254,
     445,   256,   253,   278,   255,   259,   258,   257,   257,   257,
     293,   294,   257,   257,   297,   298,   299,   300,   250,   251,
     258,   253,   253,   255,   262,   257,   257,   259,     3,   312,
     253,  1057,  1058,   316,   253,   318,  2033,   627,   253,   629,
     630,   253,   226,   227,   228,   229,   250,   251,   253,   253,
     255,   255,   256,     6,   259,   259,   646,   340,   255,   342,
     343,   344,   253,     4,   255,   255,   250,   251,   250,   251,
     107,   253,   109,   255,   664,   259,   359,   259,   226,   227,
     228,   229,     6,   366,   250,   251,    61,   253,   253,   255,
     255,   241,   242,   259,   259,   256,   241,   242,   688,   257,
     559,   262,   250,   251,  2139,   254,     6,   226,   227,   228,
     229,   236,   237,   262,   226,   227,   228,   229,     4,     6,
     549,   321,   322,   236,   237,   226,   227,   228,   229,   329,
     330,   250,   251,   241,   242,   250,   251,   727,   250,   251,
     250,   251,   425,   426,   241,   242,     8,   430,   431,   259,
      36,    37,     4,   253,   262,   253,   104,   257,   603,   107,
     108,   109,     4,   446,   253,   262,   255,     4,   143,   141,
     453,   254,   120,   148,   149,   150,   253,  2174,   104,   262,
     257,   107,   157,   109,    36,    37,     4,   159,   241,   242,
     253,   241,   242,   476,    36,    37,   168,   169,   170,    36,
      37,   434,   174,   175,   253,   146,   147,   148,   149,   262,
     141,   152,   262,   241,   242,   256,   191,   253,    36,    37,
     161,   262,   505,   164,   110,   111,   253,  2224,   159,   241,
     242,   206,   241,   242,   262,   183,   258,   168,   169,   170,
     262,  1969,   253,   174,   175,   104,   529,   253,   107,   254,
     262,   256,   259,   262,   261,   538,   539,   262,   110,   111,
     543,   120,   545,   546,   547,   548,   549,   696,   110,   111,
     253,   554,   247,   110,   111,   558,   559,   560,   561,   562,
     563,   564,   253,   566,   255,   568,   731,   262,   263,   564,
     253,   566,   110,   111,   241,   242,   104,   253,    54,   107,
     146,   147,   188,   189,   241,   242,   152,   241,   242,   241,
     242,   594,   241,   242,   253,   262,   259,   600,   254,   262,
     765,   241,   242,   241,   242,   262,   262,   258,   262,   254,
     262,   256,   565,   262,   241,   242,   253,   782,   255,   622,
     623,     4,   262,     6,   262,   241,   242,   792,   241,   242,
     258,   188,   189,   257,   262,   262,   751,   638,   639,   254,
     253,   256,   952,  1272,   257,   253,   262,   262,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   253,   670,   671,   672,
     252,   101,   675,   253,   104,   253,   258,   107,   254,   109,
     243,   244,   245,   246,   247,   254,   262,   256,   257,   252,
     120,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     122,   704,   705,   706,   707,   708,   257,   710,   711,   712,
     713,   714,   241,   242,   717,   254,   636,   637,   713,   241,
     242,   641,   771,   262,   253,   728,   146,   147,   257,   205,
     425,   254,   152,   898,  1480,   257,     6,     7,   741,   262,
     435,   241,   242,   243,   244,   245,   246,   247,   253,   107,
     255,     6,   252,   756,   259,   101,   709,   262,   104,   762,
     254,   107,   457,   109,   254,   258,   256,   258,   262,   262,
     258,   262,   262,   109,   262,   778,   779,   250,   251,   253,
     253,   784,   255,   786,   260,   253,   789,   790,   257,   250,
     251,   257,   253,   796,   255,   798,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   927,   241,   242,   258,   252,   250,   251,   262,
     253,   297,   255,   258,   257,  1571,   253,   262,   831,   258,
     833,   104,   107,   262,   258,  1581,   312,   258,   262,   258,
     316,   262,   258,   262,   253,   258,   262,   258,   543,   262,
     545,   262,   547,   548,   549,   808,   258,   258,   258,   258,
     262,   262,   262,   262,   258,   868,   561,   562,   262,   258,
    2128,   257,   257,   262,   107,   878,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,  1059,   258,   257,   900,   252,   262,
     254,   104,   256,   258,   104,  2160,   258,   262,   262,   107,
     262,   258,   107,   916,     8,   262,   258,   258,   258,   258,
     262,   262,   262,   262,     4,   928,   258,  2185,  1043,   258,
     262,   258,   258,   262,   937,   262,   262,   258,     4,     4,
     258,   262,  1057,  1058,   262,   948,   258,  2202,   258,   644,
     262,     4,   262,   258,   430,   431,   258,   262,   258,  1074,
     262,   258,   262,   258,   258,   262,     6,   262,   262,   258,
     446,   258,   667,   262,   258,   262,   258,   258,   262,   258,
     262,   262,   258,   262,   258,   143,   262,   940,   262,   258,
     148,   149,   150,   262,   258,   253,   253,   253,   262,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   253,   704,
     705,   706,   707,   253,   258,   710,   711,   712,   262,   258,
     258,     6,   258,   262,   262,   720,   262,   255,   723,  1194,
     253,  1196,   258,   191,  1351,   955,   262,   255,   257,     6,
     735,   261,   962,   257,  1209,     6,   966,   253,   206,  1052,
     261,     9,   253,   257,   253,   191,   253,  1060,   191,   253,
     253,   253,   253,   253,   253,  1068,   191,   130,   253,   257,
     546,   253,   253,  1238,   253,   770,   191,   772,  1081,   257,
    1709,  1710,   558,  1086,   560,   253,   253,   253,   257,   253,
       4,   253,   257,     6,   789,  1210,  1211,   257,   257,   253,
     257,   253,   253,   798,   253,   253,   253,   253,  1061,     6,
     255,     6,     6,   257,   257,  1118,  1119,   257,  1121,  1122,
    1123,     5,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1297,  1298,  1137,   257,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   257,   255,   255,  1322,   252,   255,
       6,   191,   257,  1328,   258,    49,    50,    51,    52,    53,
      54,    55,    56,    57,  1177,  1178,  1179,   253,    62,    63,
      64,    65,  1347,   253,   253,   253,    70,    71,    72,    73,
       6,   253,   253,     6,    78,   255,    80,  1117,  1201,   257,
       6,     8,     6,     8,     7,   257,     6,   257,   257,  1374,
      94,     6,   257,    97,  1217,  1218,  1219,   258,    96,   262,
     262,   254,     7,  1388,     6,     6,   254,   252,   257,    67,
    1395,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   257,   257,   257,  1559,
     252,   259,     8,  1563,     7,     7,   951,  1574,   953,   954,
    1375,  1376,   253,     6,   254,   741,     6,   425,   257,     7,
    1273,  1272,   967,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,  1289,  1290,  1291,     6,
     252,   986,     7,     6,     6,   258,   188,  1300,   257,     6,
     256,   258,  1305,   258,   254,   257,  1309,     7,   259,     6,
    1005,   255,   253,     6,   257,  1318,     6,  1320,     6,     6,
    1323,     6,   254,   207,   208,   209,   255,     7,     7,     7,
       7,     7,     7,     7,   218,  1338,     7,     7,   222,     7,
     224,     7,     7,     7,     7,     7,  1041,     7,  1351,   257,
       6,   254,   256,   262,     7,   262,  1985,   262,   258,   258,
     262,   254,     7,   259,     4,     6,   257,   257,   141,   257,
     259,   258,   258,  1376,     7,     6,   259,     7,  1381,     7,
    1383,     7,   254,   254,     9,   543,   262,   545,   262,   547,
     548,  1086,   262,   254,   256,   259,   261,  1400,   191,     7,
     162,   258,   257,   561,   562,     6,     6,     6,   259,   253,
      49,    49,  1415,   253,   257,   257,  1419,   253,   259,   253,
     259,     7,     7,     7,   900,   262,   191,   254,     7,     7,
       7,     6,   254,  1582,  1583,     7,   262,     7,     7,     7,
       7,     4,   257,   253,     6,  1398,   119,  1400,     7,     6,
     107,     7,     7,     7,     7,     7,  1571,     7,     7,   257,
       6,   937,     6,     6,  1781,     7,     7,     6,     6,     4,
     260,  1474,  1475,  1476,   262,   254,   262,   257,     6,  1482,
    1483,  1484,   257,  1178,  1179,   257,     6,   258,     7,     6,
       6,   255,     6,   253,   253,     6,   257,  1500,     6,     6,
     258,     6,   259,     6,     6,   256,     6,   262,  1511,     6,
     134,     6,     6,     6,     6,     6,  1519,     6,     6,     6,
    1523,     6,     6,     5,   254,   254,     6,     6,     4,     6,
     257,   257,     7,     6,   257,     7,   257,   695,   257,   697,
     698,   699,   700,   701,   702,  1240,   704,   705,   706,   707,
     255,     6,   710,   711,   712,     6,   257,     6,   257,   257,
       6,   257,   257,   257,     6,   187,   258,     6,   257,  1684,
       6,  1574,   254,   259,   257,     7,  1052,     6,   262,  1582,
    1583,   262,     6,     6,     6,  1588,   253,     4,     7,  1509,
     262,     6,  1068,   262,     6,   253,   257,     6,   253,   258,
       6,     6,  1555,  1606,     6,     6,   105,   141,  1773,     6,
    1305,     5,   262,  1616,  1309,   257,     6,   254,  1621,     6,
     141,   257,   257,  1318,     6,  1320,   141,     6,  1323,     6,
     262,   789,     6,   262,   254,  1784,     6,  1332,     6,   262,
     798,     6,  1118,  1119,   262,  1121,  1122,  1123,   257,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,   257,
       6,     6,     6,  1616,     6,     6,   257,     7,     6,   257,
     257,   145,     5,   254,   257,     6,     6,   257,     6,     6,
       6,  1376,   258,   257,  1994,   258,     7,     6,   186,   254,
       7,   257,     6,  1696,   258,     6,     6,   258,  1701,  1702,
     258,  1177,     6,  2020,     6,     6,   257,     6,  1709,  1710,
       6,   259,     6,   258,   254,     6,  1636,     6,   189,     6,
     257,  1724,   258,   253,   257,  1201,   258,  1730,   257,   254,
     257,   257,     6,   257,     6,   258,     6,   141,  1741,   257,
       6,  1217,     6,     6,   257,   254,  1749,     6,     6,  1752,
       6,     6,  1705,     6,   258,     6,     6,   258,     6,     6,
       6,   257,     6,     6,     6,     6,     6,  1770,     6,     6,
       6,  1774,  2141,  1387,   257,  1449,   257,  1628,  1781,  2089,
    1783,  1784,   473,  1952,  1692,  1912,     3,  1070,  1414,     3,
       3,     3,   615,  1981,  1747,     3,  1774,  1273,  1552,  1754,
      -1,  1754,  1755,  1583,    -1,  1725,  1726,  1727,  1728,  1729,
    1730,   789,    -1,  1289,  1290,  1291,  1819,    -1,    -1,  2129,
      -1,    -1,  1775,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1839,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1850,  1851,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1338,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    -1,  1875,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1887,    -1,    -1,  1582,  1583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1901,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1400,    -1,    -1,    -1,  1086,    -1,
      -1,    -1,    -1,    -1,    -1,  1938,    -1,    -1,    -1,  1415,
      -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,
    1953,    -1,    -1,    -1,    -1,  1958,    -1,    -1,  1961,  1962,
      -1,  1914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1979,    -1,    -1,  1982,
      -1,    -1,    -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,
    1993,    -1,    -1,    -1,  1997,    -1,    -1,    -1,  1474,  1475,
    1476,    -1,    -1,    -1,  1957,    -1,  1482,  1483,  1484,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2020,    -1,    -1,
    1178,  1179,    -1,    -1,  1500,    -1,    -1,    -1,    -1,    -1,
    2033,    -1,    -1,    -1,    -1,  1511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1749,    -1,    -1,  1752,    -1,  2062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1767,    -1,  1769,    -1,    -1,    -1,  1998,  1999,
    2000,  2001,  2002,    -1,    -1,    -1,    -1,    -1,    -1,  1784,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
    2113,    -1,  1588,   252,    -1,   254,    -1,   256,     8,    -1,
      -1,    -1,    -1,    -1,  1819,    -1,    -1,    -1,  2131,  2132,
    2133,  2134,  2135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1616,  2061,    -1,    -1,    -1,  2065,    -1,  1305,    -1,    -1,
      -1,  1309,  2105,    -1,    -1,    -1,     6,    -1,    -1,    -1,
    1318,    -1,  1320,    -1,    -1,  1323,    -1,    -1,    -1,    -1,
      -1,  2174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2115,    -1,    -1,    -1,  2119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2211,    -1,
      -1,    -1,    -1,    -1,    -1,  2135,    -1,    -1,  1376,    -1,
    1696,  2224,    -1,    -1,    -1,    -1,    -1,  2230,  2231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,     6,    -1,
    2180,  2181,    -1,    -1,    -1,  1741,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,   152,    -1,  1770,    -1,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,    -1,    -1,  1783,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,   185,   186,   187,   188,   189,
     190,    -1,   192,   193,   194,   195,    -1,    -1,    -1,   199,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,  1839,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  2074,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,  1875,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   273,   274,   275,   276,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   292,   293,   294,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2139,    -1,    -1,    -1,  1606,    -1,
      -1,    -1,    -1,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1938,    -1,   324,   325,  2161,    -1,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,  1953,    -1,    -1,
     340,   341,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,  1979,   252,   365,   366,    -1,    -1,    -1,
     370,   371,   372,    -1,   374,    -1,  2211,  1993,   378,   379,
     380,    -1,    -1,   383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2230,  2231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2243,    -1,
      -1,    -1,    -1,   199,    -1,    -1,    -1,  2033,    -1,    -1,
      -1,    -1,   422,    -1,    -1,    -1,   426,   427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,   444,    -1,  2062,    -1,    -1,    -1,
      -1,  1749,    -1,    -1,  1752,     6,    -1,    -1,   458,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   478,   479,
     480,   481,   252,    -1,    -1,    -1,   486,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   504,   505,    -1,   293,   294,   509,
      -1,    -1,    -1,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
      -1,   541,   542,    -1,   544,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   553,   340,    -1,   556,   557,  2174,    -1,
      -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,   568,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
      -1,   601,   602,    -1,    -1,    -1,    -1,    -1,  2224,   609,
     610,   611,    -1,    -1,     6,    -1,    -1,   617,   618,   619,
     620,    -1,   622,   623,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,   641,   642,   643,    -1,    -1,    -1,   647,   648,   649,
     650,   651,   652,   653,   654,   655,    -1,    -1,    -1,    -1,
      -1,   661,    -1,   663,    -1,    -1,   666,    -1,     6,    -1,
     670,   671,   672,   673,    -1,   675,   676,   677,   678,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   703,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,   717,    -1,    -1,
      -1,    -1,    -1,    -1,   724,    -1,   726,    -1,    -1,   729,
     730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   738,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   756,    -1,   758,    -1,
      -1,    -1,    -1,   763,   764,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   778,    -1,
     780,   781,   568,    -1,   784,    -1,   786,   787,    -1,    -1,
      -1,   791,    -1,   793,    -1,    -1,    -1,    -1,    -1,   799,
      -1,    -1,    -1,   803,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,   829,
      -1,   831,    -1,   833,    -1,    -1,   622,   623,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   868,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,   879,
     880,    -1,    -1,    -1,   670,   671,   672,    -1,    -1,   675,
     199,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,  2211,   252,    -1,   916,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   928,    -1,
      -1,   717,  2230,  2231,    -1,    -1,   936,    -1,    -1,    -1,
     940,    -1,    -1,    -1,    -1,  2243,    -1,    -1,   948,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   956,   957,    -1,    -1,
      -1,    -1,   962,    -1,    -1,   274,    -1,    -1,   277,    -1,
     756,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   979,
      -1,    -1,   982,    -1,   293,   294,    -1,    -1,    -1,    -1,
      -1,    -1,   778,    -1,    -1,    -1,    -1,    -1,   784,    -1,
     786,    -1,    -1,    -1,  1004,    -1,  1006,  1007,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1025,    -1,    -1,    -1,    -1,
      -1,   340,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1048,    -1,
      -1,    -1,    -1,    -1,    -1,  1055,    -1,   366,    -1,    -1,
      -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1075,  1076,    -1,    -1,    -1,
      -1,  1081,   868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   878,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,  1112,  1113,  1114,  1115,   252,   426,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     916,    -1,    -1,    -1,    -1,    -1,    -1,  1137,    -1,    -1,
      -1,    -1,   928,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   948,  1163,  1164,  1165,  1166,  1167,    -1,    -1,
      -1,    -1,  1172,  1173,    -1,  1175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,  1189,
    1190,    -1,    -1,    -1,    -1,    -1,   505,  1197,  1198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1206,  1207,    -1,    -1,
      -1,    -1,  1212,  1213,    -1,    -1,    -1,    -1,  1218,  1219,
     529,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,   538,
     539,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,  1252,    -1,   563,   252,    -1,    -1,    -1,   568,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,   594,    -1,    -1,  1288,    -1,
      -1,    -1,    -1,    -1,    -1,  1081,    -1,    -1,    -1,    -1,
    1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1308,    -1,
      -1,    -1,    -1,   622,   623,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1329,
    1330,    -1,    -1,    -1,  1334,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1345,    -1,    -1,  1348,    -1,
      -1,  1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   670,   671,   672,    -1,    -1,   675,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1377,    -1,    -1,
    1380,  1381,  1382,  1383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1391,    -1,    -1,  1394,    -1,  1396,  1397,  1398,    -1,
      -1,  1401,  1402,    -1,    -1,    -1,    -1,    -1,   717,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,  1218,  1219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   756,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,   778,
     252,    -1,    -1,    -1,    -1,   784,    -1,   786,    -1,    -1,
      -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1491,  1492,  1493,    -1,    -1,    -1,    -1,    -1,    -1,
    1500,    -1,  1502,    -1,    -1,    -1,    -1,    -1,    -1,  1509,
      -1,    -1,    -1,    -1,  1300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   831,  1523,   833,    -1,    -1,    -1,  1528,  1529,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1537,  1538,  1539,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1547,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,  1557,    -1,   868,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1578,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1586,  1587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1381,    -1,  1383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,   916,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   928,
      -1,  1621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   948,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,  1665,  1666,  1667,    -1,    -1,
     130,   131,    -1,    -1,   134,   135,  1676,   137,   138,    -1,
     140,  1681,  1682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,  1694,    -1,    -1,    -1,   158,    -1,
      -1,  1701,  1702,  1703,    -1,  1705,    -1,    -1,    -1,    -1,
      -1,  1711,  1712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,    -1,
    1730,    -1,    -1,    -1,    -1,  1735,    -1,  1523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,
    1750,    -1,    -1,    -1,  1754,    -1,   448,    -1,    -1,    -1,
      -1,    -1,    -1,  1763,  1764,    -1,  1766,    -1,    -1,    -1,
      -1,    -1,  1081,    -1,    -1,    -1,  1776,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1790,    -1,    -1,    -1,    -1,  1795,  1796,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1809,
      -1,    -1,  1812,  1813,    -1,  1815,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1137,    -1,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
    1850,  1851,   252,     6,    -1,    -1,    -1,  1857,  1858,    -1,
      -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,  1869,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1878,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1897,  1898,    -1,
      -1,  1901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1218,
    1219,    -1,    -1,   605,    -1,  1701,  1702,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,  1935,  1936,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1956,    -1,    -1,    -1,
      -1,  1961,  1962,  1963,    -1,    -1,    -1,    -1,  1968,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1982,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1300,    -1,    -1,    -1,     6,    -1,  1997,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2005,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
    2030,    -1,    -1,    -1,    -1,    -1,  2036,    -1,    -1,  2039,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,  1850,  1851,    26,    -1,    28,    -1,
    2070,    -1,  1381,    -1,  1383,    -1,    -1,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,  2095,  2096,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2110,  2111,    -1,  2113,    -1,  1901,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2126,     6,    -1,    -1,
      -1,  2131,  2132,  2133,  2134,  2135,    -1,    -1,    -1,    -1,
      -1,  2141,    -1,    -1,    -1,  2145,   838,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,    -1,   850,   851,
     852,   853,    -1,   855,   856,   857,   858,    -1,    -1,    -1,
      -1,    -1,  2172,    -1,    -1,  1961,  1962,  2177,  2178,   871,
      -1,   873,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
    2190,   883,    -1,    -1,    -1,    -1,  1982,    -1,   890,   891,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   899,    -1,    -1,
      -1,  1997,    -1,    -1,  1523,    -1,    -1,  2217,  2218,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,   266,    -1,    -1,    -1,
      -1,    -1,  1621,    -1,    -1,    -1,    -1,    -1,    -1,  1011,
    1012,  1013,    -1,    -1,    -1,  1017,  1018,  2113,    -1,  1021,
    1022,  1023,  1024,    -1,  1026,    -1,    -1,    -1,    -1,  1031,
      -1,    -1,    -1,    -1,    -1,  2131,  2132,  2133,  2134,  2135,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     6,
      -1,    -1,    -1,   252,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,  1701,  1702,     7,     8,   252,    -1,   254,    -1,
      -1,    -1,    -1,    -1,  2190,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1111,
      -1,  1730,    -1,    -1,  1116,   385,   386,   387,    -1,    -1,
      -1,   391,   392,   393,   394,   395,   396,   397,    -1,   399,
      -1,    -1,    -1,    -1,   404,   405,    -1,    -1,   408,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1215,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,  1850,  1851,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1887,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1901,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,   576,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1961,  1962,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1357,    -1,    -1,     7,    -1,
      -1,    -1,    -1,  1982,    -1,    -1,   206,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,   215,   216,   217,  1997,   219,
     220,   221,     8,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1399,    -1,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,   257,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,  1433,  1434,  1435,  1436,  1437,  1438,  1439,    -1,    -1,
      -1,    -1,  1444,  1445,    -1,    -1,    -1,    -1,  1450,    -1,
    1452,    -1,    -1,    -1,  1456,    -1,    -1,  1459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1470,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,  2113,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,  2131,  2132,  2133,  2134,  2135,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,  1543,    -1,  1545,    -1,   120,    -1,  1549,    -1,  1551,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1582,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     8,    -1,   894,    -1,   252,    -1,    -1,    -1,
      -1,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   927,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     3,     4,     5,    -1,
     252,  1683,   257,    10,    11,    12,   258,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,
      77,    78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    -1,
      97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
     107,    -1,   109,    -1,  1786,    -1,    -1,  1789,    -1,   116,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   130,    -1,   132,   133,    -1,   135,    -1,
     137,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,    -1,   152,   153,   154,   155,   156,
     157,    -1,    -1,    -1,   161,  1105,    -1,   164,  1840,  1841,
      -1,  1843,    -1,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,     8,   224,   225,    -1,
      -1,    -1,    -1,  1905,  1906,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,    -1,  1202,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,  1954,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    76,    77,    78,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,
      -1,   135,    -1,   137,    -1,    -1,   140,    -1,  1358,  1359,
      -1,    -1,   146,   147,   148,   149,   150,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     8,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,   211,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1454,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,  1463,   248,    -1,    -1,  2199,    -1,   253,
       3,     4,     5,   257,     7,    -1,   260,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,   224,   225,   226,   227,   228,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,   250,   251,    -1,
     253,    -1,   255,     3,     4,     5,   259,   260,    -1,    -1,
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
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,     3,     4,    -1,   257,    -1,     8,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,
     219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   253,     3,     4,     5,    -1,   258,
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
     248,    -1,    -1,    -1,    -1,   253,     3,     4,    -1,   257,
      -1,    -1,   260,    10,    11,    12,    -1,    -1,    15,    16,
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
     257,   258,    -1,   260,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,
     215,   216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,     3,
       4,    -1,   257,    -1,    -1,   260,    10,    11,    12,    -1,
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
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,
       3,     4,    -1,   257,    -1,    -1,   260,    10,    11,    12,
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
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,    -1,   210,   211,    -1,
      -1,    -1,   215,   216,   217,    -1,   219,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,     3,     4,    -1,    -1,   258,    -1,   260,    10,    11,
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
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,     3,     4,    -1,   257,    -1,     8,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,    -1,
     219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
       3,     4,    -1,    -1,   253,     8,    -1,    10,    11,    12,
      -1,   260,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,    -1,   210,   211,    -1,
      -1,    -1,   215,   216,   217,    -1,   219,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,    -1,
     253,    -1,    -1,    10,    11,    12,    -1,   260,    15,    16,
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
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   248,     3,     4,     5,    -1,   253,    -1,
      -1,    10,    11,    12,    -1,   260,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    -1,    97,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,    -1,
      -1,   260,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,
       3,     4,     5,   257,    -1,    -1,   260,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   257,    -1,    -1,   260,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,   224,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,     3,     4,    -1,    -1,   253,    -1,    -1,    10,    11,
      12,    -1,   260,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      92,    93,     8,    95,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   262,   215,   216,   217,    -1,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,   257,    -1,    -1,   260,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,   262,    -1,    -1,   210,    -1,    -1,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,   248,     3,     4,    -1,    -1,   253,    -1,    -1,
      10,    11,    12,    -1,   260,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    81,    82,    83,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    92,    93,    -1,    95,    -1,
     130,   131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,   144,    -1,   206,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,   215,   216,   217,   158,   219,
     220,   221,   162,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,   183,   184,   185,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
     260,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   206,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,   215,   216,
     217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,     6,   253,    -1,    -1,    10,
      11,    12,    -1,   260,    15,    16,    17,    18,    19,    20,
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
      -1,    -1,   123,    -1,    92,    93,    -1,    95,    -1,   130,
     131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,   215,   216,   217,   158,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,   183,   184,   185,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,     3,     4,    -1,    -1,   253,    -1,    -1,    10,    11,
      12,    -1,   260,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      92,    93,    -1,    95,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,   262,   215,   216,   217,    -1,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,   262,    -1,    -1,   210,    -1,    -1,    -1,    -1,   215,
     216,   217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,
      -1,    -1,   248,     3,     4,    -1,    -1,   253,   254,    -1,
      10,    11,    12,    -1,   260,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    -1,    95,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,   206,    -1,   252,    -1,
     210,    -1,    -1,    -1,    -1,   215,   216,   217,   262,   219,
     220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,   207,   208,   209,    -1,    -1,    -1,
     260,    -1,    -1,    13,    14,   218,    -1,    -1,    -1,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,   250,   251,    70,
      71,    72,    73,    -1,   257,    -1,   259,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,   137,   117,   118,   119,
     120,    13,    14,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    13,
      14,   252,    -1,   183,   184,   185,   207,   208,   209,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,
      -1,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,   254,    -1,   256,   257,    -1,   130,   131,
      -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    13,    14,   158,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,
      -1,   183,   184,   185,    -1,    -1,   130,   131,    -1,    -1,
     134,   135,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,   158,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,   183,
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
      -1,    13,    14,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   258,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   158,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,   258,    -1,   117,   118,   119,   120,    -1,
      -1,   123,    -1,   183,   184,   185,    -1,    -1,   130,   131,
      -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   258,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,    -1,    -1,   134,   135,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   158,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,   258,    -1,   117,   118,
     119,   120,    -1,    -1,   123,    -1,   183,   184,   185,    -1,
      -1,   130,   131,    -1,    -1,   134,   135,    -1,   137,   138,
      -1,   140,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   158,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,   183,   184,   185,    -1,    -1,    -1,
      46,    47,    48,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    -1,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,   258,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,   142,   143,   144,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,    -1,    -1,    -1,   171,   172,   173,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,   182,   183,   184,   185,
      -1,    -1,   188,    -1,   190,    -1,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
       4,    -1,    -1,    -1,    -1,    -1,   212,   213,   214,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,   223,    -1,   225,
      -1,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    46,    47,    48,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    -1,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,   116,   117,   118,   119,   120,   121,    -1,   123,
      -1,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,   142,   143,
     144,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,    -1,    -1,    -1,   171,   172,   173,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,   182,   183,
     184,   185,     4,     5,   188,    -1,   190,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
     214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,     4,     5,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,
       4,     5,   104,    -1,    -1,   107,    -1,   109,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   120,    -1,
      -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,   137,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    94,    -1,    -1,    97,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,
     222,    -1,   224,   225,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   218,    -1,
      -1,    -1,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,
     224,   230,   231,   232,   233,   234,   235,   236,   237,   238,
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
     257,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,   257,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,   257,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,   254,    -1,   256,   230,   231,   232,   233,   234,   235,
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
     252,    -1,    -1,    -1,   256,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,   256,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,   256,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,   254,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254
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
     258,     7,   289,   288,   359,   258,     8,     8,   362,   259,
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
     346,   346,   258,   289,   286,   259,   286,   346,   346,   288,
     258,   359,   362,   362,     7,     7,     7,   141,   337,     6,
     254,   262,     7,     7,     7,     7,     7,   258,     4,   289,
     258,   262,   262,   262,   258,   258,   119,     4,     6,   346,
     257,     6,   253,     6,   176,     6,   176,   258,   332,   262,
     331,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     316,   359,     6,   257,     6,     6,     6,   107,     7,     7,
       6,     6,   346,   359,   359,   359,     4,   262,     8,     8,
     254,   289,   289,   362,   366,   346,   366,   260,   262,   302,
     366,   366,   289,   366,   254,   262,   289,   257,   311,   257,
       6,   346,     6,   257,   359,   258,   258,   346,     6,   188,
     189,   289,   346,     6,     7,   363,   365,     6,   255,     6,
       6,   288,   287,   287,     6,   274,   253,   253,   257,   284,
       6,   289,   259,   366,   346,   256,   254,   346,     8,   362,
     346,   362,   258,   258,     6,     6,   267,   289,   259,   346,
       6,     6,   346,   289,   254,   346,   257,   346,   367,   288,
      49,   257,   359,   367,   370,   346,   346,   256,   262,     6,
     254,   254,   254,   254,     6,     6,   134,   307,   307,   359,
       6,     6,     6,   359,   141,   191,   306,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   258,   288,   288,
     288,   288,   288,   288,   288,   262,   262,   262,   254,   288,
     288,   300,   288,   254,   288,   254,   287,   349,   288,     6,
     288,   253,   255,   287,   289,   254,   256,   288,     6,   258,
     258,   359,   359,   359,     4,     6,   285,   346,   359,   359,
     359,   257,   257,     7,     6,     7,   346,   346,   346,   257,
     257,   257,   255,     6,   346,   359,   346,     6,     6,   346,
     356,   258,     5,   359,   257,   257,   257,   257,   257,   257,
     257,   359,   258,     6,   362,   257,   346,   346,   256,     6,
       6,   187,   346,   346,   346,     6,     6,     7,   288,   262,
     262,   288,   262,   346,     4,   203,   303,   304,   288,   254,
     288,   350,   367,   253,   255,   346,   257,   317,     6,   317,
     262,     6,     6,   259,     7,     7,   285,   286,     6,   363,
     258,   262,   346,   285,   257,   288,   371,   372,   373,   371,
     253,   346,   346,   358,   359,   257,   253,     4,     6,   254,
       6,   254,   258,   258,   254,   258,     6,     6,   366,   253,
       4,   254,   262,   253,   258,   262,   359,   367,     7,   287,
     297,   346,   361,   301,     6,     6,     6,     6,   356,     6,
       6,     6,   141,   308,   101,   120,   105,     6,     5,   257,
     346,   346,   346,   346,   254,   349,   346,   346,   288,   286,
     257,   257,     6,   306,     6,   346,   359,   141,   141,     4,
       6,   362,   362,   346,   346,   367,   258,   254,   258,   262,
     316,   316,   346,   346,   258,   262,   254,   258,   262,     6,
       6,   358,   356,   356,   356,   356,   356,   242,   356,     6,
     258,   346,     6,     6,     6,   359,   258,   262,     8,   258,
     254,   257,   346,   367,   366,   346,   366,   346,   367,   370,
     372,   367,   262,   254,   262,   258,   346,   334,   334,   359,
     289,   364,   367,   346,     6,     6,   363,   256,   359,   373,
       6,   288,   288,   271,   346,   262,   262,   258,   262,   272,
     346,   346,     6,     6,     6,     6,   346,   346,   254,     6,
     346,   293,   295,   257,   372,   258,   262,     7,     7,   145,
       6,   257,   257,   257,     5,   358,   288,   288,   262,   288,
     254,   254,   256,   362,   362,     6,     6,   346,   346,   257,
     258,   258,   257,     6,     6,   257,   346,   258,   258,   258,
     256,     6,   359,     7,   257,   346,   258,   262,   262,   262,
     262,   262,   262,     6,   258,   186,   346,   346,   362,     6,
       6,   254,   288,   288,   304,   367,   258,   258,   258,   258,
       7,     6,     6,     6,   259,     6,   258,     6,     6,   254,
     262,   346,   346,   257,   359,   258,   262,   254,   254,   262,
     258,   298,   302,   359,   288,   346,   367,   376,   362,   362,
     346,     6,   258,   346,   349,   258,   258,     6,     6,   358,
     146,   147,   152,   341,   146,   147,   341,   362,   316,   258,
     262,     6,   258,   359,   317,   258,     6,   362,   356,   356,
     356,   356,   356,   346,   258,   258,   258,   254,     6,   257,
       6,   363,   189,   275,   346,   262,   262,   358,     6,   346,
     346,     6,   258,   258,   294,     7,   253,   258,   258,   258,
     257,   262,   254,   257,   258,   257,   356,   359,     6,   257,
     356,     6,   258,   258,   346,     6,   141,   258,   328,   257,
     258,   262,   262,   262,   262,   262,     6,     6,     6,   317,
       6,   257,   346,   346,   258,   262,   298,   367,   254,   346,
     346,   362,     6,   356,     6,   356,     6,     6,   258,   346,
     331,   317,     6,   362,   362,   362,   362,   356,   362,   334,
     272,   254,   262,     6,   257,   346,   258,   262,   262,   258,
     262,   262,     6,   258,   258,   329,   258,   258,   258,   258,
     262,   258,   258,   258,   278,   346,   358,   258,   346,   346,
     356,   356,   331,     6,     6,     6,     6,   362,     6,     6,
       6,   257,   254,   258,     6,   258,   288,   262,   262,   258,
     258,   276,   366,   281,   257,     6,   346,   346,     6,   258,
     262,   257,   358,   258,   258,     6,   366,   279,   366,   258,
       6,     6,   258,   262,     6,     6,   366
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
#line 5755 "Gmsh.y"
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
#line 5769 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 537:
#line 5775 "Gmsh.y"
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
#line 5787 "Gmsh.y"
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
#line 5801 "Gmsh.y"
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
#line 5811 "Gmsh.y"
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

  case 542:
#line 5831 "Gmsh.y"
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
#line 5843 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 544:
#line 5847 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 545:
#line 5852 "Gmsh.y"
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
#line 5864 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 547:
#line 5868 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 548:
#line 5872 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 549:
#line 5876 "Gmsh.y"
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
#line 5894 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 551:
#line 5902 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 552:
#line 5910 "Gmsh.y"
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
#line 5939 "Gmsh.y"
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
#line 5949 "Gmsh.y"
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
#line 5965 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 556:
#line 5976 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 557:
#line 5981 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 558:
#line 5985 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 559:
#line 5989 "Gmsh.y"
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
#line 6001 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 561:
#line 6005 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 562:
#line 6017 "Gmsh.y"
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
#line 6034 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 564:
#line 6044 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 565:
#line 6048 "Gmsh.y"
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
#line 6063 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 567:
#line 6068 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 568:
#line 6075 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 569:
#line 6079 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 570:
#line 6084 "Gmsh.y"
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
#line 6098 "Gmsh.y"
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
#line 6112 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 573:
#line 6116 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 574:
#line 6120 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 575:
#line 6124 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 576:
#line 6128 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 577:
#line 6136 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 578:
#line 6142 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 579:
#line 6151 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 580:
#line 6155 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 581:
#line 6159 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 582:
#line 6167 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 583:
#line 6173 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 584:
#line 6179 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 585:
#line 6183 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6190 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 587:
#line 6198 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6205 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 589:
#line 6214 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 590:
#line 6218 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 591:
#line 6222 "Gmsh.y"
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
#line 6237 "Gmsh.y"
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
#line 6251 "Gmsh.y"
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
#line 6265 "Gmsh.y"
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
#line 6277 "Gmsh.y"
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
#line 6293 "Gmsh.y"
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
#line 6302 "Gmsh.y"
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
#line 6311 "Gmsh.y"
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
#line 6321 "Gmsh.y"
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
#line 6332 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 601:
#line 6340 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 602:
#line 6348 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 603:
#line 6352 "Gmsh.y"
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
#line 6371 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 605:
#line 6378 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 606:
#line 6384 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 607:
#line 6390 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 608:
#line 6397 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6404 "Gmsh.y"
    { init_options(); ;}
    break;

  case 610:
#line 6406 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 611:
#line 6414 "Gmsh.y"
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
#line 6438 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 613:
#line 6440 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 614:
#line 6446 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 615:
#line 6451 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 616:
#line 6453 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 617:
#line 6458 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 618:
#line 6463 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 619:
#line 6468 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 620:
#line 6470 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 621:
#line 6474 "Gmsh.y"
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
#line 6486 "Gmsh.y"
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
#line 6500 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 624:
#line 6504 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 625:
#line 6511 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 626:
#line 6519 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 627:
#line 6527 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 628:
#line 6538 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 629:
#line 6540 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 630:
#line 6543 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14631 "Gmsh.tab.cpp"
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


#line 6546 "Gmsh.y"


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

