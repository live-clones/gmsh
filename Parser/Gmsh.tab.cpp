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
#define YYLAST   17335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  259
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  619
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2215

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
     749,   752,   760,   768,   776,   785,   794,   802,   810,   822,
     830,   839,   848,   857,   867,   871,   876,   887,   895,   903,
     911,   919,   927,   935,   943,   951,   959,   967,   977,   985,
     993,  1002,  1011,  1024,  1025,  1035,  1037,  1039,  1041,  1043,
    1048,  1050,  1052,  1054,  1059,  1061,  1063,  1068,  1070,  1072,
    1074,  1079,  1085,  1097,  1103,  1113,  1123,  1131,  1136,  1146,
    1156,  1158,  1160,  1161,  1164,  1171,  1179,  1187,  1194,  1202,
    1211,  1222,  1237,  1254,  1267,  1282,  1297,  1312,  1327,  1336,
    1345,  1352,  1357,  1363,  1369,  1376,  1383,  1387,  1392,  1396,
    1402,  1409,  1415,  1420,  1424,  1429,  1433,  1438,  1444,  1449,
    1455,  1459,  1465,  1473,  1481,  1485,  1493,  1497,  1500,  1503,
    1506,  1509,  1512,  1528,  1531,  1534,  1537,  1547,  1559,  1562,
    1565,  1568,  1571,  1588,  1600,  1607,  1616,  1625,  1636,  1638,
    1641,  1644,  1646,  1650,  1654,  1659,  1664,  1666,  1668,  1674,
    1686,  1700,  1701,  1709,  1710,  1724,  1725,  1741,  1742,  1749,
    1759,  1762,  1766,  1777,  1791,  1793,  1796,  1802,  1810,  1813,
    1816,  1820,  1823,  1827,  1830,  1834,  1844,  1851,  1853,  1855,
    1857,  1859,  1861,  1862,  1865,  1869,  1873,  1878,  1888,  1893,
    1908,  1909,  1913,  1914,  1916,  1917,  1920,  1921,  1924,  1925,
    1928,  1935,  1943,  1950,  1956,  1960,  1969,  1978,  1987,  1996,
    2005,  2011,  2016,  2023,  2035,  2047,  2066,  2085,  2098,  2111,
    2124,  2135,  2140,  2145,  2150,  2155,  2160,  2163,  2167,  2174,
    2176,  2178,  2180,  2183,  2189,  2197,  2208,  2210,  2214,  2217,
    2220,  2223,  2227,  2231,  2235,  2239,  2243,  2247,  2251,  2255,
    2259,  2263,  2267,  2271,  2275,  2279,  2283,  2287,  2291,  2295,
    2301,  2306,  2311,  2316,  2321,  2326,  2331,  2336,  2341,  2346,
    2351,  2358,  2363,  2368,  2373,  2378,  2383,  2388,  2393,  2398,
    2405,  2412,  2419,  2424,  2426,  2428,  2430,  2432,  2434,  2436,
    2438,  2440,  2442,  2444,  2446,  2447,  2454,  2456,  2461,  2468,
    2470,  2475,  2480,  2485,  2492,  2498,  2506,  2515,  2526,  2531,
    2536,  2543,  2548,  2552,  2555,  2561,  2567,  2571,  2577,  2584,
    2593,  2600,  2609,  2616,  2621,  2629,  2636,  2643,  2650,  2655,
    2662,  2667,  2668,  2671,  2672,  2675,  2676,  2684,  2686,  2690,
    2692,  2694,  2697,  2698,  2702,  2704,  2707,  2710,  2714,  2718,
    2730,  2740,  2748,  2756,  2758,  2762,  2764,  2766,  2769,  2773,
    2778,  2784,  2786,  2790,  2792,  2795,  2799,  2803,  2809,  2814,
    2819,  2822,  2827,  2830,  2834,  2838,  2855,  2861,  2867,  2873,
    2875,  2877,  2879,  2883,  2889,  2897,  2902,  2907,  2912,  2919,
    2926,  2935,  2944,  2949,  2964,  2969,  2974,  2976,  2978,  2982,
    2986,  2996,  3004,  3006,  3012,  3016,  3023,  3025,  3029,  3031,
    3033,  3038,  3043,  3047,  3053,  3060,  3069,  3076,  3081,  3087,
    3089,  3094,  3096,  3098,  3100,  3102,  3107,  3114,  3119,  3126,
    3132,  3140,  3145,  3150,  3155,  3164,  3169,  3174,  3179,  3184,
    3193,  3202,  3209,  3214,  3221,  3226,  3228,  3233,  3238,  3239,
    3246,  3251,  3254,  3259,  3264,  3266,  3268,  3272,  3274,  3276,
    3280,  3284,  3288,  3294,  3302,  3308,  3314,  3323,  3325,  3327
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
     341,   250,     7,   355,     6,    -1,    99,   249,   341,   250,
       7,   355,   302,     6,    -1,   100,   249,   341,   250,     7,
     355,   302,     6,    -1,   179,   249,   341,   250,     7,   355,
       6,    -1,   180,   249,   341,   250,     7,   355,     6,    -1,
     181,   249,   341,   250,     7,   355,   183,   355,   182,   341,
       6,    -1,   116,   249,   341,   250,     7,   355,     6,    -1,
     101,     4,   249,   341,   250,     7,   355,     6,    -1,   131,
     104,   249,   341,   250,     7,   355,     6,    -1,   104,   249,
     341,   250,     7,   355,   301,     6,    -1,   132,   104,   249,
     341,   250,     7,   355,   301,     6,    -1,    13,    14,     6,
      -1,    14,   104,   341,     6,    -1,   120,   104,   249,   341,
     250,     7,     5,     5,     5,     6,    -1,   102,   249,   341,
     250,     7,   355,     6,    -1,   103,   249,   341,   250,     7,
     355,     6,    -1,   107,   249,   341,   250,     7,   355,     6,
      -1,   110,   249,   341,   250,     7,   355,     6,    -1,   114,
     249,   341,   250,     7,   355,     6,    -1,   115,   249,   341,
     250,     7,   355,     6,    -1,   108,   249,   341,   250,     7,
     355,     6,    -1,   109,   249,   341,   250,     7,   355,     6,
      -1,   128,   249,   341,   250,     7,   355,     6,    -1,   155,
     249,   341,   250,     7,   355,     6,    -1,   104,     4,   249,
     341,   250,     7,   355,   303,     6,    -1,   106,   249,   341,
     250,     7,   355,     6,    -1,   127,   249,   341,   250,     7,
     355,     6,    -1,   132,   127,   249,   341,   250,     7,   355,
       6,    -1,   135,   307,   249,   341,   250,     7,   355,     6,
      -1,   135,   307,   249,   341,   250,     7,   355,     4,   253,
     354,   254,     6,    -1,    -1,   134,   306,   305,   249,   300,
     250,   281,   355,     6,    -1,    98,    -1,   101,    -1,   104,
      -1,   106,    -1,   117,   253,   341,   254,    -1,   101,    -1,
     104,    -1,   106,    -1,   117,   253,   341,   254,    -1,   101,
      -1,   104,    -1,   117,   253,   341,   254,    -1,    98,    -1,
     101,    -1,   104,    -1,   117,   253,   341,   254,    -1,   144,
     352,   253,   311,   254,    -1,   143,   253,   352,   258,   352,
     258,   341,   254,   253,   311,   254,    -1,   145,   352,   253,
     311,   254,    -1,   146,   253,   352,   258,   341,   254,   253,
     311,   254,    -1,   146,   253,   352,   258,   352,   254,   253,
     311,   254,    -1,   149,   253,   358,   254,   253,   311,   254,
      -1,     4,   253,   311,   254,    -1,   161,   101,   253,   358,
     254,   104,   253,   341,   254,    -1,   158,   101,   249,   341,
     250,   253,   358,   254,     6,    -1,   312,    -1,   310,    -1,
      -1,   312,   304,    -1,   312,   306,   253,   358,   254,     6,
      -1,   312,   134,   306,   253,   358,   254,     6,    -1,   312,
     137,   306,   253,   358,   254,     6,    -1,   312,   306,   253,
       8,   254,     6,    -1,   312,   134,   306,   253,     8,   254,
       6,    -1,   148,   131,   249,   341,   250,     7,   355,     6,
      -1,   148,    98,   249,   341,   250,     7,   253,   354,   254,
       6,    -1,   148,   131,   249,   341,   250,     7,   253,   352,
     258,   352,   258,   358,   254,     6,    -1,   148,   131,   249,
     341,   250,     7,   253,   352,   258,   352,   258,   352,   258,
     358,   254,     6,    -1,   148,   102,   249,   341,   250,     7,
     253,   352,   258,   358,   254,     6,    -1,   148,   108,   249,
     341,   250,     7,   253,   352,   258,   352,   258,   358,   254,
       6,    -1,   148,   109,   249,   341,   250,     7,   253,   352,
     258,   352,   258,   358,   254,     6,    -1,   148,   111,   249,
     341,   250,     7,   253,   352,   258,   352,   258,   358,   254,
       6,    -1,   148,   112,   249,   341,   250,     7,   253,   352,
     258,   352,   258,   358,   254,     6,    -1,   148,     4,   249,
     341,   250,     7,   355,     6,    -1,   148,     4,   249,   341,
     250,     7,     5,     6,    -1,   148,     4,   253,   341,   254,
       6,    -1,   159,   253,   312,   254,    -1,   141,   159,   253,
     312,   254,    -1,   159,     4,   253,   312,   254,    -1,   159,
     195,   251,   341,   252,     6,    -1,   159,     4,   251,   341,
     252,     6,    -1,   159,   372,     6,    -1,   159,     4,     4,
       6,    -1,   159,    90,     6,    -1,   184,   359,   253,   312,
     254,    -1,   141,   184,   359,   253,   312,   254,    -1,   219,
     341,   253,   312,   254,    -1,   200,   253,     8,   254,    -1,
     200,     5,     6,    -1,   201,   253,     8,   254,    -1,   201,
       5,     6,    -1,   200,   253,   312,   254,    -1,   141,   200,
     253,   312,   254,    -1,   201,   253,   312,   254,    -1,   141,
     201,   253,   312,   254,    -1,   372,   363,     6,    -1,    76,
     249,   369,   250,     6,    -1,   372,   372,   251,   341,   252,
     362,     6,    -1,   372,   372,   372,   251,   341,   252,     6,
      -1,   372,   341,     6,    -1,   139,   249,     4,   250,   255,
       4,     6,    -1,   178,     4,     6,    -1,   193,     6,    -1,
     194,     6,    -1,    71,     6,    -1,    72,     6,    -1,    65,
       6,    -1,    65,   253,   341,   258,   341,   258,   341,   258,
     341,   258,   341,   258,   341,   254,     6,    -1,    66,     6,
      -1,    67,     6,    -1,    81,     6,    -1,    83,   253,   341,
     258,   341,   258,   341,   254,     6,    -1,    83,   253,   341,
     258,   341,   258,   341,   258,   341,   254,     6,    -1,    82,
       6,    -1,    84,     6,    -1,    85,     6,    -1,   122,     6,
      -1,   123,   253,   358,   254,   253,   358,   254,   253,   354,
     254,   253,   341,   258,   341,   254,     6,    -1,   198,   249,
     253,   358,   254,   258,   363,   258,   363,   250,     6,    -1,
     186,   249,   341,     8,   341,   250,    -1,   186,   249,   341,
       8,   341,     8,   341,   250,    -1,   186,     4,   187,   253,
     341,     8,   341,   254,    -1,   186,     4,   187,   253,   341,
       8,   341,     8,   341,   254,    -1,   188,    -1,   199,     4,
      -1,   199,   363,    -1,   196,    -1,   197,   372,     6,    -1,
     197,   363,     6,    -1,   189,   249,   341,   250,    -1,   190,
     249,   341,   250,    -1,   191,    -1,   192,    -1,   147,   352,
     253,   312,   254,    -1,   147,   253,   352,   258,   352,   258,
     341,   254,   253,   312,   254,    -1,   147,   253,   352,   258,
     352,   258,   352,   258,   341,   254,   253,   312,   254,    -1,
      -1,   147,   352,   253,   312,   322,   326,   254,    -1,    -1,
     147,   253,   352,   258,   352,   258,   341,   254,   253,   312,
     323,   326,   254,    -1,    -1,   147,   253,   352,   258,   352,
     258,   352,   258,   341,   254,   253,   312,   324,   326,   254,
      -1,    -1,   147,   253,   312,   325,   326,   254,    -1,   147,
     253,   312,   254,   138,   116,   253,   341,   254,    -1,   127,
     355,    -1,   132,   127,   355,    -1,   129,   253,   358,   254,
     253,   358,   254,   253,   358,   254,    -1,   130,   253,   358,
     254,   253,   358,   254,   253,   358,   254,   253,   358,   254,
      -1,   327,    -1,   326,   327,    -1,   164,   253,   341,   254,
       6,    -1,   164,   253,   355,   258,   355,   254,     6,    -1,
     165,     6,    -1,   156,     6,    -1,   156,   341,     6,    -1,
     170,     6,    -1,   170,   172,     6,    -1,   171,     6,    -1,
     171,   172,     6,    -1,   166,   249,   341,   250,     7,   355,
     138,   341,     6,    -1,   138,     4,   251,   341,   252,     6,
      -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,   154,
      -1,    -1,   159,     6,    -1,   141,   159,     6,    -1,   159,
     341,     6,    -1,   141,   159,   341,     6,    -1,   328,   253,
     312,   329,   254,   253,   312,   329,   254,    -1,   113,   249,
     362,   250,    -1,   328,   249,   341,   250,     7,   253,   312,
     329,   254,   253,   312,   329,   254,     6,    -1,    -1,   138,
       4,   341,    -1,    -1,     4,    -1,    -1,     7,   355,    -1,
      -1,     7,   341,    -1,    -1,   149,   355,    -1,   118,   119,
     356,     7,   341,     6,    -1,   133,   101,   356,     7,   341,
     332,     6,    -1,   133,   104,   356,   334,   333,     6,    -1,
     133,   106,   356,   334,     6,    -1,   173,   356,     6,    -1,
      96,    98,   249,   341,   258,   341,   250,     6,    -1,    96,
     101,   249,   341,   258,   341,   250,     6,    -1,    96,   104,
     249,   341,   258,   341,   250,     6,    -1,    96,   106,   249,
     341,   258,   341,   250,     6,    -1,   162,   104,   253,   358,
     254,     7,   341,     6,    -1,   156,   104,   356,   335,     6,
      -1,   156,   106,   356,     6,    -1,   157,   104,   356,     7,
     341,     6,    -1,   136,   101,   253,   358,   254,     7,   253,
     358,   254,   336,     6,    -1,   136,   104,   253,   358,   254,
       7,   253,   358,   254,   336,     6,    -1,   136,   101,   253,
     358,   254,     7,   253,   358,   254,   143,   253,   352,   258,
     352,   258,   341,   254,     6,    -1,   136,   104,   253,   358,
     254,     7,   253,   358,   254,   143,   253,   352,   258,   352,
     258,   341,   254,     6,    -1,   136,   101,   253,   358,   254,
       7,   253,   358,   254,   144,   352,     6,    -1,   136,   104,
     253,   358,   254,     7,   253,   358,   254,   144,   352,     6,
      -1,   136,   104,   341,   253,   358,   254,     7,   341,   253,
     358,   254,     6,    -1,   306,   253,   358,   254,   187,   306,
     253,   341,   254,     6,    -1,   163,   308,   356,     6,    -1,
     124,   309,   356,     6,    -1,   125,   106,   355,     6,    -1,
     140,   101,   355,     6,    -1,   135,   307,   355,     6,    -1,
     160,     6,    -1,   160,     4,     6,    -1,   160,    98,   253,
     358,   254,     6,    -1,   208,    -1,   209,    -1,   210,    -1,
     339,     6,    -1,   339,   253,   355,   254,     6,    -1,   339,
     253,   355,   258,   355,   254,     6,    -1,   339,   249,   355,
     250,   253,   355,   258,   355,   254,     6,    -1,   342,    -1,
     249,   341,   250,    -1,   238,   341,    -1,   237,   341,    -1,
     244,   341,    -1,   341,   238,   341,    -1,   341,   237,   341,
      -1,   341,   239,   341,    -1,   341,   240,   341,    -1,   341,
     242,   341,    -1,   341,   243,   341,    -1,   341,   241,   341,
      -1,   341,   248,   341,    -1,   341,   231,   341,    -1,   341,
     232,   341,    -1,   341,   236,   341,    -1,   341,   235,   341,
      -1,   341,   230,   341,    -1,   341,   229,   341,    -1,   341,
     228,   341,    -1,   341,   227,   341,    -1,   341,   233,   341,
      -1,   341,   234,   341,    -1,   341,   226,   341,     8,   341,
      -1,    16,   283,   341,   284,    -1,    17,   283,   341,   284,
      -1,    18,   283,   341,   284,    -1,    19,   283,   341,   284,
      -1,    20,   283,   341,   284,    -1,    21,   283,   341,   284,
      -1,    22,   283,   341,   284,    -1,    23,   283,   341,   284,
      -1,    24,   283,   341,   284,    -1,    26,   283,   341,   284,
      -1,    27,   283,   341,   258,   341,   284,    -1,    28,   283,
     341,   284,    -1,    29,   283,   341,   284,    -1,    30,   283,
     341,   284,    -1,    31,   283,   341,   284,    -1,    32,   283,
     341,   284,    -1,    33,   283,   341,   284,    -1,    34,   283,
     341,   284,    -1,    35,   283,   341,   284,    -1,    36,   283,
     341,   258,   341,   284,    -1,    37,   283,   341,   258,   341,
     284,    -1,    38,   283,   341,   258,   341,   284,    -1,    25,
     283,   341,   284,    -1,     3,    -1,    10,    -1,    15,    -1,
      11,    -1,    12,    -1,   215,    -1,   216,    -1,   217,    -1,
      78,    -1,    79,    -1,    80,    -1,    -1,    89,   283,   341,
     343,   293,   284,    -1,   346,    -1,   206,   283,   362,   284,
      -1,   206,   283,   362,   258,   341,   284,    -1,   348,    -1,
     372,   251,   341,   252,    -1,   372,   249,   341,   250,    -1,
     211,   249,   348,   250,    -1,   211,   249,   348,   255,   349,
     250,    -1,   213,   249,   348,   344,   250,    -1,   213,   249,
     348,   255,   349,   344,   250,    -1,   213,   249,   348,   283,
     341,   284,   344,   250,    -1,   213,   249,   348,   255,   349,
     283,   341,   284,   344,   250,    -1,   212,   249,   363,   250,
      -1,   256,   372,   283,   284,    -1,   256,   348,   255,   349,
     283,   284,    -1,    92,   283,   372,   284,    -1,    92,   283,
     284,    -1,   372,   282,    -1,   372,   251,   341,   252,   282,
      -1,   372,   249,   341,   250,   282,    -1,   372,   255,   349,
      -1,   372,     9,   372,   255,   349,    -1,   372,   255,   349,
     249,   341,   250,    -1,   372,     9,   372,   255,   349,   249,
     341,   250,    -1,   372,   255,   349,   251,   341,   252,    -1,
     372,     9,   372,   255,   349,   251,   341,   252,    -1,   372,
     251,   341,   252,   255,     4,    -1,   372,   255,     4,   282,
      -1,   372,   251,   341,   252,   255,     4,   282,    -1,   202,
     249,   362,   258,   341,   250,    -1,    57,   249,   355,   258,
     355,   250,    -1,    58,   283,   362,   258,   362,   284,    -1,
      56,   283,   362,   284,    -1,    59,   283,   362,   258,   362,
     284,    -1,    64,   249,   369,   250,    -1,    -1,   258,   341,
      -1,    -1,   258,   362,    -1,    -1,    90,   348,   351,   347,
     251,   294,   252,    -1,   372,    -1,   372,     9,   372,    -1,
       4,    -1,    93,    -1,    93,   341,    -1,    -1,   249,   350,
     250,    -1,   353,    -1,   238,   352,    -1,   237,   352,    -1,
     352,   238,   352,    -1,   352,   237,   352,    -1,   253,   341,
     258,   341,   258,   341,   258,   341,   258,   341,   254,    -1,
     253,   341,   258,   341,   258,   341,   258,   341,   254,    -1,
     253,   341,   258,   341,   258,   341,   254,    -1,   249,   341,
     258,   341,   258,   341,   250,    -1,   355,    -1,   354,   258,
     355,    -1,   341,    -1,   357,    -1,   253,   254,    -1,   253,
     358,   254,    -1,   238,   253,   358,   254,    -1,   341,   239,
     253,   358,   254,    -1,   355,    -1,   253,     8,   254,    -1,
       5,    -1,   238,   357,    -1,   341,   239,   357,    -1,   341,
       8,   341,    -1,   341,     8,   341,     8,   341,    -1,    98,
     253,   341,   254,    -1,    98,   253,     8,   254,    -1,    98,
       5,    -1,   307,   253,     8,   254,    -1,   307,     5,    -1,
     134,   306,   356,    -1,   137,   306,   355,    -1,   306,   187,
      65,   253,   341,   258,   341,   258,   341,   258,   341,   258,
     341,   258,   341,   254,    -1,    65,   306,   253,   358,   254,
      -1,    73,   307,   253,   341,   254,    -1,    74,   307,   253,
     341,   254,    -1,   310,    -1,   321,    -1,   330,    -1,   372,
     283,   284,    -1,   372,   255,   349,   283,   284,    -1,   372,
       9,   372,   255,   349,   283,   284,    -1,    39,   251,   372,
     252,    -1,    39,   251,   357,   252,    -1,    39,   249,   357,
     250,    -1,    39,   283,   253,   358,   254,   284,    -1,   372,
     283,   253,   358,   254,   284,    -1,    40,   283,   341,   258,
     341,   258,   341,   284,    -1,    41,   283,   341,   258,   341,
     258,   341,   284,    -1,    42,   283,   362,   284,    -1,    43,
     283,   341,   258,   341,   258,   341,   258,   341,   258,   341,
     258,   341,   284,    -1,   207,   283,   357,   284,    -1,    32,
     283,   357,   284,    -1,   341,    -1,   357,    -1,   358,   258,
     341,    -1,   358,   258,   357,    -1,   253,   341,   258,   341,
     258,   341,   258,   341,   254,    -1,   253,   341,   258,   341,
     258,   341,   254,    -1,   372,    -1,     4,   255,   184,   255,
       4,    -1,   253,   361,   254,    -1,   372,   251,   341,   252,
     255,   185,    -1,   359,    -1,   361,   258,   359,    -1,   363,
      -1,   372,    -1,   372,   251,   341,   252,    -1,   372,   249,
     341,   250,    -1,   372,   255,   349,    -1,   372,     9,   372,
     255,   349,    -1,   372,   255,   349,   249,   341,   250,    -1,
     372,     9,   372,   255,   349,   249,   341,   250,    -1,   372,
     251,   341,   252,   255,     4,    -1,   306,   253,   341,   254,
      -1,   134,   306,   253,   341,   254,    -1,     5,    -1,   220,
     251,   372,   252,    -1,    68,    -1,   218,    -1,    75,    -1,
      77,    -1,   204,   249,   362,   250,    -1,   203,   249,   362,
     258,   362,   250,    -1,   205,   283,   362,   284,    -1,   205,
     283,   362,   258,   362,   284,    -1,   214,   249,   348,   345,
     250,    -1,   214,   249,   348,   255,   349,   345,   250,    -1,
      49,   283,   369,   284,    -1,    50,   249,   362,   250,    -1,
      51,   249,   362,   250,    -1,    52,   249,   362,   258,   362,
     258,   362,   250,    -1,    47,   283,   369,   284,    -1,    61,
     283,   362,   284,    -1,    62,   283,   362,   284,    -1,    63,
     283,   362,   284,    -1,    60,   283,   341,   258,   362,   258,
     362,   284,    -1,    55,   283,   362,   258,   341,   258,   341,
     284,    -1,    55,   283,   362,   258,   341,   284,    -1,    48,
     283,   362,   284,    -1,    48,   283,   362,   258,   358,   284,
      -1,    69,   283,   362,   284,    -1,    70,    -1,    54,   283,
     362,   284,    -1,    53,   283,   362,   284,    -1,    -1,    94,
     283,   363,   364,   297,   284,    -1,    91,   283,   365,   284,
      -1,   256,   341,    -1,   372,     9,   256,   341,    -1,    47,
     283,   368,   284,    -1,   369,    -1,   368,    -1,   253,   369,
     254,    -1,   362,    -1,   370,    -1,   369,   258,   362,    -1,
     369,   258,   370,    -1,   372,   249,   250,    -1,   372,   255,
     349,   249,   250,    -1,   372,     9,   372,   255,   349,   249,
     250,    -1,     4,   257,   253,   341,   254,    -1,   371,   257,
     253,   341,   254,    -1,   221,   251,   362,   252,   257,   253,
     341,   254,    -1,     4,    -1,   371,    -1,   221,   251,   362,
     252,    -1
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
    1618,  1624,  1647,  1663,  1679,  1716,  1760,  1776,  1792,  1824,
    1840,  1857,  1873,  1923,  1941,  1947,  1953,  1960,  1991,  2006,
    2028,  2051,  2074,  2097,  2121,  2145,  2169,  2195,  2212,  2228,
    2246,  2264,  2271,  2280,  2279,  2309,  2311,  2313,  2315,  2317,
    2325,  2327,  2329,  2331,  2339,  2341,  2343,  2351,  2353,  2355,
    2357,  2367,  2383,  2399,  2415,  2431,  2447,  2464,  2501,  2523,
    2547,  2548,  2553,  2556,  2560,  2577,  2597,  2617,  2636,  2663,
    2682,  2703,  2718,  2734,  2752,  2803,  2824,  2846,  2869,  2974,
    2990,  3025,  3047,  3069,  3081,  3087,  3102,  3130,  3142,  3151,
    3158,  3170,  3190,  3194,  3199,  3203,  3208,  3215,  3222,  3229,
    3241,  3314,  3332,  3357,  3372,  3405,  3417,  3441,  3445,  3450,
    3457,  3462,  3472,  3477,  3483,  3491,  3495,  3499,  3503,  3507,
    3511,  3515,  3524,  3588,  3604,  3621,  3638,  3660,  3682,  3717,
    3725,  3733,  3739,  3746,  3753,  3773,  3799,  3811,  3822,  3840,
    3858,  3877,  3876,  3901,  3900,  3927,  3926,  3951,  3950,  3973,
    3989,  4006,  4023,  4046,  4074,  4077,  4083,  4095,  4115,  4119,
    4123,  4127,  4131,  4135,  4139,  4143,  4152,  4165,  4166,  4167,
    4168,  4169,  4173,  4174,  4175,  4176,  4177,  4180,  4204,  4223,
    4246,  4249,  4265,  4268,  4285,  4288,  4294,  4297,  4304,  4307,
    4314,  4336,  4377,  4421,  4460,  4485,  4497,  4509,  4521,  4533,
    4542,  4572,  4598,  4624,  4656,  4683,  4709,  4735,  4761,  4787,
    4809,  4820,  4868,  4922,  4937,  4949,  4960,  4967,  4982,  4996,
    4997,  4998,  5002,  5008,  5020,  5038,  5066,  5067,  5068,  5069,
    5070,  5071,  5072,  5073,  5074,  5081,  5082,  5083,  5084,  5085,
    5086,  5087,  5088,  5089,  5090,  5091,  5092,  5093,  5094,  5095,
    5096,  5097,  5098,  5099,  5100,  5101,  5102,  5103,  5104,  5105,
    5106,  5107,  5108,  5109,  5110,  5111,  5112,  5113,  5114,  5115,
    5116,  5117,  5118,  5127,  5128,  5129,  5130,  5131,  5132,  5133,
    5134,  5135,  5136,  5137,  5142,  5141,  5149,  5151,  5156,  5161,
    5165,  5170,  5175,  5179,  5183,  5187,  5191,  5195,  5199,  5205,
    5220,  5224,  5230,  5235,  5254,  5274,  5305,  5309,  5313,  5317,
    5321,  5325,  5329,  5334,  5344,  5354,  5359,  5370,  5379,  5384,
    5389,  5417,  5418,  5424,  5425,  5431,  5430,  5453,  5455,  5460,
    5469,  5471,  5477,  5478,  5483,  5487,  5491,  5495,  5499,  5506,
    5510,  5514,  5518,  5525,  5530,  5537,  5542,  5546,  5551,  5555,
    5563,  5574,  5578,  5582,  5596,  5604,  5612,  5619,  5629,  5652,
    5657,  5663,  5668,  5674,  5685,  5691,  5697,  5703,  5715,  5729,
    5739,  5749,  5759,  5771,  5775,  5780,  5792,  5796,  5800,  5804,
    5822,  5830,  5838,  5867,  5877,  5893,  5904,  5909,  5913,  5917,
    5929,  5933,  5945,  5962,  5972,  5976,  5991,  5996,  6003,  6007,
    6012,  6026,  6042,  6046,  6050,  6054,  6058,  6066,  6072,  6081,
    6085,  6089,  6097,  6103,  6109,  6113,  6121,  6129,  6136,  6145,
    6149,  6153,  6168,  6182,  6196,  6208,  6224,  6233,  6242,  6252,
    6263,  6271,  6279,  6283,  6302,  6309,  6315,  6322,  6330,  6329,
    6339,  6363,  6365,  6371,  6376,  6378,  6383,  6388,  6393,  6395,
    6399,  6411,  6425,  6429,  6436,  6444,  6452,  6463,  6465,  6468
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
     304,   304,   304,   305,   304,   306,   306,   306,   306,   306,
     307,   307,   307,   307,   308,   308,   308,   309,   309,   309,
     309,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     311,   311,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     315,   316,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   319,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   321,   321,
     321,   322,   321,   323,   321,   324,   321,   325,   321,   321,
     321,   321,   321,   321,   326,   326,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   328,   328,
     328,   328,   329,   329,   329,   329,   329,   330,   330,   331,
     332,   332,   333,   333,   334,   334,   335,   335,   336,   336,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   338,   338,   338,   339,
     339,   339,   340,   340,   340,   340,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   343,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   344,   344,   345,   345,   347,   346,   348,   348,   349,
     350,   350,   351,   351,   352,   352,   352,   352,   352,   353,
     353,   353,   353,   354,   354,   355,   355,   355,   355,   355,
     355,   356,   356,   356,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   358,   358,   358,   358,
     359,   359,   359,   359,   360,   360,   361,   361,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   364,   363,
     363,   365,   365,   366,   367,   367,   368,   369,   369,   369,
     369,   370,   370,   370,   371,   371,   371,   372,   372,   372
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
       2,     7,     7,     7,     8,     8,     7,     7,    11,     7,
       8,     8,     8,     9,     3,     4,    10,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     9,     7,     7,
       8,     8,    12,     0,     9,     1,     1,     1,     1,     4,
       1,     1,     1,     4,     1,     1,     4,     1,     1,     1,
       4,     5,    11,     5,     9,     9,     7,     4,     9,     9,
       1,     1,     0,     2,     6,     7,     7,     6,     7,     8,
      10,    14,    16,    12,    14,    14,    14,    14,     8,     8,
       6,     4,     5,     5,     6,     6,     3,     4,     3,     5,
       6,     5,     4,     3,     4,     3,     4,     5,     4,     5,
       3,     5,     7,     7,     3,     7,     3,     2,     2,     2,
       2,     2,    15,     2,     2,     2,     9,    11,     2,     2,
       2,     2,    16,    11,     6,     8,     8,    10,     1,     2,
       2,     1,     3,     3,     4,     4,     1,     1,     5,    11,
      13,     0,     7,     0,    13,     0,    15,     0,     6,     9,
       2,     3,    10,    13,     1,     2,     5,     7,     2,     2,
       3,     2,     3,     2,     3,     9,     6,     1,     1,     1,
       1,     1,     0,     2,     3,     3,     4,     9,     4,    14,
       0,     3,     0,     1,     0,     2,     0,     2,     0,     2,
       6,     7,     6,     5,     3,     8,     8,     8,     8,     8,
       5,     4,     6,    11,    11,    18,    18,    12,    12,    12,
      10,     4,     4,     4,     4,     4,     2,     3,     6,     1,
       1,     1,     2,     5,     7,    10,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     1,     4,     6,     1,
       4,     4,     4,     6,     5,     7,     8,    10,     4,     4,
       6,     4,     3,     2,     5,     5,     3,     5,     6,     8,
       6,     8,     6,     4,     7,     6,     6,     6,     4,     6,
       4,     0,     2,     0,     2,     0,     7,     1,     3,     1,
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
       8,     6,     4,     6,     4,     1,     4,     4,     0,     6,
       4,     2,     4,     4,     1,     1,     3,     1,     1,     3,
       3,     3,     5,     7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   617,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
       0,     0,   196,     0,     0,   197,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,   328,   329,   330,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,     0,
       0,   296,   297,     0,     0,     0,   291,     0,     0,     0,
       0,     0,   379,   380,   381,     0,     0,     5,     6,     7,
       8,    10,     0,    11,    24,    12,    13,    14,    15,    23,
      22,    21,    16,     0,    17,    18,    19,    20,     0,    25,
       0,   618,     0,   222,     0,     0,     0,     0,     0,     0,
     271,     0,   273,   274,   269,   270,     0,   275,   278,     0,
     279,   280,   115,   125,   617,   492,   487,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,   207,
     208,   209,     0,     0,     0,     0,   433,   434,   436,   437,
     435,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   442,   443,
       0,     0,   195,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,   439,   440,
       0,     0,     0,     0,     0,     0,     0,     0,   529,   530,
       0,   531,   505,   386,   446,   449,   310,   506,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,   196,
     197,   198,   193,   200,   201,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   494,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,     0,     0,   222,     0,     0,   376,     0,     0,
       0,   204,   205,     0,     0,     0,     0,     0,   513,     0,
       0,   511,     0,     0,     0,     0,     0,   617,     0,     0,
     552,     0,     0,     0,     0,   267,   268,     0,   569,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   571,     0,   595,   573,   574,     0,     0,     0,
       0,     0,     0,   572,     0,     0,     0,     0,   289,   290,
       0,   222,     0,   222,     0,     0,     0,   487,     0,     0,
       0,   222,   382,     0,     0,    78,     0,    65,     0,     0,
      69,    68,    67,    66,    71,    70,    72,    73,     0,     0,
       0,     0,     0,     0,     0,   558,   487,     0,   221,     0,
     220,     0,   174,     0,     0,   558,   559,     0,     0,     0,
     607,     0,   608,   559,     0,   113,   113,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   546,
     547,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   389,     0,
     388,   514,   390,     0,   507,     0,     0,   487,     0,   522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,   463,     0,     0,     0,     0,
       0,     0,     0,   311,     0,   344,   344,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,   222,   222,
       0,   496,   495,     0,     0,     0,     0,   222,   222,     0,
       0,     0,     0,   307,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   346,     0,     0,
       0,     0,     0,   222,   248,     0,     0,   246,   377,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   354,
     266,     0,     0,     0,     0,     0,   222,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   292,     0,   253,     0,     0,   255,
       0,     0,     0,   388,     0,   222,     0,     0,     0,     0,
       0,     0,     0,   332,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    74,    75,     0,
       0,     0,   264,    40,   260,     0,     0,     0,     0,     0,
     217,     0,     0,     0,     0,     0,   223,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,   490,     0,     0,   488,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   338,     0,     0,
       0,   199,     0,     0,     0,     0,     0,     0,   372,   373,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   444,   462,     0,     0,     0,     0,   523,   524,
       0,     0,     0,     0,     0,   481,     0,   387,   508,     0,
       0,     0,     0,   516,     0,   406,   405,   404,   403,   399,
     400,   407,   408,   402,   401,   392,   391,     0,   393,   515,
     394,   397,   395,   396,   398,   488,     0,     0,   489,   466,
       0,   532,     0,     0,     0,     0,     0,     0,     0,     0,
     342,     0,     0,     0,     0,   375,     0,     0,     0,     0,
     374,     0,   222,     0,     0,     0,     0,     0,   498,   497,
       0,     0,     0,     0,     0,     0,     0,   301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   361,     0,     0,   247,     0,     0,     0,   241,     0,
       0,     0,     0,   371,     0,     0,     0,   387,   512,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   295,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   598,     0,     0,
       0,   483,     0,     0,   252,   256,   254,   258,     0,   393,
       0,   488,   466,   619,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,   387,     0,    65,     0,
       0,     0,     0,    81,     0,    65,    66,     0,     0,     0,
     488,     0,     0,   466,     0,     0,     0,   193,     0,     0,
       0,   614,    28,    26,    27,     0,     0,     0,     0,     0,
     489,   562,    30,     0,    29,     0,     0,   261,   609,   610,
       0,   611,   562,     0,    76,   116,    77,   126,   491,   493,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   548,   549,
     210,     9,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   432,   419,     0,   421,   422,   423,   424,   425,   545,
     426,   427,   428,     0,     0,     0,   537,   536,   535,     0,
       0,     0,   542,     0,   478,     0,     0,     0,   480,     0,
       0,     0,   130,   461,   519,   518,   203,     0,     0,   447,
     544,   452,     0,   458,     0,     0,     0,     0,   509,     0,
       0,   459,     0,   521,     0,     0,     0,     0,   451,   450,
     473,    72,    73,     0,     0,     0,     0,     0,     0,     0,
     387,   340,   345,   343,     0,   353,     0,   150,   151,   203,
     387,     0,     0,     0,     0,   242,     0,   257,   259,     0,
       0,     0,   211,   213,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   314,     0,   298,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
     347,   360,     0,     0,     0,   243,     0,     0,     0,     0,
     206,     0,     0,     0,     0,     0,     0,     0,     0,   249,
       0,     0,     0,     0,   585,     0,   592,   581,   582,   583,
       0,   597,   596,     0,     0,   586,   587,   588,   594,   601,
     600,     0,   141,     0,   575,     0,   577,     0,     0,     0,
     570,     0,   251,     0,     0,     0,     0,     0,     0,     0,
     333,     0,     0,     0,   383,     0,   615,     0,   103,    65,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,   567,    50,     0,     0,
       0,    63,     0,    41,    42,    43,    44,    45,     0,   451,
     450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   561,   560,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,   133,   134,     0,     0,
       0,     0,     0,     0,     0,   157,   157,     0,     0,     0,
       0,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   350,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   527,   528,     0,
       0,     0,     0,     0,   481,   482,     0,   454,     0,     0,
       0,   517,   409,   510,   467,   465,     0,   464,     0,     0,
     533,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     352,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,   319,     0,     0,   318,
       0,   321,     0,   323,     0,   308,   315,     0,     0,     0,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,     0,   245,   244,   378,     0,     0,    37,    38,     0,
       0,     0,     0,   553,     0,     0,     0,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   483,   484,   579,     0,   467,     0,     0,   222,   334,
       0,   335,   222,     0,     0,   568,     0,    88,     0,     0,
       0,     0,    86,    93,    95,     0,   556,     0,   101,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,    36,
     467,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,   563,     0,     0,    34,
      33,     0,   563,   612,     0,     0,   117,   122,     0,     0,
       0,   136,   139,   140,   486,     0,    79,     0,     0,     0,
       0,    80,   161,     0,     0,     0,     0,   162,   177,   178,
     159,     0,     0,     0,   163,   188,   179,   183,   184,   180,
     181,   182,   169,     0,     0,   420,   429,   430,   431,   538,
       0,     0,     0,   476,   477,   479,   131,   445,   475,   448,
     453,     0,     0,   481,   189,   460,     0,    72,    73,     0,
     472,   468,   470,   539,   185,     0,     0,     0,   153,     0,
       0,   351,     0,   152,     0,     0,     0,     0,   265,     0,
       0,     0,     0,   222,   222,     0,     0,   320,   505,     0,
       0,   322,   324,     0,     0,   302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   186,     0,     0,
       0,     0,   166,   167,     0,     0,     0,     0,   104,   105,
     106,   110,     0,   593,     0,     0,   591,     0,   602,     0,
       0,   142,   143,   599,   576,   578,     0,     0,     0,     0,
       0,     0,   332,   336,   332,     0,   384,    87,    65,     0,
       0,     0,     0,    85,     0,   554,     0,     0,     0,     0,
       0,     0,   605,   604,     0,     0,     0,     0,     0,   503,
       0,     0,   472,   262,   468,   263,     0,     0,     0,     0,
       0,   227,   224,     0,     0,   566,   564,     0,     0,     0,
       0,   118,   123,     0,     0,     0,   546,   547,   135,   355,
     356,   357,   358,   158,   164,   165,   170,     0,     0,     0,
       0,     0,   172,     0,     0,     0,     0,     0,     0,   455,
       0,     0,     0,     0,   534,   474,     0,     0,   171,     0,
     190,   341,     0,     0,   191,     0,     0,     0,     0,     0,
       0,   502,   501,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   238,     0,     0,     0,     0,     0,
       0,     0,     0,   229,     0,     0,   359,    39,     0,   551,
       0,     0,   286,   285,     0,     0,     0,     0,     0,     0,
     145,   146,   149,   148,   147,     0,   580,     0,   616,     0,
       0,     0,     0,     0,     0,    98,     0,     0,    99,   557,
       0,     0,     0,    90,     0,     0,     0,    46,     0,     0,
       0,     0,     0,    48,     0,   228,   225,   226,    35,     0,
       0,   613,   276,     0,   130,   141,     0,     0,   138,     0,
       0,     0,   160,   187,     0,     0,     0,     0,     0,   540,
     541,     0,   481,   456,     0,   469,   471,     0,     0,   173,
     194,     0,   348,   348,     0,   111,   112,   222,     0,   214,
     215,   309,     0,   316,     0,     0,   222,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   218,     0,     0,     0,
       0,   107,   108,   584,   590,   589,   144,     0,     0,     0,
     337,     0,    94,    96,     0,   102,     0,    84,   606,    91,
      92,    51,     0,     0,     0,     0,   504,     0,     0,   469,
     565,     0,     0,     0,     0,   120,   603,     0,   127,     0,
       0,     0,     0,   176,     0,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     500,     0,   326,     0,     0,   303,     0,   230,     0,     0,
       0,     0,     0,     0,     0,   550,   287,     0,     0,   370,
     222,   385,     0,   555,     0,    47,     0,     0,     0,    64,
      49,     0,   277,   119,   124,   130,     0,     0,   155,   156,
     154,     0,     0,   457,     0,     0,     0,     0,     0,   349,
     363,     0,     0,   364,     0,   212,     0,   317,     0,   299,
       0,   222,     0,     0,     0,     0,     0,     0,   168,   109,
     283,   332,   100,     0,     0,     0,     0,     0,     0,   128,
     129,     0,     0,     0,     0,   192,     0,   367,     0,   368,
     369,   499,     0,     0,   305,   233,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,    61,     0,     0,   121,
       0,     0,     0,   313,     0,     0,   325,   304,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
     236,   237,     0,   231,   339,    52,     0,    59,     0,   272,
       0,   543,     0,     0,     0,   306,     0,     0,    53,     0,
       0,   282,     0,     0,     0,   232,     0,     0,     0,     0,
     525,     0,     0,    56,    54,     0,    57,     0,   365,   366,
       0,     0,    62,    60,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   117,  1065,   118,   119,  1049,  1896,  1902,
    1343,  1554,  2054,  2187,  1344,  2158,  2205,  1345,  2189,  1346,
    1347,  1558,   439,   595,   596,  1138,   120,   779,   465,  1914,
    2065,  1915,   466,  1785,  1420,  1375,  1376,  1377,  1518,  1721,
    1722,  1206,  1613,  1604,  1798,   756,   607,   276,   277,   354,
     203,   278,   449,   450,   124,   125,   126,   127,   128,   129,
     130,   131,   279,  1238,  2090,  2149,   945,  1234,  1235,   280,
    1028,   281,   135,  1449,  1204,   920,   960,  2024,   136,   137,
     138,   139,   282,   283,  1162,  1177,  1299,   284,   784,   285,
     909,   783,   468,   622,   322,  1758,   361,   362,   287,   565,
     369,  1330,  1547,   460,   455,  1292,  1005,  1593,  1751,  1752,
     990,   462,   141,   417
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1875
static const yytype_int16 yypact[] =
{
   12858,    80,    73, 13019, -1875, -1875,    -5,   117,    -7,  -100,
     -50,    11,    33,   175,   292,   303,   350,    84,   360,   378,
     108,   391,   418,   157,   168,    21,   180,   667,   180,   214,
     251,   257,    31,   263,   266,    53,   273,   289,   310,   330,
     364,   367,   380,   439,   445,   451,   448,   611,   610,   754,
     508,   -23,   726,   614,  6933,   624,   519,   589,   746,   -55,
     572,   517,   355,   126,   629,   759,  -105,   632,   291,   291,
     636,   348,   124,   639, -1875, -1875, -1875, -1875, -1875,   637,
     501,   796,   808,    13,    57,   811,   813,   413,   925,   932,
     945,  5945,   957,   721,   722,   723,    29,    67, -1875,   736,
     737, -1875, -1875,   981,   982,   742, -1875,  5058,   745, 13257,
      36,    37, -1875, -1875, -1875, 11869,   744, -1875, -1875, -1875,
   -1875, -1875,   743, -1875, -1875, -1875, -1875, -1875, -1875, -1875,
   -1875, -1875, -1875,   290, -1875, -1875, -1875, -1875,    58, -1875,
     994,   748,  5696,    70,   749,   995, 11869, 13197, 13197, 13197,
   -1875, 11869, -1875, -1875, -1875, -1875, 13197, -1875, -1875, 11869,
   -1875, -1875, -1875, -1875,   750,   760,   999, -1875, -1875, 13292,
     761,   762,   763,   764,    21, 11869, 11869, 11869,   766, 11869,
   11869, 11869,   769, 11869, 11869, 11869, 11869, 11869, 11869, 11869,
   13197, 11869, 11869, 11869, 11869,  5945,   770, -1875,  9640, -1875,
   -1875, -1875,   768,  5945,  7180, 13197, -1875, -1875, -1875, -1875,
   -1875,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   180,   180,   482,   180,   180,   180,   180,   180,
     775,   180,   180,   776,   517,   355,   355, -1875, -1875, -1875,
     180,   180,    42,   816,   827,   839,   779,  7180,   902,   517,
     517,   785,   180,   180,   787,   788,   789, -1875, -1875, -1875,
   11869,  7427, 11869, 11869,  7674,    21,   853,    43, -1875, -1875,
     790, -1875,  2856, -1875, -1875, -1875, -1875, -1875,    68, 11869,
    9640,  9640,   792,   793,  7921,  5945,  5945,  5945, -1875, -1875,
   -1875, -1875, -1875, -1875, -1875, -1875,   794,  8168,   795,  4777,
    1041,  7180,   797,    29,   800,   801,   291,   291,   291, 11869,
   11869,   -44, -1875,   353,   291, 10555,   361,   331,   806,   807,
     809,   812,   815,   817,   818,  9640, 11869,  5945,  5945,  5945,
     819,    16,  1043,   814, -1875,  1054,  1063, -1875,   822,   840,
     841, -1875, -1875,   848,  5945,   820,   861,   866, -1875, 11869,
    6192, -1875,  1064,  1112, 11869, 11869, 11869,   483, 11869,   867,
   -1875,   934, 11869, 11869, 11869, -1875, -1875, 11869, -1875,   180,
     180,   180,   870,   873,   874,   180,   180,   180,   180,   180,
     180,   180, -1875,   180, -1875, -1875, -1875,   180,   180,   875,
     876,   180,   877, -1875,   879,  1121,  1122,   878, -1875, -1875,
    1129,  1128,  1131,  1130,   180, 11869, 10837,   113, 13197,  9640,
   11869, -1875, -1875,  7180,  7180, -1875,   886, 13292,   517,  1133,
   -1875, -1875, -1875, -1875, -1875, -1875, 11869, 11869,    39,  7180,
    1135,   694,   889,  1589,   891,  1139,    28,   893, -1875,   897,
   13513, 11869, -1875,  1770,  -182, -1875,    93,  -141,   -47,  7363,
   -1875,   100, -1875,   116,  7610,  -123,   -93,  1062, -1875,    21,
     898, 11869, 11869, 11869, 11869,   899, 15462, 15487, 15512, 11869,
   15537, 15562, 15587, 11869, 15612, 15637, 15662, 15687, 15712, 15737,
   15762,   908, 15787, 15812, 15837, 14103,  1152, 11869,  9640,  5124,
   -1875,   377, 11869,  1154,  1155,   912, 11869, 11869, 11869, 11869,
   11869, 11869, 11869, 11869, 11869, 11869, 11869, 11869, 11869, 11869,
   11869, 11869,  9640, 11869, 11869, 11869, 11869, 11869, 11869,  9640,
    9640,   910, 11869, 11869, 13197, 11869, 13197,  7180, 13197, 13197,
   13197,   911,   914,   915, 11869,    49, -1875, 10638, 11869,  7180,
    5945,  7180, 13197, 13197,  9640,    21, 13292,    21,   917,  9640,
     917, -1875,   917, 15862, -1875,   397,   916,    76,  1104, -1875,
    1162, 11869, 11869, 11869, 11869, 11869, 11869, 11869, 11869, 11869,
   11869, 11869, 11869, 11869, 11869,  8415, 11869, 11869, 11869, 11869,
   11869,    21, 11869, 11869,  1168, -1875,   698, 15887,   449,   461,
   11869, 11869, 11869, -1875,  1166,  1167,  1167,   926, 11869, 11869,
    1171,  9640,  9640, 11169,   928,  1174, -1875,   930, -1875, -1875,
    -171, -1875, -1875,  7857,  8104,   291,   291,    70,    70,  -168,
   10555, 10555, 11869,  4571,  -146, -1875, 11869, 11869, 11869, 11869,
   11869, 11869, 11869, 11869, 11869,   470, 15912,  1178,  1180,  1183,
   11869,  1181, 11869, -1875, -1875, 11869,  4967, -1875, -1875,  9640,
    9640,  9640, 11869,  1185, 11869, 11869, 11869, 15937,   941, -1875,
   -1875, 15962, 15987, 16012,  1012,  8351, -1875,   944,  5387, 16037,
   16062, 15057, 13197, 13197, 13197, 13197, 13197, 13197, 13197, 13197,
   13197, 11869, 13197, 13197, 13197, 13197,    20, 13292, 13197, 13197,
   13197,    21,    21, -1875, -1875,  9640, -1875,   946, 11897, -1875,
     947, 11995, 11869,   917, 11869, -1875,    21, 11869, 11869,  1168,
     951,   509, 16087, 13415,   948,   523, 11869,  1193,   952,  7180,
   16112, 15084,   167,   953,  1199,  1201, -1875, -1875, -1875,  9640,
      22, 11869, -1875, -1875, -1875,    21, 11869, 11869,  1168,   958,
   -1875,   962,   -45,   517,   355,   517, -1875,   959, 14132, -1875,
     142,  9640,    21, 11869, 11869,  1206,  1208,  9640,  1210,  9640,
   11869,  1211, 13197,    21, 10880,  1206, 11869,  1212, -1875,    21,
    1215, 13197, 11869,   972,   974, -1875, 11869,  8598,  8840,  9082,
    9329, 13292,  1216,  1219,  1220, 16137,  1221,  1222,  1223, 16162,
    1224,  1225,  1229,  1230,  1231,  1232,  1233, -1875,  1234,  1235,
    1236, -1875, 11869, 16187,  9640,   992,  9640, 14161, -1875, -1875,
    1243, 15030, 15030, 15030, 15030, 15030, 15030, 15030, 15030, 15030,
   15030, 15030,  9576, 15030, 15030, 15030, 15030,  1532,   703, 15030,
   15030, 15030,  9913, 10252, 10505,  5124,  1000,  1001,    10,  9640,
   10587, 10911,   703, 11243,   703,   993,   996,   997,   199,  9640,
   11869, 11869, 17087, -1875,   703,   998, 14190, 14219, -1875, -1875,
    1002,  -151,   703,     8,  1006,   474,   525,  1250, -1875,  1206,
     703,  1005,  1010,  5623,  5881,   849,   514,   429,   429,   402,
     402,   402,   402,   402,   402,   469,   469,  9640,   268, -1875,
     268,   268,   917,   917,   917,  1004, 16212, 15111,   -29,   707,
    9640, -1875,  1258,  1013,  1014, 16237, 16262, 16287, 11869,  7180,
    1264,  1263, 10313, 14248, 16312, -1875,   528,   530,  9640,  1015,
   -1875, 12103, -1875, 12171, 12239,   291, 11869, 11869, -1875, -1875,
    1017,  1019, 10555,  4328,  1136,     2,   291, 12307, 16337, 14277,
   16362, 16387, 16412, 16437, 16462, 16487, 16512,  1022,  1269, 11869,
    1272, -1875, 11869, 16537, -1875, 15138, 12375, 15165, -1875,   531,
     533,   536, 14306, -1875, 15192, 15219, 11494, -1875, -1875,  1273,
    1275,  1276,  1024, 11869, 12443, 11869, 11869, -1875, -1875,    45,
     -68,    87,   -68,  1034,  1035,  1029,   703,   703,  1031, 11576,
     703,   703,   703,   703, 11869,   703,  1282, -1875,  1036,  1046,
     238,   128,  1045,   538, -1875, -1875, -1875, -1875, 15030,   268,
   12511,  1038,   708,  1042,  1111,  1293,  1142, 10970,  1049,  1051,
    1299,  7180, 14335, -1875, 11869,  1300,   171,   130, 13292, 11869,
    1301,  1304,    32, -1875,   541,  1262,  1265,  7180, 14364,    30,
    1056, 16562, 15246,   304, 11869, 11869,  1066,  1060,  1068,  1065,
    8662, -1875, -1875, -1875, -1875, 13197,   224,  1067, 16587, 15273,
   -1875,  1070, -1875,   346, -1875,   362, 11736, -1875, -1875, -1875,
    1069, -1875,  1071, 11929, -1875,    77, -1875, -1875, 17087, -1875,
    1317, 15030, 11869, 11869, 11869, 11869,   703,   291,  7180,  7180,
    1316,  7180,  7180,  7180,  1320,  7180,  7180,  7180,  7180,  7180,
    7180,  7180,  7180,  7180,  7180,  1827,  1321,  9640,  5124, -1875,
   -1875, -1875, -1875, -1875, -1875, -1875, -1875, -1875, -1875, -1875,
   -1875, -1875, -1875, 11869, -1875, -1875, -1875, -1875, -1875, -1875,
   -1875, -1875, -1875, 11869, 11869, 11869, -1875, -1875, -1875,   543,
   11869, 11869, -1875, 11869, -1875,  7180, 13197, 13197, -1875,   544,
   14393, 14422,  1072, -1875, -1875, -1875,  1144, 11869, 11869, -1875,
   -1875, -1875,  1206, -1875,  1206, 11869, 11869,  1079, -1875,  7180,
     180, -1875, 11869, -1875, 11869, 11869,   546,  1206,   -29,  -114,
   -1875, 11869, 11869,   703,   549,  7180,  9640,  9640,  1325,  1326,
    1327,  3223, -1875, -1875,  1329, -1875,  1086, 17087,  1082, -1875,
    1330,  1334,  1335,   551,  1339, -1875, 12579, -1875, -1875,  -132,
   12649, 13205, -1875, -1875, 14451,   -17,  1228,  1341, 11212,  1093,
    1342,  1100,    38,    40,   -14, -1875,  -124, -1875,     2,  1343,
    1345,  1346,  1348,  1349,  1350,  1351,  1352,  1354,    70,  7180,
   17087, -1875,  2207,  1110,  1360, -1875,  1361,  1362,  1266,  1365,
   -1875,  1363,  1367, 11869,  7180,  7180,  7180,  1370, 13349, -1875,
    6128,  1382,    56,  1372, -1875,  9640, -1875, -1875, -1875, -1875,
   13197, -1875, -1875, 11869, 13197, -1875, -1875, -1875, -1875, 17087,
   -1875,  1124,  1119, 13197, -1875, 13197, -1875,  1206, 13197,  1132,
   -1875,  1123, -1875,  1206, 11869, 11869,  1134,   517,  1138, 11302,
   -1875,  2379,  1140,  7180, -1875,  1141, -1875, 14480, -1875, -1875,
   11869,  1377,    54, 11869,  1379,  1380,  3000, -1875,  1385,    29,
    1383,  1143,   703,   180,   180,  1390, -1875, -1875,  1148,  1172,
    1169, -1875,  1395, -1875, -1875, -1875, -1875, -1875,  1206,   -67,
    2211, 11869, 15300, 16612, 11869,  8904, 11869,  9640,  1173,   552,
    1414,   148,  1206, -1875,  1170, 11869,  1420,  1422, 11869,  1206,
   11544, 11869,  9882,   703,  5176,  1177,  1175, -1875,  1425, 16637,
   16662, 16687, 16712,  1426,    83,  1305,  1305,  7180,  1429,  1431,
    1433,  7180,   -76,  1434,  1435,  1439,  1440,  1441,  1442,  1443,
    1445,  1446, -1875,  1448,   554, 15030, 15030, 15030, 15030,   703,
   13443, 13476, 13509,  1204,   703,   703, -1875, -1875, -1875,  1317,
     703, 16737, 15030,  1205,  -128, 17087, 15030, -1875,  1450,   703,
   13542, 17087, 17087, -1875,   711, -1875,  1453, -1875, 16762, 15327,
   -1875,   703,  1452,   562,   563,  7180,  7180,  7180,  1455,  1454,
   -1875,   181, 11869,  7180,  1214,  1217,  1456,   438, -1875, 11869,
   11869, 11869,  1218,  1226,  1237,  1213, -1875,  3279,  7180, -1875,
   11869, -1875,  1462, -1875,  1463, -1875, -1875, 10555,   269,  6439,
   -1875,  1238,  1239,  1240,  1242,  1244,  1245,  9146,  1207,  1466,
   -1875,  9640, -1875, -1875, -1875,  1247, 11869, -1875, -1875, 15354,
    1467,  1468,  1295, -1875, 11869, 11869, 11869, -1875,  1475,  1476,
    1477,   668,   372,  1227,  3995,  1246, 11869,    26,   703,  1251,
     703,  1248, -1875, -1875, 13292,   715, 11869,  1249, -1875, -1875,
    3317, -1875, -1875,  1252,  1480, -1875,  3399, -1875,   176,  1241,
    1496,  3774, -1875, -1875, -1875,    29, -1875,   564, -1875, 11869,
     181,   929,  3701, -1875,  1256, 11869, 11869,  7180,  1254, -1875,
     488,  1483,  1502, 16787,  1511,  1250, 16812,  1268,   569, 16837,
     570,  1517,  1521, -1875, -1875, 13197,  1279,  1525, 16862, -1875,
   -1875, 13575,  1281, -1875,  6375,  5449, 17087, -1875,  1524,   180,
    7674, -1875, -1875, -1875, -1875,  1317, -1875,  1527,  1528,  1530,
    1531, -1875, -1875,   291,  1533,  1535,  1537, -1875, -1875, -1875,
    1400,    72,  1444,  1538, -1875, -1875, -1875, -1875, -1875, -1875,
   -1875, -1875, -1875,  1540,  1294, -1875, -1875, -1875, -1875, -1875,
   11869, 11869, 11869, -1875, -1875, -1875,  1175, -1875, -1875, -1875,
   -1875, 11869,  1302,  1292, -1875, -1875, 11869, 11869, 11869,   703,
     -29, -1875, -1875, -1875, -1875,  1298,  1303,  1547,   -76,  1549,
   11869, -1875,  7180, 17087,   961,  9640,  9640, 11869, -1875, 10313,
   14509, 16887,  6622,    70,    70, 11869, 11869, -1875,   335,  1306,
   16912, -1875, -1875, 14538,  -122, -1875,  1551,  1552,  7180,   291,
     291,   291,   291,   291,  6686,  1553, -1875, -1875,   571, 11869,
    3862,  1554, -1875, -1875,  7180,  6869,  1176, 16937, -1875, -1875,
   -1875, -1875,  9974, -1875, 13197, 11869, -1875, 13197, 17087, 10221,
   13292,  1307, -1875, -1875, -1875, -1875,  1311,  1308, 11869, 11869,
   14567, 11869, 13415, -1875, 13415,  7180, -1875, -1875, 13292, 11869,
    1556,  1559,    32, -1875,  1561, -1875,    29, 15381,  7180, 13197,
    1562,   703, -1875,  1312,   703, 11869, 13608, 13641,   576, -1875,
   11869, 11869,   400, -1875,  1318, -1875,  1327,  1563,  1567,  1330,
    1568, -1875, -1875,  1569, 11869, -1875, -1875, 11869, 11627,  1570,
   11869, -1875, -1875,  1324,  3701,   577,  4649,  1571, -1875, -1875,
   -1875, -1875, -1875,   399, -1875, -1875, -1875,  1437,  1574,  1328,
    1331,  1332, -1875,  1581,  7180, 15030, 15030, 13674, 15030, -1875,
    1338, 13707, 16962, 15408, -1875, -1875,  9640,  9640, -1875,  1583,
   -1875, 17087,  1584,  1340, -1875,   579,   585, 15002,  3964,  1585,
    1347, -1875, -1875, 11869,  1373,  1374, 14596, 15435,  1586,  7180,
    1587,  1353, 11869, -1875, -1875,   586,   -62,   172,   174,   190,
     200,  9393,   209, -1875,  1590, 14625, -1875, -1875,  1417, -1875,
   11869, 11869, -1875, -1875,  9640,  4031,  1595,  1355, 15030,   703,
   17087, -1875, -1875, -1875, -1875,    26, -1875, 13292, -1875, 14654,
    1375,  1381,  1384,  1596,  4102, -1875,  1597,  1625, -1875, -1875,
    1386,  1630,   587, -1875,  1631,  1633,   375, 17087, 11869, 11869,
    1387,  7180,   593, 17087, 16987, -1875, -1875, -1875, -1875, 17012,
   13740, -1875, -1875, 14683,  1072,  1119,  7180,   703, -1875, 11869,
   13292,    21, -1875, -1875,  9640,  9640, 11869,  1636,   594, -1875,
   -1875, 11869,  1292, -1875, 11869, -1875, -1875,   595,   601, -1875,
   -1875,  7180,   505,   631,  9640, -1875, -1875,    70,  7116, -1875,
   -1875, -1875,  1638, -1875,  1391,  7180, -1875, 14712,  1640,  9640,
     291,   291,   291,   291,   291, -1875, -1875, 11869, 14741, 14770,
     603, -1875, -1875, -1875, -1875, -1875, -1875,  1398,  1643,  1397,
   -1875,  1645, -1875, -1875,    29, -1875,  1418, -1875, -1875, -1875,
   -1875, -1875, 11869, 13773, 13806,  7180, -1875,  1647, 11869,  1401,
   -1875, 11869,  1649,  1402,  1403, -1875, -1875,  4809, -1875,  1409,
     604,   625, 14799, -1875,  1407, 13839,  1411, 13872, -1875,  1412,
     630,  1413,   291,  7180,  1658,  1415,   291,  1661,   633,  1416,
   -1875, 11869, -1875,  1663,  1539, 12647,  1423, -1875,   641,   213,
     215,   217,   231,   241,  4207, -1875, -1875,  1665,  1669, -1875,
   -1875, -1875,  1672, -1875,  1427, 17087, 11869, 11869,   643, -1875,
   17087, 13905, -1875, -1875, -1875,  1072, 13292,  1432, -1875, -1875,
   -1875, 11869, 11869, -1875, 11869,  9640,  1673,   291,   132, -1875,
   -1875,   291,   141, -1875,  1675, -1875, 14828, -1875, 11869, -1875,
       2, -1875,  1677,  9640,  9640,  9640,  9640,  9393, -1875, -1875,
   -1875, 13415, -1875, 11869, 17037, 13938,    44, 11869,  1436, -1875,
   -1875, 13971, 14004, 14037,   644, -1875,   243, -1875,   247, -1875,
   -1875, -1875,  4372,   327, 12715, -1875,   652,   657,   660,   665,
     249,   666,  1438,   672, -1875, 11869, -1875,  7180, 14857, -1875,
   11869, 11869, 11869, -1875,   291,   291, -1875, -1875, -1875,     2,
    1680,  1681,  1682,  1683,  9640,  1687,  1688,  1689,  1447, 17062,
     673,  1690, 14886, 15030, 14070,   283,   287,   338, -1875, -1875,
   -1875, -1875,   674, -1875, -1875, -1875, 13197, -1875,  1449, -1875,
    1691, -1875, 11869, 11869, 11869, -1875,  1692,   684, -1875,  1451,
    7180, -1875, 14915, 14944, 14973, -1875,  1693, 13197, 13197,   685,
   -1875,  1697,  1699, -1875, -1875,   687, -1875,  1700, -1875, -1875,
    1701, 13197, -1875, -1875, -1875
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1875, -1875, -1875, -1875,   347, -1875, -1875, -1875, -1875,  -394,
   -1875, -1875, -1875, -1875, -1875, -1875, -1875, -1875, -1875, -1875,
   -1875, -1875,  -724,  -115,  4254,  3541, -1875,  1253, -1875, -1875,
   -1875, -1875, -1875, -1875, -1874, -1875,   293,   115,  -202, -1875,
    -160, -1875,    59,   332, -1875,  1713, -1875,   182,   -48, -1875,
   -1875,     0,  -622,  -313, -1875, -1875, -1875, -1875, -1875, -1875,
   -1875, -1875,  1717, -1875, -1875, -1875, -1875, -1236, -1227,  1718,
   -1719,  1719, -1875, -1875, -1875,  1117, -1875,  -219, -1875, -1875,
   -1875, -1875,  2219, -1875, -1875, -1414,   204,  1723, -1875,     3,
    -710, -1875, -1875,   278, -1875, -1677,   765,  -177,  2765,  2832,
    -312,   -15, -1875,   826,   -86, -1875, -1875,     9,   177, -1674,
    -152,   963, -1875,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -567
static const yytype_int16 yytable[] =
{
     142,   617,  1478,   123,   461,   940,   941,  1476,  1039,  1022,
    1642,  1845,   633,  1880,   307,  1881,  1047,   341,   496,   591,
     651,   405,   166,   409,   164,   164,   503,   440,   165,  1045,
    1719,   656,   164,   367,  1337,   178,   164,   745,  1053,   150,
    2003,   410,   412,   732,  1471,  1873,  1473,   546,   569,   293,
    2136,   288,  1272,   164,   312,  1071,   445,   182,  1538,   293,
    1508,   346,  1611,   347,   422,  1082,   625,   626,   760,   625,
     626,   371,   294,     5,   447,   199,   761,   591,   200,   313,
     345,   201,  1056,   470,  1372,   469,     4,   935,   288,  1602,
     942,   625,   626,   370,   202,   314,   315,   146,   708,   737,
     711,   738,   762,   342,   406,   625,   626,  1168,   723,   766,
    1917,  1612,   946,   625,   626,   625,   626,   767,   604,   605,
     606,   167,   716,   168,  1227,   773,  1459,  1928,   327,   777,
    1175,   145,   434,   435,  1477,   778,  1842,  1319,  2117,   446,
    1227,  1436,  1228,   448,   456,   456,   456,  2119,  1062,   147,
    1229,  1230,  1231,   463,  1574,   348,  1232,  1233,  1228,   780,
     647,   648,   649,  1509,  1510,   778,  1229,  1230,  1231,  1180,
    1799,   475,  1232,  1233,  1038,   625,   626,   663,  1319,   434,
     435,   152,   737,  1738,   738,   122,  -561,   456,  1319,  1800,
     772,  2108,   288,   625,   626,   288,  1959,   542,   543,   148,
     288,   288,   456,   768,  1338,  1339,  1340,  1341,   343,   627,
    1472,   769,  1474,    67,    68,    69,    70,   434,   435,    73,
     625,   626,   328,   733,   734,  1720,   329,   308,    82,  1810,
     309,    85,   330,   331,   116,   332,   333,  1463,  1539,  1540,
    1475,   116,   116,   302,   430,   431,   432,  1046,   143,   116,
     116,  1476,   144,   116,   288,   334,   434,   435,  1171,   592,
     149,   593,  1148,  1172,  2020,   594,   344,   652,   288,   653,
     116,   288,   567,   144,   434,   435,  1004,   746,   566,   747,
     179,  -559,   368,   748,  1342,  1329,   151,   288,   288,   411,
     413,   288,   288,   288,   288,   547,   570,  2137,   153,   737,
    1273,   738,   183,   931,   288,   933,   934,   423,   288,   154,
     370,   424,  1320,  1323,   434,   435,   372,   592,  2058,   593,
     625,   626,   947,   594,   442,   167,   167,   168,   168,   442,
     442,   442,   288,   156,   288,   288,   288,   737,   442,   738,
     966,   727,   763,   571,   764,  1275,   321,   323,   765,   326,
     771,   288,   430,   431,   432,   433,   155,   288,   772,   434,
     435,   159,   717,   984,   718,   774,   157,   764,   719,   625,
     626,   775,   442,   868,  1063,  1064,   434,   435,   625,   626,
    1063,  1064,  2132,  1297,   158,  1322,  1298,   442,   858,   430,
     431,   432,   433,   430,   431,   432,   433,   160,   430,   431,
     432,   433,  1020,   430,   431,   432,   433,  1227,   162,   625,
     626,   625,   626,   434,   435,   456,   288,   434,   435,   163,
     288,   288,   434,   435,   161,  1228,   541,   625,   626,   167,
    1960,   168,  1961,  1229,  1230,  1231,   288,   625,   626,  1232,
    1233,   550,   551,   749,  1668,  1669,   625,   626,  1962,  1158,
     625,   626,   625,   626,   625,   626,   303,   772,  1963,   304,
    2160,   305,  1423,   175,  1424,  1227,   785,  1964,   625,   626,
     874,  2093,   306,  2094,  1361,  2095,  1227,  1434,   625,   626,
     625,   626,   816,  1228,   625,   626,   625,   626,   737,  2096,
     738,  1229,  1230,  1231,  1228,   288,  1295,  1232,  1233,  2097,
     176,  2144,  1229,  1230,  1231,  2145,   177,  2154,  1232,  1233,
     588,   589,   180,  2199,   351,   181,   590,   352,  2016,   288,
     625,   626,   184,  1685,   625,   626,   288,   848,   317,   318,
     353,   456,   992,   456,   288,   456,   456,   463,   185,   420,
     319,  2183,   864,   421,   320,  2184,   288,   288,   288,   456,
     456,   288,   166,  1351,   166,  1305,   288,  -562,   873,   186,
     875,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   187,
     636,  2147,   288,   590,   637,   317,   318,  1521,   905,  1838,
     625,   626,  2185,  1525,   620,   621,  1366,   319,   625,   626,
     442,   325,   629,   634,   816,   337,   628,   338,   288,   288,
     728,  1007,  1367,   188,   635,   298,   189,  1040,   299,  1216,
     816,   300,   737,   301,   738,  1991,  1488,   448,   448,   190,
     816,   815,   757,  1992,    46,   816,   625,   626,  1560,   583,
     584,   714,   586,   587,   588,   589,   434,   435,  2021,  2022,
     590,   878,  1576,  -566,  2023,   816,   288,   288,   288,  1582,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,   295,  1711,  1712,   296,   590,   297,   463,
     456,   463,   456,   456,   456,   456,   456,   456,   191,   456,
     456,   456,   456,  1006,   192,   456,   456,   456,   166,  1012,
     193,   194,   288,   913,  1011,  1096,  1058,   816,   714,   586,
     587,   588,   589,  1021,   196,   914,   442,   590,   442,   816,
     442,   442,   442,   167,   957,   168,   288,  1662,   816,  1174,
     195,   529,  1175,   530,   442,   442,   288,  1761,   674,  1729,
     144,  -563,  1050,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,   288,  1067,
     197,   198,   590,  1024,   288,   170,   288,   816,   171,   463,
    1080,   172,   290,   173,  2025,  2026,  1085,  1030,   456,  1178,
    2023,  1031,  1211,   816,  1212,  1257,   816,  1258,   816,   816,
    1259,   816,  1301,  1190,   816,  1332,   816,  1409,  1416,   816,
    1433,   816,   816,  1441,   816,  1456,  1572,   816,  1624,   816,
     816,   288,   816,   288,  1739,   757,  1655,  1656,  1745,   286,
     816,   816,  1746,  1768,  1770,  1854,  1748,   816,   816,   816,
    1900,  1918,   204,  1942,  1901,  1919,  1208,   816,   757,  1943,
    1958,  1988,   291,   816,  1901,   772,   288,  1997,  2014,  2018,
     292,  1998,  1901,   816,  2123,  2019,   288,  2047,  2068,   816,
     311,   816,   816,   205,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   289,   442,   442,   442,   442,   310,  2069,
     442,   442,   442,   816,  2076,   316,   336,  2084,  1901,   324,
     757,   816,   335,   757,   288,  2092,  1476,  2106,  2143,   816,
     339,  1901,   816,   938,   939,   757,  2150,   288,   621,   340,
     816,  2151,   349,  2167,  2152,   816,   288,   350,   816,  2153,
    2155,  1321,  1324,   816,   816,   288,  2157,  2178,  2186,   355,
    1998,  1901,   816,   164,   378,  1057,   356,  1059,  2196,  2207,
    1476,  2210,  2197,  1901,   737,  2211,   738,   739,   737,   357,
     738,   910,  1325,   737,   442,   738,  1191,  1304,  1192,  1305,
    1647,   363,  1648,   442,  1728,  1823,  1729,  1824,   444,   504,
     364,   365,   366,   454,   457,   458,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   373,   374,   375,   376,   388,
     389,   390,   391,   377,   407,   418,   419,   392,   393,   394,
     425,   452,   451,  -196,   395,   426,   396,   144,   469,   467,
     471,   472,   473,   474,  -197,   479,   491,  1546,   483,   497,
     397,   502,   286,   398,   537,   540,  -198,   298,   288,   549,
     299,   505,   548,   300,   552,   301,   555,   556,   557,  1331,
     568,   600,   601,   421,   288,   614,    46,   608,   611,   654,
     616,  1834,  1835,   618,   619,   638,   639,   288,   640,   603,
     657,   641,   456,   428,   642,   655,   643,   644,   650,   658,
     669,   664,   610,  1435,  1437,   659,   615,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,   660,   661,   288,   288,   590,   288,   288,
     288,   662,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   665,   757,   288,   757,   757,   666,   670,   685,
     676,   677,   686,   687,   698,   699,   701,   703,   704,   757,
     702,   705,   399,   400,   401,   706,   707,   709,   710,   726,
     729,   736,   741,   402,   743,   744,   143,   403,   757,   404,
     116,   750,   288,   456,   456,   782,   786,   791,   807,   812,
     818,   819,   820,   849,   859,   590,   757,   860,   861,   881,
     882,   879,   908,   918,   919,   922,   288,   925,   929,   737,
     930,   738,  1749,   932,  1861,   959,   961,   964,   724,   725,
     962,   973,   288,   288,   288,   978,   982,   985,  1029,  1033,
    1014,  1016,   757,  1023,   735,  1034,  1042,  1043,  1041,  1054,
    1070,  1055,  1060,  1219,  1072,  1732,  1074,  1077,  1084,  1734,
    1225,  1086,  1089,  1097,  1236,  1090,  1098,  1099,  1101,  1102,
    1103,  1105,  1106,  1744,  1435,  1437,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,   720,  1117,   288,   442,   448,  1121,
    1146,  1155,  1164,  1147,  1156,  1157,  1173,  1179,  1182,  1187,
    1167,   288,   288,   288,  1183,  1195,  1196,  1197,  1203,  1205,
    1214,  1222,   288,  1223,  1226,  1248,  1249,   456,  1251,  1267,
    1264,   456,  1265,  1266,  1278,  1279,  1587,  1280,  1592,  1283,
     456,  1291,   456,  1303,  1293,   456,  1294,  1300,  1307,  1306,
    1308,  1309,   855,  1312,  1313,  1314,  1318,  1327,  1328,  1333,
     288,  1348,  1334,  1355,   603,  1354,   869,  1356,  1357,  1365,
    1370,  1374,  1362,  1387,  1369,  2029,   370,  1391,  1403,  1427,
    1419,  -199,  1445,  1446,  1447,  1450,  1451,  1453,   442,   442,
    1452,  1454,  1455,  1457,  1464,  1465,  1468,   456,  1469,  1470,
    1479,  1480,   288,  1481,   288,  1482,  1483,  1484,  1485,  1486,
     852,  1487,   854,  1491,   856,   857,  1492,  1493,  1494,  1497,
    1495,   288,  1496,  1498,  1503,  1384,  1511,  1517,   870,   871,
    1516,  1524,  1523,  1537,   288,  1542,  1543,  1526,   288,  1548,
    1506,  1528,  1545,  1532,  1549,  1534,  1553,  1555,   757,  1753,
    1753,  1559,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
    1573,  1556,  1557,  1740,   590,  1577,  1579,  1571,  1580,  1594,
    1862,  1596,  1601,  1595,  1889,  1607,  1603,  1608,  1727,  1609,
    1614,  1615,   288,   288,   288,  1616,  1617,  1618,  1619,  1620,
     288,  1621,  1622,  1623,  1633,  1640,  1644,  1650,  1654,  1660,
    1661,  1696,   442,  1667,  1676,   288,   442,  1665,  1681,  1682,
    1666,  1673,  1697,  1702,  1703,   442,   288,   442,  1704,  1674,
     442,  1708,  1709,  1710,   288,  1714,  1736,  1762,   288,  1527,
    1675,  1688,  1689,  1690,  1035,  1691,  1741,  1692,  1693,  1782,
    1699,  1724,  1731,  1742,  1717,  1755,  1298,  1760,  1763,   991,
    1735,   993,   994,   995,   996,   997,   998,  1765,  1000,  1001,
    1002,  1003,  1767,  1771,  1008,  1009,  1010,  1772,  1774,  1775,
    1778,  1783,   442,  1789,  1790,  1815,  1791,  1792,  1797,  1794,
     571,  1795,   370,  1796,  1802,  1803,  1801,  1804,   463,   463,
    1175,  1816,  1809,  1818,   288,  1820,  1817,  1843,  1844,  1853,
    1857,  1876,  1885,  1886,  1839,  1875,  1877,  1888,  1893,  1905,
     772,  -564,   456,  1906,  1907,  1908,  1912,  1916,  1921,  1922,
    1923,  1924,   288,  1829,  1925,  1926,  1927,   288,  1933,  1939,
    1940,  1946,  1953,  1941,  1955,   742,  1965,  1892,  1078,  1967,
    1947,  1972,  1982,  2053,  1984,  1973,  1956,  1087,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,  1866,  1949,  1950,  1979,
     590,  1985,  1507,  1871,  1874,  1980,  1987,  1989,  1981,  1990,
    1995,  1986,  2013,  2035,  2032,  2033,  2037,  1815,  2048,  2049,
    2050,  2051,  1883,  2059,  -565,  2062,  2063,  2064,  2067,   288,
    2071,  2073,   288,   288,  2080,  2075,  2077,  2083,  2081,  2087,
    2085,  2099,  2052,   448,   448,  2100,  2091,  2088,  2102,  2115,
    2103,  2120,  2110,  2125,  1202,   288,  2168,  2169,  2170,  2171,
    2139,   288,  2156,  2173,  2174,  2175,  2179,  2191,  2195,  2203,
    2176,   288,  2190,  2208,  2198,  2209,  2212,  2213,  1575,  2133,
    1788,   456,  1636,  2004,   456,  1976,   121,  1819,  1605,   781,
     132,   133,   134,   921,  2027,  1726,   140,  1887,  1872,  1754,
       0,     0,   288,   442,   442,  1079,     0,  2101,     0,  1331,
       0,     0,     0,   370,     0,   288,   463,     0,     0,     0,
       0,     0,     0,     0,     0,  1684,     0,   442,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   814,   586,   587,   588,   589,   759,     0,  2124,     0,
     590,   463,   737,     0,   738,     0,     0,     0,     0,     0,
       0,  1977,     0,     0,     0,     0,  1315,     0,     0,     0,
       0,   288,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1335,   288,   288,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,  1402,  2008,     0,   288,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   288,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,     0,  1385,  1386,     0,  1388,  1389,  1390,     0,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
       0,  1793,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1360,     0,     0,     0,     0,   442,     0,   288,   442,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   288,   757,     0,   757,     0,  2009,     0,
    1413,   288,   288,     0,     0,     0,     0,     0,     0,     0,
       0,   442,     0,     0,     0,     0,     0,     0,   288,     0,
       0,   288,     0,     0,  1428,     0,     0,   448,     0,     0,
       0,     0,   288,     0,     0,     0,   288,     0,     0,     0,
    1442,     0,     0,     0,     0,     0,   442,  1846,  1847,  1848,
    1849,  1850,  1852,     0,     0,     0,     0,     0,     0,     0,
    2109,   370,  1414,  1415,     0,     0,     0,     0,     0,     0,
       0,     0,   288,     0,     0,     0,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,  1489,     0,     0,     0,   590,     0,
     288,     0,     0,     0,     0,     0,     0,     0,     0,  1500,
    1501,  1502,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,   288,     0,     0,   590,     0,     0,  1533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   288,   288,   288,   288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1513,     0,     0,     0,
    1515,     0,     0,     0,     0,     0,     0,     0,     0,  1519,
       0,  1520,     0,     0,  1522,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,  1591,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,  1606,     0,     0,     0,  1610,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   456,     0,     0,  1562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   288,     0,     0,
       0,     0,     0,     0,   456,   456,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   456,     0,
    1657,  1658,  1659,  1490,     0,   164,   378,   757,  1664,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1679,     0,     0,     0,     0,  2039,  2040,
    2041,  2042,  2043,     0,  1687,     0,     0,     0,     0,     0,
       0,     0,  1695,     0,     0,     0,     0,     0,   379,   380,
     381,   382,   383,   384,   385,   386,   387,     0,     0,     0,
       0,   388,   389,   390,   391,     0,     0,     0,     0,   392,
     393,   394,     0,   757,     0,     0,   395,     0,   396,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2078,     0,   397,     0,  2082,   398,   757,     0,     0,   298,
       0,     0,   299,     0,     0,   300,     0,   301,     0,     0,
       0,     0,  1759,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   428,     0,     0,     0,     0,
    1781,     0,     0,     0,     0,  2116,     0,     0,   442,  2118,
       0,   443,     0,     0,     0,   453,     0,     0,     0,     0,
     459,     0,     0,     0,     0,  2130,     0,     0,   464,   442,
     442,     0,     0,     0,     0,  1531,     0,     0,     0,     0,
       0,     0,     0,   442,   476,   477,   478,     0,   480,   481,
     482,  1773,   484,   485,   486,   487,   488,   489,   490,     0,
     492,   493,   494,   495,   399,   400,   401,   499,     0,     0,
       0,     0,  2165,  2166,     0,   402,     0,  1822,     0,   403,
       0,   404,   116,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,  1759,     0,   590,     0,   434,   435,     0,
       0,     0,     0,     0,  -560,     0,  1561,     0,     0,  1858,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
     560,   562,   563,   499,     0,     0,     0,     0,     0,     0,
    1882,     0,     0,     0,     0,     0,     0,     0,   597,   499,
     499,     0,     0,  1891,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   623,   624,
    1867,     0,     0,  1869,   624,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   499,   646,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1759,
       0,     0,     0,     0,     0,     0,     0,     0,   667,   499,
       0,     0,     0,   671,   672,   673,     0,   675,     0,     0,
       0,   678,   679,   680,     0,     0,   681,     0,     0,     0,
       0,     0,     0,     0,  1954,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,   713,     0,     0,     0,   499,   722,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   730,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1996,     0,     0,     0,
     758,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2005,     0,     0,     0,     0,     0,     0,     0,     0,
     787,   788,   789,   790,     0,     0,     0,     0,   795,     0,
       0,     0,   799,     0,     0,     0,  1759,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   813,   560,     0,     0,
    2034,   817,     0,     0,     0,   821,   822,   823,   824,   825,
     826,   827,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   837,   839,   840,   841,   842,   843,   844,   845,   845,
       0,   850,   851,     0,   853,     0,     0,     0,     0,     0,
    1759,     0,     0,   862,     0,     0,   866,   867,     0,     0,
       0,     0,     0,   845,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2079,     0,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   892,
     893,   894,   895,   896,   898,   900,   901,   902,   903,   904,
       0,   906,   907,     0,     0,     0,     0,     0,     0,   915,
     916,   917,     0,     0,     0,     0,     0,   923,   924,     0,
     499,   499,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
     713,   943,     0,     0,     0,   948,   949,   950,   951,   952,
     953,   954,   955,   956,   571,     0,     0,     0,     0,   963,
       0,   965,     0,     0,   967,     0,     0,     0,   499,   499,
     499,   972,     0,   974,   975,   976,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1759,     0,     0,     0,     0,     0,     0,     0,
     999,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   499,     0,     0,     0,     0,     0,
       0,  1018,     0,  1019,     0,     0,   906,   907,     0,     0,
       0,     0,     0,     0,     0,  1032,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1759,     0,     0,   499,     0,
    1048,     0,     0,   500,     0,  1051,  1052,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     499,     0,  1068,  1069,     0,     0,   499,     0,   499,  1076,
       0,     0,     0,  1068,     0,  1083,     0,     0,     0,     0,
       0,  1088,  2188,     0,     0,  1091,  1544,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2204,  2206,     0,     0,     0,     0,     0,
     501,  1115,     0,   898,     0,  1118,   561,  2214,     0,   500,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   500,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,  1160,
    1161,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     500,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
       0,     0,   598,   599,     0,   500,     0,     0,     0,   499,
       0,     0,     0,     0,     0,     0,     0,  1201,     0,     0,
       0,  1207,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,  1220,  1221,     0,     0,     0,
       0,  1224,     0,     0,     0,     0,     0,   645,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1250,     0,
       0,  1252,     0,     0,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1268,     0,  1270,  1271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1289,     0,     0,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,  1311,     0,   590,     0,
       0,   721,     0,  1317,     0,     0,     0,     0,  1326,     0,
       0,     0,     0,   561,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1352,  1353,     0,     0,     0,     0,   499,
       0,     0,     0,     0,     0,  1677,     0,   838,     0,     0,
       0,     0,     0,     0,   846,   847,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1379,  1380,  1381,  1382,     0,     0,     0,     0,   872,
       0,     0,     0,  1733,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     899,     0,  1405,     0,     0,     0,     0,     0,     0,     0,
       0,  1448,  1406,  1407,  1408,     0,     0,     0,     0,  1410,
    1411,     0,  1412,     0,     0,     0,   500,   500,     0,     0,
       0,     0,     0,     0,     0,     0,  1421,  1422,     0,     0,
       0,   876,     0,     0,  1425,  1426,     0,     0,     0,     0,
       0,  1430,     0,  1431,  1432,  1737,     0,     0,     0,     0,
    1438,  1439,     0,     0,     0,   499,   499,     0,     0,     0,
       0,     0,     0,     0,   500,   500,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   926,   927,     0,     0,  1467,     0,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
     500,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1499,     0,     0,     0,     0,     0,     0,     0,
       0,   969,   970,   971,   499,     0,     0,     0,     0,     0,
       0,     0,  1514,     0,   500,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,  1438,  1439,     0,   500,   590,  1530,     0,
       0,     0,   500,     0,   500,     0,     0,  1013,     0,  1536,
       0,     0,  1541,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
    1563,  1044,     0,  1566,   499,  1569,   499,     0,     0,   899,
       0,  1119,     0,     0,  1578,     0,     0,  1581,     0,  1578,
    1584,  1586,     0,  1066,     0,     0,     0,     0,     0,  1073,
       0,  1075,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   500,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   500,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,  1663,     0,     0,     0,   500,     0,     0,  1670,  1671,
    1672,  1149,     0,     0,     0,     0,     0,  1678,     0,  1680,
       0,  1159,     0,   500,     0,     0,  1683,     0,     0,     0,
       0,     0,     0,     0,     0,   164,   378,     0,     0,     0,
     499,     0,     0,     0,     0,  1700,     0,     0,     0,     0,
       0,     0,     0,  1705,  1706,  1707,     0,     0,     0,  1186,
       0,     0,     0,     0,     0,  1718,     0,     0,     0,     0,
       0,     0,  1194,     0,     0,  1730,     0,     0,   379,   380,
     381,   382,   383,   384,   385,   386,   387,     0,     0,     0,
    1213,   388,   389,   390,   391,     0,     0,     0,  1747,   392,
     393,   394,     0,     0,  1756,  1757,   395,     0,   396,     0,
    1743,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   397,     0,     0,   398,     0,     0,     0,   298,
       0,     0,   299,     0,     0,   300,     0,   301,     0,  1786,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,   500,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   428,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1805,
    1806,  1807,     0,     0,     0,     0,     0,     0,     0,     0,
    1808,     0,     0,     0,     0,  1811,  1812,  1813,  1856,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1821,
       0,     0,   500,     0,   499,   499,  1827,     0,  1828,     0,
       0,     0,  1359,     0,  1836,  1837,     0,     0,     0,     0,
       0,     0,     0,     0,   399,   400,   401,     0,     0,     0,
       0,     0,     0,   499,     0,   402,     0,     0,  1855,   403,
       0,   404,   116,     0,     0,     0,     0,     0,     0,     0,
       0,  1865,     0,     0,  1868,     0,     0,     0,  1870,     0,
       0,     0,     0,     0,     0,     0,     0,  1812,  1813,  1404,
    1879,     0,     0,     0,  1749,     0,     0,     0,  1884,     0,
       0,   500,   500,     0,     0,     0,     0,     0,     0,     0,
    1945,     0,     0,     0,  1897,     0,     0,     0,     0,  1903,
    1904,     0,   740,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1909,     0,     0,  1910,  1909,     0,  1913,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  1443,  1444,
       0,     0,     0,     0,     0,   499,   499,  1971,     0,     0,
     500,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1948,     0,     0,     0,     0,     0,     0,     0,
       0,  1957,     0,     0,     0,     0,     0,     0,     0,     0,
     560,     0,     0,     0,     0,     0,     0,     0,     0,  1968,
    1969,     0,     0,   499,     0,     0,   863,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,  1512,  1983,     0,
     590,     0,     0,     0,     0,     0,     0,  1993,  1994,     0,
     500,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   911,  2007,     0,
       0,     0,     0,   499,   499,  2012,     0,     0,     0,     0,
    2015,     0,     0,  2017,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,     0,
       0,     0,     0,     0,     0,     0,  2044,  1568,     0,  1570,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,  2055,   590,  2098,     0,     0,     0,  2060,     0,     0,
    2061,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,   737,     0,   738,     0,     0,
    2086,     0,     0,  1715,     0,     0,   500,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,  2104,  2105,     0,     0,   590,
     169,     0,   174,     0,     0,     0,     0,     0,     0,     0,
    2111,  2112,     0,  2113,   499,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2122,     0,     0,
       0,     0,   499,   499,   499,   499,   499,     0,     0,     0,
       0,     0,  1903,  1698,     0,     0,  2138,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,  2159,  1787,     0,     0,     0,  2162,
    2163,  2164,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,
    1130,  1131,  1132,   499,  1134,  1135,  1136,  1137,  2146,  1139,
    1140,  1141,  1142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1152,     0,  1154,   441,     0,     0,     0,
       0,  2192,  2193,  2194,     0,  1163,     0,     0,     0,     0,
       0,     0,  1169,  1170,     0,     0,     0,     0,     0,     0,
       0,  1181,     0,     0,     0,     0,     0,     0,     0,     0,
     500,   500,     0,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,   500,
       0,     0,     0,     0,     0,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   531,   532,
     533,   534,   535,   536,     0,   538,   539,  1825,  1826,     0,
       0,     0,     0,     0,   544,   545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,   554,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,  1276,  1277,     0,     0,     0,  1281,  1282,     0,
       0,  1285,  1286,  1287,  1288,     0,  1290,     0,     0,     0,
       0,  1296,     0,     0,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,   977,     0,
       0,   500,   500,     0,     7,     8,   936,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,   561,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,  1378,   682,   683,   684,     0,  1383,     0,   688,
     689,   690,   691,   692,   693,   694,     0,   695,  1937,  1938,
       0,   696,   697,     0,     0,   700,  1920,   571,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   712,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    43,    44,    45,    46,   500,
     500,    48,     0,     0,     0,     0,  1970,     0,   751,    55,
       0,     0,    58,   752,     0,   753,   754,     0,   755,   500,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   500,     0,    79,     0,     0,     0,
       0,     0,     0,     0,  1440,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,     0,     0,     0,  2010,  2011,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2028,     0,     0,     0,
     206,   164,     0,     0,     0,     0,     0,   207,   208,   209,
       0,  2038,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   414,
     228,   229,   230,   231,   232,   233,  2066,     0,     0,     0,
       0,   880,     0,     0,     0,   944,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
     500,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   248,   249,   500,   500,
     500,   500,   500,     0,     0,     0,   250,    25,     0,   251,
       0,     0,     0,  1550,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   814,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2114,     0,     0,
       0,     0,     0,     0,  1588,     0,     0,     0,     0,   500,
       0,     0,     0,     0,     0,  2126,  2127,  2128,  2129,  2131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1625,  1626,  1627,  1628,
    1629,     0,     0,     0,     0,  1634,  1635,     0,     0,     0,
       0,  1637,     0,  1639,     0,     0,     0,  1643,     0,     0,
    1645,     0,     0,     0,     0,     0,     0,     0,     0,   261,
       7,     8,  1653,   262,     0,     0,  2172,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   415,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   359,     0,     0,     0,
     612,     0,     0,   275,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,  1713,     0,  1716,     0,   590,     0,  1723,
       0,  1725,   164,   378,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,  1750,     0,   751,    55,     0,     0,    58,   752,
       0,   753,   754,     0,   755,   379,   380,   381,   382,   383,
     384,   385,   386,   387,     0,     0,     0,     0,   388,   389,
     390,   391,    79,     0,     0,     0,   392,   393,   394,  1176,
       0,     0,   571,   395,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,    95,   397,
       0,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   206,
       6,   378,     0,     0,     0,     0,   207,   208,   209,     0,
    1814,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
       0,   968,     0,  1589,   380,   381,   382,   383,   384,   385,
     386,   387,   239,   240,   241,   242,   388,   389,   390,   391,
     243,   244,     0,     0,   392,   393,   394,     0,     0,   245,
     246,   395,     0,   396,   247,   248,   249,     0,     0,     0,
       0,   399,   400,   401,     0,   250,    25,   397,   251,     0,
     398,     0,   402,     0,   252,     0,   403,   253,   404,   116,
     254,     0,   255,     0,     0,     0,     0,     0,     0,    42,
       0,     0,  1894,   256,     0,  1895,     0,     0,     0,     0,
       0,     0,     0,   257,     0,    56,    57,     0,   258,     0,
     259,     0,     0,   260,     0,     0,     0,     0,     0,    67,
      68,    69,    70,    71,     0,    73,    74,    75,    76,    77,
      78,     0,     0,     0,    82,     0,     0,    85,     0,  1373,
       0,     0,     0,     0,     0,     0,  1929,  1930,     0,  1932,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   814,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,   261,   399,
     400,   401,   262,   263,     0,     0,     0,   264,   265,   266,
     402,   267,   268,   269,   403,   986,   404,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1974,
    1975,     0,     0,   270,   271,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   359,     0,     0,     0,  1590,
       0,     0,   275,     0,  1429,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   206,     6,   378,     0,     0,     0,  2006,   207,
     208,   209,     0,     0,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,     0,     0,     0,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   239,   240,   241,   242,   388,
     389,   390,   391,   243,   244,     0,     0,   392,   393,   394,
       0,     0,   245,   246,   395,     0,   396,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
     397,   251,     0,   398,     0,     0,     0,   252,     0,     0,
     253,     0,     0,   254,     0,   255,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   257,     0,    56,    57,
       0,   258,     0,   259,     0,     0,   260,  1551,  1552,     0,
       0,     0,    67,    68,    69,    70,    71,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    82,     0,     0,
      85,     0,     0,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,  1184,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,   399,   400,   401,   262,   263,     0,     0,     0,
     264,   265,   266,   402,   267,   268,   269,   403,     0,   404,
     116,     0,     0,     0,     0,     0,     0,     0,  1641,     0,
       0,     0,     0,     0,     0,     0,   270,   271,  1649,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   359,   206,
     164,   378,   274,   427,  2181,   275,   207,   208,   209,     0,
       0,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   414,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   239,   240,   241,   242,   388,   389,   390,   391,
     243,     0,     0,     0,   392,   393,   394,     0,     0,     0,
       0,   395,     0,   396,   247,   248,   249,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    25,   397,   251,     0,
     398,     0,     0,     0,   298,     0,     0,   299,     0,     0,
     300,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     428,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1784,     0,     0,     0,     0,     0,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1185,
       0,   429,     0,     0,     0,     0,     0,     0,   261,   399,
     400,   401,   262,     0,     0,     0,     0,   264,   265,   266,
     402,   267,   268,   269,   403,     0,   404,   116,   430,   431,
     432,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   415,     0,     0,     0,     0,     0,
     272,     0,   434,   435,     0,   436,     0,   437,   206,     6,
     358,   438,   275,     0,     0,   207,   208,   209,     0,     0,
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
       0,     0,     0,    82,     0,     0,    85,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,  1505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,   262,   263,     0,     0,     0,   264,   265,   266,     0,
     267,   268,   269,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   271,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   359,   206,     6,     0,   360,     0,
     668,   275,   207,   208,   209,     0,     0,   210,   211,   212,
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
      82,     0,     0,    85,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   262,   263,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     498,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   359,   206,     6,  1686,     0,   564,     0,   275,   207,
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
      85,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  1779,
       0,     0,     0,  1780,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,   262,   263,     0,     0,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   271,     0,     0,
       0,     0,     0,   272,     0,     0,     0,     0,   359,   206,
       6,     0,   274,     0,     0,   275,   207,   208,   209,     0,
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
      78,     0,     0,     0,    82,     0,     0,    85,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  1832,     0,     0,     0,
    1833,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,   262,   263,     0,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   630,  1851,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   632,   206,     6,     0,   320,
     564,     0,   275,   207,   208,   209,     0,     0,   210,   211,
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
       0,    82,     0,     0,    85,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  1859,     0,     0,     0,  1860,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,   262,
     263,     0,     0,     0,   264,   265,   266,     0,   267,   268,
     269,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   271,     0,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   273,   206,     6,     0,   274,     0,     0,   275,
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
       0,    85,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    2030,     0,     0,     0,  2031,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   262,   263,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   271,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   359,
     206,     6,     0,   274,     0,     0,   275,   207,   208,   209,
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
      77,    78,     0,     0,     0,    82,     0,     0,    85,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   770,     0,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,   262,   263,     0,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   498,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,   359,   206,     6,     0,
     559,     0,     0,   275,   207,   208,   209,     0,     0,   210,
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
       0,     0,    82,     0,     0,    85,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   776,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
     262,   263,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   498,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   359,   206,     6,     0,     0,   564,     0,
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
       0,     0,    85,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   936,     0,     0,     0,     0,
       0,     0,     0,   261,     0,     0,     0,   262,   263,     0,
       0,     0,   264,   265,   266,     0,   267,   268,   269,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   271,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     602,   206,     6,     0,   274,     0,     0,   275,   207,   208,
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
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   937,     0,     0,     0,     0,     0,     0,     0,
     261,     0,     0,     0,   262,   263,     0,     0,     0,   264,
     265,   266,     0,   267,   268,   269,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   271,     0,     0,     0,
       0,     0,   272,     0,     0,     0,     0,   609,   206,     6,
       0,   274,     0,     0,   275,   207,   208,   209,     0,     0,
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
       0,     0,     0,    82,     0,     0,    85,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   983,
       0,     0,     0,     0,     0,     0,     0,   261,     0,     0,
       0,   262,   263,     0,     0,     0,   264,   265,   266,     0,
     267,   268,   269,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,   498,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   359,   206,     6,     0,   897,     0,
    1358,   275,   207,   208,   209,     0,     0,   210,   211,   212,
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
      82,     0,     0,    85,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1092,     0,     0,     0,
       0,     0,     0,     0,   261,     0,     0,     0,   262,   263,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     498,     0,     0,     0,     0,     0,   272,   206,     6,     0,
       0,   359,  1567,     0,   207,   208,   209,     0,   275,   210,
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
       0,     0,    82,     0,     0,    85,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1093,     0,
       0,     0,     0,     0,     0,     0,   261,     0,     0,     0,
     262,   263,     0,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   498,     0,     0,     0,     0,     0,   272,   206,
       6,     0,     0,   359,     0,     0,   207,   208,   209,     0,
     275,   210,   211,   212,   213,   214,   215,   216,   217,   218,
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
      78,     0,     0,     0,    82,     0,     0,    85,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1094,     0,     0,     0,     0,     0,     0,     0,   261,     0,
       0,     0,   262,   263,     0,     0,     0,   264,   265,   266,
       0,   267,   268,   269,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,   271,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   359,   206,     6,     0,  1694,
       0,     0,   275,   207,   208,   209,     0,     0,   210,   211,
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
       0,    82,     0,     0,    85,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1095,     0,     0,
       0,     0,     0,     0,     0,   261,     0,     0,     0,   262,
     263,     0,     0,     0,   264,   265,   266,     0,   267,   268,
     269,     0,     0,     0,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,  1851,     0,     0,     0,     0,     0,   272,     0,     0,
       0,     0,   632,   206,     6,     0,   320,     0,     0,   275,
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
       0,    85,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1133,     0,     0,     0,     0,     0,
       0,     0,   261,     0,     0,     0,   262,   263,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   498,     0,
       0,     0,     0,     0,   272,   206,   164,   378,     0,   359,
       0,     0,   207,   208,   209,     0,   275,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   414,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   239,   240,
     241,   242,   388,   389,   390,   391,   243,     0,     0,     0,
     392,   393,   394,     0,     0,     0,     0,   395,     0,   396,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,   397,   251,     0,   398,   206,   164,   378,
       0,     0,     0,     0,   207,   208,   209,     0,     0,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   414,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     239,   240,   241,   242,   388,   389,   390,   391,   243,     0,
       0,     0,   392,   393,   394,     0,     0,     0,     0,   395,
       0,   396,   247,   248,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   250,    25,   397,   251,     0,   398,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   261,   399,   400,   401,   262,     0,
       0,     0,     0,   264,   265,   266,   402,   267,   268,   269,
     403,     0,   404,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     415,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   359,     0,     0,     0,  1585,     0,     0,   275,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1143,     0,     0,     0,     0,   261,   399,   400,   401,
     262,     0,     0,     0,     0,   264,   265,   266,   402,   267,
     268,   269,   403,     0,   404,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   415,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   359,   206,   164,   378,  1864,     0,     0,
     275,   207,   208,   209,     0,     0,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   414,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,  1589,   380,
     381,   382,   383,   384,   385,   386,   387,   239,   240,   241,
     242,   388,   389,   390,   391,   243,     0,     0,     0,   392,
     393,   394,     0,     0,     0,     0,   395,     0,   396,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,     0,
     250,    25,   397,   251,     0,   398,   206,   164,   378,     0,
       0,     0,     0,   207,   208,   209,     0,     0,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   414,   228,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   239,
     240,   241,   242,   388,   389,   390,   391,   243,     0,     0,
       0,   392,   393,   394,     0,     0,     0,     0,   395,     0,
     396,   247,   248,   249,     0,     0,     0,     0,     0,     0,
       0,     0,   250,    25,   397,   251,     0,   398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   261,   399,   400,   401,   262,     0,     0,
       0,     0,   264,   265,   266,   402,   267,   268,   269,   403,
       0,   404,   116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,   415,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
     359,     0,     0,     0,  1749,     0,     0,   275,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1144,     0,     0,     0,     0,   261,   399,   400,   401,   262,
       0,     0,     0,     0,   264,   265,   266,   402,   267,   268,
     269,   403,     0,   404,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   415,     0,     0,     0,     0,     0,   272,   206,   164,
       0,     0,   359,     0,     0,   207,   208,   209,     0,   275,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   414,   228,   229,
     230,   231,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   239,   240,   241,   242,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   247,   248,   249,     0,     0,     0,     0,
       0,   206,   164,     0,   250,    25,   865,   251,   207,   208,
     209,     0,     0,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     414,   228,   229,   230,   231,   232,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   240,   241,   242,     0,     0,
       0,     0,   243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   248,   249,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    25,     0,
     251,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,   261,     0,     0,
       0,   262,     0,  1145,     0,     0,   264,   265,   266,     0,
     267,   268,   269,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   630,   631,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,   632,     0,     0,     0,   320,     0,
       0,   275,     0,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
     261,     0,     0,     0,   262,  1150,     0,     0,     0,   264,
     265,   266,     0,   267,   268,   269,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   415,     0,     0,     0,
       0,     0,   272,   206,   164,     0,     0,   359,     0,     0,
     207,   208,   209,     0,   275,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   414,   228,   229,   230,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,   206,   164,     0,  1310,     0,     0,     0,
     207,   208,   209,     0,     0,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   414,   228,   229,   230,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,   241,   242,
       0,     0,     0,     0,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   247,   248,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   250,
      25,     0,   251,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,   261,     0,     0,   590,   262,     0,     0,     0,
     715,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   415,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,   359,
    1081,     0,     0,     0,     0,     0,   275,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1151,
       0,     0,   261,     0,     0,     0,   262,     0,     0,     0,
       0,   264,   265,   266,     0,   267,   268,   269,     0,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   270,   415,     0,
       0,     0,     0,     0,   272,   206,   164,     0,  1466,   359,
       0,     0,   207,   208,   209,     0,   275,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   414,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,   206,   164,     0,  1529,     0,
       0,     0,   207,   208,   209,     0,     0,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   414,   228,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,   240,
     241,   242,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     247,   248,   249,     0,     0,     0,     0,     0,     0,     0,
       0,   250,    25,     0,   251,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,   261,     0,     0,   590,   262,     0,
       0,     0,   928,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     415,     0,     0,     0,     0,     0,   272,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,   275,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1153,     0,     0,   261,     0,     0,     0,   262,     0,
       0,     0,     0,   264,   265,   266,     0,   267,   268,   269,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     415,     0,     0,     0,     0,     0,   272,   206,   164,     0,
       0,   359,     0,     0,   207,   208,   209,     0,   275,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   414,   228,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   240,   241,   242,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   247,   248,   249,     0,     0,     0,     0,     0,
     206,   164,     0,   250,    25,     0,   251,   207,   208,   209,
       0,     0,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   414,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   239,   240,   241,   242,     0,     0,     0,
       0,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   247,   248,   249,     0,     0,
       0,     0,     0,     0,     0,     0,   250,    25,     0,   251,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,   261,     0,     0,     0,
     262,     0,  1263,     0,     0,   264,   265,   266,     0,   267,
     268,   269,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   270,   415,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,   359,  1583,     0,     0,     0,     0,     0,
     275,     0,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,   261,
       0,     0,     0,   262,  1284,     0,     0,     0,   264,   265,
     266,     0,   267,   268,   269,     0,     0,     0,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,   415,     0,     0,     0,     0,
       0,   272,   206,   164,     0,     0,   359,  1911,     0,   207,
     208,   209,     0,   275,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   414,   228,   229,   230,   231,   232,   233,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   239,   240,   241,   242,     0,
       0,     0,     0,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   247,   248,   249,
       0,     0,     0,     0,     0,     0,     0,     0,   250,    25,
       0,   251,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1368,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     7,     8,
       0,    43,    44,    45,    46,     0,     0,    48,     0,     0,
       0,     0,     0,     0,   751,    55,     0,     0,    58,   752,
       0,   753,   754,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   261,     0,     0,     0,   262,    93,    94,    95,     0,
     264,   265,   266,     0,   267,   268,   269,     0,     0,     0,
     116,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   270,   415,     0,    43,
      44,    45,    46,   272,     0,    48,     7,     8,   359,     0,
       0,     0,   751,    55,     0,   275,    58,   752,     0,   753,
     754,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,  1015,     0,     0,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,    93,    94,    95,   590,     0,     0,
       0,     0,     0,     0,     7,     8,     0,  1371,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     751,    55,     0,     0,    58,   752,     0,   753,   754,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,  1017,
       0,     0,     7,     8,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    93,    94,    95,    43,    44,    45,    46,     0,
       0,    48,     0,     0,     0,     0,     0,     0,   751,    55,
       0,     0,    58,   752,     0,   753,   754,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      93,    94,    95,    43,    44,    45,    46,  1215,     0,    48,
       0,     0,     0,     0,     0,     0,   751,    55,     0,     0,
      58,   752,     0,   753,   754,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    93,    94,
      95,    43,    44,    45,    46,  1217,     0,    48,     0,     0,
       0,     0,     0,     0,   751,    55,     0,     0,    58,   752,
       0,   753,   754,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    93,    94,    95,    43,
      44,    45,    46,  1218,     0,    48,     0,     0,     0,     0,
       0,     0,   751,    55,     0,     0,    58,   752,     0,   753,
     754,     0,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    93,    94,    95,    43,    44,    45,
      46,  1237,     0,    48,     0,     0,     0,     0,     0,     0,
     751,    55,     0,     0,    58,   752,     0,   753,   754,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    93,    94,    95,    43,    44,    45,    46,  1255,
       0,    48,     0,     0,     0,     0,     0,     0,   751,    55,
       0,     0,    58,   752,     0,   753,   754,     0,   755,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      93,    94,    95,    43,    44,    45,    46,  1269,     0,    48,
       0,     0,     0,     0,     0,     0,   751,    55,     0,     0,
      58,   752,     0,   753,   754,     0,   755,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    93,    94,
      95,    43,    44,    45,    46,  1302,     0,    48,     0,     0,
       0,     0,     0,     0,   751,    55,     0,     0,    58,   752,
       0,   753,   754,     0,   755,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    93,    94,    95,    43,
      44,    45,    46,  1458,     0,    48,     0,     0,     0,     0,
       0,     0,   751,    55,     0,     0,    58,   752,     0,   753,
     754,     0,   755,     0,     0,     0,     0,     0,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
      79,    -4,    -4,     0,     0,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,    93,    94,    95,   590,     0,     0,
       0,  2089,    -4,    -4,    -4,     0,     0,  1460,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,
      -4,     0,     0,     0,    -4,     0,     0,     0,     0,    -4,
      -4,    -4,    -4,    -4,     0,    -4,    -4,     0,    -4,     0,
       0,     0,     0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,  2148,
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
      95,   164,   378,    96,     0,    97,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
     116,     0,     0,     0,   379,   380,   381,   382,   383,   384,
     385,   386,   387,     0,     0,     0,     0,   388,   389,   390,
     391,   408,   378,     0,     0,   392,   393,   394,     0,     0,
       0,     0,   395,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   397,     0,
       0,   398,     0,     0,     0,   298,     0,   378,   299,     0,
       0,   300,     0,   301,   379,   380,   381,   382,   383,   384,
     385,   386,   387,     0,    46,     0,     0,   388,   389,   390,
     391,     0,     0,     0,     0,   392,   393,   394,     0,     0,
       0,   428,   395,     0,   396,     0,     0,     0,     0,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   397,     0,
       0,   398,   388,   389,   390,   391,     0,     0,     0,     0,
     392,   393,   394,     0,     0,     0,     0,   395,     0,   396,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   397,     0,     0,   398,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     399,   400,   401,     0,     0,     0,     0,     0,     0,     0,
       0,   402,     0,     0,     0,   403,     0,   404,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
     399,   400,   401,  1461,     0,     0,     0,     0,     0,     0,
       0,   402,     0,     0,     0,   403,     0,   404,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   399,   400,   401,     0,     0,
       0,     0,     0,     0,     0,     0,   402,     0,     0,     0,
     403,     0,   404,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     7,     8,     0,    43,
      44,    45,    46,     0,     0,    48,     0,     0,     0,     0,
       0,     0,   751,    55,     0,     0,    58,   752,     0,   753,
     754,     0,   755,     0,     0,     0,  1026,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,  1027,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,    93,    94,    95,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1504,     0,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    43,    44,    45,
      46,     0,     0,    48,     0,     0,     0,     0,     0,     0,
     751,    55,     0,     0,    58,   752,     0,   753,   754,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,    93,    94,    95,     0,     0,     0,     0,     0,
       0,  1630,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1631,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1632,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1646,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1777,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1898,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1899,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1931,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1934,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2001,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2056,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2057,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2072,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2074,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2107,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2135,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2140,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2141,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2142,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2182,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,   811,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  1061,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,  1120,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,  1165,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  1166,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  1209,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,  1240,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    1260,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  1316,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  1336,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,  1417,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  1418,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,  1462,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,  1535,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  1830,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  1841,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,  1878,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    1951,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  1966,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  1978,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,  2002,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,     0,  2036,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,  2045,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,     0,     0,  2046,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,  2070,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,  2121,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,     0,
       0,  2161,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,     0,     0,
    2180,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,     0,     0,  2200,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,  2201,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,  2202,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,     0,  1944,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
     737,     0,   738,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,   989,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,  1037,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,  1189,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
    1254,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,  1256,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,     0,     0,  1261,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   714,   586,
     587,   588,   589,     0,     0,     0,     0,   590,     0,     0,
       0,  1262,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   714,   586,   587,   588,   589,
       0,     0,     0,     0,   590,     0,     0,     0,  1350,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   714,   586,   587,   588,   589,     0,     0,     0,
       0,   590,     0,     0,     0,  1364,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   714,
     586,   587,   588,   589,     0,     0,     0,     0,   590,     0,
       0,     0,  1564,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,     0,     0,  1652,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     582,   583,   584,   714,   586,   587,   588,   589,     0,     0,
       0,     0,   590,     0,     0,     0,  1701,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     714,   586,   587,   588,   589,     0,     0,     0,     0,   590,
       0,     0,     0,  1890,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   714,   586,   587,
     588,   589,     0,     0,     0,     0,   590,     0,     0,     0,
    1936,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   714,   586,   587,   588,   589,     0,
       0,     0,     0,   590,     0,     0,     0,  1952,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   792,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   793,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   794,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   796,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   797,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   798,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   800,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   801,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   802,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   803,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   804,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   805,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   806,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   808,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   809,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   810,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   877,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   912,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   958,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   977,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   979,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   980,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   981,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,   987,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,   988,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1025,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1036,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1100,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1104,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1116,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1188,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1198,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1199,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1200,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1210,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1239,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1241,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1242,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1243,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1244,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1245,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1246,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1247,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1253,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1349,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1363,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1565,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1597,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1598,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1599,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1600,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1638,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1651,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1764,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1766,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1769,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1776,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1831,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1840,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1863,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  1935,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  1999,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  2000,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590,     0,  2134,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   714,   586,   587,   588,   589,     0,     0,     0,     0,
     590,     0,  2177,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   714,   586,   587,   588,
     589,     0,     0,     0,     0,   590
};

static const yytype_int16 yycheck[] =
{
       3,   313,  1238,     3,   156,   627,   628,  1234,   732,   719,
    1424,  1688,   325,  1732,    62,  1734,   740,     4,   195,     9,
       4,   107,    25,   109,     4,     4,   203,   142,    25,     7,
       4,   344,     4,     4,     4,     4,     4,     9,   748,     6,
    1914,     5,     5,     4,     6,  1719,     6,     5,     5,   104,
       6,    54,     7,     4,   159,   765,   142,     4,     4,   104,
       4,     4,   138,     6,     6,   775,   237,   238,   250,   237,
     238,     4,   127,     0,     4,    98,   258,     9,   101,   184,
      83,   104,   127,   169,     7,     9,     6,   258,    91,     6,
     258,   237,   238,    96,   117,   200,   201,   104,   411,   250,
     413,   252,     9,    90,   107,   237,   238,   258,   421,   250,
    1784,   187,   258,   237,   238,   237,   238,   258,   295,   296,
     297,   249,     9,   251,   138,     9,   258,  1804,     4,   252,
     258,    14,   246,   247,   258,   258,   258,     7,     6,   142,
     138,   255,   156,   143,   147,   148,   149,     6,     6,   249,
     164,   165,   166,   156,     6,    98,   170,   171,   156,   252,
     337,   338,   339,   107,   108,   258,   164,   165,   166,   879,
      98,   174,   170,   171,     7,   237,   238,   354,     7,   246,
     247,     6,   250,     7,   252,     3,   253,   190,     7,   117,
     258,  2065,   195,   237,   238,   198,   258,   245,   246,   249,
     203,   204,   205,   250,   174,   175,   176,   177,   195,   253,
     172,   258,   172,   143,   144,   145,   146,   246,   247,   149,
     237,   238,    98,   184,   185,   199,   102,   101,   158,  1643,
     104,   161,   108,   109,   221,   111,   112,   254,   184,   185,
     254,   221,   221,    61,   222,   223,   224,   225,   253,   221,
     221,  1478,   257,   221,   257,   131,   246,   247,   250,   249,
     249,   251,   252,   255,  1941,   255,   253,   251,   271,   253,
     221,   274,   275,   257,   246,   247,   256,   249,   275,   251,
     249,   253,   253,   255,   254,   253,   253,   290,   291,   253,
     253,   294,   295,   296,   297,   253,   253,   253,     6,   250,
     255,   252,   249,   616,   307,   618,   619,   249,   311,     6,
     313,   253,  1036,  1037,   246,   247,   249,   249,  1995,   251,
     237,   238,   635,   255,   142,   249,   249,   251,   251,   147,
     148,   149,   335,   249,   337,   338,   339,   250,   156,   252,
     653,   427,   249,     8,   251,   258,    68,    69,   255,    71,
     250,   354,   222,   223,   224,   225,     6,   360,   258,   246,
     247,   253,   249,   676,   251,   249,     6,   251,   255,   237,
     238,   255,   190,   550,   232,   233,   246,   247,   237,   238,
     232,   233,  2101,   255,     6,   255,   258,   205,   540,   222,
     223,   224,   225,   222,   223,   224,   225,     6,   222,   223,
     224,   225,   715,   222,   223,   224,   225,   138,   251,   237,
     238,   237,   238,   246,   247,   418,   419,   246,   247,   251,
     423,   424,   246,   247,     6,   156,   244,   237,   238,   249,
     258,   251,   258,   164,   165,   166,   439,   237,   238,   170,
     171,   259,   260,   446,     6,     7,   237,   238,   258,   250,
     237,   238,   237,   238,   237,   238,   101,   258,   258,   104,
    2137,   106,  1172,   249,  1174,   138,   469,   258,   237,   238,
     556,   258,   117,   258,   250,   258,   138,  1187,   237,   238,
     237,   238,   258,   156,   237,   238,   237,   238,   250,   258,
     252,   164,   165,   166,   156,   498,   258,   170,   171,   258,
     249,   258,   164,   165,   166,   258,   249,   258,   170,   171,
     242,   243,   249,  2190,   101,   249,   248,   104,  1932,   522,
     237,   238,   249,   254,   237,   238,   529,   530,   237,   238,
     117,   534,   684,   536,   537,   538,   539,   540,   249,   249,
     249,   258,   545,   253,   253,   258,   549,   550,   551,   552,
     553,   554,   555,   249,   557,   251,   559,   253,   555,   249,
     557,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   249,
     249,   254,   585,   248,   253,   237,   238,  1297,   591,   254,
     237,   238,   254,  1303,   316,   317,   250,   249,   237,   238,
     418,   253,   324,   325,   258,   104,   253,   106,   611,   612,
     428,   697,   250,   249,   253,    98,   249,   732,   101,   932,
     258,   104,   250,   106,   252,   250,  1248,   627,   628,   249,
     258,   254,   450,   258,   117,   258,   237,   238,  1348,   237,
     238,   239,   240,   241,   242,   243,   246,   247,   143,   144,
     248,   254,  1362,   253,   149,   258,   659,   660,   661,  1369,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   101,     6,     7,   104,   248,   106,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   249,   692,
     693,   694,   695,   696,   249,   698,   699,   700,   701,   702,
     249,   253,   705,   254,   701,   791,   754,   258,   239,   240,
     241,   242,   243,   716,   104,   254,   534,   248,   536,   258,
     538,   539,   540,   249,   254,   251,   729,  1451,   258,   255,
     119,   249,   258,   251,   552,   553,   739,   249,   255,   251,
     257,   253,   745,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   761,   762,
       6,   253,   248,   254,   767,    98,   769,   258,   101,   772,
     773,   104,   253,   106,   143,   144,   779,   254,   781,   254,
     149,   258,   254,   258,   254,   254,   258,   254,   258,   258,
     254,   258,   254,   908,   258,   254,   258,   254,   254,   258,
     254,   258,   258,   254,   258,   254,   254,   258,   254,   258,
     258,   814,   258,   816,  1538,   633,   254,   254,   254,    54,
     258,   258,   258,   254,   254,   254,  1550,   258,   258,   258,
     254,   254,   106,   254,   258,   258,   922,   258,   656,   254,
     254,   254,   253,   258,   258,   258,   849,   254,   254,   254,
     104,   258,   258,   258,  2090,   254,   859,   254,   254,   258,
     101,   258,   258,   249,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   249,   692,   693,   694,   695,   249,   254,
     698,   699,   700,   258,   254,   253,   249,   254,   258,   253,
     708,   258,   253,   711,   897,   254,  2123,   254,   254,   258,
     104,   258,   258,   625,   626,   723,   254,   910,   630,   101,
     258,   254,   101,  2149,   254,   258,   919,   104,   258,   254,
     254,  1036,  1037,   258,   258,   928,   254,   254,   254,     4,
     258,   258,   258,     4,     5,   753,     4,   755,   254,   254,
    2167,   254,   258,   258,   250,   258,   252,   253,   250,     4,
     252,   253,  1038,   250,   772,   252,   249,   249,   251,   251,
     249,     4,   251,   781,   249,     4,   251,     6,   142,   204,
     249,   249,   249,   147,   148,   149,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   249,   249,     6,     6,    60,
      61,    62,    63,   251,   249,   251,   253,    68,    69,    70,
       6,     6,   253,   187,    75,   257,    77,   257,     9,   249,
     249,   249,   249,   249,   187,   249,   190,  1329,   249,   249,
      91,   253,   257,    94,   249,   249,   187,    98,  1031,   127,
     101,   205,   253,   104,   249,   106,   249,   249,   249,  1042,
     187,   249,   249,   253,  1047,     4,   117,   253,   253,     6,
     253,  1673,  1674,   253,   253,   249,   249,  1060,   249,   294,
       6,   249,  1065,   134,   249,   251,   249,   249,   249,     6,
       6,   251,   307,  1188,  1189,   253,   311,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   253,   253,  1098,  1099,   248,  1101,  1102,
    1103,   253,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,   251,   931,  1117,   933,   934,   251,     6,   249,
     253,   187,   249,   249,   249,   249,   249,     6,     6,   947,
     251,   253,   203,   204,   205,     6,     8,     6,     8,   253,
       7,     6,   253,   214,   253,     6,   253,   218,   966,   220,
     221,   254,  1155,  1156,  1157,    93,   258,   258,   250,     7,
       6,     6,   250,   253,   253,   248,   984,   253,   253,    65,
       8,   255,     4,     7,     7,   249,  1179,     6,   250,   250,
       6,   252,   253,   253,     8,     7,     6,     6,   423,   424,
       7,     6,  1195,  1196,  1197,   254,   184,   253,   250,     6,
     254,   254,  1020,   252,   439,   253,     7,     6,   255,   251,
       4,   249,   253,   935,     6,  1528,     6,     6,     6,  1532,
     942,     6,   250,     7,   946,   251,     7,     7,     7,     7,
       7,     7,     7,  1545,  1349,  1350,     7,     7,     7,     7,
       7,     7,     7,     7,   418,   253,  1249,  1065,  1248,     6,
     250,   258,   254,   252,   258,   258,   250,     7,   253,   255,
     258,  1264,  1265,  1266,   254,     7,   253,   253,     4,     6,
     255,   254,  1275,   254,   138,   253,     7,  1280,     6,   255,
       7,  1284,     7,     7,   250,   250,  1372,   258,  1374,   258,
    1293,     9,  1295,   255,   258,  1298,   250,   252,   187,   257,
       7,   159,   537,   254,   253,     6,     6,     6,     4,    47,
    1313,   255,    47,   253,   549,   249,   551,   249,   253,   249,
     249,     4,   255,     7,   255,  1947,  1329,     7,     7,   250,
     258,   187,     7,     7,     7,     6,   250,     7,  1156,  1157,
     258,     7,     7,     4,   116,     4,   253,  1350,     6,   249,
       7,     6,  1355,     7,  1357,     7,     7,     7,     7,     7,
     534,     7,   536,   253,   538,   539,     6,     6,     6,     6,
     104,  1374,     7,     6,     4,  1097,     4,   258,   552,   553,
     256,   258,   250,     6,  1387,     6,     6,   253,  1391,     6,
       8,   253,     7,   253,   251,   254,     6,   249,  1216,  1551,
    1552,     6,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       6,   249,   253,  1538,   248,   255,     6,   254,     6,   252,
     254,     6,     6,   258,  1746,     6,   131,     6,  1524,     6,
       6,     6,  1445,  1446,  1447,     6,     6,     6,     6,     6,
    1453,     6,     6,     5,   250,   250,     6,     4,     6,     4,
       6,   254,  1280,     7,   251,  1468,  1284,   253,     6,     6,
     253,   253,     6,     6,     6,  1293,  1479,  1295,   183,   253,
    1298,     6,     6,     6,  1487,   258,     6,     4,  1491,  1307,
     253,   253,   253,   253,   729,   253,   255,   253,   253,  1585,
     253,   250,   253,     7,   258,   249,   258,   253,     6,   683,
     258,   685,   686,   687,   688,   689,   690,     6,   692,   693,
     694,   695,   254,     6,   698,   699,   700,     6,   249,     4,
     249,     7,  1350,     6,     6,  1650,     6,     6,   138,     6,
       8,     6,  1545,     6,     6,     5,   102,   253,  1551,  1552,
     258,   253,   250,     6,  1557,     6,   253,     6,     6,     6,
       6,   250,     6,     4,   258,   258,   258,     6,     6,     6,
     258,   253,  1575,     6,     6,     6,     6,   253,     7,   142,
       6,   253,  1585,  1669,   253,   253,     5,  1590,   250,     6,
       6,     6,     6,   253,     7,     6,     6,  1749,   772,   182,
     253,     6,     6,   185,     7,   250,   253,   781,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,  1712,   254,   254,   254,
     248,     6,   250,  1719,  1720,   254,     6,     6,   254,     6,
     253,   255,     6,  1956,     6,   254,     6,  1762,   250,     6,
     253,     6,  1738,     6,   253,     6,   254,   254,   249,  1662,
     253,   250,  1665,  1666,     6,   253,   253,     6,   253,     6,
     254,     6,  1984,  1673,  1674,     6,   253,   138,     6,     6,
     253,     6,   250,     6,   919,  1688,     6,     6,     6,     6,
     254,  1694,   254,     6,     6,     6,     6,     6,     6,     6,
     253,  1704,   253,     6,   253,     6,     6,     6,  1361,  2103,
    1595,  1714,  1419,  1915,  1717,  1875,     3,  1658,  1386,   466,
       3,     3,     3,   606,  1943,  1521,     3,  1742,  1719,  1552,
      -1,    -1,  1735,  1551,  1552,   772,    -1,  2050,    -1,  1742,
      -1,    -1,    -1,  1746,    -1,  1748,  1749,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1477,    -1,  1575,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     6,    -1,  2091,    -1,
     248,  1784,   250,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,  1877,    -1,    -1,    -1,    -1,  1031,    -1,    -1,    -1,
      -1,  1804,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1047,  1816,  1817,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     6,  1920,    -1,  1839,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1851,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1864,    -1,  1098,  1099,    -1,  1101,  1102,  1103,    -1,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
      -1,  1603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1065,    -1,    -1,    -1,    -1,  1714,    -1,  1901,  1717,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1916,  1732,    -1,  1734,    -1,  1921,    -1,
    1155,  1924,  1925,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1749,    -1,    -1,    -1,    -1,    -1,    -1,  1941,    -1,
      -1,  1944,    -1,    -1,  1179,    -1,    -1,  1947,    -1,    -1,
      -1,    -1,  1955,    -1,    -1,    -1,  1959,    -1,    -1,    -1,
    1195,    -1,    -1,    -1,    -1,    -1,  1784,  1689,  1690,  1691,
    1692,  1693,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2066,  1984,  1156,  1157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1995,    -1,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,  1249,    -1,    -1,    -1,   248,    -1,
    2023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1264,
    1265,  1266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,  2075,    -1,    -1,   248,    -1,    -1,  1313,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2093,  2094,  2095,  2096,  2097,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1280,    -1,    -1,    -1,
    1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1293,
      -1,  1295,    -1,    -1,  1298,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2137,    -1,    -1,    -1,    -1,  1374,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2154,  1387,    -1,    -1,    -1,  1391,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2176,    -1,    -1,  1350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2190,    -1,    -1,
      -1,    -1,    -1,    -1,  2197,  2198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2211,    -1,
    1445,  1446,  1447,     6,    -1,     4,     5,  2035,  1453,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1468,    -1,    -1,    -1,    -1,  1960,  1961,
    1962,  1963,  1964,    -1,  1479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1487,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,  2101,    -1,    -1,    75,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2022,    -1,    91,    -1,  2026,    94,  2124,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,    -1,
      -1,    -1,  1557,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
    1585,    -1,    -1,    -1,    -1,  2077,    -1,    -1,  2176,  2081,
      -1,   142,    -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,  2097,    -1,    -1,   159,  2197,
    2198,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2211,   175,   176,   177,    -1,   179,   180,
     181,  1575,   183,   184,   185,   186,   187,   188,   189,    -1,
     191,   192,   193,   194,   203,   204,   205,   198,    -1,    -1,
      -1,    -1,  2144,  2145,    -1,   214,    -1,  1662,    -1,   218,
      -1,   220,   221,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,  1688,    -1,   248,    -1,   246,   247,    -1,
      -1,    -1,    -1,    -1,   253,    -1,   255,    -1,    -1,  1704,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,
     271,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,    -1,
    1735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,   290,
     291,    -1,    -1,  1748,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   319,   320,
    1714,    -1,    -1,  1717,   325,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   335,   336,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1804,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   359,   360,
      -1,    -1,    -1,   364,   365,   366,    -1,   368,    -1,    -1,
      -1,   372,   373,   374,    -1,    -1,   377,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1839,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,   415,    -1,    -1,    -1,   419,   420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,   437,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1901,    -1,    -1,    -1,
     451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1916,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     471,   472,   473,   474,    -1,    -1,    -1,    -1,   479,    -1,
      -1,    -1,   483,    -1,    -1,    -1,  1941,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   497,   498,    -1,    -1,
    1955,   502,    -1,    -1,    -1,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
      -1,   532,   533,    -1,   535,    -1,    -1,    -1,    -1,    -1,
    1995,    -1,    -1,   544,    -1,    -1,   547,   548,    -1,    -1,
      -1,    -1,    -1,   554,    -1,    -1,    -1,    -1,   559,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2023,    -1,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
      -1,   592,   593,    -1,    -1,    -1,    -1,    -1,    -1,   600,
     601,   602,    -1,    -1,    -1,    -1,    -1,   608,   609,    -1,
     611,   612,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,
     631,   632,    -1,    -1,    -1,   636,   637,   638,   639,   640,
     641,   642,   643,   644,     8,    -1,    -1,    -1,    -1,   650,
      -1,   652,    -1,    -1,   655,    -1,    -1,    -1,   659,   660,
     661,   662,    -1,   664,   665,   666,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,
      -1,   712,    -1,   714,    -1,    -1,   717,   718,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   726,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2190,    -1,    -1,   739,    -1,
     741,    -1,    -1,   198,    -1,   746,   747,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     761,    -1,   763,   764,    -1,    -1,   767,    -1,   769,   770,
      -1,    -1,    -1,   774,    -1,   776,    -1,    -1,    -1,    -1,
      -1,   782,  2176,    -1,    -1,   786,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2197,  2198,    -1,    -1,    -1,    -1,    -1,
     198,   812,    -1,   814,    -1,   816,   271,  2211,    -1,   274,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   290,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   849,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   859,   860,
     861,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     335,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   897,    -1,    -1,    -1,
      -1,    -1,   290,   291,    -1,   360,    -1,    -1,    -1,   910,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,    -1,    -1,
      -1,   922,    -1,    -1,    -1,    -1,    -1,   928,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   936,   937,    -1,    -1,    -1,
      -1,   942,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   959,    -1,
      -1,   962,    -1,    -1,   419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   983,    -1,   985,   986,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1004,    -1,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,  1027,    -1,   248,    -1,
      -1,   419,    -1,  1034,    -1,    -1,    -1,    -1,  1039,    -1,
      -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1054,  1055,    -1,    -1,    -1,    -1,  1060,
      -1,    -1,    -1,    -1,    -1,     6,    -1,   522,    -1,    -1,
      -1,    -1,    -1,    -1,   529,   530,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1092,  1093,  1094,  1095,    -1,    -1,    -1,    -1,   554,
      -1,    -1,    -1,     6,   559,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     585,    -1,  1133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,  1143,  1144,  1145,    -1,    -1,    -1,    -1,  1150,
    1151,    -1,  1153,    -1,    -1,    -1,   611,   612,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1167,  1168,    -1,    -1,
      -1,   559,    -1,    -1,  1175,  1176,    -1,    -1,    -1,    -1,
      -1,  1182,    -1,  1184,  1185,     6,    -1,    -1,    -1,    -1,
    1191,  1192,    -1,    -1,    -1,  1196,  1197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   659,   660,   661,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   611,   612,    -1,    -1,  1228,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
     705,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   659,   660,   661,  1275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1283,    -1,   739,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,  1304,  1305,    -1,   761,   248,  1309,    -1,
      -1,    -1,   767,    -1,   769,    -1,    -1,   705,    -1,  1320,
      -1,    -1,  1323,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
    1351,   739,    -1,  1354,  1355,  1356,  1357,    -1,    -1,   814,
      -1,   816,    -1,    -1,  1365,    -1,    -1,  1368,    -1,  1370,
    1371,  1372,    -1,   761,    -1,    -1,    -1,    -1,    -1,   767,
      -1,   769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   849,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   859,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   897,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1452,    -1,    -1,    -1,   910,    -1,    -1,  1459,  1460,
    1461,   849,    -1,    -1,    -1,    -1,    -1,  1468,    -1,  1470,
      -1,   859,    -1,   928,    -1,    -1,  1477,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
    1491,    -1,    -1,    -1,    -1,  1496,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,  1505,  1506,    -1,    -1,    -1,   897,
      -1,    -1,    -1,    -1,    -1,  1516,    -1,    -1,    -1,    -1,
      -1,    -1,   910,    -1,    -1,  1526,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
     928,    60,    61,    62,    63,    -1,    -1,    -1,  1549,    68,
      69,    70,    -1,    -1,  1555,  1556,    75,    -1,    77,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,   106,    -1,  1590,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,  1060,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1630,
    1631,  1632,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1641,    -1,    -1,    -1,    -1,  1646,  1647,  1648,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1660,
      -1,    -1,  1117,    -1,  1665,  1666,  1667,    -1,  1669,    -1,
      -1,    -1,  1060,    -1,  1675,  1676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   203,   204,   205,    -1,    -1,    -1,
      -1,    -1,    -1,  1694,    -1,   214,    -1,    -1,  1699,   218,
      -1,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1712,    -1,    -1,  1715,    -1,    -1,    -1,  1719,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1728,  1729,  1117,
    1731,    -1,    -1,    -1,   253,    -1,    -1,    -1,  1739,    -1,
      -1,  1196,  1197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,  1755,    -1,    -1,    -1,    -1,  1760,
    1761,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1774,    -1,    -1,  1777,  1778,    -1,  1780,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,  1196,  1197,
      -1,    -1,    -1,    -1,    -1,  1816,  1817,     6,    -1,    -1,
    1275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1851,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1860,
    1861,    -1,    -1,  1864,    -1,    -1,   545,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,  1275,     6,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,  1898,  1899,    -1,
    1355,    -1,  1357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,  1919,    -1,
      -1,    -1,    -1,  1924,  1925,  1926,    -1,    -1,    -1,    -1,
    1931,    -1,    -1,  1934,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1944,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1959,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1967,  1355,    -1,  1357,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,  1992,   248,     6,    -1,    -1,    -1,  1998,    -1,    -1,
    2001,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,   250,    -1,   252,    -1,    -1,
    2031,    -1,    -1,   258,    -1,    -1,  1491,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,  2056,  2057,    -1,    -1,   248,
      26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2071,  2072,    -1,  2074,  2075,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2088,    -1,    -1,
      -1,    -1,  2093,  2094,  2095,  2096,  2097,    -1,    -1,    -1,
      -1,    -1,  2103,  1491,    -1,    -1,  2107,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,  2135,  1590,    -1,    -1,    -1,  2140,
    2141,  2142,   821,   822,   823,   824,   825,   826,   827,   828,
     829,   830,   831,  2154,   833,   834,   835,   836,     6,   838,
     839,   840,   841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   852,    -1,   854,   142,    -1,    -1,    -1,
      -1,  2182,  2183,  2184,    -1,   864,    -1,    -1,    -1,    -1,
      -1,    -1,   871,   872,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   880,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1665,  1666,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,  1694,
      -1,    -1,    -1,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,    -1,   241,   242,  1665,  1666,    -1,
      -1,    -1,    -1,    -1,   250,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   262,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   990,   991,   992,    -1,    -1,    -1,   996,   997,    -1,
      -1,  1000,  1001,  1002,  1003,    -1,  1005,    -1,    -1,    -1,
      -1,  1010,    -1,    -1,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,   248,    -1,   250,    -1,
      -1,  1816,  1817,    -1,    13,    14,   258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,  1851,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1864,
      -1,    -1,  1091,   379,   380,   381,    -1,  1096,    -1,   385,
     386,   387,   388,   389,   390,   391,    -1,   393,  1816,  1817,
      -1,   397,   398,    -1,    -1,   401,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    -1,    -1,    -1,   114,   115,   116,   117,  1924,
    1925,   120,    -1,    -1,    -1,    -1,  1864,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,  1944,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1959,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,    -1,    -1,    -1,  1924,  1925,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1944,    -1,    -1,    -1,
       3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,  1959,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     7,    -1,    -1,    -1,
      -1,   567,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
    2075,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,  2093,  2094,
    2095,  2096,  2097,    -1,    -1,    -1,    89,    90,    -1,    92,
      -1,    -1,    -1,  1332,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2075,    -1,    -1,
      -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,  2154,
      -1,    -1,    -1,    -1,    -1,  2093,  2094,  2095,  2096,  2097,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1405,  1406,  1407,  1408,
    1409,    -1,    -1,    -1,    -1,  1414,  1415,    -1,    -1,    -1,
      -1,  1420,    -1,  1422,    -1,    -1,    -1,  1426,    -1,    -1,
    1429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      13,    14,  1441,   206,    -1,    -1,  2154,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
     253,    -1,    -1,   256,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,  1512,    -1,  1514,    -1,   248,    -1,  1518,
      -1,  1520,     4,     5,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
      -1,   114,   115,   116,   117,    -1,    -1,   120,    -1,    -1,
      -1,    -1,  1551,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,   155,    -1,    -1,    -1,    68,    69,    70,   875,
      -1,    -1,     8,    75,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,    91,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   909,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
    1649,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,   254,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    73,
      74,    75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,   203,   204,   205,    -1,    89,    90,    91,    92,    -1,
      94,    -1,   214,    -1,    98,    -1,   218,   101,   220,   221,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,  1751,   117,    -1,  1754,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,    -1,   132,    -1,
     134,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,    -1,  1085,
      -1,    -1,    -1,    -1,    -1,    -1,  1805,  1806,    -1,  1808,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,   206,   207,    -1,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,     8,   220,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1868,
    1869,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,
      -1,    -1,   256,    -1,  1180,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,  1917,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,    -1,    68,    69,    70,
      -1,    -1,    73,    74,    75,    -1,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    -1,    94,    -1,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
      -1,   132,    -1,   134,    -1,    -1,   137,  1333,  1334,    -1,
      -1,    -1,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,    -1,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     8,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,   206,   207,    -1,    -1,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,   220,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1424,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,  1434,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,
       4,     5,   253,     7,  2163,   256,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    75,    -1,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    -1,
      94,    -1,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,   220,   221,   222,   223,
     224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,   246,   247,    -1,   249,    -1,   251,     3,     4,
       5,   255,   256,    -1,    -1,    10,    11,    12,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,   249,     3,     4,    -1,   253,    -1,
       8,   256,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,    -1,    -1,    -1,   206,   207,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,     3,     4,     5,    -1,   254,    -1,   256,    10,
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
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,     3,
       4,    -1,   253,    -1,    -1,   256,    10,    11,    12,    -1,
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
     248,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    -1,   206,   207,    -1,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,   249,     3,     4,    -1,   253,
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
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,     3,     4,    -1,    -1,   254,    -1,
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
      -1,   253,    -1,    -1,   256,    10,    11,    12,    -1,    -1,
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
       8,   256,    10,    11,    12,    -1,    -1,    15,    16,    17,
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
     238,    -1,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
      -1,   249,     8,    -1,    10,    11,    12,    -1,   256,    15,
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
       4,    -1,    -1,   249,    -1,    -1,    10,    11,    12,    -1,
     256,    15,    16,    17,    18,    19,    20,    21,    22,    23,
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
     244,    -1,    -1,    -1,    -1,   249,     3,     4,    -1,   253,
      -1,    -1,   256,    10,    11,    12,    -1,    -1,    15,    16,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
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
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    -1,   206,   207,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,     3,     4,     5,    -1,   249,
      -1,    -1,    10,    11,    12,    -1,   256,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    -1,    94,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      -1,    77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,   253,    -1,    -1,   256,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,   220,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,     3,     4,     5,   253,    -1,    -1,
     256,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
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
      -1,    -1,    -1,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    -1,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
     249,    -1,    -1,    -1,   253,    -1,    -1,   256,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,    -1,    -1,    -1,    -1,   202,   203,   204,   205,   206,
      -1,    -1,    -1,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,   220,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     237,   238,    -1,    -1,    -1,    -1,    -1,   244,     3,     4,
      -1,    -1,   249,    -1,    -1,    10,    11,    12,    -1,   256,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,     3,     4,    -1,    89,    90,     8,    92,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,
      92,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,   202,    -1,    -1,
      -1,   206,    -1,   258,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,   253,    -1,
      -1,   256,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     202,    -1,    -1,    -1,   206,   258,    -1,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,    -1,   249,    -1,    -1,
      10,    11,    12,    -1,   256,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,     3,     4,    -1,     6,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      90,    -1,    92,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,   202,    -1,    -1,   248,   206,    -1,    -1,    -1,
     253,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,   249,
     250,    -1,    -1,    -1,    -1,    -1,   256,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,
      -1,    -1,   202,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,   238,    -1,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,     6,   249,
      -1,    -1,    10,    11,    12,    -1,   256,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,     3,     4,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    -1,    92,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   202,    -1,    -1,   248,   206,    -1,
      -1,    -1,   253,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,   256,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,    -1,   202,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
      -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   237,
     238,    -1,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
      -1,   249,    -1,    -1,    10,    11,    12,    -1,   256,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    89,    90,    -1,    92,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    92,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,    -1,    -1,    -1,   202,    -1,    -1,    -1,
     206,    -1,   258,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,    -1,    -1,    -1,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   237,   238,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,    -1,   249,   250,    -1,    -1,    -1,    -1,    -1,
     256,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   202,
      -1,    -1,    -1,   206,   258,    -1,    -1,    -1,   211,   212,
     213,    -1,   215,   216,   217,    -1,    -1,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,    -1,    -1,    -1,    -1,
      -1,   244,     3,     4,    -1,    -1,   249,   250,    -1,    10,
      11,    12,    -1,   256,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    92,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    13,    14,
      -1,   114,   115,   116,   117,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    -1,   206,   179,   180,   181,    -1,
     211,   212,   213,    -1,   215,   216,   217,    -1,    -1,    -1,
     221,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   237,   238,    -1,   114,
     115,   116,   117,   244,    -1,   120,    13,    14,   249,    -1,
      -1,    -1,   127,   128,    -1,   256,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,   254,    -1,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   179,   180,   181,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    -1,   114,   115,   116,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   179,   180,   181,   114,   115,   116,   117,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     179,   180,   181,   114,   115,   116,   117,   254,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   179,   180,
     181,   114,   115,   116,   117,   254,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   179,   180,   181,   114,
     115,   116,   117,   254,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   179,   180,   181,   114,   115,   116,
     117,   254,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,   134,   135,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   179,   180,   181,   114,   115,   116,   117,   254,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,    -1,   131,   132,    -1,   134,   135,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     179,   180,   181,   114,   115,   116,   117,   254,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,
     131,   132,    -1,   134,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   179,   180,
     181,   114,   115,   116,   117,   254,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,   134,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   179,   180,   181,   114,
     115,   116,   117,   254,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    13,    14,    -1,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   179,   180,   181,   248,    -1,    -1,
      -1,   254,    44,    45,    46,    -1,    -1,   258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,
     221,    -1,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,     4,     5,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    -1,    98,    -1,     5,   101,    -1,
      -1,   104,    -1,   106,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,   117,    -1,    -1,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,    -1,
      -1,   134,    75,    -1,    77,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    91,    -1,
      -1,    94,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,    -1,   220,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   204,   205,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   203,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
     218,    -1,   220,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    13,    14,    -1,   114,
     115,   116,   117,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,    -1,   131,   132,    -1,   134,
     135,    -1,   137,    -1,    -1,    -1,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,   159,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,    -1,   179,   180,   181,   248,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   258,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   226,
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
     248,    -1,    -1,    -1,    -1,   253,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,   248,    -1,
     250,    -1,   252,   226,   227,   228,   229,   230,   231,   232,
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
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248,    -1,   250,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,    -1,   250,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,    -1,    -1,    -1,   248
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
     104,   106,   306,   101,   104,   106,   117,   307,   101,   104,
     249,   101,   159,   184,   200,   201,   253,   237,   238,   249,
     253,   352,   353,   352,   253,   253,   352,     4,    98,   102,
     108,   109,   111,   112,   131,   253,   249,   104,   106,   104,
     101,     4,    90,   195,   253,   372,     4,     6,    98,   101,
     104,   101,   104,   117,   308,     4,     4,     4,     5,   249,
     253,   355,   356,     4,   249,   249,   249,     4,   253,   359,
     372,     4,   249,   249,   249,     6,     6,   251,     5,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    60,    61,
      62,    63,    68,    69,    70,    75,    77,    91,    94,   203,
     204,   205,   214,   218,   220,   363,   372,   249,     4,   363,
       5,   253,     5,   253,    32,   238,   341,   372,   251,   253,
     249,   253,     6,   249,   253,     6,   257,     7,   134,   195,
     222,   223,   224,   225,   246,   247,   249,   251,   255,   281,
     282,   283,   306,   341,   362,   363,   372,     4,   310,   311,
     312,   253,     6,   341,   362,   363,   372,   362,   362,   341,
     362,   369,   370,   372,   341,   287,   291,   249,   351,     9,
     363,   249,   249,   249,   249,   372,   341,   341,   341,   249,
     341,   341,   341,   249,   341,   341,   341,   341,   341,   341,
     341,   362,   341,   341,   341,   341,   356,   249,   238,   341,
     357,   358,   253,   356,   355,   362,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   249,
     251,   283,   283,   283,   283,   283,   283,   249,   283,   283,
     249,   306,   307,   307,   283,   283,     5,   253,   253,   127,
     306,   306,   249,   283,   283,   249,   249,   249,   341,   253,
     341,   357,   341,   341,   254,   358,   348,   372,   187,     5,
     253,     8,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     248,     9,   249,   251,   255,   282,   283,   341,   358,   358,
     249,   249,   249,   355,   356,   356,   356,   305,   253,   249,
     355,   253,   253,   341,     4,   355,   253,   359,   253,   253,
     352,   352,   352,   341,   341,   237,   238,   253,   253,   352,
     237,   238,   249,   312,   352,   253,   249,   253,   249,   249,
     249,   249,   249,   249,   249,   358,   341,   356,   356,   356,
     249,     4,   251,   253,     6,   251,   312,     6,     6,   253,
     253,   253,   253,   356,   251,   251,   251,   341,     8,     6,
       6,   341,   341,   341,   255,   341,   253,   187,   341,   341,
     341,   341,   283,   283,   283,   249,   249,   249,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   249,   249,
     283,   249,   251,     6,     6,   253,     6,     8,   312,     6,
       8,   312,   283,   341,   239,   253,     9,   249,   251,   255,
     362,   358,   341,   312,   355,   355,   253,   363,   306,     7,
     341,   341,     4,   184,   185,   355,     6,   250,   252,   253,
     284,   253,     6,   253,     6,     9,   249,   251,   255,   372,
     254,   127,   132,   134,   135,   137,   304,   306,   341,     6,
     250,   258,     9,   249,   251,   255,   250,   258,   250,   258,
     258,   250,   258,     9,   249,   255,   258,   252,   258,   286,
     252,   286,    93,   350,   347,   372,   258,   341,   341,   341,
     341,   258,   250,   250,   250,   341,   250,   250,   250,   341,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   254,     7,   341,   239,   254,   258,   341,     6,     6,
     250,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   357,   341,
     341,   341,   341,   341,   341,   341,   357,   357,   372,   253,
     341,   341,   362,   341,   362,   355,   362,   362,   369,   253,
     253,   253,   341,   284,   372,     8,   341,   341,   356,   355,
     362,   362,   357,   348,   363,   348,   358,   250,   254,   255,
     283,    65,     8,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   253,   341,   357,
     341,   341,   341,   341,   341,   372,   341,   341,     4,   349,
     253,   284,   250,   254,   254,   341,   341,   341,     7,     7,
     334,   334,   249,   341,   341,     6,   358,   358,   253,   250,
       6,   312,   253,   312,   312,   258,   258,   258,   352,   352,
     311,   311,   258,   341,   254,   325,   258,   312,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   254,   250,     7,
     335,     6,     7,   341,     6,   341,   312,   341,   254,   358,
     358,   358,   341,     6,   341,   341,   341,   250,   254,   250,
     250,   250,   184,   258,   312,   253,     8,   250,   250,   252,
     369,   362,   369,   362,   362,   362,   362,   362,   362,   341,
     362,   362,   362,   362,   256,   365,   372,   363,   362,   362,
     362,   348,   372,   358,   254,   254,   254,   254,   341,   341,
     312,   372,   349,   252,   254,   250,   141,   159,   329,   250,
     254,   258,   341,     6,   253,   355,   250,   252,     7,   281,
     282,   255,     7,     6,   358,     7,   225,   281,   341,   266,
     372,   341,   341,   349,   251,   249,   127,   306,   307,   306,
     253,   254,     6,   232,   233,   263,   358,   372,   341,   341,
       4,   349,     6,   358,     6,   358,   341,     6,   362,   370,
     372,   250,   349,   341,     6,   372,     6,   362,   341,   250,
     251,   341,   258,   258,   258,   258,   363,     7,     7,     7,
     250,     7,     7,     7,   250,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   341,   250,   253,   341,   357,
     254,     6,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   258,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   258,   258,   258,   250,   252,   252,   358,
     258,   258,   284,   258,   284,   258,   258,   258,   250,   358,
     341,   341,   343,   284,   254,   254,   254,   258,   258,   284,
     284,   250,   255,   250,   255,   258,   283,   344,   254,     7,
     349,   284,   253,   254,     8,     8,   358,   255,   250,   252,
     282,   249,   251,   283,   358,     7,   253,   253,   250,   250,
     250,   341,   355,     4,   333,     6,   300,   341,   363,   254,
     250,   254,   254,   358,   255,   254,   312,   254,   254,   352,
     341,   341,   254,   254,   341,   352,   138,   138,   156,   164,
     165,   166,   170,   171,   326,   327,   352,   254,   322,   250,
     254,   250,   250,   250,   250,   250,   250,   250,   253,     7,
     341,     6,   341,   250,   252,   254,   252,   254,   254,   254,
     254,   252,   252,   258,     7,     7,     7,   255,   341,   254,
     341,   341,     7,   255,   284,   258,   284,   284,   250,   250,
     258,   284,   284,   258,   258,   284,   284,   284,   284,   341,
     284,     9,   364,   258,   250,   258,   284,   255,   258,   345,
     252,   254,   254,   255,   249,   251,   257,   187,     7,   159,
       6,   341,   254,   253,     6,   355,   254,   341,     6,     7,
     281,   282,   255,   281,   282,   363,   341,     6,     4,   253,
     360,   372,   254,    47,    47,   355,   254,     4,   174,   175,
     176,   177,   254,   269,   273,   276,   278,   279,   255,   250,
     252,   249,   341,   341,   249,   253,   249,   253,     8,   358,
     362,   250,   255,   250,   252,   249,   250,   250,   258,   255,
     249,   258,     7,   283,     4,   294,   295,   296,   284,   341,
     341,   341,   341,   284,   352,   355,   355,     7,   355,   355,
     355,     7,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,     6,     7,   358,   341,   341,   341,   341,   254,
     341,   341,   341,   355,   362,   362,   254,   254,   254,   258,
     293,   341,   341,   349,   349,   341,   341,   250,   355,   283,
     341,   341,   341,   254,   349,   282,   255,   282,   341,   341,
     284,   254,   355,   358,   358,     7,     7,     7,   138,   332,
       6,   250,   258,     7,     7,     7,   254,     4,   254,   258,
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
       4,     6,   281,   341,   355,   253,   253,     7,     6,     7,
     341,   341,   341,   253,   253,   253,   251,     6,   341,   355,
     341,     6,     6,   341,   352,   254,     5,   355,   253,   253,
     253,   253,   253,   253,   253,   355,   254,     6,   358,   253,
     341,   252,     6,     6,   183,   341,   341,   341,     6,     6,
       6,     6,     7,   284,   258,   258,   284,   258,   341,     4,
     199,   298,   299,   284,   250,   284,   345,   363,   249,   251,
     341,   253,   312,     6,   312,   258,     6,     6,     7,   281,
     282,   255,     7,     6,   359,   254,   258,   341,   281,   253,
     284,   367,   368,   369,   367,   249,   341,   341,   354,   355,
     253,   249,     4,     6,   250,     6,   250,   254,   254,   250,
     254,     6,     6,   362,   249,     4,   250,   258,   249,   254,
     258,   355,   363,     7,   283,   292,   341,   357,   296,     6,
       6,     6,     6,   352,     6,     6,     6,   138,   303,    98,
     117,   102,     6,     5,   253,   341,   341,   341,   341,   250,
     344,   341,   341,   341,   284,   282,   253,   253,     6,   301,
       6,   341,   355,     4,     6,   358,   358,   341,   341,   363,
     254,   250,   254,   258,   311,   311,   341,   341,   254,   258,
     250,   254,   258,     6,     6,   354,   352,   352,   352,   352,
     352,   238,   352,     6,   254,   341,     6,     6,   355,   254,
     258,     8,   254,   250,   253,   341,   363,   362,   341,   362,
     341,   363,   366,   368,   363,   258,   250,   258,   254,   341,
     329,   329,   355,   363,   341,     6,     4,   360,     6,   359,
     252,   355,   369,     6,   284,   284,   267,   341,   258,   258,
     254,   258,   268,   341,   341,     6,     6,     6,     6,   341,
     341,   250,     6,   341,   288,   290,   253,   368,   254,   258,
       7,     7,   142,     6,   253,   253,   253,     5,   354,   284,
     284,   258,   284,   250,   258,   250,   252,   358,   358,     6,
       6,   253,   254,   254,   253,     6,     6,   253,   341,   254,
     254,   254,   252,     6,   355,     7,   253,   341,   254,   258,
     258,   258,   258,   258,   258,     6,   254,   182,   341,   341,
     358,     6,     6,   250,   284,   284,   299,   363,   254,   254,
     254,   254,     6,     6,     7,     6,   255,     6,   254,     6,
       6,   250,   258,   341,   341,   253,   355,   254,   258,   250,
     250,   258,   254,   293,   297,   355,   284,   341,   363,   372,
     358,   358,   341,     6,   254,   341,   344,   341,   254,   254,
     354,   143,   144,   149,   336,   143,   144,   336,   358,   311,
     254,   258,     6,   254,   355,   312,   254,     6,   358,   352,
     352,   352,   352,   352,   341,   254,   254,   254,   250,     6,
     253,     6,   359,   185,   271,   341,   258,   258,   354,     6,
     341,   341,     6,   254,   254,   289,     7,   249,   254,   254,
     254,   253,   258,   250,   258,   253,   254,   253,   352,   355,
       6,   253,   352,     6,   254,   254,   341,     6,   138,   254,
     323,   253,   254,   258,   258,   258,   258,   258,     6,     6,
       6,   312,     6,   253,   341,   341,   254,   258,   293,   363,
     250,   341,   341,   341,   358,     6,   352,     6,   352,     6,
       6,   254,   341,   326,   312,     6,   358,   358,   358,   358,
     352,   358,   329,   268,   250,   258,     6,   253,   341,   254,
     258,   258,   258,   254,   258,   258,     6,   254,   254,   324,
     254,   254,   254,   254,   258,   254,   254,   254,   274,   341,
     354,   254,   341,   341,   341,   352,   352,   326,     6,     6,
       6,     6,   358,     6,     6,     6,   253,   250,   254,     6,
     254,   284,   258,   258,   258,   254,   254,   272,   362,   277,
     253,     6,   341,   341,   341,     6,   254,   258,   253,   354,
     254,   254,   254,     6,   362,   275,   362,   254,     6,     6,
     254,   258,     6,     6,   362
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

  case 165:
#line 1717 "Gmsh.y"
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

  case 166:
#line 1761 "Gmsh.y"
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

  case 167:
#line 1777 "Gmsh.y"
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

  case 168:
#line 1794 "Gmsh.y"
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

  case 169:
#line 1825 "Gmsh.y"
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

  case 170:
#line 1841 "Gmsh.y"
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

  case 171:
#line 1858 "Gmsh.y"
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

  case 172:
#line 1874 "Gmsh.y"
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

  case 173:
#line 1924 "Gmsh.y"
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

  case 174:
#line 1942 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 175:
#line 1948 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 176:
#line 1954 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 177:
#line 1961 "Gmsh.y"
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

  case 178:
#line 1992 "Gmsh.y"
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

  case 179:
#line 2007 "Gmsh.y"
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

  case 180:
#line 2029 "Gmsh.y"
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

  case 181:
#line 2052 "Gmsh.y"
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

  case 182:
#line 2075 "Gmsh.y"
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

  case 183:
#line 2098 "Gmsh.y"
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

  case 184:
#line 2122 "Gmsh.y"
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

  case 185:
#line 2146 "Gmsh.y"
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

  case 186:
#line 2170 "Gmsh.y"
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

  case 187:
#line 2196 "Gmsh.y"
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

  case 188:
#line 2213 "Gmsh.y"
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

  case 189:
#line 2229 "Gmsh.y"
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

  case 190:
#line 2247 "Gmsh.y"
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

  case 191:
#line 2265 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (8)].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 192:
#line 2273 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (12)].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 193:
#line 2280 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 194:
#line 2284 "Gmsh.y"
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

  case 195:
#line 2310 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 196:
#line 2312 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 197:
#line 2314 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 198:
#line 2316 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 199:
#line 2318 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 200:
#line 2326 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 201:
#line 2328 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 202:
#line 2330 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 203:
#line 2332 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 204:
#line 2340 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2342 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2344 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 207:
#line 2352 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 208:
#line 2354 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 209:
#line 2356 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 210:
#line 2358 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 211:
#line 2368 "Gmsh.y"
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

  case 212:
#line 2384 "Gmsh.y"
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

  case 213:
#line 2400 "Gmsh.y"
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

  case 214:
#line 2416 "Gmsh.y"
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

  case 215:
#line 2432 "Gmsh.y"
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

  case 216:
#line 2448 "Gmsh.y"
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

  case 217:
#line 2465 "Gmsh.y"
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

  case 218:
#line 2502 "Gmsh.y"
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

  case 219:
#line 2524 "Gmsh.y"
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

  case 220:
#line 2547 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 221:
#line 2548 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 222:
#line 2553 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 223:
#line 2557 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 224:
#line 2561 "Gmsh.y"
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

  case 225:
#line 2578 "Gmsh.y"
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

  case 226:
#line 2598 "Gmsh.y"
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

  case 227:
#line 2618 "Gmsh.y"
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

  case 228:
#line 2637 "Gmsh.y"
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

  case 229:
#line 2664 "Gmsh.y"
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

  case 230:
#line 2683 "Gmsh.y"
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

  case 231:
#line 2705 "Gmsh.y"
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

  case 232:
#line 2720 "Gmsh.y"
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

  case 233:
#line 2735 "Gmsh.y"
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

  case 234:
#line 2754 "Gmsh.y"
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

  case 235:
#line 2805 "Gmsh.y"
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

  case 236:
#line 2826 "Gmsh.y"
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

  case 237:
#line 2848 "Gmsh.y"
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

  case 238:
#line 2870 "Gmsh.y"
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

  case 239:
#line 2975 "Gmsh.y"
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

  case 240:
#line 2991 "Gmsh.y"
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

  case 241:
#line 3026 "Gmsh.y"
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

  case 242:
#line 3048 "Gmsh.y"
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

  case 243:
#line 3070 "Gmsh.y"
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

  case 244:
#line 3082 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 245:
#line 3088 "Gmsh.y"
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

  case 246:
#line 3103 "Gmsh.y"
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

  case 247:
#line 3131 "Gmsh.y"
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

  case 248:
#line 3143 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 249:
#line 3152 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 250:
#line 3159 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 251:
#line 3171 "Gmsh.y"
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

  case 252:
#line 3191 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 253:
#line 3195 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 254:
#line 3200 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 255:
#line 3204 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 256:
#line 3209 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 257:
#line 3216 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 258:
#line 3223 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 259:
#line 3230 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 260:
#line 3242 "Gmsh.y"
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

  case 261:
#line 3315 "Gmsh.y"
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

  case 262:
#line 3333 "Gmsh.y"
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

  case 263:
#line 3358 "Gmsh.y"
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

  case 264:
#line 3373 "Gmsh.y"
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

  case 265:
#line 3406 "Gmsh.y"
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

  case 266:
#line 3418 "Gmsh.y"
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

  case 267:
#line 3442 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 268:
#line 3446 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 269:
#line 3451 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 270:
#line 3458 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 271:
#line 3463 "Gmsh.y"
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

  case 272:
#line 3473 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 273:
#line 3478 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 274:
#line 3484 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 275:
#line 3492 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 276:
#line 3496 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d), M_PI);
    ;}
    break;

  case 277:
#line 3500 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (11)].d), (yyvsp[(5) - (11)].d), (yyvsp[(7) - (11)].d), (yyvsp[(9) - (11)].d));
    ;}
    break;

  case 278:
