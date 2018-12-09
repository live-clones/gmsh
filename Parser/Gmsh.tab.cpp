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
     tOnelabAction = 327,
     tOnelabRun = 328,
     tCodeName = 329,
     tCpu = 330,
     tMemory = 331,
     tTotalMemory = 332,
     tCreateTopology = 333,
     tCreateGeometry = 334,
     tRenumberMeshNodes = 335,
     tRenumberMeshElements = 336,
     tDistanceFunction = 337,
     tDefineConstant = 338,
     tUndefineConstant = 339,
     tDefineNumber = 340,
     tDefineStruct = 341,
     tNameStruct = 342,
     tDimNameSpace = 343,
     tAppend = 344,
     tDefineString = 345,
     tSetNumber = 346,
     tSetTag = 347,
     tSetString = 348,
     tPoint = 349,
     tCircle = 350,
     tEllipse = 351,
     tCurve = 352,
     tSphere = 353,
     tPolarSphere = 354,
     tSurface = 355,
     tSpline = 356,
     tVolume = 357,
     tBox = 358,
     tCylinder = 359,
     tCone = 360,
     tTorus = 361,
     tEllipsoid = 362,
     tQuadric = 363,
     tShapeFromFile = 364,
     tRectangle = 365,
     tDisk = 366,
     tWire = 367,
     tGeoEntity = 368,
     tCharacteristic = 369,
     tLength = 370,
     tParametric = 371,
     tElliptic = 372,
     tRefineMesh = 373,
     tAdaptMesh = 374,
     tRelocateMesh = 375,
     tReorientMesh = 376,
     tSetFactory = 377,
     tThruSections = 378,
     tWedge = 379,
     tFillet = 380,
     tChamfer = 381,
     tPlane = 382,
     tRuled = 383,
     tTransfinite = 384,
     tPhysical = 385,
     tCompound = 386,
     tPeriodic = 387,
     tParent = 388,
     tUsing = 389,
     tPlugin = 390,
     tDegenerated = 391,
     tRecursive = 392,
     tRotate = 393,
     tTranslate = 394,
     tSymmetry = 395,
     tDilate = 396,
     tExtrude = 397,
     tLevelset = 398,
     tAffine = 399,
     tBooleanUnion = 400,
     tBooleanIntersection = 401,
     tBooleanDifference = 402,
     tBooleanSection = 403,
     tBooleanFragments = 404,
     tThickSolid = 405,
     tRecombine = 406,
     tSmoother = 407,
     tSplit = 408,
     tDelete = 409,
     tCoherence = 410,
     tIntersect = 411,
     tMeshAlgorithm = 412,
     tReverseMesh = 413,
     tLayers = 414,
     tScaleLast = 415,
     tHole = 416,
     tAlias = 417,
     tAliasWithOptions = 418,
     tCopyOptions = 419,
     tQuadTriAddVerts = 420,
     tQuadTriNoNewVerts = 421,
     tRecombLaterals = 422,
     tTransfQuadTri = 423,
     tText2D = 424,
     tText3D = 425,
     tInterpolationScheme = 426,
     tTime = 427,
     tCombine = 428,
     tBSpline = 429,
     tBezier = 430,
     tNurbs = 431,
     tNurbsOrder = 432,
     tNurbsKnots = 433,
     tColor = 434,
     tColorTable = 435,
     tFor = 436,
     tIn = 437,
     tEndFor = 438,
     tIf = 439,
     tElseIf = 440,
     tElse = 441,
     tEndIf = 442,
     tExit = 443,
     tAbort = 444,
     tField = 445,
     tReturn = 446,
     tCall = 447,
     tSlide = 448,
     tMacro = 449,
     tShow = 450,
     tHide = 451,
     tGetValue = 452,
     tGetStringValue = 453,
     tGetEnv = 454,
     tGetString = 455,
     tGetNumber = 456,
     tUnique = 457,
     tHomology = 458,
     tCohomology = 459,
     tBetti = 460,
     tExists = 461,
     tFileExists = 462,
     tGetForced = 463,
     tGetForcedStr = 464,
     tGMSH_MAJOR_VERSION = 465,
     tGMSH_MINOR_VERSION = 466,
     tGMSH_PATCH_VERSION = 467,
     tGmshExecutableName = 468,
     tSetPartition = 469,
     tNameToString = 470,
     tStringToName = 471,
     tAFFECTDIVIDE = 472,
     tAFFECTTIMES = 473,
     tAFFECTMINUS = 474,
     tAFFECTPLUS = 475,
     tOR = 476,
     tAND = 477,
     tNOTEQUAL = 478,
     tEQUAL = 479,
     tGREATERGREATER = 480,
     tLESSLESS = 481,
     tGREATEROREQUAL = 482,
     tLESSOREQUAL = 483,
     UNARYPREC = 484,
     tMINUSMINUS = 485,
     tPLUSPLUS = 486
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
#define tOnelabAction 327
#define tOnelabRun 328
#define tCodeName 329
#define tCpu 330
#define tMemory 331
#define tTotalMemory 332
#define tCreateTopology 333
#define tCreateGeometry 334
#define tRenumberMeshNodes 335
#define tRenumberMeshElements 336
#define tDistanceFunction 337
#define tDefineConstant 338
#define tUndefineConstant 339
#define tDefineNumber 340
#define tDefineStruct 341
#define tNameStruct 342
#define tDimNameSpace 343
#define tAppend 344
#define tDefineString 345
#define tSetNumber 346
#define tSetTag 347
#define tSetString 348
#define tPoint 349
#define tCircle 350
#define tEllipse 351
#define tCurve 352
#define tSphere 353
#define tPolarSphere 354
#define tSurface 355
#define tSpline 356
#define tVolume 357
#define tBox 358
#define tCylinder 359
#define tCone 360
#define tTorus 361
#define tEllipsoid 362
#define tQuadric 363
#define tShapeFromFile 364
#define tRectangle 365
#define tDisk 366
#define tWire 367
#define tGeoEntity 368
#define tCharacteristic 369
#define tLength 370
#define tParametric 371
#define tElliptic 372
#define tRefineMesh 373
#define tAdaptMesh 374
#define tRelocateMesh 375
#define tReorientMesh 376
#define tSetFactory 377
#define tThruSections 378
#define tWedge 379
#define tFillet 380
#define tChamfer 381
#define tPlane 382
#define tRuled 383
#define tTransfinite 384
#define tPhysical 385
#define tCompound 386
#define tPeriodic 387
#define tParent 388
#define tUsing 389
#define tPlugin 390
#define tDegenerated 391
#define tRecursive 392
#define tRotate 393
#define tTranslate 394
#define tSymmetry 395
#define tDilate 396
#define tExtrude 397
#define tLevelset 398
#define tAffine 399
#define tBooleanUnion 400
#define tBooleanIntersection 401
#define tBooleanDifference 402
#define tBooleanSection 403
#define tBooleanFragments 404
#define tThickSolid 405
#define tRecombine 406
#define tSmoother 407
#define tSplit 408
#define tDelete 409
#define tCoherence 410
#define tIntersect 411
#define tMeshAlgorithm 412
#define tReverseMesh 413
#define tLayers 414
#define tScaleLast 415
#define tHole 416
#define tAlias 417
#define tAliasWithOptions 418
#define tCopyOptions 419
#define tQuadTriAddVerts 420
#define tQuadTriNoNewVerts 421
#define tRecombLaterals 422
#define tTransfQuadTri 423
#define tText2D 424
#define tText3D 425
#define tInterpolationScheme 426
#define tTime 427
#define tCombine 428
#define tBSpline 429
#define tBezier 430
#define tNurbs 431
#define tNurbsOrder 432
#define tNurbsKnots 433
#define tColor 434
#define tColorTable 435
#define tFor 436
#define tIn 437
#define tEndFor 438
#define tIf 439
#define tElseIf 440
#define tElse 441
#define tEndIf 442
#define tExit 443
#define tAbort 444
#define tField 445
#define tReturn 446
#define tCall 447
#define tSlide 448
#define tMacro 449
#define tShow 450
#define tHide 451
#define tGetValue 452
#define tGetStringValue 453
#define tGetEnv 454
#define tGetString 455
#define tGetNumber 456
#define tUnique 457
#define tHomology 458
#define tCohomology 459
#define tBetti 460
#define tExists 461
#define tFileExists 462
#define tGetForced 463
#define tGetForcedStr 464
#define tGMSH_MAJOR_VERSION 465
#define tGMSH_MINOR_VERSION 466
#define tGMSH_PATCH_VERSION 467
#define tGmshExecutableName 468
#define tSetPartition 469
#define tNameToString 470
#define tStringToName 471
#define tAFFECTDIVIDE 472
#define tAFFECTTIMES 473
#define tAFFECTMINUS 474
#define tAFFECTPLUS 475
#define tOR 476
#define tAND 477
#define tNOTEQUAL 478
#define tEQUAL 479
#define tGREATERGREATER 480
#define tLESSLESS 481
#define tGREATEROREQUAL 482
#define tLESSOREQUAL 483
#define UNARYPREC 484
#define tMINUSMINUS 485
#define tPLUSPLUS 486




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

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
#include "Generator.h"
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
#line 742 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 755 "Gmsh.tab.cpp"

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
#define YYLAST   16369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  611
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2178

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   486

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   239,     2,   251,     2,   236,   238,     2,
     244,   245,   234,   232,   253,   233,   250,   235,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     226,     2,   227,   221,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   246,     2,   247,   243,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   248,   237,   249,   252,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   222,   223,   224,   225,
     228,   229,   230,   231,   240,   241,   242
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
     707,   711,   712,   718,   724,   730,   731,   734,   742,   750,
     758,   767,   776,   784,   792,   804,   812,   821,   830,   839,
     849,   853,   858,   869,   877,   885,   893,   901,   909,   917,
     925,   933,   941,   949,   958,   966,   974,   983,   992,  1005,
    1006,  1016,  1018,  1020,  1022,  1024,  1029,  1031,  1033,  1035,
    1040,  1042,  1044,  1049,  1051,  1053,  1055,  1060,  1066,  1078,
    1084,  1094,  1104,  1109,  1119,  1129,  1131,  1133,  1134,  1137,
    1144,  1152,  1160,  1167,  1175,  1184,  1195,  1210,  1227,  1240,
    1255,  1270,  1285,  1300,  1309,  1318,  1325,  1330,  1336,  1343,
    1350,  1354,  1359,  1363,  1369,  1376,  1382,  1387,  1391,  1396,
    1400,  1405,  1411,  1416,  1422,  1426,  1432,  1440,  1448,  1452,
    1460,  1464,  1467,  1470,  1473,  1476,  1479,  1495,  1498,  1501,
    1504,  1507,  1510,  1513,  1516,  1533,  1545,  1552,  1561,  1570,
    1581,  1583,  1586,  1589,  1591,  1595,  1599,  1604,  1609,  1611,
    1613,  1619,  1631,  1645,  1646,  1654,  1655,  1669,  1670,  1686,
    1687,  1694,  1704,  1707,  1711,  1722,  1736,  1738,  1741,  1747,
    1755,  1758,  1761,  1765,  1768,  1772,  1775,  1779,  1789,  1796,
    1798,  1800,  1802,  1804,  1806,  1807,  1810,  1814,  1818,  1823,
    1833,  1838,  1853,  1854,  1858,  1859,  1861,  1862,  1865,  1866,
    1869,  1870,  1873,  1880,  1888,  1895,  1901,  1905,  1914,  1923,
    1932,  1941,  1950,  1956,  1961,  1968,  1980,  1992,  2011,  2030,
    2043,  2056,  2069,  2080,  2085,  2090,  2095,  2100,  2105,  2108,
    2112,  2119,  2121,  2123,  2125,  2128,  2134,  2142,  2153,  2155,
    2159,  2162,  2165,  2168,  2172,  2176,  2180,  2184,  2188,  2192,
    2196,  2200,  2204,  2208,  2212,  2216,  2220,  2224,  2228,  2232,
    2236,  2240,  2246,  2251,  2256,  2261,  2266,  2271,  2276,  2281,
    2286,  2291,  2296,  2303,  2308,  2313,  2318,  2323,  2328,  2333,
    2338,  2343,  2350,  2357,  2364,  2369,  2371,  2373,  2375,  2377,
    2379,  2381,  2383,  2385,  2387,  2389,  2391,  2392,  2399,  2401,
    2406,  2413,  2415,  2420,  2425,  2430,  2437,  2443,  2451,  2460,
    2471,  2476,  2481,  2488,  2493,  2497,  2500,  2506,  2512,  2516,
    2522,  2529,  2538,  2545,  2554,  2561,  2566,  2574,  2581,  2588,
    2595,  2600,  2607,  2612,  2613,  2616,  2617,  2620,  2621,  2629,
    2631,  2635,  2637,  2639,  2642,  2643,  2647,  2649,  2652,  2655,
    2659,  2663,  2675,  2685,  2693,  2701,  2703,  2707,  2709,  2711,
    2714,  2718,  2723,  2729,  2731,  2735,  2737,  2740,  2744,  2748,
    2754,  2759,  2764,  2767,  2772,  2775,  2779,  2783,  2800,  2806,
    2808,  2810,  2812,  2816,  2822,  2830,  2835,  2840,  2845,  2852,
    2859,  2868,  2877,  2882,  2897,  2902,  2907,  2909,  2911,  2915,
    2919,  2929,  2937,  2939,  2945,  2949,  2956,  2958,  2962,  2964,
    2966,  2971,  2976,  2980,  2986,  2993,  3002,  3009,  3015,  3021,
    3027,  3033,  3035,  3040,  3042,  3044,  3046,  3048,  3053,  3060,
    3065,  3072,  3078,  3086,  3091,  3096,  3101,  3110,  3115,  3120,
    3125,  3130,  3139,  3148,  3155,  3160,  3167,  3172,  3174,  3179,
    3184,  3185,  3192,  3197,  3200,  3205,  3210,  3212,  3214,  3218,
    3220,  3222,  3226,  3230,  3234,  3240,  3248,  3254,  3260,  3269,
    3271,  3273
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     255,     0,    -1,   256,    -1,     1,     6,    -1,    -1,   256,
     257,    -1,   259,    -1,   260,    -1,   280,    -1,   122,   244,
     356,   245,     6,    -1,   298,    -1,   304,    -1,   308,    -1,
     309,    -1,   310,    -1,   311,    -1,   315,    -1,   324,    -1,
     325,    -1,   331,    -1,   332,    -1,   314,    -1,   313,    -1,
     312,    -1,   307,    -1,   334,    -1,   227,    -1,   228,    -1,
      44,   244,   356,   245,     6,    -1,    45,   244,   356,   245,
       6,    -1,    44,   244,   356,   245,   258,   356,     6,    -1,
      44,   244,   356,   253,   352,   245,     6,    -1,    45,   244,
     356,   253,   352,   245,     6,    -1,    44,   244,   356,   253,
     352,   245,   258,   356,     6,    -1,   366,   356,   248,   261,
     249,     6,    -1,   162,     4,   246,   335,   247,     6,    -1,
     163,     4,   246,   335,   247,     6,    -1,   164,     4,   246,
     335,   253,   335,   247,     6,    -1,    -1,   261,   264,    -1,
     261,   268,    -1,   261,   271,    -1,   261,   273,    -1,   261,
     274,    -1,   335,    -1,   262,   253,   335,    -1,   335,    -1,
     263,   253,   335,    -1,    -1,    -1,     4,   265,   244,   262,
     245,   266,   248,   263,   249,     6,    -1,   356,    -1,   267,
     253,   356,    -1,    -1,   169,   244,   335,   253,   335,   253,
     335,   245,   269,   248,   267,   249,     6,    -1,   356,    -1,
     270,   253,   356,    -1,    -1,   170,   244,   335,   253,   335,
     253,   335,   253,   335,   245,   272,   248,   270,   249,     6,
      -1,   171,   248,   348,   249,   248,   348,   249,     6,    -1,
     171,   248,   348,   249,   248,   348,   249,   248,   348,   249,
     248,   348,   249,     6,    -1,    -1,   172,   275,   248,   263,
     249,     6,    -1,     7,    -1,   220,    -1,   219,    -1,   218,
      -1,   217,    -1,   242,    -1,   241,    -1,   244,    -1,   246,
      -1,   245,    -1,   247,    -1,    83,   246,   282,   247,     6,
      -1,    84,   246,   286,   247,     6,    -1,   340,     6,    -1,
      91,   278,   357,   253,   335,   279,     6,    -1,    93,   278,
     366,   253,   357,   279,     6,    -1,   366,   276,   349,     6,
      -1,   366,   277,     6,    -1,   366,   278,   279,   276,   349,
       6,    -1,   366,   278,   248,   352,   249,   279,   276,   349,
       6,    -1,   366,   246,   335,   247,   276,   335,     6,    -1,
     366,   246,   335,   247,   277,     6,    -1,   366,   244,   335,
     245,   276,   335,     6,    -1,   366,   244,   335,   245,   277,
       6,    -1,   366,     7,   357,     6,    -1,   366,   278,   279,
       7,    46,   278,   279,     6,    -1,   366,   278,   279,     7,
      46,   278,   361,   279,     6,    -1,   366,   278,   279,   220,
      46,   278,   361,   279,     6,    -1,   366,   250,     4,     7,
     357,     6,    -1,   366,   246,   335,   247,   250,     4,     7,
     357,     6,    -1,   366,   250,     4,   276,   335,     6,    -1,
     366,   246,   335,   247,   250,     4,   276,   335,     6,    -1,
     366,   250,     4,   277,     6,    -1,   366,   246,   335,   247,
     250,     4,   277,     6,    -1,   366,   250,   179,   250,     4,
       7,   353,     6,    -1,   366,   246,   335,   247,   250,   179,
     250,     4,     7,   353,     6,    -1,   366,   250,   180,     7,
     354,     6,    -1,   366,   246,   335,   247,   250,   180,     7,
     354,     6,    -1,   366,   190,     7,   349,     6,    -1,   190,
     246,   335,   247,     7,     4,     6,    -1,   190,   246,   335,
     247,     7,   103,     6,    -1,   190,   246,   335,   247,     7,
     104,     6,    -1,   190,   246,   335,   247,   250,     4,     7,
     335,     6,    -1,   190,   246,   335,   247,   250,     4,     7,
     357,     6,    -1,   190,   246,   335,   247,   250,     4,     7,
     248,   352,   249,     6,    -1,   190,   246,   335,   247,   250,
       4,     6,    -1,   135,   244,     4,   245,   250,     4,     7,
     335,     6,    -1,   135,   244,     4,   245,   250,     4,     7,
     357,     6,    -1,    -1,   253,    -1,    -1,   282,   281,   366,
      -1,   282,   281,   366,     7,   335,    -1,    -1,   282,   281,
     366,     7,   248,   349,   283,   288,   249,    -1,    -1,   282,
     281,   366,   278,   279,     7,   248,   349,   284,   288,   249,
      -1,   282,   281,   366,     7,   357,    -1,    -1,   282,   281,
     366,     7,   248,   357,   285,   292,   249,    -1,    -1,   286,
     281,   356,    -1,   335,     7,   357,    -1,   287,   253,   335,
       7,   357,    -1,   351,     7,   366,   244,   245,    -1,    -1,
     253,   290,    -1,    -1,   290,    -1,   291,    -1,   290,   253,
     291,    -1,     4,   349,    -1,     4,    -1,     4,   248,   287,
     249,    -1,     4,   357,    -1,     4,   360,    -1,    -1,   253,
     293,    -1,   294,    -1,   293,   253,   294,    -1,     4,   335,
      -1,     4,   357,    -1,   194,   357,    -1,     4,   362,    -1,
       4,   360,    -1,   335,    -1,   357,    -1,   357,   253,   335,
      -1,    -1,   182,    98,   248,   335,   249,    -1,   134,    94,
     248,   352,   249,    -1,   134,   113,   248,   352,   249,    -1,
      -1,   127,   346,    -1,    94,   244,   335,   245,     7,   346,
       6,    -1,    97,   244,   335,   245,     7,   349,     6,    -1,
     101,   244,   335,   245,     7,   349,     6,    -1,    95,   244,
     335,   245,     7,   349,   297,     6,    -1,    96,   244,   335,
     245,     7,   349,   297,     6,    -1,   174,   244,   335,   245,
       7,   349,     6,    -1,   175,   244,   335,   245,     7,   349,
       6,    -1,   176,   244,   335,   245,     7,   349,   178,   349,
     177,   335,     6,    -1,   112,   244,   335,   245,     7,   349,
       6,    -1,    97,     4,   244,   335,   245,     7,   349,     6,
      -1,   127,   100,   244,   335,   245,     7,   349,     6,    -1,
     100,   244,   335,   245,     7,   349,   296,     6,    -1,   128,
     100,   244,   335,   245,     7,   349,   296,     6,    -1,    13,
      14,     6,    -1,    14,   100,   335,     6,    -1,   116,   100,
     244,   335,   245,     7,     5,     5,     5,     6,    -1,    98,
     244,   335,   245,     7,   349,     6,    -1,    99,   244,   335,
     245,     7,   349,     6,    -1,   103,   244,   335,   245,     7,
     349,     6,    -1,   106,   244,   335,   245,     7,   349,     6,
      -1,   110,   244,   335,   245,     7,   349,     6,    -1,   111,
     244,   335,   245,     7,   349,     6,    -1,   104,   244,   335,
     245,     7,   349,     6,    -1,   105,   244,   335,   245,     7,
     349,     6,    -1,   124,   244,   335,   245,     7,   349,     6,
      -1,   150,   244,   335,   245,     7,   349,     6,    -1,   100,
       4,   244,   335,   245,     7,   349,     6,    -1,   102,   244,
     335,   245,     7,   349,     6,    -1,   123,   244,   335,   245,
       7,   349,     6,    -1,   128,   123,   244,   335,   245,     7,
     349,     6,    -1,   131,   301,   244,   335,   245,     7,   349,
       6,    -1,   131,   301,   244,   335,   245,     7,   349,     4,
     248,   348,   249,     6,    -1,    -1,   130,   300,   299,   244,
     295,   245,   276,   349,     6,    -1,    94,    -1,    97,    -1,
     100,    -1,   102,    -1,   113,   248,   335,   249,    -1,    97,
      -1,   100,    -1,   102,    -1,   113,   248,   335,   249,    -1,
      97,    -1,   100,    -1,   113,   248,   335,   249,    -1,    94,
      -1,    97,    -1,   100,    -1,   113,   248,   335,   249,    -1,
     139,   346,   248,   305,   249,    -1,   138,   248,   346,   253,
     346,   253,   335,   249,   248,   305,   249,    -1,   140,   346,
     248,   305,   249,    -1,   141,   248,   346,   253,   335,   249,
     248,   305,   249,    -1,   141,   248,   346,   253,   346,   249,
     248,   305,   249,    -1,     4,   248,   305,   249,    -1,   156,
      97,   248,   352,   249,   100,   248,   335,   249,    -1,   153,
      97,   244,   335,   245,   248,   352,   249,     6,    -1,   306,
      -1,   304,    -1,    -1,   306,   298,    -1,   306,   300,   248,
     352,   249,     6,    -1,   306,   130,   300,   248,   352,   249,
       6,    -1,   306,   133,   300,   248,   352,   249,     6,    -1,
     306,   300,   248,     8,   249,     6,    -1,   306,   130,   300,
     248,     8,   249,     6,    -1,   143,   127,   244,   335,   245,
       7,   349,     6,    -1,   143,    94,   244,   335,   245,     7,
     248,   348,   249,     6,    -1,   143,   127,   244,   335,   245,
       7,   248,   346,   253,   346,   253,   352,   249,     6,    -1,
     143,   127,   244,   335,   245,     7,   248,   346,   253,   346,
     253,   346,   253,   352,   249,     6,    -1,   143,    98,   244,
     335,   245,     7,   248,   346,   253,   352,   249,     6,    -1,
     143,   104,   244,   335,   245,     7,   248,   346,   253,   346,
     253,   352,   249,     6,    -1,   143,   105,   244,   335,   245,
       7,   248,   346,   253,   346,   253,   352,   249,     6,    -1,
     143,   107,   244,   335,   245,     7,   248,   346,   253,   346,
     253,   352,   249,     6,    -1,   143,   108,   244,   335,   245,
       7,   248,   346,   253,   346,   253,   352,   249,     6,    -1,
     143,     4,   244,   335,   245,     7,   349,     6,    -1,   143,
       4,   244,   335,   245,     7,     5,     6,    -1,   143,     4,
     248,   335,   249,     6,    -1,   154,   248,   306,   249,    -1,
     137,   154,   248,   306,   249,    -1,   154,   190,   246,   335,
     247,     6,    -1,   154,     4,   246,   335,   247,     6,    -1,
     154,   366,     6,    -1,   154,     4,     4,     6,    -1,   154,
      86,     6,    -1,   179,   353,   248,   306,   249,    -1,   137,
     179,   353,   248,   306,   249,    -1,   214,   335,   248,   306,
     249,    -1,   195,   248,     8,   249,    -1,   195,     5,     6,
      -1,   196,   248,     8,   249,    -1,   196,     5,     6,    -1,
     195,   248,   306,   249,    -1,   137,   195,   248,   306,   249,
      -1,   196,   248,   306,   249,    -1,   137,   196,   248,   306,
     249,    -1,   366,   357,     6,    -1,    73,   244,   363,   245,
       6,    -1,   366,   366,   246,   335,   247,   356,     6,    -1,
     366,   366,   366,   246,   335,   247,     6,    -1,   366,   335,
       6,    -1,   135,   244,     4,   245,   250,     4,     6,    -1,
     173,     4,     6,    -1,   188,     6,    -1,   189,     6,    -1,
      70,     6,    -1,    71,     6,    -1,    64,     6,    -1,    64,
     248,   335,   253,   335,   253,   335,   253,   335,   253,   335,
     253,   335,   249,     6,    -1,    65,     6,    -1,    66,     6,
      -1,    78,     6,    -1,    79,     6,    -1,    80,     6,    -1,
      81,     6,    -1,   118,     6,    -1,   119,   248,   352,   249,
     248,   352,   249,   248,   348,   249,   248,   335,   253,   335,
     249,     6,    -1,   193,   244,   248,   352,   249,   253,   357,
     253,   357,   245,     6,    -1,   181,   244,   335,     8,   335,
     245,    -1,   181,   244,   335,     8,   335,     8,   335,   245,
      -1,   181,     4,   182,   248,   335,     8,   335,   249,    -1,
     181,     4,   182,   248,   335,     8,   335,     8,   335,   249,
      -1,   183,    -1,   194,     4,    -1,   194,   357,    -1,   191,
      -1,   192,   366,     6,    -1,   192,   357,     6,    -1,   184,
     244,   335,   245,    -1,   185,   244,   335,   245,    -1,   186,
      -1,   187,    -1,   142,   346,   248,   306,   249,    -1,   142,
     248,   346,   253,   346,   253,   335,   249,   248,   306,   249,
      -1,   142,   248,   346,   253,   346,   253,   346,   253,   335,
     249,   248,   306,   249,    -1,    -1,   142,   346,   248,   306,
     316,   320,   249,    -1,    -1,   142,   248,   346,   253,   346,
     253,   335,   249,   248,   306,   317,   320,   249,    -1,    -1,
     142,   248,   346,   253,   346,   253,   346,   253,   335,   249,
     248,   306,   318,   320,   249,    -1,    -1,   142,   248,   306,
     319,   320,   249,    -1,   142,   248,   306,   249,   134,   112,
     248,   335,   249,    -1,   123,   349,    -1,   128,   123,   349,
      -1,   125,   248,   352,   249,   248,   352,   249,   248,   352,
     249,    -1,   126,   248,   352,   249,   248,   352,   249,   248,
     352,   249,   248,   352,   249,    -1,   321,    -1,   320,   321,
      -1,   159,   248,   335,   249,     6,    -1,   159,   248,   349,
     253,   349,   249,     6,    -1,   160,     6,    -1,   151,     6,
      -1,   151,   335,     6,    -1,   165,     6,    -1,   165,   167,
       6,    -1,   166,     6,    -1,   166,   167,     6,    -1,   161,
     244,   335,   245,     7,   349,   134,   335,     6,    -1,   134,
       4,   246,   335,   247,     6,    -1,   145,    -1,   146,    -1,
     147,    -1,   148,    -1,   149,    -1,    -1,   154,     6,    -1,
     137,   154,     6,    -1,   154,   335,     6,    -1,   137,   154,
     335,     6,    -1,   322,   248,   306,   323,   249,   248,   306,
     323,   249,    -1,   109,   244,   356,   245,    -1,   322,   244,
     335,   245,     7,   248,   306,   323,   249,   248,   306,   323,
     249,     6,    -1,    -1,   134,     4,   335,    -1,    -1,     4,
      -1,    -1,     7,   349,    -1,    -1,     7,   335,    -1,    -1,
     144,   349,    -1,   114,   115,   350,     7,   335,     6,    -1,
     129,    97,   350,     7,   335,   326,     6,    -1,   129,   100,
     350,   328,   327,     6,    -1,   129,   102,   350,   328,     6,
      -1,   168,   350,     6,    -1,    92,    94,   244,   335,   253,
     335,   245,     6,    -1,    92,    97,   244,   335,   253,   335,
     245,     6,    -1,    92,   100,   244,   335,   253,   335,   245,
       6,    -1,    92,   102,   244,   335,   253,   335,   245,     6,
      -1,   157,   100,   248,   352,   249,     7,   335,     6,    -1,
     151,   100,   350,   329,     6,    -1,   151,   102,   350,     6,
      -1,   152,   100,   350,     7,   335,     6,    -1,   132,    97,
     248,   352,   249,     7,   248,   352,   249,   330,     6,    -1,
     132,   100,   248,   352,   249,     7,   248,   352,   249,   330,
       6,    -1,   132,    97,   248,   352,   249,     7,   248,   352,
     249,   138,   248,   346,   253,   346,   253,   335,   249,     6,
      -1,   132,   100,   248,   352,   249,     7,   248,   352,   249,
     138,   248,   346,   253,   346,   253,   335,   249,     6,    -1,
     132,    97,   248,   352,   249,     7,   248,   352,   249,   139,
     346,     6,    -1,   132,   100,   248,   352,   249,     7,   248,
     352,   249,   139,   346,     6,    -1,   132,   100,   335,   248,
     352,   249,     7,   335,   248,   352,   249,     6,    -1,   300,
     248,   352,   249,   182,   300,   248,   335,   249,     6,    -1,
     158,   302,   350,     6,    -1,   120,   303,   350,     6,    -1,
     121,   102,   349,     6,    -1,   136,    97,   349,     6,    -1,
     131,   301,   349,     6,    -1,   155,     6,    -1,   155,     4,
       6,    -1,   155,    94,   248,   352,   249,     6,    -1,   203,
      -1,   204,    -1,   205,    -1,   333,     6,    -1,   333,   248,
     349,   249,     6,    -1,   333,   248,   349,   253,   349,   249,
       6,    -1,   333,   244,   349,   245,   248,   349,   253,   349,
     249,     6,    -1,   336,    -1,   244,   335,   245,    -1,   233,
     335,    -1,   232,   335,    -1,   239,   335,    -1,   335,   233,
     335,    -1,   335,   232,   335,    -1,   335,   234,   335,    -1,
     335,   235,   335,    -1,   335,   237,   335,    -1,   335,   238,
     335,    -1,   335,   236,   335,    -1,   335,   243,   335,    -1,
     335,   226,   335,    -1,   335,   227,   335,    -1,   335,   231,
     335,    -1,   335,   230,   335,    -1,   335,   225,   335,    -1,
     335,   224,   335,    -1,   335,   223,   335,    -1,   335,   222,
     335,    -1,   335,   228,   335,    -1,   335,   229,   335,    -1,
     335,   221,   335,     8,   335,    -1,    16,   278,   335,   279,
      -1,    17,   278,   335,   279,    -1,    18,   278,   335,   279,
      -1,    19,   278,   335,   279,    -1,    20,   278,   335,   279,
      -1,    21,   278,   335,   279,    -1,    22,   278,   335,   279,
      -1,    23,   278,   335,   279,    -1,    24,   278,   335,   279,
      -1,    26,   278,   335,   279,    -1,    27,   278,   335,   253,
     335,   279,    -1,    28,   278,   335,   279,    -1,    29,   278,
     335,   279,    -1,    30,   278,   335,   279,    -1,    31,   278,
     335,   279,    -1,    32,   278,   335,   279,    -1,    33,   278,
     335,   279,    -1,    34,   278,   335,   279,    -1,    35,   278,
     335,   279,    -1,    36,   278,   335,   253,   335,   279,    -1,
      37,   278,   335,   253,   335,   279,    -1,    38,   278,   335,
     253,   335,   279,    -1,    25,   278,   335,   279,    -1,     3,
      -1,    10,    -1,    15,    -1,    11,    -1,    12,    -1,   210,
      -1,   211,    -1,   212,    -1,    75,    -1,    76,    -1,    77,
      -1,    -1,    85,   278,   335,   337,   288,   279,    -1,   340,
      -1,   201,   278,   356,   279,    -1,   201,   278,   356,   253,
     335,   279,    -1,   342,    -1,   366,   246,   335,   247,    -1,
     366,   244,   335,   245,    -1,   206,   244,   342,   245,    -1,
     206,   244,   342,   250,   343,   245,    -1,   208,   244,   342,
     338,   245,    -1,   208,   244,   342,   250,   343,   338,   245,
      -1,   208,   244,   342,   278,   335,   279,   338,   245,    -1,
     208,   244,   342,   250,   343,   278,   335,   279,   338,   245,
      -1,   207,   244,   357,   245,    -1,   251,   366,   278,   279,
      -1,   251,   342,   250,   343,   278,   279,    -1,    88,   278,
     366,   279,    -1,    88,   278,   279,    -1,   366,   277,    -1,
     366,   246,   335,   247,   277,    -1,   366,   244,   335,   245,
     277,    -1,   366,   250,   343,    -1,   366,     9,   366,   250,
     343,    -1,   366,   250,   343,   244,   335,   245,    -1,   366,
       9,   366,   250,   343,   244,   335,   245,    -1,   366,   250,
     343,   246,   335,   247,    -1,   366,     9,   366,   250,   343,
     246,   335,   247,    -1,   366,   246,   335,   247,   250,     4,
      -1,   366,   250,     4,   277,    -1,   366,   246,   335,   247,
     250,     4,   277,    -1,   197,   244,   356,   253,   335,   245,
      -1,    56,   244,   349,   253,   349,   245,    -1,    57,   278,
     356,   253,   356,   279,    -1,    55,   278,   356,   279,    -1,
      58,   278,   356,   253,   356,   279,    -1,    63,   244,   363,
     245,    -1,    -1,   253,   335,    -1,    -1,   253,   356,    -1,
      -1,    86,   342,   345,   341,   246,   289,   247,    -1,   366,
      -1,   366,     9,   366,    -1,     4,    -1,    89,    -1,    89,
     335,    -1,    -1,   244,   344,   245,    -1,   347,    -1,   233,
     346,    -1,   232,   346,    -1,   346,   233,   346,    -1,   346,
     232,   346,    -1,   248,   335,   253,   335,   253,   335,   253,
     335,   253,   335,   249,    -1,   248,   335,   253,   335,   253,
     335,   253,   335,   249,    -1,   248,   335,   253,   335,   253,
     335,   249,    -1,   244,   335,   253,   335,   253,   335,   245,
      -1,   349,    -1,   348,   253,   349,    -1,   335,    -1,   351,
      -1,   248,   249,    -1,   248,   352,   249,    -1,   233,   248,
     352,   249,    -1,   335,   234,   248,   352,   249,    -1,   349,
      -1,   248,     8,   249,    -1,     5,    -1,   233,   351,    -1,
     335,   234,   351,    -1,   335,     8,   335,    -1,   335,     8,
     335,     8,   335,    -1,    94,   248,   335,   249,    -1,    94,
     248,     8,   249,    -1,    94,     5,    -1,   301,   248,     8,
     249,    -1,   301,     5,    -1,   130,   300,   350,    -1,   133,
     300,   349,    -1,   300,   182,    64,   248,   335,   253,   335,
     253,   335,   253,   335,   253,   335,   253,   335,   249,    -1,
      64,   300,   248,   352,   249,    -1,   304,    -1,   315,    -1,
     324,    -1,   366,   278,   279,    -1,   366,   250,   343,   278,
     279,    -1,   366,     9,   366,   250,   343,   278,   279,    -1,
      39,   246,   366,   247,    -1,    39,   246,   351,   247,    -1,
      39,   244,   351,   245,    -1,    39,   278,   248,   352,   249,
     279,    -1,   366,   278,   248,   352,   249,   279,    -1,    40,
     278,   335,   253,   335,   253,   335,   279,    -1,    41,   278,
     335,   253,   335,   253,   335,   279,    -1,    42,   278,   356,
     279,    -1,    43,   278,   335,   253,   335,   253,   335,   253,
     335,   253,   335,   253,   335,   279,    -1,   202,   278,   351,
     279,    -1,    32,   278,   351,   279,    -1,   335,    -1,   351,
      -1,   352,   253,   335,    -1,   352,   253,   351,    -1,   248,
     335,   253,   335,   253,   335,   253,   335,   249,    -1,   248,
     335,   253,   335,   253,   335,   249,    -1,   366,    -1,     4,
     250,   179,   250,     4,    -1,   248,   355,   249,    -1,   366,
     246,   335,   247,   250,   180,    -1,   353,    -1,   355,   253,
     353,    -1,   357,    -1,   366,    -1,   366,   246,   335,   247,
      -1,   366,   244,   335,   245,    -1,   366,   250,   343,    -1,
     366,     9,   366,   250,   343,    -1,   366,   250,   343,   244,
     335,   245,    -1,   366,     9,   366,   250,   343,   244,   335,
     245,    -1,   366,   246,   335,   247,   250,     4,    -1,   130,
      94,   248,   335,   249,    -1,   130,    97,   248,   335,   249,
      -1,   130,   100,   248,   335,   249,    -1,   130,   102,   248,
     335,   249,    -1,     5,    -1,   215,   246,   366,   247,    -1,
      67,    -1,   213,    -1,    72,    -1,    74,    -1,   199,   244,
     356,   245,    -1,   198,   244,   356,   253,   356,   245,    -1,
     200,   278,   356,   279,    -1,   200,   278,   356,   253,   356,
     279,    -1,   209,   244,   342,   339,   245,    -1,   209,   244,
     342,   250,   343,   339,   245,    -1,    48,   278,   363,   279,
      -1,    49,   244,   356,   245,    -1,    50,   244,   356,   245,
      -1,    51,   244,   356,   253,   356,   253,   356,   245,    -1,
      46,   278,   363,   279,    -1,    60,   278,   356,   279,    -1,
      61,   278,   356,   279,    -1,    62,   278,   356,   279,    -1,
      59,   278,   335,   253,   356,   253,   356,   279,    -1,    54,
     278,   356,   253,   335,   253,   335,   279,    -1,    54,   278,
     356,   253,   335,   279,    -1,    47,   278,   356,   279,    -1,
      47,   278,   356,   253,   352,   279,    -1,    68,   278,   356,
     279,    -1,    69,    -1,    53,   278,   356,   279,    -1,    52,
     278,   356,   279,    -1,    -1,    90,   278,   357,   358,   292,
     279,    -1,    87,   278,   359,   279,    -1,   251,   335,    -1,
     366,     9,   251,   335,    -1,    46,   278,   362,   279,    -1,
     363,    -1,   362,    -1,   248,   363,   249,    -1,   356,    -1,
     364,    -1,   363,   253,   356,    -1,   363,   253,   364,    -1,
     366,   244,   245,    -1,   366,   250,   343,   244,   245,    -1,
     366,     9,   366,   250,   343,   244,   245,    -1,     4,   252,
     248,   335,   249,    -1,   365,   252,   248,   335,   249,    -1,
     216,   246,   356,   247,   252,   248,   335,   249,    -1,     4,
      -1,   365,    -1,   216,   246,   356,   247,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   268,   268,   269,   274,   276,   280,   281,   282,   283,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   321,   325,   332,   337,
     342,   356,   369,   382,   410,   424,   437,   450,   469,   474,
     475,   476,   477,   478,   482,   484,   489,   491,   497,   601,
     496,   619,   626,   637,   636,   654,   661,   672,   671,   688,
     705,   728,   727,   741,   742,   743,   744,   745,   749,   750,
     756,   756,   757,   757,   763,   764,   765,   766,   771,   777,
     839,   854,   883,   893,   898,   906,   911,   919,   928,   933,
     945,   962,   968,   977,   995,  1013,  1022,  1034,  1039,  1047,
    1067,  1090,  1109,  1117,  1124,  1131,  1153,  1176,  1214,  1235,
    1247,  1261,  1261,  1263,  1265,  1274,  1284,  1283,  1304,  1303,
    1321,  1331,  1330,  1344,  1346,  1354,  1360,  1365,  1391,  1393,
    1396,  1398,  1402,  1403,  1407,  1419,  1432,  1447,  1456,  1469,
    1471,  1475,  1476,  1481,  1489,  1498,  1506,  1520,  1538,  1542,
    1549,  1558,  1561,  1567,  1571,  1583,  1586,  1593,  1616,  1632,
    1648,  1685,  1725,  1741,  1757,  1789,  1805,  1822,  1838,  1888,
    1906,  1912,  1918,  1925,  1956,  1971,  1993,  2016,  2039,  2062,
    2086,  2110,  2134,  2160,  2177,  2193,  2211,  2229,  2236,  2245,
    2244,  2274,  2276,  2278,  2280,  2282,  2290,  2292,  2294,  2296,
    2304,  2306,  2308,  2316,  2318,  2320,  2322,  2332,  2348,  2364,
    2380,  2396,  2412,  2449,  2471,  2495,  2496,  2501,  2504,  2508,
    2524,  2543,  2562,  2581,  2608,  2627,  2648,  2663,  2679,  2697,
    2748,  2769,  2791,  2814,  2919,  2935,  2970,  2992,  3014,  3020,
    3035,  3063,  3075,  3084,  3091,  3103,  3122,  3126,  3131,  3135,
    3140,  3147,  3154,  3161,  3173,  3246,  3264,  3289,  3304,  3337,
    3349,  3373,  3377,  3382,  3389,  3394,  3404,  3409,  3415,  3423,
    3427,  3431,  3435,  3439,  3448,  3512,  3528,  3545,  3562,  3584,
    3606,  3641,  3649,  3657,  3663,  3670,  3677,  3697,  3723,  3735,
    3746,  3764,  3782,  3801,  3800,  3825,  3824,  3851,  3850,  3875,
    3874,  3897,  3913,  3930,  3947,  3970,  3998,  4001,  4007,  4019,
    4039,  4043,  4047,  4051,  4055,  4059,  4063,  4067,  4076,  4089,
    4090,  4091,  4092,  4093,  4097,  4098,  4099,  4100,  4101,  4104,
    4128,  4147,  4170,  4173,  4189,  4192,  4209,  4212,  4218,  4221,
    4228,  4231,  4238,  4260,  4301,  4345,  4384,  4409,  4421,  4433,
    4445,  4457,  4466,  4496,  4522,  4548,  4580,  4607,  4633,  4659,
    4685,  4711,  4733,  4744,  4792,  4846,  4861,  4873,  4884,  4891,
    4906,  4920,  4921,  4922,  4926,  4932,  4944,  4962,  4990,  4991,
    4992,  4993,  4994,  4995,  4996,  4997,  4998,  5005,  5006,  5007,
    5008,  5009,  5010,  5011,  5012,  5013,  5014,  5015,  5016,  5017,
    5018,  5019,  5020,  5021,  5022,  5023,  5024,  5025,  5026,  5027,
    5028,  5029,  5030,  5031,  5032,  5033,  5034,  5035,  5036,  5037,
    5038,  5039,  5040,  5041,  5042,  5051,  5052,  5053,  5054,  5055,
    5056,  5057,  5058,  5059,  5060,  5061,  5066,  5065,  5073,  5075,
    5080,  5085,  5089,  5094,  5099,  5103,  5107,  5111,  5115,  5119,
    5123,  5129,  5145,  5150,  5156,  5162,  5181,  5202,  5235,  5239,
    5244,  5248,  5252,  5256,  5261,  5266,  5276,  5286,  5291,  5302,
    5311,  5316,  5321,  5349,  5350,  5356,  5357,  5363,  5362,  5385,
    5387,  5392,  5401,  5403,  5409,  5410,  5415,  5419,  5423,  5427,
    5431,  5438,  5442,  5446,  5450,  5457,  5462,  5469,  5474,  5478,
    5483,  5487,  5495,  5506,  5510,  5514,  5528,  5536,  5544,  5551,
    5561,  5584,  5589,  5595,  5600,  5606,  5617,  5623,  5629,  5635,
    5645,  5655,  5665,  5677,  5681,  5686,  5698,  5702,  5706,  5710,
    5728,  5736,  5744,  5773,  5783,  5799,  5810,  5815,  5819,  5823,
    5835,  5839,  5851,  5868,  5878,  5882,  5897,  5902,  5909,  5913,
    5918,  5932,  5948,  5952,  5956,  5960,  5964,  5972,  5978,  5984,
    5990,  5999,  6003,  6007,  6015,  6021,  6027,  6031,  6039,  6047,
    6054,  6063,  6067,  6071,  6086,  6100,  6114,  6126,  6142,  6151,
    6160,  6170,  6181,  6189,  6197,  6201,  6220,  6227,  6233,  6240,
    6248,  6247,  6257,  6281,  6283,  6289,  6294,  6296,  6301,  6306,
    6311,  6313,  6317,  6329,  6343,  6347,  6354,  6362,  6370,  6381,
    6383,  6386
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
  "tOnelabAction", "tOnelabRun", "tCodeName", "tCpu", "tMemory",
  "tTotalMemory", "tCreateTopology", "tCreateGeometry",
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
  "tUsing", "tPlugin", "tDegenerated", "tRecursive", "tRotate",
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
  "Shape", "@9", "GeoEntity", "GeoEntity123", "GeoEntity12", "GeoEntity02",
  "Transform", "MultipleShape", "ListOfShapes", "LevelSet", "Delete",
  "Colorify", "SetPartition", "Visibility", "Command", "Slide", "Loop",
  "Extrude", "@10", "@11", "@12", "@13", "ExtrudeParameters",
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
     475,    63,   476,   477,   478,   479,    60,    62,   480,   481,
     482,   483,    43,    45,    42,    47,    37,   124,    38,    33,
     484,   485,   486,    94,    40,    41,    91,    93,   123,   125,
      46,    35,   126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   254,   255,   255,   256,   256,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   258,   258,   259,   259,
     259,   259,   259,   259,   260,   260,   260,   260,   261,   261,
     261,   261,   261,   261,   262,   262,   263,   263,   265,   266,
     264,   267,   267,   269,   268,   270,   270,   272,   271,   273,
     273,   275,   274,   276,   276,   276,   276,   276,   277,   277,
     278,   278,   279,   279,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   281,   281,   282,   282,   282,   283,   282,   284,   282,
     282,   285,   282,   286,   286,   287,   287,   287,   288,   288,
     289,   289,   290,   290,   291,   291,   291,   291,   291,   292,
     292,   293,   293,   294,   294,   294,   294,   294,   295,   295,
     295,   296,   296,   296,   296,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   299,
     298,   300,   300,   300,   300,   300,   301,   301,   301,   301,
     302,   302,   302,   303,   303,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   305,   305,   306,   306,   306,
     306,   306,   306,   306,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   310,   311,   311,   311,   311,
     311,   311,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   313,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     315,   315,   315,   316,   315,   317,   315,   318,   315,   319,
     315,   315,   315,   315,   315,   315,   320,   320,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   322,
     322,   322,   322,   322,   323,   323,   323,   323,   323,   324,
     324,   325,   326,   326,   327,   327,   328,   328,   329,   329,
     330,   330,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   332,   332,
     332,   333,   333,   333,   334,   334,   334,   334,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   337,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   338,   338,   339,   339,   341,   340,   342,
     342,   343,   344,   344,   345,   345,   346,   346,   346,   346,
     346,   347,   347,   347,   347,   348,   348,   349,   349,   349,
     349,   349,   349,   350,   350,   350,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   352,   352,   352,   352,
     353,   353,   353,   353,   354,   354,   355,   355,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     356,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     358,   357,   357,   359,   359,   360,   361,   361,   362,   363,
     363,   363,   363,   364,   364,   364,   365,   365,   365,   366,
     366,   366
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
       3,     0,     5,     5,     5,     0,     2,     7,     7,     7,
       8,     8,     7,     7,    11,     7,     8,     8,     8,     9,
       3,     4,    10,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     8,     7,     7,     8,     8,    12,     0,
       9,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       1,     1,     4,     1,     1,     1,     4,     5,    11,     5,
       9,     9,     4,     9,     9,     1,     1,     0,     2,     6,
       7,     7,     6,     7,     8,    10,    14,    16,    12,    14,
      14,    14,    14,     8,     8,     6,     4,     5,     6,     6,
       3,     4,     3,     5,     6,     5,     4,     3,     4,     3,
       4,     5,     4,     5,     3,     5,     7,     7,     3,     7,
       3,     2,     2,     2,     2,     2,    15,     2,     2,     2,
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
       4,     4,     2,     4,     2,     3,     3,    16,     5,     1,
       1,     1,     3,     5,     7,     4,     4,     4,     6,     6,
       8,     8,     4,    14,     4,     4,     1,     1,     3,     3,
       9,     7,     1,     5,     3,     6,     1,     3,     1,     1,
       4,     4,     3,     5,     6,     8,     6,     5,     5,     5,
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
       0,     0,     0,     2,     3,     1,   609,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
     192,     0,     0,   193,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   319,   320,   321,   322,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   280,     0,     0,   288,   289,
       0,     0,     0,   283,     0,     0,     0,     0,     0,   371,
     372,   373,     0,     0,     5,     6,     7,     8,    10,     0,
      11,    24,    12,    13,    14,    15,    23,    22,    21,    16,
       0,    17,    18,    19,    20,     0,    25,     0,   610,     0,
     217,     0,     0,     0,     0,     0,   265,     0,   267,   268,
     263,   264,     0,   269,   270,   271,   272,   113,   123,   609,
     484,   479,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   273,     0,   203,   204,   205,     0,     0,     0,
       0,   425,   426,   428,   429,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     433,   434,   435,     0,     0,   191,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,   431,   432,     0,     0,     0,     0,     0,     0,     0,
       0,   519,   520,     0,   521,   497,   378,   438,   441,   302,
     498,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,   193,   194,   189,   196,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   486,     0,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   609,     0,     0,   217,     0,     0,   368,
       0,     0,     0,   200,   201,     0,     0,     0,     0,     0,
     505,     0,     0,   503,     0,     0,     0,     0,     0,   609,
       0,     0,   542,     0,     0,     0,     0,   261,   262,     0,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   563,     0,   587,   565,   566,     0,
       0,     0,     0,     0,     0,   564,     0,     0,     0,     0,
     281,   282,     0,   217,     0,   217,     0,     0,     0,   479,
       0,     0,     0,   217,   374,     0,     0,    76,     0,    63,
       0,     0,    67,    66,    65,    64,    69,    68,    70,    71,
       0,     0,     0,     0,     0,     0,   548,   479,     0,   216,
       0,   215,     0,   170,     0,     0,   548,   549,     0,     0,
     599,     0,   600,   549,   111,   111,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   536,   537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   381,     0,   380,   506,   382,
       0,   499,     0,     0,   479,     0,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
      71,     0,   455,     0,     0,     0,     0,     0,     0,     0,
     303,     0,   336,   336,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   217,     0,   217,   217,     0,   488,   487,
       0,     0,     0,     0,   217,   217,     0,     0,     0,     0,
     299,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   338,     0,     0,     0,     0,     0,   242,
       0,     0,   240,   369,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   346,   260,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   285,   284,
       0,   247,     0,     0,   249,     0,     0,     0,   380,     0,
     217,     0,     0,     0,     0,     0,     0,     0,   324,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    72,    73,     0,     0,   258,
      38,   254,     0,     0,     0,     0,     0,   212,     0,     0,
       0,     0,     0,   218,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,   482,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   330,     0,     0,     0,   195,     0,     0,     0,     0,
       0,     0,   364,   365,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   436,   454,     0,     0,     0,     0,
     515,   516,     0,     0,     0,     0,     0,   473,     0,   379,
     500,     0,     0,     0,     0,   508,     0,   398,   397,   396,
     395,   391,   392,   399,   400,   394,   393,   384,   383,     0,
     385,   507,   386,   389,   387,   388,   390,   480,     0,     0,
     481,   458,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,   334,     0,     0,     0,     0,   367,     0,     0,
       0,     0,   366,     0,   217,     0,     0,     0,     0,     0,
     490,   489,     0,     0,     0,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   353,     0,     0,   241,     0,     0,   236,     0,
       0,     0,     0,   363,     0,     0,     0,   379,   504,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,     0,     0,
       0,   475,     0,     0,   246,   250,   248,   252,     0,   385,
       0,   480,   458,   611,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,   379,
       0,    63,     0,     0,     0,     0,    79,     0,    63,    64,
       0,     0,   480,     0,     0,   458,     0,     0,     0,   189,
       0,     0,     0,   606,    28,    26,    27,     0,     0,     0,
       0,     0,   481,   552,    29,     0,     0,   255,   601,   602,
       0,   603,   552,    74,   114,    75,   124,   483,   485,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   538,   539,   206,
       9,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     424,   411,     0,   413,   414,   415,   416,   417,   535,   418,
     419,   420,     0,     0,     0,   527,   526,   525,     0,     0,
       0,   532,     0,   470,     0,     0,     0,   472,     0,   128,
     453,   511,   510,   199,     0,     0,   439,   534,   444,     0,
     450,     0,     0,     0,     0,   501,     0,     0,   451,     0,
     513,     0,     0,     0,     0,   443,   442,   465,    70,    71,
       0,     0,     0,     0,     0,     0,     0,   379,   332,   337,
     335,     0,   345,     0,   148,   149,   199,   379,     0,     0,
       0,     0,   237,     0,   251,   253,     0,     0,     0,   207,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   306,     0,   290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   339,   352,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,     0,
       0,     0,     0,     0,   243,     0,     0,     0,     0,   577,
       0,   584,   573,   574,   575,     0,   589,   588,     0,     0,
     578,   579,   580,   586,   593,   592,     0,   139,     0,   567,
       0,   569,     0,     0,     0,   562,     0,   245,     0,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,   375,
       0,   607,     0,     0,     0,     0,   101,    63,     0,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,    61,     0,
      39,    40,    41,    42,    43,     0,   443,   442,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     551,   550,     0,     0,     0,     0,     0,     0,     0,   135,
       0,   131,   132,     0,     0,     0,     0,     0,     0,     0,
     155,   155,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   342,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   518,     0,     0,     0,     0,     0,   473,   474,     0,
     446,     0,     0,     0,   509,   401,   502,   459,   457,     0,
     456,     0,     0,   523,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   344,     0,     0,     0,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,   311,
       0,     0,   310,     0,   313,     0,   315,     0,   300,   307,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   354,     0,   239,   238,   370,     0,     0,    35,
      36,     0,     0,     0,     0,   543,     0,     0,     0,   276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   475,   476,   571,     0,   459,     0,     0,
     217,   326,     0,   327,   217,     0,     0,   557,   558,   559,
     560,     0,    86,     0,     0,     0,     0,    84,    91,    93,
       0,   546,     0,    99,     0,     0,     0,     0,    81,     0,
       0,     0,     0,     0,    34,   459,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    31,
       0,   553,     0,     0,    32,     0,   553,   604,     0,   115,
     120,     0,     0,     0,   134,   137,   138,   478,     0,    77,
       0,     0,     0,     0,    78,   157,     0,     0,     0,     0,
     158,   173,   174,     0,     0,     0,     0,   159,   184,   175,
     179,   180,   176,   177,   178,   165,     0,     0,   412,   421,
     422,   423,   528,     0,     0,     0,   468,   469,   471,   129,
     437,   467,   440,   445,     0,     0,   473,   185,   452,     0,
      70,    71,     0,   464,   460,   462,   529,   181,     0,     0,
       0,   151,     0,     0,   343,     0,   150,     0,     0,     0,
       0,   259,     0,     0,     0,     0,   217,   217,     0,     0,
     312,   497,     0,     0,   314,   316,     0,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,   162,   163,     0,     0,     0,     0,
     102,   103,   104,   108,     0,   585,     0,     0,   583,     0,
     594,     0,     0,   140,   141,   591,   568,   570,     0,     0,
       0,     0,     0,     0,   324,   328,   324,     0,   376,    85,
      63,     0,     0,     0,     0,    83,     0,   544,     0,     0,
       0,     0,     0,     0,   597,   596,     0,     0,     0,     0,
       0,   495,     0,     0,   464,   256,   460,   257,     0,     0,
       0,     0,     0,   222,   219,     0,     0,   556,   554,     0,
       0,   116,   121,     0,     0,     0,   536,   537,   133,   347,
     348,   349,   350,   156,   160,   161,   166,   183,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,   447,     0,
       0,     0,     0,   524,   466,     0,     0,   167,     0,   186,
     333,     0,     0,   187,     0,     0,     0,     0,     0,     0,
     494,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,   233,     0,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     0,   351,    37,     0,   541,     0,
       0,   278,   277,     0,     0,     0,     0,     0,     0,   143,
     144,   147,   146,   145,     0,   572,     0,   608,     0,     0,
       0,     0,     0,     0,    96,     0,     0,    97,   547,     0,
       0,     0,    88,     0,     0,     0,    44,     0,     0,     0,
       0,     0,    46,     0,   223,   220,   221,    33,     0,     0,
     605,   128,   139,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,   530,   531,     0,   473,   448,     0,
     461,   463,     0,     0,   169,   190,     0,   340,   340,     0,
     109,   110,   217,     0,   210,   211,   301,     0,   308,     0,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
     214,   213,     0,     0,     0,     0,   105,   106,   576,   582,
     581,   142,     0,     0,     0,   329,     0,    92,    94,     0,
     100,     0,    82,   598,    89,    90,    49,     0,     0,     0,
       0,   496,     0,     0,   461,   555,     0,     0,     0,   118,
     595,     0,   125,     0,     0,     0,     0,   172,     0,     0,
       0,     0,   304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   492,     0,   318,     0,     0,   295,
       0,   225,     0,     0,     0,     0,     0,     0,     0,   540,
     279,     0,     0,   362,   217,   377,     0,   545,     0,    45,
       0,     0,     0,    62,    47,     0,   117,   122,   128,     0,
       0,   153,   154,   152,     0,     0,   449,     0,     0,     0,
       0,     0,   341,   355,     0,     0,   356,     0,   208,     0,
     309,     0,   291,     0,   217,     0,     0,     0,     0,     0,
       0,   164,   107,   275,   324,    98,     0,     0,     0,     0,
       0,     0,   126,   127,     0,     0,     0,     0,   188,     0,
     359,     0,   360,   361,   491,     0,     0,   297,   228,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,    59,
       0,     0,   119,     0,     0,     0,   305,     0,     0,   317,
     296,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,   230,   231,   232,     0,   226,   331,    50,     0,
      57,     0,   266,     0,   533,     0,     0,     0,   298,     0,
       0,    51,     0,     0,   274,     0,     0,     0,   227,     0,
       0,     0,     0,   517,     0,     0,    54,    52,     0,    55,
       0,   357,   358,     0,     0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   114,  1047,   115,   116,  1031,  1865,  1871,
    1320,  1529,  2018,  2150,  1321,  2121,  2168,  1322,  2152,  1323,
    1324,  1533,   431,   582,   583,  1117,   117,   763,   454,  1881,
    2028,  1882,   455,  1755,  1393,  1350,  1351,  1352,  1490,  1693,
    1694,  1183,  1586,  1577,   743,   594,   269,   270,   346,   198,
     271,   440,   441,   121,   122,   123,   124,   125,   126,   127,
     128,   272,  1215,  2053,  2112,   927,  1211,  1212,   273,  1008,
     274,   132,  1422,  1181,   902,   941,  1988,   133,   134,   135,
     136,   275,   276,  1139,  1154,  1274,   277,   768,   278,   891,
     767,   457,   609,   315,  1730,   353,   354,   280,   552,   361,
    1308,  1522,   450,   446,  1267,   985,  1566,  1723,  1724,   970,
     452,   138,   409
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1823
static const yytype_int16 yypact[] =
{
   12156,    63,   108, 12312, -1823, -1823,   -78,   163,   -19,   -31,
     -24,    47,   221,   226,   231,   243,    14,   293,   303,   392,
     405,    20,    83,    25,    68,    81,    68,    90,   174,   183,
      13,   296,   313,    26,   324,   346,   358,   383,   414,   419,
     429,   435,   447,   476,   208,   382,   418,   499,   326,   507,
     506,   491,  6670,   498,   397,   458,   650,   -52,   -18,   497,
     129,    89,   514,   763,   -79,   581,   210,   210,   648,   345,
      52, -1823, -1823, -1823, -1823, -1823,   646,   261,   799,   820,
      24,    61,   824,   857,   290,   628,   958,   965,  5702,   966,
     728,   730,   731,    27,    38, -1823,   733,   734, -1823, -1823,
     970,   974,   735, -1823,  4162,   738,  5554,    28,    31, -1823,
   -1823, -1823, 11492,   737, -1823, -1823, -1823, -1823, -1823,   739,
   -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823,
     340, -1823, -1823, -1823, -1823,    46, -1823,   979,   727,  5453,
      62,   740,   984, 11492,  3883,  3883, -1823, 11492, -1823, -1823,
   -1823, -1823,  3883, -1823, -1823, -1823, -1823, -1823, -1823,   741,
     747,   983, -1823, -1823, 11386,   750,   751,   752,   753,    25,
   11492, 11492, 11492,   754, 11492, 11492, 11492,   756, 11492, 11492,
   11492, 11492, 11492, 11492, 11492,  3883, 11492, 11492, 11492, 11492,
    5702,   757, -1823,  9322, -1823, -1823, -1823,   758,  5702,  6912,
    3883, -1823, -1823, -1823, -1823, -1823,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,   225,
      68,    68,    68,    68,    68,   760,    68,    68,   761,   497,
   -1823, -1823, -1823,    68,    68,    35,   825,   829,   830,   765,
    6912,   879,   497,   497,   770,    68,    68,   771,   772,   774,
   -1823, -1823, -1823, 11492,  7154, 11492, 11492,  7396,    25,   837,
      40, -1823, -1823,   773, -1823,  4406, -1823, -1823, -1823, -1823,
   -1823,   116, 11492,  9322,  9322,   776,   779,  7638,  5702,  5702,
    5702, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823,   777,
    7880,   778,  4462,  1020,  6912,   780,    27,   782,   783,   210,
     210,   210, 11492, 11492,   269, -1823,   298,   210, 10214,   373,
     412,   790,   791,   792,   793,   794,   796,   797, 11492,  5702,
    5702,  5702,   801,    17,  1040,   802, -1823,  1041,  1043, -1823,
     804,   808,   819, -1823, -1823,   821,  5702,   822,   826,   827,
   -1823, 11492,  5944, -1823,  1064,  1065, 11492, 11492, 11492,   409,
   11492,   828, -1823,   898, 11492, 11492, 11492, -1823, -1823, 11492,
   -1823,    68,    68,    68,   847,   848,   850,    68,    68,    68,
      68,    68,    68,    68, -1823,    68, -1823, -1823, -1823,    68,
      68,   851,   852,    68,   856, -1823,   855,  1096,  1097,   858,
   -1823, -1823,  1098,  1101,  1099,  1102,    68, 11492, 13985,   123,
    3883,  9322, 11492, -1823, -1823,  6912,  6912, -1823,   863, 11386,
     410,  1106, -1823, -1823, -1823, -1823, -1823, -1823, 11492, 11492,
      37,  6912,  1110,   663,  1531,   869,  1112,    94,   871, -1823,
     872, 12525, 11492, -1823,  1563,  -183, -1823,    67,  -106,  6364,
   -1823,   -46, -1823,    87,   -95,   213,  1031, -1823,    25,   870,
   11492, 11492, 11492, 11492,   873, 14501, 14526, 14551, 11492, 14576,
   14601, 14626, 11492, 14651, 14676, 14701, 14726, 14751, 14776, 14801,
     877, 14826, 14851, 14876, 13115,  1117, 11492,  9322,  4534, -1823,
     386, 11492,  1119,  1121,   883, 11492, 11492, 11492, 11492, 11492,
   11492, 11492, 11492, 11492, 11492, 11492, 11492, 11492, 11492, 11492,
   11492,  9322, 11492, 11492, 11492, 11492, 11492, 11492,  9322,  9322,
     882, 11492, 11492,  3883, 11492,  3883,  6912,  3883,  3883,  3883,
     886, 11492,    51, -1823, 10293, 11492,  6912,  5702,  6912,  3883,
    3883,  9322,    25, 11386,    25,   892,  9322,   892, -1823,   892,
   14901, -1823,   436,   887,    86,  1072, -1823,  1130, 11492, 11492,
   11492, 11492, 11492, 11492, 11492, 11492, 11492, 11492, 11492, 11492,
   11492, 11492,  8122, 11492, 11492, 11492, 11492, 11492,    25, 11492,
   11492,  1135, -1823,   671, 14926,   444,   462, 11492, 11492, 11492,
   -1823,  1136,  1137,  1137,   902, 11492, 11492,  1142,  9322,  9322,
   14013,   897,  1144, -1823,   903, -1823, -1823,  -159, -1823, -1823,
    6606,  6848,   210,   210,    62,    62,  -127, 10214, 10214, 11492,
    1914,  -118, -1823, 11492, 11492, 11492, 11492, 11492, 11492, 11492,
   11492, 11492, 14951,  1145,  1148,  1149, 11492,  1151, 11492, -1823,
   11492,  3080, -1823, -1823,  9322,  9322,  9322, 11492,  1152, 11492,
   11492, 11492, 14976,   906, -1823, -1823, 15001, 15026, 15051,   980,
    7090, -1823,   912,  4614, 15076, 15101, 14096,  3883,  3883,  3883,
    3883,  3883,  3883,  3883,  3883,  3883, 11492,  3883,  3883,  3883,
    3883,    23, 11386,  3883,  3883,  3883,    25,    25, -1823, -1823,
    9322, -1823,   913,  4684, -1823,   914, 10655, 11492,   892, 11492,
   -1823,    25, 11492, 11492,  1135,   917,   463, 15126, 12458,   916,
     464, 11492,  1159,   919,   920,   924,   926,  6912, 15151, 14123,
     160,   925,  1169,  1172, -1823, -1823, -1823,  9322,   204, -1823,
   -1823, -1823,    25, 11492, 11492,  1135,   933, -1823,   938,   -43,
     497,   129,   497, -1823,   932, 13144, -1823,   182,  9322,    25,
   11492, 11492,  1177,  1178,  9322, 11492,  1179,  3883,    25, 10530,
    1177,  1181, -1823,    25,  1182,  3883, 11492,   944,   945, -1823,
   11492,  7332,  7574,  7816,  8058, 11386,  1176,  1188,  1189, 15176,
    1190,  1208,  1210, 15201,  1211,  1212,  1213,  1214,  1217,  1218,
    1219, -1823,  1220,  1221,  1222, -1823, 11492, 15226,  9322,   982,
    9322, 13173, -1823, -1823,  1225, 14069, 14069, 14069, 14069, 14069,
   14069, 14069, 14069, 14069, 14069, 14069,  8300, 14069, 14069, 14069,
   14069,  1240,   274, 14069, 14069, 14069,  8537,  8774,  9016,  4534,
     987,   986,   109,  9322,  9258,  9590,   274,  9920,   274,   981,
     988,   989,    -9,  9322, 16126, -1823,   274,   990, 13202, 13231,
   -1823, -1823,   991,     3,   274,  -141,   995,   384,   469,  1228,
   -1823,  1177,   274,   997,   994,  4646,  4926,  1141,  1361,   973,
     973,   467,   467,   467,   467,   467,   467,   388,   388,  9322,
      82, -1823,    82,    82,   892,   892,   892,   996, 15251, 14150,
     692,   301,  9322, -1823,  1242,  1002,  1003, 15276, 15301, 15326,
   11492,  6912,  1249,  1248,  9977, 13260, 15351, -1823,   470,   472,
    9322,  1005, -1823, 10978, -1823, 11520, 11650,   210, 11492, 11492,
   -1823, -1823,  1008,  1009, 10214,  5161,  1125,   -32,   210, 11707,
   15376, 13289, 15401, 15426, 15451, 15476, 15501, 15526, 15551,  1253,
   11492,  1256, -1823, 11492, 15576, -1823, 14177, 14204, -1823,   477,
     478,   479, 13318, -1823, 14231, 14258, 10161, -1823, -1823,  1257,
    1259,  1261,  1013, 11492, 11774, 11492, 11492, -1823, -1823,    43,
     188,   364,   188,  1024,  1026,  1019,   274,   274,  1021, 10245,
     274,   274,   274,   274, 11492,   274,  1264, -1823,  1022,  1032,
     391,  -113,  1029,   484, -1823, -1823, -1823, -1823, 14069,    82,
   11831,  1028,   450,  1027,  1104,  1276,  1133, 10616,  1035,  1042,
    1282,  6912, 13347, -1823, 11492, 11492, 11492, 11492,  1283,   164,
     104, 11386, 11492,  1285,  1288,    30, -1823,   485,  1247,  1250,
    6912,    22,  1044, 15601, 14285,   124, 11492, 11492,  1051,  1049,
    1054,  1052,  8364, -1823, -1823, -1823, -1823,  3883,     9,  1053,
   15626, 14312, -1823,  1057, -1823,   140, 10486, -1823, -1823, -1823,
    1055, -1823,  1058, -1823,    56, -1823, -1823, 16126, -1823,  1302,
   14069, 11492, 11492, 11492, 11492,   274,   210,  6912,  6912,  1300,
    6912,  6912,  6912,  1303,  6912,  6912,  6912,  6912,  6912,  6912,
    6912,  6912,  6912,  6912,  1742,  1304,  9322,  4534, -1823, -1823,
   -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823,
   -1823, -1823, 11492, -1823, -1823, -1823, -1823, -1823, -1823, -1823,
   -1823, -1823, 11492, 11492, 11492, -1823, -1823, -1823,   487, 11492,
   11492, -1823, 11492, -1823,  6912,  3883,  3883, -1823,   494,  1056,
   -1823, -1823, -1823,  1131, 11492, 11492, -1823, -1823, -1823,  1177,
   -1823,  1177, 11492, 11492,  1067, -1823,  6912,    68, -1823, 11492,
   -1823, 11492, 11492,   495,  1177,   692,  -129, -1823, 11492, 11492,
     274,   500,  6912,  9322,  9322,  1307,  1308,  1309,  3886, -1823,
   -1823,  1311, -1823,  1073, 16126,  1066, -1823,  1313,  1314,  1316,
     503,  1322, -1823, 11898, -1823, -1823,  -102, 10809, 11123, -1823,
   -1823, 13376,   -88,  1215,  1324, 10853,  1082,  1326,  1089,    41,
      45,   -73, -1823,   -48, -1823,   -32,  1327,  1330,  1331,  1333,
    1334,  1335,  1336,  1337,  1338,  6912, 16126, -1823,  1975,  1100,
    1341,  1343,  1344,  1237,  1345, -1823,  1347,  1348, 11492,  6912,
    6912,  6912,  1351, 11952, -1823,  4959,  1498,    50,  1352, -1823,
    9322, -1823, -1823, -1823, -1823,  3883, -1823, -1823, 11492,  3883,
   -1823, -1823, -1823, -1823, 16126, -1823,  1107,  1108,  3883, -1823,
    3883, -1823,  1177,  3883,  1115, -1823,  1109, -1823,  1177, 11492,
   11492,  1103,   497,  1134, 10939, -1823,  2109,  1138,  6912, -1823,
    1132, -1823, 13405, 13434, 13463, 13492, -1823, -1823, 11492,  1377,
      42, 11492,  1379,  1388,  2390, -1823,  1350,    27,  1389,  1150,
     274,    68,    68,  1391, -1823,  1154,  1156,  1153, -1823,  1396,
   -1823, -1823, -1823, -1823, -1823,  1177,   203,   899, 11492, 14339,
   15651, 11492,  8601, 11492,  9322,  1155,   510,  1397,   192,  1177,
   -1823,  1157, 11492,  1399, 11492,  1177, 11176,  9559,   274,  4889,
    1161,  1158, -1823,  1400, 15676, 15701, 15726, 15751,  1403,   142,
    1286,  1286,  6912,  1404,  1406,  1412,  6912,   -99,  1413,  1414,
    1416,  1418,  1420,  1421,  1422,  1424,  1425, -1823,  1427,   512,
   14069, 14069, 14069, 14069,   274, 12455, 12488, 12521,  1191,   274,
     274, -1823,  1302,   274, 15776, 14069,  1192,    95, 16126, 14069,
   -1823,  1428,   274, 12554, 16126, 16126, -1823,   563, -1823,  1431,
   -1823, 15801, 14366, -1823,   274,  1433,   515,   517,  6912,  6912,
    6912,  1436,  1435, -1823,   212, 11492,  6912,  1194,  1195,  1437,
     937, -1823, 11492, 11492, 11492,  1197,  1198,  1199,  1202, -1823,
    2509,  6912, -1823, 11492, -1823,  1444, -1823,  1445, -1823, -1823,
   10214,   302,  6186, -1823,  1204,  1205,  1206,  1207,  1231,  1232,
    8838,  1450, -1823,  9322, -1823, -1823, -1823,  1233, 11492, -1823,
   -1823, 14393,  1452,  1453,  1306, -1823, 11492, 11492, 11492, -1823,
    1476,  1480,  1482,   949,   401,  1236,  5339,  1239, 11492,    34,
     274,  1251,   274,  1241, -1823, -1823, 11386,   695, 11492,  1245,
   -1823, -1823,  2781, -1823, -1823,  1244,  1489, -1823, -1823, -1823,
   -1823,  3040, -1823,   197,  1252,  1491,  3241, -1823, -1823, -1823,
      27, -1823,   518, -1823, 11492,   212,  2717,  3311, -1823,  1255,
   11492, 11492,  6912,  1260, -1823,   370,  1496,  1495, 15826,  1497,
    1228, 15851,  1263,   520, 15876,   523,  1503,  1504, -1823, -1823,
    3883,  1269,  1500, 15901, -1823, 12587,  1270, -1823,  5211, 16126,
   -1823,  1508,    68,  7396, -1823, -1823, -1823, -1823,  1302, -1823,
    1510,  1512,  1513,  1515, -1823, -1823,   210,  1520,  1521,  1522,
   -1823, -1823, -1823,  1524,    49,  1434,  1527, -1823, -1823, -1823,
   -1823, -1823, -1823, -1823, -1823, -1823,  1529,  1287, -1823, -1823,
   -1823, -1823, -1823, 11492, 11492, 11492, -1823, -1823, -1823,  1158,
   -1823, -1823, -1823, -1823, 11492,  1291,  1289, -1823, -1823, 11492,
   11492, 11492,   274,   692, -1823, -1823, -1823, -1823,  1290,  1292,
    1533,   -99,  1535, 11492, -1823,  6912, 16126,   936,  9322,  9322,
   11492, -1823,  9977, 13521, 15926,  5638,    62,    62, 11492, 11492,
   -1823,   590,  1293, 15951, -1823, -1823, 13550,   -23, -1823,  1537,
    1538,  6912,   210,   210,   210,   210,   210,  6428,  1539, -1823,
     525, 11492,  3489,  1542, -1823, -1823,  6912,  5880,   621, 15976,
   -1823, -1823, -1823, -1823,  9647, -1823,  3883, 11492, -1823,  3883,
   16126,  9889, 11386,  1296, -1823, -1823, -1823, -1823,  1305,  1298,
   11492, 11492, 13579, 11492, 12458, -1823, 12458,  6912, -1823, -1823,
   11386, 11492,  1546,  1549,    30, -1823,  1548, -1823,    27, 14420,
    6912,  3883,  1550,   274, -1823,  1310,   274, 11492, 12620, 12653,
     532, -1823, 11492, 11492,   246, -1823,  1317, -1823,  1309,  1551,
    1552,  1313,  1553, -1823, -1823,  1555, 11492, -1823, -1823, 11492,
   11255, -1823, -1823,  1318,  3311,   533,  4340,  1557, -1823, -1823,
   -1823, -1823, -1823,   732, -1823, -1823, -1823, -1823,  1319,  1320,
    1323, -1823,  1565,  6912, 14069, 14069, 12686, 14069, -1823,  1328,
   12719, 16001, 14447, -1823, -1823,  9322,  9322, -1823,  1556, -1823,
   16126,  1566,  1329, -1823,   534,   535, 14041,  3575,  1568,  1332,
   -1823, -1823, 11492,  1353,  1354, 13608, 14474,  1570,  6912,  1571,
    1357, 11492, -1823, -1823,   540,    -8,     2,   193,   217,   245,
    9080,   250, -1823,  1575, 13637, -1823, -1823,  1405, -1823, 11492,
   11492, -1823, -1823,  9322,  3671,  1577,  1355, 14069,   274, 16126,
   -1823, -1823, -1823, -1823,    34, -1823, 11386, -1823, 13666,  1360,
    1362,  1363,  1600,  3809, -1823,  1603,  1607, -1823, -1823,  1364,
    1609,   541, -1823,  1610,  1612,   309, 16126, 11492, 11492,  1371,
    6912,   547, 16126, 16026, -1823, -1823, -1823, -1823, 16051, 12752,
   -1823,  1056,  1108,  6912,   274, -1823, 11492, 11386,    25,  9322,
    9322, 11492,  1614,   550, -1823, -1823, 11492,  1289, -1823, 11492,
   -1823, -1823,   552,   553, -1823, -1823,  6912,   511,   513,  9322,
   -1823, -1823,    62,  6122, -1823, -1823, -1823,  1615, -1823,  1373,
    6912, -1823, 13695,  1617,  9322,   210,   210,   210,   210,   210,
   -1823, -1823, 11492, 13724, 13753,   555, -1823, -1823, -1823, -1823,
   -1823, -1823,  1381,  1621,  1380, -1823,  1623, -1823, -1823,    27,
   -1823,  1451, -1823, -1823, -1823, -1823, -1823, 11492, 12785, 12818,
    6912, -1823,  1624, 11492,  1385, -1823, 11492,  1390,  1392, -1823,
   -1823,  4168, -1823,  1393,   582,   583, 13782, -1823,  1394, 12851,
    1395, 12884, -1823,  1398,   585,  1402,   210,  6912,  1632,  1407,
     210,  1641,   614,  1408, -1823, 11492, -1823,  1642,  1517, 11955,
    1411, -1823,   616,   253,   260,   295,   317,   320,  4042, -1823,
   -1823,  1647,  1648, -1823, -1823, -1823,  1650, -1823,  1415, 16126,
   11492, 11492,   619, -1823, 16126, 12917, -1823, -1823,  1056, 11386,
    1417, -1823, -1823, -1823, 11492, 11492, -1823, 11492,  9322,  1654,
     210,   162, -1823, -1823,   210,   167, -1823,  1655, -1823, 13811,
   -1823, 11492, -1823,   -32, -1823,  1659,  9322,  9322,  9322,  9322,
    9080, -1823, -1823, -1823, 12458, -1823, 11492, 16076, 12950,    58,
   11492,  1419, -1823, -1823, 12983, 13016, 13049,   622, -1823,   323,
   -1823,   328, -1823, -1823, -1823,  4065,   314, 12022, -1823,   624,
     629,   630,   631,   332,   632,  1423,   639, -1823, 11492, -1823,
    6912, 13840, -1823, 11492, 11492, 11492, -1823,   210,   210, -1823,
   -1823, -1823,   -32,  1660,  1661,  1663,  1664,  9322,  1665,  1668,
    1669,  1429, 16101,   642,  1670, 13869, 14069, 13082,   339,   350,
     330, -1823, -1823, -1823, -1823,   644, -1823, -1823, -1823,  3883,
   -1823,  1430, -1823,  1673, -1823, 11492, 11492, 11492, -1823,  1675,
     652, -1823,  1439,  6912, -1823, 13898, 13927, 13956, -1823,  1676,
    3883,  3883,   653, -1823,  1678,  1679, -1823, -1823,   660, -1823,
    1682, -1823, -1823,  1683,  3883, -1823, -1823, -1823
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1823, -1823, -1823, -1823,   352, -1823, -1823, -1823, -1823,  -375,
   -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823, -1823,
   -1823, -1823,  -715,  -133,  4220,  3340, -1823,  1243, -1823, -1823,
   -1823, -1823, -1823, -1823, -1822, -1823,   300,   126,  -187, -1823,
    -148, -1823,    66,   341,  1698, -1823,    -1,   -53, -1823, -1823,
      -2,  -604,  -314, -1823, -1823, -1823, -1823, -1823, -1823, -1823,
   -1823,  1703, -1823, -1823, -1823, -1823, -1212, -1192,  1704, -1688,
    1705, -1823, -1823, -1823,  1116, -1823,  -198, -1823, -1823, -1823,
   -1823,  1959, -1823, -1823, -1383,   219,  1710, -1823,     0,  -692,
   -1823, -1823,   249, -1823, -1653,   -27,  -166,  2308,  2498,  -297,
      33, -1823,   252,   -67, -1823, -1823,    48,   187, -1647,  -137,
     959, -1823,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -557
static const yytype_int16 yytable[] =
{
     139,   120,   119,  1451,   620,  1022,   432,   300,  1814,   604,
     922,   923,  1002,  1030,  1615,   451,  1849,   173,  1850,  1449,
     161,   637,   641,   160,   485,   279,  1314,   159,   333,   159,
     177,   359,   492,   402,   159,  1584,   404,   397,  1691,   401,
     533,   720,   363,  1035,  1842,   556,  1513,  1444,   286,   281,
    1247,  1446,   414,   146,  1480,   159,   320,   286,   295,  1967,
    1053,  1204,   747,  1347,  2099,   338,   438,   339,  1062,     4,
     748,   287,   436,   612,   613,   305,   749,   337,  1205,   288,
    1038,   143,   289,  1585,   290,   281,  1206,  1207,  1208,   693,
     362,   696,  1209,  1210,   917,   458,   758,   459,   159,   708,
     306,   398,  1204,   732,  1148,   612,   613,  1884,     5,  1149,
     334,  1297,   426,   427,   612,   613,   307,   308,   578,  1205,
    1893,  1409,   591,   592,   593,   578,   924,  1206,  1207,  1208,
     612,   613,   701,  1209,  1210,   928,   437,  1272,   439,   753,
    1273,   447,   447,  1768,   612,   613,   321,   754,  1575,   453,
     322,  1432,   761,  1481,  1482,   340,   323,   324,   762,   325,
     326,  1436,  1769,   633,   634,   635,   464,  1021,  2080,  1157,
     140,  1297,   493,  2082,   141,   165,  1448,   142,   166,   327,
     648,   167,   447,   168,   612,   613,   301,   281,  1044,   302,
     281,  1315,  1316,  1317,  1318,   281,   281,   447,  1549,   756,
      65,    66,    67,    68,  1710,  1450,  2071,   757,  1445,   612,
     613,  1028,  1447,   144,   335,    79,   721,   722,    82,  1297,
     145,  1514,  1515,   279,   612,   613,   296,   148,  1692,   297,
    1811,   298,   149,  1779,   612,   613,  1137,   150,   530,   113,
     113,   113,   299,   113,   757,  1924,   113,   281,   725,   151,
     726,   537,   538,  1984,  1338,  1925,  1145,   174,   152,  1449,
     590,   281,   800,   638,   281,   554,   157,   113,   553,   141,
     178,  1319,   336,   597,   984,   360,   403,   602,  1307,   405,
     281,   281,   364,   534,   281,   281,   281,   281,   557,   913,
     415,   915,   916,  1248,   416,   147,   725,   281,   726,   153,
     162,   281,   163,   362,  1298,  1301,  2100,  2022,   929,   154,
     113,   750,   162,   751,   163,   314,   316,   752,   319,   575,
     576,   422,   423,   424,   425,   577,   281,   281,   281,   158,
     162,   759,   163,   751,   170,   426,   427,   760,   733,   162,
     734,   163,  -549,   281,   735,   426,   427,   964,  1152,   281,
     426,   427,   712,   579,  1300,   580,  1127,   426,   427,   581,
     579,   329,   580,   330,   426,   427,   581,   702,  1328,   703,
    1280,   850,  -552,   704,   612,   613,  2095,   422,   423,   424,
     425,   422,   423,   424,   425,  1343,  1000,   343,   709,   710,
     344,   435,   842,   800,   612,   613,   445,   448,   155,   612,
     613,   426,   427,   345,   723,   426,   427,   447,   281,  1045,
    1046,   156,   281,   281,   422,   423,   424,   425,   171,  1045,
    1046,   422,   423,   424,  1029,   612,   613,   172,   281,   422,
     423,   424,   425,   725,   736,   726,  1204,   480,   426,   427,
     744,   757,   310,   311,   426,   427,  1926,  2123,  1204,   612,
     613,  -551,   494,  1205,   312,   769,   189,  1396,   313,  1397,
     764,  1206,  1207,  1208,  1204,  1205,   762,  1209,  1210,   518,
    1927,   519,  1407,  1206,  1207,  1208,   856,   612,   613,  1209,
    1210,  1205,   612,   613,   281,   612,   613,   426,   427,  1206,
    1207,  1208,   612,   613,  -556,  1209,  1210,   190,  1928,   839,
    2162,   612,   613,  1929,   713,   192,  2056,   714,   281,   590,
     715,   851,   716,  2057,  1980,   281,   832,   614,   191,   725,
     447,   726,   447,   281,   447,   447,   453,   612,   613,   846,
     612,   613,   972,   281,   281,   281,   447,   447,   281,   161,
     175,   161,   855,   281,   857,  1168,   615,  1169,  2058,   612,
     613,  1658,   612,   613,  1956,   612,   613,   176,   607,   608,
     612,   613,  1957,  2110,   612,   613,   616,   621,   179,   281,
    2059,   612,   613,  2060,   193,   887,  2107,   310,   311,  2148,
    1493,  2108,   612,   613,   412,  2117,  1497,  1023,   413,   312,
     180,   291,  2146,   318,   292,   281,   281,   293,   558,   294,
    1193,   194,   181,  2147,   195,   612,   613,   196,   199,   725,
      44,   726,   439,   439,  1733,   987,  1701,  1250,  -553,   744,
     197,   622,   699,   573,   574,   575,   576,   182,   162,  1830,
     163,   577,   347,  1535,  1151,   799,   725,  1152,   726,   800,
     744,   281,   281,   281,  1270,   283,   725,  1551,   726,  1985,
    1986,  1989,  1990,  1556,   800,  1987,   623,  1987,   183,   659,
     624,   141,   705,   184,   453,   447,   453,   447,   447,   447,
     447,   447,   447,   185,   447,   447,   447,   447,   986,   186,
     447,   447,   447,   161,   992,   860,   991,   281,  1040,   800,
    1018,   187,   744,   895,  1279,   744,  1280,   800,  1001,   570,
     571,   699,   573,   574,   575,   576,   284,   744,  1075,  1635,
     577,   896,  1004,  1010,   281,   800,   800,  1011,  1155,  1188,
     188,  1189,   800,   800,   281,   800,  1232,  1233,  1234,  1032,
     800,   800,   800,  1276,  1310,   200,  1384,   800,   800,  1039,
     800,  1041,   282,  1391,  1406,   281,  1049,   800,   800,  1414,
     285,   281,  1429,   800,   453,  1060,   800,  1167,   303,  1547,
    1064,  1597,   447,   800,  1628,   800,  1629,  1717,   800,  1740,
     800,  1718,  1742,   800,  1823,   836,   800,   838,   800,   840,
     841,  1869,  1885,  1907,  1908,  1870,  1886,   800,   800,  1923,
    1953,   852,   853,  1870,   757,   281,  1962,   281,  1711,  1978,
    1963,  1982,  1983,  1870,  2011,   800,   800,  1620,   800,  1621,
    1720,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   309,
     281,  2031,  2032,   577,  2039,   800,   800,  1185,  1870,  1807,
     281,  2086,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
     304,   920,   921,  2047,   577,  2055,   608,   800,  2069,   800,
    1831,  2106,  1870,  2113,  1179,   800,   281,   800,  2114,  2115,
    2116,  2118,   800,   800,   800,   800,  1299,  1302,  2120,   281,
     328,  2141,  1963,  2149,  1449,  1870,   317,   800,   281,   331,
    2130,  2159,  2170,   159,   370,  2160,  1870,   281,   725,  2173,
     726,   727,   744,  2174,   744,   744,   725,   332,   726,   892,
     971,   341,   973,   974,   975,   976,   977,   978,   744,   980,
     981,   982,   983,   426,   427,   988,   989,   990,  1449,  1700,
    1792,  1701,  1793,  1641,  1642,   371,   372,   373,   374,   375,
     376,   377,   378,   379,  1303,  1683,  1684,   342,   380,   381,
     382,   383,   348,   744,   612,   613,   384,   385,   386,   349,
     355,   387,   356,   388,   357,   358,   367,   365,   366,   418,
     368,   369,   399,   410,  1290,   417,   389,   411,   442,   390,
     443,   456,   458,   141,   460,   461,   462,   463,   468,   744,
     472,   486,   536,  1313,   526,   529,   491,  -192,   281,  1058,
    1521,  -193,  -194,   535,   539,   542,   543,  1066,   544,   555,
     587,   413,  1309,   588,   601,   595,   598,   281,   603,   420,
     605,   606,  1408,  1410,   625,   626,   627,   628,   629,   281,
     630,   631,  1803,  1804,   447,   636,   639,   642,   640,   643,
    1360,  1361,   644,  1363,  1364,  1365,   645,  1367,  1368,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,   646,   649,   647,
     654,   655,   650,   651,   281,   281,   661,   281,   281,   281,
     662,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   670,   671,   281,   672,   683,   684,   391,   392,   393,
     686,   687,   688,   689,   691,   694,   690,  1388,   394,   692,
     695,   711,   395,   717,   396,   113,   724,   730,   731,   140,
     766,   737,   791,   770,   796,   802,   775,   803,   804,  1401,
     833,   281,   447,   447,   843,   577,   863,   861,   864,   890,
     426,   427,   911,   900,   901,  1415,   904,  -550,   907,  1536,
     912,   914,   940,   281,   942,   958,   943,   945,   953,   962,
     965,  1009,   994,   996,  1003,  1013,  1196,  1014,  1015,   281,
     281,   281,  1016,  1202,  1017,  1024,  1025,  1213,  1026,  1036,
    1042,  1052,  1037,  1076,  1054,  1057,  1704,  1063,  1065,  1068,
    1706,  1069,   744,  1408,  1410,  1077,  1078,  1080,  1461,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,  1472,  1473,  1474,  1081,   577,  1082,  1084,  1085,
    1086,  1087,   281,  1716,  1088,  1089,  1090,  1091,  1092,  1093,
    1096,  1100,  1125,  1126,  1134,  1156,   281,   281,   281,  1141,
    1150,  1135,  1136,  1160,  1144,  1159,  1164,   281,   558,  1172,
    1173,  1174,   447,  1180,  1182,  1191,   447,  1199,  1200,  1203,
    1225,  1505,  1227,  1242,  1239,   447,  1240,   447,  1241,  1253,
     447,  1254,  1255,  1266,  1258,  1268,  1275,  1269,  1278,  1281,
    1560,  1499,  1565,  1283,  1287,   281,  1282,  1284,  1289,  1296,
    1288,  1305,  1306,  1311,  1325,  1331,  1312,  1332,  1333,  1337,
    1334,  1342,  1346,  1339,   362,  1345,  1349,  1362,  1993,  1392,
    1366,  1378,  1400,  -195,  1418,  1419,  1420,  1423,  1424,  1425,
    1426,  1427,  1564,  1428,   447,  1359,  1430,  1437,  1438,   281,
    1441,   281,  1442,  1443,  1452,  1579,  1453,  1467,  1454,  1583,
    1455,  1456,  1457,  1458,  1459,  1460,   281,  1464,  1463,  1465,
    1466,  1498,  1468,  1469,  1470,  1475,  1483,  1520,  1488,   281,
    1495,  1489,  1496,   281,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
    1712,  1506,  1500,  1512,   577,  1517,  1504,  1389,  1390,  1725,
    1725,  1630,  1631,  1632,  1518,  1523,  1524,  1528,  1530,  1637,
    1531,  1532,  1534,  1548,  1546,  1554,  1569,  1552,  1567,  1574,
    1580,  1568,  1581,  1576,  1652,   281,   281,   281,  1582,  1587,
    1588,  1858,  1589,   281,  1590,  1660,  1591,  1592,  1593,  1699,
    1594,  1595,  1596,  1668,  1617,  1623,  1606,  1613,   281,  1627,
    1633,  1634,  1638,  1639,  1640,  1646,  1647,  1648,  1649,   281,
    1654,  1655,  1661,  1662,  1663,  1664,  1669,   281,  1674,  1675,
     281,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   798,   573,   574,   575,   576,  1665,
    1666,  1671,  1680,   577,  1676,   725,  1681,   726,  1682,  1686,
    1784,  1752,  1689,  1703,  1273,  1708,  1696,  1707,  1714,  1727,
    1734,  1735,  1713,  1737,  1747,  1731,  1478,  1485,  1732,  1743,
    1744,  1487,  1739,  1746,  1750,  1753,  1759,   362,  1760,  1761,
    1491,  1762,  1492,   453,   453,  1494,  1764,  1765,  1766,   281,
    1767,  1751,  1770,  1771,  1772,  1773,  1778,   729,  1785,  1787,
    1786,  1789,  1152,  1812,  1813,  1822,  1808,   447,  1826,  1844,
    1845,  1846,  1854,  1855,  1857,   281,  1862,  1874,  1875,  1876,
     281,  1877,  1904,   757,  1888,  -554,  1883,  1889,  1890,   746,
    1892,  1891,  1905,  1898,  1911,  1798,  1918,  1906,  1920,  1537,
    1912,  1930,  1932,  1937,  1861,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
    1938,  1784,  1914,  1915,   577,  1921,  1947,  1999,  1791,  1944,
    1949,  1945,  1946,  1950,  1951,  1952,  1954,  1835,  1955,  1960,
    1977,  1996,  1997,  2001,  1840,  1843,  2012,  2013,  2014,  2015,
    2023,  2017,   281,  -555,  1731,   281,   281,  2030,  2043,  2026,
    2036,  2027,  2034,  1852,   439,   439,  2038,  2046,  2050,  1827,
    2040,  2051,  2016,  2062,  2063,  2044,  2065,  2048,   281,  2054,
    2078,  2083,  2073,  2066,   281,  2088,  2131,  2132,  2102,  2133,
    2134,  2136,  2119,   281,  2137,  2138,  2142,  2139,  2153,  2154,
    1851,  2158,  2166,   447,  2171,  2172,   447,  2161,  2175,  2176,
    1550,  2096,  1609,  1860,  1758,  1968,  1941,  1788,   765,  1657,
    2064,   118,  1578,   744,   281,   744,   129,   130,   131,   903,
    1991,  1309,  1698,   137,  1726,   362,  1059,   281,   453,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,  1841,
    2087,   577,     0,  1479,     0,     0,  1731,  1856,  1377,     0,
       0,   453,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
     281,     0,     0,     0,   577,     0,     0,     0,     0,  1942,
       0,  1919,   281,   281,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,  1745,     0,     0,   281,   577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
    1972,     0,     0,     0,     0,  1763,     0,     0,     0,     0,
     281,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1961,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1731,
     281,     0,     0,     0,     0,  1973,   281,   281,     0,     0,
       0,     0,     0,  1998,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   281,     0,     0,   281,     0,     0,     0,
     439,  1815,  1816,  1817,  1818,  1819,  1821,   281,     0,     0,
       0,   281,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,  1731,     0,     0,     0,     0,  1836,     0,
       0,  1838,     0,     0,     0,     0,   362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
    2042,     0,  2072,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,  1462,     0,     0,   281,   577,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   744,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,    41,    42,    43,    44,     0,     0,
      46,     0,     0,     0,     0,   281,     0,   738,    53,     0,
       0,    56,   739,     0,   740,   741,     0,   742,     0,     0,
       0,     0,     0,   281,   281,   281,   281,   281,     0,     0,
       0,     0,     0,   744,    76,     0,     0,     0,     0,     0,
       0,   408,     0,  1731,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   744,     0,    90,    91,
      92,     0,     0,     0,     0,     0,     0,   281,   434,     0,
       0,     0,   444,     0,     0,     0,   449,     0,     0,     0,
       0,     0,     0,     0,   281,  1503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1731,     0,     0,   465,
     466,   467,     0,   469,   470,   471,   447,   473,   474,   475,
     476,   477,   478,   479,     0,   481,   482,   483,   484,     0,
     281,     0,   488,     0,     0,     0,     0,   447,   447,     0,
       0,     0,     0,   926,     0,     0,     0,     0,     0,     0,
       0,   447,     0,     0,  2003,  2004,  2005,  2006,  2007,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,   545,   547,   549,   550,   488,     0,     0,     0,
       0,     0,     0,     0,     0,  2041,     0,     0,     0,  2045,
       0,   584,   488,   488,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   600,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,     0,     0,     0,     0,   611,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,     0,  2079,
       0,     0,     0,  2081,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2093,
     652,   488,     0,     0,     0,   656,   657,   658,     0,   660,
       0,     0,     0,   663,   664,   665,     0,     0,   666,     0,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,  2128,  2129,     0,     0,
       0,     0,     0,     0,     0,     0,   698,     0,     0,     0,
     488,   707,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   718,   719,     0,
       0,  2151,     0,     0,     0,     0,  1519,     0,     0,     0,
       0,   745,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2167,  2169,     0,     0,     0,     0,     0,   771,
     772,   773,   774,     0,     0,     0,  2177,   779,     0,     0,
       0,   783,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   797,   547,     0,     0,     0,
     801,     0,     0,     0,   805,   806,   807,   808,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   823,   824,   825,   826,   827,   828,   829,   829,     0,
     834,   835,     0,   837,     0,     0,     0,     0,     0,     0,
     844,     0,     0,   848,   849,     0,     0,     0,     0,     0,
     829,   489,     0,     0,     0,   488,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1650,     0,   865,   866,   867,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     878,   880,   882,   883,   884,   885,   886,     0,   888,   889,
       0,     0,     0,     0,     0,     0,   897,   898,   899,     0,
       0,     0,     0,     0,   905,   906,     0,   488,   488,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   548,     0,     0,   489,   545,   698,   925,     0,
       0,     0,   930,   931,   932,   933,   934,   935,   936,   937,
     938,   489,   489,     0,     0,   944,     0,   946,     0,   947,
       0,     0,     0,   488,   488,   488,   952,     0,   954,   955,
     956,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,   979,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
       0,     0,     0,     0,     0,     0,   998,     0,   999,     0,
     489,   888,   889,     0,     0,     0,     0,     0,     0,     0,
    1012,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,     0,     0,     0,
       0,   490,  1033,  1034,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,  1050,
    1051,     0,     0,   488,  1056,     0,     0,     0,  1050,   489,
       0,   159,   370,     0,     0,  1067,     0,     0,     0,  1070,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,  1094,     0,   880,     0,  1097,
       0,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     378,   379,     0,     0,     0,     0,   380,   381,   382,   383,
       0,   585,   586,     0,   384,   385,   386,  1705,     0,   387,
       0,   388,   488,     0,     0,   548,     0,     0,     0,     0,
       0,     0,   488,     0,   389,     0,     0,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   822,
       0,     0,     0,     0,     0,     0,   830,   831,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,     0,
       0,     0,     0,     0,     0,     0,     0,   420,     0,   854,
       0,   488,     0,     0,   489,     0,     0,     0,     0,  1178,
       0,     0,     0,  1184,     0,     0,     0,     0,     0,   488,
       0,     0,     0,     0,     0,     0,     0,  1197,  1198,     0,
     881,     0,     0,  1201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1226,
       0,     0,  1228,     0,     0,     0,   489,   489,     0,   706,
       0,     0,     0,     0,     0,   391,   392,   393,     0,     0,
       0,     0,  1243,     0,  1245,  1246,   394,     0,     0,     0,
     395,     0,   396,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1264,     0,     0,     0,     0,     0,     0,
       0,     0,   489,   489,   489,     0,     0,     0,     0,     0,
       0,     0,   725,     0,   726,  1721,  1286,     0,     0,     0,
       0,     0,     0,  1292,  1293,  1294,  1295,     0,     0,     0,
       0,  1304,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1329,  1330,     0,   489,     0,
       0,   488,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
    1354,  1355,  1356,  1357,     0,   489,     0,     0,     0,     0,
       0,     0,     0,     0,   858,     0,  1709,     0,     0,     0,
       0,     0,     0,     0,     0,   488,   489,     0,     0,     0,
       0,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,  1380,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1381,  1382,  1383,     0,     0,     0,     0,  1385,  1386,
       0,  1387,     0,     7,     8,     0,   908,   909,     0,     0,
       0,     0,     0,  1394,  1395,     0,   881,     0,  1098,     0,
       0,  1398,  1399,     0,     0,     0,     0,     0,  1403,     0,
    1404,  1405,     0,     0,     0,     0,     0,  1411,  1412,     0,
       0,     0,   488,   488,     0,     0,     0,     0,     0,     0,
       0,   489,   949,   950,   951,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1440,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   489,   993,     0,
      41,    42,    43,    44,     0,     0,    46,  1471,     0,     0,
     489,     0,     0,   738,    53,     0,     0,    56,   739,   488,
     740,   741,     0,   742,     0,     0,     0,  1486,   489,     0,
       0,     0,     0,     0,     0,  1027,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,  1411,  1412,
       0,     0,     0,  1502,     0,     0,  1048,  1715,     0,     0,
       0,     0,  1055,     0,    90,    91,    92,  1511,     0,     0,
    1516,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,  1538,     0,     0,
    1541,   488,  1544,   488,     0,     0,     0,     0,     0,     0,
       0,  1553,     0,  1555,     0,  1553,  1559,     0,     0,     0,
       0,     0,     0,     0,     0,   159,   370,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   948,
       0,  1128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1138,     0,     0,     0,     0,     0,     0,     0,     0,
     489,     0,     0,     0,     0,     0,     0,   371,   372,   373,
     374,   375,   376,   377,   378,   379,     0,     0,     0,     0,
     380,   381,   382,   383,     0,     0,     0,  1163,   384,   385,
     386,     0,     0,   387,  1636,   388,     0,     0,     0,     0,
    1171,  1643,  1644,  1645,     0,     0,     0,     0,   389,     0,
    1651,   390,  1653,     0,   489,     0,     0,     0,  1190,  1656,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,     0,     0,     0,     0,  1672,     0,     0,
       0,     0,     0,     0,     0,  1677,  1678,  1679,     0,     0,
       0,   420,     0,     0,     0,     0,     0,  1690,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1702,     0,     0,
       0,     0,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,   489,   489,  1719,   577,     0,     0,     0,     0,  1728,
    1729,     0,     0,     0,     0,  1825,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   391,
     392,   393,     0,     0,     0,     0,     0,     0,     0,     0,
     394,     0,  1756,     0,   395,     0,   396,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1336,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   489,  1721,
       0,     0,  1774,  1775,  1776,     0,     0,     0,     0,     0,
       0,     0,     0,  1777,     0,     0,     0,     0,  1780,  1781,
    1782,  1910,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1790,     0,  1379,     0,     0,   488,   488,  1796,
       0,  1797,     0,     0,     0,     0,     0,  1805,  1806,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,     0,     0,     0,
    1824,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     489,     0,   489,  1834,     0,     0,  1837,     0,     0,     0,
    1839,     0,     0,     0,     0,     0,     0,     0,     0,  1781,
    1782,     0,  1848,     0,     0,     0,     0,     0,     0,     0,
    1853,  1416,  1417,     0,     0,     0,     0,  1936,     0,     0,
       0,     0,     0,     0,     0,     0,  1866,     0,     0,     0,
       0,  1872,  1873,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1878,     0,     0,  1879,  1878,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,   488,     0,     0,  1484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1913,     0,     0,     0,     0,     0,     0,     0,     0,
    1922,   489,     0,   728,     0,     0,     0,     0,     0,   547,
       0,     0,     0,     0,     0,     0,     0,     0,  1933,  1934,
       0,     0,   488,     0,     0,     0,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,  1948,     0,     0,   577,     0,
       0,     0,     0,     0,     0,     0,  1958,  1959,     0,     0,
    1543,     0,  1545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1971,     0,     0,   488,   488,
    1976,     0,     0,     0,     0,  1979,     0,     0,  1981,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,     0,
       0,  1757,   845,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,   159,   370,     0,
       0,  2008,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  2019,     0,     0,     0,
       0,     0,  2024,   893,     0,  2025,     0,     0,     0,   371,
     372,   373,   374,   375,   376,   377,   378,   379,     0,     0,
       0,     0,   380,   381,   382,   383,   489,   489,     0,     0,
     384,   385,   386,     0,  2049,   387,     0,   388,     0,     0,
       0,  1670,     0,     0,     0,     0,     0,     0,     0,     0,
     389,     0,     0,   390,     0,   489,     0,     0,     0,  2067,
    2068,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2074,  2075,     0,  2076,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2085,     0,     0,   420,     0,   488,   488,   488,   488,   488,
    1421,     0,     0,     0,     0,  1872,     0,     0,     0,  2101,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,  2061,     0,
       0,     0,   577,     0,     0,     0,     0,  2122,     0,     0,
       0,     0,  2125,  2126,  2127,     0,     0,     0,     0,     0,
       0,  2109,     0,     0,     0,     0,   488,     0,     0,     0,
       0,   391,   392,   393,     0,     0,     0,     0,     0,     0,
       0,     0,   394,   489,   489,     0,   395,     0,   396,   113,
       0,     0,     0,     0,  2155,  2156,  2157,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,   548,   577,
       0,     0,     0,     0,     0,     0,  1794,  1795,     0,     0,
       0,   489,     0,     0,     0,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,     0,  1113,  1114,  1115,
    1116,     0,  1118,  1119,  1120,  1121,   159,   370,     0,     0,
       0,     0,     0,     0,     0,  2029,  1131,     0,  1133,     0,
       0,     0,     0,     0,     0,     0,  1140,     0,     0,     0,
       0,     0,     0,  1146,  1147,     0,     0,   489,   489,     0,
       0,     0,  1158,     0,     0,     0,     0,     0,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   489,     0,     0,
       0,   380,   381,   382,   383,     0,     0,     0,     0,   384,
     385,   386,   489,     0,   387,     0,   388,     0,     0,     0,
       0,     0,     0,     0,   164,     0,   169,     0,     0,   389,
       0,     0,   390,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,  1902,  1903,   577,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
    1249,  1251,  1252,     0,     0,     0,  1256,  1257,     0,     0,
    1260,  1261,  1262,  1263,     0,  1265,     0,     0,     0,     0,
    1271,  1935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,  1887,   558,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   433,
     391,   392,   393,     0,   489,   489,   489,   489,   489,     0,
       0,   394,     0,     0,     0,   395,     0,   396,   113,     0,
       0,     0,     0,     0,     0,     0,     0,  1974,  1975,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,  1992,     0,     0,
    1353,   577,     0,     0,   558,  1358,     0,     0,     0,     0,
       0,     0,  2002,     0,     0,   489,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   520,
     521,   522,   523,   524,   525,     0,   527,   528,     0,     0,
       0,     0,     0,   531,   532,   201,   159,     0,     0,     0,
       0,     0,   202,   203,   204,   540,   541,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   406,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1413,     0,     0,     0,     0,     0,     0,   234,   235,   236,
     237,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2077,   240,   241,   242,
       0,     0,   558,     0,     0,     0,     0,   243,    23,     0,
     244,     0,     0,     0,  2089,  2090,  2091,  2092,  2094,     0,
       0,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   798,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,   667,   668,   669,     0,     0,     0,   673,   674,   675,
     676,   677,   678,   679,     0,   680,     0,     0,     0,   681,
     682,     0,     0,   685,     0,  2135,     0,     0,     0,     0,
       0,     0,   966,     0,     0,     0,   697,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,     0,     0,     0,     0,   577,
    1525,     0,     0,     0,  1161,     0,     0,     0,     0,   254,
       0,     0,     0,   255,     0,     0,     0,     0,   257,   258,
     259,     0,   260,   261,   262,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1561,     0,
       0,     0,     0,     0,   263,   407,     0,     7,     8,     0,
       0,   265,     0,     0,     0,     0,   351,     0,     0,     0,
     599,     0,     0,   268,     0,     0,     0,     0,     0,     0,
    1598,  1599,  1600,  1601,  1602,     0,     0,     0,     0,  1607,
    1608,     0,     0,  1610,     0,  1612,     0,     0,     0,  1616,
       0,     0,  1618,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1626,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   798,   573,
     574,   575,   576,     0,   862,     0,     0,   577,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,    41,    42,    43,    44,     0,     0,
      46,     0,     0,     0,     0,     0,     0,   738,    53,     0,
       0,    56,   739,     0,   740,   741,     0,   742,     0,     0,
       0,     0,     0,     0,  1685,     0,  1688,     0,     0,     0,
    1695,     0,  1697,     0,    76,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,    90,    91,
      92,     0,     0,     0,     0,     0,  1722,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,   201,     6,   370,     0,     0,     0,     0,   202,
     203,   204,     0,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   995,  1162,  1562,   372,   373,   374,   375,
     376,   377,   378,   379,   234,   235,   236,   237,   380,   381,
     382,   383,   238,   239,     0,     0,   384,   385,   386,     0,
       0,   387,  1783,   388,   240,   241,   242,  1477,     0,     0,
       0,     0,     0,     0,   243,    23,   389,   244,     0,   390,
       0,     0,     0,   245,     0,     0,   246,     0,     0,   247,
       0,   248,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,   249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,    54,    55,     0,   251,     0,   252,
       0,     0,   253,     0,     0,     0,     0,    65,    66,    67,
      68,    69,     0,     0,    71,    72,    73,    74,    75,     0,
       0,     0,    79,     0,     0,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1863,     0,     0,  1864,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1153,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   391,   392,   393,
     255,   256,     0,     0,     0,   257,   258,   259,   394,   260,
     261,   262,   395,     0,   396,   113,     0,     0,     0,     0,
       0,  1170,     0,     0,  1894,  1895,     0,  1897,     0,     0,
       0,   263,   264,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,   351,     0,     0,     0,  1563,     0,     0,
     268,     0,     0,     0,     0,     0,     0,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,  1939,  1940,     0,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,     6,   370,     0,     0,     0,
       0,   202,   203,   204,  1970,     0,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     0,     0,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   234,   235,   236,   237,
     380,   381,   382,   383,   238,   239,     0,     0,   384,   385,
     386,     0,     0,   387,  1348,   388,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,   243,    23,   389,   244,
       0,   390,     0,     0,     0,   245,     0,     0,   246,     0,
       0,   247,     0,   248,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,    54,    55,     0,   251,
       0,   252,     0,     0,   253,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,     0,    71,    72,    73,    74,
      75,     0,     0,     0,    79,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1402,     0,     0,
       0,     0,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   957,     0,   254,   391,
     392,   393,   255,   256,   918,     0,     0,   257,   258,   259,
     394,   260,   261,   262,   395,     0,   396,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,   264,     0,     0,     0,     0,     0,
     265,     0,     0,     0,     0,   351,   201,   159,   370,   267,
     419,     0,   268,   202,   203,   204,  2144,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   406,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   234,   235,
     236,   237,   380,   381,   382,   383,   238,     0,     0,     0,
     384,   385,   386,     0,     0,   387,     0,   388,   240,   241,
     242,  1526,  1527,     0,     0,     0,     0,     0,   243,    23,
     389,   244,     0,   390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   400,   370,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,   420,   725,     0,   726,     0,     0,     0,
       0,     0,  1687,     0,     0,     0,     0,     0,     0,     0,
     371,   372,   373,   374,   375,   376,   377,   378,   379,     0,
       0,     0,     0,   380,   381,   382,   383,  1614,     0,     0,
       0,   384,   385,   386,     0,     0,   387,  1622,   388,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   389,     0,   421,   390,     0,     0,     0,     0,     0,
     254,   391,   392,   393,   255,     0,     0,     0,     0,   257,
     258,   259,   394,   260,   261,   262,   395,     0,   396,   113,
     422,   423,   424,   425,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   407,     0,     0,     0,
       0,     0,   265,     0,   426,   427,     0,   428,     0,   429,
       0,     0,     0,   430,   268,   201,     6,   350,     0,     0,
       0,     0,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,   391,   392,   393,     0,     0,   234,   235,   236,
     237,     0,     0,   394,     0,   238,   239,   395,     0,   396,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
       0,     0,  1754,     0,     0,     0,     0,   243,    23,     0,
     244,     0,     0,     0,     0,     0,   245,     0,     0,   246,
       0,     0,   247,     0,   248,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,    54,    55,     0,
     251,     0,   252,     0,     0,   253,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,     0,    71,    72,    73,
      74,    75,     0,     0,     0,    79,     0,     0,    82,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,  1801,     0,     0,
       0,  1802,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,   255,   256,     0,     0,     0,   257,   258,
     259,     0,   260,   261,   262,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,   264,     0,     0,     0,     0,
       0,   265,     0,     0,     0,     0,   351,   201,     6,     0,
     352,     0,   653,   268,   202,   203,   204,     0,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,   237,     0,     0,     0,     0,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
      23,     0,   244,     0,     0,     0,     0,     0,   245,     0,
       0,   246,     0,     0,   247,     0,   248,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,    54,
      55,     0,   251,     0,   252,     0,     0,   253,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,     0,    71,
      72,    73,    74,    75,     0,     0,     0,    79,     0,     0,
      82,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,  1828,
       0,     0,     0,  1829,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,   255,   256,     0,     0,     0,
     257,   258,   259,     0,   260,   261,   262,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,   487,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,   351,   201,
       6,  1659,     0,   551,     0,   268,   202,   203,   204,     0,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,   236,   237,     0,     0,     0,     0,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,    23,     0,   244,     0,     0,     0,     0,     0,
     245,     0,     0,   246,     0,     0,   247,     0,   248,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,    54,    55,     0,   251,     0,   252,     0,     0,   253,
       0,     0,     0,     0,    65,    66,    67,    68,    69,     0,
       0,    71,    72,    73,    74,    75,     0,     0,     0,    79,
       0,     0,    82,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,  1994,     0,     0,     0,  1995,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,   255,   256,     0,
       0,     0,   257,   258,   259,     0,   260,   261,   262,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   264,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
     351,   201,     6,     0,   267,     0,     0,   268,   202,   203,
     204,     0,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,   237,     0,     0,     0,
       0,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,    23,     0,   244,     0,     0,     0,
       0,     0,   245,     0,     0,   246,     0,     0,   247,     0,
     248,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,     0,    54,    55,     0,   251,     0,   252,     0,
       0,   253,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,     0,    71,    72,    73,    74,    75,     0,     0,
       0,    79,     0,     0,    82,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   755,     0,     0,
       0,     0,     0,     0,     0,   254,     0,     0,     0,   255,
     256,     0,     0,     0,   257,   258,   259,     0,   260,   261,
     262,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     617,  1820,     0,     0,     0,     0,     0,   265,     0,     0,
       0,     0,   619,   201,     6,     0,   313,   551,     0,   268,
     202,   203,   204,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   236,   237,     0,
       0,     0,     0,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,    23,     0,   244,     0,
       0,     0,     0,     0,   245,     0,     0,   246,     0,     0,
     247,     0,   248,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,    54,    55,     0,   251,     0,
     252,     0,     0,   253,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,     0,    71,    72,    73,    74,    75,
       0,     0,     0,    79,     0,     0,    82,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   918,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,   255,   256,     0,     0,     0,   257,   258,   259,     0,
     260,   261,   262,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   264,     0,     0,     0,     0,     0,   265,
       0,     0,     0,     0,   266,   201,     6,     0,   267,     0,
       0,   268,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
     237,     0,     0,     0,     0,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,    23,     0,
     244,     0,     0,     0,     0,     0,   245,     0,     0,   246,
       0,     0,   247,     0,   248,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,    54,    55,     0,
     251,     0,   252,     0,     0,   253,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,     0,    71,    72,    73,
      74,    75,     0,     0,     0,    79,     0,     0,    82,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   919,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,   255,   256,     0,     0,     0,   257,   258,
     259,     0,   260,   261,   262,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,   264,     0,     0,     0,     0,
       0,   265,     0,     0,     0,     0,   351,   201,     6,     0,
     267,     0,     0,   268,   202,   203,   204,     0,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,   237,     0,     0,     0,     0,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
      23,     0,   244,     0,     0,     0,     0,     0,   245,     0,
       0,   246,     0,     0,   247,     0,   248,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,    54,
      55,     0,   251,     0,   252,     0,     0,   253,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,     0,    71,
      72,    73,    74,    75,     0,     0,     0,    79,     0,     0,
      82,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   963,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,   255,   256,     0,     0,     0,
     257,   258,   259,     0,   260,   261,   262,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,   487,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,   351,   201,
       6,     0,   546,     0,     0,   268,   202,   203,   204,     0,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,   236,   237,     0,     0,     0,     0,   238,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,    23,     0,   244,     0,     0,     0,     0,     0,
     245,     0,     0,   246,     0,     0,   247,     0,   248,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,    54,    55,     0,   251,     0,   252,     0,     0,   253,
       0,     0,     0,     0,    65,    66,    67,    68,    69,     0,
       0,    71,    72,    73,    74,    75,     0,     0,     0,    79,
       0,     0,    82,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1071,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,   255,   256,     0,
       0,     0,   257,   258,   259,     0,   260,   261,   262,     0,
       0,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   487,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
     351,   201,     6,     0,     0,   551,     0,   268,   202,   203,
     204,     0,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,   237,     0,     0,     0,
       0,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,    23,     0,   244,     0,     0,     0,
       0,     0,   245,     0,     0,   246,     0,     0,   247,     0,
     248,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,     0,    54,    55,     0,   251,     0,   252,     0,
       0,   253,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,     0,    71,    72,    73,    74,    75,     0,     0,
       0,    79,     0,     0,    82,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,   254,     0,     0,     0,   255,
     256,     0,     0,     0,   257,   258,   259,     0,   260,   261,
     262,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   264,     0,     0,     0,     0,     0,   265,     0,     0,
       0,     0,   589,   201,     6,     0,   267,     0,     0,   268,
     202,   203,   204,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   236,   237,     0,
       0,     0,     0,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,    23,     0,   244,     0,
       0,     0,     0,     0,   245,     0,     0,   246,     0,     0,
     247,     0,   248,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,    54,    55,     0,   251,     0,
     252,     0,     0,   253,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,     0,    71,    72,    73,    74,    75,
       0,     0,     0,    79,     0,     0,    82,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1073,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,   255,   256,     0,     0,     0,   257,   258,   259,     0,
     260,   261,   262,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   264,     0,     0,     0,     0,     0,   265,
       0,     0,     0,     0,   596,   201,     6,     0,   267,     0,
       0,   268,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
     237,     0,     0,     0,     0,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,    23,     0,
     244,     0,     0,     0,     0,     0,   245,     0,     0,   246,
       0,     0,   247,     0,   248,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,    54,    55,     0,
     251,     0,   252,     0,     0,   253,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,     0,    71,    72,    73,
      74,    75,     0,     0,     0,    79,     0,     0,    82,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1074,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,   255,   256,     0,     0,     0,   257,   258,
     259,     0,   260,   261,   262,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,   487,     0,     0,     0,     0,
       0,   265,     0,     0,     0,     0,   351,   201,     6,     0,
     879,     0,  1335,   268,   202,   203,   204,     0,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,   237,     0,     0,     0,     0,   238,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,     0,     0,     0,     0,     0,     0,     0,   243,
      23,     0,   244,     0,     0,     0,     0,     0,   245,     0,
       0,   246,     0,     0,   247,     0,   248,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,    54,
      55,     0,   251,     0,   252,     0,     0,   253,     0,     0,
       0,     0,    65,    66,    67,    68,    69,     0,     0,    71,
      72,    73,    74,    75,     0,     0,     0,    79,     0,     0,
      82,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,   255,   256,     0,     0,     0,
     257,   258,   259,     0,   260,   261,   262,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,   487,     0,     0,
       0,     0,     0,   265,   201,     6,     0,     0,   351,  1542,
       0,   202,   203,   204,     0,   268,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,   236,   237,
       0,     0,     0,     0,   238,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,   242,     0,
       0,     0,     0,     0,     0,     0,   243,    23,     0,   244,
       0,     0,     0,     0,     0,   245,     0,     0,   246,     0,
       0,   247,     0,   248,     0,     0,     0,     0,     0,     0,
      40,     0,     0,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,    54,    55,     0,   251,
       0,   252,     0,     0,   253,     0,     0,     0,     0,    65,
      66,    67,    68,    69,     0,     0,    71,    72,    73,    74,
      75,     0,     0,     0,    79,     0,     0,    82,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1122,     0,     0,     0,     0,     0,     0,     0,   254,     0,
       0,     0,   255,   256,     0,     0,     0,   257,   258,   259,
       0,   260,   261,   262,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,   487,     0,     0,     0,     0,     0,
     265,   201,     6,     0,     0,   351,     0,     0,   202,   203,
     204,     0,   268,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   234,   235,   236,   237,     0,     0,     0,
       0,   238,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,   241,   242,     0,     0,     0,     0,
       0,     0,     0,   243,    23,     0,   244,     0,     0,     0,
       0,     0,   245,     0,     0,   246,     0,     0,   247,     0,
     248,     0,     0,     0,     0,     0,     0,    40,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,     0,    54,    55,     0,   251,     0,   252,     0,
       0,   253,     0,     0,     0,     0,    65,    66,    67,    68,
      69,     0,     0,    71,    72,    73,    74,    75,     0,     0,
       0,    79,     0,     0,    82,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1123,     0,     0,
       0,     0,     0,     0,     0,   254,     0,     0,     0,   255,
     256,     0,     0,     0,   257,   258,   259,     0,   260,   261,
     262,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     263,   264,     0,     0,     0,     0,     0,   265,     0,     0,
       0,     0,   351,   201,     6,     0,  1667,     0,     0,   268,
     202,   203,   204,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   236,   237,     0,
       0,     0,     0,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,    23,     0,   244,     0,
       0,     0,     0,     0,   245,     0,     0,   246,     0,     0,
     247,     0,   248,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,    54,    55,     0,   251,     0,
     252,     0,     0,   253,     0,     0,     0,     0,    65,    66,
      67,    68,    69,     0,     0,    71,    72,    73,    74,    75,
       0,     0,     0,    79,     0,     0,    82,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1124,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,   255,   256,     0,     0,     0,   257,   258,   259,     0,
     260,   261,   262,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   617,  1820,     0,     0,     0,     0,     0,   265,
       0,     0,     0,     0,   619,   201,     6,     0,   313,     0,
       0,   268,   202,   203,   204,     0,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
     237,     0,     0,     0,     0,   238,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,    23,     0,
     244,     0,     0,     0,     0,     0,   245,     0,     0,   246,
       0,     0,   247,     0,   248,     0,     0,     0,     0,     0,
       0,    40,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,     0,    54,    55,     0,
     251,     0,   252,     0,     0,   253,     0,     0,     0,     0,
      65,    66,    67,    68,    69,     0,     0,    71,    72,    73,
      74,    75,     0,     0,     0,    79,     0,     0,    82,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1129,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,   255,   256,     0,     0,     0,   257,   258,
     259,     0,   260,   261,   262,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   263,   487,     0,     0,     0,     0,
       0,   265,   201,   159,   370,     0,   351,     0,     0,   202,
     203,   204,     0,   268,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   406,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,     0,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   234,   235,   236,   237,   380,   381,
     382,   383,   238,     0,     0,     0,   384,   385,   386,     0,
       0,   387,     0,   388,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,   243,    23,   389,   244,     0,   390,
     201,   159,   370,     0,     0,     0,     0,   202,   203,   204,
       0,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   406,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   234,   235,   236,   237,   380,   381,   382,   383,
     238,     0,     0,     0,   384,   385,   386,     0,     0,   387,
       0,   388,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,   243,    23,   389,   244,     0,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   391,   392,   393,
     255,     0,     0,     0,     0,   257,   258,   259,   394,   260,
     261,   262,   395,     0,   396,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   407,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,   351,     0,     0,     0,  1558,     0,     0,
     268,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1130,   254,   391,   392,   393,   255,     0,
       0,     0,     0,   257,   258,   259,   394,   260,   261,   262,
     395,     0,   396,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
     407,     0,     0,     0,     0,     0,   265,     0,     0,     0,
       0,   351,   201,   159,   370,  1833,     0,     0,   268,   202,
     203,   204,     0,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   406,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,     0,  1562,   372,   373,   374,   375,
     376,   377,   378,   379,   234,   235,   236,   237,   380,   381,
     382,   383,   238,     0,     0,     0,   384,   385,   386,     0,
       0,   387,     0,   388,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,   243,    23,   389,   244,     0,   390,
     201,   159,   370,     0,     0,     0,     0,   202,   203,   204,
       0,     0,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   406,
     223,   224,   225,   226,   227,   228,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   234,   235,   236,   237,   380,   381,   382,   383,
     238,     0,     0,     0,   384,   385,   386,     0,     0,   387,
       0,   388,   240,   241,   242,     0,     0,     0,     0,     0,
       0,     0,   243,    23,   389,   244,     0,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,   391,   392,   393,
     255,     0,     0,     0,     0,   257,   258,   259,   394,   260,
     261,   262,   395,     0,   396,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   407,     0,     0,     0,     0,     0,   265,     0,
       0,     0,     0,   351,     0,     0,     0,  1721,     0,     0,
     268,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1132,   254,   391,   392,   393,   255,     0,
       0,     0,     0,   257,   258,   259,   394,   260,   261,   262,
     395,     0,   396,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   263,
     407,     0,     0,     0,     0,     0,   265,   201,   159,     0,
       0,   351,     0,     0,   202,   203,   204,     0,   268,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   406,   223,   224,   225,
     226,   227,   228,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,   237,     0,     0,     0,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
     241,   242,     0,     0,     0,     0,   201,   159,     0,   243,
      23,   847,   244,   202,   203,   204,     0,     0,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   406,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
     236,   237,     0,     0,     0,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,   243,    23,
       0,   244,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
       0,   254,     0,     0,  1238,   255,     0,     0,     0,     0,
     257,   258,   259,     0,   260,   261,   262,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,   619,     0,
       0,     0,   313,     0,     0,   268,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
     254,     0,     0,     0,   255,     0,     0,     0,  1259,   257,
     258,   259,     0,   260,   261,   262,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,   407,     0,     0,     0,
       0,     0,   265,   201,   159,     0,     0,   351,     0,     0,
     202,   203,   204,     0,   268,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   406,   223,   224,   225,   226,   227,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   236,   237,     0,
       0,     0,     0,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,   241,   242,     0,     0,
       0,     0,     0,     0,     0,   243,    23,     0,   244,   201,
     159,     0,  1285,     0,     0,     0,   202,   203,   204,     0,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   406,   223,
     224,   225,   226,   227,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,   234,   235,   236,   237,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   243,    23,     0,   244,     0,     0,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,   254,     0,   577,
       0,   255,     0,     0,     0,     0,   257,   258,   259,  1344,
     260,   261,   262,     0,     0,     0,   113,     0,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   263,   407,     0,    41,    42,    43,    44,   265,
       0,    46,     0,     0,   351,  1061,     0,     0,   738,    53,
       0,   268,    56,   739,     0,   740,   741,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,   255,     0,     0,
       0,     0,   257,   258,   259,     0,   260,   261,   262,    90,
      91,    92,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   407,
       0,     0,     0,     0,     0,   265,   201,   159,     0,  1439,
     351,     0,     0,   202,   203,   204,     0,   268,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   406,   223,   224,   225,   226,
     227,   228,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   997,     0,     0,     0,   234,   235,
     236,   237,     0,     0,     0,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,   241,
     242,     0,     0,     0,     0,     0,     0,     0,   243,    23,
       0,   244,   201,   159,     0,  1501,     0,     0,     0,   202,
     203,   204,     0,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   406,   223,   224,   225,   226,   227,   228,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,   234,   235,   236,   237,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,   241,   242,     0,     0,     0,
       0,     0,     0,     0,   243,    23,     0,   244,     0,     0,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
     254,     0,   577,     0,   255,     0,     0,     0,     0,   257,
     258,   259,  1433,   260,   261,   262,     0,     0,     0,   113,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   263,   407,     0,    41,    42,
      43,    44,   265,     0,    46,     0,     0,   351,     0,     0,
       0,   738,    53,     0,   268,    56,   739,     0,   740,   741,
       0,   742,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,     0,     0,     0,   254,     0,     0,     0,
     255,     0,     0,     0,     0,   257,   258,   259,     0,   260,
     261,   262,    90,    91,    92,   113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   263,   407,     0,     0,     0,     0,     0,   265,   201,
     159,     0,     0,   351,     0,     0,   202,   203,   204,     0,
     268,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   406,   223,
     224,   225,   226,   227,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1192,     0,     0,
       0,   234,   235,   236,   237,     0,     0,     0,     0,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   240,   241,   242,     0,     0,     0,     0,   201,   159,
       0,   243,    23,     0,   244,   202,   203,   204,     0,     0,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   406,   223,   224,
     225,   226,   227,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     234,   235,   236,   237,     0,     0,     0,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   241,   242,     0,     0,     0,     0,     0,     0,     0,
     243,    23,     0,   244,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,     0,   254,     0,     0,  1434,   255,     0,     0,
       0,     0,   257,   258,   259,     0,   260,   261,   262,     0,
       0,   370,   113,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   407,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
     351,  1557,     0,     0,     0,     0,     0,   268,     0,     0,
       0,     0,   371,   372,   373,   374,   375,   376,   377,   378,
     379,     0,     0,     0,     0,   380,   381,   382,   383,     0,
       0,     0,   254,   384,   385,   386,   255,     0,   387,     0,
     388,   257,   258,   259,     0,   260,   261,   262,     0,     0,
       0,   113,     0,   389,     0,     0,   390,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   263,   407,     0,
       0,     0,     0,     0,   265,   201,   159,     0,     0,   351,
    1880,     0,   202,   203,   204,     0,   268,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   406,   223,   224,   225,   226,   227,
     228,     0,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
     237,     0,     0,     0,     0,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   243,    23,     0,
     244,     0,     0,     0,   391,   392,   393,     0,     0,     0,
       0,     0,     0,     0,     0,   394,     0,     0,     0,   395,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,     0,     0,
      41,    42,    43,    44,     0,     0,    46,     0,     0,     0,
       0,     0,     0,   738,    53,     0,     0,    56,   739,     0,
     740,   741,     0,   742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,   255,    90,    91,    92,     0,   257,   258,
     259,     0,   260,   261,   262,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,   263,   407,     0,     0,     0,     0,
       0,   265,     0,     0,     0,     0,   351,     0,     0,     0,
       0,     0,     0,   268,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     0,     0,     0,
      41,    42,    43,    44,     0,     0,    46,     0,     0,  1194,
       0,     0,     0,   738,    53,     0,     0,    56,   739,     0,
     740,   741,     0,   742,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,    41,    42,    43,
      44,     0,     0,    46,    90,    91,    92,     0,     0,     0,
     738,    53,     0,     0,    56,   739,     0,   740,   741,     0,
     742,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    90,    91,    92,    41,    42,    43,    44,     0,     0,
      46,     0,     0,     0,     0,     0,     0,   738,    53,  1195,
       0,    56,   739,     0,   740,   741,     0,   742,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       0,    41,    42,    43,    44,     0,     0,    46,    90,    91,
      92,     0,     0,     0,   738,    53,  1214,     0,    56,   739,
       0,   740,   741,     0,   742,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    90,    91,    92,    41,    42,
      43,    44,     0,     0,    46,     0,     0,     0,     0,     0,
       0,   738,    53,  1244,     0,    56,   739,     0,   740,   741,
       0,   742,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,     0,     0,    41,    42,    43,    44,     0,
       0,    46,    90,    91,    92,     0,     0,     0,   738,    53,
    1277,     0,    56,   739,     0,   740,   741,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    90,
      91,    92,    41,    42,    43,    44,     0,     0,    46,     0,
       0,     0,     0,     0,     0,   738,    53,  1431,     0,    56,
     739,     0,   740,   741,     0,   742,    -4,     1,     0,     0,
      -4,     0,     0,     0,     0,     0,     0,     0,     0,    -4,
      -4,     0,    76,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,    90,    91,    92,     0,
      -4,    -4,     0,     0,  2052,  1476,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,    -4,    -4,     0,     0,     0,    -4,    -4,     0,    -4,
       0,     0,     0,     0,    -4,    -4,    -4,    -4,     0,    -4,
      -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,  2111,    -4,     0,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,     0,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
       0,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,     0,     6,     0,    -4,    -4,
      -4,     0,     0,     0,    -4,     7,     8,     0,     0,    -4,
      -4,    -4,    -4,     0,     0,    -4,     0,    -4,     0,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,     0,     9,    10,     0,    -4,
      -4,    -4,     0,     0,     0,     0,     0,     0,     0,     0,
      -4,     0,    -4,     0,     0,     0,    11,    12,    13,     0,
       0,     0,    14,    15,     0,    16,     0,     0,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     0,    23,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     0,
       0,    40,    41,    42,    43,    44,    45,     0,    46,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     7,     8,     0,    85,    86,    87,     0,     0,     0,
      88,     0,     0,     0,     0,    89,    90,    91,    92,     0,
       0,    93,     0,    94,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,   112,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,     0,     0,    41,    42,
      43,    44,     0,     0,    46,     0,     0,     0,     0,     0,
       0,   738,    53,     0,     0,    56,   739,     0,   740,   741,
       0,   742,     0,     0,     0,  1006,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
       0,     0,  1007,     0,     0,     0,     0,     0,     0,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    90,    91,    92,    41,    42,    43,    44,     0,
       0,    46,     0,     0,     0,     0,     0,     0,   738,    53,
       0,     0,    56,   739,     0,   740,   741,     0,   742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,    90,
      91,    92,     0,     0,     0,     0,     0,     0,  1603,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1604,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1605,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1619,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1749,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1867,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1868,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1896,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1899,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1966,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2020,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2021,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2035,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2037,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2070,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2098,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2103,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2104,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2105,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2145,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,     0,     0,   795,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,  1043,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,  1099,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,  1142,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
    1143,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,  1186,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,  1217,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,  1235,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,     0,     0,  1291,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,  1435,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,     0,     0,  1507,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,  1508,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,  1509,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,  1510,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
    1799,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,  1810,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,  1847,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,  1916,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,     0,     0,  1931,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,  1943,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,     0,     0,  2000,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,     0,     0,  2009,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,     0,  2010,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,     0,
       0,  2033,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,     0,
    2084,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,     0,     0,  2124,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,     0,     0,  2143,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,     0,     0,  2163,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,     0,     0,  2164,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,  2165,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,     0,   700,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
       0,   910,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,     0,  1909,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,   725,     0,   726,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,   969,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
    1020,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,  1166,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,  1230,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,  1231,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,     0,     0,  1236,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   699,   573,   574,   575,   576,     0,     0,     0,
       0,   577,     0,     0,     0,  1237,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   699,
     573,   574,   575,   576,     0,     0,     0,     0,   577,     0,
       0,     0,  1327,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   699,   573,   574,   575,
     576,     0,     0,     0,     0,   577,     0,     0,     0,  1341,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   699,   573,   574,   575,   576,     0,     0,
       0,     0,   577,     0,     0,     0,  1539,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,     0,     0,  1625,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   699,   573,   574,
     575,   576,     0,     0,     0,     0,   577,     0,     0,     0,
    1673,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   699,   573,   574,   575,   576,     0,
       0,     0,     0,   577,     0,     0,     0,  1859,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   699,   573,   574,   575,   576,     0,     0,     0,     0,
     577,     0,     0,     0,  1901,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   699,   573,
     574,   575,   576,     0,     0,     0,     0,   577,     0,     0,
       0,  1917,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   776,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   777,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   778,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   780,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   781,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   782,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   784,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   785,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   786,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   787,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   788,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   789,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   790,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   792,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   793,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   794,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   859,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   894,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   939,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   957,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   959,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   960,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   961,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,   967,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,   968,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1005,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1019,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1079,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1083,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1095,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1165,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1175,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1176,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1177,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1187,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1216,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1218,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1219,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1220,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1221,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1222,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1223,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1224,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1229,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1326,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1340,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1540,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1570,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1571,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1572,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1573,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1611,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1624,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1736,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1738,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1741,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1748,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1800,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1809,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1832,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1900,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  1964,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  1965,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577,
       0,  2097,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   699,   573,   574,   575,   576,
       0,     0,     0,     0,   577,     0,  2140,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     699,   573,   574,   575,   576,     0,     0,     0,     0,   577
};

static const yytype_int16 yycheck[] =
{
       3,     3,     3,  1215,   318,   720,   139,    60,  1661,   306,
     614,   615,   704,   728,  1397,   152,  1704,     4,  1706,  1211,
      23,     4,   336,    23,   190,    52,     4,     4,     4,     4,
       4,     4,   198,     5,     4,   134,     5,   104,     4,   106,
       5,     4,     4,   735,  1691,     5,     4,     6,   100,    52,
       7,     6,     6,     6,     4,     4,     4,   100,    59,  1881,
     752,   134,   245,     7,     6,     4,     4,     6,   760,     6,
     253,   123,   139,   232,   233,   154,     9,    80,   151,    97,
     123,   100,   100,   182,   102,    88,   159,   160,   161,   403,
      93,   405,   165,   166,   253,     9,     9,   164,     4,   413,
     179,   104,   134,     9,   245,   232,   233,  1754,     0,   250,
      86,     7,   241,   242,   232,   233,   195,   196,     9,   151,
    1773,   250,   288,   289,   290,     9,   253,   159,   160,   161,
     232,   233,     9,   165,   166,   253,   139,   250,   140,   245,
     253,   144,   145,    94,   232,   233,    94,   253,     6,   152,
      98,   253,   247,   103,   104,    94,   104,   105,   253,   107,
     108,   249,   113,   329,   330,   331,   169,     7,     6,   861,
     248,     7,   199,     6,   252,    94,   249,    14,    97,   127,
     346,   100,   185,   102,   232,   233,    97,   190,     6,   100,
     193,   169,   170,   171,   172,   198,   199,   200,     6,   245,
     138,   139,   140,   141,     7,   253,  2028,   253,   167,   232,
     233,     7,   167,   244,   190,   153,   179,   180,   156,     7,
     244,   179,   180,   250,   232,   233,    97,     6,   194,   100,
     253,   102,     6,  1616,   232,   233,   245,     6,   239,   216,
     216,   216,   113,   216,   253,   253,   216,   250,   245,     6,
     247,   252,   253,  1906,   245,   253,   253,   244,   244,  1451,
     287,   264,   253,   246,   267,   268,   246,   216,   268,   252,
     244,   249,   248,   300,   251,   248,   248,   304,   248,   248,
     283,   284,   244,   248,   287,   288,   289,   290,   248,   603,
     244,   605,   606,   250,   248,   248,   245,   300,   247,     6,
     244,   304,   246,   306,  1019,  1020,   248,  1960,   622,     6,
     216,   244,   244,   246,   246,    66,    67,   250,    69,   237,
     238,   217,   218,   219,   220,   243,   329,   330,   331,   246,
     244,   244,   246,   246,   244,   241,   242,   250,   244,   244,
     246,   246,   248,   346,   250,   241,   242,   661,   253,   352,
     241,   242,   419,   244,   250,   246,   247,   241,   242,   250,
     244,   100,   246,   102,   241,   242,   250,   244,   244,   246,
     246,   537,   248,   250,   232,   233,  2064,   217,   218,   219,
     220,   217,   218,   219,   220,   245,   700,    97,   415,   416,
     100,   139,   529,   253,   232,   233,   144,   145,     6,   232,
     233,   241,   242,   113,   431,   241,   242,   410,   411,   227,
     228,     6,   415,   416,   217,   218,   219,   220,   244,   227,
     228,   217,   218,   219,   220,   232,   233,   244,   431,   217,
     218,   219,   220,   245,   437,   247,   134,   185,   241,   242,
     441,   253,   232,   233,   241,   242,   253,  2100,   134,   232,
     233,   248,   200,   151,   244,   458,   248,  1149,   248,  1151,
     247,   159,   160,   161,   134,   151,   253,   165,   166,   244,
     253,   246,  1164,   159,   160,   161,   543,   232,   233,   165,
     166,   151,   232,   233,   487,   232,   233,   241,   242,   159,
     160,   161,   232,   233,   248,   165,   166,   115,   253,   526,
    2153,   232,   233,   253,    94,     6,   253,    97,   511,   536,
     100,   538,   102,   253,  1897,   518,   519,   248,   100,   245,
     523,   247,   525,   526,   527,   528,   529,   232,   233,   532,
     232,   233,   669,   536,   537,   538,   539,   540,   541,   542,
     244,   544,   542,   546,   544,   244,   248,   246,   253,   232,
     233,   249,   232,   233,   245,   232,   233,   244,   309,   310,
     232,   233,   253,   249,   232,   233,   317,   318,   244,   572,
     253,   232,   233,   253,   248,   578,   253,   232,   233,   249,
    1272,   253,   232,   233,   244,   253,  1278,   720,   248,   244,
     244,    94,   253,   248,    97,   598,   599,   100,     8,   102,
     914,    94,   244,   253,    97,   232,   233,   100,   102,   245,
     113,   247,   614,   615,   244,   682,   246,   253,   248,   620,
     113,   248,   234,   235,   236,   237,   238,   244,   244,     8,
     246,   243,     4,  1325,   250,   249,   245,   253,   247,   253,
     641,   644,   645,   646,   253,   248,   245,  1339,   247,   138,
     139,   138,   139,  1345,   253,   144,   244,   144,   244,   250,
     248,   252,   410,   244,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   244,   677,   678,   679,   680,   681,   244,
     683,   684,   685,   686,   687,   249,   686,   690,   741,   253,
     717,   244,   693,   249,   244,   696,   246,   253,   701,   232,
     233,   234,   235,   236,   237,   238,   248,   708,   775,  1424,
     243,   249,   249,   249,   717,   253,   253,   253,   249,   249,
     244,   249,   253,   253,   727,   253,   249,   249,   249,   732,
     253,   253,   253,   249,   249,   244,   249,   253,   253,   740,
     253,   742,   244,   249,   249,   748,   749,   253,   253,   249,
     100,   754,   249,   253,   757,   758,   253,   890,   244,   249,
     763,   249,   765,   253,   249,   253,   249,   249,   253,   249,
     253,   253,   249,   253,   249,   523,   253,   525,   253,   527,
     528,   249,   249,   249,   249,   253,   253,   253,   253,   249,
     249,   539,   540,   253,   253,   798,   249,   800,  1513,   249,
     253,   249,   249,   253,   249,   253,   253,   244,   253,   246,
    1525,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   248,
     833,   249,   249,   243,   249,   253,   253,   904,   253,   249,
     843,  2053,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      97,   612,   613,   249,   243,   249,   617,   253,   249,   253,
     249,   249,   253,   249,   901,   253,   879,   253,   249,   249,
     249,   249,   253,   253,   253,   253,  1019,  1020,   249,   892,
     244,   249,   253,   249,  2086,   253,   248,   253,   901,   100,
    2112,   249,   249,     4,     5,   253,   253,   910,   245,   249,
     247,   248,   913,   253,   915,   916,   245,    97,   247,   248,
     668,    97,   670,   671,   672,   673,   674,   675,   929,   677,
     678,   679,   680,   241,   242,   683,   684,   685,  2130,   244,
       4,   246,     6,     6,     7,    46,    47,    48,    49,    50,
      51,    52,    53,    54,  1021,     6,     7,   100,    59,    60,
      61,    62,     4,   964,   232,   233,    67,    68,    69,     4,
       4,    72,   244,    74,   244,   244,     6,   244,   244,   252,
       6,   246,   244,   246,  1011,     6,    87,   248,   248,    90,
       6,   244,     9,   252,   244,   244,   244,   244,   244,  1000,
     244,   244,   123,  1030,   244,   244,   248,   182,  1011,   757,
    1307,   182,   182,   248,   244,   244,   244,   765,   244,   182,
     244,   248,  1025,   244,     4,   248,   248,  1030,   248,   130,
     248,   248,  1165,  1166,   244,   244,   244,   244,   244,  1042,
     244,   244,  1646,  1647,  1047,   244,     6,     6,   246,     6,
    1077,  1078,   248,  1080,  1081,  1082,   248,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,   248,   246,   248,
       6,     6,   246,   246,  1077,  1078,   248,  1080,  1081,  1082,
     182,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,   244,   244,  1096,   244,   244,   244,   198,   199,   200,
     244,   246,     6,     6,     6,     6,   248,  1134,   209,     8,
       8,   248,   213,     7,   215,   216,     6,   248,     6,   248,
      89,   249,   245,   253,     7,     6,   253,     6,   245,  1156,
     248,  1134,  1135,  1136,   248,   243,    64,   250,     8,     4,
     241,   242,   245,     7,     7,  1172,   244,   248,     6,   250,
       6,   248,     7,  1156,     6,   249,     7,     6,     6,   179,
     248,   245,   249,   249,   247,     6,   917,   248,   248,  1172,
    1173,  1174,   248,   924,   248,   250,     7,   928,     6,   246,
     248,     4,   244,     7,     6,     6,  1500,     6,     6,   245,
    1504,   246,  1193,  1326,  1327,     7,     7,     7,  1225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,  1239,  1240,  1241,     7,   243,     7,     7,     7,
       7,     7,  1225,  1520,     7,     7,     7,     7,     7,     7,
     248,     6,   245,   247,   253,     7,  1239,  1240,  1241,   249,
     245,   253,   253,   249,   253,   248,   250,  1250,     8,     7,
     248,   248,  1255,     4,     6,   250,  1259,   249,   249,   134,
       7,  1288,     6,   250,     7,  1268,     7,  1270,     7,   245,
    1273,   245,   253,     9,   253,   253,   247,   245,   250,   252,
    1347,  1282,  1349,     7,   249,  1288,   182,   154,     6,     6,
     248,     6,     4,    46,   250,   244,    46,   248,   244,  1047,
     248,   244,   244,   250,  1307,   250,     4,     7,  1912,   253,
       7,     7,   245,   182,     7,     7,     7,     6,   245,   253,
       7,     7,  1349,     7,  1327,  1076,     4,   112,     4,  1332,
     248,  1334,     6,   244,     7,  1362,     6,   100,     7,  1366,
       7,     7,     7,     7,     7,     7,  1349,     6,   248,     6,
       6,   248,     7,     6,     6,     4,     4,     7,   251,  1362,
     245,   253,   253,  1366,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
    1513,   249,   248,     6,   243,     6,   248,  1135,  1136,  1526,
    1527,  1418,  1419,  1420,     6,     6,   246,     6,   244,  1426,
     244,   248,     6,     6,   249,     6,     6,   250,   247,     6,
       6,   253,     6,   127,  1441,  1418,  1419,  1420,     6,     6,
       6,  1718,     6,  1426,     6,  1452,     6,     6,     6,  1496,
       6,     6,     5,  1460,     6,     4,   245,   245,  1441,     6,
       4,     6,   248,   248,     7,   248,   248,   248,   246,  1452,
       6,     6,   248,   248,   248,   248,     6,  1460,     6,     6,
    1463,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   248,
     248,   248,     6,   243,   178,   245,     6,   247,     6,   253,
    1623,  1558,   253,   248,   253,     6,   245,   253,     7,   244,
       4,     6,   250,     6,     4,  1532,     8,  1255,   248,     6,
       6,  1259,   249,   244,   244,     7,     6,  1520,     6,     6,
    1268,     6,  1270,  1526,  1527,  1273,     6,     6,     6,  1532,
       6,  1558,    98,     6,     5,   248,   245,     6,   248,     6,
     248,     6,   253,     6,     6,     6,   253,  1550,     6,   253,
     245,   253,     6,     4,     6,  1558,     6,     6,     6,     6,
    1563,     6,     6,   253,     7,   248,   248,   248,   248,     6,
       5,   248,     6,   245,     6,  1642,     6,   248,     7,  1327,
     248,     6,   177,     6,  1721,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     245,  1734,   249,   249,   243,   248,     6,  1921,  1635,   249,
       7,   249,   249,     6,   250,     6,     6,  1684,     6,   248,
       6,     6,   249,     6,  1691,  1692,   245,     6,   248,     6,
       6,   180,  1635,   248,  1661,  1638,  1639,   244,     6,   249,
     245,   249,   248,  1710,  1646,  1647,   248,     6,     6,  1676,
     248,   134,  1949,     6,     6,   248,     6,   249,  1661,   248,
       6,     6,   245,   248,  1667,     6,     6,     6,   249,     6,
       6,     6,   249,  1676,     6,     6,     6,   248,   248,     6,
    1707,     6,     6,  1686,     6,     6,  1689,   248,     6,     6,
    1338,  2066,  1392,  1720,  1568,  1882,  1844,  1631,   455,  1450,
    2014,     3,  1361,  1704,  1707,  1706,     3,     3,     3,   593,
    1908,  1714,  1493,     3,  1527,  1718,   757,  1720,  1721,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,  1691,
    2054,   243,    -1,   245,    -1,    -1,  1773,  1714,     6,    -1,
      -1,  1754,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
    1773,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,  1846,
      -1,  1808,  1785,  1786,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,  1550,    -1,    -1,  1808,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
    1887,    -1,    -1,    -1,    -1,  1576,    -1,    -1,    -1,    -1,
    1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1870,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1883,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1870,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1906,
    1883,    -1,    -1,    -1,    -1,  1888,  1889,  1890,    -1,    -1,
      -1,    -1,    -1,  1920,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1906,    -1,    -1,  1909,    -1,    -1,    -1,
    1912,  1662,  1663,  1664,  1665,  1666,  1667,  1920,    -1,    -1,
      -1,  1924,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,  1960,    -1,    -1,    -1,    -1,  1686,    -1,
      -1,  1689,    -1,    -1,    -1,    -1,  1949,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1960,    -1,    -1,
    1987,    -1,  2029,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,     6,    -1,    -1,  1987,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1999,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,  2038,    -1,   123,   124,    -1,
      -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,
      -1,    -1,    -1,  2056,  2057,  2058,  2059,  2060,    -1,    -1,
      -1,    -1,    -1,  2064,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   112,    -1,  2100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2087,    -1,   174,   175,
     176,    -1,    -1,    -1,    -1,    -1,    -1,  2100,   139,    -1,
      -1,    -1,   143,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2117,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2153,    -1,    -1,   170,
     171,   172,    -1,   174,   175,   176,  2139,   178,   179,   180,
     181,   182,   183,   184,    -1,   186,   187,   188,   189,    -1,
    2153,    -1,   193,    -1,    -1,    -1,    -1,  2160,  2161,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2174,    -1,    -1,  1925,  1926,  1927,  1928,  1929,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,   263,   264,   265,   266,   267,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1986,    -1,    -1,    -1,  1990,
      -1,   282,   283,   284,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   312,   313,    -1,    -1,    -1,    -1,   318,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   328,    -1,  2040,
      -1,    -1,    -1,  2044,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2060,
     351,   352,    -1,    -1,    -1,   356,   357,   358,    -1,   360,
      -1,    -1,    -1,   364,   365,   366,    -1,    -1,   369,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,  2107,  2108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,
     411,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   429,    -1,
      -1,  2139,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2160,  2161,    -1,    -1,    -1,    -1,    -1,   460,
     461,   462,   463,    -1,    -1,    -1,  2174,   468,    -1,    -1,
      -1,   472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   486,   487,    -1,    -1,    -1,
     491,    -1,    -1,    -1,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,    -1,
     521,   522,    -1,   524,    -1,    -1,    -1,    -1,    -1,    -1,
     531,    -1,    -1,   534,   535,    -1,    -1,    -1,    -1,    -1,
     541,   193,    -1,    -1,    -1,   546,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,    -1,   579,   580,
      -1,    -1,    -1,    -1,    -1,    -1,   587,   588,   589,    -1,
      -1,    -1,    -1,    -1,   595,   596,    -1,   598,   599,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,   267,   617,   618,   619,    -1,
      -1,    -1,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   283,   284,    -1,    -1,   636,    -1,   638,    -1,   640,
      -1,    -1,    -1,   644,   645,   646,   647,    -1,   649,   650,
     651,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,   676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   690,
      -1,    -1,    -1,    -1,    -1,    -1,   697,    -1,   699,    -1,
     352,   702,   703,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     711,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,
      -1,   193,   733,   734,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   748,    -1,   750,
     751,    -1,    -1,   754,   755,    -1,    -1,    -1,   759,   411,
      -1,     4,     5,    -1,    -1,   766,    -1,    -1,    -1,   770,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,   796,    -1,   798,    -1,   800,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,   283,   284,    -1,    67,    68,    69,     6,    -1,    72,
      -1,    74,   833,    -1,    -1,   487,    -1,    -1,    -1,    -1,
      -1,    -1,   843,    -1,    87,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,
      -1,    -1,    -1,    -1,    -1,    -1,   518,   519,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   879,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,   541,
      -1,   892,    -1,    -1,   546,    -1,    -1,    -1,    -1,   900,
      -1,    -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,   910,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,   919,    -1,
     572,    -1,    -1,   924,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   940,
      -1,    -1,   943,    -1,    -1,    -1,   598,   599,    -1,   411,
      -1,    -1,    -1,    -1,    -1,   198,   199,   200,    -1,    -1,
      -1,    -1,   963,    -1,   965,   966,   209,    -1,    -1,    -1,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   984,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   644,   645,   646,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,    -1,   247,   248,  1007,    -1,    -1,    -1,
      -1,    -1,    -1,  1014,  1015,  1016,  1017,    -1,    -1,    -1,
      -1,  1022,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1036,  1037,    -1,   690,    -1,
      -1,  1042,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
    1071,  1072,  1073,  1074,    -1,   727,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   546,    -1,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1096,   748,    -1,    -1,    -1,
      -1,    -1,   754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1122,  1123,  1124,    -1,    -1,    -1,    -1,  1129,  1130,
      -1,  1132,    -1,    13,    14,    -1,   598,   599,    -1,    -1,
      -1,    -1,    -1,  1144,  1145,    -1,   798,    -1,   800,    -1,
      -1,  1152,  1153,    -1,    -1,    -1,    -1,    -1,  1159,    -1,
    1161,  1162,    -1,    -1,    -1,    -1,    -1,  1168,  1169,    -1,
      -1,    -1,  1173,  1174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   833,   644,   645,   646,    -1,    -1,    -1,    -1,    -1,
      -1,   843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   879,   690,    -1,
     110,   111,   112,   113,    -1,    -1,   116,  1238,    -1,    -1,
     892,    -1,    -1,   123,   124,    -1,    -1,   127,   128,  1250,
     130,   131,    -1,   133,    -1,    -1,    -1,  1258,   910,    -1,
      -1,    -1,    -1,    -1,    -1,   727,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1279,  1280,
      -1,    -1,    -1,  1284,    -1,    -1,   748,     6,    -1,    -1,
      -1,    -1,   754,    -1,   174,   175,   176,  1298,    -1,    -1,
    1301,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,  1328,    -1,    -1,
    1331,  1332,  1333,  1334,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1342,    -1,  1344,    -1,  1346,  1347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,   833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1042,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    -1,    -1,   879,    67,    68,
      69,    -1,    -1,    72,  1425,    74,    -1,    -1,    -1,    -1,
     892,  1432,  1433,  1434,    -1,    -1,    -1,    -1,    87,    -1,
    1441,    90,  1443,    -1,  1096,    -1,    -1,    -1,   910,  1450,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1463,    -1,    -1,    -1,    -1,  1468,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1476,  1477,  1478,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,  1488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1498,    -1,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,  1173,  1174,  1524,   243,    -1,    -1,    -1,    -1,  1530,
    1531,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
     199,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,    -1,  1563,    -1,   213,    -1,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1042,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1250,   248,
      -1,    -1,  1603,  1604,  1605,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1614,    -1,    -1,    -1,    -1,  1619,  1620,
    1621,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1633,    -1,  1096,    -1,    -1,  1638,  1639,  1640,
      -1,  1642,    -1,    -1,    -1,    -1,    -1,  1648,  1649,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1667,    -1,    -1,    -1,
    1671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1332,    -1,  1334,  1684,    -1,    -1,  1687,    -1,    -1,    -1,
    1691,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1700,
    1701,    -1,  1703,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1711,  1173,  1174,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1727,    -1,    -1,    -1,
      -1,  1732,  1733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1746,    -1,    -1,  1749,  1750,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1785,  1786,    -1,    -1,  1250,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1811,  1463,    -1,   433,    -1,    -1,    -1,    -1,    -1,  1820,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1829,  1830,
      -1,    -1,  1833,    -1,    -1,    -1,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,     6,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1867,  1868,    -1,    -1,
    1332,    -1,  1334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1886,    -1,    -1,  1889,  1890,
    1891,    -1,    -1,    -1,    -1,  1896,    -1,    -1,  1899,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1909,    -1,
      -1,  1563,   532,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1924,    -1,    -1,    -1,     4,     5,    -1,
      -1,  1932,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,  1957,    -1,    -1,    -1,
      -1,    -1,  1963,   583,    -1,  1966,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,  1638,  1639,    -1,    -1,
      67,    68,    69,    -1,  1995,    72,    -1,    74,    -1,    -1,
      -1,  1463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    90,    -1,  1667,    -1,    -1,    -1,  2020,
    2021,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2034,  2035,    -1,  2037,  2038,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2051,    -1,    -1,   130,    -1,  2056,  2057,  2058,  2059,  2060,
     134,    -1,    -1,    -1,    -1,  2066,    -1,    -1,    -1,  2070,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,     6,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,  2098,    -1,    -1,
      -1,    -1,  2103,  2104,  2105,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,  2117,    -1,    -1,    -1,
      -1,   198,   199,   200,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   209,  1785,  1786,    -1,   213,    -1,   215,   216,
      -1,    -1,    -1,    -1,  2145,  2146,  2147,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,  1820,   243,
      -1,    -1,    -1,    -1,    -1,    -1,  1638,  1639,    -1,    -1,
      -1,  1833,    -1,    -1,    -1,   805,   806,   807,   808,   809,
     810,   811,   812,   813,   814,   815,    -1,   817,   818,   819,
     820,    -1,   822,   823,   824,   825,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,   836,    -1,   838,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   846,    -1,    -1,    -1,
      -1,    -1,    -1,   853,   854,    -1,    -1,  1889,  1890,    -1,
      -1,    -1,   862,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,  1909,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,  1924,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    26,    -1,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,  1785,  1786,   243,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     970,   971,   972,    -1,    -1,    -1,   976,   977,    -1,    -1,
     980,   981,   982,   983,    -1,   985,    -1,    -1,    -1,    -1,
     990,  1833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2038,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     198,   199,   200,    -1,  2056,  2057,  2058,  2059,  2060,    -1,
      -1,   209,    -1,    -1,    -1,   213,    -1,   215,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1889,  1890,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,  1909,    -1,    -1,
    1070,   243,    -1,    -1,     8,  1075,    -1,    -1,    -1,    -1,
      -1,    -1,  1924,    -1,    -1,  2117,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,    -1,   236,   237,    -1,    -1,
      -1,    -1,    -1,   243,   244,     3,     4,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,   255,   256,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1170,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2038,    75,    76,    77,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,  2056,  2057,  2058,  2059,  2060,    -1,
      -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,   372,   373,    -1,    -1,    -1,   377,   378,   379,
     380,   381,   382,   383,    -1,   385,    -1,    -1,    -1,   389,
     390,    -1,    -1,   393,    -1,  2117,    -1,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    -1,    -1,   406,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
    1310,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1348,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    13,    14,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
    1380,  1381,  1382,  1383,  1384,    -1,    -1,    -1,    -1,  1389,
    1390,    -1,    -1,  1393,    -1,  1395,    -1,    -1,    -1,  1399,
      -1,    -1,  1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1414,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,   554,    -1,    -1,   243,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    -1,
      -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,
      -1,    -1,    -1,    -1,  1484,    -1,  1486,    -1,    -1,    -1,
    1490,    -1,  1492,    -1,   150,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,   174,   175,
     176,    -1,    -1,    -1,    -1,    -1,  1526,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   249,     8,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,  1622,    74,    75,    76,    77,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,
      -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,   153,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1723,    -1,    -1,  1726,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   857,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,   202,    -1,    -1,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,   891,    -1,    -1,  1774,  1775,    -1,  1777,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1837,  1838,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    10,    11,    12,  1884,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    67,    68,
      69,    -1,    -1,    72,  1064,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,
      -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1157,    -1,    -1,
      -1,    -1,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,    -1,   197,   198,
     199,   200,   201,   202,   253,    -1,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
     239,    -1,    -1,    -1,    -1,   244,     3,     4,     5,   248,
       7,    -1,   251,    10,    11,    12,  2126,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,  1311,  1312,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,   130,   245,    -1,   247,    -1,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,  1397,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,  1407,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,   190,    90,    -1,    -1,    -1,    -1,    -1,
     197,   198,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,    -1,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,   239,    -1,   241,   242,    -1,   244,    -1,   246,
      -1,    -1,    -1,   250,   251,     3,     4,     5,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,   198,   199,   200,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,   209,    -1,    63,    64,   213,    -1,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,  1562,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
     248,    -1,     8,   251,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,     3,
       4,     5,    -1,   249,    -1,   251,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,   125,   126,    -1,   128,    -1,   130,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,   156,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
     244,     3,     4,    -1,   248,    -1,    -1,   251,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,   248,   249,    -1,   251,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
      -1,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
     248,    -1,    -1,   251,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,     3,
       4,    -1,   248,    -1,    -1,   251,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,   125,   126,    -1,   128,    -1,   130,    -1,    -1,   133,
      -1,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,   156,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,    -1,
      -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
     244,     3,     4,    -1,    -1,   249,    -1,   251,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,   248,    -1,    -1,   251,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
      -1,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,     3,     4,    -1,
     248,    -1,     8,   251,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,    -1,   128,    -1,   130,    -1,    -1,   133,    -1,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,   201,   202,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,     3,     4,    -1,    -1,   244,     8,
      -1,    10,    11,    12,    -1,   251,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,
      -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,
      -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,
      -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
     239,     3,     4,    -1,    -1,   244,    -1,    -1,    10,    11,
      12,    -1,   251,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   123,    -1,   125,   126,    -1,   128,    -1,   130,    -1,
      -1,   133,    -1,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,   153,    -1,    -1,   156,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,   206,   207,   208,    -1,   210,   211,
     212,    -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,
      -1,    -1,   244,     3,     4,    -1,   248,    -1,    -1,   251,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
     100,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,   125,   126,    -1,   128,    -1,
     130,    -1,    -1,   133,    -1,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,   153,    -1,    -1,   156,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,   201,   202,    -1,    -1,    -1,   206,   207,   208,    -1,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,   244,     3,     4,    -1,   248,    -1,
      -1,   251,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,    -1,   125,   126,    -1,
     128,    -1,   130,    -1,    -1,   133,    -1,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,   153,    -1,    -1,   156,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,     3,     4,     5,    -1,   244,    -1,    -1,    10,
      11,    12,    -1,   251,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,   248,    -1,    -1,
     251,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,
      -1,   244,     3,     4,     5,   248,    -1,    -1,   251,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,
      -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    -1,    90,
       3,     4,     5,    -1,    -1,    -1,    -1,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,    -1,   215,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,   248,    -1,    -1,
     251,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   197,   198,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,   215,   216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
     233,    -1,    -1,    -1,    -1,    -1,   239,     3,     4,    -1,
      -1,   244,    -1,    -1,    10,    11,    12,    -1,   251,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,     3,     4,    -1,    85,
      86,     8,    88,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,    -1,   253,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,
      -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,   248,    -1,    -1,   251,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
     197,    -1,    -1,    -1,   201,    -1,    -1,    -1,   253,   206,
     207,   208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   232,   233,    -1,    -1,    -1,
      -1,    -1,   239,     3,     4,    -1,    -1,   244,    -1,    -1,
      10,    11,    12,    -1,   251,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,     3,
       4,    -1,     6,    -1,    -1,    -1,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,   197,    -1,   243,
      -1,   201,    -1,    -1,    -1,    -1,   206,   207,   208,   253,
     210,   211,   212,    -1,    -1,    -1,   216,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   232,   233,    -1,   110,   111,   112,   113,   239,
      -1,   116,    -1,    -1,   244,   245,    -1,    -1,   123,   124,
      -1,   251,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,   174,
     175,   176,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,     3,     4,    -1,     6,
     244,    -1,    -1,    10,    11,    12,    -1,   251,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,     3,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
     197,    -1,   243,    -1,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   253,   210,   211,   212,    -1,    -1,    -1,   216,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   232,   233,    -1,   110,   111,
     112,   113,   239,    -1,   116,    -1,    -1,   244,    -1,    -1,
      -1,   123,   124,    -1,   251,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,    -1,   210,
     211,   212,   174,   175,   176,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,    -1,    -1,    -1,    -1,   239,     3,
       4,    -1,    -1,   244,    -1,    -1,    10,    11,    12,    -1,
     251,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    -1,    -1,    -1,    -1,     3,     4,
      -1,    85,    86,    -1,    88,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,    -1,   253,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,    -1,   210,   211,   212,    -1,
      -1,     5,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,
      -1,    -1,    -1,    -1,    -1,   239,    -1,    -1,    -1,    -1,
     244,   245,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    -1,
      -1,    -1,   197,    67,    68,    69,   201,    -1,    72,    -1,
      74,   206,   207,   208,    -1,   210,   211,   212,    -1,    -1,
      -1,   216,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,   233,    -1,
      -1,    -1,    -1,    -1,   239,     3,     4,    -1,    -1,   244,
     245,    -1,    10,    11,    12,    -1,   251,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,   198,   199,   200,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,   213,
      -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,   123,   124,    -1,    -1,   127,   128,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,   201,   174,   175,   176,    -1,   206,   207,
     208,    -1,   210,   211,   212,    -1,    -1,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    14,    -1,    -1,   232,   233,    -1,    -1,    -1,    -1,
      -1,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,   251,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,   249,
      -1,    -1,    -1,   123,   124,    -1,    -1,   127,   128,    -1,
     130,   131,    -1,   133,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,    -1,    -1,   116,   174,   175,   176,    -1,    -1,    -1,
     123,   124,    -1,    -1,   127,   128,    -1,   130,   131,    -1,
     133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   174,   175,   176,   110,   111,   112,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   249,
      -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,    -1,    -1,   116,   174,   175,
     176,    -1,    -1,    -1,   123,   124,   249,    -1,   127,   128,
      -1,   130,   131,    -1,   133,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   174,   175,   176,   110,   111,
     112,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,   249,    -1,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,    -1,
      -1,   116,   174,   175,   176,    -1,    -1,    -1,   123,   124,
     249,    -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   174,
     175,   176,   110,   111,   112,   113,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,   249,    -1,   127,
     128,    -1,   130,   131,    -1,   133,     0,     1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,   150,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,   174,   175,   176,    -1,
      44,    45,    -1,    -1,   249,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    -1,    73,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,    83,
      84,    -1,    86,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,   110,   111,   112,   113,
     114,   249,   116,    -1,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,   142,   143,
      -1,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,    -1,     4,    -1,   162,   163,
     164,    -1,    -1,    -1,   168,    13,    14,    -1,    -1,   173,
     174,   175,   176,    -1,    -1,   179,    -1,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,    -1,    44,    45,    -1,   203,
     204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     214,    -1,   216,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    -1,    83,    84,    -1,    86,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,   110,   111,   112,   113,   114,    -1,   116,    -1,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,   142,   143,    -1,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,    13,    14,    -1,   162,   163,   164,    -1,    -1,    -1,
     168,    -1,    -1,    -1,    -1,   173,   174,   175,   176,    -1,
      -1,   179,    -1,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,    -1,    -1,   203,   204,   205,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,   123,   124,    -1,    -1,   127,   128,    -1,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   174,   175,   176,   110,   111,   112,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,
      -1,    -1,   127,   128,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,   174,
     175,   176,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     253,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   253,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,   249,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,   249,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   249,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,    -1,   249,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,
      -1,   249,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,
     249,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,    -1,    -1,   249,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,   248,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
      -1,   248,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,   245,    -1,   247,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,   247,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
     247,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,   247,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,   247,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,   247,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,   247,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,   247,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,   247,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,    -1,    -1,   247,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,    -1,
     247,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,   247,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,   247,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,   247,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243,
      -1,   245,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,   243,    -1,   245,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,    -1,    -1,    -1,    -1,   243
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   255,   256,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    80,
      81,    83,    84,    86,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     109,   110,   111,   112,   113,   114,   116,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   162,   163,   164,   168,   173,
     174,   175,   176,   179,   181,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   203,
     204,   205,   214,   216,   257,   259,   260,   280,   298,   300,
     304,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     322,   324,   325,   331,   332,   333,   334,   340,   365,   366,
     248,   252,    14,   100,   244,   244,     6,   248,     6,     6,
       6,     6,   244,     6,     6,     6,     6,   246,   246,     4,
     342,   366,   244,   246,   278,    94,    97,   100,   102,   278,
     244,   244,   244,     4,   244,   244,   244,     4,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   248,
     115,   100,     6,   248,    94,    97,   100,   113,   303,   102,
     244,     3,    10,    11,    12,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    55,    56,    57,    58,    63,    64,
      75,    76,    77,    85,    88,    94,    97,   100,   102,   113,
     123,   128,   130,   133,   197,   201,   202,   206,   207,   208,
     210,   211,   212,   232,   233,   239,   244,   248,   251,   300,
     301,   304,   315,   322,   324,   335,   336,   340,   342,   349,
     351,   366,   244,   248,   248,   100,   100,   123,    97,   100,
     102,    94,    97,   100,   102,   300,    97,   100,   102,   113,
     301,    97,   100,   244,    97,   154,   179,   195,   196,   248,
     232,   233,   244,   248,   346,   347,   346,   248,   248,   346,
       4,    94,    98,   104,   105,   107,   108,   127,   244,   100,
     102,   100,    97,     4,    86,   190,   248,   366,     4,     6,
      94,    97,   100,    97,   100,   113,   302,     4,     4,     4,
       5,   244,   248,   349,   350,     4,   244,   244,   244,     4,
     248,   353,   366,     4,   244,   244,   244,     6,     6,   246,
       5,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      59,    60,    61,    62,    67,    68,    69,    72,    74,    87,
      90,   198,   199,   200,   209,   213,   215,   357,   366,   244,
       4,   357,     5,   248,     5,   248,    32,   233,   335,   366,
     246,   248,   244,   248,     6,   244,   248,     6,   252,     7,
     130,   190,   217,   218,   219,   220,   241,   242,   244,   246,
     250,   276,   277,   278,   335,   356,   357,   366,     4,   304,
     305,   306,   248,     6,   335,   356,   357,   366,   356,   335,
     356,   363,   364,   366,   282,   286,   244,   345,     9,   357,
     244,   244,   244,   244,   366,   335,   335,   335,   244,   335,
     335,   335,   244,   335,   335,   335,   335,   335,   335,   335,
     356,   335,   335,   335,   335,   350,   244,   233,   335,   351,
     352,   248,   350,   349,   356,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   244,   246,
     278,   278,   278,   278,   278,   278,   244,   278,   278,   244,
     300,   278,   278,     5,   248,   248,   123,   300,   300,   244,
     278,   278,   244,   244,   244,   335,   248,   335,   351,   335,
     335,   249,   352,   342,   366,   182,     5,   248,     8,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   243,     9,   244,
     246,   250,   277,   278,   335,   352,   352,   244,   244,   244,
     349,   350,   350,   350,   299,   248,   244,   349,   248,   248,
     335,     4,   349,   248,   353,   248,   248,   346,   346,   346,
     335,   335,   232,   233,   248,   248,   346,   232,   233,   244,
     306,   346,   248,   244,   248,   244,   244,   244,   244,   244,
     244,   244,   335,   350,   350,   350,   244,     4,   246,     6,
     246,   306,     6,     6,   248,   248,   248,   248,   350,   246,
     246,   246,   335,     8,     6,     6,   335,   335,   335,   250,
     335,   248,   182,   335,   335,   335,   335,   278,   278,   278,
     244,   244,   244,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   244,   244,   278,   244,   246,     6,     6,
     248,     6,     8,   306,     6,     8,   306,   278,   335,   234,
     248,     9,   244,   246,   250,   356,   352,   335,   306,   349,
     349,   248,   357,    94,    97,   100,   102,     7,   335,   335,
       4,   179,   180,   349,     6,   245,   247,   248,   279,     6,
     248,     6,     9,   244,   246,   250,   366,   249,   123,   128,
     130,   131,   133,   298,   300,   335,     6,   245,   253,     9,
     244,   246,   250,   245,   253,   253,   245,   253,     9,   244,
     250,   247,   253,   281,   247,   281,    89,   344,   341,   366,
     253,   335,   335,   335,   335,   253,   245,   245,   245,   335,
     245,   245,   245,   335,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   249,     7,   335,   234,   249,
     253,   335,     6,     6,   245,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   351,   335,   335,   335,   335,   335,   335,   335,
     351,   351,   366,   248,   335,   335,   356,   335,   356,   349,
     356,   356,   363,   248,   335,   279,   366,     8,   335,   335,
     350,   349,   356,   356,   351,   342,   357,   342,   352,   245,
     249,   250,   278,    64,     8,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   248,
     335,   351,   335,   335,   335,   335,   335,   366,   335,   335,
       4,   343,   248,   279,   245,   249,   249,   335,   335,   335,
       7,     7,   328,   328,   244,   335,   335,     6,   352,   352,
     248,   245,     6,   306,   248,   306,   306,   253,   253,   253,
     346,   346,   305,   305,   253,   335,   249,   319,   253,   306,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   245,
       7,   329,     6,     7,   335,     6,   335,   335,   249,   352,
     352,   352,   335,     6,   335,   335,   335,   245,   249,   245,
     245,   245,   179,   253,   306,   248,     8,   245,   245,   247,
     363,   356,   363,   356,   356,   356,   356,   356,   356,   335,
     356,   356,   356,   356,   251,   359,   366,   357,   356,   356,
     356,   342,   366,   352,   249,   249,   249,   249,   335,   335,
     306,   366,   343,   247,   249,   245,   137,   154,   323,   245,
     249,   253,   335,     6,   248,   248,   248,   248,   349,   245,
     247,     7,   276,   277,   250,     7,     6,   352,     7,   220,
     276,   261,   366,   335,   335,   343,   246,   244,   123,   300,
     301,   300,   248,   249,     6,   227,   228,   258,   352,   366,
     335,   335,     4,   343,     6,   352,   335,     6,   356,   364,
     366,   245,   343,     6,   366,     6,   356,   335,   245,   246,
     335,   253,   253,   253,   253,   357,     7,     7,     7,   245,
       7,     7,     7,   245,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   335,   245,   248,   335,   351,   249,
       6,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   253,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   253,   253,   253,   245,   247,   247,   352,   253,
     253,   279,   253,   279,   253,   253,   253,   245,   352,   337,
     279,   249,   249,   249,   253,   253,   279,   279,   245,   250,
     245,   250,   253,   278,   338,   249,     7,   343,   279,   248,
     249,     8,     8,   352,   250,   245,   247,   277,   244,   246,
     278,   352,     7,   248,   248,   245,   245,   245,   335,   349,
       4,   327,     6,   295,   335,   357,   249,   245,   249,   249,
     352,   250,   249,   306,   249,   249,   346,   335,   335,   249,
     249,   335,   346,   134,   134,   151,   159,   160,   161,   165,
     166,   320,   321,   346,   249,   316,   245,   249,   245,   245,
     245,   245,   245,   245,   245,     7,   335,     6,   335,   245,
     247,   247,   249,   249,   249,   249,   247,   247,   253,     7,
       7,     7,   250,   335,   249,   335,   335,     7,   250,   279,
     253,   279,   279,   245,   245,   253,   279,   279,   253,   253,
     279,   279,   279,   279,   335,   279,     9,   358,   253,   245,
     253,   279,   250,   253,   339,   247,   249,   249,   250,   244,
     246,   252,   182,     7,   154,     6,   335,   249,   248,     6,
     349,   249,   335,   335,   335,   335,     6,     7,   276,   277,
     250,   276,   277,   357,   335,     6,     4,   248,   354,   366,
     249,    46,    46,   349,     4,   169,   170,   171,   172,   249,
     264,   268,   271,   273,   274,   250,   245,   247,   244,   335,
     335,   244,   248,   244,   248,     8,   352,   356,   245,   250,
     245,   247,   244,   245,   253,   250,   244,     7,   278,     4,
     289,   290,   291,   279,   335,   335,   335,   335,   279,   346,
     349,   349,     7,   349,   349,   349,     7,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,     6,     7,   352,
     335,   335,   335,   335,   249,   335,   335,   335,   349,   356,
     356,   249,   253,   288,   335,   335,   343,   343,   335,   335,
     245,   349,   278,   335,   335,   335,   249,   343,   277,   250,
     277,   335,   335,   279,   249,   349,   352,   352,     7,     7,
       7,   134,   326,     6,   245,   253,     7,     7,     7,   249,
       4,   249,   253,   253,   253,   249,   249,   112,     4,     6,
     335,   248,     6,   244,     6,   167,     6,   167,   249,   321,
     253,   320,     7,     6,     7,     7,     7,     7,     7,     7,
       7,   349,     6,   248,     6,     6,     6,   100,     7,     6,
       6,   335,   349,   349,   349,     4,   253,     8,     8,   245,
       4,   103,   104,     4,   352,   356,   335,   356,   251,   253,
     292,   356,   356,   343,   356,   245,   253,   343,   248,   300,
     248,     6,   335,     6,   248,   349,   249,   249,   249,   249,
     249,   335,     6,     4,   179,   180,   335,     6,     6,     6,
       7,   353,   355,     6,   246,   279,   278,   278,     6,   265,
     244,   244,   248,   275,     6,   343,   250,   356,   335,   247,
     245,   335,     8,   352,   335,   352,   249,   249,     6,     6,
     258,   343,   250,   335,     6,   335,   343,   245,   248,   335,
     357,   279,    46,   248,   349,   357,   360,   247,   253,     6,
     245,   245,   245,   245,     6,     6,   127,   297,   297,   349,
       6,     6,     6,   349,   134,   182,   296,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     5,   249,   279,   279,
     279,   279,   279,   253,   253,   253,   245,   279,   279,   290,
     279,   245,   279,   245,   278,   338,   279,     6,   279,   253,
     244,   246,   278,     4,   245,   247,   279,     6,   249,   249,
     349,   349,   349,     4,     6,   276,   335,   349,   248,   248,
       7,     6,     7,   335,   335,   335,   248,   248,   248,   246,
       6,   335,   349,   335,     6,     6,   335,   346,   249,     5,
     349,   248,   248,   248,   248,   248,   248,   248,   349,     6,
     352,   248,   335,   247,     6,     6,   178,   335,   335,   335,
       6,     6,     6,     6,     7,   279,   253,   253,   279,   253,
     335,     4,   194,   293,   294,   279,   245,   279,   339,   357,
     244,   246,   335,   248,   306,     6,   306,   253,     6,     6,
       7,   276,   277,   250,     7,     6,   353,   249,   253,   335,
     276,   248,   279,   361,   362,   363,   361,   244,   335,   335,
     348,   349,   248,   244,     4,     6,   245,     6,   245,   249,
     249,   245,   249,     6,     6,   356,   244,     4,   245,   253,
     244,   349,   357,     7,   278,   287,   335,   351,   291,     6,
       6,     6,     6,   346,     6,     6,     6,     6,    94,   113,
      98,     6,     5,   248,   335,   335,   335,   335,   245,   338,
     335,   335,   335,   279,   277,   248,   248,     6,   296,     6,
     335,   349,     4,     6,   352,   352,   335,   335,   357,   249,
     245,   249,   253,   305,   305,   335,   335,   249,   253,   245,
     249,   253,     6,     6,   348,   346,   346,   346,   346,   346,
     233,   346,     6,   249,   335,     6,     6,   349,   249,   253,
       8,   249,   245,   248,   335,   357,   356,   335,   356,   335,
     357,   360,   362,   357,   253,   245,   253,   249,   335,   323,
     323,   349,   357,   335,     6,     4,   354,     6,   353,   247,
     349,   363,     6,   279,   279,   262,   335,   253,   253,   249,
     253,   263,   335,   335,     6,     6,     6,     6,   335,   335,
     245,   283,   285,   248,   362,   249,   253,     7,     7,   248,
     248,   248,     5,   348,   279,   279,   253,   279,   245,   253,
     245,   247,   352,   352,     6,     6,   248,   249,   249,   248,
       6,     6,   248,   335,   249,   249,   249,   247,     6,   349,
       7,   248,   335,   249,   253,   253,   253,   253,   253,   253,
       6,   249,   177,   335,   335,   352,     6,     6,   245,   279,
     279,   294,   357,   249,   249,   249,   249,     6,     6,     7,
       6,   250,     6,   249,     6,     6,   245,   253,   335,   335,
     248,   349,   249,   253,   245,   245,   253,   288,   292,   349,
     279,   335,   357,   366,   352,   352,   335,     6,   249,   335,
     338,   335,   249,   249,   348,   138,   139,   144,   330,   138,
     139,   330,   352,   305,   249,   253,     6,   249,   349,   306,
     249,     6,   352,   346,   346,   346,   346,   346,   335,   249,
     249,   249,   245,     6,   248,     6,   353,   180,   266,   335,
     253,   253,   348,     6,   335,   335,   249,   249,   284,     7,
     244,   249,   249,   249,   248,   253,   245,   253,   248,   249,
     248,   346,   349,     6,   248,   346,     6,   249,   249,   335,
       6,   134,   249,   317,   248,   249,   253,   253,   253,   253,
     253,     6,     6,     6,   306,     6,   248,   335,   335,   249,
     253,   288,   357,   245,   335,   335,   335,   352,     6,   346,
       6,   346,     6,     6,   249,   335,   320,   306,     6,   352,
     352,   352,   352,   346,   352,   323,   263,   245,   253,     6,
     248,   335,   249,   253,   253,   253,   249,   253,   253,     6,
     249,   249,   318,   249,   249,   249,   249,   253,   249,   249,
     249,   269,   335,   348,   249,   335,   335,   335,   346,   346,
     320,     6,     6,     6,     6,   352,     6,     6,     6,   248,
     245,   249,     6,   249,   279,   253,   253,   253,   249,   249,
     267,   356,   272,   248,     6,   335,   335,   335,     6,   249,
     253,   248,   348,   249,   249,   249,     6,   356,   270,   356,
     249,     6,     6,   249,   253,     6,     6,   356
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
#line 269 "Gmsh.y"
    { yyerrok; return 1; ;}
    break;

  case 6:
#line 280 "Gmsh.y"
    { return 1; ;}
    break;

  case 7:
#line 281 "Gmsh.y"
    { return 1; ;}
    break;

  case 8:
#line 282 "Gmsh.y"
    { return 1; ;}
    break;

  case 9:
#line 284 "Gmsh.y"
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
#line 302 "Gmsh.y"
    { return 1; ;}
    break;

  case 11:
#line 303 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 12:
#line 304 "Gmsh.y"
    { return 1; ;}
    break;

  case 13:
#line 305 "Gmsh.y"
    { return 1; ;}
    break;

  case 14:
#line 306 "Gmsh.y"
    { return 1; ;}
    break;

  case 15:
#line 307 "Gmsh.y"
    { return 1; ;}
    break;

  case 16:
#line 308 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 17:
#line 309 "Gmsh.y"
    { List_Delete((yyvsp[(1) - (1)].l)); return 1; ;}
    break;

  case 18:
#line 310 "Gmsh.y"
    { return 1; ;}
    break;

  case 19:
#line 311 "Gmsh.y"
    { return 1; ;}
    break;

  case 20:
#line 312 "Gmsh.y"
    { return 1; ;}
    break;

  case 21:
#line 313 "Gmsh.y"
    { return 1; ;}
    break;

  case 22:
#line 314 "Gmsh.y"
    { return 1; ;}
    break;

  case 23:
#line 315 "Gmsh.y"
    { return 1; ;}
    break;

  case 24:
#line 316 "Gmsh.y"
    { return 1; ;}
    break;

  case 25:
#line 317 "Gmsh.y"
    { return 1; ;}
    break;

  case 26:
#line 322 "Gmsh.y"
    {
      (yyval.c) = (char*)"w";
    ;}
    break;

  case 27:
#line 326 "Gmsh.y"
    {
      (yyval.c) = (char*)"a";
    ;}
    break;

  case 28:
#line 333 "Gmsh.y"
    {
      Msg::Direct((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 29:
#line 338 "Gmsh.y"
    {
      Msg::Error((yyvsp[(3) - (5)].c));
      Free((yyvsp[(3) - (5)].c));
    ;}
    break;

  case 30:
#line 343 "Gmsh.y"
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
#line 357 "Gmsh.y"
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
#line 370 "Gmsh.y"
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
#line 383 "Gmsh.y"
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
#line 411 "Gmsh.y"
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
#line 425 "Gmsh.y"
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
#line 438 "Gmsh.y"
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
#line 451 "Gmsh.y"
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
#line 469 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData = new PViewDataList();
#endif
    ;}
    break;

  case 44:
#line 483 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 45:
#line 485 "Gmsh.y"
    { ViewCoord.push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 46:
#line 490 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(1) - (1)].d)); ;}
    break;

  case 47:
#line 492 "Gmsh.y"
    { if(ViewValueList) ViewValueList->push_back((yyvsp[(3) - (3)].d)); ;}
    break;

  case 48:
#line 497 "Gmsh.y"
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
#line 601 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList){
	for(int i = 0; i < 3; i++)
	  for(unsigned int j = 0; j < ViewCoord.size() / 3; j++)
	    ViewValueList->push_back(ViewCoord[3 * j + i]);
      }
#endif
    ;}
    break;

  case 50:
#line 611 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(ViewValueList) (*ViewNumList)++;
#endif
    ;}
    break;

  case 51:
#line 620 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 52:
#line 627 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T2C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 53:
#line 637 "Gmsh.y"
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
#line 646 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT2++;
#endif
    ;}
    break;

  case 55:
#line 655 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(1) - (1)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(1) - (1)].c)[i]);
#endif
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 56:
#line 662 "Gmsh.y"
    {
#if defined(HAVE_POST)
      for(int i = 0; i < (int)strlen((yyvsp[(3) - (3)].c)) + 1; i++) ViewData->T3C.push_back((yyvsp[(3) - (3)].c)[i]);
#endif
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 57:
#line 672 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->T3D.push_back((yyvsp[(3) - (10)].d)); ViewData->T3D.push_back((yyvsp[(5) - (10)].d));
      ViewData->T3D.push_back((yyvsp[(7) - (10)].d)); ViewData->T3D.push_back((yyvsp[(9) - (10)].d));
      ViewData->T3D.push_back(ViewData->T3C.size());
#endif
    ;}
    break;

  case 58:
#line 680 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewData->NbT3++;
#endif
    ;}
    break;

  case 59:
