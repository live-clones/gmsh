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
     tLayers = 419,
     tScaleLast = 420,
     tHole = 421,
     tAlias = 422,
     tAliasWithOptions = 423,
     tCopyOptions = 424,
     tQuadTriAddVerts = 425,
     tQuadTriNoNewVerts = 426,
     tRecombLaterals = 427,
     tTransfQuadTri = 428,
     tText2D = 429,
     tText3D = 430,
     tInterpolationScheme = 431,
     tTime = 432,
     tCombine = 433,
     tBSpline = 434,
     tBezier = 435,
     tNurbs = 436,
     tNurbsOrder = 437,
     tNurbsKnots = 438,
     tColor = 439,
     tColorTable = 440,
     tFor = 441,
     tIn = 442,
     tEndFor = 443,
     tIf = 444,
     tElseIf = 445,
     tElse = 446,
     tEndIf = 447,
     tExit = 448,
     tAbort = 449,
     tField = 450,
     tReturn = 451,
     tCall = 452,
     tSlide = 453,
     tMacro = 454,
     tShow = 455,
     tHide = 456,
     tGetValue = 457,
     tGetStringValue = 458,
     tGetEnv = 459,
     tGetString = 460,
     tGetNumber = 461,
     tUnique = 462,
     tHomology = 463,
     tCohomology = 464,
     tBetti = 465,
     tExists = 466,
     tFileExists = 467,
     tGetForced = 468,
     tGetForcedStr = 469,
     tGMSH_MAJOR_VERSION = 470,
     tGMSH_MINOR_VERSION = 471,
     tGMSH_PATCH_VERSION = 472,
     tGmshExecutableName = 473,
     tSetPartition = 474,
     tNameToString = 475,
     tStringToName = 476,
     tAFFECTDIVIDE = 477,
     tAFFECTTIMES = 478,
     tAFFECTMINUS = 479,
     tAFFECTPLUS = 480,
     tOR = 481,
     tAND = 482,
     tNOTEQUAL = 483,
     tEQUAL = 484,
     tGREATERGREATER = 485,
     tLESSLESS = 486,
     tGREATEROREQUAL = 487,
     tLESSOREQUAL = 488,
     UNARYPREC = 489,
     tMINUSMINUS = 490,
     tPLUSPLUS = 491
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
#define tLayers 419
#define tScaleLast 420
#define tHole 421
#define tAlias 422
#define tAliasWithOptions 423
#define tCopyOptions 424
#define tQuadTriAddVerts 425
#define tQuadTriNoNewVerts 426
#define tRecombLaterals 427
#define tTransfQuadTri 428
#define tText2D 429
#define tText3D 430
#define tInterpolationScheme 431
#define tTime 432
#define tCombine 433
#define tBSpline 434
#define tBezier 435
#define tNurbs 436
#define tNurbsOrder 437
#define tNurbsKnots 438
#define tColor 439
#define tColorTable 440
#define tFor 441
#define tIn 442
#define tEndFor 443
#define tIf 444
#define tElseIf 445
#define tElse 446
#define tEndIf 447
#define tExit 448
#define tAbort 449
#define tField 450
#define tReturn 451
#define tCall 452
#define tSlide 453
#define tMacro 454
#define tShow 455
#define tHide 456
#define tGetValue 457
#define tGetStringValue 458
#define tGetEnv 459
#define tGetString 460
#define tGetNumber 461
#define tUnique 462
#define tHomology 463
#define tCohomology 464
#define tBetti 465
#define tExists 466
#define tFileExists 467
#define tGetForced 468
#define tGetForcedStr 469
#define tGMSH_MAJOR_VERSION 470
#define tGMSH_MINOR_VERSION 471
#define tGMSH_PATCH_VERSION 472
#define tGmshExecutableName 473
#define tSetPartition 474
#define tNameToString 475
#define tStringToName 476
#define tAFFECTDIVIDE 477
#define tAFFECTTIMES 478
#define tAFFECTMINUS 479
#define tAFFECTPLUS 480
#define tOR 481
#define tAND 482
#define tNOTEQUAL 483
#define tEQUAL 484
#define tGREATERGREATER 485
#define tLESSLESS 486
#define tGREATEROREQUAL 487
#define tLESSOREQUAL 488
#define UNARYPREC 489
#define tMINUSMINUS 490
#define tPLUSPLUS 491




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
#line 752 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 765 "Gmsh.tab.cpp"

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
#define YYLAST   17247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  259
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  621
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2233

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   491

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   244,     2,   256,     2,   241,   243,     2,
     249,   250,   239,   237,   258,   238,   255,   240,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     231,     2,   232,   226,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   251,     2,   252,   248,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   253,   242,   254,   257,     2,     2,     2,
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
     225,   227,   228,   229,   230,   233,   234,   235,   236,   245,
     246,   247
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
    2009,  2018,  2027,  2033,  2038,  2045,  2057,  2069,  2088,  2107,
    2120,  2133,  2146,  2157,  2162,  2167,  2172,  2177,  2182,  2185,
    2189,  2196,  2198,  2200,  2202,  2205,  2211,  2219,  2230,  2232,
    2236,  2239,  2242,  2245,  2249,  2253,  2257,  2261,  2265,  2269,
    2273,  2277,  2281,  2285,  2289,  2293,  2297,  2301,  2305,  2309,
    2313,  2317,  2323,  2328,  2333,  2338,  2343,  2348,  2353,  2358,
    2363,  2368,  2373,  2380,  2385,  2390,  2395,  2400,  2405,  2410,
    2415,  2420,  2427,  2434,  2441,  2446,  2448,  2450,  2452,  2454,
    2456,  2458,  2460,  2462,  2464,  2466,  2468,  2469,  2476,  2478,
    2483,  2490,  2492,  2497,  2502,  2507,  2514,  2520,  2528,  2537,
    2548,  2553,  2558,  2565,  2570,  2574,  2577,  2583,  2589,  2593,
    2599,  2606,  2615,  2622,  2631,  2638,  2643,  2651,  2658,  2665,
    2672,  2677,  2684,  2689,  2690,  2693,  2694,  2697,  2698,  2706,
    2708,  2712,  2714,  2716,  2719,  2720,  2724,  2726,  2729,  2732,
    2736,  2740,  2752,  2762,  2770,  2778,  2780,  2784,  2786,  2788,
    2791,  2795,  2800,  2806,  2808,  2812,  2814,  2817,  2821,  2825,
    2831,  2836,  2841,  2844,  2849,  2852,  2856,  2860,  2877,  2883,
    2889,  2895,  2897,  2899,  2901,  2905,  2911,  2919,  2924,  2929,
    2934,  2941,  2948,  2957,  2966,  2971,  2986,  2991,  2996,  2998,
    3000,  3004,  3008,  3018,  3026,  3028,  3034,  3038,  3045,  3047,
    3051,  3053,  3055,  3060,  3065,  3069,  3075,  3082,  3091,  3098,
    3103,  3109,  3111,  3116,  3118,  3120,  3122,  3124,  3129,  3136,
    3141,  3148,  3154,  3162,  3167,  3172,  3177,  3186,  3191,  3196,
    3201,  3206,  3215,  3224,  3231,  3236,  3243,  3248,  3250,  3255,
    3260,  3261,  3268,  3273,  3276,  3281,  3286,  3288,  3290,  3294,
    3296,  3298,  3302,  3306,  3310,  3316,  3324,  3330,  3336,  3345,
    3347,  3349
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     260,     0,    -1,   261,    -1,     1,     6,    -1,    -1,   261,
     262,    -1,   264,    -1,   265,    -1,   285,    -1,   126,   249,
     362,   250,     6,    -1,   304,    -1,   310,    -1,   314,    -1,
     315,    -1,   316,    -1,   317,    -1,   321,    -1,   330,    -1,
     331,    -1,   337,    -1,   338,    -1,   320,    -1,   319,    -1,
     318,    -1,   313,    -1,   340,    -1,   232,    -1,   233,    -1,
      44,   249,   362,   250,     6,    -1,    46,   249,   362,   250,
       6,    -1,    45,   249,   362,   250,     6,    -1,    44,   249,
     362,   250,   263,   362,     6,    -1,    44,   249,   362,   258,
     358,   250,     6,    -1,    46,   249,   362,   258,   358,   250,
       6,    -1,    45,   249,   362,   258,   358,   250,     6,    -1,
      44,   249,   362,   258,   358,   250,   263,   362,     6,    -1,
     372,   362,   253,   266,   254,     6,    -1,   167,     4,   251,
     341,   252,     6,    -1,   168,     4,   251,   341,   252,     6,
      -1,   169,     4,   251,   341,   258,   341,   252,     6,    -1,
      -1,   266,   269,    -1,   266,   273,    -1,   266,   276,    -1,
     266,   278,    -1,   266,   279,    -1,   341,    -1,   267,   258,
     341,    -1,   341,    -1,   268,   258,   341,    -1,    -1,    -1,
       4,   270,   249,   267,   250,   271,   253,   268,   254,     6,
      -1,   362,    -1,   272,   258,   362,    -1,    -1,   174,   249,
     341,   258,   341,   258,   341,   250,   274,   253,   272,   254,
       6,    -1,   362,    -1,   275,   258,   362,    -1,    -1,   175,
     249,   341,   258,   341,   258,   341,   258,   341,   250,   277,
     253,   275,   254,     6,    -1,   176,   253,   354,   254,   253,
     354,   254,     6,    -1,   176,   253,   354,   254,   253,   354,
     254,   253,   354,   254,   253,   354,   254,     6,    -1,    -1,
     177,   280,   253,   268,   254,     6,    -1,     7,    -1,   225,
      -1,   224,    -1,   223,    -1,   222,    -1,   247,    -1,   246,
      -1,   249,    -1,   251,    -1,   250,    -1,   252,    -1,    87,
     251,   287,   252,     6,    -1,    88,   251,   291,   252,     6,
      -1,   346,     6,    -1,    95,   283,   363,   258,   341,   284,
       6,    -1,    97,   283,   372,   258,   363,   284,     6,    -1,
     372,   281,   355,     6,    -1,   372,   282,     6,    -1,   372,
     283,   284,   281,   355,     6,    -1,   372,   283,   253,   358,
     254,   284,   281,   355,     6,    -1,   372,   251,   341,   252,
     281,   341,     6,    -1,   372,   251,   341,   252,   282,     6,
      -1,   372,   249,   341,   250,   281,   341,     6,    -1,   372,
     249,   341,   250,   282,     6,    -1,   372,     7,   363,     6,
      -1,   372,   283,   284,     7,    47,   283,   284,     6,    -1,
     372,   283,   284,     7,    47,   283,   367,   284,     6,    -1,
     372,   283,   284,   225,    47,   283,   367,   284,     6,    -1,
     372,   255,     4,     7,   363,     6,    -1,   372,   251,   341,
     252,   255,     4,     7,   363,     6,    -1,   372,   255,     4,
     281,   341,     6,    -1,   372,   251,   341,   252,   255,     4,
     281,   341,     6,    -1,   372,   255,     4,   282,     6,    -1,
     372,   251,   341,   252,   255,     4,   282,     6,    -1,   372,
     255,   184,   255,     4,     7,   359,     6,    -1,   372,   251,
     341,   252,   255,   184,   255,     4,     7,   359,     6,    -1,
     372,   255,   185,     7,   360,     6,    -1,   372,   251,   341,
     252,   255,   185,     7,   360,     6,    -1,   372,   195,     7,
     355,     6,    -1,   195,   251,   341,   252,     7,     4,     6,
      -1,   195,   251,   341,   252,     7,   107,     6,    -1,   195,
     251,   341,   252,     7,   108,     6,    -1,   195,   251,   341,
     252,   255,     4,     7,   341,     6,    -1,   195,   251,   341,
     252,   255,     4,     7,   363,     6,    -1,   195,   251,   341,
     252,   255,     4,     7,   253,   358,   254,     6,    -1,   195,
     251,   341,   252,   255,     4,     6,    -1,   139,   249,     4,
     250,   255,     4,     7,   341,     6,    -1,   139,   249,     4,
     250,   255,     4,     7,   363,     6,    -1,    -1,   258,    -1,
      -1,   287,   286,   372,    -1,   287,   286,   372,     7,   341,
      -1,    -1,   287,   286,   372,     7,   253,   355,   288,   293,
     254,    -1,    -1,   287,   286,   372,   283,   284,     7,   253,
     355,   289,   293,   254,    -1,   287,   286,   372,     7,   363,
      -1,    -1,   287,   286,   372,     7,   253,   363,   290,   297,
     254,    -1,    -1,   291,   286,   362,    -1,   341,     7,   363,
      -1,   292,   258,   341,     7,   363,    -1,   357,     7,   372,
     249,   250,    -1,    -1,   258,   295,    -1,    -1,   295,    -1,
     296,    -1,   295,   258,   296,    -1,     4,   355,    -1,     4,
      -1,     4,   253,   292,   254,    -1,     4,   363,    -1,     4,
     366,    -1,    -1,   258,   298,    -1,   299,    -1,   298,   258,
     299,    -1,     4,   341,    -1,     4,   363,    -1,   199,   363,
      -1,     4,   368,    -1,     4,   366,    -1,   341,    -1,   363,
      -1,   363,   258,   341,    -1,    -1,   187,   102,   253,   341,
     254,    -1,   138,    98,   253,   358,   254,    -1,   138,   117,
     253,   358,   254,    -1,    -1,   131,   352,    -1,    -1,   138,
     142,    -1,    98,   249,   341,   250,     7,   352,     6,    -1,
     101,   249,   341,   250,     7,   355,     6,    -1,   105,   249,
     341,   250,     7,   355,     6,    -1,   135,   105,   249,   341,
     250,     7,   355,   138,   341,     6,    -1,   135,   179,   249,
     341,   250,     7,   355,   138,   341,     6,    -1,    99,   249,
     341,   250,     7,   355,   302,     6,    -1,   100,   249,   341,
     250,     7,   355,   302,     6,    -1,   179,   249,   341,   250,
       7,   355,     6,    -1,   180,   249,   341,   250,     7,   355,
       6,    -1,   181,   249,   341,   250,     7,   355,   183,   355,
     182,   341,     6,    -1,   116,   249,   341,   250,     7,   355,
       6,    -1,   101,     4,   249,   341,   250,     7,   355,     6,
      -1,   131,   104,   249,   341,   250,     7,   355,     6,    -1,
     104,   249,   341,   250,     7,   355,   301,     6,    -1,   132,
     104,   249,   341,   250,     7,   355,   301,     6,    -1,    13,
      14,     6,    -1,    14,   104,   341,     6,    -1,   120,   104,
     249,   341,   250,     7,     5,     5,     5,     6,    -1,   102,
     249,   341,   250,     7,   355,     6,    -1,   103,   249,   341,
     250,     7,   355,     6,    -1,   107,   249,   341,   250,     7,
     355,     6,    -1,   110,   249,   341,   250,     7,   355,     6,
      -1,   114,   249,   341,   250,     7,   355,     6,    -1,   115,
     249,   341,   250,     7,   355,     6,    -1,   108,   249,   341,
     250,     7,   355,     6,    -1,   109,   249,   341,   250,     7,
     355,     6,    -1,   128,   249,   341,   250,     7,   355,     6,
      -1,   155,   249,   341,   250,     7,   355,     6,    -1,   104,
       4,   249,   341,   250,     7,   355,   303,     6,    -1,   106,
     249,   341,   250,     7,   355,     6,    -1,   127,   249,   341,
     250,     7,   355,     6,    -1,   132,   127,   249,   341,   250,
       7,   355,     6,    -1,   135,   307,   249,   341,   250,     7,
     355,     6,    -1,   135,   307,   249,   341,   250,     7,   355,
       4,   253,   354,   254,     6,    -1,    -1,   134,   306,   305,
     249,   300,   250,   281,   355,     6,    -1,    98,    -1,   101,
      -1,   104,    -1,   106,    -1,   117,   253,   341,   254,    -1,
     101,    -1,   104,    -1,   106,    -1,   117,   253,   341,   254,
      -1,   101,    -1,   104,    -1,   117,   253,   341,   254,    -1,
      98,    -1,   101,    -1,   104,    -1,   117,   253,   341,   254,
      -1,   144,   352,   253,   311,   254,    -1,   143,   253,   352,
     258,   352,   258,   341,   254,   253,   311,   254,    -1,   145,
     352,   253,   311,   254,    -1,   146,   253,   352,   258,   341,
     254,   253,   311,   254,    -1,   146,   253,   352,   258,   352,
     254,   253,   311,   254,    -1,   149,   253,   358,   254,   253,
     311,   254,    -1,     4,   253,   311,   254,    -1,   161,   101,
     253,   358,   254,   104,   253,   341,   254,    -1,   158,   101,
     249,   341,   250,   253,   358,   254,     6,    -1,   312,    -1,
     310,    -1,    -1,   312,   304,    -1,   312,   306,   253,   358,
     254,     6,    -1,   312,   134,   306,   253,   358,   254,     6,
      -1,   312,   137,   306,   253,   358,   254,     6,    -1,   312,
     306,   253,     8,   254,     6,    -1,   312,   134,   306,   253,
       8,   254,     6,    -1,   148,   131,   249,   341,   250,     7,
     355,     6,    -1,   148,    98,   249,   341,   250,     7,   253,
     354,   254,     6,    -1,   148,   131,   249,   341,   250,     7,
     253,   352,   258,   352,   258,   358,   254,     6,    -1,   148,
     131,   249,   341,   250,     7,   253,   352,   258,   352,   258,
     352,   258,   358,   254,     6,    -1,   148,   102,   249,   341,
     250,     7,   253,   352,   258,   358,   254,     6,    -1,   148,
     108,   249,   341,   250,     7,   253,   352,   258,   352,   258,
     358,   254,     6,    -1,   148,   109,   249,   341,   250,     7,
     253,   352,   258,   352,   258,   358,   254,     6,    -1,   148,
     111,   249,   341,   250,     7,   253,   352,   258,   352,   258,
     358,   254,     6,    -1,   148,   112,   249,   341,   250,     7,
     253,   352,   258,   352,   258,   358,   254,     6,    -1,   148,
       4,   249,   341,   250,     7,   355,     6,    -1,   148,     4,
     249,   341,   250,     7,     5,     6,    -1,   148,     4,   253,
     341,   254,     6,    -1,   159,   253,   312,   254,    -1,   141,
     159,   253,   312,   254,    -1,   159,     4,   253,   312,   254,
      -1,   159,   195,   251,   341,   252,     6,    -1,   159,     4,
     251,   341,   252,     6,    -1,   159,   372,     6,    -1,   159,
       4,     4,     6,    -1,   159,    90,     6,    -1,   184,   359,
     253,   312,   254,    -1,   141,   184,   359,   253,   312,   254,
      -1,   219,   341,   253,   312,   254,    -1,   200,   253,     8,
     254,    -1,   200,     5,     6,    -1,   201,   253,     8,   254,
      -1,   201,     5,     6,    -1,   200,   253,   312,   254,    -1,
     141,   200,   253,   312,   254,    -1,   201,   253,   312,   254,
      -1,   141,   201,   253,   312,   254,    -1,   372,   363,     6,
      -1,    76,   249,   369,   250,     6,    -1,   372,   372,   251,
     341,   252,   362,     6,    -1,   372,   372,   372,   251,   341,
     252,     6,    -1,   372,   341,     6,    -1,   139,   249,     4,
     250,   255,     4,     6,    -1,   178,     4,     6,    -1,   193,
       6,    -1,   194,     6,    -1,    71,     6,    -1,    72,     6,
      -1,    65,     6,    -1,    65,   253,   341,   258,   341,   258,
     341,   258,   341,   258,   341,   258,   341,   254,     6,    -1,
      66,     6,    -1,    67,     6,    -1,    81,     6,    -1,    83,
     253,   341,   258,   341,   258,   341,   254,     6,    -1,    83,
     253,   341,   258,   341,   258,   341,   258,   341,   254,     6,
      -1,    82,     6,    -1,    84,     6,    -1,    85,     6,    -1,
     122,     6,    -1,   123,   253,   358,   254,   253,   358,   254,
     253,   354,   254,   253,   341,   258,   341,   254,     6,    -1,
     198,   249,   253,   358,   254,   258,   363,   258,   363,   250,
       6,    -1,   186,   249,   341,     8,   341,   250,    -1,   186,
     249,   341,     8,   341,     8,   341,   250,    -1,   186,     4,
     187,   253,   341,     8,   341,   254,    -1,   186,     4,   187,
     253,   341,     8,   341,     8,   341,   254,    -1,   188,    -1,
     199,     4,    -1,   199,   363,    -1,   196,    -1,   197,   372,
       6,    -1,   197,   363,     6,    -1,   189,   249,   341,   250,
      -1,   190,   249,   341,   250,    -1,   191,    -1,   192,    -1,
     147,   352,   253,   312,   254,    -1,   147,   253,   352,   258,
     352,   258,   341,   254,   253,   312,   254,    -1,   147,   253,
     352,   258,   352,   258,   352,   258,   341,   254,   253,   312,
     254,    -1,    -1,   147,   352,   253,   312,   322,   326,   254,
      -1,    -1,   147,   253,   352,   258,   352,   258,   341,   254,
     253,   312,   323,   326,   254,    -1,    -1,   147,   253,   352,
     258,   352,   258,   352,   258,   341,   254,   253,   312,   324,
     326,   254,    -1,    -1,   147,   253,   312,   325,   326,   254,
      -1,   147,   253,   312,   254,   138,   116,   253,   341,   254,
      -1,   127,   355,    -1,   132,   127,   355,    -1,   129,   253,
     358,   254,   253,   358,   254,   253,   358,   254,    -1,   130,
     253,   358,   254,   253,   358,   254,   253,   358,   254,   253,
     358,   254,    -1,   327,    -1,   326,   327,    -1,   164,   253,
     341,   254,     6,    -1,   164,   253,   355,   258,   355,   254,
       6,    -1,   165,     6,    -1,   156,     6,    -1,   156,   341,
       6,    -1,   170,     6,    -1,   170,   172,     6,    -1,   171,
       6,    -1,   171,   172,     6,    -1,   166,   249,   341,   250,
       7,   355,   138,   341,     6,    -1,   138,     4,   251,   341,
     252,     6,    -1,   150,    -1,   151,    -1,   152,    -1,   153,
      -1,   154,    -1,    -1,   159,     6,    -1,   141,   159,     6,
      -1,   159,   341,     6,    -1,   141,   159,   341,     6,    -1,
     328,   253,   312,   329,   254,   253,   312,   329,   254,    -1,
     113,   249,   362,   250,    -1,   328,   249,   341,   250,     7,
     253,   312,   329,   254,   253,   312,   329,   254,     6,    -1,
      -1,   138,     4,   341,    -1,    -1,     4,    -1,    -1,     7,
     355,    -1,    -1,     7,   341,    -1,    -1,   149,   355,    -1,
     118,   119,   356,     7,   341,     6,    -1,   133,   101,   356,
       7,   341,   332,     6,    -1,   133,   104,   356,   334,   333,
       6,    -1,   133,   106,   356,   334,     6,    -1,   173,   356,
       6,    -1,    96,    98,   249,   341,   258,   341,   250,     6,
      -1,    96,   101,   249,   341,   258,   341,   250,     6,    -1,
      96,   104,   249,   341,   258,   341,   250,     6,    -1,    96,
     106,   249,   341,   258,   341,   250,     6,    -1,   162,   104,
     253,   358,   254,     7,   341,     6,    -1,   156,   104,   356,
     335,     6,    -1,   156,   106,   356,     6,    -1,   157,   104,
     356,     7,   341,     6,    -1,   136,   101,   253,   358,   254,
       7,   253,   358,   254,   336,     6,    -1,   136,   104,   253,
     358,   254,     7,   253,   358,   254,   336,     6,    -1,   136,
     101,   253,   358,   254,     7,   253,   358,   254,   143,   253,
     352,   258,   352,   258,   341,   254,     6,    -1,   136,   104,
     253,   358,   254,     7,   253,   358,   254,   143,   253,   352,
     258,   352,   258,   341,   254,     6,    -1,   136,   101,   253,
     358,   254,     7,   253,   358,   254,   144,   352,     6,    -1,
     136,   104,   253,   358,   254,     7,   253,   358,   254,   144,
     352,     6,    -1,   136,   104,   341,   253,   358,   254,     7,
     341,   253,   358,   254,     6,    -1,   306,   253,   358,   254,
     187,   306,   253,   341,   254,     6,    -1,   163,   308,   356,
       6,    -1,   124,   309,   356,     6,    -1,   125,   106,   355,
       6,    -1,   140,   101,   355,     6,    -1,   135,   307,   355,
       6,    -1,   160,     6,    -1,   160,     4,     6,    -1,   160,
      98,   253,   358,   254,     6,    -1,   208,    -1,   209,    -1,
     210,    -1,   339,     6,    -1,   339,   253,   355,   254,     6,
      -1,   339,   253,   355,   258,   355,   254,     6,    -1,   339,
     249,   355,   250,   253,   355,   258,   355,   254,     6,    -1,
     342,    -1,   249,   341,   250,    -1,   238,   341,    -1,   237,
     341,    -1,   244,   341,    -1,   341,   238,   341,    -1,   341,
     237,   341,    -1,   341,   239,   341,    -1,   341,   240,   341,
      -1,   341,   242,   341,    -1,   341,   243,   341,    -1,   341,
     241,   341,    -1,   341,   248,   341,    -1,   341,   231,   341,
      -1,   341,   232,   341,    -1,   341,   236,   341,    -1,   341,
     235,   341,    -1,   341,   230,   341,    -1,   341,   229,   341,
      -1,   341,   228,   341,    -1,   341,   227,   341,    -1,   341,
     233,   341,    -1,   341,   234,   341,    -1,   341,   226,   341,
       8,   341,    -1,    16,   283,   341,   284,    -1,    17,   283,
     341,   284,    -1,    18,   283,   341,   284,    -1,    19,   283,
     341,   284,    -1,    20,   283,   341,   284,    -1,    21,   283,
     341,   284,    -1,    22,   283,   341,   284,    -1,    23,   283,
     341,   284,    -1,    24,   283,   341,   284,    -1,    26,   283,
     341,   284,    -1,    27,   283,   341,   258,   341,   284,    -1,
      28,   283,   341,   284,    -1,    29,   283,   341,   284,    -1,
      30,   283,   341,   284,    -1,    31,   283,   341,   284,    -1,
      32,   283,   341,   284,    -1,    33,   283,   341,   284,    -1,
      34,   283,   341,   284,    -1,    35,   283,   341,   284,    -1,
      36,   283,   341,   258,   341,   284,    -1,    37,   283,   341,
     258,   341,   284,    -1,    38,   283,   341,   258,   341,   284,
      -1,    25,   283,   341,   284,    -1,     3,    -1,    10,    -1,
      15,    -1,    11,    -1,    12,    -1,   215,    -1,   216,    -1,
     217,    -1,    78,    -1,    79,    -1,    80,    -1,    -1,    89,
     283,   341,   343,   293,   284,    -1,   346,    -1,   206,   283,
     362,   284,    -1,   206,   283,   362,   258,   341,   284,    -1,
     348,    -1,   372,   251,   341,   252,    -1,   372,   249,   341,
     250,    -1,   211,   249,   348,   250,    -1,   211,   249,   348,
     255,   349,   250,    -1,   213,   249,   348,   344,   250,    -1,
     213,   249,   348,   255,   349,   344,   250,    -1,   213,   249,
     348,   283,   341,   284,   344,   250,    -1,   213,   249,   348,
     255,   349,   283,   341,   284,   344,   250,    -1,   212,   249,
     363,   250,    -1,   256,   372,   283,   284,    -1,   256,   348,
     255,   349,   283,   284,    -1,    92,   283,   372,   284,    -1,
      92,   283,   284,    -1,   372,   282,    -1,   372,   251,   341,
     252,   282,    -1,   372,   249,   341,   250,   282,    -1,   372,
     255,   349,    -1,   372,     9,   372,   255,   349,    -1,   372,
     255,   349,   249,   341,   250,    -1,   372,     9,   372,   255,
     349,   249,   341,   250,    -1,   372,   255,   349,   251,   341,
     252,    -1,   372,     9,   372,   255,   349,   251,   341,   252,
      -1,   372,   251,   341,   252,   255,     4,    -1,   372,   255,
       4,   282,    -1,   372,   251,   341,   252,   255,     4,   282,
      -1,   202,   249,   362,   258,   341,   250,    -1,    57,   249,
     355,   258,   355,   250,    -1,    58,   283,   362,   258,   362,
     284,    -1,    56,   283,   362,   284,    -1,    59,   283,   362,
     258,   362,   284,    -1,    64,   249,   369,   250,    -1,    -1,
     258,   341,    -1,    -1,   258,   362,    -1,    -1,    90,   348,
     351,   347,   251,   294,   252,    -1,   372,    -1,   372,     9,
     372,    -1,     4,    -1,    93,    -1,    93,   341,    -1,    -1,
     249,   350,   250,    -1,   353,    -1,   238,   352,    -1,   237,
     352,    -1,   352,   238,   352,    -1,   352,   237,   352,    -1,
     253,   341,   258,   341,   258,   341,   258,   341,   258,   341,
     254,    -1,   253,   341,   258,   341,   258,   341,   258,   341,
     254,    -1,   253,   341,   258,   341,   258,   341,   254,    -1,
     249,   341,   258,   341,   258,   341,   250,    -1,   355,    -1,
     354,   258,   355,    -1,   341,    -1,   357,    -1,   253,   254,
      -1,   253,   358,   254,    -1,   238,   253,   358,   254,    -1,
     341,   239,   253,   358,   254,    -1,   355,    -1,   253,     8,
     254,    -1,     5,    -1,   238,   357,    -1,   341,   239,   357,
      -1,   341,     8,   341,    -1,   341,     8,   341,     8,   341,
      -1,    98,   253,   341,   254,    -1,    98,   253,     8,   254,
      -1,    98,     5,    -1,   307,   253,     8,   254,    -1,   307,
       5,    -1,   134,   306,   356,    -1,   137,   306,   355,    -1,
     306,   187,    65,   253,   341,   258,   341,   258,   341,   258,
     341,   258,   341,   258,   341,   254,    -1,    65,   306,   253,
     358,   254,    -1,    73,   307,   253,   341,   254,    -1,    74,
     307,   253,   341,   254,    -1,   310,    -1,   321,    -1,   330,
      -1,   372,   283,   284,    -1,   372,   255,   349,   283,   284,
      -1,   372,     9,   372,   255,   349,   283,   284,    -1,    39,
     251,   372,   252,    -1,    39,   251,   357,   252,    -1,    39,
     249,   357,   250,    -1,    39,   283,   253,   358,   254,   284,
      -1,   372,   283,   253,   358,   254,   284,    -1,    40,   283,
     341,   258,   341,   258,   341,   284,    -1,    41,   283,   341,
     258,   341,   258,   341,   284,    -1,    42,   283,   362,   284,
      -1,    43,   283,   341,   258,   341,   258,   341,   258,   341,
     258,   341,   258,   341,   284,    -1,   207,   283,   357,   284,
      -1,    32,   283,   357,   284,    -1,   341,    -1,   357,    -1,
     358,   258,   341,    -1,   358,   258,   357,    -1,   253,   341,
     258,   341,   258,   341,   258,   341,   254,    -1,   253,   341,
     258,   341,   258,   341,   254,    -1,   372,    -1,     4,   255,
     184,   255,     4,    -1,   253,   361,   254,    -1,   372,   251,
     341,   252,   255,   185,    -1,   359,    -1,   361,   258,   359,
      -1,   363,    -1,   372,    -1,   372,   251,   341,   252,    -1,
     372,   249,   341,   250,    -1,   372,   255,   349,    -1,   372,
       9,   372,   255,   349,    -1,   372,   255,   349,   249,   341,
     250,    -1,   372,     9,   372,   255,   349,   249,   341,   250,
      -1,   372,   251,   341,   252,   255,     4,    -1,   306,   253,
     341,   254,    -1,   134,   306,   253,   341,   254,    -1,     5,
      -1,   220,   251,   372,   252,    -1,    68,    -1,   218,    -1,
      75,    -1,    77,    -1,   204,   249,   362,   250,    -1,   203,
     249,   362,   258,   362,   250,    -1,   205,   283,   362,   284,
      -1,   205,   283,   362,   258,   362,   284,    -1,   214,   249,
     348,   345,   250,    -1,   214,   249,   348,   255,   349,   345,
     250,    -1,    49,   283,   369,   284,    -1,    50,   249,   362,
     250,    -1,    51,   249,   362,   250,    -1,    52,   249,   362,
     258,   362,   258,   362,   250,    -1,    47,   283,   369,   284,
      -1,    61,   283,   362,   284,    -1,    62,   283,   362,   284,
      -1,    63,   283,   362,   284,    -1,    60,   283,   341,   258,
     362,   258,   362,   284,    -1,    55,   283,   362,   258,   341,
     258,   341,   284,    -1,    55,   283,   362,   258,   341,   284,
      -1,    48,   283,   362,   284,    -1,    48,   283,   362,   258,
     358,   284,    -1,    69,   283,   362,   284,    -1,    70,    -1,
      54,   283,   362,   284,    -1,    53,   283,   362,   284,    -1,
      -1,    94,   283,   363,   364,   297,   284,    -1,    91,   283,
     365,   284,    -1,   256,   341,    -1,   372,     9,   256,   341,
      -1,    47,   283,   368,   284,    -1,   369,    -1,   368,    -1,
     253,   369,   254,    -1,   362,    -1,   370,    -1,   369,   258,
     362,    -1,   369,   258,   370,    -1,   372,   249,   250,    -1,
     372,   255,   349,   249,   250,    -1,   372,     9,   372,   255,
     349,   249,   250,    -1,     4,   257,   253,   341,   254,    -1,
     371,   257,   253,   341,   254,    -1,   221,   251,   362,   252,
     257,   253,   341,   254,    -1,     4,    -1,   371,    -1,   221,
     251,   362,   252,    -1
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
    3266,  3273,  3285,  3358,  3376,  3401,  3416,  3449,  3461,  3485,
    3489,  3494,  3501,  3506,  3516,  3521,  3527,  3535,  3539,  3543,
    3547,  3551,  3555,  3559,  3568,  3632,  3648,  3665,  3682,  3704,
    3726,  3761,  3769,  3777,  3783,  3790,  3797,  3817,  3843,  3855,
    3866,  3884,  3902,  3921,  3920,  3945,  3944,  3971,  3970,  3995,
    3994,  4017,  4033,  4050,  4067,  4090,  4118,  4121,  4127,  4139,
    4159,  4163,  4167,  4171,  4175,  4179,  4183,  4187,  4196,  4209,
    4210,  4211,  4212,  4213,  4217,  4218,  4219,  4220,  4221,  4224,
    4248,  4267,  4290,  4293,  4309,  4312,  4329,  4332,  4338,  4341,
    4348,  4351,  4358,  4380,  4421,  4465,  4504,  4529,  4541,  4553,
    4565,  4577,  4586,  4616,  4642,  4668,  4700,  4727,  4753,  4779,
    4805,  4831,  4853,  4864,  4912,  4966,  4981,  4993,  5004,  5011,
    5026,  5040,  5041,  5042,  5046,  5052,  5064,  5082,  5110,  5111,
    5112,  5113,  5114,  5115,  5116,  5117,  5118,  5125,  5126,  5127,
    5128,  5129,  5130,  5131,  5132,  5133,  5134,  5135,  5136,  5137,
    5138,  5139,  5140,  5141,  5142,  5143,  5144,  5145,  5146,  5147,
    5148,  5149,  5150,  5151,  5152,  5153,  5154,  5155,  5156,  5157,
    5158,  5159,  5160,  5161,  5162,  5171,  5172,  5173,  5174,  5175,
    5176,  5177,  5178,  5179,  5180,  5181,  5186,  5185,  5193,  5195,
    5200,  5205,  5209,  5214,  5219,  5223,  5227,  5231,  5235,  5239,
    5243,  5249,  5264,  5268,  5274,  5279,  5298,  5318,  5349,  5353,
    5357,  5361,  5365,  5369,  5373,  5378,  5388,  5398,  5403,  5414,
    5423,  5428,  5433,  5461,  5462,  5468,  5469,  5475,  5474,  5497,
    5499,  5504,  5513,  5515,  5521,  5522,  5527,  5531,  5535,  5539,
    5543,  5550,  5554,  5558,  5562,  5569,  5574,  5581,  5586,  5590,
    5595,  5599,  5607,  5618,  5622,  5626,  5640,  5648,  5656,  5663,
    5673,  5696,  5701,  5707,  5712,  5718,  5729,  5735,  5741,  5747,
    5759,  5773,  5783,  5793,  5803,  5815,  5819,  5824,  5836,  5840,
    5844,  5848,  5866,  5874,  5882,  5911,  5921,  5937,  5948,  5953,
    5957,  5961,  5973,  5977,  5989,  6006,  6016,  6020,  6035,  6040,
    6047,  6051,  6056,  6070,  6086,  6090,  6094,  6098,  6102,  6110,
    6116,  6125,  6129,  6133,  6141,  6147,  6153,  6157,  6165,  6173,
    6180,  6189,  6193,  6197,  6212,  6226,  6240,  6252,  6268,  6277,
    6286,  6296,  6307,  6315,  6323,  6327,  6346,  6353,  6359,  6366,
    6374,  6373,  6383,  6407,  6409,  6415,  6420,  6422,  6427,  6432,
    6437,  6439,  6443,  6455,  6469,  6473,  6480,  6488,  6496,  6507,
    6509,  6512
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
  "tMeshAlgorithm", "tReverseMesh", "tLayers", "tScaleLast", "tHole",
  "tAlias", "tAliasWithOptions", "tCopyOptions", "tQuadTriAddVerts",
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
     475,   476,   477,   478,   479,   480,    63,   481,   482,   483,
     484,    60,    62,   485,   486,   487,   488,    43,    45,    42,
      47,    37,   124,    38,    33,   489,   490,   491,    94,    40,
      41,    91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   259,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   265,   265,
     266,   266,   266,   266,   266,   266,   267,   267,   268,   268,
     270,   271,   269,   272,   272,   274,   273,   275,   275,   277,
     276,   278,   278,   280,   279,   281,   281,   281,   281,   281,
     282,   282,   283,   283,   284,   284,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   286,   286,   287,   287,   287,   288,   287,
     289,   287,   287,   290,   287,   291,   291,   292,   292,   292,
     293,   293,   294,   294,   295,   295,   296,   296,   296,   296,
     296,   297,   297,   298,   298,   299,   299,   299,   299,   299,
     300,   300,   300,   301,   301,   301,   301,   302,   302,   303,
     303,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   305,   304,   306,   306,   306,
     306,   306,   307,   307,   307,   307,   308,   308,   308,   309,
     309,   309,   309,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   314,   314,   314,   314,   314,   314,   314,
     314,   315,   315,   316,   317,   317,   317,   317,   317,   317,
     317,   317,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   321,   321,   322,   321,   323,   321,   324,   321,   325,
     321,   321,   321,   321,   321,   321,   326,   326,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   328,
     328,   328,   328,   328,   329,   329,   329,   329,   329,   330,
     330,   331,   332,   332,   333,   333,   334,   334,   335,   335,
     336,   336,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   338,   338,
     338,   339,   339,   339,   340,   340,   340,   340,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   343,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   344,   344,   345,   345,   347,   346,   348,
     348,   349,   350,   350,   351,   351,   352,   352,   352,   352,
     352,   353,   353,   353,   353,   354,   354,   355,   355,   355,
     355,   355,   355,   356,   356,   356,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   358,   358,
     358,   358,   359,   359,   359,   359,   360,   360,   361,   361,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     364,   363,   363,   365,   365,   366,   367,   367,   368,   369,
     369,   369,   369,   370,   370,   370,   371,   371,   371,   372,
     372,   372
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
       8,     8,     5,     4,     6,    11,    11,    18,    18,    12,
      12,    12,    10,     4,     4,     4,     4,     4,     2,     3,
       6,     1,     1,     1,     2,     5,     7,    10,     1,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     1,     4,
       6,     1,     4,     4,     4,     6,     5,     7,     8,    10,
       4,     4,     6,     4,     3,     2,     5,     5,     3,     5,
       6,     8,     6,     8,     6,     4,     7,     6,     6,     6,
       4,     6,     4,     0,     2,     0,     2,     0,     7,     1,
       3,     1,     1,     2,     0,     3,     1,     2,     2,     3,
       3,    11,     9,     7,     7,     1,     3,     1,     1,     2,
       3,     4,     5,     1,     3,     1,     2,     3,     3,     5,
       4,     4,     2,     4,     2,     3,     3,    16,     5,     5,
       5,     1,     1,     1,     3,     5,     7,     4,     4,     4,
       6,     6,     8,     8,     4,    14,     4,     4,     1,     1,
       3,     3,     9,     7,     1,     5,     3,     6,     1,     3,
       1,     1,     4,     4,     3,     5,     6,     8,     6,     4,
       5,     1,     4,     1,     1,     1,     1,     4,     6,     4,
       6,     5,     7,     4,     4,     4,     8,     4,     4,     4,
       4,     8,     8,     6,     4,     6,     4,     1,     4,     4,
       0,     6,     4,     2,     4,     4,     1,     1,     3,     1,
       1,     3,     3,     3,     5,     7,     5,     5,     8,     1,
       1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   619,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
       0,     0,   198,     0,     0,   199,     0,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   329,   330,   331,   332,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   290,     0,
       0,   298,   299,     0,     0,     0,   293,     0,     0,     0,
       0,     0,   381,   382,   383,     0,     0,     5,     6,     7,
       8,    10,     0,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   620,     0,   224,     0,     0,     0,     0,     0,     0,
     273,     0,   275,   276,   271,   272,     0,   277,   280,     0,
     281,   282,   115,   125,   619,   494,   489,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   283,     0,   209,
     210,   211,     0,     0,     0,     0,   435,   436,   438,   439,
     437,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   443,   444,   445,
       0,     0,   197,   202,   203,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   440,   441,   442,
       0,     0,     0,     0,     0,     0,     0,     0,   531,   532,
       0,   533,   507,   388,   448,   451,   312,   508,   489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   198,
     199,   200,   195,   202,   203,     0,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   619,     0,     0,   224,     0,     0,   378,
       0,     0,     0,   206,   207,     0,     0,     0,     0,     0,
     515,     0,     0,   513,     0,     0,     0,     0,     0,   619,
       0,     0,   554,     0,     0,     0,     0,   269,   270,     0,
     571,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   573,     0,   597,   575,   576,     0,
       0,     0,     0,     0,     0,   574,     0,     0,     0,     0,
     291,   292,     0,   224,     0,   224,     0,     0,     0,   489,
       0,     0,     0,   224,   384,     0,     0,    78,     0,    65,
       0,     0,    69,    68,    67,    66,    71,    70,    72,    73,
       0,     0,     0,     0,     0,     0,     0,   560,   489,     0,
     223,     0,   222,     0,   176,     0,     0,   560,   561,     0,
       0,     0,   609,     0,   610,   561,     0,   113,   113,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   548,   549,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,     0,   390,   516,   392,     0,   509,     0,     0,   489,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,     0,   465,     0,     0,
       0,     0,     0,     0,     0,   313,     0,   346,   346,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,   224,   224,     0,   498,   497,     0,     0,     0,
       0,   224,   224,     0,     0,     0,     0,   309,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,   224,   250,     0,
       0,   248,   379,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   356,   268,     0,     0,     0,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,   294,     0,
     255,     0,     0,   257,     0,     0,     0,   390,     0,   224,
       0,     0,     0,     0,     0,     0,     0,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    74,    75,     0,     0,     0,   266,    40,   262,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,     0,
     225,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,   492,     0,     0,   490,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   340,     0,     0,     0,   201,     0,     0,     0,     0,
       0,     0,   374,   375,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,   464,     0,     0,
       0,     0,   525,   526,     0,     0,     0,     0,     0,   483,
       0,   389,   510,     0,     0,     0,     0,   518,     0,   408,
     407,   406,   405,   401,   402,   409,   410,   404,   403,   394,
     393,     0,   395,   517,   396,   399,   397,   398,   400,   490,
       0,     0,   491,   468,     0,   534,     0,     0,     0,     0,
       0,     0,     0,     0,   344,     0,     0,     0,     0,     0,
       0,   377,     0,     0,     0,     0,   376,     0,   224,     0,
       0,     0,     0,     0,   500,   499,     0,     0,     0,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   363,     0,     0,
     249,     0,     0,     0,   243,     0,     0,     0,     0,   373,
       0,     0,     0,   389,   514,     0,     0,     0,     0,     0,
       0,     0,     0,   296,   297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   600,     0,     0,     0,   485,     0,     0,
     254,   258,   256,   260,     0,   395,     0,   490,   468,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
       0,     0,   389,     0,    65,     0,     0,     0,     0,    81,
       0,    65,    66,     0,     0,     0,   490,     0,     0,   468,
       0,     0,     0,   195,     0,     0,     0,   616,    28,    26,
      27,     0,     0,     0,     0,     0,   491,   564,    30,     0,
      29,     0,     0,   263,   611,   612,     0,   613,   564,     0,
      76,   116,    77,   126,   493,   495,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,   551,   212,     9,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   434,   421,     0,
     423,   424,   425,   426,   427,   547,   428,   429,   430,     0,
       0,     0,   539,   538,   537,     0,     0,     0,   544,     0,
     480,     0,     0,     0,   482,     0,     0,     0,   130,   463,
     521,   520,   205,     0,     0,   449,   546,   454,     0,   460,
       0,     0,     0,     0,   511,     0,     0,   461,     0,   523,
       0,     0,     0,     0,   453,   452,   475,    72,    73,     0,
       0,     0,     0,     0,     0,     0,   389,   342,   347,   345,
       0,   355,     0,   150,   151,     0,   205,     0,   389,     0,
       0,     0,     0,   244,     0,   259,   261,     0,     0,     0,
     213,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   316,     0,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,     0,   349,   362,
       0,     0,     0,   245,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     0,
       0,     0,   587,     0,   594,   583,   584,   585,     0,   599,
     598,     0,     0,   588,   589,   590,   596,   603,   602,     0,
     141,     0,   577,     0,   579,     0,     0,     0,   572,     0,
     253,     0,     0,     0,     0,     0,     0,     0,   335,     0,
       0,     0,   385,     0,   617,     0,   103,    65,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,   569,    50,     0,     0,     0,    63,
       0,    41,    42,    43,    44,    45,     0,   453,   452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   563,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,   133,   134,     0,     0,     0,     0,
       0,     0,     0,   157,   157,     0,     0,     0,     0,     0,
     153,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,   529,   530,     0,     0,     0,
       0,     0,   483,   484,     0,   456,     0,     0,     0,   519,
     411,   512,   469,   467,     0,   466,     0,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   354,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,   321,     0,     0,   320,
       0,   323,     0,   325,     0,   310,   317,     0,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,     0,   247,   246,   380,     0,     0,    37,    38,     0,
       0,     0,     0,   555,     0,     0,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,   486,   581,     0,   469,     0,     0,   224,   336,
       0,   337,   224,     0,     0,   570,     0,    88,     0,     0,
       0,     0,    86,    93,    95,     0,   558,     0,   101,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,    36,
     469,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,   565,     0,     0,    34,
      33,     0,   565,   614,     0,     0,   117,   122,     0,     0,
       0,   136,   139,   140,   488,     0,    79,     0,     0,     0,
       0,    80,   161,     0,     0,     0,     0,   162,   179,   180,
     159,     0,     0,     0,   163,   190,   181,   185,   186,   182,
     183,   184,   171,     0,     0,   422,   431,   432,   433,   540,
       0,     0,     0,   478,   479,   481,   131,   447,   477,   450,
     455,     0,     0,   483,   191,   462,     0,    72,    73,     0,
     474,   470,   472,   541,   187,     0,     0,     0,   153,     0,
       0,   353,     0,   152,     0,     0,     0,     0,     0,     0,
     267,     0,     0,     0,     0,   224,   224,     0,     0,   322,
     507,     0,     0,   324,   326,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   218,   188,
       0,     0,     0,     0,   168,   169,     0,     0,     0,     0,
     104,   105,   106,   110,     0,   595,     0,     0,   593,     0,
     604,     0,     0,   142,   143,   601,   578,   580,     0,     0,
       0,     0,     0,     0,   334,   338,   334,     0,   386,    87,
      65,     0,     0,     0,     0,    85,     0,   556,     0,     0,
       0,     0,     0,     0,   607,   606,     0,     0,     0,     0,
       0,   505,     0,     0,   474,   264,   470,   265,     0,     0,
       0,     0,     0,   229,   226,     0,     0,   568,   566,     0,
       0,     0,     0,   118,   123,     0,     0,     0,   548,   549,
     135,   357,   358,   359,   360,   158,   166,   167,   172,     0,
       0,     0,     0,     0,   174,     0,     0,     0,     0,     0,
       0,   457,     0,     0,     0,     0,   536,   476,     0,     0,
     173,     0,   192,   343,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,     0,   504,   503,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   240,     0,
       0,     0,     0,     0,     0,     0,     0,   231,     0,     0,
     361,    39,     0,   553,     0,     0,   288,   287,     0,     0,
       0,     0,     0,     0,   145,   146,   149,   148,   147,     0,
     582,     0,   618,     0,     0,     0,     0,     0,     0,    98,
       0,     0,    99,   559,     0,     0,     0,    90,     0,     0,
       0,    46,     0,     0,     0,     0,     0,    48,     0,   230,
     227,   228,    35,     0,     0,   615,   278,     0,   130,   141,
       0,     0,   138,     0,     0,     0,   160,   189,     0,     0,
       0,     0,     0,   542,   543,     0,   483,   458,     0,   471,
     473,     0,     0,   175,   196,     0,     0,     0,   350,   350,
       0,   111,   112,   224,     0,   216,   217,   311,     0,   318,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,   221,   220,     0,     0,     0,     0,   107,   108,   586,
     592,   591,   144,     0,     0,     0,   339,     0,    94,    96,
       0,   102,     0,    84,   608,    91,    92,    51,     0,     0,
       0,     0,   506,     0,     0,   471,   567,     0,     0,     0,
       0,   120,   605,     0,   127,     0,     0,     0,     0,   178,
       0,     0,     0,     0,   314,     0,   164,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   502,     0,
     328,     0,     0,   305,     0,   232,     0,     0,     0,     0,
       0,     0,     0,   552,   289,     0,     0,   372,   224,   387,
       0,   557,     0,    47,     0,     0,     0,    64,    49,     0,
     279,   119,   124,   130,     0,     0,   155,   156,   154,     0,
       0,   459,     0,     0,     0,     0,     0,   351,   365,     0,
       0,   366,     0,   214,     0,   319,     0,   301,     0,   224,
       0,     0,     0,     0,     0,     0,   170,   109,   285,   334,
     100,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,   194,     0,   369,     0,   370,   371,   501,
       0,     0,   307,   235,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,    61,     0,     0,   121,     0,     0,
       0,   315,     0,     0,   327,   306,   302,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   237,   238,   239,
       0,   233,   341,    52,     0,    59,     0,   274,     0,   545,
       0,     0,     0,   308,     0,     0,    53,     0,     0,   284,
       0,     0,     0,   234,     0,     0,     0,     0,   527,     0,
       0,    56,    54,     0,    57,     0,   367,   368,     0,     0,
      62,    60,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   117,  1071,   118,   119,  1055,  1910,  1916,
    1351,  1564,  2072,  2205,  1352,  2176,  2223,  1353,  2207,  1354,
    1355,  1568,   441,   597,   598,  1144,   120,   783,   467,  1928,
    2083,  1929,   468,  1797,  1428,  1383,  1384,  1385,  1528,  1733,
    1734,  1212,  1623,  1614,  1810,   760,   609,   276,   277,   356,
     203,   278,   451,   452,   124,   125,   126,   127,   128,   129,
     130,   131,   279,  1246,  2108,  2167,   951,  1242,  1243,   280,
    1034,   281,   135,  1457,  1210,   924,   966,  2042,   136,   137,
     138,   139,   282,   283,  1168,  1183,  1307,   284,   788,   285,
     913,   787,   470,   626,   324,  1770,   363,   364,   287,   567,
     371,  1338,  1557,   462,   457,  1300,  1011,  1603,  1763,  1764,
     996,   464,   141,   419
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1900
static const yytype_int16 yypact[] =
{
   12948,    51,    47, 13109, -1900, -1900,   -64,    58,   -18,  -131,
    -122,  -111,    30,   203,   217,   247,   255,   -35,   329,   345,
      45,   354,   390,    52,   195,    24,   308,   361,   308,   178,
     205,   249,    20,   259,   271,    66,   319,   353,   401,   409,
     415,   420,   427,   449,   478,   515,   519,   690,   730,   818,
     609,   612,   780,   644,  6647,   648,   647,   677,   803,   -46,
     135,   542,    -6,   154,   672,   826,   -65,   731,  -128,  -128,
     744,   264,   720,   788, -1900, -1900, -1900, -1900, -1900,   695,
     463,   877,   901,    17,    57,   909,   942,   633,  1045,  1053,
    1056,  4702,  1060,   821,   832,   833,    10,    69, -1900,   834,
     835, -1900, -1900,  1067,  1082,   838, -1900,  1791,   841,  2744,
      36,    37, -1900, -1900, -1900, 11664,   843, -1900, -1900, -1900,
   -1900, -1900,   839, -1900, -1900, -1900, -1900, -1900, -1900, -1900,
   -1900, -1900, -1900,   208, -1900, -1900, -1900, -1900,    13, -1900,
    1085,   836,  5657,   476,   844,  1089, 11664, 13287, 13287, 13287,
   -1900, 11664, -1900, -1900, -1900, -1900, 13287, -1900, -1900, 11664,
   -1900, -1900, -1900, -1900,   846,   847,  1090, -1900, -1900,  5754,
     849,   851,   858,   869,    24, 11664, 11664, 11664,   870, 11664,
   11664, 11664,   872, 11664, 11664, 11664, 11664, 11664, 11664, 11664,
   13287, 11664, 11664, 11664, 11664,  4702,   873, -1900,  9354, -1900,
   -1900, -1900,   874,  4702,  6894, 13287, -1900, -1900, -1900, -1900,
   -1900,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   334,   308,   308,   308,   308,   308,
     875,   308,   308,   876,   542,   614,   614, -1900, -1900, -1900,
     308,   308,    43,   936,   939,   943,   878,  6894,  1002,   542,
     542,   883,   308,   308,   884,   885,   886, -1900, -1900, -1900,
   11664,  7141, 11664, 11664,  7388,    24,   949,    44, -1900, -1900,
     887, -1900,  4460, -1900, -1900, -1900, -1900, -1900,    62, 11664,
    9354,  9354,   889,   890,  7635,  4702,  4702,  4702, -1900, -1900,
   -1900, -1900, -1900, -1900, -1900,   892, -1900,   893,   894,  7882,
     896, 10269,  1138,  6894,   897,    10,   898,   899,  -128,  -128,
    -128, 11664, 11664,  -124, -1900,  -106,  -128, 10352,   256,   238,
     904,   905,   906,   907,   908,   912,   913,  9354, 11664,  4702,
    4702,  4702,   914,    22,  1139,   928, -1900,  1141,  1158, -1900,
     932,   933,   934, -1900, -1900,   937,  4702,   930,   938,   940,
   -1900, 11664,  5906, -1900,  1182,  1186, 11664, 11664, 11664,   457,
   11664,   941, -1900,  1006, 11664, 11664, 11664, -1900, -1900, 11664,
   -1900,   308,   308,   308,   946,   947,   948,   308,   308,   308,
     308,   308,   308,   308, -1900,   308, -1900, -1900, -1900,   308,
     308,   952,   953,   308,   954, -1900,   955,  1198,  1199,   956,
   -1900, -1900,  1201,  1200,  1204,  1203,   308, 11664, 10881,   103,
   13287,  9354, 11664, -1900, -1900,  6894,  6894, -1900,   960,  5754,
     542,  1207, -1900, -1900, -1900, -1900, -1900, -1900, 11664, 11664,
      42,  6894,  1209,   708,   966,   737,   973,  1225,    31,   979,
   -1900,   982, 13413, 11664, -1900,  1206,  -171, -1900,    92,   -92,
     174,  6830, -1900,   213, -1900,   106,  7077,   -88,   104,  1144,
   -1900,    24,   980, 11664, 11664, 11664, 11664,   985, 15324, 15349,
   15374, 11664, 15399, 15424, 15449, 11664, 15474, 15499, 15524, 15549,
   15574, 15599, 15624,   990, 15649, 15674, 15699, 13937,  1237, 11664,
    9354,  4827, -1900,   306, 11664,  1240,  1241,   998, 11664, 11664,
   11664, 11664, 11664, 11664, 11664, 11664, 11664, 11664, 11664, 11664,
   11664, 11664, 11664, 11664,  9354, 11664, 11664, 11664, 11664, 11664,
   11664,  9354,  9354,   999, 11664, 11664, 13287, 11664, 13287,  6894,
   13287, 13287, 13287,  1000,  1004,  1005, 11664,    64, -1900, 10599,
   11664,  6894,  4702,  6894, 13287, 13287,  9354,    24,  5754,    24,
    1003,  9354,  1003, -1900,  1003, 15724, -1900,   347,  1007,   139,
    1194, -1900,  1252, 11664, 11664, 11664, 11664, 11664, 11664, 11664,
   11664, 11664, 11664, 11664, 11664, 11664, 11664,  8129, 11664, 11664,
   11664, 11664, 11664,    24, 11664, 11664,  1257, -1900,   824, 15749,
     357,   372, 11664, 11664, 11664, -1900,  1256,  1258,  1258,  1015,
   11664, 11664, 11664, 11664,  1260,  9354,  9354, 14836,  1017,  1262,
   -1900,  1019, -1900, -1900,  -132, -1900, -1900,  7324,  7571,  -128,
    -128,   476,   476,  -121, 10352, 10352, 11664,   472,   -75, -1900,
   11664, 11664, 11664, 11664, 11664, 11664, 11664, 11664, 11664,   465,
   15774,  1266,  1269,  1271, 11664,  1270, 11664, -1900, -1900, 11664,
   12062, -1900, -1900,  9354,  9354,  9354, 11664,  1276, 11664, 11664,
   11664, 15799,  1029, -1900, -1900, 15824, 15849, 15874,  1100,  7818,
   -1900,  1033,  4850, 15899, 15924, 14919, 13287, 13287, 13287, 13287,
   13287, 13287, 13287, 13287, 13287, 11664, 13287, 13287, 13287, 13287,
       3,  5754, 13287, 13287, 13287,    24,    24, -1900, -1900,  9354,
   -1900,  1034, 12120, -1900,  1036, 12225, 11664,  1003, 11664, -1900,
      24, 11664, 11664,  1257,  1035,   490, 15949, 13308,  1041,   498,
   11664,  1287,  1042,  6894, 15974, 14946,   206,  1039,  1294,  1296,
   -1900, -1900, -1900,  9354,    25, 11664, -1900, -1900, -1900,    24,
   11664, 11664,  1257,  1054, -1900,  1055,   -42,   542,    -6,   542,
   -1900,  1057, 13966, -1900,   159,  9354,    24, 11664, 11664,  1305,
    1300,  9354,  1307,  9354, 11664,  1308, 13287,    24, 10682,  1305,
   11664,  1309, -1900,    24,  1311, 13287, 11664,  1061,  1068, -1900,
   11664,  8065,  8312,  8554,  8796,  5754,  1313,  1314,  1315, 15999,
    1316,  1317,  1318, 16024,  1319,  1320,  1322,  1323,  1324,  1325,
    1326, -1900,  1328,  1329,  1330, -1900, 11664, 16049,  9354,  1086,
    9354, 13995, -1900, -1900,  1332, 14892, 14892, 14892, 14892, 14892,
   14892, 14892, 14892, 14892, 14892, 14892,  9043, 14892, 14892, 14892,
   14892,   558,   517, 14892, 14892, 14892,  9290,  9627,  9966,  4827,
    1091,  1088,    93,  9354, 10219, 10301,   517, 10549,   517,  1084,
    1087,  1092,   223,  9354, 11664, 11664, 16999, -1900,   517,  1093,
   14024, 14053, -1900, -1900,  1094,   358,   517,  -127,  1096,   419,
     525,  1337, -1900,  1305,   517,  1095,  1097,  4883,  5089,  1499,
    1530,   935,   935,   676,   676,   676,   676,   676,   676,  -165,
    -165,  9354,   518, -1900,   518,   518,  1003,  1003,  1003,  1098,
   16074, 14973,   435,   553,  9354, -1900,  1342,  1101,  1103, 16099,
   16124, 16149, 11664,  6894,  1353,  1352, 10027, 16174, 14082, 16199,
   16224, -1900,   562,   579,  9354,  1104, -1900, 12283, -1900, 12341,
   12399,  -128, 11664, 11664, -1900, -1900,  1107,  1109, 10352,  4733,
    1226,   318,  -128, 12457, 16249, 14111, 16274, 16299, 16324, 16349,
   16374, 16399, 16424,  1112,  1359, 11664,  1361, -1900, 11664, 16449,
   -1900, 15000, 12515, 15027, -1900,   587,   594,   595, 14140, -1900,
   15054, 15081, 10631, -1900, -1900,  1362,  1363,  1364,  1113, 11664,
   12573, 11664, 11664, -1900, -1900,    49,   383,   483,   383,  1122,
    1124,  1117,   517,   517,  1118, 10955,   517,   517,   517,   517,
   11664,   517,  1368, -1900,  1120,  1130,   495,   484,  1129,   600,
   -1900, -1900, -1900, -1900, 14892,   518, 12631,  1127,   570,  1126,
    1197,  1378,  1227, 10924,  1133,  1135,  1383,  6894, 14169, -1900,
   11664,  1384,   253,    77,  5754, 11664,  1385,  1389,    23, -1900,
     601,  1347,  1348,  6894, 14198,    41,  1142, 16474, 15108,   292,
   11664, 11664,  1149,  1146,  1151,  1148,  8376, -1900, -1900, -1900,
   -1900, 13287,   260,  1147, 16499, 15135, -1900,  1154, -1900,   269,
   -1900,   284, 11206, -1900, -1900, -1900,  1150, -1900,  1155, 11288,
   -1900,    82, -1900, -1900, 16999, -1900,  1402, 14892, 11664, 11664,
   11664, 11664,   517,  -128,  6894,  6894,  1401,  6894,  6894,  6894,
    1404,  6894,  6894,  6894,  6894,  6894,  6894,  6894,  6894,  6894,
    6894,  1275,  1405,  9354,  4827, -1900, -1900, -1900, -1900, -1900,
   -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900, 11664,
   -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900, 11664,
   11664, 11664, -1900, -1900, -1900,   630, 11664, 11664, -1900, 11664,
   -1900,  6894, 13287, 13287, -1900,   636, 14227, 14256,  1157, -1900,
   -1900, -1900,  1222, 11664, 11664, -1900, -1900, -1900,  1305, -1900,
    1305, 11664, 11664,  1166, -1900,  6894,   308, -1900, 11664, -1900,
   11664, 11664,   637,  1305,   435,   -12, -1900, 11664, 11664,   517,
     638,  6894,  9354,  9354,  1410,  1411,  1412,  2471, -1900, -1900,
    1414, -1900,  1171, 16999,  1165,  1418, -1900,  1419,  1420,  1421,
    1422,   645,  1426, -1900, 12689, -1900, -1900,   -70, 11531, 11613,
   -1900, -1900, 14285,    -8,  1339,  1452, 11014,  1208,  1451,  1213,
      27,    38,   -74, -1900,   -60, -1900,   318,  1456,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,   476,  6894, 16999, -1900,
    1302,  1214,  1470, -1900,  1471,  1472,  1375,  1473, -1900,  1475,
    1476, 11664,  6894,  6894,  6894,  1479, 11874, -1900,  5347,   639,
      33,  1480, -1900,  9354, -1900, -1900, -1900, -1900, 13287, -1900,
   -1900, 11664, 13287, -1900, -1900, -1900, -1900, 16999, -1900,  1229,
    1230, 13287, -1900, 13287, -1900,  1305, 13287,  1239, -1900,  1232,
   -1900,  1305, 11664, 11664,  1234,   542,  1238, 11256, -1900,  2045,
    1242,  6894, -1900,  1243, -1900, 14314, -1900, -1900, 11664,  1487,
      48, 11664,  1490,  1493,  2164, -1900,  1513,    10,  1494,  1273,
     517,   308,   308,  1515, -1900, -1900,  1278,  1297,  1272, -1900,
    1516, -1900, -1900, -1900, -1900, -1900,  1305,   -71,  2133, 11664,
   15162, 16524, 11664,  8618, 11664,  9354,  1293,   651,  1542,   188,
    1305, -1900,  1298, 11664,  1543,  1545, 11664,  1305, 11339, 11664,
    9596,   517,  5147,  1303,  1299, -1900,  1548, 16549, 16574, 16599,
   16624,  1550,    19,  1429,  1429,  6894,  1555,  1556,  1557,  6894,
     -84,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,
   -1900,  1569,   652, 14892, 14892, 14892, 14892,   517, 12050, 12739,
   13343,  1327,   517,   517, -1900, -1900, -1900,  1402,   517, 16649,
   14892,  1331,   -77, 16999, 14892, -1900,  1570,   517, 13376, 16999,
   16999, -1900,   634, -1900,  1571, -1900, 16674, 15189, -1900,   517,
    1573,   654,   668,  6894,  6894,  6894,  1576,  1577, -1900,   212,
   11664,  6894,  6894,  6894,  1333,  1334,  1578,   771, -1900, 11664,
   11664, 11664,  1335,  1336,  1338,  1344, -1900,  2241,  6894, -1900,
   11664, -1900,  1587, -1900,  1590, -1900, -1900, 10352,   -14,  6153,
   -1900,  1345,  1346,  1354,  1356,  1357,  1358,  8860,  1360,  1594,
   -1900,  9354, -1900, -1900, -1900,  1365, 11664, -1900, -1900, 15216,
    1595,  1606,  1423, -1900, 11664, 11664, 11664, -1900,  1609,  1610,
    1613,   840,   499,  1366,  5842,  1367, 11664,    26,   517,  1370,
     517,  1369, -1900, -1900,  5754,   686, 11664,  1373, -1900, -1900,
    2407, -1900, -1900,  1372,  1616, -1900,  2854, -1900,   589,  1376,
    1625,  3004, -1900, -1900, -1900,    10, -1900,   674, -1900, 11664,
     212, 11878, 11938, -1900,  1374, 11664, 11664,  6894,  1381, -1900,
     554,  1580,  1629, 16699,  1630,  1337, 16724,  1386,   675, 16749,
     680,  1631,  1632, -1900, -1900, 13287,  1390,  1637, 16774, -1900,
   -1900, 13409,  1393, -1900,  4313,  5410, 16999, -1900,  1636,   308,
    7388, -1900, -1900, -1900, -1900,  1402, -1900,  1638,  1639,  1640,
    1642, -1900, -1900,  -128,  1643,  1644,  1645, -1900, -1900, -1900,
    1514,   -48,  1551,  1648, -1900, -1900, -1900, -1900, -1900, -1900,
   -1900, -1900, -1900,  1650,  1403, -1900, -1900, -1900, -1900, -1900,
   11664, 11664, 11664, -1900, -1900, -1900,  1299, -1900, -1900, -1900,
   -1900, 11664,  1407,  1400, -1900, -1900, 11664, 11664, 11664,   517,
     435, -1900, -1900, -1900, -1900,  1406,  1408,  1656,   -84,  1657,
   11664, -1900,  6894, 16999,  1526,  1527,   857,  9354,  9354, 11664,
   -1900, 10027, 14343, 16799,  6089,   476,   476, 11664, 11664, -1900,
     141,  1409, 16824, -1900, -1900, 14372,   -52, -1900,  1660,  1662,
    6894,  -128,  -128,  -128,  -128,  -128,  6400,  1664, -1900, -1900,
     682, 11664,  3054,  1665, -1900, -1900,  6894,  6336,   171, 16849,
   -1900, -1900, -1900, -1900,  9688, -1900, 13287, 11664, -1900, 13287,
   16999,  9935,  5754,  1415, -1900, -1900, -1900, -1900,  1427,  1424,
   11664, 11664, 14401, 11664, 13308, -1900, 13308,  6894, -1900, -1900,
    5754, 11664,  1666,  1672,    23, -1900,  1674, -1900,    10, 15243,
    6894, 13287,  1675,   517, -1900,  1430,   517, 11664, 13442, 13475,
     688, -1900, 11664, 11664,   512, -1900,  1425, -1900,  1412,  1678,
    1681,  1420,  1683, -1900, -1900,  1684, 11664, -1900, -1900, 11664,
   11581,  1685, 11664, -1900, -1900,  1439, 11938,   689,  3150,  1689,
   -1900, -1900, -1900, -1900, -1900,   842, -1900, -1900, -1900,  1558,
    1692,  1446,  1448,  1449, -1900,  1699,  6894, 14892, 14892, 13508,
   14892, -1900,  1455, 13541, 16874, 15270, -1900, -1900,  9354,  9354,
   -1900,  1700, -1900, 16999,  1701, 11664, 11664,  1457, -1900,   691,
     696, 14864,  3395,  1702,  1458, -1900, -1900, 11664,  1468,  1489,
   14430, 15297,  1703,  6894,  1705,  1492, 11664, -1900, -1900,   698,
     -47,   -30,   -16,   202,   232,  9107,   258, -1900,  1708, 14459,
   -1900, -1900,  1533, -1900, 11664, 11664, -1900, -1900,  9354,  3420,
    1710,  1469, 14892,   517, 16999, -1900, -1900, -1900, -1900,    26,
   -1900,  5754, -1900, 14488,  1495,  1496,  1498,  1711,  3717, -1900,
    1713,  1712, -1900, -1900,  1491,  1715,   699, -1900,  1718,  1719,
     297, 16999, 11664, 11664,  1500,  6894,   701, 16999, 16899, -1900,
   -1900, -1900, -1900, 16924, 13574, -1900, -1900, 14517,  1157,  1230,
    6894,   517, -1900, 11664,  5754,    24, -1900, -1900,  9354,  9354,
   11664,  1742,   728, -1900, -1900, 11664,  1400, -1900, 11664, -1900,
   -1900,   729,   749, -1900, -1900,  3790,  3972,  6894,   176,   632,
    9354, -1900, -1900,   476,  6583, -1900, -1900, -1900,  1748, -1900,
    1502,  6894, -1900, 14546,  1768,  9354,  -128,  -128,  -128,  -128,
    -128, -1900, -1900, 11664, 14575, 14604,   754, -1900, -1900, -1900,
   -1900, -1900, -1900,  1529,  1770,  1524, -1900,  1774, -1900, -1900,
      10, -1900,  1596, -1900, -1900, -1900, -1900, -1900, 11664, 13607,
   13640,  6894, -1900,  1776, 11664,  1531, -1900, 11664,  1777,  1532,
    1535, -1900, -1900,  4417, -1900,  1536,   755,   757, 14633, -1900,
    1534, 13673,  1540, 13706, -1900,  1538, -1900, -1900,   762,  1539,
    -128,  6894,  1793,  1544,  -128,  1794,   764,  1547, -1900, 11664,
   -1900,  1796,  1667, 12747,  1553, -1900,   765,   266,   268,   274,
     356,   380,  4093, -1900, -1900,  1797,  1798, -1900, -1900, -1900,
    1801, -1900,  1568, 16999, 11664, 11664,   767, -1900, 16999, 13739,
   -1900, -1900, -1900,  1157,  5754,  1572, -1900, -1900, -1900, 11664,
   11664, -1900, 11664,  9354,  1802,  -128,   128, -1900, -1900,  -128,
     148, -1900,  1804, -1900, 14662, -1900, 11664, -1900,   318, -1900,
    1805,  9354,  9354,  9354,  9354,  9107, -1900, -1900, -1900, 13308,
   -1900, 11664, 16949, 13772,    54, 11664,  1574, -1900, -1900, 13805,
   13838, 13871,   770, -1900,   386, -1900,   391, -1900, -1900, -1900,
    4389,   277, 12805, -1900,   772,   773,   779,   781,   417,   782,
    1575,   784, -1900, 11664, -1900,  6894, 14691, -1900, 11664, 11664,
   11664, -1900,  -128,  -128, -1900, -1900, -1900,   318,  1806,  1808,
    1809,  1811,  9354,  1812,  1814,  1818,  1582, 16974,   789,  1821,
   14720, 14892, 13904,   467,   470,   501, -1900, -1900, -1900, -1900,
     790, -1900, -1900, -1900, 13287, -1900,  1583, -1900,  1824, -1900,
   11664, 11664, 11664, -1900,  1827,   797, -1900,  1602,  6894, -1900,
   14749, 14778, 14807, -1900,  1841, 13287, 13287,   798, -1900,  1842,
    1843, -1900, -1900,   804, -1900,  1850, -1900, -1900,  1851, 13287,
   -1900, -1900, -1900
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1900, -1900, -1900, -1900,   489, -1900, -1900, -1900, -1900,  -256,
   -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900, -1900,
   -1900, -1900,  -721,  -141,  3592,  3572, -1900,  1399, -1900, -1900,
   -1900, -1900, -1900, -1900, -1899, -1900,   442,   265,   -58, -1900,
     -17, -1900,   209,   479, -1900,  1871, -1900,   302,   -49, -1900,
   -1900,     0,  -620,  -293, -1900, -1900, -1900, -1900, -1900, -1900,
   -1900, -1900,  1873, -1900, -1900, -1900, -1900, -1244, -1237,  1875,
   -1726,  1876, -1900, -1900, -1900,  1280, -1900,   -79, -1900, -1900,
   -1900, -1900,  2405, -1900, -1900, -1416,   350,  1880, -1900,     6,
    -714, -1900, -1900,   196, -1900, -1683,   871,  -136,  2936,  1600,
    -305,   130, -1900,   531,  -103, -1900, -1900,   155,   330, -1688,
    -148,  1119, -1900,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -569
static const yytype_int16 yytable[] =
{
     142,   442,  1488,   123,   407,  1486,   411,   164,   463,  1028,
     621,   946,   947,   309,   369,  1045,  1652,  1859,  1894,   424,
    1895,   343,   166,  1053,   178,  1612,   655,   164,   164,  2019,
    1731,   165,  1051,  1481,   637,   164,   150,  1518,  1059,   447,
     749,   412,   414,  1887,  1483,  1345,   736,     5,   548,   571,
    1811,   288,  1548,   660,  1621,  1077,  1280,     4,   293,   498,
    2154,   348,   293,   349,  1235,  1088,   472,   505,   164,  1812,
     182,   593,   145,   373,   718,   588,   589,   590,   591,   764,
     347,   294,  1236,   592,  1327,  1062,   146,   765,   288,  1380,
    1237,  1238,  1239,   372,   314,   303,  1240,  1241,   304,   305,
     306,   766,   593,  1622,   408,   629,   630,   344,  1931,   319,
     320,   307,   720,   629,   630,   777,   629,   630,   147,   315,
     712,   321,   715,  1177,  1235,   322,   941,   148,  1178,   631,
     727,   629,   630,  1942,  2135,   316,   317,   948,   149,   448,
    1519,  1520,  1236,   450,   458,   458,   458,   632,   471,   573,
    1237,  1238,  1239,   465,  2137,   350,  1240,  1241,   770,   606,
     607,   608,   629,   630,   781,  1068,   771,   629,   630,  1186,
     782,   477,   167,   308,   168,   436,   437,   629,   630,  1875,
    1485,  1181,  -563,   952,  2126,   629,   630,   458,  1469,   143,
     629,   630,   288,   144,  1584,   288,   544,   545,  1487,  1482,
     288,   288,   458,   651,   652,   653,  1856,   629,   630,   152,
    1484,  1975,   345,  1044,   156,  1346,  1347,  1348,  1349,  1327,
     667,   629,   630,   153,   116,  1732,   737,   738,  1976,   629,
     630,   116,  1549,  1550,   436,   437,   295,  1822,   116,   296,
    1697,   297,  1977,  1444,   116,   116,  1473,   432,   433,   434,
    1052,  1486,   116,   154,   288,   310,   629,   630,   311,  1010,
    1327,   155,   425,   370,   323,   325,   426,   328,   288,   179,
     346,   288,   569,   656,  2038,   657,  1337,   436,   437,   144,
     750,   568,   751,   151,  -561,   116,   752,   288,   288,   413,
     415,   288,   288,   288,   288,  1350,   549,   572,   159,   432,
     433,   434,   435,   162,  1281,   122,   288,  2155,   436,   437,
     288,   594,   372,   595,   741,   183,   742,   596,   374,  2039,
    2040,  1328,  1331,   436,   437,  2041,   731,   937,  2076,   939,
     940,   167,  1330,   168,   288,   157,   288,   288,   288,   436,
     437,   767,   594,   768,   595,  1154,   953,   769,   596,   436,
     437,   158,   721,   288,   722,   778,   784,   768,   723,   288,
     160,   779,   782,   302,   972,   629,   630,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   629,   630,   990,   167,   592,
     168,  1069,  1070,  2150,   862,  1852,   161,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,  1235,   872,   458,   288,   592,
    1069,  1070,   288,   288,   772,  1876,  1026,   175,   432,   433,
     434,   435,   773,  1236,   432,   433,   434,   435,   288,   629,
     630,  1237,  1238,  1239,   444,   753,   163,  1240,  1241,   444,
     444,   444,   436,   437,   176,   878,  1235,   422,   444,   170,
    1978,   423,   171,   775,  1431,   172,  1432,   173,   789,   629,
     630,   776,  2178,  1164,  1236,   432,   433,   434,   435,  1442,
     449,   776,  1237,  1238,  1239,     7,     8,   640,  1240,  1241,
    1979,   641,   444,   629,   630,   629,   630,   288,   177,   436,
     437,   319,   320,   629,   630,   629,   630,   444,   180,   639,
    1369,   629,   630,   321,   624,   625,  1980,   327,   820,  1374,
     181,   288,   633,   638,  2111,  2217,  2112,   820,   288,   852,
    2032,  2165,  2113,   458,  1375,   458,   288,   458,   458,   465,
     998,  1359,   820,  1313,   868,  -564,   543,  2007,   288,   288,
     288,   458,   458,   288,   166,  2008,   166,   167,   288,   168,
     819,   552,   553,   877,   820,   879,   573,   339,   184,   340,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,   531,   288,   532,    43,    44,    45,    46,
     909,  1531,    48,   629,   630,  1046,  1750,  1535,  1013,   755,
      55,   882,   185,    58,   756,   820,   757,   758,   741,   759,
     742,   917,   288,   288,  2114,   820,  1174,   629,   630,    67,
      68,    69,    70,   629,   630,    73,   918,    79,   629,   630,
     820,   450,   450,   741,    82,   742,  1498,    85,  2115,  1235,
     298,   776,  1570,   299,  2162,  1224,   300,  1516,   301,  2163,
     186,    93,    94,    95,   629,   630,  1586,  1236,   187,    46,
     288,   288,   288,  1592,   188,  1237,  1238,  1239,   167,   189,
     168,  1240,  1241,   446,  1180,  2172,   190,  1181,   456,   459,
     460,   436,   437,   465,   458,   465,   458,   458,   458,   458,
     458,   458,  1102,   458,   458,   458,   458,  1012,   191,   458,
     458,   458,   166,  1018,   629,   630,   288,   629,   630,  1064,
     199,  1017,   678,   200,   144,   303,   201,  1027,   304,   963,
     306,   493,   444,   820,   329,  2201,   950,   192,  2202,   202,
     288,   307,   732,   741,   353,   742,   507,   354,  1672,  1305,
     288,  1283,  1306,   746,  1030,   741,  1056,   742,   820,   741,
     355,   742,  1036,  1303,   761,  2203,  1037,   820,   436,   437,
     590,   591,   288,  1073,   193,  -568,   592,   741,   288,   742,
     288,  1196,   194,   465,  1086,  2043,  2044,  1680,  1681,  1184,
    1091,  2041,   458,   820,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   818,   588,   589,
     590,   591,  1197,  1773,  1198,  1741,   592,  -565,   741,   195,
     742,   432,   433,   434,   435,   288,  1219,   288,   330,  1312,
     820,  1313,   331,  1214,   197,   944,   945,  1751,   332,   333,
     625,   334,   335,  1220,   196,   436,   437,   820,   444,  1760,
     444,  1265,   444,   444,   444,   820,  1723,  1724,  1266,  1267,
     288,   336,   820,   820,  1309,  1340,   444,   444,   820,   820,
     288,  1837,   198,  1838,  2141,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,  1657,  1417,  1658,   204,   592,   820,  1517,
    1424,  1441,  1449,   205,   820,   820,   820,   289,   288,  1466,
     290,  1329,  1332,   820,  1486,  1582,  1634,   292,  1665,   820,
     820,   288,   820,   585,   586,   718,   588,   589,   590,   591,
     288,   312,  1666,  2185,   592,   286,   820,   313,  1757,  1780,
     291,   288,  1758,   820,  1782,  1740,  1868,  1741,   820,   761,
     820,  1333,  1914,  1932,   338,  1958,  1915,  1933,  1486,   820,
    1959,   724,  1974,  2004,   820,  2013,  1915,   776,   741,  2014,
     742,   743,   761,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,   341,  2030,  2034,   318,   592,  1915,   820,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   326,   444,   444,
     444,   444,   342,  2035,   444,   444,   444,   820,  2065,  2086,
     351,  2087,   820,   820,   761,   820,  2094,   761,  2102,  2110,
    1915,  2124,   820,   820,  2161,  1915,  2168,  2169,   820,   761,
     820,   820,  1556,  2170,   288,  2171,  2173,   820,  2175,   820,
     820,   337,  2014,  2196,  2204,  1339,   352,  1915,   820,   357,
     288,  2214,  2225,  1443,  1445,  2215,  1915,   358,  2228,  1063,
     359,  1065,  2229,   288,   365,  1848,  1849,   856,   458,   858,
     366,   860,   861,   377,   741,   506,   742,   914,   444,   629,
     630,   367,   368,   375,   376,   874,   875,   444,   378,   379,
     409,   427,   421,   428,   420,   454,   469,   453,   473,   471,
     474,   288,   288,   144,   288,   288,   288,   475,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   476,   481,
     288,   485,   499,  -198,   539,   542,  -199,   504,   286,   551,
    -200,   550,   554,   557,   558,   559,   570,  1227,   602,   603,
     423,   610,   618,   612,  1233,   658,   611,   661,  1244,   615,
     620,   622,   623,   642,   643,   644,   645,   646,   288,   458,
     458,   647,   648,   654,   662,   605,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,   659,
     614,   668,   288,   592,   619,   663,   664,   665,   673,   669,
     666,   670,   674,   681,   680,   689,   690,   691,   288,   288,
     288,   702,   703,   705,   707,   708,   706,   710,   711,   709,
     713,   714,   763,   730,   733,   740,  1443,  1445,   997,   745,
     999,  1000,  1001,  1002,  1003,  1004,   747,  1006,  1007,  1008,
    1009,   748,   143,  1014,  1015,  1016,   754,   786,   790,   761,
     811,   761,   761,   795,   816,  1744,   822,   823,   824,  1746,
    1756,   592,   853,   863,   288,   761,   450,   864,   865,   885,
     886,   912,   883,   922,   926,   923,   931,   935,   936,   288,
     288,   288,   938,   965,   761,   967,   970,  1597,   968,  1602,
     288,  1410,   979,   984,   988,   458,   991,  1029,  1020,   458,
    1022,  1035,   761,  1039,  1047,  1040,   728,   729,   458,  1392,
     458,  1048,  1049,   458,  1061,  1060,  1078,  1084,  1500,  1076,
    1066,  1095,   739,  1080,  1083,  1090,  1093,  1092,   288,  1096,
    1103,  1104,  1105,  1107,  1108,  1109,  1111,  1112,   761,  1113,
    1114,  1115,  1116,  1117,   372,  1118,  1119,  1120,  1127,  1123,
    1153,  1152,  1161,  2047,  1185,  1162,  1179,  1170,  1188,  1201,
    1163,  1189,  1173,  1193,  1202,   458,  1203,  1209,  1211,  1222,
     288,  1230,   288,  1231,  1234,  1256,  1257,  1259,  1275,  1272,
    1273,  1274,  1286,   444,  1287,  1288,  1291,  1299,  1301,   288,
    1302,  1308,  1311,  1314,  1315,  1316,  1317,  1320,  1321,  1322,
    1326,  1335,   288,  1336,  1341,  1342,   288,  1356,  1362,  1363,
    1364,  1365,  1370,  1373,  1378,  1377,  1382,  1752,  1395,  -201,
     859,  1399,  1411,  1765,  1765,  1427,  1435,  1453,  1454,  1455,
    1458,  1459,   605,  1460,   873,  1461,  1462,  1463,  1464,  1465,
    1467,  1739,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
     288,   288,   288,  1903,   592,  1474,  1475,  1479,   288,   288,
     288,  1478,  1480,  1489,   444,   444,  1490,  1501,  1491,  1492,
    1493,  1494,  1495,  1496,  1497,   288,  1502,  1503,  1504,  1505,
    1506,  1507,  1508,  1513,  1521,  1526,   288,  1536,  1527,  1533,
    1534,  1538,  1794,  1547,   288,  1542,  1552,  1544,   288,  1553,
    1558,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,  1827,
    1555,  1563,  1569,   592,  1559,  1567,   761,  1565,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,  1566,  1581,  1583,  1589,
     592,  1590,   372,  1587,  1606,  1604,  1611,  1605,   465,   465,
    1613,  1617,  1618,  1619,   288,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1660,  1654,  1643,  1843,  1664,
    1670,  1650,   458,  1671,  1774,  1679,  1677,  1678,  1685,  1686,
     444,  1687,   288,  1693,   444,  1688,  1694,   288,  1700,  1701,
    1709,  1714,  1368,   444,  1041,   444,  1716,  1702,   444,  1703,
    1704,  1705,  1715,  1906,  1708,  1720,  1721,  1537,  1711,  1722,
    1736,  1880,  1748,  1767,  1726,  1729,  1743,  1306,  1885,  1888,
    1747,  1753,  1754,  1827,  1772,  1775,  1777,  1783,  1784,  1786,
    1779,  1787,  1790,  1795,  1801,  1802,  1803,  1897,  1804,  1806,
    1807,  1808,  1809,  1813,  1814,  1815,  1816,  1821,  1181,  1828,
     444,  1829,  1830,  1832,  1835,  1836,  1857,  1853,  1858,   288,
    1867,  1871,  1899,  1889,   288,   288,  1900,  1890,  -566,  2053,
    1902,  1907,  1891,  1696,  1919,   450,   450,  1920,   776,  1921,
    1922,  1926,  1930,  1422,  1423,  2070,  1935,   288,  1937,  1938,
    1936,  1939,  1940,   288,  1941,  1947,  1953,  1954,  1962,  1969,
    1957,  1963,  1971,   288,  1981,  1983,  1988,  1998,  2001,  1989,
    2000,  2003,  1965,   458,  2005,  2006,   458,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,  1966,   288,  1972,  2002,   592,  2029,  1995,
    1996,  1339,  1997,  2011,  2050,   372,  2051,   288,   465,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,  2055,  2119,  2067,  2068,   592,  2066,
    2069,  2071,  2077,  2080,  -567,  2085,  2081,  2089,  1993,  2082,
    2091,  2093,  2095,   465,  1208,   164,   380,  2099,   503,  2098,
    2101,  2103,  2105,  2117,  2118,  2106,  2109,  2120,  2133,  1805,
    2138,  2143,  2186,   288,  2187,  2188,  2142,  2189,  2191,  1523,
    2192,  2121,  2128,  1525,  2193,   288,   288,  2197,  2157,  2174,
    2209,  2024,  1529,  2213,  1530,  2194,  2208,  1532,   381,   382,
     383,   384,   385,   386,   387,   388,   389,  2221,  2226,  2227,
     288,   390,   391,   392,   393,  2216,  2230,  2231,  1585,   394,
     395,   396,   288,   444,   444,  2151,   397,   785,   398,  1646,
    1800,  2020,  1992,  1615,   121,   288,   132,  1831,   133,   134,
    2045,  1738,   399,   140,  1901,   400,  1886,   444,   925,  1572,
     600,   601,  1766,     0,     0,  1085,     0,  1860,  1861,  1862,
    1863,  1864,  1866,     0,     0,     0,     0,     0,  1323,     0,
       0,     0,   288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1343,     0,     0,   288,     0,     0,
       0,     0,  2025,     0,     0,   288,   288,   649,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,   288,     0,     0,
       0,     0,     0,   450,     0,     0,     0,     0,   288,     0,
       0,     0,   288,     0,     0,  1393,  1394,     0,  1396,  1397,
    1398,  2127,  1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,
    1408,  1409,     0,     0,   401,   402,   403,   372,     0,     0,
       0,     0,     0,     0,     0,   404,     0,     0,   288,   405,
       0,   406,   116,     0,     0,     0,     0,     0,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,   444,     0,
       0,   444,  1421,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,   761,     0,   761,     0,
       0,  1541,     0,     0,     0,     0,  1436,     0,     0,     0,
       0,     0,     0,   444,     0,     0,     0,     0,     0,     0,
       0,     0,  1450,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,     0,     0,     0,     0,     0,   444,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,   288,
     288,   288,   288,     0,     0,     0,  1785,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1499,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   380,     0,
       0,     0,     0,  1510,  1511,  1512,     0,     0,     0,     0,
       0,     0,   288,     0,     0,     0,     0,     0,     0,     0,
       0,   880,     0,     0,     0,     0,     0,     0,     0,   288,
    1554,     0,  2057,  2058,  2059,  2060,  2061,     0,     0,     0,
     381,   382,   383,   384,   385,   386,   387,   388,   389,     0,
       0,   458,  1543,   390,   391,   392,   393,     0,     0,     0,
       0,   394,   395,   396,     0,   288,     0,     0,   397,     0,
     398,     0,   458,   458,     0,   932,   933,     0,     0,     0,
       0,     0,     0,     0,   399,     0,   458,   400,     0,     0,
       0,   298,     0,     0,   299,     0,  2096,   300,     0,   301,
    2100,     0,     0,     0,     0,     0,     0,  1689,     0,     0,
      46,     0,     0,  1601,     0,     0,     0,  1881,     0,     0,
    1883,     0,     0,   975,   976,   977,  1616,   430,     0,     0,
    1620,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,  2134,     0,   592,     0,  2136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1019,
       0,  2148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1667,  1668,  1669,     0,     0,     0,
       0,     0,  1674,  1675,  1676,     0,   401,   402,   403,     0,
       0,     0,     0,  1050,     0,     0,     0,   404,     0,  1691,
       0,   405,     0,   406,   116,   761,     0,     0,  2183,  2184,
    1699,     0,     0,     0,     0,  1072,     0,     0,  1707,     0,
       0,  1079,     0,  1081,     0,     0,     0,     0,     0,   436,
     437,     0,     0,     0,     0,     0,  -562,     0,  1571,     0,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,  1745,     0,     0,     0,     0,     0,     0,
       0,   761,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1771,     0,
       0,     0,     0,     0,   761,     0,     0,     0,     0,     0,
       0,     0,     0,  1155,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1165,     0,     0,  1793,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,     0,   444,     0,     0,     0,
       0,  1192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1200,     0,     0,   444,   444,     0,
     418,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   444,     0,     0,  1221,     0,     0,     0,     0,     0,
       0,     0,     0,  1834,     0,     0,     0,   445,     0,     0,
       0,   455,     0,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,   466,     0,     0,     0,     0,     0,
       0,  1771,     0,     0,     0,     0,     0,     0,     0,     0,
     478,   479,   480,     0,   482,   483,   484,  1872,   486,   487,
     488,   489,   490,   491,   492,     0,   494,   495,   496,   497,
       0,     0,     0,   501,     0,     0,     0,     0,     0,  1456,
       0,     0,     0,     0,     0,     0,     0,     0,  1896,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1905,     0,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1367,     0,     0,     0,
       0,     0,     0,     0,     0,   560,   562,   564,   565,   501,
       0,     0,     0,     0,     0,     0,     0,  1771,     0,     0,
       0,     0,     0,     0,   599,   501,   501,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,   617,     0,     0,   592,
       0,     0,     0,  1412,  1970,  2206,   627,   628,     0,     0,
       0,     0,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   501,   650,     0,     0,  2222,  2224,   410,   380,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2232,     0,     0,     0,     0,     0,   671,   501,     0,     0,
       0,   675,   676,   677,     0,   679,     0,     0,     0,   682,
     683,   684,     0,     0,   685,     0,  2012,     0,     0,     0,
       0,   381,   382,   383,   384,   385,   386,   387,   388,   389,
       0,  2021,  1451,  1452,   390,   391,   392,   393,     0,     0,
       0,     0,   394,   395,   396,     0,     0,     0,     0,   397,
       0,   398,   717,     0,     0,     0,   501,   726,  1771,     0,
       0,     0,     0,     0,     0,   399,     0,     0,   400,     0,
       0,     0,  2052,   734,   735,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   762,     0,
    1749,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   791,   792,
     793,   794,  1771,  1522,     0,     0,   799,     0,     0,     0,
     803,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   817,   562,     0,     0,     0,   821,
       0,     0,  2097,   825,   826,   827,   828,   829,   830,   831,
     832,   833,   834,   835,   836,   837,   838,   839,   840,   841,
     843,   844,   845,   846,   847,   848,   849,   849,     0,   854,
     855,     0,   857,     0,     0,     0,     0,   401,   402,   403,
       0,   866,     0,     0,   870,   871,     0,     0,   404,     0,
       0,   849,   405,  1578,   406,  1580,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   887,   888,
     889,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   902,   904,   905,   906,   907,   908,     0,   910,
     911,     0,     0,     0,     0,     0,     0,   919,   920,   921,
    1755,     0,     0,     0,     0,   927,   928,   929,   930,     0,
     501,   501,     0,     0,     0,     0,  1771,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   560,
     717,   949,     0,     0,     0,   954,   955,   956,   957,   958,
     959,   960,   961,   962,     0,     0,     0,     0,     0,   969,
    1870,   971,     0,     0,   973,     0,     0,     0,   501,   501,
     501,   978,     0,   980,   981,   982,     0,     0,     0,  1771,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
    1005,  1710,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,     0,     0,     0,
       0,  1024,     0,  1025,     0,     0,   910,   911,     0,     0,
       0,     0,     0,     0,   502,  1038,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,     0,
    1054,     0,     0,     0,     0,  1057,  1058,  1934,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,  1074,  1075,     0,     0,   501,     0,   501,  1082,
       0,     0,     0,  1074,     0,  1089,     0,     0,     0,     0,
       0,  1094,     0,     0,     0,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   563,     0,     0,
     502,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1121,     0,   902,     0,  1124,   502,   502,     0,     0,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,  1166,
    1167,     0,     0,   502,     0,     0,     0,  1839,  1840,     0,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,   502,     0,
       0,     0,   592,     0,     0,     0,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,     0,  1207,     0,     0,
       0,  1213,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,     0,     0,     0,     0,  1228,  1229,     0,
       0,     0,     0,  1232,     0,     0,     0,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1258,     0,     0,  1260,     0,     0,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   818,
     588,   589,   590,   591,  1276,     0,  1278,  1279,   592,     0,
       0,  1961,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1987,     0,  1951,  1952,
       0,     0,     0,     0,     0,     0,   563,     0,  1319,     0,
       0,     0,     0,     0,     0,  1325,     0,     0,     0,     0,
    1334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     842,     0,     0,     0,     0,  1360,  1361,   850,   851,     0,
       0,   501,     0,     0,     0,     0,     0,     0,  1986,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   876,     0,     0,     0,     0,   502,     0,     0,
       0,     0,     0,  1387,  1388,  1389,  1390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   903,     0,     0,     0,     0,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2026,  2027,
       0,     0,     0,     0,  1413,     0,     0,     0,     0,     0,
       0,   502,   502,     0,  1414,  1415,  1416,     0,     0,     0,
    2046,  1418,  1419,     0,  1420,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2056,     0,     0,  1429,  1430,
       0,     0,     0,     0,     0,     0,  1433,  1434,     0,     0,
       0,     0,     0,  1438,     0,  1439,  1440,     0,     0,   502,
     502,   502,  1446,  1447,     0,     0,     0,   501,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
     174,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,  1477,     0,   592,     0,   502,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,  1509,     0,     0,   502,
       0,     0,     0,     0,     0,     0,     0,     0,   501,     0,
       0,     0,     0,  2132,     0,     0,  1524,     0,     0,     0,
       0,   502,     0,     0,     0,     0,     0,   502,     0,   502,
       0,  2144,  2145,  2146,  2147,  2149,     0,  1446,  1447,     0,
       0,     0,  1540,  1999,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1546,   443,     0,  1551,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   903,     0,  1125,     0,     0,     0,
       0,     0,     0,     0,  1573,     0,     0,  1576,   501,  1579,
     501,     0,  2190,     0,     0,     0,     0,     0,  1588,     0,
       0,  1591,     0,  1588,  1594,  1596,     0,     0,     0,   502,
       0,     0,     0,     0,     0,     0,  2036,     0,     0,   502,
       0,     0,     0,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   533,   534,   535,   536,
     537,   538,     0,   540,   541,     0,     0,   502,     0,     0,
       0,     0,   546,   547,     0,     0,     0,     0,     0,     0,
     502,     0,     0,     0,   555,   556,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1673,     0,     0,     0,     0,
     502,     0,     0,     0,  1682,  1683,  1684,     0,     0,     0,
       0,     0,     0,  1690,     0,  1692,     0,     0,     0,     0,
       0,     0,  1695,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,     0,     0,     0,
       0,  1712,     0,     0,     0,     0,     0,     0,     0,  1717,
    1718,  1719,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1742,     0,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,  1759,   592,     0,     0,     0,     0,
    1768,  1769,     0,   686,   687,   688,     0,     0,  2037,   692,
     693,   694,   695,   696,   697,   698,     0,   699,     0,     0,
       0,   700,   701,     0,     0,   704,     0,     0,     0,     0,
       0,     0,   502,     0,     0,  1798,     0,     0,   716,     0,
       0,     0,     0,     0,     0,   744,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,  1817,  1818,  1819,     0,     0,
       0,     0,     0,     0,     0,     0,  1820,     0,     0,   502,
       0,  1823,  1824,  1825,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1833,     0,     0,     0,     0,
       0,     0,   501,   501,  1841,     0,  1842,     0,     0,     0,
       0,     0,  1850,  1851,     0,     0,     0,     0,     0,  2116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,     0,     0,  1869,     0,     0,   867,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1879,
       0,     0,  1882,     0,     0,     0,  1884,     0,   502,   502,
       0,     0,     0,     0,     0,  1824,  1825,     0,  1893,     0,
       0,     0,     0,     0,     0,     0,  1898,     0,     0,     0,
       0,   884,     0,     0,     0,     0,     0,     0,     0,     0,
     915,     0,  1911,     0,     0,     0,     0,  1917,  1918,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1923,     0,     0,  1924,  1923,     0,  1927,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,   502,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,   501,     0,     0,     0,     0,     0,
    1955,  1956,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1964,     0,     0,     0,     0,     0,     0,     0,
       0,  1973,     0,     0,     0,     0,     0,     0,     0,     0,
     562,     0,     0,     0,     0,     0,     0,     0,     0,  1984,
    1985,     0,     0,   501,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   502,
       0,   502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2009,  2010,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,  2023,     0,
       0,   592,     0,   501,   501,  2028,     0,     0,     0,     0,
    2031,     0,     0,  2033,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,     0,     0,     0,     0,     0,     0,  2062,     0,
       0,     0,     0,     0,     0,  2164,     0,  1128,  1129,  1130,
    1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,     0,  1140,
    1141,  1142,  1143,  2073,  1145,  1146,  1147,  1148,     0,  2078,
       0,     0,  2079,     0,  2084,     0,     0,     0,  1158,     0,
    1160,     0,     0,     0,     0,     0,     0,   502,     0,     0,
    1169,     0,     0,     0,     0,     0,     0,  1175,  1176,     0,
       0,     0,     0,     0,  2104,     0,  1187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573,     0,
       0,  1182,     0,     0,     0,     0,     0,     0,     0,  2122,
    2123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2129,  2130,     0,  2131,   501,     0,
       0,     0,     0,     0,     0,  1199,     0,     0,     0,     0,
       0,  2140,     0,     0,     0,     0,   501,   501,   501,   501,
     501,     0,     0,     0,     0,     0,  1917,     0,     0,     0,
    2156,     0,     0,     0,     0,     0,  1799,     0,     0,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,  2177,     0,
       0,   592,     0,  2180,  2181,  2182,     0,  1791,  1282,  1284,
    1285,  1792,     0,     0,  1289,  1290,     0,   501,  1293,  1294,
    1295,  1296,     0,  1298,     0,     0,     0,     0,  1304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2210,  2211,  2212,     0,     0,
       0,     0,     0,   502,   502,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,   502,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,  1386,
       0,     0,     0,     0,  1391,     0,     0,     0,     0,     0,
       0,     0,     0,  1381,     0,     0,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,     0,   206,     6,   360,   592,     0,
       0,     0,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,   502,   502,   243,   244,     0,     0,
       0,  1448,     0,     0,     0,   245,   246,     0,  1437,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,     0,     0,     0,     0,     0,
     252,   563,     0,   253,     0,     0,   254,     0,   255,     0,
       0,     0,     0,     0,   502,    42,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,    56,    57,     0,   258,   573,   259,     0,     0,   260,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,   992,     0,
      82,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   502,   502,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1190,     0,     0,     0,     0,   502,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   262,   263,
       0,   502,  1560,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1561,  1562,     0,     0,     0,     0,   270,
     271,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   361,     0,  1598,     0,   362,     0,     0,   275,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,   983,     0,  1635,  1636,  1637,  1638,  1639,
       0,   942,     0,     0,  1644,  1645,     0,     0,     0,     0,
    1647,     0,  1649,     0,     0,     0,  1653,     0,     0,  1655,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1663,     0,     0,  1651,     0,     0,     0,     0,   502,
       0,     0,     0,     0,  1659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   502,   502,   502,
     502,   502,     0,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   818,   588,   589,   590,
     591,     0,     0,     0,     0,   592,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,  1725,     0,  1728,  1191,   592,     0,
    1735,     0,  1737,     0,     0,     0,     0,     0,   502,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,  1762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     6,   380,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,  1796,     0,     0,  1599,   382,   383,   384,   385,   386,
     387,   388,   389,   239,   240,   241,   242,   390,   391,   392,
     393,   243,   244,     0,     0,   394,   395,   396,     0,     0,
     245,   246,   397,     0,   398,   247,   248,   249,     0,     0,
       0,  1826,     0,     0,     0,     0,   250,    25,   399,   251,
       0,   400,     0,     0,     0,   252,     0,     0,   253,     0,
       0,   254,     0,   255,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,    56,    57,     0,   258,
       0,   259,     0,     0,   260,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,  1908,     0,   592,  1909,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     401,   402,   403,   262,   263,  1515,     0,     0,   264,   265,
     266,   404,   267,   268,   269,   405,     0,   406,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   271,     0,     0,     0,  1943,
    1944,   272,  1946,     0,     0,     0,   361,     0,     0,     0,
    1600,     0,     0,   275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,     6,   380,     0,     0,     0,     0,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,  1990,  1991,     0,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   239,   240,   241,   242,
     390,   391,   392,   393,   243,   244,     0,     0,   394,   395,
     396,     0,     0,   245,   246,   397,     0,   398,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,   399,   251,  2022,   400,     0,     0,     0,   252,     0,
       0,   253,     0,     0,   254,     0,   255,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,    56,
      57,     0,   258,     0,   259,     0,     0,   260,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,     0,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   261,   401,   402,   403,   262,   263,     0,     0,
       0,   264,   265,   266,   404,   267,   268,   269,   405,     0,
     406,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   271,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   361,
     206,   164,   380,   274,   429,     0,   275,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   416,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   239,   240,   241,   242,   390,   391,   392,
     393,   243,     0,     0,     0,   394,   395,   396,     0,     0,
       0,     0,   397,     0,   398,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,   399,   251,
       0,   400,     0,  2199,     0,   298,     0,     0,   299,   380,
       0,   300,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   381,   382,   383,   384,   385,   386,   387,   388,   389,
       0,     0,     0,     0,   390,   391,   392,   393,     0,     0,
       0,     0,   394,   395,   396,     0,     0,     0,     0,   397,
       0,   398,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   399,     0,     0,   400,     0,
       0,     0,   431,     0,     0,     0,     0,     0,     0,   261,
     401,   402,   403,   262,     0,     0,     0,     0,   264,   265,
     266,   404,   267,   268,   269,   405,     0,   406,   116,   432,
     433,   434,   435,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   417,     0,     0,     0,     0,
       0,   272,     0,   436,   437,     0,   438,     0,   439,   206,
       6,     0,   440,   275,   672,     0,   207,   208,   209,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,   401,   402,   403,
       0,     0,   239,   240,   241,   242,     0,     0,   404,     0,
     243,   244,   405,     0,   406,     0,     0,     0,     0,   245,
     246,     0,     0,     0,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    25,     0,   251,     0,
       0,     0,     0,     0,   252,     0,     0,   253,     0,     0,
     254,     0,   255,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,    56,    57,     0,   258,     0,
     259,     0,     0,   260,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,   741,     0,   742,     0,     0,     0,     0,     0,
    1727,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,   262,   263,     0,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   500,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   361,   206,     6,  1698,     0,
     566,     0,   275,   207,   208,   209,     0,     0,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   239,
     240,   241,   242,     0,     0,     0,     0,   243,   244,     0,
       0,     0,     0,     0,     0,     0,   245,   246,     0,     0,
       0,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,    25,     0,   251,     0,     0,     0,     0,
       0,   252,     0,     0,   253,     0,     0,   254,     0,   255,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
     256,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,    56,    57,     0,   258,     0,   259,     0,     0,
     260,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,     0,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    82,     0,     0,    85,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,  1846,     0,     0,     0,  1847,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,   262,
     263,     0,     0,     0,   264,   265,   266,     0,   267,   268,
     269,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   271,     0,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   361,   206,     6,     0,   274,     0,     0,   275,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,     0,     0,     0,     0,     0,   252,     0,
       0,   253,     0,     0,   254,     0,   255,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,    56,
      57,     0,   258,     0,   259,     0,     0,   260,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
    1873,     0,     0,     0,  1874,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   262,   263,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   634,  1865,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   636,
     206,     6,     0,   322,   566,     0,   275,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
       0,   243,   244,     0,     0,     0,     0,     0,     0,     0,
     245,   246,     0,     0,     0,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,     0,   251,
       0,     0,     0,     0,     0,   252,     0,     0,   253,     0,
       0,   254,     0,   255,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,    56,    57,     0,   258,
       0,   259,     0,     0,   260,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,  2048,     0,     0,
       0,  2049,     0,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,   262,   263,     0,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   271,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   273,   206,     6,     0,
     274,     0,     0,   275,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,   244,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,     0,     0,     0,
       0,     0,   252,     0,     0,   253,     0,     0,   254,     0,
     255,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,    56,    57,     0,   258,     0,   259,     0,
       0,   260,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   774,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
     262,   263,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   271,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   361,   206,     6,     0,   274,     0,     0,
     275,   207,   208,   209,     0,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
     242,     0,     0,     0,     0,   243,   244,     0,     0,     0,
       0,     0,     0,     0,   245,   246,     0,     0,     0,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,    25,     0,   251,     0,     0,     0,     0,     0,   252,
       0,     0,   253,     0,     0,   254,     0,   255,     0,     0,
       0,     0,     0,     0,    42,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   257,     0,
      56,    57,     0,   258,     0,   259,     0,     0,   260,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    82,
       0,     0,    85,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   780,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,   262,   263,     0,
       0,     0,   264,   265,   266,     0,   267,   268,   269,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   500,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     361,   206,     6,     0,   561,     0,     0,   275,   207,   208,
     209,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,   241,   242,     0,     0,
       0,     0,   243,   244,     0,     0,     0,     0,     0,     0,
       0,   245,   246,     0,     0,     0,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    25,     0,
     251,     0,     0,     0,     0,     0,   252,     0,     0,   253,
       0,     0,   254,     0,   255,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,    56,    57,     0,
     258,     0,   259,     0,     0,   260,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   942,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,   262,   263,     0,     0,     0,   264,
     265,   266,     0,   267,   268,   269,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   500,     0,     0,     0,
       0,     0,   272,     0,     0,     0,     0,   361,   206,     6,
       0,     0,   566,     0,   275,   207,   208,   209,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   240,   241,   242,     0,     0,     0,     0,   243,
     244,     0,     0,     0,     0,     0,     0,     0,   245,   246,
       0,     0,     0,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,    25,     0,   251,     0,     0,
       0,     0,     0,   252,     0,     0,   253,     0,     0,   254,
       0,   255,     0,     0,     0,     0,     0,     0,    42,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   257,     0,    56,    57,     0,   258,     0,   259,
       0,     0,   260,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,     0,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    82,     0,     0,    85,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   943,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,   262,   263,     0,     0,     0,   264,   265,   266,     0,
     267,   268,   269,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   271,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   604,   206,     6,     0,   274,     0,
       0,   275,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,   244,     0,     0,
       0,     0,     0,     0,     0,   245,   246,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,     0,     0,     0,     0,     0,
     252,     0,     0,   253,     0,     0,   254,     0,   255,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   257,
       0,    56,    57,     0,   258,     0,   259,     0,     0,   260,
       0,     0,     0,     0,     0,    67,    68,    69,    70,    71,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      82,     0,     0,    85,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   989,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   262,   263,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     271,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   613,   206,     6,     0,   274,     0,     0,   275,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,   244,     0,     0,     0,     0,     0,
       0,     0,   245,   246,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
       0,   251,     0,     0,     0,     0,     0,   252,     0,     0,
     253,     0,     0,   254,     0,   255,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,    56,    57,
       0,   258,     0,   259,     0,     0,   260,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,   262,   263,     0,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   500,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   361,   206,
       6,     0,   901,     0,  1366,   275,   207,   208,   209,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,   242,     0,     0,     0,     0,
     243,   244,     0,     0,     0,     0,     0,     0,     0,   245,
     246,     0,     0,     0,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    25,     0,   251,     0,
       0,     0,     0,     0,   252,     0,     0,   253,     0,     0,
     254,     0,   255,     0,     0,     0,     0,     0,     0,    42,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,    56,    57,     0,   258,     0,
     259,     0,     0,   260,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1099,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,   262,   263,     0,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   500,     0,     0,     0,     0,     0,
     272,   206,     6,     0,     0,   361,  1577,     0,   207,   208,
     209,     0,   275,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,   241,   242,     0,     0,
       0,     0,   243,   244,     0,     0,     0,     0,     0,     0,
       0,   245,   246,     0,     0,     0,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    25,     0,
     251,     0,     0,     0,     0,     0,   252,     0,     0,   253,
       0,     0,   254,     0,   255,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   257,     0,    56,    57,     0,
     258,     0,   259,     0,     0,   260,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    82,     0,     0,    85,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,   262,   263,     0,     0,     0,   264,
     265,   266,     0,   267,   268,   269,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   500,     0,     0,     0,
       0,     0,   272,   206,     6,     0,     0,   361,     0,     0,
     207,   208,   209,     0,   275,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,   244,     0,     0,     0,     0,
       0,     0,     0,   245,   246,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,     0,     0,     0,     0,     0,   252,     0,
       0,   253,     0,     0,   254,     0,   255,     0,     0,     0,
       0,     0,     0,    42,     0,     0,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,     0,    56,
      57,     0,   258,     0,   259,     0,     0,   260,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    71,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    82,     0,
       0,    85,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   262,   263,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   271,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   361,
     206,     6,     0,  1706,     0,     0,   275,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
       0,   243,   244,     0,     0,     0,     0,     0,     0,     0,
     245,   246,     0,     0,     0,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,     0,   251,
       0,     0,     0,     0,     0,   252,     0,     0,   253,     0,
       0,   254,     0,   255,     0,     0,     0,     0,     0,     0,
      42,     0,     0,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,    56,    57,     0,   258,
       0,   259,     0,     0,   260,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    82,     0,     0,    85,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1139,     0,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,   262,   263,     0,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   634,  1865,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   636,   206,     6,     0,
     322,     0,     0,   275,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,   244,
       0,     0,     0,     0,     0,     0,     0,   245,   246,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,     0,     0,     0,
       0,     0,   252,     0,     0,   253,     0,     0,   254,     0,
     255,     0,     0,     0,     0,     0,     0,    42,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,    56,    57,     0,   258,     0,   259,     0,
       0,   260,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    82,     0,     0,    85,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1149,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
     262,   263,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   500,     0,     0,     0,     0,     0,   272,   206,
     164,   380,     0,   361,     0,     0,   207,   208,   209,     0,
     275,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   416,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   239,   240,   241,   242,   390,   391,   392,   393,
     243,     0,     0,     0,   394,   395,   396,     0,     0,     0,
       0,   397,     0,   398,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    25,   399,   251,     0,
     400,   206,   164,   380,     0,     0,     0,     0,   207,   208,
     209,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     416,   228,   229,   230,   231,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   239,   240,   241,   242,   390,   391,
     392,   393,   243,     0,     0,     0,   394,   395,   396,     0,
       0,     0,     0,   397,     0,   398,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    25,   399,
     251,     0,   400,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,   401,
     402,   403,   262,     0,     0,     0,     0,   264,   265,   266,
     404,   267,   268,   269,   405,     0,   406,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   417,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   361,     0,     0,     0,  1595,
       0,     0,   275,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1150,     0,     0,     0,     0,
     261,   401,   402,   403,   262,     0,     0,     0,     0,   264,
     265,   266,   404,   267,   268,   269,   405,     0,   406,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   417,     0,     0,     0,
       0,     0,   272,     0,     0,     0,     0,   361,   206,   164,
     380,  1878,     0,     0,   275,   207,   208,   209,     0,     0,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   416,   228,   229,
     230,   231,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,  1599,   382,   383,   384,   385,   386,   387,   388,
     389,   239,   240,   241,   242,   390,   391,   392,   393,   243,
       0,     0,     0,   394,   395,   396,     0,     0,     0,     0,
     397,     0,   398,   247,   248,   249,     0,     0,     0,     0,
       0,     0,     0,     0,   250,    25,   399,   251,     0,   400,
     206,   164,   380,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   416,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   239,   240,   241,   242,   390,   391,   392,
     393,   243,     0,     0,     0,   394,   395,   396,     0,     0,
       0,     0,   397,     0,   398,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,   399,   251,
       0,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,   401,   402,
     403,   262,     0,     0,     0,     0,   264,   265,   266,   404,
     267,   268,   269,   405,     0,   406,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   417,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   361,     0,     0,     0,  1761,     0,
       0,   275,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1151,     0,     0,     0,     0,   261,
     401,   402,   403,   262,     0,     0,     0,     0,   264,   265,
     266,   404,   267,   268,   269,   405,     0,   406,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   417,     0,     0,     0,     0,
       0,   272,   206,   164,     0,     0,   361,     0,     0,   207,
     208,   209,     0,   275,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   416,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,   206,   164,     0,   250,    25,
       0,   251,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   416,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,   261,     0,     0,     0,   262,     0,  1156,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   417,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   361,     0,
       0,     0,   616,     0,     0,   275,     0,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,   261,     0,     0,     0,   262,  1157,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   634,
     635,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   636,   206,   164,     0,   322,     0,   869,   275,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   416,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,   206,   164,     0,   250,    25,
       0,   251,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   416,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,   261,     0,     0,     0,   262,     0,  1159,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   417,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   361,     0,
       0,     0,     0,     0,     0,   275,     0,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,   261,     0,     0,     0,   262,  1271,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     417,     0,     0,     0,     0,     0,   272,   206,   164,     0,
    1318,   361,  1087,     0,   207,   208,   209,     0,   275,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   416,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,   206,   164,     0,
    1476,     0,     0,     0,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   416,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,   261,     0,     0,   592,
     262,     0,     0,     0,   719,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   417,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     275,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1292,     0,     0,   261,     0,     0,     0,
     262,     0,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   417,     0,     0,     0,     0,     0,   272,   206,
     164,     0,  1539,   361,     0,     0,   207,   208,   209,     0,
     275,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   416,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,   241,   242,     0,     0,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,   249,     0,     0,     0,
       0,     0,   206,   164,     0,   250,    25,     0,   251,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   416,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
       0,   251,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,   261,     0,
       0,     0,   262,     0,  1376,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   417,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,     0,   275,     0,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,   261,     0,     0,     0,   262,  1379,     0,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   417,     0,     0,
       0,     0,     0,   272,   206,   164,     0,     0,   361,  1593,
       0,   207,   208,   209,     0,   275,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   416,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   239,   240,   241,
     242,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   247,
     248,   249,     0,     0,     0,     0,     0,   206,   164,     0,
     250,    25,     0,   251,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   416,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,     0,   251,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,   261,     0,     0,     0,   262,     0,  1470,
       0,     0,   264,   265,   266,     0,   267,   268,   269,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   417,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     361,  1925,     0,     0,     0,     0,     0,   275,     0,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,   261,     0,     0,     0,
     262,  1471,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,   164,   380,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   417,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     275,     0,     0,     0,     0,   381,   382,   383,   384,   385,
     386,   387,   388,   389,     0,     0,     0,     0,   390,   391,
     392,   393,   164,   380,     0,     0,   394,   395,   396,     0,
       0,     0,     0,   397,     0,   398,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   399,
       0,     0,   400,     0,     0,     0,   298,     0,     0,   299,
       0,     0,   300,     0,   301,   381,   382,   383,   384,   385,
     386,   387,   388,   389,     0,    46,     0,     0,   390,   391,
     392,   393,     0,     0,     0,     0,   394,   395,   396,     0,
       0,     0,   430,   397,     0,   398,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   399,
       0,     0,   400,     0,     0,     0,   298,     0,     0,   299,
       0,     0,   300,     0,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,     0,     0,     7,     8,     0,     0,     0,
       0,   401,   402,   403,     0,     0,     0,     0,     0,     0,
       0,     0,   404,     0,     0,     0,   405,     0,   406,   116,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,   741,     0,
     742,  1761,  1514,     7,     8,     0,     0,     0,     0,     0,
       0,   401,   402,   403,     0,     0,     0,     0,     0,     0,
       0,     0,   404,     0,     0,     0,   405,     0,   406,   116,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    43,    44,    45,    46,
       0,     0,    48,     0,     0,     0,     0,     0,     0,   755,
      55,  1761,     0,    58,   756,     0,   757,   758,     0,   759,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,    43,    44,    45,    46,     7,     8,
      48,    93,    94,    95,     0,     0,     0,   755,    55,     0,
       0,    58,   756,     0,   757,   758,     0,   759,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     7,     8,   592,    93,
      94,    95,     0,     0,     0,     0,     0,     0,  1640,     0,
       0,     0,     0,     0,     0,     0,   974,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,   755,    55,     7,     8,    58,   756,     0,   757,
     758,     0,   759,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1021,     0,     0,     0,     0,     0,
      79,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,    93,    94,    95,     0,     0,     0,
     755,    55,     7,     8,    58,   756,     0,   757,   758,     0,
     759,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,    93,    94,    95,     0,     0,     0,   755,    55,
       7,     8,    58,   756,     0,   757,   758,     0,   759,  1023,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
      93,    94,    95,     0,     0,     0,   755,    55,     7,     8,
      58,   756,     0,   757,   758,     0,   759,  1223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,    93,    94,
      95,     0,     0,     0,   755,    55,     7,     8,    58,   756,
       0,   757,   758,     0,   759,  1225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    93,    94,    95,     0,
       0,     0,   755,    55,     7,     8,    58,   756,     0,   757,
     758,     0,   759,  1226,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,    93,    94,    95,     0,     0,     0,
     755,    55,     7,     8,    58,   756,     0,   757,   758,     0,
     759,  1245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,     0,
       0,    48,    93,    94,    95,     0,     0,     0,   755,    55,
       7,     8,    58,   756,     0,   757,   758,     0,   759,  1263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    43,    44,    45,    46,     0,     0,    48,
      93,    94,    95,     0,     0,     0,   755,    55,     7,     8,
      58,   756,     0,   757,   758,     0,   759,  1277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,    93,    94,
      95,     0,     0,     0,   755,    55,     0,     0,    58,   756,
       0,   757,   758,     0,   759,  1310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    43,
      44,    45,    46,     0,     0,    48,    93,    94,    95,     0,
       0,     0,   755,    55,     0,     0,    58,   756,     0,   757,
     758,     0,   759,  1468,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
      79,    -4,    -4,     0,     0,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,    93,    94,    95,   592,     0,     0,
       0,     0,    -4,    -4,    -4,     0,     0,  1641,     0,     0,
       0,  2107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,  2166,
       0,    -4,    -4,    -4,    -4,    -4,    -4,     0,    -4,     0,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,     0,     6,     0,    -4,    -4,    -4,     0,     0,
       0,    -4,     7,     8,     0,     0,    -4,    -4,    -4,    -4,
       0,     0,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,     0,     9,    10,    11,    -4,    -4,    -4,     0,
       0,     0,     0,     0,     0,     0,     0,    -4,     0,    -4,
       0,     0,     0,     0,    12,    13,    14,     0,     0,     0,
      15,    16,     0,     0,     0,    17,     0,     0,     0,     0,
      18,    19,    20,    21,    22,     0,    23,    24,     0,    25,
       0,     0,     0,     0,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,    42,    43,    44,    45,    46,    47,     0,    48,
       0,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,    88,    89,    90,     0,
       0,     0,    91,     0,     0,     0,     0,    92,    93,    94,
      95,   164,   380,    96,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,     7,     8,     0,     0,     0,     0,     0,   115,     0,
     116,     0,     0,     0,   381,   382,   383,   384,   385,   386,
     387,   388,   389,     0,     0,     0,     0,   390,   391,   392,
     393,     0,     0,     0,     0,   394,   395,   396,     0,     0,
       0,     0,   397,     0,   398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     0,
       0,   400,     0,     0,     0,   298,     0,     0,   299,     0,
       0,   300,     0,   301,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,   430,    43,    44,    45,    46,     7,     8,    48,     0,
       0,     0,     0,     0,     0,   755,    55,     0,     0,    58,
     756,     0,   757,   758,     0,   759,     0,     0,     0,  1032,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,     0,     0,     0,  1033,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
     401,   402,   403,     0,     0,     0,     0,     0,     0,     0,
       0,   404,     0,     0,     0,   405,     0,   406,   116,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     755,    55,     0,     0,    58,   756,     0,   757,   758,     0,
     759,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,    93,    94,    95,     0,     0,     0,     0,     0,
       0,  1642,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1656,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1789,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1912,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1913,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1945,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1948,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2017,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2074,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2075,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2090,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2092,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2125,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2153,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2158,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2159,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2160,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2200,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,   815,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
    1067,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,  1126,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,  1171,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,  1172,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,  1216,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,  1248,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,  1268,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,  1324,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,  1344,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,  1425,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
    1426,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,  1472,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,  1545,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,  1844,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,  1855,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,  1892,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,  1967,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,  1982,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,  1994,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,  2018,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,     0,
    2054,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,     0,     0,  2063,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,     0,  2064,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,     0,     0,  2088,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,     0,     0,  2139,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,     0,     0,  2179,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,  2198,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,     0,     0,  2218,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
       0,     0,  2219,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,  2220,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,     0,   934,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,     0,  1960,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,   741,     0,   742,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,   995,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,  1043,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,  1195,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,  1262,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,  1264,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,     0,     0,  1269,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     718,   588,   589,   590,   591,     0,     0,     0,     0,   592,
       0,     0,     0,  1270,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   718,   588,   589,
     590,   591,     0,     0,     0,     0,   592,     0,     0,     0,
    1358,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   718,   588,   589,   590,   591,     0,
       0,     0,     0,   592,     0,     0,     0,  1372,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   718,   588,   589,   590,   591,     0,     0,     0,     0,
     592,     0,     0,     0,  1574,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,     0,
       0,  1662,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   585,   586,   718,   588,   589,   590,   591,
       0,     0,     0,     0,   592,     0,     0,     0,  1713,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   718,   588,   589,   590,   591,     0,     0,     0,
       0,   592,     0,     0,     0,  1904,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   718,
     588,   589,   590,   591,     0,     0,     0,     0,   592,     0,
       0,     0,  1950,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   718,   588,   589,   590,
     591,     0,     0,     0,     0,   592,     0,     0,     0,  1968,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   796,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   797,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   798,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   800,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   801,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   802,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   804,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   805,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   806,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   807,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   808,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   809,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   810,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   812,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   813,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   814,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   881,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   916,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   964,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   983,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   985,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   986,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   987,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,   993,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,   994,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1031,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1042,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1106,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1110,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1122,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1194,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1204,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1205,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1206,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1215,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1217,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1218,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1247,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1249,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1250,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1251,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1252,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1253,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1254,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1255,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1261,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1357,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1371,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1575,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1607,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1608,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1609,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1610,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1648,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1661,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1776,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1778,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1781,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1788,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1845,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1854,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  1877,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  1949,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  2015,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  2016,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592,     0,  2152,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   718,   588,   589,   590,   591,     0,     0,
       0,     0,   592,     0,  2195,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   718,   588,
     589,   590,   591,     0,     0,     0,     0,   592
};

static const yytype_int16 yycheck[] =
{
       3,   142,  1246,     3,   107,  1242,   109,     4,   156,   723,
     315,   631,   632,    62,     4,   736,  1432,  1700,  1744,     6,
    1746,     4,    25,   744,     4,     6,     4,     4,     4,  1928,
       4,    25,     7,     6,   327,     4,     6,     4,   752,   142,
       9,     5,     5,  1731,     6,     4,     4,     0,     5,     5,
      98,    54,     4,   346,   138,   769,     7,     6,   104,   195,
       6,     4,   104,     6,   138,   779,   169,   203,     4,   117,
       4,     9,    14,     4,   239,   240,   241,   242,   243,   250,
      83,   127,   156,   248,     7,   127,   104,   258,    91,     7,
     164,   165,   166,    96,   159,   101,   170,   171,   104,   105,
     106,     9,     9,   187,   107,   237,   238,    90,  1796,   237,
     238,   117,     9,   237,   238,     9,   237,   238,   249,   184,
     413,   249,   415,   250,   138,   253,   258,   249,   255,   253,
     423,   237,   238,  1816,     6,   200,   201,   258,   249,   142,
     107,   108,   156,   143,   147,   148,   149,   253,     9,     8,
     164,   165,   166,   156,     6,    98,   170,   171,   250,   295,
     296,   297,   237,   238,   252,     6,   258,   237,   238,   883,
     258,   174,   249,   179,   251,   246,   247,   237,   238,     8,
     254,   258,   253,   258,  2083,   237,   238,   190,   258,   253,
     237,   238,   195,   257,     6,   198,   245,   246,   258,   172,
     203,   204,   205,   339,   340,   341,   258,   237,   238,     6,
     172,   258,   195,     7,   249,   174,   175,   176,   177,     7,
     356,   237,   238,     6,   221,   199,   184,   185,   258,   237,
     238,   221,   184,   185,   246,   247,   101,  1653,   221,   104,
     254,   106,   258,   255,   221,   221,   254,   222,   223,   224,
     225,  1488,   221,     6,   257,   101,   237,   238,   104,   256,
       7,     6,   249,   253,    68,    69,   253,    71,   271,   249,
     253,   274,   275,   251,  1957,   253,   253,   246,   247,   257,
     249,   275,   251,   253,   253,   221,   255,   290,   291,   253,
     253,   294,   295,   296,   297,   254,   253,   253,   253,   222,
     223,   224,   225,   251,   255,     3,   309,   253,   246,   247,
     313,   249,   315,   251,   250,   249,   252,   255,   249,   143,
     144,  1042,  1043,   246,   247,   149,   429,   620,  2011,   622,
     623,   249,   255,   251,   337,     6,   339,   340,   341,   246,
     247,   249,   249,   251,   251,   252,   639,   255,   255,   246,
     247,     6,   249,   356,   251,   249,   252,   251,   255,   362,
       6,   255,   258,    61,   657,   237,   238,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   237,   238,   680,   249,   248,
     251,   232,   233,  2119,   542,   254,     6,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   138,   552,   420,   421,   248,
     232,   233,   425,   426,   250,   254,   719,   249,   222,   223,
     224,   225,   258,   156,   222,   223,   224,   225,   441,   237,
     238,   164,   165,   166,   142,   448,   251,   170,   171,   147,
     148,   149,   246,   247,   249,   558,   138,   249,   156,    98,
     258,   253,   101,   250,  1178,   104,  1180,   106,   471,   237,
     238,   258,  2155,   250,   156,   222,   223,   224,   225,  1193,
       4,   258,   164,   165,   166,    13,    14,   249,   170,   171,
     258,   253,   190,   237,   238,   237,   238,   500,   249,   246,
     247,   237,   238,   237,   238,   237,   238,   205,   249,   253,
     250,   237,   238,   249,   318,   319,   258,   253,   258,   250,
     249,   524,   326,   327,   258,  2208,   258,   258,   531,   532,
    1946,   254,   258,   536,   250,   538,   539,   540,   541,   542,
     688,   249,   258,   251,   547,   253,   244,   250,   551,   552,
     553,   554,   555,   556,   557,   258,   559,   249,   561,   251,
     254,   259,   260,   557,   258,   559,     8,   104,   249,   106,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   249,   587,   251,   114,   115,   116,   117,
     593,  1305,   120,   237,   238,   736,     7,  1311,   701,   127,
     128,   254,   249,   131,   132,   258,   134,   135,   250,   137,
     252,   254,   615,   616,   258,   258,   258,   237,   238,   143,
     144,   145,   146,   237,   238,   149,   254,   155,   237,   238,
     258,   631,   632,   250,   158,   252,  1256,   161,   258,   138,
      98,   258,  1356,   101,   258,   938,   104,     8,   106,   258,
     249,   179,   180,   181,   237,   238,  1370,   156,   249,   117,
     663,   664,   665,  1377,   249,   164,   165,   166,   249,   249,
     251,   170,   171,   142,   255,   258,   249,   258,   147,   148,
     149,   246,   247,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   795,   696,   697,   698,   699,   700,   249,   702,
     703,   704,   705,   706,   237,   238,   709,   237,   238,   758,
      98,   705,   255,   101,   257,   101,   104,   720,   104,   254,
     106,   190,   420,   258,     4,   258,   254,   249,   258,   117,
     733,   117,   430,   250,   101,   252,   205,   104,  1459,   255,
     743,   258,   258,     6,   254,   250,   749,   252,   258,   250,
     117,   252,   254,   258,   452,   254,   258,   258,   246,   247,
     242,   243,   765,   766,   249,   253,   248,   250,   771,   252,
     773,   912,   253,   776,   777,   143,   144,     6,     7,   254,
     783,   149,   785,   258,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   249,   249,   251,   251,   248,   253,   250,   119,
     252,   222,   223,   224,   225,   818,   254,   820,    98,   249,
     258,   251,   102,   926,     6,   629,   630,  1548,   108,   109,
     634,   111,   112,   254,   104,   246,   247,   258,   536,  1560,
     538,   254,   540,   541,   542,   258,     6,     7,   254,   254,
     853,   131,   258,   258,   254,   254,   554,   555,   258,   258,
     863,     4,   253,     6,  2108,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   249,   254,   251,   106,   248,   258,   250,
     254,   254,   254,   249,   258,   258,   258,   249,   901,   254,
     253,  1042,  1043,   258,  2141,   254,   254,   104,   254,   258,
     258,   914,   258,   237,   238,   239,   240,   241,   242,   243,
     923,   249,   254,  2167,   248,    54,   258,   101,   254,   254,
     253,   934,   258,   258,   254,   249,   254,   251,   258,   637,
     258,  1044,   254,   254,   249,   254,   258,   258,  2185,   258,
     254,   420,   254,   254,   258,   254,   258,   258,   250,   258,
     252,   253,   660,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   104,   254,   254,   253,   248,   258,   258,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   253,   696,   697,
     698,   699,   101,   254,   702,   703,   704,   258,   254,   254,
     101,   254,   258,   258,   712,   258,   254,   715,   254,   254,
     258,   254,   258,   258,   254,   258,   254,   254,   258,   727,
     258,   258,  1337,   254,  1037,   254,   254,   258,   254,   258,
     258,   253,   258,   254,   254,  1048,   104,   258,   258,     4,
    1053,   254,   254,  1194,  1195,   258,   258,     4,   254,   757,
       4,   759,   258,  1066,     4,  1685,  1686,   536,  1071,   538,
     249,   540,   541,     6,   250,   204,   252,   253,   776,   237,
     238,   249,   249,   249,   249,   554,   555,   785,     6,   251,
     249,     6,   253,   257,   251,     6,   249,   253,   249,     9,
     249,  1104,  1105,   257,  1107,  1108,  1109,   249,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,   249,   249,
    1123,   249,   249,   187,   249,   249,   187,   253,   257,   127,
     187,   253,   249,   249,   249,   249,   187,   941,   249,   249,
     253,   249,     4,   249,   948,     6,   253,     6,   952,   253,
     253,   253,   253,   249,   249,   249,   249,   249,  1161,  1162,
    1163,   249,   249,   249,     6,   294,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   251,
     309,   251,  1185,   248,   313,   253,   253,   253,     6,   251,
     253,   251,     6,   187,   253,   249,   249,   249,  1201,  1202,
    1203,   249,   249,   249,     6,     6,   251,     6,     8,   253,
       6,     8,     6,   253,     7,     6,  1357,  1358,   687,   253,
     689,   690,   691,   692,   693,   694,   253,   696,   697,   698,
     699,     6,   253,   702,   703,   704,   254,    93,   258,   937,
     250,   939,   940,   258,     7,  1538,     6,     6,   250,  1542,
    1555,   248,   253,   253,  1257,   953,  1256,   253,   253,    65,
       8,     4,   255,     7,   249,     7,     6,   250,     6,  1272,
    1273,  1274,   253,     7,   972,     6,     6,  1380,     7,  1382,
    1283,     6,     6,   254,   184,  1288,   253,   252,   254,  1292,
     254,   250,   990,     6,   255,   253,   425,   426,  1301,  1103,
    1303,     7,     6,  1306,   249,   251,     6,   776,     6,     4,
     253,   250,   441,     6,     6,     6,   785,     6,  1321,   251,
       7,     7,     7,     7,     7,     7,     7,     7,  1026,     7,
       7,     7,     7,     7,  1337,     7,     7,     7,     6,   253,
     252,   250,   258,  1963,     7,   258,   250,   254,   253,     7,
     258,   254,   258,   255,   253,  1358,   253,     4,     6,   255,
    1363,   254,  1365,   254,   138,   253,     7,     6,   255,     7,
       7,     7,   250,  1071,   250,   258,   258,     9,   258,  1382,
     250,   252,   255,   257,   187,     7,   159,   254,   253,     6,
       6,     6,  1395,     4,    47,    47,  1399,   255,   249,   253,
     249,   253,   255,   249,   249,   255,     4,  1548,     7,   187,
     539,     7,     7,  1561,  1562,   258,   250,     7,     7,     7,
       6,   250,   551,   258,   553,     7,     7,     7,     7,     7,
       4,  1534,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
    1453,  1454,  1455,  1758,   248,   116,     4,     6,  1461,  1462,
    1463,   253,   249,     7,  1162,  1163,     6,   253,     7,     7,
       7,     7,     7,     7,     7,  1478,     6,     6,     6,   104,
       7,     6,     6,     4,     4,   256,  1489,   253,   258,   250,
     258,   253,  1595,     6,  1497,   253,     6,   254,  1501,     6,
       6,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,  1660,
       7,     6,     6,   248,   251,   253,  1224,   249,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   249,   254,     6,     6,
     248,     6,  1555,   255,     6,   252,     6,   258,  1561,  1562,
     131,     6,     6,     6,  1567,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,     4,     6,   250,  1681,     6,
       4,   250,  1585,     6,     4,     7,   253,   253,   253,   253,
    1288,   253,  1595,     6,  1292,   251,     6,  1600,   253,   253,
       6,     6,  1071,  1301,   733,  1303,   183,   253,  1306,   253,
     253,   253,     6,  1761,   254,     6,     6,  1315,   253,     6,
     250,  1724,     6,   249,   258,   258,   253,   258,  1731,  1732,
     258,   255,     7,  1774,   253,     6,     6,     6,     6,   249,
     254,     4,   249,     7,     6,     6,     6,  1750,     6,     6,
       6,     6,   138,   102,     6,     5,   253,   250,   258,   253,
    1358,   253,     6,     6,   138,   138,     6,   258,     6,  1672,
       6,     6,     6,   258,  1677,  1678,     4,   250,   253,  1972,
       6,     6,   258,  1487,     6,  1685,  1686,     6,   258,     6,
       6,     6,   253,  1162,  1163,  2000,     7,  1700,     6,   253,
     142,   253,   253,  1706,     5,   250,     6,     6,     6,     6,
     253,   253,     7,  1716,     6,   182,     6,     6,     6,   250,
       7,     6,   254,  1726,     6,     6,  1729,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   254,  1747,   253,   255,   248,     6,   254,
     254,  1754,   254,   253,     6,  1758,   254,  1760,  1761,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     6,  2068,     6,   253,   248,   250,
       6,   185,     6,     6,   253,   249,   254,   253,  1891,   254,
     250,   253,   253,  1796,   923,     4,     5,   253,   198,     6,
       6,   254,     6,     6,     6,   138,   253,     6,     6,  1613,
       6,     6,     6,  1816,     6,     6,  2109,     6,     6,  1288,
       6,   253,   250,  1292,     6,  1828,  1829,     6,   254,   254,
       6,  1934,  1301,     6,  1303,   253,   253,  1306,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     6,     6,     6,
    1853,    60,    61,    62,    63,   253,     6,     6,  1369,    68,
      69,    70,  1865,  1561,  1562,  2121,    75,   468,    77,  1427,
    1605,  1929,  1889,  1394,     3,  1878,     3,  1668,     3,     3,
    1959,  1531,    91,     3,  1754,    94,  1731,  1585,   608,  1358,
     290,   291,  1562,    -1,    -1,   776,    -1,  1701,  1702,  1703,
    1704,  1705,  1706,    -1,    -1,    -1,    -1,    -1,  1037,    -1,
      -1,    -1,  1915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1053,    -1,    -1,  1930,    -1,    -1,
      -1,    -1,  1935,    -1,    -1,  1938,  1939,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1957,    -1,    -1,  1960,    -1,    -1,
      -1,    -1,    -1,  1963,    -1,    -1,    -1,    -1,  1971,    -1,
      -1,    -1,  1975,    -1,    -1,  1104,  1105,    -1,  1107,  1108,
    1109,  2084,  1111,  1112,  1113,  1114,  1115,  1116,  1117,  1118,
    1119,  1120,    -1,    -1,   203,   204,   205,  2000,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,  2011,   218,
      -1,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,  1726,    -1,
      -1,  1729,  1161,    -1,    -1,    -1,    -1,    -1,  2041,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1744,    -1,  1746,    -1,
      -1,     6,    -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,
      -1,    -1,    -1,  1761,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1796,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2111,  2112,
    2113,  2114,  2115,    -1,    -1,    -1,  1585,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,    -1,    -1,  1272,  1273,  1274,    -1,    -1,    -1,    -1,
      -1,    -1,  2155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   561,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2172,
       6,    -1,  1976,  1977,  1978,  1979,  1980,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,  2194,  1321,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    69,    70,    -1,  2208,    -1,    -1,    75,    -1,
      77,    -1,  2215,  2216,    -1,   615,   616,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,  2229,    94,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,  2040,   104,    -1,   106,
    2044,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
     117,    -1,    -1,  1382,    -1,    -1,    -1,  1726,    -1,    -1,
    1729,    -1,    -1,   663,   664,   665,  1395,   134,    -1,    -1,
    1399,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,  2095,    -1,   248,    -1,  2099,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   709,
      -1,  2115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1453,  1454,  1455,    -1,    -1,    -1,
      -1,    -1,  1461,  1462,  1463,    -1,   203,   204,   205,    -1,
      -1,    -1,    -1,   743,    -1,    -1,    -1,   214,    -1,  1478,
      -1,   218,    -1,   220,   221,  2053,    -1,    -1,  2162,  2163,
    1489,    -1,    -1,    -1,    -1,   765,    -1,    -1,  1497,    -1,
      -1,   771,    -1,   773,    -1,    -1,    -1,    -1,    -1,   246,
     247,    -1,    -1,    -1,    -1,    -1,   253,    -1,   255,    -1,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1567,    -1,
      -1,    -1,    -1,    -1,  2142,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   853,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   863,    -1,    -1,  1595,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,  2194,    -1,    -1,    -1,
      -1,   901,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   914,    -1,    -1,  2215,  2216,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2229,    -1,    -1,   934,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1672,    -1,    -1,    -1,   142,    -1,    -1,
      -1,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,  1700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,   177,    -1,   179,   180,   181,  1716,   183,   184,
     185,   186,   187,   188,   189,    -1,   191,   192,   193,   194,
      -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1760,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1066,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   270,   271,   272,   273,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1816,    -1,    -1,
      -1,    -1,    -1,    -1,   289,   290,   291,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,   311,    -1,    -1,   248,
      -1,    -1,    -1,  1123,  1853,  2194,   321,   322,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,   338,    -1,    -1,  2215,  2216,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2229,    -1,    -1,    -1,    -1,    -1,   361,   362,    -1,    -1,
      -1,   366,   367,   368,    -1,   370,    -1,    -1,    -1,   374,
     375,   376,    -1,    -1,   379,    -1,  1915,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,  1930,  1202,  1203,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      -1,    77,   417,    -1,    -1,    -1,   421,   422,  1957,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,  1971,   438,   439,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,   474,
     475,   476,  2011,  1283,    -1,    -1,   481,    -1,    -1,    -1,
     485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   499,   500,    -1,    -1,    -1,   504,
      -1,    -1,  2041,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,    -1,   534,
     535,    -1,   537,    -1,    -1,    -1,    -1,   203,   204,   205,
      -1,   546,    -1,    -1,   549,   550,    -1,    -1,   214,    -1,
      -1,   556,   218,  1363,   220,  1365,   561,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,    -1,   594,
     595,    -1,    -1,    -1,    -1,    -1,    -1,   602,   603,   604,
       6,    -1,    -1,    -1,    -1,   610,   611,   612,   613,    -1,
     615,   616,    -1,    -1,    -1,    -1,  2155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   634,
     635,   636,    -1,    -1,    -1,   640,   641,   642,   643,   644,
     645,   646,   647,   648,    -1,    -1,    -1,    -1,    -1,   654,
       6,   656,    -1,    -1,   659,    -1,    -1,    -1,   663,   664,
     665,   666,    -1,   668,   669,   670,    -1,    -1,    -1,  2208,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
     695,  1501,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   709,    -1,    -1,    -1,    -1,    -1,
      -1,   716,    -1,   718,    -1,    -1,   721,   722,    -1,    -1,
      -1,    -1,    -1,    -1,   198,   730,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   743,    -1,
     745,    -1,    -1,    -1,    -1,   750,   751,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     765,    -1,   767,   768,    -1,    -1,   771,    -1,   773,   774,
      -1,    -1,    -1,   778,    -1,   780,    -1,    -1,    -1,    -1,
      -1,   786,    -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   816,    -1,   818,    -1,   820,   290,   291,    -1,    -1,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   853,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   863,   864,
     865,    -1,    -1,   337,    -1,    -1,    -1,  1677,  1678,    -1,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   362,    -1,
      -1,    -1,   248,    -1,    -1,    -1,   901,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   922,    -1,    -1,
      -1,   926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   934,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   942,   943,    -1,
      -1,    -1,    -1,   948,    -1,    -1,    -1,   421,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     965,    -1,    -1,   968,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   989,    -1,   991,   992,   248,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1010,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,  1828,  1829,
      -1,    -1,    -1,    -1,    -1,    -1,   500,    -1,  1033,    -1,
      -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,    -1,    -1,
    1045,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     524,    -1,    -1,    -1,    -1,  1060,  1061,   531,   532,    -1,
      -1,  1066,    -1,    -1,    -1,    -1,    -1,    -1,  1878,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,   561,    -1,    -1,
      -1,    -1,    -1,  1098,  1099,  1100,  1101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   587,    -1,    -1,    -1,    -1,  1123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1938,  1939,
      -1,    -1,    -1,    -1,  1139,    -1,    -1,    -1,    -1,    -1,
      -1,   615,   616,    -1,  1149,  1150,  1151,    -1,    -1,    -1,
    1960,  1156,  1157,    -1,  1159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1975,    -1,    -1,  1173,  1174,
      -1,    -1,    -1,    -1,    -1,    -1,  1181,  1182,    -1,    -1,
      -1,    -1,    -1,  1188,    -1,  1190,  1191,    -1,    -1,   663,
     664,   665,  1197,  1198,    -1,    -1,    -1,  1202,  1203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,  1236,    -1,   248,    -1,   709,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1271,    -1,    -1,   743,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,
      -1,    -1,    -1,  2093,    -1,    -1,  1291,    -1,    -1,    -1,
      -1,   765,    -1,    -1,    -1,    -1,    -1,   771,    -1,   773,
      -1,  2111,  2112,  2113,  2114,  2115,    -1,  1312,  1313,    -1,
      -1,    -1,  1317,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1328,   142,    -1,  1331,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   818,    -1,   820,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1359,    -1,    -1,  1362,  1363,  1364,
    1365,    -1,  2172,    -1,    -1,    -1,    -1,    -1,  1373,    -1,
      -1,  1376,    -1,  1378,  1379,  1380,    -1,    -1,    -1,   853,
      -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,   863,
      -1,    -1,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,    -1,   241,   242,    -1,    -1,   901,    -1,    -1,
      -1,    -1,   250,   251,    -1,    -1,    -1,    -1,    -1,    -1,
     914,    -1,    -1,    -1,   262,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1460,    -1,    -1,    -1,    -1,
     934,    -1,    -1,    -1,  1469,  1470,  1471,    -1,    -1,    -1,
      -1,    -1,    -1,  1478,    -1,  1480,    -1,    -1,    -1,    -1,
      -1,    -1,  1487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,
      -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1514,
    1515,  1516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1536,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,  1559,   248,    -1,    -1,    -1,    -1,
    1565,  1566,    -1,   381,   382,   383,    -1,    -1,     6,   387,
     388,   389,   390,   391,   392,   393,    -1,   395,    -1,    -1,
      -1,   399,   400,    -1,    -1,   403,    -1,    -1,    -1,    -1,
      -1,    -1,  1066,    -1,    -1,  1600,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,  1640,  1641,  1642,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1651,    -1,    -1,  1123,
      -1,  1656,  1657,  1658,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1670,    -1,    -1,    -1,    -1,
      -1,    -1,  1677,  1678,  1679,    -1,  1681,    -1,    -1,    -1,
      -1,    -1,  1687,  1688,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1706,    -1,    -1,    -1,    -1,  1711,    -1,    -1,   547,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,
      -1,    -1,  1727,    -1,    -1,    -1,  1731,    -1,  1202,  1203,
      -1,    -1,    -1,    -1,    -1,  1740,  1741,    -1,  1743,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1751,    -1,    -1,    -1,
      -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     598,    -1,  1767,    -1,    -1,    -1,    -1,  1772,  1773,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1786,    -1,    -1,  1789,  1790,    -1,  1792,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,  1283,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1828,  1829,    -1,    -1,    -1,    -1,    -1,
    1835,  1836,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1847,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1874,
    1875,    -1,    -1,  1878,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1363,
      -1,  1365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1912,  1913,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,  1933,    -1,
      -1,   248,    -1,  1938,  1939,  1940,    -1,    -1,    -1,    -1,
    1945,    -1,    -1,  1948,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1960,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1975,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1983,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,   825,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,    -1,   837,
     838,   839,   840,  2008,   842,   843,   844,   845,    -1,  2014,
      -1,    -1,  2017,    -1,     7,    -1,    -1,    -1,   856,    -1,
     858,    -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,
     868,    -1,    -1,    -1,    -1,    -1,    -1,   875,   876,    -1,
      -1,    -1,    -1,    -1,  2049,    -1,   884,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,   879,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2074,
    2075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2089,  2090,    -1,  2092,  2093,    -1,
      -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,
      -1,  2106,    -1,    -1,    -1,    -1,  2111,  2112,  2113,  2114,
    2115,    -1,    -1,    -1,    -1,    -1,  2121,    -1,    -1,    -1,
    2125,    -1,    -1,    -1,    -1,    -1,  1600,    -1,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,  2153,    -1,
      -1,   248,    -1,  2158,  2159,  2160,    -1,   254,   996,   997,
     998,   258,    -1,    -1,  1002,  1003,    -1,  2172,  1006,  1007,
    1008,  1009,    -1,  1011,    -1,    -1,    -1,    -1,  1016,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2200,  2201,  2202,    -1,    -1,
      -1,    -1,    -1,  1677,  1678,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,  1706,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,  1097,
      -1,    -1,    -1,    -1,  1102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1091,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,     3,     4,     5,   248,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,  1828,  1829,    64,    65,    -1,    -1,
      -1,  1199,    -1,    -1,    -1,    73,    74,    -1,  1186,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,  1865,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,
      -1,    -1,    -1,    -1,  1878,   113,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,    -1,   132,     8,   134,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,     8,    -1,
     158,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1938,  1939,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,    -1,    -1,  1960,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,
      -1,  1975,  1340,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1341,  1342,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,    -1,  1381,    -1,   253,    -1,    -1,   256,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,   250,    -1,  1413,  1414,  1415,  1416,  1417,
      -1,   258,    -1,    -1,  1422,  1423,    -1,    -1,    -1,    -1,
    1428,    -1,  1430,    -1,    -1,    -1,  1434,    -1,    -1,  1437,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1449,    -1,    -1,  1432,    -1,    -1,    -1,    -1,  2093,
      -1,    -1,    -1,    -1,  1442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2111,  2112,  2113,
    2114,  2115,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,  1522,    -1,  1524,     8,   248,    -1,
    1528,    -1,  1530,    -1,    -1,    -1,    -1,    -1,  2172,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,  1561,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,  1599,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    68,    69,    70,    -1,    -1,
      73,    74,    75,    -1,    77,    78,    79,    80,    -1,    -1,
      -1,  1659,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,  1763,    -1,   248,  1766,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,     8,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   220,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,  1817,
    1818,   244,  1820,    -1,    -1,    -1,   249,    -1,    -1,    -1,
     253,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,  1882,  1883,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    68,    69,
      70,    -1,    -1,    73,    74,    75,    -1,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,  1931,    94,    -1,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,
      -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,   206,   207,    -1,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
     220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
       3,     4,     5,   253,     7,    -1,   256,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    -1,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      -1,    94,    -1,  2181,    -1,    98,    -1,    -1,   101,     5,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   220,   221,   222,
     223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,   246,   247,    -1,   249,    -1,   251,     3,
       4,    -1,   255,   256,     8,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,   214,    -1,
      64,    65,   218,    -1,   220,    -1,    -1,    -1,    -1,    73,
      74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,   252,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,     3,     4,     5,    -1,
     254,    -1,   256,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,    -1,   149,   150,   151,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,
     207,    -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,
     217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,   249,     3,     4,    -1,   253,    -1,    -1,   256,
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
      -1,   161,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
       3,     4,    -1,   253,   254,    -1,   256,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,   249,     3,     4,    -1,
     253,    -1,    -1,   256,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   158,    -1,    -1,   161,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
     206,   207,    -1,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,     3,     4,    -1,   253,    -1,    -1,
     256,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,    -1,   132,    -1,   134,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,    -1,
     149,   150,   151,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
     249,     3,     4,    -1,   253,    -1,    -1,   256,    10,    11,
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
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,     4,
      -1,    -1,   254,    -1,   256,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,   134,
      -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,   249,     3,     4,    -1,   253,    -1,
      -1,   256,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     158,    -1,    -1,   161,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,   253,    -1,    -1,   256,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
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
     161,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,
       4,    -1,   253,    -1,     8,   256,    10,    11,    12,    -1,
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
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,     3,     4,    -1,    -1,   249,     8,    -1,    10,    11,
      12,    -1,   256,    15,    16,    17,    18,    19,    20,    21,
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
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,    -1,   249,    -1,    -1,
      10,    11,    12,    -1,   256,    15,    16,    17,    18,    19,
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
      -1,   161,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
       3,     4,    -1,   253,    -1,    -1,   256,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,
      -1,   134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,   249,     3,     4,    -1,
     253,    -1,    -1,   256,    10,    11,    12,    -1,    -1,    15,
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
      -1,    -1,   158,    -1,    -1,   161,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
     206,   207,    -1,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,     3,
       4,     5,    -1,   249,    -1,    -1,    10,    11,    12,    -1,
     256,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    -1,
      94,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,   220,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,
      -1,    -1,   256,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,   220,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,     4,
       5,   253,    -1,    -1,   256,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    -1,    94,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    -1,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,   220,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,    -1,
      -1,   256,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,   220,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,     3,     4,    -1,    -1,   249,    -1,    -1,    10,
      11,    12,    -1,   256,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    89,    90,
      -1,    92,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,    -1,   258,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,   253,    -1,    -1,   256,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   258,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,     3,     4,    -1,   253,    -1,     8,   256,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,     3,     4,    -1,    89,    90,
      -1,    92,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,    -1,   258,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   258,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
       6,   249,   250,    -1,    10,    11,    12,    -1,   256,    15,
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
      -1,    -1,    -1,    89,    90,    -1,    92,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,   202,    -1,    -1,   248,
     206,    -1,    -1,    -1,   253,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,   202,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,     3,
       4,    -1,     6,   249,    -1,    -1,    10,    11,    12,    -1,
     256,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,     3,     4,    -1,    89,    90,    -1,    92,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    92,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,    -1,   258,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,   256,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   258,    -1,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,     3,     4,    -1,    -1,   249,   250,
      -1,    10,    11,    12,    -1,   256,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      89,    90,    -1,    92,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    -1,    92,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,   202,    -1,    -1,    -1,   206,    -1,   258,
      -1,    -1,   211,   212,   213,    -1,   215,   216,   217,    -1,
      -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
     249,   250,    -1,    -1,    -1,    -1,    -1,   256,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,
     206,   258,    -1,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,     4,     5,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,     4,     5,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,   117,    -1,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,   134,    75,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,    -1,   220,   221,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   250,    -1,
     252,   253,   258,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   214,    -1,    -1,    -1,   218,    -1,   220,   221,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    -1,    -1,    -1,   114,   115,   116,   117,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,   253,    -1,   131,   132,    -1,   134,   135,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,   114,   115,   116,   117,    13,    14,
     120,   179,   180,   181,    -1,    -1,    -1,   127,   128,    -1,
      -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    13,    14,   248,   179,
     180,   181,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,   114,
     115,   116,   117,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    13,    14,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
     155,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,   114,   115,   116,
     117,    -1,    -1,   120,   179,   180,   181,    -1,    -1,    -1,
     127,   128,    13,    14,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,   114,   115,   116,   117,    -1,
      -1,   120,   179,   180,   181,    -1,    -1,    -1,   127,   128,
      13,    14,   131,   132,    -1,   134,   135,    -1,   137,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,   120,
     179,   180,   181,    -1,    -1,    -1,   127,   128,    13,    14,
     131,   132,    -1,   134,   135,    -1,   137,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,   114,   115,   116,   117,    -1,    -1,   120,   179,   180,
     181,    -1,    -1,    -1,   127,   128,    13,    14,   131,   132,
      -1,   134,   135,    -1,   137,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,   114,
     115,   116,   117,    -1,    -1,   120,   179,   180,   181,    -1,
      -1,    -1,   127,   128,    13,    14,   131,   132,    -1,   134,
     135,    -1,   137,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,   114,   115,   116,
     117,    -1,    -1,   120,   179,   180,   181,    -1,    -1,    -1,
     127,   128,    13,    14,   131,   132,    -1,   134,   135,    -1,
     137,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,   114,   115,   116,   117,    -1,
      -1,   120,   179,   180,   181,    -1,    -1,    -1,   127,   128,
      13,    14,   131,   132,    -1,   134,   135,    -1,   137,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,   120,
     179,   180,   181,    -1,    -1,    -1,   127,   128,    13,    14,
     131,   132,    -1,   134,   135,    -1,   137,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,   114,   115,   116,   117,    -1,    -1,   120,   179,   180,
     181,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,   114,
     115,   116,   117,    -1,    -1,   120,   179,   180,   181,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,   254,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    13,    14,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   179,   180,   181,   248,    -1,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,   258,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    88,    -1,    90,    -1,
      -1,    -1,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   254,
      -1,   113,   114,   115,   116,   117,   118,    -1,   120,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    -1,    -1,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,     4,    -1,   167,   168,   169,    -1,    -1,
      -1,   173,    13,    14,    -1,    -1,   178,   179,   180,   181,
      -1,    -1,   184,    -1,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,    -1,    44,    45,    46,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,   221,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    87,    88,    -1,    90,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,   114,   115,   116,   117,   118,    -1,   120,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    -1,    -1,   139,   140,
     141,    -1,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,   168,   169,    -1,
      -1,    -1,   173,    -1,    -1,    -1,    -1,   178,   179,   180,
     181,     4,     5,   184,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,    -1,    -1,   208,   209,   210,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,   219,    -1,
     221,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,    -1,
      -1,   134,   114,   115,   116,   117,    13,    14,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,
     132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     203,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,    -1,   220,   221,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,   179,   180,   181,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
     254,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,   254,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,   254,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,   254,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,   253,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,    -1,   252,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   252,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,   252,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,   252,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,   252,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
     252,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,   252,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,   252,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,   252,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,   252,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,   250,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   260,   261,     6,     0,     4,    13,    14,    44,
      45,    46,    65,    66,    67,    71,    72,    76,    81,    82,
      83,    84,    85,    87,    88,    90,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   113,   114,   115,   116,   117,   118,   120,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   139,   140,   141,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   167,   168,
     169,   173,   178,   179,   180,   181,   184,   186,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   208,   209,   210,   219,   221,   262,   264,   265,
     285,   304,   306,   310,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   328,   330,   331,   337,   338,   339,   340,
     346,   371,   372,   253,   257,    14,   104,   249,   249,   249,
       6,   253,     6,     6,     6,     6,   249,     6,     6,   253,
       6,     6,   251,   251,     4,   348,   372,   249,   251,   283,
      98,   101,   104,   106,   283,   249,   249,   249,     4,   249,
     249,   249,     4,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   253,   119,   104,     6,   253,    98,
     101,   104,   117,   309,   106,   249,     3,    10,    11,    12,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    56,
      57,    58,    59,    64,    65,    73,    74,    78,    79,    80,
      89,    92,    98,   101,   104,   106,   117,   127,   132,   134,
     137,   202,   206,   207,   211,   212,   213,   215,   216,   217,
     237,   238,   244,   249,   253,   256,   306,   307,   310,   321,
     328,   330,   341,   342,   346,   348,   355,   357,   372,   249,
     253,   253,   104,   104,   127,   101,   104,   106,    98,   101,
     104,   106,   306,   101,   104,   105,   106,   117,   179,   307,
     101,   104,   249,   101,   159,   184,   200,   201,   253,   237,
     238,   249,   253,   352,   353,   352,   253,   253,   352,     4,
      98,   102,   108,   109,   111,   112,   131,   253,   249,   104,
     106,   104,   101,     4,    90,   195,   253,   372,     4,     6,
      98,   101,   104,   101,   104,   117,   308,     4,     4,     4,
       5,   249,   253,   355,   356,     4,   249,   249,   249,     4,
     253,   359,   372,     4,   249,   249,   249,     6,     6,   251,
       5,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      60,    61,    62,    63,    68,    69,    70,    75,    77,    91,
      94,   203,   204,   205,   214,   218,   220,   363,   372,   249,
       4,   363,     5,   253,     5,   253,    32,   238,   341,   372,
     251,   253,   249,   253,     6,   249,   253,     6,   257,     7,
     134,   195,   222,   223,   224,   225,   246,   247,   249,   251,
     255,   281,   282,   283,   306,   341,   362,   363,   372,     4,
     310,   311,   312,   253,     6,   341,   362,   363,   372,   362,
     362,   341,   362,   369,   370,   372,   341,   287,   291,   249,
     351,     9,   363,   249,   249,   249,   249,   372,   341,   341,
     341,   249,   341,   341,   341,   249,   341,   341,   341,   341,
     341,   341,   341,   362,   341,   341,   341,   341,   356,   249,
     238,   341,   357,   358,   253,   356,   355,   362,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   249,   251,   283,   283,   283,   283,   283,   283,   249,
     283,   283,   249,   306,   307,   307,   283,   283,     5,   253,
     253,   127,   306,   306,   249,   283,   283,   249,   249,   249,
     341,   253,   341,   357,   341,   341,   254,   358,   348,   372,
     187,     5,   253,     8,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   248,     9,   249,   251,   255,   282,   283,   341,
     358,   358,   249,   249,   249,   355,   356,   356,   356,   305,
     249,   253,   249,   249,   355,   253,   253,   341,     4,   355,
     253,   359,   253,   253,   352,   352,   352,   341,   341,   237,
     238,   253,   253,   352,   237,   238,   249,   312,   352,   253,
     249,   253,   249,   249,   249,   249,   249,   249,   249,   358,
     341,   356,   356,   356,   249,     4,   251,   253,     6,   251,
     312,     6,     6,   253,   253,   253,   253,   356,   251,   251,
     251,   341,     8,     6,     6,   341,   341,   341,   255,   341,
     253,   187,   341,   341,   341,   341,   283,   283,   283,   249,
     249,   249,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   249,   249,   283,   249,   251,     6,     6,   253,
       6,     8,   312,     6,     8,   312,   283,   341,   239,   253,
       9,   249,   251,   255,   362,   358,   341,   312,   355,   355,
     253,   363,   306,     7,   341,   341,     4,   184,   185,   355,
       6,   250,   252,   253,   284,   253,     6,   253,     6,     9,
     249,   251,   255,   372,   254,   127,   132,   134,   135,   137,
     304,   306,   341,     6,   250,   258,     9,   249,   251,   255,
     250,   258,   250,   258,   258,   250,   258,     9,   249,   255,
     258,   252,   258,   286,   252,   286,    93,   350,   347,   372,
     258,   341,   341,   341,   341,   258,   250,   250,   250,   341,
     250,   250,   250,   341,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   254,     7,   341,   239,   254,
     258,   341,     6,     6,   250,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   357,   341,   341,   341,   341,   341,   341,   341,
     357,   357,   372,   253,   341,   341,   362,   341,   362,   355,
     362,   362,   369,   253,   253,   253,   341,   284,   372,     8,
     341,   341,   356,   355,   362,   362,   357,   348,   363,   348,
     358,   250,   254,   255,   283,    65,     8,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   253,   341,   357,   341,   341,   341,   341,   341,   372,
     341,   341,     4,   349,   253,   284,   250,   254,   254,   341,
     341,   341,     7,     7,   334,   334,   249,   341,   341,   341,
     341,     6,   358,   358,   253,   250,     6,   312,   253,   312,
     312,   258,   258,   258,   352,   352,   311,   311,   258,   341,
     254,   325,   258,   312,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   254,   250,     7,   335,     6,     7,   341,
       6,   341,   312,   341,   254,   358,   358,   358,   341,     6,
     341,   341,   341,   250,   254,   250,   250,   250,   184,   258,
     312,   253,     8,   250,   250,   252,   369,   362,   369,   362,
     362,   362,   362,   362,   362,   341,   362,   362,   362,   362,
     256,   365,   372,   363,   362,   362,   362,   348,   372,   358,
     254,   254,   254,   254,   341,   341,   312,   372,   349,   252,
     254,   250,   141,   159,   329,   250,   254,   258,   341,     6,
     253,   355,   250,   252,     7,   281,   282,   255,     7,     6,
     358,     7,   225,   281,   341,   266,   372,   341,   341,   349,
     251,   249,   127,   306,   307,   306,   253,   254,     6,   232,
     233,   263,   358,   372,   341,   341,     4,   349,     6,   358,
       6,   358,   341,     6,   362,   370,   372,   250,   349,   341,
       6,   372,     6,   362,   341,   250,   251,   341,   258,   258,
     258,   258,   363,     7,     7,     7,   250,     7,     7,     7,
     250,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   341,   250,   253,   341,   357,   254,     6,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   258,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   258,
     258,   258,   250,   252,   252,   358,   258,   258,   284,   258,
     284,   258,   258,   258,   250,   358,   341,   341,   343,   284,
     254,   254,   254,   258,   258,   284,   284,   250,   255,   250,
     255,   258,   283,   344,   254,     7,   349,   284,   253,   254,
       8,     8,   358,   255,   250,   252,   282,   249,   251,   283,
     358,     7,   253,   253,   250,   250,   250,   341,   355,     4,
     333,     6,   300,   341,   363,   250,   254,   250,   250,   254,
     254,   358,   255,   254,   312,   254,   254,   352,   341,   341,
     254,   254,   341,   352,   138,   138,   156,   164,   165,   166,
     170,   171,   326,   327,   352,   254,   322,   250,   254,   250,
     250,   250,   250,   250,   250,   250,   253,     7,   341,     6,
     341,   250,   252,   254,   252,   254,   254,   254,   254,   252,
     252,   258,     7,     7,     7,   255,   341,   254,   341,   341,
       7,   255,   284,   258,   284,   284,   250,   250,   258,   284,
     284,   258,   258,   284,   284,   284,   284,   341,   284,     9,
     364,   258,   250,   258,   284,   255,   258,   345,   252,   254,
     254,   255,   249,   251,   257,   187,     7,   159,     6,   341,
     254,   253,     6,   355,   254,   341,     6,     7,   281,   282,
     255,   281,   282,   363,   341,     6,     4,   253,   360,   372,
     254,    47,    47,   355,   254,     4,   174,   175,   176,   177,
     254,   269,   273,   276,   278,   279,   255,   250,   252,   249,
     341,   341,   249,   253,   249,   253,     8,   358,   362,   250,
     255,   250,   252,   249,   250,   250,   258,   255,   249,   258,
       7,   283,     4,   294,   295,   296,   284,   341,   341,   341,
     341,   284,   352,   355,   355,     7,   355,   355,   355,     7,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
       6,     7,   358,   341,   341,   341,   341,   254,   341,   341,
     341,   355,   362,   362,   254,   254,   254,   258,   293,   341,
     341,   349,   349,   341,   341,   250,   355,   283,   341,   341,
     341,   254,   349,   282,   255,   282,   341,   341,   284,   254,
     355,   358,   358,     7,     7,     7,   138,   332,     6,   250,
     258,     7,     7,     7,     7,     7,   254,     4,   254,   258,
     258,   258,   254,   254,   116,     4,     6,   341,   253,     6,
     249,     6,   172,     6,   172,   254,   327,   258,   326,     7,
       6,     7,     7,     7,     7,     7,     7,     7,   311,   355,
       6,   253,     6,     6,     6,   104,     7,     6,     6,   341,
     355,   355,   355,     4,   258,     8,     8,   250,     4,   107,
     108,     4,   358,   362,   341,   362,   256,   258,   297,   362,
     362,   349,   362,   250,   258,   349,   253,   306,   253,     6,
     341,     6,   253,   355,   254,   254,   341,     6,     4,   184,
     185,   341,     6,     6,     6,     7,   359,   361,     6,   251,
     284,   283,   283,     6,   270,   249,   249,   253,   280,     6,
     349,   255,   362,   341,   252,   250,   341,     8,   358,   341,
     358,   254,   254,     6,     6,   263,   349,   255,   341,     6,
       6,   341,   349,   250,   341,   253,   341,   363,   284,    47,
     253,   355,   363,   366,   252,   258,     6,   250,   250,   250,
     250,     6,     6,   131,   302,   302,   355,     6,     6,     6,
     355,   138,   187,   301,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     5,   254,   284,   284,   284,   284,   284,
     258,   258,   258,   250,   284,   284,   295,   284,   250,   284,
     250,   283,   344,   284,     6,   284,   258,   249,   251,   283,
       4,   250,   252,   284,     6,   254,   254,   355,   355,   355,
       4,     6,   281,   341,   355,   355,   355,   253,   253,     7,
       6,     7,   341,   341,   341,   253,   253,   253,   251,     6,
     341,   355,   341,     6,     6,   341,   352,   254,     5,   355,
     253,   253,   253,   253,   253,   253,   253,   355,   254,     6,
     358,   253,   341,   252,     6,     6,   183,   341,   341,   341,
       6,     6,     6,     6,     7,   284,   258,   258,   284,   258,
     341,     4,   199,   298,   299,   284,   250,   284,   345,   363,
     249,   251,   341,   253,   312,     6,   312,   258,     6,     6,
       7,   281,   282,   255,     7,     6,   359,   254,   258,   341,
     281,   253,   284,   367,   368,   369,   367,   249,   341,   341,
     354,   355,   253,   249,     4,     6,   250,     6,   250,   254,
     254,   250,   254,     6,     6,   362,   249,     4,   250,   258,
     249,   254,   258,   355,   363,     7,   283,   292,   341,   357,
     296,     6,     6,     6,     6,   352,     6,     6,     6,   138,
     303,    98,   117,   102,     6,     5,   253,   341,   341,   341,
     341,   250,   344,   341,   341,   341,   284,   282,   253,   253,
       6,   301,     6,   341,   355,   138,   138,     4,     6,   358,
     358,   341,   341,   363,   254,   250,   254,   258,   311,   311,
     341,   341,   254,   258,   250,   254,   258,     6,     6,   354,
     352,   352,   352,   352,   352,   238,   352,     6,   254,   341,
       6,     6,   355,   254,   258,     8,   254,   250,   253,   341,
     363,   362,   341,   362,   341,   363,   366,   368,   363,   258,
     250,   258,   254,   341,   329,   329,   355,   363,   341,     6,
       4,   360,     6,   359,   252,   355,   369,     6,   284,   284,
     267,   341,   258,   258,   254,   258,   268,   341,   341,     6,
       6,     6,     6,   341,   341,   250,     6,   341,   288,   290,
     253,   368,   254,   258,     7,     7,   142,     6,   253,   253,
     253,     5,   354,   284,   284,   258,   284,   250,   258,   250,
     252,   358,   358,     6,     6,   341,   341,   253,   254,   254,
     253,     6,     6,   253,   341,   254,   254,   254,   252,     6,
     355,     7,   253,   341,   254,   258,   258,   258,   258,   258,
     258,     6,   254,   182,   341,   341,   358,     6,     6,   250,
     284,   284,   299,   363,   254,   254,   254,   254,     6,     6,
       7,     6,   255,     6,   254,     6,     6,   250,   258,   341,
     341,   253,   355,   254,   258,   250,   250,   258,   254,   293,
     297,   355,   284,   341,   363,   372,   358,   358,   341,     6,
     254,   341,   344,   341,   254,   254,     6,     6,   354,   143,
     144,   149,   336,   143,   144,   336,   358,   311,   254,   258,
       6,   254,   355,   312,   254,     6,   358,   352,   352,   352,
     352,   352,   341,   254,   254,   254,   250,     6,   253,     6,
     359,   185,   271,   341,   258,   258,   354,     6,   341,   341,
       6,   254,   254,   289,     7,   249,   254,   254,   254,   253,
     258,   250,   258,   253,   254,   253,   352,   355,     6,   253,
     352,     6,   254,   254,   341,     6,   138,   254,   323,   253,
     254,   258,   258,   258,   258,   258,     6,     6,     6,   312,
       6,   253,   341,   341,   254,   258,   293,   363,   250,   341,
     341,   341,   358,     6,   352,     6,   352,     6,     6,   254,
     341,   326,   312,     6,   358,   358,   358,   358,   352,   358,
     329,   268,   250,   258,     6,   253,   341,   254,   258,   258,
     258,   254,   258,   258,     6,   254,   254,   324,   254,   254,
     254,   254,   258,   254,   254,   254,   274,   341,   354,   254,
     341,   341,   341,   352,   352,   326,     6,     6,     6,     6,
     358,     6,     6,     6,   253,   250,   254,     6,   254,   284,
     258,   258,   258,   254,   254,   272,   362,   277,   253,     6,
     341,   341,   341,     6,   254,   258,   253,   354,   254,   254,
     254,     6,   362,   275,   362,   254,     6,     6,   254,   258,
       6,     6,   362
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
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsFromVisibleViews"))
	PView::combine(false, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "ElementsByViewName"))
	PView::combine(false, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromAllViews"))
	PView::combine(true, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsFromVisibleViews"))
	PView::combine(true, 0, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeStepsByViewName"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "Views"))
	PView::combine(false, 1, CTX::instance()->post.combineRemoveOrig);
      else if(!strcmp((yyvsp[(2) - (3)].c), "TimeSteps"))
	PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
      else
	yymsg(0, "Unknown 'Combine' command");
#endif
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 269:
#line 3486 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 270:
#line 3490 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 271:
#line 3495 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 272:
#line 3502 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 273:
#line 3507 "Gmsh.y"
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
#line 3517 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 275:
#line 3522 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 276:
#line 3528 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 277:
#line 3536 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 278:
#line 3540 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 279:
#line 3544 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 280:
#line 3548 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 281:
#line 3552 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 282:
#line 3556 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 283:
#line 3560 "Gmsh.y"
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
#line 3570 "Gmsh.y"
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
#line 3633 "Gmsh.y"
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
#line 3649 "Gmsh.y"
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
#line 3666 "Gmsh.y"
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
#line 3683 "Gmsh.y"
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
#line 3705 "Gmsh.y"
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
#line 3727 "Gmsh.y"
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
#line 3762 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 292:
#line 3770 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 293:
#line 3778 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 294:
#line 3784 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 295:
#line 3791 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 296:
#line 3798 "Gmsh.y"
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
#line 3818 "Gmsh.y"
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
#line 3844 "Gmsh.y"
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
#line 3856 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 300:
#line 3867 "Gmsh.y"
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
#line 3885 "Gmsh.y"
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
#line 3903 "Gmsh.y"
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
#line 3921 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 304:
#line 3927 "Gmsh.y"
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
#line 3945 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 306:
#line 3951 "Gmsh.y"
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
#line 3971 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 308:
#line 3977 "Gmsh.y"
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
#line 3995 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 310:
#line 4001 "Gmsh.y"
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
#line 4018 "Gmsh.y"
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
#line 4034 "Gmsh.y"
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
#line 4051 "Gmsh.y"
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
#line 4069 "Gmsh.y"
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
#line 4092 "Gmsh.y"
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
#line 4119 "Gmsh.y"
    {
    ;}
    break;

  case 317:
#line 4122 "Gmsh.y"
    {
    ;}
    break;

  case 318:
#line 4128 "Gmsh.y"
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
#line 4140 "Gmsh.y"
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
#line 4160 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 321:
#line 4164 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 322:
#line 4168 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 323:
#line 4172 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 324:
#line 4176 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 325:
#line 4180 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 326:
#line 4184 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 327:
#line 4188 "Gmsh.y"
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
#line 4197 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 329:
#line 4209 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 330:
#line 4210 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 331:
#line 4211 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 332:
#line 4212 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 333:
#line 4213 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 334:
#line 4217 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 335:
#line 4218 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 336:
#line 4219 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 337:
#line 4220 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 338:
#line 4221 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 339:
#line 4226 "Gmsh.y"
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
#line 4249 "Gmsh.y"
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
#line 4269 "Gmsh.y"
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
#line 4290 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 343:
#line 4294 "Gmsh.y"
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
#line 4309 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 345:
#line 4313 "Gmsh.y"
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
#line 4329 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 347:
#line 4333 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 348:
#line 4338 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 349:
#line 4342 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 350:
#line 4348 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 351:
#line 4352 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 352:
#line 4359 "Gmsh.y"
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
#line 4381 "Gmsh.y"
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
#line 4422 "Gmsh.y"
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
#line 4466 "Gmsh.y"
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
#line 4505 "Gmsh.y"
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
#line 4530 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GVertex *gf = GModel::current()->getVertexByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Vertex %d",tag);
      }
    ;}
    break;

  case 358:
#line 4542 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GEdge *gf = GModel::current()->getEdgeByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Edge %d",tag);
      }
    ;}
    break;

  case 359:
#line 4554 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GFace *gf = GModel::current()->getFaceByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Face %d",tag);
      }
    ;}
    break;

  case 360:
#line 4566 "Gmsh.y"
    {
      int tag = (int)(yyvsp[(4) - (8)].d);
      GRegion *gf = GModel::current()->getRegionByTag(tag);
      if(gf){
	int new_tag = (int)(yyvsp[(6) - (8)].d);
	gf->setTag(new_tag);
      }
      else{
	yymsg(0, "Unknown Model Region %d",tag);
      }
    ;}
    break;

  case 361:
#line 4578 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 362:
#line 4587 "Gmsh.y"
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

  case 363:
#line 4617 "Gmsh.y"
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

  case 364:
#line 4643 "Gmsh.y"
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

  case 365:
#line 4670 "Gmsh.y"
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

  case 366:
#line 4702 "Gmsh.y"
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

  case 367:
#line 4729 "Gmsh.y"
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

  case 368:
#line 4755 "Gmsh.y"
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

  case 369:
#line 4781 "Gmsh.y"
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

  case 370:
#line 4807 "Gmsh.y"
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

  case 371:
#line 4833 "Gmsh.y"
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

  case 372:
#line 4854 "Gmsh.y"
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

  case 373:
#line 4865 "Gmsh.y"
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

  case 374:
#line 4913 "Gmsh.y"
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

  case 375:
#line 4967 "Gmsh.y"
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

  case 376:
#line 4982 "Gmsh.y"
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

  case 377:
#line 4994 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 378:
#line 5005 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 379:
#line 5012 "Gmsh.y"
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

  case 380:
#line 5027 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 381:
#line 5040 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 382:
#line 5041 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 383:
#line 5042 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 384:
#line 5047 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 385:
#line 5053 "Gmsh.y"
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

  case 386:
#line 5065 "Gmsh.y"
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

  case 387:
#line 5083 "Gmsh.y"
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

  case 388:
#line 5110 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 389:
#line 5111 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 390:
#line 5112 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 391:
#line 5113 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 392:
#line 5114 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 393:
#line 5115 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 394:
#line 5116 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 395:
#line 5117 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 396:
#line 5119 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 397:
#line 5125 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 398:
#line 5126 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 399:
#line 5127 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 400:
#line 5128 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 401:
#line 5129 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 402:
#line 5130 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 403:
#line 5131 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 404:
#line 5132 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 405:
#line 5133 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 406:
#line 5134 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 407:
#line 5135 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 408:
#line 5136 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 409:
#line 5137 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 410:
#line 5138 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 411:
#line 5139 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 412:
#line 5140 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 413:
#line 5141 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 414:
#line 5142 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 415:
#line 5143 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 416:
#line 5144 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 417:
#line 5145 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5146 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 419:
#line 5147 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5148 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 421:
#line 5149 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5150 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 423:
#line 5151 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5152 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5153 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 426:
#line 5154 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 427:
#line 5155 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 428:
#line 5156 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 429:
#line 5157 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 430:
#line 5158 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 431:
#line 5159 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 432:
#line 5160 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 433:
#line 5161 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 434:
#line 5162 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 435:
#line 5171 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 436:
#line 5172 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 437:
#line 5173 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 438:
#line 5174 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 439:
#line 5175 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 440:
#line 5176 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 441:
#line 5177 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 442:
#line 5178 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 443:
#line 5179 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 444:
#line 5180 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 445:
#line 5181 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 446:
#line 5186 "Gmsh.y"
    { init_options(); ;}
    break;

  case 447:
#line 5188 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 448:
#line 5194 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 449:
#line 5196 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 450:
#line 5201 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 451:
#line 5206 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 452:
#line 5211 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 453:
#line 5216 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 454:
#line 5220 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 455:
#line 5224 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 456:
#line 5228 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 457:
#line 5232 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 458:
#line 5236 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 459:
#line 5240 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 460:
#line 5244 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 461:
#line 5250 "Gmsh.y"
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

  case 462:
#line 5265 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 463:
#line 5269 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 464:
#line 5275 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 465:
#line 5280 "Gmsh.y"
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

  case 466:
#line 5299 "Gmsh.y"
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

  case 467:
#line 5319 "Gmsh.y"
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
#line 5350 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 469:
#line 5354 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 470:
#line 5358 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 471:
#line 5362 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 472:
#line 5366 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 473:
#line 5370 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 474:
#line 5374 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 475:
#line 5379 "Gmsh.y"
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

  case 476:
#line 5389 "Gmsh.y"
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

  case 477:
#line 5399 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 478:
#line 5404 "Gmsh.y"
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

  case 479:
#line 5415 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 480:
#line 5424 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 481:
#line 5429 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 482:
#line 5434 "Gmsh.y"
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

  case 483:
#line 5461 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 484:
#line 5463 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 485:
#line 5468 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 486:
#line 5470 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 487:
#line 5475 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 488:
#line 5482 "Gmsh.y"
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

  case 489:
#line 5498 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 490:
#line 5500 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 491:
#line 5505 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 492:
#line 5514 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 493:
#line 5516 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 494:
#line 5521 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 495:
#line 5523 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 496:
#line 5528 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 497:
#line 5532 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 498:
#line 5536 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 499:
#line 5540 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 500:
#line 5544 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 501:
#line 5551 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 502:
#line 5555 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 503:
#line 5559 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 504:
#line 5563 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 505:
#line 5570 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 506:
#line 5575 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 507:
#line 5582 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 508:
#line 5587 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 509:
#line 5591 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 510:
#line 5596 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 511:
#line 5600 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 512:
#line 5608 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 513:
#line 5619 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 514:
#line 5623 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 515:
#line 5627 "Gmsh.y"
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

  case 516:
#line 5641 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 517:
#line 5649 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 518:
#line 5657 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 519:
#line 5664 "Gmsh.y"
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

  case 520:
#line 5674 "Gmsh.y"
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

  case 521:
#line 5697 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 522:
#line 5702 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 523:
#line 5708 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 524:
#line 5713 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 525:
#line 5719 "Gmsh.y"
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

  case 526:
#line 5730 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 527:
#line 5737 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 528:
#line 5742 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 529:
#line 5748 "Gmsh.y"
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

  case 530:
#line 5760 "Gmsh.y"
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

  case 531:
#line 5774 "Gmsh.y"
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

  case 532:
#line 5784 "Gmsh.y"
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
#line 5794 "Gmsh.y"
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
#line 5804 "Gmsh.y"
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

  case 535:
#line 5816 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 536:
#line 5820 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 537:
#line 5825 "Gmsh.y"
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

  case 538:
#line 5837 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 539:
#line 5841 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 540:
#line 5845 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 541:
#line 5849 "Gmsh.y"
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

  case 542:
#line 5867 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 543:
#line 5875 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 544:
#line 5883 "Gmsh.y"
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

  case 545:
#line 5912 "Gmsh.y"
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

  case 546:
#line 5922 "Gmsh.y"
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

  case 547:
#line 5938 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 548:
#line 5949 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 549:
#line 5954 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 550:
#line 5958 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 551:
#line 5962 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 552:
#line 5974 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 553:
#line 5978 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 554:
#line 5990 "Gmsh.y"
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

  case 555:
#line 6007 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 556:
#line 6017 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 557:
#line 6021 "Gmsh.y"
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

  case 558:
#line 6036 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 559:
#line 6041 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 560:
#line 6048 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 561:
#line 6052 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 562:
#line 6057 "Gmsh.y"
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

  case 563:
#line 6071 "Gmsh.y"
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
#line 6087 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 565:
#line 6091 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 566:
#line 6095 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 567:
#line 6099 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 568:
#line 6103 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 569:
#line 6111 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 570:
#line 6117 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 571:
#line 6126 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 572:
#line 6130 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 573:
#line 6134 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 574:
#line 6142 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 575:
#line 6148 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 576:
#line 6154 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 577:
#line 6158 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 6166 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 579:
#line 6174 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 580:
#line 6181 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 581:
#line 6190 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 582:
#line 6194 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 583:
#line 6198 "Gmsh.y"
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

  case 584:
#line 6213 "Gmsh.y"
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

  case 585:
#line 6227 "Gmsh.y"
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

  case 586:
#line 6241 "Gmsh.y"
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

  case 587:
#line 6253 "Gmsh.y"
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

  case 588:
#line 6269 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 589:
#line 6278 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 590:
#line 6287 "Gmsh.y"
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

  case 591:
#line 6297 "Gmsh.y"
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

  case 592:
#line 6308 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 593:
#line 6316 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 594:
#line 6324 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 595:
#line 6328 "Gmsh.y"
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

  case 596:
#line 6347 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 597:
#line 6354 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 598:
#line 6360 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 599:
#line 6367 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 600:
#line 6374 "Gmsh.y"
    { init_options(); ;}
    break;

  case 601:
#line 6376 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 602:
#line 6384 "Gmsh.y"
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

  case 603:
#line 6408 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 604:
#line 6410 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 605:
#line 6416 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 606:
#line 6421 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 607:
#line 6423 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 608:
#line 6428 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 609:
#line 6433 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 610:
#line 6438 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 611:
#line 6440 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 612:
#line 6444 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 613:
#line 6456 "Gmsh.y"
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

  case 614:
#line 6470 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 615:
#line 6474 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 616:
#line 6481 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 617:
#line 6489 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 618:
#line 6497 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 619:
#line 6508 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 620:
#line 6510 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 621:
#line 6513 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14486 "Gmsh.tab.cpp"
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


#line 6516 "Gmsh.y"


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
    Msg::Error("Could not find curve slave %d or master %d for periodic copy",
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
    Msg::Error("Could not find surface slave %d or master %d for periodic copy",
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
    Msg::Error("Could not find surface %d or %d for periodic copy",
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