#line 3504 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 279:
#line 3508 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 280:
#line 3512 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 281:
#line 3516 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 282:
#line 3526 "Gmsh.y"
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

  case 283:
#line 3589 "Gmsh.y"
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

  case 284:
#line 3605 "Gmsh.y"
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

  case 285:
#line 3622 "Gmsh.y"
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

  case 286:
#line 3639 "Gmsh.y"
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

  case 287:
#line 3661 "Gmsh.y"
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

  case 288:
#line 3683 "Gmsh.y"
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

  case 289:
#line 3718 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 290:
#line 3726 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 291:
#line 3734 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 292:
#line 3740 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 293:
#line 3747 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 294:
#line 3754 "Gmsh.y"
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

  case 295:
#line 3774 "Gmsh.y"
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

  case 296:
#line 3800 "Gmsh.y"
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

  case 297:
#line 3812 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 298:
#line 3823 "Gmsh.y"
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

  case 299:
#line 3841 "Gmsh.y"
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

  case 300:
#line 3859 "Gmsh.y"
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

  case 301:
#line 3877 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 302:
#line 3883 "Gmsh.y"
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

  case 303:
#line 3901 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 304:
#line 3907 "Gmsh.y"
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

  case 305:
#line 3927 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 306:
#line 3933 "Gmsh.y"
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

  case 307:
#line 3951 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 308:
#line 3957 "Gmsh.y"
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

  case 309:
#line 3974 "Gmsh.y"
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

  case 310:
#line 3990 "Gmsh.y"
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

  case 311:
#line 4007 "Gmsh.y"
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

  case 312:
#line 4025 "Gmsh.y"
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

  case 313:
#line 4048 "Gmsh.y"
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

  case 314:
#line 4075 "Gmsh.y"
    {
    ;}
    break;

  case 315:
#line 4078 "Gmsh.y"
    {
    ;}
    break;

  case 316:
#line 4084 "Gmsh.y"
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

  case 317:
#line 4096 "Gmsh.y"
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

  case 318:
#line 4116 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 319:
#line 4120 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 320:
#line 4124 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 321:
#line 4128 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 322:
#line 4132 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 323:
#line 4136 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 324:
#line 4140 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 325:
#line 4144 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 326:
#line 4153 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 327:
#line 4165 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 328:
#line 4166 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 329:
#line 4167 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 330:
#line 4168 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 331:
#line 4169 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 332:
#line 4173 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 333:
#line 4174 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 334:
#line 4175 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 335:
#line 4176 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 336:
#line 4177 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 337:
#line 4182 "Gmsh.y"
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

  case 338:
#line 4205 "Gmsh.y"
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

  case 339:
#line 4225 "Gmsh.y"
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

  case 340:
#line 4246 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 341:
#line 4250 "Gmsh.y"
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

  case 342:
#line 4265 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 343:
#line 4269 "Gmsh.y"
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

  case 344:
#line 4285 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 345:
#line 4289 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 346:
#line 4294 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 347:
#line 4298 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 348:
#line 4304 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 349:
#line 4308 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 350:
#line 4315 "Gmsh.y"
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

  case 351:
#line 4337 "Gmsh.y"
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

  case 352:
#line 4378 "Gmsh.y"
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

  case 353:
#line 4422 "Gmsh.y"
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

  case 354:
#line 4461 "Gmsh.y"
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

  case 355:
#line 4486 "Gmsh.y"
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

  case 356:
#line 4498 "Gmsh.y"
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

  case 357:
#line 4510 "Gmsh.y"
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

  case 358:
#line 4522 "Gmsh.y"
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

  case 359:
#line 4534 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 360:
#line 4543 "Gmsh.y"
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

  case 361:
#line 4573 "Gmsh.y"
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

  case 362:
#line 4599 "Gmsh.y"
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

  case 363:
#line 4626 "Gmsh.y"
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

  case 364:
#line 4658 "Gmsh.y"
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

  case 365:
#line 4685 "Gmsh.y"
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

  case 366:
#line 4711 "Gmsh.y"
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

  case 367:
#line 4737 "Gmsh.y"
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

  case 368:
#line 4763 "Gmsh.y"
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

  case 369:
#line 4789 "Gmsh.y"
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

  case 370:
#line 4810 "Gmsh.y"
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

  case 371:
#line 4821 "Gmsh.y"
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

  case 372:
#line 4869 "Gmsh.y"
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

  case 373:
#line 4923 "Gmsh.y"
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

  case 374:
#line 4938 "Gmsh.y"
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

  case 375:
#line 4950 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 376:
#line 4961 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 377:
#line 4968 "Gmsh.y"
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

  case 378:
#line 4983 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 379:
#line 4996 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 380:
#line 4997 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 381:
#line 4998 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 382:
#line 5003 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 383:
#line 5009 "Gmsh.y"
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

  case 384:
#line 5021 "Gmsh.y"
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

  case 385:
#line 5039 "Gmsh.y"
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

  case 386:
#line 5066 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 387:
#line 5067 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 388:
#line 5068 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 389:
#line 5069 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 390:
#line 5070 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 391:
#line 5071 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 392:
#line 5072 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 393:
#line 5073 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 394:
#line 5075 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 395:
#line 5081 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 396:
#line 5082 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 397:
#line 5083 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 398:
#line 5084 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 399:
#line 5085 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 400:
#line 5086 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 401:
#line 5087 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 402:
#line 5088 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 403:
#line 5089 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 404:
#line 5090 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 405:
#line 5091 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 406:
#line 5092 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 407:
#line 5093 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 408:
#line 5094 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 409:
#line 5095 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 410:
#line 5096 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 411:
#line 5097 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 412:
#line 5098 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 413:
#line 5099 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 414:
#line 5100 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 415:
#line 5101 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 416:
#line 5102 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 417:
#line 5103 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5104 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 419:
#line 5105 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5106 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 421:
#line 5107 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5108 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 423:
#line 5109 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 424:
#line 5110 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5111 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 426:
#line 5112 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 427:
#line 5113 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 428:
#line 5114 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 429:
#line 5115 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 430:
#line 5116 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 431:
#line 5117 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 432:
#line 5118 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 433:
#line 5127 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 434:
#line 5128 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 435:
#line 5129 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 436:
#line 5130 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 437:
#line 5131 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 438:
#line 5132 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 439:
#line 5133 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 440:
#line 5134 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 441:
#line 5135 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 442:
#line 5136 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 443:
#line 5137 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 444:
#line 5142 "Gmsh.y"
    { init_options(); ;}
    break;

  case 445:
#line 5144 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 446:
#line 5150 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 447:
#line 5152 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 448:
#line 5157 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 449:
#line 5162 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 450:
#line 5167 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 451:
#line 5172 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 452:
#line 5176 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 453:
#line 5180 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 454:
#line 5184 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 455:
#line 5188 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 456:
#line 5192 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 457:
#line 5196 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 458:
#line 5200 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 459:
#line 5206 "Gmsh.y"
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

  case 460:
#line 5221 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 461:
#line 5225 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 462:
#line 5231 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 463:
#line 5236 "Gmsh.y"
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

  case 464:
#line 5255 "Gmsh.y"
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

  case 465:
#line 5275 "Gmsh.y"
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

  case 466:
#line 5306 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 467:
#line 5310 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 468:
#line 5314 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 469:
#line 5318 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 470:
#line 5322 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 471:
#line 5326 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 472:
#line 5330 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 473:
#line 5335 "Gmsh.y"
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

  case 474:
#line 5345 "Gmsh.y"
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

  case 475:
#line 5355 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 476:
#line 5360 "Gmsh.y"
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

  case 477:
#line 5371 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 478:
#line 5380 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 479:
#line 5385 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 480:
#line 5390 "Gmsh.y"
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

  case 481:
#line 5417 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 482:
#line 5419 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 483:
#line 5424 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 484:
#line 5426 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 485:
#line 5431 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 486:
#line 5438 "Gmsh.y"
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

  case 487:
