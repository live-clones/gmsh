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
     tFmod = 291,
     tModulo = 292,
     tHypot = 293,
     tList = 294,
     tLinSpace = 295,
     tLogSpace = 296,
     tListFromFile = 297,
     tCatenary = 298,
     tPrintf = 299,
     tError = 300,
     tWarning = 301,
     tStr = 302,
     tSprintf = 303,
     tStrCat = 304,
     tStrPrefix = 305,
     tStrRelative = 306,
     tStrReplace = 307,
     tAbsolutePath = 308,
     tDirName = 309,
     tStrSub = 310,
     tStrLen = 311,
     tFind = 312,
     tStrFind = 313,
     tStrCmp = 314,
     tStrChoice = 315,
     tUpperCase = 316,
     tLowerCase = 317,
     tLowerCaseIn = 318,
     tTextAttributes = 319,
     tBoundingBox = 320,
     tDraw = 321,
     tSetChanged = 322,
     tToday = 323,
     tFixRelativePath = 324,
     tCurrentDirectory = 325,
     tCurrentFileName = 326,
     tSyncModel = 327,
     tNewModel = 328,
     tMass = 329,
     tCenterOfMass = 330,
     tOnelabAction = 331,
     tOnelabRun = 332,
     tCodeName = 333,
     tCpu = 334,
     tMemory = 335,
     tTotalMemory = 336,
     tCreateTopology = 337,
     tCreateGeometry = 338,
     tClassifySurfaces = 339,
     tRenumberMeshNodes = 340,
     tRenumberMeshElements = 341,
     tDistanceFunction = 342,
     tDefineConstant = 343,
     tUndefineConstant = 344,
     tDefineNumber = 345,
     tDefineStruct = 346,
     tNameStruct = 347,
     tDimNameSpace = 348,
     tAppend = 349,
     tDefineString = 350,
     tSetNumber = 351,
     tSetTag = 352,
     tSetString = 353,
     tPoint = 354,
     tCircle = 355,
     tEllipse = 356,
     tCurve = 357,
     tSphere = 358,
     tPolarSphere = 359,
     tSurface = 360,
     tSpline = 361,
     tVolume = 362,
     tBox = 363,
     tCylinder = 364,
     tCone = 365,
     tTorus = 366,
     tEllipsoid = 367,
     tQuadric = 368,
     tShapeFromFile = 369,
     tRectangle = 370,
     tDisk = 371,
     tWire = 372,
     tGeoEntity = 373,
     tCharacteristic = 374,
     tLength = 375,
     tParametric = 376,
     tElliptic = 377,
     tRefineMesh = 378,
     tAdaptMesh = 379,
     tRelocateMesh = 380,
     tReorientMesh = 381,
     tSetFactory = 382,
     tThruSections = 383,
     tWedge = 384,
     tFillet = 385,
     tChamfer = 386,
     tPlane = 387,
     tRuled = 388,
     tTransfinite = 389,
     tPhysical = 390,
     tCompound = 391,
     tPeriodic = 392,
     tParent = 393,
     tUsing = 394,
     tPlugin = 395,
     tDegenerated = 396,
     tRecursive = 397,
     tSewing = 398,
     tRotate = 399,
     tTranslate = 400,
     tSymmetry = 401,
     tDilate = 402,
     tExtrude = 403,
     tLevelset = 404,
     tAffine = 405,
     tBooleanUnion = 406,
     tBooleanIntersection = 407,
     tBooleanDifference = 408,
     tBooleanSection = 409,
     tBooleanFragments = 410,
     tThickSolid = 411,
     tRecombine = 412,
     tSmoother = 413,
     tSplit = 414,
     tDelete = 415,
     tCoherence = 416,
     tIntersect = 417,
     tMeshAlgorithm = 418,
     tReverseMesh = 419,
     tMeshSizeFromBoundary = 420,
     tLayers = 421,
     tScaleLast = 422,
     tHole = 423,
     tAlias = 424,
     tAliasWithOptions = 425,
     tCopyOptions = 426,
     tQuadTriAddVerts = 427,
     tQuadTriNoNewVerts = 428,
     tRecombLaterals = 429,
     tTransfQuadTri = 430,
     tText2D = 431,
     tText3D = 432,
     tInterpolationScheme = 433,
     tTime = 434,
     tCombine = 435,
     tBSpline = 436,
     tBezier = 437,
     tNurbs = 438,
     tNurbsOrder = 439,
     tNurbsKnots = 440,
     tColor = 441,
     tColorTable = 442,
     tFor = 443,
     tIn = 444,
     tEndFor = 445,
     tIf = 446,
     tElseIf = 447,
     tElse = 448,
     tEndIf = 449,
     tExit = 450,
     tAbort = 451,
     tField = 452,
     tReturn = 453,
     tCall = 454,
     tSlide = 455,
     tMacro = 456,
     tShow = 457,
     tHide = 458,
     tGetValue = 459,
     tGetStringValue = 460,
     tGetEnv = 461,
     tGetString = 462,
     tGetNumber = 463,
     tUnique = 464,
     tHomology = 465,
     tCohomology = 466,
     tBetti = 467,
     tExists = 468,
     tFileExists = 469,
     tGetForced = 470,
     tGetForcedStr = 471,
     tGMSH_MAJOR_VERSION = 472,
     tGMSH_MINOR_VERSION = 473,
     tGMSH_PATCH_VERSION = 474,
     tGmshExecutableName = 475,
     tSetPartition = 476,
     tNameToString = 477,
     tStringToName = 478,
     tAFFECTDIVIDE = 479,
     tAFFECTTIMES = 480,
     tAFFECTMINUS = 481,
     tAFFECTPLUS = 482,
     tOR = 483,
     tAND = 484,
     tNOTEQUAL = 485,
     tEQUAL = 486,
     tGREATERGREATER = 487,
     tLESSLESS = 488,
     tGREATEROREQUAL = 489,
     tLESSOREQUAL = 490,
     UNARYPREC = 491,
     tMINUSMINUS = 492,
     tPLUSPLUS = 493
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
#define tFmod 291
#define tModulo 292
#define tHypot 293
#define tList 294
#define tLinSpace 295
#define tLogSpace 296
#define tListFromFile 297
#define tCatenary 298
#define tPrintf 299
#define tError 300
#define tWarning 301
#define tStr 302
#define tSprintf 303
#define tStrCat 304
#define tStrPrefix 305
#define tStrRelative 306
#define tStrReplace 307
#define tAbsolutePath 308
#define tDirName 309
#define tStrSub 310
#define tStrLen 311
#define tFind 312
#define tStrFind 313
#define tStrCmp 314
#define tStrChoice 315
#define tUpperCase 316
#define tLowerCase 317
#define tLowerCaseIn 318
#define tTextAttributes 319
#define tBoundingBox 320
#define tDraw 321
#define tSetChanged 322
#define tToday 323
#define tFixRelativePath 324
#define tCurrentDirectory 325
#define tCurrentFileName 326
#define tSyncModel 327
#define tNewModel 328
#define tMass 329
#define tCenterOfMass 330
#define tOnelabAction 331
#define tOnelabRun 332
#define tCodeName 333
#define tCpu 334
#define tMemory 335
#define tTotalMemory 336
#define tCreateTopology 337
#define tCreateGeometry 338
#define tClassifySurfaces 339
#define tRenumberMeshNodes 340
#define tRenumberMeshElements 341
#define tDistanceFunction 342
#define tDefineConstant 343
#define tUndefineConstant 344
#define tDefineNumber 345
#define tDefineStruct 346
#define tNameStruct 347
#define tDimNameSpace 348
#define tAppend 349
#define tDefineString 350
#define tSetNumber 351
#define tSetTag 352
#define tSetString 353
#define tPoint 354
#define tCircle 355
#define tEllipse 356
#define tCurve 357
#define tSphere 358
#define tPolarSphere 359
#define tSurface 360
#define tSpline 361
#define tVolume 362
#define tBox 363
#define tCylinder 364
#define tCone 365
#define tTorus 366
#define tEllipsoid 367
#define tQuadric 368
#define tShapeFromFile 369
#define tRectangle 370
#define tDisk 371
#define tWire 372
#define tGeoEntity 373
#define tCharacteristic 374
#define tLength 375
#define tParametric 376
#define tElliptic 377
#define tRefineMesh 378
#define tAdaptMesh 379
#define tRelocateMesh 380
#define tReorientMesh 381
#define tSetFactory 382
#define tThruSections 383
#define tWedge 384
#define tFillet 385
#define tChamfer 386
#define tPlane 387
#define tRuled 388
#define tTransfinite 389
#define tPhysical 390
#define tCompound 391
#define tPeriodic 392
#define tParent 393
#define tUsing 394
#define tPlugin 395
#define tDegenerated 396
#define tRecursive 397
#define tSewing 398
#define tRotate 399
#define tTranslate 400
#define tSymmetry 401
#define tDilate 402
#define tExtrude 403
#define tLevelset 404
#define tAffine 405
#define tBooleanUnion 406
#define tBooleanIntersection 407
#define tBooleanDifference 408
#define tBooleanSection 409
#define tBooleanFragments 410
#define tThickSolid 411
#define tRecombine 412
#define tSmoother 413
#define tSplit 414
#define tDelete 415
#define tCoherence 416
#define tIntersect 417
#define tMeshAlgorithm 418
#define tReverseMesh 419
#define tMeshSizeFromBoundary 420
#define tLayers 421
#define tScaleLast 422
#define tHole 423
#define tAlias 424
#define tAliasWithOptions 425
#define tCopyOptions 426
#define tQuadTriAddVerts 427
#define tQuadTriNoNewVerts 428
#define tRecombLaterals 429
#define tTransfQuadTri 430
#define tText2D 431
#define tText3D 432
#define tInterpolationScheme 433
#define tTime 434
#define tCombine 435
#define tBSpline 436
#define tBezier 437
#define tNurbs 438
#define tNurbsOrder 439
#define tNurbsKnots 440
#define tColor 441
#define tColorTable 442
#define tFor 443
#define tIn 444
#define tEndFor 445
#define tIf 446
#define tElseIf 447
#define tElse 448
#define tEndIf 449
#define tExit 450
#define tAbort 451
#define tField 452
#define tReturn 453
#define tCall 454
#define tSlide 455
#define tMacro 456
#define tShow 457
#define tHide 458
#define tGetValue 459
#define tGetStringValue 460
#define tGetEnv 461
#define tGetString 462
#define tGetNumber 463
#define tUnique 464
#define tHomology 465
#define tCohomology 466
#define tBetti 467
#define tExists 468
#define tFileExists 469
#define tGetForced 470
#define tGetForcedStr 471
#define tGMSH_MAJOR_VERSION 472
#define tGMSH_MINOR_VERSION 473
#define tGMSH_PATCH_VERSION 474
#define tGmshExecutableName 475
#define tSetPartition 476
#define tNameToString 477
#define tStringToName 478
#define tAFFECTDIVIDE 479
#define tAFFECTTIMES 480
#define tAFFECTMINUS 481
#define tAFFECTPLUS 482
#define tOR 483
#define tAND 484
#define tNOTEQUAL 485
#define tEQUAL 486
#define tGREATERGREATER 487
#define tLESSLESS 488
#define tGREATEROREQUAL 489
#define tLESSOREQUAL 490
#define UNARYPREC 491
#define tMINUSMINUS 492
#define tPLUSPLUS 493




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
#line 756 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 769 "Gmsh.tab.cpp"

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
#define YYLAST   17435

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  623
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   246,     2,   258,     2,   243,   245,     2,
     251,   252,   241,   239,   260,   240,   257,   242,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     233,     2,   234,   228,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   253,     2,   254,   250,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   255,   244,   256,   259,     2,     2,     2,
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
     225,   226,   227,   229,   230,   231,   232,   235,   236,   237,
     238,   247,   248,   249
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
     150,   151,   154,   157,   160,   163,   166,   168,   172,   174,
     178,   179,   180,   191,   193,   197,   198,   212,   214,   218,
     219,   235,   244,   259,   260,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   295,   301,   304,
     312,   320,   325,   329,   336,   346,   354,   361,   369,   376,
     381,   390,   400,   410,   417,   427,   434,   444,   450,   459,
     468,   480,   487,   497,   503,   511,   519,   527,   537,   547,
     559,   567,   577,   587,   588,   590,   591,   595,   601,   602,
     612,   613,   625,   631,   632,   642,   643,   647,   651,   657,
     663,   664,   667,   668,   670,   672,   676,   679,   681,   686,
     689,   692,   693,   696,   698,   702,   705,   708,   711,   714,
     717,   719,   721,   725,   726,   732,   738,   744,   745,   748,
     749,   752,   760,   768,   776,   787,   798,   807,   816,   824,
     832,   844,   852,   861,   870,   879,   889,   893,   898,   909,
     917,   925,   933,   941,   949,   957,   965,   973,   981,   989,
     999,  1007,  1015,  1024,  1033,  1046,  1047,  1057,  1059,  1061,
    1063,  1065,  1070,  1072,  1074,  1076,  1081,  1083,  1085,  1090,
    1092,  1094,  1096,  1101,  1107,  1119,  1125,  1135,  1145,  1153,
    1158,  1168,  1178,  1180,  1182,  1183,  1186,  1193,  1201,  1209,
    1216,  1224,  1233,  1244,  1259,  1276,  1289,  1304,  1319,  1334,
    1349,  1358,  1367,  1374,  1379,  1385,  1391,  1398,  1405,  1409,
    1414,  1418,  1424,  1431,  1437,  1442,  1446,  1451,  1455,  1460,
    1466,  1471,  1477,  1481,  1487,  1495,  1503,  1507,  1515,  1519,
    1522,  1525,  1528,  1531,  1534,  1550,  1553,  1556,  1559,  1569,
    1581,  1584,  1587,  1590,  1593,  1610,  1622,  1629,  1638,  1647,
    1658,  1660,  1663,  1666,  1668,  1672,  1676,  1681,  1686,  1688,
    1690,  1696,  1708,  1722,  1723,  1731,  1732,  1746,  1747,  1763,
    1764,  1771,  1781,  1784,  1788,  1799,  1813,  1815,  1818,  1824,
    1832,  1835,  1838,  1842,  1845,  1849,  1852,  1856,  1866,  1873,
    1875,  1877,  1879,  1881,  1883,  1884,  1887,  1891,  1895,  1900,
    1910,  1915,  1930,  1931,  1935,  1936,  1938,  1939,  1942,  1943,
    1946,  1947,  1950,  1957,  1965,  1972,  1978,  1982,  1991,  2000,
    2009,  2018,  2027,  2036,  2042,  2047,  2054,  2066,  2078,  2097,
    2116,  2129,  2142,  2155,  2166,  2171,  2176,  2181,  2186,  2191,
    2194,  2198,  2205,  2207,  2209,  2211,  2214,  2220,  2228,  2239,
    2241,  2245,  2248,  2251,  2254,  2258,  2262,  2266,  2270,  2274,
    2278,  2282,  2286,  2290,  2294,  2298,  2302,  2306,  2310,  2314,
    2318,  2322,  2326,  2332,  2337,  2342,  2347,  2352,  2357,  2362,
    2367,  2372,  2377,  2382,  2389,  2394,  2399,  2404,  2409,  2414,
    2419,  2424,  2429,  2436,  2443,  2450,  2455,  2457,  2459,  2461,
    2463,  2465,  2467,  2469,  2471,  2473,  2475,  2477,  2478,  2485,
    2487,  2492,  2499,  2501,  2506,  2511,  2516,  2523,  2529,  2537,
    2546,  2557,  2562,  2567,  2574,  2579,  2583,  2586,  2592,  2598,
    2602,  2608,  2615,  2624,  2631,  2640,  2647,  2652,  2660,  2667,
    2674,  2681,  2686,  2693,  2698,  2699,  2702,  2703,  2706,  2707,
    2715,  2717,  2721,  2723,  2725,  2728,  2729,  2733,  2735,  2738,
    2741,  2745,  2749,  2761,  2771,  2779,  2787,  2789,  2793,  2795,
    2797,  2800,  2804,  2809,  2815,  2817,  2821,  2823,  2826,  2830,
    2834,  2840,  2845,  2850,  2853,  2858,  2861,  2865,  2869,  2886,
    2892,  2898,  2904,  2906,  2908,  2910,  2914,  2920,  2928,  2933,
    2938,  2943,  2950,  2957,  2966,  2975,  2980,  2995,  3000,  3005,
    3007,  3009,  3013,  3017,  3027,  3035,  3037,  3043,  3047,  3054,
    3056,  3060,  3062,  3064,  3069,  3074,  3078,  3084,  3091,  3100,
    3107,  3112,  3118,  3120,  3125,  3127,  3129,  3131,  3133,  3138,
    3145,  3150,  3157,  3163,  3171,  3176,  3181,  3186,  3195,  3200,
    3205,  3210,  3215,  3224,  3233,  3240,  3245,  3252,  3257,  3259,
    3261,  3266,  3271,  3272,  3279,  3284,  3287,  3292,  3297,  3299,
    3301,  3305,  3307,  3309,  3313,  3317,  3321,  3327,  3335,  3341,
    3347,  3356,  3358,  3360
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     262,     0,    -1,   263,    -1,     1,     6,    -1,    -1,   263,
     264,    -1,   266,    -1,   267,    -1,   287,    -1,   127,   251,
     364,   252,     6,    -1,   306,    -1,   312,    -1,   316,    -1,
     317,    -1,   318,    -1,   319,    -1,   323,    -1,   332,    -1,
     333,    -1,   339,    -1,   340,    -1,   322,    -1,   321,    -1,
     320,    -1,   315,    -1,   342,    -1,   234,    -1,   235,    -1,
      44,   251,   364,   252,     6,    -1,    46,   251,   364,   252,
       6,    -1,    45,   251,   364,   252,     6,    -1,    44,   251,
     364,   252,   265,   364,     6,    -1,    44,   251,   364,   260,
     360,   252,     6,    -1,    46,   251,   364,   260,   360,   252,
       6,    -1,    45,   251,   364,   260,   360,   252,     6,    -1,
      44,   251,   364,   260,   360,   252,   265,   364,     6,    -1,
     374,   364,   255,   268,   256,     6,    -1,   169,     4,   253,
     343,   254,     6,    -1,   170,     4,   253,   343,   254,     6,
      -1,   171,     4,   253,   343,   260,   343,   254,     6,    -1,
      -1,   268,   271,    -1,   268,   275,    -1,   268,   278,    -1,
     268,   280,    -1,   268,   281,    -1,   343,    -1,   269,   260,
     343,    -1,   343,    -1,   270,   260,   343,    -1,    -1,    -1,
       4,   272,   251,   269,   252,   273,   255,   270,   256,     6,
      -1,   364,    -1,   274,   260,   364,    -1,    -1,   176,   251,
     343,   260,   343,   260,   343,   252,   276,   255,   274,   256,
       6,    -1,   364,    -1,   277,   260,   364,    -1,    -1,   177,
     251,   343,   260,   343,   260,   343,   260,   343,   252,   279,
     255,   277,   256,     6,    -1,   178,   255,   356,   256,   255,
     356,   256,     6,    -1,   178,   255,   356,   256,   255,   356,
     256,   255,   356,   256,   255,   356,   256,     6,    -1,    -1,
     179,   282,   255,   270,   256,     6,    -1,     7,    -1,   227,
      -1,   226,    -1,   225,    -1,   224,    -1,   249,    -1,   248,
      -1,   251,    -1,   253,    -1,   252,    -1,   254,    -1,    88,
     253,   289,   254,     6,    -1,    89,   253,   293,   254,     6,
      -1,   348,     6,    -1,    96,   285,   365,   260,   343,   286,
       6,    -1,    98,   285,   374,   260,   365,   286,     6,    -1,
     374,   283,   357,     6,    -1,   374,   284,     6,    -1,   374,
     285,   286,   283,   357,     6,    -1,   374,   285,   255,   360,
     256,   286,   283,   357,     6,    -1,   374,   253,   343,   254,
     283,   343,     6,    -1,   374,   253,   343,   254,   284,     6,
      -1,   374,   251,   343,   252,   283,   343,     6,    -1,   374,
     251,   343,   252,   284,     6,    -1,   374,     7,   365,     6,
      -1,   374,   285,   286,     7,    47,   285,   286,     6,    -1,
     374,   285,   286,     7,    47,   285,   369,   286,     6,    -1,
     374,   285,   286,   227,    47,   285,   369,   286,     6,    -1,
     374,   257,     4,     7,   365,     6,    -1,   374,   253,   343,
     254,   257,     4,     7,   365,     6,    -1,   374,   257,     4,
     283,   343,     6,    -1,   374,   253,   343,   254,   257,     4,
     283,   343,     6,    -1,   374,   257,     4,   284,     6,    -1,
     374,   253,   343,   254,   257,     4,   284,     6,    -1,   374,
     257,   186,   257,     4,     7,   361,     6,    -1,   374,   253,
     343,   254,   257,   186,   257,     4,     7,   361,     6,    -1,
     374,   257,   187,     7,   362,     6,    -1,   374,   253,   343,
     254,   257,   187,     7,   362,     6,    -1,   374,   197,     7,
     357,     6,    -1,   197,   253,   343,   254,     7,     4,     6,
      -1,   197,   253,   343,   254,     7,   108,     6,    -1,   197,
     253,   343,   254,     7,   109,     6,    -1,   197,   253,   343,
     254,   257,     4,     7,   343,     6,    -1,   197,   253,   343,
     254,   257,     4,     7,   365,     6,    -1,   197,   253,   343,
     254,   257,     4,     7,   255,   360,   256,     6,    -1,   197,
     253,   343,   254,   257,     4,     6,    -1,   140,   251,     4,
     252,   257,     4,     7,   343,     6,    -1,   140,   251,     4,
     252,   257,     4,     7,   365,     6,    -1,    -1,   260,    -1,
      -1,   289,   288,   374,    -1,   289,   288,   374,     7,   343,
      -1,    -1,   289,   288,   374,     7,   255,   357,   290,   295,
     256,    -1,    -1,   289,   288,   374,   285,   286,     7,   255,
     357,   291,   295,   256,    -1,   289,   288,   374,     7,   365,
      -1,    -1,   289,   288,   374,     7,   255,   365,   292,   299,
     256,    -1,    -1,   293,   288,   364,    -1,   343,     7,   365,
      -1,   294,   260,   343,     7,   365,    -1,   359,     7,   374,
     251,   252,    -1,    -1,   260,   297,    -1,    -1,   297,    -1,
     298,    -1,   297,   260,   298,    -1,     4,   357,    -1,     4,
      -1,     4,   255,   294,   256,    -1,     4,   365,    -1,     4,
     368,    -1,    -1,   260,   300,    -1,   301,    -1,   300,   260,
     301,    -1,     4,   343,    -1,     4,   365,    -1,   201,   365,
      -1,     4,   370,    -1,     4,   368,    -1,   343,    -1,   365,
      -1,   365,   260,   343,    -1,    -1,   189,   103,   255,   343,
     256,    -1,   139,    99,   255,   360,   256,    -1,   139,   118,
     255,   360,   256,    -1,    -1,   132,   354,    -1,    -1,   139,
     143,    -1,    99,   251,   343,   252,     7,   354,     6,    -1,
     102,   251,   343,   252,     7,   357,     6,    -1,   106,   251,
     343,   252,     7,   357,     6,    -1,   136,   106,   251,   343,
     252,     7,   357,   139,   343,     6,    -1,   136,   181,   251,
     343,   252,     7,   357,   139,   343,     6,    -1,   100,   251,
     343,   252,     7,   357,   304,     6,    -1,   101,   251,   343,
     252,     7,   357,   304,     6,    -1,   181,   251,   343,   252,
       7,   357,     6,    -1,   182,   251,   343,   252,     7,   357,
       6,    -1,   183,   251,   343,   252,     7,   357,   185,   357,
     184,   343,     6,    -1,   117,   251,   343,   252,     7,   357,
       6,    -1,   102,     4,   251,   343,   252,     7,   357,     6,
      -1,   132,   105,   251,   343,   252,     7,   357,     6,    -1,
     105,   251,   343,   252,     7,   357,   303,     6,    -1,   133,
     105,   251,   343,   252,     7,   357,   303,     6,    -1,    13,
      14,     6,    -1,    14,   105,   343,     6,    -1,   121,   105,
     251,   343,   252,     7,     5,     5,     5,     6,    -1,   103,
     251,   343,   252,     7,   357,     6,    -1,   104,   251,   343,
     252,     7,   357,     6,    -1,   108,   251,   343,   252,     7,
     357,     6,    -1,   111,   251,   343,   252,     7,   357,     6,
      -1,   115,   251,   343,   252,     7,   357,     6,    -1,   116,
     251,   343,   252,     7,   357,     6,    -1,   109,   251,   343,
     252,     7,   357,     6,    -1,   110,   251,   343,   252,     7,
     357,     6,    -1,   129,   251,   343,   252,     7,   357,     6,
      -1,   156,   251,   343,   252,     7,   357,     6,    -1,   105,
       4,   251,   343,   252,     7,   357,   305,     6,    -1,   107,
     251,   343,   252,     7,   357,     6,    -1,   128,   251,   343,
     252,     7,   357,     6,    -1,   133,   128,   251,   343,   252,
       7,   357,     6,    -1,   136,   309,   251,   343,   252,     7,
     357,     6,    -1,   136,   309,   251,   343,   252,     7,   357,
       4,   255,   356,   256,     6,    -1,    -1,   135,   308,   307,
     251,   302,   252,   283,   357,     6,    -1,    99,    -1,   102,
      -1,   105,    -1,   107,    -1,   118,   255,   343,   256,    -1,
     102,    -1,   105,    -1,   107,    -1,   118,   255,   343,   256,
      -1,   102,    -1,   105,    -1,   118,   255,   343,   256,    -1,
      99,    -1,   102,    -1,   105,    -1,   118,   255,   343,   256,
      -1,   145,   354,   255,   313,   256,    -1,   144,   255,   354,
     260,   354,   260,   343,   256,   255,   313,   256,    -1,   146,
     354,   255,   313,   256,    -1,   147,   255,   354,   260,   343,
     256,   255,   313,   256,    -1,   147,   255,   354,   260,   354,
     256,   255,   313,   256,    -1,   150,   255,   360,   256,   255,
     313,   256,    -1,     4,   255,   313,   256,    -1,   162,   102,
     255,   360,   256,   105,   255,   343,   256,    -1,   159,   102,
     251,   343,   252,   255,   360,   256,     6,    -1,   314,    -1,
     312,    -1,    -1,   314,   306,    -1,   314,   308,   255,   360,
     256,     6,    -1,   314,   135,   308,   255,   360,   256,     6,
      -1,   314,   138,   308,   255,   360,   256,     6,    -1,   314,
     308,   255,     8,   256,     6,    -1,   314,   135,   308,   255,
       8,   256,     6,    -1,   149,   132,   251,   343,   252,     7,
     357,     6,    -1,   149,    99,   251,   343,   252,     7,   255,
     356,   256,     6,    -1,   149,   132,   251,   343,   252,     7,
     255,   354,   260,   354,   260,   360,   256,     6,    -1,   149,
     132,   251,   343,   252,     7,   255,   354,   260,   354,   260,
     354,   260,   360,   256,     6,    -1,   149,   103,   251,   343,
     252,     7,   255,   354,   260,   360,   256,     6,    -1,   149,
     109,   251,   343,   252,     7,   255,   354,   260,   354,   260,
     360,   256,     6,    -1,   149,   110,   251,   343,   252,     7,
     255,   354,   260,   354,   260,   360,   256,     6,    -1,   149,
     112,   251,   343,   252,     7,   255,   354,   260,   354,   260,
     360,   256,     6,    -1,   149,   113,   251,   343,   252,     7,
     255,   354,   260,   354,   260,   360,   256,     6,    -1,   149,
       4,   251,   343,   252,     7,   357,     6,    -1,   149,     4,
     251,   343,   252,     7,     5,     6,    -1,   149,     4,   255,
     343,   256,     6,    -1,   160,   255,   314,   256,    -1,   142,
     160,   255,   314,   256,    -1,   160,     4,   255,   314,   256,
      -1,   160,   197,   253,   343,   254,     6,    -1,   160,     4,
     253,   343,   254,     6,    -1,   160,   374,     6,    -1,   160,
       4,     4,     6,    -1,   160,    91,     6,    -1,   186,   361,
     255,   314,   256,    -1,   142,   186,   361,   255,   314,   256,
      -1,   221,   343,   255,   314,   256,    -1,   202,   255,     8,
     256,    -1,   202,     5,     6,    -1,   203,   255,     8,   256,
      -1,   203,     5,     6,    -1,   202,   255,   314,   256,    -1,
     142,   202,   255,   314,   256,    -1,   203,   255,   314,   256,
      -1,   142,   203,   255,   314,   256,    -1,   374,   365,     6,
      -1,    77,   251,   371,   252,     6,    -1,   374,   374,   253,
     343,   254,   364,     6,    -1,   374,   374,   374,   253,   343,
     254,     6,    -1,   374,   343,     6,    -1,   140,   251,     4,
     252,   257,     4,     6,    -1,   180,     4,     6,    -1,   195,
       6,    -1,   196,     6,    -1,    72,     6,    -1,    73,     6,
      -1,    65,     6,    -1,    65,   255,   343,   260,   343,   260,
     343,   260,   343,   260,   343,   260,   343,   256,     6,    -1,
      66,     6,    -1,    67,     6,    -1,    82,     6,    -1,    84,
     255,   343,   260,   343,   260,   343,   256,     6,    -1,    84,
     255,   343,   260,   343,   260,   343,   260,   343,   256,     6,
      -1,    83,     6,    -1,    85,     6,    -1,    86,     6,    -1,
     123,     6,    -1,   124,   255,   360,   256,   255,   360,   256,
     255,   356,   256,   255,   343,   260,   343,   256,     6,    -1,
     200,   251,   255,   360,   256,   260,   365,   260,   365,   252,
       6,    -1,   188,   251,   343,     8,   343,   252,    -1,   188,
     251,   343,     8,   343,     8,   343,   252,    -1,   188,     4,
     189,   255,   343,     8,   343,   256,    -1,   188,     4,   189,
     255,   343,     8,   343,     8,   343,   256,    -1,   190,    -1,
     201,     4,    -1,   201,   365,    -1,   198,    -1,   199,   374,
       6,    -1,   199,   365,     6,    -1,   191,   251,   343,   252,
      -1,   192,   251,   343,   252,    -1,   193,    -1,   194,    -1,
     148,   354,   255,   314,   256,    -1,   148,   255,   354,   260,
     354,   260,   343,   256,   255,   314,   256,    -1,   148,   255,
     354,   260,   354,   260,   354,   260,   343,   256,   255,   314,
     256,    -1,    -1,   148,   354,   255,   314,   324,   328,   256,
      -1,    -1,   148,   255,   354,   260,   354,   260,   343,   256,
     255,   314,   325,   328,   256,    -1,    -1,   148,   255,   354,
     260,   354,   260,   354,   260,   343,   256,   255,   314,   326,
     328,   256,    -1,    -1,   148,   255,   314,   327,   328,   256,
      -1,   148,   255,   314,   256,   139,   117,   255,   343,   256,
      -1,   128,   357,    -1,   133,   128,   357,    -1,   130,   255,
     360,   256,   255,   360,   256,   255,   360,   256,    -1,   131,
     255,   360,   256,   255,   360,   256,   255,   360,   256,   255,
     360,   256,    -1,   329,    -1,   328,   329,    -1,   166,   255,
     343,   256,     6,    -1,   166,   255,   357,   260,   357,   256,
       6,    -1,   167,     6,    -1,   157,     6,    -1,   157,   343,
       6,    -1,   172,     6,    -1,   172,   174,     6,    -1,   173,
       6,    -1,   173,   174,     6,    -1,   168,   251,   343,   252,
       7,   357,   139,   343,     6,    -1,   139,     4,   253,   343,
     254,     6,    -1,   151,    -1,   152,    -1,   153,    -1,   154,
      -1,   155,    -1,    -1,   160,     6,    -1,   142,   160,     6,
      -1,   160,   343,     6,    -1,   142,   160,   343,     6,    -1,
     330,   255,   314,   331,   256,   255,   314,   331,   256,    -1,
     114,   251,   364,   252,    -1,   330,   251,   343,   252,     7,
     255,   314,   331,   256,   255,   314,   331,   256,     6,    -1,
      -1,   139,     4,   343,    -1,    -1,     4,    -1,    -1,     7,
     357,    -1,    -1,     7,   343,    -1,    -1,   150,   357,    -1,
     119,   120,   358,     7,   343,     6,    -1,   134,   102,   358,
       7,   343,   334,     6,    -1,   134,   105,   358,   336,   335,
       6,    -1,   134,   107,   358,   336,     6,    -1,   175,   358,
       6,    -1,    97,    99,   251,   343,   260,   343,   252,     6,
      -1,    97,   102,   251,   343,   260,   343,   252,     6,    -1,
      97,   105,   251,   343,   260,   343,   252,     6,    -1,    97,
     107,   251,   343,   260,   343,   252,     6,    -1,   163,   105,
     255,   360,   256,     7,   343,     6,    -1,   165,   105,   255,
     360,   256,     7,   343,     6,    -1,   157,   105,   358,   337,
       6,    -1,   157,   107,   358,     6,    -1,   158,   105,   358,
       7,   343,     6,    -1,   137,   102,   255,   360,   256,     7,
     255,   360,   256,   338,     6,    -1,   137,   105,   255,   360,
     256,     7,   255,   360,   256,   338,     6,    -1,   137,   102,
     255,   360,   256,     7,   255,   360,   256,   144,   255,   354,
     260,   354,   260,   343,   256,     6,    -1,   137,   105,   255,
     360,   256,     7,   255,   360,   256,   144,   255,   354,   260,
     354,   260,   343,   256,     6,    -1,   137,   102,   255,   360,
     256,     7,   255,   360,   256,   145,   354,     6,    -1,   137,
     105,   255,   360,   256,     7,   255,   360,   256,   145,   354,
       6,    -1,   137,   105,   343,   255,   360,   256,     7,   343,
     255,   360,   256,     6,    -1,   308,   255,   360,   256,   189,
     308,   255,   343,   256,     6,    -1,   164,   310,   358,     6,
      -1,   125,   311,   358,     6,    -1,   126,   107,   357,     6,
      -1,   141,   102,   357,     6,    -1,   136,   309,   357,     6,
      -1,   161,     6,    -1,   161,     4,     6,    -1,   161,    99,
     255,   360,   256,     6,    -1,   210,    -1,   211,    -1,   212,
      -1,   341,     6,    -1,   341,   255,   357,   256,     6,    -1,
     341,   255,   357,   260,   357,   256,     6,    -1,   341,   251,
     357,   252,   255,   357,   260,   357,   256,     6,    -1,   344,
      -1,   251,   343,   252,    -1,   240,   343,    -1,   239,   343,
      -1,   246,   343,    -1,   343,   240,   343,    -1,   343,   239,
     343,    -1,   343,   241,   343,    -1,   343,   242,   343,    -1,
     343,   244,   343,    -1,   343,   245,   343,    -1,   343,   243,
     343,    -1,   343,   250,   343,    -1,   343,   233,   343,    -1,
     343,   234,   343,    -1,   343,   238,   343,    -1,   343,   237,
     343,    -1,   343,   232,   343,    -1,   343,   231,   343,    -1,
     343,   230,   343,    -1,   343,   229,   343,    -1,   343,   235,
     343,    -1,   343,   236,   343,    -1,   343,   228,   343,     8,
     343,    -1,    16,   285,   343,   286,    -1,    17,   285,   343,
     286,    -1,    18,   285,   343,   286,    -1,    19,   285,   343,
     286,    -1,    20,   285,   343,   286,    -1,    21,   285,   343,
     286,    -1,    22,   285,   343,   286,    -1,    23,   285,   343,
     286,    -1,    24,   285,   343,   286,    -1,    26,   285,   343,
     286,    -1,    27,   285,   343,   260,   343,   286,    -1,    28,
     285,   343,   286,    -1,    29,   285,   343,   286,    -1,    30,
     285,   343,   286,    -1,    31,   285,   343,   286,    -1,    32,
     285,   343,   286,    -1,    33,   285,   343,   286,    -1,    34,
     285,   343,   286,    -1,    35,   285,   343,   286,    -1,    36,
     285,   343,   260,   343,   286,    -1,    37,   285,   343,   260,
     343,   286,    -1,    38,   285,   343,   260,   343,   286,    -1,
      25,   285,   343,   286,    -1,     3,    -1,    10,    -1,    15,
      -1,    11,    -1,    12,    -1,   217,    -1,   218,    -1,   219,
      -1,    79,    -1,    80,    -1,    81,    -1,    -1,    90,   285,
     343,   345,   295,   286,    -1,   348,    -1,   208,   285,   364,
     286,    -1,   208,   285,   364,   260,   343,   286,    -1,   350,
      -1,   374,   253,   343,   254,    -1,   374,   251,   343,   252,
      -1,   213,   251,   350,   252,    -1,   213,   251,   350,   257,
     351,   252,    -1,   215,   251,   350,   346,   252,    -1,   215,
     251,   350,   257,   351,   346,   252,    -1,   215,   251,   350,
     285,   343,   286,   346,   252,    -1,   215,   251,   350,   257,
     351,   285,   343,   286,   346,   252,    -1,   214,   251,   365,
     252,    -1,   258,   374,   285,   286,    -1,   258,   350,   257,
     351,   285,   286,    -1,    93,   285,   374,   286,    -1,    93,
     285,   286,    -1,   374,   284,    -1,   374,   253,   343,   254,
     284,    -1,   374,   251,   343,   252,   284,    -1,   374,   257,
     351,    -1,   374,     9,   374,   257,   351,    -1,   374,   257,
     351,   251,   343,   252,    -1,   374,     9,   374,   257,   351,
     251,   343,   252,    -1,   374,   257,   351,   253,   343,   254,
      -1,   374,     9,   374,   257,   351,   253,   343,   254,    -1,
     374,   253,   343,   254,   257,     4,    -1,   374,   257,     4,
     284,    -1,   374,   253,   343,   254,   257,     4,   284,    -1,
     204,   251,   364,   260,   343,   252,    -1,    57,   251,   357,
     260,   357,   252,    -1,    58,   285,   364,   260,   364,   286,
      -1,    56,   285,   364,   286,    -1,    59,   285,   364,   260,
     364,   286,    -1,    64,   251,   371,   252,    -1,    -1,   260,
     343,    -1,    -1,   260,   364,    -1,    -1,    91,   350,   353,
     349,   253,   296,   254,    -1,   374,    -1,   374,     9,   374,
      -1,     4,    -1,    94,    -1,    94,   343,    -1,    -1,   251,
     352,   252,    -1,   355,    -1,   240,   354,    -1,   239,   354,
      -1,   354,   240,   354,    -1,   354,   239,   354,    -1,   255,
     343,   260,   343,   260,   343,   260,   343,   260,   343,   256,
      -1,   255,   343,   260,   343,   260,   343,   260,   343,   256,
      -1,   255,   343,   260,   343,   260,   343,   256,    -1,   251,
     343,   260,   343,   260,   343,   252,    -1,   357,    -1,   356,
     260,   357,    -1,   343,    -1,   359,    -1,   255,   256,    -1,
     255,   360,   256,    -1,   240,   255,   360,   256,    -1,   343,
     241,   255,   360,   256,    -1,   357,    -1,   255,     8,   256,
      -1,     5,    -1,   240,   359,    -1,   343,   241,   359,    -1,
     343,     8,   343,    -1,   343,     8,   343,     8,   343,    -1,
      99,   255,   343,   256,    -1,    99,   255,     8,   256,    -1,
      99,     5,    -1,   309,   255,     8,   256,    -1,   309,     5,
      -1,   135,   308,   358,    -1,   138,   308,   357,    -1,   308,
     189,    65,   255,   343,   260,   343,   260,   343,   260,   343,
     260,   343,   260,   343,   256,    -1,    65,   308,   255,   360,
     256,    -1,    74,   309,   255,   343,   256,    -1,    75,   309,
     255,   343,   256,    -1,   312,    -1,   323,    -1,   332,    -1,
     374,   285,   286,    -1,   374,   257,   351,   285,   286,    -1,
     374,     9,   374,   257,   351,   285,   286,    -1,    39,   253,
     374,   254,    -1,    39,   253,   359,   254,    -1,    39,   251,
     359,   252,    -1,    39,   285,   255,   360,   256,   286,    -1,
     374,   285,   255,   360,   256,   286,    -1,    40,   285,   343,
     260,   343,   260,   343,   286,    -1,    41,   285,   343,   260,
     343,   260,   343,   286,    -1,    42,   285,   364,   286,    -1,
      43,   285,   343,   260,   343,   260,   343,   260,   343,   260,
     343,   260,   343,   286,    -1,   209,   285,   359,   286,    -1,
      32,   285,   359,   286,    -1,   343,    -1,   359,    -1,   360,
     260,   343,    -1,   360,   260,   359,    -1,   255,   343,   260,
     343,   260,   343,   260,   343,   256,    -1,   255,   343,   260,
     343,   260,   343,   256,    -1,   374,    -1,     4,   257,   186,
     257,     4,    -1,   255,   363,   256,    -1,   374,   253,   343,
     254,   257,   187,    -1,   361,    -1,   363,   260,   361,    -1,
     365,    -1,   374,    -1,   374,   253,   343,   254,    -1,   374,
     251,   343,   252,    -1,   374,   257,   351,    -1,   374,     9,
     374,   257,   351,    -1,   374,   257,   351,   251,   343,   252,
      -1,   374,     9,   374,   257,   351,   251,   343,   252,    -1,
     374,   253,   343,   254,   257,     4,    -1,   308,   255,   343,
     256,    -1,   135,   308,   255,   343,   256,    -1,     5,    -1,
     222,   253,   374,   254,    -1,    68,    -1,   220,    -1,    76,
      -1,    78,    -1,   206,   251,   364,   252,    -1,   205,   251,
     364,   260,   364,   252,    -1,   207,   285,   364,   286,    -1,
     207,   285,   364,   260,   364,   286,    -1,   216,   251,   350,
     347,   252,    -1,   216,   251,   350,   257,   351,   347,   252,
      -1,    49,   285,   371,   286,    -1,    50,   251,   364,   252,
      -1,    51,   251,   364,   252,    -1,    52,   251,   364,   260,
     364,   260,   364,   252,    -1,    47,   285,   371,   286,    -1,
      61,   285,   364,   286,    -1,    62,   285,   364,   286,    -1,
      63,   285,   364,   286,    -1,    60,   285,   343,   260,   364,
     260,   364,   286,    -1,    55,   285,   364,   260,   343,   260,
     343,   286,    -1,    55,   285,   364,   260,   343,   286,    -1,
      48,   285,   364,   286,    -1,    48,   285,   364,   260,   360,
     286,    -1,    69,   285,   364,   286,    -1,    70,    -1,    71,
      -1,    54,   285,   364,   286,    -1,    53,   285,   364,   286,
      -1,    -1,    95,   285,   365,   366,   299,   286,    -1,    92,
     285,   367,   286,    -1,   258,   343,    -1,   374,     9,   258,
     343,    -1,    47,   285,   370,   286,    -1,   371,    -1,   370,
      -1,   255,   371,   256,    -1,   364,    -1,   372,    -1,   371,
     260,   364,    -1,   371,   260,   372,    -1,   374,   251,   252,
      -1,   374,   257,   351,   251,   252,    -1,   374,     9,   374,
     257,   351,   251,   252,    -1,     4,   259,   255,   343,   256,
      -1,   373,   259,   255,   343,   256,    -1,   223,   253,   364,
     254,   259,   255,   343,   256,    -1,     4,    -1,   373,    -1,
     223,   253,   364,   254,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   271,   271,   272,   277,   279,   283,   284,   285,   286,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   324,   328,   335,   340,
     345,   350,   364,   377,   390,   403,   431,   445,   458,   471,
     490,   495,   496,   497,   498,   499,   503,   505,   510,   512,
     518,   622,   517,   640,   647,   658,   657,   675,   682,   693,
     692,   709,   726,   749,   748,   762,   763,   764,   765,   766,
     770,   771,   777,   777,   778,   778,   784,   785,   786,   787,
     792,   798,   860,   875,   904,   914,   919,   927,   932,   940,
     949,   954,   966,   983,   989,   998,  1016,  1034,  1043,  1055,
    1060,  1068,  1088,  1111,  1131,  1139,  1146,  1153,  1175,  1198,
    1236,  1257,  1269,  1283,  1283,  1285,  1287,  1296,  1306,  1305,
    1326,  1325,  1343,  1353,  1352,  1366,  1368,  1376,  1382,  1387,
    1414,  1416,  1419,  1421,  1425,  1426,  1430,  1442,  1455,  1470,
    1479,  1492,  1494,  1498,  1499,  1504,  1512,  1521,  1529,  1543,
    1561,  1565,  1572,  1581,  1584,  1590,  1594,  1606,  1609,  1616,
    1619,  1625,  1648,  1664,  1680,  1697,  1714,  1751,  1795,  1811,
    1827,  1859,  1875,  1892,  1908,  1958,  1976,  1982,  1988,  1995,
    2026,  2041,  2063,  2086,  2109,  2132,  2156,  2180,  2204,  2230,
    2247,  2263,  2281,  2299,  2311,  2325,  2324,  2354,  2356,  2358,
    2360,  2362,  2370,  2372,  2374,  2376,  2384,  2386,  2388,  2396,
    2398,  2400,  2402,  2412,  2428,  2444,  2460,  2476,  2492,  2509,
    2546,  2568,  2592,  2593,  2598,  2601,  2605,  2622,  2642,  2662,
    2681,  2708,  2727,  2748,  2763,  2779,  2797,  2848,  2869,  2891,
    2914,  3019,  3035,  3070,  3092,  3114,  3126,  3132,  3147,  3175,
    3187,  3196,  3203,  3215,  3235,  3239,  3244,  3248,  3253,  3260,
    3267,  3274,  3286,  3359,  3377,  3402,  3417,  3450,  3462,  3494,
    3498,  3503,  3510,  3515,  3525,  3530,  3536,  3544,  3548,  3552,
    3556,  3560,  3564,  3568,  3577,  3641,  3657,  3674,  3691,  3713,
    3735,  3770,  3778,  3786,  3792,  3799,  3806,  3826,  3852,  3864,
    3875,  3893,  3911,  3930,  3929,  3954,  3953,  3980,  3979,  4004,
    4003,  4026,  4042,  4059,  4076,  4099,  4127,  4130,  4136,  4148,
    4168,  4172,  4176,  4180,  4184,  4188,  4192,  4196,  4205,  4218,
    4219,  4220,  4221,  4222,  4226,  4227,  4228,  4229,  4230,  4233,
    4257,  4276,  4299,  4302,  4318,  4321,  4338,  4341,  4347,  4350,
    4357,  4360,  4367,  4389,  4430,  4474,  4513,  4538,  4550,  4562,
    4574,  4586,  4603,  4620,  4650,  4676,  4702,  4734,  4761,  4787,
    4813,  4839,  4865,  4887,  4898,  4946,  5000,  5015,  5027,  5038,
    5045,  5060,  5074,  5075,  5076,  5080,  5086,  5098,  5116,  5144,
    5145,  5146,  5147,  5148,  5149,  5150,  5151,  5152,  5159,  5160,
    5161,  5162,  5163,  5164,  5165,  5166,  5167,  5168,  5169,  5170,
    5171,  5172,  5173,  5174,  5175,  5176,  5177,  5178,  5179,  5180,
    5181,  5182,  5183,  5184,  5185,  5186,  5187,  5188,  5189,  5190,
    5191,  5192,  5193,  5194,  5195,  5196,  5205,  5206,  5207,  5208,
    5209,  5210,  5211,  5212,  5213,  5214,  5215,  5220,  5219,  5227,
    5229,  5234,  5239,  5243,  5248,  5253,  5257,  5261,  5265,  5269,
    5273,  5277,  5283,  5298,  5302,  5308,  5313,  5332,  5352,  5383,
    5387,  5391,  5395,  5399,  5403,  5407,  5412,  5422,  5432,  5437,
    5448,  5457,  5462,  5467,  5495,  5496,  5502,  5503,  5509,  5508,
    5531,  5533,  5538,  5547,  5549,  5555,  5556,  5561,  5565,  5569,
    5573,  5577,  5584,  5588,  5592,  5596,  5603,  5608,  5615,  5620,
    5624,  5629,  5633,  5641,  5652,  5656,  5660,  5674,  5682,  5690,
    5697,  5707,  5730,  5735,  5741,  5746,  5752,  5763,  5769,  5775,
    5781,  5793,  5807,  5817,  5827,  5837,  5849,  5853,  5858,  5870,
    5874,  5878,  5882,  5900,  5908,  5916,  5945,  5955,  5971,  5982,
    5987,  5991,  5995,  6007,  6011,  6023,  6040,  6050,  6054,  6069,
    6074,  6081,  6085,  6090,  6104,  6120,  6124,  6128,  6132,  6136,
    6144,  6150,  6159,  6163,  6167,  6175,  6181,  6187,  6191,  6199,
    6207,  6214,  6223,  6227,  6231,  6246,  6260,  6274,  6286,  6302,
    6311,  6320,  6330,  6341,  6349,  6357,  6361,  6380,  6387,  6393,
    6399,  6406,  6414,  6413,  6423,  6447,  6449,  6455,  6460,  6462,
    6467,  6472,  6477,  6479,  6483,  6495,  6509,  6513,  6520,  6528,
    6536,  6547,  6549,  6552
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
  "tRound", "tFmod", "tModulo", "tHypot", "tList", "tLinSpace",
  "tLogSpace", "tListFromFile", "tCatenary", "tPrintf", "tError",
  "tWarning", "tStr", "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative",
  "tStrReplace", "tAbsolutePath", "tDirName", "tStrSub", "tStrLen",
  "tFind", "tStrFind", "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase",
  "tLowerCaseIn", "tTextAttributes", "tBoundingBox", "tDraw",
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
     475,   476,   477,   478,   479,   480,   481,   482,    63,   483,
     484,   485,   486,    60,    62,   487,   488,   489,   490,    43,
      45,    42,    47,    37,   124,    38,    33,   491,   492,   493,
      94,    40,    41,    91,    93,   123,   125,    46,    35,   126,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   261,   262,   262,   263,   263,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267,   267,   267,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     272,   273,   271,   274,   274,   276,   275,   277,   277,   279,
     278,   280,   280,   282,   281,   283,   283,   283,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   288,   288,   289,   289,   289,   290,   289,
     291,   289,   289,   292,   289,   293,   293,   294,   294,   294,
     295,   295,   296,   296,   297,   297,   298,   298,   298,   298,
     298,   299,   299,   300,   300,   301,   301,   301,   301,   301,
     302,   302,   302,   303,   303,   303,   303,   304,   304,   305,
     305,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   307,   306,   308,   308,   308,
     308,   308,   309,   309,   309,   309,   310,   310,   310,   311,
     311,   311,   311,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   316,   316,   316,   316,   316,   316,   316,
     316,   317,   317,   318,   319,   319,   319,   319,   319,   319,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   321,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     323,   323,   323,   324,   323,   325,   323,   326,   323,   327,
     323,   323,   323,   323,   323,   323,   328,   328,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   330,
     330,   330,   330,   330,   331,   331,   331,   331,   331,   332,
     332,   333,   334,   334,   335,   335,   336,   336,   337,   337,
     338,   338,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   340,
     340,   340,   341,   341,   341,   342,   342,   342,   342,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   345,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   346,   346,   347,   347,   349,   348,
     350,   350,   351,   352,   352,   353,   353,   354,   354,   354,
     354,   354,   355,   355,   355,   355,   356,   356,   357,   357,
     357,   357,   357,   357,   358,   358,   358,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   360,
     360,   360,   360,   361,   361,   361,   361,   362,   362,   363,
     363,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   366,   365,   365,   367,   367,   368,   369,   369,
     370,   371,   371,   371,   371,   372,   372,   372,   373,   373,
     373,   374,   374,   374
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     7,     7,     7,     7,     9,     6,     6,     6,     8,
       0,     2,     2,     2,     2,     2,     1,     3,     1,     3,
       0,     0,    10,     1,     3,     0,    13,     1,     3,     0,
      15,     8,    14,     0,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     2,     7,
       7,     4,     3,     6,     9,     7,     6,     7,     6,     4,
       8,     9,     9,     6,     9,     6,     9,     5,     8,     8,
      11,     6,     9,     5,     7,     7,     7,     9,     9,    11,
       7,     9,     9,     0,     1,     0,     3,     5,     0,     9,
       0,    11,     5,     0,     9,     0,     3,     3,     5,     5,
       0,     2,     0,     1,     1,     3,     2,     1,     4,     2,
       2,     0,     2,     1,     3,     2,     2,     2,     2,     2,
       1,     1,     3,     0,     5,     5,     5,     0,     2,     0,
       2,     7,     7,     7,    10,    10,     8,     8,     7,     7,
      11,     7,     8,     8,     8,     9,     3,     4,    10,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     9,
       7,     7,     8,     8,    12,     0,     9,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     1,     4,     5,    11,     5,     9,     9,     7,     4,
       9,     9,     1,     1,     0,     2,     6,     7,     7,     6,
       7,     8,    10,    14,    16,    12,    14,    14,    14,    14,
       8,     8,     6,     4,     5,     5,     6,     6,     3,     4,
       3,     5,     6,     5,     4,     3,     4,     3,     4,     5,
       4,     5,     3,     5,     7,     7,     3,     7,     3,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     9,    11,
       2,     2,     2,     2,    16,    11,     6,     8,     8,    10,
       1,     2,     2,     1,     3,     3,     4,     4,     1,     1,
       5,    11,    13,     0,     7,     0,    13,     0,    15,     0,
       6,     9,     2,     3,    10,    13,     1,     2,     5,     7,
       2,     2,     3,     2,     3,     2,     3,     9,     6,     1,
       1,     1,     1,     1,     0,     2,     3,     3,     4,     9,
       4,    14,     0,     3,     0,     1,     0,     2,     0,     2,
       0,     2,     6,     7,     6,     5,     3,     8,     8,     8,
       8,     8,     8,     5,     4,     6,    11,    11,    18,    18,
      12,    12,    12,    10,     4,     4,     4,     4,     4,     2,
       3,     6,     1,     1,     1,     2,     5,     7,    10,     1,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     1,
       4,     6,     1,     4,     4,     4,     6,     5,     7,     8,
      10,     4,     4,     6,     4,     3,     2,     5,     5,     3,
       5,     6,     8,     6,     8,     6,     4,     7,     6,     6,
       6,     4,     6,     4,     0,     2,     0,     2,     0,     7,
       1,     3,     1,     1,     2,     0,     3,     1,     2,     2,
       3,     3,    11,     9,     7,     7,     1,     3,     1,     1,
       2,     3,     4,     5,     1,     3,     1,     2,     3,     3,
       5,     4,     4,     2,     4,     2,     3,     3,    16,     5,
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
       0,     0,     0,     2,     3,     1,   621,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
       0,     0,   198,     0,     0,   199,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,   330,   331,   332,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   290,
       0,     0,   298,   299,     0,     0,     0,   293,     0,     0,
       0,     0,     0,   382,   383,   384,     0,     0,     5,     6,
       7,     8,    10,     0,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,     0,   622,     0,   224,     0,     0,     0,     0,     0,
       0,   273,     0,   275,   276,   271,   272,     0,   277,   280,
       0,   281,   282,   115,   125,   621,   495,   490,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,     0,
     209,   210,   211,     0,     0,     0,     0,   436,   437,   439,
     440,   438,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   444,   445,
     446,     0,     0,   197,   202,   203,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   441,   442,
     443,     0,     0,     0,     0,     0,     0,     0,     0,   532,
     533,     0,   534,   508,   389,   449,   452,   312,   509,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     198,   199,   200,   195,   202,   203,     0,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   621,     0,     0,   224,     0,     0,
     379,     0,     0,     0,   206,   207,     0,     0,     0,     0,
       0,     0,   516,     0,     0,   514,     0,     0,     0,     0,
       0,   621,     0,     0,   555,     0,     0,     0,     0,   269,
     270,     0,   572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,     0,   598,   599,
     576,   577,     0,     0,     0,     0,     0,     0,   575,     0,
       0,     0,     0,   291,   292,     0,   224,     0,   224,     0,
       0,     0,   490,     0,     0,     0,   224,   385,     0,     0,
      78,     0,    65,     0,     0,    69,    68,    67,    66,    71,
      70,    72,    73,     0,     0,     0,     0,     0,     0,     0,
     561,   490,     0,   223,     0,   222,     0,   176,     0,     0,
     561,   562,     0,     0,     0,   611,     0,   612,   562,     0,
     113,   113,     0,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   549,   550,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   392,     0,   391,   517,   393,     0,   510,
       0,     0,   490,     0,   525,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
     466,     0,     0,     0,     0,     0,     0,     0,   313,     0,
     346,   346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,     0,   224,   224,     0,   499,   498,
       0,     0,     0,     0,   224,   224,     0,     0,     0,     0,
     309,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,     0,     0,
     224,   250,     0,     0,   248,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   356,   268,     0,
       0,     0,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,   294,     0,   255,     0,     0,   257,     0,     0,
       0,   391,     0,   224,     0,     0,     0,     0,     0,     0,
       0,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    74,    75,     0,     0,     0,
     266,    40,   262,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,     0,   225,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,     0,
     493,     0,     0,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   340,     0,     0,     0,   201,
       0,     0,     0,     0,     0,     0,   375,   376,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   490,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,   465,     0,     0,     0,     0,   526,   527,     0,     0,
       0,     0,     0,   484,     0,   390,   511,     0,     0,     0,
       0,   519,     0,   409,   408,   407,   406,   402,   403,   410,
     411,   405,   404,   395,   394,     0,   396,   518,   397,   400,
     398,   399,   401,   491,     0,     0,   492,   469,     0,   535,
       0,     0,     0,     0,     0,     0,     0,     0,   344,     0,
       0,     0,     0,     0,     0,   378,     0,     0,     0,     0,
     377,     0,   224,     0,     0,     0,     0,     0,   501,   500,
       0,     0,     0,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,     0,     0,   249,     0,     0,     0,   243,     0,
       0,     0,     0,   374,     0,     0,     0,     0,   390,   515,
       0,     0,     0,     0,     0,     0,     0,     0,   296,   297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   602,     0,
       0,     0,   486,     0,     0,   254,   258,   256,   260,     0,
     396,     0,   491,   469,   623,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,     0,     0,   390,     0,    65,
       0,     0,     0,     0,    81,     0,    65,    66,     0,     0,
       0,   491,     0,     0,   469,     0,     0,     0,   195,     0,
       0,     0,   618,    28,    26,    27,     0,     0,     0,     0,
       0,   492,   565,    30,     0,    29,     0,     0,   263,   613,
     614,     0,   615,   565,     0,    76,   116,    77,   126,   494,
     496,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551,
     552,   212,     9,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   435,   422,     0,   424,   425,   426,   427,   428,
     548,   429,   430,   431,     0,     0,     0,   540,   539,   538,
       0,     0,     0,   545,     0,   481,     0,     0,     0,   483,
       0,     0,     0,   130,   464,   522,   521,   205,     0,     0,
     450,   547,   455,     0,   461,     0,     0,     0,     0,   512,
       0,     0,   462,     0,   524,     0,     0,     0,     0,   454,
     453,   476,    72,    73,     0,     0,     0,     0,     0,     0,
       0,   390,   342,   347,   345,     0,   355,     0,   150,   151,
       0,   205,     0,   390,     0,     0,     0,     0,   244,     0,
     259,   261,     0,     0,     0,   213,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,     0,
     300,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   224,     0,   349,   363,     0,     0,     0,   245,     0,
       0,     0,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     0,     0,     0,   588,     0,
     595,   584,   585,   586,     0,   601,   600,     0,     0,   589,
     590,   591,   597,   605,   604,     0,   141,     0,   578,     0,
     580,     0,     0,     0,   573,     0,   253,     0,     0,     0,
       0,     0,     0,     0,   335,     0,     0,     0,   386,     0,
     619,     0,   103,    65,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
     570,    50,     0,     0,     0,    63,     0,    41,    42,    43,
      44,    45,     0,   454,   453,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   564,   563,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
     133,   134,     0,     0,     0,     0,     0,     0,     0,   157,
     157,     0,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   352,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     529,   530,   531,     0,     0,     0,     0,     0,   484,   485,
       0,   457,     0,     0,     0,   520,   412,   513,   470,   468,
       0,   467,     0,     0,   536,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     0,     0,     0,     0,
       0,     0,   321,     0,     0,   320,     0,   323,     0,   325,
       0,   310,   317,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   365,     0,   247,   246,
     381,     0,     0,     0,    37,    38,     0,     0,     0,     0,
     556,     0,     0,     0,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   486,   487,
     582,     0,   470,     0,     0,   224,   336,     0,   337,   224,
       0,     0,   571,     0,    88,     0,     0,     0,     0,    86,
      93,    95,     0,   559,     0,   101,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,    36,   470,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,     0,   566,     0,     0,    34,    33,     0,   566,
     616,     0,     0,   117,   122,     0,     0,     0,   136,   139,
     140,   489,     0,    79,     0,     0,     0,     0,    80,   161,
       0,     0,     0,     0,   162,   179,   180,   159,     0,     0,
       0,   163,   190,   181,   185,   186,   182,   183,   184,   171,
       0,     0,   423,   432,   433,   434,   541,     0,     0,     0,
     479,   480,   482,   131,   448,   478,   451,   456,     0,     0,
     484,   191,   463,     0,    72,    73,     0,   475,   471,   473,
     542,   187,     0,     0,     0,   153,     0,     0,   353,     0,
     152,     0,     0,     0,     0,     0,     0,   267,     0,     0,
       0,     0,   224,   224,     0,     0,   322,   508,     0,     0,
     324,   326,     0,     0,   304,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   188,     0,     0,     0,
       0,     0,   168,   169,     0,     0,     0,     0,   104,   105,
     106,   110,     0,   596,     0,     0,   594,     0,   606,     0,
       0,   142,   143,   603,   579,   581,     0,     0,     0,     0,
       0,     0,   334,   338,   334,     0,   387,    87,    65,     0,
       0,     0,     0,    85,     0,   557,     0,     0,     0,     0,
       0,     0,   609,   608,     0,     0,     0,     0,     0,   506,
       0,     0,   475,   264,   471,   265,     0,     0,     0,     0,
       0,   229,   226,     0,     0,   569,   567,     0,     0,     0,
       0,   118,   123,     0,     0,     0,   549,   550,   135,   357,
     358,   359,   360,   158,   166,   167,   172,     0,     0,     0,
       0,     0,   174,     0,     0,     0,     0,     0,     0,   458,
       0,     0,     0,     0,   537,   477,     0,     0,   173,     0,
     192,   343,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,     0,   505,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,   240,     0,     0,     0,
       0,     0,     0,     0,     0,   231,     0,     0,   361,   362,
      39,     0,   554,     0,     0,   288,   287,     0,     0,     0,
       0,     0,     0,   145,   146,   149,   148,   147,     0,   583,
       0,   620,     0,     0,     0,     0,     0,     0,    98,     0,
       0,    99,   560,     0,     0,     0,    90,     0,     0,     0,
      46,     0,     0,     0,     0,     0,    48,     0,   230,   227,
     228,    35,     0,     0,   617,   278,     0,   130,   141,     0,
       0,   138,     0,     0,     0,   160,   189,     0,     0,     0,
       0,     0,   543,   544,     0,   484,   459,     0,   472,   474,
       0,     0,   175,   196,     0,     0,     0,   350,   350,     0,
     111,   112,   224,     0,   216,   217,   311,     0,   318,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
     221,   220,     0,     0,     0,     0,   107,   108,   587,   593,
     592,   144,     0,     0,     0,   339,     0,    94,    96,     0,
     102,     0,    84,   610,    91,    92,    51,     0,     0,     0,
       0,   507,     0,     0,   472,   568,     0,     0,     0,     0,
     120,   607,     0,   127,     0,     0,     0,     0,   178,     0,
       0,     0,     0,   314,     0,   164,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,   328,
       0,     0,   305,     0,   232,     0,     0,     0,     0,     0,
       0,     0,   553,   289,     0,     0,   373,   224,   388,     0,
     558,     0,    47,     0,     0,     0,    64,    49,     0,   279,
     119,   124,   130,     0,     0,   155,   156,   154,     0,     0,
     460,     0,     0,     0,     0,     0,   351,   366,     0,     0,
     367,     0,   214,     0,   319,     0,   301,     0,   224,     0,
       0,     0,     0,     0,     0,   170,   109,   285,   334,   100,
       0,     0,     0,     0,     0,     0,   128,   129,     0,     0,
       0,     0,   194,     0,   370,     0,   371,   372,   502,     0,
       0,   307,   235,     0,     0,     0,     0,     0,     0,     0,
       0,    55,     0,    61,     0,     0,   121,     0,     0,     0,
     315,     0,     0,   327,   306,   302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   237,   238,   239,     0,
     233,   341,    52,     0,    59,     0,   274,     0,   546,     0,
       0,     0,   308,     0,     0,    53,     0,     0,   284,     0,
       0,     0,   234,     0,     0,     0,     0,   528,     0,     0,
      56,    54,     0,    57,     0,   368,   369,     0,     0,    62,
      60,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,  1076,   119,   120,  1060,  1919,  1925,
    1357,  1571,  2081,  2214,  1358,  2185,  2232,  1359,  2216,  1360,
    1361,  1575,   444,   600,   601,  1149,   121,   787,   470,  1937,
    2092,  1938,   471,  1805,  1434,  1389,  1390,  1391,  1535,  1741,
    1742,  1217,  1630,  1621,  1818,   764,   612,   277,   278,   357,
     204,   279,   454,   455,   125,   126,   127,   128,   129,   130,
     131,   132,   280,  1251,  2117,  2176,   955,  1247,  1248,   281,
    1039,   282,   136,  1463,  1215,   928,   970,  2051,   137,   138,
     139,   140,   283,   284,  1173,  1188,  1313,   285,   792,   286,
     917,   791,   473,   629,   325,  1778,   365,   366,   288,   570,
     373,  1344,  1564,   465,   460,  1306,  1016,  1610,  1771,  1772,
    1001,   467,   142,   422
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1899
static const yytype_int16 yypact[] =
{
   12862,    40,    55, 13025, -1899, -1899,  -138,    77,   -21,   -76,
     -54,   -42,    11,    98,   156,   237,   270,    32,   308,   327,
      43,   342,   364,   121,   128,    30,  -110,   394,  -110,   146,
     159,   165,    39,   179,   188,    54,   206,   222,   253,   263,
     269,   357,   377,   392,   407,   430,   340,   564,   608,   713,
     470,   393,   622,   488,  6571,   514,   513,   552,   675,   -49,
     312,    58,     1,   528,   532,   738,   -87,   645,   210,   210,
     694,   469,   466,   747, -1899, -1899, -1899, -1899, -1899,   573,
      80,   761,   818,    57,    38,   837,   886,    50,   908,  1013,
    1016,  1021,  5575,  1023,   777,   779,   780,    24,    59, -1899,
     781,   782, -1899, -1899,  1029,  1030,   784, -1899,  1267,   787,
    1950,    15,    31, -1899, -1899, -1899, 11631,   788, -1899, -1899,
   -1899, -1899, -1899,   785, -1899, -1899, -1899, -1899, -1899, -1899,
   -1899, -1899, -1899, -1899,   -51, -1899, -1899, -1899, -1899,    53,
   -1899,  1036,   786,  4740,    33,   789,  1037, 11631, 13205, 13205,
   13205, -1899, 11631, -1899, -1899, -1899, -1899, 13205, -1899, -1899,
   11631, -1899, -1899, -1899, -1899,   790,   795,  1038, -1899, -1899,
    3111,   800,   801,   802,   803,    30, 11631, 11631, 11631,   805,
   11631, 11631, 11631,   806, 11631, 11631, 11631, 11631, 11631, 11631,
   11631, 13205, 11631, 11631, 11631, 11631,  5575,   807, -1899,  9300,
   -1899, -1899, -1899,   804,  5575,  6820, 13205, -1899, -1899, -1899,
   -1899, -1899,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,   257,  -110,  -110,  -110,  -110,
    -110,   809,  -110,  -110,   810,    58,    20,    20, -1899, -1899,
   -1899,  -110,  -110,    36,   873,   874,   876,   812,  6820,   941,
      58,    58,   821,  -110,  -110,   823,   824,   825, -1899, -1899,
   -1899, 11631,  7069, 11631, 11631,  7318,    30,   888,    42, -1899,
   -1899,   826, -1899,  4406, -1899, -1899, -1899, -1899, -1899,   114,
   11631,  9300,  9300,   827,   828,  7567,  5575,  5575,  5575, -1899,
   -1899, -1899, -1899, -1899, -1899, -1899,   829, -1899,   830,   831,
    7816,   832, 10223,  1080,  6820,   835,    24,   836,   838,   210,
     210,   210, 11631, 11631,   472, -1899,   478,   210, 10307,   483,
      76,   843,   845,   846,   847,   848,   849,   850,  9300, 11631,
    5575,  5575,  5575,   851,    22,  1097,   833, -1899,  1098,  1099,
   -1899,   853,   857,   868, -1899, -1899,   869,  5575,   889,   892,
     893,   894, -1899, 11631,  5824, -1899,  1143,  1144, 11631, 11631,
   11631,   287, 11631,   896, -1899,   963, 11631, 11631, 11631, -1899,
   -1899, 11631, -1899,  -110,  -110,  -110,   902,   904,   905,  -110,
    -110,  -110,  -110,  -110,  -110,  -110, -1899,  -110, -1899, -1899,
   -1899, -1899,  -110,  -110,   906,   909,  -110,   910, -1899,   913,
    1153,  1156,   930, -1899, -1899,  1180,  1184,  1182,  1186,  -110,
   11631, 10841,   158, 13205,  9300, 11631, -1899, -1899,  6820,  6820,
   -1899,   940,  3111,    58,  1189, -1899, -1899, -1899, -1899, -1899,
   -1899, 11631, 11631,   242,  6820,  1191,   734,   943,  1845,   944,
    1194,    92,   946, -1899,   950, 13332, 11631, -1899,  2055,   100,
   -1899,    68,   207,   245,  8737, -1899,   322, -1899,    69,  8986,
    -194,  -126,  1108, -1899,    30,   965, 11631, 11631, 11631, 11631,
     966, 15510, 15535, 15560, 11631, 15585, 15610, 15635, 11631, 15660,
   15685, 15710, 15735, 15760, 15785, 15810,   975, 15835, 15860, 15885,
    5083,  1221, 11631,  9300,  6008, -1899,   180, 11631,  1226,  1227,
     982, 11631, 11631, 11631, 11631, 11631, 11631, 11631, 11631, 11631,
   11631, 11631, 11631, 11631, 11631, 11631, 11631,  9300, 11631, 11631,
   11631, 11631, 11631, 11631,  9300,  9300,   983, 11631, 11631, 13205,
   11631, 13205,  6820, 13205, 13205, 13205,   984,   985,   986, 11631,
      64, -1899, 10556, 11631,  6820,  5575,  6820, 13205, 13205,  9300,
      30,  3111,    30,   992,  9300,   992, -1899,   992, 15910, -1899,
     274,   988,    83,  1178, -1899,  1241, 11631, 11631, 11631, 11631,
   11631, 11631, 11631, 11631, 11631, 11631, 11631, 11631, 11631, 11631,
    8065, 11631, 11631, 11631, 11631, 11631,    30, 11631, 11631,  1246,
   -1899,   760, 15935,   277,   396, 11631, 11631, 11631, -1899,  1244,
    1247,  1247,  1004, 11631, 11631, 11631, 11631,  1250,  9300,  9300,
   15022,  1005,  1252, -1899,  1007, -1899, -1899,  -175, -1899, -1899,
    9235,  9575,   210,   210,    33,    33,  -165, 10307, 10307, 11631,
    2855,  -142, -1899, 11631, 11631, 11631, 11631, 11631, 11631, 11631,
   11631, 11631,   426, 15960,  1256,  1258,  1259, 11631,  1261, 11631,
   -1899, -1899, 11631,  4122, -1899, -1899,  9300,  9300,  9300, 11631,
    1262,  9300, 11631, 11631, 11631, 15985,  1009, -1899, -1899, 16010,
   16035, 16060,  1083,  9917, -1899,  1015,  6257, 16085, 16110, 15105,
   13205, 13205, 13205, 13205, 13205, 13205, 13205, 13205, 13205, 11631,
   13205, 13205, 13205, 13205,    26,  3111, 13205, 13205, 13205,    30,
      30, -1899, -1899,  9300, -1899,  1017, 12033, -1899,  1018, 12075,
   11631,   992, 11631, -1899,    30, 11631, 11631,  1246,  1026,   496,
   16135, 13226,  1032,   499, 11631,  1275,  1027,  6820, 16160, 15132,
     254,  1033,  1280,  1283, -1899, -1899, -1899,  9300,   292, 11631,
   -1899, -1899, -1899,    30, 11631, 11631,  1246,  1041, -1899,  1045,
     -35,    58,     1,    58, -1899,  1042, 14152, -1899,   145,  9300,
      30, 11631, 11631,  1295,  1294,  9300,  1296,  9300, 11631,  1297,
   13205,    30, 10640,  1295, 11631,  1299, -1899,    30,  1301, 13205,
   11631,  1049,  1055, -1899, 11631, 10173, 10254, 10506, 10587,  3111,
    1303,  1304,  1305, 16185,  1306,  1316,  1318, 16210,  1319,  1324,
    1325,  1326,  1332,  1334,  1335, -1899,  1337,  1342,  1344, -1899,
   11631, 16235,  9300,  1100,  9300, 14181, -1899, -1899,  1346, 15078,
   15078, 15078, 15078, 15078, 15078, 15078, 15078, 15078, 15078, 15078,
   10915, 15078, 15078, 15078, 15078,   939,   476, 15078, 15078, 15078,
   11169, 11250, 11497,  6008,  1101,  1102,   102,  9300, 11578, 12073,
     476, 12652,   476,  1094,  1103,  1104,   334,  9300, 11631, 11631,
   17185, -1899,   476,  1109, 14210, 14239, -1899, -1899,  1107,   345,
     476,   -71,  1105,   500,   525,  1351, -1899,  1295,   476,  1114,
    1115,  6506,  6755,  1899,  2470,   717,   717,   433,   433,   433,
     433,   433,   433,   504,   504,  9300,   224, -1899,   224,   224,
     992,   992,   992,  1113, 16260, 15159,   238,   720,  9300, -1899,
    1353,  1117,  1118, 16285, 16310, 16335, 11631,  6820,  1370,  1369,
    9979, 16360, 14268, 16385, 16410, -1899,   560,   569,  9300,  1119,
   -1899, 12144, -1899, 12250, 12308,   210, 11631, 11631, -1899, -1899,
    1121,  1122, 10307,  7502,  1242,   -37,   210, 12367, 16435, 14297,
   16460, 16485, 16510, 16535, 16560, 16585, 16610,  1125,  1375, 11631,
    1377, -1899, 11631, 16635, -1899, 15186, 12425, 15213, -1899,   570,
     576,   577, 14326, -1899,   578, 15240, 15267, 13261, -1899, -1899,
    1379,  1380,  1381,  1127, 11631, 12484, 11631, 11631, -1899, -1899,
      46,   509,   510,   509,  1137,  1138,  1131,   476,   476,  1132,
   13294,   476,   476,   476,   476, 11631,   476,  1384, -1899,  1134,
    1145,   519,   410,  1141,   579, -1899, -1899, -1899, -1899, 15078,
     224, 12542,  1139,   739,  1140,  1211,  1394,  1263, 10884,  1168,
    1171,  1422,  6820, 14355, -1899, 11631,  1424,   258,   151,  3111,
   11631,  1425,  1428,    41, -1899,   585,  1387,  1389,  6820, 14384,
      29,  1183, 16660, 15294,    91, 11631, 11631,  1188,  1187,  1190,
    1193,  8314, -1899, -1899, -1899, -1899, 13205,   365,  1192, 16685,
   15321, -1899,  1195, -1899,   380, -1899,   409, 13327, -1899, -1899,
   -1899,  1196, -1899,  1199, 13360, -1899,    79, -1899, -1899, 17185,
   -1899,  1439, 15078, 11631, 11631, 11631, 11631,   476,   210,  6820,
    6820,  1438,  6820,  6820,  6820,  1444,  6820,  6820,  6820,  6820,
    6820,  6820,  6820,  6820,  6820,  6820,  2085,  1447,  9300,  6008,
   -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899,
   -1899, -1899, -1899, -1899, 11631, -1899, -1899, -1899, -1899, -1899,
   -1899, -1899, -1899, -1899, 11631, 11631, 11631, -1899, -1899, -1899,
     595, 11631, 11631, -1899, 11631, -1899,  6820, 13205, 13205, -1899,
     596, 14413, 14442,  1200, -1899, -1899, -1899,  1266, 11631, 11631,
   -1899, -1899, -1899,  1295, -1899,  1295, 11631, 11631,  1207, -1899,
    6820,  -110, -1899, 11631, -1899, 11631, 11631,   597,  1295,   238,
     343, -1899, 11631, 11631,   476,   602,  6820,  9300,  9300,  1454,
    1455,  1460,  7255, -1899, -1899,  1462, -1899,  1217, 17185,  1215,
    1469, -1899,  1470,  1471,  1473,  1475,   603,  1480, -1899, 12601,
   -1899, -1899,  -127, 13393, 13426, -1899, -1899, 14471,  -130,  1368,
    1482, 10975,  1233,  1485,  1243,    17,    70,   -85, -1899,   -90,
   -1899,   -37,  1486,  1489,  1490,  1491,  1494,  1495,  1496,  1498,
    1499,    33,  6820, 17185, -1899,  2244,  1253,  1501, -1899,  1503,
    1505,  1391,  1506, -1899,  1507,  1509,  1510, 11631,  6820,  6820,
    6820,  1508, 13459, -1899,  7004,   979,    65,  1513, -1899,  9300,
   -1899, -1899, -1899, -1899, 13205, -1899, -1899, 11631, 13205, -1899,
   -1899, -1899, -1899, 17185, -1899,  1260,  1264, 13205, -1899, 13205,
   -1899,  1295, 13205,  1268, -1899,  1265, -1899,  1295, 11631, 11631,
    1271,    58,  1272, 11219, -1899,  2527,  1273,  6820, -1899,  1291,
   -1899, 14500, -1899, -1899, 11631,  1515,   248, 11631,  1516,  1517,
    2691, -1899,  1512,    24,  1523,  1298,   476,  -110,  -110,  1530,
   -1899, -1899,  1302,  1307,  1293, -1899,  1543, -1899, -1899, -1899,
   -1899, -1899,  1295,   527,  4342, 11631, 15348, 16710, 11631,  8558,
   11631,  9300,  1308,   611,  1544,   178,  1295, -1899,  1300, 11631,
    1546,  1548, 11631,  1295, 11303, 11631,  9544,   476,  5052,  1309,
    1310, -1899,  1549, 16735, 16760, 16785, 16810,  1555,   118,  1430,
    1430,  6820,  1561,  1562,  1563,  6820,   -89,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574, -1899,  1576,   612, 15078,
   15078, 15078, 15078,   476, 13492, 13525, 13558,  1330,   476,   476,
   -1899, -1899, -1899,  1439,   476, 16835, 15078,  1331,   194, 17185,
   15078, -1899,  1578,   476, 13591, 17185, 17185, -1899,   765, -1899,
    1582, -1899, 16860, 15375, -1899,   476,  1584,   613,   618,  6820,
    6820,  6820,  1587,  1586, -1899,   302, 11631,  6820,  6820,  6820,
    1333,  1338,  1588,   736, -1899, 11631, 11631, 11631,  1339,  1341,
    1343,  1347, -1899,  3108,  6820, -1899, 11631, -1899,  1596, -1899,
    1597, -1899, -1899, 10307,   265,  6073, -1899,  1352,  1354,  1358,
    1359,  1361,  1362,  8802,  1350,  1602, -1899,  9300, -1899, -1899,
   -1899,  1363, 11631, 11631, -1899, -1899, 15402,  1613,  1614,  1436,
   -1899, 11631, 11631, 11631, -1899,  1617,  1619,  1626,   927,   554,
    1373,  1175,  1374, 11631,    44,   476,  1383,   476,  1378, -1899,
   -1899,  3111,   770, 11631,  1385, -1899, -1899,  3262, -1899, -1899,
    1382,  1633, -1899,  3290, -1899,   264,  1386,  1634,  3426, -1899,
   -1899, -1899,    24, -1899,   619, -1899, 11631,   302, 11847, 11908,
   -1899,  1395, 11631, 11631,  6820,  1392, -1899,   307,  1650,  1651,
   16885,  1652,  1351, 16910,  1400,   620, 16935,   621,  1653,  1654,
   -1899, -1899, 13205,  1410,  1658, 16960, -1899, -1899, 13624,  1412,
   -1899,  7751,  5326, 17185, -1899,  1657,  -110,  7318, -1899, -1899,
   -1899, -1899,  1439, -1899,  1659,  1660,  1662,  1663, -1899, -1899,
     210,  1664,  1666,  1667, -1899, -1899, -1899,  1535,   -61,  1575,
    1669, -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899,
    1672,  1429, -1899, -1899, -1899, -1899, -1899, 11631, 11631, 11631,
   -1899, -1899, -1899,  1310, -1899, -1899, -1899, -1899, 11631,  1427,
    1420, -1899, -1899, 11631, 11631, 11631,   476,   238, -1899, -1899,
   -1899, -1899,  1431,  1432,  1679,   -89,  1682, 11631, -1899,  6820,
   17185,  1550,  1551,  1020,  9300,  9300, 11631, -1899,  9979, 14529,
   16985,  8000,    33,    33, 11631, 11631, -1899,   559,  1434, 17010,
   -1899, -1899, 14558,   -50, -1899,  1685,  1690,  6820,   210,   210,
     210,   210,   210,  6322,  1691, -1899, -1899,   627, 11631,  3461,
    3754,  1692, -1899, -1899,  6820,  8249,   898, 17035, -1899, -1899,
   -1899, -1899,  9637, -1899, 13205, 11631, -1899, 13205, 17185,  9886,
    3111,  1442, -1899, -1899, -1899, -1899,  1451,  1445, 11631, 11631,
   14587, 11631, 13226, -1899, 13226,  6820, -1899, -1899,  3111, 11631,
    1700,  1703,    41, -1899,  1702, -1899,    24, 15429,  6820, 13205,
    1705,   476, -1899,  1449,   476, 11631, 13657, 13690,   628, -1899,
   11631, 11631,   562, -1899,  1457, -1899,  1460,  1707,  1708,  1471,
    1709, -1899, -1899,  1710, 11631, -1899, -1899, 11631, 11547,  1711,
   11631, -1899, -1899,  1463, 11908,   630,  5511,  1712, -1899, -1899,
   -1899, -1899, -1899,   768, -1899, -1899, -1899,  1577,  1716,  1468,
    1472,  1474, -1899,  1720,  6820, 15078, 15078, 13723, 15078, -1899,
    1476, 13756, 17060, 15456, -1899, -1899,  9300,  9300, -1899,  1724,
   -1899, 17185,  1726, 11631, 11631,  1478, -1899,   633,   635, 15050,
    3879,  1729,  1481, -1899, -1899, 11631,  1483,  1484, 14616, 15483,
    1731,  6820,  1719,  1487, 11631, -1899, -1899,   638,   184,   203,
     216,   283,   310,  9051,   341, -1899,  1732, 14645, -1899, -1899,
   -1899,  1557, -1899, 11631, 11631, -1899, -1899,  9300,  4274,  1737,
    1492, 15078,   476, 17185, -1899, -1899, -1899, -1899,    44, -1899,
    3111, -1899, 14674,  1493,  1497,  1500,  1739,  4380, -1899,  1740,
    1744, -1899, -1899,  1504,  1745,   641, -1899,  1748,  1749,   480,
   17185, 11631, 11631,  1502,  6820,   643, 17185, 17085, -1899, -1899,
   -1899, -1899, 17110, 13789, -1899, -1899, 14703,  1200,  1264,  6820,
     476, -1899, 11631,  3111,    30, -1899, -1899,  9300,  9300, 11631,
    1752,   649, -1899, -1899, 11631,  1420, -1899, 11631, -1899, -1899,
     651,   652, -1899, -1899,  4457,  4799,  6820,   668,   678,  9300,
   -1899, -1899,    33,  8493, -1899, -1899, -1899,  1754, -1899,  1511,
    6820, -1899, 14732,  1756,  9300,   210,   210,   210,   210,   210,
   -1899, -1899, 11631, 14761, 14790,   654, -1899, -1899, -1899, -1899,
   -1899, -1899,  1518,  1758,  1514, -1899,  1762, -1899, -1899,    24,
   -1899,  1559, -1899, -1899, -1899, -1899, -1899, 11631, 13822, 13855,
    6820, -1899,  1765, 11631,  1519, -1899, 11631,  1766,  1520,  1521,
   -1899, -1899,  5759, -1899,  1522,   657,   662, 14819, -1899,  1524,
   13888,  1534, 13921, -1899,  1536, -1899, -1899,   663,  1537,   210,
    6820,  1769,  1541,   210,  1792,   665,  1547, -1899, 11631, -1899,
    1793,  1661, 12659,  1552, -1899,   670,   344,   349,   367,   371,
     382,  4988, -1899, -1899,  1796,  1798, -1899, -1899, -1899,  1799,
   -1899,  1553, 17185, 11631, 11631,   671, -1899, 17185, 13954, -1899,
   -1899, -1899,  1200,  3111,  1554, -1899, -1899, -1899, 11631, 11631,
   -1899, 11631,  9300,  1804,   210,   133, -1899, -1899,   210,   147,
   -1899,  1805, -1899, 14848, -1899, 11631, -1899,   -37, -1899,  1806,
    9300,  9300,  9300,  9300,  9051, -1899, -1899, -1899, 13226, -1899,
   11631, 17135, 13987,    23, 11631,  1558, -1899, -1899, 14020, 14053,
   14086,   672, -1899,   384, -1899,   397, -1899, -1899, -1899,  5267,
     446, 12718, -1899,   682,   684,   685,   708,   406,   709,  1560,
     714, -1899, 11631, -1899,  6820, 14877, -1899, 11631, 11631, 11631,
   -1899,   210,   210, -1899, -1899, -1899,   -37,  1807,  1809,  1811,
    1812,  9300,  1813,  1817,  1818,  1580, 17160,   716,  1819, 14906,
   15078, 14119,   411,   420,   481, -1899, -1899, -1899, -1899,   722,
   -1899, -1899, -1899, 13205, -1899,  1581, -1899,  1821, -1899, 11631,
   11631, 11631, -1899,  1822,   723, -1899,  1583,  6820, -1899, 14935,
   14964, 14993, -1899,  1823, 13205, 13205,   724, -1899,  1824,  1825,
   -1899, -1899,   725, -1899,  1826, -1899, -1899,  1831, 13205, -1899,
   -1899, -1899
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1899, -1899, -1899, -1899,   464, -1899, -1899, -1899, -1899,  -289,
   -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899, -1899,
   -1899, -1899,  -724,  -111,    -1,  3480, -1899,  1371, -1899, -1899,
   -1899, -1899, -1899, -1899, -1898, -1899,   412,   231,   -94, -1899,
     -52, -1899,   172,   448, -1899,  1846, -1899,   303,   -48, -1899,
   -1899,     0,  -622,  -257, -1899, -1899, -1899, -1899, -1899, -1899,
   -1899, -1899,  1847, -1899, -1899, -1899, -1899, -1247, -1246,  1849,
   -1733,  1850, -1899, -1899, -1899,  1245, -1899,  -114, -1899, -1899,
   -1899, -1899,  2080, -1899, -1899, -1420,   317,  1854, -1899,     6,
    -721, -1899, -1899,   -60, -1899, -1692,   421,   -40,  2551,  2770,
    -314,    97, -1899,  1087,  -103, -1899, -1899,   123,   291, -1690,
    -147,  1084, -1899,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -570
static const yytype_int16 yytable[] =
{
     143,  1492,   624,   124,  1494,   410,  1033,   414,   324,   326,
     466,   329,   950,   951,   310,  1867,  1050,   151,  1659,  1903,
     415,  1904,   167,  1487,  1058,   170,   658,   175,   371,  2163,
     165,   166,   445,  1351,   165,  1064,   417,   452,  1819,  2028,
     450,   551,   349,   179,   350,   165,     4,   574,  1739,  1896,
    1628,   289,  1082,  1286,  1240,     5,   294,  1820,   183,   427,
     785,   344,  1093,   375,   632,   633,   786,   475,   165,  1525,
     294,   640,  1241,   315,   632,   633,  1489,   770,   781,   295,
     348,  1242,  1243,  1244,   147,   945,  1386,  1245,  1246,   289,
     663,   146,   474,  1067,   374,   952,   165,   632,   633,   316,
    1629,   753,  1240,   304,   153,   411,   305,   306,   307,   632,
     633,   596,   632,   633,  1940,   317,   318,   144,   956,   308,
    1241,   145,   304,   596,  1619,   305,  1479,   307,   788,  1242,
    1243,  1244,  1951,  1475,   786,  1245,  1246,   351,   308,  2144,
     451,   168,   446,   169,   453,   461,   461,   461,   345,   632,
     633,  1073,   354,  2146,   468,   355,   501,   299,  1333,   716,
     300,   719,   154,   301,   508,   302,  1191,   724,   356,   731,
    1493,  1491,   480,  1526,  1527,   148,    46,    67,    68,    69,
      70,  1182,   309,    73,  1591,   340,  1183,   341,   461,   632,
     633,  1488,    82,   289,  2135,    85,   289,   149,   547,   548,
     425,   289,   289,   461,   426,  1352,  1353,  1354,  1355,   150,
    1864,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   536,   537,   538,   539,   540,   541,
    1830,   543,   544,   155,  1490,  1740,   740,   117,  1492,   117,
     549,   550,  1555,   117,   346,   289,   609,   610,   611,   627,
     628,  1049,   558,   559,   117,  1333,   152,   636,   641,   289,
     416,  1758,   289,   572,  2047,   659,   156,   660,  2164,   372,
     117,   145,   571,   157,  1015,  1356,   418,   117,   289,   289,
     180,   552,   289,   289,   289,   289,  1343,   575,   160,  1056,
     654,   655,   656,  1287,   428,   184,   123,   289,   429,  1333,
     376,   289,   347,   374,   158,   117,   745,   670,   746,   771,
     782,   772,   772,  1334,  1337,   773,   783,   643,  2085,   735,
     168,   644,   169,   159,   168,   289,   169,   289,   289,   289,
     439,   440,  1365,   754,  1319,   755,  -565,  -562,   161,   756,
     439,   440,   768,   597,   289,   598,  1159,   632,   633,   599,
     769,   289,   439,   440,   303,   597,   941,   598,   943,   944,
     162,   599,   632,   633,   163,   435,   436,   437,   438,  1074,
    1075,   164,   690,   691,   692,   957,   632,   633,   696,   697,
     698,   699,   700,   701,   702,  2159,   703,   176,   866,   439,
     440,   704,   705,   976,  1240,   708,   439,   440,  1336,   725,
     177,   726,  1074,  1075,   296,   727,   178,   297,   720,   298,
     461,   289,  1241,   632,   633,   289,   289,   995,   741,   742,
     181,  1242,  1243,  1244,  1556,  1557,   823,  1245,  1246,   182,
     824,   289,   632,   633,  1984,   168,   447,   169,   757,   320,
     321,   447,   447,   447,  1186,   632,   633,   185,   882,   774,
     447,   322,  1437,  1985,  1438,   323,  1031,   775,   593,   594,
     330,   793,  2187,   186,   595,   287,  1986,  1448,   435,   436,
     437,   438,   435,   436,   437,   438,   439,   440,   435,   436,
     437,   438,   200,   171,   447,   201,   172,   776,   202,   173,
     289,   174,   439,   440,   187,   777,   439,   440,   534,   447,
     535,   203,   439,   440,   188,   876,   435,   436,   437,  1057,
     189,  1704,   632,   633,   289,  2226,   435,   436,   437,   438,
     886,   289,   856,   921,   824,  2041,   461,   824,   461,   289,
     461,   461,   468,  1987,   682,  1003,   145,   872,   546,   632,
     633,   289,   289,   289,   461,   461,   289,   167,  1781,   167,
    1749,   289,  -566,   555,   556,   331,   881,   576,   883,   332,
    1988,   888,   948,   949,   779,   333,   334,   628,   335,   336,
     632,   633,   780,   632,   633,  1240,  1169,   289,   632,   633,
    1538,   439,   440,   913,   780,   195,  1542,   745,   337,   746,
    1450,  1989,  1018,  1241,  2120,  1179,   632,   633,   190,  2121,
     632,   633,  1242,  1243,  1244,   289,   289,  1375,  1245,  1246,
    1240,   632,   633,   632,   633,   824,   509,  2122,   191,  1051,
     311,  2123,  1380,   312,   453,   453,   632,   633,  1241,  1504,
     824,  1577,  2124,   192,  2171,   632,   633,  1242,  1243,  1244,
     632,   633,   922,  1245,  1246,  1593,   824,  2172,   193,   632,
     633,  1381,  1599,   289,   289,   289,  2181,  1311,   289,   824,
    1312,  2210,   588,   589,   722,   591,   592,   593,   594,   287,
    2211,   194,   967,   595,   196,  1229,   824,   468,   461,   468,
     461,   461,   461,   461,   461,   461,  1107,   461,   461,   461,
     461,  1017,  2174,   461,   461,   461,   167,  1023,   320,   321,
     289,   632,   633,   197,  1069,  1022,   608,   632,   633,   198,
     322,  1032,   632,   633,   328,   199,   447,   634,   745,   205,
     746,   617,  2016,   635,   289,   622,   736,  2212,   642,   206,
    2017,  1679,  1687,  1688,   289,   722,   591,   592,   593,   594,
    1061,   168,  1035,   169,   595,  1041,   824,  1185,   765,  1042,
    1186,   745,   745,   746,   746,   290,   289,  1078,   291,   780,
    1289,   745,   289,   746,   289,   439,   440,   468,  1091,  1309,
     293,  1189,  -564,   313,  1096,   824,   461,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,  1201,   745,   292,   746,   595,
     439,   440,  2048,  2049,   824,  1860,  1224,  -569,  2050,   289,
     824,   289,  2052,  2053,   339,  1225,  1270,  1219,  2050,   824,
     824,  1759,  1271,  1272,  1274,  1315,   824,   824,   824,   824,
     314,  1346,   447,  1768,   447,   824,   447,   447,   447,   732,
     733,  1423,  1430,  1447,   289,   824,   824,   824,  1455,  1472,
     447,   447,   824,   824,   289,   743,   342,  1589,  1641,  1672,
    2150,   824,   824,   824,  1673,  1765,  1788,  1790,   824,  1766,
     824,   824,  1187,  1876,  1923,  1232,  1941,   824,  1924,  1967,
    1942,  1968,  1238,   824,  1983,   824,  1249,  2013,  1924,  2022,
     319,   780,   289,  2023,  1492,  2039,  1884,  2043,  2044,  1924,
    2074,   824,   824,  2095,   824,   289,  1204,   824,  2096,  2103,
     343,  2111,   824,  1924,   289,   824,  2119,  2133,  2170,  2194,
     824,  1924,   824,  1731,  1732,   289,  1335,  1338,  2177,   352,
    2178,  2179,   824,   765,   824,   824,  1339,   576,  1492,   327,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,   863,  2180,  2182,   765,   595,   824,   824,
    2184,  1202,  2205,  1203,  2023,   608,  1924,   877,  2213,  2223,
    2234,  2237,   824,  2224,  1924,  2238,   745,  1523,   746,   747,
    1318,   353,  1319,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   338,   447,   447,   447,   447,   632,   633,   447,
     447,   447,   745,   358,   746,   918,  1664,   359,  1665,   765,
     360,  1748,   765,  1749,  1845,   361,  1846,   367,   368,  1563,
     369,   370,   377,   378,   765,   379,   380,   381,   412,   289,
     424,   423,   430,   457,   456,   431,   472,   474,  1398,   145,
    1345,   476,   477,   478,   479,   289,   484,   488,   502,   507,
     542,   545,  -198,  -199,  1068,  -200,  1070,   553,   289,   554,
    1856,  1857,   557,   461,   560,   561,   562,   573,   605,   606,
     613,   426,   615,   447,   621,   614,   662,   618,  1449,  1451,
     623,   625,   447,   626,   645,  1387,   646,   647,   648,   649,
     650,   651,   657,   661,   664,   665,   289,   289,   666,   289,
     289,   289,   667,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   668,   669,   289,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,   671,   672,   673,   674,   595,   677,
     678,   684,   685,   693,  1885,   694,   695,   706,  1046,   711,
     707,   709,   712,   289,   461,   461,   710,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     822,   591,   592,   593,   594,   713,   714,   289,   717,   595,
    1443,   745,   715,   746,   718,   734,   737,   744,   749,   751,
     752,   144,   790,   289,   289,   289,   758,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,   794,   799,   815,   820,   595,
     449,  1524,   826,   827,   828,   459,   462,   463,   857,   867,
     868,   869,   595,   889,   765,   887,   765,   765,  1764,   890,
     916,   926,  1449,  1451,   927,   930,   935,   939,   940,   289,
     765,   453,   942,   969,   971,   989,   972,   974,   983,   993,
     996,   165,   382,  1025,  1027,   289,   289,   289,   496,   765,
    1034,  1044,  1045,  1604,  1040,  1609,   289,  1053,  1752,  1054,
    1052,   461,  1754,   510,  1065,   461,  1066,  1071,   765,  1081,
    1083,  1100,  1085,  1088,   461,  1095,   461,  1097,  1101,   461,
    1108,  1109,  1110,  1112,   383,   384,   385,   386,   387,   388,
     389,   390,   391,  1113,   289,  1114,  1116,   392,   393,   394,
     395,  1117,  1118,  1119,   765,   396,   397,   398,   399,  1120,
     374,  1121,  1122,   400,  1123,   401,  1568,  1569,  1213,  1124,
    2056,  1125,  1132,  1157,  1166,  1128,  1158,  1184,  1190,   402,
    1206,   461,   403,  1167,  1168,  1175,   289,  1178,   289,  1193,
    1198,  1194,  1207,  1208,  1214,  1216,  1227,  1235,  1236,   447,
    1261,  1239,  1262,  1264,  1281,   289,  1278,  1279,  1280,  1292,
    1293,  1294,  1297,  1305,  1307,  1314,  1317,  1308,   289,  1320,
    1321,  1322,   289,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,  1773,  1773,  1323,  1326,   595,  1327,   745,  1328,   746,
    1332,  1341,  1342,  1703,  1347,  1735,  1348,  1658,  1747,  1368,
    1362,  1370,  1369,  1388,  1760,  1401,  1379,  1666,  1371,  1376,
    1384,  1405,  1912,  1383,  1417,  -201,   289,   289,   289,  1441,
    1433,  1459,  1460,  1329,   289,   289,   289,  1461,  1464,  1465,
     447,   447,   404,   405,   406,  1466,  1467,  1468,  1469,  1349,
    1470,   289,  1471,   407,  1473,  1480,  1481,   408,  1484,   409,
     117,  1485,   289,  1495,  1486,  1496,  1511,  1497,  1498,  1802,
     289,  1499,  1500,  1501,   289,  1502,  1503,  1508,  1507,  1509,
     728,  1510,  1520,  1512,  1513,  1514,  1515,  1528,  1533,  1562,
    1540,  1554,  1559,  1560,  1534,  1541,  1543,  1545,  1549,  1565,
    1399,  1400,   765,  1402,  1403,  1404,  1570,  1406,  1407,  1408,
    1409,  1410,  1411,  1412,  1413,  1414,  1415,  1551,  1574,  1576,
    1590,  1566,  1596,  1572,  1597,  1613,  1835,  1594,  1573,   374,
    1813,  1618,  1620,  1611,  1588,   468,   468,  1624,  1625,  1626,
    1612,   289,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1650,  1657,  1661,  1851,  1667,  1427,  1684,   461,
    1671,  1677,  1678,  1685,  1692,  1686,  1693,   447,  1694,   289,
    1695,   447,  1700,  1701,   289,  1804,  1715,  1707,  1716,  1708,
     447,  1442,   447,  1709,  1710,   447,  1711,  1712,  1718,  1722,
    1723,  1724,  1915,  1728,  1544,  1729,   860,  1456,   862,  1889,
     864,   865,  1730,  1734,  1737,  1744,  1894,  1897,  1312,  1756,
    1751,  1762,  1755,  1761,   878,   879,  1775,  1780,  1868,  1869,
    1870,  1871,  1872,  1874,  1782,  1906,  1787,  1783,  1785,  1791,
    1792,  1794,  1795,  1798,  1803,  1809,  1810,   447,  1811,  1812,
    1814,  1835,  1815,  1816,  1817,  1822,   289,  1823,  1821,  1829,
    1186,   289,   289,  1505,  1824,  1838,  1836,  1837,  1840,  1843,
    1844,  1865,   453,   453,  1861,  2079,  1866,  1875,  1880,  1517,
    1518,  1519,  1898,  1899,   289,  1900,  1908,  1909,  1911,   780,
     289,  1916,  -567,  1928,  1929,  1930,  1931,  1935,  1939,  1944,
    1945,   289,  1946,  1947,  2062,  1950,  1980,  1948,  1956,  1949,
    1962,   461,  1963,  1966,   461,  1971,  1972,  1978,  1990,  1974,
    1975,  1992,  1981,  1997,  1998,  2007,  2080,  2009,  1550,  2004,
    2010,  2012,   289,  2005,  2014,  2015,  2006,  2020,  2038,  1345,
    2059,  2011,  2064,   374,  2076,   289,   468,  2060,  2078,  2077,
    2075,  2086,  2089,  2094,  -568,  2107,  2090,  2091,  1002,  2098,
    1004,  1005,  1006,  1007,  1008,  1009,  2100,  1011,  1012,  1013,
    1014,  2102,  2104,  1019,  1020,  1021,  2108,  2002,  2110,  2114,
    2115,   468,  2126,  2112,  2127,  2129,  2137,  2118,  2130,  1608,
    2142,  2147,  2152,  2195,  2166,  2196,  2183,  2197,  2198,  2200,
    2128,   289,  1623,  2201,  2202,  2206,  1627,  2218,  2222,  2230,
    2235,  2236,  2239,   289,   289,  2203,  2217,  2240,  2225,  1592,
    2033,  2160,   789,  1808,  2029,  1653,  2001,  1839,  1622,   122,
     133,   750,   134,   135,  2054,  1746,   929,   141,   289,  1910,
    1774,  2151,  1895,     0,  1090,     0,     0,  1089,     0,     0,
     289,   447,   447,     0,     0,     0,  1098,     0,     0,     0,
    1674,  1675,  1676,     0,   289,     0,     0,     0,  1681,  1682,
    1683,     0,     0,     0,     0,   447,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1698,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1706,     0,     0,     0,
       0,   289,     0,     0,  1714,  2066,  2067,  2068,  2069,  2070,
       0,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,  2034,     0,     0,   289,   289,     0,     0,     0,     0,
       0,     0,     0,     0,   413,   382,     0,     0,     0,     0,
       0,     0,     0,   289,     0,     0,   289,     0,     0,     0,
       0,     0,   453,     0,     0,     0,     0,   289,     0,     0,
       0,   289,     0,     0,     0,     0,     0,     0,     0,  2105,
    2136,     0,     0,  2109,     0,  1779,     0,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   374,     0,     0,     0,
     392,   393,   394,   395,     0,     0,     0,   289,   396,   397,
     398,   399,     0,  1801,     0,     0,   400,     0,   401,     0,
       0,     0,     0,     0,     0,     0,     0,   447,     0,     0,
     447,     0,   402,     0,  2143,   403,     0,   289,  2145,     0,
       0,     0,     0,     0,     0,   765,     0,   765,     0,     0,
       0,   767,     0,     0,  2157,     0,     0,     0,     0,     0,
       0,     0,   447,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,  1416,     0,     0,     0,   595,     0,     0,     0,   289,
    1842,     0,     0,     0,     0,     0,     0,   447,     0,     0,
       0,  2192,  2193,     0,     0,     0,     0,   289,   289,   289,
     289,   289,     0,     0,     0,     0,     0,     0,  1779,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,  1881,     0,     0,     0,   595,
       0,     0,     0,     0,     0,   404,   405,   406,     0,     0,
       0,   289,     0,  1374,     0,     0,   407,     0,     0,     0,
     408,     0,   409,     0,     0,     0,  1905,     0,   289,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1914,
       0,     0,     0,     0,     0,     0,   421,     0,     0,     0,
     461,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   289,     0,     0,     0,     0,     0,
       0,   461,   461,   448,     0,     0,     0,   458,     0,     0,
       0,     0,   464,     0,     0,   461,     0,     0,     0,     0,
     469,     0,     0,     0,     0,  1779,     0,     0,     0,     0,
    1506,     0,     0,     0,  1428,  1429,   481,   482,   483,     0,
     485,   486,   487,     0,   489,   490,   491,   492,   493,   494,
     495,     0,   497,   498,   499,   500,     0,     0,     0,   504,
       0,     0,  1979,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2021,     0,     0,     0,     0,
       0,   563,   565,   567,   568,   504,     0,     0,     0,     0,
    2030,     0,     0,     0,     0,   765,     0,     0,     0,     0,
     602,   504,   504,     0,     0,     0,     0,     0,     0,     0,
       0,  1530,     0,     0,     0,  1532,     0,  1779,     0,     0,
       0,     0,   620,     0,  1536,     0,  1537,     0,     0,  1539,
       0,  2061,   630,   631,     0,     0,     0,     0,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   504,   653,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   765,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1779,     0,   675,   504,     0,     0,     0,   679,   680,
     681,  1579,   683,     0,   765,     0,   686,   687,   688,     0,
       0,   689,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2106,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
     721,     0,     0,     0,   504,   730,   447,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   738,   739,     0,     0,     0,     0,   447,   447,     0,
       0,     0,     0,  1548,     0,     0,   766,     0,     0,     0,
       0,   447,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   795,   796,   797,   798,
       0,     0,     0,     0,   803,     0,     0,     0,   807,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   821,   565,     0,  1779,     0,   825,     0,     0,
       0,   829,   830,   831,   832,   833,   834,   835,   836,   837,
     838,   839,   840,   841,   842,   843,   844,   845,   847,   848,
     849,   850,   851,   852,   853,   853,     0,   858,   859,     0,
     861,     0,     0,     0,     0,     0,     0,     0,     0,   870,
       0,     0,   874,   875,     0,     0,     0,     0,  1779,   853,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   891,   892,   893,   894,
     895,   896,   897,   898,   899,   900,   901,   902,   903,   904,
     906,   908,   909,   910,   911,   912,     0,   914,   915,  1793,
       0,     0,     0,     0,     0,   923,   924,   925,     0,     0,
       0,     0,     0,   931,   932,   933,   934,  1561,   504,   504,
       0,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,   563,   721,   953,
     595,     0,     0,   958,   959,   960,   961,   962,   963,   964,
     965,   966,     0,     0,     0,     0,     0,   973,     0,   975,
       0,     0,   977,     0,     0,     0,   504,   504,   504,   982,
     505,   504,   985,   986,   987,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1010,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,     0,     0,     0,     0,
    1029,     0,  1030,     0,     0,   914,   915,     0,     0,     0,
       0,     0,     0,     0,  1043,     0,     0,     0,     0,     0,
       0,  1890,     0,   566,  1892,     0,   505,   504,     0,  1059,
       0,     0,     0,     0,  1062,  1063,     0,     0,     0,     0,
       0,     0,   505,   505,     0,     0,     0,     0,     0,   504,
       0,  1079,  1080,     0,     0,   504,     0,   504,  1087,     0,
       0,     0,  1079,     0,  1094,     0,     0,     0,     7,     8,
    1099,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1126,     0,   906,     0,  1129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,   504,     0,     0,
       0,   595,     0,     0,     0,     0,     0,   504,  1171,  1172,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,   506,
      43,    44,    45,    46,     0,   505,    48,     0,     0,     0,
       0,     0,     0,   759,    55,   504,     0,    58,   760,     0,
     761,   762,     0,   763,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,     0,  1212,     0,     0,     0,
    1218,    79,     0,     0,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,     0,  1233,  1234,     0,     0,
       0,     0,  1237,     0,     0,     0,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1263,
       0,     0,  1265,     0,   566,     0,     0,     0,     0,     0,
       0,   603,   604,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1282,     0,  1284,  1285,   846,     0,
       0,     0,     0,     0,     0,   854,   855,     0,     0,     0,
       0,     0,     0,     0,     0,  1303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,     0,
     880,   954,     0,     0,  1696,   505,   382,     0,  1325,     0,
       0,     0,     0,     0,     0,  1331,     0,     0,     0,     0,
    1340,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   907,     0,     0,     0,  1366,  1367,     0,     0,     0,
       0,   504,     0,     0,     0,     0,     0,     0,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,   505,
     505,   392,   393,   394,   395,     0,     0,     0,     0,   396,
     397,   398,   399,  1393,  1394,  1395,  1396,   400,     0,   401,
       0,     0,     0,     0,   729,     0,     0,     0,     0,     0,
       0,     0,     0,   402,     0,     0,   403,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,   505,   505,   505,
       0,     0,   505,     0,  1419,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1420,  1421,  1422,     0,     0,     0,
       0,  1424,  1425,     0,  1426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1435,  1436,
       0,     0,     0,     0,   505,     0,  1439,  1440,  1753,     0,
       0,     0,     0,  1444,     0,  1445,  1446,     0,     0,     0,
       0,     0,  1452,  1453,     0,     0,     0,   504,   504,     0,
    2215,     0,     0,     0,     0,     0,  1757,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2231,  2233,     0,     0,     0,   404,   405,   406,     0,
     505,  1483,     0,     0,     0,  2241,   505,   407,   505,     0,
       0,   408,     0,   409,   884,     0,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,  1516,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,     0,     0,   907,     0,  1130,     0,  1531,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   936,   937,
       0,     0,     0,     0,     0,     0,     0,     0,  1452,  1453,
       0,     0,     0,  1547,     0,     0,     0,     0,   505,     0,
       0,     0,     0,     0,  1553,     0,     0,  1558,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1763,     0,     0,     0,   979,   980,   981,     0,
       0,   984,     0,     0,     0,  1580,     0,     0,  1583,   504,
    1586,   504,     0,     0,     0,     0,   505,     0,     0,  1595,
       0,     0,  1598,     0,  1595,  1601,  1603,  1878,     0,   505,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1024,     0,     0,     0,     0,     0,   505,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,  1055,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,  1077,
     595,     0,     0,     0,     0,  1084,  1680,  1086,     0,     0,
       0,     0,     0,     0,     0,  1689,  1690,  1691,     0,     0,
       0,     0,     0,     0,  1697,     0,  1699,     0,     0,     0,
       0,     0,     0,  1702,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,  1719,  1720,     0,     0,     0,     0,     0,     0,
       0,  1725,  1726,  1727,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1738,     0,     0,     0,     0,     0,     0,
       0,     0,   505,  1750,     0,     0,     0,  1160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1170,     0,     0,
       0,     0,     0,     0,     0,     0,  1767,     0,     0,     0,
       0,     0,  1776,  1777,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,  1197,   595,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,  1806,  1205,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,  1226,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1825,  1826,  1827,
       0,     0,     0,     0,     0,     0,     0,     0,  1828,     0,
       0,     0,     0,  1831,  1832,  1833,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1841,   505,   505,
    1879,     0,     0,     0,   504,   504,  1849,     0,  1850,     0,
       0,     0,     0,     0,  1858,  1859,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,     0,     0,  1877,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1888,     0,     0,  1891,     0,     0,     0,  1893,
       0,     0,     0,     0,     0,     0,     0,     0,  1832,  1833,
       0,  1902,     0,     0,     0,     0,     0,     0,     0,  1907,
     505,  1373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1920,     0,     0,     0,     0,
    1926,  1927,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1932,     0,     0,  1933,  1932,     0,
    1936,     0,     0,     0,     0,  1970,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1418,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,   504,     0,     0,
     505,     0,   505,  1964,  1965,     0,   748,     0,     0,     0,
       0,     0,     0,     0,     0,  1973,     0,     0,     0,     0,
       0,     0,     0,     0,  1982,     0,     0,     0,     0,     0,
       0,     0,     0,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1993,  1994,     0,     0,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1457,  1458,     0,
       0,     0,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,  2018,  2019,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2032,     0,     0,     0,     0,   504,   504,  2037,
     871,     0,     0,     0,  2040,     0,     0,  2042,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,     0,     0,     0,     0,     0,     0,     0,   505,  1529,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,  2071,     0,     0,     0,     0,     0,     0,     0,
       0,   919,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2082,     0,     0,
       0,     0,     0,  2087,     0,     0,  2088,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     7,     8,     0,  2113,  1585,
       0,  1587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1807,     0,
       0,     0,     0,  2131,  2132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2138,  2139,
       0,  2140,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2149,     0,     0,     0,     0,
     504,   504,   504,   504,   504,     0,     0,     0,     0,     0,
    1926,     0,     0,     0,  2165,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,   505,   505,    43,    44,    45,
      46,     0,  2186,    48,     0,     0,     0,  2189,  2190,  2191,
     759,    55,     0,     0,    58,   760,     0,   761,   762,     0,
     763,   504,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1717,    79,     0,
    1996,     0,     0,     0,     0,     0,     0,     0,     0,  2219,
    2220,  2221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,     0,     0,     0,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
       0,  1145,  1146,  1147,  1148,     0,  1150,  1151,  1152,  1153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1163,     0,  1165,     0,     0,     0,   165,   382,     0,     0,
       0,     0,  1174,     0,     0,     0,     0,     0,     0,  1180,
    1181,     0,     0,     0,     0,     0,     0,     0,  1192,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   978,     0,
       0,     0,     0,     0,     0,     0,  2008,   505,   505,   383,
     384,   385,   386,   387,   388,   389,   390,   391,     0,     0,
       0,     0,   392,   393,   394,   395,     0,     0,     0,     0,
     396,   397,   398,   399,   576,     0,     0,     0,   400,     0,
     401,     0,     0,     0,   566,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,   403,   505,     0,
       0,   299,     0,     0,   300,     0,     0,   301,     0,   302,
       0,     0,     0,     0,  1847,  1848,     0,     0,     0,     0,
      46,     0,     0,  2045,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   433,     0,     0,
       0,  1288,  1290,  1291,     0,     0,     0,  1295,  1296,     0,
       0,  1299,  1300,  1301,  1302,     0,  1304,     0,   505,   505,
       0,  1310,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
     505,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   404,   405,   406,
       0,     0,     0,     0,     0,     0,     0,     0,   407,     0,
       0,     0,   408,     0,   409,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1392,     0,     0,     0,     0,  1397,     0,     0,
     439,   440,     0,     0,     0,     0,     0,  -563,     0,  1578,
       0,     0,     0,     0,     0,     0,  1960,  1961,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,     0,   505,     0,     0,   595,  1995,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,   505,   505,   505,   505,     0,     0,     0,     0,
       0,     0,     0,     0,  1454,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2035,  2036,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,  2055,
       0,     0,     0,   207,   165,   382,     0,   432,     0,     0,
     208,   209,   210,     0,  2065,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   419,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   240,   241,   242,   243,
     392,   393,   394,   395,   244,  2046,     0,     0,   396,   397,
     398,   399,     0,     0,     0,     0,   400,     0,   401,   248,
     249,   250,     0,     0,     0,     0,  1567,     0,     0,     0,
     251,    25,   402,   252,     0,   403,     0,     0,     0,   299,
       0,     0,   300,     0,     0,   301,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,  1605,     0,     0,
       0,     0,  2141,     0,     0,   433,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2153,  2154,  2155,  2156,  2158,     0,     0,     0,     0,  1642,
    1643,  1644,  1645,  1646,     0,     0,     0,     0,  1651,  1652,
       0,     0,     0,     0,  1654,     0,  1656,     0,     0,     0,
    1660,     0,     0,  1662,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1670,     0,   434,     0,     0,
       0,     0,     0,     0,   262,   404,   405,   406,   263,     0,
       0,  2199,     0,   265,   266,   267,   407,   268,   269,   270,
     408,     0,   409,   117,   435,   436,   437,   438,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     420,     0,     0,     0,     0,     0,   273,     0,   439,   440,
       0,   441,     0,   442,  2125,     0,     0,   443,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1733,
       0,  1736,     0,     0,     0,  1743,     0,  1745,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,  1770,   595,
       0,     0,     0,     0,     0,   207,     6,   382,     0,     0,
       0,     0,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,  1606,
     384,   385,   386,   387,   388,   389,   390,   391,   240,   241,
     242,   243,   392,   393,   394,   395,   244,   245,     0,     0,
     396,   397,   398,   399,     0,     0,   246,   247,   400,     0,
     401,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,   402,   252,  1834,   403,     0,     0,
       0,   253,     0,     0,   254,     0,     0,   255,     0,   256,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,    56,    57,     0,   259,     0,   260,     0,     0,
     261,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,     0,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1917,     0,     0,  1918,     0,   262,   404,   405,   406,
     263,   264,     0,     0,     0,   265,   266,   267,   407,   268,
     269,   270,   408,  2173,   409,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   272,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   363,     0,  1952,  1953,  1607,  1955,     0,
     276,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,   207,
       6,   382,     0,   595,     0,     0,   208,   209,   210,   819,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,  1999,  2000,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   240,   241,   242,   243,   392,   393,   394,   395,
     244,   245,     0,     0,   396,   397,   398,   399,     0,     0,
     246,   247,   400,     0,   401,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   251,    25,   402,   252,
    2031,   403,     0,     0,     0,   253,     0,     0,   254,     0,
       0,   255,     0,   256,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,     0,    56,    57,     0,   259,
       0,   260,     0,     0,   261,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,     0,
       0,     0,     0,     0,     0,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,  1943,   576,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   404,   405,   406,   263,   264,     0,     0,     0,   265,
     266,   267,   407,   268,   269,   270,   408,     0,   409,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   272,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   363,   207,     6,
     362,   275,     0,     0,   276,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,   243,     0,     0,     0,     0,   244,
     245,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,     0,
    2208,     0,     0,     0,   253,     0,     0,   254,     0,     0,
     255,     0,   256,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,    56,    57,     0,   259,     0,
     260,     0,     0,   261,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,     0,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   822,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,  2093,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   263,   264,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   272,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,   207,     6,     0,
     364,     0,   676,   276,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,   245,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
       0,     0,     0,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   251,    25,     0,   252,     0,     0,
       0,     0,     0,   253,     0,     0,   254,     0,     0,   255,
       0,   256,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,    56,    57,     0,   259,     0,   260,
       0,     0,   261,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,   576,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,   263,   264,     0,     0,     0,   265,   266,   267,
       0,   268,   269,   270,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   503,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   363,   207,     6,  1705,     0,
     569,     0,   276,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,   243,     0,     0,     0,     0,   244,   245,     0,
       0,     0,     0,     0,     0,     0,     0,   246,   247,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,     0,   252,     0,     0,     0,
       0,     0,   253,     0,     0,   254,     0,     0,   255,     0,
     256,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,    56,    57,     0,   259,     0,   260,     0,
       0,   261,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   822,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,   997,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,   263,   264,     0,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   272,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   363,   207,     6,     0,   275,     0,
       0,   276,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,   243,     0,     0,     0,     0,   244,   245,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,     0,     0,
       0,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,     0,   252,     0,     0,     0,     0,
       0,   253,     0,     0,   254,     0,     0,   255,     0,   256,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,    56,    57,     0,   259,     0,   260,     0,     0,
     261,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,  1195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
     263,   264,     0,     0,     0,   265,   266,   267,     0,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   637,  1873,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   639,   207,     6,     0,   323,   569,     0,
     276,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
     243,     0,     0,     0,     0,   244,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,   254,     0,     0,   255,     0,   256,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,    56,    57,     0,   259,     0,   260,     0,     0,   261,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,  1196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   272,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   274,   207,     6,     0,   275,     0,     0,   276,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,   245,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,     0,   252,     0,     0,     0,     0,     0,   253,
       0,     0,   254,     0,     0,   255,     0,   256,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
      56,    57,     0,   259,     0,   260,     0,     0,   261,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,  1522,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   263,   264,
       0,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     272,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,   207,     6,     0,   275,     0,     0,   276,   208,
     209,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,   243,     0,
       0,     0,     0,   244,   245,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,     0,   252,     0,     0,     0,     0,     0,   253,     0,
       0,   254,     0,     0,   255,     0,   256,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,    56,
      57,     0,   259,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   263,   264,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   503,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     363,   207,     6,     0,   564,     0,     0,   276,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,   243,     0,     0,
       0,     0,   244,   245,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,  1462,     0,     0,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   251,    25,
       0,   252,     0,     0,     0,     0,     0,   253,     0,     0,
     254,     0,     0,   255,     0,   256,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,     0,    56,    57,
       0,   259,     0,   260,     0,     0,   261,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,     0,     0,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,   263,   264,     0,     0,
       0,   265,   266,   267,     0,   268,   269,   270,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   503,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   363,
     207,     6,     0,     0,   569,     0,   276,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,   243,     0,     0,     0,
       0,   244,   245,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,     0,
     252,     0,     0,     0,     0,     0,   253,     0,     0,   254,
       0,     0,   255,     0,   256,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,     0,    56,    57,     0,
     259,     0,   260,     0,     0,   261,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   988,     0,     0,     0,     0,     0,
       0,     0,   946,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   272,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   607,   207,
       6,     0,   275,     0,     0,   276,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,   245,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,     0,     0,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   251,    25,     0,   252,
       0,     0,     0,     0,     0,   253,     0,     0,   254,     0,
       0,   255,     0,   256,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,     0,    56,    57,     0,   259,
       0,   260,     0,     0,   261,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  1799,     0,     0,
       0,  1800,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,   263,   264,     0,     0,     0,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   272,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   616,   207,     6,
       0,   275,     0,     0,   276,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,   243,     0,     0,     0,     0,   244,
     245,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,     0,
       0,     0,     0,     0,   253,     0,     0,   254,     0,     0,
     255,     0,   256,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,    56,    57,     0,   259,     0,
     260,     0,     0,   261,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  1854,     0,     0,     0,
    1855,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   263,   264,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   503,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,   207,     6,     0,
     905,     0,  1372,   276,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,   245,
       0,     0,     0,     0,     0,     0,     0,     0,   246,   247,
       0,     0,     0,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   251,    25,     0,   252,     0,     0,
       0,     0,     0,   253,     0,     0,   254,     0,     0,   255,
       0,   256,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,    56,    57,     0,   259,     0,   260,
       0,     0,   261,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  1882,     0,     0,     0,  1883,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,   263,   264,     0,     0,     0,   265,   266,   267,
       0,   268,   269,   270,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   503,     0,     0,     0,     0,     0,
     273,   207,     6,     0,     0,   363,  1584,     0,   208,   209,
     210,     0,   276,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,   243,     0,     0,
       0,     0,   244,   245,     0,     0,     0,     0,     0,     0,
       0,     0,   246,   247,     0,     0,     0,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   251,    25,
       0,   252,     0,     0,     0,     0,     0,   253,     0,     0,
     254,     0,     0,   255,     0,   256,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,     0,    56,    57,
       0,   259,     0,   260,     0,     0,   261,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  2057,
       0,     0,     0,  2058,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,   263,   264,     0,     0,
       0,   265,   266,   267,     0,   268,   269,   270,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   503,     0,
       0,     0,     0,     0,   273,   207,     6,     0,     0,   363,
       0,     0,   208,   209,   210,     0,   276,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,   243,     0,     0,     0,     0,   244,   245,     0,     0,
       0,     0,     0,     0,     0,     0,   246,   247,     0,     0,
       0,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,     0,   252,     0,     0,     0,     0,
       0,   253,     0,     0,   254,     0,     0,   255,     0,   256,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,     0,    56,    57,     0,   259,     0,   260,     0,     0,
     261,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   778,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
     263,   264,     0,     0,     0,   265,   266,   267,     0,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   272,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   363,   207,     6,     0,  1713,     0,     0,
     276,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
     243,     0,     0,     0,     0,   244,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,   254,     0,     0,   255,     0,   256,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,    56,    57,     0,   259,     0,   260,     0,     0,   261,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   784,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,  1873,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   639,   207,     6,     0,   323,     0,     0,   276,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,   245,     0,     0,     0,     0,
       0,     0,     0,     0,   246,   247,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,     0,   252,     0,     0,     0,     0,     0,   253,
       0,     0,   254,     0,     0,   255,     0,   256,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
      56,    57,     0,   259,     0,   260,     0,     0,   261,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   946,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   263,   264,
       0,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     503,     0,     0,     0,     0,     0,   273,   207,   165,   382,
       0,   363,     0,     0,   208,   209,   210,     0,   276,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   419,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     240,   241,   242,   243,   392,   393,   394,   395,   244,     0,
       0,     0,   396,   397,   398,   399,     0,     0,     0,     0,
     400,     0,   401,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   251,    25,   402,   252,     0,   403,
     207,   165,   382,     0,     0,     0,     0,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   419,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   240,   241,   242,   243,   392,   393,   394,
     395,   244,     0,     0,     0,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   401,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,   402,
     252,     0,   403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   262,   404,
     405,   406,   263,     0,     0,     0,     0,   265,   266,   267,
     407,   268,   269,   270,   408,     0,   409,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   420,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   363,     0,     0,     0,  1602,
       0,     0,   276,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   947,     0,     0,     0,     0,
       0,   262,   404,   405,   406,   263,     0,     0,     0,     0,
     265,   266,   267,   407,   268,   269,   270,   408,     0,   409,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   420,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,   207,
     165,   382,  1887,     0,     0,   276,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   419,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,  1606,   384,   385,   386,   387,   388,   389,
     390,   391,   240,   241,   242,   243,   392,   393,   394,   395,
     244,     0,     0,     0,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   401,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   251,    25,   402,   252,
       0,   403,   207,   165,   382,     0,     0,     0,     0,   208,
     209,   210,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   419,   229,   230,   231,   232,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   240,   241,   242,   243,   392,
     393,   394,   395,   244,     0,     0,     0,   396,   397,   398,
     399,     0,     0,     0,     0,   400,     0,   401,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,   402,   252,     0,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     262,   404,   405,   406,   263,     0,     0,     0,     0,   265,
     266,   267,   407,   268,   269,   270,   408,     0,   409,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   420,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   363,     0,     0,
       0,  1769,     0,     0,   276,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   994,     0,     0,
       0,     0,     0,   262,   404,   405,   406,   263,     0,     0,
       0,     0,   265,   266,   267,   407,   268,   269,   270,   408,
       0,   409,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   420,
       0,     0,     0,     0,     0,   273,   207,   165,     0,     0,
     363,     0,     0,   208,   209,   210,     0,   276,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   419,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,   243,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
     207,   165,     0,   251,    25,     0,   252,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   419,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,   243,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,     0,
     252,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,   262,     0,     0,
       0,   263,     0,  1103,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   420,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   363,     0,     0,     0,   619,     0,
       0,   276,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,   262,     0,     0,  1104,   263,     0,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   637,   638,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   639,   207,
     165,     0,   323,     0,   873,   276,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   419,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,     0,     0,
       0,     0,     0,   207,   165,     0,   251,    25,     0,   252,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   419,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,     0,   252,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
     262,     0,     0,     0,   263,     0,  1105,     0,     0,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   420,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   363,     0,     0,
       0,     0,     0,     0,   276,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,   262,     0,     0,  1106,   263,     0,
       0,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     420,     0,     0,     0,     0,     0,   273,   207,   165,     0,
    1324,   363,  1092,     0,   208,   209,   210,     0,   276,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   419,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   251,    25,     0,   252,   207,   165,
       0,  1482,     0,     0,     0,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   419,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,   243,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,   262,     0,
       0,   595,   263,     0,     0,     0,   723,   265,   266,   267,
       0,   268,   269,   270,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   420,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   363,     0,     0,     0,     0,
       0,     0,   276,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1144,     0,     0,     0,   262,
       0,     0,     0,   263,     0,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   420,     0,     0,     0,     0,
       0,   273,   207,   165,     0,  1546,   363,     0,     0,   208,
     209,   210,     0,   276,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   419,   229,   230,   231,   232,   233,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,   243,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,     0,     0,     0,     0,     0,   207,   165,     0,   251,
      25,     0,   252,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   419,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,   243,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,     0,   252,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,   262,     0,     0,     0,   263,     0,  1154,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   420,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     363,     0,     0,     0,     0,     0,     0,   276,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,   262,     0,     0,
    1155,   263,     0,     0,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   420,     0,     0,     0,     0,     0,   273,
     207,   165,     0,     0,   363,  1600,     0,   208,   209,   210,
       0,   276,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   419,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,   243,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,   207,   165,     0,   251,    25,     0,
     252,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   419,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
     243,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,   262,     0,     0,     0,   263,     0,  1156,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   420,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,  1934,
       0,     0,     0,     0,     0,   276,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,   262,     0,     0,  1161,   263,
       0,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,   165,   382,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   420,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   363,     0,     0,     0,     0,     0,     0,   276,
       0,     0,     0,     0,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,     0,   392,   393,   394,
     395,     0,   165,   382,     0,   396,   397,   398,   399,     0,
       0,     0,     0,   400,     0,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   402,
       0,     0,   403,     0,     0,     0,   299,     0,     0,   300,
       0,     0,   301,     0,   302,   383,   384,   385,   386,   387,
     388,   389,   390,   391,     0,    46,     0,     0,   392,   393,
     394,   395,     0,     0,     0,     0,   396,   397,   398,   399,
       0,     0,   433,     0,   400,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     402,     0,     0,   403,     0,     0,     0,   299,     0,     0,
     300,     0,     0,   301,     0,   302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,     0,     0,     7,     8,     0,     0,
       0,     0,   404,   405,   406,     0,     0,     0,     0,     0,
       0,     0,     0,   407,     0,     0,     0,   408,     0,   409,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   745,
       0,   746,  1769,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   404,   405,   406,     0,     0,     0,     0,
       0,     0,     0,     0,   407,     0,     0,     0,   408,     0,
     409,   117,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,    43,    44,
      45,    46,     0,     0,    48,     0,     0,     7,     8,     0,
       0,   759,    55,  1769,     0,    58,   760,     0,   761,   762,
       0,   763,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,    79,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
       0,     0,     0,   759,    55,     0,     0,    58,   760,     0,
     761,   762,     0,   763,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    94,    95,    96,    43,
      44,    45,    46,     7,     8,    48,     0,     0,     0,     0,
       0,     0,   759,    55,     0,     0,    58,   760,     0,   761,
     762,     0,   763,     0,     0,     0,     0,     0,     0,  1026,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     7,     8,   595,     0,    94,    95,    96,     0,     0,
       0,  1028,     0,  1162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   759,    55,
       7,     8,    58,   760,     0,   761,   762,     0,   763,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1228,     0,     0,     0,     0,     0,    79,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,    94,    95,    96,     0,     0,   759,    55,     7,     8,
      58,   760,     0,   761,   762,     0,   763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,    43,    44,    45,    46,     0,     0,    48,    94,
      95,    96,     0,     0,     0,   759,    55,     7,     8,    58,
     760,     0,   761,   762,     0,   763,  1230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,    94,    95,
      96,     0,     0,   759,    55,     7,     8,    58,   760,     0,
     761,   762,     0,   763,  1231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    94,    95,    96,     0,
       0,     0,   759,    55,     7,     8,    58,   760,     0,   761,
     762,     0,   763,  1250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,    94,    95,    96,     0,     0,
     759,    55,     7,     8,    58,   760,     0,   761,   762,     0,
     763,  1268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,    94,    95,    96,     0,     0,     0,   759,
      55,     7,     8,    58,   760,     0,   761,   762,     0,   763,
    1283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     0,     0,
      48,     0,    94,    95,    96,     0,     0,   759,    55,     0,
       0,    58,   760,     0,   761,   762,     0,   763,  1316,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
      94,    95,    96,     0,     0,     0,   759,    55,     0,     0,
      58,   760,     0,   761,   762,     0,   763,  1474,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    79,    -4,    -4,     0,     0,     0,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,    94,
      95,    96,   595,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,  1164,     0,     0,  2116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,  2175,     0,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,
       0,    -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,
       0,     0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,
      10,    11,    -4,    -4,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,     0,    -4,     0,     0,     0,     0,
      12,    13,    14,     0,     0,     0,     0,    15,    16,     0,
       0,     0,    17,     0,     0,     0,     0,    18,    19,    20,
      21,    22,     0,    23,    24,     0,    25,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,    42,
      43,    44,    45,    46,    47,     0,    48,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,     0,    64,    65,    66,     0,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    89,    90,    91,     0,     0,     0,
      92,     0,     0,     0,     0,    93,    94,    95,    96,   165,
     382,    97,     0,    98,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,   113,   114,   115,     0,     7,
       8,     0,     0,     0,     0,     0,   116,     0,   117,     0,
       0,     0,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,   393,   394,   395,     0,
       0,     0,     0,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
     403,     0,     0,     0,   299,     0,     0,   300,     0,     0,
     301,     0,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
     433,    43,    44,    45,    46,     7,     8,    48,     0,     0,
       0,     0,     0,     0,   759,    55,     0,     0,    58,   760,
       0,   761,   762,     0,   763,     0,     0,     0,  1037,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,  1038,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
     404,   405,   406,     0,     0,     0,     0,     0,     0,     0,
       0,   407,     0,     0,     0,   408,     0,   409,   117,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     759,    55,     0,     0,    58,   760,     0,   761,   762,     0,
     763,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,    94,    95,    96,     0,     0,     0,     0,
       0,  1277,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1298,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1382,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1385,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1476,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1477,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1521,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1647,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1648,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1649,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1663,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1797,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1921,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1922,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1954,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1957,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2026,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2083,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2084,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2099,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2101,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2134,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2162,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2167,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2168,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2169,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2209,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,  1072,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  1131,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  1176,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  1177,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  1221,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,  1253,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,  1273,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,  1330,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
    1350,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  1431,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,  1432,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  1478,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  1552,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  1852,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  1863,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,  1901,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,  1976,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,  1991,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
    2003,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  2027,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,  2063,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  2072,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  2073,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  2097,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  2148,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,  2188,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,  2207,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,  2227,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
    2228,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  2229,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,   938,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,  1969,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
     745,     0,   746,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,  1000,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,  1048,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,  1200,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
    1267,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,  1269,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,  1275,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,  1276,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,  1364,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,  1378,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,  1581,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,  1669,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,  1721,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,  1913,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
    1959,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,  1977,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   800,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   801,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   802,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   804,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   805,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   806,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   808,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   809,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   810,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   811,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   812,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   813,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   814,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   816,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   817,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   818,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   885,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   920,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   968,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   988,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   990,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   991,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   992,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   998,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,   999,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1036,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1047,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1111,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1115,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1127,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1199,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1209,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1210,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1211,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1220,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1222,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1223,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1252,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1254,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1255,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1256,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1257,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1258,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1259,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1260,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1266,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1363,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1377,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1582,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1614,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1615,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1616,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1617,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1655,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1668,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1784,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1786,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1789,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1796,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1853,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1862,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  1886,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  1958,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  2024,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  2025,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,  2161,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,  2204,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595
};

static const yytype_int16 yycheck[] =
{
       3,  1247,   316,     3,  1251,   108,   727,   110,    68,    69,
     157,    71,   634,   635,    62,  1707,   740,     6,  1438,  1752,
       5,  1754,    25,     6,   748,    26,     4,    28,     4,     6,
       4,    25,   143,     4,     4,   756,     5,     4,    99,  1937,
     143,     5,     4,     4,     6,     4,     6,     5,     4,  1739,
     139,    54,   773,     7,   139,     0,   105,   118,     4,     6,
     254,     4,   783,     4,   239,   240,   260,   170,     4,     4,
     105,   328,   157,   160,   239,   240,     6,     9,     9,   128,
      83,   166,   167,   168,   105,   260,     7,   172,   173,    92,
     347,    14,     9,   128,    97,   260,     4,   239,   240,   186,
     189,     9,   139,   102,     6,   108,   105,   106,   107,   239,
     240,     9,   239,   240,  1804,   202,   203,   255,   260,   118,
     157,   259,   102,     9,     6,   105,   256,   107,   254,   166,
     167,   168,  1824,   260,   260,   172,   173,    99,   118,     6,
     143,   251,   143,   253,   144,   148,   149,   150,    91,   239,
     240,     6,   102,     6,   157,   105,   196,    99,     7,   416,
     102,   418,     6,   105,   204,   107,   887,     9,   118,   426,
     260,   256,   175,   108,   109,   251,   118,   144,   145,   146,
     147,   252,   181,   150,     6,   105,   257,   107,   191,   239,
     240,   174,   159,   196,  2092,   162,   199,   251,   246,   247,
     251,   204,   205,   206,   255,   176,   177,   178,   179,   251,
     260,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
    1660,   242,   243,     6,   174,   201,     4,   223,  1494,   223,
     251,   252,     4,   223,   197,   258,   296,   297,   298,   319,
     320,     7,   263,   264,   223,     7,   255,   327,   328,   272,
     255,     7,   275,   276,  1966,   253,     6,   255,   255,   255,
     223,   259,   276,   251,   258,   256,   255,   223,   291,   292,
     251,   255,   295,   296,   297,   298,   255,   255,   255,     7,
     340,   341,   342,   257,   251,   251,     3,   310,   255,     7,
     251,   314,   255,   316,     6,   223,   252,   357,   254,   251,
     251,   253,   253,  1047,  1048,   257,   257,   251,  2020,   432,
     251,   255,   253,     6,   251,   338,   253,   340,   341,   342,
     248,   249,   251,   251,   253,   253,   255,   255,     6,   257,
     248,   249,   252,   251,   357,   253,   254,   239,   240,   257,
     260,   364,   248,   249,    61,   251,   623,   253,   625,   626,
       6,   257,   239,   240,   253,   224,   225,   226,   227,   234,
     235,   253,   383,   384,   385,   642,   239,   240,   389,   390,
     391,   392,   393,   394,   395,  2128,   397,   251,   545,   248,
     249,   402,   403,   660,   139,   406,   248,   249,   257,   251,
     251,   253,   234,   235,   102,   257,   251,   105,   419,   107,
     423,   424,   157,   239,   240,   428,   429,   684,   186,   187,
     251,   166,   167,   168,   186,   187,   256,   172,   173,   251,
     260,   444,   239,   240,   260,   251,   143,   253,   451,   239,
     240,   148,   149,   150,   260,   239,   240,   251,   561,   252,
     157,   251,  1183,   260,  1185,   255,   723,   260,   244,   245,
       4,   474,  2164,   251,   250,    54,   260,  1198,   224,   225,
     226,   227,   224,   225,   226,   227,   248,   249,   224,   225,
     226,   227,    99,    99,   191,   102,   102,   252,   105,   105,
     503,   107,   248,   249,   251,   260,   248,   249,   251,   206,
     253,   118,   248,   249,   251,   555,   224,   225,   226,   227,
     251,   256,   239,   240,   527,  2217,   224,   225,   226,   227,
     256,   534,   535,   256,   260,  1955,   539,   260,   541,   542,
     543,   544,   545,   260,   257,   692,   259,   550,   245,   239,
     240,   554,   555,   556,   557,   558,   559,   560,   251,   562,
     253,   564,   255,   260,   261,    99,   560,     8,   562,   103,
     260,   572,   632,   633,   252,   109,   110,   637,   112,   113,
     239,   240,   260,   239,   240,   139,   252,   590,   239,   240,
    1311,   248,   249,   596,   260,   255,  1317,   252,   132,   254,
     257,   260,   705,   157,   260,   260,   239,   240,   251,   260,
     239,   240,   166,   167,   168,   618,   619,   252,   172,   173,
     139,   239,   240,   239,   240,   260,   205,   260,   251,   740,
     102,   260,   252,   105,   634,   635,   239,   240,   157,  1261,
     260,  1362,   260,   251,   260,   239,   240,   166,   167,   168,
     239,   240,   256,   172,   173,  1376,   260,   260,   251,   239,
     240,   252,  1383,   666,   667,   668,   260,   257,   671,   260,
     260,   260,   239,   240,   241,   242,   243,   244,   245,   258,
     260,   251,   256,   250,   120,   942,   260,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   799,   700,   701,   702,
     703,   704,   256,   706,   707,   708,   709,   710,   239,   240,
     713,   239,   240,   105,   762,   709,   295,   239,   240,     6,
     251,   724,   239,   240,   255,   255,   423,   255,   252,   107,
     254,   310,   252,   255,   737,   314,   433,   256,   255,   251,
     260,  1465,     6,     7,   747,   241,   242,   243,   244,   245,
     753,   251,   256,   253,   250,   256,   260,   257,   455,   260,
     260,   252,   252,   254,   254,   251,   769,   770,   255,   260,
     260,   252,   775,   254,   777,   248,   249,   780,   781,   260,
     105,   256,   255,   251,   787,   260,   789,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   916,   252,   255,   254,   250,
     248,   249,   144,   145,   260,   256,   256,   255,   150,   822,
     260,   824,   144,   145,   251,   256,   256,   930,   150,   260,
     260,  1555,   256,   256,   256,   256,   260,   260,   260,   260,
     102,   256,   539,  1567,   541,   260,   543,   544,   545,   428,
     429,   256,   256,   256,   857,   260,   260,   260,   256,   256,
     557,   558,   260,   260,   867,   444,   105,   256,   256,   256,
    2117,   260,   260,   260,   256,   256,   256,   256,   260,   260,
     260,   260,   883,   256,   256,   945,   256,   260,   260,   256,
     260,   256,   952,   260,   256,   260,   956,   256,   260,   256,
     255,   260,   905,   260,  2150,   256,     8,   256,   256,   260,
     256,   260,   260,   256,   260,   918,   917,   260,   256,   256,
     102,   256,   260,   260,   927,   260,   256,   256,   256,  2176,
     260,   260,   260,     6,     7,   938,  1047,  1048,   256,   102,
     256,   256,   260,   640,   260,   260,  1049,     8,  2194,   255,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   542,   256,   256,   663,   250,   260,   260,
     256,   251,   256,   253,   260,   554,   260,   556,   256,   256,
     256,   256,   260,   260,   260,   260,   252,     8,   254,   255,
     251,   105,   253,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   255,   700,   701,   702,   703,   239,   240,   706,
     707,   708,   252,   105,   254,   255,   251,     4,   253,   716,
       4,   251,   719,   253,     4,     4,     6,     4,   251,  1343,
     251,   251,   251,   251,   731,     6,     6,   253,   251,  1042,
     255,   253,     6,     6,   255,   259,   251,     9,  1108,   259,
    1053,   251,   251,   251,   251,  1058,   251,   251,   251,   255,
     251,   251,   189,   189,   761,   189,   763,   255,  1071,   128,
    1692,  1693,   251,  1076,   251,   251,   251,   189,   251,   251,
     251,   255,   251,   780,     4,   255,   253,   255,  1199,  1200,
     255,   255,   789,   255,   251,  1096,   251,   251,   251,   251,
     251,   251,   251,     6,     6,     6,  1109,  1110,   255,  1112,
    1113,  1114,   255,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,   255,   255,  1128,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   255,   253,   253,   253,   250,     6,
       6,   255,   189,   251,   256,   251,   251,   251,   737,     6,
     251,   251,     6,  1166,  1167,  1168,   253,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   255,     6,  1190,     6,   250,
    1191,   252,     8,   254,     8,   255,     7,     6,   255,   255,
       6,   255,    94,  1206,  1207,  1208,   256,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   260,   260,   252,     7,   250,
     143,   252,     6,     6,   252,   148,   149,   150,   255,   255,
     255,   255,   250,    65,   941,   257,   943,   944,  1562,     8,
       4,     7,  1363,  1364,     7,   251,     6,   252,     6,  1262,
     957,  1261,   255,     7,     6,   256,     7,     6,     6,   186,
     255,     4,     5,   256,   256,  1278,  1279,  1280,   191,   976,
     254,     6,   255,  1386,   252,  1388,  1289,     7,  1545,     6,
     257,  1294,  1549,   206,   253,  1298,   251,   255,   995,     4,
       6,   252,     6,     6,  1307,     6,  1309,     6,   253,  1312,
       7,     7,     7,     7,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     7,  1327,     7,     7,    60,    61,    62,
      63,     7,     7,     7,  1031,    68,    69,    70,    71,     7,
    1343,     7,     7,    76,     7,    78,  1347,  1348,   927,     7,
    1972,     7,     6,   252,   260,   255,   254,   252,     7,    92,
       7,  1364,    95,   260,   260,   256,  1369,   260,  1371,   255,
     257,   256,   255,   255,     4,     6,   257,   256,   256,  1076,
     255,   139,     7,     6,   257,  1388,     7,     7,     7,   252,
     252,   260,   260,     9,   260,   254,   257,   252,  1401,   259,
     189,     7,  1405,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,  1568,  1569,   160,   256,   250,   255,   252,     6,   254,
       6,     6,     4,  1493,    47,   260,    47,  1438,  1541,   251,
     257,   251,   255,     4,  1555,     7,   251,  1448,   255,   257,
     251,     7,  1766,   257,     7,   189,  1459,  1460,  1461,   252,
     260,     7,     7,  1042,  1467,  1468,  1469,     7,     6,   252,
    1167,  1168,   205,   206,   207,   260,     7,     7,     7,  1058,
       7,  1484,     7,   216,     4,   117,     4,   220,   255,   222,
     223,     6,  1495,     7,   251,     6,   105,     7,     7,  1602,
    1503,     7,     7,     7,  1507,     7,     7,     6,   255,     6,
     423,     6,     4,     7,     7,     6,     6,     4,   258,     7,
     252,     6,     6,     6,   260,   260,   255,   255,   255,     6,
    1109,  1110,  1229,  1112,  1113,  1114,     6,  1116,  1117,  1118,
    1119,  1120,  1121,  1122,  1123,  1124,  1125,   256,   255,     6,
       6,   253,     6,   251,     6,     6,  1667,   257,   251,  1562,
    1620,     6,   132,   254,   256,  1568,  1569,     6,     6,     6,
     260,  1574,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,   252,   252,     6,  1688,     4,  1166,   255,  1592,
       6,     4,     6,   255,   255,     7,   255,  1294,   255,  1602,
     253,  1298,     6,     6,  1607,  1606,   256,   255,     6,   255,
    1307,  1190,  1309,   255,   255,  1312,   255,   255,   255,     6,
       6,   185,  1769,     6,  1321,     6,   539,  1206,   541,  1732,
     543,   544,     6,   260,   260,   252,  1739,  1740,   260,     6,
     255,     7,   260,   257,   557,   558,   251,   255,  1708,  1709,
    1710,  1711,  1712,  1713,     4,  1758,   256,     6,     6,     6,
       6,   251,     4,   251,     7,     6,     6,  1364,     6,     6,
       6,  1782,     6,     6,   139,     6,  1679,     5,   103,   252,
     260,  1684,  1685,  1262,   255,     6,   255,   255,     6,   139,
     139,     6,  1692,  1693,   260,  2009,     6,     6,     6,  1278,
    1279,  1280,   260,   252,  1707,   260,     6,     4,     6,   260,
    1713,     6,   255,     6,     6,     6,     6,     6,   255,     7,
     143,  1724,     6,   255,  1981,     5,     7,   255,   252,   255,
       6,  1734,     6,   255,  1737,     6,   255,     6,     6,   256,
     256,   184,   255,     6,   252,     6,   187,     7,  1327,   256,
       6,     6,  1755,   256,     6,     6,   256,   255,     6,  1762,
       6,   257,     6,  1766,     6,  1768,  1769,   256,     6,   255,
     252,     6,     6,   251,   255,     6,   256,   256,   691,   255,
     693,   694,   695,   696,   697,   698,   252,   700,   701,   702,
     703,   255,   255,   706,   707,   708,   255,  1900,     6,     6,
     139,  1804,     6,   256,     6,     6,   252,   255,   255,  1388,
       6,     6,     6,     6,   256,     6,   256,     6,     6,     6,
    2077,  1824,  1401,     6,     6,     6,  1405,     6,     6,     6,
       6,     6,     6,  1836,  1837,   255,   255,     6,   255,  1375,
    1943,  2130,   471,  1612,  1938,  1433,  1898,  1675,  1400,     3,
       3,     6,     3,     3,  1968,  1538,   611,     3,  1861,  1762,
    1569,  2118,  1739,    -1,   780,    -1,    -1,   780,    -1,    -1,
    1873,  1568,  1569,    -1,    -1,    -1,   789,    -1,    -1,    -1,
    1459,  1460,  1461,    -1,  1887,    -1,    -1,    -1,  1467,  1468,
    1469,    -1,    -1,    -1,    -1,  1592,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1495,    -1,    -1,    -1,
      -1,  1924,    -1,    -1,  1503,  1985,  1986,  1987,  1988,  1989,
      -1,    -1,    -1,    -1,    -1,    -1,  1939,    -1,    -1,    -1,
      -1,  1944,    -1,    -1,  1947,  1948,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1966,    -1,    -1,  1969,    -1,    -1,    -1,
      -1,    -1,  1972,    -1,    -1,    -1,    -1,  1980,    -1,    -1,
      -1,  1984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2049,
    2093,    -1,    -1,  2053,    -1,  1574,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,  2009,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,  2020,    68,    69,
      70,    71,    -1,  1602,    -1,    -1,    76,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,
    1737,    -1,    92,    -1,  2104,    95,    -1,  2050,  2108,    -1,
      -1,    -1,    -1,    -1,    -1,  1752,    -1,  1754,    -1,    -1,
      -1,     6,    -1,    -1,  2124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1769,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     6,    -1,    -1,    -1,   250,    -1,    -1,    -1,  2102,
    1679,    -1,    -1,    -1,    -1,    -1,    -1,  1804,    -1,    -1,
      -1,  2171,  2172,    -1,    -1,    -1,    -1,  2120,  2121,  2122,
    2123,  2124,    -1,    -1,    -1,    -1,    -1,    -1,  1707,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,  1724,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,   205,   206,   207,    -1,    -1,
      -1,  2164,    -1,  1076,    -1,    -1,   216,    -1,    -1,    -1,
     220,    -1,   222,    -1,    -1,    -1,  1755,    -1,  2181,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1768,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
    2203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2217,    -1,    -1,    -1,    -1,    -1,
      -1,  2224,  2225,   143,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,   152,    -1,    -1,  2238,    -1,    -1,    -1,    -1,
     160,    -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,  1167,  1168,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,   185,   186,   187,   188,   189,
     190,    -1,   192,   193,   194,   195,    -1,    -1,    -1,   199,
      -1,    -1,  1861,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,    -1,    -1,
      -1,   271,   272,   273,   274,   275,    -1,    -1,    -1,    -1,
    1939,    -1,    -1,    -1,    -1,  2062,    -1,    -1,    -1,    -1,
     290,   291,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1294,    -1,    -1,    -1,  1298,    -1,  1966,    -1,    -1,
      -1,    -1,   312,    -1,  1307,    -1,  1309,    -1,    -1,  1312,
      -1,  1980,   322,   323,    -1,    -1,    -1,    -1,   328,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,   339,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2020,    -1,   363,   364,    -1,    -1,    -1,   368,   369,
     370,  1364,   372,    -1,  2151,    -1,   376,   377,   378,    -1,
      -1,   381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2050,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     420,    -1,    -1,    -1,   424,   425,  2203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   441,   442,    -1,    -1,    -1,    -1,  2224,  2225,    -1,
      -1,    -1,    -1,     6,    -1,    -1,   456,    -1,    -1,    -1,
      -1,  2238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   476,   477,   478,   479,
      -1,    -1,    -1,    -1,   484,    -1,    -1,    -1,   488,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   502,   503,    -1,  2164,    -1,   507,    -1,    -1,
      -1,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,    -1,   537,   538,    -1,
     540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,
      -1,    -1,   552,   553,    -1,    -1,    -1,    -1,  2217,   559,
      -1,    -1,    -1,    -1,   564,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,    -1,   597,   598,  1592,
      -1,    -1,    -1,    -1,    -1,   605,   606,   607,    -1,    -1,
      -1,    -1,    -1,   613,   614,   615,   616,     6,   618,   619,
      -1,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,   637,   638,   639,
     250,    -1,    -1,   643,   644,   645,   646,   647,   648,   649,
     650,   651,    -1,    -1,    -1,    -1,    -1,   657,    -1,   659,
      -1,    -1,   662,    -1,    -1,    -1,   666,   667,   668,   669,
     199,   671,   672,   673,   674,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   699,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,
     720,    -1,   722,    -1,    -1,   725,   726,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,    -1,    -1,
      -1,  1734,    -1,   272,  1737,    -1,   275,   747,    -1,   749,
      -1,    -1,    -1,    -1,   754,   755,    -1,    -1,    -1,    -1,
      -1,    -1,   291,   292,    -1,    -1,    -1,    -1,    -1,   769,
      -1,   771,   772,    -1,    -1,   775,    -1,   777,   778,    -1,
      -1,    -1,   782,    -1,   784,    -1,    -1,    -1,    13,    14,
     790,    -1,    -1,    -1,   794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     820,    -1,   822,    -1,   824,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   857,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   867,   868,   869,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,   199,
     115,   116,   117,   118,    -1,   424,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   905,    -1,   132,   133,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,    -1,   918,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   926,    -1,    -1,    -1,
     930,   156,    -1,    -1,    -1,    -1,    -1,    -1,   938,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   946,   947,    -1,    -1,
      -1,    -1,   952,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,
      -1,    -1,   972,    -1,   503,    -1,    -1,    -1,    -1,    -1,
      -1,   291,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   994,    -1,   996,   997,   527,    -1,
      -1,    -1,    -1,    -1,    -1,   534,   535,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1015,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
     559,   256,    -1,    -1,     6,   564,     5,    -1,  1038,    -1,
      -1,    -1,    -1,    -1,    -1,  1045,    -1,    -1,    -1,    -1,
    1050,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   590,    -1,    -1,    -1,  1065,  1066,    -1,    -1,    -1,
      -1,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,   618,
     619,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,  1103,  1104,  1105,  1106,    76,    -1,    78,
      -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    -1,  1128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   666,   667,   668,
      -1,    -1,   671,    -1,  1144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1154,  1155,  1156,    -1,    -1,    -1,
      -1,  1161,  1162,    -1,  1164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,  1179,
      -1,    -1,    -1,    -1,   713,    -1,  1186,  1187,     6,    -1,
      -1,    -1,    -1,  1193,    -1,  1195,  1196,    -1,    -1,    -1,
      -1,    -1,  1202,  1203,    -1,    -1,    -1,  1207,  1208,    -1,
    2203,    -1,    -1,    -1,    -1,    -1,     6,    -1,   747,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2224,  2225,    -1,    -1,    -1,   205,   206,   207,    -1,
     769,  1241,    -1,    -1,    -1,  2238,   775,   216,   777,    -1,
      -1,   220,    -1,   222,   564,    -1,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,  1277,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1289,
      -1,    -1,    -1,   822,    -1,   824,    -1,  1297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   618,   619,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1318,  1319,
      -1,    -1,    -1,  1323,    -1,    -1,    -1,    -1,   857,    -1,
      -1,    -1,    -1,    -1,  1334,    -1,    -1,  1337,   867,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,   666,   667,   668,    -1,
      -1,   671,    -1,    -1,    -1,  1365,    -1,    -1,  1368,  1369,
    1370,  1371,    -1,    -1,    -1,    -1,   905,    -1,    -1,  1379,
      -1,    -1,  1382,    -1,  1384,  1385,  1386,     6,    -1,   918,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,   938,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   747,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,   769,
     250,    -1,    -1,    -1,    -1,   775,  1466,   777,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1475,  1476,  1477,    -1,    -1,
      -1,    -1,    -1,    -1,  1484,    -1,  1486,    -1,    -1,    -1,
      -1,    -1,    -1,  1493,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1507,    -1,    -1,
      -1,    -1,  1512,  1513,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1521,  1522,  1523,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1533,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1071,  1543,    -1,    -1,    -1,   857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   867,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1566,    -1,    -1,    -1,
      -1,    -1,  1572,  1573,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,   905,   250,    -1,    -1,  1128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1607,   918,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,   938,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1647,  1648,  1649,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1658,    -1,
      -1,    -1,    -1,  1663,  1664,  1665,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1677,  1207,  1208,
       6,    -1,    -1,    -1,  1684,  1685,  1686,    -1,  1688,    -1,
      -1,    -1,    -1,    -1,  1694,  1695,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1713,    -1,    -1,    -1,    -1,  1718,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1732,    -1,    -1,  1735,    -1,    -1,    -1,  1739,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1748,  1749,
      -1,  1751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1759,
    1289,  1071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1775,    -1,    -1,    -1,    -1,
    1780,  1781,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1794,    -1,    -1,  1797,  1798,    -1,
    1800,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1836,  1837,    -1,    -1,
    1369,    -1,  1371,  1843,  1844,    -1,   446,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1864,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1873,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1883,  1884,    -1,    -1,  1887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1207,  1208,    -1,
      -1,    -1,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,  1921,  1922,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1942,    -1,    -1,    -1,    -1,  1947,  1948,  1949,
     550,    -1,    -1,    -1,  1954,    -1,    -1,  1957,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1969,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1507,  1289,
      -1,    -1,    -1,    -1,  1984,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2017,    -1,    -1,
      -1,    -1,    -1,  2023,    -1,    -1,  2026,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,  2058,  1369,
      -1,  1371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,
      -1,    -1,    -1,  2083,  2084,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2098,  2099,
      -1,  2101,  2102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2115,    -1,    -1,    -1,    -1,
    2120,  2121,  2122,  2123,  2124,    -1,    -1,    -1,    -1,    -1,
    2130,    -1,    -1,    -1,  2134,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,  1684,  1685,   115,   116,   117,
     118,    -1,  2162,   121,    -1,    -1,    -1,  2167,  2168,  2169,
     128,   129,    -1,    -1,   132,   133,    -1,   135,   136,    -1,
     138,  2181,    -1,    -1,  1713,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1507,   156,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2209,
    2210,  2211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
      -1,   841,   842,   843,   844,    -1,   846,   847,   848,   849,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     860,    -1,   862,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,   872,    -1,    -1,    -1,    -1,    -1,    -1,   879,
     880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,  1836,  1837,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,     8,    -1,    -1,    -1,    76,    -1,
      78,    -1,    -1,    -1,  1873,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    95,  1887,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,  1684,  1685,    -1,    -1,    -1,    -1,
     118,    -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,  1001,  1002,  1003,    -1,    -1,    -1,  1007,  1008,    -1,
      -1,  1011,  1012,  1013,  1014,    -1,  1016,    -1,  1947,  1948,
      -1,  1021,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
    1969,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1984,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,    -1,   220,    -1,   222,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1102,    -1,    -1,    -1,    -1,  1107,    -1,    -1,
     248,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,  1836,  1837,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,  2102,    -1,    -1,   250,  1887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2120,  2121,  2122,  2123,  2124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1204,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1947,  1948,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2181,    -1,    -1,    -1,    -1,    -1,    -1,  1969,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,  1984,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     6,    -1,    -1,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,  1346,    -1,    -1,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1387,    -1,    -1,
      -1,    -1,  2102,    -1,    -1,   135,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2120,  2121,  2122,  2123,  2124,    -1,    -1,    -1,    -1,  1419,
    1420,  1421,  1422,  1423,    -1,    -1,    -1,    -1,  1428,  1429,
      -1,    -1,    -1,    -1,  1434,    -1,  1436,    -1,    -1,    -1,
    1440,    -1,    -1,  1443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1455,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,
      -1,  2181,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,   222,   223,   224,   225,   226,   227,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,   248,   249,
      -1,   251,    -1,   253,     6,    -1,    -1,   257,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1529,
      -1,  1531,    -1,    -1,    -1,  1535,    -1,  1537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,  1568,   250,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    69,    70,    71,    -1,    -1,    74,    75,    76,    -1,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    92,    93,  1666,    95,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,   130,   131,    -1,   133,    -1,   135,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,   162,    -1,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,  1774,    -1,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,     6,   222,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,   251,    -1,  1825,  1826,   255,  1828,    -1,
     258,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     3,
       4,     5,    -1,   250,    -1,    -1,    10,    11,    12,   256,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,  1891,  1892,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    69,    70,    71,    -1,    -1,
      74,    75,    76,    -1,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
    1940,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,   130,   131,    -1,   133,
      -1,   135,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,   222,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,     4,
       5,   255,    -1,    -1,   258,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,    -1,
    2190,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,   130,   131,    -1,   133,    -1,
     135,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,   159,    -1,    -1,   162,    -1,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,     3,     4,    -1,
     255,    -1,     8,   258,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,   130,   131,    -1,   133,    -1,   135,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,   162,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,   209,    -1,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,   251,     3,     4,     5,    -1,
     256,    -1,   258,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,   130,   131,    -1,   133,    -1,   135,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,   150,   151,   152,   153,   154,   155,    -1,
      -1,    -1,   159,    -1,    -1,   162,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,   251,     3,     4,    -1,   255,    -1,
      -1,   258,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,   130,   131,    -1,   133,    -1,   135,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,   162,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,   251,     3,     4,    -1,   255,   256,    -1,
     258,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,   130,   131,    -1,   133,    -1,   135,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
     159,    -1,    -1,   162,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,   251,     3,     4,    -1,   255,    -1,    -1,   258,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
     130,   131,    -1,   133,    -1,   135,    -1,    -1,   138,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,   251,     3,     4,    -1,   255,    -1,    -1,   258,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,
     131,    -1,   133,    -1,   135,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,   159,    -1,
      -1,   162,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   209,    -1,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,
      -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
     251,     3,     4,    -1,   255,    -1,    -1,   258,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,   139,    -1,    -1,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,   131,
      -1,   133,    -1,   135,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,    -1,    -1,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,
       3,     4,    -1,    -1,   256,    -1,   258,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    -1,   130,   131,    -1,
     133,    -1,   135,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,
       4,    -1,   255,    -1,    -1,   258,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
     114,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,   130,   131,    -1,   133,
      -1,   135,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,   150,   151,   152,   153,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,     4,
      -1,   255,    -1,    -1,   258,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,   130,   131,    -1,   133,    -1,
     135,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,   150,   151,   152,   153,   154,
     155,    -1,    -1,    -1,   159,    -1,    -1,   162,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,     3,     4,    -1,
     255,    -1,     8,   258,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,   130,   131,    -1,   133,    -1,   135,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,   162,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,   209,    -1,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,     3,     4,    -1,    -1,   251,     8,    -1,    10,    11,
      12,    -1,   258,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   130,   131,
      -1,   133,    -1,   135,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,   150,   151,
     152,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,
      -1,    -1,    -1,    -1,   246,     3,     4,    -1,    -1,   251,
      -1,    -1,    10,    11,    12,    -1,   258,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,   130,   131,    -1,   133,    -1,   135,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,   162,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,
     208,   209,    -1,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,   251,     3,     4,    -1,   255,    -1,    -1,
     258,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,   130,   131,    -1,   133,    -1,   135,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
     159,    -1,    -1,   162,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,   251,     3,     4,    -1,   255,    -1,    -1,   258,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    -1,    -1,    -1,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
     130,   131,    -1,   133,    -1,   135,    -1,    -1,   138,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   209,
      -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,     3,     4,     5,
      -1,   251,    -1,    -1,    10,    11,    12,    -1,   258,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      76,    -1,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,    95,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,
      93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,    -1,    -1,    -1,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   222,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,   255,
      -1,    -1,   258,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,   204,   205,   206,   207,   208,    -1,    -1,    -1,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,
       4,     5,   255,    -1,    -1,   258,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    76,    -1,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      -1,    95,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,   222,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,   255,    -1,    -1,   258,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,    -1,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,   222,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,
      -1,    -1,    -1,    -1,    -1,   246,     3,     4,    -1,    -1,
     251,    -1,    -1,    10,    11,    12,    -1,   258,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    90,    91,    -1,    93,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,
      93,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,    -1,   260,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,   255,    -1,
      -1,   258,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,   260,   208,    -1,    -1,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,
       4,    -1,   255,    -1,     8,   258,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    90,    91,    -1,    93,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    93,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
     204,    -1,    -1,    -1,   208,    -1,   260,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,   258,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,   260,   208,    -1,
      -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,     3,     4,    -1,
       6,   251,   252,    -1,    10,    11,    12,    -1,   258,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    93,     3,     4,
      -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,   204,    -1,
      -1,   250,   208,    -1,    -1,    -1,   255,   213,   214,   215,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,   258,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,   204,
      -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,     3,     4,    -1,     6,   251,    -1,    -1,    10,
      11,    12,    -1,   258,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    90,
      91,    -1,    93,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    93,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,   260,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,
      -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,   258,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
     260,   208,    -1,    -1,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
       3,     4,    -1,    -1,   251,   252,    -1,    10,    11,    12,
      -1,   258,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,    90,    91,    -1,
      93,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    93,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,    -1,   260,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,    -1,    -1,   258,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,   260,   208,
      -1,    -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,     4,     5,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,     4,     5,    -1,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,   102,
      -1,    -1,   105,    -1,   107,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,   118,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    69,    70,    71,
      -1,    -1,   135,    -1,    76,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,    99,    -1,    -1,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,   220,    -1,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   207,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   220,    -1,
     222,   223,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,    -1,    -1,    -1,   115,   116,
     117,   118,    -1,    -1,   121,    -1,    -1,    13,    14,    -1,
      -1,   128,   129,   255,    -1,   132,   133,    -1,   135,   136,
      -1,   138,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,   156,
     115,   116,   117,   118,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,    -1,    -1,   132,   133,    -1,
     135,   136,    -1,   138,   181,   182,   183,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   181,   182,   183,   115,
     116,   117,   118,    13,    14,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,   132,   133,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    13,    14,   250,    -1,   181,   182,   183,    -1,    -1,
      -1,   256,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,   115,   116,   117,   118,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
      13,    14,   132,   133,    -1,   135,   136,    -1,   138,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,   156,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,   115,   116,   117,   118,    -1,    -1,   121,
      -1,   181,   182,   183,    -1,    -1,   128,   129,    13,    14,
     132,   133,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
      -1,    -1,   115,   116,   117,   118,    -1,    -1,   121,   181,
     182,   183,    -1,    -1,    -1,   128,   129,    13,    14,   132,
     133,    -1,   135,   136,    -1,   138,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
     115,   116,   117,   118,    -1,    -1,   121,    -1,   181,   182,
     183,    -1,    -1,   128,   129,    13,    14,   132,   133,    -1,
     135,   136,    -1,   138,   256,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,   115,
     116,   117,   118,    -1,    -1,   121,   181,   182,   183,    -1,
      -1,    -1,   128,   129,    13,    14,   132,   133,    -1,   135,
     136,    -1,   138,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,   115,   116,   117,
     118,    -1,    -1,   121,    -1,   181,   182,   183,    -1,    -1,
     128,   129,    13,    14,   132,   133,    -1,   135,   136,    -1,
     138,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    -1,    -1,    -1,   115,   116,   117,   118,
      -1,    -1,   121,   181,   182,   183,    -1,    -1,    -1,   128,
     129,    13,    14,   132,   133,    -1,   135,   136,    -1,   138,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    -1,    -1,    -1,   115,   116,   117,   118,    -1,    -1,
     121,    -1,   181,   182,   183,    -1,    -1,   128,   129,    -1,
      -1,   132,   133,    -1,   135,   136,    -1,   138,   256,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,   115,   116,   117,   118,    -1,    -1,   121,
     181,   182,   183,    -1,    -1,    -1,   128,   129,    -1,    -1,
     132,   133,    -1,   135,   136,    -1,   138,   256,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    13,    14,    -1,    -1,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,   181,
     182,   183,   250,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,   260,    -1,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,
      88,    89,    -1,    91,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   256,    -1,   114,   115,   116,   117,
     118,   119,    -1,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      -1,    -1,   140,   141,   142,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,     4,
      -1,   169,   170,   171,    -1,    -1,    -1,   175,    13,    14,
      -1,    -1,   180,   181,   182,   183,    -1,    -1,   186,    -1,
     188,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    -1,    -1,    -1,    44,
      45,    46,   210,   211,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,    -1,   223,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,   114,
     115,   116,   117,   118,   119,    -1,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,    -1,    -1,   140,   141,   142,    -1,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,    -1,
     175,    -1,    -1,    -1,    -1,   180,   181,   182,   183,     4,
       5,   186,    -1,   188,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   211,   212,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,   221,    -1,   223,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
     135,   115,   116,   117,   118,    13,    14,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,   132,   133,
      -1,   135,   136,    -1,   138,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
     205,   206,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,    -1,    -1,    -1,   220,    -1,   222,   223,    -1,
      -1,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,   115,   116,   117,
     118,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,    -1,    -1,   132,   133,    -1,   135,   136,    -1,
     138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,   181,   182,   183,    -1,    -1,    -1,    -1,
      -1,   260,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   260,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,   256,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,   256,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,   256,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,   256,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,   256,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,   256,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     256,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,   256,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,   256,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,   256,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,   256,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,   256,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,   256,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     256,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,   256,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,   256,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,    -1,    -1,   256,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,    -1,    -1,   256,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,    -1,    -1,   256,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,   256,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,   256,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     256,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,   256,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,   255,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,    -1,   255,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
     252,    -1,   254,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,   254,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,   254,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,   254,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
     254,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,   254,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,   254,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,   254,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,   254,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,   254,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,   254,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,   254,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,   254,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    -1,   254,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
     254,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,   254,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,   252,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   262,   263,     6,     0,     4,    13,    14,    44,
      45,    46,    65,    66,    67,    72,    73,    77,    82,    83,
      84,    85,    86,    88,    89,    91,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   114,   115,   116,   117,   118,   119,   121,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   140,   141,   142,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   169,
     170,   171,   175,   180,   181,   182,   183,   186,   188,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   210,   211,   212,   221,   223,   264,   266,
     267,   287,   306,   308,   312,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   330,   332,   333,   339,   340,   341,
     342,   348,   373,   374,   255,   259,    14,   105,   251,   251,
     251,     6,   255,     6,     6,     6,     6,   251,     6,     6,
     255,     6,     6,   253,   253,     4,   350,   374,   251,   253,
     285,    99,   102,   105,   107,   285,   251,   251,   251,     4,
     251,   251,   251,     4,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   255,   120,   105,     6,   255,
      99,   102,   105,   118,   311,   107,   251,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      56,    57,    58,    59,    64,    65,    74,    75,    79,    80,
      81,    90,    93,    99,   102,   105,   107,   118,   128,   133,
     135,   138,   204,   208,   209,   213,   214,   215,   217,   218,
     219,   239,   240,   246,   251,   255,   258,   308,   309,   312,
     323,   330,   332,   343,   344,   348,   350,   357,   359,   374,
     251,   255,   255,   105,   105,   128,   102,   105,   107,    99,
     102,   105,   107,   308,   102,   105,   106,   107,   118,   181,
     309,   102,   105,   251,   102,   160,   186,   202,   203,   255,
     239,   240,   251,   255,   354,   355,   354,   255,   255,   354,
       4,    99,   103,   109,   110,   112,   113,   132,   255,   251,
     105,   107,   105,   102,     4,    91,   197,   255,   374,     4,
       6,    99,   102,   105,   102,   105,   118,   310,   105,     4,
       4,     4,     5,   251,   255,   357,   358,     4,   251,   251,
     251,     4,   255,   361,   374,     4,   251,   251,   251,     6,
       6,   253,     5,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    60,    61,    62,    63,    68,    69,    70,    71,
      76,    78,    92,    95,   205,   206,   207,   216,   220,   222,
     365,   374,   251,     4,   365,     5,   255,     5,   255,    32,
     240,   343,   374,   253,   255,   251,   255,     6,   251,   255,
       6,   259,     7,   135,   197,   224,   225,   226,   227,   248,
     249,   251,   253,   257,   283,   284,   285,   308,   343,   364,
     365,   374,     4,   312,   313,   314,   255,     6,   343,   364,
     365,   374,   364,   364,   343,   364,   371,   372,   374,   343,
     289,   293,   251,   353,     9,   365,   251,   251,   251,   251,
     374,   343,   343,   343,   251,   343,   343,   343,   251,   343,
     343,   343,   343,   343,   343,   343,   364,   343,   343,   343,
     343,   358,   251,   240,   343,   359,   360,   255,   358,   357,
     364,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   251,   253,   285,   285,   285,   285,
     285,   285,   251,   285,   285,   251,   308,   309,   309,   285,
     285,     5,   255,   255,   128,   308,   308,   251,   285,   285,
     251,   251,   251,   343,   255,   343,   359,   343,   343,   256,
     360,   350,   374,   189,     5,   255,     8,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   250,     9,   251,   253,   257,
     284,   285,   343,   360,   360,   251,   251,   251,   357,   358,
     358,   358,   307,   251,   255,   251,   251,   357,   255,   255,
     343,     4,   357,   255,   361,   255,   255,   354,   354,   354,
     343,   343,   239,   240,   255,   255,   354,   239,   240,   251,
     314,   354,   255,   251,   255,   251,   251,   251,   251,   251,
     251,   251,   360,   343,   358,   358,   358,   251,     4,   253,
     255,     6,   253,   314,     6,     6,   255,   255,   255,   255,
     358,   255,   253,   253,   253,   343,     8,     6,     6,   343,
     343,   343,   257,   343,   255,   189,   343,   343,   343,   343,
     285,   285,   285,   251,   251,   251,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   251,   251,   285,   251,
     253,     6,     6,   255,     6,     8,   314,     6,     8,   314,
     285,   343,   241,   255,     9,   251,   253,   257,   364,   360,
     343,   314,   357,   357,   255,   365,   308,     7,   343,   343,
       4,   186,   187,   357,     6,   252,   254,   255,   286,   255,
       6,   255,     6,     9,   251,   253,   257,   374,   256,   128,
     133,   135,   136,   138,   306,   308,   343,     6,   252,   260,
       9,   251,   253,   257,   252,   260,   252,   260,   260,   252,
     260,     9,   251,   257,   260,   254,   260,   288,   254,   288,
      94,   352,   349,   374,   260,   343,   343,   343,   343,   260,
     252,   252,   252,   343,   252,   252,   252,   343,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   256,
       7,   343,   241,   256,   260,   343,     6,     6,   252,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   359,   343,   343,   343,
     343,   343,   343,   343,   359,   359,   374,   255,   343,   343,
     364,   343,   364,   357,   364,   364,   371,   255,   255,   255,
     343,   286,   374,     8,   343,   343,   358,   357,   364,   364,
     359,   350,   365,   350,   360,   252,   256,   257,   285,    65,
       8,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   255,   343,   359,   343,   343,
     343,   343,   343,   374,   343,   343,     4,   351,   255,   286,
     252,   256,   256,   343,   343,   343,     7,     7,   336,   336,
     251,   343,   343,   343,   343,     6,   360,   360,   255,   252,
       6,   314,   255,   314,   314,   260,   260,   260,   354,   354,
     313,   313,   260,   343,   256,   327,   260,   314,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   256,   252,     7,
     337,     6,     7,   343,     6,   343,   314,   343,   256,   360,
     360,   360,   343,     6,   360,   343,   343,   343,   252,   256,
     252,   252,   252,   186,   260,   314,   255,     8,   252,   252,
     254,   371,   364,   371,   364,   364,   364,   364,   364,   364,
     343,   364,   364,   364,   364,   258,   367,   374,   365,   364,
     364,   364,   350,   374,   360,   256,   256,   256,   256,   343,
     343,   314,   374,   351,   254,   256,   252,   142,   160,   331,
     252,   256,   260,   343,     6,   255,   357,   252,   254,     7,
     283,   284,   257,     7,     6,   360,     7,   227,   283,   343,
     268,   374,   343,   343,   351,   253,   251,   128,   308,   309,
     308,   255,   256,     6,   234,   235,   265,   360,   374,   343,
     343,     4,   351,     6,   360,     6,   360,   343,     6,   364,
     372,   374,   252,   351,   343,     6,   374,     6,   364,   343,
     252,   253,   343,   260,   260,   260,   260,   365,     7,     7,
       7,   252,     7,     7,     7,   252,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,   343,   252,   255,   343,
     359,   256,     6,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   260,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   260,   260,   260,   252,   254,   254,
     360,   260,   260,   286,   260,   286,   260,   260,   260,   252,
     360,   343,   343,   345,   286,   256,   256,   256,   260,   260,
     286,   286,   252,   257,   252,   257,   260,   285,   346,   256,
       7,   351,   286,   255,   256,     8,     8,   360,   257,   252,
     254,   284,   251,   253,   285,   360,     7,   255,   255,   252,
     252,   252,   343,   357,     4,   335,     6,   302,   343,   365,
     252,   256,   252,   252,   256,   256,   360,   257,   256,   314,
     256,   256,   354,   343,   343,   256,   256,   343,   354,   139,
     139,   157,   166,   167,   168,   172,   173,   328,   329,   354,
     256,   324,   252,   256,   252,   252,   252,   252,   252,   252,
     252,   255,     7,   343,     6,   343,   252,   254,   256,   254,
     256,   256,   256,   256,   256,   254,   254,   260,     7,     7,
       7,   257,   343,   256,   343,   343,     7,   257,   286,   260,
     286,   286,   252,   252,   260,   286,   286,   260,   260,   286,
     286,   286,   286,   343,   286,     9,   366,   260,   252,   260,
     286,   257,   260,   347,   254,   256,   256,   257,   251,   253,
     259,   189,     7,   160,     6,   343,   256,   255,     6,   357,
     256,   343,     6,     7,   283,   284,   257,   283,   284,   365,
     343,     6,     4,   255,   362,   374,   256,    47,    47,   357,
     256,     4,   176,   177,   178,   179,   256,   271,   275,   278,
     280,   281,   257,   252,   254,   251,   343,   343,   251,   255,
     251,   255,     8,   360,   364,   252,   257,   252,   254,   251,
     252,   252,   260,   257,   251,   260,     7,   285,     4,   296,
     297,   298,   286,   343,   343,   343,   343,   286,   354,   357,
     357,     7,   357,   357,   357,     7,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,     6,     7,   360,   343,
     343,   343,   343,   256,   343,   343,   343,   357,   364,   364,
     256,   256,   256,   260,   295,   343,   343,   351,   351,   343,
     343,   252,   357,   285,   343,   343,   343,   256,   351,   284,
     257,   284,   343,   343,   286,   256,   357,   360,   360,     7,
       7,     7,   139,   334,     6,   252,   260,     7,     7,     7,
       7,     7,   256,     4,   256,   260,   260,   260,   256,   256,
     117,     4,     6,   343,   255,     6,   251,     6,   174,     6,
     174,   256,   329,   260,   328,     7,     6,     7,     7,     7,
       7,     7,     7,     7,   313,   357,     6,   255,     6,     6,
       6,   105,     7,     7,     6,     6,   343,   357,   357,   357,
       4,   260,     8,     8,   252,     4,   108,   109,     4,   360,
     364,   343,   364,   258,   260,   299,   364,   364,   351,   364,
     252,   260,   351,   255,   308,   255,     6,   343,     6,   255,
     357,   256,   256,   343,     6,     4,   186,   187,   343,     6,
       6,     6,     7,   361,   363,     6,   253,   286,   285,   285,
       6,   272,   251,   251,   255,   282,     6,   351,   257,   364,
     343,   254,   252,   343,     8,   360,   343,   360,   256,   256,
       6,     6,   265,   351,   257,   343,     6,     6,   343,   351,
     252,   343,   255,   343,   365,   286,    47,   255,   357,   365,
     368,   254,   260,     6,   252,   252,   252,   252,     6,     6,
     132,   304,   304,   357,     6,     6,     6,   357,   139,   189,
     303,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       5,   256,   286,   286,   286,   286,   286,   260,   260,   260,
     252,   286,   286,   297,   286,   252,   286,   252,   285,   346,
     286,     6,   286,   260,   251,   253,   285,     4,   252,   254,
     286,     6,   256,   256,   357,   357,   357,     4,     6,   283,
     343,   357,   357,   357,   255,   255,     7,     6,     7,   343,
     343,   343,   255,   255,   255,   253,     6,   343,   357,   343,
       6,     6,   343,   354,   256,     5,   357,   255,   255,   255,
     255,   255,   255,   255,   357,   256,     6,   360,   255,   343,
     343,   254,     6,     6,   185,   343,   343,   343,     6,     6,
       6,     6,     7,   286,   260,   260,   286,   260,   343,     4,
     201,   300,   301,   286,   252,   286,   347,   365,   251,   253,
     343,   255,   314,     6,   314,   260,     6,     6,     7,   283,
     284,   257,     7,     6,   361,   256,   260,   343,   283,   255,
     286,   369,   370,   371,   369,   251,   343,   343,   356,   357,
     255,   251,     4,     6,   252,     6,   252,   256,   256,   252,
     256,     6,     6,   364,   251,     4,   252,   260,   251,   256,
     260,   357,   365,     7,   285,   294,   343,   359,   298,     6,
       6,     6,     6,   354,     6,     6,     6,   139,   305,    99,
     118,   103,     6,     5,   255,   343,   343,   343,   343,   252,
     346,   343,   343,   343,   286,   284,   255,   255,     6,   303,
       6,   343,   357,   139,   139,     4,     6,   360,   360,   343,
     343,   365,   256,   252,   256,   260,   313,   313,   343,   343,
     256,   260,   252,   256,   260,     6,     6,   356,   354,   354,
     354,   354,   354,   240,   354,     6,   256,   343,     6,     6,
       6,   357,   256,   260,     8,   256,   252,   255,   343,   365,
     364,   343,   364,   343,   365,   368,   370,   365,   260,   252,
     260,   256,   343,   331,   331,   357,   365,   343,     6,     4,
     362,     6,   361,   254,   357,   371,     6,   286,   286,   269,
     343,   260,   260,   256,   260,   270,   343,   343,     6,     6,
       6,     6,   343,   343,   252,     6,   343,   290,   292,   255,
     370,   256,   260,     7,     7,   143,     6,   255,   255,   255,
       5,   356,   286,   286,   260,   286,   252,   260,   252,   254,
     360,   360,     6,     6,   343,   343,   255,   256,   256,   255,
       6,     6,   255,   343,   256,   256,   256,   254,     6,   357,
       7,   255,   343,   256,   260,   260,   260,   260,   260,   260,
       6,   256,   184,   343,   343,   360,     6,     6,   252,   286,
     286,   301,   365,   256,   256,   256,   256,     6,     6,     7,
       6,   257,     6,   256,     6,     6,   252,   260,   343,   343,
     255,   357,   256,   260,   252,   252,   260,   256,   295,   299,
     357,   286,   343,   365,   374,   360,   360,   343,     6,   256,
     343,   346,   343,   256,   256,     6,     6,   356,   144,   145,
     150,   338,   144,   145,   338,   360,   313,   256,   260,     6,
     256,   357,   314,   256,     6,   360,   354,   354,   354,   354,
     354,   343,   256,   256,   256,   252,     6,   255,     6,   361,
     187,   273,   343,   260,   260,   356,     6,   343,   343,     6,
     256,   256,   291,     7,   251,   256,   256,   256,   255,   260,
     252,   260,   255,   256,   255,   354,   357,     6,   255,   354,
       6,   256,   256,   343,     6,   139,   256,   325,   255,   256,
     260,   260,   260,   260,   260,     6,     6,     6,   314,     6,
     255,   343,   343,   256,   260,   295,   365,   252,   343,   343,
     343,   360,     6,   354,     6,   354,     6,     6,   256,   343,
     328,   314,     6,   360,   360,   360,   360,   354,   360,   331,
     270,   252,   260,     6,   255,   343,   256,   260,   260,   260,
     256,   260,   260,     6,   256,   256,   326,   256,   256,   256,
     256,   260,   256,   256,   256,   276,   343,   356,   256,   343,
     343,   343,   354,   354,   328,     6,     6,     6,     6,   360,
       6,     6,     6,   255,   252,   256,     6,   256,   286,   260,
     260,   260,   256,   256,   274,   364,   279,   255,     6,   343,
     343,   343,     6,   256,   260,   255,   356,   256,   256,   256,
       6,   364,   277,   364,   256,     6,     6,   256,   260,     6,
       6,   364
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

  case 46:
#line 504 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 506 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 511 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 49:
#line 513 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 50:
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

  case 51:
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

  case 52:
#line 632 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 53:
#line 641 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 54:
#line 648 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 55:
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

  case 56:
#line 667 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 57:
#line 676 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 58:
#line 683 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 59:
#line 693 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 60:
#line 701 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 61:
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

  case 62:
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

  case 63:
#line 749 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 64:
#line 755 "Gmsh.y"
    {
    ;}
    break;

  case 65:
#line 762 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 66:
#line 763 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 67:
#line 764 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 68:
#line 765 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 69:
#line 766 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 70:
#line 770 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 71:
#line 771 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 72:
#line 777 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 73:
#line 777 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 74:
#line 778 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 75:
#line 778 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 79:
#line 788 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 80:
#line 793 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 81:
#line 799 "Gmsh.y"
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

  case 82:
#line 861 "Gmsh.y"
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

  case 83:
#line 876 "Gmsh.y"
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

  case 84:
#line 905 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 85:
#line 915 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 920 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 928 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 88:
#line 933 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 89:
#line 941 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 90:
#line 950 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 91:
#line 955 "Gmsh.y"
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

  case 92:
#line 967 "Gmsh.y"
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

  case 93:
#line 984 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 94:
#line 990 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 95:
#line 999 "Gmsh.y"
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

  case 96:
#line 1017 "Gmsh.y"
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

  case 97:
#line 1035 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 98:
#line 1044 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 99:
#line 1056 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 100:
#line 1061 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 101:
#line 1069 "Gmsh.y"
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

  case 102:
#line 1089 "Gmsh.y"
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

  case 103:
#line 1112 "Gmsh.y"
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

  case 104:
#line 1132 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 105:
#line 1140 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 106:
#line 1147 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 107:
#line 1154 "Gmsh.y"
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

  case 108:
#line 1176 "Gmsh.y"
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

  case 109:
#line 1199 "Gmsh.y"
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

  case 110:
#line 1237 "Gmsh.y"
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

  case 111:
#line 1258 "Gmsh.y"
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

  case 112:
#line 1270 "Gmsh.y"
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

  case 116:
#line 1288 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 117:
#line 1297 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 118:
#line 1306 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1308 "Gmsh.y"
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

  case 120:
#line 1326 "Gmsh.y"
    { init_options(); ;}
    break;

  case 121:
#line 1328 "Gmsh.y"
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

  case 122:
#line 1344 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 123:
#line 1353 "Gmsh.y"
    { init_options(); ;}
    break;

  case 124:
#line 1355 "Gmsh.y"
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

  case 126:
#line 1369 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 127:
#line 1377 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 128:
#line 1383 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 129:
#line 1388 "Gmsh.y"
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

  case 136:
#line 1431 "Gmsh.y"
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

  case 137:
#line 1443 "Gmsh.y"
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

  case 138:
#line 1456 "Gmsh.y"
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

  case 139:
#line 1471 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 140:
#line 1480 "Gmsh.y"
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

  case 145:
#line 1505 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 146:
#line 1513 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 147:
#line 1522 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 148:
#line 1530 "Gmsh.y"
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

  case 149:
#line 1544 "Gmsh.y"
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

  case 150:
#line 1562 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 151:
#line 1566 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 152:
#line 1573 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 153:
#line 1581 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 154:
#line 1585 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 155:
#line 1591 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 156:
#line 1595 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 157:
#line 1606 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 158:
#line 1610 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 159:
#line 1616 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 160:
#line 1620 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 161:
#line 1626 "Gmsh.y"
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

  case 162:
#line 1649 "Gmsh.y"
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

  case 163:
#line 1665 "Gmsh.y"
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

  case 164:
#line 1681 "Gmsh.y"
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

  case 165:
#line 1698 "Gmsh.y"
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

  case 166:
#line 1715 "Gmsh.y"
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

  case 167:
#line 1752 "Gmsh.y"
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

  case 168:
#line 1796 "Gmsh.y"
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

  case 169:
#line 1812 "Gmsh.y"
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

  case 170:
#line 1829 "Gmsh.y"
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

  case 171:
#line 1860 "Gmsh.y"
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

  case 172:
#line 1876 "Gmsh.y"
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

  case 173:
#line 1893 "Gmsh.y"
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

  case 174:
#line 1909 "Gmsh.y"
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

  case 175:
#line 1959 "Gmsh.y"
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

  case 176:
#line 1977 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 177:
#line 1983 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 178:
#line 1989 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1996 "Gmsh.y"
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

  case 180:
#line 2027 "Gmsh.y"
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

  case 181:
#line 2042 "Gmsh.y"
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

  case 182:
#line 2064 "Gmsh.y"
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

  case 183:
#line 2087 "Gmsh.y"
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

  case 184:
#line 2110 "Gmsh.y"
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

  case 185:
#line 2133 "Gmsh.y"
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

  case 186:
#line 2157 "Gmsh.y"
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

  case 187:
#line 2181 "Gmsh.y"
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

  case 188:
#line 2205 "Gmsh.y"
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

  case 189:
#line 2231 "Gmsh.y"
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

  case 190:
#line 2248 "Gmsh.y"
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

  case 191:
#line 2264 "Gmsh.y"
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

  case 192:
#line 2282 "Gmsh.y"
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

  case 193:
#line 2300 "Gmsh.y"
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

  case 194:
#line 2313 "Gmsh.y"
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

  case 195:
#line 2325 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 196:
#line 2329 "Gmsh.y"
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

  case 197:
#line 2355 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 198:
#line 2357 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 199:
#line 2359 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 200:
#line 2361 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 201:
#line 2363 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 202:
#line 2371 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 203:
#line 2373 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 204:
#line 2375 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 205:
#line 2377 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 206:
#line 2385 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 207:
#line 2387 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 208:
#line 2389 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 209:
#line 2397 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 210:
#line 2399 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 211:
#line 2401 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 212:
#line 2403 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 213:
#line 2413 "Gmsh.y"
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

  case 214:
#line 2429 "Gmsh.y"
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

  case 215:
#line 2445 "Gmsh.y"
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

  case 216:
#line 2461 "Gmsh.y"
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

  case 217:
#line 2477 "Gmsh.y"
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

  case 218:
#line 2493 "Gmsh.y"
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

  case 219:
#line 2510 "Gmsh.y"
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

  case 220:
#line 2547 "Gmsh.y"
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

  case 221:
#line 2569 "Gmsh.y"
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

  case 222:
#line 2592 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 223:
#line 2593 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 224:
#line 2598 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 225:
#line 2602 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 226:
#line 2606 "Gmsh.y"
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

  case 227:
#line 2623 "Gmsh.y"
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

  case 228:
#line 2643 "Gmsh.y"
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

  case 229:
#line 2663 "Gmsh.y"
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

  case 230:
#line 2682 "Gmsh.y"
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

  case 231:
#line 2709 "Gmsh.y"
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

  case 232:
#line 2728 "Gmsh.y"
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

  case 233:
#line 2750 "Gmsh.y"
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

  case 234:
#line 2765 "Gmsh.y"
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

  case 235:
#line 2780 "Gmsh.y"
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

  case 236:
#line 2799 "Gmsh.y"
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

  case 237:
#line 2850 "Gmsh.y"
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

  case 238:
#line 2871 "Gmsh.y"
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

  case 239:
#line 2893 "Gmsh.y"
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

  case 240:
#line 2915 "Gmsh.y"
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

  case 241:
#line 3020 "Gmsh.y"
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

  case 242:
#line 3036 "Gmsh.y"
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

  case 243:
#line 3071 "Gmsh.y"
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

  case 244:
#line 3093 "Gmsh.y"
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

  case 245:
#line 3115 "Gmsh.y"
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

  case 246:
#line 3127 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 247:
#line 3133 "Gmsh.y"
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

  case 248:
#line 3148 "Gmsh.y"
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

  case 249:
#line 3176 "Gmsh.y"
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

  case 250:
#line 3188 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 251:
#line 3197 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3204 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 253:
#line 3216 "Gmsh.y"
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

  case 254:
#line 3236 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 255:
#line 3240 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 256:
#line 3245 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 257:
#line 3249 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 258:
#line 3254 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 259:
#line 3261 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3268 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 261:
#line 3275 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 262:
#line 3287 "Gmsh.y"
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

  case 263:
#line 3360 "Gmsh.y"
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

  case 264:
#line 3378 "Gmsh.y"
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

  case 265:
#line 3403 "Gmsh.y"
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

  case 266:
#line 3418 "Gmsh.y"
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

  case 267:
#line 3451 "Gmsh.y"
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

  case 268:
#line 3463 "Gmsh.y"
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

  case 269:
#line 3495 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 270:
#line 3499 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 271:
#line 3504 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 272:
#line 3511 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 273:
#line 3516 "Gmsh.y"
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

  case 274:
#line 3526 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 275:
#line 3531 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 276:
#line 3537 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 277:
#line 3545 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 278:
#line 3549 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 279:
#line 3553 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 280:
#line 3557 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 281:
#line 3561 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 282:
#line 3565 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 283:
#line 3569 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 284:
#line 3579 "Gmsh.y"
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

  case 285:
#line 3642 "Gmsh.y"
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

  case 286:
#line 3658 "Gmsh.y"
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

  case 287:
#line 3675 "Gmsh.y"
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

  case 288:
#line 3692 "Gmsh.y"
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

  case 289:
#line 3714 "Gmsh.y"
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

  case 290:
#line 3736 "Gmsh.y"
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

  case 291:
#line 3771 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 292:
#line 3779 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 293:
#line 3787 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 294:
#line 3793 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 295:
#line 3800 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 296:
#line 3807 "Gmsh.y"
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

  case 297:
#line 3827 "Gmsh.y"
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

  case 298:
#line 3853 "Gmsh.y"
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

  case 299:
#line 3865 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 300:
#line 3876 "Gmsh.y"
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

  case 301:
#line 3894 "Gmsh.y"
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

  case 302:
#line 3912 "Gmsh.y"
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

  case 303:
#line 3930 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 304:
#line 3936 "Gmsh.y"
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

  case 305:
#line 3954 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 306:
#line 3960 "Gmsh.y"
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

  case 307:
#line 3980 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 308:
#line 3986 "Gmsh.y"
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

  case 309:
#line 4004 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 310:
#line 4010 "Gmsh.y"
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

  case 311:
#line 4027 "Gmsh.y"
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

  case 312:
#line 4043 "Gmsh.y"
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

  case 313:
#line 4060 "Gmsh.y"
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

  case 314:
#line 4078 "Gmsh.y"
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

  case 315:
#line 4101 "Gmsh.y"
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

  case 316:
#line 4128 "Gmsh.y"
    {
    ;}
    break;

  case 317:
#line 4131 "Gmsh.y"
    {
    ;}
    break;

  case 318:
#line 4137 "Gmsh.y"
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

  case 319:
#line 4149 "Gmsh.y"
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

  case 320:
#line 4169 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 321:
#line 4173 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 322:
#line 4177 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 323:
#line 4181 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 324:
#line 4185 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 325:
#line 4189 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 326:
#line 4193 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 327:
#line 4197 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 328:
#line 4206 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 329:
#line 4218 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 330:
#line 4219 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 331:
#line 4220 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 332:
#line 4221 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 333:
#line 4222 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 334:
#line 4226 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 335:
#line 4227 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 336:
#line 4228 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 337:
#line 4229 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 338:
#line 4230 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 339:
#line 4235 "Gmsh.y"
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

  case 340:
#line 4258 "Gmsh.y"
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

  case 341:
#line 4278 "Gmsh.y"
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

  case 342:
#line 4299 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 343:
#line 4303 "Gmsh.y"
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

  case 344:
#line 4318 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 345:
#line 4322 "Gmsh.y"
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

  case 346:
#line 4338 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 347:
#line 4342 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 348:
#line 4347 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 349:
#line 4351 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 350:
#line 4357 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 351:
#line 4361 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 352:
#line 4368 "Gmsh.y"
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

  case 353:
#line 4390 "Gmsh.y"
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

  case 354:
#line 4431 "Gmsh.y"
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

  case 355:
#line 4475 "Gmsh.y"
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

  case 356:
#line 4514 "Gmsh.y"
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

  case 357:
#line 4539 "Gmsh.y"
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

  case 358:
#line 4551 "Gmsh.y"
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

  case 359:
#line 4563 "Gmsh.y"
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

  case 360:
#line 4575 "Gmsh.y"
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

  case 361:
#line 4587 "Gmsh.y"
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

  case 362:
#line 4604 "Gmsh.y"
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

  case 363:
#line 4621 "Gmsh.y"
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

  case 364:
#line 4651 "Gmsh.y"
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

  case 365:
#line 4677 "Gmsh.y"
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

  case 366:
#line 4704 "Gmsh.y"
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

  case 367:
#line 4736 "Gmsh.y"
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

  case 368:
#line 4763 "Gmsh.y"
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

  case 369:
#line 4789 "Gmsh.y"
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

  case 370:
#line 4815 "Gmsh.y"
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

  case 371:
#line 4841 "Gmsh.y"
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

  case 372:
#line 4867 "Gmsh.y"
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

  case 373:
#line 4888 "Gmsh.y"
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

  case 374:
#line 4899 "Gmsh.y"
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

  case 375:
#line 4947 "Gmsh.y"
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

  case 376:
#line 5001 "Gmsh.y"
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

  case 377:
#line 5016 "Gmsh.y"
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

  case 378:
#line 5028 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 379:
#line 5039 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 380:
#line 5046 "Gmsh.y"
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

  case 381:
#line 5061 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 382:
#line 5074 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 383:
#line 5075 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 384:
#line 5076 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 385:
#line 5081 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 386:
#line 5087 "Gmsh.y"
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

  case 387:
#line 5099 "Gmsh.y"
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

  case 388:
#line 5117 "Gmsh.y"
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

  case 389:
#line 5144 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 390:
#line 5145 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 391:
#line 5146 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 392:
#line 5147 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 393:
#line 5148 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 394:
#line 5149 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 395:
#line 5150 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 396:
#line 5151 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 397:
#line 5153 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 398:
#line 5159 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 399:
#line 5160 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 400:
#line 5161 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 401:
#line 5162 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 402:
#line 5163 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5164 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5165 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 405:
#line 5166 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 406:
#line 5167 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 407:
#line 5168 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5169 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5170 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5171 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 411:
#line 5172 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 412:
#line 5173 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 413:
#line 5174 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 414:
#line 5175 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 415:
#line 5176 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 416:
#line 5177 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 417:
#line 5178 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 418:
#line 5179 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 419:
#line 5180 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 420:
#line 5181 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 421:
#line 5182 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5183 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5184 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 424:
#line 5185 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5186 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5187 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5188 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5189 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 429:
#line 5190 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 430:
#line 5191 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5192 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 432:
#line 5193 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 433:
#line 5194 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 434:
#line 5195 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 435:
#line 5196 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 436:
#line 5205 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 437:
#line 5206 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 438:
#line 5207 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 439:
#line 5208 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 440:
#line 5209 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 441:
#line 5210 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 442:
#line 5211 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 443:
#line 5212 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 444:
#line 5213 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 445:
#line 5214 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 446:
#line 5215 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 447:
#line 5220 "Gmsh.y"
    { init_options(); ;}
    break;

  case 448:
#line 5222 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 449:
#line 5228 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 450:
#line 5230 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 451:
#line 5235 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 452:
#line 5240 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 453:
#line 5245 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 454:
#line 5250 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 455:
#line 5254 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 456:
#line 5258 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 457:
#line 5262 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 458:
#line 5266 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 459:
#line 5270 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 460:
#line 5274 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 461:
#line 5278 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5284 "Gmsh.y"
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

  case 463:
#line 5299 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 464:
#line 5303 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 465:
#line 5309 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 466:
#line 5314 "Gmsh.y"
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

  case 467:
#line 5333 "Gmsh.y"
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

  case 468:
#line 5353 "Gmsh.y"
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

  case 469:
#line 5384 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 470:
#line 5388 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 471:
#line 5392 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 472:
#line 5396 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 473:
#line 5400 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 474:
#line 5404 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 475:
#line 5408 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 476:
#line 5413 "Gmsh.y"
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

  case 477:
#line 5423 "Gmsh.y"
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

  case 478:
#line 5433 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 479:
#line 5438 "Gmsh.y"
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

  case 480:
#line 5449 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 481:
#line 5458 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 482:
#line 5463 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 483:
#line 5468 "Gmsh.y"
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

  case 484:
#line 5495 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 485:
#line 5497 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 486:
#line 5502 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 487:
#line 5504 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 488:
#line 5509 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 489:
#line 5516 "Gmsh.y"
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

  case 490:
#line 5532 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 491:
#line 5534 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 492:
#line 5539 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 493:
#line 5548 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 494:
#line 5550 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 495:
#line 5555 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 496:
#line 5557 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 497:
#line 5562 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 498:
#line 5566 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 499:
#line 5570 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 500:
#line 5574 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 501:
#line 5578 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 502:
#line 5585 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 503:
#line 5589 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 504:
#line 5593 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 505:
#line 5597 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 506:
#line 5604 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 507:
#line 5609 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 508:
#line 5616 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 509:
#line 5621 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 510:
#line 5625 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 511:
#line 5630 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 512:
#line 5634 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 513:
#line 5642 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 514:
#line 5653 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 515:
#line 5657 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 516:
#line 5661 "Gmsh.y"
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

  case 517:
#line 5675 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 518:
#line 5683 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 519:
#line 5691 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 520:
#line 5698 "Gmsh.y"
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

  case 521:
#line 5708 "Gmsh.y"
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

  case 522:
#line 5731 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 523:
#line 5736 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 524:
#line 5742 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 525:
#line 5747 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 526:
#line 5753 "Gmsh.y"
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

  case 527:
#line 5764 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 528:
#line 5771 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 529:
#line 5776 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 530:
#line 5782 "Gmsh.y"
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

  case 531:
#line 5794 "Gmsh.y"
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

  case 532:
#line 5808 "Gmsh.y"
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

  case 533:
#line 5818 "Gmsh.y"
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

  case 534:
#line 5828 "Gmsh.y"
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

  case 535:
#line 5838 "Gmsh.y"
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

  case 536:
#line 5850 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 537:
#line 5854 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 538:
#line 5859 "Gmsh.y"
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

  case 539:
#line 5871 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 540:
#line 5875 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 541:
#line 5879 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 542:
#line 5883 "Gmsh.y"
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

  case 543:
#line 5901 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 544:
#line 5909 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 545:
#line 5917 "Gmsh.y"
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

  case 546:
#line 5946 "Gmsh.y"
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

  case 547:
#line 5956 "Gmsh.y"
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

  case 548:
#line 5972 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 549:
#line 5983 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 550:
#line 5988 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 551:
#line 5992 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 552:
#line 5996 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 553:
#line 6008 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 554:
#line 6012 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 555:
#line 6024 "Gmsh.y"
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

  case 556:
#line 6041 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 557:
#line 6051 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 558:
#line 6055 "Gmsh.y"
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

  case 559:
#line 6070 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 560:
#line 6075 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 561:
#line 6082 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 562:
#line 6086 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 563:
#line 6091 "Gmsh.y"
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

  case 564:
#line 6105 "Gmsh.y"
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

  case 565:
#line 6121 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 566:
#line 6125 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 567:
#line 6129 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 568:
#line 6133 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 569:
#line 6137 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 570:
#line 6145 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 571:
#line 6151 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 572:
#line 6160 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 573:
#line 6164 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 574:
#line 6168 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 575:
#line 6176 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 576:
#line 6182 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 577:
#line 6188 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 578:
#line 6192 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 579:
#line 6200 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 580:
#line 6208 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 581:
#line 6215 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 582:
#line 6224 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 583:
#line 6228 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 584:
#line 6232 "Gmsh.y"
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

  case 585:
#line 6247 "Gmsh.y"
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

  case 586:
#line 6261 "Gmsh.y"
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

  case 587:
#line 6275 "Gmsh.y"
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

  case 588:
#line 6287 "Gmsh.y"
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

  case 589:
#line 6303 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 590:
#line 6312 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 591:
#line 6321 "Gmsh.y"
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

  case 592:
#line 6331 "Gmsh.y"
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

  case 593:
#line 6342 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 594:
#line 6350 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 595:
#line 6358 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 596:
#line 6362 "Gmsh.y"
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

  case 597:
#line 6381 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 598:
#line 6388 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 599:
#line 6394 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 600:
#line 6400 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 601:
#line 6407 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 602:
#line 6414 "Gmsh.y"
    { init_options(); ;}
    break;

  case 603:
#line 6416 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 604:
#line 6424 "Gmsh.y"
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

  case 605:
#line 6448 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 606:
#line 6450 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 607:
#line 6456 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 608:
#line 6461 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 609:
#line 6463 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 610:
#line 6468 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 611:
#line 6473 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 612:
#line 6478 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 613:
#line 6480 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 614:
#line 6484 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 615:
#line 6496 "Gmsh.y"
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

  case 616:
#line 6510 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 617:
#line 6514 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 618:
#line 6521 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 619:
#line 6529 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 620:
#line 6537 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 621:
#line 6548 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 622:
#line 6550 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 623:
#line 6553 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14579 "Gmsh.tab.cpp"
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


#line 6556 "Gmsh.y"


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