#line 690 "Gmsh.y"
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
#line 709 "Gmsh.y"
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
#line 728 "Gmsh.y"
    {
#if defined(HAVE_POST)
      ViewValueList = &ViewData->Time;
#endif
    ;}
    break;

  case 62:
#line 734 "Gmsh.y"
    {
    ;}
    break;

  case 63:
#line 741 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 64:
#line 742 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 65:
#line 743 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 66:
#line 744 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 67:
#line 745 "Gmsh.y"
    { (yyval.i) = 4; ;}
    break;

  case 68:
#line 749 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 69:
#line 750 "Gmsh.y"
    { (yyval.i) = -1; ;}
    break;

  case 70:
#line 756 "Gmsh.y"
    { (yyval.c) = (char*)"("; ;}
    break;

  case 71:
#line 756 "Gmsh.y"
    { (yyval.c) = (char*)"["; ;}
    break;

  case 72:
#line 757 "Gmsh.y"
    { (yyval.c) = (char*)")"; ;}
    break;

  case 73:
#line 757 "Gmsh.y"
    { (yyval.c) = (char*)"]"; ;}
    break;

  case 77:
#line 767 "Gmsh.y"
    {
      Msg::SetOnelabNumber((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].d));
      Free((yyvsp[(3) - (7)].c));
    ;}
    break;

  case 78:
#line 772 "Gmsh.y"
    {
      Msg::SetOnelabString((yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
      Free((yyvsp[(3) - (7)].c));
      Free((yyvsp[(5) - (7)].c));
    ;}
    break;

  case 79:
#line 778 "Gmsh.y"
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
#line 840 "Gmsh.y"
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
#line 855 "Gmsh.y"
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
#line 884 "Gmsh.y"
    {
      assignVariables((yyvsp[(1) - (9)].c), (yyvsp[(4) - (9)].l), (yyvsp[(7) - (9)].i), (yyvsp[(8) - (9)].l));
      Free((yyvsp[(1) - (9)].c));
      List_Delete((yyvsp[(4) - (9)].l));
      List_Delete((yyvsp[(8) - (9)].l));
    ;}
    break;

  case 83:
#line 894 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 84:
#line 899 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 85:
#line 907 "Gmsh.y"
    {
      assignVariable((yyvsp[(1) - (7)].c), (int)(yyvsp[(3) - (7)].d), (yyvsp[(5) - (7)].i), (yyvsp[(6) - (7)].d));
      Free((yyvsp[(1) - (7)].c));
    ;}
    break;

  case 86:
#line 912 "Gmsh.y"
    {
      incrementVariable((yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].i));
      Free((yyvsp[(1) - (6)].c));
    ;}
    break;

  case 87:
#line 920 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (4)].c)] = std::vector<std::string>(1, (yyvsp[(3) - (4)].c));
      Free((yyvsp[(1) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 88:
#line 929 "Gmsh.y"
    {
      gmsh_yystringsymbols[(yyvsp[(1) - (8)].c)] = std::vector<std::string>();
      Free((yyvsp[(1) - (8)].c));
    ;}
    break;

  case 89:
#line 934 "Gmsh.y"
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
#line 946 "Gmsh.y"
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
#line 963 "Gmsh.y"
    {
      std::string tmp((yyvsp[(5) - (6)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (6)].c), 0, (yyvsp[(3) - (6)].c), tmp);
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 92:
#line 969 "Gmsh.y"
    {
      std::string tmp((yyvsp[(8) - (9)].c));
      StringOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (9)].c), (int)(yyvsp[(3) - (9)].d), (yyvsp[(6) - (9)].c), tmp);
      Free((yyvsp[(1) - (9)].c)); Free((yyvsp[(6) - (9)].c)); Free((yyvsp[(8) - (9)].c));
    ;}
    break;

  case 93:
#line 978 "Gmsh.y"
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
#line 996 "Gmsh.y"
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
#line 1014 "Gmsh.y"
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
#line 1023 "Gmsh.y"
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
#line 1035 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (8)].c), 0, (yyvsp[(5) - (8)].c), (yyvsp[(7) - (8)].u));
      Free((yyvsp[(1) - (8)].c)); Free((yyvsp[(5) - (8)].c));
    ;}
    break;

  case 98:
#line 1040 "Gmsh.y"
    {
      ColorOption(GMSH_SET|GMSH_GUI, (yyvsp[(1) - (11)].c), (int)(yyvsp[(3) - (11)].d), (yyvsp[(8) - (11)].c), (yyvsp[(10) - (11)].u));
      Free((yyvsp[(1) - (11)].c)); Free((yyvsp[(8) - (11)].c));
    ;}
    break;

  case 99:
#line 1048 "Gmsh.y"
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
#line 1068 "Gmsh.y"
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
#line 1091 "Gmsh.y"
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
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 102:
#line 1110 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1118 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 104:
#line 1125 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 105:
#line 1132 "Gmsh.y"
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
#line 1154 "Gmsh.y"
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
#line 1177 "Gmsh.y"
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
#line 1215 "Gmsh.y"
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
#line 1236 "Gmsh.y"
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
#line 1248 "Gmsh.y"
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
#line 1266 "Gmsh.y"
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
#line 1275 "Gmsh.y"
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
#line 1284 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1286 "Gmsh.y"
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
      Free((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 118:
#line 1304 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1306 "Gmsh.y"
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
      Free((yyvsp[(8) - (11)].l));
    ;}
    break;

  case 120:
#line 1322 "Gmsh.y"
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
#line 1331 "Gmsh.y"
    { init_options(); ;}
    break;

  case 122:
#line 1333 "Gmsh.y"
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
#line 1347 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 125:
#line 1355 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 126:
#line 1361 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 127:
#line 1366 "Gmsh.y"
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
    ;}
    break;

  case 134:
#line 1408 "Gmsh.y"
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
#line 1420 "Gmsh.y"
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
#line 1433 "Gmsh.y"
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
#line 1448 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 138:
#line 1457 "Gmsh.y"
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
#line 1482 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 144:
#line 1490 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 145:
#line 1499 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1507 "Gmsh.y"
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
#line 1521 "Gmsh.y"
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
#line 1539 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 149:
#line 1543 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 150:
#line 1550 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 151:
#line 1558 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 152:
#line 1562 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 153:
#line 1568 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 154:
#line 1572 "Gmsh.y"
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
#line 1583 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 156:
#line 1587 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 157:
#line 1594 "Gmsh.y"
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

  case 158:
#line 1617 "Gmsh.y"
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

  case 159:
#line 1633 "Gmsh.y"
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

  case 160:
#line 1649 "Gmsh.y"
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

  case 161:
#line 1686 "Gmsh.y"
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
        else if(tags.size() == 4){
          r = GModel::current()->getOCCInternals()->addEllipseArc
            (num, tags[0], tags[1], tags[3]);
        }
        else if(param.size() >= 5 && param.size() <= 7){
          double a1 = (param.size() == 7) ? param[5] : 0.;
          double a2 = (param.size() == 7) ? param[6] :
            (param.size() == 6) ? param[5] : 2.*M_PI;
          r = GModel::current()->getOCCInternals()->addEllipse
            (num, param[0], param[1], param[2], param[3], param[4], a1, a2);
        }
        else{
          yymsg(0, "Ellipse requires 3 or 4 points, or 5 to 7 parameters");
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

  case 162:
#line 1726 "Gmsh.y"
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

  case 163:
#line 1742 "Gmsh.y"
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

  case 164:
#line 1759 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (11)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (11)].l), tags);
      std::vector<double> seqknots; ListOfDouble2Vector((yyvsp[(8) - (11)].l), seqknots);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        int degree = (int)(yyvsp[(10) - (11)].d);
        std::vector<double> weights, knots;
        std::vector<int> mults;
        for(unsigned int i = 0; i < seqknots.size(); i++){
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

  case 165:
#line 1790 "Gmsh.y"
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

  case 166:
#line 1806 "Gmsh.y"
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

  case 167:
#line 1823 "Gmsh.y"
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

  case 168:
#line 1839 "Gmsh.y"
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
            for(unsigned int i = 2; i < constraints.size(); i+=2){
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

  case 169:
#line 1889 "Gmsh.y"
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

  case 170:
#line 1907 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 171:
#line 1913 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 172:
#line 1919 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1926 "Gmsh.y"
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

  case 174:
#line 1957 "Gmsh.y"
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

  case 175:
#line 1972 "Gmsh.y"
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

  case 176:
#line 1994 "Gmsh.y"
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

  case 177:
#line 2017 "Gmsh.y"
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

  case 178:
#line 2040 "Gmsh.y"
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

  case 179:
#line 2063 "Gmsh.y"
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

  case 180:
#line 2087 "Gmsh.y"
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

  case 181:
#line 2111 "Gmsh.y"
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

  case 182:
#line 2135 "Gmsh.y"
    {
      int num = (int)(yyvsp[(3) - (7)].d);
      std::vector<double> param; ListOfDouble2Vector((yyvsp[(6) - (7)].l), param);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        if(param.size() >= 2){
          int in = (int)param[0];
          double offset = param[1];
          std::vector<int> exclude;
          for(unsigned int i = 2; i < param.size(); i++)
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

  case 183:
#line 2161 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (8)].d);
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(7) - (8)].l), tags);
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        r = GModel::current()->getOCCInternals()->addSurfaceLoop(num, tags);
      }
      else{
        r = GModel::current()->getGEOInternals()->addSurfaceLoop(num, tags);
      }
      if(!r) yymsg(0, "Could not add surface loop");
      List_Delete((yyvsp[(7) - (8)].l));
      Free((yyvsp[(2) - (8)].c));
      (yyval.s).Type = MSH_SURF_LOOP;
      (yyval.s).Num = num;
    ;}
    break;

  case 184:
#line 2178 "Gmsh.y"
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

  case 185:
#line 2194 "Gmsh.y"
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

  case 186:
#line 2212 "Gmsh.y"
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

  case 187:
#line 2230 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (8)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2238 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (12)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2245 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 190:
#line 2249 "Gmsh.y"
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

  case 191:
#line 2275 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 192:
#line 2277 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 193:
#line 2279 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 194:
#line 2281 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 195:
#line 2283 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 196:
#line 2291 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 197:
#line 2293 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 198:
#line 2295 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 199:
#line 2297 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 200:
#line 2305 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 201:
#line 2307 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 202:
#line 2309 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 203:
#line 2317 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2319 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2321 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2323 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 207:
#line 2333 "Gmsh.y"
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

  case 208:
#line 2349 "Gmsh.y"
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

  case 209:
#line 2365 "Gmsh.y"
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

  case 210:
#line 2381 "Gmsh.y"
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

  case 211:
#line 2397 "Gmsh.y"
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

  case 212:
#line 2413 "Gmsh.y"
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

  case 213:
#line 2450 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Intersect line not available with OpenCASCADE");
      }
      else{
        std::vector<int> in, out; ListOfDouble2Vector((yyvsp[(4) - (9)].l), in);
        r = GModel::current()->getGEOInternals()->intersectCurvesWithSurface
          (in, (int)(yyvsp[(8) - (9)].d), out);
        for(unsigned int i = 0; i < out.size(); i++){
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

  case 214:
#line 2472 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(Shape));
      bool r = true;
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals()){
        yymsg(0, "Split Line not available with OpenCASCADE");
      }
      else{
        std::vector<int> vertices, curves; ListOfDouble2Vector((yyvsp[(7) - (9)].l), vertices);
        r = GModel::current()->getGEOInternals()->splitCurve
          ((int)(yyvsp[(4) - (9)].d), vertices, curves);
        for(unsigned int i = 0; i < curves.size(); i++){
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

  case 215:
#line 2495 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2496 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 217:
#line 2501 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 218:
#line 2505 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 219:
#line 2509 "Gmsh.y"
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
    ;}
    break;

  case 220:
#line 2525 "Gmsh.y"
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
    ;}
    break;

  case 221:
#line 2544 "Gmsh.y"
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
    ;}
    break;

  case 222:
