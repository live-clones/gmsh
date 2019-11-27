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
     tSyncModel = 326,
     tNewModel = 327,
     tMass = 328,
     tCenterOfMass = 329,
     tOnelabAction = 330,
     tOnelabRun = 331,
     tCodeName = 332,
     tCpu = 333,
     tMemory = 334,
     tTotalMemory = 335,
     tCreateTopology = 336,
     tCreateGeometry = 337,
     tClassifySurfaces = 338,
     tRenumberMeshNodes = 339,
     tRenumberMeshElements = 340,
     tDistanceFunction = 341,
     tDefineConstant = 342,
     tUndefineConstant = 343,
     tDefineNumber = 344,
     tDefineStruct = 345,
     tNameStruct = 346,
     tDimNameSpace = 347,
     tAppend = 348,
     tDefineString = 349,
     tSetNumber = 350,
     tSetTag = 351,
     tSetString = 352,
     tPoint = 353,
     tCircle = 354,
     tEllipse = 355,
     tCurve = 356,
     tSphere = 357,
     tPolarSphere = 358,
     tSurface = 359,
     tSpline = 360,
     tVolume = 361,
     tBox = 362,
     tCylinder = 363,
     tCone = 364,
     tTorus = 365,
     tEllipsoid = 366,
     tQuadric = 367,
     tShapeFromFile = 368,
     tRectangle = 369,
     tDisk = 370,
     tWire = 371,
     tGeoEntity = 372,
     tCharacteristic = 373,
     tLength = 374,
     tParametric = 375,
     tElliptic = 376,
     tRefineMesh = 377,
     tAdaptMesh = 378,
     tRelocateMesh = 379,
     tReorientMesh = 380,
     tSetFactory = 381,
     tThruSections = 382,
     tWedge = 383,
     tFillet = 384,
     tChamfer = 385,
     tPlane = 386,
     tRuled = 387,
     tTransfinite = 388,
     tPhysical = 389,
     tCompound = 390,
     tPeriodic = 391,
     tParent = 392,
     tUsing = 393,
     tPlugin = 394,
     tDegenerated = 395,
     tRecursive = 396,
     tSewing = 397,
     tRotate = 398,
     tTranslate = 399,
     tSymmetry = 400,
     tDilate = 401,
     tExtrude = 402,
     tLevelset = 403,
     tAffine = 404,
     tBooleanUnion = 405,
     tBooleanIntersection = 406,
     tBooleanDifference = 407,
     tBooleanSection = 408,
     tBooleanFragments = 409,
     tThickSolid = 410,
     tRecombine = 411,
     tSmoother = 412,
     tSplit = 413,
     tDelete = 414,
     tCoherence = 415,
     tIntersect = 416,
     tMeshAlgorithm = 417,
     tReverseMesh = 418,
     tMeshSizeFromBoundary = 419,
     tLayers = 420,
     tScaleLast = 421,
     tHole = 422,
     tAlias = 423,
     tAliasWithOptions = 424,
     tCopyOptions = 425,
     tQuadTriAddVerts = 426,
     tQuadTriNoNewVerts = 427,
     tRecombLaterals = 428,
     tTransfQuadTri = 429,
     tText2D = 430,
     tText3D = 431,
     tInterpolationScheme = 432,
     tTime = 433,
     tCombine = 434,
     tBSpline = 435,
     tBezier = 436,
     tNurbs = 437,
     tNurbsOrder = 438,
     tNurbsKnots = 439,
     tColor = 440,
     tColorTable = 441,
     tFor = 442,
     tIn = 443,
     tEndFor = 444,
     tIf = 445,
     tElseIf = 446,
     tElse = 447,
     tEndIf = 448,
     tExit = 449,
     tAbort = 450,
     tField = 451,
     tReturn = 452,
     tCall = 453,
     tSlide = 454,
     tMacro = 455,
     tShow = 456,
     tHide = 457,
     tGetValue = 458,
     tGetStringValue = 459,
     tGetEnv = 460,
     tGetString = 461,
     tGetNumber = 462,
     tUnique = 463,
     tHomology = 464,
     tCohomology = 465,
     tBetti = 466,
     tExists = 467,
     tFileExists = 468,
     tGetForced = 469,
     tGetForcedStr = 470,
     tGMSH_MAJOR_VERSION = 471,
     tGMSH_MINOR_VERSION = 472,
     tGMSH_PATCH_VERSION = 473,
     tGmshExecutableName = 474,
     tSetPartition = 475,
     tNameToString = 476,
     tStringToName = 477,
     tAFFECTDIVIDE = 478,
     tAFFECTTIMES = 479,
     tAFFECTMINUS = 480,
     tAFFECTPLUS = 481,
     tOR = 482,
     tAND = 483,
     tNOTEQUAL = 484,
     tEQUAL = 485,
     tGREATERGREATER = 486,
     tLESSLESS = 487,
     tGREATEROREQUAL = 488,
     tLESSOREQUAL = 489,
     UNARYPREC = 490,
     tMINUSMINUS = 491,
     tPLUSPLUS = 492
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
#define tSyncModel 326
#define tNewModel 327
#define tMass 328
#define tCenterOfMass 329
#define tOnelabAction 330
#define tOnelabRun 331
#define tCodeName 332
#define tCpu 333
#define tMemory 334
#define tTotalMemory 335
#define tCreateTopology 336
#define tCreateGeometry 337
#define tClassifySurfaces 338
#define tRenumberMeshNodes 339
#define tRenumberMeshElements 340
#define tDistanceFunction 341
#define tDefineConstant 342
#define tUndefineConstant 343
#define tDefineNumber 344
#define tDefineStruct 345
#define tNameStruct 346
#define tDimNameSpace 347
#define tAppend 348
#define tDefineString 349
#define tSetNumber 350
#define tSetTag 351
#define tSetString 352
#define tPoint 353
#define tCircle 354
#define tEllipse 355
#define tCurve 356
#define tSphere 357
#define tPolarSphere 358
#define tSurface 359
#define tSpline 360
#define tVolume 361
#define tBox 362
#define tCylinder 363
#define tCone 364
#define tTorus 365
#define tEllipsoid 366
#define tQuadric 367
#define tShapeFromFile 368
#define tRectangle 369
#define tDisk 370
#define tWire 371
#define tGeoEntity 372
#define tCharacteristic 373
#define tLength 374
#define tParametric 375
#define tElliptic 376
#define tRefineMesh 377
#define tAdaptMesh 378
#define tRelocateMesh 379
#define tReorientMesh 380
#define tSetFactory 381
#define tThruSections 382
#define tWedge 383
#define tFillet 384
#define tChamfer 385
#define tPlane 386
#define tRuled 387
#define tTransfinite 388
#define tPhysical 389
#define tCompound 390
#define tPeriodic 391
#define tParent 392
#define tUsing 393
#define tPlugin 394
#define tDegenerated 395
#define tRecursive 396
#define tSewing 397
#define tRotate 398
#define tTranslate 399
#define tSymmetry 400
#define tDilate 401
#define tExtrude 402
#define tLevelset 403
#define tAffine 404
#define tBooleanUnion 405
#define tBooleanIntersection 406
#define tBooleanDifference 407
#define tBooleanSection 408
#define tBooleanFragments 409
#define tThickSolid 410
#define tRecombine 411
#define tSmoother 412
#define tSplit 413
#define tDelete 414
#define tCoherence 415
#define tIntersect 416
#define tMeshAlgorithm 417
#define tReverseMesh 418
#define tMeshSizeFromBoundary 419
#define tLayers 420
#define tScaleLast 421
#define tHole 422
#define tAlias 423
#define tAliasWithOptions 424
#define tCopyOptions 425
#define tQuadTriAddVerts 426
#define tQuadTriNoNewVerts 427
#define tRecombLaterals 428
#define tTransfQuadTri 429
#define tText2D 430
#define tText3D 431
#define tInterpolationScheme 432
#define tTime 433
#define tCombine 434
#define tBSpline 435
#define tBezier 436
#define tNurbs 437
#define tNurbsOrder 438
#define tNurbsKnots 439
#define tColor 440
#define tColorTable 441
#define tFor 442
#define tIn 443
#define tEndFor 444
#define tIf 445
#define tElseIf 446
#define tElse 447
#define tEndIf 448
#define tExit 449
#define tAbort 450
#define tField 451
#define tReturn 452
#define tCall 453
#define tSlide 454
#define tMacro 455
#define tShow 456
#define tHide 457
#define tGetValue 458
#define tGetStringValue 459
#define tGetEnv 460
#define tGetString 461
#define tGetNumber 462
#define tUnique 463
#define tHomology 464
#define tCohomology 465
#define tBetti 466
#define tExists 467
#define tFileExists 468
#define tGetForced 469
#define tGetForcedStr 470
#define tGMSH_MAJOR_VERSION 471
#define tGMSH_MINOR_VERSION 472
#define tGMSH_PATCH_VERSION 473
#define tGmshExecutableName 474
#define tSetPartition 475
#define tNameToString 476
#define tStringToName 477
#define tAFFECTDIVIDE 478
#define tAFFECTTIMES 479
#define tAFFECTMINUS 480
#define tAFFECTPLUS 481
#define tOR 482
#define tAND 483
#define tNOTEQUAL 484
#define tEQUAL 485
#define tGREATERGREATER 486
#define tLESSLESS 487
#define tGREATEROREQUAL 488
#define tLESSOREQUAL 489
#define UNARYPREC 490
#define tMINUSMINUS 491
#define tPLUSPLUS 492




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
#line 754 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 767 "Gmsh.tab.cpp"

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
#define YYLAST   17696

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  260
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  622
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2241

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   492

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   245,     2,   257,     2,   242,   244,     2,
     250,   251,   240,   238,   259,   239,   256,   241,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     232,     2,   233,   227,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   252,     2,   253,   249,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   254,   243,   255,   258,     2,     2,     2,
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
     225,   226,   228,   229,   230,   231,   234,   235,   236,   237,
     246,   247,   248
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
    3264,  3269,  3270,  3277,  3282,  3285,  3290,  3295,  3297,  3299,
    3303,  3305,  3307,  3311,  3315,  3319,  3325,  3333,  3339,  3345,
    3354,  3356,  3358
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     261,     0,    -1,   262,    -1,     1,     6,    -1,    -1,   262,
     263,    -1,   265,    -1,   266,    -1,   286,    -1,   126,   250,
     363,   251,     6,    -1,   305,    -1,   311,    -1,   315,    -1,
     316,    -1,   317,    -1,   318,    -1,   322,    -1,   331,    -1,
     332,    -1,   338,    -1,   339,    -1,   321,    -1,   320,    -1,
     319,    -1,   314,    -1,   341,    -1,   233,    -1,   234,    -1,
      44,   250,   363,   251,     6,    -1,    46,   250,   363,   251,
       6,    -1,    45,   250,   363,   251,     6,    -1,    44,   250,
     363,   251,   264,   363,     6,    -1,    44,   250,   363,   259,
     359,   251,     6,    -1,    46,   250,   363,   259,   359,   251,
       6,    -1,    45,   250,   363,   259,   359,   251,     6,    -1,
      44,   250,   363,   259,   359,   251,   264,   363,     6,    -1,
     373,   363,   254,   267,   255,     6,    -1,   168,     4,   252,
     342,   253,     6,    -1,   169,     4,   252,   342,   253,     6,
      -1,   170,     4,   252,   342,   259,   342,   253,     6,    -1,
      -1,   267,   270,    -1,   267,   274,    -1,   267,   277,    -1,
     267,   279,    -1,   267,   280,    -1,   342,    -1,   268,   259,
     342,    -1,   342,    -1,   269,   259,   342,    -1,    -1,    -1,
       4,   271,   250,   268,   251,   272,   254,   269,   255,     6,
      -1,   363,    -1,   273,   259,   363,    -1,    -1,   175,   250,
     342,   259,   342,   259,   342,   251,   275,   254,   273,   255,
       6,    -1,   363,    -1,   276,   259,   363,    -1,    -1,   176,
     250,   342,   259,   342,   259,   342,   259,   342,   251,   278,
     254,   276,   255,     6,    -1,   177,   254,   355,   255,   254,
     355,   255,     6,    -1,   177,   254,   355,   255,   254,   355,
     255,   254,   355,   255,   254,   355,   255,     6,    -1,    -1,
     178,   281,   254,   269,   255,     6,    -1,     7,    -1,   226,
      -1,   225,    -1,   224,    -1,   223,    -1,   248,    -1,   247,
      -1,   250,    -1,   252,    -1,   251,    -1,   253,    -1,    87,
     252,   288,   253,     6,    -1,    88,   252,   292,   253,     6,
      -1,   347,     6,    -1,    95,   284,   364,   259,   342,   285,
       6,    -1,    97,   284,   373,   259,   364,   285,     6,    -1,
     373,   282,   356,     6,    -1,   373,   283,     6,    -1,   373,
     284,   285,   282,   356,     6,    -1,   373,   284,   254,   359,
     255,   285,   282,   356,     6,    -1,   373,   252,   342,   253,
     282,   342,     6,    -1,   373,   252,   342,   253,   283,     6,
      -1,   373,   250,   342,   251,   282,   342,     6,    -1,   373,
     250,   342,   251,   283,     6,    -1,   373,     7,   364,     6,
      -1,   373,   284,   285,     7,    47,   284,   285,     6,    -1,
     373,   284,   285,     7,    47,   284,   368,   285,     6,    -1,
     373,   284,   285,   226,    47,   284,   368,   285,     6,    -1,
     373,   256,     4,     7,   364,     6,    -1,   373,   252,   342,
     253,   256,     4,     7,   364,     6,    -1,   373,   256,     4,
     282,   342,     6,    -1,   373,   252,   342,   253,   256,     4,
     282,   342,     6,    -1,   373,   256,     4,   283,     6,    -1,
     373,   252,   342,   253,   256,     4,   283,     6,    -1,   373,
     256,   185,   256,     4,     7,   360,     6,    -1,   373,   252,
     342,   253,   256,   185,   256,     4,     7,   360,     6,    -1,
     373,   256,   186,     7,   361,     6,    -1,   373,   252,   342,
     253,   256,   186,     7,   361,     6,    -1,   373,   196,     7,
     356,     6,    -1,   196,   252,   342,   253,     7,     4,     6,
      -1,   196,   252,   342,   253,     7,   107,     6,    -1,   196,
     252,   342,   253,     7,   108,     6,    -1,   196,   252,   342,
     253,   256,     4,     7,   342,     6,    -1,   196,   252,   342,
     253,   256,     4,     7,   364,     6,    -1,   196,   252,   342,
     253,   256,     4,     7,   254,   359,   255,     6,    -1,   196,
     252,   342,   253,   256,     4,     6,    -1,   139,   250,     4,
     251,   256,     4,     7,   342,     6,    -1,   139,   250,     4,
     251,   256,     4,     7,   364,     6,    -1,    -1,   259,    -1,
      -1,   288,   287,   373,    -1,   288,   287,   373,     7,   342,
      -1,    -1,   288,   287,   373,     7,   254,   356,   289,   294,
     255,    -1,    -1,   288,   287,   373,   284,   285,     7,   254,
     356,   290,   294,   255,    -1,   288,   287,   373,     7,   364,
      -1,    -1,   288,   287,   373,     7,   254,   364,   291,   298,
     255,    -1,    -1,   292,   287,   363,    -1,   342,     7,   364,
      -1,   293,   259,   342,     7,   364,    -1,   358,     7,   373,
     250,   251,    -1,    -1,   259,   296,    -1,    -1,   296,    -1,
     297,    -1,   296,   259,   297,    -1,     4,   356,    -1,     4,
      -1,     4,   254,   293,   255,    -1,     4,   364,    -1,     4,
     367,    -1,    -1,   259,   299,    -1,   300,    -1,   299,   259,
     300,    -1,     4,   342,    -1,     4,   364,    -1,   200,   364,
      -1,     4,   369,    -1,     4,   367,    -1,   342,    -1,   364,
      -1,   364,   259,   342,    -1,    -1,   188,   102,   254,   342,
     255,    -1,   138,    98,   254,   359,   255,    -1,   138,   117,
     254,   359,   255,    -1,    -1,   131,   353,    -1,    -1,   138,
     142,    -1,    98,   250,   342,   251,     7,   353,     6,    -1,
     101,   250,   342,   251,     7,   356,     6,    -1,   105,   250,
     342,   251,     7,   356,     6,    -1,   135,   105,   250,   342,
     251,     7,   356,   138,   342,     6,    -1,   135,   180,   250,
     342,   251,     7,   356,   138,   342,     6,    -1,    99,   250,
     342,   251,     7,   356,   303,     6,    -1,   100,   250,   342,
     251,     7,   356,   303,     6,    -1,   180,   250,   342,   251,
       7,   356,     6,    -1,   181,   250,   342,   251,     7,   356,
       6,    -1,   182,   250,   342,   251,     7,   356,   184,   356,
     183,   342,     6,    -1,   116,   250,   342,   251,     7,   356,
       6,    -1,   101,     4,   250,   342,   251,     7,   356,     6,
      -1,   131,   104,   250,   342,   251,     7,   356,     6,    -1,
     104,   250,   342,   251,     7,   356,   302,     6,    -1,   132,
     104,   250,   342,   251,     7,   356,   302,     6,    -1,    13,
      14,     6,    -1,    14,   104,   342,     6,    -1,   120,   104,
     250,   342,   251,     7,     5,     5,     5,     6,    -1,   102,
     250,   342,   251,     7,   356,     6,    -1,   103,   250,   342,
     251,     7,   356,     6,    -1,   107,   250,   342,   251,     7,
     356,     6,    -1,   110,   250,   342,   251,     7,   356,     6,
      -1,   114,   250,   342,   251,     7,   356,     6,    -1,   115,
     250,   342,   251,     7,   356,     6,    -1,   108,   250,   342,
     251,     7,   356,     6,    -1,   109,   250,   342,   251,     7,
     356,     6,    -1,   128,   250,   342,   251,     7,   356,     6,
      -1,   155,   250,   342,   251,     7,   356,     6,    -1,   104,
       4,   250,   342,   251,     7,   356,   304,     6,    -1,   106,
     250,   342,   251,     7,   356,     6,    -1,   127,   250,   342,
     251,     7,   356,     6,    -1,   132,   127,   250,   342,   251,
       7,   356,     6,    -1,   135,   308,   250,   342,   251,     7,
     356,     6,    -1,   135,   308,   250,   342,   251,     7,   356,
       4,   254,   355,   255,     6,    -1,    -1,   134,   307,   306,
     250,   301,   251,   282,   356,     6,    -1,    98,    -1,   101,
      -1,   104,    -1,   106,    -1,   117,   254,   342,   255,    -1,
     101,    -1,   104,    -1,   106,    -1,   117,   254,   342,   255,
      -1,   101,    -1,   104,    -1,   117,   254,   342,   255,    -1,
      98,    -1,   101,    -1,   104,    -1,   117,   254,   342,   255,
      -1,   144,   353,   254,   312,   255,    -1,   143,   254,   353,
     259,   353,   259,   342,   255,   254,   312,   255,    -1,   145,
     353,   254,   312,   255,    -1,   146,   254,   353,   259,   342,
     255,   254,   312,   255,    -1,   146,   254,   353,   259,   353,
     255,   254,   312,   255,    -1,   149,   254,   359,   255,   254,
     312,   255,    -1,     4,   254,   312,   255,    -1,   161,   101,
     254,   359,   255,   104,   254,   342,   255,    -1,   158,   101,
     250,   342,   251,   254,   359,   255,     6,    -1,   313,    -1,
     311,    -1,    -1,   313,   305,    -1,   313,   307,   254,   359,
     255,     6,    -1,   313,   134,   307,   254,   359,   255,     6,
      -1,   313,   137,   307,   254,   359,   255,     6,    -1,   313,
     307,   254,     8,   255,     6,    -1,   313,   134,   307,   254,
       8,   255,     6,    -1,   148,   131,   250,   342,   251,     7,
     356,     6,    -1,   148,    98,   250,   342,   251,     7,   254,
     355,   255,     6,    -1,   148,   131,   250,   342,   251,     7,
     254,   353,   259,   353,   259,   359,   255,     6,    -1,   148,
     131,   250,   342,   251,     7,   254,   353,   259,   353,   259,
     353,   259,   359,   255,     6,    -1,   148,   102,   250,   342,
     251,     7,   254,   353,   259,   359,   255,     6,    -1,   148,
     108,   250,   342,   251,     7,   254,   353,   259,   353,   259,
     359,   255,     6,    -1,   148,   109,   250,   342,   251,     7,
     254,   353,   259,   353,   259,   359,   255,     6,    -1,   148,
     111,   250,   342,   251,     7,   254,   353,   259,   353,   259,
     359,   255,     6,    -1,   148,   112,   250,   342,   251,     7,
     254,   353,   259,   353,   259,   359,   255,     6,    -1,   148,
       4,   250,   342,   251,     7,   356,     6,    -1,   148,     4,
     250,   342,   251,     7,     5,     6,    -1,   148,     4,   254,
     342,   255,     6,    -1,   159,   254,   313,   255,    -1,   141,
     159,   254,   313,   255,    -1,   159,     4,   254,   313,   255,
      -1,   159,   196,   252,   342,   253,     6,    -1,   159,     4,
     252,   342,   253,     6,    -1,   159,   373,     6,    -1,   159,
       4,     4,     6,    -1,   159,    90,     6,    -1,   185,   360,
     254,   313,   255,    -1,   141,   185,   360,   254,   313,   255,
      -1,   220,   342,   254,   313,   255,    -1,   201,   254,     8,
     255,    -1,   201,     5,     6,    -1,   202,   254,     8,   255,
      -1,   202,     5,     6,    -1,   201,   254,   313,   255,    -1,
     141,   201,   254,   313,   255,    -1,   202,   254,   313,   255,
      -1,   141,   202,   254,   313,   255,    -1,   373,   364,     6,
      -1,    76,   250,   370,   251,     6,    -1,   373,   373,   252,
     342,   253,   363,     6,    -1,   373,   373,   373,   252,   342,
     253,     6,    -1,   373,   342,     6,    -1,   139,   250,     4,
     251,   256,     4,     6,    -1,   179,     4,     6,    -1,   194,
       6,    -1,   195,     6,    -1,    71,     6,    -1,    72,     6,
      -1,    65,     6,    -1,    65,   254,   342,   259,   342,   259,
     342,   259,   342,   259,   342,   259,   342,   255,     6,    -1,
      66,     6,    -1,    67,     6,    -1,    81,     6,    -1,    83,
     254,   342,   259,   342,   259,   342,   255,     6,    -1,    83,
     254,   342,   259,   342,   259,   342,   259,   342,   255,     6,
      -1,    82,     6,    -1,    84,     6,    -1,    85,     6,    -1,
     122,     6,    -1,   123,   254,   359,   255,   254,   359,   255,
     254,   355,   255,   254,   342,   259,   342,   255,     6,    -1,
     199,   250,   254,   359,   255,   259,   364,   259,   364,   251,
       6,    -1,   187,   250,   342,     8,   342,   251,    -1,   187,
     250,   342,     8,   342,     8,   342,   251,    -1,   187,     4,
     188,   254,   342,     8,   342,   255,    -1,   187,     4,   188,
     254,   342,     8,   342,     8,   342,   255,    -1,   189,    -1,
     200,     4,    -1,   200,   364,    -1,   197,    -1,   198,   373,
       6,    -1,   198,   364,     6,    -1,   190,   250,   342,   251,
      -1,   191,   250,   342,   251,    -1,   192,    -1,   193,    -1,
     147,   353,   254,   313,   255,    -1,   147,   254,   353,   259,
     353,   259,   342,   255,   254,   313,   255,    -1,   147,   254,
     353,   259,   353,   259,   353,   259,   342,   255,   254,   313,
     255,    -1,    -1,   147,   353,   254,   313,   323,   327,   255,
      -1,    -1,   147,   254,   353,   259,   353,   259,   342,   255,
     254,   313,   324,   327,   255,    -1,    -1,   147,   254,   353,
     259,   353,   259,   353,   259,   342,   255,   254,   313,   325,
     327,   255,    -1,    -1,   147,   254,   313,   326,   327,   255,
      -1,   147,   254,   313,   255,   138,   116,   254,   342,   255,
      -1,   127,   356,    -1,   132,   127,   356,    -1,   129,   254,
     359,   255,   254,   359,   255,   254,   359,   255,    -1,   130,
     254,   359,   255,   254,   359,   255,   254,   359,   255,   254,
     359,   255,    -1,   328,    -1,   327,   328,    -1,   165,   254,
     342,   255,     6,    -1,   165,   254,   356,   259,   356,   255,
       6,    -1,   166,     6,    -1,   156,     6,    -1,   156,   342,
       6,    -1,   171,     6,    -1,   171,   173,     6,    -1,   172,
       6,    -1,   172,   173,     6,    -1,   167,   250,   342,   251,
       7,   356,   138,   342,     6,    -1,   138,     4,   252,   342,
     253,     6,    -1,   150,    -1,   151,    -1,   152,    -1,   153,
      -1,   154,    -1,    -1,   159,     6,    -1,   141,   159,     6,
      -1,   159,   342,     6,    -1,   141,   159,   342,     6,    -1,
     329,   254,   313,   330,   255,   254,   313,   330,   255,    -1,
     113,   250,   363,   251,    -1,   329,   250,   342,   251,     7,
     254,   313,   330,   255,   254,   313,   330,   255,     6,    -1,
      -1,   138,     4,   342,    -1,    -1,     4,    -1,    -1,     7,
     356,    -1,    -1,     7,   342,    -1,    -1,   149,   356,    -1,
     118,   119,   357,     7,   342,     6,    -1,   133,   101,   357,
       7,   342,   333,     6,    -1,   133,   104,   357,   335,   334,
       6,    -1,   133,   106,   357,   335,     6,    -1,   174,   357,
       6,    -1,    96,    98,   250,   342,   259,   342,   251,     6,
      -1,    96,   101,   250,   342,   259,   342,   251,     6,    -1,
      96,   104,   250,   342,   259,   342,   251,     6,    -1,    96,
     106,   250,   342,   259,   342,   251,     6,    -1,   162,   104,
     254,   359,   255,     7,   342,     6,    -1,   164,   104,   254,
     359,   255,     7,   342,     6,    -1,   156,   104,   357,   336,
       6,    -1,   156,   106,   357,     6,    -1,   157,   104,   357,
       7,   342,     6,    -1,   136,   101,   254,   359,   255,     7,
     254,   359,   255,   337,     6,    -1,   136,   104,   254,   359,
     255,     7,   254,   359,   255,   337,     6,    -1,   136,   101,
     254,   359,   255,     7,   254,   359,   255,   143,   254,   353,
     259,   353,   259,   342,   255,     6,    -1,   136,   104,   254,
     359,   255,     7,   254,   359,   255,   143,   254,   353,   259,
     353,   259,   342,   255,     6,    -1,   136,   101,   254,   359,
     255,     7,   254,   359,   255,   144,   353,     6,    -1,   136,
     104,   254,   359,   255,     7,   254,   359,   255,   144,   353,
       6,    -1,   136,   104,   342,   254,   359,   255,     7,   342,
     254,   359,   255,     6,    -1,   307,   254,   359,   255,   188,
     307,   254,   342,   255,     6,    -1,   163,   309,   357,     6,
      -1,   124,   310,   357,     6,    -1,   125,   106,   356,     6,
      -1,   140,   101,   356,     6,    -1,   135,   308,   356,     6,
      -1,   160,     6,    -1,   160,     4,     6,    -1,   160,    98,
     254,   359,   255,     6,    -1,   209,    -1,   210,    -1,   211,
      -1,   340,     6,    -1,   340,   254,   356,   255,     6,    -1,
     340,   254,   356,   259,   356,   255,     6,    -1,   340,   250,
     356,   251,   254,   356,   259,   356,   255,     6,    -1,   343,
      -1,   250,   342,   251,    -1,   239,   342,    -1,   238,   342,
      -1,   245,   342,    -1,   342,   239,   342,    -1,   342,   238,
     342,    -1,   342,   240,   342,    -1,   342,   241,   342,    -1,
     342,   243,   342,    -1,   342,   244,   342,    -1,   342,   242,
     342,    -1,   342,   249,   342,    -1,   342,   232,   342,    -1,
     342,   233,   342,    -1,   342,   237,   342,    -1,   342,   236,
     342,    -1,   342,   231,   342,    -1,   342,   230,   342,    -1,
     342,   229,   342,    -1,   342,   228,   342,    -1,   342,   234,
     342,    -1,   342,   235,   342,    -1,   342,   227,   342,     8,
     342,    -1,    16,   284,   342,   285,    -1,    17,   284,   342,
     285,    -1,    18,   284,   342,   285,    -1,    19,   284,   342,
     285,    -1,    20,   284,   342,   285,    -1,    21,   284,   342,
     285,    -1,    22,   284,   342,   285,    -1,    23,   284,   342,
     285,    -1,    24,   284,   342,   285,    -1,    26,   284,   342,
     285,    -1,    27,   284,   342,   259,   342,   285,    -1,    28,
     284,   342,   285,    -1,    29,   284,   342,   285,    -1,    30,
     284,   342,   285,    -1,    31,   284,   342,   285,    -1,    32,
     284,   342,   285,    -1,    33,   284,   342,   285,    -1,    34,
     284,   342,   285,    -1,    35,   284,   342,   285,    -1,    36,
     284,   342,   259,   342,   285,    -1,    37,   284,   342,   259,
     342,   285,    -1,    38,   284,   342,   259,   342,   285,    -1,
      25,   284,   342,   285,    -1,     3,    -1,    10,    -1,    15,
      -1,    11,    -1,    12,    -1,   216,    -1,   217,    -1,   218,
      -1,    78,    -1,    79,    -1,    80,    -1,    -1,    89,   284,
     342,   344,   294,   285,    -1,   347,    -1,   207,   284,   363,
     285,    -1,   207,   284,   363,   259,   342,   285,    -1,   349,
      -1,   373,   252,   342,   253,    -1,   373,   250,   342,   251,
      -1,   212,   250,   349,   251,    -1,   212,   250,   349,   256,
     350,   251,    -1,   214,   250,   349,   345,   251,    -1,   214,
     250,   349,   256,   350,   345,   251,    -1,   214,   250,   349,
     284,   342,   285,   345,   251,    -1,   214,   250,   349,   256,
     350,   284,   342,   285,   345,   251,    -1,   213,   250,   364,
     251,    -1,   257,   373,   284,   285,    -1,   257,   349,   256,
     350,   284,   285,    -1,    92,   284,   373,   285,    -1,    92,
     284,   285,    -1,   373,   283,    -1,   373,   252,   342,   253,
     283,    -1,   373,   250,   342,   251,   283,    -1,   373,   256,
     350,    -1,   373,     9,   373,   256,   350,    -1,   373,   256,
     350,   250,   342,   251,    -1,   373,     9,   373,   256,   350,
     250,   342,   251,    -1,   373,   256,   350,   252,   342,   253,
      -1,   373,     9,   373,   256,   350,   252,   342,   253,    -1,
     373,   252,   342,   253,   256,     4,    -1,   373,   256,     4,
     283,    -1,   373,   252,   342,   253,   256,     4,   283,    -1,
     203,   250,   363,   259,   342,   251,    -1,    57,   250,   356,
     259,   356,   251,    -1,    58,   284,   363,   259,   363,   285,
      -1,    56,   284,   363,   285,    -1,    59,   284,   363,   259,
     363,   285,    -1,    64,   250,   370,   251,    -1,    -1,   259,
     342,    -1,    -1,   259,   363,    -1,    -1,    90,   349,   352,
     348,   252,   295,   253,    -1,   373,    -1,   373,     9,   373,
      -1,     4,    -1,    93,    -1,    93,   342,    -1,    -1,   250,
     351,   251,    -1,   354,    -1,   239,   353,    -1,   238,   353,
      -1,   353,   239,   353,    -1,   353,   238,   353,    -1,   254,
     342,   259,   342,   259,   342,   259,   342,   259,   342,   255,
      -1,   254,   342,   259,   342,   259,   342,   259,   342,   255,
      -1,   254,   342,   259,   342,   259,   342,   255,    -1,   250,
     342,   259,   342,   259,   342,   251,    -1,   356,    -1,   355,
     259,   356,    -1,   342,    -1,   358,    -1,   254,   255,    -1,
     254,   359,   255,    -1,   239,   254,   359,   255,    -1,   342,
     240,   254,   359,   255,    -1,   356,    -1,   254,     8,   255,
      -1,     5,    -1,   239,   358,    -1,   342,   240,   358,    -1,
     342,     8,   342,    -1,   342,     8,   342,     8,   342,    -1,
      98,   254,   342,   255,    -1,    98,   254,     8,   255,    -1,
      98,     5,    -1,   308,   254,     8,   255,    -1,   308,     5,
      -1,   134,   307,   357,    -1,   137,   307,   356,    -1,   307,
     188,    65,   254,   342,   259,   342,   259,   342,   259,   342,
     259,   342,   259,   342,   255,    -1,    65,   307,   254,   359,
     255,    -1,    73,   308,   254,   342,   255,    -1,    74,   308,
     254,   342,   255,    -1,   311,    -1,   322,    -1,   331,    -1,
     373,   284,   285,    -1,   373,   256,   350,   284,   285,    -1,
     373,     9,   373,   256,   350,   284,   285,    -1,    39,   252,
     373,   253,    -1,    39,   252,   358,   253,    -1,    39,   250,
     358,   251,    -1,    39,   284,   254,   359,   255,   285,    -1,
     373,   284,   254,   359,   255,   285,    -1,    40,   284,   342,
     259,   342,   259,   342,   285,    -1,    41,   284,   342,   259,
     342,   259,   342,   285,    -1,    42,   284,   363,   285,    -1,
      43,   284,   342,   259,   342,   259,   342,   259,   342,   259,
     342,   259,   342,   285,    -1,   208,   284,   358,   285,    -1,
      32,   284,   358,   285,    -1,   342,    -1,   358,    -1,   359,
     259,   342,    -1,   359,   259,   358,    -1,   254,   342,   259,
     342,   259,   342,   259,   342,   255,    -1,   254,   342,   259,
     342,   259,   342,   255,    -1,   373,    -1,     4,   256,   185,
     256,     4,    -1,   254,   362,   255,    -1,   373,   252,   342,
     253,   256,   186,    -1,   360,    -1,   362,   259,   360,    -1,
     364,    -1,   373,    -1,   373,   252,   342,   253,    -1,   373,
     250,   342,   251,    -1,   373,   256,   350,    -1,   373,     9,
     373,   256,   350,    -1,   373,   256,   350,   250,   342,   251,
      -1,   373,     9,   373,   256,   350,   250,   342,   251,    -1,
     373,   252,   342,   253,   256,     4,    -1,   307,   254,   342,
     255,    -1,   134,   307,   254,   342,   255,    -1,     5,    -1,
     221,   252,   373,   253,    -1,    68,    -1,   219,    -1,    75,
      -1,    77,    -1,   205,   250,   363,   251,    -1,   204,   250,
     363,   259,   363,   251,    -1,   206,   284,   363,   285,    -1,
     206,   284,   363,   259,   363,   285,    -1,   215,   250,   349,
     346,   251,    -1,   215,   250,   349,   256,   350,   346,   251,
      -1,    49,   284,   370,   285,    -1,    50,   250,   363,   251,
      -1,    51,   250,   363,   251,    -1,    52,   250,   363,   259,
     363,   259,   363,   251,    -1,    47,   284,   370,   285,    -1,
      61,   284,   363,   285,    -1,    62,   284,   363,   285,    -1,
      63,   284,   363,   285,    -1,    60,   284,   342,   259,   363,
     259,   363,   285,    -1,    55,   284,   363,   259,   342,   259,
     342,   285,    -1,    55,   284,   363,   259,   342,   285,    -1,
      48,   284,   363,   285,    -1,    48,   284,   363,   259,   359,
     285,    -1,    69,   284,   363,   285,    -1,    70,    -1,    54,
     284,   363,   285,    -1,    53,   284,   363,   285,    -1,    -1,
      94,   284,   364,   365,   298,   285,    -1,    91,   284,   366,
     285,    -1,   257,   342,    -1,   373,     9,   257,   342,    -1,
      47,   284,   369,   285,    -1,   370,    -1,   369,    -1,   254,
     370,   255,    -1,   363,    -1,   371,    -1,   370,   259,   363,
      -1,   370,   259,   371,    -1,   373,   250,   251,    -1,   373,
     256,   350,   250,   251,    -1,   373,     9,   373,   256,   350,
     250,   251,    -1,     4,   258,   254,   342,   255,    -1,   372,
     258,   254,   342,   255,    -1,   222,   252,   363,   253,   258,
     254,   342,   255,    -1,     4,    -1,   372,    -1,   222,   252,
     363,   253,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   270,   270,   271,   276,   278,   282,   283,   284,   285,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   323,   327,   334,   339,
     344,   349,   363,   376,   389,   402,   430,   444,   457,   470,
     489,   494,   495,   496,   497,   498,   502,   504,   509,   511,
     517,   621,   516,   639,   646,   657,   656,   674,   681,   692,
     691,   708,   725,   748,   747,   761,   762,   763,   764,   765,
     769,   770,   776,   776,   777,   777,   783,   784,   785,   786,
     791,   797,   859,   874,   903,   913,   918,   926,   931,   939,
     948,   953,   965,   982,   988,   997,  1015,  1033,  1042,  1054,
    1059,  1067,  1087,  1110,  1130,  1138,  1145,  1152,  1174,  1197,
    1235,  1256,  1268,  1282,  1282,  1284,  1286,  1295,  1305,  1304,
    1325,  1324,  1342,  1352,  1351,  1365,  1367,  1375,  1381,  1386,
    1413,  1415,  1418,  1420,  1424,  1425,  1429,  1441,  1454,  1469,
    1478,  1491,  1493,  1497,  1498,  1503,  1511,  1520,  1528,  1542,
    1560,  1564,  1571,  1580,  1583,  1589,  1593,  1605,  1608,  1615,
    1618,  1624,  1647,  1663,  1679,  1696,  1713,  1750,  1794,  1810,
    1826,  1858,  1874,  1891,  1907,  1957,  1975,  1981,  1987,  1994,
    2025,  2040,  2062,  2085,  2108,  2131,  2155,  2179,  2203,  2229,
    2246,  2262,  2280,  2298,  2310,  2324,  2323,  2353,  2355,  2357,
    2359,  2361,  2369,  2371,  2373,  2375,  2383,  2385,  2387,  2395,
    2397,  2399,  2401,  2411,  2427,  2443,  2459,  2475,  2491,  2508,
    2545,  2567,  2591,  2592,  2597,  2600,  2604,  2621,  2641,  2661,
    2680,  2707,  2726,  2747,  2762,  2778,  2796,  2847,  2868,  2890,
    2913,  3018,  3034,  3069,  3091,  3113,  3125,  3131,  3146,  3174,
    3186,  3195,  3202,  3214,  3234,  3238,  3243,  3247,  3252,  3259,
    3266,  3273,  3285,  3358,  3376,  3401,  3416,  3449,  3461,  3493,
    3497,  3502,  3509,  3514,  3524,  3529,  3535,  3543,  3547,  3551,
    3555,  3559,  3563,  3567,  3576,  3640,  3656,  3673,  3690,  3712,
    3734,  3769,  3777,  3785,  3791,  3798,  3805,  3825,  3851,  3863,
    3874,  3892,  3910,  3929,  3928,  3953,  3952,  3979,  3978,  4003,
    4002,  4025,  4041,  4058,  4075,  4098,  4126,  4129,  4135,  4147,
    4167,  4171,  4175,  4179,  4183,  4187,  4191,  4195,  4204,  4217,
    4218,  4219,  4220,  4221,  4225,  4226,  4227,  4228,  4229,  4232,
    4256,  4275,  4298,  4301,  4317,  4320,  4337,  4340,  4346,  4349,
    4356,  4359,  4366,  4388,  4429,  4473,  4512,  4537,  4549,  4561,
    4573,  4585,  4602,  4619,  4649,  4675,  4701,  4733,  4760,  4786,
    4812,  4838,  4864,  4886,  4897,  4945,  4999,  5014,  5026,  5037,
    5044,  5059,  5073,  5074,  5075,  5079,  5085,  5097,  5115,  5143,
    5144,  5145,  5146,  5147,  5148,  5149,  5150,  5151,  5158,  5159,
    5160,  5161,  5162,  5163,  5164,  5165,  5166,  5167,  5168,  5169,
    5170,  5171,  5172,  5173,  5174,  5175,  5176,  5177,  5178,  5179,
    5180,  5181,  5182,  5183,  5184,  5185,  5186,  5187,  5188,  5189,
    5190,  5191,  5192,  5193,  5194,  5195,  5204,  5205,  5206,  5207,
    5208,  5209,  5210,  5211,  5212,  5213,  5214,  5219,  5218,  5226,
    5228,  5233,  5238,  5242,  5247,  5252,  5256,  5260,  5264,  5268,
    5272,  5276,  5282,  5297,  5301,  5307,  5312,  5331,  5351,  5382,
    5386,  5390,  5394,  5398,  5402,  5406,  5411,  5421,  5431,  5436,
    5447,  5456,  5461,  5466,  5494,  5495,  5501,  5502,  5508,  5507,
    5530,  5532,  5537,  5546,  5548,  5554,  5555,  5560,  5564,  5568,
    5572,  5576,  5583,  5587,  5591,  5595,  5602,  5607,  5614,  5619,
    5623,  5628,  5632,  5640,  5651,  5655,  5659,  5673,  5681,  5689,
    5696,  5706,  5729,  5734,  5740,  5745,  5751,  5762,  5768,  5774,
    5780,  5792,  5806,  5816,  5826,  5836,  5848,  5852,  5857,  5869,
    5873,  5877,  5881,  5899,  5907,  5915,  5944,  5954,  5970,  5981,
    5986,  5990,  5994,  6006,  6010,  6022,  6039,  6049,  6053,  6068,
    6073,  6080,  6084,  6089,  6103,  6119,  6123,  6127,  6131,  6135,
    6143,  6149,  6158,  6162,  6166,  6174,  6180,  6186,  6190,  6198,
    6206,  6213,  6222,  6226,  6230,  6245,  6259,  6273,  6285,  6301,
    6310,  6319,  6329,  6340,  6348,  6356,  6360,  6379,  6386,  6392,
    6399,  6407,  6406,  6416,  6440,  6442,  6448,  6453,  6455,  6460,
    6465,  6470,  6472,  6476,  6488,  6502,  6506,  6513,  6521,  6529,
    6540,  6542,  6545
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
  "tSyncModel", "tNewModel", "tMass", "tCenterOfMass", "tOnelabAction",
  "tOnelabRun", "tCodeName", "tCpu", "tMemory", "tTotalMemory",
  "tCreateTopology", "tCreateGeometry", "tClassifySurfaces",
  "tRenumberMeshNodes", "tRenumberMeshElements", "tDistanceFunction",
  "tDefineConstant", "tUndefineConstant", "tDefineNumber", "tDefineStruct",
  "tNameStruct", "tDimNameSpace", "tAppend", "tDefineString", "tSetNumber",
  "tSetTag", "tSetString", "tPoint", "tCircle", "tEllipse", "tCurve",
  "tSphere", "tPolarSphere", "tSurface", "tSpline", "tVolume", "tBox",
  "tCylinder", "tCone", "tTorus", "tEllipsoid", "tQuadric",
  "tShapeFromFile", "tRectangle", "tDisk", "tWire", "tGeoEntity",
  "tCharacteristic", "tLength", "tParametric", "tElliptic", "tRefineMesh",
  "tAdaptMesh", "tRelocateMesh", "tReorientMesh", "tSetFactory",
  "tThruSections", "tWedge", "tFillet", "tChamfer", "tPlane", "tRuled",
  "tTransfinite", "tPhysical", "tCompound", "tPeriodic", "tParent",
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tSewing", "tRotate",
  "tTranslate", "tSymmetry", "tDilate", "tExtrude", "tLevelset", "tAffine",
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
  "NumericIncrement", "LP", "RP", "Affectation", "Comma",
  "DefineConstants", "@6", "@7", "@8", "UndefineConstants", "Enumeration",
  "FloatParameterOptionsOrNone", "FloatParameterOptionsOrNone_NoComma",
  "FloatParameterOptions", "FloatParameterOption",
  "CharParameterOptionsOrNone", "CharParameterOptions",
  "CharParameterOption", "PhysicalId_per_dim_entity", "SurfaceConstraints",
  "CircleOptions", "LoopOptions", "Shape", "@9", "GeoEntity",
  "GeoEntity123", "GeoEntity12", "GeoEntity02", "Transform",
  "MultipleShape", "ListOfShapes", "LevelSet", "Delete", "Colorify",
  "SetPartition", "Visibility", "Command", "Slide", "Loop", "Extrude",
  "@10", "@11", "@12", "@13", "ExtrudeParameters", "ExtrudeParameter",
  "BooleanOperator", "BooleanOption", "Boolean", "BooleanShape",
  "TransfiniteType", "TransfiniteArrangement", "TransfiniteCorners",
  "RecombineAngle", "PeriodicTransform", "Constraints", "Coherence",
  "HomologyCommand", "Homology", "FExpr", "FExpr_Single", "@14",
  "GetForced_Default", "GetForcedStr_Default", "DefineStruct", "@15",
  "Struct_FullName", "tSTRING_Member", "Append", "AppendOrNot", "VExpr",
  "VExpr_Single", "RecursiveListOfListOfDouble", "ListOfDouble",
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
     475,   476,   477,   478,   479,   480,   481,    63,   482,   483,
     484,   485,    60,    62,   486,   487,   488,   489,    43,    45,
      42,    47,    37,   124,    38,    33,   490,   491,   492,    94,
      40,    41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   260,   261,   261,   262,   262,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   264,   264,   265,   265,
     265,   265,   265,   265,   265,   265,   266,   266,   266,   266,
     267,   267,   267,   267,   267,   267,   268,   268,   269,   269,
     271,   272,   270,   273,   273,   275,   274,   276,   276,   278,
     277,   279,   279,   281,   280,   282,   282,   282,   282,   282,
     283,   283,   284,   284,   285,   285,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   288,   288,   288,   289,   288,
     290,   288,   288,   291,   288,   292,   292,   293,   293,   293,
     294,   294,   295,   295,   296,   296,   297,   297,   297,   297,
     297,   298,   298,   299,   299,   300,   300,   300,   300,   300,
     301,   301,   301,   302,   302,   302,   302,   303,   303,   304,
     304,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   306,   305,   307,   307,   307,
     307,   307,   308,   308,   308,   308,   309,   309,   309,   310,
     310,   310,   310,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   312,   312,   313,   313,   313,   313,   313,   313,
     313,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   315,   315,   315,   315,   315,   315,   315,
     315,   316,   316,   317,   318,   318,   318,   318,   318,   318,
     318,   318,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   320,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   322,   322,   323,   322,   324,   322,   325,   322,   326,
     322,   322,   322,   322,   322,   322,   327,   327,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   329,
     329,   329,   329,   329,   330,   330,   330,   330,   330,   331,
     331,   332,   333,   333,   334,   334,   335,   335,   336,   336,
     337,   337,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   339,
     339,   339,   340,   340,   340,   341,   341,   341,   341,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   344,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   345,   345,   346,   346,   348,   347,
     349,   349,   350,   351,   351,   352,   352,   353,   353,   353,
     353,   353,   354,   354,   354,   354,   355,   355,   356,   356,
     356,   356,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   359,
     359,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   365,   364,   364,   366,   366,   367,   368,   368,   369,
     370,   370,   370,   370,   371,   371,   371,   372,   372,   372,
     373,   373,   373
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
       4,     4,     8,     8,     6,     4,     6,     4,     1,     4,
       4,     0,     6,     4,     2,     4,     4,     1,     1,     3,
       1,     1,     3,     3,     3,     5,     7,     5,     5,     8,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   620,     0,     0,     0,
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
      25,     0,   621,     0,   224,     0,     0,     0,     0,     0,
       0,   273,     0,   275,   276,   271,   272,     0,   277,   280,
       0,   281,   282,   115,   125,   620,   495,   490,    72,    73,
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
       0,     0,     0,     0,   620,     0,     0,   224,     0,     0,
     379,     0,     0,     0,   206,   207,     0,     0,     0,     0,
       0,     0,   516,     0,     0,   514,     0,     0,     0,     0,
       0,   620,     0,     0,   555,     0,     0,     0,     0,   269,
     270,     0,   572,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,     0,   598,   576,
     577,     0,     0,     0,     0,     0,     0,   575,     0,     0,
       0,     0,   291,   292,     0,   224,     0,   224,     0,     0,
       0,   490,     0,     0,     0,   224,   385,     0,     0,    78,
       0,    65,     0,     0,    69,    68,    67,    66,    71,    70,
      72,    73,     0,     0,     0,     0,     0,     0,     0,   561,
     490,     0,   223,     0,   222,     0,   176,     0,     0,   561,
     562,     0,     0,     0,   610,     0,   611,   562,     0,   113,
     113,     0,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   549,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     523,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   392,     0,   391,   517,   393,     0,   510,     0,
       0,   490,     0,   525,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,     0,   466,
       0,     0,     0,     0,     0,     0,     0,   313,     0,   346,
     346,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,   224,   224,     0,   499,   498,     0,
       0,     0,     0,   224,   224,     0,     0,     0,     0,   309,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,     0,     0,     0,     0,     0,   224,
     250,     0,     0,   248,   380,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,   268,     0,     0,
       0,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   294,     0,   255,     0,     0,   257,     0,     0,     0,
     391,     0,   224,     0,     0,     0,     0,     0,     0,     0,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    74,    75,     0,     0,     0,   266,
      40,   262,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,     0,   225,     0,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,   493,
       0,     0,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   340,     0,     0,     0,   201,     0,
       0,     0,     0,     0,     0,   375,   376,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   447,
     465,     0,     0,     0,     0,   526,   527,     0,     0,     0,
       0,     0,   484,     0,   390,   511,     0,     0,     0,     0,
     519,     0,   409,   408,   407,   406,   402,   403,   410,   411,
     405,   404,   395,   394,     0,   396,   518,   397,   400,   398,
     399,   401,   491,     0,     0,   492,   469,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,   344,     0,     0,
       0,     0,     0,     0,   378,     0,     0,     0,     0,   377,
       0,   224,     0,     0,     0,     0,     0,   501,   500,     0,
       0,     0,     0,     0,     0,     0,   303,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,     0,     0,   249,     0,     0,     0,   243,     0,     0,
       0,     0,   374,     0,     0,     0,     0,   390,   515,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   601,     0,     0,
       0,   486,     0,     0,   254,   258,   256,   260,     0,   396,
       0,   491,   469,   622,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,   390,     0,    65,     0,
       0,     0,     0,    81,     0,    65,    66,     0,     0,     0,
     491,     0,     0,   469,     0,     0,     0,   195,     0,     0,
       0,   617,    28,    26,    27,     0,     0,     0,     0,     0,
     492,   565,    30,     0,    29,     0,     0,   263,   612,   613,
       0,   614,   565,     0,    76,   116,    77,   126,   494,   496,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   551,   552,
     212,     9,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   435,   422,     0,   424,   425,   426,   427,   428,   548,
     429,   430,   431,     0,     0,     0,   540,   539,   538,     0,
       0,     0,   545,     0,   481,     0,     0,     0,   483,     0,
       0,     0,   130,   464,   522,   521,   205,     0,     0,   450,
     547,   455,     0,   461,     0,     0,     0,     0,   512,     0,
       0,   462,     0,   524,     0,     0,     0,     0,   454,   453,
     476,    72,    73,     0,     0,     0,     0,     0,     0,     0,
     390,   342,   347,   345,     0,   355,     0,   150,   151,     0,
     205,     0,   390,     0,     0,     0,     0,   244,     0,   259,
     261,     0,     0,     0,   213,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   316,     0,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,   349,   363,     0,     0,     0,   245,     0,     0,
       0,     0,   208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     0,     0,     0,   588,     0,   595,
     584,   585,   586,     0,   600,   599,     0,     0,   589,   590,
     591,   597,   604,   603,     0,   141,     0,   578,     0,   580,
       0,     0,     0,   573,     0,   253,     0,     0,     0,     0,
       0,     0,     0,   335,     0,     0,     0,   386,     0,   618,
       0,   103,    65,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,   570,
      50,     0,     0,     0,    63,     0,    41,    42,    43,    44,
      45,     0,   454,   453,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   564,   563,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,   133,
     134,     0,     0,     0,     0,     0,     0,     0,   157,   157,
       0,     0,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   529,
     530,   531,     0,     0,     0,     0,     0,   484,   485,     0,
     457,     0,     0,     0,   520,   412,   513,   470,   468,     0,
     467,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   354,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,     0,     0,
       0,   321,     0,     0,   320,     0,   323,     0,   325,     0,
     310,   317,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,   247,   246,   381,
       0,     0,     0,    37,    38,     0,     0,     0,     0,   556,
       0,     0,     0,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   486,   487,   582,
       0,   470,     0,     0,   224,   336,     0,   337,   224,     0,
       0,   571,     0,    88,     0,     0,     0,     0,    86,    93,
      95,     0,   559,     0,   101,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,    36,   470,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,     0,   566,     0,     0,    34,    33,     0,   566,   615,
       0,     0,   117,   122,     0,     0,     0,   136,   139,   140,
     489,     0,    79,     0,     0,     0,     0,    80,   161,     0,
       0,     0,     0,   162,   179,   180,   159,     0,     0,     0,
     163,   190,   181,   185,   186,   182,   183,   184,   171,     0,
       0,   423,   432,   433,   434,   541,     0,     0,     0,   479,
     480,   482,   131,   448,   478,   451,   456,     0,     0,   484,
     191,   463,     0,    72,    73,     0,   475,   471,   473,   542,
     187,     0,     0,     0,   153,     0,     0,   353,     0,   152,
       0,     0,     0,     0,     0,     0,   267,     0,     0,     0,
       0,   224,   224,     0,     0,   322,   508,     0,     0,   324,
     326,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,   188,     0,     0,     0,     0,
       0,   168,   169,     0,     0,     0,     0,   104,   105,   106,
     110,     0,   596,     0,     0,   594,     0,   605,     0,     0,
     142,   143,   602,   579,   581,     0,     0,     0,     0,     0,
       0,   334,   338,   334,     0,   387,    87,    65,     0,     0,
       0,     0,    85,     0,   557,     0,     0,     0,     0,     0,
       0,   608,   607,     0,     0,     0,     0,     0,   506,     0,
       0,   475,   264,   471,   265,     0,     0,     0,     0,     0,
     229,   226,     0,     0,   569,   567,     0,     0,     0,     0,
     118,   123,     0,     0,     0,   549,   550,   135,   357,   358,
     359,   360,   158,   166,   167,   172,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,     0,   458,     0,
       0,     0,     0,   537,   477,     0,     0,   173,     0,   192,
     343,     0,     0,     0,     0,   193,     0,     0,     0,     0,
       0,     0,   505,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   240,     0,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,   361,   362,    39,
       0,   554,     0,     0,   288,   287,     0,     0,     0,     0,
       0,     0,   145,   146,   149,   148,   147,     0,   583,     0,
     619,     0,     0,     0,     0,     0,     0,    98,     0,     0,
      99,   560,     0,     0,     0,    90,     0,     0,     0,    46,
       0,     0,     0,     0,     0,    48,     0,   230,   227,   228,
      35,     0,     0,   616,   278,     0,   130,   141,     0,     0,
     138,     0,     0,     0,   160,   189,     0,     0,     0,     0,
       0,   543,   544,     0,   484,   459,     0,   472,   474,     0,
       0,   175,   196,     0,     0,     0,   350,   350,     0,   111,
     112,   224,     0,   216,   217,   311,     0,   318,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     220,     0,     0,     0,     0,   107,   108,   587,   593,   592,
     144,     0,     0,     0,   339,     0,    94,    96,     0,   102,
       0,    84,   609,    91,    92,    51,     0,     0,     0,     0,
     507,     0,     0,   472,   568,     0,     0,     0,     0,   120,
     606,     0,   127,     0,     0,     0,     0,   178,     0,     0,
       0,     0,   314,     0,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   503,     0,   328,     0,
       0,   305,     0,   232,     0,     0,     0,     0,     0,     0,
       0,   553,   289,     0,     0,   373,   224,   388,     0,   558,
       0,    47,     0,     0,     0,    64,    49,     0,   279,   119,
     124,   130,     0,     0,   155,   156,   154,     0,     0,   460,
       0,     0,     0,     0,     0,   351,   366,     0,     0,   367,
       0,   214,     0,   319,     0,   301,     0,   224,     0,     0,
       0,     0,     0,     0,   170,   109,   285,   334,   100,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,   194,     0,   370,     0,   371,   372,   502,     0,     0,
     307,   235,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,    61,     0,     0,   121,     0,     0,     0,   315,
       0,     0,   327,   306,   302,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   237,   238,   239,     0,   233,
     341,    52,     0,    59,     0,   274,     0,   546,     0,     0,
       0,   308,     0,     0,    53,     0,     0,   284,     0,     0,
       0,   234,     0,     0,     0,     0,   528,     0,     0,    56,
      54,     0,    57,     0,   368,   369,     0,     0,    62,    60,
      58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   118,  1075,   119,   120,  1059,  1918,  1924,
    1356,  1570,  2080,  2213,  1357,  2184,  2231,  1358,  2215,  1359,
    1360,  1574,   443,   599,   600,  1148,   121,   786,   469,  1936,
    2091,  1937,   470,  1804,  1433,  1388,  1389,  1390,  1534,  1740,
    1741,  1216,  1629,  1620,  1817,   763,   611,   277,   278,   357,
     204,   279,   453,   454,   125,   126,   127,   128,   129,   130,
     131,   132,   280,  1250,  2116,  2175,   954,  1246,  1247,   281,
    1038,   282,   136,  1462,  1214,   927,   969,  2050,   137,   138,
     139,   140,   283,   284,  1172,  1187,  1312,   285,   791,   286,
     916,   790,   472,   628,   325,  1777,   365,   366,   288,   569,
     373,  1343,  1563,   464,   459,  1305,  1015,  1609,  1770,  1771,
    1000,   466,   142,   421
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1909
static const yytype_int16 yypact[] =
{
   13660,   109,   129, 13822, -1909, -1909,  -184,   127,    64,   -61,
      -7,    11,    33,   222,   316,   323,   330,    54,   336,   373,
      55,   389,   392,   174,   187,    31,  -164,   568,  -164,   195,
     200,   241,    20,   254,   338,    53,   391,   395,   407,   420,
     427,   428,   435,   445,   451,   479,   244,   447,   522,   654,
     453,   507,   631,   495,  7420,   531,   518,   586,   683,   -44,
     481,    78,     5,   248,   557,   715,   -69,   602,    -4,    -4,
     678,   359,   370,   684, -1909, -1909, -1909, -1909, -1909,   573,
     367,   733,   748,    17,    57,   756,   762,   -33,   802,   940,
     941,   942,  6428,   943,   699,   700,   701,    23,    58, -1909,
     702,   703, -1909, -1909,   948,   950,   705, -1909,  1121,   708,
    4150,    27,    36, -1909, -1909, -1909, 12053,   707, -1909, -1909,
   -1909, -1909, -1909,   706, -1909, -1909, -1909, -1909, -1909, -1909,
   -1909, -1909, -1909, -1909,  -102, -1909, -1909, -1909, -1909,    48,
   -1909,   955,   704,  6178,   344,   709,   958, 12053, 14001, 14001,
   14001, -1909, 12053, -1909, -1909, -1909, -1909, 14001, -1909, -1909,
   12053, -1909, -1909, -1909, -1909,   710,   716,   960, -1909, -1909,
    6275,   717,   720,   721,   722,    31, 12053, 12053, 12053,   723,
   12053, 12053, 12053,   724, 12053, 12053, 12053, 12053, 12053, 12053,
   12053, 14001, 12053, 12053, 12053, 12053,  6428,   727, -1909, 10138,
   -1909, -1909, -1909,   725,  6428,  7668, 14001, -1909, -1909, -1909,
   -1909, -1909,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,   234,  -164,  -164,  -164,  -164,
    -164,   728,  -164,  -164,   731,    78,   360,   360, -1909, -1909,
   -1909,  -164,  -164,    42,   794,   795,   796,   732,  7668,   858,
      78,    78,   737,  -164,  -164,   738,   739,   740, -1909, -1909,
   -1909, 12053,  7916, 12053, 12053,  8164,    31,   803,    43, -1909,
   -1909,   752, -1909,  4881, -1909, -1909, -1909, -1909, -1909,   130,
   12053, 10138, 10138,   751,   757,  8412,  6428,  6428,  6428, -1909,
   -1909, -1909, -1909, -1909, -1909, -1909,   761, -1909,   758,   763,
    8660,   760,  5327,  1011,  7668,   765,    23,   766,   768,    -4,
      -4,    -4, 12053, 12053,    -2, -1909,    21,    -4, 10813,   272,
     -38,   767,   773,   774,   775,   776,   777,   779, 10138, 12053,
    6428,  6428,  6428,   780,    22,  1010,   782, -1909,  1025,  1026,
   -1909,   781,   783,   785, -1909, -1909,   786,  6428,   787,   784,
     790,   791, -1909, 12053,  6676, -1909,  1039,  1040, 12053, 12053,
   12053,   276, 12053,   793, -1909,   860, 12053, 12053, 12053, -1909,
   -1909, 12053, -1909,  -164,  -164,  -164,   800,   801,   805,  -164,
    -164,  -164,  -164,  -164,  -164,  -164, -1909,  -164, -1909, -1909,
   -1909,  -164,  -164,   806,   807,  -164,   808, -1909,   809,  1046,
    1047,   810, -1909, -1909,  1053,  1052,  1056,  1058,  -164, 12053,
   15256,   140, 14001, 10138, 12053, -1909, -1909,  7668,  7668, -1909,
     814,  6275,    78,  1067, -1909, -1909, -1909, -1909, -1909, -1909,
   12053, 12053,    41,  7668,  1071,   682,   824,  1575,   825,  1074,
      69,   827, -1909,   828, 14127, 12053, -1909,  1670,  -131, -1909,
      49,  -116,   -84,  7355, -1909,   -18, -1909,    68,  7603,  -174,
     -89,   991, -1909,    31,   826, 12053, 12053, 12053, 12053,   829,
   15772, 15797, 15822, 12053, 15847, 15872, 15897, 12053, 15922, 15947,
   15972, 15997, 16022, 16047, 16072,   835, 16097, 16122, 16147,  5688,
    1080, 12053, 10138,  5210, -1909,   -40, 12053,  1086,  1087,   843,
   12053, 12053, 12053, 12053, 12053, 12053, 12053, 12053, 12053, 12053,
   12053, 12053, 12053, 12053, 12053, 12053, 10138, 12053, 12053, 12053,
   12053, 12053, 12053, 10138, 10138,   841, 12053, 12053, 14001, 12053,
   14001,  7668, 14001, 14001, 14001,   842,   844,   845, 12053,    32,
   -1909,  2683, 12053,  7668,  6428,  7668, 14001, 14001, 10138,    31,
    6275,    31,   848, 10138,   848, -1909,   848, 16172, -1909,   107,
     846,    60,  1035, -1909,  1093, 12053, 12053, 12053, 12053, 12053,
   12053, 12053, 12053, 12053, 12053, 12053, 12053, 12053, 12053,  8908,
   12053, 12053, 12053, 12053, 12053,    31, 12053, 12053,  1099, -1909,
     686, 16197,   288,   348, 12053, 12053, 12053, -1909,  1097,  1100,
    1100,   861, 12053, 12053, 12053, 12053,  1116, 10138, 10138, 15284,
     872,  1141, -1909,   894, -1909, -1909,  -172, -1909, -1909,  7851,
    8099,    -4,    -4,   344,   344,  -125, 10813, 10813, 12053,  4706,
    -101, -1909, 12053, 12053, 12053, 12053, 12053, 12053, 12053, 12053,
   12053,   351, 16222,  1142,  1144,  1145, 12053,  1148, 12053, -1909,
   -1909, 12053, 12323, -1909, -1909, 10138, 10138, 10138, 12053,  1150,
   10138, 12053, 12053, 12053, 16247,   903, -1909, -1909, 16272, 16297,
   16322,   972,  8347, -1909,   905,  5245, 16347, 16372, 15367, 14001,
   14001, 14001, 14001, 14001, 14001, 14001, 14001, 14001, 12053, 14001,
   14001, 14001, 14001,    10,  6275, 14001, 14001, 14001,    31,    31,
   -1909, -1909, 10138, -1909,   906, 12421, -1909,   910, 12519, 12053,
     848, 12053, -1909,    31, 12053, 12053,  1099,   907,   425, 16397,
   14022,   915,   463, 12053,  1161,   923,  7668, 16422, 15394,   207,
     924,  1172,  1179, -1909, -1909, -1909, 10138,   146, 12053, -1909,
   -1909, -1909,    31, 12053, 12053,  1099,   935, -1909,   938,   -23,
      78,     5,    78, -1909,   939, 14386, -1909,    93, 10138,    31,
   12053, 12053,  1188,  1189, 10138,  1191, 10138, 12053,  1193, 14001,
      31, 11061,  1188, 12053,  1194, -1909,    31,  1195, 14001, 12053,
     954,   956, -1909, 12053,  8595,  8843,  9091,  9334,  6275,  1187,
    1199,  1200, 16447,  1202,  1203,  1204, 16472,  1206,  1207,  1209,
    1210,  1211,  1212,  1213, -1909,  1214,  1215,  1217, -1909, 12053,
   16497, 10138,   977, 10138, 14415, -1909, -1909,  1230, 15340, 15340,
   15340, 15340, 15340, 15340, 15340, 15340, 15340, 15340, 15340,  9577,
   15340, 15340, 15340, 15340,   902,   308, 15340, 15340, 15340,  9825,
   10073, 10412,  5210,   986,   988,   103, 10138, 10752, 11017,   308,
   11092,   308,   983,   985,   989,   122, 10138, 12053, 12053, 17447,
   -1909,   308,   994, 14444, 14473, -1909, -1909,   992,   457,   308,
     -64,  1001,   387,   493,  1246, -1909,  1188,   308,  1002,  1000,
    5358,  5394,  1173,  1304,  1392,  1392,   410,   410,   410,   410,
     410,   410,   376,   376, 10138,   386, -1909,   386,   386,   848,
     848,   848,  1005, 16522, 15421,   209,   390, 10138, -1909,  1250,
    1008,  1009, 16547, 16572, 16597, 12053,  7668,  1260,  1259, 10721,
   16622, 14502, 16647, 16672, -1909,   500,   509, 10138,  1012, -1909,
   12617, -1909, 12715, 12813,    -4, 12053, 12053, -1909, -1909,  1014,
    1015, 10813,  5865,  1128,   575,    -4, 12911, 16697, 14531, 16722,
   16747, 16772, 16797, 16822, 16847, 16872,  1013,  1264, 12053,  1266,
   -1909, 12053, 16897, -1909, 15448, 13009, 15475, -1909,   515,   520,
     523, 14560, -1909,   525, 15502, 15529, 11350, -1909, -1909,  1270,
    1272,  1273,  1017, 12053, 13107, 12053, 12053, -1909, -1909,    30,
     464,   468,   464,  1030,  1031,  1024,   308,   308,  1028, 11425,
     308,   308,   308,   308, 12053,   308,  1275, -1909,  1029,  1038,
     475,  -156,  1042,   553, -1909, -1909, -1909, -1909, 15340,   386,
   13205,  1037,   511,  1041,  1108,  1291,  1143, 11151,  1045,  1050,
    1295,  7668, 14589, -1909, 12053,  1300,   211,   120,  6275, 12053,
    1301,  1305,    25, -1909,   554,  1263,  1267,  7668, 14618,    29,
    1055, 16922, 15556,   421, 12053, 12053,  1063,  1061,  1066,  1064,
    9156, -1909, -1909, -1909, -1909, 14001,   132,  1068, 16947, 15583,
   -1909,  1070, -1909,   249, -1909,   269, 11676, -1909, -1909, -1909,
    1072, -1909,  1081, 11759, -1909,    16, -1909, -1909, 17447, -1909,
    1318, 15340, 12053, 12053, 12053, 12053,   308,    -4,  7668,  7668,
    1323,  7668,  7668,  7668,  1325,  7668,  7668,  7668,  7668,  7668,
    7668,  7668,  7668,  7668,  7668,  1846,  1327, 10138,  5210, -1909,
   -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909,
   -1909, -1909, -1909, 12053, -1909, -1909, -1909, -1909, -1909, -1909,
   -1909, -1909, -1909, 12053, 12053, 12053, -1909, -1909, -1909,   555,
   12053, 12053, -1909, 12053, -1909,  7668, 14001, 14001, -1909,   560,
   14647, 14676,  1076, -1909, -1909, -1909,  1149, 12053, 12053, -1909,
   -1909, -1909,  1188, -1909,  1188, 12053, 12053,  1090, -1909,  7668,
    -164, -1909, 12053, -1909, 12053, 12053,   566,  1188,   209,   137,
   -1909, 12053, 12053,   308,   569,  7668, 10138, 10138,  1331,  1337,
    1338,  2777, -1909, -1909,  1340, -1909,  1096, 17447,  1089,  1343,
   -1909,  1344,  1345,  1346,  1347,   571,  1351, -1909, 13303, -1909,
   -1909,   -88, 12009, 12355, -1909, -1909, 14705,  -113,  1240,  1353,
   11394,  1104,  1355,  1109,    37,    44,   -74, -1909,   -82, -1909,
     575,  1356,  1358,  1359,  1361,  1362,  1363,  1364,  1365,  1366,
     344,  7668, 17447, -1909,  2119,  1120,  1369, -1909,  1370,  1371,
    1258,  1372, -1909,  1373,  1375,  1377, 12053,  7668,  7668,  7668,
    1381, 12453, -1909,  5595,  1278,    52,  1382, -1909, 10138, -1909,
   -1909, -1909, -1909, 14001, -1909, -1909, 12053, 14001, -1909, -1909,
   -1909, -1909, 17447, -1909,  1130,  1129, 14001, -1909, 14001, -1909,
    1188, 14001,  1138, -1909,  1131, -1909,  1188, 12053, 12053,  1137,
      78,  1139, 11484, -1909,  2178,  1140,  7668, -1909,  1163, -1909,
   14734, -1909, -1909, 12053,  1386,    45, 12053,  1389,  1390,  2205,
   -1909,  1391,    23,  1393,  1171,   308,  -164,  -164,  1394, -1909,
   -1909,  1174,  1175,  1176, -1909,  1420, -1909, -1909, -1909, -1909,
   -1909,  1188,   175,  2089, 12053, 15610, 16972, 12053,  9399, 12053,
   10138,  1177,   572,  1421,   124,  1188, -1909,  1180, 12053,  1422,
    1425, 12053,  1188, 11727, 12053,  4988,   308,  5656,  1182,  1178,
   -1909,  1427, 16997, 17022, 17047, 17072,  1433,    24,  1309,  1309,
    7668,  1435,  1436,  1437,  7668,   -92,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1446,  1447, -1909,  1449,   574, 15340, 15340,
   15340, 15340,   308, 12551, 12649, 12747,  1208,   308,   308, -1909,
   -1909, -1909,  1318,   308, 17097, 15340,  1216,    -1, 17447, 15340,
   -1909,  1452,   308, 12845, 17447, 17447, -1909,   517, -1909,  1456,
   -1909, 17122, 15637, -1909,   308,  1455,   577,   580,  7668,  7668,
    7668,  1458,  1460, -1909,   218, 12053,  7668,  7668,  7668,  1219,
    1220,  1461,   565, -1909, 12053, 12053, 12053,  1221,  1222,  1223,
    1226, -1909,  2314,  7668, -1909, 12053, -1909,  1465, -1909,  1473,
   -1909, -1909, 10813,   347,  6924, -1909,  1227,  1228,  1231,  1232,
    1233,  1234,  9642,  1229,  1483, -1909, 10138, -1909, -1909, -1909,
    1236, 12053, 12053, -1909, -1909, 15664,  1486,  1487,  1310, -1909,
   12053, 12053, 12053, -1909,  1489,  1490,  1491,   747,   485,  1239,
    5035,  1241, 12053,    40,   308,  1251,   308,  1242, -1909, -1909,
    6275,   536, 12053,  1269, -1909, -1909,  2554, -1909, -1909,  1245,
    1518, -1909,  2730, -1909,   353,  1274,  1519,  2837, -1909, -1909,
   -1909,    23, -1909,   583, -1909, 12053,   218, 12100, 12280, -1909,
    1282, 12053, 12053,  7668,  1271, -1909,   508,  1524,  1543, 17147,
    1544,  1246, 17172,  1299,   593, 17197,   595,  1549,  1551, -1909,
   -1909, 14001,  1311,  1555, 17222, -1909, -1909, 12943,  1312, -1909,
    6363,  5930, 17447, -1909,  1553,  -164,  8164, -1909, -1909, -1909,
   -1909,  1318, -1909,  1557,  1560,  1562,  1563, -1909, -1909,    -4,
    1565,  1566,  1567, -1909, -1909, -1909,  1445,   -22,  1472,  1569,
   -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909,  1571,
    1324, -1909, -1909, -1909, -1909, -1909, 12053, 12053, 12053, -1909,
   -1909, -1909,  1178, -1909, -1909, -1909, -1909, 12053,  1326,  1320,
   -1909, -1909, 12053, 12053, 12053,   308,   209, -1909, -1909, -1909,
   -1909,  1328,  1330,  1574,   -92,  1579, 12053, -1909,  7668, 17447,
    1448,  1451,   937, 10138, 10138, 12053, -1909, 10721, 14763, 17247,
    6611,   344,   344, 12053, 12053, -1909,   172,  1332, 17272, -1909,
   -1909, 14792,   -73, -1909,  1581,  1584,  7668,    -4,    -4,    -4,
      -4,    -4,  7172,  1586, -1909, -1909,   596, 12053,  3265,  3309,
    1587, -1909, -1909,  7668,  6859,   562, 17297, -1909, -1909, -1909,
   -1909, 10381, -1909, 14001, 12053, -1909, 14001, 17447, 10473,  6275,
    1335, -1909, -1909, -1909, -1909,  1348,  1342, 12053, 12053, 14821,
   12053, 14022, -1909, 14022,  7668, -1909, -1909,  6275, 12053,  1591,
    1598,    25, -1909,  1599, -1909,    23, 15691,  7668, 14001,  1600,
     308, -1909,  1354,   308, 12053, 13041, 13139,   603, -1909, 12053,
   12053,   327, -1909,  1350, -1909,  1338,  1601,  1604,  1345,  1606,
   -1909, -1909,  1609, 12053, -1909, -1909, 12053, 11810,  1610, 12053,
   -1909, -1909,  1368, 12280,   609,  4745,  1611, -1909, -1909, -1909,
   -1909, -1909,   393, -1909, -1909, -1909,  1475,  1614,  1383,  1384,
    1385, -1909,  1635,  7668, 15340, 15340, 13237, 15340, -1909,  1399,
   13335, 17322, 15718, -1909, -1909, 10138, 10138, -1909,  1636, -1909,
   17447,  1637, 12053, 12053,  1397, -1909,   610,   612, 15312,  3510,
    1646,  1400, -1909, -1909, 12053,  1398,  1401, 14850, 15745,  1649,
    7668,  1650,  1404, 12053, -1909, -1909,   617,   -65,   -48,   -39,
     -30,   -17,  9890,   -15, -1909,  1653, 14879, -1909, -1909, -1909,
    1477, -1909, 12053, 12053, -1909, -1909, 10138,  3650,  1655,  1411,
   15340,   308, 17447, -1909, -1909, -1909, -1909,    40, -1909,  6275,
   -1909, 14908,  1409,  1412,  1413,  1663,  3683, -1909,  1665,  1667,
   -1909, -1909,  1418,  1672,   618, -1909,  1676,  1677,   298, 17447,
   12053, 12053,  1430,  7668,   619, 17447, 17347, -1909, -1909, -1909,
   -1909, 17372, 13458, -1909, -1909, 14937,  1076,  1129,  7668,   308,
   -1909, 12053,  6275,    31, -1909, -1909, 10138, 10138, 12053,  1679,
     620, -1909, -1909, 12053,  1320, -1909, 12053, -1909, -1909,   625,
     627, -1909, -1909,  4044,  4237,  7668,   512,   607, 10138, -1909,
   -1909,   344,  7107, -1909, -1909, -1909,  1681, -1909,  1450,  7668,
   -1909, 14966,  1682, 10138,    -4,    -4,    -4,    -4,    -4, -1909,
   -1909, 12053, 14995, 15024,   628, -1909, -1909, -1909, -1909, -1909,
   -1909,  1453,  1684,  1454, -1909,  1687, -1909, -1909,    23, -1909,
    1509, -1909, -1909, -1909, -1909, -1909, 12053, 14056, 14089,  7668,
   -1909,  1690, 12053,  1457, -1909, 12053,  1691,  1459,  1462, -1909,
   -1909,  2337, -1909,  1463,   630,   635, 15053, -1909,  1464, 14122,
    1468, 14155, -1909,  1467, -1909, -1909,   636,  1469,    -4,  7668,
    1692,  1470,    -4,  1695,   638,  1471, -1909, 12053, -1909,  1696,
    1568, 13401,  1474, -1909,   641,   179,   210,   224,   236,   258,
    4429, -1909, -1909,  1701,  1706, -1909, -1909, -1909,  1709, -1909,
    1478, 17447, 12053, 12053,   643, -1909, 17447, 14188, -1909, -1909,
   -1909,  1076,  6275,  1476, -1909, -1909, -1909, 12053, 12053, -1909,
   12053, 10138,  1710,    -4,    95, -1909, -1909,    -4,   102, -1909,
    1716, -1909, 15082, -1909, 12053, -1909,   575, -1909,  1719, 10138,
   10138, 10138, 10138,  9890, -1909, -1909, -1909, 14022, -1909, 12053,
   17397, 14221,    46, 12053,  1479, -1909, -1909, 14254, 14287, 14320,
     644, -1909,   268, -1909,   277, -1909, -1909, -1909,  4495,   424,
   13499, -1909,   650,   652,   653,   658,   283,   660,  1480,   661,
   -1909, 12053, -1909,  7668, 15111, -1909, 12053, 12053, 12053, -1909,
      -4,    -4, -1909, -1909, -1909,   575,  1723,  1725,  1730,  1731,
   10138,  1732,  1733,  1734,  1488, 17422,   663,  1735, 15140, 15340,
   14353,   286,   345,   456, -1909, -1909, -1909, -1909,   666, -1909,
   -1909, -1909, 14001, -1909,  1492, -1909,  1737, -1909, 12053, 12053,
   12053, -1909,  1738,   669, -1909,  1493,  7668, -1909, 15169, 15198,
   15227, -1909,  1739, 14001, 14001,   671, -1909,  1742,  1743, -1909,
   -1909,   672, -1909,  1744, -1909, -1909,  1746, 14001, -1909, -1909,
   -1909
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1909, -1909, -1909, -1909,   379, -1909, -1909, -1909, -1909,  -375,
   -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909, -1909,
   -1909, -1909,  -732,   -71,  2256,  4084, -1909,  1285, -1909, -1909,
   -1909, -1909, -1909, -1909, -1908, -1909,   324,   148,  -180, -1909,
    -137, -1909,    87,   364, -1909,  1763, -1909,   303,   -49, -1909,
   -1909,     0,  -622,  -294, -1909, -1909, -1909, -1909, -1909, -1909,
   -1909, -1909,  1764, -1909, -1909, -1909, -1909, -1246, -1245,  1765,
   -1733,  1766, -1909, -1909, -1909,  1160, -1909,  -196, -1909, -1909,
   -1909, -1909,  2664, -1909, -1909, -1421,   235,  1770, -1909,     6,
    -717, -1909, -1909,   -63, -1909, -1687,  1124,  -179,  3197,  3313,
    -314,    13, -1909,   533,   -68, -1909, -1909,    38,   212, -1679,
    -147,   996, -1909,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -570
static const yytype_int16 yytable[] =
{
     143,  1491,   623,   124,  1493,   324,   326,  1049,   329,  1032,
     465,   949,   950,   310,   165,  1057,  1658,   500,  1902,  1866,
    1903,   344,   167,  1385,   179,   507,   657,   371,  2027,   165,
    1618,   166,   414,  1350,   639,   165,   165,  1285,  1063,   151,
     409,   416,   413,  1486,  1738,   739,  1627,   550,   573,  1554,
    1488,   289,  2162,   662,   426,  1081,  1524,   183,   769,  1895,
     294,   349,   375,   350,  1239,  1092,   631,   632,   354,   473,
     144,   355,   444,   165,   145,   449,  1818,   780,   752,   784,
     348,   294,  1240,   295,   356,   785,   168,   944,   169,   289,
     315,  1241,  1242,  1243,   374,  1819,  1628,  1244,  1245,  1072,
    1310,  2143,   474,  1311,  1066,   410,   304,   345,  2145,   305,
     306,   307,   595,   631,   632,     4,   316,   608,   609,   610,
     767,   715,   308,   718,  1939,   631,   632,  1332,   768,     5,
    1590,   730,   317,   318,   951,   773,  1950,   631,   632,   595,
     450,   146,  1478,   774,   452,   460,   460,   460,   424,   723,
     631,   632,   425,  1055,   467,   351,   631,   632,   955,  1525,
    1526,   653,   654,   655,   787,   631,   632,   775,   147,  1190,
     785,  1474,   479,   631,   632,   776,   299,  1492,   669,   300,
     575,  1490,   301,  2134,   302,   309,  1863,  1181,   460,   148,
     631,   632,  1182,   289,  1983,    46,   289,   546,   547,   631,
     632,   289,   289,   460,  1351,  1352,  1353,  1354,   631,   632,
    1487,  1984,   642,   346,  1048,   822,   643,  1489,  1332,   823,
    1985,   631,   632,   631,   632,  1332,   740,   741,   153,  1986,
    1555,  1556,   117,   778,   320,   321,   631,   632,  1829,   117,
    1739,   779,  1987,   149,  1988,   117,   322,   117,  1491,   168,
     323,   169,   633,   117,   117,   289,   626,   627,  1185,   631,
     632,   150,   631,   632,   635,   640,   168,  1014,   169,   289,
     180,   347,   289,   571,   658,   634,   659,   372,  2046,  1342,
     145,   415,   570,   744,  1355,   745,  1286,   152,   289,   289,
     417,   117,   289,   289,   289,   289,   551,   574,   427,   770,
    2163,   771,   428,   184,   157,   772,   123,   289,   376,   160,
     168,   289,   169,   374,  1333,  1336,   438,   439,   781,   753,
     771,   754,   154,  -562,   782,   755,  1073,  1074,   940,   155,
     942,   943,  2084,   631,   632,   289,   156,   289,   289,   289,
     631,   632,   158,   434,   435,   436,   437,   956,   451,   311,
     438,   439,   312,   596,   289,   597,  1158,  1073,  1074,   598,
    1757,   289,   885,   734,   303,   975,   823,   438,   439,   434,
     435,   436,  1056,  1168,   330,   875,  1335,   438,   439,   159,
     596,   779,   597,  1374,   438,   439,   598,   438,   439,   994,
     724,   823,   725,  1449,  2158,   161,   726,   865,   162,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   631,   632,   460,
     289,   594,   438,   439,   289,   289,   163,  1859,  1030,  -564,
     434,   435,   436,   437,   434,   435,   436,   437,  2119,   164,
     289,   434,   435,   436,   437,   176,   446,   756,   631,   632,
     177,   446,   446,   446,   438,   439,   438,   439,   438,   439,
     446,   304,   631,   632,   305,  1436,   307,  1437,   331,  2120,
     792,   340,   332,   341,   631,   632,  2186,   308,   333,   334,
    1447,   335,   336,  2121,   533,  1239,   534,    67,    68,    69,
      70,   178,   881,    73,   446,  2122,   631,   632,   195,   289,
    1379,   337,    82,  1240,   181,    85,   631,   632,   823,   446,
     631,   632,  1241,  1242,  1243,   631,   632,  2123,  1244,  1245,
    1380,   631,   632,   289,   631,   632,   641,  2170,   823,  2225,
     289,   855,   681,  2040,   145,   460,  2171,   460,   289,   460,
     460,   467,  2180,   920,  1002,  2209,   871,   823,   545,  2015,
     289,   289,   289,   460,   460,   289,   167,  2016,   167,   744,
     289,   745,  1239,   554,   555,   880,   196,   882,   947,   948,
    1883,  1686,  1687,   627,   438,   439,   434,   435,   436,   437,
    1240,  -569,   296,   631,   632,   297,   289,   298,   182,  1241,
    1242,  1243,   912,  1537,  1239,  1244,  1245,   320,   321,  1541,
     438,   439,  1703,   921,  2210,   200,   966,   823,   201,   322,
     823,   202,  1240,   328,   289,   289,   721,   590,   591,   592,
     593,  1241,  1242,  1243,   203,   594,   197,  1244,  1245,   592,
     593,   631,   632,   452,   452,   594,  1017,   168,  1503,   169,
    1201,   185,  1202,  1184,  1576,   186,  1185,  1228,   587,   588,
     721,   590,   591,   592,   593,  2047,  2048,   187,  1592,   594,
     198,  2049,   289,   289,   289,  1598,   171,   289,  1050,   172,
     188,  1364,   173,  1318,   174,  -565,   448,   189,   190,  2173,
    1034,   458,   461,   462,   823,   191,   467,   460,   467,   460,
     460,   460,   460,   460,   460,   192,   460,   460,   460,   460,
    1016,   193,   460,   460,   460,   167,  1022,   199,   744,   289,
     745,  2211,  1068,  1239,  1021,   744,  1178,   745,  1040,   744,
    1031,   745,  1041,   779,   495,   446,   744,  1288,   745,   194,
    1106,  1240,  1678,   289,  1308,   735,   744,   205,   745,   509,
    1241,  1242,  1243,   289,   823,   206,  1244,  1245,  1188,  1060,
    2051,  2052,   823,  1730,  1731,  1223,  2049,   764,  1780,   823,
    1748,  1317,  -566,  1318,  1224,   289,  1077,  1663,   823,  1664,
    1269,   289,   291,   289,   823,  1270,   467,  1090,  1271,   823,
    1273,   290,   823,  1095,   823,   460,  1747,   293,  1748,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,   313,  1314,  1345,
    1422,   594,   823,   823,   823,  1429,   314,  1884,   289,   823,
     289,  1446,  1758,   339,  1454,   823,  1471,  1588,   823,  1640,
     823,   823,  1671,   823,  1767,  1672,   823,   342,  1764,   823,
     292,   446,  1765,   446,  1200,   446,   446,   446,  1787,   343,
    1789,  1875,   823,   289,   823,   823,   319,   352,  1922,   446,
     446,  1218,  1923,   289,  1940,  1966,   353,  1967,  1941,   823,
    2149,   823,  1982,  2012,  2021,  2038,  1923,   779,  2022,  1923,
    2042,  1231,  2043,  2073,   823,  2094,   823,   823,  1237,   823,
    2095,  2102,  1248,  2110,   823,  1923,  2118,   823,  2132,  2169,
     823,   289,  1923,   823,  1491,  2176,   358,  2177,  2178,   823,
     575,   823,   823,  2179,   289,  2181,  2183,   823,  2204,   823,
    2022,  2212,  1923,   289,  2222,   823,  2233,  2236,  2223,  2193,
    1923,  2237,   327,   744,   289,   745,   746,   744,   338,   745,
     917,  1844,   764,  1845,   359,   360,   361,   367,  1491,   368,
     369,   370,   377,   378,   379,   727,   380,   381,   411,   422,
     423,   429,   430,   455,   456,   764,   471,   475,   145,   473,
     476,   477,   478,   483,   487,  1334,  1337,   501,   541,   506,
    1338,   544,  -198,  -199,  -200,   553,   552,   556,   559,   560,
     561,   572,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   604,   446,   446,   446,   446,   425,   605,   446,   446,
     446,   612,   613,   614,   617,   620,   660,   644,   764,   622,
     624,   764,   625,   645,   646,   647,   648,   649,  1562,   650,
     656,   663,   664,   764,   661,   665,   671,   666,   289,   667,
     668,   670,   672,   673,  1397,   676,   677,   683,   684,  1344,
     692,   693,   710,   711,   289,   694,   705,   706,   708,   713,
     714,   709,   716,  1067,   712,  1069,   717,   289,   733,  1855,
    1856,   859,   460,   861,   736,   863,   864,   743,   748,   750,
     751,   144,   446,   757,   789,   793,   814,   819,   798,   877,
     878,   446,   825,   826,   827,   856,   866,   594,   867,   868,
     888,   889,   886,   915,   925,   289,   289,   926,   289,   289,
     289,   929,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   934,   938,   289,   165,   382,  1448,  1450,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   821,   590,   591,   592,   593,   939,   941,   968,
     970,   594,   971,   744,   973,   745,   982,   992,   988,   995,
    1033,  1024,   289,   460,   460,  1026,  1039,  1043,   383,   384,
     385,   386,   387,   388,   389,   390,   391,  1044,   287,  1052,
    1051,   392,   393,   394,   395,  1053,   289,  1064,  1065,   396,
     397,   398,  1080,  1070,  1107,  1082,   399,  1084,   400,  1087,
    1094,  1096,   289,   289,   289,  1099,  1108,  1109,  1100,  1111,
    1112,  1113,   401,  1115,  1116,   402,  1117,  1118,  1119,  1120,
    1121,  1122,  1123,  1001,  1124,  1003,  1004,  1005,  1006,  1007,
    1008,  1127,  1010,  1011,  1012,  1013,  1131,  1156,  1018,  1019,
    1020,  1157,  1165,   764,  1166,   764,   764,  1763,  1167,  1174,
    1751,  1177,  1183,  1189,  1753,  1193,  1192,  1205,   289,   764,
     452,  1197,  1206,  1207,  1213,  1215,  1238,  1260,  1226,  1234,
    1235,  1261,  1263,  1280,   289,   289,   289,  1277,   764,  1278,
    1279,  1291,  1292,  1293,  1304,   289,  1522,  1296,  1306,  1307,
     460,  1448,  1450,  1316,   460,  1313,  1320,   764,  1321,  1319,
    1325,  1327,  1322,   460,  1326,   460,  1331,  1340,   460,  1341,
    1346,  1361,  1088,  1367,  1347,  1368,  1369,  1603,  1370,  1608,
    1378,  1097,  1387,   289,  1375,   403,   404,   405,  1382,   508,
    1400,  1383,  1404,   764,  1416,  1432,   406,  -201,  1458,   374,
     407,  1440,   408,   117,  1459,  1460,  1463,  1464,  1465,  2055,
    1466,  1467,  1468,  1469,  1470,  1472,  1479,  1480,  1483,  1485,
     460,  1484,  1510,  1494,  1495,   289,  1496,   289,  1497,  1498,
    1499,  1500,  1501,  1502,  1506,  1507,  1508,  1509,   446,  1511,
    1512,  1513,   287,  1514,   289,  1519,  1527,  1532,  1533,  1539,
    1540,  1542,  1553,  1544,  1548,  1558,  1559,   289,  1561,  1564,
    1569,   289,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,  1550,   607,
    1772,  1772,   594,  1565,  1571,  1572,  1575,  1589,  1595,  1702,
    1573,  1596,  1587,  1612,   616,  1610,  1593,  1611,   621,  1617,
    1619,  1623,  1624,  1625,  1630,  1631,  1632,  1633,  1634,  1635,
    1636,  1911,  1637,  1638,  1639,   289,   289,   289,  1660,  1649,
    1666,  1670,  1676,   289,   289,   289,  1677,  1656,  1685,   446,
     446,  1699,  1746,  1683,  1684,  1691,  1692,  1693,  1694,  1700,
     289,  1706,  1707,  1759,  1714,  1708,  1709,  1710,  1711,  1715,
    1717,   289,  1721,  1722,  1723,  1727,  1728,  1729,  1733,   289,
    1736,  1311,  1743,   289,  1754,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,  1750,  1755,  1779,  1761,   594,  1781,  1523,
    1760,   764,  1774,  1801,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,  1782,
    1784,   731,   732,   594,  1786,  1790,  1812,  1791,   374,  1794,
    1802,  1793,  1797,  1808,   467,   467,  1809,   742,  1810,  1811,
     289,  1813,  1814,  1815,  1820,  1821,  1822,  1828,  1823,  1185,
    1837,   749,  1835,  1816,  1836,  1839,  1842,  1864,   460,  1843,
    1865,  1860,  1874,  1879,  1897,  1834,   446,  1907,   289,  1898,
     446,  1899,  1908,   289,  -567,  1910,  1915,  1927,  1373,   446,
    1928,   446,  1929,   779,   446,  1930,  1934,  1944,  1943,  1850,
    1945,  1914,  1938,  1543,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,  1946,  1947,  1948,
    1949,   594,  1961,  1962,  1867,  1868,  1869,  1870,  1871,  1873,
    1955,  1965,  1970,  1973,  1971,  1977,  1974,  1979,  1980,  1989,
    1991,  1996,  1997,  1888,  2003,   862,   446,  2004,  2005,  2006,
    1893,  1896,  2008,  2009,  2010,   289,   766,   607,  2011,   876,
     289,   289,  2013,  2014,  2019,  2037,  2061,  2058,  2063,  1905,
    2075,   452,   452,  2077,  2078,  2079,  2085,  2088,  2106,  1427,
    1428,  2109,  2113,   289,  2074,  2059,  2114,  2125,  2076,   289,
    1834,  -568,  2126,  2093,  2089,  2128,  2141,  2090,  2097,  2099,
     289,  2101,  2146,  2103,  2107,  2151,  2111,  2136,  2117,  2194,
     460,  2195,  2129,   460,  2165,  2182,  2196,  2197,  2199,  2200,
    2201,  2205,  2202,  2217,  2221,  2229,  2216,  2224,  2234,  2235,
    2238,   289,  2239,  1591,  2159,   788,  1652,  2028,  1344,  1807,
    2000,  1838,   374,  1621,   289,   467,   122,   133,   134,   135,
     928,  2053,  1745,   141,  1909,  1089,  1894,     0,     0,     0,
    1773,     0,  2127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     467,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
     289,     0,     0,  2150,   594,     0,  1529,     0,     0,     0,
    1531,  2001,   289,   289,     0,     0,     0,     0,     0,  1535,
       0,  1536,     0,     0,  1538,     0,     0,     0,     0,     0,
       0,     0,  1415,     0,     0,     0,     0,   289,     0,     0,
    1045,     0,     0,     0,     0,     0,     0,     0,     0,   289,
     446,   446,     0,     0,  2032,     0,     0,     0,     0,     0,
       0,     0,     0,   289,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   446,     0,  1578,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
     289,  2065,  2066,  2067,  2068,  2069,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   289,     0,     0,     0,     0,
    2033,     0,     0,   289,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   289,     0,     0,   289,     0,     0,     0,     0,
       0,   452,     0,     0,     0,     0,   289,     0,     0,     0,
     289,     0,     0,     0,     0,  2104,     0,     0,     0,  2108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,     0,     0,     0,  2135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,   446,
    2142,     0,     0,     0,  2144,     0,   289,     0,     0,     0,
    1212,     0,     0,     0,   764,     0,   764,     0,     0,     0,
    2156,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   446,     0,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,   165,   382,   594,     0,     0,   289,     0,
       0,     0,     0,     0,     0,     0,   446,  2191,  2192,     0,
       0,     0,     0,     0,     0,     0,   289,   289,   289,   289,
     289,     0,     0,     0,  1792,  1505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   383,   384,   385,   386,
     387,   388,   389,   390,   391,     0,     0,     0,     0,   392,
     393,   394,   395,     0,     0,     0,     0,   396,   397,   398,
     289,     0,     0,     0,   399,  1328,   400,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   289,     0,     0,
     401,  1348,     0,   402,  1547,     0,     0,   299,     0,     0,
     300,     0,     0,   301,     0,   302,     0,     0,     0,   460,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,  1560,     0,   289,     0,     0,     0,     0,     0,     0,
     460,   460,     0,   432,     0,     0,     0,     0,     0,     0,
       0,     0,  1398,  1399,   460,  1401,  1402,  1403,     0,  1405,
    1406,  1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1889,     0,     0,  1891,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,   175,     0,     0,     0,     0,  1426,
       0,     0,     0,   403,   404,   405,     0,     0,     0,     0,
       0,     0,     0,     0,   406,     0,     0,     0,   407,     0,
     408,   117,     0,  1441,     0,     0,     0,     0,     0,     0,
    1695,     0,     0,     0,     0,     0,     0,     0,     0,  1455,
       0,     0,     0,     0,     0,     0,   438,   439,     0,     0,
       0,     0,     0,  -563,  2092,  1577,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,   764,     0,     0,     0,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   445,
       0,  1516,  1517,  1518,     0,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
     764,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
    1549,     0,     0,   764,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   535,   536,   537,   538,   539,   540,     0,   542,   543,
       0,     0,     0,     0,     0,   446,     0,   548,   549,     0,
       0,  1607,     0,     0,     0,     0,     0,     0,     0,   557,
     558,     0,     0,     0,  1622,     0,   446,   446,  1626,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     446,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
    1752,     0,     0,   594,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,  1673,  1674,  1675,     0,   594,     0,     0,     0,
    1680,  1681,  1682,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1697,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1705,     0,
       0,     0,     0,     0,     0,     0,  1713,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   689,
     690,   691,     0,     0,     0,   695,   696,   697,   698,   699,
     700,   701,     0,   702,     0,     0,     0,   703,   704,     0,
       0,   707,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   719,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,   165,     0,     0,
       0,   872,     0,   208,   209,   210,     0,  1778,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   418,   229,   230,   231,   232,
     233,   234,     0,     0,     0,  1800,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2214,  1756,     0,     0,   240,
     241,   242,   243,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,  2230,  2232,     0,     0,
       0,   248,   249,   250,     0,     0,     0,     0,     0,     0,
    2240,     0,   251,    25,     0,   252,     0,     0,     0,     0,
     420,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,  1841,   594,     0,     0,     0,   447,     0,     0,
       0,   457,     0,     0,     0,     0,   463,     0,     0,     0,
       0,     0,     0,     0,   468,     0,     0,   887,     0,     0,
    1778,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,   481,   482,  1762,   484,   485,   486,  1880,   488,   489,
     490,   491,   492,   493,   494,     0,   496,   497,   498,   499,
       0,     0,     0,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1904,     0,
       0,     0,     0,     0,     0,     0,   262,     0,     0,     0,
     263,  1913,     0,     0,     0,   265,   266,   267,     0,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1461,     0,     0,     0,     0,
       0,   271,   419,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   363,     0,   562,   564,   566,   567,   503,
     276,     0,     0,     0,     0,     0,     0,  1778,     0,     0,
       0,     0,     0,     0,   601,   503,   503,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,   619,     0,     0,   594,
       0,     0,     0,     0,  1978,     0,   629,   630,     0,     0,
       0,     0,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,   652,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,   674,   503,     0,
       0,     0,   678,   679,   680,     0,   682,     0,     0,     0,
     685,   686,   687,     0,     0,   688,     0,  2020,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2029,     0,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,   720,     0,     0,   594,   503,   729,  1778,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2060,   737,   738,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   765,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1186,   794,
     795,   796,   797,  1778,     0,     0,     0,   802,     0,     0,
       0,   806,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   820,   564,     0,     0,     0,
     824,     0,  1203,  2105,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,   842,   843,
     844,   846,   847,   848,   849,   850,   851,   852,   852,     0,
     857,   858,     0,   860,     0,     0,     0,     0,     0,     0,
       0,     0,   869,     0,     0,   873,   874,     0,     0,     0,
       0,     0,   852,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   890,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   902,   903,   905,   907,   908,   909,   910,   911,     0,
     913,   914,     0,     0,     0,     0,     0,     0,   922,   923,
     924,  1877,     0,     0,     0,     0,   930,   931,   932,   933,
       0,   503,   503,     0,     0,     0,     0,  1778,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     562,   720,   952,     0,     0,     0,   957,   958,   959,   960,
     961,   962,   963,   964,   965,  1878,     0,     0,     0,     0,
     972,     0,   974,     0,     0,   976,     0,     0,     0,   503,
     503,   503,   981,     0,   503,   984,   985,   986,     0,     0,
    1778,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1009,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   503,     0,     0,     0,
       0,     0,     0,  1028,     0,  1029,     0,     0,   913,   914,
       0,     0,     0,     0,     0,     0,   504,  1042,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,  1058,     0,     0,     0,     0,  1061,  1062,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,     0,  1078,  1079,     0,     0,   503,     0,
     503,  1086,     0,     0,     0,  1078,  1442,  1093,     0,     0,
       0,     0,     0,  1098,     0,     0,     0,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,   504,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1125,     0,   905,     0,  1128,   504,   504,
       0,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,   505,     0,   594,     0,  1969,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,  1170,  1171,     0,     0,   504,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,   504,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,  1211,
       0,     0,     0,  1217,     0,     0,     0,     0,     0,     0,
       0,   503,  1567,  1568,   602,   603,     0,     0,     0,  1232,
    1233,     0,     0,     0,     0,  1236,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1262,     0,     0,  1264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,     0,     0,     0,  1995,  1281,     0,  1283,
    1284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2007,
       0,     0,     0,  1657,     0,     0,     0,     0,     0,   565,
       0,  1324,     0,  1665,     0,     0,     0,     0,  1330,     0,
       0,     0,     0,  1339,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   845,     0,     0,     0,     0,  1365,  1366,
     853,   854,     0,     0,   503,     0,   728,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,   879,     0,     0,     0,   594,
     504,     0,     0,     0,     0,     0,  1392,  1393,  1394,  1395,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   906,     0,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1418,     0,     0,
       0,     0,     0,     0,   504,   504,     0,  1419,  1420,  1421,
       0,     0,     0,     0,  1423,  1424,     0,  1425,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1434,  1435,     0,     0,     0,     0,     0,     0,  1438,
    1439,     0,     0,     0,     0,     0,  1443,     0,  1444,  1445,
       0,  1803,   504,   504,   504,  1451,  1452,   504,     0,     0,
     503,   503,     0,     0,     0,     0,   883,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,     0,  1482,     0,     0,     0,     0,   504,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
     935,   936,   594,     0,     0,     0,     0,     0,     0,     0,
    1515,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
    1530,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,   504,     0,   504,     0,     0,     0,     0,   978,   979,
     980,  1451,  1452,   983,     0,     0,  1546,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1552,     0,     0,
    1557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   906,     0,
    1129,     0,     0,     0,     0,  1023,     0,     0,  1579,     0,
       0,  1582,   503,  1585,   503,     0,     0,     0,     0,     0,
       0,     0,  1594,     0,     0,  1597,     0,  1594,  1600,  1602,
    2044,     0,     0,   504,     0,     0,     0,     0,     0,  1054,
       0,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,     0,     0,     0,     0,     0,  1083,     0,  1085,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   504,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1679,
       0,     0,     0,     0,   504,     0,     0,     0,  1688,  1689,
    1690,     0,     0,     0,     0,     0,     0,  1696,     0,  1698,
       0,     0,     0,     0,   412,   382,  1701,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1159,
     503,     0,     0,     0,     0,  1718,  1719,     0,     0,  1169,
       0,     0,     0,     0,  1724,  1725,  1726,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1737,   383,   384,   385,
     386,   387,   388,   389,   390,   391,  1749,     0,     0,     0,
     392,   393,   394,   395,     0,     0,     0,  1196,   396,   397,
     398,     0,     0,     0,     0,   399,     0,   400,     0,  1766,
    1204,     0,     0,     0,     0,  1775,  1776,     0,     0,     0,
       0,   401,     0,  2045,   402,     0,     0,     0,     0,     0,
    1225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
    1805,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1824,  1825,  1826,     0,     0,     0,     0,     0,     0,     0,
       0,  1827,     0,     0,   504,     0,  1830,  1831,  1832,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1840,     0,     0,     0,     0,     0,     0,   503,   503,  1848,
       0,  1849,     0,     0,   403,   404,   405,  1857,  1858,     0,
       0,     0,     0,     0,     0,   406,     0,     0,     0,   407,
       0,   408,     0,     0,     0,     0,   503,     0,     0,     0,
       0,  1876,     0,  1372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1887,     0,     0,  1890,     0,
       0,     0,  1892,   504,   504,     0,     0,     0,     0,     0,
       0,  1831,  1832,     0,  1901,     0,     0,     0,     0,     0,
       0,     0,  1906,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2124,     0,     0,  1919,     0,
    1417,     0,     0,  1925,  1926,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1931,     0,     0,
    1932,  1931,     0,  1935,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,   504,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   503,
     503,  2172,     0,     0,     0,     0,  1963,  1964,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1972,  1456,
    1457,     0,     0,     0,     0,     0,     0,  1981,     0,   747,
       0,     0,     0,     0,     0,     0,   564,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1992,  1993,     0,     0,
     503,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2017,  2018,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1528,     0,     0,     0,  2031,     0,     0,     0,     0,
     503,   503,  2036,     0,     0,     0,     0,  2039,     0,     0,
    2041,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   503,   870,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,     0,     0,     0,     0,  2070,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
    2081,  1584,     0,  1586,   918,     0,  2086,     0,     0,  2087,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,  2112,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,  2130,  2131,     0,     0,
       0,     0,  1942,   575,     0,     0,     0,     0,     0,     0,
       0,  2137,  2138,     0,  2139,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2148,     0,
       0,     0,     0,   503,   503,   503,   503,   503,     0,     0,
       0,     0,     0,  1925,     0,     0,     0,  2164,     0,     0,
       0,     0,     0,  1806,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,     0,  1716,
      43,    44,    45,    46,     0,  2185,    48,     0,     0,     0,
    2188,  2189,  2190,   758,    55,     0,     0,    58,   759,     0,
     760,   761,     0,   762,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2218,  2219,  2220,     0,     0,     0,     0,     0,
     504,   504,     0,     0,     0,     0,    94,    95,    96,   575,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,     0,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,
    1140,  1141,  1142,     0,  1144,  1145,  1146,  1147,     0,  1149,
    1150,  1151,  1152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1162,     0,  1164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1173,     0,     0,     0,     0,
       0,   953,  1179,  1180,     0,     0,     0,     0,     0,     0,
       0,  1191,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   821,   590,   591,   592,   593,
       0,   207,   165,   382,   594,     0,  1846,  1847,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     418,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,   504,   504,     0,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   240,   241,   242,   243,   392,   393,
     394,   395,   244,     0,     0,     0,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   400,   248,   249,   250,   565,
       0,     0,     0,     0,     0,     0,     0,   251,    25,   401,
     252,     0,   402,   504,  1287,  1289,  1290,     0,     0,     0,
    1294,  1295,     0,     0,  1298,  1299,  1300,  1301,     0,  1303,
       0,     0,     0,     0,  1309,     0,     0,     0,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,   504,     0,     0,     0,  1959,  1960,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,  1391,     0,     0,     0,     0,
    1396,   262,   403,   404,   405,   263,     0,     0,     0,  1994,
     265,   266,   267,   406,   268,   269,   270,   407,     0,   408,
     117,     0,     0,     0,     0,     0,     0,     0,   575,     0,
       0,     0,     0,     0,     0,     0,   271,   419,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,     0,
       0,     0,  1601,     0,     0,   276,     0,     0,     0,     0,
       0,     0,     0,   996,     0,     0,     0,     0,     0,  2034,
    2035,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,  2054,     0,     0,   594,     0,   744,  1453,   745,     0,
       0,     0,     0,     0,  1734,     0,  2064,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,   504,   504,   504,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     207,   165,     0,     0,     0,     0,     0,   208,   209,   210,
       0,     0,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   418,
     229,   230,   231,   232,   233,   234,  1194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,     0,   240,   241,   242,   243,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1195,     0,     0,   248,   249,   250,     0,     0,
       0,     0,     0,     0,  2140,     0,   251,    25,     0,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1566,
       0,     0,  2152,  2153,  2154,  2155,  2157,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     821,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1604,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,  2198,   594,     0,     0,     0,     0,     0,
       0,     0,  1641,  1642,  1643,  1644,  1645,     0,     0,     0,
       0,  1650,  1651,     0,     0,     0,     0,  1653,     0,  1655,
       0,     0,     0,  1659,     0,     0,  1661,     0,     0,     0,
     262,     0,     0,     0,   263,     0,     0,     0,  1669,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   419,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   363,     0,     0,
       0,   618,     0,     0,   276,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,  1521,     0,     0,     0,   594,     0,     0,
       0,     0,  1732,     0,  1735,     0,     0,     0,  1742,     0,
    1744,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,     0,
       0,  1769,     0,     0,     0,     0,     0,     0,     0,   207,
       6,   382,     0,     0,     0,     0,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,  1605,   384,   385,   386,   387,   388,   389,
     390,   391,   240,   241,   242,   243,   392,   393,   394,   395,
     244,   245,     0,     0,   396,   397,   398,     0,     0,   246,
     247,   399,     0,   400,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,   401,   252,  1833,
     402,     0,     0,     0,   253,     0,     0,   254,     0,     0,
     255,     0,   256,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,    56,    57,     0,   259,     0,
     260,     0,     0,   261,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,     0,     0,
       0,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1916,     0,     0,  1917,     0,   262,
     403,   404,   405,   263,   264,     0,     0,     0,   265,   266,
     267,   406,   268,   269,   270,   407,     0,   408,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   272,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,     0,  1951,  1952,
    1606,  1954,     0,   276,     0,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,   207,     6,   382,     0,   594,     0,     0,
     208,   209,   210,   818,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,  1998,  1999,     0,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   240,   241,   242,   243,
     392,   393,   394,   395,   244,   245,     0,     0,   396,   397,
     398,     0,     0,   246,   247,   399,     0,   400,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,   401,   252,  2030,   402,     0,     0,     0,   253,     0,
       0,   254,     0,     0,   255,     0,   256,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,    56,
      57,     0,   259,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,   987,     0,     0,     0,
       0,     0,     0,     0,   945,     0,     0,     0,     0,     0,
       0,     0,     0,   262,   403,   404,   405,   263,   264,     0,
       0,     0,   265,   266,   267,   406,   268,   269,   270,   407,
       0,   408,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     363,   207,   165,   382,   275,   431,     0,   276,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     418,   229,   230,   231,   232,   233,   234,     0,     0,     0,
       0,     0,     0,     0,     0,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   240,   241,   242,   243,   392,   393,
     394,   395,   244,     0,     0,     0,   396,   397,   398,     0,
       0,     0,     0,   399,     0,   400,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,   401,
     252,     0,   402,  2207,     0,     0,   299,     0,     0,   300,
     382,     0,   301,     0,   302,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   432,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   383,   384,   385,   386,   387,   388,   389,   390,
     391,     0,     0,     0,     0,   392,   393,   394,   395,     0,
       0,     0,     0,   396,   397,   398,     0,     0,     0,     0,
     399,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,     0,   402,
       0,     0,     0,     0,   433,     0,     0,     0,     0,     0,
       0,   262,   403,   404,   405,   263,     0,     0,     0,     0,
     265,   266,   267,   406,   268,   269,   270,   407,     0,   408,
     117,   434,   435,   436,   437,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   419,     0,     0,
       0,     0,     0,   273,     0,   438,   439,     0,   440,     0,
     441,   207,     6,   362,   442,   276,     0,     0,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,   403,
     404,   405,     0,     0,   240,   241,   242,   243,     0,     0,
     406,     0,   244,   245,   407,     0,   408,     0,     0,     0,
       0,   246,   247,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,     0,
     252,     0,     0,     0,     0,     0,   253,     0,     0,   254,
       0,     0,   255,     0,   256,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,     0,    56,    57,     0,
     259,     0,   260,     0,     0,   261,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,  1798,     0,
       0,     0,  1799,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   272,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,   207,
       6,     0,   364,     0,   675,   276,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,   245,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,     0,
       0,     0,     0,     0,   253,     0,     0,   254,     0,     0,
     255,     0,   256,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,    56,    57,     0,   259,     0,
     260,     0,     0,   261,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,  1853,     0,     0,     0,
    1854,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   263,   264,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   502,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,   207,     6,  1704,
       0,   568,     0,   276,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,   245,
       0,     0,     0,     0,     0,     0,     0,   246,   247,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,     0,   252,     0,     0,     0,
       0,     0,   253,     0,     0,   254,     0,     0,   255,     0,
     256,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,    56,    57,     0,   259,     0,   260,     0,
       0,   261,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,  1881,     0,     0,     0,  1882,     0,
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
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,   254,     0,     0,   255,     0,   256,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,    56,    57,     0,   259,     0,   260,     0,     0,   261,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,  2056,     0,     0,     0,  2057,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     636,  1872,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   638,   207,     6,     0,   323,   568,     0,   276,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,     0,   252,     0,     0,     0,     0,     0,   253,     0,
       0,   254,     0,     0,   255,     0,   256,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,    56,
      57,     0,   259,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   777,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   263,   264,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     274,   207,     6,     0,   275,     0,     0,   276,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,   243,     0,     0,
       0,     0,   244,   245,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,     0,
     252,     0,     0,     0,     0,     0,   253,     0,     0,   254,
       0,     0,   255,     0,   256,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,     0,    56,    57,     0,
     259,     0,   260,     0,     0,   261,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   783,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   272,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,   207,
       6,     0,   275,     0,     0,   276,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,   245,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,     0,
       0,     0,     0,     0,   253,     0,     0,   254,     0,     0,
     255,     0,   256,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,    56,    57,     0,   259,     0,
     260,     0,     0,   261,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     945,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   263,   264,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   502,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,   363,   207,     6,     0,
     563,     0,     0,   276,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,   245,
       0,     0,     0,     0,     0,     0,     0,   246,   247,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,     0,   252,     0,     0,     0,
       0,     0,   253,     0,     0,   254,     0,     0,   255,     0,
     256,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,    56,    57,     0,   259,     0,   260,     0,
       0,   261,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   946,     0,
       0,     0,     0,     0,     0,     0,     0,   262,     0,     0,
       0,   263,   264,     0,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   502,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   363,   207,     6,     0,     0,   568,
       0,   276,   208,   209,   210,     0,     0,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,   243,     0,     0,     0,     0,   244,   245,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,   254,     0,     0,   255,     0,   256,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,    56,    57,     0,   259,     0,   260,     0,     0,   261,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   993,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   272,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   606,   207,     6,     0,   275,     0,     0,   276,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,     0,   252,     0,     0,     0,     0,     0,   253,     0,
       0,   254,     0,     0,   255,     0,   256,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,    56,
      57,     0,   259,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   263,   264,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     615,   207,     6,     0,   275,     0,     0,   276,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,   243,     0,     0,
       0,     0,   244,   245,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,     0,
     252,     0,     0,     0,     0,     0,   253,     0,     0,   254,
       0,     0,   255,     0,   256,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,     0,    56,    57,     0,
     259,     0,   260,     0,     0,   261,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   502,     0,     0,
       0,     0,     0,   273,     0,     0,     0,     0,   363,   207,
       6,     0,   904,     0,  1371,   276,   208,   209,   210,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,   241,   242,   243,     0,     0,     0,     0,
     244,   245,     0,     0,     0,     0,     0,     0,     0,   246,
     247,     0,     0,     0,   248,   249,   250,     0,     0,     0,
       0,     0,     0,     0,     0,   251,    25,     0,   252,     0,
       0,     0,     0,     0,   253,     0,     0,   254,     0,     0,
     255,     0,   256,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,    56,    57,     0,   259,     0,
     260,     0,     0,   261,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,     0,     0,     0,   262,
       0,     0,     0,   263,   264,     0,     0,     0,   265,   266,
     267,     0,   268,   269,   270,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   271,   502,     0,     0,     0,     0,
       0,   273,   207,     6,     0,     0,   363,  1583,     0,   208,
     209,   210,     0,   276,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,   243,     0,
       0,     0,     0,   244,   245,     0,     0,     0,     0,     0,
       0,     0,   246,   247,     0,     0,     0,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   251,    25,
       0,   252,     0,     0,     0,     0,     0,   253,     0,     0,
     254,     0,     0,   255,     0,   256,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,     0,    56,    57,
       0,   259,     0,   260,     0,     0,   261,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,     0,     0,     0,     0,
       0,     0,   262,     0,     0,     0,   263,   264,     0,     0,
       0,   265,   266,   267,     0,   268,   269,   270,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   502,     0,
       0,     0,     0,     0,   273,   207,     6,     0,     0,   363,
       0,     0,   208,   209,   210,     0,   276,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,   243,     0,     0,     0,     0,   244,   245,     0,     0,
       0,     0,     0,     0,     0,   246,   247,     0,     0,     0,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   251,    25,     0,   252,     0,     0,     0,     0,     0,
     253,     0,     0,   254,     0,     0,   255,     0,   256,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
       0,    56,    57,     0,   259,     0,   260,     0,     0,   261,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1143,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,     0,     0,   263,
     264,     0,     0,     0,   265,   266,   267,     0,   268,   269,
     270,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     271,   272,     0,     0,     0,     0,     0,   273,     0,     0,
       0,     0,   363,   207,     6,     0,  1712,     0,     0,   276,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,   245,     0,     0,     0,     0,
       0,     0,     0,   246,   247,     0,     0,     0,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,     0,   252,     0,     0,     0,     0,     0,   253,     0,
       0,   254,     0,     0,   255,     0,   256,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,    56,
      57,     0,   259,     0,   260,     0,     0,   261,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1153,     0,     0,     0,     0,     0,
       0,     0,     0,   262,     0,     0,     0,   263,   264,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,  1872,
       0,     0,     0,     0,     0,   273,     0,     0,     0,     0,
     638,   207,     6,     0,   323,     0,     0,   276,   208,   209,
     210,     0,     0,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,   243,     0,     0,
       0,     0,   244,   245,     0,     0,     0,     0,     0,     0,
       0,   246,   247,     0,     0,     0,   248,   249,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   251,    25,     0,
     252,     0,     0,     0,     0,     0,   253,     0,     0,   254,
       0,     0,   255,     0,   256,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,     0,    56,    57,     0,
     259,     0,   260,     0,     0,   261,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1154,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,   263,   264,     0,     0,     0,
     265,   266,   267,     0,   268,   269,   270,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,   502,     0,     0,
       0,     0,     0,   273,   207,   165,   382,     0,   363,     0,
       0,   208,   209,   210,     0,   276,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   418,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   240,   241,   242,
     243,   392,   393,   394,   395,   244,     0,     0,     0,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   400,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,   401,   252,     0,   402,   207,   165,   382,     0,
       0,     0,     0,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   418,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
    1605,   384,   385,   386,   387,   388,   389,   390,   391,   240,
     241,   242,   243,   392,   393,   394,   395,   244,     0,     0,
       0,   396,   397,   398,     0,     0,     0,     0,   399,     0,
     400,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,   401,   252,     0,   402,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   403,   404,   405,   263,     0,
       0,     0,     0,   265,   266,   267,   406,   268,   269,   270,
     407,     0,   408,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     419,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,     0,     0,     0,  1886,     0,     0,   276,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1155,     0,     0,     0,     0,   262,   403,   404,   405,
     263,     0,     0,     0,     0,   265,   266,   267,   406,   268,
     269,   270,   407,     0,   408,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   419,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   363,   207,   165,   382,  1768,     0,     0,
     276,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   418,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   240,   241,   242,
     243,   392,   393,   394,   395,   244,     0,     0,     0,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   400,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,   401,   252,     0,   402,   207,   165,     0,     0,
       0,     0,     0,   208,   209,   210,     0,     0,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   418,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,   243,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,     0,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   262,   403,   404,   405,   263,     0,
       0,     0,     0,   265,   266,   267,   406,   268,   269,   270,
     407,     0,   408,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     419,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,     0,     0,     0,     0,     0,     0,   276,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1160,     0,     0,     0,     0,   262,     0,     0,     0,
     263,     0,     0,     0,     0,   265,   266,   267,     0,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   636,   637,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   638,   207,   165,     0,   323,     0,     0,
     276,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   418,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
     243,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,     0,   252,   207,   165,     0,  1323,     0,     0,
       0,   208,   209,   210,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   418,   229,   230,   231,   232,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
     243,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,     0,
     251,    25,     0,   252,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,   262,     0,   594,     0,   263,     0,
       0,     0,     0,   265,   266,   267,  1161,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     419,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   363,  1091,     0,     0,     0,     0,     0,   276,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1163,     0,     0,   262,     0,     0,     0,   263,     0,
       0,     0,     0,   265,   266,   267,     0,   268,   269,   270,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
     419,     0,     0,     0,     0,     0,   273,   207,   165,     0,
    1481,   363,     0,     0,   208,   209,   210,     0,   276,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   418,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,     0,   252,   207,   165,     0,
    1545,     0,     0,     0,   208,   209,   210,     0,     0,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   418,   229,   230,   231,
     232,   233,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,   243,     0,     0,     0,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,   249,   250,     0,     0,     0,     0,     0,
       0,     0,     0,   251,    25,     0,   252,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,   262,     0,   594,
       0,   263,     0,     0,     0,     0,   265,   266,   267,  1276,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   419,     0,     0,     0,     0,     0,   273,
       0,     0,     0,     0,   363,     0,     0,     0,     0,     0,
       0,   276,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1297,     0,     0,   262,     0,     0,
       0,   263,     0,     0,     0,     0,   265,   266,   267,     0,
     268,   269,   270,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   271,   419,     0,     0,     0,     0,     0,   273,
     207,   165,     0,     0,   363,     0,     0,   208,   209,   210,
       0,   276,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   418,
     229,   230,   231,   232,   233,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,   243,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   249,   250,     0,     0,
       0,     0,     0,   207,   165,     0,   251,    25,     0,   252,
     208,   209,   210,     0,     0,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   418,   229,   230,   231,   232,   233,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,   243,
       0,     0,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,   249,
     250,     0,     0,     0,     0,     0,     0,     0,     0,   251,
      25,     0,   252,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,     0,
     262,     0,     0,     0,   263,  1381,     0,     0,     0,   265,
     266,   267,     0,   268,   269,   270,     0,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   271,   419,     0,     0,     0,
       0,     0,   273,     0,     0,     0,     0,   363,  1599,     0,
       0,     0,     0,     0,   276,     0,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,   262,     0,     0,     0,   263,  1384,     0,
       0,     0,   265,   266,   267,     0,   268,   269,   270,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,   419,
       0,     0,     0,     0,     0,   273,   207,   165,     0,     0,
     363,  1933,     0,   208,   209,   210,     0,   276,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   418,   229,   230,   231,   232,
     233,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   382,     0,     0,     0,   240,
     241,   242,   243,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,     0,   251,    25,     0,   252,     0,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     0,     0,     0,     0,
     392,   393,   394,   395,     0,     0,     0,     0,   396,   397,
     398,     0,     0,     0,     0,   399,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,   402,     0,     0,     0,   299,     0,
       0,   300,     0,     0,   301,     0,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,     0,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,   262,     0,   594,     0,
     263,     0,     0,     0,     0,   265,   266,   267,  1475,   268,
     269,   270,     0,     0,     0,   117,     0,     0,     0,     0,
       0,     0,     0,     0,   165,   382,     0,     0,     0,     0,
       0,   271,   419,     0,     0,     0,     0,     0,   273,     0,
       0,     0,     0,   363,   403,   404,   405,     0,     0,     0,
     276,     0,     0,     0,     0,   406,     0,     0,     0,   407,
       0,   408,   117,     0,     0,     0,     0,   383,   384,   385,
     386,   387,   388,   389,   390,   391,     7,     8,     0,     0,
     392,   393,   394,   395,     0,     0,     0,     0,   396,   397,
     398,   744,     0,   745,  1768,   399,     0,   400,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,   402,     0,     0,     0,   299,     0,
       0,   300,     0,     0,   301,     0,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     7,     8,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     758,    55,     0,     0,    58,   759,     0,   760,   761,     0,
     762,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,   403,   404,   405,     0,     0,     0,
       0,     0,     0,     0,     0,   406,     0,     0,     0,   407,
       0,   408,   117,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     7,     8,  1768,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   758,    55,
       0,     0,    58,   759,     0,   760,   761,     0,   762,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,   977,     0,
       0,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,    94,    95,    96,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1476,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       7,     8,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   758,    55,     0,     0,
      58,   759,     0,   760,   761,     0,   762,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,  1025,     0,     0,     0,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,    94,
      95,    96,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1520,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     7,     8,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   758,    55,     0,     0,    58,   759,
       0,   760,   761,     0,   762,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,  1027,     0,     0,     0,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,    94,    95,    96,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1646,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     7,     8,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,   758,    55,     0,     0,    58,   759,     0,   760,
     761,     0,   762,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,  1227,     0,     0,     0,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,    94,    95,    96,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1647,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     7,     8,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     758,    55,     0,     0,    58,   759,     0,   760,   761,     0,
     762,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
    1229,     0,     0,     0,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,    94,    95,    96,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1648,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     7,     8,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   758,    55,
       0,     0,    58,   759,     0,   760,   761,     0,   762,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,  1230,     0,
       0,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,    94,    95,    96,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1662,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       7,     8,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   758,    55,     0,     0,
      58,   759,     0,   760,   761,     0,   762,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,  1249,     0,     0,     0,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,    94,
      95,    96,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1796,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     7,     8,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   758,    55,     0,     0,    58,   759,
       0,   760,   761,     0,   762,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,  1267,     0,     0,     0,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,    94,    95,    96,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1920,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     7,     8,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,   758,    55,     0,     0,    58,   759,     0,   760,
     761,     0,   762,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,  1282,     0,     0,     0,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,    94,    95,    96,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1921,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     7,     8,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     758,    55,     0,     0,    58,   759,     0,   760,   761,     0,
     762,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
    1315,     0,     0,     0,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,    94,    95,    96,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1953,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     7,     8,     0,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   758,    55,
       0,     0,    58,   759,     0,   760,   761,     0,   762,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,  1473,     0,
       0,     0,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,    94,    95,    96,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1956,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
       0,     0,     0,     0,     0,     0,   758,    55,     0,     0,
      58,   759,     0,   760,   761,     0,   762,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,  2115,     0,     0,     0,
      -4,     1,     0,     0,    -4,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,     0,     0,     0,     0,    94,
      95,    96,     0,     0,     0,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,    -4,    -4,    -4,   594,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2025,     0,     0,
       0,     0,     0,     0,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,    -4,     0,     0,     0,    -4,     0,     0,     0,
       0,    -4,    -4,    -4,    -4,    -4,     0,    -4,    -4,     0,
      -4,     0,     0,     0,  2174,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,     0,
      -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     0,    -4,
      -4,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     6,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,     7,     8,     0,     0,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,     9,    10,    11,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,     0,     0,     0,    12,    13,    14,
       0,     0,     0,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,    18,    19,    20,    21,    22,     0,    23,
      24,     0,    25,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,    42,    43,    44,    45,    46,
      47,     0,    48,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      89,    90,    91,     0,     0,     0,    92,     0,     0,     0,
       0,    93,    94,    95,    96,   165,   382,    97,     0,    98,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,   113,   114,   115,     0,     7,     8,     0,     0,     0,
       0,     0,   116,     0,   117,     0,     0,     0,   383,   384,
     385,   386,   387,   388,   389,   390,   391,     0,     0,     0,
       0,   392,   393,   394,   395,     0,     0,     0,     0,   396,
     397,   398,     0,     0,     0,     0,   399,     0,   400,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   401,     0,     0,   402,     0,     0,     0,   299,
       0,     0,   300,     0,     0,   301,     0,   302,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,   432,    43,    44,    45,    46,
       7,     8,    48,     0,     0,     0,     0,     0,     0,   758,
      55,     0,     0,    58,   759,     0,   760,   761,     0,   762,
       0,     0,     0,  1036,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
       0,  1037,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,   403,   404,   405,     0,     0,
       0,     0,     0,     0,     0,     0,   406,     0,     0,     0,
     407,     0,   408,   117,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   758,    55,     0,     0,    58,   759,
       0,   760,   761,     0,   762,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,    94,    95,    96,
       0,     0,     0,     0,     0,  2082,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2083,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2098,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2100,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2133,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2161,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2166,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2167,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2168,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2208,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,  1071,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
    1130,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,  1175,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,  1176,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,  1220,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,  1252,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,  1272,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,  1329,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
       0,     0,     0,  1349,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,  1430,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,  1431,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
    1477,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,  1551,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,  1851,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,  1862,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,  1900,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,  1975,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,  1990,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
       0,     0,     0,  2002,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,  2026,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,     0,
       0,  2062,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,     0,     0,
    2071,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,     0,  2072,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,     0,     0,  2096,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,     0,  2147,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,  2187,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,     0,     0,  2206,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,     0,     0,  2226,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
       0,     0,     0,  2227,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
       0,     0,  2228,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,     0,
     722,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,     0,   937,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,     0,  1968,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,   744,     0,   745,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
     999,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,  1047,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,  1199,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
       0,  1266,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,  1268,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,     0,     0,  1274,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   721,
     590,   591,   592,   593,     0,     0,     0,     0,   594,     0,
       0,     0,  1275,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   721,   590,   591,   592,
     593,     0,     0,     0,     0,   594,     0,     0,     0,  1363,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   721,   590,   591,   592,   593,     0,     0,
       0,     0,   594,     0,     0,     0,  1377,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     721,   590,   591,   592,   593,     0,     0,     0,     0,   594,
       0,     0,     0,  1580,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,     0,     0,
    1668,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   721,   590,   591,   592,   593,     0,
       0,     0,     0,   594,     0,     0,     0,  1720,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   721,   590,   591,   592,   593,     0,     0,     0,     0,
     594,     0,     0,     0,  1912,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   721,   590,
     591,   592,   593,     0,     0,     0,     0,   594,     0,     0,
       0,  1958,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   721,   590,   591,   592,   593,
       0,     0,     0,     0,   594,     0,     0,     0,  1976,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   799,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   800,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   801,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   803,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   804,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   805,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   807,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   808,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   809,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   810,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   811,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   812,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   813,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   815,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   816,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   817,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   884,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   919,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   967,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   987,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   989,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   990,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   991,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,   997,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,   998,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1035,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1046,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1110,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1114,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1126,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1198,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1208,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1209,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1210,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1219,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1221,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1222,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1251,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1253,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1254,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1255,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1256,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1257,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1258,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1259,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1265,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1362,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1376,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1581,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1613,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1614,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1615,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1616,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1654,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1667,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1783,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1785,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1788,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1795,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1852,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1861,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  1885,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  1957,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  2023,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  2024,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594,     0,  2160,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   721,   590,   591,   592,   593,     0,     0,     0,
       0,   594,     0,  2203,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   721,   590,   591,
     592,   593,     0,     0,     0,     0,   594
};

static const yytype_int16 yycheck[] =
{
       3,  1246,   316,     3,  1250,    68,    69,   739,    71,   726,
     157,   633,   634,    62,     4,   747,  1437,   196,  1751,  1706,
    1753,     4,    25,     7,     4,   204,     4,     4,  1936,     4,
       6,    25,     5,     4,   328,     4,     4,     7,   755,     6,
     108,     5,   110,     6,     4,     4,   138,     5,     5,     4,
       6,    54,     6,   347,     6,   772,     4,     4,     9,  1738,
     104,     4,     4,     6,   138,   782,   238,   239,   101,     9,
     254,   104,   143,     4,   258,   143,    98,     9,     9,   253,
      83,   104,   156,   127,   117,   259,   250,   259,   252,    92,
     159,   165,   166,   167,    97,   117,   188,   171,   172,     6,
     256,     6,   170,   259,   127,   108,   101,    90,     6,   104,
     105,   106,     9,   238,   239,     6,   185,   296,   297,   298,
     251,   415,   117,   417,  1803,   238,   239,     7,   259,     0,
       6,   425,   201,   202,   259,   251,  1823,   238,   239,     9,
     143,    14,   255,   259,   144,   148,   149,   150,   250,     9,
     238,   239,   254,     7,   157,    98,   238,   239,   259,   107,
     108,   340,   341,   342,   253,   238,   239,   251,   104,   886,
     259,   259,   175,   238,   239,   259,    98,   259,   357,   101,
       8,   255,   104,  2091,   106,   180,   259,   251,   191,   250,
     238,   239,   256,   196,   259,   117,   199,   246,   247,   238,
     239,   204,   205,   206,   175,   176,   177,   178,   238,   239,
     173,   259,   250,   196,     7,   255,   254,   173,     7,   259,
     259,   238,   239,   238,   239,     7,   185,   186,     6,   259,
     185,   186,   222,   251,   238,   239,   238,   239,  1659,   222,
     200,   259,   259,   250,   259,   222,   250,   222,  1493,   250,
     254,   252,   254,   222,   222,   258,   319,   320,   259,   238,
     239,   250,   238,   239,   327,   328,   250,   257,   252,   272,
     250,   254,   275,   276,   252,   254,   254,   254,  1965,   254,
     258,   254,   276,   251,   255,   253,   256,   254,   291,   292,
     254,   222,   295,   296,   297,   298,   254,   254,   250,   250,
     254,   252,   254,   250,   250,   256,     3,   310,   250,   254,
     250,   314,   252,   316,  1046,  1047,   247,   248,   250,   250,
     252,   252,     6,   254,   256,   256,   233,   234,   622,     6,
     624,   625,  2019,   238,   239,   338,     6,   340,   341,   342,
     238,   239,     6,   223,   224,   225,   226,   641,     4,   101,
     247,   248,   104,   250,   357,   252,   253,   233,   234,   256,
       7,   364,   255,   431,    61,   659,   259,   247,   248,   223,
     224,   225,   226,   251,     4,   554,   256,   247,   248,     6,
     250,   259,   252,   251,   247,   248,   256,   247,   248,   683,
     250,   259,   252,   256,  2127,     6,   256,   544,     6,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   238,   239,   422,
     423,   249,   247,   248,   427,   428,   252,   255,   722,   254,
     223,   224,   225,   226,   223,   224,   225,   226,   259,   252,
     443,   223,   224,   225,   226,   250,   143,   450,   238,   239,
     250,   148,   149,   150,   247,   248,   247,   248,   247,   248,
     157,   101,   238,   239,   104,  1182,   106,  1184,    98,   259,
     473,   104,   102,   106,   238,   239,  2163,   117,   108,   109,
    1197,   111,   112,   259,   250,   138,   252,   143,   144,   145,
     146,   250,   560,   149,   191,   259,   238,   239,   254,   502,
     251,   131,   158,   156,   250,   161,   238,   239,   259,   206,
     238,   239,   165,   166,   167,   238,   239,   259,   171,   172,
     251,   238,   239,   526,   238,   239,   254,   259,   259,  2216,
     533,   534,   256,  1954,   258,   538,   259,   540,   541,   542,
     543,   544,   259,   255,   691,   259,   549,   259,   245,   251,
     553,   554,   555,   556,   557,   558,   559,   259,   561,   251,
     563,   253,   138,   260,   261,   559,   119,   561,   631,   632,
       8,     6,     7,   636,   247,   248,   223,   224,   225,   226,
     156,   254,   101,   238,   239,   104,   589,   106,   250,   165,
     166,   167,   595,  1310,   138,   171,   172,   238,   239,  1316,
     247,   248,   255,   255,   259,    98,   255,   259,   101,   250,
     259,   104,   156,   254,   617,   618,   240,   241,   242,   243,
     244,   165,   166,   167,   117,   249,   104,   171,   172,   243,
     244,   238,   239,   633,   634,   249,   704,   250,  1260,   252,
     250,   250,   252,   256,  1361,   250,   259,   941,   238,   239,
     240,   241,   242,   243,   244,   143,   144,   250,  1375,   249,
       6,   149,   665,   666,   667,  1382,    98,   670,   739,   101,
     250,   250,   104,   252,   106,   254,   143,   250,   250,   255,
     255,   148,   149,   150,   259,   250,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   250,   699,   700,   701,   702,
     703,   250,   705,   706,   707,   708,   709,   254,   251,   712,
     253,   255,   761,   138,   708,   251,   259,   253,   255,   251,
     723,   253,   259,   259,   191,   422,   251,   259,   253,   250,
     798,   156,  1464,   736,   259,   432,   251,   106,   253,   206,
     165,   166,   167,   746,   259,   250,   171,   172,   255,   752,
     143,   144,   259,     6,     7,   255,   149,   454,   250,   259,
     252,   250,   254,   252,   255,   768,   769,   250,   259,   252,
     255,   774,   254,   776,   259,   255,   779,   780,   255,   259,
     255,   250,   259,   786,   259,   788,   250,   104,   252,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   250,   255,   255,
     255,   249,   259,   259,   259,   255,   101,   255,   821,   259,
     823,   255,  1554,   250,   255,   259,   255,   255,   259,   255,
     259,   259,   255,   259,  1566,   255,   259,   104,   255,   259,
     254,   538,   259,   540,   915,   542,   543,   544,   255,   101,
     255,   255,   259,   856,   259,   259,   254,   101,   255,   556,
     557,   929,   259,   866,   255,   255,   104,   255,   259,   259,
    2116,   259,   255,   255,   255,   255,   259,   259,   259,   259,
     255,   944,   255,   255,   259,   255,   259,   259,   951,   259,
     255,   255,   955,   255,   259,   259,   255,   259,   255,   255,
     259,   904,   259,   259,  2149,   255,   104,   255,   255,   259,
       8,   259,   259,   255,   917,   255,   255,   259,   255,   259,
     259,   255,   259,   926,   255,   259,   255,   255,   259,  2175,
     259,   259,   254,   251,   937,   253,   254,   251,   254,   253,
     254,     4,   639,     6,     4,     4,     4,     4,  2193,   250,
     250,   250,   250,   250,     6,   422,     6,   252,   250,   252,
     254,     6,   258,   254,     6,   662,   250,   250,   258,     9,
     250,   250,   250,   250,   250,  1046,  1047,   250,   250,   254,
    1048,   250,   188,   188,   188,   127,   254,   250,   250,   250,
     250,   188,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   250,   699,   700,   701,   702,   254,   250,   705,   706,
     707,   250,   254,   250,   254,     4,     6,   250,   715,   254,
     254,   718,   254,   250,   250,   250,   250,   250,  1342,   250,
     250,     6,     6,   730,   252,   254,   252,   254,  1041,   254,
     254,   254,   252,   252,  1107,     6,     6,   254,   188,  1052,
     250,   250,     6,     6,  1057,   250,   250,   250,   250,     6,
       8,   252,     6,   760,   254,   762,     8,  1070,   254,  1691,
    1692,   538,  1075,   540,     7,   542,   543,     6,   254,   254,
       6,   254,   779,   255,    93,   259,   251,     7,   259,   556,
     557,   788,     6,     6,   251,   254,   254,   249,   254,   254,
      65,     8,   256,     4,     7,  1108,  1109,     7,  1111,  1112,
    1113,   250,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,     6,   251,  1127,     4,     5,  1198,  1199,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     6,   254,     7,
       6,   249,     7,   251,     6,   253,     6,   185,   255,   254,
     253,   255,  1165,  1166,  1167,   255,   251,     6,    47,    48,
      49,    50,    51,    52,    53,    54,    55,   254,    54,     7,
     256,    60,    61,    62,    63,     6,  1189,   252,   250,    68,
      69,    70,     4,   254,     7,     6,    75,     6,    77,     6,
       6,     6,  1205,  1206,  1207,   251,     7,     7,   252,     7,
       7,     7,    91,     7,     7,    94,     7,     7,     7,     7,
       7,     7,     7,   690,     7,   692,   693,   694,   695,   696,
     697,   254,   699,   700,   701,   702,     6,   251,   705,   706,
     707,   253,   259,   940,   259,   942,   943,  1561,   259,   255,
    1544,   259,   251,     7,  1548,   255,   254,     7,  1261,   956,
    1260,   256,   254,   254,     4,     6,   138,   254,   256,   255,
     255,     7,     6,   256,  1277,  1278,  1279,     7,   975,     7,
       7,   251,   251,   259,     9,  1288,     8,   259,   259,   251,
    1293,  1362,  1363,   256,  1297,   253,   188,   994,     7,   258,
     255,     6,   159,  1306,   254,  1308,     6,     6,  1311,     4,
      47,   256,   779,   250,    47,   254,   250,  1385,   254,  1387,
     250,   788,     4,  1326,   256,   204,   205,   206,   256,   205,
       7,   250,     7,  1030,     7,   259,   215,   188,     7,  1342,
     219,   251,   221,   222,     7,     7,     6,   251,   259,  1971,
       7,     7,     7,     7,     7,     4,   116,     4,   254,   250,
    1363,     6,   104,     7,     6,  1368,     7,  1370,     7,     7,
       7,     7,     7,     7,   254,     6,     6,     6,  1075,     7,
       7,     6,   258,     6,  1387,     4,     4,   257,   259,   251,
     259,   254,     6,   254,   254,     6,     6,  1400,     7,     6,
       6,  1404,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   255,   295,
    1567,  1568,   249,   252,   250,   250,     6,     6,     6,  1492,
     254,     6,   255,     6,   310,   253,   256,   259,   314,     6,
     131,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,  1765,     6,     6,     5,  1458,  1459,  1460,     6,   251,
       4,     6,     4,  1466,  1467,  1468,     6,   251,     7,  1166,
    1167,     6,  1540,   254,   254,   254,   254,   254,   252,     6,
    1483,   254,   254,  1554,   255,   254,   254,   254,   254,     6,
     254,  1494,     6,     6,   184,     6,     6,     6,   259,  1502,
     259,   259,   251,  1506,   259,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   254,     6,   254,     7,   249,     4,   251,
     256,  1228,   250,  1601,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     6,
       6,   427,   428,   249,   255,     6,  1619,     6,  1561,     4,
       7,   250,   250,     6,  1567,  1568,     6,   443,     6,     6,
    1573,     6,     6,     6,   102,     6,     5,   251,   254,   259,
       6,     6,   254,   138,   254,     6,   138,     6,  1591,   138,
       6,   259,     6,     6,   259,  1666,  1293,     6,  1601,   251,
    1297,   259,     4,  1606,   254,     6,     6,     6,  1075,  1306,
       6,  1308,     6,   259,  1311,     6,     6,   142,     7,  1687,
       6,  1768,   254,  1320,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   254,   254,   254,
       5,   249,     6,     6,  1707,  1708,  1709,  1710,  1711,  1712,
     251,   254,     6,   255,   254,     6,   255,     7,   254,     6,
     183,     6,   251,  1731,   255,   541,  1363,   255,   255,     6,
    1738,  1739,     7,     6,   256,  1678,     6,   553,     6,   555,
    1683,  1684,     6,     6,   254,     6,  1980,     6,     6,  1757,
       6,  1691,  1692,     6,  2008,   186,     6,     6,     6,  1166,
    1167,     6,     6,  1706,   251,   255,   138,     6,   254,  1712,
    1781,   254,     6,   250,   255,     6,     6,   255,   254,   251,
    1723,   254,     6,   254,   254,     6,   255,   251,   254,     6,
    1733,     6,   254,  1736,   255,   255,     6,     6,     6,     6,
       6,     6,   254,     6,     6,     6,   254,   254,     6,     6,
       6,  1754,     6,  1374,  2129,   470,  1432,  1937,  1761,  1611,
    1897,  1674,  1765,  1399,  1767,  1768,     3,     3,     3,     3,
     610,  1967,  1537,     3,  1761,   779,  1738,    -1,    -1,    -1,
    1568,    -1,  2076,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1803,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
    1823,    -1,    -1,  2117,   249,    -1,  1293,    -1,    -1,    -1,
    1297,  1899,  1835,  1836,    -1,    -1,    -1,    -1,    -1,  1306,
      -1,  1308,    -1,    -1,  1311,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    -1,  1860,    -1,    -1,
     736,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1872,
    1567,  1568,    -1,    -1,  1942,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1886,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1591,    -1,  1363,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
    1923,  1984,  1985,  1986,  1987,  1988,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1938,    -1,    -1,    -1,    -1,
    1943,    -1,    -1,  1946,  1947,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1965,    -1,    -1,  1968,    -1,    -1,    -1,    -1,
      -1,  1971,    -1,    -1,    -1,    -1,  1979,    -1,    -1,    -1,
    1983,    -1,    -1,    -1,    -1,  2048,    -1,    -1,    -1,  2052,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2008,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2019,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2092,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,  1736,
    2103,    -1,    -1,    -1,  2107,    -1,  2049,    -1,    -1,    -1,
     926,    -1,    -1,    -1,  1751,    -1,  1753,    -1,    -1,    -1,
    2123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1768,    -1,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,     4,     5,   249,    -1,    -1,  2101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1803,  2170,  2171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2119,  2120,  2121,  2122,
    2123,    -1,    -1,    -1,  1591,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,    70,
    2163,    -1,    -1,    -1,    75,  1041,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2180,    -1,    -1,
      91,  1057,    -1,    94,     6,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,  2202,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,     6,    -1,  2216,    -1,    -1,    -1,    -1,    -1,    -1,
    2223,  2224,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1108,  1109,  2237,  1111,  1112,  1113,    -1,  1115,
    1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,  1736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    -1,  1165,
      -1,    -1,    -1,   204,   205,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,    -1,
     221,   222,    -1,  1189,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1205,
      -1,    -1,    -1,    -1,    -1,    -1,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,     7,   256,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,  2061,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
      -1,  1277,  1278,  1279,    -1,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
    2127,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
    1326,    -1,    -1,  2150,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,    -1,   242,   243,
      -1,    -1,    -1,    -1,    -1,  2202,    -1,   251,   252,    -1,
      -1,  1387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   263,
     264,    -1,    -1,    -1,  1400,    -1,  2223,  2224,  1404,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2237,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
       6,    -1,    -1,   249,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,  1458,  1459,  1460,    -1,   249,    -1,    -1,    -1,
    1466,  1467,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1494,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1502,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,
     384,   385,    -1,    -1,    -1,   389,   390,   391,   392,   393,
     394,   395,    -1,   397,    -1,    -1,    -1,   401,   402,    -1,
      -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    -1,
      -1,     8,    -1,    10,    11,    12,    -1,  1573,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,  1601,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2202,     6,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2223,  2224,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
    2237,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,
     116,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,  1678,   249,    -1,    -1,    -1,   143,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,    -1,    -1,   571,    -1,    -1,
    1706,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,   177,   178,     6,   180,   181,   182,  1723,   184,   185,
     186,   187,   188,   189,   190,    -1,   192,   193,   194,   195,
      -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,
     207,  1767,    -1,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   250,    -1,   271,   272,   273,   274,   275,
     257,    -1,    -1,    -1,    -1,    -1,    -1,  1823,    -1,    -1,
      -1,    -1,    -1,    -1,   290,   291,   292,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,   312,    -1,    -1,   249,
      -1,    -1,    -1,    -1,  1860,    -1,   322,   323,    -1,    -1,
      -1,    -1,   328,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   338,   339,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,   363,   364,    -1,
      -1,    -1,   368,   369,   370,    -1,   372,    -1,    -1,    -1,
     376,   377,   378,    -1,    -1,   381,    -1,  1923,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1938,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,   419,    -1,    -1,   249,   423,   424,  1965,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1979,   440,   441,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   882,   475,
     476,   477,   478,  2019,    -1,    -1,    -1,   483,    -1,    -1,
      -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   501,   502,    -1,    -1,    -1,
     506,    -1,   916,  2049,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,    -1,
     536,   537,    -1,   539,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   548,    -1,    -1,   551,   552,    -1,    -1,    -1,
      -1,    -1,   558,    -1,    -1,    -1,    -1,   563,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,    -1,
     596,   597,    -1,    -1,    -1,    -1,    -1,    -1,   604,   605,
     606,     6,    -1,    -1,    -1,    -1,   612,   613,   614,   615,
      -1,   617,   618,    -1,    -1,    -1,    -1,  2163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     636,   637,   638,    -1,    -1,    -1,   642,   643,   644,   645,
     646,   647,   648,   649,   650,     6,    -1,    -1,    -1,    -1,
     656,    -1,   658,    -1,    -1,   661,    -1,    -1,    -1,   665,
     666,   667,   668,    -1,   670,   671,   672,   673,    -1,    -1,
    2216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1095,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   712,    -1,    -1,    -1,
      -1,    -1,    -1,   719,    -1,   721,    -1,    -1,   724,   725,
      -1,    -1,    -1,    -1,    -1,    -1,   199,   733,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     746,    -1,   748,    -1,    -1,    -1,    -1,   753,   754,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   768,    -1,   770,   771,    -1,    -1,   774,    -1,
     776,   777,    -1,    -1,    -1,   781,  1190,   783,    -1,    -1,
      -1,    -1,    -1,   789,    -1,    -1,    -1,   793,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   272,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   819,    -1,   821,    -1,   823,   291,   292,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,   199,    -1,   249,    -1,     6,    -1,    -1,    -1,
     856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     866,   867,   868,    -1,    -1,   338,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   364,    -1,    -1,    -1,    -1,    -1,    -1,   904,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   917,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   925,
      -1,    -1,    -1,   929,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   937,  1346,  1347,   291,   292,    -1,    -1,    -1,   945,
     946,    -1,    -1,    -1,    -1,   951,    -1,    -1,    -1,    -1,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   968,    -1,    -1,   971,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   338,    -1,    -1,    -1,    -1,     6,   993,    -1,   995,
     996,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1014,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,  1437,    -1,    -1,    -1,    -1,    -1,   502,
      -1,  1037,    -1,  1447,    -1,    -1,    -1,    -1,  1044,    -1,
      -1,    -1,    -1,  1049,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,  1064,  1065,
     533,   534,    -1,    -1,  1070,    -1,   423,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   558,    -1,    -1,    -1,   249,
     563,    -1,    -1,    -1,    -1,    -1,  1102,  1103,  1104,  1105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   589,    -1,    -1,    -1,
      -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1143,    -1,    -1,
      -1,    -1,    -1,    -1,   617,   618,    -1,  1153,  1154,  1155,
      -1,    -1,    -1,    -1,  1160,  1161,    -1,  1163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1177,  1178,    -1,    -1,    -1,    -1,    -1,    -1,  1185,
    1186,    -1,    -1,    -1,    -1,    -1,  1192,    -1,  1194,  1195,
      -1,  1605,   665,   666,   667,  1201,  1202,   670,    -1,    -1,
    1206,  1207,    -1,    -1,    -1,    -1,   563,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,  1240,    -1,    -1,    -1,    -1,   712,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
     617,   618,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1276,    -1,    -1,   746,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1288,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1296,    -1,    -1,    -1,    -1,   768,    -1,    -1,    -1,    -1,
      -1,   774,    -1,   776,    -1,    -1,    -1,    -1,   665,   666,
     667,  1317,  1318,   670,    -1,    -1,  1322,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1333,    -1,    -1,
    1336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   821,    -1,
     823,    -1,    -1,    -1,    -1,   712,    -1,    -1,  1364,    -1,
      -1,  1367,  1368,  1369,  1370,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1378,    -1,    -1,  1381,    -1,  1383,  1384,  1385,
       6,    -1,    -1,   856,    -1,    -1,    -1,    -1,    -1,   746,
      -1,    -1,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   768,    -1,    -1,    -1,    -1,    -1,   774,    -1,   776,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   904,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1465,
      -1,    -1,    -1,    -1,   937,    -1,    -1,    -1,  1474,  1475,
    1476,    -1,    -1,    -1,    -1,    -1,    -1,  1483,    -1,  1485,
      -1,    -1,    -1,    -1,     4,     5,  1492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   856,
    1506,    -1,    -1,    -1,    -1,  1511,  1512,    -1,    -1,   866,
      -1,    -1,    -1,    -1,  1520,  1521,  1522,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1532,    47,    48,    49,
      50,    51,    52,    53,    54,    55,  1542,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,   904,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,  1565,
     917,    -1,    -1,    -1,    -1,  1571,  1572,    -1,    -1,    -1,
      -1,    91,    -1,     6,    94,    -1,    -1,    -1,    -1,    -1,
     937,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1070,    -1,    -1,
    1606,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1646,  1647,  1648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1657,    -1,    -1,  1127,    -1,  1662,  1663,  1664,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1676,    -1,    -1,    -1,    -1,    -1,    -1,  1683,  1684,  1685,
      -1,  1687,    -1,    -1,   204,   205,   206,  1693,  1694,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
      -1,   221,    -1,    -1,    -1,    -1,  1712,    -1,    -1,    -1,
      -1,  1717,    -1,  1070,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1731,    -1,    -1,  1734,    -1,
      -1,    -1,  1738,  1206,  1207,    -1,    -1,    -1,    -1,    -1,
      -1,  1747,  1748,    -1,  1750,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,  1774,    -1,
    1127,    -1,    -1,  1779,  1780,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1793,    -1,    -1,
    1796,  1797,    -1,  1799,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,  1288,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1835,
    1836,     6,    -1,    -1,    -1,    -1,  1842,  1843,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1854,  1206,
    1207,    -1,    -1,    -1,    -1,    -1,    -1,  1863,    -1,   445,
      -1,    -1,    -1,    -1,    -1,    -1,  1872,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1882,  1883,    -1,    -1,
    1886,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1368,    -1,  1370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1920,  1921,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1288,    -1,    -1,    -1,  1941,    -1,    -1,    -1,    -1,
    1946,  1947,  1948,    -1,    -1,    -1,    -1,  1953,    -1,    -1,
    1956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1968,   549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1983,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1991,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
    2016,  1368,    -1,  1370,   600,    -1,  2022,    -1,    -1,  2025,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,  2057,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,  2082,  2083,    -1,    -1,
      -1,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2097,  2098,    -1,  2100,  2101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2114,    -1,
      -1,    -1,    -1,  2119,  2120,  2121,  2122,  2123,    -1,    -1,
      -1,    -1,    -1,  2129,    -1,    -1,    -1,  2133,    -1,    -1,
      -1,    -1,    -1,  1606,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    -1,    -1,  1506,
     114,   115,   116,   117,    -1,  2161,   120,    -1,    -1,    -1,
    2166,  2167,  2168,   127,   128,    -1,    -1,   131,   132,    -1,
     134,   135,    -1,   137,  2180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2208,  2209,  2210,    -1,    -1,    -1,    -1,    -1,
    1683,  1684,    -1,    -1,    -1,    -1,   180,   181,   182,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1712,
      -1,    -1,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   837,   838,    -1,   840,   841,   842,   843,    -1,   845,
     846,   847,   848,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   859,    -1,   861,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   871,    -1,    -1,    -1,    -1,
      -1,   255,   878,   879,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   887,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,     3,     4,     5,   249,    -1,  1683,  1684,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,  1835,  1836,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    78,    79,    80,  1872,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    94,  1886,  1000,  1001,  1002,    -1,    -1,    -1,
    1006,  1007,    -1,    -1,  1010,  1011,  1012,  1013,    -1,  1015,
      -1,    -1,    -1,    -1,  1020,    -1,    -1,    -1,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1946,  1947,    -1,    -1,    -1,  1835,  1836,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1968,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1983,    -1,    -1,    -1,    -1,  1101,    -1,    -1,    -1,    -1,
    1106,   203,   204,   205,   206,   207,    -1,    -1,    -1,  1886,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,   221,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,  1946,
    1947,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,  1968,    -1,    -1,   249,    -1,   251,  1203,   253,    -1,
      -1,    -1,    -1,    -1,   259,    -1,  1983,    -1,  2101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2119,  2120,  2121,  2122,
    2123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2180,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,  2101,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1345,
      -1,    -1,  2119,  2120,  2121,  2122,  2123,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1386,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,  2180,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1418,  1419,  1420,  1421,  1422,    -1,    -1,    -1,
      -1,  1427,  1428,    -1,    -1,    -1,    -1,  1433,    -1,  1435,
      -1,    -1,    -1,  1439,    -1,    -1,  1442,    -1,    -1,    -1,
     203,    -1,    -1,    -1,   207,    -1,    -1,    -1,  1454,   212,
     213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,   250,    -1,    -1,
      -1,   254,    -1,    -1,   257,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     8,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,  1528,    -1,  1530,    -1,    -1,    -1,  1534,    -1,
    1536,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    73,
      74,    75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,  1665,
      94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,    -1,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1770,    -1,    -1,  1773,    -1,   203,
     204,   205,   206,   207,   208,    -1,    -1,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,    -1,   221,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,   250,    -1,  1824,  1825,
     254,  1827,    -1,   257,    -1,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     3,     4,     5,    -1,   249,    -1,    -1,
      10,    11,    12,   255,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,  1890,  1891,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    69,
      70,    -1,    -1,    73,    74,    75,    -1,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,  1939,    94,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,   206,   207,   208,    -1,
      -1,    -1,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,   221,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
     250,     3,     4,     5,   254,     7,    -1,   257,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    94,  2189,    -1,    -1,    98,    -1,    -1,   101,
       5,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,    -1,
      -1,   203,   204,   205,   206,   207,    -1,    -1,    -1,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,    -1,   221,
     222,   223,   224,   225,   226,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,    -1,   247,   248,    -1,   250,    -1,
     252,     3,     4,     5,   256,   257,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
     205,   206,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
     215,    -1,    64,    65,   219,    -1,   221,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   250,     3,
       4,    -1,   254,    -1,     8,   257,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,   208,    -1,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,   250,     3,     4,     5,
      -1,   255,    -1,   257,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,
      -1,   207,   208,    -1,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,   250,     3,     4,    -1,   254,    -1,
      -1,   257,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,   255,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,
     208,    -1,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   250,     3,     4,    -1,   254,   255,    -1,   257,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,   208,    -1,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
     250,     3,     4,    -1,   254,    -1,    -1,   257,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   250,     3,
       4,    -1,   254,    -1,    -1,   257,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,   208,    -1,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,    -1,   250,     3,     4,    -1,
     254,    -1,    -1,   257,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,
      -1,   207,   208,    -1,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,   250,     3,     4,    -1,    -1,   255,
      -1,   257,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,
     208,    -1,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   250,     3,     4,    -1,   254,    -1,    -1,   257,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,   208,    -1,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
     250,     3,     4,    -1,   254,    -1,    -1,   257,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,   250,     3,
       4,    -1,   254,    -1,     8,   257,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,   208,    -1,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,    -1,
      -1,   245,     3,     4,    -1,    -1,   250,     8,    -1,    10,
      11,    12,    -1,   257,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
      -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,    -1,    -1,   207,   208,    -1,    -1,
      -1,   212,   213,   214,    -1,   216,   217,   218,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,
      -1,    -1,    -1,    -1,   245,     3,     4,    -1,    -1,   250,
      -1,    -1,    10,    11,    12,    -1,   257,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,   207,
     208,    -1,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   250,     3,     4,    -1,   254,    -1,    -1,   257,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,   208,    -1,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,
     250,     3,     4,    -1,   254,    -1,    -1,   257,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,
     132,    -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,   207,   208,    -1,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,
      -1,    -1,    -1,   245,     3,     4,     5,    -1,   250,    -1,
      -1,    10,    11,    12,    -1,   257,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    -1,    94,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    -1,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,    -1,
      -1,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,   221,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,   254,    -1,    -1,   257,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   203,   204,   205,   206,
     207,    -1,    -1,    -1,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,    -1,   221,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   250,     3,     4,     5,   254,    -1,    -1,
     257,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    -1,    94,     3,     4,    -1,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,    -1,
      -1,    -1,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,    -1,   221,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,   257,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,
     207,    -1,    -1,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   250,     3,     4,    -1,   254,    -1,    -1,
     257,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,     3,     4,    -1,     6,    -1,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,   203,    -1,   249,    -1,   207,    -1,
      -1,    -1,    -1,   212,   213,   214,   259,   216,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,    -1,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,   250,   251,    -1,    -1,    -1,    -1,    -1,   257,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,    -1,    -1,   203,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,
     239,    -1,    -1,    -1,    -1,    -1,   245,     3,     4,    -1,
       6,   250,    -1,    -1,    10,    11,    12,    -1,   257,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,     3,     4,    -1,
       6,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,   203,    -1,   249,
      -1,   207,    -1,    -1,    -1,    -1,   212,   213,   214,   259,
     216,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,   203,    -1,    -1,
      -1,   207,    -1,    -1,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,
       3,     4,    -1,    -1,   250,    -1,    -1,    10,    11,    12,
      -1,   257,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    89,    90,    -1,    92,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     203,    -1,    -1,    -1,   207,   259,    -1,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,   239,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,    -1,   250,   251,    -1,
      -1,    -1,    -1,    -1,   257,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,   203,    -1,    -1,    -1,   207,   259,    -1,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,    -1,
      -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
      -1,    -1,    -1,    -1,    -1,   245,     3,     4,    -1,    -1,
     250,   251,    -1,    10,    11,    12,    -1,   257,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,   203,    -1,   249,    -1,
     207,    -1,    -1,    -1,    -1,   212,   213,   214,   259,   216,
     217,   218,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,   238,   239,    -1,    -1,    -1,    -1,    -1,   245,    -1,
      -1,    -1,    -1,   250,   204,   205,   206,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
      -1,   221,   222,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    13,    14,    -1,    -1,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,    69,
      70,   251,    -1,   253,   254,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    13,    14,    -1,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,   219,
      -1,   221,   222,   180,   181,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    13,    14,   254,   114,   115,   116,   117,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   255,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,   180,   181,   182,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      13,    14,    -1,   114,   115,   116,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,   255,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,   180,
     181,   182,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    13,    14,
      -1,   114,   115,   116,   117,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,   255,    -1,    -1,    -1,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,   180,   181,   182,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    13,    14,    -1,   114,
     115,   116,   117,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   255,    -1,    -1,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,   180,   181,   182,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    13,    14,    -1,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
     255,    -1,    -1,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,   180,   181,   182,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    13,    14,    -1,   114,   115,   116,   117,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   255,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,   180,   181,   182,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      13,    14,    -1,   114,   115,   116,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,   255,    -1,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,   180,
     181,   182,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    13,    14,
      -1,   114,   115,   116,   117,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,   255,    -1,    -1,    -1,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,   180,   181,   182,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    13,    14,    -1,   114,
     115,   116,   117,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,   255,    -1,    -1,    -1,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,   180,   181,   182,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    13,    14,    -1,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
     255,    -1,    -1,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,   180,   181,   182,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    13,    14,    -1,   114,   115,   116,   117,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,   255,    -1,
      -1,    -1,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,   180,   181,   182,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    -1,   255,    -1,    -1,    -1,
       0,     1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    44,    45,    46,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    -1,    87,    88,    -1,
      90,    -1,    -1,    -1,   255,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,   114,   115,   116,   117,   118,    -1,
     120,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,    -1,    -1,   139,
     140,   141,    -1,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    -1,     4,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    13,    14,    -1,    -1,   179,
     180,   181,   182,    -1,    -1,   185,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,    -1,    -1,    -1,    44,    45,    46,   209,
     210,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,   222,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,    87,
      88,    -1,    90,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   113,   114,   115,   116,   117,
     118,    -1,   120,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,    -1,
      -1,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    -1,    -1,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,   179,   180,   181,   182,     4,     5,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,   211,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,   220,    -1,   222,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,   134,   114,   115,   116,   117,
      13,    14,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,
      -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,   204,   205,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,
     219,    -1,   221,   222,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,   114,   115,   116,   117,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,   180,   181,   182,
      -1,    -1,    -1,    -1,    -1,   259,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   259,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   259,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   259,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,   255,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
     255,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,   255,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,   255,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,   255,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,   255,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,   255,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,   255,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,   255,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
     255,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,   255,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,   255,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,   255,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,   255,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,   255,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,   255,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,   255,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
     255,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,   255,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,   255,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,   255,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,   255,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,   255,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,   255,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,   255,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
     254,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,   254,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,   251,    -1,   253,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
     253,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,   253,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,   253,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,   253,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,   253,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,   253,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,   253,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,   253,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
     253,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,   253,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,   253,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,   253,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249,    -1,   251,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,   249,    -1,   251,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,    -1,    -1,    -1,   249
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   261,   262,     6,     0,     4,    13,    14,    44,
      45,    46,    65,    66,    67,    71,    72,    76,    81,    82,
      83,    84,    85,    87,    88,    90,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   113,   114,   115,   116,   117,   118,   120,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   139,   140,   141,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   168,
     169,   170,   174,   179,   180,   181,   182,   185,   187,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   209,   210,   211,   220,   222,   263,   265,
     266,   286,   305,   307,   311,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   329,   331,   332,   338,   339,   340,
     341,   347,   372,   373,   254,   258,    14,   104,   250,   250,
     250,     6,   254,     6,     6,     6,     6,   250,     6,     6,
     254,     6,     6,   252,   252,     4,   349,   373,   250,   252,
     284,    98,   101,   104,   106,   284,   250,   250,   250,     4,
     250,   250,   250,     4,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   254,   119,   104,     6,   254,
      98,   101,   104,   117,   310,   106,   250,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      56,    57,    58,    59,    64,    65,    73,    74,    78,    79,
      80,    89,    92,    98,   101,   104,   106,   117,   127,   132,
     134,   137,   203,   207,   208,   212,   213,   214,   216,   217,
     218,   238,   239,   245,   250,   254,   257,   307,   308,   311,
     322,   329,   331,   342,   343,   347,   349,   356,   358,   373,
     250,   254,   254,   104,   104,   127,   101,   104,   106,    98,
     101,   104,   106,   307,   101,   104,   105,   106,   117,   180,
     308,   101,   104,   250,   101,   159,   185,   201,   202,   254,
     238,   239,   250,   254,   353,   354,   353,   254,   254,   353,
       4,    98,   102,   108,   109,   111,   112,   131,   254,   250,
     104,   106,   104,   101,     4,    90,   196,   254,   373,     4,
       6,    98,   101,   104,   101,   104,   117,   309,   104,     4,
       4,     4,     5,   250,   254,   356,   357,     4,   250,   250,
     250,     4,   254,   360,   373,     4,   250,   250,   250,     6,
       6,   252,     5,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    60,    61,    62,    63,    68,    69,    70,    75,
      77,    91,    94,   204,   205,   206,   215,   219,   221,   364,
     373,   250,     4,   364,     5,   254,     5,   254,    32,   239,
     342,   373,   252,   254,   250,   254,     6,   250,   254,     6,
     258,     7,   134,   196,   223,   224,   225,   226,   247,   248,
     250,   252,   256,   282,   283,   284,   307,   342,   363,   364,
     373,     4,   311,   312,   313,   254,     6,   342,   363,   364,
     373,   363,   363,   342,   363,   370,   371,   373,   342,   288,
     292,   250,   352,     9,   364,   250,   250,   250,   250,   373,
     342,   342,   342,   250,   342,   342,   342,   250,   342,   342,
     342,   342,   342,   342,   342,   363,   342,   342,   342,   342,
     357,   250,   239,   342,   358,   359,   254,   357,   356,   363,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   250,   252,   284,   284,   284,   284,   284,
     284,   250,   284,   284,   250,   307,   308,   308,   284,   284,
       5,   254,   254,   127,   307,   307,   250,   284,   284,   250,
     250,   250,   342,   254,   342,   358,   342,   342,   255,   359,
     349,   373,   188,     5,   254,     8,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   249,     9,   250,   252,   256,   283,
     284,   342,   359,   359,   250,   250,   250,   356,   357,   357,
     357,   306,   250,   254,   250,   250,   356,   254,   254,   342,
       4,   356,   254,   360,   254,   254,   353,   353,   353,   342,
     342,   238,   239,   254,   254,   353,   238,   239,   250,   313,
     353,   254,   250,   254,   250,   250,   250,   250,   250,   250,
     250,   359,   342,   357,   357,   357,   250,     4,   252,   254,
       6,   252,   313,     6,     6,   254,   254,   254,   254,   357,
     254,   252,   252,   252,   342,     8,     6,     6,   342,   342,
     342,   256,   342,   254,   188,   342,   342,   342,   342,   284,
     284,   284,   250,   250,   250,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   250,   250,   284,   250,   252,
       6,     6,   254,     6,     8,   313,     6,     8,   313,   284,
     342,   240,   254,     9,   250,   252,   256,   363,   359,   342,
     313,   356,   356,   254,   364,   307,     7,   342,   342,     4,
     185,   186,   356,     6,   251,   253,   254,   285,   254,     6,
     254,     6,     9,   250,   252,   256,   373,   255,   127,   132,
     134,   135,   137,   305,   307,   342,     6,   251,   259,     9,
     250,   252,   256,   251,   259,   251,   259,   259,   251,   259,
       9,   250,   256,   259,   253,   259,   287,   253,   287,    93,
     351,   348,   373,   259,   342,   342,   342,   342,   259,   251,
     251,   251,   342,   251,   251,   251,   342,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   255,     7,
     342,   240,   255,   259,   342,     6,     6,   251,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   358,   342,   342,   342,   342,
     342,   342,   342,   358,   358,   373,   254,   342,   342,   363,
     342,   363,   356,   363,   363,   370,   254,   254,   254,   342,
     285,   373,     8,   342,   342,   357,   356,   363,   363,   358,
     349,   364,   349,   359,   251,   255,   256,   284,    65,     8,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   254,   342,   358,   342,   342,   342,
     342,   342,   373,   342,   342,     4,   350,   254,   285,   251,
     255,   255,   342,   342,   342,     7,     7,   335,   335,   250,
     342,   342,   342,   342,     6,   359,   359,   254,   251,     6,
     313,   254,   313,   313,   259,   259,   259,   353,   353,   312,
     312,   259,   342,   255,   326,   259,   313,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   255,   251,     7,   336,
       6,     7,   342,     6,   342,   313,   342,   255,   359,   359,
     359,   342,     6,   359,   342,   342,   342,   251,   255,   251,
     251,   251,   185,   259,   313,   254,     8,   251,   251,   253,
     370,   363,   370,   363,   363,   363,   363,   363,   363,   342,
     363,   363,   363,   363,   257,   366,   373,   364,   363,   363,
     363,   349,   373,   359,   255,   255,   255,   255,   342,   342,
     313,   373,   350,   253,   255,   251,   141,   159,   330,   251,
     255,   259,   342,     6,   254,   356,   251,   253,     7,   282,
     283,   256,     7,     6,   359,     7,   226,   282,   342,   267,
     373,   342,   342,   350,   252,   250,   127,   307,   308,   307,
     254,   255,     6,   233,   234,   264,   359,   373,   342,   342,
       4,   350,     6,   359,     6,   359,   342,     6,   363,   371,
     373,   251,   350,   342,     6,   373,     6,   363,   342,   251,
     252,   342,   259,   259,   259,   259,   364,     7,     7,     7,
     251,     7,     7,     7,   251,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   342,   251,   254,   342,   358,
     255,     6,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   259,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   259,   259,   259,   251,   253,   253,   359,
     259,   259,   285,   259,   285,   259,   259,   259,   251,   359,
     342,   342,   344,   285,   255,   255,   255,   259,   259,   285,
     285,   251,   256,   251,   256,   259,   284,   345,   255,     7,
     350,   285,   254,   255,     8,     8,   359,   256,   251,   253,
     283,   250,   252,   284,   359,     7,   254,   254,   251,   251,
     251,   342,   356,     4,   334,     6,   301,   342,   364,   251,
     255,   251,   251,   255,   255,   359,   256,   255,   313,   255,
     255,   353,   342,   342,   255,   255,   342,   353,   138,   138,
     156,   165,   166,   167,   171,   172,   327,   328,   353,   255,
     323,   251,   255,   251,   251,   251,   251,   251,   251,   251,
     254,     7,   342,     6,   342,   251,   253,   255,   253,   255,
     255,   255,   255,   255,   253,   253,   259,     7,     7,     7,
     256,   342,   255,   342,   342,     7,   256,   285,   259,   285,
     285,   251,   251,   259,   285,   285,   259,   259,   285,   285,
     285,   285,   342,   285,     9,   365,   259,   251,   259,   285,
     256,   259,   346,   253,   255,   255,   256,   250,   252,   258,
     188,     7,   159,     6,   342,   255,   254,     6,   356,   255,
     342,     6,     7,   282,   283,   256,   282,   283,   364,   342,
       6,     4,   254,   361,   373,   255,    47,    47,   356,   255,
       4,   175,   176,   177,   178,   255,   270,   274,   277,   279,
     280,   256,   251,   253,   250,   342,   342,   250,   254,   250,
     254,     8,   359,   363,   251,   256,   251,   253,   250,   251,
     251,   259,   256,   250,   259,     7,   284,     4,   295,   296,
     297,   285,   342,   342,   342,   342,   285,   353,   356,   356,
       7,   356,   356,   356,     7,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,     6,     7,   359,   342,   342,
     342,   342,   255,   342,   342,   342,   356,   363,   363,   255,
     255,   255,   259,   294,   342,   342,   350,   350,   342,   342,
     251,   356,   284,   342,   342,   342,   255,   350,   283,   256,
     283,   342,   342,   285,   255,   356,   359,   359,     7,     7,
       7,   138,   333,     6,   251,   259,     7,     7,     7,     7,
       7,   255,     4,   255,   259,   259,   259,   255,   255,   116,
       4,     6,   342,   254,     6,   250,     6,   173,     6,   173,
     255,   328,   259,   327,     7,     6,     7,     7,     7,     7,
       7,     7,     7,   312,   356,     6,   254,     6,     6,     6,
     104,     7,     7,     6,     6,   342,   356,   356,   356,     4,
     259,     8,     8,   251,     4,   107,   108,     4,   359,   363,
     342,   363,   257,   259,   298,   363,   363,   350,   363,   251,
     259,   350,   254,   307,   254,     6,   342,     6,   254,   356,
     255,   255,   342,     6,     4,   185,   186,   342,     6,     6,
       6,     7,   360,   362,     6,   252,   285,   284,   284,     6,
     271,   250,   250,   254,   281,     6,   350,   256,   363,   342,
     253,   251,   342,     8,   359,   342,   359,   255,   255,     6,
       6,   264,   350,   256,   342,     6,     6,   342,   350,   251,
     342,   254,   342,   364,   285,    47,   254,   356,   364,   367,
     253,   259,     6,   251,   251,   251,   251,     6,     6,   131,
     303,   303,   356,     6,     6,     6,   356,   138,   188,   302,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     5,
     255,   285,   285,   285,   285,   285,   259,   259,   259,   251,
     285,   285,   296,   285,   251,   285,   251,   284,   345,   285,
       6,   285,   259,   250,   252,   284,     4,   251,   253,   285,
       6,   255,   255,   356,   356,   356,     4,     6,   282,   342,
     356,   356,   356,   254,   254,     7,     6,     7,   342,   342,
     342,   254,   254,   254,   252,     6,   342,   356,   342,     6,
       6,   342,   353,   255,     5,   356,   254,   254,   254,   254,
     254,   254,   254,   356,   255,     6,   359,   254,   342,   342,
     253,     6,     6,   184,   342,   342,   342,     6,     6,     6,
       6,     7,   285,   259,   259,   285,   259,   342,     4,   200,
     299,   300,   285,   251,   285,   346,   364,   250,   252,   342,
     254,   313,     6,   313,   259,     6,     6,     7,   282,   283,
     256,     7,     6,   360,   255,   259,   342,   282,   254,   285,
     368,   369,   370,   368,   250,   342,   342,   355,   356,   254,
     250,     4,     6,   251,     6,   251,   255,   255,   251,   255,
       6,     6,   363,   250,     4,   251,   259,   250,   255,   259,
     356,   364,     7,   284,   293,   342,   358,   297,     6,     6,
       6,     6,   353,     6,     6,     6,   138,   304,    98,   117,
     102,     6,     5,   254,   342,   342,   342,   342,   251,   345,
     342,   342,   342,   285,   283,   254,   254,     6,   302,     6,
     342,   356,   138,   138,     4,     6,   359,   359,   342,   342,
     364,   255,   251,   255,   259,   312,   312,   342,   342,   255,
     259,   251,   255,   259,     6,     6,   355,   353,   353,   353,
     353,   353,   239,   353,     6,   255,   342,     6,     6,     6,
     356,   255,   259,     8,   255,   251,   254,   342,   364,   363,
     342,   363,   342,   364,   367,   369,   364,   259,   251,   259,
     255,   342,   330,   330,   356,   364,   342,     6,     4,   361,
       6,   360,   253,   356,   370,     6,   285,   285,   268,   342,
     259,   259,   255,   259,   269,   342,   342,     6,     6,     6,
       6,   342,   342,   251,     6,   342,   289,   291,   254,   369,
     255,   259,     7,     7,   142,     6,   254,   254,   254,     5,
     355,   285,   285,   259,   285,   251,   259,   251,   253,   359,
     359,     6,     6,   342,   342,   254,   255,   255,   254,     6,
       6,   254,   342,   255,   255,   255,   253,     6,   356,     7,
     254,   342,   255,   259,   259,   259,   259,   259,   259,     6,
     255,   183,   342,   342,   359,     6,     6,   251,   285,   285,
     300,   364,   255,   255,   255,   255,     6,     6,     7,     6,
     256,     6,   255,     6,     6,   251,   259,   342,   342,   254,
     356,   255,   259,   251,   251,   259,   255,   294,   298,   356,
     285,   342,   364,   373,   359,   359,   342,     6,   255,   342,
     345,   342,   255,   255,     6,     6,   355,   143,   144,   149,
     337,   143,   144,   337,   359,   312,   255,   259,     6,   255,
     356,   313,   255,     6,   359,   353,   353,   353,   353,   353,
     342,   255,   255,   255,   251,     6,   254,     6,   360,   186,
     272,   342,   259,   259,   355,     6,   342,   342,     6,   255,
     255,   290,     7,   250,   255,   255,   255,   254,   259,   251,
     259,   254,   255,   254,   353,   356,     6,   254,   353,     6,
     255,   255,   342,     6,   138,   255,   324,   254,   255,   259,
     259,   259,   259,   259,     6,     6,     6,   313,     6,   254,
     342,   342,   255,   259,   294,   364,   251,   342,   342,   342,
     359,     6,   353,     6,   353,     6,     6,   255,   342,   327,
     313,     6,   359,   359,   359,   359,   353,   359,   330,   269,
     251,   259,     6,   254,   342,   255,   259,   259,   259,   255,
     259,   259,     6,   255,   255,   325,   255,   255,   255,   255,
     259,   255,   255,   255,   275,   342,   355,   255,   342,   342,
     342,   353,   353,   327,     6,     6,     6,     6,   359,     6,
       6,     6,   254,   251,   255,     6,   255,   285,   259,   259,
     259,   255,   255,   273,   363,   278,   254,     6,   342,   342,
     342,     6,   255,   259,   254,   355,   255,   255,   255,     6,
     363,   276,   363,   255,     6,     6,   255,   259,     6,     6,
     363
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

  case 46:
#line 503 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 505 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 510 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 49:
#line 512 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 50:
#line 517 "Gmsh.y"
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
#line 621 "Gmsh.y"
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
#line 631 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 53:
#line 640 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 54:
#line 647 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 55:
#line 657 "Gmsh.y"
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
#line 666 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 57:
#line 675 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 58:
#line 682 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 59:
#line 692 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 60:
#line 700 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 61:
#line 710 "Gmsh.y"
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
#line 729 "Gmsh.y"
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
#line 748 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 64:
#line 754 "Gmsh.y"
    {
    ;}
    break;

  case 65:
#line 761 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 66:
#line 762 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 67:
#line 763 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 68:
#line 764 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 69:
#line 765 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 70:
#line 769 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 71:
#line 770 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 72:
#line 776 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 73:
#line 776 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 74:
#line 777 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 75:
#line 777 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 79:
#line 787 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 80:
#line 792 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 81:
#line 798 "Gmsh.y"
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
#line 860 "Gmsh.y"
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
#line 875 "Gmsh.y"
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
#line 904 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 85:
#line 914 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 919 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 927 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 88:
#line 932 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 89:
#line 940 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 90:
#line 949 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 91:
#line 954 "Gmsh.y"
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
#line 966 "Gmsh.y"
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
#line 983 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 94:
#line 989 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 95:
#line 998 "Gmsh.y"
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
#line 1016 "Gmsh.y"
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
#line 1034 "Gmsh.y"
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
#line 1043 "Gmsh.y"
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
#line 1055 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 100:
#line 1060 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 101:
#line 1068 "Gmsh.y"
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
#line 1088 "Gmsh.y"
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
#line 1111 "Gmsh.y"
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
#line 1131 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 105:
#line 1139 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 106:
#line 1146 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 107:
#line 1153 "Gmsh.y"
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
#line 1175 "Gmsh.y"
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
#line 1198 "Gmsh.y"
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
#line 1236 "Gmsh.y"
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
#line 1257 "Gmsh.y"
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
#line 1269 "Gmsh.y"
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
#line 1287 "Gmsh.y"
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
#line 1296 "Gmsh.y"
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
#line 1305 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1307 "Gmsh.y"
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
#line 1325 "Gmsh.y"
    { init_options(); ;}
    break;

  case 121:
#line 1327 "Gmsh.y"
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
#line 1343 "Gmsh.y"
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
#line 1352 "Gmsh.y"
    { init_options(); ;}
    break;

  case 124:
#line 1354 "Gmsh.y"
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
#line 1368 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 127:
#line 1376 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 128:
#line 1382 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 129:
#line 1387 "Gmsh.y"
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
#line 1430 "Gmsh.y"
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
#line 1442 "Gmsh.y"
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
#line 1455 "Gmsh.y"
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
#line 1470 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 140:
#line 1479 "Gmsh.y"
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
#line 1504 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 146:
#line 1512 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 147:
#line 1521 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 148:
#line 1529 "Gmsh.y"
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
#line 1543 "Gmsh.y"
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
#line 1561 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 151:
#line 1565 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 152:
#line 1572 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 153:
#line 1580 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 154:
#line 1584 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 155:
#line 1590 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 156:
#line 1594 "Gmsh.y"
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
#line 1605 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 158:
#line 1609 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 159:
#line 1615 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 160:
#line 1619 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 161:
#line 1625 "Gmsh.y"
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
#line 1648 "Gmsh.y"
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
#line 1664 "Gmsh.y"
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
#line 1680 "Gmsh.y"
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
#line 1697 "Gmsh.y"
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
#line 1714 "Gmsh.y"
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
#line 1751 "Gmsh.y"
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
#line 1795 "Gmsh.y"
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
#line 1811 "Gmsh.y"
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
#line 1828 "Gmsh.y"
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
#line 1859 "Gmsh.y"
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
#line 1875 "Gmsh.y"
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
#line 1892 "Gmsh.y"
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
#line 1908 "Gmsh.y"
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
#line 1958 "Gmsh.y"
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
#line 1976 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 177:
#line 1982 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 178:
#line 1988 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 179:
#line 1995 "Gmsh.y"
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
#line 2026 "Gmsh.y"
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
#line 2041 "Gmsh.y"
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
#line 2063 "Gmsh.y"
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
#line 2086 "Gmsh.y"
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
#line 2109 "Gmsh.y"
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
#line 2132 "Gmsh.y"
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
#line 2156 "Gmsh.y"
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
#line 2180 "Gmsh.y"
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
#line 2204 "Gmsh.y"
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
#line 2230 "Gmsh.y"
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
#line 2247 "Gmsh.y"
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
#line 2263 "Gmsh.y"
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
#line 2281 "Gmsh.y"
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
#line 2299 "Gmsh.y"
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
#line 2312 "Gmsh.y"
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
#line 2324 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 196:
#line 2328 "Gmsh.y"
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
#line 2354 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 198:
#line 2356 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 199:
#line 2358 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 200:
#line 2360 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 201:
#line 2362 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 202:
#line 2370 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 203:
#line 2372 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 204:
#line 2374 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 205:
#line 2376 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 206:
#line 2384 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 207:
#line 2386 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 208:
#line 2388 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 209:
#line 2396 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 210:
#line 2398 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 211:
#line 2400 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 212:
#line 2402 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 213:
#line 2412 "Gmsh.y"
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
#line 2428 "Gmsh.y"
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
#line 2444 "Gmsh.y"
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
#line 2460 "Gmsh.y"
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
#line 2476 "Gmsh.y"
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
#line 2492 "Gmsh.y"
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
#line 2509 "Gmsh.y"
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
#line 2546 "Gmsh.y"
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
#line 2568 "Gmsh.y"
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
#line 2591 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 223:
#line 2592 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 224:
#line 2597 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 225:
#line 2601 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 226:
#line 2605 "Gmsh.y"
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
#line 2622 "Gmsh.y"
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
#line 2642 "Gmsh.y"
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
#line 2662 "Gmsh.y"
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
#line 2681 "Gmsh.y"
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
#line 2708 "Gmsh.y"
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
#line 2727 "Gmsh.y"
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
#line 2749 "Gmsh.y"
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
#line 2764 "Gmsh.y"
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
#line 2779 "Gmsh.y"
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
#line 2798 "Gmsh.y"
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
#line 2849 "Gmsh.y"
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
#line 2870 "Gmsh.y"
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
#line 2892 "Gmsh.y"
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
#line 2914 "Gmsh.y"
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
#line 3019 "Gmsh.y"
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
#line 3035 "Gmsh.y"
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
#line 3070 "Gmsh.y"
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
#line 3092 "Gmsh.y"
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
#line 3114 "Gmsh.y"
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
#line 3126 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 247:
#line 3132 "Gmsh.y"
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
#line 3147 "Gmsh.y"
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
#line 3175 "Gmsh.y"
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
#line 3187 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 251:
#line 3196 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3203 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 253:
#line 3215 "Gmsh.y"
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
#line 3235 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 255:
#line 3239 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 256:
#line 3244 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 257:
#line 3248 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 258:
#line 3253 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 259:
#line 3260 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3267 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 261:
#line 3274 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 262:
#line 3286 "Gmsh.y"
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
#line 3359 "Gmsh.y"
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
#line 3377 "Gmsh.y"
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
#line 3402 "Gmsh.y"
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
#line 3417 "Gmsh.y"
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
#line 3450 "Gmsh.y"
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
#line 3462 "Gmsh.y"
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
#line 3494 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 270:
#line 3498 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 271:
#line 3503 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 272:
#line 3510 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 273:
#line 3515 "Gmsh.y"
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
#line 3525 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 275:
#line 3530 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 276:
#line 3536 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 277:
#line 3544 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 278:
#line 3548 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 279:
#line 3552 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 280:
#line 3556 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 281:
#line 3560 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 282:
#line 3564 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 283:
#line 3568 "Gmsh.y"
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
#line 3578 "Gmsh.y"
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
#line 3641 "Gmsh.y"
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
#line 3657 "Gmsh.y"
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
#line 3674 "Gmsh.y"
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
#line 3691 "Gmsh.y"
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
#line 3713 "Gmsh.y"
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
#line 3735 "Gmsh.y"
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
#line 3770 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 292:
#line 3778 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 293:
#line 3786 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 294:
#line 3792 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 295:
#line 3799 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 296:
#line 3806 "Gmsh.y"
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
#line 3826 "Gmsh.y"
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
#line 3852 "Gmsh.y"
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
#line 3864 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 300:
#line 3875 "Gmsh.y"
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
#line 3893 "Gmsh.y"
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
#line 3911 "Gmsh.y"
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
#line 3929 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 304:
#line 3935 "Gmsh.y"
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
#line 3953 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 306:
#line 3959 "Gmsh.y"
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
#line 3979 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 308:
#line 3985 "Gmsh.y"
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
#line 4003 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 310:
#line 4009 "Gmsh.y"
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
#line 4026 "Gmsh.y"
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
#line 4042 "Gmsh.y"
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
#line 4059 "Gmsh.y"
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
#line 4077 "Gmsh.y"
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
#line 4100 "Gmsh.y"
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
#line 4127 "Gmsh.y"
    {
    ;}
    break;

  case 317:
#line 4130 "Gmsh.y"
    {
    ;}
    break;

  case 318:
#line 4136 "Gmsh.y"
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
#line 4148 "Gmsh.y"
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
#line 4168 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 321:
#line 4172 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 322:
#line 4176 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 323:
#line 4180 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 324:
#line 4184 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 325:
#line 4188 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 326:
#line 4192 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 327:
#line 4196 "Gmsh.y"
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
#line 4205 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 329:
#line 4217 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 330:
#line 4218 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 331:
#line 4219 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 332:
#line 4220 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 333:
#line 4221 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 334:
#line 4225 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 335:
#line 4226 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 336:
#line 4227 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 337:
#line 4228 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 338:
#line 4229 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 339:
#line 4234 "Gmsh.y"
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
#line 4257 "Gmsh.y"
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
#line 4277 "Gmsh.y"
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
#line 4298 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 343:
#line 4302 "Gmsh.y"
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
#line 4317 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 345:
#line 4321 "Gmsh.y"
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
#line 4337 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 347:
#line 4341 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 348:
#line 4346 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 349:
#line 4350 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 350:
#line 4356 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 351:
#line 4360 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 352:
#line 4367 "Gmsh.y"
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
#line 4389 "Gmsh.y"
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
#line 4430 "Gmsh.y"
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
#line 4474 "Gmsh.y"
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
#line 4513 "Gmsh.y"
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
#line 4538 "Gmsh.y"
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
#line 4550 "Gmsh.y"
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
#line 4562 "Gmsh.y"
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
#line 4574 "Gmsh.y"
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
#line 4586 "Gmsh.y"
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
#line 4603 "Gmsh.y"
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
#line 4620 "Gmsh.y"
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
#line 4650 "Gmsh.y"
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
#line 4676 "Gmsh.y"
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
#line 4703 "Gmsh.y"
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
#line 4735 "Gmsh.y"
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
#line 4762 "Gmsh.y"
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
#line 4788 "Gmsh.y"
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
#line 4814 "Gmsh.y"
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
#line 4840 "Gmsh.y"
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
#line 4866 "Gmsh.y"
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
#line 4887 "Gmsh.y"
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
#line 4898 "Gmsh.y"
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
#line 4946 "Gmsh.y"
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
#line 5000 "Gmsh.y"
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
#line 5015 "Gmsh.y"
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
#line 5027 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 379:
#line 5038 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 380:
#line 5045 "Gmsh.y"
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
#line 5060 "Gmsh.y"
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
#line 5073 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 383:
#line 5074 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 384:
#line 5075 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 385:
#line 5080 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 386:
#line 5086 "Gmsh.y"
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
#line 5098 "Gmsh.y"
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
#line 5116 "Gmsh.y"
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
#line 5143 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 390:
#line 5144 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 391:
#line 5145 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 392:
#line 5146 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 393:
#line 5147 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 394:
#line 5148 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 395:
#line 5149 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 396:
#line 5150 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 397:
#line 5152 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 398:
#line 5158 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 399:
#line 5159 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 400:
#line 5160 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 401:
#line 5161 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 402:
#line 5162 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5163 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 404:
#line 5164 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 405:
#line 5165 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 406:
#line 5166 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 407:
#line 5167 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5168 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5169 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 410:
#line 5170 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 411:
#line 5171 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 412:
#line 5172 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 413:
#line 5173 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 414:
#line 5174 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 415:
#line 5175 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 416:
#line 5176 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 417:
#line 5177 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 418:
#line 5178 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 419:
#line 5179 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 420:
#line 5180 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 421:
#line 5181 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 422:
#line 5182 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5183 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 424:
#line 5184 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5185 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5186 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5187 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5188 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 429:
#line 5189 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 430:
#line 5190 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 431:
#line 5191 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 432:
#line 5192 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 433:
#line 5193 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 434:
#line 5194 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 435:
#line 5195 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 436:
#line 5204 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 437:
#line 5205 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 438:
#line 5206 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 439:
#line 5207 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 440:
#line 5208 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 441:
#line 5209 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 442:
#line 5210 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 443:
#line 5211 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 444:
#line 5212 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 445:
#line 5213 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 446:
#line 5214 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 447:
#line 5219 "Gmsh.y"
    { init_options(); ;}
    break;

  case 448:
#line 5221 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 449:
#line 5227 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 450:
#line 5229 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 451:
#line 5234 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 452:
#line 5239 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 453:
#line 5244 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 454:
#line 5249 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 455:
#line 5253 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 456:
#line 5257 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 457:
#line 5261 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 458:
#line 5265 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 459:
#line 5269 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 460:
#line 5273 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 461:
#line 5277 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5283 "Gmsh.y"
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
#line 5298 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 464:
#line 5302 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 465:
#line 5308 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 466:
#line 5313 "Gmsh.y"
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
#line 5332 "Gmsh.y"
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
#line 5352 "Gmsh.y"
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
#line 5383 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 470:
#line 5387 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 471:
#line 5391 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 472:
#line 5395 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 473:
#line 5399 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 474:
#line 5403 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 475:
#line 5407 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 476:
#line 5412 "Gmsh.y"
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
#line 5422 "Gmsh.y"
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
#line 5432 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 479:
#line 5437 "Gmsh.y"
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
#line 5448 "Gmsh.y"
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
#line 5457 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 482:
#line 5462 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 483:
#line 5467 "Gmsh.y"
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
#line 5494 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 485:
#line 5496 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 486:
#line 5501 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 487:
#line 5503 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 488:
#line 5508 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 489:
#line 5515 "Gmsh.y"
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
#line 5531 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 491:
#line 5533 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 492:
#line 5538 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 493:
#line 5547 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 494:
#line 5549 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 495:
#line 5554 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 496:
#line 5556 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 497:
#line 5561 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 498:
#line 5565 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 499:
#line 5569 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 500:
#line 5573 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 501:
#line 5577 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 502:
#line 5584 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 503:
#line 5588 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 504:
#line 5592 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 505:
#line 5596 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 506:
#line 5603 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 507:
#line 5608 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 508:
#line 5615 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 509:
#line 5620 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 510:
#line 5624 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 511:
#line 5629 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 512:
#line 5633 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 513:
#line 5641 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 514:
#line 5652 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 515:
#line 5656 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 516:
#line 5660 "Gmsh.y"
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
#line 5674 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 518:
#line 5682 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 519:
#line 5690 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 520:
#line 5697 "Gmsh.y"
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
#line 5707 "Gmsh.y"
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
#line 5730 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 523:
#line 5735 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 524:
#line 5741 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 525:
#line 5746 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 526:
#line 5752 "Gmsh.y"
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
#line 5763 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 528:
#line 5770 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 529:
#line 5775 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 530:
#line 5781 "Gmsh.y"
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
#line 5793 "Gmsh.y"
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
#line 5807 "Gmsh.y"
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

  case 534:
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

  case 535:
#line 5837 "Gmsh.y"
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
#line 5849 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 537:
#line 5853 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 538:
#line 5858 "Gmsh.y"
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
#line 5870 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 540:
#line 5874 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 541:
#line 5878 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 542:
#line 5882 "Gmsh.y"
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
#line 5900 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 544:
#line 5908 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 545:
#line 5916 "Gmsh.y"
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
#line 5945 "Gmsh.y"
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
#line 5955 "Gmsh.y"
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
#line 5971 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 549:
#line 5982 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 550:
#line 5987 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 551:
#line 5991 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 552:
#line 5995 "Gmsh.y"
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
#line 6007 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 554:
#line 6011 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 555:
#line 6023 "Gmsh.y"
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
#line 6040 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 557:
#line 6050 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 558:
#line 6054 "Gmsh.y"
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
#line 6069 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 560:
#line 6074 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 561:
#line 6081 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 562:
#line 6085 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 563:
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

  case 564:
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

  case 565:
#line 6120 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 566:
#line 6124 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 567:
#line 6128 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 568:
#line 6132 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 569:
#line 6136 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 570:
#line 6144 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 571:
#line 6150 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 572:
#line 6159 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 573:
#line 6163 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 574:
#line 6167 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 575:
#line 6175 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 576:
#line 6181 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 577:
#line 6187 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 578:
#line 6191 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 579:
#line 6199 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 580:
#line 6207 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 581:
#line 6214 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 582:
#line 6223 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 583:
#line 6227 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 584:
#line 6231 "Gmsh.y"
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
#line 6246 "Gmsh.y"
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
#line 6260 "Gmsh.y"
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
#line 6274 "Gmsh.y"
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
#line 6286 "Gmsh.y"
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
#line 6302 "Gmsh.y"
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
#line 6311 "Gmsh.y"
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
#line 6320 "Gmsh.y"
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
#line 6330 "Gmsh.y"
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
#line 6341 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 594:
#line 6349 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 595:
#line 6357 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 596:
#line 6361 "Gmsh.y"
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
#line 6380 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 598:
#line 6387 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 599:
#line 6393 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 600:
#line 6400 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 601:
#line 6407 "Gmsh.y"
    { init_options(); ;}
    break;

  case 602:
#line 6409 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 603:
#line 6417 "Gmsh.y"
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

  case 604:
#line 6441 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 605:
#line 6443 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 606:
#line 6449 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 607:
#line 6454 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 608:
#line 6456 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 609:
#line 6461 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 610:
#line 6466 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 611:
#line 6471 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 612:
#line 6473 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 613:
#line 6477 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 614:
#line 6489 "Gmsh.y"
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

  case 615:
#line 6503 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 616:
#line 6507 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 617:
#line 6514 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 618:
#line 6522 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 619:
#line 6530 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 620:
#line 6541 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 621:
#line 6543 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 622:
#line 6546 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14618 "Gmsh.tab.cpp"
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


#line 6549 "Gmsh.y"


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

