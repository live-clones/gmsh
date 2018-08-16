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
     tDistanceFunction = 335,
     tDefineConstant = 336,
     tUndefineConstant = 337,
     tDefineNumber = 338,
     tDefineStruct = 339,
     tNameStruct = 340,
     tDimNameSpace = 341,
     tAppend = 342,
     tDefineString = 343,
     tSetNumber = 344,
     tSetTag = 345,
     tSetString = 346,
     tPoint = 347,
     tCircle = 348,
     tEllipse = 349,
     tCurve = 350,
     tSphere = 351,
     tPolarSphere = 352,
     tSurface = 353,
     tSpline = 354,
     tVolume = 355,
     tBox = 356,
     tCylinder = 357,
     tCone = 358,
     tTorus = 359,
     tEllipsoid = 360,
     tQuadric = 361,
     tShapeFromFile = 362,
     tRectangle = 363,
     tDisk = 364,
     tWire = 365,
     tGeoEntity = 366,
     tCharacteristic = 367,
     tLength = 368,
     tParametric = 369,
     tElliptic = 370,
     tRefineMesh = 371,
     tAdaptMesh = 372,
     tRelocateMesh = 373,
     tReorientMesh = 374,
     tSetFactory = 375,
     tThruSections = 376,
     tWedge = 377,
     tFillet = 378,
     tChamfer = 379,
     tPlane = 380,
     tRuled = 381,
     tTransfinite = 382,
     tPhysical = 383,
     tCompound = 384,
     tPeriodic = 385,
     tParent = 386,
     tUsing = 387,
     tPlugin = 388,
     tDegenerated = 389,
     tRecursive = 390,
     tRotate = 391,
     tTranslate = 392,
     tSymmetry = 393,
     tDilate = 394,
     tExtrude = 395,
     tLevelset = 396,
     tAffine = 397,
     tBooleanUnion = 398,
     tBooleanIntersection = 399,
     tBooleanDifference = 400,
     tBooleanSection = 401,
     tBooleanFragments = 402,
     tThickSolid = 403,
     tRecombine = 404,
     tSmoother = 405,
     tSplit = 406,
     tDelete = 407,
     tCoherence = 408,
     tIntersect = 409,
     tMeshAlgorithm = 410,
     tReverseMesh = 411,
     tLayers = 412,
     tScaleLast = 413,
     tHole = 414,
     tAlias = 415,
     tAliasWithOptions = 416,
     tCopyOptions = 417,
     tQuadTriAddVerts = 418,
     tQuadTriNoNewVerts = 419,
     tRecombLaterals = 420,
     tTransfQuadTri = 421,
     tText2D = 422,
     tText3D = 423,
     tInterpolationScheme = 424,
     tTime = 425,
     tCombine = 426,
     tBSpline = 427,
     tBezier = 428,
     tNurbs = 429,
     tNurbsOrder = 430,
     tNurbsKnots = 431,
     tColor = 432,
     tColorTable = 433,
     tFor = 434,
     tIn = 435,
     tEndFor = 436,
     tIf = 437,
     tElseIf = 438,
     tElse = 439,
     tEndIf = 440,
     tExit = 441,
     tAbort = 442,
     tField = 443,
     tReturn = 444,
     tCall = 445,
     tSlide = 446,
     tMacro = 447,
     tShow = 448,
     tHide = 449,
     tGetValue = 450,
     tGetStringValue = 451,
     tGetEnv = 452,
     tGetString = 453,
     tGetNumber = 454,
     tUnique = 455,
     tHomology = 456,
     tCohomology = 457,
     tBetti = 458,
     tExists = 459,
     tFileExists = 460,
     tGetForced = 461,
     tGetForcedStr = 462,
     tGMSH_MAJOR_VERSION = 463,
     tGMSH_MINOR_VERSION = 464,
     tGMSH_PATCH_VERSION = 465,
     tGmshExecutableName = 466,
     tSetPartition = 467,
     tNameToString = 468,
     tStringToName = 469,
     tAFFECTDIVIDE = 470,
     tAFFECTTIMES = 471,
     tAFFECTMINUS = 472,
     tAFFECTPLUS = 473,
     tOR = 474,
     tAND = 475,
     tNOTEQUAL = 476,
     tEQUAL = 477,
     tGREATERGREATER = 478,
     tLESSLESS = 479,
     tGREATEROREQUAL = 480,
     tLESSOREQUAL = 481,
     UNARYPREC = 482,
     tMINUSMINUS = 483,
     tPLUSPLUS = 484
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
#define tDistanceFunction 335
#define tDefineConstant 336
#define tUndefineConstant 337
#define tDefineNumber 338
#define tDefineStruct 339
#define tNameStruct 340
#define tDimNameSpace 341
#define tAppend 342
#define tDefineString 343
#define tSetNumber 344
#define tSetTag 345
#define tSetString 346
#define tPoint 347
#define tCircle 348
#define tEllipse 349
#define tCurve 350
#define tSphere 351
#define tPolarSphere 352
#define tSurface 353
#define tSpline 354
#define tVolume 355
#define tBox 356
#define tCylinder 357
#define tCone 358
#define tTorus 359
#define tEllipsoid 360
#define tQuadric 361
#define tShapeFromFile 362
#define tRectangle 363
#define tDisk 364
#define tWire 365
#define tGeoEntity 366
#define tCharacteristic 367
#define tLength 368
#define tParametric 369
#define tElliptic 370
#define tRefineMesh 371
#define tAdaptMesh 372
#define tRelocateMesh 373
#define tReorientMesh 374
#define tSetFactory 375
#define tThruSections 376
#define tWedge 377
#define tFillet 378
#define tChamfer 379
#define tPlane 380
#define tRuled 381
#define tTransfinite 382
#define tPhysical 383
#define tCompound 384
#define tPeriodic 385
#define tParent 386
#define tUsing 387
#define tPlugin 388
#define tDegenerated 389
#define tRecursive 390
#define tRotate 391
#define tTranslate 392
#define tSymmetry 393
#define tDilate 394
#define tExtrude 395
#define tLevelset 396
#define tAffine 397
#define tBooleanUnion 398
#define tBooleanIntersection 399
#define tBooleanDifference 400
#define tBooleanSection 401
#define tBooleanFragments 402
#define tThickSolid 403
#define tRecombine 404
#define tSmoother 405
#define tSplit 406
#define tDelete 407
#define tCoherence 408
#define tIntersect 409
#define tMeshAlgorithm 410
#define tReverseMesh 411
#define tLayers 412
#define tScaleLast 413
#define tHole 414
#define tAlias 415
#define tAliasWithOptions 416
#define tCopyOptions 417
#define tQuadTriAddVerts 418
#define tQuadTriNoNewVerts 419
#define tRecombLaterals 420
#define tTransfQuadTri 421
#define tText2D 422
#define tText3D 423
#define tInterpolationScheme 424
#define tTime 425
#define tCombine 426
#define tBSpline 427
#define tBezier 428
#define tNurbs 429
#define tNurbsOrder 430
#define tNurbsKnots 431
#define tColor 432
#define tColorTable 433
#define tFor 434
#define tIn 435
#define tEndFor 436
#define tIf 437
#define tElseIf 438
#define tElse 439
#define tEndIf 440
#define tExit 441
#define tAbort 442
#define tField 443
#define tReturn 444
#define tCall 445
#define tSlide 446
#define tMacro 447
#define tShow 448
#define tHide 449
#define tGetValue 450
#define tGetStringValue 451
#define tGetEnv 452
#define tGetString 453
#define tGetNumber 454
#define tUnique 455
#define tHomology 456
#define tCohomology 457
#define tBetti 458
#define tExists 459
#define tFileExists 460
#define tGetForced 461
#define tGetForcedStr 462
#define tGMSH_MAJOR_VERSION 463
#define tGMSH_MINOR_VERSION 464
#define tGMSH_PATCH_VERSION 465
#define tGmshExecutableName 466
#define tSetPartition 467
#define tNameToString 468
#define tStringToName 469
#define tAFFECTDIVIDE 470
#define tAFFECTTIMES 471
#define tAFFECTMINUS 472
#define tAFFECTPLUS 473
#define tOR 474
#define tAND 475
#define tNOTEQUAL 476
#define tEQUAL 477
#define tGREATERGREATER 478
#define tLESSLESS 479
#define tGREATEROREQUAL 480
#define tLESSOREQUAL 481
#define UNARYPREC 482
#define tMINUSMINUS 483
#define tPLUSPLUS 484




/* Copy the first part of user declarations.  */
#line 1 "Gmsh.y"

// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

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
void getBoundingBox(int dim, int tag, List_T *out);
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
#line 738 "Gmsh.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 751 "Gmsh.tab.cpp"

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
#define YYLAST   16246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  252
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  609
/* YYNRULES -- Number of states.  */
#define YYNSTATES  2174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   484

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   237,     2,   249,     2,   234,   236,     2,
     242,   243,   232,   230,   251,   231,   248,   233,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     224,     2,   225,   219,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   244,     2,   245,   241,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   246,   235,   247,   250,     2,     2,     2,
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
     215,   216,   217,   218,   220,   221,   222,   223,   226,   227,
     228,   229,   238,   239,   240
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
    1504,  1507,  1510,  1527,  1539,  1546,  1555,  1564,  1575,  1577,
    1580,  1583,  1585,  1589,  1593,  1598,  1603,  1605,  1607,  1613,
    1625,  1639,  1640,  1648,  1649,  1663,  1664,  1680,  1681,  1688,
    1698,  1701,  1705,  1716,  1730,  1732,  1735,  1741,  1749,  1752,
    1755,  1759,  1762,  1766,  1769,  1773,  1783,  1790,  1792,  1794,
    1796,  1798,  1800,  1801,  1804,  1808,  1812,  1817,  1827,  1832,
    1847,  1848,  1852,  1853,  1855,  1856,  1859,  1860,  1863,  1864,
    1867,  1874,  1882,  1889,  1895,  1899,  1908,  1917,  1926,  1935,
    1944,  1950,  1955,  1962,  1974,  1986,  2005,  2024,  2037,  2050,
    2063,  2074,  2079,  2084,  2089,  2094,  2099,  2102,  2106,  2113,
    2115,  2117,  2119,  2122,  2128,  2136,  2147,  2149,  2153,  2156,
    2159,  2162,  2166,  2170,  2174,  2178,  2182,  2186,  2190,  2194,
    2198,  2202,  2206,  2210,  2214,  2218,  2222,  2226,  2230,  2234,
    2240,  2245,  2250,  2255,  2260,  2265,  2270,  2275,  2280,  2285,
    2290,  2297,  2302,  2307,  2312,  2317,  2322,  2327,  2332,  2337,
    2344,  2351,  2358,  2363,  2365,  2367,  2369,  2371,  2373,  2375,
    2377,  2379,  2381,  2383,  2385,  2386,  2393,  2395,  2400,  2407,
    2409,  2414,  2419,  2424,  2431,  2437,  2445,  2454,  2465,  2470,
    2475,  2482,  2487,  2491,  2494,  2500,  2506,  2510,  2516,  2523,
    2532,  2539,  2548,  2555,  2560,  2568,  2575,  2582,  2589,  2594,
    2601,  2606,  2607,  2610,  2611,  2614,  2615,  2623,  2625,  2629,
    2631,  2633,  2636,  2637,  2641,  2643,  2646,  2649,  2653,  2657,
    2669,  2679,  2687,  2695,  2697,  2701,  2703,  2705,  2708,  2712,
    2717,  2723,  2725,  2729,  2731,  2734,  2738,  2742,  2748,  2753,
    2758,  2761,  2766,  2769,  2773,  2777,  2794,  2800,  2802,  2804,
    2806,  2810,  2816,  2824,  2829,  2834,  2839,  2846,  2853,  2862,
    2871,  2876,  2891,  2896,  2901,  2903,  2905,  2909,  2913,  2923,
    2931,  2933,  2939,  2943,  2950,  2952,  2956,  2958,  2960,  2965,
    2970,  2974,  2980,  2987,  2996,  3003,  3009,  3015,  3021,  3027,
    3029,  3034,  3036,  3038,  3040,  3042,  3047,  3054,  3059,  3066,
    3072,  3080,  3085,  3090,  3095,  3104,  3109,  3114,  3119,  3124,
    3133,  3142,  3149,  3154,  3161,  3166,  3168,  3173,  3178,  3179,
    3186,  3191,  3194,  3199,  3204,  3206,  3208,  3212,  3214,  3216,
    3220,  3224,  3228,  3234,  3242,  3248,  3254,  3263,  3265,  3267
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     253,     0,    -1,   254,    -1,     1,     6,    -1,    -1,   254,
     255,    -1,   257,    -1,   258,    -1,   278,    -1,   120,   242,
     354,   243,     6,    -1,   296,    -1,   302,    -1,   306,    -1,
     307,    -1,   308,    -1,   309,    -1,   313,    -1,   322,    -1,
     323,    -1,   329,    -1,   330,    -1,   312,    -1,   311,    -1,
     310,    -1,   305,    -1,   332,    -1,   225,    -1,   226,    -1,
      44,   242,   354,   243,     6,    -1,    45,   242,   354,   243,
       6,    -1,    44,   242,   354,   243,   256,   354,     6,    -1,
      44,   242,   354,   251,   350,   243,     6,    -1,    45,   242,
     354,   251,   350,   243,     6,    -1,    44,   242,   354,   251,
     350,   243,   256,   354,     6,    -1,   364,   354,   246,   259,
     247,     6,    -1,   160,     4,   244,   333,   245,     6,    -1,
     161,     4,   244,   333,   245,     6,    -1,   162,     4,   244,
     333,   251,   333,   245,     6,    -1,    -1,   259,   262,    -1,
     259,   266,    -1,   259,   269,    -1,   259,   271,    -1,   259,
     272,    -1,   333,    -1,   260,   251,   333,    -1,   333,    -1,
     261,   251,   333,    -1,    -1,    -1,     4,   263,   242,   260,
     243,   264,   246,   261,   247,     6,    -1,   354,    -1,   265,
     251,   354,    -1,    -1,   167,   242,   333,   251,   333,   251,
     333,   243,   267,   246,   265,   247,     6,    -1,   354,    -1,
     268,   251,   354,    -1,    -1,   168,   242,   333,   251,   333,
     251,   333,   251,   333,   243,   270,   246,   268,   247,     6,
      -1,   169,   246,   346,   247,   246,   346,   247,     6,    -1,
     169,   246,   346,   247,   246,   346,   247,   246,   346,   247,
     246,   346,   247,     6,    -1,    -1,   170,   273,   246,   261,
     247,     6,    -1,     7,    -1,   218,    -1,   217,    -1,   216,
      -1,   215,    -1,   240,    -1,   239,    -1,   242,    -1,   244,
      -1,   243,    -1,   245,    -1,    81,   244,   280,   245,     6,
      -1,    82,   244,   284,   245,     6,    -1,   338,     6,    -1,
      89,   276,   355,   251,   333,   277,     6,    -1,    91,   276,
     364,   251,   355,   277,     6,    -1,   364,   274,   347,     6,
      -1,   364,   275,     6,    -1,   364,   276,   277,   274,   347,
       6,    -1,   364,   276,   246,   350,   247,   277,   274,   347,
       6,    -1,   364,   244,   333,   245,   274,   333,     6,    -1,
     364,   244,   333,   245,   275,     6,    -1,   364,   242,   333,
     243,   274,   333,     6,    -1,   364,   242,   333,   243,   275,
       6,    -1,   364,     7,   355,     6,    -1,   364,   276,   277,
       7,    46,   276,   277,     6,    -1,   364,   276,   277,     7,
      46,   276,   359,   277,     6,    -1,   364,   276,   277,   218,
      46,   276,   359,   277,     6,    -1,   364,   248,     4,     7,
     355,     6,    -1,   364,   244,   333,   245,   248,     4,     7,
     355,     6,    -1,   364,   248,     4,   274,   333,     6,    -1,
     364,   244,   333,   245,   248,     4,   274,   333,     6,    -1,
     364,   248,     4,   275,     6,    -1,   364,   244,   333,   245,
     248,     4,   275,     6,    -1,   364,   248,   177,   248,     4,
       7,   351,     6,    -1,   364,   244,   333,   245,   248,   177,
     248,     4,     7,   351,     6,    -1,   364,   248,   178,     7,
     352,     6,    -1,   364,   244,   333,   245,   248,   178,     7,
     352,     6,    -1,   364,   188,     7,   347,     6,    -1,   188,
     244,   333,   245,     7,     4,     6,    -1,   188,   244,   333,
     245,     7,   101,     6,    -1,   188,   244,   333,   245,     7,
     102,     6,    -1,   188,   244,   333,   245,   248,     4,     7,
     333,     6,    -1,   188,   244,   333,   245,   248,     4,     7,
     355,     6,    -1,   188,   244,   333,   245,   248,     4,     7,
     246,   350,   247,     6,    -1,   188,   244,   333,   245,   248,
       4,     6,    -1,   133,   242,     4,   243,   248,     4,     7,
     333,     6,    -1,   133,   242,     4,   243,   248,     4,     7,
     355,     6,    -1,    -1,   251,    -1,    -1,   280,   279,   364,
      -1,   280,   279,   364,     7,   333,    -1,    -1,   280,   279,
     364,     7,   246,   347,   281,   286,   247,    -1,    -1,   280,
     279,   364,   276,   277,     7,   246,   347,   282,   286,   247,
      -1,   280,   279,   364,     7,   355,    -1,    -1,   280,   279,
     364,     7,   246,   355,   283,   290,   247,    -1,    -1,   284,
     279,   354,    -1,   333,     7,   355,    -1,   285,   251,   333,
       7,   355,    -1,   349,     7,   364,   242,   243,    -1,    -1,
     251,   288,    -1,    -1,   288,    -1,   289,    -1,   288,   251,
     289,    -1,     4,   347,    -1,     4,    -1,     4,   246,   285,
     247,    -1,     4,   355,    -1,     4,   358,    -1,    -1,   251,
     291,    -1,   292,    -1,   291,   251,   292,    -1,     4,   333,
      -1,     4,   355,    -1,   192,   355,    -1,     4,   360,    -1,
       4,   358,    -1,   333,    -1,   355,    -1,   355,   251,   333,
      -1,    -1,   180,    96,   246,   333,   247,    -1,   132,    92,
     246,   350,   247,    -1,   132,   111,   246,   350,   247,    -1,
      -1,   125,   344,    -1,    92,   242,   333,   243,     7,   344,
       6,    -1,    95,   242,   333,   243,     7,   347,     6,    -1,
      99,   242,   333,   243,     7,   347,     6,    -1,    93,   242,
     333,   243,     7,   347,   295,     6,    -1,    94,   242,   333,
     243,     7,   347,   295,     6,    -1,   172,   242,   333,   243,
       7,   347,     6,    -1,   173,   242,   333,   243,     7,   347,
       6,    -1,   174,   242,   333,   243,     7,   347,   176,   347,
     175,   333,     6,    -1,   110,   242,   333,   243,     7,   347,
       6,    -1,    95,     4,   242,   333,   243,     7,   347,     6,
      -1,   125,    98,   242,   333,   243,     7,   347,     6,    -1,
      98,   242,   333,   243,     7,   347,   294,     6,    -1,   126,
      98,   242,   333,   243,     7,   347,   294,     6,    -1,    13,
      14,     6,    -1,    14,    98,   333,     6,    -1,   114,    98,
     242,   333,   243,     7,     5,     5,     5,     6,    -1,    96,
     242,   333,   243,     7,   347,     6,    -1,    97,   242,   333,
     243,     7,   347,     6,    -1,   101,   242,   333,   243,     7,
     347,     6,    -1,   104,   242,   333,   243,     7,   347,     6,
      -1,   108,   242,   333,   243,     7,   347,     6,    -1,   109,
     242,   333,   243,     7,   347,     6,    -1,   102,   242,   333,
     243,     7,   347,     6,    -1,   103,   242,   333,   243,     7,
     347,     6,    -1,   122,   242,   333,   243,     7,   347,     6,
      -1,   148,   242,   333,   243,     7,   347,     6,    -1,    98,
       4,   242,   333,   243,     7,   347,     6,    -1,   100,   242,
     333,   243,     7,   347,     6,    -1,   121,   242,   333,   243,
       7,   347,     6,    -1,   126,   121,   242,   333,   243,     7,
     347,     6,    -1,   129,   299,   242,   333,   243,     7,   347,
       6,    -1,   129,   299,   242,   333,   243,     7,   347,     4,
     246,   346,   247,     6,    -1,    -1,   128,   298,   297,   242,
     293,   243,   274,   347,     6,    -1,    92,    -1,    95,    -1,
      98,    -1,   100,    -1,   111,   246,   333,   247,    -1,    95,
      -1,    98,    -1,   100,    -1,   111,   246,   333,   247,    -1,
      95,    -1,    98,    -1,   111,   246,   333,   247,    -1,    92,
      -1,    95,    -1,    98,    -1,   111,   246,   333,   247,    -1,
     137,   344,   246,   303,   247,    -1,   136,   246,   344,   251,
     344,   251,   333,   247,   246,   303,   247,    -1,   138,   344,
     246,   303,   247,    -1,   139,   246,   344,   251,   333,   247,
     246,   303,   247,    -1,   139,   246,   344,   251,   344,   247,
     246,   303,   247,    -1,     4,   246,   303,   247,    -1,   154,
      95,   246,   350,   247,    98,   246,   333,   247,    -1,   151,
      95,   242,   333,   243,   246,   350,   247,     6,    -1,   304,
      -1,   302,    -1,    -1,   304,   296,    -1,   304,   298,   246,
     350,   247,     6,    -1,   304,   128,   298,   246,   350,   247,
       6,    -1,   304,   131,   298,   246,   350,   247,     6,    -1,
     304,   298,   246,     8,   247,     6,    -1,   304,   128,   298,
     246,     8,   247,     6,    -1,   141,   125,   242,   333,   243,
       7,   347,     6,    -1,   141,    92,   242,   333,   243,     7,
     246,   346,   247,     6,    -1,   141,   125,   242,   333,   243,
       7,   246,   344,   251,   344,   251,   350,   247,     6,    -1,
     141,   125,   242,   333,   243,     7,   246,   344,   251,   344,
     251,   344,   251,   350,   247,     6,    -1,   141,    96,   242,
     333,   243,     7,   246,   344,   251,   350,   247,     6,    -1,
     141,   102,   242,   333,   243,     7,   246,   344,   251,   344,
     251,   350,   247,     6,    -1,   141,   103,   242,   333,   243,
       7,   246,   344,   251,   344,   251,   350,   247,     6,    -1,
     141,   105,   242,   333,   243,     7,   246,   344,   251,   344,
     251,   350,   247,     6,    -1,   141,   106,   242,   333,   243,
       7,   246,   344,   251,   344,   251,   350,   247,     6,    -1,
     141,     4,   242,   333,   243,     7,   347,     6,    -1,   141,
       4,   242,   333,   243,     7,     5,     6,    -1,   141,     4,
     246,   333,   247,     6,    -1,   152,   246,   304,   247,    -1,
     135,   152,   246,   304,   247,    -1,   152,   188,   244,   333,
     245,     6,    -1,   152,     4,   244,   333,   245,     6,    -1,
     152,   364,     6,    -1,   152,     4,     4,     6,    -1,   152,
      84,     6,    -1,   177,   351,   246,   304,   247,    -1,   135,
     177,   351,   246,   304,   247,    -1,   212,   333,   246,   304,
     247,    -1,   193,   246,     8,   247,    -1,   193,     5,     6,
      -1,   194,   246,     8,   247,    -1,   194,     5,     6,    -1,
     193,   246,   304,   247,    -1,   135,   193,   246,   304,   247,
      -1,   194,   246,   304,   247,    -1,   135,   194,   246,   304,
     247,    -1,   364,   355,     6,    -1,    73,   242,   361,   243,
       6,    -1,   364,   364,   244,   333,   245,   354,     6,    -1,
     364,   364,   364,   244,   333,   245,     6,    -1,   364,   333,
       6,    -1,   133,   242,     4,   243,   248,     4,     6,    -1,
     171,     4,     6,    -1,   186,     6,    -1,   187,     6,    -1,
      70,     6,    -1,    71,     6,    -1,    64,     6,    -1,    64,
     246,   333,   251,   333,   251,   333,   251,   333,   251,   333,
     251,   333,   247,     6,    -1,    65,     6,    -1,    66,     6,
      -1,    78,     6,    -1,    79,     6,    -1,   116,     6,    -1,
     117,   246,   350,   247,   246,   350,   247,   246,   346,   247,
     246,   333,   251,   333,   247,     6,    -1,   191,   242,   246,
     350,   247,   251,   355,   251,   355,   243,     6,    -1,   179,
     242,   333,     8,   333,   243,    -1,   179,   242,   333,     8,
     333,     8,   333,   243,    -1,   179,     4,   180,   246,   333,
       8,   333,   247,    -1,   179,     4,   180,   246,   333,     8,
     333,     8,   333,   247,    -1,   181,    -1,   192,     4,    -1,
     192,   355,    -1,   189,    -1,   190,   364,     6,    -1,   190,
     355,     6,    -1,   182,   242,   333,   243,    -1,   183,   242,
     333,   243,    -1,   184,    -1,   185,    -1,   140,   344,   246,
     304,   247,    -1,   140,   246,   344,   251,   344,   251,   333,
     247,   246,   304,   247,    -1,   140,   246,   344,   251,   344,
     251,   344,   251,   333,   247,   246,   304,   247,    -1,    -1,
     140,   344,   246,   304,   314,   318,   247,    -1,    -1,   140,
     246,   344,   251,   344,   251,   333,   247,   246,   304,   315,
     318,   247,    -1,    -1,   140,   246,   344,   251,   344,   251,
     344,   251,   333,   247,   246,   304,   316,   318,   247,    -1,
      -1,   140,   246,   304,   317,   318,   247,    -1,   140,   246,
     304,   247,   132,   110,   246,   333,   247,    -1,   121,   347,
      -1,   126,   121,   347,    -1,   123,   246,   350,   247,   246,
     350,   247,   246,   350,   247,    -1,   124,   246,   350,   247,
     246,   350,   247,   246,   350,   247,   246,   350,   247,    -1,
     319,    -1,   318,   319,    -1,   157,   246,   333,   247,     6,
      -1,   157,   246,   347,   251,   347,   247,     6,    -1,   158,
       6,    -1,   149,     6,    -1,   149,   333,     6,    -1,   163,
       6,    -1,   163,   165,     6,    -1,   164,     6,    -1,   164,
     165,     6,    -1,   159,   242,   333,   243,     7,   347,   132,
     333,     6,    -1,   132,     4,   244,   333,   245,     6,    -1,
     143,    -1,   144,    -1,   145,    -1,   146,    -1,   147,    -1,
      -1,   152,     6,    -1,   135,   152,     6,    -1,   152,   333,
       6,    -1,   135,   152,   333,     6,    -1,   320,   246,   304,
     321,   247,   246,   304,   321,   247,    -1,   107,   242,   354,
     243,    -1,   320,   242,   333,   243,     7,   246,   304,   321,
     247,   246,   304,   321,   247,     6,    -1,    -1,   132,     4,
     333,    -1,    -1,     4,    -1,    -1,     7,   347,    -1,    -1,
       7,   333,    -1,    -1,   142,   347,    -1,   112,   113,   348,
       7,   333,     6,    -1,   127,    95,   348,     7,   333,   324,
       6,    -1,   127,    98,   348,   326,   325,     6,    -1,   127,
     100,   348,   326,     6,    -1,   166,   348,     6,    -1,    90,
      92,   242,   333,   251,   333,   243,     6,    -1,    90,    95,
     242,   333,   251,   333,   243,     6,    -1,    90,    98,   242,
     333,   251,   333,   243,     6,    -1,    90,   100,   242,   333,
     251,   333,   243,     6,    -1,   155,    98,   246,   350,   247,
       7,   333,     6,    -1,   149,    98,   348,   327,     6,    -1,
     149,   100,   348,     6,    -1,   150,    98,   348,     7,   333,
       6,    -1,   130,    95,   246,   350,   247,     7,   246,   350,
     247,   328,     6,    -1,   130,    98,   246,   350,   247,     7,
     246,   350,   247,   328,     6,    -1,   130,    95,   246,   350,
     247,     7,   246,   350,   247,   136,   246,   344,   251,   344,
     251,   333,   247,     6,    -1,   130,    98,   246,   350,   247,
       7,   246,   350,   247,   136,   246,   344,   251,   344,   251,
     333,   247,     6,    -1,   130,    95,   246,   350,   247,     7,
     246,   350,   247,   137,   344,     6,    -1,   130,    98,   246,
     350,   247,     7,   246,   350,   247,   137,   344,     6,    -1,
     130,    98,   333,   246,   350,   247,     7,   333,   246,   350,
     247,     6,    -1,   298,   246,   350,   247,   180,   298,   246,
     333,   247,     6,    -1,   156,   300,   348,     6,    -1,   118,
     301,   348,     6,    -1,   119,   100,   347,     6,    -1,   134,
      95,   347,     6,    -1,   129,   299,   347,     6,    -1,   153,
       6,    -1,   153,     4,     6,    -1,   153,    92,   246,   350,
     247,     6,    -1,   201,    -1,   202,    -1,   203,    -1,   331,
       6,    -1,   331,   246,   347,   247,     6,    -1,   331,   246,
     347,   251,   347,   247,     6,    -1,   331,   242,   347,   243,
     246,   347,   251,   347,   247,     6,    -1,   334,    -1,   242,
     333,   243,    -1,   231,   333,    -1,   230,   333,    -1,   237,
     333,    -1,   333,   231,   333,    -1,   333,   230,   333,    -1,
     333,   232,   333,    -1,   333,   233,   333,    -1,   333,   235,
     333,    -1,   333,   236,   333,    -1,   333,   234,   333,    -1,
     333,   241,   333,    -1,   333,   224,   333,    -1,   333,   225,
     333,    -1,   333,   229,   333,    -1,   333,   228,   333,    -1,
     333,   223,   333,    -1,   333,   222,   333,    -1,   333,   221,
     333,    -1,   333,   220,   333,    -1,   333,   226,   333,    -1,
     333,   227,   333,    -1,   333,   219,   333,     8,   333,    -1,
      16,   276,   333,   277,    -1,    17,   276,   333,   277,    -1,
      18,   276,   333,   277,    -1,    19,   276,   333,   277,    -1,
      20,   276,   333,   277,    -1,    21,   276,   333,   277,    -1,
      22,   276,   333,   277,    -1,    23,   276,   333,   277,    -1,
      24,   276,   333,   277,    -1,    26,   276,   333,   277,    -1,
      27,   276,   333,   251,   333,   277,    -1,    28,   276,   333,
     277,    -1,    29,   276,   333,   277,    -1,    30,   276,   333,
     277,    -1,    31,   276,   333,   277,    -1,    32,   276,   333,
     277,    -1,    33,   276,   333,   277,    -1,    34,   276,   333,
     277,    -1,    35,   276,   333,   277,    -1,    36,   276,   333,
     251,   333,   277,    -1,    37,   276,   333,   251,   333,   277,
      -1,    38,   276,   333,   251,   333,   277,    -1,    25,   276,
     333,   277,    -1,     3,    -1,    10,    -1,    15,    -1,    11,
      -1,    12,    -1,   208,    -1,   209,    -1,   210,    -1,    75,
      -1,    76,    -1,    77,    -1,    -1,    83,   276,   333,   335,
     286,   277,    -1,   338,    -1,   199,   276,   354,   277,    -1,
     199,   276,   354,   251,   333,   277,    -1,   340,    -1,   364,
     244,   333,   245,    -1,   364,   242,   333,   243,    -1,   204,
     242,   340,   243,    -1,   204,   242,   340,   248,   341,   243,
      -1,   206,   242,   340,   336,   243,    -1,   206,   242,   340,
     248,   341,   336,   243,    -1,   206,   242,   340,   276,   333,
     277,   336,   243,    -1,   206,   242,   340,   248,   341,   276,
     333,   277,   336,   243,    -1,   205,   242,   355,   243,    -1,
     249,   364,   276,   277,    -1,   249,   340,   248,   341,   276,
     277,    -1,    86,   276,   364,   277,    -1,    86,   276,   277,
      -1,   364,   275,    -1,   364,   244,   333,   245,   275,    -1,
     364,   242,   333,   243,   275,    -1,   364,   248,   341,    -1,
     364,     9,   364,   248,   341,    -1,   364,   248,   341,   242,
     333,   243,    -1,   364,     9,   364,   248,   341,   242,   333,
     243,    -1,   364,   248,   341,   244,   333,   245,    -1,   364,
       9,   364,   248,   341,   244,   333,   245,    -1,   364,   244,
     333,   245,   248,     4,    -1,   364,   248,     4,   275,    -1,
     364,   244,   333,   245,   248,     4,   275,    -1,   195,   242,
     354,   251,   333,   243,    -1,    56,   242,   347,   251,   347,
     243,    -1,    57,   276,   354,   251,   354,   277,    -1,    55,
     276,   354,   277,    -1,    58,   276,   354,   251,   354,   277,
      -1,    63,   242,   361,   243,    -1,    -1,   251,   333,    -1,
      -1,   251,   354,    -1,    -1,    84,   340,   343,   339,   244,
     287,   245,    -1,   364,    -1,   364,     9,   364,    -1,     4,
      -1,    87,    -1,    87,   333,    -1,    -1,   242,   342,   243,
      -1,   345,    -1,   231,   344,    -1,   230,   344,    -1,   344,
     231,   344,    -1,   344,   230,   344,    -1,   246,   333,   251,
     333,   251,   333,   251,   333,   251,   333,   247,    -1,   246,
     333,   251,   333,   251,   333,   251,   333,   247,    -1,   246,
     333,   251,   333,   251,   333,   247,    -1,   242,   333,   251,
     333,   251,   333,   243,    -1,   347,    -1,   346,   251,   347,
      -1,   333,    -1,   349,    -1,   246,   247,    -1,   246,   350,
     247,    -1,   231,   246,   350,   247,    -1,   333,   232,   246,
     350,   247,    -1,   347,    -1,   246,     8,   247,    -1,     5,
      -1,   231,   349,    -1,   333,   232,   349,    -1,   333,     8,
     333,    -1,   333,     8,   333,     8,   333,    -1,    92,   246,
     333,   247,    -1,    92,   246,     8,   247,    -1,    92,     5,
      -1,   299,   246,     8,   247,    -1,   299,     5,    -1,   128,
     298,   348,    -1,   131,   298,   347,    -1,   298,   180,    64,
     246,   333,   251,   333,   251,   333,   251,   333,   251,   333,
     251,   333,   247,    -1,    64,   298,   246,   333,   247,    -1,
     302,    -1,   313,    -1,   322,    -1,   364,   276,   277,    -1,
     364,   248,   341,   276,   277,    -1,   364,     9,   364,   248,
     341,   276,   277,    -1,    39,   244,   364,   245,    -1,    39,
     244,   349,   245,    -1,    39,   242,   349,   243,    -1,    39,
     276,   246,   350,   247,   277,    -1,   364,   276,   246,   350,
     247,   277,    -1,    40,   276,   333,   251,   333,   251,   333,
     277,    -1,    41,   276,   333,   251,   333,   251,   333,   277,
      -1,    42,   276,   354,   277,    -1,    43,   276,   333,   251,
     333,   251,   333,   251,   333,   251,   333,   251,   333,   277,
      -1,   200,   276,   349,   277,    -1,    32,   276,   349,   277,
      -1,   333,    -1,   349,    -1,   350,   251,   333,    -1,   350,
     251,   349,    -1,   246,   333,   251,   333,   251,   333,   251,
     333,   247,    -1,   246,   333,   251,   333,   251,   333,   247,
      -1,   364,    -1,     4,   248,   177,   248,     4,    -1,   246,
     353,   247,    -1,   364,   244,   333,   245,   248,   178,    -1,
     351,    -1,   353,   251,   351,    -1,   355,    -1,   364,    -1,
     364,   244,   333,   245,    -1,   364,   242,   333,   243,    -1,
     364,   248,   341,    -1,   364,     9,   364,   248,   341,    -1,
     364,   248,   341,   242,   333,   243,    -1,   364,     9,   364,
     248,   341,   242,   333,   243,    -1,   364,   244,   333,   245,
     248,     4,    -1,   128,    92,   246,   333,   247,    -1,   128,
      95,   246,   333,   247,    -1,   128,    98,   246,   333,   247,
      -1,   128,   100,   246,   333,   247,    -1,     5,    -1,   213,
     244,   364,   245,    -1,    67,    -1,   211,    -1,    72,    -1,
      74,    -1,   197,   242,   354,   243,    -1,   196,   242,   354,
     251,   354,   243,    -1,   198,   276,   354,   277,    -1,   198,
     276,   354,   251,   354,   277,    -1,   207,   242,   340,   337,
     243,    -1,   207,   242,   340,   248,   341,   337,   243,    -1,
      48,   276,   361,   277,    -1,    49,   242,   354,   243,    -1,
      50,   242,   354,   243,    -1,    51,   242,   354,   251,   354,
     251,   354,   243,    -1,    46,   276,   361,   277,    -1,    60,
     276,   354,   277,    -1,    61,   276,   354,   277,    -1,    62,
     276,   354,   277,    -1,    59,   276,   333,   251,   354,   251,
     354,   277,    -1,    54,   276,   354,   251,   333,   251,   333,
     277,    -1,    54,   276,   354,   251,   333,   277,    -1,    47,
     276,   354,   277,    -1,    47,   276,   354,   251,   350,   277,
      -1,    68,   276,   354,   277,    -1,    69,    -1,    53,   276,
     354,   277,    -1,    52,   276,   354,   277,    -1,    -1,    88,
     276,   355,   356,   290,   277,    -1,    85,   276,   357,   277,
      -1,   249,   333,    -1,   364,     9,   249,   333,    -1,    46,
     276,   360,   277,    -1,   361,    -1,   360,    -1,   246,   361,
     247,    -1,   354,    -1,   362,    -1,   361,   251,   354,    -1,
     361,   251,   362,    -1,   364,   242,   243,    -1,   364,   248,
     341,   242,   243,    -1,   364,     9,   364,   248,   341,   242,
     243,    -1,     4,   250,   246,   333,   247,    -1,   363,   250,
     246,   333,   247,    -1,   214,   244,   354,   245,   250,   246,
     333,   247,    -1,     4,    -1,   363,    -1,   214,   244,   354,
     245,    -1
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
    1067,  1090,  1108,  1116,  1123,  1130,  1152,  1175,  1213,  1234,
    1246,  1260,  1260,  1262,  1264,  1273,  1283,  1282,  1303,  1302,
    1320,  1330,  1329,  1343,  1345,  1353,  1359,  1364,  1390,  1392,
    1395,  1397,  1401,  1402,  1406,  1418,  1431,  1446,  1455,  1468,
    1470,  1474,  1475,  1480,  1488,  1497,  1505,  1519,  1537,  1541,
    1548,  1557,  1560,  1566,  1570,  1582,  1585,  1592,  1615,  1631,
    1647,  1684,  1724,  1740,  1756,  1788,  1804,  1821,  1837,  1887,
    1905,  1911,  1917,  1924,  1955,  1970,  1992,  2015,  2038,  2061,
    2085,  2109,  2133,  2159,  2176,  2192,  2210,  2228,  2235,  2244,
    2243,  2273,  2275,  2277,  2279,  2281,  2289,  2291,  2293,  2295,
    2303,  2305,  2307,  2315,  2317,  2319,  2321,  2331,  2347,  2363,
    2379,  2395,  2411,  2448,  2470,  2494,  2495,  2500,  2503,  2507,
    2523,  2541,  2559,  2577,  2602,  2621,  2642,  2657,  2673,  2691,
    2742,  2763,  2785,  2808,  2913,  2929,  2964,  2986,  3008,  3014,
    3029,  3057,  3069,  3078,  3085,  3097,  3116,  3120,  3125,  3129,
    3134,  3141,  3148,  3155,  3167,  3240,  3258,  3275,  3290,  3323,
    3335,  3359,  3363,  3368,  3375,  3380,  3390,  3395,  3401,  3409,
    3413,  3417,  3426,  3490,  3506,  3523,  3540,  3562,  3584,  3619,
    3627,  3635,  3641,  3648,  3655,  3675,  3701,  3713,  3724,  3742,
    3760,  3779,  3778,  3803,  3802,  3829,  3828,  3853,  3852,  3875,
    3891,  3908,  3925,  3948,  3976,  3979,  3985,  3997,  4017,  4021,
    4025,  4029,  4033,  4037,  4041,  4045,  4054,  4067,  4068,  4069,
    4070,  4071,  4075,  4076,  4077,  4078,  4079,  4082,  4106,  4125,
    4148,  4151,  4167,  4170,  4187,  4190,  4196,  4199,  4206,  4209,
    4216,  4238,  4279,  4323,  4362,  4387,  4399,  4411,  4423,  4435,
    4444,  4474,  4500,  4526,  4558,  4585,  4611,  4637,  4663,  4689,
    4711,  4722,  4770,  4824,  4839,  4851,  4862,  4869,  4884,  4898,
    4899,  4900,  4904,  4910,  4922,  4940,  4968,  4969,  4970,  4971,
    4972,  4973,  4974,  4975,  4976,  4983,  4984,  4985,  4986,  4987,
    4988,  4989,  4990,  4991,  4992,  4993,  4994,  4995,  4996,  4997,
    4998,  4999,  5000,  5001,  5002,  5003,  5004,  5005,  5006,  5007,
    5008,  5009,  5010,  5011,  5012,  5013,  5014,  5015,  5016,  5017,
    5018,  5019,  5020,  5029,  5030,  5031,  5032,  5033,  5034,  5035,
    5036,  5037,  5038,  5039,  5044,  5043,  5051,  5053,  5058,  5063,
    5067,  5072,  5077,  5081,  5085,  5089,  5093,  5097,  5101,  5107,
    5123,  5128,  5134,  5140,  5159,  5180,  5213,  5217,  5222,  5226,
    5230,  5234,  5239,  5244,  5254,  5264,  5269,  5280,  5289,  5294,
    5299,  5327,  5328,  5334,  5335,  5341,  5340,  5363,  5365,  5370,
    5379,  5381,  5387,  5388,  5393,  5397,  5401,  5405,  5409,  5416,
    5420,  5424,  5428,  5435,  5440,  5447,  5452,  5456,  5461,  5465,
    5473,  5484,  5488,  5492,  5506,  5514,  5522,  5529,  5539,  5562,
    5567,  5573,  5578,  5584,  5595,  5601,  5607,  5612,  5622,  5632,
    5642,  5654,  5658,  5663,  5675,  5679,  5683,  5687,  5705,  5713,
    5721,  5750,  5760,  5776,  5787,  5792,  5796,  5800,  5812,  5816,
    5828,  5845,  5855,  5859,  5874,  5879,  5886,  5890,  5895,  5909,
    5925,  5929,  5933,  5937,  5941,  5949,  5955,  5961,  5967,  5976,
    5980,  5984,  5992,  5998,  6004,  6008,  6016,  6024,  6031,  6040,
    6044,  6048,  6063,  6077,  6091,  6103,  6119,  6128,  6137,  6147,
    6158,  6166,  6174,  6178,  6197,  6204,  6210,  6217,  6225,  6224,
    6234,  6258,  6260,  6266,  6271,  6273,  6278,  6283,  6288,  6290,
    6294,  6306,  6320,  6324,  6331,  6339,  6347,  6358,  6360,  6363
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
  "tRecursive", "tRotate", "tTranslate", "tSymmetry", "tDilate",
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
  "CircleOptions", "Shape", "@9", "GeoEntity", "GeoEntity123",
  "GeoEntity12", "GeoEntity02", "Transform", "MultipleShape",
  "ListOfShapes", "LevelSet", "Delete", "Colorify", "SetPartition",
  "Visibility", "Command", "Slide", "Loop", "Extrude", "@10", "@11", "@12",
  "@13", "ExtrudeParameters", "ExtrudeParameter", "BooleanOperator",
  "BooleanOption", "Boolean", "BooleanShape", "TransfiniteType",
  "TransfiniteArrangement", "TransfiniteCorners", "RecombineAngle",
  "PeriodicTransform", "Constraints", "Coherence", "HomologyCommand",
  "Homology", "FExpr", "FExpr_Single", "@14", "GetForced_Default",
  "GetForcedStr_Default", "DefineStruct", "@15", "Struct_FullName",
  "tSTRING_Member", "Append", "AppendOrNot", "VExpr", "VExpr_Single",
  "RecursiveListOfListOfDouble", "ListOfDouble", "ListOfDoubleOrAll",
  "FExpr_Multi", "RecursiveListOfDouble", "ColorExpr", "ListOfColor",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,    63,
     474,   475,   476,   477,    60,    62,   478,   479,   480,   481,
      43,    45,    42,    47,    37,   124,    38,    33,   482,   483,
     484,    94,    40,    41,    91,    93,   123,   125,    46,    35,
     126,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   252,   253,   253,   254,   254,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   256,   256,   257,   257,
     257,   257,   257,   257,   258,   258,   258,   258,   259,   259,
     259,   259,   259,   259,   260,   260,   261,   261,   263,   264,
     262,   265,   265,   267,   266,   268,   268,   270,   269,   271,
     271,   273,   272,   274,   274,   274,   274,   274,   275,   275,
     276,   276,   277,   277,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   279,   279,   280,   280,   280,   281,   280,   282,   280,
     280,   283,   280,   284,   284,   285,   285,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   289,   289,   289,   290,
     290,   291,   291,   292,   292,   292,   292,   292,   293,   293,
     293,   294,   294,   294,   294,   295,   295,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   297,
     296,   298,   298,   298,   298,   298,   299,   299,   299,   299,
     300,   300,   300,   301,   301,   301,   301,   302,   302,   302,
     302,   302,   302,   302,   302,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   307,   307,   308,   309,   309,   309,   309,
     309,   309,   309,   309,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   313,   313,
     313,   314,   313,   315,   313,   316,   313,   317,   313,   313,
     313,   313,   313,   313,   318,   318,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   320,   320,   320,
     320,   320,   321,   321,   321,   321,   321,   322,   322,   323,
     324,   324,   325,   325,   326,   326,   327,   327,   328,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   330,   330,   330,   331,
     331,   331,   332,   332,   332,   332,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   335,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   336,   336,   337,   337,   339,   338,   340,   340,   341,
     342,   342,   343,   343,   344,   344,   344,   344,   344,   345,
     345,   345,   345,   346,   346,   347,   347,   347,   347,   347,
     347,   348,   348,   348,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   350,   350,   350,   350,   351,   351,
     351,   351,   352,   352,   353,   353,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   356,   355,
     355,   357,   357,   358,   359,   359,   360,   361,   361,   361,
     361,   362,   362,   362,   363,   363,   363,   364,   364,   364
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
       2,     4,     2,     3,     3,    16,     5,     1,     1,     1,
       3,     5,     7,     4,     4,     4,     6,     6,     8,     8,
       4,    14,     4,     4,     1,     1,     3,     3,     9,     7,
       1,     5,     3,     6,     1,     3,     1,     1,     4,     4,
       3,     5,     6,     8,     6,     5,     5,     5,     5,     1,
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
       0,     0,     0,     2,     3,     1,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,     0,     0,   192,     0,
       0,   193,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
     318,   319,   320,   321,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   278,     0,     0,   286,   287,     0,     0,
       0,   281,     0,     0,     0,     0,     0,   369,   370,   371,
       0,     0,     5,     6,     7,     8,    10,     0,    11,    24,
      12,    13,    14,    15,    23,    22,    21,    16,     0,    17,
      18,    19,    20,     0,    25,     0,   608,     0,   217,     0,
       0,     0,     0,     0,   265,     0,   267,   268,   263,   264,
       0,   269,   270,   113,   123,   607,   482,   477,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   271,     0,
     203,   204,   205,     0,     0,     0,     0,   423,   424,   426,
     427,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,   432,   433,     0,
       0,   191,   196,   197,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   428,   429,   430,     0,
       0,     0,     0,     0,     0,     0,     0,   517,   518,     0,
     519,   495,   376,   436,   439,   300,   496,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,   193,
     194,   189,   196,   197,   198,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,     0,     0,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   607,
       0,     0,   217,     0,     0,   366,     0,     0,     0,   200,
     201,     0,     0,     0,     0,     0,   503,     0,     0,   501,
       0,     0,     0,     0,     0,   607,     0,     0,   540,     0,
       0,     0,     0,   261,   262,     0,   559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     561,     0,   585,   563,   564,     0,     0,     0,     0,     0,
       0,   562,     0,     0,     0,     0,   279,   280,     0,   217,
       0,   217,     0,     0,     0,   477,     0,     0,     0,   217,
     372,     0,     0,    76,     0,    63,     0,     0,    67,    66,
      65,    64,    69,    68,    70,    71,     0,     0,     0,     0,
       0,     0,   546,   477,     0,   216,     0,   215,     0,   170,
       0,     0,   546,   547,     0,     0,   597,     0,   598,   547,
     111,   111,     0,   475,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   534,   535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   510,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   379,     0,   378,   504,   380,     0,   497,     0,     0,
     477,     0,   512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,    71,     0,   453,     0,
       0,     0,     0,     0,     0,     0,   301,     0,   334,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,   217,   217,     0,   486,   485,     0,     0,     0,     0,
     217,   217,     0,     0,     0,     0,   297,     0,   217,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,     0,     0,     0,   242,     0,     0,   240,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     344,   260,     0,     0,     0,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   283,   282,     0,   247,     0,     0,
     249,     0,     0,     0,   378,     0,   217,     0,     0,     0,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    72,    73,     0,     0,   258,    38,   254,     0,     0,
       0,     0,     0,   212,     0,     0,     0,     0,     0,   218,
       0,     0,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,   480,     0,     0,   478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   328,     0,     0,
       0,   195,     0,     0,     0,     0,     0,     0,   362,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     434,   452,     0,     0,     0,     0,   513,   514,     0,     0,
       0,     0,     0,   471,     0,   377,   498,     0,     0,     0,
       0,   506,     0,   396,   395,   394,   393,   389,   390,   397,
     398,   392,   391,   382,   381,     0,   383,   505,   384,   387,
     385,   386,   388,   478,     0,     0,   479,   456,     0,   520,
       0,     0,     0,     0,     0,     0,     0,     0,   332,     0,
       0,     0,     0,   365,     0,     0,     0,     0,   364,     0,
     217,     0,     0,     0,     0,     0,   488,   487,     0,     0,
       0,     0,     0,     0,     0,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   351,     0,
       0,   241,     0,     0,   236,     0,     0,     0,     0,   361,
       0,     0,     0,   377,   502,     0,     0,     0,     0,     0,
       0,     0,     0,   284,   285,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   588,     0,     0,     0,   473,     0,     0,
     246,   250,   248,   252,     0,   383,     0,   478,   456,   609,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,   377,     0,    63,     0,     0,
       0,     0,    79,     0,    63,    64,     0,     0,   478,     0,
       0,   456,     0,     0,     0,   189,     0,     0,     0,   604,
      28,    26,    27,     0,     0,     0,     0,     0,   479,   550,
      29,     0,     0,   255,   599,   600,     0,   601,   550,    74,
     114,    75,   124,   481,   483,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,   537,   206,     9,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   422,   409,     0,   411,
     412,   413,   414,   415,   533,   416,   417,   418,     0,     0,
       0,   525,   524,   523,     0,     0,     0,   530,     0,   468,
       0,     0,     0,   470,     0,   128,   451,   509,   508,   199,
       0,     0,   437,   532,   442,     0,   448,     0,     0,     0,
       0,   499,     0,     0,   449,     0,   511,     0,     0,     0,
       0,   441,   440,   463,    70,    71,     0,     0,     0,     0,
       0,     0,     0,   377,   330,   335,   333,     0,   343,     0,
     148,   149,   199,   377,     0,     0,     0,     0,   237,     0,
     251,   253,     0,     0,     0,   207,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,     0,
     288,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   337,   350,     0,     0,     0,     0,     0,     0,
       0,   202,     0,     0,     0,     0,     0,     0,     0,     0,
     243,     0,     0,     0,     0,   575,     0,   582,   571,   572,
     573,     0,   587,   586,     0,     0,   576,   577,   578,   584,
     591,   590,     0,   139,     0,   565,     0,   567,     0,     0,
       0,   560,     0,   245,     0,     0,     0,     0,     0,     0,
       0,   323,     0,     0,     0,   373,     0,   605,     0,     0,
       0,     0,   101,    63,     0,     0,     0,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,    61,     0,    39,    40,    41,    42,
      43,     0,   441,   440,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   549,   548,     0,     0,
       0,     0,     0,     0,     0,   135,     0,   131,   132,     0,
       0,     0,     0,     0,     0,     0,   155,   155,     0,     0,
       0,     0,     0,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   516,     0,     0,
       0,     0,     0,   471,   472,     0,   444,     0,     0,     0,
     507,   399,   500,   457,   455,     0,   454,     0,     0,   521,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   342,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,   308,     0,
     311,     0,   313,     0,   298,   305,     0,     0,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,   352,     0,
     239,   238,   368,     0,     0,    35,    36,     0,     0,     0,
       0,   541,     0,     0,     0,   274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   473,
     474,   569,     0,   457,     0,     0,   217,   324,     0,   325,
     217,     0,     0,   555,   556,   557,   558,     0,    86,     0,
       0,     0,     0,    84,    91,    93,     0,   544,     0,    99,
       0,     0,     0,     0,    81,     0,     0,     0,     0,     0,
      34,   457,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,    31,     0,   551,     0,     0,
      32,     0,   551,   602,     0,   115,   120,     0,     0,     0,
     134,   137,   138,   476,     0,    77,     0,     0,     0,     0,
      78,   157,     0,     0,     0,     0,   158,   173,   174,     0,
       0,     0,     0,   159,   184,   175,   179,   180,   176,   177,
     178,   165,     0,     0,   410,   419,   420,   421,   526,     0,
       0,     0,   466,   467,   469,   129,   435,   465,   438,   443,
       0,     0,   471,   185,   450,     0,    70,    71,     0,   462,
     458,   460,   527,   181,     0,     0,     0,   151,     0,     0,
     341,     0,   150,     0,     0,     0,     0,   259,     0,     0,
       0,     0,   217,   217,     0,     0,   310,   495,     0,     0,
     312,   314,     0,     0,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   182,     0,     0,     0,     0,
     162,   163,     0,     0,     0,     0,   102,   103,   104,   108,
       0,   583,     0,     0,   581,     0,   592,     0,     0,   140,
     141,   589,   566,   568,     0,     0,     0,     0,     0,     0,
     322,   326,   322,     0,   374,    85,    63,     0,     0,     0,
       0,    83,     0,   542,     0,     0,     0,     0,     0,     0,
     595,   594,     0,     0,     0,     0,     0,   493,     0,     0,
     462,   256,   458,   257,     0,     0,     0,     0,     0,   222,
     219,     0,     0,   554,   552,     0,     0,   116,   121,     0,
       0,     0,   534,   535,   133,   345,   346,   347,   348,   156,
     160,   161,   166,   183,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,   445,     0,     0,     0,     0,   522,
     464,     0,     0,   167,     0,   186,   331,     0,     0,   187,
       0,     0,     0,     0,     0,     0,   492,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   233,
       0,     0,     0,     0,     0,     0,     0,     0,   224,     0,
       0,   349,    37,     0,   539,     0,     0,   276,   275,     0,
       0,     0,     0,     0,     0,   143,   144,   147,   146,   145,
       0,   570,     0,   606,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    97,   545,     0,     0,     0,    88,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    46,     0,
     223,   220,   221,    33,     0,     0,   603,   128,   139,     0,
       0,   136,     0,     0,     0,     0,     0,     0,     0,     0,
     528,   529,     0,   471,   446,     0,   459,   461,     0,     0,
     169,   190,     0,   338,   338,     0,   109,   110,   217,     0,
     210,   211,   299,     0,   306,     0,     0,   217,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   213,     0,     0,
       0,     0,   105,   106,   574,   580,   579,   142,     0,     0,
       0,   327,     0,    92,    94,     0,   100,     0,    82,   596,
      89,    90,    49,     0,     0,     0,     0,   494,     0,     0,
     459,   553,     0,     0,     0,   118,   593,     0,   125,     0,
       0,     0,     0,   172,     0,     0,     0,     0,   302,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,     0,   316,     0,     0,   293,     0,   225,     0,     0,
       0,     0,     0,     0,     0,   538,   277,     0,     0,   360,
     217,   375,     0,   543,     0,    45,     0,     0,     0,    62,
      47,     0,   117,   122,   128,     0,     0,   153,   154,   152,
       0,     0,   447,     0,     0,     0,     0,     0,   339,   353,
       0,     0,   354,     0,   208,     0,   307,     0,   289,     0,
     217,     0,     0,     0,     0,     0,     0,   164,   107,   273,
     322,    98,     0,     0,     0,     0,     0,     0,   126,   127,
       0,     0,     0,     0,   188,     0,   357,     0,   358,   359,
     489,     0,     0,   295,   228,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,    59,     0,     0,   119,     0,
       0,     0,   303,     0,     0,   315,   294,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   229,   230,   231,
     232,     0,   226,   329,    50,     0,    57,     0,   266,     0,
     531,     0,     0,     0,   296,     0,     0,    51,     0,     0,
     272,     0,     0,     0,   227,     0,     0,     0,     0,   515,
       0,     0,    54,    52,     0,    55,     0,   355,   356,     0,
       0,    60,    58,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,   112,  1043,   113,   114,  1027,  1861,  1867,
    1316,  1525,  2014,  2146,  1317,  2117,  2164,  1318,  2148,  1319,
    1320,  1529,   427,   578,   579,  1113,   115,   759,   450,  1877,
    2024,  1878,   451,  1751,  1389,  1346,  1347,  1348,  1486,  1689,
    1690,  1179,  1582,  1573,   739,   590,   265,   266,   342,   194,
     267,   436,   437,   119,   120,   121,   122,   123,   124,   125,
     126,   268,  1211,  2049,  2108,   923,  1207,  1208,   269,  1004,
     270,   130,  1418,  1177,   898,   937,  1984,   131,   132,   133,
     134,   271,   272,  1135,  1150,  1270,   273,   764,   274,   887,
     763,   453,   605,   311,  1726,   349,   350,   276,   548,   357,
    1304,  1518,   446,   442,  1263,   981,  1562,  1719,  1720,   966,
     448,   136,   405
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1835
static const yytype_int16 yypact[] =
{
   11798,    63,    52, 11952, -1835, -1835,   -76,   130,   -16,  -120,
     -67,    26,   236,   248,   253,   257,   -58,   296,   305,   -26,
       5,    23,   191,   478,   191,    89,   100,   110,    37,   115,
     141,    54,   156,   163,   174,   181,   213,   220,   223,   251,
     254,   273,   322,   439,   460,   584,   381,     6,   541,   415,
    6153,   427,   398,   429,   619,   -50,   447,   482,   402,   352,
     448,   643,   -91,   436,   268,   268,   462,   318,   376, -1835,
   -1835, -1835, -1835, -1835,   504,   631,   656,   687,    24,    53,
     699,   708,    78,   798,   820,   828,  5193,   888,   647,   657,
     663,    12,    56, -1835,   671,   678, -1835, -1835,   923,   944,
     717, -1835,  7942,   721,  8177,    32,    44, -1835, -1835, -1835,
   11002,   727, -1835, -1835, -1835, -1835, -1835,   722, -1835, -1835,
   -1835, -1835, -1835, -1835, -1835, -1835, -1835, -1835,    46, -1835,
   -1835, -1835, -1835,     9, -1835,   966,   723,  4943,   302,   728,
     970, 11002, 12123, 12123, -1835, 11002, -1835, -1835, -1835, -1835,
   12123, -1835, -1835, -1835, -1835,   733,   735,   969, -1835, -1835,
   12153,   742,   743,   746,   747,    23, 11002, 11002, 11002,   748,
   11002, 11002, 11002,   749, 11002, 11002, 11002, 11002, 11002, 11002,
   11002, 12123, 11002, 11002, 11002, 11002,  5193,   750, -1835,  8783,
   -1835, -1835, -1835,   751,  5193,  6393, 12123, -1835, -1835, -1835,
   -1835, -1835,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   264,   191,   191,   191,   191,
     191,   752,   191,   191,   754,   482, -1835, -1835, -1835,   191,
     191,    45,   813,   818,   821,   756,  6393,   879,   482,   482,
     761,   191,   191,   763,   764,   769, -1835, -1835, -1835, 11002,
    6633, 11002, 11002,  6873,    23,   830,    48, -1835, -1835,   766,
   -1835,  4399, -1835, -1835, -1835, -1835, -1835,   107, 11002,  8783,
    8783,   771,   773,  7113,  5193,  5193,  5193, -1835, -1835, -1835,
   -1835, -1835, -1835, -1835, -1835,   774,  7353,   775,  9665,  1013,
    6393,   776,    12,   778,   779,   268,   268,   268, 11002, 11002,
     -21, -1835,   218,   268,  9742,   320,    73,   777,   784,   785,
     788,   789,   790,   791, 11002,  5193,  5193,  5193,   794,    18,
    1031,   795, -1835,  1032,  1037, -1835,   799,   802,   806, -1835,
   -1835,   819,  5193,   800,   822,   823, -1835, 11002,  5433, -1835,
    1058,  1062, 11002, 11002, 11002,   507, 11002,   826, -1835,   896,
   11002, 11002, 11002, -1835, -1835, 11002, -1835,   191,   191,   191,
     845,   846,   848,   191,   191,   191,   191,   191,   191,   191,
   -1835,   191, -1835, -1835, -1835,   191,   191,   849,   850,   191,
     851, -1835,   852,  1088,  1089,   853, -1835, -1835,  1091,  1090,
    1094,  1093,   191, 11002, 13864,   114, 12123,  8783, 11002, -1835,
   -1835,  6393,  6393, -1835,   856, 12153,   555,  1115, -1835, -1835,
   -1835, -1835, -1835, -1835, 11002, 11002,    36,  6393,  1117,   661,
    1063,   878,  1124,    86,   887, -1835,   884, 12276, 11002, -1835,
    1561,   -20, -1835,    59,   295,  6569, -1835,   336, -1835,    85,
      -5,   239,  1047, -1835,    23,   886, 11002, 11002, 11002, 11002,
     889, 14380, 14405, 14430, 11002, 14455, 14480, 14505, 11002, 14530,
   14555, 14580, 14605, 14630, 14655, 14680,   892, 14705, 14730, 14755,
   12965,  1129, 11002,  8783,  4639, -1835,   306, 11002,  1132,  1133,
     899, 11002, 11002, 11002, 11002, 11002, 11002, 11002, 11002, 11002,
   11002, 11002, 11002, 11002, 11002, 11002, 11002,  8783, 11002, 11002,
   11002, 11002, 11002, 11002,  8783,  8783,   897, 11002, 11002, 12123,
   11002, 12123,  6393, 12123, 12123, 12123,   898, 11002,    21, -1835,
    9982, 11002,  6393,  5193,  6393, 12123, 12123,  8783,    23, 12153,
      23,   905,  8783,   905, -1835,   905, 14780, -1835,   337,   900,
      68,  1086, -1835,  1143, 11002, 11002, 11002, 11002, 11002, 11002,
   11002, 11002, 11002, 11002, 11002, 11002, 11002, 11002,  7593, 11002,
   11002, 11002, 11002, 11002,    23, 11002, 11002,  1148, -1835,   724,
   14805,   451,   467, 11002, 11002, 11002, -1835,  1146,  1147,  1147,
     913, 11002, 11002,  1150,  8783,  8783, 13892,   914,  1152, -1835,
     915, -1835, -1835,  -164, -1835, -1835,  6809,  7049,   268,   268,
     302,   302,  -151,  9742,  9742, 11002,  4995,  -124, -1835, 11002,
   11002, 11002, 11002, 11002, 11002, 11002, 11002, 11002, 14830,  1153,
    1157,  1161, 11002,  1158, 11002, -1835, 11002, 10107, -1835, -1835,
    8783,  8783,  8783, 11002,  1164, 11002, 11002, 11002, 14855,   912,
   -1835, -1835, 14880, 14905, 14930,   994,  7289, -1835,   926,  4813,
   14955, 14980, 13975, 12123, 12123, 12123, 12123, 12123, 12123, 12123,
   12123, 12123, 11002, 12123, 12123, 12123, 12123,    16, 12153, 12123,
   12123, 12123,    23,    23, -1835, -1835,  8783, -1835,   927, 10738,
   -1835,   928, 11050, 11002,   905, 11002, -1835,    23, 11002, 11002,
    1148,   931,   477, 15005, 12166,   934,   483, 11002,  1172,   933,
     935,   936,   937,  6393, 15030, 14002,   148,   932,  1177,  1179,
   -1835, -1835, -1835,  8783,   204, -1835, -1835, -1835,    23, 11002,
   11002,  1148,   942, -1835,   945,   -36,   482,   402,   482, -1835,
     946, 12994, -1835,   135,  8783,    23, 11002, 11002,  1187,  1189,
    8783, 11002,  1190, 12123,    23, 10059,  1187,  1191, -1835,    23,
    1192, 12123, 11002,   950,   955, -1835, 11002,  7529,  8239,  8479,
    8719, 12153,  1193,  1194,  1195, 15055,  1196,  1197,  1198, 15080,
    1199,  1200,  1204,  1205,  1206,  1207,  1209, -1835,  1210,  1213,
    1214, -1835, 11002, 15105,  8783,   977,  8783, 13023, -1835, -1835,
    1218, 13948, 13948, 13948, 13948, 13948, 13948, 13948, 13948, 13948,
   13948, 13948,  9053, 13948, 13948, 13948, 13948,  1360,   568, 13948,
   13948, 13948,  9379,  9610,  9698,  4639,   982,   981,    96,  8783,
    9927, 10246,   568, 10325,   568,   976,   978,   979,   363, 11002,
   16005, -1835,   568,   984, 13052, 13081, -1835, -1835,   985,   186,
     568,   -97,   992,   401,   485,  1221, -1835,  1187,   568,   991,
     993,  5129,  5369,  1873,  2201,   535,   535,   389,   389,   389,
     389,   389,   389,   399,   399,  8783,  -163, -1835,  -163,  -163,
     905,   905,   905,   990, 15130, 14029,  -148,   581,  8783, -1835,
    1232,   995,   996, 15155, 15180, 15205, 11002,  6393,  1240,  1239,
    9430, 13110, 15230, -1835,   492,   493,  8783,   998, -1835, 11170,
   -1835, 11227, 11294,   268, 11002, 11002, -1835, -1835,  1000,  1002,
    9742,  4201,  1118,   328,   268, 11351, 15255, 13139, 15280, 15305,
   15330, 15355, 15380, 15405, 15430,  1244, 11002,  1247, -1835, 11002,
   15455, -1835, 14056, 14083, -1835,   498,   501,   527, 13168, -1835,
   14110, 14137, 10558, -1835, -1835,  1248,  1249,  1251,  1006, 11002,
   11418, 11002, 11002, -1835, -1835,    47,   362,   456,   362,  1016,
    1017,  1011,   568,   568,  1014, 10870,   568,   568,   568,   568,
   11002,   568,  1255, -1835,  1018,  1024,   461,   -45,  1023,   528,
   -1835, -1835, -1835, -1835, 13948,  -163, 11475,  1022,   589,  1021,
    1092,  1266,  1122, 10294,  1028,  1033,  1272,  6393, 13197, -1835,
   11002, 11002, 11002, 11002,  1274,   152,    69, 12153, 11002,  1295,
    1298,    25, -1835,   530,  1257,  1259,  6393,    27,  1060, 15480,
   14164,  -113, 11002, 11002,  1064,  1065,  1067,  1066,  7833, -1835,
   -1835, -1835, -1835, 12123,   375,  1068, 15505, 14191, -1835,  1071,
   -1835,   408, 11596, -1835, -1835, -1835,  1069, -1835,  1072, -1835,
     106, -1835, -1835, 16005, -1835,  1306, 13948, 11002, 11002, 11002,
   11002,   568,   268,  6393,  6393,  1308,  6393,  6393,  6393,  1312,
    6393,  6393,  6393,  6393,  6393,  6393,  6393,  6393,  6393,  6393,
    1738,  1315,  8783,  4639, -1835, -1835, -1835, -1835, -1835, -1835,
   -1835, -1835, -1835, -1835, -1835, -1835, -1835, -1835, 11002, -1835,
   -1835, -1835, -1835, -1835, -1835, -1835, -1835, -1835, 11002, 11002,
   11002, -1835, -1835, -1835,   533, 11002, 11002, -1835, 11002, -1835,
    6393, 12123, 12123, -1835, 13226,  1073, -1835, -1835, -1835,  1149,
   11002, 11002, -1835, -1835, -1835,  1187, -1835,  1187, 11002, 11002,
    1080, -1835,  6393,   191, -1835, 11002, -1835, 11002, 11002,   536,
    1187,  -148,   -41, -1835, 11002, 11002,   568,   538,  6393,  8783,
    8783,  1319,  1321,  1323,  2562, -1835, -1835,  1326, -1835,  1095,
   16005,  1082, -1835,  1327,  1329,  1330,   539,  1335, -1835, 11542,
   -1835, -1835,  -121, 12206, 12239, -1835, -1835, 13255,  -166,  1230,
    1337, 10378,  1097,  1338,  1103,    39,    40,   312, -1835,  -119,
   -1835,   328,  1339,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1349,  6393, 16005, -1835,  1792,  1102,  1351,  1352,  1355,  1265,
    1357, -1835,  1359,  1361, 11002,  6393,  6393,  6393,  1362, 12272,
   -1835,  5609,  1529,    70,  1365, -1835,  8783, -1835, -1835, -1835,
   -1835, 12123, -1835, -1835, 11002, 12123, -1835, -1835, -1835, -1835,
   16005, -1835,  1121,  1120, 12123, -1835, 12123, -1835,  1187, 12123,
    1130, -1835,  1123, -1835,  1187, 11002, 11002,  1126,   482,  1131,
   10613, -1835,  2023,  1134,  6393, -1835,  1128, -1835, 13284, 13313,
   13342, 13371, -1835, -1835, 11002,  1372,    38, 11002,  1373,  1375,
    2162, -1835,  1378,    12,  1376,  1142,   568,   191,   191,  1384,
   -1835,  1151,  1154,  1145, -1835,  1386, -1835, -1835, -1835, -1835,
   -1835,  1187,   476,   768, 11002, 14218, 15530, 11002,  8068, 11002,
    8783,  1155,   545,  1388,   146,  1187, -1835,  1156, 11002,  1391,
   11002,  1187, 10690,  9018,   568,  4463,  1160,  1163, -1835,  1392,
   15555, 15580, 15605, 15630,  1393,   144,  1275,  1275,  6393,  1395,
    1397,  1400,  6393,   -96,  1401,  1402,  1403,  1412,  1416,  1417,
    1418,  1419,  1420, -1835,  1422,   548, 13948, 13948, 13948, 13948,
     568, 12305, 12338, 12371,  1174,   568,   568, -1835,  1306,   568,
   15655, 13948,  1185,   155, 16005, 13948, -1835,  1424,   568, 12404,
   16005, 16005, -1835,   610, -1835,  1427, -1835, 15680, 14245, -1835,
     568,  1426,   550,   553,  6393,  6393,  6393,  1429,  1430, -1835,
     210, 11002,  6393,  1201,  1202,  1428,   222, -1835, 11002, 11002,
   11002,  1203,  1208,  1220,  1211, -1835,  2443,  6393, -1835, 11002,
   -1835,  1431, -1835,  1432, -1835, -1835,  9742,   437,  5673, -1835,
    1222,  1223,  1228,  1229,  1231,  1235,  8303,  1433, -1835,  8783,
   -1835, -1835, -1835,  1236, 11002, -1835, -1835, 14272,  1434,  1435,
    1267, -1835, 11002, 11002, 11002, -1835,  1436,  1438,  1440,   521,
     468,  1216,  3052,  1225, 11002,    35,   568,  1241,   568,  1237,
   -1835, -1835, 12153,   624, 11002,  1243, -1835, -1835,  2838, -1835,
   -1835,  1242,  1444, -1835, -1835, -1835, -1835,  2975, -1835,   178,
    1246,  1480,  3093, -1835, -1835, -1835,    12, -1835,   556, -1835,
   11002,   210,  2773,  1411, -1835,  1250, 11002, 11002,  6393,  1245,
   -1835,   412,  1486,  1489, 15705,  1491,  1221, 15730,  1253,   558,
   15755,   561,  1492,  1496, -1835, -1835, 12123,  1261,  1500, 15780,
   -1835, 12437,  1263, -1835,  4703, 16005, -1835,  1499,   191,  6873,
   -1835, -1835, -1835, -1835,  1306, -1835,  1501,  1502,  1504,  1505,
   -1835, -1835,   268,  1506,  1508,  1509, -1835, -1835, -1835,  1510,
     -22,  1421,  1512, -1835, -1835, -1835, -1835, -1835, -1835, -1835,
   -1835, -1835,  1516,  1276, -1835, -1835, -1835, -1835, -1835, 11002,
   11002, 11002, -1835, -1835, -1835,  1163, -1835, -1835, -1835, -1835,
   11002,  1280,  1273, -1835, -1835, 11002, 11002, 11002,   568,  -148,
   -1835, -1835, -1835, -1835,  1282,  1283,  1520,   -96,  1524, 11002,
   -1835,  6393, 16005,   924,  8783,  8783, 11002, -1835,  9430, 13400,
   15805,  5849,   302,   302, 11002, 11002, -1835,   713,  1281, 15830,
   -1835, -1835, 13429,  -116, -1835,  1525,  1527,  6393,   268,   268,
     268,   268,   268,  5913,  1528, -1835,   587, 11002,  3290,  1530,
   -1835, -1835,  6393,  6089,   885, 15855, -1835, -1835, -1835, -1835,
    9104, -1835, 12123, 11002, -1835, 12123, 16005,  9344, 12153,  1284,
   -1835, -1835, -1835, -1835,  1297,  1287, 11002, 11002, 13458, 11002,
   12166, -1835, 12166,  6393, -1835, -1835, 12153, 11002,  1535,  1538,
      25, -1835,  1539, -1835,    12, 14299,  6393, 12123,  1540,   568,
   -1835,  1293,   568, 11002, 12470, 12503,   592, -1835, 11002, 11002,
     487, -1835,  1301, -1835,  1323,  1542,  1543,  1327,  1544, -1835,
   -1835,  1546, 11002, -1835, -1835, 11002, 10925, -1835, -1835,  1307,
    1411,   597,  4074,  1547, -1835, -1835, -1835, -1835, -1835,   466,
   -1835, -1835, -1835, -1835,  1309,  1311,  1313, -1835,  1553,  6393,
   13948, 13948, 12536, 13948, -1835,  1317, 12569, 15880, 14326, -1835,
   -1835,  8783,  8783, -1835,  1555, -1835, 16005,  1556,  1318, -1835,
     598,   599, 13920,  3355,  1557,  1320, -1835, -1835, 11002,  1322,
    1325, 13487, 14353,  1559,  6393,  1563,  1328, 11002, -1835, -1835,
     600,   -93,   -88,   -82,   -70,   -51,  8543,   -43, -1835,  1562,
   13516, -1835, -1835,  1398, -1835, 11002, 11002, -1835, -1835,  8783,
    3544,  1569,  1333, 13948,   568, 16005, -1835, -1835, -1835, -1835,
      35, -1835, 12153, -1835, 13545,  1353,  1363,  1364,  1571,  3626,
   -1835,  1595,  1600, -1835, -1835,  1366,  1606,   612, -1835,  1607,
    1609,   438, 16005, 11002, 11002,  1370,  6393,   613, 16005, 15905,
   -1835, -1835, -1835, -1835, 15930, 12602, -1835,  1073,  1120,  6393,
     568, -1835, 11002, 12153,    23,  8783,  8783, 11002,  1611,   614,
   -1835, -1835, 11002,  1273, -1835, 11002, -1835, -1835,   620,   622,
   -1835, -1835,  6393,   108,   265,  8783, -1835, -1835,   302,  6329,
   -1835, -1835, -1835,  1613, -1835,  1374,  6393, -1835, 13574,  1614,
    8783,   268,   268,   268,   268,   268, -1835, -1835, 11002, 13603,
   13632,   627, -1835, -1835, -1835, -1835, -1835, -1835,  1380,  1620,
    1381, -1835,  1623, -1835, -1835,    12, -1835,  1455, -1835, -1835,
   -1835, -1835, -1835, 11002, 12635, 12668,  6393, -1835,  1628, 11002,
    1389, -1835, 11002,  1390,  1396, -1835, -1835,  4097, -1835,  1405,
     628,   629, 13661, -1835,  1404, 12701,  1399, 12734, -1835,  1406,
     630,  1407,   268,  6393,  1632,  1410,   268,  1633,   637,  1414,
   -1835, 11002, -1835,  1638,  1517, 11599,  1413, -1835,   639,   -29,
     -10,     2,   159,   183,  3939, -1835, -1835,  1642,  1652, -1835,
   -1835, -1835,  1656, -1835,  1425, 16005, 11002, 11002,   644, -1835,
   16005, 12767, -1835, -1835,  1073, 12153,  1423, -1835, -1835, -1835,
   11002, 11002, -1835, 11002,  8783,  1657,   268,   147, -1835, -1835,
     268,   151, -1835,  1658, -1835, 13690, -1835, 11002, -1835,   328,
   -1835,  1659,  8783,  8783,  8783,  8783,  8543, -1835, -1835, -1835,
   12166, -1835, 11002, 15955, 12800,    29, 11002,  1437, -1835, -1835,
   12833, 12866, 12899,   650, -1835,   212, -1835,   215, -1835, -1835,
   -1835,  4031,   440, 11666, -1835,   651,   665,   667,   668,   243,
     674,  1441,   675, -1835, 11002, -1835,  6393, 13719, -1835, 11002,
   11002, 11002, -1835,   268,   268, -1835, -1835, -1835,   328,  1661,
    1662,  1664,  1666,  8783,  1667,  1668,  1669,  1439, 15980,   676,
    1671, 13748, 13948, 12932,   258,   293,   453, -1835, -1835, -1835,
   -1835,   704, -1835, -1835, -1835, 12123, -1835,  1447, -1835,  1672,
   -1835, 11002, 11002, 11002, -1835,  1674,   705, -1835,  1448,  6393,
   -1835, 13777, 13806, 13835, -1835,  1675, 12123, 12123,   706, -1835,
    1677,  1681, -1835, -1835,   711, -1835,  1684, -1835, -1835,  1690,
   12123, -1835, -1835, -1835
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1835, -1835, -1835, -1835,   364, -1835, -1835, -1835, -1835,  -356,
   -1835, -1835, -1835, -1835, -1835, -1835, -1835, -1835, -1835, -1835,
   -1835, -1835,  -711,  -133,  3991,  2570, -1835,  1258, -1835, -1835,
   -1835, -1835, -1835, -1835, -1834, -1835,   324,   153,  -170, -1835,
    -130, -1835,    88,   359,  1715, -1835,    -1,   -44, -1835, -1835,
      -2,  -601,  -281, -1835, -1835, -1835, -1835, -1835, -1835, -1835,
   -1835,  1716, -1835, -1835, -1835, -1835, -1208, -1195,  1717, -1681,
    1718, -1835, -1835, -1835,  1135, -1835,  -179, -1835, -1835, -1835,
   -1835,  2014, -1835, -1835, -1376,   237,  1724, -1835,     3,  -693,
   -1835, -1835,   249, -1835, -1613,   -27,  -160,  2363,  -183,  -294,
      22, -1835,  1549,    17, -1835, -1835,    41,   208, -1657,  -139,
     980, -1835,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -555
static const yytype_int16 yytable[] =
{
     137,   118,   117,  1447,   428,  1018,   486,   998,   600,   918,
     919,   447,  1445,  1026,   296,   410,   355,  1611,   157,  1845,
     155,  1846,   633,   275,   156,   155,   481,   155,   329,   155,
    1838,  1310,   144,   616,   488,  2095,  1580,   398,  1031,  1687,
     716,   169,  1509,  1963,  1810,  1440,  1442,   277,   282,   400,
     529,   637,     5,   552,  1243,  1049,   291,   334,   173,   335,
     359,   301,   282,  1058,   608,   609,   608,   609,   745,     4,
    1764,   283,   571,   572,  1476,   333,  1293,   454,   573,   608,
     609,  1432,   141,   277,  1581,  1034,   302,   913,   358,  1765,
     155,   422,   423,  1880,   754,   728,   581,   582,   190,   394,
     920,   191,   303,   304,   192,   574,   608,   609,   330,   608,
     609,   608,   609,  1343,   608,   609,   574,   193,   689,   393,
     692,   397,   142,   697,   587,   588,   589,   924,   704,  1324,
    1428,  1276,  1446,  -550,   433,  1807,   435,   608,   609,   443,
     443,  1040,   608,   609,   140,   336,  1144,   449,   608,   609,
    1571,  1145,  1545,  2076,   432,  1017,  1889,  2078,  1920,  1293,
     608,   609,   460,  1921,  1153,   629,   630,   631,   489,  1922,
     138,  1477,  1478,   339,   139,   143,   340,   455,   443,   608,
     609,  1923,   644,   277,   150,  1706,   277,   608,   609,   341,
    2067,   277,   277,   443,  1311,  1312,  1313,  1314,   422,   423,
    1924,   608,   609,  1268,  1441,  1443,  1269,  1405,  1925,   608,
     609,  1024,   331,   717,   718,  1510,  1511,  1293,   153,   275,
     608,   609,  2052,   743,   702,   610,   111,  1688,  1637,  1638,
     111,   744,   608,   609,   526,   111,  1775,   111,   111,   111,
     757,  2053,   146,   277,  1981,  1982,   758,   533,   534,   154,
    1983,   411,  1445,  2054,   147,   412,   586,   277,   356,   148,
     277,   550,   634,   149,   721,   980,   722,   549,   139,   593,
     332,  1303,   145,   598,  1315,  2096,   277,   277,   399,   170,
     277,   277,   277,   277,   418,   419,   420,   421,   408,  1980,
     401,   530,   409,   277,   553,  1244,   174,   277,   360,   358,
     111,   746,   151,   747,  1294,  1297,   434,   748,   422,   423,
     158,   152,   159,   310,   312,   619,   315,  1296,   909,   620,
     911,   912,   277,   277,   277,   422,   423,   755,   729,   747,
     730,   166,  -547,   756,   731,   422,   423,   925,   575,   277,
     576,  1123,   167,  2018,   577,   277,   422,   423,   158,   575,
     159,   576,   168,   422,   423,   577,   698,   171,   699,   854,
    1041,  1042,   700,   418,   419,   420,   421,   418,   419,   420,
     421,  1041,  1042,   846,   608,   609,   960,   608,   609,  2091,
     316,   608,   609,   172,   705,   706,   838,   422,   423,   608,
     609,   422,   423,   418,   419,   420,   421,   158,   175,   159,
     719,  1985,  1986,   443,   277,   176,  1148,  1983,   277,   277,
    2055,   904,   905,   608,   609,   996,   177,   422,   423,   418,
     419,   420,  1025,   178,   277,   418,   419,   420,   421,   721,
     732,   722,   708,   158,  2056,   159,   740,  1141,    63,    64,
      65,    66,   608,   609,  1200,   608,   609,   297,   608,   609,
     298,   765,  1392,    77,  1393,   179,    80,   945,   946,   947,
    1200,  1201,   180,  2103,   611,   181,  2104,  1403,   317,  1202,
    1203,  1204,   318,   608,   609,  1205,  1206,  1201,   319,   320,
     277,   321,   322,  2119,   760,  1202,  1203,  1204,   608,   609,
     758,  1205,  1206,   182,  2113,   835,   183,   292,   306,   307,
     293,   323,   294,   989,   277,   586,   514,   847,   515,  2142,
     308,   277,   828,   295,   309,   184,   443,  1976,   443,   277,
     443,   443,   449,   608,   609,   842,   968,  1679,  1680,   277,
     277,   277,   443,   443,   277,   157,  2158,   157,   749,   277,
    1023,   851,   284,   853,  2143,   285,   750,   286,   306,   307,
     608,   609,   186,   795,   603,   604,   852,   796,   187,  1444,
     308,  1044,   612,   617,   314,   277,   618,  1051,   185,  1200,
     161,   883,  1200,   162,   287,  1489,   163,   288,   164,   752,
     289,  1493,   290,  1019,   856,  1200,  1201,   753,   796,  1201,
     188,   277,   277,    42,  1202,  1203,  1204,  1202,  1203,  1204,
    1205,  1206,  1201,  1205,  1206,   721,  1133,   722,   435,   435,
    1202,  1203,  1204,   753,   753,   740,  1205,  1206,  1334,   566,
     567,   695,   569,   570,   571,   572,   796,   189,  1531,  1189,
     573,   695,   569,   570,   571,   572,   740,   277,   277,   277,
     573,   195,  1547,   158,   279,   159,  1124,   709,  1552,  1147,
     710,  1339,  1148,   711,  1729,   712,  1697,   196,  -551,   796,
     449,   443,   449,   443,   443,   443,   443,   443,   443,   278,
     443,   443,   443,   443,   982,   280,   443,   443,   443,   157,
     988,  1952,   305,   277,  1654,   987,  1014,  2106,   740,  1953,
     299,   740,  1159,  1036,   997,   983,   608,   609,   891,   721,
    2144,   722,   796,   740,   721,  1167,   722,  1246,   313,  1631,
     277,   721,  1266,   722,   892,   422,   423,   281,   796,   796,
     277,   554,  -549,  1186,  1000,  1028,   422,   423,   796,   325,
    1006,   326,  1151,  -554,  1007,  1035,   796,  1037,   300,  1184,
    1185,   277,  1045,   796,   796,  1228,   324,   277,  1229,   796,
     449,  1056,   796,  1163,   327,   655,  1060,   139,   443,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,   155,   366,  1230,  1272,   573,  1306,   796,   796,
    1380,   796,   328,  1402,   796,  1410,  1425,   796,  1071,   796,
     796,   277,  1543,   277,   337,  1593,   796,  1624,  1707,   796,
    1625,   796,   343,  1713,   796,  1736,   338,  1714,  1738,   796,
    1716,   721,   796,   722,   367,   368,   369,   370,   371,   372,
     373,   374,   375,  1164,   344,  1165,   277,   376,   377,   378,
     379,  1275,   345,  1276,  1819,   380,   381,   382,   796,  1865,
     383,  2082,   384,  1866,  1881,  1903,  1904,  1919,  1882,   796,
     796,  1866,  1616,   385,  1617,  1332,   386,   916,   917,  1949,
    1958,  1974,   604,   753,  1959,  1866,  1696,  1978,  1697,  1979,
    1175,   796,   277,   796,  2007,  2027,  2028,  2035,   796,   796,
     796,  1866,  1295,  1298,  2043,   277,  2051,  1445,   796,   352,
     796,  2065,   351,  1826,   277,  1866,   416,  2102,  2109,   353,
    2126,   796,   796,   277,   721,   354,   722,   723,   740,  1375,
     740,   740,  2110,   361,  2111,  2112,   796,  1181,   796,   796,
     362,  2114,  2116,  2137,   740,   796,  1959,  1866,  1788,   363,
    1789,  1445,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     364,  2145,  2155,  2166,   573,   796,  2156,  1866,  2169,   740,
    1803,   365,  2170,   395,   387,   388,   389,   721,   407,   722,
     888,   406,   413,   414,   438,   390,   439,   452,   454,   391,
    1286,   392,   111,   139,   456,   457,  1412,  1413,   458,   459,
     464,   468,   482,  -192,   522,   740,   525,   487,  -193,  1309,
     532,  -194,   531,   535,   277,   538,   539,   422,   423,  1517,
     551,   540,   409,   583,  -548,   584,  1532,   597,  1305,   621,
     591,   594,   599,   277,   601,   602,   622,   623,  1404,  1406,
     624,   625,   626,   627,  1299,   277,   632,   635,   638,   636,
     443,  1799,  1800,   639,   645,   640,  1356,  1357,   641,  1359,
    1360,  1361,   642,  1363,  1364,  1365,  1366,  1367,  1368,  1369,
    1370,  1371,  1372,  1480,   650,   643,   646,   647,   651,   725,
     277,   277,   657,   277,   277,   277,   658,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   666,   667,   277,
     668,   679,   680,   682,   684,   685,   683,   687,   688,   686,
     690,   691,   707,  1384,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,   713,   720,   726,  1397,   573,   277,   443,   443,
     727,   733,  1827,   138,   762,   787,   792,   766,   798,   799,
     771,  1411,   800,   829,   839,  1539,   573,  1541,   857,   277,
     859,   860,   886,   896,   897,   900,   903,   907,   908,   954,
     936,   910,  1192,   938,   941,   277,   277,   277,   939,  1198,
     949,   958,   961,  1209,   990,   992,   999,  1005,  1009,  1010,
    1020,  1011,  1012,  1013,  1021,  1022,  1032,  1033,   740,  1404,
    1406,  1048,  1038,  1064,  1457,  1050,  1053,  1059,  1061,  1065,
    1072,  1073,  1074,  1076,  1077,  1078,  1080,  1081,  1468,  1469,
    1470,  1082,  1083,  1084,  1085,  1700,  1086,  1087,   277,  1702,
    1088,  1089,  1712,  1092,  1096,  1121,  1122,  1130,  1152,  1131,
    1132,  1137,   277,   277,   277,  1146,  1140,  1155,  1160,  1168,
    1156,  1169,  1170,   277,  1176,  1178,  1187,  1195,   443,  1196,
    1199,  1221,   443,  1223,  1238,  1235,  1236,  1501,  1237,  1249,
    1250,   443,  1251,   443,  1262,  1254,   443,  1265,  1271,  1264,
    1274,  1277,  1278,  1279,  1280,  1283,  1666,  1495,  1285,  1284,
    1292,   277,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
     358,  1301,  1302,  1307,   573,  1308,  1327,  1989,  1321,  1329,
    1345,  1328,  1330,  1338,  1342,  1358,  1335,  1341,  1560,  1362,
     443,  1355,  1374,  1396,  1388,   277,  1414,   277,  1415,  -195,
    1416,  1575,  1419,  1421,  1422,  1579,  1423,  1424,  1420,  1426,
    1433,  1434,   277,  1437,  1438,  1439,  1448,  1449,  1459,  1450,
    1451,  1452,  1453,  1454,  1455,   277,  1456,  1460,  1461,   277,
    1556,  1462,  1561,  1463,  1464,  1465,  1471,  1466,   554,  1479,
    1484,  1485,  1494,  1491,  1492,  1502,  1708,  1496,  1508,  1513,
    1500,  1514,  1519,  1721,  1721,  1516,  1520,  1626,  1627,  1628,
    1524,  1528,  1530,  1526,  1544,  1633,  1527,  1550,  1565,  1570,
    1572,  1576,  1542,  1577,  1548,  1563,  1578,  1583,  1584,  1585,
    1648,   277,   277,   277,  1564,   155,   366,  1602,  1586,   277,
    1854,  1656,  1587,  1588,  1589,  1590,  1591,  1592,  1609,  1664,
    1613,  1619,  1623,  1629,   277,  1636,  1630,  1650,  1651,  1665,
    1670,  1671,  1676,  1672,  1677,   277,  1678,  1634,  1635,  1642,
    1704,  1790,  1791,   277,  1643,  1645,   277,   367,   368,   369,
     370,   371,   372,   373,   374,   375,  1644,  1682,  1657,  1658,
     376,   377,   378,   379,  1659,  1660,  1685,  1661,   380,   381,
     382,  1662,  1667,   383,  1692,   384,  1780,  1710,  1269,  1699,
    1730,  1728,  1723,  1703,  1709,  1731,   385,  1733,  1739,   386,
    1735,  1727,  1740,  1742,  1743,  1746,  1749,  1755,  1756,  1695,
    1757,  1758,  1760,   358,  1761,  1762,  1763,  1766,  1767,   449,
     449,  1768,  1769,  1774,  1148,   277,  1783,  1747,  1781,  1782,
    1785,  1808,  1804,  1809,  1818,  1840,  1822,  1474,  1842,   416,
    1841,  1850,  1851,   443,   753,  1853,  1858,  -552,  1870,  1871,
    1872,   277,  1873,  1879,  1884,  1885,   277,  1886,  1888,  1887,
    1894,  1900,  1901,  1907,  1902,  1914,  1908,   742,  1926,  1910,
    1916,  1748,  1911,  1928,  1917,  1933,  1934,  1943,  1857,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   794,   569,   570,   571,   572,  1780,  1898,  1899,
    1940,   573,  1945,   721,  1787,   722,  1946,   387,   388,   389,
    1941,  1942,  1948,  1950,  1947,  1951,  1956,  1973,   390,  1992,
    1997,  1993,   391,  2008,   392,   111,  2009,  2010,   277,  2011,
    1727,   277,   277,  2013,  2019,  -553,  1995,  2022,  2039,  2042,
     435,   435,  2032,  2023,  2046,  1823,  1931,  2026,  2058,  2047,
    2030,  2012,  2034,  2036,   277,  1794,  2040,  1717,  2059,  2050,
     277,  2044,  2061,  2074,  2079,  2084,  2069,  2127,  2128,   277,
    2129,  2062,  2130,  2132,  2133,  2134,  1847,  2138,  2150,   443,
    2154,  2162,   443,  2167,  2098,  2135,   431,  2168,  2115,  1856,
    2171,   441,   444,  2149,  2157,  1653,  2172,  1831,  1546,   740,
     277,   740,  1970,  1971,  1836,  1839,  2092,  1305,  1964,   761,
    1937,   358,  1605,   277,   449,  1784,  1574,  1754,   116,   127,
     128,   129,  1988,  1848,   899,  1987,  1694,   135,  1837,  2060,
     476,  1722,  1852,  1055,     0,     0,     0,  1998,     0,     0,
       0,     0,  1727,     0,  1373,   490,     0,   449,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,   277,     0,     0,  2083,
     573,     0,  1475,     0,     0,     0,     0,  1915,   277,   277,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,  1458,     0,
       0,   277,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,     0,     0,     0,     0,     0,
       0,  1759,     0,     0,     0,     0,   277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1957,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2073,  1965,     0,     0,     0,     0,     0,     0,  1938,
       0,     0,     0,   277,     0,     0,     0,     0,     0,  2085,
    2086,  2087,  2088,  2090,     0,  1727,   277,     0,     0,     0,
       0,  1969,   277,   277,     0,     0,     0,     0,     0,  1994,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
    1968,     0,   277,     0,     0,     0,   435,  1811,  1812,  1813,
    1814,  1815,  1817,   277,     0,     0,     0,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1727,
    2131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   277,     0,   701,  2038,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   740,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,  1499,
       0,   277,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,  2068,     0,     0,     0,     0,     0,     0,   277,
     277,   277,   277,   277,     0,     0,     0,     0,     0,   740,
       0,     0,     0,     0,     0,     0,     0,     0,   832,  1727,
     834,     0,   836,   837,     0,     0,     0,     0,     0,     0,
       0,     0,   740,     0,   848,   849,     0,     0,     0,     0,
       0,     0,     0,   277,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
     277,     0,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,  1727,     0,   404,     0,     0,     0,     0,     0,
       0,     0,   443,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,     0,     0,     0,
       0,   430,     0,   443,   443,   440,     0,     0,     0,   445,
       0,     0,     0,     0,     0,     0,     0,   443,  1515,     0,
    1999,  2000,  2001,  2002,  2003,     0,     0,     0,     0,     0,
     461,   462,   463,     0,   465,   466,   467,     0,   469,   470,
     471,   472,   473,   474,   475,     0,   477,   478,   479,   480,
       0,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   967,     0,   969,   970,   971,   972,   973,
     974,     0,   976,   977,   978,   979,     0,     0,   984,   985,
     986,  2037,     0,     0,     0,  2041,     0,     0,     0,     0,
       0,     0,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,   541,   543,   545,   546,   484,     0,     0,
       0,     0,     0,     0,     0,  2075,     0,     0,     0,  2077,
       0,     0,   580,   484,   484,     0,     0,     0,     0,     0,
       0,     0,  1054,     0,     0,  2089,     0,     0,     0,     0,
    1062,     0,   596,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   606,   607,     0,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2124,  2125,     0,     0,     0,     0,     0,     0,
       0,   648,   484,     0,     0,     0,   652,   653,   654,     0,
     656,     0,     0,     0,   659,   660,   661,     0,     0,   662,
       0,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   694,     0,     0,
       0,   484,   703,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,   714,   715,
       0,     0,   573,     0,     0,     0,     0,     0,     0,  1646,
       0,     0,   741,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     767,   768,   769,   770,     0,     0,     0,     0,   775,     0,
       0,     0,   779,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   793,   543,     0,     0,
       0,   797,     0,     0,     0,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   819,   820,   821,   822,   823,   824,   825,   825,
       0,   830,   831,     0,   833,     0,     0,     0,     0,     0,
       0,   840,     0,     0,   844,   845,     0,     0,     0,     0,
       0,   825,   485,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   861,   862,
     863,   864,   865,   866,   867,   868,   869,   870,   871,   872,
     873,   874,   876,   878,   879,   880,   881,   882,     0,   884,
     885,     0,  1333,     0,     0,     0,     0,   893,   894,   895,
       0,     0,     0,     0,     0,   901,   902,     0,   484,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   544,     0,     0,   485,   541,   694,   921,
       0,     0,     0,   926,   927,   928,   929,   930,   931,   932,
     933,   934,   485,   485,     0,     0,   940,     0,   942,     0,
     943,     0,     0,     0,   484,   484,   484,   948,     0,   950,
     951,   952,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
    1385,  1386,     0,     0,   573,     0,   975,     0,     0,     0,
       0,     0,     0,     0,  1417,     0,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,   994,     0,   995,
       0,   485,   884,   885,     0,     0,     0,     0,     0,     0,
       0,  1008,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,  1029,  1030,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,     0,
    1046,  1047,     0,     0,   484,  1052,     0,     0,     0,  1046,
     485,     0,     0,     0,     0,     0,  1063,   155,   366,     0,
    1066,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
    1481,     0,     0,   573,  1483,     0,  1090,     0,   876,     0,
    1093,     0,     0,  1487,     0,  1488,     0,     0,  1490,   367,
     368,   369,   370,   371,   372,   373,   374,   375,     0,     0,
       0,     0,   376,   377,   378,   379,     0,     0,     0,     0,
     380,   381,   382,   484,  1701,   383,   544,   384,     0,     0,
       0,     0,     0,  1134,     0,     0,     0,     0,   385,     0,
       0,   386,     0,     0,     0,     0,     0,     0,     0,     0,
     818,     0,  1533,     0,     0,     0,     0,   826,   827,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     850,   416,   484,     0,     0,   485,     0,     0,     0,     0,
    1174,     0,     0,     0,  1180,     0,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,  1193,  1194,
       0,   877,     0,     0,  1197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1222,     0,     0,  1224,     0,     0,     0,   485,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   387,
     388,   389,     0,  1239,     0,  1241,  1242,     0,     0,     0,
     390,  1705,     0,     0,   391,     0,   392,   111,     0,     0,
       0,     0,     0,     0,  1260,     0,     0,     0,     0,   724,
       0,     0,     0,   485,   485,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   721,  1282,   722,  1717,
       0,     0,     0,     0,  1288,  1289,  1290,  1291,     0,     0,
       0,     0,  1300,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1325,  1326,     0,   485,
       0,     0,   484,     0,     0,     0,     0,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,  1350,  1351,  1352,  1353,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,  1741,     0,     0,   841,  1711,
       0,     0,     0,     0,     0,     0,   484,   485,     0,     0,
       0,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,  1376,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1377,  1378,  1379,     0,     0,     0,     0,  1381,
    1382,     0,  1383,     0,     0,     0,     0,     0,     0,   889,
       0,     0,     0,     0,  1390,  1391,     0,   877,     0,  1094,
       0,     0,  1394,  1395,     0,     0,     0,     0,     0,  1399,
       0,  1400,  1401,     0,     0,     0,     0,     0,  1407,  1408,
       0,     0,     0,   484,   484,     0,     0,     0,     0,     0,
       0,     0,   485,     0,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,  1436,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1832,     0,     0,  1834,     0,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1467,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,  1482,   485,
       0,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,  1407,
    1408,     0,     0,   573,  1498,   721,  1821,   722,     0,     0,
       0,     0,     0,  1683,     0,     0,     0,     0,  1507,     0,
       0,  1512,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,  1534,     0,
       0,  1537,   484,  1540,   484,     0,     0,     0,     0,     0,
       0,     0,  1549,     0,  1551,     0,  1549,  1555,     0,     0,
       0,  1906,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,     0,  1109,  1110,  1111,  1112,     0,  1114,  1115,
    1116,  1117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,  1127,     0,  1129,     0,     0,     0,     0,     0,
       0,     0,  1136,     0,     0,     0,     0,     0,     0,  1142,
    1143,     0,     0,     0,     0,     0,     0,     0,  1154,     0,
       0,     0,     0,     0,     0,  1632,     0,     0,     0,     0,
       0,     0,  1639,  1640,  1641,     0,     0,     0,     0,     0,
       0,  1647,     0,  1649,     0,   485,     0,     0,     0,     0,
    1652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,  1668,     0,
       0,     0,     0,     0,     0,     0,  1673,  1674,  1675,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1686,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1698,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,   485,   485,  1715,     0,  1245,  1247,  1248,     0,
    1724,  1725,  1252,  1253,     0,     0,  1256,  1257,  1258,  1259,
    1932,  1261,     0,     0,     0,     0,  1267,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1752,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,  1770,  1771,  1772,     0,     0,     0,     0,
       0,     0,     0,     0,  1773,     0,     0,     0,     0,  1776,
    1777,  1778,  1944,     0,     0,     0,  1349,     0,     0,     0,
       0,  1354,     0,  1786,     0,     0,     0,     0,   484,   484,
    1792,     0,  1793,     0,     0,     0,     0,     0,  1801,  1802,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,  1820,     0,     0,  2147,     0,     0,     0,     0,     0,
       0,   485,     0,   485,  1830,     0,     0,  1833,     0,     0,
       0,  1835,     0,     0,     0,  2163,  2165,     0,     0,     0,
    1777,  1778,     0,  1844,     0,     0,     0,     0,     0,  2173,
       0,  1849,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1409,  1862,     0,     0,
       0,     0,  1868,  1869,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,     0,  1875,
    1874,     0,     0,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1909,     0,     0,     0,     0,     0,     0,     0,
       0,  1918,   485,     0,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,  1929,
    1930,     0,     0,   484,     0,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,     0,     0,     0,     0,     0,  1521,  1954,  1955,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1967,     0,     0,   484,
     484,  1972,     0,     0,     0,     0,  1975,     0,     0,  1977,
       0,     0,     0,     0,  1557,     0,     0,     0,     0,   484,
       0,     0,  1753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,  2004,     0,     0,  2057,  1594,  1595,  1596,  1597,
    1598,     0,     0,     0,     0,  1603,  1604,     0,     0,  1606,
       0,  1608,     0,     0,     0,  1612,     0,  2015,  1614,     0,
       0,     0,     0,  2020,     0,     0,  2021,     0,     0,     0,
    1622,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   485,   485,     0,
       0,     0,     0,     0,     0,  2045,     0,     0,     0,     0,
       0,     0,     0,   160,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
    2063,  2064,     0,     0,     0,     0,     0,  2105,     0,     0,
       0,     0,     0,     0,  2070,  2071,     0,  2072,   484,     0,
    1681,     0,  1684,     0,     0,     0,  1691,     0,  1693,     0,
       0,  2081,     0,     0,     0,     0,   484,   484,   484,   484,
     484,     0,     0,     0,     0,     0,  1868,     0,     0,     0,
    2097,  1883,   554,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1718,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2025,     0,     0,     0,  2118,     0,
       0,     0,     0,  2121,  2122,  2123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2151,  2152,  2153,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,   544,
     573,     0,     0,     0,     0,     0,     0,     0,  1779,     0,
       0,     0,   485,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   516,   517,   518,   519,
     520,   521,     0,   523,   524,     0,     0,     0,     0,     0,
     527,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,   537,     0,     0,     0,     0,   485,   485,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,   485,     0,
       0,     0,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,     0,     0,  1859,
       0,     0,  1860,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   794,   569,   570,   571,
     572,     0,     0,     0,     0,   573,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
    1890,  1891,     0,  1893,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   663,   664,
     665,     0,     0,     0,   669,   670,   671,   672,   673,   674,
     675,     0,   676,     0,     0,     0,   677,   678,     0,     0,
     681,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   693,     0,     0,     0,   485,     0,     0,
       0,     0,     0,  1935,  1936,     0,     0,   554,     0,     0,
       0,     0,     0,     0,     0,   485,   485,   485,   485,   485,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,   953,     0,     0,     0,     0,     0,
    1966,     0,   914,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,     6,   366,     0,
       0,     0,     0,   198,   199,   200,   485,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,  1558,
     368,   369,   370,   371,   372,   373,   374,   375,   230,   231,
     232,   233,   376,   377,   378,   379,   234,   235,     0,     0,
     380,   381,   382,     0,     0,   383,     0,   384,   236,   237,
     238,   858,     0,     0,     0,     0,   239,    21,   385,   240,
       0,   386,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,   554,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   387,
     388,   389,   251,   252,     0,     0,     0,   253,   254,   255,
     390,   256,   257,   258,   391,     0,   392,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2140,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,   366,  1559,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   230,   231,
     232,   233,   376,   377,   378,   379,   234,   235,     0,     0,
     380,   381,   382,     0,     0,   383,     0,   384,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,   385,   240,
       0,   386,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,   962,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,  1149,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   794,   569,   570,   571,   572,     0,     0,  1166,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   387,
     388,   389,   251,   252,     0,     0,     0,   253,   254,   255,
     390,   256,   257,   258,   391,     0,   392,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,   155,   366,   263,
     415,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   402,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   230,   231,
     232,   233,   376,   377,   378,   379,   234,     0,     7,     8,
     380,   381,   382,     0,     0,   383,     0,   384,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,   385,   240,
       0,   386,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,  1344,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,    39,    40,    41,    42,     0,     0,    44,
       0,     0,     0,     0,     0,     0,   734,    51,     0,     0,
      54,   735,     0,   736,   737,     0,   738,     0,     0,     0,
       0,   417,     0,     0,     0,     0,     0,  1157,   250,   387,
     388,   389,   251,    74,  1398,     0,     0,   253,   254,   255,
     390,   256,   257,   258,   391,     0,   392,   111,   418,   419,
     420,   421,     0,     0,     0,     0,     0,    88,    89,    90,
       0,     0,     0,   259,   403,     0,     0,     0,     0,     0,
     261,     0,   422,   423,     0,   424,     0,   425,     0,     0,
       0,   426,   264,     0,     0,     0,   197,     6,   346,     0,
       0,     0,     0,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,   922,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,  1522,  1523,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,  1158,     0,     0,
       0,     0,     0,     0,  1610,     0,     0,     0,   250,     0,
       0,     0,   251,   252,  1618,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,   348,
       0,   649,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,  1750,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,  1473,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   483,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,  1655,     0,
     547,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,   263,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,  1797,     0,     0,     0,
    1798,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,  1816,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   615,   197,     6,     0,   309,
     547,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,  1824,     0,     0,     0,
    1825,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   262,   197,     6,     0,   263,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,  1990,     0,     0,     0,
    1991,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,   263,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     751,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   483,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,   542,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     914,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   483,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,     0,
     547,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     915,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   585,   197,     6,     0,   263,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     959,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   592,   197,     6,     0,   263,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1067,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   483,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,   875,
       0,  1331,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,   155,   366,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   367,   368,
     369,   370,   371,   372,   373,   374,   375,     0,     0,     0,
       0,   376,   377,   378,   379,     0,     0,     0,     0,   380,
     381,   382,     0,     0,   383,     0,   384,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   385,   250,     0,
     386,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   483,     0,     0,     0,     0,     0,
     261,   197,     6,     0,     0,   347,  1538,     0,   198,   199,
     200,     0,   264,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,     0,     0,     0,
       0,   234,   235,     0,     0,     0,     0,     0,   387,   388,
     389,     0,     0,   236,   237,   238,     0,     0,     0,   390,
       0,   239,    21,   391,   240,   392,   111,     0,     0,     0,
     241,     0,     0,   242,     0,     0,   243,     0,   244,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,   245,
       0,   396,   366,     0,     0,     0,     0,     0,     0,   246,
       0,    52,    53,     0,   247,     0,   248,     0,     0,   249,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
       0,    69,    70,    71,    72,    73,     0,     0,     0,    77,
       0,     0,    80,   367,   368,   369,   370,   371,   372,   373,
     374,   375,     0,     0,     0,     0,   376,   377,   378,   379,
       0,     0,     0,     0,   380,   381,   382,     0,     0,   383,
       0,   384,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   385,   250,     0,   386,     0,   251,   252,     0,
       0,     0,   253,   254,   255,     0,   256,   257,   258,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   483,
       0,     0,     0,     0,     0,   261,   197,     6,     0,     0,
     347,     0,     0,   198,   199,   200,     0,   264,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,   387,   388,   389,     0,     0,   236,   237,
     238,     0,     0,     0,   390,     0,   239,    21,   391,   240,
     392,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1068,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   260,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   347,   197,     6,     0,  1663,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1069,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,  1816,     0,     0,     0,     0,     0,
     261,     0,     0,     0,     0,   615,   197,     6,     0,   309,
       0,     0,   264,   198,   199,   200,     0,     0,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,     0,     0,     0,   239,    21,     0,   240,
       0,     0,     0,     0,     0,   241,     0,     0,   242,     0,
       0,   243,     0,   244,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   246,     0,    52,    53,     0,   247,
       0,   248,     0,     0,   249,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,    69,    70,    71,    72,
      73,     0,     0,     0,    77,     0,     0,    80,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1070,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,   251,   252,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   259,   483,     0,     0,     0,     0,     0,
     261,   197,   155,   366,     0,   347,     0,     0,   198,   199,
     200,     0,   264,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     402,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   230,   231,   232,   233,   376,   377,   378,
     379,   234,     0,     0,     0,   380,   381,   382,     0,     0,
     383,     0,   384,   236,   237,   238,     0,     0,     0,     0,
       0,   239,    21,   385,   240,     0,   386,   197,   155,   366,
       0,     0,     0,     0,   198,   199,   200,     0,     0,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   402,   219,   220,   221,
     222,   223,   224,     0,     0,     0,     0,     0,     0,     0,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   230,
     231,   232,   233,   376,   377,   378,   379,   234,     0,     0,
       0,   380,   381,   382,     0,     0,   383,     0,   384,   236,
     237,   238,     0,     0,     0,     0,     0,   239,    21,   385,
     240,     0,   386,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   387,   388,   389,   251,     0,     0,
       0,     0,   253,   254,   255,   390,   256,   257,   258,   391,
       0,   392,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   403,
       0,     0,     0,     0,     0,   261,     0,     0,     0,     0,
     347,     0,     0,     0,  1554,     0,     0,   264,     0,     0,
       0,     0,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,   250,
     387,   388,   389,   251,  1108,     0,     0,     0,   253,   254,
     255,   390,   256,   257,   258,   391,     0,   392,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   403,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   347,   197,   155,   366,
    1829,     0,     0,   264,   198,   199,   200,     0,     0,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   402,   219,   220,   221,
     222,   223,   224,     0,     0,     0,     0,     0,     0,     0,
    1558,   368,   369,   370,   371,   372,   373,   374,   375,   230,
     231,   232,   233,   376,   377,   378,   379,   234,     0,     0,
       0,   380,   381,   382,     0,     0,   383,     0,   384,   236,
     237,   238,     0,     0,     0,     0,     0,   239,    21,   385,
     240,     0,   386,   197,   155,   366,     0,     0,     0,     0,
     198,   199,   200,     0,     0,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   402,   219,   220,   221,   222,   223,   224,     0,
       0,     0,     0,     0,     0,     0,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   230,   231,   232,   233,   376,
     377,   378,   379,   234,     0,     0,     0,   380,   381,   382,
       0,     0,   383,     0,   384,   236,   237,   238,     0,     0,
       0,     0,     0,   239,    21,   385,   240,     0,   386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     387,   388,   389,   251,     0,     0,     0,     0,   253,   254,
     255,   390,   256,   257,   258,   391,     0,   392,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   403,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   347,     0,     0,     0,
    1717,     0,     0,   264,     0,     0,     0,     0,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,   250,   387,   388,   389,   251,
    1118,     0,     0,     0,   253,   254,   255,   390,   256,   257,
     258,   391,     0,   392,   111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     259,   403,     0,     0,     0,     0,     0,   261,   197,   155,
       0,     0,   347,     0,     0,   198,   199,   200,     0,   264,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   402,   219,   220,
     221,   222,   223,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,   231,   232,   233,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,   238,     0,     0,   197,   155,     0,   239,    21,
       0,   240,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   402,   219,   220,   221,   222,   223,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   231,   232,
     233,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,   238,
       0,     0,     0,     0,     0,   239,    21,     0,   240,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
     250,  1119,     0,     0,   251,     0,     0,     0,     0,   253,
     254,   255,     0,   256,   257,   258,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   259,   403,     0,     0,     0,
       0,     0,   261,     0,     0,     0,     0,   347,     0,     0,
       0,   595,     0,     0,   264,     0,     0,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,   250,     0,   573,
       0,   251,     0,     0,     0,     0,   253,   254,   255,  1120,
     256,   257,   258,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,     0,     0,     0,     0,     0,   261,
       0,     0,     0,     0,   615,   197,   155,     0,   309,     0,
     843,   264,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   402,   219,   220,   221,   222,   223,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   231,   232,
     233,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,   238,
       0,     0,   197,   155,     0,   239,    21,     0,   240,   198,
     199,   200,     0,     0,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   402,   219,   220,   221,   222,   223,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,   231,   232,   233,     0,     0,
       7,     8,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   237,   238,     0,     0,     0,
       0,     0,   239,    21,     0,   240,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,     0,     0,     0,   250,  1125,     0,
       0,   251,     0,     0,     0,     0,   253,   254,   255,     0,
     256,   257,   258,     0,     0,     0,   111,     0,     0,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,   259,   403,     0,    39,    40,    41,    42,   261,
       0,    44,     0,     0,   347,     0,     0,     0,   734,    51,
       0,   264,    54,   735,     0,   736,   737,     0,   738,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,    74,     0,     0,   251,     0,
       0,     0,     0,   253,   254,   255,     0,   256,   257,   258,
       0,     0,     0,   111,     0,     0,     0,     0,     0,    88,
      89,    90,     0,     0,     0,     0,     0,     0,     0,   259,
     403,     0,     0,     0,     0,     0,   261,   197,   155,     0,
    1281,   347,  1057,     0,   198,   199,   200,     0,   264,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   402,   219,   220,   221,
     222,   223,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
     231,   232,   233,     0,   944,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     237,   238,     0,     0,     0,     0,     0,   239,    21,     0,
     240,   197,   155,     0,  1435,     0,     0,     0,   198,   199,
     200,     0,     0,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     402,   219,   220,   221,   222,   223,   224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,   232,   233,     0,     0,     0,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,   237,   238,     0,     0,     0,     0,
       0,   239,    21,     0,   240,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,   250,
       0,     0,     0,   251,     0,     0,     0,  1126,   253,   254,
     255,     0,   256,   257,   258,     0,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,   403,     0,     0,     0,     0,
       0,   261,     0,     0,     0,     0,   347,     0,     0,     0,
       0,     0,     0,   264,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,     0,   250,     0,     0,  1128,   251,     0,     0,
       0,     0,   253,   254,   255,     0,   256,   257,   258,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   259,   403,
       0,     0,     0,     0,     0,   261,   197,   155,     0,  1497,
     347,     0,     0,   198,   199,   200,     0,   264,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   402,   219,   220,   221,   222,
     223,   224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,   231,
     232,   233,     0,     0,     0,     0,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,     0,   197,   155,     0,   239,    21,     0,   240,
     198,   199,   200,     0,     0,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   402,   219,   220,   221,   222,   223,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,   231,   232,   233,     0,
       0,     7,     8,   234,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   237,   238,     0,     0,
       0,     0,     0,   239,    21,     0,   240,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,   250,  1234,
       0,     0,   251,     0,     0,     0,     0,   253,   254,   255,
       0,   256,   257,   258,     0,     0,     0,   111,     0,     0,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,   259,   403,     0,    39,    40,    41,    42,
     261,     0,    44,     0,     0,   347,     0,     0,     0,   734,
      51,     0,   264,    54,   735,     0,   736,   737,     0,   738,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,    74,     0,     0,   251,
       0,     0,     0,     0,   253,   254,   255,     0,   256,   257,
     258,     0,     0,     0,   111,     0,     0,     0,     0,     0,
      88,    89,    90,     0,     0,     0,     0,     0,     0,     0,
     259,   403,     0,     0,     0,     0,     0,   261,   197,   155,
       0,     0,   347,  1553,     0,   198,   199,   200,     0,   264,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   402,   219,   220,
     221,   222,   223,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,   231,   232,   233,     0,   991,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,   238,     0,     0,   197,   155,     0,   239,    21,
       0,   240,   198,   199,   200,     0,     0,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   402,   219,   220,   221,   222,   223,
     224,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   231,   232,
     233,     0,     0,     7,     8,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,   238,
       0,     0,     0,     0,     0,   239,    21,     0,   240,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
     250,  1255,     0,     0,   251,     0,     0,     0,     0,   253,
     254,   255,     0,   256,   257,   258,     0,     0,     0,   111,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,   259,   403,     0,    39,    40,
      41,    42,   261,     0,    44,     0,     0,   347,  1876,     0,
       0,   734,    51,     0,   264,    54,   735,     0,   736,   737,
       0,   738,     0,     7,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,    74,     0,
       0,   251,     0,     0,     0,     0,   253,   254,   255,     0,
     256,   257,   258,     0,     0,     0,   111,     0,     0,     0,
       0,     0,    88,    89,    90,     0,     0,     0,     0,     0,
       0,     0,   259,   403,     0,     0,     0,     0,     0,   261,
       7,     8,     0,     0,   347,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,    39,    40,
      41,    42,     0,     0,    44,     0,     0,     0,     0,     0,
       0,   734,    51,     0,     0,    54,   735,   993,   736,   737,
       0,   738,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,     0,     0,    39,    40,    41,    42,     0,
       0,    44,    88,    89,    90,     0,     0,     0,   734,    51,
       0,     0,    54,   735,     0,   736,   737,     0,   738,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    88,
      89,    90,    39,    40,    41,    42,     0,     0,    44,     0,
       0,     0,     0,     0,     0,   734,    51,  1188,     0,    54,
     735,     0,   736,   737,     0,   738,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,     0,     0,    39,
      40,    41,    42,     0,     0,    44,    88,    89,    90,     0,
       0,     0,   734,    51,  1190,     0,    54,   735,     0,   736,
     737,     0,   738,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    88,    89,    90,    39,    40,    41,    42,
       0,     0,    44,     0,     0,     0,     0,     0,     0,   734,
      51,  1191,     0,    54,   735,     0,   736,   737,     0,   738,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,    39,    40,    41,    42,     0,     0,    44,
      88,    89,    90,     0,     0,     0,   734,    51,  1210,     0,
      54,   735,     0,   736,   737,     0,   738,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    88,    89,    90,
      39,    40,    41,    42,     0,     0,    44,     0,     0,     0,
       0,     0,     0,   734,    51,  1240,     0,    54,   735,     0,
     736,   737,     0,   738,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     0,     0,     0,    39,    40,    41,
      42,     0,     0,    44,    88,    89,    90,     0,     0,     0,
     734,    51,  1273,     0,    54,   735,     0,   736,   737,     0,
     738,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    88,    89,    90,    39,    40,    41,    42,     0,     0,
      44,     0,     0,     0,     0,     0,     0,   734,    51,  1427,
       0,    54,   735,     0,   736,   737,     0,   738,    -4,     1,
       0,     0,    -4,     0,     0,     0,     0,     0,     0,     0,
       0,    -4,    -4,     0,    74,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,    88,    89,
      90,     0,    -4,    -4,     0,     0,  2048,  1340,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -4,    -4,    -4,     0,     0,     0,    -4,    -4,
       0,    -4,     0,     0,     0,     0,    -4,    -4,     0,    -4,
      -4,     0,    -4,     0,     0,     0,     0,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,     0,     0,    -4,    -4,    -4,    -4,    -4,
      -4,     0,    -4,  2107,    -4,    -4,    -4,    -4,    -4,    -4,
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
      17,    18,     0,    19,    20,     0,    21,     0,     0,     0,
       0,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     0,     0,    38,
      39,    40,    41,    42,    43,     0,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    83,    84,    85,     0,     0,     0,    86,     0,
       0,     0,     0,    87,    88,    89,    90,   155,   366,    91,
       0,    92,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,   107,   108,   109,     0,     0,   366,     0,
       0,     0,     0,     0,   110,     0,   111,     0,     0,   367,
     368,   369,   370,   371,   372,   373,   374,   375,     0,     7,
       8,     0,   376,   377,   378,   379,     0,     0,     0,     0,
     380,   381,   382,     0,     0,   383,     0,   384,     0,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   385,     0,
       0,   386,   376,   377,   378,   379,     0,     0,     0,     0,
     380,   381,   382,     0,     0,   383,     0,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   385,     0,
       0,   386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     0,     0,     0,    39,    40,    41,    42,     0,     0,
      44,     0,     0,     0,     0,     0,     0,   734,    51,     7,
       8,    54,   735,     0,   736,   737,     0,   738,     0,     0,
       0,  1002,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,     0,     0,  1003,   387,
     388,   389,     0,     0,     0,     0,     0,     0,     0,     0,
     390,     0,     0,     0,   391,     0,   392,   111,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,   387,
     388,   389,     0,     0,     0,     0,     0,     0,     0,     0,
     390,     0,     0,     0,   391,     0,   392,     0,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     0,     0,     0,    39,    40,    41,    42,     0,     0,
      44,     0,     0,     0,     0,     0,     0,   734,    51,     0,
       0,    54,   735,     0,   736,   737,     0,   738,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,    88,    89,
      90,     0,     0,     0,     0,     0,     0,  1429,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1430,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1472,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1599,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1600,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1601,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1615,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1745,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1863,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1864,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1892,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1895,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1962,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2016,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2017,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2031,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2033,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2066,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2094,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2099,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2100,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2101,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2141,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,   791,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,  1039,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
    1095,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,  1138,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,     0,     0,     0,     0,  1139,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,  1182,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,  1213,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,  1231,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,  1287,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,     0,     0,  1387,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,  1431,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,  1503,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
    1504,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,  1505,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,     0,     0,     0,     0,  1506,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,  1795,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,  1806,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,  1843,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,  1912,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,     0,     0,  1927,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,  1939,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
       0,  1996,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,     0,     0,
    2005,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,     0,  2006,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,     0,     0,     0,     0,  2029,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,  2080,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,     0,     0,  2120,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,  2139,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,     0,     0,  2159,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,     0,     0,  2160,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
       0,     0,  2161,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,     0,
     696,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,     0,   906,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,  1905,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,   721,     0,   722,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
     965,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,  1016,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,  1162,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,  1226,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,  1227,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,  1232,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   695,
     569,   570,   571,   572,     0,     0,     0,     0,   573,     0,
       0,     0,  1233,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   695,   569,   570,   571,
     572,     0,     0,     0,     0,   573,     0,     0,     0,  1323,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   695,   569,   570,   571,   572,     0,     0,
       0,     0,   573,     0,     0,     0,  1337,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     695,   569,   570,   571,   572,     0,     0,     0,     0,   573,
       0,     0,     0,  1535,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,     0,     0,
    1621,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   695,   569,   570,   571,   572,     0,
       0,     0,     0,   573,     0,     0,     0,  1669,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   695,   569,   570,   571,   572,     0,     0,     0,     0,
     573,     0,     0,     0,  1855,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   695,   569,
     570,   571,   572,     0,     0,     0,     0,   573,     0,     0,
       0,  1897,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   695,   569,   570,   571,   572,
       0,     0,     0,     0,   573,     0,     0,     0,  1913,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   772,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   773,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   774,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   776,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   777,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   778,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   780,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   781,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   782,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   783,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   784,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   785,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   786,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   788,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   789,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   790,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   855,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   890,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   935,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   953,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   955,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   956,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   957,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,   963,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,   964,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1001,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1015,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1075,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1079,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1091,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1161,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1171,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1172,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1173,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1183,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1212,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1214,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1215,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1216,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1217,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1218,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1219,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1220,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1225,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1322,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1336,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1536,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1566,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1567,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1568,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1569,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1607,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1620,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1732,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1734,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1737,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1744,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1796,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1805,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1828,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1896,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  1960,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  1961,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573,     0,  2093,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   695,   569,   570,   571,   572,     0,     0,     0,
       0,   573,     0,  2136,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   695,   569,   570,
     571,   572,     0,     0,     0,     0,   573
};

static const yytype_int16 yycheck[] =
{
       3,     3,     3,  1211,   137,   716,   189,   700,   302,   610,
     611,   150,  1207,   724,    58,     6,     4,  1393,    21,  1700,
       4,  1702,     4,    50,    21,     4,   186,     4,     4,     4,
    1687,     4,     6,   314,   194,     6,   132,     5,   731,     4,
       4,     4,     4,  1877,  1657,     6,     6,    50,    98,     5,
       5,   332,     0,     5,     7,   748,    57,     4,     4,     6,
       4,   152,    98,   756,   230,   231,   230,   231,     9,     6,
      92,   121,   235,   236,     4,    78,     7,     9,   241,   230,
     231,   247,    98,    86,   180,   121,   177,   251,    91,   111,
       4,   239,   240,  1750,     9,     9,   279,   280,    92,   102,
     251,    95,   193,   194,    98,     9,   230,   231,    84,   230,
     231,   230,   231,     7,   230,   231,     9,   111,   399,   102,
     401,   104,   242,     9,   284,   285,   286,   251,   409,   242,
     251,   244,   251,   246,   137,   251,   138,   230,   231,   142,
     143,     6,   230,   231,    14,    92,   243,   150,   230,   231,
       6,   248,     6,     6,   137,     7,  1769,     6,   251,     7,
     230,   231,   165,   251,   857,   325,   326,   327,   195,   251,
     246,   101,   102,    95,   250,   242,    98,   160,   181,   230,
     231,   251,   342,   186,   242,     7,   189,   230,   231,   111,
    2024,   194,   195,   196,   167,   168,   169,   170,   239,   240,
     251,   230,   231,   248,   165,   165,   251,   248,   251,   230,
     231,     7,   188,   177,   178,   177,   178,     7,   244,   246,
     230,   231,   251,   243,   407,   246,   214,   192,     6,     7,
     214,   251,   230,   231,   235,   214,  1612,   214,   214,   214,
     245,   251,     6,   246,   136,   137,   251,   248,   249,   244,
     142,   242,  1447,   251,     6,   246,   283,   260,   246,     6,
     263,   264,   244,     6,   243,   249,   245,   264,   250,   296,
     246,   246,   246,   300,   247,   246,   279,   280,   246,   242,
     283,   284,   285,   286,   215,   216,   217,   218,   242,  1902,
     246,   246,   246,   296,   246,   248,   242,   300,   242,   302,
     214,   242,     6,   244,  1015,  1016,     4,   248,   239,   240,
     242,     6,   244,    64,    65,   242,    67,   248,   599,   246,
     601,   602,   325,   326,   327,   239,   240,   242,   242,   244,
     244,   242,   246,   248,   248,   239,   240,   618,   242,   342,
     244,   245,   242,  1956,   248,   348,   239,   240,   242,   242,
     244,   244,   242,   239,   240,   248,   242,   242,   244,   542,
     225,   226,   248,   215,   216,   217,   218,   215,   216,   217,
     218,   225,   226,   533,   230,   231,   657,   230,   231,  2060,
       4,   230,   231,   242,   411,   412,   525,   239,   240,   230,
     231,   239,   240,   215,   216,   217,   218,   242,   242,   244,
     427,   136,   137,   406,   407,   242,   251,   142,   411,   412,
     251,   594,   595,   230,   231,   696,   242,   239,   240,   215,
     216,   217,   218,   242,   427,   215,   216,   217,   218,   243,
     433,   245,   415,   242,   251,   244,   437,   251,   136,   137,
     138,   139,   230,   231,   132,   230,   231,    95,   230,   231,
      98,   454,  1145,   151,  1147,   242,   154,   640,   641,   642,
     132,   149,   242,   251,   246,   242,   251,  1160,    92,   157,
     158,   159,    96,   230,   231,   163,   164,   149,   102,   103,
     483,   105,   106,  2096,   245,   157,   158,   159,   230,   231,
     251,   163,   164,   242,   251,   522,   242,    95,   230,   231,
      98,   125,   100,   686,   507,   532,   242,   534,   244,   251,
     242,   514,   515,   111,   246,   242,   519,  1893,   521,   522,
     523,   524,   525,   230,   231,   528,   665,     6,     7,   532,
     533,   534,   535,   536,   537,   538,  2149,   540,   243,   542,
     723,   538,    95,   540,   251,    98,   251,   100,   230,   231,
     230,   231,   113,   247,   305,   306,   539,   251,    98,   247,
     242,   744,   313,   314,   246,   568,   246,   750,   246,   132,
      92,   574,   132,    95,    92,  1268,    98,    95,   100,   243,
      98,  1274,   100,   716,   247,   132,   149,   251,   251,   149,
       6,   594,   595,   111,   157,   158,   159,   157,   158,   159,
     163,   164,   149,   163,   164,   243,   243,   245,   610,   611,
     157,   158,   159,   251,   251,   616,   163,   164,   243,   230,
     231,   232,   233,   234,   235,   236,   251,   246,  1321,   910,
     241,   232,   233,   234,   235,   236,   637,   640,   641,   642,
     241,   100,  1335,   242,   246,   244,   829,    92,  1341,   248,
      95,   243,   251,    98,   242,   100,   244,   242,   246,   251,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   242,
     673,   674,   675,   676,   677,   246,   679,   680,   681,   682,
     683,   243,   246,   686,   247,   682,   713,   247,   689,   251,
     242,   692,   875,   737,   697,   678,   230,   231,   247,   243,
     247,   245,   251,   704,   243,   888,   245,   251,   246,  1420,
     713,   243,   251,   245,   247,   239,   240,    98,   251,   251,
     723,     8,   246,   906,   247,   728,   239,   240,   251,    98,
     247,   100,   247,   246,   251,   736,   251,   738,    95,   247,
     247,   744,   745,   251,   251,   247,   242,   750,   247,   251,
     753,   754,   251,   886,    98,   248,   759,   250,   761,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     4,     5,   247,   247,   241,   247,   251,   251,
     247,   251,    95,   247,   251,   247,   247,   251,   771,   251,
     251,   794,   247,   796,    95,   247,   251,   247,  1509,   251,
     247,   251,     4,   247,   251,   247,    98,   251,   247,   251,
    1521,   243,   251,   245,    46,    47,    48,    49,    50,    51,
      52,    53,    54,   242,     4,   244,   829,    59,    60,    61,
      62,   242,     4,   244,   247,    67,    68,    69,   251,   247,
      72,  2049,    74,   251,   247,   247,   247,   247,   251,   251,
     251,   251,   242,    85,   244,  1038,    88,   608,   609,   247,
     247,   247,   613,   251,   251,   251,   242,   247,   244,   247,
     897,   251,   875,   251,   247,   247,   247,   247,   251,   251,
     251,   251,  1015,  1016,   247,   888,   247,  2082,   251,   242,
     251,   247,     4,     8,   897,   251,   128,   247,   247,   242,
    2108,   251,   251,   906,   243,   242,   245,   246,   909,  1092,
     911,   912,   247,   242,   247,   247,   251,   900,   251,   251,
     242,   247,   247,   247,   925,   251,   251,   251,     4,     6,
       6,  2126,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       6,   247,   247,   247,   241,   251,   251,   251,   247,   960,
     247,   244,   251,   242,   196,   197,   198,   243,   246,   245,
     246,   244,     6,   250,   246,   207,     6,   242,     9,   211,
    1007,   213,   214,   250,   242,   242,  1169,  1170,   242,   242,
     242,   242,   242,   180,   242,   996,   242,   246,   180,  1026,
     121,   180,   246,   242,  1007,   242,   242,   239,   240,  1303,
     180,   242,   246,   242,   246,   242,   248,     4,  1021,   242,
     246,   246,   246,  1026,   246,   246,   242,   242,  1161,  1162,
     242,   242,   242,   242,  1017,  1038,   242,     6,     6,   244,
    1043,  1642,  1643,     6,   244,   246,  1073,  1074,   246,  1076,
    1077,  1078,   246,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1246,     6,   246,   244,   244,     6,     6,
    1073,  1074,   246,  1076,  1077,  1078,   180,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,   242,   242,  1092,
     242,   242,   242,   242,     6,     6,   244,     6,     8,   246,
       6,     8,   246,  1130,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     7,     6,   246,  1152,   241,  1130,  1131,  1132,
       6,   247,   247,   246,    87,   243,     7,   251,     6,     6,
     251,  1168,   243,   246,   246,  1328,   241,  1330,   248,  1152,
      64,     8,     4,     7,     7,   242,     6,   243,     6,   247,
       7,   246,   913,     6,     6,  1168,  1169,  1170,     7,   920,
       6,   177,   246,   924,   247,   247,   245,   243,     6,   246,
     248,   246,   246,   246,     7,     6,   244,   242,  1189,  1322,
    1323,     4,   246,   243,  1221,     6,     6,     6,     6,   244,
       7,     7,     7,     7,     7,     7,     7,     7,  1235,  1236,
    1237,     7,     7,     7,     7,  1496,     7,     7,  1221,  1500,
       7,     7,  1516,   246,     6,   243,   245,   251,     7,   251,
     251,   247,  1235,  1236,  1237,   243,   251,   246,   248,     7,
     247,   246,   246,  1246,     4,     6,   248,   247,  1251,   247,
     132,     7,  1255,     6,   248,     7,     7,  1284,     7,   243,
     243,  1264,   251,  1266,     9,   251,  1269,   243,   245,   251,
     248,   250,   180,     7,   152,   247,  1459,  1278,     6,   246,
       6,  1284,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
    1303,     6,     4,    46,   241,    46,   242,  1908,   248,   242,
       4,   246,   246,   242,   242,     7,   248,   248,  1345,     7,
    1323,  1072,     7,   243,   251,  1328,     7,  1330,     7,   180,
       7,  1358,     6,   251,     7,  1362,     7,     7,   243,     4,
     110,     4,  1345,   246,     6,   242,     7,     6,   246,     7,
       7,     7,     7,     7,     7,  1358,     7,     6,     6,  1362,
    1343,     6,  1345,    98,     7,     6,     4,     6,     8,     4,
     249,   251,   246,   243,   251,   247,  1509,   246,     6,     6,
     246,     6,     6,  1522,  1523,     7,   244,  1414,  1415,  1416,
       6,   246,     6,   242,     6,  1422,   242,     6,     6,     6,
     125,     6,   247,     6,   248,   245,     6,     6,     6,     6,
    1437,  1414,  1415,  1416,   251,     4,     5,   243,     6,  1422,
    1714,  1448,     6,     6,     6,     6,     6,     5,   243,  1456,
       6,     4,     6,     4,  1437,     7,     6,     6,     6,     6,
       6,     6,     6,   176,     6,  1448,     6,   246,   246,   246,
       6,  1634,  1635,  1456,   246,   244,  1459,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   246,   251,   246,   246,
      59,    60,    61,    62,   246,   246,   251,   246,    67,    68,
      69,   246,   246,    72,   243,    74,  1619,     7,   251,   246,
       4,   246,   242,   251,   248,     6,    85,     6,     6,    88,
     247,  1528,     6,   242,     4,   242,     7,     6,     6,  1492,
       6,     6,     6,  1516,     6,     6,     6,    96,     6,  1522,
    1523,     5,   246,   243,   251,  1528,     6,  1554,   246,   246,
       6,     6,   251,     6,     6,   251,     6,     8,   251,   128,
     243,     6,     4,  1546,   251,     6,     6,   246,     6,     6,
       6,  1554,     6,   246,     7,   246,  1559,   246,     5,   246,
     243,     6,     6,     6,   246,     6,   246,     6,     6,   247,
       7,  1554,   247,   175,   246,     6,   243,     6,  1717,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,  1730,  1781,  1782,
     247,   241,     7,   243,  1631,   245,     6,   196,   197,   198,
     247,   247,     6,     6,   248,     6,   246,     6,   207,     6,
       6,   247,   211,   243,   213,   214,     6,   246,  1631,     6,
    1657,  1634,  1635,   178,     6,   246,  1917,   247,     6,     6,
    1642,  1643,   243,   247,     6,  1672,  1829,   242,     6,   132,
     246,  1945,   246,   246,  1657,  1638,   246,   246,     6,   246,
    1663,   247,     6,     6,     6,     6,   243,     6,     6,  1672,
       6,   246,     6,     6,     6,     6,  1703,     6,     6,  1682,
       6,     6,  1685,     6,   247,   246,   137,     6,   247,  1716,
       6,   142,   143,   246,   246,  1446,     6,  1680,  1334,  1700,
    1703,  1702,  1885,  1886,  1687,  1688,  2062,  1710,  1878,   451,
    1840,  1714,  1388,  1716,  1717,  1627,  1357,  1564,     3,     3,
       3,     3,  1905,  1706,   589,  1904,  1489,     3,  1687,  2010,
     181,  1523,  1710,   753,    -1,    -1,    -1,  1920,    -1,    -1,
      -1,    -1,  1769,    -1,     6,   196,    -1,  1750,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,  1769,    -1,    -1,  2050,
     241,    -1,   243,    -1,    -1,    -1,    -1,  1804,  1781,  1782,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     6,    -1,
      -1,  1804,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1816,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1572,    -1,    -1,    -1,    -1,  1829,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1866,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2034,  1879,    -1,    -1,    -1,    -1,    -1,    -1,  1842,
      -1,    -1,    -1,  1866,    -1,    -1,    -1,    -1,    -1,  2052,
    2053,  2054,  2055,  2056,    -1,  1902,  1879,    -1,    -1,    -1,
      -1,  1884,  1885,  1886,    -1,    -1,    -1,    -1,    -1,  1916,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1902,
    1883,    -1,  1905,    -1,    -1,    -1,  1908,  1658,  1659,  1660,
    1661,  1662,  1663,  1916,    -1,    -1,    -1,  1920,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1956,
    2113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1945,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1956,    -1,   406,  1983,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
    1983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1995,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     6,
      -1,  2034,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2025,    -1,    -1,    -1,    -1,    -1,    -1,  2052,
    2053,  2054,  2055,  2056,    -1,    -1,    -1,    -1,    -1,  2060,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,  2096,
     521,    -1,   523,   524,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2083,    -1,   535,   536,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2096,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
    2113,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2149,    -1,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2149,    -1,    -1,    -1,
      -1,   137,    -1,  2156,  2157,   141,    -1,    -1,    -1,   145,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2170,     6,    -1,
    1921,  1922,  1923,  1924,  1925,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,   170,   171,   172,    -1,   174,   175,
     176,   177,   178,   179,   180,    -1,   182,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   664,    -1,   666,   667,   668,   669,   670,
     671,    -1,   673,   674,   675,   676,    -1,    -1,   679,   680,
     681,  1982,    -1,    -1,    -1,  1986,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   259,   260,   261,   262,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2036,    -1,    -1,    -1,  2040,
      -1,    -1,   278,   279,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   753,    -1,    -1,  2056,    -1,    -1,    -1,    -1,
     761,    -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   308,   309,    -1,    -1,    -1,    -1,   314,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2103,  2104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   347,   348,    -1,    -1,    -1,   352,   353,   354,    -1,
     356,    -1,    -1,    -1,   360,   361,   362,    -1,    -1,   365,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,
      -1,   407,   408,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   424,   425,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     456,   457,   458,   459,    -1,    -1,    -1,    -1,   464,    -1,
      -1,    -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   482,   483,    -1,    -1,
      -1,   487,    -1,    -1,    -1,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
      -1,   517,   518,    -1,   520,    -1,    -1,    -1,    -1,    -1,
      -1,   527,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,
      -1,   537,   189,    -1,    -1,    -1,   542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,    -1,   575,
     576,    -1,  1043,    -1,    -1,    -1,    -1,   583,   584,   585,
      -1,    -1,    -1,    -1,    -1,   591,   592,    -1,   594,   595,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,   263,   613,   614,   615,
      -1,    -1,    -1,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   279,   280,    -1,    -1,   632,    -1,   634,    -1,
     636,    -1,    -1,    -1,   640,   641,   642,   643,    -1,   645,
     646,   647,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
    1131,  1132,    -1,    -1,   241,    -1,   672,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,
     686,    -1,    -1,    -1,    -1,    -1,    -1,   693,    -1,   695,
      -1,   348,   698,   699,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   707,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,    -1,    -1,
      -1,    -1,    -1,   729,   730,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   744,    -1,
     746,   747,    -1,    -1,   750,   751,    -1,    -1,    -1,   755,
     407,    -1,    -1,    -1,    -1,    -1,   762,     4,     5,    -1,
     766,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
    1251,    -1,    -1,   241,  1255,    -1,   792,    -1,   794,    -1,
     796,    -1,    -1,  1264,    -1,  1266,    -1,    -1,  1269,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,   829,     6,    72,   483,    74,    -1,    -1,
      -1,    -1,    -1,   839,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,    -1,  1323,    -1,    -1,    -1,    -1,   514,   515,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   875,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     537,   128,   888,    -1,    -1,   542,    -1,    -1,    -1,    -1,
     896,    -1,    -1,    -1,   900,    -1,    -1,    -1,    -1,    -1,
     906,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,   915,
      -1,   568,    -1,    -1,   920,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     936,    -1,    -1,   939,    -1,    -1,    -1,   594,   595,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,   198,    -1,   959,    -1,   961,   962,    -1,    -1,    -1,
     207,     6,    -1,    -1,   211,    -1,   213,   214,    -1,    -1,
      -1,    -1,    -1,    -1,   980,    -1,    -1,    -1,    -1,   429,
      -1,    -1,    -1,   640,   641,   642,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,  1003,   245,   246,
      -1,    -1,    -1,    -1,  1010,  1011,  1012,  1013,    -1,    -1,
      -1,    -1,  1018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1032,  1033,    -1,   686,
      -1,    -1,  1038,    -1,    -1,    -1,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,  1067,  1068,  1069,  1070,    -1,   723,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1546,    -1,    -1,   528,     6,
      -1,    -1,    -1,    -1,    -1,    -1,  1092,   744,    -1,    -1,
      -1,    -1,    -1,   750,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1118,  1119,  1120,    -1,    -1,    -1,    -1,  1125,
    1126,    -1,  1128,    -1,    -1,    -1,    -1,    -1,    -1,   579,
      -1,    -1,    -1,    -1,  1140,  1141,    -1,   794,    -1,   796,
      -1,    -1,  1148,  1149,    -1,    -1,    -1,    -1,    -1,  1155,
      -1,  1157,  1158,    -1,    -1,    -1,    -1,    -1,  1164,  1165,
      -1,    -1,    -1,  1169,  1170,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   829,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,  1201,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1682,    -1,    -1,  1685,    -1,    -1,    -1,   875,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1234,    -1,
      -1,   888,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1254,   906,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,  1275,
    1276,    -1,    -1,   241,  1280,   243,     6,   245,    -1,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,  1294,    -1,
      -1,  1297,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,  1324,    -1,
      -1,  1327,  1328,  1329,  1330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1338,    -1,  1340,    -1,  1342,  1343,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   801,   802,   803,   804,   805,   806,   807,   808,   809,
     810,   811,    -1,   813,   814,   815,   816,    -1,   818,   819,
     820,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1038,   832,    -1,   834,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   842,    -1,    -1,    -1,    -1,    -1,    -1,   849,
     850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   858,    -1,
      -1,    -1,    -1,    -1,    -1,  1421,    -1,    -1,    -1,    -1,
      -1,    -1,  1428,  1429,  1430,    -1,    -1,    -1,    -1,    -1,
      -1,  1437,    -1,  1439,    -1,  1092,    -1,    -1,    -1,    -1,
    1446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1459,    -1,    -1,    -1,    -1,  1464,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1472,  1473,  1474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1494,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,  1169,  1170,  1520,    -1,   966,   967,   968,    -1,
    1526,  1527,   972,   973,    -1,    -1,   976,   977,   978,   979,
       6,   981,    -1,    -1,    -1,    -1,   986,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1559,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1246,
      -1,    -1,    -1,  1599,  1600,  1601,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1610,    -1,    -1,    -1,    -1,  1615,
    1616,  1617,     6,    -1,    -1,    -1,  1066,    -1,    -1,    -1,
      -1,  1071,    -1,  1629,    -1,    -1,    -1,    -1,  1634,  1635,
    1636,    -1,  1638,    -1,    -1,    -1,    -1,    -1,  1644,  1645,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1663,    -1,    -1,
      -1,  1667,    -1,    -1,  2135,    -1,    -1,    -1,    -1,    -1,
      -1,  1328,    -1,  1330,  1680,    -1,    -1,  1683,    -1,    -1,
      -1,  1687,    -1,    -1,    -1,  2156,  2157,    -1,    -1,    -1,
    1696,  1697,    -1,  1699,    -1,    -1,    -1,    -1,    -1,  2170,
      -1,  1707,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1166,  1723,    -1,    -1,
      -1,    -1,  1728,  1729,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1742,    -1,    -1,  1745,
    1746,    -1,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1781,  1782,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1807,  1459,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1816,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1825,
    1826,    -1,    -1,  1829,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1306,  1863,  1864,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1882,    -1,    -1,  1885,
    1886,  1887,    -1,    -1,    -1,    -1,  1892,    -1,    -1,  1895,
      -1,    -1,    -1,    -1,  1344,    -1,    -1,    -1,    -1,  1905,
      -1,    -1,  1559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1920,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1928,    -1,    -1,     6,  1376,  1377,  1378,  1379,
    1380,    -1,    -1,    -1,    -1,  1385,  1386,    -1,    -1,  1389,
      -1,  1391,    -1,    -1,    -1,  1395,    -1,  1953,  1398,    -1,
      -1,    -1,    -1,  1959,    -1,    -1,  1962,    -1,    -1,    -1,
    1410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1634,  1635,    -1,
      -1,    -1,    -1,    -1,    -1,  1991,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,
    2016,  2017,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,  2030,  2031,    -1,  2033,  2034,    -1,
    1480,    -1,  1482,    -1,    -1,    -1,  1486,    -1,  1488,    -1,
      -1,  2047,    -1,    -1,    -1,    -1,  2052,  2053,  2054,  2055,
    2056,    -1,    -1,    -1,    -1,    -1,  2062,    -1,    -1,    -1,
    2066,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1522,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,    -1,    -1,    -1,  2094,    -1,
      -1,    -1,    -1,  2099,  2100,  2101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2113,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1781,  1782,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2141,  2142,  2143,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,  1816,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1618,    -1,
      -1,    -1,  1829,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    -1,   232,   233,    -1,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,    -1,    -1,    -1,  1885,  1886,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,  1905,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1920,    -1,    -1,    -1,    -1,    -1,  1719,
      -1,    -1,  1722,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
    1770,  1771,    -1,  1773,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,   368,
     369,    -1,    -1,    -1,   373,   374,   375,   376,   377,   378,
     379,    -1,   381,    -1,    -1,    -1,   385,   386,    -1,    -1,
     389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   402,    -1,    -1,    -1,  2034,    -1,    -1,
      -1,    -1,    -1,  1833,  1834,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2052,  2053,  2054,  2055,  2056,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,
    1880,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,  2113,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,   550,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,   213,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2122,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,     5,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      -1,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,     8,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,   853,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,   887,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,   198,   199,   200,    -1,    -1,    -1,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,   213,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,     5,   246,
       7,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    13,    14,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,
      -1,    88,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,  1060,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
     125,   126,    -1,   128,   129,    -1,   131,    -1,    -1,    -1,
      -1,   188,    -1,    -1,    -1,    -1,    -1,     8,   195,   196,
     197,   198,   199,   148,  1153,    -1,    -1,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,   172,   173,   174,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,   239,   240,    -1,   242,    -1,   244,    -1,    -1,
      -1,   248,   249,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,   247,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,  1307,  1308,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,  1393,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,  1403,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,     8,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,  1558,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,     5,    -1,
     247,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
     247,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,    -1,
     247,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,     8,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,   195,    -1,
      88,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,     3,     4,    -1,    -1,   242,     8,    -1,    10,    11,
      12,    -1,   249,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,   196,   197,
     198,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,   207,
      -1,    83,    84,   211,    86,   213,   214,    -1,    -1,    -1,
      92,    -1,    -1,    95,    -1,    -1,    98,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,    -1,   111,
      -1,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,   123,   124,    -1,   126,    -1,   128,    -1,    -1,   131,
      -1,    -1,    -1,    -1,   136,   137,   138,   139,   140,    -1,
      -1,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
      -1,    -1,   154,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,   195,    -1,    88,    -1,   199,   200,    -1,
      -1,    -1,   204,   205,   206,    -1,   208,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,   237,     3,     4,    -1,    -1,
     242,    -1,    -1,    10,    11,    12,    -1,   249,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,   196,   197,   198,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,   207,    -1,    83,    84,   211,    86,
     213,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,    -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,
      -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,    -1,
      -1,    98,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,    -1,   126,
      -1,   128,    -1,    -1,   131,    -1,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,    -1,    -1,   154,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,   199,   200,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,
     237,     3,     4,     5,    -1,   242,    -1,    -1,    10,    11,
      12,    -1,   249,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    -1,    88,     3,     4,     5,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,   213,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,   246,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   195,
     196,   197,   198,   199,   251,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,   213,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,   242,     3,     4,     5,
     246,    -1,    -1,   249,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    -1,    72,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    -1,    88,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    68,    69,
      -1,    -1,    72,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,   197,   198,   199,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,   213,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,   195,   196,   197,   198,   199,
     251,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,   213,   214,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   231,    -1,    -1,    -1,    -1,    -1,   237,     3,     4,
      -1,    -1,   242,    -1,    -1,    10,    11,    12,    -1,   249,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,     3,     4,    -1,    83,    84,
      -1,    86,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   251,    -1,    -1,   199,    -1,    -1,    -1,    -1,   204,
     205,   206,    -1,   208,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,   231,    -1,    -1,    -1,
      -1,    -1,   237,    -1,    -1,    -1,    -1,   242,    -1,    -1,
      -1,   246,    -1,    -1,   249,    -1,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,   195,    -1,   241,
      -1,   199,    -1,    -1,    -1,    -1,   204,   205,   206,   251,
     208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,   237,
      -1,    -1,    -1,    -1,   242,     3,     4,    -1,   246,    -1,
       8,   249,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,     3,     4,    -1,    83,    84,    -1,    86,    10,
      11,    12,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,
      13,    14,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    86,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   251,    -1,
      -1,   199,    -1,    -1,    -1,    -1,   204,   205,   206,    -1,
     208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   230,   231,    -1,   108,   109,   110,   111,   237,
      -1,   114,    -1,    -1,   242,    -1,    -1,    -1,   121,   122,
      -1,   249,   125,   126,    -1,   128,   129,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   148,    -1,    -1,   199,    -1,
      -1,    -1,    -1,   204,   205,   206,    -1,   208,   209,   210,
      -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
     231,    -1,    -1,    -1,    -1,    -1,   237,     3,     4,    -1,
       6,   242,   243,    -1,    10,    11,    12,    -1,   249,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    -1,   247,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,
      86,     3,     4,    -1,     6,    -1,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    83,    84,    -1,    86,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,   195,
      -1,    -1,    -1,   199,    -1,    -1,    -1,   251,   204,   205,
     206,    -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,
      -1,   237,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    -1,    -1,   251,   199,    -1,    -1,
      -1,    -1,   204,   205,   206,    -1,   208,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,   237,     3,     4,    -1,     6,
     242,    -1,    -1,    10,    11,    12,    -1,   249,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,     3,     4,    -1,    83,    84,    -1,    86,
      10,    11,    12,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    -1,
      -1,    13,    14,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    86,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   251,
      -1,    -1,   199,    -1,    -1,    -1,    -1,   204,   205,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   230,   231,    -1,   108,   109,   110,   111,
     237,    -1,   114,    -1,    -1,   242,    -1,    -1,    -1,   121,
     122,    -1,   249,   125,   126,    -1,   128,   129,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   148,    -1,    -1,   199,
      -1,    -1,    -1,    -1,   204,   205,   206,    -1,   208,   209,
     210,    -1,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   231,    -1,    -1,    -1,    -1,    -1,   237,     3,     4,
      -1,    -1,   242,   243,    -1,    10,    11,    12,    -1,   249,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,   247,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    -1,    -1,     3,     4,    -1,    83,    84,
      -1,    86,    10,    11,    12,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    -1,    -1,    13,    14,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    86,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   251,    -1,    -1,   199,    -1,    -1,    -1,    -1,   204,
     205,   206,    -1,   208,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   230,   231,    -1,   108,   109,
     110,   111,   237,    -1,   114,    -1,    -1,   242,   243,    -1,
      -1,   121,   122,    -1,   249,   125,   126,    -1,   128,   129,
      -1,   131,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   148,    -1,
      -1,   199,    -1,    -1,    -1,    -1,   204,   205,   206,    -1,
     208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,    -1,
      -1,    -1,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,   237,
      13,    14,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,   125,   126,   247,   128,   129,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,   114,   172,   173,   174,    -1,    -1,    -1,   121,   122,
      -1,    -1,   125,   126,    -1,   128,   129,    -1,   131,    -1,
      -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   172,
     173,   174,   108,   109,   110,   111,    -1,    -1,   114,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   247,    -1,   125,
     126,    -1,   128,   129,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,    -1,    -1,   114,   172,   173,   174,    -1,
      -1,    -1,   121,   122,   247,    -1,   125,   126,    -1,   128,
     129,    -1,   131,    -1,    -1,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   172,   173,   174,   108,   109,   110,   111,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,   247,    -1,   125,   126,    -1,   128,   129,    -1,   131,
      -1,    -1,    -1,    -1,    -1,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,   114,
     172,   173,   174,    -1,    -1,    -1,   121,   122,   247,    -1,
     125,   126,    -1,   128,   129,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   172,   173,   174,
     108,   109,   110,   111,    -1,    -1,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   247,    -1,   125,   126,    -1,
     128,   129,    -1,   131,    -1,    -1,    -1,    -1,    -1,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,    -1,    -1,   114,   172,   173,   174,    -1,    -1,    -1,
     121,   122,   247,    -1,   125,   126,    -1,   128,   129,    -1,
     131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   172,   173,   174,   108,   109,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   247,
      -1,   125,   126,    -1,   128,   129,    -1,   131,     0,     1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,   148,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,   172,   173,
     174,    -1,    44,    45,    -1,    -1,   247,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    71,
      -1,    73,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    -1,    84,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,   108,   109,   110,   111,
     112,    -1,   114,   247,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    -1,
      -1,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,     4,    -1,   160,   161,
     162,    -1,    -1,    -1,   166,    13,    14,    -1,    -1,   171,
     172,   173,   174,    -1,    -1,   177,    -1,   179,    -1,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    44,    45,    -1,   201,
     202,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     212,    -1,   214,    -1,    -1,    -1,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    -1,    73,    -1,    -1,    -1,    -1,
      78,    79,    -1,    81,    82,    -1,    84,    -1,    -1,    -1,
      -1,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
      -1,    -1,   160,   161,   162,    -1,    -1,    -1,   166,    -1,
      -1,    -1,    -1,   171,   172,   173,   174,     4,     5,   177,
      -1,   179,    -1,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    -1,   212,    -1,   214,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    13,
      14,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    85,    -1,
      -1,    88,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    -1,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    13,
      14,   125,   126,    -1,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,    -1,    -1,    -1,   152,   196,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,    -1,   213,   214,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,    -1,    -1,    -1,   211,    -1,   213,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,   125,   126,    -1,   128,   129,    -1,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,   251,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   251,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   251,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,   247,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
      -1,   247,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
     247,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,   247,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   247,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,   247,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,   247,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,   247,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,   247,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
      -1,   247,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
     247,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,   247,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   247,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,   247,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,   247,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,   247,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,   247,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
      -1,   247,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
     247,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,   247,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,   247,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,   247,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,   247,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,    -1,    -1,   247,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,    -1,    -1,   247,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,   247,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,
     246,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,    -1,   246,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,   246,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,   243,    -1,   245,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
     245,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,   245,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,   245,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,   245,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,   245,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,   245,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,   245,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,   245,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,   245,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,   241,
      -1,    -1,    -1,   245,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,
     245,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,   241,    -1,    -1,    -1,   245,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
     241,    -1,    -1,    -1,   245,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,   241,    -1,    -1,
      -1,   245,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,   241,    -1,    -1,    -1,   245,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241,    -1,   243,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,   241,    -1,   243,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,   241
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   253,   254,     6,     0,     4,    13,    14,    44,
      45,    64,    65,    66,    70,    71,    73,    78,    79,    81,
      82,    84,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   107,   108,
     109,   110,   111,   112,   114,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   160,   161,   162,   166,   171,   172,   173,
     174,   177,   179,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   201,   202,   203,
     212,   214,   255,   257,   258,   278,   296,   298,   302,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   320,   322,
     323,   329,   330,   331,   332,   338,   363,   364,   246,   250,
      14,    98,   242,   242,     6,   246,     6,     6,     6,     6,
     242,     6,     6,   244,   244,     4,   340,   364,   242,   244,
     276,    92,    95,    98,   100,   276,   242,   242,   242,     4,
     242,   242,   242,     4,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   246,   113,    98,     6,   246,
      92,    95,    98,   111,   301,   100,   242,     3,    10,    11,
      12,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      55,    56,    57,    58,    63,    64,    75,    76,    77,    83,
      86,    92,    95,    98,   100,   111,   121,   126,   128,   131,
     195,   199,   200,   204,   205,   206,   208,   209,   210,   230,
     231,   237,   242,   246,   249,   298,   299,   302,   313,   320,
     322,   333,   334,   338,   340,   347,   349,   364,   242,   246,
     246,    98,    98,   121,    95,    98,   100,    92,    95,    98,
     100,   298,    95,    98,   100,   111,   299,    95,    98,   242,
      95,   152,   177,   193,   194,   246,   230,   231,   242,   246,
     344,   345,   344,   246,   246,   344,     4,    92,    96,   102,
     103,   105,   106,   125,   242,    98,   100,    98,    95,     4,
      84,   188,   246,   364,     4,     6,    92,    95,    98,    95,
      98,   111,   300,     4,     4,     4,     5,   242,   246,   347,
     348,     4,   242,   242,   242,     4,   246,   351,   364,     4,
     242,   242,   242,     6,     6,   244,     5,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    59,    60,    61,    62,
      67,    68,    69,    72,    74,    85,    88,   196,   197,   198,
     207,   211,   213,   355,   364,   242,     4,   355,     5,   246,
       5,   246,    32,   231,   333,   364,   244,   246,   242,   246,
       6,   242,   246,     6,   250,     7,   128,   188,   215,   216,
     217,   218,   239,   240,   242,   244,   248,   274,   275,   276,
     333,   354,   355,   364,     4,   302,   303,   304,   246,     6,
     333,   354,   355,   364,   354,   333,   354,   361,   362,   364,
     280,   284,   242,   343,     9,   355,   242,   242,   242,   242,
     364,   333,   333,   333,   242,   333,   333,   333,   242,   333,
     333,   333,   333,   333,   333,   333,   354,   333,   333,   333,
     333,   348,   242,   231,   333,   349,   350,   246,   348,   347,
     354,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   242,   244,   276,   276,   276,   276,
     276,   276,   242,   276,   276,   242,   298,   276,   276,     5,
     246,   246,   121,   298,   298,   242,   276,   276,   242,   242,
     242,   333,   246,   333,   349,   333,   333,   247,   350,   340,
     364,   180,     5,   246,     8,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   241,     9,   242,   244,   248,   275,   276,
     333,   350,   350,   242,   242,   242,   347,   348,   348,   348,
     297,   246,   242,   347,   246,   246,   333,     4,   347,   246,
     351,   246,   246,   344,   344,   344,   333,   333,   230,   231,
     246,   246,   344,   230,   231,   242,   304,   344,   246,   242,
     246,   242,   242,   242,   242,   242,   242,   242,   333,   348,
     348,   348,   242,     4,   244,     6,   244,   304,     6,     6,
     246,   246,   246,   246,   348,   244,   244,   244,   333,     8,
       6,     6,   333,   333,   333,   248,   333,   246,   180,   333,
     333,   333,   333,   276,   276,   276,   242,   242,   242,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   242,
     242,   276,   242,   244,     6,     6,   246,     6,     8,   304,
       6,     8,   304,   276,   333,   232,   246,     9,   242,   244,
     248,   354,   350,   333,   304,   347,   347,   246,   355,    92,
      95,    98,   100,     7,   333,   333,     4,   177,   178,   347,
       6,   243,   245,   246,   277,     6,   246,     6,     9,   242,
     244,   248,   364,   247,   121,   126,   128,   129,   131,   296,
     298,   333,     6,   243,   251,     9,   242,   244,   248,   243,
     251,   251,   243,   251,     9,   242,   248,   245,   251,   279,
     245,   279,    87,   342,   339,   364,   251,   333,   333,   333,
     333,   251,   243,   243,   243,   333,   243,   243,   243,   333,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   247,     7,   333,   232,   247,   251,   333,     6,     6,
     243,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   349,   333,
     333,   333,   333,   333,   333,   333,   349,   349,   364,   246,
     333,   333,   354,   333,   354,   347,   354,   354,   361,   246,
     333,   277,   364,     8,   333,   333,   348,   347,   354,   354,
     349,   340,   355,   340,   350,   243,   247,   248,   276,    64,
       8,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   246,   333,   349,   333,   333,
     333,   333,   333,   364,   333,   333,     4,   341,   246,   277,
     243,   247,   247,   333,   333,   333,     7,     7,   326,   326,
     242,   333,   333,     6,   350,   350,   246,   243,     6,   304,
     246,   304,   304,   251,   251,   251,   344,   344,   303,   303,
     251,   333,   247,   317,   251,   304,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   243,     7,   327,     6,     7,
     333,     6,   333,   333,   247,   350,   350,   350,   333,     6,
     333,   333,   333,   243,   247,   243,   243,   243,   177,   251,
     304,   246,     8,   243,   243,   245,   361,   354,   361,   354,
     354,   354,   354,   354,   354,   333,   354,   354,   354,   354,
     249,   357,   364,   355,   354,   354,   354,   340,   364,   350,
     247,   247,   247,   247,   333,   333,   304,   364,   341,   245,
     247,   243,   135,   152,   321,   243,   247,   251,   333,     6,
     246,   246,   246,   246,   347,   243,   245,     7,   274,   275,
     248,     7,     6,   350,     7,   218,   274,   259,   364,   333,
     333,   341,   244,   242,   121,   298,   299,   298,   246,   247,
       6,   225,   226,   256,   350,   364,   333,   333,     4,   341,
       6,   350,   333,     6,   354,   362,   364,   243,   341,     6,
     364,     6,   354,   333,   243,   244,   333,   251,   251,   251,
     251,   355,     7,     7,     7,   243,     7,     7,     7,   243,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     333,   243,   246,   333,   349,   247,     6,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   251,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   251,   251,
     251,   243,   245,   245,   350,   251,   251,   277,   251,   277,
     251,   251,   251,   243,   333,   335,   277,   247,   247,   247,
     251,   251,   277,   277,   243,   248,   243,   248,   251,   276,
     336,   247,     7,   341,   277,   246,   247,     8,     8,   350,
     248,   243,   245,   275,   242,   244,   276,   350,     7,   246,
     246,   243,   243,   243,   333,   347,     4,   325,     6,   293,
     333,   355,   247,   243,   247,   247,   350,   248,   247,   304,
     247,   247,   344,   333,   333,   247,   247,   333,   344,   132,
     132,   149,   157,   158,   159,   163,   164,   318,   319,   344,
     247,   314,   243,   247,   243,   243,   243,   243,   243,   243,
     243,     7,   333,     6,   333,   243,   245,   245,   247,   247,
     247,   247,   245,   245,   251,     7,     7,     7,   248,   333,
     247,   333,   333,     7,   248,   277,   251,   277,   277,   243,
     243,   251,   277,   277,   251,   251,   277,   277,   277,   277,
     333,   277,     9,   356,   251,   243,   251,   277,   248,   251,
     337,   245,   247,   247,   248,   242,   244,   250,   180,     7,
     152,     6,   333,   247,   246,     6,   347,   247,   333,   333,
     333,   333,     6,     7,   274,   275,   248,   274,   275,   355,
     333,     6,     4,   246,   352,   364,   247,    46,    46,   347,
       4,   167,   168,   169,   170,   247,   262,   266,   269,   271,
     272,   248,   243,   245,   242,   333,   333,   242,   246,   242,
     246,     8,   350,   354,   243,   248,   243,   245,   242,   243,
     251,   248,   242,     7,   276,     4,   287,   288,   289,   277,
     333,   333,   333,   333,   277,   344,   347,   347,     7,   347,
     347,   347,     7,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,     6,     7,   350,   333,   333,   333,   333,
     247,   333,   333,   333,   347,   354,   354,   247,   251,   286,
     333,   333,   341,   341,   333,   333,   243,   347,   276,   333,
     333,   333,   247,   341,   275,   248,   275,   333,   333,   277,
     247,   347,   350,   350,     7,     7,     7,   132,   324,     6,
     243,   251,     7,     7,     7,   247,     4,   247,   251,   251,
     251,   247,   247,   110,     4,     6,   333,   246,     6,   242,
       6,   165,     6,   165,   247,   319,   251,   318,     7,     6,
       7,     7,     7,     7,     7,     7,     7,   347,     6,   246,
       6,     6,     6,    98,     7,     6,     6,   333,   347,   347,
     347,     4,   251,     8,     8,   243,     4,   101,   102,     4,
     350,   354,   333,   354,   249,   251,   290,   354,   354,   341,
     354,   243,   251,   341,   246,   298,   246,     6,   333,     6,
     246,   347,   247,   247,   247,   247,   247,   333,     6,     4,
     177,   178,   333,     6,     6,     6,     7,   351,   353,     6,
     244,   277,   276,   276,     6,   263,   242,   242,   246,   273,
       6,   341,   248,   354,   333,   245,   243,   333,     8,   350,
     333,   350,   247,   247,     6,     6,   256,   341,   248,   333,
       6,   333,   341,   243,   246,   333,   355,   277,    46,   246,
     347,   355,   358,   245,   251,     6,   243,   243,   243,   243,
       6,     6,   125,   295,   295,   347,     6,     6,     6,   347,
     132,   180,   294,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     5,   247,   277,   277,   277,   277,   277,   251,
     251,   251,   243,   277,   277,   288,   277,   243,   277,   243,
     276,   336,   277,     6,   277,   251,   242,   244,   276,     4,
     243,   245,   277,     6,   247,   247,   347,   347,   347,     4,
       6,   274,   333,   347,   246,   246,     7,     6,     7,   333,
     333,   333,   246,   246,   246,   244,     6,   333,   347,   333,
       6,     6,   333,   344,   247,     5,   347,   246,   246,   246,
     246,   246,   246,   246,   347,     6,   350,   246,   333,   245,
       6,     6,   176,   333,   333,   333,     6,     6,     6,     6,
       7,   277,   251,   251,   277,   251,   333,     4,   192,   291,
     292,   277,   243,   277,   337,   355,   242,   244,   333,   246,
     304,     6,   304,   251,     6,     6,     7,   274,   275,   248,
       7,     6,   351,   247,   251,   333,   274,   246,   277,   359,
     360,   361,   359,   242,   333,   333,   346,   347,   246,   242,
       4,     6,   243,     6,   243,   247,   247,   243,   247,     6,
       6,   354,   242,     4,   243,   251,   242,   347,   355,     7,
     276,   285,   333,   349,   289,     6,     6,     6,     6,   344,
       6,     6,     6,     6,    92,   111,    96,     6,     5,   246,
     333,   333,   333,   333,   243,   336,   333,   333,   333,   277,
     275,   246,   246,     6,   294,     6,   333,   347,     4,     6,
     350,   350,   333,   333,   355,   247,   243,   247,   251,   303,
     303,   333,   333,   247,   251,   243,   247,   251,     6,     6,
     346,   344,   344,   344,   344,   344,   231,   344,     6,   247,
     333,     6,     6,   347,   247,   251,     8,   247,   243,   246,
     333,   355,   354,   333,   354,   333,   355,   358,   360,   355,
     251,   243,   251,   247,   333,   321,   321,   347,   355,   333,
       6,     4,   352,     6,   351,   245,   347,   361,     6,   277,
     277,   260,   333,   251,   251,   247,   251,   261,   333,   333,
       6,     6,     6,     6,   333,   333,   243,   281,   283,   246,
     360,   247,   251,     7,     7,   246,   246,   246,     5,   346,
     277,   277,   251,   277,   243,   251,   243,   245,   350,   350,
       6,     6,   246,   247,   247,   246,     6,     6,   246,   333,
     247,   247,   247,   245,     6,   347,     7,   246,   333,   247,
     251,   251,   251,   251,   251,   251,     6,   247,   175,   333,
     333,   350,     6,     6,   243,   277,   277,   292,   355,   247,
     247,   247,   247,     6,     6,     7,     6,   248,     6,   247,
       6,     6,   243,   251,   333,   333,   246,   347,   247,   251,
     243,   243,   251,   286,   290,   347,   277,   333,   355,   364,
     350,   350,   333,     6,   247,   333,   336,   333,   247,   247,
     346,   136,   137,   142,   328,   136,   137,   328,   350,   303,
     247,   251,     6,   247,   347,   304,   247,     6,   350,   344,
     344,   344,   344,   344,   333,   247,   247,   247,   243,     6,
     246,     6,   351,   178,   264,   333,   251,   251,   346,     6,
     333,   333,   247,   247,   282,     7,   242,   247,   247,   247,
     246,   251,   243,   251,   246,   247,   246,   344,   347,     6,
     246,   344,     6,   247,   247,   333,     6,   132,   247,   315,
     246,   247,   251,   251,   251,   251,   251,     6,     6,     6,
     304,     6,   246,   333,   333,   247,   251,   286,   355,   243,
     333,   333,   333,   350,     6,   344,     6,   344,     6,     6,
     247,   333,   318,   304,     6,   350,   350,   350,   350,   344,
     350,   321,   261,   243,   251,     6,   246,   333,   247,   251,
     251,   251,   247,   251,   251,     6,   247,   247,   316,   247,
     247,   247,   247,   251,   247,   247,   247,   267,   333,   346,
     247,   333,   333,   333,   344,   344,   318,     6,     6,     6,
       6,   350,     6,     6,     6,   246,   243,   247,     6,   247,
     277,   251,   251,   251,   247,   247,   265,   354,   270,   246,
       6,   333,   333,   333,     6,   247,   251,   246,   346,   247,
     247,   247,     6,   354,   268,   354,   247,     6,     6,   247,
     251,     6,     6,   354
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
    ;}
    break;

  case 102:
#line 1109 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c)))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), (yyvsp[(6) - (7)].c));
#endif
      Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 103:
#line 1117 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Box"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Box");
#endif
    ;}
    break;

  case 104:
#line 1124 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      if(!GModel::current()->getFields()->newField((int)(yyvsp[(3) - (7)].d), "Cylinder"))
	yymsg(0, "Cannot create field %i of type '%s'", (int)(yyvsp[(3) - (7)].d), "Cylinder");
#endif
    ;}
    break;

  case 105:
#line 1131 "Gmsh.y"
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
#line 1153 "Gmsh.y"
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
#line 1176 "Gmsh.y"
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
#line 1214 "Gmsh.y"
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
#line 1235 "Gmsh.y"
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
#line 1247 "Gmsh.y"
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
#line 1265 "Gmsh.y"
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
#line 1274 "Gmsh.y"
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
#line 1283 "Gmsh.y"
    { init_options(); ;}
    break;

  case 117:
#line 1285 "Gmsh.y"
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
#line 1303 "Gmsh.y"
    { init_options(); ;}
    break;

  case 119:
#line 1305 "Gmsh.y"
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
#line 1321 "Gmsh.y"
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
#line 1330 "Gmsh.y"
    { init_options(); ;}
    break;

  case 122:
#line 1332 "Gmsh.y"
    {
      std::string key((yyvsp[(3) - (9)].c)), val((yyvsp[(6) - (9)].c));
      if(!gmsh_yysymbols.count(key)){
        Msg::ExchangeOnelabParameter(key, val, floatOptions, charOptions);
        gmsh_yystringsymbols[key] = std::vector<std::string>(1, val);
      }
      Free((yyvsp[(3) - (9)].c));
      Free((yyvsp[(6) - (9)].c));
    ;}
    break;

  case 124:
#line 1346 "Gmsh.y"
    {
      std::string name((yyvsp[(3) - (3)].c));
      Msg::UndefineOnelabParameter(name);
      Free((yyvsp[(3) - (3)].c));
    ;}
    break;

  case 125:
#line 1354 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(doubleXstring));
      doubleXstring v = {(yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 126:
#line 1360 "Gmsh.y"
    {
      doubleXstring v = {(yyvsp[(3) - (5)].d), (yyvsp[(5) - (5)].c)};
      List_Add((yyval.l), &v);
    ;}
    break;

  case 127:
#line 1365 "Gmsh.y"
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
#line 1407 "Gmsh.y"
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
#line 1419 "Gmsh.y"
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
#line 1432 "Gmsh.y"
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
#line 1447 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 138:
#line 1456 "Gmsh.y"
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
#line 1481 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      double val = (yyvsp[(2) - (2)].d);
      floatOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
    ;}
    break;

  case 144:
#line 1489 "Gmsh.y"
    {
      std::string key((yyvsp[(1) - (2)].c));
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(1) - (2)].c));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 145:
#line 1498 "Gmsh.y"
    {
      std::string key("Macro");
      std::string val((yyvsp[(2) - (2)].c));
      charOptions[key].push_back(val);
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 146:
#line 1506 "Gmsh.y"
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
#line 1520 "Gmsh.y"
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
#line 1538 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(1) - (1)].d);
    ;}
    break;

  case 149:
#line 1542 "Gmsh.y"
    {
      int t = GModel::current()->getGEOInternals()->getMaxPhysicalTag();
      GModel::current()->getGEOInternals()->setMaxPhysicalTag(t + 1);
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (1)].c)), dim_entity, t + 1);
      Free((yyvsp[(1) - (1)].c));
    ;}
    break;

  case 150:
#line 1549 "Gmsh.y"
    {
      (yyval.i) = GModel::current()->setPhysicalName(std::string((yyvsp[(1) - (3)].c)), dim_entity, (yyvsp[(3) - (3)].d));
      Free((yyvsp[(1) - (3)].c));
    ;}
    break;

  case 151:
#line 1557 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 152:
#line 1561 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
      double p = (yyvsp[(4) - (5)].d);
      List_Add((yyval.l), &p);
    ;}
    break;

  case 153:
#line 1567 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
    ;}
    break;

  case 154:
#line 1571 "Gmsh.y"
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
#line 1582 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = 0.;
    ;}
    break;

  case 156:
#line 1586 "Gmsh.y"
    {
      for(int i = 0; i < 4; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 157:
#line 1593 "Gmsh.y"
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
#line 1616 "Gmsh.y"
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
#line 1632 "Gmsh.y"
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
#line 1648 "Gmsh.y"
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
#line 1685 "Gmsh.y"
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
#line 1725 "Gmsh.y"
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
#line 1741 "Gmsh.y"
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
#line 1758 "Gmsh.y"
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
#line 1789 "Gmsh.y"
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
#line 1805 "Gmsh.y"
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
#line 1822 "Gmsh.y"
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
#line 1838 "Gmsh.y"
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
#line 1888 "Gmsh.y"
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
#line 1906 "Gmsh.y"
    {
      myGmshSurface = 0;
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 171:
#line 1912 "Gmsh.y"
    {
      myGmshSurface = gmshSurface::getSurface((int)(yyvsp[(3) - (4)].d));
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 172:
#line 1918 "Gmsh.y"
    {
      int num = (int)(yyvsp[(4) - (10)].d);
      myGmshSurface = gmshParametricSurface::NewParametricSurface(num, (yyvsp[(7) - (10)].c), (yyvsp[(8) - (10)].c), (yyvsp[(9) - (10)].c));
      (yyval.s).Type = 0;
      (yyval.s).Num = num;
    ;}
    break;

  case 173:
#line 1925 "Gmsh.y"
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
#line 1956 "Gmsh.y"
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
#line 1971 "Gmsh.y"
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
#line 1993 "Gmsh.y"
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
#line 2016 "Gmsh.y"
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
#line 2039 "Gmsh.y"
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
#line 2062 "Gmsh.y"
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
#line 2086 "Gmsh.y"
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
#line 2110 "Gmsh.y"
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
#line 2134 "Gmsh.y"
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
#line 2160 "Gmsh.y"
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
#line 2177 "Gmsh.y"
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
#line 2193 "Gmsh.y"
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
#line 2211 "Gmsh.y"
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
#line 2229 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (8)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 188:
#line 2237 "Gmsh.y"
    {
      yymsg(0, "Compounds entities are deprecated: use Compound meshing constraints "
            "instead, i.e. Compound %s { ... };", ((yyvsp[(2) - (12)].i) == 2) ? "Surface" : "Line");
      (yyval.s).Type = 0;
      (yyval.s).Num = 0;
    ;}
    break;

  case 189:
#line 2244 "Gmsh.y"
    {
      dim_entity = (yyvsp[(2) - (2)].i);
    ;}
    break;

  case 190:
#line 2248 "Gmsh.y"
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
#line 2274 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 192:
#line 2276 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 193:
#line 2278 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 194:
#line 2280 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 195:
#line 2282 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [0,3]");
    ;}
    break;

  case 196:
#line 2290 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 197:
#line 2292 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 198:
#line 2294 "Gmsh.y"
    { (yyval.i) = 3; ;}
    break;

  case 199:
#line 2296 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>3) yymsg(0, "GeoEntity dim out of range [1,3]");
    ;}
    break;

  case 200:
#line 2304 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 201:
#line 2306 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 202:
#line 2308 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<1 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [1,2]");
    ;}
    break;

  case 203:
#line 2316 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 204:
#line 2318 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 205:
#line 2320 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 206:
#line 2322 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(3) - (4)].d);
      if ((yyval.i)<0 || (yyval.i)>2) yymsg(0, "GeoEntity dim out of range [0,2]");
    ;}
    break;

  case 207:
#line 2332 "Gmsh.y"
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
#line 2348 "Gmsh.y"
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
#line 2364 "Gmsh.y"
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
#line 2380 "Gmsh.y"
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
#line 2396 "Gmsh.y"
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
#line 2412 "Gmsh.y"
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
#line 2449 "Gmsh.y"
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
#line 2471 "Gmsh.y"
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
#line 2494 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 216:
#line 2495 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 217:
#line 2500 "Gmsh.y"
    {
      (yyval.l) = List_Create(3, 3, sizeof(Shape));
    ;}
    break;

  case 218:
#line 2504 "Gmsh.y"
    {
      List_Add((yyval.l), &(yyvsp[(2) - (2)].s));
    ;}
    break;

  case 219:
#line 2508 "Gmsh.y"
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
#line 2524 "Gmsh.y"
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
    ;}
    break;

  case 221:
#line 2542 "Gmsh.y"
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
    ;}
    break;

  case 222:
#line 2560 "Gmsh.y"
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
    ;}
    break;

  case 223:
#line 2578 "Gmsh.y"
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
    ;}
    break;

  case 224:
#line 2603 "Gmsh.y"
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
#line 2622 "Gmsh.y"
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
#line 2644 "Gmsh.y"
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
#line 2659 "Gmsh.y"
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
#line 2674 "Gmsh.y"
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
#line 2693 "Gmsh.y"
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
#line 2744 "Gmsh.y"
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
#line 2765 "Gmsh.y"
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
#line 2787 "Gmsh.y"
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
#line 2809 "Gmsh.y"
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
#line 2914 "Gmsh.y"
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
#line 2930 "Gmsh.y"
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
#line 2965 "Gmsh.y"
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
#line 2987 "Gmsh.y"
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
#line 3009 "Gmsh.y"
    {
#if defined(HAVE_MESH)
      GModel::current()->getFields()->deleteField((int)(yyvsp[(4) - (6)].d));
#endif
    ;}
    break;

  case 239:
#line 3015 "Gmsh.y"
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
#line 3030 "Gmsh.y"
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
#line 3058 "Gmsh.y"
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
#line 3070 "Gmsh.y"
    {
      gmsh_yynamespaces.clear();
    ;}
    break;

  case 243:
#line 3079 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setColor(dimTags, (yyvsp[(2) - (5)].u), false);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 244:
#line 3086 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(5) - (6)].l), dimTags);
      setColor(dimTags, (yyvsp[(3) - (6)].u), true);
      List_Delete((yyvsp[(5) - (6)].l));
    ;}
    break;

  case 245:
#line 3098 "Gmsh.y"
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
#line 3117 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
    ;}
    break;

  case 247:
#line 3121 "Gmsh.y"
    {
      setVisibility(-1, 1, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 248:
#line 3126 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
    ;}
    break;

  case 249:
#line 3130 "Gmsh.y"
    {
      setVisibility(-1, 0, false);
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 250:
#line 3135 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 1, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 251:
#line 3142 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 1, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 252:
#line 3149 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(3) - (4)].l), dimTags);
      setVisibility(dimTags, 0, false);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 253:
#line 3156 "Gmsh.y"
    {
      std::vector<std::pair<int, int> > dimTags;
      ListOfShapes2VectorOfPairs((yyvsp[(4) - (5)].l), dimTags);
      setVisibility(dimTags, 0, true);
      List_Delete((yyvsp[(4) - (5)].l));
    ;}
    break;

  case 254:
#line 3168 "Gmsh.y"
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
#line 3241 "Gmsh.y"
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
#line 3259 "Gmsh.y"
    {
#if defined(HAVE_POST)
      if(!strcmp((yyvsp[(1) - (7)].c), "Save") && !strcmp((yyvsp[(2) - (7)].c), "View")){
	int index = (int)(yyvsp[(4) - (7)].d);
	if(index >= 0 && index < (int)PView::list.size()){
          std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(6) - (7)].c));
	  PView::list[index]->write(tmp, CTX::instance()->post.fileFormat);
	}
	else
	  yymsg(0, "Unknown view %d", index);
      }
      else
	yymsg(0, "Unknown command '%s'", (yyvsp[(1) - (7)].c));
#endif
      Free((yyvsp[(1) - (7)].c)); Free((yyvsp[(2) - (7)].c)); Free((yyvsp[(6) - (7)].c));
    ;}
    break;

  case 257:
#line 3276 "Gmsh.y"
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
#line 3291 "Gmsh.y"
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
#line 3324 "Gmsh.y"
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
#line 3336 "Gmsh.y"
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
#line 3360 "Gmsh.y"
    {
      Msg::Exit(0);
    ;}
    break;

  case 262:
#line 3364 "Gmsh.y"
    {
      gmsh_yyerrorstate = 999; // this will be checked when yyparse returns
      YYABORT;
    ;}
    break;

  case 263:
#line 3369 "Gmsh.y"
    {
      // force sync
      if(GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      GModel::current()->getGEOInternals()->synchronize(GModel::current());
    ;}
    break;

  case 264:
#line 3376 "Gmsh.y"
    {
      new GModel();
      GModel::current(GModel::list.size() - 1);
    ;}
    break;

  case 265:
#line 3381 "Gmsh.y"
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
#line 3391 "Gmsh.y"
    {
      CTX::instance()->forcedBBox = 1;
      SetBoundingBox((yyvsp[(3) - (15)].d), (yyvsp[(5) - (15)].d), (yyvsp[(7) - (15)].d), (yyvsp[(9) - (15)].d), (yyvsp[(11) - (15)].d), (yyvsp[(13) - (15)].d));
    ;}
    break;

  case 267:
#line 3396 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
      drawContext::global()->draw();
#endif
    ;}
    break;

  case 268:
#line 3402 "Gmsh.y"
    {
#if defined(HAVE_OPENGL)
     CTX::instance()->mesh.changed = ENT_ALL;
     for(unsigned int index = 0; index < PView::list.size(); index++)
       PView::list[index]->setChanged(true);
#endif
    ;}
    break;

  case 269:
#line 3410 "Gmsh.y"
    {
      GModel::current()->createTopologyFromMesh();
    ;}
    break;

  case 270:
#line 3414 "Gmsh.y"
    {
      GModel::current()->createGeometryOfDiscreteEntities();
    ;}
    break;

  case 271:
#line 3418 "Gmsh.y"
    {
      if(GModel::current()->getOCCInternals() &&
         GModel::current()->getOCCInternals()->getChanged())
        GModel::current()->getOCCInternals()->synchronize(GModel::current());
      if(GModel::current()->getGEOInternals()->getChanged())
        GModel::current()->getGEOInternals()->synchronize(GModel::current());
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    ;}
    break;

  case 272:
#line 3428 "Gmsh.y"
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

  case 273:
#line 3491 "Gmsh.y"
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

  case 274:
#line 3507 "Gmsh.y"
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

  case 275:
#line 3524 "Gmsh.y"
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

  case 276:
#line 3541 "Gmsh.y"
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

  case 277:
#line 3563 "Gmsh.y"
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

  case 278:
#line 3585 "Gmsh.y"
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

  case 279:
#line 3620 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 280:
#line 3628 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->createFunction
         (std::string((yyvsp[(2) - (2)].c)), gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Redefinition of function %s", (yyvsp[(2) - (2)].c));
      skip(NULL, "Return");
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 281:
#line 3636 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->leaveFunction
         (&gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Error while exiting function");
    ;}
    break;

  case 282:
#line 3642 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 283:
#line 3649 "Gmsh.y"
    {
      if(!FunctionManager::Instance()->enterFunction
         (std::string((yyvsp[(2) - (3)].c)), &gmsh_yyin, gmsh_yyname, gmsh_yylineno))
	yymsg(0, "Unknown function '%s'", (yyvsp[(2) - (3)].c));
      Free((yyvsp[(2) - (3)].c));
    ;}
    break;

  case 284:
#line 3656 "Gmsh.y"
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

  case 285:
#line 3676 "Gmsh.y"
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

  case 286:
#line 3702 "Gmsh.y"
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

  case 287:
#line 3714 "Gmsh.y"
    {
      ImbricatedTest--;
      if(ImbricatedTest < 0)
        yymsg(1, "Orphan EndIf");
    ;}
    break;

  case 288:
#line 3725 "Gmsh.y"
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

  case 289:
#line 3743 "Gmsh.y"
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

  case 290:
#line 3761 "Gmsh.y"
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

  case 291:
#line 3779 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 292:
#line 3785 "Gmsh.y"
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

  case 293:
#line 3803 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 294:
#line 3809 "Gmsh.y"
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

  case 295:
#line 3829 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 296:
#line 3835 "Gmsh.y"
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

  case 297:
#line 3853 "Gmsh.y"
    {
      extr.mesh.ExtrudeMesh = extr.mesh.Recombine = false;
      extr.mesh.QuadToTri = NO_QUADTRI;
      extr.mesh.ScaleLast = false;
    ;}
    break;

  case 298:
#line 3859 "Gmsh.y"
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

  case 299:
#line 3876 "Gmsh.y"
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

  case 300:
#line 3892 "Gmsh.y"
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

  case 301:
#line 3909 "Gmsh.y"
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

  case 302:
#line 3927 "Gmsh.y"
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

  case 303:
#line 3950 "Gmsh.y"
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

  case 304:
#line 3977 "Gmsh.y"
    {
    ;}
    break;

  case 305:
#line 3980 "Gmsh.y"
    {
    ;}
    break;

  case 306:
#line 3986 "Gmsh.y"
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

  case 307:
#line 3998 "Gmsh.y"
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

  case 308:
#line 4018 "Gmsh.y"
    {
      extr.mesh.ScaleLast = true;
    ;}
    break;

  case 309:
#line 4022 "Gmsh.y"
    {
      extr.mesh.Recombine = true;
    ;}
    break;

  case 310:
#line 4026 "Gmsh.y"
    {
      extr.mesh.Recombine = (yyvsp[(2) - (3)].d) ? true : false;
    ;}
    break;

  case 311:
#line 4030 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1;
    ;}
    break;

  case 312:
#line 4034 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_ADDVERTS_1_RECOMB;
    ;}
    break;

  case 313:
#line 4038 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1;
    ;}
    break;

  case 314:
#line 4042 "Gmsh.y"
    {
      extr.mesh.QuadToTri = QUADTRI_NOVERTS_1_RECOMB;
    ;}
    break;

  case 315:
#line 4046 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(6) - (9)].l), tags);
      int num = (int)(yyvsp[(3) - (9)].d);
      GModel::current()->getGEOInternals()->addDiscreteSurface(num);
      extr.mesh.Holes[num].first = (yyvsp[(8) - (9)].d);
      extr.mesh.Holes[num].second = tags;
      List_Delete((yyvsp[(6) - (9)].l));
    ;}
    break;

  case 316:
#line 4055 "Gmsh.y"
    {
      if(!strcmp((yyvsp[(2) - (6)].c), "Index"))
        extr.mesh.BoundaryLayerIndex = (yyvsp[(4) - (6)].d);
      else if(!strcmp((yyvsp[(2) - (6)].c), "View"))
        extr.mesh.ViewIndex = (yyvsp[(4) - (6)].d);
      Free((yyvsp[(2) - (6)].c));
    ;}
    break;

  case 317:
#line 4067 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Union; ;}
    break;

  case 318:
#line 4068 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Intersection; ;}
    break;

  case 319:
#line 4069 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Difference; ;}
    break;

  case 320:
#line 4070 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Section; ;}
    break;

  case 321:
#line 4071 "Gmsh.y"
    { (yyval.i) = OCC_Internals::Fragments; ;}
    break;

  case 322:
#line 4075 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 323:
#line 4076 "Gmsh.y"
    { (yyval.i) = 1; ;}
    break;

  case 324:
#line 4077 "Gmsh.y"
    { (yyval.i) = 2; ;}
    break;

  case 325:
#line 4078 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].d) ? 1 : 0; ;}
    break;

  case 326:
#line 4079 "Gmsh.y"
    { (yyval.i) = (yyvsp[(3) - (4)].d) ? 2 : 0; ;}
    break;

  case 327:
#line 4084 "Gmsh.y"
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

  case 328:
#line 4107 "Gmsh.y"
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

  case 329:
#line 4127 "Gmsh.y"
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

  case 330:
#line 4148 "Gmsh.y"
    {
      (yyval.v)[0] = (yyval.v)[1] = 1.;
    ;}
    break;

  case 331:
#line 4152 "Gmsh.y"
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

  case 332:
#line 4167 "Gmsh.y"
    {
      (yyval.i) = -1; // left
    ;}
    break;

  case 333:
#line 4171 "Gmsh.y"
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

  case 334:
#line 4187 "Gmsh.y"
    {
     (yyval.l) = List_Create(1, 1, sizeof(double));
   ;}
    break;

  case 335:
#line 4191 "Gmsh.y"
    {
     (yyval.l) = (yyvsp[(2) - (2)].l);
   ;}
    break;

  case 336:
#line 4196 "Gmsh.y"
    {
      (yyval.i) = 45;
    ;}
    break;

  case 337:
#line 4200 "Gmsh.y"
    {
      (yyval.i) = (int)(yyvsp[(2) - (2)].d);
    ;}
    break;

  case 338:
#line 4206 "Gmsh.y"
    {
      (yyval.l) = List_Create(1, 1, sizeof(double));
    ;}
    break;

  case 339:
#line 4210 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
    ;}
    break;

  case 340:
#line 4217 "Gmsh.y"
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

  case 341:
#line 4239 "Gmsh.y"
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

  case 342:
#line 4280 "Gmsh.y"
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

  case 343:
#line 4324 "Gmsh.y"
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

  case 344:
#line 4363 "Gmsh.y"
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

  case 345:
#line 4388 "Gmsh.y"
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

  case 346:
#line 4400 "Gmsh.y"
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

  case 347:
#line 4412 "Gmsh.y"
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

  case 348:
#line 4424 "Gmsh.y"
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

  case 349:
#line 4436 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(4) - (8)].l)); i++){
	double d;
	List_Read((yyvsp[(4) - (8)].l), i, &d);
	CTX::instance()->mesh.algo2dPerFace[(int)d] = (int)(yyvsp[(7) - (8)].d);
      }
      List_Delete((yyvsp[(4) - (8)].l));
    ;}
    break;

  case 350:
#line 4445 "Gmsh.y"
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

  case 351:
#line 4475 "Gmsh.y"
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

  case 352:
#line 4501 "Gmsh.y"
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

  case 353:
#line 4528 "Gmsh.y"
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

  case 354:
#line 4560 "Gmsh.y"
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

  case 355:
#line 4587 "Gmsh.y"
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

  case 356:
#line 4613 "Gmsh.y"
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

  case 357:
#line 4639 "Gmsh.y"
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

  case 358:
#line 4665 "Gmsh.y"
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

  case 359:
#line 4691 "Gmsh.y"
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

  case 360:
#line 4712 "Gmsh.y"
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

  case 361:
#line 4723 "Gmsh.y"
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

  case 362:
#line 4771 "Gmsh.y"
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

  case 363:
#line 4825 "Gmsh.y"
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

  case 364:
#line 4840 "Gmsh.y"
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

  case 365:
#line 4852 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(3) - (4)].l), tags);
      GModel::current()->getGEOInternals()->setCompoundMesh((yyvsp[(2) - (4)].i), tags);
      List_Delete((yyvsp[(3) - (4)].l));
    ;}
    break;

  case 366:
#line 4863 "Gmsh.y"
    {
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->removeAllDuplicates();
      else
        GModel::current()->getGEOInternals()->removeAllDuplicates();
    ;}
    break;

  case 367:
#line 4870 "Gmsh.y"
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

  case 368:
#line 4885 "Gmsh.y"
    {
      std::vector<int> tags; ListOfDouble2Vector((yyvsp[(4) - (6)].l), tags);
      if(gmsh_yyfactory == "OpenCASCADE" && GModel::current()->getOCCInternals())
        GModel::current()->getOCCInternals()->mergeVertices(tags);
      else
        GModel::current()->getGEOInternals()->mergeVertices(tags);
      List_Delete((yyvsp[(4) - (6)].l));
    ;}
    break;

  case 369:
#line 4898 "Gmsh.y"
    { (yyval.c) = (char*)"Homology"; ;}
    break;

  case 370:
#line 4899 "Gmsh.y"
    { (yyval.c) = (char*)"Cohomology"; ;}
    break;

  case 371:
#line 4900 "Gmsh.y"
    { (yyval.c) = (char*)"Betti"; ;}
    break;

  case 372:
#line 4905 "Gmsh.y"
    {
      std::vector<int> domain, subdomain, dim;
      for(int i = 0; i < 4; i++) dim.push_back(i);
      GModel::current()->addHomologyRequest((yyvsp[(1) - (2)].c), domain, subdomain, dim);
    ;}
    break;

  case 373:
#line 4911 "Gmsh.y"
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

  case 374:
#line 4923 "Gmsh.y"
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

  case 375:
#line 4941 "Gmsh.y"
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

  case 376:
#line 4968 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d);           ;}
    break;

  case 377:
#line 4969 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (3)].d);           ;}
    break;

  case 378:
#line 4970 "Gmsh.y"
    { (yyval.d) = -(yyvsp[(2) - (2)].d);          ;}
    break;

  case 379:
#line 4971 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);           ;}
    break;

  case 380:
#line 4972 "Gmsh.y"
    { (yyval.d) = !(yyvsp[(2) - (2)].d);          ;}
    break;

  case 381:
#line 4973 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) - (yyvsp[(3) - (3)].d);      ;}
    break;

  case 382:
#line 4974 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) + (yyvsp[(3) - (3)].d);      ;}
    break;

  case 383:
#line 4975 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) * (yyvsp[(3) - (3)].d);      ;}
    break;

  case 384:
#line 4977 "Gmsh.y"
    {
      if(!(yyvsp[(3) - (3)].d))
	yymsg(0, "Division by zero in '%g / %g'", (yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));
      else
	(yyval.d) = (yyvsp[(1) - (3)].d) / (yyvsp[(3) - (3)].d);
    ;}
    break;

  case 385:
#line 4983 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) | (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 386:
#line 4984 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) & (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 387:
#line 4985 "Gmsh.y"
    { (yyval.d) = (int)(yyvsp[(1) - (3)].d) % (int)(yyvsp[(3) - (3)].d); ;}
    break;

  case 388:
#line 4986 "Gmsh.y"
    { (yyval.d) = pow((yyvsp[(1) - (3)].d), (yyvsp[(3) - (3)].d));  ;}
    break;

  case 389:
#line 4987 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d);      ;}
    break;

  case 390:
#line 4988 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) > (yyvsp[(3) - (3)].d);      ;}
    break;

  case 391:
#line 4989 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) <= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 392:
#line 4990 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) >= (yyvsp[(3) - (3)].d);     ;}
    break;

  case 393:
#line 4991 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) == (yyvsp[(3) - (3)].d);     ;}
    break;

  case 394:
#line 4992 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) != (yyvsp[(3) - (3)].d);     ;}
    break;

  case 395:
#line 4993 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) && (yyvsp[(3) - (3)].d);     ;}
    break;

  case 396:
#line 4994 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (3)].d) || (yyvsp[(3) - (3)].d);     ;}
    break;

  case 397:
#line 4995 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) >> (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 398:
#line 4996 "Gmsh.y"
    { (yyval.d) = ((int)(yyvsp[(1) - (3)].d) << (int)(yyvsp[(3) - (3)].d)); ;}
    break;

  case 399:
#line 4997 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (5)].d) ? (yyvsp[(3) - (5)].d) : (yyvsp[(5) - (5)].d); ;}
    break;

  case 400:
#line 4998 "Gmsh.y"
    { (yyval.d) = exp((yyvsp[(3) - (4)].d));      ;}
    break;

  case 401:
#line 4999 "Gmsh.y"
    { (yyval.d) = log((yyvsp[(3) - (4)].d));      ;}
    break;

  case 402:
#line 5000 "Gmsh.y"
    { (yyval.d) = log10((yyvsp[(3) - (4)].d));    ;}
    break;

  case 403:
#line 5001 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (4)].d));     ;}
    break;

  case 404:
#line 5002 "Gmsh.y"
    { (yyval.d) = sin((yyvsp[(3) - (4)].d));      ;}
    break;

  case 405:
#line 5003 "Gmsh.y"
    { (yyval.d) = asin((yyvsp[(3) - (4)].d));     ;}
    break;

  case 406:
#line 5004 "Gmsh.y"
    { (yyval.d) = cos((yyvsp[(3) - (4)].d));      ;}
    break;

  case 407:
#line 5005 "Gmsh.y"
    { (yyval.d) = acos((yyvsp[(3) - (4)].d));     ;}
    break;

  case 408:
#line 5006 "Gmsh.y"
    { (yyval.d) = tan((yyvsp[(3) - (4)].d));      ;}
    break;

  case 409:
#line 5007 "Gmsh.y"
    { (yyval.d) = atan((yyvsp[(3) - (4)].d));     ;}
    break;

  case 410:
#line 5008 "Gmsh.y"
    { (yyval.d) = atan2((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d));;}
    break;

  case 411:
#line 5009 "Gmsh.y"
    { (yyval.d) = sinh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 412:
#line 5010 "Gmsh.y"
    { (yyval.d) = cosh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 413:
#line 5011 "Gmsh.y"
    { (yyval.d) = tanh((yyvsp[(3) - (4)].d));     ;}
    break;

  case 414:
#line 5012 "Gmsh.y"
    { (yyval.d) = fabs((yyvsp[(3) - (4)].d));     ;}
    break;

  case 415:
#line 5013 "Gmsh.y"
    { (yyval.d) = std::abs((yyvsp[(3) - (4)].d)); ;}
    break;

  case 416:
#line 5014 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d));    ;}
    break;

  case 417:
#line 5015 "Gmsh.y"
    { (yyval.d) = ceil((yyvsp[(3) - (4)].d));     ;}
    break;

  case 418:
#line 5016 "Gmsh.y"
    { (yyval.d) = floor((yyvsp[(3) - (4)].d) + 0.5); ;}
    break;

  case 419:
#line 5017 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 420:
#line 5018 "Gmsh.y"
    { (yyval.d) = fmod((yyvsp[(3) - (6)].d), (yyvsp[(5) - (6)].d)); ;}
    break;

  case 421:
#line 5019 "Gmsh.y"
    { (yyval.d) = sqrt((yyvsp[(3) - (6)].d) * (yyvsp[(3) - (6)].d) + (yyvsp[(5) - (6)].d) * (yyvsp[(5) - (6)].d)); ;}
    break;

  case 422:
#line 5020 "Gmsh.y"
    { (yyval.d) = (yyvsp[(3) - (4)].d) * (double)rand() / (double)RAND_MAX; ;}
    break;

  case 423:
#line 5029 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 424:
#line 5030 "Gmsh.y"
    { (yyval.d) = 3.141592653589793; ;}
    break;

  case 425:
#line 5031 "Gmsh.y"
    { (yyval.d) = (double)ImbricatedTest; ;}
    break;

  case 426:
#line 5032 "Gmsh.y"
    { (yyval.d) = Msg::GetCommRank(); ;}
    break;

  case 427:
#line 5033 "Gmsh.y"
    { (yyval.d) = Msg::GetCommSize(); ;}
    break;

  case 428:
#line 5034 "Gmsh.y"
    { (yyval.d) = GetGmshMajorVersion(); ;}
    break;

  case 429:
#line 5035 "Gmsh.y"
    { (yyval.d) = GetGmshMinorVersion(); ;}
    break;

  case 430:
#line 5036 "Gmsh.y"
    { (yyval.d) = GetGmshPatchVersion(); ;}
    break;

  case 431:
#line 5037 "Gmsh.y"
    { (yyval.d) = Cpu(); ;}
    break;

  case 432:
#line 5038 "Gmsh.y"
    { (yyval.d) = GetMemoryUsage()/1024./1024.; ;}
    break;

  case 433:
#line 5039 "Gmsh.y"
    { (yyval.d) = TotalRam(); ;}
    break;

  case 434:
#line 5044 "Gmsh.y"
    { init_options(); ;}
    break;

  case 435:
#line 5046 "Gmsh.y"
    {
      std::vector<double> val(1, (yyvsp[(3) - (6)].d));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.d) = val[0];
    ;}
    break;

  case 436:
#line 5052 "Gmsh.y"
    { (yyval.d) = (yyvsp[(1) - (1)].d); ;}
    break;

  case 437:
#line 5054 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 438:
#line 5059 "Gmsh.y"
    {
      (yyval.d) = Msg::GetOnelabNumber((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 439:
#line 5064 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(1) - (1)].c2).char1, (yyvsp[(1) - (1)].c2).char2);
    ;}
    break;

  case 440:
#line 5069 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 441:
#line 5074 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float(NULL, (yyvsp[(1) - (4)].c), 2, (int)(yyvsp[(3) - (4)].d));
    ;}
    break;

  case 442:
#line 5078 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (4)].c2).char1, (yyvsp[(3) - (4)].c2).char2, 1, 0, 0., 1);
    ;}
    break;

  case 443:
#line 5082 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (6)].c2).char1, (yyvsp[(3) - (6)].c2).char2, (yyvsp[(5) - (6)].c), 0, 0., 1);
    ;}
    break;

  case 444:
#line 5086 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (5)].c2).char1, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].d), 2);
    ;}
    break;

  case 445:
#line 5090 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].d), 2);
    ;}
    break;

  case 446:
#line 5094 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_Float((yyvsp[(3) - (8)].c2).char1, (yyvsp[(3) - (8)].c2).char2, 2, (int)(yyvsp[(5) - (8)].d), (yyvsp[(7) - (8)].d), 2);
    ;}
    break;

  case 447:
#line 5098 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(3) - (10)].c2).char1, (yyvsp[(3) - (10)].c2).char2, (yyvsp[(5) - (10)].c), (int)(yyvsp[(7) - (10)].d), (yyvsp[(9) - (10)].d), 2);
    ;}
    break;

  case 448:
#line 5102 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.d) = !StatFile(tmp);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 449:
#line 5108 "Gmsh.y"
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

  case 450:
#line 5124 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float_getDim((yyvsp[(2) - (6)].c2).char1, (yyvsp[(2) - (6)].c2).char2, (yyvsp[(4) - (6)].c));
    ;}
    break;

  case 451:
#line 5129 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(3) - (4)].c));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 452:
#line 5135 "Gmsh.y"
    {
      std::string struct_namespace(std::string(""));
      (yyval.d) = (double)gmsh_yynamespaces[struct_namespace].size();
    ;}
    break;

  case 453:
#line 5141 "Gmsh.y"
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

  case 454:
#line 5160 "Gmsh.y"
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

  case 455:
#line 5181 "Gmsh.y"
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

  case 456:
#line 5214 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 457:
#line 5218 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 458:
#line 5223 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 459:
#line 5227 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 460:
#line 5231 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 461:
#line 5235 "Gmsh.y"
    {
      (yyval.d) = treat_Struct_FullName_dot_tSTRING_Float((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 462:
#line 5240 "Gmsh.y"
    {
      NumberOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), (yyval.d));
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 463:
#line 5245 "Gmsh.y"
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

  case 464:
#line 5255 "Gmsh.y"
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

  case 465:
#line 5265 "Gmsh.y"
    {
      (yyval.d) = Msg::GetValue((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].d));
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 466:
#line 5270 "Gmsh.y"
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

  case 467:
#line 5281 "Gmsh.y"
    {
      std::string s((yyvsp[(3) - (6)].c)), substr((yyvsp[(5) - (6)].c));
      if(s.find(substr) != std::string::npos)
        (yyval.d) = 1.;
      else
        (yyval.d) = 0.;
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 468:
#line 5290 "Gmsh.y"
    {
      (yyval.d) = strlen((yyvsp[(3) - (4)].c));
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 469:
#line 5295 "Gmsh.y"
    {
      (yyval.d) = strcmp((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      Free((yyvsp[(3) - (6)].c)); Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 470:
#line 5300 "Gmsh.y"
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

  case 471:
#line 5327 "Gmsh.y"
    { (yyval.d) = 0.; ;}
    break;

  case 472:
#line 5329 "Gmsh.y"
    { (yyval.d) = (yyvsp[(2) - (2)].d);;}
    break;

  case 473:
#line 5334 "Gmsh.y"
    { (yyval.c) = NULL; ;}
    break;

  case 474:
#line 5336 "Gmsh.y"
    { (yyval.c) = (yyvsp[(2) - (2)].c);;}
    break;

  case 475:
#line 5341 "Gmsh.y"
    {
      std::string struct_namespace((yyvsp[(2) - (3)].c2).char1? (yyvsp[(2) - (3)].c2).char1 : std::string("")),
        struct_name((yyvsp[(2) - (3)].c2).char2);
      init_options
        (gmsh_yynamespaces.getMember_ValMax(struct_namespace, struct_name));
    ;}
    break;

  case 476:
#line 5348 "Gmsh.y"
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

  case 477:
#line 5364 "Gmsh.y"
    { (yyval.c2).char1 = NULL; (yyval.c2).char2 = (yyvsp[(1) - (1)].c); ;}
    break;

  case 478:
#line 5366 "Gmsh.y"
    { (yyval.c2).char1 = (yyvsp[(1) - (3)].c); (yyval.c2).char2 = (yyvsp[(3) - (3)].c); ;}
    break;

  case 479:
#line 5371 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); flag_tSTRING_alloc = 1; ;}
    break;

  case 480:
#line 5380 "Gmsh.y"
    { (yyval.i) = 99; ;}
    break;

  case 481:
#line 5382 "Gmsh.y"
    { (yyval.i) = (int)(yyvsp[(2) - (2)].d); ;}
    break;

  case 482:
#line 5387 "Gmsh.y"
    { (yyval.i) = 0; ;}
    break;

  case 483:
#line 5389 "Gmsh.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 484:
#line 5394 "Gmsh.y"
    {
      memcpy((yyval.v), (yyvsp[(1) - (1)].v), 5*sizeof(double));
    ;}
    break;

  case 485:
#line 5398 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = -(yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 486:
#line 5402 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(2) - (2)].v)[i];
    ;}
    break;

  case 487:
#line 5406 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] - (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 488:
#line 5410 "Gmsh.y"
    {
      for(int i = 0; i < 5; i++) (yyval.v)[i] = (yyvsp[(1) - (3)].v)[i] + (yyvsp[(3) - (3)].v)[i];
    ;}
    break;

  case 489:
#line 5417 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (11)].d);  (yyval.v)[1] = (yyvsp[(4) - (11)].d);  (yyval.v)[2] = (yyvsp[(6) - (11)].d);  (yyval.v)[3] = (yyvsp[(8) - (11)].d); (yyval.v)[4] = (yyvsp[(10) - (11)].d);
    ;}
    break;

  case 490:
#line 5421 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (9)].d);  (yyval.v)[1] = (yyvsp[(4) - (9)].d);  (yyval.v)[2] = (yyvsp[(6) - (9)].d);  (yyval.v)[3] = (yyvsp[(8) - (9)].d); (yyval.v)[4] = 1.0;
    ;}
    break;

  case 491:
#line 5425 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 492:
#line 5429 "Gmsh.y"
    {
      (yyval.v)[0] = (yyvsp[(2) - (7)].d);  (yyval.v)[1] = (yyvsp[(4) - (7)].d);  (yyval.v)[2] = (yyvsp[(6) - (7)].d);  (yyval.v)[3] = 0.0; (yyval.v)[4] = 1.0;
    ;}
    break;

  case 493:
#line 5436 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(List_T*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].l)));
    ;}
    break;

  case 494:
#line 5441 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].l)));
    ;}
    break;

  case 495:
#line 5448 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 496:
#line 5453 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 497:
#line 5457 "Gmsh.y"
    {
      // creates an empty list
      (yyval.l) = List_Create(2, 1, sizeof(double));
    ;}
    break;

  case 498:
#line 5462 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 499:
#line 5466 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 500:
#line 5474 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (5)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (5)].d);
      }
    ;}
    break;

  case 501:
#line 5485 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 502:
#line 5489 "Gmsh.y"
    {
      (yyval.l) = 0;
    ;}
    break;

  case 503:
#line 5493 "Gmsh.y"
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

  case 504:
#line 5507 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (2)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) = - (*pd);
      }
    ;}
    break;

  case 505:
#line 5515 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (3)].l);
      for(int i = 0; i < List_Nbr((yyval.l)); i++){
	double *pd = (double*)List_Pointer((yyval.l), i);
	(*pd) *= (yyvsp[(1) - (3)].d);
      }
    ;}
    break;

  case 506:
#line 5523 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      for(double d = (yyvsp[(1) - (3)].d); ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d <= (yyvsp[(3) - (3)].d)) : (d >= (yyvsp[(3) - (3)].d));
          ((yyvsp[(1) - (3)].d) < (yyvsp[(3) - (3)].d)) ? (d += 1.) : (d -= 1.))
	List_Add((yyval.l), &d);
    ;}
    break;

  case 507:
#line 5530 "Gmsh.y"
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

  case 508:
#line 5540 "Gmsh.y"
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

  case 509:
#line 5563 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
    ;}
    break;

  case 510:
#line 5568 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags(0, (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 511:
#line 5574 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (4)].i), (yyval.l));
    ;}
    break;

  case 512:
#line 5579 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getAllElementaryTags((yyvsp[(1) - (2)].i), (yyval.l));
      Free((yyvsp[(2) - (2)].c));
    ;}
    break;

  case 513:
#line 5585 "Gmsh.y"
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

  case 514:
#line 5596 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getParentTags((yyvsp[(2) - (3)].i), (yyvsp[(3) - (3)].l), (yyval.l));
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 515:
#line 5603 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getElementaryTagsInBoundingBox((yyvsp[(1) - (16)].i), (yyvsp[(5) - (16)].d), (yyvsp[(7) - (16)].d), (yyvsp[(9) - (16)].d), (yyvsp[(11) - (16)].d), (yyvsp[(13) - (16)].d), (yyvsp[(15) - (16)].d), (yyval.l));
    ;}
    break;

  case 516:
#line 5608 "Gmsh.y"
    {
      (yyval.l) = List_Create(10, 10, sizeof(double));
      getBoundingBox((yyvsp[(2) - (5)].i), (int)(yyvsp[(4) - (5)].d), (yyval.l));
    ;}
    break;

  case 517:
#line 5613 "Gmsh.y"
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

  case 518:
#line 5623 "Gmsh.y"
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

  case 519:
#line 5633 "Gmsh.y"
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
#line 5643 "Gmsh.y"
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

  case 521:
#line 5655 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 522:
#line 5659 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfFloat((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 523:
#line 5664 "Gmsh.y"
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

  case 524:
#line 5676 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 525:
#line 5680 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 526:
#line 5684 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(4) - (6)].l);
    ;}
    break;

  case 527:
#line 5688 "Gmsh.y"
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

  case 528:
#line 5706 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = (yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1);
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 529:
#line 5714 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(double));
      for(int i = 0; i < (int)(yyvsp[(7) - (8)].d); i++) {
	double d = pow(10,(yyvsp[(3) - (8)].d) + ((yyvsp[(5) - (8)].d)-(yyvsp[(3) - (8)].d))*(double)i/((yyvsp[(7) - (8)].d)-1));
	List_Add((yyval.l), &d);
      }
    ;}
    break;

  case 530:
#line 5722 "Gmsh.y"
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

  case 531:
#line 5751 "Gmsh.y"
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

  case 532:
#line 5761 "Gmsh.y"
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

  case 533:
#line 5777 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (4)].l)); i++){
        double *d = (double*)List_Pointer((yyvsp[(3) - (4)].l), i);
        *d = std::abs(*d);
      }
      (yyval.l) = (yyvsp[(3) - (4)].l);
    ;}
    break;

  case 534:
#line 5788 "Gmsh.y"
    {
      (yyval.l) = List_Create(2, 1, sizeof(double));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].d)));
    ;}
    break;

  case 535:
#line 5793 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(1) - (1)].l);
    ;}
    break;

  case 536:
#line 5797 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].d)));
    ;}
    break;

  case 537:
#line 5801 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	double d;
	List_Read((yyvsp[(3) - (3)].l), i, &d);
	List_Add((yyval.l), &d);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 538:
#line 5813 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (9)].d), (int)(yyvsp[(4) - (9)].d), (int)(yyvsp[(6) - (9)].d), (int)(yyvsp[(8) - (9)].d));
    ;}
    break;

  case 539:
#line 5817 "Gmsh.y"
    {
      (yyval.u) = CTX::instance()->packColor((int)(yyvsp[(2) - (7)].d), (int)(yyvsp[(4) - (7)].d), (int)(yyvsp[(6) - (7)].d), 255);
    ;}
    break;

  case 540:
#line 5829 "Gmsh.y"
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

  case 541:
#line 5846 "Gmsh.y"
    {
      unsigned int val = 0;
      ColorOption(GMSH_GET, (yyvsp[(1) - (5)].c), 0, (yyvsp[(5) - (5)].c), val);
      (yyval.u) = val;
      Free((yyvsp[(1) - (5)].c)); Free((yyvsp[(5) - (5)].c));
    ;}
    break;

  case 542:
#line 5856 "Gmsh.y"
    {
      (yyval.l) = (yyvsp[(2) - (3)].l);
    ;}
    break;

  case 543:
#line 5860 "Gmsh.y"
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

  case 544:
#line 5875 "Gmsh.y"
    {
      (yyval.l) = List_Create(256, 10, sizeof(unsigned int));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].u)));
    ;}
    break;

  case 545:
#line 5880 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].u)));
    ;}
    break;

  case 546:
#line 5887 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 547:
#line 5891 "Gmsh.y"
    {
      // No need to extend to Struct_FullName (a Tag is not a String)
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(1) - (1)].c));
    ;}
    break;

  case 548:
#line 5896 "Gmsh.y"
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

  case 549:
#line 5910 "Gmsh.y"
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

  case 550:
#line 5926 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (3)].c), (yyvsp[(3) - (3)].c));
    ;}
    break;

  case 551:
#line 5930 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c), (yyvsp[(5) - (5)].c));
    ;}
    break;

  case 552:
#line 5934 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String(NULL, (yyvsp[(1) - (6)].c), (yyvsp[(3) - (6)].c), (int)(yyvsp[(5) - (6)].d));
    ;}
    break;

  case 553:
#line 5938 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(1) - (8)].c), (yyvsp[(3) - (8)].c), (yyvsp[(5) - (8)].c), (int)(yyvsp[(7) - (8)].d));
    ;}
    break;

  case 554:
#line 5942 "Gmsh.y"
    {
      std::string out;
      StringOption(GMSH_GET, (yyvsp[(1) - (6)].c), (int)(yyvsp[(3) - (6)].d), (yyvsp[(6) - (6)].c), out);
      (yyval.c) = (char*)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(1) - (6)].c)); Free((yyvsp[(6) - (6)].c));
    ;}
    break;

  case 555:
#line 5950 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(0, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 556:
#line 5956 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(1, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 557:
#line 5962 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(2, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 558:
#line 5968 "Gmsh.y"
    {
      std::string name = GModel::current()->getPhysicalName(3, (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char*)Malloc((name.size() + 1) * sizeof(char));
      strcpy((yyval.c), name.c_str());
    ;}
    break;

  case 559:
#line 5977 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(1) - (1)].c);
    ;}
    break;

  case 560:
#line 5981 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 561:
#line 5985 "Gmsh.y"
    {
      (yyval.c) = (char *)Malloc(32 * sizeof(char));
      time_t now;
      time(&now);
      strcpy((yyval.c), ctime(&now));
      (yyval.c)[strlen((yyval.c)) - 1] = '\0';
    ;}
    break;

  case 562:
#line 5993 "Gmsh.y"
    {
      std::string exe = Msg::GetExecutableName();
      (yyval.c) = (char *)Malloc(exe.size() + 1);
      strcpy((yyval.c), exe.c_str());
    ;}
    break;

  case 563:
#line 5999 "Gmsh.y"
    {
      std::string action = Msg::GetOnelabAction();
      (yyval.c) = (char *)Malloc(action.size() + 1);
      strcpy((yyval.c), action.c_str());
    ;}
    break;

  case 564:
#line 6005 "Gmsh.y"
    {
      (yyval.c) = strsave((char*)"Gmsh");
    ;}
    break;

  case 565:
#line 6009 "Gmsh.y"
    {
      const char *env = GetEnvironmentVar((yyvsp[(3) - (4)].c));
      if(!env) env = "";
      (yyval.c) = (char *)Malloc((sizeof(env) + 1) * sizeof(char));
      strcpy((yyval.c), env);
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 566:
#line 6017 "Gmsh.y"
    {
      std::string s = Msg::GetString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 567:
#line 6025 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (4)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 568:
#line 6032 "Gmsh.y"
    {
      std::string s = Msg::GetOnelabString((yyvsp[(3) - (6)].c), (yyvsp[(5) - (6)].c));
      (yyval.c) = (char *)Malloc((s.size() + 1) * sizeof(char));
      strcpy((yyval.c), s.c_str());
      Free((yyvsp[(3) - (6)].c));
      Free((yyvsp[(5) - (6)].c));
    ;}
    break;

  case 569:
#line 6041 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_String(NULL, (yyvsp[(3) - (5)].c2).char2, 1, 0, (yyvsp[(4) - (5)].c), 2);
    ;}
    break;

  case 570:
#line 6045 "Gmsh.y"
    {
      (yyval.c) = treat_Struct_FullName_dot_tSTRING_String((yyvsp[(3) - (7)].c2).char1, (yyvsp[(3) - (7)].c2).char2, (yyvsp[(5) - (7)].c), 0, (yyvsp[(6) - (7)].c), 2);
    ;}
    break;

  case 571:
#line 6049 "Gmsh.y"
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

  case 572:
#line 6064 "Gmsh.y"
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

  case 573:
#line 6078 "Gmsh.y"
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

  case 574:
#line 6092 "Gmsh.y"
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

  case 575:
#line 6104 "Gmsh.y"
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

  case 576:
#line 6120 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = toupper((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 577:
#line 6129 "Gmsh.y"
    {
      int i = 0;
      while ((yyvsp[(3) - (4)].c)[i]) {
        (yyvsp[(3) - (4)].c)[i] = tolower((yyvsp[(3) - (4)].c)[i]);
        i++;
      }
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 578:
#line 6138 "Gmsh.y"
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

  case 579:
#line 6148 "Gmsh.y"
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

  case 580:
#line 6159 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (8)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (8)].d), (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 581:
#line 6167 "Gmsh.y"
    {
      std::string in = (yyvsp[(3) - (6)].c);
      std::string out = in.substr((int)(yyvsp[(5) - (6)].d), std::string::npos);
      (yyval.c) = (char *)Malloc((out.size() + 1) * sizeof(char));
      strcpy((yyval.c), out.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 582:
#line 6175 "Gmsh.y"
    {
      (yyval.c) = (yyvsp[(3) - (4)].c);
    ;}
    break;

  case 583:
#line 6179 "Gmsh.y"
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

  case 584:
#line 6198 "Gmsh.y"
    {
      std::string tmp = FixRelativePath(gmsh_yyname, (yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 585:
#line 6205 "Gmsh.y"
    {
      std::string tmp = SplitFileName(GetAbsolutePath(gmsh_yyname))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
    ;}
    break;

  case 586:
#line 6211 "Gmsh.y"
    {
      std::string tmp = SplitFileName((yyvsp[(3) - (4)].c))[0];
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 587:
#line 6218 "Gmsh.y"
    {
      std::string tmp = GetAbsolutePath((yyvsp[(3) - (4)].c));
      (yyval.c) = (char*)Malloc((tmp.size() + 1) * sizeof(char));
      strcpy((yyval.c), tmp.c_str());
      Free((yyvsp[(3) - (4)].c));
    ;}
    break;

  case 588:
#line 6225 "Gmsh.y"
    { init_options(); ;}
    break;

  case 589:
#line 6227 "Gmsh.y"
    {
      std::string val((yyvsp[(3) - (6)].c));
      Msg::ExchangeOnelabParameter("", val, floatOptions, charOptions);
      (yyval.c) = (char*)Malloc((val.size() + 1) * sizeof(char));
      strcpy((yyval.c), val.c_str());
      Free((yyvsp[(3) - (6)].c));
    ;}
    break;

  case 590:
#line 6235 "Gmsh.y"
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

  case 591:
#line 6259 "Gmsh.y"
    { struct_namespace = std::string(""); (yyval.d) = (yyvsp[(2) - (2)].d); ;}
    break;

  case 592:
#line 6261 "Gmsh.y"
    { struct_namespace = (yyvsp[(1) - (4)].c); Free((yyvsp[(1) - (4)].c)); (yyval.d) = (yyvsp[(4) - (4)].d); ;}
    break;

  case 593:
#line 6267 "Gmsh.y"
    { (yyval.l) = (yyvsp[(3) - (4)].l); ;}
    break;

  case 594:
#line 6272 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 595:
#line 6274 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 596:
#line 6279 "Gmsh.y"
    { (yyval.l) = (yyvsp[(2) - (3)].l); ;}
    break;

  case 597:
#line 6284 "Gmsh.y"
    {
      (yyval.l) = List_Create(20,20,sizeof(char*));
      List_Add((yyval.l), &((yyvsp[(1) - (1)].c)));
    ;}
    break;

  case 598:
#line 6289 "Gmsh.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 599:
#line 6291 "Gmsh.y"
    {
      List_Add((yyval.l), &((yyvsp[(3) - (3)].c)));
    ;}
    break;

  case 600:
#line 6295 "Gmsh.y"
    {
      for(int i = 0; i < List_Nbr((yyvsp[(3) - (3)].l)); i++){
	char* c;
	List_Read((yyvsp[(3) - (3)].l), i, &c);
	List_Add((yyval.l), &c);
      }
      List_Delete((yyvsp[(3) - (3)].l));
    ;}
    break;

  case 601:
#line 6307 "Gmsh.y"
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

  case 602:
#line 6321 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString(NULL, (yyvsp[(1) - (5)].c), (yyvsp[(3) - (5)].c));
    ;}
    break;

  case 603:
#line 6325 "Gmsh.y"
    {
      (yyval.l) = treat_Struct_FullName_dot_tSTRING_ListOfString((yyvsp[(1) - (7)].c), (yyvsp[(3) - (7)].c), (yyvsp[(5) - (7)].c));
    ;}
    break;

  case 604:
#line 6332 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 605:
#line 6340 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(4) - (5)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(1) - (5)].c))+strlen(tmpstr)+1)*sizeof(char)) ;
      strcpy((yyval.c), (yyvsp[(1) - (5)].c)) ; strcat((yyval.c), tmpstr) ;
      Free((yyvsp[(1) - (5)].c));
    ;}
    break;

  case 606:
#line 6348 "Gmsh.y"
    {
      char tmpstr[256];
      sprintf(tmpstr, "_%d", (int)(yyvsp[(7) - (8)].d));
      (yyval.c) = (char *)Malloc((strlen((yyvsp[(3) - (8)].c))+strlen(tmpstr)+1)*sizeof(char));
      strcpy((yyval.c), (yyvsp[(3) - (8)].c)); strcat((yyval.c), tmpstr);
      Free((yyvsp[(3) - (8)].c));
    ;}
    break;

  case 607:
#line 6359 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 608:
#line 6361 "Gmsh.y"
    { (yyval.c) = (yyvsp[(1) - (1)].c); ;}
    break;

  case 609:
#line 6364 "Gmsh.y"
    { (yyval.c) = (yyvsp[(3) - (4)].c); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 14045 "Gmsh.tab.cpp"
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


#line 6367 "Gmsh.y"


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

void getBoundingBox(int dim, int tag, List_T *out)
{
  if(GModel::current()->getOCCInternals() &&
     GModel::current()->getOCCInternals()->getChanged())
    GModel::current()->getOCCInternals()->synchronize(GModel::current());
  if(GModel::current()->getGEOInternals()->getChanged())
    GModel::current()->getGEOInternals()->synchronize(GModel::current());

  GEntity *ge = GModel::current()->getEntityByTag(dim, tag);
  SBoundingBox3d box;
  if(ge) box = ge->bounds();
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