#line 5454 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 488:
#line 5456 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 489:
#line 5461 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 490:
#line 5470 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 491:
#line 5472 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 492:
#line 5477 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 493:
#line 5479 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 494:
#line 5484 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 495:
#line 5488 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 496:
#line 5492 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 497:
#line 5496 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 498:
#line 5500 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 499:
#line 5507 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 500:
#line 5511 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 501:
#line 5515 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 502:
#line 5519 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 503:
#line 5526 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 504:
#line 5531 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 505:
#line 5538 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 506:
#line 5543 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 507:
#line 5547 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 508:
#line 5552 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 509:
#line 5556 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 510:
#line 5564 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 511:
#line 5575 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 512:
#line 5579 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 513:
#line 5583 "Gmsh.y"
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

  case 514:
#line 5597 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 515:
#line 5605 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 516:
#line 5613 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 517:
#line 5620 "Gmsh.y"
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

  case 518:
#line 5630 "Gmsh.y"
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

  case 519:
#line 5653 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 520:
#line 5658 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 521:
#line 5664 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 522:
#line 5669 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 523:
#line 5675 "Gmsh.y"
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

  case 524:
#line 5686 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 525:
#line 5693 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 526:
#line 5698 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 527:
#line 5704 "Gmsh.y"
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

  case 528:
