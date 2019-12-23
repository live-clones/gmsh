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
static int flag_tSTRING_alloc = 0;
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
#line 166 "Gmsh.y"
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
#line 760 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 773 "Gmsh.tab.cpp"

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
#define YYLAST   17773

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  263
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  628
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
     278,   280,   282,   284,   286,   288,   290,   292,   298,   304,
     307,   315,   323,   328,   332,   339,   349,   357,   364,   372,
     379,   384,   393,   403,   413,   420,   430,   437,   447,   453,
     462,   471,   483,   490,   500,   506,   514,   522,   530,   540,
     550,   562,   570,   580,   590,   591,   593,   594,   598,   604,
     605,   615,   616,   628,   634,   635,   645,   646,   650,   654,
     660,   666,   667,   670,   671,   673,   675,   679,   682,   685,
     688,   690,   695,   698,   701,   702,   705,   707,   711,   714,
     717,   720,   723,   726,   728,   730,   734,   735,   741,   747,
     753,   754,   757,   758,   761,   769,   777,   785,   796,   807,
     816,   825,   833,   841,   853,   861,   870,   879,   888,   898,
     902,   907,   918,   926,   934,   942,   950,   958,   966,   974,
     982,   990,   998,  1008,  1016,  1024,  1033,  1042,  1055,  1056,
    1066,  1068,  1070,  1072,  1074,  1079,  1081,  1083,  1085,  1090,
    1092,  1094,  1099,  1101,  1103,  1105,  1110,  1116,  1128,  1134,
    1144,  1154,  1162,  1167,  1177,  1187,  1189,  1191,  1192,  1195,
    1202,  1210,  1218,  1225,  1233,  1242,  1253,  1268,  1285,  1298,
    1313,  1328,  1343,  1358,  1367,  1376,  1383,  1388,  1394,  1400,
    1407,  1414,  1418,  1423,  1427,  1433,  1440,  1446,  1451,  1455,
    1460,  1464,  1469,  1475,  1480,  1486,  1490,  1496,  1504,  1512,
    1516,  1524,  1528,  1531,  1534,  1537,  1540,  1543,  1559,  1562,
    1565,  1568,  1578,  1590,  1593,  1596,  1599,  1602,  1619,  1631,
    1638,  1647,  1656,  1667,  1669,  1672,  1675,  1677,  1681,  1685,
    1690,  1695,  1697,  1699,  1705,  1717,  1731,  1732,  1740,  1741,
    1755,  1756,  1772,  1773,  1780,  1790,  1793,  1797,  1808,  1822,
    1824,  1827,  1833,  1841,  1844,  1847,  1851,  1854,  1858,  1861,
    1865,  1875,  1882,  1884,  1886,  1888,  1890,  1892,  1893,  1896,
    1900,  1904,  1909,  1919,  1924,  1939,  1940,  1944,  1945,  1947,
    1948,  1951,  1952,  1955,  1956,  1959,  1966,  1974,  1981,  1987,
    1991,  2000,  2009,  2018,  2027,  2036,  2045,  2051,  2056,  2063,
    2075,  2087,  2106,  2125,  2138,  2151,  2164,  2175,  2180,  2185,
    2190,  2195,  2200,  2203,  2207,  2214,  2216,  2218,  2220,  2223,
    2229,  2237,  2248,  2250,  2254,  2257,  2260,  2263,  2267,  2271,
    2275,  2279,  2283,  2287,  2291,  2295,  2299,  2303,  2307,  2311,
    2315,  2319,  2323,  2327,  2331,  2335,  2341,  2346,  2351,  2356,
    2361,  2366,  2371,  2376,  2381,  2386,  2391,  2398,  2403,  2408,
    2413,  2418,  2423,  2428,  2433,  2438,  2445,  2452,  2459,  2464,
    2471,  2478,  2480,  2482,  2484,  2486,  2488,  2490,  2492,  2494,
    2496,  2498,  2500,  2501,  2508,  2510,  2515,  2522,  2524,  2529,
    2534,  2539,  2546,  2552,  2560,  2569,  2580,  2585,  2590,  2597,
    2602,  2606,  2609,  2615,  2621,  2625,  2631,  2638,  2647,  2654,
    2663,  2670,  2675,  2683,  2690,  2697,  2704,  2709,  2716,  2721,
    2722,  2725,  2726,  2729,  2730,  2738,  2740,  2744,  2746,  2748,
    2751,  2752,  2756,  2758,  2761,  2764,  2768,  2772,  2784,  2794,
    2802,  2810,  2812,  2816,  2818,  2820,  2823,  2827,  2832,  2838,
    2840,  2844,  2846,  2849,  2853,  2857,  2863,  2868,  2873,  2876,
    2881,  2884,  2888,  2892,  2909,  2915,  2921,  2927,  2929,  2931,
    2933,  2937,  2943,  2951,  2956,  2961,  2966,  2973,  2980,  2989,
    2998,  3003,  3018,  3023,  3028,  3030,  3032,  3036,  3040,  3050,
    3058,  3060,  3066,  3070,  3077,  3079,  3083,  3085,  3087,  3092,
    3097,  3101,  3107,  3114,  3123,  3130,  3135,  3141,  3143,  3148,
    3150,  3152,  3154,  3156,  3161,  3168,  3173,  3180,  3186,  3194,
    3199,  3204,  3209,  3218,  3223,  3228,  3233,  3238,  3247,  3256,
    3263,  3268,  3275,  3280,  3282,  3284,  3289,  3294,  3295,  3302,
    3307,  3310,  3315,  3320,  3322,  3324,  3328,  3330,  3332,  3336,
    3340,  3344,  3350,  3358,  3364,  3370,  3379,  3381,  3383
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     264,     0,    -1,   265,    -1,     1,     6,    -1,    -1,   265,
     266,    -1,   268,    -1,   269,    -1,   289,    -1,   129,   253,
     366,   254,     6,    -1,   308,    -1,   314,    -1,   318,    -1,
     319,    -1,   320,    -1,   321,    -1,   325,    -1,   334,    -1,
     335,    -1,   341,    -1,   342,    -1,   324,    -1,   323,    -1,
     322,    -1,   317,    -1,   344,    -1,   236,    -1,   237,    -1,
      46,   253,   366,   254,     6,    -1,    48,   253,   366,   254,
       6,    -1,    47,   253,   366,   254,     6,    -1,    46,   253,
     366,   254,   267,   366,     6,    -1,    46,   253,   366,   262,
     362,   254,     6,    -1,    48,   253,   366,   262,   362,   254,
       6,    -1,    47,   253,   366,   262,   362,   254,     6,    -1,
      46,   253,   366,   262,   362,   254,   267,   366,     6,    -1,
     376,   366,   257,   270,   258,     6,    -1,   171,     4,   255,
     345,   256,     6,    -1,   172,     4,   255,   345,   256,     6,
      -1,   173,     4,   255,   345,   262,   345,   256,     6,    -1,
      -1,   270,   273,    -1,   270,   277,    -1,   270,   280,    -1,
     270,   282,    -1,   270,   283,    -1,   270,   324,    -1,   345,
      -1,   271,   262,   345,    -1,   345,    -1,   272,   262,   345,
      -1,    -1,    -1,     4,   274,   253,   271,   254,   275,   257,
     272,   258,     6,    -1,   366,    -1,   276,   262,   366,    -1,
      -1,   178,   253,   345,   262,   345,   262,   345,   254,   278,
     257,   276,   258,     6,    -1,   366,    -1,   279,   262,   366,
      -1,    -1,   179,   253,   345,   262,   345,   262,   345,   262,
     345,   254,   281,   257,   279,   258,     6,    -1,   180,   257,
     358,   258,   257,   358,   258,     6,    -1,   180,   257,   358,
     258,   257,   358,   258,   257,   358,   258,   257,   358,   258,
       6,    -1,    -1,   181,   284,   257,   272,   258,     6,    -1,
       7,    -1,   229,    -1,   228,    -1,   227,    -1,   226,    -1,
     251,    -1,   250,    -1,   253,    -1,   255,    -1,   254,    -1,
     256,    -1,    90,   255,   291,   256,     6,    -1,    91,   255,
     295,   256,     6,    -1,   350,     6,    -1,    98,   287,   367,
     262,   345,   288,     6,    -1,   100,   287,   376,   262,   367,
     288,     6,    -1,   376,   285,   359,     6,    -1,   376,   286,
       6,    -1,   376,   287,   288,   285,   359,     6,    -1,   376,
     287,   257,   362,   258,   288,   285,   359,     6,    -1,   376,
     255,   345,   256,   285,   345,     6,    -1,   376,   255,   345,
     256,   286,     6,    -1,   376,   253,   345,   254,   285,   345,
       6,    -1,   376,   253,   345,   254,   286,     6,    -1,   376,
       7,   367,     6,    -1,   376,   287,   288,     7,    49,   287,
     288,     6,    -1,   376,   287,   288,     7,    49,   287,   371,
     288,     6,    -1,   376,   287,   288,   229,    49,   287,   371,
     288,     6,    -1,   376,   259,     4,     7,   367,     6,    -1,
     376,   255,   345,   256,   259,     4,     7,   367,     6,    -1,
     376,   259,     4,   285,   345,     6,    -1,   376,   255,   345,
     256,   259,     4,   285,   345,     6,    -1,   376,   259,     4,
     286,     6,    -1,   376,   255,   345,   256,   259,     4,   286,
       6,    -1,   376,   259,   188,   259,     4,     7,   363,     6,
      -1,   376,   255,   345,   256,   259,   188,   259,     4,     7,
     363,     6,    -1,   376,   259,   189,     7,   364,     6,    -1,
     376,   255,   345,   256,   259,   189,     7,   364,     6,    -1,
     376,   199,     7,   359,     6,    -1,   199,   255,   345,   256,
       7,     4,     6,    -1,   199,   255,   345,   256,     7,   110,
       6,    -1,   199,   255,   345,   256,     7,   111,     6,    -1,
     199,   255,   345,   256,   259,     4,     7,   345,     6,    -1,
     199,   255,   345,   256,   259,     4,     7,   367,     6,    -1,
     199,   255,   345,   256,   259,     4,     7,   257,   362,   258,
       6,    -1,   199,   255,   345,   256,   259,     4,     6,    -1,
     142,   253,     4,   254,   259,     4,     7,   345,     6,    -1,
     142,   253,     4,   254,   259,     4,     7,   367,     6,    -1,
      -1,   262,    -1,    -1,   291,   290,   376,    -1,   291,   290,
     376,     7,   345,    -1,    -1,   291,   290,   376,     7,   257,
     359,   292,   297,   258,    -1,    -1,   291,   290,   376,   287,
     288,     7,   257,   359,   293,   297,   258,    -1,   291,   290,
     376,     7,   367,    -1,    -1,   291,   290,   376,     7,   257,
     367,   294,   301,   258,    -1,    -1,   295,   290,   366,    -1,
     345,     7,   367,    -1,   296,   262,   345,     7,   367,    -1,
     361,     7,   376,   253,   254,    -1,    -1,   262,   299,    -1,
      -1,   299,    -1,   300,    -1,   299,   262,   300,    -1,     4,
     359,    -1,    36,   345,    -1,    37,   345,    -1,     4,    -1,
       4,   257,   296,   258,    -1,     4,   367,    -1,     4,   370,
      -1,    -1,   262,   302,    -1,   303,    -1,   302,   262,   303,
      -1,     4,   345,    -1,     4,   367,    -1,   203,   367,    -1,
       4,   372,    -1,     4,   370,    -1,   345,    -1,   367,    -1,
     367,   262,   345,    -1,    -1,   191,   105,   257,   345,   258,
      -1,   141,   101,   257,   362,   258,    -1,   141,   120,   257,
     362,   258,    -1,    -1,   134,   356,    -1,    -1,   141,   145,
      -1,   101,   253,   345,   254,     7,   356,     6,    -1,   104,
     253,   345,   254,     7,   359,     6,    -1,   108,   253,   345,
     254,     7,   359,     6,    -1,   138,   108,   253,   345,   254,
       7,   359,   141,   345,     6,    -1,   138,   183,   253,   345,
     254,     7,   359,   141,   345,     6,    -1,   102,   253,   345,
     254,     7,   359,   306,     6,    -1,   103,   253,   345,   254,
       7,   359,   306,     6,    -1,   183,   253,   345,   254,     7,
     359,     6,    -1,   184,   253,   345,   254,     7,   359,     6,
      -1,   185,   253,   345,   254,     7,   359,   187,   359,   186,
     345,     6,    -1,   119,   253,   345,   254,     7,   359,     6,
      -1,   104,     4,   253,   345,   254,     7,   359,     6,    -1,
     134,   107,   253,   345,   254,     7,   359,     6,    -1,   107,
     253,   345,   254,     7,   359,   305,     6,    -1,   135,   107,
     253,   345,   254,     7,   359,   305,     6,    -1,    13,    14,
       6,    -1,    14,   107,   345,     6,    -1,   123,   107,   253,
     345,   254,     7,     5,     5,     5,     6,    -1,   105,   253,
     345,   254,     7,   359,     6,    -1,   106,   253,   345,   254,
       7,   359,     6,    -1,   110,   253,   345,   254,     7,   359,
       6,    -1,   113,   253,   345,   254,     7,   359,     6,    -1,
     117,   253,   345,   254,     7,   359,     6,    -1,   118,   253,
     345,   254,     7,   359,     6,    -1,   111,   253,   345,   254,
       7,   359,     6,    -1,   112,   253,   345,   254,     7,   359,
       6,    -1,   131,   253,   345,   254,     7,   359,     6,    -1,
     158,   253,   345,   254,     7,   359,     6,    -1,   107,     4,
     253,   345,   254,     7,   359,   307,     6,    -1,   109,   253,
     345,   254,     7,   359,     6,    -1,   130,   253,   345,   254,
       7,   359,     6,    -1,   135,   130,   253,   345,   254,     7,
     359,     6,    -1,   138,   311,   253,   345,   254,     7,   359,
       6,    -1,   138,   311,   253,   345,   254,     7,   359,     4,
     257,   358,   258,     6,    -1,    -1,   137,   310,   309,   253,
     304,   254,   285,   359,     6,    -1,   101,    -1,   104,    -1,
     107,    -1,   109,    -1,   120,   257,   345,   258,    -1,   104,
      -1,   107,    -1,   109,    -1,   120,   257,   345,   258,    -1,
     104,    -1,   107,    -1,   120,   257,   345,   258,    -1,   101,
      -1,   104,    -1,   107,    -1,   120,   257,   345,   258,    -1,
     147,   356,   257,   315,   258,    -1,   146,   257,   356,   262,
     356,   262,   345,   258,   257,   315,   258,    -1,   148,   356,
     257,   315,   258,    -1,   149,   257,   356,   262,   345,   258,
     257,   315,   258,    -1,   149,   257,   356,   262,   356,   258,
     257,   315,   258,    -1,   152,   257,   362,   258,   257,   315,
     258,    -1,     4,   257,   315,   258,    -1,   164,   104,   257,
     362,   258,   107,   257,   345,   258,    -1,   161,   104,   253,
     345,   254,   257,   362,   258,     6,    -1,   316,    -1,   314,
      -1,    -1,   316,   308,    -1,   316,   310,   257,   362,   258,
       6,    -1,   316,   137,   310,   257,   362,   258,     6,    -1,
     316,   140,   310,   257,   362,   258,     6,    -1,   316,   310,
     257,     8,   258,     6,    -1,   316,   137,   310,   257,     8,
     258,     6,    -1,   151,   134,   253,   345,   254,     7,   359,
       6,    -1,   151,   101,   253,   345,   254,     7,   257,   358,
     258,     6,    -1,   151,   134,   253,   345,   254,     7,   257,
     356,   262,   356,   262,   362,   258,     6,    -1,   151,   134,
     253,   345,   254,     7,   257,   356,   262,   356,   262,   356,
     262,   362,   258,     6,    -1,   151,   105,   253,   345,   254,
       7,   257,   356,   262,   362,   258,     6,    -1,   151,   111,
     253,   345,   254,     7,   257,   356,   262,   356,   262,   362,
     258,     6,    -1,   151,   112,   253,   345,   254,     7,   257,
     356,   262,   356,   262,   362,   258,     6,    -1,   151,   114,
     253,   345,   254,     7,   257,   356,   262,   356,   262,   362,
     258,     6,    -1,   151,   115,   253,   345,   254,     7,   257,
     356,   262,   356,   262,   362,   258,     6,    -1,   151,     4,
     253,   345,   254,     7,   359,     6,    -1,   151,     4,   253,
     345,   254,     7,     5,     6,    -1,   151,     4,   257,   345,
     258,     6,    -1,   162,   257,   316,   258,    -1,   144,   162,
     257,   316,   258,    -1,   162,     4,   257,   316,   258,    -1,
     162,   199,   255,   345,   256,     6,    -1,   162,     4,   255,
     345,   256,     6,    -1,   162,   376,     6,    -1,   162,     4,
       4,     6,    -1,   162,    93,     6,    -1,   188,   363,   257,
     316,   258,    -1,   144,   188,   363,   257,   316,   258,    -1,
     223,   345,   257,   316,   258,    -1,   204,   257,     8,   258,
      -1,   204,     5,     6,    -1,   205,   257,     8,   258,    -1,
     205,     5,     6,    -1,   204,   257,   316,   258,    -1,   144,
     204,   257,   316,   258,    -1,   205,   257,   316,   258,    -1,
     144,   205,   257,   316,   258,    -1,   376,   367,     6,    -1,
      79,   253,   373,   254,     6,    -1,   376,   376,   255,   345,
     256,   366,     6,    -1,   376,   376,   376,   255,   345,   256,
       6,    -1,   376,   345,     6,    -1,   142,   253,     4,   254,
     259,     4,     6,    -1,   182,     4,     6,    -1,   197,     6,
      -1,   198,     6,    -1,    74,     6,    -1,    75,     6,    -1,
      67,     6,    -1,    67,   257,   345,   262,   345,   262,   345,
     262,   345,   262,   345,   262,   345,   258,     6,    -1,    68,
       6,    -1,    69,     6,    -1,    84,     6,    -1,    86,   257,
     345,   262,   345,   262,   345,   258,     6,    -1,    86,   257,
     345,   262,   345,   262,   345,   262,   345,   258,     6,    -1,
      85,     6,    -1,    87,     6,    -1,    88,     6,    -1,   125,
       6,    -1,   126,   257,   362,   258,   257,   362,   258,   257,
     358,   258,   257,   345,   262,   345,   258,     6,    -1,   202,
     253,   257,   362,   258,   262,   367,   262,   367,   254,     6,
      -1,   190,   253,   345,     8,   345,   254,    -1,   190,   253,
     345,     8,   345,     8,   345,   254,    -1,   190,     4,   191,
     257,   345,     8,   345,   258,    -1,   190,     4,   191,   257,
     345,     8,   345,     8,   345,   258,    -1,   192,    -1,   203,
       4,    -1,   203,   367,    -1,   200,    -1,   201,   376,     6,
      -1,   201,   367,     6,    -1,   193,   253,   345,   254,    -1,
     194,   253,   345,   254,    -1,   195,    -1,   196,    -1,   150,
     356,   257,   316,   258,    -1,   150,   257,   356,   262,   356,
     262,   345,   258,   257,   316,   258,    -1,   150,   257,   356,
     262,   356,   262,   356,   262,   345,   258,   257,   316,   258,
      -1,    -1,   150,   356,   257,   316,   326,   330,   258,    -1,
      -1,   150,   257,   356,   262,   356,   262,   345,   258,   257,
     316,   327,   330,   258,    -1,    -1,   150,   257,   356,   262,
     356,   262,   356,   262,   345,   258,   257,   316,   328,   330,
     258,    -1,    -1,   150,   257,   316,   329,   330,   258,    -1,
     150,   257,   316,   258,   141,   119,   257,   345,   258,    -1,
     130,   359,    -1,   135,   130,   359,    -1,   132,   257,   362,
     258,   257,   362,   258,   257,   362,   258,    -1,   133,   257,
     362,   258,   257,   362,   258,   257,   362,   258,   257,   362,
     258,    -1,   331,    -1,   330,   331,    -1,   168,   257,   345,
     258,     6,    -1,   168,   257,   359,   262,   359,   258,     6,
      -1,   169,     6,    -1,   159,     6,    -1,   159,   345,     6,
      -1,   174,     6,    -1,   174,   176,     6,    -1,   175,     6,
      -1,   175,   176,     6,    -1,   170,   253,   345,   254,     7,
     359,   141,   345,     6,    -1,   141,     4,   255,   345,   256,
       6,    -1,   153,    -1,   154,    -1,   155,    -1,   156,    -1,
     157,    -1,    -1,   162,     6,    -1,   144,   162,     6,    -1,
     162,   345,     6,    -1,   144,   162,   345,     6,    -1,   332,
     257,   316,   333,   258,   257,   316,   333,   258,    -1,   116,
     253,   366,   254,    -1,   332,   253,   345,   254,     7,   257,
     316,   333,   258,   257,   316,   333,   258,     6,    -1,    -1,
     141,     4,   345,    -1,    -1,     4,    -1,    -1,     7,   359,
      -1,    -1,     7,   345,    -1,    -1,   152,   359,    -1,   121,
     122,   360,     7,   345,     6,    -1,   136,   104,   360,     7,
     345,   336,     6,    -1,   136,   107,   360,   338,   337,     6,
      -1,   136,   109,   360,   338,     6,    -1,   177,   360,     6,
      -1,    99,   101,   253,   345,   262,   345,   254,     6,    -1,
      99,   104,   253,   345,   262,   345,   254,     6,    -1,    99,
     107,   253,   345,   262,   345,   254,     6,    -1,    99,   109,
     253,   345,   262,   345,   254,     6,    -1,   165,   107,   257,
     362,   258,     7,   345,     6,    -1,   167,   107,   257,   362,
     258,     7,   345,     6,    -1,   159,   107,   360,   339,     6,
      -1,   159,   109,   360,     6,    -1,   160,   107,   360,     7,
     345,     6,    -1,   139,   104,   257,   362,   258,     7,   257,
     362,   258,   340,     6,    -1,   139,   107,   257,   362,   258,
       7,   257,   362,   258,   340,     6,    -1,   139,   104,   257,
     362,   258,     7,   257,   362,   258,   146,   257,   356,   262,
     356,   262,   345,   258,     6,    -1,   139,   107,   257,   362,
     258,     7,   257,   362,   258,   146,   257,   356,   262,   356,
     262,   345,   258,     6,    -1,   139,   104,   257,   362,   258,
       7,   257,   362,   258,   147,   356,     6,    -1,   139,   107,
     257,   362,   258,     7,   257,   362,   258,   147,   356,     6,
      -1,   139,   107,   345,   257,   362,   258,     7,   345,   257,
     362,   258,     6,    -1,   310,   257,   362,   258,   191,   310,
     257,   345,   258,     6,    -1,   166,   312,   360,     6,    -1,
     127,   313,   360,     6,    -1,   128,   109,   359,     6,    -1,
     143,   104,   359,     6,    -1,   138,   311,   359,     6,    -1,
     163,     6,    -1,   163,     4,     6,    -1,   163,   101,   257,
     362,   258,     6,    -1,   212,    -1,   213,    -1,   214,    -1,
     343,     6,    -1,   343,   257,   359,   258,     6,    -1,   343,
     257,   359,   262,   359,   258,     6,    -1,   343,   253,   359,
     254,   257,   359,   262,   359,   258,     6,    -1,   346,    -1,
     253,   345,   254,    -1,   242,   345,    -1,   241,   345,    -1,
     248,   345,    -1,   345,   242,   345,    -1,   345,   241,   345,
      -1,   345,   243,   345,    -1,   345,   244,   345,    -1,   345,
     246,   345,    -1,   345,   247,   345,    -1,   345,   245,   345,
      -1,   345,   252,   345,    -1,   345,   235,   345,    -1,   345,
     236,   345,    -1,   345,   240,   345,    -1,   345,   239,   345,
      -1,   345,   234,   345,    -1,   345,   233,   345,    -1,   345,
     232,   345,    -1,   345,   231,   345,    -1,   345,   237,   345,
      -1,   345,   238,   345,    -1,   345,   230,   345,     8,   345,
      -1,    16,   287,   345,   288,    -1,    17,   287,   345,   288,
      -1,    18,   287,   345,   288,    -1,    19,   287,   345,   288,
      -1,    20,   287,   345,   288,    -1,    21,   287,   345,   288,
      -1,    22,   287,   345,   288,    -1,    23,   287,   345,   288,
      -1,    24,   287,   345,   288,    -1,    26,   287,   345,   288,
      -1,    27,   287,   345,   262,   345,   288,    -1,    28,   287,
     345,   288,    -1,    29,   287,   345,   288,    -1,    30,   287,
     345,   288,    -1,    31,   287,   345,   288,    -1,    32,   287,
     345,   288,    -1,    33,   287,   345,   288,    -1,    34,   287,
     345,   288,    -1,    35,   287,   345,   288,    -1,    38,   287,
     345,   262,   345,   288,    -1,    39,   287,   345,   262,   345,
     288,    -1,    40,   287,   345,   262,   345,   288,    -1,    25,
     287,   345,   288,    -1,    37,   287,   345,   262,   345,   288,
      -1,    36,   287,   345,   262,   345,   288,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   219,    -1,
     220,    -1,   221,    -1,    81,    -1,    82,    -1,    83,    -1,
      -1,    92,   287,   345,   347,   297,   288,    -1,   350,    -1,
     210,   287,   366,   288,    -1,   210,   287,   366,   262,   345,
     288,    -1,   352,    -1,   376,   255,   345,   256,    -1,   376,
     253,   345,   254,    -1,   215,   253,   352,   254,    -1,   215,
     253,   352,   259,   353,   254,    -1,   217,   253,   352,   348,
     254,    -1,   217,   253,   352,   259,   353,   348,   254,    -1,
     217,   253,   352,   287,   345,   288,   348,   254,    -1,   217,
     253,   352,   259,   353,   287,   345,   288,   348,   254,    -1,
     216,   253,   367,   254,    -1,   260,   376,   287,   288,    -1,
     260,   352,   259,   353,   287,   288,    -1,    95,   287,   376,
     288,    -1,    95,   287,   288,    -1,   376,   286,    -1,   376,
     255,   345,   256,   286,    -1,   376,   253,   345,   254,   286,
      -1,   376,   259,   353,    -1,   376,     9,   376,   259,   353,
      -1,   376,   259,   353,   253,   345,   254,    -1,   376,     9,
     376,   259,   353,   253,   345,   254,    -1,   376,   259,   353,
     255,   345,   256,    -1,   376,     9,   376,   259,   353,   255,
     345,   256,    -1,   376,   255,   345,   256,   259,     4,    -1,
     376,   259,     4,   286,    -1,   376,   255,   345,   256,   259,
       4,   286,    -1,   206,   253,   366,   262,   345,   254,    -1,
      59,   253,   359,   262,   359,   254,    -1,    60,   287,   366,
     262,   366,   288,    -1,    58,   287,   366,   288,    -1,    61,
     287,   366,   262,   366,   288,    -1,    66,   253,   373,   254,
      -1,    -1,   262,   345,    -1,    -1,   262,   366,    -1,    -1,
      93,   352,   355,   351,   255,   298,   256,    -1,   376,    -1,
     376,     9,   376,    -1,     4,    -1,    96,    -1,    96,   345,
      -1,    -1,   253,   354,   254,    -1,   357,    -1,   242,   356,
      -1,   241,   356,    -1,   356,   242,   356,    -1,   356,   241,
     356,    -1,   257,   345,   262,   345,   262,   345,   262,   345,
     262,   345,   258,    -1,   257,   345,   262,   345,   262,   345,
     262,   345,   258,    -1,   257,   345,   262,   345,   262,   345,
     258,    -1,   253,   345,   262,   345,   262,   345,   254,    -1,
     359,    -1,   358,   262,   359,    -1,   345,    -1,   361,    -1,
     257,   258,    -1,   257,   362,   258,    -1,   242,   257,   362,
     258,    -1,   345,   243,   257,   362,   258,    -1,   359,    -1,
     257,     8,   258,    -1,     5,    -1,   242,   361,    -1,   345,
     243,   361,    -1,   345,     8,   345,    -1,   345,     8,   345,
       8,   345,    -1,   101,   257,   345,   258,    -1,   101,   257,
       8,   258,    -1,   101,     5,    -1,   311,   257,     8,   258,
      -1,   311,     5,    -1,   137,   310,   360,    -1,   140,   310,
     359,    -1,   310,   191,    67,   257,   345,   262,   345,   262,
     345,   262,   345,   262,   345,   262,   345,   258,    -1,    67,
     310,   257,   362,   258,    -1,    76,   311,   257,   345,   258,
      -1,    77,   311,   257,   345,   258,    -1,   314,    -1,   325,
      -1,   334,    -1,   376,   287,   288,    -1,   376,   259,   353,
     287,   288,    -1,   376,     9,   376,   259,   353,   287,   288,
      -1,    41,   255,   376,   256,    -1,    41,   255,   361,   256,
      -1,    41,   253,   361,   254,    -1,    41,   287,   257,   362,
     258,   288,    -1,   376,   287,   257,   362,   258,   288,    -1,
      42,   287,   345,   262,   345,   262,   345,   288,    -1,    43,
     287,   345,   262,   345,   262,   345,   288,    -1,    44,   287,
     366,   288,    -1,    45,   287,   345,   262,   345,   262,   345,
     262,   345,   262,   345,   262,   345,   288,    -1,   211,   287,
     361,   288,    -1,    32,   287,   361,   288,    -1,   345,    -1,
     361,    -1,   362,   262,   345,    -1,   362,   262,   361,    -1,
     257,   345,   262,   345,   262,   345,   262,   345,   258,    -1,
     257,   345,   262,   345,   262,   345,   258,    -1,   376,    -1,
       4,   259,   188,   259,     4,    -1,   257,   365,   258,    -1,
     376,   255,   345,   256,   259,   189,    -1,   363,    -1,   365,
     262,   363,    -1,   367,    -1,   376,    -1,   376,   255,   345,
     256,    -1,   376,   253,   345,   254,    -1,   376,   259,   353,
      -1,   376,     9,   376,   259,   353,    -1,   376,   259,   353,
     253,   345,   254,    -1,   376,     9,   376,   259,   353,   253,
     345,   254,    -1,   376,   255,   345,   256,   259,     4,    -1,
     310,   257,   345,   258,    -1,   137,   310,   257,   345,   258,
      -1,     5,    -1,   224,   255,   376,   256,    -1,    70,    -1,
     222,    -1,    78,    -1,    80,    -1,   208,   253,   366,   254,
      -1,   207,   253,   366,   262,   366,   254,    -1,   209,   287,
     366,   288,    -1,   209,   287,   366,   262,   366,   288,    -1,
     218,   253,   352,   349,   254,    -1,   218,   253,   352,   259,
     353,   349,   254,    -1,    51,   287,   373,   288,    -1,    52,
     253,   366,   254,    -1,    53,   253,   366,   254,    -1,    54,
     253,   366,   262,   366,   262,   366,   254,    -1,    49,   287,
     373,   288,    -1,    63,   287,   366,   288,    -1,    64,   287,
     366,   288,    -1,    65,   287,   366,   288,    -1,    62,   287,
     345,   262,   366,   262,   366,   288,    -1,    57,   287,   366,
     262,   345,   262,   345,   288,    -1,    57,   287,   366,   262,
     345,   288,    -1,    50,   287,   366,   288,    -1,    50,   287,
     366,   262,   362,   288,    -1,    71,   287,   366,   288,    -1,
      72,    -1,    73,    -1,    56,   287,   366,   288,    -1,    55,
     287,   366,   288,    -1,    -1,    97,   287,   367,   368,   301,
     288,    -1,    94,   287,   369,   288,    -1,   260,   345,    -1,
     376,     9,   260,   345,    -1,    49,   287,   372,   288,    -1,
     373,    -1,   372,    -1,   257,   373,   258,    -1,   366,    -1,
     374,    -1,   373,   262,   366,    -1,   373,   262,   374,    -1,
     376,   253,   254,    -1,   376,   259,   353,   253,   254,    -1,
     376,     9,   376,   259,   353,   253,   254,    -1,     4,   261,
     257,   345,   258,    -1,   375,   261,   257,   345,   258,    -1,
     225,   255,   366,   256,   261,   257,   345,   258,    -1,     4,
      -1,   375,    -1,   225,   255,   366,   256,    -1
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
     767,   771,   772,   778,   778,   779,   779,   785,   786,   787,
     788,   793,   799,   861,   876,   905,   915,   920,   928,   933,
     941,   950,   955,   967,   984,   990,   999,  1017,  1035,  1044,
    1056,  1061,  1069,  1089,  1112,  1132,  1140,  1147,  1154,  1176,
    1199,  1237,  1258,  1270,  1284,  1284,  1286,  1288,  1297,  1307,
    1306,  1327,  1326,  1344,  1354,  1353,  1367,  1369,  1377,  1383,
    1388,  1415,  1417,  1420,  1422,  1426,  1427,  1431,  1443,  1447,
    1451,  1464,  1478,  1486,  1499,  1501,  1505,  1506,  1511,  1519,
    1528,  1536,  1550,  1568,  1572,  1579,  1588,  1591,  1597,  1601,
    1613,  1616,  1623,  1626,  1632,  1655,  1671,  1687,  1704,  1721,
    1758,  1802,  1818,  1834,  1866,  1882,  1899,  1915,  1965,  1983,
    1989,  1995,  2002,  2033,  2048,  2070,  2093,  2116,  2139,  2163,
    2187,  2211,  2237,  2254,  2270,  2288,  2306,  2318,  2332,  2331,
    2361,  2363,  2365,  2367,  2369,  2377,  2379,  2381,  2383,  2391,
    2393,  2395,  2403,  2405,  2407,  2409,  2419,  2435,  2451,  2467,
    2483,  2499,  2516,  2553,  2575,  2599,  2600,  2605,  2608,  2612,
    2629,  2649,  2669,  2688,  2715,  2734,  2755,  2770,  2786,  2804,
    2855,  2876,  2898,  2921,  3026,  3042,  3077,  3099,  3121,  3133,
    3139,  3154,  3182,  3194,  3203,  3210,  3222,  3242,  3246,  3251,
    3255,  3260,  3267,  3274,  3281,  3293,  3366,  3384,  3409,  3424,
    3457,  3469,  3501,  3505,  3510,  3517,  3522,  3532,  3537,  3543,
    3551,  3555,  3559,  3563,  3567,  3571,  3575,  3584,  3648,  3664,
    3681,  3698,  3720,  3742,  3777,  3785,  3793,  3799,  3806,  3813,
    3833,  3859,  3871,  3882,  3900,  3918,  3937,  3936,  3961,  3960,
    3987,  3986,  4011,  4010,  4033,  4049,  4066,  4083,  4106,  4134,
    4137,  4143,  4155,  4175,  4179,  4183,  4187,  4191,  4195,  4199,
    4203,  4212,  4225,  4226,  4227,  4228,  4229,  4233,  4234,  4235,
    4236,  4237,  4240,  4264,  4283,  4306,  4309,  4325,  4328,  4345,
    4348,  4354,  4357,  4364,  4367,  4374,  4396,  4437,  4481,  4520,
    4545,  4557,  4569,  4581,  4593,  4610,  4627,  4657,  4683,  4709,
    4741,  4768,  4794,  4820,  4846,  4872,  4894,  4905,  4953,  5007,
    5022,  5034,  5045,  5052,  5067,  5081,  5082,  5083,  5087,  5093,
    5105,  5123,  5151,  5152,  5153,  5154,  5155,  5156,  5157,  5158,
    5159,  5166,  5167,  5168,  5169,  5170,  5171,  5172,  5173,  5174,
    5175,  5176,  5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,
    5185,  5186,  5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,
    5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,
    5205,  5214,  5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,
    5223,  5224,  5229,  5228,  5236,  5238,  5243,  5248,  5252,  5257,
    5262,  5266,  5270,  5274,  5278,  5282,  5286,  5292,  5307,  5311,
    5317,  5322,  5341,  5361,  5392,  5396,  5400,  5404,  5408,  5412,
    5416,  5421,  5431,  5441,  5446,  5457,  5466,  5471,  5476,  5504,
    5505,  5511,  5512,  5518,  5517,  5540,  5542,  5547,  5556,  5558,
    5564,  5565,  5570,  5574,  5578,  5582,  5586,  5593,  5597,  5601,
    5605,  5612,  5617,  5624,  5629,  5633,  5638,  5642,  5650,  5661,
    5665,  5669,  5683,  5691,  5699,  5706,  5716,  5739,  5744,  5750,
    5755,  5761,  5772,  5778,  5784,  5790,  5802,  5816,  5826,  5836,
    5846,  5858,  5862,  5867,  5879,  5883,  5887,  5891,  5909,  5917,
    5925,  5954,  5964,  5980,  5991,  5996,  6000,  6004,  6016,  6020,
    6032,  6049,  6059,  6063,  6078,  6083,  6090,  6094,  6099,  6113,
    6129,  6133,  6137,  6141,  6145,  6153,  6159,  6168,  6172,  6176,
    6184,  6190,  6196,  6200,  6208,  6216,  6223,  6232,  6236,  6240,
    6255,  6269,  6283,  6295,  6311,  6320,  6329,  6339,  6350,  6358,
    6366,  6370,  6389,  6396,  6402,  6408,  6415,  6423,  6422,  6432,
    6456,  6458,  6464,  6469,  6471,  6476,  6481,  6486,  6488,  6492,
    6504,  6518,  6522,  6529,  6537,  6545,  6556,  6558,  6561
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
  "NumericAffectation", "NumericIncrement", "LP", "RP", "Affectation",
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
  "DefineStruct", "@15", "Struct_FullName", "tSTRING_Member", "Append",
  "AppendOrNot", "VExpr", "VExpr_Single", "RecursiveListOfListOfDouble",
  "ListOfDouble", "ListOfDoubleOrAll", "FExpr_Multi",
  "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
  "RecursiveListOfColor", "StringExprVar", "StringExpr", "@16",
  "NameStruct_Arg", "Str_BracedRecursiveListOfStringExprVar",
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
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   290,   290,   291,   291,   291,   292,
     291,   293,   291,   291,   294,   291,   295,   295,   296,   296,
     296,   297,   297,   298,   298,   299,   299,   300,   300,   300,
     300,   300,   300,   300,   301,   301,   302,   302,   303,   303,
     303,   303,   303,   304,   304,   304,   305,   305,   305,   305,
     306,   306,   307,   307,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   309,   308,
     310,   310,   310,   310,   310,   311,   311,   311,   311,   312,
     312,   312,   313,   313,   313,   313,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   318,   318,   318,   318,
     318,   318,   318,   318,   319,   319,   320,   321,   321,   321,
     321,   321,   321,   321,   321,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   325,   325,   325,   326,   325,   327,   325,
     328,   325,   329,   325,   325,   325,   325,   325,   325,   330,
     330,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   332,   332,   332,   332,   332,   333,   333,   333,
     333,   333,   334,   334,   335,   336,   336,   337,   337,   338,
     338,   339,   339,   340,   340,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   342,   342,   342,   343,   343,   343,   344,   344,
     344,   344,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   347,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   348,
     348,   349,   349,   351,   350,   352,   352,   353,   354,   354,
     355,   355,   356,   356,   356,   356,   356,   357,   357,   357,
     357,   358,   358,   359,   359,   359,   359,   359,   359,   360,
     360,   360,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   362,   362,   362,   362,   363,   363,
     363,   363,   364,   364,   365,   365,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   366,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   368,   367,   367,
     369,   369,   370,   371,   371,   372,   373,   373,   373,   373,
     374,   374,   374,   375,   375,   375,   376,   376,   376
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
       1,     1,     1,     1,     1,     1,     1,     5,     5,     2,
       7,     7,     4,     3,     6,     9,     7,     6,     7,     6,
       4,     8,     9,     9,     6,     9,     6,     9,     5,     8,
       8,    11,     6,     9,     5,     7,     7,     7,     9,     9,
      11,     7,     9,     9,     0,     1,     0,     3,     5,     0,
       9,     0,    11,     5,     0,     9,     0,     3,     3,     5,
       5,     0,     2,     0,     1,     1,     3,     2,     2,     2,
       1,     4,     2,     2,     0,     2,     1,     3,     2,     2,
       2,     2,     2,     1,     1,     3,     0,     5,     5,     5,
       0,     2,     0,     2,     7,     7,     7,    10,    10,     8,
       8,     7,     7,    11,     7,     8,     8,     8,     9,     3,
       4,    10,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     9,     7,     7,     8,     8,    12,     0,     9,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     4,     1,     1,     1,     4,     5,    11,     5,     9,
       9,     7,     4,     9,     9,     1,     1,     0,     2,     6,
       7,     7,     6,     7,     8,    10,    14,    16,    12,    14,
      14,    14,    14,     8,     8,     6,     4,     5,     5,     6,
       6,     3,     4,     3,     5,     6,     5,     4,     3,     4,
       3,     4,     5,     4,     5,     3,     5,     7,     7,     3,
       7,     3,     2,     2,     2,     2,     2,    15,     2,     2,
       2,     9,    11,     2,     2,     2,     2,    16,    11,     6,
       8,     8,    10,     1,     2,     2,     1,     3,     3,     4,
       4,     1,     1,     5,    11,    13,     0,     7,     0,    13,
       0,    15,     0,     6,     9,     2,     3,    10,    13,     1,
       2,     5,     7,     2,     2,     3,     2,     3,     2,     3,
       9,     6,     1,     1,     1,     1,     1,     0,     2,     3,
       3,     4,     9,     4,    14,     0,     3,     0,     1,     0,
       2,     0,     2,     0,     2,     6,     7,     6,     5,     3,
       8,     8,     8,     8,     8,     8,     5,     4,     6,    11,
      11,    18,    18,    12,    12,    12,    10,     4,     4,     4,
       4,     4,     2,     3,     6,     1,     1,     1,     2,     5,
       7,    10,     1,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     4,     6,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     1,     4,     6,     1,     4,     4,
       4,     6,     5,     7,     8,    10,     4,     4,     6,     4,
       3,     2,     5,     5,     3,     5,     6,     8,     6,     8,
       6,     4,     7,     6,     6,     6,     4,     6,     4,     0,
       2,     0,     2,     0,     7,     1,     3,     1,     1,     2,
       0,     3,     1,     2,     2,     3,     3,    11,     9,     7,
       7,     1,     3,     1,     1,     2,     3,     4,     5,     1,
       3,     1,     2,     3,     3,     5,     4,     4,     2,     4,
       2,     3,     3,    16,     5,     5,     5,     1,     1,     1,
       3,     5,     7,     4,     4,     4,     6,     6,     8,     8,
       4,    14,     4,     4,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     4,     4,
       3,     5,     6,     8,     6,     4,     5,     1,     4,     1,
       1,     1,     1,     4,     6,     4,     6,     5,     7,     4,
       4,     4,     8,     4,     4,     4,     4,     8,     8,     6,
       4,     6,     4,     1,     1,     4,     4,     0,     6,     4,
       2,     4,     4,     1,     1,     3,     1,     1,     3,     3,
       3,     5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,   201,     0,     0,   202,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   332,   333,   334,   335,   336,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,   301,   302,     0,     0,     0,   296,     0,     0,
       0,     0,     0,   385,   386,   387,     0,     0,     5,     6,
       7,     8,    10,     0,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,     0,   627,     0,   227,     0,     0,     0,     0,     0,
       0,   276,     0,   278,   279,   274,   275,     0,   280,   283,
       0,   284,   285,   116,   126,   626,   500,   495,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   286,     0,
     212,   213,   214,     0,     0,     0,     0,   441,   442,   444,
     445,   443,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   450,   451,     0,     0,   200,   205,   206,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,   447,   448,     0,     0,     0,     0,     0,     0,     0,
       0,   537,   538,     0,   539,   513,   392,   454,   457,   315,
     514,   495,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,   201,   202,   203,   198,   205,   206,     0,   207,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   502,     0,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,     0,     0,   227,
       0,     0,   382,     0,     0,     0,   209,   210,     0,     0,
       0,     0,     0,     0,   521,     0,     0,   519,     0,     0,
       0,     0,     0,   626,     0,     0,   560,     0,     0,     0,
       0,   272,   273,     0,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   579,     0,
     603,   604,   581,   582,     0,     0,     0,     0,     0,     0,
     580,     0,     0,     0,     0,   294,   295,     0,   227,     0,
     227,     0,     0,     0,   495,     0,     0,     0,   227,   388,
       0,     0,    79,     0,    66,     0,     0,    70,    69,    68,
      67,    72,    71,    73,    74,     0,     0,     0,     0,     0,
       0,     0,   566,   495,     0,   226,     0,   225,     0,   179,
       0,     0,   566,   567,     0,     0,     0,   616,     0,   617,
     567,     0,   114,   114,     0,   493,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   554,   555,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,     0,   394,
     522,   396,     0,   515,     0,     0,   495,     0,   530,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,   471,     0,     0,     0,     0,     0,
       0,     0,   316,     0,   349,   349,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,     0,   227,
     227,     0,   504,   503,     0,     0,     0,     0,   227,   227,
       0,     0,     0,     0,   312,     0,   227,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,     0,
       0,     0,     0,     0,   227,   253,     0,     0,   251,   383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   271,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   298,   297,     0,   258,     0,
       0,   260,     0,     0,     0,   394,     0,   227,     0,     0,
       0,     0,     0,     0,     0,   337,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    75,
      76,     0,     0,     0,   269,    40,   265,     0,     0,     0,
       0,     0,   222,     0,     0,     0,     0,     0,   228,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,   498,     0,     0,   496,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   343,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
     378,   379,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   452,   470,     0,     0,
       0,     0,   531,   532,     0,     0,     0,     0,     0,   489,
       0,   393,   516,     0,     0,     0,     0,   524,     0,   412,
     411,   410,   409,   405,   406,   413,   414,   408,   407,   398,
     397,     0,   399,   523,   400,   403,   401,   402,   404,   496,
       0,     0,   497,   474,     0,   540,     0,     0,     0,     0,
       0,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,   381,     0,     0,     0,     0,   380,     0,   227,     0,
       0,     0,     0,     0,   506,   505,     0,     0,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,     0,     0,
     252,     0,     0,     0,   246,     0,     0,     0,     0,   377,
       0,     0,     0,     0,   393,   520,     0,     0,     0,     0,
       0,     0,     0,     0,   299,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,   491,     0,
       0,   257,   261,   259,   263,     0,   399,     0,   496,   474,
     628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,   393,     0,    66,     0,     0,     0,     0,
      82,     0,    66,    67,     0,     0,     0,   496,     0,     0,
     474,     0,     0,     0,   198,     0,     0,     0,   623,    28,
      26,    27,     0,     0,     0,     0,     0,   497,   570,    30,
       0,    29,     0,     0,   266,   618,   619,     0,   620,   570,
       0,    77,   117,    78,   127,   499,   501,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   556,   557,   215,     9,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   438,   425,
       0,   427,   428,   429,   430,   431,   553,   432,   433,   434,
       0,     0,     0,     0,     0,   545,   544,   543,     0,     0,
       0,   550,     0,   486,     0,     0,     0,   488,     0,     0,
       0,   131,   469,   527,   526,   208,     0,     0,   455,   552,
     460,     0,   466,     0,     0,     0,     0,   517,     0,     0,
     467,     0,   529,     0,     0,     0,     0,   459,   458,   481,
      73,    74,     0,     0,     0,     0,     0,     0,     0,   393,
     345,   350,   348,     0,   358,     0,   153,   154,     0,   208,
       0,   393,     0,     0,     0,     0,   247,     0,   262,   264,
       0,     0,     0,   216,   218,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   319,     0,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,   352,   366,     0,     0,     0,   248,     0,     0,     0,
       0,   211,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,     0,   593,     0,   600,   589,
     590,   591,     0,   606,   605,     0,     0,   594,   595,   596,
     602,   610,   609,     0,   144,     0,   583,     0,   585,     0,
       0,     0,   578,     0,   256,     0,     0,     0,     0,     0,
       0,     0,   338,     0,     0,     0,   389,     0,   624,     0,
     104,    66,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,     0,     0,   575,    51,
       0,     0,     0,    64,     0,    41,    42,    43,    44,    45,
      46,     0,   459,   458,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   569,   568,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   140,     0,     0,
       0,   134,   135,     0,     0,     0,     0,     0,     0,     0,
     160,   160,     0,     0,     0,     0,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   534,   535,   536,     0,     0,     0,     0,
       0,   489,   490,     0,   462,     0,     0,     0,   525,   415,
     518,   475,   473,     0,   472,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,     0,     0,     0,     0,   324,     0,     0,   323,     0,
     326,     0,   328,     0,   313,   320,     0,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   368,
       0,   250,   249,   384,     0,     0,     0,    37,    38,     0,
       0,     0,     0,   561,     0,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,   492,   587,     0,   475,     0,     0,   227,   339,
       0,   340,   227,     0,     0,   576,     0,    89,     0,     0,
       0,     0,    87,    94,    96,     0,   564,     0,   102,     0,
       0,     0,     0,    84,     0,     0,     0,     0,     0,    36,
     475,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,   571,     0,     0,    34,
      33,     0,   571,   621,     0,     0,   118,   123,     0,     0,
       0,   137,   142,   143,   138,   139,   494,     0,    80,     0,
       0,     0,     0,    81,   164,     0,     0,     0,     0,   165,
     182,   183,   162,     0,     0,     0,   166,   193,   184,   188,
     189,   185,   186,   187,   174,     0,     0,   426,   440,   439,
     435,   436,   437,   546,     0,     0,     0,   484,   485,   487,
     132,   453,   483,   456,   461,     0,     0,   489,   194,   468,
       0,    73,    74,     0,   480,   476,   478,   547,   190,     0,
       0,     0,   156,     0,     0,   356,     0,   155,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   227,
     227,     0,     0,   325,   513,     0,     0,   327,   329,     0,
       0,   307,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   221,   191,     0,     0,     0,     0,     0,   171,
     172,     0,     0,     0,     0,   105,   106,   107,   111,     0,
     601,     0,     0,   599,     0,   611,     0,     0,   145,   146,
     608,   584,   586,     0,     0,     0,     0,     0,     0,   337,
     341,   337,     0,   390,    88,    66,     0,     0,     0,     0,
      86,     0,   562,     0,     0,     0,     0,     0,     0,   614,
     613,     0,     0,     0,     0,     0,   511,     0,     0,   480,
     267,   476,   268,     0,     0,     0,     0,     0,   232,   229,
       0,     0,   574,   572,     0,     0,     0,     0,   119,   124,
       0,     0,     0,   554,   555,   136,   360,   361,   362,   363,
     161,   169,   170,   175,     0,     0,     0,     0,     0,   177,
       0,     0,     0,     0,     0,     0,   463,     0,     0,     0,
       0,   542,   482,     0,     0,   176,     0,   195,   346,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,     0,
     510,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,   243,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,   364,   365,    39,     0,   559,
       0,     0,   291,   290,     0,     0,     0,     0,     0,     0,
     148,   149,   152,   151,   150,     0,   588,     0,   625,     0,
       0,     0,     0,     0,     0,    99,     0,     0,   100,   565,
       0,     0,     0,    91,     0,     0,     0,    47,     0,     0,
       0,     0,     0,    49,     0,   233,   230,   231,    35,     0,
       0,   622,   281,     0,   131,   144,     0,     0,   141,     0,
       0,     0,   163,   192,     0,     0,     0,     0,     0,   548,
     549,     0,   489,   464,     0,   477,   479,     0,     0,   178,
     199,     0,     0,     0,   353,   353,     0,   112,   113,   227,
       0,   219,   220,   314,     0,   321,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   224,   223,     0,
       0,     0,     0,   108,   109,   592,   598,   597,   147,     0,
       0,     0,   342,     0,    95,    97,     0,   103,     0,    85,
     615,    92,    93,    52,     0,     0,     0,     0,   512,     0,
       0,   477,   573,     0,     0,     0,     0,   121,   612,     0,
     128,     0,     0,     0,     0,   181,     0,     0,     0,     0,
     317,     0,   167,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   508,     0,   331,     0,     0,   308,
       0,   235,     0,     0,     0,     0,     0,     0,     0,   558,
     292,     0,     0,   376,   227,   391,     0,   563,     0,    48,
       0,     0,     0,    65,    50,     0,   282,   120,   125,   131,
       0,     0,   158,   159,   157,     0,     0,   465,     0,     0,
       0,     0,     0,   354,   369,     0,     0,   370,     0,   217,
       0,   322,     0,   304,     0,   227,     0,     0,     0,     0,
       0,     0,   173,   110,   288,   337,   101,     0,     0,     0,
       0,     0,     0,   129,   130,     0,     0,     0,     0,   197,
       0,   373,     0,   374,   375,   507,     0,     0,   310,   238,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
      62,     0,     0,   122,     0,     0,     0,   318,     0,     0,
     330,   309,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,   242,     0,   236,   344,    53,
       0,    60,     0,   277,     0,   551,     0,     0,     0,   311,
       0,     0,    54,     0,     0,   287,     0,     0,     0,   237,
       0,     0,     0,     0,   533,     0,     0,    57,    55,     0,
      58,     0,   371,   372,     0,     0,    63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,  1082,   119,   120,  1066,  1936,  1942,
    1365,  1584,  2098,  2231,  1366,  2202,  2249,  1367,  2233,  1368,
    1369,  1588,   446,   604,   605,  1155,   121,   791,   472,  1954,
    2109,  1955,   473,  1822,  1447,  1400,  1401,  1402,  1548,  1758,
    1759,  1225,  1645,  1636,  1835,   768,   616,   279,   280,   359,
     204,   281,   456,   457,   125,   126,   127,   128,   129,   130,
     131,   132,   282,  1259,  2134,  2193,   961,  1255,  1256,   283,
    1045,   284,   136,  1476,  1223,   934,   976,  2068,   137,   138,
     139,   140,   285,   286,  1181,  1196,  1321,   287,   796,   288,
     923,   795,   475,   633,   327,  1795,   367,   368,   290,   574,
     375,  1352,  1577,   467,   462,  1314,  1022,  1623,  1788,  1789,
    1007,   469,   142,   424
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1921
static const yytype_int16 yypact[] =
{
   13150,    90,   151, 13352, -1921, -1921,   -11,   156,    85,   -24,
      64,    71,    20,   270,   329,   332,   341,   125,   403,   411,
      45,   419,   448,   194,   200,    26,   -68,    75,   -68,   214,
     224,   258,    50,   267,   275,    58,   295,   364,   386,   393,
     399,   402,   405,   447,   453,   459,   274,   468,   569,   713,
     431,   616,   613,   474,  6963,   482,   495,   518,   665,   -49,
     443,   617,   327,   107,   534,   697,  -114,   529,   191,   191,
     541,   296,    66,   567, -1921, -1921, -1921, -1921, -1921,   586,
     276,   725,   743,    11,    40,   752,   793,   356,   803,   913,
     922,   929,  5959,   934,   700,   728,   745,    15,    61, -1921,
     764,   790, -1921, -1921,   978,  1028,   789, -1921,   435,   798,
   13596,    32,    35, -1921, -1921, -1921, 11989,   797, -1921, -1921,
   -1921, -1921, -1921,   796, -1921, -1921, -1921, -1921, -1921, -1921,
   -1921, -1921, -1921, -1921,  -147, -1921, -1921, -1921, -1921,    30,
   -1921,  1048,   799,  5706,   452,   800,  1049, 11989, 13534, 13534,
   13534, -1921, 11989, -1921, -1921, -1921, -1921, 13534, -1921, -1921,
   11989, -1921, -1921, -1921, -1921,   801,   805,  1050, -1921, -1921,
    7594,   810,   811,   812,   813,    26, 11989, 11989, 11989,   814,
   11989, 11989, 11989,   815, 11989, 11989, 11989, 11989, 11989, 11989,
   11989, 13534, 11989, 11989, 11989, 11989,  5959,   816, -1921,  9714,
   -1921, -1921, -1921,   820,  5959,  7214, 13534, -1921, -1921, -1921,
   -1921, -1921,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   352,   -68,   -68,
     -68,   -68,   -68,   817,   -68,   -68,   818,   617,   625,   625,
   -1921, -1921, -1921,   -68,   -68,    36,   881,   882,   887,   823,
    7214,   951,   617,   617,   829,   -68,   -68,   830,   831,   833,
   -1921, -1921, -1921, 11989,  7465, 11989, 11989,  7716,    26,   899,
      47, -1921, -1921,   834, -1921,  4603, -1921, -1921, -1921, -1921,
   -1921,    57, 11989,  9714,  9714,   839,   841,  7967,  5959,  5959,
    5959, -1921, -1921, -1921, -1921, -1921, -1921, -1921,   842, -1921,
     836,   843,  8218,   844,  4662,  1094,  7214,   847,    15,   848,
     849,   191,   191,   191, 11989, 11989,   238, -1921,   421,   191,
   10647,   423,   259,   854,   855,   856,   857,   858,   861,   876,
    9714, 11989,  5959,  5959,  5959,   877,    12,  1126,   845, -1921,
    1127,  1128, -1921,   878,   879,   880, -1921, -1921,   898,  5959,
     900,   883,   884,   903, -1921, 11989,  6210, -1921,  1154,  1155,
   11989, 11989, 11989,   469, 11989,   905, -1921,   972, 11989, 11989,
   11989, -1921, -1921, 11989, -1921,   -68,   -68,   -68,   911,   912,
     914,   -68,   -68,   -68,   -68,   -68,   -68,   -68, -1921,   -68,
   -1921, -1921, -1921, -1921,   -68,   -68,   915,   916,   -68,   917,
   -1921,   919,  1160,  1169,   920, -1921, -1921,  1170,  1171,  1172,
    1173,   -68, 11989, 11946,    77, 13534,  9714, 11989, -1921, -1921,
    7214,  7214, -1921,   923,  7594,   617,  1175, -1921, -1921, -1921,
   -1921, -1921, -1921, 11989, 11989,    53,  7214,  1177,   776,   927,
    2328,   937,  1190,    29,   940, -1921,   944, 11378, 11989, -1921,
    2403,  -198, -1921,    98,  -191,   -97,  8655, -1921,   -50, -1921,
     105,  8901,   -23,   110,  1107, -1921,    26,   942, 11989, 11989,
   11989, 11989,   943, 15869, 15894, 15919, 11989, 15944, 15969, 15994,
   11989, 16019, 16044, 16069, 16094, 16119, 16144, 16169,   956, 16194,
   16219, 16244, 14482,  1208, 11989,  9714,  6145, -1921,   374, 11989,
    1211,  1212,   965, 11989, 11989, 11989, 11989, 11989, 11989, 11989,
   11989, 11989, 11989, 11989, 11989, 11989, 11989, 11989, 11989,  9714,
   11989, 11989, 11989, 11989, 11989, 11989, 11989, 11989,  9714,  9714,
     963, 11989, 11989, 13534, 11989, 13534,  7214, 13534, 13534, 13534,
     964,   966,   967, 11989,     9, -1921, 10733, 11989,  7214,  5959,
    7214, 13534, 13534,  9714,    26,  7594,    26,   970,  9714,   970,
   -1921,   970, 16269, -1921,   408,   968,   116,  1158, -1921,  1218,
   11989, 11989, 11989, 11989, 11989, 11989, 11989, 11989, 11989, 11989,
   11989, 11989, 11989, 11989,  8469, 11989, 11989, 11989, 11989, 11989,
      26, 11989, 11989,  1224, -1921,   781, 16294,   415,   488, 11989,
   11989, 11989, -1921,  1222,  1225,  1225,   981, 11989, 11989, 11989,
   11989,  1229,  9714,  9714, 15381,   977,  1230, -1921,   982, -1921,
   -1921,  -144, -1921, -1921,  9147,  9398,   191,   191,   452,   452,
    -141, 10647, 10647, 11989, 12017,  -126, -1921, 11989, 11989, 11989,
   11989, 11989, 11989, 11989, 11989, 11989,   542, 16319,  1231,  1235,
    1237, 11989,  1236, 11989, -1921, -1921, 11989, 12149, -1921, -1921,
    9714,  9714,  9714, 11989,  1240,  9714, 11989, 11989, 11989, 16344,
     989, -1921, -1921, 16369, 16394, 16419,  1060,  9649, -1921,   992,
    6396, 16444, 16469, 15464, 13534, 13534, 13534, 13534, 13534, 13534,
   13534, 13534, 13534, 11989, 13534, 13534, 13534, 13534,    10,  7594,
   13534, 13534, 13534,    26,    26, -1921, -1921,  9714, -1921,   993,
   12207, -1921,   994, 12292, 11989,   970, 11989, -1921,    26, 11989,
   11989,  1224,   999,   568, 16494, 11039,   996,   573, 11989,  1251,
    1001,  7214, 16519, 15491,   148,  1000,  1254,  1256, -1921, -1921,
   -1921,  9714,   184, 11989, -1921, -1921, -1921,    26, 11989, 11989,
    1224,  1008, -1921,  1011,   -46,   617,   327,   617, -1921,  1009,
   14511, -1921,    23,  9714,    26, 11989, 11989,  1265,  1264,  9714,
    1266,  9714, 11989,  1271, 13534,    26, 10979,  1265, 11989,  1275,
   -1921,    26,  1276, 13534, 11989,  1017,  1031, -1921, 11989,  9991,
   10337, 10599, 10678,  7594,  1280,  1281,  1282, 16544,  1283,  1284,
    1288, 16569,  1291,  1294,  1295,  1297,  1298,  1299,  1300, -1921,
    1301,  1302,  1303, -1921, 11989, 16594,  9714,  1054,  9714, 14540,
   -1921, -1921,  1307, 15437, 15437, 15437, 15437, 15437, 15437, 15437,
   15437, 15437, 15437, 15437, 11010, 15437, 15437, 15437, 15437,  1849,
     739, 15437, 15437, 15437, 11349, 11609, 11688, 11855, 12969,  6145,
    1061,  1062,    93,  9714, 13149, 13464,   739, 13530,   739,  1057,
    1058,  1059,   -36,  9714, 11989, 11989, 12136, -1921,   739,  1064,
   14569, 14598, -1921, -1921,  1063,  -112,   739,  -151,  1069,   359,
     579,  1309, -1921,  1265,   739,  1067,  1068,  6647,  6898,   652,
     522,   907,   907,   550,   550,   550,   550,   550,   550,   278,
     278,  9714,   533, -1921,   533,   533,   970,   970,   970,  1070,
   16619, 15518,  -128,   773,  9714, -1921,  1320,  1071,  1073, 16644,
   16669, 16694, 11989,  7214,  1327,  1329, 10401, 16719, 14627, 16744,
   16769, -1921,   580,   582,  9714,  1074, -1921, 12350, -1921, 12435,
   12493,   191, 11989, 11989, -1921, -1921,  1079,  1080, 10647,  4528,
    1198,   300,   191, 12578, 16794, 14656, 16819, 16844, 16869, 16894,
   16919, 16944, 16969,  1083,  1334, 11989,  1336, -1921, 11989, 16994,
   -1921, 15545, 12636, 15572, -1921,   588,   590,   591, 14685, -1921,
     596, 15599, 15626, 13591, -1921, -1921,  1339,  1340,  1342,  1091,
   11989, 12721, 11989, 11989, -1921, -1921,    46,   247,   368,   247,
    1097,  1098,  1095,   739,   739,  1100, 13624,   739,   739,   739,
     739, 11989,   739,  1344, -1921,  1101,  1102,   425,  -125,  1103,
     599, -1921, -1921, -1921, -1921, 15437,   533, 12779,  1105,   786,
    1104,  1176,  1359,  1206, 11072,  1111,  1114,  1366,  7214, 14714,
   -1921, 11989,  1367,   153,    72,  7594, 11989,  1368,  1372,    24,
   -1921,   601,  1330,  1331,  7214, 14743,    27,  1119, 17019, 15653,
     339, 11989, 11989,  1129,  1124,  1131,  1134,  8720, -1921, -1921,
   -1921, -1921, 13534,    67,  1137, 17044, 15680, -1921,  1133, -1921,
      88, -1921,   108, 13657, -1921, -1921, -1921,  1138, -1921,  1142,
   13690, -1921,   106, -1921, -1921, 12136, -1921,    56, 15437, 11989,
   11989, 11989, 11989,   739,   191,  7214,  7214,  1391,  7214,  7214,
    7214,  1392,  7214,  7214,  7214,  7214,  7214,  7214,  7214,  7214,
    7214,  7214,  2622,  1393,  9714,  6145, -1921, -1921, -1921, -1921,
   -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921,
   11989, -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921,
   11989, 11989, 11989, 11989, 11989, -1921, -1921, -1921,   604, 11989,
   11989, -1921, 11989, -1921,  7214, 13534, 13534, -1921,   606, 14772,
   14801,  1141, -1921, -1921, -1921,  1213, 11989, 11989, -1921, -1921,
   -1921,  1265, -1921,  1265, 11989, 11989,  1151, -1921,  7214,   -68,
   -1921, 11989, -1921, 11989, 11989,   607,  1265,  -128,  -139, -1921,
   11989, 11989,   739,   609,  7214,  9714,  9714,  1399,  1400,  1401,
     575, -1921, -1921,  1404, -1921,  1157, 12136,  1150,  1407, -1921,
    1408,  1409,  1410,  1411,   614,  1415, -1921, 12864, -1921, -1921,
    -103, 13723, 13756, -1921, -1921, 14830,     6,  1304,  1416, 11318,
    1164,  1418,  1174,    33,    37,   -42, -1921,   -47, -1921,   300,
    1427,  1419,  1432,  1433,  1437,  1438,  1439,  1443,  1444,   452,
    7214, 12136, -1921,  2831,  1165,  1446, -1921,  1447,  1448,  1348,
    1449, -1921,  1450,  1452,  1453, 11989,  7214,  7214,  7214,  1456,
   13789, -1921,  7149,  2153,    38,  1457, -1921,  9714, -1921, -1921,
   -1921, -1921, 13534, -1921, -1921, 11989, 13534, -1921, -1921, -1921,
   -1921, 12136, -1921,  1202,  1201, 13534, -1921, 13534, -1921,  1265,
   13534,  1210, -1921,  1203, -1921,  1265, 11989, 11989,  1209,   617,
    1216, 11411, -1921,  2968,  1217,  7214, -1921,  1223, -1921, 14859,
   -1921, -1921, 11989,  1461,    55, 11989,  1469,  1470,  3024, -1921,
    1473,    15,  1476,  1228,   739,   -68,   -68,  1479, -1921, -1921,
    1233,  1234,  1232, -1921,  1482, -1921, -1921, -1921, -1921, -1921,
   -1921,  1265,   221,  3577, 11989, 15707, 17069, 11989,  8966, 11989,
    9714,  1238,   615,  1484,   155,  1265, -1921,  1239, 11989,  1485,
    1486, 11989,  1265, 11657, 11989,  9960,   739,  5137, 11989, 11989,
    1241,  1242, -1921,  1489, 17094, 17119, 17144, 17169,  1493,    14,
    1369,  1369,  7214,  1494,  1495,  1496,  7214,   -96,  1500,  1502,
    1503,  1505,  1506,  1508,  1510,  1512,  1513, -1921,  1515,   620,
   15437, 15437, 15437, 15437, 15437, 15437,   739, 13822, 13855, 13888,
    1267,   739,   739, -1921, -1921, -1921,    56,   739, 17194, 15437,
    1268,  -177, 12136, 15437, -1921,  1517,   739, 13921, 12136, 12136,
   -1921,   787, -1921,  1521, -1921, 17219, 15734, -1921,   739,  1520,
     644,   645,  7214,  7214,  7214,  1523,  1522, -1921,   192, 11989,
    7214,  7214,  7214,  1272,  1273,  1524,   255, -1921, 11989, 11989,
   11989,  1286,  1292,  1296,  1277, -1921,  3163,  7214, -1921, 11989,
   -1921,  1527, -1921,  1542, -1921, -1921, 10647,    -6,  6461, -1921,
    1305,  1310,  1311,  1312,  1313,  1314,  9212,  1306,  1549, -1921,
    9714, -1921, -1921, -1921,  1316, 11989, 11989, -1921, -1921, 15761,
    1550,  1551,  1371, -1921, 11989, 11989, 11989, -1921,  1553,  1555,
    1560,   394,   477,  1315,  3987,  1318, 11989,    28,   739,  1322,
     739,  1319, -1921, -1921,  7594,   794, 11989,  1317, -1921, -1921,
    3289, -1921, -1921,  1321,  1576, -1921,  3763, -1921,   179,  1326,
    1579,  4295, -1921, -1921, -1921,    15, -1921,   647, -1921, 11989,
     192,  1136,  2194, -1921,  1335, 11989, 11989,  7214,  1332, -1921,
     496,  1586,  1585, 17244,  1587,  1309, 17269,  1337,   653, 17294,
     654,  1588,  1590, -1921, -1921, 13534,  1345,  1593, 17319, -1921,
   -1921, 13954,  1346, -1921,  7651,  5455, 12136, -1921,  1594,   -68,
    7716, -1921, -1921, -1921, 12136, 12136, -1921,    56, -1921,  1598,
    1600,  1602,  1603, -1921, -1921,   191,  1604,  1605,  1607, -1921,
   -1921, -1921,  1451,   -32,  1509,  1609, -1921, -1921, -1921, -1921,
   -1921, -1921, -1921, -1921, -1921,  1595,  1361, -1921, -1921, -1921,
   -1921, -1921, -1921, -1921, 11989, 11989, 11989, -1921, -1921, -1921,
    1242, -1921, -1921, -1921, -1921, 11989,  1362,  1357, -1921, -1921,
   11989, 11989, 11989,   739,  -128, -1921, -1921, -1921, -1921,  1363,
    1364,  1616,   -96,  1617, 11989, -1921,  7214, 12136,  1487,  1488,
    1044,  9714,  9714, 11989, -1921, 10401, 14888, 17344,  7902,   452,
     452, 11989, 11989, -1921,   337,  1365, 17369, -1921, -1921, 14917,
     -17, -1921,  1619,  1620,  7214,   191,   191,   191,   191,   191,
    6712,  1624, -1921, -1921,   656, 11989,  4363,  4799,  1625, -1921,
   -1921,  7214,  8153,   769, 17394, -1921, -1921, -1921, -1921, 10055,
   -1921, 13534, 11989, -1921, 13534, 12136, 10306,  7594,  1370, -1921,
   -1921, -1921, -1921,  1380,  1373, 11989, 11989, 14946, 11989, 11039,
   -1921, 11039,  7214, -1921, -1921,  7594, 11989,  1630,  1633,    24,
   -1921,  1632, -1921,    15, 15788,  7214, 13534,  1634,   739, -1921,
    1379,   739, 11989, 13987, 14020,   661, -1921, 11989, 11989,   490,
   -1921,  1385, -1921,  1401,  1637,  1639,  1409,  1640, -1921, -1921,
    1641, 11989, -1921, -1921, 11989, 11743,  1642, 11989, -1921, -1921,
    1394,  2194,   662,  3849,  1643, -1921, -1921, -1921, -1921, -1921,
     196, -1921, -1921, -1921,  1504,  1647,  1403,  1414,  1417, -1921,
    1651,  7214, 15437, 15437, 14053, 15437, -1921,  1421, 14086, 17419,
   15815, -1921, -1921,  9714,  9714, -1921,  1666, -1921, 12136,  1667,
   11989, 11989,  1420, -1921,   667,   669, 15409,  4822,  1670,  1422,
   -1921, -1921, 11989,  1423,  1424, 14975, 15842,  1672,  7214,  1676,
    1428, 11989, -1921, -1921,   670,    -4,   152,   154,   204,   220,
    9463,   252, -1921,  1678, 15004, -1921, -1921, -1921,  1501, -1921,
   11989, 11989, -1921, -1921,  9714,  4865,  1680,  1435, 15437,   739,
   12136, -1921, -1921, -1921, -1921,    28, -1921,  7594, -1921, 15033,
    1434,  1436,  1442,  1684,  5072, -1921,  1690,  1685, -1921, -1921,
    1445,  1695,   678, -1921,  1696,  1697,   135, 12136, 11989, 11989,
    1455,  7214,   681, 12136, 17444, -1921, -1921, -1921, -1921, 17469,
   14119, -1921, -1921, 15062,  1141,  1201,  7214,   739, -1921, 11989,
    7594,    26, -1921, -1921,  9714,  9714, 11989,  1699,   686, -1921,
   -1921, 11989,  1357, -1921, 11989, -1921, -1921,   687,   688, -1921,
   -1921,  5177,  5390,  7214,   637,   682,  9714, -1921, -1921,   452,
    8404, -1921, -1921, -1921,  1700, -1921,  1458,  7214, -1921, 15091,
    1701,  9714,   191,   191,   191,   191,   191, -1921, -1921, 11989,
   15120, 15149,   689, -1921, -1921, -1921, -1921, -1921, -1921,  1463,
    1704,  1462, -1921,  1709, -1921, -1921,    15, -1921,  1529, -1921,
   -1921, -1921, -1921, -1921, 11989, 14152, 14185,  7214, -1921,  1714,
   11989,  1465, -1921, 11989,  1717,  1466,  1467, -1921, -1921,  5204,
   -1921,  1475,   694,   696, 15178, -1921,  1478, 14218,  1472, 14251,
   -1921,  1483, -1921, -1921,   701,  1490,   191,  7214,  1733,  1492,
     191,  1735,   702,  1497, -1921, 11989, -1921,  1736,  1611, 12922,
    1499, -1921,   703,   277,   292,   344,   346,   361,  5632, -1921,
   -1921,  1737,  1738, -1921, -1921, -1921,  1739, -1921,  1507, 12136,
   11989, 11989,   709, -1921, 12136, 14284, -1921, -1921, -1921,  1141,
    7594,  1511, -1921, -1921, -1921, 11989, 11989, -1921, 11989,  9714,
    1740,   191,   113, -1921, -1921,   191,   146, -1921,  1744, -1921,
   15207, -1921, 11989, -1921,   300, -1921,  1748,  9714,  9714,  9714,
    9714,  9463, -1921, -1921, -1921, 11039, -1921, 11989, 17494, 14317,
      49, 11989,  1514, -1921, -1921, 14350, 14383, 14416,   710, -1921,
     369, -1921,   385, -1921, -1921, -1921,  5894,   283, 13007, -1921,
     715,   716,   717,   718,   387,   724,  1516,   729, -1921, 11989,
   -1921,  7214, 15236, -1921, 11989, 11989, 11989, -1921,   191,   191,
   -1921, -1921, -1921,   300,  1751,  1752,  1753,  1754,  9714,  1755,
    1756,  1757,  1518, 17519,   734,  1760, 15265, 15437, 14449,   392,
     409,   515, -1921, -1921, -1921, -1921,   760, -1921, -1921, -1921,
   13534, -1921,  1528, -1921,  1761, -1921, 11989, 11989, 11989, -1921,
    1762,   761, -1921,  1531,  7214, -1921, 15294, 15323, 15352, -1921,
    1764, 13534, 13534,   762, -1921,  1765,  1767, -1921, -1921,   767,
   -1921,  1771, -1921, -1921,  1772, 13534, -1921, -1921, -1921
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1921, -1921, -1921, -1921,   395, -1921, -1921, -1921, -1921,  -366,
   -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921, -1921,
   -1921, -1921,  -735,  -119,  4227,  3544, -1921,  1323, -1921, -1921,
   -1921, -1921, -1921, -1921, -1920, -1921,   338,   159,  -164, -1921,
    -123, -1921,   101,   383, -1921,  1792, -1921,   840,   -51, -1921,
   -1921,    -1,  -634,  -262, -1921, -1921, -1921, -1921, -1921, -1921,
   -1921,   732,  1794, -1921, -1921, -1921, -1921, -1251, -1254,  1796,
   -1759,  1797, -1921, -1921, -1921,  1186, -1921,  -183, -1921, -1921,
   -1921, -1921,  2173, -1921, -1921, -1445,   253,  1802, -1921,     0,
    -710, -1921, -1921,     4, -1921, -1717,   539,  -169,  2887,  2822,
    -315,    31, -1921,   731,   -61, -1921, -1921,    51,   226, -1738,
    -134,  1022, -1921,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -575
static const yytype_int16 yytable[] =
{
     143,  1505,   124,   628,   956,   957,  1676,  1884,  1507,  1056,
    1920,   312,  1921,   165,   165,   346,   662,  1064,  1913,   373,
    1634,  1039,   167,   468,   447,   166,   151,   503,   165,  1079,
     165,  1359,  1756,   165,  2045,   510,   429,   417,   757,  1500,
     419,   555,  1538,  1502,   351,  1643,   352,   412,   317,   416,
    1070,   291,   578,  1294,   179,  2180,   772,   744,   296,  1568,
    1397,   296,   183,   778,   773,   377,   600,  1088,   644,  1836,
     332,   779,   326,   328,   318,   331,   168,  1099,   169,  1341,
     350,   297,   452,  1957,  1073,  1194,   728,   667,  1837,   291,
     319,   320,  1398,  1399,   376,  1644,     4,   636,   637,  1248,
     636,   637,   600,  1190,   347,   413,   427,   774,  1191,   477,
     428,   441,   442,  1395,   785,   636,   637,  1249,   951,  2161,
    1463,   958,   441,   442,  1968,   476,  1250,  1251,  1252,   613,
     614,   615,  1253,  1254,  1319,  1248,   962,  1320,   636,   637,
     453,   353,   749,   455,   750,   463,   463,   463,  1539,  1540,
    1187,     5,  2163,  1249,   470,  1055,   720,   780,   723,  1488,
    1341,  1604,  1250,  1251,  1252,   781,   735,   333,  1253,  1254,
     146,   334,   482,   658,   659,   660,   171,   335,   336,   172,
     337,   338,   173,  1199,   174,   168,  1775,   169,   463,  2152,
     674,  1062,   147,   291,   636,   637,   291,   551,   552,  1341,
     339,   291,   291,   463,   783,  1360,  1361,  1362,  1363,  1501,
     348,   313,   784,  1503,   314,  1506,  1504,    98,  1177,    99,
     100,   101,   102,   103,   636,   637,   784,   107,   108,   148,
     110,  1757,  1847,   789,   117,   117,   117,   636,   637,   790,
     117,   745,   746,  1569,  1570,  1881,   144,   636,   637,   117,
     145,   117,  1721,  1505,   117,   636,   637,   291,  2001,  1080,
    1081,  1704,  1705,   749,  1492,   750,  2064,   663,   349,   664,
    1021,   291,   374,   145,   291,   576,   153,   152,   575,   441,
     442,  1351,   758,   430,   759,  1364,  -567,   431,   760,   418,
     291,   291,   420,   556,   291,   291,   291,   291,   437,   438,
     439,   440,   160,   180,   579,  1295,  2181,   441,   442,   291,
     601,   184,   602,   291,   378,   376,   603,   149,  1342,  1345,
    2102,  1384,   441,   442,   150,   631,   632,   441,   442,   828,
     729,  1344,   730,   640,   645,   154,   731,   291,   155,   291,
     291,   291,  1389,   441,   442,   580,   601,   156,   602,  1167,
     828,   775,   603,   776,   636,   637,   291,   777,   786,   168,
     776,   169,  1390,   291,   787,   947,   792,   949,   950,   168,
     828,   169,   790,   739,   437,   438,   439,   440,   157,   437,
     438,   439,   440,   342,   963,   343,  2176,   636,   637,  2033,
     882,  1080,  1081,   636,   637,   636,   637,  2034,   441,   442,
    1748,  1749,   982,   441,   442,   437,   438,   439,   440,   158,
     437,   438,   439,  1063,  2002,   872,  2003,   159,   437,   438,
     439,   440,   463,   291,  1248,   161,  1001,   291,   291,   441,
     442,   306,   322,   323,   307,   308,   309,   636,   637,   165,
     384,  1248,  1249,   291,   324,   636,   637,   310,   325,   163,
     761,  1250,  1251,  1252,   162,   164,   454,  1253,  1254,  1249,
     356,   636,   637,   357,  2204,  1037,  2004,   176,  1250,  1251,
    1252,   441,   442,   797,  1253,  1254,   358,   177,  -569,   636,
     637,  1450,  2005,  1451,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   636,   637,   638,  1461,   394,   395,   396,
     397,   749,   291,   750,   888,   398,   399,   400,   401,   784,
     311,   178,   647,   402,  2006,   403,   648,  2243,   636,   637,
     181,   726,   595,   596,   597,   598,   291,  2058,   182,   404,
     599,   195,   405,   636,   637,   291,   862,   322,   323,  2137,
     463,  2191,   463,   291,   463,   463,   470,   298,   185,   324,
     299,   878,   300,   330,  2138,   291,   291,   291,   463,   463,
     291,   167,  1009,   167,   887,   291,   889,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   636,   637,   636,   637,   599,
     196,   291,  1374,   289,  1327,  1877,  -570,   919,    67,    68,
      69,    70,   636,   637,    73,   538,  2139,   539,  2140,  1551,
     636,   637,   168,    82,   169,  1555,    85,   186,  1193,   291,
     291,  1194,   749,  2141,   750,  1057,   636,   637,   636,   637,
    1297,  2188,   827,   636,   637,  1517,   828,   455,   455,   187,
     954,   955,   406,   407,   408,   632,   188,  2189,  1024,  2198,
     636,   637,   189,   409,  2227,   190,  1248,   410,   191,   411,
     117,  1590,   636,   637,   636,   637,   892,   291,   291,   291,
     828,  2228,   291,   927,  1249,  1606,   197,   828,   639,   749,
     646,   750,  1612,  1250,  1251,  1252,  1237,  1317,   199,  1253,
    1254,   470,   463,   470,   463,   463,   463,   463,   463,   463,
     192,   463,   463,   463,   463,  1023,   193,   463,   463,   463,
     167,  1029,   194,  1028,   291,  1075,  1475,   200,   301,   198,
     201,   302,   205,   202,   303,  1038,   304,   206,   686,   306,
     145,   749,   307,   750,   309,   292,   203,    46,   291,   828,
     441,   442,  1113,  1696,   511,   310,   928,  -574,   291,  1798,
     828,  1766,   293,  -571,  1067,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
     291,  1084,   295,  2229,   599,   294,   291,  1901,   291,   597,
     598,   470,  1097,  2065,  2066,   599,   321,   315,  1102,  2067,
     463,   592,   593,   726,   595,   596,   597,   598,   329,   289,
     973,   316,   599,  1209,   828,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,   291,   340,   291,  1041,   599,  2069,  2070,
     828,  1047,   344,  1776,  2067,  1048,   612,  1197,  1232,   341,
    1233,   828,   828,   123,   828,  1785,  1278,   345,  1279,  1280,
     828,   621,   828,   828,  1282,   626,   354,  1323,   828,  1354,
     291,   828,  1436,   828,  1443,  1460,   828,  1468,   828,   828,
     291,   828,  1485,  1602,   451,  1227,   828,   828,  1656,   461,
     464,   465,   828,  2167,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
     355,   305,  1689,  1690,   599,  1782,   828,   828,   291,  1783,
     360,  1805,  1807,  1505,  1893,   828,   828,   361,   828,  1940,
    1958,   291,   498,  1941,  1959,  1984,   362,  1985,  2000,   828,
     291,   828,  1941,   363,  1343,  1346,  2030,   512,   369,  2039,
     784,   291,  2211,  2040,  2056,  2060,  2061,  2091,  1941,   828,
     828,   828,  2112,   370,  2113,  1240,   828,  1505,   828,  2120,
    2128,  2136,  1246,  1941,   828,   828,  1257,  2150,  2187,   736,
     737,  1941,   828,  2194,  2195,  2196,  2197,   828,   828,   828,
     828,   371,  2199,   449,   381,   747,   828,  2201,   449,   449,
     449,  2040,  2222,   749,  1347,   750,  1941,   449,   372,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,   379,  2230,  2240,
    2251,   599,   828,  2241,  1941,  2254,  1210,  1902,  1211,  2255,
     749,   449,   750,   751,   382,   749,  1576,   750,   924,  1326,
    1681,  1327,  1682,   380,   383,   291,   449,  1765,  1862,  1766,
    1863,   414,   425,   426,   432,   459,  1353,   458,   474,   476,
     433,   291,   145,   478,   479,   480,   481,   486,   490,   504,
     546,   549,  -201,  -202,   291,  1873,  1874,   509,  -203,   463,
     557,   558,   561,   564,   565,   869,   566,   550,  1462,  1464,
     577,   428,   609,   618,   610,   617,   619,   612,   625,   883,
     666,   622,   559,   560,   627,   629,   630,   649,   650,   651,
     652,   653,   291,   291,   654,   291,   291,   291,  1409,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   655,
     661,   291,   665,   668,   669,   670,   671,   672,   676,   677,
     165,   384,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,   673,   732,   675,   678,   599,
     681,   682,   688,   689,   697,   698,   715,   699,   710,   711,
     713,   291,   463,   463,   714,   716,   718,   717,   721,   719,
     738,   722,   741,   748,   753,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   755,   291,   756,   144,   394,   395,
     396,   397,   762,   794,   798,   803,   398,   399,   400,   401,
     819,   291,   291,   291,   402,   824,   403,   830,   831,   832,
     863,   873,   599,   874,   875,   895,   896,   893,   922,   932,
     404,   945,   933,   405,   936,   941,   946,   301,   975,   948,
     302,   977,   980,   303,   978,   304,   989,   995,   999,  1002,
    1046,  1031,  1033,  1462,  1464,  1040,    46,  1050,  1051,  1058,
    1781,  1059,  1060,  1071,  1072,   449,  1077,   291,   455,  1087,
    1089,  1106,  1091,   435,   866,   740,   868,  1094,   870,   871,
    1052,  1101,  1103,   291,   291,   291,  1107,  1114,  1115,  1116,
    1118,  1119,   884,   885,   291,  1120,  1769,   769,  1122,   463,
    1771,  1123,  1124,   463,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,  1134,   463,  1138,   463,  1165,  1198,   463,  1166,  1174,
    1175,  1176,  1183,  1192,  1201,  1186,  1202,  1214,  1215,  1206,
    1216,  1222,   291,  1235,  1617,  1224,  1622,  1243,  1244,  1247,
    1269,  1270,  1272,   406,   407,   408,  1286,  1287,   376,  1288,
    1289,  1300,  1301,  1313,   409,  2073,  1316,  1302,   410,  1322,
     411,   117,  1305,  1315,  1325,  1328,  1330,  1329,  1331,  1334,
     463,  1335,  1336,  1340,  1349,   291,  1350,   291,  1371,  1355,
    1356,  1378,  1377,   449,  1379,   449,  1388,   449,   449,   449,
     749,  1380,   750,  1786,   291,  1393,  1385,  1392,  1412,  1416,
    1428,   449,   449,  1446,  -204,  1454,  1472,  1473,  1474,   291,
    1477,  1478,  1479,   291,  1480,  1481,  1482,  1483,  1484,  1486,
    1494,  1497,  1520,  1493,  1498,  1509,  1008,  1499,  1010,  1011,
    1012,  1013,  1014,  1015,  1508,  1017,  1018,  1019,  1020,  1510,
    1511,  1025,  1026,  1027,  1512,  1513,  1514,  1790,  1790,  1777,
    1515,  1516,  1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,
    1533,  1541,  1546,  1547,  1553,  1554,  1556,  1567,  1929,   291,
     291,   291,  1221,  1558,  1562,  1572,  1573,   291,   291,   291,
    1575,  1564,  1578,  1579,   769,  1583,  1585,  1586,  1589,  1587,
    1603,  1609,  1610,  1764,   291,  1628,  1601,  1626,  1607,  1633,
    1639,  1640,  1641,  1635,  1627,   291,  1646,   769,  1647,  1648,
    1720,  1649,  1650,   291,  1651,  1095,  1652,   291,  1653,  1654,
    1655,  1667,  1674,  1678,  1104,  1684,  1688,  1694,  1695,  1701,
    1702,  1703,  1712,  1717,   449,   449,   449,   449,   449,   449,
     449,   449,   449,  1709,   449,   449,   449,   449,  1718,  1710,
     449,   449,   449,  1711,  1819,  1733,  1739,  1740,  1741,  1745,
     769,  1746,  1724,   769,  1732,  1852,  1747,  1725,  1726,  1727,
    1728,  1729,   376,  1735,  1768,   769,  1761,  1751,   470,   470,
    1754,  1320,  1773,  1772,   291,  1778,  1779,  1337,  1792,  1797,
    1799,  1800,  1834,  1802,  1808,  1804,  1809,  1812,  1811,  1815,
    1840,  1820,   463,  1357,  1826,  1074,  1827,  1076,  1828,  1829,
    1831,  1832,   291,  1833,  1838,  1839,  1846,   291,  1841,  1194,
    1853,  1854,  1855,  1857,   449,  1882,  1883,  1878,  1860,  1861,
    1892,  1897,  1915,   449,  1916,  1917,  1925,  1926,  1928,  1830,
    1933,   784,  -572,  1945,  1868,  1946,  1947,  1948,  1952,  1962,
    1961,  1956,  1932,  1963,  1410,  1411,  1967,  1413,  1414,  1415,
    1964,  1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,
    1426,  1965,  1979,  1980,  1966,  1973,  1988,  1983,  1995,  1989,
    1852,  1991,  1992,  1997,  2007,  1998,  2014,  2009,  1906,  2015,
    2024,  2027,  2021,   291,  2022,  1911,  1914,  2026,   291,   291,
    2023,  2029,  2031,  2032,  2028,  2055,  2076,  2081,   455,   455,
    2093,  2096,  2037,  1440,  1923,  2095,  2077,  2092,  2097,  2094,
    2103,   291,  -573,  2106,  2107,  2108,  2117,   291,  2111,  1885,
    1886,  1887,  1888,  1889,  1891,  2115,  2079,  1455,   291,  2124,
    2119,  2127,  2131,  2143,  2144,  2146,  2159,  2121,   463,  2125,
    2164,   463,  2132,  1469,  2169,  2129,  2135,  2212,  2213,  2214,
    2215,  2217,  2218,  2219,  2147,  2154,  2223,  2235,  2239,   291,
    2247,  2252,  2183,  2253,  2200,  2220,  1353,  2256,  2257,  1605,
     376,  2177,   291,   470,  1670,  2234,  1825,   769,  2242,   769,
     769,  2046,  2018,  1856,  1637,   122,   793,   133,  1370,   134,
     135,   935,  2071,   769,  1763,   141,  1096,  1912,  1791,  1518,
    1927,     0,     0,  1383,     0,     0,     0,     0,   470,     0,
       0,     0,   769,     0,     0,  1530,  1531,  1532,     0,     0,
       0,     0,  2145,     0,     0,     0,     0,     0,   291,     0,
       0,   769,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   291,     0,     0,     0,     0,  2019,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2168,  1563,   291,     0,   769,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2050,
       0,   291,     0,     0,     0,     0,  1441,  1442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   449,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1621,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1638,     0,   291,     0,  1642,     0,     0,  2051,     0,
       0,   291,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     291,     0,     0,   291,     0,     0,     0,     0,   455,     0,
       0,     0,     0,     0,   291,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,  2083,  2084,  2085,  2086,
    2087,  1691,  1692,  1693,     0,   449,   449,     0,     0,  1698,
    1699,  1700,     0,   376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1543,   291,     0,  1715,  1545,     0,     0,
       0,     0,     0,     0,     0,     0,  1549,  1723,  1550,  2153,
       0,  1552,     0,     0,     0,  1731,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,     0,     0,
    2122,     0,     0,     0,  2126,     0,     0,   769,     0,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   826,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   749,  1592,   750,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,     0,     0,     0,
       0,     0,     0,     0,     0,  2160,  1796,     0,     0,  2162,
       0,     0,     0,     0,   291,   291,   291,   291,   291,     0,
       0,     0,   449,     0,     0,  2174,   449,     0,     0,     0,
       0,     0,     0,     0,  1818,   449,     0,   449,     0,     0,
     449,  1536,     0,     0,     0,     0,     0,     0,     0,  1557,
       0,     0,     0,     0,     0,     0,     0,     0,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2209,  2210,     0,   291,     0,     0,   165,   384,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   449,     0,     0,     0,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,     0,  1859,     0,     0,   463,   463,
       0,     0,     0,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   463,     0,     0,     0,   394,   395,   396,   397,
       0,     0,     0,  1796,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   403,     0,     0,     0,     0,     0,
    1898,     0,     0,     0,     0,     0,     0,     0,   404,   423,
       0,   405,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,     0,     0,     0,     0,     0,
       0,  1922,     0,     0,    46,     0,   450,     0,     0,     0,
     460,     0,     0,     0,  1931,   466,     0,     0,     0,     0,
       0,   435,     0,   471,   754,     0,  1810,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   483,
     484,   485,     0,   487,   488,   489,     0,   491,   492,   493,
     494,   495,   496,   497,     0,   499,   500,   501,   502,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
    1796,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,   406,   407,   408,     0,   599,     0,  1537,     0,   771,
       0,     0,   409,     0,     0,     0,   410,  1996,   411,   117,
       0,   449,   449,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   449,   567,   569,   571,   572,
     506,  1786,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   606,   506,   506,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2038,     0,  1907,     0,     0,  1909,     0,   624,     0,     0,
       0,     0,     0,     0,     0,  2047,     0,   634,   635,     0,
       0,     0,     0,   635,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,   657,     0,     0,     0,     0,     0,
       0,     0,  1796,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2078,     0,   679,   506,
       0,     0,     0,   683,   684,   685,     0,   687,     0,     0,
       0,   690,   691,   692,     0,     0,   693,     0,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,  1796,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,     0,     0,   449,   725,     0,     0,     0,   506,
     734,     0,     0,     0,     0,     0,  2123,     0,     0,   769,
       0,   769,     0,     0,     0,     0,   742,   743,     0,     0,
       0,     0,     0,     0,     0,     0,   449,     0,  1427,     0,
       0,   770,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,   799,   800,   801,   802,   599,     0,     0,     0,   807,
       0,   449,     0,   811,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   825,   569,     0,
       0,     0,   829,     0,     0,     0,   833,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   859,     0,   864,   865,     0,   867,     0,     0,
    1796,     0,     0,     0,     0,     0,   876,     0,     0,   880,
     881,     0,     0,     0,     0,     0,   859,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   912,   914,   915,
     916,   917,   918,  1796,   920,   921,     0,     0,     0,     0,
       0,     0,   929,   930,   931,     0,     0,     0,     0,     0,
     937,   938,   939,   940,     0,   506,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   567,   725,   959,     0,     0,     0,
     964,   965,   966,   967,   968,   969,   970,   971,   972,     0,
       0,     0,     0,     0,   979,     0,   981,  1519,     0,   983,
       0,     0,     0,   506,   506,   506,   988,     0,   506,   991,
     992,   993,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,  1016,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,  1035,     0,  1036,
       0,     0,   920,   921,     0,     0,     0,     0,     0,     0,
       0,  1049,     0,     0,     0,     0,     0,     0,     0,   769,
       0,     0,     0,     0,   506,     0,  1065,     0,     0,     0,
       0,  1068,  1069,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,     0,  1085,  1086,
       0,  2232,   506,     0,   506,  1093,     0,     0,     0,  1085,
       0,  1100,     0,     0,     0,     0,     0,  1105,     0,     0,
       0,  1108,  2248,  2250,  1561,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   769,  2258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1132,     0,   912,
       0,  1135,     0,     0,     0,     0,     0,     0,   769,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   508,     0,     0,     0,     0,     0,     0,     0,     0,
    1574,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,  1179,  1180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,   449,   449,   599,   506,     0,   507,     0,     0,     0,
       0,     0,     0,     0,     0,   449,     0,   506,     0,     0,
       0,     0,     0,     0,     0,  1220,     0,     0,     0,  1226,
       0,     0,     0,     0,     0,   607,   608,   506,     0,     0,
       0,     0,     0,     0,     0,  1241,  1242,     0,     0,     0,
       0,  1245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1271,     0,
       0,  1273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570,   656,     0,   507,     0,     0,     0,     0,  1713,
       0,     0,     0,  1290,     0,  1292,  1293,     0,     0,     0,
     507,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1311,     0,     0,     0,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,  1333,     0,     0,
     599,     0,     0,     0,  1339,     0,     0,   507,     0,  1348,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1375,  1376,     0,     0,   733,     0,
     506,     0,     0,   507,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  1404,  1405,  1406,  1407,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1770,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,     0,   507,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1430,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1431,  1432,  1433,  1434,  1435,     0,     0,
       0,     0,  1437,  1438,     0,  1439,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1448,
    1449,     0,     0,     0,     0,     0,     0,  1452,  1453,     0,
       0,     0,     0,     0,  1457,     0,  1458,  1459,     0,     0,
       0,     0,     0,  1465,  1466,     0,     0,     0,   506,   506,
     890,     0,   570,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,   850,     0,     0,     0,
       0,     0,  1496,     0,     0,   860,   861,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   942,   943,     0,     0,     0,     0,
     886,     0,     0,     0,     0,   507,     0,     0,  1529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,  1544,     0,
       0,   913,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   985,   986,   987,     0,     0,   990,     0,  1465,
    1466,     0,     0,     0,  1560,     0,     0,     0,     0,   507,
     507,     0,     0,     0,     0,  1566,     0,     0,  1571,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,  1030,
       0,   599,     0,     0,     0,     0,     0,  1593,     0,     0,
    1596,   506,  1599,   506,     0,     0,     0,   507,   507,   507,
       0,  1608,   507,     0,  1611,     0,  1608,  1614,  1616,     0,
       0,  1624,  1625,  1061,     0,     0,     0,     0,     0,     0,
       0,   165,   384,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1083,     0,     0,     0,     0,
       0,  1090,     0,  1092,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,     0,     0,   507,   394,
     395,   396,   397,     0,     0,     0,     0,   398,   399,   400,
     401,     0,  1697,     0,     0,   402,     0,   403,     0,     0,
     507,  1706,  1707,  1708,     0,     0,   507,     0,   507,     0,
    1714,   404,  1716,     0,   405,     0,     0,     0,   301,  1719,
       0,   302,     0,     0,   303,  1168,   304,     0,     0,     0,
       0,     0,     0,   506,     0,  1178,     0,    46,  1736,  1737,
       0,     0,     0,     0,     0,     0,     0,  1742,  1743,  1744,
       0,     0,     0,   913,   435,  1136,     0,     0,     0,  1755,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1767,
       0,     0,     0,  1205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1213,     0,     0,     0,
     507,     0,  1784,     0,     0,     0,     0,     0,  1793,  1794,
     507,     0,     0,     0,     0,     0,  1234,     0,     0,  1774,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,   407,   408,     0,     0,     0,
       0,     0,     0,  1823,     0,   409,     0,     0,   507,   410,
       0,   411,   117,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   442,     0,
       0,   507,     0,     0,  -568,     0,  1591,  1842,  1843,  1844,
       0,     0,     0,     0,     0,     0,     0,     0,  1845,     0,
       0,     0,     0,  1848,  1849,  1850,  1960,   580,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1858,     0,     0,
       0,     0,     0,     0,   506,   506,  1866,     0,  1867,     0,
       0,     0,     0,     0,  1875,  1876,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1382,
       0,     0,     0,   506,     0,     0,     0,     0,  1894,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1905,     0,     0,  1908,     0,     0,     0,  1910,
       0,     0,     0,     0,     0,     0,     0,     0,  1849,  1850,
       0,  1919,     0,     0,     0,     0,     0,     0,     0,  1924,
       0,     0,     0,     0,     0,     0,  1429,     0,     0,     0,
       0,     0,     0,     0,   507,  1937,     0,     0,     0,     0,
    1943,  1944,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1949,     0,     0,  1950,  1949,     0,
    1953,     0,   752,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,   506,   506,     0,     0,
       0,     0,     0,  1981,  1982,     0,     0,  1470,  1471,     0,
       0,     0,     0,     0,     0,  1990,     0,     0,     0,     0,
       0,     0,     0,     0,  1999,     0,     0,     0,     0,     0,
       0,     0,     0,   569,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2010,  2011,     0,     0,   506,     0,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   826,   595,   596,   597,   598,     0,   877,     0,
       0,   599,   507,   507,     0,     0,     0,     0,     0,     0,
       0,  2035,  2036,     0,     0,     0,     0,     0,     0,  1542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2049,     0,     0,     0,     0,   506,   506,  2054,
       0,     0,     0,     0,  2057,     0,     0,  2059,     0,   925,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,  2088,     0,   507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1598,     0,  1600,     0,     0,     0,     0,  2099,     0,     0,
       0,     0,     0,  2104,     0,     0,  2105,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,   749,     0,   750,     0,     0,     0,     0,  2130,  1752,
       0,     0,     0,   170,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   507,     0,   507,     0,     0,
       0,     0,     0,  2148,  2149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2155,  2156,
       0,  2157,   506,     0,     0,     0,     0,     0,     0,     0,
       0,  1780,     0,     0,     0,  2166,     0,     0,     0,     0,
     506,   506,   506,   506,   506,     0,     0,     0,     0,     0,
    1943,     0,     0,     0,  2182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1734,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2203,     0,     0,     0,     0,  2206,  2207,  2208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1895,
     448,   506,     0,     0,     0,     0,     0,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,     0,  1151,
    1152,  1153,  1154,     0,  1156,  1157,  1158,  1159,     0,  2236,
    2237,  2238,     0,     0,     0,     0,     0,   507,     0,     0,
    1171,     0,  1173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1182,     0,     0,     0,     0,     0,     0,  1188,
    1189,     0,     0,     0,     0,     0,     0,     0,  1200,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   540,   541,   542,   543,   544,   545,
       0,   547,   548,     0,     0,     0,     0,     0,     0,     0,
     553,   554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   562,   563,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1824,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1864,  1865,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,  1296,  1298,  1299,     0,     0,     0,  1303,  1304,     0,
       0,  1307,  1308,  1309,  1310,     0,  1312,     0,     0,     0,
       0,  1318,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,   507,
       0,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,   580,   694,   695,   696,   599,     0,   507,   700,   701,
     702,   703,   704,   705,   706,     0,   707,     0,     0,     0,
       0,   708,   709,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   724,     0,
       0,     0,  1403,     0,     0,     0,     0,  1408,     0,     0,
       0,     0,     0,     0,     0,   207,   165,     0,     0,     0,
       0,     0,   208,   209,   210,  1977,  1978,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   421,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,   243,   244,   245,     0,     0,  2012,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     507,   507,     0,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,     0,   253,    25,  1467,   254,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,   570,     0,     0,
     599,     0,   994,     0,     0,     0,  2052,  2053,     0,     0,
     952,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   894,     0,  1896,     0,     0,  2072,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2082,     0,     0,     0,     0,  1987,     0,
       0,     0,     0,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   507,   507,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,  2013,   265,   507,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1580,     0,
       0,     0,     0,   273,   422,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   365,     0,     0,     0,   623,
       0,     0,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1618,  2158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2170,
    2171,  2172,  2173,  2175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1657,  1658,  1659,  1660,  1661,  1662,
    1663,     0,     0,     0,     0,  1668,  1669,     0,     0,     0,
       0,  1671,     0,  1673,     0,     0,     0,  1677,     0,     0,
    1679,     0,     0,     0,     0,     0,   507,     0,     0,     0,
       0,     0,  1687,     0,     0,     0,     0,     0,     0,     0,
    2216,     0,     0,     0,   507,   507,   507,   507,   507,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,  2025,     0,
       0,     0,     0,     0,     0,   507,  1750,     0,  1753,     0,
       0,     0,  1760,     0,  1762,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,  1195,   599,     0,     0,
       0,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,     6,   384,     0,     0,     0,     0,   208,   209,   210,
    1212,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,  2062,     0,     0,  1619,   386,   387,   388,
     389,   390,   391,   392,   393,   242,   243,   244,   245,   394,
     395,   396,   397,   246,   247,     0,     0,   398,   399,   400,
     401,  2110,     0,   248,   249,   402,     0,   403,   250,   251,
     252,     0,     0,     0,     0,     0,     0,  1851,     0,   253,
      25,   404,   254,     0,   405,     0,     0,     0,   255,     0,
       0,   256,     0,     0,   257,     0,   258,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,    56,
      57,     0,   261,     0,   262,     0,     0,   263,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,  1396,
       0,     0,  1934,     0,     0,  1935,     0,     0,     0,     0,
       0,     0,     0,   264,   406,   407,   408,   265,   266,     0,
       0,     0,   267,   268,   269,   409,   270,   271,   272,   410,
       0,   411,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   274,
       0,     0,     0,     0,     0,   275,  1969,  1970,     0,  1972,
     365,     0,     0,     0,  1620,     0,  2063,   278,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,  1456,     0,     0,   599,
       0,     0,     0,     0,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,  2016,  2017,     0,     0,   599,     0,   207,     6,
     384,     0,     0,     0,     0,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,  2048,     0,     0,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   242,   243,   244,   245,   394,   395,   396,
     397,   246,   247,     0,     0,   398,   399,   400,   401,     0,
       0,   248,   249,   402,     0,   403,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,    25,   404,
     254,     0,   405,     0,     0,     0,   255,     0,     0,   256,
       0,     0,   257,     0,   258,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   259,     0,     0,     0,     0,
       0,     0,  1581,  1582,     0,   260,     0,    56,    57,     0,
     261,     0,   262,     0,     0,   263,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,  2142,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,   406,   407,   408,   265,   266,     0,     0,     0,
     267,   268,   269,   409,   270,   271,   272,   410,  1675,   411,
     117,     0,     0,     0,     0,     0,     0,     0,  1683,     0,
       0,     0,     0,     0,     0,     0,   273,   274,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,   207,
     165,   384,   277,   434,     0,   278,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   421,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,  2225,     0,     0,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   242,   243,   244,   245,   394,   395,
     396,   397,   246,     0,     0,     0,   398,   399,   400,   401,
       0,     0,     0,     0,   402,     0,   403,   250,   251,   252,
       0,     0,     0,     0,     0,     0,     0,     0,   253,    25,
     404,   254,     0,   405,     0,     0,     0,   301,     0,     0,
     302,     0,     0,   303,     0,   304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,     0,     0,  1821,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2190,     0,     0,     0,     0,   436,     0,     0,     0,     0,
       0,     0,   264,   406,   407,   408,   265,     0,     0,     0,
       0,   267,   268,   269,   409,   270,   271,   272,   410,     0,
     411,   117,   437,   438,   439,   440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   422,     0,
       0,     0,     0,     0,   275,     0,   441,   442,     0,   443,
       0,   444,   207,     6,   364,   445,   278,     0,     0,   208,
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
       0,     0,     0,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,   265,
     266,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   274,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,   365,   207,     6,     0,   366,     0,   680,   278,
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
     586,   587,   588,   589,   590,   591,   592,   593,   826,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,  1003,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
     265,   266,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   505,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,   207,     6,  1722,     0,   573,     0,
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
       0,     0,     0,     0,     0,  1203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   265,   266,     0,     0,     0,   267,   268,   269,     0,
     270,   271,   272,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   274,     0,     0,     0,     0,     0,   275,
       0,     0,     0,     0,   365,   207,     6,     0,   277,     0,
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
       0,     0,     0,     0,     0,     0,  1204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,   266,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,  1890,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   643,   207,     6,     0,   325,
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
     599,     0,     0,     0,     0,     0,     0,  1535,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,   266,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   274,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   276,   207,     6,     0,
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
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   265,   266,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   274,     0,     0,     0,
       0,     0,   275,     0,     0,     0,     0,   365,   207,     6,
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
       0,     0,     0,     0,     0,   260,     0,    56,    57,   384,
     261,     0,   262,     0,     0,   263,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,   395,   396,   397,
       0,     0,     0,     0,   398,   399,   400,   401,     0,     0,
       0,   264,   402,     0,   403,   265,   266,     0,     0,     0,
     267,   268,   269,     0,   270,   271,   272,     0,   404,     0,
     117,   405,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   505,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,   207,
       6,     0,   568,     0,     0,   278,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   243,   244,   245,     0,     0,
       0,     0,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,     0,     0,     0,   250,   251,   252,
       0,   406,   407,   408,     0,     0,     0,     0,   253,    25,
       0,   254,   409,     0,     0,     0,   410,   255,   411,     0,
     256,     0,     0,   257,     0,   258,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   260,     0,    56,    57,
       0,   261,     0,   262,     0,     0,   263,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  1816,
       0,     0,     0,  1817,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,   265,   266,     0,     0,
       0,   267,   268,   269,     0,   270,   271,   272,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   505,     0,
       0,     0,     0,     0,   275,     0,     0,     0,     0,   365,
     207,     6,     0,     0,   573,     0,   278,   208,   209,   210,
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
    1871,     0,     0,     0,  1872,     0,     0,     0,     0,     0,
       0,     0,     0,   264,     0,     0,     0,   265,   266,     0,
       0,     0,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   274,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     611,   207,     6,     0,   277,     0,     0,   278,   208,   209,
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
       0,  1899,     0,     0,     0,  1900,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   265,   266,
       0,     0,     0,   267,   268,   269,     0,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     274,     0,     0,     0,     0,     0,   275,     0,     0,     0,
       0,   620,   207,     6,     0,   277,     0,     0,   278,   208,
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
       0,     0,  2074,     0,     0,     0,  2075,     0,     0,     0,
       0,     0,     0,     0,     0,   264,     0,     0,     0,   265,
     266,     0,     0,     0,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   505,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,   365,   207,     6,     0,   911,     0,  1381,   278,
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
       0,     0,     0,     0,     0,     0,     0,   782,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
     265,   266,     0,     0,     0,   267,   268,   269,     0,   270,
     271,   272,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   505,     0,     0,     0,     0,     0,   275,   207,
       6,     0,     0,   365,  1597,     0,   208,   209,   210,     0,
     278,   211,   212,   213,   214,   215,   216,   217,   218,   219,
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
       0,     0,     0,   788,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,   265,   266,     0,     0,
       0,   267,   268,   269,     0,   270,   271,   272,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   505,     0,
       0,     0,     0,     0,   275,   207,     6,     0,     0,   365,
       0,     0,   208,   209,   210,     0,   278,   211,   212,   213,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   952,
       0,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,   266,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   274,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   365,   207,     6,     0,  1730,
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
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     953,     0,     0,     0,     0,     0,     0,     0,     0,   264,
       0,     0,     0,   265,   266,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,  1890,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,   643,   207,     6,     0,
     325,     0,     0,   278,   208,   209,   210,     0,     0,   211,
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
       0,  1000,     0,     0,     0,     0,     0,     0,     0,     0,
     264,     0,     0,     0,   265,   266,     0,     0,     0,   267,
     268,   269,     0,   270,   271,   272,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   505,     0,     0,     0,
       0,     0,   275,   207,   165,   384,     0,   365,     0,     0,
     208,   209,   210,     0,   278,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   421,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   242,   243,
     244,   245,   394,   395,   396,   397,   246,     0,     0,     0,
     398,   399,   400,   401,     0,     0,     0,     0,   402,     0,
     403,   250,   251,   252,     0,     0,     0,     0,     0,     0,
       0,     0,   253,    25,   404,   254,     0,   405,   207,   165,
     384,     0,     0,     0,     0,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   421,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,     0,     0,
       0,     0,     0,     0,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   242,   243,   244,   245,   394,   395,   396,
     397,   246,     0,     0,     0,   398,   399,   400,   401,     0,
       0,     0,     0,   402,     0,   403,   250,   251,   252,     0,
       0,     0,     0,     0,     0,     0,     0,   253,    25,   404,
     254,     0,   405,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,   406,   407,   408,
     265,     0,     0,     0,     0,   267,   268,   269,   409,   270,
     271,   272,   410,     0,   411,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   273,   422,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,   365,     0,     0,     0,  1615,     0,     0,
     278,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
       0,   264,   406,   407,   408,   265,     0,     0,     0,     0,
     267,   268,   269,   409,   270,   271,   272,   410,     0,   411,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   422,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,   365,   207,
     165,   384,  1904,     0,     0,   278,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   421,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,  1619,   386,   387,   388,   389,
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
       0,     0,     0,  1786,     0,     0,   278,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,     0,     0,     0,     0,   264,   406,   407,
     408,   265,     0,     0,     0,     0,   267,   268,   269,   409,
     270,   271,   272,   410,     0,   411,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   422,     0,     0,     0,     0,     0,   275,
     207,   165,     0,     0,   365,     0,     0,   208,   209,   210,
       0,   278,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   421,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   243,   244,   245,     0,
       0,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,     0,     0,     0,     0,   207,   165,     0,   253,
      25,   879,   254,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   421,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,   244,   245,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   253,    25,     0,   254,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   264,     0,     0,     0,   265,     0,     0,
       0,  1111,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,   642,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     643,     0,     0,     0,   325,     0,     0,   278,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,   264,
    1112,     0,     0,   265,     0,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   422,     0,     0,     0,     0,
       0,   275,   207,   165,     0,     0,   365,     0,     0,   208,
     209,   210,     0,   278,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   421,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,   207,   165,     0,  1332,     0,
       0,     0,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   421,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     242,   243,   244,   245,     0,     0,     0,     0,   246,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   250,   251,   252,    43,    44,    45,    46,
       0,     0,    48,     0,   253,    25,     0,   254,     0,   763,
      55,     0,     0,    58,   764,     0,   765,   766,     0,   767,
       0,     0,     0,  1043,     0,   264,     0,     0,     0,   265,
       0,     0,     0,     0,   267,   268,   269,    79,   270,   271,
     272,  1044,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   422,    94,    95,    96,     0,     0,   275,     0,     0,
       0,     0,   365,  1098,     0,     0,     0,     0,     0,   278,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1150,     0,     0,     0,     0,     0,   264,     0,
       0,     0,   265,     0,     0,     0,     0,   267,   268,   269,
       0,   270,   271,   272,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   273,   422,     0,     0,     0,     0,     0,
     275,   207,   165,     0,  1495,   365,     0,     0,   208,   209,
     210,     0,   278,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     421,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   243,   244,   245,
       0,     0,     0,     0,   246,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,   250,
     251,   252,     0,     0,     0,     0,     0,     0,     0,     0,
     253,    25,     0,   254,   207,   165,     0,  1559,     0,     0,
       0,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   421,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   242,
     243,   244,   245,     0,     0,     0,     0,   246,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,   250,   251,   252,    43,    44,    45,    46,     0,
       0,    48,     0,   253,    25,     0,   254,     0,   763,    55,
       0,     0,    58,   764,     0,   765,   766,     0,   767,     0,
       0,     0,     0,     0,   264,     0,     0,     0,   265,     0,
       0,     0,     0,   267,   268,   269,    79,   270,   271,   272,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
     422,    94,    95,    96,     0,     0,   275,     0,     0,     0,
       0,   365,     0,     0,     0,     0,     0,     0,   278,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1160,     0,     0,     0,     0,     0,   264,     0,     0,
       0,   265,     0,     0,     0,     0,   267,   268,   269,     0,
     270,   271,   272,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,   422,     0,     0,     0,     0,     0,   275,
     207,   165,     0,     0,   365,     0,     0,   208,   209,   210,
       0,   278,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   421,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   242,   243,   244,   245,     0,
       0,     0,     0,   246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,     0,     0,     0,     0,     0,   207,   165,     0,   253,
      25,     0,   254,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   421,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,   243,   244,   245,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,   251,   252,     0,     0,     0,
       0,     0,     0,     0,     0,   253,    25,     0,   254,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   264,     0,     0,     0,   265,     0,     0,
       0,  1161,   267,   268,   269,     0,   270,   271,   272,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   422,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
     365,  1613,     0,     0,     0,     0,     0,   278,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,   264,
    1162,     0,     0,   265,     0,     0,     0,     0,   267,   268,
     269,     0,   270,   271,   272,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   273,   422,     0,     0,     0,     0,
       0,   275,   207,   165,     0,     0,   365,  1951,     0,   208,
     209,   210,     0,   278,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   421,   229,   230,   231,   232,   233,   234,   235,   236,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   243,   244,
     245,     0,     0,     0,     0,   246,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   253,    25,     0,   254,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1163,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,   763,    55,     0,
       0,    58,   764,     0,   765,   766,     0,   767,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,   264,     0,     0,   599,   265,
      94,    95,    96,   727,   267,   268,   269,     0,   270,   271,
     272,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
     273,   422,     0,     0,     0,     0,     0,   275,     0,     0,
       0,     0,   365,     0,     0,     0,     0,     0,     0,   278,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,   960,     0,     0,     0,   763,
      55,     0,     0,    58,   764,     0,   765,   766,     0,   767,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    79,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,    94,    95,    96,     0,     0,   763,    55,     0,
       0,    58,   764,     0,   765,   766,     0,   767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    79,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
      94,    95,    96,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,   984,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,   763,    55,     0,     0,    58,   764,     0,   765,
     766,     0,   767,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
      79,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,  1032,     0,    43,    44,    45,
      46,     0,     0,    48,     0,    94,    95,    96,     0,     0,
     763,    55,     0,     0,    58,   764,     0,   765,   766,     0,
     767,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
    1034,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,   763,    55,     0,     0,    58,
     764,     0,   765,   766,     0,   767,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,    79,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,  1236,     0,
      43,    44,    45,    46,     0,     0,    48,     0,    94,    95,
      96,     0,     0,   763,    55,     0,     0,    58,   764,     0,
     765,   766,     0,   767,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,  1238,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   763,    55,
       0,     0,    58,   764,     0,   765,   766,     0,   767,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,    79,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,  1239,     0,    43,    44,    45,    46,     0,     0,    48,
       0,    94,    95,    96,     0,     0,   763,    55,     0,     0,
      58,   764,     0,   765,   766,     0,   767,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,  1258,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,   763,    55,     0,     0,    58,   764,     0,   765,   766,
       0,   767,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,    79,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,  1276,     0,    43,    44,    45,    46,
       0,     0,    48,     0,    94,    95,    96,     0,     0,   763,
      55,     0,     0,    58,   764,     0,   765,   766,     0,   767,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,  1291,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   763,    55,     0,     0,    58,   764,
       0,   765,   766,     0,   767,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,    79,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,  1324,     0,    43,
      44,    45,    46,     0,     0,    48,     0,    94,    95,    96,
       0,     0,   763,    55,     0,     0,    58,   764,     0,   765,
     766,     0,   767,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,  1487,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,   763,    55,     0,
       0,    58,   764,     0,   765,   766,     0,   767,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,     0,     0,     0,    -4,    -4,    -4,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,    -4,    -4,    -4,
       0,   599,     0,     0,    -4,    -4,     0,     0,     0,    -4,
       0,  1164,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,  2192,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     0,     0,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     6,     0,     0,     0,
       0,     0,    -4,    -4,    -4,     7,     8,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,     0,     0,     0,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     9,    10,
      11,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1169,     0,     0,     0,     0,     0,     0,     0,    12,
      13,    14,     0,     0,     0,     0,    15,    16,     0,     0,
       0,    17,     0,     0,     0,     0,    18,    19,    20,    21,
      22,     0,    23,    24,     0,    25,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,    42,    43,
      44,    45,    46,    47,     0,    48,     0,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,    64,    65,    66,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,    89,    90,    91,     0,     0,     0,    92,
       0,     0,     0,     0,    93,    94,    95,    96,   165,   384,
      97,     0,    98,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,   116,     0,   117,     0,     0,
       0,     0,     0,   385,   386,   387,   388,   389,   390,   391,
     392,   393,     0,     0,     0,     0,   394,   395,   396,   397,
     415,   384,     0,     0,   398,   399,   400,   401,     0,     0,
       0,     0,   402,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,     0,
       0,   405,     0,     0,     0,   301,     0,     0,   302,     0,
       0,   303,     0,   304,     0,   385,   386,   387,   388,   389,
     390,   391,   392,   393,    46,     0,     0,     0,   394,   395,
     396,   397,     0,     0,     0,     0,   398,   399,   400,   401,
       0,   435,     0,     0,   402,     0,   403,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     404,     0,     0,   405,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   406,   407,   408,     0,     0,     0,     0,     0,     0,
       0,     0,   409,     0,     0,     0,   410,     0,   411,   117,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   406,   407,   408,     0,     0,     0,     0,
       0,     0,     0,     0,   409,     0,     0,     0,   410,     0,
     411,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1285,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1306,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1391,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1394,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1489,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1490,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1534,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1664,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1665,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1666,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1680,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1814,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1938,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1939,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1971,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1974,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2043,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2100,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2101,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2116,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2118,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2151,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2179,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2184,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2185,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2186,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2226,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
     823,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  1078,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  1137,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  1184,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1185,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1229,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1261,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  1281,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  1338,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  1358,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    1444,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  1445,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  1491,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  1565,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  1869,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  1880,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  1918,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  1993,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  2008,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  2020,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    2044,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,     0,  2080,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,     0,     0,  2089,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,     0,  2090,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,     0,     0,  2114,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,     0,     0,  2165,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,     0,     0,  2205,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,     0,     0,  2224,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
       0,     0,  2244,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,     0,
       0,  2245,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,     0,     0,
    2246,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,     0,   944,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,     0,  1986,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,   749,     0,   750,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
    1006,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,  1054,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,  1208,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,  1275,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,  1277,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,     0,     0,  1283,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   726,
     595,   596,   597,   598,     0,     0,     0,     0,   599,     0,
       0,     0,  1284,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   726,   595,   596,   597,
     598,     0,     0,     0,     0,   599,     0,     0,     0,  1373,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   726,   595,   596,   597,   598,     0,     0,
       0,     0,   599,     0,     0,     0,  1387,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     726,   595,   596,   597,   598,     0,     0,     0,     0,   599,
       0,     0,     0,  1594,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,     0,     0,
    1686,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   726,   595,   596,   597,   598,     0,
       0,     0,     0,   599,     0,     0,     0,  1738,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   726,   595,   596,   597,   598,     0,     0,     0,     0,
     599,     0,     0,     0,  1930,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   726,   595,
     596,   597,   598,     0,     0,     0,     0,   599,     0,     0,
       0,  1976,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   726,   595,   596,   597,   598,
       0,     0,     0,     0,   599,     0,     0,     0,  1994,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   804,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   805,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   806,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   808,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   809,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   810,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   812,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   813,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   814,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   815,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   816,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   817,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   818,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   820,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   821,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   822,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   891,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   926,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   974,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   994,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   996,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,   997,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,   998,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1004,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1005,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1042,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1053,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1117,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1121,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1133,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1207,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1217,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1218,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1219,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1228,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1230,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1231,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1260,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1262,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1263,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1264,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1265,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1266,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1267,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1268,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1274,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1372,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1386,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1595,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1629,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1630,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1631,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1632,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1672,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1685,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1801,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1803,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1806,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1813,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1870,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1879,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  1903,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  1975,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  2041,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  2042,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   726,   595,   596,
     597,   598,     0,     0,     0,     0,   599,     0,  2178,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   726,   595,   596,   597,   598,     0,     0,     0,
       0,   599,     0,  2221
};

static const yytype_int16 yycheck[] =
{
       3,  1255,     3,   318,   638,   639,  1451,  1724,  1259,   744,
    1769,    62,  1771,     4,     4,     4,     4,   752,  1756,     4,
       6,   731,    25,   157,   143,    25,     6,   196,     4,     6,
       4,     4,     4,     4,  1954,   204,     6,     5,     9,     6,
       5,     5,     4,     6,     4,   141,     6,   108,   162,   110,
     760,    54,     5,     7,     4,     6,   254,     4,   107,     4,
       4,   107,     4,   254,   262,     4,     9,   777,   330,   101,
       4,   262,    68,    69,   188,    71,   253,   787,   255,     7,
      83,   130,   143,  1821,   130,   262,     9,   349,   120,    92,
     204,   205,    36,    37,    97,   191,     6,   241,   242,   141,
     241,   242,     9,   254,    93,   108,   253,     9,   259,   170,
     257,   250,   251,     7,     9,   241,   242,   159,   262,     6,
     259,   262,   250,   251,  1841,     9,   168,   169,   170,   298,
     299,   300,   174,   175,   259,   141,   262,   262,   241,   242,
     143,   101,   254,   144,   256,   148,   149,   150,   110,   111,
     262,     0,     6,   159,   157,     7,   418,   254,   420,   262,
       7,     6,   168,   169,   170,   262,   428,   101,   174,   175,
      14,   105,   175,   342,   343,   344,   101,   111,   112,   104,
     114,   115,   107,   893,   109,   253,     7,   255,   191,  2109,
     359,     7,   107,   196,   241,   242,   199,   248,   249,     7,
     134,   204,   205,   206,   254,   178,   179,   180,   181,   176,
     199,   104,   262,   176,   107,   262,   258,   190,   254,   192,
     193,   194,   195,   196,   241,   242,   262,   200,   201,   253,
     203,   203,  1677,   256,   225,   225,   225,   241,   242,   262,
     225,   188,   189,   188,   189,   262,   257,   241,   242,   225,
     261,   225,   258,  1507,   225,   241,   242,   260,   262,   236,
     237,     6,     7,   254,   258,   256,  1983,   255,   257,   257,
     260,   274,   257,   261,   277,   278,     6,   257,   278,   250,
     251,   257,   253,   253,   255,   258,   257,   257,   259,   257,
     293,   294,   257,   257,   297,   298,   299,   300,   226,   227,
     228,   229,   257,   253,   257,   259,   257,   250,   251,   312,
     253,   253,   255,   316,   253,   318,   259,   253,  1053,  1054,
    2037,   254,   250,   251,   253,   321,   322,   250,   251,   262,
     253,   259,   255,   329,   330,     6,   259,   340,     6,   342,
     343,   344,   254,   250,   251,     8,   253,     6,   255,   256,
     262,   253,   259,   255,   241,   242,   359,   259,   253,   253,
     255,   255,   254,   366,   259,   627,   256,   629,   630,   253,
     262,   255,   262,   434,   226,   227,   228,   229,   253,   226,
     227,   228,   229,   107,   646,   109,  2145,   241,   242,   254,
     559,   236,   237,   241,   242,   241,   242,   262,   250,   251,
       6,     7,   664,   250,   251,   226,   227,   228,   229,     6,
     226,   227,   228,   229,   262,   549,   262,     6,   226,   227,
     228,   229,   425,   426,   141,     6,   688,   430,   431,   250,
     251,   104,   241,   242,   107,   108,   109,   241,   242,     4,
       5,   141,   159,   446,   253,   241,   242,   120,   257,   255,
     453,   168,   169,   170,     6,   255,     4,   174,   175,   159,
     104,   241,   242,   107,  2181,   727,   262,   253,   168,   169,
     170,   250,   251,   476,   174,   175,   120,   253,   257,   241,
     242,  1191,   262,  1193,    49,    50,    51,    52,    53,    54,
      55,    56,    57,   241,   242,   257,  1206,    62,    63,    64,
      65,   254,   505,   256,   565,    70,    71,    72,    73,   262,
     183,   253,   253,    78,   262,    80,   257,  2234,   241,   242,
     253,   243,   244,   245,   246,   247,   529,  1972,   253,    94,
     252,   257,    97,   241,   242,   538,   539,   241,   242,   262,
     543,   258,   545,   546,   547,   548,   549,   104,   253,   253,
     107,   554,   109,   257,   262,   558,   559,   560,   561,   562,
     563,   564,   696,   566,   564,   568,   566,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   241,   242,   241,   242,   252,
     122,   594,   253,    54,   255,   258,   257,   600,   146,   147,
     148,   149,   241,   242,   152,   253,   262,   255,   262,  1319,
     241,   242,   253,   161,   255,  1325,   164,   253,   259,   622,
     623,   262,   254,   262,   256,   744,   241,   242,   241,   242,
     262,   262,   258,   241,   242,  1269,   262,   638,   639,   253,
     636,   637,   207,   208,   209,   641,   253,   262,   709,   262,
     241,   242,   253,   218,   262,   253,   141,   222,   253,   224,
     225,  1371,   241,   242,   241,   242,   258,   670,   671,   672,
     262,   262,   675,   258,   159,  1385,   107,   262,   257,   254,
     257,   256,  1392,   168,   169,   170,   948,   262,   257,   174,
     175,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     253,   704,   705,   706,   707,   708,   253,   710,   711,   712,
     713,   714,   253,   713,   717,   766,   141,   101,   101,     6,
     104,   104,   109,   107,   107,   728,   109,   253,   259,   104,
     261,   254,   107,   256,   109,   253,   120,   120,   741,   262,
     250,   251,   803,  1478,   205,   120,   258,   257,   751,   253,
     262,   255,   257,   257,   757,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     773,   774,   107,   258,   252,   257,   779,     8,   781,   246,
     247,   784,   785,   146,   147,   252,   257,   253,   791,   152,
     793,   241,   242,   243,   244,   245,   246,   247,   257,   260,
     258,   104,   252,   922,   262,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   826,   257,   828,   258,   252,   146,   147,
     262,   258,   107,  1568,   152,   262,   297,   258,   258,   253,
     258,   262,   262,     3,   262,  1580,   258,   104,   258,   258,
     262,   312,   262,   262,   258,   316,   104,   258,   262,   258,
     863,   262,   258,   262,   258,   258,   262,   258,   262,   262,
     873,   262,   258,   258,   143,   936,   262,   262,   258,   148,
     149,   150,   262,  2134,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     107,    61,   258,   258,   252,   258,   262,   262,   911,   262,
     107,   258,   258,  2167,   258,   262,   262,     4,   262,   258,
     258,   924,   191,   262,   262,   258,     4,   258,   258,   262,
     933,   262,   262,     4,  1053,  1054,   258,   206,     4,   258,
     262,   944,  2193,   262,   258,   258,   258,   258,   262,   262,
     262,   262,   258,   253,   258,   951,   262,  2211,   262,   258,
     258,   258,   958,   262,   262,   262,   962,   258,   258,   430,
     431,   262,   262,   258,   258,   258,   258,   262,   262,   262,
     262,   253,   258,   143,     6,   446,   262,   258,   148,   149,
     150,   262,   258,   254,  1055,   256,   262,   157,   253,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   253,   258,   258,
     258,   252,   262,   262,   262,   258,   253,   258,   255,   262,
     254,   191,   256,   257,     6,   254,  1351,   256,   257,   253,
     253,   255,   255,   253,   255,  1048,   206,   253,     4,   255,
       6,   253,   255,   257,     6,     6,  1059,   257,   253,     9,
     261,  1064,   261,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   191,   191,  1077,  1709,  1710,   257,   191,  1082,
     257,   130,   253,   253,   253,   546,   253,   247,  1207,  1208,
     191,   257,   253,   257,   253,   253,   253,   558,     4,   560,
     255,   257,   262,   263,   257,   257,   257,   253,   253,   253,
     253,   253,  1115,  1116,   253,  1118,  1119,  1120,  1114,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,   253,
     253,  1134,     6,     6,     6,   257,   257,   257,   255,   255,
       4,     5,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   257,   425,   257,   255,   252,
       6,     6,   257,   191,   253,   253,     6,   253,   253,   253,
     253,  1174,  1175,  1176,   255,     6,     6,   257,     6,     8,
     257,     8,     7,     6,   257,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   257,  1198,     6,   257,    62,    63,
      64,    65,   258,    96,   262,   262,    70,    71,    72,    73,
     254,  1214,  1215,  1216,    78,     7,    80,     6,     6,   254,
     257,   257,   252,   257,   257,    67,     8,   259,     4,     7,
      94,   254,     7,    97,   253,     6,     6,   101,     7,   257,
     104,     6,     6,   107,     7,   109,     6,   258,   188,   257,
     254,   258,   258,  1372,  1373,   256,   120,     6,   257,   259,
    1575,     7,     6,   255,   253,   425,   257,  1270,  1269,     4,
       6,   254,     6,   137,   543,   435,   545,     6,   547,   548,
     741,     6,     6,  1286,  1287,  1288,   255,     7,     7,     7,
       7,     7,   561,   562,  1297,     7,  1558,   457,     7,  1302,
    1562,     7,     7,  1306,     7,     7,     7,     7,     7,     7,
       7,   257,  1315,     6,  1317,   254,     7,  1320,   256,   262,
     262,   262,   258,   254,   257,   262,   258,     7,   257,   259,
     257,     4,  1335,   259,  1395,     6,  1397,   258,   258,   141,
     257,     7,     6,   207,   208,   209,     7,     7,  1351,     7,
     259,   254,   254,     9,   218,  1989,   254,   262,   222,   256,
     224,   225,   262,   262,   259,   261,     7,   191,   162,   258,
    1373,   257,     6,     6,     6,  1378,     4,  1380,   259,    49,
      49,   257,   253,   543,   253,   545,   253,   547,   548,   549,
     254,   257,   256,   257,  1397,   253,   259,   259,     7,     7,
       7,   561,   562,   262,   191,   254,     7,     7,     7,  1412,
       6,   254,   262,  1416,     7,     7,     7,     7,     7,     4,
       4,   257,   257,   119,     6,     6,   695,   253,   697,   698,
     699,   700,   701,   702,     7,   704,   705,   706,   707,     7,
       7,   710,   711,   712,     7,     7,     7,  1581,  1582,  1568,
       7,     7,     6,     6,     6,   107,     7,     7,     6,     6,
       4,     4,   260,   262,   254,   262,   257,     6,  1783,  1472,
    1473,  1474,   933,   257,   257,     6,     6,  1480,  1481,  1482,
       7,   258,     6,   255,   644,     6,   253,   253,     6,   257,
       6,     6,     6,  1554,  1497,     6,   258,   256,   259,     6,
       6,     6,     6,   134,   262,  1508,     6,   667,     6,     6,
    1506,     6,     6,  1516,     6,   784,     6,  1520,     6,     6,
       5,   254,   254,     6,   793,     4,     6,     4,     6,   257,
     257,     7,   255,     6,   694,   695,   696,   697,   698,   699,
     700,   701,   702,   257,   704,   705,   706,   707,     6,   257,
     710,   711,   712,   257,  1615,     6,     6,     6,   187,     6,
     720,     6,   257,   723,   258,  1684,     6,   257,   257,   257,
     257,   257,  1575,   257,   257,   735,   254,   262,  1581,  1582,
     262,   262,     6,   262,  1587,   259,     7,  1048,   253,   257,
       4,     6,   141,     6,     6,   258,     6,     4,   253,   253,
       5,     7,  1605,  1064,     6,   765,     6,   767,     6,     6,
       6,     6,  1615,     6,   105,     6,   254,  1620,   257,   262,
     257,   257,     6,     6,   784,     6,     6,   262,   141,   141,
       6,     6,   262,   793,   254,   262,     6,     4,     6,  1635,
       6,   262,   257,     6,  1705,     6,     6,     6,     6,   145,
       7,   257,  1786,     6,  1115,  1116,     5,  1118,  1119,  1120,
     257,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
    1131,   257,     6,     6,   257,   254,     6,   257,     6,   257,
    1799,   258,   258,     7,     6,   257,     6,   186,  1749,   254,
       6,     6,   258,  1696,   258,  1756,  1757,     7,  1701,  1702,
     258,     6,     6,     6,   259,     6,     6,     6,  1709,  1710,
       6,  2026,   257,  1174,  1775,     6,   258,   254,   189,   257,
       6,  1724,   257,     6,   258,   258,   254,  1730,   253,  1725,
    1726,  1727,  1728,  1729,  1730,   257,  1998,  1198,  1741,     6,
     257,     6,     6,     6,     6,     6,     6,   257,  1751,   257,
       6,  1754,   141,  1214,     6,   258,   257,     6,     6,     6,
       6,     6,     6,     6,   257,   254,     6,     6,     6,  1772,
       6,     6,   258,     6,   258,   257,  1779,     6,     6,  1384,
    1783,  2147,  1785,  1786,  1446,   257,  1627,   947,   257,   949,
     950,  1955,  1915,  1692,  1411,     3,   473,     3,  1066,     3,
       3,   615,  1985,   963,  1551,     3,   784,  1756,  1582,  1270,
    1779,    -1,    -1,  1082,    -1,    -1,    -1,    -1,  1821,    -1,
      -1,    -1,   982,    -1,    -1,  1286,  1287,  1288,    -1,    -1,
      -1,    -1,  2094,    -1,    -1,    -1,    -1,    -1,  1841,    -1,
      -1,  1001,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,  1854,    -1,    -1,    -1,    -1,  1917,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2135,  1335,  1878,    -1,  1037,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1890,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1960,
      -1,  1904,    -1,    -1,    -1,    -1,  1175,  1176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1082,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1397,    -1,  1941,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1412,    -1,  1956,    -1,  1416,    -1,    -1,  1961,    -1,
      -1,  1964,  1965,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1983,    -1,    -1,  1986,    -1,    -1,    -1,    -1,  1989,    -1,
      -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2002,  2003,  2004,  2005,
    2006,  1472,  1473,  1474,    -1,  1175,  1176,    -1,    -1,  1480,
    1481,  1482,    -1,  2026,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1302,  2037,    -1,  1497,  1306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1315,  1508,  1317,  2110,
      -1,  1320,    -1,    -1,    -1,  1516,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2067,    -1,    -1,    -1,    -1,    -1,
    2066,    -1,    -1,    -1,  2070,    -1,    -1,  1237,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   254,  1373,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2121,  1587,    -1,    -1,  2125,
      -1,    -1,    -1,    -1,  2137,  2138,  2139,  2140,  2141,    -1,
      -1,    -1,  1302,    -1,    -1,  2141,  1306,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1615,  1315,    -1,  1317,    -1,    -1,
    1320,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1329,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2188,  2189,    -1,  2198,    -1,    -1,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1373,    -1,    -1,    -1,  2220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2234,    -1,    -1,    -1,  1696,    -1,    -1,  2241,  2242,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,  2255,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,  1724,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
    1741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,   116,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1772,    -1,    -1,   120,    -1,   143,    -1,    -1,    -1,
     147,    -1,    -1,    -1,  1785,   152,    -1,    -1,    -1,    -1,
      -1,   137,    -1,   160,     6,    -1,  1605,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
     177,   178,    -1,   180,   181,   182,    -1,   184,   185,   186,
     187,   188,   189,   190,    -1,   192,   193,   194,   195,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1841,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   207,   208,   209,    -1,   252,    -1,   254,    -1,     6,
      -1,    -1,   218,    -1,    -1,    -1,   222,  1878,   224,   225,
      -1,  1581,  1582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1605,   273,   274,   275,   276,
     277,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   292,   293,   294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1941,    -1,  1751,    -1,    -1,  1754,    -1,   314,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1956,    -1,   324,   325,    -1,
      -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   340,   341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1997,    -1,   365,   366,
      -1,    -1,    -1,   370,   371,   372,    -1,   374,    -1,    -1,
      -1,   378,   379,   380,    -1,    -1,   383,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,  2037,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1751,    -1,    -1,  1754,   422,    -1,    -1,    -1,   426,
     427,    -1,    -1,    -1,    -1,    -1,  2067,    -1,    -1,  1769,
      -1,  1771,    -1,    -1,    -1,    -1,   443,   444,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,     6,    -1,
      -1,   458,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   478,   479,   480,   481,   252,    -1,    -1,    -1,   486,
      -1,  1821,    -1,   490,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   504,   505,    -1,
      -1,    -1,   509,    -1,    -1,    -1,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,    -1,   541,   542,    -1,   544,    -1,    -1,
    2181,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,   556,
     557,    -1,    -1,    -1,    -1,    -1,   563,    -1,    -1,    -1,
      -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,  2234,   601,   602,    -1,    -1,    -1,    -1,
      -1,    -1,   609,   610,   611,    -1,    -1,    -1,    -1,    -1,
     617,   618,   619,   620,    -1,   622,   623,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   641,   642,   643,    -1,    -1,    -1,
     647,   648,   649,   650,   651,   652,   653,   654,   655,    -1,
      -1,    -1,    -1,    -1,   661,    -1,   663,     6,    -1,   666,
      -1,    -1,    -1,   670,   671,   672,   673,    -1,   675,   676,
     677,   678,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,   703,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     717,    -1,    -1,    -1,    -1,    -1,    -1,   724,    -1,   726,
      -1,    -1,   729,   730,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2079,
      -1,    -1,    -1,    -1,   751,    -1,   753,    -1,    -1,    -1,
      -1,   758,   759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,   775,   776,
      -1,  2220,   779,    -1,   781,   782,    -1,    -1,    -1,   786,
      -1,   788,    -1,    -1,    -1,    -1,    -1,   794,    -1,    -1,
      -1,   798,  2241,  2242,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2145,  2255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   824,    -1,   826,
      -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,  2168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,   863,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   873,   874,   875,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2220,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,  2241,  2242,   252,   911,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2255,    -1,   924,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   932,    -1,    -1,    -1,   936,
      -1,    -1,    -1,    -1,    -1,   293,   294,   944,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   952,   953,    -1,    -1,    -1,
      -1,   958,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,    -1,
      -1,   978,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   274,   340,    -1,   277,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,  1000,    -1,  1002,  1003,    -1,    -1,    -1,
     293,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1021,    -1,    -1,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,  1044,    -1,    -1,
     252,    -1,    -1,    -1,  1051,    -1,    -1,   340,    -1,  1056,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1071,  1072,    -1,    -1,   426,    -1,
    1077,    -1,    -1,   366,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,  1109,  1110,  1111,  1112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1134,    -1,    -1,
      -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1150,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1160,  1161,  1162,  1163,  1164,    -1,    -1,
      -1,    -1,  1169,  1170,    -1,  1172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1186,
    1187,    -1,    -1,    -1,    -1,    -1,    -1,  1194,  1195,    -1,
      -1,    -1,    -1,    -1,  1201,    -1,  1203,  1204,    -1,    -1,
      -1,    -1,    -1,  1210,  1211,    -1,    -1,    -1,  1215,  1216,
     568,    -1,   505,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,   529,    -1,    -1,    -1,
      -1,    -1,  1249,    -1,    -1,   538,   539,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,   623,    -1,    -1,    -1,    -1,
     563,    -1,    -1,    -1,    -1,   568,    -1,    -1,  1285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1305,    -1,
      -1,   594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   670,   671,   672,    -1,    -1,   675,    -1,  1326,
    1327,    -1,    -1,    -1,  1331,    -1,    -1,    -1,    -1,   622,
     623,    -1,    -1,    -1,    -1,  1342,    -1,    -1,  1345,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,   717,
      -1,   252,    -1,    -1,    -1,    -1,    -1,  1374,    -1,    -1,
    1377,  1378,  1379,  1380,    -1,    -1,    -1,   670,   671,   672,
      -1,  1388,   675,    -1,  1391,    -1,  1393,  1394,  1395,    -1,
      -1,  1398,  1399,   751,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   773,    -1,    -1,    -1,    -1,
      -1,   779,    -1,   781,   717,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,   751,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,  1479,    -1,    -1,    78,    -1,    80,    -1,    -1,
     773,  1488,  1489,  1490,    -1,    -1,   779,    -1,   781,    -1,
    1497,    94,  1499,    -1,    97,    -1,    -1,    -1,   101,  1506,
      -1,   104,    -1,    -1,   107,   863,   109,    -1,    -1,    -1,
      -1,    -1,    -1,  1520,    -1,   873,    -1,   120,  1525,  1526,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1534,  1535,  1536,
      -1,    -1,    -1,   826,   137,   828,    -1,    -1,    -1,  1546,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1556,
      -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   924,    -1,    -1,    -1,
     863,    -1,  1579,    -1,    -1,    -1,    -1,    -1,  1585,  1586,
     873,    -1,    -1,    -1,    -1,    -1,   944,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,    -1,    -1,  1620,    -1,   218,    -1,    -1,   911,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   924,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,   251,    -1,
      -1,   944,    -1,    -1,   257,    -1,   259,  1664,  1665,  1666,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1675,    -1,
      -1,    -1,    -1,  1680,  1681,  1682,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1694,    -1,    -1,
      -1,    -1,    -1,    -1,  1701,  1702,  1703,    -1,  1705,    -1,
      -1,    -1,    -1,    -1,  1711,  1712,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1077,
      -1,    -1,    -1,  1730,    -1,    -1,    -1,    -1,  1735,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1749,    -1,    -1,  1752,    -1,    -1,    -1,  1756,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1765,  1766,
      -1,  1768,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1776,
      -1,    -1,    -1,    -1,    -1,    -1,  1134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1077,  1792,    -1,    -1,    -1,    -1,
    1797,  1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1811,    -1,    -1,  1814,  1815,    -1,
    1817,    -1,   448,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,  1134,    -1,    -1,    -1,    -1,  1853,  1854,    -1,    -1,
      -1,    -1,    -1,  1860,  1861,    -1,    -1,  1215,  1216,    -1,
      -1,    -1,    -1,    -1,    -1,  1872,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1881,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1890,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1900,  1901,    -1,    -1,  1904,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,   554,    -1,
      -1,   252,  1215,  1216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1938,  1939,    -1,    -1,    -1,    -1,    -1,    -1,  1297,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1959,    -1,    -1,    -1,    -1,  1964,  1965,  1966,
      -1,    -1,    -1,    -1,  1971,    -1,    -1,  1974,    -1,   605,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2001,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2009,    -1,  1297,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1378,    -1,  1380,    -1,    -1,    -1,    -1,  2034,    -1,    -1,
      -1,    -1,    -1,  2040,    -1,    -1,  2043,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,   254,    -1,   256,    -1,    -1,    -1,    -1,  2075,   262,
      -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1378,    -1,  1380,    -1,    -1,
      -1,    -1,    -1,  2100,  2101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2115,  2116,
      -1,  2118,  2119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,  2132,    -1,    -1,    -1,    -1,
    2137,  2138,  2139,  2140,  2141,    -1,    -1,    -1,    -1,    -1,
    2147,    -1,    -1,    -1,  2151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2179,    -1,    -1,    -1,    -1,  2184,  2185,  2186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
     143,  2198,    -1,    -1,    -1,    -1,    -1,   833,   834,   835,
     836,   837,   838,   839,   840,   841,   842,   843,    -1,   845,
     846,   847,   848,    -1,   850,   851,   852,   853,    -1,  2226,
    2227,  2228,    -1,    -1,    -1,    -1,    -1,  1520,    -1,    -1,
     866,    -1,   868,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   878,    -1,    -1,    -1,    -1,    -1,    -1,   885,
     886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   894,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,   244,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,   266,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1620,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1701,  1702,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,  1007,  1008,  1009,    -1,    -1,    -1,  1013,  1014,    -1,
      -1,  1017,  1018,  1019,  1020,    -1,  1022,    -1,    -1,    -1,
      -1,  1027,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1701,  1702,
      -1,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     8,   385,   386,   387,   252,    -1,  1730,   391,   392,
     393,   394,   395,   396,   397,    -1,   399,    -1,    -1,    -1,
      -1,   404,   405,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,    -1,
      -1,    -1,  1108,    -1,    -1,    -1,    -1,  1113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,  1853,  1854,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,  1904,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1853,  1854,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,  1212,    95,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,  1890,    -1,    -1,
     252,    -1,   254,    -1,    -1,    -1,  1964,  1965,    -1,    -1,
     262,  1904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   576,    -1,     6,    -1,    -1,  1986,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2001,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,  1964,  1965,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,     6,   210,  1986,    -1,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,    -1,    -1,    -1,   225,  2001,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1354,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1396,  2119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2137,
    2138,  2139,  2140,  2141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,    -1,    -1,    -1,    -1,  1441,  1442,    -1,    -1,    -1,
      -1,  1447,    -1,  1449,    -1,    -1,    -1,  1453,    -1,    -1,
    1456,    -1,    -1,    -1,    -1,    -1,  2119,    -1,    -1,    -1,
      -1,    -1,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2198,    -1,    -1,    -1,  2137,  2138,  2139,  2140,  2141,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,  2198,  1542,    -1,  1544,    -1,
      -1,    -1,  1548,    -1,  1550,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,   889,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1581,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
     923,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     6,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    -1,    70,    71,    72,
      73,     7,    -1,    76,    77,    78,    -1,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,  1683,    -1,    92,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,
     133,    -1,   135,    -1,   137,    -1,    -1,   140,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,
      -1,   164,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,  1102,
      -1,    -1,  1788,    -1,    -1,  1791,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,  1842,  1843,    -1,  1845,
     253,    -1,    -1,    -1,   257,    -1,     6,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,    -1,  1199,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,  1908,  1909,    -1,    -1,   252,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,  1957,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    76,    77,    78,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,  1355,  1356,    -1,   130,    -1,   132,   133,    -1,
     135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,   152,   153,   154,
     155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     6,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,  1451,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1461,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,     3,
       4,     5,   257,     7,    -1,   260,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,  2207,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,  1619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,    -1,
     224,   225,   226,   227,   228,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,   248,    -1,   250,   251,    -1,   253,
      -1,   255,     3,     4,     5,   259,   260,    -1,    -1,    10,
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
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,
     211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,     3,     4,    -1,   257,    -1,     8,   260,
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
      -1,    -1,    -1,   253,     3,     4,     5,    -1,   258,    -1,
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
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,   210,   211,    -1,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,   253,     3,     4,    -1,   257,
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
     252,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,     5,
     135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,    -1,   152,   153,   154,
     155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,   206,    78,    -1,    80,   210,   211,    -1,    -1,    -1,
     215,   216,   217,    -1,   219,   220,   221,    -1,    94,    -1,
     225,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,   218,    -1,    -1,    -1,   222,   101,   224,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,   133,
      -1,   135,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,    -1,   152,   153,
     154,   155,   156,   157,    -1,    -1,    -1,   161,    -1,    -1,
     164,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,   210,   211,    -1,    -1,
      -1,   215,   216,   217,    -1,   219,   220,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,
       3,     4,    -1,    -1,   258,    -1,   260,    10,    11,    12,
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
     258,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
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
      -1,   258,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
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
      -1,    -1,   258,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,
     211,    -1,    -1,    -1,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,     3,     4,    -1,   257,    -1,     8,   260,
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
       4,    -1,    -1,   253,     8,    -1,    10,    11,    12,    -1,
     260,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
      -1,    -1,    10,    11,    12,    -1,   260,    15,    16,    17,
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
      -1,    -1,   248,     3,     4,     5,    -1,   253,    -1,    -1,
      10,    11,    12,    -1,   260,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    -1,    97,     3,     4,
       5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    -1,    -1,    -1,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,   257,    -1,    -1,
     260,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,    -1,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,     3,
       4,     5,   257,    -1,    -1,   260,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
       3,     4,    -1,    -1,   253,    -1,    -1,    10,    11,    12,
      -1,   260,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    92,
      93,     8,    95,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   262,   215,   216,   217,    -1,   219,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   257,    -1,    -1,   260,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     262,    -1,    -1,   210,    -1,    -1,    -1,    -1,   215,   216,
     217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,    -1,   253,    -1,    -1,    10,
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
      -1,    -1,    -1,   144,    -1,   206,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,   215,   216,   217,   158,   219,   220,
     221,   162,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,   183,   184,   185,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,   260,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,   215,   216,   217,
      -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,
     248,     3,     4,    -1,     6,   253,    -1,    -1,    10,    11,
      12,    -1,   260,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    95,     3,     4,    -1,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    81,    82,    83,   117,   118,   119,   120,    -1,
      -1,   123,    -1,    92,    93,    -1,    95,    -1,   130,   131,
      -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,   215,   216,   217,   158,   219,   220,   221,
      -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,   183,   184,   185,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,   260,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,   215,   216,   217,    -1,
     219,   220,   221,    -1,    -1,    -1,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,    -1,    -1,    -1,    -1,   248,
       3,     4,    -1,    -1,   253,    -1,    -1,    10,    11,    12,
      -1,   260,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,   206,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   262,   215,   216,   217,    -1,   219,   220,   221,    -1,
      -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,   260,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     262,    -1,    -1,   210,    -1,    -1,    -1,    -1,   215,   216,
     217,    -1,   219,   220,   221,    -1,    -1,    -1,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,    -1,   253,   254,    -1,    10,
      11,    12,    -1,   260,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    -1,    95,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
      -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,   206,    -1,    -1,   252,   210,
     183,   184,   185,   257,   215,   216,   217,    -1,   219,   220,
     221,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,   258,    -1,    -1,    -1,   130,
     131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,   158,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,   183,   184,   185,    -1,    -1,   130,   131,    -1,
      -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,   158,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
     183,   184,   185,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,   258,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,    -1,    -1,   134,   135,    -1,   137,
     138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
     158,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   258,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,   183,   184,   185,    -1,    -1,
     130,   131,    -1,    -1,   134,   135,    -1,   137,   138,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
     258,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,    -1,   134,
     135,    -1,   137,   138,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,   158,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   258,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,   183,   184,
     185,    -1,    -1,   130,   131,    -1,    -1,   134,   135,    -1,
     137,   138,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,   101,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,   185,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,   258,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
      -1,   134,   135,    -1,   137,   138,    -1,   140,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,    46,    47,    48,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    67,    68,    69,
      -1,   252,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,
      -1,   262,    -1,    -1,    84,    85,    86,    87,    88,    -1,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,   258,   116,   117,   118,   119,
     120,   121,    -1,   123,    -1,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,   142,   143,   144,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,    -1,    -1,
      -1,   171,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,   182,   183,   184,   185,    -1,    -1,   188,    -1,
     190,    -1,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,     4,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,   223,    -1,   225,    -1,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,    -1,    46,    47,
      48,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,   116,   117,
     118,   119,   120,   121,    -1,   123,    -1,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,   142,   143,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
      -1,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,   182,   183,   184,   185,     4,     5,
     188,    -1,   190,    -1,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,   214,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    62,    63,    64,    65,
       4,     5,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   120,    -1,    -1,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,   137,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,    -1,    -1,    -1,   222,    -1,   224,   225,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   258,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
     258,   230,   231,   232,   233,   234,   235,   236,   237,   238,
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
     269,   289,   308,   310,   314,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   332,   334,   335,   341,   342,   343,
     344,   350,   375,   376,   257,   261,    14,   107,   253,   253,
     253,     6,   257,     6,     6,     6,     6,   253,     6,     6,
     257,     6,     6,   255,   255,     4,   352,   376,   253,   255,
     287,   101,   104,   107,   109,   287,   253,   253,   253,     4,
     253,   253,   253,     4,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   257,   122,   107,     6,   257,
     101,   104,   107,   120,   313,   109,   253,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    58,    59,    60,    61,    66,    67,    76,    77,
      81,    82,    83,    92,    95,   101,   104,   107,   109,   120,
     130,   135,   137,   140,   206,   210,   211,   215,   216,   217,
     219,   220,   221,   241,   242,   248,   253,   257,   260,   310,
     311,   314,   325,   332,   334,   345,   346,   350,   352,   359,
     361,   376,   253,   257,   257,   107,   107,   130,   104,   107,
     109,   101,   104,   107,   109,   310,   104,   107,   108,   109,
     120,   183,   311,   104,   107,   253,   104,   162,   188,   204,
     205,   257,   241,   242,   253,   257,   356,   357,   356,   257,
     257,   356,     4,   101,   105,   111,   112,   114,   115,   134,
     257,   253,   107,   109,   107,   104,     4,    93,   199,   257,
     376,     4,     6,   101,   104,   107,   104,   107,   120,   312,
     107,     4,     4,     4,     5,   253,   257,   359,   360,     4,
     253,   253,   253,     4,   257,   363,   376,     4,   253,   253,
     253,     6,     6,   255,     5,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    62,    63,    64,    65,    70,    71,
      72,    73,    78,    80,    94,    97,   207,   208,   209,   218,
     222,   224,   367,   376,   253,     4,   367,     5,   257,     5,
     257,    32,   242,   345,   376,   255,   257,   253,   257,     6,
     253,   257,     6,   261,     7,   137,   199,   226,   227,   228,
     229,   250,   251,   253,   255,   259,   285,   286,   287,   310,
     345,   366,   367,   376,     4,   314,   315,   316,   257,     6,
     345,   366,   367,   376,   366,   366,   345,   366,   373,   374,
     376,   345,   291,   295,   253,   355,     9,   367,   253,   253,
     253,   253,   376,   345,   345,   345,   253,   345,   345,   345,
     253,   345,   345,   345,   345,   345,   345,   345,   366,   345,
     345,   345,   345,   360,   253,   242,   345,   361,   362,   257,
     360,   359,   366,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   253,   255,
     287,   287,   287,   287,   287,   287,   253,   287,   287,   253,
     310,   311,   311,   287,   287,     5,   257,   257,   130,   310,
     310,   253,   287,   287,   253,   253,   253,   345,   257,   345,
     361,   345,   345,   258,   362,   352,   376,   191,     5,   257,
       8,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   252,
       9,   253,   255,   259,   286,   287,   345,   362,   362,   253,
     253,   253,   359,   360,   360,   360,   309,   253,   257,   253,
     253,   359,   257,   257,   345,     4,   359,   257,   363,   257,
     257,   356,   356,   356,   345,   345,   241,   242,   257,   257,
     356,   241,   242,   253,   316,   356,   257,   253,   257,   253,
     253,   253,   253,   253,   253,   253,   362,   345,   360,   360,
     360,   253,     4,   255,   257,     6,   255,   316,     6,     6,
     257,   257,   257,   257,   360,   257,   255,   255,   255,   345,
       8,     6,     6,   345,   345,   345,   259,   345,   257,   191,
     345,   345,   345,   345,   287,   287,   287,   253,   253,   253,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     253,   253,   287,   253,   255,     6,     6,   257,     6,     8,
     316,     6,     8,   316,   287,   345,   243,   257,     9,   253,
     255,   259,   366,   362,   345,   316,   359,   359,   257,   367,
     310,     7,   345,   345,     4,   188,   189,   359,     6,   254,
     256,   257,   288,   257,     6,   257,     6,     9,   253,   255,
     259,   376,   258,   130,   135,   137,   138,   140,   308,   310,
     345,     6,   254,   262,     9,   253,   255,   259,   254,   262,
     254,   262,   262,   254,   262,     9,   253,   259,   262,   256,
     262,   290,   256,   290,    96,   354,   351,   376,   262,   345,
     345,   345,   345,   262,   254,   254,   254,   345,   254,   254,
     254,   345,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   258,     7,   345,   243,   258,   262,   345,
       6,     6,   254,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     361,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     361,   361,   376,   257,   345,   345,   366,   345,   366,   359,
     366,   366,   373,   257,   257,   257,   345,   288,   376,     8,
     345,   345,   360,   359,   366,   366,   361,   352,   367,   352,
     362,   254,   258,   259,   287,    67,     8,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   257,   345,   361,   345,   345,   345,   345,   345,   376,
     345,   345,     4,   353,   257,   288,   254,   258,   258,   345,
     345,   345,     7,     7,   338,   338,   253,   345,   345,   345,
     345,     6,   362,   362,   257,   254,     6,   316,   257,   316,
     316,   262,   262,   262,   356,   356,   315,   315,   262,   345,
     258,   329,   262,   316,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   258,   254,     7,   339,     6,     7,   345,
       6,   345,   316,   345,   258,   362,   362,   362,   345,     6,
     362,   345,   345,   345,   254,   258,   254,   254,   254,   188,
     262,   316,   257,     8,   254,   254,   256,   373,   366,   373,
     366,   366,   366,   366,   366,   366,   345,   366,   366,   366,
     366,   260,   369,   376,   367,   366,   366,   366,   352,   376,
     362,   258,   258,   258,   258,   345,   345,   316,   376,   353,
     256,   258,   254,   144,   162,   333,   254,   258,   262,   345,
       6,   257,   359,   254,   256,     7,   285,   286,   259,     7,
       6,   362,     7,   229,   285,   345,   270,   376,   345,   345,
     353,   255,   253,   130,   310,   311,   310,   257,   258,     6,
     236,   237,   267,   362,   376,   345,   345,     4,   353,     6,
     362,     6,   362,   345,     6,   366,   374,   376,   254,   353,
     345,     6,   376,     6,   366,   345,   254,   255,   345,   262,
     262,   262,   262,   367,     7,     7,     7,   254,     7,     7,
       7,   254,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   345,   254,   257,   345,   361,   258,     6,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     262,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     262,   262,   262,   262,   262,   254,   256,   256,   362,   262,
     262,   288,   262,   288,   262,   262,   262,   254,   362,   345,
     345,   347,   288,   258,   258,   258,   262,   262,   288,   288,
     254,   259,   254,   259,   262,   287,   348,   258,     7,   353,
     288,   257,   258,     8,     8,   362,   259,   254,   256,   286,
     253,   255,   287,   362,     7,   257,   257,   254,   254,   254,
     345,   359,     4,   337,     6,   304,   345,   367,   254,   258,
     254,   254,   258,   258,   362,   259,   258,   316,   258,   258,
     356,   345,   345,   258,   258,   345,   356,   141,   141,   159,
     168,   169,   170,   174,   175,   330,   331,   356,   258,   326,
     254,   258,   254,   254,   254,   254,   254,   254,   254,   257,
       7,   345,     6,   345,   254,   256,   258,   256,   258,   258,
     258,   258,   258,   256,   256,   262,     7,     7,     7,   259,
     345,   258,   345,   345,     7,   259,   288,   262,   288,   288,
     254,   254,   262,   288,   288,   262,   262,   288,   288,   288,
     288,   345,   288,     9,   368,   262,   254,   262,   288,   259,
     262,   349,   256,   258,   258,   259,   253,   255,   261,   191,
       7,   162,     6,   345,   258,   257,     6,   359,   258,   345,
       6,     7,   285,   286,   259,   285,   286,   367,   345,     6,
       4,   257,   364,   376,   258,    49,    49,   359,   258,     4,
     178,   179,   180,   181,   258,   273,   277,   280,   282,   283,
     324,   259,   254,   256,   253,   345,   345,   253,   257,   253,
     257,     8,   362,   366,   254,   259,   254,   256,   253,   254,
     254,   262,   259,   253,   262,     7,   287,     4,    36,    37,
     298,   299,   300,   288,   345,   345,   345,   345,   288,   356,
     359,   359,     7,   359,   359,   359,     7,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,     6,     7,   362,
     345,   345,   345,   345,   345,   345,   258,   345,   345,   345,
     359,   366,   366,   258,   258,   258,   262,   297,   345,   345,
     353,   353,   345,   345,   254,   359,   287,   345,   345,   345,
     258,   353,   286,   259,   286,   345,   345,   288,   258,   359,
     362,   362,     7,     7,     7,   141,   336,     6,   254,   262,
       7,     7,     7,     7,     7,   258,     4,   258,   262,   262,
     262,   258,   258,   119,     4,     6,   345,   257,     6,   253,
       6,   176,     6,   176,   258,   331,   262,   330,     7,     6,
       7,     7,     7,     7,     7,     7,     7,   315,   359,     6,
     257,     6,     6,     6,   107,     7,     7,     6,     6,   345,
     359,   359,   359,     4,   262,     8,     8,   254,     4,   110,
     111,     4,   362,   366,   345,   366,   260,   262,   301,   366,
     366,   353,   366,   254,   262,   353,   257,   310,   257,     6,
     345,     6,   257,   359,   258,   258,   345,     6,     4,   188,
     189,   345,     6,     6,     6,     7,   363,   365,     6,   255,
     288,   287,   287,     6,   274,   253,   253,   257,   284,     6,
     353,   259,   366,   345,   256,   254,   345,     8,   362,   345,
     362,   258,   258,     6,     6,   267,   353,   259,   345,     6,
       6,   345,   353,   254,   345,   257,   345,   367,   288,    49,
     257,   359,   367,   370,   345,   345,   256,   262,     6,   254,
     254,   254,   254,     6,     6,   134,   306,   306,   359,     6,
       6,     6,   359,   141,   191,   305,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     5,   258,   288,   288,   288,
     288,   288,   288,   288,   262,   262,   262,   254,   288,   288,
     299,   288,   254,   288,   254,   287,   348,   288,     6,   288,
     262,   253,   255,   287,     4,   254,   256,   288,     6,   258,
     258,   359,   359,   359,     4,     6,   285,   345,   359,   359,
     359,   257,   257,     7,     6,     7,   345,   345,   345,   257,
     257,   257,   255,     6,   345,   359,   345,     6,     6,   345,
     356,   258,     5,   359,   257,   257,   257,   257,   257,   257,
     257,   359,   258,     6,   362,   257,   345,   345,   256,     6,
       6,   187,   345,   345,   345,     6,     6,     6,     6,     7,
     288,   262,   262,   288,   262,   345,     4,   203,   302,   303,
     288,   254,   288,   349,   367,   253,   255,   345,   257,   316,
       6,   316,   262,     6,     6,     7,   285,   286,   259,     7,
       6,   363,   258,   262,   345,   285,   257,   288,   371,   372,
     373,   371,   253,   345,   345,   358,   359,   257,   253,     4,
       6,   254,     6,   254,   258,   258,   254,   258,     6,     6,
     366,   253,     4,   254,   262,   253,   258,   262,   359,   367,
       7,   287,   296,   345,   361,   300,     6,     6,     6,     6,
     356,     6,     6,     6,   141,   307,   101,   120,   105,     6,
       5,   257,   345,   345,   345,   345,   254,   348,   345,   345,
     345,   288,   286,   257,   257,     6,   305,     6,   345,   359,
     141,   141,     4,     6,   362,   362,   345,   345,   367,   258,
     254,   258,   262,   315,   315,   345,   345,   258,   262,   254,
     258,   262,     6,     6,   358,   356,   356,   356,   356,   356,
     242,   356,     6,   258,   345,     6,     6,     6,   359,   258,
     262,     8,   258,   254,   257,   345,   367,   366,   345,   366,
     345,   367,   370,   372,   367,   262,   254,   262,   258,   345,
     333,   333,   359,   367,   345,     6,     4,   364,     6,   363,
     256,   359,   373,     6,   288,   288,   271,   345,   262,   262,
     258,   262,   272,   345,   345,     6,     6,     6,     6,   345,
     345,   254,     6,   345,   292,   294,   257,   372,   258,   262,
       7,     7,   145,     6,   257,   257,   257,     5,   358,   288,
     288,   262,   288,   254,   262,   254,   256,   362,   362,     6,
       6,   345,   345,   257,   258,   258,   257,     6,     6,   257,
     345,   258,   258,   258,   256,     6,   359,     7,   257,   345,
     258,   262,   262,   262,   262,   262,   262,     6,   258,   186,
     345,   345,   362,     6,     6,   254,   288,   288,   303,   367,
     258,   258,   258,   258,     6,     6,     7,     6,   259,     6,
     258,     6,     6,   254,   262,   345,   345,   257,   359,   258,
     262,   254,   254,   262,   258,   297,   301,   359,   288,   345,
     367,   376,   362,   362,   345,     6,   258,   345,   348,   345,
     258,   258,     6,     6,   358,   146,   147,   152,   340,   146,
     147,   340,   362,   315,   258,   262,     6,   258,   359,   316,
     258,     6,   362,   356,   356,   356,   356,   356,   345,   258,
     258,   258,   254,     6,   257,     6,   363,   189,   275,   345,
     262,   262,   358,     6,   345,   345,     6,   258,   258,   293,
       7,   253,   258,   258,   258,   257,   262,   254,   262,   257,
     258,   257,   356,   359,     6,   257,   356,     6,   258,   258,
     345,     6,   141,   258,   327,   257,   258,   262,   262,   262,
     262,   262,     6,     6,     6,   316,     6,   257,   345,   345,
     258,   262,   297,   367,   254,   345,   345,   345,   362,     6,
     356,     6,   356,     6,     6,   258,   345,   330,   316,     6,
     362,   362,   362,   362,   356,   362,   333,   272,   254,   262,
       6,   257,   345,   258,   262,   262,   262,   258,   262,   262,
       6,   258,   258,   328,   258,   258,   258,   258,   262,   258,
     258,   258,   278,   345,   358,   258,   345,   345,   345,   356,
     356,   330,     6,     6,     6,     6,   362,     6,     6,     6,
     257,   254,   258,     6,   258,   288,   262,   262,   262,   258,
     258,   276,   366,   281,   257,     6,   345,   345,   345,     6,
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
#line 779 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 76:
#line 779 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 80:
#line 789 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 81:
#line 794 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 82:
#line 800 "Gmsh.y"
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

  case 83:
#line 862 "Gmsh.y"
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

  case 84:
#line 877 "Gmsh.y"
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

  case 85:
#line 906 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 86:
#line 916 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 87:
#line 921 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 88:
#line 929 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 89:
#line 934 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 90:
#line 942 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 91:
#line 951 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 92:
#line 956 "Gmsh.y"
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

  case 93:
#line 968 "Gmsh.y"
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

  case 94:
#line 985 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 95:
#line 991 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 96:
#line 1000 "Gmsh.y"
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

  case 97:
#line 1018 "Gmsh.y"
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

  case 98:
#line 1036 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 99:
#line 1045 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 100:
#line 1057 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 101:
#line 1062 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 102:
#line 1070 "Gmsh.y"
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

  case 103:
#line 1090 "Gmsh.y"
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

  case 104:
#line 1113 "Gmsh.y"
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

  case 105:
#line 1133 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 106:
#line 1141 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 107:
#line 1148 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 108:
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

  case 109:
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

  case 110:
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

  case 111:
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

  case 112:
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

  case 113:
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

  case 117:
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

  case 118:
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

  case 119:
#line 1307 "Gmsh.y"
    { init_options(); ;}
    break;

  case 120:
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

  case 121:
#line 1327 "Gmsh.y"
    { init_options(); ;}
    break;

  case 122:
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

  case 123:
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

  case 124:
#line 1354 "Gmsh.y"
    { init_options(); ;}
    break;

  case 125:
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

  case 127:
#line 1370 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 128:
#line 1378 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 129:
#line 1384 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 130:
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

  case 137:
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

  case 138:
#line 1444 "Gmsh.y"
    {
      floatOptions["Min"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 139:
#line 1448 "Gmsh.y"
    {
      floatOptions["Max"].push_back((yyvsp[(2) - (2)].d));
    ;}
    break;

  case 140:
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

  case 141:
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

  case 142:
#line 1479 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 143:
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

  case 148:
#line 1512 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 149:
#line 1520 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 150:
#line 1529 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 151:
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

  case 152:
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

  case 153:
#line 1569 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 154:
#line 1573 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 155:
#line 1580 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 156:
#line 1588 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 157:
#line 1592 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 158:
#line 1598 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 159:
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

  case 160:
#line 1613 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 161:
#line 1617 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 162:
#line 1623 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 163:
#line 1627 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 164:
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

  case 165:
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

  case 166:
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

  case 167:
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

  case 168:
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

  case 169:
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

  case 170:
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

  case 171:
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

  case 172:
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

  case 173:
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

  case 174:
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

  case 175:
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

  case 176:
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

  case 177:
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

  case 178:
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

  case 179:
#line 1984 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 180:
#line 1990 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 181:
#line 1996 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 182:
#line 2003 "Gmsh.y"
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

  case 183:
#line 2034 "Gmsh.y"
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

  case 184:
#line 2049 "Gmsh.y"
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

  case 185:
#line 2071 "Gmsh.y"
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

  case 186:
#line 2094 "Gmsh.y"
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

  case 187:
#line 2117 "Gmsh.y"
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

  case 188:
#line 2140 "Gmsh.y"
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

  case 189:
#line 2164 "Gmsh.y"
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

  case 190:
#line 2188 "Gmsh.y"
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

  case 191:
#line 2212 "Gmsh.y"
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

  case 192:
#line 2238 "Gmsh.y"
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

  case 193:
#line 2255 "Gmsh.y"
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

  case 194:
#line 2271 "Gmsh.y"
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

  case 195:
#line 2289 "Gmsh.y"
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

  case 196:
#line 2307 "Gmsh.y"
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

  case 197:
#line 2320 "Gmsh.y"
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

  case 198:
#line 2332 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 199:
#line 2336 "Gmsh.y"
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

  case 200:
#line 2362 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 201:
#line 2364 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 202:
#line 2366 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 203:
#line 2368 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 204:
#line 2370 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 205:
#line 2378 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 206:
#line 2380 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 207:
#line 2382 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 208:
#line 2384 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 209:
#line 2392 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 210:
#line 2394 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 211:
#line 2396 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 212:
#line 2404 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 213:
#line 2406 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 214:
#line 2408 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 215:
#line 2410 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 216:
#line 2420 "Gmsh.y"
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

  case 217:
#line 2436 "Gmsh.y"
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

  case 218:
#line 2452 "Gmsh.y"
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

  case 219:
#line 2468 "Gmsh.y"
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

  case 220:
#line 2484 "Gmsh.y"
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

  case 221:
#line 2500 "Gmsh.y"
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

  case 222:
#line 2517 "Gmsh.y"
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

  case 223:
#line 2554 "Gmsh.y"
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

  case 224:
#line 2576 "Gmsh.y"
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

  case 225:
#line 2599 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 226:
#line 2600 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 227:
#line 2605 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 228:
#line 2609 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 229:
#line 2613 "Gmsh.y"
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

  case 230:
#line 2630 "Gmsh.y"
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

  case 231:
#line 2650 "Gmsh.y"
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

  case 232:
#line 2670 "Gmsh.y"
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

  case 233:
#line 2689 "Gmsh.y"
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

  case 234:
#line 2716 "Gmsh.y"
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

  case 235:
#line 2735 "Gmsh.y"
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

  case 236:
#line 2757 "Gmsh.y"
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

  case 237:
#line 2772 "Gmsh.y"
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

  case 238:
#line 2787 "Gmsh.y"
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

  case 239:
#line 2806 "Gmsh.y"
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

  case 240:
#line 2857 "Gmsh.y"
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

  case 241:
#line 2878 "Gmsh.y"
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

  case 242:
#line 2900 "Gmsh.y"
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

  case 243:
#line 2922 "Gmsh.y"
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

  case 244:
#line 3027 "Gmsh.y"
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

  case 245:
#line 3043 "Gmsh.y"
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

  case 246:
#line 3078 "Gmsh.y"
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

  case 247:
#line 3100 "Gmsh.y"
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

  case 248:
#line 3122 "Gmsh.y"
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

  case 249:
#line 3134 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 250:
#line 3140 "Gmsh.y"
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

  case 251:
#line 3155 "Gmsh.y"
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

  case 252:
#line 3183 "Gmsh.y"
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

  case 253:
#line 3195 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 254:
#line 3204 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 255:
#line 3211 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 256:
#line 3223 "Gmsh.y"
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

  case 257:
#line 3243 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 258:
#line 3247 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 259:
#line 3252 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 260:
#line 3256 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 261:
#line 3261 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 262:
#line 3268 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 263:
#line 3275 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 264:
#line 3282 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 265:
#line 3294 "Gmsh.y"
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

  case 266:
#line 3367 "Gmsh.y"
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

  case 267:
#line 3385 "Gmsh.y"
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

  case 268:
#line 3410 "Gmsh.y"
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

  case 269:
#line 3425 "Gmsh.y"
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

  case 270:
#line 3458 "Gmsh.y"
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

  case 271:
#line 3470 "Gmsh.y"
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

  case 272:
#line 3502 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 273:
#line 3506 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 274:
#line 3511 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 275:
#line 3518 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 276:
#line 3523 "Gmsh.y"
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

  case 277:
#line 3533 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 278:
#line 3538 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 279:
#line 3544 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 280:
#line 3552 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 281:
#line 3556 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 282:
#line 3560 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 283:
#line 3564 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 284:
#line 3568 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 285:
#line 3572 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 286:
#line 3576 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 287:
#line 3586 "Gmsh.y"
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

  case 288:
#line 3649 "Gmsh.y"
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

  case 289:
#line 3665 "Gmsh.y"
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

  case 290:
#line 3682 "Gmsh.y"
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

  case 291:
#line 3699 "Gmsh.y"
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

  case 292:
#line 3721 "Gmsh.y"
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

  case 293:
#line 3743 "Gmsh.y"
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

  case 294:
#line 3778 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 295:
#line 3786 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 296:
#line 3794 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 297:
#line 3800 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 298:
#line 3807 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 299:
#line 3814 "Gmsh.y"
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

  case 300:
#line 3834 "Gmsh.y"
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

  case 301:
#line 3860 "Gmsh.y"
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

  case 302:
#line 3872 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 303:
#line 3883 "Gmsh.y"
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

  case 304:
#line 3901 "Gmsh.y"
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

  case 305:
#line 3919 "Gmsh.y"
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

  case 306:
#line 3937 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 3943 "Gmsh.y"
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

  case 308:
#line 3961 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 3967 "Gmsh.y"
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

  case 310:
#line 3987 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 3993 "Gmsh.y"
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

  case 312:
#line 4011 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 313:
#line 4017 "Gmsh.y"
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

  case 314:
#line 4034 "Gmsh.y"
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

  case 315:
#line 4050 "Gmsh.y"
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

  case 316:
#line 4067 "Gmsh.y"
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

  case 317:
#line 4085 "Gmsh.y"
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

  case 318:
#line 4108 "Gmsh.y"
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

  case 319:
#line 4135 "Gmsh.y"
    {
    ;}
    break;

  case 320:
#line 4138 "Gmsh.y"
    {
    ;}
    break;

  case 321:
#line 4144 "Gmsh.y"
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

  case 322:
#line 4156 "Gmsh.y"
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

  case 323:
#line 4176 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 324:
#line 4180 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 325:
#line 4184 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 326:
#line 4188 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 327:
#line 4192 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 328:
#line 4196 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 329:
#line 4200 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 330:
#line 4204 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 331:
#line 4213 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 332:
#line 4225 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 333:
#line 4226 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 334:
#line 4227 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 335:
#line 4228 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 336:
#line 4229 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 337:
#line 4233 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 338:
#line 4234 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 339:
#line 4235 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 340:
#line 4236 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 341:
#line 4237 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 342:
#line 4242 "Gmsh.y"
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

  case 343:
#line 4265 "Gmsh.y"
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

  case 344:
#line 4285 "Gmsh.y"
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

  case 345:
#line 4306 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 346:
#line 4310 "Gmsh.y"
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

  case 347:
#line 4325 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 348:
#line 4329 "Gmsh.y"
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

  case 349:
#line 4345 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 350:
#line 4349 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 351:
#line 4354 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 352:
#line 4358 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 353:
#line 4364 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 354:
#line 4368 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 355:
#line 4375 "Gmsh.y"
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

  case 356:
#line 4397 "Gmsh.y"
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

  case 357:
#line 4438 "Gmsh.y"
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

  case 358:
#line 4482 "Gmsh.y"
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

  case 359:
#line 4521 "Gmsh.y"
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

  case 360:
#line 4546 "Gmsh.y"
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

  case 361:
#line 4558 "Gmsh.y"
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

  case 362:
#line 4570 "Gmsh.y"
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

  case 363:
#line 4582 "Gmsh.y"
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

  case 364:
#line 4594 "Gmsh.y"
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

  case 365:
#line 4611 "Gmsh.y"
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

  case 366:
#line 4628 "Gmsh.y"
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

  case 367:
#line 4658 "Gmsh.y"
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

  case 368:
#line 4684 "Gmsh.y"
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

  case 369:
#line 4711 "Gmsh.y"
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

  case 370:
#line 4743 "Gmsh.y"
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

  case 371:
#line 4770 "Gmsh.y"
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

  case 372:
#line 4796 "Gmsh.y"
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

  case 373:
#line 4822 "Gmsh.y"
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

  case 374:
#line 4848 "Gmsh.y"
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

  case 375:
#line 4874 "Gmsh.y"
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

  case 376:
#line 4895 "Gmsh.y"
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

  case 377:
#line 4906 "Gmsh.y"
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

  case 378:
#line 4954 "Gmsh.y"
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

  case 379:
#line 5008 "Gmsh.y"
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

  case 380:
#line 5023 "Gmsh.y"
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

  case 381:
#line 5035 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 382:
#line 5046 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 383:
#line 5053 "Gmsh.y"
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

  case 384:
#line 5068 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 385:
#line 5081 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 386:
#line 5082 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 387:
#line 5083 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 388:
#line 5088 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 389:
#line 5094 "Gmsh.y"
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

  case 390:
#line 5106 "Gmsh.y"
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

  case 391:
#line 5124 "Gmsh.y"
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

  case 392:
#line 5151 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 393:
#line 5152 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 394:
#line 5153 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 395:
#line 5154 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 396:
#line 5155 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 397:
#line 5156 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 398:
#line 5157 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 399:
#line 5158 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 400:
#line 5160 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 401:
#line 5166 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 402:
#line 5167 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 403:
#line 5168 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 404:
#line 5169 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 405:
#line 5170 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 406:
#line 5171 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 407:
#line 5172 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5173 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5174 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5175 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5176 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 412:
#line 5177 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 413:
#line 5178 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 414:
#line 5179 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 415:
#line 5180 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 416:
#line 5181 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 417:
#line 5182 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 418:
#line 5183 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 419:
#line 5184 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5185 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5186 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5187 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5188 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5189 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 425:
#line 5190 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5191 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 427:
#line 5192 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5193 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5194 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5195 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5196 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 432:
#line 5197 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 433:
#line 5198 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 434:
#line 5199 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 435:
#line 5200 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 436:
#line 5201 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 437:
#line 5202 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 438:
#line 5203 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 439:
#line 5204 "Gmsh.y"
    { (yyval.d) = std::max((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 440:
#line 5205 "Gmsh.y"
    { (yyval.d) = std::min((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 441:
#line 5214 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 442:
#line 5215 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 443:
#line 5216 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 444:
#line 5217 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 445:
#line 5218 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 446:
#line 5219 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 447:
#line 5220 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 448:
#line 5221 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 449:
#line 5222 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 450:
#line 5223 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 451:
#line 5224 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 452:
#line 5229 "Gmsh.y"
    { init_options(); ;}
    break;

  case 453:
#line 5231 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 454:
#line 5237 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 455:
#line 5239 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 456:
#line 5244 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 457:
#line 5249 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 458:
#line 5254 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 459:
#line 5259 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 460:
#line 5263 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 461:
#line 5267 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 462:
#line 5271 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 463:
#line 5275 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 464:
#line 5279 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 465:
#line 5283 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 466:
#line 5287 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 467:
#line 5293 "Gmsh.y"
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

  case 468:
#line 5308 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 469:
#line 5312 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 470:
#line 5318 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 471:
#line 5323 "Gmsh.y"
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

  case 472:
#line 5342 "Gmsh.y"
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

  case 473:
#line 5362 "Gmsh.y"
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

  case 474:
#line 5393 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 475:
#line 5397 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 476:
#line 5401 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 477:
#line 5405 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 478:
#line 5409 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 479:
#line 5413 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 480:
#line 5417 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 481:
#line 5422 "Gmsh.y"
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

  case 482:
#line 5432 "Gmsh.y"
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

  case 483:
#line 5442 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 484:
#line 5447 "Gmsh.y"
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

  case 485:
#line 5458 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 486:
#line 5467 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 487:
#line 5472 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 488:
#line 5477 "Gmsh.y"
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

  case 489:
#line 5504 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 490:
#line 5506 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 491:
#line 5511 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 492:
#line 5513 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 493:
#line 5518 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 494:
#line 5525 "Gmsh.y"
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

  case 495:
#line 5541 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 496:
#line 5543 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 497:
#line 5548 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 498:
#line 5557 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 499:
#line 5559 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 500:
#line 5564 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 501:
#line 5566 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 502:
#line 5571 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 503:
#line 5575 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 504:
#line 5579 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 505:
#line 5583 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 506:
#line 5587 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 507:
#line 5594 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 508:
#line 5598 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 509:
#line 5602 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 510:
#line 5606 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 511:
#line 5613 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 512:
#line 5618 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 513:
#line 5625 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 514:
#line 5630 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 515:
#line 5634 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 516:
#line 5639 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 517:
#line 5643 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 518:
#line 5651 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 519:
#line 5662 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 520:
#line 5666 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 521:
#line 5670 "Gmsh.y"
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

  case 522:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 523:
#line 5692 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 524:
#line 5700 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 525:
#line 5707 "Gmsh.y"
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

  case 526:
#line 5717 "Gmsh.y"
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

  case 527:
#line 5740 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 528:
#line 5745 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 529:
#line 5751 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 530:
#line 5756 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 531:
#line 5762 "Gmsh.y"
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

  case 532:
#line 5773 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 533:
#line 5780 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 534:
#line 5785 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 535:
#line 5791 "Gmsh.y"
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

  case 536:
#line 5803 "Gmsh.y"
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

  case 537:
#line 5817 "Gmsh.y"
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

  case 538:
#line 5827 "Gmsh.y"
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

  case 539:
#line 5837 "Gmsh.y"
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
#line 5847 "Gmsh.y"
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

  case 541:
#line 5859 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 542:
#line 5863 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 543:
#line 5868 "Gmsh.y"
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

  case 544:
#line 5880 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 545:
#line 5884 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 546:
#line 5888 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 547:
#line 5892 "Gmsh.y"
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

  case 548:
#line 5910 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 549:
#line 5918 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 550:
#line 5926 "Gmsh.y"
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

  case 551:
#line 5955 "Gmsh.y"
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

  case 552:
#line 5965 "Gmsh.y"
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

  case 553:
#line 5981 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 554:
#line 5992 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 555:
#line 5997 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 556:
#line 6001 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 557:
#line 6005 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 558:
#line 6017 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 559:
#line 6021 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 560:
#line 6033 "Gmsh.y"
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

  case 561:
#line 6050 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 562:
#line 6060 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 563:
#line 6064 "Gmsh.y"
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

  case 564:
#line 6079 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 565:
#line 6084 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 566:
#line 6091 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 567:
#line 6095 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 568:
#line 6100 "Gmsh.y"
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

  case 569:
#line 6114 "Gmsh.y"
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

  case 570:
#line 6130 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 571:
#line 6134 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 572:
#line 6138 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 573:
#line 6142 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 574:
#line 6146 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 575:
#line 6154 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 576:
#line 6160 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 577:
#line 6169 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 578:
#line 6173 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 579:
#line 6177 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 580:
#line 6185 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 581:
#line 6191 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 582:
#line 6197 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 583:
#line 6201 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 584:
#line 6209 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 585:
#line 6217 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 586:
#line 6224 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 587:
#line 6233 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 588:
#line 6237 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 589:
#line 6241 "Gmsh.y"
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

  case 590:
#line 6256 "Gmsh.y"
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

  case 591:
#line 6270 "Gmsh.y"
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

  case 592:
#line 6284 "Gmsh.y"
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

  case 593:
#line 6296 "Gmsh.y"
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

  case 594:
#line 6312 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 595:
#line 6321 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 596:
#line 6330 "Gmsh.y"
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

  case 597:
#line 6340 "Gmsh.y"
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

  case 598:
#line 6351 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 599:
#line 6359 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 600:
#line 6367 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 601:
#line 6371 "Gmsh.y"
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

  case 602:
#line 6390 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 603:
#line 6397 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 604:
#line 6403 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 605:
#line 6409 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 606:
#line 6416 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 607:
#line 6423 "Gmsh.y"
    { init_options(); ;}
    break;

  case 608:
#line 6425 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 609:
#line 6433 "Gmsh.y"
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

  case 610:
#line 6457 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 611:
#line 6459 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 612:
#line 6465 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 613:
#line 6470 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 614:
#line 6472 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 615:
#line 6477 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 616:
#line 6482 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 617:
#line 6487 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 618:
#line 6489 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 619:
#line 6493 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 620:
#line 6505 "Gmsh.y"
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

  case 621:
#line 6519 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 622:
#line 6523 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 623:
#line 6530 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 624:
#line 6538 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 625:
#line 6546 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 626:
#line 6557 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 627:
#line 6559 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 628:
#line 6562 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14680 "Gmsh.tab.cpp"
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


#line 6565 "Gmsh.y"


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
  if (flag_tSTRING_alloc) Free(c3);
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
  if (flag_tSTRING_alloc) Free(c3);
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
  if (flag_tSTRING_alloc) Free(c3);
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
  if (flag_tSTRING_alloc) Free(c3);
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
  if (flag_tSTRING_alloc) Free(c3);
  return out;
}

