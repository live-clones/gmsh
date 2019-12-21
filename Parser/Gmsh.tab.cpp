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
#define YYLAST   17472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  624
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2243

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
     150,   151,   154,   157,   160,   163,   166,   169,   171,   175,
     177,   181,   182,   183,   194,   196,   200,   201,   215,   217,
     221,   222,   238,   247,   262,   263,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   298,   304,
     307,   315,   323,   328,   332,   339,   349,   357,   364,   372,
     379,   384,   393,   403,   413,   420,   430,   437,   447,   453,
     462,   471,   483,   490,   500,   506,   514,   522,   530,   540,
     550,   562,   570,   580,   590,   591,   593,   594,   598,   604,
     605,   615,   616,   628,   634,   635,   645,   646,   650,   654,
     660,   666,   667,   670,   671,   673,   675,   679,   682,   684,
     689,   692,   695,   696,   699,   701,   705,   708,   711,   714,
     717,   720,   722,   724,   728,   729,   735,   741,   747,   748,
     751,   752,   755,   763,   771,   779,   790,   801,   810,   819,
     827,   835,   847,   855,   864,   873,   882,   892,   896,   901,
     912,   920,   928,   936,   944,   952,   960,   968,   976,   984,
     992,  1002,  1010,  1018,  1027,  1036,  1049,  1050,  1060,  1062,
    1064,  1066,  1068,  1073,  1075,  1077,  1079,  1084,  1086,  1088,
    1093,  1095,  1097,  1099,  1104,  1110,  1122,  1128,  1138,  1148,
    1156,  1161,  1171,  1181,  1183,  1185,  1186,  1189,  1196,  1204,
    1212,  1219,  1227,  1236,  1247,  1262,  1279,  1292,  1307,  1322,
    1337,  1352,  1361,  1370,  1377,  1382,  1388,  1394,  1401,  1408,
    1412,  1417,  1421,  1427,  1434,  1440,  1445,  1449,  1454,  1458,
    1463,  1469,  1474,  1480,  1484,  1490,  1498,  1506,  1510,  1518,
    1522,  1525,  1528,  1531,  1534,  1537,  1553,  1556,  1559,  1562,
    1572,  1584,  1587,  1590,  1593,  1596,  1613,  1625,  1632,  1641,
    1650,  1661,  1663,  1666,  1669,  1671,  1675,  1679,  1684,  1689,
    1691,  1693,  1699,  1711,  1725,  1726,  1734,  1735,  1749,  1750,
    1766,  1767,  1774,  1784,  1787,  1791,  1802,  1816,  1818,  1821,
    1827,  1835,  1838,  1841,  1845,  1848,  1852,  1855,  1859,  1869,
    1876,  1878,  1880,  1882,  1884,  1886,  1887,  1890,  1894,  1898,
    1903,  1913,  1918,  1933,  1934,  1938,  1939,  1941,  1942,  1945,
    1946,  1949,  1950,  1953,  1960,  1968,  1975,  1981,  1985,  1994,
    2003,  2012,  2021,  2030,  2039,  2045,  2050,  2057,  2069,  2081,
    2100,  2119,  2132,  2145,  2158,  2169,  2174,  2179,  2184,  2189,
    2194,  2197,  2201,  2208,  2210,  2212,  2214,  2217,  2223,  2231,
    2242,  2244,  2248,  2251,  2254,  2257,  2261,  2265,  2269,  2273,
    2277,  2281,  2285,  2289,  2293,  2297,  2301,  2305,  2309,  2313,
    2317,  2321,  2325,  2329,  2335,  2340,  2345,  2350,  2355,  2360,
    2365,  2370,  2375,  2380,  2385,  2392,  2397,  2402,  2407,  2412,
    2417,  2422,  2427,  2432,  2439,  2446,  2453,  2458,  2460,  2462,
    2464,  2466,  2468,  2470,  2472,  2474,  2476,  2478,  2480,  2481,
    2488,  2490,  2495,  2502,  2504,  2509,  2514,  2519,  2526,  2532,
    2540,  2549,  2560,  2565,  2570,  2577,  2582,  2586,  2589,  2595,
    2601,  2605,  2611,  2618,  2627,  2634,  2643,  2650,  2655,  2663,
    2670,  2677,  2684,  2689,  2696,  2701,  2702,  2705,  2706,  2709,
    2710,  2718,  2720,  2724,  2726,  2728,  2731,  2732,  2736,  2738,
    2741,  2744,  2748,  2752,  2764,  2774,  2782,  2790,  2792,  2796,
    2798,  2800,  2803,  2807,  2812,  2818,  2820,  2824,  2826,  2829,
    2833,  2837,  2843,  2848,  2853,  2856,  2861,  2864,  2868,  2872,
    2889,  2895,  2901,  2907,  2909,  2911,  2913,  2917,  2923,  2931,
    2936,  2941,  2946,  2953,  2960,  2969,  2978,  2983,  2998,  3003,
    3008,  3010,  3012,  3016,  3020,  3030,  3038,  3040,  3046,  3050,
    3057,  3059,  3063,  3065,  3067,  3072,  3077,  3081,  3087,  3094,
    3103,  3110,  3115,  3121,  3123,  3128,  3130,  3132,  3134,  3136,
    3141,  3148,  3153,  3160,  3166,  3174,  3179,  3184,  3189,  3198,
    3203,  3208,  3213,  3218,  3227,  3236,  3243,  3248,  3255,  3260,
    3262,  3264,  3269,  3274,  3275,  3282,  3287,  3290,  3295,  3300,
    3302,  3304,  3308,  3310,  3312,  3316,  3320,  3324,  3330,  3338,
    3344,  3350,  3359,  3361,  3363
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
     268,   280,    -1,   268,   281,    -1,   268,   322,    -1,   343,
      -1,   269,   260,   343,    -1,   343,    -1,   270,   260,   343,
      -1,    -1,    -1,     4,   272,   251,   269,   252,   273,   255,
     270,   256,     6,    -1,   364,    -1,   274,   260,   364,    -1,
      -1,   176,   251,   343,   260,   343,   260,   343,   252,   276,
     255,   274,   256,     6,    -1,   364,    -1,   277,   260,   364,
      -1,    -1,   177,   251,   343,   260,   343,   260,   343,   260,
     343,   252,   279,   255,   277,   256,     6,    -1,   178,   255,
     356,   256,   255,   356,   256,     6,    -1,   178,   255,   356,
     256,   255,   356,   256,   255,   356,   256,   255,   356,   256,
       6,    -1,    -1,   179,   282,   255,   270,   256,     6,    -1,
       7,    -1,   227,    -1,   226,    -1,   225,    -1,   224,    -1,
     249,    -1,   248,    -1,   251,    -1,   253,    -1,   252,    -1,
     254,    -1,    88,   253,   289,   254,     6,    -1,    89,   253,
     293,   254,     6,    -1,   348,     6,    -1,    96,   285,   365,
     260,   343,   286,     6,    -1,    98,   285,   374,   260,   365,
     286,     6,    -1,   374,   283,   357,     6,    -1,   374,   284,
       6,    -1,   374,   285,   286,   283,   357,     6,    -1,   374,
     285,   255,   360,   256,   286,   283,   357,     6,    -1,   374,
     253,   343,   254,   283,   343,     6,    -1,   374,   253,   343,
     254,   284,     6,    -1,   374,   251,   343,   252,   283,   343,
       6,    -1,   374,   251,   343,   252,   284,     6,    -1,   374,
       7,   365,     6,    -1,   374,   285,   286,     7,    47,   285,
     286,     6,    -1,   374,   285,   286,     7,    47,   285,   369,
     286,     6,    -1,   374,   285,   286,   227,    47,   285,   369,
     286,     6,    -1,   374,   257,     4,     7,   365,     6,    -1,
     374,   253,   343,   254,   257,     4,     7,   365,     6,    -1,
     374,   257,     4,   283,   343,     6,    -1,   374,   253,   343,
     254,   257,     4,   283,   343,     6,    -1,   374,   257,     4,
     284,     6,    -1,   374,   253,   343,   254,   257,     4,   284,
       6,    -1,   374,   257,   186,   257,     4,     7,   361,     6,
      -1,   374,   253,   343,   254,   257,   186,   257,     4,     7,
     361,     6,    -1,   374,   257,   187,     7,   362,     6,    -1,
     374,   253,   343,   254,   257,   187,     7,   362,     6,    -1,
     374,   197,     7,   357,     6,    -1,   197,   253,   343,   254,
       7,     4,     6,    -1,   197,   253,   343,   254,     7,   108,
       6,    -1,   197,   253,   343,   254,     7,   109,     6,    -1,
     197,   253,   343,   254,   257,     4,     7,   343,     6,    -1,
     197,   253,   343,   254,   257,     4,     7,   365,     6,    -1,
     197,   253,   343,   254,   257,     4,     7,   255,   360,   256,
       6,    -1,   197,   253,   343,   254,   257,     4,     6,    -1,
     140,   251,     4,   252,   257,     4,     7,   343,     6,    -1,
     140,   251,     4,   252,   257,     4,     7,   365,     6,    -1,
      -1,   260,    -1,    -1,   289,   288,   374,    -1,   289,   288,
     374,     7,   343,    -1,    -1,   289,   288,   374,     7,   255,
     357,   290,   295,   256,    -1,    -1,   289,   288,   374,   285,
     286,     7,   255,   357,   291,   295,   256,    -1,   289,   288,
     374,     7,   365,    -1,    -1,   289,   288,   374,     7,   255,
     365,   292,   299,   256,    -1,    -1,   293,   288,   364,    -1,
     343,     7,   365,    -1,   294,   260,   343,     7,   365,    -1,
     359,     7,   374,   251,   252,    -1,    -1,   260,   297,    -1,
      -1,   297,    -1,   298,    -1,   297,   260,   298,    -1,     4,
     357,    -1,     4,    -1,     4,   255,   294,   256,    -1,     4,
     365,    -1,     4,   368,    -1,    -1,   260,   300,    -1,   301,
      -1,   300,   260,   301,    -1,     4,   343,    -1,     4,   365,
      -1,   201,   365,    -1,     4,   370,    -1,     4,   368,    -1,
     343,    -1,   365,    -1,   365,   260,   343,    -1,    -1,   189,
     103,   255,   343,   256,    -1,   139,    99,   255,   360,   256,
      -1,   139,   118,   255,   360,   256,    -1,    -1,   132,   354,
      -1,    -1,   139,   143,    -1,    99,   251,   343,   252,     7,
     354,     6,    -1,   102,   251,   343,   252,     7,   357,     6,
      -1,   106,   251,   343,   252,     7,   357,     6,    -1,   136,
     106,   251,   343,   252,     7,   357,   139,   343,     6,    -1,
     136,   181,   251,   343,   252,     7,   357,   139,   343,     6,
      -1,   100,   251,   343,   252,     7,   357,   304,     6,    -1,
     101,   251,   343,   252,     7,   357,   304,     6,    -1,   181,
     251,   343,   252,     7,   357,     6,    -1,   182,   251,   343,
     252,     7,   357,     6,    -1,   183,   251,   343,   252,     7,
     357,   185,   357,   184,   343,     6,    -1,   117,   251,   343,
     252,     7,   357,     6,    -1,   102,     4,   251,   343,   252,
       7,   357,     6,    -1,   132,   105,   251,   343,   252,     7,
     357,     6,    -1,   105,   251,   343,   252,     7,   357,   303,
       6,    -1,   133,   105,   251,   343,   252,     7,   357,   303,
       6,    -1,    13,    14,     6,    -1,    14,   105,   343,     6,
      -1,   121,   105,   251,   343,   252,     7,     5,     5,     5,
       6,    -1,   103,   251,   343,   252,     7,   357,     6,    -1,
     104,   251,   343,   252,     7,   357,     6,    -1,   108,   251,
     343,   252,     7,   357,     6,    -1,   111,   251,   343,   252,
       7,   357,     6,    -1,   115,   251,   343,   252,     7,   357,
       6,    -1,   116,   251,   343,   252,     7,   357,     6,    -1,
     109,   251,   343,   252,     7,   357,     6,    -1,   110,   251,
     343,   252,     7,   357,     6,    -1,   129,   251,   343,   252,
       7,   357,     6,    -1,   156,   251,   343,   252,     7,   357,
       6,    -1,   105,     4,   251,   343,   252,     7,   357,   305,
       6,    -1,   107,   251,   343,   252,     7,   357,     6,    -1,
     128,   251,   343,   252,     7,   357,     6,    -1,   133,   128,
     251,   343,   252,     7,   357,     6,    -1,   136,   309,   251,
     343,   252,     7,   357,     6,    -1,   136,   309,   251,   343,
     252,     7,   357,     4,   255,   356,   256,     6,    -1,    -1,
     135,   308,   307,   251,   302,   252,   283,   357,     6,    -1,
      99,    -1,   102,    -1,   105,    -1,   107,    -1,   118,   255,
     343,   256,    -1,   102,    -1,   105,    -1,   107,    -1,   118,
     255,   343,   256,    -1,   102,    -1,   105,    -1,   118,   255,
     343,   256,    -1,    99,    -1,   102,    -1,   105,    -1,   118,
     255,   343,   256,    -1,   145,   354,   255,   313,   256,    -1,
     144,   255,   354,   260,   354,   260,   343,   256,   255,   313,
     256,    -1,   146,   354,   255,   313,   256,    -1,   147,   255,
     354,   260,   343,   256,   255,   313,   256,    -1,   147,   255,
     354,   260,   354,   256,   255,   313,   256,    -1,   150,   255,
     360,   256,   255,   313,   256,    -1,     4,   255,   313,   256,
      -1,   162,   102,   255,   360,   256,   105,   255,   343,   256,
      -1,   159,   102,   251,   343,   252,   255,   360,   256,     6,
      -1,   314,    -1,   312,    -1,    -1,   314,   306,    -1,   314,
     308,   255,   360,   256,     6,    -1,   314,   135,   308,   255,
     360,   256,     6,    -1,   314,   138,   308,   255,   360,   256,
       6,    -1,   314,   308,   255,     8,   256,     6,    -1,   314,
     135,   308,   255,     8,   256,     6,    -1,   149,   132,   251,
     343,   252,     7,   357,     6,    -1,   149,    99,   251,   343,
     252,     7,   255,   356,   256,     6,    -1,   149,   132,   251,
     343,   252,     7,   255,   354,   260,   354,   260,   360,   256,
       6,    -1,   149,   132,   251,   343,   252,     7,   255,   354,
     260,   354,   260,   354,   260,   360,   256,     6,    -1,   149,
     103,   251,   343,   252,     7,   255,   354,   260,   360,   256,
       6,    -1,   149,   109,   251,   343,   252,     7,   255,   354,
     260,   354,   260,   360,   256,     6,    -1,   149,   110,   251,
     343,   252,     7,   255,   354,   260,   354,   260,   360,   256,
       6,    -1,   149,   112,   251,   343,   252,     7,   255,   354,
     260,   354,   260,   360,   256,     6,    -1,   149,   113,   251,
     343,   252,     7,   255,   354,   260,   354,   260,   360,   256,
       6,    -1,   149,     4,   251,   343,   252,     7,   357,     6,
      -1,   149,     4,   251,   343,   252,     7,     5,     6,    -1,
     149,     4,   255,   343,   256,     6,    -1,   160,   255,   314,
     256,    -1,   142,   160,   255,   314,   256,    -1,   160,     4,
     255,   314,   256,    -1,   160,   197,   253,   343,   254,     6,
      -1,   160,     4,   253,   343,   254,     6,    -1,   160,   374,
       6,    -1,   160,     4,     4,     6,    -1,   160,    91,     6,
      -1,   186,   361,   255,   314,   256,    -1,   142,   186,   361,
     255,   314,   256,    -1,   221,   343,   255,   314,   256,    -1,
     202,   255,     8,   256,    -1,   202,     5,     6,    -1,   203,
     255,     8,   256,    -1,   203,     5,     6,    -1,   202,   255,
     314,   256,    -1,   142,   202,   255,   314,   256,    -1,   203,
     255,   314,   256,    -1,   142,   203,   255,   314,   256,    -1,
     374,   365,     6,    -1,    77,   251,   371,   252,     6,    -1,
     374,   374,   253,   343,   254,   364,     6,    -1,   374,   374,
     374,   253,   343,   254,     6,    -1,   374,   343,     6,    -1,
     140,   251,     4,   252,   257,     4,     6,    -1,   180,     4,
       6,    -1,   195,     6,    -1,   196,     6,    -1,    72,     6,
      -1,    73,     6,    -1,    65,     6,    -1,    65,   255,   343,
     260,   343,   260,   343,   260,   343,   260,   343,   260,   343,
     256,     6,    -1,    66,     6,    -1,    67,     6,    -1,    82,
       6,    -1,    84,   255,   343,   260,   343,   260,   343,   256,
       6,    -1,    84,   255,   343,   260,   343,   260,   343,   260,
     343,   256,     6,    -1,    83,     6,    -1,    85,     6,    -1,
      86,     6,    -1,   123,     6,    -1,   124,   255,   360,   256,
     255,   360,   256,   255,   356,   256,   255,   343,   260,   343,
     256,     6,    -1,   200,   251,   255,   360,   256,   260,   365,
     260,   365,   252,     6,    -1,   188,   251,   343,     8,   343,
     252,    -1,   188,   251,   343,     8,   343,     8,   343,   252,
      -1,   188,     4,   189,   255,   343,     8,   343,   256,    -1,
     188,     4,   189,   255,   343,     8,   343,     8,   343,   256,
      -1,   190,    -1,   201,     4,    -1,   201,   365,    -1,   198,
      -1,   199,   374,     6,    -1,   199,   365,     6,    -1,   191,
     251,   343,   252,    -1,   192,   251,   343,   252,    -1,   193,
      -1,   194,    -1,   148,   354,   255,   314,   256,    -1,   148,
     255,   354,   260,   354,   260,   343,   256,   255,   314,   256,
      -1,   148,   255,   354,   260,   354,   260,   354,   260,   343,
     256,   255,   314,   256,    -1,    -1,   148,   354,   255,   314,
     324,   328,   256,    -1,    -1,   148,   255,   354,   260,   354,
     260,   343,   256,   255,   314,   325,   328,   256,    -1,    -1,
     148,   255,   354,   260,   354,   260,   354,   260,   343,   256,
     255,   314,   326,   328,   256,    -1,    -1,   148,   255,   314,
     327,   328,   256,    -1,   148,   255,   314,   256,   139,   117,
     255,   343,   256,    -1,   128,   357,    -1,   133,   128,   357,
      -1,   130,   255,   360,   256,   255,   360,   256,   255,   360,
     256,    -1,   131,   255,   360,   256,   255,   360,   256,   255,
     360,   256,   255,   360,   256,    -1,   329,    -1,   328,   329,
      -1,   166,   255,   343,   256,     6,    -1,   166,   255,   357,
     260,   357,   256,     6,    -1,   167,     6,    -1,   157,     6,
      -1,   157,   343,     6,    -1,   172,     6,    -1,   172,   174,
       6,    -1,   173,     6,    -1,   173,   174,     6,    -1,   168,
     251,   343,   252,     7,   357,   139,   343,     6,    -1,   139,
       4,   253,   343,   254,     6,    -1,   151,    -1,   152,    -1,
     153,    -1,   154,    -1,   155,    -1,    -1,   160,     6,    -1,
     142,   160,     6,    -1,   160,   343,     6,    -1,   142,   160,
     343,     6,    -1,   330,   255,   314,   331,   256,   255,   314,
     331,   256,    -1,   114,   251,   364,   252,    -1,   330,   251,
     343,   252,     7,   255,   314,   331,   256,   255,   314,   331,
     256,     6,    -1,    -1,   139,     4,   343,    -1,    -1,     4,
      -1,    -1,     7,   357,    -1,    -1,     7,   343,    -1,    -1,
     150,   357,    -1,   119,   120,   358,     7,   343,     6,    -1,
     134,   102,   358,     7,   343,   334,     6,    -1,   134,   105,
     358,   336,   335,     6,    -1,   134,   107,   358,   336,     6,
      -1,   175,   358,     6,    -1,    97,    99,   251,   343,   260,
     343,   252,     6,    -1,    97,   102,   251,   343,   260,   343,
     252,     6,    -1,    97,   105,   251,   343,   260,   343,   252,
       6,    -1,    97,   107,   251,   343,   260,   343,   252,     6,
      -1,   163,   105,   255,   360,   256,     7,   343,     6,    -1,
     165,   105,   255,   360,   256,     7,   343,     6,    -1,   157,
     105,   358,   337,     6,    -1,   157,   107,   358,     6,    -1,
     158,   105,   358,     7,   343,     6,    -1,   137,   102,   255,
     360,   256,     7,   255,   360,   256,   338,     6,    -1,   137,
     105,   255,   360,   256,     7,   255,   360,   256,   338,     6,
      -1,   137,   102,   255,   360,   256,     7,   255,   360,   256,
     144,   255,   354,   260,   354,   260,   343,   256,     6,    -1,
     137,   105,   255,   360,   256,     7,   255,   360,   256,   144,
     255,   354,   260,   354,   260,   343,   256,     6,    -1,   137,
     102,   255,   360,   256,     7,   255,   360,   256,   145,   354,
       6,    -1,   137,   105,   255,   360,   256,     7,   255,   360,
     256,   145,   354,     6,    -1,   137,   105,   343,   255,   360,
     256,     7,   343,   255,   360,   256,     6,    -1,   308,   255,
     360,   256,   189,   308,   255,   343,   256,     6,    -1,   164,
     310,   358,     6,    -1,   125,   311,   358,     6,    -1,   126,
     107,   357,     6,    -1,   141,   102,   357,     6,    -1,   136,
     309,   357,     6,    -1,   161,     6,    -1,   161,     4,     6,
      -1,   161,    99,   255,   360,   256,     6,    -1,   210,    -1,
     211,    -1,   212,    -1,   341,     6,    -1,   341,   255,   357,
     256,     6,    -1,   341,   255,   357,   260,   357,   256,     6,
      -1,   341,   251,   357,   252,   255,   357,   260,   357,   256,
       6,    -1,   344,    -1,   251,   343,   252,    -1,   240,   343,
      -1,   239,   343,    -1,   246,   343,    -1,   343,   240,   343,
      -1,   343,   239,   343,    -1,   343,   241,   343,    -1,   343,
     242,   343,    -1,   343,   244,   343,    -1,   343,   245,   343,
      -1,   343,   243,   343,    -1,   343,   250,   343,    -1,   343,
     233,   343,    -1,   343,   234,   343,    -1,   343,   238,   343,
      -1,   343,   237,   343,    -1,   343,   232,   343,    -1,   343,
     231,   343,    -1,   343,   230,   343,    -1,   343,   229,   343,
      -1,   343,   235,   343,    -1,   343,   236,   343,    -1,   343,
     228,   343,     8,   343,    -1,    16,   285,   343,   286,    -1,
      17,   285,   343,   286,    -1,    18,   285,   343,   286,    -1,
      19,   285,   343,   286,    -1,    20,   285,   343,   286,    -1,
      21,   285,   343,   286,    -1,    22,   285,   343,   286,    -1,
      23,   285,   343,   286,    -1,    24,   285,   343,   286,    -1,
      26,   285,   343,   286,    -1,    27,   285,   343,   260,   343,
     286,    -1,    28,   285,   343,   286,    -1,    29,   285,   343,
     286,    -1,    30,   285,   343,   286,    -1,    31,   285,   343,
     286,    -1,    32,   285,   343,   286,    -1,    33,   285,   343,
     286,    -1,    34,   285,   343,   286,    -1,    35,   285,   343,
     286,    -1,    36,   285,   343,   260,   343,   286,    -1,    37,
     285,   343,   260,   343,   286,    -1,    38,   285,   343,   260,
     343,   286,    -1,    25,   285,   343,   286,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   217,    -1,
     218,    -1,   219,    -1,    79,    -1,    80,    -1,    81,    -1,
      -1,    90,   285,   343,   345,   295,   286,    -1,   348,    -1,
     208,   285,   364,   286,    -1,   208,   285,   364,   260,   343,
     286,    -1,   350,    -1,   374,   253,   343,   254,    -1,   374,
     251,   343,   252,    -1,   213,   251,   350,   252,    -1,   213,
     251,   350,   257,   351,   252,    -1,   215,   251,   350,   346,
     252,    -1,   215,   251,   350,   257,   351,   346,   252,    -1,
     215,   251,   350,   285,   343,   286,   346,   252,    -1,   215,
     251,   350,   257,   351,   285,   343,   286,   346,   252,    -1,
     214,   251,   365,   252,    -1,   258,   374,   285,   286,    -1,
     258,   350,   257,   351,   285,   286,    -1,    93,   285,   374,
     286,    -1,    93,   285,   286,    -1,   374,   284,    -1,   374,
     253,   343,   254,   284,    -1,   374,   251,   343,   252,   284,
      -1,   374,   257,   351,    -1,   374,     9,   374,   257,   351,
      -1,   374,   257,   351,   251,   343,   252,    -1,   374,     9,
     374,   257,   351,   251,   343,   252,    -1,   374,   257,   351,
     253,   343,   254,    -1,   374,     9,   374,   257,   351,   253,
     343,   254,    -1,   374,   253,   343,   254,   257,     4,    -1,
     374,   257,     4,   284,    -1,   374,   253,   343,   254,   257,
       4,   284,    -1,   204,   251,   364,   260,   343,   252,    -1,
      57,   251,   357,   260,   357,   252,    -1,    58,   285,   364,
     260,   364,   286,    -1,    56,   285,   364,   286,    -1,    59,
     285,   364,   260,   364,   286,    -1,    64,   251,   371,   252,
      -1,    -1,   260,   343,    -1,    -1,   260,   364,    -1,    -1,
      91,   350,   353,   349,   253,   296,   254,    -1,   374,    -1,
     374,     9,   374,    -1,     4,    -1,    94,    -1,    94,   343,
      -1,    -1,   251,   352,   252,    -1,   355,    -1,   240,   354,
      -1,   239,   354,    -1,   354,   240,   354,    -1,   354,   239,
     354,    -1,   255,   343,   260,   343,   260,   343,   260,   343,
     260,   343,   256,    -1,   255,   343,   260,   343,   260,   343,
     260,   343,   256,    -1,   255,   343,   260,   343,   260,   343,
     256,    -1,   251,   343,   260,   343,   260,   343,   252,    -1,
     357,    -1,   356,   260,   357,    -1,   343,    -1,   359,    -1,
     255,   256,    -1,   255,   360,   256,    -1,   240,   255,   360,
     256,    -1,   343,   241,   255,   360,   256,    -1,   357,    -1,
     255,     8,   256,    -1,     5,    -1,   240,   359,    -1,   343,
     241,   359,    -1,   343,     8,   343,    -1,   343,     8,   343,
       8,   343,    -1,    99,   255,   343,   256,    -1,    99,   255,
       8,   256,    -1,    99,     5,    -1,   309,   255,     8,   256,
      -1,   309,     5,    -1,   135,   308,   358,    -1,   138,   308,
     357,    -1,   308,   189,    65,   255,   343,   260,   343,   260,
     343,   260,   343,   260,   343,   260,   343,   256,    -1,    65,
     308,   255,   360,   256,    -1,    74,   309,   255,   343,   256,
      -1,    75,   309,   255,   343,   256,    -1,   312,    -1,   323,
      -1,   332,    -1,   374,   285,   286,    -1,   374,   257,   351,
     285,   286,    -1,   374,     9,   374,   257,   351,   285,   286,
      -1,    39,   253,   374,   254,    -1,    39,   253,   359,   254,
      -1,    39,   251,   359,   252,    -1,    39,   285,   255,   360,
     256,   286,    -1,   374,   285,   255,   360,   256,   286,    -1,
      40,   285,   343,   260,   343,   260,   343,   286,    -1,    41,
     285,   343,   260,   343,   260,   343,   286,    -1,    42,   285,
     364,   286,    -1,    43,   285,   343,   260,   343,   260,   343,
     260,   343,   260,   343,   260,   343,   286,    -1,   209,   285,
     359,   286,    -1,    32,   285,   359,   286,    -1,   343,    -1,
     359,    -1,   360,   260,   343,    -1,   360,   260,   359,    -1,
     255,   343,   260,   343,   260,   343,   260,   343,   256,    -1,
     255,   343,   260,   343,   260,   343,   256,    -1,   374,    -1,
       4,   257,   186,   257,     4,    -1,   255,   363,   256,    -1,
     374,   253,   343,   254,   257,   187,    -1,   361,    -1,   363,
     260,   361,    -1,   365,    -1,   374,    -1,   374,   253,   343,
     254,    -1,   374,   251,   343,   252,    -1,   374,   257,   351,
      -1,   374,     9,   374,   257,   351,    -1,   374,   257,   351,
     251,   343,   252,    -1,   374,     9,   374,   257,   351,   251,
     343,   252,    -1,   374,   253,   343,   254,   257,     4,    -1,
     308,   255,   343,   256,    -1,   135,   308,   255,   343,   256,
      -1,     5,    -1,   222,   253,   374,   254,    -1,    68,    -1,
     220,    -1,    76,    -1,    78,    -1,   206,   251,   364,   252,
      -1,   205,   251,   364,   260,   364,   252,    -1,   207,   285,
     364,   286,    -1,   207,   285,   364,   260,   364,   286,    -1,
     216,   251,   350,   347,   252,    -1,   216,   251,   350,   257,
     351,   347,   252,    -1,    49,   285,   371,   286,    -1,    50,
     251,   364,   252,    -1,    51,   251,   364,   252,    -1,    52,
     251,   364,   260,   364,   260,   364,   252,    -1,    47,   285,
     371,   286,    -1,    61,   285,   364,   286,    -1,    62,   285,
     364,   286,    -1,    63,   285,   364,   286,    -1,    60,   285,
     343,   260,   364,   260,   364,   286,    -1,    55,   285,   364,
     260,   343,   260,   343,   286,    -1,    55,   285,   364,   260,
     343,   286,    -1,    48,   285,   364,   286,    -1,    48,   285,
     364,   260,   360,   286,    -1,    69,   285,   364,   286,    -1,
      70,    -1,    71,    -1,    54,   285,   364,   286,    -1,    53,
     285,   364,   286,    -1,    -1,    95,   285,   365,   366,   299,
     286,    -1,    92,   285,   367,   286,    -1,   258,   343,    -1,
     374,     9,   258,   343,    -1,    47,   285,   370,   286,    -1,
     371,    -1,   370,    -1,   255,   371,   256,    -1,   364,    -1,
     372,    -1,   371,   260,   364,    -1,   371,   260,   372,    -1,
     374,   251,   252,    -1,   374,   257,   351,   251,   252,    -1,
     374,     9,   374,   257,   351,   251,   252,    -1,     4,   259,
     255,   343,   256,    -1,   373,   259,   255,   343,   256,    -1,
     223,   253,   364,   254,   259,   255,   343,   256,    -1,     4,
      -1,   373,    -1,   223,   253,   364,   254,    -1
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
    1388,  1415,  1417,  1420,  1422,  1426,  1427,  1431,  1443,  1456,
    1471,  1480,  1493,  1495,  1499,  1500,  1505,  1513,  1522,  1530,
    1544,  1562,  1566,  1573,  1582,  1585,  1591,  1595,  1607,  1610,
    1617,  1620,  1626,  1649,  1665,  1681,  1698,  1715,  1752,  1796,
    1812,  1828,  1860,  1876,  1893,  1909,  1959,  1977,  1983,  1989,
    1996,  2027,  2042,  2064,  2087,  2110,  2133,  2157,  2181,  2205,
    2231,  2248,  2264,  2282,  2300,  2312,  2326,  2325,  2355,  2357,
    2359,  2361,  2363,  2371,  2373,  2375,  2377,  2385,  2387,  2389,
    2397,  2399,  2401,  2403,  2413,  2429,  2445,  2461,  2477,  2493,
    2510,  2547,  2569,  2593,  2594,  2599,  2602,  2606,  2623,  2643,
    2663,  2682,  2709,  2728,  2749,  2764,  2780,  2798,  2849,  2870,
    2892,  2915,  3020,  3036,  3071,  3093,  3115,  3127,  3133,  3148,
    3176,  3188,  3197,  3204,  3216,  3236,  3240,  3245,  3249,  3254,
    3261,  3268,  3275,  3287,  3360,  3378,  3403,  3418,  3451,  3463,
    3495,  3499,  3504,  3511,  3516,  3526,  3531,  3537,  3545,  3549,
    3553,  3557,  3561,  3565,  3569,  3578,  3642,  3658,  3675,  3692,
    3714,  3736,  3771,  3779,  3787,  3793,  3800,  3807,  3827,  3853,
    3865,  3876,  3894,  3912,  3931,  3930,  3955,  3954,  3981,  3980,
    4005,  4004,  4027,  4043,  4060,  4077,  4100,  4128,  4131,  4137,
    4149,  4169,  4173,  4177,  4181,  4185,  4189,  4193,  4197,  4206,
    4219,  4220,  4221,  4222,  4223,  4227,  4228,  4229,  4230,  4231,
    4234,  4258,  4277,  4300,  4303,  4319,  4322,  4339,  4342,  4348,
    4351,  4358,  4361,  4368,  4390,  4431,  4475,  4514,  4539,  4551,
    4563,  4575,  4587,  4604,  4621,  4651,  4677,  4703,  4735,  4762,
    4788,  4814,  4840,  4866,  4888,  4899,  4947,  5001,  5016,  5028,
    5039,  5046,  5061,  5075,  5076,  5077,  5081,  5087,  5099,  5117,
    5145,  5146,  5147,  5148,  5149,  5150,  5151,  5152,  5153,  5160,
    5161,  5162,  5163,  5164,  5165,  5166,  5167,  5168,  5169,  5170,
    5171,  5172,  5173,  5174,  5175,  5176,  5177,  5178,  5179,  5180,
    5181,  5182,  5183,  5184,  5185,  5186,  5187,  5188,  5189,  5190,
    5191,  5192,  5193,  5194,  5195,  5196,  5197,  5206,  5207,  5208,
    5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,  5221,  5220,
    5228,  5230,  5235,  5240,  5244,  5249,  5254,  5258,  5262,  5266,
    5270,  5274,  5278,  5284,  5299,  5303,  5309,  5314,  5333,  5353,
    5384,  5388,  5392,  5396,  5400,  5404,  5408,  5413,  5423,  5433,
    5438,  5449,  5458,  5463,  5468,  5496,  5497,  5503,  5504,  5510,
    5509,  5532,  5534,  5539,  5548,  5550,  5556,  5557,  5562,  5566,
    5570,  5574,  5578,  5585,  5589,  5593,  5597,  5604,  5609,  5616,
    5621,  5625,  5630,  5634,  5642,  5653,  5657,  5661,  5675,  5683,
    5691,  5698,  5708,  5731,  5736,  5742,  5747,  5753,  5764,  5770,
    5776,  5782,  5794,  5808,  5818,  5828,  5838,  5850,  5854,  5859,
    5871,  5875,  5879,  5883,  5901,  5909,  5917,  5946,  5956,  5972,
    5983,  5988,  5992,  5996,  6008,  6012,  6024,  6041,  6051,  6055,
    6070,  6075,  6082,  6086,  6091,  6105,  6121,  6125,  6129,  6133,
    6137,  6145,  6151,  6160,  6164,  6168,  6176,  6182,  6188,  6192,
    6200,  6208,  6215,  6224,  6228,  6232,  6247,  6261,  6275,  6287,
    6303,  6312,  6321,  6331,  6342,  6350,  6358,  6362,  6381,  6388,
    6394,  6400,  6407,  6415,  6414,  6424,  6448,  6450,  6456,  6461,
    6463,  6468,  6473,  6478,  6480,  6484,  6496,  6510,  6514,  6521,
    6529,  6537,  6548,  6550,  6553
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
     268,   268,   268,   268,   268,   268,   268,   269,   269,   270,
     270,   272,   273,   271,   274,   274,   276,   275,   277,   277,
     279,   278,   280,   280,   282,   281,   283,   283,   283,   283,
     283,   284,   284,   285,   285,   286,   286,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   288,   289,   289,   289,   290,
     289,   291,   289,   289,   292,   289,   293,   293,   294,   294,
     294,   295,   295,   296,   296,   297,   297,   298,   298,   298,
     298,   298,   299,   299,   300,   300,   301,   301,   301,   301,
     301,   302,   302,   302,   303,   303,   303,   303,   304,   304,
     305,   305,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   307,   306,   308,   308,
     308,   308,   308,   309,   309,   309,   309,   310,   310,   310,
     311,   311,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   313,   313,   314,   314,   314,   314,   314,
     314,   314,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   316,   316,   316,   316,   316,   316,
     316,   316,   317,   317,   318,   319,   319,   319,   319,   319,
     319,   319,   319,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   321,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   323,   323,   323,   324,   323,   325,   323,   326,   323,
     327,   323,   323,   323,   323,   323,   323,   328,   328,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   330,   330,   330,   330,   331,   331,   331,   331,   331,
     332,   332,   333,   334,   334,   335,   335,   336,   336,   337,
     337,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     340,   340,   340,   341,   341,   341,   342,   342,   342,   342,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   345,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   346,   346,   347,   347,   349,
     348,   350,   350,   351,   352,   352,   353,   353,   354,   354,
     354,   354,   354,   355,   355,   355,   355,   356,   356,   357,
     357,   357,   357,   357,   357,   358,   358,   358,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     360,   360,   360,   360,   361,   361,   361,   361,   362,   362,
     363,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   366,   365,   365,   367,   367,   368,   369,
     369,   370,   371,   371,   371,   371,   372,   372,   372,   373,
     373,   373,   374,   374,   374
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
       5,     0,     2,     0,     1,     1,     3,     2,     1,     4,
       2,     2,     0,     2,     1,     3,     2,     2,     2,     2,
       2,     1,     1,     3,     0,     5,     5,     5,     0,     2,
       0,     2,     7,     7,     7,    10,    10,     8,     8,     7,
       7,    11,     7,     8,     8,     8,     9,     3,     4,    10,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       9,     7,     7,     8,     8,    12,     0,     9,     1,     1,
       1,     1,     4,     1,     1,     1,     4,     1,     1,     4,
       1,     1,     1,     4,     5,    11,     5,     9,     9,     7,
       4,     9,     9,     1,     1,     0,     2,     6,     7,     7,
       6,     7,     8,    10,    14,    16,    12,    14,    14,    14,
      14,     8,     8,     6,     4,     5,     5,     6,     6,     3,
       4,     3,     5,     6,     5,     4,     3,     4,     3,     4,
       5,     4,     5,     3,     5,     7,     7,     3,     7,     3,
       2,     2,     2,     2,     2,    15,     2,     2,     2,     9,
      11,     2,     2,     2,     2,    16,    11,     6,     8,     8,
      10,     1,     2,     2,     1,     3,     3,     4,     4,     1,
       1,     5,    11,    13,     0,     7,     0,    13,     0,    15,
       0,     6,     9,     2,     3,    10,    13,     1,     2,     5,
       7,     2,     2,     3,     2,     3,     2,     3,     9,     6,
       1,     1,     1,     1,     1,     0,     2,     3,     3,     4,
       9,     4,    14,     0,     3,     0,     1,     0,     2,     0,
       2,     0,     2,     6,     7,     6,     5,     3,     8,     8,
       8,     8,     8,     8,     5,     4,     6,    11,    11,    18,
      18,    12,    12,    12,    10,     4,     4,     4,     4,     4,
       2,     3,     6,     1,     1,     1,     2,     5,     7,    10,
       1,     3,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       1,     4,     6,     1,     4,     4,     4,     6,     5,     7,
       8,    10,     4,     4,     6,     4,     3,     2,     5,     5,
       3,     5,     6,     8,     6,     8,     6,     4,     7,     6,
       6,     6,     4,     6,     4,     0,     2,     0,     2,     0,
       7,     1,     3,     1,     1,     2,     0,     3,     1,     2,
       2,     3,     3,    11,     9,     7,     7,     1,     3,     1,
       1,     2,     3,     4,     5,     1,     3,     1,     2,     3,
       3,     5,     4,     4,     2,     4,     2,     3,     3,    16,
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
       0,     0,     0,     2,     3,     1,   622,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
       0,     0,   199,     0,     0,   200,     0,   201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   330,   331,   332,   333,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   291,
       0,     0,   299,   300,     0,     0,     0,   294,     0,     0,
       0,     0,     0,   383,   384,   385,     0,     0,     5,     6,
       7,     8,    10,     0,    11,    24,    12,    13,    14,    15,
      23,    22,    21,    16,     0,    17,    18,    19,    20,     0,
      25,     0,   623,     0,   225,     0,     0,     0,     0,     0,
       0,   274,     0,   276,   277,   272,   273,     0,   278,   281,
       0,   282,   283,   116,   126,   622,   496,   491,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   284,     0,
     210,   211,   212,     0,     0,     0,     0,   437,   438,   440,
     441,   439,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   445,   446,
     447,     0,     0,   198,   203,   204,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   442,   443,
     444,     0,     0,     0,     0,     0,     0,     0,     0,   533,
     534,     0,   535,   509,   390,   450,   453,   313,   510,   491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     199,   200,   201,   196,   203,   204,     0,   205,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   498,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,     0,   225,     0,     0,
     380,     0,     0,     0,   207,   208,     0,     0,     0,     0,
       0,     0,   517,     0,     0,   515,     0,     0,     0,     0,
       0,   622,     0,     0,   556,     0,     0,     0,     0,   270,
     271,     0,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   575,     0,   599,   600,
     577,   578,     0,     0,     0,     0,     0,     0,   576,     0,
       0,     0,     0,   292,   293,     0,   225,     0,   225,     0,
       0,     0,   491,     0,     0,     0,   225,   386,     0,     0,
      79,     0,    66,     0,     0,    70,    69,    68,    67,    72,
      71,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     562,   491,     0,   224,     0,   223,     0,   177,     0,     0,
     562,   563,     0,     0,     0,   612,     0,   613,   563,     0,
     114,   114,     0,   489,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,   551,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   393,     0,   392,   518,   394,     0,   511,
       0,     0,   491,     0,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
     467,     0,     0,     0,     0,     0,     0,     0,   314,     0,
     347,   347,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,   225,   225,     0,   500,   499,
       0,     0,     0,     0,   225,   225,     0,     0,     0,     0,
     310,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,     0,     0,     0,     0,
     225,   251,     0,     0,   249,   381,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   269,     0,
       0,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   296,   295,     0,   256,     0,     0,   258,     0,     0,
       0,   392,     0,   225,     0,     0,     0,     0,     0,     0,
       0,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    75,    76,     0,     0,     0,
     267,    40,   263,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,   226,     0,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,     0,     0,     0,
     494,     0,     0,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   341,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,   376,   377,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,   466,     0,     0,     0,     0,   527,   528,     0,     0,
       0,     0,     0,   485,     0,   391,   512,     0,     0,     0,
       0,   520,     0,   410,   409,   408,   407,   403,   404,   411,
     412,   406,   405,   396,   395,     0,   397,   519,   398,   401,
     399,   400,   402,   492,     0,     0,   493,   470,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,   345,     0,
       0,     0,     0,     0,     0,   379,     0,     0,     0,     0,
     378,     0,   225,     0,     0,     0,     0,     0,   502,   501,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,     0,     0,   250,     0,     0,     0,   244,     0,
       0,     0,     0,   375,     0,     0,     0,     0,   391,   516,
       0,     0,     0,     0,     0,     0,     0,     0,   297,   298,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   603,     0,
       0,     0,   487,     0,     0,   255,   259,   257,   261,     0,
     397,     0,   492,   470,   624,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,   391,     0,    66,
       0,     0,     0,     0,    82,     0,    66,    67,     0,     0,
       0,   492,     0,     0,   470,     0,     0,     0,   196,     0,
       0,     0,   619,    28,    26,    27,     0,     0,     0,     0,
       0,   493,   566,    30,     0,    29,     0,     0,   264,   614,
     615,     0,   616,   566,     0,    77,   117,    78,   127,   495,
     497,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   552,
     553,   213,     9,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   436,   423,     0,   425,   426,   427,   428,   429,
     549,   430,   431,   432,     0,     0,     0,   541,   540,   539,
       0,     0,     0,   546,     0,   482,     0,     0,     0,   484,
       0,     0,     0,   131,   465,   523,   522,   206,     0,     0,
     451,   548,   456,     0,   462,     0,     0,     0,     0,   513,
       0,     0,   463,     0,   525,     0,     0,     0,     0,   455,
     454,   477,    73,    74,     0,     0,     0,     0,     0,     0,
       0,   391,   343,   348,   346,     0,   356,     0,   151,   152,
       0,   206,     0,   391,     0,     0,     0,     0,   245,     0,
     260,   262,     0,     0,     0,   214,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   317,     0,
     301,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,   350,   364,     0,     0,     0,   246,     0,
       0,     0,     0,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   589,     0,
     596,   585,   586,   587,     0,   602,   601,     0,     0,   590,
     591,   592,   598,   606,   605,     0,   142,     0,   579,     0,
     581,     0,     0,     0,   574,     0,   254,     0,     0,     0,
       0,     0,     0,     0,   336,     0,     0,     0,   387,     0,
     620,     0,   104,    66,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,     0,     0,     0,
     571,    51,     0,     0,     0,    64,     0,    41,    42,    43,
      44,    45,    46,     0,   455,   454,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,   564,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,   134,   135,     0,     0,     0,     0,     0,     0,     0,
     158,   158,     0,     0,     0,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   530,   531,   532,     0,     0,     0,     0,     0,   485,
     486,     0,   458,     0,     0,     0,   521,   413,   514,   471,
     469,     0,   468,     0,     0,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   253,     0,     0,     0,     0,
       0,     0,     0,   322,     0,     0,   321,     0,   324,     0,
     326,     0,   311,   318,     0,     0,     0,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,     0,   248,
     247,   382,     0,     0,     0,    37,    38,     0,     0,     0,
       0,   557,     0,     0,     0,   287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
     488,   583,     0,   471,     0,     0,   225,   337,     0,   338,
     225,     0,     0,   572,     0,    89,     0,     0,     0,     0,
      87,    94,    96,     0,   560,     0,   102,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,    36,   471,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,     0,   567,     0,     0,    34,    33,     0,
     567,   617,     0,     0,   118,   123,     0,     0,     0,   137,
     140,   141,   490,     0,    80,     0,     0,     0,     0,    81,
     162,     0,     0,     0,     0,   163,   180,   181,   160,     0,
       0,     0,   164,   191,   182,   186,   187,   183,   184,   185,
     172,     0,     0,   424,   433,   434,   435,   542,     0,     0,
       0,   480,   481,   483,   132,   449,   479,   452,   457,     0,
       0,   485,   192,   464,     0,    73,    74,     0,   476,   472,
     474,   543,   188,     0,     0,     0,   154,     0,     0,   354,
       0,   153,     0,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,   225,   225,     0,     0,   323,   509,     0,
       0,   325,   327,     0,     0,   305,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   189,     0,     0,
       0,     0,     0,   169,   170,     0,     0,     0,     0,   105,
     106,   107,   111,     0,   597,     0,     0,   595,     0,   607,
       0,     0,   143,   144,   604,   580,   582,     0,     0,     0,
       0,     0,     0,   335,   339,   335,     0,   388,    88,    66,
       0,     0,     0,     0,    86,     0,   558,     0,     0,     0,
       0,     0,     0,   610,   609,     0,     0,     0,     0,     0,
     507,     0,     0,   476,   265,   472,   266,     0,     0,     0,
       0,     0,   230,   227,     0,     0,   570,   568,     0,     0,
       0,     0,   119,   124,     0,     0,     0,   550,   551,   136,
     358,   359,   360,   361,   159,   167,   168,   173,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
     459,     0,     0,     0,     0,   538,   478,     0,     0,   174,
       0,   193,   344,     0,     0,     0,     0,   194,     0,     0,
       0,     0,     0,     0,   506,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   242,   241,     0,     0,
       0,     0,     0,     0,     0,     0,   232,     0,     0,   362,
     363,    39,     0,   555,     0,     0,   289,   288,     0,     0,
       0,     0,     0,     0,   146,   147,   150,   149,   148,     0,
     584,     0,   621,     0,     0,     0,     0,     0,     0,    99,
       0,     0,   100,   561,     0,     0,     0,    91,     0,     0,
       0,    47,     0,     0,     0,     0,     0,    49,     0,   231,
     228,   229,    35,     0,     0,   618,   279,     0,   131,   142,
       0,     0,   139,     0,     0,     0,   161,   190,     0,     0,
       0,     0,     0,   544,   545,     0,   485,   460,     0,   473,
     475,     0,     0,   176,   197,     0,     0,     0,   351,   351,
       0,   112,   113,   225,     0,   217,   218,   312,     0,   319,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   221,     0,     0,     0,     0,   108,   109,   588,
     594,   593,   145,     0,     0,     0,   340,     0,    95,    97,
       0,   103,     0,    85,   611,    92,    93,    52,     0,     0,
       0,     0,   508,     0,     0,   473,   569,     0,     0,     0,
       0,   121,   608,     0,   128,     0,     0,     0,     0,   179,
       0,     0,     0,     0,   315,     0,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
     329,     0,     0,   306,     0,   233,     0,     0,     0,     0,
       0,     0,     0,   554,   290,     0,     0,   374,   225,   389,
       0,   559,     0,    48,     0,     0,     0,    65,    50,     0,
     280,   120,   125,   131,     0,     0,   156,   157,   155,     0,
       0,   461,     0,     0,     0,     0,     0,   352,   367,     0,
       0,   368,     0,   215,     0,   320,     0,   302,     0,   225,
       0,     0,     0,     0,     0,     0,   171,   110,   286,   335,
     101,     0,     0,     0,     0,     0,     0,   129,   130,     0,
       0,     0,     0,   195,     0,   371,     0,   372,   373,   503,
       0,     0,   308,   236,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,    62,     0,     0,   122,     0,     0,
       0,   316,     0,     0,   328,   307,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,   234,   342,    53,     0,    60,     0,   275,     0,   547,
       0,     0,     0,   309,     0,     0,    54,     0,     0,   285,
       0,     0,     0,   235,     0,     0,     0,     0,   529,     0,
       0,    57,    55,     0,    58,     0,   369,   370,     0,     0,
      63,    61,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,  1076,   119,   120,  1060,  1920,  1926,
    1357,  1572,  2082,  2215,  1358,  2186,  2233,  1359,  2217,  1360,
    1361,  1576,   444,   600,   601,  1149,   121,   787,   470,  1938,
    2093,  1939,   471,  1806,  1435,  1390,  1391,  1392,  1536,  1742,
    1743,  1217,  1631,  1622,  1819,   764,   612,   277,   278,   357,
     204,   279,   454,   455,   125,   126,   127,   128,   129,   130,
     131,   132,   280,  1251,  2118,  2177,   955,  1247,  1248,   281,
    1039,   282,   136,  1464,  1215,   928,   970,  2052,   137,   138,
     139,   140,   283,   284,  1173,  1188,  1313,   285,   792,   286,
     917,   791,   473,   629,   325,  1779,   365,   366,   288,   570,
     373,  1344,  1565,   465,   460,  1306,  1016,  1611,  1772,  1773,
    1001,   467,   142,   422
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1905
static const yytype_int16 yypact[] =
{
   13162,    64,    50, 13325, -1905, -1905,   -77,    71,     1,  -119,
     -95,    -6,    13,   232,   248,   251,   257,    29,   293,   302,
      74,   313,   318,    83,    89,    39,  -112,   135,  -112,   100,
     112,   117,    53,   130,   144,    59,   154,   181,   221,   226,
     235,   245,   279,   282,   376,   381,   180,   325,   317,   643,
     294,   543,   545,   408,  7040,   432,   441,   447,   606,   -61,
     413,   390,   312,    85,   468,   627,  -111,   499,   -40,   -40,
     507,   411,    82,   527, -1905, -1905, -1905, -1905, -1905,   490,
     461,   733,   741,    20,    56,   748,   766,   539,   798,   906,
     907,   924,  6044,   935,   713,   735,   751,    23,    61, -1905,
     762,   769, -1905, -1905,  1011,  1015,   771, -1905,  1583,   774,
    2637,    24,    31, -1905, -1905, -1905, 12018,   773, -1905, -1905,
   -1905, -1905, -1905,   772, -1905, -1905, -1905, -1905, -1905, -1905,
   -1905, -1905, -1905, -1905,   -42, -1905, -1905, -1905, -1905,    47,
   -1905,  1023,   776,  5793,   329,   775,  1025, 12018, 13505, 13505,
   13505, -1905, 12018, -1905, -1905, -1905, -1905, 13505, -1905, -1905,
   12018, -1905, -1905, -1905, -1905,   777,   781,  1024, -1905, -1905,
    5891,   786,   787,   789,   790,    39, 12018, 12018, 12018,   791,
   12018, 12018, 12018,   793, 12018, 12018, 12018, 12018, 12018, 12018,
   12018, 13505, 12018, 12018, 12018, 12018,  6044,   794, -1905,  9769,
   -1905, -1905, -1905,   792,  6044,  7289, 13505, -1905, -1905, -1905,
   -1905, -1905,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,   469,  -112,  -112,  -112,  -112,
    -112,   795,  -112,  -112,   797,   390,   551,   551, -1905, -1905,
   -1905,  -112,  -112,    35,   860,   862,   863,   799,  7289,   925,
     390,   390,   805,  -112,  -112,   806,   809,   810, -1905, -1905,
   -1905, 12018,  7538, 12018, 12018,  7787,    39,   876,    41, -1905,
   -1905,   812, -1905,  1115, -1905, -1905, -1905, -1905, -1905,    52,
   12018,  9769,  9769,   818,   819,  8036,  6044,  6044,  6044, -1905,
   -1905, -1905, -1905, -1905, -1905, -1905,   820, -1905,   817,   823,
    8285,   821,  4870,  1071,  7289,   822,    23,   824,   826,   -40,
     -40,   -40, 12018, 12018,   -90, -1905,   -72,   -40, 10692,   200,
     363,   827,   831,   833,   834,   835,   836,   837,  9769, 12018,
    6044,  6044,  6044,   838,    11,  1084,   840, -1905,  1085,  1088,
   -1905,   841,   842,   843, -1905, -1905,   845,  6044,   846,   849,
     850,   851, -1905, 12018,  6293, -1905,  1099,  1102, 12018, 12018,
   12018,   592, 12018,   857, -1905,   937, 12018, 12018, 12018, -1905,
   -1905, 12018, -1905,  -112,  -112,  -112,   877,   878,   879,  -112,
    -112,  -112,  -112,  -112,  -112,  -112, -1905,  -112, -1905, -1905,
   -1905, -1905,  -112,  -112,   881,   882,  -112,   883, -1905,   874,
    1148,  1149,   901, -1905, -1905,  1151,  1152,  1153,  1154,  -112,
   12018, 10977,   125, 13505,  9769, 12018, -1905, -1905,  7289,  7289,
   -1905,   929,  5891,   390,  1178, -1905, -1905, -1905, -1905, -1905,
   -1905, 12018, 12018,    38,  7289,  1155,   553,   931,   908,   934,
    1184,    95,   936, -1905,   939, 13632, 12018, -1905,   938,  -144,
   -1905,    69,  -124,    93,  6975, -1905,   110, -1905,    70,  7224,
    -159,  -117,  1098, -1905,    39,   933, 12018, 12018, 12018, 12018,
     941, 15547, 15572, 15597, 12018, 15622, 15647, 15672, 12018, 15697,
   15722, 15747, 15772, 15797, 15822, 15847,   942, 15872, 15897, 15922,
   14188,  1189, 12018,  9769,  4503, -1905,   452, 12018,  1191,  1192,
     947, 12018, 12018, 12018, 12018, 12018, 12018, 12018, 12018, 12018,
   12018, 12018, 12018, 12018, 12018, 12018, 12018,  9769, 12018, 12018,
   12018, 12018, 12018, 12018,  9769,  9769,   951, 12018, 12018, 13505,
   12018, 13505,  7289, 13505, 13505, 13505,   952,   953,   954, 12018,
      33, -1905, 10776, 12018,  7289,  6044,  7289, 13505, 13505,  9769,
      39,  5891,    39,   960,  9769,   960, -1905,   960, 15947, -1905,
     486,   945,    81,  1146, -1905,  1204, 12018, 12018, 12018, 12018,
   12018, 12018, 12018, 12018, 12018, 12018, 12018, 12018, 12018, 12018,
    8534, 12018, 12018, 12018, 12018, 12018,    39, 12018, 12018,  1211,
   -1905,   760, 15972,   492,   493, 12018, 12018, 12018, -1905,  1209,
    1210,  1210,   967, 12018, 12018, 12018, 12018,  1213,  9769,  9769,
   11312,   968,  1215, -1905,   970, -1905, -1905,  -167, -1905, -1905,
    7473,  7722,   -40,   -40,   329,   329,  -130, 10692, 10692, 12018,
    4538,  -127, -1905, 12018, 12018, 12018, 12018, 12018, 12018, 12018,
   12018, 12018,   495, 15997,  1219,  1216,  1220, 12018,  1222, 12018,
   -1905, -1905, 12018,  4668, -1905, -1905,  9769,  9769,  9769, 12018,
    1224,  9769, 12018, 12018, 12018, 16022,   975, -1905, -1905, 16047,
   16072, 16097,  1046,  7971, -1905,   978,  4602, 16122, 16147, 15142,
   13505, 13505, 13505, 13505, 13505, 13505, 13505, 13505, 13505, 12018,
   13505, 13505, 13505, 13505,    16,  5891, 13505, 13505, 13505,    39,
      39, -1905, -1905,  9769, -1905,   979, 12266, -1905,   980, 12375,
   12018,   960, 12018, -1905,    39, 12018, 12018,  1211,   983,   500,
   16172, 13526,   982,   501, 12018,  1232,   984,  7289, 16197, 15169,
     131,   985,  1233,  1235, -1905, -1905, -1905,  9769,   173, 12018,
   -1905, -1905, -1905,    39, 12018, 12018,  1211,   990, -1905,   994,
     -60,   390,   312,   390, -1905,   995, 14217, -1905,    17,  9769,
      39, 12018, 12018,  1245,  1246,  9769,  1247,  9769, 12018,  1248,
   13505,    39, 11020,  1245, 12018,  1250, -1905,    39,  1251, 13505,
   12018,  1006,  1008, -1905, 12018,  8220,  8469,  8718,  8962,  5891,
    1255,  1256,  1257, 16222,  1259,  1260,  1261, 16247,  1262,  1263,
    1264,  1265,  1266,  1267,  1271, -1905,  1273,  1274,  1275, -1905,
   12018, 16272,  9769,  1028,  9769, 14246, -1905, -1905,  1278, 15115,
   15115, 15115, 15115, 15115, 15115, 15115, 15115, 15115, 15115, 15115,
    9206, 15115, 15115, 15115, 15115,   646,   430, 15115, 15115, 15115,
    9455,  9704, 10044,  4503,  1033,  1034,   118,  9769, 10386, 10642,
     430, 10723,   430,  1029,  1030,  1032,   230,  9769, 12018, 12018,
   17222, -1905,   430,  1037, 14275, 14304, -1905, -1905,  1036,   207,
     430,  -198,  1042,   227,   503,  1290, -1905,  1245,   430,  1044,
    1045,  4779,  4966,  1506,  1761,  1690,  1690,   431,   431,   431,
     431,   431,   431,   473,   473,  9769,   483, -1905,   483,   483,
     960,   960,   960,  1043, 16297, 15196,   164,   479,  9769, -1905,
    1295,  1048,  1050, 16322, 16347, 16372, 12018,  7289,  1303,  1302,
   10448, 16397, 14333, 16422, 16447, -1905,   508,   509,  9769,  1053,
   -1905, 12444, -1905, 12550, 12608,   -40, 12018, 12018, -1905, -1905,
    1056,  1057, 10692,  5479,  1175,   344,   -40, 12667, 16472, 14362,
   16497, 16522, 16547, 16572, 16597, 16622, 16647,  1060,  1309, 12018,
    1311, -1905, 12018, 16672, -1905, 15223, 12725, 15250, -1905,   520,
     523,   525, 14391, -1905,   550, 15277, 15304, 11051, -1905, -1905,
    1312,  1313,  1314,  1061, 12018, 12784, 12018, 12018, -1905, -1905,
      40,   267,   338,   267,  1070,  1073,  1063,   430,   430,  1066,
   11386,   430,   430,   430,   430, 12018,   430,  1319, -1905,  1069,
    1078,   369,  -135,  1077,   557, -1905, -1905, -1905, -1905, 15115,
     483, 12842,  1075,   641,  1074,  1147,  1328,  1177, 11111,  1082,
    1109,  1360,  7289, 14420, -1905, 12018,  1362,   159,    34,  5891,
   12018,  1364,  1367,    26, -1905,   558,  1325,  1326,  7289, 14449,
      28,  1117, 16697, 15331,   -82, 12018, 12018,  1124,  1121,  1126,
    1123,  8783, -1905, -1905, -1905, -1905, 13505,   277,  1125, 16722,
   15358, -1905,  1129, -1905,   298, -1905,   365, 11640, -1905, -1905,
   -1905,  1127, -1905,  1130, 11721, -1905,    14, -1905, -1905, 17222,
   -1905,  1379, 15115, 12018, 12018, 12018, 12018,   430,   -40,  7289,
    7289,  1378,  7289,  7289,  7289,  1380,  7289,  7289,  7289,  7289,
    7289,  7289,  7289,  7289,  7289,  7289,  1194,  1381,  9769,  4503,
   -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905,
   -1905, -1905, -1905, -1905, 12018, -1905, -1905, -1905, -1905, -1905,
   -1905, -1905, -1905, -1905, 12018, 12018, 12018, -1905, -1905, -1905,
     564, 12018, 12018, -1905, 12018, -1905,  7289, 13505, 13505, -1905,
     566, 14478, 14507,  1131, -1905, -1905, -1905,  1200, 12018, 12018,
   -1905, -1905, -1905,  1245, -1905,  1245, 12018, 12018,  1138, -1905,
    7289,  -112, -1905, 12018, -1905, 12018, 12018,   567,  1245,   164,
     -13, -1905, 12018, 12018,   430,   572,  7289,  9769,  9769,  1385,
    1386,  1387,  2141, -1905, -1905,  1389, -1905,  1144, 17222,  1137,
    1391, -1905,  1393,  1394,  1395,  1397,   573,  1401, -1905, 12901,
   -1905, -1905,  -125, 11974, 12195, -1905, -1905, 14536,   -79,  1289,
    1403, 11355,  1156,  1402,  1158,    49,    58,   -70, -1905,   171,
   -1905,   344,  1405,  1404,  1406,  1407,  1409,  1410,  1411,  1412,
    1433,   329,  7289, 17222, -1905,  1305,  1186,  1436, -1905,  1437,
    1439,  1341,  1440, -1905,  1441,  1443,  1444, 12018,  7289,  7289,
    7289,  1447, 12373, -1905,  5246,   739,    67,  1449, -1905,  9769,
   -1905, -1905, -1905, -1905, 13505, -1905, -1905, 12018, 13505, -1905,
   -1905, -1905, -1905, 17222, -1905,  1196,  1195, 13505, -1905, 13505,
   -1905,  1245, 13505,  1208, -1905,  1201, -1905,  1245, 12018, 12018,
    1207,   390,  1214, 11446, -1905,  1792,  1217,  7289, -1905,  1212,
   -1905, 14565, -1905, -1905, 12018,  1450,    44, 12018,  1457,  1458,
    1846, -1905,  1466,    23,  1468,  1223,   430,  -112,  -112,  1469,
   -1905, -1905,  1226,  1227,  1225, -1905,  1473, -1905, -1905, -1905,
   -1905, -1905, -1905,  1245,   388,  3465, 12018, 15385, 16747, 12018,
    9027, 12018,  9769,  1228,   574,  1475,   153,  1245, -1905,  1229,
   12018,  1477,  1479, 12018,  1245, 11690, 12018, 10013,   430,  5210,
    1234,  1230, -1905,  1481, 16772, 16797, 16822, 16847,  1483,    75,
    1359,  1359,  7289,  1486,  1488,  1489,  7289,  -101,  1490,  1491,
    1492,  1493,  1494,  1496,  1497,  1498,  1500, -1905,  1502,   575,
   15115, 15115, 15115, 15115,   430, 12952, 13561, 13594,  1258,   430,
     430, -1905, -1905, -1905,  1379,   430, 16872, 15115,  1268,  -177,
   17222, 15115, -1905,  1503,   430, 13627, 17222, 17222, -1905,   712,
   -1905,  1504, -1905, 16897, 15412, -1905,   430,  1505,   580,   585,
    7289,  7289,  7289,  1508,  1507, -1905,   177, 12018,  7289,  7289,
    7289,  1269,  1270,  1510,   589, -1905, 12018, 12018, 12018,  1276,
    1296,  1297,  1277, -1905,  1905,  7289, -1905, 12018, -1905,  1509,
   -1905,  1512, -1905, -1905, 10692,   -15,  6542, -1905,  1298,  1299,
    1301,  1304,  1306,  1307,  9271,  1272,  1513, -1905,  9769, -1905,
   -1905, -1905,  1308, 12018, 12018, -1905, -1905, 15439,  1515,  1517,
    1329, -1905, 12018, 12018, 12018, -1905,  1520,  1523,  1551,   764,
     426,  1310,  5276,  1315, 12018,    27,   430,  1316,   430,  1318,
   -1905, -1905,  5891,   734, 12018,  1321, -1905, -1905,  2103, -1905,
   -1905,  1320,  1552, -1905,  2186, -1905,   167,  1317,  1557,  2362,
   -1905, -1905, -1905,    23, -1905,   596, -1905, 12018,   177, 12065,
   12245, -1905,  1322, 12018, 12018,  7289,  1324, -1905,   -43,  1561,
    1563, 16922,  1565,  1290, 16947,  1327,   597, 16972,   599,  1575,
    1576, -1905, -1905, 13505,  1333,  1581, 16997, -1905, -1905, 13660,
    1335, -1905,  5979,  5544, 17222, -1905,  1582,  -112,  7787, -1905,
   -1905, -1905, -1905,  1379, -1905,  1585,  1586,  1587,  1588, -1905,
   -1905,   -40,  1589,  1590,  1592, -1905, -1905, -1905,  1460,   -41,
    1499,  1597, -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905,
   -1905,  1599,  1351, -1905, -1905, -1905, -1905, -1905, 12018, 12018,
   12018, -1905, -1905, -1905,  1230, -1905, -1905, -1905, -1905, 12018,
    1355,  1348, -1905, -1905, 12018, 12018, 12018,   430,   164, -1905,
   -1905, -1905, -1905,  1354,  1356,  1607,  -101,  1608, 12018, -1905,
    7289, 17222,  1478,  1480,  1012,  9769,  9769, 12018, -1905, 10448,
   14594, 17022,  6228,   329,   329, 12018, 12018, -1905,   341,  1358,
   17047, -1905, -1905, 14623,   184, -1905,  1610,  1614,  7289,   -40,
     -40,   -40,   -40,   -40,  6791,  1616, -1905, -1905,   602, 12018,
    2864,  2894,  1617, -1905, -1905,  7289,  6477,   559, 17072, -1905,
   -1905, -1905, -1905, 10106, -1905, 13505, 12018, -1905, 13505, 17222,
   10355,  5891,  1365, -1905, -1905, -1905, -1905,  1374,  1368, 12018,
   12018, 14652, 12018, 13526, -1905, 13526,  7289, -1905, -1905,  5891,
   12018,  1621,  1625,    26, -1905,  1633, -1905,    23, 15466,  7289,
   13505,  1634,   430, -1905,  1388,   430, 12018, 13693, 13726,   607,
   -1905, 12018, 12018,   476, -1905,  1392, -1905,  1387,  1635,  1643,
    1394,  1644, -1905, -1905,  1649, 12018, -1905, -1905, 12018, 11774,
    1650, 12018, -1905, -1905,  1414, 12245,   609,  4130,  1651, -1905,
   -1905, -1905, -1905, -1905,   768, -1905, -1905, -1905,  1514,  1654,
    1415,  1416,  1417, -1905,  1657,  7289, 15115, 15115, 13759, 15115,
   -1905,  1413, 13792, 17097, 15493, -1905, -1905,  9769,  9769, -1905,
    1658, -1905, 17222,  1660, 12018, 12018,  1419, -1905,   610,   612,
   15087,  2955,  1661,  1421, -1905, -1905, 12018,  1423,  1424, 14681,
   15520,  1675,  7289,  1677,  1430, 12018, -1905, -1905,   637,   194,
     210,   225,   263,   265,  9520,   274, -1905,  1680, 14710, -1905,
   -1905, -1905,  1516, -1905, 12018, 12018, -1905, -1905,  9769,  3154,
    1682,  1438, 15115,   430, 17222, -1905, -1905, -1905, -1905,    27,
   -1905,  5891, -1905, 14739,  1435,  1445,  1446,  1683,  3698, -1905,
    1685,  1687, -1905, -1905,  1442,  1688,   639, -1905,  1697,  1698,
     425, 17222, 12018, 12018,  1451,  7289,   645, 17222, 17122, -1905,
   -1905, -1905, -1905, 17147, 13825, -1905, -1905, 14768,  1131,  1195,
    7289,   430, -1905, 12018,  5891,    39, -1905, -1905,  9769,  9769,
   12018,  1702,   652, -1905, -1905, 12018,  1348, -1905, 12018, -1905,
   -1905,   657,   660, -1905, -1905,  3886,  3964,  7289,   593,   595,
    9769, -1905, -1905,   329,  6726, -1905, -1905, -1905,  1703, -1905,
    1454,  7289, -1905, 14797,  1707,  9769,   -40,   -40,   -40,   -40,
     -40, -1905, -1905, 12018, 14826, 14855,   662, -1905, -1905, -1905,
   -1905, -1905, -1905,  1464,  1711,  1463, -1905,  1713, -1905, -1905,
      23, -1905,  1533, -1905, -1905, -1905, -1905, -1905, 12018, 13858,
   13891,  7289, -1905,  1715, 12018,  1470, -1905, 12018,  1717,  1471,
    1472, -1905, -1905,  4344, -1905,  1501,   663,   665, 14884, -1905,
    1474, 13924,  1482, 13957, -1905,  1476, -1905, -1905,   670,  1518,
     -40,  7289,  1718,  1519,   -40,  1720,   671,  1521, -1905, 12018,
   -1905,  1724,  1615, 12959,  1524, -1905,   673,   305,   349,   362,
     364,   366,  3993, -1905, -1905,  1749,  1751, -1905, -1905, -1905,
    1752, -1905,  1525, 17222, 12018, 12018,   678, -1905, 17222, 13990,
   -1905, -1905, -1905,  1131,  5891,  1526, -1905, -1905, -1905, 12018,
   12018, -1905, 12018,  9769,  1753,   -40,   101, -1905, -1905,   -40,
     120, -1905,  1755, -1905, 14913, -1905, 12018, -1905,   344, -1905,
    1756,  9769,  9769,  9769,  9769,  9520, -1905, -1905, -1905, 13526,
   -1905, 12018, 17172, 14023,    22, 12018,  1528, -1905, -1905, 14056,
   14089, 14122,   680, -1905,   368, -1905,   371, -1905, -1905, -1905,
    4063,   270, 13018, -1905,   681,   686,   689,   691,   373,   692,
    1529,   694, -1905, 12018, -1905,  7289, 14942, -1905, 12018, 12018,
   12018, -1905,   -40,   -40, -1905, -1905, -1905,   344,  1759,  1765,
    1766,  1769,  9769,  1770,  1775,  1776,  1531, 17197,   699,  1781,
   14971, 15115, 14155,   380,   395,   290, -1905, -1905, -1905, -1905,
     700, -1905, -1905, -1905, 13505, -1905,  1536, -1905,  1786, -1905,
   12018, 12018, 12018, -1905,  1787,   701, -1905,  1539,  7289, -1905,
   15000, 15029, 15058, -1905,  1789, 13505, 13505,   702, -1905,  1790,
    1791, -1905, -1905,   732, -1905,  1795, -1905, -1905,  1798, 13505,
   -1905, -1905, -1905
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1905, -1905, -1905, -1905,   320, -1905, -1905, -1905, -1905,  -324,
   -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905, -1905,
   -1905, -1905,  -731,  -141,  4307,  3610, -1905,  1337, -1905, -1905,
   -1905, -1905, -1905, -1905, -1904, -1905,   375,   197,  -126, -1905,
     -87, -1905,   138,   414, -1905,  1813, -1905,   303,   -49, -1905,
   -1905,     4,  -631,  -295, -1905, -1905, -1905, -1905, -1905, -1905,
   -1905,   757,  1815, -1905, -1905, -1905, -1905, -1245, -1242,  1816,
   -1739,  1817, -1905, -1905, -1905,  1218, -1905,  -148, -1905, -1905,
   -1905, -1905,  2297, -1905, -1905, -1428,   284,  1822, -1905,     0,
    -717, -1905, -1905,   179, -1905, -1696,   785,  -178,  2878,  2983,
    -315,    65, -1905,  1620,   -26, -1905, -1905,    90,   261, -1705,
    -149,  1052, -1905,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -571
static const yytype_int16 yytable[] =
{
     143,   624,   445,   950,   951,  1493,  1495,   124,   466,  1050,
    1033,  1660,  1868,   310,  1904,   658,  1905,  1058,   501,   151,
     165,  1387,   167,  1073,   344,   166,   508,   371,  2164,   415,
     165,  1740,  1351,   640,  2029,  1897,   417,   165,  1629,  1064,
     551,  1333,   740,   165,   294,   294,   574,  1286,  1556,   315,
       5,   289,   663,   427,  1182,  1488,  1082,   179,  1820,  1183,
     349,   596,   350,   183,  1490,   375,  1093,   295,  1067,  1240,
       4,  1526,   632,   633,   168,   316,   169,  1821,   770,   781,
     348,  1620,   410,  1186,   414,   146,   330,  1241,  1630,   289,
     474,   317,   318,   945,   374,   785,  1242,  1243,  1244,   165,
    1941,   786,  1245,  1246,   753,   411,   147,  2145,   768,   632,
     633,   345,   632,   633,   632,   633,   769,   450,   609,   610,
     611,   716,  1311,   719,  1240,  1312,  2147,   596,   774,  1952,
     952,   731,   148,   956,   724,  1476,   775,   788,  1049,   168,
     451,   169,  1241,   786,   475,   461,   461,   461,   453,   632,
     633,  1242,  1243,  1244,   468,   351,   149,  1245,  1246,  1592,
     632,   633,   654,   655,   656,   634,  1333,   632,   633,  1366,
    1191,  1319,   480,  -566,  1759,  1527,  1528,  1480,   144,   670,
    1056,   331,   145,   635,  1333,   332,  1492,   311,   461,  2136,
     312,   333,   334,   289,   335,   336,   289,   547,   548,   320,
     321,   289,   289,   461,  1352,  1353,  1354,  1355,  1782,   425,
    1750,   322,  -567,   426,   337,   323,    98,   346,    99,   100,
     101,   102,   103,  1489,   741,   742,   107,   108,  1741,   110,
    1557,  1558,  1491,  1831,   171,   439,   440,   172,   153,   117,
     173,  1705,   174,   117,  1451,   150,   117,   324,   326,   117,
     329,  1074,  1075,  1493,   154,   289,   117,   155,   435,   436,
     437,   438,   117,   156,   659,   168,   660,   169,   152,   289,
     145,  2048,   289,   572,  1015,   347,   571,  2165,   372,   416,
     157,  1343,   439,   440,  1356,   745,   418,   746,   289,   289,
     552,  1336,   289,   289,   289,   289,   575,  1287,   428,   158,
     439,   440,   429,   597,   180,   598,   123,   289,   159,   599,
     184,   289,   376,   374,   632,   633,  1334,  1337,   117,   161,
     771,   782,   772,   772,   162,  2086,   773,   783,   941,   160,
     943,   944,   168,   452,   169,   289,   163,   289,   289,   289,
     632,   633,   164,   439,   440,   776,   754,   957,   755,   576,
    -563,   176,   756,   777,   289,   435,   436,   437,   438,   632,
     633,   289,   779,   177,   303,   976,   439,   440,   178,   597,
     780,   598,  1159,   439,   440,   599,   725,   876,   726,   439,
     440,   181,   727,   435,   436,   437,   438,  1074,  1075,   995,
    2160,   435,   436,   437,   438,   182,   866,   435,   436,   437,
    1057,   435,   436,   437,   438,   185,   735,   439,   440,  1240,
     632,   633,   439,   440,   304,   439,   440,   305,   306,   307,
     461,   289,   197,   632,   633,   289,   289,  1241,  1031,  1240,
     308,  1494,   186,   632,   633,   195,  1242,  1243,  1244,   632,
     633,   289,  1245,  1246,  1865,   196,   447,  1241,   757,   632,
     633,   447,   447,   447,  1985,   642,  1242,  1243,  1244,   745,
     447,   746,  1245,  1246,   632,   633,  1438,  1179,  1439,  2188,
    1986,   793,   187,    67,    68,    69,    70,   188,   168,    73,
     169,  1449,  1169,  1240,  1185,  1987,   189,  1186,    82,   299,
     780,    85,   300,   309,   447,   301,   190,   302,   627,   628,
     289,  1241,   632,   633,   632,   633,   636,   641,    46,   447,
    1242,  1243,  1244,   632,   633,   296,  1245,  1246,   297,   745,
     298,   746,  2227,  1988,   289,  1989,  2175,   780,  2042,  1376,
     191,   289,   856,   192,  1990,   882,   461,   824,   461,   289,
     461,   461,   468,  1003,   632,   633,  2213,   872,   546,   199,
    1381,   289,   289,   289,   461,   461,   289,   167,   824,   167,
     881,   289,   883,   555,   556,  2121,   340,  1885,   341,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   289,   632,   633,
     745,   595,   746,   913,  1539,  1688,  1689,  1861,  1289,  1051,
    1543,   632,   633,   632,   633,   632,   633,   632,   633,  2122,
     632,   633,   632,   633,   643,   289,   289,  1382,   644,   632,
     633,   745,  2123,   746,  2124,   824,  2125,   193,  2172,  1309,
    1505,  2173,   194,  2182,   632,   633,   439,   440,   453,   453,
    2211,   354,   200,  -565,   355,   201,  1578,  1229,   202,   198,
     320,   321,   205,   304,   576,  2212,   305,   356,   307,   206,
    1594,   203,   322,   289,   289,   289,   328,  1600,   289,   308,
     588,   589,   722,   591,   592,   593,   594,  2017,   745,  1018,
     746,   595,   745,   290,   746,  2018,   824,   468,   461,   468,
     461,   461,   461,   461,   461,   461,   291,   461,   461,   461,
     461,  1017,   292,   461,   461,   461,   167,  1023,   823,  1022,
     289,   293,   824,  1069,   722,   591,   592,   593,   594,   313,
     534,  1032,   535,   595,   439,   440,   447,   593,   594,   314,
    1202,  -570,  1203,   595,   289,  1680,   736,  2049,  2050,  2053,
    2054,   339,   886,  2051,   289,  2051,   824,  1524,   921,   922,
    1061,   967,   824,   824,   319,   824,  1035,  1041,   765,  1189,
     824,  1042,   327,   824,  1224,  1225,   289,  1078,   824,   824,
    1732,  1733,   289,  1107,   289,  1201,  1270,   468,  1091,  1271,
     824,  1272,   338,   824,  1096,   824,   461,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,   745,  1274,   746,   747,   595,
     824,   948,   949,  1315,  1346,  1886,   628,   824,   824,   289,
    1424,   289,  1431,  1448,   824,  1760,   824,   824,  1456,  1473,
    1590,  1642,   824,   824,   824,   824,  1673,  1769,   342,   287,
     824,  1674,   447,   343,   447,   824,   447,   447,   447,   682,
     352,   145,  1766,  1789,   289,  1791,  1767,   824,  1877,   824,
     447,   447,   824,  1924,   289,  1942,  1968,  1925,  1969,  1943,
     824,   353,   824,  2151,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   822,   591,   592,
     593,   594,  1318,  1984,  1319,  2014,   595,  1925,   745,   780,
     746,  2023,   289,   358,  1219,  2024,  1335,  1338,  2040,  1493,
     359,   360,  1925,  2044,   750,   289,  2045,   824,  2075,  2096,
     824,  2097,   824,   824,   289,   824,  2104,  2112,   361,  2120,
    1925,   824,  2195,   824,  2134,   289,  2171,  2178,  1925,   367,
     824,   824,  2179,   765,   767,  2180,   824,  2181,  2183,   824,
    2185,   824,   824,  1493,  2024,  2206,  2214,  2224,  2235,  1925,
     824,  2225,  1925,  1665,   368,  1666,   765,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,  1749,   369,  1750,  2238,   595,
     509,  1525,  2239,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   370,   447,   447,   447,   447,   632,   633,   447,
     447,   447,   745,   377,   746,   918,  1846,   379,  1847,   765,
     378,   380,   765,  1339,   381,   412,   423,   424,  1564,   430,
     456,   457,   472,   474,   765,   431,   145,   476,   477,   289,
     478,   479,   484,   287,   488,   502,   542,   507,   545,  -199,
    1345,  -200,  -201,   554,   553,   289,   557,   560,  1450,  1452,
     561,   562,  1857,  1858,  1068,   573,  1070,   426,   289,   605,
     606,   613,   614,   461,   615,   621,   618,   623,   645,   625,
     608,   626,   646,   447,   647,   648,   649,   650,   651,   657,
     661,   664,   447,   662,   665,   617,   666,   667,   668,   622,
     669,   671,   672,   673,   674,   677,   289,   289,   678,   289,
     289,   289,   684,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   576,  1232,   289,   685,   710,   693,   694,
     695,  1238,   706,   707,   709,  1249,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,   711,   712,   713,   714,   595,   717,
     715,   744,   718,   289,   461,   461,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,   734,   737,   749,   289,   595,   751,
     752,   144,   790,   794,   815,   758,   820,   826,   827,   828,
    1417,   799,   887,   289,   289,   289,   857,   867,   868,   869,
     595,   889,   890,   732,   733,   916,   926,   927,   930,   935,
     939,   940,   971,  1450,  1452,   942,   969,   972,   974,   743,
     983,   989,   993,   996,  1040,  1025,  1027,  1034,  1044,  1045,
    1053,  1054,  1052,  1065,   765,  1066,   765,   765,  1765,  1081,
    1071,  1753,  1083,  1085,  1088,  1755,  1095,  1097,  1100,   289,
     765,  1101,  1108,  1109,  1110,   453,  1112,  1113,  1114,  1116,
    1117,  1118,  1119,  1120,  1121,   289,   289,   289,  1122,   765,
    1123,  1124,  1125,  1128,  1132,  1157,   289,  1399,  1158,  1166,
    1167,   461,  1168,  1175,  1184,   461,  1178,  1190,   765,  1193,
    1198,  1194,  1206,  1207,   461,  1208,   461,  1214,  1216,   461,
    1227,  1507,  1235,  1236,  1239,  1261,  1262,  1264,  1281,  1278,
    1279,  1280,  1292,  1294,   289,  1293,  1297,   863,  1305,  1307,
    1308,  1314,  1317,  1320,   765,  1322,  1321,  1323,  1326,   608,
     374,   877,  2057,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,  1605,   461,  1610,  1327,   595,  1328,   289,  1332,   289,
    1341,  1342,  1347,  1348,  1363,  1369,  1370,  1371,  1372,   447,
    1380,  1385,  1377,  1389,  1384,  1402,   289,  1406,  1418,  -202,
    1442,  1434,  1460,  1461,  1462,  1465,  1466,  1467,  1468,   289,
    1469,  1470,  1471,   289,  1472,  1474,  1481,  1482,  1486,  1487,
    1497,  1485,  1496,  1498,  1499,  1761,  1500,  1501,  1502,  1503,
    1774,  1774,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
    1504,  1508,  1509,  1510,   595,  1511,  1512,  1513,  1514,  1515,
    1516,  1521,  1913,  1529,  1534,  1535,  1555,   289,   289,   289,
    1541,  1542,  1544,  1560,  1561,   289,   289,   289,  1552,  1546,
     447,   447,  1550,  1563,  1566,  1571,  1567,  1573,  1574,  1577,
    1575,  1591,   289,  1597,  1589,  1598,  1595,  1614,  1612,  1619,
    1613,  1621,  1625,   289,  1626,  1627,  1632,  1633,  1634,  1635,
    1636,   289,  1637,  1638,  1639,   289,  1640,  1641,  1668,  1662,
    1651,  1672,  1678,  1679,  1725,  1701,  1748,  1687,  1702,  1717,
    1658,  1723,  1046,  1724,  1685,  1686,  1729,  1836,  1716,  1730,
    1696,  1693,   765,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,  1694,  1695,  1708,  1709,   595,  1710,  1731,  1757,  1711,
     374,  1712,  1713,  1719,  1763,  1783,   468,   468,  1745,  1784,
    1735,  1786,   289,  1776,  1762,  1738,  1752,  1803,  1312,  1781,
    1756,  1792,  1793,  1788,  1795,  1796,  1799,   165,   382,  1804,
     461,  1810,  1811,  1812,  1813,  1815,  1816,   447,  1817,  1818,
     289,   447,  1822,  1823,  1824,   289,  1825,  1830,  1186,  1837,
     447,  1838,   447,  1839,  1841,   447,  1866,  1844,  1862,  1845,
    1867,  1916,  1876,  1881,  1545,  1899,  1900,  1909,  1901,  1910,
     383,   384,   385,   386,   387,   388,   389,   390,   391,  1912,
    1917,  1929,  1836,   392,   393,   394,   395,  -568,   780,  1930,
    1931,   396,   397,   398,   399,  1932,  1936,  1946,  1945,   400,
    1947,   401,  1951,  1852,  1963,  1957,  1964,  1972,   447,  1940,
    1948,  1949,  1950,  1704,  1967,   402,  1973,   289,   403,  1975,
    1976,  1979,   289,   289,  1981,  1982,  1991,  2063,  1998,  2008,
    1999,  2005,  2010,  2011,  2013,  2080,  1593,   453,   453,  2012,
    1993,  2006,  2007,  2015,  2016,   289,  2021,  1890,  2039,  2060,
    2061,   289,  1213,  2065,  1895,  1898,  2076,  2077,  2078,  2079,
    2081,  2087,   289,  2090,  2108,  -569,  2111,  2091,  2092,  2099,
    2115,  2103,   461,  1907,  2101,   461,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,  2095,   289,  2116,  2127,   595,  2128,  2130,  2143,
    1345,  2148,  2153,   449,   374,  2196,   289,   468,   459,   462,
     463,  2197,  2198,  2105,  2109,  2199,  2201,  2113,  2138,  2119,
    2131,  2202,  2203,  2129,  2167,  2184,  2204,  2207,   404,   405,
     406,  2218,  2219,  2223,  2226,  2231,  2236,  2237,  1549,   407,
    1814,  2240,   468,   408,  2241,   409,   117,  2161,   789,  1654,
    1809,   496,  2002,  2030,  1840,  1623,   122,  1362,   133,   134,
     135,  2055,   289,  1747,  2152,   141,   510,  1329,  1911,   929,
    1896,  1775,  1090,     0,   289,   289,     0,     0,     0,     0,
       0,     0,     0,  1349,     0,     0,     0,     0,     0,     0,
       0,     0,  1562,     0,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   289,   447,   447,     0,  2003,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   289,     0,     0,  1869,  1870,
    1871,  1872,  1873,  1875,  1400,  1401,   447,  1403,  1404,  1405,
       0,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,
    1416,  1697,     0,     0,     0,     0,     0,     0,  2034,     0,
       0,     0,   289,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,   289,     0,     0,
     595,     0,  2035,     0,     0,   289,   289,     0,     0,     0,
       0,  1428,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   289,     0,     0,   289,     0,     0,
       0,     0,     0,     0,     0,  1443,     0,   453,   289,     0,
       0,     0,   289,     0,     0,     0,     0,     0,     0,     0,
       0,  1457,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,   374,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,   289,     0,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,   447,     0,
       0,   447,   595,   728,     0,     0,     0,  1506,   289,     0,
       0,     0,     0,     0,     0,     0,   765,     0,   765,     0,
       0,     0,     0,  1518,  1519,  1520,     0,     0,  2137,     0,
       0,     0,     0,   447,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
     289,     0,     0,     0,     0,     0,     0,     0,   447,  1754,
       0,     0,  1551,     0,     0,     0,     0,     0,   289,   289,
     289,   289,   289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,   860,
       0,   862,   289,   864,   865,  2067,  2068,  2069,  2070,  2071,
       0,     0,     0,     0,  1609,     0,     0,   878,   879,   289,
       0,     0,     0,     0,     0,     0,     0,  1624,     0,     0,
       0,  1628,  1758,     0,     0,     0,     0,     0,     0,     0,
       0,   461,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   289,     0,     0,     0,     0,
       0,     0,   461,   461,     0,     0,     0,     0,     0,  2106,
       0,     0,     0,  2110,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,  1675,  1676,  1677,     0,     0,
       0,     0,     0,  1682,  1683,  1684,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1699,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1463,  1707,     0,     0,  2144,     0,     0,     0,  2146,  1715,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2158,     0,     0,     0,     0,     0,
       0,  1002,     0,  1004,  1005,  1006,  1007,  1008,  1009,     0,
    1011,  1012,  1013,  1014,     0,     0,  1019,  1020,  1021,     0,
       0,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,  2193,  2194,   595,     0,     0,     0,     0,     0,     0,
    1780,     0,     0,     0,     0,     0,   765,     0,  1764,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,  1802,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
    1089,     0,     0,     0,     0,     0,     0,     0,     0,  1098,
       0,     0,     0,   421,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,   765,     0,     0,     0,   595,     0,     0,     0,
     448,     0,     0,     0,   458,     0,     0,     0,     0,   464,
       0,     0,     0,     0,     0,   765,     0,   469,     0,     0,
       0,     0,     0,     0,     0,  1843,     0,     0,     0,     0,
       0,     0,     0,   481,   482,   483,     0,   485,   486,   487,
       0,   489,   490,   491,   492,   493,   494,   495,     0,   497,
     498,   499,   500,  1780,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,     0,     0,
    1882,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   447,   447,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1906,   447,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1915,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,   565,
     567,   568,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602,   504,   504,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,   620,
    1780,     0,   595,     0,     0,     0,     0,     0,     0,   630,
     631,     0,     0,     0,     0,   631,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,   653,     0,     0,     0,
       0,   413,   382,     0,     0,     0,     0,  1980,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     675,   504,     0,     0,     0,   679,   680,   681,     0,   683,
       0,     0,     0,   686,   687,   688,     0,     0,   689,     0,
       0,     0,     0,     0,   383,   384,   385,   386,   387,   388,
     389,   390,   391,     0,     0,     0,  1375,   392,   393,   394,
     395,     0,     0,     0,     0,   396,   397,   398,   399,     0,
    2022,     0,     0,   400,     0,   401,     0,   721,     0,     0,
       0,   504,   730,     0,     0,  2031,     0,     0,     0,   402,
       0,     0,   403,     0,     0,     0,     0,     0,   738,   739,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1780,   766,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2062,     0,     0,     0,
       0,     0,     0,   795,   796,   797,   798,     0,     0,     0,
       0,   803,     0,     0,     0,   807,     0,  1429,  1430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   821,
     565,     0,     0,     0,   825,     0,  1780,     0,   829,   830,
     831,   832,   833,   834,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   847,   848,   849,   850,   851,
     852,   853,   853,     0,   858,   859,  2107,   861,     0,     0,
       0,     0,   404,   405,   406,     0,   870,     0,     0,   874,
     875,     0,     0,   407,     0,     0,   853,   408,     0,   409,
       0,   504,     0,     0,     0,     0,     0,     0,     0,     0,
    1879,     0,     0,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   906,   908,   909,
     910,   911,   912,     0,   914,   915,     0,     0,     0,     0,
    1880,     0,   923,   924,   925,     0,     0,     0,     0,     0,
     931,   932,   933,   934,  1531,   504,   504,     0,  1533,     0,
       0,     0,     0,     0,     0,     0,     0,  1537,     0,  1538,
       0,     0,  1540,     0,   563,   721,   953,     0,     0,     0,
     958,   959,   960,   961,   962,   963,   964,   965,   966,     0,
    1780,     0,     0,     0,   973,     0,   975,     0,     0,   977,
       0,  1971,     0,   504,   504,   504,   982,     0,   504,   985,
     986,   987,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1580,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1010,     0,     0,     0,
       0,     0,     0,  1780,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,  1029,     0,  1030,
       0,     0,   914,   915,     0,     0,     0,     0,     0,     0,
       0,  1043,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,  1059,     0,     0,     0,
       0,  1062,  1063,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,  1079,  1080,
       0,     0,   504,     0,   504,  1087,     0,   505,     0,  1079,
       0,  1094,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,  1102,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,  1126,     0,   906,
       0,  1129,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
     566,     0,     0,   505,   504,     0,     0,     0,     0,     0,
    1997,     0,     0,     0,   504,  1171,  1172,     0,     0,   505,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   506,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,   504,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,  1794,     0,   504,   505,     0,     0,     0,
       0,     0,     0,  1212,     0,     0,     0,  1218,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,   505,  1233,  1234,     0,     0,     0,     0,  1237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1263,     0,     0,  1265,
       0,     0,     0,     0,   603,   604,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1282,     0,  1284,  1285,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1303,     0,     0,     0,     0,     0,     0,     0,
       0,   652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1325,     0,     0,     0,     0,
       0,     0,  1331,     0,     0,     0,     0,  1340,     0,     0,
       0,     0,     0,     0,     0,  1891,     0,     0,  1893,     0,
       0,     0,  1367,  1368,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   566,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
    1394,  1395,  1396,  1397,   595,   846,     0,   729,     0,     0,
       0,     0,   854,   855,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   880,     0,     0,
       0,  1420,   505,     0,     0,     0,     0,     0,     0,     0,
       0,  1421,  1422,  1423,     0,     0,     0,     0,  1425,  1426,
       0,  1427,     0,     0,     0,     0,     0,     0,   907,   165,
     382,     0,     0,     0,     0,  1436,  1437,     0,     0,     0,
       0,     0,     0,  1440,  1441,     0,     0,     0,     0,     0,
    1445,     0,  1446,  1447,     0,     0,   505,   505,     0,  1453,
    1454,     0,     0,     0,   504,   504,     0,     0,     0,     0,
       0,     0,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,   393,   394,   395,     0,
       0,     0,     0,   396,   397,   398,   399,     0,  1484,     0,
       0,   400,     0,   401,   505,   505,   505,   884,     0,   505,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
     403,     0,     0,     0,   299,     0,     0,   300,     0,     0,
     301,     0,   302,     0,  1517,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,   504,     0,     0,     0,
       0,   505,     0,     0,  1532,     0,     0,     0,     0,     0,
     433,   936,   937,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1453,  1454,     0,     0,     0,
    1548,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,  1554,     0,     0,  1559,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,   979,
     980,   981,     0,   505,   984,   505,     0,     0,     0,     0,
       0,     0,     0,  1581,     0,     0,  1584,   504,  1587,   504,
     404,   405,   406,     0,     0,     0,     0,  1596,     0,     0,
    1599,   407,  1596,  1602,  1604,   408,     0,   409,   117,     0,
       0,     0,     0,     0,     0,     0,  1024,     0,     0,     0,
     907,     0,  1130,     0,  2009,     0,     0,     0,     0,     0,
       0,     0,     0,   439,   440,     0,     0,     0,     0,     0,
    -564,     0,  1579,     0,     0,     0,     0,     0,     0,     0,
    1055,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,     0,
       0,     0,  1077,     0,     0,     0,     0,     0,  1084,     0,
    1086,     0,     0,     0,  1681,     0,     0,     0,     0,     0,
       0,     0,     0,  1690,  1691,  1692,     0,     0,     0,     0,
       0,     0,  1698,   505,  1700,     0,     0,     0,     0,     0,
       0,  1703,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
    1720,  1721,     0,     0,     0,     0,   505,     0,     0,  1726,
    1727,  1728,     0,     0,  2216,     0,     0,     0,     0,     0,
       0,  1739,     0,     0,     0,     0,     0,     0,     0,     0,
    1160,  1751,     0,     0,     0,  2232,  2234,     0,     0,     0,
    1170,     0,     0,     0,     0,     0,     0,     0,     0,  2242,
       0,     0,     0,     0,  1768,     0,     0,     0,     0,     0,
    1777,  1778,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1197,     0,
       0,     0,  2046,     0,     0,     0,     0,     0,     0,     0,
       0,  1205,     0,     0,     0,  1807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1226,     0,     0,     0,     0,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,  1826,  1827,  1828,   595,   505,
       0,     0,     0,     0,     0,     0,  1829,     0,     0,     0,
       0,  1832,  1833,  1834,     0,     0,     0,     0,     0,     0,
    2047,     0,     0,     0,     0,  1842,     0,     0,     0,     0,
       0,     0,   504,   504,  1850,     0,  1851,     0,     0,     0,
       0,     0,  1859,  1860,     0,     0,     0,     0,     0,  2126,
       0,     0,     0,     0,     0,     0,   505,     0,     0,     0,
       0,   504,     0,     0,     0,     0,  1878,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1889,     0,     0,  1892,     0,     0,     0,  1894,     0,     0,
       0,     0,     0,     0,     0,     0,  1833,  1834,     0,  1903,
       0,     0,     0,     0,  1374,     0,   748,  1908,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2174,
       0,     0,     0,  1921,     0,     0,     0,     0,  1927,  1928,
       0,     0,     0,     0,     0,   505,   505,     0,     0,     0,
       0,     0,  1933,     0,     0,  1934,  1933,     0,  1937,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1419,     0,     0,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,   504,   504,   595,  1944,   576,     0,
       0,  1965,  1966,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1974,     0,     0,     0,     0,     0,     0,
     871,     0,  1983,     0,     0,     0,     0,   505,     0,     0,
       0,   565,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1994,  1995,     0,     0,   504,     0,     0,     0,     0,
    1458,  1459,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,   919,     0,     0,   595,     0,     0,     0,     0,  2019,
    2020,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
    2033,     0,     0,   595,     0,   504,   504,  2038,   505,     0,
     505,     0,  2041,     0,     0,  2043,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,  1530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
    2072,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,  2083,     0,     0,     0,     0,
       0,  2088,     0,     0,  2089,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2094,     0,  1586,     0,  1588,  2114,     0,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   822,   591,   592,   593,   594,     0,     0,     0,     0,
     595,  2132,  2133,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2139,  2140,     0,  2141,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2150,     0,     0,     0,     0,   504,   504,
     504,   504,   504,     0,     0,     0,     0,     0,  1927,     0,
       0,     0,  2166,     0,     0,     0,     0,     0,     0,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
     446,  1145,  1146,  1147,  1148,     0,  1150,  1151,  1152,  1153,
    2187,     0,     0,     0,     0,  2190,  2191,  2192,     0,     0,
    1163,     0,  1165,     0,     0,     0,     0,     0,     0,   504,
       0,     0,  1174,     0,     0,     0,  1808,     0,     0,  1180,
    1181,  1718,     0,     0,     0,     0,     0,     0,  1192,     0,
       0,     0,     0,     0,     0,     0,     0,  2220,  2221,  2222,
       0,   576,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   536,   537,   538,   539,   540,   541,     0,   543,
     544,     7,     8,     0,     0,     0,     0,     0,   549,   550,
       0,     0,     0,   505,   505,     0,     0,     0,     0,     0,
     558,   559,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,   505,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     997,  1288,  1290,  1291,     0,     0,     0,  1295,  1296,     0,
       0,  1299,  1300,  1301,  1302,     0,  1304,     0,     0,     0,
       0,  1310,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   759,    55,  1848,  1849,
      58,   760,     0,   761,   762,     0,   763,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     690,   691,   692,     0,    79,     0,   696,   697,   698,   699,
     700,   701,   702,     0,   703,     0,     0,     0,     0,   704,
     705,     0,  1393,   708,     0,   505,   505,  1398,     0,    94,
      95,    96,     0,     0,     0,     0,   720,     0,     0,     0,
       0,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   822,   591,   592,   593,   594,     0,
       0,     0,   566,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,  1195,     0,    48,
       0,     0,     0,     0,   954,     0,   759,    55,     0,     0,
      58,   760,     0,   761,   762,     0,   763,     0,     0,     0,
       0,     0,     0,     0,  1455,     0,     0,     0,     0,     0,
    1961,  1962,     0,     0,    79,     0,   505,   505,     0,     0,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,   505,    94,
      95,    96,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,  1996,     0,   207,   165,     0,     0,     0,     0,   888,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   419,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   978,     0,   240,   241,   242,   243,
       0,  2036,  2037,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,     0,  2056,     0,     0,  1568,     0,     0,     0,
     251,    25,     0,   252,     0,     0,     0,     0,  2066,     0,
       0,     0,     0,     0,  1196,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1606,   505,
     505,   505,   505,   505,     0,     0,     0,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
    1643,  1644,  1645,  1646,  1647,     0,     0,     0,     0,  1652,
    1653,     0,     0,     0,     0,  1655,     0,  1657,     0,     0,
       0,  1661,     0,     0,  1663,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,  1671,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   263,     0,
       0,     0,     0,   265,   266,   267,  2142,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2154,  2155,  2156,  2157,  2159,   271,
     420,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,     0,     0,     0,   619,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1734,     0,  1737,     0,     0,     0,  1744,     0,  1746,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1771,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1187,     0,     0,     0,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,   207,     6,   382,   595,     0,     0,     0,
     208,   209,   210,     0,  1204,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,  1523,     0,     0,  1607,   384,   385,
     386,   387,   388,   389,   390,   391,   240,   241,   242,   243,
     392,   393,   394,   395,   244,   245,     0,  1835,   396,   397,
     398,   399,     0,     0,   246,   247,   400,     0,   401,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,   402,   252,     0,   403,     0,     0,     0,   253,
       0,     0,   254,     0,     0,   255,     0,   256,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,     0,
      56,    57,     0,   259,     0,   260,     0,     0,   261,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1918,     0,     0,  1919,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1388,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   404,   405,   406,   263,   264,
       0,     0,     0,   265,   266,   267,   407,   268,   269,   270,
     408,     0,   409,   117,     0,     0,  1953,  1954,     0,  1956,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     272,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,     0,     0,     0,  1608,     0,     0,   276,     0,
       0,     0,     0,     0,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,  1444,     0,
       0,     0,  2000,  2001,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,   745,     0,
     746,     0,     0,     0,     0,     0,  1736,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   207,     6,   382,
       0,  2032,     0,     0,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     240,   241,   242,   243,   392,   393,   394,   395,   244,   245,
       0,     0,   396,   397,   398,   399,     0,     0,   246,   247,
     400,     0,   401,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   251,    25,   402,   252,     0,   403,
       0,     0,     0,   253,     0,     0,   254,     0,     0,   255,
       0,   256,     0,     0,  1569,  1570,     0,     0,    42,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,    56,    57,     0,   259,     0,   260,
       0,     0,   261,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,   988,     0,     0,     0,     0,     0,     0,     0,   946,
       0,     0,     0,     0,     0,     0,  1659,     0,   262,   404,
     405,   406,   263,   264,     0,     0,  1667,   265,   266,   267,
     407,   268,   269,   270,   408,     0,   409,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   272,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   363,   207,   165,   382,   275,
     432,  2209,   276,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   419,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   240,
     241,   242,   243,   392,   393,   394,   395,   244,     0,     0,
       0,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   401,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,   402,   252,     0,   403,     0,
       0,     0,   299,     0,     0,   300,   382,     0,   301,     0,
     302,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,  1805,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   433,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,   393,   394,   395,     0,     0,     0,     0,   396,
     397,   398,   399,     0,     0,     0,     0,   400,     0,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   402,     0,     0,   403,     0,     0,     0,
     434,     0,     0,     0,     0,     0,     0,   262,   404,   405,
     406,   263,     0,     0,     0,     0,   265,   266,   267,   407,
     268,   269,   270,   408,     0,   409,   117,   435,   436,   437,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   420,     0,     0,     0,     0,     0,   273,
       0,   439,   440,     0,   441,     0,   442,   207,     6,   362,
     443,   276,     0,     0,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,   404,   405,   406,     0,
     240,   241,   242,   243,     0,     0,     0,   407,   244,   245,
       0,   408,     0,   409,     0,     0,     0,     0,   246,   247,
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
       0,     0,     0,     0,     0,  1800,     0,     0,     0,  1801,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,   263,   264,     0,     0,     0,   265,   266,   267,
       0,   268,   269,   270,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   272,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   363,   207,     6,     0,   364,
       0,   676,   276,   208,   209,   210,     0,     0,   211,   212,
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
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  1855,     0,     0,     0,  1856,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,   263,   264,     0,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   503,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   363,   207,     6,  1706,     0,   569,
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
       0,     0,     0,  1883,     0,     0,     0,  1884,     0,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
     263,   264,     0,     0,     0,   265,   266,   267,     0,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   272,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   363,   207,     6,     0,   275,     0,     0,
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
       0,     0,  2058,     0,     0,     0,  2059,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,  1874,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   639,   207,     6,     0,   323,   569,     0,   276,
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
       0,     0,     0,     0,     0,   778,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   263,   264,
       0,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     272,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   274,   207,     6,     0,   275,     0,     0,   276,   208,
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
       0,     0,     0,     0,   784,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   263,   264,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     363,   207,     6,     0,   275,     0,     0,   276,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
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
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   946,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,   263,   264,     0,     0,
       0,   265,   266,   267,     0,   268,   269,   270,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   503,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   363,
     207,     6,     0,   564,     0,     0,   276,   208,   209,   210,
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
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   947,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   503,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,   207,
       6,     0,     0,   569,     0,   276,   208,   209,   210,     0,
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
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   994,     0,     0,     0,     0,     0,     0,     0,     0,
     262,     0,     0,     0,   263,   264,     0,     0,     0,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   272,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   607,   207,     6,
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
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   263,   264,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   272,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   616,   207,     6,     0,
     275,     0,     0,   276,   208,   209,   210,     0,     0,   211,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,     0,     0,     0,     0,     0,     0,   262,     0,
       0,     0,   263,   264,     0,     0,     0,   265,   266,   267,
       0,   268,   269,   270,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   503,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   363,   207,     6,     0,   905,
       0,  1373,   276,   208,   209,   210,     0,     0,   211,   212,
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
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1105,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,   263,   264,     0,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   503,     0,     0,     0,     0,     0,   273,
     207,     6,     0,     0,   363,  1585,     0,   208,   209,   210,
       0,   276,   211,   212,   213,   214,   215,   216,   217,   218,
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
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   503,     0,     0,
       0,     0,     0,   273,   207,     6,     0,     0,   363,     0,
       0,   208,   209,   210,     0,   276,   211,   212,   213,   214,
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
       0,     0,     0,     0,     0,     0,  1144,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   272,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   363,   207,     6,     0,  1714,     0,     0,   276,
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
       0,     0,     0,     0,     0,  1154,     0,     0,     0,     0,
       0,     0,     0,     0,   262,     0,     0,     0,   263,   264,
       0,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   637,
    1874,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   639,   207,     6,     0,   323,     0,     0,   276,   208,
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
       0,     0,     0,     0,  1155,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   263,   264,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   503,
       0,     0,     0,     0,     0,   273,   207,   165,   382,     0,
     363,     0,     0,   208,   209,   210,     0,   276,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   419,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   240,
     241,   242,   243,   392,   393,   394,   395,   244,     0,     0,
       0,   396,   397,   398,   399,     0,     0,     0,     0,   400,
       0,   401,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,   402,   252,     0,   403,   207,
     165,   382,     0,     0,     0,     0,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   419,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   240,   241,   242,   243,   392,   393,   394,   395,
     244,     0,     0,     0,   396,   397,   398,   399,     0,     0,
       0,     0,   400,     0,   401,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   251,    25,   402,   252,
       0,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,   404,   405,
     406,   263,     0,     0,     0,     0,   265,   266,   267,   407,
     268,   269,   270,   408,     0,   409,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   420,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   363,     0,     0,     0,  1603,     0,
       0,   276,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1156,     0,     0,     0,     0,     0,
     262,   404,   405,   406,   263,     0,     0,     0,     0,   265,
     266,   267,   407,   268,   269,   270,   408,     0,   409,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   420,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   363,   207,   165,
     382,  1888,     0,     0,   276,   208,   209,   210,     0,     0,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   419,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,  1607,   384,   385,   386,   387,   388,   389,   390,
     391,   240,   241,   242,   243,   392,   393,   394,   395,   244,
       0,     0,     0,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   401,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,   402,   252,     0,
     403,   207,   165,   382,     0,     0,     0,     0,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     419,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   240,   241,   242,   243,   392,   393,
     394,   395,   244,     0,     0,     0,   396,   397,   398,   399,
       0,     0,     0,     0,   400,     0,   401,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   251,    25,
     402,   252,     0,   403,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     404,   405,   406,   263,     0,     0,     0,     0,   265,   266,
     267,   407,   268,   269,   270,   408,     0,   409,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   420,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,     0,     0,     0,
    1770,     0,     0,   276,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1161,     0,     0,     0,
       0,     0,   262,   404,   405,   406,   263,     0,     0,     0,
       0,   265,   266,   267,   407,   268,   269,   270,   408,     0,
     409,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   420,     0,
       0,     0,     0,     0,   273,   207,   165,     0,     0,   363,
       0,     0,   208,   209,   210,     0,   276,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   419,   229,   230,   231,   232,   233,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,   243,     0,     0,     0,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,   250,     0,     0,     0,     0,     0,   207,
     165,     0,   251,    25,   873,   252,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   419,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   251,    25,     0,   252,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,   262,     0,     0,     0,
     263,     0,  1162,     0,     0,   265,   266,   267,     0,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   637,   638,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   639,     0,     0,     0,   323,     0,     0,
     276,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
     262,     0,     0,  1164,   263,     0,     0,     0,     0,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   420,     0,     0,     0,
       0,     0,   273,   207,   165,     0,     0,   363,     0,     0,
     208,   209,   210,     0,   276,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   419,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,     0,   252,   207,   165,     0,  1324,     0,     0,
       0,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   419,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
     243,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,   262,     0,     0,   595,   263,     0,
       0,     0,   723,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     420,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,  1092,     0,     0,     0,     0,     0,   276,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1277,     0,     0,     0,   262,     0,     0,     0,   263,
       0,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   420,     0,     0,     0,     0,     0,   273,   207,   165,
       0,  1483,   363,     0,     0,   208,   209,   210,     0,   276,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   419,   229,   230,
     231,   232,   233,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,   243,     0,     0,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,   207,
     165,     0,  1547,     0,     0,     0,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   419,   229,
     230,   231,   232,   233,   234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   251,    25,     0,   252,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,   262,
       0,     0,   595,   263,     0,     0,     0,   938,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   420,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,     0,   276,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1298,     0,     0,     0,
     262,     0,     0,     0,   263,     0,     0,     0,     0,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   420,     0,     0,     0,
       0,     0,   273,   207,   165,     0,     0,   363,     0,     0,
     208,   209,   210,     0,   276,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   419,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,   207,   165,     0,
     251,    25,     0,   252,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   419,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   251,    25,     0,   252,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,   262,     0,     0,     0,   263,     0,
    1383,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     420,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,  1601,     0,     0,     0,     0,     0,   276,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,   262,     0,
       0,  1386,   263,     0,     0,     0,     0,   265,   266,   267,
       0,   268,   269,   270,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,   420,     0,     0,     0,     0,     0,
     273,   207,   165,     0,     0,   363,  1935,     0,   208,   209,
     210,     0,   276,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     419,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     382,     0,     0,     0,   240,   241,   242,   243,     0,     0,
       0,     0,   244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   251,    25,
       0,   252,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,   393,   394,   395,     0,
       0,     0,     0,   396,   397,   398,   399,     0,     0,     0,
       0,   400,     0,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
     403,     0,     0,     0,   299,     0,     0,   300,     0,     0,
     301,     0,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     433,     0,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,   262,     0,   595,     0,   263,     0,     0,     0,
       0,   265,   266,   267,  1477,   268,   269,   270,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,   165,
     382,     0,     0,     0,     0,     0,     0,   271,   420,     0,
       0,     0,     0,     0,   273,     0,     0,     0,     0,   363,
     404,   405,   406,     0,     0,     0,   276,     0,     0,     7,
       8,   407,     0,     0,     0,   408,     0,   409,   117,     0,
       0,     0,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,   393,   394,   395,     0,
       0,     0,     0,   396,   397,   398,   399,   745,     0,   746,
    1770,   400,     0,   401,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
     403,     0,     0,     0,   299,     0,     0,   300,     0,     0,
     301,     0,   302,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
     433,    43,    44,    45,    46,     0,     0,    48,     7,     8,
       0,     0,     0,     0,   759,    55,     0,     0,    58,   760,
       0,   761,   762,     0,   763,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,    94,    95,    96,
     404,   405,   406,     0,     0,  1478,     0,     7,     8,     0,
       0,   407,     0,     0,     0,   408,     0,   409,   117,     0,
       0,     0,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      43,    44,    45,    46,     0,     0,    48,     0,     0,     0,
    1770,     0,     0,   759,    55,     0,     0,    58,   760,     0,
     761,   762,     0,   763,     0,     0,     0,     0,     0,     0,
       0,     0,  1026,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    94,    95,    96,    43,
      44,    45,    46,     7,     8,    48,     0,     0,     0,     0,
       0,     0,   759,    55,     0,     0,    58,   760,     0,   761,
     762,     0,   763,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     7,     8,   595,     0,    94,    95,    96,     0,     0,
       0,  1028,     0,  1522,     0,     0,     0,     0,     0,     0,
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
      58,   760,     0,   761,   762,     0,   763,  1475,     0,     0,
       0,     0,    -4,     1,     0,     0,    -4,     0,     0,     0,
       0,     0,     0,     0,    79,    -4,    -4,     0,     0,     0,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,    94,
      95,    96,   595,     0,     0,     0,    -4,    -4,    -4,     0,
       0,     0,  1648,     0,     0,  2117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,    -4,    -4,
       0,     0,     0,     0,    -4,    -4,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,  2176,     0,    -4,    -4,    -4,    -4,
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
       0,  1649,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1650,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1664,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1798,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1922,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1923,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1955,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1958,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2027,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2084,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2085,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2100,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2102,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2135,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2163,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2168,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2169,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2170,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2210,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,   819,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,  1072,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,  1131,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,  1176,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
    1177,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  1221,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,  1253,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  1273,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  1330,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  1350,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  1432,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,  1433,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,  1479,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,  1553,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
    1853,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  1864,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,  1902,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  1977,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  1992,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  2004,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  2028,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,     0,  2064,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
       0,     0,  2073,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,     0,
       0,  2074,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
    2098,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,     0,     0,  2149,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,     0,     0,  2189,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,     0,     0,  2208,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,     0,     0,  2228,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,     0,     0,  2229,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,     0,     0,  2230,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,     0,  1970,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,   745,     0,   746,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,  1000,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,  1048,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
    1200,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,  1267,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,  1269,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,     0,
       0,  1275,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   722,   591,   592,   593,   594,
       0,     0,     0,     0,   595,     0,     0,     0,  1276,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   722,   591,   592,   593,   594,     0,     0,     0,
       0,   595,     0,     0,     0,  1365,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   722,
     591,   592,   593,   594,     0,     0,     0,     0,   595,     0,
       0,     0,  1379,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   722,   591,   592,   593,
     594,     0,     0,     0,     0,   595,     0,     0,     0,  1582,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,     0,     0,  1670,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     722,   591,   592,   593,   594,     0,     0,     0,     0,   595,
       0,     0,     0,  1722,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   722,   591,   592,
     593,   594,     0,     0,     0,     0,   595,     0,     0,     0,
    1914,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   722,   591,   592,   593,   594,     0,
       0,     0,     0,   595,     0,     0,     0,  1960,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   722,   591,   592,   593,   594,     0,     0,     0,     0,
     595,     0,     0,     0,  1978,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   800,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   801,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   802,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   804,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   805,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   806,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   808,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   809,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   810,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   811,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   812,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   813,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   814,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   816,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   817,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   818,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   885,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   920,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   968,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   988,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   990,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   991,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   992,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,   998,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,   999,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1036,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1047,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1111,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1115,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1127,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1199,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1209,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1210,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1211,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1220,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1222,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1223,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1252,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1254,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1255,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1256,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1257,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1258,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1259,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1260,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1266,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1364,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1378,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1583,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1615,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1616,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1617,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1618,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1656,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1669,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1785,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1787,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1790,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1797,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1854,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1863,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  1887,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  1959,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  2025,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  2026,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595,     0,  2162,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   722,   591,
     592,   593,   594,     0,     0,     0,     0,   595,     0,  2205,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   722,   591,   592,   593,   594,     0,     0,
       0,     0,   595
};

static const yytype_int16 yycheck[] =
{
       3,   316,   143,   634,   635,  1247,  1251,     3,   157,   740,
     727,  1439,  1708,    62,  1753,     4,  1755,   748,   196,     6,
       4,     7,    25,     6,     4,    25,   204,     4,     6,     5,
       4,     4,     4,   328,  1938,  1740,     5,     4,   139,   756,
       5,     7,     4,     4,   105,   105,     5,     7,     4,   160,
       0,    54,   347,     6,   252,     6,   773,     4,    99,   257,
       4,     9,     6,     4,     6,     4,   783,   128,   128,   139,
       6,     4,   239,   240,   251,   186,   253,   118,     9,     9,
      83,     6,   108,   260,   110,    14,     4,   157,   189,    92,
       9,   202,   203,   260,    97,   254,   166,   167,   168,     4,
    1805,   260,   172,   173,     9,   108,   105,     6,   252,   239,
     240,    91,   239,   240,   239,   240,   260,   143,   296,   297,
     298,   416,   257,   418,   139,   260,     6,     9,   252,  1825,
     260,   426,   251,   260,     9,   260,   260,   254,     7,   251,
     143,   253,   157,   260,   170,   148,   149,   150,   144,   239,
     240,   166,   167,   168,   157,    99,   251,   172,   173,     6,
     239,   240,   340,   341,   342,   255,     7,   239,   240,   251,
     887,   253,   175,   255,     7,   108,   109,   256,   255,   357,
       7,    99,   259,   255,     7,   103,   256,   102,   191,  2093,
     105,   109,   110,   196,   112,   113,   199,   246,   247,   239,
     240,   204,   205,   206,   176,   177,   178,   179,   251,   251,
     253,   251,   255,   255,   132,   255,   188,   197,   190,   191,
     192,   193,   194,   174,   186,   187,   198,   199,   201,   201,
     186,   187,   174,  1661,    99,   248,   249,   102,     6,   223,
     105,   256,   107,   223,   257,   251,   223,    68,    69,   223,
      71,   234,   235,  1495,     6,   258,   223,     6,   224,   225,
     226,   227,   223,     6,   253,   251,   255,   253,   255,   272,
     259,  1967,   275,   276,   258,   255,   276,   255,   255,   255,
     251,   255,   248,   249,   256,   252,   255,   254,   291,   292,
     255,   257,   295,   296,   297,   298,   255,   257,   251,     6,
     248,   249,   255,   251,   251,   253,     3,   310,     6,   257,
     251,   314,   251,   316,   239,   240,  1047,  1048,   223,     6,
     251,   251,   253,   253,     6,  2021,   257,   257,   623,   255,
     625,   626,   251,     4,   253,   338,   253,   340,   341,   342,
     239,   240,   253,   248,   249,   252,   251,   642,   253,     8,
     255,   251,   257,   260,   357,   224,   225,   226,   227,   239,
     240,   364,   252,   251,    61,   660,   248,   249,   251,   251,
     260,   253,   254,   248,   249,   257,   251,   555,   253,   248,
     249,   251,   257,   224,   225,   226,   227,   234,   235,   684,
    2129,   224,   225,   226,   227,   251,   545,   224,   225,   226,
     227,   224,   225,   226,   227,   251,   432,   248,   249,   139,
     239,   240,   248,   249,   102,   248,   249,   105,   106,   107,
     423,   424,   105,   239,   240,   428,   429,   157,   723,   139,
     118,   260,   251,   239,   240,   255,   166,   167,   168,   239,
     240,   444,   172,   173,   260,   120,   143,   157,   451,   239,
     240,   148,   149,   150,   260,   255,   166,   167,   168,   252,
     157,   254,   172,   173,   239,   240,  1183,   260,  1185,  2165,
     260,   474,   251,   144,   145,   146,   147,   251,   251,   150,
     253,  1198,   252,   139,   257,   260,   251,   260,   159,    99,
     260,   162,   102,   181,   191,   105,   251,   107,   319,   320,
     503,   157,   239,   240,   239,   240,   327,   328,   118,   206,
     166,   167,   168,   239,   240,   102,   172,   173,   105,   252,
     107,   254,  2218,   260,   527,   260,   256,   260,  1956,   252,
     251,   534,   535,   251,   260,   561,   539,   260,   541,   542,
     543,   544,   545,   692,   239,   240,   256,   550,   245,   255,
     252,   554,   555,   556,   557,   558,   559,   560,   260,   562,
     560,   564,   562,   260,   261,   260,   105,     8,   107,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   590,   239,   240,
     252,   250,   254,   596,  1311,     6,     7,   256,   260,   740,
    1317,   239,   240,   239,   240,   239,   240,   239,   240,   260,
     239,   240,   239,   240,   251,   618,   619,   252,   255,   239,
     240,   252,   260,   254,   260,   260,   260,   251,   260,   260,
    1261,   260,   251,   260,   239,   240,   248,   249,   634,   635,
     260,   102,    99,   255,   105,   102,  1363,   942,   105,     6,
     239,   240,   107,   102,     8,   260,   105,   118,   107,   251,
    1377,   118,   251,   666,   667,   668,   255,  1384,   671,   118,
     239,   240,   241,   242,   243,   244,   245,   252,   252,   705,
     254,   250,   252,   251,   254,   260,   260,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   255,   700,   701,   702,
     703,   704,   255,   706,   707,   708,   709,   710,   256,   709,
     713,   105,   260,   762,   241,   242,   243,   244,   245,   251,
     251,   724,   253,   250,   248,   249,   423,   244,   245,   102,
     251,   255,   253,   250,   737,  1466,   433,   144,   145,   144,
     145,   251,   256,   150,   747,   150,   260,     8,   256,   256,
     753,   256,   260,   260,   255,   260,   256,   256,   455,   256,
     260,   260,   255,   260,   256,   256,   769,   770,   260,   260,
       6,     7,   775,   799,   777,   916,   256,   780,   781,   256,
     260,   256,   255,   260,   787,   260,   789,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   252,   256,   254,   255,   250,
     260,   632,   633,   256,   256,   256,   637,   260,   260,   822,
     256,   824,   256,   256,   260,  1556,   260,   260,   256,   256,
     256,   256,   260,   260,   260,   260,   256,  1568,   105,    54,
     260,   256,   539,   102,   541,   260,   543,   544,   545,   257,
     102,   259,   256,   256,   857,   256,   260,   260,   256,   260,
     557,   558,   260,   256,   867,   256,   256,   260,   256,   260,
     260,   105,   260,  2118,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   251,   256,   253,   256,   250,   260,   252,   260,
     254,   256,   905,   105,   930,   260,  1047,  1048,   256,  2151,
       4,     4,   260,   256,     6,   918,   256,   260,   256,   256,
     260,   256,   260,   260,   927,   260,   256,   256,     4,   256,
     260,   260,  2177,   260,   256,   938,   256,   256,   260,     4,
     260,   260,   256,   640,     6,   256,   260,   256,   256,   260,
     256,   260,   260,  2195,   260,   256,   256,   256,   256,   260,
     260,   260,   260,   251,   251,   253,   663,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   251,   251,   253,   256,   250,
     205,   252,   260,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   251,   700,   701,   702,   703,   239,   240,   706,
     707,   708,   252,   251,   254,   255,     4,     6,     6,   716,
     251,     6,   719,  1049,   253,   251,   253,   255,  1343,     6,
     255,     6,   251,     9,   731,   259,   259,   251,   251,  1042,
     251,   251,   251,   258,   251,   251,   251,   255,   251,   189,
    1053,   189,   189,   128,   255,  1058,   251,   251,  1199,  1200,
     251,   251,  1693,  1694,   761,   189,   763,   255,  1071,   251,
     251,   251,   255,  1076,   251,     4,   255,   255,   251,   255,
     295,   255,   251,   780,   251,   251,   251,   251,   251,   251,
       6,     6,   789,   253,     6,   310,   255,   255,   255,   314,
     255,   255,   253,   253,   253,     6,  1109,  1110,     6,  1112,
    1113,  1114,   255,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,     8,   945,  1128,   189,   253,   251,   251,
     251,   952,   251,   251,   251,   956,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     6,     6,   255,     6,   250,     6,
       8,     6,     8,  1166,  1167,  1168,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   255,     7,   255,  1190,   250,   255,
       6,   255,    94,   260,   252,   256,     7,     6,     6,   252,
       6,   260,   257,  1206,  1207,  1208,   255,   255,   255,   255,
     250,    65,     8,   428,   429,     4,     7,     7,   251,     6,
     252,     6,     6,  1364,  1365,   255,     7,     7,     6,   444,
       6,   256,   186,   255,   252,   256,   256,   254,     6,   255,
       7,     6,   257,   253,   941,   251,   943,   944,  1563,     4,
     255,  1546,     6,     6,     6,  1550,     6,     6,   252,  1262,
     957,   253,     7,     7,     7,  1261,     7,     7,     7,     7,
       7,     7,     7,     7,     7,  1278,  1279,  1280,     7,   976,
       7,     7,     7,   255,     6,   252,  1289,  1108,   254,   260,
     260,  1294,   260,   256,   252,  1298,   260,     7,   995,   255,
     257,   256,     7,   255,  1307,   255,  1309,     4,     6,  1312,
     257,     6,   256,   256,   139,   255,     7,     6,   257,     7,
       7,     7,   252,   260,  1327,   252,   260,   542,     9,   260,
     252,   254,   257,   259,  1031,     7,   189,   160,   256,   554,
    1343,   556,  1973,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,  1387,  1365,  1389,   255,   250,     6,  1370,     6,  1372,
       6,     4,    47,    47,   257,   251,   255,   251,   255,  1076,
     251,   251,   257,     4,   257,     7,  1389,     7,     7,   189,
     252,   260,     7,     7,     7,     6,   252,   260,     7,  1402,
       7,     7,     7,  1406,     7,     4,   117,     4,     6,   251,
       6,   255,     7,     7,     7,  1556,     7,     7,     7,     7,
    1569,  1570,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       7,   255,     6,     6,   250,     6,   105,     7,     7,     6,
       6,     4,  1767,     4,   258,   260,     6,  1460,  1461,  1462,
     252,   260,   255,     6,     6,  1468,  1469,  1470,   256,   255,
    1167,  1168,   255,     7,     6,     6,   253,   251,   251,     6,
     255,     6,  1485,     6,   256,     6,   257,     6,   254,     6,
     260,   132,     6,  1496,     6,     6,     6,     6,     6,     6,
       6,  1504,     6,     6,     6,  1508,     6,     5,     4,     6,
     252,     6,     4,     6,   185,     6,  1542,     7,     6,     6,
     252,     6,   737,     6,   255,   255,     6,  1668,   256,     6,
     253,   255,  1229,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   255,   255,   255,   255,   250,   255,     6,     6,   255,
    1563,   255,   255,   255,     7,     4,  1569,  1570,   252,     6,
     260,     6,  1575,   251,   257,   260,   255,  1603,   260,   255,
     260,     6,     6,   256,   251,     4,   251,     4,     5,     7,
    1593,     6,     6,     6,     6,     6,     6,  1294,     6,   139,
    1603,  1298,   103,     6,     5,  1608,   255,   252,   260,   255,
    1307,   255,  1309,     6,     6,  1312,     6,   139,   260,   139,
       6,  1770,     6,     6,  1321,   260,   252,     6,   260,     4,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     6,
       6,     6,  1783,    60,    61,    62,    63,   255,   260,     6,
       6,    68,    69,    70,    71,     6,     6,   143,     7,    76,
       6,    78,     5,  1689,     6,   252,     6,     6,  1365,   255,
     255,   255,   255,  1494,   255,    92,   255,  1680,    95,   256,
     256,     6,  1685,  1686,     7,   255,     6,  1982,     6,     6,
     252,   256,     7,     6,     6,  2010,  1376,  1693,  1694,   257,
     184,   256,   256,     6,     6,  1708,   255,  1733,     6,     6,
     256,  1714,   927,     6,  1740,  1741,   252,     6,   255,     6,
     187,     6,  1725,     6,     6,   255,     6,   256,   256,   255,
       6,   255,  1735,  1759,   252,  1738,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   251,  1756,   139,     6,   250,     6,     6,     6,
    1763,     6,     6,   143,  1767,     6,  1769,  1770,   148,   149,
     150,     6,     6,   255,   255,     6,     6,   256,   252,   255,
     255,     6,     6,  2078,   256,   256,   255,     6,   205,   206,
     207,   255,     6,     6,   255,     6,     6,     6,     6,   216,
    1621,     6,  1805,   220,     6,   222,   223,  2131,   471,  1434,
    1613,   191,  1899,  1939,  1676,  1401,     3,  1060,     3,     3,
       3,  1969,  1825,  1539,  2119,     3,   206,  1042,  1763,   611,
    1740,  1570,   780,    -1,  1837,  1838,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1058,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1862,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1874,  1569,  1570,    -1,  1901,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1888,    -1,    -1,  1709,  1710,
    1711,  1712,  1713,  1714,  1109,  1110,  1593,  1112,  1113,  1114,
      -1,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,     6,    -1,    -1,    -1,    -1,    -1,    -1,  1944,    -1,
      -1,    -1,  1925,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,  1940,    -1,    -1,
     250,    -1,  1945,    -1,    -1,  1948,  1949,    -1,    -1,    -1,
      -1,  1166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1967,    -1,    -1,  1970,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1190,    -1,  1973,  1981,    -1,
      -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1206,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,  2010,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,  2021,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,  1735,    -1,
      -1,  1738,   250,   423,    -1,    -1,    -1,  1262,  2051,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1753,    -1,  1755,    -1,
      -1,    -1,    -1,  1278,  1279,  1280,    -1,    -1,  2094,    -1,
      -1,    -1,    -1,  1770,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
    2103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1805,     6,
      -1,    -1,  1327,    -1,    -1,    -1,    -1,    -1,  2121,  2122,
    2123,  2124,  2125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,   539,
      -1,   541,  2165,   543,   544,  1986,  1987,  1988,  1989,  1990,
      -1,    -1,    -1,    -1,  1389,    -1,    -1,   557,   558,  2182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1402,    -1,    -1,
      -1,  1406,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2218,    -1,    -1,    -1,    -1,
      -1,    -1,  2225,  2226,    -1,    -1,    -1,    -1,    -1,  2050,
      -1,    -1,    -1,  2054,    -1,    -1,  2239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1460,  1461,  1462,    -1,    -1,
      -1,    -1,    -1,  1468,  1469,  1470,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,  1496,    -1,    -1,  2105,    -1,    -1,    -1,  2109,  1504,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2125,    -1,    -1,    -1,    -1,    -1,
      -1,   691,    -1,   693,   694,   695,   696,   697,   698,    -1,
     700,   701,   702,   703,    -1,    -1,   706,   707,   708,    -1,
      -1,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,  2172,  2173,   250,    -1,    -1,    -1,    -1,    -1,    -1,
    1575,    -1,    -1,    -1,    -1,    -1,  2063,    -1,     6,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,  1603,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   789,
      -1,    -1,    -1,   116,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,  2129,    -1,    -1,    -1,   250,    -1,    -1,    -1,
     143,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,  2152,    -1,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,   178,    -1,   180,   181,   182,
      -1,   184,   185,   186,   187,   188,   189,   190,    -1,   192,
     193,   194,   195,  1708,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2204,    -1,    -1,
    1725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2225,  2226,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1756,  2239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1769,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,   272,
     273,   274,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,   291,   292,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,   312,
    1825,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,   328,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   338,   339,    -1,    -1,    -1,
      -1,     4,     5,    -1,    -1,    -1,    -1,  1862,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     363,   364,    -1,    -1,    -1,   368,   369,   370,    -1,   372,
      -1,    -1,    -1,   376,   377,   378,    -1,    -1,   381,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,  1076,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    70,    71,    -1,
    1925,    -1,    -1,    76,    -1,    78,    -1,   420,    -1,    -1,
      -1,   424,   425,    -1,    -1,  1940,    -1,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   441,   442,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1967,   456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1981,    -1,    -1,    -1,
      -1,    -1,    -1,   476,   477,   478,   479,    -1,    -1,    -1,
      -1,   484,    -1,    -1,    -1,   488,    -1,  1167,  1168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   502,
     503,    -1,    -1,    -1,   507,    -1,  2021,    -1,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,    -1,   537,   538,  2051,   540,    -1,    -1,
      -1,    -1,   205,   206,   207,    -1,   549,    -1,    -1,   552,
     553,    -1,    -1,   216,    -1,    -1,   559,   220,    -1,   222,
      -1,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,    -1,   597,   598,    -1,    -1,    -1,    -1,
       6,    -1,   605,   606,   607,    -1,    -1,    -1,    -1,    -1,
     613,   614,   615,   616,  1294,   618,   619,    -1,  1298,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1307,    -1,  1309,
      -1,    -1,  1312,    -1,   637,   638,   639,    -1,    -1,    -1,
     643,   644,   645,   646,   647,   648,   649,   650,   651,    -1,
    2165,    -1,    -1,    -1,   657,    -1,   659,    -1,    -1,   662,
      -1,     6,    -1,   666,   667,   668,   669,    -1,   671,   672,
     673,   674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1365,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   699,    -1,    -1,    -1,
      -1,    -1,    -1,  2218,    -1,    -1,    -1,    -1,    -1,    -1,
     713,    -1,    -1,    -1,    -1,    -1,    -1,   720,    -1,   722,
      -1,    -1,   725,   726,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   747,    -1,   749,    -1,    -1,    -1,
      -1,   754,   755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   769,    -1,   771,   772,
      -1,    -1,   775,    -1,   777,   778,    -1,   199,    -1,   782,
      -1,   784,    -1,    -1,    -1,    -1,    -1,   790,    -1,    -1,
      -1,   794,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,   820,    -1,   822,
      -1,   824,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
     272,    -1,    -1,   275,   857,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,   867,   868,   869,    -1,    -1,   291,
     292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   199,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,   905,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1593,    -1,   918,   338,    -1,    -1,    -1,
      -1,    -1,    -1,   926,    -1,    -1,    -1,   930,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   938,    -1,    -1,    -1,    -1,
      -1,    -1,   364,   946,   947,    -1,    -1,    -1,    -1,   952,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,   972,
      -1,    -1,    -1,    -1,   291,   292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   994,    -1,   996,   997,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   424,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1015,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1038,    -1,    -1,    -1,    -1,
      -1,    -1,  1045,    -1,    -1,    -1,    -1,  1050,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1735,    -1,    -1,  1738,    -1,
      -1,    -1,  1065,  1066,    -1,    -1,    -1,    -1,  1071,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   503,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
    1103,  1104,  1105,  1106,   250,   527,    -1,   424,    -1,    -1,
      -1,    -1,   534,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,
      -1,  1144,   564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1154,  1155,  1156,    -1,    -1,    -1,    -1,  1161,  1162,
      -1,  1164,    -1,    -1,    -1,    -1,    -1,    -1,   590,     4,
       5,    -1,    -1,    -1,    -1,  1178,  1179,    -1,    -1,    -1,
      -1,    -1,    -1,  1186,  1187,    -1,    -1,    -1,    -1,    -1,
    1193,    -1,  1195,  1196,    -1,    -1,   618,   619,    -1,  1202,
    1203,    -1,    -1,    -1,  1207,  1208,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,  1241,    -1,
      -1,    76,    -1,    78,   666,   667,   668,   564,    -1,   671,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,   107,    -1,  1277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,  1289,    -1,    -1,    -1,
      -1,   713,    -1,    -1,  1297,    -1,    -1,    -1,    -1,    -1,
     135,   618,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1318,  1319,    -1,    -1,    -1,
    1323,    -1,    -1,    -1,    -1,   747,    -1,    -1,    -1,    -1,
      -1,  1334,    -1,    -1,  1337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   769,    -1,   666,
     667,   668,    -1,   775,   671,   777,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1366,    -1,    -1,  1369,  1370,  1371,  1372,
     205,   206,   207,    -1,    -1,    -1,    -1,  1380,    -1,    -1,
    1383,   216,  1385,  1386,  1387,   220,    -1,   222,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   713,    -1,    -1,    -1,
     822,    -1,   824,    -1,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,   249,    -1,    -1,    -1,    -1,    -1,
     255,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     747,    -1,    -1,    -1,    -1,   857,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   867,    -1,    -1,    -1,    -1,
      -1,    -1,   769,    -1,    -1,    -1,    -1,    -1,   775,    -1,
     777,    -1,    -1,    -1,  1467,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1476,  1477,  1478,    -1,    -1,    -1,    -1,
      -1,    -1,  1485,   905,  1487,    -1,    -1,    -1,    -1,    -1,
      -1,  1494,    -1,    -1,    -1,    -1,   918,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1508,    -1,    -1,    -1,    -1,
    1513,  1514,    -1,    -1,    -1,    -1,   938,    -1,    -1,  1522,
    1523,  1524,    -1,    -1,  2204,    -1,    -1,    -1,    -1,    -1,
      -1,  1534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     857,  1544,    -1,    -1,    -1,  2225,  2226,    -1,    -1,    -1,
     867,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2239,
      -1,    -1,    -1,    -1,  1567,    -1,    -1,    -1,    -1,    -1,
    1573,  1574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   905,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   918,    -1,    -1,    -1,  1608,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   938,    -1,    -1,    -1,    -1,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,    -1,  1648,  1649,  1650,   250,  1071,
      -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,    -1,    -1,
      -1,  1664,  1665,  1666,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,  1678,    -1,    -1,    -1,    -1,
      -1,    -1,  1685,  1686,  1687,    -1,  1689,    -1,    -1,    -1,
      -1,    -1,  1695,  1696,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,  1128,    -1,    -1,    -1,
      -1,  1714,    -1,    -1,    -1,    -1,  1719,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1733,    -1,    -1,  1736,    -1,    -1,    -1,  1740,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1749,  1750,    -1,  1752,
      -1,    -1,    -1,    -1,  1071,    -1,   446,  1760,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,  1776,    -1,    -1,    -1,    -1,  1781,  1782,
      -1,    -1,    -1,    -1,    -1,  1207,  1208,    -1,    -1,    -1,
      -1,    -1,  1795,    -1,    -1,  1798,  1799,    -1,  1801,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1128,    -1,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,  1837,  1838,   250,     7,     8,    -1,
      -1,  1844,  1845,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,    -1,
     550,    -1,  1865,    -1,    -1,    -1,    -1,  1289,    -1,    -1,
      -1,  1874,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1884,  1885,    -1,    -1,  1888,    -1,    -1,    -1,    -1,
    1207,  1208,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,   601,    -1,    -1,   250,    -1,    -1,    -1,    -1,  1922,
    1923,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
    1943,    -1,    -1,   250,    -1,  1948,  1949,  1950,  1370,    -1,
    1372,    -1,  1955,    -1,    -1,  1958,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1970,    -1,    -1,
      -1,    -1,  1289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1993,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,  2018,    -1,    -1,    -1,    -1,
      -1,  2024,    -1,    -1,  2027,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,  1370,    -1,  1372,  2059,    -1,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,  2084,  2085,    -1,    -1,    -1,  1508,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2099,  2100,    -1,  2102,
    2103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2116,    -1,    -1,    -1,    -1,  2121,  2122,
    2123,  2124,  2125,    -1,    -1,    -1,    -1,    -1,  2131,    -1,
      -1,    -1,  2135,    -1,    -1,    -1,    -1,    -1,    -1,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     143,   841,   842,   843,   844,    -1,   846,   847,   848,   849,
    2163,    -1,    -1,    -1,    -1,  2168,  2169,  2170,    -1,    -1,
     860,    -1,   862,    -1,    -1,    -1,    -1,    -1,    -1,  2182,
      -1,    -1,   872,    -1,    -1,    -1,  1608,    -1,    -1,   879,
     880,  1508,    -1,    -1,    -1,    -1,    -1,    -1,   888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2210,  2211,  2212,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,    -1,   242,
     243,    13,    14,    -1,    -1,    -1,    -1,    -1,   251,   252,
      -1,    -1,    -1,  1685,  1686,    -1,    -1,    -1,    -1,    -1,
     263,   264,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,  1714,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,  1001,  1002,  1003,    -1,    -1,    -1,  1007,  1008,    -1,
      -1,  1011,  1012,  1013,  1014,    -1,  1016,    -1,    -1,    -1,
      -1,  1021,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,   115,   116,   117,   118,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,  1685,  1686,
     132,   133,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     383,   384,   385,    -1,   156,    -1,   389,   390,   391,   392,
     393,   394,   395,    -1,   397,    -1,    -1,    -1,    -1,   402,
     403,    -1,  1102,   406,    -1,  1837,  1838,  1107,    -1,   181,
     182,   183,    -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,
      -1,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,  1874,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1888,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,   115,   116,   117,   118,     8,    -1,   121,
      -1,    -1,    -1,    -1,   256,    -1,   128,   129,    -1,    -1,
     132,   133,    -1,   135,   136,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1204,    -1,    -1,    -1,    -1,    -1,
    1837,  1838,    -1,    -1,   156,    -1,  1948,  1949,    -1,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,  1970,   181,
     182,   183,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1985,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1888,    -1,     3,     4,    -1,    -1,    -1,    -1,   572,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,    -1,    56,    57,    58,    59,
      -1,  1948,  1949,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,  1970,    -1,    -1,  1346,    -1,    -1,    -1,
      90,    91,    -1,    93,    -1,    -1,    -1,    -1,  1985,    -1,
      -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,  2103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1388,  2121,
    2122,  2123,  2124,  2125,    -1,    -1,    -1,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
    1420,  1421,  1422,  1423,  1424,    -1,    -1,    -1,    -1,  1429,
    1430,    -1,    -1,    -1,    -1,  1435,    -1,  1437,    -1,    -1,
      -1,  1441,    -1,    -1,  1444,    -1,    -1,    -1,    -1,    -1,
    2182,    -1,    -1,    -1,    -1,    -1,  1456,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,
      -1,    -1,    -1,   213,   214,   215,  2103,   217,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2121,  2122,  2123,  2124,  2125,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,   255,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1530,    -1,  1532,    -1,    -1,    -1,  1536,    -1,  1538,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1569,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     883,    -1,    -1,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,     3,     4,     5,   250,    -1,    -1,    -1,
      10,    11,    12,    -1,   917,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     8,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,  1667,    68,    69,
      70,    71,    -1,    -1,    74,    75,    76,    -1,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    92,    93,    -1,    95,    -1,    -1,    -1,    99,
      -1,    -1,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
     130,   131,    -1,   133,    -1,   135,    -1,    -1,   138,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1772,    -1,    -1,  1775,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1096,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,   222,   223,    -1,    -1,  1826,  1827,    -1,  1829,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,   255,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,  1191,    -1,
      -1,    -1,  1892,  1893,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,    -1,
     254,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,  1941,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    68,    69,    70,    71,    -1,    -1,    74,    75,
      76,    -1,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,    95,
      -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,  1347,  1348,    -1,    -1,   114,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,   130,   131,    -1,   133,    -1,   135,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,   150,   151,   152,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,   162,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,   250,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,  1439,    -1,   204,   205,
     206,   207,   208,   209,    -1,    -1,  1449,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   222,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,   251,     3,     4,     5,   255,
       7,  2191,   258,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    95,    -1,
      -1,    -1,    99,    -1,    -1,   102,     5,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,  1607,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,    -1,    -1,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,   222,   223,   224,   225,   226,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
      -1,   248,   249,    -1,   251,    -1,   253,     3,     4,     5,
     257,   258,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   207,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,   216,    64,    65,
      -1,   220,    -1,   222,    -1,    -1,    -1,    -1,    74,    75,
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
     246,    -1,    -1,    -1,    -1,   251,     3,     4,    -1,   255,
      -1,     8,   258,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,   251,     3,     4,     5,    -1,   256,
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
      -1,    -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,
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
      -1,    -1,   256,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,
     209,    -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,    -1,   251,     3,     4,    -1,   255,   256,    -1,   258,
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
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,
       3,     4,    -1,   255,    -1,    -1,   258,    10,    11,    12,
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
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,
       4,    -1,    -1,   256,    -1,   258,    10,    11,    12,    -1,
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
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,     3,     4,    -1,
     255,    -1,    -1,   258,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,   209,    -1,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,    -1,    -1,    -1,    -1,   251,     3,     4,    -1,   255,
      -1,     8,   258,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,    -1,
      -1,   208,   209,    -1,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
       3,     4,    -1,    -1,   251,     8,    -1,    10,    11,    12,
      -1,   258,    15,    16,    17,    18,    19,    20,    21,    22,
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
      -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,    -1,   208,   209,    -1,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,     3,     4,    -1,    -1,   251,    -1,
      -1,    10,    11,    12,    -1,   258,    15,    16,    17,    18,
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
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,    -1,    -1,   208,   209,    -1,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,
      -1,    -1,    -1,    -1,    -1,   246,     3,     4,     5,    -1,
     251,    -1,    -1,    10,    11,    12,    -1,   258,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    -1,    95,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    76,    -1,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,    -1,    -1,    -1,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,   255,    -1,
      -1,   258,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,    -1,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,   222,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,    -1,    -1,    -1,    -1,   251,     3,     4,
       5,   255,    -1,    -1,   258,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    76,    -1,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,    -1,
      95,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    93,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,    -1,    -1,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,   220,    -1,   222,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
     255,    -1,    -1,   258,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,    -1,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,   220,    -1,
     222,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,
      -1,    -1,    -1,    -1,   246,     3,     4,    -1,    -1,   251,
      -1,    -1,    10,    11,    12,    -1,   258,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,     3,
       4,    -1,    90,    91,     8,    93,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,   204,    -1,    -1,    -1,
     208,    -1,   260,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   239,   240,    -1,    -1,    -1,    -1,    -1,   246,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,   255,    -1,    -1,
     258,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,   260,   208,    -1,    -1,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,     3,     4,    -1,    -1,   251,    -1,    -1,
      10,    11,    12,    -1,   258,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    91,    -1,    93,     3,     4,    -1,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    -1,    93,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,   204,    -1,    -1,   250,   208,    -1,
      -1,    -1,   255,   213,   214,   215,    -1,   217,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   260,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,
      -1,    -1,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,     3,     4,
      -1,     6,   251,    -1,    -1,    10,    11,    12,    -1,   258,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,     3,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    93,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,   204,
      -1,    -1,   250,   208,    -1,    -1,    -1,   255,   213,   214,
     215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,
      -1,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
     204,    -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,     3,     4,    -1,    -1,   251,    -1,    -1,
      10,    11,    12,    -1,   258,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      90,    91,    -1,    93,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    93,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,
     260,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
      -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,    -1,    -1,    -1,   258,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,
      -1,   260,   208,    -1,    -1,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,     3,     4,    -1,    -1,   251,   252,    -1,    10,    11,
      12,    -1,   258,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      -1,    93,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,    -1,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,   204,    -1,   250,    -1,   208,    -1,    -1,    -1,
      -1,   213,   214,   215,   260,   217,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,   239,   240,    -1,
      -1,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,   251,
     205,   206,   207,    -1,    -1,    -1,   258,    -1,    -1,    13,
      14,   216,    -1,    -1,    -1,   220,    -1,   222,   223,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,   252,    -1,   254,
     255,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
     135,   115,   116,   117,   118,    -1,    -1,   121,    13,    14,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,   132,   133,
      -1,   135,   136,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   181,   182,   183,
     205,   206,   207,    -1,    -1,   260,    -1,    13,    14,    -1,
      -1,   216,    -1,    -1,    -1,   220,    -1,   222,   223,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
     115,   116,   117,   118,    -1,    -1,   121,    -1,    -1,    -1,
     255,    -1,    -1,   128,   129,    -1,    -1,   132,   133,    -1,
     135,   136,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   181,   182,   183,   115,
     116,   117,   118,    13,    14,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,   132,   133,    -1,   135,
     136,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   255,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,   250,    -1,   252,    -1,   254,
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
     250,    -1,    -1,    -1,   254,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250,    -1,   252,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    -1,    -1,    -1,    -1,   250,    -1,   252,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,    -1,    -1,
      -1,    -1,   250
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
     280,   281,   322,   257,   252,   254,   251,   343,   343,   251,
     255,   251,   255,     8,   360,   364,   252,   257,   252,   254,
     251,   252,   252,   260,   257,   251,   260,     7,   285,     4,
     296,   297,   298,   286,   343,   343,   343,   343,   286,   354,
     357,   357,     7,   357,   357,   357,     7,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,     6,     7,   360,
     343,   343,   343,   343,   256,   343,   343,   343,   357,   364,
     364,   256,   256,   256,   260,   295,   343,   343,   351,   351,
     343,   343,   252,   357,   285,   343,   343,   343,   256,   351,
     284,   257,   284,   343,   343,   286,   256,   357,   360,   360,
       7,     7,     7,   139,   334,     6,   252,   260,     7,     7,
       7,     7,     7,   256,     4,   256,   260,   260,   260,   256,
     256,   117,     4,     6,   343,   255,     6,   251,     6,   174,
       6,   174,   256,   329,   260,   328,     7,     6,     7,     7,
       7,     7,     7,     7,     7,   313,   357,     6,   255,     6,
       6,     6,   105,     7,     7,     6,     6,   343,   357,   357,
     357,     4,   260,     8,     8,   252,     4,   108,   109,     4,
     360,   364,   343,   364,   258,   260,   299,   364,   364,   351,
     364,   252,   260,   351,   255,   308,   255,     6,   343,     6,
     255,   357,   256,   256,   343,     6,     4,   186,   187,   343,
       6,     6,     6,     7,   361,   363,     6,   253,   286,   285,
     285,     6,   272,   251,   251,   255,   282,     6,   351,   257,
     364,   343,   254,   252,   343,     8,   360,   343,   360,   256,
     256,     6,     6,   265,   351,   257,   343,     6,     6,   343,
     351,   252,   343,   255,   343,   365,   286,    47,   255,   357,
     365,   368,   254,   260,     6,   252,   252,   252,   252,     6,
       6,   132,   304,   304,   357,     6,     6,     6,   357,   139,
     189,   303,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     5,   256,   286,   286,   286,   286,   286,   260,   260,
     260,   252,   286,   286,   297,   286,   252,   286,   252,   285,
     346,   286,     6,   286,   260,   251,   253,   285,     4,   252,
     254,   286,     6,   256,   256,   357,   357,   357,     4,     6,
     283,   343,   357,   357,   357,   255,   255,     7,     6,     7,
     343,   343,   343,   255,   255,   255,   253,     6,   343,   357,
     343,     6,     6,   343,   354,   256,     5,   357,   255,   255,
     255,   255,   255,   255,   255,   357,   256,     6,   360,   255,
     343,   343,   254,     6,     6,   185,   343,   343,   343,     6,
       6,     6,     6,     7,   286,   260,   260,   286,   260,   343,
       4,   201,   300,   301,   286,   252,   286,   347,   365,   251,
     253,   343,   255,   314,     6,   314,   260,     6,     6,     7,
     283,   284,   257,     7,     6,   361,   256,   260,   343,   283,
     255,   286,   369,   370,   371,   369,   251,   343,   343,   356,
     357,   255,   251,     4,     6,   252,     6,   252,   256,   256,
     252,   256,     6,     6,   364,   251,     4,   252,   260,   251,
     256,   260,   357,   365,     7,   285,   294,   343,   359,   298,
       6,     6,     6,     6,   354,     6,     6,     6,   139,   305,
      99,   118,   103,     6,     5,   255,   343,   343,   343,   343,
     252,   346,   343,   343,   343,   286,   284,   255,   255,     6,
     303,     6,   343,   357,   139,   139,     4,     6,   360,   360,
     343,   343,   365,   256,   252,   256,   260,   313,   313,   343,
     343,   256,   260,   252,   256,   260,     6,     6,   356,   354,
     354,   354,   354,   354,   240,   354,     6,   256,   343,     6,
       6,     6,   357,   256,   260,     8,   256,   252,   255,   343,
     365,   364,   343,   364,   343,   365,   368,   370,   365,   260,
     252,   260,   256,   343,   331,   331,   357,   365,   343,     6,
       4,   362,     6,   361,   254,   357,   371,     6,   286,   286,
     269,   343,   260,   260,   256,   260,   270,   343,   343,     6,
       6,     6,     6,   343,   343,   252,     6,   343,   290,   292,
     255,   370,   256,   260,     7,     7,   143,     6,   255,   255,
     255,     5,   356,   286,   286,   260,   286,   252,   260,   252,
     254,   360,   360,     6,     6,   343,   343,   255,   256,   256,
     255,     6,     6,   255,   343,   256,   256,   256,   254,     6,
     357,     7,   255,   343,   256,   260,   260,   260,   260,   260,
     260,     6,   256,   184,   343,   343,   360,     6,     6,   252,
     286,   286,   301,   365,   256,   256,   256,   256,     6,     6,
       7,     6,   257,     6,   256,     6,     6,   252,   260,   343,
     343,   255,   357,   256,   260,   252,   252,   260,   256,   295,
     299,   357,   286,   343,   365,   374,   360,   360,   343,     6,
     256,   343,   346,   343,   256,   256,     6,     6,   356,   144,
     145,   150,   338,   144,   145,   338,   360,   313,   256,   260,
       6,   256,   357,   314,   256,     6,   360,   354,   354,   354,
     354,   354,   343,   256,   256,   256,   252,     6,   255,     6,
     361,   187,   273,   343,   260,   260,   356,     6,   343,   343,
       6,   256,   256,   291,     7,   251,   256,   256,   256,   255,
     260,   252,   260,   255,   256,   255,   354,   357,     6,   255,
     354,     6,   256,   256,   343,     6,   139,   256,   325,   255,
     256,   260,   260,   260,   260,   260,     6,     6,     6,   314,
       6,   255,   343,   343,   256,   260,   295,   365,   252,   343,
     343,   343,   360,     6,   354,     6,   354,     6,     6,   256,
     343,   328,   314,     6,   360,   360,   360,   360,   354,   360,
     331,   270,   252,   260,     6,   255,   343,   256,   260,   260,
     260,   256,   260,   260,     6,   256,   256,   326,   256,   256,
     256,   256,   260,   256,   256,   256,   276,   343,   356,   256,
     343,   343,   343,   354,   354,   328,     6,     6,     6,     6,
     360,     6,     6,     6,   255,   252,   256,     6,   256,   286,
     260,   260,   260,   256,   256,   274,   364,   279,   255,     6,
     343,   343,   343,     6,   256,   260,   255,   356,   256,   256,
     256,     6,   364,   277,   364,   256,     6,     6,   256,   260,
       6,     6,   364
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

  case 139:
#line 1457 "Gmsh.y"
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

  case 140:
#line 1472 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 141:
#line 1481 "Gmsh.y"
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

  case 146:
#line 1506 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 147:
#line 1514 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 148:
#line 1523 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 149:
#line 1531 "Gmsh.y"
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
#line 1545 "Gmsh.y"
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

  case 151:
#line 1563 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 152:
#line 1567 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 153:
#line 1574 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 154:
#line 1582 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 155:
#line 1586 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 156:
#line 1592 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 157:
#line 1596 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 158:
#line 1607 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 159:
#line 1611 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 160:
#line 1617 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 161:
#line 1621 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 162:
#line 1627 "Gmsh.y"
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

  case 163:
#line 1650 "Gmsh.y"
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

  case 164:
#line 1666 "Gmsh.y"
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

  case 165:
#line 1682 "Gmsh.y"
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

  case 166:
#line 1699 "Gmsh.y"
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

  case 167:
#line 1716 "Gmsh.y"
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

  case 168:
#line 1753 "Gmsh.y"
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

  case 169:
#line 1797 "Gmsh.y"
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

  case 170:
#line 1813 "Gmsh.y"
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

  case 171:
#line 1830 "Gmsh.y"
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

  case 172:
#line 1861 "Gmsh.y"
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

  case 173:
#line 1877 "Gmsh.y"
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

  case 174:
#line 1894 "Gmsh.y"
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

  case 175:
#line 1910 "Gmsh.y"
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

  case 176:
#line 1960 "Gmsh.y"
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

  case 177:
#line 1978 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 178:
#line 1984 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 179:
#line 1990 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 180:
#line 1997 "Gmsh.y"
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

  case 181:
#line 2028 "Gmsh.y"
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

  case 182:
#line 2043 "Gmsh.y"
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

  case 183:
#line 2065 "Gmsh.y"
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

  case 184:
#line 2088 "Gmsh.y"
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

  case 185:
#line 2111 "Gmsh.y"
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

  case 186:
#line 2134 "Gmsh.y"
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

  case 187:
#line 2158 "Gmsh.y"
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

  case 188:
#line 2182 "Gmsh.y"
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

  case 189:
#line 2206 "Gmsh.y"
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

  case 190:
#line 2232 "Gmsh.y"
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

  case 191:
#line 2249 "Gmsh.y"
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

  case 192:
#line 2265 "Gmsh.y"
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

  case 193:
#line 2283 "Gmsh.y"
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

  case 194:
#line 2301 "Gmsh.y"
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

  case 195:
#line 2314 "Gmsh.y"
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

  case 196:
#line 2326 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 197:
#line 2330 "Gmsh.y"
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

  case 198:
#line 2356 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 199:
#line 2358 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 200:
#line 2360 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 201:
#line 2362 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 202:
#line 2364 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 203:
#line 2372 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 204:
#line 2374 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 205:
#line 2376 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 206:
#line 2378 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 207:
#line 2386 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 208:
#line 2388 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 209:
#line 2390 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 210:
#line 2398 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 211:
#line 2400 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 212:
#line 2402 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 213:
#line 2404 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 214:
#line 2414 "Gmsh.y"
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

  case 215:
#line 2430 "Gmsh.y"
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

  case 216:
#line 2446 "Gmsh.y"
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

  case 217:
#line 2462 "Gmsh.y"
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

  case 218:
#line 2478 "Gmsh.y"
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

  case 219:
#line 2494 "Gmsh.y"
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

  case 220:
#line 2511 "Gmsh.y"
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

  case 221:
#line 2548 "Gmsh.y"
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

  case 222:
#line 2570 "Gmsh.y"
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

  case 223:
#line 2593 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 224:
#line 2594 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 225:
#line 2599 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 226:
#line 2603 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 227:
#line 2607 "Gmsh.y"
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

  case 228:
#line 2624 "Gmsh.y"
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

  case 229:
#line 2644 "Gmsh.y"
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

  case 230:
#line 2664 "Gmsh.y"
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

  case 231:
#line 2683 "Gmsh.y"
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

  case 232:
#line 2710 "Gmsh.y"
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

  case 233:
#line 2729 "Gmsh.y"
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

  case 234:
#line 2751 "Gmsh.y"
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

  case 235:
#line 2766 "Gmsh.y"
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

  case 236:
#line 2781 "Gmsh.y"
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

  case 237:
#line 2800 "Gmsh.y"
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

  case 238:
#line 2851 "Gmsh.y"
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

  case 239:
#line 2872 "Gmsh.y"
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

  case 240:
#line 2894 "Gmsh.y"
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

  case 241:
#line 2916 "Gmsh.y"
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

  case 242:
#line 3021 "Gmsh.y"
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

  case 243:
#line 3037 "Gmsh.y"
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

  case 244:
#line 3072 "Gmsh.y"
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

  case 245:
#line 3094 "Gmsh.y"
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

  case 246:
#line 3116 "Gmsh.y"
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

  case 247:
#line 3128 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 248:
#line 3134 "Gmsh.y"
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

  case 249:
#line 3149 "Gmsh.y"
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

  case 250:
#line 3177 "Gmsh.y"
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

  case 251:
#line 3189 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 252:
#line 3198 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 253:
#line 3205 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 254:
#line 3217 "Gmsh.y"
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

  case 255:
#line 3237 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 256:
#line 3241 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 257:
#line 3246 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 258:
#line 3250 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 259:
#line 3255 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 260:
#line 3262 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 261:
#line 3269 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 262:
#line 3276 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 263:
#line 3288 "Gmsh.y"
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

  case 264:
#line 3361 "Gmsh.y"
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

  case 265:
#line 3379 "Gmsh.y"
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

  case 266:
#line 3404 "Gmsh.y"
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

  case 267:
#line 3419 "Gmsh.y"
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

  case 268:
#line 3452 "Gmsh.y"
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

  case 269:
#line 3464 "Gmsh.y"
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

  case 270:
#line 3496 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 271:
#line 3500 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 272:
#line 3505 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 273:
#line 3512 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 274:
#line 3517 "Gmsh.y"
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

  case 275:
#line 3527 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 276:
#line 3532 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 277:
#line 3538 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 278:
#line 3546 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 279:
#line 3550 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 280:
#line 3554 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 281:
#line 3558 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 282:
#line 3562 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 283:
#line 3566 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 284:
#line 3570 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 285:
#line 3580 "Gmsh.y"
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

  case 286:
#line 3643 "Gmsh.y"
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

  case 287:
#line 3659 "Gmsh.y"
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

  case 288:
#line 3676 "Gmsh.y"
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

  case 289:
#line 3693 "Gmsh.y"
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

  case 290:
#line 3715 "Gmsh.y"
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

  case 291:
#line 3737 "Gmsh.y"
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

  case 292:
#line 3772 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 293:
#line 3780 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 294:
#line 3788 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 295:
#line 3794 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 296:
#line 3801 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 297:
#line 3808 "Gmsh.y"
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

  case 298:
#line 3828 "Gmsh.y"
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

  case 299:
#line 3854 "Gmsh.y"
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

  case 300:
#line 3866 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 301:
#line 3877 "Gmsh.y"
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

  case 302:
#line 3895 "Gmsh.y"
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

  case 303:
#line 3913 "Gmsh.y"
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

  case 304:
#line 3931 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 3937 "Gmsh.y"
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

  case 306:
#line 3955 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 307:
#line 3961 "Gmsh.y"
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

  case 308:
#line 3981 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 309:
#line 3987 "Gmsh.y"
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

  case 310:
#line 4005 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 311:
#line 4011 "Gmsh.y"
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

  case 312:
#line 4028 "Gmsh.y"
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

  case 313:
#line 4044 "Gmsh.y"
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

  case 314:
#line 4061 "Gmsh.y"
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

  case 315:
#line 4079 "Gmsh.y"
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

  case 316:
#line 4102 "Gmsh.y"
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

  case 317:
#line 4129 "Gmsh.y"
    {
    ;}
    break;

  case 318:
#line 4132 "Gmsh.y"
    {
    ;}
    break;

  case 319:
#line 4138 "Gmsh.y"
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

  case 320:
#line 4150 "Gmsh.y"
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

  case 321:
#line 4170 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 322:
#line 4174 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 323:
#line 4178 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 324:
#line 4182 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 325:
#line 4186 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 326:
#line 4190 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 327:
#line 4194 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 328:
#line 4198 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 329:
#line 4207 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 330:
#line 4219 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 331:
#line 4220 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 332:
#line 4221 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 333:
#line 4222 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 334:
#line 4223 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 335:
#line 4227 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 336:
#line 4228 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 337:
#line 4229 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 338:
#line 4230 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 339:
#line 4231 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 340:
#line 4236 "Gmsh.y"
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

  case 341:
#line 4259 "Gmsh.y"
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

  case 342:
#line 4279 "Gmsh.y"
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

  case 343:
#line 4300 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 344:
#line 4304 "Gmsh.y"
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

  case 345:
#line 4319 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 346:
#line 4323 "Gmsh.y"
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

  case 347:
#line 4339 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 348:
#line 4343 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 349:
#line 4348 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 350:
#line 4352 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 351:
#line 4358 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 352:
#line 4362 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 353:
#line 4369 "Gmsh.y"
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

  case 354:
#line 4391 "Gmsh.y"
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

  case 355:
#line 4432 "Gmsh.y"
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

  case 356:
#line 4476 "Gmsh.y"
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

  case 357:
#line 4515 "Gmsh.y"
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

  case 358:
#line 4540 "Gmsh.y"
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

  case 359:
#line 4552 "Gmsh.y"
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

  case 360:
#line 4564 "Gmsh.y"
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

  case 361:
#line 4576 "Gmsh.y"
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

  case 362:
#line 4588 "Gmsh.y"
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

  case 363:
#line 4605 "Gmsh.y"
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

  case 364:
#line 4622 "Gmsh.y"
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

  case 365:
#line 4652 "Gmsh.y"
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

  case 366:
#line 4678 "Gmsh.y"
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

  case 367:
#line 4705 "Gmsh.y"
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

  case 368:
#line 4737 "Gmsh.y"
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

  case 369:
#line 4764 "Gmsh.y"
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

  case 370:
#line 4790 "Gmsh.y"
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

  case 371:
#line 4816 "Gmsh.y"
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

  case 372:
#line 4842 "Gmsh.y"
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

  case 373:
#line 4868 "Gmsh.y"
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

  case 374:
#line 4889 "Gmsh.y"
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

  case 375:
#line 4900 "Gmsh.y"
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

  case 376:
#line 4948 "Gmsh.y"
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

  case 377:
#line 5002 "Gmsh.y"
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

  case 378:
#line 5017 "Gmsh.y"
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

  case 379:
#line 5029 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 380:
#line 5040 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 381:
#line 5047 "Gmsh.y"
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

  case 382:
#line 5062 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 383:
#line 5075 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 384:
#line 5076 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 385:
#line 5077 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 386:
#line 5082 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 387:
#line 5088 "Gmsh.y"
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

  case 388:
#line 5100 "Gmsh.y"
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

  case 389:
#line 5118 "Gmsh.y"
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

  case 390:
#line 5145 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 391:
#line 5146 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 392:
#line 5147 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 393:
#line 5148 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 394:
#line 5149 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 395:
#line 5150 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 396:
#line 5151 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 397:
#line 5152 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 398:
#line 5154 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 399:
#line 5160 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 400:
#line 5161 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 401:
#line 5162 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 402:
#line 5163 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 403:
#line 5164 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5165 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 405:
#line 5166 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 406:
#line 5167 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 407:
#line 5168 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5169 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5170 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5171 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 411:
#line 5172 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 412:
#line 5173 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 413:
#line 5174 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 414:
#line 5175 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 415:
#line 5176 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 416:
#line 5177 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 417:
#line 5178 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5179 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 419:
#line 5180 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5181 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5182 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5183 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 423:
#line 5184 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5185 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 425:
#line 5186 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5187 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5188 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5189 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 429:
#line 5190 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 430:
#line 5191 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 431:
#line 5192 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 432:
#line 5193 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 433:
#line 5194 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 434:
#line 5195 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 435:
#line 5196 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 436:
#line 5197 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 437:
#line 5206 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 438:
#line 5207 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 439:
#line 5208 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 440:
#line 5209 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 441:
#line 5210 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 442:
#line 5211 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 443:
#line 5212 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 444:
#line 5213 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 445:
#line 5214 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 446:
#line 5215 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 447:
#line 5216 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 448:
#line 5221 "Gmsh.y"
    { init_options(); ;}
    break;

  case 449:
#line 5223 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 450:
#line 5229 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 451:
#line 5231 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 452:
#line 5236 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 453:
#line 5241 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 454:
#line 5246 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 455:
#line 5251 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 456:
#line 5255 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 457:
#line 5259 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 458:
#line 5263 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 459:
#line 5267 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 460:
#line 5271 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 461:
#line 5275 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 462:
#line 5279 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 463:
#line 5285 "Gmsh.y"
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

  case 464:
#line 5300 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 465:
#line 5304 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 466:
#line 5310 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 467:
#line 5315 "Gmsh.y"
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

  case 468:
#line 5334 "Gmsh.y"
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
#line 5354 "Gmsh.y"
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

  case 470:
#line 5385 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 471:
#line 5389 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 472:
#line 5393 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 473:
#line 5397 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 474:
#line 5401 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 475:
#line 5405 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 476:
#line 5409 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 477:
#line 5414 "Gmsh.y"
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

  case 478:
#line 5424 "Gmsh.y"
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

  case 479:
#line 5434 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 480:
#line 5439 "Gmsh.y"
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

  case 481:
#line 5450 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 482:
#line 5459 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 483:
#line 5464 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 484:
#line 5469 "Gmsh.y"
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

  case 485:
#line 5496 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 486:
#line 5498 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 487:
#line 5503 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 488:
#line 5505 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 489:
#line 5510 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 490:
#line 5517 "Gmsh.y"
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

  case 491:
#line 5533 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 492:
#line 5535 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 493:
#line 5540 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 494:
#line 5549 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 495:
#line 5551 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 496:
#line 5556 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 497:
#line 5558 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 498:
#line 5563 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 499:
#line 5567 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 500:
#line 5571 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 501:
#line 5575 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 502:
#line 5579 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 503:
#line 5586 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 504:
#line 5590 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 505:
#line 5594 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 506:
#line 5598 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 507:
#line 5605 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 508:
#line 5610 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 509:
#line 5617 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 510:
#line 5622 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 511:
#line 5626 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 512:
#line 5631 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 513:
#line 5635 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 514:
#line 5643 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 515:
#line 5654 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 516:
#line 5658 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 517:
#line 5662 "Gmsh.y"
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

  case 518:
#line 5676 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 519:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 520:
#line 5692 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 521:
#line 5699 "Gmsh.y"
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

  case 522:
#line 5709 "Gmsh.y"
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

  case 523:
#line 5732 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 524:
#line 5737 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 525:
#line 5743 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 526:
#line 5748 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 527:
#line 5754 "Gmsh.y"
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

  case 528:
#line 5765 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 529:
#line 5772 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 530:
#line 5777 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 531:
#line 5783 "Gmsh.y"
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

  case 532:
#line 5795 "Gmsh.y"
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

  case 533:
#line 5809 "Gmsh.y"
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
#line 5819 "Gmsh.y"
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
#line 5829 "Gmsh.y"
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

  case 536:
#line 5839 "Gmsh.y"
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

  case 537:
#line 5851 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 538:
#line 5855 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 539:
#line 5860 "Gmsh.y"
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

  case 540:
#line 5872 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 541:
#line 5876 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 542:
#line 5880 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 543:
#line 5884 "Gmsh.y"
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

  case 544:
#line 5902 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 545:
#line 5910 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 546:
#line 5918 "Gmsh.y"
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

  case 547:
#line 5947 "Gmsh.y"
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

  case 548:
#line 5957 "Gmsh.y"
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

  case 549:
#line 5973 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 550:
#line 5984 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 551:
#line 5989 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 552:
#line 5993 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 553:
#line 5997 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 554:
#line 6009 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 555:
#line 6013 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 556:
#line 6025 "Gmsh.y"
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

  case 557:
#line 6042 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 558:
#line 6052 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 559:
#line 6056 "Gmsh.y"
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

  case 560:
#line 6071 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 561:
#line 6076 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 562:
#line 6083 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 563:
#line 6087 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 564:
#line 6092 "Gmsh.y"
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
#line 6106 "Gmsh.y"
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

  case 566:
#line 6122 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 567:
#line 6126 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 568:
#line 6130 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 569:
#line 6134 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 570:
#line 6138 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 571:
#line 6146 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 572:
#line 6152 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 573:
#line 6161 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 574:
#line 6165 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 575:
#line 6169 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 576:
#line 6177 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 577:
#line 6183 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 578:
#line 6189 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 579:
#line 6193 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 580:
#line 6201 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 581:
#line 6209 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 582:
#line 6216 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 583:
#line 6225 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 584:
#line 6229 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 585:
#line 6233 "Gmsh.y"
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

  case 586:
#line 6248 "Gmsh.y"
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

  case 587:
#line 6262 "Gmsh.y"
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

  case 588:
#line 6276 "Gmsh.y"
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

  case 589:
#line 6288 "Gmsh.y"
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

  case 590:
#line 6304 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 591:
#line 6313 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 592:
#line 6322 "Gmsh.y"
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

  case 593:
#line 6332 "Gmsh.y"
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

  case 594:
#line 6343 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 595:
#line 6351 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 596:
#line 6359 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 597:
#line 6363 "Gmsh.y"
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

  case 598:
#line 6382 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 599:
#line 6389 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 600:
#line 6395 "Gmsh.y"
    {
      std::string tmp = GetFileNameWithoutPath(gmsh_yyname);
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 601:
#line 6401 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 602:
#line 6408 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 603:
#line 6415 "Gmsh.y"
    { init_options(); ;}
    break;

  case 604:
#line 6417 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 605:
#line 6425 "Gmsh.y"
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

  case 606:
#line 6449 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 607:
#line 6451 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 608:
#line 6457 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 609:
#line 6462 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 610:
#line 6464 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 611:
#line 6469 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 612:
#line 6474 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 613:
#line 6479 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 614:
#line 6481 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 615:
#line 6485 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 616:
#line 6497 "Gmsh.y"
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

  case 617:
#line 6511 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 618:
#line 6515 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 619:
#line 6522 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 620:
#line 6530 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 621:
#line 6538 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 622:
#line 6549 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 623:
#line 6551 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 624:
#line 6554 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14587 "Gmsh.tab.cpp"
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


#line 6557 "Gmsh.y"


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