#line 5716 "Gmsh.y"
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

  case 529:
#line 5730 "Gmsh.y"
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

  case 530:
#line 5740 "Gmsh.y"
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

  case 531:
#line 5750 "Gmsh.y"
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
#line 5760 "Gmsh.y"
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

  case 533:
#line 5772 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 534:
#line 5776 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 535:
#line 5781 "Gmsh.y"
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

  case 536:
#line 5793 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 537:
#line 5797 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 538:
#line 5801 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 539:
#line 5805 "Gmsh.y"
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

  case 540:
#line 5823 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 541:
#line 5831 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 542:
#line 5839 "Gmsh.y"
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

  case 543:
#line 5868 "Gmsh.y"
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

  case 544:
#line 5878 "Gmsh.y"
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

  case 545:
#line 5894 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 546:
#line 5905 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 547:
#line 5910 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 548:
#line 5914 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 549:
#line 5918 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 550:
#line 5930 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 551:
#line 5934 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 552:
#line 5946 "Gmsh.y"
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

  case 553:
#line 5963 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 554:
#line 5973 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 555:
#line 5977 "Gmsh.y"
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

  case 556:
#line 5992 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 557:
#line 5997 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 558:
#line 6004 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 559:
#line 6008 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 560:
#line 6013 "Gmsh.y"
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

  case 561:
#line 6027 "Gmsh.y"
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

  case 562:
#line 6043 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 563:
#line 6047 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 564:
#line 6051 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 565:
#line 6055 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 566:
#line 6059 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 567:
#line 6067 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 568:
#line 6073 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 569:
#line 6082 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 570:
#line 6086 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 571:
#line 6090 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 572:
#line 6098 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 573:
#line 6104 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 574:
#line 6110 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 575:
#line 6114 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 576:
#line 6122 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 577:
#line 6130 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 578:
#line 6137 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 579:
#line 6146 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 580:
#line 6150 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 581:
#line 6154 "Gmsh.y"
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

  case 582:
#line 6169 "Gmsh.y"
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

  case 583:
#line 6183 "Gmsh.y"
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

  case 584:
#line 6197 "Gmsh.y"
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

  case 585:
#line 6209 "Gmsh.y"
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

  case 586:
#line 6225 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 587:
#line 6234 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 588:
#line 6243 "Gmsh.y"
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

  case 589:
#line 6253 "Gmsh.y"
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

  case 590:
#line 6264 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 591:
#line 6272 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 592:
#line 6280 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 593:
#line 6284 "Gmsh.y"
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

  case 594:
#line 6303 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 595:
#line 6310 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 596:
#line 6316 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 597:
#line 6323 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 598:
#line 6330 "Gmsh.y"
    { init_options(); ;}
    break;

  case 599:
#line 6332 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 600:
#line 6340 "Gmsh.y"
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

  case 601:
#line 6364 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 602:
#line 6366 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 603:
#line 6372 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 604:
#line 6377 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 605:
#line 6379 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 606:
#line 6384 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 607:
#line 6389 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 608:
#line 6394 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 609:
#line 6396 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 610:
#line 6400 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 611:
#line 6412 "Gmsh.y"
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

  case 612:
#line 6426 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 613:
#line 6430 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 614:
#line 6437 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 615:
#line 6445 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 616:
#line 6453 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 617:
#line 6464 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 618:
#line 6466 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 619:
#line 6469 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14442 "Gmsh.tab.cpp"
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


#line 6472 "Gmsh.y"


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