#line 2563 "Gmsh.y"
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

  case 223:
#line 2582 "Gmsh.y"
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

  case 224:
#line 2609 "Gmsh.y"
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

  case 225:
#line 2628 "Gmsh.y"
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

  case 226:
#line 2650 "Gmsh.y"
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

  case 227:
#line 2665 "Gmsh.y"
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

  case 228:
#line 2680 "Gmsh.y"
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

  case 229:
#line 2699 "Gmsh.y"
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

  case 230:
#line 2750 "Gmsh.y"
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

  case 231:
#line 2771 "Gmsh.y"
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

  case 232:
#line 2793 "Gmsh.y"
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

  case 233:
#line 2815 "Gmsh.y"
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

  case 234:
#line 2920 "Gmsh.y"
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

  case 235:
#line 2936 "Gmsh.y"
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

  case 236:
#line 2971 "Gmsh.y"
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

  case 237:
#line 2993 "Gmsh.y"
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

  case 238:
#line 3015 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 239:
#line 3021 "Gmsh.y"
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

  case 240:
#line 3036 "Gmsh.y"
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

  case 241:
#line 3064 "Gmsh.y"
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

  case 242:
#line 3076 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 243:
#line 3085 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3092 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 245:
#line 3104 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      for(unsigned int i = 0; i < dimTags.size(); i++){
        GEntity *ge = GModel::current()->getEntityByTag
          (dimTags[i].first, dimTags[i].second);
        if(ge){
          for(unsigned int j = 0; j < ge->getNumMeshElements(); j++)
            ge->getMeshElement(j)->setPartition((int)(yyvsp[(2) - (5)].d));
        }
      }
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 246:
#line 3123 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 247:
#line 3127 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3132 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 249:
#line 3136 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 250:
#line 3141 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 251:
#line 3148 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3155 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3162 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3174 "Gmsh.y"
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

  case 255:
