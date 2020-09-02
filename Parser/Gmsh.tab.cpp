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
     tUnsplitWindow = 483,
     tAFFECTDIVIDE = 484,
     tAFFECTTIMES = 485,
     tAFFECTMINUS = 486,
     tAFFECTPLUS = 487,
     tOR = 488,
     tAND = 489,
     tNOTEQUAL = 490,
     tEQUAL = 491,
     tGREATERGREATER = 492,
     tLESSLESS = 493,
     tGREATEROREQUAL = 494,
     tLESSOREQUAL = 495,
     UNARYPREC = 496,
     tMINUSMINUS = 497,
     tPLUSPLUS = 498
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
#define tUnsplitWindow 483
#define tAFFECTDIVIDE 484
#define tAFFECTTIMES 485
#define tAFFECTMINUS 486
#define tAFFECTPLUS 487
#define tOR 488
#define tAND 489
#define tNOTEQUAL 490
#define tEQUAL 491
#define tGREATERGREATER 492
#define tLESSLESS 493
#define tGREATEROREQUAL 494
#define tLESSOREQUAL 495
#define UNARYPREC 496
#define tMINUSMINUS 497
#define tPLUSPLUS 498




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
#line 769 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 782 "Gmsh.tab.cpp"

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
#define YYLAST   17723

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  634
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2261

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   498

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   251,     2,   263,     2,   248,   250,     2,
     256,   257,   246,   244,   265,   245,   262,   247,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     238,     2,   239,   233,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   258,     2,   259,   255,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   260,   249,   261,   264,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   234,   235,
     236,   237,   240,   241,   242,   243,   252,   253,   254
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
    2909,  2915,  2921,  2927,  2929,  2931,  2933,  2937,  2943,  2951,
    2956,  2961,  2966,  2973,  2980,  2989,  2998,  3003,  3018,  3023,
    3028,  3030,  3032,  3036,  3040,  3050,  3058,  3060,  3066,  3070,
    3077,  3079,  3083,  3085,  3087,  3092,  3097,  3101,  3107,  3114,
    3123,  3130,  3135,  3141,  3143,  3148,  3150,  3152,  3154,  3156,
    3161,  3168,  3173,  3180,  3186,  3194,  3199,  3204,  3209,  3218,
    3223,  3228,  3233,  3238,  3247,  3256,  3263,  3268,  3275,  3280,
    3282,  3284,  3289,  3294,  3295,  3302,  3307,  3310,  3315,  3320,
    3322,  3324,  3328,  3330,  3332,  3336,  3340,  3344,  3350,  3358,
    3364,  3370,  3379,  3381,  3383
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     267,     0,    -1,   268,    -1,     1,     6,    -1,    -1,   268,
     269,    -1,   271,    -1,   272,    -1,   293,    -1,   130,   256,
     369,   257,     6,    -1,   312,    -1,   318,    -1,   322,    -1,
     323,    -1,   324,    -1,   325,    -1,   329,    -1,   338,    -1,
     339,    -1,   345,    -1,   346,    -1,   328,    -1,   327,    -1,
     326,    -1,   321,    -1,   348,    -1,   239,    -1,   240,    -1,
      46,   256,   369,   257,     6,    -1,    48,   256,   369,   257,
       6,    -1,    47,   256,   369,   257,     6,    -1,    46,   256,
     369,   257,   270,   369,     6,    -1,    46,   256,   369,   265,
     365,   257,     6,    -1,    48,   256,   369,   265,   365,   257,
       6,    -1,    47,   256,   369,   265,   365,   257,     6,    -1,
      46,   256,   369,   265,   365,   257,   270,   369,     6,    -1,
     379,   369,   260,   273,   261,     6,    -1,   172,     4,   258,
     349,   259,     6,    -1,   173,     4,   258,   349,   259,     6,
      -1,   174,     4,   258,   349,   265,   349,   259,     6,    -1,
      -1,   273,   276,    -1,   273,   280,    -1,   273,   283,    -1,
     273,   285,    -1,   273,   286,    -1,   273,   328,    -1,   349,
      -1,   274,   265,   349,    -1,   349,    -1,   275,   265,   349,
      -1,    -1,    -1,     4,   277,   256,   274,   257,   278,   260,
     275,   261,     6,    -1,   369,    -1,   279,   265,   369,    -1,
      -1,   179,   256,   349,   265,   349,   265,   349,   257,   281,
     260,   279,   261,     6,    -1,   369,    -1,   282,   265,   369,
      -1,    -1,   180,   256,   349,   265,   349,   265,   349,   265,
     349,   257,   284,   260,   282,   261,     6,    -1,   181,   260,
     361,   261,   260,   361,   261,     6,    -1,   181,   260,   361,
     261,   260,   361,   261,   260,   361,   261,   260,   361,   261,
       6,    -1,    -1,   182,   287,   260,   275,   261,     6,    -1,
       7,    -1,   232,    -1,   231,    -1,   230,    -1,   229,    -1,
     254,    -1,   253,    -1,   256,    -1,   258,    -1,   257,    -1,
     259,    -1,     4,    -1,    36,    -1,    37,    -1,   110,    -1,
     111,    -1,    90,   258,   295,   259,     6,    -1,    91,   258,
     299,   259,     6,    -1,   354,     6,    -1,    98,   290,   370,
     265,   349,   291,     6,    -1,   100,   290,   379,   265,   370,
     291,     6,    -1,   379,   288,   362,     6,    -1,   379,   289,
       6,    -1,   379,   290,   291,   288,   362,     6,    -1,   379,
     290,   260,   365,   261,   291,   288,   362,     6,    -1,   379,
     258,   349,   259,   288,   349,     6,    -1,   379,   258,   349,
     259,   289,     6,    -1,   379,   256,   349,   257,   288,   349,
       6,    -1,   379,   256,   349,   257,   289,     6,    -1,   379,
       7,   370,     6,    -1,   379,   290,   291,     7,    49,   290,
     291,     6,    -1,   379,   290,   291,     7,    49,   290,   374,
     291,     6,    -1,   379,   290,   291,   232,    49,   290,   374,
     291,     6,    -1,   379,   262,   292,     7,   370,     6,    -1,
     379,   258,   349,   259,   262,   292,     7,   370,     6,    -1,
     379,   262,   292,   288,   349,     6,    -1,   379,   258,   349,
     259,   262,   292,   288,   349,     6,    -1,   379,   262,   292,
     289,     6,    -1,   379,   258,   349,   259,   262,   292,   289,
       6,    -1,   379,   262,   189,   262,   292,     7,   366,     6,
      -1,   379,   258,   349,   259,   262,   189,   262,   292,     7,
     366,     6,    -1,   379,   262,   190,     7,   367,     6,    -1,
     379,   258,   349,   259,   262,   190,     7,   367,     6,    -1,
     379,   200,     7,   362,     6,    -1,   200,   258,   349,   259,
       7,   292,     6,    -1,   200,   258,   349,   259,   262,   292,
       7,   349,     6,    -1,   200,   258,   349,   259,   262,   292,
       7,   370,     6,    -1,   200,   258,   349,   259,   262,   292,
       7,   260,   365,   261,     6,    -1,   200,   258,   349,   259,
     262,   292,     6,    -1,   143,   256,     4,   257,   262,   292,
       7,   349,     6,    -1,   143,   256,     4,   257,   262,   292,
       7,   370,     6,    -1,    -1,   265,    -1,    -1,   295,   294,
     379,    -1,   295,   294,   379,     7,   349,    -1,    -1,   295,
     294,   379,     7,   260,   362,   296,   301,   261,    -1,    -1,
     295,   294,   379,   290,   291,     7,   260,   362,   297,   301,
     261,    -1,   295,   294,   379,     7,   370,    -1,    -1,   295,
     294,   379,     7,   260,   370,   298,   305,   261,    -1,    -1,
     299,   294,   369,    -1,   349,     7,   370,    -1,   300,   265,
     349,     7,   370,    -1,   364,     7,   379,   256,   257,    -1,
      -1,   265,   303,    -1,    -1,   303,    -1,   304,    -1,   303,
     265,   304,    -1,     4,   362,    -1,    36,   349,    -1,    37,
     349,    -1,     4,    -1,     4,   260,   300,   261,    -1,     4,
     370,    -1,     4,   373,    -1,    -1,   265,   306,    -1,   307,
      -1,   306,   265,   307,    -1,     4,   349,    -1,     4,   370,
      -1,   204,   370,    -1,     4,   375,    -1,     4,   373,    -1,
     349,    -1,   370,    -1,   370,   265,   349,    -1,    -1,   192,
     105,   260,   349,   261,    -1,   142,   101,   260,   365,   261,
      -1,   142,   120,   260,   365,   261,    -1,    -1,   135,   359,
      -1,    -1,   142,   146,    -1,   101,   256,   349,   257,     7,
     359,     6,    -1,   104,   256,   349,   257,     7,   362,     6,
      -1,   108,   256,   349,   257,     7,   362,     6,    -1,   139,
     108,   256,   349,   257,     7,   362,   142,   349,     6,    -1,
     139,   184,   256,   349,   257,     7,   362,   142,   349,     6,
      -1,   102,   256,   349,   257,     7,   362,   310,     6,    -1,
     103,   256,   349,   257,     7,   362,   310,     6,    -1,   184,
     256,   349,   257,     7,   362,     6,    -1,   185,   256,   349,
     257,     7,   362,     6,    -1,   186,   256,   349,   257,     7,
     362,   188,   362,   187,   349,     6,    -1,   119,   256,   349,
     257,     7,   362,     6,    -1,   104,     4,   256,   349,   257,
       7,   362,     6,    -1,   135,   107,   256,   349,   257,     7,
     362,     6,    -1,   107,   256,   349,   257,     7,   362,   309,
       6,    -1,   136,   107,   256,   349,   257,     7,   362,   309,
       6,    -1,   184,   107,   256,   349,   257,     7,   362,     6,
      -1,   185,   107,   256,   349,   257,     7,   362,     6,    -1,
      13,    14,     6,    -1,    14,   107,   349,     6,    -1,   123,
     107,   256,   349,   257,     7,     5,     5,     5,     6,    -1,
     105,   256,   349,   257,     7,   362,     6,    -1,   106,   256,
     349,   257,     7,   362,     6,    -1,   110,   256,   349,   257,
       7,   362,     6,    -1,   113,   256,   349,   257,     7,   362,
       6,    -1,   117,   256,   349,   257,     7,   362,     6,    -1,
     118,   256,   349,   257,     7,   362,     6,    -1,   111,   256,
     349,   257,     7,   362,     6,    -1,   112,   256,   349,   257,
       7,   362,     6,    -1,   132,   256,   349,   257,     7,   362,
       6,    -1,   159,   256,   349,   257,     7,   362,     6,    -1,
     107,     4,   256,   349,   257,     7,   362,   311,     6,    -1,
     109,   256,   349,   257,     7,   362,     6,    -1,   131,   256,
     349,   257,     7,   362,     6,    -1,   136,   131,   256,   349,
     257,     7,   362,     6,    -1,   139,   315,   256,   349,   257,
       7,   362,     6,    -1,   139,   315,   256,   349,   257,     7,
     362,     4,   260,   361,   261,     6,    -1,    -1,   138,   314,
     313,   256,   308,   257,   288,   362,     6,    -1,   101,    -1,
     104,    -1,   107,    -1,   109,    -1,   120,   260,   349,   261,
      -1,   104,    -1,   107,    -1,   109,    -1,   120,   260,   349,
     261,    -1,   104,    -1,   107,    -1,   120,   260,   349,   261,
      -1,   101,    -1,   104,    -1,   107,    -1,   120,   260,   349,
     261,    -1,   148,   359,   260,   319,   261,    -1,   147,   260,
     359,   265,   359,   265,   349,   261,   260,   319,   261,    -1,
     149,   359,   260,   319,   261,    -1,   150,   260,   359,   265,
     349,   261,   260,   319,   261,    -1,   150,   260,   359,   265,
     359,   261,   260,   319,   261,    -1,   153,   260,   365,   261,
     260,   319,   261,    -1,     4,   260,   319,   261,    -1,   165,
     104,   260,   365,   261,   107,   260,   349,   261,    -1,   162,
     104,   260,   349,   261,   101,   260,   365,   261,     6,    -1,
     162,   104,   256,   349,   257,   260,   365,   261,     6,    -1,
     320,    -1,   318,    -1,    -1,   320,   312,    -1,   320,   314,
     260,   365,   261,     6,    -1,   320,   138,   314,   260,   365,
     261,     6,    -1,   320,   141,   314,   260,   365,   261,     6,
      -1,   320,   314,   260,     8,   261,     6,    -1,   320,   138,
     314,   260,     8,   261,     6,    -1,   152,   135,   256,   349,
     257,     7,   362,     6,    -1,   152,   101,   256,   349,   257,
       7,   260,   361,   261,     6,    -1,   152,   135,   256,   349,
     257,     7,   260,   359,   265,   359,   265,   365,   261,     6,
      -1,   152,   135,   256,   349,   257,     7,   260,   359,   265,
     359,   265,   359,   265,   365,   261,     6,    -1,   152,   105,
     256,   349,   257,     7,   260,   359,   265,   365,   261,     6,
      -1,   152,   111,   256,   349,   257,     7,   260,   359,   265,
     359,   265,   365,   261,     6,    -1,   152,   112,   256,   349,
     257,     7,   260,   359,   265,   359,   265,   365,   261,     6,
      -1,   152,   114,   256,   349,   257,     7,   260,   359,   265,
     359,   265,   365,   261,     6,    -1,   152,   115,   256,   349,
     257,     7,   260,   359,   265,   359,   265,   365,   261,     6,
      -1,   152,     4,   256,   349,   257,     7,   362,     6,    -1,
     152,     4,   256,   349,   257,     7,     5,     6,    -1,   152,
       4,   260,   349,   261,     6,    -1,   163,   260,   320,   261,
      -1,   145,   163,   260,   320,   261,    -1,   163,     4,   260,
     320,   261,    -1,   163,   200,   258,   349,   259,     6,    -1,
     163,     4,   258,   349,   259,     6,    -1,   163,   379,     6,
      -1,   163,     4,     4,     6,    -1,   163,    93,     6,    -1,
     189,   366,   260,   320,   261,    -1,   145,   189,   366,   260,
     320,   261,    -1,   225,   349,   260,   320,   261,    -1,   205,
     260,     8,   261,    -1,   205,     5,     6,    -1,   206,   260,
       8,   261,    -1,   206,     5,     6,    -1,   205,   260,   320,
     261,    -1,   145,   205,   260,   320,   261,    -1,   206,   260,
     320,   261,    -1,   145,   206,   260,   320,   261,    -1,   379,
     370,     6,    -1,    79,   256,   376,   257,     6,    -1,   379,
     379,   258,   349,   259,   369,     6,    -1,   379,   379,   379,
     258,   349,   259,     6,    -1,   379,   349,     6,    -1,   228,
       6,    -1,   143,   256,     4,   257,   262,     4,     6,    -1,
     183,     4,     6,    -1,   198,     6,    -1,   199,     6,    -1,
      74,     6,    -1,    75,     6,    -1,    67,     6,    -1,    67,
     260,   349,   265,   349,   265,   349,   265,   349,   265,   349,
     265,   349,   261,     6,    -1,    68,     6,    -1,    69,     6,
      -1,    84,     6,    -1,    86,   260,   349,   265,   349,   265,
     349,   261,     6,    -1,    86,   260,   349,   265,   349,   265,
     349,   265,   349,   261,     6,    -1,    85,     6,    -1,    85,
     260,   320,   261,    -1,    87,     6,    -1,    88,     6,    -1,
     125,     6,    -1,   126,     6,    -1,   127,   260,   365,   261,
     260,   365,   261,   260,   361,   261,   260,   349,   265,   349,
     261,     6,    -1,   203,   256,   260,   365,   261,   265,   370,
     265,   370,   257,     6,    -1,   191,   256,   349,     8,   349,
     257,    -1,   191,   256,   349,     8,   349,     8,   349,   257,
      -1,   191,     4,   192,   260,   349,     8,   349,   261,    -1,
     191,     4,   192,   260,   349,     8,   349,     8,   349,   261,
      -1,   193,    -1,   204,     4,    -1,   204,   370,    -1,   201,
      -1,   202,   379,     6,    -1,   202,   370,     6,    -1,   194,
     256,   349,   257,    -1,   195,   256,   349,   257,    -1,   196,
      -1,   197,    -1,   151,   359,   260,   320,   261,    -1,   151,
     260,   359,   265,   359,   265,   349,   261,   260,   320,   261,
      -1,   151,   260,   359,   265,   359,   265,   359,   265,   349,
     261,   260,   320,   261,    -1,    -1,   151,   359,   260,   320,
     330,   334,   261,    -1,    -1,   151,   260,   359,   265,   359,
     265,   349,   261,   260,   320,   331,   334,   261,    -1,    -1,
     151,   260,   359,   265,   359,   265,   359,   265,   349,   261,
     260,   320,   332,   334,   261,    -1,    -1,   151,   260,   320,
     333,   334,   261,    -1,   151,   260,   320,   261,   142,   119,
     260,   349,   261,    -1,   131,   362,    -1,   136,   131,   362,
      -1,   133,   260,   365,   261,   260,   365,   261,   260,   365,
     261,    -1,   134,   260,   365,   261,   260,   365,   261,   260,
     365,   261,   260,   365,   261,    -1,   335,    -1,   334,   335,
      -1,   169,   260,   349,   261,     6,    -1,   169,   260,   362,
     265,   362,   261,     6,    -1,   170,     6,    -1,   160,     6,
      -1,   160,   349,     6,    -1,   175,     6,    -1,   175,   177,
       6,    -1,   176,     6,    -1,   176,   177,     6,    -1,   171,
     256,   349,   257,     7,   362,   142,   349,     6,    -1,   142,
       4,   258,   349,   259,     6,    -1,   154,    -1,   155,    -1,
     156,    -1,   157,    -1,   158,    -1,    -1,   163,     6,    -1,
     145,   163,     6,    -1,   163,   349,     6,    -1,   145,   163,
     349,     6,    -1,   336,   260,   320,   337,   261,   260,   320,
     337,   261,    -1,   116,   256,   369,   257,    -1,   336,   256,
     349,   257,     7,   260,   320,   337,   261,   260,   320,   337,
     261,     6,    -1,    -1,   142,     4,   349,    -1,    -1,     4,
      -1,    -1,     7,   362,    -1,    -1,     7,   349,    -1,    -1,
     153,   362,    -1,   121,   122,   363,     7,   349,     6,    -1,
     137,   104,   363,     7,   349,   340,     6,    -1,   137,   107,
     363,   342,   341,     6,    -1,   137,   109,   363,   342,     6,
      -1,   178,   363,     6,    -1,    99,   314,   256,   349,   265,
     349,   257,     6,    -1,   213,   314,   256,   349,   257,     6,
      -1,   166,   107,   260,   365,   261,     7,   349,     6,    -1,
     168,   107,   260,   365,   261,     7,   349,     6,    -1,   160,
     107,   363,   343,     6,    -1,   160,   109,   363,     6,    -1,
     161,   107,   363,     7,   349,     6,    -1,   140,   104,   260,
     365,   261,     7,   260,   365,   261,   344,     6,    -1,   140,
     107,   260,   365,   261,     7,   260,   365,   261,   344,     6,
      -1,   140,   104,   260,   365,   261,     7,   260,   365,   261,
     147,   260,   359,   265,   359,   265,   349,   261,     6,    -1,
     140,   107,   260,   365,   261,     7,   260,   365,   261,   147,
     260,   359,   265,   359,   265,   349,   261,     6,    -1,   140,
     104,   260,   365,   261,     7,   260,   365,   261,   148,   359,
       6,    -1,   140,   107,   260,   365,   261,     7,   260,   365,
     261,   148,   359,     6,    -1,   140,   107,   349,   260,   365,
     261,     7,   349,   260,   365,   261,     6,    -1,   314,   260,
     365,   261,   192,   314,   260,   349,   261,     6,    -1,   167,
     316,   363,     6,    -1,   128,   317,   363,     6,    -1,   129,
     109,   362,     6,    -1,   144,   104,   362,     6,    -1,   139,
     315,   362,     6,    -1,   164,     6,    -1,   164,     4,     6,
      -1,   164,   101,   260,   365,   261,     6,    -1,   214,    -1,
     215,    -1,   216,    -1,   347,     6,    -1,   347,   260,   362,
     261,     6,    -1,   347,   260,   362,   265,   362,   261,     6,
      -1,   347,   256,   362,   257,   260,   362,   265,   362,   261,
       6,    -1,   350,    -1,   256,   349,   257,    -1,   245,   349,
      -1,   244,   349,    -1,   251,   349,    -1,   349,   245,   349,
      -1,   349,   244,   349,    -1,   349,   246,   349,    -1,   349,
     247,   349,    -1,   349,   249,   349,    -1,   349,   250,   349,
      -1,   349,   248,   349,    -1,   349,   255,   349,    -1,   349,
     238,   349,    -1,   349,   239,   349,    -1,   349,   243,   349,
      -1,   349,   242,   349,    -1,   349,   237,   349,    -1,   349,
     236,   349,    -1,   349,   235,   349,    -1,   349,   234,   349,
      -1,   349,   240,   349,    -1,   349,   241,   349,    -1,   349,
     233,   349,     8,   349,    -1,    16,   290,   349,   291,    -1,
      17,   290,   349,   291,    -1,    18,   290,   349,   291,    -1,
      19,   290,   349,   291,    -1,    20,   290,   349,   291,    -1,
      21,   290,   349,   291,    -1,    22,   290,   349,   291,    -1,
      23,   290,   349,   291,    -1,    24,   290,   349,   291,    -1,
      26,   290,   349,   291,    -1,    27,   290,   349,   265,   349,
     291,    -1,    28,   290,   349,   291,    -1,    29,   290,   349,
     291,    -1,    30,   290,   349,   291,    -1,    31,   290,   349,
     291,    -1,    32,   290,   349,   291,    -1,    33,   290,   349,
     291,    -1,    34,   290,   349,   291,    -1,    35,   290,   349,
     291,    -1,    38,   290,   349,   265,   349,   291,    -1,    39,
     290,   349,   265,   349,   291,    -1,    40,   290,   349,   265,
     349,   291,    -1,    25,   290,   349,   291,    -1,    37,   290,
     349,   265,   349,   291,    -1,    36,   290,   349,   265,   349,
     291,    -1,     3,    -1,    10,    -1,    15,    -1,    11,    -1,
      12,    -1,   221,    -1,   222,    -1,   223,    -1,    81,    -1,
      82,    -1,    83,    -1,    -1,    92,   290,   349,   351,   301,
     291,    -1,   354,    -1,   211,   290,   369,   291,    -1,   211,
     290,   369,   265,   349,   291,    -1,   356,    -1,   379,   258,
     349,   259,    -1,   379,   256,   349,   257,    -1,   217,   256,
     356,   257,    -1,   217,   256,   356,   262,   292,   257,    -1,
     219,   256,   356,   352,   257,    -1,   219,   256,   356,   262,
     292,   352,   257,    -1,   219,   256,   356,   290,   349,   291,
     352,   257,    -1,   219,   256,   356,   262,   292,   290,   349,
     291,   352,   257,    -1,   218,   256,   370,   257,    -1,   263,
     379,   290,   291,    -1,   263,   356,   262,   292,   290,   291,
      -1,    95,   290,   379,   291,    -1,    95,   290,   291,    -1,
     379,   289,    -1,   379,   258,   349,   259,   289,    -1,   379,
     256,   349,   257,   289,    -1,   379,   262,   292,    -1,   379,
       9,   379,   262,   292,    -1,   379,   262,   292,   256,   349,
     257,    -1,   379,     9,   379,   262,   292,   256,   349,   257,
      -1,   379,   262,   292,   258,   349,   259,    -1,   379,     9,
     379,   262,   292,   258,   349,   259,    -1,   379,   258,   349,
     259,   262,   292,    -1,   379,   262,   292,   289,    -1,   379,
     258,   349,   259,   262,   292,   289,    -1,   207,   256,   369,
     265,   349,   257,    -1,    59,   256,   362,   265,   362,   257,
      -1,    60,   290,   369,   265,   369,   291,    -1,    58,   290,
     369,   291,    -1,    61,   290,   369,   265,   369,   291,    -1,
      66,   256,   376,   257,    -1,    -1,   265,   349,    -1,    -1,
     265,   369,    -1,    -1,    93,   356,   358,   355,   258,   302,
     259,    -1,   379,    -1,   379,     9,   379,    -1,    96,    -1,
      96,   349,    -1,    -1,   256,   357,   257,    -1,   360,    -1,
     245,   359,    -1,   244,   359,    -1,   359,   245,   359,    -1,
     359,   244,   359,    -1,   260,   349,   265,   349,   265,   349,
     265,   349,   265,   349,   261,    -1,   260,   349,   265,   349,
     265,   349,   265,   349,   261,    -1,   260,   349,   265,   349,
     265,   349,   261,    -1,   256,   349,   265,   349,   265,   349,
     257,    -1,   362,    -1,   361,   265,   362,    -1,   349,    -1,
     364,    -1,   260,   261,    -1,   260,   365,   261,    -1,   245,
     260,   365,   261,    -1,   349,   246,   260,   365,   261,    -1,
     362,    -1,   260,     8,   261,    -1,     5,    -1,   245,   364,
      -1,   349,   246,   364,    -1,   349,     8,   349,    -1,   349,
       8,   349,     8,   349,    -1,   101,   260,   349,   261,    -1,
     101,   260,     8,   261,    -1,   101,     5,    -1,   315,   260,
       8,   261,    -1,   315,     5,    -1,   138,   314,   363,    -1,
     141,   314,   362,    -1,   314,   192,    67,   362,    -1,    67,
     314,   260,   365,   261,    -1,    76,   315,   260,   349,   261,
      -1,    77,   315,   260,   349,   261,    -1,   318,    -1,   329,
      -1,   338,    -1,   379,   290,   291,    -1,   379,   262,   292,
     290,   291,    -1,   379,     9,   379,   262,   292,   290,   291,
      -1,    41,   258,   379,   259,    -1,    41,   258,   364,   259,
      -1,    41,   256,   364,   257,    -1,    41,   290,   260,   365,
     261,   291,    -1,   379,   290,   260,   365,   261,   291,    -1,
      42,   290,   349,   265,   349,   265,   349,   291,    -1,    43,
     290,   349,   265,   349,   265,   349,   291,    -1,    44,   290,
     369,   291,    -1,    45,   290,   349,   265,   349,   265,   349,
     265,   349,   265,   349,   265,   349,   291,    -1,   212,   290,
     364,   291,    -1,    32,   290,   364,   291,    -1,   349,    -1,
     364,    -1,   365,   265,   349,    -1,   365,   265,   364,    -1,
     260,   349,   265,   349,   265,   349,   265,   349,   261,    -1,
     260,   349,   265,   349,   265,   349,   261,    -1,   379,    -1,
       4,   262,   189,   262,     4,    -1,   260,   368,   261,    -1,
     379,   258,   349,   259,   262,   190,    -1,   366,    -1,   368,
     265,   366,    -1,   370,    -1,   379,    -1,   379,   258,   349,
     259,    -1,   379,   256,   349,   257,    -1,   379,   262,   292,
      -1,   379,     9,   379,   262,   292,    -1,   379,   262,   292,
     256,   349,   257,    -1,   379,     9,   379,   262,   292,   256,
     349,   257,    -1,   379,   258,   349,   259,   262,     4,    -1,
     314,   260,   349,   261,    -1,   138,   314,   260,   349,   261,
      -1,     5,    -1,   226,   258,   379,   259,    -1,    70,    -1,
     224,    -1,    78,    -1,    80,    -1,   209,   256,   369,   257,
      -1,   208,   256,   369,   265,   369,   257,    -1,   210,   290,
     369,   291,    -1,   210,   290,   369,   265,   369,   291,    -1,
     220,   256,   356,   353,   257,    -1,   220,   256,   356,   262,
     292,   353,   257,    -1,    51,   290,   376,   291,    -1,    52,
     256,   369,   257,    -1,    53,   256,   369,   257,    -1,    54,
     256,   369,   265,   369,   265,   369,   257,    -1,    49,   290,
     376,   291,    -1,    63,   290,   369,   291,    -1,    64,   290,
     369,   291,    -1,    65,   290,   369,   291,    -1,    62,   290,
     349,   265,   369,   265,   369,   291,    -1,    57,   290,   369,
     265,   349,   265,   349,   291,    -1,    57,   290,   369,   265,
     349,   291,    -1,    50,   290,   369,   291,    -1,    50,   290,
     369,   265,   365,   291,    -1,    71,   290,   369,   291,    -1,
      72,    -1,    73,    -1,    56,   290,   369,   291,    -1,    55,
     290,   369,   291,    -1,    -1,    97,   290,   370,   371,   305,
     291,    -1,    94,   290,   372,   291,    -1,   263,   349,    -1,
     379,     9,   263,   349,    -1,    49,   290,   375,   291,    -1,
     376,    -1,   375,    -1,   260,   376,   261,    -1,   369,    -1,
     377,    -1,   376,   265,   369,    -1,   376,   265,   377,    -1,
     379,   256,   257,    -1,   379,   262,   292,   256,   257,    -1,
     379,     9,   379,   262,   292,   256,   257,    -1,     4,   264,
     260,   349,   261,    -1,   378,   264,   260,   349,   261,    -1,
     227,   258,   369,   259,   264,   260,   349,   261,    -1,     4,
      -1,   378,    -1,   227,   258,   369,   259,    -1
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
    5863,  5869,  5881,  5895,  5905,  5915,  5925,  5937,  5941,  5946,
    5958,  5962,  5966,  5970,  5988,  5996,  6004,  6033,  6043,  6059,
    6070,  6075,  6079,  6083,  6095,  6099,  6111,  6128,  6138,  6142,
    6157,  6162,  6169,  6173,  6178,  6192,  6206,  6210,  6214,  6218,
    6222,  6230,  6236,  6245,  6249,  6253,  6261,  6267,  6273,  6277,
    6284,  6292,  6299,  6308,  6312,  6316,  6331,  6345,  6359,  6371,
    6387,  6396,  6405,  6415,  6426,  6434,  6442,  6446,  6465,  6472,
    6478,  6484,  6491,  6499,  6498,  6508,  6532,  6534,  6540,  6545,
    6547,  6552,  6557,  6562,  6564,  6568,  6580,  6594,  6598,  6605,
    6613,  6621,  6632,  6634,  6637
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
     485,   486,   487,    63,   488,   489,   490,   491,    60,    62,
     492,   493,   494,   495,    43,    45,    42,    47,    37,   124,
      38,    33,   496,   497,   498,    94,    40,    41,    91,    93,
     123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   266,   267,   267,   268,   268,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   270,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   272,   272,   272,   272,
     273,   273,   273,   273,   273,   273,   273,   274,   274,   275,
     275,   277,   278,   276,   279,   279,   281,   280,   282,   282,
     284,   283,   285,   285,   287,   286,   288,   288,   288,   288,
     288,   289,   289,   290,   290,   291,   291,   292,   292,   292,
     292,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   294,   294,   295,
     295,   295,   296,   295,   297,   295,   295,   298,   295,   299,
     299,   300,   300,   300,   301,   301,   302,   302,   303,   303,
     304,   304,   304,   304,   304,   304,   304,   305,   305,   306,
     306,   307,   307,   307,   307,   307,   308,   308,   308,   309,
     309,   309,   309,   310,   310,   311,   311,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   313,   312,   314,   314,   314,   314,   314,
     315,   315,   315,   315,   316,   316,   316,   317,   317,   317,
     317,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   319,   319,   320,   320,   320,   320,   320,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     323,   323,   324,   325,   325,   325,   325,   325,   325,   325,
     325,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   327,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   329,   329,   329,   330,   329,   331,   329,   332,
     329,   333,   329,   329,   329,   329,   329,   329,   334,   334,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   336,   336,   336,   336,   336,   337,   337,   337,   337,
     337,   338,   338,   339,   340,   340,   341,   341,   342,   342,
     343,   343,   344,   344,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   346,
     346,   346,   347,   347,   347,   348,   348,   348,   348,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   351,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   352,   352,   353,   353,
     355,   354,   356,   356,   357,   357,   358,   358,   359,   359,
     359,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   362,   362,   362,   362,   363,   363,   363,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     365,   365,   365,   365,   366,   366,   366,   366,   367,   367,
     368,   368,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   371,   370,   370,   372,   372,   373,   374,
     374,   375,   376,   376,   376,   376,   377,   377,   377,   378,
     378,   378,   379,   379,   379
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
       5,     5,     5,     1,     1,     1,     3,     5,     7,     4,
       4,     4,     6,     6,     8,     8,     4,    14,     4,     4,
       1,     1,     3,     3,     9,     7,     1,     5,     3,     6,
       1,     3,     1,     1,     4,     4,     3,     5,     6,     8,
       6,     4,     5,     1,     4,     1,     1,     1,     1,     4,
       6,     4,     6,     5,     7,     4,     4,     4,     8,     4,
       4,     4,     4,     8,     8,     6,     4,     6,     4,     1,
       1,     4,     4,     0,     6,     4,     2,     4,     4,     1,
       1,     3,     1,     1,     3,     3,     3,     5,     7,     5,
       5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   632,     0,     0,     0,
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
      19,    20,     0,    25,     0,   633,     0,   233,     0,     0,
       0,     0,     0,     0,   283,     0,   285,   286,   281,   282,
       0,   287,   290,   233,     0,   292,   293,   119,   129,   632,
     506,   502,    73,    74,     0,   205,   206,   207,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,     0,   217,   218,   219,     0,
       0,     0,     0,   448,   449,   451,   452,   450,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   456,   457,   458,     0,
       0,   205,   210,   211,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   453,   454,   455,     0,
       0,     0,     0,     0,     0,     0,     0,   543,   544,     0,
     545,   519,   399,   461,   464,   324,   520,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,   210,   211,
       0,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   632,     0,
       0,   233,     0,     0,   389,     0,     0,     0,   214,   215,
       0,     0,     0,     0,     0,     0,   527,     0,     0,   525,
       0,     0,     0,     0,     0,     0,     0,   632,     0,     0,
     566,     0,     0,     0,     0,   279,   280,     0,   583,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   585,     0,   609,   610,   587,   588,     0,     0,
       0,     0,     0,     0,   586,     0,     0,     0,     0,   303,
     304,     0,   233,     0,   233,     0,     0,     0,     0,   502,
       0,   276,     0,     0,   233,   395,     0,     0,    84,     0,
      66,     0,     0,    70,    69,    68,    67,    72,    71,    73,
      74,     0,     0,     0,     0,     0,     0,     0,   572,   502,
       0,   232,     0,   231,     0,   184,     0,     0,   572,   573,
       0,     0,     0,   622,     0,   623,   573,     0,     0,   117,
     117,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     560,   561,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   534,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,     0,   401,   528,   403,     0,   521,     0,     0,
     502,     0,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,   478,     0,
       0,     0,     0,     0,     0,     0,   325,     0,   358,   358,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,   233,   233,     0,   510,   509,     0,     0,
       0,     0,   233,   233,     0,     0,     0,     0,   321,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   360,     0,     0,     0,     0,     0,     0,   233,
     259,     0,     0,   257,   390,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,   278,     0,     0,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,   306,     0,   264,     0,     0,   266,     0,
       0,     0,     0,   401,     0,   233,     0,     0,     0,     0,
       0,     0,     0,   346,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,     0,     0,     0,
       0,    88,    75,    76,     0,     0,     0,   275,    40,   271,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,   234,     0,     0,   185,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,   118,     0,     0,     0,   504,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352,     0,     0,     0,   209,     0,     0,     0,     0,     0,
       0,   385,   386,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   502,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   459,   477,     0,
       0,     0,     0,   537,   538,     0,     0,     0,     0,     0,
     496,     0,   400,   522,     0,     0,     0,     0,   530,     0,
     419,   418,   417,   416,   412,   413,   420,   421,   415,   414,
     405,   404,     0,   406,   529,   407,   410,   408,   409,   411,
     503,     0,     0,   481,     0,   546,     0,     0,     0,     0,
       0,     0,     0,     0,   356,     0,     0,     0,     0,     0,
       0,   388,     0,     0,     0,     0,   387,     0,   233,     0,
       0,     0,     0,     0,   512,   511,     0,     0,     0,     0,
       0,     0,     0,   315,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   374,     0,     0,
       0,   258,     0,     0,     0,   252,     0,     0,     0,     0,
     384,     0,     0,     0,     0,   400,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   308,   309,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,     0,     0,
       0,   498,     0,     0,   263,   267,   265,   269,     0,     0,
     406,     0,   503,   481,   634,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,     0,     0,   400,     0,     0,
       0,    66,     0,     0,    87,     0,    66,    67,     0,     0,
       0,   503,     0,     0,   481,     0,     0,     0,   203,     0,
       0,     0,   629,    28,    26,    27,     0,     0,     0,     0,
       0,   576,    30,     0,    29,     0,     0,   272,   624,   625,
       0,   626,   576,     0,    82,   120,    83,   130,   505,   507,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   562,   563,   220,     9,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   445,   432,
       0,   434,   435,   436,   437,   438,   559,   439,   440,   441,
       0,     0,     0,     0,     0,   551,   550,   549,     0,     0,
       0,   556,     0,   493,     0,     0,     0,   495,     0,     0,
       0,   134,   476,   533,   532,   213,     0,     0,   462,   558,
     467,     0,   473,     0,     0,     0,     0,   523,     0,     0,
     474,   539,   535,     0,     0,     0,     0,   466,   465,    73,
      74,   488,     0,     0,     0,     0,     0,     0,     0,   400,
     354,   359,   357,     0,   367,     0,   156,   157,     0,   213,
       0,   400,     0,     0,     0,     0,   253,     0,   268,   270,
       0,     0,     0,   221,   223,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   328,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,   361,   373,     0,     0,     0,     0,   254,     0,     0,
       0,     0,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,     0,     0,     0,   599,
       0,   606,   595,   596,   597,     0,   612,   611,     0,     0,
     600,   601,   602,   608,   616,   615,     0,   147,     0,   589,
       0,   591,     0,     0,     0,   584,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,   347,     0,     0,     0,
     396,     0,   630,     0,   109,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,   581,    51,     0,     0,     0,    64,     0,    41,
      42,    43,    44,    45,    46,     0,   466,   465,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   574,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   137,   138,     0,     0,     0,
       0,   163,   163,     0,     0,     0,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   540,   541,   542,     0,     0,     0,
       0,     0,   496,   497,     0,   469,     0,     0,   531,   422,
     524,   482,   480,     0,   479,     0,     0,   547,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,   261,     0,
       0,     0,     0,     0,     0,     0,   333,     0,     0,   332,
       0,   335,     0,   337,     0,   322,   329,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     375,     0,     0,   256,   255,   391,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,   567,     0,     0,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   498,   499,   593,     0,   370,   482,     0,
       0,   233,   348,     0,   349,   233,     0,     0,   582,     0,
      94,     0,     0,     0,     0,    92,     0,   570,     0,   107,
       0,    99,   101,     0,     0,     0,    89,     0,     0,     0,
       0,     0,    36,   482,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    32,     0,   577,
       0,     0,    34,    33,     0,   577,   627,     0,     0,   121,
     126,     0,     0,     0,   140,   145,   146,   141,   142,   501,
       0,    85,     0,    86,   167,     0,     0,     0,     0,   168,
     187,   188,   165,     0,     0,     0,   169,   198,   189,   193,
     194,   190,   191,   192,   177,     0,     0,   433,   447,   446,
     442,   443,   444,   552,     0,     0,     0,   491,   492,   494,
     135,   460,   490,   463,   468,     0,     0,   496,   199,   475,
      73,    74,     0,   487,   483,   485,   553,   195,     0,     0,
       0,   159,     0,     0,   365,     0,   158,     0,     0,     0,
       0,     0,     0,   277,     0,     0,     0,     0,   233,   233,
       0,     0,   334,   519,     0,     0,   336,   338,     0,     0,
     316,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   196,     0,     0,     0,     0,     0,     0,     0,
     174,     0,   175,     0,     0,     0,     0,   110,   114,     0,
     607,     0,     0,   605,     0,   617,     0,     0,   148,   149,
     614,   590,   592,     0,     0,     0,     0,     0,     0,   346,
     350,   346,     0,   397,    93,     0,     0,    66,     0,     0,
      91,     0,   568,     0,     0,     0,     0,     0,     0,   620,
     619,     0,     0,     0,     0,     0,   517,     0,     0,    77,
     273,   483,   274,     0,     0,     0,     0,     0,   238,   235,
       0,     0,   580,   578,     0,     0,     0,     0,   122,   127,
       0,     0,     0,   560,   561,   139,   369,   164,   172,   173,
     178,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,   470,     0,     0,     0,   548,   489,     0,
       0,   179,     0,   200,   355,     0,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,   516,   515,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
       0,     0,   371,   372,    39,   182,   183,     0,   565,     0,
       0,   300,   299,     0,     0,     0,     0,     0,     0,   151,
     152,   155,   154,   153,     0,   594,     0,   631,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,   571,     0,
       0,     0,    96,     0,     0,     0,    47,     0,     0,     0,
       0,     0,    49,     0,   239,   236,   237,    35,     0,     0,
     628,   288,     0,   134,   147,     0,     0,   144,     0,     0,
       0,   166,   197,     0,     0,     0,     0,     0,   554,   555,
       0,   496,   471,   484,   486,     0,     0,   181,   204,     0,
       0,     0,   362,   362,     0,   115,   116,   233,     0,   224,
     225,   323,     0,   330,     0,     0,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,   228,     0,     0,
       0,     0,   111,   112,   598,   604,   603,   150,     0,     0,
       0,   351,     0,     0,   108,   100,   102,     0,    90,   621,
      97,    98,    52,     0,     0,     0,     0,   518,     0,     0,
     484,   579,     0,     0,     0,     0,   124,   618,     0,   131,
       0,     0,     0,     0,   186,     0,     0,     0,   326,     0,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   514,     0,   340,     0,     0,   317,     0,   241,
       0,     0,     0,     0,     0,     0,   229,     0,   564,   301,
       0,     0,   383,   233,   398,     0,   569,     0,    48,     0,
       0,     0,    65,    50,     0,   289,   123,   128,   134,     0,
       0,   161,   162,   160,     0,     0,   472,     0,     0,     0,
       0,   363,   376,     0,     0,   377,     0,   222,     0,   331,
       0,   313,     0,   233,     0,     0,     0,     0,     0,     0,
     176,   113,   297,   346,   106,     0,     0,     0,     0,     0,
       0,   132,   133,     0,     0,     0,   202,     0,   380,     0,
     381,   382,   513,     0,     0,   319,   244,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,    62,     0,     0,
     125,     0,     0,   327,     0,     0,   339,   318,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
     248,     0,   242,   353,    53,     0,    60,     0,   284,     0,
     557,     0,     0,   320,     0,     0,    54,     0,     0,   296,
       0,     0,   243,     0,     0,     0,     0,     0,     0,    57,
      55,     0,    58,     0,   378,   379,     0,     0,    63,    61,
      59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   121,  1096,   122,   123,  1080,  1945,  1951,
    1379,  1597,  2107,  2235,  1380,  2208,  2251,  1381,  2237,  1382,
    1383,  1601,   452,   608,   609,  1165,  1693,   124,   805,   479,
    1963,  2118,  1964,   480,  1832,  1458,  1414,  1415,  1416,  1560,
    1768,  1769,  1235,  1655,  1646,  1842,   781,   620,   285,   286,
     361,   210,   287,   462,   463,   128,   129,   130,   131,   132,
     133,   134,   135,   288,  1269,  2142,  2199,   971,  1265,  1266,
     289,  1059,   290,   139,  1486,  1233,   944,   986,  2076,   140,
     141,   142,   143,   291,   292,  1191,  1206,  1334,   293,   810,
     294,   809,   482,   637,   329,  1805,   369,   370,   296,   578,
     379,  1363,  1588,   473,   468,  1327,  1035,  1636,  1798,  1799,
    1020,   475,   145,   429
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1927
static const yytype_int16 yypact[] =
{
   13661,    47,   110, 13865, -1927, -1927,   -20,   114,   -31,  -137,
     -88,   -45,    18,   141,   152,   193,   225,   -10,   255,    35,
      -5,   277,   367,    31,   144,    14,   138,   672,   138,   128,
     165,   176,    43,   210,   222,    60,   229,   264,   298,   324,
     337,   344,   369,   392,   395,   402,   166,   330,   466,   659,
     669,   422,   483,   598,   457,  6772,   503,   520,   530,   724,
     -59,   728,   672,   414,    75,   583,   771,  -112,   580,  -144,
    -144,   592,   126,   663,   607, -1927, -1927, -1927, -1927, -1927,
     587,   459,   795,   774,    12,    64,   800,   811,   106,   821,
     908,   931,   937,  5756,   945,   -71,   -67,   702,    24,    63,
   -1927,   704,   723, -1927, -1927,   985,  1009,   734, -1927,  8669,
     761,  6637,    22,    25,   672, -1927, -1927, -1927, 11936,   760,
    1014, -1927, -1927, -1927, -1927, -1927,   767, -1927, -1927, -1927,
   -1927, -1927, -1927, -1927, -1927, -1927, -1927,   139, -1927, -1927,
   -1927, -1927,    15, -1927,  1026,   769,  4911,    80,   803,  1033,
   11936, 14048, 14048, 14048, -1927, 11936, -1927, -1927, -1927, -1927,
   14048, -1927, -1927, -1927, 11936, -1927, -1927, -1927, -1927,   791,
     809,  1062, -1927, -1927,  6891, -1927, -1927, -1927, -1927,   828,
      14, 11936, 11936, 11936,   833, 11936, 11936, 11936,   843, 11936,
   11936, 11936, 11936, 11936, 11936, 11936, 14048, 11936, 11936, 11936,
   11936,  5756,   854, -1927, -1927,  9556, -1927, -1927, -1927,   816,
    5756,  7026, 14048, -1927, -1927, -1927, -1927, -1927,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   408,   138,   138,   138,   138,   138,   859,
     138,   138,   862,   672,   241,   241, -1927, -1927, -1927,   138,
     138,    30,   936,   950,   961,   894,  7026,  1025,   672,   672,
     901,   138,   138,   902,   903,   924, -1927, -1927, -1927, 11936,
    7280, 11936, 11936,  7534,    14,   995,    33, -1927, -1927,   928,
   -1927,  4970, -1927, -1927, -1927, -1927, -1927,   182, 11936,  9556,
    9556,   933,   934,  7788,  5756,  5756,  5756, -1927, -1927, -1927,
     935, -1927,   938,   939,  8042,   940, 10498,  1189,  7026,   941,
      24,   942,   943,  -144,  -144,  -144, 11936, 11936,   179, -1927,
     271,  -144, 10584,   283,   205,   948,   951,   954,   956,   957,
     958,   959,  9556, 11936,  5756,  5756,  5756,   427,     9,  1188,
     960, -1927,  1190,  1191, -1927,   946,   977,   979, -1927, -1927,
     980,  5756,   982,   962,   987,   988, -1927, 11936,  6010, -1927,
    1193,  1210,   963, 11936,   991, 11936, 11936,   430, 11936,   983,
   -1927,  1052, 11936, 11936, 11936, -1927, -1927, 11936, -1927,   138,
     138,   138,   992,   993,   994,   138,   138,   138,   138,   138,
     138,   138, -1927,   138, -1927, -1927, -1927, -1927,   138,   138,
     997,   998,   138,   999, -1927,  1000,  1211,  1245,   996, -1927,
   -1927,  1251,  1252,  1255,  1254,  1010,   138, 11936, 15277,   192,
   14048, -1927,  9556, 11936, -1927, -1927,  7026,  7026, -1927,  1005,
    6891,   672,  1261, -1927, -1927, -1927, -1927, -1927, -1927, 11936,
   11936,   471,  7026,  1263,   594,  1011,  1309,  1012,  1267,    52,
    1015, -1927,  1013, 14187, 11936, -1927,  1628,  -178, -1927,    51,
     -51,   186,  7467, -1927,   190, -1927,    82, 12345,  7721,  -125,
     -41,  1180, -1927,    14,  1016, 11936,  1017, 15793, 15818, 15843,
   11936, 15868, 15893, 15918, 11936, 15943, 15968, 15993, 16018, 16043,
   16068, 16093,  1022, 16118, 16143, 16168, 14378,  1273, 11936,  9556,
    5167, -1927,   432, 11936,  1277,  1278,  1028, 11936, 11936, 11936,
   11936, 11936, 11936, 11936, 11936, 11936, 11936, 11936, 11936, 11936,
   11936, 11936, 11936,  9556, 11936, 11936, 11936, 11936, 11936, 11936,
   11936, 11936,  9556,  9556,  1027, 11936, 11936, 14048, 11936, 14048,
    7026, 14048, 14048, 14048,  1029,  1031,  1032, 11936,    29, -1927,
   10838, 11936,  7026,  5756,  7026, 14048, 14048,  9556,    14,  6891,
      14,  1038,  9556,  1038, -1927,  1038, 16193, -1927,   458,  1024,
      77,  1221, -1927,  1286, 11936, 11936, 11936, 11936, 11936, 11936,
   11936, 11936, 11936, 11936, 11936, 11936, 11936, 11936,  8296, 11936,
   11936, 11936, 11936, 11936,    14, 11936, 11936,    62, -1927,   667,
   16218,   504,   521, 11936, 11936, 11936, -1927,  1289,  1292,  1292,
    1044, 11936, 11936, 11936, 11936,  1295,  9556,  9556, 15305,  1046,
    1298, -1927,  1045, -1927, -1927,  -190, -1927, -1927,  7975,  8229,
    -144,  -144,    80,    80,  -187, 10584, 10584, 11936, 12404,  -182,
   -1927, 11936, 11936, 11936, 11936, 11936, 11936, 11936, 11936, 11936,
     535, 16243,  1299,  1302,  1303, 11936, 11936,  1305, 11936, -1927,
   -1927, 11936, 12512, -1927, -1927,  9556,  9556,  9556, 11936,  1307,
    9556, 11936, 11936, 11936, 16268,  1048, -1927, -1927, 11936, 16293,
   11936, 16318, 16343,  1125,  8732, -1927,  1057,  5439, 16368, 16393,
   15388, 14048, 14048, 14048, 14048, 14048, 14048, 14048, 14048, 14048,
   11936, 14048, 14048, 14048, 14048,    11,  6891, 14048, 14048, 14048,
      14,    14, -1927, -1927,  9556, -1927,  1058, 12571, -1927,  1059,
   12679, 11936, 11936,  1038, 11936, -1927,    14, 11936, 11936,    62,
    1063,   584, 16418, 14101,  1061,   585, 11936,  1315,  1064,  7026,
   16443, 15415, -1927, -1927, -1927, -1927, -1927,  1066,  1316,   242,
    1320, -1927, -1927, -1927,  9556,   137, 11936, -1927, -1927, -1927,
      14, 11936, 11936,    62,  1071, -1927,  1075,   -58,   672,   414,
     672, -1927,  1072, 14407, -1927,   120,  9556,    14, 11936, 11936,
      62,  1327,  9556,  1328,  9556, 11936,  1329, 14048,    14, 10924,
      62, -1927, 11936,  1330, -1927,    14,  1331, 14048, 11936,  1082,
    1083, -1927, 11936,  8981,  6891,  1333,  1337,  1340, 16468,  1341,
    1342,  1343, 16493,  1345,  1347,  1348,  1350,  1353,  1354,  1355,
   -1927,  1356,  1357,  1358, -1927, 11936, 16518,  9556,  1123,  9556,
   14436, -1927, -1927,  1379, 15361, 15361, 15361, 15361, 15361, 15361,
   15361, 15361, 15361, 15361, 15361,  9235, 15361, 15361, 15361, 15361,
     651,   463, 15361, 15361, 15361,  9489,  9836, 10185, 10447, 10529,
    5167,  1129,  1131,    93,  9556, 10787, 10869,   463, 11204,   463,
    1127,  1128,  1130,   267,  9556, 11936, 11936, 17468, -1927,   463,
    1133, 14465, 14494, -1927, -1927,  1134,   373,   463,  -188,  1139,
     123,   600,  1381, -1927,    62,   463,  7026,  1136,  5689,  5943,
    1132,   726,   986,   986,   740,   740,   740,   740,   740,   740,
     578,   578,  9556,   -69, -1927,   -69,   -69,  1038,  1038,  1038,
    1138, 16543, 15442,   502,  9556, -1927,  1391,  1141,  1142, 16568,
   16593, 16618, 11936,  7026,  1399,  1398, 10249, 16643, 14523, 16668,
   16693, -1927,   609,   611,  9556,  1143, -1927, 12738, -1927, 12846,
   12905,  -144, 11936, 11936, -1927, -1927,  1145,  1146, 10584,  2820,
    1269,   763,  -144, 13013, 16718, 14552, 16743, 16768, 16793, 16818,
   16843, 16868, 16893,  1149,  1405, 11936,  1408, -1927, 11936, 16918,
   14581, -1927, 15469, 13072, 15496, -1927,   612,   648,   650, 14610,
   -1927,   655, 15523, 15550, 11464, -1927, -1927, 16943,  1409, 16968,
    1410,  1411,  1153, 11936, 13180, 11936, 11936, -1927, -1927,    32,
     398,   419,   398,  1162,  1164,  1157,   463,   463,  1158, 11546,
     463,   463,   463,   463, 11936,   463,  1416, -1927,  1161,  1170,
     528,    72,  1169,   656, -1927, -1927, -1927, -1927, 16993, 15361,
     -69, 13239,  1167,   555,  1166,  1239,  1425,  1270, 11173,  1173,
    1175,  1430,  7026, 14639, -1927, 11936,  1431,   258,   100,    62,
      27,  6891, 11936,  1432, -1927,   664,  1390,  1392,  7026, 14668,
     196,  1178, 17018, 15577,   699, 11936, 11936,  1192,  1184,  1194,
    1185,  8550, -1927, -1927, -1927, -1927, 14048,   288,  1187, 17043,
   15604,  1195, -1927,   326, -1927,   374, 11799, -1927, -1927, -1927,
    1196, -1927,  1197, 11881, -1927,    10, -1927, -1927, 17468, -1927,
      67, 15361, 11936,   463,  -144,  7026,  7026,  1439,  7026,  7026,
    7026,  1445,  7026,  7026,  7026,  7026,  7026,  7026,  7026,  7026,
    7026,  7026,  1853,  1447,  9556,  5167, -1927, -1927, -1927, -1927,
   -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927,
   11936, -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927,
   11936, 11936, 11936, 11936, 11936, -1927, -1927, -1927,   681, 11936,
   11936, -1927, 11936, -1927,  7026, 14048, 14048, -1927,   682, 14697,
   14726,  1198, -1927, -1927, -1927,  1264, 11936, 11936, -1927, -1927,
   -1927,    62, -1927,    62, 11936, 11936,  1200, -1927,  7026,   138,
   -1927, -1927, -1927, 11936, 11936,   689,    62,   238,   332, 11936,
   11936, -1927,   463,   733,  7026,  9556,  9556,  1448,  1452,  1454,
    2794, -1927, -1927,  1456, -1927,  1207, 17468,  1201,  1458, -1927,
    1460,  1461,  1462,  1463,   736,    84, -1927, 13347, -1927, -1927,
    -148, 12154, 12331, -1927, -1927, 14755,   -57,  1352,  1468, 11266,
    1215,  1470,  1222,    26,    28,    -9, -1927,  -120, -1927,   763,
    1475,  1477,  1478,  1479,  1483,  1484,  1485,  1486,  1487,    80,
    7026, 17468, -1927,  1915,  1235,  1395,  1491, -1927,  1492,  1493,
    1394,  1497, -1927,  1499,  1501,  1502, 11936,  1503,  7026,  1504,
    7026,  7026,  1505, 12498, -1927,  6197,   929,    62,    62, -1927,
    9556, -1927, -1927, -1927, -1927, 14048, -1927, -1927, 11936, 14048,
   -1927, -1927, -1927, -1927, 17468, -1927,  1249,  1248, 14048, -1927,
   14048, -1927,    62, 14048,  1257, -1927,  1250,  1511, -1927,    62,
   11936, 11936,  1258,   672,  1259, 11515, -1927,  1969,  1260,  7026,
   -1927,  1262, -1927, 14784, -1927, -1927, 11936,  1515,   652, 11936,
    1516,  1518,    24,  1520,  1271,  1521,  2105, -1927,   463,   138,
     138,  1524, -1927, -1927,  1275,  1276,  1274, -1927,  1527, -1927,
   -1927, -1927, -1927, -1927, -1927,    62,  -131,  4496, 11936, 15631,
   17068, 11936,  8799, 11936,  9556,  1279,   738,  1529,   124,    62,
   -1927,  1301, 11936,  1530,  1531, 11936,    62, 11601, 11936,  9805,
     463,  5234, 11936, 11936,  1306,  1296, -1927,  1532, 17093,  1554,
      76,  1433,  1433,  7026,  1560,  1561,  1563,  7026,  -100,  1565,
    1566,  1567,  1568,  1569,  1570,  1571,  1572,  1573, -1927,  1575,
     739, 15361, 15361, 15361, 15361, 15361, 15361,   463, 12665, 12832,
   12999,  1324,   463,   463, -1927, -1927, -1927,    67,   463, 17118,
   15361,  1325,   172, 17468, 15361, -1927,  1578,   463, 17468, 17468,
   -1927,   493, -1927,    62, -1927, 17143, 15658, -1927,   463,  1579,
     741,   746,  7026,  7026,  7026,  1582,  1581, -1927,   252, 11936,
    7026,  7026,  7026,  1334,  1335,  1583,  1587,  1589, -1927, 11936,
   11936, 11936,  1338,  1339,  1344,  1349, -1927,  2672,  7026, -1927,
   11936, -1927,  1594, -1927,  1595, -1927, -1927, 10584,   510,  6264,
   -1927,  1346,  1351,  1360,  1361,  1362,  1363,  9048,  1365,  1596,
   -1927,  9556,  1364, -1927, -1927, -1927,  1367, 11936, 11936, -1927,
   -1927, 15685,  7026,  1599,  7026,  1602,  1400, -1927, 11936, 11936,
   11936, -1927,  1603,   628,   540,  1366,  2447,  1368, 11936,    21,
     463,  1332,   463,  1370, -1927, -1927,  6891, -1927,   514, 11936,
    1369, -1927, -1927,  3073, -1927, -1927,  1372,  1604, -1927,  3214,
   -1927,  1377,  1605,   415,  3422, -1927,    24, -1927,   747, -1927,
   11936, -1927, -1927,   252, 12156, 12218, -1927,  1384, 11936, 11936,
    7026,  1382, -1927,     4,   105,  1607, 17168,  1608,  1381, 17193,
    1385,   748, 17218,   749,  1610,  1622, -1927, -1927, 14048,  1387,
    1645, 17243, -1927, -1927, 13166,  1396, -1927,  3614,  5502, 17468,
   -1927,  1644,   138,  7534, -1927, -1927, -1927, 17468, 17468, -1927,
      67, -1927,  1647, -1927, -1927,  -144,  1648,  1649,  1650, -1927,
   -1927, -1927,  1517,    70,  1552,  1652, -1927, -1927, -1927, -1927,
   -1927, -1927, -1927, -1927, -1927,  1655,  1401, -1927, -1927, -1927,
   -1927, -1927, -1927, -1927, 11936, 11936, 11936, -1927, -1927, -1927,
    1296, -1927, -1927, -1927, -1927, 11936,  1406,  1397, -1927, -1927,
   11936, 11936,   463,   238, -1927, -1927, -1927, -1927,  1404,  1412,
    1659,  -100,  1662, 11936, -1927,  7026, 17468,  1541,  1542,   808,
    9556,  9556, 11936, -1927, 10249, 14813, 17268,  4141,    80,    80,
   11936, 11936, -1927,   170,  1420, 17293, -1927, -1927, 14842,  -113,
   -1927,  1680,  1681,  7026,  -144,  -144,  -144,  -144,  -144,  6518,
    1682, -1927, -1927,   777,  9556, 11936,  3907,  3930,  1683,  1684,
   -1927,  1685, -1927,  7026,  6959,   372, 17318, -1927, -1927,  9900,
   -1927, 14048, 11936, -1927, 14048, 17468, 10154,  6891,  1427, -1927,
   -1927, -1927, -1927,  1437,  1434, 11936, 11936, 14871, 11936, 14101,
   -1927, 14101,  7026, -1927, -1927,    62,    27,  6891, 11936,  1690,
   -1927,  1691, -1927,    24, 15712,  7026, 14048,  1692,   463, -1927,
    1438,   463, 11936, 13333, 13446,   779, -1927, 11936, 11936,  1446,
   -1927,  1449, -1927,  1454,  1699,  1704,  1461,  1705, -1927, -1927,
    1706, 11936, -1927, -1927, 11936, 11850,  1707, 11936, -1927, -1927,
    1455, 12218,   780,  3582,  1709, -1927, -1927,   297, -1927, -1927,
   -1927,  1574,  1713,  1464,  1466,  1467, -1927,  1717,  7026, 15361,
   15361, 13659, 15361, -1927,  1471, 17343, 15739, -1927, -1927,  9556,
    9556, -1927,  1723, -1927, 17468,  1725, 11936, 11936,  1472, -1927,
     785,   786, 15333,  4042,  1727,  1474, -1927, -1927, 11936,  1476,
    1481, 14900, 15766,  1729,  7026,  1716,  1480, 11936, -1927, -1927,
     787,  -109,  -106,   -81,   -48,   -22,  9302,    -8, -1927,  1732,
     788, 14929, -1927, -1927, -1927, -1927, -1927,  1556, -1927, 11936,
   11936, -1927, -1927,  9556,  4191,  1733,  1488, 15361,   463, 17468,
   -1927, -1927, -1927, -1927,    21, -1927,  6891, -1927, 14958,  1490,
    1494,  1495,  1737,  1740,  1741,  4491, -1927, -1927, -1927,  1498,
    1742,   796, -1927,  1746,  1747,   397, 17468, 11936, 11936,  1506,
    7026,   797, 17468, 17368, -1927, -1927, -1927, -1927, 17393, 14114,
   -1927, -1927, 14987,  1198,  1248,  7026,   463, -1927, 11936,  6891,
      14, -1927, -1927,  9556,  9556, 11936,  1748,   799, -1927, -1927,
   11936,  1397, -1927, -1927, -1927,   805,   807, -1927, -1927,  4548,
    4571,  7026,   543,   591,  9556, -1927, -1927,    80,  7213, -1927,
   -1927, -1927,  1751, -1927,  1507,  7026, -1927, 15016,  1753,  9556,
    -144,  -144,  -144,  -144,  -144, -1927,  1756, -1927, 11936, 15045,
   15074,   812, -1927, -1927, -1927, -1927, -1927, -1927,  1510,  1757,
    1509, -1927,  1758,    24, -1927, -1927, -1927,  1580, -1927, -1927,
   -1927, -1927, -1927, 11936, 14147, 14180,  7026, -1927,  1765, 11936,
    1512, -1927, 11936,  1767,  1513,  1514, -1927, -1927,  4653, -1927,
    1522,   817,   820, 15103, -1927,  1525, 14213,  1519, -1927,  1526,
   -1927, -1927,   822,  1528,  -144,  7026,  1771,  1534,  -144,  1774,
     825,  1535, -1927, 11936, -1927,  1775,  1640, 13406,  1537, -1927,
     831,   197,   214,   232,   249,   254, -1927,  4595, -1927, -1927,
    1783,  1785, -1927, -1927, -1927,  1789, -1927,  1538, 17468, 11936,
   11936,   836, -1927, 17468, 14246, -1927, -1927, -1927,  1198,  6891,
    1543, -1927, -1927, -1927, 11936, 11936, -1927,  9556,  1793,  -144,
      83, -1927, -1927,  -144,   112, -1927,  1795, -1927, 15132, -1927,
   11936, -1927,   763, -1927,  1797,  9556,  9556,  9556,  9556,  9302,
   -1927, -1927, -1927, 14101, -1927, 11936, 17418, 14279,    38, 11936,
    1544, -1927, -1927, 14312, 14345,   839, -1927,   260, -1927,   293,
   -1927, -1927, -1927,  4622,   646, 13514, -1927,   841,   846,   847,
     848,   312,   855,  1545,   856, -1927, 11936, -1927,  7026, 15161,
   -1927, 11936, 11936, -1927,  -144,  -144, -1927, -1927, -1927,   763,
    1801,  1802,  1803,  1804,  9556,  1805,  1806,  1807,  1555, 17443,
     879,  1808, 15190, 15361,   334,   384,   687, -1927, -1927, -1927,
   -1927,   882, -1927, -1927, -1927, 14048, -1927,  1557, -1927,  1810,
   -1927, 11936, 11936, -1927,  1812,   884, -1927,  1562,  7026, -1927,
   15219, 15248, -1927,  1814, 14048, 14048,   887,  1818,  1819, -1927,
   -1927,   890, -1927,  1820, -1927, -1927,  1821, 14048, -1927, -1927,
   -1927
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1927, -1927, -1927, -1927,   431, -1927, -1927, -1927, -1927,  -325,
   -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927, -1927,
   -1927, -1927,  -745,  -123,  2212,  3632,  -147, -1927,  1371, -1927,
   -1927, -1927, -1927, -1927, -1927, -1926, -1927,   375,   191,  -130,
   -1927,   -91, -1927,   134,   416, -1927,  1833, -1927,    23,   -34,
   -1927, -1927,    -1,  -639,   -98, -1927, -1927, -1927, -1927, -1927,
   -1927, -1927,   757,  1837, -1927, -1927, -1927, -1927, -1263, -1260,
    1840, -1770,  1841, -1927, -1927, -1927,  1227, -1927,  -146, -1927,
   -1927, -1927, -1927,  2213, -1927, -1927, -1455,   285,  1846, -1927,
      34, -1927, -1927,   178, -1927, -1721,   541,  -191,  2562,  2911,
    -319,    66, -1927,   317,   -66, -1927, -1927,    87,   263, -1720,
    -152,  1053, -1927,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -581
static const yytype_int16 yytable[] =
{
     146,   632,   127,   966,   967,  1516,  1518,  1686,   474,  1929,
     507,  1930,  1890,   667,  1072,   169,   348,  1409,   169,   514,
    1078,   435,   171,   453,   154,  1766,   126,   421,   377,   314,
     423,   169,  1511,   169,  1513,   559,   372,  2054,   582,  1307,
     374,   162,  1653,   416,  2187,   420,  1922,   184,   302,   302,
     179,   319,   297,     4,   640,   641,   169,   640,   641,   170,
     787,   770,   640,   641,   188,   477,   752,   381,   353,  1200,
     354,  1411,   303,  1087,  1201,   961,   150,   320,   968,   785,
     458,   352,  1644,   972,   460,   307,   483,   786,  1496,  2168,
     297,   798,  1654,   321,   322,   380,   640,   641,   753,   754,
     324,   325,   604,  1412,  1413,   349,   417,  1355,   484,  1809,
       5,  1966,   326,   617,   618,   619,   327,  1499,  2170,   151,
     753,   754,   447,   448,   640,   641,  1093,  1977,   149,  -575,
    1617,   640,   641,  1258,   803,   640,   641,   425,   640,   641,
     804,   753,   754,   459,  1076,  1517,   461,   156,   469,   469,
     469,  1259,  1887,   662,   663,   664,  2009,   476,   157,  2010,
    1260,  1261,  1262,   640,   641,   355,  1263,  1264,   152,   455,
     679,  1843,   755,   756,   455,   455,   455,   486,   584,   315,
     601,   602,   316,   455,  2011,   373,   603,   640,   641,   375,
    1844,   604,  2160,   469,   755,   756,   640,   641,   297,   158,
    1373,   736,   297,  1512,  1503,  1514,   791,   297,   297,   469,
     358,   153,   350,   359,   792,   755,   756,  2012,   806,   455,
     555,   556,   640,   641,   804,  1767,   360,    68,    69,    70,
      71,   159,  1854,    74,   648,   455,   640,   641,   119,   119,
     147,   119,    83,  2013,   148,    86,   160,   328,   330,  1071,
     333,   119,  1515,   672,   119,   164,   119,  2014,  1516,  1355,
    1808,   161,  1776,   297,  -577,  1355,   172,   668,   173,   669,
    2072,   436,   351,   148,  1034,   437,   554,   297,   155,   119,
     297,   580,   422,   165,   378,   424,   762,  1362,   763,   167,
     560,   563,   564,   583,  1308,   163,   297,   297,  2188,   185,
     297,   297,   297,   297,   759,   447,   448,   788,   771,   789,
     772,   297,  -573,   790,   773,   297,   189,   380,   579,   382,
     640,   641,  1356,  1359,   727,  2111,   730,   640,   641,   443,
     444,   445,   446,   172,  1332,   173,   743,  1333,   799,   297,
     789,   297,   297,   297,   800,   308,   447,   448,   309,   605,
     311,   606,  1177,   447,   448,   607,   640,   641,   297,  1094,
    1095,   312,  1358,  1094,  1095,   297,   443,   444,   445,  1077,
     324,   325,   893,   166,   747,  1374,  1375,  1376,  1377,   172,
    1910,   173,   326,  2183,   181,  1203,   332,    99,  1204,   100,
     101,   102,   103,   104,   172,   433,   173,   108,   109,   434,
     111,   883,   168,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   182,  1787,   640,   641,   603,   200,   469,   172,   297,
     173,  1883,   183,   297,   297,   447,   448,  1204,   605,   642,
     606,   640,   641,   793,   607,   447,   448,   796,   737,   297,
     738,   794,   201,   455,   739,   797,   774,  1378,   640,   641,
     933,   651,  2145,   457,   748,   652,   186,  2210,   467,   470,
     471,   443,   444,   445,   446,   752,   640,   641,   187,  2146,
     811,   443,   444,   445,   446,   190,   782,   443,   444,   445,
     446,   447,   448,   640,   641,   447,   448,  2147,   640,   641,
     782,   635,   636,   899,   640,   641,   297,   753,   754,   644,
     649,   447,   448,   502,  2148,   640,   641,  2246,   308,  2149,
     191,   309,   310,   311,  1187,  2194,  2067,   640,   641,   516,
     297,   643,   797,   957,   312,   959,   960,   640,   641,   297,
     873,   640,   641,   650,   469,  1398,   469,   297,   469,   469,
     476,  1022,   973,   839,   192,   889,   640,   641,  2195,   297,
     297,   297,   469,   469,   297,   171,   344,   171,   345,   297,
     455,   993,   455,   202,   455,   455,   455,  2204,   640,   641,
     193,   755,   756,  1403,   206,   447,   448,   207,   455,   455,
     208,   839,  1053,   194,  1473,   297,   295,  1014,   313,  2231,
     195,   930,   898,   209,   900,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,   297,   297,   196,  1084,   603,   640,   641,
     762,  1404,   763,  1911,  1758,  1759,  1073,  1051,  1197,   839,
    1528,   461,   461,  1101,   443,   444,   445,   446,   197,  2232,
    1037,   198,  1258,  1112,  2042,   762,   752,   763,   199,   584,
     757,   758,  2043,   797,   542,   203,   543,   334,   447,   448,
    1259,   782,   297,   297,   297,   204,   762,   297,   763,  1260,
    1261,  1262,   205,   665,  1310,  1263,  1264,   666,   753,   754,
    2073,  2074,   693,   838,   148,   782,  2075,   839,   476,   469,
     476,   469,   469,   469,   469,   469,   469,   211,   469,   469,
     469,   469,  1036,   212,   469,   469,   469,   171,  1042,   903,
     762,   297,   763,   839,   455,   455,   455,   455,   455,   455,
     455,   455,   455,  1052,   455,   455,   455,   455,  2077,  2078,
     455,   455,   455,  1705,  2075,  1089,   297,   740,  1123,  1690,
     782,  1691,   515,   782,  1041,   447,   448,  1209,  1219,   298,
    1220,   297,   755,   756,   335,   937,   782,  1081,   336,   839,
    1775,  1730,  1776,   175,   337,   338,   176,   339,   340,   177,
     299,   178,   938,   297,  1098,   762,   839,   763,  1258,   297,
     300,   297,    46,  1330,   476,  1110,   983,   762,   341,   763,
     839,  1088,  1115,  1090,   469,   839,  1259,   295,   447,   448,
    1221,  1340,  1868,  1341,  1869,  1260,  1261,  1262,   964,   965,
     455,  1263,  1264,   636,   734,   599,   600,   601,   602,  1258,
     455,   301,   304,   603,   297,   305,   297,   306,  1788,   317,
     323,  1581,  1582,   343,   616,  1055,  1061,  1259,  1795,   839,
    1062,   762,   331,   763,   764,   625,  1260,  1261,  1262,   630,
    1247,  1207,  1263,  1264,   877,   839,   879,   342,   881,   882,
    1242,   297,  1243,  1289,   839,   318,   839,   839,   347,  2174,
    1237,   297,   895,   896,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   837,   599,   600,
     601,   602,   346,   297,   356,  1258,   603,  2197,   762,  1290,
     763,  1291,   363,   839,  1516,   839,  1293,  1336,   357,   297,
     839,   839,  1361,  1259,   762,  1368,   763,   934,   362,   839,
    1221,   297,  1260,  1261,  1262,   364,  2216,  1550,  1263,  1264,
     297,   365,  1447,  1454,  1357,  1360,   839,   839,  2233,   371,
    1470,   297,   447,   448,   839,  1388,  1516,  1341,   376,  -576,
     383,  1221,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,   744,   745,   384,
     782,   603,   782,   782,   596,   597,   734,   599,   600,   601,
     602,   385,   387,   760,  1478,   603,   782,  1495,   839,  1615,
    1666,   839,  1698,   839,   839,  1365,   839,  1699,  1792,  1815,
    1817,   839,  1793,   839,   839,   386,   782,   418,   430,  1021,
     431,  1023,  1024,  1025,  1026,  1027,  1028,   432,  1030,  1031,
    1032,  1033,   438,   439,  1038,  1039,  1040,   782,  1899,   465,
    1949,  1967,   839,  1587,  1950,  1968,  1992,  1993,  2008,  2016,
     839,   839,  1950,   839,  1461,   148,  1462,  2039,  2048,   297,
    2065,   797,  2049,   464,  1950,   481,  2068,  1364,  2069,  1471,
     839,   483,   839,  2100,   782,   297,   513,   839,  2121,  1879,
    1880,  2122,   839,  2128,   485,   839,  2136,  1950,   297,   490,
     839,   880,  2144,   469,  1472,  1474,   839,  2158,  1497,   494,
    2193,  1950,  2200,   616,   839,   894,   839,  2201,  2202,  2203,
     508,   839,   839,   839,  1108,   550,  2205,  2207,   553,   455,
     839,  2049,   297,   297,  1117,   297,   297,   297,  -206,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,  1250,
    2227,   297,  -207,  2234,  1950,  2243,  1256,   839,  2253,  2244,
    1267,  2256,  1950,  -208,   561,  2257,   562,   565,   568,   569,
    1552,  1553,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
     570,   297,   469,   469,   603,  1563,  1551,   581,   434,   613,
     614,   621,  1568,   629,   670,   623,   673,   674,   622,   686,
     626,   631,   633,   634,   653,   297,   675,   654,   455,   455,
     655,  1583,   656,   657,   658,   659,   687,   722,   671,   688,
     681,   297,   297,   297,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,   676,  1603,   677,
     678,   603,   680,   695,   696,   682,   683,   690,   704,   705,
     706,   723,  1619,   717,   718,   720,   724,   725,   721,  1625,
     726,   728,   729,  1472,  1474,   746,   731,  1791,   749,   761,
     782,   766,   768,   769,   775,   147,   808,   297,   461,   830,
     835,   812,   814,   841,   842,   843,   904,   874,   906,   884,
    1066,   885,   886,   603,   907,   297,   942,   297,   297,   943,
     946,   951,  1420,   955,   956,   958,   985,   297,   987,  1006,
     988,   991,   469,  1000,  1012,   767,   469,  1015,  1060,  1044,
    1046,  1064,  1054,  1070,  1065,   469,  1074,   469,  1069,  1085,
     469,  1086,  1091,  1102,  1104,  1107,  1114,  1116,   455,  1119,
    1124,  1120,   455,  1630,  1125,  1635,   297,  1126,  1128,  1129,
    1130,   455,  1132,   455,  1133,  1134,   455,  1135,  2081,   380,
    1136,  1137,  1138,  1139,  1140,  1141,  1570,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,  1144,   469,  1148,  1175,   603,  1208,   297,
    1176,   297,  1184,  1185,  1193,  1186,  1202,  1212,  1224,  1196,
    1216,  1225,  1226,  1232,  1234,  1245,  1253,  1254,   297,  1279,
     455,  1257,  1280,  1397,  1282,  1302,  1298,  1300,  1301,  1313,
     297,  1314,  1315,  1318,   297,  1326,  1328,  1329,  1335,  1339,
    1342,  1343,  1344,  1345,  1348,  1349,  1350,  1354,  1367,  1369,
    1385,  1370,  1800,  1800,  1392,  1394,  1423,  1211,  1391,  1399,
    1393,  1402,  1427,  1407,  1439,  1482,  -209,  1465,  1406,  1483,
    1789,  1484,  1487,  1457,  1488,  1490,  1489,  1491,  1492,  1493,
    1494,  1504,  1505,  1779,  1938,  1508,  1509,  1781,  1510,   297,
     297,   297,  1519,  1520,  1231,  1521,  1522,   297,   297,   297,
    1523,  1524,  1525,  1526,  1527,  1531,  1532,  1533,  1534,  1535,
    1774,  1536,  1452,  1453,  1537,   297,  1538,  1539,  1540,  1547,
    1542,  1544,  1558,  1559,  1565,  1566,   297,  1567,  1569,  1571,
    1575,  1580,  1585,  1577,   297,  1586,  1589,  1591,   297,  1590,
    1596,  1598,  1599,  1602,  1600,  1616,  1622,  1623,  1641,   297,
    1614,   297,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
    1643,  1640,  1829,  1620,   603,  1639,  1649,  1650,  1645,  1651,
    1858,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1677,  1684,   380,  1688,  1697,  1703,  1704,  1753,  1771,
    1712,   476,   476,  1713,  1710,  1711,  1714,   297,  1718,  1719,
    1726,  1727,  1742,  1351,  1720,  1750,  1733,  1721,  1752,  1757,
    1783,  1734,  1786,  1810,  1812,   469,  1818,   455,   455,  1371,
    1735,  1736,  1737,  1738,  1744,   297,  1741,  1745,  1819,  1778,
     297,  1761,  1555,  1764,   784,  1333,  1557,  1782,  1932,  1785,
    1802,   455,  1807,  1821,  1941,  1561,  1814,  1562,  1874,  1822,
    1564,  1830,  1825,  1836,  1838,  1839,  1840,  1845,  1846,  1841,
    1847,  1848,  1204,  1853,  1859,  1861,  1421,  1422,  1863,  1424,
    1425,  1426,  1860,  1428,  1429,  1430,  1431,  1432,  1433,  1434,
    1435,  1436,  1437,  1866,  1867,  1884,  1888,  1889,  1898,  1904,
    1905,  1906,  1924,  1915,  1925,  1729,  1936,  1937,  1942,  1926,
    1920,  1923,   297,   797,  1605,  1954,  -580,   297,   297,  -578,
    1955,  1956,  1957,  1961,  2105,  1965,  1970,   461,   461,  1972,
    1971,  1934,  1976,  2005,  1973,  1451,  1974,  1975,  1982,  1987,
     297,  1988,  1991,  1996,  1997,  2003,   297,  1999,  2015,  2023,
    2006,   297,  2000,  2018,  2033,  2024,  2034,  2035,  2038,  1466,
     297,  2030,  2040,  2041,  2064,  2031,  2032,  2084,   469,  2089,
    2037,   469,  2096,  2102,  2104,  1479,  2046,  2101,  2085,  2103,
    2106,  2112,  -579,  2115,  2116,  2117,  2126,  2132,  2120,   297,
    2135,  2139,  2140,  1364,   455,  2124,  2127,   455,  2129,  2151,
     380,  2152,   297,   476,  2133,  2154,  2137,  2143,  2155,  2166,
    2162,  2171,   782,  2176,   782,  2190,  2206,  2217,  2218,  2219,
    2220,  2222,  2223,  2224,  2228,  2225,  2239,  2238,  2242,   455,
    2249,  1529,  2245,  1837,  2254,  2255,  2258,  2259,   476,  1618,
    2184,  1835,  1680,  2027,  2055,  1862,   125,  1384,  1647,  1543,
     136,  1545,  1546,   137,   138,   297,   945,  2079,  1773,   144,
    1109,   807,  1933,  1921,   455,     0,   297,   297,  1801,  1438,
    2028,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,   297,     0,   603,     0,     0,     0,     0,     0,     0,
    1576,     0,     0,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2059,     0,     0,     0,     0,  2087,     0,
     297,     0,  1891,  1892,  1893,  1894,  1895,  1897,     0,     0,
       0,  1530,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1820,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
       0,     0,  1634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   297,     0,  1648,     0,     0,  2060,  1652,     0,
     297,   297,     0,     0,     0,  1574,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,     0,
       0,   297,     0,     0,     0,     0,   461,     0,     0,     0,
       0,     0,   297,     0,     0,  2153,   297,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1700,  1701,  1702,     0,     0,     0,     0,
     380,  1707,  1708,  1709,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,  2175,     0,     0,     0,  1724,
       0,     0,     0,  2161,     0,     0,     0,     0,     0,     0,
    1732,     0,     0,     0,     0,     0,     0,     0,  1740,     0,
       0,     0,   297,     0,     0,     0,     0,     0,  1916,     0,
       0,  1918,     0,  1749,     0,  1751,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     782,  1592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1806,   297,   297,   297,   297,   297,     0,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,  1828,
     603,     0,     0,     0,     0,     0,   782,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,  2091,  2092,
    2093,  2094,  2095,     0,     0,     0,     0,     0,   782,     0,
       0,   297,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,   469,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,   174,     0,
     180,   469,   469,     0,     0,     0,  1865,     0,   455,     0,
       0,     0,  2130,     0,   469,     0,  2134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   455,   455,     0,
       0,     0,     0,     0,  1806,     0,     0,     0,     0,     0,
     455,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1907,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2167,     0,     0,
       0,  2169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1931,     0,     0,     0,  2181,     0,     0,
       0,   428,     0,     0,     0,     0,  1940,     0,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,   454,   456,
     603,     0,     0,   466,     0,     0,     0,     0,   472,     0,
       0,     0,  2214,  2215,     0,     0,     0,   478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1806,
       0,     0,     0,     0,   487,   488,   489,     0,   491,   492,
     493,     0,   495,   496,   497,   498,   499,   500,   501,     0,
     503,   504,   505,   506,     0,     0,     0,     0,   510,     0,
       0,     0,     0,     0,     0,  2004,     0,     0,     0,     0,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   544,   545,   546,   547,   548,
     549,     0,   551,   552,     0,     0,     0,     0,     0,     0,
       0,   557,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   566,   567,     0,     0,     0,     0,     0,
       0,  2047,   571,   573,   575,   576,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2056,     0,     0,     0,
       0,   610,   510,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   628,
       0,     0,  1806,     0,     0,     0,     0,     0,     0,   638,
     639,     0,  2236,     0,     0,   639,  2086,     0,     0,     0,
       0,     0,     0,     0,     0,   510,   661,     0,     0,     0,
       0,  2250,  2252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2260,     0,     0,     0,     0,     0,
     684,   510,     0,     0,     0,     0,   689,  1806,   691,   692,
       0,   694,     0,     0,     0,   697,   698,   699,     0,     0,
     700,   701,   702,   703,     0,     0,     0,   707,   708,   709,
     710,   711,   712,   713,     0,   714,  2131,     0,     0,     0,
     715,   716,     0,     0,   719,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   732,     0,
     733,     0,     0,     0,     0,   510,   742,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   750,   751,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   783,  1722,     0,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,   813,     0,
       0,     0,   603,   818,   762,     0,   763,   822,     0,     0,
       0,     0,  1762,     0,     0,     0,     0,     0,     0,     0,
       0,   836,   573,     0,     0,     0,   840,     0,     0,  1806,
     844,   845,   846,   847,   848,   849,   850,   851,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   870,     0,   875,   876,
       0,   878,     0,     0,     0,     0,     0,   511,     0,     0,
     887,     0,     0,   891,   892,     0,     0,     0,     0,  1806,
     870,     0,     0,     0,     0,   510,     0,     0,     0,     0,
       0,     0,   905,     0,     0,     0,     0,   908,   909,   910,
     911,   912,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   923,   925,   926,   927,   928,   929,     0,   931,   932,
       0,     0,     0,     0,     0,     0,   939,   940,   941,     0,
       0,     0,     0,     0,   947,   948,   949,   950,     0,   510,
     510,     0,   574,     0,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   571,   733,
     969,   511,   511,     0,   974,   975,   976,   977,   978,   979,
     980,   981,   982,     0,     0,     0,     0,     0,   989,   990,
       0,   992,     0,     0,   994,     0,     0,     0,   510,   510,
     510,   999,     0,   510,  1002,  1003,  1004,     0,     0,     0,
       0,  1007,     0,  1009,   511,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,  1029,     0,     0,     0,   603,     0,     0,
     511,     0,     0,     0,     0,     0,  1485,   510,     0,     0,
       0,     0,     0,     0,  1048,  1049,     0,  1050,     0,     0,
     931,   932,     0,     0,     0,     0,     0,     0,     0,  1063,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,  1079,
       0,     0,     0,     0,  1082,  1083,     0,     0,     0,     0,
       0,     0,     0,     0,   511,     0,     0,     0,     0,   510,
       0,  1099,  1100,     0,     0,   510,     0,   510,  1106,     0,
       0,     0,  1099,     0,     0,  1113,     0,     0,     0,     0,
       0,  1118,     0,     0,     0,  1121,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,  1142,   603,
     923,     0,  1145,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,   574,     0,     0,     0,   603,     0,  1005,     0,  1780,
       0,     0,     0,     0,     0,   962,     0,   510,     0,     0,
       0,     0,     0,     0,     0,   861,     0,   510,  1189,  1190,
       0,     0,     0,     0,   871,   872,     0,     0,     0,     0,
       0,     0,  1205,     0,     0,     0,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   897,
       0,     0,     0,     0,   511,   510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1222,     0,   510,     0,     0,
       0,     0,     0,     0,     0,  1230,     0,     0,     0,  1236,
     924,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,  1251,  1252,     0,     0,     0,
       0,  1255,     0,     0,     0,     0,     0,     0,   511,   511,
       0,     0,     0,     0,     0,     0,     0,     0,  1281,     0,
       0,  1283,     0,     0,     0,     0,     0,     0,     0,     0,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
    1784,     0,     0,     0,     0,     0,  1303,     0,  1305,  1306,
       0,     0,     0,     0,     0,     0,     0,   511,   511,   511,
       0,     0,   511,     0,     0,     0,     0,  1324,     0,     0,
       0,     0,     0,   660,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1347,     0,     0,     0,     0,     0,     0,  1353,     0,
       0,     0,     0,     0,     0,  1366,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1389,  1390,
       0,     0,     0,     0,   510,     0,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,   511,  1410,   603,     0,
       0,     0,     0,     0,     0,  1418,     0,     0,     0,     0,
       0,     0,     0,   741,     0,     0,     0,     0,   511,     0,
       0,     0,     0,     0,   511,     0,   511,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1442,  1443,  1444,  1445,  1446,     0,     0,
       0,     0,  1448,  1449,     0,  1450,     0,     0,     0,   924,
       0,  1146,     0,     0,     0,     0,     0,     0,     0,  1459,
    1460,     0,     0,     0,     0,     0,     0,  1463,  1464,     0,
       0,  1467,     0,     0,     0,     0,  1468,  1469,  1790,     0,
       0,     0,  1475,  1476,     0,     0,   511,     0,   510,   510,
       0,     0,     0,     0,     0,     0,   511,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,  1507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   901,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1541,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,     0,   510,     0,     0,     0,     0,     0,     0,
       0,  1556,     0,     0,     0,     0,     0,   952,   953,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1475,  1476,     0,     0,     0,  1573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1579,
       0,     0,  1584,     0,     0,     0,     0,     0,     0,     0,
       0,  1594,  1595,     0,     0,     0,   996,   997,   998,  1969,
     584,  1001,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1606,     0,     0,  1609,   510,  1612,   510,     0,     0,
       0,     0,     0,     0,     0,  1621,     0,     0,  1624,     0,
    1621,  1627,  1629,     0,     0,  1637,  1638,     0,     0,     0,
       0,     0,     0,     0,     0,  1043,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   511,     0,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,  1685,  1075,     0,   603,     0,     0,
       0,     0,     0,  1692,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1097,     0,     0,
       0,     0,  1706,  1103,     0,  1105,   511,     0,     0,     0,
       0,     0,  1715,  1716,  1717,     0,     0,     0,     0,     0,
       0,  1723,     0,  1725,     0,     0,     0,     0,     0,     0,
    1728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   510,     0,     0,     0,     0,     0,
    1746,  1747,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1754,  1755,  1756,     0,     0,     0,     0,     0,     0,
       0,  1765,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1777,     0,     0,  1178,     0,   511,   511,     0,
       0,     0,     0,     0,     0,  1188,     0,     0,     0,     0,
       0,     0,     0,  1794,     0,     0,     0,     0,     0,     0,
       0,  1803,  1804,     0,     0,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   837,   599,
     600,   601,   602,  1215,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,  1831,  1223,  1833,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,  1244,     0,     0,     0,   603,
       0,     0,   511,     0,     0,  1826,     0,     0,     0,  1827,
       0,     0,     0,     0,     0,     0,     0,  1849,  1850,  1851,
       0,     0,     0,     0,     0,     0,     0,     0,  1852,     0,
       0,     0,     0,  1855,  1856,     0,     0,     0,     0,     0,
       0,     0,     0,  1902,     0,     0,  1864,     0,     0,     0,
       0,     0,     0,   510,   510,  1872,     0,  1873,     0,     0,
       0,     0,     0,  1881,  1882,     0,  1903,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   510,     0,   511,     0,   511,   510,  1901,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1914,     0,     0,  1917,     0,     0,     0,  1919,
       0,     0,     0,     0,     0,     0,     0,     0,  1855,  1856,
       0,  1928,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1935,  1396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1946,     0,     0,     0,     0,
    1952,  1953,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1958,     0,     0,  1959,  1958,     0,
    1962,     0,     0,     0,     0,     0,     0,     0,  1995,     0,
       0,     0,     0,     0,     0,  1440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   510,   510,     0,     0,     0,     0,     0,  1989,
    1990,     0,     0,     0,     0,     0,   765,     0,     0,     0,
       0,  1998,     0,   511,     0,     0,     0,     0,     0,     0,
    2007,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2019,  2020,     0,     0,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1480,  1481,     0,     0,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
    2044,  2045,   603,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,  2058,     0,     0,     0,   603,   510,   510,  2063,     0,
     888,     0,     0,  2066,     0,  1834,     0,  2022,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1554,   510,     0,     0,     0,     0,     0,     0,     0,
       0,  2097,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2108,     0,     0,     0,
       0,     0,  2113,     0,     0,  2114,     0,     0,     0,     0,
       0,     0,   511,   511,     0,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,  2138,   603,     0,     0,
       0,   511,     0,  1611,     0,  1613,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2156,  2157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2163,  2164,     0,
     510,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2173,     0,     0,     0,     0,   510,   510,
     510,   510,   510,     0,     0,     0,     0,     0,  1952,     0,
       0,     0,  2189,     0,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,  2209,
       0,     0,  1877,     0,  2212,  2213,  1878,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,   511,   511,     0,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,  1743,     0,  2240,  2241,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   511,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,     0,  1161,  1162,
    1163,  1164,     0,  1166,  1167,  1168,  1169,  2036,     0,     0,
     169,   388,     0,     0,     0,     0,     0,     0,     0,  1181,
       0,  1183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1192,     0,     0,     0,     0,     0,     0,  1198,  1199,
       0,     0,     0,     0,     0,   511,   511,  1210,     0,     0,
       0,     0,     0,     0,     0,   389,   390,   391,   392,   393,
     394,   395,   396,   397,  2070,     0,   511,     0,   398,   399,
     400,   401,     0,     0,     0,     0,   402,   403,   404,   405,
       0,   511,     0,     0,   406,     0,   407,  2071,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     408,     0,     0,   409,     0,     0,     0,   175,     0,     0,
     176,  2150,     0,   177,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,  1870,  1871,     0,     0,     0,     0,     0,  2196,     0,
       0,     0,     0,     0,   441,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1309,  1311,  1312,  1900,     0,     0,  1316,  1317,
    2119,     0,  1320,  1321,  1322,  1323,     0,  1325,     0,     0,
       0,     0,  1331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,   411,   412,   511,   511,   511,
     511,   511,     0,     0,     0,     0,   413,     0,     0,     0,
     414,     0,   415,   119,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,   447,
     448,     0,     0,  1417,     0,  1419,  -574,     0,  1604,     0,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
    1985,  1986,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,  2021,     0,   603,     0,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,  1477,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,  2061,  2062,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,  2080,     0,     0,   603,     0,
       0,     0,     0,     0,   213,   169,   388,     0,   440,     0,
    2090,   214,   215,   216,     0,     0,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   426,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   248,
     249,   250,   251,   398,   399,   400,   401,   252,   584,     0,
       0,   402,   403,   404,   405,     0,     0,     0,     0,   406,
       0,   407,   256,   257,   258,     0,     0,     0,     0,     0,
    1593,     0,     0,   259,    25,   408,   260,     0,   409,     0,
       0,     0,   175,     0,     0,   176,     0,     0,   177,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,     0,     0,  2165,     0,
       0,     0,  1631,     0,     0,     0,     0,     0,     0,   441,
       0,     0,     0,     0,     0,     0,  2177,  2178,  2179,  2180,
    2182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1667,  1668,  1669,  1670,  1671,  1672,  1673,
       0,     0,     0,     0,  1678,  1679,     0,     0,     0,     0,
    1681,     0,  1683,     0,     0,     0,  1687,     0,     0,  1689,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1696,   442,     0,     0,     0,  2221,     0,     0,   270,   410,
     411,   412,   271,     0,     0,     0,     0,     0,   273,   274,
     275,   413,   276,   277,   278,   414,     0,   415,   119,     0,
     443,   444,   445,   446,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,   427,     0,     0,     0,
       0,     0,   281,     0,   447,   448,     0,   449,     0,   450,
       0,     0,     0,   451,   284,   584,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1760,     0,  1763,     0,
       0,     0,  1770,     0,  1772,     0,     0,     0,     0,     0,
       0,     0,     0,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,     0,     0,     0,     0,   603,  1797,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,     6,   388,
       0,     0,     0,     0,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,  1632,   390,   391,   392,   393,   394,   395,
     396,   397,   248,   249,   250,   251,   398,   399,   400,   401,
     252,   253,     0,     0,   402,   403,   404,   405,     0,     0,
     254,   255,   406,     0,   407,   256,   257,   258,     0,     0,
       0,     0,     0,     0,  1857,     0,   259,    25,   408,   260,
       0,   409,     0,     0,     0,   261,     0,     0,   262,     0,
       0,   263,     0,   264,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,    57,    58,     0,
     267,     0,   268,     0,     0,   269,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   837,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
    1943,     0,     0,  1944,     0,     0,     0,     0,     0,     0,
       0,   270,   410,   411,   412,   271,   272,  1016,     0,     0,
       0,   273,   274,   275,   413,   276,   277,   278,   414,     0,
     415,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   280,
       0,  1978,  1979,     0,  1981,   281,     0,     0,     0,     0,
     367,     0,     0,     0,  1633,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,   213,     6,   388,     0,     0,
       0,     0,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,  2025,
    2026,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     248,   249,   250,   251,   398,   399,   400,   401,   252,   253,
       0,     0,   402,   403,   404,   405,     0,     0,   254,   255,
     406,     0,   407,   256,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   259,    25,   408,   260,  2057,   409,
       0,     0,     0,   261,     0,     0,   262,     0,     0,   263,
       0,   264,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,    57,    58,     0,   267,     0,
     268,     0,     0,   269,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,     0,     0,
       0,     0,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,  1213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     410,   411,   412,   271,   272,     0,     0,     0,     0,   273,
     274,   275,   413,   276,   277,   278,   414,     0,   415,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,   280,     0,     0,
       0,     0,     0,   281,     0,     0,     0,     0,   367,   213,
       6,   366,   283,     0,     0,   284,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,   251,     0,     0,
       0,     0,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,     0,     0,     0,   256,   257,   258,
       0,     0,     0,     0,     0,  2230,     0,     0,   259,    25,
       0,   260,     0,     0,     0,     0,     0,   261,     0,     0,
     262,     0,     0,   263,     0,   264,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,    57,
      58,     0,   267,     0,   268,     0,     0,   269,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,  1214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,   271,   272,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277,   278,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,   280,     0,     0,     0,     0,     0,   281,     0,     0,
       0,     0,   367,   213,     6,     0,   368,     0,   685,   284,
     214,   215,   216,     0,     0,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,   251,     0,     0,     0,     0,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,     0,     0,
       0,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,    25,     0,   260,     0,     0,     0,     0,
       0,   261,     0,     0,   262,     0,     0,   263,     0,   264,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,    57,    58,     0,   267,     0,   268,     0,
       0,   269,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,     0,  1549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,     0,
       0,   271,   272,     0,     0,     0,     0,   273,   274,   275,
       0,   276,   277,   278,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,   509,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,   367,   213,     6,  1731,
       0,   577,     0,   284,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,   251,     0,     0,     0,     0,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,     0,     0,     0,   256,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,   259,    25,     0,   260,
       0,     0,     0,     0,     0,   261,     0,     0,   262,     0,
       0,   263,     0,   264,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,    57,    58,     0,
     267,     0,   268,     0,     0,   269,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,     0,     0,     0,   271,   272,     0,     0,     0,
       0,   273,   274,   275,     0,   276,   277,   278,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   280,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
     367,   213,     6,     0,   283,     0,     0,   284,   214,   215,
     216,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,   251,
       0,     0,     0,     0,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,     0,     0,     0,   256,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     259,    25,     0,   260,     0,     0,     0,     0,     0,   261,
       0,     0,   262,     0,     0,   263,     0,   264,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   265,     0,
       0,   419,   388,     0,     0,     0,     0,     0,     0,   266,
       0,    57,    58,     0,   267,     0,   268,     0,     0,   269,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,     0,     0,   389,   390,   391,   392,
     393,   394,   395,   396,   397,     0,     0,     0,     0,   398,
     399,   400,   401,     0,     0,     0,     0,   402,   403,   404,
     405,     0,     0,     0,     0,   406,     0,   407,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,   271,
     272,   408,     0,     0,   409,   273,   274,   275,     0,   276,
     277,   278,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   645,  1896,     0,     0,     0,     0,     0,   281,
       0,     0,     0,     0,   647,   213,     6,     0,   327,   577,
       0,   284,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,   410,   411,   412,   254,   255,
       0,     0,     0,   256,   257,   258,     0,   413,     0,     0,
       0,   414,     0,   415,   259,    25,     0,   260,     0,     0,
       0,     0,     0,   261,     0,     0,   262,     0,     0,   263,
       0,   264,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   265,     0,     0,     0,   388,     0,     0,     0,
       0,     0,     0,   266,     0,    57,    58,     0,   267,     0,
     268,     0,     0,   269,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,     0,     0,
     389,   390,   391,   392,   393,   394,   395,   396,   397,     0,
       0,     0,     0,   398,   399,   400,   401,     0,     0,     0,
       0,   402,   403,   404,   405,     0,     0,     0,     0,   406,
       0,   407,     0,     0,     0,     0,     0,     0,     0,   270,
       0,     0,     0,   271,   272,   408,     0,     0,   409,   273,
     274,   275,     0,   276,   277,   278,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,   280,     0,     0,
       0,     0,     0,   281,     0,     0,     0,     0,   282,   213,
       6,     0,   283,     0,     0,   284,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,   251,     0,     0,
       0,     0,   252,   253,     0,     0,     0,     0,     0,   410,
     411,   412,   254,   255,     0,     0,     0,   256,   257,   258,
       0,   413,     0,     0,     0,   414,     0,   415,   259,    25,
       0,   260,     0,     0,     0,     0,     0,   261,     0,     0,
     262,     0,     0,   263,     0,   264,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,    57,
      58,     0,   267,     0,   268,     0,     0,   269,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    1908,     0,     0,     0,  1909,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,   271,   272,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277,   278,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,   280,     0,     0,     0,     0,     0,   281,     0,     0,
       0,     0,   367,   213,     6,     0,   283,     0,     0,   284,
     214,   215,   216,     0,     0,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,   251,     0,     0,     0,     0,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,     0,     0,
       0,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,    25,     0,   260,     0,     0,     0,     0,
       0,   261,     0,     0,   262,     0,     0,   263,     0,   264,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   266,     0,    57,    58,     0,   267,     0,   268,     0,
       0,   269,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  2082,     0,     0,     0,  2083,     0,
       0,     0,     0,     0,     0,     0,     0,   270,     0,     0,
       0,   271,   272,     0,     0,     0,     0,   273,   274,   275,
       0,   276,   277,   278,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,   509,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,   367,   213,     6,     0,
     572,     0,     0,   284,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,   251,     0,     0,     0,     0,
     252,   253,     0,     0,     0,     0,     0,     0,     0,     0,
     254,   255,     0,     0,     0,   256,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,   259,    25,     0,   260,
       0,     0,     0,     0,     0,   261,     0,     0,   262,     0,
       0,   263,     0,   264,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   266,     0,    57,    58,     0,
     267,     0,   268,     0,     0,   269,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,     0,     0,     0,    83,     0,     0,    86,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   795,     0,     0,     0,     0,     0,     0,     0,
       0,   270,     0,     0,     0,   271,   272,     0,     0,     0,
       0,   273,   274,   275,     0,   276,   277,   278,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   509,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
     367,   213,     6,     0,     0,   577,     0,   284,   214,   215,
     216,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,   251,
       0,     0,     0,     0,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,     0,     0,     0,   256,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     259,    25,     0,   260,     0,     0,     0,     0,     0,   261,
       0,     0,   262,     0,     0,   263,     0,   264,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,    57,    58,     0,   267,     0,   268,     0,     0,   269,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   802,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,   271,
     272,     0,     0,     0,     0,   273,   274,   275,     0,   276,
     277,   278,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,   280,     0,     0,     0,     0,     0,   281,
       0,     0,     0,     0,   615,   213,     6,     0,   283,     0,
       0,   284,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
       0,     0,     0,   256,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   259,    25,     0,   260,     0,     0,
       0,     0,     0,   261,     0,     0,   262,     0,     0,   263,
       0,   264,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,    57,    58,     0,   267,     0,
     268,     0,     0,   269,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     962,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,     0,     0,   271,   272,     0,     0,     0,     0,   273,
     274,   275,     0,   276,   277,   278,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   279,   280,     0,     0,
       0,     0,     0,   281,     0,     0,     0,     0,   624,   213,
       6,     0,   283,     0,     0,   284,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,   251,     0,     0,
       0,     0,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,     0,     0,     0,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,   259,    25,
       0,   260,     0,     0,     0,     0,     0,   261,     0,     0,
     262,     0,     0,   263,     0,   264,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,    57,
      58,     0,   267,     0,   268,     0,     0,   269,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,   271,   272,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277,   278,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,   509,     0,     0,     0,     0,     0,   281,     0,     0,
       0,     0,   367,   213,     6,     0,   922,     0,  1395,   284,
     214,   215,   216,     0,     0,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,   251,     0,     0,     0,     0,   252,   253,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   255,     0,     0,
       0,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,    25,     0,   260,     0,     0,     0,     0,
       0,   261,     0,     0,   262,     0,     0,   263,     0,   264,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     265,     0,     0,   169,   388,     0,     0,     0,     0,     0,
       0,   266,     0,    57,    58,     0,   267,     0,   268,     0,
       0,   269,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,     0,    74,    75,    76,    77,    78,    79,     0,
       0,     0,    83,     0,     0,    86,     0,     0,   389,   390,
     391,   392,   393,   394,   395,   396,   397,     0,     0,     0,
       0,   398,   399,   400,   401,     0,     0,     0,     0,   402,
     403,   404,   405,     0,     0,     0,     0,   406,     0,   407,
       0,     0,     0,     0,     0,     0,     0,   270,     0,     0,
       0,   271,   272,   408,     0,     0,   409,   273,   274,   275,
       0,   276,   277,   278,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,   509,     0,     0,     0,     0,
       0,   281,   213,     6,     0,     0,   367,  1610,     0,   214,
     215,   216,     0,   284,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,   250,
     251,     0,     0,     0,     0,   252,   253,     0,     0,     0,
       0,     0,     0,     0,     0,   254,   255,   410,   411,   412,
     256,   257,   258,     0,     0,     0,     0,     0,     0,   413,
       0,   259,    25,   414,   260,   415,   119,     0,     0,     0,
     261,     0,     0,   262,     0,     0,   263,     0,   264,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     266,     0,    57,    58,     0,   267,     0,   268,     0,     0,
     269,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,    74,    75,    76,    77,    78,    79,     0,     0,
       0,    83,     0,     0,    86,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1013,     0,     0,
       0,     0,     0,     0,     0,     0,   270,     0,     0,     0,
     271,   272,     0,     0,     0,     0,   273,   274,   275,     0,
     276,   277,   278,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,   509,     0,     0,     0,     0,     0,
     281,   213,     6,     0,     0,   367,     0,     0,   214,   215,
     216,     0,   284,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,   251,
       0,     0,     0,     0,   252,   253,     0,     0,     0,     0,
       0,     0,     0,     0,   254,   255,     0,     0,     0,   256,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
     259,    25,     0,   260,     0,     0,     0,     0,     0,   261,
       0,     0,   262,     0,     0,   263,     0,   264,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   266,
       0,    57,    58,     0,   267,     0,   268,     0,     0,   269,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,    74,    75,    76,    77,    78,    79,     0,     0,     0,
      83,     0,     0,    86,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1122,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,   271,
     272,     0,     0,     0,     0,   273,   274,   275,     0,   276,
     277,   278,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,   280,     0,     0,     0,     0,     0,   281,
       0,     0,     0,     0,   367,   213,     6,     0,  1739,     0,
       0,   284,   214,   215,   216,     0,     0,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,   251,     0,     0,     0,     0,   252,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   254,   255,
       0,     0,     0,   256,   257,   258,     0,     0,     0,     0,
       0,     0,     0,     0,   259,    25,     0,   260,     0,     0,
       0,     0,     0,   261,     0,     0,   262,     0,     0,   263,
       0,   264,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   265,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   266,     0,    57,    58,     0,   267,     0,
     268,     0,     0,   269,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,     0,    74,    75,    76,    77,    78,
      79,     0,     0,     0,    83,     0,     0,    86,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1160,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,     0,     0,   271,   272,     0,     0,     0,     0,   273,
     274,   275,     0,   276,   277,   278,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   645,  1896,     0,     0,
       0,     0,     0,   281,     0,     0,     0,     0,   647,   213,
       6,     0,   327,     0,     0,   284,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,   251,     0,     0,
       0,     0,   252,   253,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,     0,     0,     0,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,   259,    25,
       0,   260,     0,     0,     0,     0,     0,   261,     0,     0,
     262,     0,     0,   263,     0,   264,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   266,     0,    57,
      58,     0,   267,     0,   268,     0,     0,   269,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,     0,    74,
      75,    76,    77,    78,    79,     0,     0,     0,    83,     0,
       0,    86,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1170,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,   271,   272,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277,   278,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,   509,     0,     0,     0,     0,     0,   281,   213,   169,
     388,     0,   367,     0,     0,   214,   215,   216,     0,   284,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   426,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,     0,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   248,   249,   250,   251,   398,   399,   400,
     401,   252,     0,     0,     0,   402,   403,   404,   405,     0,
       0,     0,     0,   406,     0,   407,   256,   257,   258,     0,
       0,     0,     0,     0,     0,     0,     0,   259,    25,   408,
     260,     0,   409,   213,   169,   388,     0,     0,     0,     0,
     214,   215,   216,     0,     0,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   426,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   248,   249,
     250,   251,   398,   399,   400,   401,   252,     0,     0,     0,
     402,   403,   404,   405,     0,     0,     0,     0,   406,     0,
     407,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,   259,    25,   408,   260,     0,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   410,   411,   412,   271,     0,     0,     0,
       0,     0,   273,   274,   275,   413,   276,   277,   278,   414,
       0,   415,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
     427,     0,     0,     0,     0,     0,   281,     0,     0,     0,
       0,   367,     0,     0,     0,  1628,     0,     0,   284,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1171,     0,     0,     0,     0,     0,   270,   410,   411,
     412,   271,     0,     0,     0,     0,     0,   273,   274,   275,
     413,   276,   277,   278,   414,     0,   415,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,   427,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,   367,   213,   169,   388,
    1913,     0,     0,   284,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   426,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,  1632,   390,   391,   392,   393,   394,   395,
     396,   397,   248,   249,   250,   251,   398,   399,   400,   401,
     252,     0,     0,     0,   402,   403,   404,   405,     0,     0,
       0,     0,   406,     0,   407,   256,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,   259,    25,   408,   260,
       0,   409,   213,   169,   388,     0,     0,     0,     0,   214,
     215,   216,     0,     0,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   426,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,     0,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   248,   249,   250,
     251,   398,   399,   400,   401,   252,     0,     0,     0,   402,
     403,   404,   405,     0,     0,     0,     0,   406,     0,   407,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,   259,    25,   408,   260,     0,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   410,   411,   412,   271,     0,     0,     0,     0,
       0,   273,   274,   275,   413,   276,   277,   278,   414,     0,
     415,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   427,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
     367,     0,     0,     0,  1796,     0,     0,   284,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1172,     0,     0,     0,     0,     0,   270,   410,   411,   412,
     271,     0,     0,     0,     0,     0,   273,   274,   275,   413,
     276,   277,   278,   414,     0,   415,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   279,   427,     0,     0,     0,     0,     0,
     281,   213,   169,     0,     0,   367,     0,     0,   214,   215,
     216,     0,   284,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     426,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,   251,
       0,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     257,   258,     0,     0,     0,     0,     0,   213,   169,     0,
     259,    25,     0,   260,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   426,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,   251,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,   259,    25,     0,   260,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,   270,     0,     0,     0,   271,
       0,     0,  1173,     0,     0,   273,   274,   275,     0,   276,
     277,   278,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,   427,     0,     0,     0,     0,     0,   281,
       0,     0,     0,     0,   367,     0,     0,     0,   627,     0,
       0,   284,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,   270,     0,     0,  1174,   271,     0,     0,     0,     0,
       0,   273,   274,   275,     0,   276,   277,   278,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,   646,
       0,     0,     0,     0,     0,   281,     0,     0,     0,     0,
     647,   213,   169,     0,   327,     0,   890,   284,   214,   215,
     216,     0,     0,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     426,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,   251,
       0,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
     257,   258,     0,     0,     0,     0,     0,   213,   169,     0,
     259,    25,     0,   260,   214,   215,   216,     0,     0,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   426,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,   251,     0,     0,     0,     0,
     252,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,   259,    25,     0,   260,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,   270,     0,     0,     0,   271,
       0,     0,  1179,     0,     0,   273,   274,   275,     0,   276,
     277,   278,     0,     0,     0,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   279,   427,     0,     0,     0,     0,     0,   281,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,   284,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,   270,     0,     0,  1180,   271,     0,     0,     0,     0,
       0,   273,   274,   275,     0,   276,   277,   278,     0,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   427,
       0,     0,     0,     0,     0,   281,   213,   169,     0,  1346,
     367,  1111,     0,   214,   215,   216,     0,   284,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   426,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,   250,   251,     0,     0,     0,     0,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,   257,   258,     0,     0,     0,
       0,     0,     0,     0,     0,   259,    25,     0,   260,   213,
     169,     0,  1506,     0,     0,     0,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   426,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,   251,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,   259,    25,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,   271,     0,     0,     0,     0,     0,
     273,   274,   275,     0,   276,   277,   278,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,   427,     0,
       0,     0,     0,     0,   281,     0,     0,     0,     0,   367,
       0,     0,     0,     0,     0,     0,   284,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1182,
       0,     0,     0,   270,     0,     0,     0,   271,     0,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277,   278,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,   427,     0,     0,     0,     0,     0,   281,   213,   169,
       0,  1572,   367,     0,     0,   214,   215,   216,     0,   284,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   426,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,   251,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,   257,   258,     0,
       0,     0,     0,     0,   213,   169,     0,   259,    25,     0,
     260,   214,   215,   216,     0,     0,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   426,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,   251,     0,     0,     0,     0,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,   259,    25,     0,   260,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,   270,     0,     0,     0,   271,     0,     0,  1296,
       0,     0,   273,   274,   275,     0,   276,   277,   278,     0,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   279,
     427,     0,     0,     0,     0,     0,   281,     0,     0,     0,
       0,   367,     0,     0,     0,     0,     0,     0,   284,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,   270,     0,
       0,  1319,   271,     0,     0,     0,     0,     0,   273,   274,
     275,     0,   276,   277,   278,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   279,   427,     0,     0,     0,
       0,     0,   281,   213,   169,     0,     0,   367,  1626,     0,
     214,   215,   216,     0,   284,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   426,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,   251,     0,     0,     0,     0,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   256,   257,   258,     0,     0,     0,     0,     0,   213,
     169,     0,   259,    25,     0,   260,   214,   215,   216,     0,
       0,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   426,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,   251,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,   259,    25,
       0,   260,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,   270,     0,     0,
       0,   271,     0,     0,  1405,     0,     0,   273,   274,   275,
       0,   276,   277,   278,     0,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,   427,     0,     0,     0,     0,
       0,   281,     0,     0,     0,     0,   367,  1960,     0,     0,
       0,     0,     0,   284,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,     0,   270,     0,     0,  1408,   271,     0,     0,
       0,     0,     0,   273,   274,   275,     0,   276,   277,   278,
     169,   388,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     279,   427,     0,     0,     0,     0,     0,   281,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,   284,
       0,     0,     0,     0,     0,   389,   390,   391,   392,   393,
     394,   395,   396,   397,     0,     0,     0,     0,   398,   399,
     400,   401,   169,   388,     0,     0,   402,   403,   404,   405,
       0,     0,     0,     0,   406,     0,   407,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     408,     0,     0,   409,     0,     0,     0,   175,     0,     0,
     176,     0,     0,   177,     0,   178,     0,   389,   390,   391,
     392,   393,   394,   395,   396,   397,    46,     0,     0,     0,
     398,   399,   400,   401,     0,     0,     0,     0,   402,   403,
     404,   405,     0,     0,   441,     0,   406,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   408,     0,     0,   409,     0,     0,     0,   175,
       0,     0,   176,     0,     0,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,     0,     7,     8,
       0,     0,     0,     0,   410,   411,   412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   413,     0,     0,     0,
     414,     0,   415,   119,     0,     0,     0,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,   762,     0,   763,  1796,     7,     8,  1500,
       0,     0,     0,     0,     0,     0,   410,   411,   412,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   413,     0,
       0,     0,   414,     0,   415,   119,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,   776,    56,  1796,     0,
      59,   777,     0,   778,   779,     0,   780,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     7,     8,    48,     0,    95,
      96,    97,     0,     0,     0,   776,    56,     0,     0,    59,
     777,     0,   778,   779,     0,   780,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     7,     8,   603,     0,    95,    96,
      97,     0,     0,     0,     0,     0,  1501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   801,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,   776,    56,     0,     0,    59,   777,     0,
     778,   779,     0,   780,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   970,     0,     0,     0,     0,
       0,    80,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     7,     8,    48,     0,    95,    96,    97,     0,
       0,     0,   776,    56,     0,     0,    59,   777,     0,   778,
     779,     0,   780,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     7,     8,   603,     0,    95,    96,    97,     0,     0,
       0,     0,     0,  1548,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   995,     0,     0,     0,     0,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,     0,
     776,    56,     0,     0,    59,   777,     0,   778,   779,     0,
     780,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1045,     0,     0,     0,     0,     0,    80,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     7,
       8,    48,     0,    95,    96,    97,     0,     0,     0,   776,
      56,     0,     0,    59,   777,     0,   778,   779,     0,   780,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     7,     8,
     603,     0,    95,    96,    97,     0,     0,     0,     0,     0,
    1674,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1047,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,   776,    56,     0,
       0,    59,   777,     0,   778,   779,     0,   780,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1246,
       0,     0,     0,     0,     0,    80,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     7,     8,    48,     0,
      95,    96,    97,     0,     0,     0,   776,    56,     0,     0,
      59,   777,     0,   778,   779,     0,   780,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     7,     8,   603,     0,    95,
      96,    97,     0,     0,     0,     0,     0,  1675,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1248,     0,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,   776,    56,     0,     0,    59,   777,
       0,   778,   779,     0,   780,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1249,     0,     0,     0,
       0,     0,    80,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     7,     8,    48,     0,    95,    96,    97,
       0,     0,     0,   776,    56,     0,     0,    59,   777,     0,
     778,   779,     0,   780,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     7,     8,   603,     0,    95,    96,    97,     0,
       0,     0,     0,     0,  1676,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1268,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,   776,    56,     0,     0,    59,   777,     0,   778,   779,
       0,   780,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1287,     0,     0,     0,     0,     0,    80,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       7,     8,    48,     0,    95,    96,    97,     0,     0,     0,
     776,    56,     0,     0,    59,   777,     0,   778,   779,     0,
     780,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     7,
       8,   603,     0,    95,    96,    97,     0,     0,     0,     0,
       0,  1824,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1304,     0,     0,     0,     0,     0,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   776,    56,
       0,     0,    59,   777,     0,   778,   779,     0,   780,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1338,     0,     0,     0,     0,     0,    80,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     7,     8,    48,
       0,    95,    96,    97,     0,     0,     0,   776,    56,     0,
       0,    59,   777,     0,   778,   779,     0,   780,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
      95,    96,    97,     0,     0,     0,     0,     0,  1947,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1498,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,   776,    56,     0,     0,    59,
     777,     0,   778,   779,     0,   780,     0,     0,     0,     0,
       0,    -4,     1,     0,     0,    -4,     0,  2141,     0,     0,
       0,     0,     0,    80,    -4,    -4,     0,     0,     0,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,    95,    96,
      97,   603,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,  1948,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,     0,    -4,    -4,     0,     0,     0,
      -4,     0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,  2198,     0,    -4,    -4,    -4,
      -4,    -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     0,    -4,    -4,    -4,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,     0,     0,
      -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,     7,     8,
       0,     0,     0,     0,     0,     0,    -4,     0,    -4,    -4,
       0,     0,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     9,    10,    11,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1980,     0,     0,     0,     0,     0,
       0,     0,    12,    13,    14,     0,     0,     0,     0,    15,
      16,     0,     0,     0,    17,     0,     0,     0,     0,    18,
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
      96,    97,   169,   388,    98,     0,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,   119,   120,     0,     0,     0,   389,   390,   391,
     392,   393,   394,   395,   396,   397,     0,     0,     0,     0,
     398,   399,   400,   401,     7,     8,     0,     0,   402,   403,
     404,   405,     0,     0,     0,     0,   406,     0,   407,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   408,     0,     0,   409,     0,     0,     0,   175,
       0,     0,   176,     0,     0,   177,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,   776,    56,     0,     0,    59,   777,     0,   778,
     779,     0,   780,     0,     0,     0,  1057,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,     0,
      80,     0,     0,     0,  1058,     0,     0,     0,   413,     0,
       0,     0,   414,     0,   415,   119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,   776,    56,
       0,     0,    59,   777,     0,   778,   779,     0,   780,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,    95,    96,    97,     0,     0,     0,     0,     0,  2052,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2109,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2110,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2125,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2159,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2186,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2191,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2192,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,   834,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,  1092,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,  1147,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,  1194,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,  1195,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  1239,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,  1271,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  1285,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,  1292,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    1352,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  1372,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,  1455,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,  1456,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,  1502,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,  1578,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  1875,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,  1886,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  1927,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,  2001,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    2017,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  2029,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,     0,  2053,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,     0,     0,  2088,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,  2098,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,     0,     0,  2099,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,     0,  2123,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,     0,     0,  2172,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
       0,     0,  2211,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,     0,
       0,  2229,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,     0,     0,
    2247,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,     0,     0,  2248,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,     0,   735,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,     0,   954,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,     0,  1994,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,   762,     0,
     763,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,  1019,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,  1068,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,  1218,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,  1286,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,  1288,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
       0,     0,  1294,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   734,   599,   600,   601,
     602,     0,     0,     0,     0,   603,     0,     0,     0,  1295,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   734,   599,   600,   601,   602,     0,     0,
       0,     0,   603,     0,     0,     0,  1387,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     734,   599,   600,   601,   602,     0,     0,     0,     0,   603,
       0,     0,     0,  1401,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   734,   599,   600,
     601,   602,     0,     0,     0,     0,   603,     0,     0,     0,
    1607,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,     0,     0,  1695,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   734,   599,   600,   601,   602,     0,     0,     0,     0,
     603,     0,     0,     0,  1748,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   734,   599,
     600,   601,   602,     0,     0,     0,     0,   603,     0,     0,
       0,  1939,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   734,   599,   600,   601,   602,
       0,     0,     0,     0,   603,     0,     0,     0,  1984,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   734,   599,   600,   601,   602,     0,     0,     0,
       0,   603,     0,     0,     0,  2002,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     815,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   816,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     817,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   819,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     820,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   821,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     823,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   824,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     825,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   826,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     827,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   828,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     829,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   831,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     832,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   833,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     902,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,   936,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
     984,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1005,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1008,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1010,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1011,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1017,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1018,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1056,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1067,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1127,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1131,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1143,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1217,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1227,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1228,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1229,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1238,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1240,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1241,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1270,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1272,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1273,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1274,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1275,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1276,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1277,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1278,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1284,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1297,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1299,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1337,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1386,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1400,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1608,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1642,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1682,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1694,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1811,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1813,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1816,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1823,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1876,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1885,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  1912,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    1983,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  2050,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    2051,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603,     0,  2185,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   734,
     599,   600,   601,   602,     0,     0,     0,     0,   603,     0,
    2226,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   734,   599,   600,   601,   602,     0,
       0,     0,     0,   603
};

static const yytype_int16 yycheck[] =
{
       3,   320,     3,   642,   643,  1265,  1269,  1462,   160,  1779,
     201,  1781,  1733,     4,   759,     4,     4,     7,     4,   210,
     765,     6,    25,   146,     6,     4,     3,     5,     4,    63,
       5,     4,     6,     4,     6,     5,   107,  1963,     5,     7,
     107,     6,   142,   109,     6,   111,  1766,     4,   107,   107,
      27,   163,    55,     6,   244,   245,     4,   244,   245,    25,
       9,     9,   244,   245,     4,   163,     4,     4,     4,   257,
       6,     4,   131,   131,   262,   265,   107,   189,   265,   257,
     146,    84,     6,   265,     4,    62,     9,   265,     4,     6,
      93,     9,   192,   205,   206,    98,   244,   245,    36,    37,
     244,   245,     9,    36,    37,    93,   109,     7,   174,     4,
       0,  1831,   256,   304,   305,   306,   260,   265,     6,   256,
      36,    37,   253,   254,   244,   245,     6,  1848,    14,   260,
       6,   244,   245,   142,   259,   244,   245,   114,   244,   245,
     265,    36,    37,   146,     7,   265,   147,     6,   151,   152,
     153,   160,   265,   344,   345,   346,   265,   160,     6,   265,
     169,   170,   171,   244,   245,   101,   175,   176,   256,   146,
     361,   101,   110,   111,   151,   152,   153,   180,     8,   104,
     249,   250,   107,   160,   265,   256,   255,   244,   245,   256,
     120,     9,  2118,   196,   110,   111,   244,   245,   201,     6,
       4,     9,   205,   177,   261,   177,   257,   210,   211,   212,
     104,   256,   200,   107,   265,   110,   111,   265,   259,   196,
     254,   255,   244,   245,   265,   204,   120,   147,   148,   149,
     150,     6,  1687,   153,   332,   212,   244,   245,   227,   227,
     260,   227,   162,   265,   264,   165,   256,    69,    70,     7,
      72,   227,   261,   351,   227,   260,   227,   265,  1518,     7,
     256,     6,   258,   266,   260,     7,   256,   258,   258,   260,
    1991,   256,   260,   264,   263,   260,   253,   280,   260,   227,
     283,   284,   260,     6,   260,   260,   257,   260,   259,   258,
     260,   268,   269,   260,   262,   260,   299,   300,   260,   256,
     303,   304,   305,   306,   451,   253,   254,   256,   256,   258,
     258,   314,   260,   262,   262,   318,   256,   320,   284,   256,
     244,   245,  1067,  1068,   422,  2046,   424,   244,   245,   229,
     230,   231,   232,   256,   262,   258,   434,   265,   256,   342,
     258,   344,   345,   346,   262,   104,   253,   254,   107,   256,
     109,   258,   259,   253,   254,   262,   244,   245,   361,   239,
     240,   120,   262,   239,   240,   368,   229,   230,   231,   232,
     244,   245,   563,     6,   440,   179,   180,   181,   182,   256,
       8,   258,   256,  2153,   256,   262,   260,   191,   265,   193,
     194,   195,   196,   197,   256,   256,   258,   201,   202,   260,
     204,   553,   258,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   256,     7,   244,   245,   255,   260,   430,   256,   432,
     258,   261,   256,   436,   437,   253,   254,   265,   256,   260,
     258,   244,   245,   257,   262,   253,   254,   257,   256,   452,
     258,   265,   122,   430,   262,   265,   459,   261,   244,   245,
     607,   256,   265,   146,   441,   260,   256,  2188,   151,   152,
     153,   229,   230,   231,   232,     4,   244,   245,   256,   265,
     483,   229,   230,   231,   232,   256,   463,   229,   230,   231,
     232,   253,   254,   244,   245,   253,   254,   265,   244,   245,
     477,   323,   324,   569,   244,   245,   509,    36,    37,   331,
     332,   253,   254,   196,   265,   244,   245,  2238,   104,   265,
     256,   107,   108,   109,   257,   265,  1981,   244,   245,   212,
     533,   260,   265,   631,   120,   633,   634,   244,   245,   542,
     543,   244,   245,   260,   547,   257,   549,   550,   551,   552,
     553,   703,   650,   265,   256,   558,   244,   245,   265,   562,
     563,   564,   565,   566,   567,   568,   107,   570,   109,   572,
     547,   669,   549,   107,   551,   552,   553,   265,   244,   245,
     256,   110,   111,   257,   101,   253,   254,   104,   565,   566,
     107,   265,   739,   256,   262,   598,    55,   695,   184,   265,
     256,   604,   568,   120,   570,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   626,   627,   256,   773,   255,   244,   245,
     257,   257,   259,   261,     6,     7,   759,   735,   265,   265,
    1279,   642,   643,   790,   229,   230,   231,   232,   256,   265,
     716,   256,   142,   800,   257,   257,     4,   259,   256,     8,
     189,   190,   265,   265,   256,     6,   258,     4,   253,   254,
     160,   648,   675,   676,   677,     6,   257,   680,   259,   169,
     170,   171,   260,   256,   265,   175,   176,   260,    36,    37,
     147,   148,   262,   261,   264,   672,   153,   265,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   109,   711,   712,
     713,   714,   715,   256,   717,   718,   719,   720,   721,   261,
     257,   724,   259,   265,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   736,   711,   712,   713,   714,   147,   148,
     717,   718,   719,  1488,   153,   779,   749,   430,   814,   256,
     727,   258,   211,   730,   720,   253,   254,   904,   256,   256,
     258,   764,   110,   111,   101,   261,   743,   770,   105,   265,
     256,   261,   258,   101,   111,   112,   104,   114,   115,   107,
     260,   109,   261,   786,   787,   257,   265,   259,   142,   792,
     260,   794,   120,   265,   797,   798,   261,   257,   135,   259,
     265,   778,   805,   780,   807,   265,   160,   266,   253,   254,
     933,   256,     4,   258,     6,   169,   170,   171,   640,   641,
     797,   175,   176,   645,   246,   247,   248,   249,   250,   142,
     807,   107,   104,   255,   837,   107,   839,   109,  1583,   256,
     260,   189,   190,   256,   303,   261,   261,   160,  1593,   265,
     265,   257,   260,   259,   260,   314,   169,   170,   171,   318,
     958,   261,   175,   176,   547,   265,   549,   260,   551,   552,
     261,   874,   261,   261,   265,   104,   265,   265,   104,  2142,
     946,   884,   565,   566,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   107,   906,   104,   142,   255,   261,   257,   261,
     259,   261,     4,   265,  2174,   265,   261,   261,   107,   922,
     265,   265,  1069,   160,   257,   261,   259,   260,   107,   265,
    1053,   934,   169,   170,   171,     4,  2199,     8,   175,   176,
     943,     4,   261,   261,  1067,  1068,   265,   265,   261,     4,
     261,   954,   253,   254,   265,   256,  2216,   258,   256,   260,
     256,  1084,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   436,   437,   256,
     957,   255,   959,   960,   244,   245,   246,   247,   248,   249,
     250,     6,   258,   452,   261,   255,   973,   261,   265,   261,
     261,   265,   261,   265,   265,  1071,   265,   261,   261,   261,
     261,   265,   265,   265,   265,     6,   993,   256,   258,   702,
       6,   704,   705,   706,   707,   708,   709,   260,   711,   712,
     713,   714,     6,   264,   717,   718,   719,  1014,   261,     6,
     261,   261,   265,  1362,   265,   265,   261,   261,   261,   261,
     265,   265,   265,   265,  1201,   264,  1203,   261,   261,  1062,
     261,   265,   265,   260,   265,   256,   261,  1070,   261,  1216,
     265,     9,   265,   261,  1051,  1078,   260,   265,   261,  1718,
    1719,   261,   265,   261,   256,   265,   261,   265,  1091,   256,
     265,   550,   261,  1096,  1217,  1218,   265,   261,  1245,   256,
     261,   265,   261,   562,   265,   564,   265,   261,   261,   261,
     256,   265,   265,   265,   797,   256,   261,   261,   256,  1096,
     265,   265,  1125,  1126,   807,  1128,  1129,  1130,   192,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,   961,
     261,  1144,   192,   261,   265,   261,   968,   265,   261,   265,
     972,   261,   265,   192,   260,   265,   131,   256,   256,   256,
    1307,  1308,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     256,  1184,  1185,  1186,   255,  1332,   257,   192,   260,   256,
     256,   256,  1339,     4,     6,   256,     6,     6,   260,     6,
     260,   260,   260,   260,   256,  1208,   260,   256,  1185,  1186,
     256,  1358,   256,   256,   256,   256,     6,     6,   258,   256,
     258,  1224,  1225,  1226,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   260,  1385,   260,
     260,   255,   260,   260,   192,   258,   258,   256,   256,   256,
     256,     6,  1399,   256,   256,   256,   260,     6,   258,  1406,
       8,     6,     8,  1386,  1387,   260,   256,  1586,     7,     6,
    1247,   260,   260,     6,   261,   260,    96,  1280,  1279,   257,
       7,   265,   265,     6,     6,   257,   262,   260,    67,   260,
     749,   260,   260,   255,     8,  1298,     7,  1300,  1301,     7,
     256,     6,  1124,   257,     6,   260,     7,  1310,     6,   261,
       7,     6,  1315,     6,   189,     6,  1319,   260,   257,   261,
     261,     6,   259,     7,   260,  1328,     6,  1330,   262,   258,
    1333,   256,   260,     6,     6,     6,     6,     6,  1315,   257,
       7,   258,  1319,  1409,     7,  1411,  1349,     7,     7,     7,
       7,  1328,     7,  1330,     7,     7,  1333,     7,  1997,  1362,
       7,     7,     7,     7,     7,     7,  1343,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   260,  1387,     6,   257,   255,     7,  1392,
     259,  1394,   265,   265,   261,   265,   257,   261,     7,   265,
     262,   260,   260,     4,     6,   262,   261,   261,  1411,   260,
    1387,   142,     7,  1096,     6,   262,     7,     7,     7,   257,
    1423,   257,   265,   265,  1427,     9,   265,   257,   259,   262,
     264,   192,     7,   163,   261,   260,     6,     6,     6,    49,
     262,    49,  1594,  1595,   260,   260,     7,   906,   256,   262,
     256,   256,     7,   256,     7,     7,   192,   257,   262,     7,
    1583,     7,     6,   265,   257,     7,   265,     7,     7,     7,
       7,   119,     4,  1571,  1793,   260,     6,  1575,   256,  1482,
    1483,  1484,     7,     6,   943,     7,     7,  1490,  1491,  1492,
       7,     7,     7,     7,     7,   260,   101,     6,     6,     6,
    1566,   107,  1185,  1186,     7,  1508,     7,     6,     6,     4,
       7,     7,   263,   265,   257,   265,  1519,     6,   260,   260,
     260,     6,     6,   261,  1527,     7,     6,     6,  1531,   258,
       6,   256,   256,     6,   260,     6,     6,     6,     6,  1542,
     261,  1544,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
       6,   265,  1628,   262,   255,   259,     6,     6,   135,     6,
    1693,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   257,   257,  1586,     6,     6,     4,     6,   188,   257,
       7,  1594,  1595,     6,   260,   260,     7,  1600,   260,   260,
       6,     6,     6,  1062,   260,     6,   260,   258,     6,     6,
       6,   260,     7,     6,     6,  1618,     6,  1594,  1595,  1078,
     260,   260,   260,   260,   260,  1628,   261,   260,     6,   260,
    1633,   265,  1315,   265,     6,   265,  1319,   265,  1785,   262,
     256,  1618,   260,   256,  1796,  1328,   261,  1330,  1714,     4,
    1333,     7,   256,     6,     6,     6,     6,   105,     6,   142,
       5,   260,   265,   257,   260,     6,  1125,  1126,     6,  1128,
    1129,  1130,   260,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,   142,   142,   265,     6,     6,     6,     6,
       6,     6,   265,  1759,   257,  1517,     6,     6,     6,   265,
    1766,  1767,  1705,   265,  1387,     6,   260,  1710,  1711,   260,
       6,     6,     6,     6,  2033,   260,     7,  1718,  1719,     6,
     146,  1787,     5,     7,   260,  1184,   260,   260,   257,     6,
    1733,     6,   260,     6,   260,     6,  1739,   261,     6,     6,
     260,  1744,   261,   187,     7,   257,     6,     6,     6,  1208,
    1753,   261,     6,     6,     6,   261,   261,     6,  1761,     6,
     262,  1764,     6,     6,     6,  1224,   260,   257,   261,   260,
     190,     6,   260,     6,   261,   261,   257,     6,   256,  1782,
       6,     6,   142,  1786,  1761,   260,   260,  1764,   260,     6,
    1793,     6,  1795,  1796,   260,     6,   261,   260,   260,     6,
     257,     6,  1779,     6,  1781,   261,   261,     6,     6,     6,
       6,     6,     6,     6,     6,   260,     6,   260,     6,  1796,
       6,  1280,   260,  1645,     6,     6,     6,     6,  1831,  1398,
    2155,  1640,  1457,  1924,  1964,  1701,     3,  1080,  1422,  1298,
       3,  1300,  1301,     3,     3,  1848,   619,  1993,  1563,     3,
     797,   480,  1786,  1766,  1831,    -1,  1859,  1860,  1595,     6,
    1926,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,  1884,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
    1349,    -1,    -1,  1896,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1969,    -1,    -1,    -1,    -1,  2006,    -1,
    1913,    -1,  1734,  1735,  1736,  1737,  1738,  1739,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1618,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1950,    -1,    -1,
      -1,    -1,  1411,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1965,    -1,  1423,    -1,    -1,  1970,  1427,    -1,
    1973,  1974,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1991,    -1,
      -1,  1994,    -1,    -1,    -1,    -1,  1997,    -1,    -1,    -1,
      -1,    -1,  2005,    -1,    -1,  2103,  2009,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1482,  1483,  1484,    -1,    -1,    -1,    -1,
    2033,  1490,  1491,  1492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2046,    -1,  2143,    -1,    -1,    -1,  1508,
      -1,    -1,    -1,  2119,    -1,    -1,    -1,    -1,    -1,    -1,
    1519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1527,    -1,
      -1,    -1,  2075,    -1,    -1,    -1,    -1,    -1,  1761,    -1,
      -1,  1764,    -1,  1542,    -1,  1544,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
    2087,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1600,  2145,  2146,  2147,  2148,  2149,    -1,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,  1628,
     255,    -1,    -1,    -1,    -1,    -1,  2153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2188,    -1,    -1,  2010,  2011,
    2012,  2013,  2014,    -1,    -1,    -1,    -1,    -1,  2175,    -1,
      -1,  2204,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,  2225,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2238,    -1,    -1,    26,    -1,
      28,  2244,  2245,    -1,    -1,    -1,  1705,    -1,  2225,    -1,
      -1,    -1,  2074,    -1,  2257,    -1,  2078,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2244,  2245,    -1,
      -1,    -1,    -1,    -1,  1733,    -1,    -1,    -1,    -1,    -1,
    2257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2129,    -1,    -1,
      -1,  2133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1782,    -1,    -1,    -1,  2149,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,  1795,    -1,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,   146,   146,
     255,    -1,    -1,   150,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,  2194,  2195,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1848,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,   185,   186,
     187,    -1,   189,   190,   191,   192,   193,   194,   195,    -1,
     197,   198,   199,   200,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,    -1,    -1,  1884,    -1,    -1,    -1,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   271,   272,    -1,    -1,    -1,    -1,    -1,
      -1,  1950,   279,   280,   281,   282,   283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1965,    -1,    -1,    -1,
      -1,   298,   299,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   316,
      -1,    -1,  1991,    -1,    -1,    -1,    -1,    -1,    -1,   326,
     327,    -1,  2225,    -1,    -1,   332,  2005,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   342,   343,    -1,    -1,    -1,
      -1,  2244,  2245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2257,    -1,    -1,    -1,    -1,    -1,
     367,   368,    -1,    -1,    -1,    -1,   373,  2046,   375,   376,
      -1,   378,    -1,    -1,    -1,   382,   383,   384,    -1,    -1,
     387,   389,   390,   391,    -1,    -1,    -1,   395,   396,   397,
     398,   399,   400,   401,    -1,   403,  2075,    -1,    -1,    -1,
     408,   409,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,
     427,    -1,    -1,    -1,    -1,   432,   433,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   449,   450,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,     6,    -1,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   485,    -1,
      -1,    -1,   255,   490,   257,    -1,   259,   494,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   508,   509,    -1,    -1,    -1,   513,    -1,    -1,  2188,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,    -1,   545,   546,
      -1,   548,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,
     557,    -1,    -1,   560,   561,    -1,    -1,    -1,    -1,  2238,
     567,    -1,    -1,    -1,    -1,   572,    -1,    -1,    -1,    -1,
      -1,    -1,   580,    -1,    -1,    -1,    -1,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,    -1,   605,   606,
      -1,    -1,    -1,    -1,    -1,    -1,   613,   614,   615,    -1,
      -1,    -1,    -1,    -1,   621,   622,   623,   624,    -1,   626,
     627,    -1,   280,    -1,    -1,   283,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,   646,
     647,   299,   300,    -1,   651,   652,   653,   654,   655,   656,
     657,   658,   659,    -1,    -1,    -1,    -1,    -1,   665,   666,
      -1,   668,    -1,    -1,   671,    -1,    -1,    -1,   675,   676,
     677,   678,    -1,   680,   681,   682,   683,    -1,    -1,    -1,
      -1,   688,    -1,   690,   342,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   710,    -1,    -1,    -1,   255,    -1,    -1,
     368,    -1,    -1,    -1,    -1,    -1,   142,   724,    -1,    -1,
      -1,    -1,    -1,    -1,   731,   732,    -1,   734,    -1,    -1,
     737,   738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   746,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   764,    -1,   766,
      -1,    -1,    -1,    -1,   771,   772,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,   786,
      -1,   788,   789,    -1,    -1,   792,    -1,   794,   795,    -1,
      -1,    -1,   799,    -1,    -1,   802,    -1,    -1,    -1,    -1,
      -1,   808,    -1,    -1,    -1,   812,    -1,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,   835,   255,
     837,    -1,   839,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   509,    -1,    -1,    -1,   255,    -1,   257,    -1,     6,
      -1,    -1,    -1,    -1,    -1,   265,    -1,   874,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   533,    -1,   884,   885,   886,
      -1,    -1,    -1,    -1,   542,   543,    -1,    -1,    -1,    -1,
      -1,    -1,   900,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   567,
      -1,    -1,    -1,    -1,   572,   922,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   933,    -1,   934,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   942,    -1,    -1,    -1,   946,
     598,    -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   962,   963,    -1,    -1,    -1,
      -1,   968,    -1,    -1,    -1,    -1,    -1,    -1,   626,   627,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   985,    -1,
      -1,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     299,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,  1013,    -1,  1015,  1016,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,   676,   677,
      -1,    -1,   680,    -1,    -1,    -1,    -1,  1034,    -1,    -1,
      -1,    -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1058,    -1,    -1,    -1,    -1,    -1,    -1,  1065,    -1,
      -1,    -1,    -1,    -1,    -1,  1072,   724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1085,  1086,
      -1,    -1,    -1,    -1,  1091,    -1,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,   764,  1115,   255,    -1,
      -1,    -1,    -1,    -1,    -1,  1122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,   786,    -1,
      -1,    -1,    -1,    -1,   792,    -1,   794,  1144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1170,  1171,  1172,  1173,  1174,    -1,    -1,
      -1,    -1,  1179,  1180,    -1,  1182,    -1,    -1,    -1,   837,
      -1,   839,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1196,
    1197,    -1,    -1,    -1,    -1,    -1,    -1,  1204,  1205,    -1,
      -1,  1209,    -1,    -1,    -1,    -1,  1213,  1214,     6,    -1,
      -1,    -1,  1219,  1220,    -1,    -1,   874,    -1,  1225,  1226,
      -1,    -1,    -1,    -1,    -1,    -1,   884,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,  1259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   572,   922,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   934,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1296,
      -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,    -1,    -1,
      -1,    -1,    -1,  1310,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1318,    -1,    -1,    -1,    -1,    -1,   626,   627,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1340,  1341,    -1,    -1,    -1,  1345,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1356,
      -1,    -1,  1359,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1369,  1370,    -1,    -1,    -1,   675,   676,   677,     7,
       8,   680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1388,    -1,    -1,  1391,  1392,  1393,  1394,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1402,    -1,    -1,  1405,    -1,
    1407,  1408,  1409,    -1,    -1,  1412,  1413,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   724,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1091,    -1,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,  1462,   764,    -1,   255,    -1,    -1,
      -1,    -1,    -1,  1471,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   786,    -1,    -1,
      -1,    -1,  1489,   792,    -1,   794,  1144,    -1,    -1,    -1,
      -1,    -1,  1499,  1500,  1501,    -1,    -1,    -1,    -1,    -1,
      -1,  1508,    -1,  1510,    -1,    -1,    -1,    -1,    -1,    -1,
    1517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1531,    -1,    -1,    -1,    -1,    -1,
    1537,  1538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1548,  1549,  1550,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1569,    -1,    -1,   874,    -1,  1225,  1226,    -1,
      -1,    -1,    -1,    -1,    -1,   884,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1598,  1599,    -1,    -1,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   922,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,    -1,  1632,   934,  1633,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   954,    -1,    -1,    -1,   255,
      -1,    -1,  1310,    -1,    -1,   261,    -1,    -1,    -1,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1674,  1675,  1676,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1685,    -1,
      -1,    -1,    -1,  1690,  1691,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,  1703,    -1,    -1,    -1,
      -1,    -1,    -1,  1710,  1711,  1712,    -1,  1714,    -1,    -1,
      -1,    -1,    -1,  1720,  1721,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1739,    -1,  1392,    -1,  1394,  1744,  1745,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1759,    -1,    -1,  1762,    -1,    -1,    -1,  1766,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1775,  1776,
      -1,  1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1788,  1091,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1802,    -1,    -1,    -1,    -1,
    1807,  1808,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1821,    -1,    -1,  1824,  1825,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,  1144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1859,  1860,    -1,    -1,    -1,    -1,    -1,  1866,
    1867,    -1,    -1,    -1,    -1,    -1,   454,    -1,    -1,    -1,
      -1,  1878,    -1,  1531,    -1,    -1,    -1,    -1,    -1,    -1,
    1887,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1896,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1909,  1910,    -1,    -1,  1913,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1225,  1226,    -1,    -1,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
    1947,  1948,   255,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,  1968,    -1,    -1,    -1,   255,  1973,  1974,  1975,    -1,
     558,    -1,    -1,  1980,    -1,  1633,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1310,  2009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2043,    -1,    -1,    -1,
      -1,    -1,  2049,    -1,    -1,  2052,    -1,    -1,    -1,    -1,
      -1,    -1,  1710,  1711,    -1,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,  2083,   255,    -1,    -1,
      -1,  1739,    -1,  1392,    -1,  1394,  1744,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2109,  2110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2124,  2125,    -1,
    2127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2140,    -1,    -1,    -1,    -1,  2145,  2146,
    2147,  2148,  2149,    -1,    -1,    -1,    -1,    -1,  2155,    -1,
      -1,    -1,  2159,    -1,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,  2186,
      -1,    -1,   261,    -1,  2191,  2192,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2204,    -1,    -1,
      -1,  1859,  1860,    -1,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,  1531,    -1,  2231,  2232,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1896,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1913,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,    -1,   856,   857,
     858,   859,    -1,   861,   862,   863,   864,     6,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   877,
      -1,   879,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   889,    -1,    -1,    -1,    -1,    -1,    -1,   896,   897,
      -1,    -1,    -1,    -1,    -1,  1973,  1974,   905,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     6,    -1,  1994,    -1,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      -1,  2009,    -1,    -1,    78,    -1,    80,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,     6,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,  1710,  1711,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1020,  1021,  1022,  1744,    -1,    -1,  1026,  1027,
       7,    -1,  1030,  1031,  1032,  1033,    -1,  1035,    -1,    -1,
      -1,    -1,  1040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   208,   209,   210,  2145,  2146,  2147,
    2148,  2149,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
     224,    -1,   226,   227,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,   253,
     254,    -1,    -1,  1121,    -1,  1123,   260,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2204,    -1,    -1,    -1,
    1859,  1860,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,  1913,    -1,   255,    -1,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,  1222,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,    -1,  1973,  1974,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,  1994,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,
    2009,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     8,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
    1368,    -1,    -1,    92,    93,    94,    95,    -1,    97,    -1,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,  2127,    -1,
      -1,    -1,  1410,    -1,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,  2145,  2146,  2147,  2148,
    2149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1441,  1442,  1443,  1444,  1445,  1446,  1447,
      -1,    -1,    -1,    -1,  1452,  1453,    -1,    -1,    -1,    -1,
    1458,    -1,  1460,    -1,    -1,    -1,  1464,    -1,    -1,  1467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1478,   200,    -1,    -1,    -1,  2204,    -1,    -1,   207,   208,
     209,   210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,   227,    -1,
     229,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   253,   254,    -1,   256,    -1,   258,
      -1,    -1,    -1,   262,   263,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1554,    -1,  1556,    -1,
      -1,    -1,  1560,    -1,  1562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,    -1,    -1,    -1,   255,  1594,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    -1,    70,    71,    72,    73,    -1,    -1,
      76,    77,    78,    -1,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,  1692,    -1,    92,    93,    94,    95,
      -1,    97,    -1,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,   107,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,    -1,   133,   134,    -1,
     136,    -1,   138,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,   157,   158,    -1,    -1,    -1,   162,    -1,    -1,   165,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1798,    -1,    -1,  1801,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,   210,   211,   212,     8,    -1,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,  1849,  1850,    -1,  1852,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,  1917,
    1918,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    -1,    70,    71,    72,    73,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,  1966,    97,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,    -1,
      -1,    -1,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,     3,
       4,     5,   260,    -1,    -1,   263,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,  2213,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,
      -1,   165,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,   256,     3,     4,    -1,   260,    -1,     8,   263,
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
      -1,    -1,   162,    -1,    -1,   165,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,   256,     3,     4,     5,
      -1,   261,    -1,   263,    10,    11,    12,    -1,    -1,    15,
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
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
     256,     3,     4,    -1,   260,    -1,    -1,   263,    10,    11,
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
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   131,
      -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,   151,
      -1,   153,   154,   155,   156,   157,   158,    -1,    -1,    -1,
     162,    -1,    -1,   165,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    94,    -1,    -1,    97,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,   256,     3,     4,    -1,   260,   261,
      -1,   263,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,   208,   209,   210,    76,    77,
      -1,    -1,    -1,    81,    82,    83,    -1,   220,    -1,    -1,
      -1,   224,    -1,   226,    92,    93,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,   107,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,   120,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,   133,   134,    -1,   136,    -1,
     138,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,   151,    -1,   153,   154,   155,   156,   157,
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    94,    -1,    -1,    97,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,     3,
       4,    -1,   260,    -1,    -1,   263,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,   208,
     209,   210,    76,    77,    -1,    -1,    -1,    81,    82,    83,
      -1,   220,    -1,    -1,    -1,   224,    -1,   226,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,   133,
     134,    -1,   136,    -1,   138,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,    -1,   153,
     154,   155,   156,   157,   158,    -1,    -1,    -1,   162,    -1,
      -1,   165,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,   256,     3,     4,    -1,   260,    -1,    -1,   263,
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
      -1,    -1,   162,    -1,    -1,   165,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,   256,     3,     4,    -1,
     260,    -1,    -1,   263,    10,    11,    12,    -1,    -1,    15,
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
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,    -1,   211,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
     256,     3,     4,    -1,    -1,   261,    -1,   263,    10,    11,
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
     162,    -1,    -1,   165,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,   256,     3,     4,    -1,   260,    -1,
      -1,   263,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,     3,
       4,    -1,   260,    -1,    -1,   263,    10,    11,    12,    -1,
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
      -1,   165,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,   256,     3,     4,    -1,   260,    -1,     8,   263,
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
     120,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,   131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,    -1,   153,   154,   155,   156,   157,   158,    -1,
      -1,    -1,   162,    -1,    -1,   165,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
      -1,   211,   212,    94,    -1,    -1,    97,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,   251,     3,     4,    -1,    -1,   256,     8,    -1,    10,
      11,    12,    -1,   263,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,   208,   209,   210,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,   220,
      -1,    92,    93,   224,    95,   226,   227,    -1,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,   133,   134,    -1,   136,    -1,   138,    -1,    -1,
     141,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,   150,
     151,    -1,   153,   154,   155,   156,   157,   158,    -1,    -1,
      -1,   162,    -1,    -1,   165,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,
     211,   212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,
     221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,     3,     4,    -1,    -1,   256,    -1,    -1,    10,    11,
      12,    -1,   263,    15,    16,    17,    18,    19,    20,    21,
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
     162,    -1,    -1,   165,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,    -1,   211,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,   256,     3,     4,    -1,   260,    -1,
      -1,   263,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,    -1,    -1,    -1,   162,    -1,    -1,   165,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,    -1,    -1,   217,
     218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   244,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,     3,
       4,    -1,   260,    -1,    -1,   263,    10,    11,    12,    -1,
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
      -1,   165,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,   212,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,     3,     4,
       5,    -1,   256,    -1,    -1,    10,    11,    12,    -1,   263,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,   260,    -1,    -1,   263,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   226,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,   256,     3,     4,     5,
     260,    -1,    -1,   263,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,   260,    -1,    -1,   263,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,
     211,    -1,    -1,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,     3,     4,    -1,    -1,   256,    -1,    -1,    10,    11,
      12,    -1,   263,    15,    16,    17,    18,    19,    20,    21,
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
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,   207,    -1,    -1,    -1,   211,
      -1,    -1,   265,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,
      -1,   263,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,   265,   211,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
     256,     3,     4,    -1,   260,    -1,     8,   263,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
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
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,   207,    -1,    -1,    -1,   211,
      -1,    -1,   265,    -1,    -1,   217,   218,   219,    -1,   221,
     222,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,
      -1,   263,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,   207,    -1,    -1,   265,   211,    -1,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,   221,   222,   223,    -1,    -1,
      -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,     3,     4,    -1,     6,
     256,   257,    -1,    10,    11,    12,    -1,   263,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    95,     3,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,   221,   222,   223,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,   263,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   211,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,     3,     4,
      -1,     6,   256,    -1,    -1,    10,    11,    12,    -1,   263,
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
      -1,    -1,    -1,    92,    93,    -1,    95,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,   207,    -1,    -1,    -1,   211,    -1,    -1,   265,
      -1,    -1,   217,   218,   219,    -1,   221,   222,   223,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,   263,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,
      -1,   265,   211,    -1,    -1,    -1,    -1,    -1,   217,   218,
     219,    -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,
      -1,    -1,   251,     3,     4,    -1,    -1,   256,   257,    -1,
      10,    11,    12,    -1,   263,    15,    16,    17,    18,    19,
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
      -1,    95,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,   207,    -1,    -1,
      -1,   211,    -1,    -1,   265,    -1,    -1,   217,   218,   219,
      -1,   221,   222,   223,    -1,    -1,    -1,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,   256,   257,    -1,    -1,
      -1,    -1,    -1,   263,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,    -1,   207,    -1,    -1,   265,   211,    -1,    -1,
      -1,    -1,    -1,   217,   218,   219,    -1,   221,   222,   223,
       4,     5,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,    63,
      64,    65,     4,     5,    -1,    -1,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,   107,    -1,   109,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   120,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,   138,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    13,    14,
      -1,    -1,    -1,    -1,   208,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,    -1,    -1,
     224,    -1,   226,   227,    -1,    -1,    -1,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,   257,    -1,   259,   260,    13,    14,   265,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,    -1,
      -1,    -1,   224,    -1,   226,   227,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   131,   132,   260,    -1,
     135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    13,    14,   123,    -1,   184,
     185,   186,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    13,    14,   255,    -1,   184,   185,
     186,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,    -1,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,   159,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,   117,   118,
     119,   120,    13,    14,   123,    -1,   184,   185,   186,    -1,
      -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    13,    14,   255,    -1,   184,   185,   186,    -1,    -1,
      -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     131,   132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   159,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    -1,    -1,    -1,   117,   118,   119,   120,    13,
      14,   123,    -1,   184,   185,   186,    -1,    -1,    -1,   131,
     132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    13,    14,
     255,    -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,
     265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,    -1,
      -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,   159,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,    -1,   117,   118,   119,   120,    13,    14,   123,    -1,
     184,   185,   186,    -1,    -1,    -1,   131,   132,    -1,    -1,
     135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    13,    14,   255,    -1,   184,
     185,   186,    -1,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,    -1,    -1,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
      -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,   159,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    -1,    -1,    -1,   117,
     118,   119,   120,    13,    14,   123,    -1,   184,   185,   186,
      -1,    -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,
     138,   139,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    13,    14,   255,    -1,   184,   185,   186,    -1,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    -1,    -1,    -1,   117,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,   139,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,   159,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    -1,    -1,    -1,   117,   118,   119,   120,
      13,    14,   123,    -1,   184,   185,   186,    -1,    -1,    -1,
     131,   132,    -1,    -1,   135,   136,    -1,   138,   139,    -1,
     141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    13,
      14,   255,    -1,   184,   185,   186,    -1,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,   159,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      -1,    -1,    -1,   117,   118,   119,   120,    13,    14,   123,
      -1,   184,   185,   186,    -1,    -1,    -1,   131,   132,    -1,
      -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     184,   185,   186,    -1,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,    -1,    -1,
      -1,   117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   131,   132,    -1,    -1,   135,
     136,    -1,   138,   139,    -1,   141,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,     4,    -1,   261,    -1,    -1,
      -1,    -1,    -1,   159,    13,    14,    -1,    -1,    -1,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   184,   185,
     186,   255,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   261,    -1,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,   172,   173,   174,    -1,    -1,    -1,   178,
      -1,    -1,    -1,    -1,   183,   184,   185,   186,    -1,    -1,
     189,    -1,   191,    -1,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,     4,
      -1,    -1,    -1,    -1,   213,   214,   215,   216,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   225,    -1,   227,   228,
      -1,    -1,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    46,    47,    48,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    84,
      85,    86,    87,    88,    -1,    90,    91,    -1,    93,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    -1,
      -1,   116,   117,   118,   119,   120,   121,    -1,   123,    -1,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,   172,   173,   174,
      -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,   183,   184,
     185,   186,     4,     5,   189,    -1,   191,    -1,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,    -1,    -1,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,    -1,   227,   228,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      62,    63,    64,    65,    13,    14,    -1,    -1,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,   107,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    -1,    -1,    -1,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   131,   132,    -1,    -1,   135,   136,    -1,   138,
     139,    -1,   141,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,    -1,
     159,    -1,    -1,    -1,   163,    -1,    -1,    -1,   220,    -1,
      -1,    -1,   224,    -1,   226,   227,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,   186,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    -1,    -1,    -1,   117,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,    -1,   138,   139,    -1,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,   184,   185,   186,    -1,    -1,    -1,    -1,    -1,   265,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   265,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   265,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   265,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   265,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     265,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,   261,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,   261,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,   261,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,   261,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,   261,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,   261,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
     261,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,   261,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,   261,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,   261,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,   261,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,   261,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,   261,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
     261,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,   261,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,   261,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,   261,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,   261,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,    -1,    -1,   261,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
      -1,    -1,   261,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,   261,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
     261,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,   261,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,    -1,   260,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,    -1,   260,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    -1,   260,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,   257,    -1,
     259,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,   259,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,   259,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,   259,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,   259,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,   259,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,   259,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,   259,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,   259,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,   259,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
     259,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,    -1,    -1,   259,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,    -1,    -1,    -1,
     255,    -1,    -1,    -1,   259,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,    -1,
      -1,   259,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,   259,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,   259,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255,    -1,   257,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
     257,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,    -1,
      -1,    -1,    -1,   255
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   267,   268,     6,     0,     4,    13,    14,    46,
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
     228,   269,   271,   272,   293,   312,   314,   318,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   336,   338,   339,
     345,   346,   347,   348,   354,   378,   379,   260,   264,    14,
     107,   256,   256,   256,     6,   260,     6,     6,     6,     6,
     256,     6,     6,   260,   260,     6,     6,   258,   258,     4,
     356,   379,   256,   258,   290,   101,   104,   107,   109,   314,
     290,   256,   256,   256,     4,   256,   256,   256,     4,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     260,   122,   107,     6,     6,   260,   101,   104,   107,   120,
     317,   109,   256,     3,    10,    11,    12,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    58,    59,
      60,    61,    66,    67,    76,    77,    81,    82,    83,    92,
      95,   101,   104,   107,   109,   120,   131,   136,   138,   141,
     207,   211,   212,   217,   218,   219,   221,   222,   223,   244,
     245,   251,   256,   260,   263,   314,   315,   318,   329,   336,
     338,   349,   350,   354,   356,   362,   364,   379,   256,   260,
     260,   107,   107,   131,   104,   107,   109,   314,   104,   107,
     108,   109,   120,   184,   315,   104,   107,   256,   104,   163,
     189,   205,   206,   260,   244,   245,   256,   260,   359,   360,
     359,   260,   260,   359,     4,   101,   105,   111,   112,   114,
     115,   135,   260,   256,   107,   109,   107,   104,     4,    93,
     200,   260,   379,     4,     6,   101,   104,   107,   104,   107,
     120,   316,   107,     4,     4,     4,     5,   256,   260,   362,
     363,     4,   107,   256,   107,   256,   256,     4,   260,   366,
     379,     4,   256,   256,   256,     6,     6,   258,     5,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    62,    63,
      64,    65,    70,    71,    72,    73,    78,    80,    94,    97,
     208,   209,   210,   220,   224,   226,   370,   379,   256,     4,
     370,     5,   260,     5,   260,   314,    32,   245,   349,   379,
     258,     6,   260,   256,   260,     6,   256,   260,     6,   264,
       7,   138,   200,   229,   230,   231,   232,   253,   254,   256,
     258,   262,   288,   289,   290,   314,   349,   369,   370,   379,
       4,   318,   319,   320,   260,     6,   349,   369,   370,   379,
     369,   369,   349,   369,   376,   377,   379,   320,   349,   295,
     299,   256,   358,     9,   370,   256,   379,   349,   349,   349,
     256,   349,   349,   349,   256,   349,   349,   349,   349,   349,
     349,   349,   369,   349,   349,   349,   349,   363,   256,   245,
     349,   364,   365,   260,   363,   362,   369,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   256,   258,   290,   290,   290,   290,   290,   290,
     256,   290,   290,   256,   314,   315,   315,   290,   290,     5,
     260,   260,   131,   314,   314,   256,   290,   290,   256,   256,
     256,   349,   260,   349,   364,   349,   349,   261,   365,   356,
     379,   192,     5,   260,     8,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   255,     9,   256,   258,   262,   289,   290,
     349,   365,   365,   256,   256,   256,   362,   363,   363,   363,
     313,   256,   260,   256,   256,   362,   260,   260,   349,     4,
     362,   260,   366,   260,   260,   359,   359,   359,   349,   349,
     244,   245,   260,   260,   359,   244,   245,   256,   320,   359,
     260,   256,   260,   256,   256,   256,   256,   256,   256,   256,
     365,   349,   363,   363,   363,   256,   260,     4,   258,   260,
       6,   258,   320,     6,     6,   260,   260,   260,   260,   363,
     260,   258,   258,   258,   349,     8,     6,     6,   256,   349,
     256,   349,   349,   262,   349,   260,   192,   349,   349,   349,
     349,   290,   290,   290,   256,   256,   256,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   256,   256,   290,
     256,   258,     6,     6,   260,     6,     8,   320,     6,     8,
     320,   256,   290,   349,   246,   260,     9,   256,   258,   262,
     369,   365,   349,   320,   362,   362,   260,   370,   314,     7,
     349,   349,     4,    36,    37,   110,   111,   189,   190,   292,
     362,     6,   257,   259,   260,   291,   260,     6,   260,     6,
       9,   256,   258,   262,   379,   261,   131,   136,   138,   139,
     141,   312,   314,   349,     6,   257,   265,     9,   256,   258,
     262,   257,   265,   257,   265,   265,   257,   265,     9,   256,
     262,   261,   265,   259,   265,   294,   259,   294,    96,   357,
     355,   379,   265,   349,   265,   257,   257,   257,   349,   257,
     257,   257,   349,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   261,     7,   349,   246,   261,   265,
     349,     6,     6,   257,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   364,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   364,   364,   379,   260,   349,   349,   369,   349,   369,
     362,   369,   369,   376,   260,   260,   260,   349,   291,   379,
       8,   349,   349,   363,   362,   369,   369,   364,   356,   370,
     356,   365,   257,   261,   262,   290,    67,     8,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   260,   349,   364,   349,   349,   349,   349,   349,
     379,   349,   349,   292,   260,   291,   257,   261,   261,   349,
     349,   349,     7,     7,   342,   342,   256,   349,   349,   349,
     349,     6,   365,   365,   260,   257,     6,   320,   260,   320,
     320,   265,   265,   265,   359,   359,   319,   319,   265,   349,
     261,   333,   265,   320,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   261,   257,     7,   343,     6,     7,   349,
     349,     6,   349,   320,   349,   261,   365,   365,   365,   349,
       6,   365,   349,   349,   349,   257,   261,   349,   257,   349,
     257,   257,   189,   265,   320,   260,     8,   257,   257,   259,
     376,   369,   376,   369,   369,   369,   369,   369,   369,   349,
     369,   369,   369,   369,   263,   372,   379,   370,   369,   369,
     369,   356,   379,   365,   261,   261,   261,   261,   349,   349,
     349,   320,   379,   292,   259,   261,   257,   145,   163,   337,
     257,   261,   265,   349,     6,   260,   362,   257,   259,   262,
       7,     7,   288,   289,     6,   365,     7,   232,   288,   349,
     273,   379,   349,   349,   292,   258,   256,   131,   314,   315,
     314,   260,   261,     6,   239,   240,   270,   365,   379,   349,
     349,   292,     6,   365,     6,   365,   349,     6,   369,   377,
     379,   257,   292,   349,     6,   379,     6,   369,   349,   257,
     258,   349,   265,   370,     7,     7,     7,   257,     7,     7,
       7,   257,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   349,   257,   260,   349,   364,   261,     6,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     265,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     265,   265,   265,   265,   265,   257,   259,   259,   365,   265,
     265,   291,   265,   291,   265,   265,   265,   257,   365,   349,
     349,   351,   291,   261,   261,   261,   265,   265,   291,   291,
     257,   262,   257,   262,   265,   290,   352,   261,     7,   292,
     291,   362,   261,     8,     8,   365,   262,   257,   259,   256,
     258,   289,   290,   365,     7,   260,   260,   257,   257,   257,
     349,   362,     4,   341,     6,   308,   349,   370,   257,   261,
     257,   257,   261,   261,   365,   262,   261,   320,   261,   261,
     359,   349,   349,   261,   261,   349,   359,   142,   142,   160,
     169,   170,   171,   175,   176,   334,   335,   359,   261,   330,
     257,   261,   257,   257,   257,   257,   257,   257,   257,   260,
       7,   349,     6,   349,   257,   261,   259,   261,   259,   261,
     261,   261,   261,   261,   259,   259,   265,   257,     7,   257,
       7,     7,   262,   349,   261,   349,   349,     7,   262,   291,
     265,   291,   291,   257,   257,   265,   291,   291,   265,   265,
     291,   291,   291,   291,   349,   291,     9,   371,   265,   257,
     265,   291,   262,   265,   353,   259,   261,   257,   261,   262,
     256,   258,   264,   192,     7,   163,     6,   349,   261,   260,
       6,   362,   261,   349,     6,     7,   288,   289,   262,   288,
     289,   292,   260,   367,   379,   370,   349,     6,   261,    49,
      49,   362,   261,     4,   179,   180,   181,   182,   261,   276,
     280,   283,   285,   286,   328,   262,   257,   259,   256,   349,
     349,   256,   260,   256,   260,     8,   365,   369,   257,   262,
     257,   259,   256,   257,   257,   265,   262,   256,   265,     7,
     290,     4,    36,    37,   302,   303,   304,   291,   349,   291,
     359,   362,   362,     7,   362,   362,   362,     7,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,     6,     7,
     365,   349,   349,   349,   349,   349,   349,   261,   349,   349,
     349,   362,   369,   369,   261,   261,   261,   265,   301,   349,
     349,   292,   292,   349,   349,   257,   362,   290,   349,   349,
     261,   292,   289,   262,   289,   349,   349,   291,   261,   362,
     365,   365,     7,     7,     7,   142,   340,     6,   257,   265,
       7,     7,     7,     7,     7,   261,     4,   292,   261,   265,
     265,   265,   261,   261,   119,     4,     6,   349,   260,     6,
     256,     6,   177,     6,   177,   261,   335,   265,   334,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   319,   362,
       6,   260,   101,     6,     6,     6,   107,     7,     7,     6,
       6,   349,     7,   362,     7,   362,   362,     4,   265,     8,
       8,   257,   292,   292,   365,   369,   349,   369,   263,   265,
     305,   369,   369,   292,   369,   257,   265,     6,   292,   260,
     314,   260,     6,   349,     6,   260,   362,   261,   261,   349,
       6,   189,   190,   292,   349,     6,     7,   366,   368,     6,
     258,     6,     6,   291,   290,   290,     6,   277,   256,   256,
     260,   287,     6,   292,   262,   369,   349,   259,   257,   349,
       8,   365,   349,   365,   261,   261,     6,     6,   270,   292,
     262,   349,     6,     6,   349,   292,   257,   349,   260,   349,
     370,   291,    49,   260,   362,   370,   373,   349,   349,   259,
     265,     6,   257,     6,     6,   135,   310,   310,   362,     6,
       6,     6,   362,   142,   192,   309,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     5,   261,   291,   291,   291,
     291,   291,   291,   291,   265,   265,   265,   257,   291,   291,
     303,   291,   257,   291,   257,   290,   352,   291,     6,   291,
     256,   258,   290,   292,   257,   259,   291,     6,   261,   261,
     362,   362,   362,     4,     6,   288,   349,   362,   362,   362,
     260,   260,     7,     6,     7,   349,   349,   349,   260,   260,
     260,   258,     6,   349,   362,   349,     6,     6,   349,   359,
     261,     5,   362,   260,   260,   260,   260,   260,   260,   260,
     362,   261,     6,   365,   260,   260,   349,   349,   259,   362,
       6,   362,     6,   188,   349,   349,   349,     6,     6,     7,
     291,   265,   265,   291,   265,   349,     4,   204,   306,   307,
     291,   257,   291,   353,   370,   256,   258,   349,   260,   320,
       6,   320,   265,     6,     6,   262,     7,     7,   288,   289,
       6,   366,   261,   265,   349,   288,   260,   291,   374,   375,
     376,   374,   256,   349,   349,   361,   362,   260,   256,     4,
       6,   257,     6,   257,   261,   261,   257,   261,     6,     6,
     369,   256,     4,   257,   265,   256,   261,   265,   362,   370,
       7,   290,   300,   349,   364,   304,     6,   359,     6,     6,
       6,   142,   311,   101,   120,   105,     6,     5,   260,   349,
     349,   349,   349,   257,   352,   349,   349,   291,   289,   260,
     260,     6,   309,     6,   349,   362,   142,   142,     4,     6,
     365,   365,   349,   349,   370,   261,   257,   261,   265,   319,
     319,   349,   349,   261,   265,   257,   261,   265,     6,     6,
     361,   359,   359,   359,   359,   359,   245,   359,     6,   261,
     365,   349,     6,     6,     6,     6,     6,   362,   261,   265,
       8,   261,   257,   260,   349,   370,   369,   349,   369,   349,
     370,   373,   375,   370,   265,   257,   265,   261,   349,   337,
     337,   362,   292,   367,   370,   349,     6,     6,   366,   259,
     362,   376,     6,   291,   291,   274,   349,   265,   265,   261,
     265,   275,   349,   349,     6,     6,     6,     6,   349,   349,
     257,     6,   349,   296,   298,   260,   375,   261,   265,     7,
       7,   146,     6,   260,   260,   260,     5,   361,   291,   291,
     265,   291,   257,   257,   259,   365,   365,     6,     6,   349,
     349,   260,   261,   261,   260,     6,     6,   260,   349,   261,
     261,   261,   259,     6,   362,     7,   260,   349,   261,   265,
     265,   265,   265,   265,   265,     6,   261,   261,   187,   349,
     349,   365,     6,     6,   257,   291,   291,   307,   370,   261,
     261,   261,   261,     7,     6,     6,     6,   262,     6,   261,
       6,     6,   257,   265,   349,   349,   260,   362,   261,   265,
     257,   257,   265,   261,   301,   305,   362,   291,   349,   370,
     379,   365,   365,   349,     6,   261,   349,   352,   261,   261,
       6,     6,   361,   147,   148,   153,   344,   147,   148,   344,
     365,   319,   261,   265,     6,   261,   362,   320,   261,     6,
     365,   359,   359,   359,   359,   359,     6,   349,   261,   261,
     261,   257,     6,   260,     6,   366,   190,   278,   349,   265,
     265,   361,     6,   349,   349,     6,   261,   261,   297,     7,
     256,   261,   261,   261,   260,   265,   257,   260,   261,   260,
     359,   362,     6,   260,   359,     6,   261,   261,   349,     6,
     142,   261,   331,   260,   261,   265,   265,   265,   265,   265,
       6,     6,     6,   320,     6,   260,   349,   349,   261,   265,
     301,   370,   257,   349,   349,   365,     6,   359,     6,   359,
       6,     6,   261,   349,   334,   320,     6,   365,   365,   365,
     365,   359,   365,   337,   275,   257,   265,     6,   260,   349,
     261,   265,   265,   261,   265,   265,     6,   261,   261,   332,
     261,   261,   261,   261,   265,   261,   261,   261,   281,   349,
     361,   261,   349,   349,   359,   359,   334,     6,     6,     6,
       6,   365,     6,     6,     6,   260,   257,   261,     6,   261,
     291,   265,   265,   261,   261,   279,   369,   284,   260,     6,
     349,   349,     6,   261,   265,   260,   361,   261,   261,     6,
     369,   282,   369,   261,     6,     6,   261,   265,     6,     6,
     369
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
#line 5906 "Gmsh.y"
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
#line 5916 "Gmsh.y"
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
#line 5926 "Gmsh.y"
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

  case 547:
#line 5938 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 548:
#line 5942 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 549:
#line 5947 "Gmsh.y"
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

  case 550:
#line 5959 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 551:
#line 5963 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 552:
#line 5967 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 553:
#line 5971 "Gmsh.y"
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

  case 554:
#line 5989 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 555:
#line 5997 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 556:
#line 6005 "Gmsh.y"
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

  case 557:
#line 6034 "Gmsh.y"
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

  case 558:
#line 6044 "Gmsh.y"
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

  case 559:
#line 6060 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 560:
#line 6071 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 561:
#line 6076 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 562:
#line 6080 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 563:
#line 6084 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 564:
#line 6096 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 565:
#line 6100 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 566:
#line 6112 "Gmsh.y"
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

  case 567:
#line 6129 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 568:
#line 6139 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 569:
#line 6143 "Gmsh.y"
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

  case 570:
#line 6158 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 571:
#line 6163 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 572:
#line 6170 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 573:
#line 6174 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 574:
#line 6179 "Gmsh.y"
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
#line 6193 "Gmsh.y"
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
#line 6207 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 577:
#line 6211 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 578:
#line 6215 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 579:
#line 6219 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 580:
#line 6223 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 581:
#line 6231 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 582:
#line 6237 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 583:
#line 6246 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 584:
#line 6250 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 585:
#line 6254 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 586:
#line 6262 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 587:
#line 6268 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 588:
#line 6274 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 589:
#line 6278 "Gmsh.y"
    {
      std::string env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((env.size() + 1) * sizeof(char));
      strcpy((yyval.c), env.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 590:
#line 6285 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 591:
#line 6293 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 592:
#line 6300 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 593:
#line 6309 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 594:
#line 6313 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 595:
#line 6317 "Gmsh.y"
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

  case 596:
#line 6332 "Gmsh.y"
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

  case 597:
#line 6346 "Gmsh.y"
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

  case 598:
#line 6360 "Gmsh.y"
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

  case 599:
#line 6372 "Gmsh.y"
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

  case 600:
#line 6388 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 601:
#line 6397 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 602:
#line 6406 "Gmsh.y"
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

  case 603:
#line 6416 "Gmsh.y"
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

  case 604:
#line 6427 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 605:
#line 6435 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 606:
#line 6443 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 607:
#line 6447 "Gmsh.y"
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

  case 608:
#line 6466 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 609:
#line 6473 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 610:
#line 6479 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 611:
#line 6485 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 612:
#line 6492 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 613:
#line 6499 "Gmsh.y"
    { init_options(); ;}
    break;

  case 614:
#line 6501 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 615:
#line 6509 "Gmsh.y"
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

  case 616:
#line 6533 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 617:
#line 6535 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 618:
#line 6541 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 619:
#line 6546 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 620:
#line 6548 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 621:
#line 6553 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 622:
#line 6558 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 623:
#line 6563 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 624:
#line 6565 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 625:
#line 6569 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 626:
#line 6581 "Gmsh.y"
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

  case 627:
#line 6595 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 628:
#line 6599 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 629:
#line 6606 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 630:
#line 6614 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 631:
#line 6622 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 632:
#line 6633 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 633:
#line 6635 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 634:
#line 6638 "Gmsh.y"
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


#line 6641 "Gmsh.y"


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

