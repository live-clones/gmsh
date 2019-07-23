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
     tStr = 301,
     tSprintf = 302,
     tStrCat = 303,
     tStrPrefix = 304,
     tStrRelative = 305,
     tStrReplace = 306,
     tAbsolutePath = 307,
     tDirName = 308,
     tStrSub = 309,
     tStrLen = 310,
     tFind = 311,
     tStrFind = 312,
     tStrCmp = 313,
     tStrChoice = 314,
     tUpperCase = 315,
     tLowerCase = 316,
     tLowerCaseIn = 317,
     tTextAttributes = 318,
     tBoundingBox = 319,
     tDraw = 320,
     tSetChanged = 321,
     tToday = 322,
     tFixRelativePath = 323,
     tCurrentDirectory = 324,
     tSyncModel = 325,
     tNewModel = 326,
     tMass = 327,
     tCenterOfMass = 328,
     tOnelabAction = 329,
     tOnelabRun = 330,
     tCodeName = 331,
     tCpu = 332,
     tMemory = 333,
     tTotalMemory = 334,
     tCreateTopology = 335,
     tCreateGeometry = 336,
     tClassifySurfaces = 337,
     tRenumberMeshNodes = 338,
     tRenumberMeshElements = 339,
     tDistanceFunction = 340,
     tDefineConstant = 341,
     tUndefineConstant = 342,
     tDefineNumber = 343,
     tDefineStruct = 344,
     tNameStruct = 345,
     tDimNameSpace = 346,
     tAppend = 347,
     tDefineString = 348,
     tSetNumber = 349,
     tSetTag = 350,
     tSetString = 351,
     tPoint = 352,
     tCircle = 353,
     tEllipse = 354,
     tCurve = 355,
     tSphere = 356,
     tPolarSphere = 357,
     tSurface = 358,
     tSpline = 359,
     tVolume = 360,
     tBox = 361,
     tCylinder = 362,
     tCone = 363,
     tTorus = 364,
     tEllipsoid = 365,
     tQuadric = 366,
     tShapeFromFile = 367,
     tRectangle = 368,
     tDisk = 369,
     tWire = 370,
     tGeoEntity = 371,
     tCharacteristic = 372,
     tLength = 373,
     tParametric = 374,
     tElliptic = 375,
     tRefineMesh = 376,
     tAdaptMesh = 377,
     tRelocateMesh = 378,
     tReorientMesh = 379,
     tSetFactory = 380,
     tThruSections = 381,
     tWedge = 382,
     tFillet = 383,
     tChamfer = 384,
     tPlane = 385,
     tRuled = 386,
     tTransfinite = 387,
     tPhysical = 388,
     tCompound = 389,
     tPeriodic = 390,
     tParent = 391,
     tUsing = 392,
     tPlugin = 393,
     tDegenerated = 394,
     tRecursive = 395,
     tSewing = 396,
     tRotate = 397,
     tTranslate = 398,
     tSymmetry = 399,
     tDilate = 400,
     tExtrude = 401,
     tLevelset = 402,
     tAffine = 403,
     tBooleanUnion = 404,
     tBooleanIntersection = 405,
     tBooleanDifference = 406,
     tBooleanSection = 407,
     tBooleanFragments = 408,
     tThickSolid = 409,
     tRecombine = 410,
     tSmoother = 411,
     tSplit = 412,
     tDelete = 413,
     tCoherence = 414,
     tIntersect = 415,
     tMeshAlgorithm = 416,
     tReverseMesh = 417,
     tLayers = 418,
     tScaleLast = 419,
     tHole = 420,
     tAlias = 421,
     tAliasWithOptions = 422,
     tCopyOptions = 423,
     tQuadTriAddVerts = 424,
     tQuadTriNoNewVerts = 425,
     tRecombLaterals = 426,
     tTransfQuadTri = 427,
     tText2D = 428,
     tText3D = 429,
     tInterpolationScheme = 430,
     tTime = 431,
     tCombine = 432,
     tBSpline = 433,
     tBezier = 434,
     tNurbs = 435,
     tNurbsOrder = 436,
     tNurbsKnots = 437,
     tColor = 438,
     tColorTable = 439,
     tFor = 440,
     tIn = 441,
     tEndFor = 442,
     tIf = 443,
     tElseIf = 444,
     tElse = 445,
     tEndIf = 446,
     tExit = 447,
     tAbort = 448,
     tField = 449,
     tReturn = 450,
     tCall = 451,
     tSlide = 452,
     tMacro = 453,
     tShow = 454,
     tHide = 455,
     tGetValue = 456,
     tGetStringValue = 457,
     tGetEnv = 458,
     tGetString = 459,
     tGetNumber = 460,
     tUnique = 461,
     tHomology = 462,
     tCohomology = 463,
     tBetti = 464,
     tExists = 465,
     tFileExists = 466,
     tGetForced = 467,
     tGetForcedStr = 468,
     tGMSH_MAJOR_VERSION = 469,
     tGMSH_MINOR_VERSION = 470,
     tGMSH_PATCH_VERSION = 471,
     tGmshExecutableName = 472,
     tSetPartition = 473,
     tNameToString = 474,
     tStringToName = 475,
     tAFFECTDIVIDE = 476,
     tAFFECTTIMES = 477,
     tAFFECTMINUS = 478,
     tAFFECTPLUS = 479,
     tOR = 480,
     tAND = 481,
     tNOTEQUAL = 482,
     tEQUAL = 483,
     tGREATERGREATER = 484,
     tLESSLESS = 485,
     tGREATEROREQUAL = 486,
     tLESSOREQUAL = 487,
     UNARYPREC = 488,
     tMINUSMINUS = 489,
     tPLUSPLUS = 490
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
#define tStr 301
#define tSprintf 302
#define tStrCat 303
#define tStrPrefix 304
#define tStrRelative 305
#define tStrReplace 306
#define tAbsolutePath 307
#define tDirName 308
#define tStrSub 309
#define tStrLen 310
#define tFind 311
#define tStrFind 312
#define tStrCmp 313
#define tStrChoice 314
#define tUpperCase 315
#define tLowerCase 316
#define tLowerCaseIn 317
#define tTextAttributes 318
#define tBoundingBox 319
#define tDraw 320
#define tSetChanged 321
#define tToday 322
#define tFixRelativePath 323
#define tCurrentDirectory 324
#define tSyncModel 325
#define tNewModel 326
#define tMass 327
#define tCenterOfMass 328
#define tOnelabAction 329
#define tOnelabRun 330
#define tCodeName 331
#define tCpu 332
#define tMemory 333
#define tTotalMemory 334
#define tCreateTopology 335
#define tCreateGeometry 336
#define tClassifySurfaces 337
#define tRenumberMeshNodes 338
#define tRenumberMeshElements 339
#define tDistanceFunction 340
#define tDefineConstant 341
#define tUndefineConstant 342
#define tDefineNumber 343
#define tDefineStruct 344
#define tNameStruct 345
#define tDimNameSpace 346
#define tAppend 347
#define tDefineString 348
#define tSetNumber 349
#define tSetTag 350
#define tSetString 351
#define tPoint 352
#define tCircle 353
#define tEllipse 354
#define tCurve 355
#define tSphere 356
#define tPolarSphere 357
#define tSurface 358
#define tSpline 359
#define tVolume 360
#define tBox 361
#define tCylinder 362
#define tCone 363
#define tTorus 364
#define tEllipsoid 365
#define tQuadric 366
#define tShapeFromFile 367
#define tRectangle 368
#define tDisk 369
#define tWire 370
#define tGeoEntity 371
#define tCharacteristic 372
#define tLength 373
#define tParametric 374
#define tElliptic 375
#define tRefineMesh 376
#define tAdaptMesh 377
#define tRelocateMesh 378
#define tReorientMesh 379
#define tSetFactory 380
#define tThruSections 381
#define tWedge 382
#define tFillet 383
#define tChamfer 384
#define tPlane 385
#define tRuled 386
#define tTransfinite 387
#define tPhysical 388
#define tCompound 389
#define tPeriodic 390
#define tParent 391
#define tUsing 392
#define tPlugin 393
#define tDegenerated 394
#define tRecursive 395
#define tSewing 396
#define tRotate 397
#define tTranslate 398
#define tSymmetry 399
#define tDilate 400
#define tExtrude 401
#define tLevelset 402
#define tAffine 403
#define tBooleanUnion 404
#define tBooleanIntersection 405
#define tBooleanDifference 406
#define tBooleanSection 407
#define tBooleanFragments 408
#define tThickSolid 409
#define tRecombine 410
#define tSmoother 411
#define tSplit 412
#define tDelete 413
#define tCoherence 414
#define tIntersect 415
#define tMeshAlgorithm 416
#define tReverseMesh 417
#define tLayers 418
#define tScaleLast 419
#define tHole 420
#define tAlias 421
#define tAliasWithOptions 422
#define tCopyOptions 423
#define tQuadTriAddVerts 424
#define tQuadTriNoNewVerts 425
#define tRecombLaterals 426
#define tTransfQuadTri 427
#define tText2D 428
#define tText3D 429
#define tInterpolationScheme 430
#define tTime 431
#define tCombine 432
#define tBSpline 433
#define tBezier 434
#define tNurbs 435
#define tNurbsOrder 436
#define tNurbsKnots 437
#define tColor 438
#define tColorTable 439
#define tFor 440
#define tIn 441
#define tEndFor 442
#define tIf 443
#define tElseIf 444
#define tElse 445
#define tEndIf 446
#define tExit 447
#define tAbort 448
#define tField 449
#define tReturn 450
#define tCall 451
#define tSlide 452
#define tMacro 453
#define tShow 454
#define tHide 455
#define tGetValue 456
#define tGetStringValue 457
#define tGetEnv 458
#define tGetString 459
#define tGetNumber 460
#define tUnique 461
#define tHomology 462
#define tCohomology 463
#define tBetti 464
#define tExists 465
#define tFileExists 466
#define tGetForced 467
#define tGetForcedStr 468
#define tGMSH_MAJOR_VERSION 469
#define tGMSH_MINOR_VERSION 470
#define tGMSH_PATCH_VERSION 471
#define tGmshExecutableName 472
#define tSetPartition 473
#define tNameToString 474
#define tStringToName 475
#define tAFFECTDIVIDE 476
#define tAFFECTTIMES 477
#define tAFFECTMINUS 478
#define tAFFECTPLUS 479
#define tOR 480
#define tAND 481
#define tNOTEQUAL 482
#define tEQUAL 483
#define tGREATERGREATER 484
#define tLESSLESS 485
#define tGREATEROREQUAL 486
#define tLESSOREQUAL 487
#define UNARYPREC 488
#define tMINUSMINUS 489
#define tPLUSPLUS 490




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
#line 750 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 763 "Gmsh.tab.cpp"

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
#define YYLAST   17160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  258
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  114
/* YYNRULES -- Number of rules.  */
#define YYNRULES  616
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   490

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,     2,   255,     2,   240,   242,     2,
     248,   249,   238,   236,   257,   237,   254,   239,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     230,     2,   231,   225,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   250,     2,   251,   247,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   252,   241,   253,   256,     2,     2,     2,
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
     226,   227,   228,   229,   232,   233,   234,   235,   244,   245,
     246
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    12,    14,    16,    18,
      24,    26,    28,    30,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    54,    56,    58,    60,    66,
      72,    80,    88,    96,   106,   113,   120,   127,   136,   137,
     140,   143,   146,   149,   152,   154,   158,   160,   164,   165,
     166,   177,   179,   183,   184,   198,   200,   204,   205,   221,
     230,   245,   246,   253,   255,   257,   259,   261,   263,   265,
     267,   269,   271,   273,   275,   281,   287,   290,   298,   306,
     311,   315,   322,   332,   340,   347,   355,   362,   367,   376,
     386,   396,   403,   413,   420,   430,   436,   445,   454,   466,
     473,   483,   489,   497,   505,   513,   523,   533,   545,   553,
     563,   573,   574,   576,   577,   581,   587,   588,   598,   599,
     611,   617,   618,   628,   629,   633,   637,   643,   649,   650,
     653,   654,   656,   658,   662,   665,   667,   672,   675,   678,
     679,   682,   684,   688,   691,   694,   697,   700,   703,   705,
     707,   711,   712,   718,   724,   730,   731,   734,   735,   738,
     746,   754,   762,   771,   780,   788,   796,   808,   816,   825,
     834,   843,   853,   857,   862,   873,   881,   889,   897,   905,
     913,   921,   929,   937,   945,   953,   963,   971,   979,   988,
     997,  1010,  1011,  1021,  1023,  1025,  1027,  1029,  1034,  1036,
    1038,  1040,  1045,  1047,  1049,  1054,  1056,  1058,  1060,  1065,
    1071,  1083,  1089,  1099,  1109,  1117,  1122,  1132,  1142,  1144,
    1146,  1147,  1150,  1157,  1165,  1173,  1180,  1188,  1197,  1208,
    1223,  1240,  1253,  1268,  1283,  1298,  1313,  1322,  1331,  1338,
    1343,  1349,  1355,  1362,  1369,  1373,  1378,  1382,  1388,  1395,
    1401,  1406,  1410,  1415,  1419,  1424,  1430,  1435,  1441,  1445,
    1451,  1459,  1467,  1471,  1479,  1483,  1486,  1489,  1492,  1495,
    1498,  1514,  1517,  1520,  1523,  1533,  1536,  1539,  1542,  1545,
    1562,  1574,  1581,  1590,  1599,  1610,  1612,  1615,  1618,  1620,
    1624,  1628,  1633,  1638,  1640,  1642,  1648,  1660,  1674,  1675,
    1683,  1684,  1698,  1699,  1715,  1716,  1723,  1733,  1736,  1740,
    1751,  1765,  1767,  1770,  1776,  1784,  1787,  1790,  1794,  1797,
    1801,  1804,  1808,  1818,  1825,  1827,  1829,  1831,  1833,  1835,
    1836,  1839,  1843,  1847,  1852,  1862,  1867,  1882,  1883,  1887,
    1888,  1890,  1891,  1894,  1895,  1898,  1899,  1902,  1909,  1917,
    1924,  1930,  1934,  1943,  1952,  1961,  1970,  1979,  1985,  1990,
    1997,  2009,  2021,  2040,  2059,  2072,  2085,  2098,  2109,  2114,
    2119,  2124,  2129,  2134,  2137,  2141,  2148,  2150,  2152,  2154,
    2157,  2163,  2171,  2182,  2184,  2188,  2191,  2194,  2197,  2201,
    2205,  2209,  2213,  2217,  2221,  2225,  2229,  2233,  2237,  2241,
    2245,  2249,  2253,  2257,  2261,  2265,  2269,  2275,  2280,  2285,
    2290,  2295,  2300,  2305,  2310,  2315,  2320,  2325,  2332,  2337,
    2342,  2347,  2352,  2357,  2362,  2367,  2372,  2379,  2386,  2393,
    2398,  2400,  2402,  2404,  2406,  2408,  2410,  2412,  2414,  2416,
    2418,  2420,  2421,  2428,  2430,  2435,  2442,  2444,  2449,  2454,
    2459,  2466,  2472,  2480,  2489,  2500,  2505,  2510,  2517,  2522,
    2526,  2529,  2535,  2541,  2545,  2551,  2558,  2567,  2574,  2583,
    2590,  2595,  2603,  2610,  2617,  2624,  2629,  2636,  2641,  2642,
    2645,  2646,  2649,  2650,  2658,  2660,  2664,  2666,  2668,  2671,
    2672,  2676,  2678,  2681,  2684,  2688,  2692,  2704,  2714,  2722,
    2730,  2732,  2736,  2738,  2740,  2743,  2747,  2752,  2758,  2760,
    2764,  2766,  2769,  2773,  2777,  2783,  2788,  2793,  2796,  2801,
    2804,  2808,  2812,  2829,  2835,  2841,  2847,  2849,  2851,  2853,
    2857,  2863,  2871,  2876,  2881,  2886,  2893,  2900,  2909,  2918,
    2923,  2938,  2943,  2948,  2950,  2952,  2956,  2960,  2970,  2978,
    2980,  2986,  2990,  2997,  2999,  3003,  3005,  3007,  3012,  3017,
    3021,  3027,  3034,  3043,  3050,  3055,  3061,  3063,  3068,  3070,
    3072,  3074,  3076,  3081,  3088,  3093,  3100,  3106,  3114,  3119,
    3124,  3129,  3138,  3143,  3148,  3153,  3158,  3167,  3176,  3183,
    3188,  3195,  3200,  3202,  3207,  3212,  3213,  3220,  3225,  3228,
    3233,  3238,  3240,  3242,  3246,  3248,  3250,  3254,  3258,  3262,
    3268,  3276,  3282,  3288,  3297,  3299,  3301
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     259,     0,    -1,   260,    -1,     1,     6,    -1,    -1,   260,
     261,    -1,   263,    -1,   264,    -1,   284,    -1,   125,   248,
     361,   249,     6,    -1,   303,    -1,   309,    -1,   313,    -1,
     314,    -1,   315,    -1,   316,    -1,   320,    -1,   329,    -1,
     330,    -1,   336,    -1,   337,    -1,   319,    -1,   318,    -1,
     317,    -1,   312,    -1,   339,    -1,   231,    -1,   232,    -1,
      44,   248,   361,   249,     6,    -1,    45,   248,   361,   249,
       6,    -1,    44,   248,   361,   249,   262,   361,     6,    -1,
      44,   248,   361,   257,   357,   249,     6,    -1,    45,   248,
     361,   257,   357,   249,     6,    -1,    44,   248,   361,   257,
     357,   249,   262,   361,     6,    -1,   371,   361,   252,   265,
     253,     6,    -1,   166,     4,   250,   340,   251,     6,    -1,
     167,     4,   250,   340,   251,     6,    -1,   168,     4,   250,
     340,   257,   340,   251,     6,    -1,    -1,   265,   268,    -1,
     265,   272,    -1,   265,   275,    -1,   265,   277,    -1,   265,
     278,    -1,   340,    -1,   266,   257,   340,    -1,   340,    -1,
     267,   257,   340,    -1,    -1,    -1,     4,   269,   248,   266,
     249,   270,   252,   267,   253,     6,    -1,   361,    -1,   271,
     257,   361,    -1,    -1,   173,   248,   340,   257,   340,   257,
     340,   249,   273,   252,   271,   253,     6,    -1,   361,    -1,
     274,   257,   361,    -1,    -1,   174,   248,   340,   257,   340,
     257,   340,   257,   340,   249,   276,   252,   274,   253,     6,
      -1,   175,   252,   353,   253,   252,   353,   253,     6,    -1,
     175,   252,   353,   253,   252,   353,   253,   252,   353,   253,
     252,   353,   253,     6,    -1,    -1,   176,   279,   252,   267,
     253,     6,    -1,     7,    -1,   224,    -1,   223,    -1,   222,
      -1,   221,    -1,   246,    -1,   245,    -1,   248,    -1,   250,
      -1,   249,    -1,   251,    -1,    86,   250,   286,   251,     6,
      -1,    87,   250,   290,   251,     6,    -1,   345,     6,    -1,
      94,   282,   362,   257,   340,   283,     6,    -1,    96,   282,
     371,   257,   362,   283,     6,    -1,   371,   280,   354,     6,
      -1,   371,   281,     6,    -1,   371,   282,   283,   280,   354,
       6,    -1,   371,   282,   252,   357,   253,   283,   280,   354,
       6,    -1,   371,   250,   340,   251,   280,   340,     6,    -1,
     371,   250,   340,   251,   281,     6,    -1,   371,   248,   340,
     249,   280,   340,     6,    -1,   371,   248,   340,   249,   281,
       6,    -1,   371,     7,   362,     6,    -1,   371,   282,   283,
       7,    46,   282,   283,     6,    -1,   371,   282,   283,     7,
      46,   282,   366,   283,     6,    -1,   371,   282,   283,   224,
      46,   282,   366,   283,     6,    -1,   371,   254,     4,     7,
     362,     6,    -1,   371,   250,   340,   251,   254,     4,     7,
     362,     6,    -1,   371,   254,     4,   280,   340,     6,    -1,
     371,   250,   340,   251,   254,     4,   280,   340,     6,    -1,
     371,   254,     4,   281,     6,    -1,   371,   250,   340,   251,
     254,     4,   281,     6,    -1,   371,   254,   183,   254,     4,
       7,   358,     6,    -1,   371,   250,   340,   251,   254,   183,
     254,     4,     7,   358,     6,    -1,   371,   254,   184,     7,
     359,     6,    -1,   371,   250,   340,   251,   254,   184,     7,
     359,     6,    -1,   371,   194,     7,   354,     6,    -1,   194,
     250,   340,   251,     7,     4,     6,    -1,   194,   250,   340,
     251,     7,   106,     6,    -1,   194,   250,   340,   251,     7,
     107,     6,    -1,   194,   250,   340,   251,   254,     4,     7,
     340,     6,    -1,   194,   250,   340,   251,   254,     4,     7,
     362,     6,    -1,   194,   250,   340,   251,   254,     4,     7,
     252,   357,   253,     6,    -1,   194,   250,   340,   251,   254,
       4,     6,    -1,   138,   248,     4,   249,   254,     4,     7,
     340,     6,    -1,   138,   248,     4,   249,   254,     4,     7,
     362,     6,    -1,    -1,   257,    -1,    -1,   286,   285,   371,
      -1,   286,   285,   371,     7,   340,    -1,    -1,   286,   285,
     371,     7,   252,   354,   287,   292,   253,    -1,    -1,   286,
     285,   371,   282,   283,     7,   252,   354,   288,   292,   253,
      -1,   286,   285,   371,     7,   362,    -1,    -1,   286,   285,
     371,     7,   252,   362,   289,   296,   253,    -1,    -1,   290,
     285,   361,    -1,   340,     7,   362,    -1,   291,   257,   340,
       7,   362,    -1,   356,     7,   371,   248,   249,    -1,    -1,
     257,   294,    -1,    -1,   294,    -1,   295,    -1,   294,   257,
     295,    -1,     4,   354,    -1,     4,    -1,     4,   252,   291,
     253,    -1,     4,   362,    -1,     4,   365,    -1,    -1,   257,
     297,    -1,   298,    -1,   297,   257,   298,    -1,     4,   340,
      -1,     4,   362,    -1,   198,   362,    -1,     4,   367,    -1,
       4,   365,    -1,   340,    -1,   362,    -1,   362,   257,   340,
      -1,    -1,   186,   101,   252,   340,   253,    -1,   137,    97,
     252,   357,   253,    -1,   137,   116,   252,   357,   253,    -1,
      -1,   130,   351,    -1,    -1,   137,   141,    -1,    97,   248,
     340,   249,     7,   351,     6,    -1,   100,   248,   340,   249,
       7,   354,     6,    -1,   104,   248,   340,   249,     7,   354,
       6,    -1,    98,   248,   340,   249,     7,   354,   301,     6,
      -1,    99,   248,   340,   249,     7,   354,   301,     6,    -1,
     178,   248,   340,   249,     7,   354,     6,    -1,   179,   248,
     340,   249,     7,   354,     6,    -1,   180,   248,   340,   249,
       7,   354,   182,   354,   181,   340,     6,    -1,   115,   248,
     340,   249,     7,   354,     6,    -1,   100,     4,   248,   340,
     249,     7,   354,     6,    -1,   130,   103,   248,   340,   249,
       7,   354,     6,    -1,   103,   248,   340,   249,     7,   354,
     300,     6,    -1,   131,   103,   248,   340,   249,     7,   354,
     300,     6,    -1,    13,    14,     6,    -1,    14,   103,   340,
       6,    -1,   119,   103,   248,   340,   249,     7,     5,     5,
       5,     6,    -1,   101,   248,   340,   249,     7,   354,     6,
      -1,   102,   248,   340,   249,     7,   354,     6,    -1,   106,
     248,   340,   249,     7,   354,     6,    -1,   109,   248,   340,
     249,     7,   354,     6,    -1,   113,   248,   340,   249,     7,
     354,     6,    -1,   114,   248,   340,   249,     7,   354,     6,
      -1,   107,   248,   340,   249,     7,   354,     6,    -1,   108,
     248,   340,   249,     7,   354,     6,    -1,   127,   248,   340,
     249,     7,   354,     6,    -1,   154,   248,   340,   249,     7,
     354,     6,    -1,   103,     4,   248,   340,   249,     7,   354,
     302,     6,    -1,   105,   248,   340,   249,     7,   354,     6,
      -1,   126,   248,   340,   249,     7,   354,     6,    -1,   131,
     126,   248,   340,   249,     7,   354,     6,    -1,   134,   306,
     248,   340,   249,     7,   354,     6,    -1,   134,   306,   248,
     340,   249,     7,   354,     4,   252,   353,   253,     6,    -1,
      -1,   133,   305,   304,   248,   299,   249,   280,   354,     6,
      -1,    97,    -1,   100,    -1,   103,    -1,   105,    -1,   116,
     252,   340,   253,    -1,   100,    -1,   103,    -1,   105,    -1,
     116,   252,   340,   253,    -1,   100,    -1,   103,    -1,   116,
     252,   340,   253,    -1,    97,    -1,   100,    -1,   103,    -1,
     116,   252,   340,   253,    -1,   143,   351,   252,   310,   253,
      -1,   142,   252,   351,   257,   351,   257,   340,   253,   252,
     310,   253,    -1,   144,   351,   252,   310,   253,    -1,   145,
     252,   351,   257,   340,   253,   252,   310,   253,    -1,   145,
     252,   351,   257,   351,   253,   252,   310,   253,    -1,   148,
     252,   357,   253,   252,   310,   253,    -1,     4,   252,   310,
     253,    -1,   160,   100,   252,   357,   253,   103,   252,   340,
     253,    -1,   157,   100,   248,   340,   249,   252,   357,   253,
       6,    -1,   311,    -1,   309,    -1,    -1,   311,   303,    -1,
     311,   305,   252,   357,   253,     6,    -1,   311,   133,   305,
     252,   357,   253,     6,    -1,   311,   136,   305,   252,   357,
     253,     6,    -1,   311,   305,   252,     8,   253,     6,    -1,
     311,   133,   305,   252,     8,   253,     6,    -1,   147,   130,
     248,   340,   249,     7,   354,     6,    -1,   147,    97,   248,
     340,   249,     7,   252,   353,   253,     6,    -1,   147,   130,
     248,   340,   249,     7,   252,   351,   257,   351,   257,   357,
     253,     6,    -1,   147,   130,   248,   340,   249,     7,   252,
     351,   257,   351,   257,   351,   257,   357,   253,     6,    -1,
     147,   101,   248,   340,   249,     7,   252,   351,   257,   357,
     253,     6,    -1,   147,   107,   248,   340,   249,     7,   252,
     351,   257,   351,   257,   357,   253,     6,    -1,   147,   108,
     248,   340,   249,     7,   252,   351,   257,   351,   257,   357,
     253,     6,    -1,   147,   110,   248,   340,   249,     7,   252,
     351,   257,   351,   257,   357,   253,     6,    -1,   147,   111,
     248,   340,   249,     7,   252,   351,   257,   351,   257,   357,
     253,     6,    -1,   147,     4,   248,   340,   249,     7,   354,
       6,    -1,   147,     4,   248,   340,   249,     7,     5,     6,
      -1,   147,     4,   252,   340,   253,     6,    -1,   158,   252,
     311,   253,    -1,   140,   158,   252,   311,   253,    -1,   158,
       4,   252,   311,   253,    -1,   158,   194,   250,   340,   251,
       6,    -1,   158,     4,   250,   340,   251,     6,    -1,   158,
     371,     6,    -1,   158,     4,     4,     6,    -1,   158,    89,
       6,    -1,   183,   358,   252,   311,   253,    -1,   140,   183,
     358,   252,   311,   253,    -1,   218,   340,   252,   311,   253,
      -1,   199,   252,     8,   253,    -1,   199,     5,     6,    -1,
     200,   252,     8,   253,    -1,   200,     5,     6,    -1,   199,
     252,   311,   253,    -1,   140,   199,   252,   311,   253,    -1,
     200,   252,   311,   253,    -1,   140,   200,   252,   311,   253,
      -1,   371,   362,     6,    -1,    75,   248,   368,   249,     6,
      -1,   371,   371,   250,   340,   251,   361,     6,    -1,   371,
     371,   371,   250,   340,   251,     6,    -1,   371,   340,     6,
      -1,   138,   248,     4,   249,   254,     4,     6,    -1,   177,
       4,     6,    -1,   192,     6,    -1,   193,     6,    -1,    70,
       6,    -1,    71,     6,    -1,    64,     6,    -1,    64,   252,
     340,   257,   340,   257,   340,   257,   340,   257,   340,   257,
     340,   253,     6,    -1,    65,     6,    -1,    66,     6,    -1,
      80,     6,    -1,    82,   252,   340,   257,   340,   257,   340,
     253,     6,    -1,    81,     6,    -1,    83,     6,    -1,    84,
       6,    -1,   121,     6,    -1,   122,   252,   357,   253,   252,
     357,   253,   252,   353,   253,   252,   340,   257,   340,   253,
       6,    -1,   197,   248,   252,   357,   253,   257,   362,   257,
     362,   249,     6,    -1,   185,   248,   340,     8,   340,   249,
      -1,   185,   248,   340,     8,   340,     8,   340,   249,    -1,
     185,     4,   186,   252,   340,     8,   340,   253,    -1,   185,
       4,   186,   252,   340,     8,   340,     8,   340,   253,    -1,
     187,    -1,   198,     4,    -1,   198,   362,    -1,   195,    -1,
     196,   371,     6,    -1,   196,   362,     6,    -1,   188,   248,
     340,   249,    -1,   189,   248,   340,   249,    -1,   190,    -1,
     191,    -1,   146,   351,   252,   311,   253,    -1,   146,   252,
     351,   257,   351,   257,   340,   253,   252,   311,   253,    -1,
     146,   252,   351,   257,   351,   257,   351,   257,   340,   253,
     252,   311,   253,    -1,    -1,   146,   351,   252,   311,   321,
     325,   253,    -1,    -1,   146,   252,   351,   257,   351,   257,
     340,   253,   252,   311,   322,   325,   253,    -1,    -1,   146,
     252,   351,   257,   351,   257,   351,   257,   340,   253,   252,
     311,   323,   325,   253,    -1,    -1,   146,   252,   311,   324,
     325,   253,    -1,   146,   252,   311,   253,   137,   115,   252,
     340,   253,    -1,   126,   354,    -1,   131,   126,   354,    -1,
     128,   252,   357,   253,   252,   357,   253,   252,   357,   253,
      -1,   129,   252,   357,   253,   252,   357,   253,   252,   357,
     253,   252,   357,   253,    -1,   326,    -1,   325,   326,    -1,
     163,   252,   340,   253,     6,    -1,   163,   252,   354,   257,
     354,   253,     6,    -1,   164,     6,    -1,   155,     6,    -1,
     155,   340,     6,    -1,   169,     6,    -1,   169,   171,     6,
      -1,   170,     6,    -1,   170,   171,     6,    -1,   165,   248,
     340,   249,     7,   354,   137,   340,     6,    -1,   137,     4,
     250,   340,   251,     6,    -1,   149,    -1,   150,    -1,   151,
      -1,   152,    -1,   153,    -1,    -1,   158,     6,    -1,   140,
     158,     6,    -1,   158,   340,     6,    -1,   140,   158,   340,
       6,    -1,   327,   252,   311,   328,   253,   252,   311,   328,
     253,    -1,   112,   248,   361,   249,    -1,   327,   248,   340,
     249,     7,   252,   311,   328,   253,   252,   311,   328,   253,
       6,    -1,    -1,   137,     4,   340,    -1,    -1,     4,    -1,
      -1,     7,   354,    -1,    -1,     7,   340,    -1,    -1,   148,
     354,    -1,   117,   118,   355,     7,   340,     6,    -1,   132,
     100,   355,     7,   340,   331,     6,    -1,   132,   103,   355,
     333,   332,     6,    -1,   132,   105,   355,   333,     6,    -1,
     172,   355,     6,    -1,    95,    97,   248,   340,   257,   340,
     249,     6,    -1,    95,   100,   248,   340,   257,   340,   249,
       6,    -1,    95,   103,   248,   340,   257,   340,   249,     6,
      -1,    95,   105,   248,   340,   257,   340,   249,     6,    -1,
     161,   103,   252,   357,   253,     7,   340,     6,    -1,   155,
     103,   355,   334,     6,    -1,   155,   105,   355,     6,    -1,
     156,   103,   355,     7,   340,     6,    -1,   135,   100,   252,
     357,   253,     7,   252,   357,   253,   335,     6,    -1,   135,
     103,   252,   357,   253,     7,   252,   357,   253,   335,     6,
      -1,   135,   100,   252,   357,   253,     7,   252,   357,   253,
     142,   252,   351,   257,   351,   257,   340,   253,     6,    -1,
     135,   103,   252,   357,   253,     7,   252,   357,   253,   142,
     252,   351,   257,   351,   257,   340,   253,     6,    -1,   135,
     100,   252,   357,   253,     7,   252,   357,   253,   143,   351,
       6,    -1,   135,   103,   252,   357,   253,     7,   252,   357,
     253,   143,   351,     6,    -1,   135,   103,   340,   252,   357,
     253,     7,   340,   252,   357,   253,     6,    -1,   305,   252,
     357,   253,   186,   305,   252,   340,   253,     6,    -1,   162,
     307,   355,     6,    -1,   123,   308,   355,     6,    -1,   124,
     105,   354,     6,    -1,   139,   100,   354,     6,    -1,   134,
     306,   354,     6,    -1,   159,     6,    -1,   159,     4,     6,
      -1,   159,    97,   252,   357,   253,     6,    -1,   207,    -1,
     208,    -1,   209,    -1,   338,     6,    -1,   338,   252,   354,
     253,     6,    -1,   338,   252,   354,   257,   354,   253,     6,
      -1,   338,   248,   354,   249,   252,   354,   257,   354,   253,
       6,    -1,   341,    -1,   248,   340,   249,    -1,   237,   340,
      -1,   236,   340,    -1,   243,   340,    -1,   340,   237,   340,
      -1,   340,   236,   340,    -1,   340,   238,   340,    -1,   340,
     239,   340,    -1,   340,   241,   340,    -1,   340,   242,   340,
      -1,   340,   240,   340,    -1,   340,   247,   340,    -1,   340,
     230,   340,    -1,   340,   231,   340,    -1,   340,   235,   340,
      -1,   340,   234,   340,    -1,   340,   229,   340,    -1,   340,
     228,   340,    -1,   340,   227,   340,    -1,   340,   226,   340,
      -1,   340,   232,   340,    -1,   340,   233,   340,    -1,   340,
     225,   340,     8,   340,    -1,    16,   282,   340,   283,    -1,
      17,   282,   340,   283,    -1,    18,   282,   340,   283,    -1,
      19,   282,   340,   283,    -1,    20,   282,   340,   283,    -1,
      21,   282,   340,   283,    -1,    22,   282,   340,   283,    -1,
      23,   282,   340,   283,    -1,    24,   282,   340,   283,    -1,
      26,   282,   340,   283,    -1,    27,   282,   340,   257,   340,
     283,    -1,    28,   282,   340,   283,    -1,    29,   282,   340,
     283,    -1,    30,   282,   340,   283,    -1,    31,   282,   340,
     283,    -1,    32,   282,   340,   283,    -1,    33,   282,   340,
     283,    -1,    34,   282,   340,   283,    -1,    35,   282,   340,
     283,    -1,    36,   282,   340,   257,   340,   283,    -1,    37,
     282,   340,   257,   340,   283,    -1,    38,   282,   340,   257,
     340,   283,    -1,    25,   282,   340,   283,    -1,     3,    -1,
      10,    -1,    15,    -1,    11,    -1,    12,    -1,   214,    -1,
     215,    -1,   216,    -1,    77,    -1,    78,    -1,    79,    -1,
      -1,    88,   282,   340,   342,   292,   283,    -1,   345,    -1,
     205,   282,   361,   283,    -1,   205,   282,   361,   257,   340,
     283,    -1,   347,    -1,   371,   250,   340,   251,    -1,   371,
     248,   340,   249,    -1,   210,   248,   347,   249,    -1,   210,
     248,   347,   254,   348,   249,    -1,   212,   248,   347,   343,
     249,    -1,   212,   248,   347,   254,   348,   343,   249,    -1,
     212,   248,   347,   282,   340,   283,   343,   249,    -1,   212,
     248,   347,   254,   348,   282,   340,   283,   343,   249,    -1,
     211,   248,   362,   249,    -1,   255,   371,   282,   283,    -1,
     255,   347,   254,   348,   282,   283,    -1,    91,   282,   371,
     283,    -1,    91,   282,   283,    -1,   371,   281,    -1,   371,
     250,   340,   251,   281,    -1,   371,   248,   340,   249,   281,
      -1,   371,   254,   348,    -1,   371,     9,   371,   254,   348,
      -1,   371,   254,   348,   248,   340,   249,    -1,   371,     9,
     371,   254,   348,   248,   340,   249,    -1,   371,   254,   348,
     250,   340,   251,    -1,   371,     9,   371,   254,   348,   250,
     340,   251,    -1,   371,   250,   340,   251,   254,     4,    -1,
     371,   254,     4,   281,    -1,   371,   250,   340,   251,   254,
       4,   281,    -1,   201,   248,   361,   257,   340,   249,    -1,
      56,   248,   354,   257,   354,   249,    -1,    57,   282,   361,
     257,   361,   283,    -1,    55,   282,   361,   283,    -1,    58,
     282,   361,   257,   361,   283,    -1,    63,   248,   368,   249,
      -1,    -1,   257,   340,    -1,    -1,   257,   361,    -1,    -1,
      89,   347,   350,   346,   250,   293,   251,    -1,   371,    -1,
     371,     9,   371,    -1,     4,    -1,    92,    -1,    92,   340,
      -1,    -1,   248,   349,   249,    -1,   352,    -1,   237,   351,
      -1,   236,   351,    -1,   351,   237,   351,    -1,   351,   236,
     351,    -1,   252,   340,   257,   340,   257,   340,   257,   340,
     257,   340,   253,    -1,   252,   340,   257,   340,   257,   340,
     257,   340,   253,    -1,   252,   340,   257,   340,   257,   340,
     253,    -1,   248,   340,   257,   340,   257,   340,   249,    -1,
     354,    -1,   353,   257,   354,    -1,   340,    -1,   356,    -1,
     252,   253,    -1,   252,   357,   253,    -1,   237,   252,   357,
     253,    -1,   340,   238,   252,   357,   253,    -1,   354,    -1,
     252,     8,   253,    -1,     5,    -1,   237,   356,    -1,   340,
     238,   356,    -1,   340,     8,   340,    -1,   340,     8,   340,
       8,   340,    -1,    97,   252,   340,   253,    -1,    97,   252,
       8,   253,    -1,    97,     5,    -1,   306,   252,     8,   253,
      -1,   306,     5,    -1,   133,   305,   355,    -1,   136,   305,
     354,    -1,   305,   186,    64,   252,   340,   257,   340,   257,
     340,   257,   340,   257,   340,   257,   340,   253,    -1,    64,
     305,   252,   357,   253,    -1,    72,   306,   252,   340,   253,
      -1,    73,   306,   252,   340,   253,    -1,   309,    -1,   320,
      -1,   329,    -1,   371,   282,   283,    -1,   371,   254,   348,
     282,   283,    -1,   371,     9,   371,   254,   348,   282,   283,
      -1,    39,   250,   371,   251,    -1,    39,   250,   356,   251,
      -1,    39,   248,   356,   249,    -1,    39,   282,   252,   357,
     253,   283,    -1,   371,   282,   252,   357,   253,   283,    -1,
      40,   282,   340,   257,   340,   257,   340,   283,    -1,    41,
     282,   340,   257,   340,   257,   340,   283,    -1,    42,   282,
     361,   283,    -1,    43,   282,   340,   257,   340,   257,   340,
     257,   340,   257,   340,   257,   340,   283,    -1,   206,   282,
     356,   283,    -1,    32,   282,   356,   283,    -1,   340,    -1,
     356,    -1,   357,   257,   340,    -1,   357,   257,   356,    -1,
     252,   340,   257,   340,   257,   340,   257,   340,   253,    -1,
     252,   340,   257,   340,   257,   340,   253,    -1,   371,    -1,
       4,   254,   183,   254,     4,    -1,   252,   360,   253,    -1,
     371,   250,   340,   251,   254,   184,    -1,   358,    -1,   360,
     257,   358,    -1,   362,    -1,   371,    -1,   371,   250,   340,
     251,    -1,   371,   248,   340,   249,    -1,   371,   254,   348,
      -1,   371,     9,   371,   254,   348,    -1,   371,   254,   348,
     248,   340,   249,    -1,   371,     9,   371,   254,   348,   248,
     340,   249,    -1,   371,   250,   340,   251,   254,     4,    -1,
     305,   252,   340,   253,    -1,   133,   305,   252,   340,   253,
      -1,     5,    -1,   219,   250,   371,   251,    -1,    67,    -1,
     217,    -1,    74,    -1,    76,    -1,   203,   248,   361,   249,
      -1,   202,   248,   361,   257,   361,   249,    -1,   204,   282,
     361,   283,    -1,   204,   282,   361,   257,   361,   283,    -1,
     213,   248,   347,   344,   249,    -1,   213,   248,   347,   254,
     348,   344,   249,    -1,    48,   282,   368,   283,    -1,    49,
     248,   361,   249,    -1,    50,   248,   361,   249,    -1,    51,
     248,   361,   257,   361,   257,   361,   249,    -1,    46,   282,
     368,   283,    -1,    60,   282,   361,   283,    -1,    61,   282,
     361,   283,    -1,    62,   282,   361,   283,    -1,    59,   282,
     340,   257,   361,   257,   361,   283,    -1,    54,   282,   361,
     257,   340,   257,   340,   283,    -1,    54,   282,   361,   257,
     340,   283,    -1,    47,   282,   361,   283,    -1,    47,   282,
     361,   257,   357,   283,    -1,    68,   282,   361,   283,    -1,
      69,    -1,    53,   282,   361,   283,    -1,    52,   282,   361,
     283,    -1,    -1,    93,   282,   362,   363,   296,   283,    -1,
      90,   282,   364,   283,    -1,   255,   340,    -1,   371,     9,
     255,   340,    -1,    46,   282,   367,   283,    -1,   368,    -1,
     367,    -1,   252,   368,   253,    -1,   361,    -1,   369,    -1,
     368,   257,   361,    -1,   368,   257,   369,    -1,   371,   248,
     249,    -1,   371,   254,   348,   248,   249,    -1,   371,     9,
     371,   254,   348,   248,   249,    -1,     4,   256,   252,   340,
     253,    -1,   370,   256,   252,   340,   253,    -1,   220,   250,
     361,   251,   256,   252,   340,   253,    -1,     4,    -1,   370,
      -1,   220,   250,   361,   251,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   270,   270,   271,   276,   278,   282,   283,   284,   285,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   323,   327,   334,   339,
     344,   358,   371,   384,   412,   426,   439,   452,   471,   476,
     477,   478,   479,   480,   484,   486,   491,   493,   499,   603,
     498,   621,   628,   639,   638,   656,   663,   674,   673,   690,
     707,   730,   729,   743,   744,   745,   746,   747,   751,   752,
     758,   758,   759,   759,   765,   766,   767,   768,   773,   779,
     841,   856,   885,   895,   900,   908,   913,   921,   930,   935,
     947,   964,   970,   979,   997,  1015,  1024,  1036,  1041,  1049,
    1069,  1092,  1112,  1120,  1127,  1134,  1156,  1179,  1217,  1238,
    1250,  1264,  1264,  1266,  1268,  1277,  1287,  1286,  1307,  1306,
    1324,  1334,  1333,  1347,  1349,  1357,  1363,  1368,  1395,  1397,
    1400,  1402,  1406,  1407,  1411,  1423,  1436,  1451,  1460,  1473,
    1475,  1479,  1480,  1485,  1493,  1502,  1510,  1524,  1542,  1546,
    1553,  1562,  1565,  1571,  1575,  1587,  1590,  1597,  1600,  1606,
    1629,  1645,  1661,  1698,  1734,  1750,  1766,  1798,  1814,  1831,
    1847,  1897,  1915,  1921,  1927,  1934,  1965,  1980,  2002,  2025,
    2048,  2071,  2095,  2119,  2143,  2169,  2186,  2202,  2220,  2238,
    2245,  2254,  2253,  2283,  2285,  2287,  2289,  2291,  2299,  2301,
    2303,  2305,  2313,  2315,  2317,  2325,  2327,  2329,  2331,  2341,
    2357,  2373,  2389,  2405,  2421,  2438,  2475,  2497,  2521,  2522,
    2527,  2530,  2534,  2551,  2571,  2591,  2610,  2637,  2656,  2677,
    2692,  2708,  2726,  2777,  2798,  2820,  2843,  2948,  2964,  2999,
    3021,  3043,  3055,  3061,  3076,  3104,  3116,  3125,  3132,  3144,
    3164,  3168,  3173,  3177,  3182,  3189,  3196,  3203,  3215,  3288,
    3306,  3331,  3346,  3379,  3391,  3415,  3419,  3424,  3431,  3436,
    3446,  3451,  3457,  3465,  3469,  3473,  3477,  3481,  3485,  3494,
    3558,  3574,  3591,  3608,  3630,  3652,  3687,  3695,  3703,  3709,
    3716,  3723,  3743,  3769,  3781,  3792,  3810,  3828,  3847,  3846,
    3871,  3870,  3897,  3896,  3921,  3920,  3943,  3959,  3976,  3993,
    4016,  4044,  4047,  4053,  4065,  4085,  4089,  4093,  4097,  4101,
    4105,  4109,  4113,  4122,  4135,  4136,  4137,  4138,  4139,  4143,
    4144,  4145,  4146,  4147,  4150,  4174,  4193,  4216,  4219,  4235,
    4238,  4255,  4258,  4264,  4267,  4274,  4277,  4284,  4306,  4348,
    4392,  4431,  4456,  4468,  4480,  4492,  4504,  4513,  4543,  4569,
    4595,  4627,  4654,  4680,  4706,  4732,  4758,  4780,  4791,  4839,
    4893,  4908,  4920,  4931,  4938,  4953,  4967,  4968,  4969,  4973,
    4979,  4991,  5009,  5037,  5038,  5039,  5040,  5041,  5042,  5043,
    5044,  5045,  5052,  5053,  5054,  5055,  5056,  5057,  5058,  5059,
    5060,  5061,  5062,  5063,  5064,  5065,  5066,  5067,  5068,  5069,
    5070,  5071,  5072,  5073,  5074,  5075,  5076,  5077,  5078,  5079,
    5080,  5081,  5082,  5083,  5084,  5085,  5086,  5087,  5088,  5089,
    5098,  5099,  5100,  5101,  5102,  5103,  5104,  5105,  5106,  5107,
    5108,  5113,  5112,  5120,  5122,  5127,  5132,  5136,  5141,  5146,
    5150,  5154,  5158,  5162,  5166,  5170,  5176,  5191,  5195,  5201,
    5206,  5225,  5245,  5276,  5280,  5284,  5288,  5292,  5296,  5300,
    5305,  5315,  5325,  5330,  5341,  5350,  5355,  5360,  5388,  5389,
    5395,  5396,  5402,  5401,  5424,  5426,  5431,  5440,  5442,  5448,
    5449,  5454,  5458,  5462,  5466,  5470,  5477,  5481,  5485,  5489,
    5496,  5501,  5508,  5513,  5517,  5522,  5526,  5534,  5545,  5549,
    5553,  5567,  5575,  5583,  5590,  5600,  5623,  5628,  5634,  5639,
    5645,  5656,  5662,  5668,  5674,  5686,  5700,  5710,  5720,  5730,
    5742,  5746,  5751,  5763,  5767,  5771,  5775,  5793,  5801,  5809,
    5838,  5848,  5864,  5875,  5880,  5884,  5888,  5900,  5904,  5916,
    5933,  5943,  5947,  5962,  5967,  5974,  5978,  5983,  5997,  6013,
    6017,  6021,  6025,  6029,  6037,  6043,  6052,  6056,  6060,  6068,
    6074,  6080,  6084,  6092,  6100,  6107,  6116,  6120,  6124,  6139,
    6153,  6167,  6179,  6195,  6204,  6213,  6223,  6234,  6242,  6250,
    6254,  6273,  6280,  6286,  6293,  6301,  6300,  6310,  6334,  6336,
    6342,  6347,  6349,  6354,  6359,  6364,  6366,  6370,  6382,  6396,
    6400,  6407,  6415,  6423,  6434,  6436,  6439
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
  "tLogSpace", "tListFromFile", "tCatenary", "tPrintf", "tError", "tStr",
  "tSprintf", "tStrCat", "tStrPrefix", "tStrRelative", "tStrReplace",
  "tAbsolutePath", "tDirName", "tStrSub", "tStrLen", "tFind", "tStrFind",
  "tStrCmp", "tStrChoice", "tUpperCase", "tLowerCase", "tLowerCaseIn",
  "tTextAttributes", "tBoundingBox", "tDraw", "tSetChanged", "tToday",
  "tFixRelativePath", "tCurrentDirectory", "tSyncModel", "tNewModel",
  "tMass", "tCenterOfMass", "tOnelabAction", "tOnelabRun", "tCodeName",
  "tCpu", "tMemory", "tTotalMemory", "tCreateTopology", "tCreateGeometry",
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
  "tLayers", "tScaleLast", "tHole", "tAlias", "tAliasWithOptions",
  "tCopyOptions", "tQuadTriAddVerts", "tQuadTriNoNewVerts",
  "tRecombLaterals", "tTransfQuadTri", "tText2D", "tText3D",
  "tInterpolationScheme", "tTime", "tCombine", "tBSpline", "tBezier",
  "tNurbs", "tNurbsOrder", "tNurbsKnots", "tColor", "tColorTable", "tFor",
  "tIn", "tEndFor", "tIf", "tElseIf", "tElse", "tEndIf", "tExit", "tAbort",
  "tField", "tReturn", "tCall", "tSlide", "tMacro", "tShow", "tHide",
  "tGetValue", "tGetStringValue", "tGetEnv", "tGetString", "tGetNumber",
  "tUnique", "tHomology", "tCohomology", "tBetti", "tExists",
  "tFileExists", "tGetForced", "tGetForcedStr", "tGMSH_MAJOR_VERSION",
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
     475,   476,   477,   478,   479,    63,   480,   481,   482,   483,
      60,    62,   484,   485,   486,   487,    43,    45,    42,    47,
      37,   124,    38,    33,   488,   489,   490,    94,    40,    41,
      91,    93,   123,   125,    46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   258,   259,   259,   260,   260,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   262,   262,   263,   263,
     263,   263,   263,   263,   264,   264,   264,   264,   265,   265,
     265,   265,   265,   265,   266,   266,   267,   267,   269,   270,
     268,   271,   271,   273,   272,   274,   274,   276,   275,   277,
     277,   279,   278,   280,   280,   280,   280,   280,   281,   281,
     282,   282,   283,   283,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   285,   285,   286,   286,   286,   287,   286,   288,   286,
     286,   289,   286,   290,   290,   291,   291,   291,   292,   292,
     293,   293,   294,   294,   295,   295,   295,   295,   295,   296,
     296,   297,   297,   298,   298,   298,   298,   298,   299,   299,
     299,   300,   300,   300,   300,   301,   301,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   304,   303,   305,   305,   305,   305,   305,   306,   306,
     306,   306,   307,   307,   307,   308,   308,   308,   308,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   310,   310,
     311,   311,   311,   311,   311,   311,   311,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   314,   314,   315,
     316,   316,   316,   316,   316,   316,   316,   316,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   320,   320,   320,   321,   320,
     322,   320,   323,   320,   324,   320,   320,   320,   320,   320,
     320,   325,   325,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   327,   327,   327,   327,   327,   328,
     328,   328,   328,   328,   329,   329,   330,   331,   331,   332,
     332,   333,   333,   334,   334,   335,   335,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   337,   337,   337,   338,   338,   338,   339,
     339,   339,   339,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   342,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   343,   343,
     344,   344,   346,   345,   347,   347,   348,   349,   349,   350,
     350,   351,   351,   351,   351,   351,   352,   352,   352,   352,
     353,   353,   354,   354,   354,   354,   354,   354,   355,   355,
     355,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   357,   357,   357,   357,   358,   358,   358,
     358,   359,   359,   360,   360,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   363,   362,   362,   364,   364,
     365,   366,   366,   367,   368,   368,   368,   368,   369,   369,
     369,   370,   370,   370,   371,   371,   371
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       7,     7,     7,     9,     6,     6,     6,     8,     0,     2,
       2,     2,     2,     2,     1,     3,     1,     3,     0,     0,
      10,     1,     3,     0,    13,     1,     3,     0,    15,     8,
      14,     0,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     2,     7,     7,     4,
       3,     6,     9,     7,     6,     7,     6,     4,     8,     9,
       9,     6,     9,     6,     9,     5,     8,     8,    11,     6,
       9,     5,     7,     7,     7,     9,     9,    11,     7,     9,
       9,     0,     1,     0,     3,     5,     0,     9,     0,    11,
       5,     0,     9,     0,     3,     3,     5,     5,     0,     2,
       0,     1,     1,     3,     2,     1,     4,     2,     2,     0,
       2,     1,     3,     2,     2,     2,     2,     2,     1,     1,
       3,     0,     5,     5,     5,     0,     2,     0,     2,     7,
       7,     7,     8,     8,     7,     7,    11,     7,     8,     8,
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
      15,     2,     2,     2,     9,     2,     2,     2,     2,    16,
      11,     6,     8,     8,    10,     1,     2,     2,     1,     3,
       3,     4,     4,     1,     1,     5,    11,    13,     0,     7,
       0,    13,     0,    15,     0,     6,     9,     2,     3,    10,
      13,     1,     2,     5,     7,     2,     2,     3,     2,     3,
       2,     3,     9,     6,     1,     1,     1,     1,     1,     0,
       2,     3,     3,     4,     9,     4,    14,     0,     3,     0,
       1,     0,     2,     0,     2,     0,     2,     6,     7,     6,
       5,     3,     8,     8,     8,     8,     8,     5,     4,     6,
      11,    11,    18,    18,    12,    12,    12,    10,     4,     4,
       4,     4,     4,     2,     3,     6,     1,     1,     1,     2,
       5,     7,    10,     1,     3,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     1,     4,     6,     1,     4,     4,     4,
       6,     5,     7,     8,    10,     4,     4,     6,     4,     3,
       2,     5,     5,     3,     5,     6,     8,     6,     8,     6,
       4,     7,     6,     6,     6,     4,     6,     4,     0,     2,
       0,     2,     0,     7,     1,     3,     1,     1,     2,     0,
       3,     1,     2,     2,     3,     3,    11,     9,     7,     7,
       1,     3,     1,     1,     2,     3,     4,     5,     1,     3,
       1,     2,     3,     3,     5,     4,     4,     2,     4,     2,
       3,     3,    16,     5,     5,     5,     1,     1,     1,     3,
       5,     7,     4,     4,     4,     6,     6,     8,     8,     4,
      14,     4,     4,     1,     1,     3,     3,     9,     7,     1,
       5,     3,     6,     1,     3,     1,     1,     4,     4,     3,
       5,     6,     8,     6,     4,     5,     1,     4,     1,     1,
       1,     1,     4,     6,     4,     6,     5,     7,     4,     4,
       4,     8,     4,     4,     4,     4,     8,     8,     6,     4,
       6,     4,     1,     4,     4,     0,     6,     4,     2,     4,
       4,     1,     1,     3,     1,     1,     3,     3,     3,     5,
       7,     5,     5,     8,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     2,     3,     1,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,   194,     0,     0,   195,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   324,   325,   326,   327,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
     293,   294,     0,     0,     0,   288,     0,     0,     0,     0,
       0,   376,   377,   378,     0,     0,     5,     6,     7,     8,
      10,     0,    11,    24,    12,    13,    14,    15,    23,    22,
      21,    16,     0,    17,    18,    19,    20,     0,    25,     0,
     615,     0,   220,     0,     0,     0,     0,     0,   269,     0,
     271,   272,   267,   268,     0,   273,   275,     0,   276,   277,
     113,   123,   614,   489,   484,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,     0,   205,   206,   207,
       0,     0,     0,     0,   430,   431,   433,   434,   432,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,   439,   440,     0,     0,
     193,   198,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   435,   436,   437,     0,     0,
       0,     0,     0,     0,     0,     0,   526,   527,     0,   528,
     502,   383,   443,   446,   307,   503,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     191,   198,   199,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
       0,     0,   220,     0,     0,   373,     0,     0,     0,   202,
     203,     0,     0,     0,     0,     0,   510,     0,     0,   508,
       0,     0,     0,     0,     0,   614,     0,     0,   549,     0,
       0,     0,     0,   265,   266,     0,   566,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     568,     0,   592,   570,   571,     0,     0,     0,     0,     0,
       0,   569,     0,     0,     0,     0,   286,   287,     0,   220,
       0,   220,     0,     0,     0,   484,     0,     0,     0,   220,
     379,     0,     0,    76,     0,    63,     0,     0,    67,    66,
      65,    64,    69,    68,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   555,   484,     0,   219,     0,   218,     0,
     172,     0,     0,   555,   556,     0,     0,   604,     0,   605,
     556,     0,   111,   111,     0,   482,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,   544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   517,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   386,     0,   385,   511,   387,
       0,   504,     0,     0,   484,     0,   519,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,   460,     0,     0,     0,     0,     0,     0,     0,
     308,     0,   341,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,     0,   220,   220,     0,   493,   492,
       0,     0,     0,     0,   220,   220,     0,     0,     0,     0,
     304,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   343,     0,     0,     0,     0,     0,
     220,   246,     0,     0,   244,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   351,   264,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     290,   289,     0,   251,     0,     0,   253,     0,     0,     0,
     385,     0,   220,     0,     0,     0,     0,     0,     0,     0,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    72,    73,     0,     0,     0,   262,
      38,   258,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,     0,   221,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,     0,     0,     0,   487,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,     0,     0,     0,   197,     0,     0,     0,
       0,     0,     0,   369,   370,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   459,     0,
       0,     0,     0,   520,   521,     0,     0,     0,     0,     0,
     478,     0,   384,   505,     0,     0,     0,     0,   513,     0,
     403,   402,   401,   400,   396,   397,   404,   405,   399,   398,
     389,   388,     0,   390,   512,   391,   394,   392,   393,   395,
     485,     0,     0,   486,   463,     0,   529,     0,     0,     0,
       0,     0,     0,     0,     0,   339,     0,     0,     0,     0,
     372,     0,     0,     0,     0,   371,     0,   220,     0,     0,
       0,     0,     0,   495,   494,     0,     0,     0,     0,     0,
       0,     0,   298,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   358,     0,     0,   245,
       0,     0,     0,   239,     0,     0,     0,     0,   368,     0,
       0,     0,   384,   509,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   595,     0,     0,     0,   480,     0,     0,   250,
     254,   252,   256,     0,   390,     0,   485,   463,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,   384,     0,    63,     0,     0,     0,     0,    79,     0,
      63,    64,     0,     0,     0,   485,     0,     0,   463,     0,
       0,     0,   191,     0,     0,     0,   611,    28,    26,    27,
       0,     0,     0,     0,     0,   486,   559,    29,     0,     0,
     259,   606,   607,     0,   608,   559,     0,    74,   114,    75,
     124,   488,   490,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   545,   546,   208,     9,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   429,   416,     0,   418,   419,   420,
     421,   422,   542,   423,   424,   425,     0,     0,     0,   534,
     533,   532,     0,     0,     0,   539,     0,   475,     0,     0,
       0,   477,     0,     0,     0,   128,   458,   516,   515,   201,
       0,     0,   444,   541,   449,     0,   455,     0,     0,     0,
       0,   506,     0,     0,   456,     0,   518,     0,     0,     0,
       0,   448,   447,   470,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   384,   337,   342,   340,     0,   350,     0,
     148,   149,   201,   384,     0,     0,     0,     0,   240,     0,
     255,   257,     0,     0,     0,   209,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   311,     0,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,     0,   344,   357,     0,     0,     0,   241,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   247,     0,     0,     0,     0,   582,     0,   589,
     578,   579,   580,     0,   594,   593,     0,     0,   583,   584,
     585,   591,   598,   597,     0,   139,     0,   572,     0,   574,
       0,     0,     0,   567,     0,   249,     0,     0,     0,     0,
       0,     0,     0,   330,     0,     0,     0,   380,     0,   612,
       0,   101,    63,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   564,
      48,     0,     0,     0,    61,     0,    39,    40,    41,    42,
      43,     0,   448,   447,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,   557,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,   155,   155,     0,
       0,     0,     0,     0,   151,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   523,   524,
     525,     0,     0,     0,     0,     0,   478,   479,     0,   451,
       0,     0,     0,   514,   406,   507,   464,   462,     0,   461,
       0,     0,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,   316,     0,
       0,   315,     0,   318,     0,   320,     0,   305,   312,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   359,     0,   243,   242,   375,     0,     0,    35,
      36,     0,     0,     0,     0,   550,     0,     0,     0,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   481,   576,     0,   464,     0,     0,
     220,   331,     0,   332,   220,     0,     0,   565,     0,    86,
       0,     0,     0,     0,    84,    91,    93,     0,   553,     0,
      99,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,    34,   464,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,    31,     0,   560,     0,
       0,    32,     0,   560,   609,     0,     0,   115,   120,     0,
       0,     0,   134,   137,   138,   483,     0,    77,     0,     0,
       0,     0,    78,   159,     0,     0,     0,     0,   160,   175,
     176,   157,     0,     0,     0,   161,   186,   177,   181,   182,
     178,   179,   180,   167,     0,     0,   417,   426,   427,   428,
     535,     0,     0,     0,   473,   474,   476,   129,   442,   472,
     445,   450,     0,     0,   478,   187,   457,     0,    70,    71,
       0,   469,   465,   467,   536,   183,     0,     0,     0,   151,
       0,     0,   348,     0,   150,     0,     0,     0,     0,   263,
       0,     0,     0,     0,   220,   220,     0,     0,   317,   502,
       0,     0,   319,   321,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   214,   184,     0,
       0,     0,     0,   164,   165,     0,     0,     0,     0,   102,
     103,   104,   108,     0,   590,     0,     0,   588,     0,   599,
       0,     0,   140,   141,   596,   573,   575,     0,     0,     0,
       0,     0,     0,   329,   333,   329,     0,   381,    85,    63,
       0,     0,     0,     0,    83,     0,   551,     0,     0,     0,
       0,     0,     0,   602,   601,     0,     0,     0,     0,     0,
     500,     0,     0,   469,   260,   465,   261,     0,     0,     0,
       0,     0,   225,   222,     0,     0,   563,   561,     0,     0,
       0,   116,   121,     0,     0,     0,   543,   544,   133,   352,
     353,   354,   355,   156,   162,   163,   168,     0,     0,     0,
       0,     0,   170,     0,     0,     0,     0,     0,     0,   452,
       0,     0,     0,     0,   531,   471,     0,     0,   169,     0,
     188,   338,     0,     0,   189,     0,     0,     0,     0,     0,
       0,   499,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   236,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,   356,    37,     0,   548,
       0,     0,   283,   282,     0,     0,     0,     0,     0,     0,
     143,   144,   147,   146,   145,     0,   577,     0,   613,     0,
       0,     0,     0,     0,     0,    96,     0,     0,    97,   554,
       0,     0,     0,    88,     0,     0,     0,    44,     0,     0,
       0,     0,     0,    46,     0,   226,   223,   224,    33,     0,
       0,   610,   274,   128,   139,     0,     0,   136,     0,     0,
       0,   158,   185,     0,     0,     0,     0,     0,   537,   538,
       0,   478,   453,     0,   466,   468,     0,     0,   171,   192,
       0,   345,   345,     0,   109,   110,   220,     0,   212,   213,
     306,     0,   313,     0,     0,   220,     0,     0,     0,     0,
       0,     0,     0,     0,   217,   216,     0,     0,     0,     0,
     105,   106,   581,   587,   586,   142,     0,     0,     0,   334,
       0,    92,    94,     0,   100,     0,    82,   603,    89,    90,
      49,     0,     0,     0,     0,   501,     0,     0,   466,   562,
       0,     0,     0,   118,   600,     0,   125,     0,     0,     0,
       0,   174,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   497,     0,
     323,     0,     0,   300,     0,   228,     0,     0,     0,     0,
       0,     0,     0,   547,   284,     0,     0,   367,   220,   382,
       0,   552,     0,    45,     0,     0,     0,    62,    47,     0,
     117,   122,   128,     0,     0,   153,   154,   152,     0,     0,
     454,     0,     0,     0,     0,     0,   346,   360,     0,     0,
     361,     0,   210,     0,   314,     0,   296,     0,   220,     0,
       0,     0,     0,     0,     0,   166,   107,   280,   329,    98,
       0,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,     0,   190,     0,   364,     0,   365,   366,   496,     0,
       0,   302,   231,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,    59,     0,     0,   119,     0,     0,     0,
     310,     0,     0,   322,   301,   297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   233,   234,   235,     0,
     229,   336,    50,     0,    57,     0,   270,     0,   540,     0,
       0,     0,   303,     0,     0,    51,     0,     0,   279,     0,
       0,     0,   230,     0,     0,     0,     0,   522,     0,     0,
      54,    52,     0,    55,     0,   362,   363,     0,     0,    60,
      58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   116,  1060,   117,   118,  1044,  1886,  1892,
    1336,  1546,  2042,  2174,  1337,  2145,  2192,  1338,  2176,  1339,
    1340,  1550,   437,   592,   593,  1131,   119,   774,   462,  1903,
    2052,  1904,   463,  1775,  1412,  1367,  1368,  1369,  1510,  1712,
    1713,  1199,  1604,  1595,  1788,   753,   604,   274,   275,   352,
     201,   276,   447,   448,   123,   124,   125,   126,   127,   128,
     129,   130,   277,  1231,  2077,  2136,   940,  1227,  1228,   278,
    1023,   279,   134,  1441,  1197,   915,   955,  2012,   135,   136,
     137,   138,   280,   281,  1155,  1170,  1292,   282,   779,   283,
     904,   778,   465,   619,   320,  1749,   359,   360,   285,   562,
     367,  1323,  1539,   457,   453,  1285,  1000,  1584,  1742,  1743,
     985,   459,   140,   415
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1850
static const yytype_int16 yypact[] =
{
   12714,    54,    26, 12874, -1850, -1850,  -128,    91,    24,   -71,
     -60,    41,   141,   196,   225,   249,   -28,   256,   262,   -11,
     271,   303,    93,    97,    40,   -83,   600,   -83,   106,   115,
     124,    68,   167,   203,    69,   223,   245,   254,   259,   265,
     293,   326,   339,   348,   354,   168,   365,   506,   315,   362,
     518,   546,   411,  6809,   437,   439,   446,   612,   -48,   570,
     122,   533,   -26,   490,   654,   -65,   507,   383,   383,   557,
     409,    71,   575, -1850, -1850, -1850, -1850, -1850,   514,   277,
     667,   695,    19,    53,   701,   734,     4,   840,   849,   880,
    5825,   884,   647,   668,   676,    20,    72, -1850,   681,   684,
   -1850, -1850,   909,   946,   703, -1850, 13111,   706, 13170,     5,
      35, -1850, -1850, -1850, 11721,   736, -1850, -1850, -1850, -1850,
   -1850,   778, -1850, -1850, -1850, -1850, -1850, -1850, -1850, -1850,
   -1850, -1850,   -72, -1850, -1850, -1850, -1850,    52, -1850,   985,
     743,  5572,   456,   785,  1029, 11721, 13051, 13051, -1850, 11721,
   -1850, -1850, -1850, -1850, 13051, -1850, -1850, 11721, -1850, -1850,
   -1850, -1850,   782,   796,  1037, -1850, -1850, 13228,   811,   815,
     816,   818,    40, 11721, 11721, 11721,   819, 11721, 11721, 11721,
     820, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 13051, 11721,
   11721, 11721, 11721,  5825,   821, -1850,  9505, -1850, -1850, -1850,
     823,  5825,  7055, 13051, -1850, -1850, -1850, -1850, -1850,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   311,   -83,   -83,   -83,   -83,   -83,   822,   -83,
     -83,   824,   122,   533,   533, -1850, -1850, -1850,   -83,   -83,
      36,   885,   887,   890,   825,  7055,   952,   122,   122,   831,
     -83,   -83,   832,   833,   834, -1850, -1850, -1850, 11721,  7301,
   11721, 11721,  7547,    40,   897,    46, -1850, -1850,   835, -1850,
    4253, -1850, -1850, -1850, -1850, -1850,   116, 11721,  9505,  9505,
     836,   837,  7793,  5825,  5825,  5825, -1850, -1850, -1850, -1850,
   -1850, -1850, -1850, -1850,   838,  8039,   842,  4313,  1082,  7055,
     856,    20,   857,   858,   383,   383,   383, 11721, 11721,   -63,
   -1850,   248,   383, 10415,   300,   -18,   863,   864,   867,   868,
     888,   889,   891,  9505, 11721,  5825,  5825,  5825,   894,    11,
    1132,   898, -1850,  1135,  1137, -1850,   892,   900,   901, -1850,
   -1850,   902,  5825,   899,   905,   906, -1850, 11721,  6071, -1850,
    1144,  1151, 11721, 11721, 11721,   404, 11721,   907, -1850,   972,
   11721, 11721, 11721, -1850, -1850, 11721, -1850,   -83,   -83,   -83,
     912,   913,   914,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
   -1850,   -83, -1850, -1850, -1850,   -83,   -83,   915,   917,   -83,
     918, -1850,   920,  1161,  1165,   922, -1850, -1850,  1166,  1167,
    1170,  1169,   -83, 11721, 14772,   123, 13051,  9505, 11721, -1850,
   -1850,  7055,  7055, -1850,   926, 13228,   122,  1172, -1850, -1850,
   -1850, -1850, -1850, -1850, 11721, 11721,    23,  7055,  1174,   191,
     929,   893,   930,  1177,    30,   932, -1850,   935, 13448, 11721,
   -1850,  1183,  -135, -1850,    57,  -116,   981, -1850,   -97, -1850,
      74,  6499,  -160,   -95,  1081, -1850,    40,   933, 11721, 11721,
   11721, 11721,   934, 15288, 15313, 15338, 11721, 15363, 15388, 15413,
   11721, 15438, 15463, 15488, 15513, 15538, 15563, 15588,   943, 15613,
   15638, 15663, 13873,  1186, 11721,  9505,  4664, -1850,   -70, 11721,
    1190,  1191,   949, 11721, 11721, 11721, 11721, 11721, 11721, 11721,
   11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721,  9505,
   11721, 11721, 11721, 11721, 11721, 11721,  9505,  9505,   947, 11721,
   11721, 13051, 11721, 13051,  7055, 13051, 13051, 13051,   948,   953,
     973, 11721,    61, -1850, 10497, 11721,  7055,  5825,  7055, 13051,
   13051,  9505,    40, 13228,    40,   954,  9505,   954, -1850,   954,
   15688, -1850,   164,   950,    89,  1168, -1850,  1221, 11721, 11721,
   11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721, 11721,
   11721, 11721,  8285, 11721, 11721, 11721, 11721, 11721,    40, 11721,
   11721,  1229, -1850,   722, 15713,   285,   297, 11721, 11721, 11721,
   -1850,  1228,  1230,  1230,   988, 11721, 11721,  1236,  9505,  9505,
   14800,   994,  1238, -1850,   993, -1850, -1850,  -188, -1850, -1850,
    6745,  6991,   383,   383,   456,   456,  -155, 10415, 10415, 11721,
    3778,  -127, -1850, 11721, 11721, 11721, 11721, 11721, 11721, 11721,
   11721, 11721,   387, 15738,  1239,  1241,  1242, 11721,  1244, 11721,
   -1850, -1850, 11721,  3966, -1850, -1850,  9505,  9505,  9505, 11721,
    1245, 11721, 11721, 11721, 15763,   995, -1850, -1850, 15788, 15813,
   15838,  1069,  7237, -1850,  1001,  4713, 15863, 15888, 14883, 13051,
   13051, 13051, 13051, 13051, 13051, 13051, 13051, 13051, 11721, 13051,
   13051, 13051, 13051,     3, 13228, 13051, 13051, 13051,    40,    40,
   -1850, -1850,  9505, -1850,  1004,  5134, -1850,  1005, 11892, 11721,
     954, 11721, -1850,    40, 11721, 11721,  1229,  1009,   395, 15913,
   13351,  1012,   464, 11721,  1257,  1015,  7055, 15938, 14910,   129,
    1010,  1261,  1263, -1850, -1850, -1850,  9505,   214, 11721, -1850,
   -1850, -1850,    40, 11721, 11721,  1229,  1021, -1850,  1024,   -42,
     122,   533,   122, -1850,  1023, 13902, -1850,    22,  9505,    40,
   11721, 11721,  1269,  1270,  9505, 11721,  1272, 13051,    40, 10738,
    1269, 11721,  1273, -1850,    40,  1276, 13051, 11721,  1035,  1036,
   -1850, 11721,  7483,  7729,  7975,  8221, 13228,  1285,  1286,  1287,
   15963,  1288,  1290,  1291, 15988,  1292,  1293,  1294,  1295,  1297,
    1298,  1299, -1850,  1300,  1301,  1302, -1850, 11721, 16013,  9505,
    1039,  9505, 13931, -1850, -1850,  1304, 14856, 14856, 14856, 14856,
   14856, 14856, 14856, 14856, 14856, 14856, 14856,  8467, 14856, 14856,
   14856, 14856,   631,   457, 14856, 14856, 14856,  8708,  8949,  9195,
    4664,  1062,  1061,    90,  9505,  9441,  9777,   457, 10114,   457,
    1057,  1058,  1059,     7,  9505, 11721, 11721, 16913, -1850,   457,
    1064, 13960, 13989, -1850, -1850,  1063,   218,   457,  -187,  1072,
     393,   515,  1316, -1850,  1269,   457,  1074,  1071,  5068,  5261,
    1320,  1478,   728,   728,   427,   427,   427,   427,   427,   427,
     510,   510,  9505,   460, -1850,   460,   460,   954,   954,   954,
    1073, 16038, 14937,   381,   519,  9505, -1850,  1321,  1077,  1078,
   16063, 16088, 16113, 11721,  7055,  1328,  1329, 10174, 14018, 16138,
   -1850,   540,   554,  9505,  1080, -1850, 11960, -1850, 12028, 12096,
     383, 11721, 11721, -1850, -1850,  1084,  1085, 10415,  5481,  1202,
      -6,   383, 12164, 16163, 14047, 16188, 16213, 16238, 16263, 16288,
   16313, 16338,  1089,  1335, 11721,  1337, -1850, 11721, 16363, -1850,
   14964, 12232, 14991, -1850,   565,   566,   571, 14076, -1850, 15018,
   15045, 10364, -1850, -1850,  1339,  1341,  1342,  1090, 11721, 12300,
   11721, 11721, -1850, -1850,    49,   462,   496,   462,  1101,  1102,
    1095,   457,   457,  1096, 10446,   457,   457,   457,   457, 11721,
     457,  1345, -1850,  1098,  1107,   509,   208,  1106,   573, -1850,
   -1850, -1850, -1850, 14856,   460, 12368,  1105,   604,  1104,  1175,
    1355,  1206, 10827,  1112,  1114,  1361,  7055, 14105, -1850, 11721,
    1362,   202,    73, 13228, 11721,  1363,  1366,    31, -1850,   579,
    1325,  1326,  7055, 14134,    21,  1119, 16388, 15072,   325, 11721,
   11721,  1126,  1123,  1129,  1127,  8531, -1850, -1850, -1850, -1850,
   13051,    16,  1124, 16413, 15099, -1850,  1133, -1850,   110, 10694,
   -1850, -1850, -1850,  1128, -1850,  1136, 10769, -1850,    81, -1850,
   -1850, 16913, -1850,  1379, 14856, 11721, 11721, 11721, 11721,   457,
     383,  7055,  7055,  1378,  7055,  7055,  7055,  1380,  7055,  7055,
    7055,  7055,  7055,  7055,  7055,  7055,  7055,  7055,  1256,  1382,
    9505,  4664, -1850, -1850, -1850, -1850, -1850, -1850, -1850, -1850,
   -1850, -1850, -1850, -1850, -1850, -1850, 11721, -1850, -1850, -1850,
   -1850, -1850, -1850, -1850, -1850, -1850, 11721, 11721, 11721, -1850,
   -1850, -1850,   585, 11721, 11721, -1850, 11721, -1850,  7055, 13051,
   13051, -1850,   586, 14163, 14192,  1138, -1850, -1850, -1850,  1200,
   11721, 11721, -1850, -1850, -1850,  1269, -1850,  1269, 11721, 11721,
    1145, -1850,  7055,   -83, -1850, 11721, -1850, 11721, 11721,   592,
    1269,   381,    -9, -1850, 11721, 11721,   457,   593,  7055,  9505,
    9505,  1389,  1390,  1391,  3896, -1850, -1850,  1393, -1850,  1152,
   16913,  1143, -1850,  1395,  1396,  1397,   622,  1402, -1850, 12436,
   -1850, -1850,  -120, 11024, 11099, -1850, -1850, 14221,   175,  1311,
    1423, 11068,  1176,  1426,  1181,    37,    39,   -69, -1850,   -91,
   -1850,    -6,  1430,  1427,  1431,  1433,  1434,  1436,  1437,  1438,
    1439,   456,  7055, 16913, -1850,  1284,  1197,  1444, -1850,  1445,
    1446,  1350,  1447, -1850,  1449,  1450, 11721,  7055,  7055,  7055,
    1454, 11347, -1850,  5515,   708,    33,  1455, -1850,  9505, -1850,
   -1850, -1850, -1850, 13051, -1850, -1850, 11721, 13051, -1850, -1850,
   -1850, -1850, 16913, -1850,  1205,  1204, 13051, -1850, 13051, -1850,
    1269, 13051,  1213, -1850,  1207, -1850,  1269, 11721, 11721,  1211,
     122,  1214, 11157, -1850,  1581,  1215,  7055, -1850,  1212, -1850,
   14250, -1850, -1850, 11721,  1463,    34, 11721,  1464,  1465,  1642,
   -1850,  1466,    20,  1468,  1222,   457,   -83,   -83,  1469, -1850,
   -1850,  1231,  1252,  1225, -1850,  1472, -1850, -1850, -1850, -1850,
   -1850,  1269,   273,  3469, 11721, 15126, 16438, 11721,  8772, 11721,
    9505,  1249,   624,  1498,   155,  1269, -1850,  1251, 11721,  1500,
   11721,  1269, 11398, 11721,  9746,   457,  4969,  1277,  1275, -1850,
    1502, 16463, 16488, 16513, 16538,  1521,   109,  1399,  1399,  7055,
    1524,  1527,  1529,  7055,  -101,  1530,  1531,  1532,  1533,  1536,
    1537,  1538,  1539,  1557, -1850,  1560,   633, 14856, 14856, 14856,
   14856,   457, 11429, 12506, 13109,  1317,   457,   457, -1850, -1850,
   -1850,  1379,   457, 16563, 14856,  1319,   232, 16913, 14856, -1850,
    1563,   457, 13165, 16913, 16913, -1850,   626, -1850,  1566, -1850,
   16588, 15153, -1850,   457,  1568,   640,   641,  7055,  7055,  7055,
    1572,  1571, -1850,   235, 11721,  7055,  1327,  1330,  1565,   737,
   -1850, 11721, 11721, 11721,  1338,  1340,  1343,  1331, -1850,  1757,
    7055, -1850, 11721, -1850,  1574, -1850,  1585, -1850, -1850, 10415,
     309,  6317, -1850,  1344,  1347,  1348,  1349,  1351,  1352,  9013,
    1353,  1587, -1850,  9505, -1850, -1850, -1850,  1356, 11721, -1850,
   -1850, 15180,  1588,  1591,  1420, -1850, 11721, 11721, 11721, -1850,
    1599,  1601,  1603,   810,   543,  1354,  2960,  1357, 11721,    28,
     457,  1367,   457,  1358, -1850, -1850, 13228,   635, 11721,  1365,
   -1850, -1850,  1857, -1850, -1850,  1364,  1604, -1850,  1914, -1850,
     209,  1368,  1611,  2114, -1850, -1850, -1850,    20, -1850,   643,
   -1850, 11721,   235,  4666, 11768, -1850,  1371, 11721, 11721,  7055,
    1372, -1850,   470,  1616,  1617, 16613,  1619,  1316, 16638,  1374,
     648, 16663,   650,  1622,  1623, -1850, -1850, 13051,  1383,  1626,
   16688, -1850, 13285,  1384, -1850, 14279,  5316, 16913, -1850,  1628,
     -83,  7547, -1850, -1850, -1850, -1850,  1379, -1850,  1630,  1631,
    1632,  1633, -1850, -1850,   383,  1634,  1636,  1637, -1850, -1850,
   -1850,  1507,   -27,  1545,  1641, -1850, -1850, -1850, -1850, -1850,
   -1850, -1850, -1850, -1850,  1644,  1404, -1850, -1850, -1850, -1850,
   -1850, 11721, 11721, 11721, -1850, -1850, -1850,  1275, -1850, -1850,
   -1850, -1850, 11721,  1408,  1394, -1850, -1850, 11721, 11721, 11721,
     457,   381, -1850, -1850, -1850, -1850,  1406,  1407,  1654,  -101,
    1655, 11721, -1850,  7055, 16913,   921,  9505,  9505, 11721, -1850,
   10174, 14308, 16713,  5763,   456,   456, 11721, 11721, -1850,   163,
    1405, 16738, -1850, -1850, 14337,   -25, -1850,  1657,  1660,  7055,
     383,   383,   383,   383,   383,  6563,  1662, -1850, -1850,   651,
   11721,  2540,  1663, -1850, -1850,  7055,  6007,   549, 16763, -1850,
   -1850, -1850, -1850,  9837, -1850, 13051, 11721, -1850, 13051, 16913,
   10083, 13228,  1413, -1850, -1850, -1850, -1850,  1422,  1415, 11721,
   11721, 14366, 11721, 13351, -1850, 13351,  7055, -1850, -1850, 13228,
   11721,  1667,  1670,    31, -1850,  1669, -1850,    20, 15207,  7055,
   13051,  1671,   457, -1850,  1421,   457, 11721, 13378, 13411,   653,
   -1850, 11721, 11721,   377, -1850,  1428, -1850,  1391,  1673,  1675,
    1395,  1677, -1850, -1850,  1678, 11721, -1850, -1850, 11721, 11480,
    1679, -1850, -1850,  1435, 11768,   656,  3420,  1681, -1850, -1850,
   -1850, -1850, -1850,   435, -1850, -1850, -1850,  1548,  1680,  1441,
    1442,  1443, -1850,  1685,  7055, 14856, 14856, 13444, 14856, -1850,
    1448, 13477, 16788, 15234, -1850, -1850,  9505,  9505, -1850,  1690,
   -1850, 16913,  1692,  1451, -1850,   664,   665, 14828,  2686,  1693,
    1452, -1850, -1850, 11721,  1471,  1473, 14395, 15261,  1694,  7055,
    1684,  1470, 11721, -1850, -1850,   666,   -22,    -8,   170,   172,
     213,  9259,   251, -1850,  1695, 14424, -1850, -1850,  1540, -1850,
   11721, 11721, -1850, -1850,  9505,  2733,  1721,  1479, 14856,   457,
   16913, -1850, -1850, -1850, -1850,    28, -1850, 13228, -1850, 14453,
    1476,  1480,  1482,  1725,  2872, -1850,  1731,  1726, -1850, -1850,
    1485,  1734,   673, -1850,  1735,  1736,   127, 16913, 11721, 11721,
    1491,  7055,   719, 16913, 16813, -1850, -1850, -1850, -1850, 16838,
   13510, -1850, -1850,  1138,  1204,  7055,   457, -1850, 11721, 13228,
      40, -1850, -1850,  9505,  9505, 11721,  1738,   739, -1850, -1850,
   11721,  1394, -1850, 11721, -1850, -1850,   744,   745, -1850, -1850,
    7055,   662,   672,  9505, -1850, -1850,   456,  6253, -1850, -1850,
   -1850,  1739, -1850,  1493,  7055, -1850, 14482,  1741,  9505,   383,
     383,   383,   383,   383, -1850, -1850, 11721, 14511, 14540,   747,
   -1850, -1850, -1850, -1850, -1850, -1850,  1503,  1743,  1499, -1850,
    1748, -1850, -1850,    20, -1850,  1573, -1850, -1850, -1850, -1850,
   -1850, 11721, 13543, 13576,  7055, -1850,  1749, 11721,  1504, -1850,
   11721,  1505,  1506, -1850, -1850,  3108, -1850,  1512,   752,   754,
   14569, -1850,  1509, 13609,  1513, 13642, -1850,  1514,   755,  1515,
     383,  7055,  1758,  1516,   383,  1759,   757,  1519, -1850, 11721,
   -1850,  1763,  1638, 12504,  1522, -1850,   760,   260,   278,   327,
     329,   331,  3063, -1850, -1850,  1770,  1771, -1850, -1850, -1850,
    1772, -1850,  1528, 16913, 11721, 11721,   762, -1850, 16913, 13675,
   -1850, -1850,  1138, 13228,  1534, -1850, -1850, -1850, 11721, 11721,
   -1850, 11721,  9505,  1773,   383,   120, -1850, -1850,   383,   142,
   -1850,  1775, -1850, 14598, -1850, 11721, -1850,    -6, -1850,  1776,
    9505,  9505,  9505,  9505,  9259, -1850, -1850, -1850, 13351, -1850,
   11721, 16863, 13708,    47, 11721,  1541, -1850, -1850, 13741, 13774,
   13807,   767, -1850,   333, -1850,   335, -1850, -1850, -1850,  3252,
     340, 12572, -1850,   768,   769,   774,   775,   346,   776,  1542,
     783, -1850, 11721, -1850,  7055, 14627, -1850, 11721, 11721, 11721,
   -1850,   383,   383, -1850, -1850, -1850,    -6,  1778,  1779,  1780,
    1781,  9505,  1783,  1786,  1787,  1544, 16888,   790,  1791, 14656,
   14856, 13840,   371,   375,   357, -1850, -1850, -1850, -1850,   792,
   -1850, -1850, -1850, 13051, -1850,  1546, -1850,  1793, -1850, 11721,
   11721, 11721, -1850,  1794,   798, -1850,  1549,  7055, -1850, 14685,
   14714, 14743, -1850,  1796, 13051, 13051,   803, -1850,  1799,  1818,
   -1850, -1850,   805, -1850,  1819, -1850, -1850,  1821, 13051, -1850,
   -1850, -1850
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1850, -1850, -1850, -1850,   475, -1850, -1850, -1850, -1850,  -260,
   -1850, -1850, -1850, -1850, -1850, -1850, -1850, -1850, -1850, -1850,
   -1850, -1850,  -717,  -140,  4407,  3424, -1850,  1370, -1850, -1850,
   -1850, -1850, -1850, -1850, -1849, -1850,   420,   250,   -67, -1850,
     -31, -1850,   186,   461, -1850,  1837, -1850,   298,   -39, -1850,
   -1850,     0,  -611,  -290, -1850, -1850, -1850, -1850, -1850, -1850,
   -1850, -1850,  1840, -1850, -1850, -1850, -1850, -1222, -1223,  1841,
   -1707,  1842, -1850, -1850, -1850,  1243, -1850,   -85, -1850, -1850,
   -1850, -1850,  2096, -1850, -1850, -1410,   336,  1845, -1850,     6,
    -699, -1850, -1850,   176, -1850, -1671,   859,  -182,  2621,  2512,
    -306,   117, -1850,    45,   -77, -1850, -1850,   143,   308, -1668,
    -152,  1087, -1850,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -564
static const yytype_int16 yytable[] =
{
     141,   438,   458,   122,  1468,   614,  1633,   162,  1835,  1470,
     408,   493,  1034,   935,   936,   648,  1870,  1017,  1871,   500,
    1042,   164,   305,   339,   365,  1330,     5,   729,  1057,   403,
     163,   407,  1710,   630,   162,   162,  1602,  1500,  1530,   742,
     410,   543,  1863,  1463,   162,  1465,  1048,   148,   622,   623,
     286,   566,   653,  2123,  1991,   291,  1265,   344,   420,   345,
       4,   291,  1164,  1066,   443,   162,   759,  1165,  1220,   930,
    1789,  1075,   176,   180,   306,   325,   369,   307,   292,   343,
    1312,   622,   623,   768,  1051,  1603,  1221,   286,  1364,  1790,
     467,   772,   368,   310,  1222,  1223,  1224,   773,   466,   588,
    1225,  1226,   937,   404,   349,   144,  1906,   350,   340,   622,
     623,   601,   602,   603,   757,  1593,   622,   623,   311,   705,
     351,   708,   758,  1917,   142,   588,  2104,   145,   143,   720,
     941,  1220,   713,   763,   312,   313,  1033,  1451,   444,  1501,
    1502,   764,   446,   454,   454,   622,   623,   150,  2106,  1221,
     346,   460,   766,   644,   645,   646,   775,  1222,  1223,  1224,
     767,  1566,   773,  1225,  1226,   165,  1469,   166,   326,   472,
     660,   568,   327,   622,   623,  1173,   418,   146,   328,   329,
     419,   330,   331,   810,  1467,   454,   442,   811,   147,   624,
     286,   452,   455,   286,  1331,  1332,  1333,  1334,   286,   286,
     454,   332,   151,  2095,   539,   540,   730,   731,  1464,  1312,
    1466,   622,   623,   341,   622,   623,  1729,  1531,  1532,   296,
     154,  1040,   297,   115,  1800,   298,  1711,   299,   622,   623,
     633,   152,  1832,   488,   634,  1948,   432,   433,    45,   115,
     115,   157,  1312,   319,   321,  1428,   324,  1468,   502,  1949,
     115,   115,   286,  1058,  1059,   153,  1151,   409,   999,  2008,
     115,   649,   155,   650,   767,  1354,   286,   143,   156,   286,
     564,   342,   366,   811,  1335,   432,   433,   158,   743,   563,
     744,   115,  -556,  1322,   745,   286,   286,   411,   544,   286,
     286,   286,   286,   149,   428,   429,   430,   431,   567,  2124,
     421,   121,   286,  1266,   422,   760,   286,   761,   368,   159,
     734,   762,   735,  2046,  1313,  1316,   177,   181,   432,   433,
     370,   195,   769,   926,   761,   928,   929,  1315,   770,   165,
     286,   166,   286,   286,   286,   432,   433,   165,   589,   166,
     590,  1141,   942,   160,   591,   622,   623,   161,   724,   286,
     428,   429,   430,   431,   173,   286,   622,   623,   300,  1359,
     961,   432,   433,   174,   589,   863,   590,   811,   432,   433,
     591,   714,   175,   715,   432,   433,  1980,   716,   622,   623,
     335,  2119,   336,   979,  1981,   853,  1058,  1059,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   622,   623,   622,   623,
     587,   622,   623,   454,   286,   178,  1828,   873,   286,   286,
     192,   811,  1015,   428,   429,   430,   431,  1950,  1455,  1951,
     428,   429,   430,   431,   286,   428,   429,   430,  1041,   440,
     734,   746,   735,   736,   440,   440,  1220,   432,   433,   622,
     623,   179,   440,  2147,   432,   433,   428,   429,   430,   431,
     445,   717,  1290,   780,  1221,  1291,  1415,   734,  1416,   735,
    1952,   182,  1222,  1223,  1224,  1161,   869,  1220,  1225,  1226,
     165,  1426,   166,   193,   622,   623,   440,   622,   623,  1168,
     617,   618,   286,   183,  1220,  1221,   622,   623,   626,   631,
     625,   440,   184,  1222,  1223,  1224,  2186,   185,  1953,  1225,
    1226,  2004,  1221,   186,   622,   623,   286,  2080,   432,   433,
    1222,  1223,  1224,   286,   843,  -558,  1225,  1226,   454,   987,
     454,   286,   454,   454,   460,  2081,   622,   623,   908,   859,
     538,   187,   811,   286,   286,   286,   454,   454,   286,   164,
     909,   164,   632,   286,   811,   547,   548,  1851,   868,   526,
     870,   527,  1676,   622,   623,   622,   623,   622,   623,   622,
     623,   622,   623,  1344,   188,  1298,   847,  -559,   849,   286,
     851,   852,   622,   623,  2082,   900,  2083,   189,  2084,  1035,
    2131,  1513,  2132,  2134,   865,   866,   190,  1517,    66,    67,
      68,    69,   191,  2141,    72,   286,   286,   622,   623,   194,
    2172,   622,   623,    81,   196,   197,    84,  1002,   198,   315,
     316,   199,   432,   433,   446,   446,   432,   433,  2170,  -563,
    1480,   317,  2171,   301,   200,   318,   302,  1209,   303,   568,
     952,   165,  1552,   166,   811,   315,   316,  1167,  1019,   304,
    1168,   202,   811,   286,   286,   286,  1568,   317,   671,   203,
     143,   323,  1573,   580,   581,   711,   583,   584,   585,   586,
     293,   622,   623,   294,   587,   295,   460,   454,   460,   454,
     454,   454,   454,   454,   454,   287,   454,   454,   454,   454,
    1001,   288,   454,   454,   454,   164,  1007,   168,   289,   286,
     169,   585,   586,   170,  1006,   171,   734,   587,   735,  1089,
    1016,   734,  1053,   735,   440,   290,  1498,  1025,  1752,   767,
    1720,  1026,  -560,   286,   725,   986,  1653,   988,   989,   990,
     991,   992,   993,   286,   995,   996,   997,   998,   308,  1045,
    1003,  1004,  1005,  1659,  1660,   734,   754,   735,   711,   583,
     584,   585,   586,  1268,   309,   286,  1062,   587,   734,   314,
     735,   286,   334,  1183,   460,  1073,  1288,  1184,  1171,  1185,
     337,  1078,   811,   454,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,   734,  1204,   735,   338,   587,   811,   933,   934,
     811,   347,  1852,   618,  2009,  2010,   286,  1205,   286,   322,
    2011,   811,  1071,  1730,  2013,  2014,  1702,  1703,  1250,  1251,
    2011,  1080,   811,   811,  1252,  1739,  1294,   333,   811,   440,
     811,   440,  1325,   440,   440,   440,   811,   348,  1401,  1408,
    1201,   286,   811,   811,   353,  1425,  1433,   440,   440,   811,
     811,   286,  1297,   354,  1298,  2110,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   809,
     583,   584,   585,   586,  1638,  1448,  1639,  1564,   587,   811,
     734,   811,   735,  1719,   355,  1720,  1615,  1468,   361,   286,
     811,  1314,  1317,  1646,  1647,   362,  1736,   811,   811,   739,
    1737,  1759,   286,  1761,  1844,   811,  1890,   811,   811,  1907,
    1891,   286,   284,  1908,  2154,   373,   363,  1931,  1932,  1947,
     286,   811,   811,  1891,   364,  1813,  1977,  1814,   754,   371,
     767,  1468,   372,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,   754,   374,   375,   405,   587,  1318,  1499,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,   734,  1986,   735,   905,   587,  1987,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   416,   440,   440,   440,
     440,   423,  2002,   440,   440,   440,  1891,  2006,  2007,   424,
    2035,   811,   811,   754,   811,  2055,   754,  2056,  2063,   811,
    2071,   811,  1891,  2079,   811,  2093,  1538,   811,   754,  1891,
    2130,  2137,  2138,   286,   811,   811,   811,  2139,  2140,  2142,
     417,   811,   811,   811,  1324,   450,  2144,   449,   143,   286,
    1987,  1427,  1429,  2165,   464,  2173,   466,  1891,  1052,   811,
    1054,  2183,   286,  1824,  1825,  2184,  2194,   454,  2197,   468,
    1891,   501,  2198,   469,   470,   440,   471,   476,   480,   494,
     534,  -194,   537,  -195,   440,   499,  -196,   545,   546,   549,
     552,   553,   554,   565,   597,   598,   611,   419,   286,   286,
     605,   286,   286,   286,   608,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,  1353,  1212,   286,   613,   615,
     616,   635,   636,  1218,   284,   637,   638,  1229,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,   639,   640,   651,   641,
     587,   654,   647,   655,   656,   286,   454,   454,   652,   661,
     666,   600,   657,   658,   659,   662,   663,   667,   674,   673,
     682,   683,   684,   695,   607,   696,   698,   700,   612,   286,
     699,   701,   703,   777,   702,   704,   706,   707,   723,   726,
     733,   738,   740,   741,   142,   286,   286,   286,   747,   756,
     781,   786,   802,   807,  1406,  1407,   813,   814,   815,   844,
     854,   587,  1427,  1429,   874,   855,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,   754,   856,   754,   754,   587,   877,
    1723,  1735,   876,   903,  1725,   913,   917,   914,   765,   286,
     754,   446,   920,   924,   925,   927,   954,   956,   973,   957,
     959,   968,   977,   980,   286,   286,   286,  1009,  1011,   754,
    1018,  1024,  1394,  1028,  1036,   286,  1376,  1029,  1037,  1038,
     454,  1049,  1050,  1065,   454,  1055,  1067,   754,  1070,  1077,
     721,   722,  1079,   454,  1082,   454,  1083,  1578,   454,  1583,
    1482,  1110,  1090,  1091,  1092,  1094,   732,  1095,  1096,  1098,
    1099,  1100,  1101,   286,  1102,  1103,  1104,  1105,  1106,  1107,
    1114,  1139,  1140,   754,  1148,  1149,  1150,  1157,  1505,   368,
    1160,  1166,  1507,  1172,  1176,  2017,  1175,  1180,  1188,  1189,
    1190,  1511,  1196,  1512,  1207,  1198,  1514,  1215,  1216,  1219,
     454,  1241,  1242,  1244,  1260,   286,  1257,   286,  1258,  1259,
    1271,  1272,  1273,  1276,  1284,  1286,  1287,  1293,   440,  1296,
    1299,  1300,  1301,   286,  1302,  1305,  1306,  1307,  1311,  1320,
    1321,  1326,  1327,  1341,  1347,  1348,   286,  1349,  1355,  1350,
     286,  1358,  1361,  1366,  1362,  1379,  -197,  1383,  1554,  1395,
    1731,  1744,  1744,   850,  1419,  1411,  1437,  1438,  1439,  1442,
    1444,  1443,  1445,  1446,  1447,   600,  1449,   864,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,  1456,  1457,  1460,  1462,
     587,  1879,  1461,  1472,   286,   286,   286,  1471,  1473,  1718,
    1474,  1475,   286,  1476,  1477,  1478,  1479,   440,   440,  1483,
    1484,  1485,  1486,  1487,  1488,  1489,  1490,   286,  1495,  1503,
    1508,  1509,  1515,  1518,  1516,  1526,  1520,  1524,   286,  1529,
    1534,  1535,  1541,  1537,  1540,  1545,   286,  1549,  1551,  1547,
     286,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,  1772,
    1548,  1805,  1563,   587,  1565,  1569,  1571,   754,  1587,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,  1592,  1585,  1594,
    1598,   587,  1586,  1599,   368,  1600,  1605,  1606,  1607,  1608,
     460,   460,  1609,  1610,  1611,  1612,   286,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,  1613,   454,  1614,  1624,   587,  1631,  1635,
    1641,   440,  1658,   286,  1645,   440,  1651,  1652,   286,  1656,
    1672,  1667,  1657,  1819,   440,  1030,   440,  1523,  1882,   440,
    1664,  1673,  1665,  1688,  1693,  1666,  1679,  1694,  1519,  1680,
    1681,  1682,  1695,  1683,  1684,  1699,  1687,  1700,  1690,  1701,
    1727,  1705,  1764,  1805,  1708,  1291,  1715,  1722,  1733,  1746,
    1753,  1726,  1732,  1754,  1751,  1756,  1856,  1758,  1762,  1763,
    1766,  1765,  1769,  1861,  1864,  1773,  1779,  1780,  1781,  1782,
    1784,   440,  1785,  1786,  1787,  1675,  1791,  1792,  1536,  1793,
     286,  1168,  1873,   286,   286,  2023,  1794,  1799,  1806,  1807,
    1808,  1810,  1829,  1833,   446,   446,  1834,  2040,  1843,  1847,
    1865,  1866,  1867,  1875,  1876,  1878,   286,  1883,   767,  1895,
    -561,  1896,   286,  1897,  1898,  1902,  1912,  1905,  1910,  1911,
    1916,  1944,   286,  1913,  1914,  1915,  1928,  1922,  1929,  1935,
    1942,  1954,   454,  1930,  1936,   454,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,  1956,  1945,   286,  1938,   587,  1939,  1961,  1962,  1968,
    1324,  1971,  1974,  1969,   368,  1970,   286,   460,  1973,  1975,
    1976,  1978,  1979,  1984,  2001,  2020,  2021,  2025,  2088,  2037,
    1857,  2038,  2036,  1859,  2039,  2047,  -562,  2041,  2050,  2051,
    2054,  2058,  2060,  1668,  2067,  2070,  2062,  2064,  2068,  2074,
    1783,   460,  2072,  1195,  2078,  2075,  2086,  2087,  2089,  2102,
    2090,  2107,  2112,  2097,  2155,  2156,  2157,  2158,  2111,  2160,
    1966,   286,  2161,  2162,  2126,  2143,  2163,  2166,  2177,  2178,
    2182,  2185,  2190,   286,   286,  2195,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,  2196,  2199,   286,  2200,   587,  1567,
    2120,  1627,  1996,   776,  1965,  1809,  1778,  1992,   286,  1596,
     120,   440,   440,   131,   132,   133,   916,  2015,   139,  1717,
    1877,   286,  1745,  1862,  1072,     0,  1836,  1837,  1838,  1839,
    1840,  1842,     0,  1724,     0,   440,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,  1308,     0,     0,   286,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1328,   286,     0,     0,     0,     0,  1997,     0,     0,
     286,   286,     0,     0,     0,     0,     0,     0,     0,     0,
    1728,     0,     0,     0,     0,     0,     0,   286,     0,     0,
     286,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       0,   286,     0,     0,     0,   286,     0,     0,     0,     0,
    1377,  1378,     0,  1380,  1381,  1382,     0,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,  1391,  1392,  1393,     0,     0,     0,
     368,     0,     0,     0,     0,     0,  2096,     0,     0,     0,
       0,   286,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,   440,   587,     0,   440,  1405,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   754,     0,   754,     0,     0,     0,     0,     0,     0,
       0,  1420,     0,     0,     0,     0,     0,     0,   440,     0,
       0,     0,     0,     0,     0,     0,     0,  1434,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,     0,     0,     0,     0,   286,   286,   286,
     286,   286,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,  1481,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1492,  1493,  1494,     0,
    1734,   286,     0,     0,     0,  2027,  2028,  2029,  2030,  2031,
       0,     0,     0,     0,     0,     0,     0,     0,   286,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
     454,   587,     0,     0,     0,  1525,     0,     0,     0,     0,
       0,     0,     0,     0,   286,     0,     0,     0,     0,     0,
       0,   454,   454,     0,     0,     0,  2065,     0,     0,     0,
    2069,     0,     0,     0,     0,   454,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2175,     0,
     414,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1582,     0,     0,     0,  2191,
    2193,     0,     0,     0,     0,     0,     0,   441,  1597,     0,
    2103,   451,  1601,  2201,  2105,   456,     0,     0,     0,     0,
       0,     0,     0,   461,     0,     0,     0,     0,     0,     0,
    2117,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   475,     0,   477,   478,   479,     0,   481,   482,   483,
     484,   485,   486,   487,     0,   489,   490,   491,   492,     0,
       0,     0,   496,     0,     0,     0,  1648,  1649,  1650,     0,
       0,     0,     0,     0,  1655,     0,     0,  2152,  2153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1670,
       0,   754,     0,     0,     0,     0,     0,     0,     0,     0,
    1678,     0,     0,     0,     0,     0,     0,     0,  1686,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,   555,   557,   559,   560,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   496,   496,   754,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   610,     0,     0,     0,     0,  1750,   754,
       0,     0,     0,   620,   621,     0,     0,     0,     0,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   496,
     643,     0,     0,     0,     0,  1771,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   664,   496,     0,     0,     0,   668,   669,
     670,   440,   672,     0,     0,     0,   675,   676,   677,     0,
       0,   678,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   710,
       0,     0,  1812,   496,   719,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     727,   728,     0,     0,     0,     0,     0,     0,  1750,     0,
       0,     0,     0,     0,     0,   755,  1846,     0,     0,     0,
       0,     0,     0,     0,  1848,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   782,   783,   784,   785,     0,     0,
       0,     0,   790,     0,     0,     0,   794,     0,     0,     0,
       0,     0,     0,     0,     0,  1872,     0,     0,     0,     0,
     808,   557,     0,     0,     0,   812,     0,     0,  1881,   816,
     817,   818,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   834,   835,   836,   837,
     838,   839,   840,   840,     0,   845,   846,     0,   848,     0,
       0,     0,     0,     0,     0,     0,     0,   857,     0,     0,
     861,   862,     0,     0,     0,     0,     0,   840,     0,     0,
       0,     0,   496,  1750,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   878,   879,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   890,   891,   893,   895,
     896,   897,   898,   899,     0,   901,   902,     0,  1943,     0,
       0,     0,  1934,   910,   911,   912,     0,     0,     0,     0,
       0,   918,   919,     0,   496,   496,     0,     0,   498,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   555,   710,   938,     0,     0,     0,   943,
     944,   945,   946,   947,   948,   949,   950,   951,     0,  1960,
       0,     0,     0,   958,     0,   960,     0,     0,   962,     0,
    1985,     0,   496,   496,   496,   967,     0,   969,   970,   971,
       0,     0,     0,     0,  1993,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,   994,     0,     0,   587,     0,  1750,
       0,     0,     0,     0,     0,     0,     0,     0,   496,     0,
     595,   596,     0,  2022,     0,  1013,     0,  1014,     0,     0,
     901,   902,     0,     0,     0,     0,     0,   497,     0,  1027,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   496,     0,  1043,     0,     0,     0,     0,  1046,
    1047,     0,     0,  1750,     0,   642,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,  1063,  1064,     0,     0,
     496,  1069,     0,     0,     0,  1063,     0,  1076,     0,     0,
    2066,     0,     0,  1081,     0,     0,     0,  1084,  1972,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     558,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,     0,   893,     0,  1111,     0,   497,
     497,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,   718,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     496,  1153,  1154,     0,   497,     0,     0,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,   497,
     587,     0,     0,  1750,     0,     0,     0,     0,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,  1194,
       0,     0,     0,  1200,     0,     0,     0,     0,     0,   496,
       0,     0,     0,     0,     0,     0,     0,  1213,  1214,     0,
       0,     0,     0,  1217,     0,     0,  1750,     0,   497,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1243,     0,     0,  1245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   871,  2085,
       0,     0,     0,     0,  1261,     0,  1263,  1264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1282,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,  2053,   558,     0,  1304,   587,
     921,   922,     0,     0,     0,  1310,     0,     0,     0,     0,
    1319,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     833,     0,     0,     0,     0,  1345,  1346,   841,   842,     0,
       0,   496,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   964,   965,
     966,     0,   867,     0,     0,     0,     0,   497,     0,     0,
       0,  1371,  1372,  1373,  1374,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,   894,     0,     0,   496,   587,     0,   734,
       0,   735,     0,     0,  1008,     0,     0,  1706,     0,     0,
       0,     0,  1397,     0,     0,     0,     0,     0,     0,   497,
     497,     0,  1398,  1399,  1400,     0,     0,     0,     0,  1402,
    1403,     0,  1404,     0,     0,     0,     0,     0,  1039,     0,
       0,     0,     0,     0,     0,     0,  1413,  1414,  2133,     0,
       0,     0,     0,     0,  1417,  1418,     0,     0,     0,     0,
    1061,  1422,     0,  1423,  1424,     0,  1068,   497,   497,   497,
    1430,  1431,     0,     0,     0,   496,   496,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,  1459,     0,     0,
       0,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,  1491,     0,     0,   587,  1142,   497,     0,     0,
       0,     0,     0,     0,   496,     0,  1152,     0,     0,     0,
       0,     0,  1506,     0,     0,     0,     0,     0,     0,   497,
       0,     0,     0,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,  1430,  1431,     0,     0,     0,  1522,     0,
       0,     0,     0,     0,  1179,     0,     0,     0,     0,  1528,
       0,     0,  1533,     0,     0,     0,     0,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1909,   568,     0,
     894,     0,  1112,     0,     0,  1206,     0,     0,     0,     0,
    1555,     0,     0,  1558,   496,  1561,   496,     0,     0,     0,
       0,     0,     0,     0,  1570,     0,  1572,     0,  1570,  1575,
    1577,     0,     0,     0,     0,   497,     0,     0,     0,     0,
       0,     0,     0,   162,   376,   497,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,   377,   378,   379,   380,   381,
     382,   383,   384,   385,     0,     0,   497,     0,   386,   387,
     388,   389,     0,     0,     0,     0,   390,   391,   392,     0,
    1654,     0,     0,   393,   497,   394,     0,  1661,  1662,  1663,
       0,     0,     0,     0,     0,     0,  1669,     0,  1671,   395,
       0,     0,   396,     0,     0,  1674,   296,  1352,     0,   297,
       0,     0,   298,     0,   299,     0,     0,     0,     0,   496,
       0,     0,     0,     0,  1691,    45,     0,     0,     0,     0,
       0,     0,  1696,  1697,  1698,     0,     0,     0,     0,     0,
       0,     0,   426,     0,  1709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1721,     0,     0,     0,     0,     0,
       0,     0,  1396,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1738,     0,     0,
       0,     0,     0,  1747,  1748,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   809,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,   397,   398,   399,     0,     0,   497,  1776,     0,     0,
       0,     0,   400,     0,     0,     0,   401,     0,   402,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1435,  1436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   433,     0,  1795,  1796,  1797,
       0,  -557,     0,  1553,     0,     0,     0,     0,  1798,     0,
       0,   497,     0,  1801,  1802,  1803,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1811,     0,     0,
       0,     0,   496,   496,  1817,     0,  1818,     0,     0,     0,
       0,     0,  1826,  1827,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1504,   496,     0,     0,     0,     0,  1845,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,  1855,
       0,     0,  1858,     0,     0,     0,  1860,     0,     0,     0,
     497,   497,     0,     0,     0,  1802,  1803,     0,  1869,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1887,     0,     0,     0,     0,  1893,  1894,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1560,  1899,  1562,   737,  1900,  1899,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,   497,
       0,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,   496,   496,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,  1937,
       0,     0,     0,     0,     0,     0,     0,     0,  1946,     0,
       0,     0,    78,     0,     0,     0,     0,   557,     0,     0,
       0,     0,     0,     0,     0,     0,  1957,  1958,     0,     0,
     496,     0,     0,     0,     0,     0,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   858,     0,     0,   497,
       0,   497,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,  1982,  1983,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1689,     0,     0,     0,     0,
       0,     0,     0,     0,  1995,     0,     0,     0,     0,   496,
     496,  2000,     0,     0,     0,     0,  2003,   906,     0,  2005,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   496,
       0,   939,     0,  1440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   496,     0,     0,     0,     0,     0,
       0,     0,  2032,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,  2043,     0,    42,
      43,    44,    45,  2048,     0,    47,  2049,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,   497,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2073,     0,     0,     0,     0,
      78,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
    2091,  2092,     0,   587,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,  2098,  2099,     0,  2100,   496,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1815,  1816,
       0,  2109,     0,     0,     0,     0,   496,   496,   496,   496,
     496,     0,     0,     0,     0,     0,  1893,     0,     0,     0,
    2125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1777,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2146,   963,
       0,     0,     0,  2149,  2150,  2151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   496,     0,     0,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,     0,  1127,  1128,  1129,  1130,     0,  1132,  1133,  1134,
    1135,   568,     0,     0,     0,  2179,  2180,  2181,     0,     0,
       0,  1145,     0,  1147,     0,     0,     0,   497,   497,     0,
       0,     0,     0,  1156,     0,     0,     0,     0,     0,     0,
    1162,  1163,     0,     0,     0,     0,     0,     0,     0,  1174,
       0,     0,     0,     0,     0,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   162,  1926,  1927,
       0,     0,     0,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   412,   226,   227,   228,   229,
     230,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1959,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,  1267,
    1269,  1270,     0,     0,     0,  1274,  1275,     0,     0,  1278,
    1279,  1280,  1281,     0,  1283,  1998,  1999,   497,   497,  1289,
       0,     0,   167,     0,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2016,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2026,     0,   558,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   497,     0,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,  1370,     0,
       0,     0,     0,  1375,   259,     0,     0,     0,   260,     0,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,   497,   497,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   439,   268,
     413,     0,     0,     0,   497,     0,   270,     0,     0,     0,
       0,   357,     0,     0,     0,   609,     0,     0,   273,   497,
       0,     0,     0,     0,  2101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2113,  2114,  2115,  2116,  2118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1432,     0,     0,     0,     0,     0,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   528,
     529,   530,   531,   532,   533,     0,   535,   536,     0,     0,
       0,     0,     0,  2159,     0,   541,   542,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   550,   551,     0,
     162,   376,   568,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   497,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   497,   497,   497,   497,   497,     0,     0,     0,     0,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   981,     0,     0,     0,   386,   387,   388,   389,     0,
       0,     0,     0,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   394,     0,     0,     0,     0,     0,     0,  1542,
       0,     0,     0,     0,     0,     0,   395,     0,     0,   396,
       0,     0,   497,   296,     0,     0,   297,     0,     0,   298,
       0,   299,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,   679,   680,   681,     0,     0,  1579,
     685,   686,   687,   688,   689,   690,   691,     0,   692,   426,
       0,     0,   693,   694,     0,     0,   697,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   709,
       0,  1616,  1617,  1618,  1619,  1620,     0,     0,     0,     0,
    1625,  1626,     0,     0,     0,     0,  1628,     0,  1630,     0,
       0,     0,  1634,     0,     0,  1636,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   397,   398,
     399,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,   401,     0,   402,   115,     0,     0,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   809,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,   734,     0,   735,  1740,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1704,     0,
    1707,     0,     0,     0,  1714,     0,  1716,     0,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,  1741,     0,     0,
       0,   875,   204,     6,   376,     0,     0,     0,     0,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,  1580,   378,   379,   380,   381,
     382,   383,   384,   385,   237,   238,   239,   240,   386,   387,
     388,   389,   241,   242,     0,     0,   390,   391,   392,     0,
       0,   243,   244,   393,     0,   394,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,   395,
     249,     0,   396,     0,  1804,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,  1177,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1884,     0,     0,  1885,
     259,   397,   398,   399,   260,   261,     0,     0,     0,   262,
     263,   264,   400,   265,   266,   267,   401,     0,   402,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   357,     0,  1918,
    1919,  1581,  1921,     0,   273,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,    42,    43,    44,
      45,     0,     0,    47,     0,     0,     0,     0,     0,     0,
     748,    54,     0,     0,    57,   749,     0,   750,   751,  1178,
     752,     0,     0,     0,     0,     0,     0,  1169,     0,     0,
       0,     0,  1963,  1964,     0,     0,     0,     0,    78,     0,
       0,     0,     0,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,  1186,    92,    93,    94,   587,     0,     0,     0,   204,
       6,   376,     0,     0,     0,     0,   205,   206,   207,     0,
    1994,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   237,   238,   239,   240,   386,   387,   388,   389,   241,
     242,     0,     0,   390,   391,   392,     0,  1010,   243,   244,
     393,     0,   394,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   248,    24,   395,   249,     0,   396,
       0,     0,     0,   250,     0,     0,   251,     0,     0,   252,
       0,   253,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,    55,    56,     0,   256,     0,   257,
       0,     0,   258,     0,     0,     0,     0,     0,    66,    67,
      68,    69,    70,     0,    72,    73,    74,    75,    76,    77,
       0,     0,     0,    81,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,  1365,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   397,   398,
     399,   260,   261,  1497,     0,     0,   262,   263,   264,   400,
     265,   266,   267,   401,     0,   402,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   269,     0,     0,     0,     0,     0,   270,
       0,     0,     0,     0,   357,     0,     0,     0,   272,     0,
       0,   273,     0,     0,  2168,   204,   162,   376,     0,   425,
    1421,     0,   205,   206,   207,     0,     0,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   412,   226,   227,   228,   229,   230,
     231,     0,     0,     0,     0,     0,     0,     0,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   237,   238,   239,
     240,   386,   387,   388,   389,   241,     0,     0,     0,   390,
     391,   392,     0,     0,     0,     0,   393,     0,   394,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
     248,    24,   395,   249,     0,   396,     0,     0,     0,   296,
       0,     0,   297,     0,     0,   298,     0,   299,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   426,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
     972,     0,     0,  1543,  1544,     0,     0,     0,   931,     0,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,   427,     0,     0,     0,
       0,     0,     0,   259,   397,   398,   399,   260,     0,     0,
       0,     0,   262,   263,   264,   400,   265,   266,   267,   401,
       0,   402,   115,   428,   429,   430,   431,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   413,
       0,     0,     0,     0,     0,   270,     0,   432,   433,     0,
     434,     0,   435,  1632,     0,     0,   436,   273,   204,     6,
     356,     0,     0,  1640,     0,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,     0,  1774,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1822,     0,     0,     0,
    1823,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   269,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,   204,     6,     0,   358,     0,   665,
     273,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,   244,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,    55,
      56,     0,   256,     0,   257,     0,     0,   258,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,    81,     0,
       0,    84,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1849,     0,     0,     0,  1850,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,   261,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   495,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   357,
     204,     6,  1677,     0,   561,     0,   273,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,     0,
       0,     0,     0,     0,   250,     0,     0,   251,     0,     0,
     252,     0,   253,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,    55,    56,     0,   256,     0,
     257,     0,     0,   258,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  2018,     0,     0,     0,
    2019,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   269,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,   272,
       0,     0,   273,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,   244,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   253,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,    55,    56,     0,   256,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,    76,    77,     0,     0,     0,
      81,     0,     0,    84,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   771,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,   261,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   627,
    1841,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   629,   204,     6,     0,   318,   561,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,   244,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   931,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,   261,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   271,   204,     6,
       0,   272,     0,     0,   273,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   932,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   269,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,   204,     6,     0,   272,     0,     0,
     273,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,   244,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,    55,
      56,     0,   256,     0,   257,     0,     0,   258,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,    81,     0,
       0,    84,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   978,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,   261,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   495,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   357,
     204,     6,     0,   556,     0,     0,   273,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,     0,
       0,     0,     0,     0,   250,     0,     0,   251,     0,     0,
     252,     0,   253,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   255,     0,    55,    56,     0,   256,     0,
     257,     0,     0,   258,     0,     0,     0,     0,     0,    66,
      67,    68,    69,    70,     0,    72,    73,    74,    75,    76,
      77,     0,     0,     0,    81,     0,     0,    84,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1085,     0,     0,     0,     0,     0,     0,     0,   259,     0,
       0,     0,   260,   261,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   495,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,     6,     0,     0,
     561,     0,   273,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,   244,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   253,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,    55,    56,     0,   256,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,    76,    77,     0,     0,     0,
      81,     0,     0,    84,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1086,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,   261,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     269,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   599,   204,     6,     0,   272,     0,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,   244,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,   261,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   268,   269,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   606,   204,     6,
       0,   272,     0,     0,   273,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1088,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   495,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   357,   204,     6,     0,   892,     0,  1351,
     273,   205,   206,   207,     0,     0,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,   244,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,     0,     0,     0,     0,   250,     0,
       0,   251,     0,     0,   252,     0,   253,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,    55,
      56,     0,   256,     0,   257,     0,     0,   258,     0,     0,
       0,     0,     0,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,    76,    77,     0,     0,     0,    81,     0,
       0,    84,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1126,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,   261,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   495,     0,
       0,     0,     0,     0,   270,   204,     6,     0,     0,   357,
    1559,     0,   205,   206,   207,     0,   273,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,   238,   239,
     240,     0,     0,     0,     0,   241,   242,     0,     0,     0,
       0,     0,     0,     0,   243,   244,     0,     0,     0,   245,
     246,   247,     0,     0,     0,     0,     0,     0,     0,     0,
     248,    24,     0,   249,     0,     0,     0,     0,     0,   250,
       0,     0,   251,     0,     0,   252,     0,   253,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,   254,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,     0,
      55,    56,     0,   256,     0,   257,     0,     0,   258,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,    76,    77,     0,     0,     0,    81,
       0,     0,    84,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1136,     0,     0,     0,     0,
       0,     0,     0,   259,     0,     0,     0,   260,   261,     0,
       0,     0,   262,   263,   264,     0,   265,   266,   267,     0,
       0,     0,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   268,   495,
       0,     0,     0,     0,     0,   270,   204,     6,     0,     0,
     357,     0,     0,   205,   206,   207,     0,   273,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     0,     0,     0,     0,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,   244,     0,     0,     0,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,     0,   249,     0,     0,     0,     0,     0,
     250,     0,     0,   251,     0,     0,   252,     0,   253,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   255,
       0,    55,    56,     0,   256,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,    76,    77,     0,     0,     0,
      81,     0,     0,    84,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1137,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,     0,   260,   261,
       0,     0,     0,   262,   263,   264,     0,   265,   266,   267,
       0,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     269,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   357,   204,     6,     0,  1685,     0,     0,   273,   205,
     206,   207,     0,     0,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,   244,     0,     0,     0,   245,   246,   247,     0,
       0,     0,     0,     0,     0,     0,     0,   248,    24,     0,
     249,     0,     0,     0,     0,     0,   250,     0,     0,   251,
       0,     0,   252,     0,   253,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,    55,    56,     0,
     256,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,    72,    73,    74,
      75,    76,    77,     0,     0,     0,    81,     0,     0,    84,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1138,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,     0,   260,   261,     0,     0,     0,   262,
     263,   264,     0,   265,   266,   267,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   627,  1841,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,   629,   204,     6,
       0,   318,     0,     0,   273,   205,   206,   207,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,   244,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
       0,     0,     0,   248,    24,     0,   249,     0,     0,     0,
       0,     0,   250,     0,     0,   251,     0,     0,   252,     0,
     253,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,    55,    56,     0,   256,     0,   257,     0,
       0,   258,     0,     0,     0,     0,     0,    66,    67,    68,
      69,    70,     0,    72,    73,    74,    75,    76,    77,     0,
       0,     0,    81,     0,     0,    84,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1143,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,     0,
     260,   261,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   268,   495,     0,     0,     0,     0,     0,   270,   204,
     162,   376,     0,   357,     0,     0,   205,   206,   207,     0,
     273,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   412,   226,
     227,   228,   229,   230,   231,     0,     0,     0,     0,     0,
       0,     0,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   237,   238,   239,   240,   386,   387,   388,   389,   241,
       0,     0,     0,   390,   391,   392,     0,     0,     0,     0,
     393,     0,   394,   245,   246,   247,     0,     0,     0,     0,
       0,     0,     0,     0,   248,    24,   395,   249,     0,   396,
     204,   162,   376,     0,     0,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   237,   238,   239,   240,   386,   387,   388,   389,
     241,     0,     0,     0,   390,   391,   392,     0,     0,     0,
       0,   393,     0,   394,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,   395,   249,     0,
     396,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   397,   398,
     399,   260,     0,     0,     0,     0,   262,   263,   264,   400,
     265,   266,   267,   401,     0,   402,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   268,   413,     0,     0,     0,     0,     0,   270,
       0,     0,     0,     0,   357,     0,     0,     0,  1576,     0,
       0,   273,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1144,     0,     0,     0,   259,   397,
     398,   399,   260,     0,     0,     0,     0,   262,   263,   264,
     400,   265,   266,   267,   401,     0,   402,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,   357,   204,   162,   376,  1854,
       0,     0,   273,   205,   206,   207,     0,     0,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   412,   226,   227,   228,   229,
     230,   231,     0,     0,     0,     0,     0,     0,     0,  1580,
     378,   379,   380,   381,   382,   383,   384,   385,   237,   238,
     239,   240,   386,   387,   388,   389,   241,     0,     0,     0,
     390,   391,   392,     0,     0,     0,     0,   393,     0,   394,
     245,   246,   247,     0,     0,     0,     0,     0,     0,     0,
       0,   248,    24,   395,   249,     0,   396,   204,   162,   376,
       0,     0,     0,     0,   205,   206,   207,     0,     0,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   412,   226,   227,   228,
     229,   230,   231,     0,     0,     0,     0,     0,     0,     0,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   237,
     238,   239,   240,   386,   387,   388,   389,   241,     0,     0,
       0,   390,   391,   392,     0,     0,     0,     0,   393,     0,
     394,   245,   246,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   248,    24,   395,   249,     0,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   397,   398,   399,   260,     0,
       0,     0,     0,   262,   263,   264,   400,   265,   266,   267,
     401,     0,   402,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   268,
     413,     0,     0,     0,     0,     0,   270,     0,     0,     0,
       0,   357,     0,     0,     0,  1740,     0,     0,   273,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1146,     0,     0,     0,   259,   397,   398,   399,   260,
       0,     0,     0,     0,   262,   263,   264,   400,   265,   266,
     267,   401,     0,   402,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     268,   413,     0,     0,     0,     0,     0,   270,   204,   162,
       0,     0,   357,     0,     0,   205,   206,   207,     0,   273,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   412,   226,   227,
     228,   229,   230,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,     0,     0,     0,     0,   241,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,     0,     0,     0,     0,     0,
     204,   162,     0,   248,    24,   860,   249,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,   259,     0,     0,     0,
     260,  1256,     0,     0,     0,   262,   263,   264,     0,   265,
     266,   267,     0,     0,     0,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   627,   628,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   629,     0,     0,     0,   318,     0,     0,
     273,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,   259,     0,
       0,     0,   260,  1277,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,   204,   162,     0,     0,   357,     0,     0,   205,   206,
     207,     0,   273,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
     204,   162,     0,  1303,     0,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,   259,
       0,   587,     0,   260,     0,     0,     0,     0,   262,   263,
     264,  1360,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,  1074,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1363,     0,   259,     0,
       0,     0,   260,     0,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,   204,   162,     0,  1458,   357,     0,     0,   205,   206,
     207,     0,   273,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    24,     0,   249,
     204,   162,     0,  1521,     0,     0,     0,   205,   206,   207,
       0,     0,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   412,
     226,   227,   228,   229,   230,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,    24,     0,   249,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,   259,
       0,   587,     0,   260,     0,     0,     0,     0,   262,   263,
     264,  1452,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1453,     0,   259,     0,
       0,     0,   260,     0,     0,     0,     0,   262,   263,   264,
       0,   265,   266,   267,     0,     0,     0,   115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   268,   413,     0,     0,     0,     0,     0,
     270,   204,   162,     0,     0,   357,     0,     0,   205,   206,
     207,     0,   273,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     412,   226,   227,   228,   229,   230,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,     0,     0,     0,
       0,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,     0,     0,   204,   162,     0,   248,    24,     0,   249,
     205,   206,   207,     0,     0,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   412,   226,   227,   228,   229,   230,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   237,   238,   239,   240,     0,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   245,   246,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,    24,
       0,   249,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,   259,
       0,     0,     0,   260,  1496,     0,     0,     0,   262,   263,
     264,     0,   265,   266,   267,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   413,     0,     0,     0,     0,
       0,   270,     0,     0,     0,     0,   357,  1574,     0,     0,
       0,     0,     0,   273,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,   259,     0,     0,     0,   260,  1621,     0,     0,     0,
     262,   263,   264,     0,   265,   266,   267,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   268,   413,     0,     0,
       0,     0,     0,   270,   204,   162,     0,     0,   357,  1901,
       0,   205,   206,   207,     0,   273,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   412,   226,   227,   228,   229,   230,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   376,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   248,
      24,     0,   249,     0,   377,   378,   379,   380,   381,   382,
     383,   384,   385,     0,     0,     0,     0,   386,   387,   388,
     389,     0,     0,     0,     0,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   394,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   395,     0,
       0,   396,     0,     0,     0,   296,     0,     0,   297,     0,
       0,   298,     0,   299,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,   260,     0,     0,     0,
       0,   262,   263,   264,     0,   265,   266,   267,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   268,   413,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   357,
     397,   398,   399,     7,     8,     0,   273,     0,     0,     0,
       0,   400,     0,     0,     0,   401,     0,   402,   115,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,    42,    43,    44,    45,     0,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
    1740,     0,    57,   749,     0,   750,   751,     0,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      92,    93,    94,    42,    43,    44,    45,     0,     0,    47,
       0,     0,     0,     0,     0,     0,   748,    54,     0,     0,
      57,   749,     0,   750,   751,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    92,    93,
      94,    42,    43,    44,    45,  1012,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    92,    93,    94,    42,
      43,    44,    45,  1208,     0,    47,     0,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    92,    93,    94,    42,    43,    44,
      45,  1210,     0,    47,     0,     0,     0,     0,     0,     0,
     748,    54,     0,     0,    57,   749,     0,   750,   751,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    92,    93,    94,    42,    43,    44,    45,  1211,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
       0,     0,    57,   749,     0,   750,   751,     0,   752,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      92,    93,    94,    42,    43,    44,    45,  1230,     0,    47,
       0,     0,     0,     0,     0,     0,   748,    54,     0,     0,
      57,   749,     0,   750,   751,     0,   752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    92,    93,
      94,    42,    43,    44,    45,  1248,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    92,    93,    94,    42,
      43,    44,    45,  1262,     0,    47,     0,     0,     0,     0,
       0,     0,   748,    54,     0,     0,    57,   749,     0,   750,
     751,     0,   752,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    92,    93,    94,    42,    43,    44,
      45,  1295,     0,    47,     0,     0,     0,     0,     0,     0,
     748,    54,     0,     0,    57,   749,     0,   750,   751,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    92,    93,    94,    42,    43,    44,    45,  1450,
       0,    47,     0,     0,     0,     0,     0,     0,   748,    54,
       0,     0,    57,   749,     0,   750,   751,     0,   752,     0,
       0,     0,     0,     0,    -4,     1,     0,     0,    -4,     0,
       0,     0,     0,     0,     0,     0,    78,    -4,    -4,     0,
       0,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
      92,    93,    94,   587,     0,     0,     0,  2076,    -4,    -4,
       0,     0,     0,  1622,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,    -4,     0,     0,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,    -4,     0,
      -4,    -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,     0,  2135,    -4,    -4,    -4,    -4,
      -4,    -4,     0,    -4,     0,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,     0,    -4,    -4,    -4,     0,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,     6,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,     7,     8,     0,
       0,    -4,    -4,    -4,    -4,     0,     0,    -4,     0,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     0,     0,     9,    10,
       0,    -4,    -4,    -4,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,     0,    -4,     0,     0,     0,    11,    12,
      13,     0,     0,     0,    14,    15,     0,     0,     0,    16,
       0,     0,     0,     0,    17,    18,    19,    20,    21,     0,
      22,    23,     0,    24,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,     0,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    63,    64,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,     0,     0,     0,    90,     0,     0,     0,
       0,    91,    92,    93,    94,   162,   376,    95,     0,    96,
       0,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   111,   112,   113,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,   115,     0,     0,   377,   378,   379,
     380,   381,   382,   383,   384,   385,     0,     0,     0,     0,
     386,   387,   388,   389,     0,   162,   376,     0,   390,   391,
     392,     0,     0,     0,     0,   393,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,     0,   396,     0,     0,     0,   296,     0,
       0,   297,     0,     0,   298,     0,   299,   377,   378,   379,
     380,   381,   382,   383,   384,   385,     0,    45,     0,     0,
     386,   387,   388,   389,   406,   376,     0,     0,   390,   391,
     392,     0,     0,     0,   426,   393,     0,   394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,     0,   396,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   377,   378,   379,   380,
     381,   382,   383,   384,   385,     0,     0,     0,     0,   386,
     387,   388,   389,   376,     0,     0,     0,   390,   391,   392,
       0,     0,     0,     0,   393,     0,   394,     0,     0,     0,
       0,     0,     0,   397,   398,   399,     0,     0,     0,     0,
     395,     0,     0,   396,   400,     0,     0,     0,   401,     0,
     402,   115,     0,     0,   377,   378,   379,   380,   381,   382,
     383,   384,   385,     0,     0,     0,     0,   386,   387,   388,
     389,     0,     0,     0,     0,   390,   391,   392,     0,     0,
       0,     0,   393,     0,   394,     0,     0,     0,     0,     0,
       0,     0,     0,   397,   398,   399,     0,     0,   395,     0,
       0,   396,     0,     0,   400,     0,     0,     0,   401,     0,
     402,   115,     0,     0,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     7,     8,  1623,     0,     0,     0,
       0,     0,   397,   398,   399,     0,     0,     0,     0,     0,
       0,     0,     0,   400,     0,     0,     0,   401,     0,   402,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1637,     0,     0,     0,     0,     0,     0,     0,
     397,   398,   399,     0,     0,     0,     0,     0,     0,     0,
       0,   400,     0,     0,     0,   401,     0,   402,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     7,     8,     0,    42,    43,    44,    45,     0,     0,
      47,     0,     0,     0,     0,     0,     0,   748,    54,     0,
       0,    57,   749,     0,   750,   751,     0,   752,     0,     0,
       0,  1021,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,  1022,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,    92,
      93,    94,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1768,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,    42,    43,    44,    45,     0,     0,    47,     0,     0,
       0,     0,     0,     0,   748,    54,     0,     0,    57,   749,
       0,   750,   751,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,    92,    93,    94,     0,
       0,     0,     0,     0,     0,  1888,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1889,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1920,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1923,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1990,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2044,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2045,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2059,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2061,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2094,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2122,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2127,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2128,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2129,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2169,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,   806,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  1056,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  1113,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  1158,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  1159,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1202,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1233,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  1253,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  1309,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  1329,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1409,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  1410,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  1454,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  1527,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  1770,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  1820,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    1831,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  1868,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  1940,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  1955,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  1967,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,     0,  2024,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,  2033,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,  2034,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
       0,     0,  2057,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
       0,  2108,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,     0,     0,
    2148,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,     0,     0,  2167,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,     0,     0,  2187,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,  2188,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,     0,     0,  2189,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,     0,   712,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,     0,   923,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,     0,
    1933,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,   734,     0,   735,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,   984,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,  1032,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,  1182,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,  1247,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,  1249,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,     0,     0,  1254,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   711,   583,   584,   585,   586,     0,     0,
       0,     0,   587,     0,     0,     0,  1255,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   580,   581,
     711,   583,   584,   585,   586,     0,     0,     0,     0,   587,
       0,     0,     0,  1343,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   711,   583,   584,
     585,   586,     0,     0,     0,     0,   587,     0,     0,     0,
    1357,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   711,   583,   584,   585,   586,     0,
       0,     0,     0,   587,     0,     0,     0,  1556,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,     0,     0,  1643,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   711,   583,
     584,   585,   586,     0,     0,     0,     0,   587,     0,     0,
       0,  1692,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   711,   583,   584,   585,   586,
       0,     0,     0,     0,   587,     0,     0,     0,  1880,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   711,   583,   584,   585,   586,     0,     0,     0,
       0,   587,     0,     0,     0,  1925,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   711,
     583,   584,   585,   586,     0,     0,     0,     0,   587,     0,
       0,     0,  1941,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   787,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   788,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   789,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   791,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   792,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   793,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   795,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   796,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   797,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   798,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   799,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   800,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   801,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   803,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   804,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   805,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   872,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   907,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   953,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   972,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   974,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   975,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   976,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,   982,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,   983,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1020,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1031,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1093,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1097,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1109,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1181,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1191,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1192,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1193,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1203,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1232,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1234,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1235,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1236,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1237,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1238,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1239,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1240,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1246,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1342,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1356,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1557,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1588,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1589,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1590,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1591,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1629,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1642,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1755,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1757,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1760,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1767,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1821,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1830,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1853,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1924,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  1988,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  1989,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587,     0,  2121,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   711,   583,   584,   585,
     586,     0,     0,     0,     0,   587,     0,  2164,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   711,   583,   584,   585,   586,     0,     0,     0,     0,
     587
};

static const yytype_int16 yycheck[] =
{
       3,   141,   154,     3,  1227,   311,  1416,     4,  1679,  1231,
       5,   193,   729,   624,   625,     4,  1723,   716,  1725,   201,
     737,    24,    61,     4,     4,     4,     0,     4,     6,   106,
      24,   108,     4,   323,     4,     4,   137,     4,     4,     9,
       5,     5,  1710,     6,     4,     6,   745,     6,   236,   237,
      53,     5,   342,     6,  1903,   103,     7,     4,     6,     6,
       6,   103,   249,   762,   141,     4,     9,   254,   137,   257,
      97,   770,     4,     4,   100,     4,     4,   103,   126,    82,
       7,   236,   237,     9,   126,   186,   155,    90,     7,   116,
     167,   251,    95,   158,   163,   164,   165,   257,     9,     9,
     169,   170,   257,   106,   100,    14,  1774,   103,    89,   236,
     237,   293,   294,   295,   249,     6,   236,   237,   183,   409,
     116,   411,   257,  1794,   252,     9,     6,   103,   256,   419,
     257,   137,     9,   249,   199,   200,     7,   257,   141,   106,
     107,   257,   142,   146,   147,   236,   237,     6,     6,   155,
      97,   154,   249,   335,   336,   337,   251,   163,   164,   165,
     257,     6,   257,   169,   170,   248,   257,   250,    97,   172,
     352,     8,   101,   236,   237,   874,   248,   248,   107,   108,
     252,   110,   111,   253,   253,   188,   141,   257,   248,   252,
     193,   146,   147,   196,   173,   174,   175,   176,   201,   202,
     203,   130,     6,  2052,   243,   244,   183,   184,   171,     7,
     171,   236,   237,   194,   236,   237,     7,   183,   184,    97,
     248,     7,   100,   220,  1634,   103,   198,   105,   236,   237,
     248,     6,   257,   188,   252,   257,   245,   246,   116,   220,
     220,   252,     7,    67,    68,   254,    70,  1470,   203,   257,
     220,   220,   255,   231,   232,     6,   249,   252,   255,  1930,
     220,   250,     6,   252,   257,   249,   269,   256,     6,   272,
     273,   252,   252,   257,   253,   245,   246,     6,   248,   273,
     250,   220,   252,   252,   254,   288,   289,   252,   252,   292,
     293,   294,   295,   252,   221,   222,   223,   224,   252,   252,
     248,     3,   305,   254,   252,   248,   309,   250,   311,     6,
     249,   254,   251,  1984,  1031,  1032,   248,   248,   245,   246,
     248,     6,   248,   613,   250,   615,   616,   254,   254,   248,
     333,   250,   335,   336,   337,   245,   246,   248,   248,   250,
     250,   251,   632,   250,   254,   236,   237,   250,   425,   352,
     221,   222,   223,   224,   248,   358,   236,   237,    60,   249,
     650,   245,   246,   248,   248,   547,   250,   257,   245,   246,
     254,   248,   248,   250,   245,   246,   249,   254,   236,   237,
     103,  2088,   105,   673,   257,   537,   231,   232,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   236,   237,   236,   237,
     247,   236,   237,   416,   417,   248,   253,   253,   421,   422,
     252,   257,   712,   221,   222,   223,   224,   257,   253,   257,
     221,   222,   223,   224,   437,   221,   222,   223,   224,   141,
     249,   444,   251,   252,   146,   147,   137,   245,   246,   236,
     237,   248,   154,  2124,   245,   246,   221,   222,   223,   224,
       4,   416,   254,   466,   155,   257,  1165,   249,  1167,   251,
     257,   248,   163,   164,   165,   257,   553,   137,   169,   170,
     248,  1180,   250,   118,   236,   237,   188,   236,   237,   257,
     314,   315,   495,   248,   137,   155,   236,   237,   322,   323,
     252,   203,   248,   163,   164,   165,  2177,   248,   257,   169,
     170,  1921,   155,   248,   236,   237,   519,   257,   245,   246,
     163,   164,   165,   526,   527,   252,   169,   170,   531,   681,
     533,   534,   535,   536,   537,   257,   236,   237,   253,   542,
     242,   248,   257,   546,   547,   548,   549,   550,   551,   552,
     253,   554,   252,   556,   257,   257,   258,     8,   552,   248,
     554,   250,   253,   236,   237,   236,   237,   236,   237,   236,
     237,   236,   237,   248,   248,   250,   531,   252,   533,   582,
     535,   536,   236,   237,   257,   588,   257,   248,   257,   729,
     257,  1290,   257,   253,   549,   550,   248,  1296,   142,   143,
     144,   145,   248,   257,   148,   608,   609,   236,   237,   103,
     253,   236,   237,   157,   252,    97,   160,   694,   100,   236,
     237,   103,   245,   246,   624,   625,   245,   246,   257,   252,
    1241,   248,   257,   100,   116,   252,   103,   927,   105,     8,
     253,   248,  1341,   250,   257,   236,   237,   254,   253,   116,
     257,   105,   257,   656,   657,   658,  1355,   248,   254,   248,
     256,   252,  1361,   236,   237,   238,   239,   240,   241,   242,
     100,   236,   237,   103,   247,   105,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   248,   689,   690,   691,   692,
     693,   252,   695,   696,   697,   698,   699,    97,   252,   702,
     100,   241,   242,   103,   698,   105,   249,   247,   251,   786,
     713,   249,   751,   251,   416,   103,     8,   253,   248,   257,
     250,   257,   252,   726,   426,   680,  1443,   682,   683,   684,
     685,   686,   687,   736,   689,   690,   691,   692,   248,   742,
     695,   696,   697,     6,     7,   249,   448,   251,   238,   239,
     240,   241,   242,   257,   100,   758,   759,   247,   249,   252,
     251,   764,   248,   903,   767,   768,   257,   248,   253,   250,
     103,   774,   257,   776,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   249,   253,   251,   100,   247,   257,   622,   623,
     257,   100,   253,   627,   142,   143,   809,   253,   811,   252,
     148,   257,   767,  1530,   142,   143,     6,     7,   253,   253,
     148,   776,   257,   257,   253,  1542,   253,   252,   257,   531,
     257,   533,   253,   535,   536,   537,   257,   103,   253,   253,
     917,   844,   257,   257,     4,   253,   253,   549,   550,   257,
     257,   854,   248,     4,   250,  2077,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   248,   253,   250,   253,   247,   257,
     249,   257,   251,   248,     4,   250,   253,  2110,     4,   892,
     257,  1031,  1032,   253,   253,   248,   253,   257,   257,     6,
     257,   253,   905,   253,   253,   257,   253,   257,   257,   253,
     257,   914,    53,   257,  2136,     6,   248,   253,   253,   253,
     923,   257,   257,   257,   248,     4,   253,     6,   630,   248,
     257,  2154,   248,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   653,     6,   250,   248,   247,  1033,   249,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   249,   253,   251,   252,   247,   257,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   250,   689,   690,   691,
     692,     6,   253,   695,   696,   697,   257,   253,   253,   256,
     253,   257,   257,   705,   257,   253,   708,   253,   253,   257,
     253,   257,   257,   253,   257,   253,  1322,   257,   720,   257,
     253,   253,   253,  1026,   257,   257,   257,   253,   253,   253,
     252,   257,   257,   257,  1037,     6,   253,   252,   256,  1042,
     257,  1181,  1182,   253,   248,   253,     9,   257,   750,   257,
     752,   253,  1055,  1664,  1665,   257,   253,  1060,   253,   248,
     257,   202,   257,   248,   248,   767,   248,   248,   248,   248,
     248,   186,   248,   186,   776,   252,   186,   252,   126,   248,
     248,   248,   248,   186,   248,   248,     4,   252,  1091,  1092,
     252,  1094,  1095,  1096,   252,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1060,   930,  1110,   252,   252,
     252,   248,   248,   937,   255,   248,   248,   941,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   248,   248,     6,   248,
     247,     6,   248,     6,   252,  1148,  1149,  1150,   250,   250,
       6,   292,   252,   252,   252,   250,   250,     6,   186,   252,
     248,   248,   248,   248,   305,   248,   248,     6,   309,  1172,
     250,     6,     6,    92,   252,     8,     6,     8,   252,     7,
       6,   252,   252,     6,   252,  1188,  1189,  1190,   253,     6,
     257,   257,   249,     7,  1149,  1150,     6,     6,   249,   252,
     252,   247,  1342,  1343,   254,   252,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   926,   252,   928,   929,   247,     8,
    1520,  1537,    64,     4,  1524,     7,   248,     7,   257,  1242,
     942,  1241,     6,   249,     6,   252,     7,     6,   253,     7,
       6,     6,   183,   252,  1257,  1258,  1259,   253,   253,   961,
     251,   249,     6,     6,   254,  1268,  1090,   252,     7,     6,
    1273,   250,   248,     4,  1277,   252,     6,   979,     6,     6,
     421,   422,     6,  1286,   249,  1288,   250,  1364,  1291,  1366,
       6,   252,     7,     7,     7,     7,   437,     7,     7,     7,
       7,     7,     7,  1306,     7,     7,     7,     7,     7,     7,
       6,   249,   251,  1015,   257,   257,   257,   253,  1273,  1322,
     257,   249,  1277,     7,   253,  1936,   252,   254,     7,   252,
     252,  1286,     4,  1288,   254,     6,  1291,   253,   253,   137,
    1343,   252,     7,     6,   254,  1348,     7,  1350,     7,     7,
     249,   249,   257,   257,     9,   257,   249,   251,  1060,   254,
     256,   186,     7,  1366,   158,   253,   252,     6,     6,     6,
       4,    46,    46,   254,   248,   252,  1379,   248,   254,   252,
    1383,   248,   254,     4,   248,     7,   186,     7,  1343,     7,
    1530,  1543,  1544,   534,   249,   257,     7,     7,     7,     6,
     257,   249,     7,     7,     7,   546,     4,   548,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   115,     4,   252,   248,
     247,  1737,     6,     6,  1437,  1438,  1439,     7,     7,  1516,
       7,     7,  1445,     7,     7,     7,     7,  1149,  1150,   252,
       6,     6,     6,   103,     7,     6,     6,  1460,     4,     4,
     255,   257,   249,   252,   257,   253,   252,   252,  1471,     6,
       6,     6,   250,     7,     6,     6,  1479,   252,     6,   248,
    1483,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,  1576,
     248,  1641,   253,   247,     6,   254,     6,  1209,     6,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     6,   251,   130,
       6,   247,   257,     6,  1537,     6,     6,     6,     6,     6,
    1543,  1544,     6,     6,     6,     6,  1549,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     6,  1567,     5,   249,   247,   249,     6,
       4,  1273,     7,  1576,     6,  1277,     4,     6,  1581,   252,
       6,   250,   252,  1660,  1286,   726,  1288,     6,  1740,  1291,
     252,     6,   252,     6,     6,   252,   252,     6,  1300,   252,
     252,   252,   182,   252,   252,     6,   253,     6,   252,     6,
       6,   257,  1567,  1753,   257,   257,   249,   252,     7,   248,
       4,   257,   254,     6,   252,     6,  1703,   253,     6,     6,
       4,   248,   248,  1710,  1711,     7,     6,     6,     6,     6,
       6,  1343,     6,     6,   137,  1469,   101,     6,     6,     5,
    1653,   257,  1729,  1656,  1657,  1945,   252,   249,   252,   252,
       6,     6,   257,     6,  1664,  1665,     6,  1973,     6,     6,
     257,   249,   257,     6,     4,     6,  1679,     6,   257,     6,
     252,     6,  1685,     6,     6,     6,     6,   252,     7,   141,
       5,     7,  1695,   252,   252,   252,     6,   249,     6,     6,
       6,     6,  1705,   252,   252,  1708,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   181,   252,  1726,   253,   247,   253,     6,   249,   253,
    1733,     6,     6,   253,  1737,   253,  1739,  1740,     7,   254,
       6,     6,     6,   252,     6,     6,   253,     6,  2038,     6,
    1705,   252,   249,  1708,     6,     6,   252,   184,   253,   253,
     248,   252,   249,     6,     6,     6,   252,   252,   252,     6,
    1594,  1774,   253,   914,   252,   137,     6,     6,     6,     6,
     252,     6,     6,   249,     6,     6,     6,     6,  2078,     6,
    1867,  1794,     6,     6,   253,   253,   252,     6,   252,     6,
       6,   252,     6,  1806,  1807,     6,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     6,     6,  1829,     6,   247,  1354,
    2090,  1411,  1909,   463,  1865,  1649,  1586,  1904,  1841,  1378,
       3,  1543,  1544,     3,     3,     3,   603,  1932,     3,  1513,
    1733,  1854,  1544,  1710,   767,    -1,  1680,  1681,  1682,  1683,
    1684,  1685,    -1,     6,    -1,  1567,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,  1026,    -1,    -1,  1891,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1042,  1905,    -1,    -1,    -1,    -1,  1910,    -1,    -1,
    1913,  1914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    -1,    -1,  1930,    -1,    -1,
    1933,    -1,    -1,    -1,    -1,    -1,  1936,    -1,    -1,    -1,
      -1,  1944,    -1,    -1,    -1,  1948,    -1,    -1,    -1,    -1,
    1091,  1092,    -1,  1094,  1095,  1096,    -1,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,    -1,    -1,    -1,
    1973,    -1,    -1,    -1,    -1,    -1,  2053,    -1,    -1,    -1,
      -1,  1984,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,  1705,   247,    -1,  1708,  1148,  2011,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1723,    -1,  1725,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1172,    -1,    -1,    -1,    -1,    -1,    -1,  1740,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1774,    -1,    -1,    -1,    -1,  2080,  2081,  2082,
    2083,  2084,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,  1242,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1257,  1258,  1259,    -1,
       6,  2124,    -1,    -1,    -1,  1949,  1950,  1951,  1952,  1953,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2141,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
    2163,   247,    -1,    -1,    -1,  1306,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2177,    -1,    -1,    -1,    -1,    -1,
      -1,  2184,  2185,    -1,    -1,    -1,  2010,    -1,    -1,    -1,
    2014,    -1,    -1,    -1,    -1,  2198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2163,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1366,    -1,    -1,    -1,  2184,
    2185,    -1,    -1,    -1,    -1,    -1,    -1,   141,  1379,    -1,
    2064,   145,  1383,  2198,  2068,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,
    2084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    -1,   177,   178,   179,    -1,   181,   182,   183,
     184,   185,   186,   187,    -1,   189,   190,   191,   192,    -1,
      -1,    -1,   196,    -1,    -1,    -1,  1437,  1438,  1439,    -1,
      -1,    -1,    -1,    -1,  1445,    -1,    -1,  2131,  2132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1460,
      -1,  2023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1479,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,   268,   269,   270,   271,   272,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,   288,   289,  2088,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   307,    -1,    -1,    -1,    -1,  1549,  2111,
      -1,    -1,    -1,   317,   318,    -1,    -1,    -1,    -1,   323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,
     334,    -1,    -1,    -1,    -1,  1576,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   357,   358,    -1,    -1,    -1,   362,   363,
     364,  2163,   366,    -1,    -1,    -1,   370,   371,   372,    -1,
      -1,   375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2184,  2185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2198,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,
      -1,    -1,  1653,   417,   418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   435,    -1,    -1,    -1,    -1,    -1,    -1,  1679,    -1,
      -1,    -1,    -1,    -1,    -1,   449,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1695,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   468,   469,   470,   471,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1726,    -1,    -1,    -1,    -1,
     494,   495,    -1,    -1,    -1,   499,    -1,    -1,  1739,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,    -1,   529,   530,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   541,    -1,    -1,
     544,   545,    -1,    -1,    -1,    -1,    -1,   551,    -1,    -1,
      -1,    -1,   556,  1794,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,    -1,   589,   590,    -1,  1829,    -1,
      -1,    -1,     6,   597,   598,   599,    -1,    -1,    -1,    -1,
      -1,   605,   606,    -1,   608,   609,    -1,    -1,   196,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   627,   628,   629,    -1,    -1,    -1,   633,
     634,   635,   636,   637,   638,   639,   640,   641,    -1,     6,
      -1,    -1,    -1,   647,    -1,   649,    -1,    -1,   652,    -1,
    1891,    -1,   656,   657,   658,   659,    -1,   661,   662,   663,
      -1,    -1,    -1,    -1,  1905,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,   688,    -1,    -1,   247,    -1,  1930,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,    -1,
     288,   289,    -1,  1944,    -1,   709,    -1,   711,    -1,    -1,
     714,   715,    -1,    -1,    -1,    -1,    -1,   196,    -1,   723,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   736,    -1,   738,    -1,    -1,    -1,    -1,   743,
     744,    -1,    -1,  1984,    -1,   333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   758,    -1,   760,   761,    -1,    -1,
     764,   765,    -1,    -1,    -1,   769,    -1,   771,    -1,    -1,
    2011,    -1,    -1,   777,    -1,    -1,    -1,   781,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     269,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   807,    -1,   809,    -1,   811,    -1,   288,
     289,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   417,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,
     844,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     854,   855,   856,    -1,   333,    -1,    -1,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,   358,
     247,    -1,    -1,  2124,    -1,    -1,    -1,    -1,   892,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   905,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   913,
      -1,    -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,   923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   931,   932,    -1,
      -1,    -1,    -1,   937,    -1,    -1,  2177,    -1,   417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     954,    -1,    -1,   957,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,     6,
      -1,    -1,    -1,    -1,   978,    -1,   980,   981,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   999,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     7,   495,    -1,  1022,   247,
     608,   609,    -1,    -1,    -1,  1029,    -1,    -1,    -1,    -1,
    1034,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,    -1,    -1,    -1,    -1,  1049,  1050,   526,   527,    -1,
      -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   656,   657,
     658,    -1,   551,    -1,    -1,    -1,    -1,   556,    -1,    -1,
      -1,  1085,  1086,  1087,  1088,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   582,    -1,    -1,  1110,   247,    -1,   249,
      -1,   251,    -1,    -1,   702,    -1,    -1,   257,    -1,    -1,
      -1,    -1,  1126,    -1,    -1,    -1,    -1,    -1,    -1,   608,
     609,    -1,  1136,  1137,  1138,    -1,    -1,    -1,    -1,  1143,
    1144,    -1,  1146,    -1,    -1,    -1,    -1,    -1,   736,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1160,  1161,     6,    -1,
      -1,    -1,    -1,    -1,  1168,  1169,    -1,    -1,    -1,    -1,
     758,  1175,    -1,  1177,  1178,    -1,   764,   656,   657,   658,
    1184,  1185,    -1,    -1,    -1,  1189,  1190,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,  1221,    -1,    -1,
      -1,    -1,    -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,  1256,    -1,    -1,   247,   844,   736,    -1,    -1,
      -1,    -1,    -1,    -1,  1268,    -1,   854,    -1,    -1,    -1,
      -1,    -1,  1276,    -1,    -1,    -1,    -1,    -1,    -1,   758,
      -1,    -1,    -1,    -1,    -1,   764,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1297,  1298,    -1,    -1,    -1,  1302,    -1,
      -1,    -1,    -1,    -1,   892,    -1,    -1,    -1,    -1,  1313,
      -1,    -1,  1316,    -1,    -1,    -1,    -1,   905,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,    -1,
     809,    -1,   811,    -1,    -1,   923,    -1,    -1,    -1,    -1,
    1344,    -1,    -1,  1347,  1348,  1349,  1350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1358,    -1,  1360,    -1,  1362,  1363,
    1364,    -1,    -1,    -1,    -1,   844,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,   854,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   892,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    -1,   905,    -1,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
    1444,    -1,    -1,    74,   923,    76,    -1,  1451,  1452,  1453,
      -1,    -1,    -1,    -1,    -1,    -1,  1460,    -1,  1462,    90,
      -1,    -1,    93,    -1,    -1,  1469,    97,  1055,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,  1483,
      -1,    -1,    -1,    -1,  1488,   116,    -1,    -1,    -1,    -1,
      -1,    -1,  1496,  1497,  1498,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,  1508,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1541,    -1,    -1,
      -1,    -1,    -1,  1547,  1548,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   202,   203,   204,    -1,    -1,  1055,  1581,    -1,    -1,
      -1,    -1,   213,    -1,    -1,    -1,   217,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1189,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,    -1,  1621,  1622,  1623,
      -1,   252,    -1,   254,    -1,    -1,    -1,    -1,  1632,    -1,
      -1,  1110,    -1,  1637,  1638,  1639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1651,    -1,    -1,
      -1,    -1,  1656,  1657,  1658,    -1,  1660,    -1,    -1,    -1,
      -1,    -1,  1666,  1667,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1268,  1685,    -1,    -1,    -1,    -1,  1690,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,  1703,
      -1,    -1,  1706,    -1,    -1,    -1,  1710,    -1,    -1,    -1,
    1189,  1190,    -1,    -1,    -1,  1719,  1720,    -1,  1722,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1746,    -1,    -1,    -1,    -1,  1751,  1752,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1348,  1765,  1350,   439,  1768,  1769,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,  1268,
      -1,   113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,  1806,  1807,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,  1823,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1832,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,  1841,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1850,  1851,    -1,    -1,
    1854,    -1,    -1,    -1,    -1,    -1,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,  1348,
      -1,  1350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,  1888,  1889,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1908,    -1,    -1,    -1,    -1,  1913,
    1914,  1915,    -1,    -1,    -1,    -1,  1920,   593,    -1,  1923,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1933,
      -1,   253,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1948,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1956,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,    -1,  1981,    -1,   113,
     114,   115,   116,  1987,    -1,   119,  1990,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,  1483,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2019,    -1,    -1,    -1,    -1,
     154,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
    2044,  2045,    -1,   247,   178,   179,   180,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2058,  2059,    -1,  2061,  2062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1656,  1657,
      -1,  2075,    -1,    -1,    -1,    -1,  2080,  2081,  2082,  2083,
    2084,    -1,    -1,    -1,    -1,    -1,  2090,    -1,    -1,    -1,
    2094,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2122,   253,
      -1,    -1,    -1,  2127,  2128,  2129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2141,    -1,    -1,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   825,
     826,    -1,   828,   829,   830,   831,    -1,   833,   834,   835,
     836,     8,    -1,    -1,    -1,  2169,  2170,  2171,    -1,    -1,
      -1,   847,    -1,   849,    -1,    -1,    -1,  1656,  1657,    -1,
      -1,    -1,    -1,   859,    -1,    -1,    -1,    -1,    -1,    -1,
     866,   867,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   875,
      -1,    -1,    -1,    -1,    -1,    -1,  1685,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,  1806,  1807,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1854,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,   985,
     986,   987,    -1,    -1,    -1,   991,   992,    -1,    -1,   995,
     996,   997,   998,    -1,  1000,  1913,  1914,  1806,  1807,  1005,
      -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1933,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1948,    -1,  1841,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1854,    -1,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,
      -1,    -1,    -1,  1089,   201,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,  1913,  1914,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   236,
     237,    -1,    -1,    -1,  1933,    -1,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,    -1,    -1,   255,  1948,
      -1,    -1,    -1,    -1,  2062,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2080,  2081,  2082,  2083,  2084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1186,    -1,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,    -1,   239,   240,    -1,    -1,
      -1,    -1,    -1,  2141,    -1,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,   261,    -1,
       4,     5,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2062,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2080,  2081,  2082,  2083,  2084,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     8,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,  1325,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,    93,
      -1,    -1,  2141,    97,    -1,    -1,   100,    -1,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,   377,   378,   379,    -1,    -1,  1365,
     383,   384,   385,   386,   387,   388,   389,    -1,   391,   133,
      -1,    -1,   395,   396,    -1,    -1,   399,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,  1397,  1398,  1399,  1400,  1401,    -1,    -1,    -1,    -1,
    1406,  1407,    -1,    -1,    -1,    -1,  1412,    -1,  1414,    -1,
      -1,    -1,  1418,    -1,    -1,  1421,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1433,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   249,    -1,   251,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1504,    -1,
    1506,    -1,    -1,    -1,  1510,    -1,  1512,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,  1543,    -1,    -1,
      -1,   564,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    73,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      91,    -1,    93,    -1,  1640,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,     8,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1742,    -1,    -1,  1745,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,    -1,  1795,
    1796,   252,  1798,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,    -1,   113,   114,   115,
     116,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,   130,   131,    -1,   133,   134,     8,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   870,    -1,    -1,
      -1,    -1,  1858,  1859,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   904,   178,   179,   180,   247,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,    -1,
    1906,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    67,    68,    69,    -1,   253,    72,    73,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,    -1,   148,   149,   150,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1078,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,   206,     8,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,    -1,
      -1,   255,    -1,    -1,  2150,     3,     4,     5,    -1,     7,
    1173,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    -1,    -1,    74,    -1,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    91,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
     249,    -1,    -1,  1326,  1327,    -1,    -1,    -1,   257,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,   194,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   219,   220,   221,   222,   223,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,    -1,   245,   246,    -1,
     248,    -1,   250,  1416,    -1,    -1,   254,   255,     3,     4,
       5,    -1,    -1,  1426,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,  1580,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,     3,     4,    -1,   252,    -1,     8,
     255,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
       3,     4,     5,    -1,   253,    -1,   255,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,    -1,
     133,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,    -1,   160,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,   252,
      -1,    -1,   255,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,   252,   253,    -1,   255,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,   252,    -1,    -1,   255,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,     3,     4,    -1,   252,    -1,    -1,
     255,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
       3,     4,    -1,   252,    -1,    -1,   255,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,    -1,   131,    -1,
     133,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,    -1,   148,   149,   150,   151,   152,
     153,    -1,    -1,    -1,   157,    -1,    -1,   160,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,     3,     4,    -1,    -1,
     253,    -1,   255,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,   252,    -1,    -1,   255,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,   252,    -1,    -1,   255,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,     3,     4,    -1,   252,    -1,     8,
     255,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,   148,
     149,   150,   151,   152,   153,    -1,    -1,    -1,   157,    -1,
      -1,   160,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,     3,     4,    -1,    -1,   248,
       8,    -1,    10,    11,    12,    -1,   255,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,    -1,
     148,   149,   150,   151,   152,   153,    -1,    -1,    -1,   157,
      -1,    -1,   160,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,    -1,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,     3,     4,    -1,    -1,
     248,    -1,    -1,    10,    11,    12,    -1,   255,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,   100,    -1,    -1,   103,    -1,   105,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,    -1,   131,    -1,   133,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
      -1,   148,   149,   150,   151,   152,   153,    -1,    -1,    -1,
     157,    -1,    -1,   160,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,   205,   206,
      -1,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,     3,     4,    -1,   252,    -1,    -1,   255,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,    -1,
     131,    -1,   133,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,    -1,   148,   149,   150,
     151,   152,   153,    -1,    -1,    -1,   157,    -1,    -1,   160,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,   248,     3,     4,
      -1,   252,    -1,    -1,   255,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,   103,    -1,
     105,    -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,    -1,   131,    -1,   133,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,    -1,   148,   149,   150,   151,   152,   153,    -1,
      -1,    -1,   157,    -1,    -1,   160,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,     3,
       4,     5,    -1,   248,    -1,    -1,    10,    11,    12,    -1,
     255,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    93,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    -1,    76,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,   252,    -1,
      -1,   255,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,   201,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   248,     3,     4,     5,   252,
      -1,    -1,   255,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,    76,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    -1,    93,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    -1,    -1,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    91,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   201,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,    -1,    -1,    -1,   252,    -1,    -1,   255,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,   201,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,     3,     4,
      -1,    -1,   248,    -1,    -1,    10,    11,    12,    -1,   255,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,    88,    89,     8,    91,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,   257,    -1,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,   252,    -1,    -1,
     255,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,   205,   257,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,     3,     4,    -1,    -1,   248,    -1,    -1,    10,    11,
      12,    -1,   255,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,   201,
      -1,   247,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,
     212,   257,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,   201,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,     3,     4,    -1,     6,   248,    -1,    -1,    10,    11,
      12,    -1,   255,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
       3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,   201,
      -1,   247,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,
     212,   257,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,
      -1,    -1,    -1,   255,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,    -1,   201,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,     3,     4,    -1,    -1,   248,    -1,    -1,    10,    11,
      12,    -1,   255,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      -1,    -1,    -1,     3,     4,    -1,    88,    89,    -1,    91,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,   205,   257,    -1,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   248,   249,    -1,    -1,
      -1,    -1,    -1,   255,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,   205,   257,    -1,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,    -1,    -1,    -1,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,   243,     3,     4,    -1,    -1,   248,   249,
      -1,    10,    11,    12,    -1,   255,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    -1,    91,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,    -1,    -1,
      -1,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
     202,   203,   204,    13,    14,    -1,   255,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,   217,    -1,   219,   220,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    -1,    -1,    -1,   113,   114,   115,   116,    -1,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     252,    -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     178,   179,   180,   113,   114,   115,   116,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
     130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   178,   179,
     180,   113,   114,   115,   116,   253,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   178,   179,   180,   113,
     114,   115,   116,   253,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   178,   179,   180,   113,   114,   115,
     116,   253,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,   130,   131,    -1,   133,   134,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   178,   179,   180,   113,   114,   115,   116,   253,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     178,   179,   180,   113,   114,   115,   116,   253,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
     130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   178,   179,
     180,   113,   114,   115,   116,   253,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   178,   179,   180,   113,
     114,   115,   116,   253,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,   130,   131,    -1,   133,
     134,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   178,   179,   180,   113,   114,   115,
     116,   253,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,   130,   131,    -1,   133,   134,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   178,   179,   180,   113,   114,   115,   116,   253,
      -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    13,    14,    -1,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
     178,   179,   180,   247,    -1,    -1,    -1,   253,    44,    45,
      -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,   253,   112,   113,   114,   115,
     116,   117,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,     4,    -1,
     166,   167,   168,    -1,    -1,    -1,   172,    13,    14,    -1,
      -1,   177,   178,   179,   180,    -1,    -1,   183,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    44,    45,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,    -1,   220,    -1,    -1,    -1,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,    -1,
      86,    87,    -1,    89,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,    -1,    -1,   112,   113,   114,   115,
     116,   117,    -1,   119,    -1,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      -1,    -1,   138,   139,   140,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,   177,   178,   179,   180,     4,     5,   183,    -1,   185,
      -1,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   218,    -1,   220,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,     4,     5,    -1,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,   103,    -1,   105,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,   116,    -1,    -1,
      59,    60,    61,    62,     4,     5,    -1,    -1,    67,    68,
      69,    -1,    -1,    -1,   133,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,     5,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    93,   213,    -1,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,   213,    -1,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    14,   257,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   213,    -1,    -1,    -1,   217,    -1,   219,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   213,    -1,    -1,    -1,   217,    -1,   219,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    13,    14,    -1,   113,   114,   115,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,   130,   131,    -1,   133,   134,    -1,   136,    -1,    -1,
      -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   154,    -1,    -1,    -1,   158,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,   178,
     179,   180,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,   113,   114,   115,   116,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   130,   131,
      -1,   133,   134,    -1,   136,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   154,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   257,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,   253,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,   253,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,   253,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,   253,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,    -1,    -1,   253,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,    -1,   253,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,   253,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     253,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,    -1,    -1,   253,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,    -1,   252,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,    -1,   252,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
     252,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,   249,    -1,   251,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,   251,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   251,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   251,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,   251,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,   251,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,
      -1,    -1,    -1,   251,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
     251,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
      -1,    -1,    -1,   247,    -1,    -1,    -1,   251,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,   251,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,    -1,
      -1,   251,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,   251,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,    -1,    -1,
      -1,   247,    -1,    -1,    -1,   251,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,    -1,    -1,    -1,   247,    -1,
      -1,    -1,   251,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247,    -1,   249,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,    -1,    -1,    -1,    -1,   247,    -1,   249,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,    -1,    -1,    -1,
     247
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   259,   260,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    75,    80,    81,    82,
      83,    84,    86,    87,    89,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   112,   113,   114,   115,   116,   117,   119,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   138,   139,   140,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   166,   167,   168,
     172,   177,   178,   179,   180,   183,   185,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   207,   208,   209,   218,   220,   261,   263,   264,   284,
     303,   305,   309,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   327,   329,   330,   336,   337,   338,   339,   345,
     370,   371,   252,   256,    14,   103,   248,   248,     6,   252,
       6,     6,     6,     6,   248,     6,     6,   252,     6,     6,
     250,   250,     4,   347,   371,   248,   250,   282,    97,   100,
     103,   105,   282,   248,   248,   248,     4,   248,   248,   248,
       4,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   252,   118,   103,     6,   252,    97,   100,   103,
     116,   308,   105,   248,     3,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    55,    56,    57,
      58,    63,    64,    72,    73,    77,    78,    79,    88,    91,
      97,   100,   103,   105,   116,   126,   131,   133,   136,   201,
     205,   206,   210,   211,   212,   214,   215,   216,   236,   237,
     243,   248,   252,   255,   305,   306,   309,   320,   327,   329,
     340,   341,   345,   347,   354,   356,   371,   248,   252,   252,
     103,   103,   126,   100,   103,   105,    97,   100,   103,   105,
     305,   100,   103,   105,   116,   306,   100,   103,   248,   100,
     158,   183,   199,   200,   252,   236,   237,   248,   252,   351,
     352,   351,   252,   252,   351,     4,    97,   101,   107,   108,
     110,   111,   130,   252,   248,   103,   105,   103,   100,     4,
      89,   194,   252,   371,     4,     6,    97,   100,   103,   100,
     103,   116,   307,     4,     4,     4,     5,   248,   252,   354,
     355,     4,   248,   248,   248,     4,   252,   358,   371,     4,
     248,   248,   248,     6,     6,   250,     5,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    59,    60,    61,    62,
      67,    68,    69,    74,    76,    90,    93,   202,   203,   204,
     213,   217,   219,   362,   371,   248,     4,   362,     5,   252,
       5,   252,    32,   237,   340,   371,   250,   252,   248,   252,
       6,   248,   252,     6,   256,     7,   133,   194,   221,   222,
     223,   224,   245,   246,   248,   250,   254,   280,   281,   282,
     305,   340,   361,   362,   371,     4,   309,   310,   311,   252,
       6,   340,   361,   362,   371,   361,   340,   361,   368,   369,
     371,   340,   286,   290,   248,   350,     9,   362,   248,   248,
     248,   248,   371,   340,   340,   340,   248,   340,   340,   340,
     248,   340,   340,   340,   340,   340,   340,   340,   361,   340,
     340,   340,   340,   355,   248,   237,   340,   356,   357,   252,
     355,   354,   361,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   248,   250,   282,   282,
     282,   282,   282,   282,   248,   282,   282,   248,   305,   306,
     306,   282,   282,     5,   252,   252,   126,   305,   305,   248,
     282,   282,   248,   248,   248,   340,   252,   340,   356,   340,
     340,   253,   357,   347,   371,   186,     5,   252,     8,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   247,     9,   248,
     250,   254,   281,   282,   340,   357,   357,   248,   248,   248,
     354,   355,   355,   355,   304,   252,   248,   354,   252,   252,
     340,     4,   354,   252,   358,   252,   252,   351,   351,   351,
     340,   340,   236,   237,   252,   252,   351,   236,   237,   248,
     311,   351,   252,   248,   252,   248,   248,   248,   248,   248,
     248,   248,   357,   340,   355,   355,   355,   248,     4,   250,
     252,     6,   250,   311,     6,     6,   252,   252,   252,   252,
     355,   250,   250,   250,   340,     8,     6,     6,   340,   340,
     340,   254,   340,   252,   186,   340,   340,   340,   340,   282,
     282,   282,   248,   248,   248,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   248,   248,   282,   248,   250,
       6,     6,   252,     6,     8,   311,     6,     8,   311,   282,
     340,   238,   252,     9,   248,   250,   254,   361,   357,   340,
     311,   354,   354,   252,   362,   305,     7,   340,   340,     4,
     183,   184,   354,     6,   249,   251,   252,   283,   252,     6,
     252,     6,     9,   248,   250,   254,   371,   253,   126,   131,
     133,   134,   136,   303,   305,   340,     6,   249,   257,     9,
     248,   250,   254,   249,   257,   257,   249,   257,     9,   248,
     254,   257,   251,   257,   285,   251,   285,    92,   349,   346,
     371,   257,   340,   340,   340,   340,   257,   249,   249,   249,
     340,   249,   249,   249,   340,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   253,     7,   340,   238,
     253,   257,   340,     6,     6,   249,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   356,   340,   340,   340,   340,   340,   340,
     340,   356,   356,   371,   252,   340,   340,   361,   340,   361,
     354,   361,   361,   368,   252,   252,   252,   340,   283,   371,
       8,   340,   340,   355,   354,   361,   361,   356,   347,   362,
     347,   357,   249,   253,   254,   282,    64,     8,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   252,   340,   356,   340,   340,   340,   340,   340,
     371,   340,   340,     4,   348,   252,   283,   249,   253,   253,
     340,   340,   340,     7,     7,   333,   333,   248,   340,   340,
       6,   357,   357,   252,   249,     6,   311,   252,   311,   311,
     257,   257,   257,   351,   351,   310,   310,   257,   340,   253,
     324,   257,   311,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   253,   249,     7,   334,     6,     7,   340,     6,
     340,   311,   340,   253,   357,   357,   357,   340,     6,   340,
     340,   340,   249,   253,   249,   249,   249,   183,   257,   311,
     252,     8,   249,   249,   251,   368,   361,   368,   361,   361,
     361,   361,   361,   361,   340,   361,   361,   361,   361,   255,
     364,   371,   362,   361,   361,   361,   347,   371,   357,   253,
     253,   253,   253,   340,   340,   311,   371,   348,   251,   253,
     249,   140,   158,   328,   249,   253,   257,   340,     6,   252,
     354,   249,   251,     7,   280,   281,   254,     7,     6,   357,
       7,   224,   280,   340,   265,   371,   340,   340,   348,   250,
     248,   126,   305,   306,   305,   252,   253,     6,   231,   232,
     262,   357,   371,   340,   340,     4,   348,     6,   357,   340,
       6,   361,   369,   371,   249,   348,   340,     6,   371,     6,
     361,   340,   249,   250,   340,   257,   257,   257,   257,   362,
       7,     7,     7,   249,     7,     7,     7,   249,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   340,   249,
     252,   340,   356,   253,     6,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   257,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   257,   257,   257,   249,
     251,   251,   357,   257,   257,   283,   257,   283,   257,   257,
     257,   249,   357,   340,   340,   342,   283,   253,   253,   253,
     257,   257,   283,   283,   249,   254,   249,   254,   257,   282,
     343,   253,     7,   348,   283,   252,   253,     8,     8,   357,
     254,   249,   251,   281,   248,   250,   282,   357,     7,   252,
     252,   249,   249,   249,   340,   354,     4,   332,     6,   299,
     340,   362,   253,   249,   253,   253,   357,   254,   253,   311,
     253,   253,   351,   340,   340,   253,   253,   340,   351,   137,
     137,   155,   163,   164,   165,   169,   170,   325,   326,   351,
     253,   321,   249,   253,   249,   249,   249,   249,   249,   249,
     249,   252,     7,   340,     6,   340,   249,   251,   253,   251,
     253,   253,   253,   253,   251,   251,   257,     7,     7,     7,
     254,   340,   253,   340,   340,     7,   254,   283,   257,   283,
     283,   249,   249,   257,   283,   283,   257,   257,   283,   283,
     283,   283,   340,   283,     9,   363,   257,   249,   257,   283,
     254,   257,   344,   251,   253,   253,   254,   248,   250,   256,
     186,     7,   158,     6,   340,   253,   252,     6,   354,   253,
     340,     6,     7,   280,   281,   254,   280,   281,   362,   340,
       6,     4,   252,   359,   371,   253,    46,    46,   354,   253,
       4,   173,   174,   175,   176,   253,   268,   272,   275,   277,
     278,   254,   249,   251,   248,   340,   340,   248,   252,   248,
     252,     8,   357,   361,   249,   254,   249,   251,   248,   249,
     257,   254,   248,   257,     7,   282,     4,   293,   294,   295,
     283,   340,   340,   340,   340,   283,   351,   354,   354,     7,
     354,   354,   354,     7,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   354,     6,     7,   357,   340,   340,   340,
     340,   253,   340,   340,   340,   354,   361,   361,   253,   253,
     253,   257,   292,   340,   340,   348,   348,   340,   340,   249,
     354,   282,   340,   340,   340,   253,   348,   281,   254,   281,
     340,   340,   283,   253,   354,   357,   357,     7,     7,     7,
     137,   331,     6,   249,   257,     7,     7,     7,   253,     4,
     253,   257,   257,   257,   253,   253,   115,     4,     6,   340,
     252,     6,   248,     6,   171,     6,   171,   253,   326,   257,
     325,     7,     6,     7,     7,     7,     7,     7,     7,     7,
     310,   354,     6,   252,     6,     6,     6,   103,     7,     6,
       6,   340,   354,   354,   354,     4,   257,     8,     8,   249,
       4,   106,   107,     4,   357,   361,   340,   361,   255,   257,
     296,   361,   361,   348,   361,   249,   257,   348,   252,   305,
     252,     6,   340,     6,   252,   354,   253,   253,   340,     6,
       4,   183,   184,   340,     6,     6,     6,     7,   358,   360,
       6,   250,   283,   282,   282,     6,   269,   248,   248,   252,
     279,     6,   348,   254,   361,   340,   251,   249,   340,     8,
     357,   340,   357,   253,   253,     6,     6,   262,   348,   254,
     340,     6,   340,   348,   249,   340,   252,   340,   362,   283,
      46,   252,   354,   362,   365,   251,   257,     6,   249,   249,
     249,   249,     6,     6,   130,   301,   301,   354,     6,     6,
       6,   354,   137,   186,   300,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     5,   253,   283,   283,   283,   283,
     283,   257,   257,   257,   249,   283,   283,   294,   283,   249,
     283,   249,   282,   343,   283,     6,   283,   257,   248,   250,
     282,     4,   249,   251,   283,     6,   253,   253,   354,   354,
     354,     4,     6,   280,   340,   354,   252,   252,     7,     6,
       7,   340,   340,   340,   252,   252,   252,   250,     6,   340,
     354,   340,     6,     6,   340,   351,   253,     5,   354,   252,
     252,   252,   252,   252,   252,   252,   354,   253,     6,   357,
     252,   340,   251,     6,     6,   182,   340,   340,   340,     6,
       6,     6,     6,     7,   283,   257,   257,   283,   257,   340,
       4,   198,   297,   298,   283,   249,   283,   344,   362,   248,
     250,   340,   252,   311,     6,   311,   257,     6,     6,     7,
     280,   281,   254,     7,     6,   358,   253,   257,   340,   280,
     252,   283,   366,   367,   368,   366,   248,   340,   340,   353,
     354,   252,   248,     4,     6,   249,     6,   249,   253,   253,
     249,   253,     6,     6,   361,   248,     4,   249,   257,   248,
     253,   354,   362,     7,   282,   291,   340,   356,   295,     6,
       6,     6,     6,   351,     6,     6,     6,   137,   302,    97,
     116,   101,     6,     5,   252,   340,   340,   340,   340,   249,
     343,   340,   340,   340,   283,   281,   252,   252,     6,   300,
       6,   340,   354,     4,     6,   357,   357,   340,   340,   362,
     253,   249,   253,   257,   310,   310,   340,   340,   253,   257,
     249,   253,   257,     6,     6,   353,   351,   351,   351,   351,
     351,   237,   351,     6,   253,   340,     6,     6,   354,   253,
     257,     8,   253,   249,   252,   340,   362,   361,   340,   361,
     340,   362,   365,   367,   362,   257,   249,   257,   253,   340,
     328,   328,   354,   362,   340,     6,     4,   359,     6,   358,
     251,   354,   368,     6,   283,   283,   266,   340,   257,   257,
     253,   257,   267,   340,   340,     6,     6,     6,     6,   340,
     340,   249,     6,   287,   289,   252,   367,   253,   257,     7,
       7,   141,     6,   252,   252,   252,     5,   353,   283,   283,
     257,   283,   249,   257,   249,   251,   357,   357,     6,     6,
     252,   253,   253,   252,     6,     6,   252,   340,   253,   253,
     253,   251,     6,   354,     7,   252,   340,   253,   257,   257,
     257,   257,   257,   257,     6,   253,   181,   340,   340,   357,
       6,     6,   249,   283,   283,   298,   362,   253,   253,   253,
     253,     6,     6,     7,     6,   254,     6,   253,     6,     6,
     249,   257,   340,   340,   252,   354,   253,   257,   249,   249,
     257,   292,   296,   354,   283,   340,   362,   371,   357,   357,
     340,     6,   253,   340,   343,   340,   253,   253,   353,   142,
     143,   148,   335,   142,   143,   335,   357,   310,   253,   257,
       6,   253,   354,   311,   253,     6,   357,   351,   351,   351,
     351,   351,   340,   253,   253,   253,   249,     6,   252,     6,
     358,   184,   270,   340,   257,   257,   353,     6,   340,   340,
     253,   253,   288,     7,   248,   253,   253,   253,   252,   257,
     249,   257,   252,   253,   252,   351,   354,     6,   252,   351,
       6,   253,   253,   340,     6,   137,   253,   322,   252,   253,
     257,   257,   257,   257,   257,     6,     6,     6,   311,     6,
     252,   340,   340,   253,   257,   292,   362,   249,   340,   340,
     340,   357,     6,   351,     6,   351,     6,     6,   253,   340,
     325,   311,     6,   357,   357,   357,   357,   351,   357,   328,
     267,   249,   257,     6,   252,   340,   253,   257,   257,   257,
     253,   257,   257,     6,   253,   253,   323,   253,   253,   253,
     253,   257,   253,   253,   253,   273,   340,   353,   253,   340,
     340,   340,   351,   351,   325,     6,     6,     6,     6,   357,
       6,     6,     6,   252,   249,   253,     6,   253,   283,   257,
     257,   257,   253,   253,   271,   361,   276,   252,     6,   340,
     340,   340,     6,   253,   257,   252,   353,   253,   253,   253,
       6,   361,   274,   361,   253,     6,     6,   253,   257,     6,
       6,   361
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
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 345 "Gmsh.y"
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

  case 31:
#line 359 "Gmsh.y"
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

  case 32:
#line 372 "Gmsh.y"
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

  case 33:
#line 385 "Gmsh.y"
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

  case 34:
#line 413 "Gmsh.y"
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

  case 35:
#line 427 "Gmsh.y"
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

  case 36:
#line 440 "Gmsh.y"
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

  case 37:
#line 453 "Gmsh.y"
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

  case 38:
#line 471 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 485 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 487 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 492 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 494 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 499 "Gmsh.y"
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

  case 49:
#line 603 "Gmsh.y"
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

  case 50:
#line 613 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 622 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 629 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 639 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T2D.push_back((yyvsp[(3) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(5) - (8)].d));
      ViewData->T2D.push_back((yyvsp[(7) - (8)].d));
      ViewData->T2D.push_back(ViewData->T2C.size());
#endif
    ;}
    break;

  case 54:
#line 648 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 657 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 664 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 674 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 682 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 692 "Gmsh.y"
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

  case 60:
#line 711 "Gmsh.y"
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

  case 61:
#line 730 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 736 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 743 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 744 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 745 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 746 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 747 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 751 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 752 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 758 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 758 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 759 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 759 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 769 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 774 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 780 "Gmsh.y"
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

  case 80:
#line 842 "Gmsh.y"
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

  case 81:
#line 857 "Gmsh.y"
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

  case 82:
#line 886 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 896 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 901 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 909 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 914 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 922 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 931 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 936 "Gmsh.y"
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

  case 90:
#line 948 "Gmsh.y"
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

  case 91:
#line 965 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 971 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 980 "Gmsh.y"
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

  case 94:
#line 998 "Gmsh.y"
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

  case 95:
#line 1016 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d)){
	d += (yyvsp[(4) - (5)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (5)].c), 0, (yyvsp[(3) - (5)].c), d);
      }
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 96:
#line 1025 "Gmsh.y"
    {
      double d = 0.;
      if(NumberOption(GMSH_GET, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d)){
	d += (yyvsp[(7) - (8)].i);
	NumberOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), (int)(yyvsp[(3) - (8)].d), (yyvsp[(6) - (8)].c), d);
      }
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(6) - (8)].c));
    ;}
    break;

  case 97:
#line 1037 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1042 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1050 "Gmsh.y"
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

  case 100:
#line 1070 "Gmsh.y"
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

  case 101:
#line 1093 "Gmsh.y"
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

  case 102:
#line 1113 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1121 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 104:
#line 1128 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 105:
#line 1135 "Gmsh.y"
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

  case 106:
#line 1157 "Gmsh.y"
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

  case 107:
#line 1180 "Gmsh.y"
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

  case 108:
#line 1218 "Gmsh.y"
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

  case 109:
#line 1239 "Gmsh.y"
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

  case 110:
#line 1251 "Gmsh.y"
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

  case 114:
#line 1269 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (3)].c));
      std::vector<double> val(1, 0.);
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 115:
#line 1278 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c));
      std::vector<double> val(1, (yyvsp[(5) - (5)].d));
      if(!gmsh_yysymbols.count(key)){
        gmsh_yysymbols[key].value = val;
      }
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 116:
#line 1287 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1289 "Gmsh.y"
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

  case 118:
#line 1307 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1309 "Gmsh.y"
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

  case 120:
#line 1325 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (5)].c)), val((yyvsp[(5) - (5)].c));
      if(!gmsh_yystringsymbols.count(key)){
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (5)].c));
      Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 121:
#line 1334 "Gmsh.y"
    { init_options(); ;}
    break;

  case 122:
#line 1336 "Gmsh.y"
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

  case 124:
#line 1350 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 125:
#line 1358 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 126:
#line 1364 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 127:
#line 1369 "Gmsh.y"
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

  case 134:
#line 1412 "Gmsh.y"
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

  case 135:
#line 1424 "Gmsh.y"
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

  case 136:
#line 1437 "Gmsh.y"
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

  case 137:
#line 1452 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 138:
#line 1461 "Gmsh.y"
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

  case 143:
#line 1486 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 144:
#line 1494 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 145:
#line 1503 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1511 "Gmsh.y"
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

  case 147:
#line 1525 "Gmsh.y"
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

  case 148:
#line 1543 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 149:
#line 1547 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 150:
#line 1554 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 151:
#line 1562 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 152:
#line 1566 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 153:
#line 1572 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 154:
#line 1576 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      double flag = -1;
      List_Add((yyval.l), &flag);
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (5)].l)); i++)
        List_Add((yyval.l), List_Pointer((yyvsp[(4) - (5)].l), i));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 155:
#line 1587 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 156:
#line 1591 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 157:
#line 1597 "Gmsh.y"
    {
      (yyval.d) = 0;
    ;}
    break;

  case 158:
#line 1601 "Gmsh.y"
    {
      (yyval.d) = 1;
    ;}
    break;

  case 159:
#line 1607 "Gmsh.y"
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

  case 160:
#line 1630 "Gmsh.y"
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

  case 161:
#line 1646 "Gmsh.y"
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

  case 162:
#line 1662 "Gmsh.y"
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

  case 163:
#line 1699 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (8)].l), tags);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (8)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(tags.size() == 3){
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[2]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 points, or 5 to 7 parameters");
        }
      }
      else{
        if(tags.size() == 4){
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

  case 164:
#line 1735 "Gmsh.y"
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

  case 165:
#line 1751 "Gmsh.y"
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

  case 166:
#line 1768 "Gmsh.y"
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

  case 167:
#line 1799 "Gmsh.y"
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

  case 168:
#line 1815 "Gmsh.y"
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

  case 169:
#line 1832 "Gmsh.y"
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

  case 170:
#line 1848 "Gmsh.y"
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

  case 171:
#line 1898 "Gmsh.y"
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

  case 172:
#line 1916 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 173:
#line 1922 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 174:
#line 1928 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 175:
#line 1935 "Gmsh.y"
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

  case 176:
#line 1966 "Gmsh.y"
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

  case 177:
#line 1981 "Gmsh.y"
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

  case 178:
#line 2003 "Gmsh.y"
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

  case 179:
#line 2026 "Gmsh.y"
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

  case 180:
#line 2049 "Gmsh.y"
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

  case 181:
#line 2072 "Gmsh.y"
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

  case 182:
#line 2096 "Gmsh.y"
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

  case 183:
#line 2120 "Gmsh.y"
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

  case 184:
#line 2144 "Gmsh.y"
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

  case 185:
#line 2170 "Gmsh.y"
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

  case 186:
#line 2187 "Gmsh.y"
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

  case 187:
#line 2203 "Gmsh.y"
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

  case 188:
#line 2221 "Gmsh.y"
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

  case 189:
#line 2239 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (8)].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 190:
#line 2247 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (12)].i) == 2) ? "Surface" : "Curve");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 191:
#line 2254 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 192:
#line 2258 "Gmsh.y"
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

  case 193:
#line 2284 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 194:
#line 2286 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 195:
#line 2288 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 196:
#line 2290 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 197:
#line 2292 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 198:
#line 2300 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 199:
#line 2302 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 200:
#line 2304 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 201:
#line 2306 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 202:
#line 2314 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 203:
#line 2316 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 204:
#line 2318 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 205:
#line 2326 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 206:
#line 2328 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 207:
#line 2330 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 208:
#line 2332 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 209:
#line 2342 "Gmsh.y"
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

  case 210:
#line 2358 "Gmsh.y"
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

  case 211:
#line 2374 "Gmsh.y"
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

  case 212:
#line 2390 "Gmsh.y"
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

  case 213:
#line 2406 "Gmsh.y"
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

  case 214:
#line 2422 "Gmsh.y"
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

  case 215:
#line 2439 "Gmsh.y"
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

  case 216:
#line 2476 "Gmsh.y"
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

  case 217:
#line 2498 "Gmsh.y"
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

  case 218:
#line 2521 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 219:
#line 2522 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 220:
#line 2527 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 221:
#line 2531 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 222:
#line 2535 "Gmsh.y"
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

  case 223:
#line 2552 "Gmsh.y"
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

  case 224:
#line 2572 "Gmsh.y"
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

  case 225:
#line 2592 "Gmsh.y"
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

  case 226:
#line 2611 "Gmsh.y"
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

  case 227:
#line 2638 "Gmsh.y"
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

  case 228:
#line 2657 "Gmsh.y"
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

  case 229:
#line 2679 "Gmsh.y"
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

  case 230:
#line 2694 "Gmsh.y"
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

  case 231:
#line 2709 "Gmsh.y"
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

  case 232:
#line 2728 "Gmsh.y"
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

  case 233:
#line 2779 "Gmsh.y"
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

  case 234:
#line 2800 "Gmsh.y"
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

  case 235:
#line 2822 "Gmsh.y"
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

  case 236:
#line 2844 "Gmsh.y"
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

  case 237:
#line 2949 "Gmsh.y"
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

  case 238:
#line 2965 "Gmsh.y"
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

  case 239:
#line 3000 "Gmsh.y"
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

  case 240:
#line 3022 "Gmsh.y"
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

  case 241:
#line 3044 "Gmsh.y"
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

  case 242:
#line 3056 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 243:
#line 3062 "Gmsh.y"
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

  case 244:
#line 3077 "Gmsh.y"
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

  case 245:
#line 3105 "Gmsh.y"
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

  case 246:
#line 3117 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 247:
#line 3126 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 248:
#line 3133 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 249:
#line 3145 "Gmsh.y"
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

  case 250:
#line 3165 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 251:
#line 3169 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 252:
#line 3174 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 253:
#line 3178 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 254:
#line 3183 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 255:
#line 3190 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 256:
#line 3197 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 257:
#line 3204 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 258:
#line 3216 "Gmsh.y"
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

  case 259:
#line 3289 "Gmsh.y"
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

  case 260:
#line 3307 "Gmsh.y"
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

  case 261:
#line 3332 "Gmsh.y"
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

  case 262:
#line 3347 "Gmsh.y"
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

  case 263:
#line 3380 "Gmsh.y"
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

  case 264:
#line 3392 "Gmsh.y"
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

  case 265:
#line 3416 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 266:
#line 3420 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 267:
#line 3425 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 268:
#line 3432 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 269:
#line 3437 "Gmsh.y"
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

  case 270:
#line 3447 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 271:
#line 3452 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 272:
#line 3458 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(std::size_t index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 273:
#line 3466 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 274:
#line 3470 "Gmsh.y"
    {
      GModel::current()->classifySurfaces((yyvsp[(3) - (9)].d), (yyvsp[(5) - (9)].d), (yyvsp[(7) - (9)].d));
    ;}
    break;

  case 275:
#line 3474 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 276:
#line 3478 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 277:
#line 3482 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 278:
#line 3486 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 279:
#line 3496 "Gmsh.y"
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

  case 280:
#line 3559 "Gmsh.y"
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

  case 281:
#line 3575 "Gmsh.y"
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

  case 282:
#line 3592 "Gmsh.y"
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

  case 283:
#line 3609 "Gmsh.y"
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

  case 284:
#line 3631 "Gmsh.y"
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

  case 285:
#line 3653 "Gmsh.y"
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

  case 286:
#line 3688 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 287:
#line 3696 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 288:
#line 3704 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 289:
#line 3710 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 290:
#line 3717 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 291:
#line 3724 "Gmsh.y"
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

  case 292:
#line 3744 "Gmsh.y"
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

  case 293:
#line 3770 "Gmsh.y"
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

  case 294:
#line 3782 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 295:
#line 3793 "Gmsh.y"
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

  case 296:
#line 3811 "Gmsh.y"
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

  case 297:
#line 3829 "Gmsh.y"
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

  case 298:
#line 3847 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 299:
#line 3853 "Gmsh.y"
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

  case 300:
#line 3871 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 301:
#line 3877 "Gmsh.y"
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

  case 302:
#line 3897 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 303:
#line 3903 "Gmsh.y"
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

  case 304:
#line 3921 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 305:
#line 3927 "Gmsh.y"
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

  case 306:
#line 3944 "Gmsh.y"
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

  case 307:
#line 3960 "Gmsh.y"
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

  case 308:
#line 3977 "Gmsh.y"
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

  case 309:
#line 3995 "Gmsh.y"
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

  case 310:
#line 4018 "Gmsh.y"
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

  case 311:
#line 4045 "Gmsh.y"
    {
    ;}
    break;

  case 312:
#line 4048 "Gmsh.y"
    {
    ;}
    break;

  case 313:
#line 4054 "Gmsh.y"
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

  case 314:
#line 4066 "Gmsh.y"
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

  case 315:
#line 4086 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 316:
#line 4090 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 317:
#line 4094 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 318:
#line 4098 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 319:
#line 4102 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 320:
#line 4106 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 321:
#line 4110 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 322:
#line 4114 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 323:
#line 4123 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 324:
#line 4135 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 325:
#line 4136 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 326:
#line 4137 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 327:
#line 4138 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 328:
#line 4139 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 329:
#line 4143 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 330:
#line 4144 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 331:
#line 4145 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 332:
#line 4146 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 333:
#line 4147 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 334:
#line 4152 "Gmsh.y"
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

  case 335:
#line 4175 "Gmsh.y"
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

  case 336:
#line 4195 "Gmsh.y"
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

  case 337:
#line 4216 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 338:
#line 4220 "Gmsh.y"
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

  case 339:
#line 4235 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 340:
#line 4239 "Gmsh.y"
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

  case 341:
#line 4255 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 342:
#line 4259 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 343:
#line 4264 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 344:
#line 4268 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 345:
#line 4274 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 346:
#line 4278 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 347:
#line 4285 "Gmsh.y"
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

  case 348:
#line 4307 "Gmsh.y"
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
	      //	      Msg::Info("edge %p tagged %d with %d points",ge,ge->tag(),npoints);
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

  case 349:
#line 4349 "Gmsh.y"
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

  case 350:
#line 4393 "Gmsh.y"
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

  case 351:
#line 4432 "Gmsh.y"
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

  case 352:
#line 4457 "Gmsh.y"
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

  case 353:
#line 4469 "Gmsh.y"
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

  case 354:
#line 4481 "Gmsh.y"
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

  case 355:
#line 4493 "Gmsh.y"
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

  case 356:
#line 4505 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 357:
#line 4514 "Gmsh.y"
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

  case 358:
#line 4544 "Gmsh.y"
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

  case 359:
#line 4570 "Gmsh.y"
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

  case 360:
#line 4597 "Gmsh.y"
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

  case 361:
#line 4629 "Gmsh.y"
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

  case 362:
#line 4656 "Gmsh.y"
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

  case 363:
#line 4682 "Gmsh.y"
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

  case 364:
#line 4708 "Gmsh.y"
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

  case 365:
#line 4734 "Gmsh.y"
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

  case 366:
#line 4760 "Gmsh.y"
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

  case 367:
#line 4781 "Gmsh.y"
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

  case 368:
#line 4792 "Gmsh.y"
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

  case 369:
#line 4840 "Gmsh.y"
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

  case 370:
#line 4894 "Gmsh.y"
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

  case 371:
#line 4909 "Gmsh.y"
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

  case 372:
#line 4921 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 373:
#line 4932 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 374:
#line 4939 "Gmsh.y"
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

  case 375:
#line 4954 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 376:
#line 4967 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 377:
#line 4968 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 378:
#line 4969 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 379:
#line 4974 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 380:
#line 4980 "Gmsh.y"
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

  case 381:
#line 4992 "Gmsh.y"
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

  case 382:
#line 5010 "Gmsh.y"
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

  case 383:
#line 5037 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 384:
#line 5038 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 385:
#line 5039 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 386:
#line 5040 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 387:
#line 5041 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 388:
#line 5042 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 389:
#line 5043 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 390:
#line 5044 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 391:
#line 5046 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 392:
#line 5052 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 393:
#line 5053 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 394:
#line 5054 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 395:
#line 5055 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 396:
#line 5056 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 397:
#line 5057 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 398:
#line 5058 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 399:
#line 5059 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 400:
#line 5060 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 401:
#line 5061 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 402:
#line 5062 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 403:
#line 5063 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 404:
#line 5064 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 405:
#line 5065 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 406:
#line 5066 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 407:
#line 5067 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 408:
#line 5068 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 409:
#line 5069 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 410:
#line 5070 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 411:
#line 5071 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 412:
#line 5072 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 413:
#line 5073 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 414:
#line 5074 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 415:
#line 5075 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 416:
#line 5076 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 417:
#line 5077 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 418:
#line 5078 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 419:
#line 5079 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5080 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 421:
#line 5081 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 422:
#line 5082 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 423:
#line 5083 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 424:
#line 5084 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 425:
#line 5085 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 426:
#line 5086 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 427:
#line 5087 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 428:
#line 5088 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 429:
#line 5089 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 430:
#line 5098 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 431:
#line 5099 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 432:
#line 5100 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 433:
#line 5101 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 434:
#line 5102 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 435:
#line 5103 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 436:
#line 5104 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 437:
#line 5105 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 438:
#line 5106 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 439:
#line 5107 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 440:
#line 5108 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 441:
#line 5113 "Gmsh.y"
    { init_options(); ;}
    break;

  case 442:
#line 5115 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 443:
#line 5121 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 444:
#line 5123 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 445:
#line 5128 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 446:
#line 5133 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 447:
#line 5138 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 448:
#line 5143 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 449:
#line 5147 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 450:
#line 5151 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 451:
#line 5155 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 452:
#line 5159 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 453:
#line 5163 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 454:
#line 5167 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 455:
#line 5171 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 456:
#line 5177 "Gmsh.y"
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

  case 457:
#line 5192 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 458:
#line 5196 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 459:
#line 5202 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 460:
#line 5207 "Gmsh.y"
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

  case 461:
#line 5226 "Gmsh.y"
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

  case 462:
#line 5246 "Gmsh.y"
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

  case 463:
#line 5277 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 464:
#line 5281 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 465:
#line 5285 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 466:
#line 5289 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 467:
#line 5293 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 468:
#line 5297 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 469:
#line 5301 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 470:
#line 5306 "Gmsh.y"
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

  case 471:
#line 5316 "Gmsh.y"
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

  case 472:
#line 5326 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 473:
#line 5331 "Gmsh.y"
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

  case 474:
#line 5342 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 475:
#line 5351 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 476:
#line 5356 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 477:
#line 5361 "Gmsh.y"
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

  case 478:
#line 5388 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 479:
#line 5390 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 480:
#line 5395 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 481:
#line 5397 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 482:
#line 5402 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 483:
#line 5409 "Gmsh.y"
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

  case 484:
#line 5425 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 485:
#line 5427 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 486:
#line 5432 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 487:
#line 5441 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 488:
#line 5443 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 489:
#line 5448 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 490:
#line 5450 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 491:
#line 5455 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 492:
#line 5459 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 493:
#line 5463 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 494:
#line 5467 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 495:
#line 5471 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 496:
#line 5478 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 497:
#line 5482 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 498:
#line 5486 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 499:
#line 5490 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 500:
#line 5497 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 501:
#line 5502 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 502:
#line 5509 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 503:
#line 5514 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 504:
#line 5518 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 505:
#line 5523 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 506:
#line 5527 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 507:
#line 5535 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 508:
#line 5546 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 509:
#line 5550 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 510:
#line 5554 "Gmsh.y"
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

  case 511:
#line 5568 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 512:
#line 5576 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 513:
#line 5584 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 514:
#line 5591 "Gmsh.y"
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

  case 515:
#line 5601 "Gmsh.y"
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

  case 516:
#line 5624 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 517:
#line 5629 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 518:
#line 5635 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 519:
#line 5640 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 520:
#line 5646 "Gmsh.y"
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

  case 521:
#line 5657 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 522:
#line 5664 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 523:
#line 5669 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 524:
#line 5675 "Gmsh.y"
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

  case 525:
#line 5687 "Gmsh.y"
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

  case 526:
#line 5701 "Gmsh.y"
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

  case 527:
#line 5711 "Gmsh.y"
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

  case 528:
#line 5721 "Gmsh.y"
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

  case 529:
#line 5731 "Gmsh.y"
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

  case 530:
#line 5743 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 531:
#line 5747 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 532:
#line 5752 "Gmsh.y"
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

  case 533:
#line 5764 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 534:
#line 5768 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 535:
#line 5772 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 536:
#line 5776 "Gmsh.y"
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

  case 537:
#line 5794 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 538:
#line 5802 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 539:
#line 5810 "Gmsh.y"
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

  case 540:
#line 5839 "Gmsh.y"
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

  case 541:
#line 5849 "Gmsh.y"
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

  case 542:
#line 5865 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 543:
#line 5876 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 544:
#line 5881 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 545:
#line 5885 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 546:
#line 5889 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 547:
#line 5901 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 548:
#line 5905 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 549:
#line 5917 "Gmsh.y"
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

  case 550:
#line 5934 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 551:
#line 5944 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 552:
#line 5948 "Gmsh.y"
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

  case 553:
#line 5963 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 554:
#line 5968 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 555:
#line 5975 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 556:
#line 5979 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 557:
#line 5984 "Gmsh.y"
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

  case 558:
#line 5998 "Gmsh.y"
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

  case 559:
#line 6014 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 560:
#line 6018 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 561:
#line 6022 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 562:
#line 6026 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 563:
#line 6030 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 564:
#line 6038 "Gmsh.y"
    {
      std::string name = GModel::current()->getElementaryName((yyvsp[(1) - (4)].i), (int)(yyvsp[(3) - (4)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 565:
#line 6044 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 566:
#line 6053 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 567:
#line 6057 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 568:
#line 6061 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 569:
#line 6069 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 570:
#line 6075 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 571:
#line 6081 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 572:
#line 6085 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 573:
#line 6093 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 574:
#line 6101 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 575:
#line 6108 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 576:
#line 6117 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 577:
#line 6121 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 578:
#line 6125 "Gmsh.y"
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

  case 579:
#line 6140 "Gmsh.y"
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

  case 580:
#line 6154 "Gmsh.y"
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

  case 581:
#line 6168 "Gmsh.y"
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

  case 582:
#line 6180 "Gmsh.y"
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

  case 583:
#line 6196 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 584:
#line 6205 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 585:
#line 6214 "Gmsh.y"
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

  case 586:
#line 6224 "Gmsh.y"
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

  case 587:
#line 6235 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 588:
#line 6243 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 589:
#line 6251 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 590:
#line 6255 "Gmsh.y"
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

  case 591:
#line 6274 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 592:
#line 6281 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 593:
#line 6287 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 594:
#line 6294 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 595:
#line 6301 "Gmsh.y"
    { init_options(); ;}
    break;

  case 596:
#line 6303 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 597:
#line 6311 "Gmsh.y"
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

  case 598:
#line 6335 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 599:
#line 6337 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 600:
#line 6343 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 601:
#line 6348 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 602:
#line 6350 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 603:
#line 6355 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 604:
#line 6360 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 605:
#line 6365 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 606:
#line 6367 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 607:
#line 6371 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 608:
#line 6383 "Gmsh.y"
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

  case 609:
#line 6397 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 610:
#line 6401 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 611:
#line 6408 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 612:
#line 6416 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 613:
#line 6424 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 614:
#line 6435 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 615:
#line 6437 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 616:
#line 6440 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14361 "Gmsh.tab.cpp"
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


#line 6443 "Gmsh.y"


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