#line 3247 "Gmsh.y"
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

  case 256:
#line 3265 "Gmsh.y"
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

  case 257:
#line 3290 "Gmsh.y"
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

  case 258:
#line 3305 "Gmsh.y"
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

  case 259:
#line 3338 "Gmsh.y"
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

  case 260:
#line 3350 "Gmsh.y"
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

  case 261:
#line 3374 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 262:
#line 3378 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 263:
#line 3383 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 264:
#line 3390 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 265:
#line 3395 "Gmsh.y"
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

  case 266:
#line 3405 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 267:
#line 3410 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 268:
#line 3416 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 269:
#line 3424 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 270:
#line 3428 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 271:
#line 3432 "Gmsh.y"
    {
      GModel::current()->renumberMeshVertices();
    ;}
    break;

  case 272:
#line 3436 "Gmsh.y"
    {
      GModel::current()->renumberMeshElements();
    ;}
    break;

  case 273:
#line 3440 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 274:
#line 3450 "Gmsh.y"
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

  case 275:
#line 3513 "Gmsh.y"
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

  case 276:
#line 3529 "Gmsh.y"
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

  case 277:
#line 3546 "Gmsh.y"
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

  case 278:
#line 3563 "Gmsh.y"
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

  case 279:
#line 3585 "Gmsh.y"
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

  case 280:
#line 3607 "Gmsh.y"
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

  case 281:
#line 3642 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 282:
#line 3650 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 283:
#line 3658 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 284:
#line 3664 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 285:
#line 3671 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 286:
#line 3678 "Gmsh.y"
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

  case 287:
#line 3698 "Gmsh.y"
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

  case 288:
#line 3724 "Gmsh.y"
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

  case 289:
#line 3736 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 290:
#line 3747 "Gmsh.y"
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

  case 291:
#line 3765 "Gmsh.y"
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

  case 292:
#line 3783 "Gmsh.y"
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

  case 293:
#line 3801 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3807 "Gmsh.y"
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

  case 295:
#line 3825 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3831 "Gmsh.y"
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

  case 297:
#line 3851 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 298:
#line 3857 "Gmsh.y"
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

  case 299:
#line 3875 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 300:
#line 3881 "Gmsh.y"
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

  case 301:
#line 3898 "Gmsh.y"
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

  case 302:
#line 3914 "Gmsh.y"
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

  case 303:
#line 3931 "Gmsh.y"
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

  case 304:
#line 3949 "Gmsh.y"
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

  case 305:
#line 3972 "Gmsh.y"
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

  case 306:
#line 3999 "Gmsh.y"
    {
    ;}
    break;

  case 307:
#line 4002 "Gmsh.y"
    {
    ;}
    break;

  case 308:
#line 4008 "Gmsh.y"
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

  case 309:
#line 4020 "Gmsh.y"
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

  case 310:
#line 4040 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 311:
#line 4044 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 312:
#line 4048 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 313:
#line 4052 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 314:
#line 4056 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 315:
#line 4060 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 316:
#line 4064 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 317:
#line 4068 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 318:
#line 4077 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 319:
#line 4089 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 320:
#line 4090 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 321:
#line 4091 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 322:
#line 4092 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 323:
#line 4093 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 324:
#line 4097 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 325:
#line 4098 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 326:
#line 4099 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 327:
#line 4100 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 328:
#line 4101 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 329:
#line 4106 "Gmsh.y"
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

  case 330:
#line 4129 "Gmsh.y"
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

  case 331:
#line 4149 "Gmsh.y"
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

  case 332:
#line 4170 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 333:
#line 4174 "Gmsh.y"
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

  case 334:
#line 4189 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 335:
#line 4193 "Gmsh.y"
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

  case 336:
#line 4209 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 337:
#line 4213 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 338:
#line 4218 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 339:
#line 4222 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 340:
#line 4228 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 341:
#line 4232 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 342:
#line 4239 "Gmsh.y"
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

  case 343:
#line 4261 "Gmsh.y"
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

  case 344:
#line 4302 "Gmsh.y"
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
              for(unsigned int j = 0; j < corners.size(); j++){
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

  case 345:
#line 4346 "Gmsh.y"
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
              for(unsigned int i = 0; i < corners.size(); i++){
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

  case 346:
#line 4385 "Gmsh.y"
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

  case 347:
#line 4410 "Gmsh.y"
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

  case 348:
#line 4422 "Gmsh.y"
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

  case 349:
#line 4434 "Gmsh.y"
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

  case 350:
#line 4446 "Gmsh.y"
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

  case 351:
#line 4458 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 352:
#line 4467 "Gmsh.y"
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

  case 353:
#line 4497 "Gmsh.y"
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

  case 354:
#line 4523 "Gmsh.y"
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

  case 355:
#line 4550 "Gmsh.y"
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

  case 356:
#line 4582 "Gmsh.y"
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

  case 357:
#line 4609 "Gmsh.y"
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

  case 358:
#line 4635 "Gmsh.y"
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

  case 359:
#line 4661 "Gmsh.y"
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

  case 360:
#line 4687 "Gmsh.y"
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

  case 361:
#line 4713 "Gmsh.y"
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

  case 362:
#line 4734 "Gmsh.y"
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

  case 363:
#line 4745 "Gmsh.y"
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

  case 364:
#line 4793 "Gmsh.y"
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

  case 365:
#line 4847 "Gmsh.y"
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

  case 366:
#line 4862 "Gmsh.y"
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

  case 367:
#line 4874 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 368:
#line 4885 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 369:
#line 4892 "Gmsh.y"
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

  case 370:
#line 4907 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 371:
#line 4920 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 372:
#line 4921 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 373:
#line 4922 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 374:
#line 4927 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 375:
#line 4933 "Gmsh.y"
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

  case 376:
#line 4945 "Gmsh.y"
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

  case 377:
#line 4963 "Gmsh.y"
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

  case 378:
#line 4990 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 379:
#line 4991 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 380:
#line 4992 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 381:
#line 4993 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 382:
#line 4994 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 383:
#line 4995 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 384:
#line 4996 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 385:
#line 4997 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 386:
#line 4999 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 387:
#line 5005 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 388:
#line 5006 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 389:
#line 5007 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 390:
#line 5008 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 391:
#line 5009 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 392:
#line 5010 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 393:
#line 5011 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 5012 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 395:
#line 5013 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 396:
#line 5014 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 397:
#line 5015 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 398:
#line 5016 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 399:
#line 5017 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 400:
#line 5018 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 401:
#line 5019 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 402:
#line 5020 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 403:
#line 5021 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 404:
#line 5022 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 405:
#line 5023 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 5024 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 407:
#line 5025 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 5026 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 409:
#line 5027 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 5028 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 411:
#line 5029 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 5030 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 413:
#line 5031 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 414:
#line 5032 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 415:
#line 5033 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 416:
#line 5034 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 417:
#line 5035 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 418:
#line 5036 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 419:
#line 5037 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 420:
#line 5038 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 421:
#line 5039 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 422:
#line 5040 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 423:
#line 5041 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 424:
#line 5042 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 425:
#line 5051 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 426:
#line 5052 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 427:
#line 5053 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 428:
#line 5054 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 429:
#line 5055 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 430:
#line 5056 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 431:
#line 5057 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 432:
#line 5058 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 433:
#line 5059 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 434:
#line 5060 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 435:
#line 5061 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 436:
#line 5066 "Gmsh.y"
    { init_options(); ;}
    break;

  case 437:
#line 5068 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 438:
#line 5074 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 439:
#line 5076 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 440:
#line 5081 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 441:
#line 5086 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 442:
#line 5091 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 443:
#line 5096 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 444:
#line 5100 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 445:
#line 5104 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 446:
#line 5108 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 447:
#line 5112 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 448:
#line 5116 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 449:
#line 5120 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 450:
#line 5124 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 451:
#line 5130 "Gmsh.y"
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

  case 452:
#line 5146 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 453:
#line 5151 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 454:
#line 5157 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 455:
#line 5163 "Gmsh.y"
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

  case 456:
#line 5182 "Gmsh.y"
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

  case 457:
#line 5203 "Gmsh.y"
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

  case 458:
#line 5236 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 459:
#line 5240 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 460:
#line 5245 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 461:
#line 5249 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 462:
#line 5253 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 463:
#line 5257 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 464:
#line 5262 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 465:
#line 5267 "Gmsh.y"
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

  case 466:
#line 5277 "Gmsh.y"
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

  case 467:
#line 5287 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 468:
#line 5292 "Gmsh.y"
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

  case 469:
#line 5303 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 470:
#line 5312 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 471:
#line 5317 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 472:
#line 5322 "Gmsh.y"
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

  case 473:
#line 5349 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 474:
#line 5351 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 475:
#line 5356 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 476:
#line 5358 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 477:
#line 5363 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 478:
#line 5370 "Gmsh.y"
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

  case 479:
#line 5386 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 480:
#line 5388 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 481:
#line 5393 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 482:
#line 5402 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 483:
#line 5404 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 484:
#line 5409 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 485:
#line 5411 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 486:
#line 5416 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 487:
#line 5420 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 488:
#line 5424 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 489:
#line 5428 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 490:
#line 5432 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 491:
#line 5439 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 492:
#line 5443 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 493:
#line 5447 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 494:
#line 5451 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 495:
#line 5458 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 496:
#line 5463 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 497:
#line 5470 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 498:
#line 5475 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 499:
#line 5479 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 500:
#line 5484 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 501:
#line 5488 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 502:
#line 5496 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 503:
#line 5507 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 504:
#line 5511 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 505:
#line 5515 "Gmsh.y"
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

  case 506:
#line 5529 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 507:
#line 5537 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 508:
#line 5545 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 509:
#line 5552 "Gmsh.y"
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

  case 510:
#line 5562 "Gmsh.y"
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

  case 511:
#line 5585 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 512:
#line 5590 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 513:
#line 5596 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 514:
#line 5601 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 515:
#line 5607 "Gmsh.y"
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

  case 516:
#line 5618 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 517:
#line 5625 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 518:
#line 5630 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].l), (yyval.l));
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 519:
#line 5636 "Gmsh.y"
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

  case 520:
#line 5646 "Gmsh.y"
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

  case 521:
#line 5656 "Gmsh.y"
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

  case 522:
#line 5666 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 523:
#line 5678 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 524:
#line 5682 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 525:
#line 5687 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      if(!gmsh_yysymbols.count((yyvsp[(3) - (4)].c)))
	yymsg(0, "Unknown variable '%s'", (yyvsp[(3) - (4)].c));
      else{
        gmsh_yysymbol &s(gmsh_yysymbols[(yyvsp[(3) - (4)].c)]);
	for(unsigned int i = 0; i < s.value.size(); i++)
	  List_Add((yyval.l), &s.value[i]);
      }
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 526:
#line 5699 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 527:
#line 5703 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 528:
#line 5707 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 529:
#line 5711 "Gmsh.y"
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

  case 530:
#line 5729 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 531:
#line 5737 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 532:
#line 5745 "Gmsh.y"
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

  case 533:
#line 5774 "Gmsh.y"
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

  case 534:
#line 5784 "Gmsh.y"
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
      for(unsigned int i = 0; i < tmp.size(); i++){
        List_Add((yyval.l), &tmp[i]);
      }
    ;}
    break;

  case 535:
#line 5800 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 536:
#line 5811 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 537:
#line 5816 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 538:
#line 5820 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 539:
#line 5824 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 540:
#line 5836 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 541:
#line 5840 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 542:
#line 5852 "Gmsh.y"
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

  case 543:
#line 5869 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 544:
#line 5879 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 545:
#line 5883 "Gmsh.y"
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

  case 546:
#line 5898 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 547:
#line 5903 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 548:
#line 5910 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 549:
#line 5914 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 550:
#line 5919 "Gmsh.y"
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

  case 551:
#line 5933 "Gmsh.y"
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

  case 552:
#line 5949 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 553:
#line 5953 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 554:
#line 5957 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 555:
#line 5961 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 556:
#line 5965 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 557:
#line 5973 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 558:
#line 5979 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 559:
#line 5985 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 560:
#line 5991 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 561:
#line 6000 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 562:
#line 6004 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 563:
#line 6008 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 564:
#line 6016 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 565:
#line 6022 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 566:
#line 6028 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 567:
#line 6032 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 568:
#line 6040 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 569:
#line 6048 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 570:
#line 6055 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 571:
#line 6064 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 572:
#line 6068 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 573:
#line 6072 "Gmsh.y"
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

  case 574:
#line 6087 "Gmsh.y"
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

  case 575:
#line 6101 "Gmsh.y"
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

  case 576:
#line 6115 "Gmsh.y"
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

  case 577:
#line 6127 "Gmsh.y"
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

  case 578:
#line 6143 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 579:
#line 6152 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 580:
#line 6161 "Gmsh.y"
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

  case 581:
#line 6171 "Gmsh.y"
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

  case 582:
#line 6182 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 583:
#line 6190 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 584:
#line 6198 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 585:
#line 6202 "Gmsh.y"
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

  case 586:
#line 6221 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 6228 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 588:
#line 6234 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 589:
#line 6241 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 590:
#line 6248 "Gmsh.y"
    { init_options(); ;}
    break;

  case 591:
#line 6250 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 592:
#line 6258 "Gmsh.y"
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

  case 593:
#line 6282 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 594:
#line 6284 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 595:
#line 6290 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 596:
#line 6295 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 597:
#line 6297 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 598:
#line 6302 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 599:
#line 6307 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 600:
#line 6312 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 601:
#line 6314 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 602:
#line 6318 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 603:
#line 6330 "Gmsh.y"
    {
      (yyval.l) = List_Create(20, 20, sizeof(char *));
      if(!gmsh_yystringsymbols.count((yyvsp[(1) - (3)].c)))
	yymsg(0, "Unknown string variable '%s'", (yyvsp[(1) - (3)].c));
      else{
        std::vector<std::string> &s(gmsh_yystringsymbols[(yyvsp[(1) - (3)].c)]);
	for(unsigned int i = 0; i < s.size(); i++) {
          char * val_ = strsave((char*)s.at(i).c_str());
	  List_Add((yyval.l), &val_);
        }
      }
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 604:
#line 6344 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 605:
#line 6348 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 606:
#line 6355 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 607:
#line 6363 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 608:
#line 6371 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 609:
#line 6382 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 610:
#line 6384 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 611:
#line 6387 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14107 "Gmsh.tab.cpp"
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


#line 6390 "Gmsh.y"


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
  for(unsigned int i = 0; i < strlen(format); i++)
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
      for(unsigned int i = 0; i < s.value.size(); i++){
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
      for(unsigned int i = 0; i < it->second.size(); i++){
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
  for(unsigned int i = 0; i < v.size(); i++){
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
    for(unsigned int i = 0; i < tags.size(); i++){
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
    for(unsigned int i = 0; i < tags.size(); i++){
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

void getAllElementaryTags(int dim, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  std::vector<GEntity*> entities;
  GModel::current()->getEntities(entities, dim);
  for(unsigned int i = 0; i < entities.size(); i++){
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
  for(unsigned int i = 0; i < entities.size(); i++){
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
  for(unsigned int i = 0; i < entities.size(); i++){
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

  for(unsigned int i = 0; i < dimTags.size(); i++){
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

  for(unsigned int i = 0; i < dimTags.size(); i++){
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
    for(unsigned int i = 0; i < out_vector->size(); i++) {
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
    for(unsigned int i = 0; i < out_vector->size(); i++) {
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

